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
 * \file     Mcu_Rtc.c                                                                                  *
 * \brief    AUTOSAR 4.3.1 MCAL Mcu Driver                                                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/03     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "RegHelper.h"
#include "RegBase.h"
#include "Mcu_Delay.h"
#include "Xtal_Reg.h"
#include "Mcu_Rtc.h"
#include "Rtc_Reg.h"
#include "Mcu_GeneralTypes.h"
#include "Mcu.h"
#if (MCU_RTC_DOMAIN_SS_DYNAMIC_PCLK == STD_ON)
#include "Mcu_Clk.h"
#include "SchM_Mcu.h"
#include "Mcu_CkgenDrv.h"
#include "Mcu_ClkCfgNd.h"
#endif /* MCU_RTC_DOMAIN_SS_DYNAMIC_PCLK == STD_ON */

/********************************************************************************************************
 *                                 Private Macro definition                                             *
 *******************************************************************************************************/
/** \brief  Tick convert to time. */
#define RTC_CLK_HZ                              (32U * 1024U)
#define RTC_CLK_SHIFT                           ctz32(RTC_CLK_HZ)
#define RTC_SECOND_TO_TICK(s)                   ((s) << RTC_CLK_SHIFT)
#define RTC_TICK_TO_SECOND(t)                   ((t) >> RTC_CLK_SHIFT)

/** \brief  Time calculation. */
#define SECONDS_PER_MINUTE                      (60ULL)
#define MINUTES_PER_HOUR                        (60ULL)
#define HOURS_PER_DAY                           (24ULL)
#define SECONDS_PER_HOUR                        (SECONDS_PER_MINUTE * MINUTES_PER_HOUR)
#define SECONDS_PER_DAY                         (SECONDS_PER_HOUR * HOURS_PER_DAY)

/** \brief The maximum/minmum value of the time parameter. */
#define LEAP_YEAR_DAYS                          (366ULL)
#define COMMON_YEAR_DAYS                        (365ULL)
#define TM_START_YEAR                           (1900ULL)
#define EPOCH_START_YEAR                        (1970ULL)

/** \brief Delay time for waiting for the RTC Timer to be ready. */
#define DELAY_US                                (360ULL)
#define CROSS_DELAY_US                          (50ULL)

/** \brief Delay time for waiting for the RTC Timer to be ready,
 * When RTC domain PCLK switch. */
#if (MCU_RTC_DOMAIN_SS_DYNAMIC_PCLK == STD_ON)
#define RTC_SS_ACCESS_DELAY_CYCLE(n)            Mcu_udelay(35 * n)
#else
#define RTC_SS_ACCESS_DELAY_CYCLE(n)
#endif /* MCU_RTC_DOMAIN_SS_DYNAMIC_PCLK == STD_ON */

/********************************************************************************************************
 *                                  Private Constant Definitions                                        *
 *******************************************************************************************************/
#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"
/** \brief  Record the default days of the every month. */
static const uint8 MonDays[12U] =
{
    31U, 28U, 31U, 30U, 31U, 30U, 31U, 31U, 30U, 31U, 30U, 31U
};
#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"
/********************************************************************************************************
 *                                  Private Variable Definitions                                        *
 *******************************************************************************************************/
#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"
/** \brief  Record the default initialization value of the RTC Timer. */
static Mcu_RtcTimerModeType Mcu_RtcTimerMode[2U] = {RTC_TIMER_MODE_SEC, RTC_TIMER_MODE_SEC};
#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

#define MCU_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"
/** \brief  Record the Callback notification function of the RTC Timer. */
static Mcu_AlarmNotifyType Mcu_Rtc1AlarmNotify[1];
static Mcu_AlarmNotifyType Mcu_Rtc2AlarmNotify[1];
#define MCU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

/********************************************************************************************************
 *                                  Private Function Declarations                                       *
 *******************************************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
/** *****************************************************************************************************
 * \brief This function is used to Gets the offset of the first non-zero bit.
 *
 * \verbatim
 * Syntax             : uint32 ctz32
 *                      (
 *                          uint32 x
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
static uint32 ctz32(uint32 x)
{
    uint32 i;

    for (i = 0U; i != 32U; ++i)
    {
        if (1U == ((x >> i) & 1U))
        {
            break;
        } /* else not needed */
    }

    if (32U == i)
    {
        i = 0U;
    } /* else not needed */

    return i;
}

/** *****************************************************************************************************
 * \brief This function is used to update register set.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_Ip_RtcRegisterCrossClockEn
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
 * Parameters (in)    : base  The base address of RTC to be set.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK - The Executed successfully.
 *                      MCU_E_TIMEOUT - The wait timeout.
 *
 * Description        : If other register has been configured,set this register to update other
 *                      register configure.
 *
 * \endverbatim
 * Traceability       : SW_SM005
 *******************************************************************************************************/
static Std_ReturnType Mcu_Ip_RtcRegisterCrossClockEn(uint32 base)
{
    Std_ReturnType ret = E_OK;
    uint32 timeout = 0U;
    uint32 v = readl(base + RTC_REGISTER_CROSS_CLOCK);

    v |= BM_REGISTERR_CROSS_CLOCK_EN;

    writel(v, base + RTC_REGISTER_CROSS_CLOCK);

    /* wait register set sync, 32K clock 2 cycle */
    while ((0U != readl(base + RTC_REGISTER_CROSS_CLOCK)) && (timeout < 1000UL))
    {
        timeout++;
        ret = Mcu_udelay(100U);

        if (E_OK != ret)
        {
            break;
        } /* else not needed */
    }

    if (timeout >= 1000U)
    {
        ret = MCU_E_TIMEOUT;
    } /* else not needed */

    if (E_OK == ret)
    {
        /* wait for 50us, The clock bus has the problem of crossing the clock critical area */
        ret = Mcu_udelay((uint32)CROSS_DELAY_US);
    } /* else not needed */

    return ret;
}

/** *****************************************************************************************************
 * \brief This function is used to get rtc tick.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_Ip_RtcReadTick
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
 * Parameters (in)    : base  The base address of RTC to be set.
 *                      tick  The tick value to be set into RTC.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The current tick value.
 *
 * Description        :
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005
 *******************************************************************************************************/
static uint64 Mcu_Ip_RtcReadTick(uint32 base)
{
    /* rtc_l/h is writable if 'en' not set */
    uint32 l;
    uint32 h;

    readl(base + RTC_L);
    readl(base + RTC_H);

    l = readl(base + RTC_REG_L_HOLD_SHADOW);
    h = readl(base + RTC_REG_H_HOLD_SHADOW);

    return (uint64)l | ((uint64)h << 32U);
}

/** *****************************************************************************************************
 * \brief This function is used to set rtc tick.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_Ip_RtcSetTick
 *                      (
 *                          uint32 base,
 *                          uint64 tick
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : base  The base address of RTC to be set.
 *                      tick  The tick value to be set into RTC.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK - The Executed successfully.
 *                      E_NOT_OK - The Parameter invalid.
 *
 * Description        : Usually, this routine used to set 'start point' of RTC. When setting tick,
 *                      rtc shall be in disabled mode.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005
 *******************************************************************************************************/
static Std_ReturnType Mcu_Ip_RtcSetTick(uint32 base, uint64 tick)
{
    Std_ReturnType ret;

    if (tick >= RTC_TICK_MAX)
    {
        ret = E_NOT_OK;
    }
    else
    {
        /* shall write RTC_L then RTC_H */
        writel((uint32)tick, base + RTC_L);
        writel((uint32)(tick >> 32U), base + RTC_H);

        /* wait register set sync*/
        ret = Mcu_Ip_RtcRegisterCrossClockEn(base);
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function is used to Setup alarm timeout of the RTC.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_Ip_RtcSetupAlarm
 *                      (
 *                          uint32 base,
 *                          uint64 interval,
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
 *                      interval - The alarm time tick value.
 *                      notify - The Callback notification function.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK - The Executed successfully.
 *                      MCU_E_PARAM_CONFIG - The Parameter invalid.
 *
 * Description        : Set the tick value of the alarm based on the current tick value and register
 *                      the interrupt handling callback interface.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_055 SWSR_MCU_054 SWSR_MCU_005
 *******************************************************************************************************/
static Std_ReturnType Mcu_Ip_RtcSetupAlarm(uint32 base, uint64 interval, Mcu_AlarmNotifyType notify)
{
    Std_ReturnType ret;
    uint64 now = Mcu_Ip_RtcReadTick(base);
    uint64 tmt = now + interval;
    uint32 v;

    if ((now >= RTC_TICK_MAX) || (interval >= RTC_TICK_MAX)
            || ((RTC_TICK_MAX - now) < interval))
    {
        ret = MCU_E_PARAM_CONFIG;
    }
    else
    {

        if (APB_RTC2_BASE == base)
        {
            Mcu_Rtc2AlarmNotify[0] = notify;
        }
        else
        {
            Mcu_Rtc1AlarmNotify[0] = notify;
        }

        v = readl(base + RTC_WAKEUP_CTRL);
        /* shall disable wakeup then update timer */
        v &= ~(BM_WAKEUP_CTRL_ENABLE | BM_WAKEUP_CTRL_REQ_ENABLE);
        writel(v, base + RTC_WAKEUP_CTRL);
        ret = Mcu_Ip_RtcRegisterCrossClockEn(base);

        if (E_OK == ret)
        {
            /* shall write TIMER_L then TIMER_H */
            writel((uint32)tmt, base + TIMER_L);
            writel((uint32)(tmt >> 32U), base + TIMER_H);
            ret = Mcu_Ip_RtcRegisterCrossClockEn(base);

            if (E_OK == ret)
            {
                v &= ~ BM_WAKEUP_CTRL_CLEAR;    /* make sure 'clear' not set */
                v |= BM_WAKEUP_CTRL_ENABLE | BM_WAKEUP_CTRL_IRQ_ENABLE | BM_WAKEUP_CTRL_REQ_ENABLE;
                writel(v, base + RTC_WAKEUP_CTRL);
                ret = Mcu_Ip_RtcRegisterCrossClockEn(base);
            } /* else not needed */
        } /* else not needed */
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function is used to get TIMER register value.
 *
 * \verbatim
 * Syntax             : uint64 Mcu_Ip_RtcGetTmt
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
 * Description        : The value of TIMER register is set for both sleep and alarm Settings.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005
 *******************************************************************************************************/
static uint64 Mcu_Ip_RtcGetTmt(uint32 base)
{
    uint32 valueLow = readl(base + TIMER_L);
    uint32 valueHigh = readl(base + TIMER_H);

    return (((uint64)valueHigh << 32) | (uint64)valueLow);
}

/** *****************************************************************************************************
 * \brief This function is used to clear IRQ status with interrupt call back.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_Ip_RtcResumeCb
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
 * Description        : Callback of rtc after a wakeup.After a resume, rtc enabled, wakeup enabled
 *                      and wakeup_irq still asserted. SW shall call this routine to clear
 *                      wakeup_irq/wakeup_en. Then wakeup can still be setup by calling rtc_setup_wakeup.
 *                      Note: Call this routine after every resuming.
 *
 * \endverbatim
 * Traceability       : SW_SM003 SW_SM004 SWSR_MCU_005
 *******************************************************************************************************/
static Std_ReturnType Mcu_Ip_RtcResumeCb(uint32 base)
{
    Std_ReturnType ret;
    uint32 value;
    uint32 interruptEnable;
    uint32 interruptStatus;
    uint32 testBit;

    ret = Mcu_EnterCheck(MCU_SID_SET_MODE);

    // delay 35us wait for Status Sync update
    RTC_SS_ACCESS_DELAY_CYCLE(1);

    value = readl(base + RTC_WAKEUP_CTRL);
    interruptEnable = value & (BM_WAKEUP_CTRL_ENABLE | BM_WAKEUP_CTRL_REQ_ENABLE |
                               BM_WAKEUP_CTRL_IRQ_ENABLE);
    interruptStatus = value & (BM_WAKEUP_CTRL_STATUS);
    testBit = (BM_WAKEUP_CTRL_ENABLE | BM_WAKEUP_CTRL_REQ_ENABLE | BM_WAKEUP_CTRL_IRQ_ENABLE |
               BM_WAKEUP_CTRL_STATUS);

    if ((E_OK != ret) || (testBit != (interruptEnable | interruptStatus)))
    {
        ret = MCU_E_INT_UNEXPECT;
    }

    ret = ret | Mcu_Ip_RtcClearWakeupFlag(base);

    return ret;
}

/** *****************************************************************************************************
 * \brief This function is used to Check whether it is a leap year.
 *
 * \verbatim
 * Syntax             : boolean Mcu_Ip_RtcIsLeapYear
 *                      (
 *                          uint16 year
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : year - The year number.
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
static boolean Mcu_Ip_RtcIsLeapYear(uint16 year)
{
    boolean res = FALSE;

    if (0U == (year % 4U))
    {
        if (0U == (year % 100U))
        {
            if (0U == (year % 400U))
            {
                res = TRUE;
            } /* else not needed */
        }
        else
        {
            res = TRUE;
        }
    } /* else not needed */

    return res;
}

/** *****************************************************************************************************
 * \brief This function is used to RTC time Simple algorithm to Epoch seconds.
 *
 * \verbatim
 * Syntax             : uint64 Mcu_Ip_RtcTimeToSec
 *                      (
 *                          const Mcu_RtcTimeType *const tmPtr
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : tmPtr - The time pointer.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Convert from standard time value value to tick.
 *
 * \endverbatim
 * Traceability       : SW_SM006 SWSR_MCU_005
 *******************************************************************************************************/
static uint64 Mcu_Ip_RtcTimeToSec(const Mcu_RtcTimeType *const tmPtr)
{
    uint64 epochSec = 0U;
    uint16 year = tmPtr->year;
    uint8 month = tmPtr->month - (uint8)1U;
    uint16 num;

    for (num = (uint16)EPOCH_START_YEAR; num < year; num++)
    {
        epochSec += (uint64)(SECONDS_PER_DAY *
                             ((TRUE == Mcu_Ip_RtcIsLeapYear(num)) ? LEAP_YEAR_DAYS : COMMON_YEAR_DAYS));
    }

    for (num = 0U; num < month; num++)
    {
        epochSec += (uint64)(MonDays[num] * SECONDS_PER_DAY);

        if ((TRUE == Mcu_Ip_RtcIsLeapYear(year)) && (1U == num))
        {
            epochSec += (uint64)SECONDS_PER_DAY;
        } /* else not needed */
    }

    epochSec += (uint64)((tmPtr->day - 1ULL) * SECONDS_PER_DAY);
    epochSec += (uint64)(tmPtr->hours * SECONDS_PER_HOUR);
    epochSec += (uint64)(tmPtr->minutes * SECONDS_PER_MINUTE);
    epochSec += (uint64)(tmPtr->seconds);

    return epochSec;
}

/** *****************************************************************************************************
 * \brief This function is used to Simple algorithm to Epoch seconds to RTC time.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_RtcSecToTime
 *                      (
 *                          uint64 epochSec,
 *                          Mcu_RtcTimeType *tmPtr
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : epochSec - The tick value.
 *                      tmPtr - The time pointer.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Convert from tick value to standard time value.
 *
 * \endverbatim
 * Traceability       : SW_SM006 SWSR_MCU_005
 *******************************************************************************************************/
static void Mcu_Ip_RtcSecToTime(uint64 epochSec, Mcu_RtcTimeType *tmPtr)
{
    uint16 year = (uint16)EPOCH_START_YEAR;
    uint8 month = 0U;
    uint32 days = (uint32)(epochSec / SECONDS_PER_DAY);
    uint32 seconds;
    boolean flag = FALSE;

    if (0U != days)
    {
        tmPtr->weekday = (uint8)((4U + days) % 7U);
    }
    else
    {
        tmPtr->weekday = 0U;
    }

    while (days >= COMMON_YEAR_DAYS)
    {
        if (TRUE == Mcu_Ip_RtcIsLeapYear(year))
        {
            if (days >= LEAP_YEAR_DAYS)
            {
                days -= (uint32)LEAP_YEAR_DAYS;
            }
            else
            {
                year++;
                break;
            }
        }
        else
        {
            days -= (uint32)COMMON_YEAR_DAYS;
        }

        year++;
    }

    tmPtr->year = year;

    while (days >= 28U)
    {
        if ((TRUE == Mcu_Ip_RtcIsLeapYear(year)) && (1U == month))
        {
            if (days >= 29U)
            {
                days -= 29U;
            }
            else
            {
                flag = TRUE;
            }
        }
        else
        {
            if (days >= MonDays[month])
            {
                days -= MonDays[month];
            }
            else
            {
                flag = TRUE;
            }
        }

        if (TRUE == flag)
        {
            break;
        } /* else not needed */

        month++;
    }

    tmPtr->month = month + 1U;
    tmPtr->day = (uint8)(days + 1U);

    seconds = (uint32)(epochSec % SECONDS_PER_DAY);
    tmPtr->hours = (uint8)(seconds / 3600U);
    tmPtr->minutes = (uint8)((seconds % 3600U) / 60U);
    tmPtr->seconds = (uint8)((seconds % 3600U) % 60U);
}

/** *****************************************************************************************************
 * \brief This function is used to Verify that the entered day is valid.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_Ip_RtcIsDay
 *                      (
 *                          const Mcu_RtcTimeType *const timePtr
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : timePtr - The RTC Timer time pointer.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK - The Executed successfully.
 *                      MCU_E_PARAM_CONFIG - The Parameter invalid.
 *
 * Description        :
 *
 * \endverbatim
 * Traceability       : SW_SM006 SWSR_MCU_005
 *******************************************************************************************************/
static Std_ReturnType Mcu_Ip_RtcIsDay(const Mcu_RtcTimeType *const timePtr )
{
    Std_ReturnType errStatus = E_OK;

    if ((timePtr->day <= 0U) || (timePtr->day > 31U))
    {
        errStatus = MCU_E_PARAM_CONFIG;
    }
    else
    {
        if (2U == timePtr->month)
        {
            if (TRUE == Mcu_Ip_RtcIsLeapYear(timePtr->year))
            {
                if (timePtr->day > 29U)
                {
                    errStatus = MCU_E_PARAM_CONFIG;
                } /* else not needed */
            }
            else
            {
                if (timePtr->day > 28U)
                {
                    errStatus = MCU_E_PARAM_CONFIG;
                } /* else not needed */
            }
        }
        else
        {
            if ((4U == timePtr->month) || (6U == timePtr->month) || (9U == timePtr->month)
                    || (11U == timePtr->month))
            {
                if (timePtr->day > 30U)
                {
                    errStatus = MCU_E_PARAM_CONFIG;
                } /* else not needed */
            } /* else not needed */
        }
    }

    return errStatus;
}

/** *****************************************************************************************************
 * \brief This function is used to Verify that the entered date is valid.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_Ip_RtcIsDate
 *                      (
 *                          const Mcu_RtcTimeType *const timePtr
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : timePtr - The RTC Timer time pointer.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK - The Executed successfully.
 *                      MCU_E_PARAM_CONFIG - The Parameter invalid.
 *
 * Description        :
 *
 * \endverbatim
 * Traceability       : SW_SM006 SWSR_MCU_005
 *******************************************************************************************************/
static Std_ReturnType Mcu_Ip_RtcIsDate(const Mcu_RtcTimeType *const timePtr )
{
    Std_ReturnType errStatus;

    if ((0U == timePtr->year) || (timePtr->year < 1970U))
    {
        errStatus = MCU_E_PARAM_CONFIG;
    }
    else
    {
        if ((timePtr->month <= 0U) || (timePtr->month > 12U))
        {
            errStatus = MCU_E_PARAM_CONFIG;
        }
        else
        {
            errStatus = Mcu_Ip_RtcIsDay(timePtr);
        }
    }

    if (E_OK == errStatus)
    {
        if (timePtr->weekday > 6U)
        {
            errStatus = MCU_E_PARAM_CONFIG;
        }
        else
        {
            if ((timePtr->hours >= 24U) || (timePtr->minutes >= 60U) || (timePtr->seconds >= 60U))
            {
                errStatus = MCU_E_PARAM_CONFIG;
            } /* else not needed */
        }
    } /* else not needed */

    return errStatus;
}

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
/*PRQA S 1505 1*/
Std_ReturnType Mcu_Ip_RtcEnable(uint32 base)
{
    Std_ReturnType ret = E_OK;
    uint32 v;

    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    v = readl(base + SEC_RTC_CTRL);

    if ((v & BM_SEC_RTC_CTRL_LOCK) > 0U)
    {
        ret = MCU_E_REGLOCKED;
    } /* else not needed */

    if (E_OK == ret)
    {
        v |= (BM_SEC_RTC_CTRL_RTC_ENABLE);
        writel(v, base + SEC_RTC_CTRL);

        /* RTC domain register Access hook exit function */
        RTC_DOMAIN_SS_HOOK_EXIT();

        /* wait for 9 32KHz cycle clock, ensure the value arrive the register */
        ret = Mcu_udelay((uint32)DELAY_US);
    }
    else
    {
        /* RTC domain register Access hook exit function */
        RTC_DOMAIN_SS_HOOK_EXIT();
    }

    return ret;
}

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
/*PRQA S 1505 1*/
Std_ReturnType Mcu_Ip_RtcDisable(uint32 base)
{
    Std_ReturnType ret = E_OK;

    uint32 v;

    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    v = readl(base + SEC_RTC_CTRL);

    if ((v & BM_SEC_RTC_CTRL_LOCK) > 0U)
    {
        ret = MCU_E_REGLOCKED;
    } /* else not needed */

    if (E_OK == ret)
    {
        v &= ~BM_SEC_RTC_CTRL_RTC_ENABLE;
        writel(v, base + SEC_RTC_CTRL);

        /* RTC domain register Access hook exit function */
        RTC_DOMAIN_SS_HOOK_EXIT();

        /* wait for 9 32KHz cycle clock, ensure the value arrive the register */
        ret = Mcu_udelay((uint32)DELAY_US);
    }
    else
    {
        /* RTC domain register Access hook exit function */
        RTC_DOMAIN_SS_HOOK_EXIT();
    }

    return ret;
}

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
boolean Mcu_Ip_RtcIsWakenup(uint32 base)
{
    boolean ret;

    uint32 v;

    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    // delay 35us wait for Status Sync update
    RTC_SS_ACCESS_DELAY_CYCLE(1);

    v = readl(base + RTC_WAKEUP_CTRL) & BM_WAKEUP_CTRL_STATUS;

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();

    if (0x0U != v)
    {
        ret = TRUE;
    }
    else
    {
        ret = FALSE;
    }

    return ret;
}

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
/*PRQA S 1505 1*/
Std_ReturnType Mcu_Ip_RtcSetupWakeup(uint32 base, uint64 interval)
{
    Std_ReturnType ret;
    uint64 now;
    uint64 tmt;
    uint32 v;

    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    // delay 35us wait for Tick Sync update
    RTC_SS_ACCESS_DELAY_CYCLE(1);

    now = Mcu_Ip_RtcReadTick(base);
    tmt = now + interval;

    if ((now >= RTC_TICK_MAX) || (interval >= RTC_TICK_MAX)
            || ((RTC_TICK_MAX - now) < interval))
    {
        ret = MCU_E_PARAM_CONFIG;
    }
    else
    {
        v = readl(base + RTC_WAKEUP_CTRL);
        /* shall disable wakeup then update timer */
        v &= ~(BM_WAKEUP_CTRL_ENABLE | BM_WAKEUP_CTRL_IRQ_ENABLE | BM_WAKEUP_CTRL_REQ_ENABLE);
        writel(v, base + RTC_WAKEUP_CTRL);
        ret = Mcu_Ip_RtcRegisterCrossClockEn(base);

        if (E_OK == ret)
        {
            /* shall write TIMER_L then TIMER_H */
            writel((uint32)tmt, base + TIMER_L);
            writel((uint32)(tmt >> 32), base + TIMER_H);
            ret = Mcu_Ip_RtcRegisterCrossClockEn(base);

            if (E_OK == ret)
            {
                v &= ~ BM_WAKEUP_CTRL_CLEAR;    /* make sure 'clear' not set */
                v |= (BM_WAKEUP_CTRL_ENABLE | BM_WAKEUP_CTRL_IRQ_ENABLE | BM_WAKEUP_CTRL_REQ_ENABLE);
                writel(v, base + RTC_WAKEUP_CTRL);
                ret = Mcu_Ip_RtcRegisterCrossClockEn(base);

                v = readl(base + SEC_RTC_CTRL);
                if (BM_SEC_RTC_CTRL_RTC_ENABLE != (v & BM_SEC_RTC_CTRL_RTC_ENABLE))
                {
                    ret |= Mcu_Ip_RtcEnable(base);
                }

            } /* else not needed */
        } /* else not needed */
    }

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();

    return ret;
}

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
ISR(Mcu_Ip_RtcIrqHandler1)
{
    Std_ReturnType ret;

    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    ret = Mcu_Ip_RtcResumeCb(APB_RTC1_BASE);

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();

    if ((Mcu_Rtc1AlarmNotify[0] != NULL_PTR) && (E_OK == ret))
    {
        /*PRQA S 0326 1*/
        (void)Mcu_Rtc1AlarmNotify[0]((void *)APB_RTC1_BASE);
    } /* else not needed */
}

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
ISR(Mcu_Ip_RtcIrqHandler2)
{
    Std_ReturnType ret;

    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    ret = Mcu_Ip_RtcResumeCb(APB_RTC2_BASE);

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();

    if ((Mcu_Rtc2AlarmNotify[0] != NULL_PTR) && (E_OK == ret))
    {
        /*PRQA S 0326 1*/
        (void)Mcu_Rtc2AlarmNotify[0]((void *)APB_RTC2_BASE);
    } /* else not needed */
}

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
Std_ReturnType Mcu_Ip_RtcSetTime(uint32 base, const Mcu_RtcTimeType *const rtcTimePtr)
{

    Std_ReturnType ret = MCU_E_PARAM_POINTER;
    uint64 secs;
    /*workaround for rewritting RTC_L/H,extra waitting is 480us*/

    if (NULL_PTR != rtcTimePtr)
    {
        ret = Mcu_Ip_RtcIsDate(rtcTimePtr);

        if (E_OK == ret)
        {
            secs = Mcu_Ip_RtcTimeToSec(rtcTimePtr);

            ret = Mcu_Ip_RtcDisable(base);

            /* RTC domain register Access hook enter function */
            RTC_DOMAIN_SS_HOOK_ENTER();

            ret = ret | Mcu_Ip_RtcSetTick(base, RTC_SECOND_TO_TICK(secs));

            /* RTC domain register Access hook exit function */
            RTC_DOMAIN_SS_HOOK_EXIT();

            ret = ret | Mcu_Ip_RtcEnable(base);
        } /* else not needed */
    } /* else not needed */

    return ret;
}

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
/*PRQA S 1505 1*/
Std_ReturnType Mcu_Ip_RtcGetTime(uint32 base, Mcu_RtcTimeType *rtcTimePtr)
{
    Std_ReturnType ret = MCU_E_PARAM_POINTER;
    uint64 tick;
    uint64 sec;

    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    // delay 35us wait for Tick Sync update
    RTC_SS_ACCESS_DELAY_CYCLE(1);
    tick = Mcu_Ip_RtcReadTick(base);
    sec = RTC_TICK_TO_SECOND(tick);

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();

    if (NULL_PTR != rtcTimePtr)
    {
        Mcu_Ip_RtcSecToTime(sec, rtcTimePtr);
        ret = E_OK;
    } /* else not needed */

    return ret;
}

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
                                      Mcu_AlarmNotifyType notify)
{
    Std_ReturnType ret;
    Mcu_RtcTimeType tm1, tm2;

    if (NULL_PTR == rtcAlarmTimePtr)
    {
        ret = MCU_E_PARAM_POINTER;
    }
    else
    {

        ret = Mcu_Ip_RtcGetTime(base, &tm1);

        /*PRQA S 2991,2995 1*/
        if (E_OK == ret)
        {
            tm2.year = tm1.year;
            tm2.month = tm1.month;
            tm2.day = rtcAlarmTimePtr->day;
            tm2.seconds = rtcAlarmTimePtr->seconds;
            tm2.minutes = rtcAlarmTimePtr->minutes;
            tm2.hours = rtcAlarmTimePtr->hours;
            tm2.weekday = rtcAlarmTimePtr->weekday;

            uint64 now = Mcu_Ip_RtcTimeToSec(&tm1);
            uint64 later = Mcu_Ip_RtcTimeToSec(&tm2);

            if (later < now)
            {
                ret = MCU_E_PARAM_CONFIG;
            }
            else
            {
                /* RTC domain register Access hook enter function */
                RTC_DOMAIN_SS_HOOK_ENTER();

                ret = Mcu_Ip_RtcSetupAlarm(base, RTC_SECOND_TO_TICK(later - now), notify);

                /* RTC domain register Access hook exit function */
                RTC_DOMAIN_SS_HOOK_EXIT();
            }
        } /* else not needed */
    }

    return ret;
}

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
Std_ReturnType Mcu_Ip_RtcGetAlarmTime(uint32 base, Mcu_RtcAlarmTimeType *rtcAlarmTimePtr)
{
    Std_ReturnType ret = MCU_E_PARAM_POINTER;
    uint64 tmt;
    Mcu_RtcTimeType rtcTimePtr;
    uint32 rdata;

    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    tmt = Mcu_Ip_RtcGetTmt(base);

    rdata = readl(base + RTC_WAKEUP_CTRL);

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();

    tmt = RTC_TICK_TO_SECOND(tmt);
    Mcu_Ip_RtcSecToTime(tmt, &rtcTimePtr);

    if (NULL_PTR != rtcAlarmTimePtr)
    {
        if (0U != ( rdata & BM_WAKEUP_CTRL_IRQ_ENABLE))
        {
            rtcAlarmTimePtr->seconds = rtcTimePtr.seconds;
            rtcAlarmTimePtr->minutes = rtcTimePtr.minutes;
            rtcAlarmTimePtr->hours = rtcTimePtr.hours;
            rtcAlarmTimePtr->weekday = rtcTimePtr.weekday;
            rtcAlarmTimePtr->day = rtcTimePtr.day;
            ret = E_OK;
        }
        else
        {
            ret = MCU_E_PARAM_CONFIG;
        }
    } /* else not needed */

    return ret;
}

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
                                      Mcu_RtcTimerModeType timerMode)
{
    uint64 tmt = (uint64)timerTime;
    Std_ReturnType ret;

    if (base == APB_RTC2_BASE)
    {
        Mcu_RtcTimerMode[1U] = timerMode;
    }
    else
    {
        Mcu_RtcTimerMode[0U] = timerMode;
    }

    if (RTC_TIMER_MODE_MIN == timerMode)
    {
        tmt *= 60U;
    }

    tmt = RTC_SECOND_TO_TICK(tmt);

    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    /*clear rtc wakeup interrupt flag */
    ret = Mcu_Ip_RtcClearWakeupFlag(base);

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();

    if (E_OK == ret)
    {
        ret = Mcu_Ip_RtcSetupWakeup(base, tmt);
    }

    return ret;
}

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
                                      Mcu_RtcTimerModeType *timerModePtr)
{
    uint64 sec;
    Std_ReturnType ret = E_OK;

    uint64 tmt;
    uint64 tick;

    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    // delay 35us wait for Tick Sync update
    RTC_SS_ACCESS_DELAY_CYCLE(1);
    tmt = Mcu_Ip_RtcGetTmt(base);
    tick = Mcu_Ip_RtcReadTick(base);

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();

    Mcu_RtcTimerModeType timermode = RTC_TIMER_MODE_SEC;

    if ((NULL_PTR != timerTimePtr) && (NULL_PTR != timerModePtr))
    {
        if (tick >= tmt)
        {
            *timerTimePtr = (Mcu_RtcSleepTimeType)0U;
        }
        else
        {
            sec = RTC_TICK_TO_SECOND(tmt - tick);

            if (APB_RTC2_BASE == base)
            {
                timermode = Mcu_RtcTimerMode[1U];
            }
            else
            {
                timermode = Mcu_RtcTimerMode[0U];
            }

            if (RTC_TIMER_MODE_MIN == timermode)
            {
                sec /= 60U;
            }

            *timerTimePtr = (Mcu_RtcSleepTimeType)sec;
        }

        *timerModePtr = timermode;
    }
    else
    {
        ret = MCU_E_PARAM_POINTER;
    }


    return ret;
}

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
Std_ReturnType Mcu_Ip_RtcClearTimerCounter(uint32 base)
{
    Std_ReturnType ret;

    ret = Mcu_Ip_RtcDisable(base);

    if (E_OK == ret)
    {
        /* RTC domain register Access hook enter function */
        RTC_DOMAIN_SS_HOOK_ENTER();

        ret = Mcu_Ip_RtcSetTick(base, 0ULL);

        /* RTC domain register Access hook exit function */
        RTC_DOMAIN_SS_HOOK_EXIT();
    } /* else not needed */

    return ret;
}

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
uint8 Mcu_Ip_RtcGetWakeupFlag(uint32 base)
{
    uint32 v;

    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    // delay 35us wait for Sync Status update
    RTC_SS_ACCESS_DELAY_CYCLE(1);

    v = readl(base + RTC_WAKEUP_CTRL);

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();

    return (uint8)(v & BM_WAKEUP_CTRL_STATUS);
}

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
Std_ReturnType Mcu_Ip_RtcClearWakeupFlag(uint32 base)
{
    Std_ReturnType ret;
    uint32 value;

    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    /* clear IRQ, REQ, EN enable */
    value = readl(base + RTC_WAKEUP_CTRL);
    value &= ~(BM_WAKEUP_CTRL_ENABLE | BM_WAKEUP_CTRL_REQ_ENABLE | BM_WAKEUP_CTRL_IRQ_ENABLE);
    writel(value, base + RTC_WAKEUP_CTRL);
    ret = Mcu_Ip_RtcRegisterCrossClockEn(base);

    /* write 1,to clear IRQ status */
    value = readl(base + RTC_WAKEUP_CTRL);
    value |= BM_WAKEUP_CTRL_CLEAR;
    writel(value, base + RTC_WAKEUP_CTRL);
    ret = ret | Mcu_Ip_RtcRegisterCrossClockEn(base);

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();

    return ret;
}

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
void Mcu_Ip_RtcDisableRegParityErrIntEnable(uint32 base)
{
    uint32 v = readl(base + RTC_REG_PARITY_ERR_INT_STAT_EN);

    v &= ~(BM_REG_PARITY_ERR_INT_STAT_REG_PARITY_ERR);
    writel(v, base + RTC_REG_PARITY_ERR_INT_STAT_EN);
}

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
void Mcu_Ip_RtcEnableRegParityErrIntEnable(uint32 base)
{
    uint32 v = readl(base + RTC_REG_PARITY_ERR_INT_STAT_EN);

    v |= (BM_REG_PARITY_ERR_INT_STAT_REG_PARITY_ERR);
    writel(v, base + RTC_REG_PARITY_ERR_INT_STAT_EN);
}

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
 * Traceability       : SWSR_MCU_005 SW_SM007
 *******************************************************************************************************/
void Mcu_Ip_RtcDomainPclkEnable(void)
{
    SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_00();

    if (E_OK != Mcu_EnterCheck(MCU_SID_RTC_DOMAIN_PCLK))
    {
        // do nothing
    }
    else
    {
        if (0 == McuRtcSSPclkRef)
        {
            Mcu_Ip_ClkEnable(CLK_NODE(g_ckgen_gating_rtc_pclk));
            Mcu_Ip_RtcEnableRegParityErrIntEnable(APB_RTC1_BASE);
            Mcu_Ip_RtcEnableRegParityErrIntEnable(APB_RTC2_BASE);
            McuRtcSSPclkRef = 1U;
        }
        else if (0 < McuRtcSSPclkRef)
        {
            McuRtcSSPclkRef++;
        }
        else
        {
            // do nothing
        }
    }

    SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_00();
}

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
 * Traceability       : SWSR_MCU_005 SW_SM007
 *******************************************************************************************************/
void Mcu_Ip_RtcDomainPclkDisable(void)
{
    SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_00();

    if (E_OK != Mcu_EnterCheck(MCU_SID_RTC_DOMAIN_PCLK))
    {
        // do nothing
    }
    else
    {
        if (1 < McuRtcSSPclkRef)
        {
            McuRtcSSPclkRef--;
        }
        else if (1 == McuRtcSSPclkRef)
        {
            Mcu_Ip_RtcDisableRegParityErrIntEnable(APB_RTC1_BASE);
            Mcu_Ip_RtcDisableRegParityErrIntEnable(APB_RTC2_BASE);
            Mcu_Ip_ClkDisable(CLK_NODE(g_ckgen_gating_rtc_pclk));
            McuRtcSSPclkRef = 0;
        }
        else
        {
            // do nothing
        }
    }

    SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_00();
}
#endif /* MCU_RTC_DOMAIN_SS_DYNAMIC_PCLK == STD_ON */

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif
/* End of file */
