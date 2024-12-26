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
 * @file  Port.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Port Driver.
*/

#ifndef PORT_H
#define PORT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "Port_Hw_E3.h"
#include "Port_Hw_E3_PinCtrl.h"

#define PORT_MODULE_ID  124

/* Error Codes */
#define PORT_E_INIT_FAILED              ((uint8)0x0C)
#define PORT_E_PARAM_INVALID_MODE       ((uint8)0x0D)
#define PORT_E_UNINIT                   ((uint8)0x0F)
#define PORT_E_PARAM_POINTER            ((uint8)0x10)

typedef struct {
    VAR(uint8, PORT_VAR) Num;
    P2CONST(pin_settings_config_t, AUTOMATIC, PORT_APPL_CONST) pPadCfg;
} Port_ConfigType;

extern const Port_ConfigType Port_Cfg;

/**
 * @brief    Initializes the Port Driver.
 * @details  This function initializes ports and pins with the configuration
 *           pionted by pCfg.
 *
 * @param[in] pCfg     A pointer to the configutation structure.
 */
FUNC(void, PORT_CODE) Port_Init
(
    P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) pCfg
);

/**
 * @brief   Set the direction of the Pin.
 * @details For most of the pins, the direction be controlled by IPs. For instance,
 *          UART tx pin is an output and rx is an input. An exception here is GPIO,
 *          which direction controlled by GPIO 'dir' and these pins are ones SW
 *          can really set their direction. To make things less-complicate, this
 *          func only set direction of GPIOs.
 *
 * @param[in]   Pin  The Pin index.
 * @param[in]   Direction  Input/Output.
 */
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
FUNC(void, PORT_CODE) Port_SetPinDirection
(
    VAR(Port_PinType,           AUTOMATIC) Pin,
    VAR(Port_PinDirectionType,  AUTOMATIC) Direction
);
#endif

/**
 * @brief   Get version information of this driver.
 * @param[inout]    pointer to Std_VersionInfoType which holds the version infor.
 */
FUNC (void, PORT_CODE) Port_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, PORT_APPL_DATA) pVerInfo
);

FUNC(void, PORT_CODE) Port_SetPinMode
(
    VAR(Port_PinType,           AUTOMATIC) Pin,
    VAR(Port_PinModeType,  AUTOMATIC)    Mode
);

/**
 * @brief   refresh the pad config.
 * @param[in]    Pin  refer the pin index
 * @param[in]    Mode a pointer to Port_PinConfigType which include the pad info.
 */
FUNC(void, PORT_CODE) Port_RefreshPinConfig
(
    VAR(Port_PinType,           AUTOMATIC) Pin,
    P2VAR(Port_PinConfigType, AUTOMATIC, PORT_APPL_CONST) Mode
);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef PORT_H */

