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
 *  \file     Port_Cfg.h                                                                                *
 *  \brief    Semidrive. AUTOSAR 4.3.1 MCAL Port Driver.                                                *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date                 <th>Version                                                             *
 * <tr><td>2024-03-08 16:29:00      <td>1.0.0 R                                            *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef PORT_CFG_H
#define PORT_CFG_H
#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Port_Types.h"
#include "BswM_Check_Action.h"
/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
/**
 *  \addtogroup MCAL_PORT_MACRO PORT Macro
 *  @{
 *
 */

 /**
 *  \name Port Module generation version.
 *
 *  @{
 */
/** \brief  Generate Autosar Specific Version Information. */
#define PORT_AR_RELEASE_MAJOR_VERSION                                    (4U)
#define PORT_AR_RELEASE_MINOR_VERSION                                    (3U)
#define PORT_AR_RELEASE_REVISION_VERSION                                 (1U)

/** \brief  Generate Vendor Specific Version Information. */
#define PORT_SW_MAJOR_VERSION                                            (3U)
#define PORT_SW_MINOR_VERSION                                            (1U)
#define PORT_SW_PATCH_VERSION                                            (0U)

/** @} */

/**
 *  \name Pre-compile switches for enabling/disabling PORT MCAL APIs.
 *
 *  @{
 */
/** \brief  Derived Configuration for PortDevErrorDetect */
#define PORT_DEV_ERROR_DETECT       (STD_OFF)
/** \brief  Derived Configuration for PortSafetyEnable */
#define PORT_SAFETY_ENABLE          (STD_ON)
/** \brief  Derived Configuration for Port_GetVersionInfo API */
#define PORT_VERSION_INFO_API       (STD_OFF)
/** \brief  Derived Configuration for Port_SetPinMode API */
#define PORT_SET_PIN_MODE_API       (STD_OFF)
/** \brief  Derived Configuration for Port_SetPinDirection API */
#define PORT_SET_PIN_DIRECTION_API  (STD_ON)
/** \brief  Derived Configuration for pin interrupt dectect */
#define PORT_EN_PIN_INT_API         (STD_ON)
/** @} */
/**
 *  \name Port Module generation configuration info.
 *
 *  @{
 */
/** \brief  define the configed pin num */
#define NUM_OF_CONFIGURED_PINS  203U


/** \brief  define the configed analog pin num */
#define NUM_OF_ANALOG_PINS  18U

/** \brief analog pin enable */
#define PORT_ANALOG_PIN_ENABLE  (STD_ON)

/** \brief Symbolic name for port pin:GPIO_Y6 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PinPort_GPIO_Y6  GPIO_Y6
/** \brief Symbolic name for port pin:GPIO_Y7 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PinPort_GPIO_Y7  GPIO_Y7
/** \brief Symbolic name for port pin:GPIO_Y2 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PinPort_GPIO_Y2  GPIO_Y2
/** \brief Symbolic name for port pin:GPIO_Y3 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PinPort_GPIO_Y3  GPIO_Y3
/** \brief Symbolic name for port pin:GPIO_Y8 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PinPort_GPIO_Y8  GPIO_Y8
/** \brief Symbolic name for port pin:GPIO_Y9 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PinPort_GPIO_Y9_SS0  GPIO_Y9
/** \brief Symbolic name for port pin:GPIO_Y4 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PinPort_GPIO_Y4  GPIO_Y4
/** \brief Symbolic name for port pin:GPIO_Y5 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PinPort_GPIO_Y5  GPIO_Y5
/** \brief Symbolic name for port pin:GPIO_Y11 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PinPort_GPIO_Y11_DQS  GPIO_Y11
/** \brief Symbolic name for port pin:GPIO_Y10 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PinPort_GPIO_Y10_SCLK  GPIO_Y10
/** \brief Symbolic name for port pin:GPIO_Y1 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PinPort_GPIO_Y1  GPIO_Y1
/** \brief Symbolic name for port pin:GPIO_Y0 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PinPort_GPIO_Y0  GPIO_Y0
/** \brief Symbolic name for port pin:GPIO_B0 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PinPort_GPIO_B0_ETH  GPIO_B0
/** \brief Symbolic name for port pin:GPIO_B1 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PinPort_GPIO_B1_ETH  GPIO_B1
/** \brief Symbolic name for port pin:GPIO_B2 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#if BSWM_TEST
#define PortConf_PortPin_UART7_TX_GPIO_B2  GPIO_B2
/** \brief Symbolic name for port pin:GPIO_B3 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_UART7_RX_GPIO_B3  GPIO_B3
#else
#define PortConf_PortPin_UART7_TX  GPIO_B2
/** \brief Symbolic name for port pin:GPIO_B3 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_UART7_RX  GPIO_B3
#endif
/** \brief Symbolic name for port pin:GPIO_B4 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_I2C3_SCL  GPIO_B4
/** \brief Symbolic name for port pin:GPIO_B5 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_I2C3_SDA  GPIO_B5
/** \brief Symbolic name for port pin:GPIO_B6 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ADC_EXP_E_OUT  GPIO_B6
/** \brief Symbolic name for port pin:GPIO_B8 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_IAN35  GPIO_B8
/** \brief Symbolic name for port pin:GPIO_B10 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_UART3_TX  GPIO_B10
/** \brief Symbolic name for port pin:GPIO_B15 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ADC_EXP_D_OUT  GPIO_B15
/** \brief Symbolic name for port pin:GPIO_B13 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_UART2_RX  GPIO_B13
/** \brief Symbolic name for port pin:GPIO_B12 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_UART2_TX  GPIO_B12
/** \brief Symbolic name for port pin:GPIO_B9 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_IAN45  GPIO_B9
/** \brief Symbolic name for port pin:GPIO_B11 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_UART3_RX  GPIO_B11
/** \brief Symbolic name for port pin:GPIO_B7 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_IAN9  GPIO_B7
/** \brief Symbolic name for port pin:GPIO_B14 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ADC_EXP_A_OUT  GPIO_B14
/** \brief Symbolic name for port pin:GPIO_C0 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_IAN49  GPIO_C0
/** \brief Symbolic name for port pin:GPIO_C1 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_IAN48  GPIO_C1
/** \brief Symbolic name for port pin:GPIO_C6 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_I2C2_SCL  GPIO_C6
/** \brief Symbolic name for port pin:GPIO_C7 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_I2C2_SDA  GPIO_C7
/** \brief Symbolic name for port pin:GPIO_C4 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_IAN47  GPIO_C4
/** \brief Symbolic name for port pin:GPIO_C11 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_IAN44  GPIO_C11
/** \brief Symbolic name for port pin:GPIO_C9 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_IAN41  GPIO_C9
/** \brief Symbolic name for port pin:GPIO_C10 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_IAN24  GPIO_C10
/** \brief Symbolic name for port pin:GPIO_C5 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_IAN43  GPIO_C5
/** \brief Symbolic name for port pin:GPIO_C2 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_I2C1_SCL  GPIO_C2
/** \brief Symbolic name for port pin:GPIO_C8 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_IAN46  GPIO_C8
/** \brief Symbolic name for port pin:GPIO_C3 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_I2C1_SDA  GPIO_C3
/** \brief Symbolic name for port pin:GPIO_C12 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_Pin7012_A_IN0  GPIO_C12
/** \brief Symbolic name for port pin:GPIO_C13 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin7E100_B_IN3_delete  GPIO_C13
/** \brief Symbolic name for port pin:GPIO_C14 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_7012_A_IN1  GPIO_C14
/** \brief Symbolic name for port pin:GPIO_C15 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_Current2PWM02  GPIO_C15
/** \brief Symbolic name for port pin:GPIO_D12 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_CAN3_RX  GPIO_D12
/** \brief Symbolic name for port pin:GPIO_D13 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_CAN3_TX  GPIO_D13
/** \brief Symbolic name for port pin:GPIO_D14 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_CAN1_RX  GPIO_D14
/** \brief Symbolic name for port pin:GPIO_D15 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_CAN1_TX  GPIO_D15
/** \brief Symbolic name for port pin:GPIO_D11 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_CAN2_TX  GPIO_D11
/** \brief Symbolic name for port pin:GPIO_D10 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_CAN2_RX  GPIO_D10
/** \brief Symbolic name for port pin:GPIO_D6 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_CAN4_RX  GPIO_D6
/** \brief Symbolic name for port pin:GPIO_D7 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_CAN4_TX  GPIO_D7
/** \brief Symbolic name for port pin:GPIO_D4 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_CAN5_RX  GPIO_D4
/** \brief Symbolic name for port pin:GPIO_D5 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_CAN5_TX  GPIO_D5
/** \brief Symbolic name for port pin:GPIO_D9 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_CAN6_TX  GPIO_D9
/** \brief Symbolic name for port pin:GPIO_D8 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_CAN6_RX  GPIO_D8
/** \brief Symbolic name for port pin:GPIO_D39 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ADC_EXP_C_S0  GPIO_D39
/** \brief Symbolic name for port pin:GPIO_D41 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ADC_EXP_C_S1  GPIO_D41
/** \brief Symbolic name for port pin:GPIO_D38 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ADC_EXP_C_S2  GPIO_D38
/** \brief Symbolic name for port pin:GPIO_D35 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ADC_EXP_C_S3  GPIO_D35
/** \brief Symbolic name for port pin:GPIO_D33 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ADC_EXP_D_S2  GPIO_D33
/** \brief Symbolic name for port pin:GPIO_D31 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ADC_EXP_D_S3  GPIO_D31
/** \brief Symbolic name for port pin:GPIO_D18 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_75242_B_IN0  GPIO_D18
/** \brief Symbolic name for port pin:GPIO_D19 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_75242_B_IN1  GPIO_D19
/** \brief Symbolic name for port pin:GPIO_D2 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_RESET_6424A_C_IN  GPIO_D2
/** \brief Symbolic name for port pin:GPIO_D20 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_RESET_9539_E_IN  GPIO_D20
/** \brief Symbolic name for port pin:GPIO_D0 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_VNQ7E100_A_IN1  GPIO_D0
/** \brief Symbolic name for port pin:GPIO_D40 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_VNQ7E100_A_IN3  GPIO_D40
/** \brief Symbolic name for port pin:GPIO_D37 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_RKE_INT_GPIO_D37  GPIO_D37
/** \brief Symbolic name for port pin:GPIO_D28 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_LF_INT_GPIO_D28  GPIO_D28
/** \brief Symbolic name for port pin:GPIO_D30 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_WAKEUP_GPIOD30  GPIO_D30
/** \brief Symbolic name for port pin:GPIO_D1 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_GPIO_D1_6408_INT  GPIO_D1
/** \brief Symbolic name for port pin:GPIO_D3 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_GPIO_D3_SYSERR_EN  GPIO_D3
/** \brief Symbolic name for port pin:GPIO_D16 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_GPIO_D16_7E100A_IN0  GPIO_D16
/** \brief Symbolic name for port pin:GPIO_D17 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_7E100_A_IN2  GPIO_D17
/** \brief Symbolic name for port pin:GPIO_D21 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_BR_INTB  GPIO_D21
/** \brief Symbolic name for port pin:GPIO_D22 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_BR_RSTB  GPIO_D22
/** \brief Symbolic name for port pin:GPIO_D23 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ANT_BLE_DET  GPIO_D23
/** \brief Symbolic name for port pin:GPIO_D24 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ETH_TX_RST_N  GPIO_D24
/** \brief Symbolic name for port pin:GPIO_D25 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_BR_PWREN  GPIO_D25
/** \brief Symbolic name for port pin:GPIO_D27 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_Pin9539_A_INT  GPIO_D27
/** \brief Symbolic name for port pin:GPIO_D29 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ETH_TX_INT_B  GPIO_D29
/** \brief Symbolic name for port pin:GPIO_D32 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_EPB_B_MOS_EN  GPIO_D32
/** \brief Symbolic name for port pin:GPIO_D34 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_HALL_INPUT_EN  GPIO_D34
/** \brief Symbolic name for port pin:GPIO_D36 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_9539_B_INT  GPIO_D36
/** \brief Symbolic name for port pin:GPIO_G0 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ETH1_TXC  GPIO_G0
/** \brief Symbolic name for port pin:GPIO_G1 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ETH1_TXD0  GPIO_G1
/** \brief Symbolic name for port pin:GPIO_G2 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ETH1_TXD1  GPIO_G2
/** \brief Symbolic name for port pin:GPIO_G3 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ETH1_TXD2  GPIO_G3
/** \brief Symbolic name for port pin:GPIO_G4 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ETH1_TXD3  GPIO_G4
/** \brief Symbolic name for port pin:GPIO_G5 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ETH1_TXEN  GPIO_G5
/** \brief Symbolic name for port pin:GPIO_G6 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ETH1_RXC  GPIO_G6
/** \brief Symbolic name for port pin:GPIO_G7 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ETH1_RXD0  GPIO_G7
/** \brief Symbolic name for port pin:GPIO_G8 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ETH1_RXD1  GPIO_G8
/** \brief Symbolic name for port pin:GPIO_G9 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ETH1_RXD2  GPIO_G9
/** \brief Symbolic name for port pin:GPIO_G10 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ETH1_RXD3  GPIO_G10
/** \brief Symbolic name for port pin:GPIO_G11 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ETH1_RXDV  GPIO_G11
/** \brief Symbolic name for port pin:GPIO_L0 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ETH2_MDIO  GPIO_L0
/** \brief Symbolic name for port pin:GPIO_L1 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ETH2_MDC  GPIO_L1
/** \brief Symbolic name for port pin:GPIO_L2 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ETH2_RMII_REF_CLK  GPIO_L2
/** \brief Symbolic name for port pin:GPIO_L3 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ETH2_TXD0  GPIO_L3
/** \brief Symbolic name for port pin:GPIO_L4 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ETH2_TXD1  GPIO_L4
/** \brief Symbolic name for port pin:GPIO_L5 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ETH2_TXEN  GPIO_L5
/** \brief Symbolic name for port pin:GPIO_L6 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ETH2_RXE  GPIO_L6
/** \brief Symbolic name for port pin:GPIO_L7 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ETH2_RXD0  GPIO_L7
/** \brief Symbolic name for port pin:GPIO_L8 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ETH2_RXD1  GPIO_L8
/** \brief Symbolic name for port pin:GPIO_L9 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ETH2_RXDV  GPIO_L9
/** \brief Symbolic name for port pin:GPIO_A4 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_IAN25  GPIO_A4
/** \brief Symbolic name for port pin:GPIO_A5 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ADC_EXP_C_OUT  GPIO_A5
/** \brief Symbolic name for port pin:GPIO_A6 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_IAN23  GPIO_A6
/** \brief Symbolic name for port pin:GPIO_A7 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_Current2PWM01  GPIO_A7
/** \brief Symbolic name for port pin:GPIO_A8 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_BTS7012_B_IN1  GPIO_A8
/** \brief Symbolic name for port pin:GPIO_A9 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_MCU_SPI2_SS1_GPIO_A9  GPIO_A9
/** \brief Symbolic name for port pin:GPIO_A10 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_MCU_SPI2_SS0_GPIO_A10  GPIO_A10
/** \brief Symbolic name for port pin:GPIO_A11 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_MCU_SPI2_SCLK_GPIO_A11  GPIO_A11
/** \brief Symbolic name for port pin:GPIO_A14 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ADC_EXP_B_OUT_A14  GPIO_A14
/** \brief Symbolic name for port pin:GPIO_A15 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
//#define PortConf_PortPin_PortPin_FLSH_GPIO_A15  GPIO_A15
/** \brief Symbolic name for port pin:GPIO_A12 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_MCU_SPI2_MISO_GPIO_A12  GPIO_A12
/** \brief Symbolic name for port pin:GPIO_A13 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_MCU_SPI2_MOSI_GPIO_A13  GPIO_A13
/** \brief Symbolic name for port pin:GPIO_F0 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_SPI5_SS2  GPIO_F0
/** \brief Symbolic name for port pin:GPIO_F1 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_SPI5_SS1  GPIO_F1
/** \brief Symbolic name for port pin:GPIO_F2 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_SPI5_SS0  GPIO_F2
/** \brief Symbolic name for port pin:GPIO_F3 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_SPI5_MISO  GPIO_F3
/** \brief Symbolic name for port pin:GPIO_F4 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_SPI5_MOSI  GPIO_F4
/** \brief Symbolic name for port pin:GPIO_F5 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_SPI5_SCLK  GPIO_F5
/** \brief Symbolic name for port pin:GPIO_S7 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_SPI7_SS3  GPIO_S7
/** \brief Symbolic name for port pin:GPIO_S8 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_SPI7_SS2  GPIO_S8
/** \brief Symbolic name for port pin:GPIO_S9 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_SPI7_SS1  GPIO_S9
/** \brief Symbolic name for port pin:GPIO_S10 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_SPI7_SS0  GPIO_S10
/** \brief Symbolic name for port pin:GPIO_S11 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_SPI7_SCLK  GPIO_S11
/** \brief Symbolic name for port pin:GPIO_S12 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_SPI7_MISO  GPIO_S12
/** \brief Symbolic name for port pin:GPIO_S13 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_SPI7_MOSI  GPIO_S13
/** \brief Symbolic name for port pin:GPIO_S0 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_MCU_UART11_TX  GPIO_S0
/** \brief Symbolic name for port pin:GPIO_S1 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_MCU_UART11_RX  GPIO_S1
/** \brief Symbolic name for port pin:GPIO_S2 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_BTS7012_C_IN1  GPIO_S2
/** \brief Symbolic name for port pin:GPIO_S5 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_TLE8108_IN2  GPIO_S5
/** \brief Symbolic name for port pin:GPIO_S3 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_IN_IPL03  GPIO_S3
/** \brief Symbolic name for port pin:GPIO_S4 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_IN_IPL02  GPIO_S4
/** \brief Symbolic name for port pin:GPIO_S6 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_IN_IPL04  GPIO_S6
/** \brief Symbolic name for port pin:GPIO_E0 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_GPIO_E0  GPIO_E0
/** \brief Symbolic name for port pin:GPIO_E1 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_GPIO_E1  GPIO_E1
/** \brief Symbolic name for port pin:GPIO_E7 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ADC_EXP_E_S0  GPIO_E7
/** \brief Symbolic name for port pin:GPIO_E6 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ADC_EXP_D_S0  GPIO_E6
/** \brief Symbolic name for port pin:GPIO_E2 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_GPIO_E2  GPIO_E2
/** \brief Symbolic name for port pin:GPIO_E3 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ADC_EXP_E_S1  GPIO_E3
/** \brief Symbolic name for port pin:GPIO_E16 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ADC_EXP_E_S2  GPIO_E16
/** \brief Symbolic name for port pin:GPIO_E15 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ADC_EXP_E_S3  GPIO_E15
/** \brief Symbolic name for port pin:GPIO_E11 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_ADC_EXP_D_S1  GPIO_E11
/** \brief Symbolic name for port pin:GPIO_E13 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_GPIO_E13  GPIO_E13
/** \brief Symbolic name for port pin:GPIO_E14 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_GPIO_E14  GPIO_E14
/** \brief Symbolic name for port pin:GPIO_E21 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_GPIO_E21  GPIO_E21
/** \brief Symbolic name for port pin:GPIO_E22 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_GPIO_E22  GPIO_E22
/** \brief Symbolic name for port pin:GPIO_E23 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_GPIO_E23  GPIO_E23
/** \brief Symbolic name for port pin:GPIO_E24 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_GPIO_E24  GPIO_E24
/** \brief Symbolic name for port pin:GPIO_E25 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_GPIO_E25  GPIO_E25
/** \brief Symbolic name for port pin:GPIO_E17 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_GPIO_E17  GPIO_E17
/** \brief Symbolic name for port pin:GPIO_E18 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_GPIO_E18  GPIO_E18
/** \brief Symbolic name for port pin:GPIO_E4 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_UART4_TX  GPIO_E4
/** \brief Symbolic name for port pin:GPIO_E5 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_UART4_RX  GPIO_E5
/** \brief Symbolic name for port pin:GPIO_E8 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_UART5_TX  GPIO_E8
/** \brief Symbolic name for port pin:GPIO_E9 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_UART5_RX  GPIO_E9
/** \brief Symbolic name for port pin:GPIO_E10 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_MCU_MPU_GPIO5  GPIO_E10
/** \brief Symbolic name for port pin:GPIO_E12 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_MCU_MPU_GPIO4  GPIO_E12
/** \brief Symbolic name for port pin:GPIO_E19 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_UART8_RXD  GPIO_E19
/** \brief Symbolic name for port pin:GPIO_E20 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_MCU_MPU_GPIO3  GPIO_E20
/** \brief Symbolic name for port pin:GPIO_E26 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_MCU_MPU_GPIO6  GPIO_E26
/** \brief Symbolic name for port pin:GPIO_M4 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_MCU_UART14_TX  GPIO_M4
/** \brief Symbolic name for port pin:GPIO_M5 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_MCU_UART14_RX  GPIO_M5
/** \brief Symbolic name for port pin:GPIO_M9 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_75242_A_IN0  GPIO_M9
/** \brief Symbolic name for port pin:GPIO_M0 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_BTS7020_A_IN0  GPIO_M0
/** \brief Symbolic name for port pin:GPIO_M6 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_BTS7020_A_IN1  GPIO_M6
/** \brief Symbolic name for port pin:GPIO_M7 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_BTS7020_B_IN0  GPIO_M7
/** \brief Symbolic name for port pin:GPIO_M8 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_BTS7020_B_IN1  GPIO_M8
/** \brief Symbolic name for port pin:GPIO_M3 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_BTS7012_C_IN0  GPIO_M3
/** \brief Symbolic name for port pin:GPIO_M1 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_EPB_A_MOS_EN  GPIO_M1
/** \brief Symbolic name for port pin:GPIO_M2 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_GPIO_M2TCA6424_INT  GPIO_M2
/** \brief Symbolic name for port pin:GPIO_M10 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_GPIO_M10  GPIO_M10
/** \brief Symbolic name for port pin:GPIO_M11 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_GPIO_M11  GPIO_M11
/** \brief Symbolic name for port pin:GPIO_H6 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_75242_A_IN1  GPIO_H6
/** \brief Symbolic name for port pin:GPIO_H1 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_BTS7012_B_IN0  GPIO_H1
/** \brief Symbolic name for port pin:GPIO_H3 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_BTS7120_B_IN1  GPIO_H3
/** \brief Symbolic name for port pin:GPIO_H8 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_BTS7120_D_IN1  GPIO_H8
/** \brief Symbolic name for port pin:GPIO_H4 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_BTS7120_D_IN0  GPIO_H4
/** \brief Symbolic name for port pin:GPIO_H12 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_BTS7120_B_IN0  GPIO_H12
/** \brief Symbolic name for port pin:GPIO_H5 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_VNQ7E100_B_IN0  GPIO_H5
/** \brief Symbolic name for port pin:GPIO_H13 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_TLE94103_SPI5_SS3  GPIO_H13
/** \brief Symbolic name for port pin:GPIO_H7 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_TLE8108_IN1  GPIO_H7
/** \brief Symbolic name for port pin:GPIO_H9 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_TLE8108_IN3  GPIO_H9
/** \brief Symbolic name for port pin:GPIO_H10 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_TLE8108_IN4  GPIO_H10
/** \brief Symbolic name for port pin:GPIO_H0 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_GPIO_H0_DELETE  GPIO_H0
/** \brief Symbolic name for port pin:GPIO_H2 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_IN_IPL01  GPIO_H2
/** \brief Symbolic name for port pin:GPIO_H11 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_HPIO_H11_DELETE  GPIO_H11
/** \brief Symbolic name for port pin:GPIO_X0 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_GPIO_X0  GPIO_X0
/** \brief Symbolic name for port pin:GPIO_X1 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_GPIO_X1_PA_SCLK  GPIO_X1
/** \brief Symbolic name for port pin:GPIO_X2 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_GPIO_X2_PA_SS0  GPIO_X2
/** \brief Symbolic name for port pin:GPIO_X3 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_GPIO_X3_  GPIO_X3
/** \brief Symbolic name for port pin:GPIO_X4 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_GPIO_X4  GPIO_X4
/** \brief Symbolic name for port pin:GPIO_X5 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_GPIO_X5  GPIO_X5
/** \brief Symbolic name for port pin:GPIO_X6 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_GPIO_X6  GPIO_X6
/** \brief Symbolic name for port pin:GPIO_X7 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_GPIO_X7  GPIO_X7
/** \brief Symbolic name for port pin:GPIO_X8 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_GPIO_X8  GPIO_X8
/** \brief Symbolic name for port pin:GPIO_X9 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_GPIO_X9  GPIO_X9
/** \brief Symbolic name for port pin:GPIO_X10 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_PortPin_GPIO_X10  GPIO_X10
/** \brief Symbolic name for port pin:GPIO_X11 */
/** Traceability       : SWSR_PORT_011 SWSR_PORT_012 SWSR_PORT_013 */
#define PortConf_PortPin_EPB_A_MOS_EN_xtrg  GPIO_X11
/** @} */
/** @} */

/********************************************************************************************************
 *                                  Global Variable Declarations                                        *
 *******************************************************************************************************/
/** \brief global config for all io */
extern const Port_SettingsConfigType Port_PinInitConfig[NUM_OF_CONFIGURED_PINS];

/** \brief global config for analog io */
extern const Port_AnalogConfigType Port_PinAnalogConfig[NUM_OF_ANALOG_PINS];

/** \brief  The entire configuration of the port pin, is provided to the initialization function */
extern const Port_ConfigType Port_Cfg;


#ifdef __cplusplus
}
#endif
/* End of file */
#endif /* PORT_CFG_H */
