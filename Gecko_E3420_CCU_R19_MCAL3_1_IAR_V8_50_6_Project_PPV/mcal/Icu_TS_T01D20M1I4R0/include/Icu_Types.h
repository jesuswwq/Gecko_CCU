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
 * \file     Icu_Types.h                                                                                *
 * \brief    This file contains the data type definitions used by the MCAL ICU driver                   *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/17     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifndef ICU_TYPES_H
#define ICU_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/

/* autosar standard types file */
#include "Std_Types.h"

/********************************************************************************************************
 *                                      Data types definition                                           *
 *******************************************************************************************************/

/**
 *  \addtogroup MCAL_ICU_CFG ICU Configuration.
 *  \{
 */

/**********************Autosar standard data types*****************************/

/** \brief  icu channel id type (low 8 bit : channel Id for single capture mode,
high 8 bit : channel id for multi capture mode  */
/**
 * Traceability : SWSR_ICU_013
 */
typedef uint16 Icu_ChannelType;

/** \brief  Timerstamp mode buffer index (buffer size data type : uint16)  */
/**
 * Traceability : SWSR_ICU_026
 */
typedef uint16 Icu_IndexType;

/** \brief  Edge counter number  */
/**
 * Traceability : SWSR_ICU_027
 */
typedef uint32 Icu_EdgeNumberType;

/** \brief  icu common value type  */
/**
 * Traceability : SWSR_ICU_024
 */
typedef uint32 Icu_ValueType;

/**********************Semidrive customised data types*************************/

/** \brief  edge detection mode notification function  */
typedef void(*Icu_SignalNotificationType)(void);

/** \brief  timestamp mode notification function  */
typedef void(*Icu_TimestampNotificationType)(void);


/********************************************************************************************************
 *                                      Enumerated data types                                           *
 *******************************************************************************************************/

/**********************Autosar standard enum types*****************************/


/**
* \brief    Input state of an ICU channel.
*/
/**
 * Traceability : SWSR_ICU_014
 */
typedef enum
{
    /** An activation edge has been detected  */
    ICU_ACTIVE = 0U,
    /** No activation edge has been detected  */
    ICU_IDLE
} Icu_InputStateType;

/**
* \brief    definition of the type of activation of an ICU channel.
*/
/**
 * Traceability : SWSR_ICU_023
 */
typedef enum
{
    /** An appropriate action shall be executed when a rising edge occurs  */
    ICU_RISING_EDGE  = 0U,
    /** An appropriate action shall be executed when a falling edge occurs  */
    ICU_FALLING_EDGE,
    /** An appropriate action shall be executed when a signal toggles  */
    ICU_BOTH_EDGES
} Icu_ActivationType;

/**
* \brief    definition of the measurement mode type.
*/
/**
 * Traceability : SWSR_ICU_028
 */
typedef enum
{
    /** Mode for detecting edges  */
    ICU_MODE_SIGNAL_EDGE_DETECT = 0U,
    /** Mode for measuring different times between configurable edges  */
    ICU_MODE_SIGNAL_MEASUREMENT,
    /** Mode for capturing timer values on configurable edges  */
    ICU_MODE_TIMESTAMP,
    /** Mode for counting edges on configurable  */
    ICU_MODE_EDGE_COUNTER
} Icu_MeasurementModeType;

/**
* \brief    definition of the measurement property type.
*/
/**
 * Traceability : SWSR_ICU_029
 */
typedef enum
{
    /**  Reading the elapsed Signal Low Time  */
    ICU_LOW_TIME = 0U,
    /**  Reading the elapsed Signal Hign Time  */
    ICU_HIGH_TIME,
    /**  Reading the elapsed Signal Period Time  */
    ICU_PERIOD_TIME,
    /**  Calculating the duty cycle  */
    ICU_DUTY_CYCLE
} Icu_SignalMeasurementPropertyType;

/**
* \brief    Definition of the timestamp measurement property type.
*/
/**
 * Traceability : SWSR_ICU_030
 */
typedef enum
{
    /**  Buffer will just be filled once  */
    ICU_LINEAR_BUFFER = 0U,
    /**  The driver can restarts at the beginning of the buffer  */
    ICU_CIRCULAR_BUFFER
} Icu_TimestampBufferType;


/**********************Semidrive customised enum types*************************/

/**
* \brief    hardware modules used in icu driver.
*/
typedef enum
{
    /**  The etimer1 modue  */
    ICU_INDEX_ETIMER1 = 0U,
    /**  The etimer2 modue  */
    ICU_INDEX_ETIMER2,
    /**  The etimer3 modue  */
    ICU_INDEX_ETIMER3,
    /**  The etimer4 modue  */
    ICU_INDEX_ETIMER4
} Icu_HwModule;

/**
* \brief    hardware channel used in icu driver.
*/
typedef enum
{
    /**  The etimer capture a channel  */
    ICU_HW_CPT_A  = 0U,
    /**  The etimer capture b channel  */
    ICU_HW_CPT_B,
    /**  The etimer capture c channel  */
    ICU_HW_CPT_C,
    /**  The etimer capture d channel  */
    ICU_HW_CPT_D
} Icu_HwChannel;

/**
* \brief    clock source used by hardware module.
*/
typedef enum
{
    /**  High frequency clock  */
    ICU_SEL_HF_CLK = 0U,
    /**  Alternative high frequency clock  */
    ICU_SEL_AHF_CLK,
    /**  External clock  */
    ICU_SEL_EXT_CLK,
    /**  Low power clock  */
    ICU_SEL_LP_CLK
} Icu_ClockRefType;

/**
* \brief    edge change types in multi capture mode.
*/
typedef enum
{
    /**  A rising edge occurs in multi capture mode */
    ICU_MULTI_CPT_RISING_EDGE = 0U,
    /**  A falling edge occurs in multi capture mode */
    ICU_MULTI_CPT_FALLING_EDGE
} Icu_MultiCptEdgeChangeType;

/**
* \brief    icu driver initial status.
*/
typedef enum
{
    /** The driver has been initilized */
    ICU_STATUS_UNINIT = 0U,
    /** The driver not initilized yet */
    ICU_STATUS_INITED
} Icu_InitialStateType;


/********************************************************************************************************
 *                                          Struct data types                                           *
 *******************************************************************************************************/

/*********************Semidrive customised struct types************************/

/**
* \brief    parameter settings for icu measurement mode.
*/
typedef struct
{
    struct
    {
        /**  notification function point to edge detection mode */
        Icu_SignalNotificationType sigNotifyFuncPtr;
        /**  whether to call function in edge detection mode */
        boolean notifyEdgeDetDefault;
    } Icu_SignalEdgeDetection;
    /**  sub-mode in signal measurement mode */
    Icu_SignalMeasurementPropertyType sigMeasureProperty;
    struct
    {
        /**  buffer-mode in timestamp mode */
        Icu_TimestampBufferType tsBufferProperty;
        /**  whether to call function in timestamp mode */
        boolean notifyTsDefault;
        /**  notification function point to timestamp mode */
        Icu_TimestampNotificationType tsNotifyFuncPtr;
    } Icu_TimestampMeasurement;
} Icu_MeasureModeParamType;

/**
* \brief    hardware channel information
*/
typedef struct
{
    /**  etimer module select */
    Icu_HwModule timerModule;
    /**  etimer channel select */
    Icu_HwChannel timerChannel;
    /**  etimer frequency division value */
    uint16 timerPrescaler;
    /**  etimer clock source select */
    Icu_ClockRefType timerClock;
    /**  multi capture channel number */
    uint8 multiCptChanNum;
} Icu_HwChannelConfigType;

/**
* \brief    mode select and parameter settings for multi capture channel
*/
typedef struct
{
    struct
    {
        /**  default activation for edge count mode */
        Icu_ActivationType edgeCntMulStartEdge;
    } Icu_MultiCptEdgeCount;
    struct
    {
        /**  buffer mode for timestamp mode */
        Icu_TimestampBufferType tsBufferMulProperty;
        /**  default activation for timestamp mode */
        Icu_ActivationType tsMulStartEdge;
        /**  whether to call function in timestamp mode */
        boolean notifyTsMulDefault;
        /**  notification function point to timestamp mode */
        Icu_TimestampNotificationType notifyTsMulFuncPtr;
    } Icu_MultiCptTimestamp;
    struct
    {
        /**  sub-mode in signal measurement mode */
        Icu_SignalMeasurementPropertyType sigMeasureMulProperty;
        /**  default activation for signal measurement mode */
        Icu_ActivationType sigMeasureMulStartEdge;
    } Icu_MultiCptSigMeasure;
    /**  measurement mode select */
    Icu_MeasurementModeType icuMeasurementModeMul;
} Icu_MultiCptChanType;

/**
* \brief    icu channel configuration
*/
typedef struct
{
    /**  icu channel index */
    Icu_IndexType icuChannel;
    /**  support multi capture mode or not */
    boolean multiCaptureEnable;
    /**  default activation for the channel */
    Icu_ActivationType icuDefaultStartEdge;
    /**  measurement mode select */
    Icu_MeasurementModeType icuMeasurementMode;
    /**  hardware filter level */
    uint16 icuFilterLevel;
    /**  point to the parameter configuration to the measurement mode */
    const Icu_MeasureModeParamType* measureParamPtr;
    /**  point to the hardware channel config */
    const Icu_HwChannelConfigType* icuHwChanCfgPtr;
    /**  point to the multi capture channel config */
    const Icu_MultiCptChanType* multiCptChanCfgPtr;
} Icu_ChannelConfigType;

/***************** *****Autosar standard struct types**** *********************/

/**
* \brief    icu initialization channel configuration
*/
/**
 * Traceability : SWSR_ICU_015
 */
typedef struct
{
    /**  point to the icu channnels configuration */
    const Icu_ChannelConfigType (*chanConfigPtr)[];
} Icu_ConfigType;

/**
* \brief    icu dutycycle and period information
*/
/**
 * Traceability : SWSR_ICU_025
 */
typedef struct
{
    /**  dutycyle time */
    Icu_ValueType ActiveTime;
    /**  period time */
    Icu_ValueType PeriodTime;
} Icu_DutyCycleType;

/** \} */
/* end of MCAL_ICU_CFG ICU Configuration. */

#ifdef __cplusplus
}
#endif

#endif /* ICU_TYPES_H */
/* End of file */
