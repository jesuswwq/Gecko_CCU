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
 * \file     Adc_irq.c                                                                                  *
 * \brief    AUTOSAR 4.3.1 MCAL Adc interrupt Driver                                                    *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/29     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Adc_Hw_E3.h"
#include "Adc_irq.h"
#include "Mcal.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_ISR(id) \
ISR(Adc_EndGroupConvUnit##id)\
{\
    Adc_EndGroupConversion((Adc_HwUnitType)id##U - 1U);\
}

ADC_ISR(1)
ADC_ISR(2)
ADC_ISR(3)

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif
