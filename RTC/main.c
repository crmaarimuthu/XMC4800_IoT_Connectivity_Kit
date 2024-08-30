/*
 * main.c
 *
 *  Created on: 2024 Aug 29 22:04:49
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


XMC_RTC_TIME_t timeval =
  {
     .seconds = 0U,
     .minutes = 0U,
     .hours =23U,
     .days = 29U,
     .month = 8,
     .year = 2024U
  };

XMC_RTC_ALARM_t alarm =
  {
     .seconds = 0U,
     .minutes = 1U,
     .hours = 23U,
     .days = 29U,
     .month = 8,
     .year = 2024U
  };

int main(void)
{
	RTC_STATUS_t RTC_ST = RTC_STATUS_FAILURE;
	RTC_STATUS_t RTC_SAT = RTC_STATUS_FAILURE;
  DAVE_STATUS_t status;

  status = DAVE_Init();           /* Initialization of DAVE APPs  */
  RTC_Stop();
  RTC_ST=RTC_SetTime(&timeval);

  RTC_SAT=RTC_SetAlarmTime(&alarm);
  RTC_Start();
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

	  if((RTC_ST==RTC_STATUS_SUCCESS)&&(RTC_SAT==RTC_STATUS_SUCCESS))
	  {
		  RTC_GetTime(&timeval);
		  RTC_GetAlarmTime(&alarm);
		  if((timeval.minutes>=alarm.minutes)&&((timeval.minutes<=alarm.minutes)&&(timeval.seconds<=alarm.seconds+59)))//alarm set 1 minute (01:00 to 02:00) led on
		  {
			  DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_0);

		  }
		  else
		  {
			  DIGITAL_IO_SetOutputLow(&DIGITAL_IO_0);
		  }

	  }
  }
}
