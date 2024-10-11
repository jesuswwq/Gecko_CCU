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
 *  \file     Mcu_KickCore.h                                                                            *
 *  \brief    This file contains interface header for Mcu MCAL driver, ...                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/02     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef MCU_KICKCORE_H
#define MCU_KICKCORE_H

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Platform_Types.h"
#include "Std_Types.h"

/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
#define STICKY_REG_OFF          (0x4U)
#define MCU_SCR_SF_DOMAIN       (0U)
#define MCU_TYPE_RW             (0U)
#define MCU_TYPE_L31            (3U)
#define MCU_TYPE_R16W16         (4U)
#define MCU_SCR_SW_TYPE_OFFSET  (0x1000U)
#define MCU_SCR_L31_TYPE_OFFSET (0x1400U)
#define MCU_SCR_R16W16_TYPE_OFFSET (0x1600U)
#ifndef SEMIDRIVE_E3_LITE_SERIES
#define MCU_SCR_SF_REMAP_CR5_SF_AW_ADDR_OFFSET_19_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_L31, 0U, 20U}
#define MCU_SCR_SF_SCR_REMAP_CR5_SF_REMAP_EN  {MCU_SCR_SF_DOMAIN, MCU_TYPE_L31, 20U, 1U}
#define MCU_SCR_SF_REMAP_CR5_SF_AR_ADDR_OFFSET_19_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_L31, 0U, 20U}
#define MCU_SCR_SF_REMAP_CR5_SX_AW0_ADDR_OFFSET_19_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_L31, 32U, 20U}
#define MCU_SCR_SF_REMAP_CR5_SX_AW0_REMAP_EN  {MCU_SCR_SF_DOMAIN, MCU_TYPE_L31, 52U, 1U}
#define MCU_SCR_SF_REMAP_CR5_SX_AR0_ADDR_OFFSET_19_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_L31, 32U, 20U}
#define MCU_SCR_SF_REMAP_CR5_SX_AR0_REMAP_EN  {MCU_SCR_SF_DOMAIN, MCU_TYPE_L31, 52U, 1U}
#define MCU_SCR_SF_REMAP_CR5_SX_AW1_ADDR_OFFSET_19_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_L31, 64U, 20U}
#define MCU_SCR_SF_REMAP_CR5_SX_AW1_REMAP_EN  {MCU_SCR_SF_DOMAIN, MCU_TYPE_L31, 84U, 1U}
#define MCU_SCR_SF_REMAP_CR5_SX_AR1_ADDR_OFFSET_19_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_L31, 64U, 20U}
#define MCU_SCR_SF_REMAP_CR5_SX_AR1_REMAP_EN  {MCU_SCR_SF_DOMAIN, MCU_TYPE_L31, 84U, 1U}
#define MCU_SCR_SF_REMAP_CR5_SP_AW0_ADDR_OFFSET_19_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_L31, 96U, 20U}
#define MCU_SCR_SF_REMAP_CR5_SP_AW0_REMAP_EN  {MCU_SCR_SF_DOMAIN, MCU_TYPE_L31, 116U, 1U}
#define MCU_SCR_SF_REMAP_CR5_SP_AR0_ADDR_OFFSET_19_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_L31, 96U, 20U}
#define MCU_SCR_SF_REMAP_CR5_SP_AR0_REMAP_EN  {MCU_SCR_SF_DOMAIN, MCU_TYPE_L31, 116U, 1U}
#define MCU_SCR_SF_REMAP_CR5_SP_AW1_ADDR_OFFSET_19_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_L31, 128U, 20U}
#define MCU_SCR_SF_REMAP_CR5_SP_AW1_REMAP_EN  {MCU_SCR_SF_DOMAIN, MCU_TYPE_L31, 148U, 1U}
#define MCU_SCR_SF_REMAP_CR5_SP_AR1_ADDR_OFFSET_19_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_L31, 128U, 20U}
#define MCU_SCR_SF_REMAP_CR5_SP_AR1_REMAP_EN  {MCU_SCR_SF_DOMAIN, MCU_TYPE_L31, 148U, 1U}
#define MCU_SCR_SF_VIC2_IS_LOCKSTEP_MODE_P  {MCU_SCR_SF_DOMAIN, MCU_TYPE_L31, 352U, 1U}
#define MCU_SCR_SF_VIC3_IS_LOCKSTEP_MODE_P  {MCU_SCR_SF_DOMAIN, MCU_TYPE_L31, 384U, 1U}
#define MCU_SCR_SF_SCR_CR5_SP_LS_DISABLE  {MCU_SCR_SF_DOMAIN, MCU_TYPE_L31, 416U, 1U}
#define MCU_SCR_SF_SCR_CR5_SP_SLCLAMP_DISABLE  {MCU_SCR_SF_DOMAIN, MCU_TYPE_L31, 417U, 1U}
#define MCU_SCR_SF_SCR_CR5_SX_LS_DISABLE  {MCU_SCR_SF_DOMAIN, MCU_TYPE_L31, 448U, 1U}
#define MCU_SCR_SF_SCR_CR5_SX_SLCLAMP_DISABLE  {MCU_SCR_SF_DOMAIN, MCU_TYPE_L31, 449U, 1U}
#define MCU_SCR_SF_CR5_SX_DCCMINP_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_RW, 676U, 1U}
#define MCU_SCR_SF_CR5_SX_DCCMINP2_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_RW, 677U, 1U}
#define MCU_SCR_SF_CR5_SP_DCCMINP_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_RW, 644U, 1U}
#define MCU_SCR_SF_CR5_SP_DCCMINP2_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_RW, 645U, 1U}
#define MCU_SCR_SF_SCR_CR5_SF_DCCMINP_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_RW, 612U, 1U}
#define MCU_SCR_SF_BTI_SF_M0_TIMEOUT_DIV_7_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 0U, 8U}
#define MCU_SCR_SF_BTI_SF_M0_BTI_EN  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 8U, 1U}
#define MCU_SCR_SF_BTI_SF_P0_TIMEOUT_DIV_7_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 32U, 8U}
#define MCU_SCR_SF_BTI_SF_P0_BTI_EN  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 40U, 1U}
#define MCU_SCR_SF_BTI_SF_AHB_TIMEOUT_DIV_7_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 64U, 8U}
#define MCU_SCR_SF_BTI_SF_AHB_BTI_EN  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 72U, 1U}
#define MCU_SCR_SF_BTI_SX_M0_TIMEOUT_DIV_7_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 96U, 8U}
#define MCU_SCR_SF_BTI_SX_M0_BTI_EN  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 104U, 1U}
#define MCU_SCR_SF_BTI_SX_P0_TIMEOUT_DIV_7_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 128U, 8U}
#define MCU_SCR_SF_BTI_SX_P0_BTI_EN  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 136U, 1U}
#define MCU_SCR_SF_BTI_SX_M1_TIMEOUT_DIV_7_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 160U, 8U}
#define MCU_SCR_SF_BTI_SX_M1_BTI_EN  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 168U, 1U}
#define MCU_SCR_SF_BTI_SX_P1_TIMEOUT_DIV_7_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 192U, 8U}
#define MCU_SCR_SF_BTI_SX_P1_BTI_EN  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 200U, 1U}
#define MCU_SCR_SF_BTI_SX_AHB_TIMEOUT_DIV_7_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 224U, 8U}
#define MCU_SCR_SF_BTI_SX_AHB_BTI_EN  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 232U, 1U}
#define MCU_SCR_SF_BTI_DISPSF_TIMEOUT_DIV_7_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 256U, 8U}
#define MCU_SCR_SF_BTI_DISPSF_BTI_EN  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 264U, 1U}
#define MCU_SCR_SF_BTI_APSF_TIMEOUT_DIV_7_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 288U, 8U}
#define MCU_SCR_SF_BTI_APSF_BTI_EN  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 296U, 1U}
#define MCU_SCR_SF_BTI_SP_M0_TIMEOUT_DIV_7_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 320U, 8U}
#define MCU_SCR_SF_BTI_SP_M0_BTI_EN  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 328U, 1U}
#define MCU_SCR_SF_BTI_SP_P0_TIMEOUT_DIV_7_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 352U, 8U}
#define MCU_SCR_SF_BTI_SP_P0_BTI_EN  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 360U, 1U}
#define MCU_SCR_SF_BTI_SP0_AHB_TIMEOUT_DIV_7_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 384U, 8U}
#define MCU_SCR_SF_BTI_SP0_AHB_BTI_EN  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 392U, 1U}
#define MCU_SCR_SF_BTI_SP_M1_TIMEOUT_DIV_7_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 416U, 8U}
#define MCU_SCR_SF_BTI_SP_M1_BTI_EN  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 424U, 1U}
#define MCU_SCR_SF_BTI_SP_P1_TIMEOUT_DIV_7_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 448U, 8U}
#define MCU_SCR_SF_BTI_SP_P1_BTI_EN  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 456U, 1U}
#define MCU_SCR_SF_AAPB_XSPI1A_SRC_IRQ_ENB  {MCU_SCR_SF_DOMAIN, MCU_TYPE_RW, 352U, 1U}
#define MCU_SCR_SF_AAPB_XSPI1A_SRC_UNCERR_CLR  {MCU_SCR_SF_DOMAIN, MCU_TYPE_RW, 353U, 1U}
#define MCU_SCR_SF_AAPB_XSPI1A_DST_IRQ_ENB  {MCU_SCR_SF_DOMAIN, MCU_TYPE_RW, 354U, 1U}
#define MCU_SCR_SF_AAPB_XSPI1A_DST_UNCERR_CLR  {MCU_SCR_SF_DOMAIN, MCU_TYPE_RW, 355U, 1U}
#define MCU_SCR_SF_AAPB_XSPI1B_SRC_IRQ_ENB  {MCU_SCR_SF_DOMAIN, MCU_TYPE_RW, 356U, 1U}
#define MCU_SCR_SF_AAPB_XSPI1B_SRC_UNCERR_CLR  {MCU_SCR_SF_DOMAIN, MCU_TYPE_RW, 357U, 1U}
#define MCU_SCR_SF_AAPB_XSPI1B_DST_IRQ_ENB  {MCU_SCR_SF_DOMAIN, MCU_TYPE_RW, 358U, 1U}
#define MCU_SCR_SF_AAPB_XSPI1B_DST_UNCERR_CLR  {MCU_SCR_SF_DOMAIN, MCU_TYPE_RW, 359U, 1U}
#define MCU_SCR_SF_AAPB_XSPI2A_SRC_IRQ_ENB  {MCU_SCR_SF_DOMAIN, MCU_TYPE_RW, 360U, 1U}
#define MCU_SCR_SF_AAPB_XSPI2A_SRC_UNCERR_CLR  {MCU_SCR_SF_DOMAIN, MCU_TYPE_RW, 361U, 1U}
#define MCU_SCR_SF_AAPB_XSPI2A_DST_IRQ_ENB  {MCU_SCR_SF_DOMAIN, MCU_TYPE_RW, 362U, 1U}
#define MCU_SCR_SF_AAPB_XSPI2A_DST_UNCERR_CLR  {MCU_SCR_SF_DOMAIN, MCU_TYPE_RW, 363U, 1U}
#define MCU_SCR_SF_AAPB_XSPI2B_SRC_IRQ_ENB  {MCU_SCR_SF_DOMAIN, MCU_TYPE_RW, 364U, 1U}
#define MCU_SCR_SF_AAPB_XSPI2B_SRC_UNCERR_CLR  {MCU_SCR_SF_DOMAIN, MCU_TYPE_RW, 365U, 1U}
#define MCU_SCR_SF_AAPB_XSPI2B_DST_IRQ_ENB  {MCU_SCR_SF_DOMAIN, MCU_TYPE_RW, 366U, 1U}
#define MCU_SCR_SF_AAPB_XSPI2B_DST_UNCERR_CLR  {MCU_SCR_SF_DOMAIN, MCU_TYPE_RW, 367U, 1U}
#else
#define MCU_SCR_SF_REMAP_CR5_SF_AW_ADDR_OFFSET_19_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_L31, 0U, 20U}
#define MCU_SCR_SF_SCR_REMAP_CR5_SF_REMAP_EN  {MCU_SCR_SF_DOMAIN, MCU_TYPE_L31, 20U, 1U}
#define MCU_SCR_SF_REMAP_CR5_SF_AR_ADDR_OFFSET_19_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_L31, 0U, 20U}
#define MCU_SCR_SF_SCR_CR5_SF_DCCMINP_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_RW, 452U, 1U}
#define MCU_SCR_SF_BTI_SF_M0_TIMEOUT_DIV_7_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 0U, 8U}
#define MCU_SCR_SF_BTI_SF_M0_BTI_EN  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 8U, 1U}
#define MCU_SCR_SF_BTI_SF_P0_TIMEOUT_DIV_7_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 32U, 8U}
#define MCU_SCR_SF_BTI_SF_P0_BTI_EN  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 40U, 1U}
#define MCU_SCR_SF_BTI_SF_AHB_TIMEOUT_DIV_7_0  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 64U, 8U}
#define MCU_SCR_SF_BTI_SF_AHB_BTI_EN  {MCU_SCR_SF_DOMAIN, MCU_TYPE_R16W16, 72U, 1U}
#define MCU_SCR_SF_AAPB_XSPI1A_SRC_IRQ_ENB  {MCU_SCR_SF_DOMAIN, MCU_TYPE_RW, 192U, 1U}
#define MCU_SCR_SF_AAPB_XSPI1A_SRC_UNCERR_CLR  {MCU_SCR_SF_DOMAIN, MCU_TYPE_RW, 193U, 1U}
#define MCU_SCR_SF_AAPB_XSPI1A_DST_IRQ_ENB  {MCU_SCR_SF_DOMAIN, MCU_TYPE_RW, 194U, 1U}
#define MCU_SCR_SF_AAPB_XSPI1A_DST_UNCERR_CLR  {MCU_SCR_SF_DOMAIN, MCU_TYPE_RW, 195U, 1U}
#define MCU_SCR_SF_AAPB_XSPI1B_SRC_IRQ_ENB  {MCU_SCR_SF_DOMAIN, MCU_TYPE_RW, 196U, 1U}
#define MCU_SCR_SF_AAPB_XSPI1B_SRC_UNCERR_CLR  {MCU_SCR_SF_DOMAIN, MCU_TYPE_RW, 197U, 1U}
#define MCU_SCR_SF_AAPB_XSPI1B_DST_IRQ_ENB  {MCU_SCR_SF_DOMAIN, MCU_TYPE_RW, 198U, 1U}
#define MCU_SCR_SF_AAPB_XSPI1B_DST_UNCERR_CLR  {MCU_SCR_SF_DOMAIN, MCU_TYPE_RW, 199U, 1U}
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/
/********************************************************************************************************
 *                                  Global Types definition                                             *
 *******************************************************************************************************/
/* NOTE: This enum shall be only used for core kicking scenario */
typedef enum
{
    KICK_CR5_SF = 0,
    KICK_CR5_SP0,
    KICK_CR5_SP1,
    KICK_CR5_SX0,
    KICK_CR5_SX1,
    KICK_CR5_SX,
    KICK_CR5_SP,
    KICK_CORE_MAX,
} Mcu_KickCoreType;

typedef struct
{
    uint8         domain;
    uint16        type;       /* signal type */
    uint16        startBit;
    uint16        width;
} Mcu_ScrSignalType;

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
void Mcu_Ip_SocScrSetBit(const Mcu_ScrSignalType *signalPtr, uint32 value);
Std_ReturnType Mcu_Ip_SocKickCore(Mcu_KickCoreType core, uint32 entry);
void Mcu_Ip_SocBtiEnableSf(void);
void Mcu_Ip_SocBtiEnable(void);

#endif /* MCU_KICKCORE_H */
/* End of file */
