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

#ifndef PORT_IP_H
#define PORT_IP_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "Dio_IP.h"
#include "Port_Cfg.h"

typedef uint16 Port_PinType;
typedef pin_settings_config_t Port_PinConfigType;

typedef enum {
    MUX_0,
    MUX_1,
    MUX_2,
    MUX_3,
    MUX_4,
    MUX_5,
    MUX_6,
    MUX_7,
    MUX_8,
    MUX_9
} Port_PinModeType;


typedef enum {
    PORT_PIN_IN = 0,        /**< @brief input. */
    PORT_PIN_OUT,           /**< @brief output. */
    PORT_PIN_INOUT          /**< @brief bidirectional. */
} Port_PinDirectionType;

/**
 * @brief Set direction of Dio pads.
 * @param[in]   Pin         the pin which direction to be set.
 * @param[in]   Direction   the direction to be set, 0 for input and 1 for output.
 */
FUNC(void, PORT_CODE) Port_Ip_SetPinDirection
(
    VAR(Port_PinType,              AUTOMATIC) Pin,
    VAR(Port_PinDirectionType,   AUTOMATIC) Direction
);

/**
 * @brief   Release MMC phy reset if needed. If pads mux-ed as mmc(mux=1), do nothing.
 */
//void Port_IpTryReleaseMMCPhy(void);

/**
 * @brief Set pin mode.
 * @param[in]   Pin         the pin which mode to be set.
 * @param[in]   Mode         the mode to be set, MUX0~MUX9.
 */
FUNC(void, PORT_CODE) Port_Ip_SetPinMode
(
    VAR(Port_PinType,           AUTOMATIC) Pin,
    VAR(Port_PinModeType,     AUTOMATIC) Mode
);

/**
 * @brief reconfig the pin
 * @param[in]   Pin         the pin which mode to be set.
 * @param[in]   Mode        pin mode, include mux/push poll/open drain... etc.
 */
FUNC(void, PORT_CODE) Port_Ip_RefreshPinConfig
(
    VAR(uint16,           AUTOMATIC) Pin,
    P2VAR(Port_PinConfigType, AUTOMATIC, PORT_APPL_CONST) Mode
);

void Port_Hw_Init(const pin_settings_config_t *settings, const unsigned int num);

#if (PORT_ETHCOMP_PIN_ENABLE == STD_ON)
void Port_Ip_ETHCOMPPadSet(void);
#endif

#if (PORT_ANALOG_PIN_ENABLE == STD_ON)
void Port_Ip_AnalogPadInit(void);
#endif

#if (PORT_RELEASE_DISPLAY_PIN == STD_ON)
#ifndef SEMIDRIVE_E3_LITE_SERIES
void Port_Ip_DispalyPadRelease(void);
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif  /* PORT_IP_H */
