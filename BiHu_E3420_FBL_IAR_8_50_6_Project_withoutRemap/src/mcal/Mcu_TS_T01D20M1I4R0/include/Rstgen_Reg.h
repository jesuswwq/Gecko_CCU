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

#ifndef __RSTGEN_REG_TS_H__
#define __RSTGEN_REG_TS_H__

//--------------------------------------------------------------------------
// Register Name   : DOM_PER0_OFF
// Register Offset : 0x0
// Description     : This register is used for to control domain0~3 secure and priviledge access permission.
//--------------------------------------------------------------------------
#define DOM_PER0_OFF(n) (0x0U + 12U*(n))

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

#define DOM_PER1_OFF(n) (0x4U + 12U*(n))

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
#define DOM_PER_LOCK_OFF(n) (0x8U + 12U*(n))

#define BM_DOM_PER_LOCK_DOM7_LOCK   (0x01U << 7U)

#define BM_DOM_PER_LOCK_DOM6_LOCK   (0x01U << 6U)

#define BM_DOM_PER_LOCK_DOM5_LOCK   (0x01U << 5U)

#define BM_DOM_PER_LOCK_DOM4_LOCK   (0x01U << 4U)

#define BM_DOM_PER_LOCK_DOM3_LOCK   (0x01U << 3U)

#define BM_DOM_PER_LOCK_DOM2_LOCK   (0x01U << 2U)

#define BM_DOM_PER_LOCK_DOM1_LOCK   (0x01U << 1U)

#define BM_DOM_PER_LOCK_DOM0_LOCK   (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : GLOBAL_RESET_RS_OFF
// Register Offset : 0x200
// Description     : This register is used for assign rule space for global reset control
//--------------------------------------------------------------------------
#define GLOBAL_RESET_RS_OFF 0x200U

#define BM_GLOBAL_RESET_RS_LOCK (0x01U << 31U)

#define FM_GLOBAL_RESET_RS_RS   (0xfU << 1U)
#define FV_GLOBAL_RESET_RS_RS(v) \
    (((v) << 1U) & FM_GLOBAL_RESET_RS_RS)
#define GFV_GLOBAL_RESET_RS_RS(v) \
    (((v) & FM_GLOBAL_RESET_RS_RS) >> 1U)

#define BM_GLOBAL_RESET_RS_EN   (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : GLOBAL_RESET_CONTROL_OFF
// Register Offset : 0x204
// Description     : This register is used for global reset control
//--------------------------------------------------------------------------
#define GLOBAL_RESET_CONTROL_OFF    0x204U

#define BM_GLOBAL_RESET_CONTROL_SS_RDY  (0x01U << 31U)

#define BM_GLOBAL_RESET_CONTROL_TEST_IST_EN (0x01U << 29U)

#define BM_GLOBAL_RESET_CONTROL_SW_GLB_RST  (0x01U << 28U)

#define BM_GLOBAL_RESET_CONTROL_SW_GLB_RST_EN   (0x01U << 27U)

#define FM_GLOBAL_RESET_CONTROL_RST_REQ_EN  (0xffU << 19U)
#define FV_GLOBAL_RESET_CONTROL_RST_REQ_EN(v) \
    (((v) << 19U) & FM_GLOBAL_RESET_CONTROL_RST_REQ_EN)
#define GFV_GLOBAL_RESET_CONTROL_RST_REQ_EN(v) \
    (((v) & FM_GLOBAL_RESET_CONTROL_RST_REQ_EN) >> 19U)

#define FM_GLOBAL_RESET_CONTROL_WDT2_EN (0xffU << 11U)
#define FV_GLOBAL_RESET_CONTROL_WDT2_EN(v) \
    (((v) << 11U) & FM_GLOBAL_RESET_CONTROL_WDT2_EN)
#define GFV_GLOBAL_RESET_CONTROL_WDT2_EN(v) \
    (((v) & FM_GLOBAL_RESET_CONTROL_WDT2_EN) >> 11U)

#define FM_GLOBAL_RESET_CONTROL_WDT1_EN (0xffU << 3U)
#define FV_GLOBAL_RESET_CONTROL_WDT1_EN(v) \
    (((v) << 3U) & FM_GLOBAL_RESET_CONTROL_WDT1_EN)
#define GFV_GLOBAL_RESET_CONTROL_WDT1_EN(v) \
    (((v) & FM_GLOBAL_RESET_CONTROL_WDT1_EN) >> 3U)

#define BM_GLOBAL_RESET_CONTROL_SEC_VIO_EN  (0x01U << 2U)

#define BM_GLOBAL_RESET_CONTROL_SEM_EN  (0x01U << 1U)

#define BM_GLOBAL_RESET_CONTROL_SYS_PANIC_EN    (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : GLOBAL_RESET_STA_OFF
// Register Offset : 0x208
// Description     : GLOBAL RESET STATUS REGISTER
//--------------------------------------------------------------------------
#define GLOBAL_RESET_STA_OFF    0x208U

#define FM_GLOBAL_RESET_STA_GLB_STA_LAST    (0xffffffffU << 0U)
#define FV_GLOBAL_RESET_STA_GLB_STA_LAST(v) \
    (((v) << 0U) & FM_GLOBAL_RESET_STA_GLB_STA_LAST)
#define GFV_GLOBAL_RESET_STA_GLB_STA_LAST(v) \
    (((v) & FM_GLOBAL_RESET_STA_GLB_STA_LAST) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : GLOBAL_RESET_STA_ALL_OFF
// Register Offset : 0x20c
// Description     : GLOBAL RESET STATUS REGISTER
//--------------------------------------------------------------------------
#define GLOBAL_RESET_STA_ALL_OFF    0x20cU

#define FM_GLOBAL_RESET_STA_ALL_GLB_STA_ALL (0xffffffffU << 0U)
#define FV_GLOBAL_RESET_STA_ALL_GLB_STA_ALL(v) \
    (((v) << 0U) & FM_GLOBAL_RESET_STA_ALL_GLB_STA_ALL)
#define GFV_GLOBAL_RESET_STA_ALL_GLB_STA_ALL(v) \
    (((v) & FM_GLOBAL_RESET_STA_ALL_GLB_STA_ALL) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : GLOBAL_ERR_STA_ALL_OFF
// Register Offset : 0x210
// Description     : GLOBAL ERROR STATUS REGISTER
//--------------------------------------------------------------------------
#define GLOBAL_ERR_STA_ALL_OFF  0x210U

#define FM_GLOBAL_ERR_STA_ALL_ERR_STA_ALL   (0xffffffffU << 0U)
#define FV_GLOBAL_ERR_STA_ALL_ERR_STA_ALL(v) \
    (((v) << 0U) & FM_GLOBAL_ERR_STA_ALL_ERR_STA_ALL)
#define GFV_GLOBAL_ERR_STA_ALL_ERR_STA_ALL(v) \
    (((v) & FM_GLOBAL_ERR_STA_ALL_ERR_STA_ALL) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : IST_RESET_RS_OFF
// Register Offset : 0x1000
// Description     : This register is used for assign rule space for ist reset control
//--------------------------------------------------------------------------
#define IST_RESET_RS_OFF    0x1000U

#define BM_IST_RESET_RS_LOCK    (0x01U << 31U)

#define FM_IST_RESET_RS_RS  (0xfU << 1U)
#define FV_IST_RESET_RS_RS(v) \
    (((v) << 1U) & FM_IST_RESET_RS_RS)
#define GFV_IST_RESET_RS_RS(v) \
    (((v) & FM_IST_RESET_RS_RS) >> 1U)

#define BM_IST_RESET_RS_EN  (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : IST_RESET_CONTROL_OFF
// Register Offset : 0x1004
// Description     : This register is used for ist reset control
//--------------------------------------------------------------------------
#define IST_RESET_CONTROL_OFF   0x1004U

#define BM_IST_RESET_CONTROL_RMON_O (0x01U << 31U)

#define BM_IST_RESET_CONTROL_RMON_I (0x01U << 30U)

#define BM_IST_RESET_CONTROL_RSTA   (0x01U << 29U)

#define BM_IST_RESET_CONTROL_AUTO_CLR_RST_B (0x01U << 6U)

#define BM_IST_RESET_CONTROL_SLP_MODE   (0x01U << 2U)

#define BM_IST_RESET_CONTROL_HIB_MODE   (0x01U << 1U)

#define BM_IST_RESET_CONTROL_RUN_MODE   (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : MISSION_RESET_RS_OFF
// Register Offset : 0x1100
// Description     : This register is used for assign rule space for mission reset control
//--------------------------------------------------------------------------
#define MISSION_RESET_RS_OFF(n) (0x1100U + 8U*(n))

#define BM_MISSION_RESET_RS_LOCK    (0x01U << 31U)

#define FM_MISSION_RESET_RS_RS  (0xfU << 1U)
#define FV_MISSION_RESET_RS_RS(v) \
    (((v) << 1U) & FM_MISSION_RESET_RS_RS)
#define GFV_MISSION_RESET_RS_RS(v) \
    (((v) & FM_MISSION_RESET_RS_RS) >> 1U)

#define BM_MISSION_RESET_RS_EN  (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : MISSION_RESET_CONTROL_OFF
// Register Offset : 0x1104
// Description     : This register is used for mission reset control
//--------------------------------------------------------------------------
#define MISSION_RESET_CONTROL_OFF(n)    (0x1104U + 8U*(n))

#define BM_MISSION_RESET_CONTROL_RMON_O (0x01U << 31U)

#define BM_MISSION_RESET_CONTROL_RMON_I (0x01U << 30U)

#define BM_MISSION_RESET_CONTROL_RSTA   (0x01U << 29U)

#define BM_MISSION_RESET_CONTROL_LOCK   (0x01U << 28U)

#define BM_MISSION_RESET_CONTROL_AUTO_CLR_RST_B (0x01U << 6U)

#define BM_MISSION_RESET_CONTROL_SLP_MODE   (0x01U << 2U)

#define BM_MISSION_RESET_CONTROL_HIB_MODE   (0x01U << 1U)

#define BM_MISSION_RESET_CONTROL_RUN_MODE   (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : LATENT_RESET_RS_OFF
// Register Offset : 0x1200
// Description     : This register is used for assign rule space for latent reset control
//--------------------------------------------------------------------------
#define LATENT_RESET_RS_OFF(n)  (0x1200U + 8U*(n))

#define BM_LATENT_RESET_RS_LOCK (0x01U << 31U)

#define FM_LATENT_RESET_RS_RS   (0xfU << 1U)
#define FV_LATENT_RESET_RS_RS(v) \
    (((v) << 1U) & FM_LATENT_RESET_RS_RS)
#define GFV_LATENT_RESET_RS_RS(v) \
    (((v) & FM_LATENT_RESET_RS_RS) >> 1U)

#define BM_LATENT_RESET_RS_EN   (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : REG_AP_APB0_RSTGEN_LATENT_RESET_CONTROL
// Register Offset : 0x1204
// Description     : This register is used for latent reset control
//--------------------------------------------------------------------------
#define LATENT_RESET_CONTROL_OFF(n) (0x1204U + 8U*(n))

#define BM_LATENT_RESET_CONTROL_RMON_O  (0x01U << 31U)

#define BM_LATENT_RESET_CONTROL_RMON_I  (0x01U << 30U)

#define BM_LATENT_RESET_CONTROL_RSTA    (0x01U << 29U)

#define BM_LATENT_RESET_CONTROL_LOCK    (0x01U << 28U)

#define BM_LATENT_RESET_CONTROL_AUTO_CLR_RST_B  (0x01U << 6U)

#define BM_LATENT_RESET_CONTROL_SLP_MODE    (0x01U << 2U)

#define BM_LATENT_RESET_CONTROL_HIB_MODE    (0x01U << 1U)

#define BM_LATENT_RESET_CONTROL_RUN_MODE    (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : MODULE_RESET_RS_OFF
// Register Offset : 0x1300
// Description     : This register is used for assign rule space for module reset control
//--------------------------------------------------------------------------
#define MODULE_RESET_RS_OFF(n)  (0x1300U + 8U*(n))

#define BM_MODULE_RESET_RS_LOCK (0x01U << 31U)

#define FM_MODULE_RESET_RS_RS   (0xfU << 1U)
#define FV_MODULE_RESET_RS_RS(v) \
    (((v) << 1U) & FM_MODULE_RESET_RS_RS)
#define GFV_MODULE_RESET_RS_RS(v) \
    (((v) & FM_MODULE_RESET_RS_RS) >> 1U)

#define BM_MODULE_RESET_RS_EN   (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : MODULE_RESET_CONTROL_OFF
// Register Offset : 0x1304
// Description     : This register is used for module reset control
//--------------------------------------------------------------------------
#define MODULE_RESET_CONTROL_OFF(n) (0x1304U + 8U*(n))

#define BM_MODULE_RESET_CONTROL_RMON_O  (0x01U << 31U)

#define BM_MODULE_RESET_CONTROL_RMON_I  (0x01U << 30U)

#define BM_MODULE_RESET_CONTROL_RSTA    (0x01U << 29U)

#define FM_MODULE_RESET_CONTROL_BTI_TOUT_VAL    (0xfU << 8U)
#define FV_MODULE_RESET_CONTROL_BTI_TOUT_VAL(v) \
    (((v) << 8U) & FM_MODULE_RESET_CONTROL_BTI_TOUT_VAL)
#define GFV_MODULE_RESET_CONTROL_BTI_TOUT_VAL(v) \
    (((v) & FM_MODULE_RESET_CONTROL_BTI_TOUT_VAL) >> 8U)

#define BM_MODULE_RESET_CONTROL_AUTO_CLR_RST_B  (0x01U << 6U)

#define BM_MODULE_RESET_CONTROL_SLP_MODE    (0x01U << 2U)

#define BM_MODULE_RESET_CONTROL_HIB_MODE    (0x01U << 1U)

#define BM_MODULE_RESET_CONTROL_RUN_MODE    (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : CORE_RESET_RS_OFF
// Register Offset : 0x1a00
// Description     : This register is used for assign rule space for core reset control
//--------------------------------------------------------------------------
#define CORE_RESET_RS_OFF(n)    (0x1a00U + 8U*(n))

#define BM_CORE_RESET_RS_LOCK   (0x01U << 31U)

#define FM_CORE_RESET_RS_RS (0xfU << 1U)
#define FV_CORE_RESET_RS_RS(v) \
    (((v) << 1U) & FM_CORE_RESET_RS_RS)
#define GFV_CORE_RESET_RS_RS(v) \
    (((v) & FM_CORE_RESET_RS_RS) >> 1U)

#define BM_CORE_RESET_RS_EN (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : CORE_RESET_CONTROL_OFF
// Register Offset : 0x1a04
// Description     : This register is used for core reset control
//--------------------------------------------------------------------------
#define CORE_RESET_CONTROL_OFF(n)   (0x1a04U + 8U*(n))

#define BM_CORE_RESET_CONTROL_RMON_O    (0x01U << 31U)

#define BM_CORE_RESET_CONTROL_RMON_I    (0x01U << 30U)

#define BM_CORE_RESET_CONTROL_RSTA  (0x01U << 29U)

#define FM_CORE_RESET_CONTROL_BTI_TOUT_VAL  (0xfU << 8U)
#define FV_CORE_RESET_CONTROL_BTI_TOUT_VAL(v) \
    (((v) << 8U) & FM_CORE_RESET_CONTROL_BTI_TOUT_VAL)
#define GFV_CORE_RESET_CONTROL_BTI_TOUT_VAL(v) \
    (((v) & FM_CORE_RESET_CONTROL_BTI_TOUT_VAL) >> 8U)

#define BM_CORE_RESET_CONTROL_AUTO_CLR_RST_B    (0x01U << 6U)

#define BM_CORE_RESET_CONTROL_RST_REQ_EN    (0x01U << 5U)

#define BM_CORE_RESET_CONTROL_WDT2_RST_EN   (0x01U << 4U)

#define BM_CORE_RESET_CONTROL_WDT1_RST_EN   (0x01U << 3U)

#define BM_CORE_RESET_CONTROL_SLP_MODE  (0x01U << 2U)

#define BM_CORE_RESET_CONTROL_HIB_MODE  (0x01U << 1U)

#define BM_CORE_RESET_CONTROL_RUN_MODE  (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : DBG_RESET_RS_OFF
// Register Offset : 0x1b00
// Description     : This register is used for assign rule space for dbg reset control
//--------------------------------------------------------------------------
#define DBG_RESET_RS_OFF    0x1b00U

#define BM_DBG_RESET_RS_LOCK    (0x01U << 31U)

#define FM_DBG_RESET_RS_RS  (0xfU << 1U)
#define FV_DBG_RESET_RS_RS(v) \
    (((v) << 1U) & FM_DBG_RESET_RS_RS)
#define GFV_DBG_RESET_RS_RS(v) \
    (((v) & FM_DBG_RESET_RS_RS) >> 1U)

#define BM_DBG_RESET_RS_EN  (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : DBG_RESET_CONTROL_OFF
// Register Offset : 0x1b04
// Description     : This register is used for dbg reset control
//--------------------------------------------------------------------------
#define DBG_RESET_CONTROL_OFF   0x1b04U

#define BM_DBG_RESET_CONTROL_RMON_O (0x01U << 31U)

#define BM_DBG_RESET_CONTROL_RMON_I (0x01U << 30U)

#define BM_DBG_RESET_CONTROL_RSTA   (0x01U << 29U)

#define BM_DBG_RESET_CONTROL_DBG_REQ_EN (0x01U << 8U)

#define BM_DBG_RESET_CONTROL_AUTO_CLR_RST_B (0x01U << 6U)

#define BM_DBG_RESET_CONTROL_SLP_MODE   (0x01U << 2U)

#define BM_DBG_RESET_CONTROL_HIB_MODE   (0x01U << 1U)

#define BM_DBG_RESET_CONTROL_RUN_MODE   (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : SW_RESET_PASSWORD_CONTROL_OFF
// Register Offset : 0x1c00
// Description     : SW RESET PASSWORD CONTROL REGISTER
//--------------------------------------------------------------------------
#define SW_RESET_PASSWORD_CONTROL_OFF   0x1c00U

#define BM_SW_RESET_PASSWORD_CONTROL_LOCK   (0x01U << 31U)

#define BM_SW_RESET_PASSWORD_CONTROL_EN (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : SW_RESET_PASSWORD_OFF
// Register Offset : 0x1c04
// Description     : This register is used for protecting un-expected sw reset
//--------------------------------------------------------------------------
#define SW_RESET_PASSWORD_OFF   0x1c04U

#define FM_SW_RESET_PASSWORD_PW (0xffffffffU << 0U)
#define FV_SW_RESET_PASSWORD_PW(v) \
    (((v) << 0U) & FM_SW_RESET_PASSWORD_PW)
#define GFV_SW_RESET_PASSWORD_PW(v) \
    (((v) & FM_SW_RESET_PASSWORD_PW) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : GENERAL_REG_RS_OFF
// Register Offset : 0x2000
// Description     : This register is used for assign rule space for general reigster
//--------------------------------------------------------------------------
#define GENERAL_REG_RS_OFF(n)   (0x2000U + 8U*(n))

#define BM_GENERAL_REG_RS_LOCK  (0x01U << 31U)

#define FM_GENERAL_REG_RS_RS    (0xfU << 1U)
#define FV_GENERAL_REG_RS_RS(v) \
    (((v) << 1U) & FM_GENERAL_REG_RS_RS)
#define GFV_GENERAL_REG_RS_RS(v) \
    (((v) & FM_GENERAL_REG_RS_RS) >> 1U)

#define BM_GENERAL_REG_RS_EN    (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : GENERAL_REG_OFF
// Register Offset : 0x2004
// Description     : This register is used for general purpose
//--------------------------------------------------------------------------
#define GENERAL_REG_OFF(n)  (0x2004U + 8U*(n))

#define FM_GENERAL_REG_GENERAL  (0xffffffffU << 0U)
#define FV_GENERAL_REG_GENERAL(v) \
    (((v) << 0U) & FM_GENERAL_REG_GENERAL)
#define GFV_GENERAL_REG_GENERAL(v) \
    (((v) & FM_GENERAL_REG_GENERAL) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : BOOT_MODE_RS_OFF
// Register Offset : 0x3000
// Description     : This register is used for assign rule space for boot mode
//--------------------------------------------------------------------------
#define BOOT_MODE_RS_OFF    0x3000U

#define BM_BOOT_MODE_RS_LOCK    (0x01U << 31U)

#define FM_BOOT_MODE_RS_RS  (0xfU << 1U)
#define FV_BOOT_MODE_RS_RS(v) \
    (((v) << 1U) & FM_BOOT_MODE_RS_RS)
#define GFV_BOOT_MODE_RS_RS(v) \
    (((v) & FM_BOOT_MODE_RS_RS) >> 1U)

#define BM_BOOT_MODE_RS_EN  (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : BOOT_MODE_OFF
// Register Offset : 0x3004
// Description     : This register is used for record boot mode
//--------------------------------------------------------------------------
#define BOOT_MODE_OFF   0x3004U

#define FM_BOOT_MODE_BOOT_MODE  (0x7fU << 0U)
#define FV_BOOT_MODE_BOOT_MODE(v) \
    (((v) << 0U) & FM_BOOT_MODE_BOOT_MODE)
#define GFV_BOOT_MODE_BOOT_MODE(v) \
    (((v) & FM_BOOT_MODE_BOOT_MODE) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : RESET_FLOW_TIME_RS_OFF
// Register Offset : 0x3100
// Description     : This register is used for assign rule space for reset flow time
//--------------------------------------------------------------------------
#define RESET_FLOW_TIME_RS_OFF  0x3100U

#define BM_RESET_FLOW_TIME_RS_LOCK  (0x01U << 31U)

#define FM_RESET_FLOW_TIME_RS_RS    (0xfU << 1U)
#define FV_RESET_FLOW_TIME_RS_RS(v) \
    (((v) << 1U) & FM_RESET_FLOW_TIME_RS_RS)
#define GFV_RESET_FLOW_TIME_RS_RS(v) \
    (((v) & FM_RESET_FLOW_TIME_RS_RS) >> 1U)

#define BM_RESET_FLOW_TIME_RS_EN    (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : RESET_FLOW_TIME_CONTROL_OFF
// Register Offset : 0x3104
// Description     : This register is used for global reset flow time
//--------------------------------------------------------------------------
#define RESET_FLOW_TIME_CONTROL_OFF 0x3104U

#define FM_RESET_FLOW_TIME_CONTROL_T4   (0x1fU << 23U)
#define FV_RESET_FLOW_TIME_CONTROL_T4(v) \
    (((v) << 23U) & FM_RESET_FLOW_TIME_CONTROL_T4)
#define GFV_RESET_FLOW_TIME_CONTROL_T4(v) \
    (((v) & FM_RESET_FLOW_TIME_CONTROL_T4) >> 23U)

#define FM_RESET_FLOW_TIME_CONTROL_T3   (0x1fU << 18U)
#define FV_RESET_FLOW_TIME_CONTROL_T3(v) \
    (((v) << 18U) & FM_RESET_FLOW_TIME_CONTROL_T3)
#define GFV_RESET_FLOW_TIME_CONTROL_T3(v) \
    (((v) & FM_RESET_FLOW_TIME_CONTROL_T3) >> 18U)

#define FM_RESET_FLOW_TIME_CONTROL_T2   (0xffU << 10U)
#define FV_RESET_FLOW_TIME_CONTROL_T2(v) \
    (((v) << 10U) & FM_RESET_FLOW_TIME_CONTROL_T2)
#define GFV_RESET_FLOW_TIME_CONTROL_T2(v) \
    (((v) & FM_RESET_FLOW_TIME_CONTROL_T2) >> 10U)

#define FM_RESET_FLOW_TIME_CONTROL_T1   (0x1fU << 5U)
#define FV_RESET_FLOW_TIME_CONTROL_T1(v) \
    (((v) << 5U) & FM_RESET_FLOW_TIME_CONTROL_T1)
#define GFV_RESET_FLOW_TIME_CONTROL_T1(v) \
    (((v) & FM_RESET_FLOW_TIME_CONTROL_T1) >> 5U)

#define FM_RESET_FLOW_TIME_CONTROL_T0   (0x1fU << 0U)
#define FV_RESET_FLOW_TIME_CONTROL_T0(v) \
    (((v) << 0U) & FM_RESET_FLOW_TIME_CONTROL_T0)
#define GFV_RESET_FLOW_TIME_CONTROL_T0(v) \
    (((v) & FM_RESET_FLOW_TIME_CONTROL_T0) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : RSTGEN_RES_RS_OFF
// Register Offset : 0x3200
// Description     : This register is used for assign rule space for rstgen reserve register
//--------------------------------------------------------------------------
#define RSTGEN_RES_RS_OFF   0x3200U

#define BM_RSTGEN_RES_RS_LOCK   (0x01U << 31U)

#define FM_RSTGEN_RES_RS_RS (0xfU << 1U)
#define FV_RSTGEN_RES_RS_RS(v) \
    (((v) << 1U) & FM_RSTGEN_RES_RS_RS)
#define GFV_RSTGEN_RES_RS_RS(v) \
    (((v) & FM_RSTGEN_RES_RS_RS) >> 1U)

#define BM_RSTGEN_RES_RS_EN (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : RSTGEN_RES_OFF
// Register Offset : 0x3204
// Description     : RSTGEN RESERVE REGISTER
//--------------------------------------------------------------------------
#define RSTGEN_RES_OFF  0x3204U

#define FM_RSTGEN_RES_RES   (0xffffffffU << 0U)
#define FV_RSTGEN_RES_RES(v) \
    (((v) << 0U) & FM_RSTGEN_RES_RES)
#define GFV_RSTGEN_RES_RES(v) \
    (((v) & FM_RSTGEN_RES_RES) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : RSTGEN_MISC_RS_OFF
// Register Offset : 0x3300
// Description     : This register is used for assign rule space for rstgen misc register
//--------------------------------------------------------------------------
#define RSTGEN_MISC_RS_OFF  0x3300U

#define BM_RSTGEN_MISC_RS_LOCK  (0x01U << 31U)

#define FM_RSTGEN_MISC_RS_RS    (0xfU << 1U)
#define FV_RSTGEN_MISC_RS_RS(v) \
    (((v) << 1U) & FM_RSTGEN_MISC_RS_RS)
#define GFV_RSTGEN_MISC_RS_RS(v) \
    (((v) & FM_RSTGEN_MISC_RS_RS) >> 1U)

#define BM_RSTGEN_MISC_RS_EN    (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : RSTGEN_MISC_OFF
// Register Offset : 0x3304
// Description     : RSTGEN MISC REGISTER
//--------------------------------------------------------------------------
#define RSTGEN_MISC_OFF 0x3304U

#define FM_RSTGEN_MISC_MISC (0xffffffffU << 0U)
#define FV_RSTGEN_MISC_MISC(v) \
    (((v) << 0U) & FM_RSTGEN_MISC_MISC)
#define GFV_RSTGEN_MISC_MISC(v) \
    (((v) & FM_RSTGEN_MISC_MISC) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : RSTGEN_SUP_DOM_OFF
// Register Offset : 0x3400
// Description     : RSTGEN SUPER DOMAIN REGISTER
//--------------------------------------------------------------------------
#define RSTGEN_SUP_DOM_OFF  0x3400U

#define BM_RSTGEN_SUP_DOM_LOCK  (0x01U << 31U)

#define FM_RSTGEN_SUP_DOM_PPROT (0x3U << 5U)
#define FV_RSTGEN_SUP_DOM_PPROT(v) \
    (((v) << 5U) & FM_RSTGEN_SUP_DOM_PPROT)
#define GFV_RSTGEN_SUP_DOM_PPROT(v) \
    (((v) & FM_RSTGEN_SUP_DOM_PPROT) >> 5U)

#define BM_RSTGEN_SUP_DOM_SEC_EN    (0x01U << 4U)

#define FM_RSTGEN_SUP_DOM_DID   (0xfU << 0U)
#define FV_RSTGEN_SUP_DOM_DID(v) \
    (((v) << 0U) & FM_RSTGEN_SUP_DOM_DID)
#define GFV_RSTGEN_SUP_DOM_DID(v) \
    (((v) & FM_RSTGEN_SUP_DOM_DID) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : RSTGEN_TOUT_RS_OFF
// Register Offset : 0x3500
// Description     : This register is used for assign rule space for rstgen timeouit register
//--------------------------------------------------------------------------
#define RSTGEN_TOUT_RS_OFF  0x3500U

#define BM_RSTGEN_TOUT_RS_LOCK  (0x01U << 31U)

#define FM_RSTGEN_TOUT_RS_RS    (0xfU << 1U)
#define FV_RSTGEN_TOUT_RS_RS(v) \
    (((v) << 1U) & FM_RSTGEN_TOUT_RS_RS)
#define GFV_RSTGEN_TOUT_RS_RS(v) \
    (((v) & FM_RSTGEN_TOUT_RS_RS) >> 1U)

#define BM_RSTGEN_TOUT_RS_EN    (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : RSTGEN_IST_TOUT_OFF
// Register Offset : 0x3504
// Description     : RSTGEN IST TIMEOUT REGISTER
//--------------------------------------------------------------------------
#define RSTGEN_IST_TOUT_OFF 0x3504U

#define FM_RSTGEN_IST_TOUT_TOUT_VAL (0xffffU << 0U)
#define FV_RSTGEN_IST_TOUT_TOUT_VAL(v) \
    (((v) << 0U) & FM_RSTGEN_IST_TOUT_TOUT_VAL)
#define GFV_RSTGEN_IST_TOUT_TOUT_VAL(v) \
    (((v) & FM_RSTGEN_IST_TOUT_TOUT_VAL) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : RSTGEN_BTI_TOUT_OFF
// Register Offset : 0x3508
// Description     : RSTGEN BTI TIMEOUT REGISTER
//--------------------------------------------------------------------------
#define RSTGEN_BTI_TOUT_OFF 0x3508U

#define FM_RSTGEN_BTI_TOUT_TOUT_VAL (0xffffU << 0U)
#define FV_RSTGEN_BTI_TOUT_TOUT_VAL(v) \
    (((v) << 0U) & FM_RSTGEN_BTI_TOUT_TOUT_VAL)
#define GFV_RSTGEN_BTI_TOUT_TOUT_VAL(v) \
    (((v) & FM_RSTGEN_BTI_TOUT_TOUT_VAL) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : RSTGEN_FUSA_RS_OFF
// Register Offset : 0x4000
// Description     : This register is used for assign rule space for rstgen fusa register
//--------------------------------------------------------------------------
#define RSTGEN_FUSA_RS_OFF          0x4000U

#define BM_RSTGEN_FUSA_RS_LOCK  (0x01U << 31U)

#define FM_RSTGEN_FUSA_RS_RS    (0xfU << 1U)
#define FV_RSTGEN_FUSA_RS_RS(v) \
    (((v) << 1U) & FM_RSTGEN_FUSA_RS_RS)
#define GFV_RSTGEN_FUSA_RS_RS(v) \
    (((v) & FM_RSTGEN_FUSA_RS_RS) >> 1U)

#define BM_RSTGEN_FUSA_RS_EN    (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : RSTGEN_APB_ERR_INT_OFF
// Register Offset : 0x4004
// Description     : APB ERROR INTERRUPT REGISTER
//--------------------------------------------------------------------------
#define RSTGEN_APB_ERR_INT_OFF      0x4004U

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

//--------------------------------------------------------------------------
// Register Name   : APB_LKSTEP_INT_OFF
// Register Offset : 0x4008
// Description     : APB LOCKSTEP INTERRUPT REGISTER
//--------------------------------------------------------------------------
#define RSTGEN_APB_LKSTEP_INT_OFF  0x4008U

#define BM_APB_LKSTEP_INT_SYNC_ERR_INT_CLR  (0x01U << 19U)

#define BM_APB_LKSTEP_INT_RESP_ERR_INT_CLR  (0x01U << 18U)

#define BM_APB_LKSTEP_INT_REQ_ERR_INT_CLR   (0x01U << 17U)

#define BM_APB_LKSTEP_INT_CMP_ERR_INT_CLR   (0x01U << 16U)

#define BM_APB_LKSTEP_INT_SYNC_ERR_INT_STA  (0x01U << 11U)

#define BM_APB_LKSTEP_INT_RESP_ERR_INT_STA  (0x01U << 10U)

#define BM_APB_LKSTEP_INT_REQ_ERR_INT_STA   (0x01U << 9U)

#define BM_APB_LKSTEP_INT_CMP_ERR_INT_STA   (0x01U << 8U)

#define BM_APB_LKSTEP_INT_SYNC_ERR_INT_EN   (0x01U << 3U)

#define BM_APB_LKSTEP_INT_RESP_ERR_INT_EN   (0x01U << 2U)

#define BM_APB_LKSTEP_INT_REQ_ERR_INT_EN    (0x01U << 1U)

#define BM_APB_LKSTEP_INT_CMP_ERR_INT_EN    (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : RSTGEN_FUSA_INT_OFF
// Register Offset : 0x400c
// Description     : RSTGEN INTERNAL FUSA INTERRUPT REGISTER
//--------------------------------------------------------------------------
#define RSTGEN_FUSA_INT_OFF 0x400cU

#define BM_RSTGEN_FUSA_INT_BTI_TOUT_ERR_CLR (0x01U << 21U)

#define BM_RSTGEN_FUSA_INT_LKSTEP_CMP_ERR_CLR   (0x01U << 20U)

#define BM_RSTGEN_FUSA_INT_SYNC_ERR_CLR (0x01U << 19U)

#define BM_RSTGEN_FUSA_INT_BOOT_MODE_CHK_ERR_CLR    (0x01U << 18U)

#define BM_RSTGEN_FUSA_INT_SWM_TRANS_ERR_CLR    (0x01U << 17U)

#define BM_RSTGEN_FUSA_INT_SWM_CHK_ERR_CLR  (0x01U << 16U)

#define BM_RSTGEN_FUSA_INT_BTI_TOUT_ERR_STA (0x01U << 13U)

#define BM_RSTGEN_FUSA_INT_LKSTEP_CMP_ERR_STA   (0x01U << 12U)

#define BM_RSTGEN_FUSA_INT_SYNC_ERR_STA (0x01U << 11U)

#define BM_RSTGEN_FUSA_INT_BOOT_MODE_CHK_ERR_STA    (0x01U << 10U)

#define BM_RSTGEN_FUSA_INT_SWM_TRANS_ERR_STA    (0x01U << 9U)

#define BM_RSTGEN_FUSA_INT_SWM_CHK_ERR_STA  (0x01U << 8U)

#define BM_RSTGEN_FUSA_INT_BTI_TOUT_ERR_EN  (0x01U << 5U)

#define BM_RSTGEN_FUSA_INT_LKSTEP_CMP_ERR_EN    (0x01U << 4U)

#define BM_RSTGEN_FUSA_INT_SYNC_ERR_EN  (0x01U << 3U)

#define BM_RSTGEN_FUSA_INT_BOOT_MODE_CHK_ERR_EN (0x01U << 2U)

#define BM_RSTGEN_FUSA_INT_SWM_TRANS_ERR_EN (0x01U << 1U)

#define BM_RSTGEN_FUSA_INT_SWM_CHK_ERR_EN   (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : WDT_LKSTEP_INT_OFF
// Register Offset : 0x4010
// Description     : WDT LOCKSTEP INTERRUPT REGISTER
//--------------------------------------------------------------------------
#define RSTGEN_WDT_LKSTEP_INT_OFF  0x4010U

#define BM_WDT_LKSTEP_INT_IST_TOUT_ERR_INT_CLR  (0x01U << 18U)

#define BM_WDT_LKSTEP_INT_SYNC_ERR_INT_CLR  (0x01U << 17U)

#define BM_WDT_LKSTEP_INT_CMP_ERR_INT_CLR   (0x01U << 16U)

#define BM_WDT_LKSTEP_INT_IST_TOUT_ERR_INT_STA  (0x01U << 10U)

#define BM_WDT_LKSTEP_INT_SYNC_ERR_INT_STA  (0x01U << 9U)

#define BM_WDT_LKSTEP_INT_CMP_ERR_INT_STA   (0x01U << 8U)

#define BM_WDT_LKSTEP_INT_IST_TOUT_ERR_INT_EN   (0x01U << 2U)

#define BM_WDT_LKSTEP_INT_SYNC_ERR_INT_EN   (0x01U << 1U)

#define BM_WDT_LKSTEP_INT_CMP_ERR_INT_EN    (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : RSTGEN_INJ_EN_OFF
// Register Offset : 0x4100
// Description     : RSTGEN ERROR INJECTION ENABLE
//--------------------------------------------------------------------------
#define RSTGEN_INJ_EN_OFF   0x4100U

#define FM_RSTGEN_INJ_EN_INJ_EN (0xffffU << 0U)
#define FV_RSTGEN_INJ_EN_INJ_EN(v) \
    (((v) << 0U) & FM_RSTGEN_INJ_EN_INJ_EN)
#define GFV_RSTGEN_INJ_EN_INJ_EN(v) \
    (((v) & FM_RSTGEN_INJ_EN_INJ_EN) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : RSTGEN_INJ_BIT_OFF
// Register Offset : 0x4104
// Description     : RSTGEN ERROR INJECTION REGISTER
//--------------------------------------------------------------------------
#define RSTGEN_INJ_BIT_OFF  0x4104U

#define FM_RSTGEN_INJ_BIT_IRQ_INJ   (0x7U << 29U)
#define FV_RSTGEN_INJ_BIT_IRQ_INJ(v) \
    (((v) << 29U) & FM_RSTGEN_INJ_BIT_IRQ_INJ)
#define GFV_RSTGEN_INJ_BIT_IRQ_INJ(v) \
    (((v) & FM_RSTGEN_INJ_BIT_IRQ_INJ) >> 29U)

#define FM_RSTGEN_INJ_BIT_ERR_INJ_BIT   (0x1fffffffU << 0U)
#define FV_RSTGEN_INJ_BIT_ERR_INJ_BIT(v) \
    (((v) << 0U) & FM_RSTGEN_INJ_BIT_ERR_INJ_BIT)
#define GFV_RSTGEN_INJ_BIT_ERR_INJ_BIT(v) \
    (((v) & FM_RSTGEN_INJ_BIT_ERR_INJ_BIT) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : RSTGEN_INJ_BIT_1_OFF
// Register Offset : 0x4108
// Description     : RSTGEN ERROR INJECTION REGISTER
//--------------------------------------------------------------------------
#define RSTGEN_INJ_BIT_1_OFF    0x4108U

#define FM_RSTGEN_INJ_BIT_1_ERR_INJ_BIT (0xffffU << 0U)
#define FV_RSTGEN_INJ_BIT_1_ERR_INJ_BIT(v) \
    (((v) << 0U) & FM_RSTGEN_INJ_BIT_1_ERR_INJ_BIT)
#define GFV_RSTGEN_INJ_BIT_1_ERR_INJ_BIT(v) \
    (((v) & FM_RSTGEN_INJ_BIT_1_ERR_INJ_BIT) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : RSTGEN_INJ_BIT_2_OFF
// Register Offset : 0x410c
// Description     : RSTGEN ERROR INJECTION REGISTER
//--------------------------------------------------------------------------
#define RSTGEN_INJ_BIT_2_OFF    0x410cU

#define FM_RSTGEN_INJ_BIT_2_ERR_INJ_BIT (0xffffU << 0U)
#define FV_RSTGEN_INJ_BIT_2_ERR_INJ_BIT(v) \
    (((v) << 0U) & FM_RSTGEN_INJ_BIT_2_ERR_INJ_BIT)
#define GFV_RSTGEN_INJ_BIT_2_ERR_INJ_BIT(v) \
    (((v) & FM_RSTGEN_INJ_BIT_2_ERR_INJ_BIT) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : RSTGEN_FUNC_INT_RS_OFF
// Register Offset : 0x4200
// Description     : This register is used for assign rule space for rstgen function interrupt register
//--------------------------------------------------------------------------
#define RSTGEN_FUNC_INT_RS_OFF  0x4200U

#define BM_RSTGEN_FUNC_INT_RS_LOCK  (0x01U << 31U)

#define FM_RSTGEN_FUNC_INT_RS_RS    (0xfU << 1U)
#define FV_RSTGEN_FUNC_INT_RS_RS(v) \
    (((v) << 1U) & FM_RSTGEN_FUNC_INT_RS_RS)
#define GFV_RSTGEN_FUNC_INT_RS_RS(v) \
    (((v) & FM_RSTGEN_FUNC_INT_RS_RS) >> 1U)

#define BM_RSTGEN_FUNC_INT_RS_EN    (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : RSTGEN_FUNC_INT_OFF
// Register Offset : 0x4204
// Description     : RSTGEN FUNC INTERRUPT REGISTER
//--------------------------------------------------------------------------
#define RSTGEN_FUNC_INT_OFF 0x4204U

#define BM_RSTGEN_FUNC_INT_ACCESS_PER_ERR_CLR   (0x01U << 16U)

#define BM_RSTGEN_FUNC_INT_ACCESS_PER_ERR_STA   (0x01U << 8U)

#define BM_RSTGEN_FUNC_INT_ACCESS_PER_ERR_EN    (0x01U << 0U)


#endif  /* __RSTGEN_REG_H__ */