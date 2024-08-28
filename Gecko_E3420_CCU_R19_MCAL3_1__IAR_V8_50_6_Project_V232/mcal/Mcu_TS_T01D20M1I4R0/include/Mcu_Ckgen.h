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
 *  \file     Mcu_Ckgen.h                                                                           *
 *  \brief    This file contains interface header for Mcu MCAL driver, ...                             *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/01     <td>1.0.0                               *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef MCU_CKGEN_H
#define MCU_CKGEN_H

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Mcu_GeneralTypes.h"
/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
/* Domain access permission */
#define CKGEN_DOM_PER                       (0x0U)
#define CKGEN_DOM_PER_SEC_PER_LSB           (0U)
#define CKGEN_DOM_PER_NSEC_PER_LSB          (2U)
#define CKGEN_DOM_PER_PRI_PER_LSB           (4U)
#define CKGEN_DOM_PER_USE_PER_LSB           (6U)
#define CKGEN_DOM_PER_MASK                  (0x3U)

#define CKGEN_DOM_PER_LOCK                  (0x8U)

/* RS register */
#define CKGEN_RS_EN                         (0U)
#define CKGEN_RS_RS_LSB                     (1U)
#define CKGEN_RS_RS_MASK                    (0xFU)
#define CKGEN_RS_LOCK                       (31U)

/* Global Control */
#define CKGEN_GLB_CTL                       (0x204U)
#define CKGEN_GLB_CTL_24M_DIVA_DIS          (0U)
#define CKGEN_GLB_CTL_24M_DIVB_DIS          (1U)
#define CKGEN_GLB_CTL_24M_DIVC_DIS          (2U)
#define CKGEN_GLB_CTL_24M_DIVA_NUM_LSB      (3U)
#define CKGEN_GLB_CTL_24M_DIVA_NUM_MASK     (0x3FFU)
#define CKGEN_GLB_CTL_24M_DIVB_NUM_LSB      (18U)
#define CKGEN_GLB_CTL_24M_DIVB_NUM_MASK     (0x3FFU)
#define CKGEN_GLB_CTL_24M_DIVC_NUM_LSB      (28U)
#define CKGEN_GLB_CTL_24M_DIVC_NUM_MASK     (0xFU)

/* SUP DOM */
#define CKGEN_SUP_DOM                       (0x300U)
#define CKGEN_SUP_DOM_DID_LSB               (0U)
#define CKGEN_SUP_DOM_DID_MASK              (0xFU)
#define CKGEN_SUP_DOM_SEC_EN                (4U)
#define CKGEN_SUP_DOM_PPROT_LSB             (5U)
#define CKGEN_SUP_DOM_PPROT_MASK            (0x3U)
#define CKGEN_SUP_DOM_LOCK                  (31U)

/* CKGEN RES */
#define CKGEN_RES_RS                        (0x400U)
#define CKGEN_RES_RS_SF_RATIO_SEL           (0U)
#define CKGEN_RES_RS_SP_RATIO_SEL           (1U)
#define CKGEN_RES                           (0x404U)

/* IP slice register */
#define CKGEN_IP_RS                         (0x1000U)
#define CKGEN_IP_CTL                        (0x1004U)
#define CKGEN_IP_CTL_SRC_SEL_LSB            (0U)
#define CKGEN_IP_CTL_SRC_SEL_CKIN0_3        (0U)
#define CKGEN_IP_CTL_SRC_SEL_CKIN4          (2U)
#define CKGEN_IP_CTL_SRC_SEL_MASK           (0x7U)
#define CKGEN_IP_CTL_PRE_EN                 (4U)
#define CKGEN_IP_CTL_MAIN_EN                (5U)
#define CKGEN_IP_CTL_DBG_EN                 (6U)
#define CKGEN_IP_CTL_HW_DIS_EN              (7U)
#define CKGEN_IP_CTL_DIV_NUM_LSB            (8U)
#define CKGEN_IP_CTL_DIV_NUM_MASK           (0xFFU)
#define CKGEN_IP_CTL_D0_ACTIVE              (27U)
#define CKGEN_IP_CTL_DIV_CHG_BUSY           (28U)
#define CKGEN_IP_CTL_PRE_EN_STATUS          (29U)
#define CKGEN_IP_CTL_MAIN_EN_STATUS         (30U)
#define CKGEN_IP_CTL_HW_CG_EN_STATUS        (31U)

#define CKGEN_IP_MON_CTL                    (0x1008U)
#define CKGEN_IP_MON_CTL_EN                 (0U)
#define CKGEN_IP_MON_CTL_ACTIVE_DISABLE     (1U)
#define CKGEN_IP_MON_CTL_SRC_SEL            (2U)
#define CKGEN_IP_MON_CTL_SLP_EXP            (3U)
#define CKGEN_IP_MON_CTL_HIB_EXP            (4U)
#define CKGEN_IP_MON_CTL_FREQ_UPD           (8U)
#define CKGEN_IP_MON_CTL_EN_STA             (9U)
#define CKGEN_IP_MON_CTL_FREQ_LSB           (16U)
#define CKGEN_IP_MON_CTL_FREQ_MASK          (0xFFFFU)

#define CKGEN_IP_MON_THRD                   (0x100CU)
#define CKGEN_IP_MON_THRD_LOW_LSB           (0U)
#define CKGEN_IP_MON_THRD_LOW_MASK          (0xFFFFU)
#define CKGEN_IP_MON_THRD_HIGH_LSB          (16U)
#define CKGEN_IP_MON_THRD_HIGH_MASK         (0xFFFFU)

/* BUS slice register */
#define CKGEN_BUS_RS                        (0x2000U)
#define CKGEN_BUS_CTL                       (0x2004U)
#define CKGEN_BUS_CTL_SRC_SEL_LSB           (0U)
#define CKGEN_BUS_CTL_SRC_SEL_CKIN0_3       (0U)
#define CKGEN_BUS_CTL_SRC_SEL_CKIN4         (2U)
#define CKGEN_BUS_CTL_SRC_SEL_CKOUT         (3U)
#define CKGEN_BUS_CTL_SRC_SEL_MASK          (0xFU)
#define CKGEN_BUS_CTL_PRE_EN                (4U)
#define CKGEN_BUS_CTL_MAIN_EN               (5U)
#define CKGEN_BUS_CTL_DBG_EN                (6U)
#define CKGEN_BUS_CTL_HW_DIS_EN             (7U)
#define CKGEN_BUS_CTL_DIV_NUM_LSB           (8U)
#define CKGEN_BUS_CTL_DIV_NUM_MASK          (0x1FU)
#define CKGEN_BUS_CTL_PRE_MUX_D0_ACTIVE     (26U)
#define CKGEN_BUS_CTL_POST_MUX_D0_ACTIVE    (27U)
#define CKGEN_BUS_CTL_DIV_CHG_BUSY          (28U)
#define CKGEN_BUS_CTL_PRE_EN_STATUS         (29U)
#define CKGEN_BUS_CTL_MAIN_EN_STATUS        (30U)
#define CKGEN_BUS_CTL_HW_CG_EN_STATUS       (31U)

#define CKGEN_BUS_SYNC_CTL                  (0x2008U)
#define CKGEN_BUS_SYNC_CTL_DIV_M_LSB        (0U)
#define CKGEN_BUS_SYNC_CTL_DIV_N_LSB        (4U)
#define CKGEN_BUS_SYNC_CTL_DIV_P_LSB        (8U)
#define CKGEN_BUS_SYNC_CTL_DIV_Q_LSB        (12U)
#define CKGEN_BUS_SYNC_CTL_DIV_MASK         (0xFU)
#define CKGEN_BUS_SYNC_CTL_DIV_CHG_BUSY_LSB (28U)
#define CKGEN_BUS_SYNC_CTL_DIV_CHG_BUSY_N_LSB (29U)
#define CKGEN_BUS_SYNC_CTL_DIV_CHG_BUSY_P_LSB (30U)
#define CKGEN_BUS_SYNC_CTL_DIV_CHG_BUSY_Q_LSB (31U)

#define CKGEN_BUS_MON_CTL0                  (0x200CU)
#define CKGEN_BUS_MON_CTL0_EN               (0U)
#define CKGEN_BUS_MON_CTL0_ACTIVE_DISABLE   (1U)
#define CKGEN_BUS_MON_CTL0_SRC_SEL          (2U)
#define CKGEN_BUS_MON_CTL0_SLP_EXP          (3U)
#define CKGEN_BUS_MON_CTL0_HIB_EXP          (4U)
#define CKGEN_BUS_MON_CTL0_EN_STA           (5U)
#define CKGEN_BUS_MON_CTL0_FREQ_UPD(m)      (8U + (m))

#define CKGEN_BUS_MON_CTL1                  (0x2010U)
#define CKGEN_BUS_MON_CTL1_FREQ0_LSB        (0U)
#define CKGEN_BUS_MON_CTL1_FREQ1_LSB        (16U)

#define CKGEN_BUS_MON_CTL2                  (0x2014U)
#define CKGEN_BUS_MON_CTL2_FREQ2_LSB        (0U)
#define CKGEN_BUS_MON_CTL2_FREQ3_LSB        (16U)
#define CKGEN_BUS_MON_CTL_FREQ_MASK         (0xFFFFU)

#define CKGEN_BUS_MON_THRD0                 (0x2018U)
#define CKGEN_BUS_MON_THRD1                 (0x201CU)
#define CKGEN_BUS_MON_THRD2                 (0x2020U)
#define CKGEN_BUS_MON_THRD3                 (0x2024U)
#define CKGEN_BUS_MON_THRD_LOW_LSB          (0U)
#define CKGEN_BUS_MON_THRD_HIGH_LSB         (16U)
#define CKGEN_BUS_MON_THRD_MASK             (0xFFFFU)

/* CORE slice register */
#define CKGEN_CORE_RS                       (0x3000U)
#define CKGEN_CORE_CTL                      (0x3004U)
#define CKGEN_CORE_CTL_SRC_SEL_LSB          (0U)
#define CKGEN_CORE_CTL_SRC_SEL_CKIN0_3      (0U)
#define CKGEN_CORE_CTL_SRC_SEL_CKIN4        (2U)
#define CKGEN_CORE_CTL_SRC_SEL_MASK         (0x7U)
#define CKGEN_CORE_CTL_PRE_EN               (4U)
#define CKGEN_CORE_CTL_MAIN_EN              (5U)
#define CKGEN_CORE_CTL_DBG_EN               (6U)
#define CKGEN_CORE_CTL_HW_DIS_EN            (7U)
#define CKGEN_CORE_CTL_DIV_NUM_LSB          (8U)
#define CKGEN_CORE_CTL_DIV_NUM_MASK         (0x1FU)
#define CKGEN_CORE_CTL_D0_ACTIVE            (27U)
#define CKGEN_CORE_CTL_DIV_CHG_BUSY         (28U)
#define CKGEN_CORE_CTL_PRE_EN_STATUS        (29U)
#define CKGEN_CORE_CTL_MAIN_EN_STATUS       (30U)
#define CKGEN_CORE_CTL_HW_CG_EN_STATUS      (31U)

#define CKGEN_CORE_MON_CTL                  (0x3008U)
#define CKGEN_CORE_MON_CTL_EN               (0U)
#define CKGEN_CORE_MON_CTL_ACTIVE_DISABLE   (1U)
#define CKGEN_CORE_MON_CTL_SRC_SEL          (2U)
#define CKGEN_CORE_MON_CTL_SLP_EXP          (3U)
#define CKGEN_CORE_MON_CTL_HIB_EXP          (4U)
#define CKGEN_CORE_MON_CTL_FREQ_UPD         (8U)
#define CKGEN_CORE_MON_CTL_EN_STA           (9U)
#define CKGEN_CORE_MON_CTL_FREQ_LSB         (16U)
#define CKGEN_CORE_MON_CTL_FREQ_MASK        (0xFFFFU)

#define CKGEN_CORE_MON_THRD                 (0x300cu)
#define CKGEN_CORE_MON_THRD_LOW_LSB         (0U)
#define CKGEN_CORE_MON_THRD_LOW_MASK        (0xFFFFU)
#define CKGEN_CORE_MON_THRD_HIGH_LSB        (16U)
#define CKGEN_CORE_MON_THRD_HIGH_MASK       (0xFFFFU)

/* XCG register */
#define CKGEN_PCG_RS                        (0x4000U)
#define CKGEN_PCG_CTL                       (0x4004U)
#define CKGEN_BCG_RS                        (0x5000U)
#define CKGEN_BCG_CTL                       (0x5004U)
#define CKGEN_CCG_RS                        (0x6000U)
#define CKGEN_CCG_CTL                       (0x6004U)
#define CKGEN_XCG_RS(m)                     (CKGEN_PCG_RS + ((m) * 0x1000U))
#define CKGEN_XCG_CTL(m)                    (CKGEN_PCG_CTL + ((m) * 0x1000U))

#define CKGEN_CG_CTL_RUN_MODE               (0U)
#define CKGEN_CG_CTL_HIB_MODE               (1U)
#define CKGEN_CG_CTL_SLP_MODE               (2U)
#define CKGEN_CG_CTL_ACTIVE_MON_EN          (3U)
#define CKGEN_CG_CTL_ACTIVE_MON_STA         (4U)
#define CKGEN_CG_CTL_CG_GATED               (5U)
#define CKGEN_CG_CTL_DBG_EN                 (6U)
#define CKGEN_CG_CTL_LP_MASK                (8U)

#define CKGEN_PLL_RS                        (0x7000U)
#define CKGEN_PLL_CTL                       (0x7004U)
#define CKGEN_PLL_CTL_RUN_MODE              (0U)
#define CKGEN_PLL_CTL_HIB_MODE              (1U)
#define CKGEN_PLL_CTL_SLP_MODE              (2U)
#define CKGEN_PLL_CTL_IGNORE                (3U)
#define CKGEN_PLL_PD_RUN_MODE               (4U)
#define CKGEN_PLL_PD_HIB_MODE               (5U)
#define CKGEN_PLL_PD_SLP_MODE               (6U)

#define CKGEN_PLL_MON_CTL                   (0x7008U)
#define CKGEN_PLL_MON_CTL_EN                (0U)
#define CKGEN_PLL_MON_CTL_TOUT_VAL_LSB      (8U)
#define CKGEN_PLL_MON_CTL_TOUT_VAL_MASK     (0xFFFFU)
#define CKGEN_PLL_MON_CTL_CLK_READY         (31U)

#define CKGEN_XTAL_RS                       (0x7500U)
#define CKGEN_XTAL_CTL                      (0x7504U)
#define CKGEN_XTAL_CTL_RUN_MODE             (0U)
#define CKGEN_XTAL_CTL_HIB_MODE             (1U)
#define CKGEN_XTAL_CTL_SLP_MODE             (2U)
#define CKGEN_XTAL_CTL_IGNORE               (3U)

#define CKGEN_XTAL_MON_CTL                  (0x7508U)
#define CKGEN_XTAL_MON_CTL_EN               (0U)
#define CKGEN_XTAL_MON_CTL_EN_STA           (1U)
#define CKGEN_XTAL_MON_CTL_TOUT_VAL_LSB     (8U)
#define CKGEN_XTAL_MON_CTL_TOUT_VAL_MASK    (0xFFFFU)
#define CKGEN_XTAL_MON_CTL_RC24M_READY      (28U)
#define CKGEN_XTAL_MON_CTL_XTAL_READY       (29U)
#define CKGEN_XTAL_MON_CTL_RC24M_ACTIVE     (30U)
#define CKGEN_XTAL_MON_CTL_XTAL_ACTIVE      (31U)

#define CKGEN_DBG_MON_RS                    (0x8000U)

#define CKGEN_DBG_MON_CLK_SRC               (0x8004U)
#define CKGEN_DBG_MON_CLK_SRC_IP_LSB        (0U)
#define CKGEN_DBG_MON_CLK_SRC_BUS_LSB       (8U)
#define CKGEN_DBG_MON_CLK_SRC_CORE_LSB      (16U)
#define CKGEN_DBG_MON_CLK_SRC_EXT_LSB       (31U)
#define CKGEN_DBG_MON_CLK_SRC_LSB(src)      ((src) * 8U)
#define CKGEN_DBG_MON_CLK_SRC_MASK          (0xFFU)

#define CKGEN_DBG_MON_CTL                   (0x8008U)
#define CKGEN_DBG_MON_CTL_DBG_GATING_EN     (0U)
#define CKGEN_DBG_MON_CTL_MON_GATING_EN     (1U)
#define CKGEN_DBG_MON_CTL_CQM_GATING_EN     (2U)
#define CKGEN_DBG_MON_CTL_CLK_SEL_LSB       (3U)
#define CKGEN_DBG_MON_CTL_CLK_SEL_MASK      (0x3U)

#define CKGEN_DBG_CTL                       (0x800CU)
#define CKGEN_DBG_CTL_DIV_LSB               (0U)
#define CKGEN_DBG_CTL_DIV_MASK              (0xFU)

#define CKGEN_MON_CTL                       (0x8010U)
#define CKGEN_MON_CTL_EN                    (0U)
#define CKGEN_MON_CTL_SRC_SEL               (1U)
#define CKGEN_MON_CTL_ACT_LOSS_DIS          (2U)
#define CKGEN_MON_CTL_FREQ_UPD              (8U)
#define CKGEN_MON_CTL_EN_STA                (9U)
#define CKGEN_MON_CTL_FREQ_LSB              (16U)
#define CKGEN_MON_CTL_FREQ_MASK             (0xFFFFU)

#define CKGEN_MON_CHK_THRD                  (0x8014U)
#define CKGEN_MON_CHK_THRD_LOW_LSB          (0U)
#define CKGEN_MON_CHK_THRD_HIGH_LSB         (16U)
#define CKGEN_MON_CHK_THRD_MASK             (0xFFFFU)

#define CKGEN_LOW_SPD_CHK_CTL               (0x8020U)
#define CKGEN_LOW_SPD_CHK_CTL_LOSS_DIS      (0U)
#define CKGEN_LOW_SPD_CHK_CTL_MON_EN        (1U)
#define CKGEN_LOW_SPD_CHK_CTL_24M_SEL       (2U)
#define CKGEN_LOW_SPD_CHK_CTL_32K_SEL       (8U)
#define CKGEN_LOW_SPD_CHK_CTL_MON_UPD       (14U)
#define CKGEN_LOW_SPD_CHK_CTL_MON_EN_STA    (15U)
#define CKGEN_LOW_SPD_CHK_CTL_FREQ_MON_LSB  (16U)
#define CKGEN_LOW_SPD_CHK_CTL_FREQ_MON_MASK (0xFFFFU)

#define CKGEN_LOW_SPD_CHK_THRD              (0x8024U)
#define CKGEN_LOW_SPD_CHK_THRD_LOW_LSB      (0U)
#define CKGEN_LOW_SPD_CHK_THRD_HIGH_LSB     (16U)
#define CKGEN_LOW_SPD_CHK_THRD_MASK         (0xFFFFU)

#define CKGEN_CQM_CTL                       (0x8040U)
#define CKGEN_CQM_CTL_MON_EN                (0U)
#define CKGEN_CQM_CTL_SRC_SEL_LSB           (1U)
#define CKGEN_CQM_CTL_SRC_SEL_MASK          (0x3U)
#define CKGEN_CQM_CTL_JITTER_RATE_LSB       (3U)
#define CKGEN_CQM_CTL_JITTER_RATE_MASK      (0x3FU)
#define CKGEN_CQM_CTL_DUTY_RATE_LSB         (9U)
#define CKGEN_CQM_CTL_DUTY_RATE_MASK        (0x3FU)

#define CKGEN_IP_CLK_COR_EN                 (0xA300U)
#define CKGEN_IP_CLK_UNC_EN                 (0xA304U)
#define CKGEN_IP_CLK_INT_STA                (0xA308U)

#define CKGEN_BUS_CLK_COR_EN                (0xA400U)
#define CKGEN_BUS_CLK_UNC_EN                (0xA404U)
#define CKGEN_BUS_CLK_INT_STA               (0xA408U)

#define CKGEN_CORE_CLK_COR_EN               (0xA500U)
#define CKGEN_CORE_CLK_UNC_EN               (0xA504U)
#define CKGEN_CORE_CLK_INT_STA              (0xA508U)

#define CKGEN_PCG_COR_EN                    (0xA600U)
#define CKGEN_XCG_COR_EN(m)                 (CKGEN_PCG_COR_EN + (m) * 0x100U)
#define CKGEN_PCG_UNC_EN                    (0xA604U)
#define CKGEN_XCG_UNC_EN(m)                 (CKGEN_PCG_UNC_EN + (m) * 0x100U)
#define CKGEN_PCG_INT_STA                   (0xA608U)
#define CKGEN_XCG_INT_STA(m)                (CKGEN_PCG_INT_STA + (m) * 0x100U)

#define CKGEN_PLL_UNC_EN                    (0xA904U)
#define CKGEN_PLL_INT_STA                   (0xA908U)

#define CKGEN_XTAL_UNC_EN                   (0xAA04U)
#define CKGEN_XTAL_INT_STA                  (0xAA08U)

#define CKGEN_MON_COR_EN                    (0xAB00U)
#define CKGEN_MON_UNC_EN                    (0xAB04U)
#define CKGEN_MON_INT_STA                   (0xAB08U)

#define CKGEN_LOW_SPD_COR_EN                (0xAC00U)
#define CKGEN_LOW_SPD_UNC_EN                (0xAC04U)
#define CKGEN_LOW_SPD_INT_STA               (0xAC08U)

#define CKGEN_CQM_COR_EN                    (0xAD00U)
#define CKGEN_CQM_UNC_EN                    (0xAD04U)
#define CKGEN_CQM_DUTY_INT_STA              (0xAD08U)
#define CKGEN_CQM_JITTER_INT_STA            (0xAD0CU)

#define CKGEN_FUNC_INT_RS                   (0xB000U)
#define CKGEN_FUNC_INT                      (0xB004U)
#define CKGEN_FUNC_INT_ACCESS_ERR_EN        (0U)
#define CKGEN_FUNC_INT_ACCESS_ERR_STA       (8U)
#define CKGEN_FUNC_INT_ACCESS_ERR_CLR       (16U)

/* BUS index */
#define CKGEN_BUS_ID_TYPE_ROOT              (0U)
#define CKGEN_BUS_ID_TYPE_DIV_ROOT          (1U)
#define CKGEN_BUS_ID_TYPE_DIV_M             (2U)
#define CKGEN_BUS_ID_TYPE_DIV_N             (3U)
#define CKGEN_BUS_ID_TYPE_DIV_P             (4U)
#define CKGEN_BUS_ID_TYPE_DIV_Q             (5U)
#define CKGEN_BUS_ID_TYPE_DIV_SF            (6U)
#define CKGEN_BUS_ID_TYPE_DIV_SP            (7U)
#define CKGEN_BUS_ID_TYPE_LSB               (24U)
#define CKGEN_BUS_ID_TYPE_MASK              (0xFFU)
#define CKGEN_BUS_ID_NUM_LSB                (0U)
#define CKGEN_BUS_ID_NUM_MASK               (0xFFFFU)

/* CG type */
#define CKGEN_CG_ID_TYPE_PCG_TYPE           (0U)
#define CKGEN_CG_ID_TYPE_BCG_TYPE           (1U)
#define CKGEN_CG_ID_TYPE_CCG_TYPE           (2U)
#define CKGEN_CG_ID_TYPE_PLL_TYPE           (3U)
#define CKGEN_CG_ID_TYPE_XTAL_TYPE          (4U)
#define CKGEN_CG_ID_TYPE_LSB                (24U)
#define CKGEN_CG_ID_TYPE_MASK               (0xFFU)
#define CKGEN_CG_ID_NUM_LSB                 (0U)
#define CKGEN_CG_ID_NUM_MASK                (0xFFFFU)


/* Ckgen sleep mode */
#define CKGEN_RUN_MODE                      (0U)
#define CKGEN_HIB_MODE                      (1U)
#define CKGEN_SLP_MODE                      (2U)
#define CKGEN_PD_RUN_MODE                   (4U)
#define CKGEN_PD_HIB_MODE                   (5U)
#define CKGEN_PD_SLP_MODE                   (6U)

#define CKGEN_CG_STATE(r, h, s) \
((r << CKGEN_RUN_MODE) | (h << CKGEN_HIB_MODE) | (s << CKGEN_SLP_MODE))

#define CKGEN_CG_DISABLE                    (0U)
#define CKGEN_CG_ENABLE                     (1U)

#define CKGEN_SAF                           (0U)
#define CKGEN_AP                            (1U)

#define CKGEN_MON_DIVA                      (0U)
#define CKGEN_MON_DIVB                      (1U)
#define CKGEN_MON_DIVC                      (2U)

#define CKGEN_IP_CK_IN4_SEL(sel)            ((sel) & (1U << 2))

#define CKGEN_BUS_ID_TYPE(id)               ((id) >> CKGEN_BUS_ID_TYPE_LSB)

#define CKGEN_CG_ID_TYPE(id)                ((id) >> CKGEN_CG_ID_TYPE_LSB)

#define CKGEN_DOM_PER_DOMAIN_OFF(did)       ((did)*8U)

#define CKGEN_DOM_PER_LOCK_OFF(did)         (did)

#define CKGEN_DOM_PER_BASE(base, rsId) \
    ((base) + (CKGEN_DOM_PER + ((rsId)*12U)))

#define CKGEN_DOM_PER_LOCK_BASE(base, rsId) \
    ((base) + (CKGEN_DOM_PER_LOCK + ((rsId)*12U)))

#define CKGEN_GLB_CTL_BASE(base) \
    ((base) + CKGEN_GLB_CTL)

#define CKGEN_IP_RS_BASE(base, id) \
    ((base) + (CKGEN_IP_RS + ((id)*16U)))

#define CKGEN_IP_CTL_BASE(base, id) \
    ((base) + (CKGEN_IP_CTL + ((id)*16U)))

#define CKGEN_IP_MON_CTL_BASE(base, id) \
    ((base) + (CKGEN_IP_MON_CTL + ((id)*16U)))

#define CKGEN_IP_MON_THRD_BASE(base, id) \
    ((base) + (CKGEN_IP_MON_THRD + ((id)*16U)))

#define CKGEN_BUS_RS_BASE(base, id) \
    ((base) + (CKGEN_BUS_RS + (((id)&CKGEN_BUS_ID_NUM_MASK)*40U)))

#define CKGEN_BUS_CTL_BASE(base, id) \
    ((base) + (CKGEN_BUS_CTL + (((id)&CKGEN_BUS_ID_NUM_MASK)*40U)))

#define CKGEN_BUS_SYNC_CTL_BASE(base, id) \
    ((base) + (CKGEN_BUS_SYNC_CTL + (((id)&CKGEN_BUS_ID_NUM_MASK)*40U)))

#define CKGEN_BUS_MON_CTL0_BASE(base, id) \
    ((base) + (CKGEN_BUS_MON_CTL0 + (((id)&CKGEN_BUS_ID_NUM_MASK)*40U)))

#define CKGEN_BUS_MON_CTL1_BASE(base, id) \
    ((base) + (CKGEN_BUS_MON_CTL1 + (((id)&CKGEN_BUS_ID_NUM_MASK)*40U)))

#define CKGEN_BUS_MON_CTL2_BASE(base, id) \
    ((base) + (CKGEN_BUS_MON_CTL2 + (((id)&CKGEN_BUS_ID_NUM_MASK)*40U)))

#define CKGEN_BUS_MON_THRD0_BASE(base, id) \
    ((base) + (CKGEN_BUS_MON_THRD0 + (((id)&CKGEN_BUS_ID_NUM_MASK)*40U)))

#define CKGEN_BUS_MON_THRD1_BASE(base, id) \
    ((base) + (CKGEN_BUS_MON_THRD1 + (((id)&CKGEN_BUS_ID_NUM_MASK)*40U)))

#define CKGEN_BUS_MON_THRD2_BASE(base, id) \
    ((base) + (CKGEN_BUS_MON_THRD2 + (((id)&CKGEN_BUS_ID_NUM_MASK)*40U)))

#define CKGEN_BUS_MON_THRD3_BASE(base, id) \
    ((base) + (CKGEN_BUS_MON_THRD3 + (((id)&CKGEN_BUS_ID_NUM_MASK)*40U)))

#define CKGEN_CORE_RS_BASE(base, id) \
    ((base) + (CKGEN_CORE_RS + ((id)*16U)))

#define CKGEN_CORE_CTL_BASE(base, id) \
    ((base) + (CKGEN_CORE_CTL + ((id)*16U)))

#define CKGEN_CORE_MON_CTL_BASE(base, id) \
    ((base) + (CKGEN_CORE_MON_CTL + ((id)*16U)))

#define CKGEN_CORE_MON_THRD_BASE(base, id) \
    ((base) + (CKGEN_CORE_MON_THRD + ((id)*16U)))

#define CKGEN_XCG_RS_BASE(base, id, m) \
    ((base) + (CKGEN_XCG_RS(m) + (((id)&CKGEN_CG_ID_NUM_MASK)*8U)))

#define CKGEN_XCG_CTL_BASE(base, id, m) \
    ((base) + (CKGEN_XCG_CTL(m) + (((id)&CKGEN_CG_ID_NUM_MASK)*8U)))

#define CKGEN_PLL_CTL_BASE(base, id) \
    ((base) + (CKGEN_PLL_CTL + ((id)*12U)))

#define CKGEN_PLL_MON_CTL_BASE(base, id) \
    ((base) + (CKGEN_PLL_MON_CTL + ((id)*12U)))

#define CKGEN_IP_CLK_COR_EN_BASE(base, id) \
    ((base) + (CKGEN_IP_CLK_COR_EN + ((id)*12U)))

#define CKGEN_IP_CLK_UNC_EN_BASE(base, id) \
    ((base) + (CKGEN_IP_CLK_UNC_EN + ((id)*12U)))

#define CKGEN_IP_CLK_INT_STA_BASE(base, id) \
    ((base) + (CKGEN_IP_CLK_INT_STA + ((id)*12U)))

#define CKGEN_BUS_CLK_COR_EN_BASE(base, id) \
    ((base) + (CKGEN_BUS_CLK_COR_EN + ((id)*12U)))

#define CKGEN_BUS_CLK_UNC_EN_BASE(base, id) \
    ((base) + (CKGEN_BUS_CLK_UNC_EN + ((id)*12U)))

#define CKGEN_BUS_CLK_INT_STA_BASE(base, id) \
    ((base) + (CKGEN_BUS_CLK_INT_STA + ((id)*12U)))

#define CKGEN_CORE_CLK_COR_EN_BASE(base, id) \
    ((base) + (CKGEN_CORE_CLK_COR_EN + ((id)*12U)))

#define CKGEN_CORE_CLK_UNC_EN_BASE(base, id) \
    ((base) + (CKGEN_CORE_CLK_UNC_EN + ((id)*12U)))

#define CKGEN_CORE_CLK_INT_STA_BASE(base, id) \
    ((base) + (CKGEN_CORE_CLK_INT_STA + ((id)*12U)))

#define CKGEN_XCG_COR_EN_BASE(base, id, m) \
    ((base) + (CKGEN_XCG_COR_EN(m) + ((id)*12U)))

#define CKGEN_XCG_UNC_EN_BASE(base, id, m) \
    ((base) + (CKGEN_XCG_UNC_EN(m) + ((id)*12U)))

#define CKGEN_XCG_INT_STA_BASE(base, id, m) \
    ((base) + (CKGEN_XCG_INT_STA(m) + ((id)*12U)))

#define CKGEN_CQM_CTL_BASE(base, id) \
    ((base) + (CKGEN_CQM_CTL + ((id)*4U)))

#define CKGEN_PCG_ID(id) \
    ((CKGEN_CG_ID_TYPE_PCG_TYPE << CKGEN_CG_ID_TYPE_LSB) + (id))

#define CKGEN_BCG_ID(id) \
    ((CKGEN_CG_ID_TYPE_BCG_TYPE << CKGEN_CG_ID_TYPE_LSB) + (id))

#define CKGEN_CCG_ID(id) \
    ((CKGEN_CG_ID_TYPE_CCG_TYPE << CKGEN_CG_ID_TYPE_LSB) + (id))

#define CKGEN_BUS_ROOT_ID(id) \
    ((CKGEN_BUS_ID_TYPE_ROOT << CKGEN_BUS_ID_TYPE_LSB) + (id))

#define CKGEN_BUS_DIV_ROOT_ID(id) \
    ((CKGEN_BUS_ID_TYPE_DIV_ROOT << CKGEN_BUS_ID_TYPE_LSB) + (id))

#define CKGEN_BUS_DIV_M_ID(id) \
    ((CKGEN_BUS_ID_TYPE_DIV_M << CKGEN_BUS_ID_TYPE_LSB) + (id))

#define CKGEN_BUS_DIV_N_ID(id) \
    ((CKGEN_BUS_ID_TYPE_DIV_N << CKGEN_BUS_ID_TYPE_LSB) + (id))

#define CKGEN_BUS_DIV_P_ID(id) \
    ((CKGEN_BUS_ID_TYPE_DIV_P << CKGEN_BUS_ID_TYPE_LSB) + (id))

#define CKGEN_BUS_DIV_Q_ID(id) \
    ((CKGEN_BUS_ID_TYPE_DIV_Q << CKGEN_BUS_ID_TYPE_LSB) + (id))

#define CKGEN_BUS_DIV_SF_ID(id) \
    ((CKGEN_BUS_ID_TYPE_DIV_SF << CKGEN_BUS_ID_TYPE_LSB) + (id))

#define CKGEN_BUS_DIV_SP_ID(id) \
    ((CKGEN_BUS_ID_TYPE_DIV_SP << CKGEN_BUS_ID_TYPE_LSB) + (id))

#define CKGEN_PERMISSION(u, p, s, n) \
    ((((u) & CKGEN_DOM_PER_MASK) << CKGEN_DOM_PER_USE_PER_LSB) | \
    (((p) & CKGEN_DOM_PER_MASK) << CKGEN_DOM_PER_PRI_PER_LSB) | \
    (((n) & CKGEN_DOM_PER_MASK) << CKGEN_DOM_PER_NSEC_PER_LSB) | \
    (((s) & CKGEN_DOM_PER_MASK) << CKGEN_DOM_PER_SEC_PER_LSB))

#define CKGEN_WAIT_TIME                     (500000U)

#define EXT_XTAL_FREQ   (24000000U)
#define LOW_32K_FREQ    (32000U)
/********************************************************************************************************
 *                                  Global Types definition                                             *
 *******************************************************************************************************/

typedef enum
{
    MCU_IP_SLICE   =   0U,
    MCU_CORE_SLICE =   1U,
    MCU_BUS_SLICE  =   2U,
    MCU_XTAL_24M   =   3U,
    MCU_MAX_TYPE   =   4U,
} Mcu_ClkSliceType;

typedef enum
{
    MCU_SF_DOMAIN =   0U,
    MCU_AP_DOMAIN =   1U,
    MCU_MAX_DOMAIN =  2U,
} Mcu_ClkDomainType;

typedef enum
{
    MCU_CQM_CKGEN          = 0U,
    MCU_CQM_SF             = 1U,
    MCU_CQM_SP0            = 2U,
    MCU_CQM_SP1            = 3U,
    MCU_CQM_SX0            = 4U,
    MCU_CQM_SX1            = 5U,
    MCU_CQM_BUS            = 6U,
} Mcu_CqmType;

typedef uint32 Mcu_CkgenRateType;
typedef struct
{
    Mcu_ClkDomainType domainType;
    Mcu_ClkSliceType sliceType;
    uint32  typeIndex;
    uint32 sliceFreq;
    uint8  freqTolerantRat;
    uint8  monIntRes;
    uint32 realFreq;
} Mcu_CkgenMonFreqType;

typedef struct
{
    Mcu_CqmType cqmType;
    Mcu_ClkSliceType sliceType;
    uint32 typeIndex;
    uint8 dutyPercent;
    uint8 jitterPercent;
    uint8 dutyIntRes;
    uint8 jitterIntRes;
} Mcu_CkgenCqmType;

/********************************************************************************************************
 *                                  Global FUnction Declarations                                        *
 *******************************************************************************************************/
Std_ReturnType Mcu_Ip_CkgenIpSetRate(uint32 base, uint32 id, uint8 mux, Mcu_CkgenRateType srcRate,
                                     Mcu_CkgenRateType rate);

Mcu_CkgenRateType Mcu_Ip_CkgenIpGetRate(uint32 base, uint32 id, Mcu_CkgenRateType srcRate);

Std_ReturnType Mcu_Ip_CkgenBusSetRate(uint32 base, uint32 id, uint8 mux,
                                      Mcu_CkgenRateType srcRate, Mcu_CkgenRateType rate);

Mcu_CkgenRateType Mcu_Ip_CkgenBusGetRate(uint32 base, uint32 id,
        Mcu_CkgenRateType srcRate);

Std_ReturnType Mcu_Ip_CkgenCoreSetRate(uint32 base, Mcu_ClkNodeType *clkPtr,
                                       Mcu_CkgenRateType rate);

Mcu_CkgenRateType Mcu_Ip_CkgenCoreGetRate(uint32 base, uint32 id,
        Mcu_CkgenRateType srcRate);


Std_ReturnType Mcu_Ip_CkgenXcgSetGatingByMode(uint32 base, uint32 id,
        uint8 lpMode, boolean en);
#ifndef CONFIG_CLK_MONITOR
boolean Mcu_Ip_CkgenXcgIsGated(uint32 base, uint32 id);
#endif
uint32 Mcu_Ip_CkgenGetBestDiv(uint32 srcRef, uint32 freq);

#ifdef CONFIG_CLK_MONITOR
void Mcu_Ip_CkgenDbgMonIpSelect(uint32 base, uint32 id, uint8 divNum);

void Mcu_Ip_CkgenDbgMonBusSelect(uint32 base, uint32 id, uint8 divNum);

void Mcu_Ip_CkgenDbgMonCoreSelect(uint32 base, uint32 id, uint8 divNum);

Mcu_CkgenRateType Mcu_Ip_CkgenIpMonGetRate(uint32 base, uint32 id, Mcu_ClkRateType rate);

Mcu_CkgenRateType Mcu_Ip_CkgenBusMonGetRate(uint32 base, uint32 id);

Mcu_CkgenRateType Mcu_Ip_CkgenCoreMonGetRate(uint32 base, uint32 id);

void Mcu_Ip_CkgenXcgAmonEnable(uint32 base, uint32 id, boolean en);

uint8 Mcu_Ip_CkgenXcgGetAmonState(uint32 base, uint32 id);

uint8 Mcu_Ip_CkgenMonFreq(Mcu_CkgenMonFreqType *ckgenMonFreqPtr);

uint8 Mcu_Ip_CkgenCqm(Mcu_CkgenCqmType *ckgenCqmPtr);

#endif /** #ifdef CONFIG_CLK_MONITOR*/

#endif /* MCU_CKGEN_H */
/* End of file */
