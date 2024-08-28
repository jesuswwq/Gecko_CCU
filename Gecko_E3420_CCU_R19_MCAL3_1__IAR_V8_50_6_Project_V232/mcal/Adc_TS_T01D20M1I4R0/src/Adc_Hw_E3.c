/** **************************************************************************************
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
 * an 'AS IS' basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.
 *
 *****************************************************************************************/
/** **************************************************************************************
 * \file     Adc_Hw_E3.c
 * \brief    AUTOSAR 4.3.1 MCAL Adc Ip level driver
 *
 * <table>
 * <tr><th>Date           <th>Version
 * <tr><td>2023/07/28     <td>1.0.0
 * </table>
 *****************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/*****************************************************************************************
 *                       Include header files
 *****************************************************************************************/
#include "Adc_Hw_E3.h"
#include "Adc.h"
#include "Adc_Types.h"
#include "Adc_ConfigTypes.h"
#include "Adc_Cfg.h"
/** Traceability    :   SWSR_ADC_032    */
#include "Std_Types.h"
#include "Adc_reg.h"
#include "SchM_Adc.h"
#include "RegHelper.h"
#include "Adc_Fault.h"

#if (ADC_DMA_SUPPORTED == STD_ON)
#include "Dma.h"
#include "Mcal.h"
#endif /* #if (ADC_DMA_SUPPORTED == STD_ON) */

/*****************************************************************************************
 *                           Private Variable Definitions
 *****************************************************************************************/

#if (ADC_DMA_SUPPORTED == STD_ON) /* AdcEnableDmaTransferMode enabled */
#if (ADC_NO_CACHEABLE_NEEDED == STD_ON)
#define ADC_START_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#else
#define ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif /** #if (ADC_NO_CACHEABLE_NEEDED == STD_ON) */
#include "Adc_MemMap.h"
static VAR_ALIGN(Adc_ValueGroupType
                 Adc_DmaBufAdcUnit[ADC_MODULE_NUMBER * ADC_DMA_PER_UNIT_CHNL_CNT]
                 [ADC_DMA_PER_GROUP_MAX_VALUE_CNT],
                 ADC_CACHE_LINE);
#if (ADC_NO_CACHEABLE_NEEDED == STD_ON)
#define ADC_STOP_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#else
#define ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif /** #if (ADC_NO_CACHEABLE_NEEDED == STD_ON) */
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Adc_MemMap.h"
static boolean Adc_DmaTransStatus[ADC_MODULE_NUMBER][ADC_DMA_PER_UNIT_CHNL_CNT];
#define ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Adc_MemMap.h"

#define ADC_START_SEC_CONST_UNSPECIFIED
#include "Adc_MemMap.h"
const Dma_PeripheralIdType Adc_DmaUnitTable[ADC_MODULE_NUMBER] = {DMA_ADC1, DMA_ADC2, DMA_ADC3};
const Dma_SubIdType Adc_DmaSubIdTable[ADC_DMA_PER_UNIT_CHNL_CNT] = {DMA_ADC_FIFO0, DMA_ADC_FIFO1};
#define ADC_STOP_SEC_CONST_UNSPECIFIED
#include "Adc_MemMap.h"
#endif /* AdcEnableDmaTransferMode enabled */

#define ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Adc_MemMap.h"
/* internal buffer for recording adc base address */
static Adc_RegisterBaseType Adc_BaseAddress[ADC_MODULE_NUMBER];
#define ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Adc_MemMap.h"

#ifndef SEMIDRIVE_E3_LITE_SERIES
#if (ADC_OVERVOLTAGE_DETECT == STD_ON)
#define ADC_START_SEC_CONST_UNSPECIFIED
#include "Adc_MemMap.h"
/* adc1 src bit start address */
static const uint16 Adc1_ChnlScrAddress[ADC_CHNL_MAX][ADC_CHNL_MUX_MAX] =
{
    /*CH0*/
    {
        ADC_APD_A_B0, ADC_APD_A_B1, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE
    },
    /*CH1*/
    {
        ADC_APD_A_B2, ADC_APD_A_B3, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE
    },
    /*CH2*/
    {
        ADC_APD_A_B4, ADC_APD_A_B5, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE
    },
    /*CH3*/
    {
        ADC_APD_A_B6, ADC_APD_A_B7, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE
    },
    /*CH4*/
    {
        ADC_APD_A_C0, ADC_APD_A_C1, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE
    },
    /*CH5*/
    {
        ADC_APD_A_A0, ADC_APD_A_A1, ADC_APD_A_A2, ADC_APD_A_A3, ADC_APD_A_A4,
        ADC_APD_A_A5, ADC_APD_A_A6, ADC_APD_A_A7, ADC_APD_A_A8, ADC_APD_A_A9,
        ADC_APD_A_A10, ADC_APD_A_A11, ADC_APD_A_A12, ADC_APD_A_A13,
        ADC_APD_A_A14, ADC_APD_A_A15
    },
    /*CH6*/
    {
        ADC_APD_A_B8, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE
    }
};
/* adc2 src bit start address */
static const uint16 Adc2_ChnlScrAddress[ADC_CHNL_MAX][ADC_CHNL_MUX_MAX] =
{
    /*CH0*/
    {
        ADC_APD_A_B6, ADC_APD_A_B7, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE
    },
    /*CH1*/
    {
        ADC_APD_A_B4, ADC_APD_A_B5, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE
    },
    /*CH2*/
    {
        ADC_APD_A_B2, ADC_APD_A_B3, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE
    },
    /*CH3*/
    {
        ADC_APD_A_B0, ADC_APD_A_B1, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE
    },
    /*CH4*/
    {
        ADC_APD_A_A0, ADC_APD_A_A1, ADC_APD_A_A2, ADC_APD_A_A3,
        ADC_APD_A_A4, ADC_APD_A_A5, ADC_APD_A_A6, ADC_APD_A_A7,
        ADC_APD_A_A8, ADC_APD_A_A9, ADC_APD_A_A10, ADC_APD_A_A11,
        ADC_APD_A_A12, ADC_APD_A_A13, ADC_APD_A_A14, ADC_APD_A_A15
    },
    /*CH5*/
    {
        ADC_APD_A_C0, ADC_APD_A_C1, ADC_APD_A_C2, ADC_APD_A_C3,
        ADC_APD_A_C4, ADC_APD_A_C5, ADC_APD_A_C6, ADC_APD_A_C7,
        ADC_APD_A_C8, ADC_APD_A_C9, ADC_APD_A_C10, ADC_APD_A_C11,
        ADC_APD_A_C12, ADC_APD_A_C13, ADC_APD_A_C14, ADC_APD_A_C15
    },
    /*CH6*/
    {
        ADC_APD_A_B8, ADC_APD_NONE, ADC_APD_A_B9, ADC_APD_NONE, ADC_APD_A_B10,
        ADC_APD_NONE, ADC_APD_A_B11, ADC_APD_NONE, ADC_APD_A_B12, ADC_APD_NONE,
        ADC_APD_A_B13, ADC_APD_NONE, ADC_APD_A_B14, ADC_APD_NONE, ADC_APD_A_B15,
        ADC_APD_NONE
    }
};
/* adc3 src bit start address */
static const uint16 Adc3_ChnlScrAddress[ADC_CHNL_MAX][ADC_CHNL_MUX_MAX] =
{
    /*CH0*/
    {
        ADC_APD_A_B8, ADC_APD_A_B9, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE
    },
    /*CH1*/
    {
        ADC_APD_A_B10, ADC_APD_A_B11, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE
    },
    /*CH2*/
    {
        ADC_APD_A_B12, ADC_APD_A_B13, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE
    },
    /*CH3*/
    {
        ADC_APD_A_B14, ADC_APD_A_B15, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE
    },
    /*CH4*/
    {
        ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE
    },
    /*CH5*/
    {
        ADC_APD_A_C0, ADC_APD_A_C1, ADC_APD_A_C2, ADC_APD_A_C3, ADC_APD_A_C4,
        ADC_APD_A_C5, ADC_APD_A_C6, ADC_APD_A_C7, ADC_APD_A_C8, ADC_APD_A_C9,
        ADC_APD_A_C10, ADC_APD_A_C11, ADC_APD_A_C12, ADC_APD_A_C13, ADC_APD_A_C14,
        ADC_APD_A_C15
    },
    /*CH6*/
    {
        ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE, ADC_APD_NONE,
        ADC_APD_NONE
    },
};
/* adc src bit start address array */
static const uint16 *const Adc_ChnlScrAddress[ADC_MODULE_NUMBER] =
{
    &Adc1_ChnlScrAddress[ADC1_CHNL_SCR_START_INDEX][ADC1_CHNL_SCR_START_INDEX],
    &Adc2_ChnlScrAddress[ADC2_CHNL_SCR_START_INDEX][ADC2_CHNL_SCR_START_INDEX],
    &Adc3_ChnlScrAddress[ADC3_CHNL_SCR_START_INDEX][ADC3_CHNL_SCR_START_INDEX]
};
#define ADC_STOP_SEC_CONST_UNSPECIFIED
#include "Adc_MemMap.h"
#endif /* #if (ADC_OVERVOLTAGE_DETECT == STD_ON) */
#endif

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

#if (ADC_DMA_SUPPORTED == STD_ON)
static Adc_ErrorIdType Adc_Ip_StartDmaTransmission(Adc_GroupType dmaGroup);
static Adc_ErrorIdType Adc_Ip_StopDmaTransmission(Adc_GroupType dmaGroup);
#endif /* #if (ADC_DMA_SUPPORTED == STD_ON) */
static Adc_ErrorIdType Adc_Ip_ChnlValueHandle(Adc_RegisterBaseType unitBase, Adc_GroupType grpId,
        const Adc_ValueGroupType *checkValue);
static void Adc_ClearIntEnableAndStatus(Adc_RegisterBaseType hwUnitbase);

static void Adc_WriteRegister(volatile uint32 address, uint8 startBit, uint8 bitWidth,
                              uint32 value)
{
    /* #10 get register current value */
    uint32 tempValue = *((volatile uint32 *)(address));
    /* #20 reset bit field which is ready to modify */

    tempValue &= ~(ADC_BITFIELD_MASK(bitWidth) << startBit);
    /* #30 modify tartge bit field */

    tempValue |= (value << startBit) & (ADC_BITFIELD_MASK(bitWidth) << startBit);
    /* #40 writer register */
    *((volatile uint32 *)(address)) = tempValue;
}

static void Adc_ScrSetBit(Adc_ScrStartBitType startBit, uint32 value)
{
    uint32 registerValue;
    uint32 scrRegisterOff = ADC_SCR_SF_BASE + 0x1000UL + (uint32)(((uint32)startBit >> 5UL) * 4UL);
    uint32 scrStartBit = (uint32)startBit & (0x1FU);
    registerValue = REG_READ32(ADC_SCR_SF_BASE + 0x1000U + (((uint32)startBit >> 5UL) * 4UL));

    registerValue &= ~(ADC_BITFIELD_MASK(ADC_SCR_BIT_WIDTH) << (uint32)scrStartBit);
    registerValue |= value << scrStartBit;
    REG_WRITE32(registerValue, scrRegisterOff);
}
/** **************************************************************************************
 * \brief This function checks whether Adc driver has been initialized.

 * \verbatim
 * Syntax             : Adc_ErrorIdType Adc_CheckInitNotYet(
 *                          void)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : None

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : ADC_E_UNINIT: Adc driver is not initialized
 *                      Others: No error

 * Description        : This function checks whether Adc driver has been initialized.
 * \endverbatim
 * Traceability       : SWSR_ADC_064 SWSR_ADC_072 SWSR_ADC_082 SWSR_ADC_094
 *                      SWSR_ADC_103 SWSR_ADC_109 SWSR_ADC_115 SWSR_ADC_122
 *                      SWSR_ADC_130 SWSR_ADC_137 SWSR_ADC_143 SWSR_ADC_146
 *                      SWSR_ADC_150 SWSR_ADC_177 SWSR_ADC_189 SWSR_ADC_190
 *                      SW_SM001
 *****************************************************************************************/
Adc_ErrorIdType Adc_CheckInitNotYet(void)
{
    Adc_ErrorIdType errorStatus = 0U;

    /* #10 check whether Adc has been initialized. */
    if (ADC_GLOBAL_STATE_UNINIT == Adc_GlobalState)
    {
        errorStatus = ADC_E_UNINIT;
    } /* else not needed */

    return errorStatus;
}
/** **************************************************************************************
 * \brief This function checks whether Adc interrupt enable bit is set.

 * \verbatim
 * Syntax             : static Adc_ErrorIdType Adc_InterruptEnableCheck(
 *                          Adc_RegisterBaseType unitBase)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : unitBase - ADC unit base address

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : errorStatus:
 *                      0: No Error
 *                      ADC_E_INT_NOT_ENABLE: Interrupt bit not enable.

 * Description        : This function checks whether Adc interrupt enable bit is set.
 * \endverbatim
 * Traceability       : SW_SM004
 *****************************************************************************************/
static Adc_ErrorIdType Adc_InterruptEnableCheck(Adc_RegisterBaseType unitBase)
{
    Adc_ErrorIdType errorStatus = 0U;
    AdcFaultInj_Adc_InterruptEnableCheckIntSta(unitBase);
    AdcFaultInj_Adc_InterruptEnableCheckIntSig(unitBase);

    if (FALSE == (REG_READ32(unitBase + SADC_INT_SIG_EN_BASE) & (ADC_BIT_ENABLE <<
                  SADC_INT_SIG_EN_WATER_MARK_SUB_3_FIELD_OFFSET)))
    {
        errorStatus = ADC_E_INT_NOT_ENABLE;
    }
    else if (FALSE == (REG_READ32(unitBase + SADC_INT_STA_EN_BASE) & (ADC_BIT_ENABLE <<
                       SADC_INT_STA_EN_WATER_MARK_SUB_3_FIELD_OFFSET)))
    {
        errorStatus = ADC_E_INT_NOT_ENABLE;
    }
    else
    {
        /* do nothing */
    }

    return errorStatus;
}

static const Adc_HwUnitConfigType *Adc_GetHwCfgThroughPhysicalId(Adc_HwUnitType hwPhysicalId)
{
    Adc_HwUnitType hwUnitIndex = 0U;
    const Adc_HwUnitConfigType *tempHwCfg = NULL_PTR;

    for (; hwUnitIndex < Adc_GlobalConfigPtr->unitCount; hwUnitIndex++)
    {
        if (hwPhysicalId == (Adc_HwUnitType)
                Adc_GlobalConfigPtr->adcUnitCfgPtr[hwUnitIndex].hwModulePhysicalId)
        {
            tempHwCfg = &(Adc_GlobalConfigPtr->adcUnitCfgPtr[hwUnitIndex]);
            break;
        } /* else not needed */
    }

    AdcFaultInj_Adc_GetHwCfgThroughPhysicalIdGetNull();
    return tempHwCfg;
}

static Adc_RcRchtIndexType Adc_Ip_GetInterruptBit(Adc_RegisterBaseType unitBase)
{
    uint32 registerValue;
    Adc_RcRchtIndexType interruptBit = ADC_RCHT_INDEX;
    /* #10 get subfifo3 register value */
    registerValue = REG_READ32(unitBase + SADC_SUB_FIFO_BASE(ADC_SUBFIFO_3));

    if (ADC_BIT_ENABLE == ((registerValue >> SADC_SUB_FIFO_SUB_RC_EN_RC3_FIELD_OFFSET) &
                           ADC_BIT_ENABLE))
    {
        interruptBit = ADC_RC3_INDEX;
    }
    else if (ADC_BIT_ENABLE == ((registerValue >> SADC_SUB_FIFO_SUB_RC_EN_RC2_FIELD_OFFSET) &
                                ADC_BIT_ENABLE))
    {
        interruptBit = ADC_RC2_INDEX;
    }
    else if (ADC_BIT_ENABLE == ((registerValue >> SADC_SUB_FIFO_SUB_RC_EN_RC1_FIELD_OFFSET) &
                                ADC_BIT_ENABLE))
    {
        interruptBit = ADC_RC1_INDEX;
    }
    else if (ADC_BIT_ENABLE == ((registerValue >> SADC_SUB_FIFO_SUB_RC_EN_RC0_FIELD_OFFSET) &
                                ADC_BIT_ENABLE))
    {
        interruptBit = ADC_RC0_INDEX;
    }
    else if (ADC_BIT_ENABLE == ((registerValue >> SADC_SUB_FIFO_SUB_RC_EN_RCHT_FIELD_OFFSET) &
                                ADC_BIT_ENABLE))
    {
        interruptBit = ADC_RCHT_INDEX;
    }
    else
    {
        /* do nothing */
    }

    return interruptBit;
}

static Adc_GroupType Adc_GetGrpIdThroughRcRchtIndex(const Adc_GroupType startGrpId,
        const Adc_RcRchtIndexType grpRcRchtIndex)
{
    Adc_GroupType tempGrpId;

    if (ADC_RCHT_INDEX == Adc_GlobalConfigPtr->adcGroupCfgPtr[startGrpId].groupRcRchtIndex)
    {
        tempGrpId = startGrpId + (Adc_GroupType)grpRcRchtIndex;
    }
    else
    {
        tempGrpId = startGrpId + (Adc_GroupType)grpRcRchtIndex - 1U;
    }

    return tempGrpId;
}

static void Adc_Ip_InitBuffer(Adc_ValueGroupType *buffer, uint8 bufferSize)
{
    uint8 bufferIndex = 0U;

    for (; bufferIndex < bufferSize; bufferIndex++)
    {
        buffer[bufferIndex] = 0UL;
    }

    return;
}

/* The following values for calibration related function settings are based on many experiments. */
/* These experiments are done by simulation design engineers based on ATE with different batches of chips. */
#if (ADC_VOLTAGE_CALIBRATION == STD_ON)
static void Adc_Ip_CalibrationCfg(const Adc_RegisterBaseType ipHardwareUnitbase, boolean enFlags)
{
    uint32 regValue;

    /* check enable or disable */
    /* enable calibration */
    if (TRUE == enFlags)
    {
        /* #10 adc1 calibration set */
        if (ipHardwareUnitbase == ADC1_BASE_ADDRESS)
        {
            /* prepare register value */
            regValue = (ADC1_CALIBRATION_OFFSET << SADC_DCOC_VALUE_FIELD_OFFSET) |
                       (ADC_BIT_ENABLE << SADC_DCOC_SOFT_OVWR_EN_FIELD_OFFSET) ;
            /* set calibration value */
            REG_WRITE32(regValue, (ipHardwareUnitbase + SADC_DCOC_BASE));
        }
        /* #20 adc2 calibration set */
        else if (ipHardwareUnitbase == ADC2_BASE_ADDRESS)
        {
            /* prepare register value */
            regValue = (ADC2_CALIBRATION_OFFSET << SADC_DCOC_VALUE_FIELD_OFFSET) |
                       (ADC_BIT_ENABLE << SADC_DCOC_SOFT_OVWR_EN_FIELD_OFFSET) ;
            /* set calibration value */
            REG_WRITE32(regValue, (ipHardwareUnitbase + SADC_DCOC_BASE));
        }
        /* #30 adc3 calibration set */
        else if (ipHardwareUnitbase == ADC3_BASE_ADDRESS)
        {
            /* prepare register value */
            regValue = (ADC3_CALIBRATION_OFFSET << SADC_DCOC_VALUE_FIELD_OFFSET) |
                       (ADC_BIT_ENABLE << SADC_DCOC_SOFT_OVWR_EN_FIELD_OFFSET) ;
            /* set calibration value */
            REG_WRITE32(regValue, (ipHardwareUnitbase + SADC_DCOC_BASE));
        }
        else
        {
            /* do nothing */
        }

        /* #40 enable calibration */
        REG_RMW32(ipHardwareUnitbase + SADC_DCOC_BASE,
                  SADC_DCOC_EN_FIELD_OFFSET, SADC_DCOC_EN_FIELD_SIZE, ADC_BIT_ENABLE);
    }
    /* disable calibration */
    else
    {
        /* disable calibration */
        REG_WRITE32(ADC_BIT_DISABLE, (ipHardwareUnitbase + SADC_DCOC_BASE));
    }
}
#endif /* #if (ADC_VOLTAGE_CALIBRATION == STD_ON) */

static Adc_ErrorIdType Adc_Ip_TriggerDisable(const Adc_RegisterBaseType ipHardwareUnitbase,
        Adc_GroupType disableGrpId)
{
    const Adc_GroupConfigType *tempGrpCfg = &Adc_GlobalConfigPtr->adcGroupCfgPtr[disableGrpId];
    Adc_ErrorIdType dmaDisableStatus = 0U;
    /* enter critical zone */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_05();

    if (ADC_TRIGG_SRC_SW == tempGrpCfg->triggerSource)
    {
        /* disable rc timmer */
        Adc_WriteRegister((ipHardwareUnitbase + (uint32)(SADC_RC_BASE((uint32)tempGrpCfg->groupRcRchtIndex -
                           1UL))),
                          SADC_RC_TRG_START_FIELD_OFFSET, SADC_RC_TRG_START_FIELD_SIZE, ADC_BIT_DISABLE);
    } /* else not needed */

    Adc_AllGroupInfo[disableGrpId].groupConvStatus = ADC_ALREADY_FINISHED_CONVERTED;
    /* exit critical zone */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_05();

    if (ADC_INTERRUPT_MODE == tempGrpCfg->groupTransferType)
    {
        /* config adc subfifo0 disconnected to used RCx/RCHT */
        Adc_WriteRegister((ipHardwareUnitbase + (uint32)SADC_SUB_FIFO_BASE(ADC_SUBFIFO_3)),
                          SADC_SUB_FIFO_SUB_RC_EN_FIELD_OFFSET,
                          SADC_SUB_FIFO_SUB_RC_EN_FIELD_SIZE,
                          ADC_BIT_DISABLE << (3UL - (uint8)tempGrpCfg->groupRcRchtIndex + 1UL));
        /* disable adc fifo watermark interrupt */
        /* disable fifo watermark int signal */
        Adc_WriteRegister((ipHardwareUnitbase + SADC_INT_SIG_EN_BASE),
                          SADC_INT_SIG_EN_WATER_MARK_SUB_3_FIELD_OFFSET,
                          SADC_INT_SIG_EN_WATER_MARK_SUB_3_FIELD_SIZE, ADC_BIT_DISABLE);
        /* disable fifo watermark int status */
        Adc_WriteRegister((ipHardwareUnitbase + SADC_INT_STA_EN_BASE),
                          SADC_INT_STA_EN_WATER_MARK_SUB_3_FIELD_OFFSET,
                          SADC_INT_STA_EN_WATER_MARK_SUB_3_FIELD_SIZE, ADC_BIT_DISABLE);
    } /* else not neededed */

#if (ADC_DMA_SUPPORTED == STD_ON) /* AdcEnableDmaTransferMode enabled */
    else
    {
        if (ADC_E_DMA_STOP_FAIL == Adc_Ip_StopDmaTransmission(disableGrpId))
        {
            dmaDisableStatus = ADC_E_DMA_STOP_FAIL;
        } /* else not needed */
    }

#endif /* AdcEnableDmaTransferMode enabled */
    return dmaDisableStatus;
}

static Adc_ErrorIdType Adc_Ip_TriggerEnable(const Adc_RegisterBaseType ipHardwareUnitbase,
        Adc_GroupType enableGrpId)
{
    const Adc_GroupConfigType *tempGrpCfg = &Adc_GlobalConfigPtr->adcGroupCfgPtr[enableGrpId];
    Adc_ErrorIdType dmaStartStatus = 0U;

    if (ADC_INTERRUPT_MODE == tempGrpCfg->groupTransferType)
    {
        /* Config adc subfifo0 disconnected to used RCx/RCHT */
        Adc_WriteRegister((ipHardwareUnitbase + SADC_SUB_FIFO_BASE(ADC_SUBFIFO_3)),
                          SADC_SUB_FIFO_SUB_RC_EN_FIELD_OFFSET,
                          SADC_SUB_FIFO_SUB_RC_EN_FIELD_SIZE,
                          ADC_BIT_ENABLE << (3U - (uint8)tempGrpCfg->groupRcRchtIndex + 1U));
        /* disable fifo watermark int signal */
        Adc_WriteRegister((ipHardwareUnitbase + SADC_INT_SIG_EN_BASE),
                          SADC_INT_SIG_EN_WATER_MARK_SUB_3_FIELD_OFFSET,
                          SADC_INT_SIG_EN_WATER_MARK_SUB_3_FIELD_SIZE, ADC_BIT_ENABLE);
        /* disable fifo watermark int status */
        Adc_WriteRegister((ipHardwareUnitbase + SADC_INT_STA_EN_BASE),
                          SADC_INT_STA_EN_WATER_MARK_SUB_3_FIELD_OFFSET,
                          SADC_INT_STA_EN_WATER_MARK_SUB_3_FIELD_SIZE, ADC_BIT_ENABLE);
    }

#if (ADC_DMA_SUPPORTED == STD_ON) /* AdcEnableDmaTransferMode enabled */
    else
    {
        if (ADC_E_DMA_START_FAIL == Adc_Ip_StartDmaTransmission(enableGrpId))
        {
            dmaStartStatus = ADC_E_DMA_START_FAIL;
        } /* else not needed */
    }

#endif /* AdcEnableDmaTransferMode enabled */

#if (ADC_DMA_SUPPORTED == STD_ON)

    if (ADC_E_DMA_START_FAIL != dmaStartStatus)
    {
#endif /* #if (ADC_DMA_SUPPORTED == STD_ON) */

        /* enter critical zone */
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_06();

        if (ADC_TRIGG_SRC_SW == tempGrpCfg->triggerSource)
        {
            /* ready to set current pointer to 0 */
            Adc_WriteRegister((ipHardwareUnitbase + SADC_RC_BASE((uint32)tempGrpCfg->groupRcRchtIndex - 1U)),
                              SADC_RC_SOFT_OVWR_POINT_EN_FIELD_OFFSET, SADC_RC_SOFT_OVWR_POINT_EN_FIELD_SIZE, ADC_BIT_ENABLE);
            /* set current pointer to 0. */
            Adc_WriteRegister((ipHardwareUnitbase + SADC_RC_BASE((uint32)tempGrpCfg->groupRcRchtIndex - 1U)),
                              SADC_RC_CUR_POINT_FIELD_OFFSET, SADC_RC_CUR_POINT_FIELD_SIZE, ADC_BIT_DISABLE);
            /* enable rc timmer */
            Adc_WriteRegister((ipHardwareUnitbase + SADC_RC_BASE((uint32)tempGrpCfg->groupRcRchtIndex - 1U)),
                              SADC_RC_TRG_START_FIELD_OFFSET, SADC_RC_TRG_START_FIELD_SIZE, ADC_BIT_ENABLE);
        } /* else not needed */

        Adc_AllGroupInfo[enableGrpId].groupConvStatus = ADC_NOT_YET_FINISHED_CONVERTED;
        /* exit critical zone*/
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_06();
#if (ADC_DMA_SUPPORTED == STD_ON)
    } /* else not needed */

#endif /* #if (ADC_DMA_SUPPORTED == STD_ON) */

    return dmaStartStatus;
}
/** **************************************************************************************
 * \brief This function checks whether conversion values can match with group config.

 * \verbatim
 * Syntax             : static Adc_ErrorIdType Adc_CheckValueMatch(
 *                          Adc_ValueGroupType conversionValue,
 *                          const Adc_GroupConfigType* grpCfg,
 *                          Adc_ValueGroupType* intBuffer)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : conversionValue - Raw conversion value of one channel
 *                      grpCfg - Group configuration

 * Parameters (inout) : None

 * Parameters (out)   : intBuffer - Internal result buffer

 * Return value       : None

 * Description        : This function checks whether conversion values can match with
 *                      group config.
 * \endverbatim
 * Traceability       : SWSR_ADC_097 SW_SM006
 *****************************************************************************************/
static Adc_ErrorIdType Adc_CheckValueMatch(Adc_ValueGroupType conversionValue,
        const Adc_GroupConfigType *grpCfg, Adc_ValueGroupType *intBuffer)
{
    Adc_ChannelType chnIndex = 0U;
    Adc_ErrorIdType errValueStauts = 0U;
    /* Adc physical id calculation formula is physical id =
    (physical id value configured in the register * 2) */
    /* if channel is P end,The physical id must be increased by 1 extra */

    Adc_ChannelType chnlPhysicalId = (Adc_ChannelType)((((conversionValue) >>
                                     ADC_CHNL_PHYSICAL_ID_START_BIT_IN_CONV_VALUE) & ADC_BITFIELD_MASK(ADC_CHNL_PHYSICAL_ID_BITWIDTH)) *
                                     2UL);

    uint32 chnlMuxId = (conversionValue >> ADC_CHNL_MUX_ID_START_BIT_IN_CONV_VALUE) & ADC_BITFIELD_MASK(
                           ADC_CHNL_PHYSICAL_ID_BITWIDTH);

    if (ADC_BIT_ENABLE == ((conversionValue >> ADC_CHNL_END_START_BIT_IN_CONV_VALUE) & ADC_BIT_ENABLE))
    {
        /* 1:P end 0:N end */
        chnlPhysicalId = chnlPhysicalId + 1U;
    } /* else not needed */

    for (; chnIndex < grpCfg->channelCount; chnIndex++)
    {
        if (chnlPhysicalId == grpCfg->groupChannelCfgPtr[chnIndex].physicalChannelId)
        {
            if (chnlMuxId == (uint32)grpCfg->groupChannelCfgPtr[chnIndex].channelMuxId)
            {

                intBuffer[grpCfg->groupChannelCfgPtr[chnIndex].logicalChannelId] = (conversionValue &
                        ADC_BITFIELD_MASK(ADC_CONV_VALUE_BIT_WIDTH));
                break;
            } /* else not needed */
        } /* else not needed */
    }

    if (chnIndex == grpCfg->channelCount)
    {
        errValueStauts = ADC_E_VALUE_MATCH;
    } /* else not needed */

    AdcFaultInj_Adc_CheckValueMatchFail();
    return errValueStauts;
}

static Adc_ErrorIdType Adc_Ip_ReadFifo(const Adc_RegisterBaseType unitBase, Adc_GroupType grpId,
                                       Adc_ValueGroupType *buffer)
{
    Adc_ChannelType chnlIndex = 0U;
    Adc_ValueGroupType tempValue;
    Adc_ErrorIdType errorValueStatus = 0U;
    const Adc_GroupConfigType *tempGrpCfg = &Adc_GlobalConfigPtr->adcGroupCfgPtr[grpId];

    /* if trigger source is software trigger, get rid of the first conversion value */
    if (ADC_TRIGG_SRC_SW == tempGrpCfg->triggerSource)
    {
        (void)REG_READ32(unitBase + SADC_SUB_FIFO_DATA_BASE(ADC_SUBFIFO_3));
    } /* else not needed */

    for (; chnlIndex < tempGrpCfg->channelCount; chnlIndex++)
    {
        tempValue = REG_READ32(unitBase + SADC_SUB_FIFO_DATA_BASE(ADC_SUBFIFO_3));

        if (ADC_E_VALUE_MATCH == Adc_CheckValueMatch(tempValue, tempGrpCfg, buffer))
        {
            errorValueStatus = ADC_E_VALUE_MATCH;
            break;
        } /* else not needed */
    }

    return errorValueStatus;
}

static void Adc_Ip_SetBaseAddr(void)
{
    /* #10 set base address to internal address buffer */
    Adc_BaseAddress[ADC_INDEX_ADC1] = ADC1_BASE_ADDRESS;
    Adc_BaseAddress[ADC_INDEX_ADC2] = ADC2_BASE_ADDRESS;
    Adc_BaseAddress[ADC_INDEX_ADC3] = ADC3_BASE_ADDRESS;
}

#if (ADC_DEINIT_API == STD_ON) /* AdcDeInitApi enabled */
static void Adc_Ip_ResetBaseAddr(void)
{
    /* #10 reset internal address buffer */
    Adc_BaseAddress[ADC_INDEX_ADC1] = 0UL;
    Adc_BaseAddress[ADC_INDEX_ADC2] = 0UL;
    Adc_BaseAddress[ADC_INDEX_ADC3] = 0UL;
}
#endif /* AdcDeInitApi enabled */

static void Adc_Ip_ConfigRchtEntry(Adc_RegisterBaseType unitBase,
                                   const Adc_GroupConfigType *rchtGroupCfgPtr)
{
    Adc_ChannelType rchtChannelIndex = 0U;
    const Adc_ChannelConfigType *rchtChannelCfgPtr;

    for (; rchtChannelIndex < rchtGroupCfgPtr->channelCount; rchtChannelIndex++)
    {
        rchtChannelCfgPtr = &rchtGroupCfgPtr->groupChannelCfgPtr[rchtChannelIndex];
        /* if group is hardware trigger source, config the RCHT entry */
        /* #10 config the channel negative or positive end */
        Adc_WriteRegister((unitBase + SADC_RCHT_ENTRY_BASE((uint32)rchtChannelCfgPtr->logicalChannelId)),
                          SADC_RCHT_ENTRY_CHNL_END_FIELD_OFFSET,
                          SADC_RCHT_ENTRY_CHNL_END_FIELD_SIZE,
                          ((uint32)rchtChannelCfgPtr->physicalChannelId % 2U));
        /* #20 config the channel physical id */
        /* physical id equals physical id in configuration divide by 2 */
        /* if channel with P end,physical id will plus 1 */
        /* if channel with N end,physical id won't plus 1 */
        Adc_WriteRegister((unitBase + SADC_RCHT_ENTRY_BASE((uint32)rchtChannelCfgPtr->logicalChannelId)),
                          SADC_RCHT_ENTRY_CONTROL_CHNL_FIELD_OFFSET,
                          SADC_RCHT_ENTRY_CONTROL_CHNL_FIELD_SIZE,
                          ((uint32)rchtChannelCfgPtr->physicalChannelId >> 1U));
        /* #30 config the channel mux id */
        Adc_WriteRegister((unitBase + SADC_RCHT_ENTRY_BASE((uint32)rchtChannelCfgPtr->logicalChannelId)),
                          SADC_RCHT_ENTRY_CHNL_MUXID_FIELD_OFFSET,
                          SADC_RCHT_ENTRY_CHNL_MUXID_FIELD_SIZE,
                          (rchtChannelCfgPtr->channelMuxId));
        /* #40 config the channel sample ctrl selection */
        Adc_WriteRegister((unitBase + SADC_RCHT_ENTRY_BASE((uint32)rchtChannelCfgPtr->logicalChannelId)),
                          SADC_RCHT_ENTRY_CSEL_FIELD_OFFSET, SADC_RCHT_ENTRY_CSEL_FIELD_SIZE, rchtChannelCfgPtr->sampleClock);
    }

    return;
}

static void Adc_Ip_ConfigRcEntry(Adc_RegisterBaseType unitBase,
                                 const Adc_GroupConfigType *rcGroupCfgPtr)
{
    Adc_ChannelType rcChannelIndex = 0U;
    const Adc_ChannelConfigType *rcChannelCfgPtr;

    for (; rcChannelIndex < rcGroupCfgPtr->channelCount; rcChannelIndex++)
    {
        rcChannelCfgPtr = &rcGroupCfgPtr->groupChannelCfgPtr[rcChannelIndex];
        /* if group is software trigger source, config the rc entry */
        /* #10 config the channel negative or positive end */
        Adc_WriteRegister((unitBase + SADC_RC_ENTRY_BASE(((uint32)rcGroupCfgPtr->groupRcRchtIndex - 1U),
                           (uint32)rcChannelCfgPtr->logicalChannelId)), SADC_RC_ENTRY_CHNL_END_FIELD_OFFSET,
                          SADC_RC_ENTRY_CHNL_END_FIELD_SIZE,
                          ((uint32)rcChannelCfgPtr->physicalChannelId % 2U));
        /* #20 config the channel physical id */
        /* physical id equals physical id in configuration divide by 2 */
        /* if channel with P end,physical id will plus 1 */
        /* if channel with N end,physical id won't plus 1 */
        Adc_WriteRegister((unitBase + SADC_RC_ENTRY_BASE(((uint32)rcGroupCfgPtr->groupRcRchtIndex - 1U),
                           (uint32)rcChannelCfgPtr->logicalChannelId)), SADC_RC_ENTRY_CONTROL_CHNL_FIELD_OFFSET,
                          SADC_RC_ENTRY_CONTROL_CHNL_FIELD_SIZE,
                          ((uint32)rcChannelCfgPtr->physicalChannelId >> 1U));
        /* #30 config the channel mux id */
        Adc_WriteRegister((unitBase + SADC_RC_ENTRY_BASE(((uint32)rcGroupCfgPtr->groupRcRchtIndex - 1U),
                           (uint32)rcChannelCfgPtr->logicalChannelId)), SADC_RC_ENTRY_CHNL_MUXID_FIELD_OFFSET,
                          SADC_RC_ENTRY_CHNL_MUXID_FIELD_SIZE,
                          (rcChannelCfgPtr->channelMuxId));
        /* #40 config the channel sample ctrl selection */
        Adc_WriteRegister((unitBase + SADC_RC_ENTRY_BASE(((uint32)rcGroupCfgPtr->groupRcRchtIndex - 1U),
                           (uint32)rcChannelCfgPtr->logicalChannelId)),
                          SADC_RC_ENTRY_CSEL_FIELD_OFFSET, SADC_RC_ENTRY_CSEL_FIELD_SIZE, rcChannelCfgPtr->sampleClock);
    }

    return;
}

static void Adc_Ip_ConfigGroup(const Adc_ConfigType *adcConfigPtr, Adc_HwUnitType hwUnitIndex)
{
    /* adc unit base address */
    Adc_RegisterBaseType base =
        Adc_BaseAddress[adcConfigPtr->adcUnitCfgPtr[hwUnitIndex].hwModulePhysicalId];
    /* ipGroupId of the first group in the unit */
    Adc_GroupType startGroupId = adcConfigPtr->adcUnitCfgPtr[hwUnitIndex].startGroupIdInUnit;
    /* adc group configuration */
    const Adc_GroupConfigType *groupCfgPtr = &adcConfigPtr->adcGroupCfgPtr[startGroupId];
    /* group index */
    Adc_GroupType groupIndex = 0U;

    /* group trigger source is hardware trigger source */
    if (ADC_TRIGG_SRC_HW == groupCfgPtr->triggerSource)
    {
        /* #10 config rcht entries */
        Adc_Ip_ConfigRchtEntry(base, groupCfgPtr);
        groupIndex++;
#if (ADC_DMA_SUPPORTED == STD_ON)

        if (ADC_DMA_MODE == groupCfgPtr->groupTransferType)
        {
            /* #20 config dma enabled for rcht */
            Adc_WriteRegister((base + SADC_DMA_BASE), SADC_DMA_RCHT_CONVERSION_DONE_FIELD_OFFSET,
                              SADC_DMA_RCHT_CONVERSION_DONE_FIELD_SIZE, ADC_BIT_DISABLE);
            Adc_WriteRegister((base + SADC_DMA_BASE), SADC_DMA_CHN0_RCHT_ENABLE_FIELD_OFFSET,
                              SADC_DMA_CHN0_RCHT_ENABLE_FIELD_SIZE, ADC_BIT_ENABLE);
        } /* else not needed */

#endif
    } /* else not needed */

    for (; groupIndex < adcConfigPtr->adcUnitCfgPtr[hwUnitIndex].groupCountPerUnit; groupIndex++)
    {
        groupCfgPtr = &adcConfigPtr->adcGroupCfgPtr[startGroupId + groupIndex];
#if (ADC_DMA_SUPPORTED == STD_ON)

        if (ADC_DMA_MODE == groupCfgPtr->groupTransferType)
        {
            /* #30 config dma enabled for rc each conversion */
            Adc_WriteRegister((base + SADC_DMA_BASE),
                              (SADC_DMA_RC0_CONVERSION_DONE_FIELD_OFFSET - ((uint8)groupCfgPtr->groupRcRchtIndex - 1U)),
                              SADC_DMA_EACH_RHCT_RC_CONVERSION_DONE_FIELD_SIZE, ADC_BIT_DISABLE);

            /* 40 check which dma channel should be allocated */
            if (ADC_DMA_CHNL0 == groupCfgPtr->groupDmaChannelIndex)
            {
                /* allocate dma channel_0 to target rc */
                Adc_WriteRegister((base + SADC_DMA_BASE),
                                  (SADC_DMA_CHN0_RC0_ENABLE_FIELD_OFFSET - ((uint8)groupCfgPtr->groupRcRchtIndex - 1U)),
                                  SADC_DMA_CHN0_EACH_RCHT_RC_FIELD_SIEZ, ADC_BIT_ENABLE);
            }
            /* dma channel0 is used for ohter rcht/rc */
            else if (ADC_DMA_CHNL1 == groupCfgPtr->groupDmaChannelIndex)
            {
                /* allocate dma channel_1 to target rc */
                Adc_WriteRegister((base + SADC_DMA_BASE),
                                  (SADC_DMA_CHN1_RC0_ENABLE_FIELD_OFFSET - ((uint8)groupCfgPtr->groupRcRchtIndex - 1U)),
                                  SADC_DMA_CHN1_EACH_RCHT_RC_FIELD_SIEZ, ADC_BIT_ENABLE);
            }
            else
            {
                /* do nothing */
            }
        } /* else not needed */

#endif
        /* #50 config rc entries */
        Adc_Ip_ConfigRcEntry(base, groupCfgPtr);
        /* #60 choose internal rc timmer to produce trigger signal */
        Adc_WriteRegister((base + SADC_RC_BASE(((uint32)groupCfgPtr->groupRcRchtIndex - 1UL))),
                          SADC_RC_TRG_MODE_FIELD_OFFSET,
                          SADC_RC_TRG_MODE_FIELD_SIZE,  ADC_EACH_RC_TIMMER_TRG_MODE);
        /* #70 ready to clear cur_pointer */
        Adc_WriteRegister((base + SADC_RC_BASE(((uint32)groupCfgPtr->groupRcRchtIndex - 1UL))),
                          SADC_RC_SOFT_OVWR_POINT_EN_FIELD_OFFSET,
                          SADC_RC_SOFT_OVWR_POINT_EN_FIELD_SIZE, ADC_BIT_ENABLE);
        /* #80 cur_pointer is set to 0. */
        Adc_WriteRegister((base + SADC_RC_BASE(((uint32)groupCfgPtr->groupRcRchtIndex - 1UL))),
                          SADC_RC_CUR_POINT_FIELD_OFFSET,
                          SADC_RC_CUR_POINT_FIELD_SIZE, 0U);
        /* #90 qStart is set to 0 */
        Adc_WriteRegister((base + SADC_RC_BASE(((uint32)groupCfgPtr->groupRcRchtIndex - 1UL))),
                          SADC_RC_QSTART_FIELD_OFFSET,
                          SADC_RC_QSTART_FIELD_SIZE, 0U);
        /* #100 qEnd is set to channel count minus 1 */
        Adc_WriteRegister((base + SADC_RC_BASE(((uint32)groupCfgPtr->groupRcRchtIndex - 1UL))),
                          SADC_RC_QEND_FIELD_OFFSET,
                          SADC_RC_QEND_FIELD_SIZE, ((uint32)groupCfgPtr->channelCount - 1U));
        /* #110 config rc timer compare value 1 */
        Adc_WriteRegister((base + SADC_RC_TIMER_BASE(((uint32)groupCfgPtr->groupRcRchtIndex - 1UL))),
                          SADC_RC_TIMER_CMP_VALUE_FIELD_OFFSET, SADC_RC_TIMER_CMP_VALUE_FIELD_SIZE, 1U);
        /* #120 config rc timer terminal value 16 */
        Adc_WriteRegister((base + SADC_RC_TIMER_BASE(((uint32)groupCfgPtr->groupRcRchtIndex - 1UL))),
                          SADC_RC_TIMER_TMN_VALUE_FIELD_SIZE,
                          SADC_RC_TIMER_TMN_VALUE_FIELD_OFFSET, 16U);
    }

    return;
}

static void Adc_Ip_ConfigUnit(const Adc_ConfigType *adcConfigPtr, Adc_HwUnitType hwUnitIndex)
{
    /* adc unit base address */
    Adc_RegisterBaseType base =
        Adc_BaseAddress[adcConfigPtr->adcUnitCfgPtr[hwUnitIndex].hwModulePhysicalId];
    /* register value which is ready to set into the Adc prescale Register */
    uint32 clockRegisterValue;
    /* rc timmer Index */
    uint8 rcTimerIndex = 0U;
    /* fifo index */
    uint8 fifoIndex = 0U;
    /* monitor index */
    uint8 monitorIndex = 0U;
    /* temp reg value */
    uint32 temRegValue;

    /* #01 mask rdata unc err sta en */
    Adc_WriteRegister((base + SADC_FUSA_UNCOR_ERR_INT_STAT_EN), SADC_STA_EN_RDATA_UNC_ERR_FIELD_OFFSET,
                      SADC_STA_EN_RDATA_UNC_ERR_FIELD_SIZE, ADC_BIT_DISABLE);
    Adc_WriteRegister((base + SADC_FUSA_UNCOR_ERR_INT_STAT_EN),
                      SADC_STA_EN_DMA_EOBC_UNC_ERR_FIELD_OFFSET,
                      SADC_STA_EN_DMA_EOBC_UNC_ERR_FIELD_SIZE, ADC_BIT_DISABLE);
    /* #02 mask rdata unc err sig en */
    Adc_WriteRegister((base + SADC_FUSA_UNCOR_ERR_INT_SIG_EN), SADC_SIG_EN_RDATA_UNC_ERR_FIELD_OFFSET,
                      SADC_SIG_EN_RDATA_UNC_ERR_FIELD_SIZE, ADC_BIT_DISABLE);
    Adc_WriteRegister((base + SADC_FUSA_UNCOR_ERR_INT_SIG_EN),
                      SADC_SIG_EN_DMA_EOBC_UNC_ERR_FIELD_OFFSET,
                      SADC_SIG_EN_DMA_EOBC_UNC_ERR_FIELD_SIZE, ADC_BIT_DISABLE);
    /* #03 clear rdata unc err sta */
    temRegValue = REG_READ32(base + SADC_FUSA_UNCOR_ERR_INT_STAT);
    REG_WRITE32(temRegValue, (base + SADC_FUSA_UNCOR_ERR_INT_STAT));

    /* #10 config the HTC ready_len 0x1 */
    Adc_WriteRegister((base + SADC_HTC_BASE), SADC_HTC_READY_LEN_FIELD_OFFSET,
                      SADC_HTC_READY_LEN_FIELD_SIZE, 0x1U);
    /* #20 config the HTC done_len 0xF */
    Adc_WriteRegister((base + SADC_HTC_BASE), SADC_HTC_DONE_LEN_FIELD_OFFSET,
                      SADC_HTC_DONE_LEN_FIELD_SIZE, 0xFU);
    /* #30 config scheduler to master mode */
    Adc_WriteRegister((base + SADC_SCH_CFG_BASE), SADC_SCH_CFG_MST_MODE_FIELD_OFFSET,
                      SADC_SCH_CFG_MST_MODE_FIELD_SIZE, ADC_SCHEDULER_MASTER_MODE);
    /* #40 config scheduler to async mode */
    Adc_WriteRegister((base + SADC_SCH_CFG_BASE), SADC_SCH_CFG_SYNC_MODE_FIELD_OFFSET,
                      SADC_SCH_CFG_SYNC_MODE_FIELD_OFFSET, ADC_SCHEDULER_ASYNC_MODE);
    /* #50 config scheduler to enable the rotation */
    Adc_WriteRegister((base + SADC_SCH_CFG_BASE), SADC_SCH_CFG_ROT_EN_FIELD_OFFSET,
                      SADC_SCH_CFG_ROT_EN_FIELD_SIZE, ADC_BIT_ENABLE);
    /* #60 reset timestamp */
    Adc_WriteRegister((base + SADC_SCH_CFG_BASE), SADC_SCH_CFG_TS_RST_FIELD_OFFSET,
                      SADC_SCH_CFG_TS_RST_FIELD_SIZE, ADC_BIT_ENABLE);
    /* #70 release the reset of timestamp */
    Adc_WriteRegister((base + SADC_SCH_CFG_BASE), SADC_SCH_CFG_TS_RST_FIELD_OFFSET,
                      SADC_SCH_CFG_TS_RST_FIELD_SIZE, ADC_BIT_DISABLE);
    /* #80 prepare the value ready to set in adc analog clk divider register */
    clockRegisterValue = (((uint32)adcConfigPtr->adcUnitCfgPtr[hwUnitIndex].hwClockSrcDivider - 1UL) <<
                          SADC_CLK_CTRL_REF_LOW_FIELD_OFFSET) |
                         (((uint32)adcConfigPtr->adcUnitCfgPtr[hwUnitIndex].hwClockSrcDivider - 1UL) <<
                          SADC_CLK_CTRL_REF_HIGH_FIELD_OFFSET);
    /* #90 configure Adc analog part prescale value */
    REG_WRITE32(clockRegisterValue, base + SADC_CLK_CTRL_BASE);

    /* #100 reset all RC timmers */
    for (; rcTimerIndex < ADC_RC_TIMER_CNT; rcTimerIndex++)
    {
        /* hold the reset. */
        Adc_WriteRegister((base + SADC_SOFT_RST_BASE),
                          (SADC_SOFT_RST_RC0_TMR_RST_FIELD_OFFSET + rcTimerIndex), SADC_SOFT_RST_EACH_RC_TMR_RST_FIELD_SIZE,
                          ADC_BIT_ENABLE);
        /* release the reset. */
        Adc_WriteRegister((base + SADC_SOFT_RST_BASE),
                          (SADC_SOFT_RST_RC0_TMR_RST_FIELD_OFFSET + rcTimerIndex), SADC_SOFT_RST_EACH_RC_TMR_RST_FIELD_SIZE,
                          ADC_BIT_DISABLE);
    }

    /* #110 config fifo packmode, 32bit mode */
    Adc_WriteRegister((base + SADC_FIFO_CFG_BASE),
                      SADC_FIFO_CFG_PACK_MODE_FIELD_OFFSET,
                      SADC_FIFO_CFG_PACK_MODE_FIELD_SIZE, ADC_FIFO_32BIT_MODE);

    /* #120 config Subfifo_0/1/2/3 start address is 0 */
    /* in this way,subfifo3 will have 128 words depth */
    for (; fifoIndex < ADC_SUBFIFO_CNT; fifoIndex++)
    {
        Adc_WriteRegister((base + SADC_SUB_FIFO_BASE((uint32)fifoIndex)),
                          SADC_SUB_FIFO_SUB_START_FIELD_OFFSET,
                          SADC_SUB_FIFO_SUB_START_FIELD_SIZE, 0U);
    }

    /* #130 mask all monitor to choose the 0xFFF channel configuration */
    /* in this way, prevent sem errors */
    for (; monitorIndex < ADC_MONITOR_CNT; monitorIndex++)
    {
        Adc_WriteRegister((base + SADC_MNT_THRD_SINGLE_BASE((uint32)monitorIndex)),
                          SADC_MNT_THRD_SINGLE_HTHRD_FIELD_OFFSET,
                          SADC_MNT_THRD_SINGLE_HTHRD_FIELD_SIZE, ADC_MONITOR_FULL_MASK_VALUE);
    }

    Adc_WriteRegister((base + SADC_MNT_THRD_CONT_BASE),
                      SADC_MNT_THRD_CONT_HTHRD_FIELD_OFFSET,
                      SADC_MNT_THRD_CONT_HTHRD_FIELD_SIZE, ADC_MONITOR_FULL_MASK_VALUE);

    /* #140 mask sub-fifo3 overflow error interrupt */
    Adc_WriteRegister((base + SADC_COR_ERR_INT_STA_EN_BASE),
                      SADC_COR_ERR_INT_STA_EN_SUB3_OVF_FIELD_OFFSET,
                      SADC_COR_ERR_INT_STA_EN_SUB3_OVF_FIELD_SIZE, ADC_BIT_DISABLE);
    Adc_WriteRegister((base + SADC_COR_ERR_INT_SIG_EN_BASE),
                      SADC_COR_ERR_INT_SIG_EN_SUB3_OVF_FIELD_OFFSET,
                      SADC_COR_ERR_INT_SIG_EN_SUB3_OVF_FIELD_SIZE, ADC_BIT_DISABLE);
    Adc_WriteRegister((base + SADC_UNC_ERR_INT_STA_EN_BASE),
                      SADC_UNC_ERR_INT_STA_EN_SUB3_OVF_FIELD_OFFSET,
                      SADC_UNC_ERR_INT_STA_EN_SUB3_OVF_FIELD_SIZE, ADC_BIT_DISABLE);
    Adc_WriteRegister((base + SADC_UNC_ERR_INT_SIG_EN_BASE),
                      SADC_UNC_ERR_INT_SIG_EN_SUB3_OVF_FIELD_OFFSET,
                      SADC_UNC_ERR_INT_SIG_EN_SUB3_OVF_FIELD_SIZE, ADC_BIT_DISABLE);
    return;
}

static void Adc_Ip_ConfigAnalog(const Adc_ConfigType *adcConfigPtr, Adc_HwUnitType hwUnitIndex)
{
    /* adc unit base address */
    Adc_RegisterBaseType base =
        Adc_BaseAddress[adcConfigPtr->adcUnitCfgPtr[hwUnitIndex].hwModulePhysicalId];
    /* uint analog register index */
    uint8 unitAnalogRegIndex = 0U;

    /* #10 check adc analog ref select according to selection */
    if (ADC_INTERNAL_REF_3P3V == adcConfigPtr->refVoltageSelect)
    {
        for (; unitAnalogRegIndex < ADC_CONFIG_ANA_REG_CNT; unitAnalogRegIndex++)
        {
            /* #20 choose avdd to be the reference voltage */
            Adc_WriteRegister((base + SADC_ANA_PARA_BASE((uint32)unitAnalogRegIndex)),
                              SADC_ANA_PARA_REFSEL_FIELD_OFFSET,
                              SADC_ANA_PARA_REFSEL_FIELD_SIZE, ADC_VREFP1);
            /* #30 config sample control parameter */
            Adc_WriteRegister((base + SADC_ANA_PARA_BASE((uint32)unitAnalogRegIndex)),
                              SADC_ANA_PARA_SAMCTRL_FIELD_OFFSET,
                              SADC_ANA_PARA_SAMCTRL_FIELD_SIZE, unitAnalogRegIndex);
        }
    }
    else
    {
        for (; unitAnalogRegIndex < ADC_CONFIG_ANA_REG_CNT; unitAnalogRegIndex++)
        {
            /* #40 choose vref1/vref2 to be the reference voltage */
            Adc_WriteRegister((base + SADC_ANA_PARA_BASE((uint32)unitAnalogRegIndex)),
                              SADC_ANA_PARA_REFSEL_FIELD_OFFSET,
                              SADC_ANA_PARA_REFSEL_FIELD_SIZE, ADC_VREFP2);
            /* #50 config sample control parameter */
            Adc_WriteRegister((base + SADC_ANA_PARA_BASE((uint32)unitAnalogRegIndex)),
                              SADC_ANA_PARA_SAMCTRL_FIELD_OFFSET,
                              SADC_ANA_PARA_SAMCTRL_FIELD_SIZE, unitAnalogRegIndex);
        }
    }

#ifndef SEMIDRIVE_E3_LITE_SERIES

    if (ADC_INDEX_ADC2 == adcConfigPtr->adcUnitCfgPtr[hwUnitIndex].hwModulePhysicalId)
    {
        /* #60 config adc2 mcp 0xFFFF. */
        Adc_WriteRegister((base + SADC_ANA_REF_PART2_BASE), SADC_ANA_REF_PART2_MCP_OFFSET,
                          SADC_ANA_REF_PART2_MCP_SIZE, 0xFFFFU);
    } /* else not needed */

#endif
    return;
}
/** **************************************************************************************
 * \brief This function does Adc reset operation.

 * \verbatim
 * Syntax             : static Adc_ErrorIdType Adc_Ip_ConfigReset(
 *                          const Adc_ConfigType *adcConfigPtr,
 *                          Adc_HwUnitType hwUnitIndex)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : adcConfigPtr - Pointer to configuration set
 *                    : hwUnitIndex - Adc Unit logical index

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : ipErrorStatus
 *                      ADC_NO_ERROR: No Error
 *                      ADC_E_INIT_FAIL: Init Failed

 * Description        : This function does Adc reset operation.
 * \endverbatim
 * Traceability       : SW_SM005
 *****************************************************************************************/
static Adc_ErrorIdType Adc_Ip_ConfigReset(const Adc_ConfigType *adcConfigPtr,
        Adc_HwUnitType hwUnitIndex)
{
    /* adc unit base address */
    Adc_RegisterBaseType base =
        Adc_BaseAddress[adcConfigPtr->adcUnitCfgPtr[hwUnitIndex].hwModulePhysicalId];
    /* the time of reading initial register */
    uint32 timeReadInitBit = 0UL;
    /* adc error */
    Adc_ErrorIdType ipErrorStatus;
    /* #10 disable all interrupt status */
    Adc_WriteRegister((base + SADC_INT_STA_EN_BASE), SADC_INT_STA_EN_START_BIT_FIELD_OFFSET,
                      SADC_INT_STA_EN_ALL_VALID_BIT_FIELD_SIZE, ADC_INT_STA_EN_RESET_VALUE);
    /* #20 disable all interrupt signals */
    Adc_WriteRegister((base + SADC_INT_SIG_EN_BASE), SADC_INT_SIG_EN_START_BIT_FIELD_OFFSET,
                      SADC_INT_SIG_EN_ALL_VALID_BIT_FIELD_SIZE, ADC_INT_SIG_EN_RESET_VALUE);
    /* #30 clear all interrupts status */
    Adc_WriteRegister((base + SADC_INT_STA_BASE), SADC_INT_STA_START_BIT_FIELD_OFFSET,
                      SADC_INT_STA_ALL_VALID_BIT_FIELD_SIZE, SADC_INT_STA_ALL);
    /* #40 reset adc analog soft reset */
    Adc_WriteRegister((base + SADC_SOFT_RST_BASE), SADC_SOFT_RST_ANA_RST_FIELD_OFFSET,
                      SADC_SOFT_RST_ANA_RST_FIELD_SIZE, ADC_BIT_DISABLE);
    /* #50 reset adc digital soft reset */
    Adc_WriteRegister((base + SADC_SOFT_RST_BASE), SADC_SOFT_RST_DIG_RST_FIELD_OFFSET,
                      SADC_SOFT_RST_DIG_RST_FIELD_SIZE, ADC_BIT_ENABLE);
    /* #60 release adc analog soft reset */
    Adc_WriteRegister((base + SADC_SOFT_RST_BASE), SADC_SOFT_RST_ANA_RST_FIELD_OFFSET,
                      SADC_SOFT_RST_ANA_RST_FIELD_SIZE, ADC_BIT_ENABLE);
    /* #70 release adc digital soft reset */
    Adc_WriteRegister((base + SADC_SOFT_RST_BASE), SADC_SOFT_RST_DIG_RST_FIELD_OFFSET,
                      SADC_SOFT_RST_DIG_RST_FIELD_SIZE, ADC_BIT_DISABLE);
    /* #80 config adc initialzation value */
    Adc_WriteRegister((base + SADC_INIT_BASE), SADC_INIT_VALUE_FIELD_OFFSET,
                      SADC_INIT_VALUE_FIELD_SIZE, ADC_INIT_INITVALUE_RESET_AND_CONFIG_VALUE);
    /* #90 set the adc initialization bit */
    Adc_WriteRegister((base + SADC_INIT_BASE), SADC_INIT_START_FIELD_OFFSET,
                      SADC_INIT_START_FIELD_SIZE, ADC_BIT_ENABLE);

    /* #100 wait initial adc done */
    for (; timeReadInitBit < ADC_POLLING_TIMEOUT_VALUE; timeReadInitBit++)
    {
        /* #130 check whether adc init done bit set */
        if (FALSE != (REG_READ32(base + SADC_INIT_BASE) & (ADC_BIT_ENABLE << SADC_INIT_DONE_FIELD_OFFSET)))
        {
            break;
        } /* else not needed */
    }

    AdcFaultInj_Adc_Ip_ConfigResetFail();

    /* #120 check whether adc initialization timeout */
    if (timeReadInitBit >= ADC_POLLING_TIMEOUT_VALUE)
    {
        /* init time out */
        ipErrorStatus = ADC_E_INIT_FAIL;
    }
    else
    {
        /* init successfully */
        ipErrorStatus = ADC_NO_ERROR;
#if (ADC_VOLTAGE_CALIBRATION == STD_ON)
        /* #130 config calibration */
        Adc_Ip_CalibrationCfg(base, TRUE);
#endif /* #if (ADC_VOLTAGE_CALIBRATION == STD_ON) */
    }

    return ipErrorStatus;
}

#if (ADC_DMA_SUPPORTED == STD_ON) /* AdcEnableDmaTransferMode enbaled */
static void Adc_DmaDataProcess(Adc_RegisterBaseType HwUsedDmaBase, Adc_GroupType dmaDataGroupId,
                               const Adc_ValueGroupType *dmaBuffer, const Adc_GroupConfigType *dmaDataGroupPtr)
{
    /* internal buffer */
    Adc_ValueGroupType interBuffer[ADC_USED_MAX_GROUP_CHNL_COUNT];
    /* channel index */
    Adc_ChannelType channelIndex = 0U;
    /* error number code */
    Adc_ErrorIdType dmaErrorStatus = 0U;
    /* temp value */
    const Adc_ValueGroupType *tempDmaBuffer = dmaBuffer;
    /* #10 init inter buffer with 0 */
    Adc_Ip_InitBuffer(interBuffer, ADC_USED_MAX_GROUP_CHNL_COUNT);
    /* #20 invalidate cache */
#if (ADC_NO_CACHEABLE_NEEDED == STD_OFF)
    /*PRQA S 0306  1*/
    Dma_InvalidateCache((uint32)tempDmaBuffer,
                        (((uint32)dmaDataGroupPtr->channelCount + 2U) * ADC_WORD_TO_BYTE));
#endif

    for (; channelIndex < dmaDataGroupPtr->channelCount; channelIndex++)
    {
        /* #30 check conversion values whether can match with group configuration and sort them into internal buffer */
        if (ADC_E_VALUE_MATCH == Adc_CheckValueMatch(tempDmaBuffer[channelIndex + 2U], dmaDataGroupPtr,
                interBuffer))
        {
            /* channel conversion value can not match group configuration */
            dmaErrorStatus = ADC_E_VALUE_MATCH;
            break;
        } /* else not needed */
    }

    if (ADC_E_VALUE_MATCH != dmaErrorStatus)
    {
        /* #40 over voltage process */
        if (ADC_E_DMA_START_FAIL == Adc_Ip_ChnlValueHandle(HwUsedDmaBase, dmaDataGroupId,
                (const Adc_ValueGroupType *)interBuffer))
        {
            dmaErrorStatus = ADC_E_DMA_START_FAIL;
        } /* else not neede */
    } /* else not needed */

    /* to prevent dmaErrorStatus from no use*/
    ADC_DUMMY_STATEMENT(dmaErrorStatus);
    return;
}
static void Adc_EndGroupConversionDma(Dma_ControllerStatusType dma_stat, void *context)
{
    /* #10 dma disable status */
    Adc_ErrorIdType dmaStopStatus = 0U;
    /* #20 get group used dma channel configuration */
    /*PRQA S 0316  1*/
    const Dma_ChannelConfigType *chan = (const Dma_ChannelConfigType *)context;
    /* #30 get adc group configuration */
    /*PRQA S 0316  1*/
    const Adc_GroupConfigType *damGroupCfgPtr = (Adc_GroupConfigType *)chan->context;
    /* #40 get unit configuration the group belongs to */
    const Adc_HwUnitConfigType *dmaUnitCfgPtr =
        &Adc_GlobalConfigPtr->adcUnitCfgPtr[damGroupCfgPtr->belongUnitLogicalId];
    /* #50 group id */
    Adc_GroupType dmaGroupId = Adc_GetGrpIdThroughRcRchtIndex(dmaUnitCfgPtr->startGroupIdInUnit,
                               damGroupCfgPtr->groupRcRchtIndex);

    if (DMA_COMPLETED == dma_stat)
    {
        /* #60 check whether group is already stopped by Adc_StopGroupConversion/Adc_EnableHardwareTrigger */
        if (ADC_NOT_YET_FINISHED_CONVERTED == Adc_AllGroupInfo[dmaGroupId].groupConvStatus)
        {
            /* #70 diable trigger */
            if (ADC_E_DMA_STOP_FAIL == Adc_Ip_TriggerDisable(Adc_BaseAddress[dmaUnitCfgPtr->hwModulePhysicalId],
                    dmaGroupId))
            {
                /* dma stop failed */
                dmaStopStatus = ADC_E_DMA_STOP_FAIL;
            }
            else
            {
                /* #80 process dma conversion values */
                Adc_DmaDataProcess(Adc_BaseAddress[dmaUnitCfgPtr->hwModulePhysicalId], dmaGroupId,
                                   Adc_DmaBufAdcUnit[(uint8)dmaUnitCfgPtr->hwModulePhysicalId + (uint8)
                                                                                              damGroupCfgPtr->groupDmaChannelIndex], damGroupCfgPtr);
            }
        } /* else not needed */
    } /* else not needed */

    /* prevent dmaStopStatus from no use */
    ADC_DUMMY_STATEMENT(dmaStopStatus);
}

static Adc_ErrorIdType Adc_Ip_ConfigDma(const Adc_ConfigType *adcConfigPtr,
                                        Adc_HwUnitType hwLogicalModuleId)
{
    /* hardware unit configuration */
    const Adc_HwUnitConfigType *unitCfgPtr = &adcConfigPtr->adcUnitCfgPtr[hwLogicalModuleId];
    /* group index */
    Adc_GroupType groupIndex = 0U;
    /* the first group id in current unit */
    Adc_GroupType unitStartGroupId = unitCfgPtr->startGroupIdInUnit;
    /* group configuration */
    Adc_GroupConfigType *groupCfgPtr;
    /* dma channel allocation variable */
    Dma_InstanceConfigType dmaAdcConfigData;
    /* get dma channel status */
    uint8 dmaConfigRet;
    /* allocate dma channel status */
    Adc_ErrorIdType dmaCfgStatus = 0U;
    /* dma channel infomation */
    Dma_ChannelConfigType *chan;
    /* detailed dma channel configuration */
    Dma_DeviceConfigType dmaDetailCfg;

    for (; groupIndex < unitCfgPtr->groupCountPerUnit; groupIndex++)
    {
        /* #10 get group configutation */
        groupCfgPtr = &adcConfigPtr->adcGroupCfgPtr[unitStartGroupId + groupIndex];

        /* #20 check whether group use dma to transfer */
        if (ADC_DMA_MODE == groupCfgPtr->groupTransferType)
        {
            /* #30 config dma params */
            /*PRQA S 2986  2*/
            dmaConfigRet = Dma_GetConfigParams(Adc_DmaUnitTable[unitCfgPtr->hwModulePhysicalId],
                                               Adc_DmaSubIdTable[((uint8)DMA_ADC_FIFO0 + (uint8)groupCfgPtr->groupDmaChannelIndex)],
                                               DMA_MODULE_ADC,
                                               &dmaAdcConfigData);

            AdcFaultInj_Adc_Ip_ConfigDmaGetParmFail();

            /* #40 check whether dma params config failed */
            if (E_OK != dmaConfigRet )
            {
                /* dma params config failed */
                dmaCfgStatus = ADC_E_DMA_CFG_FAIL;
            }
            else
            {
                /* #50 request dma channel */
                chan = Dma_RequestChannelWithId(dmaAdcConfigData.controller, dmaAdcConfigData.channelId);

                AdcFaultInj_Adc_Ip_ConfigDmaReqChnlFail();

                /* #60 check whether request dma channel successfully */
                if (NULL_PTR == chan)
                {
                    /* #70 request dma channel failed */
                    dmaCfgStatus = ADC_E_DMA_CFG_FAIL;
                }
                else
                {
                    /* #80 detailed dma channel configuration */


                    (void)Dma_InitConfigChannel(&dmaDetailCfg);
                    /*PRQA S 0314  1*/
                    groupCfgPtr->priv = (void *)chan;
                    /*PRQA S 0314  1*/
                    chan->context = (void *)groupCfgPtr;
                    chan->irqCallback = (Dma_IrqHandle)Adc_EndGroupConversionDma;
                    dmaDetailCfg.transaction = DMA_DEVICE;
                    dmaDetailCfg.direction = DMA_DEVICE_TO_MEMORY;
                    dmaDetailCfg.srcAddress = (uint32)Adc_BaseAddress[(uint8)unitCfgPtr->hwModulePhysicalId] +
                                              SADC_CONV_LOW_BASE((
                                                          uint32)groupCfgPtr->groupRcRchtIndex);
                    /*PRQA S 0306  1*/
                    dmaDetailCfg.dstAddress =  Mcal_AddressConvert((uint32)Adc_DmaBufAdcUnit[(uint8)
                                               unitCfgPtr->hwModulePhysicalId + (uint8)groupCfgPtr->groupDmaChannelIndex]);
                    dmaDetailCfg.srcBusWidth = DMA_BEAT_SIZE_4_BYTE;
                    dmaDetailCfg.dstBusWidth = DMA_BEAT_SIZE_4_BYTE;
                    dmaDetailCfg.srcMaxBurst = DMA_BURST_LENGTH_1;
                    dmaDetailCfg.dstMaxBurst = DMA_BURST_LENGTH_1;
                    dmaDetailCfg.processMode = DMA_INTERRUPT;
                    dmaDetailCfg.srcPortSelect = DMA_PORT_AHB32;
                    dmaDetailCfg.dstPortSelect = DMA_PORT_AXI64;
                    dmaDetailCfg.srcIncDirection = DMA_BURST_FIXED;
                    dmaDetailCfg.dstIncDirection = DMA_BURST_INCREMENTAL;
                    dmaDetailCfg.flowControl = DMA_DIR_DEVICE_TO_MEMORY;
                    dmaDetailCfg.transferMode = DMA_TRANSFER_MODE_SINGLE;
                    dmaDetailCfg.linkListTriggerMode = DMA_TRIGGER_BY_HARDWARE;
                    dmaDetailCfg.customMuxIdFlag     = (boolean)TRUE;
                    dmaDetailCfg.customMuxId         = ADC_DMA_START_MUX_ID + ((uint16)unitCfgPtr->hwModulePhysicalId *
                                                       2U) +
                                                       (uint16)groupCfgPtr->groupDmaChannelIndex;

                    AdcFaultInj_Adc_Ip_ConfigDmaCfgChnlFail();

                    /* #90 check whether dma channel config failed */
                    if (E_OK != Dma_ConfigChannel(chan, &dmaDetailCfg))
                    {
                        /* dma channel config failed */
                        dmaCfgStatus = ADC_E_DMA_CFG_FAIL;
                    }
                    /* #100 check whether dma prepare transmission failed */
                    else if (E_OK != Dma_PrepareTransmission(chan, ((uint32)groupCfgPtr->channelCount + 2U) * 4U))
                    {
                        /* dma prepare transmission failed */
                        dmaCfgStatus = ADC_E_DMA_CFG_FAIL;
                    }
                    else
                    {
                        /* do nothing */
                    }
                }
            }
        }

        /* dma config failed */
        if (ADC_E_DMA_CFG_FAIL == dmaCfgStatus)
        {
            break;
        } /* else not needed */
    }

    return dmaCfgStatus;
}

static Adc_ErrorIdType Adc_Ip_DeInitDma(const Adc_HwUnitType hwLogicalModuleId)
{
    /* hardware unit configuration */
    const Adc_HwUnitConfigType *unitCfgPtr = &Adc_GlobalConfigPtr->adcUnitCfgPtr[hwLogicalModuleId];
    /* group index */
    Adc_GroupType groupIndex = 0U;
    /* the first group id in current unit */
    Adc_GroupType unitStartGroupId = unitCfgPtr->startGroupIdInUnit;
    /* group configuration */
    const Adc_GroupConfigType *groupCfgPtr;
    /* dma deinit status */
    Adc_ErrorIdType dmaDeinitStatus = 0U;

    for (; groupIndex < unitCfgPtr->groupCountPerUnit; groupIndex++)
    {
        /* #10 get group configutation */
        groupCfgPtr = &Adc_GlobalConfigPtr->adcGroupCfgPtr[unitStartGroupId + groupIndex];

        /* #20 check whether group use dma to transfer */
        if (ADC_DMA_MODE == groupCfgPtr->groupTransferType)
        {
            /* #30 release dma channel */
            /*PRQA S 0316  1*/
            if (E_OK != Dma_ReleaseChannel((Dma_ChannelConfigType *)groupCfgPtr->priv))
            {
                dmaDeinitStatus = ADC_E_DMA_RELEASE_FAIL;
                break;
            }
            else
            {
                dmaDeinitStatus = ADC_NO_ERROR;
            }
        }
        else
        {
            dmaDeinitStatus = ADC_NO_ERROR;
        }
    }

    return dmaDeinitStatus;
}

static Adc_ErrorIdType Adc_Ip_StartDmaTransmission(Adc_GroupType dmaGroup)
{
    Adc_ErrorIdType dmaCfgStatus = 0U;
    const Adc_GroupConfigType *dmaGroupCfgPtr = &Adc_GlobalConfigPtr->adcGroupCfgPtr[dmaGroup];
    /* init buffer */
    Adc_Ip_InitBuffer(Adc_DmaBufAdcUnit[(uint8)dmaGroupCfgPtr->belongUnitPhysicalId +
                                                                                    (uint8)dmaGroupCfgPtr->groupDmaChannelIndex],  ((uint8)dmaGroupCfgPtr->channelCount + 2U) * 4U);
#if (ADC_NO_CACHEABLE_NEEDED == STD_OFF)
    /*PRQA S 0306  1*/
    Dma_CleanCache((uint32) Adc_DmaBufAdcUnit[(uint8)dmaGroupCfgPtr->belongUnitPhysicalId +
                                                               (uint8)dmaGroupCfgPtr->groupDmaChannelIndex],  ((uint32)dmaGroupCfgPtr->channelCount + 2U) * 4U);
#endif
    /* enter critical zone */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_09();

    if (FALSE ==
            Adc_DmaTransStatus[dmaGroupCfgPtr->belongUnitPhysicalId][dmaGroupCfgPtr->groupDmaChannelIndex])
    {
        Adc_DmaTransStatus[dmaGroupCfgPtr->belongUnitPhysicalId][dmaGroupCfgPtr->groupDmaChannelIndex] =
            TRUE;
        /* exit critical zone */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_09();

        /*PRQA S 0316  1*/
        if (E_OK != Dma_Start((Dma_ChannelConfigType *)dmaGroupCfgPtr->priv))
        {
            Adc_DmaTransStatus[dmaGroupCfgPtr->belongUnitPhysicalId][dmaGroupCfgPtr->groupDmaChannelIndex] =
                FALSE;
            dmaCfgStatus = ADC_E_DMA_START_FAIL;
        } /* else not needed */
    }
    else
    {
        /* exit critical zone */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_09();
    }

    return dmaCfgStatus;
}

static Adc_ErrorIdType Adc_Ip_StopDmaTransmission(Adc_GroupType dmaGroup)
{
    Adc_ErrorIdType dmaCfgStatus = 0U;
    const Adc_GroupConfigType *dmaGroupCfgPtr = &Adc_GlobalConfigPtr->adcGroupCfgPtr[dmaGroup];
    /* enter critical zone */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_09();

    if (TRUE ==
            Adc_DmaTransStatus[dmaGroupCfgPtr->belongUnitPhysicalId][dmaGroupCfgPtr->groupDmaChannelIndex])
    {
        Adc_DmaTransStatus[dmaGroupCfgPtr->belongUnitPhysicalId][dmaGroupCfgPtr->groupDmaChannelIndex] =
            FALSE;
        /* exit critical zone */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_09();

        /*PRQA S 0316  1*/
        if (E_OK != Dma_Stop((Dma_ChannelConfigType *)dmaGroupCfgPtr->priv))
        {
            Adc_DmaTransStatus[dmaGroupCfgPtr->belongUnitPhysicalId][dmaGroupCfgPtr->groupDmaChannelIndex] =
                TRUE;
            dmaCfgStatus = ADC_E_DMA_STOP_FAIL;
        } /* else not needed */
    }
    else
    {
        /* exit critical zone */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_09();
    }

    return dmaCfgStatus;
}
#endif /* AdcEnableDmaTransferMode enabled */
#if (ADC_DEINIT_API == STD_ON) /* AdcDeInitApi enabled */
/** **************************************************************************************
 * \brief This function returns the version information of this module.

 * \verbatim
 * Syntax             : void Dma_Init(
 *                          Dma_ConfigType* configPtr)

 * Service ID[hex]    : 0x00

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : configPtr - Pointer to configuration set

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : Driver Module Initialization function.The Initialization function shall
 *                      initialize all DMA relevant registers with the values of the structure
 *                      referenced by the parameter ConfigPtr
 * \endverbatim
 * Traceability       : SWSR_ADC_191
 *****************************************************************************************/
static void Adc_Ip_DeInitUnit(Adc_HwUnitType hwUnitIndex)
{
    /* adc unit base address */
    Adc_RegisterBaseType base =
        Adc_BaseAddress[Adc_GlobalConfigPtr->adcUnitCfgPtr[hwUnitIndex].hwModulePhysicalId];
    /* rc index */
    uint8 rcIndex = 0U;
    /* fifo count */
    uint8 fifoCount = 0U;
    /* rcht entry count */
    uint8 rchtEntryCount = 0U;
    /* rc entry count */
    uint8 rcEntryCount = 0U;
    /* unit analog register index */
    uint8 unitAnalogRegIndex = 0U;
    /* unit monitor register index */
    uint8 monitorIndex = 0U;

    /* #30 reset the HTC ready_len */
    Adc_WriteRegister((base + SADC_HTC_BASE), SADC_HTC_READY_LEN_FIELD_OFFSET,
                      SADC_HTC_READY_LEN_FIELD_SIZE, ADC_HTC_READY_LEN_RESET_VALUE);
    /* #40 reset the HTC done_len */
    Adc_WriteRegister((base + SADC_HTC_BASE), SADC_HTC_DONE_LEN_FIELD_OFFSET,
                      SADC_HTC_DONE_LEN_FIELD_SIZE, ADC_HTC_DONE_LEN_RESET_VALUE);
    /* #50 reset scheduler master/slave mode bit */
    Adc_WriteRegister((base + SADC_SCH_CFG_BASE), SADC_SCH_CFG_MST_MODE_FIELD_OFFSET,
                      SADC_SCH_CFG_MST_MODE_FIELD_SIZE, ADC_SCHEDULER_SLAVE_MASTER_MODE_RESET_VALUE);
    /* #60 reset scheduler async/sync mode */
    Adc_WriteRegister((base + SADC_SCH_CFG_BASE), SADC_SCH_CFG_SYNC_MODE_FIELD_OFFSET,
                      SADC_SCH_CFG_SYNC_MODE_FIELD_OFFSET, ADC_SCHEDULER_ASYNC_SYNC_MODE_RESET_VALUE);
    /* #70 reset scheduler to disable the rotation */
    Adc_WriteRegister((base + SADC_SCH_CFG_BASE), SADC_SCH_CFG_ROT_EN_FIELD_OFFSET,
                      SADC_SCH_CFG_ROT_EN_FIELD_SIZE, ADC_BIT_DISABLE);
    /* #80 reset timestamp */
    Adc_WriteRegister((base + SADC_SCH_CFG_BASE), SADC_SCH_CFG_TS_RST_FIELD_OFFSET,
                      SADC_SCH_CFG_TS_RST_FIELD_SIZE, ADC_BIT_ENABLE);
    /* #90 release the reset of timestamp */
    Adc_WriteRegister((base + SADC_SCH_CFG_BASE), SADC_SCH_CFG_TS_RST_FIELD_OFFSET,
                      SADC_SCH_CFG_TS_RST_FIELD_SIZE, ADC_BIT_DISABLE);
    /* #100 reset Adc analog part prescale value */
    REG_WRITE32(ADC_CLK_CTRL_RESET_VALUE, base + SADC_CLK_CTRL_BASE);
    /* #110 reset dma */
    REG_WRITE32(ADC_DMA_CTRL_RESET_VALUE, base + SADC_DMA_BASE);

    /* #120 reset all RC timmers */
    for (; rcIndex < ADC_RC_TIMER_CNT; rcIndex++)
    {
        /* hold the reset */
        Adc_WriteRegister((base + SADC_SOFT_RST_BASE),
                          SADC_SOFT_RST_RC0_TMR_RST_FIELD_OFFSET + rcIndex, SADC_SOFT_RST_EACH_RC_TMR_RST_FIELD_SIZE,
                          ADC_BIT_ENABLE);
        /* release the reset */
        Adc_WriteRegister((base + SADC_SOFT_RST_BASE),
                          SADC_SOFT_RST_RC0_TMR_RST_FIELD_OFFSET + rcIndex, SADC_SOFT_RST_EACH_RC_TMR_RST_FIELD_SIZE,
                          ADC_BIT_DISABLE);
        /* reset rc timer compare/terminal value. */
        REG_WRITE32(0U, (base + SADC_RC_TIMER_BASE((uint32)rcIndex)));
        /* ready to clear cur_pointer. */
        Adc_WriteRegister((base + (SADC_RC_BASE((uint32)rcIndex))), SADC_RC_SOFT_OVWR_POINT_EN_FIELD_OFFSET,
                          SADC_RC_SOFT_OVWR_POINT_EN_FIELD_SIZE, ADC_BIT_ENABLE);
        /* cur_pointer is set to 0. */
        Adc_WriteRegister((base + (SADC_RC_BASE((uint32)rcIndex))), SADC_RC_CUR_POINT_FIELD_OFFSET,
                          SADC_RC_CUR_POINT_FIELD_SIZE, 0U);
        /* deinit rc */
        Adc_WriteRegister((base + SADC_RC_BASE((uint32)rcIndex)), SADC_RC_TRG_START_FIELD_OFFSET,
                          SADC_RC_TRG_START_FIELD_SIZE, ADC_BIT_DISABLE);
        Adc_WriteRegister((base + SADC_RC_BASE((uint32)rcIndex)), SADC_RC_TMR_MODE_FIELD_OFFSET,
                          SADC_RC_TMR_MODE_FIELD_SIZE, ADC_RC_TMR_MODE_RESET_VALUE);
        Adc_WriteRegister((base + SADC_RC_BASE((uint32)rcIndex)), SADC_RC_TRG_MODE_FIELD_OFFSET,
                          SADC_RC_TRG_MODE_FIELD_SIZE, ADC_RC_TRG_MODE_RESET_VALUE);
        Adc_WriteRegister((base + SADC_RC_BASE((uint32)rcIndex)), SADC_RC_TRG_EN_FIELD_OFFSET,
                          SADC_RC_TRG_EN_FIELD_SIZE, ADC_RC_TRG_EN_RESET_VALUE);
    }

    /* #130 reset fifo packmode */
    Adc_WriteRegister((base + SADC_FIFO_CFG_BASE),
                      SADC_FIFO_CFG_PACK_MODE_FIELD_OFFSET,
                      SADC_FIFO_CFG_PACK_MODE_FIELD_SIZE, ADC_FIFO_PACK_MODE_RESET_VALUE);

    /* #140 deinit all subfifo */
    for (; fifoCount < ADC_SUBFIFO_CNT; fifoCount++)
    {
        Adc_WriteRegister((base + SADC_SUB_FIFO_BASE((uint32)fifoCount)),
                          SADC_SUB_FIFO_SUB_START_FIELD_OFFSET,
                          SADC_SUB_FIFO_SUB_START_FIELD_SIZE, ADC_SUBFIFO_START_ADDR_RESET_VALUE);
        Adc_WriteRegister((base + SADC_SUB_FIFO_BASE((uint32)fifoCount)),
                          SADC_SUB_FIFO_SUB_THRD_FIELD_OFFSET,
                          SADC_SUB_FIFO_SUB_THRD_FIELD_SIZE, ADC_SUBFIFO_THRD_RESET_VALUE);
        Adc_WriteRegister((base + SADC_SUB_FIFO_BASE((uint32)fifoCount)),
                          SADC_SUB_FIFO_SUB_RC_EN_FIELD_OFFSET,
                          SADC_SUB_FIFO_SUB_RC_EN_FIELD_SIZE, ADC_SUBFIFO_EN_RCHT_RC_RESET_VALUE);
    }

    /* #150 deinit rcht entry */
    for (; rchtEntryCount < ADC_RCHT_ENTRY_CNT; rchtEntryCount++)
    {
        Adc_WriteRegister((base + SADC_RCHT_ENTRY_BASE((uint32)rchtEntryCount)),
                          SADC_RCHT_ENTRY_AMSEL_FIELD_OFFSET, SADC_RCHT_ENTRY_AMSEL_FIELD_SIZE,
                          ADC_RCHT_RC_ENTRY_RESET_VALUE);
        Adc_WriteRegister((base + SADC_RCHT_ENTRY_BASE((uint32)rchtEntryCount)),
                          SADC_RCHT_ENTRY_CSEL_FIELD_OFFSET, SADC_RCHT_ENTRY_CSEL_FIELD_SIZE, ADC_RCHT_RC_ENTRY_RESET_VALUE);
        Adc_WriteRegister((base + SADC_RCHT_ENTRY_BASE((uint32)rchtEntryCount)),
                          SADC_RCHT_ENTRY_REPEAT_MODE_FIELD_OFFSET, SADC_RCHT_ENTRY_REPEAT_MODE_FIELD_SIZE,
                          ADC_RCHT_RC_ENTRY_RESET_VALUE);
        Adc_WriteRegister((base + SADC_RCHT_ENTRY_BASE((uint32)rchtEntryCount)),
                          SADC_RCHT_ENTRY_REPEAT_TIMES_FIELD_OFFSET, SADC_RCHT_ENTRY_REPEAT_TIMES_FIELD_SIZE,
                          ADC_RCHT_RC_ENTRY_RESET_VALUE);
    }

    /* #160 deinit rc entry */
    for (; rcEntryCount < ADC_RC_ENTRY_TOTAL_CNT; rcEntryCount++)
    {
        Adc_WriteRegister((base + SADC_RC_ENTRY_BASE(((uint32)rcEntryCount / ADC_EACH_RC_ENTRY_CNT),
                           ((uint32)rcEntryCount % ADC_EACH_RC_ENTRY_CNT))), SADC_RC_ENTRY_AMSEL_FIELD_OFFSET,
                          SADC_RC_ENTRY_AMSEL_FIELD_SIZE, ADC_RCHT_RC_ENTRY_RESET_VALUE);
        Adc_WriteRegister((base + SADC_RC_ENTRY_BASE(((uint32)rcEntryCount / ADC_EACH_RC_ENTRY_CNT),
                           ((uint32)rcEntryCount % ADC_EACH_RC_ENTRY_CNT))), SADC_RC_ENTRY_CSEL_FIELD_OFFSET,
                          SADC_RC_ENTRY_CSEL_FIELD_SIZE, ADC_RCHT_RC_ENTRY_RESET_VALUE);
        Adc_WriteRegister((base + SADC_RC_ENTRY_BASE(((uint32)rcEntryCount / ADC_EACH_RC_ENTRY_CNT),
                           ((uint32)rcEntryCount % ADC_EACH_RC_ENTRY_CNT))), SADC_RC_ENTRY_REPEAT_MODE_FIELD_OFFSET,
                          SADC_RC_ENTRY_REPEAT_MODE_FIELD_SIZE, ADC_RCHT_RC_ENTRY_RESET_VALUE);
        Adc_WriteRegister((base + SADC_RC_ENTRY_BASE(((uint32)rcEntryCount / ADC_EACH_RC_ENTRY_CNT),
                           ((uint32)rcEntryCount % ADC_EACH_RC_ENTRY_CNT))), SADC_RC_ENTRY_REPEAT_TIMES_FIELD_OFFSET,
                          SADC_RC_ENTRY_REPEAT_TIMES_FIELD_SIZE, ADC_RCHT_RC_ENTRY_RESET_VALUE);
    }

    /* #170 reset analog register configuration */
    for (; unitAnalogRegIndex < ADC_CONFIG_ANA_REG_CNT; unitAnalogRegIndex++)
    {
        Adc_WriteRegister((base + SADC_ANA_PARA_BASE((uint32)unitAnalogRegIndex)),
                          SADC_ANA_PARA_REFSEL_FIELD_OFFSET,
                          SADC_ANA_PARA_REFSEL_FIELD_SIZE, ADC_VREREF_RESET_VALUE);
        Adc_WriteRegister((base + SADC_ANA_PARA_BASE((uint32)unitAnalogRegIndex)),
                          SADC_ANA_PARA_SAMCTRL_FIELD_OFFSET,
                          SADC_ANA_PARA_SAMCTRL_FIELD_SIZE, ADC_SAMPLE_CTRL_RESET_VALUE);
    }

    /* #180 reset monitor register configuration */
    for (; monitorIndex < ADC_MONITOR_CNT; monitorIndex++)
    {
        Adc_WriteRegister((base + SADC_MNT_THRD_SINGLE_BASE((uint32)monitorIndex)),
                          SADC_MNT_THRD_SINGLE_HTHRD_FIELD_OFFSET,
                          SADC_MNT_THRD_SINGLE_HTHRD_FIELD_SIZE, ADC_MONITOR_RESET_MASK_VALUE);
    }

    Adc_WriteRegister((base + SADC_MNT_THRD_CONT_BASE),
                      SADC_MNT_THRD_CONT_HTHRD_FIELD_OFFSET,
                      SADC_MNT_THRD_CONT_HTHRD_FIELD_SIZE, ADC_MONITOR_RESET_MASK_VALUE);
#if (ADC_VOLTAGE_CALIBRATION == STD_ON)
    /* #190 disable calibration */
    Adc_Ip_CalibrationCfg(base, FALSE);
#endif /* #if (ADC_VOLTAGE_CALIBRATION == STD_ON) */

    /* #200 disable all interrupt status */
    Adc_WriteRegister((base + SADC_INT_STA_EN_BASE), SADC_INT_STA_EN_START_BIT_FIELD_OFFSET,
                      SADC_INT_STA_EN_ALL_VALID_BIT_FIELD_SIZE, ADC_INT_STA_EN_RESET_VALUE);
    /* #210 disable all interrupt signals */
    Adc_WriteRegister((base + SADC_INT_SIG_EN_BASE), SADC_INT_SIG_EN_START_BIT_FIELD_OFFSET,
                      SADC_INT_SIG_EN_ALL_VALID_BIT_FIELD_SIZE, ADC_INT_SIG_EN_RESET_VALUE);
    /* #220 clear all interrupts status */
    Adc_WriteRegister((base + SADC_INT_STA_BASE), SADC_INT_STA_START_BIT_FIELD_OFFSET,
                      SADC_INT_STA_ALL_VALID_BIT_FIELD_SIZE, SADC_INT_STA_ALL);
    /* #230 reset adc initialzation value */
    Adc_WriteRegister((base + SADC_INIT_BASE), SADC_INIT_VALUE_FIELD_OFFSET,
                      SADC_INIT_VALUE_FIELD_SIZE, ADC_INIT_INITVALUE_RESET_AND_CONFIG_VALUE);
    /* #240 reset adc analog soft reset */
    Adc_WriteRegister((base + SADC_SOFT_RST_BASE), SADC_SOFT_RST_ANA_RST_FIELD_OFFSET,
                      SADC_SOFT_RST_ANA_RST_FIELD_SIZE, ADC_BIT_DISABLE);
    /* #250 reset adc digital soft reset */
    Adc_WriteRegister((base + SADC_SOFT_RST_BASE), SADC_SOFT_RST_DIG_RST_FIELD_OFFSET,
                      SADC_SOFT_RST_DIG_RST_FIELD_SIZE, ADC_BIT_ENABLE);
    /* #260 release adc analog soft reset */
    Adc_WriteRegister((base + SADC_SOFT_RST_BASE), SADC_SOFT_RST_ANA_RST_FIELD_OFFSET,
                      SADC_SOFT_RST_ANA_RST_FIELD_SIZE, ADC_BIT_ENABLE);
    /* #270 release adc digital soft reset */
    Adc_WriteRegister((base + SADC_SOFT_RST_BASE), SADC_SOFT_RST_DIG_RST_FIELD_OFFSET,
                      SADC_SOFT_RST_DIG_RST_FIELD_SIZE, ADC_BIT_DISABLE);
    return;
}
#endif /* AdcDeInitApi enabled */
/** **************************************************************************************
 * \brief This function clears adc fifo.

 * \verbatim
 * Syntax             : static Adc_ErrorIdType Adc_Ip_ClearFifo(
 *                          Adc_RegisterBaseType unitBase,
 *                          Adc_TriggerSourceType trigSource,
 *                          boolean intFlag)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Reentrant

 * Parameters (in)    : unitBase - Adc Unit base address
 *                      trigSource - group trigger source
 *                      intFlag - flag indicates whether the function is called
 *                                in interrupt

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : clrFifoErrorStatus
 *                      0: No Error
 *                      ADC_E_FIFO_POLLING_TIMEOUT: bit set time out

 * Description        : This function clears adc fifo.
 * \endverbatim
 * Traceability       : SW_SM005
 *****************************************************************************************/
static Adc_ErrorIdType Adc_Ip_ClearFifo(Adc_RegisterBaseType unitBase,
                                        Adc_TriggerSourceType trigSource,
                                        boolean intFlag)
{
    /* record the time of reading fifo */
    uint8 readFifoTime = 0U;
    /* record the time of readint init bit */
    uint16 timeReadInitBit = 0U;
    /* error code number */
    Adc_ErrorIdType clrFifoErrorStatus = 0U;

    if ((ADC_TRIGG_SRC_SW == trigSource) && (TRUE == intFlag))
    {
        /* #10 reset adc digital soft reset */
        Adc_WriteRegister((unitBase + SADC_SOFT_RST_BASE), SADC_SOFT_RST_DIG_RST_FIELD_OFFSET,
                          SADC_SOFT_RST_DIG_RST_FIELD_SIZE, ADC_BIT_ENABLE);
        /* #20 release adc digital soft reset */
        Adc_WriteRegister((unitBase + SADC_SOFT_RST_BASE), SADC_SOFT_RST_DIG_RST_FIELD_OFFSET,
                          SADC_SOFT_RST_DIG_RST_FIELD_SIZE, ADC_BIT_DISABLE);
        /* #30 config adc initialzation value */
        Adc_WriteRegister((unitBase + SADC_INIT_BASE), SADC_INIT_VALUE_FIELD_OFFSET,
                          SADC_INIT_VALUE_FIELD_SIZE, ADC_INIT_INITVALUE_CLEAR_FIFO_CONFIG_VALUE);
        /* #40 set the adc initialization bit */
        Adc_WriteRegister((unitBase + SADC_INIT_BASE), SADC_INIT_START_FIELD_OFFSET,
                          SADC_INIT_START_FIELD_SIZE, ADC_BIT_ENABLE);

        /* #50 wait initial adc done */
        for (; timeReadInitBit < ADC_POLLING_TIMEOUT_VALUE; timeReadInitBit++)
        {
            /* #60 check whether adc init done bit set */
            if (FALSE != (REG_READ32(unitBase + SADC_INIT_BASE) & (ADC_BIT_ENABLE <<
                          SADC_INIT_DONE_FIELD_OFFSET)))
            {
#if (ADC_VOLTAGE_CALIBRATION == STD_ON)
                /* #70 config calibration */
                Adc_Ip_CalibrationCfg(unitBase, TRUE);
#endif /* #if (ADC_VOLTAGE_CALIBRATION == STD_ON) */
                break;
            } /* else not needed */
        }
    }
    else
    {
        for (; readFifoTime < ADC_FIFO_POLIING_MAX_TIME; readFifoTime++)
        {
            /* #10 read fifo */
            (void)REG_READ32(unitBase + SADC_SUB_FIFO_DATA_BASE(ADC_SUBFIFO_3));

            /* #20 check whether still conversion values in fifo */
            if (FALSE != (REG_READ32(unitBase + SADC_SUB_FIFO_BASE(ADC_SUBFIFO_3)) &
                          (ADC_BIT_ENABLE << SADC_SUB_FIFO_EMPTY_FIELD_OFFSET)))
            {
                break;
            } /* else not needed */
        }
    }

    AdcFaultInj_Adc_Ip_ClearFifoReadFail();
    AdcFaultInj_Adc_Ip_ClearFifoResetFail();

    /* check whether init bit set timeout */
    if (ADC_POLLING_TIMEOUT_VALUE <= timeReadInitBit)
    {
        clrFifoErrorStatus = ADC_E_FIFO_POLLING_TIMEOUT;
    }
    /* check whether clear fifo timeout */
    else if (ADC_FIFO_POLIING_MAX_TIME <= readFifoTime)
    {
        clrFifoErrorStatus = ADC_E_FIFO_POLLING_TIMEOUT;
    }
    else
    {
        /* do nothing */
    }

    return clrFifoErrorStatus;
}

static Adc_ErrorIdType Adc_UpdGrpStaForSingleOneShot(Adc_RegisterBaseType grpbelongUnitBase,
        Adc_GroupType singleOneGrpId)
{
    /* dma start status */
    Adc_ErrorIdType dmaFailStatus = 0U;

#if (ADC_HW_TRIGGER_API == STD_ON) /* AdcHwTriggerApi enabled */
    Adc_GroupConfigType singleOneGrpCfgPtr = Adc_GlobalConfigPtr->adcGroupCfgPtr[singleOneGrpId];
#endif /* AdcHwTriggerApi enabled */
    /* enter critical zone */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_08();
    Adc_AllGroupInfo[singleOneGrpId].groupStatus = ADC_STREAM_COMPLETED;
    Adc_AllGroupInfo[singleOneGrpId].groupConvFinishTime = 1U;
    Adc_AllGroupInfo[singleOneGrpId].groupConvFinishIndex = 1U;
    Adc_AllGroupInfo[singleOneGrpId].groupValueStatus = ADC_CONVERSION_UPDATE;
    /* exit critical zone */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_08();
#if (ADC_HW_TRIGGER_API == STD_ON) /* AdcHwTriggerApi enabled */

    if (ADC_TRIGG_SRC_HW == singleOneGrpCfgPtr.triggerSource)
    {
#if (ADC_DMA_SUPPORTED == STD_ON)

        if (ADC_E_DMA_START_FAIL == Adc_Ip_TriggerEnable(grpbelongUnitBase, singleOneGrpId))
        {
            dmaFailStatus = ADC_E_DMA_START_FAIL;
        } /* else not needed */

#else
        (void)Adc_Ip_TriggerEnable(grpbelongUnitBase, singleOneGrpId);
#endif /* #if (ADC_DMA_SUPPORTED == STD_ON) */
    } /* else not needed */

#endif /* AdcHwTriggerApi enabled */
    return dmaFailStatus;
}

static Adc_ErrorIdType Adc_UpdGrpStaForSingleConti(Adc_RegisterBaseType grpbelongUnitBase,
        Adc_GroupType singleContiGrpId)
{
    Adc_ErrorIdType dmaFailStatus = 0U;
    /* enter critical zone */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_08();
    Adc_AllGroupInfo[singleContiGrpId].groupStatus = ADC_STREAM_COMPLETED;
    Adc_AllGroupInfo[singleContiGrpId].groupConvFinishTime = 1U;
    Adc_AllGroupInfo[singleContiGrpId].groupConvFinishIndex = 1U;
    Adc_AllGroupInfo[singleContiGrpId].groupValueStatus = ADC_CONVERSION_UPDATE;
    /* exit critical zone */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_08();
#if (ADC_DMA_SUPPORTED == STD_ON)

    if (ADC_E_DMA_START_FAIL == Adc_Ip_TriggerEnable(grpbelongUnitBase, singleContiGrpId))
    {
        dmaFailStatus = ADC_E_DMA_START_FAIL;
    } /* else not needed */

#else
    (void)Adc_Ip_TriggerEnable(grpbelongUnitBase, singleContiGrpId);
#endif /* #if (ADC_DMA_SUPPORTED == STD_ON) */
    return dmaFailStatus;
}

static Adc_ErrorIdType Adc_UpdGrpStaForLinear(Adc_RegisterBaseType grpbelongUnitBase,
        Adc_GroupType linearGrpId)
{
    Adc_ErrorIdType dmaFailStatus = 0U;
    Adc_GroupConfigType linearGrpCfgPtr = Adc_GlobalConfigPtr->adcGroupCfgPtr[linearGrpId];
    /* enter critical zone */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_08();
    Adc_AllGroupInfo[linearGrpId].groupConvFinishTime += 1U;
    Adc_AllGroupInfo[linearGrpId].groupConvFinishIndex += 1U;
    Adc_AllGroupInfo[linearGrpId].groupValueStatus = ADC_CONVERSION_UPDATE;

    if (linearGrpCfgPtr.samplingTime > Adc_AllGroupInfo[linearGrpId].groupConvFinishTime)
    {
        Adc_AllGroupInfo[linearGrpId].groupStatus = ADC_COMPLETED;
        /* exit critical zone */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_08();
#if (ADC_DMA_SUPPORTED == STD_ON)

        if (ADC_E_DMA_START_FAIL == Adc_Ip_TriggerEnable(grpbelongUnitBase, linearGrpId))
        {
            dmaFailStatus = ADC_E_DMA_START_FAIL;
        } /* else not needed */

#else
        (void)Adc_Ip_TriggerEnable(grpbelongUnitBase, linearGrpId);
#endif /* #if (ADC_DMA_SUPPORTED == STD_ON) */
    }
    else
    {
        Adc_AllGroupInfo[linearGrpId].groupStatus = ADC_STREAM_COMPLETED;
        /* exit critical zone */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_08();
    }

    return dmaFailStatus;
}

static Adc_ErrorIdType Adc_UpdGrpStaForCircular(Adc_RegisterBaseType grpbelongUnitBase,
        Adc_GroupType cricularGrpId)
{
    Adc_ErrorIdType dmaFailStatus = 0U;
    const Adc_GroupConfigType *circularGrpCfgPtr = &Adc_GlobalConfigPtr->adcGroupCfgPtr[cricularGrpId];
    /* enter critical zone */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_08();
    Adc_AllGroupInfo[cricularGrpId].groupConvFinishTime += 1U;
    Adc_AllGroupInfo[cricularGrpId].groupConvFinishIndex += 1U;
    Adc_AllGroupInfo[cricularGrpId].groupValueStatus = ADC_CONVERSION_UPDATE;

    if (circularGrpCfgPtr->samplingTime > Adc_AllGroupInfo[cricularGrpId].groupConvFinishTime)
    {
        Adc_AllGroupInfo[cricularGrpId].groupStatus = ADC_COMPLETED;
        /* exit critical zone */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_08();
#if (ADC_DMA_SUPPORTED == STD_ON)

        if (ADC_E_DMA_START_FAIL == Adc_Ip_TriggerEnable(grpbelongUnitBase, cricularGrpId))
        {
            dmaFailStatus = ADC_E_DMA_START_FAIL;
        } /* else not needed */

#else
        (void)Adc_Ip_TriggerEnable(grpbelongUnitBase, cricularGrpId);
#endif /* #if (ADC_DMA_SUPPORTED == STD_ON) */
    }
    else
    {
        Adc_AllGroupInfo[cricularGrpId].groupStatus = ADC_STREAM_COMPLETED;
        Adc_AllGroupInfo[cricularGrpId].groupConvFinishTime = circularGrpCfgPtr->samplingTime;
        /* exit critical zone */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_08();
#if (ADC_DMA_SUPPORTED == STD_ON)

        if (ADC_E_DMA_START_FAIL == Adc_Ip_TriggerEnable(grpbelongUnitBase, cricularGrpId))
        {
            dmaFailStatus = ADC_E_DMA_START_FAIL;
        } /* else not needed */

#else
        (void)Adc_Ip_TriggerEnable(grpbelongUnitBase, cricularGrpId);
#endif /* #if (ADC_DMA_SUPPORTED == STD_ON) */
    }

    return dmaFailStatus;
}
/** **************************************************************************************
 * \brief This function init Adc driver in Ip level.

 * \verbatim
 * Syntax             : Adc_ErrorIdType Adc_Ip_Init(
 *                          const Adc_ConfigType* adcIpCfgPtr)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : adcIpCfgPtr - Pointer to configuration set

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : ADC_NO_ERROR:   no error
 *                      Others:         config failed

 * Description        : This function init Adc driver in Ip level
 * \endverbatim
 * Traceability       : SWSR_ADC_053 SWSR_ADC_054 SWSR_ADC_055
 *****************************************************************************************/
Adc_ErrorIdType Adc_Ip_Init(const Adc_ConfigType *adcIpCfgPtr)
{
    /* hardware Unit index */
    Adc_HwUnitType uintIndex = 0U;
    /* error code number */
    Adc_ErrorIdType errorStatus = 0U;
#if (ADC_DMA_SUPPORTED == STD_ON)
    /* group index */
    Adc_GroupType groupIndex = 0U;
#endif
    /* set adc uint base */
    Adc_Ip_SetBaseAddr();

    /* config adc channel mux */
    Adc_ScrSetBit(ADC_AMUX_ADC1_CH5N_CSEL_3, ADC_BIT_DISABLE);
    Adc_ScrSetBit(ADC_AMUX_ADC1_CH5P_CSEL_3, ADC_BIT_DISABLE);
    Adc_ScrSetBit(ADC_AMUX_ADC2_CH4N_CSEL_3, ADC_BIT_DISABLE);
    Adc_ScrSetBit(ADC_AMUX_ADC2_CH4P_CSEL_3, ADC_BIT_DISABLE);
    Adc_ScrSetBit(ADC_AMUX_ADC2_CH5N_CSEL_3, ADC_BIT_DISABLE);
    Adc_ScrSetBit(ADC_AMUX_ADC2_CH5P_CSEL_3, ADC_BIT_DISABLE);
    Adc_ScrSetBit(ADC_AMUX_ADC2_CH6N_CSEL_3, ADC_BIT_DISABLE);
    Adc_ScrSetBit(ADC_AMUX_ADC3_CH5N_CSEL_3, ADC_BIT_DISABLE);
    Adc_ScrSetBit(ADC_AMUX_ADC3_CH5P_CSEL_3, ADC_BIT_DISABLE);



    for (; uintIndex < adcIpCfgPtr->unitCount; uintIndex++)
    {
        /* #20 config hw unit */
        Adc_Ip_ConfigUnit(adcIpCfgPtr, uintIndex);
        /* #30 config group,meanwhile,entry will be configured */
        Adc_Ip_ConfigGroup(adcIpCfgPtr, uintIndex);
        /* #30 config unit analog */
        Adc_Ip_ConfigAnalog(adcIpCfgPtr, uintIndex);

        /* #40 reset digital and analog */
        if (ADC_E_INIT_FAIL == Adc_Ip_ConfigReset(adcIpCfgPtr, uintIndex))
        {
            /* init time out */
            errorStatus = ADC_E_INIT_FAIL;
        }

#if (ADC_DMA_SUPPORTED == STD_ON)
        /* 50 check whether current unit needs dma */
        else if (ADC_UNIT_DMA_USED == adcIpCfgPtr->adcUnitCfgPtr[uintIndex].unitDmaUsed)
        {
            /* 60 check whether dma resourses are allocated successfully */
            if (ADC_E_DMA_CFG_FAIL == Adc_Ip_ConfigDma(adcIpCfgPtr,
                    adcIpCfgPtr->adcUnitCfgPtr[uintIndex].hwModuleIndex))
            {
                errorStatus = ADC_E_DMA_CFG_FAIL;
            } /* else not needed */
        }
        else
        {
            /* do nothing */
        }

        /* check whether loop needed to be end */
        if (0U != errorStatus)
        {
            break;
        }

#endif
    }

#if (ADC_DMA_SUPPORTED == STD_ON)

    /* Dma config fail happened */
    if (ADC_E_DMA_CFG_FAIL == errorStatus)
    {
        for (; groupIndex < adcIpCfgPtr->groupCountAllUnit; groupIndex++)
        {
            if (adcIpCfgPtr->adcGroupCfgPtr[groupIndex].groupTransferType == ADC_DMA_MODE &&
                    adcIpCfgPtr->adcGroupCfgPtr[groupIndex].priv != NULL_PTR)
            {
                /* release Dma channel */
                /*PRQA S 0316  1*/
                (void)Dma_ReleaseChannel((Dma_ChannelConfigType *)adcIpCfgPtr->adcGroupCfgPtr[groupIndex].priv);
            }
        }

        errorStatus = ADC_E_INIT_FAIL;
    }

#endif

    return errorStatus;
}
#if (ADC_DEINIT_API == STD_ON) /* AdcDeInitApi enabled */
/** **************************************************************************************
 * \brief This function returns Adc register to power set state.

 * \verbatim
 * Syntax             : Adc_ErrorIdType Adc_Ip_DeInit(
 *                          void)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : None

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : ADC_E_FIFO_POLLING_TIMEOUT: Fifo clear time out
 *                      Other: No error

 * Description        : This function returns Adc register to power set state.
 * \endverbatim
 * Traceability       : SWSR_ADC_067
 *****************************************************************************************/
Adc_ErrorIdType Adc_Ip_DeInit(void)
{
    Adc_ErrorIdType errorStatus = 0U;
    /* hardware Unit index */
    Adc_HwUnitType uintIndex = 0;

    /* #10 reset adc analog part to full power state */
    Adc_Ip_SetPowerState(ADC_FULL_POWER);

    for (; uintIndex < Adc_GlobalConfigPtr->unitCount; uintIndex++)
    {

#if (ADC_DMA_SUPPORTED == STD_ON) /* AdcEnableDmaTransferMode enabled */

        /* #20 release all dma resources */
        if (ADC_NO_ERROR != Adc_Ip_DeInitDma(uintIndex))
        {
            errorStatus = ADC_E_DEINIT_FAIL;
        }
        else
#endif /* AdcEnableDmaTransferMode enabled */
        {
            /* #30 reset all adc register value */
            Adc_Ip_DeInitUnit(uintIndex);
        }
    }

#if (ADC_DMA_SUPPORTED == STD_ON)

    if (ADC_E_DEINIT_FAIL != errorStatus)
    {
#endif /* #if (ADC_DMA_SUPPORTED == STD_ON) */
        /* #40 reset all adc register base */
        Adc_Ip_ResetBaseAddr();
#if (ADC_DMA_SUPPORTED == STD_ON)
    } /* else not needed */

#endif /* #if (ADC_DMA_SUPPORTED == STD_ON) */

    return errorStatus;
}
#endif /* AdcDeInitApi enabled */
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) /* AdcEnableStartStopGroupApi enabled */
/** **************************************************************************************
 * \brief This function starts all channels converison of the requested Adc group.

 * \verbatim
 * Syntax             : Adc_ErrorIdType Adc_Ip_StartGroupConversion(
 *                          Adc_GroupType ipGroupId)

 * Service ID[hex]    : None

 * Sync/Async         : Asynchronous

 * Reentrancy         : Reentrant

 * Parameters (in)    : ipGroupId - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : ADC_E_FIFO_POLLING_TIMEOUT: Fifo clear time out
 *                      Other: No error

 * Description        : This function starts all channels converison of the
 *                      requested Adc group.
 * \endverbatim
 * Traceability       : SWSR_ADC_074
 *****************************************************************************************/
Adc_ErrorIdType Adc_Ip_StartGroupConversion(Adc_GroupType ipGroupId)
{
    /* error code number */
    Adc_ErrorIdType errorStatus = 0U;
    /* group configuration */
    const Adc_GroupConfigType *groupCfgPtr = &Adc_GlobalConfigPtr->adcGroupCfgPtr[ipGroupId];
    /* unit base address */
    Adc_RegisterBaseType base = Adc_BaseAddress[groupCfgPtr->belongUnitPhysicalId];
#ifndef SEMIDRIVE_E3_LITE_SERIES
#if (ADC_OVERVOLTAGE_DETECT == STD_ON) /* AdcOverVoltageDetect enabled */
    /* group index */
    Adc_ChannelType groupChannelIndex = 0U;
    /* channel config */
    const Adc_ChannelConfigType *chnlCfgPtr = groupCfgPtr->groupChannelCfgPtr;
    /* channel number id*/
    uint8 chnlNumber;
    /* channel end */
    uint8 chnlEnd;
    /* channel mux id*/
    uint8 chnlMux;
    /* variable to point to target apad start address */
    const Adc_ScrStartBitType *scrStartBitAddr;
    /* variable to save target apad start address */
    Adc_ScrStartBitType scrStartBit;

    for (; groupChannelIndex < groupCfgPtr->channelCount; groupChannelIndex++)
    {
        /* get channel number id */
        chnlNumber = chnlCfgPtr[groupChannelIndex].physicalChannelId / 2U;
        /* get channel end */
        chnlEnd = chnlCfgPtr[groupChannelIndex].physicalChannelId % 2U;
        /* get channel mux id*/
        chnlMux = chnlCfgPtr[groupChannelIndex].channelMuxId;
        /* point to target apad start address */
        scrStartBitAddr = Adc_ChnlScrAddress[groupCfgPtr->belongUnitPhysicalId];
        /* get target apad start address */
        /*PRQA S 0488  1*/
        scrStartBit = *(scrStartBitAddr + (chnlNumber * ADC_CHNL_MUX_MAX) + (chnlMux * 2U) + chnlEnd);
        /* set Apad of all channels with Pull-Down 30k */
        Adc_ScrSetBit(scrStartBit, ADC_CHNL_SCR_PULL_DOWN_30K_OHM);
        /* mark all channels are normal */
        Adc_AllGroupInfo[ipGroupId].channelDetectStatus[groupChannelIndex] = ADC_CHANNE_DET_NORMAL;
    }

    /* mark the detectation has started */
    Adc_AllGroupInfo[ipGroupId].groupDetectStatus = ADC_GROUP_UNDETECTED;
#endif /* AdcOverVoltageDetect enabled */
#endif

#if (ADC_DMA_SUPPORTED == STD_ON)

    /* #10 check whether group is dma tranfer mode */
    if (ADC_DMA_MODE == groupCfgPtr->groupTransferType)
    {
        /* #20 start dma transmission */
        if (ADC_E_DMA_START_FAIL == Adc_Ip_StartDmaTransmission(ipGroupId))
        {
            /* start dma failed */
            errorStatus = ADC_E_START_FAIL;
        } /* else not needed */

        AdcFaultInj_Adc_Ip_TriggerEnableDmaStartFail();
    }
    else
#endif /* ADC_DMA_SUPPORTED == STD_ON */
    {
        /* interrupt transfer mode */
        /* #30 clear fifo and check whether timeout happens */
        if (ADC_E_FIFO_POLLING_TIMEOUT == Adc_Ip_ClearFifo(base, ADC_TRIGG_SRC_SW, FALSE))
        {
            /* clear fifo timeout */
            errorStatus = ADC_E_START_FAIL;
        }
        else
        {
            /* #40 config adc subfifo0 connected to used RCx */
            Adc_WriteRegister(base + SADC_SUB_FIFO_BASE(ADC_SUBFIFO_3),
                              SADC_SUB_FIFO_SUB_RC_EN_FIELD_OFFSET,
                              SADC_SUB_FIFO_SUB_RC_EN_FIELD_SIZE, 0x1UL << (3U - (uint8)groupCfgPtr->groupRcRchtIndex + 1U));
            /* #50 config group fifo water mark number of channel in group */
            Adc_WriteRegister(base + SADC_SUB_FIFO_BASE(ADC_SUBFIFO_3),
                              SADC_SUB_FIFO_SUB_THRD_FIELD_OFFSET,
                              SADC_SUB_FIFO_SUB_THRD_FIELD_SIZE, ((uint32)groupCfgPtr->channelCount + 1UL));
            /* #60 enable fifo watermark int signal */
            Adc_WriteRegister(base + SADC_INT_SIG_EN_BASE, SADC_INT_SIG_EN_WATER_MARK_SUB_3_FIELD_OFFSET,
                              SADC_INT_SIG_EN_WATER_MARK_SUB_3_FIELD_SIZE, 1U);
            /* #70 enable fifo watermark int status */
            Adc_WriteRegister(base + SADC_INT_STA_EN_BASE, SADC_INT_STA_EN_WATER_MARK_SUB_3_FIELD_OFFSET,
                              SADC_INT_STA_EN_WATER_MARK_SUB_3_FIELD_SIZE, 1U);
        }
    }

    /* normal situation */
    if (ADC_E_START_FAIL != errorStatus)
    {
        /* enter critical zone */
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_00();
        /* #80 set trg_start bit to enable rc timmer */
        Adc_WriteRegister(base + SADC_RC_BASE((uint32)groupCfgPtr->groupRcRchtIndex - 1U),
                          SADC_RC_TRG_START_FIELD_OFFSET,
                          SADC_RC_TRG_START_FIELD_SIZE, 1U);
        /* #90 change group conversion status to not finished */
        Adc_AllGroupInfo[ipGroupId].groupConvStatus = ADC_NOT_YET_FINISHED_CONVERTED;
        /* exit critical zone */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_00();
        AdcFaultInj_Adc_Ip_StartInterruptPreemption();
    } /* else not needed */

    return errorStatus;
}
/** **************************************************************************************
 * \brief This function stops all conversions of channels of the requested Adc Group.
 * \verbatim
 * Syntax             : Adc_ErrorIdType Adc_Ip_StopGroupConversion(
 *                          Adc_GroupType ipGroupId)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Reentrant

 * Parameters (in)    : ipGroupId - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : ADC_E_FIFO_POLLING_TIMEOUT: Fifo clear time out
 *                      Others: No errors

 * Description        : This function stops all conversions of channels of the
 *                      requested Adc Group.
 * \endverbatim
 * Traceability       : SWSR_ADC_085 SWSR_ADC_087
 *****************************************************************************************/
Adc_ErrorIdType Adc_Ip_StopGroupConversion(Adc_GroupType ipGroupId)
{
    /* error code number */
    Adc_ErrorIdType errorStatus = 0U;
    /* group configuration */
    const Adc_GroupConfigType *groupCfgPtr = &Adc_GlobalConfigPtr->adcGroupCfgPtr[ipGroupId];
    /* unit base address */
    Adc_RegisterBaseType base = Adc_BaseAddress[groupCfgPtr->belongUnitPhysicalId];
#ifndef SEMIDRIVE_E3_LITE_SERIES
#if (ADC_OVERVOLTAGE_DETECT == STD_ON) /* AdcOverVoltageDetect enabled */
    /* group index */
    Adc_ChannelType groupChannelIndex = 0U;
    /* channel config */
    const Adc_ChannelConfigType *chnlCfgPtr = groupCfgPtr->groupChannelCfgPtr;
    /* channel number id*/
    uint8 chnlNumber;
    /* channel end */
    uint8 chnlEnd;
    /* channel mux id*/
    uint8 chnlMux;
    /* variable to point to target apad start address */
    const Adc_ScrStartBitType *scrStartBitAddr;
    /* variable to save target apad start address */
    Adc_ScrStartBitType scrStartBit;

    for (; groupChannelIndex < groupCfgPtr->channelCount; groupChannelIndex++)
    {
        /* get channel number id */
        chnlNumber = chnlCfgPtr[groupChannelIndex].physicalChannelId / 2U;
        /* get channel end */
        chnlEnd = chnlCfgPtr[groupChannelIndex].physicalChannelId % 2U;
        /* get channel mux id*/
        chnlMux = chnlCfgPtr[groupChannelIndex].channelMuxId;
        /* point to target apad start address */
        scrStartBitAddr = Adc_ChnlScrAddress[groupCfgPtr->belongUnitPhysicalId];
        /* get target apad start address */
        /*PRQA S 0488  1*/
        scrStartBit = *(scrStartBitAddr + (chnlNumber * ADC_CHNL_MUX_MAX) + (chnlMux * 2U) + chnlEnd);
        /* set Apad of all channels with Pull-Down 300ohm */
        Adc_ScrSetBit(scrStartBit, ADC_CHNL_SCR_PULL_DOWN_300_OHM);
        /* mark all channels are normal */
        Adc_AllGroupInfo[ipGroupId].channelDetectStatus[groupChannelIndex] = ADC_CHANNE_DET_NORMAL;
    }

    /* mark the detectation has started */
    Adc_AllGroupInfo[ipGroupId].groupDetectStatus = ADC_GROUP_UNDETECTED;
#endif /* AdcOverVoltageDetect enabled */
#endif
    /* enter critical zone */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_01();
    /* #10 reset trg_start bit to disable rc timmer */
    Adc_WriteRegister((base + SADC_RC_BASE((uint32)groupCfgPtr->groupRcRchtIndex - 1U)),
                      SADC_RC_TRG_START_FIELD_OFFSET,
                      SADC_RC_TRG_START_FIELD_SIZE, 0U);
    /* #20 change group conversion status to finished */
    Adc_AllGroupInfo[ipGroupId].groupConvStatus = ADC_ALREADY_FINISHED_CONVERTED;
    /* exit critical zone */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_01();
#if (ADC_DMA_SUPPORTED == STD_ON) /* AdcEnableDmaTransferMode enabled */

    /* #30 check whether group is dma tranfer mode */
    if (ADC_DMA_MODE == groupCfgPtr->groupTransferType)
    {
        /* #40 stop dma transmission */
        if (ADC_E_DMA_STOP_FAIL == Adc_Ip_StopDmaTransmission(ipGroupId))
        {
            /* stop dma transmission failed */
            errorStatus = ADC_E_STOP_FAIL;
        } /* else not needed */

        AdcFaultInj_Adc_Ip_TriggerDisableDmaStopFail();
    }
    else
#endif /* AdcEnableDmaTransferMode enabled */
    {
        /* interrupt tranfer mode */
        /* #50 config adc subfifo0 disconnected to used RCx */
        Adc_WriteRegister((base + SADC_SUB_FIFO_BASE(ADC_SUBFIFO_3)),
                          SADC_SUB_FIFO_SUB_RC_EN_FIELD_OFFSET,
                          SADC_SUB_FIFO_SUB_RC_EN_FIELD_SIZE, 0UL << (3U - (uint8)groupCfgPtr->groupRcRchtIndex + 1U));
        /* #60 clear int */
        Adc_ClearIntEnableAndStatus(base);

        /* #70 check whether clear fifo timeout */
        if (ADC_E_FIFO_POLLING_TIMEOUT == Adc_Ip_ClearFifo(base, ADC_TRIGG_SRC_SW, FALSE))
        {
            /* clear fifo timeout */
            errorStatus = ADC_E_STOP_FAIL;
        } /* else not needed */
    }

    /* to prevent errorStatus from no use */
    ADC_DUMMY_STATEMENT(errorStatus);
    return errorStatus;
}
#endif /* AdcEnableStartStopGroupApi enabled */
#if (ADC_HW_TRIGGER_API == STD_ON) /* AdcHwTriggerApi enabled */
/** **************************************************************************************
 * \brief This function enables the hardware trigger for the requested ADC Channel group
 *        in Ip level.

 * \verbatim
 * Syntax             : Adc_ErrorIdType Adc_Ip_EnableHardwareTrigger(
 *                          Adc_GroupType ipGroupId)

 * Service ID[hex]    : None

 * Sync/Async         : Asynchronous

 * Reentrancy         : Reentrant

 * Parameters (in)    : ipGroupId - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : ADC_E_FIFO_POLLING_TIMEOUT: Fifo clear time out
 *                      Others: No errors

 * Description        : This function enables the hardware trigger for the requested
 *                      ADC Channel group in Ip level.
 * \endverbatim
 * Traceability       : SWSR_ADC_167
 *****************************************************************************************/
Adc_ErrorIdType Adc_Ip_EnableHardwareTrigger(Adc_GroupType ipGroupId)
{
    /* group configuration */
    const Adc_GroupConfigType *groupCfgPtr = &Adc_GlobalConfigPtr->adcGroupCfgPtr[ipGroupId];
    /* unit base address */
    Adc_RegisterBaseType base = Adc_BaseAddress[groupCfgPtr->belongUnitPhysicalId];
    /* error code number */
    Adc_ErrorIdType errorStatus = 0U;
#ifndef SEMIDRIVE_E3_LITE_SERIES
#if (ADC_OVERVOLTAGE_DETECT == STD_ON) /* AdcOverVoltageDetect enabled */
    /* group index */
    Adc_ChannelType groupChannelIndex = 0U;
    /* channel config */
    const Adc_ChannelConfigType *chnlCfgPtr = groupCfgPtr->groupChannelCfgPtr;
    /* channel number id*/
    uint8 chnlNumber;
    /* channel end */
    uint8 chnlEnd;
    /* channel mux id*/
    uint8 chnlMux;
    /* variable to point to target apad start address */
    const Adc_ScrStartBitType *scrStartBitAddr;
    /* variable to save target apad start address */
    Adc_ScrStartBitType scrStartBit;

    for (; groupChannelIndex < groupCfgPtr->channelCount; groupChannelIndex++)
    {
        /* get channel number id */
        chnlNumber = chnlCfgPtr[groupChannelIndex].physicalChannelId / 2U;
        /* get channel end */
        chnlEnd = chnlCfgPtr[groupChannelIndex].physicalChannelId % 2U;
        /* get channel mux id*/
        chnlMux = chnlCfgPtr[groupChannelIndex].channelMuxId;
        /* point to target apad start address */
        scrStartBitAddr = Adc_ChnlScrAddress[groupCfgPtr->belongUnitPhysicalId];
        /* get target apad start address */
        /*PRQA S 0488  1*/
        scrStartBit = *(scrStartBitAddr + (chnlNumber * ADC_CHNL_MUX_MAX) + (chnlMux * 2U) + chnlEnd);
        /* set Apad of all channels with Pull-Down 30k */
        Adc_ScrSetBit(scrStartBit, ADC_CHNL_SCR_PULL_DOWN_30K_OHM);
        /* mark all channels are normal */
        Adc_AllGroupInfo[ipGroupId].channelDetectStatus[groupChannelIndex] = ADC_CHANNE_DET_NORMAL;
    }

    /* mark the detectation has started */
    Adc_AllGroupInfo[ipGroupId].groupDetectStatus = ADC_GROUP_UNDETECTED;
#endif /* AdcOverVoltageDetect enabled */
#endif
#if (ADC_DMA_SUPPORTED == STD_ON) /* AdcEnableDmaTransferMode enabled */

    /* #10 check whether group is dma mode */
    if (ADC_DMA_MODE == groupCfgPtr->groupTransferType)
    {
        /* #20 start dma transmission */
        if (ADC_E_DMA_START_FAIL == Adc_Ip_StartDmaTransmission(ipGroupId))
        {
            /* start dma failed */
            errorStatus = ADC_E_START_FAIL;
        } /* else not needed */
    }
    else
#endif /* AdcEnableDmaTransferMode enabled */
    {
        /* interrupt tranfer mode */
        /* #30 clear fifo and check whether timeout happens */
        if (ADC_E_FIFO_POLLING_TIMEOUT == Adc_Ip_ClearFifo(base, ADC_TRIGG_SRC_HW, FALSE))
        {
            /* clear fifo timeout */
            errorStatus = ADC_E_START_FAIL;
        }
        else
        {
            /* #40 config adc subfifo0 connected to used rcht */
            Adc_WriteRegister(base + SADC_SUB_FIFO_BASE(ADC_SUBFIFO_3),
                              SADC_SUB_FIFO_SUB_RC_EN_FIELD_OFFSET,
                              SADC_SUB_FIFO_SUB_RC_EN_FIELD_SIZE, (0x1UL << 0x4U));
            /* #50 config group fifo water mark number of channel in group */
            Adc_WriteRegister(base + SADC_SUB_FIFO_BASE(ADC_SUBFIFO_3),
                              SADC_SUB_FIFO_SUB_THRD_FIELD_OFFSET,
                              SADC_SUB_FIFO_SUB_THRD_FIELD_SIZE, groupCfgPtr->channelCount);
            /* #60 enable fifo watermark int signal */
            Adc_WriteRegister(base + SADC_INT_SIG_EN_BASE, SADC_INT_SIG_EN_WATER_MARK_SUB_3_FIELD_OFFSET,
                              SADC_INT_SIG_EN_WATER_MARK_SUB_3_FIELD_SIZE, 1U);
            /* #70 enable fifo watermark int status */
            Adc_WriteRegister(base + SADC_INT_STA_EN_BASE, SADC_INT_STA_EN_WATER_MARK_SUB_3_FIELD_OFFSET,
                              SADC_INT_STA_EN_WATER_MARK_SUB_3_FIELD_SIZE, 1U);
        }
    }

    /* normal situation */
    if (ADC_E_START_FAIL != errorStatus)
    {
        /* enter critical zone */
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_02();
        /* #80 set sadc_htc ready 1 to ready for external trigger */
        Adc_WriteRegister(base + SADC_HTC_BASE, SADC_HTC_READY_FIELD_OFFSET, SADC_HTC_READY_FIELD_SIZE, 1U);
        /* #90 change group conversion status to not finished */
        Adc_AllGroupInfo[ipGroupId].groupConvStatus = ADC_NOT_YET_FINISHED_CONVERTED;
        /* exit critical zone */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_02();
        AdcFaultInj_Adc_Ip_StartInterruptPreemption();
    } /* else not needed */

    return errorStatus;
}
/** **************************************************************************************
 * \brief This function disables the hardware trigger for the requested
 *        ADC Channel group.

 * \verbatim
 * Syntax             : Adc_ErrorIdType Adc_Ip_DisableHardwareTrigger(
 *                          Adc_GroupType ipGroupId)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Reentrant

 * Parameters (in)    : ipGroupId - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : ADC_E_FIFO_POLLING_TIMEOUT: Fifo clear time out
 *                      Others: No errors

 * Description        : This function disables the hardware trigger for the requested
 *                      ADC Channel group.
 * \endverbatim
 * Traceability       : SWSR_ADC_180
 *****************************************************************************************/
Adc_ErrorIdType Adc_Ip_DisableHardwareTrigger(Adc_GroupType ipGroupId)
{
    /* group configuration */
    const Adc_GroupConfigType *groupCfgPtr = &Adc_GlobalConfigPtr->adcGroupCfgPtr[ipGroupId];
    /* unit base address */
    Adc_RegisterBaseType base = Adc_BaseAddress[groupCfgPtr->belongUnitPhysicalId];
    /* error code number */
    Adc_ErrorIdType errorStatus = 0U;
#ifndef SEMIDRIVE_E3_LITE_SERIES
#if (ADC_OVERVOLTAGE_DETECT == STD_ON) /* AdcOverVoltageDetect enabled */
    /* group index */
    Adc_ChannelType groupChannelIndex = 0U;
    /* channel config */
    const Adc_ChannelConfigType *chnlCfgPtr = groupCfgPtr->groupChannelCfgPtr;
    /* channel number id*/
    uint8 chnlNumber;
    /* channel end */
    uint8 chnlEnd;
    /* channel mux id*/
    uint8 chnlMux;
    /* variable to point to target apad start address */
    const Adc_ScrStartBitType *scrStartBitAddr;
    /* variable to save target apad start address */
    Adc_ScrStartBitType scrStartBit;

    for (; groupChannelIndex < groupCfgPtr->channelCount; groupChannelIndex++)
    {
        /* get channel number id */
        chnlNumber = chnlCfgPtr[groupChannelIndex].physicalChannelId / 2U;
        /* get channel end */
        chnlEnd = chnlCfgPtr[groupChannelIndex].physicalChannelId % 2U;
        /* get channel mux id*/
        chnlMux = chnlCfgPtr[groupChannelIndex].channelMuxId;
        /* point to target apad start address */
        scrStartBitAddr = Adc_ChnlScrAddress[groupCfgPtr->belongUnitPhysicalId];
        /* get target apad start address */
        /*PRQA S 0488  1*/
        scrStartBit = *(scrStartBitAddr + (chnlNumber * ADC_CHNL_MUX_MAX) + (chnlMux * 2U) + chnlEnd);
        /* set Apad of all channels with Pull-Down 300 ohm */
        Adc_ScrSetBit(scrStartBit, ADC_CHNL_SCR_PULL_DOWN_300_OHM);
        /* mark all channels are normal */
        Adc_AllGroupInfo[ipGroupId].channelDetectStatus[groupChannelIndex] = ADC_CHANNE_DET_NORMAL;
    }

    /* mark the detectation has started */
    Adc_AllGroupInfo[ipGroupId].groupDetectStatus = ADC_GROUP_UNDETECTED;
#endif /* AdcOverVoltageDetect enabled */
#endif
    /* enter critical zone */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_03();
    /* #10 resset sadc_htc ready 0 to shield external trigger */
    Adc_WriteRegister(base + SADC_HTC_BASE, SADC_HTC_READY_FIELD_OFFSET, SADC_HTC_READY_FIELD_SIZE, 0U);
    /* #20 change group conversion status to finished */
    Adc_AllGroupInfo[ipGroupId].groupConvStatus = ADC_ALREADY_FINISHED_CONVERTED;
    /* exit critical zone */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_03();
#if (ADC_DMA_SUPPORTED == STD_ON) /* AdcEnableDmaTransferMode enabled */

    /* #30 check whether group is dma transfer mode */
    if (ADC_DMA_MODE == groupCfgPtr->groupTransferType)
    {
        /* #40 stop dma transmission */
        if (ADC_E_DMA_STOP_FAIL == Adc_Ip_StopDmaTransmission(ipGroupId))
        {
            /* stop dma transmission failed */
            errorStatus = ADC_E_STOP_FAIL;
        } /* else not needed */
    }
    else
#endif /* AdcEnableDmaTransferMode enabled */
    {
        /* interrupt transfer mode */
        /* #50 config adc subfifo0 disconnected to used rcht */
        Adc_WriteRegister(base + SADC_SUB_FIFO_BASE(ADC_SUBFIFO_3),
                          SADC_SUB_FIFO_SUB_RC_EN_FIELD_OFFSET,
                          SADC_SUB_FIFO_SUB_RC_EN_FIELD_SIZE, (0UL << 4U));
        /* #60 clear int */
        Adc_ClearIntEnableAndStatus(base);

        /* #70 check whether clear fifo time out */
        if (ADC_E_FIFO_POLLING_TIMEOUT == Adc_Ip_ClearFifo(base, ADC_TRIGG_SRC_HW, FALSE))
        {
            /* clear fifo time out */
            errorStatus = ADC_E_STOP_FAIL;
        } /* else not needed */
    }

    /* to prevent errorStatus from no use */
    ADC_DUMMY_STATEMENT(errorStatus);
    return errorStatus;
}
#endif /* AdcHwTriggerApi enabled */

static Adc_ErrorIdType Adc_CheckGroupStatusInInt(Adc_GroupType grpId)
{
    /* error code number */
    Adc_ErrorIdType errorStatus = 0U;

    /* #10 check whether group conversion status is already finished */
    if (ADC_ALREADY_FINISHED_CONVERTED == Adc_AllGroupInfo[grpId].groupConvStatus)
    {
        /* the group should not trigger adc interrupt */
        errorStatus = ADC_E_INT_SOURCE;
    }
    /* #20 check whether group status is ADC_IDLE */
    else if (ADC_IDLE == Adc_AllGroupInfo[grpId].groupStatus)
    {
        /* the group should not trigger adc interrupt */
        errorStatus = ADC_E_INT_SOURCE;
    }
    else
    {
        /* do nothing */
    }

    /* to prevent errorStatus from no use */
    ADC_DUMMY_STATEMENT(errorStatus);
    return errorStatus;
}
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON) /* AdcGrpNotifCapability enabled */
/** **************************************************************************************
 * \brief This function checks whether group notification is enabled or not.

 * \verbatim
 * Syntax             : static void Adc_CheckNotifInInterrupt(
 *                          Adc_GroupType grpNotifId)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Reentrant

 * Parameters (in)    : grpNotifId - Numeric ID of requested ADC Channel group

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function checks whether group notification is enabled or not.
 * \endverbatim
 * Traceability       : SWSR_ADC_018 SWSR_ADC_157 SWSR_ADC_158 SWSR_ADC_159 SWSR_ADC_161
 *****************************************************************************************/
static void Adc_CheckNotifInInterrupt(Adc_GroupType grpNotifId)
{
    /* #10 check whether group notification is enabled */
    if (ADC_NOTIFICATION_ENABLED == Adc_AllGroupInfo[grpNotifId].groupNotifStatus)
    {
        /* #20 excute group notification if noitf is not NULL_PTR */
        if (NULL_PTR != Adc_GlobalConfigPtr->adcGroupCfgPtr[grpNotifId].notificationPtr)
        {
            Adc_GlobalConfigPtr->adcGroupCfgPtr[grpNotifId].notificationPtr();
        } /* else not needed */
    } /* else not needed */

    return;
}
#endif /* AdcGrpNotifCapability enabled */

static Adc_ErrorIdType Adc_Ip_UpdateInInterrupt(Adc_RegisterBaseType hardwareUnitbase,
        Adc_GroupType grpStatusId)
{
    /* group configuration */
    const Adc_GroupConfigType *grpCfg = &Adc_GlobalConfigPtr->adcGroupCfgPtr[grpStatusId];
    /* dma start status */
    Adc_ErrorIdType dmaError = 0U;

    /* #10 single access mode */
    if (ADC_ACCESS_MODE_SINGLE == grpCfg->groupAccessMode)
    {
        /* #20 one-shot mode */
        if (ADC_CONV_MODE_ONESHOT == grpCfg->groupConvMode)
        {
#if (ADC_DMA_SUPPORTED == STD_ON)

            /* update group status */
            if (ADC_E_DMA_START_FAIL == Adc_UpdGrpStaForSingleOneShot(hardwareUnitbase, grpStatusId))
            {
                dmaError = ADC_E_DMA_START_FAIL;
            } /* else not needed */

#else
            (void)Adc_UpdGrpStaForSingleOneShot(hardwareUnitbase, grpStatusId);
#endif /* #if (ADC_DMA_SUPPORTED == STD_ON) */
        }
        /* #30 continuous mode */
        else
        {
#if (ADC_DMA_SUPPORTED == STD_ON)

            /* update group status */
            if (ADC_E_DMA_START_FAIL == Adc_UpdGrpStaForSingleConti(hardwareUnitbase, grpStatusId))
            {
                dmaError = ADC_E_DMA_START_FAIL;
            } /* else not needed */

#else
            (void)Adc_UpdGrpStaForSingleConti(hardwareUnitbase, grpStatusId);
#endif /* #if (ADC_DMA_SUPPORTED == STD_ON) */
        }
    }
    /* #40 streaming access mode */
    else
    {
        /* #50 linear buffer mode */
        if (ADC_STREAM_BUFFER_LINEAR == grpCfg->strBufferMode)
        {
#if (ADC_DMA_SUPPORTED == STD_ON)

            /* update group status */
            if (ADC_E_DMA_START_FAIL == Adc_UpdGrpStaForLinear(hardwareUnitbase, grpStatusId))
            {
                dmaError = ADC_E_DMA_START_FAIL;
            } /* else not needed */

#else
            (void)Adc_UpdGrpStaForLinear(hardwareUnitbase, grpStatusId);
#endif /* #if (ADC_DMA_SUPPORTED == STD_ON) */
        }
        /* #60 circular buffer mode */
        else
        {
#if (ADC_DMA_SUPPORTED == STD_ON)

            /* update group status */
            if (ADC_E_DMA_START_FAIL == Adc_UpdGrpStaForCircular(hardwareUnitbase, grpStatusId))
            {
                dmaError = ADC_E_DMA_START_FAIL;
            } /* else not needed */

#else
            (void)Adc_UpdGrpStaForCircular(hardwareUnitbase, grpStatusId);
#endif /* #if (ADC_DMA_SUPPORTED == STD_ON) */
        }
    }

    return dmaError;
}

static Adc_ErrorIdType Adc_Ip_NormalValueHandle(Adc_RegisterBaseType hwBase,
        Adc_GroupType ipGroupId,
        const Adc_ValueGroupType *valuePtr)
{
    /* channel index */
    Adc_ChannelType chnlIndex = 0U;
    /* group configuration */
    const Adc_GroupConfigType *grpCfg = &Adc_GlobalConfigPtr->adcGroupCfgPtr[ipGroupId];
    /* dma start status */
    Adc_ErrorIdType dmaStartStatus = 0U;

    const Adc_ValueGroupType *tempValuePtr = valuePtr;
    /* enter critical zone */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_07();

    /* #10 check whether current finish index reaches target sample time */
    if (grpCfg->samplingTime == Adc_AllGroupInfo[ipGroupId].groupConvFinishIndex)
    {
        /* #20 reset finish index */
        Adc_AllGroupInfo[ipGroupId].groupConvFinishIndex = 0U;
    } /* else not needed */

    for (; chnlIndex < grpCfg->channelCount; chnlIndex++)
    {
#ifndef SEMIDRIVE_E3_LITE_SERIES
#if (ADC_OVERVOLTAGE_DETECT == STD_ON) /* AdcOverVoltageDetect enabled */

        /* #30 check whether channel is access over voltage */
        if (ADC_CHANNE_DET_ABNORMAL == Adc_AllGroupInfo[ipGroupId].channelDetectStatus[chnlIndex])
        {
            /* #40 return 4095 max value to result buffer */
            grpCfg->bufferBasePtr[(chnlIndex * grpCfg->samplingTime) +
                                                                     Adc_AllGroupInfo[ipGroupId].groupConvFinishIndex] = ADC_FULL_CONVERSION_VALUE;
        }
        else
#endif /* AdcOverVoltageDetect enabled */
#endif
        {
            /* #50 return normal conversion value to result buffer */
            grpCfg->bufferBasePtr[(chnlIndex * grpCfg->samplingTime) +
                                                                     Adc_AllGroupInfo[ipGroupId].groupConvFinishIndex] = *tempValuePtr;
        }

        /* process next conversion value */
        tempValuePtr++;
    }

#if (ADC_DMA_SUPPORTED == STD_ON)

    /* #60 update group status */
    if (ADC_E_DMA_START_FAIL == Adc_Ip_UpdateInInterrupt(hwBase, ipGroupId))
    {
        dmaStartStatus = ADC_E_DMA_START_FAIL;
    } /* else not needed */

#else
    (void)Adc_Ip_UpdateInInterrupt(hwBase, ipGroupId);
#endif
    /* exit critical zone */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_07();

    /* #70 check whether group notification is enabled */
    /* if enabled,excute group notification */
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON) /* AdcGrpNotifCapability enabled */
    Adc_CheckNotifInInterrupt(ipGroupId);
#endif /* AdcGrpNotifCapability enabled */

    return dmaStartStatus;
}

static Adc_ErrorIdType Adc_Ip_ChnlValueHandle(Adc_RegisterBaseType unitBase, Adc_GroupType grpId,
        const Adc_ValueGroupType *checkValue)
{
    /* dma start status */
    Adc_ErrorIdType dmaStartStatus = 0U;

#ifndef SEMIDRIVE_E3_LITE_SERIES
#if (ADC_OVERVOLTAGE_DETECT == STD_ON) /* ADC_OVERVOLTAGE_DETECT == STD_ON */
    /* group index */
    Adc_ChannelType chnlIndex = 0U;
    /* channel config */
    const Adc_ChannelConfigType *chnlCfg;
    /* channel number id*/
    uint8 chnlNumber;
    /* channel end */
    uint8 chnlEnd;
    /* channel mux id*/
    uint8 chnlMux;
    /* variable to point to target apad start address */
    const Adc_ScrStartBitType *scrStartBitAddr;
    /* variable to save target apad start address */
    Adc_ScrStartBitType scrStartBit;

    /* #10 check whether group has deteted */
    /* no detected yet */
    if (ADC_GROUP_UNDETECTED == Adc_AllGroupInfo[grpId].groupDetectStatus)
    {
        for (; chnlIndex < Adc_GlobalConfigPtr->adcGroupCfgPtr[grpId].channelCount; chnlIndex++)
        {
            /* get channel config */
            chnlCfg = Adc_GlobalConfigPtr->adcGroupCfgPtr[grpId].groupChannelCfgPtr;
            /* get channel number id */
            chnlNumber = chnlCfg[chnlIndex].physicalChannelId / 2U;
            /* get channel end */
            chnlEnd = chnlCfg[chnlIndex].physicalChannelId % 2U;
            /* get channel mux id*/
            chnlMux = chnlCfg[chnlIndex].channelMuxId;
            /* point to target apad start address */
            scrStartBitAddr =
                Adc_ChnlScrAddress[Adc_GlobalConfigPtr->adcGroupCfgPtr[grpId].belongUnitPhysicalId];
            /* get target apad start address */
            /*PRQA S 0488  1*/
            scrStartBit = *(scrStartBitAddr + (chnlNumber * ADC_CHNL_MUX_MAX) + (chnlMux * 2U) + chnlEnd);

            /* #20 detected value is over threshold */
            if (checkValue[chnlIndex] >= ADC_OVERVOLTAGE_THRESHOLD)
            {
                /* pull down 300 ohm */
                Adc_ScrSetBit(scrStartBit, ADC_CHNL_SCR_PULL_DOWN_300_OHM);
                /* mark channel as abnormal */
                Adc_AllGroupInfo[grpId].channelDetectStatus[chnlIndex] = ADC_CHANNE_DET_ABNORMAL;
            }
            /* #30 under voltage */
            else
            {
                /* config apad to access input voltage */
                Adc_ScrSetBit(scrStartBit, ADC_CHNL_SCR_NORMAL_ACCESS);
                /* mark channel as normal */
                Adc_AllGroupInfo[grpId].channelDetectStatus[chnlIndex] = ADC_CHANNE_DET_NORMAL;
            }
        }

        /* #30 mark group has benn detected */
        Adc_AllGroupInfo[grpId].groupDetectStatus = ADC_GROUP_DETECTED;
#if (ADC_DMA_SUPPORTED == STD_ON)

        /* #40 start normal conversion */
        if (ADC_E_DMA_START_FAIL == Adc_Ip_TriggerEnable(unitBase, grpId))
        {
            /* dma start failed */
            dmaStartStatus = ADC_E_DMA_START_FAIL;
        } /* else not needed */

#else
        (void)Adc_Ip_TriggerEnable(unitBase, grpId);
#endif
    }
    /* has detected already */
    else
#endif
#endif
    {
#if (ADC_DMA_SUPPORTED == STD_ON)

        /* #50 normal conversion values process */
        if (ADC_E_DMA_START_FAIL == Adc_Ip_NormalValueHandle(unitBase, grpId, checkValue))
        {
            /* dma start failed */
            dmaStartStatus = ADC_E_DMA_START_FAIL;
        } /* else not needed */

#else
        (void)Adc_Ip_NormalValueHandle(unitBase, grpId, checkValue);
#endif /* #if (ADC_DMA_SUPPORTED == STD_ON) */
    }

    return dmaStartStatus;
}

static void Adc_ClearIntEnableAndStatus(Adc_RegisterBaseType hwUnitbase)
{
    /* disable all adc interrupts */
    /* disable all adc int signals */
    Adc_WriteRegister(hwUnitbase + SADC_INT_SIG_EN_BASE, SADC_INT_SIG_EN_START_BIT_FIELD_OFFSET,
                      SADC_INT_SIG_EN_ALL_VALID_BIT_FIELD_SIZE, ADC_INT_SIG_EN_RESET_VALUE);
    /* disable all adc int status */
    Adc_WriteRegister(hwUnitbase + SADC_INT_STA_EN_BASE, SADC_INT_STA_EN_START_BIT_FIELD_OFFSET,
                      SADC_INT_STA_EN_ALL_VALID_BIT_FIELD_SIZE, ADC_INT_STA_EN_RESET_VALUE);
    /* clear all adc int status */
    Adc_WriteRegister(hwUnitbase + SADC_INT_STA_BASE, SADC_INT_STA_START_BIT_FIELD_OFFSET,
                      SADC_INT_STA_ALL_VALID_BIT_FIELD_SIZE, SADC_INT_STA_ALL);
}
/** **************************************************************************************
 * \brief This function is ISR for Adc Driver.

 * \verbatim
 * Syntax             : void Adc_EndGroupConversion(
 *                          Adc_HwUnitType hardwarePhysicalId)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Reentrant

 * Parameters (in)    : hardwarePhysicalId - Physical Id for Adc Unit

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function is ISR for Adc Driver.
 * \endverbatim
 * Traceability       : SWSR_ADC_155 SWSR_ADC_190
 *****************************************************************************************/
#pragma default_function_attributes = @".iram_func"
void Adc_EndGroupConversion(Adc_HwUnitType hardwarePhysicalId)
{
    /* error status in interrupt */
    Adc_ErrorIdType intErrorStatus = 0U;
    /* adc uinit base */
    Adc_RegisterBaseType base;
    /* group rcht/rc index */
    Adc_RcRchtIndexType grpRcRchtIndex;
    /* adc group id which trigger interrupt */
    Adc_GroupType grpIdInInterrupt;
    /* internal buffer to save conversion values momentarily */
    Adc_ValueGroupType internalBuffer[ADC_USED_MAX_GROUP_CHNL_COUNT];
    /* get unit configuration */
    const Adc_HwUnitConfigType *hwCfgInInterrupt;
    /* init internal buffer with 0 */
    Adc_Ip_InitBuffer(internalBuffer, ADC_USED_MAX_GROUP_CHNL_COUNT);

    /* #10 check whether adc module is initialized */
    if (ADC_E_UNINIT == Adc_CheckInitNotYet())
    {
        intErrorStatus = ADC_E_UNINIT;
        base = ADC1_BASE_ADDRESS + (ADC_BASE_ADDRESS_INTERVAL * hardwarePhysicalId);
        Adc_ClearIntEnableAndStatus(base);
    }
    else
    {
        base = Adc_BaseAddress[hardwarePhysicalId];
        hwCfgInInterrupt = Adc_GetHwCfgThroughPhysicalId(hardwarePhysicalId);

        /* #20 check the unit triggers interrupt whether is configured */
        if (NULL_PTR == hwCfgInInterrupt)
        {
            intErrorStatus = ADC_E_TRIG_INT_ID;
            Adc_ClearIntEnableAndStatus(base);
        }
        else
        {
            /* #30 check whether adc interrupt signal register is enabled */
            if (ADC_E_INT_NOT_ENABLE == Adc_InterruptEnableCheck(base))
            {
                intErrorStatus = ADC_E_INT_NOT_ENABLE;
                Adc_ClearIntEnableAndStatus(base);
            }
            else
            {
                /* #40 get rcht/rc index through fifo configuration */
                grpRcRchtIndex = Adc_Ip_GetInterruptBit(base);
                /* #50 get group id through rcht/rc index */
                grpIdInInterrupt = Adc_GetGrpIdThroughRcRchtIndex(hwCfgInInterrupt->startGroupIdInUnit,
                                   grpRcRchtIndex);

                /* #60 check whether group is in valid status */
                if (ADC_E_INT_SOURCE == Adc_CheckGroupStatusInInt(grpIdInInterrupt))
                {
                    /* group should not trigger interrupt */
                    intErrorStatus = ADC_E_INT_SOURCE;
                    Adc_ClearIntEnableAndStatus(base);
                }
                /* group is in valid status */
                else
                {
                    /* #70 disable trigger and disconnect fifo */
                    (void)Adc_Ip_TriggerDisable(base, grpIdInInterrupt);

                    /* #80 check whether conversion values can match with group channels configuration */
                    if (ADC_E_VALUE_MATCH == Adc_Ip_ReadFifo(base, grpIdInInterrupt, internalBuffer))
                    {
                        /* not match */
                        intErrorStatus = ADC_E_VALUE_MATCH;
                        Adc_ClearIntEnableAndStatus(base);
                    }
                    /* conversion values match */
                    else
                    {
                        /* #90 clear fifo and check whether time out */
                        if (ADC_E_FIFO_POLLING_TIMEOUT == Adc_Ip_ClearFifo(base,
                                Adc_GlobalConfigPtr->adcGroupCfgPtr[grpIdInInterrupt].triggerSource, TRUE))
                        {
                            /* clear fifo time out */
                            intErrorStatus = ADC_E_FIFO_POLLING_TIMEOUT;
                            Adc_ClearIntEnableAndStatus(base);
                        }
                        else
                        {
                            /* 100 channel conversion values process */
                            (void)Adc_Ip_ChnlValueHandle(base, grpIdInInterrupt, (const Adc_ValueGroupType *) internalBuffer);
                            /* #110 clear int status */
                            Adc_WriteRegister(base + SADC_INT_STA_BASE, SADC_INT_STA_WATER_MARK_SUB_0_FIELD_OFFSET,
                                              SADC_INT_STA_WATER_MARK_SUB_0_FIELD_SIZE, ADC_BIT_ENABLE);
                        }
                    }
                }
            }
        }
    }

    AdcFaultInj_AdcFaultIntErrorStatus();
    /* to prevent intErrorStatus from no use */
    ADC_DUMMY_STATEMENT(intErrorStatus);
    return;
}
#pragma default_function_attributes =
/** **************************************************************************************
 * \brief This function change power state in ip level.

 * \verbatim
 * Syntax             : void Adc_Ip_SetPowerState(
 *                          Adc_PowerStateType targetPowerState)

 * Service ID[hex]    : None

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : targetPowerState - power state ready to be set

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : This function change power state in ip level.
 * \endverbatim
 * Traceability       : SWSR_ADC_134 SWSR_ADC_191
 *****************************************************************************************/
void Adc_Ip_SetPowerState(Adc_PowerStateType targetPowerState)
{
    /* time of reading register */
    uint32 readRegisterTime = 0U;
    /* unit index */
    uint8 unitIndex = 0U;
    /* register offset */
    volatile uint32 regOffBase;

    /* set all adc unit analog. */
    /* #10 target power is full power */
    if (ADC_FULL_POWER == targetPowerState)
    {
#ifndef SEMIDRIVE_E3_LITE_SERIES
        /* reset smc CVEN33 signal */
        Adc_WriteRegister(ADC_PMU_BASE_ADDRESS + ADC_SRCS_BITS_CLR_OFFSET, ADC_SRCS_CVEN33_BIT_FIELD_OFFSET,
                          ADC_SRCS_CVEN33_BIT_FIELD_SIZE, ADC_BIT_ENABLE);
#else /* #ifndef SEMIDRIVE_E3_LITE_SERIES */
        /* reset smc CVEN33 signal for Adc1 */
        Adc_WriteRegister(ADC_PMU_BASE_ADDRESS + ADC_SRCS_BITS_CLR_OFFSET,
                          ADC_SRCS_ADC1_CVEN33_BIT_FIELD_OFFSET,
                          ADC_SRCS_ADC1_CVEN33_BIT_FIELD_SIZE, ADC_BIT_ENABLE);
        /* reset smc CVEN33 signal for other analog part */
        Adc_WriteRegister(ADC_PMU_BASE_ADDRESS + ADC_SRCS_BITS_CLR_OFFSET,
                          ADC_SRCS_ADC2_ADC3_CVEN33_BIT_FIELD_OFFSET,
                          ADC_SRCS_ADC2_ADC3_CVEN33_BIT_FIELD_SIZE, ADC_BIT_ENABLE);
#endif /* #ifdef SEMIDRIVE_E3_LITE_SERIES */

        for (; unitIndex < Adc_GlobalConfigPtr->unitCount; unitIndex++)
        {
            /* scr bit*/
            /* get analog register offset */
            regOffBase = Adc_BaseAddress[Adc_GlobalConfigPtr->adcUnitCfgPtr[unitIndex].hwModulePhysicalId] +
                         SADC_ANA_REF_PART1_BASE;
            /* enable analog part */
            Adc_WriteRegister(regOffBase, SADC_ANA_REF_PART1_PD_OFFSET, SADC_ANA_REF_PART1_PD_SIZE, 0U);
            Adc_WriteRegister(regOffBase, SADC_ANA_REF_PART1_PDBIAS_OFFSET, SADC_ANA_REF_PART1_PDBIAS_SIZE, 0U);

            /* #20 ensure analog part has at least 100us to be ready */
            /* read register one time may cost at least 100ns */
            /* read 20000 times to ensure 100us has past */
            for (; readRegisterTime < ADC_POLLING_TIMEOUT_VALUE; readRegisterTime++)
            {
                (void)REG_READ32(Adc_BaseAddress[(uint8)
                                                 Adc_GlobalConfigPtr->adcUnitCfgPtr[unitIndex].hwModulePhysicalId] + SADC_ANA_REF_PART1_BASE);
            }
        }
    }
    /* #30 target power is low power */
    else
    {
        for (; unitIndex < Adc_GlobalConfigPtr->unitCount; unitIndex++)
        {
            /* scr bit*/
            /* disable analog part */
            Adc_WriteRegister(Adc_BaseAddress[Adc_GlobalConfigPtr->adcUnitCfgPtr[unitIndex].hwModulePhysicalId]
                              + SADC_ANA_REF_PART1_BASE,
                              SADC_ANA_REF_PART1_PD_OFFSET, SADC_ANA_REF_PART1_PD_SIZE, 1U);
            Adc_WriteRegister(Adc_BaseAddress[Adc_GlobalConfigPtr->adcUnitCfgPtr[unitIndex].hwModulePhysicalId]
                              + SADC_ANA_REF_PART1_BASE,
                              SADC_ANA_REF_PART1_PDBIAS_OFFSET, SADC_ANA_REF_PART1_PDBIAS_SIZE, 1U);
        }

#ifndef SEMIDRIVE_E3_LITE_SERIES
        /* disable smc CVEN33 signal for whole analog part */
        Adc_WriteRegister(ADC_PMU_BASE_ADDRESS + ADC_SRCS_BITS_SET_OFFSET, ADC_SRCS_CVEN33_BIT_FIELD_OFFSET,
                          ADC_SRCS_CVEN33_BIT_FIELD_SIZE, ADC_BIT_ENABLE);
#else /* #ifndef SEMIDRIVE_E3_LITE_SERIES */
        /* disable smc CVEN33 signal for Adc1 */
        Adc_WriteRegister(ADC_PMU_BASE_ADDRESS + ADC_SRCS_BITS_SET_OFFSET,
                          ADC_SRCS_ADC1_CVEN33_BIT_FIELD_OFFSET,
                          ADC_SRCS_ADC1_CVEN33_BIT_FIELD_SIZE, ADC_BIT_ENABLE);
        /* disable smc CVEN33 signal for other analog part */
        Adc_WriteRegister(ADC_PMU_BASE_ADDRESS + ADC_SRCS_BITS_SET_OFFSET,
                          ADC_SRCS_ADC2_ADC3_CVEN33_BIT_FIELD_OFFSET,
                          ADC_SRCS_ADC2_ADC3_CVEN33_BIT_FIELD_SIZE, ADC_BIT_ENABLE);
#endif /* #ifdef SEMIDRIVE_E3_LITE_SERIES */
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

