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
 * \file     Icu_Register.h                                                                             *
 * \brief    This file mainly contains the etimer module register address                               *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/18     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef ICU_REGISTER_H
#define ICU_REGISTER_H

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/

/* icu register operation file */
#include "Icu_Ip.h"

/********************************************************************************************************
 *                                         Macro definition                                             *
 *******************************************************************************************************/

/* scr multi capture mux enable register address */
#ifndef SEMIDRIVE_E3_LITE_SERIES
#define ICU_MULTI_ETMR_SCR_CFG_ADDR(tmr)             ((uint32)0x100CU + ((uint32)(tmr)*0x04U))
#else
#define ICU_MULTI_ETMR_SCR_CFG_ADDR                  ((uint32)0x1070U)
#endif

/* etimer interrput related register address */
#define ICU_INT_STA_ADDR32(tmr)          (Icu_Ip_EtmrBase[tmr])
#define ICU_INT_STA_EN_ADDR32(tmr)       (Icu_Ip_EtmrBase[tmr] + (uint32)0x4U)
#define ICU_INT_SIG_EN_ADDR32(tmr)       (Icu_Ip_EtmrBase[tmr] + (uint32)0x8U)

#define ICU_COR_ERR_STA_ADDR32(tmr)      (Icu_Ip_EtmrBase[tmr] + (uint32)0xCU)
#define ICU_COR_ERR_STA_EN_ADDR32(tmr)   (Icu_Ip_EtmrBase[tmr] + (uint32)0x10U)
#define ICU_COR_ERR_STA_CHN_EN(cha)               (0x04UL + (uint32)(cha))

/* etimer clock set related register address */
#define ICU_TIM_CLK_CONFIG(tmr)          (Icu_Ip_EtmrBase[tmr] + (uint32)0xA0U)
#define ICU_BM_TIM_CLK_CONFIG_CLK_CHANGE_UPD      ((uint32)0x01U << 0x1FU)
#define ICU_FM_TIM_CLK_CONFIG_SRC_CLK_SEL         ((uint32)0x3U << 0x10U)
#define ICU_FM_TIM_CLK_CONFIG_DIV_NUM             ((uint32)0xffffU << 0U)
#define ICU_FV_TIM_CLK_CONFIG_SRC_CLK_SEL(val)    \
                                        (((uint32)(val) << 0x10U) & ICU_FM_TIM_CLK_CONFIG_SRC_CLK_SEL)
#define ICU_FV_TIM_CLK_CONFIG_DIV_NUM(val)        (uint32)(val)

#define ICU_CLK_MON_EN(tmr)              (Icu_Ip_EtmrBase[tmr] + (uint32)0xA4U)
#define ICU_BM_CLK_MON_EN_CMP_SET                 ((uint32)0x01U << 0x02U)
#define ICU_BM_CLK_MON_EN_EN_N                    ((uint32)0x01U << 0x01U)
#define ICU_BM_CLK_MON_EN_EN_P                    ((uint32)0x01U << 0x00U)

/* etimer dma control related register address */
#define ICU_CHN_DMA_CTRL(tmr)            (Icu_Ip_EtmrBase[tmr] + (uint32)0xB0U)
#define ICU_BM_CHN_DMA_CTRL_CHN_16BIT_MODE(cha)   ((uint32)0x01U << (0x10U + (uint32)(cha)))
#define ICU_BM_CHN_DMA_CTRL_CHN_SIG_MASK(cha)     ((uint32)0x01U << (0x0CU + (uint32)(cha)))
#define ICU_FM_CHN_DMA_CTRL_CHN_SEL(cha)          ((uint32)0x03U << (0x04U + ((uint32)(cha)*0x2U)))
#define ICU_BM_CHN_DMA_CTRL_CHN_EN(cha)           ((uint32)0x01U << (uint32)(cha))
#define ICU_FV_CHN_DMA_CTRL_CHN_SEL(val, cha)     ((uint32)(val) << (0x04U + ((uint32)(cha)*0x2U)))

#define ICU_CHN_DMA_WML(tmr)           (Icu_Ip_EtmrBase[tmr] + (uint32)0xB4U)
#define ICU_FM_DMA_WML_CHN(cha)        ((uint32)0xFU << ((uint32)(cha)*0x8U))
#define ICU_FV_DMA_WML_CHN(val, cha)   (((uint32)(val) << ((uint32)(cha)*0x08U)))

/* etimer fifo related register address */
#define ICU_FIFO_ADDR32(tmr, cha)        (Icu_Ip_EtmrBase[tmr] + (uint32)0xC0U + ((uint32)(cha)*0x04U))
#define ICU_FIFO_STA(tmr)                (Icu_Ip_EtmrBase[tmr] + (uint32)0xD0U)

/* etimer local counter related register address */
#define ICU_LOCAL_CNT_CFG(tmr,cha)       (Icu_Ip_EtmrBase[tmr] + (uint32)0x148U + ((uint32)(cha)*0x20U))
#define ICU_CNT_CFG_START_BY_FIRST_CPT_START_BIT  (uint32)(0x19U)
#define ICU_CNT_CFG_CPT1_CLR_EN_START_BIT         (uint32)(0x18U)
#define ICU_CNT_CFG_CPT0_CLR_EN_START_BIT         (uint32)(0x17U)
#define ICU_CNT_CFG_INIT_UPD_START_BIT            (uint32)(0x10U)
#define ICU_CNT_CFG_OVF_UPD_START_BIT             (uint32)(0x11U)

#define ICU_LOCAL_CNT_OVF_VAL(tmr, cha)  (Icu_Ip_EtmrBase[tmr] + (uint32)0x144u + ((uint32)(cha)*0x20U))
#define ICU_LOCAL_CNT_EN(tmr, cha)       (Icu_Ip_EtmrBase[tmr] + (uint32)0x14Cu + ((uint32)(cha)*0x20U))
#define ICU_LOCAL_CNT(tmr,cha)           (Icu_Ip_EtmrBase[tmr] + (uint32)0x150U + ((uint32)(cha)*0x20U))
#define ICU_LOCAL_DIFF_CNT(tmr,cha)      (Icu_Ip_EtmrBase[tmr] + (uint32)0x158U + ((uint32)(cha)*0x20U))

/* etimer capture value register address */
#define ICU_CPT0_CNT0_VALUE(tmr,cha)     (Icu_Ip_EtmrBase[tmr] + (uint32)0x1C0U + ((uint32)(cha)*0x10U))
#define ICU_CPT1_CNT0_VALUE(tmr,cha)     (Icu_Ip_EtmrBase[tmr] + (uint32)0x1C8U + ((uint32)(cha)*0x10U))

/* etimer capture module related register address */
#define ICU_CPT_CONFIG(tmr, cha)         (Icu_Ip_EtmrBase[tmr] + 0x200U + ((uint32)(cha)*0x4U))
#define ICU_CPT_CONFIG_DUAL_MODE_BIT              (uint32)(0x01U)
#define ICU_CPT_CONFIG_CPT0_TRIG_MODE_START_BIT   (uint32)(0x02U)
#define ICU_CPT_CONFIG_CPT1_TRIG_MODE_START_BIT   (uint32)(0x04U)
#define ICU_CPT_CONFIG_CNT_SEL_START_BIT          (uint32)(0x06U)

#define ICU_CPT_CTRL(tmr)                (Icu_Ip_EtmrBase[tmr] + (uint32)0x210U)
#define ICU_CPT_CTRL_CONFIG_SET_START_BIT(cha)    ((uint32)0x04U + (uint32)(cha))
#define ICU_CPT_CTRL_CPT_EN_START_BIT(cha)        (uint32)(cha)

/* etimer sse control related register address */
#define ICU_CPT_SSE_CTRL_OFF(tmr, cha)  (Icu_Ip_EtmrBase[tmr] + (uint32)0x300U + ((uint32)(cha)*0x08U))
#define ICU_FM_CPT_SSE_CTRL_EDGE_SEL           ((uint32)0x3ffU << 0x06U)
#define ICU_FM_CPT_SSE_CTRL_SSE_MODE           ((uint32)0x1fU << 0x01U)
#define ICU_BM_CPT_SSE_CTRL_SSE_EN             ((uint32)0x01U << 0x00U)
#define ICU_FV_CPT_SSE_CTRL_EDGE_SEL(val)      ((uint32)(val) << 0x06U)
#define ICU_FV_CPT_SSE_CTRL_SSE_MODE(val)      ((uint32)(val) << 0x01U)

#define ICU_CPT_SSE_REG_OFF(tmr, cha)   (Icu_Ip_EtmrBase[tmr] + (uint32)0x304U + ((uint32)(cha)*0x08U))

/* etimer filter control related register address */
#define ICU_CPT_X0_FLT(tmr, cha)        (Icu_Ip_EtmrBase[tmr] + (uint32)0x400U + ((uint32)(cha)*0x04U))
#define ICU_CPT_FLT_EN                           ((uint32)0x1U << 0x00U)
#define ICU_CPT_FLT_DISEN                        ((uint32)0x0U << 0x00U)
#define ICU_CPT_FLT_POSEDGE_SEL                  ((uint32)0x0U << 0x01U)
#define ICU_CPT_FLT_NEGEDGE_SEL                  ((uint32)0x1U << 0x01U)
#define ICU_CPT_FLT_BOTHEDGE_SEL                 ((uint32)0x2U << 0x01U)
#define ICU_CPT_FLT_POS_BAND_WID(val)            ((uint32)(val) << 0x04U)
#define ICU_CPT_FLT_NEG_BAND_WID(val)            ((uint32)(val) << 0x08U)
#define ICU_CPT_FLT_SMPL_INTVAL(val)             ((uint32)(val) << 0x0CU)

#ifdef __cplusplus
}
#endif

#endif /* ICU_REGISTER_H */
/* End of file */
