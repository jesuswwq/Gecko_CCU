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
 *  \file     Adc_irq.h                                                                                 *
 *  \brief    This file contains Adc ISR interface                                                      *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/29     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifndef ADC_IRQ_H
#define ADC_IRQ_H

#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Adc_Hw_E3.h"
#include "Mcal.h"

ISR(Adc_EndGroupConvUnit1);
ISR(Adc_EndGroupConvUnit2);
ISR(Adc_EndGroupConvUnit3);

#ifdef __cplusplus
}
#endif
#endif /* ADC_IRQ_H */
/* End of file */
