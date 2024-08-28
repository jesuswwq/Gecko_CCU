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

#ifndef __MCU_SMC_H__
#define __MCU_SMC_H__
#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
/* Version and Check Begin */
/* Version Info Begin */
#define MCU_SMC_H_VENDOR_ID    0x8C
#define MCU_SMC_H_AR_RELEASE_MAJOR_VERSION    4
#define MCU_SMC_H_AR_RELEASE_MINOR_VERSION    3
#define MCU_SMC_H_AR_RELEASE_REVISION_VERSION 1
#define MCU_SMC_H_SW_MAJOR_VERSION    1
#define MCU_SMC_H_SW_MINOR_VERSION    0
#define MCU_SMC_H_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((MCU_SMC_H_AR_RELEASE_MAJOR_VERSION != STD_TYPES_H_AR_RELEASE_MAJOR_VERSION)\
    || (MCU_SMC_H_AR_RELEASE_MINOR_VERSION != STD_TYPES_H_AR_RELEASE_MINOR_VERSION)\
    || (MCU_SMC_H_AR_RELEASE_REVISION_VERSION != STD_TYPES_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Mcu_Smc.h and Std_Types.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((MCU_SMC_H_SW_MAJOR_VERSION != STD_TYPES_H_SW_MAJOR_VERSION)\
    || (MCU_SMC_H_SW_MINOR_VERSION != STD_TYPES_H_SW_MINOR_VERSION)\
    || (MCU_SMC_H_SW_PATCH_VERSION != STD_TYPES_H_SW_PATCH_VERSION))
#error "Opps, Mcu_Smc.h and Std_Types.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

#define SMC_CORE_IRQ_MASK   0xFFFF
#define SMC_COMM_IRQ_MASK   0xFFFFFFFF

/* smc swm monitor mask*/
#define SMC_AP_INTER_SWM_MASK           0x3E00000
#define SMC_SAF_INTER_SWM_MASK          0x1F0000
#define SMC_SAF_INTER_SWM_RUN_STATUS     0x10000
#define SMC_AP_INTER_SWM_RUN_STATUS     0x200000

#define MCU_SMC_RESERVED_FUNCs  0

/**
 * @brief core no.
 */
typedef enum {
    SMC_CORE_SF,
    SMC_CORE_SP,
    SMC_CORE_SX,
    SMC_CORE_GAMA1,
    SMC_SAF_MISC,
} smc_saf_core_index;

/**
 * @brief core no.
 */
typedef enum {
    SMC_CORE_DISP,
} smc_ap_core_index;

/**
 * @brief common irq index no.
 */
typedef enum {
    SMC_COMM_IRQ_0,
    SMC_COMM_IRQ_1,
    SMC_COMM_IRQ_2,
    SMC_COMM_IRQ_3,
    SMC_COMM_IRQ_4,
    SMC_COMM_IRQ_5,
    SMC_COMM_IRQ_6,
    SMC_COMM_IRQ_7,
} smc_com_irq_index;

/**
 * @brief ap off enable.
 */
typedef enum {
    CKGEN_HK,
    RSTGEN_HK,
    MODE_REQ_TRANS,
    PMU_HK
} smc_handshake_stage;

typedef enum {
    SMC_AP_ON,
    SMC_AP_OFF,
} smc_ap_off_en;

/**
 * @brief rc24m disable enable.
 */
typedef enum {
    SMC_RC_DIS_DISABLE,
    SMC_RC_DIS_ENABLE,
} smc_rc_dis_en;

/**
 * @brief power down enable.
 */
typedef enum {
    SMC_PD_DISABLE,
    SMC_PD_ENABLE,
} smc_pd_en;

/**
 * @brief wfi enable.
 */
typedef enum {
    SMC_WFI_DISABLE,
    SMC_WFI_ENABLE,
} smc_wfi_en;

/**
 * @brief lowpower mode.
 */
typedef enum {
    SMC_SLP_MODE,
    SMC_HIB_MODE,
} smc_lp_mode;

/**
 * @brief ram lp mode.
 */
typedef enum {
    SMC_RAM_LP_RET2N = 1,
    SMC_RAM_LP_RET1N = 2,
    SMC_RAM_LP_PG_EN = 4,
} smc_ram_lp_mode;

/**
 * @brief align enable.
 */
typedef enum {
    SMC_ALIGN_NO,
    SMC_ALIGN_YES,
} smc_align_mode;

/**
 * @brief wakupsrc enable.
 */
typedef enum {
    SMC_WAKEUP_SRC_DISABLE,
    SMC_WAKEUP_SRC_ENABLE,
} smc_wakeup_src_enable_e;

/**
 * @brief SMC debug mux sel.
 */
typedef enum {
    SMC_DBG_HK_SAF = 1,
    SMC_DBG_HK_AP,
    SMC_DBG_HK_PMU
} smc_debug_mux_e;

typedef struct {
    smc_pd_en       appd;
    smc_pd_en       apram;
    smc_lp_mode     aplp;
    smc_align_mode  wkup;
    smc_align_mode  lp;
} smc_ap_domain_ctrl_t;

typedef struct {
    smc_pd_en       sfpd;
    smc_pd_en       sfram;
    smc_pd_en       sppd;
    smc_pd_en       spram;
    smc_pd_en       sxpd;
    smc_pd_en       sxram;
    smc_pd_en       gama3pd;
    smc_pd_en       gama1ram;
    smc_pd_en       safmisc;
    smc_lp_mode     saflp;
} smc_saf_domain_ctrl_t;

typedef struct {
    uint16      coreirqmask;
    uint16      commirqmask0;
    uint16      commirqmask1;
    uint16      commirqmask2;
    uint16      commirqmask3;
    uint16      commirqmask4;
    uint16      commirqmask5;
    uint16      commirqmask6;
    uint16      commirqmask7;
} smc_irq_ctrl_t;

typedef struct {
    const smc_saf_domain_ctrl_t   *saf;
    const smc_ap_domain_ctrl_t    *ap;
} smc_ctrl_t;

/***********************************
* saf domain register configration *
***********************************/
/**
 * @brief safe domain wfi configuration
 *
 * @param[in] base reg base
 * @param[in] wfi_en wfi enable or not
 * @param[in] lpm saf dom low power mode, slp or hib
 */

void Mcu_SmcSafWfiConfig(uint32 base, uint8 wfi_en, smc_lp_mode lpm);

/**
 * @brief safe domain wfi configuration
 *
 * @param[in] base reg base
 * @param[in] pri_core safe domain primary core
 */
void Mcu_SmcSafPriCoreConfig(uint32 base, uint8 pri_core);

/**
 * @brief safe domain low power configuration
 *
 * @param[in] base reg base
 * @param[in] sub_dom_idx saf power domain index,range 0~3
 * @param[in] pd_en power down enable
 *
 * @return -1 if sub_dom_idx out of range, otherwise 0
 */
Std_ReturnType Mcu_SmcSafLpConfig(uint32 base, uint8 saf_dom_lp_mode, uint8 sub_dom_idx,
                                  smc_pd_en pd_en);

/**
 * @brief safe domain low power delay configuration
 *
 * @param[in] base reg base
 * @param[in] sub_dom_idx saf power domain index,range 0~3
 * @param[in] iso_dis_dly isolation disable delay
 * @param[in] po_dly power on delay
 * @param[in] pg_dly power gate delay
 * @param[in] iso_en_dly isolation enable delay
 *
 * @return -1 if sub_dom_idx out of range, otherwise 0
 */
Std_ReturnType Mcu_SmcSafLpDlyConfig(uint32 base, uint8 sub_dom_idx, uint8 iso_dis_dly,
                                     uint8 po_dly,
                                     uint8 pg_dly, uint8 iso_en_dly);

/**
 * @brief safe domain ram low power configuration under hib mode
 *
 * @param[in] base reg base
 * @param[in] mem_dom_idx saf power domain index,range 0~4
 * @param[in] ram_pd_en ram power down enable
 * @param[in] ram_setting ram low power setting
 *
 * @return -1 if mem_dom_idx out of range, otherwise 0
 */
Std_ReturnType Mcu_SmcSafRampdConfig(uint32 base, uint8 saf_dom_lp_mode, smc_pd_en ram_pd_en,
                                     uint8 mem_dom_idx);

/**
 * @brief safe domain ram low power configuration under hib mode
 *
 * @param[in] base reg base
 * @param[in] mem_dom_idx saf power domain index,range 0~4
 * @param[in] ram_setting ram low power setting
 *
 * @return -1 if mem_dom_idx out of range, otherwise 0
 */
Std_ReturnType Mcu_SmcSafRampdSettingConfig(uint32 base, uint8 saf_dom_lp_mode, uint8 ram_setting,
        uint8 mem_dom_idx);

/**
 * @brief safe domain timeout configuration
 *
 * @param[in] base reg base
 * @param[in] wdt_en saf domain handshake watchdog enable
 * @param[in] tout_stage timeout monitor stage, ckgen, rstgen or mode req trans
 * @param[in] tout_val timeout value
 *
 * @return -1 if tout_stage out of range, otherwise 0
 */
Std_ReturnType Mcu_SmcSafTimeoutConfig(uint32 base, boolean wdt_en, smc_handshake_stage tout_stage,
                                       uint8 tout_val);

/**
 * @brief safe domain timeout wakeup enable configuration
 *
 * @param[in] base reg base
 * @param[in] wkup_en safe domain timeout wakeup enable
 *
 */
void Mcu_SmcSafTimeoutWkupConfig(uint32 base, boolean wkup_en);

/**
 * @brief safe domain misc configuration
 *
 * @param[in] base reg base
 * @param[in] wkup_en safe domain timeout wakeup enable
 *
 */
void Mcu_SmcSafMiscConfig(uint32 base, boolean wkup_en, uint8 maskdly, boolean req_en);

/***********************************
* saf domain register configration *
***********************************/
/**********************************
* ap domain register configration *
**********************************/
/**
 * @brief ap domain wfi configuration
 *
 * @param[in] base reg base
 * @param[in] wfi_en ap domain wfi enable
 * @param[in] lpm ap domain low power mode
 *
 */
void Mcu_SmcApWfiConfig(uint32 base, uint8 wfi_en, smc_lp_mode lpm);

/**
 * @brief ap domain lp align with saf domain configuration
 *
 * @param[in] base reg base
 * @param[in] lp_align2sf ap domain lp align with saf domain
 *
 */
void Mcu_SmcApLpAlignSafConfig(uint32 base, smc_align_mode lp_align2sf);

/**
 * @brief ap domain wakeup align with saf domain configuration
 *
 * @param[in] base reg base
 * @param[in] wkup_align2sf ap domain wakeup align with saf domain enable
 *
 */
void Mcu_SmcApWkupAlignSafConfig(uint32 base, smc_align_mode wkup_align2sf);

/**
 * @brief ap domain primary core configuration
 *
 * @param[in] base reg base
 * @param[in] pri_core ap domain primary core
 *
 */
void Mcu_SmcApPriCoreConfig(uint32 base, uint8 pri_core);

/**
 * @brief ap domain low power configuration
 *
 * @param[in] base reg base
 * @param[in] pd_en power down enable
 *
 */
void Mcu_SmcApLpConfig(uint32 base, uint8 ap_dom_lp_mode, smc_pd_en pd_en);

/**
 * @brief safe domain low power delay configuration
 *
 * @param[in] base reg base
 * @param[in] iso_dis_dly isolation disable delay
 * @param[in] po_dly power on delay
 * @param[in] pg_dly power gate delay
 * @param[in] iso_en_dly isolation enable delay
 *
 */
void Mcu_SmcApLpDlyConfig(uint32 base, uint8 iso_dis_dly, uint8 po_dly, uint8 pg_dly,
                          uint8 iso_en_dly);

/**
 * @brief ap domain ram low power configuration
 *
 * @param[in] base reg base
 * @param[in] mem_dom_idx saf power domain index,range 0~1
 * @param[in] ram_pd_en ram power down enable
 *
 * @return -1 if mem_dom_idx out of range, otherwise 0
 */
Std_ReturnType Mcu_SmcApRampdConfig(uint32 base, uint8 ap_dom_lp_mode, smc_pd_en ram_pd_en,
                                    uint8 mem_dom_idx);

/**
 * @brief ap domain ram low power configuration
 *
 * @param[in] base reg base
 * @param[in] mem_dom_idx saf power domain index,range 0~1
 * @param[in] ram_setting ram low power setting
 *
 * @return -1 if mem_dom_idx out of range, otherwise 0
 */
Std_ReturnType Mcu_SmcApRampdSettingConfig(uint32 base, uint32 ap_dom_lp_mode, uint8 ram_setting,
        uint8 mem_dom_idx);

#ifndef SEMIDRIVE_E3_LITE_SERIES
/**
 * @brief ap domain timeout configuration
 *
 * @param[in] base reg base
 * @param[in] wdt_en ap domain handshake watchdog enable
 * @param[in] tout_stage timeout monitor stage, ckgen, rstgen or mode req trans
 * @param[in] tout_val timeout value
 *
 * @return -1 if tout_stage out of range, otherwise 0
 */
Std_ReturnType Mcu_SmcApTimeoutConfig(uint32 base, boolean wdt_en, smc_handshake_stage tout_stage,
                                      uint8 tout_val);

/**
 * @brief ap domain timeout wakeup enable configuration
 *
 * @param[in] base reg base
 * @param[in] wkup_en ap domain timeout wakeup enable
 *
 */
void Mcu_SmcApTimeoutWkupConfig(uint32 base, boolean wkup_en);

/**
 * @brief ap domain misc configuration
 *
 * @param[in] base reg base
 * @param[in] wkup_en safe domain timeout wakeup enable
 *
 */
void Mcu_SmcApMiscConfig(uint32 base, boolean wkup_en, uint8 maskdly, boolean req_en);
#endif

/**********************************
* ap domain register configration *
**********************************/

/******************************
*  soc register configration  *
******************************/
/**
 * @brief soc global configuration
 *
 * @param[in] base reg base
 * @param[in] ap_off ap domain power off
 *
 */
void Mcu_SmcSocGlobalConfig(uint32 base, boolean ap_off);

/**
 * @brief soc hib mode rc24m disable configuration
 *
 * @param[in] base reg base
 * @param[in] rc_dis_en rc24m disable in hib mode
 *
 */
void Mcu_SmcSocHibrcDisConfig(uint32 base, smc_rc_dis_en rc_dis_en);

/**
 * @brief soc pre divider number for 32k configuration
 *
 * @param[in] base reg base
 * @param[in] div_num pre div number for clk32k
 *
 */
//void Mcu_SmcSoc32kDivNumConfig(uint32 base, uint8 div_num);

/**
 * @brief soc pre divider number for 24m configuration
 *
 * @param[in] base reg base
 * @param[in] div_num pre div number for clk24k
 *
 */
void Mcu_SmcSoc24mDivNumConfig(uint32 base, uint8 div_num);

/**
 * @brief soc swm timeout configuration
 *
 * @param[in] base reg base
 * @param[in] wdt_en pmu handshake watchdog enable
 * @param[in] pmu_hk timeout value for pmu handshake
 *
 */
void Mcu_SmcSocSwmTimeoutConfig(uint32 base, boolean wdt_en, uint8 pmu_hk);

/**
 * @brief soc swm timeout wakeup configuration
 *
 * @param[in] base reg base
 * @param[in] wkup_en pmu handshake timeout wakeup enable
 *
 */
void Mcu_SmcSocSwmTimeoutWkupConfig(uint32 base, boolean wkup_en);

/**
 * @brief soc wakeup acknowledge tiomeout configuration
 *
 * @param[in] base reg base
 * @param[in] tout_val timeout value for wakeup event receive to all active cpu ack done
 *
 */
void Mcu_SmcSocWkupAckTimeoutConfig(uint32 base, uint16 tout_val);

/**
 * @brief soc wakeup to run state tiomeout configuration
 *
 * @param[in] base reg base
 * @param[in] tout_val timeout value for wakeup event receive to soc goes into RUN state
 *
 */
void Mcu_SmcSocToRunTimeoutConfig(uint32 base, uint16 tout_val);

/**
 * @brief soc low power to wakeup timeout configuration
 *
 * @param[in] base reg base
 * @param[in] tout_val timeout value between low power to wakeup event receive
 * @param[in] tout_wkup_en soc low power to wakeup timeout wakeup enable
 *
 */
void Mcu_SmcSocLp2wkupTimeoutConfig(uint32 base, uint16 tout_val, boolean tout_wkup_en);

/**
 * @brief soc wakeup irq configuration
 *
 * @param[in] base reg base
 * @param[in] err_wkup_en smc error wakeup core irq enable
 * @param[in] bk_wkup_en soc wakeup core irq enable
 *
 */
void Mcu_SmcSocWkupirqWkupConfig(uint32 base, uint8 err_wkup_en, uint8 bk_wkup_en);

/**
 * @brief soc wakeup irq clear configuration
 *
 * @param[in] base reg base
 * @param[in] wkup_irq_state soc wakeup irq state before clear
 *
 */
void Mcu_SmcSocWkupirqClr(uint32 base, uint8 *wkup_irq_state);

/**
 * @brief core irq mask configuration
 *
 * @param[in] base reg base
 * @param[in] core_idx core index, range 0~4
 * @param[in] mask_val irq mask value
 *
 * @return -1 if core_idx out of range, otherwise 0
 */
Std_ReturnType Mcu_SmcCoreIrqMaskConfig(uint32 base, uint32 core_idx, uint16 mask_val);

/**
 * @brief core irq monitor configuration
 *
 * @param[in] base reg base
 * @param[in] core_idx core index, range 0~4
 * @param[in] mask_bit irq unmask value
 *
 * @return -1 if core_idx out of range, otherwise 0
 */
Std_ReturnType Mcu_SmcCoreIrqUnMaskConfig(uint32 base, uint32 core_idx, uint16 mask_bit);

/**
 * @brief core irq monitor configuration
 *
 * @param[in] base reg base
 * @param[in] core_idx core index, range 0~4
 * @param[in] irq_state pointer to core irq state
 *
 * @return -1 if core_idx out of range, otherwise 0
 */
Std_ReturnType Mcu_SmcCoreIrqMonitor(uint32 base, uint32 core_idx, uint32 *irq_state);

/**
 * @brief core irq clear configuration
 *
 * @param[in] base reg base
 * @param[in] core_idx core index, range 0~4
 * @param[in] clr_bit_mask for each bit, 1 means not clear the corresponding bit and 0 means clear
 *
 * @return -1 if core_idx out of range, otherwise 0
 */
Std_ReturnType Mcu_SmcCoreIrqClear(uint32 base, uint32 core_idx, uint32 clr_bit_mask);

/**
 * @brief common irq mask configuration
 *
 * @param[in] base reg base
 * @param[in] core_idx core index, range 0~4
 * @param[in] irq_grp_idx core index, range 0~7
 * @param[in] mask_val irq mask value
 *
 * @return -1 if core_idx,irq_grp_idx out of range, otherwise 0
 */

Std_ReturnType Mcu_SmcComIrqMaskConfig(uint32 base, uint32 core_idx, uint32 irq_grp_idx,
                                       uint32 mask_val);

/**
 * @brief common irq unmask configuration
 *
 * @param[in] base reg base
 * @param[in] core_idx core index, range 0~4
 * @param[in] irq_grp_idx core index, range 0~7
 * @param[in] mask_bit irq unmask value
 *
 * @return -1 if core_idx,irq_grp_idx out of range, otherwise 0
 */

Std_ReturnType Mcu_SmcComIrqUnMaskConfig(uint32 base, uint32 core_idx, uint32 irq_grp_idx,
        uint32 mask_bit);

/**
 * @brief common irq monitor configuration
 *
 * @param[in] base reg base
 * @param[in] irq_grp_idx irq group index, range 0~7
 * @param[in] irq_state pointer to common irq state
 *
 * @return -1 if irq_grp_idx out of range, otherwise 0
 */
Std_ReturnType Mcu_SmcComIrqMonitor(uint32 base, uint32 irq_grp_idx, uint32 *irq_state);

/**
 * @brief common irq clear configuration
 *
 * @param[in] base reg base
 * @param[in] irq_grp_idx core index, range 0~7
 * @param[in] clr_bit_mask for each bit, 1 means not clear the corresponding bit and 0 means clear
 *
 * @return -1 if irq_grp_idx out of range, otherwise 0
 */
Std_ReturnType Mcu_SmcComIrqClear(uint32 base, uint32 irq_grp_idx, uint32 clr_bit_mask);

/**
 * @brief get swm status
 * @param[in] base reg base
 * @return value saf, ap and soc lowpower status
 */
uint32 Mcu_SmcGetSmwMonitorStatus(uint32 base);

/**
 * @brief pmu sw swm mode set
 * @param[in] base reg base
 * @param[in] set debug mux select
 */
void Mcu_SmcSetPmuSwSwmMode(uint32 base, uint32 wdata);

/**
 * @brief swm debug mux select
 * @param[in] base reg base
 * @param[in] set debug mux select
 */
void Mcu_SmcSetDebugMuxSelectMode(uint32 base, uint32 wdata);

/**
 * @brief get swm debug status
 * @param[in] base reg base
 * @return value saf, ap handshake status
 */
uint32 Mcu_SmcGetDebugMonitorStatus(uint32 base);

/**
 * @brief polling sw swm handshake result and clear it
 * @param[in] base reg base
 */
void Mcu_SmcPollingPmuSwSwmResult(uint32 base);

/**
 * @brief set sw swm enable/disable
 * @param[in] base reg base
 * @param[in] enable enable/disable
 */
void Mcu_SmcSetPmuSwSwmEnable(uint32 base, boolean enable);

/**
 * @brief configure smc timeout
 * @param[in] base reg base
 */
void Mcu_SmcSetTimeoutConfig(uint32 base);

/******************************
*  soc register configration  *
******************************/

#ifdef __cplusplus
}
#endif

#endif  /* __MCU_SMC_H__ */
