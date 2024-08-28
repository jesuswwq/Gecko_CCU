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
 *  \file     Icu_PBCfg.c                                                                               *
 *  \brief    This file contains interface header for ICU MCAL config.                                  *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date                 <th>Version                                                             *
 * <tr><td>2024-03-08 16:29:00      <td>1.0.0 R                                            *
 * </table>                                                                                             *
 *******************************************************************************************************/



#ifdef __cplusplus
extern "C" {
#endif

#include "Icu_Cfg.h"


extern void Icu_irq_test1(void);

extern void Icu_irq_test0(void);



#define ICU_START_SEC_CONST_UNSPECIFIED
/** Traceability       : SWSR_ICU_005 */
#include "Icu_MemMap.h"

static const Icu_HwChannelConfigType HwChannelConfig0 =
{
    .timerModule = (ICU_INDEX_ETIMER3),
    .timerPrescaler = (0),
    .timerClock = (ICU_SEL_HF_CLK),
    .timerChannel = (ICU_HW_CPT_A),
    .multiCptChanNum = 1

};
static const Icu_HwChannelConfigType HwChannelConfig1 =
{
    .timerModule = (ICU_INDEX_ETIMER3),
    .timerPrescaler = (0),
    .timerClock = (ICU_SEL_HF_CLK),
    .timerChannel = (ICU_HW_CPT_B),
    .multiCptChanNum = 1

};
static const Icu_HwChannelConfigType HwChannelConfig2 =
{
    .timerModule = (ICU_INDEX_ETIMER3),
    .timerPrescaler = (0),
    .timerClock = (ICU_SEL_HF_CLK),
    .timerChannel = (ICU_HW_CPT_C),
    .multiCptChanNum = 1

};
static const Icu_HwChannelConfigType HwChannelConfig3 =
{
    .timerModule = (ICU_INDEX_ETIMER3),
    .timerPrescaler = (0),
    .timerClock = (ICU_SEL_HF_CLK),
    .timerChannel = (ICU_HW_CPT_D),
    .multiCptChanNum = 1

};
static const Icu_HwChannelConfigType HwChannelConfig4 =
{
    .timerModule = (ICU_INDEX_ETIMER1),
    .timerPrescaler = (0),
    .timerClock = (ICU_SEL_HF_CLK),
    .timerChannel = (ICU_HW_CPT_A),
    .multiCptChanNum = 12

};



static const Icu_MeasureModeParamType Icu_MeasureModeParam0 =
{
    .Icu_SignalEdgeDetection  =
    {
        .sigNotifyFuncPtr = Icu_irq_test0,            
        .notifyEdgeDetDefault = TRUE        
    }
};
static const Icu_MeasureModeParamType Icu_MeasureModeParam1 =
{
    .Icu_TimestampMeasurement =
    {
        .tsBufferProperty = ICU_CIRCULAR_BUFFER,                    
        .tsNotifyFuncPtr  = Icu_irq_test1,            
        .notifyTsDefault = TRUE        
    }
};
static const Icu_MeasureModeParamType Icu_MeasureModeParam2 =
{
    /*Not need params, this is default value.*/
    .sigMeasureProperty = ICU_LOW_TIME
};
static const Icu_MeasureModeParamType Icu_MeasureModeParam3 =
{
    .sigMeasureProperty = ICU_DUTY_CYCLE
};
static const Icu_MultiCptChanType Icu_MultiCptChannelConfig4[12] =
{
    {
        .Icu_MultiCptEdgeCount =
        {
            .edgeCntMulStartEdge = ICU_BOTH_EDGES,
        },
        .icuMeasurementModeMul = ICU_MODE_EDGE_COUNTER
        
    }, /* 0 */
    {
        .Icu_MultiCptEdgeCount =
        {
            .edgeCntMulStartEdge = ICU_BOTH_EDGES,
        },
        .icuMeasurementModeMul = ICU_MODE_EDGE_COUNTER
        
    }, /* 1 */
    {
        .Icu_MultiCptEdgeCount =
        {
            .edgeCntMulStartEdge = ICU_FALLING_EDGE,
        },
        .icuMeasurementModeMul = ICU_MODE_EDGE_COUNTER
        
    }, /* 2 */
    {
        .Icu_MultiCptTimestamp =
        {
            .tsBufferMulProperty = ICU_CIRCULAR_BUFFER,
            .tsMulStartEdge = ICU_RISING_EDGE,
            
            .notifyTsMulDefault = FALSE,
            .notifyTsMulFuncPtr = NULL_PTR,            
        },
        .icuMeasurementModeMul = ICU_MODE_TIMESTAMP
        
    }, /* 3 */
    {
        .Icu_MultiCptTimestamp =
        {
            .tsBufferMulProperty = ICU_CIRCULAR_BUFFER,
            .tsMulStartEdge = ICU_RISING_EDGE,
            
            .notifyTsMulDefault = FALSE,
            .notifyTsMulFuncPtr = NULL_PTR,            
        },
        .icuMeasurementModeMul = ICU_MODE_TIMESTAMP
        
    }, /* 4 */
    {
        .Icu_MultiCptSigMeasure =
        {
            .sigMeasureMulProperty = ICU_DUTY_CYCLE,
            .sigMeasureMulStartEdge = ICU_BOTH_EDGES,
        },
        .icuMeasurementModeMul = ICU_MODE_SIGNAL_MEASUREMENT
        
    }, /* 5 */
    {
        .Icu_MultiCptEdgeCount =
        {
            .edgeCntMulStartEdge = ICU_FALLING_EDGE,
        },
        .icuMeasurementModeMul = ICU_MODE_EDGE_COUNTER
        
    }, /* 6 */
    {
        .Icu_MultiCptSigMeasure =
        {
            .sigMeasureMulProperty = ICU_DUTY_CYCLE,
            .sigMeasureMulStartEdge = ICU_RISING_EDGE,
        },
        .icuMeasurementModeMul = ICU_MODE_SIGNAL_MEASUREMENT
        
    }, /* 7 */
    {
        .Icu_MultiCptEdgeCount =
        {
            .edgeCntMulStartEdge = ICU_RISING_EDGE,
        },
        .icuMeasurementModeMul = ICU_MODE_EDGE_COUNTER
        
    }, /* 8 */
    {
        .Icu_MultiCptSigMeasure =
        {
            .sigMeasureMulProperty = ICU_DUTY_CYCLE,
            .sigMeasureMulStartEdge = ICU_RISING_EDGE,
        },
        .icuMeasurementModeMul = ICU_MODE_SIGNAL_MEASUREMENT
        
    }, /* 9 */
    {
        .Icu_MultiCptEdgeCount =
        {
            .edgeCntMulStartEdge = ICU_RISING_EDGE,
        },
        .icuMeasurementModeMul = ICU_MODE_EDGE_COUNTER
        
    }, /* 10 */
    {
        .Icu_MultiCptTimestamp =
        {
            .tsBufferMulProperty = ICU_CIRCULAR_BUFFER,
            .tsMulStartEdge = ICU_RISING_EDGE,
            
            .notifyTsMulDefault = FALSE,
            .notifyTsMulFuncPtr = NULL_PTR,            
        },
        .icuMeasurementModeMul = ICU_MODE_TIMESTAMP
        
    }, /* 11 */
};

static const Icu_ChannelConfigType Icu_ChannelConfigs[5] =
{
    {
        .icuChannel = (0u),
        .multiCaptureEnable = FALSE,
        .icuDefaultStartEdge = (ICU_RISING_EDGE),
        .icuMeasurementMode = (ICU_MODE_SIGNAL_EDGE_DETECT),
        .icuFilterLevel = (0),
        .measureParamPtr = &Icu_MeasureModeParam0,
        .icuHwChanCfgPtr = &HwChannelConfig0,
        .multiCptChanCfgPtr = NULL_PTR
    },
    {
        .icuChannel = (1u),
        .multiCaptureEnable = FALSE,
        .icuDefaultStartEdge = (ICU_RISING_EDGE),
        .icuMeasurementMode = (ICU_MODE_TIMESTAMP),
        .icuFilterLevel = (0),
        .measureParamPtr = &Icu_MeasureModeParam1,
        .icuHwChanCfgPtr = &HwChannelConfig1,
        .multiCptChanCfgPtr = NULL_PTR
    },
    {
        .icuChannel = (2u),
        .multiCaptureEnable = FALSE,
        .icuDefaultStartEdge = (ICU_RISING_EDGE),
        .icuMeasurementMode = (ICU_MODE_EDGE_COUNTER),
        .icuFilterLevel = (0),
        .measureParamPtr = &Icu_MeasureModeParam2,
        .icuHwChanCfgPtr = &HwChannelConfig2,
        .multiCptChanCfgPtr = NULL_PTR
    },
    {
        .icuChannel = (3u),
        .multiCaptureEnable = FALSE,
        .icuDefaultStartEdge = (ICU_RISING_EDGE),
        .icuMeasurementMode = (ICU_MODE_SIGNAL_MEASUREMENT),
        .icuFilterLevel = (0),
        .measureParamPtr = &Icu_MeasureModeParam3,
        .icuHwChanCfgPtr = &HwChannelConfig3,
        .multiCptChanCfgPtr = NULL_PTR
    },
    {
        .icuChannel = (4u),
        .multiCaptureEnable = TRUE,
        .icuDefaultStartEdge = (ICU_FALLING_EDGE),
        .icuMeasurementMode = (ICU_MODE_SIGNAL_MEASUREMENT),
        .icuFilterLevel = (0),
        .measureParamPtr = NULL_PTR,
        .icuHwChanCfgPtr = &HwChannelConfig4,
        .multiCptChanCfgPtr = Icu_MultiCptChannelConfig4
    },
};



/** \brief  ICU channel config */
const Icu_ConfigType Icu_ConfigSet =
{
    &Icu_ChannelConfigs,
};

#define ICU_STOP_SEC_CONST_UNSPECIFIED
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif
/* End of file */
