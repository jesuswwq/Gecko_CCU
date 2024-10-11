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
 *  \file     Adc_Fault.h                                                                               *
 *  \brief    This file contains interface header for ADC Fault injection.                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/15     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef ADC_FAULT_H
#define ADC_FAULT_H

#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
/** \brief  ADC fault injection switch */
#ifndef ADC_FAULT_INJECTION
#define ADC_FAULT_INJECTION                                              (STD_OFF)
#endif

#if (ADC_FAULT_INJECTION == STD_OFF)
/** \brief  FUNCTION:Adc_InterruptEnableCheck() fault injection to store error status in int. */
#define AdcFaultInj_AdcFaultIntErrorStatus()
/** \brief  FUNCTION:Adc_InterruptEnableCheck() fault injection status register error. */
#define AdcFaultInj_Adc_InterruptEnableCheckIntSta(unitBase)
/** \brief  FUNCTION:Adc_InterruptEnableCheck() fault injection signal register error. */
#define AdcFaultInj_Adc_InterruptEnableCheckIntSig(unitBase)
/** \brief  FUNCTION:Adc_Ip_TriggerDisable() fault injection Dma stops error. */
#define AdcFaultInj_Adc_Ip_TriggerDisableDmaStopFail()
/** \brief  FUNCTION:Adc_Ip_TriggerEnable() fault injection Dma starts error. */
#define AdcFaultInj_Adc_Ip_TriggerEnableDmaStartFail()
/** \brief  FUNCTION:Adc_CheckValueMatch() fault injection value match failed. */
#define AdcFaultInj_Adc_CheckValueMatchFail()
/** \brief  FUNCTION:Adc_Ip_ConfigReset() fault injection init bit set time out. */
#define AdcFaultInj_Adc_Ip_ConfigResetFail()
/** \brief  FUNCTION:Adc_Ip_ConfigDma() fault injection dma get param error. */
#define AdcFaultInj_Adc_Ip_ConfigDmaGetParmFail()
/** \brief  FUNCTION:Adc_Ip_ConfigDma() fault injection request Dma channel error. */
#define AdcFaultInj_Adc_Ip_ConfigDmaReqChnlFail()
/** \brief  FUNCTION:Adc_Ip_ConfigDma() fault injection config Dma channel error. */
#define AdcFaultInj_Adc_Ip_ConfigDmaCfgChnlFail()
/** \brief  FUNCTION:Adc_GetHwCfgThroughPhysicalId() fault injection get NULL config error. */
#define AdcFaultInj_Adc_GetHwCfgThroughPhysicalIdGetNull()

/** \brief  FUNCTION:Adc_Ip_ClearFifo() fault injection read fifo empty error. */
#define AdcFaultInj_Adc_Ip_ClearFifoReadFail()

/** \brief  FUNCTION:Adc_Ip_ClearFifo() fault injection reset fifo error. */
#define AdcFaultInj_Adc_Ip_ClearFifoResetFail()

/** \brief  FUNCTION:Adc_Ip_StartApi fault injection. */
#define AdcFaultInj_Adc_Ip_StartInterruptPreemption()


#else
#include "Adc_UserFault.h"
extern volatile Adc_ErrorIdType Adc_IntErrorStatus;
#endif /* #if (ADC_FAULT_INJECTION == STD_OFF) */

#ifdef __cplusplus
}
#endif

#endif /* ADC_FAULT_H */
/* End of file */
