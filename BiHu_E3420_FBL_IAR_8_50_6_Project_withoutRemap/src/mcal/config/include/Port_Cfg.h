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
 * @file  Port_Cfg.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Port Driver.
 * @date 2024-01-10 14:16:53
*/

#ifdef __cplusplus
extern "C" {
#endif

#ifndef PIN_CFG_H_
#define PIN_CFG_H_

#include "Port_Hw_E3_PinCtrl.h"

#define PORT_DEV_ERROR_DETECT       (STD_OFF)
#define PORT_VERSION_INFO_API       (STD_OFF)
#define PORT_SET_PIN_MODE_API       (STD_OFF)
#define PORT_SET_PIN_DIRECTION_API  (STD_ON)
#define PORT_EN_PIN_INT_API         (STD_OFF)
#define PORT_RELEASE_DISPLAY_PIN    (STD_ON)

/*
 * @brief define the configed digital pin num
 *
 */
#define NUM_OF_CONFIGURED_PINS  36U




#define PORT_ETHCOMP_PIN_ENABLE  (STD_OFF)

/*
 * @brief analog pin enable
 *
 */
#define PORT_ANALOG_PIN_ENABLE  (STD_OFF)

/*
 * @brief rename of then port pinid
 *
 */
#define PortConf_PortPin_CAN7_RX  GPIO_D13
#define PortConf_PortPin_CAN7_TX  GPIO_D12
#define PortConf_PortPin_RESET_6424_AC_IN_GPIO_OUT_D2  GPIO_D2
#define PortConf_PortPin_CAN8_TX  GPIO_D15
#define PortConf_PortPin_CAN8_RX  GPIO_D14
#define PortConf_PortPin_SPI7_SS0  GPIO_S10
#define PortConf_PortPin_SPI7_SCLK  GPIO_S11
#define PortConf_PortPin_SPI7_MISO  GPIO_S12
#define PortConf_PortPin_SPI7_MOSI  GPIO_S13
#define PortConf_PortPin_TCA6424_INT_GPIO_IN_M2  GPIO_M2
#define PortConf_PortPin_I2C1_SCL  GPIO_C2
#define PortConf_PortPin_I2C1_SDA  GPIO_C3
#define PortConf_PortPin_PB_DQ0  GPIO_Y0
#define PortConf_PortPin_PB_DQ1  GPIO_Y1
#define PortConf_PortPin_PB_DQ2  GPIO_Y2
#define PortConf_PortPin_PB_DQ3  GPIO_Y3
#define PortConf_PortPin_PB_DQ4  GPIO_Y4
#define PortConf_PortPin_PB_DQ5  GPIO_Y5
#define PortConf_PortPin_PB_DQ6  GPIO_Y6
#define PortConf_PortPin_PB_DQ7  GPIO_Y7
#define PortConf_PortPin_PB_DQ8  GPIO_Y8
#define PortConf_PortPin_PB_DQ9  GPIO_Y9
#define PortConf_PortPin_PB_DQ10  GPIO_Y10
#define PortConf_PortPin_PB_DQ11  GPIO_Y11
#define PortConf_PortPin_PA_DQ0  GPIO_X0
#define PortConf_PortPin_PA_DQ1  GPIO_X1
#define PortConf_PortPin_PA_DQ2  GPIO_X2
#define PortConf_PortPin_PA_DQ3  GPIO_X3
#define PortConf_PortPin_PA_DQ4  GPIO_X4
#define PortConf_PortPin_PA_DQ5  GPIO_X5
#define PortConf_PortPin_PA_DQ6  GPIO_X6
#define PortConf_PortPin_PA_DQ7  GPIO_X7
#define PortConf_PortPin_PA_DQ8  GPIO_X8
#define PortConf_PortPin_PA_DQ9  GPIO_X9
#define PortConf_PortPin_PA_DQ10  GPIO_X10
#define PortConf_PortPin_PA_DQ11  GPIO_X11

/*
 * @brief global config for digital io
 *
 */
extern const pin_settings_config_t g_pin_init_config[NUM_OF_CONFIGURED_PINS];


#endif

#ifdef __cplusplus
}
#endif
