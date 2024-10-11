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
 *  \file     Adc_Hw_E3.h                                                                               *
 *  \brief    This file contains internal interfaces of Adc Ip Level                                    *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/29     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef ADC_HW_E3_H
#define ADC_HW_E3_H

#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Adc_Types.h"
#include "Adc_ConfigTypes.h"
#include "Adc_Cfg.h"

#define ADC_BIT_ENABLE 1UL
#define ADC_BIT_DISABLE 0UL
#define ADC_BITFIELD_MASK(bitWidth)   ((1UL << (bitWidth)) - 1UL)
#define ADC_POLLING_TIMEOUT_VALUE   20000U


#define ADC_MODULE_NUMBER           3U
#define ADC_CACHE_LINE              32U
#define ADC_WORD_TO_BYTE            4U

#define ADC_EACH_RC_TIMMER_TRG_MODE 0U

#define ADC_HTC_READY_LEN_RESET_VALUE   0U
#define ADC_HTC_DONE_LEN_RESET_VALUE   0U

#define ADC_SCHEDULER_MASTER_MODE   1U
#define ADC_SCHEDULER_SLAVE_MASTER_MODE_RESET_VALUE 0U
#define ADC_SCHEDULER_ASYNC_MODE    0U
#define ADC_SCHEDULER_ASYNC_SYNC_MODE_RESET_VALUE    0U

#define ADC_RC_TIMER_CNT            4U
#define ADC_RC_TMR_MODE_RESET_VALUE 0U
#define ADC_RC_TRG_MODE_RESET_VALUE 0U
#define ADC_RC_TRG_EN_RESET_VALUE 1U

#define ADC_SUBFIFO_3               3U
#define ADC_SUBFIFO_CNT             4U
#define ADC_FIFO_32BIT_MODE         1U
#define ADC_FIFO_POLIING_MAX_TIME   128U
#define ADC_FIFO_PACK_MODE_RESET_VALUE  0U
#define ADC_SUBFIFO_START_ADDR_RESET_VALUE 0U
#define ADC_SUBFIFO_THRD_RESET_VALUE 7U
#define ADC_SUBFIFO_EN_RCHT_RC_RESET_VALUE 0U

#define ADC_CONFIG_ANA_REG_CNT      8U
#define ADC_VREFP1 0U
#define ADC_VREFP2 1U
#define ADC_VREREF_RESET_VALUE      0U
#define ADC_SAMPLE_CTRL_RESET_VALUE 0U

#define ADC_CLK_CTRL_RESET_VALUE    0U

#define ADC_DMA_CTRL_RESET_VALUE    0U


#define ADC_CONV_VALUE_BIT_WIDTH    12U
#define ADC_CHNL_PHYSICAL_ID_START_BIT_IN_CONV_VALUE 12U
#define ADC_CHNL_PHYSICAL_ID_BITWIDTH 3U
#define ADC_CHNL_MUX_ID_START_BIT_IN_CONV_VALUE 18U
#define ADC_CHNL_MUX_ID_BITWIDTH 3U
#define ADC_CHNL_END_START_BIT_IN_CONV_VALUE 15U
#define ADC_RCHT_ENTRY_CNT 32U
#define ADC_EACH_RC_ENTRY_CNT   16U
#define ADC_RC_ENTRY_TOTAL_CNT  64U
#define ADC_RCHT_RC_ENTRY_RESET_VALUE   0U

#define SADC_INT_STA_ALL ((1uL << 25u) - 1u)
#define SADC_INT_STA_ALL_VALID_BIT_FIELD_SIZE (25u)
#define ADC_INT_STA_EN_RESET_VALUE 0U
#define ADC_INT_SIG_EN_RESET_VALUE 0U
#define ADC_INIT_INITVALUE_RESET_AND_CONFIG_VALUE 0x4E20U
#define ADC_INIT_INITVALUE_CLEAR_FIFO_CONFIG_VALUE 0x10U

/* each adc unit has 9 conversion value monitors */
#define ADC_MONITOR_CNT 9U
/* adc monitor high threshold configuration */
/* this configuration is used for preventing sem error */
#define ADC_MONITOR_FULL_MASK_VALUE 0xFFFU
/* adc monitor high threshould reset value */
#define ADC_MONITOR_RESET_MASK_VALUE 0U

#if (ADC_DMA_SUPPORTED == STD_ON) /* AdcEnableDmaTransferMode enabled */
#define ADC_DMA_PER_UNIT_CHNL_CNT 2U
#define ADC_DMA_PER_GROUP_MAX_VALUE_CNT 40U

#ifndef SEMIDRIVE_E3_LITE_SERIES
#define ADC_DMA_START_MUX_ID 138U
#else
#define ADC_DMA_START_MUX_ID 80U
#endif /* #ifndef SEMIDRIVE_E3_LITE_SERIES */

#endif /* AdcEnableDmaTransferMode enabled */

#define ADC_BASE_ADDRESS_INTERVAL   (0x10000UL)
#ifndef SEMIDRIVE_E3_LITE_SERIES
#define ADC1_BASE_ADDRESS   (0xf0f70000UL)
#define ADC2_BASE_ADDRESS   (0xf0f80000UL)
#define ADC3_BASE_ADDRESS   (0xf0f90000UL)

#else /* #ifndef SEMIDRIVE_E3_LITE_SERIES */
#define ADC1_BASE_ADDRESS   (0xf0b60000UL)
#define ADC2_BASE_ADDRESS   (0xf0b70000UL)
#define ADC3_BASE_ADDRESS   (0xf0b80000UL)

#endif /* #ifdef SEMIDRIVE_E3_LITE_SERIES */

#if (ADC_POWER_STATE_SUPPORTED == STD_ON)
#define ADC_SRCS_BITS_SET_OFFSET (0x74UL)
#define ADC_SRCS_BITS_CLR_OFFSET (0x78UL)
#define ADC_PMU_BASE_ADDRESS (0xf0060000u)
#ifndef SEMIDRIVE_E3_LITE_SERIES
#define ADC_SRCS_CVEN33_BIT_FIELD_OFFSET (15u)
#define ADC_SRCS_CVEN33_BIT_FIELD_SIZE (1u)
#else /* #ifndef SEMIDRIVE_E3_LITE_SERIES */
#define ADC_SRCS_ADC1_CVEN33_BIT_FIELD_OFFSET (26u)
#define ADC_SRCS_ADC1_CVEN33_BIT_FIELD_SIZE (1u)
#define ADC_SRCS_ADC2_ADC3_CVEN33_BIT_FIELD_OFFSET (30u)
#define ADC_SRCS_ADC2_ADC3_CVEN33_BIT_FIELD_SIZE (1u)
#endif /* #ifdef SEMIDRIVE_E3_LITE_SERIES */
#endif /* #if (ADC_POWER_STATE_SUPPORTED == STD_ON) */

#define ADC_SCR_BIT_WIDTH (4UL)
#if (ADC_OVERVOLTAGE_DETECT == STD_ON)
#ifndef SEMIDRIVE_E3_LITE_SERIES
#define ADC_CHNL_SCR_PULL_DOWN_30K_OHM  4U
#define ADC_CHNL_SCR_PULL_DOWN_300_OHM  2U
#define ADC_CHNL_SCR_NORMAL_ACCESS      1U
#define ADC_APD_NONE 0U
#define ADC_CHNL_MAX 7U
#define ADC_CHNL_MUX_MAX 16U
#define ADC1_CHNL_SCR_START_INDEX 0U
#define ADC2_CHNL_SCR_START_INDEX 0U
#define ADC3_CHNL_SCR_START_INDEX 0U
#define ADC_FULL_CONVERSION_VALUE 4095U
#define ADC_APD_A_A0    704U
#define ADC_APD_A_A1    708U
#define ADC_APD_A_A2    712U
#define ADC_APD_A_A3    716U
#define ADC_APD_A_A4    720U
#define ADC_APD_A_A5    724U
#define ADC_APD_A_A6    728U
#define ADC_APD_A_A7    732U
#define ADC_APD_A_A8    736U
#define ADC_APD_A_A9    740U
#define ADC_APD_A_A10   744U
#define ADC_APD_A_A11   748U
#define ADC_APD_A_A12   752U
#define ADC_APD_A_A13   756U
#define ADC_APD_A_A14   760U
#define ADC_APD_A_A15   764U
#define ADC_APD_A_B0    768U
#define ADC_APD_A_B1    772U
#define ADC_APD_A_B2    776U
#define ADC_APD_A_B3    780U
#define ADC_APD_A_B4    784U
#define ADC_APD_A_B5    788U
#define ADC_APD_A_B6    792U
#define ADC_APD_A_B7    796U
#define ADC_APD_A_B8    800U
#define ADC_APD_A_B9    804U
#define ADC_APD_A_B10   808U
#define ADC_APD_A_B11   812U
#define ADC_APD_A_B12   816U
#define ADC_APD_A_B13   820U
#define ADC_APD_A_B14   824U
#define ADC_APD_A_B15   828U
#define ADC_APD_A_C0    832U
#define ADC_APD_A_C1    836U
#define ADC_APD_A_C2    840U
#define ADC_APD_A_C3    844U
#define ADC_APD_A_C4    848U
#define ADC_APD_A_C5    852U
#define ADC_APD_A_C6    856U
#define ADC_APD_A_C7    860U
#define ADC_APD_A_C8    864U
#define ADC_APD_A_C9    868U
#define ADC_APD_A_C10   872U
#define ADC_APD_A_C11   876U
#define ADC_APD_A_C12   880U
#define ADC_APD_A_C13   884U
#define ADC_APD_A_C14   888U
#define ADC_APD_A_C15   892U
#endif  /* #ifndef SEMIDRIVE_E3_LITE_SERIES */
#endif /* #if (ADC_OVERVOLTAGE_DETECT == STD_ON) */

#ifndef SEMIDRIVE_E3_LITE_SERIES
#define ADC_SCR_SF_BASE (0xf0680000UL)
#define ADC_AMUX_ADC1_CH5N_CSEL_3 (uint16)256U
#define ADC_AMUX_ADC1_CH5P_CSEL_3 (uint16)257U
#define ADC_AMUX_ADC2_CH4N_CSEL_3 (uint16)258U
#define ADC_AMUX_ADC2_CH4P_CSEL_3 (uint16)259U
#define ADC_AMUX_ADC2_CH5N_CSEL_3 (uint16)260U
#define ADC_AMUX_ADC2_CH5P_CSEL_3 (uint16)261U
#define ADC_AMUX_ADC2_CH6N_CSEL_3 (uint16)262U
#define ADC_AMUX_ADC3_CH5N_CSEL_3 (uint16)263U
#define ADC_AMUX_ADC3_CH5P_CSEL_3 (uint16)264U
#else /* #ifndef SEMIDRIVE_E3_LITE_SERIES */
#define ADC_SCR_SF_BASE (0xf08b0000UL)
#define ADC_AMUX_ADC1_CH5N_CSEL_3 (uint16)96U
#define ADC_AMUX_ADC1_CH5P_CSEL_3 (uint16)97U
#define ADC_AMUX_ADC2_CH4N_CSEL_3 (uint16)98U
#define ADC_AMUX_ADC2_CH4P_CSEL_3 (uint16)99U
#define ADC_AMUX_ADC2_CH5N_CSEL_3 (uint16)100U
#define ADC_AMUX_ADC2_CH5P_CSEL_3 (uint16)101U
#define ADC_AMUX_ADC2_CH6N_CSEL_3 (uint16)102U
#define ADC_AMUX_ADC3_CH5N_CSEL_3 (uint16)103U
#define ADC_AMUX_ADC3_CH5P_CSEL_3 (uint16)104U
#endif /* #ifdef SEMIDRIVE_E3_LITE_SERIES */

#if (ADC_VOLTAGE_CALIBRATION == STD_ON)
#ifndef SEMIDRIVE_E3_LITE_SERIES
#define ADC1_CALIBRATION_OFFSET 7U
#define ADC2_CALIBRATION_OFFSET 1U
#define ADC3_CALIBRATION_OFFSET 4U
#else
#define ADC1_CALIBRATION_OFFSET 5U
#define ADC2_CALIBRATION_OFFSET 6U
#define ADC3_CALIBRATION_OFFSET 4U
#endif
#endif /* #if (ADC_VOLTAGE_CALIBRATION == STD_ON) */

Adc_ErrorIdType Adc_CheckInitNotYet(void);
Adc_ErrorIdType Adc_Ip_Init(const Adc_ConfigType *adcIpCfgPtr);
#if (ADC_DEINIT_API == STD_ON)
Adc_ErrorIdType Adc_Ip_DeInit(void);
#endif /* #if (ADC_DEINIT_API == STD_ON) */
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
Adc_ErrorIdType Adc_Ip_StartGroupConversion(Adc_GroupType ipGroupId);
Adc_ErrorIdType Adc_Ip_StopGroupConversion(Adc_GroupType ipGroupId);
#endif /*#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */
#if (ADC_HW_TRIGGER_API == STD_ON)
Adc_ErrorIdType Adc_Ip_EnableHardwareTrigger(Adc_GroupType ipGroupId);
Adc_ErrorIdType Adc_Ip_DisableHardwareTrigger(Adc_GroupType ipGroupId);
#endif /* #if (ADC_HW_TRIGGER_API == STD_ON) */
void Adc_Ip_SetPowerState(Adc_PowerStateType targetPowerState);
void Adc_EndGroupConversion(Adc_HwUnitType hardwarePhysicalId);



#ifdef __cplusplus
}
#endif
#endif /* ADC_HW_E3_H */
/* End of file */

