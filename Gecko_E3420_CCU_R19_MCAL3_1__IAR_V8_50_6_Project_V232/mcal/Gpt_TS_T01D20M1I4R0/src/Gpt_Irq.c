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
 * \file     Gpt_Irq.c                                                                                  *
 * \brief    AUTOSAR 4.3.1 MCAL GPT Driver                                                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/24     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Gpt_Irq.h"
/**
 * Traceability       : SWSR_GPT_002
 */
#include "Gpt.h"
#include "Mcal.h"

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

#define GPT_ISR(id) \
ISR(Gpt_Irq##id##_Handle)\
{\
    Gpt_Irq(GPT_INDEX_BTM##id);\
}

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
GPT_ISR(1)

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
GPT_ISR(2)

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
GPT_ISR(3)

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
GPT_ISR(4)

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
GPT_ISR(5)

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
GPT_ISR(6)

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#ifdef __cplusplus
}
#endif

/* End of file */
