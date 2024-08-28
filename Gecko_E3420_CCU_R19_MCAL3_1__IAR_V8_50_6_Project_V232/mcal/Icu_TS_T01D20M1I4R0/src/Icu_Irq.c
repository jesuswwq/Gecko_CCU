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
 * \file     Icu_Irq.c                                                                                  *
 * \brief    This file mainly contains the implement of etimer interrupt handler                        *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/18     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif


/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
/* icu-irq self file */
#include "Icu_Irq.h"
/* icu data type file */
/** Traceability       : SWSR_ICU_002 */
#include "Icu.h"

/********************************************************************************************************
 *                                      External Function                                               *
 *******************************************************************************************************/

/* memap information */
#define ICU_START_SEC_CODE
/** Traceability       : SWSR_ICU_004 */
#include "Icu_MemMap.h"


/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
#define ICU_ISR(id)                                         ISR(Icu_Irq##id##_Handle)\
                                                            {\
                                                                Icu_IrqCommon(ICU_INDEX_ETIMER##id);\
                                                            }

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
ICU_ISR(1)

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
ICU_ISR(2)

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
ICU_ISR(3)

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
ICU_ISR(4)
#endif /* SEMIDRIVE_E3_LITE_SERIES */

/* memap information */
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif

/* End of file */
