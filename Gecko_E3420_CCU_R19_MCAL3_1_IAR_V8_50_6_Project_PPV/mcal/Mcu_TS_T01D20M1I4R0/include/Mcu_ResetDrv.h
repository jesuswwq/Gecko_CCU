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
 *  \file     Mcu_ResetDrv.h                                                                           *
 *  \brief    This file contains interface header for MCU MCAL driver, ...                             *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/02     <td>1.0.0                               *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifndef MCU_RESETDRV_H
#define MCU_RESETDRV_H

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Mcu_Reset.h"
/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
#define MCU_RESET_CORE     1U
#define MCU_RESET_LATENT   2U
#define MCU_RESET_MISSION  3U
#define MCU_RESET_MODULE   4U
#define MCU_RESET_IST      5U
#define MCU_RESET_DEBUG    6U

#define MCU_RESET_TYPE_SHIFT  24U

#define MCU_RESET_SIG_ID(type, idx) \
    ((uint32)((((uint32)(type)) << ((uint32)MCU_RESET_TYPE_SHIFT)) | ((uint32)(idx))))

#define MCU_RESET_TYPE(id)   ((uint32)(((uint32)(id)) >> ((uint32)MCU_RESET_TYPE_SHIFT)))
#define MCU_RESET_INDEX(id)  ((uint32)(((uint32)(id)) & MCU_BIT_MASK(MCU_RESET_TYPE_SHIFT)))

#define MCU_RESET_GENERAL_REG_NUM  8U

/********************************************************************************************************
 *                                  Global Types definition                                             *
 *******************************************************************************************************/
#ifndef SEMIDRIVE_E3_LITE_SERIES
/**
 * \brief SAF reset signal id.
 */
enum
{
    RSTSIG_SAF_RSTGEN_AP        = MCU_RESET_SIG_ID(MCU_RESET_CORE, 0ULL),
    RSTSIG_SAF_CR5_SAF,
    RSTSIG_SAF_CR5_SP0,
    RSTSIG_SAF_CR5_SP1,
    RSTSIG_SAF_CR5_SX0,
    RSTSIG_SAF_CR5_SX1,
    RSTSIG_SAF_MAC              = MCU_RESET_SIG_ID(MCU_RESET_LATENT, 0ULL),
    RSTSIG_SAF_SCR_BOOT         = MCU_RESET_SIG_ID(MCU_RESET_LATENT, 0ULL),
    RSTSIG_SAF_GPIO_SF          = MCU_RESET_SIG_ID(MCU_RESET_LATENT, 0ULL),
    RSTSIG_SAF_WDT1_2           = MCU_RESET_SIG_ID(MCU_RESET_LATENT, 0ULL),
    RSTSIG_SAF_SEM              = MCU_RESET_SIG_ID(MCU_RESET_LATENT, 0ULL),
    RSTSIG_SAF_MISSION0         = MCU_RESET_SIG_ID(MCU_RESET_MISSION, 0ULL),
    RSTSIG_SAF_MISSION1         = MCU_RESET_SIG_ID(MCU_RESET_MISSION, 1ULL),
    RSTSIG_SAF_MISSION2         = MCU_RESET_SIG_ID(MCU_RESET_MISSION, 2ULL),
    RSTSIG_SAF_UART             = MCU_RESET_SIG_ID(MCU_RESET_MISSION, 3ULL),
    RSTSIG_SAF_SPI              = MCU_RESET_SIG_ID(MCU_RESET_MISSION, 3ULL),
    RSTSIG_SAF_I2C              = MCU_RESET_SIG_ID(MCU_RESET_MISSION, 3ULL),
    RSTSIG_SAF_FLEXRAY          = MCU_RESET_SIG_ID(MCU_RESET_MISSION, 3ULL),
    RSTSIG_SAF_WDT5_6           = MCU_RESET_SIG_ID(MCU_RESET_MISSION, 3ULL),
    RSTSIG_SAF_MISSION4         = MCU_RESET_SIG_ID(MCU_RESET_MISSION, 4ULL),
    RSTSIG_SAF_WDT3_4           = MCU_RESET_SIG_ID(MCU_RESET_MISSION, 5ULL),
    RSTSIG_SAF_MISSION6         = MCU_RESET_SIG_ID(MCU_RESET_MISSION, 6ULL),
    RSTSIG_SAF_LDO              = MCU_RESET_SIG_ID(MCU_RESET_MISSION, 8ULL),
    RSTSIG_SAF_DCDC             = MCU_RESET_SIG_ID(MCU_RESET_MISSION, 9ULL),
    RSTSIG_SAF_CANFD1           = MCU_RESET_SIG_ID(MCU_RESET_MODULE, 0ULL),
    RSTSIG_SAF_CANFD2,
    RSTSIG_SAF_CANFD3_4,
    RSTSIG_SAF_CANFD5_8,
    RSTSIG_SAF_CANFD9_16,
    RSTSIG_SAF_CANFD17_24,
    RSTSIG_SAF_XSPI1A           = MCU_RESET_SIG_ID(MCU_RESET_MODULE, 10ULL),
    RSTSIG_SAF_XSPI1B,
    RSTSIG_SAF_XSPI2A,
    RSTSIG_SAF_XSPI2B,
    RSTSIG_SAF_DMA_RST0         = MCU_RESET_SIG_ID(MCU_RESET_MODULE, 15ULL),
    RSTSIG_SAF_DMA_RST1,
    RSTSIG_SAF_ENET1,
    RSTSIG_SAF_ENET2,
    RSTSIG_SAF_GAMA1            = MCU_RESET_SIG_ID(MCU_RESET_MODULE, 21ULL),
    RSTSIG_SAF_AHB_SYNCUP_GAMA1 = MCU_RESET_SIG_ID(MCU_RESET_MODULE, 21ULL),
    RSTSIG_SAF_GAMA2            = MCU_RESET_SIG_ID(MCU_RESET_MODULE, 22ULL),
    RSTSIG_SAF_AHB_SYNCUP_GAMA2 = MCU_RESET_SIG_ID(MCU_RESET_MODULE, 22ULL),
    RSTSIG_SAF_VIC1,
    RSTSIG_SAF_VIC2_PORTA,
    RSTSIG_SAF_VIC2_PORTB,
    RSTSIG_SAF_VIC3_PORTA       = MCU_RESET_SIG_ID(MCU_RESET_MODULE, 27ULL),
    RSTSIG_SAF_VIC3_PORTB,
    RSTSIG_SAF_XSPI_SLV,
    RSTSIG_SAF_MB,
    RSTSIG_SAF_XTRG,
    RSTSIG_SAF_DEBUG            = MCU_RESET_SIG_ID(MCU_RESET_DEBUG, 0ULL),
};

/**
 * \brief AP reset signal id.
 */
enum
{
    RSTSIG_AP_MISSION0     = MCU_RESET_SIG_ID(MCU_RESET_MISSION, 0ULL),
    RSTSIG_AP_DISP_MUX     = MCU_RESET_SIG_ID(MCU_RESET_MISSION, 1ULL),
    RSTSIG_AP_GPIO_AP      = MCU_RESET_SIG_ID(MCU_RESET_MISSION, 1ULL),
    RSTSIG_AP_WDT8         = MCU_RESET_SIG_ID(MCU_RESET_MISSION, 1ULL),
    RSTSIG_AP_SCR_AP       = MCU_RESET_SIG_ID(MCU_RESET_MISSION, 1ULL),
    RSTSIG_AP_MISSION1     = MCU_RESET_SIG_ID(MCU_RESET_MISSION, 1ULL),
    RSTSIG_AP_CSI          = MCU_RESET_SIG_ID(MCU_RESET_MODULE, 0ULL),
    RSTSIG_AP_DC,
    RSTSIG_AP_G2D,
    RSTSIG_AP_SDRAMC,
    RSTSIG_AP_SACI1,
    RSTSIG_AP_SACI2,//5
    RSTSIG_AP_DMA_AP,
    RSTSIG_AP_SEHC1,
    RSTSIG_AP_SEHC2,
    RSTSIG_AP_USB,
    RSTSIG_AP_SEIP,//10
    RSTSIG_AP_LVDS_SS     = MCU_RESET_SIG_ID(MCU_RESET_MODULE, 12ULL),
    RSTSIG_AP_DEBUG       = MCU_RESET_SIG_ID(MCU_RESET_DEBUG, 0ULL),
};
#else
enum
{
    RSTSIG_SAF_CR5_SAF          = MCU_RESET_SIG_ID(MCU_RESET_CORE, 0ULL),
    RSTSIG_SAF_BOOT             = MCU_RESET_SIG_ID(MCU_RESET_LATENT, 0ULL),
    RSTSIG_SAF_SS               = MCU_RESET_SIG_ID(MCU_RESET_MISSION, 0ULL),
    RSTSIG_SAF_PLL              = MCU_RESET_SIG_ID(MCU_RESET_MISSION, 1ULL),
    RSTSIG_SAF_ANA_MIX          = MCU_RESET_SIG_ID(MCU_RESET_MISSION, 2ULL),
    RSTSIG_SAF_IRAM_MIX         = MCU_RESET_SIG_ID(MCU_RESET_MISSION, 3ULL),
    RSTSIG_SAF_DCDC_MIX         = MCU_RESET_SIG_ID(MCU_RESET_MISSION, 4ULL),
    RSTSIG_SAF_AP_MIX           = MCU_RESET_SIG_ID(MCU_RESET_MISSION, 5ULL),
    RSTSIG_SAF_CANFD16          = MCU_RESET_SIG_ID(MCU_RESET_MODULE, 0ULL),
    RSTSIG_SAF_CANFD21,
    RSTSIG_SAF_CANFD3,
    RSTSIG_SAF_CANFD4,
    RSTSIG_SAF_CANFD5,
    RSTSIG_SAF_CANFD6           = MCU_RESET_SIG_ID(MCU_RESET_MODULE, 5ULL),
    RSTSIG_SAF_CANFD7,
    RSTSIG_SAF_CANFD23,
    RSTSIG_SAF_XSPI1A,
    RSTSIG_SAF_XSPI1B,
    RSTSIG_SAF_DMA_RST0         = MCU_RESET_SIG_ID(MCU_RESET_MODULE, 10ULL),
    RSTSIG_SAF_DMA_RST1,
    RSTSIG_SAF_ENET1,
    RSTSIG_SAF_VIC1,
    RSTSIG_SAF_XSPI_SLV,
    RSTSIG_SAF_XTRG             = MCU_RESET_SIG_ID(MCU_RESET_MODULE, 15ULL),
    RSTSIG_SAF_SACI1,
    RSTSIG_SAF_SEHC1,
    RSTSIG_SAF_USB,
    RSTSIG_SAF_SEIP,
    RSTSIG_SAF_CSLITE           = MCU_RESET_SIG_ID(MCU_RESET_MODULE, 20ULL),
};

#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/

extern const Mcu_ResetCtlOpsType Mcu_RstCtlOps;

#endif /* MCU_RESETDRV_H */
/* End of file */
