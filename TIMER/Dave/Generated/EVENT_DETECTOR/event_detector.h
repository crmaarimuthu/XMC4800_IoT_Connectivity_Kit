/**
 * @file event_detector.h
 * @date 2021-01-08
 *
 * NOTE:
 * This file is generated by DAVE. Any manual modification done to this file will be lost when the code is regenerated.
 *
 * @cond
 ***********************************************************************************************************************
 * EVENT_DETECTOR v4.0.8 - Configures the properties of ERU_ERS and ERU_ETL peripheral instance.
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
 *     - c++ guard is applied to APIs section<br>
 *     - Comments updated<br>
 *     - Assertion are added to inline APIs to check for NULL handle<br>
 *
 * 2021-01-08:
 *     - Modified check for minimum XMCLib version
 *
 * @endcond
 *
 */
#ifndef EVENT_DETECTOR_H
#define EVENT_DETECTOR_H

/***********************************************************************************************************************
 * HEADER FILES
 **********************************************************************************************************************/
#include "xmc_eru.h"
#include "event_detector_conf.h"
#include "DAVE_Common.h"

 /**********************************************************************************************************************
 * MACROS
 **********************************************************************************************************************/
#define EVENT_DETECTOR_XMC_LIB_MAJOR_VERSION 2
#define EVENT_DETECTOR_XMC_LIB_MINOR_VERSION 0
#define EVENT_DETECTOR_XMC_LIB_PATCH_VERSION 0

#if !((XMC_LIB_MAJOR_VERSION > EVENT_DETECTOR_XMC_LIB_MAJOR_VERSION) ||\
      ((XMC_LIB_MAJOR_VERSION == EVENT_DETECTOR_XMC_LIB_MAJOR_VERSION) && (XMC_LIB_MINOR_VERSION > EVENT_DETECTOR_XMC_LIB_MINOR_VERSION)) ||\
      ((XMC_LIB_MAJOR_VERSION == EVENT_DETECTOR_XMC_LIB_MAJOR_VERSION) && (XMC_LIB_MINOR_VERSION == EVENT_DETECTOR_XMC_LIB_MINOR_VERSION) && (XMC_LIB_PATCH_VERSION >= EVENT_DETECTOR_XMC_LIB_PATCH_VERSION)))
#error "EVENT_DETECTOR requires XMC Peripheral Library v2.0.0 or higher"
#endif

 /**********************************************************************************************************************
 * ENUMS
 **********************************************************************************************************************/
/**
 * @ingroup EVENT_DETECTOR_enumerations
 * @{
 */

/**
 *  @brief Initialization status.
 */
typedef enum EVENT_DETECTOR_STATUS
{
  EVENT_DETECTOR_STATUS_SUCCESS = 0U, /**< Status success */
  EVENT_DETECTOR_STATUS_FAILURE, /**< Status failure */
} EVENT_DETECTOR_STATUS_t;
/**
* @}
*/
/***********************************************************************************************************************
* DATA STRUCTURES
***********************************************************************************************************************/

/**
 * @ingroup EVENT_DETECTOR_datastructures
 * @{
 */ 

/**
 * @brief This structure will hold the APP configuration parameters
 */
typedef struct EVENT_DETECTOR
{
  XMC_ERU_t* const eru; /**< ERU module assigned */
  const uint8_t channel; /**< ERU channel assigned(0-3) */
  const XMC_ERU_ETL_CONFIG_t *const config; /**< reference to hardware configuration */
  bool init_status; /**< This parameter indicates the initialized state of each instance */
} EVENT_DETECTOR_t;

/**
 * @}
 */
/***********************************************************************************************************************
* API Prototypes
***********************************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/**
 * @ingroup EVENT_DETECTOR_apidoc
 * @{
 */

/**
 * @brief Get EVENT_DETECTOR APP version
 * @return DAVE_APP_VERSION_t APP version information (major, minor and patch number)
 * <BR>
 * \par<b>Description:</b><br>
 * The function can be used to check application software compatibility with a
 * specific version of the APP.
 *
 * Example Usage:
 * @code
 * #include "DAVE.h"
 * int main(void)
 * {
 *   DAVE_STATUS_t status;
 *   DAVE_APP_VERSION_t app_version;
 *
 *   status = DAVE_Init();	// EVENT_DETECTOR_Init() is called from DAVE_Init()
 *
 *   app_version = EVENT_DETECTOR_GetAppVersion();
 *
 *   if (app_version.major != 4U)
 *   {
 *     // Probably, not the right version.
 *   }
 *
 *   while(1U)
 *   {
 *   }
 *   return 1;
 * }
 * @endcode<BR>
 */
DAVE_APP_VERSION_t EVENT_DETECTOR_GetAppVersion(void);

/**
 * @brief Initializes a EVENT_DETECTOR APP instance (ERSx+ETLx where x = [0..3])
 *        with generated configuration.
 * @param handle pointer to the EVENT_DETECTOR APP configuration.
 * @return EVENT_DETECTOR_STATUS_t
 *         EVENT_DETECTOR_STATUS_SUCCESS  : if initialization is successful\n
 *         EVENT_DETECTOR_STATUS_FAILURE  : if initialization is failed
 *
 * \par<b>Description:</b><br>
 * <ul>
 * <li>Enable the clock for the ERU module and invoke the LLD Init API with generated configuration handle.</li>
 * <li>This configures the input event selection with selected polarity settings</li>
 * <li>Trigger source by combining the input signals</li>
 * </ul>
 *
 * Example Usage:
 * 
 * @code
 * #include "DAVE.h"
 * int main(void)
 * {
 *  // ... Initializes Apps configurations ...
 *  DAVE_Init(); //EVENT_DETECTOR_Init(&EVENT_DETECTOR_0) will be called from DAVE_Init()
 *  while(1U)
 *  {
 *  }
 *  return (1U);
 * }
 *
 * @endcode<BR>
 */
EVENT_DETECTOR_STATUS_t EVENT_DETECTOR_Init(EVENT_DETECTOR_t *const handle);


/**
 * @brief  Set the ETLx(x= [0..3]) status flag.
 * @param  handle pointer to the EVENT_DETECTOR APP configuration.
 * @return None
 * <BR>
 *
 * \par<b>Description:</b><br>
 * Status flag is connected with OGU block, where the state is utilized for pattern match.
 *
 * Example Usage:
 * 
 * @code
 * #include "DAVE.h"
 * int main(void)
 * {
 *  // ... Initializes Apps configurations ...
 *  DAVE_Init(); //EVENT_DETECTOR_Init(&EVENT_DETECTOR_0) will be called from DAVE_Init()
 *  
 *  //user logic
 *  
 *  EVENT_DETECTOR_SetStatusFlag(&EVENT_DETECTOR_0);
 *  while(1U)
 *  {
 *  }
 *  return (1U);
 * }
 *
 * @endcode<BR>
 */
__STATIC_INLINE void EVENT_DETECTOR_SetStatusFlag(const EVENT_DETECTOR_t *const handle)
{
  /* Checking for null handle */
  XMC_ASSERT("EVENT_DETECTOR_SetStatusFlag:handle NULL" , (handle != NULL));
  XMC_ERU_ETL_SetStatusFlag(handle->eru, handle->channel);
}


/**
 * @brief  Clears the ETLx(x= [0..3]) status flag.
 * @param  handle pointer to the EVENT_DETECTOR APP configuration.
 * @return None
 * <BR>
 *
 * \par<b>Description:</b><br>
 * If auto clear of the status flag is not enabled, EVENT_DETECTOR_ClearStatusFlag() has to be invoked to clear the
 * flag. So that next event is considered as a new event.
 *
 * Example Usage:
 * 
 * @code
 * #include "DAVE.h"
 * int main(void)
 * {
 *  // ... Initializes Apps configurations ...
 *  DAVE_Init(); //EVENT_DETECTOR_Init(&EVENT_DETECTOR_0) will be called from DAVE_Init()
 *  
 *  //user logic
 *  
 *  EVENT_DETECTOR_ClearStatusFlag(&EVENT_DETECTOR_0);
 *  while(1U)
 *  {
 *  }
 *  return (1U);
 * }
 *
 * @endcode<BR>
 */
__STATIC_INLINE void EVENT_DETECTOR_ClearStatusFlag(const EVENT_DETECTOR_t *const handle)
{
  /* Checking for null handle */
  XMC_ASSERT("EVENT_DETECTOR_ClearStatusFlag:handle NULL" , (handle != NULL));
  XMC_ERU_ETL_ClearStatusFlag(handle->eru, handle->channel);
}


/**
 * @brief  Returns the ETLx(x= [0..3]) status flag state.
 * @param  handle pointer to the EVENT_DETECTOR APP configuration.
 * @return uint32_t returns flag bit status
 * <BR>
 *
 * \par<b>Description:</b><br>
 * EVENT_DETECTOR_GetStatusFlag() can be used to check the whether any selected edge event is detected or not.
 *
 * @code
 * #include "DAVE.h"
 * int main(void)
 * {
 *  uint32_t event_status;
 *  // ... Initializes Apps configurations ...
 *  DAVE_Init(); //EVENT_DETECTOR_Init(&EVENT_DETECTOR_0) will be called from DAVE_Init()
 *  
 *  //user logic
 *  
 *  event_status = EVENT_DETECTOR_GetStatusFlag(&EVENT_DETECTOR_0);
 *  while(1U)
 *  {
 *  }
 *  return (1U);
 * }
 *
 * @endcode<BR>
 */
__STATIC_INLINE uint32_t EVENT_DETECTOR_GetStatusFlag(const EVENT_DETECTOR_t *const handle)
{
  /* Checking for null handle */
  XMC_ASSERT("EVENT_DETECTOR_GetStatusFlag:handle NULL" , (handle != NULL));
  return XMC_ERU_ETL_GetStatusFlag(handle->eru, handle->channel);
}

/**
 *@}
 */

#include "event_detector_extern.h"

#ifdef __cplusplus
}
#endif

#endif /* EVENT_DETECTOR_H */
