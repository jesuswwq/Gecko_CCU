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
 *  \file     Adc_Types.h                                                                               *
 *  \brief    This file contains adc types which will not be influenced by config file                  *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/29     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef ADC_TYPES_H
#define ADC_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include <Std_Types.h>
/**
 *  \addtogroup MCAL_ADC_CFG Adc Configuration.
 *
 * This files defines ADC MCAL configuration structures
 *  \{
 */

/** \brief  Type for Adc Notification.                                  */
typedef void (*Adc_NotificationFnPtrType)(void);

/** \brief  Type for numeric ID of a physical ADC channel.              */
/** Traceability    :   SWSR_ADC_034                                    */
typedef uint8 Adc_ChannelType;

/** \brief  Type for configuring the number of group conversions in
 *          streaming access mode.                                      */
/** Traceability    :   SWSR_ADC_044                                    */
typedef uint32 Adc_StreamNumSampleType;

/** \brief  Type for numeric ID of an ADC channel group.                */
/** Traceability    :   SWSR_ADC_035                                    */
typedef uint16 Adc_GroupType;

/** \brief  Type for numeric ID of an ADC Hw Unit.                      */
typedef uint8 Adc_HwUnitType;

/** \brief  Type for eading the converted values of a channel group.    */
/** Traceability    :   SWSR_ADC_036                                    */
typedef uint32 Adc_ValueGroupType;

/** \brief  Type for recording Adc unit base address.                   */
typedef volatile uint32 Adc_RegisterBaseType;

/** \brief  Type for recording Adc error id.                            */
typedef uint8 Adc_ErrorIdType;

/** \brief  Type for recording Adc related scr bit start bit address.   */
typedef uint16 Adc_ScrStartBitType;

/** \brief  Type for recording Adc unit clock divider.                  */
/** Traceability    :   SWSR_ADC_040                                    */
typedef uint8 Adc_PrescaleType;

/** \brief  Type for recording Adc initialization status.               */
typedef enum
{
    ADC_GLOBAL_STATE_UNINIT = 0U,
    ADC_GLOBAL_STATE_INIT
} Adc_GlobalStateType;

/** \brief  Type for recording Adc unit physical id.                    */
typedef enum
{
    ADC_INDEX_ADC1 = 0U,
    ADC_INDEX_ADC2 = 1U,
    ADC_INDEX_ADC3 = 2U,
} Adc_HwModuleIndexType;

/** \brief  Type for configuring the access mode to group
 *          conversion results.                                         */
/** Traceability    :   SWSR_ADC_037 SWSR_ADC_038 SWSR_ADC_046
 *                      SWSR_ADC_176                                    */
typedef enum
{
    ADC_ACCESS_MODE_SINGLE = 0U,
    ADC_ACCESS_MODE_STREAMING
} Adc_GroupAccessModeType;

/** \brief  Type for configuring the conversion mode of an ADC Channel
 *          group.                                                      */
/** Traceability    :   SWSR_ADC_005 SWSR_ADC_006 SWSR_ADC_043
 *                      SWSR_ADC_176                                    */
typedef enum
{
    ADC_CONV_MODE_ONESHOT = 0U,
    ADC_CONV_MODE_CONTINUOUS
} Adc_GroupConvModeType;

/** \brief  Type for configuring the streaming access mode buffer type. */
/** Traceability    :   SWSR_ADC_045 SWSR_ADC_176                       */
typedef enum
{
    ADC_STREAM_BUFFER_LINEAR = 0U,
    ADC_STREAM_BUFFER_CIRCULAR
} Adc_StreamBufferModeType;

/** \brief  Type for configuring the trigger source for an ADC Channel
 *          group.                                                      */
/** Traceability    :   SWSR_ADC_007 SWSR_ADC_008 SWSR_ADC_042          */
typedef enum
{
    ADC_TRIGG_SRC_HW = 0U,
    ADC_TRIGG_SRC_SW
} Adc_TriggerSourceType;

/** \brief  Type for current status of the conversion of the requested
 *          ADC Channel group.                                          */
/** Traceability    :   SWSR_ADC_041                                    */
typedef enum
{
    ADC_IDLE = 0U,
    ADC_BUSY,
    ADC_COMPLETED,
    ADC_STREAM_COMPLETED,
} Adc_StatusType;

/** \brief Type for recording group conversion values update.           */
/** Traceability    :   SWSR_ADC_013                                    */
typedef enum
{
    ADC_CONVERSION_NO_UPDATE = 0U,
    ADC_CONVERSION_UPDATE
} Adc_GroupValueUpdateType;

/** \brief  Type for record ADC group current conversion ends or not.   */
typedef enum
{
    ADC_NOT_YET_FINISHED_CONVERTED = 0U,
    ADC_ALREADY_FINISHED_CONVERTED
} Adc_GroupBusyType;

/** \brief  Type for indicates HwUnit ref voltage type.                 */
typedef enum
{
    ADC_INTERNAL_REF_3P3V = 0U,
    ADC_EXTERNAL_REF
} Adc_RefVoltageType;

/** \brief  Type for Adc group transfer conversion type.                */
typedef enum
{
    ADC_INTERRUPT_MODE = 0U,
    ADC_DMA_MODE
} Adc_GroupTransferType;

/** \brief  Type for Adc group use which dma channel.                   */
typedef enum
{
    ADC_DMA_CHNL0 = 0U,
    ADC_DMA_CHNL1,
    ADC_DMA_NO_USE
} Adc_GroupDmaIndexType;

/** \brief  Type for Adc unit use dma channel or not.                   */
typedef enum
{
    ADC_UNIT_DMA_UNUSED = 0U,
    ADC_UNIT_DMA_USED = 1U
} Adc_UnitDmaUsedType;

/** \brief  Type for Adc group use which rcht/rc.                       */
typedef enum
{
    ADC_RCHT_INDEX = 0U,
    ADC_RC0_INDEX = 1U,
    ADC_RC1_INDEX = 2U,
    ADC_RC2_INDEX = 3U,
    ADC_RC3_INDEX = 4U
} Adc_RcRchtIndexType;

/** \brief  Type for contains the configuration parameters for a
 *          physical channel.                                           */
typedef struct
{
    /* index of the logical channel */
    Adc_ChannelType logicalChannelId;
    /* index of the physical channel */
    Adc_ChannelType physicalChannelId;
    /* configure the sample time of channel conversions */
    uint8 sampleClock;
    /* configure the channel mux id */
    uint8 channelMuxId;
} Adc_ChannelConfigType;

/** \brief  Adc group configuration type.                               */
/** Traceability       :SWSR_ADC_001 SWSR_ADC_002 SWSR_ADC_003          */
typedef struct
{
    /* physical identifier for HwUnit */
    Adc_HwModuleIndexType belongUnitPhysicalId;
    /* logical identifier for HwUnit */
    Adc_HwUnitType belongUnitLogicalId;
    /* group rc/rcht index in Unit */
    Adc_RcRchtIndexType groupRcRchtIndex;
    /* Group notification pointer. */
    Adc_NotificationFnPtrType notificationPtr;
    /* Pointer to an object of the array of stream infos. */
    /* The referred element contains the stream info for this group. */
    /** Traceability       :SWSR_ADC_039          */
    Adc_ValueGroupType *bufferBasePtr;
    /* Access mode to group conversion results. */
    Adc_GroupAccessModeType groupAccessMode;
    /* Conversion mode of the group. */
    Adc_GroupConvModeType groupConvMode;
    /* Streaming access mode to buffer. */
    Adc_StreamBufferModeType strBufferMode;
    /* Trigger source for the group. */
    Adc_TriggerSourceType triggerSource;
    /* Number of samples that can be stored for each channel within */
    /* the stream.(I.e. length of the stream in conversion rounds.) */
    Adc_StreamNumSampleType samplingTime;
    /* group channel configuratuon */
    const Adc_ChannelConfigType *groupChannelCfgPtr;
    /* Number of channels of the group. */
    Adc_ChannelType channelCount;
    /* Transfer type (Interrupt/Dma) */
    Adc_GroupTransferType groupTransferType;
    /* group use which dma channel in the unit */
    Adc_GroupDmaIndexType groupDmaChannelIndex;
    /* ip special ops and params */
    void *priv;
} Adc_GroupConfigType;

/** \brief  Type for Adc unit configuration.                            */
/** Traceability       :SWSR_ADC_164                                    */
typedef struct
{
    /* physical identifier for HwUnit */
    Adc_HwModuleIndexType hwModulePhysicalId;
    /* logical identifier for HwUnit */
    Adc_HwUnitType hwModuleIndex;
    /* clock source divider */
    Adc_PrescaleType hwClockSrcDivider;
    /* the start groupId of current HW Unit */
    Adc_GroupType startGroupIdInUnit;
    /* group count in current Hw Unit */
    Adc_GroupType groupCountPerUnit;
    /* dma used situation */
    Adc_UnitDmaUsedType unitDmaUsed;
} Adc_HwUnitConfigType;

/** \brief  Type for Adc configuration parameters.                      */
/** Traceability       :SWSR_ADC_033                                    */
typedef struct
{
    /* pointer to Adc Unit configuration */
    Adc_HwUnitConfigType *adcUnitCfgPtr;
    /* pointer to Adc Group configuration */
    Adc_GroupConfigType *adcGroupCfgPtr;
    /* number of the array of HwUnit config */
    Adc_HwUnitType unitCount;
    /* total number of all unit groups */
    Adc_GroupType groupCountAllUnit;
    /* ref voltage selection for all units */
    Adc_RefVoltageType refVoltageSelect;
} Adc_ConfigType;
/** \} */

#ifdef __cplusplus
}
#endif

#endif /* ADC_TYPES_H */
/* End of file */
