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
 * @file  Wdg_140_Instance4_Wdt.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Wdg
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Wdg_140_Instance4_Wdt.h"

#define WDG_START_SEC_CODE
#include "Wdg_MemMap.h"

/**
 * @brief Wdg driver instance 1 Init.
 * @param[in]  ConfigPtr Pointer to a selected configuration structure
 * @return   none
*/
FUNC(void, WDG_CODE) Wdg_140_Instance4_Wdt_Init
(
    P2CONST(Wdg_ConfigType, AUTOMATIC, WDG_APPL_CONST) ConfigPtr
)
{
    Wdg_Init(ConfigPtr, WDT4_INDEX);
}

/**
 * @brief Wdg driver instance 1 SetMode
 * @param[in]  Mode The running mode which of one WDGIF_OFF_MODE/WDGIF_SLOW_MODE/WDGIF_FAST_MODE
 * @return   Std_ReturnType E_OK/E_NOT_OK
*/
FUNC(Std_ReturnType, WDG_CODE) Wdg_140_Instance4_Wdt_SetMode
(
    VAR(WdgIf_ModeType, AUTOMATIC) Mode
)
{
    VAR(Std_ReturnType, AUTOMATIC) Ret = E_NOT_OK;
    Ret = Wdg_SetMode(Mode, WDT4_INDEX);
    return Ret;
}

/**
 * @brief Wdg driver instance 4 SetTriggerCondition
 * @param[in]  Timeout Wdg timeout value(in ms).
 * @return   none
*/
FUNC(void, WDG_CODE) Wdg_140_Instance4_Wdt_SetTriggerCondition
(
    VAR(uint16, AUTOMATIC) Timeout
)
{
    Wdg_SetTriggerCondition(Timeout, WDT4_INDEX);
}

/**
 * @brief Trigger routine
 * @param[in]  none
 * @return   none
*/
FUNC(void, WDG_CODE) Wdg_140_Instance4_Wdt_TriggerRoutine
(
    void
)
{
    Wdg_Ip_TriggerRoutine(WDT4_INDEX);
}

/**
 * @brief Get version information of module
 * @param[in]  ConfigPtr Pointer to a selected configuration structure
 * @return   none
*/
FUNC(void, WDG_CODE) Wdg_140_Instance4_Wdt_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, WDG_APPL_DATA) VerInfoPtr
)
{
    Wdg_GetVersionInfo(VerInfoPtr, WDT4_INDEX);
}

#define WDG_STOP_SEC_CODE
#include "Wdg_MemMap.h"

#ifdef __cplusplus
}
#endif
