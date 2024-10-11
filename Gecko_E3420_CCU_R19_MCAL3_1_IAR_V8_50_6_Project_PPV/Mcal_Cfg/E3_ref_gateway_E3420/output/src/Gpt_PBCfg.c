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
 *  \file     Gpt_PBCfg.c                                                                               *
 *  \brief    This file contains interface header for GPT MCAL config.                                  *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date                 <th>Version                                                             *
 * <tr><td>2024-03-08 16:29:00      <td>1.0.0 R                                            *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Gpt_Cfg.h"

extern void Gpt4_G0_IRQ(void);
extern void GPT2_G1_IRQ(void);
extern void GPT1_G1_IRQ(void);
extern void GPT4_G1_IRQ(void);
extern void GPT5_G0_IRQ(void);
extern void GPT6_G1_IRQ(void);
extern void GPT5_G1_IRQ(void);
extern void GPT6_G0_IRQ(void);
extern void GPT1_G0_IRQ(void);

#define GPT_START_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"
#if(STD_ON == GPT_PREDEFTIMER_FUNCTIONALITY_API)
static const Gpt_PredefChannelConfigType Gpt_InitPredeftimer = {
    GPT_INDEX_BTM2,
    3,
};
#endif /*GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON*/

static const Gpt_ChannelConfigType Gpt_InitChannelPB[9] =
{
    {
        .notification = &Gpt4_G0_IRQ, /* Channel notification */
        .channelTickValueMax = (Gpt_ValueType)(4294967295U), /* Maximum ticks value*/
        .channelMode = (Gpt_ChannelModeType)(GPT_CH_MODE_CONTINUOUS), /* Timer mode:continous/one-shot */
        .hwChannelConfig =
        {
            .timerHwModule = (Gpt_HwModule)(GPT_INDEX_BTM4), /* hardware module ID */
            .hwChannel = (Gpt_HwChannel)(GPT_HW_TIMER_G0), /* GPT physical channel no. */
            .prescaler = (uint16)(149), /* Prescaler value */
            .notificationEnabled = (TRUE),
            .clockRef = (Gpt_ClockRefType)(GPT_CLOCKREF_APB)
        },
        .gptCoreId = (uint8)0X0 /* coreid 0:sf 1:sx0 2:sx1 3:sp0 4:sp1*/
    },
    {
        .notification = &GPT2_G1_IRQ, /* Channel notification */
        .channelTickValueMax = (Gpt_ValueType)(4294967295U), /* Maximum ticks value*/
        .channelMode = (Gpt_ChannelModeType)(GPT_CH_MODE_CONTINUOUS), /* Timer mode:continous/one-shot */
        .hwChannelConfig =
        {
            .timerHwModule = (Gpt_HwModule)(GPT_INDEX_BTM2), /* hardware module ID */
            .hwChannel = (Gpt_HwChannel)(GPT_HW_TIMER_G1), /* GPT physical channel no. */
            .prescaler = (uint16)(23), /* Prescaler value */
            .notificationEnabled = (TRUE),
            .clockRef = (Gpt_ClockRefType)(GPT_CLOCKREF_XTAL)
        },
        .gptCoreId = (uint8)0X0 /* coreid 0:sf 1:sx0 2:sx1 3:sp0 4:sp1*/
    },
    {
        .notification = &GPT1_G1_IRQ, /* Channel notification */
        .channelTickValueMax = (Gpt_ValueType)(4294967295U), /* Maximum ticks value*/
        .channelMode = (Gpt_ChannelModeType)(GPT_CH_MODE_CONTINUOUS), /* Timer mode:continous/one-shot */
        .hwChannelConfig =
        {
            .timerHwModule = (Gpt_HwModule)(GPT_INDEX_BTM1), /* hardware module ID */
            .hwChannel = (Gpt_HwChannel)(GPT_HW_TIMER_G1), /* GPT physical channel no. */
            .prescaler = (uint16)(23), /* Prescaler value */
            .notificationEnabled = (TRUE),
            .clockRef = (Gpt_ClockRefType)(GPT_CLOCKREF_XTAL)
        },
        .gptCoreId = (uint8)0X0 /* coreid 0:sf 1:sx0 2:sx1 3:sp0 4:sp1*/
    },
    {
        .notification = &GPT4_G1_IRQ, /* Channel notification */
        .channelTickValueMax = (Gpt_ValueType)(4294967295U), /* Maximum ticks value*/
        .channelMode = (Gpt_ChannelModeType)(GPT_CH_MODE_CONTINUOUS), /* Timer mode:continous/one-shot */
        .hwChannelConfig =
        {
            .timerHwModule = (Gpt_HwModule)(GPT_INDEX_BTM4), /* hardware module ID */
            .hwChannel = (Gpt_HwChannel)(GPT_HW_TIMER_G1), /* GPT physical channel no. */
            .prescaler = (uint16)(23), /* Prescaler value */
            .notificationEnabled = (TRUE),
            .clockRef = (Gpt_ClockRefType)(GPT_CLOCKREF_XTAL)
        },
        .gptCoreId = (uint8)0X0 /* coreid 0:sf 1:sx0 2:sx1 3:sp0 4:sp1*/
    },
    {
        .notification = &GPT5_G0_IRQ, /* Channel notification */
        .channelTickValueMax = (Gpt_ValueType)(4294967295U), /* Maximum ticks value*/
        .channelMode = (Gpt_ChannelModeType)(GPT_CH_MODE_CONTINUOUS), /* Timer mode:continous/one-shot */
        .hwChannelConfig =
        {
            .timerHwModule = (Gpt_HwModule)(GPT_INDEX_BTM5), /* hardware module ID */
            .hwChannel = (Gpt_HwChannel)(GPT_HW_TIMER_G0), /* GPT physical channel no. */
            .prescaler = (uint16)(149), /* Prescaler value */
            .notificationEnabled = (TRUE),
            .clockRef = (Gpt_ClockRefType)(GPT_CLOCKREF_APB)
        },
        .gptCoreId = (uint8)0X0 /* coreid 0:sf 1:sx0 2:sx1 3:sp0 4:sp1*/
    },
    {
        .notification = &GPT6_G1_IRQ, /* Channel notification */
        .channelTickValueMax = (Gpt_ValueType)(4294967295U), /* Maximum ticks value*/
        .channelMode = (Gpt_ChannelModeType)(GPT_CH_MODE_CONTINUOUS), /* Timer mode:continous/one-shot */
        .hwChannelConfig =
        {
            .timerHwModule = (Gpt_HwModule)(GPT_INDEX_BTM6), /* hardware module ID */
            .hwChannel = (Gpt_HwChannel)(GPT_HW_TIMER_G1), /* GPT physical channel no. */
            .prescaler = (uint16)(23), /* Prescaler value */
            .notificationEnabled = (TRUE),
            .clockRef = (Gpt_ClockRefType)(GPT_CLOCKREF_XTAL)
        },
        .gptCoreId = (uint8)0X0 /* coreid 0:sf 1:sx0 2:sx1 3:sp0 4:sp1*/
    },
    {
        .notification = &GPT5_G1_IRQ, /* Channel notification */
        .channelTickValueMax = (Gpt_ValueType)(4294967295U), /* Maximum ticks value*/
        .channelMode = (Gpt_ChannelModeType)(GPT_CH_MODE_CONTINUOUS), /* Timer mode:continous/one-shot */
        .hwChannelConfig =
        {
            .timerHwModule = (Gpt_HwModule)(GPT_INDEX_BTM5), /* hardware module ID */
            .hwChannel = (Gpt_HwChannel)(GPT_HW_TIMER_G1), /* GPT physical channel no. */
            .prescaler = (uint16)(23), /* Prescaler value */
            .notificationEnabled = (TRUE),
            .clockRef = (Gpt_ClockRefType)(GPT_CLOCKREF_XTAL)
        },
        .gptCoreId = (uint8)0X0 /* coreid 0:sf 1:sx0 2:sx1 3:sp0 4:sp1*/
    },
    {
        .notification = &GPT6_G0_IRQ, /* Channel notification */
        .channelTickValueMax = (Gpt_ValueType)(4294967295U), /* Maximum ticks value*/
        .channelMode = (Gpt_ChannelModeType)(GPT_CH_MODE_CONTINUOUS), /* Timer mode:continous/one-shot */
        .hwChannelConfig =
        {
            .timerHwModule = (Gpt_HwModule)(GPT_INDEX_BTM6), /* hardware module ID */
            .hwChannel = (Gpt_HwChannel)(GPT_HW_TIMER_G0), /* GPT physical channel no. */
            .prescaler = (uint16)(149), /* Prescaler value */
            .notificationEnabled = (TRUE),
            .clockRef = (Gpt_ClockRefType)(GPT_CLOCKREF_APB)
        },
        .gptCoreId = (uint8)0X0 /* coreid 0:sf 1:sx0 2:sx1 3:sp0 4:sp1*/
    },
    {
        .notification = &GPT1_G0_IRQ, /* Channel notification */
        .channelTickValueMax = (Gpt_ValueType)(4294967295U), /* Maximum ticks value*/
        .channelMode = (Gpt_ChannelModeType)(GPT_CH_MODE_CONTINUOUS), /* Timer mode:continous/one-shot */
        .hwChannelConfig =
        {
            .timerHwModule = (Gpt_HwModule)(GPT_INDEX_BTM1), /* hardware module ID */
            .hwChannel = (Gpt_HwChannel)(GPT_HW_TIMER_G0), /* GPT physical channel no. */
            .prescaler = (uint16)(149), /* Prescaler value */
            .notificationEnabled = (TRUE),
            .clockRef = (Gpt_ClockRefType)(GPT_CLOCKREF_APB)
        },
        .gptCoreId = (uint8)0X0 /* coreid 0:sf 1:sx0 2:sx1 3:sp0 4:sp1*/
    },
};



const Gpt_ConfigType  GptChannelConfigSet =
{
    .channelCount = (Gpt_ChannelType)9U,
    .channelConfig = &Gpt_InitChannelPB,
#if(STD_ON == GPT_PREDEFTIMER_FUNCTIONALITY_API)
    .predefChannelConfig = &Gpt_InitPredeftimer,
#endif /*GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON*/
};

#define GPT_STOP_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"

#ifdef __cplusplus
}
#endif

/* End of file */
