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

#ifdef __cplusplus
extern "C" {
#endif

#include "RegHelper.h"
#include "Mcu_Rtc.h"
#include "Rtc_Reg.h"
#include "Mcu_Soc.h"
#include "Mcu_Delay.h"
#include "debug.h"
#include "Xtal_Reg.h"

/* Version and Check Begin */
/* Version Info Begin */
#define MCU_RTC_C_VENDOR_ID    0x8C
#define MCU_RTC_C_AR_RELEASE_MAJOR_VERSION    4
#define MCU_RTC_C_AR_RELEASE_MINOR_VERSION    3
#define MCU_RTC_C_AR_RELEASE_REVISION_VERSION 1
#define MCU_RTC_C_SW_MAJOR_VERSION    1
#define MCU_RTC_C_SW_MINOR_VERSION    0
#define MCU_RTC_C_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((MCU_RTC_C_AR_RELEASE_MAJOR_VERSION != MCU_RTC_H_AR_RELEASE_MAJOR_VERSION)\
    || (MCU_RTC_C_AR_RELEASE_MINOR_VERSION != MCU_RTC_H_AR_RELEASE_MINOR_VERSION)\
    || (MCU_RTC_C_AR_RELEASE_REVISION_VERSION != MCU_RTC_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Mcu_Rtc.c and Mcu_Rtc.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((MCU_RTC_C_SW_MAJOR_VERSION != MCU_RTC_H_SW_MAJOR_VERSION)\
    || (MCU_RTC_C_SW_MINOR_VERSION != MCU_RTC_H_SW_MINOR_VERSION)\
    || (MCU_RTC_C_SW_PATCH_VERSION != MCU_RTC_H_SW_PATCH_VERSION))
#error "Opps, Mcu_Rtc.c and Mcu_Rtc.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((MCU_RTC_C_AR_RELEASE_MAJOR_VERSION != RTC_REG_H_AR_RELEASE_MAJOR_VERSION)\
    || (MCU_RTC_C_AR_RELEASE_MINOR_VERSION != RTC_REG_H_AR_RELEASE_MINOR_VERSION)\
    || (MCU_RTC_C_AR_RELEASE_REVISION_VERSION != RTC_REG_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Mcu_Rtc.c and Rtc_Reg.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((MCU_RTC_C_SW_MAJOR_VERSION != RTC_REG_H_SW_MAJOR_VERSION)\
    || (MCU_RTC_C_SW_MINOR_VERSION != RTC_REG_H_SW_MINOR_VERSION)\
    || (MCU_RTC_C_SW_PATCH_VERSION != RTC_REG_H_SW_PATCH_VERSION))
#error "Opps, Mcu_Rtc.c and Rtc_Reg.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

static int ctz32(uint32 x)
{
    for (int i = 0; i != 32; ++i)
        if (x >> i & 1) return i;

    return 0;
}

#define RC_CLK_SEC_OFF  4u
#define BM_RC_CLK_SEL   (0x01u << 0)

#define RTC_CLK_HZ (32 * 1024ul)
#define RTC_CLK_SHIFT ctz32(RTC_CLK_HZ)
#define RTC_SECOND_TO_TICK(s) ((s) << RTC_CLK_SHIFT)
#define RTC_TICK_TO_SECOND(t) ((t) >> RTC_CLK_SHIFT)

#define SECONDS_PER_MINUTE (60ul)
#define MINUTES_PER_HOUR (60ul)
#define HOURS_PER_DAY (24ul)
#define SECONDS_PER_HOUR (SECONDS_PER_MINUTE * MINUTES_PER_HOUR)
#define SECONDS_PER_DAY (SECONDS_PER_HOUR * HOURS_PER_DAY)

#define LEAP_YEAR_DAYS (366ul)
#define COMMON_YEAR_DAYS (365ul)
#define TM_START_YEAR (1900ul)
#define EPOCH_START_YEAR (1970ul)

#define DELAY_US  360
#define CROSS_DELAY_US  50

#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

static const uint8 mon_days[12] = {
    31u, 28u, 31u, 30u, 31u, 30u, 31u, 31u, 30u, 31u, 30u, 31u
};
#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

static Rtc_TimerModeType rtc_timermode[2] = {RTC_TIMER_MODE_SEC, RTC_TIMER_MODE_SEC};

#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

#define MCU_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

static AlarmNotifyType rtc1_alarm_notify[1];
static AlarmNotifyType rtc2_alarm_notify[1];

#define MCU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

void Mcu_RtcRegisterCrossLockEn(uint32 base)
{
    uint32 timeout = 0;
    uint32 v = readl(base + RTC_REGISTER_CROSS_CLOCK);

    v |= BM_REGISTERR_CROSS_CLOCK_EN;

    writel(v, base + RTC_REGISTER_CROSS_CLOCK);

    /* wait register set sync, 32K clock 2 cycle */
    while ((0 != readl(base + RTC_REGISTER_CROSS_CLOCK)) && (timeout++ < 1000UL))
        Mcu_udelay(100);

    /* wait for 50us, The clock bus has the problem of crossing the clock critical area */
    Mcu_udelay(CROSS_DELAY_US);
}

void Mcu_RtcEnable(uint32 base)
{
    uint32 v = readl(base + SEC_RTC_CTRL);

    if ((v & BM_SEC_RTC_CTRL_LOCK) > 0) {
        return ;
    }

    v |= (BM_SEC_RTC_CTRL_RTC_ENABLE );
    writel(v, base + SEC_RTC_CTRL);

    /* wait for 9 32KHz cycle clock, ensure the value arrive the register */
    Mcu_udelay(DELAY_US);
}

void Mcu_RtcDisable(uint32 base)
{
    uint32 v = readl(base + SEC_RTC_CTRL);

    if ((v & BM_SEC_RTC_CTRL_LOCK) > 0) {
        return ;
    }

    v &= ~BM_SEC_RTC_CTRL_RTC_ENABLE;
    writel(v, base + SEC_RTC_CTRL);

    /* wait for 9 32KHz cycle clock, ensure the value arrive the register */
    Mcu_udelay(DELAY_US);
}

uint64 Mcu_RtcReadTick(uint32 base)
{
    /* rtc_l/h is writable if 'en' not set */
    uint32 l = readl(base + RTC_L);
    uint32 h = readl(base + RTC_H);

    l = readl(base + RTC_REG_L_HOLD_SHADOW);
    h = readl(base + RTC_REG_H_HOLD_SHADOW);

    return (uint64)l | ((uint64)h << 32u);
}

Std_ReturnType Mcu_RtcSetTick(uint32 base, uint64 tick)
{
    if (tick >= RTC_TICK_MAX) {
        return (E_NOT_OK);
    }

    /* shall write RTC_L then RTC_H */
    writel((uint32)tick, base + RTC_L);
    writel((uint32)(tick >> 32), base + RTC_H);

    /* wait register set sync*/
    Mcu_RtcRegisterCrossLockEn(base);

    return E_OK;
}

Std_ReturnType Mcu_RtcAutoAdjust(uint32 base, rtc_adjust_t *adjust)
{
    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR == adjust) {
        ret = E_NOT_OK;
    } else {
        uint32 v = FV_AUTO_ADJUST_PERIOD(adjust->period)
                   | FV_AUTO_ADJUST_CYCLE(adjust->cycle);

        if ((adjust->direction) > 0u) {
            v |= BM_AUTO_ADJUST_ADJUST_DIRECTION;   /* descrease */
        } else {
            v &= ~BM_AUTO_ADJUST_ADJUST_DIRECTION;   /* increase */
        }

        writel(v | BM_AUTO_ADJUST_ENABLE, base + AUTO_ADJUST);
        Mcu_RtcRegisterCrossLockEn(base);
        ret = E_OK;
    }

    return ret;
}

Std_ReturnType Mcu_RtcSetupWakeup(uint32 base, uint64 interval)
{
    Std_ReturnType ret = E_NOT_OK;
    uint64 now = Mcu_RtcReadTick(base);
    uint64 tmt = now + interval;

    if ((now >= RTC_TICK_MAX) || (interval >= RTC_TICK_MAX)
        || ((RTC_TICK_MAX - now) < interval)) {
        ret = E_NOT_OK;
    } else {

        Mcu_RtcDisable(base);
        uint32 v = readl(base + WAKEUP_CTRL);
        /* shall disable wakeup then update timer */
        v &= ~(BM_WAKEUP_CTRL_ENABLE | BM_WAKEUP_CTRL_IRQ_ENABLE | BM_WAKEUP_CTRL_REQ_ENABLE);
        writel(v, base + WAKEUP_CTRL);
        Mcu_RtcRegisterCrossLockEn(base);

        /* shall write TIMER_L then TIMER_H */
        writel((uint32)tmt, base + TIMER_L);
        writel((uint32)(tmt >> 32), base + TIMER_H);
        Mcu_RtcRegisterCrossLockEn(base);

        v &= ~ BM_WAKEUP_CTRL_CLEAR;    /* make sure 'clear' not set */
        v |= (BM_WAKEUP_CTRL_ENABLE | BM_WAKEUP_CTRL_IRQ_ENABLE | BM_WAKEUP_CTRL_REQ_ENABLE);
        writel(v, base + WAKEUP_CTRL);
        Mcu_RtcRegisterCrossLockEn(base);
        Mcu_RtcEnable(base);
        ret = E_OK;
    }

    return ret;
}

void rtc1_IrqHandler(void)
{
    Mcu_RtcResumeCb(APB_RTC1_BASE);
    if (rtc1_alarm_notify[0] != NULL) {
        /* PRQA S 0326 2*/
        rtc1_alarm_notify[0]((void *)APB_RTC1_BASE);
    }
}

void rtc2_IrqHandler(void)
{
    Mcu_RtcResumeCb(APB_RTC2_BASE);
    if (rtc2_alarm_notify[0] != NULL) {
        /* PRQA S 0326 2*/
        rtc2_alarm_notify[0]((void *)APB_RTC2_BASE);
    }
}

Std_ReturnType Mcu_RtcSetupAlarm(uint32 base, uint64 interval, AlarmNotifyType notify)
{
    Std_ReturnType ret = E_NOT_OK;
    uint64 now = Mcu_RtcReadTick(base);
    uint64 tmt = now + interval;

    if ((now >= RTC_TICK_MAX) || (interval >= RTC_TICK_MAX)
        || ((RTC_TICK_MAX - now) < interval)
        || (NULL_PTR == notify)) {
        ret = E_NOT_OK;
    } else {

        if (base == APB_RTC2_BASE) {
            rtc2_alarm_notify[0] = notify;
        } else {
            rtc1_alarm_notify[0] = notify;
        }

        uint32 v = readl(base + WAKEUP_CTRL);
        /* shall disable wakeup then update timer */
        v &= ~(BM_WAKEUP_CTRL_ENABLE | BM_WAKEUP_CTRL_REQ_ENABLE);
        writel(v, base + WAKEUP_CTRL);
        Mcu_RtcRegisterCrossLockEn(base);

        /* shall write TIMER_L then TIMER_H */
        writel((uint32)tmt, base + TIMER_L);
        writel((uint32)(tmt >> 32), base + TIMER_H);
        Mcu_RtcRegisterCrossLockEn(base);

        v &= ~ BM_WAKEUP_CTRL_CLEAR;    /* make sure 'clear' not set */
        v |= BM_WAKEUP_CTRL_ENABLE | BM_WAKEUP_CTRL_IRQ_ENABLE | BM_WAKEUP_CTRL_REQ_ENABLE;
        writel(v, base + WAKEUP_CTRL);
        Mcu_RtcRegisterCrossLockEn(base);
        ret = E_OK;
    }

    return ret;
}

uint64 Mcu_RtcGetTmt(uint32 base)
{
    uint32 v_l = readl(base + TIMER_L);
    uint32 v_h = readl(base + TIMER_H);

    return (((uint64)v_h << 32) | (uint64)v_l);
}

void Mcu_RtcResumeCb(uint32 base)
{
    /* clear IRQ, REQ, EN enable */
    uint32 v = readl(base + WAKEUP_CTRL);
    v &= ~(BM_WAKEUP_CTRL_ENABLE | BM_WAKEUP_CTRL_REQ_ENABLE | BM_WAKEUP_CTRL_IRQ_ENABLE);
    writel(v, base + WAKEUP_CTRL);
    Mcu_RtcRegisterCrossLockEn(base);

    /* write 1,to clear IRQ status */
    v = readl(base + WAKEUP_CTRL);
    v |= BM_WAKEUP_CTRL_CLEAR;
    writel(v, base + WAKEUP_CTRL);
    Mcu_RtcRegisterCrossLockEn(base);
}

boolean Mcu_RtcIsWakenup(uint32 base)
{
    return (boolean)(0x0u != (readl(base + WAKEUP_CTRL) & BM_WAKEUP_CTRL_STATUS));
}

static boolean IsLeapYear(uint16 year)
{
    boolean res = FALSE;

    if (0u == (year % 4u)) {
        if (0 == (year % 100u)) {
            if (0 == (year % 400)) {
                res = TRUE;
            }
        } else {
            res = TRUE;
        }
    }

    return res;
}

static uint64 TimeToSec(const Rtc_TimeType *const tm)
{
    uint64 epoch_sec = 0;
    uint32 year = tm->Year;
    uint32 month = tm->Month - 1;

    for (uint32 num = EPOCH_START_YEAR; num < year; num++) {
        epoch_sec += SECONDS_PER_DAY *
                     (IsLeapYear(num) ? LEAP_YEAR_DAYS : COMMON_YEAR_DAYS);
    }

    for (uint32 num = 0; num < month; num++) {
        epoch_sec += mon_days[num] * SECONDS_PER_DAY;

        if (IsLeapYear(year) && (num == 1)) {
            epoch_sec += SECONDS_PER_DAY;
        }
    }

    epoch_sec += (tm->Day - 1) * SECONDS_PER_DAY;
    epoch_sec += tm->Hours * SECONDS_PER_HOUR;
    epoch_sec += tm->Minutes * SECONDS_PER_MINUTE;
    epoch_sec += tm->Seconds;

    return epoch_sec;
}


/**
 * @brief Simple algorithm to Epoch seconds to RTC time.
 *
 * @param tm
 * @param timec_ount
 */

void SecToTime(uint64 epoch_sec, Rtc_TimeType *tm)
{
    uint32 year = EPOCH_START_YEAR;
    uint32 month = 0;
    uint32 days = epoch_sec / SECONDS_PER_DAY;
    uint32 seconds;

    if (days) {
        tm->Weekday = (4 + days) % 7;
    } else
        tm->Weekday = 0;

    while (days >= COMMON_YEAR_DAYS) {
        if (IsLeapYear(year)) {
            if (days >= LEAP_YEAR_DAYS) {
                days -= LEAP_YEAR_DAYS;
            } else {
                year++;
                break;
            }
        } else {
            days -= COMMON_YEAR_DAYS;
        }

        year++;
    }

    tm->Year = year;

    while (days >= 28) {
        if (IsLeapYear(year) && (month == 1)) {
            if (days >= 29) {
                days -= 29;
            } else {
                break;
            }
        } else {
            if (days >= mon_days[month]) {
                days -= mon_days[month];
            } else {
                break;
            }
        }

        month++;
    }

    tm->Month = month + 1;
    tm->Day = days + 1;

    seconds = epoch_sec % SECONDS_PER_DAY;
    tm->Hours = seconds / 3600;
    tm->Minutes = (seconds % 3600) / 60;
    tm->Seconds = (seconds % 3600) % 60;
}

void Rtc_Init(const Rtc_ConfigType *configPtr)
{
    Mcu_RtcEnable(APB_RTC1_BASE);
}

Std_ReturnType Rtc_IsDate(const Rtc_TimeType *const time )
{
    if ((time->Year == 0u) || (time->Year < 1970u)) {
        return E_NOT_OK;
    }

    if ((time->Month <= 0u) || (time->Month > 12u)) {
        return E_NOT_OK;
    }

    if ((time->Day <= 0) || (time->Day > 31u)) {
        return E_NOT_OK;
    }

    if (time->Weekday > 6u) {
        return E_NOT_OK;
    }

    if ((time->Hours >= 24u) || (time->Minutes >= 60u) || (time->Seconds >= 60u)) {
        return E_NOT_OK;
    }

    if (time->Month == 2u) {
        if (IsLeapYear(time->Year) == TRUE) {
            if (time->Day > 29u) {
                return E_NOT_OK;
            }
        } else {
            if (time->Day > 28u) {
                return E_NOT_OK;
            }
        }
    }

    if ((time->Month == 4u) || (time->Month == 6u) || (time->Month == 9u) || (time->Month == 11u)) {
        if (time->Day > 30u) {
            return E_NOT_OK;
        }
    }

    return E_OK;

}

Std_ReturnType Rtc_SetTime(uint32 base, const Rtc_TimeType *const rtcTime )
{

    Std_ReturnType ret = E_NOT_OK;
    /*workaround for rewritting RTC_L/H,extra waitting is 480us*/

    ret = Rtc_IsDate(rtcTime);

    if (ret == E_OK) {
        uint64 secs = TimeToSec(rtcTime);

        Mcu_RtcDisable(base);
        ret = Mcu_RtcSetTick(base, RTC_SECOND_TO_TICK(secs));
        Mcu_RtcEnable(base);
    }

    if (0 == ret) {
        ret = E_OK;
    } else {
        ret = E_NOT_OK;
    }

    return ret;
}

Std_ReturnType Rtc_GetTime(uint32 base, Rtc_TimeType *rtcTime)
{
    uint64 tick = Mcu_RtcReadTick(base);
    uint64 sec = RTC_TICK_TO_SECOND(tick);

    SecToTime(sec, rtcTime);

    return E_OK;
}

Std_ReturnType Rtc_SetAlarmTime(uint32 base, const Rtc_AlarmTimeType *const rtcAlarmTime,
                                AlarmNotifyType notify)
{
    Std_ReturnType ret = E_NOT_OK;
    Rtc_TimeType tm1, tm2;

    if ((NULL_PTR == rtcAlarmTime) || (NULL_PTR == notify)) {
        ret = E_NOT_OK;
    } else {
        /* PRQA S 2992,2996 2 */
        if (E_OK != Rtc_GetTime(base, &tm1)) {
            ret = E_NOT_OK;
        } else {
            tm2.Year = tm1.Year;
            tm2.Month = tm1.Month;
            tm2.Day = rtcAlarmTime->Day;
            tm2.Seconds = rtcAlarmTime->Seconds;
            tm2.Minutes = rtcAlarmTime->Minutes;
            tm2.Hours = rtcAlarmTime->Hours;
            tm2.Weekday = rtcAlarmTime->Weekday;

            uint64 now = TimeToSec(&tm1);
            uint64 later = TimeToSec(&tm2);

            if (later < now) {
                ret = E_NOT_OK;
            } else {
                Mcu_RtcSetupAlarm(base, RTC_SECOND_TO_TICK(later - now), notify);
                ret = E_OK;
            }
        }
    }

    return ret;
}

Std_ReturnType Rtc_GetAlarmTime(uint32 base, Rtc_AlarmTimeType *rtcAlarmTime)
{
    Std_ReturnType ret = E_NOT_OK;
    uint64 tmt = Mcu_RtcGetTmt(base);
    Rtc_TimeType rtcTime;
    uint32 rdata = 0;

    tmt = RTC_TICK_TO_SECOND(tmt);
    SecToTime(tmt, &rtcTime);

    rdata = readl(base + WAKEUP_CTRL);

    if (( rdata & BM_WAKEUP_CTRL_IRQ_ENABLE)) {
        rtcAlarmTime->Seconds = rtcTime.Seconds;
        rtcAlarmTime->Minutes = rtcTime.Minutes;
        rtcAlarmTime->Hours = rtcTime.Hours;
        rtcAlarmTime->Weekday = rtcTime.Weekday;
        rtcAlarmTime->Day = rtcTime.Day;
        ret = E_OK;
    } else {
        ret = E_NOT_OK;
    }

    return ret;
}

Std_ReturnType Rtc_ClearAlarmTime(uint32 base)
{
    uint32 v = readl(base + WAKEUP_CTRL);

    v &= ~BM_WAKEUP_CTRL_IRQ_ENABLE;
    writel(v, base + WAKEUP_CTRL);
    Mcu_RtcRegisterCrossLockEn(base);
    return E_OK;
}

Std_ReturnType Rtc_SetSleepTime(uint32 base, Rtc_SleepTimeType timerTime,
                                Rtc_TimerModeType timerMode)
{
    uint64 tmt = (uint64)timerTime;

    if (base == APB_RTC2_BASE) {
        rtc_timermode[1] = timerMode;
    } else {
        rtc_timermode[0] = timerMode;
    }

    if (RTC_TIMER_MODE_MIN == timerMode) {
        tmt *= 60u;
    }

    tmt = RTC_SECOND_TO_TICK(tmt);

    /*clear rtc wakeup interrupt flag */
    Mcu_RtcResumeCb(base);
    Mcu_RtcSetupWakeup(base, tmt);

    return E_OK;
}

Std_ReturnType Rtc_GetSleepTime(uint32 base, Rtc_SleepTimeType *timerTimePtr,
                                Rtc_TimerModeType *timerModePtr)
{
    uint64 tmt = Mcu_RtcGetTmt(base);
    uint64 tick = Mcu_RtcReadTick(base);
    Rtc_TimerModeType timermode = RTC_TIMER_MODE_SEC;

    if (tick >= tmt) {
        *timerTimePtr = (Rtc_SleepTimeType)0;
    } else {
        uint64 sec = RTC_TICK_TO_SECOND(tmt - tick);

        if (base == APB_RTC2_BASE) {
            timermode = rtc_timermode[1];
        } else {
            timermode = rtc_timermode[0];
        }

        if (RTC_TIMER_MODE_MIN == timermode) {
            sec /= 60u;
        }

        *timerTimePtr = (Rtc_SleepTimeType)sec;
    }

    *timerModePtr = timermode;

    return E_OK;
}

Std_ReturnType Rtc_ClearTimerCounter(uint32 base)
{
    Mcu_RtcDisable(base);
    Mcu_RtcSetTick(base, 0ULL);

    return E_OK;
}

Std_ReturnType Rtc_GetWakeupFlag(uint32 base)
{
    uint32 v = readl(base + WAKEUP_CTRL);

    return v & BM_WAKEUP_CTRL_STATUS;
}

Std_ReturnType Rtc_ClearWakeupFlag(uint32 base)
{
    Mcu_RtcResumeCb(base);

    return E_OK;
}

boolean Mcu_RtcTrySwitchToXtal(uint32 base)
{
    boolean retVal = E_NOT_OK;
    uint32 timeOutCounts = 1000, count = 0;
    uint32 v = readl(base + FS_32K_FS_GLB_CTL);

    /* check xtal ready */
    if (v & BM_FS_32K_FS_GLB_CTL_XTAL_RDY) {
        /* [1:1] 0:from osc32K
         *       1:from xtal
         */
        v |= BM_FS_32K_FS_GLB_CTL_FS_SRC_SEL;
        writel(v, base + FS_32K_FS_GLB_CTL);

        /* wait for xtal active, 32K clock 2 cycle */
        while (count < timeOutCounts) {
            Mcu_udelay(100);
            v = readl(base + FS_32K_FS_GLB_CTL);

            if (v & BM_FS_32K_FS_GLB_CTL_XTAL_ACTIVE)
                break;
            else
                count++;
        }

        if (count < timeOutCounts)
            retVal = E_OK;
    }

    return retVal;
}

void Mcu_RtcDisableRegParityErrIntEnable(uint32 base)
{
    uint32 v = readl(base + RTC_REG_PARITY_ERR_INT_STAT_EN);

    v &= ~(BM_REG_PARITY_ERR_INT_STAT_REG_PARITY_ERR);
    writel(v, base + RTC_REG_PARITY_ERR_INT_STAT_EN);
}

void Mcu_RtcEnableRegParityErrIntEnable(uint32 base)
{
    uint32 v = readl(base + RTC_REG_PARITY_ERR_INT_STAT_EN);

    v |= (BM_REG_PARITY_ERR_INT_STAT_REG_PARITY_ERR);
    writel(v, base + RTC_REG_PARITY_ERR_INT_STAT_EN);
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif
