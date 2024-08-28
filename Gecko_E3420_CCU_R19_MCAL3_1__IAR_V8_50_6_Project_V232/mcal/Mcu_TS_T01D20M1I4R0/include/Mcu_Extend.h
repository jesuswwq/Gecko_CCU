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
 *  \file     Mcu_Extend.h                                                                              *
 *  \brief    This file contains interface header for MCU MCAL driver, ...                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/02     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef MCU_EXTEND_H
#define MCU_EXTEND_H

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Platform_Types.h"
#include "Mcu_GeneralTypes.h"
#include "Mcu_Clk.h"
#include "Mcu_Dcdc.h"
#include "Mcu_Ldo.h"
#include "Mcu_KickCore.h"
#include "Mcu_PvtSens.h"
#include "Mcu_Reset.h"
#include "Mcu_Rtc.h"
#include "Mcu_Pmu.h"
#include "Mcu_Ckgen.h"
#include "Mcu_RtcMode.h"
#include "Mcu_Rstgen.h"
#include "Mcu_Modules.h"
#include "Mcu_Cfg.h"
#include "Mcu_ResetDrv.h"

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
/** *****************************************************************************************************
 * \brief This function set clock rate.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_ClkSetRate(Mcu_ClkNodeType *clkPtr, Mcu_ClkRateType rate)
 *
 * Service ID[hex]    : 0x11
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : configPtr - Pointer to clock node to set rate
 *                      rate - clock rate to set
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : errorId
 *
 * Description        : This function set clock rate.
 * \endverbatim
 * Traceability       : SWSR_MCU_004 SW_SM001
 *******************************************************************************************************/
Std_ReturnType Mcu_ClkSetRate(Mcu_ClkNodeType *clkPtr, Mcu_ClkRateType rate);
/** *****************************************************************************************************
 * \brief This function get clock rate.
 *
 * \verbatim
 * Syntax             : Mcu_ClkRateType Mcu_ClkGetRate(Mcu_ClkNodeType *clkPtr)
 *
 * Service ID[hex]    : 0x12
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : configPtr - Pointer to clock node to set rate
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : clock rate value
 *
 * Description        : This function get clock rate.
 * \endverbatim
 * Traceability       : SWSR_MCU_004 SW_SM001
 *******************************************************************************************************/
Mcu_ClkRateType Mcu_ClkGetRate(Mcu_ClkNodeType *clkPtr);
#ifdef CONFIG_CLK_MONITOR
/** *****************************************************************************************************
 * \brief This function monitor clock rate.
 *
 * \verbatim
 * Syntax             : uint8 Mcu_CkgenMonFreq(Mcu_CkgenMonFreqType *ckgenMonFreqPtr)
 *
 * Service ID[hex]    : 0x13
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : ckgenMonFreqPtr - Pointer to clock monitor node
 *
 * Parameters (out)   : None
 *
 * Return value       : clock monitor status
 *                      0 - the monitor status of clock rate is ok
 *                      !0 - the monitor status of clock rate is not ok
 *
 * Description        : This function monitor clock rate.
 * \endverbatim
 * Traceability       : SWSR_MCU_049 SW_SM001
 *******************************************************************************************************/
uint8 Mcu_CkgenMonFreq(Mcu_CkgenMonFreqType *ckgenMonFreqPtr);
/** *****************************************************************************************************
 * \brief This function monitor clock cqm.
 *
 * \verbatim
 * Syntax             : uint8 Mcu_CkgenCqm(Mcu_CkgenCqmType *ckgenCqmPtr)
 *
 * Service ID[hex]    : 0x14
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : ckgenCqmPtr - Pointer to clock cqm monitor node
 *
 * Parameters (out)   : None
 *
 * Return value       : clock monitor status
 *                      0 - the monitor status of clock cqm is ok
 *                      !0 - the monitor status of clock cqm is not ok
 *
 * Description        : This function monitor clock cqm.
 * \endverbatim
 * Traceability       : SWSR_MCU_049 SW_SM001
 *******************************************************************************************************/
uint8 Mcu_CkgenCqm(Mcu_CkgenCqmType *ckgenCqmPtr);
#endif /** #ifdef CONFIG_CLK_MONITOR*/
/** *****************************************************************************************************
 * \brief This function set the dcdc detect.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_DcdcFaultDetect(const Dcdc_OvUvCfgType *dcdcCfgPtr)
 *
 * Service ID[hex]    : 0xB
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : dcdcCfgPtr - Pointer to dcdc detect set
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : errorId
 *
 * Description        : This function set the dcdc detect.
 * \endverbatim
 * Traceability       : SWSR_MCU_052 SW_SM001
 *******************************************************************************************************/
Std_ReturnType Mcu_DcdcFaultDetect(const Dcdc_OvUvCfgType *dcdcCfgPtr);
/** *****************************************************************************************************
 * \brief This function kickcore.
 *
 * \verbatim
 * Syntax             : void Mcu_SocKickCore(Mcu_KickCoreType core, uint32 entry)
 *
 * Service ID[hex]    : 0x15
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : core - core to reset
 *                      entry - address to remap
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : errorId
 *
 * Description        : This function kickcore.
 * \endverbatim
 * Traceability       : SW_SM001
 *******************************************************************************************************/
void Mcu_SocKickCore(Mcu_KickCoreType core, uint32 entry);
/** *****************************************************************************************************
 * \brief This function enable temperature monitor.
 *
 * \verbatim
 * Syntax             : void Mcu_PvtInit(void)
 *
 * Service ID[hex]    : 0xA
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
 * Return value       : errorId
 *
 * Description        : This function enable temperature monitor.
 * \endverbatim
 * Traceability       : SWSR_MCU_051 SW_SM001
 *******************************************************************************************************/
void Mcu_PvtInit(void);
/** *****************************************************************************************************
 * \brief This function get temperature value.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_PvtGet(Mcu_PvtType *devPtr, float *temperaturePtr)
 *
 * Service ID[hex]    : 0xA
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : devPtr - pointer to pvt device
 *
 * Parameters (inout) : temperaturePtr - pointer to pvt value
 *
 * Parameters (out)   : None
 *
 * Return value       : errorId
 *
 * Description        : This function get temperature value.
 * \endverbatim
 * Traceability       : SWSR_MCU_051 SW_SM001
 *******************************************************************************************************/
Std_ReturnType Mcu_PvtGet(Mcu_PvtType *devPtr, float *temperaturePtr);

/** *****************************************************************************************************
 * \brief This function get SF PVT sensor device.
 *
 * \verbatim
 * Syntax             : Mcu_PvtType *Mcu_PvtGetSfDevice(void)
 *
 * Service ID[hex]    : none
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
 * Return value       : SF PVT sensor device
 *
 * Description        : This function get SF PVT sensor device.
 * \endverbatim
 * Traceability       : SWSR_MCU_051
 *******************************************************************************************************/
Mcu_PvtType *Mcu_PvtGetSfDevice(void);

#ifndef SEMIDRIVE_E3_LITE_SERIES
/** *****************************************************************************************************
 * \brief This function enable temperature monitor for VD.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_PvtForVdInit(const Mcu_PvtForVdType *vDconfigPtr)
 *
 * Service ID[hex]    : 0xA
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : vDconfigPtr - pointer to vd pvt config
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : errorId
 *
 * Description        : This function enable temperature monitor for VD.
 * \endverbatim
 * Traceability       : SWSR_MCU_051 SW_SM001
 *******************************************************************************************************/
Std_ReturnType Mcu_PvtForVdInit(const Mcu_PvtForVdType *vDconfigPtr);

#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/

#ifndef SEMIDRIVE_E3_LITE_SERIES
/** *****************************************************************************************************
 * \brief This function get AP PVT sensor device.
 *
 * \verbatim
 * Syntax             : const Mcu_PvtType *Mcu_PvtGetApDevice(void)
 *
 * Service ID[hex]    : none
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
 * Return value       : AP PVT sensor device
 *
 * Description        : This function get AP PVT sensor device.
 * \endverbatim
 * Traceability       : SWSR_MCU_051
 *******************************************************************************************************/
Mcu_PvtType *Mcu_PvtGetApDevice(void);
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/
/** *****************************************************************************************************
 * \brief This function read general register value.
 *
 * \verbatim
 * Syntax             : uint32 Mcu_ResetCtlGeneralRead(const Mcu_ResetGeneralRegType *generalPtr)
 *
 * Service ID[hex]    : 0x16
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : generalPtr - pointer to general register
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : general reg value
 *
 * Description        : This function read general register value.
 * \endverbatim
 *******************************************************************************************************/
uint32 Mcu_ResetCtlGeneralRead(const Mcu_ResetGeneralRegType *generalPtr);
/** *****************************************************************************************************
 * \brief This function Write general register value.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_ResetCtlGeneralWrite(const Mcu_ResetGeneralRegType *generalPtr, uint32 val)
 *
 * Service ID[hex]    : 0x17
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : generalPtr - pointer to general register
 *                      val - value to write
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : errorId
 *                      0 if success,
 *                      other error code.
 *
 * Description        : This function Write general register value.
 * \endverbatim
 *******************************************************************************************************/
Std_ReturnType Mcu_ResetCtlGeneralWrite(const Mcu_ResetGeneralRegType *generalPtr, uint32 val);

/** *****************************************************************************************************
 * \brief This function write global reset mask.
 *
 * \verbatim
 * Syntax             : void Mcu_RstgenRgGlbResetEn(uint32 base, uint32 msk)
 *
 * Service ID[hex]    : none
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : base - rstgen base
 *                      msk - value to write
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function write global reset mask.
 * \endverbatim
 *******************************************************************************************************/
void Mcu_RstgenRgGlbResetEn(uint32 base, uint32 msk);
/** *****************************************************************************************************
 * \brief This function disable rtc ParityErrInt.
 *
 * \verbatim
 * Syntax             : void Mcu_RtcDisableRegParityErrIntEnable(uint32 base)
 *
 * Service ID[hex]    : none
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : base - rtc base
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function disable rtc ParityErrInt.
 * \endverbatim
 *******************************************************************************************************/
void Mcu_RtcDisableRegParityErrIntEnable(uint32 base);
/** *****************************************************************************************************
 * \brief This function enable rtc ParityErrInt.
 *
 * \verbatim
 * Syntax             : void Mcu_RtcEnableRegParityErrIntEnable(uint32 base)
 *
 * Service ID[hex]    : none
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : base - rtc base
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function enable rtc ParityErrInt.
 * \endverbatim
 *******************************************************************************************************/
void Mcu_RtcEnableRegParityErrIntEnable(uint32 base);
/** *****************************************************************************************************
 * \brief This function set rtc wakeup config.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_RtcWakeupConfig(Mcu_RtcAlarmType *manualPtr, const Mcu_RtcAlarmType *rtcPtr)
 *
 * Service ID[hex]    : 0x18
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : manualPtr - pointer to manual cofnig
 *                      rtcPtr - pointer to rtc cofnig
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : errorId
 *
 * Description        : This function set rtc wakeup config.
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SW_SM001
 *******************************************************************************************************/
Std_ReturnType Mcu_RtcWakeupConfig(Mcu_RtcAlarmType *manualPtr, const Mcu_RtcAlarmType *rtcPtr);
/** *****************************************************************************************************
 * \brief This function set pmu power contol config.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_PmuPowerControlSignalConfig(const Mcu_PmuStateType pmuMode,
 *                       const Mcu_PwrSigType *pmuPtr)
 *
 * Service ID[hex]    : 0x19
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : pmuMode - pmuMode
 *                      pmuPtr - pointer to pmu cofnig
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : errorId
 *
 * Description        : This function set pmu power contol config.
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SW_SM001
 *******************************************************************************************************/
Std_ReturnType Mcu_PmuPowerControlSignalConfig(const Mcu_PmuStateType pmuMode,
        const Mcu_PwrSigType *pmuPtr);
/** *****************************************************************************************************
 * \brief This function set clock gate by mode.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_CkgenXcgSetGatingByMode(uint32 base, uint32 id, uint8 lpMode, boolean en)
 *
 * Service ID[hex]    : 0xF
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : base - ckgen base
 *                      id - clock gate id
 *                      lpMode - lpMode
 *                      en - on or off
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : errorId
 *
 * Description        : This function set clock gate by mode.
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SW_SM001
 *******************************************************************************************************/
Std_ReturnType Mcu_CkgenXcgSetGatingByMode(uint32 base, uint32 id,
        uint8 lpMode, boolean en);
/** *****************************************************************************************************
 * \brief This function set seip clock.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_SetSeipClock(boolean enable)
 *
 * Service ID[hex]    : 0xD
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : enable - TRUE-turn on the clock; FALSE- turn off the clock.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : errorId
 *                      E_OK for success and E_NOT_OK for failure.
 *
 * Description        : This function set seip clock.
 *                      By default, the seip clock is turned off,
                        and when the seip task is required to run, the interface needs to be called to turn on the clock,
                        and after the task is completed, the interface needs to be called to turn off the clock.
 * \endverbatim
 * Traceability       : SWSR_MCU_004 SW_SM001
 *******************************************************************************************************/
Std_ReturnType Mcu_SetSeipClock(boolean enable);

#ifndef SEMIDRIVE_E3_LITE_SERIES
/** *****************************************************************************************************
 * \brief This function set/cancle AP domain PLL force bypass.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_ApPllBybass(boolean bypassEn)
 *
 * Service ID[hex]    : 0x20
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : bypassEn - TRUE- set pll bypass; FALSE- cancel pll bypass.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : errorId
 *                      E_OK for success and others for failure.
 *
 * Description        : This function set/cancle AP domain PLL force bypass.
 *                      Pll force bypass, pll output force to fs24M refclock
 *                      set and cancle need use in pairs.
 * \endverbatim
 * Traceability       : SWSR_MCU_004 SW_SM001
 *******************************************************************************************************/
Std_ReturnType Mcu_ApPllBybass(boolean bypassEn);
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/
#endif /* MCU_EXTEND_H */
/* End of file */
