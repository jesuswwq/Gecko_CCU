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
 *  \file     Mcu_Pll.h                                                                                 *
 *  \brief    This file contains interface header for MCU MCAL driver, ...                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/02     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifndef MCU_PLL_H
#define MCU_PLL_H
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_GeneralTypes.h"
/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
/* PLL index */
#define PLL_ID_NUM_LSB                  (0U)
#define PLL_ID_NUM_VCO                  (0U)
#define PLL_ID_NUM_LVDS_CLK_0           (1U)
#define PLL_ID_NUM_LVDS_CLK_1           (2U)
#define PLL_ID_NUM_LVDS_CLK_2           (3U)
#define PLL_ID_NUM_LVDS_CKGEN           (4U)
#define PLL_ID_NUM_MASK                 (0xFF)

/* Control register */
#define PLL_CTRL                        (0x0U)
#define PLL_CTRL_PD                     (0U)
#define PLL_CTRL_GATING_MODE            (1U)
#define PLL_CTRL_LOCK_MODE              (2U)
#define PLL_CTRL_LOCK_TIME_LSB          (3U)
#define PLL_CTRL_LOCK_TIME_MASK         (0xFu)
#define PLL_CTRL_POSTDIV                (7U)
#define PLL_CTRL_FORCE_LOCK             (8U)
#define PLL_CTRL_DSM_DISABLE            (9U)
#define PLL_CTRL_RESETN                 (10U)
#define PLL_CTRL_RESETN_SEL             (11U)
#define PLL_CTRL_ICP_LSB                (16U)
#define PLL_CTRL_ICP_MASK               (0x7U)
#define PLL_CTRL_LDO_V0P8_LSB           (19U)
#define PLL_CTRL_LDO_V0P8_MASK          (0x3U)
#define PLL_CTRL_VCO_BAND_LSB           (21U)
#define PLL_CTRL_VCO_BAND_MASK          (0x7U)
#define PLL_CTRL_RESETN_DLY_LSB         (25U)
#define PLL_CTRL_RESETN_DLY_MASK        (0xFu)
#define PLL_CTRL_FORCE_BYPASS           (29U)
#define PLL_CTRL_SEM_SWITCH_EN          (30U)
#define PLL_CTRL_SEMM_SWITCH_SRC_SEL    (31U)

/* N Number register */
#define PLL_N_NUM                       (0x4U)
#define PLL_N_NUM_VAL_LSB               (0U)
#define PLL_N_NUM_VAL_MASK              (0x7Fu)

/* M Number register */
#define PLL_M_NUM                       (0x8U)
#define PLL_M_NUM_VAL_LSB               (0U)
#define PLL_M_NUM_VAL_MASK              (0x3FFFFFFu)
#define PLL_M_NUM_SW_READY              (30U)
#define PLL_M_NUM_READY_SEL             (31U)

/* DSM register */
#define PLL_DSM                         (0xCu)
#define PLL_DSM_SSC_OFFSET_LSB          (0U)
#define PLL_DSM_SSc_OFFSET_MASK         (0x3U)
#define PLL_DSM_SSC_FREQ_LSB            (2U)
#define PLL_DSM_SSC_FREQ_MASK           (0x3U)
#define PLL_DSM_SSC_MODE_LSB            (4U)
#define PLL_DSM_SSC_MODE_MASK           (0x3U)
#define PLL_DSM_SSC_DEP_LSB             (6U)
#define PLL_DSM_SSC_DEP_MASK            (0x1Fu)

/* DTEST register */
#define PLL_DTEST                       (0x10U)
#define PLL_DTEST_EN                    (0U)
#define PLL_DTEST_SEL_LSB               (1U)
#define PLL_DTEST_SEL_MASK              (0x3U)
#define PLL_DTEST_REF_TEST_SEL          (3U)
#define PLL_DTEST_DTESTO                (31U)

/* ATEST register */
#define PLL_ATEST                       (0x14U)
#define PLL_ATEST_EN                    (0U)
#define PLL_ATEST_SEL_LSB               (1U)
#define PLL_ATEST_SEL_MASK              (0x3U)

/* STATUS register */
#define PLL_STATUS                      (0x20U)
#define PLL_STATUS_LOCK                 (0U)
#define PLL_STATUS_DUTY_DET             (1U)
#define PLL_STATUS_NO_REFCK             (2U)
#define PLL_STATUS_PLL_M_READY          (3U)
#define PLL_STATUS_LOCK_LOSS            (8U)
#define PLL_STATUS_DUTY_LOSS            (9U)
#define PLL_STATUS_REFCK_LOSS           (10U)

/* LVDS_CTL register */
#define PLL_LVDS_CTL                    (0xA0U)
#define PLL_LVDS_CTL_DIV2_GATING_EN     (0U)
#define PLL_LVDS_CTL_DIV7_GATING_EN     (1U)
#define PLL_LVDS_CTL_DIV2_NUM_LSB       (2U)
#define PLL_LVDS_CTL_DIV2_NUM_MASK      (0x1Fu)
#define PLL_LVDS_CTL_DIV7_NUM_LSB       (7U)
#define PLL_LVDS_CTL_DIV7_NUM_MASK      (0x1Fu)
#define PLL_LVDS_CTL_GATING_EN          (12U)
#define PLL_LVDS_CTL_CKGEN_GATING_EN    (16U)
#define PLL_LVDS_CTL_CKGEN_DIV_NUM_LSB  (17U)
#define PLL_LVDS_CTL_CKGEN_DIV_NUM_MASK (0xFu)
#define PLL_LVDS_CTL_CKGEN_GATING_STATUS  (25U)
#define PLL_LVDS_CTL_CKGEN_CHG_BUSY       (26U)
#define PLL_LVDS_CTL_GATING_STATUS      (27U)
#define PLL_LVDS_CTL_DIV7_GATING_STATUS (28U)
#define PLL_LVDS_CTL_DIV2_GATING_STATUS (29U)
#define PLL_LVDS_CTL_DIV7_CHG_BUSY      (30U)
#define PLL_LVDS_CTL_DIV2_CHG_BUSY      (31U)

#define PLL_LVDS_OUT_DIV_MIN            (1U)
#define PLL_LVDS_OUT_DIV_MAX            (32U)
#define PLL_LVDS_CKGEN_IN_DIV_MAX       (16U)

#define PLL_VCO_FMAX                    2400000000UL
#define PLL_VCO_FMIN                    500000000UL
#define PLL_VCO_BAND                    1000000000UL

#define PLL_WAIT_TIME                   10000U

/********************************************************************************************************
 *                                  Global Types definition                                             *
 *******************************************************************************************************/


typedef uint32 Mcu_PllRateType;

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
Std_ReturnType Mcu_Ip_PllEnable(uint32 base, uint32 id);

Std_ReturnType Mcu_Ip_PllDisable(uint32 base, uint32 id);

Std_ReturnType Mcu_Ip_PllPrepare(uint32 base, uint32 id,
                                 Mcu_PllRateType srcRate,
                                 Mcu_PllRateType rate, boolean dsmEn);

Mcu_PllRateType Mcu_Ip_PllGetRate(uint32 base, uint32 id,
                                  Mcu_PllRateType srcRate);

Std_ReturnType Mcu_Ip_PllSetRate(uint32 base, uint32 id,
                                 Mcu_PllRateType srcRate,
                                 Mcu_PllRateType rate);

boolean Mcu_Ip_PllIsLocked(uint32 base);

/** *****************************************************************************************************
 * \brief This function set/cancle PLL force bypass.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PllForceBypass(uint32 base, boolean enable)
 *
 * Service ID[hex]    : -
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : enable - TRUE- set pll bypass; FALSE- cancel pll bypass.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : -
 *
 * Description        : This function set/cancle PLL force bypass.
 *                      Pll force bypass, pll output force to fs24M refclock.
 *                      set and cancle need use in pairs.
 * \endverbatim
 * Traceability       : SWSR_MCU_004
 *******************************************************************************************************/
void Mcu_Ip_PllForceBypass(uint32 base, boolean enable);

void Mcu_Ip_PllSetSscAmplitude(uint32 base, Mcu_CkgenSscAmplitudeType amplitude);
void Mcu_Ip_PllSetSscFrequency(uint32 base, Mcu_CkgenSscFreqType sscFreq);
Std_ReturnType Mcu_Ip_PllSetSscMode(uint32 base, Mcu_CkgenSscModeType sscMode);

#endif /* MCU_PLL_H */
/* End of file */
