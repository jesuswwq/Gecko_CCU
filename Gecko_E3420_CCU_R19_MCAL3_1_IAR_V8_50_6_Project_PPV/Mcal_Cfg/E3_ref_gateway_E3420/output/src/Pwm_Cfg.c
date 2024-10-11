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
 *  \file     Pwm_Cfg.h                                                                                 *
 *  \brief    This file contains generated pre compile configuration file for                           *
 *            PWM MCAL driver                                                                           *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date                 <th>Version                                                             *
 * <tr><td>2024-03-08 16:29:00  <td>1.0.0 R                                                             *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Std_Types.h"
#include "Pwm_Cfg.h"

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/

#if (STD_ON == PWM_NO_CACHEABLE_NEEDED)
#define PWM_START_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#else
#define PWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif /** #if (STD_ON == PWM_NO_CACHEABLE_NEEDED) */
#include "Pwm_MemMap.h"

/********************************************************************************************************
 *                                  Global Variable Declarations                                        *
 *******************************************************************************************************/

#if (STD_ON == PWM_NO_CACHEABLE_NEEDED)
#define PWM_STOP_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#else
#define PWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif /** #if (STD_ON == PWM_NO_CACHEABLE_NEEDED) */
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CONST_UNSPECIFIED
#include "Pwm_MemMap.h"

/********************************************************************************************************
 *                                  Private Constant Definitions                                        *
 *******************************************************************************************************/
/** \brief  PWM channel group configure information */
static const Pwm_ChannelGroupType Pwm_ChannelGroup[4] =
{
    {
        {
            {
                0U,
                PWM_CNT_G0,
                (boolean)FALSE,
                {
                    {
                        0x2000U, PWM_HIGH, PWM_LOW, /* duty polarity idlestatus */
                    },
                    {
                        0U, PWM_LOW, PWM_LOW, /* SubChannel not used, fill with empty data. */
                    },
                },
                {
                    (boolean)FALSE,
                    0U,
                    0U, /*unit is word*/
                    NULL_PTR,
                },/* EnableDMA FIFOWml TotalNum DMABufferAddr*/
            },
            {
                1U,
                PWM_CNT_G1,
                (boolean)TRUE,
                {
                    {
                        0x4000U, PWM_HIGH, PWM_LOW, /* duty polarity idlestatus */
                    },
                    {
                        0x4000U, PWM_HIGH, PWM_LOW, /* duty polarity idlestatus */
                    },
                },
                {
                    (boolean)FALSE,
                    0U,
                    0U, /*unit is word*/
                    NULL_PTR,
                },/* EnableDMA FIFOWml TotalNum DMABufferAddr*/
            },
            {
                2U,
                PWM_CNT_G0,
                (boolean)TRUE,
                {
                    {
                        0x0000U, PWM_HIGH, PWM_LOW, /* duty polarity idlestatus */
                    },
                    {
                        0x0000U, PWM_HIGH, PWM_LOW, /* duty polarity idlestatus */
                    },
                },
                {
                    (boolean)FALSE,
                    0U,
                    0U, /*unit is word*/
                    NULL_PTR,
                },/* EnableDMA FIFOWml TotalNum DMABufferAddr*/
            },
            {
                3U,
                PWM_CNT_G1,
                (boolean)TRUE,
                {
                    {
                        0x0000U, PWM_HIGH, PWM_LOW, /* duty polarity idlestatus */
                    },
                    {
                        0x0000U, PWM_HIGH, PWM_LOW, /* duty polarity idlestatus */
                    },
                },
                {
                    (boolean)FALSE,
                    0U,
                    0U, /*unit is word*/
                    NULL_PTR,
                },/* EnableDMA FIFOWml TotalNum DMABufferAddr*/
            },
        },
    },
    {
        {
            {
                0U,
                PWM_CNT_G0,
                (boolean)FALSE,
                {
                    {
                        0x0000U, PWM_HIGH, PWM_LOW, /* duty polarity idlestatus */
                    },
                    {
                        0U, PWM_LOW, PWM_LOW, /* SubChannel not used, fill with empty data. */
                    },
                },
                {
                    (boolean)FALSE,
                    0U,
                    0U, /*unit is word*/
                    NULL_PTR,
                },/* EnableDMA FIFOWml TotalNum DMABufferAddr*/
            },
            {
                1U,
                PWM_CNT_G1,
                (boolean)TRUE,
                {
                    {
                        0x0000U, PWM_HIGH, PWM_LOW, /* duty polarity idlestatus */
                    },
                    {
                        0x0000U, PWM_HIGH, PWM_LOW, /* duty polarity idlestatus */
                    },
                },
                {
                    (boolean)FALSE,
                    0U,
                    0U, /*unit is word*/
                    NULL_PTR,
                },/* EnableDMA FIFOWml TotalNum DMABufferAddr*/
            },
            {
                2U,
                PWM_CNT_G0,
                (boolean)FALSE,
                {
                    {
                        0x0000U, PWM_HIGH, PWM_LOW, /* duty polarity idlestatus */
                    },
                    {
                        0U, PWM_LOW, PWM_LOW, /* SubChannel not used, fill with empty data. */
                    },
                },
                {
                    (boolean)FALSE,
                    0U,
                    0U, /*unit is word*/
                    NULL_PTR,
                },/* EnableDMA FIFOWml TotalNum DMABufferAddr*/
            },
            {
                3U,
                PWM_CNT_G1,
                (boolean)FALSE,
                {
                    {
                        0x0000U, PWM_HIGH, PWM_LOW, /* duty polarity idlestatus */
                    },
                    {
                        0U, PWM_LOW, PWM_LOW, /* SubChannel not used, fill with empty data. */
                    },
                },
                {
                    (boolean)FALSE,
                    0U,
                    0U, /*unit is word*/
                    NULL_PTR,
                },/* EnableDMA FIFOWml TotalNum DMABufferAddr*/
            },
        },
    },
    {
        {
            {
                0U,
                PWM_CNT_G0,
                (boolean)FALSE,
                {
                    {
                        0x0000U, PWM_HIGH, PWM_LOW, /* duty polarity idlestatus */
                    },
                    {
                        0U, PWM_LOW, PWM_LOW, /* SubChannel not used, fill with empty data. */
                    },
                },
                {
                    (boolean)FALSE,
                    0U,
                    0U, /*unit is word*/
                    NULL_PTR,
                },/* EnableDMA FIFOWml TotalNum DMABufferAddr*/
            },
            {
                1U,
                PWM_CNT_G1,
                (boolean)TRUE,
                {
                    {
                        0x0000U, PWM_HIGH, PWM_LOW, /* duty polarity idlestatus */
                    },
                    {
                        0x0000U, PWM_HIGH, PWM_LOW, /* duty polarity idlestatus */
                    },
                },
                {
                    (boolean)FALSE,
                    0U,
                    0U, /*unit is word*/
                    NULL_PTR,
                },/* EnableDMA FIFOWml TotalNum DMABufferAddr*/
            },
            {
                2U,
                PWM_CNT_G0,
                (boolean)TRUE,
                {
                    {
                        0x0000U, PWM_HIGH, PWM_LOW, /* duty polarity idlestatus */
                    },
                    {
                        0x0000U, PWM_HIGH, PWM_LOW, /* duty polarity idlestatus */
                    },
                },
                {
                    (boolean)FALSE,
                    0U,
                    0U, /*unit is word*/
                    NULL_PTR,
                },/* EnableDMA FIFOWml TotalNum DMABufferAddr*/
            },
            {
                3U,
                PWM_CNT_G1,
                (boolean)TRUE,
                {
                    {
                        0x0000U, PWM_HIGH, PWM_LOW, /* duty polarity idlestatus */
                    },
                    {
                        0x0000U, PWM_HIGH, PWM_LOW, /* duty polarity idlestatus */
                    },
                },
                {
                    (boolean)FALSE,
                    0U,
                    0U, /*unit is word*/
                    NULL_PTR,
                },/* EnableDMA FIFOWml TotalNum DMABufferAddr*/
            },
        },
    },
    {
        {
            {
                0U,
                PWM_CNT_G0,
                (boolean)FALSE,
                {
                    {
                        0x0000U, PWM_HIGH, PWM_LOW, /* duty polarity idlestatus */
                    },
                    {
                        0U, PWM_LOW, PWM_LOW, /* SubChannel not used, fill with empty data. */
                    },
                },
                {
                    (boolean)FALSE,
                    0U,
                    0U, /*unit is word*/
                    NULL_PTR,
                },/* EnableDMA FIFOWml TotalNum DMABufferAddr*/
            },
            {
                1U,
                PWM_CNT_G1,
                (boolean)TRUE,
                {
                    {
                        0x0000U, PWM_HIGH, PWM_LOW, /* duty polarity idlestatus */
                    },
                    {
                        0x0000U, PWM_HIGH, PWM_LOW, /* duty polarity idlestatus */
                    },
                },
                {
                    (boolean)FALSE,
                    0U,
                    0U, /*unit is word*/
                    NULL_PTR,
                },/* EnableDMA FIFOWml TotalNum DMABufferAddr*/
            },
            {
                2U,
                PWM_CNT_G0,
                (boolean)TRUE,
                {
                    {
                        0x0000U, PWM_HIGH, PWM_LOW, /* duty polarity idlestatus */
                    },
                    {
                        0x0000U, PWM_HIGH, PWM_LOW, /* duty polarity idlestatus */
                    },
                },
                {
                    (boolean)FALSE,
                    0U,
                    0U, /*unit is word*/
                    NULL_PTR,
                },/* EnableDMA FIFOWml TotalNum DMABufferAddr*/
            },
            {
                3U,
                PWM_CNT_G1,
                (boolean)TRUE,
                {
                    {
                        0x0000U, PWM_HIGH, PWM_LOW, /* duty polarity idlestatus */
                    },
                    {
                        0x0000U, PWM_HIGH, PWM_LOW, /* duty polarity idlestatus */
                    },
                },
                {
                    (boolean)FALSE,
                    0U,
                    0U, /*unit is word*/
                    NULL_PTR,
                },/* EnableDMA FIFOWml TotalNum DMABufferAddr*/
            },
        },
    },
};

/** \brief  PWM hardware module configure information */
static const Pwm_HwModuleConfigType Pwm_HwModuleConfig[4] =
{
    {
        200000000U,   /* module clock */
        0x00U,                      /* clock source selcet [0:highfreq 1:Ahighfreq 2:tie 0 3:ext] */
        4U,   /* divider num */
    },
    {
        200000000U,   /* module clock */
        0x00U,                      /* clock source selcet [0:highfreq 1:Ahighfreq 2:tie 0 3:ext] */
        4U,   /* divider num */
    },
    {
        200000000U,   /* module clock */
        0x00U,                      /* clock source selcet [0:highfreq 1:Ahighfreq 2:tie 0 3:ext] */
        4U,   /* divider num */
    },
    {
        200000000U,   /* module clock */
        0x00U,                      /* clock source selcet [0:highfreq 1:Ahighfreq 2:tie 0 3:ext] */
        4U,   /* divider num */
    },
};

/** \brief  PWM module configure information */
static const Pwm_ModuleConfigType Pwm_ModuleConfig[4] =
{
    {
        EPWM1_MODULE_INDEX,
        (Pwm_ChannelType)4U,                    /* number of channels */
        (boolean)TRUE,
        {
            {
                /* Counter G0 */
                PWM_VARIABLE_PERIOD,
                10000000U,                                  /* tick ns */
            },
            {
                /* Counter G1 */
                PWM_VARIABLE_PERIOD,
                25000000U,                                  /* tick ns */
            },
            {
                /* Counter LCNT_A */
                PWM_FIXED_PERIOD,
                0U,                                  /* tick ns */
            },
            {
                /* Counter LCNT_B */
                PWM_FIXED_PERIOD,
                0U,                                  /* tick ns */
            },
            {
                /* Counter LCNT_C */
                PWM_FIXED_PERIOD,
                0U,                                  /* tick ns */
            },
            {
                /* Counter LCNT_D */
                PWM_FIXED_PERIOD,
                0U,                                  /* tick ns */
            },
        },
        NULL_PTR,
        &Pwm_ChannelGroup[0],
        (Pwm_CoreIdType)0U,/* Core ID: 0:sf 1:sx0 2:sx1 3:sp0 4:sp1 */
        {
            (boolean)FALSE,
            0U,
        },/*EnableEID EIDValue*/
    },
    {
        EPWM2_MODULE_INDEX,
        (Pwm_ChannelType)4U,                    /* number of channels */
        (boolean)TRUE,
        {
            {
                /* Counter G0 */
                PWM_VARIABLE_PERIOD,
                10000000U,                                  /* tick ns */
            },
            {
                /* Counter G1 */
                PWM_VARIABLE_PERIOD,
                1000000U,                                  /* tick ns */
            },
            {
                /* Counter LCNT_A */
                PWM_FIXED_PERIOD,
                0U,                                  /* tick ns */
            },
            {
                /* Counter LCNT_B */
                PWM_FIXED_PERIOD,
                0U,                                  /* tick ns */
            },
            {
                /* Counter LCNT_C */
                PWM_FIXED_PERIOD,
                0U,                                  /* tick ns */
            },
            {
                /* Counter LCNT_D */
                PWM_FIXED_PERIOD,
                0U,                                  /* tick ns */
            },
        },
        NULL_PTR,
        &Pwm_ChannelGroup[1],
        (Pwm_CoreIdType)0U,/* Core ID: 0:sf 1:sx0 2:sx1 3:sp0 4:sp1 */
        {
            (boolean)FALSE,
            0U,
        },/*EnableEID EIDValue*/
    },
    {
        EPWM3_MODULE_INDEX,
        (Pwm_ChannelType)4U,                    /* number of channels */
        (boolean)TRUE,
        {
            {
                /* Counter G0 */
                PWM_VARIABLE_PERIOD,
                10000000U,                                  /* tick ns */
            },
            {
                /* Counter G1 */
                PWM_VARIABLE_PERIOD,
                10000000U,                                  /* tick ns */
            },
            {
                /* Counter LCNT_A */
                PWM_FIXED_PERIOD,
                0U,                                  /* tick ns */
            },
            {
                /* Counter LCNT_B */
                PWM_FIXED_PERIOD,
                0U,                                  /* tick ns */
            },
            {
                /* Counter LCNT_C */
                PWM_FIXED_PERIOD,
                0U,                                  /* tick ns */
            },
            {
                /* Counter LCNT_D */
                PWM_FIXED_PERIOD,
                0U,                                  /* tick ns */
            },
        },
        NULL_PTR,
        &Pwm_ChannelGroup[2],
        (Pwm_CoreIdType)0U,/* Core ID: 0:sf 1:sx0 2:sx1 3:sp0 4:sp1 */
        {
            (boolean)FALSE,
            0U,
        },/*EnableEID EIDValue*/
    },
    {
        EPWM4_MODULE_INDEX,
        (Pwm_ChannelType)4U,                    /* number of channels */
        (boolean)TRUE,
        {
            {
                /* Counter G0 */
                PWM_VARIABLE_PERIOD,
                10000000U,                                  /* tick ns */
            },
            {
                /* Counter G1 */
                PWM_VARIABLE_PERIOD,
                10000000U,                                  /* tick ns */
            },
            {
                /* Counter LCNT_A */
                PWM_FIXED_PERIOD,
                0U,                                  /* tick ns */
            },
            {
                /* Counter LCNT_B */
                PWM_FIXED_PERIOD,
                0U,                                  /* tick ns */
            },
            {
                /* Counter LCNT_C */
                PWM_FIXED_PERIOD,
                0U,                                  /* tick ns */
            },
            {
                /* Counter LCNT_D */
                PWM_FIXED_PERIOD,
                0U,                                  /* tick ns */
            },
        },
        NULL_PTR,
        &Pwm_ChannelGroup[3],
        (Pwm_CoreIdType)0U,/* Core ID: 0:sf 1:sx0 2:sx1 3:sp0 4:sp1 */
        {
            (boolean)FALSE,
            0U,
        },/*EnableEID EIDValue*/
    },
};

/********************************************************************************************************
 *                                  Global Constant Declarations                                        *
 *******************************************************************************************************/
/** \brief  PWM global configure information */
const Pwm_ConfigType Pwm_Config =
{
    (Pwm_ModuleType)4U,
    Pwm_HwModuleConfig,
    Pwm_ModuleConfig
};

#define PWM_STOP_SEC_CONST_UNSPECIFIED
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif
