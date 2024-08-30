/*
 * main.c
 *
 *  Created on: 2024 Aug 24 23:53:01
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
XMC_VADC_RESULT_SIZE_t result;
uint32_t value;
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

  }
}
void Adc_Measurement_Handler(void)
{
	result = ADC_MEASUREMENT_GetResult(&ADC_MEASUREMENT_Channel_A);

	value =result / 0.4095;
	PWM_SetDutyCycle(&PWM_0,value);
}
