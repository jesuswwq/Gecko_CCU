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
 * @file  Port.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Port Driver.
*/

#ifdef __cplusplus
extern "C" {
#endif

#include "Mcu_Soc.h"
#include "Port.h"
#include "Port_Hw_E3.h"

#define PORT_START_SEC_CODE
#include "Port_MemMap.h"

#define PORT_H_VENDOR_ID    0x8C
#define PORT_H_AR_RELEASE_MAJOR_VERSION    4
#define PORT_H_AR_RELEASE_MINOR_VERSION    3
#define PORT_H_AR_RELEASE_REVISION_VERSION 1
#define PORT_H_SW_MAJOR_VERSION    1
#define PORT_H_SW_MINOR_VERSION    0
#define PORT_H_SW_PATCH_VERSION    0

FUNC(void, PORT_CODE) Port_Init
(
    P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) pCfg
)
{
    ASSERT(pCfg != NULL_PTR);

    if (0u != pCfg->Num) {
        Port_Hw_Init(pCfg->pPadCfg, pCfg->Num);
    }
    /* for ETH COMP io */
#if (PORT_ETHCOMP_PIN_ENABLE == STD_ON)
    Port_Ip_ETHCOMPPadSet();
#endif
    /* for analog digital combo io */
#if (PORT_ANALOG_PIN_ENABLE == STD_ON)
    Port_Ip_AnalogPadInit();
#endif
#if (PORT_RELEASE_DISPLAY_PIN == STD_ON)
#ifndef SEMIDRIVE_E3_LITE_SERIES
    Port_Ip_DispalyPadRelease();
#endif
#endif
}

FUNC(void, PORT_CODE) Port_SetPinMode
(
    VAR(Port_PinType,           AUTOMATIC) Pin,
    VAR(Port_PinModeType,       AUTOMATIC) Mode
)
{
    Port_Ip_SetPinMode(Pin, Mode);
}

FUNC(void, PORT_CODE) Port_RefreshPinConfig
(
    VAR(Port_PinType,           AUTOMATIC) Pin,
    P2VAR(Port_PinConfigType, AUTOMATIC, PORT_APPL_CONST) Mode
)
{
    Port_Ip_RefreshPinConfig(Pin, Mode);
}

#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
FUNC(void, PORT_CODE) Port_SetPinDirection
(
    VAR(Port_PinType,           AUTOMATIC) Pin,
    VAR(Port_PinDirectionType,  AUTOMATIC) Direction
)
{
    Port_Ip_SetPinDirection(Pin, Direction);
}
#endif

FUNC (void, PORT_CODE) Port_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, PORT_APPL_DATA) pVerInfo
)
{
    if (NULL_PTR != pVerInfo) {
        pVerInfo->vendorID = PORT_H_VENDOR_ID;
        pVerInfo->moduleID = PORT_MODULE_ID;
        pVerInfo->sw_major_version = PORT_H_SW_MAJOR_VERSION;
        pVerInfo->sw_minor_version = PORT_H_SW_MINOR_VERSION;
        pVerInfo->sw_patch_version = PORT_H_SW_PATCH_VERSION;
    }
}

#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"

#ifdef __cplusplus
}
#endif
