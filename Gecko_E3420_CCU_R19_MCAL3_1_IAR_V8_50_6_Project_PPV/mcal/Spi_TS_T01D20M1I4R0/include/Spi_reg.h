/** **************************************************************************************
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
 * an 'AS IS' basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.
 *
 *****************************************************************************************/
/** **************************************************************************************
 *  \file     Spi_reg.h
 *  \brief    This file contains interface header for CAN MCAL driver
 *
 * <table>
 * <tr><th>Date           <th>Version
 * <tr><td>2023/07/27     <td>1.0.0
 * </table>
 *****************************************************************************************/

/* Generated by tool. Do not modify manually. */

#ifndef SPI_REG_H
#define SPI_REG_H

#define SPI_CTRL_OFF    0x0U

#define BM_SPI_CTRL_SW_RST  ((uint32)0x01U << 31U)

#define FM_SPI_CTRL_IDLE    ((uint32)0x1fU << 25U)
#define FV_SPI_CTRL_IDLE(v) \
    (((uint32)(v) << 25U) & FM_SPI_CTRL_IDLE)
#define GFV_SPI_CTRL_IDLE(v) \
    (((uint32)(v) & FM_SPI_CTRL_IDLE) >> 25U)

#define BM_SPI_CTRL_SAMPLE_POINT    ((uint32)0x01U << 24U)

#define FM_SPI_CTRL_TIMEOUT ((uint32)0x1fU << 16U)
#define FV_SPI_CTRL_TIMEOUT(v) \
    (((uint32)(v) << 16U) & FM_SPI_CTRL_TIMEOUT)
#define GFV_SPI_CTRL_TIMEOUT(v) \
    (((uint32)(v) & FM_SPI_CTRL_TIMEOUT) >> 16U)

#define FM_SPI_CTRL_NSS_POL ((uint32)0xfU << 8U)
#define FV_SPI_CTRL_NSS_POL(v) \
    (((uint32)(v) << 8U) & FM_SPI_CTRL_NSS_POL)
#define GFV_SPI_CTRL_NSS_POL(v) \
    (((uint32)(v) & FM_SPI_CTRL_NSS_POL) >> 8U)

#define BM_SPI_CTRL_SSP_CLK_MODE    ((uint32)0x01U << 6U)

#define BM_SPI_CTRL_RX_DMA_EN   ((uint32)0x01U << 5U)

#define BM_SPI_CTRL_TX_DMA_EN   ((uint32)0x01U << 4U)

#define BM_SPI_CTRL_SLV_MODE    ((uint32)0x01U << 3U)

#define BM_SPI_CTRL_HALF_MODE   ((uint32)0x01U << 2U)

#define BM_SPI_CTRL_SLV_UNS_SIZE_EN ((uint32)0x01U << 1U)

#define BM_SPI_CTRL_MODE    ((uint32)0x01U << 0U)

#define SPI_TIM_CTRL_OFF    0x4U

#define FM_SPI_TIM_CTRL_FRM_DLY ((uint32)0xffU << 16U)
#define FV_SPI_TIM_CTRL_FRM_DLY(v) \
    (((uint32)(v) << 16U) & FM_SPI_TIM_CTRL_FRM_DLY)
#define GFV_SPI_TIM_CTRL_FRM_DLY(v) \
    (((uint32)(v) & FM_SPI_TIM_CTRL_FRM_DLY) >> 16U)

#define FM_SPI_TIM_CTRL_END_DLY ((uint32)0xffU << 8U)
#define FV_SPI_TIM_CTRL_END_DLY(v) \
    (((uint32)(v) << 8U) & FM_SPI_TIM_CTRL_END_DLY)
#define GFV_SPI_TIM_CTRL_END_DLY(v) \
    (((uint32)(v) & FM_SPI_TIM_CTRL_END_DLY) >> 8U)

#define FM_SPI_TIM_CTRL_START_DLY   ((uint32)0xffU << 0U)
#define FV_SPI_TIM_CTRL_START_DLY(v) \
    (((uint32)(v) << 0U) & FM_SPI_TIM_CTRL_START_DLY)
#define GFV_SPI_TIM_CTRL_START_DLY(v) \
    (((uint32)(v) & FM_SPI_TIM_CTRL_START_DLY) >> 0U)

#define SPI_EN_OFF  0x8U

#define BM_SPI_EN_ENABLE    ((uint32)0x01U << 0U)

#define SPI_CMD_CTRL_OFF    0x10U

#define FM_SPI_CMD_CTRL_PRESSCALE   ((uint32)0xffU << 24U)
#define FV_SPI_CMD_CTRL_PRESSCALE(v) \
    (((uint32)(v) << 24U) & FM_SPI_CMD_CTRL_PRESSCALE)
#define GFV_SPI_CMD_CTRL_PRESSCALE(v) \
    (((uint32)(v) & FM_SPI_CMD_CTRL_PRESSCALE) >> 24U)

#define BM_SPI_CMD_CTRL_TX_MASK ((uint32)0x01U << 23U)

#define BM_SPI_CMD_CTRL_RX_MASK ((uint32)0x01U << 22U)

#define FM_SPI_CMD_CTRL_FRAM_SIZE   ((uint32)0x3ffU << 12U)
#define FV_SPI_CMD_CTRL_FRAM_SIZE(v) \
    (((uint32)(v) << 12U) & FM_SPI_CMD_CTRL_FRAM_SIZE)
#define GFV_SPI_CMD_CTRL_FRAM_SIZE(v) \
    (((uint32)(v) & FM_SPI_CMD_CTRL_FRAM_SIZE) >> 12U)

#define FM_SPI_CMD_CTRL_WORD_SIZE   ((uint32)0x1fU << 7U)
#define FV_SPI_CMD_CTRL_WORD_SIZE(v) \
    (((uint32)(v) << 7U) & FM_SPI_CMD_CTRL_WORD_SIZE)
#define GFV_SPI_CMD_CTRL_WORD_SIZE(v) \
    (((uint32)(v) & FM_SPI_CMD_CTRL_WORD_SIZE) >> 7U)

#define BM_SPI_CMD_CTRL_SPI_CPHA    ((uint32)0x01U << 6U)

#define BM_SPI_CMD_CTRL_SPI_CPOL    ((uint32)0x01U << 5U)

#define BM_SPI_CMD_CTRL_LAST    ((uint32)0x01U << 4U)

#define BM_SPI_CMD_CTRL_SWAP    ((uint32)0x01U << 3U)

#define BM_SPI_CMD_CTRL_LSB ((uint32)0x01U << 2U)

#define FM_SPI_CMD_CTRL_NSS ((uint32)0x3U << 0U)
#define FV_SPI_CMD_CTRL_NSS(v) \
    (((uint32)(v) << 0U) & FM_SPI_CMD_CTRL_NSS)
#define GFV_SPI_CMD_CTRL_NSS(v) \
    (((uint32)(v) & FM_SPI_CMD_CTRL_NSS) >> 0U)

#define SPI_IRQ_MASK_OFF    0x20U

#define BM_SPI_IRQ_MASK_MST_FRM_END ((uint32)0x01U << 14U)

#define BM_SPI_IRQ_MASK_SLV_NSS_INVLD   ((uint32)0x01U << 13U)

#define BM_SPI_IRQ_MASK_SLV_NSS_VLD ((uint32)0x01U << 12U)

#define BM_SPI_IRQ_MASK_IDLE    ((uint32)0x01U << 11U)

#define BM_SPI_IRQ_MASK_TIMEOUT ((uint32)0x01U << 10U)

#define BM_SPI_IRQ_MASK_TRANS_DONE  ((uint32)0x01U << 9U)

#define BM_SPI_IRQ_MASK_FRM_DONE    ((uint32)0x01U << 8U)

#define BM_SPI_IRQ_MASK_RX_FIFO_PRE_FULL    ((uint32)0x01U << 7U)

#define BM_SPI_IRQ_MASK_TX_FIFO_PRE_EMPTY   ((uint32)0x01U << 6U)

#define BM_SPI_IRQ_MASK_RX_FIFO_OVR ((uint32)0x01U << 5U)

#define BM_SPI_IRQ_MASK_RX_FIFO_FULL    ((uint32)0x01U << 4U)

#define BM_SPI_IRQ_MASK_RX_FIFO_EMPTY   ((uint32)0x01U << 3U)

#define BM_SPI_IRQ_MASK_TX_FIFO_UDR ((uint32)0x01U << 2U)

#define BM_SPI_IRQ_MASK_TX_FIFO_FULL    ((uint32)0x01U << 1U)

#define BM_SPI_IRQ_MASK_TX_FIFO_EMPTY   ((uint32)0x01U << 0U)

#define SPI_IRQ_STAT_OFF    0x24U

#define FM_SPI_IRQ_STAT_SPI_FSM_ST  ((uint32)0xfU << 28U)
#define FV_SPI_IRQ_STAT_SPI_FSM_ST(v) \
    (((uint32)(v) << 28U) & FM_SPI_IRQ_STAT_SPI_FSM_ST)
#define GFV_SPI_IRQ_STAT_SPI_FSM_ST(v) \
    (((uint32)(v) & FM_SPI_IRQ_STAT_SPI_FSM_ST) >> 28U)

#define BM_SPI_IRQ_STAT_MST_FRM_END ((uint32)0x01U << 14U)

#define BM_SPI_IRQ_STAT_SLV_NSS_INVLD   ((uint32)0x01U << 13U)

#define BM_SPI_IRQ_STAT_SLV_NSS_VLD ((uint32)0x01U << 12U)

#define BM_SPI_IRQ_STAT_IDLE    ((uint32)0x01U << 11U)

#define BM_SPI_IRQ_STAT_TIMEOUT ((uint32)0x01U << 10U)

#define BM_SPI_IRQ_STAT_TRANS_DONE  ((uint32)0x01U << 9U)

#define BM_SPI_IRQ_STAT_FRM_DONE    ((uint32)0x01U << 8U)

#define BM_SPI_IRQ_STAT_RX_FIFO_PRE_FULL    ((uint32)0x01U << 7U)

#define BM_SPI_IRQ_STAT_TX_FIFO_PRE_EMPTY   ((uint32)0x01U << 6U)

#define BM_SPI_IRQ_STAT_RX_FIFO_OVR ((uint32)0x01U << 5U)

#define BM_SPI_IRQ_STAT_RX_FIFO_FULL    ((uint32)0x01U << 4U)

#define BM_SPI_IRQ_STAT_RX_FIFO_EMPTY   ((uint32)0x01U << 3U)

#define BM_SPI_IRQ_STAT_TX_FIFO_UDR ((uint32)0x01U << 2U)

#define BM_SPI_IRQ_STAT_TX_FIFO_FULL    ((uint32)0x01U << 1U)

#define BM_SPI_IRQ_STAT_TX_FIFO_EMPTY   ((uint32)0x01U << 0U)

#define SPI_FIFO_STAT_OFF   0x30U

#define BM_SPI_FIFO_STAT_RX_FULL    ((uint32)0x01U << 25U)

#define BM_SPI_FIFO_STAT_RX_EMPTY   ((uint32)0x01U << 24U)

#define FM_SPI_FIFO_STAT_RX_FIFO_DPTR   ((uint32)0x1fU << 16U)
#define FV_SPI_FIFO_STAT_RX_FIFO_DPTR(v) \
    (((uint32)(v) << 16U) & FM_SPI_FIFO_STAT_RX_FIFO_DPTR)
#define GFV_SPI_FIFO_STAT_RX_FIFO_DPTR(v) \
    (((uint32)(v) & FM_SPI_FIFO_STAT_RX_FIFO_DPTR) >> 16U)

#define BM_SPI_FIFO_STAT_TX_FULL    ((uint32)0x01U << 9U)

#define BM_SPI_FIFO_STAT_TX_EMPTY   ((uint32)0x01U << 8U)

#define FM_SPI_FIFO_STAT_TX_FIFO_DPTR   ((uint32)0x1fU << 0U)
#define FV_SPI_FIFO_STAT_TX_FIFO_DPTR(v) \
    (((uint32)(v) << 0U) & FM_SPI_FIFO_STAT_TX_FIFO_DPTR)
#define GFV_SPI_FIFO_STAT_TX_FIFO_DPTR(v) \
    (((uint32)(v) & FM_SPI_FIFO_STAT_TX_FIFO_DPTR) >> 0U)

#define SPI_TX_FIFO_CTRL_OFF    0x34U

#define FM_SPI_TX_FIFO_CTRL_THRD    ((uint32)0xfU << 0U)
#define FV_SPI_TX_FIFO_CTRL_THRD(v) \
    (((uint32)(v) << 0U) & FM_SPI_TX_FIFO_CTRL_THRD)
#define GFV_SPI_TX_FIFO_CTRL_THRD(v) \
    (((uint32)(v) & FM_SPI_TX_FIFO_CTRL_THRD) >> 0U)

#define SPI_RX_FIFO_CTRL_OFF    0x38U

#define FM_SPI_RX_FIFO_CTRL_THRD    ((uint32)0xfU << 0U)
#define FV_SPI_RX_FIFO_CTRL_THRD(v) \
    (((uint32)(v) << 0U) & FM_SPI_RX_FIFO_CTRL_THRD)
#define GFV_SPI_RX_FIFO_CTRL_THRD(v) \
    (((uint32)(v) & FM_SPI_RX_FIFO_CTRL_THRD) >> 0U)

#define REG_PARITY_ERR_INT_STAT_OFF 0x40U

#define BM_REG_PARITY_ERR_INT_STAT_REG_PARITY_ERR   ((uint32)0x01U << 0U)

#define REG_PARITY_ERR_INT_SIG_EN_OFF   0x44U

#define BM_REG_PARITY_ERR_INT_SIG_EN_REG_PARITY_ERR ((uint32)0x01U << 0U)

#define FUSA_UNC_ERR_IRQ_STAT_OFF   0x48U

#define BM_FUSA_UNC_ERR_IRQ_STAT_RX_DMA_EOBA_POL_ERR    ((uint32)0x01U << 13U)

#define BM_FUSA_UNC_ERR_IRQ_STAT_RX_DMA_EOBC_POL_ERR    ((uint32)0x01U << 12U)

#define BM_FUSA_UNC_ERR_IRQ_STAT_RX_DMA_BW_FATAL_ERR    ((uint32)0x01U << 11U)

#define BM_FUSA_UNC_ERR_IRQ_STAT_RX_DMA_BW_UNC_ERR  ((uint32)0x01U << 10U)

#define BM_FUSA_UNC_ERR_IRQ_STAT_TX_DMA_EOBA_POL_ERR    ((uint32)0x01U << 9U)

#define BM_FUSA_UNC_ERR_IRQ_STAT_TX_DMA_EOBC_POL_ERR    ((uint32)0x01U << 8U)

#define BM_FUSA_UNC_ERR_IRQ_STAT_TX_DMA_BW_FATAL_ERR    ((uint32)0x01U << 7U)

#define BM_FUSA_UNC_ERR_IRQ_STAT_TX_DMA_BW_UNC_ERR  ((uint32)0x01U << 6U)

#define BM_FUSA_UNC_ERR_IRQ_STAT_ERR_INJ_EN_ERR ((uint32)0x01U << 5U)

#define BM_FUSA_UNC_ERR_IRQ_STAT_REG_PARITY_ERR_INJ_EN_ERR  ((uint32)0x01U << 4U)

#define BM_FUSA_UNC_ERR_IRQ_STAT_PCTL_UNC_ERR   ((uint32)0x01U << 3U)

#define BM_FUSA_UNC_ERR_IRQ_STAT_PADDR_UNC_ERR  ((uint32)0x01U << 2U)

#define BM_FUSA_UNC_ERR_IRQ_STAT_PWDATA_FATAL_ERR   ((uint32)0x01U << 1U)

#define BM_FUSA_UNC_ERR_IRQ_STAT_PWDATA_UNC_ERR ((uint32)0x01U << 0U)

#define FUSA_UNC_ERR_IRQ_MASK_OFF   0x4cU

#define BM_FUSA_UNC_ERR_IRQ_MASK_RX_DMA_EOBA_POL_ERR    ((uint32)0x01U << 13U)

#define BM_FUSA_UNC_ERR_IRQ_MASK_RX_DMA_EOBC_POL_ERR    ((uint32)0x01U << 12U)

#define BM_FUSA_UNC_ERR_IRQ_MASK_RX_DMA_BW_FATAL_ERR    ((uint32)0x01U << 11U)

#define BM_FUSA_UNC_ERR_IRQ_MASK_RX_DMA_BW_UNC_ERR  ((uint32)0x01U << 10U)

#define BM_FUSA_UNC_ERR_IRQ_MASK_TX_DMA_EOBA_POL_ERR    ((uint32)0x01U << 9U)

#define BM_FUSA_UNC_ERR_IRQ_MASK_TX_DMA_EOBC_POL_ERR    ((uint32)0x01U << 8U)

#define BM_FUSA_UNC_ERR_IRQ_MASK_TX_DMA_BW_FATAL_ERR    ((uint32)0x01U << 7U)

#define BM_FUSA_UNC_ERR_IRQ_MASK_TX_DMA_BW_UNC_ERR  ((uint32)0x01U << 6U)

#define BM_FUSA_UNC_ERR_IRQ_MASK_ERR_INJ_EN_ERR ((uint32)0x01U << 5U)

#define BM_FUSA_UNC_ERR_IRQ_MASK_REG_PARITY_ERR_INJ_EN_ERR  ((uint32)0x01U << 4U)

#define BM_FUSA_UNC_ERR_IRQ_MASK_PCTL_UNC_ERR   ((uint32)0x01U << 3U)

#define BM_FUSA_UNC_ERR_IRQ_MASK_PADDR_UNC_ERR  ((uint32)0x01U << 2U)

#define BM_FUSA_UNC_ERR_IRQ_MASK_PWDATA_FATAL_ERR   ((uint32)0x01U << 1U)

#define BM_FUSA_UNC_ERR_IRQ_MASK_PWDATA_UNC_ERR ((uint32)0x01U << 0U)

#define FUSA_COR_ERR_IRQ_STAT_OFF   0x50U

#define BM_FUSA_COR_ERR_IRQ_STAT_RX_DMA_BW_COR_ERR  ((uint32)0x01U << 2U)

#define BM_FUSA_COR_ERR_IRQ_STAT_TX_DMA_BW_COR_ERR  ((uint32)0x01U << 1U)

#define BM_FUSA_COR_ERR_IRQ_STAT_PWDATA_COR_ERR ((uint32)0x01U << 0U)

#define FUSA_COR_ERR_IRQ_MASK_OFF   0x54U

#define BM_FUSA_COR_ERR_IRQ_MASK_RX_DMA_BW_COR_ERR  ((uint32)0x01U << 2U)

#define BM_FUSA_COR_ERR_IRQ_MASK_TX_DMA_BW_COR_ERR  ((uint32)0x01U << 1U)

#define BM_FUSA_COR_ERR_IRQ_MASK_PWDATA_COR_ERR ((uint32)0x01U << 0U)

#define PWDATA_INJ_OFF  0x58U

#define FM_PWDATA_INJ_DATA_INJ  ((uint32)0xffffffffU << 0U)
#define FV_PWDATA_INJ_DATA_INJ(v) \
    (((uint32)(v) << 0U) & FM_PWDATA_INJ_DATA_INJ)
#define GFV_PWDATA_INJ_DATA_INJ(v) \
    (((uint32)(v) & FM_PWDATA_INJ_DATA_INJ) >> 0U)

#define PWECC_INJ_OFF   0x5cU

#define FM_PWECC_INJ_ECC_INJ    ((uint32)0x7fU << 0U)
#define FV_PWECC_INJ_ECC_INJ(v) \
    (((uint32)(v) << 0U) & FM_PWECC_INJ_ECC_INJ)
#define GFV_PWECC_INJ_ECC_INJ(v) \
    (((uint32)(v) & FM_PWECC_INJ_ECC_INJ) >> 0U)

#define PRDATAINJ_OFF   0x60U

#define BM_PRDATAINJ_DATA_INJ   ((uint32)0x01U << 0U)

#define INT_ERR_INJ_OFF 0x64U

#define BM_INT_ERR_INJ_UNC_ERR  ((uint32)0x01U << 2U)

#define BM_INT_ERR_INJ_COR_ERR  ((uint32)0x01U << 1U)

#define BM_INT_ERR_INJ_FUN_IRQ  ((uint32)0x01U << 0U)

#define DMA_INJ_OFF 0x68U

#define FM_DMA_INJ_RX_FW_DATA_INJ   ((uint32)0xfU << 28U)
#define FV_DMA_INJ_RX_FW_DATA_INJ(v) \
    (((uint32)(v) << 28U) & FM_DMA_INJ_RX_FW_DATA_INJ)
#define GFV_DMA_INJ_RX_FW_DATA_INJ(v) \
    (((uint32)(v) & FM_DMA_INJ_RX_FW_DATA_INJ) >> 28U)

#define FM_DMA_INJ_RX_FW_CODE_INJ   ((uint32)0xfU << 24U)
#define FV_DMA_INJ_RX_FW_CODE_INJ(v) \
    (((uint32)(v) << 24U) & FM_DMA_INJ_RX_FW_CODE_INJ)
#define GFV_DMA_INJ_RX_FW_CODE_INJ(v) \
    (((uint32)(v) & FM_DMA_INJ_RX_FW_CODE_INJ) >> 24U)

#define FM_DMA_INJ_RX_BW_DATA_INJ   ((uint32)0xfU << 20U)
#define FV_DMA_INJ_RX_BW_DATA_INJ(v) \
    (((uint32)(v) << 20U) & FM_DMA_INJ_RX_BW_DATA_INJ)
#define GFV_DMA_INJ_RX_BW_DATA_INJ(v) \
    (((uint32)(v) & FM_DMA_INJ_RX_BW_DATA_INJ) >> 20U)

#define FM_DMA_INJ_RX_BW_CODE_INJ   ((uint32)0xfU << 16U)
#define FV_DMA_INJ_RX_BW_CODE_INJ(v) \
    (((uint32)(v) << 16U) & FM_DMA_INJ_RX_BW_CODE_INJ)
#define GFV_DMA_INJ_RX_BW_CODE_INJ(v) \
    (((uint32)(v) & FM_DMA_INJ_RX_BW_CODE_INJ) >> 16U)

#define FM_DMA_INJ_TX_FW_DATA_INJ   ((uint32)0xfU << 12U)
#define FV_DMA_INJ_TX_FW_DATA_INJ(v) \
    (((uint32)(v) << 12U) & FM_DMA_INJ_TX_FW_DATA_INJ)
#define GFV_DMA_INJ_TX_FW_DATA_INJ(v) \
    (((uint32)(v) & FM_DMA_INJ_TX_FW_DATA_INJ) >> 12U)

#define FM_DMA_INJ_TX_FW_CODE_INJ   ((uint32)0xfU << 8U)
#define FV_DMA_INJ_TX_FW_CODE_INJ(v) \
    (((uint32)(v) << 8U) & FM_DMA_INJ_TX_FW_CODE_INJ)
#define GFV_DMA_INJ_TX_FW_CODE_INJ(v) \
    (((uint32)(v) & FM_DMA_INJ_TX_FW_CODE_INJ) >> 8U)

#define FM_DMA_INJ_TX_BW_DATA_INJ   ((uint32)0xfU << 4U)
#define FV_DMA_INJ_TX_BW_DATA_INJ(v) \
    (((uint32)(v) << 4U) & FM_DMA_INJ_TX_BW_DATA_INJ)
#define GFV_DMA_INJ_TX_BW_DATA_INJ(v) \
    (((uint32)(v) & FM_DMA_INJ_TX_BW_DATA_INJ) >> 4U)

#define FM_DMA_INJ_TX_BW_CODE_INJ   ((uint32)0xfU << 0U)
#define FV_DMA_INJ_TX_BW_CODE_INJ(v) \
    (((uint32)(v) << 0U) & FM_DMA_INJ_TX_BW_CODE_INJ)
#define GFV_DMA_INJ_TX_BW_CODE_INJ(v) \
    (((uint32)(v) & FM_DMA_INJ_TX_BW_CODE_INJ) >> 0U)

#define SELFTEST_MODE_OFF   0x80U

#define BM_SELFTEST_MODE_EN ((uint32)0x01U << 0U)

#define SPI_TX_FIFO_CMD_OFF 0x1000U

#define SPI_TX_FIFO_DATA_OFF    0x2000U

#define SPI_RX_FIFO_DATA_OFF    0x3000U


#endif  /** SPI_REG_H */
/** End of file */
