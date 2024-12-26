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
 *  \file     Dio_Cfg.h                                                                                 *
 *  \brief    This file contains interface header for DIO MCAL config.                                  *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date                 <th>Version                                                             *
 * <tr><td>2024-03-08 16:29:00      <td>1.0.0 R                                            *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef DIO_CFG_H
#define DIO_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Dio_Types.h"
#include "BswM_Check_Action.h"

 /**
 *  \addtogroup MCAL_DIO_MACRO DIO macro
 *  \{
 */

/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
 /**
 *  \name DIO software version macro
 *  \{
 */
/* autosar version information */
/** \brief  DIO driver autosar major version */
#define DIO_AR_RELEASE_MAJOR_VERSION      (0x04U)
/** \brief  DIO driver autosar minor version */
#define DIO_AR_RELEASE_MINOR_VERSION      (0x03U)
/** \brief  DIO driver autosar revision version */
#define DIO_AR_RELEASE_REVISION_VERSION   (0x01U)
/* semidrive driver information */
/** \brief  DIO driver vendor major version */
#define DIO_SW_MAJOR_VERSION              (0x03U)
/** \brief  DIO driver vendor minor version */
#define DIO_SW_MINOR_VERSION              (0x01U)
/** \brief  DIO driver vendor patch version */
#define DIO_SW_PATCH_VERSION              (0x00U)
/** \} */

 /**
 *  \name DIO service enable/diable defines
 *
 *  Pre-compile switches for enabling/disabling DIO MCAL APIs
 *  \{
 */
/** \brief Enable/Disable DEV error detection */
#define DIO_DEV_ERROR_DETECT                (STD_ON)

/** \brief Enable/Disable Dio_GetVersionInfo() */
#define DIO_VERSION_INFO_API                (STD_ON)

/** \brief Enable/Disable Dio_FlipChannel() */
#define DIO_FLIP_CHANNEL_API                (STD_ON)

/** \brief Enable/Disable safety */
#define DIO_SAFETY_ENABLE                (STD_ON)
/* \} */


 /**
 *  \name DIO port/channel max defines
 *  \{
 */
/** \brief Max port ID */
#define DIO_MAXNOOFPORT                     ((Dio_PortType)7UL)
/** \brief Max channel ID */
#define DIO_MAXNOOFCHANNEL                  ((Dio_ChannelType)214UL)

/** \brief SF domain max channel ID */
#define DIO_SF_CHANNEL_NUM 0x87UL

/** \brief AP domain max channel ID */
#define DIO_AP_CHANNEL_NUM 0x4FUL

/** \brief SF domain max port ID */
#define DIO_SF_PORT_NUM 0x5UL

/** \brief AP domain max port ID */
#define DIO_AP_PORT_NUM 0x3UL
/* \} */

/**
 *  \name Symbolic name of DIO PORTs
 *
 *  This is symbolic name of DIO ports generated from configurator
 *  These defines map to physical GPIO register numbers.
 * \{
 */

/** \brief Symbolic name for GPIO REG #0x00 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioPort_DioPort_0_31  ((uint8)0x00U)

/** \brief Shorter Symbolic name for GPIO channel #18 DioChannel_7012_A_IN0 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_7012_A_IN0 ((uint16)18U)

/** \brief Shorter Symbolic name for GPIO channel #17 DioChannel_7012_A_IN1 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_7012_A_IN1 ((uint16)17U)
/* \} */

/** \brief Symbolic name for GPIO REG #0x01 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioPort_DioPort_32_63  ((uint8)0x01U)

/** \brief Shorter Symbolic name for GPIO channel #37 DioChannel_7012_B_IN1 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_7012_B_IN1 ((uint16)37U)

/** \brief Shorter Symbolic name for GPIO channel #44 DioChannel_FLASH_GPIO_A15 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_FLASH_GPIO_A15 ((uint16)44U)

/** \brief Shorter Symbolic name for GPIO channel #38 DioChannel_NJJ29C0_GPIO_A9 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_NJJ29C0_GPIO_A9 ((uint16)38U)

/** \brief Shorter Symbolic name for GPIO channel #39 DioChannel_NCK2910_GPIO_A10 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_NCK2910_GPIO_A10 ((uint16)39U)
#if BSWM_TEST
/**
* @brief    Symbolic name for channel.
*/
#define DioConf_DioChannel_DioChannel_UART7_TX_GPIO_B2 ((uint16)47U)

/**
* @brief    Symbolic name for channel.
*/
#define DioConf_DioChannel_DioChannel_UART7_RX_GPIO_B3 ((uint16)48U)
#endif
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioPort_DioPort_64_95  ((uint8)0x02U)

/** \brief Shorter Symbolic name for GPIO channel #89 DioChannel_7020_A_IN0 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_7020_A_IN0 ((uint16)89U)

/** \brief Shorter Symbolic name for GPIO channel #95 DioChannel_7020_A_IN1 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_7020_A_IN1 ((uint16)95U)

/** \brief Shorter Symbolic name for GPIO channel #92 DioChannel_7012_C_IN0 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_7012_C_IN0 ((uint16)92U)

/** \brief Shorter Symbolic name for GPIO channel #91 DioChannel_GPIO_M2_TCA6424_INT */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_GPIO_M2_TCA6424_INT ((uint16)91U)
/* \} */

/** \brief Symbolic name for GPIO REG #0x03 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioPort_DioPort_96_127  ((uint8)0x03U)

/** \brief Shorter Symbolic name for GPIO channel #98 Dio_75242_A_IN0 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_Dio_75242_A_IN0 ((uint16)98U)

/** \brief Shorter Symbolic name for GPIO channel #121 Dio_75242_A_IN1 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_Dio_75242_A_IN1 ((uint16)121U)

/** \brief Shorter Symbolic name for GPIO channel #96 DioChannel_7020_B_IN0 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_7020_B_IN0 ((uint16)96U)

/** \brief Shorter Symbolic name for GPIO channel #97 DioChannel_7020_B_IN1 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_7020_B_IN1 ((uint16)97U)

/** \brief Shorter Symbolic name for GPIO channel #116 DioChannel_7012_B_IN0 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_7012_B_IN0 ((uint16)116U)

/** \brief Shorter Symbolic name for GPIO channel #127 DioChannel_7120_B_IN0 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_7120_B_IN0 ((uint16)127U)

/** \brief Shorter Symbolic name for GPIO channel #118 DioChannel_7120_B_IN1 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_7120_B_IN1 ((uint16)118U)

/** \brief Shorter Symbolic name for GPIO channel #123 DioChannel_7120_D_IN1 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_7120_D_IN1 ((uint16)123U)

/** \brief Shorter Symbolic name for GPIO channel #119 DioChannel_7120_D_IN0 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_7120_D_IN0 ((uint16)119U)

/** \brief Shorter Symbolic name for GPIO channel #103 DioChannel_7012_C_IN1 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_7012_C_IN1 ((uint16)103U)

/** \brief Shorter Symbolic name for GPIO channel #122 DioChannel_8108_IN1 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_8108_IN1 ((uint16)122U)

/** \brief Shorter Symbolic name for GPIO channel #124 DioChannel_8108_IN3 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_8108_IN3 ((uint16)124U)

/** \brief Shorter Symbolic name for GPIO channel #125 DioChannel_8108_IN4 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_8108_IN4 ((uint16)125U)

/** \brief Shorter Symbolic name for GPIO channel #106 DioChannel_8108_IN2 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_8108_IN2 ((uint16)106U)
/* \} */

/** \brief Symbolic name for GPIO REG #0x04 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioPort_DioPort_128_134  ((uint8)0x04U)
/* \} */

/** \brief Symbolic name for GPIO REG #0x05 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioPort_DioPort_135_166  ((uint8)0x05U)

/** \brief Shorter Symbolic name for GPIO channel #147 RESET_6424_AC_IN */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_RESET_6424_AC_IN ((uint16)147U)

/** \brief Shorter Symbolic name for GPIO channel #165 RESET_6424_BD_9539 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_RESET_6424_BD_9539 ((uint16)165U)

/** \brief Shorter Symbolic name for GPIO channel #163 Dio_75242_B_IN0 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_Dio_75242_B_IN0 ((uint16)163U)

/** \brief Shorter Symbolic name for GPIO channel #164 Dio_75242_B_IN1 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_Dio_75242_B_IN1 ((uint16)164U)

/** \brief Shorter Symbolic name for GPIO channel #148 DioChannel_GPIO_D3_SYSERR_EN */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_GPIO_D3_SYSERR_EN ((uint16)148U)

/** \brief Shorter Symbolic name for GPIO channel #161 DioChannel_7E100A_IN0 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_7E100A_IN0 ((uint16)161U)

/** \brief Shorter Symbolic name for GPIO channel #162 DioChannel_7E100A_IN2 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_7E100A_IN2 ((uint16)162U)

/** \brief Shorter Symbolic name for GPIO channel #166 DioChannel_BR_INTB */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_BR_INTB ((uint16)166U)
/* \} */

/** \brief Symbolic name for GPIO REG #0x06 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioPort_DioPort_167_198  ((uint8)0x06U)

/** \brief Shorter Symbolic name for GPIO channel #184 ADC_EXP_C_S0 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_ADC_EXP_C_S0 ((uint16)184U)

/** \brief Shorter Symbolic name for GPIO channel #186 ADC_EXP_C_S1 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_ADC_EXP_C_S1 ((uint16)186U)

/** \brief Shorter Symbolic name for GPIO channel #183 ADC_EXP_C_S2 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_ADC_EXP_C_S2 ((uint16)183U)

/** \brief Shorter Symbolic name for GPIO channel #180 ADC_EXP_C_S3 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_ADC_EXP_C_S3 ((uint16)180U)

/** \brief Shorter Symbolic name for GPIO channel #178 ADC_EXP_D_S2 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_ADC_EXP_D_S2 ((uint16)178U)

/** \brief Shorter Symbolic name for GPIO channel #176 ADC_EXP_D_S3 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_ADC_EXP_D_S3 ((uint16)176U)

/** \brief Shorter Symbolic name for GPIO channel #194 ADC_EXP_E_S0 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_ADC_EXP_E_S0 ((uint16)194U)

/** \brief Shorter Symbolic name for GPIO channel #193 ADC_EXP_D_S0 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_ADC_EXP_D_S0 ((uint16)193U)

/** \brief Shorter Symbolic name for GPIO channel #190 ADC_EXP_E_S1 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_ADC_EXP_E_S1 ((uint16)190U)

/** \brief Shorter Symbolic name for GPIO channel #198 ADC_EXP_D_S1 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_ADC_EXP_D_S1 ((uint16)198U)

/** \brief Shorter Symbolic name for GPIO channel #182 RKE_INT_GPIO_D37 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_RKE_INT_GPIO_D37 ((uint16)182U)

/** \brief Shorter Symbolic name for GPIO channel #173 LF_INT_GPIO_D28 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_LF_INT_GPIO_D28 ((uint16)173U)

/** \brief Shorter Symbolic name for GPIO channel #175 DioChannel_WAKEUP_D30 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_WAKEUP_D30 ((uint16)175U)

/** \brief Shorter Symbolic name for GPIO channel #167 DioChannel_BR_RSTB */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_BR_RSTB ((uint16)167U)

/** \brief Shorter Symbolic name for GPIO channel #168 DioChannel_ANT_BLE_DET */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_ANT_BLE_DET ((uint16)168U)

/** \brief Shorter Symbolic name for GPIO channel #169 DioChannel_ETH_TX_RST */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_ETH_TX_RST ((uint16)169U)

/** \brief Shorter Symbolic name for GPIO channel #170 DioChannel_BR_PWREN */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_BR_PWREN ((uint16)170U)

/** \brief Shorter Symbolic name for GPIO channel #172 DioChannel_9539A_INT */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_9539A_INT ((uint16)172U)

/** \brief Shorter Symbolic name for GPIO channel #174 DioChannel_ETH_TX_INT_B */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_ETH_TX_INT_B ((uint16)174U)

/** \brief Shorter Symbolic name for GPIO channel #177 DioChannel_EPB_B_MOS_EN */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_EPB_B_MOS_EN ((uint16)177U)

/** \brief Shorter Symbolic name for GPIO channel #179 DioChannel_HALL_INPUT_EN */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_HALL_INPUT_EN ((uint16)179U)

/** \brief Shorter Symbolic name for GPIO channel #181 DioChannel_9539_B_INT */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_9539_B_INT ((uint16)181U)

/** \brief Shorter Symbolic name for GPIO channel #197 DioChannel_MCU_MPU_GPIO5 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_MCU_MPU_GPIO5 ((uint16)197U)
/* \} */

/** \brief Symbolic name for GPIO REG #0x07 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioPort_DioPort_199_213  ((uint8)0x07U)

/** \brief Shorter Symbolic name for GPIO channel #203 ADC_EXP_E_S2 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_ADC_EXP_E_S2 ((uint16)203U)

/** \brief Shorter Symbolic name for GPIO channel #202 ADC_EXP_E_S3 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_ADC_EXP_E_S3 ((uint16)202U)

/** \brief Shorter Symbolic name for GPIO channel #204 DioChannel_GPIO_E17 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_GPIO_E17 ((uint16)204U)

/** \brief Shorter Symbolic name for GPIO channel #205 DioChannel_GPIO_E18 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_GPIO_E18 ((uint16)205U)

/** \brief Shorter Symbolic name for GPIO channel #199 DioChannel_MCU_MPU_GPIO4 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_MCU_MPU_GPIO4 ((uint16)199U)

/** \brief Shorter Symbolic name for GPIO channel #207 DioChannel_MCU_MPU_GPIO3 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_MCU_MPU_GPIO3 ((uint16)207U)

/** \brief Shorter Symbolic name for GPIO channel #213 DioChannel_MCU_MPU_GPIO6 */
/**
 * Traceability       : SWSR_DIO_009 SWSR_DIO_010 SWSR_DIO_042
 */
#define DioConf_DioChannel_DioChannel_MCU_MPU_GPIO6 ((uint16)213U)
/* \} */
/** \} */


/********************************************************************************************************
 *                                  Global Constant Declarations                                        *
 *******************************************************************************************************/
/** \brief Channel mask for enabled pins in the available ports */

/**
 * Traceability       : SWSR_DIO_074
 */
extern void (*Dio_InterruptNotification)(Dio_ChannelType channelId);

#ifdef __cplusplus
}
#endif

#endif /* DIO_CFG_H */

/* End of file */
