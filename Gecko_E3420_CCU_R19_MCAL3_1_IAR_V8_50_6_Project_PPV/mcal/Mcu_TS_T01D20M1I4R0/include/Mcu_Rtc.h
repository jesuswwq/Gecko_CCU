/** *****************************************************************************************************
 * SEMIDRIVE Copyright Statement                                                                        *
 * Copyright (c) SEMIDRIVE. All rights reserved                                                         *
 *                                                                                                      *
 * This software and all rights therein are owned by SEMIDRIVE, and are                                 *
 * protected by copyright law and other relevant laws, regulations and                                  *
 * protection. Without SEMIDRIVE's prior written consent and/or related rights,                         *
 * please do not use this software or any potion thereof in any form or by any                          *
 * means. You may not reproduce, modify or distribute this software except in                           *
 * compliance with the License. Unless required by applicable law or agreed to                          *
 * in writing, software distributed under the License is distributed on                                 *
 * an 'AS IS' basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.                         *
 *                                                                                                      *
 *******************************************************************************************************/
/** *****************************************************************************************************
 *  \file     Mcu_Rtc.h                                                                           *
 *  \brief    This file contains interface header for MCU_Rtc MCAL driver                             *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/03     <td>1.0.0                               *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef MCU_RTC_H
#define MCU_RTC_H


#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Std_Types.h"
#include "Mcal.h"
#include "Mcu_Cfg.h"

/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
/** \brief  The RTC Timer tick max value. */
#define RTC_TICK_MAX    0xffffffffffffUL

/********************************************************************************************************
 *                                  Global Types definition                                             *
 *******************************************************************************************************/
/** \brief  RTC Timer Hardware module support. */
typedef enum
{
    RTC1 = 0U,
    RTC2,
    ALL,
} Mcu_RtcChannelType;

/** \brief  RTC Timer Hardware mode support. */
typedef enum
{
    RTC_TIMER_MODE_SEC = 0U,
    RTC_TIMER_MODE_MIN,
    RTC_TIMER_MODE_INVALID = 0xFFU,
} Mcu_RtcTimerModeType;

/** \brief  RTC Time Member description. */
typedef struct
{
    uint8  seconds;             /** \brief seconds of the minute, [0,59] */
    uint8  minutes;             /** \brief minutes of the hour, [0,59] */
    uint8  hours;               /** \brief hour of the day, [0,23] */
    uint8  weekday;             /** \brief Weekday since Sun, [0,6] */
    uint8  day;                 /** \brief day of the month, [1,31] */
    uint8  month;               /** \brief months since Jan, [0,11] */
    uint16 year;                /** \brief years since 1970 */
} Mcu_RtcTimeType;

/** \brief  RTC Alarm Time Member description. */
typedef struct
{
    uint8  seconds;             /** \brief seconds of the minute, [0,59] */
    uint8  minutes;             /** \brief minutes of the hour, [0,59] */
    uint8  hours;               /** \brief hour of the day, [0,23] */
    uint8  weekday;             /** \brief Weekday since Sun, [0,6] */
    uint8  day;                 /** \brief day of the month, [1,31] */
} Mcu_RtcAlarmTimeType;

/** \brief  RTC Sleep Time attribute description. */
typedef uint16 Mcu_RtcSleepTimeType;

/** \brief  RTC Timer Callback notification type. */
typedef uint32 (*Mcu_AlarmNotifyType)(void *para);

/** \brief  RTC Timer Adjust type. */
typedef struct
{
    uint16 period;              /** \brief period to do Increase (or Decrease) */
    uint16 cycle;               /** \brief the cycles will be added to (or substracted from) rtc
                                        counter per period * 1024 rtc cycles */
    boolean direction;          /** \brief 0 - Increase; 1 - Decrease */
    /*PRQA S 1535 1*/
} Mcu_RtcAdjustType;

/** \brief  RTC Timer Alarm type. */
typedef struct
{
    Mcu_RtcChannelType channel;
    Mcu_RtcTimerModeType timerMode1;    /** \brief 0 - sec; 1 - min */
    uint16       timer1;                /** \brief rtc timer counter */
    Mcu_RtcTimerModeType timerMode2;    /** \brief 0 - sec; 1 - min */
    uint16       timer2;                /** \brief rtc timer counter */
} Mcu_RtcAlarmType;

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/

/** *****************************************************************************************************
 * \brief This function is used to enable RTC Timer.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_Ip_RtcEnable
 *                      (
 *                          uint32 base
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : base - The RTC Timer base address.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK - The Executed successfully.
 *                      MCU_E_REGLOCKED - The RTC Timer is locked.
 *                      MCU_E_TIMEOUT - The wait tmeout.
 *
 * Description        : Frequently disabling the RTC Timer may trigger the rtc_disable interrupt.
 *                      User must manually clear the rtc_disable interrupt flag.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_055 SWSR_MCU_054 SWSR_MCU_005
 *******************************************************************************************************/
Std_ReturnType Mcu_Ip_RtcEnable(uint32 base);

/** *****************************************************************************************************
 * \brief This function is used to disable RTC Timer.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_Ip_RtcDisable
 *                      (
 *                          uint32 base
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : base - The RTC Timer base address.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK - The Executed successfully.
 *                      MCU_E_REGLOCKED - The RTC Timer is locked.
 *                      MCU_E_TIMEOUT - The wait tmeout.
 *
 * Description        : Frequently disabling the RTC Timer may trigger the rtc_disable interrupt.
 *                      User must manually clear the rtc_disable interrupt flag.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_055 SWSR_MCU_054 SWSR_MCU_005
 *******************************************************************************************************/
Std_ReturnType Mcu_Ip_RtcDisable(uint32 base);

/** *****************************************************************************************************
 * \brief This function is used to set wakeup time for RTC Timer.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_Ip_RtcSetupWakeup
 *                      (
 *                          uint32 base,
 *                          uint64 interval
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : base - The RTC Timer base address.
 *                      interval - The sleep time tick value.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The software will write the final sleep value to the TIMER register based
 *                      on the current tick value plus interval value.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_055 SWSR_MCU_054 SWSR_MCU_005
 *******************************************************************************************************/
Std_ReturnType Mcu_Ip_RtcSetupWakeup(uint32 base, uint64 interval);

/** *****************************************************************************************************
 * \brief This function is used to get IRQ status for RTC Timer.
 *
 * \verbatim
 * Syntax             : boolean Mcu_Ip_RtcIsWakenup
 *                      (
 *                          uint32 base
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : base - The RTC Timer base address.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The TIMER register RTC equal or larger than RTC register value, this return 1.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005
 *******************************************************************************************************/
boolean Mcu_Ip_RtcIsWakenup(uint32 base);

/** *****************************************************************************************************
 * \brief This function is used to interrupt handle for RTC Timer1.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_RtcIrqHandler1
 *                      (
 *                          void
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        :
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005
 *******************************************************************************************************/
ISR(Mcu_Ip_RtcIrqHandler1);

/** *****************************************************************************************************
 * \brief This function is used to interrupt handle for RTC Timer2.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_RtcIrqHandler2
 *                      (
 *                          void
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        :
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005
 *******************************************************************************************************/
ISR(Mcu_Ip_RtcIrqHandler2);

/** *****************************************************************************************************
 * \brief This function is used to set time for RTC Timer.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_Ip_RtcSetTime
 *                      (
 *                          uint32 base,
 *                          Mcu_RtcTimeType *rtcTimePtr
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : base - The RTC Timer base address.
 *                      rtcTimePtr - The time pointer.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK - The Executed successfully.
 *                      MCU_E_PARAM_POINTER - The Parameter NULL.
 *
 * Description        :
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_055 SWSR_MCU_054 SW_SM006 SWSR_MCU_005
 *******************************************************************************************************/
Std_ReturnType Mcu_Ip_RtcSetTime(uint32 base, const Mcu_RtcTimeType *const rtcTimePtr);

/** *****************************************************************************************************
 * \brief This function is used to get time for RTC Timer.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_Ip_RtcGetTime
 *                      (
 *                          uint32 base,
 *                          Mcu_RtcTimeType *rtcTimePtr
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : base - The RTC Timer base address.
 *                      rtcTimePtr - The time pointer.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK - The Executed successfully.
 *                      MCU_E_PARAM_CONFIG - The Parameter invalid.
 *                      MCU_E_TIMEOUT - The Wait timeout.
 *
 * Description        :
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_055 SWSR_MCU_054 SWSR_MCU_005
 *******************************************************************************************************/
Std_ReturnType Mcu_Ip_RtcGetTime(uint32 base, Mcu_RtcTimeType *rtcTimePtr);

/** *****************************************************************************************************
 * \brief This function is used to set alarm time for RTC Timer.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_Ip_RtcSetAlarmTime
 *                      (
 *                          uint32 base,
 *                          Mcu_RtcAlarmTimeType *rtcAlarmTimePtr,
 *                          Mcu_AlarmNotifyType notify
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : base - The RTC Timer base address.
 *                      rtcAlarmTimePtr - The alarm time pointer.
 *                      notify - The RTC Timer alarm Notification function.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK - The Executed successfully.
 *                      MCU_E_PARAM_CONFIG - The Parameter invalid.
 *                      MCU_E_TIMEOUT - The Wait timeout.
 *
 * Description        : When the alarm is set, the current tick value is automatically read. If the
 *                      set alarm value is smaller than this tick, the setting does not take effect.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_055 SWSR_MCU_054 SWSR_MCU_005
 *******************************************************************************************************/
Std_ReturnType Mcu_Ip_RtcSetAlarmTime(uint32 base,
                                      const Mcu_RtcAlarmTimeType *const rtcAlarmTimePtr,
                                      Mcu_AlarmNotifyType notify);

/** *****************************************************************************************************
 * \brief This function is used to get alarm time for RTC Timer.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_Ip_RtcGetAlarmTime
 *                      (
 *                          uint32 base,
 *                          Mcu_RtcAlarmTimeType *rtcAlarmTimePtr
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : base - The RTC Timer base address.
 *                      rtcAlarmTimePtr - The alarm time pointer.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK - The Executed successfully.
 *                      MCU_E_PARAM_CONFIG - The Parameter invalid.
 *                      MCU_E_TIMEOUT - The Wait timeout.
 *
 * Description        : Before calling this function, you must call Mcu_Ip_RtcSetAlarmTime to set
 *                      the alarm value and enable IRQ_enable.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_055 SWSR_MCU_054 SWSR_MCU_005
 *******************************************************************************************************/
Std_ReturnType Mcu_Ip_RtcGetAlarmTime(uint32 base, Mcu_RtcAlarmTimeType *rtcAlarmTimePtr);

/** *****************************************************************************************************
 * \brief This function is used to set sleep time for RTC Timer.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_Ip_RtcSetSleepTime
 *                      (
 *                          uint32 base,
 *                          Mcu_RtcSleepTimeType *timerTime,
 *                          Mcu_RtcTimerModeType *timerMode
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : base - The RTC Timer base address.
 *                      timerTime - The tick value.
 *                      timerMode - The tick mode.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK - The Executed successfully.
 *                      MCU_E_REGLOCKED - is locked.
 *                      E_NOT_OK - The Parameter invalid.
 *                      MCU_E_TIMEOUT - The Wait timeout.
 *
 * Description        :
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_055 SWSR_MCU_054 SWSR_MCU_005
 *******************************************************************************************************/
Std_ReturnType Mcu_Ip_RtcSetSleepTime(uint32 base, Mcu_RtcSleepTimeType timerTime,
                                      Mcu_RtcTimerModeType timerMode);

/** *****************************************************************************************************
 * \brief This function is used to get sleep time for RTC Timer.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_Ip_RtcGetSleepTime
 *                      (
 *                          uint32 base,
 *                          Mcu_RtcSleepTimeType *timerTimePtr,
 *                          Mcu_RtcTimerModeType *timerModePtr
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : base - The RTC Timer base address.
 *                      timerTimePtr - The sleep time value.
 *                      timerModePtr - The sleep time mode.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK - The Executed successfully.
 *                      MCU_E_REGLOCKED - is locked.
 *                      E_NOT_OK - The Parameter invalid.
 *                      MCU_E_TIMEOUT - The Wait timeout.
 *
 * Description        : After clearing the RTC Timer counter, the user must re-enable the RTC Timer.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_055 SWSR_MCU_054 SWSR_MCU_005
 *******************************************************************************************************/
Std_ReturnType Mcu_Ip_RtcGetSleepTime(uint32 base, Mcu_RtcSleepTimeType *timerTimePtr,
                                      Mcu_RtcTimerModeType *timerModePtr);

/** *****************************************************************************************************
 * \brief This function is used to clear counter for RTC Timer.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_Ip_RtcClearTimerCounter
 *                      (
 *                          uint32 base
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : base - The RTC Timer base address.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK - The Executed successfully.
 *                      MCU_E_REGLOCKED - is locked.
 *                      E_NOT_OK - The Parameter invalid.
 *                      MCU_E_TIMEOUT - The Wait timeout.
 *
 * Description        : After clearing the RTC Timer counter, the user must re-enable the RTC Timer.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_055 SWSR_MCU_054 SWSR_MCU_005
 *******************************************************************************************************/
Std_ReturnType Mcu_Ip_RtcClearTimerCounter(uint32 base);

/** *****************************************************************************************************
 * \brief This function is used to get wakeup status for RTC Timer.
 *
 * \verbatim
 * Syntax             : uint8 Mcu_Ip_RtcGetWakeupFlag
 *                      (
 *                          uint32 base
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : base - The RTC Timer base address.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 1 - The RTC counter equal or larger than RTL timer value.
 *                      0 - other.
 *
 * Description        :
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005
 *******************************************************************************************************/
uint8 Mcu_Ip_RtcGetWakeupFlag(uint32 base);

/** *****************************************************************************************************
 * \brief This function is used to clear IRQ status for RTC Timer.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_Ip_RtcClearWakeupFlag
 *                      (
 *                          uint32 base
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : base - The RTC Timer base address.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK - The Executed successfully.
 *                      MCU_E_TIMEOUT - The wait timeout.
 *
 * Description        : When interrupt nesting is enabled in the interrupt handler function, if the
 *                      Mcu_Ip_RtcClearWakeupFlag function is called with IRQ turned on again, it
 *                      is possible to get caught in a loop during the process of clearing the
 *                      interrupt state of the RTC Timer (it is strongly recommended to disable IRQ
 *                      enable first). When the RTC Timer is in the 32KHzdomian state, the CPU can
 *                      perform the next operation only after signal synchronization is complete.
 * \endverbatim
 * Traceability       : SWSR_MCU_055 SWSR_MCU_054 SWSR_MCU_005
 *******************************************************************************************************/
Std_ReturnType Mcu_Ip_RtcClearWakeupFlag(uint32 base);

/** *****************************************************************************************************
 * \brief This function is used to disable register parity errInj for RTC Timer.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_RtcDisableRegParityErrIntEnable
 *                      (
 *                          uint32 base
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : base - The RTC Timer base address.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : When the clock switching of pclk is performed, the register annotation
 *                      function must be turned off, otherwise the sem error will be triggered.
 * \endverbatim
 * Traceability       : SWSR_MCU_005
 *******************************************************************************************************/
void Mcu_Ip_RtcDisableRegParityErrIntEnable(uint32 base);

/** *****************************************************************************************************
 * \brief This function is used to enable register parity errInj for RTC Timer.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_RtcEnableRegParityErrIntEnable
 *                      (
 *                          uint32 base
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : base - The RTC Timer base address.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function must be enabled when the sem needs to monitor the register
 *                      parity errinj of the RTC Timer.
 * \endverbatim
 * Traceability       : SWSR_MCU_005
 *******************************************************************************************************/
void Mcu_Ip_RtcEnableRegParityErrIntEnable(uint32 base);

#if (MCU_RTC_DOMAIN_SS_DYNAMIC_PCLK == STD_ON)
/** *****************************************************************************************************
 * \brief This function is used to enable pclk for RTC domain.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_RtcDomainPclkEnable(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function is used to enable pclk for RTC domain. only effective when
 *                      MCU_RTC_DOMAIN_SS_DYNAMIC_PCLK is set to STD_ON.
 * \endverbatim
 * Traceability       : SWSR_MCU_005
 *******************************************************************************************************/
void Mcu_Ip_RtcDomainPclkEnable(void);

/** *****************************************************************************************************
 * \brief This function is used to disable pclk for RTC domain.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_RtcDomainPclkDisable(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function is used to disable pclk for RTC domain. only effective when
 *                      MCU_RTC_DOMAIN_SS_DYNAMIC_PCLK is set to STD_ON.
 * \endverbatim
 * Traceability       : SWSR_MCU_005
 *******************************************************************************************************/
void Mcu_Ip_RtcDomainPclkDisable(void);
#endif /* MCU_RTC_DOMAIN_SS_DYNAMIC_PCLK == STD_ON */

#if (MCU_RTC_DOMAIN_SS_DYNAMIC_PCLK == STD_ON)
/** @brief RTC domain PCLK switch reference count. */
extern sint32 McuRtcSSPclkRef;
#endif /* MCU_RTC_DOMAIN_SS_DYNAMIC_PCLK == STD_ON */

/** @brief Dynamically switching the RTC Domain clock is only effective when
 * MCU_RTC_DOMAIN_SS_DYNAMIC_PCLK is set to STD_ON. */
#if (MCU_RTC_DOMAIN_SS_DYNAMIC_PCLK == STD_ON)
#define RTC_DOMAIN_SS_HOOK_ENTER()     Mcu_Ip_RtcDomainPclkEnable()
#define RTC_DOMAIN_SS_HOOK_EXIT()      Mcu_Ip_RtcDomainPclkDisable()
#else
#define RTC_DOMAIN_SS_HOOK_ENTER()
#define RTC_DOMAIN_SS_HOOK_EXIT()
#endif /* MCU_RTC_DOMAIN_SS_DYNAMIC_PCLK == STD_ON */

#ifdef __cplusplus
}
#endif

#endif /* MCU_RTC_H */
/* End of file */
