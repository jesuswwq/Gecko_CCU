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
 * \file     McuExt_Cfg.c                                                                            *
 * \brief    AUTOSAR 4.3.1 MCAL Mcu Driver                                                             *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2024-03-08 16:29:01     <td>1.0.0                               *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Mcu_LpSmc.h"

#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

static const soc_ckgen_t sleepmode_ckgen = {
    /* XTAL24MHzConfiguration */
    SOC_CKGEN_24M_ON,
    /* RC24MHzConfiguration */
    SOC_CKGEN_24M_ON,
};

/* RTCConfiguration */
static const Mcu_RtcAlarmType sleepmode_rtc = {
    RTC1,
    RTC_TIMER_MODE_SEC,
    ((uint32)120U),
    RTC_TIMER_MODE_INVALID,
    0,
};

/* GpioConfiguration */
static const gpio_group_t sleepmode_gpio = {

    FALSE,

    FALSE,

    FALSE,

    FALSE,

    FALSE,

    FALSE,

    FALSE,

    FALSE,
};

/* WakeupSourceConfiguration */
static const soc_wkup_src_t  sleepmode_wakeupsrc = {
    SMC_WAKEUP_SRC_ENABLE,
    SMC_WAKEUP_SRC_ENABLE,
    &sleepmode_rtc,
    &sleepmode_gpio,
};

/* McuSleepIpConfig */
static const Mcu_ModuleType sleepmode_wkip_list[] = {
MODULE_END,
};

/* pwr_ctrl0 */
static const Mcu_PmuPwrCtrlType sleepmode_pwrctrl0 = {
    PMU_AUTO,
    PMU_ON,
    0,
    0
};

/* pwr_ctrl1 */
static const Mcu_PmuPwrCtrlType sleepmode_pwrctrl1 = {
    PMU_AUTO,
    PMU_ON,
    0,
    3
};

/* pwr_ctrl2 */
static const Mcu_PmuPwrCtrlType sleepmode_pwrctrl2 = {
    PMU_AUTO,
    PMU_ON,
    4,
    1
};

/* pwr_ctrl3 */
static const Mcu_PmuPwrCtrlType sleepmode_pwrctrl3 = {
    PMU_MANUAL,
    PMU_ON,
    5,
    2
};

/* PowerModeTransitionConfiguration */
static const Mcu_PwrSigType sleepmode_pmu = {
    &sleepmode_pwrctrl0,
    &sleepmode_pwrctrl1,
    &sleepmode_pwrctrl2,
    &sleepmode_pwrctrl3
};

/* SafDomainConfiguration */
static const smc_saf_domain_ctrl_t sleepmode_safdomain = {
    SMC_PD_DISABLE,
    SMC_PD_DISABLE,
    SMC_PD_DISABLE,
    SMC_PD_DISABLE,
    SMC_PD_DISABLE,
    SMC_PD_DISABLE,
    SMC_PD_DISABLE,
    SMC_PD_DISABLE,
    SMC_PD_DISABLE,
    SMC_SLP_MODE
};

/* ApDomainConfiguration */
static const smc_ap_domain_ctrl_t sleepmode_apdomain = {
    SMC_PD_DISABLE,
    SMC_PD_DISABLE,
    SMC_SLP_MODE ,
    SMC_ALIGN_YES ,
    SMC_ALIGN_YES
};

static const smc_ctrl_t sleepmode_smc = {
    &sleepmode_safdomain,
    &sleepmode_apdomain,
};

/* McuSleepModeConfig */
const Mcu_SleepModeConfigType Mcu_SleepModecfg = {
    &sleepmode_ckgen,
    &sleepmode_wakeupsrc,
    &sleepmode_wkip_list[0],
    &sleepmode_smc,
    &sleepmode_pmu
};

static const soc_ckgen_t hibernatemode_ckgen = {
    /* XTAL24MHzConfiguration */
    SOC_CKGEN_24M_ON,
    /* RC24MHzConfiguration */
    SOC_CKGEN_24M_ON,
};

/* RTCConfiguration */
static const Mcu_RtcAlarmType hibernatemode_rtc = {
    RTC1,
    RTC_TIMER_MODE_SEC,
    ((uint32)120U),
    RTC_TIMER_MODE_INVALID,
    0,
};

/* GpioConfiguration */
static const gpio_group_t hibernatemode_gpio = {

    FALSE,

    FALSE,

    FALSE,

    FALSE,

    FALSE,

    FALSE,

    FALSE,

    FALSE,
};

/* WakeupSourceConfiguration */
static const soc_wkup_src_t  hibernatemode_wakeupsrc = {
    SMC_WAKEUP_SRC_ENABLE,
    SMC_WAKEUP_SRC_ENABLE,
    &hibernatemode_rtc,
    &hibernatemode_gpio,
};

/* McuWakeupIpConfiguration */
static const Mcu_ModuleType hibernatemode_wkips_list[] = {
MODULE_END,
};

/* SafDomainConfiguration */
static const smc_saf_domain_ctrl_t hibernatemode_safdomain = {
    SMC_PD_DISABLE,
    SMC_PD_DISABLE,
    SMC_PD_DISABLE,
    SMC_PD_DISABLE,
    SMC_PD_DISABLE,
    SMC_PD_DISABLE,
    SMC_PD_DISABLE,
    SMC_PD_DISABLE,
    SMC_PD_DISABLE,
    SMC_HIB_MODE
};

/* ApDomainConfiguration */
static const smc_ap_domain_ctrl_t hibernatemode_apdomain = {
    SMC_PD_DISABLE,
    SMC_PD_DISABLE,
    SMC_HIB_MODE ,
    SMC_ALIGN_YES ,
    SMC_ALIGN_YES
};

static const smc_ctrl_t hibernatemode_smc = {
    &hibernatemode_safdomain,
    &hibernatemode_apdomain,
};

/* pwr_ctrl0 */
static const Mcu_PmuPwrCtrlType hibernatemode_pwrctrl0 = {
    PMU_AUTO,
    PMU_ON,
    0,
    0
};

/* pwr_ctrl1 */
static const Mcu_PmuPwrCtrlType hibernatemode_pwrctrl1 = {
    PMU_AUTO,
    PMU_OFF,
    0,
    3
};

/* pwr_ctrl2 */
static const Mcu_PmuPwrCtrlType hibernatemode_pwrctrl2 = {
    PMU_AUTO,
    PMU_ON,
    4,
    1
};

/* pwr_ctrl3 */
static const Mcu_PmuPwrCtrlType hibernatemode_pwrctrl3 = {
    PMU_MANUAL,
    PMU_OFF,
    5,
    2
};

/* PowerModeTransitionConfiguration */
static const Mcu_PwrSigType hibernatemode_pmu = {
    &hibernatemode_pwrctrl0,
    &hibernatemode_pwrctrl1,
    &hibernatemode_pwrctrl2,
    &hibernatemode_pwrctrl3
};

/* IramPowerConfiguration */
static const soc_iramc_pwr_mode_t hibernatemode_iramc = {
    IRAMC_RETEN2,
    IRAMC_RETEN2,
    IRAMC_RETEN2,
    IRAMC_RETEN2,
};

/* McuHibernateModeConfig */
const Mcu_HibernateModeConfigType Mcu_HibernateModecfg = {
    &hibernatemode_ckgen,
    &hibernatemode_wakeupsrc,
    &hibernatemode_wkips_list[0],
    &hibernatemode_iramc,
    &hibernatemode_pmu,
    &hibernatemode_smc,
};

#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

#ifdef __cplusplus
};
#endif
