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
 * \file     Port_Cfg.c                                                                                 *
 * \brief    AUTOSAR 4.3.1 MCAL Port Driver                                                             *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date                 <th>Version                                                             *
 * <tr><td>2024-03-08 16:29:00      <td>1.0.0 R                                            *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Port_Cfg.h"


/********************************************************************************************************
 *                                  Global Variable Declarations                                        *
 *******************************************************************************************************/
/*PRQA S 1504 EOF*/
#define PORT_START_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"
/** \brief  port init config setting, provide to Port_Cfg. */
const Port_SettingsConfigType Port_PinInitConfig[NUM_OF_CONFIGURED_PINS] = {

    /* PortPinid:PinPort_GPIO_Y6 - Mux:XSPI1_PB_DATA2 */
    {
        .pinIndex         =  GPIO_Y6,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PinPort_GPIO_Y7 - Mux:XSPI1_PB_DATA1 */
    {
        .pinIndex         =  GPIO_Y7,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PinPort_GPIO_Y2 - Mux:XSPI1_PB_DATA6 */
    {
        .pinIndex         =  GPIO_Y2,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_DOWN,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PinPort_GPIO_Y3 - Mux:XSPI1_PB_DATA5 */
    {
        .pinIndex         =  GPIO_Y3,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_DOWN,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PinPort_GPIO_Y8 - Mux:XSPI1_PB_DATA0 */
    {
        .pinIndex         =  GPIO_Y8,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_HIGH,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PinPort_GPIO_Y9_SS0 - Mux:XSPI1_PB_SS0 */
    {
        .pinIndex         =  GPIO_Y9,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_OPEN_DRAIN,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_HIGH,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PinPort_GPIO_Y4 - Mux:XSPI1_PB_DATA4 */
    {
        .pinIndex         =  GPIO_Y4,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PinPort_GPIO_Y5 - Mux:XSPI1_PB_DATA3 */
    {
        .pinIndex         =  GPIO_Y5,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PinPort_GPIO_Y11_DQS - Mux:XSPI1_PB_DQS */
    {
        .pinIndex         =  GPIO_Y11,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_HIGH,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  TRUE,
    },


    /* PortPinid:PinPort_GPIO_Y10_SCLK - Mux:XSPI1_PB_SCLK */
    {
        .pinIndex         =  GPIO_Y10,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_HIGH,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PinPort_GPIO_Y1 - Mux:XSPI1_PB_DATA7 */
    {
        .pinIndex         =  GPIO_Y1,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PinPort_GPIO_Y0 - Mux:XSPI1_PB_SS1 */
    {
        .pinIndex         =  GPIO_Y0,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PinPort_GPIO_B0_ETH - Mux:ETH1_MDIO */
    {
        .pinIndex         =  GPIO_B0,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PinPort_GPIO_B1_ETH - Mux:ETH1_MDC */
    {
        .pinIndex         =  GPIO_B1,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


# if BSWM_TEST
    /* PortPinid:UART7_TX - Mux:UART7.TXD */
    {
        .pinIndex         =  GPIO_B2,
		.modeChangable    =  FALSE,
        .mux               =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
		.directChangable  =  FALSE,
    },
	
	    /* PortPinid:UART7_RX - Mux:UART7.RXD */
    {
        .pinIndex         =  GPIO_B3,
        .modeChangable    =  FALSE,
        .mux               =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
		.directChangable  =  FALSE,
    },
#else
    /* PortPinid:UART7_TX - Mux:UART7_TXD */
    {
        .pinIndex         =  GPIO_B2,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT4,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:UART7_RX - Mux:UART7_RXD */
    {
        .pinIndex         =  GPIO_B3,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT4,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },
#endif

    /* PortPinid:I2C3_SCL - Mux:I2C3_SCL */
    {
        .pinIndex         =  GPIO_B4,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT6,
        .openDrain        =  PORT_PIN_OPEN_DRAIN,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_HIGH,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:I2C3_SDA - Mux:I2C3_SDA */
    {
        .pinIndex         =  GPIO_B5,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT6,
        .openDrain        =  PORT_PIN_OPEN_DRAIN,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_HIGH,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ADC_EXP_E_OUT - Mux:ADC */
    {
        .pinIndex         =  GPIO_B6,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_OPEN_DRAIN,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_SLOW,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_LOW,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_IAN35 - Mux:ADC */
    {
        .pinIndex         =  GPIO_B8,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_OPEN_DRAIN,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_SLOW,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_LOW,
        .directChangable  =  FALSE,
    },


    /* PortPinid:UART3_TX - Mux:UART3_TXD */
    {
        .pinIndex         =  GPIO_B10,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT4,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ADC_EXP_D_OUT - Mux:ADC */
    {
        .pinIndex         =  GPIO_B15,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_OPEN_DRAIN,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_SLOW,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_LOW,
        .directChangable  =  FALSE,
    },


    /* PortPinid:UART2_RX - Mux:UART2_RXD */
    {
        .pinIndex         =  GPIO_B13,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT4,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:UART2_TX - Mux:UART2_TXD */
    {
        .pinIndex         =  GPIO_B12,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT4,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_IAN45 - Mux:ADC */
    {
        .pinIndex         =  GPIO_B9,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_OPEN_DRAIN,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_SLOW,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_LOW,
        .directChangable  =  FALSE,
    },


    /* PortPinid:UART3_RX - Mux:UART3_RXD */
    {
        .pinIndex         =  GPIO_B11,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT4,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_IAN9 - Mux:ADC */
    {
        .pinIndex         =  GPIO_B7,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_OPEN_DRAIN,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_SLOW,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_LOW,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ADC_EXP_A_OUT - Mux:ADC */
    {
        .pinIndex         =  GPIO_B14,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_OPEN_DRAIN,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_SLOW,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_LOW,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_IAN49 - Mux:ADC */
    {
        .pinIndex         =  GPIO_C0,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_OPEN_DRAIN,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_SLOW,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_LOW,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_IAN48 - Mux:ADC */
    {
        .pinIndex         =  GPIO_C1,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_OPEN_DRAIN,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_SLOW,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_LOW,
        .directChangable  =  FALSE,
    },


    /* PortPinid:I2C2_SCL - Mux:I2C2_SCL */
    {
        .pinIndex         =  GPIO_C6,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT6,
        .openDrain        =  PORT_PIN_OPEN_DRAIN,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_HIGH,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:I2C2_SDA - Mux:I2C2_SDA */
    {
        .pinIndex         =  GPIO_C7,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT6,
        .openDrain        =  PORT_PIN_OPEN_DRAIN,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_HIGH,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_IAN47 - Mux:ADC */
    {
        .pinIndex         =  GPIO_C4,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_OPEN_DRAIN,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_SLOW,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_LOW,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_IAN44 - Mux:ADC */
    {
        .pinIndex         =  GPIO_C11,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_OPEN_DRAIN,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_SLOW,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_LOW,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_IAN41 - Mux:ADC */
    {
        .pinIndex         =  GPIO_C9,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_OPEN_DRAIN,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_SLOW,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_LOW,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_IAN24 - Mux:ADC */
    {
        .pinIndex         =  GPIO_C10,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_OPEN_DRAIN,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_SLOW,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_LOW,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_IAN43 - Mux:ADC */
    {
        .pinIndex         =  GPIO_C5,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_OPEN_DRAIN,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_SLOW,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_LOW,
        .directChangable  =  FALSE,
    },


    /* PortPinid:I2C1_SCL - Mux:I2C1_SCL */
    {
        .pinIndex         =  GPIO_C2,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT6,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_HIGH,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  TRUE,
    },


    /* PortPinid:PortPin_IAN46 - Mux:ADC */
    {
        .pinIndex         =  GPIO_C8,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_OPEN_DRAIN,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_SLOW,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_LOW,
        .directChangable  =  FALSE,
    },


    /* PortPinid:I2C1_SDA - Mux:I2C1_SDA */
    {
        .pinIndex         =  GPIO_C3,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT6,
        .openDrain        =  PORT_PIN_OPEN_DRAIN,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_HIGH,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:Pin7012_A_IN0 - Mux:xTRG_IO2 */
    {
        .pinIndex         =  GPIO_C12,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT5,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin7E100_B_IN3_delete - Mux:xTRG_IO3 */
    {
        .pinIndex         =  GPIO_C13,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_7012_A_IN1 - Mux:xTRG_IO4 */
    {
        .pinIndex         =  GPIO_C14,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT5,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:Current2PWM02 - Mux:xTRG_IO5 */
    {
        .pinIndex         =  GPIO_C15,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT5,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:CAN3_RX - Mux:CANFD7_RX */
    {
        .pinIndex         =  GPIO_D12,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT2,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:CAN3_TX - Mux:CANFD7_TX */
    {
        .pinIndex         =  GPIO_D13,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT2,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:CAN1_RX - Mux:CANFD8_RX */
    {
        .pinIndex         =  GPIO_D14,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT2,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:CAN1_TX - Mux:CANFD8_TX */
    {
        .pinIndex         =  GPIO_D15,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT2,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:CAN2_TX - Mux:CANFD6_TX */
    {
        .pinIndex         =  GPIO_D11,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT2,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:CAN2_RX - Mux:CANFD6_RX */
    {
        .pinIndex         =  GPIO_D10,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT2,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:CAN4_RX - Mux:CANFD4_RX */
    {
        .pinIndex         =  GPIO_D6,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT2,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:CAN4_TX - Mux:CANFD4_TX */
    {
        .pinIndex         =  GPIO_D7,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT2,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:CAN5_RX - Mux:CANFD3_RX */
    {
        .pinIndex         =  GPIO_D4,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT2,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:CAN5_TX - Mux:CANFD3_TX */
    {
        .pinIndex         =  GPIO_D5,
        .modeChangable    =  TRUE,
        .mux              =  PORT_PIN_MUX_ALT2,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:CAN6_TX - Mux:CANFD5_TX */
    {
        .pinIndex         =  GPIO_D9,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT2,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:CAN6_RX - Mux:CANFD5_RX */
    {
        .pinIndex         =  GPIO_D8,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT2,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ADC_EXP_C_S0 - Mux:GPIO */
    {
        .pinIndex         =  GPIO_D39,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ADC_EXP_C_S1 - Mux:GPIO */
    {
        .pinIndex         =  GPIO_D41,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ADC_EXP_C_S2 - Mux:GPIO */
    {
        .pinIndex         =  GPIO_D38,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ADC_EXP_C_S3 - Mux:GPIO */
    {
        .pinIndex         =  GPIO_D35,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ADC_EXP_D_S2 - Mux:GPIO */
    {
        .pinIndex         =  GPIO_D33,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ADC_EXP_D_S3 - Mux:GPIO */
    {
        .pinIndex         =  GPIO_D31,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_75242_B_IN0 - Mux:GPIO */
    {
        .pinIndex         =  GPIO_D18,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_75242_B_IN1 - Mux:GPIO */
    {
        .pinIndex         =  GPIO_D19,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:RESET_6424A_C_IN - Mux:GPIO */
    {
        .pinIndex         =  GPIO_D2,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_HIGH,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:RESET_9539_E_IN - Mux:GPIO */
    {
        .pinIndex         =  GPIO_D20,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_HIGH,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:VNQ7E100_A_IN1 - Mux:GPIO */
    {
        .pinIndex         =  GPIO_D0,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:VNQ7E100_A_IN3 - Mux:GPIO */
    {
        .pinIndex         =  GPIO_D40,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:RKE_INT_GPIO_D37 - Mux:GPIO */
    {
        .pinIndex         =  GPIO_D37,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_BOTH_EDGE,
        .initialValue     =  PORT_PIN_LEVEL_HIGH,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:LF_INT_GPIO_D28 - Mux:GPIO */
    {
        .pinIndex         =  GPIO_D28,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_BOTH_EDGE,
        .initialValue     =  PORT_PIN_LEVEL_HIGH,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_WAKEUP_GPIOD30 - Mux:GPIO */
    {
        .pinIndex         =  GPIO_D30,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_GPIO_D1_6408_INT - Mux:GPIO */
    {
        .pinIndex         =  GPIO_D1,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_GPIO_D3_SYSERR_EN - Mux:GPIO */
    {
        .pinIndex         =  GPIO_D3,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_GPIO_D16_7E100A_IN0 - Mux:GPIO */
    {
        .pinIndex         =  GPIO_D16,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_7E100_A_IN2 - Mux:GPIO */
    {
        .pinIndex         =  GPIO_D17,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_BR_INTB - Mux:GPIO */
    {
        .pinIndex         =  GPIO_D21,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_BR_RSTB - Mux:GPIO */
    {
        .pinIndex         =  GPIO_D22,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ANT_BLE_DET - Mux:GPIO */
    {
        .pinIndex         =  GPIO_D23,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ETH_TX_RST_N - Mux:GPIO */
    {
        .pinIndex         =  GPIO_D24,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:BR_PWREN - Mux:GPIO */
    {
        .pinIndex         =  GPIO_D25,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:Pin9539_A_INT - Mux:GPIO */
    {
        .pinIndex         =  GPIO_D27,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ETH_TX_INT_B - Mux:GPIO */
    {
        .pinIndex         =  GPIO_D29,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:EPB_B_MOS_EN - Mux:GPIO */
    {
        .pinIndex         =  GPIO_D32,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:HALL_INPUT_EN - Mux:GPIO */
    {
        .pinIndex         =  GPIO_D34,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_9539_B_INT - Mux:GPIO */
    {
        .pinIndex         =  GPIO_D36,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ETH1_TXC - Mux:ETH1_TXC */
    {
        .pinIndex         =  GPIO_G0,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_DOWN,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ETH1_TXD0 - Mux:ETH1_TXD0 */
    {
        .pinIndex         =  GPIO_G1,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_DOWN,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ETH1_TXD1 - Mux:ETH1_TXD1 */
    {
        .pinIndex         =  GPIO_G2,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_DOWN,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ETH1_TXD2 - Mux:ETH1_TXD2 */
    {
        .pinIndex         =  GPIO_G3,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_DOWN,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ETH1_TXD3 - Mux:ETH1_TXD3 */
    {
        .pinIndex         =  GPIO_G4,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_DOWN,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ETH1_TXEN - Mux:ETH1_TXEN */
    {
        .pinIndex         =  GPIO_G5,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_DOWN,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ETH1_RXC - Mux:ETH1_RXC */
    {
        .pinIndex         =  GPIO_G6,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ETH1_RXD0 - Mux:ETH1_RXD0 */
    {
        .pinIndex         =  GPIO_G7,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_DOWN,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ETH1_RXD1 - Mux:ETH1_RXD1 */
    {
        .pinIndex         =  GPIO_G8,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_DOWN,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ETH1_RXD2 - Mux:ETH1_RXD2 */
    {
        .pinIndex         =  GPIO_G9,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_DOWN,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ETH1_RXD3 - Mux:ETH1_RXD3 */
    {
        .pinIndex         =  GPIO_G10,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_DOWN,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ETH1_RXDV - Mux:ETH1_RXDV */
    {
        .pinIndex         =  GPIO_G11,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_DOWN,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ETH2_MDIO - Mux:ETH2_MDIO */
    {
        .pinIndex         =  GPIO_L0,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT2,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_DOWN,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_4MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ETH2_MDC - Mux:ETH2_MDC */
    {
        .pinIndex         =  GPIO_L1,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT2,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_DOWN,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_4MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ETH2_RMII_REF_CLK - Mux:ETH2_RMII_REF_CLK */
    {
        .pinIndex         =  GPIO_L2,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT2,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_DOWN,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_ENABLE,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ETH2_TXD0 - Mux:ETH2_TXD0 */
    {
        .pinIndex         =  GPIO_L3,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT2,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_DOWN,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ETH2_TXD1 - Mux:ETH2_TXD1 */
    {
        .pinIndex         =  GPIO_L4,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT2,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_DOWN,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ETH2_TXEN - Mux:ETH2_TXEN */
    {
        .pinIndex         =  GPIO_L5,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT2,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_DOWN,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ETH2_RXE - Mux:ETH2_RX_ER */
    {
        .pinIndex         =  GPIO_L6,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT2,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_DOWN,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ETH2_RXD0 - Mux:ETH2_RXD0 */
    {
        .pinIndex         =  GPIO_L7,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT2,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_DOWN,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ETH2_RXD1 - Mux:ETH2_RXD1 */
    {
        .pinIndex         =  GPIO_L8,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT2,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_DOWN,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ETH2_RXDV - Mux:ETH2_RXDV */
    {
        .pinIndex         =  GPIO_L9,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT2,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_DOWN,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_IAN25 - Mux:ADC */
    {
        .pinIndex         =  GPIO_A4,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_OPEN_DRAIN,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_SLOW,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_LOW,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ADC_EXP_C_OUT - Mux:ADC */
    {
        .pinIndex         =  GPIO_A5,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_OPEN_DRAIN,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_SLOW,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_LOW,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_IAN23 - Mux:ADC */
    {
        .pinIndex         =  GPIO_A6,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_OPEN_DRAIN,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_SLOW,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_LOW,
        .directChangable  =  FALSE,
    },


    /* PortPinid:Current2PWM01 - Mux:GPIO */
    {
        .pinIndex         =  GPIO_A7,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:BTS7012_B_IN1 - Mux:xTRG_IO8 */
    {
        .pinIndex         =  GPIO_A8,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT5,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:MCU_SPI2_SS1_GPIO_A9 - Mux:GPIO */
    {
        .pinIndex         =  GPIO_A9,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_HIGH,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:MCU_SPI2_SS0_GPIO_A10 - Mux:GPIO */
    {
        .pinIndex         =  GPIO_A10,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_HIGH,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:MCU_SPI2_SCLK_GPIO_A11 - Mux:SPI2_SCLK */
    {
        .pinIndex         =  GPIO_A11,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT3,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ADC_EXP_B_OUT_A14 - Mux:ADC */
    {
        .pinIndex         =  GPIO_A14,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_OPEN_DRAIN,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_SLOW,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_LOW,
        .directChangable  =  FALSE,
    },


//    /* PortPinid:PortPin_FLSH_GPIO_A15 - Mux:GPIO */
//    {
//        .pinIndex         =  GPIO_A15,
//        .modeChangable    =  FALSE,
//        .mux              =  PORT_PIN_MUX_ALT0,
//        .openDrain        =  PORT_PIN_PUSH_PULL,
//        .pullConfig       =  PORT_PIN_PULL_UP,
//        .slewRate         =  PORT_PIN_SR_FAST,
//        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
//        .driveStrength    =  PORT_PIN_DS_8MA,
//        .dataDirection    =  PORT_PIN_OUT,
//        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
//        .initialValue     =  PORT_PIN_LEVEL_LOW,
//        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
//        .directChangable  =  FALSE,
//    },


    /* PortPinid:MCU_SPI2_MISO_GPIO_A12 - Mux:SPI2_MISO */
    {
        .pinIndex         =  GPIO_A12,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT3,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:MCU_SPI2_MOSI_GPIO_A13 - Mux:SPI2_MOSI */
    {
        .pinIndex         =  GPIO_A13,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT3,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:SPI5_SS2 - Mux:SPI5_SS2 */
    {
        .pinIndex         =  GPIO_F0,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT3,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_HIGH,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:SPI5_SS1 - Mux:SPI5_SS1 */
    {
        .pinIndex         =  GPIO_F1,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT3,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_HIGH,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:SPI5_SS0 - Mux:SPI5_SS0 */
    {
        .pinIndex         =  GPIO_F2,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT3,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_HIGH,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:SPI5_MISO - Mux:SPI5_MISO */
    {
        .pinIndex         =  GPIO_F3,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT3,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:SPI5_MOSI - Mux:SPI5_MOSI */
    {
        .pinIndex         =  GPIO_F4,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT3,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_HIGH,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:SPI5_SCLK - Mux:SPI5_SCLK */
    {
        .pinIndex         =  GPIO_F5,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT3,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:SPI7_SS3 - Mux:SPI7_SS3 */
    {
        .pinIndex         =  GPIO_S7,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT3,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_HIGH,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:SPI7_SS2 - Mux:SPI7_SS2 */
    {
        .pinIndex         =  GPIO_S8,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT3,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_HIGH,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:SPI7_SS1 - Mux:SPI7_SS1 */
    {
        .pinIndex         =  GPIO_S9,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT3,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_HIGH,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:SPI7_SS0 - Mux:SPI7_SS0 */
    {
        .pinIndex         =  GPIO_S10,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT3,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_HIGH,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:SPI7_SCLK - Mux:SPI7_SCLK */
    {
        .pinIndex         =  GPIO_S11,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT3,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:SPI7_MISO - Mux:SPI7_MISO */
    {
        .pinIndex         =  GPIO_S12,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT3,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:SPI7_MOSI - Mux:SPI7_MOSI */
    {
        .pinIndex         =  GPIO_S13,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT3,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:MCU_UART11_TX - Mux:UART11_TXD */
    {
        .pinIndex         =  GPIO_S0,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT4,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:MCU_UART11_RX - Mux:UART11_RXD */
    {
        .pinIndex         =  GPIO_S1,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT4,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:BTS7012_C_IN1 - Mux:xTRG_IO20 */
    {
        .pinIndex         =  GPIO_S2,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT5,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:TLE8108_IN2 - Mux:xTRG_IO23 */
    {
        .pinIndex         =  GPIO_S5,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT5,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:IN_IPL03 - Mux:xTRG_IO21 */
    {
        .pinIndex         =  GPIO_S3,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT5,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:IN_IPL02 - Mux:xTRG_IO22 */
    {
        .pinIndex         =  GPIO_S4,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT5,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:IN_IPL04 - Mux:xTRG_IO24 */
    {
        .pinIndex         =  GPIO_S6,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT5,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:GPIO_E0 - Mux:SACI1_TXSCK */
    {
        .pinIndex         =  GPIO_E0,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT4,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:GPIO_E1 - Mux:SACI1_TXWS */
    {
        .pinIndex         =  GPIO_E1,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT4,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ADC_EXP_E_S0 - Mux:GPIO */
    {
        .pinIndex         =  GPIO_E7,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_HIGH,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ADC_EXP_D_S0 - Mux:GPIO */
    {
        .pinIndex         =  GPIO_E6,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_HIGH,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:GPIO_E2 - Mux:SACI1_TXRXD0 */
    {
        .pinIndex         =  GPIO_E2,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT4,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ADC_EXP_E_S1 - Mux:GPIO */
    {
        .pinIndex         =  GPIO_E3,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ADC_EXP_E_S2 - Mux:GPIO */
    {
        .pinIndex         =  GPIO_E16,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ADC_EXP_E_S3 - Mux:GPIO */
    {
        .pinIndex         =  GPIO_E15,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:ADC_EXP_D_S1 - Mux:GPIO */
    {
        .pinIndex         =  GPIO_E11,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_GPIO_E13 - Mux:SACI2_TXSCK */
    {
        .pinIndex         =  GPIO_E13,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT4,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_HIGH,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_GPIO_E14 - Mux:SACI2_TXWS */
    {
        .pinIndex         =  GPIO_E14,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT4,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_HIGH,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_GPIO_E21 - Mux:SACI2_TXRXD6 */
    {
        .pinIndex         =  GPIO_E21,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT4,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_GPIO_E22 - Mux:SACI2_TXRXD7 */
    {
        .pinIndex         =  GPIO_E22,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT4,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_GPIO_E23 - Mux:SACI2_RXSCK */
    {
        .pinIndex         =  GPIO_E23,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT4,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_GPIO_E24 - Mux:SACI2_RXWS */
    {
        .pinIndex         =  GPIO_E24,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT4,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_GPIO_E25 - Mux:SACI_MCLK1 */
    {
        .pinIndex         =  GPIO_E25,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT4,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_GPIO_E17 - Mux:GPIO */
    {
        .pinIndex         =  GPIO_E17,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_GPIO_E18 - Mux:GPIO */
    {
        .pinIndex         =  GPIO_E18,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:UART4_TX - Mux:UART4_TXD */
    {
        .pinIndex         =  GPIO_E4,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT5,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:UART4_RX - Mux:UART4_RXD */
    {
        .pinIndex         =  GPIO_E5,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT5,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:UART5_TX - Mux:UART5_TXD */
    {
        .pinIndex         =  GPIO_E8,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT5,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:UART5_RX - Mux:UART5_RXD */
    {
        .pinIndex         =  GPIO_E9,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT5,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:MCU_MPU_GPIO5 - Mux:GPIO */
    {
        .pinIndex         =  GPIO_E10,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:MCU_MPU_GPIO4 - Mux:GPIO */
    {
        .pinIndex         =  GPIO_E12,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:UART8_RXD - Mux:UART8_RXD */
    {
        .pinIndex         =  GPIO_E19,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT5,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:MCU_MPU_GPIO3 - Mux:GPIO */
    {
        .pinIndex         =  GPIO_E20,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:MCU_MPU_GPIO6 - Mux:GPIO */
    {
        .pinIndex         =  GPIO_E26,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:MCU_UART14_TX - Mux:UART14_TXD */
    {
        .pinIndex         =  GPIO_M4,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT4,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:MCU_UART14_RX - Mux:UART14_RXD */
    {
        .pinIndex         =  GPIO_M5,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT4,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_75242_A_IN0 - Mux:xTRG_IO15 */
    {
        .pinIndex         =  GPIO_M9,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT5,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:BTS7020_A_IN0 - Mux:xTRG_IO6 */
    {
        .pinIndex         =  GPIO_M0,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT5,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:BTS7020_A_IN1 - Mux:xTRG_IO12 */
    {
        .pinIndex         =  GPIO_M6,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT5,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:BTS7020_B_IN0 - Mux:xTRG_IO13 */
    {
        .pinIndex         =  GPIO_M7,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT5,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:BTS7020_B_IN1 - Mux:xTRG_IO14 */
    {
        .pinIndex         =  GPIO_M8,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT5,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:BTS7012_C_IN0 - Mux:xTRG_IO9 */
    {
        .pinIndex         =  GPIO_M3,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT5,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:EPB_A_MOS_EN - Mux:xTRG_IO7 */
    {
        .pinIndex         =  GPIO_M1,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT5,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_GPIO_M2TCA6424_INT - Mux:GPIO */
    {
        .pinIndex         =  GPIO_M2,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_GPIO_M10 - Mux:I2C8_SCL */
    {
        .pinIndex         =  GPIO_M10,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT6,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_GPIO_M11 - Mux:I2C8_SDA */
    {
        .pinIndex         =  GPIO_M11,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT6,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_75242_A_IN1 - Mux:xTRG_IO38 */
    {
        .pinIndex         =  GPIO_H6,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT5,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:BTS7012_B_IN0 - Mux:xTRG_IO33 */
    {
        .pinIndex         =  GPIO_H1,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT5,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:BTS7120_B_IN1 - Mux:xTRG_IO35 */
    {
        .pinIndex         =  GPIO_H3,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT5,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:BTS7120_D_IN1 - Mux:xTRG_IO40 */
    {
        .pinIndex         =  GPIO_H8,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT5,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:BTS7120_D_IN0 - Mux:xTRG_IO36 */
    {
        .pinIndex         =  GPIO_H4,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT5,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:BTS7120_B_IN0 - Mux:xTRG_IO44 */
    {
        .pinIndex         =  GPIO_H12,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT5,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:VNQ7E100_B_IN0 - Mux:xTRG_IO37 */
    {
        .pinIndex         =  GPIO_H5,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT5,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:TLE94103_SPI5_SS3 - Mux:SPI5_SS3 */
    {
        .pinIndex         =  GPIO_H13,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT3,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:TLE8108_IN1 - Mux:xTRG_IO39 */
    {
        .pinIndex         =  GPIO_H7,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT5,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:TLE8108_IN3 - Mux:xTRG_IO41 */
    {
        .pinIndex         =  GPIO_H9,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT5,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:TLE8108_IN4 - Mux:xTRG_IO42 */
    {
        .pinIndex         =  GPIO_H10,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT5,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_GPIO_H0_DELETE - Mux:GPIO */
    {
        .pinIndex         =  GPIO_H0,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT0,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:IN_IPL01 - Mux:xTRG_IO34 */
    {
        .pinIndex         =  GPIO_H2,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT5,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_NOPULL,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_HPIO_H11_DELETE - Mux:xTRG_IO43 */
    {
        .pinIndex         =  GPIO_H11,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT5,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS_SCHMITT,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_GPIO_X0 - Mux:XSPI1_PA_DQS */
    {
        .pinIndex         =  GPIO_X0,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_GPIO_X1_PA_SCLK - Mux:XSPI1_PA_SCLK */
    {
        .pinIndex         =  GPIO_X1,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_HIGH,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_GPIO_X2_PA_SS0 - Mux:XSPI1_PA_SS0 */
    {
        .pinIndex         =  GPIO_X2,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_GPIO_X3_ - Mux:XSPI1_PA_DATA0 */
    {
        .pinIndex         =  GPIO_X3,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_GPIO_X4 - Mux:XSPI1_PA_DATA1 */
    {
        .pinIndex         =  GPIO_X4,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_GPIO_X5 - Mux:XSPI1_PA_DATA2 */
    {
        .pinIndex         =  GPIO_X5,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_GPIO_X6 - Mux:XSPI1_PA_DATA3 */
    {
        .pinIndex         =  GPIO_X6,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_GPIO_X7 - Mux:XSPI1_PA_DATA4 */
    {
        .pinIndex         =  GPIO_X7,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_GPIO_X8 - Mux:XSPI1_PA_DATA5 */
    {
        .pinIndex         =  GPIO_X8,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_GPIO_X9 - Mux:XSPI1_PA_DATA6 */
    {
        .pinIndex         =  GPIO_X9,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:PortPin_GPIO_X10 - Mux:XSPI1_PA_DATA7 */
    {
        .pinIndex         =  GPIO_X10,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_IN,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },


    /* PortPinid:EPB_A_MOS_EN_xtrg - Mux:XSPI1_PA_SS1 */
    {
        .pinIndex         =  GPIO_X11,
        .modeChangable    =  FALSE,
        .mux              =  PORT_PIN_MUX_ALT1,
        .openDrain        =  PORT_PIN_PUSH_PULL,
        .pullConfig       =  PORT_PIN_PULL_UP,
        .slewRate         =  PORT_PIN_SR_FAST,
        .inputSelect      =  PORT_PIN_IS_CMOS,
        .driveStrength    =  PORT_PIN_DS_8MA,
        .dataDirection    =  PORT_PIN_OUT,
        .interruptConfig  =  PORT_PIN_INTERRUPT_DISABLED,
        .initialValue     =  PORT_PIN_LEVEL_LOW,
        .forceInput       =  PORT_PIN_FORCE_INPUT_NORMAL,
        .directChangable  =  FALSE,
    },

};



/** \brief  port init analog config settings, provide to Port_Cfg. */
const Port_AnalogConfigType Port_PinAnalogConfig[NUM_OF_ANALOG_PINS] = {
    {
        GPIO_B6,
        PORT_PIN_SETTING_ANALOG_3V3,
    },
    {
        GPIO_B8,
        PORT_PIN_SETTING_ANALOG_3V3,
    },
    {
        GPIO_B15,
        PORT_PIN_SETTING_ANALOG_3V3,
    },
    {
        GPIO_B9,
        PORT_PIN_SETTING_ANALOG_3V3,
    },
    {
        GPIO_B7,
        PORT_PIN_SETTING_ANALOG_3V3,
    },
    {
        GPIO_B14,
        PORT_PIN_SETTING_ANALOG_3V3,
    },
    {
        GPIO_C0,
        PORT_PIN_SETTING_ANALOG_3V3,
    },
    {
        GPIO_C1,
        PORT_PIN_SETTING_ANALOG_3V3,
    },
    {
        GPIO_C4,
        PORT_PIN_SETTING_ANALOG_3V3,
    },
    {
        GPIO_C11,
        PORT_PIN_SETTING_ANALOG_3V3,
    },
    {
        GPIO_C9,
        PORT_PIN_SETTING_ANALOG_3V3,
    },
    {
        GPIO_C10,
        PORT_PIN_SETTING_ANALOG_3V3,
    },
    {
        GPIO_C5,
        PORT_PIN_SETTING_ANALOG_3V3,
    },
    {
        GPIO_C8,
        PORT_PIN_SETTING_ANALOG_3V3,
    },
    {
        GPIO_A4,
        PORT_PIN_SETTING_ANALOG_3V3,
    },
    {
        GPIO_A5,
        PORT_PIN_SETTING_ANALOG_3V3,
    },
    {
        GPIO_A6,
        PORT_PIN_SETTING_ANALOG_3V3,
    },
    {
        GPIO_A14,
        PORT_PIN_SETTING_ANALOG_3V3,
    },
};

/** \brief  The entire configuration of the port pin, is provided to the initialization function */
const Port_ConfigType Port_Cfg = {
    /* port init config settings number */
    NUM_OF_CONFIGURED_PINS,
    /* pointer to port init config settings */
    &Port_PinInitConfig[0],
#if (PORT_ANALOG_PIN_ENABLE == STD_ON)
    /* port init analog config settings number */
    NUM_OF_ANALOG_PINS,
    /* pointer to port init analog config settings*/
    &Port_PinAnalogConfig[0],
#endif /** #if (PORT_ANALOG_PIN_ENABLE == STD_ON)*/
};
#define PORT_STOP_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"
#ifdef __cplusplus
}
#endif
/* End of file */
