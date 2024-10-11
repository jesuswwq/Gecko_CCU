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
 * \file     Mcu_RtcMode.c                                                                              *
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
#include "Std_Types.h"
#include "RegHelper.h"
#include "RegBase.h"
#include "Mcu_GeneralTypes.h"
#include "Mcu_Rtc.h"
#include "Mcu_RtcMode.h"
/********************************************************************************************************
 *                                 Private Macro definition                                             *
 *******************************************************************************************************/

/** \brief Macro for RTC IO PAD. */
#define PAD_CONFIG_SYS_MODE0                0x1000U
#define PAD_CONFIG_SYS_MODE1                0x1004U
#define PAD_CONFIG_SYS_POR_B                0x1008U
#define PAD_CONFIG_SYS_BUTTON               0x100cU
#define PAD_CONFIG_SYS_WAKEUP0              0x1010U
#define PAD_CONFIG_SYS_WAKEUP1              0x1014U
#define PAD_CONFIG_SYS_CTRL0                0x1018U
#define PAD_CONFIG_SYS_CTRL1                0x101cU
#define PAD_CONFIG_SYS_CTRL2                0x1020U
#define PAD_CONFIG_SYS_CTRL3                0x1024U
/********************************************************************************************************
 *                                  Global Variable Declarations                                        *
 *******************************************************************************************************/
#define MCU_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"
/** \brief Record the Temporary manual Sleep Time value of the RTC Timer. */
Mcu_RtcAlarmType Mcu_PwrRtcSleepTime[MCU_MODE_ALL];
#define MCU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
/********************************************************************************************************
 *                                  Private Function Declarations                                       *
 *******************************************************************************************************/

/** *****************************************************************************************************
 * \brief This function configure Special pin pull up and down for RTC domain.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_RtcModePadPinMuxConfig
 *                      (
 *                          Mcu_PmuPolarityType wakeup0,
 *                          Mcu_PmuPolarityType wakeup1
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : wakeup0 - wakeup0 pin Polarity attribute.
 *                      wakeup1 - wakeup1 pin Polarity attribute.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The pwr_ctrl signal is pulled up and down according to the internal circuit
 *                      of the IC. The wakeup pin is pulled up and down according to the user-set
 *                      wakeup level state.
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042 SWSR_MCU_043
 *******************************************************************************************************/
static void Mcu_Ip_RtcModePadPinMuxConfig(Mcu_PmuPolarityType wakeup0, Mcu_PmuPolarityType wakeup1)
{
    rmw32(APB_IOMUXC_RTC_BASE + PAD_CONFIG_SYS_CTRL0, 0U, 2U, 0x1U); /* pull down */
    rmw32(APB_IOMUXC_RTC_BASE + PAD_CONFIG_SYS_CTRL1, 0U, 2U, 0x1U); /* pull down */
    rmw32(APB_IOMUXC_RTC_BASE + PAD_CONFIG_SYS_CTRL2, 0U, 2U, 0x1U); /* pull down */
    rmw32(APB_IOMUXC_RTC_BASE + PAD_CONFIG_SYS_CTRL3, 0U, 2U, 0x1U); /* pull down */

    if (PMU_LOW_ACTIVE == wakeup0)
    {
        rmw32(APB_IOMUXC_RTC_BASE + PAD_CONFIG_SYS_WAKEUP0, 0U, 2U, 0x3U); /* pull up */
    }
    else
    {
        rmw32(APB_IOMUXC_RTC_BASE + PAD_CONFIG_SYS_WAKEUP0, 0U, 2U, 0x1U); /* pull down */
    }

    if (PMU_LOW_ACTIVE == wakeup1)
    {
        rmw32(APB_IOMUXC_RTC_BASE + PAD_CONFIG_SYS_WAKEUP1, 0U, 2U, 0x3U); /* pull up */
    }
    else
    {
        rmw32(APB_IOMUXC_RTC_BASE + PAD_CONFIG_SYS_WAKEUP1, 0U, 2U, 0x1U); /* pull down */
    }
}

/** *****************************************************************************************************
 * \brief This function configure BCButton attribute for RTC mode wakeup.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_Ip_RtcModeBcButtonWakeupConfig
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
 * Parameters (in)    : bcPtr - BCButton Indicates the key configuration parameter.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK:configure OK;
 *                      other:Parameter invalid;
 *
 * Description        : BCButton can be used to enter/exit RTC mode. When BCButton is enabled,
 *                      it takes effect immediately.
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042 SWSR_MCU_043 SWSR_MCU_054 SWSR_MCU_055
 *******************************************************************************************************/
static Std_ReturnType Mcu_Ip_RtcModeBcButtonWakeupConfig(const Mcu_PmuButtonCtrlType *bcPtr)
{
    /* Init ButtonControl Config. */
    return Mcu_Ip_PmuButtonControlInit(bcPtr);
}

/** *****************************************************************************************************
 * \brief This function configure wakeup0 pin attribute for RTC mode wakeup.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_Ip_RtcModeWakep0PinWakeupConfig
 *                      (
 *                          const Mcu_PmuPinCtrlType *wakeup0Ptr
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : wakeup0Ptr - wakeup0 pin Indicates the key configuration parameter.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK:configure OK;
 *                      other:Parameter invalid;
 *
 * Description        : include wakeup0 pin sensitive,polarity,filter enable,filter edge and filter timer.
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042 SWSR_MCU_043 SWSR_MCU_054 SWSR_MCU_055
 *******************************************************************************************************/
static Std_ReturnType Mcu_Ip_RtcModeWakep0PinWakeupConfig(const Mcu_PmuPinCtrlType *wakeup0Ptr)
{
    /* Init Wakeup 0 Config. */
    return Mcu_Ip_PmuEnableWakeup0Wakeup(wakeup0Ptr);
}

/** *****************************************************************************************************
 * \brief This function configure wakeup1 pin attribute for RTC mode wakeup.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_Ip_RtcModeWakep1PinWakeupConfig
 *                      (
 *                          const Mcu_PmuPinCtrlType *wakeup0Ptr
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : wakeup0Ptr - wakeup1 pin Indicates the key configuration parameter.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK:configure OK;
 *                      other:Parameter invalid;
 *
 * Description        : include wakeup1 pin sensitive,polarity,filter enable,filter edge and filter timer.
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042 SWSR_MCU_043 SWSR_MCU_054 SWSR_MCU_055
 *******************************************************************************************************/
static Std_ReturnType Mcu_Ip_RtcModeWakep1PinWakeupConfig(const Mcu_PmuPinCtrlType *wakeup1Ptr)
{
    /* Init Wakeup 1 Config. */
    return Mcu_Ip_PmuEnableWakeup1Wakeup(wakeup1Ptr);
}

/** *****************************************************************************************************
 * \brief This function enable wakeup source for RTC mode wakeup.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_Ip_RtcModePmuWakeupSourceEnableConfig
 *                      (
 *                          const Mcu_PmuWakeupSrcType *wkupsrcPtr
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : wkupsrcPtr - the Wakeup source parameter pointer.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK:configure OK;
 *                      other:Parameter invalid;
 *
 * Description        : include rtc Timer, wakeup0 pin, wakeup1 pin and BC Button.
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042 SWSR_MCU_043 SWSR_MCU_054 SWSR_MCU_055
 *******************************************************************************************************/
static Std_ReturnType Mcu_Ip_RtcModePmuWakeupSourceEnableConfig(const Mcu_PmuWakeupSrcType
        *wkupsrcPtr)
{
    Std_ReturnType ret = E_OK;

    /* RTC wakeup Enable Check */
    if (PMU_WAKEUP_SRC_ENABLE == wkupsrcPtr->rtcSrc)
    {
        /* Enable RTC wakeup */
        Mcu_Ip_PmuEnableIntWakeupSrc(PMU_WAKEUP_SRC_ENABLE);
    } /* else not needed */

    /* wakeup0Ptr pin and wakeup1Ptr pin wakeup Enable Check */
    if ((PMU_WAKEUP_SRC_ENABLE == wkupsrcPtr->wakeup0Src)
            || (PMU_WAKEUP_SRC_ENABLE == wkupsrcPtr->wakeup1Src))
    {
        /* wakeup0Ptr pin and wakeup1Ptr pin logic check Config*/
        if (PMU_LOGIC_AND == wkupsrcPtr->wakeup01Sel)
        {
            Mcu_Ip_PmuEnableWakeup01Pin(PMU_WAKEUP_SRC_ENABLE);
        }
        else
        {
            Mcu_Ip_PmuEnableWakeup01Pin(PMU_WAKEUP_SRC_DISABLE);
        }
    } /* else not needed */

    /* BC Button Wakeup Enable Check */
    if (PMU_WAKEUP_SRC_ENABLE == wkupsrcPtr->bcButtonSrc)
    {
        /* Enable BC Button wakeup */
        Mcu_Ip_PmuEnableExtWakeupSrc(PMU_WAKEUP_SRC_ENABLE);
    } /* else not needed */

    return ret;
}

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/

/** *****************************************************************************************************
 * \brief This function is used to set the wake time of the temporary sleep Timer in RTC mode.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_Ip_RtcModeSetPwrSleepTime
 *                      (
 *                          const Mcu_ModeType mcuMode,
 *                          const Mcu_RtcAlarmType rtcSleepTime
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : McuMode - The power mode to switch to.
 *                      Rtc_SleepTime - RTC sleep parameter.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : If the user is not satisfied with only using the EB generated RTC Timer to
 *                      set the wake time, you can use this function to temporarily replace the
 *                      wake time. When power_down->RTC mode->power_up is completed once, the
 *                      set parameters are cleared automatically, regardless of whether the RTC
 *                      Timer is used as the wake source.
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042 SWSR_MCU_043
 *******************************************************************************************************/
void Mcu_Ip_RtcModeSetPwrSleepTime(const Mcu_ModeType mcuMode, const Mcu_RtcAlarmType rtcSleepTime)
{
    Mcu_PwrRtcSleepTime[mcuMode] = rtcSleepTime;
}

/** *****************************************************************************************************
 * \brief This function is used to configure the RTC Timer for RTC mode.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_Ip_RtcWakeupConfig
 *                      (
 *                          Mcu_RtcAlarmType *manualPtr,
 *                          const Mcu_RtcAlarmType *rtcPtr
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : manualPtr - The Temporary manual parameter pointer.
 *                      rtcPtr - The EB Configuration parameter pointer.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : After the sleep time is set, the temporary manual setting parameter timer is
 *                      automatically cleared. To use the temporary manual value again, the user must
 *                      call the Mcu_Ip_RtcModeSetPwrSleepTime function again.
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042 SWSR_MCU_043 SWSR_MCU_054 SWSR_MCU_055 SW_SM006
 *******************************************************************************************************/
Std_ReturnType Mcu_Ip_RtcWakeupConfig(Mcu_RtcAlarmType *manualPtr, const Mcu_RtcAlarmType *rtcPtr)
{
    Std_ReturnType ret;

    if ((NULL_PTR == manualPtr) || (NULL_PTR == rtcPtr))
    {
        ret = MCU_E_PARAM_POINTER;
    }
    else
    {
        if (RTC1 == rtcPtr->channel)
        {
            /* Set RTC alarm time and enable wakeup */
            if (manualPtr->timer1 != 0x0U)
            {
                ret = Mcu_Ip_RtcSetSleepTime(APB_RTC1_BASE, manualPtr->timer1, manualPtr->timerMode1);
            }
            else
            {
                ret = Mcu_Ip_RtcSetSleepTime(APB_RTC1_BASE, rtcPtr->timer1, rtcPtr->timerMode1);
            }
        }
        else if (RTC2 == rtcPtr->channel)
        {
            /* Set RTC alarm time and enable wakeup */
            if (manualPtr->timer2 != 0x0U)
            {
                ret = Mcu_Ip_RtcSetSleepTime(APB_RTC2_BASE, manualPtr->timer2, manualPtr->timerMode2);
            }
            else
            {
                ret = Mcu_Ip_RtcSetSleepTime(APB_RTC2_BASE, rtcPtr->timer2, rtcPtr->timerMode2);
            }
        }
        else
        {
            /* Set RTC alarm time and enable wakeup */
            if (manualPtr->timer1 != 0x0U)
            {
                ret = Mcu_Ip_RtcSetSleepTime(APB_RTC1_BASE, manualPtr->timer1, manualPtr->timerMode1);
            }
            else
            {
                ret = Mcu_Ip_RtcSetSleepTime(APB_RTC1_BASE, rtcPtr->timer1, rtcPtr->timerMode1);
            }

            /* Set RTC alarm time and enable wakeup */
            if ((manualPtr->timer2 != 0x0U) && (E_OK == ret))
            {
                ret = Mcu_Ip_RtcSetSleepTime(APB_RTC2_BASE, manualPtr->timer2, manualPtr->timerMode2);
            }
            else
            {
                ret = Mcu_Ip_RtcSetSleepTime(APB_RTC2_BASE, rtcPtr->timer2, rtcPtr->timerMode2);
            }
        }

        manualPtr->timer1 = 0U;
        manualPtr->timer2 = 0U;
    }


    return ret;
}

/** *****************************************************************************************************
 * \brief This function is used to configure the pwr_ctrl0~3 for running/powerup state.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_Ip_RtcModePmuSetPwrCtrlConfig
 *                      (
 *                          const Mcu_PmuPwrCtrlConfigType *configPtr,
 *                          const Mcu_PwrSigType *runPmuPtr,
 *                          const Mcu_PwrSigType *pwrupPmuPtr
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : configPtr - The polarity parameter pointer.
 *                      runPmuPtr - The running state pwr_ctrl signal delay time parameter pointer.
 *                      pwrupPmuPtr - The powerup state pwr_ctrl signal delay time parameter pointer.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The polarity of the pwr_ctrl signal is the same in all modes; The run/powerup
 *                      status is automatically controlled by the IP address. You can only set the delay.
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042 SWSR_MCU_043 SWSR_MCU_054 SWSR_MCU_055 SW_SM006
 *******************************************************************************************************/
Std_ReturnType Mcu_Ip_RtcModePmuSetPwrCtrlConfig(const Mcu_PmuPwrCtrlConfigType *configPtr,
        const Mcu_PwrSigType *runPmuPtr,
        const Mcu_PwrSigType *pwrupPmuPtr)
{
    Std_ReturnType ret;

    if ((NULL_PTR == configPtr) || (NULL_PTR == pwrupPmuPtr) || (NULL_PTR == runPmuPtr))
    {
        ret = MCU_E_PARAM_POINTER;
    }
    else
    {
        /* set pwr_ctrl auto polarity */
        Mcu_Ip_PmuSetExtPwrctrlPolarity(PMU_PWRCTRL_0, configPtr->pwrCtrl0Polarity);
        Mcu_Ip_PmuSetExtPwrctrlPolarity(PMU_PWRCTRL_1, configPtr->pwrCtrl1Polarity);
#ifndef SEMIDRIVE_E3_LITE_SERIES
        Mcu_Ip_PmuSetExtPwrctrlPolarity(PMU_PWRCTRL_2, configPtr->pwrCtrl2Polarity);
        Mcu_Ip_PmuSetExtPwrctrlPolarity(PMU_PWRCTRL_3, configPtr->pwrCtrl3Polarity);
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/
        /* set pwr_ctrl for pwr_up mode */
        ret = Mcu_Ip_PmuPowerControlSignalConfig(PMU_STATE_PWR_UP, pwrupPmuPtr);
        /*PRQA S 2991,2995 1*/
        if (E_OK == ret)
        {
            /* set pwr_ctrl for run mode */
            ret = Mcu_Ip_PmuPowerControlSignalConfig(PMU_STATE_RUN, runPmuPtr);
        } /* else not needed */

    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function is used to configure the pwr_ctrl0~3 for lowpower state.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_Ip_PmuPowerControlSignalConfig
 *                      (
 *                          const Mcu_PmuStateType pmuMode,
 *                          const Mcu_PwrSigType *pmuPtr
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : pmuMode - The target mdoe.
 *                      pmuPtr - The pwr_ctrl signal parameter pointer.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK - Execution process successful.
 *                      MCU_E_PARAM_POINTER - The Pointer is NULL.
 *                      MCU_E_PARAM_CONFIG - The Parameter invalid.
 *
 * Description        : Configure the delay time of pwr_ctrl signal in different states, open/close,
 *                      automatic/manual control, etc.
 *                      Note: The delay of all pwr_ctrl signals is timed relative to the same datum
 *                      point.
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042 SWSR_MCU_043 SWSR_MCU_054 SWSR_MCU_055
 *******************************************************************************************************/
Std_ReturnType Mcu_Ip_PmuPowerControlSignalConfig(const Mcu_PmuStateType pmuMode,
        const Mcu_PwrSigType *pmuPtr)
{
    Std_ReturnType ret = E_OK;

    if (NULL_PTR == pmuPtr)
    {
        ret = MCU_E_PARAM_POINTER;
    }
    else if (pmuMode >= PMU_STATE_INVALID)
    {
        ret = MCU_E_PARAM_CONFIG;
    }
    else
    {
        /* pwr_ctrl0 */
        if (pmuPtr->pwrCtrl0 != NULL_PTR)
        {
            Mcu_Ip_PmuSetExtPwrctrlMode(pmuMode, PMU_PWRCTRL_0,
                                        pmuPtr->pwrCtrl0->autoManual, pmuPtr->pwrCtrl0->onOff);
            Mcu_Ip_PmuSetExtPwrctrlDly(pmuMode, PMU_PWRCTRL_0, pmuPtr->pwrCtrl0->delay,
                                       pmuPtr->pwrCtrl0->delayAdj);
        } /* else not needed */

        /* pwr_ctrl1 */
        if (pmuPtr->pwrCtrl1 != NULL_PTR)
        {
            Mcu_Ip_PmuSetExtPwrctrlMode(pmuMode, PMU_PWRCTRL_1,
                                        pmuPtr->pwrCtrl1->autoManual, pmuPtr->pwrCtrl1->onOff);
            Mcu_Ip_PmuSetExtPwrctrlDly(pmuMode, PMU_PWRCTRL_1, pmuPtr->pwrCtrl1->delay,
                                       pmuPtr->pwrCtrl1->delayAdj);
        } /* else not needed */

#ifndef SEMIDRIVE_E3_LITE_SERIES

        /* pwr_ctrl2 */
        if (pmuPtr->pwrCtrl2 != NULL_PTR)
        {
            Mcu_Ip_PmuSetExtPwrctrlMode(pmuMode, PMU_PWRCTRL_2,
                                        pmuPtr->pwrCtrl2->autoManual, pmuPtr->pwrCtrl2->onOff);
            Mcu_Ip_PmuSetExtPwrctrlDly(pmuMode, PMU_PWRCTRL_2, pmuPtr->pwrCtrl2->delay,
                                       pmuPtr->pwrCtrl2->delayAdj);
        } /* else not needed */

        /* pwr_ctrl3 */
        if (pmuPtr->pwrCtrl3 != NULL_PTR)
        {
            Mcu_Ip_PmuSetExtPwrctrlMode(pmuMode, PMU_PWRCTRL_3,
                                        pmuPtr->pwrCtrl3->autoManual, pmuPtr->pwrCtrl3->onOff);
            Mcu_Ip_PmuSetExtPwrctrlDly(pmuMode, PMU_PWRCTRL_3, pmuPtr->pwrCtrl3->delay,
                                       pmuPtr->pwrCtrl3->delayAdj);
        } /* else not needed */

#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function is used to configure low power Feature for RTC mode.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_Ip_RtcModeConfig
 *                      (
 *                          const Mcu_RtcModeConfigType *rtcModeConfigPtr
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : rtcModeConfigPtr - The parameter pointer for RTC mode.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK - Execution process successful.
 *                      MCU_E_PARAM_POINTER - The Pointer is NULL.
 *                      other - Reference internal function.
 *
 * Description        : Configuration functions include: BCButton, wakeup0/1, PWR_CTRL0-3, PWR_ON0-3
 *                      properties, including the wake source configuration, and RTC domain pin
 *                      drop-down configuration function.
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042 SWSR_MCU_043 SWSR_MCU_054 SWSR_MCU_055 SW_SM006
 *******************************************************************************************************/
Std_ReturnType Mcu_Ip_RtcModeConfig(const Mcu_RtcModeConfigType *rtcModeConfigPtr)
{
    Std_ReturnType ret = E_OK;

    if (NULL_PTR != rtcModeConfigPtr)
    {
        /* disable wakeup source pin */
        Mcu_Ip_PmuDisableWakeupSrcPin();

        /* clear RTC Timer Wakeup Flag */
        (void)Mcu_Ip_RtcClearWakeupFlag(APB_RTC1_BASE);
        (void)Mcu_Ip_RtcClearWakeupFlag(APB_RTC2_BASE);

        /* BC button wakeup Config */
        if (NULL_PTR != rtcModeConfigPtr->bc)
        {
            ret = Mcu_Ip_RtcModeBcButtonWakeupConfig(rtcModeConfigPtr->bc);
        } /* else not needed */

        /* wakeup0Ptr pin wakeup Config*/
        if ((E_OK == ret) && (NULL_PTR != rtcModeConfigPtr->wakeup0))
        {
            ret = Mcu_Ip_RtcModeWakep0PinWakeupConfig(rtcModeConfigPtr->wakeup0);
        } /* else not needed */

        /* wakeup1Ptr pin wakeup Config*/
        if ((E_OK == ret) && (NULL_PTR != rtcModeConfigPtr->wakeup1))
        {
            ret = Mcu_Ip_RtcModeWakep1PinWakeupConfig(rtcModeConfigPtr->wakeup1);
        } /* else not needed */

        /* rtcmode wakup source enable configPtr*/
        if ((E_OK == ret) && (NULL_PTR != rtcModeConfigPtr->wakeupsrc))
        {
            ret = Mcu_Ip_RtcModePmuWakeupSourceEnableConfig(rtcModeConfigPtr->wakeupsrc);
        } /* else not needed */

        /* power control signal: pwr_ctrl0~3 configuration */
        if ((E_OK == ret) && (NULL_PTR != rtcModeConfigPtr->pmu))
        {
            ret = Mcu_Ip_PmuPowerControlSignalConfig(PMU_STATE_RTC, rtcModeConfigPtr->pmu);
        } /* else not needed */

        if ((E_OK == ret) && (NULL_PTR != rtcModeConfigPtr->wakeup0)
                && (NULL_PTR != rtcModeConfigPtr->wakeup1))
        {
            /* ALARM: When wakeup from rtc mode,These pin need to be reconfig to restore normal mode */
            Mcu_Ip_RtcModePadPinMuxConfig(rtcModeConfigPtr->wakeup0->polarity,
                                          rtcModeConfigPtr->wakeup1->polarity);
        } /* else not needed */
    }
    else
    {
        ret = MCU_E_PARAM_POINTER;
    }

    return ret;
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif
