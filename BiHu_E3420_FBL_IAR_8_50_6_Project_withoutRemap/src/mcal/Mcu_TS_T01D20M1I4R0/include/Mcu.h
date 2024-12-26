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
 * @file  Mcu.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Mcu Driver.
*/

#ifndef MCU_H
#define MCU_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "Mcu_Cfg.h"
#include "Mcu_Pmu.h"
#include "Mcu_Rtc.h"
#include "Mcu_Smc.h"
#include "Mcu_Soc.h"
#include "Mcu_PvtSens.h"
#include "RegHelper.h"

#define MCU_MODULE_ID 101

#include "Mcal.h"
/* Version and Check Begin */
/* Version Info Begin */
#define MCU_H_VENDOR_ID 0x8C
#define MCU_H_AR_RELEASE_MAJOR_VERSION 4
#define MCU_H_AR_RELEASE_MINOR_VERSION 3
#define MCU_H_AR_RELEASE_REVISION_VERSION 1
#define MCU_H_SW_MAJOR_VERSION 1
#define MCU_H_SW_MINOR_VERSION 0
#define MCU_H_SW_PATCH_VERSION 0
/* Version Info End */

/* Error Code */
#define MCU_E_PARAM_CONFIG 0x0Au
#define MCU_E_PARAM_CLOCK 0x0Bu
#define MCU_E_PARAM_MODE 0x0Cu
#define MCU_E_PARAM_RAMSECTION 0x0Du
#define MCU_E_PLL_NOT_LOCKED 0x0Eu
#define MCU_E_UNINIT 0x0Fu
#define MCU_E_PARAM_POINTER 0x10u
#define MCU_E_INIT_FAILED 0x11u

typedef uint32 Mcu_ClockType;

typedef uint32 Mcu_RamSectionType;

typedef enum {
    CPU_ID_SF,
    CPU_ID_SX0,
    CPU_ID_SX1,
    CPU_ID_SP0,
    CPU_ID_SP1,
    CPU_ID_MAX
} core_e_t;

typedef enum {
    MCU_POWER_ON_RESET,  /**< @brief Power On Reset (default) */
    MCU_WATCHDOG_RESET,  /**< @brief Internal Watchdog Timer Reset */
    MCU_SW_RESET,        /**< @brief Software Reset */
    MCU_RESET_UNDEFINED, /**< @brief Reset is undefined */
    MCU_SEM_RESET,       /**< @brief SEM (function safety related) reset */
    MCU_DBG_RESET,       /**< @brief Reset by Debugger */
    MCU_VDC_RESET,       /**< @brief Reset by volate detect */
    MCU_EFUSE_RESET,     /**< @brief Reset by efuse non validate detect */
    MCU_COLD_RESET,     /**< @brief Reset by ap rstgen */
} Mcu_ResetType;

typedef uint32 Mcu_RawResetType;

/* SWS_Mcu_00250 */
typedef enum {
    MCU_PLL_LOCKED = 0x5Au,           /**< @brief PLL is locked. */
    MCU_PLL_UNLOCKED = 0xA5u,         /**< @brief PLL is unlocked. */
    MCU_PLL_STATUS_UNDEFINED = 0xF0u, /**< @brief PLL Status is unknown. */
} Mcu_PllStatusType;

typedef uint32 Mcu_RamStateType;

typedef enum {
    MCU_MODE_RUN,    /**< @brief MCU Normal running mode */
    MCU_MODE_SLP,  /**< @brief All powers excepts Sleep been disabled */
    MCU_MODE_HIB,  /**< @brief All powers excepts Hibernate been disabled */
    MCU_MODE_RTC,  /**< @brief All powers excepts RTC been disabled */
} Mcu_ModeType;

typedef uint32 Mcu_ModeConfigType;

typedef uint32 Mcu_ClockConfigType;

/* Hibernate Struct Define */
typedef struct {
    const soc_ckgen_t       *ckgen;
    const soc_wkup_src_t    *wksrc;
    const Mcu_ModuleType    *wkip;
    const soc_iramc_pwr_mode_t *iram;
    const soc_pwr_sig_t     *pmu;
    const smc_ctrl_t        *smc;
} Mcu_HibernateModeConfigType;

/* SleepMode Struct Define */
typedef struct {
    const soc_ckgen_t       *ckgen;
    const soc_wkup_src_t    *wksrc;
    const Mcu_ModuleType    *wkip;
    const smc_ctrl_t        *smc;
    const soc_pwr_sig_t     *pmu;
} Mcu_SleepModeConfigType;

/* RtcMode Struct Define */
typedef struct {
    const pmu_wakeup_src_t  *wakeupsrc;
    const pmu_pin_ctrl_t    *wakeup0;
    const pmu_pin_ctrl_t    *wakeup1;
    const pmu_button_ctrl_t *BC;
    const rtc_alarm_t       *rtc;
    const soc_pwr_sig_t     *pmu;
} Mcu_RtcModeConfigType;

typedef struct {
    const enum smc_safety_dom *dom;
} Mcu_NormalModeConfigType;

/* pum pwr_ctrl0~3 auto.polarity and override enable*/
typedef struct {
    const pmu_pwr_ctrl_config_t   *config;
    const soc_pwr_sig_t           *run_pmu;
    const soc_pwr_sig_t           *pwrup_pmu;
} Mcu_PmuCtrlConfigType;

/**
* @brief   Mcu_ConfigType [SWS_Mcu_0024]
*
* @details A pointer to such a structure is provided to the MCU initialization routines for
*          configuration.
*/
typedef struct {
    VAR(Mcu_RamSectionType, MCU_VAR) N_RamSections;
    VAR(Mcu_ModeType, MCU_VAR) N_Modes;
    VAR(Mcu_ClockType, MCU_VAR) N_ClkCfgs;
    CONST(Mcu_RamConfigType, MCU_CONST) (*pRamCfgs)[MCU_MAX_RAMCFGS];
    CONST(Mcu_ModeConfigType, MCU_CONST) (*pModeCfgs)[MCU_MAX_MODECFGS];
    CONST(Mcu_ClockConfigType, MCU_CONST) (*pClkCfgs)[MCU_MAX_CLKCFGS];
    P2CONST(Mcu_HwIpsConfigType, MCU_VAR, MCU_APPL_CONST) pHwIpsCfg;
    P2CONST(Mcu_NormalModeConfigType, MCU_VAR, MCU_APPL_CONST) pNormalModeCfg;
    P2CONST(Mcu_RtcModeConfigType, MCU_VAR, MCU_APPL_CONST) pRTCModeCfg;
    P2CONST(Mcu_SleepModeConfigType, MCU_VAR, MCU_APPL_CONST) pSleepModeCfg;
    P2CONST(Mcu_HibernateModeConfigType, MCU_VAR, MCU_APPL_CONST) pHibernateModeCfg;
    P2CONST(Mcu_PmuCtrlConfigType, MCU_VAR, MCU_CONST) pwrCtrlCfg;
} Mcu_ConfigType;

#if defined(CFG_MULTI_CORE_OS)
extern const Mcu_ConfigType Mcu_Cfg[];
#else
extern const Mcu_ConfigType Mcu_Cfg;
#endif

/**
* @brief   Mcu init routine.
* @details This function does some soc specific jobs, including #1. vector table remap,
*          #2. release resets of modules which been provisioned in Mcu configuration data.
*          #3. some other actions.
* @param[in]   pConfigPtr  pointing to configuration data of Mcu.
* @return  None.
*/
FUNC(void, MCU_CODE)
Mcu_Init(P2CONST(Mcu_ConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr);

/**
* @brief Initialize clocks which configuration been provided in Mcu configuration structure.
* @details Clock configurations recommended by Semidrive will be setup in this function.
*          Customer just needs to spefic the module list, and this function will setup
*          the root clock of the modules.
* @param[in]   selection of clock settings. Will be ignored in this implementation.
* @return E_OK for success and others for failure.
*/
FUNC(Std_ReturnType, MCU_CODE)
Mcu_InitClock(VAR(Mcu_ClockType, AUTOMATIC) ClockSetting);

/**
* @brief Initialize Ram Section.
* @details There is HW mechnism to Zeroize IRAMs, thus by default, all IRAMs are cleared.
*          There is ECC support in TCM thus SW shall not read it unless it had been written. So
*          we can not noinit sections.
* @param[in]   RamSection  idx of ram section to be initialized.
* @return      E_OK for success and E_NOT_OK for failure.
*/
FUNC(Std_ReturnType, MCU_CODE)
Mcu_InitRamSection(VAR(Mcu_RamSectionType, AUTOMATIC) RamSection);

/**
* @brief Distribute PLL clock to clock system which feed peripherals.
* @details Thanks to Boot ROM, PLL had been enabled and clocks had distrubted
        to ckgen already. Thus this function do nothing.
* @return  E_OK.
*/
FUNC(Std_ReturnType, MCU_CODE)
Mcu_DistributePllClock(VAR(void, AUTOMATIC));

/**
* @brief   Get the PLL status.
* @return  The status of the PLL. There are two PLLs on safety domain. This function
*          returns the status of the two PLLs.
*/
FUNC(Mcu_PllStatusType, MCU_CODE)
Mcu_GetPllStatus(VAR(void, AUTOMATIC));

/**
* @brief   Get the reason of last reset.
* @detials Besides the reasons defined by AutoSAR spec,  MCU_SEM_RESET/MCU_DBG_RESET
*          also supported here.
* @return  The type of last reset.
*/
FUNC(Mcu_ResetType, MCU_CODE)
Mcu_GetResetReason(VAR(void, AUTOMATIC));

/**
* @brief   Get the raw value of reset status register.
* @return  Value of raw reset status register.
*/
FUNC(Mcu_RawResetType, MCU_CODE)
Mcu_GetResetRawValue(VAR(void, AUTOMATIC));

/**
* @brief   Perform reset to Mcu.
* @details It will reset safety domain (ap domain will be reset also).
*          No impact to rtc domain.
*/
FUNC(void, MCU_CODE)
Mcu_PerformReset(VAR(void, AUTOMATIC));

/**
* @brief   Set the power mode of MCU.
* @details So far, only Normal and Deepsleep (RTC power only) mode supported.
*          Once been set into Deepsleep mode, only wakeup (rtc1/2 and
*          wake_pin0/1) can wakeup the Mcu.

* @param[in]   McuMode     The power mode to switch to.
*/
FUNC(void, MCU_CODE)
Mcu_SetMode(VAR(Mcu_ModeType, AUTOMATIC) McuMode);

#if (MCU_GET_RAM_STATE_API == STD_ON)
FUNC(Mcu_RamStateType, MCU_CODE)
Mcu_GetRamState(VAR(void, AUTOMATIC));
#endif /* (MCU_GET_RAM_STATE_API == STD_ON) */

/**
* @brief   Get version information of this driver.
*/
FUNC(void, MCU_CODE)
Mcu_GetVersionInfo(
    P2VAR(Std_VersionInfoType, AUTOMATIC, MCU_APPL_DATA) pVersionInfo);

#if (STD_ON == MCU_APDOMAIN_POWERDOWN)
FUNC(void, MCU_CODE) Mcu_APDomainPowerdown(VAR(void, AUTOMATIC));
#endif
/* Non-AutoSAR APIs */
#if (MCU_PERFORM_AP_DOMAIN_RESET_API == STD_ON)
/**
* @brief   Reset Ap domain, triggered by Safety image.
*/
FUNC(void, MCU_CODE)
Mcu_PerformApDomainReset(VAR(void, AUTOMATIC));
#endif /* (MCU_PERFORM_AP_DOMAIN_RESET_API == STD_ON) */
/**
 * @brief   GetCpuId.
 *
 * @return
 *  MB_CPU_CR5_SF =  0
 *  MB_CPU_CR5_SP0 = 1
 *  MB_CPU_CR5_SP1 = 2
 *  MB_CPU_CR5_SX0 = 3
 *  MB_CPU_CR5_SX1 = 4
*/
uint32 arch_get_cpuid(void);
/**
 * @brief   GetTcmSize.
 *
 * return ATCM + BTCM Size
*/
uint32 Mcu_GetTcmSize(void);

uint32 Mcu_GetTcmBase(void);

/* 0x101a bit7~4 major bit3~0 minor */
static inline uint8 Mcu_GetChipVersion(void)
{
#ifdef SEMIDRIVE_E3_SERIES
    static uint8 version = 0xFFu;

    if (version == 0xFFu) {
        version = (uint8)(readl(APB_EFUSEC_BASE + 0x1018) >> 16u);
    } else {

    }

    return version;
#elif defined(SEMIDRIVE_E3_LITE_SERIES)
#define V_MINOR_MASK 0x000f0000
#define V_MINOR_POS 16
#define V_MINOR_L(V)  ((V)-1)
    /*
        e3l .0   0x01 @0x101a
        e3l .1   0x02 @0x101a
    */
    static uint8 version = 0xffu;

    if (version == 0xffu) {
        version = (uint8)((readl(APB_EFUSEC_BASE + 0x1018) & V_MINOR_MASK) >> V_MINOR_POS);
    }

    return V_MINOR_L(version);
#else
    return 1;
#endif
}

/**
* @brief   Mcu init low power Hibernate routine.
* @details This function does some low power Hibernate confirure jobs, including
*          #1. mask smc irq.
*          #2. ckgen configure.
*          #3. rstgen configure.
*          #4. pwr_on configure.
*          #5. iram configure.
*          #6. wake up sourece configure.
*          #7. saf domain, ap domain and SOC lowpower configure.
* @param[in]   HibernateModeConfigPtr  pointing to configuration data of Hibernate mode.
* @return  None.
*/
FUNC(void, MCU_CODE) Mcu_LowPowerHibernateConfig(
    P2CONST(Mcu_HibernateModeConfigType, AUTOMATIC, MCU_APPL_CONST) HibernateModeConfigPtr
);

/**
* @brief   Mcu init low power Sleep routine.
* @details This function does some low power Sleep confirure jobs, including
*          #1. mask smc irq.
*          #2. ckgen configure.
*          #3. rstgen configure.
*          #4. wake up sourece configure.
*          #5. saf domain, ap domain and SOC lowpower configure.
* @param[in]   SleepModeConfigPtr  pointing to configuration data of Sleep mode.
* @return  None.
*/
FUNC(void, MCU_CODE) Mcu_LowPowerSleepConfig(
    P2CONST(Mcu_SleepModeConfigType, AUTOMATIC, MCU_APPL_CONST) SleepModeConfigPtr
);

/**
* @brief   Mcu init low power Rtc routine.
* @details This function does some low power Rtc confirure jobs, including
*          #1. wake up sourece configure.
* @param[in]   RtcModeConfigPtr  pointing to configuration data of Rtc mode.
* @return  None.
*/
FUNC(void, MCU_CODE) Mcu_LowPowerRtcConfig(
    P2CONST(Mcu_RtcModeConfigType, AUTOMATIC, MCU_APPL_CONST) RtcModeConfigPtr
);

/**
* @brief   Mcu init low power routine.
* @details This function does some low power confirure jobs, including
*          #1. Rtc mode configure.
*          #1. Sleep mode configure.
*          #1. Hibernate mode configure.
* @param[in]   RtcModeConfigPtr  pointing to configuration data of Mcu.
* @return  None.
*/
FUNC(void, MCU_CODE) Mcu_LowPowerInit(
    P2CONST(Mcu_ConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr
);

/**
* @brief   Mcu pmu pwr_ctrl software control enable.
* @details This function is used for user sw control pwr_ctrl0~3.
* @param[in]   Id  pwr_ctrl0~3 index.
* @param[in]   Select  NOUSE/SELECT sw override enable.
* @return  None.
*/
FUNC(void, MCU_CODE) Mcu_SetPwrCtrlOverrideEnable(
    CONST(pmu_pwrctrl_id_e, MCU_APPL_CONST) Id,
    CONST(pmu_pwrctrl_select_e, MCU_APPL_CONST) Select
);

/**
* @brief   Mcu pmu pwr_ctrl software control.
* @details This function is used for user sw control pwr_ctrl0~3.
* @param[in]   Id  pwr_ctrl0~3 index.
* @param[in]   Value  HIGH/LOW level.
* @return  None.
*/
FUNC(void, MCU_CODE) Mcu_SetPwrCtrlOverrideValue(
    CONST(pmu_pwrctrl_id_e, MCU_APPL_CONST) Id,
    CONST(pmu_polarity_e, MCU_APPL_CONST) Value
);

/**
* @brief   Mcu pmu muanual set low power sleep time.
* @details This function is used for user sw control sleep time.
*          This function will only take effect once!!!
* @param[in]   McuMode  The power mode to switch to.
* @param[in]   Rtc_SleepTime  RTC sleep parameter.
* @return  None.
*/
FUNC(void, MCU_CODE) Mcu_SetPwrSleepTime(
    VAR(Mcu_ModeType, AUTOMATIC) McuMode,
    CONST(rtc_alarm_t, MCU_APPL_CONST) Rtc_SleepTime
);

#ifdef __cplusplus
}
#endif

#endif /* !defined(_MCU_H_) */
