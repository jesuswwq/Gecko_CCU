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
#include "Mcu_Smc.h"
#include "Smc_Reg.h"
#include <Mcu_Delay.h>

/* Version and Check Begin */
/* Version Info Begin */
#define MCU_SMC_C_VENDOR_ID    0x8C
#define MCU_SMC_C_AR_RELEASE_MAJOR_VERSION    4
#define MCU_SMC_C_AR_RELEASE_MINOR_VERSION    3
#define MCU_SMC_C_AR_RELEASE_REVISION_VERSION 1
#define MCU_SMC_C_SW_MAJOR_VERSION    1
#define MCU_SMC_C_SW_MINOR_VERSION    0
#define MCU_SMC_C_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((MCU_SMC_C_AR_RELEASE_MAJOR_VERSION != MCU_SMC_H_AR_RELEASE_MAJOR_VERSION)\
    || (MCU_SMC_C_AR_RELEASE_MINOR_VERSION != MCU_SMC_H_AR_RELEASE_MINOR_VERSION)\
    || (MCU_SMC_C_AR_RELEASE_REVISION_VERSION != MCU_SMC_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Mcu_Smc.c and Mcu_Smc.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((MCU_SMC_C_SW_MAJOR_VERSION != MCU_SMC_H_SW_MAJOR_VERSION)\
    || (MCU_SMC_C_SW_MINOR_VERSION != MCU_SMC_H_SW_MINOR_VERSION)\
    || (MCU_SMC_C_SW_PATCH_VERSION != MCU_SMC_H_SW_PATCH_VERSION))
#error "Opps, Mcu_Smc.c and Mcu_Smc.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((MCU_SMC_C_AR_RELEASE_MAJOR_VERSION != SMC_REG_H_AR_RELEASE_MAJOR_VERSION)\
    || (MCU_SMC_C_AR_RELEASE_MINOR_VERSION != SMC_REG_H_AR_RELEASE_MINOR_VERSION)\
    || (MCU_SMC_C_AR_RELEASE_REVISION_VERSION != SMC_REG_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Mcu_Smc.c and Smc_Reg.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((MCU_SMC_C_SW_MAJOR_VERSION != SMC_REG_H_SW_MAJOR_VERSION)\
    || (MCU_SMC_C_SW_MINOR_VERSION != SMC_REG_H_SW_MINOR_VERSION)\
    || (MCU_SMC_C_SW_PATCH_VERSION != SMC_REG_H_SW_PATCH_VERSION))
#error "Opps, Mcu_Smc.c and Smc_Reg.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

/***********************************
* saf domain register configration *
***********************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

void Mcu_SmcSafWfiConfig(uint32 base, uint8 wfi_en, smc_lp_mode lpm)
{
    uint32 v = readl(base + SAF_GLB_CTL_OFF);

    /* wfi disable */
    if (wfi_en) {
        v &= ~BM_SAF_GLB_CTL_WFI_DIS;
    } else {
        v |= BM_SAF_GLB_CTL_WFI_DIS;
    }

    /* saf domain lowpower mode */
    if (SMC_SLP_MODE == lpm) {
        v &= ~BM_SAF_GLB_CTL_LP_MODE;
    } else {
        v |= BM_SAF_GLB_CTL_LP_MODE;
    }

    writel(v, base + SAF_GLB_CTL_OFF);
}

void Mcu_SmcSafPriCoreConfig(uint32 base, uint8 pri_core)
{
    uint32 v = readl(base + SAF_GLB_CTL_OFF);

    /* saf domain primary core */
    v &= ~FM_SAF_GLB_CTL_PRI_CORE;
    v |= FV_SAF_GLB_CTL_PRI_CORE(pri_core);

    writel(v, base + SAF_GLB_CTL_OFF);
}

Std_ReturnType Mcu_SmcSafLpConfig(uint32 base, uint8 saf_dom_lp_mode, uint8 sub_dom_idx,
                                  smc_pd_en pd_en)
{
    Std_ReturnType ret = E_NOT_OK;

    if (sub_dom_idx < 4) {
        uint32 v = readl(base + SAF_LP_CTL_OFF(sub_dom_idx));

        /* lowpower mode enable */
        if (pd_en) {
            if (SMC_HIB_MODE == saf_dom_lp_mode) {
                v |= BM_SAF_LP_CTL_HIB_PD_EN;
            } else {
                v |= BM_SAF_LP_CTL_SLP_PD_EN;
            }
        } else {
            if (SMC_HIB_MODE == saf_dom_lp_mode) {
                v &= ~BM_SAF_LP_CTL_HIB_PD_EN;
            } else {
                v &= ~BM_SAF_LP_CTL_SLP_PD_EN;
            }
        }

        writel(v, base + SAF_LP_CTL_OFF(sub_dom_idx));

        ret = E_OK;
    }

    return ret;
}

Std_ReturnType Mcu_SmcSafLpDlyConfig(uint32 base, uint8 sub_dom_idx, uint8 iso_dis_dly,
                                     uint8 po_dly,
                                     uint8 pg_dly, uint8 iso_en_dly)
{
    Std_ReturnType ret = E_NOT_OK;

    /* saf domain lowpower delay */
    if (sub_dom_idx < 4) {
        uint32 v = readl(base + SAF_LP_DLY_CTL_OFF(sub_dom_idx));

        v &= ~FM_SAF_LP_DLY_CTL_ISO_DIS;
        v &= ~FM_SAF_LP_DLY_CTL_PO;
        v &= ~FM_SAF_LP_DLY_CTL_PG;
        v &= ~FM_SAF_LP_DLY_CTL_ISO_EN;

        v |= FV_SAF_LP_DLY_CTL_ISO_DIS(iso_dis_dly);
        v |= FV_SAF_LP_DLY_CTL_PO(po_dly);
        v |= FV_SAF_LP_DLY_CTL_PG(pg_dly);
        v |= FV_SAF_LP_DLY_CTL_ISO_EN(iso_en_dly);

        writel(v, base + SAF_LP_DLY_CTL_OFF(sub_dom_idx));

        ret = E_OK;
    }

    return ret;
}

Std_ReturnType Mcu_SmcSafRampdConfig(uint32 base, uint8 saf_dom_lp_mode, smc_pd_en ram_pd_en,
                                     uint8 mem_dom_idx)
{
    Std_ReturnType ret = E_NOT_OK;

    if (mem_dom_idx < 5) {
        uint32 v = readl(base + SAF_RAM_LP_CTL_OFF(mem_dom_idx));

        /* saf domain ram power down enable */
        if (ram_pd_en) {
            if (SMC_HIB_MODE == saf_dom_lp_mode) {
                v |= BM_SAF_RAM_LP_CTL_HIB_RAM_PD_EN;
            } else {
                v |= BM_SAF_RAM_LP_CTL_SLP_RAM_PD_EN;
            }
        } else {
            if (SMC_HIB_MODE == saf_dom_lp_mode) {
                v &= ~BM_SAF_RAM_LP_CTL_HIB_RAM_PD_EN;
            } else {
                v &= ~BM_SAF_RAM_LP_CTL_SLP_RAM_PD_EN;
            }
        }

        writel(v, base + SAF_RAM_LP_CTL_OFF(mem_dom_idx));

        ret = E_OK;
    }

    return ret;
}

Std_ReturnType Mcu_SmcSafRampdSettingConfig(uint32 base, uint8 saf_dom_lp_mode, uint8 ram_setting,
        uint8 mem_dom_idx)
{
    Std_ReturnType ret = E_NOT_OK;

    /* lowpower mode ram lowpower setting */
    if (mem_dom_idx < 5) {
        uint32 v = readl(base + SAF_RAM_LP_CTL_OFF(mem_dom_idx));

        if (SMC_HIB_MODE == saf_dom_lp_mode) {
            v &= ~FM_SAF_RAM_LP_CTL_HIB_RAM_LP_SETTING;
            v |= FV_SAF_RAM_LP_CTL_HIB_RAM_LP_SETTING(ram_setting);
        } else {
            v &= ~FM_SAF_RAM_LP_CTL_SLP_RAM_LP_SETTING;
            v |= FV_SAF_RAM_LP_CTL_SLP_RAM_LP_SETTING(ram_setting);
        }

        writel(v, base + SAF_RAM_LP_CTL_OFF(mem_dom_idx));

        ret = E_OK;
    }

    return ret;
}

Std_ReturnType Mcu_SmcSafTimeoutConfig(uint32 base, boolean wdt_en, smc_handshake_stage tout_stage,
                                       uint8 tout_val)
{
    Std_ReturnType ret = E_NOT_OK;

    uint32 v = readl(base + SAF_TIMEOUT_OFF);

    if (wdt_en) {
        /* wdt enable for handshake time monitor */
        v |= BM_SAF_TIMEOUT_WDT_EN;

        if (CKGEN_HK == tout_stage) {
            /* timeout value for ckgen swm handshake */
            v &= ~FM_SAF_TIMEOUT_CKGEN_HK;
            v |= FV_SAF_TIMEOUT_CKGEN_HK(tout_val);
        } else if (RSTGEN_HK == tout_stage) {
            /* timeout value for rstgen swm handshake */
            v &= ~FM_SAF_TIMEOUT_RSTGEN_HK;
            v |= FV_SAF_TIMEOUT_RSTGEN_HK(tout_val);
        } else if (MODE_REQ_TRANS == tout_stage) {
            /* timeout value for mode trans request */
            v &= ~FM_SAF_TIMEOUT_MODE_REQ_TRANS;
            v |= FV_SAF_TIMEOUT_MODE_REQ_TRANS(tout_val);
        } else {
            ret = E_NOT_OK;
        }
    } else {
        v &= ~BM_SAF_TIMEOUT_WDT_EN;
    }

    writel(v, base + SAF_TIMEOUT_OFF);

    return ret;
}

void Mcu_SmcSafTimeoutWkupConfig(uint32 base, boolean wkup_en)
{
    uint32 v = readl(base + SAF_TIMEOUT_OFF);

    /* timeout wakeup during lp process enable */
    if (wkup_en) {
        v |= BM_SAF_TIMEOUT_WKUP_EN;
    } else {
        v &= ~BM_SAF_TIMEOUT_WKUP_EN;
    }

    writel(v, base + SAF_TIMEOUT_OFF);
}

void Mcu_SmcSafMiscConfig(uint32 base, boolean wkup_en, uint8 maskdly, boolean req_en)
{
    uint32 v = readl(base + SAF_MISC_OFF);

    /* swm illegal transfer wakeup enable */
    if (wkup_en) {
        v |= BM_SAF_MISC_ILL_TRANS_WKUP_EN;
    } else {
        v &= ~BM_SAF_MISC_ILL_TRANS_WKUP_EN;
    }

    /* interrupt mask delay */
    v &= ~FM_SAF_MISC_IRQ_MASK_DLY;
    v |= FV_SAF_MISC_IRQ_MASK_DLY(maskdly);

    /* lp mode transition request */
    if (req_en) {
        v |= BM_SAF_MISC_LP_TRANS_REQ;
    } else {
        v &= ~BM_SAF_MISC_LP_TRANS_REQ;
    }

    writel(v, base + SAF_TIMEOUT_OFF);
}

/**********************************
* ap domain register configration *
**********************************/
void Mcu_SmcApWfiConfig(uint32 base, uint8 wfi_en, smc_lp_mode lpm)
{
    uint32 v = readl(base + AP_GLB_CTL_OFF);

    /* wfi disable */
    if (wfi_en) {
        v &= ~BM_AP_GLB_CTL_WFI_DIS;
    } else {
        v |= BM_AP_GLB_CTL_WFI_DIS;
    }

    /* ap domain lowpower mode */
    if (SMC_SLP_MODE == lpm) {
        v &= ~BM_AP_GLB_CTL_LP_MODE;
    } else {
        v |= BM_AP_GLB_CTL_LP_MODE;
    }

    writel(v, base + AP_GLB_CTL_OFF);
}

void Mcu_SmcApLpAlignSafConfig(uint32 base, smc_align_mode lp_align2sf)
{
    uint32 v = readl(base + AP_GLB_CTL_OFF);

    /* ap domain lp align with saf domain enable */
    if (lp_align2sf) {
        v |= BM_AP_GLB_CTL_LP_ALIGN2SAF;
    } else {
        v &= ~BM_AP_GLB_CTL_LP_ALIGN2SAF;
    }

    writel(v, base + AP_GLB_CTL_OFF);
}

void Mcu_SmcApWkupAlignSafConfig(uint32 base, smc_align_mode wkup_align2sf)
{
    uint32 v = readl(base + AP_GLB_CTL_OFF);

    /* ap domain wakeup align with saf domain enable */
    if (wkup_align2sf) {
        v |= BM_AP_GLB_CTL_WKUP_ALIGN2SAF;
    } else {
        v &= ~BM_AP_GLB_CTL_WKUP_ALIGN2SAF;
    }

    writel(v, base + AP_GLB_CTL_OFF);
}

void Mcu_SmcApPriCoreConfig(uint32 base, uint8 pri_core)
{
    uint32 v = readl(base + AP_GLB_CTL_OFF);

    /* ap domain primary core */
    v &= ~FM_AP_GLB_CTL_PRI_CORE;
    v |= FV_AP_GLB_CTL_PRI_CORE(pri_core);

    writel(v, base + AP_GLB_CTL_OFF);
}

void Mcu_SmcApLpConfig(uint32 base, uint8 ap_dom_lp_mode, smc_pd_en pd_en)
{
    uint32 v = readl(base + AP_LP_CTL_OFF(0));

    /* ap domain lowpower mode */
    if (pd_en) {
        if (SMC_HIB_MODE == ap_dom_lp_mode) {
            v |= BM_AP_LP_CTL_HIB_PD_EN;
        } else {
            v |= BM_AP_LP_CTL_SLP_PD_EN;
        }
    } else {
        if (SMC_HIB_MODE == ap_dom_lp_mode) {
            v &= ~BM_AP_LP_CTL_HIB_PD_EN;
        } else {
            v &= ~BM_AP_LP_CTL_SLP_PD_EN;
        }
    }

    writel(v, base + AP_LP_CTL_OFF(0));
}

void Mcu_SmcApLpDlyConfig(uint32 base, uint8 iso_dis_dly, uint8 po_dly, uint8 pg_dly,
                          uint8 iso_en_dly)
{
    uint32 v = readl(base + AP_LP_DLY_CTL_OFF(0));

    /* ap domain lowpower delay control */
    v &= ~FM_AP_LP_DLY_CTL_ISO_DIS;
    v &= ~FM_AP_LP_DLY_CTL_PO;
    v &= ~FM_AP_LP_DLY_CTL_PG;
    v &= ~FM_AP_LP_DLY_CTL_ISO_EN;

    v |= FV_AP_LP_DLY_CTL_ISO_DIS(iso_dis_dly);
    v |= FV_AP_LP_DLY_CTL_PO(po_dly);
    v |= FV_AP_LP_DLY_CTL_PG(pg_dly);
    v |= FV_AP_LP_DLY_CTL_ISO_EN(iso_en_dly);

    writel(v, base + AP_LP_DLY_CTL_OFF(0));
}

Std_ReturnType Mcu_SmcApRampdConfig(uint32 base, uint8 ap_dom_lp_mode, smc_pd_en ram_pd_en,
                                    uint8 mem_dom_idx)
{
    Std_ReturnType ret = E_NOT_OK;

    if (mem_dom_idx < 2) {
        uint32 v = readl(base + AP_RAM_LP_CTL_OFF(mem_dom_idx));

        /* lowpower mode ram power down enable */
        if (ram_pd_en) {
            if (SMC_HIB_MODE == ap_dom_lp_mode) {
                v |= BM_AP_RAM_LP_CTL_HIB_RAM_PD_EN;
            } else {
                v |= BM_AP_RAM_LP_CTL_SLP_RAM_PD_EN;
            }
        } else {
            if (SMC_HIB_MODE == ap_dom_lp_mode) {
                v &= ~BM_AP_RAM_LP_CTL_HIB_RAM_PD_EN;
            } else {
                v &= ~BM_AP_RAM_LP_CTL_SLP_RAM_PD_EN;
            }
        }

        writel(v, base + AP_RAM_LP_CTL_OFF(mem_dom_idx));
        ret = E_OK;
    }

    return ret;
}

Std_ReturnType Mcu_SmcApRampdSettingConfig(uint32 base, uint32 ap_dom_lp_mode, uint8 ram_setting,
        uint8 mem_dom_idx)
{
    Std_ReturnType ret = E_NOT_OK;

    /* lowpower mode ram lowpower setting */
    if (mem_dom_idx < 2) {
        uint32 v = readl(base + AP_RAM_LP_CTL_OFF(mem_dom_idx));

        if (SMC_HIB_MODE == ap_dom_lp_mode) {
            v &= ~FM_AP_RAM_LP_CTL_HIB_RAM_LP_SETTING;
            v |= FV_AP_RAM_LP_CTL_HIB_RAM_LP_SETTING(ram_setting);
        } else {
            v &= ~FM_AP_RAM_LP_CTL_SLP_RAM_LP_SETTING;
            v |= FV_AP_RAM_LP_CTL_SLP_RAM_LP_SETTING(ram_setting);
        }

        writel(v, base + AP_RAM_LP_CTL_OFF(mem_dom_idx));

        ret = E_OK;
    }

    return ret;
}

Std_ReturnType Mcu_SmcApTimeoutConfig(uint32 base, boolean wdt_en, smc_handshake_stage tout_stage,
                                      uint8 tout_val)
{
    Std_ReturnType ret = E_OK;

    uint32 v = readl(base + AP_TIMEOUT_OFF);

    if (wdt_en) {
        /* wdt enable for handshake time monitor */
        v |= BM_AP_TIMEOUT_WDT_EN;

        if (CKGEN_HK == tout_stage) {
            /* timeout value for ckgen swm handshake */
            v &= ~FM_AP_TIMEOUT_CKGEN_HK;
            v |= FV_AP_TIMEOUT_CKGEN_HK(tout_val);
        } else if (RSTGEN_HK == tout_stage) {
            /* timeout value for rstgen swm handshake */
            v &= ~FM_AP_TIMEOUT_RSTGEN_HK;
            v |= FV_AP_TIMEOUT_RSTGEN_HK(tout_val);
        } else if (MODE_REQ_TRANS == tout_stage) {
            /* timeout value for mode trans request */
            v &= ~FM_AP_TIMEOUT_MODE_REQ_TRANS;
            v |= FV_AP_TIMEOUT_MODE_REQ_TRANS(tout_val);
        } else {
            ret = E_NOT_OK;
        }
    } else {
        v &= ~BM_AP_TIMEOUT_WDT_EN;
    }

    writel(v, base + AP_TIMEOUT_OFF);

    return ret;
}

void Mcu_SmcApTimeoutWkupConfig(uint32 base, boolean wkup_en)
{
    uint32 v = readl(base + AP_TIMEOUT_OFF);

    /* timeout wakeup during lp process enable */
    if (wkup_en) {
        v |= BM_AP_TIMEOUT_WKUP_EN;
    } else {
        v &= ~BM_AP_TIMEOUT_WKUP_EN;
    }

    writel(v, base + AP_TIMEOUT_OFF);
}

void Mcu_SmcApMiscConfig(uint32 base, boolean wkup_en, uint8 maskdly, boolean req_en)
{
    uint32 v = readl(base + AP_MISC_OFF);

    /* swm illegal transfer wakeup enable */
    if (wkup_en) {
        v |= BM_AP_MISC_ILL_TRANS_WKUP_EN;
    } else {
        v &= ~BM_AP_MISC_ILL_TRANS_WKUP_EN;
    }

    /* interrupt mask delay */
    v &= ~FM_AP_MISC_IRQ_MASK_DLY;
    v |= FV_AP_MISC_IRQ_MASK_DLY(maskdly);

    /* lp mode transition request */
    if (req_en) {
        v |= BM_AP_MISC_LP_TRANS_REQ;
    } else {
        v &= ~BM_AP_MISC_LP_TRANS_REQ;
    }

    writel(v, base + AP_MISC_OFF);
}

/******************************
*  soc register configration  *
******************************/
void Mcu_SmcSocGlobalConfig(uint32 base, boolean ap_off)
{
    uint32 v = readl(base + SOC_GLB_CTL_OFF);

    /* ap domain power off */
    if (ap_off) {
        v |= BM_SOC_GLB_CTL_AP_OFF;
    } else {
        v &= ~BM_SOC_GLB_CTL_AP_OFF;
    }

    writel(v, base + SOC_GLB_CTL_OFF);
}

void Mcu_SmcSocHibrcDisConfig(uint32 base, smc_rc_dis_en rc_dis_en)
{
    uint32 v = readl(base + SOC_HIB_RC_DIS_OFF);

    /* hib mode rc24m disable/enable */
    if (rc_dis_en) {
        v |= BM_SOC_HIB_RC_DIS_RC_DIS_EN;
    } else {
        v &= ~BM_SOC_HIB_RC_DIS_RC_DIS_EN;
    }

    writel(v, base + SOC_HIB_RC_DIS_OFF);
}

void Mcu_SmcSoc32kDivNumConfig(uint32 base, uint8 div_num)
{
    uint32 v = readl(base + SOC_PRE_DIV_OFF);

    /* pre div number for clk32k */
    v &= ~FM_SOC_PRE_DIV_DIV_NUM_32K;
    v |= FV_SOC_PRE_DIV_DIV_NUM_32K(div_num);

    writel(v, base + SOC_PRE_DIV_OFF);
}

void Mcu_SmcSoc24mDivNumConfig(uint32 base, uint8 div_num)
{
    uint32 v = readl(base + SOC_PRE_DIV_OFF);

    /* pre div number for clk24m */
    v &= ~FM_SOC_PRE_DIV_DIV_NUM_24M;
    v |= FV_SOC_PRE_DIV_DIV_NUM_24M(div_num);

    writel(v, base + SOC_PRE_DIV_OFF);
}

void Mcu_SmcSocSwmTimeoutConfig(uint32 base, boolean wdt_en, uint8 pmu_hk)
{
    uint32 v = readl(base + SOC_SWM_TIMEOUT_OFF);

    /* wdt enable for handshake time monitor */
    if (wdt_en) {
        v |= BM_SOC_SWM_TIMEOUT_WDT_EN;
    } else {
        v &= ~BM_SOC_SWM_TIMEOUT_WDT_EN;
    }

    /* timeout value for pmu swm handshake */
    v &= ~FM_SOC_SWM_TIMEOUT_PMU_HK;
    v |= FV_SOC_SWM_TIMEOUT_PMU_HK(pmu_hk);

    writel(v, base + SOC_SWM_TIMEOUT_OFF);
}

void Mcu_SmcSocSwmTimeoutWkupConfig(uint32 base, boolean wkup_en)
{
    uint32 v = readl(base + SOC_SWM_TIMEOUT_OFF);

    /* timeout wakeup during lp process enable/disable */
    if (wkup_en) {
        v |= BM_SOC_SWM_TIMEOUT_WKUP_EN;
    } else {
        v &= ~BM_SOC_SWM_TIMEOUT_WKUP_EN;
    }

    writel(v, base + SOC_SWM_TIMEOUT_OFF);
}

void Mcu_SmcSocWkupAckTimeoutConfig(uint32 base, uint16 tout_val)
{
    uint32 v = readl(base + SOC_WKUP_CTL_OFF);

    /* wakeup done event source sel */
    v |= BM_SOC_WKUP_CTL_WKUP_DONE_SRC_SEL;

    /* wakeup wdt enable */
    v |= BM_SOC_WKUP_CTL_WKUP_WDT_EN;

    writel(v, base + SOC_WKUP_CTL_OFF);

    v = readl(base + SOC_WKUP_TIMEOUT_OFF);

    /* timeout value for wakeup event receive to all active cpu acknowleage done */
    v &= ~FM_SOC_WKUP_TIMEOUT_WKUP_ACK;
    v |= FV_SOC_WKUP_TIMEOUT_WKUP_ACK(tout_val);

    writel(v, base + SOC_WKUP_TIMEOUT_OFF);
}

void Mcu_SmcSocToRunTimeoutConfig(uint32 base, uint16 tout_val)
{
    uint32 v = readl(base + SOC_WKUP_CTL_OFF);

    /* wakeup done event source sel */
    v &= ~BM_SOC_WKUP_CTL_WKUP_DONE_SRC_SEL;

    /* wakeup wdt enable */
    v |= BM_SOC_WKUP_CTL_WKUP_WDT_EN;

    writel(v, base + SOC_WKUP_CTL_OFF);

    v = readl(base + SOC_WKUP_TIMEOUT_OFF);

    /* timeout value for wakeup event receive to soc goes into RUN state */
    v &= ~FM_SOC_WKUP_TIMEOUT_SOC_RUN;
    v |= FV_SOC_WKUP_TIMEOUT_SOC_RUN(tout_val);

    writel(v, base + SOC_WKUP_TIMEOUT_OFF);
}

void Mcu_SmcSocLp2wkupTimeoutConfig(uint32 base, uint16 tout_val, boolean tout_wkup_en)
{
    uint32 v = readl(base + SOC_WKUP_CTL_OFF);

    /* wdt enable between lp to wakeup event receive */
    v |= BM_SOC_WKUP_CTL_LP2WKUP_WDT_EN;

    /* timeout between lp to timeout wakeup enable */
    if (tout_wkup_en) {
        v |= BM_SOC_WKUP_CTL_LP2WKUP_TOUT_WKUP_EN;
    } else {
        v &= ~BM_SOC_WKUP_CTL_LP2WKUP_TOUT_WKUP_EN;
    }

    /* time between lp to wakeup event receive */
    v &= ~FM_SOC_WKUP_CTL_LP2WKUP_VAL;
    v |= FV_SOC_WKUP_CTL_LP2WKUP_VAL(tout_val);

    writel(v, base + SOC_WKUP_CTL_OFF);
}

void Mcu_SmcSocWkupirqWkupConfig(uint32 base, uint8 err_wkup_en, uint8 bk_wkup_en)
{
    uint32 v = readl(base + SMC_WKUP_IRQ_OFF);

    /* SMC error wakeup core irq enable */
    if (err_wkup_en) {
        v &= ~FM_SMC_WKUP_IRQ_ERR_WKUP_EN;
        v |= FV_SMC_WKUP_IRQ_ERR_WKUP_EN(err_wkup_en);
    }

    /* SMC wakeup core irq enable */
    if (bk_wkup_en) {
        v &= ~FM_SMC_WKUP_IRQ_BK_WKUP_EN;
        v |= FV_SMC_WKUP_IRQ_BK_WKUP_EN(bk_wkup_en);
    }

    writel(v, base + SMC_WKUP_IRQ_OFF);
}

void Mcu_SmcSocWkupirqClr(uint32 base, uint8 *wkup_irq_state)
{
    uint32 v = readl(base + SMC_WKUP_IRQ_OFF);
    uint8 irq_state = GFV_SMC_WKUP_IRQ_WKUP_IRQ_STA(v);

    *(uint8 *) wkup_irq_state = irq_state;

    /* SMC wakeup core irq clear, auto clear */
    if (irq_state) {
        v |= FV_SMC_WKUP_IRQ_WKUP_CLR(irq_state);
        writel(v, base + SMC_WKUP_IRQ_OFF);
    }
}

Std_ReturnType Mcu_SmcCoreIrqMaskConfig(uint32 base, uint32 core_idx, uint16 mask_val)
{
    Std_ReturnType ret = E_NOT_OK;

    if (core_idx < 5u) {
        uint32 v = readl(base + CORE_IRQ_MASK_OFF(core_idx));
        /* irq mask */
        v |= mask_val;
        writel(v, base + CORE_IRQ_MASK_OFF(core_idx));

        ret = E_OK;
    }

    return ret;
}

Std_ReturnType Mcu_SmcCoreIrqUnMaskConfig(uint32 base, uint32 core_idx, uint16 mask_bit)
{
    Std_ReturnType ret = E_NOT_OK;

    if (core_idx < 5u) {
        uint32 v = readl(base + CORE_IRQ_MASK_OFF(core_idx));
        /* irq unmask */
        v &= ~(0x1 << mask_bit);
        writel(v, base + CORE_IRQ_MASK_OFF(core_idx));

        ret = E_OK;
    }

    return ret;
}

Std_ReturnType Mcu_SmcCoreIrqMonitor(uint32 base, uint32 core_idx, uint32 *irq_state)
{
    Std_ReturnType ret = E_NOT_OK;

    if ((core_idx < 5) && (irq_state != NULL)) {
        /* core specfic irq monitor */
        *irq_state = readl(base + CORE_IRQ_MON_OFF(core_idx));
        ret = E_OK;
    }

    return ret;
}

Std_ReturnType Mcu_SmcCoreIrqClear(uint32 base, uint32 core_idx, uint32 clr_bit_mask)
{
    Std_ReturnType ret = E_NOT_OK;

    if (core_idx < 5) {
        uint32 irq_state = 0;
        Mcu_SmcCoreIrqMonitor(base, core_idx, &irq_state);
        writel((clr_bit_mask & irq_state), base + CORE_IRQ_MON_OFF(core_idx));
        ret = E_OK;
    }

    return ret;
}

Std_ReturnType Mcu_SmcComIrqMaskConfig(uint32 base, uint32 core_idx, uint32 irq_grp_idx,
                                       uint32 mask_val)
{
    Std_ReturnType ret = E_NOT_OK;

    if ((core_idx < 5u) && (irq_grp_idx < 8u)) {
        uint32 addr;

        if (irq_grp_idx == 0) {
            addr = base + COM_IRQ_MASK_0_OFF(core_idx);
        } else if (irq_grp_idx == 1) {
            addr = base + COM_IRQ_MASK_1_OFF(core_idx);
        } else if (irq_grp_idx == 2) {
            addr = base + COM_IRQ_MASK_2_OFF(core_idx);
        } else if (irq_grp_idx == 3) {
            addr = base + COM_IRQ_MASK_3_OFF(core_idx);
        } else if (irq_grp_idx == 4) {
            addr = base + COM_IRQ_MASK_4_OFF(core_idx);
        } else if (irq_grp_idx == 5) {
            addr = base + COM_IRQ_MASK_5_OFF(core_idx);
        } else if (irq_grp_idx == 6) {
            addr = base + COM_IRQ_MASK_6_OFF(core_idx);
        } else
            addr = base + COM_IRQ_MASK_7_OFF(core_idx);

        uint32 v = readl(addr);
        v |= mask_val;
        writel(v, addr);

        ret = E_OK;
    }

    return ret;
}

Std_ReturnType Mcu_SmcComIrqUnMaskConfig(uint32 base, uint32 core_idx, uint32 irq_grp_idx,
        uint32 mask_bit)
{
    Std_ReturnType ret = E_NOT_OK;

    if ((core_idx < 5u) && (irq_grp_idx < 8u)) {
        uint32 addr;

        if (irq_grp_idx == 0) {
            addr = base + COM_IRQ_MASK_0_OFF(core_idx);
        } else if (irq_grp_idx == 1) {
            addr = base + COM_IRQ_MASK_1_OFF(core_idx);
        } else if (irq_grp_idx == 2) {
            addr = base + COM_IRQ_MASK_2_OFF(core_idx);
        } else if (irq_grp_idx == 3) {
            addr = base + COM_IRQ_MASK_3_OFF(core_idx);
        } else if (irq_grp_idx == 4) {
            addr = base + COM_IRQ_MASK_4_OFF(core_idx);
        } else if (irq_grp_idx == 5) {
            addr = base + COM_IRQ_MASK_5_OFF(core_idx);
        } else if (irq_grp_idx == 6) {
            addr = base + COM_IRQ_MASK_6_OFF(core_idx);
        } else
            addr = base + COM_IRQ_MASK_7_OFF(core_idx);

        uint32 v = readl(addr);
        v &= ~(0x1 << mask_bit);
        writel(v, addr);

        ret = E_OK;
    }

    return ret;
}

Std_ReturnType Mcu_SmcComIrqMonitor(uint32 base, uint32 irq_grp_idx, uint32 *irq_state)
{
    Std_ReturnType ret = E_NOT_OK;

    if ((irq_grp_idx < 8) && (irq_state != NULL)) {
        if (irq_grp_idx == 0) {
            *irq_state = readl(base + COM_IRQ_MON_0_OFF);
        } else if (irq_grp_idx == 1) {
            *irq_state = readl(base + COM_IRQ_MON_1_OFF);
        } else if (irq_grp_idx == 2) {
            *irq_state = readl(base + COM_IRQ_MON_2_OFF);
        } else if (irq_grp_idx == 3) {
            *irq_state = readl(base + COM_IRQ_MON_3_OFF);
        } else if (irq_grp_idx == 4) {
            *irq_state = readl(base + COM_IRQ_MON_4_OFF);
        } else if (irq_grp_idx == 5) {
            *irq_state = readl(base + COM_IRQ_MON_5_OFF);
        } else if (irq_grp_idx == 6) {
            *irq_state = readl(base + COM_IRQ_MON_6_OFF);
        } else
            *irq_state = readl(base + COM_IRQ_MON_7_OFF);

        ret = E_OK;
    }

    return ret;
}

Std_ReturnType Mcu_SmcComIrqClear(uint32 base, uint32 irq_grp_idx, uint32 clr_bit_mask)
{
    Std_ReturnType ret = E_NOT_OK;

    if (irq_grp_idx < 8) {
        uint32 irq_state = 0;
        Mcu_SmcComIrqMonitor(base, irq_grp_idx, &irq_state);

        if (irq_grp_idx == 0) {
            writel((clr_bit_mask & irq_state), base + COM_IRQ_MON_0_OFF);
        } else if (irq_grp_idx == 1) {
            writel((clr_bit_mask & irq_state), base + COM_IRQ_MON_1_OFF);
        } else if (irq_grp_idx == 2) {
            writel((clr_bit_mask & irq_state), base + COM_IRQ_MON_2_OFF);
        } else if (irq_grp_idx == 3) {
            writel((clr_bit_mask & irq_state), base + COM_IRQ_MON_3_OFF);
        } else if (irq_grp_idx == 4) {
            writel((clr_bit_mask & irq_state), base + COM_IRQ_MON_4_OFF);
        } else if (irq_grp_idx == 5) {
            writel((clr_bit_mask & irq_state), base + COM_IRQ_MON_5_OFF);
        } else if (irq_grp_idx == 6) {
            writel((clr_bit_mask & irq_state), base + COM_IRQ_MON_6_OFF);
        } else
            writel((clr_bit_mask & irq_state), base + COM_IRQ_MON_7_OFF);

        ret = E_OK;
    }

    return ret;
}

uint32 Mcu_SmcGetSmwMonitorStatus(uint32 base)
{
    uint32 v = readl(base + SWM_MON_OFF);
    /* swm status monitor */
    return v;
}

void Mcu_SmcPollingPmuSwSwmResult(uint32 base)
{
    uint32 timeout = 0;
    uint32 v = 0;

    /* polling swm handshake result, wait for 7 clock */
    while ((!(readl(base + SMC_SW_SWM_OFF) & BM_SMC_SW_SWM_PMU_SWM_OK)) && (timeout++ < 1000U));

    /* write 0 to celar swm handshake result */
    v = readl(base + SMC_SW_SWM_OFF);

    v &= ~BM_SMC_SW_SWM_PMU_SWM_OK;
    writel(v, base + SMC_SW_SWM_OFF);
}

void Mcu_SmcSetPmuSwSwmEnable(uint32 base, boolean enable)
{
    uint32 v = readl(base + SMC_SW_SWM_OFF);

    /* enable/disable pmu sw swm */
    if (enable)
        v |= BM_SMC_SW_SWM_PMU_SWM_EN;
    else
        v &= ~BM_SMC_SW_SWM_PMU_SWM_EN;

    writel(v, base + SMC_SW_SWM_OFF);
}

void Mcu_SmcSetPmuSwSwmMode(uint32 base, uint32 wdata)
{
    uint32 v = 0;

    Mcu_SmcSetPmuSwSwmEnable(base, TRUE);

    /* pmu sw swm mode */
    readl(base + SMC_SW_SWM_OFF);
    v &= ~FM_SMC_SW_SWM_PMU_SWM_O;
    v |= FV_SMC_SW_SWM_PMU_SWM_O(wdata);
    writel(v, base + SMC_SW_SWM_OFF);

    /* write 1 to trigger swm handshake */
    v = readl(base + SMC_SW_SWM_OFF);
    v |= BM_SMC_SW_SWM_PMU_SWM_TRIGGER;
    writel(v, base + SMC_SW_SWM_OFF);

    Mcu_SmcPollingPmuSwSwmResult(base);

    Mcu_SmcSetPmuSwSwmEnable(base, FALSE);
}

void Mcu_SmcSetDebugMuxSelectMode(uint32 base, uint32 wdata)
{
    uint32 v = readl(base + SMC_DBG_SEL_OFF);

    /* debug mux select */
    v &= ~FM_SMC_DBG_SEL_SEL;
    v |= FV_SMC_DBG_SEL_SEL(wdata);

    writel(v, base + SMC_DBG_SEL_OFF);
}

uint32 Mcu_SmcGetDebugMonitorStatus(uint32 base)
{
    uint32 v = readl(base + SMC_DBG_MON_OFF);
    /* swm debug monitor */
    return v;
}


#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif
