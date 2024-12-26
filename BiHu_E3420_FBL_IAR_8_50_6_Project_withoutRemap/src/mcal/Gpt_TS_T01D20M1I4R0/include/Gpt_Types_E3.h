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
 * @file  Gpt_Types_E3.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Gpt
 */

#ifndef GPT_TYPES_E3_H
#define GPT_TYPES_E3_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"

typedef uint32 Gpt_ValueType;

/**
 * @enum Gpt_ChannelModeType
 * @brief The channel mode
*/
typedef enum {
    GPT_CH_MODE_CONTINUOUS = 0U,        /*! @brief countinous mode */
    GPT_CH_MODE_ONESHOT    = 1U         /*! @brief one-shot mode */
} Gpt_ChannelModeType;

/**
 * @enum Gpt_ClockRefType
 * @brief Timer module reference clock source
*/
typedef enum {
    GPT_CLOCKREF_APB  = 0U, /*! @brief APB clock domain*/
    GPT_CLOCKREF_XTAL = 1U, /*! @brief XTAL clock domain*/
} Gpt_ClockRefType;

/**
 * @enum Gpt_PredefTimerType
 * @brief PredefTimer
*/
typedef enum {
    GPT_PREDEF_TIMER_1US_16BIT = 0x0U,
    GPT_PREDEF_TIMER_1US_24BIT = 0x01U,
    GPT_PREDEF_TIMER_1US_32BIT = 0x02U,
} Gpt_PredefTimerType;

typedef enum {
    GPT_INDEX_BTM1 = 0U,
    GPT_INDEX_BTM2 = 1U,
    GPT_INDEX_BTM3 = 2U,
    GPT_INDEX_BTM4 = 3U,
    GPT_INDEX_BTM5 = 4U,
    GPT_INDEX_BTM6 = 5U
} Gpt_HwModule;

typedef enum {
    GPT_HW_TIMER_G0 = 0U,
    GPT_HW_TIMER_G1 = 1U,
} Gpt_HwChannel;

typedef enum {
    GPT_PREDEFTIMER_STOP = 0U,
    GPT_PREDEFTIMER_START = 1U,
} Gpt_PreDefTimerFlag;

/**
 * @struct Gpt_HwChannelPrescalerCfg
 * @brief Hardware Channel Prescaler config
*/
typedef struct {
    VAR(boolean, AUTOMATIC) bG0SetPrescaler;       /*! @brief whether to set G0 prescaler*/
    VAR(boolean, AUTOMATIC) bG1SetPrescaler;       /*! @brief whether to set G1 prescaler*/
} Gpt_HwChannelPrescalerCfg;

/**
 * @struct Gpt_HwChannelConfigType
 * @brief Hardware Channel descriptions
*/
typedef struct {
    VAR(Gpt_HwModule, AUTOMATIC) u8TimerModule;       /*! @brief Timer module ID ,0-1: Timer 0/1*/
    VAR(Gpt_HwChannel, AUTOMATIC)
    u8HwChannel;        /*! @brief GPT hw channel ID,0-1:G0/1 */
    VAR(uint8, AUTOMATIC) u8Prescaler;              /*! @brief Rtc channel clock source */
    VAR(boolean, AUTOMATIC) bNotificationEnabled;     /*! @brief Whether to enable interrupts */
    VAR(Gpt_ClockRefType, AUTOMATIC) eClockRef;       /*! @brief Reference clock*/
} Gpt_HwChannelConfigType;

/**
 * @struct Gpt_PredefChannelConfigType
 * @brief
*/
typedef struct {
    VAR(Gpt_HwModule, AUTOMATIC) u8TimerModule;     /*! @brief Timer module ID ,0-1: Timer 0/1*/
    VAR(uint8, AUTOMATIC) u8PredefTimer1us_Num;     /*! @brief 1us/tick Predef Timer Number 1-3*/
} Gpt_PredefChannelConfigType;

/**
 * @enum Gpt_ModeType
 * @brief Mode type
*/
typedef enum {
    GPT_MODE_NORMAL = 0U,
    GPT_MODE_SLEEP  = 1U
} Gpt_ModeType;

typedef enum {
    GPT_MODE_UNINIT = 0U,     /*! @brief GPT module is uninitialized */
    GPT_MODE_INITED = 1U      /*! @brief GPT Normal operation mode of the GPT */
} Gpt_DriverStateType;

typedef uint8 Gpt_ChannelType;
typedef void(*Gpt_NotificationType)(void);

/**
 * @struct Gpt_ChannelConfigType
 * @brief ChannelConfigType
*/
typedef struct {
    /*! @brief Pointer to external notification callback*/
    VAR(Gpt_NotificationType, AUTOMATIC) pfNotification;
    /*! @brief Channel max tick value */
    VAR(Gpt_ValueType, AUTOMATIC) uChannelTickValueMax;
    /*! @brief GPT channel mode */
    VAR(Gpt_ChannelModeType, AUTOMATIC) eChannelMode;
    /*! @brief Hardware dependent channel configuration*/
    VAR(Gpt_HwChannelConfigType, AUTOMATIC) Gpt_HwChannelConfig;
    /*! @brief Hardware work core*/
    VAR(uint8, AUTOMATIC) Gpt_CoreId;
} Gpt_ChannelConfigType;

/**
 * @struct Gpt_ConfigType
 * @brief Top level Gpt config
*/
typedef struct {
    /*! @brief Number of configured GPT channels*/
    CONST(Gpt_ChannelType, GPT_CONST) u8ChannelCount;
    /*! @brief Pointer to the GPT channel configuration */
    CONST(Gpt_ChannelConfigType, GPT_CONST) (*ptrChannelConfig)[];
    /*! @brief Pointer to the GPT channel predef timer configuration */
    CONSTP2CONST(Gpt_PredefChannelConfigType, GPT_CONST, GPT_APPL_CONST) ptrPredefChannelConfig;
} Gpt_ConfigType;

#ifdef __cplusplus
}
#endif

#endif /* GPT_TYPES_E3_H */
