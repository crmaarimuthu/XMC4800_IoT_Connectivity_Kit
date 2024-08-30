    #include "DAVE.h"         //Declarations from DAVE Code Generation (includes SFR declaration)

    //Pre-condition:
    //Configure receive mode and transmit mode as "Direct".
    //Description:
    //Receives 10 bytes from the I2C master and transmits the same to the master.
    //Data will be transmitted or received only when master provides the clock, read request and write request.

    int main(void)
    {
      I2C_SLAVE_STATUS_t init_status;
      uint8_t ReadData[10];

      init_status = (I2C_SLAVE_STATUS_t)I2C_SLAVE_Init(&I2C_SLAVE_0);
      if(init_status == I2C_SLAVE_STATUS_SUCCESS)
      {
        //Start data reception and wait till 10 bytes are received.
        if(I2C_SLAVE_Receive(&I2C_SLAVE_0, ReadData, 10) == I2C_SLAVE_STATUS_SUCCESS)
        {
          //Transmit the received data to master.
          I2C_SLAVE_Transmit(&I2C_SLAVE_0, ReadData, 10);
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
