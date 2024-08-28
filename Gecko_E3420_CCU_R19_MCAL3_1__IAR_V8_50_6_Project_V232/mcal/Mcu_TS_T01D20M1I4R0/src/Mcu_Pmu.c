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
 * \file     Mcu_Pmu.c                                                                                  *
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
#include "Mcu_GeneralTypes.h"
#include "Mcu_Pmu.h"
#include "Pmu_Reg.h"
#include "Mcu.h"
#include "Mcu_Rtc.h"

/********************************************************************************************************
 *                                 Private Macro definition                                             *
 *******************************************************************************************************/
/** \brief  Mcu_Pmu power ctrl signal delay value mask. */
#define PMU_PWR_SIGNAL_DELAY_SETTING_MASK       (0x3fU)

/** \brief  Mcu_Pmu power on signal delay value mask. */
#define FM_PWR_ON_SET_PWR_ON_X_SET_MASK         (0xfU)

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
/********************************************************************************************************
 *                                  Private Function Declarations                                       *
 *******************************************************************************************************/

/** *****************************************************************************************************
 * \brief This function disable MCU_PMU BCButton FSM conctrl.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuDisableButtonCtrlFsm
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
 * Description        : Turn on BCButton FSM conctrl the requirement is that while the BCButton is
 *                      on wakeup it has to go through a BCButton off process if you want to continue
 *                      wakeup. now, default disable BCButton FSM conctrl.
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
static void Mcu_Ip_PmuDisableButtonCtrlFsm(void)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + BC_CTRL_SET);

    /* default disable the state monitory for ButtonControl */
    v &= ~BM_BC_CTRL_SET_BC_FSM_ENABLE;

    writel(v, b + BC_CTRL_SET);
}

/** *****************************************************************************************************
 * \brief This function enable MCU_PMU BCButton.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuEnableButtonCtrlPin
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
 * Description        : Turn on BCButton for wakeup. It is written-able only when BC_DISABLE_LOCK
 *                      is zero.
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
static void Mcu_Ip_PmuEnableButtonCtrlPin(void)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + BC_CTRL_SET);

    /* check whether the button is currently locked */
    if (FALSE == (v & BM_BC_CTRL_SET_BC_DISABLE_LOCK))
    {
        /* enable the ButtonControl pin */
        v &= ~BM_BC_CTRL_SET_BC_DISABLE;

        writel(v, b + BC_CTRL_SET);
    }
}

/** *****************************************************************************************************
 * \brief This function set MCU_PMU BCButton off polarity.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuSetButtonCtrlOffPolarity
 *                      (
 *                          Mcu_PmuPolarityType polarity
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : polarity - To specify polarity is rising/falling or both.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The BCButton off means entering RTC mode. The BCButton on means exiting RTC mode.
 *                      The polarity is used to set an active level or edge.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
static void Mcu_Ip_PmuSetButtonCtrlOffPolarity(Mcu_PmuPolarityType polarity)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + BC_CTRL_SET);

    /* polarity of ButtonControl pin for off */
    if (PMU_LOW_ACTIVE == polarity)
    {
        /* 1:low active or falling edge OFF:high active or rising edge */
        v |= BM_BC_CTRL_SET_BC_OFF_POL;
    }
    else
    {
        /* 0:high active or rising edge OFF:low active or failing edge */
        v &= ~BM_BC_CTRL_SET_BC_OFF_POL;
    }

    writel(v, b + BC_CTRL_SET);
}

/** *****************************************************************************************************
 * \brief This function set MCU_PMU BCButton on polarity.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuSetButtonCtrlOnPolarity
 *                      (
 *                          Mcu_PmuPolarityType polarity
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : polarity - To specify polarity is rising/falling or both.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The BCButton off means entering RTC mode. The BCButton on means exiting RTC mode.
 *                      The polarity is used to set an active level or edge.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
static void Mcu_Ip_PmuSetButtonCtrlOnPolarity(Mcu_PmuPolarityType polarity)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + BC_CTRL_SET);

    /* polarity of ButtonControl pin for on */
    if (PMU_LOW_ACTIVE == polarity)
    {
        /* 1:low active or falling edge OFF:high active or rising edge */
        v |= BM_BC_CTRL_SET_BC_ON_POL;
    }
    else
    {
        /* 0:high active or rising edge OFF:low active or failing edge */
        v &= ~BM_BC_CTRL_SET_BC_ON_POL;
    }

    writel(v, b + BC_CTRL_SET);
}

/** *****************************************************************************************************
 * \brief This function set MCU_PMU BCButton off sensitive.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuSetButtonCtrlOffSensitive
 *                      (
 *                          Mcu_PmuTriggerModeType sensitive
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : sensitive - To specify button off sensitive is edge or level.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The BCButton off means entering RTC mode. The BCButton on means exiting RTC mode.
 *                      The sensitive is used to select level/edge valid.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
static void Mcu_Ip_PmuSetButtonCtrlOffSensitive(Mcu_PmuTriggerModeType sensitive)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + BC_CTRL_SET);

    /* sensitive of ButtonControl pin for off */
    if (PMU_TRIGGER_MODE_EDGE == sensitive)
    {
        /* 1: Edge */
        v |= BM_BC_CTRL_SET_BC_OFF_EDGE;
    }
    else
    {
        /* 0: Level */
        v &= ~BM_BC_CTRL_SET_BC_OFF_EDGE;
    }

    writel(v, b + BC_CTRL_SET);
}

/** *****************************************************************************************************
 * \brief This function set MCU_PMU BCButton on sensitive.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuSetButtonCtrlOnSensitive
 *                      (
 *                          Mcu_PmuTriggerModeType sensitive
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : sensitive - To specify button on sensitive is edge or level.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The BCButton off means entering RTC mode. The BCButton on means exiting RTC mode.
 *                      The sensitive is used to select level/edge valid.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
static void Mcu_Ip_PmuSetButtonCtrlOnSensitive(Mcu_PmuTriggerModeType sensitive)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + BC_CTRL_SET);

    /* sensitive of ButtonControl pin for off */
    if (PMU_TRIGGER_MODE_EDGE == sensitive)
    {
        /* 1: Edge */
        v |= BM_BC_CTRL_SET_BC_ON_EDGE;
    }
    else
    {
        /* 0: Level */
        v &= ~BM_BC_CTRL_SET_BC_ON_EDGE;
    }

    writel(v, b + BC_CTRL_SET);
}

/** *****************************************************************************************************
 * \brief This function set MCU_PMU BCButton filter timer.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuSetButtonControlFilterTimer
 *                      (
 *                          uint16 filterCnt,
 *                          uint16 sampleInterval
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : filterCnt - the numbers 32KHz cycle to filter.
 *                      sampleInterval - the numbers 32KHz cycle to collect a signal.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The time base is 32KHz Cycle. The signal is collected every
 *                      sampleInterval, and the filterCnt filters the trigger signal
 *                      that is less than the current value.
 *                      The actual filtering time = (BC_FILTER_CNT+2)*(2^BC_SAMPLE_INTERVAL)*32KHz.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
static void Mcu_Ip_PmuSetButtonControlFilterTimer(uint16 filterCnt, uint16 sampleInterval)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + BC_CTRL_SET);

    /* set filter (BC_FILTER_CNT+2)*(2^BC_SAMPLE_INTERVAL)=(1+2)*(2^0)=3*0.03125=0.1ms
       32K = 0.03125ms */
    v &= ~FM_BC_CTRL_SET_BC_FILTER_CNT;
    v &= ~FM_BC_CTRL_SET_BC_SAMPLE_INTERVAL;
    v |= FV_BC_CTRL_SET_BC_FILTER_CNT(filterCnt);
    v |= FV_BC_CTRL_SET_BC_SAMPLE_INTERVAL(sampleInterval);

    writel(v, b + BC_CTRL_SET);
}

/** *****************************************************************************************************
 * \brief This function set MCU_PMU BCButton pin Max off valid window.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuSetButtonCtrlMaxoffWindow
 *                      (
 *                          uint8 timeVal
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : timeVal - To specify the timer for max off window.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The time base is 32KHz Cycle.
 *                      The delay = BC_ON/OFF_VLD_MIN/MAX*(2^BC_CNT_UNIT)*32KHz.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
static void Mcu_Ip_PmuSetButtonCtrlMaxoffWindow(uint8 timeVal)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + BC_VLD_WINDOW);

    /* max window for valid "OFF" */
    v &= ~FM_BC_VLD_WINDOW_BC_OFF_VLD_MAX;
    v |= FV_BC_VLD_WINDOW_BC_OFF_VLD_MAX(timeVal);
    writel(v, b + BC_VLD_WINDOW);
}

/** *****************************************************************************************************
 * \brief This function set MCU_PMU BCButton pin Min off valid window.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuSetButtonCtrlMinOffWindow
 *                      (
 *                          uint8 timeVal
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : timeVal - To specify the timer for min off window.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The time base is 32KHz Cycle.
 *                      The delay = BC_ON/OFF_VLD_MIN/MAX*(2^BC_CNT_UNIT)*32KHz.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
static void Mcu_Ip_PmuSetButtonCtrlMinOffWindow(uint8 timeVal)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + BC_VLD_WINDOW);

    /* min window for valid "OFF" */
    v &= ~FM_BC_VLD_WINDOW_BC_OFF_VLD_MIN;
    v |= FV_BC_VLD_WINDOW_BC_OFF_VLD_MIN(timeVal);
    writel(v, b + BC_VLD_WINDOW);
}
/**
 * \brief  Set ButtonControl pin Max On valid window.
 * \param[in]   timeVal    To specify delay timeVal: delay timeVal = BC_ON/OFF_VLD_MIN/MAX*(2^BC_CNT_UNIT)
 *                                             default value BC_CNT_UNIT = 5
 */

/** *****************************************************************************************************
 * \brief This function set MCU_PMU BCButton pin Max on valid window.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuSetButtonCtrlMaxOnWindow
 *                      (
 *                          uint8 timeVal
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : timeVal - To specify the timer for max on window.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The time base is 32KHz Cycle.
 *                      The delay = BC_ON/OFF_VLD_MIN/MAX*(2^BC_CNT_UNIT)*32KHz.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
static void Mcu_Ip_PmuSetButtonCtrlMaxOnWindow(uint8 timeVal)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + BC_VLD_WINDOW);

    /* max window for valid "ON" */
    v &= ~FM_BC_VLD_WINDOW_BC_ON_VLD_MAX;
    v |= FV_BC_VLD_WINDOW_BC_ON_VLD_MAX(timeVal);

    writel(v, b + BC_VLD_WINDOW);
}

/** *****************************************************************************************************
 * \brief This function set MCU_PMU BCButton pin Min on valid window.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuSetButtonCtrlMinOnWindow
 *                      (
 *                          uint8 timeVal
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : timeVal - To specify the timer for min on window.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The time base is 32KHz Cycle.
 *                      The delay = BC_ON/OFF_VLD_MIN/MAX*(2^BC_CNT_UNIT)*32KHz.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
static void Mcu_Ip_PmuSetButtonCtrlMinOnWindow(uint8 timeVal)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + BC_VLD_WINDOW);

    /* min window for valid "ON" */
    v &= ~FM_BC_VLD_WINDOW_BC_ON_VLD_MIN;
    v |= FV_BC_VLD_WINDOW_BC_ON_VLD_MIN(timeVal);

    writel(v, b + BC_VLD_WINDOW);
}

/** *****************************************************************************************************
 * \brief This function enable/disable MCU_PMU BCButton pin Min/Max OFF valid window.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuEnableButtonCtrlMaxOffWindowSwitch
 *                      (
 *                          Mcu_PmuBcWinCheckType status
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : status - the BCButton window check enable/disable.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Select enable/disable window verification function independently
 *                      when entering RTC mode.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
static void Mcu_Ip_PmuEnableButtonCtrlMaxOffWindowSwitch(Mcu_PmuBcWinCheckType status)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + BC_CTRL_SET);

    /* enable/disable max window for valid "OFF" */
    if (PMU_BC_WINDOW_CHECK_ENABLE == status)
    {
        /* enable */
        v &= ~BM_BC_CTRL_SET_BC_OFF_VLD_MAX_DISABLE;
    }
    else
    {
        /* disable */
        v |= BM_BC_CTRL_SET_BC_OFF_VLD_MAX_DISABLE;
    }

    writel(v, b + BC_CTRL_SET);
}
/**
 * \brief  Switch ButtonCtrl Pin max on window check.
 * \param[in]   status      To specify whether to disable bc max on valid window check
 */

/** *****************************************************************************************************
 * \brief This function enable/disable MCU_PMU BCButton pin Min/Max ON valid window.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuEnableButtonCtrlMaxOnWindowSwitch
 *                      (
 *                          Mcu_PmuBcWinCheckType status
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : status - the BCButton window check enable/disable.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Select enable/disable window verification function independently
 *                      when exiting RTC mode.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
static void Mcu_Ip_PmuEnableButtonCtrlMaxOnWindowSwitch(Mcu_PmuBcWinCheckType status)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + BC_CTRL_SET);

    /* enable/disable max window for valid "ON" */
    if (PMU_BC_WINDOW_CHECK_ENABLE == status)
    {
        /* enable */
        v &= ~BM_BC_CTRL_SET_BC_ON_VLD_MAX_DISABLE;
    }
    else
    {
        /* disable */
        v |= BM_BC_CTRL_SET_BC_ON_VLD_MAX_DISABLE;
    }

    writel(v, b + BC_CTRL_SET);
}

/** *****************************************************************************************************
 * \brief This function set MCU_PMU BCButton pin the timer unit for window.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuSetButtonCtrlWindowTimerUnit
 *                      (
 *                          uint8 unit
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : unit - the Window unit time reference.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The time base is 32KHz Cycle. In conjunction with BC_ON/OFF_VLD_MIN/MAX,
 *                      used for BCButton pin Min/Max window.
 *                      The delay = BC_ON/OFF_VLD_MIN/MAX*(2^BC_CNT_UNIT)*32KHz.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
static void Mcu_Ip_PmuSetButtonCtrlWindowTimerUnit(uint8 unit)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + BC_CTRL_SET);

    /* control unit for ButtonControl */
    v &= ~FM_BC_CTRL_SET_BC_CNT_UNIT;
    v |= FV_BC_CTRL_SET_BC_CNT_UNIT(unit);

    writel(v, b + BC_CTRL_SET);
}

/** *****************************************************************************************************
 * \brief This function enable/disable MCU_PMU BCButton pin filter bypass.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuEnableButtonCtrlFilterBypass
 *                      (
 *                          Mcu_PmuFilterSelectType en
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : en - To specify whether to enable filter bypass.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : After the filtering function is enabled, signals that do not meet
 *                      the filtering time requirement are ignored.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
static void Mcu_Ip_PmuEnableButtonCtrlFilterBypass(Mcu_PmuFilterSelectType en)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + BC_CTRL_SET);

    /* bypass filter for ButtonControl */
    if (PMU_FILTER_ENABLE == en)
    {
        /* filter is enable */
        v &= ~BM_BC_CTRL_SET_BC_FILTER_BYPASS;
    }
    else
    {
        /* bypass filter */
        v |= BM_BC_CTRL_SET_BC_FILTER_BYPASS;
    }

    writel(v, b + BC_CTRL_SET);
}

/** *****************************************************************************************************
 * \brief This function set MCU_PMU BCButton pin filter edge.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuSetButtonCtrlFilterEdge
 *                      (
 *                          Mcu_PmuEdgeType edge
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : edge - To specify the filter edge.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : After the selected edge is triggered, the internal timer starts to work;
 *                      If the value is greater than the filter value, it is sent to other modules
 *                      in the PMU.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
static void Mcu_Ip_PmuSetButtonCtrlFilterEdge(Mcu_PmuEdgeType edge)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + BC_CTRL_SET);

    /* select which edge need to apply the filter for ButtonControl */
    v &= ~FM_BC_CTRL_SET_BC_FILTER_EDGE;
    v |= FV_BC_CTRL_SET_BC_FILTER_EDGE(edge);

    writel(v, b + BC_CTRL_SET);
}

/** *****************************************************************************************************
 * \brief This function set MCU_PMU Wakeup0 Pin Polarity.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuSetWakeup0PinPolarity
 *                      (
 *                          Mcu_PmuPolarityType polarity
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : edge - To specify the polarity.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : PMU_HIGH_ACTIVE:high active (for level mode), rising edge (for edge mode)
 *                      PMU_LOW_ACTIVE :low active (for level mode), falling edge (for edge mode)
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
static void Mcu_Ip_PmuSetWakeup0PinPolarity(Mcu_PmuPolarityType polarity)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + WAKEUP_CTRL);

    /* polarity selection for wakup0 pin */
    if (PMU_HIGH_ACTIVE == polarity)
    {
        /* high active (for level mode), rising edge (for edge mode ) */
        v &= ~BM_WAKEUP_CTRL_WKUP0_POL;
    }
    else
    {
        /* low active (for level mode), falling edge (for edge mode ) */
        v |= BM_WAKEUP_CTRL_WKUP0_POL;
    }

    writel(v, b + WAKEUP_CTRL);
}

/** *****************************************************************************************************
 * \brief This function set MCU_PMU Wakeup1 Pin Polarity.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuSetWakeup1PinPolarity
 *                      (
 *                          Mcu_PmuPolarityType polarity
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : polarity - To specify the polarity.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : PMU_HIGH_ACTIVE:high active (for level mode), rising edge (for edge mode)
 *                      PMU_LOW_ACTIVE :low active (for level mode), falling edge (for edge mode)
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
static void Mcu_Ip_PmuSetWakeup1PinPolarity(Mcu_PmuPolarityType polarity)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + WAKEUP_CTRL);

    /* polarity selection for wakup0 pin */
    if (PMU_HIGH_ACTIVE == polarity)
    {
        /* high active (for level mode), rising edge (for edge mode ) */
        v &= ~BM_WAKEUP_CTRL_WKUP1_POL;
    }
    else
    {
        /* low active (for level mode), falling edge (for edge mode ) */
        v |= BM_WAKEUP_CTRL_WKUP1_POL;
    }

    writel(v, b + WAKEUP_CTRL);
}

/** *****************************************************************************************************
 * \brief This function select MCU_PMU Wakeup0 Pin Trigger mode.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuSetWakeup0PinSensitive
 *                      (
 *                          Mcu_PmuTriggerModeType sensitive
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : edge - To specify the Trigger mode.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : To select level or edge selection for wakeup0.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
static void Mcu_Ip_PmuSetWakeup0PinSensitive(Mcu_PmuTriggerModeType sensitive)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + WAKEUP_CTRL);

    /* level or edge selection for wakeup0 */
    if (PMU_TRIGGER_MODE_EDGE == sensitive)
    {
        /* edge */
        v |= BM_WAKEUP_CTRL_WKUP0_EDGE;
    }
    else
    {
        /* level */
        v &= ~BM_WAKEUP_CTRL_WKUP0_EDGE;
    }

    writel(v, b + WAKEUP_CTRL);
}

/** *****************************************************************************************************
 * \brief This function select MCU_PMU Wakeup1 Pin Trigger mode.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuSetWakeup1PinSensitive
 *                      (
 *                          Mcu_PmuTriggerModeType sensitive
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : edge - To specify the Trigger mode.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : To select level or edge selection for wakeup1.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
static void Mcu_Ip_PmuSetWakeup1PinSensitive(Mcu_PmuTriggerModeType sensitive)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + WAKEUP_CTRL);

    /* level or edge selection for wakeup1 */
    if (PMU_TRIGGER_MODE_EDGE == sensitive)
    {
        /* edge */
        v |= BM_WAKEUP_CTRL_WKUP1_EDGE;
    }
    else
    {
        /* level */
        v &= ~BM_WAKEUP_CTRL_WKUP1_EDGE;
    }

    writel(v, b + WAKEUP_CTRL);
}

/** *****************************************************************************************************
 * \brief This function enable MCU_PMU Wakeup0 Pin.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuEnableWakeup0Pin
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
 * Description        : To enable Wakeup0 for wakeup Exiting RTC mode.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
static void Mcu_Ip_PmuEnableWakeup0Pin(void)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + WAKEUP_CTRL);

    /* enable the wakeup0 pin */
    v &= ~BM_WAKEUP_CTRL_WKUP0_DISABLE;

    writel(v, b + WAKEUP_CTRL);
}

/** *****************************************************************************************************
 * \brief This function enable MCU_PMU Wakeup1 Pin.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuEnableWakeup1Pin
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
 * Description        : To enable Wakeup1 for wakeup Exiting RTC mode.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
static void Mcu_Ip_PmuEnableWakeup1Pin(void)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + WAKEUP_CTRL);

    /* enable the wakeup1 pin */
    v &= ~BM_WAKEUP_CTRL_WKUP1_DISABLE;

    writel(v, b + WAKEUP_CTRL);
}

/** *****************************************************************************************************
 * \brief This function enable/disable MCU_PMU Wakeup0 Pin Filter Bypass.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuEnableWakeup0FilterBypass
 *                      (
 *                          Mcu_PmuFilterSelectType en
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : en - To specify whether enable filter.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : After the filtering function is enabled, signals that do not meet
 *                      the filtering time requirement are ignored.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
static void Mcu_Ip_PmuEnableWakeup0FilterBypass(Mcu_PmuFilterSelectType en)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + WAKEUP_CTRL);

    /* filter bypass for wakeup0 pin */
    if (PMU_FILTER_ENABLE == en)
    {
        /* enable the filter */
        v &= ~BM_WAKEUP_CTRL_WKUP0_FILTER_BYPASS;
    }
    else
    {
        /* filter bypass*/
        v |= BM_WAKEUP_CTRL_WKUP0_FILTER_BYPASS;
    }

    writel(v, b + WAKEUP_CTRL);
}

/** *****************************************************************************************************
 * \brief This function enable/disable MCU_PMU Wakeup1 Pin Filter Bypass.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuEnableWakeup1FilterBypass
 *                      (
 *                          Mcu_PmuFilterSelectType en
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : en - To specify whether enable filter.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : After the filtering function is enabled, signals that do not meet
 *                      the filtering time requirement are ignored.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
static void Mcu_Ip_PmuEnableWakeup1FilterBypass(Mcu_PmuFilterSelectType en)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + WAKEUP_CTRL);

    /* filter bypass for wakeup1 pin */
    if (PMU_FILTER_ENABLE == en)
    {
        /* enable the filter */
        v &= ~BM_WAKEUP_CTRL_WKUP1_FILTER_BYPASS;
    }
    else
    {
        /* filter bypass*/
        v |= BM_WAKEUP_CTRL_WKUP1_FILTER_BYPASS;
    }

    writel(v, b + WAKEUP_CTRL);
}

/** *****************************************************************************************************
 * \brief This function set MCU_PMU Wakeup0 pin filter edge.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuSetWakeup0FilterEdge
 *                      (
 *                          Mcu_PmuEdgeType edge
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : edge - To specify the filter edge.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : After the selected edge is triggered, the internal timer starts to work;
 *                      If the value is greater than the filter value, it is sent to other modules
 *                      in the PMU.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
static void Mcu_Ip_PmuSetWakeup0FilterEdge(Mcu_PmuEdgeType edgeType)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + WAKEUP_CTRL);

    /* select which edge need to apply the filter for wakeup0 pin */
    v &= ~FM_WAKEUP_CTRL_WKUP0_FILTER_EDGE;
    v |= FV_WAKEUP_CTRL_WKUP0_FILTER_EDGE(edgeType);

    writel(v, b + WAKEUP_CTRL);
}

/** *****************************************************************************************************
 * \brief This function set MCU_PMU Wakeup1 pin filter edge.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuSetWakeup1FilterEdge
 *                      (
 *                          Mcu_PmuEdgeType edgeType
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : edgeType - To specify the filter edge.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : After the selected edge is triggered, the internal timer starts to work;
 *                      If the value is greater than the filter value, it is sent to other modules
 *                      in the PMU.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
static void Mcu_Ip_PmuSetWakeup1FilterEdge(Mcu_PmuEdgeType edgeType)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + WAKEUP_CTRL);

    /* select which edge need to apply the filter for wakeup1 pin */
    v &= ~FM_WAKEUP_CTRL_WKUP1_FILTER_EDGE;
    v |= FV_WAKEUP_CTRL_WKUP1_FILTER_EDGE(edgeType);

    writel(v, b + WAKEUP_CTRL);
}

/** *****************************************************************************************************
 * \brief This function set MCU_PMU Wakeup0 filter timer.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuSetWakeup0FilterTimer
 *                      (
 *                          uint16 filterCnt,
 *                          uint16 sampleInterval
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : filterCnt - To specify wakeup0 pin filter timer WKUP0_FIELTER_CNT value.
 *                      sampleInterval - To specify wakeup0 pin filter timer WKUP0_SAMPLE_INTERVAL value.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The time base is 32KHz Cycle. The signal is collected every
 *                      sampleInterval, and the filterCnt filters the trigger signal
 *                      that is less than the current value.
 *                      The actual filtering time = (WKUP0_FILTER_CNT+2)*(2^WKUP0_SAMPLE_INTERVAL)*32KHz.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
static void Mcu_Ip_PmuSetWakeup0FilterTimer(uint16 filterCnt, uint16 sampleInterval)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + WAKEUP_CTRL);

    /* set filter (WKUP0_FILTER_CNT+2)*(2^WKUP0_SAMPLE_INTERVAL)=(1+2)*(2^0)=3*0.03125=0.1ms
       32K = 0.03125ms */
    v &= ~FM_WAKEUP_CTRL_WKUP0_FILTER_CNT;
    v &= ~FM_WAKEUP_CTRL_WKUP0_SAMPLE_INTERVAL;
    v |= FV_WAKEUP_CTRL_WKUP0_FILTER_CNT(filterCnt);
    v |= FV_WAKEUP_CTRL_WKUP0_SAMPLE_INTERVAL(sampleInterval);

    writel(v, b + WAKEUP_CTRL);
}


/** *****************************************************************************************************
 * \brief This function set MCU_PMU Wakeup1 filter timer.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuSetWakeup1FilterTimer
 *                      (
 *                          uint16 filterCnt,
 *                          uint16 sampleInterval
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : filterCnt - To specify wakeup1 pin filter timer WKUP1_FIELTER_CNT value.
 *                      sampleInterval - To specify wakeup1 pin filter timer WKUP1_SAMPLE_INTERVAL value.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The time base is 32KHz Cycle. The signal is collected every
 *                      sampleInterval, and the filterCnt filters the trigger signal
 *                      that is less than the current value.
 *                      The actual filtering time = (WKUP1_FILTER_CNT+2)*(2^WKUP1_SAMPLE_INTERVAL)*32KHz.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
static void Mcu_Ip_PmuSetWakeup1FilterTimer(uint16 filterCnt, uint16 sampleInterval)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + WAKEUP_CTRL);

    /* set filter (WKUP1_FILTER_CNT+2)*(2^WKUP1_SAMPLE_INTERVAL)=(1+2)*(2^0)=3*0.03125=0.1ms
       32K = 0.03125ms */
    v &= ~FM_WAKEUP_CTRL_WKUP1_FILTER_CNT;
    v &= ~FM_WAKEUP_CTRL_WKUP1_SAMPLE_INTERVAL;
    v |= FV_WAKEUP_CTRL_WKUP1_FILTER_CNT(filterCnt);
    v |= FV_WAKEUP_CTRL_WKUP1_SAMPLE_INTERVAL(sampleInterval);

    writel(v, b + WAKEUP_CTRL);
}


/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/

/** *****************************************************************************************************
 * \brief This function gets the current wake source for RTC mode.
 *
 * \verbatim
 * Syntax             : uint32 Mcu_Ip_PmuGetWakeupSource
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
 * Return value       : [0]: 1 - wakeup by external BC Button. 0 - other.
 *                      [1]: 1 - wakeup by RealTimeCounter periodic interrupt. 0 - other.
 *                      [2]: 1 - wakeup by external Wakeup Pin Button. 0 - other.
 *
 * Description        : Gets the current wake source for RTC mode.The state is saved until the user
 *                      calls the Mcu_Ip_PmuClearDownUpStatus and Mcu_Ip_PmuPwrdown function is not
 *                      cleared.
 *                      When user invokes Mcu_Ip_PmuPwrdown to enter RTC mode, the driver will actively
 *                      clear the current wakeup state.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
uint32 Mcu_Ip_PmuGetWakeupSource(void)
{
    uint32 b = PMU_RBASE;
    uint32 v;

    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    v = readl(b + PMU_DOWN_UP_STATUS) & 0x7U;

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();

    return v;
}

/** *****************************************************************************************************
 * \brief This function gets the last power down source.
 *
 * \verbatim
 * Syntax             : uint32 Mcu_Ip_PmuGetPowerDownSource
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
 * Return value       : [15]: 1 - power down by External BC button. 0 - other.
 *                      [14]: 1 - power down by software. 0 - other.
 *                      [13]: 1 - power down by SoC internal emergency power down request[7],
 *                                efuse vio. 0 - other.
 *                      [12]: 1 - power down by SoC internal emergency power down request[6],
 *                                Ap pt senser int. 0 - other.
 *                      [11]: 1 - power down by SoC internal emergency power down request[5],
 *                                sf pt senser int. 0 - other.
 *                      [10]: 1 - power down by SoC internal emergency power down request[4],
 *                                vd_ap int. 0 - other.
 *                      [09]: 1 - power down by SoC internal emergency power down request[3],
 *                                vd_sf_int. 0 - other.
 *                      [08]: 1 - power down by SoC internal emergency power down request[2],
 *                                fs_32k_lvpg not good. 0 - other.
 *                      [07]: 1 - power down by SoC internal emergency power down request[1],
 *                                Reserved. 0 - other.
 *                      [06]: 1 - power down by SoC internal emergency power down request[0],
 *                                sem12_int. 0 - other.
 *                      [05]: 1 - power down by Reserved. 0 - other.
 *                      [04]: 1 - power down by SMC reset check fail. 0 - other.
 *
 * Description        : Gets the last power down source.The state is saved until the user calls the
 *                      Mcu_Ip_PmuClearDownUpStatus and Mcu_Ip_PmuPwrdown function is not cleared.
 *                      When user invokes Mcu_Ip_PmuPwrdown to enter RTC mode, the driver will actively
 *                      clear the current wakeup state.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
uint32 Mcu_Ip_PmuGetPowerDownSource(void)
{
    uint32 b = PMU_RBASE;
    uint32 v;

    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    v = readl(b + PMU_DOWN_UP_STATUS) & 0xFFF0U;

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();

    return v;
}

/** *****************************************************************************************************
 * \brief This function clear the MCU_PMU.POWER_DOWN_STATUS.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuClearDownUpStatus
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
 * Description        : clear the last power down source value and the current wakeup source value.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
/*PRQA S 1505 1*/
void Mcu_Ip_PmuClearDownUpStatus(void)
{
    uint32 b = PMU_RBASE;

    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    /* Write 1 Clear the current status. */
    writel(0xFFFFU, b + PMU_DOWN_UP_STATUS);

    /* will read to confirm that the register has been reached */
    (void)readl(b + PMU_DOWN_UP_STATUS);

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();
}

/** *****************************************************************************************************
 * \brief This function Initialization the BCButton for RTC mode.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_Ip_PmuButtonControlInit
 *                      (
 *                          const Mcu_PmuButtonCtrlType *bcPtr
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : bcPtr - Pointer to configuration set
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Release successful.
 *                      MCU_E_PARAM_CONFIG: The Unreasonable parameter.
 *                      MCU_E_PARAM_POINTER: Pointer is NULL_PTR.
 *
 * Description        : When the BCButton uses the level mode to enter/exit RTC mode, the input
 *                      signal must be controlled within the window period, otherwise the BCButton
 *                      cannot be used to wake up.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
Std_ReturnType Mcu_Ip_PmuButtonControlInit(const Mcu_PmuButtonCtrlType *bcPtr)
{
    Std_ReturnType ret = E_OK;

    if (NULL_PTR != bcPtr)
    {
        /* RTC domain register Access hook enter function */
        RTC_DOMAIN_SS_HOOK_ENTER();

        /* enable BC button fsm */
        Mcu_Ip_PmuDisableButtonCtrlFsm();

        /* set BC button sensitive level */
        Mcu_Ip_PmuSetButtonCtrlOffSensitive(bcPtr->offMode);

        if (PMU_TRIGGER_MODE_LEVEL == bcPtr->offMode)
        {
            Mcu_Ip_PmuSetButtonCtrlWindowTimerUnit(bcPtr->timerUnit);
            Mcu_Ip_PmuSetButtonCtrlMinOffWindow(bcPtr->offMinVldWin);

            Mcu_Ip_PmuEnableButtonCtrlMaxOffWindowSwitch(bcPtr->offMaxVldSel);

            if (PMU_BC_WINDOW_CHECK_ENABLE == bcPtr->offMaxVldSel)
            {
                Mcu_Ip_PmuSetButtonCtrlMaxoffWindow(bcPtr->offMaxVldWin);
            } /* else not needed */
        }
        else if (PMU_TRIGGER_MODE_EDGE == bcPtr->offMode)
        {
            /* set BC button off polarity default falling,
            Before BC enable, the default pin is LOW */
            Mcu_Ip_PmuSetButtonCtrlOffPolarity(PMU_LOW_ACTIVE);

            /* switch BC button filter */
            Mcu_Ip_PmuEnableButtonCtrlFilterBypass(bcPtr->filterBypass);

            if (PMU_FILTER_ENABLE == bcPtr->filterBypass)
            {
                /* BC button filter edge set */
                Mcu_Ip_PmuSetButtonCtrlFilterEdge(bcPtr->edgeType);

                /* set BC button filter timer (BC_FILTER_CNT+2)*(2^BC_SAMPLE_INTERVAL) */
                Mcu_Ip_PmuSetButtonControlFilterTimer(bcPtr->filterCnt, bcPtr->sampleInterval);
            } /* else not needed */
        }
        else
        {
            ret = MCU_E_PARAM_CONFIG;
        }

        if (E_OK == ret)
        {
            /* set BC button on detect mode */
            Mcu_Ip_PmuSetButtonCtrlOnSensitive(bcPtr->onMode);

            if (PMU_TRIGGER_MODE_LEVEL == bcPtr->onMode)
            {
                Mcu_Ip_PmuSetButtonCtrlWindowTimerUnit(bcPtr->timerUnit);
                Mcu_Ip_PmuSetButtonCtrlMinOnWindow(bcPtr->onMinVldWin);

                Mcu_Ip_PmuEnableButtonCtrlMaxOnWindowSwitch(bcPtr->onMaxVldSel);

                if ( PMU_BC_WINDOW_CHECK_ENABLE == bcPtr->onMaxVldSel )
                {
                    Mcu_Ip_PmuSetButtonCtrlMaxOnWindow(bcPtr->onMaxVldWin);
                } /* else not needed */
            }
            else if (PMU_TRIGGER_MODE_EDGE == bcPtr->onMode)
            {
                /* set BC button off polarity default falling,
                Before BC enable, the default pin is LOW */
                Mcu_Ip_PmuSetButtonCtrlOnPolarity(PMU_LOW_ACTIVE);

                /* switch button ctrl filter */
                Mcu_Ip_PmuEnableButtonCtrlFilterBypass(bcPtr->filterBypass);

                if (PMU_FILTER_ENABLE == bcPtr->filterBypass)
                {
                    /* set BC button filter edge */
                    Mcu_Ip_PmuSetButtonCtrlFilterEdge(bcPtr->edgeType);
                    /* set BC button filter timer(BC_FILTER_CNT+2)*(2^BC_SAMPLE_INTERVAL) */
                    Mcu_Ip_PmuSetButtonControlFilterTimer(bcPtr->filterCnt, bcPtr->sampleInterval);
                } /* else not needed */
            }
            else
            {
                ret = MCU_E_PARAM_CONFIG;
            }

            if (E_OK == ret)
            {
                /* enable BC button pin */
                Mcu_Ip_PmuEnableButtonCtrlPin();

                /* set BC button off polarity */
                Mcu_Ip_PmuSetButtonCtrlOffPolarity(bcPtr->offPol);

                /* set BC button on polarity */
                Mcu_Ip_PmuSetButtonCtrlOnPolarity(bcPtr->onPol);
            } /* else not needed */
        } /* else not needed */

        /* will read to confirm that the register has been reached */
        (void)readl(PMU_RBASE + BC_CTRL_SET);

        /* RTC domain register Access hook exit function */
        RTC_DOMAIN_SS_HOOK_EXIT();
    }
    else
    {
        ret = MCU_E_PARAM_POINTER;
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function configures the pwr_ctrl signal mode.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuSetExtPwrctrlMode
 *                      (
 *                          Mcu_PmuStateType pmuMode,
 *                          Mcu_PmuPwrCtrlIdType id,
 *                          Mcu_PmuAutoManualType d1,
 *                          Mcu_PmuOnOffType d2
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : pmuMode - the target CPU mode.
 *                      id - the pwrctrl pin id.
 *                      d1 - the control mode.
 *                      d2 - the on/off control.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : If manual mode is selected, the Override function can be invoked to change
 *                      the current pwr_ctrl signal value.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
void Mcu_Ip_PmuSetExtPwrctrlMode(Mcu_PmuStateType pmuMode, Mcu_PmuPwrCtrlIdType id,
                                 Mcu_PmuAutoManualType d1,
                                 Mcu_PmuOnOffType d2)
{
    uint32 b = PMU_RBASE;
    uint32 v;
    uint32 data = ((uint32)d2 << 1U) | (uint32)d1;
    uint32 offset1 = (uint32)(6U - ((uint32)id * 2U));

    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    v = readl(b + PWR_CTRL_SET0);

    switch (pmuMode)
    {
    case PMU_STATE_RTC:
        v &= ~((uint32)FM_PWR_CTRL_SET0_PWR_CTRL_SET_MASK << (BM_PWR_CTRL_SET0_RTC_PWR_CTRL + offset1));
        v |= ((uint32)data << (BM_PWR_CTRL_SET0_RTC_PWR_CTRL + offset1));
        break;

    case PMU_STATE_RUN:
        v &= ~((uint32)FM_PWR_CTRL_SET0_PWR_CTRL_SET_MASK << (BM_PWR_CTRL_SET0_RUN_PWR_CTRL + offset1));
        v |= ((uint32)data << (BM_PWR_CTRL_SET0_RUN_PWR_CTRL + offset1));
        break;

    case PMU_STATE_SLEEP:
        v &= ~((uint32)FM_PWR_CTRL_SET0_PWR_CTRL_SET_MASK << (BM_PWR_CTRL_SET0_SLEEP_PWR_CTRL + offset1));
        v |= ((uint32)data << (BM_PWR_CTRL_SET0_SLEEP_PWR_CTRL + offset1));
        break;

    case PMU_STATE_HIBERNATE:
        v &= ~((uint32)FM_PWR_CTRL_SET0_PWR_CTRL_SET_MASK << offset1);
        v |= ((uint32)data << offset1);
        break;

    default:
        /*do nothing*/
        break;
    }

    writel(v, b + PWR_CTRL_SET0);

    /* will read to confirm that the register has been reached */
    (void)readl(b + PWR_CTRL_SET0);

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();
}

/** *****************************************************************************************************
 * \brief This function configures the pwr_ctrl signal delay time.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuSetExtPwrctrlDly
 *                      (
 *                         Mcu_PmuStateType pmuMode,
 *                         Mcu_PmuPwrCtrlIdType id,
 *                         uint8 delay,
 *                         uint8 delayAdj
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : pmuMode - the target CPU mode.
 *                      id - the pwrctrl pin id.
 *                      delay - the delay value.
 *                      delayAdj - the delay_adj value.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The configuration does not take effect after the Override is enabled.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
void Mcu_Ip_PmuSetExtPwrctrlDly(Mcu_PmuStateType pmuMode, Mcu_PmuPwrCtrlIdType id, uint8 delay,
                                uint8 delayAdj)
{
    uint32 b = PMU_RBASE;
    uint32 modeOffset = PWR_UP_PWR_CTRL_DELAY + ((uint32)pmuMode * 4U);
    uint32 pwrctrlStartbit = (uint32)id * 6U;
    uint32 v;

    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    v = readl(b + modeOffset);

    v &= ~((uint32)PMU_PWR_SIGNAL_DELAY_SETTING_MASK << pwrctrlStartbit);
    v |= ((uint32)((((uint32)((uint32)delayAdj & FM_PWR_CTRL_SET0_PWR_CTRL_SET_MASK) << 4U) | (uint32)delay) &
                   PMU_PWR_SIGNAL_DELAY_SETTING_MASK) << pwrctrlStartbit);

    writel(v, b + modeOffset);

    /* will read to confirm that the register has been reached */
    (void)readl(b + modeOffset);

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();
}

/** *****************************************************************************************************
 * \brief This function configures the pwr_ctrl signal Polarity.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuSetExtPwrctrlPolarity
 *                      (
 *                         Mcu_PmuPwrCtrlIdType id,
 *                         Mcu_PmuPolarityType polarity
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : id - the pwrctrl pin id.
 *                      polarity - To specify the polarity.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The configuration does not take effect after the Override is enabled.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
void Mcu_Ip_PmuSetExtPwrctrlPolarity(Mcu_PmuPwrCtrlIdType id, Mcu_PmuPolarityType polarity)
{
    uint32 b = PMU_RBASE;
    uint32 v;

    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    v = readl(b + PWR_CTRL_SET1);

    if (PMU_LOW_ACTIVE == polarity)
    {
        v |= ((uint32)1U << (BM_PWR_CTRL_SET1_PWR_CTRL_POL + (uint32)id));
    }
    else
    {
        v &= ~((uint32)1U << (BM_PWR_CTRL_SET1_PWR_CTRL_POL + (uint32)id));
    }

    writel(v, b + PWR_CTRL_SET1);

    /* will read to confirm that the register has been reached */
    (void)readl(b + PWR_CTRL_SET1);

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();
}

/** *****************************************************************************************************
 * \brief This function Configure the power_ctrl signal Override enable.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuSetExtPwrctrlOverrideEnable
 *                      (
 *                         Mcu_PmuPwrCtrlIdType id,
 *                         const Mcu_PmuPwrCtrlSelectType overrideEnable
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : id - the pwrctrl pin id.
 *                      overrideEnable - To enable/disable Override.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The value set here overrides the value set in Auto and manual mode when
 *                      Override is enabled.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
void Mcu_Ip_PmuSetExtPwrctrlOverrideEnable(Mcu_PmuPwrCtrlIdType id,
        const Mcu_PmuPwrCtrlSelectType overrideEnable)
{
    uint32 b = PMU_RBASE;
    uint32 v;

    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    v = readl(b + PWR_CTRL_SET1);

    if (PMU_PWRCTRL_SELECT == overrideEnable)
    {
        v |= ((uint32)1U << (BM_PWR_CTRL_SET1_SW_PWR_CTRL_EN + (uint32)id));
    }
    else
    {
        v &= ~((uint32)1U << (BM_PWR_CTRL_SET1_SW_PWR_CTRL_EN + (uint32)id));
    }

    writel(v, b + PWR_CTRL_SET1);

    /* will read to confirm that the register has been reached */
    (void)readl(b + PWR_CTRL_SET1);

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();
}

/** *****************************************************************************************************
 * \brief This function Configure the power_ctrl signal Override value.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuSetExtPwrctrlOverrideValue
 *                      (
 *                         Mcu_PmuPwrCtrlIdType id,
 *                         const Mcu_PmuPolarityType value
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : id - the pwrctrl pin id.
 *                      value - To select level value.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The value set here overrides the value set in Auto and manual mode when
 *                      Override is enabled.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
void Mcu_Ip_PmuSetExtPwrctrlOverrideValue(Mcu_PmuPwrCtrlIdType id, const Mcu_PmuPolarityType value)
{
    uint32 b = PMU_RBASE;
    uint32 v;

    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    v = readl(b + PWR_CTRL_SET1);

    if (PMU_HIGH_ACTIVE == value)
    {
        v |= ((uint32)1U << (BM_PWR_CTRL_SET1_SW_PWR_CTRL + (uint32)id));
    }
    else
    {
        v &= ~((uint32)1U << (BM_PWR_CTRL_SET1_SW_PWR_CTRL + (uint32)id));
    }

    writel(v, b + PWR_CTRL_SET1);

    /* will read to confirm that the register has been reached */
    (void)readl(b + PWR_CTRL_SET1);

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();
}

/** *****************************************************************************************************
 * \brief This function Configure the pwr_on signal delay time for all mode.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuSetPwronDly
 *                      (
 *                         Mcu_PmuStateType pmuMode,
                           uint8 id, uint8 delay,
                           uint8 delayAdj
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : pmuMode - the target CPU mode.
 *                      id - the pwron pin id.
 *                      delay - the delay value.
 *                      delayAdj - the delay_adj value.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : When the Auto mode is selected, the pwr_on signal will change after the
 *                      preset time during different state switching processes.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
void Mcu_Ip_PmuSetPwronDly(Mcu_PmuStateType pmuMode,
                           uint8 id, uint8 delay,
                           uint8 delayAdj)
{
    uint32 b = PMU_RBASE;
    uint32 modeOffset = PWR_UP_PWR_ON_DELAY + ((uint32)pmuMode * 4U);
    uint32 pwronStartbit = (uint32)id * 6U;
    uint32 v;

    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    v = readl(b + modeOffset);

    /* delay setting of pwr_on0~3 in pmu power state */
    v |= ((uint32)(((((uint32)delayAdj << 4U) | delay) & PMU_PWR_SIGNAL_DELAY_SETTING_MASK)) <<
          pwronStartbit) ;

    writel(v, b + modeOffset);

    /* will read to confirm that the register has been reached */
    (void)readl(b + modeOffset);

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();
}

/** *****************************************************************************************************
 * \brief This function is used to get the enable state of the wakeup0 pin.
 *
 * \verbatim
 * Syntax             : uint8 Mcu_Ip_PmuGetWakeup0EnableStatus
 *                      (
 *
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
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
uint8 Mcu_Ip_PmuGetWakeup0EnableStatus(void)
{
    uint32 b = PMU_RBASE;
    uint32 v;

    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    v = readl(b + WAKEUP_CTRL) ;

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();

    /* wakup0 pin status */
    v = (v & BM_WAKEUP_CTRL_WKUP0_DISABLE) >> 29U;

    return (uint8)v;
}

/** *****************************************************************************************************
 * \brief This function is used to get the enable state of the wakeup1 pin.
 *
 * \verbatim
 * Syntax             : uint8 Mcu_Ip_PmuGetWakeup1EnableStatus
 *                      (
 *
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
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
uint8 Mcu_Ip_PmuGetWakeup1EnableStatus(void)
{
    uint32 b = PMU_RBASE;
    uint32 v;

    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    v = readl(b + WAKEUP_CTRL);

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();

    /* wakup1 pin status */
    v = (v & BM_WAKEUP_CTRL_WKUP1_DISABLE) >> 30U;

    return (uint8)v;
}

/** *****************************************************************************************************
 * \brief This function is used to get the polarity selection of the wakeup0 pin.
 *
 * \verbatim
 * Syntax             : uint8 Mcu_Ip_PmuGetWakeup0Pol
 *                      (
 *
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
 * Return value       : 0 --  high active (for level mode), rising edge (for edge mode)
 *                      1 --  low active (for level mode), falling edge (for edge mode)
 *
 * Description        : Different trigger modes have different interpretations of the return value,
 *                      please pay attention to the relevant technical documentation.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
uint8 Mcu_Ip_PmuGetWakeup0Pol(void)
{
    uint32 b = PMU_RBASE;
    uint32 v;

    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    v = readl(b + WAKEUP_CTRL);

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();

    /* polarity selection for wakup0 pin */
    v = (v & BM_WAKEUP_CTRL_WKUP0_POL) >> 27U;

    return (uint8)v;
}

/** *****************************************************************************************************
 * \brief This function is used to get the polarity selection of the wakeup1 pin.
 *
 * \verbatim
 * Syntax             : uint8 Mcu_Ip_PmuGetWakeup0Pol
 *                      (
 *
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
 * Return value       : 0 --  high active (for level mode), rising edge (for edge mode)
 *                      1 --  low active (for level mode), falling edge (for edge mode)
 *
 * Description        : Different trigger modes have different interpretations of the return value,
 *                      please pay attention to the relevant technical documentation.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
uint8 Mcu_Ip_PmuGetWakeup1Pol(void)
{
    uint32 b = PMU_RBASE;
    uint32 v;

    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    v = readl(b + WAKEUP_CTRL);

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();

    /* polarity selection for wakup1 pin */
    v = (v & BM_WAKEUP_CTRL_WKUP1_POL) >> 28U;

    return (uint8)v;
}

/** *****************************************************************************************************
 * \brief This function is used to select whether wakeup0 pin and wakeup1 pin work together to wakeup.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_Ip_PmuEnableWakeup01Pin
 *                      (
 *                         Mcu_PmuWakeupSrcEnableType enable
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : enable - enable/disable wakeup0 pin and wakeup1 pin work together to wakeup.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : When wakeup0 pin and wakeup1 pin are used together as the wake source event for
 *                      RTC mode, edge mode is strongly not recommended. When selecting edge mode at the
 *                      same time, each edge signal must be collected at the 32KHz sampling point at the
 *                      same time before it can be awakened. Otherwise, it will always be in a low power
 *                      state.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
void Mcu_Ip_PmuEnableWakeup01Pin(Mcu_PmuWakeupSrcEnableType enable)
{
    uint32 b = PMU_RBASE;
    uint32 v;

    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    v = readl(b + WAKEUP_CTRL);

    /* when enabled,generate the wakeup event only when wakeup0 and wakeup1 are both active */
    if (PMU_WAKEUP_SRC_ENABLE == enable)
    {
        /* enable */
        v |= BM_WAKEUP_CTRL_WKUP01_AND_ENABLE;
    }
    else
    {
        /* disable */
        v &= ~BM_WAKEUP_CTRL_WKUP01_AND_ENABLE;
    }

    writel(v, b + WAKEUP_CTRL);

    /* will read to confirm that the register has been reached */
    (void)readl(b + WAKEUP_CTRL);

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();
}

/** *****************************************************************************************************
 * \brief This function is used to configure the properties associated with the wakeup0 pin.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_Ip_PmuEnableWakeup0Wakeup
 *                      (
 *                         const Mcu_PmuPinCtrlType *wakeupctlPtr
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : wakeupctlPtr - wakeup Pin-related attributes.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Attributes are legal.
 *                      MCU_E_PARAM_POINTER: wakeupctlPtr is NULL.
 *
 * Description        : The wakeup0 pin is only used for RTC mode wakeup. Pin-related properties
 *                      must be properly configured.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042 SWSR_MCU_054 SWSR_MCU_055
 *******************************************************************************************************/
Std_ReturnType Mcu_Ip_PmuEnableWakeup0Wakeup(const Mcu_PmuPinCtrlType *wakeupctlPtr)
{
    Std_ReturnType ret = E_OK;

    if (NULL_PTR == wakeupctlPtr)
    {
        ret = MCU_E_PARAM_POINTER;
    }
    else
    {
        /* RTC domain register Access hook enter function */
        RTC_DOMAIN_SS_HOOK_ENTER();

        if ((PMU_EDGE_TYPE_INVALID == wakeupctlPtr->pulseEdgeType) &&
                (PMU_TRIGGER_MODE_LEVEL == wakeupctlPtr->sensitive))
        {
            /* set pin detect mode */
            Mcu_Ip_PmuSetWakeup0PinSensitive(PMU_TRIGGER_MODE_LEVEL);

            /* switch pin edge filter */
            Mcu_Ip_PmuEnableWakeup0FilterBypass(wakeupctlPtr->filterBypass);

            if (PMU_FILTER_ENABLE == wakeupctlPtr->filterBypass)
            {
                /* set pin filter edge */
                Mcu_Ip_PmuSetWakeup0FilterEdge(wakeupctlPtr->edgeType);
                /* set pin filter timer*/
                Mcu_Ip_PmuSetWakeup0FilterTimer(wakeupctlPtr->filterCnt, wakeupctlPtr->sampleInterval);
            } /* else not needed */
        }
        else
        {
            /* SRCS_BITS[31] and SRCS_BITS[20] control the rising/failing edge detcet enable */
            if (PMU_EDGE_TYPE_RISING == wakeupctlPtr->edgeType)
            {
                rmw32(APB_PMU_CORE_BASE + SRCS_BITS, 31U, 1U, 0x1U);
                rmw32(APB_PMU_CORE_BASE + SRCS_BITS, 20U, 1U, 0x0U);
            }
            else if (PMU_EDGE_TYPE_FALLING == wakeupctlPtr->edgeType)
            {
                rmw32(APB_PMU_CORE_BASE + SRCS_BITS, 31U, 1U, 0x0U);
                rmw32(APB_PMU_CORE_BASE + SRCS_BITS, 20U, 1U, 0x1U);
            }
            else if (PMU_EDGE_TYPE_BOTH == wakeupctlPtr->edgeType)
            {
                rmw32(APB_PMU_CORE_BASE + SRCS_BITS, 31U, 1U, 0x1U);
                rmw32(APB_PMU_CORE_BASE + SRCS_BITS, 20U, 1U, 0x1U);
            }
            else
            {
                /*do nothing*/
            }

            /* set pin detect mode */
            Mcu_Ip_PmuSetWakeup0PinSensitive(PMU_TRIGGER_MODE_EDGE);

            /* switch pin edge filter */
            Mcu_Ip_PmuEnableWakeup0FilterBypass(PMU_FILTER_BYPASS);
        }

        /* set wakeup0 pin polarity */
        Mcu_Ip_PmuSetWakeup0PinPolarity(wakeupctlPtr->polarity);

        /* enable wakeup0 pin for wakeup */
        Mcu_Ip_PmuEnableWakeup0Pin();

        /* will read to confirm that the register has been reached */
        (void)readl(PMU_RBASE + WAKEUP_CTRL);

        /* RTC domain register Access hook exit function */
        RTC_DOMAIN_SS_HOOK_EXIT();

    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function is used to configure the properties associated with the wakeup1 pin.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_Ip_PmuEnableWakeup1Wakeup
 *                      (
 *                         const Mcu_PmuPinCtrlType *wakeupctlPtr
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : wakeupctlPtr - wakeup Pin-related attributes.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Attributes are legal.
 *                      MCU_E_PARAM_POINTER: wakeupctlPtr is NULL.
 *
 * Description        : The wakeup1 pin is only used for RTC mode wakeup. Pin-related properties
 *                      must be properly configured.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042 SWSR_MCU_054 SWSR_MCU_055
 *******************************************************************************************************/
Std_ReturnType Mcu_Ip_PmuEnableWakeup1Wakeup(const Mcu_PmuPinCtrlType *wakeupctlPtr)
{
    Std_ReturnType ret = E_OK;

    if (NULL_PTR == wakeupctlPtr)
    {
        ret = MCU_E_PARAM_POINTER;
    }
    else
    {
        /* RTC domain register Access hook enter function */
        RTC_DOMAIN_SS_HOOK_ENTER();

        /* set pin detect mode */
        Mcu_Ip_PmuSetWakeup1PinSensitive(wakeupctlPtr->sensitive);

        /* set pin edge filter data */
        if (PMU_TRIGGER_MODE_LEVEL == wakeupctlPtr->sensitive)
        {
            /* switch pin filter */
            Mcu_Ip_PmuEnableWakeup1FilterBypass(wakeupctlPtr->filterBypass);

            /* set pin edge filter data */
            if (PMU_FILTER_ENABLE == wakeupctlPtr->filterBypass)
            {
                /* set pin filter edge */
                Mcu_Ip_PmuSetWakeup1FilterEdge(wakeupctlPtr->edgeType);
                /* set pin filter timer */
                Mcu_Ip_PmuSetWakeup1FilterTimer(wakeupctlPtr->filterCnt, wakeupctlPtr->sampleInterval);
            } /* else not needed */
        } /* else not needed */

        /* set wakeup1 pin polarity */
        Mcu_Ip_PmuSetWakeup1PinPolarity(wakeupctlPtr->polarity);

        /* enable wakeup1 pin with wakeup event */
        Mcu_Ip_PmuEnableWakeup1Pin();

        /* will read to confirm that the register has been reached */
        (void)readl(PMU_RBASE + WAKEUP_CTRL);

        /* RTC domain register Access hook exit function */
        RTC_DOMAIN_SS_HOOK_EXIT();
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function configures whether to enable ButtonControl pin for wakeup with RTC mode.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuEnableExtWakeupSrc
 *                      (
 *                         Mcu_PmuWakeupSrcEnableType enable
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : enable - enable/disable ButtonControl pin wake up event.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This wakeup event is only used in RTC mode. The user must set a reasonable
 *                      pin attribute for the ButtonControl pin.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
void Mcu_Ip_PmuEnableExtWakeupSrc(Mcu_PmuWakeupSrcEnableType enable)
{
    uint32 b = PMU_RBASE;
    uint32 v;

    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    v = readl(b + WAKEUP_CTRL);

    /* enable/disable external wakeup which is generate by ButtonControl pin */
    if (PMU_WAKEUP_SRC_ENABLE == enable)
    {
        /* enable external ButtonControl pin for wake up event */
        v |= BM_WAKEUP_CTRL_EXT_WAKEUP_EN;
    }
    else
    {
        /* disable external ButtonControl pin for wake up event */
        v &= ~BM_WAKEUP_CTRL_EXT_WAKEUP_EN;
    }

    writel(v, b + WAKEUP_CTRL);

    /* will read to confirm that the register has been reached */
    (void)readl(b + WAKEUP_CTRL);

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();
}

/** *****************************************************************************************************
 * \brief This function configures whether to enable RTC periodic interrupt for wakeup with RTC mode.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuEnableIntWakeupSrc
 *                      (
 *                         Mcu_PmuWakeupSrcEnableType enable
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : enable - enable/disable RTC periodic interrupt wake up event.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This wakeup event is only used in RTC mode. The RTC Timer alarm time must
 *                      be properly set.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
void Mcu_Ip_PmuEnableIntWakeupSrc(Mcu_PmuWakeupSrcEnableType enable)
{
    uint32 b = PMU_RBASE;
    uint32 v;

    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    v = readl(b + WAKEUP_CTRL);

    /* enable/disable internal wakeup event which is generate by RTC periodic interrupt */
    if (PMU_WAKEUP_SRC_ENABLE == enable)
    {
        /* enable internal RTC periodic interrupt for wake up event */
        v |= BM_WAKEUP_CTRL_INT_WAKEUP_EN;
    }
    else
    {
        /* disable internal RTC periodic interrupt for wake up event */
        v &= ~BM_WAKEUP_CTRL_INT_WAKEUP_EN;
    }

    writel(v, b + WAKEUP_CTRL);

    /* will read to confirm that the register has been reached */
    (void)readl(b + WAKEUP_CTRL);

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();
}

/** *****************************************************************************************************
 * \brief This function is used to trigger entry into RTC mode.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuPwrdown
 *                      (
 *
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
 * Description        : When this function is executed, all cores will lose power except the RTC domain.
 *                      Before executing this function, the user must save the relevant data and use
 *                      the DMB,DSB,ISB synchronization instructions to ensure that the data transfer
 *                      is complete.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
void Mcu_Ip_PmuPwrdown(void)
{
    uint32 b = PMU_RBASE;
    uint32 v;

    /* clear current power down up status */
    Mcu_Ip_PmuClearDownUpStatus();

    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    /* disable RTC parity error interrupt status, because low power need disable RTC pclk */
    Mcu_Ip_RtcDisableRegParityErrIntEnable(APB_RTC1_BASE);
    Mcu_Ip_RtcDisableRegParityErrIntEnable(APB_RTC2_BASE);

    v = readl(b + BC_CTRL_SET);

    /* Note: a rising-edge needed to trigger the power down process */
    v |= BM_BC_CTRL_SET_PWR_DWN_REQ_SOFT;
    writel(v, b + BC_CTRL_SET);

    /* will read to confirm that the register has been reached */
    (void)readl(b + BC_CTRL_SET);

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();
}

/** *****************************************************************************************************
 * \brief This function is used to clear power down request.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuResumeCb
 *                      (
 *
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
 * Description        : When the bit value is 1, the power-off request is automatically triggered.
 *                      In normal cases, the hardware automatically clears this bit after waking up.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
void Mcu_Ip_PmuResumeCb(void)
{
    /* Rising-edge needed to trigger the pwrdown. Here we clear pwrdown bit thus
     * SW don't have to wait one 32KHz cycle to wait the sync to 32K domain.
     */
    uint32 b = PMU_RBASE;
    uint32 v;

    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    v = readl(b + BC_CTRL_SET);
    v &= ~BM_BC_CTRL_SET_PWR_DWN_REQ_SOFT;
    writel(v, b + BC_CTRL_SET);

    /* will read to confirm that the register has been reached */
    (void)readl(b + BC_CTRL_SET);

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();
}

/** *****************************************************************************************************
 * \brief This function is used to enable/disable DCDC.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuDcdcEn
 *                      (
 *                         boolean en
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : en - enable/disable DCDC.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The DCDC output is controlled by the pwr_on0 signal. According to the manual control
 *                      of the enable/disable pwr_on0 signal, the user needs to select the level value
 *                      according to the actual need of his board.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005
 *******************************************************************************************************/
void Mcu_Ip_PmuDcdcEn(boolean en)
{
    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    /* Select DCDC (pwr_on0) enable/disable */
    if (TRUE == en)
    {
        /* disable SW_PWR_ON_EN[0] for pwr_on0 with manual control */
        rmw32(APB_PMU_CORE_BASE + BM_SW_OVRRIDE_OFFSET, 4U, 1U, 0U);
        /* set SW_PWR_ON[0] value for pwr_on0 */
        rmw32(APB_PMU_CORE_BASE + BM_SW_OVRRIDE_OFFSET, 0U, 1U, 0U);
    }
    else
    {
        /* clear SW_PWR_ON[0] value for pwr_on0 */
        rmw32(APB_PMU_CORE_BASE + BM_SW_OVRRIDE_OFFSET, 0U, 1U, 1U);
        /* enable SW_PWR_ON_EN[0] for pwr_on0 with manual control */
        rmw32(APB_PMU_CORE_BASE + BM_SW_OVRRIDE_OFFSET, 4U, 1U, 1U);
    }

    /* will read to confirm that the register has been reached */
    (void)readl(APB_PMU_CORE_BASE + BM_SW_OVRRIDE_OFFSET);

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();
}

/** *****************************************************************************************************
 * \brief This function is used to enable/disable LDO.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuLdoEn
 *                      (
 *                         boolean en
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : en - enable/disable LDO.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The LDO output is controlled by the pwr_on1 signal. According to the manual control
 *                      of the enable/disable pwr_on1 signal, the user needs to select the level value
 *                      according to the actual need of his board.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005
 *******************************************************************************************************/
void Mcu_Ip_PmuLdoEn(boolean en)
{
    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    /* Select LDO (pwr_on1) enable/disable */
    if (TRUE == en)
    {
        /* set SW_PWR_ON[1] value for pwr_on1 */
        rmw32(APB_PMU_CORE_BASE + BM_SW_OVRRIDE_OFFSET, 2U, 1U, 0U);
        /* disable SW_PWR_ON_EN[1] for pwr_on1 with manual control */
        rmw32(APB_PMU_CORE_BASE + BM_SW_OVRRIDE_OFFSET, 6U, 1U, 0U);
    }
    else
    {
        /* clear SW_PWR_ON[1] value for pwr_on1 */
        rmw32(APB_PMU_CORE_BASE + BM_SW_OVRRIDE_OFFSET, 2U, 1U, 1U);
        /* enable SW_PWR_ON_EN[1] for pwr_on1 with manual control */
        rmw32(APB_PMU_CORE_BASE + BM_SW_OVRRIDE_OFFSET, 6U, 1U, 1U);
    }

    /* will read to confirm that the register has been reached */
    (void)readl(APB_PMU_CORE_BASE + BM_SW_OVRRIDE_OFFSET);

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();
}

/** *****************************************************************************************************
 * \brief This function is used to disable RTC mode wakeup source pin.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuDisableWakeupSrcPin
 *                      (
 *
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
 * Description        : The default disable Wakeup0 Wakeup1 and BCButton pin, Reopen the back if necessary.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005
 *******************************************************************************************************/
void Mcu_Ip_PmuDisableWakeupSrcPin(void)
{
    uint32 b = PMU_RBASE;
    uint32 v;

    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    v = readl(b + BC_CTRL_SET);

    /* check whether the button is currently locked */
    if (FALSE == (v & BM_BC_CTRL_SET_BC_DISABLE_LOCK))
    {
        /* disable the ButtonControl pin */
        v |= BM_BC_CTRL_SET_BC_DISABLE;

        writel(v, b + BC_CTRL_SET);
    }

    v = readl(b + WAKEUP_CTRL);
    /* disable the wakeup1 pin */
    v |= BM_WAKEUP_CTRL_WKUP1_DISABLE;
    /* disable the wakeup0 pin */
    v |= BM_WAKEUP_CTRL_WKUP0_DISABLE;
    writel(v, b + WAKEUP_CTRL);

    /* will read to confirm that the register has been reached */
    (void)readl(b + WAKEUP_CTRL);

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();
}
#if (MCU_3V3POWEROFF_RESET == STD_ON)
/** *****************************************************************************************************
 * \brief This function is used to enable 3.3V power-off reset.
 *
 * \verbatim
 * Syntax             : void Mcu_Pmu3v3PorOffReset
 *                      (
 *
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
 *                      enable monitor SF 0.8V power good status.
 *                      When 3.3V is powered down, the SF 0.8V Power good status is set to 0,
 *                      and 0 is detected to cause a reset.
 *                      reset means global reset,without RTC domain, and reset reason is 0.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005
 *******************************************************************************************************/
void Mcu_Ip_Pmu3v3PorOffReset(void)
{
    uint32 regValue;

    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    /*Set pmu reset when 3.3V power off*/
    regValue = (readl(APB_PMU_CORE_BASE + PG_LP_MODE_CTRL) | BM_PG_LP_MODE_CTRL_RTC_LV_MONITOR ) & (~BM_PG_LP_MODE_CTRL_SF_LV_PG_DISABLE);

    writel(regValue, APB_PMU_CORE_BASE + PG_LP_MODE_CTRL);

    /* will read to confirm that the register has been reached */
    regValue = readl(APB_PMU_CORE_BASE + PG_LP_MODE_CTRL);
    (void)regValue;

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();
}
#endif /**#if (MCU_3V3POWEROFF_RESET == STD_ON)*/
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif
/* End of file */
