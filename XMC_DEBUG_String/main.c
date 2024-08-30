/*
 * main.c
 *
 *  Created on: 2024 Aug 28 21:57:04
 *  Author: admin
 */




#include "DAVE.h"                 //Declarations from DAVE Code Generation (includes SFR declaration)
extern void initialise_monitor_handles(void);
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
  initialise_monitor_handles();
  XMC_DEBUG("SimTestlab\n")
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
	  XMC_DEBUG("WELCOME\n")
  }
}
