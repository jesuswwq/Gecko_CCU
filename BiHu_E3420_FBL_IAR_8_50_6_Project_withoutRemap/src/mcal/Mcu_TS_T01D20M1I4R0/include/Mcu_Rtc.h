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

#ifndef MCU_RTC_H
#define MCU_RTC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "Mcal.h"
/* Version and Check Begin */
/* Version Info Begin */
#define MCU_RTC_H_VENDOR_ID    0x8C
#define MCU_RTC_H_AR_RELEASE_MAJOR_VERSION    4
#define MCU_RTC_H_AR_RELEASE_MINOR_VERSION    3
#define MCU_RTC_H_AR_RELEASE_REVISION_VERSION 1
#define MCU_RTC_H_SW_MAJOR_VERSION    1
#define MCU_RTC_H_SW_MINOR_VERSION    0
#define MCU_RTC_H_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((MCU_RTC_H_AR_RELEASE_MAJOR_VERSION != STD_TYPES_H_AR_RELEASE_MAJOR_VERSION)\
    || (MCU_RTC_H_AR_RELEASE_MINOR_VERSION != STD_TYPES_H_AR_RELEASE_MINOR_VERSION)\
    || (MCU_RTC_H_AR_RELEASE_REVISION_VERSION != STD_TYPES_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Mcu_Rtc.h and Std_Types.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((MCU_RTC_H_SW_MAJOR_VERSION != STD_TYPES_H_SW_MAJOR_VERSION)\
    || (MCU_RTC_H_SW_MINOR_VERSION != STD_TYPES_H_SW_MINOR_VERSION)\
    || (MCU_RTC_H_SW_PATCH_VERSION != STD_TYPES_H_SW_PATCH_VERSION))
#error "Opps, Mcu_Rtc.h and Std_Types.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

typedef enum {
    RTC1,
    RTC2,
    ALL,
} Rtc_ChannelType;

#define RTC_TICK_MAX    0xffffffffffffull

typedef struct {
    uint8  Seconds;     /* seconds of the minute, [0,59] */
    uint8  Minutes;     /* minutes of the hour, [0,59] */
    uint8  Hours;       /* hour of the day, [0,23] */
    uint8  Weekday;     /* Weekday since Sun, [0,6] */
    uint8  Day;         /* day of the month, [1,31] */
    uint8  Month;       /* months since Jan, [0,11] */
    uint16 Year;        /* years since 1970 */
} Rtc_TimeType;

typedef struct {
    uint8  Seconds;     /* seconds of the minute, [0,59] */
    uint8  Minutes;     /* minutes of the hour, [0,59] */
    uint8  Hours;       /* hour of the day, [0,23] */
    uint8  Weekday;     /* Weekday since Sun, [0,6] */
    uint8  Day;         /* day of the month, [1,31] */
} Rtc_AlarmTimeType;

typedef uint32 Rtc_ConfigType;

typedef uint16 Rtc_SleepTimeType;

typedef enum {
    RTC_TIMER_MODE_SEC,
    RTC_TIMER_MODE_MIN,
    RTC_TIMER_MODE_INVALID = 0xFF,
} Rtc_TimerModeType;

typedef uint32 (*AlarmNotifyType)(void *para);

typedef struct {
    uint16 period;      /**< @brief period to do Increase (or Decrease) */
    uint16 cycle;       /**< @brief the cycles will be added to (or substracted from) rtc
                                    counter per period * 1024 rtc cycles */
    boolean direction;  /**< @brief 0 - Increase; 1 - Decrease */
} rtc_adjust_t;

typedef struct {
    Rtc_ChannelType channel;
    Rtc_TimerModeType timermode1;/**< @brief 0 - sec; 1 - min */
    uint16       timer1;      /**< @brief rtc timer counter */
    //boolean direction1;  /**< @brief 0 - Increase; 1 - Decrease */
    Rtc_TimerModeType timermode2;/**< @brief 0 - sec; 1 - min */
    uint16       timer2;      /**< @brief rtc timer counter */
    //boolean direction2;  /**< @brief 0 - Increase; 1 - Decrease */
} rtc_alarm_t;

/**
 * @brief   To set rtc tick.
 * @details Usually, this routine used to set 'start point' of RTC. When setting tick, rtc shall
 *          be in disabled mode.
 * @param[in] base  The base address of RTC to be set
 * @param[in] tick  The tick value to be set into RTC
 */
Std_ReturnType Mcu_RtcSetTick(uint32 base, uint64 tick);

/**
 * @brief   To update register set.
 * @details If other register has been configured,set this register to update other register configure.
 * @param[in] base  The base address of RTC to be set
 */
void Mcu_RtcRegisterCrossLockEn(uint32 base);

/**
 * @brief   To enable rtc.
 * @details This function enable rtc, set secure bit(rtc accessible cpus which in
 *          secure mode) and lock it.
 * @param[in] base  The base address of RTC to be set
 */
void Mcu_RtcEnable(uint32 base);

/**
 * @brief   To disable rtc.
 * @details This function disable rtc, set secure bit(rtc accessible cpus which in
 *          secure mode) and lock it.
 * @param[in] base  The base address of RTC to be set
 */
void Mcu_RtcDisable(uint32 base);

/**
 * @brief   To switch Rtc source clock from internal RC to external XTAL.
 * @details This function enable external XTAL if it not enabled yet. And switch Rtc
 *          source clock from internal RC to external XTAL if XTAL locked. If not
 *          locked, this function returns FALSE. For the first RTC power-up cycle,
 *          XTAL need ~1s to be locked.
 * @param[in] base  The base address of RTC to be set
 */
boolean Mcu_RtcTrySwitchToXtal(uint32 base);

/**
 * @brief   To read rtc tick
 * @param[in] base  The base address of RTC
 */
uint64 Mcu_RtcReadTick(uint32 base);

/**
 * @brief   Adjust rtc tick to compensate the drift of rtc clock.
 * @details For 'increase', 'cycle' added to rtc counter per 'period' * 1024 ticks.
 *          For 'descrease', 'cycle' sub from rtc counter per 256 * 1024 ticks.
 * @param[in] base  The base address of RTC
 * @param[in] adjust    Pointing the adjust parameters.
 */
Std_ReturnType Mcu_RtcAutoAdjust(uint32 base, rtc_adjust_t *adjust);

/**
 * @brief Setup wakeup timeout of the RTC
 * @details This function read the current rtc tick, adds the interval then set the wakeup
 *          point (current_tick + interval).
 * @param[in] base  The base address of RTC
 * @param[in] interval  the interval where the rtc wakeup asserts. In tick (usaually in 32.768KHz).
 */
Std_ReturnType Mcu_RtcSetupWakeup(uint32 base, uint64 interval);

/**
 * @brief To check if a rtc wakeup occured.
 * @param[in] base  The base address of RTC
 * @return  TRUE if rtc wakeup occured, FALSE if otherwise
 */
boolean Mcu_RtcIsWakenup(uint32 base);

/**
 * @brief Callback of rtc after a wakeup.
 * @details After a resume, rtc enabled, wakeup enabled and wakeup_irq still asserted.
 *          SW shall call this routine to clear wakeup_irq/wakeup_en. Then wakeup can
 *          still be setup by calling rtc_setup_wakeup.
 *          Note: Call this routine after every resuming.
 * @param[in] base  The base address of RTC
 */
void Mcu_RtcResumeCb(uint32 base);

/**
 * @brief Setup alarm timeout of the RTC
 * @details This function read the current rtc tick, adds the interval then set the alarm
 *          point (current_tick + interval) with 'Req' cleared.
 * @param[in] base  The base address of RTC
 * @param[in] interval  the interval where the rtc wakeup asserts. In tick (usaually in 32.768KHz).
 * @param[in] notify    The notification callback which will be called by RTC driver when alarm
 *                      asserts.
 */
Std_ReturnType Mcu_RtcSetupAlarm(uint32 base, uint64 interval, AlarmNotifyType notify);

/**
 * @brief rtc1 interrupt handler
 */
void rtc1_IrqHandler(void);

/**
 * @brief rtc2 interrupt handler
 */
void rtc2_IrqHandler(void);

/**
 * @brief   To enable rtc.
 * @details This function enable rtc, set secure bit(rtc accessible cpus which in
 *          secure mode) and lock it.
 * @param[in] base  The base address of RTC to be set
 */
void Rtc_Init(const Rtc_ConfigType *configPtr);

/**
 * @brief   To juge date.
 * @details This function juge wrong date.
 * @param[in] rtcTime  the rtc time:Seconds/Minutes/Hours/Weekday/Day/Month/Year.
 */
Std_ReturnType Rtc_IsDate(const Rtc_TimeType *const rtcTime );

/**
 * @brief Set Current time of the RTC
 * @details This function set the current rtc tick.
 * @param[in] index  The index of RTC
 * @param[in] rtcTime  the rtc time:Seconds/Minutes/Hours/Weekday/Day/Month/Year.
 */
Std_ReturnType Rtc_SetTime(uint32 base, const Rtc_TimeType *const rtcTime );

/**
 * @brief Get Current time of the RTC
 * @details This function get the current rtc tick.
 * @param[in] index  The index of RTC
 * @param[in] rtcTime  the rtc time:Seconds/Minutes/Hours/Weekday/Day/Month/Year.
 */
Std_ReturnType Rtc_GetTime(uint32 base, Rtc_TimeType *rtcTime);

/**
 * @brief Set alarm timeout of the RTC
 * @details This function set the current rtc tick, adds the interval then set the alarm
 *          point (current_tick + interval) with 'Req' cleared.
 * @param[in] index         The base address of RTC
 * @param[in] rtcAlarmTime  the interval where the rtc wakeup asserts. In tick (usaually in 32.768KHz).
 * @param[in] notify        The notification callback which will be called by RTC driver when alarm
 *                      asserts.
 */
Std_ReturnType Rtc_SetAlarmTime(uint32 base, const Rtc_AlarmTimeType *const rtcAlarmTime,
                                AlarmNotifyType notify);

/**
 * @brief Get alarm timeout of the RTC
 * @details This function get the current rtc tick, adds the interval then set the alarm
 *          point (current_tick + interval) with 'Req' cleared.
 * @param[in] index         The base address of RTC
 * @param[in] rtcAlarmTime  the interval where the rtc wakeup asserts. In tick (usaually in 32.768KHz).
 * @param[in] notify        The notification callback which will be called by RTC driver when alarm
 *                      asserts.
 */
Std_ReturnType Rtc_GetAlarmTime(uint32 base, Rtc_AlarmTimeType *rtcAlarmTime);

/**
 * @brief Clear alarm timeout of the RTC
 * @details This function clear the current rtc tick, adds the interval then set the alarm
 *          point (current_tick + interval) with 'Req' cleared.
 * @param[in] base  The base address of RTC
 */
Std_ReturnType Rtc_ClearAlarmTime(uint32 base);

/**
 * @brief Set sleep timeout of the RTC
 * @details This function set the current rtc tick, adds the interval then set the sleep alarm
 *          point (current_tick + interval) with 'Req' cleared.
 * @param[in] index      The base address of RTC
 * @param[in] timerTime  The interval where the rtc wakeup from sleep asserts. In tick (usaually in 32.768KHz).
 * @param[in] timerMode  The timer mode:SEC/MIN.
 */
Std_ReturnType Rtc_SetSleepTime(uint32 base, Rtc_SleepTimeType timerTime,
                                Rtc_TimerModeType timerMode);

/**
 * @brief Get sleep timeout of the RTC
 * @details This function get the current rtc tick, adds the interval then set the sleep alarm
 *          point (current_tick + interval) with 'Req' cleared.
 * @param[in] index      The base address of RTC
 * @param[in] timerTime  The interval where the rtc wakeup from sleep asserts. In tick (usaually in 32.768KHz).
 * @param[in] timerMode  The timer mode:SEC/MIN.
 */
Std_ReturnType Rtc_GetSleepTime(uint32 base, Rtc_SleepTimeType *timerTimePtr,
                                Rtc_TimerModeType *timerModePtr);

/**
 * @brief Clear timer of the RTC
 * @details This function clear the current rtc tick.
 * @param[in] base  The base address of RTC
 */
Std_ReturnType Rtc_ClearTimerCounter(uint32 base);

/**
 * @brief Get wakeup flag of the RTC
 * @details This function get the wakeup flag.
 * @param[in] base  The base address of RTC
 */
Std_ReturnType Rtc_GetWakeupFlag(uint32 base);

/**
 * @brief Clear wakeup flag of the RTC
 * @details This function clear the wakeup flag.
 * @param[in] base  The base address of RTC
 */
Std_ReturnType Rtc_ClearWakeupFlag(uint32 base);

/**
 * @brief disable parity error interrupt status of the RTC
 * @details This function disable parity error bit.
 * @param[in] base  The base address of RTC
 */
void Mcu_RtcDisableRegParityErrIntEnable(uint32 base);

/**
 * @brief enable parity error interrupt status of the RTC
 * @details This function enable parity error bit.
 * @param[in] base  The base address of RTC
 */
void Mcu_RtcEnableRegParityErrIntEnable(uint32 base);

#ifdef __cplusplus
}
#endif

#endif  /* ifndef MCU_RTC_H */

