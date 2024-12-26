/*
 * SEMIDRIVE Copyright Statement
 * Copyright (c) SEMIDRIVE. All rights reserved
 *
 * This software and all rights therein are owned by SEMIDRIVE, and are
 * protected by copyright law and other relevant laws, regulations and
 * protection. Without SEMIDRIVE's prior written consent and/or related rights,
 * please do not use this software or any potion thereof in any form or by any
 * means. You may not reproduce, modify or distribute this software except in
 * compliance with the License. Unless required by applicable law or agreed to
 * in writing, software distributed under the License is distributed on
 * an "AS IS" basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.
 *
 * You should have received a copy of the License along with this program.
 * If not, see <http://www.semidrive.com/licenses/>.
 */

/**
 * @file  Gpt.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Gpt
 */

#ifndef GPT_H
#define GPT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Gpt_Ip_E3.h"

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
#include "EcuM.h"
#endif

/* Version and Check Begin */
/* Version Info Begin */
#define GPT_H_VENDOR_ID    0x8C
#define GPT_H_AR_RELEASE_MAJOR_VERSION    4
#define GPT_H_AR_RELEASE_MINOR_VERSION    3
#define GPT_H_AR_RELEASE_REVISION_VERSION 1
#define GPT_H_SW_MAJOR_VERSION    1
#define GPT_H_SW_MINOR_VERSION    0
#define GPT_H_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((GPT_H_AR_RELEASE_MAJOR_VERSION != STD_TYPES_H_AR_RELEASE_MAJOR_VERSION)\
    || (GPT_H_AR_RELEASE_MINOR_VERSION != STD_TYPES_H_AR_RELEASE_MINOR_VERSION)\
    || (GPT_H_AR_RELEASE_REVISION_VERSION != STD_TYPES_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Gpt.h and Std_Types.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((GPT_H_SW_MAJOR_VERSION != STD_TYPES_H_SW_MAJOR_VERSION)\
    || (GPT_H_SW_MINOR_VERSION != STD_TYPES_H_SW_MINOR_VERSION)\
    || (GPT_H_SW_PATCH_VERSION != STD_TYPES_H_SW_PATCH_VERSION))
#error "Opps, Gpt.h and Std_Types.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */


#define GPT_MODULE_ID                       (100u)


/* SERVICE ID */
#define GPT_INIT_ID     ((uint8)0x01U)
#define GPT_DEINIT_ID   ((uint8)0x02U)
#define GPT_START_TIMER_ID ((uint8)0x03U)
#define GPT_STOP_TIMER_ID ((uint8)0x04U)
#define GPT_GET_TIME_ELAPSED_ID ((uint8)0x05U)
#define GPT_GET_TIME_REMAINING_ID ((uint8)0x06U)
#define GPT_ENABLE_NOTIFICATION_ID ((uint8)0x07U)
#define GPT_DISABLE_NOTIFICATION_ID ((uint8)0x08U)
#define GPT_GET_PREDEF_TIME_ID ((uint8)0x09U)
#define GPT_GET_VERSION_INFO_ID ((uint8)0x0AU)
/* ERROR CODE  */
#define GPT_E_INVALID_CALL    ((uint8)0xA0U)
#define GPT_E_UNINIT        ((uint8)0x0AU)
#define GPT_E_BUSY          ((uint8)0x0BU)
#define GPT_E_ALREADY_INITIALIZED   ((uint8)0x0DU)
#define GPT_E_PARAM_CHANNEL ((uint8)0x14U)
#define GPT_E_PARAM_VALUE   ((uint8)0x15U)
#define GPT_E_PARAM_POINTER  ((uint8)0x16U)
#define GPT_E_MODE                                ((uint8)0x0CU)
#define GPT_E_PARAM_PREDEF_TIMER                  ((uint8)0x17U)
#define GPT_E_INIT_FAILED                  ((uint8)0x0EU)

/* MODULE ID */
#define GPT_INSTANCE_ID   ((uint8)0U)

#if (GPT_VERSION_INFO_API == STD_ON)
/**
 * @brief Get version information of module
 * @param[in]  ConfigPtr Pointer to a selected configuration structure
 * @return   none
*/
FUNC(void, GPT_CODE) Gpt_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, GPT_APPL_DATA) VerInfoPtr
);
#endif /*GPT_VERSION_INFO_API == STD_ON */

/**
 * @brief Initializes the GPT driver
 * @details Init
 * @param[in]  ConfigPtr Pointer to a selected configuration structure
 * @return   none
*/
FUNC(void, GPT_CODE) Gpt_Init
(
    P2CONST(Gpt_ConfigType, AUTOMATIC, GPT_APPL_CONST) ConfigPtr
);

#if (GPT_DEINIT_API == STD_ON)
/**
 *@brief Deinitializes the GPT driver.
 *@param[in] none
 *@param[out] none
 *@return none
*/
FUNC(void, AUTOMATIC) Gpt_DeInit
(
    void
);
#endif

#if (GPT_TIME_ELAPSED_API == STD_ON)
/**
 * @brief Returns the time already elapsed.
 * @param[in] channel  Numeric identifier of the GPT channel.
 * @return     Elapsed timer value (in number of ticks)
 * @details - return 0, when timer channel in state "initialized"
 *          - return elapsed timeer value in normal
 *          - return return the time value at the moment of stopping,when timer channel in state "stoped"
 *          - return target time,when a timer channel configured for "one-shot mode" in state "expired"
*/
FUNC(Gpt_ValueType, GPT_CODE) Gpt_GetTimeElapsed
(
    VAR(Gpt_ChannelType, AUTOMATIC) Channel
);
#endif /* GPT_TIME_ELAPSED_API == STD_ON */

#if (GPT_TIME_REMAINING_API == STD_ON)
/**
 * @brief: Returns the time remaining until the target time is reached
 * @param[in]: Channel --- Numeric identifier of the GPT channel.
 * @param[out]: NONE
 * @return: Remaining timer value (in number of ticks)
*/
FUNC(Gpt_ValueType, GPT_CODE) Gpt_GetTimeRemaining
(
    VAR(Gpt_ChannelType, AUTOMATIC) Channel
);
#endif /* GPT_TIME_REMAINING_API == STD_ON */

/**
 * @brief Start a timer channel.
 * @details Start a timer channel.
 * @param[in] Channel Numeric identifier of the GPT channel.
 * @param[in] Value  Target time in number of ticks.
 * @return   none
*/
FUNC(void, GPT_CODE) Gpt_StartTimer
(
    VAR(Gpt_ChannelType, AUTOMATIC) Channel,
    VAR(Gpt_ValueType, AUTOMATIC) Value
);

/**
 * @brief Stop a timer channel.
 * @details Stop a timer channel.
 * @param[in] Channel Numeric identifier of the GPT channel.
 * @return   none
*/
FUNC(void, GPT_CODE) Gpt_StopTimer
(
    VAR(Gpt_ChannelType, AUTOMATIC) Channel
);

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
/**
 * @brief Enables the interrupt notification for a channel (relevant in normal mode).
 * @param[in] Channel Numeric identifier of the GPT channel.
 * @return none
*/
FUNC(void, GPT_CODE) Gpt_EnableNotification
(
    VAR(Gpt_ChannelType, AUTOMATIC) Channel
);

/**
 * @brief Disables the interrupt notification for a channel (relevant in normal mode)
 * @param[in] Channel Numeric identifier of the GPT channel.
 * @return none
*/
FUNC(void, GPT_CODE) Gpt_DisableNotification
(
    VAR(Gpt_ChannelType, AUTOMATIC) Channel
);
#endif /* GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON */

/**
 * @brief Not support mode change.
*/
FUNC(void, GPT_CODE) Gpt_SetMode
(
    VAR(Gpt_ModeType, AUTOMATIC) Mode
);

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/**
 * @brief Not support wakeup.
*/
FUNC(void, GPT_CODE) Gpt_DisableWakeup
(
    VAR(Gpt_ChannelType, AUTOMATIC) Channel
);

/**
 * @brief Not support wakeup.
*/
FUNC(void, GPT_CODE) Gpt_EnableWakeup
(
    VAR(Gpt_ChannelType, AUTOMATIC) Channel
);

/**
 * @brief Not support wakeup.
*/
FUNC(void, GPT_CODE) Gpt_CheckWakeup
(
    VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource
);
#endif

#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/**
 * @brief Delivers the current value of the desired GPT Predef Timer.
 * @param[in] PredefTimer  Numeric identifier of the GPT channel.
 * @param[in] pTimeValue Pointer to get time value.
 * @return E_OK or E_NOT_OK
 *  @retval E_OK 0
 *  @retval E_NOT_OK 1
*/
FUNC(Std_ReturnType, GPT_CODE) Gpt_GetPredefTimerValue
(
    VAR(Gpt_PredefTimerType, AUTOMATIC) PredefTimer,
    P2VAR(uint32, AUTOMATIC, GPT_APPL_DATA) pTimeValue
);
#endif

/**
 * @brief Interrupt.
 * @param[in] eModule  The Module that produced a interrupt.
 * @return NONE
*/
FUNC(void, AUTOMATIC) Gpt_Irq
(
    VAR(Gpt_HwModule, AUTOMATIC) eModule
);

#ifdef __cplusplus
}
#endif

#endif /*GPT_H*/
