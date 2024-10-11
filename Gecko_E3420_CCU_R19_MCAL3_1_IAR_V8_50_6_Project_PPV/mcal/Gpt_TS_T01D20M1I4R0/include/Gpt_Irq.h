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
 *  \file     Gpt_Irq.h                                                                                 *
 *  \brief    This file contains interface header for GPT MCAL driver                                   *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/24     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef GPT_IRQ_H
#define GPT_IRQ_H

#include "Mcal.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  \addtogroup MCAL_GPT_API GPT Api.
 *  \{
 */
/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
/** *****************************************************************************************************
 * \brief Interrupt service routine called on GPT1 timer event.
 *
 * \verbatim
 * Syntax             : void Gpt_Irq1_Handle(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Interrupt service routine called on GPT1 timer event.
 * \endverbatim
 * Traceability       : SWSR_GPT_084 SWSR_GPT_086
 *******************************************************************************************************/
ISR(Gpt_Irq1_Handle);

/** *****************************************************************************************************
 * \brief Interrupt service routine called on GPT1 timer event.
 *
 * \verbatim
 * Syntax             : void Gpt_Irq1_Handle(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Interrupt service routine called on GPT2 timer event.
 * \endverbatim
 * Traceability       : SWSR_GPT_084 SWSR_GPT_086
 *******************************************************************************************************/
ISR(Gpt_Irq2_Handle);

/** *****************************************************************************************************
 * \brief Interrupt service routine called on GPT1 timer event.
 *
 * \verbatim
 * Syntax             : void Gpt_Irq1_Handle(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Interrupt service routine called on GPT3 timer event.
 * \endverbatim
 * Traceability       : SWSR_GPT_084 SWSR_GPT_086
 *******************************************************************************************************/
ISR(Gpt_Irq3_Handle);

/** *****************************************************************************************************
 * \brief Interrupt service routine called on GPT1 timer event.
 *
 * \verbatim
 * Syntax             : void Gpt_Irq1_Handle(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Interrupt service routine called on GPT4 timer event.
 * \endverbatim
 * Traceability       : SWSR_GPT_084 SWSR_GPT_086
 *******************************************************************************************************/
ISR(Gpt_Irq4_Handle);

/** *****************************************************************************************************
 * \brief Interrupt service routine called on GPT1 timer event.
 *
 * \verbatim
 * Syntax             : void Gpt_Irq1_Handle(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Interrupt service routine called on GPT5 timer event.
 * \endverbatim
 * Traceability       : SWSR_GPT_084 SWSR_GPT_086
 *******************************************************************************************************/
ISR(Gpt_Irq5_Handle);

/** *****************************************************************************************************
 * \brief Interrupt service routine called on GPT1 timer event.
 *
 * \verbatim
 * Syntax             : void Gpt_Irq1_Handle(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Interrupt service routine called on GPT6 timer event.
 * \endverbatim
 * Traceability       : SWSR_GPT_084 SWSR_GPT_086
 *******************************************************************************************************/
ISR(Gpt_Irq6_Handle);
/** \} */
#ifdef __cplusplus
}
#endif

#endif /* GPT_IRQ_H */

/* End of file */
