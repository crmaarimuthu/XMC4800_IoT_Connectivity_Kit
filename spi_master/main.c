/*
 * main.c
 *
 *  Created on: 2024 Aug 25 05:21:44
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
  uint32_t baud_rate = 200U;
  status = DAVE_Init();           /* Initialization of DAVE APPs  */
  uint8_t ReadData1[10];
  uint8_t SendData1[10] = {0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA};
  uint8_t ReadData2[10];
  uint8_t SendData2[10] = {0xA, 0x9, 0x8, 0x7, 0x6, 0x5, 0x4, 0x3, 0x2, 0x1};
  uint32_t status1 = 0;
  uint32_t status2 = 0;
  if (status != DAVE_STATUS_SUCCESS)
  {
    /* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
    XMC_DEBUG("DAVE APPs initialization failed\n");

    while(1U)
    {

    }
  }

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
	SPI_MASTER_SetMode(&SPI_MASTER_0, XMC_SPI_CH_MODE_STANDARD);
	XMC_USIC_CH_SetFrameLength(XMC_SPI0_CH0,8);
	SPI_MASTER_SetBaudRate(&SPI_MASTER_0, baud_rate);
  while(1U)
  {
	  /*******METHOD-1*******/
	  SPI_MASTER_Receive(&SPI_MASTER_0, ReadData1, 10U);
	  SPI_MASTER_Transmit(&SPI_MASTER_0, SendData1, 10U);
	  while(SPI_MASTER_0.runtime->rx_busy);
	  while(SPI_MASTER_0.runtime->tx_busy);

	  /*******METHOD-2*******/

	  /* Clear the flags */
	  SPI_MASTER_ClearFlag(&SPI_MASTER_0,XMC_SPI_CH_STATUS_FLAG_ALTERNATIVE_RECEIVE_INDICATION);
	  SPI_MASTER_ClearFlag(&SPI_MASTER_0,XMC_SPI_CH_STATUS_FLAG_RECEIVE_INDICATION);
	  /* Send Write Enable Command */
	  SPI_MASTER_Transfer(&SPI_MASTER_0, SendData2, ReadData2, 10);
	  while(SPI_MASTER_0.runtime->rx_busy);
	  while(SPI_MASTER_0.runtime->tx_busy);
	  do
	  {
		  status1 = SPI_MASTER_GetFlagStatus(&SPI_MASTER_0,XMC_SPI_CH_STATUS_FLAG_ALTERNATIVE_RECEIVE_INDICATION);
		  status2 = SPI_MASTER_GetFlagStatus(&SPI_MASTER_0,XMC_SPI_CH_STATUS_FLAG_RECEIVE_INDICATION);
	  } while(((status1 == 0) && (status2 == 0)));
	  /* Clear the flags */
	  SPI_MASTER_ClearFlag(&SPI_MASTER_0,XMC_SPI_CH_STATUS_FLAG_ALTERNATIVE_RECEIVE_INDICATION);
	  SPI_MASTER_ClearFlag(&SPI_MASTER_0,XMC_SPI_CH_STATUS_FLAG_RECEIVE_INDICATION);
	  /* Enable the Slave Select Line */
	  SPI_MASTER_EnableSlaveSelectSignal(&SPI_MASTER_0, SPI_MASTER_SS_SIGNAL_0);
  }
}
