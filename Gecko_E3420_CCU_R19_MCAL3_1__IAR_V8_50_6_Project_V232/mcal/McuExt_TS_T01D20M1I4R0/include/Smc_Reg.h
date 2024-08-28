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

#ifndef SMC_REG_H
#define SMC_REG_H

#ifdef __cplusplus
extern "C" {
#endif
/* Version and Check Begin */
/* Version Info Begin */
#define SMC_REG_H_VENDOR_ID    0x8C
#define SMC_REG_H_AR_RELEASE_MAJOR_VERSION    4
#define SMC_REG_H_AR_RELEASE_MINOR_VERSION    3
#define SMC_REG_H_AR_RELEASE_REVISION_VERSION 1
#define SMC_REG_H_SW_MAJOR_VERSION    1
#define SMC_REG_H_SW_MINOR_VERSION    0
#define SMC_REG_H_SW_PATCH_VERSION    0
/* Version Info End */
/* Version and Check End */

/* Register define Start */
//--------------------------------------------------------------------------
// Register Name   : DOM_PER0_OFF
// Register Offset : 0x0
// Description     : This register is used for to control domain0~3 secure and priviledge access permission.
//--------------------------------------------------------------------------
#define DOM_PER0_OFF(n) (0x0U + (12U*(n)))

#define FM_DOM_PER0_DOM3_USE_PER    (0x3U << 30U)
#define FV_DOM_PER0_DOM3_USE_PER(v) \
    (((v) << 30U) & FM_DOM_PER0_DOM3_USE_PER)
#define GFV_DOM_PER0_DOM3_USE_PER(v) \
    (((v) & FM_DOM_PER0_DOM3_USE_PER) >> 30U)

#define FM_DOM_PER0_DOM3_PRI_PER    (0x3U << 28U)
#define FV_DOM_PER0_DOM3_PRI_PER(v) \
    (((v) << 28U) & FM_DOM_PER0_DOM3_PRI_PER)
#define GFV_DOM_PER0_DOM3_PRI_PER(v) \
    (((v) & FM_DOM_PER0_DOM3_PRI_PER) >> 28U)

#define FM_DOM_PER0_DOM3_NSE_PER    (0x3U << 26U)
#define FV_DOM_PER0_DOM3_NSE_PER(v) \
    (((v) << 26U) & FM_DOM_PER0_DOM3_NSE_PER)
#define GFV_DOM_PER0_DOM3_NSE_PER(v) \
    (((v) & FM_DOM_PER0_DOM3_NSE_PER) >> 26U)

#define FM_DOM_PER0_DOM3_SEC_PER    (0x3U << 24U)
#define FV_DOM_PER0_DOM3_SEC_PER(v) \
    (((v) << 24U) & FM_DOM_PER0_DOM3_SEC_PER)
#define GFV_DOM_PER0_DOM3_SEC_PER(v) \
    (((v) & FM_DOM_PER0_DOM3_SEC_PER) >> 24U)

#define FM_DOM_PER0_DOM2_USE_PER    (0x3U << 22U)
#define FV_DOM_PER0_DOM2_USE_PER(v) \
    (((v) << 22U) & FM_DOM_PER0_DOM2_USE_PER)
#define GFV_DOM_PER0_DOM2_USE_PER(v) \
    (((v) & FM_DOM_PER0_DOM2_USE_PER) >> 22U)

#define FM_DOM_PER0_DOM2_PRI_PER    (0x3U << 20U)
#define FV_DOM_PER0_DOM2_PRI_PER(v) \
    (((v) << 20U) & FM_DOM_PER0_DOM2_PRI_PER)
#define GFV_DOM_PER0_DOM2_PRI_PER(v) \
    (((v) & FM_DOM_PER0_DOM2_PRI_PER) >> 20U)

#define FM_DOM_PER0_DOM2_NSE_PER    (0x3U << 18U)
#define FV_DOM_PER0_DOM2_NSE_PER(v) \
    (((v) << 18U) & FM_DOM_PER0_DOM2_NSE_PER)
#define GFV_DOM_PER0_DOM2_NSE_PER(v) \
    (((v) & FM_DOM_PER0_DOM2_NSE_PER) >> 18U)

#define FM_DOM_PER0_DOM2_SEC_PER    (0x3U << 16U)
#define FV_DOM_PER0_DOM2_SEC_PER(v) \
    (((v) << 16U) & FM_DOM_PER0_DOM2_SEC_PER)
#define GFV_DOM_PER0_DOM2_SEC_PER(v) \
    (((v) & FM_DOM_PER0_DOM2_SEC_PER) >> 16U)

#define FM_DOM_PER0_DOM1_USE_PER    (0x3U << 14U)
#define FV_DOM_PER0_DOM1_USE_PER(v) \
    (((v) << 14U) & FM_DOM_PER0_DOM1_USE_PER)
#define GFV_DOM_PER0_DOM1_USE_PER(v) \
    (((v) & FM_DOM_PER0_DOM1_USE_PER) >> 14U)

#define FM_DOM_PER0_DOM1_PRI_PER    (0x3U << 12U)
#define FV_DOM_PER0_DOM1_PRI_PER(v) \
    (((v) << 12U) & FM_DOM_PER0_DOM1_PRI_PER)
#define GFV_DOM_PER0_DOM1_PRI_PER(v) \
    (((v) & FM_DOM_PER0_DOM1_PRI_PER) >> 12U)

#define FM_DOM_PER0_DOM1_NSE_PER    (0x3U << 10U)
#define FV_DOM_PER0_DOM1_NSE_PER(v) \
    (((v) << 10U) & FM_DOM_PER0_DOM1_NSE_PER)
#define GFV_DOM_PER0_DOM1_NSE_PER(v) \
    (((v) & FM_DOM_PER0_DOM1_NSE_PER) >> 10U)

#define FM_DOM_PER0_DOM1_SEC_PER    (0x3U << 8U)
#define FV_DOM_PER0_DOM1_SEC_PER(v) \
    (((v) << 8U) & FM_DOM_PER0_DOM1_SEC_PER)
#define GFV_DOM_PER0_DOM1_SEC_PER(v) \
    (((v) & FM_DOM_PER0_DOM1_SEC_PER) >> 8U)

#define FM_DOM_PER0_DOM0_USE_PER    (0x3U << 6U)
#define FV_DOM_PER0_DOM0_USE_PER(v) \
    (((v) << 6U) & FM_DOM_PER0_DOM0_USE_PER)
#define GFV_DOM_PER0_DOM0_USE_PER(v) \
    (((v) & FM_DOM_PER0_DOM0_USE_PER) >> 6U)

#define FM_DOM_PER0_DOM0_PRI_PER    (0x3U << 4U)
#define FV_DOM_PER0_DOM0_PRI_PER(v) \
    (((v) << 4U) & FM_DOM_PER0_DOM0_PRI_PER)
#define GFV_DOM_PER0_DOM0_PRI_PER(v) \
    (((v) & FM_DOM_PER0_DOM0_PRI_PER) >> 4U)

#define FM_DOM_PER0_DOM0_NSE_PER    (0x3U << 2U)
#define FV_DOM_PER0_DOM0_NSE_PER(v) \
    (((v) << 2U) & FM_DOM_PER0_DOM0_NSE_PER)
#define GFV_DOM_PER0_DOM0_NSE_PER(v) \
    (((v) & FM_DOM_PER0_DOM0_NSE_PER) >> 2U)

#define FM_DOM_PER0_DOM0_SEC_PER    (0x3U << 0U)
#define FV_DOM_PER0_DOM0_SEC_PER(v) \
    (((v) << 0U) & FM_DOM_PER0_DOM0_SEC_PER)
#define GFV_DOM_PER0_DOM0_SEC_PER(v) \
    (((v) & FM_DOM_PER0_DOM0_SEC_PER) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : DOM_PER1_OFF
// Register Offset : 0x4
// Description     : This register is used for to control domain4~7 secure and priviledge access permission.
//--------------------------------------------------------------------------
#define DOM_PER1_OFF(n) (0x4U + (12U*(n)))

#define FM_DOM_PER1_DOM7_USE_PER    (0x3U << 30U)
#define FV_DOM_PER1_DOM7_USE_PER(v) \
    (((v) << 30U) & FM_DOM_PER1_DOM7_USE_PER)
#define GFV_DOM_PER1_DOM7_USE_PER(v) \
    (((v) & FM_DOM_PER1_DOM7_USE_PER) >> 30U)

#define FM_DOM_PER1_DOM7_PRI_PER    (0x3U << 28U)
#define FV_DOM_PER1_DOM7_PRI_PER(v) \
    (((v) << 28U) & FM_DOM_PER1_DOM7_PRI_PER)
#define GFV_DOM_PER1_DOM7_PRI_PER(v) \
    (((v) & FM_DOM_PER1_DOM7_PRI_PER) >> 28U)

#define FM_DOM_PER1_DOM7_NSE_PER    (0x3U << 26U)
#define FV_DOM_PER1_DOM7_NSE_PER(v) \
    (((v) << 26U) & FM_DOM_PER1_DOM7_NSE_PER)
#define GFV_DOM_PER1_DOM7_NSE_PER(v) \
    (((v) & FM_DOM_PER1_DOM7_NSE_PER) >> 26U)

#define FM_DOM_PER1_DOM7_SEC_PER    (0x3U << 24U)
#define FV_DOM_PER1_DOM7_SEC_PER(v) \
    (((v) << 24U) & FM_DOM_PER1_DOM7_SEC_PER)
#define GFV_DOM_PER1_DOM7_SEC_PER(v) \
    (((v) & FM_DOM_PER1_DOM7_SEC_PER) >> 24U)

#define FM_DOM_PER1_DOM6_USE_PER    (0x3U << 22U)
#define FV_DOM_PER1_DOM6_USE_PER(v) \
    (((v) << 22U) & FM_DOM_PER1_DOM6_USE_PER)
#define GFV_DOM_PER1_DOM6_USE_PER(v) \
    (((v) & FM_DOM_PER1_DOM6_USE_PER) >> 22U)

#define FM_DOM_PER1_DOM6_PRI_PER    (0x3U << 20U)
#define FV_DOM_PER1_DOM6_PRI_PER(v) \
    (((v) << 20U) & FM_DOM_PER1_DOM6_PRI_PER)
#define GFV_DOM_PER1_DOM6_PRI_PER(v) \
    (((v) & FM_DOM_PER1_DOM6_PRI_PER) >> 20U)

#define FM_DOM_PER1_DOM6_NSE_PER    (0x3U << 18U)
#define FV_DOM_PER1_DOM6_NSE_PER(v) \
    (((v) << 18U) & FM_DOM_PER1_DOM6_NSE_PER)
#define GFV_DOM_PER1_DOM6_NSE_PER(v) \
    (((v) & FM_DOM_PER1_DOM6_NSE_PER) >> 18U)

#define FM_DOM_PER1_DOM6_SEC_PER    (0x3U << 16U)
#define FV_DOM_PER1_DOM6_SEC_PER(v) \
    (((v) << 16U) & FM_DOM_PER1_DOM6_SEC_PER)
#define GFV_DOM_PER1_DOM6_SEC_PER(v) \
    (((v) & FM_DOM_PER1_DOM6_SEC_PER) >> 16U)

#define FM_DOM_PER1_DOM5_USE_PER    (0x3U << 14U)
#define FV_DOM_PER1_DOM5_USE_PER(v) \
    (((v) << 14U) & FM_DOM_PER1_DOM5_USE_PER)
#define GFV_DOM_PER1_DOM5_USE_PER(v) \
    (((v) & FM_DOM_PER1_DOM5_USE_PER) >> 14U)

#define FM_DOM_PER1_DOM5_PRI_PER    (0x3U << 12U)
#define FV_DOM_PER1_DOM5_PRI_PER(v) \
    (((v) << 12U) & FM_DOM_PER1_DOM5_PRI_PER)
#define GFV_DOM_PER1_DOM5_PRI_PER(v) \
    (((v) & FM_DOM_PER1_DOM5_PRI_PER) >> 12U)

#define FM_DOM_PER1_DOM5_NSE_PER    (0x3U << 10U)
#define FV_DOM_PER1_DOM5_NSE_PER(v) \
    (((v) << 10U) & FM_DOM_PER1_DOM5_NSE_PER)
#define GFV_DOM_PER1_DOM5_NSE_PER(v) \
    (((v) & FM_DOM_PER1_DOM5_NSE_PER) >> 10U)

#define FM_DOM_PER1_DOM5_SEC_PER    (0x3U << 8U)
#define FV_DOM_PER1_DOM5_SEC_PER(v) \
    (((v) << 8U) & FM_DOM_PER1_DOM5_SEC_PER)
#define GFV_DOM_PER1_DOM5_SEC_PER(v) \
    (((v) & FM_DOM_PER1_DOM5_SEC_PER) >> 8U)

#define FM_DOM_PER1_DOM4_USE_PER    (0x3U << 6U)
#define FV_DOM_PER1_DOM4_USE_PER(v) \
    (((v) << 6U) & FM_DOM_PER1_DOM4_USE_PER)
#define GFV_DOM_PER1_DOM4_USE_PER(v) \
    (((v) & FM_DOM_PER1_DOM4_USE_PER) >> 6U)

#define FM_DOM_PER1_DOM4_PRI_PER    (0x3U << 4U)
#define FV_DOM_PER1_DOM4_PRI_PER(v) \
    (((v) << 4U) & FM_DOM_PER1_DOM4_PRI_PER)
#define GFV_DOM_PER1_DOM4_PRI_PER(v) \
    (((v) & FM_DOM_PER1_DOM4_PRI_PER) >> 4U)

#define FM_DOM_PER1_DOM4_NSE_PER    (0x3U << 2U)
#define FV_DOM_PER1_DOM4_NSE_PER(v) \
    (((v) << 2U) & FM_DOM_PER1_DOM4_NSE_PER)
#define GFV_DOM_PER1_DOM4_NSE_PER(v) \
    (((v) & FM_DOM_PER1_DOM4_NSE_PER) >> 2U)

#define FM_DOM_PER1_DOM4_SEC_PER    (0x3U << 0U)
#define FV_DOM_PER1_DOM4_SEC_PER(v) \
    (((v) << 0U) & FM_DOM_PER1_DOM4_SEC_PER)
#define GFV_DOM_PER1_DOM4_SEC_PER(v) \
    (((v) & FM_DOM_PER1_DOM4_SEC_PER) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : DOM_PER_LOCK_OFF
// Register Offset : 0x8
// Description     : This register is used to lock domain access permission setting.
//--------------------------------------------------------------------------
#define DOM_PER_LOCK_OFF(n) (0x8U + (12U*(n)))

#define BM_DOM_PER_LOCK_DOM7_LOCK   (0x01U << 7U)

#define BM_DOM_PER_LOCK_DOM6_LOCK   (0x01U << 6U)

#define BM_DOM_PER_LOCK_DOM5_LOCK   (0x01U << 5U)

#define BM_DOM_PER_LOCK_DOM4_LOCK   (0x01U << 4U)

#define BM_DOM_PER_LOCK_DOM3_LOCK   (0x01U << 3U)

#define BM_DOM_PER_LOCK_DOM2_LOCK   (0x01U << 2U)

#define BM_DOM_PER_LOCK_DOM1_LOCK   (0x01U << 1U)

#define BM_DOM_PER_LOCK_DOM0_LOCK   (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : SAF_DOM_RS_OFF
// Register Offset : 0x200
// Description     : This register is used for assign rule space for safe domain control
//--------------------------------------------------------------------------
#define SAF_DOM_RS_OFF  0x200U

#define BM_SAF_DOM_RS_LOCK  (0x01U << 31U)

#define FM_SAF_DOM_RS_RS    (0xfU << 1U)
#define FV_SAF_DOM_RS_RS(v) \
    (((v) << 1U) & FM_SAF_DOM_RS_RS)
#define GFV_SAF_DOM_RS_RS(v) \
    (((v) & FM_SAF_DOM_RS_RS) >> 1U)

#define BM_SAF_DOM_RS_EN    (0x01U << 0U)

#define AP_DOM_RS_OFF           0x204U

#define BM_AP_DOM_RS_LOCK   (0x01U << 31U)

#define FM_AP_DOM_RS_RS (0xfU << 1U)
#define FV_AP_DOM_RS_RS(v) \
    (((v) << 1U) & FM_AP_DOM_RS_RS)
#define GFV_AP_DOM_RS_RS(v) \
    (((v) & FM_AP_DOM_RS_RS) >> 1U)

#define BM_AP_DOM_RS_EN (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : SOC_DOM_RS_OFF
// Register Offset : 0x208
// Description     : This register is used for assign rule space for soc domain control
//--------------------------------------------------------------------------
#define SOC_DOM_RS_OFF  0x208U

#define BM_SOC_DOM_RS_LOCK  (0x01U << 31U)

#define FM_SOC_DOM_RS_RS    (0xfU << 1U)
#define FV_SOC_DOM_RS_RS(v) \
    (((v) << 1U) & FM_SOC_DOM_RS_RS)
#define GFV_SOC_DOM_RS_RS(v) \
    (((v) & FM_SOC_DOM_RS_RS) >> 1U)

#define BM_SOC_DOM_RS_EN    (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : SAF_GLB_CTL_OFF
// Register Offset : 0x1000
// Description     : SAFE DOMAIN GLOBAL CONTROL REGISTER
//--------------------------------------------------------------------------
#define SAF_GLB_CTL_OFF 0x1000U

#define BM_SAF_GLB_CTL_WFI_DIS  (0x01U << 8U)

#define BM_SAF_GLB_CTL_LP_MODE  (0x01U << 3U)

#define FM_SAF_GLB_CTL_PRI_CORE (0x7U << 0U)
#define FV_SAF_GLB_CTL_PRI_CORE(v) \
    (((v) << 0U) & FM_SAF_GLB_CTL_PRI_CORE)
#define GFV_SAF_GLB_CTL_PRI_CORE(v) \
    (((v) & FM_SAF_GLB_CTL_PRI_CORE) >> 0U)

#define SAF_LP_CTL_OFF(n)   (0x1008U + 8U*(n))

#define BM_SAF_LP_CTL_SW_PWR_GATE   (0x01U << 4U)

#define BM_SAF_LP_CTL_SW_ISO_EN (0x01U << 3U)

#define BM_SAF_LP_CTL_SW_PD_EN  (0x01U << 2U)

#define BM_SAF_LP_CTL_HIB_PD_EN (0x01U << 1U)

#define BM_SAF_LP_CTL_SLP_PD_EN (0x01U << 0U)

#define SAF_LP_DLY_CTL_OFF(n)   (0x100cU + 8U*(n))

#define FM_SAF_LP_DLY_CTL_ISO_DIS   (0xffU << 12U)
#define FV_SAF_LP_DLY_CTL_ISO_DIS(v) \
    (((v) << 12U) & FM_SAF_LP_DLY_CTL_ISO_DIS)
#define GFV_SAF_LP_DLY_CTL_ISO_DIS(v) \
    (((v) & FM_SAF_LP_DLY_CTL_ISO_DIS) >> 12U)

#define FM_SAF_LP_DLY_CTL_PO    (0xfU << 8U)
#define FV_SAF_LP_DLY_CTL_PO(v) \
    (((v) << 8U) & FM_SAF_LP_DLY_CTL_PO)
#define GFV_SAF_LP_DLY_CTL_PO(v) \
    (((v) & FM_SAF_LP_DLY_CTL_PO) >> 8U)

#define FM_SAF_LP_DLY_CTL_PG    (0xfU << 4U)
#define FV_SAF_LP_DLY_CTL_PG(v) \
    (((v) << 4U) & FM_SAF_LP_DLY_CTL_PG)
#define GFV_SAF_LP_DLY_CTL_PG(v) \
    (((v) & FM_SAF_LP_DLY_CTL_PG) >> 4U)

#define FM_SAF_LP_DLY_CTL_ISO_EN    (0xfU << 0U)
#define FV_SAF_LP_DLY_CTL_ISO_EN(v) \
    (((v) << 0U) & FM_SAF_LP_DLY_CTL_ISO_EN)
#define GFV_SAF_LP_DLY_CTL_ISO_EN(v) \
    (((v) & FM_SAF_LP_DLY_CTL_ISO_EN) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : SAF_RAM_LP_CTL_OFF
// Register Offset : 0x1060
// Description     : SAFE DOMAIN RAM LOW POWER CONTROL REGISTER
//--------------------------------------------------------------------------
#define SAF_RAM_LP_CTL_OFF(n)   (0x1060U + 4U*(n))

#define FM_SAF_RAM_LP_CTL_SW_RAM_LP_SETTING (0x7U << 9U)
#define FV_SAF_RAM_LP_CTL_SW_RAM_LP_SETTING(v) \
    (((v) << 9U) & FM_SAF_RAM_LP_CTL_SW_RAM_LP_SETTING)
#define GFV_SAF_RAM_LP_CTL_SW_RAM_LP_SETTING(v) \
    (((v) & FM_SAF_RAM_LP_CTL_SW_RAM_LP_SETTING) >> 9U)

#define FM_SAF_RAM_LP_CTL_HIB_RAM_LP_SETTING    (0x7U << 6U)
#define FV_SAF_RAM_LP_CTL_HIB_RAM_LP_SETTING(v) \
    (((v) << 6U) & FM_SAF_RAM_LP_CTL_HIB_RAM_LP_SETTING)
#define GFV_SAF_RAM_LP_CTL_HIB_RAM_LP_SETTING(v) \
    (((v) & FM_SAF_RAM_LP_CTL_HIB_RAM_LP_SETTING) >> 6U)

#define FM_SAF_RAM_LP_CTL_SLP_RAM_LP_SETTING    (0x7U << 3U)
#define FV_SAF_RAM_LP_CTL_SLP_RAM_LP_SETTING(v) \
    (((v) << 3U) & FM_SAF_RAM_LP_CTL_SLP_RAM_LP_SETTING)
#define GFV_SAF_RAM_LP_CTL_SLP_RAM_LP_SETTING(v) \
    (((v) & FM_SAF_RAM_LP_CTL_SLP_RAM_LP_SETTING) >> 3U)

#define BM_SAF_RAM_LP_CTL_SW_RAM_PD_EN  (0x01U << 2U)

#define BM_SAF_RAM_LP_CTL_HIB_RAM_PD_EN (0x01U << 1U)

#define BM_SAF_RAM_LP_CTL_SLP_RAM_PD_EN (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : SAF_TIMEOUT_OFF
// Register Offset : 0x1114
// Description     : SAFE DOMAIN TIMEOUT SETTING REGISTER
//--------------------------------------------------------------------------
#define SAF_TIMEOUT_OFF     0x1114U

#define BM_SAF_TIMEOUT_WKUP_EN  (0x01U << 31U)

#define BM_SAF_TIMEOUT_WDT_EN   (0x01U << 30U)

#define FM_SAF_TIMEOUT_CKGEN_HK (0xffU << 16U)
#define FV_SAF_TIMEOUT_CKGEN_HK(v) \
    (((v) << 16U) & FM_SAF_TIMEOUT_CKGEN_HK)
#define GFV_SAF_TIMEOUT_CKGEN_HK(v) \
    (((v) & FM_SAF_TIMEOUT_CKGEN_HK) >> 16U)

#define FM_SAF_TIMEOUT_RSTGEN_HK    (0xffU << 8U)
#define FV_SAF_TIMEOUT_RSTGEN_HK(v) \
    (((v) << 8U) & FM_SAF_TIMEOUT_RSTGEN_HK)
#define GFV_SAF_TIMEOUT_RSTGEN_HK(v) \
    (((v) & FM_SAF_TIMEOUT_RSTGEN_HK) >> 8U)

#define FM_SAF_TIMEOUT_MODE_REQ_TRANS   (0xffU << 0U)
#define FV_SAF_TIMEOUT_MODE_REQ_TRANS(v) \
    (((v) << 0U) & FM_SAF_TIMEOUT_MODE_REQ_TRANS)
#define GFV_SAF_TIMEOUT_MODE_REQ_TRANS(v) \
    (((v) & FM_SAF_TIMEOUT_MODE_REQ_TRANS) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : SAF_MISC_OFF
// Register Offset : 0x1118
// Description     : SAFE DOMAIN MISC REGISTER
//--------------------------------------------------------------------------
#define SAF_MISC_OFF        0x1118U

#define BM_SAF_MISC_ILL_TRANS_WKUP_EN   (0x01U << 9U)

#define FM_SAF_MISC_IRQ_MASK_DLY    (0xffU << 1U)
#define FV_SAF_MISC_IRQ_MASK_DLY(v) \
    (((v) << 1U) & FM_SAF_MISC_IRQ_MASK_DLY)
#define GFV_SAF_MISC_IRQ_MASK_DLY(v) \
    (((v) & FM_SAF_MISC_IRQ_MASK_DLY) >> 1U)

#define BM_SAF_MISC_LP_TRANS_REQ    (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : AP_GLB_CTL_OFF
// Register Offset : 0x1200
// Description     : AP DOMAIN GLOBAL CONTROL REGISTER
//--------------------------------------------------------------------------
#define AP_GLB_CTL_OFF      0x1200U

#define BM_AP_GLB_CTL_WFI_DIS   (0x01U << 8U)

#define BM_AP_GLB_CTL_WKUP_ALIGN2SAF    (0x01U << 5U)

#define BM_AP_GLB_CTL_LP_ALIGN2SAF  (0x01U << 4U)

#define BM_AP_GLB_CTL_LP_MODE   (0x01U << 3U)

#define FM_AP_GLB_CTL_PRI_CORE  (0x7U << 0U)
#define FV_AP_GLB_CTL_PRI_CORE(v) \
    (((v) << 0U) & FM_AP_GLB_CTL_PRI_CORE)
#define GFV_AP_GLB_CTL_PRI_CORE(v) \
    (((v) & FM_AP_GLB_CTL_PRI_CORE) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : AP_LP_CTL_OFF
// Register Offset : 0x1208
// Description     : AP DOMAIN LOW POWER CONTROL REGISTER
//--------------------------------------------------------------------------
#define AP_LP_CTL_OFF(n)        (0x1208U + 8U*(n))

#define BM_AP_LP_CTL_SW_PWR_GATE    (0x01U << 4U)

#define BM_AP_LP_CTL_SW_ISO_EN  (0x01U << 3U)

#define BM_AP_LP_CTL_SW_PD_EN   (0x01U << 2U)

#define BM_AP_LP_CTL_HIB_PD_EN  (0x01U << 1U)

#define BM_AP_LP_CTL_SLP_PD_EN  (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : AP_LP_DLY_CTL_OFF
// Register Offset : 0x120c
// Description     : AP DOMAIN LOW POWER DELAY CONTROL REGISTER
//--------------------------------------------------------------------------
#define AP_LP_DLY_CTL_OFF(n)    (0x120cU + 8U*(n))

#define FM_AP_LP_DLY_CTL_ISO_DIS    (0xffU << 12U)
#define FV_AP_LP_DLY_CTL_ISO_DIS(v) \
    (((v) << 12U) & FM_AP_LP_DLY_CTL_ISO_DIS)
#define GFV_AP_LP_DLY_CTL_ISO_DIS(v) \
    (((v) & FM_AP_LP_DLY_CTL_ISO_DIS) >> 12U)

#define FM_AP_LP_DLY_CTL_PO (0xfU << 8U)
#define FV_AP_LP_DLY_CTL_PO(v) \
    (((v) << 8U) & FM_AP_LP_DLY_CTL_PO)
#define GFV_AP_LP_DLY_CTL_PO(v) \
    (((v) & FM_AP_LP_DLY_CTL_PO) >> 8U)

#define FM_AP_LP_DLY_CTL_PG (0xfU << 4U)
#define FV_AP_LP_DLY_CTL_PG(v) \
    (((v) << 4U) & FM_AP_LP_DLY_CTL_PG)
#define GFV_AP_LP_DLY_CTL_PG(v) \
    (((v) & FM_AP_LP_DLY_CTL_PG) >> 4U)

#define FM_AP_LP_DLY_CTL_ISO_EN (0xfU << 0U)
#define FV_AP_LP_DLY_CTL_ISO_EN(v) \
    (((v) << 0U) & FM_AP_LP_DLY_CTL_ISO_EN)
#define GFV_AP_LP_DLY_CTL_ISO_EN(v) \
    (((v) & FM_AP_LP_DLY_CTL_ISO_EN) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : AP_RAM_LP_CTL_OFF
// Register Offset : 0x1260
// Description     : AP DOMAIN RAM LOW POWER CONTROL REGISTER
//--------------------------------------------------------------------------
#define AP_RAM_LP_CTL_OFF(n)        (0x1260U + 4U*(n))

#define FM_AP_RAM_LP_CTL_SW_RAM_LP_SETTING  (0x7U << 9U)
#define FV_AP_RAM_LP_CTL_SW_RAM_LP_SETTING(v) \
    (((v) << 9U) & FM_AP_RAM_LP_CTL_SW_RAM_LP_SETTING)
#define GFV_AP_RAM_LP_CTL_SW_RAM_LP_SETTING(v) \
    (((v) & FM_AP_RAM_LP_CTL_SW_RAM_LP_SETTING) >> 9U)

#define FM_AP_RAM_LP_CTL_HIB_RAM_LP_SETTING (0x7U << 6U)
#define FV_AP_RAM_LP_CTL_HIB_RAM_LP_SETTING(v) \
    (((v) << 6U) & FM_AP_RAM_LP_CTL_HIB_RAM_LP_SETTING)
#define GFV_AP_RAM_LP_CTL_HIB_RAM_LP_SETTING(v) \
    (((v) & FM_AP_RAM_LP_CTL_HIB_RAM_LP_SETTING) >> 6U)

#define FM_AP_RAM_LP_CTL_SLP_RAM_LP_SETTING (0x7U << 3U)
#define FV_AP_RAM_LP_CTL_SLP_RAM_LP_SETTING(v) \
    (((v) << 3U) & FM_AP_RAM_LP_CTL_SLP_RAM_LP_SETTING)
#define GFV_AP_RAM_LP_CTL_SLP_RAM_LP_SETTING(v) \
    (((v) & FM_AP_RAM_LP_CTL_SLP_RAM_LP_SETTING) >> 3U)

#define BM_AP_RAM_LP_CTL_SW_RAM_PD_EN   (0x01U << 2U)

#define BM_AP_RAM_LP_CTL_HIB_RAM_PD_EN  (0x01U << 1U)

#define BM_AP_RAM_LP_CTL_SLP_RAM_PD_EN  (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : AP_TIMEOUT_OFF
// Register Offset : 0x1314
// Description     : AP DOMAIN TIMEOUT SETTING REGISTER
//--------------------------------------------------------------------------
#define AP_TIMEOUT_OFF      0x1314U

#define BM_AP_TIMEOUT_WKUP_EN   (0x01U << 31U)

#define BM_AP_TIMEOUT_WDT_EN    (0x01U << 30U)

#define FM_AP_TIMEOUT_CKGEN_HK  (0xffU << 16U)
#define FV_AP_TIMEOUT_CKGEN_HK(v) \
    (((v) << 16U) & FM_AP_TIMEOUT_CKGEN_HK)
#define GFV_AP_TIMEOUT_CKGEN_HK(v) \
    (((v) & FM_AP_TIMEOUT_CKGEN_HK) >> 16U)

#define FM_AP_TIMEOUT_RSTGEN_HK (0xffU << 8U)
#define FV_AP_TIMEOUT_RSTGEN_HK(v) \
    (((v) << 8U) & FM_AP_TIMEOUT_RSTGEN_HK)
#define GFV_AP_TIMEOUT_RSTGEN_HK(v) \
    (((v) & FM_AP_TIMEOUT_RSTGEN_HK) >> 8U)

#define FM_AP_TIMEOUT_MODE_REQ_TRANS    (0xffU << 0U)
#define FV_AP_TIMEOUT_MODE_REQ_TRANS(v) \
    (((v) << 0U) & FM_AP_TIMEOUT_MODE_REQ_TRANS)
#define GFV_AP_TIMEOUT_MODE_REQ_TRANS(v) \
    (((v) & FM_AP_TIMEOUT_MODE_REQ_TRANS) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : AP_MISC_OFF
// Register Offset : 0x1318
// Description     : AP DOMAIN MISC REGISTER
//--------------------------------------------------------------------------
#define AP_MISC_OFF         0x1318U

#define BM_AP_MISC_ILL_TRANS_WKUP_EN    (0x01U << 9U)

#define FM_AP_MISC_IRQ_MASK_DLY (0xffU << 1U)
#define FV_AP_MISC_IRQ_MASK_DLY(v) \
    (((v) << 1U) & FM_AP_MISC_IRQ_MASK_DLY)
#define GFV_AP_MISC_IRQ_MASK_DLY(v) \
    (((v) & FM_AP_MISC_IRQ_MASK_DLY) >> 1U)

#define BM_AP_MISC_LP_TRANS_REQ (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : SOC_GLB_CTL_OFF
// Register Offset : 0x1400
// Description     : SOC GLOBAL CONTROL REGISTER
//--------------------------------------------------------------------------
#define SOC_GLB_CTL_OFF         0x1400U

#define BM_SOC_GLB_CTL_AP_OFF   (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : SOC_HIB_RC_DIS_OFF
// Register Offset : 0x1404
// Description     : SOC HIB MODE RC24M DISABLE REGISTER
//--------------------------------------------------------------------------
#define SOC_HIB_RC_DIS_OFF      0x1404U

#define BM_SOC_HIB_RC_DIS_RC_DIS_EN (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : SOC_PRE_DIV_OFF
// Register Offset : 0x1408
// Description     : SOC PRE DIVIDER NUMBER REGISTER
//--------------------------------------------------------------------------
#define SOC_PRE_DIV_OFF         0x1408U

#define FM_SOC_PRE_DIV_DIV_NUM_32K  (0x3ffU << 8U)
#define FV_SOC_PRE_DIV_DIV_NUM_32K(v) \
    (((v) << 8U) & FM_SOC_PRE_DIV_DIV_NUM_32K)
#define GFV_SOC_PRE_DIV_DIV_NUM_32K(v) \
    (((v) & FM_SOC_PRE_DIV_DIV_NUM_32K) >> 8U)

#define FM_SOC_PRE_DIV_DIV_NUM_24M  (0xffU << 0U)
#define FV_SOC_PRE_DIV_DIV_NUM_24M(v) \
    (((v) << 0U) & FM_SOC_PRE_DIV_DIV_NUM_24M)
#define GFV_SOC_PRE_DIV_DIV_NUM_24M(v) \
    (((v) & FM_SOC_PRE_DIV_DIV_NUM_24M) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : SOC_SWM_TIMEOUT_OFF
// Register Offset : 0x140c
// Description     : SWM TIMEOUT SETTING REGISTER
//--------------------------------------------------------------------------
#define SOC_SWM_TIMEOUT_OFF         0x140cU

#define BM_SOC_SWM_TIMEOUT_WKUP_EN  (0x01U << 31U)

#define BM_SOC_SWM_TIMEOUT_WDT_EN   (0x01U << 30U)

#define FM_SOC_SWM_TIMEOUT_PMU_HK   (0xffU << 0U)
#define FV_SOC_SWM_TIMEOUT_PMU_HK(v) \
    (((v) << 0U) & FM_SOC_SWM_TIMEOUT_PMU_HK)
#define GFV_SOC_SWM_TIMEOUT_PMU_HK(v) \
    (((v) & FM_SOC_SWM_TIMEOUT_PMU_HK) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : SOC_WKUP_CTL_OFF
// Register Offset : 0x1410
// Description     : SOC WAKEUP CONTROL REGISTER
//--------------------------------------------------------------------------
#define SOC_WKUP_CTL_OFF    0x1410U

#define BM_SOC_WKUP_CTL_LP2WKUP_TOUT_WKUP_EN    (0x01U << 31U)

#define BM_SOC_WKUP_CTL_WKUP_WDT_EN (0x01U << 23U)

#define FM_SOC_WKUP_CTL_SW_WKUP_ACK (0x1fU << 18U)
#define FV_SOC_WKUP_CTL_SW_WKUP_ACK(v) \
    (((v) << 18U) & FM_SOC_WKUP_CTL_SW_WKUP_ACK)
#define GFV_SOC_WKUP_CTL_SW_WKUP_ACK(v) \
    (((v) & FM_SOC_WKUP_CTL_SW_WKUP_ACK) >> 18U)

#define BM_SOC_WKUP_CTL_WKUP_DONE_SRC_SEL   (0x01U << 17U)

#define BM_SOC_WKUP_CTL_LP2WKUP_WDT_EN  (0x01U << 16U)

#define FM_SOC_WKUP_CTL_LP2WKUP_VAL (0xffffU << 0U)
#define FV_SOC_WKUP_CTL_LP2WKUP_VAL(v) \
    (((v) << 0U) & FM_SOC_WKUP_CTL_LP2WKUP_VAL)
#define GFV_SOC_WKUP_CTL_LP2WKUP_VAL(v) \
    (((v) & FM_SOC_WKUP_CTL_LP2WKUP_VAL) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : SOC_WKUP_TIMEOUT_OFF
// Register Offset : 0x1414
// Description     : WAKEUP TIMEOUT SETTING REGISTER
//--------------------------------------------------------------------------
#define SOC_WKUP_TIMEOUT_OFF    0x1414U

#define FM_SOC_WKUP_TIMEOUT_WKUP_ACK    (0xffffU << 16U)
#define FV_SOC_WKUP_TIMEOUT_WKUP_ACK(v) \
    (((v) << 16U) & FM_SOC_WKUP_TIMEOUT_WKUP_ACK)
#define GFV_SOC_WKUP_TIMEOUT_WKUP_ACK(v) \
    (((v) & FM_SOC_WKUP_TIMEOUT_WKUP_ACK) >> 16U)

#define FM_SOC_WKUP_TIMEOUT_SOC_RUN (0xffffU << 0U)
#define FV_SOC_WKUP_TIMEOUT_SOC_RUN(v) \
    (((v) << 0U) & FM_SOC_WKUP_TIMEOUT_SOC_RUN)
#define GFV_SOC_WKUP_TIMEOUT_SOC_RUN(v) \
    (((v) & FM_SOC_WKUP_TIMEOUT_SOC_RUN) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : SMC_WKUP_IRQ_OFF
// Register Offset : 0x1418
// Description     : SMC WAKEUP CORE IRQ REGISTER
//--------------------------------------------------------------------------
#define SMC_WKUP_IRQ_OFF    0x1418U

#define FM_SMC_WKUP_IRQ_WKUP_IRQ_STA    (0x1fU << 24U)
#define FV_SMC_WKUP_IRQ_WKUP_IRQ_STA(v) \
    (((v) << 24U) & FM_SMC_WKUP_IRQ_WKUP_IRQ_STA)
#define GFV_SMC_WKUP_IRQ_WKUP_IRQ_STA(v) \
    (((v) & FM_SMC_WKUP_IRQ_WKUP_IRQ_STA) >> 24U)

#define FM_SMC_WKUP_IRQ_WKUP_CLR    (0x1fU << 16U)
#define FV_SMC_WKUP_IRQ_WKUP_CLR(v) \
    (((v) << 16U) & FM_SMC_WKUP_IRQ_WKUP_CLR)
#define GFV_SMC_WKUP_IRQ_WKUP_CLR(v) \
    (((v) & FM_SMC_WKUP_IRQ_WKUP_CLR) >> 16U)

#define FM_SMC_WKUP_IRQ_ERR_WKUP_EN (0x1fU << 8U)
#define FV_SMC_WKUP_IRQ_ERR_WKUP_EN(v) \
    (((v) << 8U) & FM_SMC_WKUP_IRQ_ERR_WKUP_EN)
#define GFV_SMC_WKUP_IRQ_ERR_WKUP_EN(v) \
    (((v) & FM_SMC_WKUP_IRQ_ERR_WKUP_EN) >> 8U)

#define FM_SMC_WKUP_IRQ_BK_WKUP_EN  (0x1fU << 0U)
#define FV_SMC_WKUP_IRQ_BK_WKUP_EN(v) \
    (((v) << 0U) & FM_SMC_WKUP_IRQ_BK_WKUP_EN)
#define GFV_SMC_WKUP_IRQ_BK_WKUP_EN(v) \
    (((v) & FM_SMC_WKUP_IRQ_BK_WKUP_EN) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : SOC_MISC_OFF
// Register Offset : 0x141c
// Description     : SOC MISC REGISTER
//--------------------------------------------------------------------------
#define SOC_MISC_OFF        0x141cU

#define BM_SOC_MISC_ILL_TRANS_WKUP_EN   (0x01U << 9U)

#define BM_SOC_MISC_FIRST_PMU_HK_OK (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : SMC_SW_SWM_OFF
// Register Offset : 0x1450
// Description     : SMC SOFTWARE TRIGGER SWM REGISTER
//--------------------------------------------------------------------------
#define SMC_SW_SWM_OFF      0x1450U

#define BM_SMC_SW_SWM_PMU_SWM_OK    (0x01U << 24U)

#define FM_SMC_SW_SWM_PMU_SWM_O (0x3U << 22U)
#define FV_SMC_SW_SWM_PMU_SWM_O(v) \
    (((v) << 22U) & FM_SMC_SW_SWM_PMU_SWM_O)
#define GFV_SMC_SW_SWM_PMU_SWM_O(v) \
    (((v) & FM_SMC_SW_SWM_PMU_SWM_O) >> 22U)

#define BM_SMC_SW_SWM_PMU_SWM_TRIGGER   (0x01U << 21U)

#define BM_SMC_SW_SWM_PMU_SWM_EN    (0x01U << 20U)

#define BM_SMC_SW_SWM_SAF_RSTGEN_SWM_OK (0x01U << 19U)

#define FM_SMC_SW_SWM_SAF_RSTGEN_SWM_O  (0x3U << 17U)
#define FV_SMC_SW_SWM_SAF_RSTGEN_SWM_O(v) \
    (((v) << 17U) & FM_SMC_SW_SWM_SAF_RSTGEN_SWM_O)
#define GFV_SMC_SW_SWM_SAF_RSTGEN_SWM_O(v) \
    (((v) & FM_SMC_SW_SWM_SAF_RSTGEN_SWM_O) >> 17U)

#define BM_SMC_SW_SWM_SAF_RSTGEN_SWM_TRIGGER    (0x01U << 16U)

#define BM_SMC_SW_SWM_SAF_RSTGEN_SWM_EN (0x01U << 15U)

#define BM_SMC_SW_SWM_SAF_CKGEN_SWM_OK  (0x01U << 14U)

#define FM_SMC_SW_SWM_SAF_CKGEN_SWM_O   (0x3U << 12U)
#define FV_SMC_SW_SWM_SAF_CKGEN_SWM_O(v) \
    (((v) << 12U) & FM_SMC_SW_SWM_SAF_CKGEN_SWM_O)
#define GFV_SMC_SW_SWM_SAF_CKGEN_SWM_O(v) \
    (((v) & FM_SMC_SW_SWM_SAF_CKGEN_SWM_O) >> 12U)

#define BM_SMC_SW_SWM_SAF_CKGEN_SWM_TRIGGER (0x01U << 11U)

#define BM_SMC_SW_SWM_SAF_CKGEN_SWM_EN  (0x01U << 10U)

#define BM_SMC_SW_SWM_AP_RSTGEN_SWM_OK  (0x01U << 9U)

#define FM_SMC_SW_SWM_AP_RSTGEN_SWM_O   (0x3U << 7U)
#define FV_SMC_SW_SWM_AP_RSTGEN_SWM_O(v) \
    (((v) << 7U) & FM_SMC_SW_SWM_AP_RSTGEN_SWM_O)
#define GFV_SMC_SW_SWM_AP_RSTGEN_SWM_O(v) \
    (((v) & FM_SMC_SW_SWM_AP_RSTGEN_SWM_O) >> 7U)

#define BM_SMC_SW_SWM_AP_RSTGEN_SWM_TRIGGER (0x01U << 6U)

#define BM_SMC_SW_SWM_AP_RSTGEN_SWM_EN  (0x01U << 5U)

#define BM_SMC_SW_SWM_AP_CKGEN_SWM_OK   (0x01U << 4U)

#define FM_SMC_SW_SWM_AP_CKGEN_SWM_O    (0x3U << 2U)
#define FV_SMC_SW_SWM_AP_CKGEN_SWM_O(v) \
    (((v) << 2U) & FM_SMC_SW_SWM_AP_CKGEN_SWM_O)
#define GFV_SMC_SW_SWM_AP_CKGEN_SWM_O(v) \
    (((v) & FM_SMC_SW_SWM_AP_CKGEN_SWM_O) >> 2U)

#define BM_SMC_SW_SWM_AP_CKGEN_SWM_TRIGGER  (0x01U << 1U)

#define BM_SMC_SW_SWM_AP_CKGEN_SWM_EN   (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : SOC_CMON_RS_OFF
// Register Offset : 0x1500
// Description     : SOC CLOCK MONITOR RULE SPACE REGISTER 1
//--------------------------------------------------------------------------
#define SOC_CMON_RS_OFF         0x1500U

#define BM_SOC_CMON_RS_LOCK (0x01U << 31U)

#define FM_SOC_CMON_RS_RS   (0xfU << 1U)
#define FV_SOC_CMON_RS_RS(v) \
    (((v) << 1U) & FM_SOC_CMON_RS_RS)
#define GFV_SOC_CMON_RS_RS(v) \
    (((v) & FM_SOC_CMON_RS_RS) >> 1U)

#define BM_SOC_CMON_RS_EN   (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : SOC_CMON_OFF
// Register Offset : 0x1504
// Description     : SOC CLOCK MONITOR REGISTER
//--------------------------------------------------------------------------
#define SOC_CMON_OFF        0x1504U

#define FM_SOC_CMON_MON_FREQ    (0xffffU << 16U)
#define FV_SOC_CMON_MON_FREQ(v) \
    (((v) << 16U) & FM_SOC_CMON_MON_FREQ)
#define GFV_SOC_CMON_MON_FREQ(v) \
    (((v) & FM_SOC_CMON_MON_FREQ) >> 16U)

#define BM_SOC_CMON_MON_FREQ_UPD    (0x01U << 15U)

#define BM_SOC_CMON_ACTIVE_LOSS_DIS (0x01U << 2U)

#define BM_SOC_CMON_FORCE_MON_EN    (0x01U << 1U)

#define BM_SOC_CMON_HW_MON_EN   (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : SOC_CMON_RC_OFF
// Register Offset : 0x1508
// Description     : SOC CLOCK MONITOR RC CHECK SETTING REGISTER
//--------------------------------------------------------------------------
#define SOC_CMON_RC_OFF         0x1508U

#define FM_SOC_CMON_RC_HIGH_THRD    (0xffffU << 16U)
#define FV_SOC_CMON_RC_HIGH_THRD(v) \
    (((v) << 16U) & FM_SOC_CMON_RC_HIGH_THRD)
#define GFV_SOC_CMON_RC_HIGH_THRD(v) \
    (((v) & FM_SOC_CMON_RC_HIGH_THRD) >> 16U)

#define FM_SOC_CMON_RC_LOW_THRD (0xffffU << 0U)
#define FV_SOC_CMON_RC_LOW_THRD(v) \
    (((v) << 0U) & FM_SOC_CMON_RC_LOW_THRD)
#define GFV_SOC_CMON_RC_LOW_THRD(v) \
    (((v) & FM_SOC_CMON_RC_LOW_THRD) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : SOC_CMON_XTAL_OFF
// Register Offset : 0x150c
// Description     : SOC CLOCK MONITOR XTAL CHECK SETTING REGISTER
//--------------------------------------------------------------------------
#define SOC_CMON_XTAL_OFF       0x150cU

#define FM_SOC_CMON_XTAL_HIGH_THRD  (0xffffU << 16U)
#define FV_SOC_CMON_XTAL_HIGH_THRD(v) \
    (((v) << 16U) & FM_SOC_CMON_XTAL_HIGH_THRD)
#define GFV_SOC_CMON_XTAL_HIGH_THRD(v) \
    (((v) & FM_SOC_CMON_XTAL_HIGH_THRD) >> 16U)

#define FM_SOC_CMON_XTAL_LOW_THRD   (0xffffU << 0U)
#define FV_SOC_CMON_XTAL_LOW_THRD(v) \
    (((v) << 0U) & FM_SOC_CMON_XTAL_LOW_THRD)
#define GFV_SOC_CMON_XTAL_LOW_THRD(v) \
    (((v) & FM_SOC_CMON_XTAL_LOW_THRD) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : CORE_IRQ_MASK_RS_OFF
// Register Offset : 0x1600
// Description     : CORE SPECIFIC IRQ MASK RULE SPACE REGISTER
//--------------------------------------------------------------------------
#define CORE_IRQ_MASK_RS_OFF(n) (0x1600U + 8U*(n))

#define BM_CORE_IRQ_MASK_RS_LOCK    (0x01U << 31U)

#define FM_CORE_IRQ_MASK_RS_RS  (0xfU << 1U)
#define FV_CORE_IRQ_MASK_RS_RS(v) \
    (((v) << 1U) & FM_CORE_IRQ_MASK_RS_RS)
#define GFV_CORE_IRQ_MASK_RS_RS(v) \
    (((v) & FM_CORE_IRQ_MASK_RS_RS) >> 1U)

#define BM_CORE_IRQ_MASK_RS_EN  (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : CORE_IRQ_MASK_OFF
// Register Offset : 0x1604
// Description     : CORE SPECIFIC IRQ MASK REGISTER
//--------------------------------------------------------------------------
#define CORE_IRQ_MASK_OFF(n)    (0x1604U + 8U*(n))

#define FM_CORE_IRQ_MASK_MASK   (0xffffU << 0U)
#define FV_CORE_IRQ_MASK_MASK(v) \
    (((v) << 0U) & FM_CORE_IRQ_MASK_MASK)
#define GFV_CORE_IRQ_MASK_MASK(v) \
    (((v) & FM_CORE_IRQ_MASK_MASK) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : COM_IRQ_MASK_RS_OFF
// Register Offset : 0x1800
// Description     : COMMON IRQ MASK RULE SPACE REGISTER
//--------------------------------------------------------------------------
#define COM_IRQ_MASK_RS_OFF(n)      (0x1800U + 36U*(n))

#define BM_COM_IRQ_MASK_RS_LOCK (0x01U << 31U)

#define FM_COM_IRQ_MASK_RS_RS   (0xfU << 1U)
#define FV_COM_IRQ_MASK_RS_RS(v) \
    (((v) << 1U) & FM_COM_IRQ_MASK_RS_RS)
#define GFV_COM_IRQ_MASK_RS_RS(v) \
    (((v) & FM_COM_IRQ_MASK_RS_RS) >> 1U)

#define BM_COM_IRQ_MASK_RS_EN   (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : COM_IRQ_MASK_0_OFF
// Register Offset : 0x1804
// Description     : COMMON IRQ MASK REGISTER
//--------------------------------------------------------------------------
#define COM_IRQ_MASK_0_OFF(n)       (0x1804U + 36U*(n))

#define FM_COM_IRQ_MASK_0_MASK  (0xffffffffU << 0U)
#define FV_COM_IRQ_MASK_0_MASK(v) \
    (((v) << 0U) & FM_COM_IRQ_MASK_0_MASK)
#define GFV_COM_IRQ_MASK_0_MASK(v) \
    (((v) & FM_COM_IRQ_MASK_0_MASK) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : COM_IRQ_MASK_1_OFF
// Register Offset : 0x1808
// Description     : COMMON IRQ MASK REGISTER
//--------------------------------------------------------------------------
#define COM_IRQ_MASK_1_OFF(n)       (0x1808U + 36U*(n))

#define FM_COM_IRQ_MASK_1_MASK  (0xffffffffU << 0U)
#define FV_COM_IRQ_MASK_1_MASK(v) \
    (((v) << 0U) & FM_COM_IRQ_MASK_1_MASK)
#define GFV_COM_IRQ_MASK_1_MASK(v) \
    (((v) & FM_COM_IRQ_MASK_1_MASK) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : COM_IRQ_MASK_2_OFF
// Register Offset : 0x180c
// Description     : COMMON IRQ MASK REGISTER
//--------------------------------------------------------------------------
#define COM_IRQ_MASK_2_OFF(n)       (0x180cU + 36U*(n))

#define FM_COM_IRQ_MASK_2_MASK  (0xffffffffU << 0U)
#define FV_COM_IRQ_MASK_2_MASK(v) \
    (((v) << 0U) & FM_COM_IRQ_MASK_2_MASK)
#define GFV_COM_IRQ_MASK_2_MASK(v) \
    (((v) & FM_COM_IRQ_MASK_2_MASK) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : COM_IRQ_MASK_3_OFF
// Register Offset : 0x1810
// Description     : COMMON IRQ MASK REGISTER
//--------------------------------------------------------------------------
#define COM_IRQ_MASK_3_OFF(n)       (0x1810U + 36U*(n))

#define FM_COM_IRQ_MASK_3_MASK  (0xffffffffU << 0U)
#define FV_COM_IRQ_MASK_3_MASK(v) \
    (((v) << 0U) & FM_COM_IRQ_MASK_3_MASK)
#define GFV_COM_IRQ_MASK_3_MASK(v) \
    (((v) & FM_COM_IRQ_MASK_3_MASK) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : COM_IRQ_MASK_4_OFF
// Register Offset : 0x1814
// Description     : COMMON IRQ MASK REGISTER
//--------------------------------------------------------------------------
#define COM_IRQ_MASK_4_OFF(n)       (0x1814U + 36U*(n))

#define FM_COM_IRQ_MASK_4_MASK  (0xffffffffU << 0U)
#define FV_COM_IRQ_MASK_4_MASK(v) \
    (((v) << 0U) & FM_COM_IRQ_MASK_4_MASK)
#define GFV_COM_IRQ_MASK_4_MASK(v) \
    (((v) & FM_COM_IRQ_MASK_4_MASK) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : COM_IRQ_MASK_5_OFF
// Register Offset : 0x1818
// Description     : COMMON IRQ MASK REGISTER
//--------------------------------------------------------------------------
#define COM_IRQ_MASK_5_OFF(n)       (0x1818U + 36U*(n))

#define FM_COM_IRQ_MASK_5_MASK  (0xffffffffU << 0U)
#define FV_COM_IRQ_MASK_5_MASK(v) \
    (((v) << 0U) & FM_COM_IRQ_MASK_5_MASK)
#define GFV_COM_IRQ_MASK_5_MASK(v) \
    (((v) & FM_COM_IRQ_MASK_5_MASK) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : COM_IRQ_MASK_6_OFF
// Register Offset : 0x181c
// Description     : COMMON IRQ MASK REGISTER
//--------------------------------------------------------------------------
#define COM_IRQ_MASK_6_OFF(n)       (0x181cU + 36U*(n))

#define FM_COM_IRQ_MASK_6_MASK  (0xffffffffU << 0U)
#define FV_COM_IRQ_MASK_6_MASK(v) \
    (((v) << 0U) & FM_COM_IRQ_MASK_6_MASK)
#define GFV_COM_IRQ_MASK_6_MASK(v) \
    (((v) & FM_COM_IRQ_MASK_6_MASK) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : COM_IRQ_MASK_7_OFF
// Register Offset : 0x1820
// Description     : COMMON IRQ MASK REGISTER
//--------------------------------------------------------------------------
#define COM_IRQ_MASK_7_OFF(n)       (0x1820U + 36U*(n))

#define FM_COM_IRQ_MASK_7_MASK  (0xffffffffU << 0U)
#define FV_COM_IRQ_MASK_7_MASK(v) \
    (((v) << 0U) & FM_COM_IRQ_MASK_7_MASK)
#define GFV_COM_IRQ_MASK_7_MASK(v) \
    (((v) & FM_COM_IRQ_MASK_7_MASK) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : IRQ_MON_RS_OFF
// Register Offset : 0x1a00
// Description     : IRQ MONITOR REGISTER RULE SPACE REGISTER
//--------------------------------------------------------------------------
#define IRQ_MON_RS_OFF          0x1a00U

#define BM_IRQ_MON_RS_LOCK  (0x01U << 31U)

#define FM_IRQ_MON_RS_RS    (0xfU << 1U)
#define FV_IRQ_MON_RS_RS(v) \
    (((v) << 1U) & FM_IRQ_MON_RS_RS)
#define GFV_IRQ_MON_RS_RS(v) \
    (((v) & FM_IRQ_MON_RS_RS) >> 1U)

#define BM_IRQ_MON_RS_EN    (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : CORE_IRQ_MON_OFF
// Register Offset : 0x1a04
// Description     : CORE SPECIFIC IRQ MONITOR REGISER
//--------------------------------------------------------------------------
#define CORE_IRQ_MON_OFF(n)         (0x1a04U + 4U*(n))

#define BM_CORE_IRQ_MON_IRQ_STA_15  (0x01U << 15U)

#define BM_CORE_IRQ_MON_IRQ_STA_14  (0x01U << 14U)

#define BM_CORE_IRQ_MON_IRQ_STA_13  (0x01U << 13U)

#define BM_CORE_IRQ_MON_IRQ_STA_12  (0x01U << 12U)

#define BM_CORE_IRQ_MON_IRQ_STA_11  (0x01U << 11U)

#define BM_CORE_IRQ_MON_IRQ_STA_10  (0x01U << 10U)

#define BM_CORE_IRQ_MON_IRQ_STA_9   (0x01U << 9U)

#define BM_CORE_IRQ_MON_IRQ_STA_8   (0x01U << 8U)

#define BM_CORE_IRQ_MON_IRQ_STA_7   (0x01U << 7U)

#define BM_CORE_IRQ_MON_IRQ_STA_6   (0x01U << 6U)

#define BM_CORE_IRQ_MON_IRQ_STA_5   (0x01U << 5U)

#define BM_CORE_IRQ_MON_IRQ_STA_4   (0x01U << 4U)

#define BM_CORE_IRQ_MON_IRQ_STA_3   (0x01U << 3U)

#define BM_CORE_IRQ_MON_IRQ_STA_2   (0x01U << 2U)

#define BM_CORE_IRQ_MON_IRQ_STA_1   (0x01U << 1U)

#define BM_CORE_IRQ_MON_IRQ_STA_0   (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : COM_IRQ_MON_0_OFF
// Register Offset : 0x1b00
// Description     : COMMON IRQ MONITOR REGISTER
//--------------------------------------------------------------------------
#define COM_IRQ_MON_0_OFF           0x1b00U

#define BM_COM_IRQ_MON_0_IRQ_STA_31 (0x01U << 31U)

#define BM_COM_IRQ_MON_0_IRQ_STA_30 (0x01U << 30U)

#define BM_COM_IRQ_MON_0_IRQ_STA_29 (0x01U << 29U)

#define BM_COM_IRQ_MON_0_IRQ_STA_28 (0x01U << 28U)

#define BM_COM_IRQ_MON_0_IRQ_STA_27 (0x01U << 27U)

#define BM_COM_IRQ_MON_0_IRQ_STA_26 (0x01U << 26U)

#define BM_COM_IRQ_MON_0_IRQ_STA_25 (0x01U << 25U)

#define BM_COM_IRQ_MON_0_IRQ_STA_24 (0x01U << 24U)

#define BM_COM_IRQ_MON_0_IRQ_STA_23 (0x01U << 23U)

#define BM_COM_IRQ_MON_0_IRQ_STA_22 (0x01U << 22U)

#define BM_COM_IRQ_MON_0_IRQ_STA_21 (0x01U << 21U)

#define BM_COM_IRQ_MON_0_IRQ_STA_20 (0x01U << 20U)

#define BM_COM_IRQ_MON_0_IRQ_STA_19 (0x01U << 19U)

#define BM_COM_IRQ_MON_0_IRQ_STA_18 (0x01U << 18U)

#define BM_COM_IRQ_MON_0_IRQ_STA_17 (0x01U << 17U)

#define BM_COM_IRQ_MON_0_IRQ_STA_16 (0x01U << 16U)

#define BM_COM_IRQ_MON_0_IRQ_STA_15 (0x01U << 15U)

#define BM_COM_IRQ_MON_0_IRQ_STA_14 (0x01U << 14U)

#define BM_COM_IRQ_MON_0_IRQ_STA_13 (0x01U << 13U)

#define BM_COM_IRQ_MON_0_IRQ_STA_12 (0x01U << 12U)

#define BM_COM_IRQ_MON_0_IRQ_STA_11 (0x01U << 11U)

#define BM_COM_IRQ_MON_0_IRQ_STA_10 (0x01U << 10U)

#define BM_COM_IRQ_MON_0_IRQ_STA_9  (0x01U << 9U)

#define BM_COM_IRQ_MON_0_IRQ_STA_8  (0x01U << 8U)

#define BM_COM_IRQ_MON_0_IRQ_STA_7  (0x01U << 7U)

#define BM_COM_IRQ_MON_0_IRQ_STA_6  (0x01U << 6U)

#define BM_COM_IRQ_MON_0_IRQ_STA_5  (0x01U << 5U)

#define BM_COM_IRQ_MON_0_IRQ_STA_4  (0x01U << 4U)

#define BM_COM_IRQ_MON_0_IRQ_STA_3  (0x01U << 3U)

#define BM_COM_IRQ_MON_0_IRQ_STA_2  (0x01U << 2U)

#define BM_COM_IRQ_MON_0_IRQ_STA_1  (0x01U << 1U)

#define BM_COM_IRQ_MON_0_IRQ_STA_0  (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : COM_IRQ_MON_1_OFF
// Register Offset : 0x1b04
// Description     : COMMON IRQ MONITOR REGISTER
//--------------------------------------------------------------------------
#define COM_IRQ_MON_1_OFF           0x1b04U

#define BM_COM_IRQ_MON_1_IRQ_STA_31 (0x01U << 31U)

#define BM_COM_IRQ_MON_1_IRQ_STA_30 (0x01U << 30U)

#define BM_COM_IRQ_MON_1_IRQ_STA_29 (0x01U << 29U)

#define BM_COM_IRQ_MON_1_IRQ_STA_28 (0x01U << 28U)

#define BM_COM_IRQ_MON_1_IRQ_STA_27 (0x01U << 27U)

#define BM_COM_IRQ_MON_1_IRQ_STA_26 (0x01U << 26U)

#define BM_COM_IRQ_MON_1_IRQ_STA_25 (0x01U << 25U)

#define BM_COM_IRQ_MON_1_IRQ_STA_24 (0x01U << 24U)

#define BM_COM_IRQ_MON_1_IRQ_STA_23 (0x01U << 23U)

#define BM_COM_IRQ_MON_1_IRQ_STA_22 (0x01U << 22U)

#define BM_COM_IRQ_MON_1_IRQ_STA_21 (0x01U << 21U)

#define BM_COM_IRQ_MON_1_IRQ_STA_20 (0x01U << 20U)

#define BM_COM_IRQ_MON_1_IRQ_STA_19 (0x01U << 19U)

#define BM_COM_IRQ_MON_1_IRQ_STA_18 (0x01U << 18U)

#define BM_COM_IRQ_MON_1_IRQ_STA_17 (0x01U << 17U)

#define BM_COM_IRQ_MON_1_IRQ_STA_16 (0x01U << 16U)

#define BM_COM_IRQ_MON_1_IRQ_STA_15 (0x01U << 15U)

#define BM_COM_IRQ_MON_1_IRQ_STA_14 (0x01U << 14U)

#define BM_COM_IRQ_MON_1_IRQ_STA_13 (0x01U << 13U)

#define BM_COM_IRQ_MON_1_IRQ_STA_12 (0x01U << 12U)

#define BM_COM_IRQ_MON_1_IRQ_STA_11 (0x01U << 11U)

#define BM_COM_IRQ_MON_1_IRQ_STA_10 (0x01U << 10U)

#define BM_COM_IRQ_MON_1_IRQ_STA_9  (0x01U << 9U)

#define BM_COM_IRQ_MON_1_IRQ_STA_8  (0x01U << 8U)

#define BM_COM_IRQ_MON_1_IRQ_STA_7  (0x01U << 7U)

#define BM_COM_IRQ_MON_1_IRQ_STA_6  (0x01U << 6U)

#define BM_COM_IRQ_MON_1_IRQ_STA_5  (0x01U << 5U)

#define BM_COM_IRQ_MON_1_IRQ_STA_4  (0x01U << 4U)

#define BM_COM_IRQ_MON_1_IRQ_STA_3  (0x01U << 3U)

#define BM_COM_IRQ_MON_1_IRQ_STA_2  (0x01U << 2U)

#define BM_COM_IRQ_MON_1_IRQ_STA_1  (0x01U << 1U)

#define BM_COM_IRQ_MON_1_IRQ_STA_0  (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : COM_IRQ_MON_2_OFF
// Register Offset : 0x1b08
// Description     : COMMON IRQ MONITOR REGISTER
//--------------------------------------------------------------------------
#define COM_IRQ_MON_2_OFF           0x1b08U

#define BM_COM_IRQ_MON_2_IRQ_STA_31 (0x01U << 31U)

#define BM_COM_IRQ_MON_2_IRQ_STA_30 (0x01U << 30U)

#define BM_COM_IRQ_MON_2_IRQ_STA_29 (0x01U << 29U)

#define BM_COM_IRQ_MON_2_IRQ_STA_28 (0x01U << 28U)

#define BM_COM_IRQ_MON_2_IRQ_STA_27 (0x01U << 27U)

#define BM_COM_IRQ_MON_2_IRQ_STA_26 (0x01U << 26U)

#define BM_COM_IRQ_MON_2_IRQ_STA_25 (0x01U << 25U)

#define BM_COM_IRQ_MON_2_IRQ_STA_24 (0x01U << 24U)

#define BM_COM_IRQ_MON_2_IRQ_STA_23 (0x01U << 23U)

#define BM_COM_IRQ_MON_2_IRQ_STA_22 (0x01U << 22U)

#define BM_COM_IRQ_MON_2_IRQ_STA_21 (0x01U << 21U)

#define BM_COM_IRQ_MON_2_IRQ_STA_20 (0x01U << 20U)

#define BM_COM_IRQ_MON_2_IRQ_STA_19 (0x01U << 19U)

#define BM_COM_IRQ_MON_2_IRQ_STA_18 (0x01U << 18U)

#define BM_COM_IRQ_MON_2_IRQ_STA_17 (0x01U << 17U)

#define BM_COM_IRQ_MON_2_IRQ_STA_16 (0x01U << 16U)

#define BM_COM_IRQ_MON_2_IRQ_STA_15 (0x01U << 15U)

#define BM_COM_IRQ_MON_2_IRQ_STA_14 (0x01U << 14U)

#define BM_COM_IRQ_MON_2_IRQ_STA_13 (0x01U << 13U)

#define BM_COM_IRQ_MON_2_IRQ_STA_12 (0x01U << 12U)

#define BM_COM_IRQ_MON_2_IRQ_STA_11 (0x01U << 11U)

#define BM_COM_IRQ_MON_2_IRQ_STA_10 (0x01U << 10U)

#define BM_COM_IRQ_MON_2_IRQ_STA_9  (0x01U << 9U)

#define BM_COM_IRQ_MON_2_IRQ_STA_8  (0x01U << 8U)

#define BM_COM_IRQ_MON_2_IRQ_STA_7  (0x01U << 7U)

#define BM_COM_IRQ_MON_2_IRQ_STA_6  (0x01U << 6U)

#define BM_COM_IRQ_MON_2_IRQ_STA_5  (0x01U << 5U)

#define BM_COM_IRQ_MON_2_IRQ_STA_4  (0x01U << 4U)

#define BM_COM_IRQ_MON_2_IRQ_STA_3  (0x01U << 3U)

#define BM_COM_IRQ_MON_2_IRQ_STA_2  (0x01U << 2U)

#define BM_COM_IRQ_MON_2_IRQ_STA_1  (0x01U << 1U)

#define BM_COM_IRQ_MON_2_IRQ_STA_0  (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : COM_IRQ_MON_3_OFF
// Register Offset : 0x1b0c
// Description     : COMMON IRQ MONITOR REGISTER
//--------------------------------------------------------------------------
#define COM_IRQ_MON_3_OFF           0x1b0cU

#define BM_COM_IRQ_MON_3_IRQ_STA_31 (0x01U << 31U)

#define BM_COM_IRQ_MON_3_IRQ_STA_30 (0x01U << 30U)

#define BM_COM_IRQ_MON_3_IRQ_STA_29 (0x01U << 29U)

#define BM_COM_IRQ_MON_3_IRQ_STA_28 (0x01U << 28U)

#define BM_COM_IRQ_MON_3_IRQ_STA_27 (0x01U << 27U)

#define BM_COM_IRQ_MON_3_IRQ_STA_26 (0x01U << 26U)

#define BM_COM_IRQ_MON_3_IRQ_STA_25 (0x01U << 25U)

#define BM_COM_IRQ_MON_3_IRQ_STA_24 (0x01U << 24U)

#define BM_COM_IRQ_MON_3_IRQ_STA_23 (0x01U << 23U)

#define BM_COM_IRQ_MON_3_IRQ_STA_22 (0x01U << 22U)

#define BM_COM_IRQ_MON_3_IRQ_STA_21 (0x01U << 21U)

#define BM_COM_IRQ_MON_3_IRQ_STA_20 (0x01U << 20U)

#define BM_COM_IRQ_MON_3_IRQ_STA_19 (0x01U << 19U)

#define BM_COM_IRQ_MON_3_IRQ_STA_18 (0x01U << 18U)

#define BM_COM_IRQ_MON_3_IRQ_STA_17 (0x01U << 17U)

#define BM_COM_IRQ_MON_3_IRQ_STA_16 (0x01U << 16U)

#define BM_COM_IRQ_MON_3_IRQ_STA_15 (0x01U << 15U)

#define BM_COM_IRQ_MON_3_IRQ_STA_14 (0x01U << 14U)

#define BM_COM_IRQ_MON_3_IRQ_STA_13 (0x01U << 13U)

#define BM_COM_IRQ_MON_3_IRQ_STA_12 (0x01U << 12U)

#define BM_COM_IRQ_MON_3_IRQ_STA_11 (0x01U << 11U)

#define BM_COM_IRQ_MON_3_IRQ_STA_10 (0x01U << 10U)

#define BM_COM_IRQ_MON_3_IRQ_STA_9  (0x01U << 9U)

#define BM_COM_IRQ_MON_3_IRQ_STA_8  (0x01U << 8U)

#define BM_COM_IRQ_MON_3_IRQ_STA_7  (0x01U << 7U)

#define BM_COM_IRQ_MON_3_IRQ_STA_6  (0x01U << 6U)

#define BM_COM_IRQ_MON_3_IRQ_STA_5  (0x01U << 5U)

#define BM_COM_IRQ_MON_3_IRQ_STA_4  (0x01U << 4U)

#define BM_COM_IRQ_MON_3_IRQ_STA_3  (0x01U << 3U)

#define BM_COM_IRQ_MON_3_IRQ_STA_2  (0x01U << 2U)

#define BM_COM_IRQ_MON_3_IRQ_STA_1  (0x01U << 1U)

#define BM_COM_IRQ_MON_3_IRQ_STA_0  (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : COM_IRQ_MON_4_OFF
// Register Offset : 0x1b10
// Description     : COMMON IRQ MONITOR REGISTER
//--------------------------------------------------------------------------
#define COM_IRQ_MON_4_OFF           0x1b10U

#define BM_COM_IRQ_MON_4_IRQ_STA_31 (0x01U << 31U)

#define BM_COM_IRQ_MON_4_IRQ_STA_30 (0x01U << 30U)

#define BM_COM_IRQ_MON_4_IRQ_STA_29 (0x01U << 29U)

#define BM_COM_IRQ_MON_4_IRQ_STA_28 (0x01U << 28U)

#define BM_COM_IRQ_MON_4_IRQ_STA_27 (0x01U << 27U)

#define BM_COM_IRQ_MON_4_IRQ_STA_26 (0x01U << 26U)

#define BM_COM_IRQ_MON_4_IRQ_STA_25 (0x01U << 25U)

#define BM_COM_IRQ_MON_4_IRQ_STA_24 (0x01U << 24U)

#define BM_COM_IRQ_MON_4_IRQ_STA_23 (0x01U << 23U)

#define BM_COM_IRQ_MON_4_IRQ_STA_22 (0x01U << 22U)

#define BM_COM_IRQ_MON_4_IRQ_STA_21 (0x01U << 21U)

#define BM_COM_IRQ_MON_4_IRQ_STA_20 (0x01U << 20U)

#define BM_COM_IRQ_MON_4_IRQ_STA_19 (0x01U << 19U)

#define BM_COM_IRQ_MON_4_IRQ_STA_18 (0x01U << 18U)

#define BM_COM_IRQ_MON_4_IRQ_STA_17 (0x01U << 17U)

#define BM_COM_IRQ_MON_4_IRQ_STA_16 (0x01U << 16U)

#define BM_COM_IRQ_MON_4_IRQ_STA_15 (0x01U << 15U)

#define BM_COM_IRQ_MON_4_IRQ_STA_14 (0x01U << 14U)

#define BM_COM_IRQ_MON_4_IRQ_STA_13 (0x01U << 13U)

#define BM_COM_IRQ_MON_4_IRQ_STA_12 (0x01U << 12U)

#define BM_COM_IRQ_MON_4_IRQ_STA_11 (0x01U << 11U)

#define BM_COM_IRQ_MON_4_IRQ_STA_10 (0x01U << 10U)

#define BM_COM_IRQ_MON_4_IRQ_STA_9  (0x01U << 9U)

#define BM_COM_IRQ_MON_4_IRQ_STA_8  (0x01U << 8U)

#define BM_COM_IRQ_MON_4_IRQ_STA_7  (0x01U << 7U)

#define BM_COM_IRQ_MON_4_IRQ_STA_6  (0x01U << 6U)

#define BM_COM_IRQ_MON_4_IRQ_STA_5  (0x01U << 5U)

#define BM_COM_IRQ_MON_4_IRQ_STA_4  (0x01U << 4U)

#define BM_COM_IRQ_MON_4_IRQ_STA_3  (0x01U << 3U)

#define BM_COM_IRQ_MON_4_IRQ_STA_2  (0x01U << 2U)

#define BM_COM_IRQ_MON_4_IRQ_STA_1  (0x01U << 1U)

#define BM_COM_IRQ_MON_4_IRQ_STA_0  (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : COM_IRQ_MON_5_OFF
// Register Offset : 0x1b14
// Description     : COMMON IRQ MONITOR REGISTER
//--------------------------------------------------------------------------
#define COM_IRQ_MON_5_OFF           0x1b14U

#define BM_COM_IRQ_MON_5_IRQ_STA_31 (0x01U << 31U)

#define BM_COM_IRQ_MON_5_IRQ_STA_30 (0x01U << 30U)

#define BM_COM_IRQ_MON_5_IRQ_STA_29 (0x01U << 29U)

#define BM_COM_IRQ_MON_5_IRQ_STA_28 (0x01U << 28U)

#define BM_COM_IRQ_MON_5_IRQ_STA_27 (0x01U << 27U)

#define BM_COM_IRQ_MON_5_IRQ_STA_26 (0x01U << 26U)

#define BM_COM_IRQ_MON_5_IRQ_STA_25 (0x01U << 25U)

#define BM_COM_IRQ_MON_5_IRQ_STA_24 (0x01U << 24U)

#define BM_COM_IRQ_MON_5_IRQ_STA_23 (0x01U << 23U)

#define BM_COM_IRQ_MON_5_IRQ_STA_22 (0x01U << 22U)

#define BM_COM_IRQ_MON_5_IRQ_STA_21 (0x01U << 21U)

#define BM_COM_IRQ_MON_5_IRQ_STA_20 (0x01U << 20U)

#define BM_COM_IRQ_MON_5_IRQ_STA_19 (0x01U << 19U)

#define BM_COM_IRQ_MON_5_IRQ_STA_18 (0x01U << 18U)

#define BM_COM_IRQ_MON_5_IRQ_STA_17 (0x01U << 17U)

#define BM_COM_IRQ_MON_5_IRQ_STA_16 (0x01U << 16U)

#define BM_COM_IRQ_MON_5_IRQ_STA_15 (0x01U << 15U)

#define BM_COM_IRQ_MON_5_IRQ_STA_14 (0x01U << 14U)

#define BM_COM_IRQ_MON_5_IRQ_STA_13 (0x01U << 13U)

#define BM_COM_IRQ_MON_5_IRQ_STA_12 (0x01U << 12U)

#define BM_COM_IRQ_MON_5_IRQ_STA_11 (0x01U << 11U)

#define BM_COM_IRQ_MON_5_IRQ_STA_10 (0x01U << 10U)

#define BM_COM_IRQ_MON_5_IRQ_STA_9  (0x01U << 9U)

#define BM_COM_IRQ_MON_5_IRQ_STA_8  (0x01U << 8U)

#define BM_COM_IRQ_MON_5_IRQ_STA_7  (0x01U << 7U)

#define BM_COM_IRQ_MON_5_IRQ_STA_6  (0x01U << 6U)

#define BM_COM_IRQ_MON_5_IRQ_STA_5  (0x01U << 5U)

#define BM_COM_IRQ_MON_5_IRQ_STA_4  (0x01U << 4U)

#define BM_COM_IRQ_MON_5_IRQ_STA_3  (0x01U << 3U)

#define BM_COM_IRQ_MON_5_IRQ_STA_2  (0x01U << 2U)

#define BM_COM_IRQ_MON_5_IRQ_STA_1  (0x01U << 1U)

#define BM_COM_IRQ_MON_5_IRQ_STA_0  (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : COM_IRQ_MON_6_OFF
// Register Offset : 0x1b18
// Description     : COMMON IRQ MONITOR REGISTER
//--------------------------------------------------------------------------
#define COM_IRQ_MON_6_OFF           0x1b18U

#define BM_COM_IRQ_MON_6_IRQ_STA_31 (0x01U << 31U)

#define BM_COM_IRQ_MON_6_IRQ_STA_30 (0x01U << 30U)

#define BM_COM_IRQ_MON_6_IRQ_STA_29 (0x01U << 29U)

#define BM_COM_IRQ_MON_6_IRQ_STA_28 (0x01U << 28U)

#define BM_COM_IRQ_MON_6_IRQ_STA_27 (0x01U << 27U)

#define BM_COM_IRQ_MON_6_IRQ_STA_26 (0x01U << 26U)

#define BM_COM_IRQ_MON_6_IRQ_STA_25 (0x01U << 25U)

#define BM_COM_IRQ_MON_6_IRQ_STA_24 (0x01U << 24U)

#define BM_COM_IRQ_MON_6_IRQ_STA_23 (0x01U << 23U)

#define BM_COM_IRQ_MON_6_IRQ_STA_22 (0x01U << 22U)

#define BM_COM_IRQ_MON_6_IRQ_STA_21 (0x01U << 21U)

#define BM_COM_IRQ_MON_6_IRQ_STA_20 (0x01U << 20U)

#define BM_COM_IRQ_MON_6_IRQ_STA_19 (0x01U << 19U)

#define BM_COM_IRQ_MON_6_IRQ_STA_18 (0x01U << 18U)

#define BM_COM_IRQ_MON_6_IRQ_STA_17 (0x01U << 17U)

#define BM_COM_IRQ_MON_6_IRQ_STA_16 (0x01U << 16U)

#define BM_COM_IRQ_MON_6_IRQ_STA_15 (0x01U << 15U)

#define BM_COM_IRQ_MON_6_IRQ_STA_14 (0x01U << 14U)

#define BM_COM_IRQ_MON_6_IRQ_STA_13 (0x01U << 13U)

#define BM_COM_IRQ_MON_6_IRQ_STA_12 (0x01U << 12U)

#define BM_COM_IRQ_MON_6_IRQ_STA_11 (0x01U << 11U)

#define BM_COM_IRQ_MON_6_IRQ_STA_10 (0x01U << 10U)

#define BM_COM_IRQ_MON_6_IRQ_STA_9  (0x01U << 9U)

#define BM_COM_IRQ_MON_6_IRQ_STA_8  (0x01U << 8U)

#define BM_COM_IRQ_MON_6_IRQ_STA_7  (0x01U << 7U)

#define BM_COM_IRQ_MON_6_IRQ_STA_6  (0x01U << 6U)

#define BM_COM_IRQ_MON_6_IRQ_STA_5  (0x01U << 5U)

#define BM_COM_IRQ_MON_6_IRQ_STA_4  (0x01U << 4U)

#define BM_COM_IRQ_MON_6_IRQ_STA_3  (0x01U << 3U)

#define BM_COM_IRQ_MON_6_IRQ_STA_2  (0x01U << 2U)

#define BM_COM_IRQ_MON_6_IRQ_STA_1  (0x01U << 1U)

#define BM_COM_IRQ_MON_6_IRQ_STA_0  (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : COM_IRQ_MON_7_OFF
// Register Offset : 0x1b1c
// Description     : COMMON IRQ MONITOR REGISTER
//--------------------------------------------------------------------------
#define COM_IRQ_MON_7_OFF           0x1b1cU

#define BM_COM_IRQ_MON_7_IRQ_STA_31 (0x01U << 31U)

#define BM_COM_IRQ_MON_7_IRQ_STA_30 (0x01U << 30U)

#define BM_COM_IRQ_MON_7_IRQ_STA_29 (0x01U << 29U)

#define BM_COM_IRQ_MON_7_IRQ_STA_28 (0x01U << 28U)

#define BM_COM_IRQ_MON_7_IRQ_STA_27 (0x01U << 27U)

#define BM_COM_IRQ_MON_7_IRQ_STA_26 (0x01U << 26U)

#define BM_COM_IRQ_MON_7_IRQ_STA_25 (0x01U << 25U)

#define BM_COM_IRQ_MON_7_IRQ_STA_24 (0x01U << 24U)

#define BM_COM_IRQ_MON_7_IRQ_STA_23 (0x01U << 23U)

#define BM_COM_IRQ_MON_7_IRQ_STA_22 (0x01U << 22U)

#define BM_COM_IRQ_MON_7_IRQ_STA_21 (0x01U << 21U)

#define BM_COM_IRQ_MON_7_IRQ_STA_20 (0x01U << 20U)

#define BM_COM_IRQ_MON_7_IRQ_STA_19 (0x01U << 19U)

#define BM_COM_IRQ_MON_7_IRQ_STA_18 (0x01U << 18U)

#define BM_COM_IRQ_MON_7_IRQ_STA_17 (0x01U << 17U)

#define BM_COM_IRQ_MON_7_IRQ_STA_16 (0x01U << 16U)

#define BM_COM_IRQ_MON_7_IRQ_STA_15 (0x01U << 15U)

#define BM_COM_IRQ_MON_7_IRQ_STA_14 (0x01U << 14U)

#define BM_COM_IRQ_MON_7_IRQ_STA_13 (0x01U << 13U)

#define BM_COM_IRQ_MON_7_IRQ_STA_12 (0x01U << 12U)

#define BM_COM_IRQ_MON_7_IRQ_STA_11 (0x01U << 11U)

#define BM_COM_IRQ_MON_7_IRQ_STA_10 (0x01U << 10U)

#define BM_COM_IRQ_MON_7_IRQ_STA_9  (0x01U << 9U)

#define BM_COM_IRQ_MON_7_IRQ_STA_8  (0x01U << 8U)

#define BM_COM_IRQ_MON_7_IRQ_STA_7  (0x01U << 7U)

#define BM_COM_IRQ_MON_7_IRQ_STA_6  (0x01U << 6U)

#define BM_COM_IRQ_MON_7_IRQ_STA_5  (0x01U << 5U)

#define BM_COM_IRQ_MON_7_IRQ_STA_4  (0x01U << 4U)

#define BM_COM_IRQ_MON_7_IRQ_STA_3  (0x01U << 3U)

#define BM_COM_IRQ_MON_7_IRQ_STA_2  (0x01U << 2U)

#define BM_COM_IRQ_MON_7_IRQ_STA_1  (0x01U << 1U)

#define BM_COM_IRQ_MON_7_IRQ_STA_0  (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : SMC_RES_RS_OFF
// Register Offset : 0x1c00
// Description     : SMC RESERVE REGISTER RULE SPACE REGISTER
//--------------------------------------------------------------------------
#define SMC_RES_RS_OFF          0x1c00U

#define BM_SMC_RES_RS_LOCK  (0x01U << 31U)

#define FM_SMC_RES_RS_RS    (0xfU << 1U)
#define FV_SMC_RES_RS_RS(v) \
    (((v) << 1U) & FM_SMC_RES_RS_RS)
#define GFV_SMC_RES_RS_RS(v) \
    (((v) & FM_SMC_RES_RS_RS) >> 1U)

#define BM_SMC_RES_RS_EN    (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : SMC_RES_OFF
// Register Offset : 0x1c04
// Description     : SMC RESERVE REGISTER
//--------------------------------------------------------------------------
#define SMC_RES_OFF         0x1c04U

#define FM_SMC_RES_RES  (0xffffffffU << 0U)
#define FV_SMC_RES_RES(v) \
    (((v) << 0U) & FM_SMC_RES_RES)
#define GFV_SMC_RES_RES(v) \
    (((v) & FM_SMC_RES_RES) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : SMC_MISC_RS_OFF
// Register Offset : 0x1c08
// Description     : SMC MISC REGISTER RULE SPACE REGISTER
//--------------------------------------------------------------------------
#define SMC_MISC_RS_OFF         0x1c08U

#define BM_SMC_MISC_RS_LOCK (0x01U << 31U)

#define FM_SMC_MISC_RS_RS   (0xfU << 1U)
#define FV_SMC_MISC_RS_RS(v) \
    (((v) << 1U) & FM_SMC_MISC_RS_RS)
#define GFV_SMC_MISC_RS_RS(v) \
    (((v) & FM_SMC_MISC_RS_RS) >> 1U)

#define BM_SMC_MISC_RS_EN   (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : SMC_MISC_OFF
// Register Offset : 0x1c0c
// Description     : SMC MISC REGISTER
//--------------------------------------------------------------------------
#define SMC_MISC_OFF        0x1c0cU

#define FM_SMC_MISC_MISC    (0xffffffffU << 0U)
#define FV_SMC_MISC_MISC(v) \
    (((v) << 0U) & FM_SMC_MISC_MISC)
#define GFV_SMC_MISC_MISC(v) \
    (((v) & FM_SMC_MISC_MISC) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : SMC_SUP_DOM_OFF
// Register Offset : 0x1c10
// Description     : SMC SUPER DOMAIN REGISTER
//--------------------------------------------------------------------------
#define SMC_SUP_DOM_OFF         0x1c10U

#define BM_SMC_SUP_DOM_LOCK (0x01U << 31U)

#define FM_SMC_SUP_DOM_PPROT    (0x3U << 5U)
#define FV_SMC_SUP_DOM_PPROT(v) \
    (((v) << 5U) & FM_SMC_SUP_DOM_PPROT)
#define GFV_SMC_SUP_DOM_PPROT(v) \
    (((v) & FM_SMC_SUP_DOM_PPROT) >> 5U)

#define BM_SMC_SUP_DOM_SEC_EN   (0x01U << 4U)

#define FM_SMC_SUP_DOM_DID  (0xfU << 0U)
#define FV_SMC_SUP_DOM_DID(v) \
    (((v) << 0U) & FM_SMC_SUP_DOM_DID)
#define GFV_SMC_SUP_DOM_DID(v) \
    (((v) & FM_SMC_SUP_DOM_DID) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : SWM_MON_OFF
// Register Offset : 0x1c14
// Description     : SWM STATUS MONITOR REGISTER
//--------------------------------------------------------------------------
#define SWM_MON_OFF         0x1c14U

#define FM_SWM_MON_AP_INTER_SWM (0x1fU << 21U)
#define FV_SWM_MON_AP_INTER_SWM(v) \
    (((v) << 21U) & FM_SWM_MON_AP_INTER_SWM)
#define GFV_SWM_MON_AP_INTER_SWM(v) \
    (((v) & FM_SWM_MON_AP_INTER_SWM) >> 21U)

#define FM_SWM_MON_SAF_INTER_SWM    (0x1fU << 16U)
#define FV_SWM_MON_SAF_INTER_SWM(v) \
    (((v) << 16U) & FM_SWM_MON_SAF_INTER_SWM)
#define GFV_SWM_MON_SAF_INTER_SWM(v) \
    (((v) & FM_SWM_MON_SAF_INTER_SWM) >> 16U)

#define FM_SWM_MON_SOC_SWM  (0xfU << 8U)
#define FV_SWM_MON_SOC_SWM(v) \
    (((v) << 8U) & FM_SWM_MON_SOC_SWM)
#define GFV_SWM_MON_SOC_SWM(v) \
    (((v) & FM_SWM_MON_SOC_SWM) >> 8U)

#define FM_SWM_MON_AP_SWM   (0xfU << 4U)
#define FV_SWM_MON_AP_SWM(v) \
    (((v) << 4U) & FM_SWM_MON_AP_SWM)
#define GFV_SWM_MON_AP_SWM(v) \
    (((v) & FM_SWM_MON_AP_SWM) >> 4U)

#define FM_SWM_MON_SAF_SWM  (0xfU << 0U)
#define FV_SWM_MON_SAF_SWM(v) \
    (((v) << 0U) & FM_SWM_MON_SAF_SWM)
#define GFV_SWM_MON_SAF_SWM(v) \
    (((v) & FM_SWM_MON_SAF_SWM) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : SMC_FUSA_RS_OFF
// Register Offset : 0x1d00
// Description     : SMC FUSA RELATED REGISTER RULE SPACE REGISTER
//--------------------------------------------------------------------------
#define SMC_FUSA_RS_OFF         0x1d00U

#define BM_SMC_FUSA_RS_LOCK (0x01U << 31U)

#define FM_SMC_FUSA_RS_RS   (0xfU << 1U)
#define FV_SMC_FUSA_RS_RS(v) \
    (((v) << 1U) & FM_SMC_FUSA_RS_RS)
#define GFV_SMC_FUSA_RS_RS(v) \
    (((v) & FM_SMC_FUSA_RS_RS) >> 1U)

#define BM_SMC_FUSA_RS_EN   (0x01U << 0U)

#define BM_APB_ERR_INT_PADDR_INT_CLR    (0x01U << 23U)

#define BM_APB_ERR_INT_PUSER_INT_CLR    (0x01U << 22U)

#define BM_APB_ERR_INT_PCTRL1_INT_CLR   (0x01U << 21U)

#define BM_APB_ERR_INT_PCTRL0_INT_CLR   (0x01U << 20U)

#define BM_APB_ERR_INT_PWDAT_C_INT_CLR  (0x01U << 19U)

#define BM_APB_ERR_INT_PWDAT_U_INT_CLR  (0x01U << 18U)

#define BM_APB_ERR_INT_PWDAT_F_INT_CLR  (0x01U << 17U)

#define BM_APB_ERR_INT_PADDR_INT_STA    (0x01U << 15U)

#define BM_APB_ERR_INT_PUSER_INT_STA    (0x01U << 14U)

#define BM_APB_ERR_INT_PCTRL1_INT_STA   (0x01U << 13U)

#define BM_APB_ERR_INT_PCTRL0_INT_STA   (0x01U << 12U)

#define BM_APB_ERR_INT_PWDAT_C_INT_STA  (0x01U << 11U)

#define BM_APB_ERR_INT_PWDAT_U_INT_STA  (0x01U << 10U)

#define BM_APB_ERR_INT_PWDAT_F_INT_STA  (0x01U << 9U)

#define BM_APB_ERR_INT_PADDR_INT_EN (0x01U << 7U)

#define BM_APB_ERR_INT_PUSER_INT_EN (0x01U << 6U)

#define BM_APB_ERR_INT_PCTRL1_INT_EN    (0x01U << 5U)

#define BM_APB_ERR_INT_PCTRL0_INT_EN    (0x01U << 4U)

#define BM_APB_ERR_INT_PWDAT_C_INT_EN   (0x01U << 3U)

#define BM_APB_ERR_INT_PWDAT_U_INT_EN   (0x01U << 2U)

#define BM_APB_ERR_INT_PWDAT_F_INT_EN   (0x01U << 1U)

#define BM_APB_LKSTEP_INT_SYNC_ERR_INT_CLR  (0x01U << 19U)

#define BM_APB_LKSTEP_INT_RESP_ERR_INT_CLR  (0x01U << 18U)

#define BM_APB_LKSTEP_INT_REQ_ERR_INT_CLR   (0x01U << 17U)

#define BM_APB_LKSTEP_INT_CMP_INT_CLR   (0x01U << 16U)

#define BM_APB_LKSTEP_INT_SYNC_ERR_INT_STA  (0x01U << 11U)

#define BM_APB_LKSTEP_INT_RESP_ERR_INT_STA  (0x01U << 10U)

#define BM_APB_LKSTEP_INT_REQ_ERR_INT_STA   (0x01U << 9U)

#define BM_APB_LKSTEP_INT_CMP_INT_STA   (0x01U << 8U)

#define BM_APB_LKSTEP_INT_SYNC_ERR_INT_EN   (0x01U << 3U)

#define BM_APB_LKSTEP_INT_RESP_ERR_INT_EN   (0x01U << 2U)

#define BM_APB_LKSTEP_INT_REQ_ERR_INT_EN    (0x01U << 1U)

#define BM_APB_LKSTEP_INT_CMP_INT_EN    (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : SMC_FUSA_INT_OFF
// Register Offset : 0x1d0c
// Description     : SMC INTERNAL FUSA INTERRUPT REGISTER
//--------------------------------------------------------------------------
#define SMC_FUSA_INT_OFF            0x1d0cU

#define BM_SMC_FUSA_INT_LKSTEP_CMP_ERR_CLR  (0x01U << 21U)

#define BM_SMC_FUSA_INT_SYNC_ERR_CLR    (0x01U << 20U)

#define BM_SMC_FUSA_INT_SOC_24M_ERR_CLR (0x01U << 19U)

#define BM_SMC_FUSA_INT_SMC_CFG_ERR_CLR (0x01U << 18U)

#define BM_SMC_FUSA_INT_TOUT_ERR_CLR    (0x01U << 17U)

#define BM_SMC_FUSA_INT_SWM_CHK_ERR_CLR (0x01U << 16U)

#define BM_SMC_FUSA_INT_LKSTEP_CMP_ERR_STA  (0x01U << 13U)

#define BM_SMC_FUSA_INT_SYNC_ERR_STA    (0x01U << 12U)

#define BM_SMC_FUSA_INT_SOC_24M_ERR_STA (0x01U << 11U)

#define BM_SMC_FUSA_INT_SMC_CFG_ERR_STA (0x01U << 10U)

#define BM_SMC_FUSA_INT_TOUT_ERR_STA    (0x01U << 9U)

#define BM_SMC_FUSA_INT_SWM_CHK_ERR_STA (0x01U << 8U)

#define BM_SMC_FUSA_INT_LKSTEP_CMP_ERR_EN   (0x01U << 5U)

#define BM_SMC_FUSA_INT_SYNC_ERR_EN (0x01U << 4U)

#define BM_SMC_FUSA_INT_SOC_24M_ERR_EN  (0x01U << 3U)

#define BM_SMC_FUSA_INT_SMC_CFG_ERR_EN  (0x01U << 2U)

#define BM_SMC_FUSA_INT_TOUT_ERR_EN (0x01U << 1U)

#define BM_SMC_FUSA_INT_SWM_CHK_ERR_EN  (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : SMC_TOUT_STA_OFF
// Register Offset : 0x1d10
// Description     : SMC TIMEOUT EVENT MONITOR STATUS REGISTER
//--------------------------------------------------------------------------
#define SMC_TOUT_STA_OFF            0x1d10U

#define BM_SMC_TOUT_STA_TOUT_15 (0x01U << 15U)

#define BM_SMC_TOUT_STA_TOUT_14 (0x01U << 14U)

#define BM_SMC_TOUT_STA_TOUT_13 (0x01U << 13U)

#define BM_SMC_TOUT_STA_TOUT_12 (0x01U << 12U)

#define BM_SMC_TOUT_STA_TOUT_11 (0x01U << 11U)

#define BM_SMC_TOUT_STA_TOUT_10 (0x01U << 10U)

#define BM_SMC_TOUT_STA_TOUT_9  (0x01U << 9U)

#define BM_SMC_TOUT_STA_TOUT_8  (0x01U << 8U)

#define BM_SMC_TOUT_STA_TOUT_7  (0x01U << 7U)

#define BM_SMC_TOUT_STA_TOUT_6  (0x01U << 6U)

#define BM_SMC_TOUT_STA_TOUT_5  (0x01U << 5U)

#define BM_SMC_TOUT_STA_TOUT_4  (0x01U << 4U)

#define BM_SMC_TOUT_STA_TOUT_3  (0x01U << 3U)

#define BM_SMC_TOUT_STA_TOUT_2  (0x01U << 2U)

#define BM_SMC_TOUT_STA_TOUT_1  (0x01U << 1U)

#define BM_SMC_TOUT_STA_TOUT_0  (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : SMC_ILL_TRANS_STA_OFF
// Register Offset : 0x1d14
// Description     : SMC ILLEGAL TRANSFER EVENT MONITOR STATUS REGISTER
//--------------------------------------------------------------------------
#define SMC_ILL_TRANS_STA_OFF           0x1d14U

#define BM_SMC_ILL_TRANS_STA_ILL_TRANS_9    (0x01U << 9U)

#define BM_SMC_ILL_TRANS_STA_ILL_TRANS_8    (0x01U << 8U)

#define BM_SMC_ILL_TRANS_STA_ILL_TRANS_7    (0x01U << 7U)

#define BM_SMC_ILL_TRANS_STA_ILL_TRANS_6    (0x01U << 6U)

#define BM_SMC_ILL_TRANS_STA_ILL_TRANS_5    (0x01U << 5U)

#define BM_SMC_ILL_TRANS_STA_ILL_TRANS_4    (0x01U << 4U)

#define BM_SMC_ILL_TRANS_STA_ILL_TRANS_3    (0x01U << 3U)

#define BM_SMC_ILL_TRANS_STA_ILL_TRANS_2    (0x01U << 2U)

#define BM_SMC_ILL_TRANS_STA_ILL_TRANS_1    (0x01U << 1U)

#define BM_SMC_ILL_TRANS_STA_ILL_TRANS_0    (0x01U << 0U)

#define BM_WDT_LKSTEP_INT_CMP_ERR_CLR   (0x01U << 18U)

#define BM_WDT_LKSTEP_INT_SYNC_ERR_CLR  (0x01U << 17U)

#define BM_WDT_LKSTEP_INT_TOUT_CHK_ERR_CLR  (0x01U << 16U)

#define BM_WDT_LKSTEP_INT_CMP_ERR_STA   (0x01U << 10U)

#define BM_WDT_LKSTEP_INT_SYNC_ERR_STA  (0x01U << 9U)

#define BM_WDT_LKSTEP_INT_TOUT_CHK_ERR_STA  (0x01U << 8U)

#define BM_WDT_LKSTEP_INT_CMP_ERR_EN    (0x01U << 2U)

#define BM_WDT_LKSTEP_INT_SYNC_ERR_EN   (0x01U << 1U)

#define BM_WDT_LKSTEP_INT_TOUT_CHK_ERR_EN   (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : SMC_INJ_EN_OFF
// Register Offset : 0x1d1c
// Description     : SMC ERROR INJECTION ENABLE
//--------------------------------------------------------------------------
#define SMC_INJ_EN_OFF              0x1d1cU

#define FM_SMC_INJ_EN_INJ_EN    (0xffffU << 0U)
#define FV_SMC_INJ_EN_INJ_EN(v) \
    (((v) << 0U) & FM_SMC_INJ_EN_INJ_EN)
#define GFV_SMC_INJ_EN_INJ_EN(v) \
    (((v) & FM_SMC_INJ_EN_INJ_EN) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : SMC_INJ_BIT
// Register Offset : 0x1d20
// Description     : SMC ERROR INJECTION REGISTER
//--------------------------------------------------------------------------
#define SMC_INJ_BIT             0x1d20U

#define FM_SMC_INJ_BIT_IRQ_INJ  (0x7U << 29U)
#define FV_SMC_INJ_BIT_IRQ_INJ(v) \
    (((v) << 29U) & FM_SMC_INJ_BIT_IRQ_INJ)
#define GFV_SMC_INJ_BIT_IRQ_INJ(v) \
    (((v) & FM_SMC_INJ_BIT_IRQ_INJ) >> 29U)

#define FM_SMC_INJ_BIT_ERR_INJ_BIT  (0x1fffffffU << 0U)
#define FV_SMC_INJ_BIT_ERR_INJ_BIT(v) \
    (((v) << 0U) & FM_SMC_INJ_BIT_ERR_INJ_BIT)
#define GFV_SMC_INJ_BIT_ERR_INJ_BIT(v) \
    (((v) & FM_SMC_INJ_BIT_ERR_INJ_BIT) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : SMC_INJ_BIT_1_OFF
// Register Offset : 0x1d24
// Description     : SMC ERROR INJECTION REGISTER
//--------------------------------------------------------------------------
#define SMC_INJ_BIT_1_OFF           0x1d24U

#define FM_SMC_INJ_BIT_1_ERR_INJ_BIT    (0xffffffffU << 0U)
#define FV_SMC_INJ_BIT_1_ERR_INJ_BIT(v) \
    (((v) << 0U) & FM_SMC_INJ_BIT_1_ERR_INJ_BIT)
#define GFV_SMC_INJ_BIT_1_ERR_INJ_BIT(v) \
    (((v) & FM_SMC_INJ_BIT_1_ERR_INJ_BIT) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : SMC_INJ_BIT_2_OFF
// Register Offset : 0x1d28
// Description     : SMC ERROR INJECTION REGISTER
//--------------------------------------------------------------------------
#define SMC_INJ_BIT_2_OFF           0x1d28U

#define FM_SMC_INJ_BIT_2_ERR_INJ_BIT    (0xffffffffU << 0U)
#define FV_SMC_INJ_BIT_2_ERR_INJ_BIT(v) \
    (((v) << 0U) & FM_SMC_INJ_BIT_2_ERR_INJ_BIT)
#define GFV_SMC_INJ_BIT_2_ERR_INJ_BIT(v) \
    (((v) & FM_SMC_INJ_BIT_2_ERR_INJ_BIT) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : SMC_FUNC_INT_RS_OFF
// Register Offset : 0x1d40
// Description     : This register is used for assign rule space for rstgen function interrupt register
//--------------------------------------------------------------------------
#define SMC_FUNC_INT_RS_OFF         0x1d40U

#define BM_SMC_FUNC_INT_RS_LOCK (0x01U << 31U)

#define FM_SMC_FUNC_INT_RS_RS   (0xfU << 1U)
#define FV_SMC_FUNC_INT_RS_RS(v) \
    (((v) << 1U) & FM_SMC_FUNC_INT_RS_RS)
#define GFV_SMC_FUNC_INT_RS_RS(v) \
    (((v) & FM_SMC_FUNC_INT_RS_RS) >> 1U)

#define BM_SMC_FUNC_INT_RS_EN   (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : SMC_FUNC_INT_OFF
// Register Offset : 0x1d44
// Description     : SMC FUNC INTERRUPT REGISTER
//--------------------------------------------------------------------------
#define SMC_FUNC_INT_OFF            0x1d44U

#define BM_SMC_FUNC_INT_ACCESS_PER_ERR_CLR  (0x01U << 16U)

#define BM_SMC_FUNC_INT_ACCESS_PER_ERR_STA  (0x01U << 8U)

#define BM_SMC_FUNC_INT_ACCESS_PER_ERR_EN   (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : SMC_DBG_SEL_OFF
// Register Offset : 0x1f00
// Description     : SMC DEBUG SELECT REGISTER
//--------------------------------------------------------------------------
#define SMC_DBG_SEL_OFF         0x1f00U

#define FM_SMC_DBG_SEL_SEL  (0x7U << 0U)
#define FV_SMC_DBG_SEL_SEL(v) \
    (((v) << 0U) & FM_SMC_DBG_SEL_SEL)
#define GFV_SMC_DBG_SEL_SEL(v) \
    (((v) & FM_SMC_DBG_SEL_SEL) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : SMC_DBG_MON_OFF
// Register Offset : 0x1f04
// Description     : SMC DEBUG MONITOR REGISTER
//--------------------------------------------------------------------------
#define SMC_DBG_MON_OFF         0x1f04U

#define FM_SMC_DBG_MON_MON  (0xffffffffU << 0U)
#define FV_SMC_DBG_MON_MON(v) \
    (((v) << 0U) & FM_SMC_DBG_MON_MON)
#define GFV_SMC_DBG_MON_MON(v) \
    (((v) & FM_SMC_DBG_MON_MON) >> 0U)


#ifdef __cplusplus
}
#endif

#endif  /* SMC_REG_H */
