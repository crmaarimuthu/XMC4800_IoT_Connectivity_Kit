/*
 * main.c
 *
 *  Created on: 2024 Aug 25 03:32:06
 *  Author: admin
 */




#include "DAVE.h"                 //Declarations from DAVE Code Generation (includes SFR declaration)

/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */

int main(void)
{
  DAVE_STATUS_t status;
  uint8_t ReadData;
  status = DAVE_Init();           /* Initialization of DAVE APPs  */
  uint32_t baud=9600;
  if (status != DAVE_STATUS_SUCCESS)
  {
    /* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
    XMC_DEBUG("DAVE APPs initialization failed\n");

    while(1U)
    {

    }
  }

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  UART_SetBaudrate(&UART_0, baud, 16);
  while(1U)
  {

	  UART_Receive(&UART_0, ReadData, 1);

	  UART_Transmit(&UART_0, ReadData, 1);
	  while(UART_0.runtime->rx_busy);
	  while(UART_0.runtime->tx_busy);
  }
}
