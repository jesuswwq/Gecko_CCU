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
 * \file     Icu_Irq.h                                                                                  *
 * \brief    his file mainly contains the definition of etimer interrupt handler                        *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/18     <td>1.0.0                               *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifndef ICU_IRQ_H
#define ICU_IRQ_H

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
/* icu data types file */
#include "Icu_Types.h"
/* mcal types file */
#include "Mcal.h"

/********************************************************************************************************
 *                                         Function definition                                          *
 *******************************************************************************************************/

/** *****************************************************************************************************
 * \brief etimer1 interrupt handler
 *
 * \verbatim
 * Syntax             : void Icu_Irq1_Handle(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : etimer1 interrupt handler
 * \endverbatim
 * Traceability       : SWSR_ICU_036
 *******************************************************************************************************/
ISR(Icu_Irq1_Handle);

/** *****************************************************************************************************
 * \brief etimer2 interrupt handler
 *
 * \verbatim
 * Syntax             : void Icu_Irq2_Handle(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : etimer2 interrupt handler
 * \endverbatim
 * Traceability       : SWSR_ICU_036
 *******************************************************************************************************/
ISR(Icu_Irq2_Handle);

#ifndef SEMIDRIVE_E3_LITE_SERIES
/** *****************************************************************************************************
 * \brief etimer3 interrupt handler
 *
 * \verbatim
 * Syntax             : void Icu_Irq3_Handle(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : etimer3 interrupt handler
 * \endverbatim
 * Traceability       : SWSR_ICU_036
 *******************************************************************************************************/
ISR(Icu_Irq3_Handle);

/** *****************************************************************************************************
 * \brief etimer4 interrupt handler
 *
 * \verbatim
 * Syntax             : void Icu_Irq4_Handle(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The setting result
 *
 * Description        : etimer4 interrupt handler
 * \endverbatim
 * Traceability       : SWSR_ICU_036
 *******************************************************************************************************/
ISR(Icu_Irq4_Handle);
#endif /* SEMIDRIVE_E3_LITE_SERIES */


#ifdef __cplusplus
}
#endif

#endif /* ICU_IRQ_H */
/* End of file */
