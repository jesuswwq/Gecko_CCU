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

#ifndef TAISHAN_PINCTRL_H_
#define TAISHAN_PINCTRL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "Port_Hw_PinCtrl.h"
#include "Mcu_Scr.h"
#include "Mcu_ScrBits.h"

/* safety domain pin */
#define JTAG_TDI        0
#define JTAG_TDO        1
#define JTAG_TRST_N     2
#define JTAG_TMS        3
#define JTAG_TCK        4
#define GPIO_X0         5
#define GPIO_X1         6
#define GPIO_X2         7
#define GPIO_X3         8
#define GPIO_X4         9
#define GPIO_X5         10
#define GPIO_X6         11
#define GPIO_X7         12
#define GPIO_X8         13
#define GPIO_X9         14
#define GPIO_X10        15
#define GPIO_X11        16
#define GPIO_Y0         17
#define GPIO_Y1         18
#define GPIO_Y2         19
#define GPIO_Y3         20
#define GPIO_Y4         21
#define GPIO_Y5         22
#define GPIO_Y6         23
#define GPIO_Y7         24
#define GPIO_Y8         25
#define GPIO_Y9         26
#define GPIO_Y10        27
#define GPIO_Y11        28
#define GPIO_A0         29
#define GPIO_A1         30
#define GPIO_A2         31
#define GPIO_A3         32
#define GPIO_A4         33
#define GPIO_A5         34
#define GPIO_A6         35
#define GPIO_A7         36
#define GPIO_A8         37
#define GPIO_A9         38
#define GPIO_A10        39
#define GPIO_A11        40
#define GPIO_A12        41
#define GPIO_A13        42
#define GPIO_A14        43
#define GPIO_A15        44
#define GPIO_B0         45
#define GPIO_B1         46
#define GPIO_B2         47
#define GPIO_B3         48
#define GPIO_B4         49
#define GPIO_B5         50
#define GPIO_B6         51
#define GPIO_B7         52
#define GPIO_B8         53
#define GPIO_B9         54
#define GPIO_B10        55
#define GPIO_B11        56
#define GPIO_B12        57
#define GPIO_B13        58
#define GPIO_B14        59
#define GPIO_B15        60
#define GPIO_C0         61
#define GPIO_C1         62
#define GPIO_C2         63
#define GPIO_C3         64
#define GPIO_C4         65
#define GPIO_C5         66
#define GPIO_C6         67
#define GPIO_C7         68
/*taishan_only start*/
#define GPIO_C8         69
#define GPIO_C9         70
#define GPIO_C10        71
#define GPIO_C11        72
#define GPIO_C12        73
#define GPIO_C13        74
#define GPIO_C14        75
#define GPIO_C15        76
/*taishan_only end*/
#define GPIO_G0         77
#define GPIO_G1         78
#define GPIO_G2         79
#define GPIO_G3         80
#define GPIO_G4         81
#define GPIO_G5         82
#define GPIO_G6         83
#define GPIO_G7         84
#define GPIO_G8         85
#define GPIO_G9         86
#define GPIO_G10        87
#define GPIO_G11        88
/*taishan_only start*/
#define GPIO_M0         89
#define GPIO_M1         90
#define GPIO_M2         91
#define GPIO_M3         92
#define GPIO_M4         93
#define GPIO_M5         94
#define GPIO_M6         95
#define GPIO_M7         96
#define GPIO_M8         97
#define GPIO_M9         98
#define GPIO_M10        99
#define GPIO_M11        100
/*taishan_only end*/
#define GPIO_S0         101
#define GPIO_S1         102
#define GPIO_S2         103
#define GPIO_S3         104
#define GPIO_S4         105
#define GPIO_S5         106
#define GPIO_S6         107
#define GPIO_S7         108
/*taishan_only start*/
#define GPIO_S8         109
#define GPIO_S9         110
#define GPIO_S10        111
#define GPIO_S11        112
#define GPIO_S12        113
#define GPIO_S13        114
/*taishan_only end*/
#define GPIO_H0         115
#define GPIO_H1         116
#define GPIO_H2         117
#define GPIO_H3         118
#define GPIO_H4         119
#define GPIO_H5         120
#define GPIO_H6         121
#define GPIO_H7         122
#define GPIO_H8         123
#define GPIO_H9         124
#define GPIO_H10        125
#define GPIO_H11        126
#define GPIO_H12        127
#define GPIO_H13        128
#define GPIO_F0         129
#define GPIO_F1         130
#define GPIO_F2         131
#define GPIO_F3         132
#define GPIO_F4         133
#define GPIO_F5         134

/* ap domain pin */
#define GPIO_L0         135
#define GPIO_L1         136
#define GPIO_L2         137
#define GPIO_L3         138
#define GPIO_L4         139
#define GPIO_L5         140
#define GPIO_L6         141
#define GPIO_L7         142
#define GPIO_L8         143
#define GPIO_L9         144
/*taishan_only start*/
#define GPIO_D0         145
#define GPIO_D1         146
#define GPIO_D2         147
#define GPIO_D3         148
#define GPIO_D4         149
#define GPIO_D5         150
#define GPIO_D6         151
#define GPIO_D7         152
#define GPIO_D8         153
#define GPIO_D9         154
#define GPIO_D10        155
#define GPIO_D11        156
#define GPIO_D12        157
#define GPIO_D13        158
#define GPIO_D14        159
#define GPIO_D15        160
#define GPIO_D16        161
#define GPIO_D17        162
#define GPIO_D18        163
#define GPIO_D19        164
#define GPIO_D20        165
#define GPIO_D21        166
#define GPIO_D22        167
#define GPIO_D23        168
#define GPIO_D24        169
#define GPIO_D25        170
#define GPIO_D26        171
#define GPIO_D27        172
#define GPIO_D28        173
#define GPIO_D29        174
#define GPIO_D30        175
#define GPIO_D31        176
#define GPIO_D32        177
#define GPIO_D33        178
#define GPIO_D34        179
#define GPIO_D35        180
#define GPIO_D36        181
#define GPIO_D37        182
#define GPIO_D38        183
#define GPIO_D39        184
#define GPIO_D40        185
#define GPIO_D41        186
/*taishan_only end*/
#define GPIO_E0         187
#define GPIO_E1         188
#define GPIO_E2         189
#define GPIO_E3         190
#define GPIO_E4         191
#define GPIO_E5         192
/*taishan_only start*/
#define GPIO_E6         193
#define GPIO_E7         194
#define GPIO_E8         195
#define GPIO_E9         196
#define GPIO_E10        197
#define GPIO_E11        198
#define GPIO_E12        199
#define GPIO_E13        200
#define GPIO_E14        201
#define GPIO_E15        202
#define GPIO_E16        203
#define GPIO_E17        204
#define GPIO_E18        205
#define GPIO_E19        206
#define GPIO_E20        207
#define GPIO_E21        208
#define GPIO_E22        209
#define GPIO_E23        210
#define GPIO_E24        211
#define GPIO_E25        212
#define GPIO_E26        213
/*taishan_only end*/

#define TAISHAN_PIN_NUM                  214
#define TAISHAN_SAFETY_PIN_START         0
#define TAISHAN_SAFETY_PIN_NUM           135
#define TAISHAN_AP_PIN_START             135
#define TAISHAN_AP_PIN_NUM               79

#define TAISHAN_INPUT_SELECT_NUM         827


#define TAISHAN_PAD_CONFIG_REG_OFFSET    0x1000
#define TAISHAN_MUX_CONFIG_REG_OFFSET    0x2000
#define TAISHAN_INPUT_SELECT_REG_OFFSET  0x3000

#define MUX_FUNC_SHIFT              0
#define MUX_FUNC_WIDTH              4
#define MUX_ODE_SHIFT               4
#define MUX_ODE_WIDTH               1
#define MUX_FIN_SHIFT               8
#define MUX_FIN_WIDTH               2
#define MUX_FIN_IP_SHIFT            10
#define MUX_FIN_IP_WIDTH            16
#define MUX_FV_SHIFT                29
#define MUX_FV_WIDTH                1
#define MUX_DO_FORCE_EN_SHIFT       30
#define MUX_DO_FORCE_EN_WIDTH       1
#define MUX_DO_FORCE_VALUE_SHIFT    31
#define MUX_DO_FORCE_VALUE_WIDTH    1

#define PAD_PULL_SHIFT              0
#define PAD_PULL_WIDTH              2
#define PAD_DS_SHIFT                4
#define PAD_DS_WIDTH                2
#define PAD_SR_SHIFT                8
#define PAD_SR_WIDTH                1
#define PAD_IS_SHIFT                12
#define PAD_IS_WIDTH                1
#define PAD_POE_SHIFT               16
#define PAD_POE_WIDTH               1
#define PAD_MS_SHIFT                20
#define PAD_MS_WIDTH                1

#define INPUT_SELECT_SRC_SEL_SHIFT  0
#define INPUT_SELECT_SRC_SEL_WIDTH  4

/* Alternative function selection. */
#define MUX_FUNC_GPIO               (0x0)
#define MUX_FUNC_ALT1               (0x1)
#define MUX_FUNC_ALT2               (0x2)
#define MUX_FUNC_ALT3               (0x3)
#define MUX_FUNC_ALT4               (0x4)
#define MUX_FUNC_ALT5               (0x5)
#define MUX_FUNC_ALT6               (0x6)
#define MUX_FUNC_ALT7               (0x7)
#define MUX_FUNC_ALT8               (0x8)
#define MUX_FUNC_ALT9               (0x9)

/* Open drain or push pull, only for output pads. */
/**!!!** diff from kunlun ***/
#define MUX_ODE_PUSHPULL            (0x0)
#define MUX_ODE_OPENDRAIN           (0x1)

/* Pulls. */
#define PAD_NOPULL                  (0x0)
#define PAD_PULLDOWN                (0x1)
#define PAD_PULLUP                  (0x3)

/* Output drive strength. */
#define PAD_DS_2mA                  (0x0)
#define PAD_DS_8mA                  (0x1)
#define PAD_DS_4mA                  (0x2)
#define PAD_DS_12mA                 (0x3)

/* Slew rate. */
#define PAD_SR_FAST                 (0x0)
#define PAD_SR_SLOW                 (0x1)

/* Input Schmitt Select. Schmitt trigger mode provides input
 * glitch filtering (default is normal mode).
 */
#define PAD_IS_SCHMITT              (0x1)
#define PAD_IS_NORMAL               (0x0)

/* Pad mode select. 0->3.3v 1->5.0v */
#define PAD_MS_LOW                  (0x0)
#define PAD_MS_HIGH                 (0x1)

/* Force input ON/OFF.
 *  - no force:  Pad input/output is selected by ALT function.
 *  - force enable: Enable pad input, regardless of ALT function.
 *  - force disable: Disable pad input. Internal IP read the value of
 *    FORCE_INPUT bit.
 */
#define PAD_INPUT_NO_FORCE           (0x0)
#define PAD_INPUT_FORCE_ENABLE       (0x1)
#define PAD_INPUT_FORCE_DISABLE      (0x2)
/* Force input value. Used in PAD_INPUT_FORCE_DISABLE mode. */
#define PAD_FORCE_INPUT_VALUE_0      (0)
#define PAD_FORCE_INPUT_VALUE_1      (1)

typedef struct taishan_input_select {
    uint32  pin;
    uint32  mux;
    uint32  base;
    uint32  offset;
    uint32  value;
} taishan_input_select_t;

typedef struct taishan_pinctrl {
    uint32   base;
    uint32   pad_reg_offset;
    uint32   mux_reg_offset;
} taishan_pinctrl_t;

typedef struct {
    uint32 pin;
    scr_signal_t scrbit;
} taishan_analog_pinctrl_t;

typedef enum pin_mux {
    PIN_MUX_ALT0  = 0U,
    PIN_MUX_ALT1  = 1U,
    PIN_MUX_ALT2  = 2U,
    PIN_MUX_ALT3  = 3U,
    PIN_MUX_ALT4  = 4U,
    PIN_MUX_ALT5  = 5U,
    PIN_MUX_ALT6  = 6U,
    PIN_MUX_ALT7  = 7U,
    PIN_MUX_ALT8  = 8U,
    PIN_MUX_ALT9  = 9U,
} pin_mux_e;

typedef enum pin_open_drain {
    PIN_OPEN_DRAIN  = 0U,
    PIN_PUSH_PULL   = 2U,
} pin_open_drain_e;

typedef enum pin_pull_config {
    PIN_NOPULL     = 0U,
    PIN_PULL_DOWN  = 1U,
    PIN_PULL_UP    = 2U,
} pin_pull_config_e;

typedef enum pin_drive_strength {
    PIN_DS_2MA  = 0U,
    PIN_DS_8MA  = 1U,
    PIN_DS_4MA  = 2U,
    PIN_DS_12MA = 3U,
} pin_drive_strength_e;

typedef enum pin_slew_rate {
    PIN_SR_FAST  = 0U,
    PIN_SR_SLOW  = 1U,
} pin_slew_rate_e;

typedef enum pin_input_select {
    PIN_IS_CMOS          = 0U,
    PIN_IS_CMOS_SCHMITT  = 1U,
} pin_input_select_e;

typedef enum pin_data_direction {
    PIN_INPUT_DIRECTION  = 0U,
    PIN_OUTPUT_DIRECTION = 1U,
} pin_data_direction_e;

typedef enum pin_interrupt_config {
    PIN_INTERRUPT_DISABLED     = 0U,
    PIN_INTERRUPT_HIGH_LEVEL   = 2U,
    PIN_INTERRUPT_LOW_LEVEL    = 1U,
    PIN_INTERRUPT_RISING_EDGE  = 3U,
    PIN_INTERRUPT_FALLING_EDGE = 4U,
    PIN_INTERRUPT_BOTH_EDGE    = 5U,
    PIN_ASYC_INTERRUPT_HIGH_LEVEL   = 7U,
    PIN_ASYC_INTERRUPT_LOW_LEVEL    = 6U,
    PIN_ASYC_INTERRUPT_RISING_EDGE  = 8U,
    PIN_ASYC_INTERRUPT_FALLING_EDGE = 9U,
    PIN_ASYC_INTERRUPT_BOTH_EDGE    = 10U,
} pin_interrupt_config_e;

typedef enum pin_level_type {
    PIN_LEVEL_LOW  = 0U,
    PIN_LEVEL_HIGH = 1U,
} pin_level_type_e;

typedef enum pin_force_input {
    PIN_FORCE_INPUT_NORMAL  = 0U,
    PIN_FORCE_INPUT_ENABLE  = 1U,
    PIN_FORCE_INPUT_HIGH    = 2U,
    PIN_FORCE_INPUT_LOW     = 3U,
} pin_force_input_e;

typedef struct pin_settings_config {
    uint32                    pin_index;
    pin_mux_e                 mux;
    pin_open_drain_e          open_drain;
    pin_pull_config_e         pull_config;
    pin_drive_strength_e      drive_strength;
    pin_slew_rate_e           slew_rate;
    pin_input_select_e        input_select;
    pin_data_direction_e      data_direction;
    pin_interrupt_config_e    interrupt_config;
    pin_level_type_e          initial_value;
    pin_force_input_e         force_input;
} pin_settings_config_t;

typedef enum {
    PIN_SETTING_ANALOG_3V3  = 0U,
    PIN_SETTING_ANALOG_5V = 1U,
} pin_analog_input_e;

typedef struct {
    uint32 pin_index;
    pin_analog_input_e input_level;
} pin_analog_config_t;

typedef struct {
    uint32 pin_index;
} pin_ETH_config_t;

void taishan_pinctrl_init(pinctrl_t *pinctrl, const taishan_pinctrl_t *dev);

#endif /* TAISHAN_PINCTRL_H_ */

#ifdef __cplusplus
}
#endif