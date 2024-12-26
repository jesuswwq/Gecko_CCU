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

/**
 * @file  Mcu_Cfg.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Mcu Driver.
 * @date 2024-01-08 18:27:14
*/

#ifdef __cplusplus
extern "C" {
#endif

#include "Mcu.h"
#include "Mcu_Cfg.h"
#include "Mcu_Soc.h"
#include "Mcu_Modules.h"

#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

static const Mcu_ModuleType module_list[] = {
VIC1,CAN7,CAN8,ETIMER1,SPI7,I2C1,MODULE_END,
};

const Mcu_RamConfigType Mcu_RamCfg[4] = {
    {1, (uint8*)(TCM_BASE + 0x10000u), 0x100u, 0x55u},
    {2, (uint8*)(TCM_BASE + 0x10200u), 0x100u, 0xaau},
};

const Mcu_ModeConfigType Mcu_ModeCfg[MCU_MAX_MODECFGS] = {
            McuConf_McuModeSettingConf_Run_Mode,
            McuConf_McuModeSettingConf_Sleep_Mode,
            McuConf_McuModeSettingConf_Hibernate_Mode,
            McuConf_McuModeSettingConf_Rtc_Mode,
};

const Mcu_ClockConfigType Mcu_ClockCfg[1] = {
    0u
};

const Mcu_HwIpsConfigType HwIpsCfg = {
    &module_list[0],
};

/* WakeupSourceConfiguration */
static const pmu_wakeup_src_t  rtcmode_wakeupsrc = {
    PMU_WAKEUP_SRC_ENABLE,
    PMU_WAKEUP_SRC_DISABLE,

    PMU_LOGIC_INVALID,
    PMU_WAKEUP_SRC_DISABLE,
    PMU_WAKEUP_SRC_ENABLE
};

/* Wakeup0PinConfiguration */
static const pmu_pin_ctrl_t    rtcmode_wakeup0 = {
    PMU_EDGE_TYPE_BOTH,
    PMU_TRIGGER_MODE_EDGE,
    PMU_HIGH_ACTIVE,

    PMU_FILTER_INVALID,
    PMU_EDGE_TYPE_INVALID,
    0,
    0,
};



/* RTCConfiguration */
static const rtc_alarm_t rtcmode_rtc = {
    RTC1,
    RTC_TIMER_MODE_SEC,
    ((uint32)10U),
    RTC_TIMER_MODE_INVALID,
    0,
};

/* pwr_ctrl0 */
static const pmu_pwr_ctrl_t rtcmode_pwrctrl0 = {
    PMU_AUTO,
    PMU_OFF,
    4,
    1
};

/* pwr_ctrl1 */
static const pmu_pwr_ctrl_t rtcmode_pwrctrl1 = {
    PMU_AUTO,
    PMU_OFF,
    4,
    1
};

/* pwr_ctrl2 */
static const pmu_pwr_ctrl_t rtcmode_pwrctrl2 = {
    PMU_AUTO,
    PMU_OFF,
    4,
    1
};

/* pwr_ctrl3 */
static const pmu_pwr_ctrl_t rtcmode_pwrctrl3 = {
    PMU_AUTO,
    PMU_OFF,
    4,
    1
};

/* PowerModeTransitionConfiguration */
static const soc_pwr_sig_t rtcmode_pmu = {
    &rtcmode_pwrctrl0,
    &rtcmode_pwrctrl1,
    &rtcmode_pwrctrl2,
    &rtcmode_pwrctrl3
};

/* McuRtcModeConfig */
const Mcu_RtcModeConfigType Mcu_RtcModecfg = {
    &rtcmode_wakeupsrc,
    &rtcmode_wakeup0,

    NULL_PTR,

    NULL_PTR,
    &rtcmode_rtc,
    &rtcmode_pmu
};

static const soc_ckgen_t sleepmode_ckgen = {
    /* 24MHzConfiguration */
    SOC_CKGEN_24M_ON,
};

/* RTCConfiguration */
static const rtc_alarm_t sleepmode_rtc = {
    RTC1,
    RTC_TIMER_MODE_SEC,
    ((uint32)10U),
    RTC_TIMER_MODE_INVALID,
    0,
};


/* WakeupSourceConfiguration */
static const soc_wkup_src_t  sleepmode_wakeupsrc = {
    SMC_WAKEUP_SRC_ENABLE,
    SMC_WAKEUP_SRC_DISABLE,
    &sleepmode_rtc,

    NULL_PTR,
};

/* McuSleepIpConfig */
static const Mcu_ModuleType sleepmode_wkip_list[] = {
MODULE_END,
};

/* pwr_ctrl0 */
static const pmu_pwr_ctrl_t sleepmode_pwrctrl0 = {
    PMU_AUTO,
    PMU_ON,
    0,
    0
};

/* pwr_ctrl1 */
static const pmu_pwr_ctrl_t sleepmode_pwrctrl1 = {
    PMU_AUTO,
    PMU_ON,
    0,
    3
};

/* pwr_ctrl2 */
static const pmu_pwr_ctrl_t sleepmode_pwrctrl2 = {
    PMU_AUTO,
    PMU_ON,
    4,
    1
};

/* pwr_ctrl3 */
static const pmu_pwr_ctrl_t sleepmode_pwrctrl3 = {
    PMU_MANUAL,
    PMU_ON,
    5,
    2
};

/* PowerModeTransitionConfiguration */
static const soc_pwr_sig_t sleepmode_pmu = {
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
    /* 24MHzConfiguration */
    SOC_CKGEN_24M_ON,
};

/* RTCConfiguration */
static const rtc_alarm_t hibernatemode_rtc = {
    RTC1,
    RTC_TIMER_MODE_SEC,
    ((uint32)10U),
    RTC_TIMER_MODE_INVALID,
    0,
};


/* WakeupSourceConfiguration */
static const soc_wkup_src_t  hibernatemode_wakeupsrc = {
    SMC_WAKEUP_SRC_ENABLE,
    SMC_WAKEUP_SRC_DISABLE,
    &hibernatemode_rtc,

    NULL_PTR,
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
static const pmu_pwr_ctrl_t hibernatemode_pwrctrl0 = {
    PMU_AUTO,
    PMU_ON,
    0,
    0
};

/* pwr_ctrl1 */
static const pmu_pwr_ctrl_t hibernatemode_pwrctrl1 = {
    PMU_AUTO,
    PMU_OFF,
    0,
    3
};

/* pwr_ctrl2 */
static const pmu_pwr_ctrl_t hibernatemode_pwrctrl2 = {
    PMU_AUTO,
    PMU_ON,
    4,
    1
};

/* pwr_ctrl3 */
static const pmu_pwr_ctrl_t hibernatemode_pwrctrl3 = {
    PMU_MANUAL,
    PMU_OFF,
    5,
    2
};

/* PowerModeTransitionConfiguration */
static const soc_pwr_sig_t hibernatemode_pmu = {
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

/* run pwr_ctrl0 */
static const pmu_pwr_ctrl_t runmode_pwrctrl0 = {
    PMU_AUTO,
    PMU_ON,
    4,
    1
};

/* run pwr_ctrl1 */
static const pmu_pwr_ctrl_t runmode_pwrctrl1 = {
    PMU_AUTO,
    PMU_ON,
    4,
    1
};

/* run pwr_ctrl2 */
static const pmu_pwr_ctrl_t runmode_pwrctrl2 = {
    PMU_AUTO,
    PMU_ON,
    4,
    1
};

/* run pwr_ctrl3 */
static const pmu_pwr_ctrl_t runmode_pwrctrl3 = {
    PMU_AUTO,
    PMU_ON,
    4,
    1
};

static const soc_pwr_sig_t runmode_pmu = {
    &runmode_pwrctrl0,
    &runmode_pwrctrl1,
    &runmode_pwrctrl2,
    &runmode_pwrctrl3
};

/* pwr_up pwr_ctrl0 */
static const pmu_pwr_ctrl_t pwr_upmode_pwrctrl0 = {
    PMU_AUTO,
    PMU_ON,
    0,
    0
};

/* pwr_up pwr_ctrl1 */
static const pmu_pwr_ctrl_t pwr_upmode_pwrctrl1 = {
    PMU_AUTO,
    PMU_ON,
    0,
    3
};

/* pwr_up pwr_ctrl2 */
static const pmu_pwr_ctrl_t pwr_upmode_pwrctrl2 = {
    PMU_AUTO,
    PMU_ON,
    4,
    1
};

/* pwr_up pwr_ctrl3 */
static const pmu_pwr_ctrl_t pwr_upmode_pwrctrl3 = {
    PMU_AUTO,
    PMU_ON,
    5,
    2
};

static const soc_pwr_sig_t pwr_upmode_pmu = {
    &pwr_upmode_pwrctrl0,
    &pwr_upmode_pwrctrl1,
    &pwr_upmode_pwrctrl2,
    &pwr_upmode_pwrctrl3
};

const pmu_pwr_ctrl_config_t Mcu_PwrCtrlParaCfg = {
    PMU_HIGH_ACTIVE,
    PMU_HIGH_ACTIVE,
    PMU_HIGH_ACTIVE,
    PMU_HIGH_ACTIVE,
};

const Mcu_PmuCtrlConfigType Mcu_PwrCtrlCfg = {
    &Mcu_PwrCtrlParaCfg,
    &runmode_pmu,
    &pwr_upmode_pmu
};

static const enum smc_safety_dom normal_mode_power_gate_dom[] = {
    CR5_SP_DOM, GAMA_DOM, DOM_END,
};
extern void pvt_alarm_cb(struct sdrv_pvt *dev);

const sdrv_pvt_config_t  Mcu_PvtCfg = {
    PVT_HIGH_LEVEL_ALARM,
    150,
    60,
    60,
    pvt_alarm_cb,
};

const Mcu_NormalModeConfigType Mcu_NormalModeCfg = {
    &normal_mode_power_gate_dom[0],
};

const Mcu_ConfigType Mcu_Cfg = {
    (Mcu_RamSectionType)2,  /* N_RamSections */
    (Mcu_ModeType)1,  /* N_Modes */
    (Mcu_ClockType)1,  /* N_ClkCfgs */
    &Mcu_RamCfg,
    &Mcu_ModeCfg,
    &Mcu_ClockCfg,
    &HwIpsCfg,
    &Mcu_NormalModeCfg,
    &Mcu_RtcModecfg,
    &Mcu_SleepModecfg,
    &Mcu_HibernateModecfg,
    &Mcu_PwrCtrlCfg
};

#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

#ifdef __cplusplus
};
#endif
