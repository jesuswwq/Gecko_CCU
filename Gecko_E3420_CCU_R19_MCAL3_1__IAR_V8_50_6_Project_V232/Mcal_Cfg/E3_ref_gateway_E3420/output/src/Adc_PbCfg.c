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
 * \file     Adc_PbCfg.c                                                                                *
 * \brief    AUTOSAR 4.3.1 MCAL adc config generate file                                                *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/30     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Adc.h"
#include "Adc_Cfg.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/


/*******************************************************************************
**                        Internal Config Data                                **
*******************************************************************************/

#define ADC_START_SEC_CONST_UNSPECIFIED
#include "Adc_MemMap.h"
/* Config list for ADC channels */
static const Adc_ChannelConfigType ADC2_Group0ChannelConfig[3] = {
/** Traceability       : SWSR_ADC_001 SWSR_ADC_003 */
  {
    0U,     /* Index of the logical channel */
    8U,     /* Index of the physical channel */
    5U,     /* Sample time of channel */
    3U,     /* Channel mux id */
  },
  {
    1U,     /* Index of the logical channel */
    10U,     /* Index of the physical channel */
    5U,     /* Sample time of channel */
    5U,     /* Channel mux id */
  },
  {
    2U,     /* Index of the logical channel */
    8U,     /* Index of the physical channel */
    5U,     /* Sample time of channel */
    2U,     /* Channel mux id */
  },
};

static const Adc_ChannelConfigType ADC2_Group1ChannelConfig[10] = {
/** Traceability       : SWSR_ADC_001 SWSR_ADC_003 */
  {
    0U,     /* Index of the logical channel */
    1U,     /* Index of the physical channel */
    5U,     /* Sample time of channel */
    0U,     /* Channel mux id */
  },
  {
    1U,     /* Index of the logical channel */
    12U,     /* Index of the physical channel */
    5U,     /* Sample time of channel */
    0U,     /* Channel mux id */
  },
  {
    2U,     /* Index of the logical channel */
    11U,     /* Index of the physical channel */
    5U,     /* Sample time of channel */
    4U,     /* Channel mux id */
  },
  {
    3U,     /* Index of the logical channel */
    11U,     /* Index of the physical channel */
    5U,     /* Sample time of channel */
    2U,     /* Channel mux id */
  },
  {
    4U,     /* Index of the logical channel */
    12U,     /* Index of the physical channel */
    5U,     /* Sample time of channel */
    1U,     /* Channel mux id */
  },
  {
    5U,     /* Index of the logical channel */
    10U,     /* Index of the physical channel */
    5U,     /* Sample time of channel */
    4U,     /* Channel mux id */
  },
  {
    6U,     /* Index of the logical channel */
    10U,     /* Index of the physical channel */
    5U,     /* Sample time of channel */
    2U,     /* Channel mux id */
  },
  {
    7U,     /* Index of the logical channel */
    11U,     /* Index of the physical channel */
    5U,     /* Sample time of channel */
    0U,     /* Channel mux id */
  },
  {
    8U,     /* Index of the logical channel */
    10U,     /* Index of the physical channel */
    5U,     /* Sample time of channel */
    0U,     /* Channel mux id */
  },
  {
    9U,     /* Index of the logical channel */
    11U,     /* Index of the physical channel */
    5U,     /* Sample time of channel */
    5U,     /* Channel mux id */
  },
};

static const Adc_ChannelConfigType ADC2_Group2ChannelConfig[5] = {
/** Traceability       : SWSR_ADC_001 SWSR_ADC_003 */
  {
    0U,     /* Index of the logical channel */
    12U,     /* Index of the physical channel */
    5U,     /* Sample time of channel */
    6U,     /* Channel mux id */
  },
  {
    1U,     /* Index of the logical channel */
    8U,     /* Index of the physical channel */
    5U,     /* Sample time of channel */
    7U,     /* Channel mux id */
  },
  {
    2U,     /* Index of the logical channel */
    9U,     /* Index of the physical channel */
    5U,     /* Sample time of channel */
    2U,     /* Channel mux id */
  },
  {
    3U,     /* Index of the logical channel */
    12U,     /* Index of the physical channel */
    5U,     /* Sample time of channel */
    7U,     /* Channel mux id */
  },
  {
    4U,     /* Index of the logical channel */
    0U,     /* Index of the physical channel */
    5U,     /* Sample time of channel */
    2U,     /* Channel mux id */
  },
};

#define ADC_STOP_SEC_CONST_UNSPECIFIED
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_INIT_UNSPECIFIED
#include "Adc_MemMap.h"
/* Config list for ADC groups */

static Adc_GroupConfigType Adc_GroupConfigPtr[3] = {
  {
    ADC_INDEX_ADC2, /* physical identifier for HwUnit */
    0U, /* Adc_HwUnitIndex */
        ADC_RC0_INDEX, /* unit dose not exist hardware trigger group */
/** Traceability       : SWSR_ADC_160 */
	NULL_PTR,	/* NotificationPtr - no notification configured */
    NULL_PTR, /* BufferBasePtr */
    ADC_ACCESS_MODE_STREAMING,	/* GroupAccessMode */
    ADC_CONV_MODE_CONTINUOUS,	/* GroupConvMode */
    ADC_STREAM_BUFFER_LINEAR,	/* StrBufferMode */
    ADC_TRIGG_SRC_SW,	/* TriggerSource */
    1U,    /* LenOfStreamNumSamples */
    ADC2_Group0ChannelConfig, /* Pointer to Channel config */
          3U, /* Number of channels in the group. */
    ADC_INTERRUPT_MODE, /* TransferType  */
      ADC_DMA_NO_USE,
    NULL_PTR,
  },
  {
    ADC_INDEX_ADC2, /* physical identifier for HwUnit */
    0U, /* Adc_HwUnitIndex */
        ADC_RC1_INDEX, /* unit dose not exist hardware trigger group */
/** Traceability       : SWSR_ADC_160 */
	NULL_PTR,	/* NotificationPtr - no notification configured */
    NULL_PTR, /* BufferBasePtr */
    ADC_ACCESS_MODE_STREAMING,	/* GroupAccessMode */
    ADC_CONV_MODE_CONTINUOUS,	/* GroupConvMode */
    ADC_STREAM_BUFFER_LINEAR,	/* StrBufferMode */
    ADC_TRIGG_SRC_SW,	/* TriggerSource */
    1U,    /* LenOfStreamNumSamples */
    ADC2_Group1ChannelConfig, /* Pointer to Channel config */
          10U, /* Number of channels in the group. */
    ADC_INTERRUPT_MODE, /* TransferType  */
      ADC_DMA_NO_USE,
    NULL_PTR,
  },
  {
    ADC_INDEX_ADC2, /* physical identifier for HwUnit */
    0U, /* Adc_HwUnitIndex */
        ADC_RC2_INDEX, /* unit dose not exist hardware trigger group */
/** Traceability       : SWSR_ADC_160 */
	NULL_PTR,	/* NotificationPtr - no notification configured */
    NULL_PTR, /* BufferBasePtr */
    ADC_ACCESS_MODE_STREAMING,	/* GroupAccessMode */
    ADC_CONV_MODE_CONTINUOUS,	/* GroupConvMode */
    ADC_STREAM_BUFFER_LINEAR,	/* StrBufferMode */
    ADC_TRIGG_SRC_SW,	/* TriggerSource */
    1U,    /* LenOfStreamNumSamples */
    ADC2_Group2ChannelConfig, /* Pointer to Channel config */
          5U, /* Number of channels in the group. */
    ADC_INTERRUPT_MODE, /* TransferType  */
      ADC_DMA_NO_USE,
    NULL_PTR,
  },
};



/* Config list for HwUnits (AdcConfigSet_0) */
static Adc_HwUnitConfigType Adc_UnitConfigPtr[1] = {  {
    ADC_INDEX_ADC2, /* physical identifier for HwUnit */
    0U, /* logical identifier for HwUnit */
	3U,  /* Adc_ClockSrc Divider */
    0U, /* start group id of current Hw Unit */
    3U, /* group count in current Hw Unit */
      ADC_UNIT_DMA_UNUSED,
  },
};
#define ADC_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Adc_MemMap.h"

#define ADC_START_SEC_CONST_UNSPECIFIED
#include "Adc_MemMap.h"
CONST (Adc_ConfigType, ADC_CONST) Adc_Config = {
    Adc_UnitConfigPtr,
    Adc_GroupConfigPtr,
    1U,	/* Number of HwUnitConfigs */
    3U, /* All Groups Count*/
    ADC_INTERNAL_REF_3P3V
};
#define ADC_STOP_SEC_CONST_UNSPECIFIED
#include "Adc_MemMap.h"

#ifdef __cplusplus
  }
#endif

