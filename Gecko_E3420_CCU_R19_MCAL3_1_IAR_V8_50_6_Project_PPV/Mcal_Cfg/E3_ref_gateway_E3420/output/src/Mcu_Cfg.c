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
 * \file     Mcu_Cfg.c                                                                                  *
 * \brief    AUTOSAR 4.3.1 MCAL MCU Driver                                                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2024-03-08 16:29:00     <td>1.0.0                                                                *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Mcu.h"
#include "Mcu_Extend.h"
#include "Mcu_Cfg.h"
#include "BswM_Check_Action.h"

#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"
/* PRQA S 1533 EOF */
static const Mcu_ModuleType Mcu_ModuleList[] = {
VIC1,VIC2_A,VIC2_B,VIC3_A,VIC3_B,UART3,UART6,UART7,UART11,UART14,CAN3,CAN4,CAN5,CAN6,CAN7,CAN8,ETIMER1,ETIMER2,ETIMER3,ETIMER4,EPWM1,EPWM2,EPWM3,EPWM4,SPI2,SPI5,SPI7,DMA1,ADC1,ADC2,XTRG,MAILBOX,GAMA1,I2C1,I2C2,I2C3,I2C8,MODULE_END,
};


static const Mcu_ClockConfigType Mcu_ClockCfg[1] = {
    {
        &Mcu_ClkPrepareArray[0],
        &Mcu_ClkEnableArray[0],
        &Mcu_ClkDisableArray[0],
        &Mcu_DeassertArray[0],
        &Mcu_AssertArray[0],
#if (MCU_PLL_SPREAD == STD_ON)
        &Mcu_PllSpreadConfigs[0],

#endif /** #if (MCU_PLL_SPREAD == STD_ON)*/
    },
};

static const Mcu_HwIpsConfigType HwIpsCfg = {
    &Mcu_ModuleList[0],
};

/* WakeupSourceConfiguration */
static const Mcu_PmuWakeupSrcType  Mcu_RtcModeWakeupSrc = {
    PMU_WAKEUP_SRC_ENABLE,
    PMU_WAKEUP_SRC_ENABLE,
    PMU_LOGIC_OR,
    PMU_WAKEUP_SRC_ENABLE,
	PMU_WAKEUP_SRC_ENABLE
};

/* Wakeup0PinConfiguration */
static const Mcu_PmuPinCtrlType    Mcu_RtcModeWakeup0 = {
    PMU_EDGE_TYPE_FALLING,
    PMU_TRIGGER_MODE_EDGE,
    PMU_LOW_ACTIVE,

    PMU_FILTER_INVALID,
    PMU_EDGE_TYPE_INVALID,
    (uint16)0U,
    (uint16)0U,
};

/* Wakeup1PinConfiguration */
static const Mcu_PmuPinCtrlType    Mcu_RtcModeWakeup1 = {
    PMU_EDGE_TYPE_INVALID,
    PMU_TRIGGER_MODE_EDGE,
    PMU_LOW_ACTIVE,
    PMU_FILTER_BYPASS,

    PMU_EDGE_TYPE_INVALID,
    (uint16)0U,
    (uint16)0U,
};

/* BCButtonConfiguration */
static const Mcu_PmuButtonCtrlType Mcu_RtcModeBC = {
    PMU_TRIGGER_MODE_EDGE,
    PMU_TRIGGER_MODE_EDGE,
    PMU_LOW_ACTIVE,
    PMU_HIGH_ACTIVE,

    PMU_BC_WINDOW_CHECK_DISABLE,

    PMU_BC_WINDOW_CHECK_DISABLE,

    (uint8)0U,

    (uint8)0U,

    (uint8)0U,

    (uint8)0U,

    (uint8)0U,
    PMU_FILTER_BYPASS,

    PMU_EDGE_TYPE_INVALID,
    (uint16)0U,
    (uint16)0U,
};

/* RTCConfiguration */

static const Mcu_RtcAlarmType Mcu_RtcModeRtc = {
    RTC1,
    RTC_TIMER_MODE_MIN,
    ((uint16)5U),
    RTC_TIMER_MODE_INVALID,
    (uint16)0U,
};


/* pwr_ctrl0 */
static const Mcu_PmuPwrCtrlType Mcu_RtcModePwrctrl0 = {
    PMU_AUTO,
    PMU_OFF,
    (uint8)4U,
    (uint8)1U
};

/* pwr_ctrl1 */
static const Mcu_PmuPwrCtrlType Mcu_RtcModePwrctrl1 = {
    PMU_AUTO,
    PMU_OFF,
    (uint8)4U,
    (uint8)1U
};

/* pwr_ctrl2 */
static const Mcu_PmuPwrCtrlType Mcu_RtcModePwrctrl2 = {
    PMU_AUTO,
    PMU_OFF,
    (uint8)4U,
    (uint8)1U
};

/* pwr_ctrl3 */
static const Mcu_PmuPwrCtrlType Mcu_RtcModePwrctrl3 = {
    PMU_AUTO,
    PMU_OFF,
    (uint8)4U,
    (uint8)1U
};

/* PowerModeTransitionConfiguration */
static const Mcu_PwrSigType Mcu_RtcModePmu = {
    &Mcu_RtcModePwrctrl0,
    &Mcu_RtcModePwrctrl1,
    &Mcu_RtcModePwrctrl2,
    &Mcu_RtcModePwrctrl3
};

/* McuRtcModeConfig */
static const Mcu_RtcModeConfigType Mcu_RtcModecfg = {
    &Mcu_RtcModeWakeupSrc,
    &Mcu_RtcModeWakeup0,
    &Mcu_RtcModeWakeup1,
    &Mcu_RtcModeBC,
	&Mcu_RtcModeRtc,
    &Mcu_RtcModePmu
};

/* run pwr_ctrl0 */
static const Mcu_PmuPwrCtrlType Mcu_RunmodePwrctrl0 = {
    PMU_AUTO,
    PMU_ON,
    (uint8)4U,
    (uint8)1U
};

/* run pwr_ctrl1 */
static const Mcu_PmuPwrCtrlType Mcu_RunmodePwrctrl1 = {
    PMU_AUTO,
    PMU_ON,
    (uint8)4U,
    (uint8)1U
};

/* run pwr_ctrl2 */
static const Mcu_PmuPwrCtrlType Mcu_RunmodePwrctrl2 = {
    PMU_AUTO,
    PMU_ON,
    (uint8)4U,
    (uint8)1U
};

/* run pwr_ctrl3 */
static const Mcu_PmuPwrCtrlType Mcu_RunmodePwrctrl3 = {
    PMU_AUTO,
    PMU_ON,
    (uint8)4U,
    (uint8)1U
};

static const Mcu_PwrSigType Mcu_RunmodePmu = {
    &Mcu_RunmodePwrctrl0,
    &Mcu_RunmodePwrctrl1,
    &Mcu_RunmodePwrctrl2,
    &Mcu_RunmodePwrctrl3
};

/* pwr_up pwr_ctrl0 */
static const Mcu_PmuPwrCtrlType Mcu_PwrUpmodePwrctrl0 = {
    PMU_AUTO,
    PMU_ON,
    (uint8)0U,
    (uint8)0U
};

/* pwr_up pwr_ctrl1 */
static const Mcu_PmuPwrCtrlType Mcu_PwrUpmodePwrctrl1 = {
    PMU_AUTO,
    PMU_ON,
    (uint8)0U,
    (uint8)3U
};

/* pwr_up pwr_ctrl2 */
static const Mcu_PmuPwrCtrlType Mcu_PwrUpmodePwrctrl2 = {
    PMU_AUTO,
    PMU_ON,
    (uint8)4U,
    (uint8)1U
};

/* pwr_up pwr_ctrl3 */
static const Mcu_PmuPwrCtrlType Mcu_PwrUpmodePwrctrl3 = {
    PMU_AUTO,
    PMU_ON,
    (uint8)5U,
    (uint8)2U
};

static const Mcu_PwrSigType Mcu_PwrUpmodePmu = {
    &Mcu_PwrUpmodePwrctrl0,
    &Mcu_PwrUpmodePwrctrl1,
    &Mcu_PwrUpmodePwrctrl2,
    &Mcu_PwrUpmodePwrctrl3
};

static const Mcu_PmuPwrCtrlConfigType Mcu_PwrCtrlParaCfg = {
    PMU_HIGH_ACTIVE,
    PMU_HIGH_ACTIVE,
    PMU_HIGH_ACTIVE,
    PMU_HIGH_ACTIVE,
};

static const Mcu_PmuCtrlConfigType Mcu_PwrCtrlCfg = {
    &Mcu_PwrCtrlParaCfg,
    &Mcu_RunmodePmu,
    &Mcu_PwrUpmodePmu
};

static const Mcu_PowerDomType Mcu_NormalModePowerGateDom[] = {
    CR5_SP_DOM, GAMA_DOM, DOM_END,
};
extern void pvt_alarm_cb(Mcu_PvtType *devPtr, Mcu_PvtCoreIdType core,
                                    Mcu_PvtAlarmType alarm, void* arg);

const Mcu_PvtConfigType  Mcu_PvtCfg = {
    PVT_HIGH_LEVEL_ALARM,
    (float)150,
    (float)60,
    (float)60,
    pvt_alarm_cb,
};

static const Mcu_NormalModeConfigType Mcu_NormalModeCfg = {
    &Mcu_NormalModePowerGateDom[0],
};

const Mcu_ConfigType Mcu_Cfg = {

    (Mcu_RamSectionType)0U,  /* numRamSections */
    (Mcu_ClockType)1U,  /* numClkCfgs */
    NULL_PTR,
    &Mcu_ClockCfg,
    &HwIpsCfg,
    &Mcu_NormalModeCfg,
    &Mcu_RtcModecfg,
    &Mcu_PwrCtrlCfg
};

#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

#ifdef __cplusplus
};
#endif
/* End of file */
