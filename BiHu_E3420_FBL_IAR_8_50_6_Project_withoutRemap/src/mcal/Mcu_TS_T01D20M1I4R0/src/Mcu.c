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
 * @file  Mcu.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Mcu Driver.
*/

#ifdef __cplusplus
extern "C" {
#endif

#include <Mcal.h>
#include <Mcu.h>
#include <RegBase.h>
#include <RegHelper.h>
#include "Mcu_Ckgen.h"
#include "Mcu_Clkgate.h"
#include "Mcu_ScrBits.h"
#include "Mcu_Soc.h"
#include "Ckgen_Reg.h"
#include "arch.h"
#include "Compiler.h"
#include "e3_clk.h"
#include "Mcu_Xtal.h"
#include "taishan_rstgen.h"
#include "taishan_reset_drv.h"
#include "Mcu_Reset.h"
#include "Mcu_UserCallouts.h"
#include "e3_pll_drv.h"
#include "irq.h"
#include "cdefs.h"
#include "Mcu_Dcdc_Ldo.h"

/* Version and Check Begin */
/* Version Info Begin */
#define MCU_C_VENDOR_ID    0x8C
#define MCU_C_AR_RELEASE_MAJOR_VERSION    4
#define MCU_C_AR_RELEASE_MINOR_VERSION    3
#define MCU_C_AR_RELEASE_REVISION_VERSION 1
#define MCU_C_SW_MAJOR_VERSION    1
#define MCU_C_SW_MINOR_VERSION    0
#define MCU_C_SW_PATCH_VERSION    0
/* Version Info End */

#define MCU_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

P2CONST(Mcu_ConfigType, MCU_VAR, MCU_APPL_CONST) Mcu_CfgPtr _SECTION(.dma_buffer);
VAR(rtc_alarm_t, AUTOMATIC) Mcu_PwrRtcSleepTime[MCU_MODE_RTC + 1];

#define MCU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

extern reset_ctl_t g_rstgen_saf;
extern reset_ctl_t g_rstgen_ap;
extern const clk_node_t *clk_prepare_array[];
extern const clk_node_t *clk_enable_array[];
extern const clk_node_t *clk_disable_array[];
extern const pll_spread_config_t pll_spread_configs[];
extern const reset_sig_t *xspi_reset_array[];
extern const reset_sig_t *deassert_array[];
extern const reset_sig_t *assert_array[];
extern taishan_reset_ctl_t taishan_rstgen_sf_dev;
extern taishan_reset_ctl_t taishan_rstgen_ap_dev;
extern uint32 Mcu_GetClkEnableArraySize(void);
extern uint32 Mcu_GetClkPrepareArraySize(void);
extern uint32 Mcu_GetRstgenArraySize(void);
extern uint32 arch_get_cur_pc(void);
extern uint32 Mcu_GetDeassertArraySize(void);
extern uint32 Mcu_GetAssertArraySize(void);
extern uint32 Mcu_GetXspiResetArraySize(void);
extern uint32 Mcu_GetClkDisableArraySize(void);
extern uint32 Mcu_GetPllSpreadArraySize(void);

/**
* @brief   Mcu assert not used mudule and power switch sx sp.
* @details This function is used for assert not used mudule.
*          This function is used for power switch not exist core;
* @return  None.
*/
LOCAL_INLINE void Mcu_AssertAndPowerSwitch(void)
{
    const Mcu_NormalModeConfigType *pNormalCfg = Mcu_CfgPtr->pNormalModeCfg;
    const enum smc_safety_dom *pDom = pNormalCfg->dom;

    /* assert unused module */
    for (uint32 i = 0; i < Mcu_GetAssertArraySize(); i++) {
        reset_ctl_assert((reset_sig_t *)assert_array[i]);
    }

    /* power gate unused memory for different part */
    if (pDom != NULL_PTR) {
        for (; *pDom != DOM_END; pDom++) {
            if (*pDom == AP_DOM) {
                continue;
            }

            soc_power_gate(*pDom);
        }
    }
}

/**
 [SWS_Mcu_00026]: The function Mcu_Init shall initialize the MCU module, i.e.
 make the configuration settings for power down, clock and RAM sections visible
 within the MCU module. ( SRS_BSW_00101, SRS_BSW_00406)
 */
FUNC(void, MCU_CODE) Mcu_Init
(
    P2CONST(Mcu_ConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr
)
{
    if (NULL_PTR != pConfigPtr) {

        Mcu_CfgPtr = pConfigPtr;
        const Mcu_HwIpsConfigType *pHwIpsCfg = pConfigPtr->pHwIpsCfg;
        const Mcu_ModuleType *pModule = pHwIpsCfg->modules;
        Mcu_DCDC_MODE_SET();
        taishan_reset_init(&g_rstgen_saf, &taishan_rstgen_sf_dev);
#ifndef SEMIDRIVE_E3_LITE_SERIES
        taishan_reset_init(&g_rstgen_ap, &taishan_rstgen_ap_dev);
#endif

        for (uint32 i = 0; i < Mcu_GetDeassertArraySize(); i++) {
            reset_ctl_reset((reset_sig_t *)deassert_array[i]);
        }
#if (!defined PROJECT_APP)
        if (arch_get_cur_pc() < 0x10000000 ) {
            for (uint32 i = 0; i < Mcu_GetXspiResetArraySize(); i++) {
                reset_ctl_reset((reset_sig_t *)xspi_reset_array[i]);
            }
        }
#endif
        soc_reset_btm();

        /* Release 'reset' of every modules */
        for (; *pModule != MODULE_END; pModule++) {
            soc_reset_latent_ip(*pModule);
            soc_reset_adc(*pModule);
        }

#if (MCU_DCDC_POWERDOWN == STD_ON)
        Mcu_PmuDcdcEn(FALSE);
#endif

#if (MCU_LDO_POWERDOWN == STD_ON)
        Mcu_PmuLdoEn(FALSE);
#endif

        Mcu_LowPowerInit(pConfigPtr);
    }
}

FUNC(Std_ReturnType, MCU_CODE) Mcu_InitClock(
    VAR(Mcu_ClockType, AUTOMATIC) ClockSetting
)
{
    /* lpvd power on */
    if (LPVD_POWER_DOWN == Mcu_GetLpvdPowerStatus()) {
        Mcu_LpvdPowerSwitch(LPVD_POWER_ON);
    }

    /*32k xtal enable */
    if (XTAL_DISABLE == Mcu_GetXtal32KStatus()) {
        Mcu_Xtal32KEnable(XTAL_ENABLE);
    }

    /* Enable used clock. */
    for (uint32 i = 0; i <  Mcu_GetClkEnableArraySize(); i++) {
        clk_enable((clk_node_t *)clk_enable_array[i]);
    }

    /* Prepare clock tree. */
    for (uint32 i = 0; i < Mcu_GetClkPrepareArraySize(); i++) {
        clk_prepare((clk_node_t *)clk_prepare_array[i]);
    }

    /* disable unused clock */
    for (uint32 i = 0; i <  Mcu_GetClkDisableArraySize(); i++) {
        clk_disable((clk_node_t *)clk_disable_array[i]);
    }

#if (MCU_PLL_SPREAD == STD_ON)

    for (uint32 i = 0; i <  Mcu_GetPllSpreadArraySize(); i++)  {
        config_pll_spread(&pll_spread_configs[i]);
    }

#endif

    Mcu_AssertAndPowerSwitch();

    return E_OK;
}

FUNC(Std_ReturnType, MCU_CODE) Mcu_InitRamSection(
    VAR(Mcu_RamSectionType, AUTOMATIC) RamSection
)
{
    const Mcu_RamConfigType *pCfg = Mcu_CfgPtr->pRamCfgs[0];
    uint32 i = 0;

    for (; i < Mcu_CfgPtr->N_RamSections; i++) {
        if (RamSection == pCfg->Idx) {
            break;
        }

        pCfg++;
    }

    if (i < Mcu_CfgPtr->N_RamSections) {
        /* TCM has HW ecc machnism thus any read or non-64bit write to non-init TCM
         * will casue a data abort. If Section sit in TCM, it is application's duty
         * to make sure this section is 8-bytes aligned (start and size).
         */
        if ((((unsigned long)pCfg->Base <= (uint32)TCM_END)
             || (((unsigned long)pCfg->Base + pCfg->Size) <= (uint32)TCM_END))
            && ((0u != (unsigned long)pCfg->Base % 8u) || (0u != pCfg->Size % 8u))) {
            return E_NOT_OK;
        }

        uint8 *pRam = pCfg->Base;
        uint32 sz = pCfg->Size;

        if ((0u == (unsigned long)pRam % 8u) && (sz >= 8u)) {
             /* PRQA S 3305 2 */
            uint64 *p = (uint64 *)pRam;
            register uint64 v = pCfg->DefaultValue;
            v |= (v << 8);
            v |= (v << 16);
            v |= (v << 32);

            while (sz / 8u > 0u) {
                /* To make sure the write is 64 bits, otherwise data abort raised
                 * if writing to uninit TCM where ECC enabled there.
                 */
                DWORD_WR(v, p);
                p++;
                sz -= 8u;
            }

            pRam = (uint8 *)p;
        }

        if ((0u == (unsigned long)pRam % 4u) && (sz >= 4u)) {
            /* PRQA S 3305 2 */
            uint32 *p = (uint32 *)pRam;
            uint32 v = pCfg->DefaultValue;
            v |= (v << 8);
            v |= (v << 16);

            while (sz / 4u > 0u) {
                *p++ = v;
                sz -= 4u;
            }

            pRam = (uint8 *)p;
        }

        uint8 *p = (uint8 *)pRam;

        for (i = 0; i < sz; i++) {
            *p++ = pCfg->DefaultValue;
        }
    } else {
        return E_NOT_OK;
    }

    return E_OK;
}
#ifdef MCU_CKGEN_RESERVED_FUNCs
FUNC(Std_ReturnType, MCU_CODE) Mcu_DistributePllClock(
    VAR(void, AUTOMATIC)
)
{
    /* Thanks to Boot ROM, PLLs had been distributed to SOC already. Nothing to do here */
    return E_OK;
}

FUNC(Mcu_PllStatusType, MCU_CODE) Mcu_GetPllStatus(
    VAR(void, AUTOMATIC)
)
{
    return MCU_PLL_LOCKED;
}
#endif
FUNC(Mcu_ResetType, MCU_CODE) Mcu_GetResetReason(
    VAR(void, AUTOMATIC)
)
{
    VAR(Mcu_ResetType, AUTOMATIC) ret = MCU_RESET_UNDEFINED;
    VAR(uint32, AUTOMATIC) v = readl(APB_RSTGEN_SF_BASE + GLOBAL_RESET_STA_OFF);

    if (0u == v) {
        ret = MCU_POWER_ON_RESET;
    } else if ((v & (0x01u << 2)) > 0U) {  /* sem reset */
        ret = MCU_SEM_RESET;
    } else if ((v & (0x01u << 3)) > 0U) {  /* voltage detect reset */
        ret = MCU_VDC_RESET;
    } else if ((v & (0x01u << 4)) > 0U) {  /* efuse non valiadate reset */
        ret = MCU_EFUSE_RESET;
    } else if ((v & (0x01u << 5)) > 0U) {  /* cold reset */
        ret = MCU_COLD_RESET;
    } else if ((v & (0x01u << 11)) > 0U) {  /* sf_sw_glb reset */
        ret = MCU_SW_RESET;
    } else if ((v & (0x7dfu << 14)) > 0U) {
        /* bit[24:14] wdt reset:
         * bit[24:23]:wdt6
         * bit[22:21]:wdt4
         * bit[20]:wdt2
         * bit[18:17]:wdt5
         * bit[16:15]:wdt3
         * bit14:wdt1
         */
        ret = MCU_WATCHDOG_RESET;
    } else {
        ret = MCU_RESET_UNDEFINED;
    }

    return ret;
}

FUNC(Mcu_RawResetType, MCU_CODE) Mcu_GetResetRawValue
(VAR(void, AUTOMATIC)
)
{
    return readl(APB_RSTGEN_SF_BASE + GLOBAL_RESET_STA_OFF);
}

FUNC(void, MCU_CODE) Mcu_PerformReset(
    VAR(void, AUTOMATIC)
)
{
    reset_ctl_global_reset(&rstctl_glb);
}

FUNC(void, MCU_CODE) Mcu_SetMode(
    VAR(Mcu_ModeType, AUTOMATIC) McuMode
)
{
    if (NULL_PTR != Mcu_CfgPtr) {
        /* Enter rtc mode process */
        if ((MCU_MODE_RTC == McuMode) && (NULL_PTR != Mcu_CfgPtr->pRTCModeCfg)) {

            /* Rtc wakeup Config*/
            if ((NULL_PTR != Mcu_CfgPtr->pRTCModeCfg->rtc)
                && (NULL_PTR != Mcu_CfgPtr->pRTCModeCfg->wakeupsrc)) {
                Mcu_RtcWakeupConfig(&Mcu_PwrRtcSleepTime[MCU_MODE_RTC], Mcu_CfgPtr->pRTCModeCfg->rtc,
                                    Mcu_CfgPtr->pRTCModeCfg->wakeupsrc->rtcsrc);
            }

            /* disable RTC parity error interrupt status, because low power need disable RTC pclk */
            Mcu_RtcDisableRegParityErrIntEnable(APB_RTC1_BASE);
            Mcu_RtcDisableRegParityErrIntEnable(APB_RTC2_BASE);

            /*LPVD_CTRL:cut down power resume */
            Mcu_LpvdPowerSwitch(LPVD_POWER_DOWN);

            /* Set to enter rtc mode */
            Mcu_PmuPwrdown();

            while (1) {
                EXECUTE_WAIT();
            }
        }
        /* Enter sleep mode process */
        else if ((MCU_MODE_SLP == McuMode) && (NULL_PTR != Mcu_CfgPtr->pSleepModeCfg)) {

            if (Mcu_GetCoreID() == CPU_ID_SF) {

                /*  switch clock to 24m  */
                Mcu_SmcSwitchClockTo24Mhz();

                /* rtc wakeup config*/
                if ((NULL_PTR != Mcu_CfgPtr->pSleepModeCfg->wksrc)
                    && (NULL_PTR != Mcu_CfgPtr->pSleepModeCfg->wksrc->rtc)) {
                    Mcu_RtcWakeupConfig(&Mcu_PwrRtcSleepTime[MCU_MODE_SLP], Mcu_CfgPtr->pSleepModeCfg->wksrc->rtc,
                                        Mcu_CfgPtr->pSleepModeCfg->wksrc->rtcsrc);
                }

                /* saf domain, ap domain and SoC lowpower Config*/
                if ((NULL_PTR != Mcu_CfgPtr->pSleepModeCfg->smc)
                    && (NULL_PTR != Mcu_CfgPtr->pSleepModeCfg->ckgen)) {
                    Mcu_SoCEnterLpConfig(Mcu_CfgPtr->pSleepModeCfg->smc, MCU_MODE_SLP,
                                         Mcu_CfgPtr->pSleepModeCfg->ckgen->onoff);
                }

                /* disable RTC parity error interrupt status, because low power need disable RTC pclk */
                Mcu_RtcDisableRegParityErrIntEnable(APB_RTC1_BASE);
                Mcu_RtcDisableRegParityErrIntEnable(APB_RTC2_BASE);

                /* Start Enter Wfi*/
                Mcu_ActionToWfi(McuMode);

                /* check saf/ap/pmu swm status */
                Mcu_SmcSwmCheckAfterExitWfi();

                /* store RTC parity error interrupt status */
                Mcu_RtcEnableRegParityErrIntEnable(APB_RTC1_BASE);
                Mcu_RtcEnableRegParityErrIntEnable(APB_RTC2_BASE);

                /* store cpu clock */
                Mcu_SmcSwitchClockToNormal();

            } else {
                /* Save the current CPU CPSR.I to avoid the failure to enter low power due
                   to exiting the wfi state due to interruption */
                IRQ_SAVE
                /* Start Enter Wfi*/
                Mcu_ActionToWfi(McuMode);
                /* Resume CPU CPSR.I */
                IRQ_RESTORE
            }

        }
        /* Enter hibernate mode process */
        else if ((MCU_MODE_HIB == McuMode) && (NULL_PTR != Mcu_CfgPtr->pHibernateModeCfg)) {

            if (Mcu_GetCoreID() == CPU_ID_SF) {

                /*  switch clock to 24m  */
                Mcu_SmcSwitchClockTo24Mhz();

                /* rtc wakeup config*/
                if ((NULL_PTR != Mcu_CfgPtr->pHibernateModeCfg->wksrc)
                    && (NULL_PTR != Mcu_CfgPtr->pHibernateModeCfg->wksrc->rtc)) {
                    Mcu_RtcWakeupConfig(&Mcu_PwrRtcSleepTime[MCU_MODE_HIB], Mcu_CfgPtr->pHibernateModeCfg->wksrc->rtc,
                                        Mcu_CfgPtr->pHibernateModeCfg->wksrc->rtcsrc);
                }

                /* saf domain, ap domain and SoC lowpower Config*/
                if ((NULL_PTR != Mcu_CfgPtr->pHibernateModeCfg->smc)
                    && (NULL_PTR != Mcu_CfgPtr->pHibernateModeCfg->ckgen)) {
                    Mcu_SoCEnterLpConfig(Mcu_CfgPtr->pHibernateModeCfg->smc, MCU_MODE_HIB,
                                         Mcu_CfgPtr->pHibernateModeCfg->ckgen->onoff);
                }

                /* disable RTC parity error interrupt status, because low power need disable RTC pclk */
                Mcu_RtcDisableRegParityErrIntEnable(APB_RTC1_BASE);
                Mcu_RtcDisableRegParityErrIntEnable(APB_RTC2_BASE);

                /* usr callout: suspend process for enter hibernate mode */
                Mcu_SuspendUserCallouts(McuMode);

                /* Start Enter Wfi*/
                Mcu_ActionToWfi(McuMode);

                /* check saf/ap/pmu swm status */
                Mcu_SmcSwmCheckAfterExitWfi();

                /* usr callout: resume process for wakeup from hibernate mode */
                Mcu_ResumeUserCallouts(McuMode);

                /* store RTC parity error interrupt status */
                Mcu_RtcEnableRegParityErrIntEnable(APB_RTC1_BASE);
                Mcu_RtcEnableRegParityErrIntEnable(APB_RTC2_BASE);

                /* store cpu clock */
                Mcu_SmcSwitchClockToNormal();

            } else {
                /* Save the current CPU CPSR.I to avoid the failure to enter low power due
                   to exiting the wfi state due to interruption */
                IRQ_SAVE
                /* Start Enter Wfi*/
                Mcu_ActionToWfi(McuMode);
                /* Resume CPU CPSR.I */
                IRQ_RESTORE
            }

        } else {

        }
    }
}

FUNC(void, MCU_CODE) Mcu_LowPowerRtcConfig(
    P2CONST(Mcu_RtcModeConfigType, AUTOMATIC, MCU_APPL_CONST) RtcModeConfigPtr
)
{
    if ((NULL_PTR != RtcModeConfigPtr) && (NULL_PTR != RtcModeConfigPtr->wakeupsrc)) {

        /* BC button wakeup Config */
        if (NULL_PTR != RtcModeConfigPtr->BC) {
            Mcu_BCButtonWakeupConfig(RtcModeConfigPtr->BC, RtcModeConfigPtr->wakeupsrc->BCButtonsrc);
        }

        /* wakeup0 pin wakeup Config*/
        if (NULL_PTR != RtcModeConfigPtr->wakeup0) {
            Mcu_Wakep0PinWakeupConfig(RtcModeConfigPtr->wakeup0, RtcModeConfigPtr->wakeupsrc->wakeup0src);
        }

        /* wakeup1 pin wakeup Config*/
        if (NULL_PTR != RtcModeConfigPtr->wakeup1) {
            Mcu_Wakep1PinWakeupConfig(RtcModeConfigPtr->wakeup1, RtcModeConfigPtr->wakeupsrc->wakeup1src);
        }

        /* rtcmode wakup source enable config*/
        Mcu_PmuWakeupSourceEnableConfig(RtcModeConfigPtr->wakeupsrc);

        /* power control signal: pwr_ctrl0~3 configuration */
        if (NULL_PTR != RtcModeConfigPtr->pmu) {
            Mcu_PmuPowerControlSignalConfig(PMU_STATE_RTC, RtcModeConfigPtr->pmu);
        }

        /* ALARM: When wakeup from rtc mode,These pin need to be reconfig to restore normal mode */
        /* PRQA S 2812 2 */
        Mcu_RtcpadPinMuxConfig(RtcModeConfigPtr->wakeup0->polarity, RtcModeConfigPtr->wakeup1->polarity,
                               RtcModeConfigPtr->BC->onpol);
    }
}

FUNC(void, MCU_CODE) Mcu_LowPowerSleepConfig(
    P2CONST(Mcu_SleepModeConfigType, AUTOMATIC, MCU_APPL_CONST) SleepModeConfigPtr
)
{
    const Mcu_ModuleType *pModule = NULL_PTR;

    if ((NULL_PTR != SleepModeConfigPtr) && (NULL_PTR != SleepModeConfigPtr->wkip)) {

        pModule = SleepModeConfigPtr->wkip;

        /* ckgen configuration */
        if (NULL_PTR != SleepModeConfigPtr->ckgen) {
            Mcu_CkgenClockDisableConfig(pModule, MCU_MODE_SLP, SleepModeConfigPtr->ckgen->onoff);
        }

        /* rstgen configuration */
        Mcu_RstgenResetAssertConfig(pModule, RESET_LP_SLEEP);

        /* power control signal: pwr_ctrl0~3 configuration */
        if (NULL_PTR != SleepModeConfigPtr->pmu) {
            Mcu_PmuPowerControlSignalConfig(PMU_STATE_SLEEP, SleepModeConfigPtr->pmu);
        }

        /* wakeup source configuration */
	/* PRQA S 2995 2*/
        if ((NULL_PTR != SleepModeConfigPtr->wksrc) && (NULL_PTR != SleepModeConfigPtr->ckgen)
            && (NULL_PTR != SleepModeConfigPtr->wkip)) {
            Mcu_WakeupSourceEnableConfig(SleepModeConfigPtr->wksrc, SleepModeConfigPtr->wkip,
                                         SleepModeConfigPtr->ckgen->onoff);
        }
    }
}

FUNC(void, MCU_CODE) Mcu_LowPowerHibernateConfig(
    P2CONST(Mcu_HibernateModeConfigType, AUTOMATIC, MCU_APPL_CONST) HibernateModeConfigPtr
)
{
    const Mcu_ModuleType *pModule = NULL_PTR;

    if ((NULL_PTR != HibernateModeConfigPtr) && (NULL_PTR != HibernateModeConfigPtr->wkip)) {
        pModule = HibernateModeConfigPtr->wkip;

        /* ckgen configuration */
        if (NULL_PTR != HibernateModeConfigPtr->ckgen) {
            Mcu_CkgenClockDisableConfig(pModule, MCU_MODE_HIB, HibernateModeConfigPtr->ckgen->onoff);
        }

        /* rstgen configuration */
        Mcu_RstgenResetAssertConfig(pModule, RESET_LP_HIB);

        /* power control signal: pwr_ctrl0~3 configuration */
        if (NULL_PTR != HibernateModeConfigPtr->pmu) {
            Mcu_PmuPowerControlSignalConfig(PMU_STATE_HIBERNATE, HibernateModeConfigPtr->pmu);
        }

        /* iram1/2/3/4 power gating mode configuration */
        if (NULL_PTR != HibernateModeConfigPtr->iram) {
            Mcu_IramPowerConfig(HibernateModeConfigPtr->iram);
        }

        /* wakeup source configuration */
        /* PRQA S 2995 2*/
        if ((NULL_PTR != HibernateModeConfigPtr->wksrc) && (NULL_PTR != HibernateModeConfigPtr->ckgen)
            && (NULL_PTR != HibernateModeConfigPtr->wkip)) {
            Mcu_WakeupSourceEnableConfig(Mcu_CfgPtr->pHibernateModeCfg->wksrc,
                                         Mcu_CfgPtr->pHibernateModeCfg->wkip,
                                         Mcu_CfgPtr->pHibernateModeCfg->ckgen->onoff);
        }
    }
}

FUNC(void, MCU_CODE) Mcu_LowPowerInit(
    P2CONST(Mcu_ConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr
)
{
    if (NULL_PTR != pConfigPtr) {

        /*  mask all smc irq */
        Mcu_SmcAllIrqMaskConfig();

        /* low power RTC mode configure*/
        Mcu_LowPowerRtcConfig(pConfigPtr->pRTCModeCfg);

        /* low power Sleep mode configure */
        Mcu_LowPowerSleepConfig(pConfigPtr->pSleepModeCfg);

        /* low power Hibernate mode configure */
        Mcu_LowPowerHibernateConfig(pConfigPtr->pHibernateModeCfg);

        /* low power control ctrl pilarity configure */
        if (NULL_PTR != pConfigPtr->pwrCtrlCfg) {
            Mcu_PmuSetPwrCtrlConfig(pConfigPtr->pwrCtrlCfg->config,
                                    pConfigPtr->pwrCtrlCfg->run_pmu, pConfigPtr->pwrCtrlCfg->pwrup_pmu);
        }
    }
}

FUNC(void, MCU_CODE) Mcu_SetPwrCtrlOverrideValue(
    CONST(pmu_pwrctrl_id_e, MCU_APPL_CONST) Id,
    CONST(pmu_polarity_e, MCU_APPL_CONST) Value
)
{
    Mcu_PmuSetExtPwrctrlOverrideValue(Id, Value);
}

FUNC(void, MCU_CODE) Mcu_SetPwrCtrlOverrideEnable(
    CONST(pmu_pwrctrl_id_e, MCU_APPL_CONST) Id,
    CONST(pmu_pwrctrl_select_e, MCU_APPL_CONST) Select
)
{
    Mcu_PmuSetExtPwrctrlOverrideEnable(Id, Select);
}

FUNC(void, MCU_CODE) Mcu_SetPwrSleepTime(
    VAR(Mcu_ModeType, AUTOMATIC) McuMode,
    CONST(rtc_alarm_t, MCU_APPL_CONST) Rtc_SleepTime
)
{
    Mcu_PwrRtcSleepTime[McuMode] = Rtc_SleepTime;
}

#if (MCU_GET_RAM_STATE_API == STD_ON)
FUNC(Mcu_RamStateType, MCU_CODE) Mcu_GetRamState(
    VAR(void, AUTOMATIC)
)
{
    return (Mcu_RamStateType)0u;
}
#endif /* (MCU_GET_RAM_STATE_API == STD_ON) */

FUNC(void, MCU_CODE) Mcu_GetVersionInfo(
    P2VAR(Std_VersionInfoType, AUTOMATIC, MCU_APPL_DATA) pVersionInfo
)
{
    if (NULL_PTR != pVersionInfo) {
        pVersionInfo->vendorID = MCU_H_VENDOR_ID;
        pVersionInfo->moduleID = MCU_MODULE_ID;
        pVersionInfo->sw_major_version = MCU_H_SW_MAJOR_VERSION;
        pVersionInfo->sw_minor_version = MCU_H_SW_MINOR_VERSION;
        pVersionInfo->sw_patch_version = MCU_H_SW_PATCH_VERSION;
    }
}

#if (STD_ON == MCU_APDOMAIN_POWERDOWN)
FUNC(void, MCU_CODE) Mcu_APDomainPowerdown(VAR(void, AUTOMATIC))
{
#ifdef EN_UNIFIED_IMAGE
    uint8 CoreId = Mcu_GetCoreID();
#endif

    if (CoreId == CPU_ID_SF) {
        soc_power_gate(AP_DOM);
    }
}
#endif

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif
