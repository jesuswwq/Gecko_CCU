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

#ifndef CKGEN_REG_H
#define CKGEN_REG_H

#ifdef __cplusplus
extern "C" {
#endif

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

#define DOM_PER_LOCK_OFF(n) (0x8U + 12U*(n))

#define BM_DOM_PER_LOCK_DOM7_LOCK   (0x01U << 7U)

#define BM_DOM_PER_LOCK_DOM6_LOCK   (0x01U << 6U)

#define BM_DOM_PER_LOCK_DOM5_LOCK   (0x01U << 5U)

#define BM_DOM_PER_LOCK_DOM4_LOCK   (0x01U << 4U)

#define BM_DOM_PER_LOCK_DOM3_LOCK   (0x01U << 3U)

#define BM_DOM_PER_LOCK_DOM2_LOCK   (0x01U << 2U)

#define BM_DOM_PER_LOCK_DOM1_LOCK   (0x01U << 1U)

#define BM_DOM_PER_LOCK_DOM0_LOCK   (0x01U << 0U)

#define CKGEN_GLB_CTL_RS_OFF    0x200U

#define BM_CKGEN_GLB_CTL_RS_LOCK    (0x01U << 31U)

#define FM_CKGEN_GLB_CTL_RS_RS  (0xfU << 1U)
#define FV_CKGEN_GLB_CTL_RS_RS(v) \
    (((v) << 1U) & FM_CKGEN_GLB_CTL_RS_RS)
#define GFV_CKGEN_GLB_CTL_RS_RS(v) \
    (((v) & FM_CKGEN_GLB_CTL_RS_RS) >> 1U)

#define BM_CKGEN_GLB_CTL_RS_EN  (0x01U << 0U)

#define CKGEN_GLB_CTL_OFF   0x204U

#define FM_CKGEN_GLB_CTL_CLK_24M_DIV_C_NUM  (0xfU << 28U)
#define FV_CKGEN_GLB_CTL_CLK_24M_DIV_C_NUM(v) \
    (((v) << 28U) & FM_CKGEN_GLB_CTL_CLK_24M_DIV_C_NUM)
#define GFV_CKGEN_GLB_CTL_CLK_24M_DIV_C_NUM(v) \
    (((v) & FM_CKGEN_GLB_CTL_CLK_24M_DIV_C_NUM) >> 28U)

#define FM_CKGEN_GLB_CTL_CLK_24M_DIV_B_NUM  (0x3ffU << 18U)
#define FV_CKGEN_GLB_CTL_CLK_24M_DIV_B_NUM(v) \
    (((v) << 18U) & FM_CKGEN_GLB_CTL_CLK_24M_DIV_B_NUM)
#define GFV_CKGEN_GLB_CTL_CLK_24M_DIV_B_NUM(v) \
    (((v) & FM_CKGEN_GLB_CTL_CLK_24M_DIV_B_NUM) >> 18U)

#define FM_CKGEN_GLB_CTL_CLK_24M_DIV_A_NUM  (0x3ffU << 3U)
#define FV_CKGEN_GLB_CTL_CLK_24M_DIV_A_NUM(v) \
    (((v) << 3U) & FM_CKGEN_GLB_CTL_CLK_24M_DIV_A_NUM)
#define GFV_CKGEN_GLB_CTL_CLK_24M_DIV_A_NUM(v) \
    (((v) & FM_CKGEN_GLB_CTL_CLK_24M_DIV_A_NUM) >> 3U)

#define BM_CKGEN_GLB_CTL_CLK_24M_DIV_C_DIS  (0x01U << 2U)

#define BM_CKGEN_GLB_CTL_CLK_24M_DIV_B_DIS  (0x01U << 1U)

#define BM_CKGEN_GLB_CTL_CLK_24M_DIV_A_DIS  (0x01U << 0U)

#define CKGEN_SUP_DOM_OFF   0x300U

#define BM_CKGEN_SUP_DOM_LOCK   (0x01U << 31U)

#define FM_CKGEN_SUP_DOM_PPROT  (0x3U << 5U)
#define FV_CKGEN_SUP_DOM_PPROT(v) \
    (((v) << 5U) & FM_CKGEN_SUP_DOM_PPROT)
#define GFV_CKGEN_SUP_DOM_PPROT(v) \
    (((v) & FM_CKGEN_SUP_DOM_PPROT) >> 5U)

#define BM_CKGEN_SUP_DOM_SEC_EN (0x01U << 4U)

#define FM_CKGEN_SUP_DOM_DID    (0xfU << 0U)
#define FV_CKGEN_SUP_DOM_DID(v) \
    (((v) << 0U) & FM_CKGEN_SUP_DOM_DID)
#define GFV_CKGEN_SUP_DOM_DID(v) \
    (((v) & FM_CKGEN_SUP_DOM_DID) >> 0U)

#define CKGEN_RES_RS_OFF    0x400U

#define BM_CKGEN_RES_RS_LOCK    (0x01U << 31U)

#define FM_CKGEN_RES_RS_RS  (0xfU << 1U)
#define FV_CKGEN_RES_RS_RS(v) \
    (((v) << 1U) & FM_CKGEN_RES_RS_RS)
#define GFV_CKGEN_RES_RS_RS(v) \
    (((v) & FM_CKGEN_RES_RS_RS) >> 1U)

#define BM_CKGEN_RES_RS_EN  (0x01U << 0U)

#define CKGEN_RES_OFF   0x404U

#define FM_CKGEN_RES_RES    (0xffffffffU << 0U)
#define FV_CKGEN_RES_RES(v) \
    (((v) << 0U) & FM_CKGEN_RES_RES)
#define GFV_CKGEN_RES_RES(v) \
    (((v) & FM_CKGEN_RES_RES) >> 0U)

#define CKGEN_MISC_RS_OFF   0x500U

#define BM_CKGEN_MISC_RS_LOCK   (0x01U << 31U)

#define FM_CKGEN_MISC_RS_RS (0xfU << 1U)
#define FV_CKGEN_MISC_RS_RS(v) \
    (((v) << 1U) & FM_CKGEN_MISC_RS_RS)
#define GFV_CKGEN_MISC_RS_RS(v) \
    (((v) & FM_CKGEN_MISC_RS_RS) >> 1U)

#define BM_CKGEN_MISC_RS_EN (0x01U << 0U)

#define CKGEN_MISC_OFF  0x504U

#define FM_CKGEN_MISC_MISC  (0xffffffffU << 0U)
#define FV_CKGEN_MISC_MISC(v) \
    (((v) << 0U) & FM_CKGEN_MISC_MISC)
#define GFV_CKGEN_MISC_MISC(v) \
    (((v) & FM_CKGEN_MISC_MISC) >> 0U)

#define CKGEN_MISC_MON_OFF  0x508U

#define FM_CKGEN_MISC_MON_MON   (0xffffffffU << 0U)
#define FV_CKGEN_MISC_MON_MON(v) \
    (((v) << 0U) & FM_CKGEN_MISC_MON_MON)
#define GFV_CKGEN_MISC_MON_MON(v) \
    (((v) & FM_CKGEN_MISC_MON_MON) >> 0U)

#define IP_SLICE_RS_OFF(n)  (0x1000U + 16U*(n))

#define BM_IP_SLICE_RS_LOCK (0x01U << 31U)

#define FM_IP_SLICE_RS_RS   (0xfU << 1U)
#define FV_IP_SLICE_RS_RS(v) \
    (((v) << 1U) & FM_IP_SLICE_RS_RS)
#define GFV_IP_SLICE_RS_RS(v) \
    (((v) & FM_IP_SLICE_RS_RS) >> 1U)

#define BM_IP_SLICE_RS_EN   (0x01U << 0U)

#define IP_SLICE_CTL_OFF(n) (0x1004U + 16U*(n))

#define BM_IP_SLICE_CTL_HW_CG_EN_STATUS (0x01U << 31U)

#define BM_IP_SLICE_CTL_MAIN_EN_STATUS  (0x01U << 30U)

#define BM_IP_SLICE_CTL_PRE_EN_STATUS   (0x01U << 29U)

#define BM_IP_SLICE_CTL_DIV_CHG_BUSY    (0x01U << 28U)

#define BM_IP_SLICE_CTL_MUX_D0_ACTIVE   (0x01U << 27U)

#define FM_IP_SLICE_CTL_DIV_NUM (0xffU << 8U)
#define FV_IP_SLICE_CTL_DIV_NUM(v) \
    (((v) << 8U) & FM_IP_SLICE_CTL_DIV_NUM)
#define GFV_IP_SLICE_CTL_DIV_NUM(v) \
    (((v) & FM_IP_SLICE_CTL_DIV_NUM) >> 8U)

#define BM_IP_SLICE_CTL_HW_DIS_EN   (0x01U << 7U)

#define BM_IP_SLICE_CTL_DBG_EN  (0x01U << 6U)

#define BM_IP_SLICE_CTL_MAIN_EN (0x01U << 5U)

#define BM_IP_SLICE_CTL_PRE_EN  (0x01U << 4U)

#define FM_IP_SLICE_CTL_CLK_SRC_SEL (0x7U << 0U)
#define FV_IP_SLICE_CTL_CLK_SRC_SEL(v) \
    (((v) << 0U) & FM_IP_SLICE_CTL_CLK_SRC_SEL)
#define GFV_IP_SLICE_CTL_CLK_SRC_SEL(v) \
    (((v) & FM_IP_SLICE_CTL_CLK_SRC_SEL) >> 0U)

#define IP_SLICE_MON_CTL_OFF(n) (0x1008U + 16U*(n))

#define FM_IP_SLICE_MON_CTL_FREQ_MON    (0xffffU << 16U)
#define FV_IP_SLICE_MON_CTL_FREQ_MON(v) \
    (((v) << 16U) & FM_IP_SLICE_MON_CTL_FREQ_MON)
#define GFV_IP_SLICE_MON_CTL_FREQ_MON(v) \
    (((v) & FM_IP_SLICE_MON_CTL_FREQ_MON) >> 16U)

#define BM_IP_SLICE_MON_CTL_MON_EN_STA  (0x01U << 9U)

#define BM_IP_SLICE_MON_CTL_FREQ_MON_UPD    (0x01U << 8U)

#define BM_IP_SLICE_MON_CTL_HIB_EXP (0x01U << 4U)

#define BM_IP_SLICE_MON_CTL_SLP_EXP (0x01U << 3U)

#define BM_IP_SLICE_MON_CTL_MON_CLK_SRC_SEL (0x01U << 2U)

#define BM_IP_SLICE_MON_CTL_ACTIVE_DISABLE  (0x01U << 1U)

#define BM_IP_SLICE_MON_CTL_MON_EN  (0x01U << 0U)

#define IP_SLICE_MON_THRD_OFF(n)    (0x100cU + 16U*(n))

#define FM_IP_SLICE_MON_THRD_HIGH_THRD  (0xffffU << 16U)
#define FV_IP_SLICE_MON_THRD_HIGH_THRD(v) \
    (((v) << 16U) & FM_IP_SLICE_MON_THRD_HIGH_THRD)
#define GFV_IP_SLICE_MON_THRD_HIGH_THRD(v) \
    (((v) & FM_IP_SLICE_MON_THRD_HIGH_THRD) >> 16U)

#define FM_IP_SLICE_MON_THRD_LOW_THRD   (0xffffU << 0U)
#define FV_IP_SLICE_MON_THRD_LOW_THRD(v) \
    (((v) << 0U) & FM_IP_SLICE_MON_THRD_LOW_THRD)
#define GFV_IP_SLICE_MON_THRD_LOW_THRD(v) \
    (((v) & FM_IP_SLICE_MON_THRD_LOW_THRD) >> 0U)

#define BUS_SLICE_RS_OFF(n) (0x2000U + 40U*(n))

#define BM_BUS_SLICE_RS_LOCK    (0x01U << 31U)

#define FM_BUS_SLICE_RS_RS  (0xfU << 1U)
#define FV_BUS_SLICE_RS_RS(v) \
    (((v) << 1U) & FM_BUS_SLICE_RS_RS)
#define GFV_BUS_SLICE_RS_RS(v) \
    (((v) & FM_BUS_SLICE_RS_RS) >> 1U)

#define BM_BUS_SLICE_RS_EN  (0x01U << 0U)

#define BUS_SLICE_CTL_OFF(n)    (0x2004U + 40U*(n))

#define BM_BUS_SLICE_CTL_HW_CG_EN_STATUS    (0x01U << 31U)

#define BM_BUS_SLICE_CTL_MAIN_EN_STATUS (0x01U << 30U)

#define BM_BUS_SLICE_CTL_PRE_EN_STATUS  (0x01U << 29U)

#define BM_BUS_SLICE_CTL_DIV_CHG_BUSY   (0x01U << 28U)

#define BM_BUS_SLICE_CTL_POST_MUX_D0_ACTIVE (0x01U << 27U)

#define BM_BUS_SLICE_CTL_PRE_MUX_D0_ACTIVE  (0x01U << 26U)

#define FM_BUS_SLICE_CTL_DIV_NUM    (0x1fU << 8U)
#define FV_BUS_SLICE_CTL_DIV_NUM(v) \
    (((v) << 8U) & FM_BUS_SLICE_CTL_DIV_NUM)
#define GFV_BUS_SLICE_CTL_DIV_NUM(v) \
    (((v) & FM_BUS_SLICE_CTL_DIV_NUM) >> 8U)

#define BM_BUS_SLICE_CTL_HW_DIS_EN  (0x01U << 7U)

#define BM_BUS_SLICE_CTL_DBG_EN (0x01U << 6U)

#define BM_BUS_SLICE_CTL_MAIN_EN    (0x01U << 5U)

#define BM_BUS_SLICE_CTL_PRE_EN (0x01U << 4U)

#define FM_BUS_SLICE_CTL_CLK_SRC_SEL    (0xfU << 0U)
#define FV_BUS_SLICE_CTL_CLK_SRC_SEL(v) \
    (((v) << 0U) & FM_BUS_SLICE_CTL_CLK_SRC_SEL)
#define GFV_BUS_SLICE_CTL_CLK_SRC_SEL(v) \
    (((v) & FM_BUS_SLICE_CTL_CLK_SRC_SEL) >> 0U)

#define BUS_SLICE_SYNC_CTL_OFF(n)   (0x2008U + 40U*(n))

#define BM_BUS_SLICE_SYNC_CTL_DIV_Q_CHG_BUSY    (0x01U << 31U)

#define BM_BUS_SLICE_SYNC_CTL_DIV_P_CHG_BUSY    (0x01U << 30U)

#define BM_BUS_SLICE_SYNC_CTL_DIV_N_CHG_BUSY    (0x01U << 29U)

#define BM_BUS_SLICE_SYNC_CTL_DIV_M_CHG_BUSY    (0x01U << 28U)

#define FM_BUS_SLICE_SYNC_CTL_DIV_Q_NUM (0xfU << 12U)
#define FV_BUS_SLICE_SYNC_CTL_DIV_Q_NUM(v) \
    (((v) << 12U) & FM_BUS_SLICE_SYNC_CTL_DIV_Q_NUM)
#define GFV_BUS_SLICE_SYNC_CTL_DIV_Q_NUM(v) \
    (((v) & FM_BUS_SLICE_SYNC_CTL_DIV_Q_NUM) >> 12U)

#define FM_BUS_SLICE_SYNC_CTL_DIV_P_NUM (0xfU << 8U)
#define FV_BUS_SLICE_SYNC_CTL_DIV_P_NUM(v) \
    (((v) << 8U) & FM_BUS_SLICE_SYNC_CTL_DIV_P_NUM)
#define GFV_BUS_SLICE_SYNC_CTL_DIV_P_NUM(v) \
    (((v) & FM_BUS_SLICE_SYNC_CTL_DIV_P_NUM) >> 8U)

#define FM_BUS_SLICE_SYNC_CTL_DIV_N_NUM (0xfU << 4U)
#define FV_BUS_SLICE_SYNC_CTL_DIV_N_NUM(v) \
    (((v) << 4U) & FM_BUS_SLICE_SYNC_CTL_DIV_N_NUM)
#define GFV_BUS_SLICE_SYNC_CTL_DIV_N_NUM(v) \
    (((v) & FM_BUS_SLICE_SYNC_CTL_DIV_N_NUM) >> 4U)

#define FM_BUS_SLICE_SYNC_CTL_DIV_M_NUM (0xfU << 0U)
#define FV_BUS_SLICE_SYNC_CTL_DIV_M_NUM(v) \
    (((v) << 0U) & FM_BUS_SLICE_SYNC_CTL_DIV_M_NUM)
#define GFV_BUS_SLICE_SYNC_CTL_DIV_M_NUM(v) \
    (((v) & FM_BUS_SLICE_SYNC_CTL_DIV_M_NUM) >> 0U)

#define BUS_SLICE_MON_CTL_0_OFF(n)  (0x200cU + 40U*(n))

#define BM_BUS_SLICE_MON_CTL_0_FREQ_MON_3_UPD   (0x01U << 11U)

#define BM_BUS_SLICE_MON_CTL_0_FREQ_MON_2_UPD   (0x01U << 10U)

#define BM_BUS_SLICE_MON_CTL_0_FREQ_MON_1_UPD   (0x01U << 9U)

#define BM_BUS_SLICE_MON_CTL_0_FREQ_MON_0_UPD   (0x01U << 8U)

#define BM_BUS_SLICE_MON_CTL_0_MON_EN_STA   (0x01U << 5U)

#define BM_BUS_SLICE_MON_CTL_0_HIB_EXP  (0x01U << 4U)

#define BM_BUS_SLICE_MON_CTL_0_SLP_EXP  (0x01U << 3U)

#define BM_BUS_SLICE_MON_CTL_0_MON_CLK_SRC_SEL  (0x01U << 2U)

#define BM_BUS_SLICE_MON_CTL_0_ACTIVE_DISABLE   (0x01U << 1U)

#define BM_BUS_SLICE_MON_CTL_0_MON_EN   (0x01U << 0U)

#define BUS_SLICE_MON_CTL_1_OFF(n)  (0x2010U + 40U*(n))

#define FM_BUS_SLICE_MON_CTL_1_FREQ_MON_1   (0xffffU << 16U)
#define FV_BUS_SLICE_MON_CTL_1_FREQ_MON_1(v) \
    (((v) << 16U) & FM_BUS_SLICE_MON_CTL_1_FREQ_MON_1)
#define GFV_BUS_SLICE_MON_CTL_1_FREQ_MON_1(v) \
    (((v) & FM_BUS_SLICE_MON_CTL_1_FREQ_MON_1) >> 16U)

#define FM_BUS_SLICE_MON_CTL_1_FREQ_MON_0   (0xffffU << 0U)
#define FV_BUS_SLICE_MON_CTL_1_FREQ_MON_0(v) \
    (((v) << 0U) & FM_BUS_SLICE_MON_CTL_1_FREQ_MON_0)
#define GFV_BUS_SLICE_MON_CTL_1_FREQ_MON_0(v) \
    (((v) & FM_BUS_SLICE_MON_CTL_1_FREQ_MON_0) >> 0U)

#define BUS_SLICE_MON_CTL_2_OFF(n)  (0x2014U + 40U*(n))

#define FM_BUS_SLICE_MON_CTL_2_FREQ_MON_3   (0xffffU << 16U)
#define FV_BUS_SLICE_MON_CTL_2_FREQ_MON_3(v) \
    (((v) << 16U) & FM_BUS_SLICE_MON_CTL_2_FREQ_MON_3)
#define GFV_BUS_SLICE_MON_CTL_2_FREQ_MON_3(v) \
    (((v) & FM_BUS_SLICE_MON_CTL_2_FREQ_MON_3) >> 16U)

#define FM_BUS_SLICE_MON_CTL_2_FREQ_MON_2   (0xffffU << 0U)
#define FV_BUS_SLICE_MON_CTL_2_FREQ_MON_2(v) \
    (((v) << 0U) & FM_BUS_SLICE_MON_CTL_2_FREQ_MON_2)
#define GFV_BUS_SLICE_MON_CTL_2_FREQ_MON_2(v) \
    (((v) & FM_BUS_SLICE_MON_CTL_2_FREQ_MON_2) >> 0U)

#define BUS_SLICE_MON_0_THRD_OFF(n) (0x2018U + 40U*(n))

#define FM_BUS_SLICE_MON_0_THRD_HIGH_THRD   (0xffffU << 16U)
#define FV_BUS_SLICE_MON_0_THRD_HIGH_THRD(v) \
    (((v) << 16U) & FM_BUS_SLICE_MON_0_THRD_HIGH_THRD)
#define GFV_BUS_SLICE_MON_0_THRD_HIGH_THRD(v) \
    (((v) & FM_BUS_SLICE_MON_0_THRD_HIGH_THRD) >> 16U)

#define FM_BUS_SLICE_MON_0_THRD_LOW_THRD    (0xffffU << 0U)
#define FV_BUS_SLICE_MON_0_THRD_LOW_THRD(v) \
    (((v) << 0U) & FM_BUS_SLICE_MON_0_THRD_LOW_THRD)
#define GFV_BUS_SLICE_MON_0_THRD_LOW_THRD(v) \
    (((v) & FM_BUS_SLICE_MON_0_THRD_LOW_THRD) >> 0U)

#define BUS_SLICE_MON_1_THRD_OFF(n) (0x201cU + 40U*(n))

#define FM_BUS_SLICE_MON_1_THRD_HIGH_THRD   (0xffffU << 16U)
#define FV_BUS_SLICE_MON_1_THRD_HIGH_THRD(v) \
    (((v) << 16U) & FM_BUS_SLICE_MON_1_THRD_HIGH_THRD)
#define GFV_BUS_SLICE_MON_1_THRD_HIGH_THRD(v) \
    (((v) & FM_BUS_SLICE_MON_1_THRD_HIGH_THRD) >> 16U)

#define FM_BUS_SLICE_MON_1_THRD_LOW_THRD    (0xffffU << 0U)
#define FV_BUS_SLICE_MON_1_THRD_LOW_THRD(v) \
    (((v) << 0U) & FM_BUS_SLICE_MON_1_THRD_LOW_THRD)
#define GFV_BUS_SLICE_MON_1_THRD_LOW_THRD(v) \
    (((v) & FM_BUS_SLICE_MON_1_THRD_LOW_THRD) >> 0U)

#define BUS_SLICE_MON_2_THRD_OFF(n) (0x2020U + 40U*(n))

#define FM_BUS_SLICE_MON_2_THRD_HIGH_THRD   (0xffffU << 16U)
#define FV_BUS_SLICE_MON_2_THRD_HIGH_THRD(v) \
    (((v) << 16U) & FM_BUS_SLICE_MON_2_THRD_HIGH_THRD)
#define GFV_BUS_SLICE_MON_2_THRD_HIGH_THRD(v) \
    (((v) & FM_BUS_SLICE_MON_2_THRD_HIGH_THRD) >> 16U)

#define FM_BUS_SLICE_MON_2_THRD_LOW_THRD    (0xffffU << 0U)
#define FV_BUS_SLICE_MON_2_THRD_LOW_THRD(v) \
    (((v) << 0U) & FM_BUS_SLICE_MON_2_THRD_LOW_THRD)
#define GFV_BUS_SLICE_MON_2_THRD_LOW_THRD(v) \
    (((v) & FM_BUS_SLICE_MON_2_THRD_LOW_THRD) >> 0U)

#define BUS_SLICE_MON_3_THRD_OFF(n) (0x2024U + 40U*(n))

#define FM_BUS_SLICE_MON_3_THRD_HIGH_THRD   (0xffffU << 16U)
#define FV_BUS_SLICE_MON_3_THRD_HIGH_THRD(v) \
    (((v) << 16U) & FM_BUS_SLICE_MON_3_THRD_HIGH_THRD)
#define GFV_BUS_SLICE_MON_3_THRD_HIGH_THRD(v) \
    (((v) & FM_BUS_SLICE_MON_3_THRD_HIGH_THRD) >> 16U)

#define FM_BUS_SLICE_MON_3_THRD_LOW_THRD    (0xffffU << 0U)
#define FV_BUS_SLICE_MON_3_THRD_LOW_THRD(v) \
    (((v) << 0U) & FM_BUS_SLICE_MON_3_THRD_LOW_THRD)
#define GFV_BUS_SLICE_MON_3_THRD_LOW_THRD(v) \
    (((v) & FM_BUS_SLICE_MON_3_THRD_LOW_THRD) >> 0U)

#define CORE_SLICE_RS_OFF(n)    (0x3000U + 16U*(n))

#define BM_CORE_SLICE_RS_LOCK   (0x01U << 31U)

#define FM_CORE_SLICE_RS_RS (0xfU << 1U)
#define FV_CORE_SLICE_RS_RS(v) \
    (((v) << 1U) & FM_CORE_SLICE_RS_RS)
#define GFV_CORE_SLICE_RS_RS(v) \
    (((v) & FM_CORE_SLICE_RS_RS) >> 1U)

#define BM_CORE_SLICE_RS_EN (0x01U << 0U)

#define CORE_SLICE_CTL_OFF(n)   (0x3004U + 16U*(n))

#define BM_CORE_SLICE_CTL_HW_CG_EN_STATUS   (0x01U << 31U)

#define BM_CORE_SLICE_CTL_MAIN_EN_STATUS    (0x01U << 30U)

#define BM_CORE_SLICE_CTL_PRE_EN_STATUS (0x01U << 29U)

#define BM_CORE_SLICE_CTL_DIV_CHG_BUSY  (0x01U << 28U)

#define BM_CORE_SLICE_CTL_MUX_D0_ACTIVE (0x01U << 27U)

#define FM_CORE_SLICE_CTL_DIV_NUM   (0x1fU << 8U)
#define FV_CORE_SLICE_CTL_DIV_NUM(v) \
    (((v) << 8U) & FM_CORE_SLICE_CTL_DIV_NUM)
#define GFV_CORE_SLICE_CTL_DIV_NUM(v) \
    (((v) & FM_CORE_SLICE_CTL_DIV_NUM) >> 8U)

#define BM_CORE_SLICE_CTL_HW_DIS_EN (0x01U << 7U)

#define BM_CORE_SLICE_CTL_DBG_EN    (0x01U << 6U)

#define BM_CORE_SLICE_CTL_MAIN_EN   (0x01U << 5U)

#define BM_CORE_SLICE_CTL_PRE_EN    (0x01U << 4U)

#define FM_CORE_SLICE_CTL_CLK_SRC_SEL   (0x7U << 0U)
#define FV_CORE_SLICE_CTL_CLK_SRC_SEL(v) \
    (((v) << 0U) & FM_CORE_SLICE_CTL_CLK_SRC_SEL)
#define GFV_CORE_SLICE_CTL_CLK_SRC_SEL(v) \
    (((v) & FM_CORE_SLICE_CTL_CLK_SRC_SEL) >> 0U)

#define CORE_SLICE_MON_CTL_OFF(n)   (0x3008U + 16U*(n))

#define FM_CORE_SLICE_MON_CTL_FREQ_MON  (0xffffU << 16U)
#define FV_CORE_SLICE_MON_CTL_FREQ_MON(v) \
    (((v) << 16U) & FM_CORE_SLICE_MON_CTL_FREQ_MON)
#define GFV_CORE_SLICE_MON_CTL_FREQ_MON(v) \
    (((v) & FM_CORE_SLICE_MON_CTL_FREQ_MON) >> 16U)

#define BM_CORE_SLICE_MON_CTL_MON_EN_STA    (0x01U << 9U)

#define BM_CORE_SLICE_MON_CTL_FREQ_MON_UPD  (0x01U << 8U)

#define BM_CORE_SLICE_MON_CTL_HIB_EXP   (0x01U << 4U)

#define BM_CORE_SLICE_MON_CTL_SLP_EXP   (0x01U << 3U)

#define BM_CORE_SLICE_MON_CTL_MON_CLK_SRC_SEL   (0x01U << 2U)

#define BM_CORE_SLICE_MON_CTL_ACTIVE_DISABLE    (0x01U << 1U)

#define BM_CORE_SLICE_MON_CTL_MON_EN    (0x01U << 0U)

#define CORE_SLICE_MON_THRD_OFF(n)  (0x300cU + 16U*(n))

#define FM_CORE_SLICE_MON_THRD_HIGH_THRD    (0xffffU << 16U)
#define FV_CORE_SLICE_MON_THRD_HIGH_THRD(v) \
    (((v) << 16U) & FM_CORE_SLICE_MON_THRD_HIGH_THRD)
#define GFV_CORE_SLICE_MON_THRD_HIGH_THRD(v) \
    (((v) & FM_CORE_SLICE_MON_THRD_HIGH_THRD) >> 16U)

#define FM_CORE_SLICE_MON_THRD_LOW_THRD (0xffffU << 0U)
#define FV_CORE_SLICE_MON_THRD_LOW_THRD(v) \
    (((v) << 0U) & FM_CORE_SLICE_MON_THRD_LOW_THRD)
#define GFV_CORE_SLICE_MON_THRD_LOW_THRD(v) \
    (((v) & FM_CORE_SLICE_MON_THRD_LOW_THRD) >> 0U)

#define PCG_RS_OFF(n)   (0x4000U + 8U*(n))

#define BM_PCG_RS_LOCK  (0x01U << 31U)

#define FM_PCG_RS_RS    (0xfU << 1U)
#define FV_PCG_RS_RS(v) \
    (((v) << 1U) & FM_PCG_RS_RS)
#define GFV_PCG_RS_RS(v) \
    (((v) & FM_PCG_RS_RS) >> 1U)

#define BM_PCG_RS_EN    (0x01U << 0U)

#define PCG_CTL_OFF(n)  (0x4004U + 8U*(n))

#define BM_PCG_CTL_LP_MASK  (0x01U << 8U)

#define BM_PCG_CTL_DBG_EN   (0x01U << 6U)

#define BM_PCG_CTL_CG_GATED (0x01U << 5U)

#define BM_PCG_CTL_ACTIVE_MON_STA   (0x01U << 4U)

#define BM_PCG_CTL_ACTIVE_MON_EN    (0x01U << 3U)

#define BM_PCG_CTL_SLP_MODE (0x01U << 2U)

#define BM_PCG_CTL_HIB_MODE (0x01U << 1U)

#define BM_PCG_CTL_RUN_MODE (0x01U << 0U)

#define BCG_RS_OFF(n)   (0x5000U + 8U*(n))

#define BM_BCG_RS_LOCK  (0x01U << 31U)

#define FM_BCG_RS_RS    (0xfU << 1U)
#define FV_BCG_RS_RS(v) \
    (((v) << 1U) & FM_BCG_RS_RS)
#define GFV_BCG_RS_RS(v) \
    (((v) & FM_BCG_RS_RS) >> 1U)

#define BM_BCG_RS_EN    (0x01U << 0U)

#define BCG_CTL_OFF(n)  (0x5004U + 8U*(n))

#define BM_BCG_CTL_LP_MASK  (0x01U << 8U)

#define BM_BCG_CTL_DBG_EN   (0x01U << 6U)

#define BM_BCG_CTL_CG_GATED (0x01U << 5U)

#define BM_BCG_CTL_ACTIVE_MON_STA   (0x01U << 4U)

#define BM_BCG_CTL_ACTIVE_MON_EN    (0x01U << 3U)

#define BM_BCG_CTL_SLP_MODE (0x01U << 2U)

#define BM_BCG_CTL_HIB_MODE (0x01U << 1U)

#define BM_BCG_CTL_RUN_MODE (0x01U << 0U)

#define CCG_RS_OFF(n)   (0x6000U + 8U*(n))

#define BM_CCG_RS_LOCK  (0x01U << 31U)

#define FM_CCG_RS_RS    (0xfU << 1U)
#define FV_CCG_RS_RS(v) \
    (((v) << 1U) & FM_CCG_RS_RS)
#define GFV_CCG_RS_RS(v) \
    (((v) & FM_CCG_RS_RS) >> 1U)

#define BM_CCG_RS_EN    (0x01U << 0U)

#define CCG_CTL_OFF(n)  (0x6004U + 8U*(n))

#define BM_CCG_CTL_LP_MASK  (0x01U << 8U)

#define BM_CCG_CTL_DBG_EN   (0x01U << 6U)

#define BM_CCG_CTL_CG_GATED (0x01U << 5U)

#define BM_CCG_CTL_ACTIVE_MON_STA   (0x01U << 4U)

#define BM_CCG_CTL_ACTIVE_MON_EN    (0x01U << 3U)

#define BM_CCG_CTL_SLP_MODE (0x01U << 2U)

#define BM_CCG_CTL_HIB_MODE (0x01U << 1U)

#define BM_CCG_CTL_RUN_MODE (0x01U << 0U)

#define PLL_RS_OFF(n)   (0x7000U + 12U*(n))

#define BM_PLL_RS_LOCK  (0x01U << 31U)

#define FM_PLL_RS_RS    (0xfU << 1U)
#define FV_PLL_RS_RS(v) \
    (((v) << 1U) & FM_PLL_RS_RS)
#define GFV_PLL_RS_RS(v) \
    (((v) & FM_PLL_RS_RS) >> 1U)

#define BM_PLL_RS_EN    (0x01U << 0U)

#define PLL_CTL_OFF(n)  (0x7004U + 12U*(n))

#define BM_PLL_CTL_PD_SLP_MODE  (0x01U << 6U)

#define BM_PLL_CTL_PD_HIB_MODE  (0x01U << 5U)

#define BM_PLL_CTL_PD_RUN_MODE  (0x01U << 4U)

#define BM_PLL_CTL_IGNORE_PLL   (0x01U << 3U)

#define BM_PLL_CTL_CLK_SLP_MODE (0x01U << 2U)

#define BM_PLL_CTL_CLK_HIB_MODE (0x01U << 1U)

#define BM_PLL_CTL_CLK_RUN_MODE (0x01U << 0U)

#define PLL_MON_CTL_OFF(n)  (0x7008U + 12U*(n))

#define BM_PLL_MON_CTL_PLL_CLK_RDY  (0x01U << 31U)

#define FM_PLL_MON_CTL_TOUT_VAL (0xffffU << 8U)
#define FV_PLL_MON_CTL_TOUT_VAL(v) \
    (((v) << 8U) & FM_PLL_MON_CTL_TOUT_VAL)
#define GFV_PLL_MON_CTL_TOUT_VAL(v) \
    (((v) & FM_PLL_MON_CTL_TOUT_VAL) >> 8U)

#define BM_PLL_MON_CTL_MON_EN   (0x01U << 0U)

#define XTAL_RS_OFF(n)  (0x7500U + 12U*(n))

#define BM_XTAL_RS_LOCK (0x01U << 31U)

#define FM_XTAL_RS_RS   (0xfU << 1U)
#define FV_XTAL_RS_RS(v) \
    (((v) << 1U) & FM_XTAL_RS_RS)
#define GFV_XTAL_RS_RS(v) \
    (((v) & FM_XTAL_RS_RS) >> 1U)

#define BM_XTAL_RS_EN   (0x01U << 0U)

#define XTAL_CTL_OFF(n) (0x7504U + 12U*(n))

#define BM_XTAL_CTL_IGNORE_XTAL (0x01U << 3U)

#define BM_XTAL_CTL_SLP_MODE    (0x01U << 2U)

#define BM_XTAL_CTL_HIB_MODE    (0x01U << 1U)

#define BM_XTAL_CTL_RUN_MODE    (0x01U << 0U)

#define XTAL_MON_CTL_OFF(n) (0x7508U + 12U*(n))

#define BM_XTAL_MON_CTL_XTAL_CLK_ACTIVE (0x01U << 31U)

#define BM_XTAL_MON_CTL_RC24M_CLK_ACTIVE    (0x01U << 30U)

#define BM_XTAL_MON_CTL_XTAL_CLK_RDY    (0x01U << 29U)

#define BM_XTAL_MON_CTL_RC24M_CLK_RDY   (0x01U << 28U)

#define FM_XTAL_MON_CTL_TOUT_VAL    (0xffffU << 8U)
#define FV_XTAL_MON_CTL_TOUT_VAL(v) \
    (((v) << 8U) & FM_XTAL_MON_CTL_TOUT_VAL)
#define GFV_XTAL_MON_CTL_TOUT_VAL(v) \
    (((v) & FM_XTAL_MON_CTL_TOUT_VAL) >> 8U)

#define BM_XTAL_MON_CTL_MON_EN_STA  (0x01U << 1U)

#define BM_XTAL_MON_CTL_MON_EN  (0x01U << 0U)

#define DBG_MON_RS_OFF(n)   (0x8000U + 12U*(n))

#define BM_DBG_MON_RS_LOCK  (0x01U << 31U)

#define FM_DBG_MON_RS_RS    (0xfU << 1U)
#define FV_DBG_MON_RS_RS(v) \
    (((v) << 1U) & FM_DBG_MON_RS_RS)
#define GFV_DBG_MON_RS_RS(v) \
    (((v) & FM_DBG_MON_RS_RS) >> 1U)

#define BM_DBG_MON_RS_EN    (0x01U << 0U)

#define DBG_MON_CLK_SRC_OFF 0x8004U

#define FM_DBG_MON_CLK_SRC_EXT_CLK_SRC_SEL  (0xffU << 24U)
#define FV_DBG_MON_CLK_SRC_EXT_CLK_SRC_SEL(v) \
    (((v) << 24U) & FM_DBG_MON_CLK_SRC_EXT_CLK_SRC_SEL)
#define GFV_DBG_MON_CLK_SRC_EXT_CLK_SRC_SEL(v) \
    (((v) & FM_DBG_MON_CLK_SRC_EXT_CLK_SRC_SEL) >> 24U)

#define FM_DBG_MON_CLK_SRC_CORE_CLK_SRC_SEL (0xffU << 16U)
#define FV_DBG_MON_CLK_SRC_CORE_CLK_SRC_SEL(v) \
    (((v) << 16U) & FM_DBG_MON_CLK_SRC_CORE_CLK_SRC_SEL)
#define GFV_DBG_MON_CLK_SRC_CORE_CLK_SRC_SEL(v) \
    (((v) & FM_DBG_MON_CLK_SRC_CORE_CLK_SRC_SEL) >> 16U)

#define FM_DBG_MON_CLK_SRC_BUS_CLK_SRC_SEL  (0xffU << 8U)
#define FV_DBG_MON_CLK_SRC_BUS_CLK_SRC_SEL(v) \
    (((v) << 8U) & FM_DBG_MON_CLK_SRC_BUS_CLK_SRC_SEL)
#define GFV_DBG_MON_CLK_SRC_BUS_CLK_SRC_SEL(v) \
    (((v) & FM_DBG_MON_CLK_SRC_BUS_CLK_SRC_SEL) >> 8U)

#define FM_DBG_MON_CLK_SRC_IP_CLK_SRC_SEL   (0xffU << 0U)
#define FV_DBG_MON_CLK_SRC_IP_CLK_SRC_SEL(v) \
    (((v) << 0U) & FM_DBG_MON_CLK_SRC_IP_CLK_SRC_SEL)
#define GFV_DBG_MON_CLK_SRC_IP_CLK_SRC_SEL(v) \
    (((v) & FM_DBG_MON_CLK_SRC_IP_CLK_SRC_SEL) >> 0U)

#define DBG_MON_CTL_OFF 0x8008U

#define FM_DBG_MON_CTL_CLK_SEL  (0x3U << 3U)
#define FV_DBG_MON_CTL_CLK_SEL(v) \
    (((v) << 3U) & FM_DBG_MON_CTL_CLK_SEL)
#define GFV_DBG_MON_CTL_CLK_SEL(v) \
    (((v) & FM_DBG_MON_CTL_CLK_SEL) >> 3U)

#define BM_DBG_MON_CTL_CQM_GATING_EN    (0x01U << 2U)

#define BM_DBG_MON_CTL_MON_GATING_EN    (0x01U << 1U)

#define BM_DBG_MON_CTL_DBG_GATING_EN    (0x01U << 0U)

#define DBG_CTL_OFF 0x800cU

#define FM_DBG_CTL_DIV_NUM  (0xfU << 0U)
#define FV_DBG_CTL_DIV_NUM(v) \
    (((v) << 0U) & FM_DBG_CTL_DIV_NUM)
#define GFV_DBG_CTL_DIV_NUM(v) \
    (((v) & FM_DBG_CTL_DIV_NUM) >> 0U)

#define MON_CTL_OFF 0x8010U

#define FM_MON_CTL_FREQ_MON (0xffffU << 16U)
#define FV_MON_CTL_FREQ_MON(v) \
    (((v) << 16U) & FM_MON_CTL_FREQ_MON)
#define GFV_MON_CTL_FREQ_MON(v) \
    (((v) & FM_MON_CTL_FREQ_MON) >> 16U)

#define BM_MON_CTL_MON_EN_STA   (0x01U << 9U)

#define BM_MON_CTL_FREQ_MON_UPD (0x01U << 8U)

#define BM_MON_CTL_ACTIVE_LOSS_DIS  (0x01U << 2U)

#define BM_MON_CTL_MON_CLK_SRC_SEL  (0x01U << 1U)

#define BM_MON_CTL_MON_EN   (0x01U << 0U)

#define MON_CHK_THRD_OFF    0x8014U

#define FM_MON_CHK_THRD_HIGH    (0xffffU << 16U)
#define FV_MON_CHK_THRD_HIGH(v) \
    (((v) << 16U) & FM_MON_CHK_THRD_HIGH)
#define GFV_MON_CHK_THRD_HIGH(v) \
    (((v) & FM_MON_CHK_THRD_HIGH) >> 16U)

#define FM_MON_CHK_THRD_LOW (0xffffU << 0U)
#define FV_MON_CHK_THRD_LOW(v) \
    (((v) << 0U) & FM_MON_CHK_THRD_LOW)
#define GFV_MON_CHK_THRD_LOW(v) \
    (((v) & FM_MON_CHK_THRD_LOW) >> 0U)

#define LOW_SPD_CHK_CTL_OFF 0x8020U

#define FM_LOW_SPD_CHK_CTL_FREQ_MON (0xffffU << 16U)
#define FV_LOW_SPD_CHK_CTL_FREQ_MON(v) \
    (((v) << 16U) & FM_LOW_SPD_CHK_CTL_FREQ_MON)
#define GFV_LOW_SPD_CHK_CTL_FREQ_MON(v) \
    (((v) & FM_LOW_SPD_CHK_CTL_FREQ_MON) >> 16U)

#define BM_LOW_SPD_CHK_CTL_MON_EN_STA   (0x01U << 15U)

#define BM_LOW_SPD_CHK_CTL_FREQ_MON_UPD (0x01U << 14U)

#define FM_LOW_SPD_CHK_CTL_32K_SRC_SEL  (0x3fU << 8U)
#define FV_LOW_SPD_CHK_CTL_32K_SRC_SEL(v) \
    (((v) << 8U) & FM_LOW_SPD_CHK_CTL_32K_SRC_SEL)
#define GFV_LOW_SPD_CHK_CTL_32K_SRC_SEL(v) \
    (((v) & FM_LOW_SPD_CHK_CTL_32K_SRC_SEL) >> 8U)

#define FM_LOW_SPD_CHK_CTL_24M_SRC_SEL  (0x3fU << 2U)
#define FV_LOW_SPD_CHK_CTL_24M_SRC_SEL(v) \
    (((v) << 2U) & FM_LOW_SPD_CHK_CTL_24M_SRC_SEL)
#define GFV_LOW_SPD_CHK_CTL_24M_SRC_SEL(v) \
    (((v) & FM_LOW_SPD_CHK_CTL_24M_SRC_SEL) >> 2U)

#define BM_LOW_SPD_CHK_CTL_MON_EN   (0x01U << 1U)

#define BM_LOW_SPD_CHK_CTL_CLK_LOSS_DIS (0x01U << 0U)

#define LOW_SPD_CHK_THRD_OFF    0x8024U

#define FM_LOW_SPD_CHK_THRD_HIGH    (0xffffU << 16U)
#define FV_LOW_SPD_CHK_THRD_HIGH(v) \
    (((v) << 16U) & FM_LOW_SPD_CHK_THRD_HIGH)
#define GFV_LOW_SPD_CHK_THRD_HIGH(v) \
    (((v) & FM_LOW_SPD_CHK_THRD_HIGH) >> 16U)

#define FM_LOW_SPD_CHK_THRD_LOW (0xffffU << 0U)
#define FV_LOW_SPD_CHK_THRD_LOW(v) \
    (((v) << 0U) & FM_LOW_SPD_CHK_THRD_LOW)
#define GFV_LOW_SPD_CHK_THRD_LOW(v) \
    (((v) & FM_LOW_SPD_CHK_THRD_LOW) >> 0U)

#define CQM_CTL_OFF(n)  (0x8040U + 4U*(n))

#define FM_CQM_CTL_DUTY_RATE    (0x3fU << 9U)
#define FV_CQM_CTL_DUTY_RATE(v) \
    (((v) << 9U) & FM_CQM_CTL_DUTY_RATE)
#define GFV_CQM_CTL_DUTY_RATE(v) \
    (((v) & FM_CQM_CTL_DUTY_RATE) >> 9U)

#define FM_CQM_CTL_JITTER_RATE  (0x3fU << 3U)
#define FV_CQM_CTL_JITTER_RATE(v) \
    (((v) << 3U) & FM_CQM_CTL_JITTER_RATE)
#define GFV_CQM_CTL_JITTER_RATE(v) \
    (((v) & FM_CQM_CTL_JITTER_RATE) >> 3U)

#define FM_CQM_CTL_SRC_SEL  (0x3U << 1U)
#define FV_CQM_CTL_SRC_SEL(v) \
    (((v) << 1U) & FM_CQM_CTL_SRC_SEL)
#define GFV_CQM_CTL_SRC_SEL(v) \
    (((v) & FM_CQM_CTL_SRC_SEL) >> 1U)

#define BM_CQM_CTL_MON_EN   (0x01U << 0U)

#define CKGEN_FUSA_RS_OFF   0xa000U

#define BM_CKGEN_FUSA_RS_LOCK   (0x01U << 31U)

#define FM_CKGEN_FUSA_RS_RS (0xfU << 1U)
#define FV_CKGEN_FUSA_RS_RS(v) \
    (((v) << 1U) & FM_CKGEN_FUSA_RS_RS)
#define GFV_CKGEN_FUSA_RS_RS(v) \
    (((v) & FM_CKGEN_FUSA_RS_RS) >> 1U)

#define BM_CKGEN_FUSA_RS_EN (0x01U << 0U)

#define APB_ERR_INT_OFF 0xa004U

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

#define APB_LKSTEP_INT_OFF  0xa008U

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

#define WDT_LKSTEP_INT_OFF  0xa00cU

#define BM_WDT_LKSTEP_INT_SYNC_ERR_INT_CLR  (0x01U << 17U)

#define BM_WDT_LKSTEP_INT_CMP_ERR_INT_CLR   (0x01U << 16U)

#define BM_WDT_LKSTEP_INT_SYNC_ERR_INT_STA  (0x01U << 9U)

#define BM_WDT_LKSTEP_INT_CMP_ERR_INT_STA   (0x01U << 8U)

#define BM_WDT_LKSTEP_INT_SYNC_ERR_INT_EN   (0x01U << 1U)

#define BM_WDT_LKSTEP_INT_CMP_ERR_INT_EN    (0x01U << 0U)

#define CKGEN_FUSA_INT_OFF  0xa100U

#define BM_CKGEN_FUSA_INT_LKSTEP_CMP_ERR_CLR    (0x01U << 19U)

#define BM_CKGEN_FUSA_INT_SYNC_ERR_CLR  (0x01U << 18U)

#define BM_CKGEN_FUSA_INT_SWM_TRANS_ERR_CLR (0x01U << 17U)

#define BM_CKGEN_FUSA_INT_SWM_CHK_ERR_CLR   (0x01U << 16U)

#define BM_CKGEN_FUSA_INT_LKSTEP_CMP_ERR_STA    (0x01U << 11U)

#define BM_CKGEN_FUSA_INT_SYNC_ERR_STA  (0x01U << 10U)

#define BM_CKGEN_FUSA_INT_SWM_TRANS_ERR_STA (0x01U << 9U)

#define BM_CKGEN_FUSA_INT_SWM_CHK_ERR_STA   (0x01U << 8U)

#define BM_CKGEN_FUSA_INT_LKSTEP_CMP_ERR_EN (0x01U << 3U)

#define BM_CKGEN_FUSA_INT_SYNC_ERR_EN   (0x01U << 2U)

#define BM_CKGEN_FUSA_INT_SWM_TRANS_ERR_EN  (0x01U << 1U)

#define BM_CKGEN_FUSA_INT_SWM_CHK_ERR_EN    (0x01U << 0U)

#define CKGEN_INJ_EN_OFF    0xa200U

#define FM_CKGEN_INJ_EN_INJ_EN  (0xffffU << 0U)
#define FV_CKGEN_INJ_EN_INJ_EN(v) \
    (((v) << 0U) & FM_CKGEN_INJ_EN_INJ_EN)
#define GFV_CKGEN_INJ_EN_INJ_EN(v) \
    (((v) & FM_CKGEN_INJ_EN_INJ_EN) >> 0U)

#define CKGEN_INJ_BIT_OFF   0xa204U

#define FM_CKGEN_INJ_BIT_IRQ_INJ    (0x7U << 29U)
#define FV_CKGEN_INJ_BIT_IRQ_INJ(v) \
    (((v) << 29U) & FM_CKGEN_INJ_BIT_IRQ_INJ)
#define GFV_CKGEN_INJ_BIT_IRQ_INJ(v) \
    (((v) & FM_CKGEN_INJ_BIT_IRQ_INJ) >> 29U)

#define FM_CKGEN_INJ_BIT_ERR_INJ_BIT    (0x1fffffffU << 0U)
#define FV_CKGEN_INJ_BIT_ERR_INJ_BIT(v) \
    (((v) << 0U) & FM_CKGEN_INJ_BIT_ERR_INJ_BIT)
#define GFV_CKGEN_INJ_BIT_ERR_INJ_BIT(v) \
    (((v) & FM_CKGEN_INJ_BIT_ERR_INJ_BIT) >> 0U)

#define CKGEN_INJ_BIT_1_OFF 0xa208U

#define FM_CKGEN_INJ_BIT_1_ERR_INJ_BIT  (0xffffffffU << 0U)
#define FV_CKGEN_INJ_BIT_1_ERR_INJ_BIT(v) \
    (((v) << 0U) & FM_CKGEN_INJ_BIT_1_ERR_INJ_BIT)
#define GFV_CKGEN_INJ_BIT_1_ERR_INJ_BIT(v) \
    (((v) & FM_CKGEN_INJ_BIT_1_ERR_INJ_BIT) >> 0U)

#define CKGEN_INJ_BIT_2_OFF 0xa20cU

#define FM_CKGEN_INJ_BIT_2_ERR_INJ_BIT  (0xffffffffU << 0U)
#define FV_CKGEN_INJ_BIT_2_ERR_INJ_BIT(v) \
    (((v) << 0U) & FM_CKGEN_INJ_BIT_2_ERR_INJ_BIT)
#define GFV_CKGEN_INJ_BIT_2_ERR_INJ_BIT(v) \
    (((v) & FM_CKGEN_INJ_BIT_2_ERR_INJ_BIT) >> 0U)

#define IP_CLK_COR_EN_OFF(n)    (0xa300U + 12U*(n))

#define FM_IP_CLK_COR_EN_INT_EN (0xffffffffU << 0U)
#define FV_IP_CLK_COR_EN_INT_EN(v) \
    (((v) << 0U) & FM_IP_CLK_COR_EN_INT_EN)
#define GFV_IP_CLK_COR_EN_INT_EN(v) \
    (((v) & FM_IP_CLK_COR_EN_INT_EN) >> 0U)

#define IP_CLK_UNC_EN_OFF(n)    (0xa304U + 12U*(n))

#define FM_IP_CLK_UNC_EN_INT_EN (0xffffffffU << 0U)
#define FV_IP_CLK_UNC_EN_INT_EN(v) \
    (((v) << 0U) & FM_IP_CLK_UNC_EN_INT_EN)
#define GFV_IP_CLK_UNC_EN_INT_EN(v) \
    (((v) & FM_IP_CLK_UNC_EN_INT_EN) >> 0U)

#define IP_CLK_INT_STA_OFF(n)   (0xa308U + 12U*(n))

#define BM_IP_CLK_INT_STA_INT_STA_31    (0x01U << 31U)

#define BM_IP_CLK_INT_STA_INT_STA_30    (0x01U << 30U)

#define BM_IP_CLK_INT_STA_INT_STA_29    (0x01U << 29U)

#define BM_IP_CLK_INT_STA_INT_STA_28    (0x01U << 28U)

#define BM_IP_CLK_INT_STA_INT_STA_27    (0x01U << 27U)

#define BM_IP_CLK_INT_STA_INT_STA_26    (0x01U << 26U)

#define BM_IP_CLK_INT_STA_INT_STA_25    (0x01U << 25U)

#define BM_IP_CLK_INT_STA_INT_STA_24    (0x01U << 24U)

#define BM_IP_CLK_INT_STA_INT_STA_23    (0x01U << 23U)

#define BM_IP_CLK_INT_STA_INT_STA_22    (0x01U << 22U)

#define BM_IP_CLK_INT_STA_INT_STA_21    (0x01U << 21U)

#define BM_IP_CLK_INT_STA_INT_STA_20    (0x01U << 20U)

#define BM_IP_CLK_INT_STA_INT_STA_19    (0x01U << 19U)

#define BM_IP_CLK_INT_STA_INT_STA_18    (0x01U << 18U)

#define BM_IP_CLK_INT_STA_INT_STA_17    (0x01U << 17U)

#define BM_IP_CLK_INT_STA_INT_STA_16    (0x01U << 16U)

#define BM_IP_CLK_INT_STA_INT_STA_15    (0x01U << 15U)

#define BM_IP_CLK_INT_STA_INT_STA_14    (0x01U << 14U)

#define BM_IP_CLK_INT_STA_INT_STA_13    (0x01U << 13U)

#define BM_IP_CLK_INT_STA_INT_STA_12    (0x01U << 12U)

#define BM_IP_CLK_INT_STA_INT_STA_11    (0x01U << 11U)

#define BM_IP_CLK_INT_STA_INT_STA_10    (0x01U << 10U)

#define BM_IP_CLK_INT_STA_INT_STA_9 (0x01U << 9U)

#define BM_IP_CLK_INT_STA_INT_STA_8 (0x01U << 8U)

#define BM_IP_CLK_INT_STA_INT_STA_7 (0x01U << 7U)

#define BM_IP_CLK_INT_STA_INT_STA_6 (0x01U << 6U)

#define BM_IP_CLK_INT_STA_INT_STA_5 (0x01U << 5U)

#define BM_IP_CLK_INT_STA_INT_STA_4 (0x01U << 4U)

#define BM_IP_CLK_INT_STA_INT_STA_3 (0x01U << 3U)

#define BM_IP_CLK_INT_STA_INT_STA_2 (0x01U << 2U)

#define BM_IP_CLK_INT_STA_INT_STA_1 (0x01U << 1U)

#define BM_IP_CLK_INT_STA_INT_STA_0 (0x01U << 0U)

#define BUS_CLK_COR_EN_OFF(n)   (0xa400U + 12U*(n))

#define FM_BUS_CLK_COR_EN_INT_EN    (0xffffffffU << 0U)
#define FV_BUS_CLK_COR_EN_INT_EN(v) \
    (((v) << 0U) & FM_BUS_CLK_COR_EN_INT_EN)
#define GFV_BUS_CLK_COR_EN_INT_EN(v) \
    (((v) & FM_BUS_CLK_COR_EN_INT_EN) >> 0U)

#define BUS_CLK_UNC_EN_OFF(n)   (0xa404U + 12U*(n))

#define FM_BUS_CLK_UNC_EN_INT_EN    (0xffffffffU << 0U)
#define FV_BUS_CLK_UNC_EN_INT_EN(v) \
    (((v) << 0U) & FM_BUS_CLK_UNC_EN_INT_EN)
#define GFV_BUS_CLK_UNC_EN_INT_EN(v) \
    (((v) & FM_BUS_CLK_UNC_EN_INT_EN) >> 0U)

#define BUS_CLK_INT_STA_OFF(n)  (0xa408U + 12U*(n))

#define BM_BUS_CLK_INT_STA_INT_STA_31   (0x01U << 31U)

#define BM_BUS_CLK_INT_STA_INT_STA_30   (0x01U << 30U)

#define BM_BUS_CLK_INT_STA_INT_STA_29   (0x01U << 29U)

#define BM_BUS_CLK_INT_STA_INT_STA_28   (0x01U << 28U)

#define BM_BUS_CLK_INT_STA_INT_STA_27   (0x01U << 27U)

#define BM_BUS_CLK_INT_STA_INT_STA_26   (0x01U << 26U)

#define BM_BUS_CLK_INT_STA_INT_STA_25   (0x01U << 25U)

#define BM_BUS_CLK_INT_STA_INT_STA_24   (0x01U << 24U)

#define BM_BUS_CLK_INT_STA_INT_STA_23   (0x01U << 23U)

#define BM_BUS_CLK_INT_STA_INT_STA_22   (0x01U << 22U)

#define BM_BUS_CLK_INT_STA_INT_STA_21   (0x01U << 21U)

#define BM_BUS_CLK_INT_STA_INT_STA_20   (0x01U << 20U)

#define BM_BUS_CLK_INT_STA_INT_STA_19   (0x01U << 19U)

#define BM_BUS_CLK_INT_STA_INT_STA_18   (0x01U << 18U)

#define BM_BUS_CLK_INT_STA_INT_STA_17   (0x01U << 17U)

#define BM_BUS_CLK_INT_STA_INT_STA_16   (0x01U << 16U)

#define BM_BUS_CLK_INT_STA_INT_STA_15   (0x01U << 15U)

#define BM_BUS_CLK_INT_STA_INT_STA_14   (0x01U << 14U)

#define BM_BUS_CLK_INT_STA_INT_STA_13   (0x01U << 13U)

#define BM_BUS_CLK_INT_STA_INT_STA_12   (0x01U << 12U)

#define BM_BUS_CLK_INT_STA_INT_STA_11   (0x01U << 11U)

#define BM_BUS_CLK_INT_STA_INT_STA_10   (0x01U << 10U)

#define BM_BUS_CLK_INT_STA_INT_STA_9    (0x01U << 9U)

#define BM_BUS_CLK_INT_STA_INT_STA_8    (0x01U << 8U)

#define BM_BUS_CLK_INT_STA_INT_STA_7    (0x01U << 7U)

#define BM_BUS_CLK_INT_STA_INT_STA_6    (0x01U << 6U)

#define BM_BUS_CLK_INT_STA_INT_STA_5    (0x01U << 5U)

#define BM_BUS_CLK_INT_STA_INT_STA_4    (0x01U << 4U)

#define BM_BUS_CLK_INT_STA_INT_STA_3    (0x01U << 3U)

#define BM_BUS_CLK_INT_STA_INT_STA_2    (0x01U << 2U)

#define BM_BUS_CLK_INT_STA_INT_STA_1    (0x01U << 1U)

#define BM_BUS_CLK_INT_STA_INT_STA_0    (0x01U << 0U)

#define CORE_CLK_COR_EN_OFF(n)  (0xa500U + 12U*(n))

#define FM_CORE_CLK_COR_EN_INT_EN   (0xffffffffU << 0U)
#define FV_CORE_CLK_COR_EN_INT_EN(v) \
    (((v) << 0U) & FM_CORE_CLK_COR_EN_INT_EN)
#define GFV_CORE_CLK_COR_EN_INT_EN(v) \
    (((v) & FM_CORE_CLK_COR_EN_INT_EN) >> 0U)

#define CORE_CLK_UNC_EN_OFF(n)  (0xa504U + 12U*(n))

#define FM_CORE_CLK_UNC_EN_INT_EN   (0xffffffffU << 0U)
#define FV_CORE_CLK_UNC_EN_INT_EN(v) \
    (((v) << 0U) & FM_CORE_CLK_UNC_EN_INT_EN)
#define GFV_CORE_CLK_UNC_EN_INT_EN(v) \
    (((v) & FM_CORE_CLK_UNC_EN_INT_EN) >> 0U)

#define CORE_CLK_INT_STA_OFF(n) (0xa508U + 12U*(n))

#define BM_CORE_CLK_INT_STA_INT_STA_31  (0x01U << 31U)

#define BM_CORE_CLK_INT_STA_INT_STA_30  (0x01U << 30U)

#define BM_CORE_CLK_INT_STA_INT_STA_29  (0x01U << 29U)

#define BM_CORE_CLK_INT_STA_INT_STA_28  (0x01U << 28U)

#define BM_CORE_CLK_INT_STA_INT_STA_27  (0x01U << 27U)

#define BM_CORE_CLK_INT_STA_INT_STA_26  (0x01U << 26U)

#define BM_CORE_CLK_INT_STA_INT_STA_25  (0x01U << 25U)

#define BM_CORE_CLK_INT_STA_INT_STA_24  (0x01U << 24U)

#define BM_CORE_CLK_INT_STA_INT_STA_23  (0x01U << 23U)

#define BM_CORE_CLK_INT_STA_INT_STA_22  (0x01U << 22U)

#define BM_CORE_CLK_INT_STA_INT_STA_21  (0x01U << 21U)

#define BM_CORE_CLK_INT_STA_INT_STA_20  (0x01U << 20U)

#define BM_CORE_CLK_INT_STA_INT_STA_19  (0x01U << 19U)

#define BM_CORE_CLK_INT_STA_INT_STA_18  (0x01U << 18U)

#define BM_CORE_CLK_INT_STA_INT_STA_17  (0x01U << 17U)

#define BM_CORE_CLK_INT_STA_INT_STA_16  (0x01U << 16U)

#define BM_CORE_CLK_INT_STA_INT_STA_15  (0x01U << 15U)

#define BM_CORE_CLK_INT_STA_INT_STA_14  (0x01U << 14U)

#define BM_CORE_CLK_INT_STA_INT_STA_13  (0x01U << 13U)

#define BM_CORE_CLK_INT_STA_INT_STA_12  (0x01U << 12U)

#define BM_CORE_CLK_INT_STA_INT_STA_11  (0x01U << 11U)

#define BM_CORE_CLK_INT_STA_INT_STA_10  (0x01U << 10U)

#define BM_CORE_CLK_INT_STA_INT_STA_9   (0x01U << 9U)

#define BM_CORE_CLK_INT_STA_INT_STA_8   (0x01U << 8U)

#define BM_CORE_CLK_INT_STA_INT_STA_7   (0x01U << 7U)

#define BM_CORE_CLK_INT_STA_INT_STA_6   (0x01U << 6U)

#define BM_CORE_CLK_INT_STA_INT_STA_5   (0x01U << 5U)

#define BM_CORE_CLK_INT_STA_INT_STA_4   (0x01U << 4U)

#define BM_CORE_CLK_INT_STA_INT_STA_3   (0x01U << 3U)

#define BM_CORE_CLK_INT_STA_INT_STA_2   (0x01U << 2U)

#define BM_CORE_CLK_INT_STA_INT_STA_1   (0x01U << 1U)

#define BM_CORE_CLK_INT_STA_INT_STA_0   (0x01U << 0U)

#define PCG_COR_EN_OFF(n)   (0xa600U + 12U*(n))

#define FM_PCG_COR_EN_INT_EN    (0xffffffffU << 0U)
#define FV_PCG_COR_EN_INT_EN(v) \
    (((v) << 0U) & FM_PCG_COR_EN_INT_EN)
#define GFV_PCG_COR_EN_INT_EN(v) \
    (((v) & FM_PCG_COR_EN_INT_EN) >> 0U)

#define PCG_UNC_EN_OFF(n)   (0xa604U + 12U*(n))

#define FM_PCG_UNC_EN_INT_EN    (0xffffffffU << 0U)
#define FV_PCG_UNC_EN_INT_EN(v) \
    (((v) << 0U) & FM_PCG_UNC_EN_INT_EN)
#define GFV_PCG_UNC_EN_INT_EN(v) \
    (((v) & FM_PCG_UNC_EN_INT_EN) >> 0U)

#define PCG_INT_STA_OFF(n)  (0xa608U + 12U*(n))

#define BM_PCG_INT_STA_INT_STA_31   (0x01U << 31U)

#define BM_PCG_INT_STA_INT_STA_30   (0x01U << 30U)

#define BM_PCG_INT_STA_INT_STA_29   (0x01U << 29U)

#define BM_PCG_INT_STA_INT_STA_28   (0x01U << 28U)

#define BM_PCG_INT_STA_INT_STA_27   (0x01U << 27U)

#define BM_PCG_INT_STA_INT_STA_26   (0x01U << 26U)

#define BM_PCG_INT_STA_INT_STA_25   (0x01U << 25U)

#define BM_PCG_INT_STA_INT_STA_24   (0x01U << 24U)

#define BM_PCG_INT_STA_INT_STA_23   (0x01U << 23U)

#define BM_PCG_INT_STA_INT_STA_22   (0x01U << 22U)

#define BM_PCG_INT_STA_INT_STA_21   (0x01U << 21U)

#define BM_PCG_INT_STA_INT_STA_20   (0x01U << 20U)

#define BM_PCG_INT_STA_INT_STA_19   (0x01U << 19U)

#define BM_PCG_INT_STA_INT_STA_18   (0x01U << 18U)

#define BM_PCG_INT_STA_INT_STA_17   (0x01U << 17U)

#define BM_PCG_INT_STA_INT_STA_16   (0x01U << 16U)

#define BM_PCG_INT_STA_INT_STA_15   (0x01U << 15U)

#define BM_PCG_INT_STA_INT_STA_14   (0x01U << 14U)

#define BM_PCG_INT_STA_INT_STA_13   (0x01U << 13U)

#define BM_PCG_INT_STA_INT_STA_12   (0x01U << 12U)

#define BM_PCG_INT_STA_INT_STA_11   (0x01U << 11U)

#define BM_PCG_INT_STA_INT_STA_10   (0x01U << 10U)

#define BM_PCG_INT_STA_INT_STA_9    (0x01U << 9U)

#define BM_PCG_INT_STA_INT_STA_8    (0x01U << 8U)

#define BM_PCG_INT_STA_INT_STA_7    (0x01U << 7U)

#define BM_PCG_INT_STA_INT_STA_6    (0x01U << 6U)

#define BM_PCG_INT_STA_INT_STA_5    (0x01U << 5U)

#define BM_PCG_INT_STA_INT_STA_4    (0x01U << 4U)

#define BM_PCG_INT_STA_INT_STA_3    (0x01U << 3U)

#define BM_PCG_INT_STA_INT_STA_2    (0x01U << 2U)

#define BM_PCG_INT_STA_INT_STA_1    (0x01U << 1U)

#define BM_PCG_INT_STA_INT_STA_0    (0x01U << 0U)

#define BCG_COR_EN_OFF(n)   (0xa700U + 12U*(n))

#define FM_BCG_COR_EN_INT_EN    (0xffffffffU << 0U)
#define FV_BCG_COR_EN_INT_EN(v) \
    (((v) << 0U) & FM_BCG_COR_EN_INT_EN)
#define GFV_BCG_COR_EN_INT_EN(v) \
    (((v) & FM_BCG_COR_EN_INT_EN) >> 0U)

#define BCG_UNC_EN_OFF(n)   (0xa704U + 12U*(n))

#define FM_BCG_UNC_EN_INT_EN    (0xffffffffU << 0U)
#define FV_BCG_UNC_EN_INT_EN(v) \
    (((v) << 0U) & FM_BCG_UNC_EN_INT_EN)
#define GFV_BCG_UNC_EN_INT_EN(v) \
    (((v) & FM_BCG_UNC_EN_INT_EN) >> 0U)

#define BCG_INT_STA_OFF(n)  (0xa708U + 12U*(n))

#define BM_BCG_INT_STA_INT_STA_31   (0x01U << 31U)

#define BM_BCG_INT_STA_INT_STA_30   (0x01U << 30U)

#define BM_BCG_INT_STA_INT_STA_29   (0x01U << 29U)

#define BM_BCG_INT_STA_INT_STA_28   (0x01U << 28U)

#define BM_BCG_INT_STA_INT_STA_27   (0x01U << 27U)

#define BM_BCG_INT_STA_INT_STA_26   (0x01U << 26U)

#define BM_BCG_INT_STA_INT_STA_25   (0x01U << 25U)

#define BM_BCG_INT_STA_INT_STA_24   (0x01U << 24U)

#define BM_BCG_INT_STA_INT_STA_23   (0x01U << 23U)

#define BM_BCG_INT_STA_INT_STA_22   (0x01U << 22U)

#define BM_BCG_INT_STA_INT_STA_21   (0x01U << 21U)

#define BM_BCG_INT_STA_INT_STA_20   (0x01U << 20U)

#define BM_BCG_INT_STA_INT_STA_19   (0x01U << 19U)

#define BM_BCG_INT_STA_INT_STA_18   (0x01U << 18U)

#define BM_BCG_INT_STA_INT_STA_17   (0x01U << 17U)

#define BM_BCG_INT_STA_INT_STA_16   (0x01U << 16U)

#define BM_BCG_INT_STA_INT_STA_15   (0x01U << 15U)

#define BM_BCG_INT_STA_INT_STA_14   (0x01U << 14U)

#define BM_BCG_INT_STA_INT_STA_13   (0x01U << 13U)

#define BM_BCG_INT_STA_INT_STA_12   (0x01U << 12U)

#define BM_BCG_INT_STA_INT_STA_11   (0x01U << 11U)

#define BM_BCG_INT_STA_INT_STA_10   (0x01U << 10U)

#define BM_BCG_INT_STA_INT_STA_9    (0x01U << 9U)

#define BM_BCG_INT_STA_INT_STA_8    (0x01U << 8U)

#define BM_BCG_INT_STA_INT_STA_7    (0x01U << 7U)

#define BM_BCG_INT_STA_INT_STA_6    (0x01U << 6U)

#define BM_BCG_INT_STA_INT_STA_5    (0x01U << 5U)

#define BM_BCG_INT_STA_INT_STA_4    (0x01U << 4U)

#define BM_BCG_INT_STA_INT_STA_3    (0x01U << 3U)

#define BM_BCG_INT_STA_INT_STA_2    (0x01U << 2U)

#define BM_BCG_INT_STA_INT_STA_1    (0x01U << 1U)

#define BM_BCG_INT_STA_INT_STA_0    (0x01U << 0U)

#define CCG_COR_EN_OFF(n)   (0xa800U + 12U*(n))

#define FM_CCG_COR_EN_INT_EN    (0xffffffffU << 0U)
#define FV_CCG_COR_EN_INT_EN(v) \
    (((v) << 0U) & FM_CCG_COR_EN_INT_EN)
#define GFV_CCG_COR_EN_INT_EN(v) \
    (((v) & FM_CCG_COR_EN_INT_EN) >> 0U)

#define CCG_UNC_EN_OFF(n)   (0xa804U + 12U*(n))

#define FM_CCG_UNC_EN_INT_EN    (0xffffffffU << 0U)
#define FV_CCG_UNC_EN_INT_EN(v) \
    (((v) << 0U) & FM_CCG_UNC_EN_INT_EN)
#define GFV_CCG_UNC_EN_INT_EN(v) \
    (((v) & FM_CCG_UNC_EN_INT_EN) >> 0U)

#define CCG_INT_STA_OFF(n)  (0xa808U + 12U*(n))

#define BM_CCG_INT_STA_INT_STA_31   (0x01U << 31U)

#define BM_CCG_INT_STA_INT_STA_30   (0x01U << 30U)

#define BM_CCG_INT_STA_INT_STA_29   (0x01U << 29U)

#define BM_CCG_INT_STA_INT_STA_28   (0x01U << 28U)

#define BM_CCG_INT_STA_INT_STA_27   (0x01U << 27U)

#define BM_CCG_INT_STA_INT_STA_26   (0x01U << 26U)

#define BM_CCG_INT_STA_INT_STA_25   (0x01U << 25U)

#define BM_CCG_INT_STA_INT_STA_24   (0x01U << 24U)

#define BM_CCG_INT_STA_INT_STA_23   (0x01U << 23U)

#define BM_CCG_INT_STA_INT_STA_22   (0x01U << 22U)

#define BM_CCG_INT_STA_INT_STA_21   (0x01U << 21U)

#define BM_CCG_INT_STA_INT_STA_20   (0x01U << 20U)

#define BM_CCG_INT_STA_INT_STA_19   (0x01U << 19U)

#define BM_CCG_INT_STA_INT_STA_18   (0x01U << 18U)

#define BM_CCG_INT_STA_INT_STA_17   (0x01U << 17U)

#define BM_CCG_INT_STA_INT_STA_16   (0x01U << 16U)

#define BM_CCG_INT_STA_INT_STA_15   (0x01U << 15U)

#define BM_CCG_INT_STA_INT_STA_14   (0x01U << 14U)

#define BM_CCG_INT_STA_INT_STA_13   (0x01U << 13U)

#define BM_CCG_INT_STA_INT_STA_12   (0x01U << 12U)

#define BM_CCG_INT_STA_INT_STA_11   (0x01U << 11U)

#define BM_CCG_INT_STA_INT_STA_10   (0x01U << 10U)

#define BM_CCG_INT_STA_INT_STA_9    (0x01U << 9U)

#define BM_CCG_INT_STA_INT_STA_8    (0x01U << 8U)

#define BM_CCG_INT_STA_INT_STA_7    (0x01U << 7U)

#define BM_CCG_INT_STA_INT_STA_6    (0x01U << 6U)

#define BM_CCG_INT_STA_INT_STA_5    (0x01U << 5U)

#define BM_CCG_INT_STA_INT_STA_4    (0x01U << 4U)

#define BM_CCG_INT_STA_INT_STA_3    (0x01U << 3U)

#define BM_CCG_INT_STA_INT_STA_2    (0x01U << 2U)

#define BM_CCG_INT_STA_INT_STA_1    (0x01U << 1U)

#define BM_CCG_INT_STA_INT_STA_0    (0x01U << 0U)

#define PLL_UNC_EN_OFF  0xa904U

#define FM_PLL_UNC_EN_INT_EN    (0xffU << 0U)
#define FV_PLL_UNC_EN_INT_EN(v) \
    (((v) << 0U) & FM_PLL_UNC_EN_INT_EN)
#define GFV_PLL_UNC_EN_INT_EN(v) \
    (((v) & FM_PLL_UNC_EN_INT_EN) >> 0U)

#define PLL_INT_STA_OFF 0xa908U

#define BM_PLL_INT_STA_INT_STA_2    (0x01U << 2U)

#define BM_PLL_INT_STA_INT_STA_1    (0x01U << 1U)

#define BM_PLL_INT_STA_INT_STA_0    (0x01U << 0U)

#define XTAL_UNC_EN_OFF 0xaa04U

#define FM_XTAL_UNC_EN_INT_EN   (0xffU << 0U)
#define FV_XTAL_UNC_EN_INT_EN(v) \
    (((v) << 0U) & FM_XTAL_UNC_EN_INT_EN)
#define GFV_XTAL_UNC_EN_INT_EN(v) \
    (((v) & FM_XTAL_UNC_EN_INT_EN) >> 0U)

#define XTAL_INT_STA_OFF    0xaa08U

#define BM_XTAL_INT_STA_INT_STA_0   (0x01U << 0U)

#define MON_COR_EN_OFF  0xab00U

#define BM_MON_COR_EN_INT_EN    (0x01U << 0U)

#define MON_UNC_EN_OFF  0xab04U

#define BM_MON_UNC_EN_INT_EN    (0x01U << 0U)

#define MON_INT_STA_OFF 0xab08U

#define BM_MON_INT_STA_INT_STA  (0x01U << 0U)

#define LOW_SPD_COR_EN_OFF  0xac00U

#define BM_LOW_SPD_COR_EN_INT_EN    (0x01U << 0U)

#define LOW_SPD_UNC_EN_OFF  0xac04U

#define BM_LOW_SPD_UNC_EN_INT_EN    (0x01U << 0U)

#define LOW_SPD_INT_STA_OFF 0xac08U

#define BM_LOW_SPD_INT_STA_INT_STA  (0x01U << 0U)

#define CQM_COR_EN_OFF  0xad00U

#define FM_CQM_COR_EN_INT_EN    (0xffffffffU << 0U)
#define FV_CQM_COR_EN_INT_EN(v) \
    (((v) << 0U) & FM_CQM_COR_EN_INT_EN)
#define GFV_CQM_COR_EN_INT_EN(v) \
    (((v) & FM_CQM_COR_EN_INT_EN) >> 0U)

#define CQM_UNC_EN_OFF  0xad04U

#define FM_CQM_UNC_EN_INT_EN    (0xffffffffU << 0U)
#define FV_CQM_UNC_EN_INT_EN(v) \
    (((v) << 0U) & FM_CQM_UNC_EN_INT_EN)
#define GFV_CQM_UNC_EN_INT_EN(v) \
    (((v) & FM_CQM_UNC_EN_INT_EN) >> 0U)

#define CQM_DUTY_INT_STA_OFF    0xad08U

#define BM_CQM_DUTY_INT_STA_INT_STA_31  (0x01U << 31U)

#define BM_CQM_DUTY_INT_STA_INT_STA_30  (0x01U << 30U)

#define BM_CQM_DUTY_INT_STA_INT_STA_29  (0x01U << 29U)

#define BM_CQM_DUTY_INT_STA_INT_STA_28  (0x01U << 28U)

#define BM_CQM_DUTY_INT_STA_INT_STA_27  (0x01U << 27U)

#define BM_CQM_DUTY_INT_STA_INT_STA_26  (0x01U << 26U)

#define BM_CQM_DUTY_INT_STA_INT_STA_25  (0x01U << 25U)

#define BM_CQM_DUTY_INT_STA_INT_STA_24  (0x01U << 24U)

#define BM_CQM_DUTY_INT_STA_INT_STA_23  (0x01U << 23U)

#define BM_CQM_DUTY_INT_STA_INT_STA_22  (0x01U << 22U)

#define BM_CQM_DUTY_INT_STA_INT_STA_21  (0x01U << 21U)

#define BM_CQM_DUTY_INT_STA_INT_STA_20  (0x01U << 20U)

#define BM_CQM_DUTY_INT_STA_INT_STA_19  (0x01U << 19U)

#define BM_CQM_DUTY_INT_STA_INT_STA_18  (0x01U << 18U)

#define BM_CQM_DUTY_INT_STA_INT_STA_17  (0x01U << 17U)

#define BM_CQM_DUTY_INT_STA_INT_STA_16  (0x01U << 16U)

#define BM_CQM_DUTY_INT_STA_INT_STA_15  (0x01U << 15U)

#define BM_CQM_DUTY_INT_STA_INT_STA_14  (0x01U << 14U)

#define BM_CQM_DUTY_INT_STA_INT_STA_13  (0x01U << 13U)

#define BM_CQM_DUTY_INT_STA_INT_STA_12  (0x01U << 12U)

#define BM_CQM_DUTY_INT_STA_INT_STA_11  (0x01U << 11U)

#define BM_CQM_DUTY_INT_STA_INT_STA_10  (0x01U << 10U)

#define BM_CQM_DUTY_INT_STA_INT_STA_9   (0x01U << 9U)

#define BM_CQM_DUTY_INT_STA_INT_STA_8   (0x01U << 8U)

#define BM_CQM_DUTY_INT_STA_INT_STA_7   (0x01U << 7U)

#define BM_CQM_DUTY_INT_STA_INT_STA_6   (0x01U << 6U)

#define BM_CQM_DUTY_INT_STA_INT_STA_5   (0x01U << 5U)

#define BM_CQM_DUTY_INT_STA_INT_STA_4   (0x01U << 4U)

#define BM_CQM_DUTY_INT_STA_INT_STA_3   (0x01U << 3U)

#define BM_CQM_DUTY_INT_STA_INT_STA_2   (0x01U << 2U)

#define BM_CQM_DUTY_INT_STA_INT_STA_1   (0x01U << 1U)

#define BM_CQM_DUTY_INT_STA_INT_STA_0   (0x01U << 0U)

#define CQM_JITTER_INT_STA_OFF  0xad0cU

#define BM_CQM_JITTER_INT_STA_INT_STA_31    (0x01U << 31U)

#define BM_CQM_JITTER_INT_STA_INT_STA_30    (0x01U << 30U)

#define BM_CQM_JITTER_INT_STA_INT_STA_29    (0x01U << 29U)

#define BM_CQM_JITTER_INT_STA_INT_STA_28    (0x01U << 28U)

#define BM_CQM_JITTER_INT_STA_INT_STA_27    (0x01U << 27U)

#define BM_CQM_JITTER_INT_STA_INT_STA_26    (0x01U << 26U)

#define BM_CQM_JITTER_INT_STA_INT_STA_25    (0x01U << 25U)

#define BM_CQM_JITTER_INT_STA_INT_STA_24    (0x01U << 24U)

#define BM_CQM_JITTER_INT_STA_INT_STA_23    (0x01U << 23U)

#define BM_CQM_JITTER_INT_STA_INT_STA_22    (0x01U << 22U)

#define BM_CQM_JITTER_INT_STA_INT_STA_21    (0x01U << 21U)

#define BM_CQM_JITTER_INT_STA_INT_STA_20    (0x01U << 20U)

#define BM_CQM_JITTER_INT_STA_INT_STA_19    (0x01U << 19U)

#define BM_CQM_JITTER_INT_STA_INT_STA_18    (0x01U << 18U)

#define BM_CQM_JITTER_INT_STA_INT_STA_17    (0x01U << 17U)

#define BM_CQM_JITTER_INT_STA_INT_STA_16    (0x01U << 16U)

#define BM_CQM_JITTER_INT_STA_INT_STA_15    (0x01U << 15U)

#define BM_CQM_JITTER_INT_STA_INT_STA_14    (0x01U << 14U)

#define BM_CQM_JITTER_INT_STA_INT_STA_13    (0x01U << 13U)

#define BM_CQM_JITTER_INT_STA_INT_STA_12    (0x01U << 12U)

#define BM_CQM_JITTER_INT_STA_INT_STA_11    (0x01U << 11U)

#define BM_CQM_JITTER_INT_STA_INT_STA_10    (0x01U << 10U)

#define BM_CQM_JITTER_INT_STA_INT_STA_9 (0x01U << 9U)

#define BM_CQM_JITTER_INT_STA_INT_STA_8 (0x01U << 8U)

#define BM_CQM_JITTER_INT_STA_INT_STA_7 (0x01U << 7U)

#define BM_CQM_JITTER_INT_STA_INT_STA_6 (0x01U << 6U)

#define BM_CQM_JITTER_INT_STA_INT_STA_5 (0x01U << 5U)

#define BM_CQM_JITTER_INT_STA_INT_STA_4 (0x01U << 4U)

#define BM_CQM_JITTER_INT_STA_INT_STA_3 (0x01U << 3U)

#define BM_CQM_JITTER_INT_STA_INT_STA_2 (0x01U << 2U)

#define BM_CQM_JITTER_INT_STA_INT_STA_1 (0x01U << 1U)

#define BM_CQM_JITTER_INT_STA_INT_STA_0 (0x01U << 0U)

#define CKGEN_FUNC_INT_RS_OFF   0xb000U

#define BM_CKGEN_FUNC_INT_RS_LOCK   (0x01U << 31U)

#define FM_CKGEN_FUNC_INT_RS_RS (0xfU << 1U)
#define FV_CKGEN_FUNC_INT_RS_RS(v) \
    (((v) << 1U) & FM_CKGEN_FUNC_INT_RS_RS)
#define GFV_CKGEN_FUNC_INT_RS_RS(v) \
    (((v) & FM_CKGEN_FUNC_INT_RS_RS) >> 1U)

#define BM_CKGEN_FUNC_INT_RS_EN (0x01U << 0U)

#define CKGEN_FUNC_INT_OFF  0xb004U

#define BM_CKGEN_FUNC_INT_ACCESS_PER_ERR_CLR    (0x01U << 16U)

#define BM_CKGEN_FUNC_INT_ACCESS_PER_ERR_STA    (0x01U << 8U)

#define BM_CKGEN_FUNC_INT_ACCESS_PER_ERR_EN (0x01U << 0U)


#ifdef __cplusplus
}
#endif

#endif  /* CKGEN_REG_H */
