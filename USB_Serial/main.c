#include "DAVE.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>

#define S(s) ((int8_t*)(s))
uint16_t send_data;
typedef enum USB_STATUS
{
	USB_STATUS_SUCCESS = 0U, USB_STATUS_FAILURE
} USB_STATUS_t;
#define USBD_VCOM_BUFFSIZE (256)

int8_t usb_rx_buffer[USBD_VCOM_BUFFSIZE] ={ 0 };
const char CommandSeperator[] = " ";
  int8_t rx_buffer[64] = { 0 };
  int8_t tx_buffer[64] = { 0 };
  CDC_LineEncoding_t line_encoding_ptr;
  static void delay(uint32_t cycles);

  static void delay(uint32_t cycles)
  {
    volatile uint32_t i;

    for(i = 0UL; i < cycles ;++i)
    {
       __NOP();
    }
  }
  USB_STATUS_t USB_printf(const char *format, ...)
  {
  	char outPutString[USBD_VCOM_BUFFSIZE];
  	USB_STATUS_t result;
  	va_list args;
  	va_start(args, format);

  	vsnprintf(outPutString, USBD_VCOM_BUFFSIZE, format, args);
  	result = USBD_VCOM_SendString(S(outPutString));

  	va_end(args);
  	return result;
  }

  USB_STATUS_t processRxCommand(char* commandLine)
  {
  	char *token;

  	if ((token = strsep(&commandLine, CommandSeperator)) != NULL)
  		{
  		send_data = strtoul(token, NULL, 0);

  		send_data=send_data+10;
  		//return USB_CAN_STATUS_SUCCESS;
  		USB_printf("\r\n Return Data: %d \r\n",send_data);

  		return USB_STATUS_SUCCESS;

  		}
  	else
  		{
  			return USB_STATUS_FAILURE;
  		}
  }


  int is_printable(int8_t data_byte)
  {
  	return (31 < data_byte) && (data_byte < 126);
  }


  USBD_VCOM_STATUS_t USBD_VCOM_SendPromt(int8_t usb_rx_buffer[])
  {
  	return USB_printf("\r> %s", usb_rx_buffer);
  }


  USB_STATUS_t processCommand(int8_t usb_rx_buffer[])
  {
  	USB_STATUS_t result = USB_STATUS_FAILURE;
  	char* commandLine = (char*) usb_rx_buffer;
  	const char* cmd = NULL;
  	char *token;

  	if (usb_rx_buffer == NULL)
  	{
  		return USB_STATUS_FAILURE;
  	}

  	if ((token = strsep(&commandLine, CommandSeperator)) != NULL)
  	{
  		cmd = token;
  		if (!strcmp(cmd, "Send"))
  		{
  			result = processRxCommand(commandLine);
  		}
  		else
  		{
  			USB_printf("\r\nUnknown command '%s'\r\n", cmd);
  		}

  		if (result == USB_STATUS_SUCCESS)
  		{
  			USB_printf("\r\nResult: Success\r\n");
  		}
  		else
  		{
  			USB_printf("\r\nResult: Failure\r\n");
  		}
  	}
  	return result;
  }

  int main(void)
  {
    DAVE_STATUS_t init_status;
    uint16_t bytes = 0;
    init_status = DAVE_Init();

    if (init_status == DAVE_STATUS_SUCCESS)
    {

      if (USBD_VCOM_Connect() != USBD_VCOM_STATUS_SUCCESS)
      {
       return -1;
      }

      while (!USBD_VCOM_IsEnumDone());
      while(!cdc_event_flags.line_encoding_event_flag);

      delay(0xffff);//ensure the status of line encoding request is properly send to host.
      USBD_VCOM_GetLineEncoding(&line_encoding_ptr);

      int usb_rx_buffer_idx = 0;

      while(1U)
      {

        bytes = USBD_VCOM_BytesReceived();
        if (bytes)
        {
				USBD_VCOM_STATUS_t status;
				int8_t data_byte = 0;
				const int8_t newLine = '\r';

				status = USBD_VCOM_ReceiveByte(&data_byte);

				if (status == USBD_VCOM_STATUS_SUCCESS)
				{
					if (data_byte == newLine)
					{
						processCommand(usb_rx_buffer);

						usb_rx_buffer_idx = 0;
						memset(usb_rx_buffer, 0, USBD_VCOM_BUFFSIZE);
					}
					else if (data_byte == '\177')
					{
						if (usb_rx_buffer_idx > 0)
						{
							usb_rx_buffer_idx--;
							usb_rx_buffer[usb_rx_buffer_idx] = ' ';
							USBD_VCOM_SendPromt(usb_rx_buffer);
							usb_rx_buffer[usb_rx_buffer_idx] = 0;
						}
					}
					else if (is_printable(data_byte)
							&& (usb_rx_buffer_idx < (USBD_VCOM_BUFFSIZE - 1)))
					{
						usb_rx_buffer[usb_rx_buffer_idx++] = data_byte;
					}
					USBD_VCOM_SendPromt(usb_rx_buffer);
				}
			}

        CDC_Device_USBTask(&USBD_VCOM_cdc_interface);
      }
    }
    else
    {
      XMC_DEBUG("main: Application initialization failed");
      while(1U)
      {
      }
    }

    return 1U;
  }
