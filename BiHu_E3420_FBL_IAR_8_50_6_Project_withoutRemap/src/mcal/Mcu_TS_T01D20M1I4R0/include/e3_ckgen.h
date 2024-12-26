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

#ifndef E3_CKGEN_H_
#define E3_CKGEN_H_

#include "e3_clk.h"

/* Domain access permission */
#define CKGEN_DOM_PER                       (0x0u)
#define CKGEN_DOM_PER_SEC_PER_LSB           (0u)
#define CKGEN_DOM_PER_NSEC_PER_LSB          (2u)
#define CKGEN_DOM_PER_PRI_PER_LSB           (4u)
#define CKGEN_DOM_PER_USE_PER_LSB           (6u)
#define CKGEN_DOM_PER_MASK                  (0x3u)

#define CKGEN_DOM_PER_LOCK                  (0x8u)

/* RS register */
#define CKGEN_RS_EN                         (0u)
#define CKGEN_RS_RS_LSB                     (1u)
#define CKGEN_RS_RS_MASK                    (0xFu)
#define CKGEN_RS_LOCK                       (31u)

/* Global Control */
#define CKGEN_GLB_CTL                       (0x204u)
#define CKGEN_GLB_CTL_24M_DIVA_DIS          (0u)
#define CKGEN_GLB_CTL_24M_DIVB_DIS          (1u)
#define CKGEN_GLB_CTL_24M_DIVC_DIS          (2u)
#define CKGEN_GLB_CTL_24M_DIVA_NUM_LSB      (3u)
#define CKGEN_GLB_CTL_24M_DIVA_NUM_MASK     (0x3FFu)
#define CKGEN_GLB_CTL_24M_DIVB_NUM_LSB      (18u)
#define CKGEN_GLB_CTL_24M_DIVB_NUM_MASK     (0x3FFu)
#define CKGEN_GLB_CTL_24M_DIVC_NUM_LSB      (28u)
#define CKGEN_GLB_CTL_24M_DIVC_NUM_MASK     (0xFu)

/* SUP DOM */
#define CKGEN_SUP_DOM                       (0x300u)
#define CKGEN_SUP_DOM_DID_LSB               (0u)
#define CKGEN_SUP_DOM_DID_MASK              (0xFu)
#define CKGEN_SUP_DOM_SEC_EN                (4u)
#define CKGEN_SUP_DOM_PPROT_LSB             (5u)
#define CKGEN_SUP_DOM_PPROT_MASK            (0x3u)
#define CKGEN_SUP_DOM_LOCK                  (31u)

/* CKGEN RES */
#define CKGEN_RES_RS                        (0x400u)
#define CKGEN_RES_RS_SF_RATIO_SEL           (0u)
#define CKGEN_RES_RS_SP_RATIO_SEL           (1u)
#define CKGEN_RES                           (0x404u)

/* IP slice register */
#define CKGEN_IP_RS                         (0x1000u)
#define CKGEN_IP_CTL                        (0x1004u)
#define CKGEN_IP_CTL_SRC_SEL_LSB            (0u)
#define CKGEN_IP_CTL_SRC_SEL_CKIN0_3        (0u)
#define CKGEN_IP_CTL_SRC_SEL_CKIN4          (2u)
#define CKGEN_IP_CTL_SRC_SEL_MASK           (0x7u)
#define CKGEN_IP_CTL_PRE_EN                 (4u)
#define CKGEN_IP_CTL_MAIN_EN                (5u)
#define CKGEN_IP_CTL_DBG_EN                 (6u)
#define CKGEN_IP_CTL_HW_DIS_EN              (7u)
#define CKGEN_IP_CTL_DIV_NUM_LSB            (8u)
#define CKGEN_IP_CTL_DIV_NUM_MASK           (0xFFu)
#define CKGEN_IP_CTL_D0_ACTIVE              (27u)
#define CKGEN_IP_CTL_DIV_CHG_BUSY           (28u)
#define CKGEN_IP_CTL_PRE_EN_STATUS          (29u)
#define CKGEN_IP_CTL_MAIN_EN_STATUS         (30u)
#define CKGEN_IP_CTL_HW_CG_EN_STATUS        (31u)

#define CKGEN_IP_MON_CTL                    (0x1008u)
#define CKGEN_IP_MON_CTL_EN                 (0u)
#define CKGEN_IP_MON_CTL_ACTIVE_DISABLE     (1u)
#define CKGEN_IP_MON_CTL_SRC_SEL            (2u)
#define CKGEN_IP_MON_CTL_SLP_EXP            (3u)
#define CKGEN_IP_MON_CTL_HIB_EXP            (4u)
#define CKGEN_IP_MON_CTL_FREQ_UPD           (8u)
#define CKGEN_IP_MON_CTL_EN_STA             (9u)
#define CKGEN_IP_MON_CTL_FREQ_LSB           (16u)
#define CKGEN_IP_MON_CTL_FREQ_MASK          (0xFFFFu)

#define CKGEN_IP_MON_THRD                   (0x100Cu)
#define CKGEN_IP_MON_THRD_LOW_LSB           (0u)
#define CKGEN_IP_MON_THRD_LOW_MASK          (0xFFFFu)
#define CKGEN_IP_MON_THRD_HIGH_LSB          (16u)
#define CKGEN_IP_MON_THRD_HIGH_MASK         (0xFFFFu)

/* BUS slice register */
#define CKGEN_BUS_RS                        (0x2000u)
#define CKGEN_BUS_CTL                       (0x2004u)
#define CKGEN_BUS_CTL_SRC_SEL_LSB           (0u)
#define CKGEN_BUS_CTL_SRC_SEL_CKIN0_3       (0u)
#define CKGEN_BUS_CTL_SRC_SEL_CKIN4         (2u)
#define CKGEN_BUS_CTL_SRC_SEL_CKOUT         (3u)
#define CKGEN_BUS_CTL_SRC_SEL_MASK          (0xFu)
#define CKGEN_BUS_CTL_PRE_EN                (4u)
#define CKGEN_BUS_CTL_MAIN_EN               (5u)
#define CKGEN_BUS_CTL_DBG_EN                (6u)
#define CKGEN_BUS_CTL_HW_DIS_EN             (7u)
#define CKGEN_BUS_CTL_DIV_NUM_LSB           (8u)
#define CKGEN_BUS_CTL_DIV_NUM_MASK          (0x1Fu)
#define CKGEN_BUS_CTL_PRE_MUX_D0_ACTIVE     (26u)
#define CKGEN_BUS_CTL_POST_MUX_D0_ACTIVE    (27u)
#define CKGEN_BUS_CTL_DIV_CHG_BUSY          (28u)
#define CKGEN_BUS_CTL_PRE_EN_STATUS         (29u)
#define CKGEN_BUS_CTL_MAIN_EN_STATUS        (30u)
#define CKGEN_BUS_CTL_HW_CG_EN_STATUS       (31u)

#define CKGEN_BUS_SYNC_CTL                  (0x2008u)
#define CKGEN_BUS_SYNC_CTL_DIV_M_LSB        (0u)
#define CKGEN_BUS_SYNC_CTL_DIV_N_LSB        (4u)
#define CKGEN_BUS_SYNC_CTL_DIV_P_LSB        (8u)
#define CKGEN_BUS_SYNC_CTL_DIV_Q_LSB        (12u)
#define CKGEN_BUS_SYNC_CTL_DIV_MASK         (0xFu)
#define CKGEN_BUS_SYNC_CTL_DIV_CHG_BUSY_LSB (28u)
#define CKGEN_BUS_SYNC_CTL_DIV_CHG_BUSY_N_LSB (29u)
#define CKGEN_BUS_SYNC_CTL_DIV_CHG_BUSY_P_LSB (30u)

#define CKGEN_BUS_MON_CTL0                  (0x200Cu)
#define CKGEN_BUS_MON_CTL0_EN               (0u)
#define CKGEN_BUS_MON_CTL0_ACTIVE_DISABLE   (1u)
#define CKGEN_BUS_MON_CTL0_SRC_SEL          (2u)
#define CKGEN_BUS_MON_CTL0_SLP_EXP          (3u)
#define CKGEN_BUS_MON_CTL0_HIB_EXP          (4u)
#define CKGEN_BUS_MON_CTL0_EN_STA           (5u)
#define CKGEN_BUS_MON_CTL0_FREQ_UPD(m)      (8u + (m))

#define CKGEN_BUS_MON_CTL1                  (0x2010u)
#define CKGEN_BUS_MON_CTL1_FREQ0_LSB        (0u)
#define CKGEN_BUS_MON_CTL1_FREQ1_LSB        (16u)

#define CKGEN_BUS_MON_CTL2                  (0x2014u)
#define CKGEN_BUS_MON_CTL2_FREQ2_LSB        (0u)
#define CKGEN_BUS_MON_CTL2_FREQ3_LSB        (16u)
#define CKGEN_BUS_MON_CTL_FREQ_MASK         (0xFFFFu)

#define CKGEN_BUS_MON_THRD0                 (0x2018u)
#define CKGEN_BUS_MON_THRD1                 (0x201Cu)
#define CKGEN_BUS_MON_THRD2                 (0x2020u)
#define CKGEN_BUS_MON_THRD3                 (0x2024u)
#define CKGEN_BUS_MON_THRD_LOW_LSB          (0u)
#define CKGEN_BUS_MON_THRD_HIGH_LSB         (16u)
#define CKGEN_BUS_MON_THRD_MASK             (0xFFFFu)

/* CORE slice register */
#define CKGEN_CORE_RS                       (0x3000u)
#define CKGEN_CORE_CTL                      (0x3004u)
#define CKGEN_CORE_CTL_SRC_SEL_LSB          (0u)
#define CKGEN_CORE_CTL_SRC_SEL_CKIN0_3      (0u)
#define CKGEN_CORE_CTL_SRC_SEL_CKIN4        (2u)
#define CKGEN_CORE_CTL_SRC_SEL_MASK         (0x7u)
#define CKGEN_CORE_CTL_PRE_EN               (4u)
#define CKGEN_CORE_CTL_MAIN_EN              (5u)
#define CKGEN_CORE_CTL_DBG_EN               (6u)
#define CKGEN_CORE_CTL_HW_DIS_EN            (7u)
#define CKGEN_CORE_CTL_DIV_NUM_LSB          (8u)
#define CKGEN_CORE_CTL_DIV_NUM_MASK         (0x1Fu)
#define CKGEN_CORE_CTL_D0_ACTIVE            (27u)
#define CKGEN_CORE_CTL_DIV_CHG_BUSY         (28u)
#define CKGEN_CORE_CTL_PRE_EN_STATUS        (29u)
#define CKGEN_CORE_CTL_MAIN_EN_STATUS       (30u)
#define CKGEN_CORE_CTL_HW_CG_EN_STATUS      (31u)

#define CKGEN_CORE_MON_CTL                  (0x3008u)
#define CKGEN_CORE_MON_CTL_EN               (0u)
#define CKGEN_CORE_MON_CTL_ACTIVE_DISABLE   (1u)
#define CKGEN_CORE_MON_CTL_SRC_SEL          (2u)
#define CKGEN_CORE_MON_CTL_SLP_EXP          (3u)
#define CKGEN_CORE_MON_CTL_HIB_EXP          (4u)
#define CKGEN_CORE_MON_CTL_FREQ_UPD         (8u)
#define CKGEN_CORE_MON_CTL_EN_STA           (9u)
#define CKGEN_CORE_MON_CTL_FREQ_LSB         (16u)
#define CKGEN_CORE_MON_CTL_FREQ_MASK        (0xFFFFu)

#define CKGEN_CORE_MON_THRD                 (0x300cu)
#define CKGEN_CORE_MON_THRD_LOW_LSB         (0u)
#define CKGEN_CORE_MON_THRD_LOW_MASK        (0xFFFFu)
#define CKGEN_CORE_MON_THRD_HIGH_LSB        (16u)
#define CKGEN_CORE_MON_THRD_HIGH_MASK       (0xFFFFu)

/* XCG register */
#define CKGEN_PCG_RS                        (0x4000u)
#define CKGEN_PCG_CTL                       (0x4004u)
#define CKGEN_BCG_RS                        (0x5000u)
#define CKGEN_BCG_CTL                       (0x5004u)
#define CKGEN_CCG_RS                        (0x6000u)
#define CKGEN_CCG_CTL                       (0x6004u)
#define CKGEN_XCG_RS(m)                     (CKGEN_PCG_RS + (m) * 0x1000u)
#define CKGEN_XCG_CTL(m)                    (CKGEN_PCG_CTL + (m) * 0x1000u)

#define CKGEN_CG_CTL_RUN_MODE               (0u)
#define CKGEN_CG_CTL_HIB_MODE               (1u)
#define CKGEN_CG_CTL_SLP_MODE               (2u)
#define CKGEN_CG_CTL_ACTIVE_MON_EN          (3u)
#define CKGEN_CG_CTL_ACTIVE_MON_STA         (4u)
#define CKGEN_CG_CTL_CG_GATED               (5u)
#define CKGEN_CG_CTL_DBG_EN                 (6u)
#define CKGEN_CG_CTL_LP_MASK                (8u)

#define CKGEN_PLL_RS                        (0x7000u)
#define CKGEN_PLL_CTL                       (0x7004u)
#define CKGEN_PLL_CTL_RUN_MODE              (0u)
#define CKGEN_PLL_CTL_HIB_MODE              (1u)
#define CKGEN_PLL_CTL_SLP_MODE              (2u)
#define CKGEN_PLL_CTL_IGNORE                (3u)
#define CKGEN_PLL_PD_RUN_MODE               (4u)
#define CKGEN_PLL_PD_HIB_MODE               (5u)
#define CKGEN_PLL_PD_SLP_MODE               (6u)

#define CKGEN_PLL_MON_CTL                   (0x7008u)
#define CKGEN_PLL_MON_CTL_EN                (0u)
#define CKGEN_PLL_MON_CTL_TOUT_VAL_LSB      (8u)
#define CKGEN_PLL_MON_CTL_TOUT_VAL_MASK     (0xFFFFu)
#define CKGEN_PLL_MON_CTL_CLK_READY         (31u)

#define CKGEN_XTAL_RS                       (0x7500u)
#define CKGEN_XTAL_CTL                      (0x7504u)
#define CKGEN_XTAL_CTL_RUN_MODE             (0u)
#define CKGEN_XTAL_CTL_HIB_MODE             (1u)
#define CKGEN_XTAL_CTL_SLP_MODE             (2u)
#define CKGEN_XTAL_CTL_IGNORE               (3u)

#define CKGEN_XTAL_MON_CTL                  (0x7508u)
#define CKGEN_XTAL_MON_CTL_EN               (0u)
#define CKGEN_XTAL_MON_CTL_EN_STA           (1u)
#define CKGEN_XTAL_MON_CTL_TOUT_VAL_LSB     (8u)
#define CKGEN_XTAL_MON_CTL_TOUT_VAL_MASK    (0xFFFFu)
#define CKGEN_XTAL_MON_CTL_RC24M_READY      (28u)
#define CKGEN_XTAL_MON_CTL_XTAL_READY       (29u)
#define CKGEN_XTAL_MON_CTL_RC24M_ACTIVE     (30u)
#define CKGEN_XTAL_MON_CTL_XTAL_ACTIVE      (31u)

#define CKGEN_DBG_MON_RS                    (0x8000u)

#define CKGEN_DBG_MON_CLK_SRC               (0x8004u)
#define CKGEN_DBG_MON_CLK_SRC_IP_LSB        (0u)
#define CKGEN_DBG_MON_CLK_SRC_BUS_LSB       (8u)
#define CKGEN_DBG_MON_CLK_SRC_CORE_LSB      (16u)
#define CKGEN_DBG_MON_CLK_SRC_EXT_LSB       (31u)
#define CKGEN_DBG_MON_CLK_SRC_LSB(src)      ((src) * 8u)
#define CKGEN_DBG_MON_CLK_SRC_MASK          (0xFFu)

#define CKGEN_DBG_MON_CTL                   (0x8008u)
#define CKGEN_DBG_MON_CTL_DBG_GATING_EN     (0u)
#define CKGEN_DBG_MON_CTL_MON_GATING_EN     (1u)
#define CKGEN_DBG_MON_CTL_CQM_GATING_EN     (2u)
#define CKGEN_DBG_MON_CTL_CLK_SEL_LSB       (3u)
#define CKGEN_DBG_MON_CTL_CLK_SEL_MASK      (0x3u)

#define CKGEN_DBG_CTL                       (0x800Cu)
#define CKGEN_DBG_CTL_DIV_LSB               (0u)
#define CKGEN_DBG_CTL_DIV_MASK              (0xFu)

#define CKGEN_MON_CTL                       (0x8010u)
#define CKGEN_MON_CTL_EN                    (0u)
#define CKGEN_MON_CTL_SRC_SEL               (1u)
#define CKGEN_MON_CTL_ACT_LOSS_DIS          (2u)
#define CKGEN_MON_CTL_FREQ_UPD              (8u)
#define CKGEN_MON_CTL_EN_STA                (9u)
#define CKGEN_MON_CTL_FREQ_LSB              (16u)
#define CKGEN_MON_CTL_FREQ_MASK             (0xFFFFu)

#define CKGEN_MON_CHK_THRD                  (0x8014u)
#define CKGEN_MON_CHK_THRD_LOW_LSB          (0u)
#define CKGEN_MON_CHK_THRD_HIGH_LSB         (16u)
#define CKGEN_MON_CHK_THRD_MASK             (0xFFFFu)

#define CKGEN_LOW_SPD_CHK_CTL               (0x8020u)
#define CKGEN_LOW_SPD_CHK_CTL_LOSS_DIS      (0u)
#define CKGEN_LOW_SPD_CHK_CTL_MON_EN        (1u)
#define CKGEN_LOW_SPD_CHK_CTL_24M_SEL       (2u)
#define CKGEN_LOW_SPD_CHK_CTL_32K_SEL       (8u)
#define CKGEN_LOW_SPD_CHK_CTL_MON_UPD       (14u)
#define CKGEN_LOW_SPD_CHK_CTL_MON_EN_STA    (15u)
#define CKGEN_LOW_SPD_CHK_CTL_FREQ_MON_LSB  (16u)
#define CKGEN_LOW_SPD_CHK_CTL_FREQ_MON_MASK (0xFFFFu)

#define CKGEN_LOW_SPD_CHK_THRD              (0x8024u)
#define CKGEN_LOW_SPD_CHK_THRD_LOW_LSB      (0u)
#define CKGEN_LOW_SPD_CHK_THRD_HIGH_LSB     (16u)
#define CKGEN_LOW_SPD_CHK_THRD_MASK         (0xFFFFu)

#define CKGEN_CQM_CTL                       (0x8040u)
#define CKGEN_CQM_CTL_MON_EN                (0u)
#define CKGEN_CQM_CTL_SRC_SEL_LSB           (1u)
#define CKGEN_CQM_CTL_SRC_SEL_MASK          (0x3u)
#define CKGEN_CQM_CTL_JITTER_RATE_LSB       (3u)
#define CKGEN_CQM_CTL_JITTER_RATE_MASK      (0x3Fu)
#define CKGEN_CQM_CTL_DUTY_RATE_LSB         (9u)
#define CKGEN_CQM_CTL_DUTY_RATE_MASK        (0x3Fu)

#define CKGEN_IP_CLK_COR_EN                 (0xA300u)
#define CKGEN_IP_CLK_UNC_EN                 (0xA304u)
#define CKGEN_IP_CLK_INT_STA                (0xA308u)

#define CKGEN_BUS_CLK_COR_EN                (0xA400u)
#define CKGEN_BUS_CLK_UNC_EN                (0xA404u)
#define CKGEN_BUS_CLK_INT_STA               (0xA408u)

#define CKGEN_CORE_CLK_COR_EN               (0xA500u)
#define CKGEN_CORE_CLK_UNC_EN               (0xA504u)
#define CKGEN_CORE_CLK_INT_STA              (0xA508u)

#define CKGEN_PCG_COR_EN                    (0xA600u)
#define CKGEN_XCG_COR_EN(m)                 (CKGEN_PCG_COR_EN + (m) * 0x100u)
#define CKGEN_PCG_UNC_EN                    (0xA604u)
#define CKGEN_XCG_UNC_EN(m)                 (CKGEN_PCG_UNC_EN + (m) * 0x100u)
#define CKGEN_PCG_INT_STA                   (0xA608u)
#define CKGEN_XCG_INT_STA(m)                (CKGEN_PCG_INT_STA + (m) * 0x100u)

#define CKGEN_PLL_UNC_EN                    (0xA904u)
#define CKGEN_PLL_INT_STA                   (0xA908u)

#define CKGEN_XTAL_UNC_EN                   (0xAA04u)
#define CKGEN_XTAL_INT_STA                  (0xAA08u)

#define CKGEN_MON_COR_EN                    (0xAB00u)
#define CKGEN_MON_UNC_EN                    (0xAB04u)
#define CKGEN_MON_INT_STA                   (0xAB08u)

#define CKGEN_LOW_SPD_COR_EN                (0xAC00u)
#define CKGEN_LOW_SPD_UNC_EN                (0xAC04u)
#define CKGEN_LOW_SPD_INT_STA               (0xAC08u)

#define CKGEN_CQM_COR_EN                    (0xAD00u)
#define CKGEN_CQM_UNC_EN                    (0xAD04u)
#define CKGEN_CQM_DUTY_INT_STA              (0xAD08u)
#define CKGEN_CQM_JITTER_INT_STA            (0xAD0Cu)

#define CKGEN_FUNC_INT_RS                   (0xB000u)
#define CKGEN_FUNC_INT                      (0xB004u)
#define CKGEN_FUNC_INT_ACCESS_ERR_EN        (0u)
#define CKGEN_FUNC_INT_ACCESS_ERR_STA       (8u)
#define CKGEN_FUNC_INT_ACCESS_ERR_CLR       (16u)

/* BUS index */
#define CKGEN_BUS_ID_TYPE_ROOT              (0u)
#define CKGEN_BUS_ID_TYPE_DIV_ROOT          (1u)
#define CKGEN_BUS_ID_TYPE_DIV_M             (2u)
#define CKGEN_BUS_ID_TYPE_DIV_N             (3u)
#define CKGEN_BUS_ID_TYPE_DIV_P             (4u)
#define CKGEN_BUS_ID_TYPE_DIV_Q             (5u)
#define CKGEN_BUS_ID_TYPE_DIV_SF            (6u)
#define CKGEN_BUS_ID_TYPE_DIV_SP            (7u)
#define CKGEN_BUS_ID_TYPE_LSB               (24u)
#define CKGEN_BUS_ID_TYPE_MASK              (0xFFu)
#define CKGEN_BUS_ID_NUM_LSB                (0u)
#define CKGEN_BUS_ID_NUM_MASK               (0xFFFFu)

/* CG type */
#define CKGEN_CG_ID_TYPE_PCG_TYPE           (0u)
#define CKGEN_CG_ID_TYPE_BCG_TYPE           (1u)
#define CKGEN_CG_ID_TYPE_CCG_TYPE           (2u)
#define CKGEN_CG_ID_TYPE_PLL_TYPE           (3u)
#define CKGEN_CG_ID_TYPE_XTAL_TYPE          (4u)
#define CKGEN_CG_ID_TYPE_LSB                (24u)
#define CKGEN_CG_ID_TYPE_MASK               (0xFFu)
#define CKGEN_CG_ID_NUM_LSB                 (0u)
#define CKGEN_CG_ID_NUM_MASK                (0xFFFFu)

/* Domain access permission type */
#define CKGEN_DOM_PER_RS_NUM                (8u)
#define CKGEN_DOM_PER_DOMAIN_NUM            (8u)

#define CKGEN_DOM_PER_RW                    (0u)
#define CKGEN_DOM_PER_RO                    (1u)
#define CKGEN_DOM_PER_WO                    (2u)
#define CKGEN_DOM_PER_NONE                  (3u)

/* Ckgen sleep mode */
#define CKGEN_RUN_MODE                      (0u)
#define CKGEN_HIB_MODE                      (1u)
#define CKGEN_SLP_MODE                      (2u)
#define CKGEN_CG_STATE(r, h, s) \
((r << CKGEN_RUN_MODE) | (h << CKGEN_HIB_MODE) | (s << CKGEN_SLP_MODE))

#define CKGEN_CG_DISABLE                    0
#define CKGEN_CG_ENABLE                     1

#define CKGEN_SAF                           0
#define CKGEN_AP                            1

#define CKGEN_MON_DIVA                      0
#define CKGEN_MON_DIVB                      1
#define CKGEN_MON_DIVC                      2

#define CKGEN_IP_CK_IN4_SEL(sel)            ((sel) & (1u << 2))

#define CKGEN_BUS_ID_TYPE(id)               ((id) >> CKGEN_BUS_ID_TYPE_LSB)

#define CKGEN_CG_ID_TYPE(id)                ((id) >> CKGEN_CG_ID_TYPE_LSB)

#define CKGEN_DOM_PER_DOMAIN_OFF(did)       ((did)*8u)

#define CKGEN_DOM_PER_LOCK_OFF(did)         (did)

#define CKGEN_DOM_PER_BASE(base, rs_id) \
    ((base) + (CKGEN_DOM_PER + (rs_id)*12u))

#define CKGEN_DOM_PER_LOCK_BASE(base, rs_id) \
    ((base) + (CKGEN_DOM_PER_LOCK + (rs_id)*12u))

#define CKGEN_GLB_CTL_BASE(base) \
    ((base) + CKGEN_GLB_CTL)

#define CKGEN_IP_RS_BASE(base, id) \
    ((base) + (CKGEN_IP_RS + (id)*16u))

#define CKGEN_IP_CTL_BASE(base, id) \
    ((base) + (CKGEN_IP_CTL + (id)*16u))

#define CKGEN_IP_MON_CTL_BASE(base, id) \
    ((base) + (CKGEN_IP_MON_CTL + (id)*16u))

#define CKGEN_IP_MON_THRD_BASE(base, id) \
    ((base) + (CKGEN_IP_MON_THRD + (id)*16u))

#define CKGEN_BUS_RS_BASE(base, id) \
    ((base) + (CKGEN_BUS_RS + ((id)&CKGEN_BUS_ID_NUM_MASK)*40u))

#define CKGEN_BUS_CTL_BASE(base, id) \
    ((base) + (CKGEN_BUS_CTL + ((id)&CKGEN_BUS_ID_NUM_MASK)*40u))

#define CKGEN_BUS_SYNC_CTL_BASE(base, id) \
    ((base) + (CKGEN_BUS_SYNC_CTL + ((id)&CKGEN_BUS_ID_NUM_MASK)*40u))

#define CKGEN_BUS_MON_CTL0_BASE(base, id) \
    ((base) + (CKGEN_BUS_MON_CTL0 + ((id)&CKGEN_BUS_ID_NUM_MASK)*40u))

#define CKGEN_BUS_MON_CTL1_BASE(base, id) \
    ((base) + (CKGEN_BUS_MON_CTL1 + ((id)&CKGEN_BUS_ID_NUM_MASK)*40u))

#define CKGEN_BUS_MON_CTL2_BASE(base, id) \
    ((base) + (CKGEN_BUS_MON_CTL2 + ((id)&CKGEN_BUS_ID_NUM_MASK)*40u))

#define CKGEN_BUS_MON_THRD0_BASE(base, id) \
    ((base) + (CKGEN_BUS_MON_THRD0 + ((id)&CKGEN_BUS_ID_NUM_MASK)*40u))

#define CKGEN_BUS_MON_THRD1_BASE(base, id) \
    ((base) + (CKGEN_BUS_MON_THRD1 + ((id)&CKGEN_BUS_ID_NUM_MASK)*40u))

#define CKGEN_BUS_MON_THRD2_BASE(base, id) \
    ((base) + (CKGEN_BUS_MON_THRD2 + ((id)&CKGEN_BUS_ID_NUM_MASK)*40u))

#define CKGEN_BUS_MON_THRD3_BASE(base, id) \
    ((base) + (CKGEN_BUS_MON_THRD3 + ((id)&CKGEN_BUS_ID_NUM_MASK)*40u))

#define CKGEN_CORE_RS_BASE(base, id) \
    ((base) + (CKGEN_CORE_RS + (id)*16u))

#define CKGEN_CORE_CTL_BASE(base, id) \
    ((base) + (CKGEN_CORE_CTL + (id)*16u))

#define CKGEN_CORE_MON_CTL_BASE(base, id) \
    ((base) + (CKGEN_CORE_MON_CTL + (id)*16u))

#define CKGEN_CORE_MON_THRD_BASE(base, id) \
    ((base) + (CKGEN_CORE_MON_THRD + (id)*16u))

#define CKGEN_XCG_RS_BASE(base, id, m) \
    ((base) + (CKGEN_XCG_RS(m) + ((id)&CKGEN_CG_ID_NUM_MASK)*8u))

#define CKGEN_XCG_CTL_BASE(base, id, m) \
    ((base) + (CKGEN_XCG_CTL(m) + ((id)&CKGEN_CG_ID_NUM_MASK)*8u))

#define CKGEN_PLL_CTL_BASE(base, id) \
    ((base) + (CKGEN_PLL_CTL + (id)*12u))

#define CKGEN_PLL_MON_CTL_BASE(base, id) \
    ((base) + (CKGEN_PLL_MON_CTL + (id)*12u))

#define CKGEN_IP_CLK_COR_EN_BASE(base, id) \
    ((base) + (CKGEN_IP_CLK_COR_EN + (id)*12u))

#define CKGEN_IP_CLK_UNC_EN_BASE(base, id) \
    ((base) + (CKGEN_IP_CLK_UNC_EN + (id)*12u))

#define CKGEN_IP_CLK_INT_STA_BASE(base, id) \
    ((base) + (CKGEN_IP_CLK_INT_STA + (id)*12u))

#define CKGEN_BUS_CLK_COR_EN_BASE(base, id) \
    ((base) + (CKGEN_BUS_CLK_COR_EN + (id)*12u))

#define CKGEN_BUS_CLK_UNC_EN_BASE(base, id) \
    ((base) + (CKGEN_BUS_CLK_UNC_EN + (id)*12u))

#define CKGEN_BUS_CLK_INT_STA_BASE(base, id) \
    ((base) + (CKGEN_BUS_CLK_INT_STA + (id)*12u))

#define CKGEN_CORE_CLK_COR_EN_BASE(base, id) \
    ((base) + (CKGEN_CORE_CLK_COR_EN + (id)*12u))

#define CKGEN_CORE_CLK_UNC_EN_BASE(base, id) \
    ((base) + (CKGEN_CORE_CLK_UNC_EN + (id)*12u))

#define CKGEN_CORE_CLK_INT_STA_BASE(base, id) \
    ((base) + (CKGEN_CORE_CLK_INT_STA + (id)*12u))

#define CKGEN_XCG_COR_EN_BASE(base, id, m) \
    ((base) + (CKGEN_XCG_COR_EN(m) + (id)*12u))

#define CKGEN_XCG_UNC_EN_BASE(base, id, m) \
    ((base) + (CKGEN_XCG_UNC_EN(m) + (id)*12u))

#define CKGEN_XCG_INT_STA_BASE(base, id, m) \
    ((base) + (CKGEN_XCG_INT_STA(m) + (id)*12u))

#define CKGEN_CQM_CTL_BASE(base, id) \
    ((base) + (CKGEN_CQM_CTL + (id)*4u))

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

#define CKGEN_WAIT_TIME                     500000u

typedef enum ckgen_access_permission {
    CKGEN_ACCESS_RW = 0,
    CKGEN_ACCESS_RO,
    CKGEN_ACCESS_WO,
    CKGEN_ACCESS_NONE,
} ckgen_access_permission_e;

typedef uint32 ckgen_rate_t;

typedef struct ckgen_dom_config {
    uint8 rs;
    uint8 did;
    uint8 lock;
    uint8 permission;
} ckgen_dom_config_t;

typedef struct ckgen_sup_dom_config {
    uint8 did;
    uint8 sec_en;
    uint8 pprot;
    uint8 lock;
} ckgen_sup_dom_config_t;

typedef struct ckgen_rs_config {
    uint8 rs_en;
    uint8 rs;
    uint8 lock;
} ckgen_rs_config_t;
#ifdef MCU_CKGEN_RESERVED_FUNCs
int ckgen_dom_perpare(paddr_t base, ckgen_dom_config_t *config);

int ckgen_sup_dom_perpare(paddr_t base, ckgen_sup_dom_config_t *config);
#endif
void ckgen_rs_config(paddr_t rs_base, ckgen_rs_config_t *config);

int ckgen_ip_set_rate(paddr_t base, uint32 id, uint8 mux,
                      ckgen_rate_t src_rate, ckgen_rate_t rate);

ckgen_rate_t ckgen_ip_get_rate(paddr_t base, uint32 id,
                               ckgen_rate_t src_rate);

void ckgen_ip_rs_config(paddr_t base, uint32 id,
                        ckgen_rs_config_t *config);

int ckgen_bus_set_rate(paddr_t base, uint32 id, uint8 mux,
                       ckgen_rate_t src_rate, ckgen_rate_t rate);

ckgen_rate_t ckgen_bus_get_rate(paddr_t base, uint32 id,
                                ckgen_rate_t src_rate);

void ckgen_bus_rs_config(paddr_t base, uint32 id,
                         ckgen_rs_config_t *config);

int ckgen_core_set_rate(paddr_t base, clk_node_t *clk, ckgen_rate_t rate);

ckgen_rate_t ckgen_core_get_rate(paddr_t base, uint32 id,
                                 ckgen_rate_t src_rate);

void ckgen_core_rs_config(paddr_t base, uint32 id,
                          ckgen_rs_config_t *config);
#ifdef MCU_CKGEN_RESERVED_FUNCs
int ckgen_xcg_set_gating_state(paddr_t base, uint32 id, uint8 cg_state);
#endif
int ckgen_xcg_set_gating_by_mode(paddr_t base, uint32 id,
                                 uint8 lp_mode, bool en);

bool ckgen_xcg_is_gated(paddr_t base, uint32 id);
#ifdef MCU_CKGEN_RESERVED_FUNCs
int ckgen_pll_set_gating_state(paddr_t base, uint32 id, uint8 cg_state);
#endif
int ckgen_pll_set_gating_by_mode(paddr_t base, uint32 id,
                                 uint8 lp_mode, bool en);
#ifdef MCU_CKGEN_RESERVED_FUNCs
int ckgen_xtal_set_gating_state(paddr_t base, uint8 cg_state);
#endif
int ckgen_xtal_set_gating_by_mode(paddr_t base, uint8 lp_mode, bool en);
#ifdef MCU_CKGEN_RESERVED_FUNCs
void ckgen_xcg_lp_mask(paddr_t base, uint32 id);

void ckgen_xcg_lp_unmask(paddr_t base, uint32 id);

void ckgen_xcg_rs_config(paddr_t base, uint32 id,
                         ckgen_rs_config_t *config);

int ckgen_pll_set_pd_state(paddr_t base, uint32 id, uint8 pd_state);

void ckgen_ip_cor_int_enable(paddr_t base, uint32 id, bool en);

void ckgen_ip_unc_int_enable(paddr_t base, uint32 id, bool en);

bool ckgen_ip_get_int_state(paddr_t base, uint32 id);

void ckgen_ip_clear_int_state(paddr_t base, uint32 id);

void ckgen_bus_cor_int_enable(paddr_t base, uint32 id, bool en);

void ckgen_bus_unc_int_enable(paddr_t base, uint32 id, bool en);

bool ckgen_bus_get_int_state(paddr_t base, uint32 id);

void ckgen_bus_clear_int_state(paddr_t base, uint32 id);

void ckgen_core_cor_int_enable(paddr_t base, uint32 id, bool en);

void ckgen_core_unc_int_enable(paddr_t base, uint32 id, bool en);

bool ckgen_core_get_int_state(paddr_t base, uint32 id);

void ckgen_core_clear_int_state(paddr_t base, uint32 id);

void ckgen_xcg_cor_int_enable(paddr_t base, uint32 id, bool en);

void ckgen_xcg_unc_int_enable(paddr_t base, uint32 id, bool en);

bool ckgen_xcg_get_int_state(paddr_t base, uint32 id);

void ckgen_xcg_clear_int_state(paddr_t base, uint32 id);
#endif

uint32 ckgen_get_best_div(uint32 f_ref, uint32 freq);

#ifdef CONFIG_CLK_MONITOR

void ckgen_set_mon_div_num(paddr_t base, uint8 div_type, uint32 div_num);

ckgen_rate_t ckgen_ip_mon_get_rate(paddr_t base, uint32 id);

void ckgen_ip_mon_set_thrd(paddr_t base, uint32 id,
                           uint16 low_thrd, uint16 high_thrd);

ckgen_rate_t ckgen_bus_mon_get_rate(paddr_t base, uint32 id);

void ckgen_bus_mon_set_thrd(paddr_t base, uint32 id,
                            uint16 low_thrd, uint16 high_thrd);

ckgen_rate_t ckgen_core_mon_get_rate(paddr_t base, uint32 id);

void ckgen_core_mon_set_thrd(paddr_t base, uint32 id,
                             uint16 low_thrd, uint16 high_thrd);

void ckgen_xcg_debug_enable(paddr_t base, uint32 id, bool en);

void ckgen_xcg_amon_enable(paddr_t base, uint32 id, bool en);

uint8 ckgen_xcg_get_amon_state(paddr_t base, uint32 id);

void ckgen_pll_mon_enable(paddr_t base, uint32 id, uint32 tout);

void ckgen_pll_mon_disable(paddr_t base, uint32 id);

uint8 ckgen_pll_mon_get_state(paddr_t base, uint32 id);

void ckgen_xtal_mon_enable(paddr_t base, uint32 tout);

void ckgen_xtal_mon_disable(paddr_t base);

uint8 ckgen_xtal_mon_get_rc24m_state(paddr_t base);

uint8 ckgen_xtal_mon_get_xtal_state(paddr_t base);

void ckgen_dbg_mon_ip_select(paddr_t base, uint32 id);

void ckgen_dbg_mon_bus_select(paddr_t base, uint32 id);

void ckgen_dbg_mon_core_select(paddr_t base, uint32 id);

void ckgen_dbg_mon_ext_select(paddr_t base, uint32 id);

uint32 ckgen_dbg_mon_get_ip_rate(paddr_t base, uint32 id);

uint32 ckgen_dbg_mon_get_bus_rate(paddr_t base, uint32 id);

uint32 ckgen_dbg_mon_get_core_rate(paddr_t base, uint32 id);

uint32 ckgen_dbg_mon_get_ext_rate(paddr_t base, uint32 id);

uint32 ckgen_24M_mon_get_rate(paddr_t base);

void ckgen_cqm_enable(paddr_t base, uint32 id,
                      uint16 duty, uint16 jitter);

void ckgen_cqm_disable(paddr_t base, uint32 id);

void ckgen_cqm_cor_int_enable(paddr_t base, uint32 id, bool en);

void ckgen_cqm_unc_int_enable(paddr_t base, uint32 id, bool en);

bool ckgen_cqm_get_duty_int_state(paddr_t base, uint32 id);

bool ckgen_cqm_get_jitter_int_state(paddr_t base, uint32 id);

void ckgen_cqm_clear_duty_int_state(paddr_t base, uint32 id);

void ckgen_cqm_clear_jitter_int_state(paddr_t base, uint32 id);

#endif

#endif /* E3_CKGEN_H_ */
