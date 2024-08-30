/*
 * main.c
 *
 *  Created on: 2024 Aug 28 05:36:54
 *  Author: admin
 */




#include "DAVE.h"                 //Declarations from DAVE Code Generation (includes SFR declaration)

#define SLAVE_ADDRESS 0xA0
   #define BYTES_TO_READ 10
   #define BYTES_TO_TRANSMIT 10

   typedef enum PCA9502_REGADDR {
     IO_DIR    = 0xA << 3,
     IO_STATE  = 0xB << 3,
     IO_INTE   = 0xC << 3,
     IO_CTRL   = 0xE << 3
   } PCA9502_REGADDR_t;

   uint8_t mem_address[2];
   uint8_t data = 0x55;
   uint8_t rx_data;
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

  status = DAVE_Init();           /* Initialization of DAVE APPs  */

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
	  mem_address[0] = IO_STATE;//memory which need to be read from slave
	  //Write data to IO EXPANDER
	  I2C_MASTER_Transmit(&I2C_MASTER_0,true,SLAVE_ADDRESS,mem_address,1,false);
	  while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));

	  I2C_MASTER_Transmit(&I2C_MASTER_0,false,SLAVE_ADDRESS,&data,1,true);
	  while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));

	  //Read data from IO EXPANDER
	  I2C_MASTER_Transmit(&I2C_MASTER_0,true,SLAVE_ADDRESS,mem_address,1,false);
	  while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));

	  I2C_MASTER_Receive(&I2C_MASTER_0,true,SLAVE_ADDRESS,&rx_data,1,true,true);
	  while(I2C_MASTER_IsRxBusy(&I2C_MASTER_0));
	  for(int i=0;i<90000;i++);
  }
}
