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
 *  \file     Pwm_Ip.h                                                                                  *
 *  \brief    This file contains interface header for PWM MCAL driver                                   *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/18     <td>3.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifndef PWM_IP_H
#define PWM_IP_H

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Mcu.h"
#include "Mcu_Cfg.h"
#include "Pwm.h"
#if (STD_ON == PWM_DMA_SUPPORTED)
#include "Dma.h"
#endif

/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
/** \brief  The base addrsss of PWM controllers */
#define PWM_IP_EPWM1_BASE                                       (0xf0480000UL)
#define PWM_IP_EPWM2_BASE                                       (0xf0490000UL)
#define PWM_IP_EPWM3_BASE                                       (0xf04a0000UL)
#define PWM_IP_EPWM4_BASE                                       (0xf04b0000UL)
#define PWM_IP_ETMR1_BASE                                       (0xf04c0000UL)
#define PWM_IP_ETMR2_BASE                                       (0xf04d0000UL)
#define PWM_IP_ETMR3_BASE                                       (0xf04e0000UL)
#define PWM_IP_ETMR4_BASE                                       (0xf04f0000UL)
/** \brief  The nUmber of registers to be configUred for a PWM */
#define PWM_IP_MODULE_ADDR_GAP                                  (0x10000UL)
/* PWM interrupt status register */
#define PWM_IP_CORE_INT_STA_REG                                 (0x0U)
/* PWM interrupt status enable register */
#define PWM_IP_CORE_INT_STA_EN_REG                              (0x4U)
/* PWM interrupt signal enable register */
#define PWM_IP_CORE_INT_SIG_EN_REG                              (0x8U)
#define PWM_IP_ETMR_INT_CMP_EN(ch)                              (1UL << ((ch) + 4U))
#define PWM_IP_EPWM_INT_CMP_EN(ch)                              (1UL << (ch))
#define PWM_IP_ETMR_INT_CNT_OVF_EN(cnt)                         (1UL << ((cnt) + 10U))
#define PWM_IP_EPWM_INT_CNT_OVF_EN(cnt)                         (1UL << ((cnt) + 4U))
/* PWM   Correctable error interrupt status register */
#define PWM_IP_CORE_COR_ERR_INT_STA                             (0xcU)
#define PWM_IP_COR_ERR_CMP_N_REG_NO_UPD_STA(ch)                 (1UL << ((ch) + 16U))
#define PWM_IP_COR_ERR_CMP_N_REG_UPD_TWICE_STA(ch)              (1UL << ((ch) + 20U))
/* PWM   Correctable error interrupt status enable register */
#define PWM_IP_CORE_COR_ERR_INT_STA_EN                          (0x10U)
#define PWM_IP_COR_ERR_CMP_N_REG_NO_UPD_EN(ch)                  (1UL << ((ch) + 16U))
#define PWM_IP_COR_ERR_CMP_N_REG_UPD_TWICE_EN(ch)               (1UL << ((ch) + 20U))
/* PWM   Correctable error interrupt signal enable register */
#define PWM_IP_CORE_COR_ERR_INT_SIG_EN                          (0x14U)
#define PWM_IP_COR_ERR_CMP_N_REG_NO_UPD_SIG(ch)                 (1UL << ((ch) + 16U))
#define PWM_IP_COR_ERR_CMP_N_REG_UPD_TWICE_SIG(ch)              (1UL << ((ch) + 20U))
/* PWM  Uncorrectable error interrupt status register */
#define PWM_IP_CORE_UNC_ERR_INT_STA                             (0x18U)
#define PWM_IP_UNC_ERR_CMP_N_REG_NO_UPD_STA(ch)                 (1UL << ((ch) + 16U))
#define PWM_IP_UNC_ERR_CMP_N_REG_UPD_TWICE_STA(ch)              (1UL << ((ch) + 20U))
/* PWM  Uncorrectable error interrupt status enable register */
#define PWM_IP_CORE_UNC_ERR_INT_STA_EN                          (0x1cU)
#define PWM_IP_UNC_ERR_CMP_N_REG_NO_UPD_EN(ch)                  (1UL << ((ch) + 16U))
#define PWM_IP_UNC_ERR_CMP_N_REG_UPD_TWICE_EN(ch)               (1UL << ((ch) + 20U))
/* PWM  Uncorrectable error interrupt signal enable register */
#define PWM_IP_CORE_UNC_ERR_INT_SIG_EN                          (0x20U)
#define PWM_IP_UNC_ERR_CMP_N_REG_NO_UPD_SIG(ch)                 (1UL << ((ch) + 16U))
#define PWM_IP_UNC_ERR_CMP_N_REG_UPD_TWICE_SIG(ch)              (1UL << ((ch) + 20U))
/* PWM clock select and divider configuration register */
#define PWM_IP_CORE_CLK_CONFIG_REG                              (0xa0U)
#define PWM_IP_CORE_CLK_DIV_NUM_OFFSET                          (0U)
#define PWM_IP_CORE_CLK_DIV_NUM_MASK                            (0xffffUL)
#define PWM_IP_CORE_CLK_SRC_SEL_OFFSET                          (16U)
#define PWM_IP_CORE_CLK_SRC_SEL_MASK                            (0x3UL)
#define PWM_IP_CORE_CLK_CHANGE_UPD_OFFSET                       (31U)
#define PWM_IP_CORE_CLK_CHANGE_UPD_MASK                         (1UL)
/* PWM Software reset */
#define PWM_IP_CORE_SW_RST_REG                                  (0xa8U)
#define PWM_IP_EPWM_RST_CH_OFFSET_N(ch)                         ((ch) + 4U)
#define PWM_IP_ETMR_RST_CH_OFFSET_N(ch)                         (ch)
#define PWM_IP_CORE_RST_CH_MASK                                 (1UL)
/* PWM EPWM DMA watermark level register */
#define PWM_IP_EPWM_DMA_WML_REG                                 (0xb4U)
#define PWM_IP_EPWM_DMA_WML_CHN_A_OFFSET                        (0U)
#define PWM_IP_EPWM_DMA_WML_CHN_A_MASK                          (0x3fUL)
#define PWM_IP_EPWM_DMA_WML_CHN_B_OFFSET                        (8U)
#define PWM_IP_EPWM_DMA_WML_CHN_B_MASK                          (0x1fUL)
#define PWM_IP_EPWM_DMA_WML_CHN_C_OFFSET                        (16U)
#define PWM_IP_EPWM_DMA_WML_CHN_C_MASK                          (0xfUL)
#define PWM_IP_EPWM_DMA_WML_CHN_D_OFFSET                        (24U)
#define PWM_IP_EPWM_DMA_WML_CHN_D_MASK                          (0xfUL)
/* PWM DMA control register */
#define PWM_IP_CORE_CHN_DMA_CTRL_REG                            (0xb0U)
#define PWM_IP_CORE_CHN_DMA_EN_OFFSET(ch)                       (ch)
#define PWM_IP_CORE_CHN_DMA_EN_MASK                             (1UL)
#define PWM_IP_EPWM_CMP_N_OUT_MODE_OFFSET(ch)                   ((ch) + 16U)
#define PWM_IP_EPWM_CMP_N_OUT_MODE_MASK                         (1UL)
#define PWM_IP_EPWM_CMP_N_MODE_OFFSET(ch)                       ((ch) + 20U)
#define PWM_IP_EPWM_CMP_N_MODE_MASK                             (3UL)
#define PWM_IP_EPWM_CMP_MODE_SINGLE                             (0U)
/* PWM ETMR DMA watermark level register */
#define PWM_IP_ETMR_DMA_WML_REG                                 (0xb4U)
#define PWM_IP_ETMR_DMA_WML_OFFSET_N(ch)                        ((ch) * 8U)
#define PWM_IP_ETMR_DMA_WML_CHN_MASK                            (0xfUL)
/*  FIFO_entry for compare channel A */
#define PWM_IP_CORE_FIFO_A_REG                                  (0xc0U)
#define PWM_IP_CORE_FIFO_GAP                                    (0x4U)
#define PWM_IP_CORE_FIFO_N(ch)              (PWM_IP_CORE_FIFO_A_REG +                           \
                                                ((ch) * PWM_IP_CORE_FIFO_GAP))
/* PWM EPWM Counter G0 overflow value register */
#define PWM_IP_EPWM_CNT_G0_OVF_REG                              (0x104U)
#define PWM_IP_EPWM_CNT_OVF_REG_GAP                             (0x20U)
#define PWM_IP_EPWM_CNT_OVF_N(cnt)          (PWM_IP_EPWM_CNT_G0_OVF_REG +                       \
                                                ((cnt) * PWM_IP_EPWM_CNT_OVF_REG_GAP))
/* PWM EPWM CNT_G0 configuration register. */
#define PWM_IP_EPWM_CNT_G0_CFG_REG                              (0x108U)
#define PWM_IP_EPWM_CNT_CFG_REG_GAP                             (0x20U)
#define PWM_IP_EPWM_CNT_CFG_N(cnt)         (PWM_IP_EPWM_CNT_G0_CFG_REG +                        \
                                                ((cnt) * PWM_IP_EPWM_CNT_CFG_REG_GAP))
#define PWM_IP_EPWM_CNT_OVF_UPD_OFFSET                          (17U)
#define PWM_IP_EPWM_CNT_OVF_UPD_MASK                            (1UL)
/* PWM EPWM CNT_G0 enable register */
#define PWM_IP_EPWM_CNT_G0_EN_REG                               (0x10cU)
#define PWM_IP_EPWM_CNT_EN_REG_GAP                              (0x20U)
#define PWM_IP_EPWM_CNT_EN_N(cnt)          (PWM_IP_EPWM_CNT_G0_EN_REG +                         \
                                                ((cnt) * PWM_IP_EPWM_CNT_EN_REG_GAP))
#define PWM_IP_EPWM_CNT_EN_OFFSET                               (0U)
#define PWM_IP_EPWM_CNT_EN_MASK                                 (1UL)
/* PWM ETMR Local counter A overflow value register */
#define PWM_IP_ETMR_LCNT_A_OVF_REG                              (0x144U)
#define PWM_IP_ETMR_LCNT_OVF_REG_GAP                            (0x20U)
#define PWM_IP_ETMR_LCNT_OVF_N(cnt)         (PWM_IP_ETMR_LCNT_A_OVF_REG +                       \
                                                ((cnt) * PWM_IP_ETMR_LCNT_OVF_REG_GAP))
/* PWM ETMR Local counter A configuration register. */
#define PWM_IP_ETMR_LCNT_A_CFG_REG                              (0x148U)
#define PWM_IP_ETMR_LCNT_CFG_REG_GAP                            (0x20U)
#define PWM_IP_ETMR_LCNT_CFG_N(cnt)         (PWM_IP_ETMR_LCNT_A_CFG_REG +                       \
                                                ((cnt) * PWM_IP_ETMR_LCNT_CFG_REG_GAP))
#define PWM_IP_ETMR_CNT_OVF_UPD_OFFSET                          (17U)
#define PWM_IP_ETMR_CNT_OVF_UPD_MASK                            (1UL)
/* PWM ETMR Local counter A enable register */
#define PWM_IP_ETMR_LCNT_A_EN_REG                               (0x14cU)
#define PWM_IP_ETMR_LCNT_EN_REG_GAP                             (0x20U)
#define PWM_IP_ETMR_LCNT_EN_N(cnt)          (PWM_IP_ETMR_LCNT_A_EN_REG +                        \
                                                ((cnt) * PWM_IP_ETMR_LCNT_EN_REG_GAP))
#define PWM_IP_ETMR_LCNT_EN_OFFSET                              (0U)
#define PWM_IP_ETMR_LCNT_EN_MASK                                (1UL)
/* PWM EPWM Compare A channel configuration register */
#define PWM_IP_EPWM_CMP_A_CONFIG_REG                            (0x220U)
#define PWM_IP_EPWM_CMP_CNT_SEL_OFFSET                          (2U)
#define PWM_IP_EPWM_CMP_CNT_SEL_MASK                            (1UL)
#define PWM_IP_EPWM_CMP_CONFIG_REG_GAP                          (0x30U)
#define PWM_IP_EPWM_CMP_CONFIG_N(ch)        (PWM_IP_EPWM_CMP_A_CONFIG_REG +                       \
                                                ((ch) * PWM_IP_EPWM_CMP_CONFIG_REG_GAP))
#define PWM_IP_EPWMR_CMP_CNT_SEL_G0                             (0U)
#define PWM_IP_EPWMR_CMP_CNT_SEL_G1                             (1U)
/* PWM ETMR Compare A channel configuration register */
#define PWM_IP_ETMR_CMP_A_CONFIG_REG                            (0x220U)
#define PWM_IP_ETMR_CMP_OUT_MODE_OFFSET                         (0U)
#define PWM_IP_ETMR_CMP_OUT_MODE_MASK                           (1UL)
#define PWM_IP_ETMR_CMP_MODE_MODE_OFFSET                        (2U)
#define PWM_IP_ETMR_CMP_MODE_MODE_MASK                          (3UL)
#define PWM_IP_ETMR_CMP_MODE_SINGLE                             (0U)
#define PWM_IP_ETMR_CMP_CNT_SEL_OFFSET                          (4U)
#define PWM_IP_ETMR_CMP_CNT_SEL_MASK                            (0x3UL)
#define PWM_IP_ETMR_CMP_CONFIG_REG_GAP                          (0x30U)
#define PWM_IP_ETMR_CMP_CONFIG_N(cnt)       (PWM_IP_ETMR_CMP_A_CONFIG_REG +                       \
                                                ((cnt) * PWM_IP_ETMR_CMP_CONFIG_REG_GAP))
#define PWM_IP_ETMR_CMP_CNT_SEL_LCNT                            (1UL)
/* Compare A channel event output mode register */
#define PWM_IP_CORE_CMP_A_EVENT_OUT_MODE_REG                    (0x224U)
#define PWM_IP_CORE_CMP_EVENT_OUT_MODE_GAP                      (0x30U)
#define PWM_IP_CORE_CMP_EVENT_OUT_MODE(ch)  (PWM_IP_CORE_CMP_A_EVENT_OUT_MODE_REG +             \
                                                ((ch) * PWM_IP_CORE_CMP_EVENT_OUT_MODE_GAP))
#define PWM_IP_CORE_CMP_EVENT_OUT_CMP00_OFFSET                  (0U)
#define PWM_IP_CORE_CMP_EVENT_OUT_CMP00_LEVEL_HIGH              (3UL <<                         \
                                                        PWM_IP_CORE_CMP_EVENT_OUT_CMP00_OFFSET)
#define PWM_IP_CORE_CMP_EVENT_OUT_CMP10_OFFSET                  (8U)
#define PWM_IP_CORE_CMP_EVENT_OUT_CMP10_LEVEL_HIGH              (3UL <<                         \
                                                        PWM_IP_CORE_CMP_EVENT_OUT_CMP10_OFFSET)
#define PWM_IP_CORE_CMP_EVENT_OUT_CMP0_OVF_OFFSET               (16U)
#define PWM_IP_CORE_CMP_EVENT_OUT_CMP0_OVF_LEVEL_LOW            (4UL <<                         \
                                                        PWM_IP_CORE_CMP_EVENT_OUT_CMP0_OVF_OFFSET)
#define PWM_IP_CORE_CMP_EVENT_OUT_CMP1_OVF_OFFSET               (20U)
#define PWM_IP_CORE_CMP_EVENT_OUT_CMP1_OVF_LEVEL_LOW            (4UL <<                         \
                                                        PWM_IP_CORE_CMP_EVENT_OUT_CMP1_OVF_OFFSET)
/* PWM Compare A channel output pulse width register0 */
#define PWM_IP_CORE_CMP_A_PULSE_WID0_REG                        (0x228U)
#define PWM_IP_CORE_CMP_A_PULSE_WID0_CMP00_OFFSET               (0U)
#define PWM_IP_CORE_CMP_A_PULSE_WID0_CMP00_MASK                 (0xffUL)
/* PWM Compare value for compare A channel cmp00 event */
#define PWM_IP_CORE_CMP_A_00_VAL_REG                            (0x230U)
#define PWM_IP_CORE_CMP_CHANNEL_REG_GAP                         (0x30U)
#define PWM_IP_CORE_CMP_SUBCHANNEL_REG_GAP                      (2U * 0x4U)
/* PWM ETMR Compare A channel event ID register */
#define PWM_IP_ETMR_CMP_A_EID_REG                               (0x248U)
#define PWM_IP_ETMR_CMP_A_EID_CMP00_OFFSET                      (0U)
#define PWM_IP_ETMR_CMP_A_EID_CMP00_MASK                        (0xffUL)
/* PWM Core Signal status register */
#define PWM_IP_CORE_SIGNAL_STATUS_REG                           (0x500U)
#define PWM_IP_CORE_COMPARE_SIGNAL_MASK                         (0xffU)
#define PWM_IP_CORE_COM_SIG_CHANNEL_GAP                         (0x2U)
#define PWM_IP_CORE_COM_SIG_SUBCHANNEL_GAP                      (0x1U)
/* PWM EPWM Compare A channel event ID register */
#ifdef SEMIDRIVE_E3_LITE_SERIES
#define PWM_IP_EPWM_CMP_A_EID_REG                               (0x248U)
#else
#define PWM_IP_EPWM_CMP_A_EID_REG                               (0x24cU)
#endif
#define PWM_IP_EPWM_CMP_A_EID_CMP00_OFFSET                      (0U)
#define PWM_IP_EPWM_CMP_A_EID_CMP00_MASK                        (0xffUL)
/* PWM Compare control register */
#define PWM_IP_CORE_CMP_CTRL_REG                                (0x2e0U)
#define PWM_IP_CORE_CMP_EN_OFFSET(ch)                           (ch)
#define PWM_IP_CORE_CMP_EN_MASK                                 (1UL)
#define PWM_IP_CORE_CMP_VAL_UPD_OFFSET(ch)                      ((ch) + 8U)
#define PWM_IP_CORE_CMP_VAL_UPD_MASK                            (1UL)
#define PWM_IP_CORE_CMP_A_EID_UPD_OFFSET                        (28U)
#define PWM_IP_CORE_CMP_A_EID_UPD_MASK                          (1UL)
/* PWM EPWM interrupt status enable bits */
#define PMW_IP_EPWM_INT_EN_CMP_A                                (0x01UL << 0U)
#define PMW_IP_EPWM_INT_EN_CMP_B                                (0x01UL << 1U)
#define PMW_IP_EPWM_INT_EN_CMP_C                                (0x01UL << 2U)
#define PMW_IP_EPWM_INT_EN_CMP_D                                (0x01UL << 3U)
#define PMW_IP_EPWM_INT_EN_CNT_G0_OVF                           (0x01UL << 4U)
#define PMW_IP_EPWM_INT_EN_CNT_G1_OVF                           (0x01UL << 5U)
#define PMW_IP_EPWM_INT_STA_EN (PMW_IP_EPWM_INT_EN_CMP_A | PMW_IP_EPWM_INT_EN_CMP_B             \
            | PMW_IP_EPWM_INT_EN_CMP_C | PMW_IP_EPWM_INT_EN_CMP_D                               \
            | PMW_IP_EPWM_INT_EN_CNT_G0_OVF | PMW_IP_EPWM_INT_EN_CNT_G1_OVF)
/* PWM EPWM interrupt signal enable bits */
#define PMW_IP_EPWM_SIG_EN_CMP_A                                (0x01UL << 0U)
#define PMW_IP_EPWM_SIG_EN_CMP_B                                (0x01UL << 1U)
#define PMW_IP_EPWM_SIG_EN_CMP_C                                (0x01UL << 2U)
#define PMW_IP_EPWM_SIG_EN_CMP_D                                (0x01UL << 3U)
#define PMW_IP_EPWM_SIG_EN_CNT_G0_OVF                           (0x01UL << 4U)
#define PMW_IP_EPWM_SIG_EN_CNT_G1_OVF                           (0x01UL << 5U)
#define PMW_IP_EPWM_INT_SIG_EN (PMW_IP_EPWM_SIG_EN_CMP_A | PMW_IP_EPWM_SIG_EN_CMP_B             \
            | PMW_IP_EPWM_SIG_EN_CMP_C | PMW_IP_EPWM_SIG_EN_CMP_D                               \
            | PMW_IP_EPWM_SIG_EN_CNT_G0_OVF | PMW_IP_EPWM_SIG_EN_CNT_G1_OVF)
/* PWM ETMR interrupt status enable bits */
#define PMW_IP_ETMR_INT_EN_CMP_A                                (0x01UL << 4U)
#define PMW_IP_ETMR_INT_EN_CMP_B                                (0x01UL << 5U)
#define PMW_IP_ETMR_INT_EN_CMP_C                                (0x01UL << 6U)
#define PMW_IP_ETMR_INT_EN_CMP_D                                (0x01UL << 7U)
#define PMW_IP_ETMR_INT_EN_LCNT_A_OVF                           (0x01UL << 10U)
#define PMW_IP_ETMR_INT_EN_LCNT_B_OVF                           (0x01UL << 11U)
#define PMW_IP_ETMR_INT_EN_LCNT_C_OVF                           (0x01UL << 12U)
#define PMW_IP_ETMR_INT_EN_LCNT_D_OVF                           (0x01UL << 13U)
#define PMW_IP_ETMR_INT_STA_EN (PMW_IP_ETMR_INT_EN_CMP_A | PMW_IP_ETMR_INT_EN_CMP_B             \
            | PMW_IP_ETMR_INT_EN_CMP_C | PMW_IP_ETMR_INT_EN_CMP_D                               \
            | PMW_IP_ETMR_INT_EN_LCNT_A_OVF | PMW_IP_ETMR_INT_EN_LCNT_B_OVF                     \
            | PMW_IP_ETMR_INT_EN_LCNT_C_OVF | PMW_IP_ETMR_INT_EN_LCNT_D_OVF)
/* PWM ETMR interrupt signal enable bits */
#define PMW_IP_ETMR_SIG_EN_CMP_A                                (0x01UL << 4U)
#define PMW_IP_ETMR_SIG_EN_CMP_B                                (0x01U << 5U)
#define PMW_IP_ETMR_SIG_EN_CMP_C                                (0x01UL << 6U)
#define PMW_IP_ETMR_SIG_EN_CMP_D                                (0x01UL << 7U)
#define PMW_IP_ETMR_SIG_EN_LCNT_A_OVF                           (0x01UL << 10U)
#define PMW_IP_ETMR_SIG_EN_LCNT_B_OVF                           (0x01UL << 11U)
#define PMW_IP_ETMR_SIG_EN_LCNT_C_OVF                           (0x01UL << 12U)
#define PMW_IP_ETMR_SIG_EN_LCNT_D_OVF                           (0x01UL << 13U)
#define PMW_IP_ETMR_INT_SIG_EN (PMW_IP_ETMR_SIG_EN_CMP_A | PMW_IP_ETMR_SIG_EN_CMP_B             \
            | PMW_IP_ETMR_SIG_EN_CMP_C | PMW_IP_ETMR_SIG_EN_CMP_D                               \
            | PMW_IP_ETMR_SIG_EN_LCNT_A_OVF | PMW_IP_ETMR_SIG_EN_LCNT_B_OVF                     \
            | PMW_IP_ETMR_SIG_EN_LCNT_C_OVF | PMW_IP_ETMR_SIG_EN_LCNT_D_OVF)
/** \brief Pwm Compare channel type */
#define PWM_IP_CMP_CHANNEL_A                                       (0U)
#define PWM_IP_CMP_CHANNEL_B                                       (1U)
#define PWM_IP_CMP_CHANNEL_C                                       (2U)
#define PWM_IP_CMP_CHANNEL_D                                       (3U)
/** \brief  PWM sub channel */
#define PWM_IP_SUBCHANNEL_0                                     (0x0U)
#define PWM_IP_SUBCHANNEL_1                                     (0x1U)
/** \brief  PWM duty minimum/maximal value */
/** Traceability       : SWSR_PWM_015 */
#define PWM_IP_DUTY_0                                           (0x0U)
#define PWM_IP_DUTY_100                                         (0x8000U)
/** \brief  PWM clock wait valid maximal loop */
#define PMW_IP_CORE_WAIT_CLK_TIMEOUT                            (1000U)
/** \brief  PWM ETIMER/EPWM counter number */
#define PMW_IP_ETMR_COUNTER_NUMBER                              (4U)
#define PMW_IP_EPWM_COUNTER_NUMBER                              (2U)
/** \brief  PWM counter/compare maximal value */
#define PMW_IP_CORE_COUNTER_VALUE_MAX                           (0xffffffffUL)
#define PMW_IP_CORE_COMPARE_VALUE_MAX                           (0xffffffffUL)
/** \brief  PWM roundup */
#define PWM_ROUNDUP(a, b) (((a) + (uint32)((b)-1UL)) & (uint32)~((b)-1UL))

/********************************************************************************************************
 *                                  Global Variable Declarations                                        *
 *******************************************************************************************************/
/** \brief  PWM multi-core handler */
extern Pwm_HandlerConfigType* const Pwm_HandlerPtr[PWM_MAX_CORE_NUM];

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/

/** *****************************************************************************************************
 * \brief Get current core ID.
 *
 * \verbatim
 * Syntax             : uint8 Pwm_Ip_GetCoreID(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : CPU_ID_SF, CPU_ID_SP0, CPU_ID_SP1, CPU_ID_SX0, CPU_ID_SX1
 *
 * Description        : Assignment Pwm_Handler base address of PWM registers.
 *
 * \endverbatim
 * Traceability       :
 *******************************************************************************************************/
uint8 Pwm_Ip_GetCoreID(void);

/** *****************************************************************************************************
 * \brief Assignment Pwm_Handler base address of PWM registers.
 *
 * \verbatim
 * Syntax             : void Pwm_Ip_SetBaseAddr(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Assignment Pwm_Handler base address of PWM registers.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_025
 *******************************************************************************************************/
void Pwm_Ip_SetBaseAddr(void);

/** *****************************************************************************************************
 * \brief Get the channel class type of PWM channel.
 *
 * \verbatim
 * Syntax             : Pwm_ChannelClassType Pwm_Ip_ValidateChannelClass(
 *                          Pwm_ChannelType channelNumber)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : channelNumber - Numeric identifier of the PWM.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : PWM_VARIABLE_PERIOD         - The PWM channel has a variable period.
 *                      PWM_FIXED_PERIOD            - The PWM channel has a fixed period.
 *                      PWM_FIXED_PERIOD_SHIFTED    - The PWM channel has a fixed shifted period.
 *
 * Description        : Get the channel class type of PWM channel.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_006 SWSR_PWM_007
 *******************************************************************************************************/
Pwm_ChannelClassType Pwm_Ip_ValidateChannelClass(Pwm_ChannelType channelNumber);

/** *****************************************************************************************************
 * \brief PWM IP initialization.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Pwm_Ip_Init(
 *                          const Pwm_ConfigType* ConfigPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : ConfigPtr   - Pointer to Pwm configuration set.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK    - Pwm IP initialization successful.
 *                      Others  - Pwm IP initialization failed.
 *
 * Description        : PWM IP initialization.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_025 SWSR_PWM_026 SWSR_PWM_027 SWSR_PWM_028 SWSR_PWM_029 SWSR_PWM_030
 *                      SWSR_PWM_093 SWSR_PWM_094
 *******************************************************************************************************/
Std_ReturnType Pwm_Ip_Init(const Pwm_ConfigType* ConfigPtr);

#if (STD_ON == PWM_DE_INIT_API)
/** *****************************************************************************************************
 * \brief PWM IP De-Initialization.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Pwm_Ip_Deinit(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK    - Pwm IP De-Initialization successful.
 *                      Others  - Pwm IP De-Initialization failed.
 *
 * Description        : PWM IP De-Initialization.
 *                      This function is available if the PWM_DE_INIT_API is set STD_ON.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_036 SWSR_PWM_037 SWSR_PWM_038 SWSR_PWM_094
 *******************************************************************************************************/
Std_ReturnType Pwm_Ip_Deinit(void);
#endif /** #if (STD_ON == PWM_DE_INIT_API) */

#if (STD_ON == PWM_SET_DUTY_CYCLE_API)
/** *****************************************************************************************************
 * \brief Set the duty cycle of the PWM channel.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Pwm_Ip_SetDutyCycle(
 *                          Pwm_ChannelType channelNumber,
 *                          uint16 dutyCycle)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : channelNumber   - Numeric identifier of the PWM channel.
 *                      dutyCycle       - The duty of the PWM channel., Min=0x0000 Max=0x8000.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK    - Set duty cycle successful.
 *                      Others  - Set duty cycle failed.
 *
 * Description        : Set the duty cycle of the PWM channel.
 *                      This function is available if the PWM_SET_DUTY_CYCLE_API is set STD_ON.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_015 SWSR_PWM_042 SWSR_PWM_043 SWSR_PWM_044
 *                      SWSR_PWM_045 SWSR_PWM_094
 *******************************************************************************************************/
Std_ReturnType Pwm_Ip_SetDutyCycle(Pwm_ChannelType channelNumber, uint16 dutyCycle);
#endif /** #if (STD_ON == PWM_SET_DUTY_CYCLE_API) */

#if (STD_ON == PWM_SET_PERIOD_AND_DUTY_API)
/** *****************************************************************************************************
 * \brief Set the period and the duty cycle of the PWM channel.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Pwm_Ip_SetPeriodAndDuty(
 *                          Pwm_ChannelType channelNumber,
 *                          Pwm_PeriodType Period,
 *                          uint16 dutyCycle)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : channelNumber   - Numeric identifier of the PWM channel.
 *                      Period          - Period of the PWM signal.
 *                      dutyCycle       - The duty of the PWM channel., Min=0x0000 Max=0x8000.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK    - Set period and the duty cycle successful.
 *                      Others  - Set period and the duty cycle failed.
 *
 * Description        : Set the period and the duty cycle of the PWM channel.
 *                      This function is available if the PWM_SET_PERIOD_AND_DUTY_API is set STD_ON.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_015 SWSR_PWM_043 SWSR_PWM_044 SWSR_PWM_045
 *                      SWSR_PWM_050 SWSR_PWM_051 SWSR_PWM_056 SWSR_PWM_094
 *******************************************************************************************************/
Std_ReturnType Pwm_Ip_SetPeriodAndDuty
(
    Pwm_ChannelType channelNumber,
    Pwm_PeriodType period,
    uint16 dutyCycle
);
#endif /** #if (STD_ON == PWM_SET_PERIOD_AND_DUTY_API) */

#if (STD_ON == PWM_SET_OUTPUT_TO_IDLE_API)
/** *****************************************************************************************************
 * \brief Set PWM channel output status to idle.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Pwm_Ip_SetOutputToIdle(
 *                          Pwm_ChannelType channelNumber)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : channelNumber - Numeric identifier of the PWM channel.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK    - Set PWM channel output status to idle successful.
 *                      Others  - Set PWM channel output status to idle failed.
 *
 * Description        : Set PWM channel output status to idle.
 *                      This function is available if the PWM_SET_OUTPUT_TO_IDLE_API is set STD_ON.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_057 SWSR_PWM_094
 *******************************************************************************************************/
Std_ReturnType Pwm_Ip_SetOutputToIdle(Pwm_ChannelType channelNumber);
#endif /** #if (STD_ON == PWM_SET_OUTPUT_TO_IDLE_API) */

#if (STD_ON == PWM_NOTIFICATION_SUPPORTED)
/** *****************************************************************************************************
 * \brief Disable notification of PWM channel.
 *
 * \verbatim
 * Syntax             : void Pwm_Ip_DisableNotification(
 *                          Pwm_ChannelType channelNumber)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : channelNumber - Numeric identifier of the PWM channel.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Disable notification of PWM channel.
 *                      This function is available if the PWM_NOTIFICATION_SUPPORTED is set STD_ON.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_080
 *******************************************************************************************************/
void Pwm_Ip_DisableNotification(Pwm_ChannelType channelNumber);
#endif /** #if (STD_ON == PWM_NOTIFICATION_SUPPORTED) */

#if (STD_ON == PWM_NOTIFICATION_SUPPORTED)
/** *****************************************************************************************************
 * \brief Enable notification of PWM channel.
 *
 * \verbatim
 * Syntax             : void Pwm_Ip_EnableNotification(
 *                          Pwm_ChannelType channelNumber,
 *                          Pwm_EdgeNotificationType notification)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : channelNumber - Numeric identifier of the PWM channel.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Enable notification of PWM channel.
 *                      This function is available if the PWM_NOTIFICATION_SUPPORTED is set STD_ON.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_073 SWSR_PWM_074 SWSR_PWM_080
 *******************************************************************************************************/
void Pwm_Ip_EnableNotification
(
    Pwm_ChannelType channelNumber,
    Pwm_EdgeNotificationType notification
);
#endif /** #if (STD_ON == PWM_NOTIFICATION_SUPPORTED) */

#if (STD_ON == PWM_GET_OUTPUT_STATE_API)
/** *****************************************************************************************************
 * \brief Get output status of PWM channel.
 *
 * \verbatim
 * Syntax             : Pwm_OutputStateType Pwm_Ip_GetOutputState(
 *                          Pwm_ChannelType channelNumber)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : channelNumber - Numeric identifier of the PWM channel.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : PWM_LOW     - The PWM channel is in low state.
 *                      PWM_HIGH    - The PWM channel is in high state.
 *
 * Description        : Get output status of PWM channel.
 *                      This function is available if the PWM_GET_OUTPUT_STATE_API is set STD_ON.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_067
 *******************************************************************************************************/
Pwm_OutputStateType Pwm_Ip_GetOutputState(Pwm_ChannelType channelNumber);
#endif /** #if (STD_ON == PWM_GET_OUTPUT_STATE_API) */

/** *****************************************************************************************************
 * \brief PWM interrupt handler.
 *
 * \verbatim
 * Syntax             : void Pwm_Ip_Irq(
 *                          Pwm_HrdControllerIrqType hardController)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : hardController - Pwm controller irq index: PWM1_MODULE_IRQ_INDEX,
 *                                       PWM2_MODULE_IRQ_INDEX, PWM3_MODULE_IRQ_INDEX,
 *                                       PWM4_MODULE_IRQ_INDEX, PWM5_MODULE_IRQ_INDEX,
 *                                       PWM6_MODULE_IRQ_INDEX, PWM7_MODULE_IRQ_INDEX,
 *                                       PWM8_MODULE_IRQ_INDEX.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : PWM interrupt handler, clear irq status and call notification function.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_089 SW_SM003 SW_SM004
 *******************************************************************************************************/
void Pwm_Ip_Irq(Pwm_HrdControllerIrqType hardController);

/** *****************************************************************************************************
 * \brief Get the core id assigned by the PWM channel.
 *
 * \verbatim
 * Syntax             : Pwm_CoreIdType Pwm_Ip_GetModuleAssignCoreId(
 *                          Pwm_ChannelType channelNumber)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : channelNumber - Numeric identifier of the PWM channel.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Core ID - 0:sf 1:sx0 2:sx1 3:sp0 4:sp1.
 *
 * Description        : Get the core id assigned by the PWM channel.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_006 SWSR_PWM_007
 *******************************************************************************************************/
Pwm_CoreIdType Pwm_Ip_GetModuleAssignCoreId(Pwm_ChannelType channelNumber);

#ifdef __cplusplus
}
#endif

#endif /* PWM_IP_H */
/* End of file */
