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
 *  \file     Mcu_RtcMode.h                                                                             *
 *  \brief    This file contains interface header for Mcu MCAL driver, ...                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/03     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef MCU_RTCMODE_H
#define MCU_RTCMODE_H

#ifdef __cplusplus
extern "C"
{
#endif
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Mcu_Pmu.h"

/********************************************************************************************************
 *                                      Global variables                                                *
 *******************************************************************************************************/
/** \brief Record the Temporary manual Sleep Time value of the RTC Timer. */
extern Mcu_RtcAlarmType Mcu_PwrRtcSleepTime[MCU_MODE_ALL];
/********************************************************************************************************
 *                                  Global Types definition                                             *
 *******************************************************************************************************/
/** \brief wakeup source enable/disable define */
typedef enum
{
    WAKEUP_SRC_DISABLE = 0U,
    WAKEUP_SRC_ENABLE,
/*PRQA S 1535 1*/
} Mcu_WakeupSrcType;

/** \brief pwr_ctl0~3 pwr_on0~3 define */
typedef struct
{
    const Mcu_PmuPwrCtrlType    *pwrCtrl0;
    const Mcu_PmuPwrCtrlType    *pwrCtrl1;
    const Mcu_PmuPwrCtrlType    *pwrCtrl2;
    const Mcu_PmuPwrCtrlType    *pwrCtrl3;
} Mcu_PwrSigType;

/** \brief RtcMode Struct Define */
typedef struct
{
    const Mcu_PmuWakeupSrcType  *wakeupsrc;
    const Mcu_PmuPinCtrlType    *wakeup0;
    const Mcu_PmuPinCtrlType    *wakeup1;
    const Mcu_PmuButtonCtrlType *bc;
    const Mcu_RtcAlarmType      *rtc;
    const Mcu_PwrSigType        *pmu;
} Mcu_RtcModeConfigType;

/** \brief pum pwr_ctrl0~3 auto.polarity and override enable*/
typedef struct
{
    const Mcu_PmuPwrCtrlConfigType *config;
    const Mcu_PwrSigType           *runPmu;
    const Mcu_PwrSigType           *pwrupPmu;
} Mcu_PmuCtrlConfigType;

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
void Mcu_Ip_RtcModeSetPwrSleepTime(const Mcu_ModeType mcuMode, const Mcu_RtcAlarmType rtcSleepTime);

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
Std_ReturnType Mcu_Ip_RtcWakeupConfig(Mcu_RtcAlarmType *manualPtr, const Mcu_RtcAlarmType *rtcPtr);

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
        const Mcu_PwrSigType *pmuPtr);

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
        const Mcu_PwrSigType *pwrupPmuPtr);

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
Std_ReturnType Mcu_Ip_RtcModeConfig(const Mcu_RtcModeConfigType *rtcModeConfigPtr);

#ifdef __cplusplus
}
#endif

#endif /* MCU_RTCMODE_H */
/* End of file */
