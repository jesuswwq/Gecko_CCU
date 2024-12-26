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
 * @file  Wdg_Types.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Wdg
 */

#ifndef WDG_TYPES_H
#define WDG_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#include "WdgIf_Types.h"
#include "Std_Types.h"

/* Call back notification type */
typedef void(*Wdg_NotificationType)(void);

/**
 * @enum Wdg_TimeoutBehaviorType
 * @brief Wdg behavior when wdg timeout.
*/
typedef enum {
    WDG_RESET,
    WDG_INTERRUPT,
    WDG_BOTH
} Wdg_TimeoutBehaviorType;

/**
 * @enum Wdg_TriggerConditionType
 * @brief Trigger Condition.
*/
typedef enum {
    NO_CONDITION_MODE        = 0, /*! @brief Normal mode,can be triggered directly */
    WINDOW_BASED_MODE        = 2U /*! @brief Only can be triggered in between low_limit and timeout.*/
} Wdg_TriggerConditionType;

/**
 * @struct Wdg_Ip_ModeConfigType
 * @brief Mode Config set
*/
typedef struct {
    uint32                      uClockFrequency;
    uint32                      uTimeoutPeriod;
    uint32                      uRefreshTime;
    Wdg_TimeoutBehaviorType     eTimeoutBehavior;
    Wdg_TriggerConditionType    eTriggerCondition;
    boolean                        bExternalSignalEnable;
} Wdg_Ip_ModeConfigType;

/**
 * @enum Wdg_ModuleStatusType
 * @brief The driver state
*/
typedef enum {
    WDG_UNINIT = 0,
    WDG_IDLE,
    WDG_BUSY
} Wdg_ModuleStatusType;

/**
 * @struct Wdg_ConfigType
 * @brief Wdg config set
*/
typedef struct {
    CONST(uint16, WDG_CONST) Wdg_InitTimeout;                       /*! @brief Init Timeout(in ms) */
    CONST(uint16, WDG_CONST) Wdg_MaxTimeout;                        /*! @brief Max Timeout(in ms) */
    CONST(WdgIf_ModeType, WDG_CONST) Wdg_DefaultMode;               /*! @brief default mode */
    CONST(uint8, WDG_CONST)
    Wdg_CurrentInstance;                                            /*! @brief Current Wdg driver instance */
    CONST(Wdg_NotificationType, WDG_CONST)
    Wdg_pfNotification;                                             /*! @brief Timeout call back notification */
    CONST(Wdg_Ip_ModeConfigType, WDG_CONST) (*Wdg_ModeSettings)[];  /*! @brief Wdg mode settings */
} Wdg_ConfigType;

typedef struct {
    CONST(uint8, WDG_CONST) Wdg_u8Channel;                            /*! @brief WDG channel ID,0-5 */
    CONST(uint8, WDG_CONST) Wdg_u8Index;                              /*! @brief WDG instance ID,0-5 */
} Wdg_IndexChannelConfigType;

#ifdef __cplusplus
}
#endif

#endif /* WDG_TYPES_H */
