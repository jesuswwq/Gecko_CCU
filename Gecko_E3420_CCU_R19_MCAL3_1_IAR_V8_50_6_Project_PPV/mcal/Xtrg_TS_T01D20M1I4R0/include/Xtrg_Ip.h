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
 *  \file     Xtrg_Ip.h
 *  \brief    This file contains interface header for CAN MCAL driver, ...
 *
 * <table>
 * <tr><th>Date           <th>Version
 * <tr><td>2023/08/04     <td>1.0.0
 * </table>
 *****************************************************************************************/

#ifndef XTRG_IP_H
#define XTRG_IP_H
#ifdef __cplusplus
extern "C" {
#endif
/*****************************************************************************************
 *                       Include header files
 *****************************************************************************************/
#include "Xtrg_Types.h"
#include "Mcal.h"
/*****************************************************************************************
 *                         Private Macro definition
 *****************************************************************************************/
/** \brief  XTRG base address */
#define XTRG_REG_BASE (0xf0410000UL)
/** \brief  XTRG api related register base,related start bit and bit width */
/** \brief  XTRG bit set */
#define XTRG_BIT_ENABLE (0x1U)
/** \brief  XTRG bit reset */
#define XTRG_BIT_DISABLE (0x0U)
/** \brief  XTRG interrupt status register */
#define XTRG_FUNC_INT_STA (0x0U)
/** \brief  XTRG interrupt status enable register */
#define XTRG_FUNC_INT_STA_EN (0x4U)
/** \brief  XTRG interrupt signal enable register */
#define XTRG_FUNC_INT_SIG_EN (0x8U)
/** \brief  XTRG interrupt start bit of all valid interrupt bits in
 * Xtrg driver */
#define XTRG_FUN_INT_START_BIT (16U)
/** \brief  XTRG all interrupt bits set status */
#define XTRG_FUN_INT_ALL_BIT_SET (0xFFU)
/** \brief  XTRG each interrupt event costs one bit */
#define XTRG_FUN_INT_EACH_BITWIDTH (0x1U)
/** \brief  XTRG io filter related register and bits */
#define XTRG_IO_FLAT(io) (0x210U + ((io)*4U))
#define XTRG_IO_FLAT_SMPL_INTVAL_START_BIT (12U)
#define XTRG_IO_FLAT_NEG_BAND_WID_START_BIT (8U)
#define XTRG_IO_FLAT_POS_BAND_WID_START_BIT (4U)
#define XTRG_IO_FLAT_FLT_EDGE_SEL_START_BIT (1U)
/** \brief  XTRG software trigger related register and bits */
#define XTRG_SW_TRG_CTRL (0xC00U)
/** \brief  XTRG each software trigger controller costs four bits */
#define XTRG_SW_TRG_BITWIDTH_EACH (4U)
/** \brief  XTRG software trigger status related register and bits */
#define XTRG_SW_TRG_STATUS (0xC04U)
/** \brief  XTRG software trigger width related register and bits */
#define XTRG_SW_TRG_PULSE_WIDTH(swt) (0xC10U + (((swt) / 2U) * 4U))
/** \brief  XTRG software trigger width bit width for each swt trigger */
#define XTRG_SW_TRG_PULSE_BITWIDTH_EACH (16U)
/** \brief  XTRG software trigger start bit for each swt trigger */
#define XTRG_SW_TRG_PULSE_START_BIT(swt) (((swt) % 2U) * 16U)
/** \brief  XTRG signal matrix first four input sinals related register and bits */
#define XTRG_SSE_IN_0_3_SEL(sse) (0x310U + (0x10U * (sse)))
/** \brief  XTRG signal matrix first four input sinals each input costs eight bits */
#define XTRG_SSE_IN_BIT_WIDTH  8U
/** \brief  XTRG signal matrix fifth input sinal related register and bits */
#define XTRG_SSE_IN_4_SEL(sse) (XTRG_SSE_IN_0_3_SEL(sse) + 0x4U)
/* XTRG signal matrix truth table related register and bits */
#define XTRG_SSE_REG(sse) (XTRG_SSE_IN_0_3_SEL(sse) + 0x8U)
/* XTRG signal matrix ctrl related register and bits */
#define XTRG_SSE_CTRL(sse) (XTRG_SSE_IN_0_3_SEL(sse) + 0xcU)
#define XTRG_SSE_CTRL_SSE_MODE_START_BIT 1U
#define XTRG_SSE_CTRL_SSE_EDGE_SEL_START_BIT 6U
#define XTRG_SSE_CTRL_SSE_EDGE_SEL_BITWIDTH_EACH 2U
#define XTRG_SSE_CTRL_BIT_START 0U
#define XTRG_SSE_CTRL_ENABLE_BIT_WIDTH 1U
#define XTRG_SSE_CTRL_BIT_WIDTH 16U
/* XTRG signal mutiplex related register and bits */
#define XTRG_SIG_O_SEL(sig_o) (0x410U + ((sig_o)*4U))
#define XTRG_IO_O_SEL(io_o) (0x540U + ((io_o)*4U))
/* XTRG io signal related register and bits */
#define XTRG_IO_OUT_EN(io_o) (0x670U + (((io_o) / 32U) * 4U))
#define XTRG_IO_OUT_REGISTER_BITWIDTH 32U
#define XTRG_IO_OUT_EACH_BIT_WIDTH 1U

/* XTRG synchronization signal related register and bits */
#define XTRG_SYNC_O_SEL(sync_o) (0x680U + ((sync_o)*4U))

/* XTRG direct tmux trigger related register and bits */
#define XTRG_TMUX0_DRT_CTRL(drt_id) (0x6d0U + ((drt_id)*0x18U))
#define XTRG_TMUX0_DRT_CTRL_TID_SEL_START_BIT (0U)
#define XTRG_TMUX0_DRT_CTRL_TID_SEL_BITWIDTH (3U)
#define XTRG_TMUX0_DRT_CTRL_TRG_SEL_START_BIT (3U)
#define XTRG_TMUX0_DRT_CTRL_TRG_SEL_BITWIDTH (5U)

/* XTRG direct tmux trigger target_lut related register and bits */
#define XTRG_TMUX0_DRT_DECODE_SEL(drt_id, sel) (XTRG_TMUX0_DRT_CTRL(drt_id) + ((sel)*4U))
#define XTRG_TMUX0_DRT_DECODE_CNT_EACH_REG 4U
#define XTRG_TMUX0_DRT_DECODE_CNT_TOTAL 8U
#define XTRG_TMUX0_DRT_DECODE_BITWIDTH_EACH 8U
#define XTRG_TMUX0_DRT_DECODE_REG1 1U
#define XTRG_TMUX0_DRT_DECODE_REG2 2U

/* XTRG indirect tmux trigger related register and bits */
#define XTRG_TMUX0_INDRT_CTRL(drt_id) (0x790U + ((drt_id)*0x28U))
#define XTRG_TMUX0_INDRT_CTRL_TRG_SEL_START_BIT (3U)
#define XTRG_TMUX0_INDRT_CTRL_TREM_TID_START_BIT (16U)

/* XTRG indirect tmux trigger target_lut related register and bits */
#define XTRG_TMUX0_INDRT_DECODE_SEL(drt_id, sel) (XTRG_TMUX0_INDRT_CTRL(drt_id) + ((sel)*4U))
#define XTRG_TMUX0_INDRT_DECODE_CNT_EACH_REG 4U
#define XTRG_TMUX0_INDRT_DECODE_CNT_TOTAL 8U
#define XTRG_TMUX0_INDRT_DECODE_BITWIDTH_EACH 8U
#define XTRG_TMUX0_INDRT_DECODE_REG1 1U
#define XTRG_TMUX0_INDRT_DECODE_REG2 2U

/* XTRG indirect tmux trigger tid_pool related register and bits */
#define XTRG_TMUX0_INDRT_TID_POOL(drt_id, sel)  (XTRG_TMUX0_INDRT_CTRL(drt_id) + ((sel)*4U) + 0x8U)
#define XTRG_TMUX0_INDRT_TID_POOL_TARGET_START_BIT 5U
#define XTRG_TMUX0_INDRT_TID_POOL_CNT_EACH_REG 4U
#define XTRG_TMUX0_INDRT_TID_POOL_CNT_TOTAL 8U
#define XTRG_TMUX0_INDRT_TID_POOL_BITWIDTH_EACH 8U
#define XTRG_TMUX0_INDRT_TID_POOL_REG1 1U
#define XTRG_TMUX0_INDRT_TID_POOL_REG2 2U

/* XTRG drt/indrt tmux enable related register and bits */
#define XTRG_TMUX_DEC_EN (0x8D0U)
#define XTRG_TMUX_DEC_EN_INDRT_START_BIT (8U)
#define XTRG_TMUX_DEC_EN_EACH_TMUX_BITWIDTH (1U)

/* XTRG drt/indrt trigger adc timeout related register and bits */
#define XTRG_TMUX_DONE_MON_CNT (0x8E0U)
#define XTRG_TMUX_DONE_MON_CNT_CONFIG_START_BIT (0U)
#define XTRG_TMUX_DONE_MON_CNT_CONFIG_BITWIDTH (8U)
#define XTRG_TMUX_DONE_MON_CNT_MAX_VALUE (0xFFU)
/* Xtrg direct tmux priority related register and bits */
#define XTRG_TMUX_ARB_CTRL0 (0x8F0U)
#define XTRG_TMUX_ARB_CTRL0_TMUX0_START_BIT (0U)
#define XTRG_TMUX_ARB_CTRL0_TMUX1_START_BIT (4U)
#define XTRG_TMUX_ARB_CTRL0_TMUX2_START_BIT (8U)
#define XTRG_TMUX_ARB_CTRL0_TMUX3_START_BIT (12U)
#define XTRG_TMUX_ARB_CTRL0_TMUX4_START_BIT (16U)
#define XTRG_TMUX_ARB_CTRL0_TMUX5_START_BIT (20U)
#define XTRG_TMUX_ARB_CTRL0_TMUX6_START_BIT (24U)
#define XTRG_TMUX_ARB_CTRL0_TMUX7_START_BIT (28U)
#define XTRG_TMUX_ARB_CTRL0_EACH_TMUX_BITWIDTH (4U)
/* Xtrg indirect tmux priority related register and bits */
#define XTRG_TMUX_ARB_CTRL1 (0x8F4U)
#define XTRG_TMUX_ARB_CTRL1_TMUX0_START_BIT (0U)
#define XTRG_TMUX_ARB_CTRL1_TMUX1_START_BIT (4U)
#define XTRG_TMUX_ARB_CTRL1_TMUX2_START_BIT (8U)
#define XTRG_TMUX_ARB_CTRL1_TMUX3_START_BIT (12U)
#define XTRG_TMUX_ARB_CTRL1_TMUX4_START_BIT (16U)
#define XTRG_TMUX_ARB_CTRL1_TMUX5_START_BIT (20U)
#define XTRG_TMUX_ARB_CTRL1_TMUX6_START_BIT (24U)
#define XTRG_TMUX_ARB_CTRL1_TMUX7_START_BIT (28U)
#define XTRG_TMUX_ARB_CTRL1_EACH_TMUX_BITWIDTH (4U)
/** \brief  XTRG interrupt event count */
#define XTRG_TMUX_ADC_RSLT(adc_id, tmux_id) (0xE00U + ((adc_id)*4U) + ((tmux_id)*0xCU))
/** \brief  XTRG interrupt event count */
#define XTRG_INT_NUMBER (8U)
/** \brief Marco for Xtrg software trigger signal input group */
#define  XTRG_SWT_INPUT_GROUP 0UL
/** \brief Marco for Xtrg trigger signal input group */
#define  XTRG_TRG_INPUT_GROUP 1UL
/** \brief Marco for Xtrg normal signal input group */
#define  XTRG_SIG_INPUT_GROUP 2UL
/** \brief Marco for Xtrg synchronization signal input group */
#define  XTRG_SYNC_INPUT_GROUP 3UL
/** \brief Marco for Xtrg I/O signal input group */
#define  XTRG_IO_INPUT_GROUP 4UL
/** \brief Marco for Xtrg trigger id signal input group */
#define  XTRG_TID_INPUT_GROUP 5UL
/** \brief Marco for Xtrg normal signal output group */
#define  XTRG_SIG_OUTPUT_GROUP 6UL
/** \brief Marco for Xtrg I/O signal output group */
#define  XTRG_IO_OUTPUT_GROUP 7UL
/** \brief Marco for Xtrg synchronization signal output group */
#define XTRG_SYNC_OUTPUT_GROUP 8UL
/** \brief Marco for Xtrg signal matrix signal output group */
#define XTRG_SSIG_OUTPUT_GROUP 9UL



/** \brief Marco for Xtrg signal */

/** \brief Marco for move the flag for the group category 28 bits to the left */
#define XTRG_SIGNAL_GROUP_SHIFT 28U
/** \brief Marco for get the flag for the group category */
#define XTRG_SIGNAL_GROUP_INDEX(SIG) ((SIG) >> XTRG_SIGNAL_GROUP_SHIFT)
/** \brief Marco for Xtrg signal index without group category */
/** Traceability     :*/
#define XTRG_SIGNAL_WITHOUT_GROUP_INDEX(SIG) ((SIG)&0x0FFFFFFFUL)


#ifndef SEMIDRIVE_E3_LITE_SERIES
/** \brief Marco for Xtrg software trigger input signal group start */
#define SWT_I_START ((uint32)((uint32)XTRG_SWT_INPUT_GROUP << XTRG_SIGNAL_GROUP_SHIFT))
/** \brief Marco for the total number of signals in Xtrg software trigger input signal group */
#define SWT_I_NUMBER 8UL

/** \brief Marco for Xtrg trigger input signal group start */
#define TRG_I_START ((uint32)((uint32)XTRG_TRG_INPUT_GROUP << XTRG_SIGNAL_GROUP_SHIFT))
/** \brief Marco for the total number of signals in Xtrg trigger input signal group */
#define TRG_I_NUMBER 8UL

/** \brief Marco for Xtrg normal input signal group start */
#define SIG_I_START ((uint32)((uint32)XTRG_SIG_INPUT_GROUP << XTRG_SIGNAL_GROUP_SHIFT))
/** \brief Marco for the total number of signals in Xtrg normal input signal group */
#define SIG_I_NUMBER 68UL

/** \brief Marco for Xtrg sync input signal group start */
#define SYNC_I_START ((uint32)((uint32)XTRG_SYNC_INPUT_GROUP << XTRG_SIGNAL_GROUP_SHIFT))
/** \brief Marco for the total number of signals in Xtrg sync input signal group */
#define SYNC_I_NUMBER 20UL

/** \brief Marco for Xtrg i/o input signal group start */
#define IO_I_START ((uint32)((uint32)XTRG_IO_INPUT_GROUP << XTRG_SIGNAL_GROUP_SHIFT))
/** \brief Marco for the total number of signals in Xtrg i/o input signal group */
#define IO_I_NUMBER 64UL

/** \brief Marco for Xtrg trigger id input signal group start */
#define TID_I_START ((uint32)((uint32)XTRG_TID_INPUT_GROUP << XTRG_SIGNAL_GROUP_SHIFT))
/** \brief Marco for the total number of signals in Xtrg trigger id input signal group */
#define TID_I_NUMBER 64UL

/** \brief Marco for Xtrg normal output signal group start */
#define SIG_O_START ((uint32)((uint32)XTRG_SIG_OUTPUT_GROUP << XTRG_SIGNAL_GROUP_SHIFT))
/** \brief Marco for the total number of signals in Xtrg normal output signal group */
#define SIG_O_NUMBER 76UL

/** \brief Marco for Xtrg i/o output signal group start */
#define IO_O_START ((uint32)((uint32)XTRG_IO_OUTPUT_GROUP << XTRG_SIGNAL_GROUP_SHIFT))
/** \brief Marco for the total number of signals in Xtrg i/o output signal group */
#define IO_O_NUMBER 64UL

/** \brief Marco for Xtrg sync output signal group start */
#define SYNC_O_START ((uint32)((uint32)XTRG_SYNC_OUTPUT_GROUP << XTRG_SIGNAL_GROUP_SHIFT))
/** \brief Marco for the total number of signals in Xtrg sync output signal group */
#define SYNC_O_NUMBER 20UL

/** \brief Marco for Xtrg signal martrix output signal group start */
#define SSIG_START ((uint32)((uint32)XTRG_SSIG_OUTPUT_GROUP << XTRG_SIGNAL_GROUP_SHIFT))
/** \brief Marco for the total number of signals in Xtrg signal martrix output signal group */
#define SSIG_NUMBER 16UL

/** \brief Marco for the SWT_i group */
#define XTRG_SWT(swt) (SWT_I_START + (swt))
/** \brief Marco for the SIG_i group */
#define ETIMER_CMP_A1(ETMR_ID) (SIG_I_START + (7UL * (ETMR_ID)) + 0U)
#define ETIMER_CMP_B0(ETMR_ID) (SIG_I_START + (7U * (ETMR_ID)) + 1U)
#define ETIMER_CMP_B1(ETMR_ID) (SIG_I_START + (7U * (ETMR_ID)) + 2U)
#define ETIMER_CMP_C0(ETMR_ID) (SIG_I_START + (7U * (ETMR_ID)) + 3U)
#define ETIMER_CMP_C1(ETMR_ID) (SIG_I_START + (7U * (ETMR_ID)) + 4U)
#define ETIMER_CMP_D0(ETMR_ID) (SIG_I_START + (7U * (ETMR_ID)) + 5U)
#define ETIMER_CMP_D1(ETMR_ID) (SIG_I_START + (7U * (ETMR_ID)) + 6U)
#define ETIMER_DIR(ETMR_ID) (SIG_I_START + 28U + (ETMR_ID))
#define EPWM_CMP_A1(EPWM_ID) (SIG_I_START + 32U + (7U * (EPWM_ID)) + 0U)
#define EPWM_CMP_B0(EPWM_ID) (SIG_I_START + 32U + (7U * (EPWM_ID)) + 1U)
#define EPWM_CMP_B1(EPWM_ID) (SIG_I_START + 32U + (7U * (EPWM_ID)) + 2U)
#define EPWM_CMP_C0(EPWM_ID) (SIG_I_START + 32U + (7U * (EPWM_ID)) + 3U)
#define EPWM_CMP_C1(EPWM_ID) (SIG_I_START + 32U + (7U * (EPWM_ID)) + 4U)
#define EPWM_CMP_D0(EPWM_ID) (SIG_I_START + 32U + (7U * (EPWM_ID)) + 5U)
#define EPWM_CMP_D1(EPWM_ID) (SIG_I_START + 32U + (7U * (EPWM_ID)) + 6U)
#define ADC_DONE(ADC_ID) (SIG_I_START + 60U + (ADC_ID))
/** \brief Marco for the SYNC_i group */
#define ETIMER_SNAP_SHOT_I(ETMR_ID) (SYNC_I_START + (ETMR_ID))
#define ETIMER_SET_I(ETMR_ID) (SYNC_I_START + 4U + (ETMR_ID))
#define ETIMER_CLR_I(ETMR_ID) (SYNC_I_START + 8U + (ETMR_ID))
#define EPWM_SET_I(EPWM_ID) (SYNC_I_START + 12U + (EPWM_ID))
#define EPWM_CLR_I(EPWM_ID) (SYNC_I_START + 16U + (EPWM_ID))
/** \brief Marco for the TRG_i group */
#define ETIMER_CMP_A0(ETMR_ID) (TRG_I_START + (ETMR_ID))
#define EPWM_CMP_A0(EPWM_ID) (TRG_I_START + 4U + (EPWM_ID))
/** \brief Marco for the IO_I group */
#define IO_I(IO) (IO_I_START + (IO))
/** \brief Marco for the TID_i group */
#define ETIMER_EID(ETMR) (TID_I_START + ((ETMR)*8U))
#define EPWM_EID(EPWM) (TID_I_START + 32U + ((EPWM)*8U))
/** \brief Marco for the SIG_o group */
#define ETIMER_CPT0(ETMR, CHNL) (SIG_O_START + ((ETMR) * 8U) + (CHNL))
#define ETIMER_FAULT(ETMR, CHNL) (SIG_O_START + 32U + ((ETMR)*4U) + (CHNL))
#define ETIMER_CLK(ETMR) (SIG_O_START + 48U + (ETMR))
#define EPWM_FAULT(EPWM, CHNL) (SIG_O_START + 52U + ((EPWM)*4U) + (CHNL))
#define EPWM_CLK(EPWM) (SIG_O_START + 68U + (EPWM))
/** \brief Marco for the IO_O group */
#define IO_O(IO) (IO_O_START + (IO))
/** \brief Marco for the SYNC_o group */
#define ETIMER_SNAP_SHOT_O(ETMR) (SYNC_O_START + (ETMR))
#define ETIMER_SET_O(ETMR) (SYNC_O_START + 4U + (ETMR))
#define ETIMER_CLR_O(ETMR) (SYNC_O_START + 8U + (ETMR))
#define EPWM_SET_O(EPWM) (SYNC_O_START + 12U + (EPWM))
#define EPWM_CLR_O(EPWM) (SYNC_O_START + 16U + (EPWM))
/** \brief Marco for the SSIG group */
#define SSIG(SSIG_INPUT) (SSIG_START + (SSIG_INPUT))

#else
/** \brief Marco for Xtrg software trigger input signal group start */
#define SWT_I_START ((uint32)((uint32)XTRG_SWT_INPUT_GROUP << XTRG_SIGNAL_GROUP_SHIFT))
/** \brief Marco for the total number of signals in Xtrg software trigger input signal group */
#define SWT_I_NUMBER 8UL
/** \brief Marco for Xtrg trigger input signal group start */
#define TRG_I_START ((uint32)((uint32)XTRG_TRG_INPUT_GROUP << XTRG_SIGNAL_GROUP_SHIFT))
/** \brief Marco for the total number of signals in Xtrg trigger input signal group */
#define TRG_I_NUMBER 4UL
/** \brief Marco for Xtrg normal input signal group start */
#define SIG_I_START ((uint32)((uint32)XTRG_SIG_INPUT_GROUP << XTRG_SIGNAL_GROUP_SHIFT))
/** \brief Marco for the total number of signals in Xtrg normal input signal group */
#define SIG_I_NUMBER 38UL
/** \brief Marco for Xtrg sync input signal group start */
#define SYNC_I_START ((uint32)((uint32)XTRG_SYNC_INPUT_GROUP << XTRG_SIGNAL_GROUP_SHIFT))
/** \brief Marco for the total number of signals in Xtrg sync input signal group */
#define SYNC_I_NUMBER 10UL
/** \brief Marco for Xtrg i/o input signal group start */
#define IO_I_START ((uint32)((uint32)XTRG_IO_INPUT_GROUP << XTRG_SIGNAL_GROUP_SHIFT))
/** \brief Marco for the total number of signals in Xtrg i/o input signal group */
#define IO_I_NUMBER 64UL
/** \brief Marco for Xtrg trigger id input signal group start */
#define TID_I_START ((uint32)((uint32)XTRG_TID_INPUT_GROUP << XTRG_SIGNAL_GROUP_SHIFT))
/** \brief Marco for the total number of signals in Xtrg trigger id input signal group */
#define TID_I_NUMBER 32UL
/** \brief Marco for Xtrg normal output signal group start */
#define SIG_O_START ((uint32)((uint32)XTRG_SIG_OUTPUT_GROUP << XTRG_SIGNAL_GROUP_SHIFT))
/** \brief Marco for the total number of signals in Xtrg normal output signal group */
#define SIG_O_NUMBER 40UL
/** \brief Marco for Xtrg i/o output signal group start */
#define IO_O_START ((uint32)((uint32)XTRG_IO_OUTPUT_GROUP << XTRG_SIGNAL_GROUP_SHIFT))
/** \brief Marco for the total number of signals in Xtrg i/o output signal group */
#define IO_O_NUMBER 64UL
/** \brief Marco for Xtrg sync output signal group start */
#define SYNC_O_START ((uint32)((uint32)XTRG_SYNC_OUTPUT_GROUP << XTRG_SIGNAL_GROUP_SHIFT))
/** \brief Marco for the total number of signals in Xtrg sync output signal group */
#define SYNC_O_NUMBER 10UL
/** \brief Marco for Xtrg signal martrix output signal group start */
#define SSIG_START ((uint32)((uint32)XTRG_SSIG_OUTPUT_GROUP << XTRG_SIGNAL_GROUP_SHIFT))
/** \brief Marco for the total number of signals in Xtrg signal martrix output signal group */
#define SSIG_NUMBER 16UL


/** \brief Marco for the SWT_i group */
#define XTRG_SWT(swt) (SWT_I_START + (swt))
/** \brief Marco for the SIG_i group */
#define ETIMER_CMP_A1(ETMR_ID) (SIG_I_START + (7U * (ETMR_ID)) + 0U)
#define ETIMER_CMP_B0(ETMR_ID) (SIG_I_START + (7U * (ETMR_ID)) + 1U)
#define ETIMER_CMP_B1(ETMR_ID) (SIG_I_START + (7U * (ETMR_ID)) + 2U)
#define ETIMER_CMP_C0(ETMR_ID) (SIG_I_START + (7U * (ETMR_ID)) + 3U)
#define ETIMER_CMP_C1(ETMR_ID) (SIG_I_START + (7U * (ETMR_ID)) + 4U)
#define ETIMER_CMP_D0(ETMR_ID) (SIG_I_START + (7U * (ETMR_ID)) + 5U)
#define ETIMER_CMP_D1(ETMR_ID) (SIG_I_START + (7U * (ETMR_ID)) + 6U)
#define ETIMER_DIR(ETMR_ID) (SIG_I_START + 14U + (ETMR_ID))
#define EPWM_CMP_A1(EPWM_ID) (SIG_I_START + 16U + (7U * (EPWM_ID)) + 0U)
#define EPWM_CMP_B0(EPWM_ID) (SIG_I_START + 16U + (7U * (EPWM_ID)) + 1U)
#define EPWM_CMP_B1(EPWM_ID) (SIG_I_START + 16U + (7U * (EPWM_ID)) + 2U)
#define EPWM_CMP_C0(EPWM_ID) (SIG_I_START + 16U + (7U * (EPWM_ID)) + 3U)
#define EPWM_CMP_C1(EPWM_ID) (SIG_I_START + 16U + (7U * (EPWM_ID)) + 4U)
#define EPWM_CMP_D0(EPWM_ID) (SIG_I_START + 16U + (7U * (EPWM_ID)) + 5U)
#define EPWM_CMP_D1(EPWM_ID) (SIG_I_START + 16U + (7U * (EPWM_ID)) + 6U)
#define ADC_DONE(ADC_ID) (SIG_I_START + 30U + (ADC_ID))

/** \brief Marco for the SYNC_i group */
#define ETIMER_SNAP_SHOT_I(ETMR_ID) (SYNC_I_START + (ETMR_ID))
#define ETIMER_SET_I(ETMR_ID) (SYNC_I_START + 2U + (ETMR_ID))
#define ETIMER_CLR_I(ETMR_ID) (SYNC_I_START + 4U + (ETMR_ID))
#define EPWM_SET_I(EPWM_ID) (SYNC_I_START + 6U + (EPWM_ID))
#define EPWM_CLR_I(EPWM_ID) (SYNC_I_START + 8U + (EPWM_ID))
/** \brief Marco for the TRG_i group */
#define ETIMER_CMP_A0(ETMR_ID) (TRG_I_START + (ETMR_ID))
#define EPWM_CMP_A0(EPWM_ID) (TRG_I_START + 2U + (EPWM_ID))
/** \brief Marco for the IO_I group */
#define IO_I(IO) (IO_I_START + (IO))
/** \brief Marco for the TID_i group */
#define ETIMER_EID(ETMR) (TID_I_START + ((ETMR)*8U))
#define EPWM_EID(EPWM) (TID_I_START + 16U + ((EPWM)*8U))
/** \brief Marco for the SIG_o group */
#define ETIMER_CPT0(ETMR, CHNL) (SIG_O_START + ((ETMR) * 8U) + (CHNL))
#define ETIMER_FAULT(ETMR, CHNL) (SIG_O_START + 16U + ((ETMR)*4U) + (CHNL))
#define ETIMER_CLK(ETMR) (SIG_O_START + 24U + (ETMR))
#define EPWM_FAULT(EPWM, CHNL) (SIG_O_START + 26U + ((EPWM)*4U) + (CHNL))
#define EPWM_CLK(EPWM) (SIG_O_START + 34U + (EPWM))
/** \brief Marco for the IO_O group */
#define IO_O(IO) (IO_O_START + (IO))
/** \brief Marco for the SYNC_o group */
#define ETIMER_SNAP_SHOT_O(ETMR) (SYNC_O_START + (ETMR))
#define ETIMER_SET_O(ETMR) (SYNC_O_START + 2U + (ETMR))
#define ETIMER_CLR_O(ETMR) (SYNC_O_START + 4U + (ETMR))
#define EPWM_SET_O(EPWM) (SYNC_O_START + 6U + (EPWM))
#define EPWM_CLR_O(EPWM) (SYNC_O_START + 8U + (EPWM))
/** \brief Marco for the SSIG group */
#define SSIG(SSIG_INPUT) (SSIG_START + (SSIG_INPUT))
#endif
/** \brief Marco for the Xtrg total cnt of different signal groups */
#define XTRG_SIG_GROUP_CNT 10U
/** \brief Marco for the low state of xtrg software trigger */
#define XTRG_SWT_STATE_LOW 0U
/** \brief Marco for the high state of xtrg software trigger */
#define XTRG_SWT_STATE_HIGH 1U
/** \brief Marco for the input count of one xtrg signal matrix */
#define XTRG_SSE_SIGNAL_CNT 5U
/** \brief Marco for max times of reading software trigger register */
/** Traceability     :*/
#define XTRG_SWT_POLLING_TIME 10000U


/** **************************************************************************************
 * \brief This function is used for generating specific Xtrg software trigger event or
 *          pulse in IP level.

 * \verbatim
 * Syntax             : Xtrg_ErrorIdType Xtrg_Ip_SoftwareTrigger(volatile uint32 base,
 *                          const Xtrg_SWTriggerType *ipSoftwareTrigCfg)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : base - Xtrg base address
 *                      ipSoftwareTrigCfg - Xtrg software trigger configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : errorId: Xtrg error id

 * Description        : This function is used for generating specific Xtrg software
 *                      trigger event or pulse in IP level.
 * \endverbatim
 * Traceability       : SWSR_XTRG_014
 *****************************************************************************************/
Xtrg_ErrorIdType Xtrg_Ip_SoftwareTrigger(volatile uint32 base,
        const Xtrg_SWTriggerType *ipSoftwareTrigCfg);
/** **************************************************************************************
 * \brief This function is used for getting the level state of specific Xtrg software
 *          trigger in IP level.

 * \verbatim
 * Syntax             : boolean Xtrg_Ip_GetSoftwareTrigState(
 *                          volatile uint32 base,
 *                          Xtrg_SWTrigSelectorType ipTrigSelector)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : base - Xtrg base address
 *                      ipTrigSelector - Xtrg software trigger selector

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : XTRG_SWT_STATE_HIGH: High State
 *                      XTRG_SWT_STATE_LOW: Low State

 * Description        : This function is used for getting the level state of specific Xtrg software
 *                      trigger in IP level.
 * \endverbatim
 *****************************************************************************************/
boolean Xtrg_Ip_GetSoftwareTrigState(volatile uint32 base, Xtrg_SWTrigSelectorType ipTrigSelector);
/** **************************************************************************************
 * \brief This function is used for configuring the Xtrg signal matrix in IP level.

 * \verbatim
 * Syntax             : void Xtrg_Ip_SigMatrixConfig(
 *                          volatile uint32 base,
 *                          const Xtrg_SigMatrixType *ipSigMatrixCfg)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : base - Xtrg base address
 *                      ipSigMatrixCfg - Xtrg signal matrix configuration
 *                      ipEnable - Xtrg signal matrix enable/disable

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for configuring the Xtrg signal matrix
 *                      in IP level.
 * \endverbatim
 * Traceability       : SWSR_XTRG_003
 *****************************************************************************************/
void Xtrg_Ip_SigMatrixConfig(volatile uint32 base,
                             const Xtrg_SigMatrixType *ipSigMatrixCfg,
                             boolean ipSseEnable);
/** **************************************************************************************
 * \brief This function is used for configuring the Xtrg Mutiplexing Mux in IP level.

 * \verbatim
 * Syntax             : void Xtrg_Ip_SigMutiplex(
                            volatile uint32 base,
                            const Xtrg_SignalType *ipMutiplexSignal)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : base - Xtrg base address
 *                      ipMutiplexSignal - Xtrg signal for multiplexing Mux configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for configuring the Xtrg Mutiplexing
 *                      Mux in IP level.
 * \endverbatim
 * Traceability       : SWSR_XTRG_005
 *****************************************************************************************/
void Xtrg_Ip_SigMutiplex(
    volatile uint32 base,
    const Xtrg_SignalType *ipMutiplexSignal
);
/** **************************************************************************************
 * \brief This function is used for configuring the Xtrg Synchronization Mux in IP level.

 * \verbatim
 * Syntax             : void Xtrg_Ip_SigSynchronize(
 *                          volatile uint32 base,
 *                          const Xtrg_SignalType *ipSyncSignalCfg)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : base - Xtrg base address
 *                      ipSyncSignalCfg - Xtrg signal for multiplexing Mux configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for configuring the Xtrg Synchronization
 *                      Mux in IP level.
 * \endverbatim
 * Traceability       : SWSR_XTRG_006
 *****************************************************************************************/
void Xtrg_Ip_SigSynchronize(
    volatile uint32 base,
    const Xtrg_SignalType *ipSyncSignalCfg
);
/** **************************************************************************************
 * \brief This function is used for configuring the Xtrg Direct Trigger Mux
 *          configuration in IP level.

 * \verbatim
 * Syntax             : void Xtrg_Ip_DirectTriggerAdc(
 *                          volatile uint32 base,
 *                          const Xtrg_DrtTrigMuxType *ipDirectTriggerCfg)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : base - Xtrg base address
 *                      ipDirectTriggerCfg - Xtrg Direct Trigger Mux configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for configuring the Xtrg Direct Trigger Mux
 *                      configuration in IP level.
 * \endverbatim
 * Traceability       : SWSR_XTRG_007
 *****************************************************************************************/
void Xtrg_Ip_DirectTriggerAdc(
    volatile uint32 base,
    const Xtrg_DrtTrigMuxType *ipDirectTriggerCfg
);
/** **************************************************************************************
 * \brief This function is used for configuring the Xtrg Indirect Trigger Mux
 *          configuration in IP level.

 * \verbatim
 * Syntax             : void Xtrg_Ip_IndirectTriggerAdc(
 *                          volatile uint32 base,
 *                          const Xtrg_IndrtTrigMuxType *ipIndirectTriggerCfg)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : base - Xtrg base address
 *                      ipIndirectTriggerCfg - Xtrg Indirect Trigger Mux configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for configuring the Xtrg Indirect Trigger Mux
 *                      configuration in IP level.
 * \endverbatim
 * Traceability       : SWSR_XTRG_007
 *****************************************************************************************/
void Xtrg_Ip_IndirectTriggerAdc(
    volatile uint32 base,
    const Xtrg_IndrtTrigMuxType *ipIndirectTriggerCfg
);

/** **************************************************************************************
 * \brief This function is used for reading the Adc channel conversion value
 *          which is triggered by Xtrg Trigger Mux in IP level.

 * \verbatim
 * Syntax             : uint32 Xtrg_Ip_ReadTrigAdcValue(
 *                          volatile uint32 base,
 *                          Xtrg_TrigMuxSelectorType ipTrigMuxSelector,
 *                          Xtrg_TrigAdcIndexType ipTriggeredAdc)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : base - Xtrg base address
 *                      ipTrigMuxSelector - Xtrg Indirect/direct Trigger Mux
 *                      ipTriggeredAdc - Adc triggered by Xtrg trigger Mux

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : ipConversionValue: conversion value of triggered Adc channel

 * Description        : This function is used for reading the Adc channel conversion value
 *                      which is triggered by Xtrg Trigger Mux in IP level.
 * \endverbatim
 * Traceability       : SWSR_XTRG_008
 *****************************************************************************************/
uint32 Xtrg_Ip_ReadTrigAdcValue(
    volatile uint32 base,
    Xtrg_TrigMuxSelectorType ipTrigMuxSelector,
    Xtrg_TrigAdcIndexType ipTriggeredAdc
);
/** **************************************************************************************
 * \brief This function is used for configuring the Xtrg Indirect Trigger
 *        Mux configuration in IP level.

 * \verbatim
 * Syntax             : void Xtrg_Ip_IOFilterConfig(
 *                          volatile uint32 base,
 *                          const Xtrg_IOFilterType *ipIoFilterCfg,
 *                          boolean ipEnable)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : base - Xtrg base address
 *                      ipIoFilterCfg - Xtrg I/O filter configuration
 *                      ipEnable - Enable/Disable Xtrg I/O filter configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for configuring the Xtrg Indirect Trigger
 *                      Mux configuration in IP level.
 * \endverbatim
 * Traceability       : SWSR_XTRG_009
 *****************************************************************************************/
void Xtrg_Ip_IOFilterConfig(
    volatile uint32 base,
    const Xtrg_IOFilterType *ipIoFilterCfg,
    boolean ipEnable
);
/** **************************************************************************************
 * \brief This function is used for configuring Xtrg Direct Trigger Mux priority
 *          configuration in IP level.

 * \verbatim
 * Syntax             : void Xtrg_Ip_DirTrigAdcPrioConfig(
 *                          volatile uint32 base,
 *                          Xtrg_DrtTrigMuxSelectorType ipDirectTmux,
 *                          Xtrg_TmuxTrigPriority ipPriorityCfg)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : base - Xtrg base address
 *                      ipDirectTmux - Xtrg direct trigger mux selectors
 *                      ipPriorityCfg - Xtrg direct Trigger Mux priority configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for configuring Xtrg Direct Trigger Mux priority
 *                      configuration in IP level.
 * \endverbatim
 * Traceability       : SWSR_XTRG_010
 *****************************************************************************************/
void Xtrg_Ip_DirTrigAdcPrioConfig(
    volatile uint32 base,
    Xtrg_DrtTrigMuxSelectorType ipDirectTmux,
    Xtrg_TmuxTrigPriority ipPriorityCfg
);
/** **************************************************************************************
 * \brief This function is used for configuring Xtrg Indirect Trigger Mux priority
 *          configuration in IP level.

 * \verbatim
 * Syntax             : void Xtrg_Ip_IndirTrigAdcPrioConfig(
 *                          volatile uint32 base,
 *                          Xtrg_IndrtTrigMuxSelectorType ipIndirectTmux,
 *                          Xtrg_TmuxTrigPriority ipPriorityCfg)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : base - Xtrg base address
 *                      ipIndirectTmux - Xtrg indirect trigger mux selectors
 *                      ipPriorityCfg - Xtrg indirect Trigger Mux priority configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for configuring Xtrg Indirect Trigger Mux priority
 *                      configuration in IP level.
 * \endverbatim
 * Traceability       : SWSR_XTRG_010
 *****************************************************************************************/
void Xtrg_Ip_IndirTrigAdcPrioConfig(
    volatile uint32 base,
    Xtrg_IndrtTrigMuxSelectorType ipIndirectTmux,
    Xtrg_TmuxTrigPriority ipPriorityCfg
);
/** **************************************************************************************
 * \brief This function is used for setting Xtrg interrupt configuration in IP level.

 * \verbatim
 * Syntax             : void Xtrg_Ip_InterruptEnable(
 *                          volatile uint32 base,
 *                          Xtrg_NormalInterruptType ipInterruptId)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : base - Xtrg base address
 *                      ipInterruptId - Xtrg interrupt ID

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for setting Xtrg interrupt configuration
 *                      in IP level.
 * \endverbatim
 * Traceability       : SWSR_XTRG_011
 *****************************************************************************************/
void Xtrg_Ip_InterruptEnable(
    volatile uint32 base,
    Xtrg_NormalInterruptType ipInterruptId
);
/** **************************************************************************************
 * \brief This function is used for resetting configuring Xtrg interrupt
 *          configuration in IP level.

 * \verbatim
 * Syntax             : void Xtrg_Ip_InterruptDisable(
 *                          volatile uint32 base,
 *                          Xtrg_NormalInterruptType ipInterruptId)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : base - Xtrg base address
 *                      ipInterruptId - Xtrg interrupt ID

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for resetting configuring Xtrg interrupt
 *                          configuration in IP level.
 * \endverbatim
 * Traceability       : SWSR_XTRG_011
 *****************************************************************************************/
void Xtrg_Ip_InterruptDisable(
    volatile uint32 base,
    Xtrg_NormalInterruptType ipInterruptId
);
/** **************************************************************************************
 * \brief This function returns the version information of this module.

 * \verbatim
 * Syntax             : void Xtrg_Ip_DirTrigEnableConfig(
 *                          volatile uint32 base,
 *                          Xtrg_DrtTrigMuxSelectorType ipDirectTmux,
 *                          boolean en)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : base - Xtrg base address
 *                      ipDirectTmux - Xtrg Direct Trigger Mux configuration
 *                      en - Xtrg direct trigger mux enable/disable configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function returns the version information of this module.
 * \endverbatim
 *****************************************************************************************/
void Xtrg_Ip_DirTrigEnableConfig(
    volatile uint32 base,
    Xtrg_DrtTrigMuxSelectorType ipDirectTmux,
    boolean en
);
/** **************************************************************************************
 * \brief This function is used for configuring Indirect Trigger enable/disable
 *          in IP level.

 * \verbatim
 * Syntax             : void Xtrg_Ip_IndirTrigEnableConfig(
 *                          volatile uint32 base,
 *                          Xtrg_IndrtTrigMuxSelectorType ipInDirectTmux,
 *                          boolean en)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : base - Xtrg base address
 *                      ipInDirectTmux - Xtrg Indirect Trigger Mux configuration
 *                      en - Xtrg indirect trigger mux enable/disable configuration

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is used for configuring Indirect Trigger
 *                      enable/disable in IP level.
 * \endverbatim
 *****************************************************************************************/
void Xtrg_Ip_IndirTrigEnableConfig(
    volatile uint32 base,
    Xtrg_IndrtTrigMuxSelectorType ipInDirectTmux,
    boolean en
);

ISR(Xtrg_IrqHandler);

#ifdef __cplusplus
}
#endif
#endif /* XTRG_IP_H */
/* End of file */

