/*
 * main.c
 *
 *  Created on: 2024 Aug 28 02:14:04
 *  Author: admin
 */




#include "DAVE.h"                 //Declarations from DAVE Code Generation (includes SFR declaration)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
	uint32_t new_baudrate = 500000;  // in Hz
	uint16_t new_sampe_point = 80;
	uint8_t new_sjw = 2;
	uint8_t *array_data;

	uint32_t received_id;
	uint8_t received_data[8];
	uint32_t get_status;
	uint32_t get_data;
	typedef enum USB_CAN_STATUS
	{
		USB_CAN_STATUS_SUCCESS = 0U, USB_CAN_STATUS_FAILURE
	} USB_CAN_STATUS_t;

#define USBD_VCOM_BUFFSIZE (256)
/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */

	void CanSendMessage(uint8_t *data,uint16_t CAN_identifier,int CanBytes)
	{
		XMC_CAN_MO_t *MO_Ptr;
		const CAN_NODE_t *HandlePtr1 = &CAN_NODE_0;
		MO_Ptr = HandlePtr1->lmobj_ptr[0]->mo_ptr;   //'0' refers to first message object configured
				                                                     // for the selected can node
		CAN_NODE_Enable(HandlePtr1);
		XMC_CAN_NODE_SetInitBit(HandlePtr1->node_ptr);
		CAN_NODE_ConfigBaudrate(HandlePtr1, new_baudrate, new_sampe_point,new_sjw);//400000
		XMC_CAN_NODE_ResetInitBit(HandlePtr1->node_ptr);

		array_data = data;
		MO_Ptr->can_mo_type = XMC_CAN_MO_TYPE_TRANSMSGOBJ;  //Configure message object type as transmit type
		MO_Ptr->can_id_mode = XMC_CAN_FRAME_TYPE_STANDARD_11BITS; //configure MO identifier type
		MO_Ptr->can_data_length = CanBytes; // Configure CAN transmit MO data length field
		MO_Ptr->can_identifier =CAN_identifier ; // Example identifier
		MO_Ptr->can_id_mask = 0x7FF;
		MO_Ptr->can_priority = XMC_CAN_ARBITRATION_MODE_IDE_DIR_BASED_PRIO_2;
		// Runtime change the MO configuration

		CAN_NODE_MO_Init(HandlePtr1->lmobj_ptr[0]);
		CAN_NODE_MO_UpdateData(HandlePtr1->lmobj_ptr[0],array_data); //CAN Transmit
		CAN_NODE_MO_Transmit(HandlePtr1->lmobj_ptr[0]);




	}
	void CanNode0_receiveINT()
		{
			  XMC_CAN_MO_t *MO_Ptr;
			  const CAN_NODE_t *HandlePtr1 = &CAN_NODE_0;
			 // long double current_angle = 5.78899 ;
			  MO_Ptr = HandlePtr1->lmobj_ptr[1]->mo_ptr;   //'0' refers to first message object configured
			                                                     // for the selected can node


			CAN_NODE_Enable(HandlePtr1);

			// For run time baud rate configuration change
			// Configure new baud rate to 1MHz

			XMC_CAN_NODE_SetInitBit(HandlePtr1->node_ptr);
			CAN_NODE_ConfigBaudrate(HandlePtr1, new_baudrate, new_sampe_point,new_sjw);
			XMC_CAN_NODE_ResetInitBit(HandlePtr1->node_ptr);
	        //Receive the data
			CAN_NODE_MO_Receive(HandlePtr1->lmobj_ptr[1]);

			MO_Ptr->can_mo_type = XMC_CAN_MO_TYPE_RECMSGOBJ;  //Configure message object type as transmit type
			MO_Ptr->can_id_mode = XMC_CAN_FRAME_TYPE_STANDARD_11BITS; //configure MO identifier type
			MO_Ptr->can_data_length = 8; // Configure CAN transmit MO data length field
			received_id=MO_Ptr->can_identifier;
			MO_Ptr->can_identifier =received_id ; // Example identifier
			MO_Ptr->can_id_mask = 0x0;
			MO_Ptr->can_priority = XMC_CAN_ARBITRATION_MODE_IDE_DIR_BASED_PRIO_2;
			// Runtime change the MO configuration
			CAN_NODE_MO_Init(HandlePtr1->lmobj_ptr[1]);

			for (int i = 0; i < 8; i++)
			{
				received_data[i] = MO_Ptr->can_data_byte[i];
			}


		}

	void USB_CAN_printf(const char *format, ...)
	{
		char outPutString[USBD_VCOM_BUFFSIZE];
		va_list args;
		va_start(args, format);

		vsnprintf(outPutString, USBD_VCOM_BUFFSIZE, format, args);
		//result = USBD_VCOM_SendString(S(outPutString));

		va_end(args);
	}
int main(void)
{
  DAVE_STATUS_t status;

  status = DAVE_Init();           /* Initialization of DAVE APPs  */

  uint8_t can_data[8]={1,2,3,4,5,6,7,8};

  if (status != DAVE_STATUS_SUCCESS)
  {
    /* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
    XMC_DEBUG("DAVE APPs initialization failed\n");

    while(1U)
    {

    }
  }

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */




  while(1U)
  {
	 CanSendMessage(can_data,100,8);
	 CanNode0_receiveINT();
	 for(int i=0;i<900000;i++);

		uint8_t Receive_Error = XMC_CAN_NODE_GetReceiveErrorCounter((XMC_CAN_NODE_t *const) &CAN_NODE_0);


		CAN_NODE_GetStatus(&CAN_NODE_0);
			USB_CAN_printf("\r \n  \r \n");
			for (int i = 32; i >= 0; --i)
			{
				// Check if the i-th bit is set
				get_data =(get_status & (1 << i));
				switch (get_data) {

			case (1):
					printf("\r LAST_ERROR_CODE Stuff Error  \r \n");
				break;
			case (2):
					USB_CAN_printf("\r LAST_ERROR_CODE Form Error  \r \n");
				break;
			case (3):
					USB_CAN_printf("\r LAST_ERROR_CODE Ack Error  \r \n");
				break;
			case (4):
					USB_CAN_printf("\r LAST_ERROR_CODE Bit1 Error \r \n");
				break;
			case (5):
					USB_CAN_printf("\r LAST_ERROR_CODE Bit0 Error \r \n");
				break;
			case (6):
					USB_CAN_printf("\r LAST_ERROR_CODE CRC Error  \r \n");
				break;
			case (7):
					USB_CAN_printf("\r  CPU write to LEC  \r \n");
				break;
			case 8:
					USB_CAN_printf("\r TX OK \r \n ");
				break;
			case 16:
					USB_CAN_printf("\r RX OK \r \n ");
				break;
			case 32:
				USB_CAN_printf("\r ALERT WARNING \r \n ");
				break;
			case 64:
				USB_CAN_printf("\r ERROR WARNING\r \n ");
				break;
			case 128:
				USB_CAN_printf("\r BUS OFF \r \n ");
				break;
			case 256:
				USB_CAN_printf("\r LIST_LENGTH_ERROR \r \n ");
				break;
			case 512:
				USB_CAN_printf("\r LIST_OBJECT_ERROR \r \n ");
				break;
			}
				USB_CAN_printf("\r get status: %d\r \n",get_status);
				USB_CAN_printf("\r Receive Error: %d \r \n",Receive_Error);
		}
  }
}
