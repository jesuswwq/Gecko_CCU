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
 * @file  sdrv_etimer_lld.h
 * @brief Semidrive. Etimer
 */

#ifndef DRV_LLD_SDRV_ETIMER_H
#define DRV_LLD_SDRV_ETIMER_H

#include "__compiler.h"

#include "types.h"
#include "__regs_base.h"

#ifndef ASSEMBLY

__BEGIN_CDECLS

#define ETMR_INT_STA_OFF 0x0U
#define ETMR_BM_INT_STA_CHN_DMA_REQ(id) (0x01U << (20U + (id)))
#define ETMR_BM_INT_STA_CNT_SNAP_SHOT(id) (0x01U << 14U(id))
#define ETMR_BM_INT_STA_CNT_OVF(id) (0x01U << (8U + (id)))
#define ETMR_BM_INT_STA_CMP(id) (0x01U << (4U + (id)))
#define ETMR_BM_INT_STA_CPT(id) (0x01U << (id))

#define ETMR_INT_STA_EN_OFF 0x4U
#define ETMR_BM_INT_STA_EN_CHN_DMA_REQ(id) (0x01U << (20U + (id)))
#define ETMR_BM_INT_STA_EN_CNT_SNAP_SHOT(id) (0x01U << (14U + (id)))
#define ETMR_BM_INT_STA_EN_CNT_OVF(id) (0x01U << (8U + (id)))
#define ETMR_BM_INT_STA_EN_CMP(id) (0x01U << (4U + (id)))
#define ETMR_BM_INT_STA_EN_CPT(id) (0x01U << (id))

#define ETMR_INT_SIG_EN_OFF 0x8U

#define ETMR_COR_ERR_INT_STA_OFF 0xcU

#define ETMR_COR_ERR_INT_STA_EN_OFF 0x10U

#define ETMR_COR_ERR_INT_SIG_EN_OFF 0x14U

#define ETMR_UNC_ERR_INT_STA_OFF 0x18U

#define ETMR_UNC_ERR_INT_STA_EN_OFF 0x1cU

#define ETMR_UNC_ERR_INT_SIG_EN_OFF 0x20U

#define ETMR_FUSA_COR_ERR_INT_STA_OFF 0x24U

#define ETMR_FUSA_COR_ERR_INT_STA_EN_OFF 0x28U

#define ETMR_FUSA_COR_ERR_INT_SIG_EN_OFF 0x2cU

#define ETMR_FUSA_UNC_ERR_INT_STA_OFF 0x30U

#define ETMR_FUSA_UNC_ERR_INT_STA_EN_OFF 0x34U

#define ETMR_FUSA_UNC_ERR_INT_SIG_EN_OFF 0x38U

#define ETMR_FUSA_UNC_ERR_INT_STA_1_OFF 0x3cU

#define ETMR_FUSA_UNC_ERR_INT_STA_EN_1_OFF 0x40U

#define ETMR_FUSA_UNC_ERR_INT_SIG_EN_1_OFF 0x44U

#define ETMR_REG_PARITY_ERR_INT_STAT_OFF 0x4cU

#define ETMR_REG_PARITY_ERR_INT_STAT_EN_OFF 0x50U

#define ETMR_REG_PARITY_ERR_INT_SIG_EN_OFF 0x54U

#define ETMR_PRDATAINJ_OFF 0x5cU

#define ETMR_RAM_RDATA_INJ_OFF 0x60U

#define ETMR_RAM_RECC_INJ_OFF 0x64U

#define ETMR_RAM_RDATA_MON_INJ_OFF 0x68U

#define ETMR_RAM_RECC_MON_INJ_OFF 0x6cU

#define ETMR_PWDATA_INJ_OFF 0x70U

#define ETMR_PWECC_INJ_OFF 0x74U

#define ETMR_FM_PWECC_INJ_ECC_INJ (0x7fU << 0U)
#define ETMR_FV_PWECC_INJ_ECC_INJ(v) (((v) << 0U) & ETMR_FM_PWECC_INJ_ECC_INJ)
#define ETMR_GFV_PWECC_INJ_ECC_INJ(v) (((v)&ETMR_FM_PWECC_INJ_ECC_INJ) >> 0U)

#define ETMR_DMA_FW_DATA_INJ_OFF 0x80U

#define ETMR_FM_DMA_FW_DATA_INJ_CONFIG_DMA (0x7U << 16U)
#define ETMR_FV_DMA_FW_DATA_INJ_CONFIG_DMA(v)                                  \
    (((v) << 16U) & ETMR_FM_DMA_FW_DATA_INJ_CONFIG_DMA)
#define ETMR_GFV_DMA_FW_DATA_INJ_CONFIG_DMA(v)                                 \
    (((v)&ETMR_FM_DMA_FW_DATA_INJ_CONFIG_DMA) >> 16U)

#define ETMR_FM_DMA_FW_DATA_INJ_DMA_D (0x7U << 12U)
#define ETMR_FV_DMA_FW_DATA_INJ_DMA_D(v)                                       \
    (((v) << 12U) & ETMR_FM_DMA_FW_DATA_INJ_DMA_D)
#define ETMR_GFV_DMA_FW_DATA_INJ_DMA_D(v)                                      \
    (((v)&ETMR_FM_DMA_FW_DATA_INJ_DMA_D) >> 12U)

#define ETMR_FM_DMA_FW_DATA_INJ_DMA_C (0x7U << 8U)
#define ETMR_FV_DMA_FW_DATA_INJ_DMA_C(v)                                       \
    (((v) << 8U) & ETMR_FM_DMA_FW_DATA_INJ_DMA_C)
#define ETMR_GFV_DMA_FW_DATA_INJ_DMA_C(v)                                      \
    (((v)&ETMR_FM_DMA_FW_DATA_INJ_DMA_C) >> 8U)

#define ETMR_FM_DMA_FW_DATA_INJ_DMA_B (0x7U << 4U)
#define ETMR_FV_DMA_FW_DATA_INJ_DMA_B(v)                                       \
    (((v) << 4U) & ETMR_FM_DMA_FW_DATA_INJ_DMA_B)
#define ETMR_GFV_DMA_FW_DATA_INJ_DMA_B(v)                                      \
    (((v)&ETMR_FM_DMA_FW_DATA_INJ_DMA_B) >> 4U)

#define ETMR_FM_DMA_FW_DATA_INJ_DMA_A (0x7U << 0U)
#define ETMR_FV_DMA_FW_DATA_INJ_DMA_A(v)                                       \
    (((v) << 0U) & ETMR_FM_DMA_FW_DATA_INJ_DMA_A)
#define ETMR_GFV_DMA_FW_DATA_INJ_DMA_A(v)                                      \
    (((v)&ETMR_FM_DMA_FW_DATA_INJ_DMA_A) >> 0U)

#define ETMR_DMA_FW_CODE_INJ_OFF 0x84U

#define ETMR_FM_DMA_FW_CODE_INJ_CONFIG_DMA (0xfU << 16U)
#define ETMR_FV_DMA_FW_CODE_INJ_CONFIG_DMA(v)                                  \
    (((v) << 16U) & ETMR_FM_DMA_FW_CODE_INJ_CONFIG_DMA)
#define ETMR_GFV_DMA_FW_CODE_INJ_CONFIG_DMA(v)                                 \
    (((v)&ETMR_FM_DMA_FW_CODE_INJ_CONFIG_DMA) >> 16U)

#define ETMR_FM_DMA_FW_CODE_INJ_DMA_D (0xfU << 12U)
#define ETMR_FV_DMA_FW_CODE_INJ_DMA_D(v)                                       \
    (((v) << 12U) & ETMR_FM_DMA_FW_CODE_INJ_DMA_D)
#define ETMR_GFV_DMA_FW_CODE_INJ_DMA_D(v)                                      \
    (((v)&ETMR_FM_DMA_FW_CODE_INJ_DMA_D) >> 12U)

#define FM_DMA_FW_CODE_INJ_DMA_C (0xfU << 8U)
#define ETMR_FV_DMA_FW_CODE_INJ_DMA_C(v)                                       \
    (((v) << 8U) & FM_DMA_FW_CODE_INJ_DMA_C)
#define ETMR_GFV_DMA_FW_CODE_INJ_DMA_C(v) (((v)&FM_DMA_FW_CODE_INJ_DMA_C) >> 8U)

#define ETMR_FM_DMA_FW_CODE_INJ_DMA_B (0xfU << 4U)
#define ETMR_FV_DMA_FW_CODE_INJ_DMA_B(v)                                       \
    (((v) << 4U) & ETMR_FM_DMA_FW_CODE_INJ_DMA_B)
#define ETMR_GFV_DMA_FW_CODE_INJ_DMA_B(v)                                      \
    (((v)&ETMR_FM_DMA_FW_CODE_INJ_DMA_B) >> 4U)

#define ETMR_FM_DMA_FW_CODE_INJ_DMA_A (0xfU << 0U)
#define ETMR_FV_DMA_FW_CODE_INJ_DMA_A(v)                                       \
    (((v) << 0U) & ETMR_FM_DMA_FW_CODE_INJ_DMA_A)
#define ETMR_GFV_DMA_FW_CODE_INJ_DMA_A(v)                                      \
    (((v)&ETMR_FM_DMA_FW_CODE_INJ_DMA_A) >> 0U)

#define ETMR_DMA_BW_DATA_INJ_OFF 0x88U

#define ETMR_FM_DMA_BW_DATA_INJ_CONFIG_DMA (0xfU << 16U)
#define ETMR_FV_DMA_BW_DATA_INJ_CONFIG_DMA(v)                                  \
    (((v) << 16U) & ETMR_FM_DMA_BW_DATA_INJ_CONFIG_DMA)
#define ETMR_GFV_DMA_BW_DATA_INJ_CONFIG_DMA(v)                                 \
    (((v)&ETMR_FM_DMA_BW_DATA_INJ_CONFIG_DMA) >> 16U)

#define ETMR_FM_DMA_BW_DATA_INJ_DMA_D (0xfU << 12U)
#define ETMR_FV_DMA_BW_DATA_INJ_DMA_D(v)                                       \
    (((v) << 12U) & ETMR_FM_DMA_BW_DATA_INJ_DMA_D)
#define ETMR_GFV_DMA_BW_DATA_INJ_DMA_D(v)                                      \
    (((v)&ETMR_FM_DMA_BW_DATA_INJ_DMA_D) >> 12U)

#define ETMR_FM_DMA_BW_DATA_INJ_DMA_C (0xfU << 8U)
#define ETMR_FV_DMA_BW_DATA_INJ_DMA_C(v)                                       \
    (((v) << 8U) & ETMR_FM_DMA_BW_DATA_INJ_DMA_C)
#define ETMR_GFV_DMA_BW_DATA_INJ_DMA_C(v)                                      \
    (((v)&ETMR_FM_DMA_BW_DATA_INJ_DMA_C) >> 8U)

#define ETMR_FM_DMA_BW_DATA_INJ_DMA_B (0xfU << 4U)
#define ETMR_FV_DMA_BW_DATA_INJ_DMA_B(v)                                       \
    (((v) << 4U) & ETMR_FM_DMA_BW_DATA_INJ_DMA_B)
#define ETMR_GFV_DMA_BW_DATA_INJ_DMA_B(v)                                      \
    (((v)&ETMR_FM_DMA_BW_DATA_INJ_DMA_B) >> 4U)

#define ETMR_FM_DMA_BW_DATA_INJ_DMA_A (0xfU << 0U)
#define ETMR_FV_DMA_BW_DATA_INJ_DMA_A(v)                                       \
    (((v) << 0U) & ETMR_FM_DMA_BW_DATA_INJ_DMA_A)
#define ETMR_GFV_DMA_BW_DATA_INJ_DMA_A(v)                                      \
    (((v)&ETMR_FM_DMA_BW_DATA_INJ_DMA_A) >> 0U)

#define ETMR_DMA_BW_CODE_INJ_OFF 0x8cU

#define ETMR_FM_DMA_BW_CODE_INJ_CONFIG_DMA (0xfU << 16U)
#define ETMR_FV_DMA_BW_CODE_INJ_CONFIG_DMA(v)                                  \
    (((v) << 16U) & ETMR_FM_DMA_BW_CODE_INJ_CONFIG_DMA)
#define ETMR_GFV_DMA_BW_CODE_INJ_CONFIG_DMA(v)                                 \
    (((v)&ETMR_FM_DMA_BW_CODE_INJ_CONFIG_DMA) >> 16U)

#define ETMR_FM_DMA_BW_CODE_INJ_DMA_D (0xfU << 12U)
#define ETMR_FV_DMA_BW_CODE_INJ_DMA_D(v)                                       \
    (((v) << 12U) & ETMR_FM_DMA_BW_CODE_INJ_DMA_D)
#define ETMR_GFV_DMA_BW_CODE_INJ_DMA_D(v)                                      \
    (((v)&ETMR_FM_DMA_BW_CODE_INJ_DMA_D) >> 12U)

#define ETMR_FM_DMA_BW_CODE_INJ_DMA_C (0xfU << 8U)
#define ETMR_FV_DMA_BW_CODE_INJ_DMA_C(v)                                       \
    (((v) << 8U) & ETMR_FM_DMA_BW_CODE_INJ_DMA_C)
#define ETMR_GFV_DMA_BW_CODE_INJ_DMA_C(v)                                      \
    (((v)&ETMR_FM_DMA_BW_CODE_INJ_DMA_C) >> 8U)

#define ETMR_FM_DMA_BW_CODE_INJ_DMA_B (0xfU << 4U)
#define ETMR_FV_DMA_BW_CODE_INJ_DMA_B(v)                                       \
    (((v) << 4U) & ETMR_FM_DMA_BW_CODE_INJ_DMA_B)
#define ETMR_GFV_DMA_BW_CODE_INJ_DMA_B(v)                                      \
    (((v)&ETMR_FM_DMA_BW_CODE_INJ_DMA_B) >> 4U)

#define ETMR_FM_DMA_BW_CODE_INJ_DMA_A (0xfU << 0U)
#define ETMR_FV_DMA_BW_CODE_INJ_DMA_A(v)                                       \
    (((v) << 0U) & ETMR_FM_DMA_BW_CODE_INJ_DMA_A)
#define ETMR_GFV_DMA_BW_CODE_INJ_DMA_A(v)                                      \
    (((v)&ETMR_FM_DMA_BW_CODE_INJ_DMA_A) >> 0U)

#define ETMR_INT_ERR_INJ_OFF 0x90U

#define ETMR_CLK_MON_CMP_ERR_INJ_OFF 0x94U

#define ETMR_FM_CLK_MON_CMP_ERR_INJ_ERR1 (0x3U << 2U)
#define ETMR_FV_CLK_MON_CMP_ERR_INJ_ERR1(v)                                    \
    (((v) << 2U) & ETMR_FM_CLK_MON_CMP_ERR_INJ_ERR1)
#define ETMR_GFV_CLK_MON_CMP_ERR_INJ_ERR1(v)                                   \
    (((v)&ETMR_FM_CLK_MON_CMP_ERR_INJ_ERR1) >> 2U)

#define ETMR_FM_CLK_MON_CMP_ERR_INJ_ERR0 (0x3U << 0U)
#define ETMR_FV_CLK_MON_CMP_ERR_INJ_ERR0(v)                                    \
    (((v) << 0U) & ETMR_FM_CLK_MON_CMP_ERR_INJ_ERR0)
#define ETMR_GFV_CLK_MON_CMP_ERR_INJ_ERR0(v)                                   \
    (((v)&ETMR_FM_CLK_MON_CMP_ERR_INJ_ERR0) >> 0U)

#define ETMR_TIM_CLK_CONFIG_OFF 0xa0U

#define ETMR_BM_TIM_CLK_CONFIG_CLK_CHANGE_UPD (0x01U << 31U)

#define ETMR_FM_TIM_CLK_CONFIG_SRC_CLK_SEL (0x3U << 16U)
#define ETMR_FV_TIM_CLK_CONFIG_SRC_CLK_SEL(v)                                  \
    (((v) << 16U) & ETMR_FM_TIM_CLK_CONFIG_SRC_CLK_SEL)

#define ETMR_FM_TIM_CLK_CONFIG_DIV_NUM (0xffffU << 0U)
#define ETMR_FV_TIM_CLK_CONFIG_DIV_NUM(v)                                      \
    (((v) << 0U) & ETMR_FM_TIM_CLK_CONFIG_DIV_NUM)

#define ETMR_CLK_MON_EN_OFF 0xa4U

#define ETMR_BM_CLK_MON_EN_CMP_SET (0x01U << 2U)

#define ETMR_BM_CLK_MON_EN_EN_N (0x01U << 1U)

#define ETMR_BM_CLK_MON_EN_EN_P (0x01U << 0U)

#define ETMR_SW_RST_OFF 0xa8U

#define ETMR_BM_SW_RST_CNT_G1 (0x01U << 5U)

#define ETMR_BM_SW_RST_CNT_G0 (0x01U << 4U)

#define ETMR_BM_SW_RST_CHN_D (0x01U << 3U)

#define ETMR_BM_SW_RST_CHN_C (0x01U << 2U)

#define ETMR_BM_SW_RST_CHN_B (0x01U << 1U)

#define ETMR_BM_SW_RST_CHN_A (0x01U << 0U)

#define ETMR_CHN_DMA_CTRL_OFF 0xb0U
#define ETMR_BM_CHN_DMA_CTRL_CHN_16BIT_MODE(id) (0x01U << (16U + (id)))
#define ETMR_BM_CHN_DMA_CTRL_CHN_SIG_MASK(id) (0x01U << (12U + (id)))
#define ETMR_FM_CHN_DMA_CTRL_CHN_SEL(id) (0x3U << (4U + (id)*0x2U))
#define ETMR_FV_CHN_DMA_CTRL_CHN_SEL(v, id)                                    \
    (((v) << (4U + (id)*0x2U)) & ETMR_FM_CHN_DMA_CTRL_CHN_SEL(id))
#define ETMR_BM_CHN_DMA_CTRL_CHN_EN(id) (0x01U << (id))

#define ETMR_DMA_WML_OFF 0xb4U
#define ETMR_FM_DMA_WML_CHN(id) (0xfU << ((id)*0x8U))
#define ETMR_FV_DMA_WML_CHN(v, id)                                             \
    (((v) << ((id)*0x8U)) & ETMR_FM_DMA_WML_CHN(id))

#define ETMR_CONFIG_DMA_CTL_OFF 0xb8U

#define ETMR_FM_CONFIG_DMA_CTL_TRIG_SEL (0x3fffU << 2U)
#define ETMR_FV_CONFIG_DMA_CTL_TRIG_SEL(v)                                     \
    (((v) << 2U) & ETMR_FM_CONFIG_DMA_CTL_TRIG_SEL)
#define ETMR_BM_CONFIG_DMA_CTL_SIG_MASK (0x01U << 1U)
#define ETMR_BM_CONFIG_DMA_CTL_EN (0x01U << 0U)

#define ETMR_FIFO_REQ_STATUS_OFF 0xbcU

#define ETMR_FIFO_OFF(id) (0xc0U + (id)*0x4U)

#define ETMR_FIFO_STA_OFF 0xd0U

#define ETMR_BM_FIFO_STA_FIFO_ERR (0x01U << ((id * 8U) + 7U))
#define ETMR_FM_FIFO_STA_FIFO_ENTRIES(id) (0x1fU << ((id * 8U) + 2U))
#define ETMR_FV_FIFO_STA_FIFO_ENTRIES(v, id)                                   \
    (((v) << ((id * 8U) + 2U)) & ETMR_FM_FIFO_STA_FIFO_ENTRIES(id))
#define ETMR_GFV_FIFO_STA_FIFO_ENTRIES(v, id)                                  \
    (((v)&ETMR_FM_FIFO_STA_FIFO_ENTRIES(id)) >> ((id * 8U) + 2U))
#define ETMR_BM_FIFO_STA_FIFO_EMPTY (0x01U << ((id * 8U) + 1U))
#define ETMR_BM_FIFO_STA_FIFO_FULL(id) (0x01U << (id * 8U))

#define ETMR_CNT_INIT_OFF(id) (0x100U + (id)*0x20)

#define ETMR_CNT_OVF_OFF(id) (0x104U + (id)*0x20)

#define ETMR_CNT_CFG_OFF(id) (0x108U + (id)*0x20)
#define ETMR_BM_CNT_G0_CFG_CASCADE_MODE (0x01U << 31U)
/* basic cnt cfg */
#define ETMR_BM_CNT_CFG_CENTER_ALIGN_MODE (0x1U << 24U)
#define ETMR_FM_CNT_CFG_CENTER_ALIGN_CE_SEL (0x3U << 22U)
#define ETMR_FV_CNT_CFG_CENTER_ALIGN_CE_SEL(v)                                 \
    (((v) << 20U) & ETMR_FM_CNT_CFG_CENTER_ALIGN_CE_SEL)
#define ETMR_FM_CNT_CFG_CENTER_ALIGN_OVF_SEL (0x3U << 20U)
#define ETMR_FV_CNT_CFG_CENTER_ALIGN_OVF_SEL(v)                                \
    (((v) << 20U) & ETMR_FM_CNT_CFG_CENTER_ALIGN_OVF_SEL)
#define ETMR_BM_CNT_CFG_OVF_RST_DIS (0x01U << 19U)
#define ETMR_BM_CNT_CFG_CON_MODE (0x01U << 18U)
#define ETMR_BM_CNT_CFG_OVF_UPD (0x01U << 17U)
#define ETMR_BM_CNT_CFG_INIT_UPD (0x01U << 16U)
#define ETMR_FM_CNT_CFG_INTERVAL (0xffU << 8U)
#define ETMR_FV_CNT_CFG_INTERVAL(v) (((v) << 8U) & ETMR_FM_CNT_CFG_INTERVAL)
#define ETMR_BM_CNT_CFG_CE_EN (0x01U << 7U)
#define ETMR_FM_CNT_CFG_CLR_TRIG_SEL (0x3U << 5U)
#define ETMR_FV_CNT_CFG_CLR_TRIG_SEL(v)                                        \
    (((v) << 5U) & ETMR_FM_CNT_CFG_CLR_TRIG_SEL)
#define ETMR_FM_CNT_CFG_SET_UPD_SEL (0x3U << 3U)
#define ETMR_FV_CNT_CFG_SET_UPD_SEL(v)                                         \
    (((v) << 3U) & ETMR_FM_CNT_CFG_SET_UPD_SEL)
#define ETMR_FM_CNT_CFG_SET_TRIG_SEL (0x3U << 1U)
#define ETMR_FV_CNT_CFG_SET_TRIG_SEL(v)                                        \
    (((v) << 1U) & ETMR_FM_CNT_CFG_SET_TRIG_SEL)
#define ETMR_BM_CNT_CFG_FRC_RLD (0x01U << 0U)
/* local cnt cfg */
#define ETMR_BM_LCNT_CFG_OVF_RST_DIS (0x01U << 28U)
#define ETMR_BM_LCNT_CFG_DELTA_TIME_EN (0x01U << 27U)
#define ETMR_BM_LCNT_CFG_SIG_EN (0x01U << 26U)
#define ETMR_BM_LCNT_CFG_START_BY_FIRST_CPT (0x01U << 25U)
#define ETMR_BM_LCNT_CFG_CPT1_CLR_EN (0x01U << 24U)
#define ETMR_BM_LCNT_CFG_CPT0_CLR_EN (0x01U << 23U)
#define ETMR_FM_LCNT_CFG_SIG_TRIG_SEL (0x3U << 21U)
#define ETMR_FV_LCNT_CFG_SIG_TRIG_SEL(v)                                       \
    (((v) << 21U) & ETMR_FM_LCNT_CFG_SIG_TRIG_SEL)
#define ETMR_BM_LCNT_CFG_NO_STOP_OVF_MODE (0x01U << 20U)
#define ETMR_BM_LCNT_CFG_NO_STOP_MODE (0x01U << 19U)
#define ETMR_BM_LCNT_CFG_CON_MODE (0x01U << 18U)
#define ETMR_BM_LCNT_CFG_OVF_UPD (0x01U << 17U)
#define ETMR_BM_LCNT_CFG_INIT_UPD (0x01U << 16U)
#define ETMR_FM_LCNT_CFG_INTERVAL (0xffU << 8U)
#define ETMR_FV_LCNT_CFG_INTERVAL(v) (((v) << 8U) & ETMR_FM_LCNT_CFG_INTERVAL)
#define ETMR_BM_LCNT_CFG_CE_EN (0x01U << 7U)
#define ETMR_FM_LCNT_CFG_CLR_TRIG_SEL (0x3U << 5U)
#define ETMR_FV_LCNT_CFG_CLR_TRIG_SEL(v)                                       \
    (((v) << 5U) & ETMR_FM_LCNT_CFG_CLR_TRIG_SEL)
#define ETMR_FM_LCNT_CFG_SET_UPD_SEL (0x3U << 3U)
#define ETMR_FV_LCNT_CFG_SET_UPD_SEL(v)                                        \
    (((v) << 3U) & ETMR_FM_LCNT_CFG_SET_UPD_SEL)
#define ETMR_FM_LCNT_CFG_SET_TRIG_SEL (0x3U << 1U)
#define ETMR_FV_LCNT_CFG_SET_TRIG_SEL(v)                                       \
    (((v) << 1U) & ETMR_FM_LCNT_CFG_SET_TRIG_SEL)
#define ETMR_BM_LCNT_CFG_FRC_RLD (0x01U << 0U)

#define ETMR_CNT_EN_OFF(id) (0x10cU + (id)*0x20)

#define ETMR_CNT_OFF(id) (0x110U + (id)*0x20)

#define ETMR_CNT_HOLD_OFF(id) (0x114U + ((id)*0x20U))

#define ETMR_CNT_DIFF_OFF(id) (0x118U + ((id)*0x20U))

#define ETMR_CPT_CPT0_CNT0_OFF(id) (0x1c0U + (id)*0x10U)

#define ETMR_CPT_CPT0_CNT1_OFF(id) (0x1c4U + (id)*0x10U)

#define ETMR_CPT_CPT1_CNT0_OFF(id) (0x1c8U + (id)*0x10U)

#define ETMR_CPT_CPT1_CNT1_OFF(id) (0x1ccU + (id)*0x10U)

#define ETMR_CPT_CONFIG_OFF(id) (0x200U + (id)*4)
#define ETMR_FM_CPT_CONFIG_CE_TRIG_SEL (0x3U << 9U)
#define ETMR_FV_CPT_CONFIG_CE_TRIG_SEL(v)                                      \
    (((v) << 9U) & ETMR_FM_CPT_CONFIG_CE_TRIG_SEL)
#define ETMR_BM_CPT_CONFIG_CE_EN (0x01U << 8U)
#define ETMR_FM_CPT_CONFIG_CNT_SEL (0x3U << 6U)
#define ETMR_FV_CPT_CONFIG_CNT_SEL(v) (((v) << 6U) & ETMR_FM_CPT_CONFIG_CNT_SEL)
#define ETMR_FM_CPT_CONFIG_CPT1_TRIG_MODE (0x3U << 4U)
#define ETMR_FV_CPT_CONFIG_CPT1_TRIG_MODE(v)                                   \
    (((v) << 4U) & ETMR_FM_CPT_CONFIG_CPT1_TRIG_MODE)
#define ETMR_FM_CPT_CONFIG_CPT0_TRIG_MODE (0x3U << 2U)
#define ETMR_FV_CPT_CONFIG_CPT0_TRIG_MODE(v)                                   \
    (((v) << 2U) & ETMR_FM_CPT_CONFIG_CPT0_TRIG_MODE)
#define ETMR_BM_CPT_CONFIG_DUAL_MODE (0x01U << 1U)
#define ETMR_BM_CPT_CONFIG_CON_MODE (0x01U << 0U)

#define ETMR_CPT_CTRL_OFF 0x210U
#define ETMR_BM_CPT_CTRL_CPT_CONFIG_SET(id) (0x01U << (4U + (id)))
#define ETMR_BM_CPT_CTRL_CPT_EN(id) (0x01U << (id))

#define ETMR_CMP_CONFIG_OFF(id) (0x220U + (id)*0x30U)
#define ETMR_FM_CMP_CONFIG_REFRESH_INTVAL (0xffU << 24U)
#define ETMR_FV_CMP_CONFIG_REFRESH_INTVAL(v)                                   \
    (((v) << 24U) & ETMR_FM_CMP_CONFIG_REFRESH_INTVAL)
#define ETMR_BM_CMP_CONFIG_SW_RLD_MODE(v) (v << 16U)
#define ETMR_BM_CMP_CONFIG_SW_RLD_SET (0x01U << 15U)
#define ETMR_BM_CMP_CONFIG_RLD_TRIG_MODE(v) (v << 14U)
#define ETMR_FM_CMP_CONFIG_CLR_TRIG_SEL (0x3U << 12U)
#define ETMR_FV_CMP_CONFIG_CLR_TRIG_SEL(v)                                     \
    (((v) << 12U) & ETMR_FM_CMP_CONFIG_CLR_TRIG_SEL)
#define ETMR_FM_CMP_CONFIG_SET_TRIG_SEL (0x3U << 10U)
#define ETMR_FV_CMP_CONFIG_SET_TRIG_SEL(v)                                     \
    (((v) << 10U) & ETMR_FM_CMP_CONFIG_SET_TRIG_SEL)
#define ETMR_BM_CMP_CONFIG_HW_RLD_MODE (0x01U << 9U)
#define ETMR_BM_CMP_CONFIG_CE_EN (0x01U << 8U)
#define ETMR_FM_CMP_CONFIG_CE_TRIG_SEL (0x3U << 6U)
#define ETMR_FV_CMP_CONFIG_CE_TRIG_SEL(v)                                      \
    (((v) << 6U) & ETMR_FM_CMP_CONFIG_CE_TRIG_SEL)
#define ETMR_FM_CMP_CONFIG_CNT_SEL (0x3U << 4U)
#define ETMR_FV_CMP_CONFIG_CNT_SEL(v) (((v) << 4U) & ETMR_FM_CMP_CONFIG_CNT_SEL)
#define ETMR_FM_CMP_CONFIG_CMP_MODE (0x3U << 2U)
#define ETMR_FV_CMP_CONFIG_CMP_MODE(v)                                         \
    (((v) << 2U) & ETMR_FM_CMP_CONFIG_CMP_MODE)
#define ETMR_BM_CMP_CONFIG_CON_MODE(v) (v << 1U)
#define ETMR_BM_CMP_CONFIG_OUT_MODE(v) (v << 0U)

#define ETMR_CMP_EVENT_OUT_MODE_OFF(id) (0x224U + (id)*0x30U)
#define ETMR_FM_CMP_EVENT_OUT_MODE_CMP1_OVF (0x7U << 20U)
#define ETMR_FV_CMP_EVENT_OUT_MODE_CMP1_OVF(v)                                 \
    (((v) << 20U) & ETMR_FM_CMP_EVENT_OUT_MODE_CMP1_OVF)
#define ETMR_FM_CMP_EVENT_OUT_MODE_CMP0_OVF (0x7U << 16U)
#define ETMR_FV_CMP_EVENT_OUT_MODE_CMP0_OVF(v)                                 \
    (((v) << 16U) & ETMR_FM_CMP_EVENT_OUT_MODE_CMP0_OVF)
#define ETMR_FM_CMP_EVENT_OUT_MODE_CMP11 (0x7U << 12U)
#define ETMR_FV_CMP_EVENT_OUT_MODE_CMP11(v)                                    \
    (((v) << 12U) & ETMR_FM_CMP_EVENT_OUT_MODE_CMP11)
#define ETMR_FM_CMP_EVENT_OUT_MODE_CMP10 (0x7U << 8U)
#define ETMR_FV_CMP_EVENT_OUT_MODE_CMP10(v)                                    \
    (((v) << 8U) & ETMR_FM_CMP_EVENT_OUT_MODE_CMP10)
#define ETMR_FM_CMP_EVENT_OUT_MODE_CMP01 (0x7U << 4U)
#define ETMR_FV_CMP_EVENT_OUT_MODE_CMP01(v)                                    \
    (((v) << 4U) & ETMR_FM_CMP_EVENT_OUT_MODE_CMP01)
#define ETMR_FM_CMP_EVENT_OUT_MODE_CMP00 (0x7U << 0U)
#define ETMR_FV_CMP_EVENT_OUT_MODE_CMP00(v)                                    \
    (((v) << 0U) & ETMR_FM_CMP_EVENT_OUT_MODE_CMP00)

#define ETMR_CMP_PULSE_WID0_OFF(id) (0x228U + (id)*0x30U)
#define ETMR_FM_CMP_PULSE_WID0_CMP11 (0xffU << 24U)
#define ETMR_FV_CMP_PULSE_WID0_CMP11(v)                                        \
    (((v) << 24U) & ETMR_FM_CMP_PULSE_WID0_CMP11)
#define ETMR_FM_CMP_PULSE_WID0_CMP10 (0xffU << 16U)
#define ETMR_FV_CMP_PULSE_WID0_CMP10(v)                                        \
    (((v) << 16U) & ETMR_FM_CMP_PULSE_WID0_CMP10)
#define ETMR_FM_CMP_PULSE_WID0_CMP01 (0xffU << 8U)
#define ETMR_FV_CMP_PULSE_WID0_CMP01(v)                                        \
    (((v) << 8U) & ETMR_FM_CMP_PULSE_WID0_CMP01)
#define ETMR_FM_CMP_PULSE_WID0_CMP00 (0xffU << 0U)
#define ETMR_FV_CMP_PULSE_WID0_CMP00(v)                                        \
    (((v) << 0U) & ETMR_FM_CMP_PULSE_WID0_CMP00)

#define ETMR_CMP_PULSE_WID1_OFF(id) (0x22cU + (id)*0x30U)
#define ETMR_FM_CMP_PULSE_WID1_CMP0_OVF (0xffU << 8U)
#define ETMR_FV_CMP_PULSE_WID1_CMP0_OVF(v)                                     \
    (((v) << 8U) & ETMR_FM_CMP_PULSE_WID1_CMP0_OVF)
#define ETMR_FM_CMP_PULSE_WID1_CMP1_OVF (0xffU << 0U)
#define ETMR_FV_CMP_PULSE_WID1_CMP1_OVF(v)                                     \
    (((v) << 0U) & ETMR_FM_CMP_PULSE_WID1_CMP1_OVF)

#define ETMR_CMP_VAL_OFF(id, group) (0x230U + ((id)*0x30U) + (group) * (0x4U))

#define ETMR_CMP_A_DITHER_OFF 0x240U

#define ETMR_FM_CMP_A_DITHER_INIT_OFFSET (0xffffU << 16U)
#define FV_CMP_A_DITHER_INIT_OFFSET(v)                                         \
    (((v) << 16U) & ETMR_FM_CMP_A_DITHER_INIT_OFFSET)
#define ETMR_GFV_CMP_A_DITHER_INIT_OFFSET(v)                                   \
    (((v)&ETMR_FM_CMP_A_DITHER_INIT_OFFSET) >> 16U)

#define ETMR_FM_CMP_A_DITHER_CLIP_RSLT (0xfU << 2U)
#define ETMR_FV_CMP_A_DITHER_CLIP_RSLT(v)                                      \
    (((v) << 2U) & ETMR_FM_CMP_A_DITHER_CLIP_RSLT)
#define ETMR_GFV_CMP_A_DITHER_CLIP_RSLT(v)                                     \
    (((v)&ETMR_FM_CMP_A_DITHER_CLIP_RSLT) >> 2U)

#define ETMR_BM_CMP_A_DITHER_INIT_OFFSET_EN (0x01U << 1U)

#define ETMR_BM_CMP_A_DITHER_DITHER_EN (0x01U << 0U)

#define ETMR_ETMR_CMP_OFFSET_OFF(id) (0x244U + (id)*0x30U)

#define ETMR_CMP_A_EID_OFF 0x248U

#define ETMR_FM_CMP_A_EID_CMP(id) (0xffU << ((id)*0x8U))
#define ETMR_FV_CMP_A_EID_CMP(v, id)                                           \
    (((v) << ((id)*0x8U)) & ETMR_FM_CMP_A_EID_CMP(id))

#define ETMR_CMP_B_DITHER_OFF 0x270U

#define ETMR_FM_CMP_B_DITHER_INIT_OFFSET (0xffffU << 16U)
#define ETMR_FV_CMP_B_DITHER_INIT_OFFSET(v)                                    \
    (((v) << 16U) & ETMR_FM_CMP_B_DITHER_INIT_OFFSET)
#define ETMR_GFV_CMP_B_DITHER_INIT_OFFSET(v)                                   \
    (((v)&ETMR_FM_CMP_B_DITHER_INIT_OFFSET) >> 16U)

#define ETMR_FM_CMP_B_DITHER_CLIP_RSLT (0xfU << 2U)
#define ETMR_FV_CMP_B_DITHER_CLIP_RSLT(v)                                      \
    (((v) << 2U) & ETMR_FM_CMP_B_DITHER_CLIP_RSLT)
#define ETMR_GFV_CMP_B_DITHER_CLIP_RSLT(v)                                     \
    (((v)&ETMR_FM_CMP_B_DITHER_CLIP_RSLT) >> 2U)

#define ETMR_BM_CMP_B_DITHER_INIT_OFFSET_EN (0x01U << 1U)

#define ETMR_BM_CMP_B_DITHER_DITHER_EN (0x01U << 0U)

#define ETMR_CMP_C_DITHER_OFF 0x2a0U

#define ETMR_FM_CMP_C_DITHER_INIT_OFFSET (0xffffU << 16U)
#define ETMR_FV_CMP_C_DITHER_INIT_OFFSET(v)                                    \
    (((v) << 16U) & ETMR_FM_CMP_C_DITHER_INIT_OFFSET)
#define ETMR_GFV_CMP_C_DITHER_INIT_OFFSET(v)                                   \
    (((v)&ETMR_FM_CMP_C_DITHER_INIT_OFFSET) >> 16U)

#define ETMR_FM_CMP_C_DITHER_CLIP_RSLT (0xfU << 2U)
#define ETMR_FV_CMP_C_DITHER_CLIP_RSLT(v)                                      \
    (((v) << 2U) & ETMR_FM_CMP_C_DITHER_CLIP_RSLT)
#define ETMR_GFV_CMP_C_DITHER_CLIP_RSLT(v)                                     \
    (((v)&ETMR_FM_CMP_C_DITHER_CLIP_RSLT) >> 2U)

#define ETMR_BM_CMP_C_DITHER_INIT_OFFSET_EN (0x01U << 1U)

#define ETMR_BM_CMP_C_DITHER_DITHER_EN (0x01U << 0U)

#define ETMR_CMP_D_DITHER_OFF 0x2d0U

#define ETMR_FM_CMP_D_DITHER_INIT_OFFSET (0xffffU << 16U)
#define ETMR_FV_CMP_D_DITHER_INIT_OFFSET(v)                                    \
    (((v) << 16U) & ETMR_FM_CMP_D_DITHER_INIT_OFFSET)
#define ETMR_GFV_CMP_D_DITHER_INIT_OFFSET(v)                                   \
    (((v)&ETMR_FM_CMP_D_DITHER_INIT_OFFSET) >> 16U)

#define ETMR_FM_CMP_D_DITHER_CLIP_RSLT (0xfU << 2U)
#define ETMR_FV_CMP_D_DITHER_CLIP_RSLT(v)                                      \
    (((v) << 2U) & ETMR_FM_CMP_D_DITHER_CLIP_RSLT)
#define ETMR_GFV_CMP_D_DITHER_CLIP_RSLT(v)                                     \
    (((v)&ETMR_FM_CMP_D_DITHER_CLIP_RSLT) >> 2U)

#define ETMR_BM_CMP_D_DITHER_INIT_OFFSET_EN (0x01U << 1U)

#define ETMR_BM_CMP_D_DITHER_DITHER_EN (0x01U << 0U)

#define ETMR_CMP_CTRL_OFF 0x2e0U
#define ETMR_BM_CMP_CTRL_CMP_A_EID_UPD (0x01U << 28U)
#define ETMR_BM_CMP_CTRL_CMP_X1_INIT_UPD(id) (0x01U << (21U + (id)*0x2U))
#define ETMR_BM_CMP_CTRL_CMP_X0_INIT_UPD(id) (0x01U << (20U + (id)*0x2U))
#define ETMR_BM_CMP_CTRL_CMP_X1_INIT_STATUS(id) (0x01U << (13U + (id)*0x2U))
#define ETMR_BM_CMP_CTRL_CMP_X0_INIT_STATUS(id) (0x01U << (12U + (id)*0x2U))
#define ETMR_BM_CMP_CTRL_CMP_VAL_UPD(id) (0x01U << (8U + (id)))
#define ETMR_BM_CMP_CTRL_CMP_CONFIG_SET(id) (0x01U << (4U + (id)))
#define ETMR_BM_CMP_CTRL_CMP_EN(id) (0x01U << (id))

#define ETMR_CPT_SSE_CTRL_OFF(id) (0x300U + (id)*0x8U)
#define ETMR_BM_CPT_SSE_CTRL_QUAD_INDEX_POL (0x01U << 26U)
#define ETMR_BM_CPT_SSE_CTRL_QUAD_HOME_POL (0x01U << 25U)
#define ETMR_FM_CPT_SSE_CTRL_QUAD_CLR_SEL (0xfU << 21U)
#define ETMR_FV_CPT_SSE_CTRL_QUAD_CLR_SEL(v)                                   \
    (((v) << 21U) & ETMR_FM_CPT_SSE_CTRL_QUAD_CLR_SEL)
#define ETMR_FM_CPT_SSE_CTRL_QUAD_SET_SEL (0xfU << 17U)
#define ETMR_FV_CPT_SSE_CTRL_QUAD_SET_SEL(v)                                   \
    (((v) << 17U) & ETMR_FM_CPT_SSE_CTRL_QUAD_SET_SEL)
#define ETMR_BM_CPT_SSE_CTRL_QUAD_MODE_EN (0x01U << 16U)
#define ETMR_FM_CPT_SSE_CTRL_EDGE_SEL (0x3ffU << 6U)
#define ETMR_FV_CPT_SSE_CTRL_EDGE_SEL(v)                                       \
    (((v) << 6U) & ETMR_FM_CPT_SSE_CTRL_EDGE_SEL)
#define ETMR_FM_CPT_SSE_CTRL_SSE_MODE (0x1fU << 1U)
#define ETMR_FV_CPT_SSE_CTRL_SSE_MODE(v)                                       \
    (((v) << 1U) & ETMR_FM_CPT_SSE_CTRL_SSE_MODE)
#define ETMR_BM_CPT_SSE_CTRL_SSE_EN (0x01U << 0U)

#define ETMR_CPT_SSE_REG_OFF(id) (0x304U + (id)*0x8U)

#define ETMR_CMP_SSE_CTRL_OFF(id) (0x320U + (id)*0x8U)
#define ETMR_BM_CMP_SSE_CTRL_SSE_FAULT_DET_EN (0x01U << 19U)
#define ETMR_FM_CMP_SSE_CTRL_SSE_SO_DET_FAULT (0x7U << 16U)
#define ETMR_FV_CMP_SSE_CTRL_SSE_SO_DET_FAULT(v)                               \
    (((v) << 16U) & ETMR_FM_CMP_SSE_CTRL_SSE_SO_DET_FAULT)
#define ETMR_FM_CMP_SSE_CTRL_EDGE_SEL (0x3ffU << 6U)
#define ETMR_FV_CMP_SSE_CTRL_EDGE_SEL(v)                                       \
    (((v) << 6U) & ETMR_FM_CMP_SSE_CTRL_EDGE_SEL)
#define ETMR_FM_CMP_SSE_CTRL_SSE_MODE (0x1fU << 1U)
#define ETMR_FV_CMP_SSE_CTRL_SSE_MODE(v)                                       \
    (((v) << 1U) & ETMR_FM_CMP_SSE_CTRL_SSE_MODE)
#define ETMR_BM_CMP_SSE_CTRL_SSE_EN (0x01U << 0U)

#define ETMR_CMP_SSE_REG_OFF(id) (0x324U + (id)*0x8U)

#define ETMR_CPT_INPUT_SEL_OFF(id) (0x340U + (id)*0x4U)
#define ETMR_FM_CPT_INPUT_SEL_DIR_SEL (0xfU << 12U)
#define ETMR_FV_CPT_INPUT_SEL_DIR_SEL(v)                                       \
    (((v) << 12U) & ETMR_FM_CPT_INPUT_SEL_DIR_SEL)
#define ETMR_FM_CPT_INPUT_SEL_SIG_SEL (0xfU << 8U)
#define ETMR_FV_CPT_INPUT_SEL_SIG_SEL(v)                                       \
    (((v) << 8U) & ETMR_FM_CPT_INPUT_SEL_SIG_SEL)
#define ETMR_FM_CPT_INPUT_SEL_CLR_SEL (0xfU << 4U)
#define ETMR_FV_CPT_INPUT_SEL_CLR_SEL(v)                                       \
    (((v) << 4U) & ETMR_FM_CPT_INPUT_SEL_CLR_SEL)
#define ETMR_FM_CPT_INPUT_SEL_SET_SEL (0xfU << 0U)
#define ETMR_FV_CPT_INPUT_SEL_SET_SEL(v)                                       \
    (((v) << 0U) & ETMR_FM_CPT_INPUT_SEL_SET_SEL)

#define ETMR_CMP_INPUT_SEL_OFF(id) (0x350U + (id)*0x4U)
#define ETMR_FM_CMP_INPUT_SEL_CLR_SEL (0xfU << 4U)
#define ETMR_FV_CMP_INPUT_SEL_CLR_SEL(v)                                       \
    (((v) << 4U) & ETMR_FM_CMP_INPUT_SEL_CLR_SEL)
#define ETMR_FM_CMP_INPUT_SEL_SET_SEL (0xfU << 0U)
#define ETMR_FV_CMP_INPUT_SEL_SET_SEL(v)                                       \
    (((v) << 0U) & ETMR_FM_CMP_INPUT_SEL_SET_SEL)

#define ETMR_CNT_INPUT_SEL_OFF(id) (0x360U + (id)*0x4U)
#define ETMR_FM_CNT_INPUT_SEL_CLR_SEL (0xfU << 4U)
#define ETMR_FV_CNT_INPUT_SEL_CLR_SEL(v)                                       \
    (((v) << 4U) & ETMR_FM_CNT_INPUT_SEL_CLR_SEL)
#define ETMR_FM_CNT_INPUT_SEL_SET_SEL (0xfU << 0U)
#define ETMR_FV_CNT_INPUT_SEL_SET_SEL(v)                                       \
    (((v) << 0U) & ETMR_FM_CNT_INPUT_SEL_SET_SEL)

#define ETMR_EXT_OUTPUT_SEL_OFF 0x368U

#define ETMR_FM_EXT_OUTPUT_SEL_DIR_SEL (0xfU << 8U)
#define ETMR_FV_EXT_OUTPUT_SEL_DIR_SEL(v)                                      \
    (((v) << 8U) & ETMR_FM_EXT_OUTPUT_SEL_DIR_SEL)
#define ETMR_GFV_EXT_OUTPUT_SEL_DIR_SEL(v)                                     \
    (((v)&ETMR_FM_EXT_OUTPUT_SEL_DIR_SEL) >> 8U)

#define ETMR_FM_EXT_OUTPUT_SEL_CLR_SEL (0xfU << 4U)
#define ETMR_FV_EXT_OUTPUT_SEL_CLR_SEL(v)                                      \
    (((v) << 4U) & ETMR_FM_EXT_OUTPUT_SEL_CLR_SEL)
#define ETMR_GFV_EXT_OUTPUT_SEL_CLR_SEL(v)                                     \
    (((v)&ETMR_FM_EXT_OUTPUT_SEL_CLR_SEL) >> 4U)

#define ETMR_FM_EXT_OUTPUT_SEL_SET_SEL (0xfU << 0U)
#define ETMR_FV_EXT_OUTPUT_SEL_SET_SEL(v)                                      \
    (((v) << 0U) & ETMR_FM_EXT_OUTPUT_SEL_SET_SEL)
#define ETMR_GFV_EXT_OUTPUT_SEL_SET_SEL(v)                                     \
    (((v)&ETMR_FM_EXT_OUTPUT_SEL_SET_SEL) >> 0U)

#define ETMR_ETM_POL_INV_OFF 0x36cU

#define ETMR_CPT_SW_TRIG_OFF 0x370U

#define ETMR_CMP_SW_TRIG_OFF 0x374U

#define ETMR_CNT_EXT_SW_TRIG_OFF 0x378U

#define ETMR_SW_TRIG_CTRL_OFF 0x380U
#define ETMR_BM_SW_TRIG_CTRL_SW_TRIG0_CTRL0(trig, id)                          \
    (0x01U << (trig * 0x4U + (id)))

#define ETMR_SW_TRIG_STATUS_OFF 0x384U

#define ETMR_SW_TRIG_PULSE0_OFF 0x388U

#define ETMR_FM_SW_TRIG_PULSE0_TRIG1_WIDTH (0xffffU << 16U)
#define ETMR_FV_SW_TRIG_PULSE0_TRIG1_WIDTH(v)                                  \
    (((v) << 16U) & ETMR_FM_SW_TRIG_PULSE0_TRIG1_WIDTH)
#define ETMR_FM_SW_TRIG_PULSE0_TRIG0_WIDTH (0xffffU << 0U)
#define ETMR_FV_SW_TRIG_PULSE0_TRIG0_WIDTH(v)                                  \
    (((v) << 0U) & ETMR_FM_SW_TRIG_PULSE0_TRIG0_WIDTH)
#define ETMR_SW_TRIG_PULSE1_OFF 0x38cU
#define ETMR_FM_SW_TRIG_PULSE1_TRIG3_WIDTH (0xffffU << 16U)
#define ETMR_FV_SW_TRIG_PULSE1_TRIG3_WIDTH(v)                                  \
    (((v) << 16U) & ETMR_FM_SW_TRIG_PULSE1_TRIG3_WIDTH)
#define ETMR_FM_SW_TRIG_PULSE1_TRIG2_WIDTH (0xffffU << 0U)
#define ETMR_FV_SW_TRIG_PULSE1_TRIG2_WIDTH(v)                                  \
    (((v) << 0U) & ETMR_FM_SW_TRIG_PULSE1_TRIG2_WIDTH)

#define ETMR_CNT_SNAP_SHOT_SEL_OFF(id) (0x390U + (id)*0x4U)

#define ETMR_SNAP_SHOT_O_SEL_OFF 0x3a8U

#define ETMR_CPT_X0_FLT_OFF(id) (0x400U + (id)*0x4U)
#define ETMR_FM_CPT_X0_FLT_SMPL_INTVAL (0xffU << 12U)
#define ETMR_FV_CPT_X0_FLT_SMPL_INTVAL(v)                                      \
    (((v) << 12U) & ETMR_FM_CPT_X0_FLT_SMPL_INTVAL)
#define ETMR_FM_CPT_X0_FLT_NEG_BAND_WID (0xfU << 8U)
#define ETMR_FV_CPT_X0_FLT_NEG_BAND_WID(v)                                     \
    (((v) << 8U) & ETMR_FM_CPT_X0_FLT_NEG_BAND_WID)
#define ETMR_FM_CPT_X0_FLT_POS_BAND_WID (0xfU << 4U)
#define ETMR_FV_CPT_X0_FLT_POS_BAND_WID(v)                                     \
    (((v) << 4U) & ETMR_FM_CPT_X0_FLT_POS_BAND_WID)
#define ETMR_FM_CPT_X0_FLT_FLT_EDGE_SEL (0x3U << 1U)
#define ETMR_FV_CPT_X0_FLT_FLT_EDGE_SEL(v)                                     \
    (((v) << 1U) & ETMR_FM_CPT_X0_FLT_FLT_EDGE_SEL)
#define ETMR_BM_CPT_X0_FLT_FLT_EN (0x01U << 0U)

#define ETMR_FAULT_X_FLT_OFF(id) (0x410U + (id)*0x4U)
#define ETMR_FM_FAULT_X_FLT_SMPL_INTVAL (0xffU << 12U)
#define ETMR_FV_FAULT_X_FLT_SMPL_INTVAL(v)                                     \
    (((v) << 12U) & ETMR_FM_FAULT_X_FLT_SMPL_INTVAL)
#define ETMR_FM_FAULT_X_FLT_NEG_BAND_WID (0xfU << 8U)
#define ETMR_FV_FAULT_X_FLT_NEG_BAND_WID(v)                                    \
    (((v) << 8U) & ETMR_FM_FAULT_X_FLT_NEG_BAND_WID)
#define ETMR_FM_FAULT_X_FLT_POS_BAND_WID (0xfU << 4U)
#define ETMR_FV_FAULT_X_FLT_POS_BAND_WID(v)                                    \
    (((v) << 4U) & ETMR_FM_FAULT_X_FLT_POS_BAND_WID)
#define ETMR_FM_FAULT_X_FLT_FLT_EDGE_SEL (0x3U << 1U)
#define ETMR_FV_FAULT_X_FLT_FLT_EDGE_SEL(v)                                    \
    (((v) << 1U) & ETMR_FM_FAULT_X_FLT_FLT_EDGE_SEL)
#define ETMR_BM_FAULT_X_FLT_FLT_EN (0x01U << 0U)

#define ETMR_SYNC_DIS_OFF 0x420U

#define ETMR_ETMR_CMP_FAULT_EVENT_CTRL_OFF(id) (0x440U + (id)*0x4U)
#define ETMR_BM_CMP_FAULT_EVENT_CTRL_FAULT_X_CLR(id)                           \
    (0x01U << (3U + 0x4U * (id)))
#define ETMR_BM_CMP_FAULT_EVENT_CTRL_FAULT_X_CLR_MODE(id)                      \
    (0x01U << (2U + 0x4U * (id)))
#define ETMR_BM_CMP_FAULT_EVENT_CTRL_FAULT_X_POL(id)                           \
    (0x01U << (1U + 0x4U * (id)))
#define ETMR_BM_CMP_FAULT_EVENT_CTRL_FAULT_X_EN(id) (0x01U << (0x4U * (id)))

#define ETMR_CMP_DTI_CTRL_OFF(id) (0x460U + (id)*0x8U)

#if SEMIDRIVE_E3_LITE_SERIES
#define ETMR_BM_CMP_CMP1_IDLE_STA (0x01U << 9U)
#define ETMR_BM_CMP_CMP0_IDLE_STA (0x01U << 8U)
#define ETMR_BM_CMP_SW_TRIG_FRC (0x01U << 7U)
#endif

#define ETMR_BM_CMP_DTI_CTRL_CMP1_INV_CMP0 (0x01U << 6U)
#define ETMR_BM_CMP_DTI_CTRL_CMP1_SAME_CMP0 (0x01U << 5U)
#define ETMR_BM_CMP_DTI_CTRL_CMP1_FS_STATUS (0x01U << 4U)
#define ETMR_BM_CMP_DTI_CTRL_CMP0_FS_STATUS (0x01U << 3U)
#define ETMR_BM_CMP_DTI_CTRL_CMP1_POL (0x01U << 2U)
#define ETMR_BM_CMP_DTI_CTRL_CMP0_POL (0x01U << 1U)
#define ETMR_BM_CMP_DTI_CTRL_EN (0x01U << 0U)

#define ETMR_CMP_DTI_WID_OFF(id) (0x464U + (id)*0x8U)
#define ETMR_FM_CMP_DTI_WID_DT1_WID (0xffffU << 16U)
#define ETMR_FV_CMP_DTI_WID_DT1_WID(v)                                         \
    (((v) << 16U) & ETMR_FM_CMP_DTI_WID_DT1_WID)
#define ETMR_FM_CMP_DTI_WID_DT0_WID (0xffffU << 0U)
#define ETMR_FV_CMP_DTI_WID_DT0_WID(v)                                         \
    (((v) << 0U) & ETMR_FM_CMP_DTI_WID_DT0_WID)

#define ETMR_SIGNAL_STATUS_OFF 0x500U

#define ETMR_SELFTEST_MODE_OFF 0xffcU

#if CONFIG_E3
#define ETMR_CBC_ZERO_VECTOR_BY_SCR_ADDR (APB_SCR_SF_BASE + 0x1000 + 0x98)
#else
#define ETMR_CBC_ZERO_VECTOR_BY_SCR_ADDR (APB_SCR_SF_BASE + 0x1000 + 0x68)
#endif
#define ETMR_CBC_POS(etmr_id, chnl_id) (etmr_id * 4 + 4 + chnl_id)
#define ETMR_ZERO_VECTOR_POS(etmr_id, chnl_id) (etmr_id * 4 + chnl_id)

#ifdef SEMIDRIVE_E3_LITE_SERIES
#define ETMR_CENTER_ALIGN_CMP_INT_STA_OFF 0xF0
#define ETMR_CENTER_ALIGN_CMP_INT_STA_EN_OFF 0xF4
#define ETMR_CENTER_ALIGN_CMP_INT_SIG_EN_OFF 0xF8

#define ETMR_LCNT_CFG1_OFF(id) (0x15c + (id)*0x20)
#define ETMR_BM_LCNT_CFG_CENTER_ALIGN_MODE (0x1U << 4U)
#define ETMR_FM_LCNT_CFG_CENTER_ALIGN_CE_SEL (0x3U << 2U)
#define ETMR_FV_LCNT_CFG_CENTER_ALIGN_CE_SEL(v)                                \
    (((v) << 2U) & ETMR_FM_LCNT_CFG_CENTER_ALIGN_CE_SEL)
#define ETMR_FM_LCNT_CFG_CENTER_ALIGN_OVF_SEL (0x3U << 0U)
#define ETMR_FV_LCNT_CFG_CENTER_ALIGN_OVF_SEL(v)                               \
    (((v) << 0U) & ETMR_FM_LCNT_CFG_CENTER_ALIGN_OVF_SEL)

#define ETMR_CMP_CONFIG1_OFF(id) (0x24c + (id)*0x30)
#define ETMR_BM_CMP_CENTER_ALIGN_MODE (0x1U << 18U)
#define ETMR_FM_CMP_CENTER_ALIGN_RLD_SEL (0x3U << 16U)
#define ETMR_FV_CMP_CENTER_ALIGN_RLD_SEL(v)                                    \
    (((v) << 16U) & ETMR_FM_CMP_CENTER_ALIGN_RLD_SEL)
#define ETMR_FM_CMP_CENTER_ALIGN_CMP11_IRQ_SEL (0x3U << 14U)
#define ETMR_FV_CMP_CENTER_ALIGN_CMP11_IRQ_SEL(v)                              \
    (((v) << 14U) & ETMR_FM_CMP_CENTER_ALIGN_CMP11_IRQ_SEL)
#define ETMR_FM_CMP_CENTER_ALIGN_CMP10_IRQ_SEL (0x3U << 12U)
#define ETMR_FV_CMP_CENTER_ALIGN_CMP10_IRQ_SEL(v)                              \
    (((v) << 12U) & ETMR_FM_CMP_CENTER_ALIGN_CMP10_IRQ_SEL)
#define ETMR_FM_CMP_CENTER_ALIGN_CMP01_IRQ_SEL (0x3U << 10U)
#define ETMR_FV_CMP_CENTER_ALIGN_CMP01_IRQ_SEL(v)                              \
    (((v) << 10U) & ETMR_FM_CMP_CENTER_ALIGN_CMP01_IRQ_SEL)
#define ETMR_FM_CMP_CENTER_ALIGN_CMP00_IRQ_SEL (0x3U << 8U)
#define ETMR_FV_CMP_CENTER_ALIGN_CMP00_IRQ_SEL(v)                              \
    (((v) << 8U) & ETMR_FM_CMP_CENTER_ALIGN_CMP00_IRQ_SEL)
#define ETMR_FM_CMP_CENTER_ALIGN_CE_SEL (0xffU << 0U)
#define ETMR_FV_CMP_CENTER_ALIGN_CE_SEL(v)                                     \
    (((v) << 0U) & ETMR_FM_CMP_CENTER_ALIGN_CE_SEL)

#define ETMR_CMP_FAULT_EVENT_STA_OFF 0x450
#endif

/* sdrv etimer source */
typedef enum {
    SDRV_ETIMR_HF_CLK = 0,
    SDRV_ETIMR_AHF_CLK,
    SDRV_ETIMR_EXT_CLK,
    SDRV_ETIMR_LP_CLK,
} sdrv_etimer_clk_src_e;

typedef enum {
    SDRV_ETIMR_CLK_MON_ENABLE = 5,
    SDRV_ETIMR_CLK_MON_DISABLE
} sdrv_etimer_clk_mon_en_e;

typedef enum {
    SDRV_ETIMR_CNT_G0,
    SDRV_ETIMR_CNT_G1,
    SDRV_ETIMR_LCNT_A,
    SDRV_ETIMR_LCNT_B,
    SDRV_ETIMR_LCNT_C,
    SDRV_ETIMR_LCNT_D,
    SDRV_ETIMR_CNT_NUM
} sdrv_etimer_cnt_id_e;

typedef enum {
    SDRV_ETIMR_RESET_EVENT_NONE,
    SDRV_ETIMR_RESET_EVENT_CPT0,
    SDRV_ETIMR_RESET_EVENT_CPT1,
    SDRV_ETIMR_RESET_EVENT_CPT0_CPT1
} sdrv_etimer_cnt_rst_e;

typedef enum {
    SDRV_ETIMR_LCNT_CPT_0_CLR,
    SDRV_ETIMR_LCNT_CPT_1_CLR
} sdrv_etimer_cpt_clr_e;

typedef enum {
    SDRV_ETIMR_CNT_CONSECTIVE,
    SDRV_ETIMR_CNT_ONE_SHOT
} sdrv_etimer_cnt_con_mode_e;

typedef enum {
    SDRV_ETIMR_CNT_IGNORE_CLR,
    SDRV_ETIMR_CNT_POSEDGE_CLR,
    SDRV_ETIMR_CNT_NEGEDGE_CLR,
    SDRV_ETIMR_CNT_HIGH_LEVEL_CLR
} sdrv_etimer_cnt_clr_trig_sel_e;

typedef enum {
    SDRV_ETIMR_CNT_NOUPDATE_UPD,
    SDRV_ETIMR_CNT_RLDOVF_UPD,
    SDRV_ETIMR_CNT_RLDINIT_UPD,
    SDRV_ETIMR_CNT_BOTHRLD_UPD
} sdrv_etimer_cnt_set_upd_sel_e;

typedef enum {
    SDRV_ETIMR_CNT_IGNORE_SET,
    SDRV_ETIMR_CNT_POSEDGE_SET,
    SDRV_ETIMR_CNT_NEGEDGE_SET,
    SDRV_ETIMR_CNT_HIGH_LEVEL_SET
} sdrv_etimer_cnt_set_trig_sel_e;

typedef enum {
    SDRV_ETIMR_CNT_POSEDGE_SIG,
    SDRV_ETIMR_CNT_NEGEDGE_SIG,
    SDRV_ETIMR_CNT_TOGGLE_SIG,
    SDRV_ETIMR_CNT_HIGH_LEVEL_SIG
} sdrv_etimer_cnt_sig_trig_sel_e;

typedef enum {
    SDRV_ETIMR_32_BIT_MODE,
    SDRV_ETIMR_16_BIT_MODE
} sdrv_etimer_bit_mode_e;

typedef enum {
    SDRV_ETIMR_CMP_BLOCK,
    SDRV_ETIMR_CPT_BLOCK,
    SDRV_ETIMR_DELAY_MODE
} sdrv_etimer_chn_block_e;

typedef enum {
    SDRV_ETIMR_CHN_A,
    SDRV_ETIMR_CHN_B,
    SDRV_ETIMR_CHN_C,
    SDRV_ETIMR_CHN_D,
    SDRV_ETIMR_CHN_NR
} sdrv_etimer_chn_id_e;

typedef enum {
    SDRV_ETIMR_DMA_TRIG_CMP_A = 0x1,
    SDRV_ETIMR_DMA_TRIG_CMP_B = 0x2,
    SDRV_ETIMR_DMA_TRIG_CMP_C = 0x4,
    SDRV_ETIMR_DMA_TRIG_CMP_D = 0x8,
    SDRV_ETIMR_DMA_TRIG_CPT_A = 0x10,
    SDRV_ETIMR_DMA_TRIG_CPT_B = 0x20,
    SDRV_ETIMR_DMA_TRIG_CPT_C = 0x40,
    SDRV_ETIMR_DMA_TRIG_CPT_D = 0x80,
    SDRV_ETIMR_DMA_TRIG_CNT_G0 = 0x100,
    SDRV_ETIMR_DMA_TRIG_CNT_G1 = 0x200,
    SDRV_ETIMR_DMA_TRIG_LCNT_A = 0x400,
    SDRV_ETIMR_DMA_TRIG_LCNT_B = 0x800,
    SDRV_ETIMR_DMA_TRIG_LCNT_C = 0x1000,
    SDRV_ETIMR_DMA_TRIG_LCNT_D = 0x2000
} sdrv_etimer_dma_trig_sel_e;

typedef enum {
    SDRV_ETIMR_POSITIVE_PULSE, // â†?
    SDRV_ETIMR_NEGATIVE_PULSE, // â†?
    SDRV_ETIMR_TOGGLE_SIG,
    SDRV_ETIMR_LEVEL_HIGH,
    SDRV_ETIMR_LEVEL_LOW,
    SDRV_ETIMR_KEEP
} sdrv_etimer_out_mode_e;

typedef enum {
    SDRV_ETIMR_CMP_00,
    SDRV_ETIMR_CMP_01,
    SDRV_ETIMR_CMP_10,
    SDRV_ETIMR_CMP_11
} sdrv_etimer_cmp_event_e;

typedef enum {
    SDRV_ETIMR_CMP_OUT_CMP0,
    SDRV_ETIMR_CMP_OUT_CMP0_CMP1
} sdrv_etimer_cmp_out_e;

typedef enum {
    SDRV_ETIMR_CMP_CONSECUTIVE,
    SDRV_ETIMR_CMP_ONE_SHOT
} sdrv_etimer_cmp_con_mode_e;

typedef enum {
    SDRV_ETIMR_CMP_SINGLE,
    SDRV_ETIMR_CMP_DUAL,
    SDRV_ETIMR_CMP_MULTI
} sdrv_etimer_cmp_mode_e;

typedef enum {
    SDRV_ETIMR_CMP_CNT_G0,
    SDRV_ETIMR_CMP_LCNT,
    SDRV_ETIMR_CMP_LCNT_D
} sdrv_etimer_cmp_cnt_sel_e;

typedef enum {
    SDRV_ETIMR_CMP_CE_CMP00,
    SDRV_ETIMR_CMP_CE_CMP01,
    SDRV_ETIMR_CMP_CE_CMP10,
    SDRV_ETIMR_CMP_CE_CMP11
} sdrv_etimer_cmp_ce_trig_e;

typedef enum {
    SDRV_ETIMR_CMP_IGNORE,
    SDRV_ETIMR_CMP_POSEDGE,
    SDRV_ETIMR_CMP_NEGEEDGE,
    SDRV_ETIMR_CMP_LEVEL_HIGH
} sdrv_etimer_cmp_event_trig_e;

typedef enum {
    SDRV_ETIMR_CMP_0_NO_CHANGE,
    SDRV_ETIMR_CMP_0_INVERT,
    SDRV_ETIMR_CMP_1_NO_CHANGE,
    SDRV_ETIMR_CMP_1_INVERT,
    SDRV_ETIMR_CMP_1_SAME_0,
    SDRV_ETIMR_CMP_1_INVERT_0
} sdrv_etimer_dti_ctrl_e;

typedef enum {
    SDRV_ETIMR_CMP_OUT_0,
    SDRV_ETIMR_CMP_OUT_1
} sdrv_etimer_cmp_group_e;

typedef enum {
    SDRV_ETIMR_CMP_FAULT0,
    SDRV_ETIMR_CMP_FAULT1,
    SDRV_ETIMR_CMP_FAULT2,
    SDRV_ETIMR_CMP_FAULT3
} sdrv_etimer_cmp_fault_e;

typedef enum {
    SDRV_ETIMR_TRIG_SEL_SET,
    SDRV_ETIMR_TRIG_SEL_CLR,
    SDRV_ETIMR_TRIG_SEL_SIG,
    SDRV_ETIMR_TRIG_SEL_DIR
} sdrv_etimer_trig_sel_e;

typedef enum {
    SDRV_ETIMR_TRIG_SEL_EXT_SET,
    SDRV_ETIMR_TRIG_SEL_EXT_CLR,
    SDRV_ETIMR_TRIG_SEL_CPT_A_SSE_SET_CLR,
    SDRV_ETIMR_TRIG_SEL_CPT_A_CE,
    SDRV_ETIMR_TRIG_SEL_CPT_B_CE,
    SDRV_ETIMR_TRIG_SEL_CPT_C_CE,
    SDRV_ETIMR_TRIG_SEL_CPT_D_CE,
    SDRV_ETIMR_TRIG_SEL_CNT_G0_CE,
    SDRV_ETIMR_TRIG_SEL_CMP_X_CE,
    /* X: A, B, C, D */
    SDRV_ETIMR_TRIG_SEL_LEVEL_LOW,
    SDRV_ETIMR_TRIG_SEL_LEVEL_HIGH,
    SDRV_ETIMR_TRIG_SEL_SW_PROGRAM_PULSE,
    SDRV_ETIMR_TRIG_SEL_SW_TRIG0,
    SDRV_ETIMR_TRIG_SEL_SW_TRIG1,
    SDRV_ETIMR_TRIG_SEL_SW_TRIG2,
    SDRV_ETIMR_TRIG_SEL_SW_TRIG3
} sdrv_etimer_trig_set_clr_e;

typedef enum {
    SDRV_ETIMR_OUT_SEL_EXT_SET,
    SDRV_ETIMR_OUT_SEL_EXT_CLR,
    SDRV_ETIMR_OUT_SEL_CPT_A_SSE_SET_CLR,
    SDRV_ETIMR_OUT_SEL_CPT_A_CE,
    SDRV_ETIMR_OUT_SEL_CPT_B_CE,
    SDRV_ETIMR_OUT_SEL_CPT_C_CE,
    SDRV_ETIMR_OUT_SEL_CPT_D_CE,
    SDRV_ETIMR_OUT_SEL_CNT_G0_CE,
    SDRV_ETIMR_OUT_SEL_CMP_G1_CE,
    SDRV_ETIMR_OUT_SEL_LEVEL_LOW,
    SDRV_ETIMR_OUT_SEL_LEVEL_HIGH,
    SDRV_ETIMR_OUT_SEL_SW_PROGRAM_PULSE,
    SDRV_ETIMR_OUT_SEL_SW_TRIG0,
    SDRV_ETIMR_OUT_SEL_SW_TRIG1,
    SDRV_ETIMR_OUT_SEL_SW_TRIG2,
    SDRV_ETIMR_OUT_SEL_SW_TRIG3
} sdrv_etimer_ext_out_set_clr_e;

typedef enum {
    SDRV_ETIMR_TRIG_SIG_CPT_X_SSE, /* X: A, B, C, D */
    SDRV_ETIMR_TRIG_SIG_CPT_X1,
    SDRV_ETIMR_TRIG_SIG_CMP_X1,
    SDRV_ETIMR_TRIG_SIG_CPT_A_CE,
    SDRV_ETIMR_TRIG_SIG_CPT_B_CE,
    SDRV_ETIMR_TRIG_SIG_CPT_C_CE,
    SDRV_ETIMR_TRIG_SIG_CPT_D_CE,
    SDRV_ETIMR_TRIG_SIG_CNT_G0_CE,
    SDRV_ETIMR_TRIG_SIG_CNT_G1_CE,
    SDRV_ETIMR_TRIG_SIG_LEVEL_LOW,
    SDRV_ETIMR_TRIG_SIG_LEVEL_HIGH,
    SDRV_ETIMR_TRIG_SIG_SW_PROGRAM_PULSE,
    SDRV_ETIMR_TRIG_SIG_SW_TRIG0,
    SDRV_ETIMR_TRIG_SIG_SW_TRIG1,
    SDRV_ETIMR_TRIG_SIG_SW_TRIG2,
    SDRV_ETIMR_TRIG_SIG_SW_TRIG3
} sdrv_etimer_trig_sig_e;

typedef enum {
    SDRV_ETIMR_TRIG_DIR_LEVEL_HIGH1,
    SDRV_ETIMR_TRIG_DIR_LEVEL_LOW,
    SDRV_ETIMR_TRIG_DIR_CPT_A_SSE_DIR,
    SDRV_ETIMR_TRIG_DIR_CPT_A_SSE,
    SDRV_ETIMR_TRIG_DIR_CPT_B_SSE,
    SDRV_ETIMR_TRIG_DIR_CPT_C_SSE,
    SDRV_ETIMR_TRIG_DIR_CPT_D_SSE,
    SDRV_ETIMR_TRIG_DIR_CPT_X1,
    /* X: A, B, C, D */
    SDRV_ETIMR_TRIG_DIR_CMP_X1,
    /* X: A, B, C, D */
    SDRV_ETIMR_TRIG_DIR_LEVEL_HIGH2,
    SDRV_ETIMR_TRIG_DIR_LEVEL_HIGH3,
    SDRV_ETIMR_TRIG_DIR_LEVEL_HIGH4,
    SDRV_ETIMR_TRIG_DIR_SW_TRIG0,
    SDRV_ETIMR_TRIG_DIR_SW_TRIG1,
    SDRV_ETIMR_TRIG_DIR_SW_TRIG2,
    SDRV_ETIMR_TRIG_DIR_SW_TRIG3
} sdrv_etimer_trig_dir_e;

typedef enum {
    SDRV_ETIMR_OUT_DIR_LEVEL_HIGH1,
    SDRV_ETIMR_OUT_DIR_LEVEL_LOW,
    SDRV_ETIMR_OUT_DIR_CPT_A_SSE_DIR,
    SDRV_ETIMR_OUT_DIR_CPT_A_SSE,
    SDRV_ETIMR_OUT_DIR_CPT_B_SSE,
    SDRV_ETIMR_OUT_DIR_CPT_C_SSE,
    SDRV_ETIMR_OUT_DIR_CPT_D_SSE,
    SDRV_ETIMR_OUT_DIR_CPT_A1,
    SDRV_ETIMR_OUT_DIR_CPT_B1,
    SDRV_ETIMR_OUT_DIR_CPT_C1,
    SDRV_ETIMR_OUT_DIR_CPT_D1,
    SDRV_ETIMR_OUT_DIR_CMP_A1,
    SDRV_ETIMR_OUT_DIR_SW_TRIG0,
    SDRV_ETIMR_OUT_DIR_SW_TRIG1,
    SDRV_ETIMR_OUT_DIR_SW_TRIG2,
    SDRV_ETIMR_OUT_DIR_SW_TRIG3
} sdrv_etimer_ext_out_dir_e;

typedef enum {
    SDRV_ETIMR_SSE_MODE_LEVEL,
    SDRV_ETIMR_SSE_MODE_EDGE
} sdrv_etimer_sse_mode_e;

typedef enum {
    SDRV_ETIMR_SSE_EDGE_RISING,
    SDRV_ETIMR_SSE_EDGE_FAILING,
    SDRV_ETIMR_SSE_EDGE_BOTH
} sdrv_etimer_sse_edge_e;

typedef enum {
    SDRV_ETIMR_CMP_FAULT_LEVEL_LOW,
    SDRV_ETIMR_CMP_FAULT_LEVEL_HIGH,
    SDRV_ETIMR_CMP_FAULT_EDGE_POS,
    SDRV_ETIMR_CMP_FAULT_EDGE_NEG,
    SDRV_ETIMR_CMP_FAULT_EDGE_BOTH
} sdrv_etimer_cmp_fault_det_e;

typedef enum {
    SDRV_ETIMR_CPT_CONSECTIVE,
    SDRV_ETIMR_CPT_ONE_SHOT
} sdrv_etimer_cpt_con_mode_e;

typedef enum {
    SDRV_ETIMR_CPT_CPT0,
    SDRV_ETIMR_CPT_CPT0_CPT1
} sdrv_etimer_cpt_dual_mode_e;

typedef enum {
    SDRV_ETIMR_CPT_RISE_EDGE,
    SDRV_ETIMR_CPT_FALL_EDGE,
    SDRV_ETIMR_CPT_BOTH_EDGE,
    SDRV_ETIMR_CPT_TRIG_IGNORE,
} sdrv_etimer_cpt_trig_mode_e;

typedef enum {
    SDRV_ETIMR_CPT_CNTG0,
    SDRV_ETIMR_CPT_CNTG0_CNTG1,
    SDRV_ETIMR_CPT_LCNT,
    SDRV_ETIMR_CPT_CNT_IGNORE
} sdrv_etimer_cpt_cnt_sel_e;

typedef enum {
    SDRV_ETIMR_CPT_CPT0_TRIG,
    SDRV_ETIMR_CPT_CPT1_TRIG,
    SDRV_ETIMR_CPT_BOTH_TRIG1
} sdrv_etimer_cpt_ce_trig_sel_e;

typedef enum {
    SDRV_ETIMR_FLT_POSEEDGE,
    SDRV_ETIMR_FLT_NEGEEDGE,
    SDRV_ETIMR_FLT_BOTHEDGE
} sdrv_etimer_flt_edge_e;

typedef enum {
    SDRV_ETIMR_FAULT_POL_HIGH,
    SDRV_ETIMR_FAULT_POL_LOW
} sdrv_etimer_cmp_fault_pol_e;

typedef enum {
    SDRV_ETIMR_FAULT_AUTO_CLR,
    SDRV_ETIMR_FAULT_STICKY
} sdrv_etimer_cmp_fault_mode_e;

typedef enum {
    SDRV_ETIMR_SW_TRIG0,
    SDRV_ETIMR_SW_TRIG1,
    SDRV_ETIMR_SW_TRIG2,
    SDRV_ETIMR_SW_TRIG3
} sdrv_etimer_sw_trig_sel_e;

typedef enum {
    SDRV_ETIMR_SW_TRIG_PULSE,
    SDRV_ETIMR_SW_TRIG_TOGGLE,
    SDRV_ETIMR_SW_TRIG_LOW,
    SDRV_ETIMR_SW_TRIG_HIGH
} sdrv_etimer_sw_trig_typr_e;

typedef enum {
    SDRV_ETIMR_SNAP_CNT_G0 = 0x1,
    SDRV_ETIMR_SNAP_CNT_G1 = 0x2,
    SDRV_ETIMR_SNAP_LCNT_A = 0x4,
    SDRV_ETIMR_SNAP_LCNT_B = 0x8,
    SDRV_ETIMR_SNAP_LCNT_C = 0x10,
    SDRV_ETIMR_SNAP_LCNT_D = 0x20,
    SDRV_ETIMR_SNAP_POSEDGE = 0x40
} sdrv_etimer_snap_src_e;

typedef enum {
    SDRV_ETIMR_QUAD_HOMEHIGH,
    SDRV_ETIMR_QUAD_IDXHIGH,
    SDRV_ETIMR_QUAD_HOMEHIGH_BLOW_ALOW,
    SDRV_ETIMR_QUAD_HOMEHIGH_BLOW_AHIGH,
    SDRV_ETIMR_QUAD_HOMEHIGH_BHIGH_ALOW,
    SDRV_ETIMR_QUAD_HOMEHIGH_BHIGH_AHIGH,
    SDRV_ETIMR_QUAD_IDXHIGH_BLOW_ALOW,
    SDRV_ETIMR_QUAD_IDXHIGH_BLOW_AHIGH,
    SDRV_ETIMR_QUAD_IDXHIGH_BHIGH_ALOW,
    SDRV_ETIMR_QUAD_IDXHIGH_BHIGH_AHIGH
} sdrv_etimer_quad_trig_e;

typedef enum {
    SDRV_ETIMR_QUAD_POL_KEEP,
    SDRV_ETIMR_QUAD_POL_CHANGE
} sdrv_etimer_quad_pol_e;

typedef enum {
    SDRV_ETIMR_1_CHN_INT = 199,
    SDRV_ETIMR_1_OVF_INT,
    SDRV_ETIMR_2_CHN_INT,
    SDRV_ETIMR_2_OVF_INT,
    SDRV_ETIMR_3_CHN_INT,
    SDRV_ETIMR_3_OVF_INT,
    SDRV_ETIMR_4_CHN_INT,
    SDRV_ETIMR_4_OVF_INT
} sdrv_etimer_irq_e;

typedef enum {
    SDRV_ETIMR_INT_CPT_A = 0x1,
    SDRV_ETIMR_INT_CPT_B = 0x2,
    SDRV_ETIMR_INT_CPT_C = 0x4,
    SDRV_ETIMR_INT_CPT_D = 0x8,
    SDRV_ETIMR_INT_CMP_A = 0x10,
    SDRV_ETIMR_INT_CMP_B = 0x20,
    SDRV_ETIMR_INT_CMP_C = 0x40,
    SDRV_ETIMR_INT_CMP_D = 0x80,
    SDRV_ETIMR_INT_CNT_G0_OVF = 0x100,
    SDRV_ETIMR_INT_CNT_G1_OVF = 0x200,
    SDRV_ETIMR_INT_LCNT_A_OVF = 0x400,
    SDRV_ETIMR_INT_LCNT_B_OVF = 0x800,
    SDRV_ETIMR_INT_LCNT_C_OVF = 0x1000,
    SDRV_ETIMR_INT_LCNT_D_OVF = 0x2000,
    SDRV_ETIMR_INT_CNT_G0_SNAP = 0x4000,
    SDRV_ETIMR_INT_CNT_G1_SNAP = 0x8000,
    SDRV_ETIMR_INT_LCNT_A_SNAP = 0x10000,
    SDRV_ETIMR_INT_LCNT_B_SNAP = 0x20000,
    SDRV_ETIMR_INT_LCNT_C_SNAP = 0x40000,
    SDRV_ETIMR_INT_LCNT_D_SNAP = 0x80000,
} sdrv_etimer_int_e;

#if SEMIDRIVE_E3_LITE_SERIES
typedef enum {
    SDRV_ETIMR_BOTH_OVF_UDR,
    SDRV_ETIMR_BOTH_OVF_UDR1,
    SDRV_ETIMR_ONLY_OVF,
    SDRV_ETIMR_ONLY_UDR
} sdrv_etimer_cen_ali_sel_e;

typedef enum {
    SDRV_ETIMR_TRIG_NONE,
    SDRV_ETIMR_TRIG_INC,
    SDRV_ETIMR_TRIG_DEC,
    SDRV_ETIMR_TRIG_INC_DEC
} sdrv_etimer_cmp_cen_irq_sel_e;
#endif

typedef struct clk_set {
    uint32 div_num;
    sdrv_etimer_clk_src_e src_clk_sel;
} clk_set_t;

typedef struct basic_cnt_config {
    bool frc_rld;
    sdrv_etimer_cnt_set_trig_sel_e set_trig_sel;
    sdrv_etimer_cnt_set_upd_sel_e set_upd_sel;
    sdrv_etimer_cnt_clr_trig_sel_e clr_trig_sel;
    bool ce_en;
    uint32 interval;
    sdrv_etimer_cnt_con_mode_e con_mode;
    bool ovf_rst_dis;
    bool cascade_mode;
} basic_cnt_config_t;

typedef struct local_cnt_config {
    bool frc_rld;
    sdrv_etimer_cnt_set_trig_sel_e set_trig_sel;
    sdrv_etimer_cnt_set_upd_sel_e set_upd_sel;
    sdrv_etimer_cnt_clr_trig_sel_e clr_trig_sel;
    bool ce_en;
    uint32 interval;
    sdrv_etimer_cnt_con_mode_e con_mode;
    bool no_stop_mode;
    uint32 no_stop_ovf_mode;
    sdrv_etimer_cnt_sig_trig_sel_e sig_trig_sel;
    bool cpt0_clr_en;
    bool cpt1_clr_en;
    bool start_by_first_cpt;
    bool sig_en;
    bool delta_time_en;
    bool ovf_rst_dis;
} local_cnt_config_t;

typedef struct sdrv_timer_sse_ctrl {
    sdrv_etimer_sse_mode_e sse_mode[5];
    sdrv_etimer_sse_edge_e edge_sel[5];
} sdrv_etimer_sse_ctrl_t;

typedef struct chn_etimer_dma_ctrl {
    uint32 chn_en;
    sdrv_etimer_chn_block_e block_sel;
    uint32 chn_sig_mask;
    sdrv_etimer_bit_mode_e bit_mode; /* compare mode only */
} chn_etimer_dma_ctrl_t;

typedef struct cmp_config {
    sdrv_etimer_cmp_out_e out_mode;
    sdrv_etimer_cmp_con_mode_e con_mode;
    sdrv_etimer_cmp_mode_e cmp_mode;
    sdrv_etimer_cmp_cnt_sel_e cnt_sel;
    sdrv_etimer_cmp_ce_trig_e ce_trig_sel;
    bool ce_en;
    uint32 hw_rld_mode;
    sdrv_etimer_cmp_event_trig_e set_trig_sel;
    sdrv_etimer_cmp_event_trig_e clr_trig_sel;
    uint32 rld_trig_mode;
    uint32 sw_rld_mode;
    uint32 ref_interval;
} cmp_config_t;

typedef struct cpt_config {
    sdrv_etimer_cpt_ce_trig_sel_e ce_trig_sel;
    bool ce_en;
    sdrv_etimer_cpt_cnt_sel_e cnt_sel;
    sdrv_etimer_cpt_trig_mode_e cpt1_trig_mode;
    sdrv_etimer_cpt_trig_mode_e cpt0_trig_mode;
    sdrv_etimer_cpt_dual_mode_e dual_mode;
    sdrv_etimer_cpt_con_mode_e con_mode;
} cpt_config_t;

typedef struct etimer_out_mode {
    sdrv_etimer_out_mode_e cmp_00_out;
    sdrv_etimer_out_mode_e cmp_01_out;
    sdrv_etimer_out_mode_e cmp_10_out;
    sdrv_etimer_out_mode_e cmp_11_out;
    sdrv_etimer_out_mode_e cmp_0_ovf_out;
    sdrv_etimer_out_mode_e cmp_1_ovf_out;
} etimer_cmp_event_mode_t;

typedef struct etimer_cmp_pulse_wid0 {

    uint32 cmp_00_pluse;
    uint32 cmp_01_pluse;
    uint32 cmp_10_pluse;
    uint32 cmp_11_pluse;
} etimer_cmp_pulse_wid0_t;

typedef struct etimer_cmp_pulse_wid1 {
    uint32 cmp_1_ovf_pluse;
    uint32 cmp_0_ovf_pluse;
} etimer_cmp_pulse_wid1_t;

typedef struct etimer_cmp_init_status {
    bool init_status_x0;
    bool init_status_x1;
} etimer_cmp_init_status_t;

typedef struct quad_ctrl {
    sdrv_etimer_quad_trig_e quad_set_sel;
    sdrv_etimer_quad_trig_e quad_clr_sel;
    sdrv_etimer_quad_pol_e quad_home_pol;
    sdrv_etimer_quad_pol_e quad_index_pol;
} quad_ctrl_t;

typedef struct flt_config {
    sdrv_etimer_flt_edge_e flt_edge_sel;
    uint32 pos_band_wid;
    uint32 neg_band_wid;
    uint32 sample_intval;
} flt_config_t;

typedef struct cmp_fault_ctrl {
    sdrv_etimer_cmp_fault_pol_e fault_pol;
    sdrv_etimer_cmp_fault_mode_e fault_clr_mode;
} cmp_fault_ctrl_t;

#if SEMIDRIVE_E3_LITE_SERIES
typedef struct cnt_center_align_config {
    sdrv_etimer_cen_ali_sel_e ovf_sel;
    sdrv_etimer_cen_ali_sel_e ce_sel;
} cnt_center_align_config_t;

typedef struct cmp_center_align_config {
    sdrv_etimer_cen_ali_sel_e rld_sel;
    sdrv_etimer_cmp_cen_irq_sel_e cmp11_irq;
    sdrv_etimer_cmp_cen_irq_sel_e cmp10_irq;
    sdrv_etimer_cmp_cen_irq_sel_e cmp01_irq;
    sdrv_etimer_cmp_cen_irq_sel_e cmp00_irq;
    uint8 ce_sel;
} cmp_center_align_config_t;
#endif

void sdrv_etimer_lld_clk_cfg(uint32 base, clk_set_t *cfg);

void sdrv_etimer_lld_clk_mon_en(uint32 base, bool enable);

void sdrv_etimer_lld_cnt_upd(uint32 base, sdrv_etimer_cnt_id_e cnt_x,
                             bool init_flag, bool ovf_flag);

void sdrv_etimer_lld_cnt_ovf(uint32 base, sdrv_etimer_cnt_id_e cnt_x,
                             uint32 val);

void sdrv_etimer_lld_lcnt_cpt_clr_en(uint32 base, sdrv_etimer_cnt_id_e cnt_x,
                                     sdrv_etimer_cpt_clr_e cpt_event,
                                     bool enable);

void sdrv_etimer_lld_cnt_init(uint32 base, sdrv_etimer_cnt_id_e cnt_x,
                              uint32 val);

void sdrv_etimer_lld_cnt_en(uint32 base, sdrv_etimer_cnt_id_e cnt_x,
                            bool enable);

uint32 sdrv_etimer_lld_get_cnt_value(uint32 base,
                                       sdrv_etimer_cnt_id_e cnt_x);

void sdrv_etimer_lld_cnt_frc_rld(uint32 base, sdrv_etimer_cnt_id_e cnt_x);

void sdrv_etimer_lld_basic_cnt_cfg(uint32 base, sdrv_etimer_cnt_id_e cnt_x,
                                   basic_cnt_config_t *cfg);

void sdrv_etimer_lld_local_cnt_cfg(uint32 base, sdrv_etimer_cnt_id_e cnt_x,
                                   local_cnt_config_t *cfg);

void sdrv_etimer_lld_int_en(uint32 base, uint32 bit_mask, bool enable);

void sdrv_etimer_lld_int_enable(uint32 base, uint32 int_sel);

void sdrv_etimer_lld_cor_int_enable(uint32 base, uint32 int_sel);

void sdrv_etimer_lld_unc_int_enable(uint32 base, uint32 int_sel);

uint32 sdrv_etimer_lld_get_int_status(uint32 base);

void sdrv_etimer_lld_clear_int_status(uint32 base, uint32 int_sta);

uint32 sdrv_etimer_lld_get_cor_int_status(uint32 base);

void sdrv_etimer_lld_clear_cor_int_status(uint32 base, uint32 int_sta);

uint32 sdrv_etimer_lld_get_unc_int_status(uint32 base);

void sdrv_etimer_lld_clear_unc_int_status(uint32 base, uint32 int_sta);

void sdrv_etimer_lld_dma_chn_cfg(uint32 base, sdrv_etimer_chn_id_e ch,
                                 chn_etimer_dma_ctrl_t *config);

void sdrv_etimer_lld_dma_wml(uint32 base, sdrv_etimer_chn_id_e chn,
                             uint32 value);

void sdrv_etimer_lld_config_dma_ctrl(uint32 base, uint32 trig_sel);

void sdrv_etimer_lld_out_mode(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                              etimer_cmp_event_mode_t *mode);

void sdrv_etimer_lld_cmp_val(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                             sdrv_etimer_cmp_event_e group, uint32 val);

void sdrv_etimer_lld_cmp_pulse_wid0_set(uint32 base,
                                        sdrv_etimer_chn_id_e etimer_id,
                                        etimer_cmp_pulse_wid0_t *wid0);

void sdrv_etimer_lld_cmp_pulse_wid1_set(uint32 base,
                                        sdrv_etimer_chn_id_e etimer_id,
                                        etimer_cmp_pulse_wid1_t *wid1);

void sdrv_etimer_lld_cmp_val_upd(uint32 base, sdrv_etimer_chn_id_e etimer_id);

void sdrv_etimer_lld_cmp_init_status(uint32 base,
                                     sdrv_etimer_chn_id_e etimer_id,
                                     etimer_cmp_init_status_t *init_sta);

void sdrv_etimer_lld_cmp_cfg(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                             cmp_config_t *cfg);

uint32 sdrv_etimer_lld_get_cmp_mode(uint32 base,
                                      sdrv_etimer_chn_id_e etimer_id);

void sdrv_etimer_lld_cmp_sw_rld(uint32 base, sdrv_etimer_chn_id_e etimer_id);

void sdrv_etimer_lld_cmp_en(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                            bool enable);

void sdrv_etimer_lld_cmp_config_set(uint32 base,
                                    sdrv_etimer_chn_id_e etimer_id);

void sdrv_etimer_lld_cpt_cfg(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                             cpt_config_t *cfg);

void sdrv_etimer_lld_cpt_config_set(uint32 base,
                                    sdrv_etimer_chn_id_e etimer_id);

void sdrv_etimer_lld_cpt_en(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                            bool enable);

void sdrv_etimer_lld_dti_ctrl_cfg(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                                  sdrv_etimer_dti_ctrl_e ctrl_mode);

void sdrv_etimer_lld_dti_wid(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                             uint16 wid0, uint16 wid1);

void sdrv_etimer_lld_dti_ctrl_en(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                                 bool enable);

void sdrv_etimer_lld_fs_status_set(uint32 base,
                                   sdrv_etimer_chn_id_e etimer_id,
                                   sdrv_etimer_cmp_group_e group, bool enable);

void sdrv_etimer_lld_cmp_input_sel(uint32 base,
                                   sdrv_etimer_chn_id_e etimer_id,
                                   sdrv_etimer_trig_sel_e sel,
                                   sdrv_etimer_trig_set_clr_e val);

void sdrv_etimer_lld_cnt_input_sel(uint32 base, sdrv_etimer_cnt_id_e cnt_x,
                                   sdrv_etimer_trig_sel_e sel,
                                   sdrv_etimer_trig_set_clr_e val);

void sdrv_etimer_lld_cpt_input_set_clr_sel(uint32 base,
                                           sdrv_etimer_chn_id_e etimer_id,
                                           sdrv_etimer_trig_sel_e sel,
                                           sdrv_etimer_trig_set_clr_e val);

void sdrv_etimer_lld_cpt_input_sig_sel(uint32 base,
                                       sdrv_etimer_chn_id_e etimer_id,
                                       sdrv_etimer_trig_sel_e sel,
                                       sdrv_etimer_trig_sig_e val);

void sdrv_etimer_lld_cpt_input_dir_sel(uint32 base,
                                       sdrv_etimer_chn_id_e etimer_id,
                                       sdrv_etimer_trig_sel_e sel,
                                       sdrv_etimer_trig_dir_e val);

void sdrv_etimer_lld_cnt_trig_gen(uint32 base, uint32 trigger);

void sdrv_etimer_lld_sw_trig_ctrl(uint32 base,
                                  sdrv_etimer_sw_trig_sel_e trig_sel,
                                  sdrv_etimer_sw_trig_typr_e trig_type);

void sdrv_etimer_lld_sw_trig_pulse(uint32 base,
                                   sdrv_etimer_sw_trig_sel_e trig_sel,
                                   uint32 value);

void sdrv_etimer_lld_cmp_sse_ctrl(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                                  const sdrv_etimer_sse_ctrl_t *cfg);

void sdrv_etimer_lld_cmp_sse_en(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                                bool enable);

void sdrv_etimer_lld_cmp_sse_val(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                                 uint32 value);

void sdrv_etimer_lld_cpt_sse_ctrl(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                                  const sdrv_etimer_sse_ctrl_t *cfg);

void sdrv_etimer_lld_cpt_quad_ctrl(uint32 base, quad_ctrl_t *quad_ctrl);

void sdrv_etimer_lld_cpt_quad_en(uint32 base, bool enable);

void sdrv_etimer_lld_cpt_sse_en(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                                bool enable);

void sdrv_etimer_lld_cpt_sse_val(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                                 uint32 value);

void sdrv_etimer_lld_cpt_flt_cfg(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                                 flt_config_t *cfg);

void sdrv_etimer_lld_cpt_flt_en(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                                bool enable);

void sdrv_etimer_lld_fault_flt_cfg(uint32 base,
                                   sdrv_etimer_chn_id_e etimer_id,
                                   flt_config_t *cfg);

void sdrv_etimer_lld_fault_flt_en(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                                  bool enable);

void sdrv_etimer_lld_cnt_snap_shot(uint32 base, sdrv_etimer_cnt_id_e cnt_x,
                                   uint32 val);

void sdrv_etimer_lld_output_snap_shot(uint32 base, uint32 val);

void sdrv_etimer_lld_cmp_fault_ctrl(uint32 base,
                                    sdrv_etimer_chn_id_e etimer_id,
                                    sdrv_etimer_cmp_fault_e fault_idx,
                                    cmp_fault_ctrl_t *cfg);

void sdrv_etimer_lld_cmp_fault_en(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                                  sdrv_etimer_cmp_fault_e fault_idx,
                                  bool enable);

void sdrv_etimer_lld_cmp_fault_clr(uint32 base,
                                   sdrv_etimer_chn_id_e etimer_id,
                                   sdrv_etimer_cmp_fault_e fault_idx);

void sdrv_etimer_lld_cmp_offset(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                                uint32 val);

void sdrv_etimer_lld_sw_rst(uint32 base, uint32 val);

uint32 sdrv_etimer_lld_get_fifo_req_sta(uint32 base);

uint32 sdrv_etimer_lld_get_fifo_val(uint32 base,
                                      sdrv_etimer_chn_id_e etimer_id);

uint32 sdrv_etimer_lld_get_fifo_sta(uint32 base);

void sdrv_etimer_lld_clear_fifo(uint32 base, sdrv_etimer_chn_id_e etimer_id);

uint32 sdrv_etimer_lld_get_cpt0_cnt0(uint32 base,
                                       sdrv_etimer_chn_id_e etimer_id);

uint32 sdrv_etimer_lld_get_cpt0_cnt1(uint32 base,
                                       sdrv_etimer_chn_id_e etimer_id);

uint32 sdrv_etimer_lld_get_cpt1_cnt0(uint32 base,
                                       sdrv_etimer_chn_id_e etimer_id);

uint32 sdrv_etimer_lld_get_cpt1_cnt1(uint32 base,
                                       sdrv_etimer_chn_id_e etimer_id);

void sdrv_etimer_lld_lcnt_sig_en(uint32 base, sdrv_etimer_cnt_id_e cnt_x,
                                 bool enable);

void sdrv_etimer_lld_cmp_trig_cfg(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                                  sdrv_etimer_trig_sel_e sel,
                                  sdrv_etimer_cmp_event_trig_e val);

void sdrv_etimer_lld_lcnt_trig_cfg(uint32 base, sdrv_etimer_cnt_id_e cnt_x,
                                   sdrv_etimer_trig_sel_e sel,
                                   sdrv_etimer_cmp_event_trig_e val);

void sdrv_etimer_lld_lcnt_ovf_rst_en(uint32 base, sdrv_etimer_cnt_id_e cnt_x,
                                     bool enable);

void sdrv_etimer_lld_cpt_trig_cfg(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                                  sdrv_etimer_trig_sel_e sel,
                                  sdrv_etimer_cmp_event_trig_e val);

void sdrv_etimer_lld_cmp_eid(uint32 base, sdrv_etimer_cmp_event_e cmp_event,
                             uint32 val);

void sdrv_etimer_lld_cmp_eid_upd(uint32 base);

void sdrv_etimer_lld_set_sync_dis(uint32 base, uint32 val);

void sdrv_etimer_lld_ext_output_dir_sel(uint32 base,
                                        sdrv_etimer_trig_sel_e sel,
                                        sdrv_etimer_ext_out_dir_e val);

void sdrv_etimer_lld_ext_output_set_clr_sel(uint32 base,
                                            sdrv_etimer_trig_sel_e sel,
                                            sdrv_etimer_ext_out_set_clr_e val);

uint32 sdrv_etimer_lld_get_sig_status(uint32 base);

void sdrv_etimer_lld_set_self_test(uint32 base, bool enable);

void sdrv_etimer_lld_cmp_fault_det_en(uint32 base,
                                      sdrv_etimer_chn_id_e etimer_id,
                                      bool enable);

void sdrv_etimer_lld_cmp_fault_det_set(uint32 base,
                                       sdrv_etimer_chn_id_e etimer_id,
                                       sdrv_etimer_cmp_fault_det_e fault_det);

uint32 sdrv_etimer_lld_get_fusa_cor_int_status(uint32 base);

void sdrv_etimer_lld_clear_fusa_cor_int_status(uint32 base, uint32 int_sta);

uint32 sdrv_etimer_lld_get_fusa_unc_int_status(uint32 base);

void sdrv_etimer_lld_clear_fusa_unc_int_status(uint32 base, uint32 int_sta);

void sdrv_etimer_lld_cmp_dti_cbc(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                                 bool enable);

void sdrv_etimer_lld_cmp_dti_zero_vector(uint32 base,
                                         sdrv_etimer_chn_id_e etimer_id,
                                         bool enable);

#if SEMIDRIVE_E3_LITE_SERIES
void sdrv_etimer_lld_cnt_center_align_en(uint32 base,
                                         sdrv_etimer_cnt_id_e cnt_x,
                                         bool enable);

void sdrv_etimer_lld_cnt_center_align_cfg(uint32 base,
                                          sdrv_etimer_cnt_id_e cnt_x,
                                          cnt_center_align_config_t *cfg);

void sdrv_etimer_lld_cmp_center_align_en(uint32 base,
                                         sdrv_etimer_chn_id_e etimer_id,
                                         bool enable);

void sdrv_etimer_lld_cmp_center_align_cfg(uint32 base,
                                          sdrv_etimer_chn_id_e etimer_id,
                                          cmp_center_align_config_t *cfg);

uint32 sdrv_etimer_lld_get_cmp_fault_sta(uint32 base);

void sdrv_etimer_lld_cmp_frc_idle(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                                  sdrv_etimer_cmp_group_e group, bool enable);

void sdrv_etimer_lld_cmp_sw_trig_idle(uint32 base,
                                      sdrv_etimer_chn_id_e etimer_id,
                                      bool enable);

void sdrv_etimer_lld_cmp_cen_ali_int_enable(uint32 base, uint32 int_sel);

uint32 sdrv_etimer_lld_get_cmp_cen_ali_int_status(uint32 base);

void sdrv_etimer_lld_clear_cmp_cen_ali_int_status(uint32 base,
                                                  uint32 int_sta);

#endif

__END_CDECLS

#endif

#endif
