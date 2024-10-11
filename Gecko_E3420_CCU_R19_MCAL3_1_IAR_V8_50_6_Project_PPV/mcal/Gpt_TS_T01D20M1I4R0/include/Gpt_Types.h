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
 *  \file     Gpt_Types.h                                                                               *
 *  \brief    This file contains interface header for GPT MCAL driver                                   *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/24     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef GPT_TYPES_H
#define GPT_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Std_Types.h"

/**
 *  \addtogroup MCAL_GPT_CFG GPT Configuration.
 *  \{
 */
/********************************************************************************************************
 *                                  Global Types definition                                             *
 *******************************************************************************************************/
/** \brief  Type describing the timeout value  */
/**
 * Traceability       : SWSR_GPT_014
 */
typedef uint32 Gpt_ValueType;

/** \brief Type describing the Gpt channel */
/**
 * Traceability       : SWSR_GPT_013
 */
typedef uint32 Gpt_ChannelType;

/** \brief  Notification callback function pointer  */
typedef void(*Gpt_NotificationType)(void);

/** \cond cache size */
/** cache line size */
#define GPT_CACHE_LINE      32U
/** \endcond */

/** \cond channel status */
/**
 *   GPT channel staatus
 */
typedef enum
{
    /** GPT channel status - uninitialized */
    GPT_STATUS_UNKNOW = 0,
    /** GPT channel status - initialized */
    GPT_STATUS_INITIALIZED = 1,
    /** GPT channel status - stopped */
    GPT_STATUS_STOPPED = 2,
    /** GPT channel status - expired */
    GPT_STATUS_EXPIRED = 3,
    /** GPT channel status - running */
    GPT_STATUS_RUNNING = 4
} Gpt_ChannelStatusType;
/** \endcond */

/**
 *  \brief  channel mode
 */
typedef enum
{
    /** countinous mode */
    GPT_CH_MODE_CONTINUOUS = 0U,
    /** one-shot mode */
    GPT_CH_MODE_ONESHOT    = 1U
} Gpt_ChannelModeType;

/**
 *  \brief  channel info
 */
typedef struct
{
    /** channel mode*/
    Gpt_ChannelModeType channelMode;
    /** GPT channel runtime status */
    Gpt_ChannelStatusType channelStatus;
    /** GPT channel has notification enabled at runtime */
    boolean notificationEnabled;
} Gpt_ChannelInfoType;


/**
 *  \brief clk ref
 */
typedef enum
{
    /** APB clock domain*/
    GPT_CLOCKREF_APB  = 0U,
    /** XTAL clock domain*/
    GPT_CLOCKREF_XTAL = 1U,
} Gpt_ClockRefType;

/**
* \brief    Predef Timer type. Indicates the type of predef timer.
* \details  This enumeration specifies the possible types of Predef Timer used to configure PREDEFTIMER
* \implements Gpt_PredefTimerType_enumeration
*/
typedef enum
{
    /** Selected value is the PREDEF_TIMER_1US_16BIT  */
    GPT_PREDEF_TIMER_1US_16BIT = 0x0U,
    /** Selected value is the PREDEF_TIMER_1US_24BIT  */
    GPT_PREDEF_TIMER_1US_24BIT = 0x01U,
    /** Selected value is the PREDEF_TIMER_1US_32BIT  */
    GPT_PREDEF_TIMER_1US_32BIT = 0x02U,
} Gpt_PredefTimerType;

/**
 *  \brief  hardware Module
 */
typedef enum
{
    /** BTM1 */
    GPT_INDEX_BTM1 = 0UL,
    /** BTM2 */
    GPT_INDEX_BTM2 = 1UL,
    /** BTM3 */
    GPT_INDEX_BTM3 = 2UL,
    /** BTM4 */
    GPT_INDEX_BTM4 = 3UL,
    /** BTM5 */
    GPT_INDEX_BTM5 = 4UL,
    /** BTM6 */
    GPT_INDEX_BTM6 = 5UL
} Gpt_HwModule;

/**
 *  \brief  hardware channel
 */
typedef enum
{
    /** G0 is apb clk ref */
    GPT_HW_TIMER_G0 = 0U,
    /** G0 is 24M clk ref */
    GPT_HW_TIMER_G1 = 1U,
} Gpt_HwChannel;

/**
 *  \brief hardware channel config
 */
typedef struct
{
    /** Timer module ID ,0-1: Timer 0/1*/
    Gpt_HwModule timerHwModule;
    /** GPT hw channel ID,0-1:G0/1 */
    Gpt_HwChannel hwChannel;
    /** Rtc channel clock source */
    uint32 prescaler;
    /** Whether to enable interrupts */
    boolean notificationEnabled;
    /** Reference clock*/
    Gpt_ClockRefType clockRef;
} Gpt_HwChannelConfigType;

/**
 *  \brief predeftimer channel config
 */
typedef struct
{
    /** Timer module ID ,0-1: Timer 0/1*/
    Gpt_HwModule timerHwModule;
    /** 1us/tick Predef Timer Number 1-3*/
    uint8 predefTimer1usNum;
} Gpt_PredefChannelConfigType;


/**
 *  \brief GPT driver status
 */
typedef enum
{
    /** GPT module is uninitialized */
    GPT_MODE_UNINIT = 0U,
    /** GPT Normal operation mode of the GPT */
    GPT_MODE_INITED = 1U
} Gpt_DriverStateType;

/** \brief  Configuration per channel */
typedef struct
{
    /** Pointer to external notification callback*/
    Gpt_NotificationType notification;
    /** Channel max tick value */
    Gpt_ValueType channelTickValueMax;
    /** GPT channel mode */
    Gpt_ChannelModeType channelMode;
    /** Hardware dependent channel configuration*/
    Gpt_HwChannelConfigType hwChannelConfig;
    /** Hardware work core*/
    uint8 gptCoreId;
} Gpt_ChannelConfigType;

/** \brief  global configuration of the driver  */
/**
 * Traceability       : SWSR_GPT_012
 */
typedef struct
{
    /** Number of configured GPT channels*/
    Gpt_ChannelType channelCount;
    /** Pointer to the GPT channel configuration */
    const Gpt_ChannelConfigType (*channelConfig)[];
    /** Pointer to the GPT channel predef timer configuration */
    const Gpt_PredefChannelConfigType *const predefChannelConfig;
} Gpt_ConfigType;

/** \} */

#ifdef __cplusplus
}
#endif

#endif /* GPT_TYPES_H */

/* End of file */
