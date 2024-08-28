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
 *  \file     Gpt_Register.h                                                                            *
 *  \brief    This file contains interface header for GPT MCAL driver                                   *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/24     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef GPT_REGISTER_H
#define GPT_REGISTER_H

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                 Private Macro definition                                             *
 *******************************************************************************************************/
/**  max GPT module */
#define GPT_IP_MAX_MODULE  (6U)

/********************************************************************************************************
 *                                 Private Macro definition                                             *
 *******************************************************************************************************/
#ifdef SEMIDRIVE_E3_LITE_SERIES
/* BTM4 Base Addr */
#define APBMUX_BTM4_BASE   (0xf0450000UL)
/* BTM3 Base Addr */
#define APBMUX_BTM3_BASE   (0xf0440000UL)
/* BTM2 Base Addr */
#define APBMUX_BTM2_BASE   (0xf0430000UL)
/* BTM1 Base Addr */
#define APBMUX_BTM1_BASE   (0xf0420000UL)
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES */

#ifdef SEMIDRIVE_E3_SERIES
/* BTM6 Base Addr */
#define APBMUX_BTM6_BASE (0xf0470000UL)
/* BTM5 Base Addr */
#define APBMUX_BTM5_BASE (0xf0460000UL)
/* BTM4 Base Addr */
#define APBMUX_BTM4_BASE (0xf0450000UL)
/* BTM3 Base Addr */
#define APBMUX_BTM3_BASE (0xf0440000UL)
/* BTM2 Base Addr */
#define APBMUX_BTM2_BASE (0xf0430000UL)
/* BTM1 Base Addr */
#define APBMUX_BTM1_BASE (0xf0420000UL)
#endif /** #ifdef SEMIDRIVE_E3_SERIES */

/* G0 and G1 common control */
#define GPT_COM_CTRL_ADDR32(tm) (BTM_BASE_ADDR32[tm])

/* G0 Timer enable */
#define GPT_CNT_G0_EN_ADDR32(tm) (BTM_BASE_ADDR32[tm] + (uint32)0x4U)
/* G0 Timer config */
#define GPT_CNT_G0_CFG_ADDR32(tm) (BTM_BASE_ADDR32[tm] + (uint32)0x8U)
/* G0 Timer over flow */
#define GPT_CNT_G0_OVF_ADDR32(tm) (BTM_BASE_ADDR32[tm] + (uint32)0xCU)
/* G0 Timer value */
#define GPT_CNT_G0_VAL_ADDR32(tm) (BTM_BASE_ADDR32[tm] + (uint32)0x14U)

/* G1 Timer config */
#define GPT_CNT_G1_CFG_ADDR32(tm) (BTM_BASE_ADDR32[tm] + (uint32)0x28U)
/* G1 Timer status update regist */
#define GPT_CNT_G1_UPD_ADDR32(tm) (BTM_BASE_ADDR32[tm] + (uint32)0x38U)

/* INT status */
#define GPT_INT_STA_ADDR32(tm)    (BTM_BASE_ADDR32[tm] + (uint32)0x40U)
/* INT status enable */
#define GPT_INT_STA_EN_ADDR32(tm)    (BTM_BASE_ADDR32[tm] + (uint32)0x44U)
/* INT signer enable */
#define GPT_INT_SIG_EN_ADDR32(tm)    (BTM_BASE_ADDR32[tm] + ((uint32)0x48U))

/* G0 interrupt status bit */
#define GPT_IP_HW_CHANNEL_G0_IRQ    0x5U
/* G1 interrupt status bit */
#define GPT_IP_HW_CHANNEL_G1_IRQ    0xAU

/* Gpt us to s */
#define GPT_TIME_US (1000000UL)

/* Gpt G1 update flag signal mask */
#define GPT_CNT_G1_UPD_FLAG_SI_MASK (0x01UL << 2U)
/* Gpt G1 update over flow flag mask */
#define GPT_CNT_G1_UPD_FLAG_OVF_MASK (0x01UL << 0U)

/* counter interval statrt bit */
#define GPT_CNT_SI_VAL_MASK_START (24U)
/* counter interval bit wide */
#define GPT_CNT_SI_VAL_MASK_WIDTH (8U)
#define GPT_CNT_INC_VAL (0x01UL << 16U)

/* over flow status enable regist */
#define GPT_IP_OVFINT_EN_MASK_START(ch) ((2U + (uint32)(ch)))

/* G1 regist offset */
#define GPT_IP_REG_OFFSET_20H (0x20U)

#ifdef __cplusplus
}
#endif

#endif /* GPT_REGISTER_H */

/* End of file */
