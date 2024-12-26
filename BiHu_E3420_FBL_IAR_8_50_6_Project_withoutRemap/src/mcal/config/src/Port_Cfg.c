/*
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
* an "AS IS" basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.
*
* You should have received a copy of the License along with this program.
* If not, see <http://www.semidrive.com/licenses/>.
*/

/**
 * @file  Port_Cfg.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Port Driver.
 * @date 2024-01-10 14:16:53
*/

#ifdef __cplusplus
extern "C" {
#endif

#include "Port.h"
#include "Port_Hw_E3_PinCtrl.h"








const pin_settings_config_t g_pin_init_config[] = {

    /* PortPinid:CAN7_RX - Mux:CANFD7.TX */
    {
        .pin_index         =  GPIO_D13,
        .mux               =  PIN_MUX_ALT2,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_INPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_LOW,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },


    /* PortPinid:CAN7_TX - Mux:CANFD7.RX */
    {
        .pin_index         =  GPIO_D12,
        .mux               =  PIN_MUX_ALT2,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_INPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_LOW,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },


    /* PortPinid:RESET_6424_AC_IN_GPIO_OUT_D2 - Mux:GPIO */
    {
        .pin_index         =  GPIO_D2,
        .mux               =  PIN_MUX_ALT0,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS_SCHMITT,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_OUTPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_LOW,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },


    /* PortPinid:SPI7_SS0 - Mux:SPI7.SS0 */
    {
        .pin_index         =  GPIO_D15,
        .mux               =  PIN_MUX_ALT2,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_INPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_LOW,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },
    {
        .pin_index         =  GPIO_D14,
        .mux               =  PIN_MUX_ALT2,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_INPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_LOW,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },
    {
        .pin_index         =  GPIO_S10,
        .mux               =  PIN_MUX_ALT3,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_OUTPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_HIGH,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },


    /* PortPinid:SPI7_SCLK - Mux:SPI7.SCLK */
    {
        .pin_index         =  GPIO_S11,
        .mux               =  PIN_MUX_ALT3,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_OUTPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_LOW,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },


    /* PortPinid:SPI7_MISO - Mux:SPI7.MISO */
    {
        .pin_index         =  GPIO_S12,
        .mux               =  PIN_MUX_ALT3,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_INPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_LOW,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },


    /* PortPinid:SPI7_MOSI - Mux:SPI7.MOSI */
    {
        .pin_index         =  GPIO_S13,
        .mux               =  PIN_MUX_ALT3,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_OUTPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_LOW,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },


    /* PortPinid:TCA6424_INT_GPIO_IN_M2 - Mux:GPIO */
    {
        .pin_index         =  GPIO_M2,
        .mux               =  PIN_MUX_ALT0,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS_SCHMITT,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_INPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_LOW,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },


    /* PortPinid:I2C1_SCL - Mux:I2C1.SCL */
    {
        .pin_index         =  GPIO_C2,
        .mux               =  PIN_MUX_ALT6,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_INPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_LOW,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },


    /* PortPinid:I2C1_SDA - Mux:I2C1.SDA */
    {
        .pin_index         =  GPIO_C3,
        .mux               =  PIN_MUX_ALT6,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_INPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_LOW,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },


    /* PortPinid:PB_DQ0 - Mux:XSPI1.PB_SS1 */
    {
        .pin_index         =  GPIO_Y0,
        .mux               =  PIN_MUX_ALT1,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_INPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_LOW,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },


    /* PortPinid:PB_DQ1 - Mux:XSPI1.PB_DATA7 */
    {
        .pin_index         =  GPIO_Y1,
        .mux               =  PIN_MUX_ALT1,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_INPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_LOW,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },


    /* PortPinid:PB_DQ2 - Mux:XSPI1.PB_DATA6 */
    {
        .pin_index         =  GPIO_Y2,
        .mux               =  PIN_MUX_ALT1,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_INPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_LOW,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },


    /* PortPinid:PB_DQ3 - Mux:XSPI1.PB_DATA5 */
    {
        .pin_index         =  GPIO_Y3,
        .mux               =  PIN_MUX_ALT1,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_INPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_LOW,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },


    /* PortPinid:PB_DQ4 - Mux:XSPI1.PB_DATA4 */
    {
        .pin_index         =  GPIO_Y4,
        .mux               =  PIN_MUX_ALT1,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_INPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_LOW,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },


    /* PortPinid:PB_DQ5 - Mux:XSPI1.PB_DATA3 */
    {
        .pin_index         =  GPIO_Y5,
        .mux               =  PIN_MUX_ALT1,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_INPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_LOW,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },


    /* PortPinid:PB_DQ6 - Mux:XSPI1.PB_DATA2 */
    {
        .pin_index         =  GPIO_Y6,
        .mux               =  PIN_MUX_ALT1,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_INPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_LOW,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },


    /* PortPinid:PB_DQ7 - Mux:XSPI1.PB_DATA1 */
    {
        .pin_index         =  GPIO_Y7,
        .mux               =  PIN_MUX_ALT1,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_INPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_LOW,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },


    /* PortPinid:PB_DQ8 - Mux:XSPI1.PB_DATA0 */
    {
        .pin_index         =  GPIO_Y8,
        .mux               =  PIN_MUX_ALT1,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_INPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_LOW,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },


    /* PortPinid:PB_DQ9 - Mux:XSPI1.PB_SS0 */
    {
        .pin_index         =  GPIO_Y9,
        .mux               =  PIN_MUX_ALT1,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_INPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_LOW,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },


    /* PortPinid:PB_DQ10 - Mux:XSPI1.PB_SCLK */
    {
        .pin_index         =  GPIO_Y10,
        .mux               =  PIN_MUX_ALT1,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_INPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_LOW,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },


    /* PortPinid:PB_DQ11 - Mux:XSPI1.PB_DQS */
    {
        .pin_index         =  GPIO_Y11,
        .mux               =  PIN_MUX_ALT1,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_INPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_LOW,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },


    /* PortPinid:PA_DQ0 - Mux:XSPI1.PA_DQS */
    {
        .pin_index         =  GPIO_X0,
        .mux               =  PIN_MUX_ALT1,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_INPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_LOW,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },


    /* PortPinid:PA_DQ1 - Mux:XSPI1.PA_SCLK */
    {
        .pin_index         =  GPIO_X1,
        .mux               =  PIN_MUX_ALT1,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_INPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_LOW,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },


    /* PortPinid:PA_DQ2 - Mux:XSPI1.PA_SS0 */
    {
        .pin_index         =  GPIO_X2,
        .mux               =  PIN_MUX_ALT1,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_INPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_LOW,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },


    /* PortPinid:PA_DQ3 - Mux:XSPI1.PA_DATA0 */
    {
        .pin_index         =  GPIO_X3,
        .mux               =  PIN_MUX_ALT1,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_INPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_LOW,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },


    /* PortPinid:PA_DQ4 - Mux:XSPI1.PA_DATA1 */
    {
        .pin_index         =  GPIO_X4,
        .mux               =  PIN_MUX_ALT1,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_INPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_LOW,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },


    /* PortPinid:PA_DQ5 - Mux:XSPI1.PA_DATA2 */
    {
        .pin_index         =  GPIO_X5,
        .mux               =  PIN_MUX_ALT1,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_INPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_LOW,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },


    /* PortPinid:PA_DQ6 - Mux:XSPI1.PA_DATA3 */
    {
        .pin_index         =  GPIO_X6,
        .mux               =  PIN_MUX_ALT1,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_INPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_LOW,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },


    /* PortPinid:PA_DQ7 - Mux:XSPI1.PA_DATA4 */
    {
        .pin_index         =  GPIO_X7,
        .mux               =  PIN_MUX_ALT1,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_INPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_LOW,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },


    /* PortPinid:PA_DQ8 - Mux:XSPI1.PA_DATA5 */
    {
        .pin_index         =  GPIO_X8,
        .mux               =  PIN_MUX_ALT1,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_INPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_LOW,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },


    /* PortPinid:PA_DQ9 - Mux:XSPI1.PA_DATA6 */
    {
        .pin_index         =  GPIO_X9,
        .mux               =  PIN_MUX_ALT1,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_INPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_LOW,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },


    /* PortPinid:PA_DQ10 - Mux:XSPI1.PA_DATA7 */
    {
        .pin_index         =  GPIO_X10,
        .mux               =  PIN_MUX_ALT1,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_INPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_LOW,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },


    /* PortPinid:PA_DQ11 - Mux:XSPI1.PA_SS1 */
    {
        .pin_index         =  GPIO_X11,
        .mux               =  PIN_MUX_ALT1,
        .open_drain        =  PIN_PUSH_PULL,
        .pull_config       =  PIN_PULL_UP,
        .slew_rate         =  PIN_SR_FAST,
        .input_select      =  PIN_IS_CMOS,
        .drive_strength    =  PIN_DS_8MA,
        .data_direction    =  PIN_INPUT_DIRECTION,
        .interrupt_config  =  PIN_INTERRUPT_DISABLED,
        .initial_value     =  PIN_LEVEL_LOW,
        .force_input       =  PIN_FORCE_INPUT_NORMAL,
    },

};

CONST(Port_ConfigType, PORT_CONST) Port_Cfg = {
    NUM_OF_CONFIGURED_PINS,
    &g_pin_init_config[0]
};







#ifdef __cplusplus
}
#endif
