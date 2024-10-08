/**
 * @file event_generator.c
 * @date 2015-12-18
 *
 * NOTE:
 * This file is generated by DAVE. Any manual modification done to this file will be lost when the code is regenerated.
 *
 * @cond
 ***********************************************************************************************************************
 * EVENT_GENERATOR v4.1.16 - Configures the properties of ERU_OGU peripheral instance
 *
 * Copyright (c) 2015-2020, Infineon Technologies AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,are permitted provided that the
 * following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright notice, this list of conditions and the  following
 *   disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *   following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *   Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
 *   products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * To improve the quality of the software, users are encouraged to share modifications, enhancements or bug fixes
 * with Infineon Technologies AG (dave@infineon.com).
 ***********************************************************************************************************************
 *
 * Change History
 * --------------
 *
 * 2015-02-16:
 *     - Initial version<br>
 *
 * 2015-05-08:
 *     - Guidelines updated<br>
 *
 * 2015-06-29:
 *     - Added XMC_SCU_INTERRUPT_EnableNmiRequest() call during APP initialization, to enable the promotion of the
 *       eru event as NMI.<br>
 *
 * 2015-09-30:
 *     - EVENT_GENERATOR_NMI_ENABLED is changed as  EVENT_GENERATOR_NMI_SUPPORTED.
 *
 * @endcond
 *
 */
/***********************************************************************************************************************
 * HEADER FILES
***********************************************************************************************************************/
#include "event_generator.h"

/***********************************************************************************************************************
 * MACROS
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * LOCAL DATA
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * LOCAL ROUTINES
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * API IMPLEMENTATION
 **********************************************************************************************************************/
/* Returns the version of the EVENT_GENERATOR APP. */
DAVE_APP_VERSION_t EVENT_GENERATOR_GetAppVersion(void)
{
  DAVE_APP_VERSION_t version;

  version.major = EVENT_GENERATOR_MAJOR_VERSION;
  version.minor = EVENT_GENERATOR_MINOR_VERSION;
  version.patch = EVENT_GENERATOR_PATCH_VERSION;

  return version;
}

/*
 * This function Initializes a EVENT_GENERATOR APP instances based on user configuration.
 */
EVENT_GENERATOR_STATUS_t EVENT_GENERATOR_Init(EVENT_GENERATOR_t *const handle)
{
  /* Checking for null handle */
  XMC_ASSERT("EVENT_GENERATOR_Init:handle NULL" , (handle != NULL));
  
  /* Checking for initialization state of the instance */
  if (false == handle->init_status)
  {
    /* Hardware initialization based on UI */
    XMC_ERU_OGU_Init(handle->eru, handle->channel, handle->config);
    #if (EVENT_GENERATOR_NMI_SUPPORTED == 1U)
    /* Promote the eru event as NMI, Applicable only for XMC4000 devices */
    XMC_SCU_INTERRUPT_EnableNmiRequest(handle->nmi_eru_msk);
    #endif
    /* Update the init status of the instance */
    handle->init_status = true;
  }
  
  return EVENT_GENERATOR_STATUS_SUCCESS;
}
