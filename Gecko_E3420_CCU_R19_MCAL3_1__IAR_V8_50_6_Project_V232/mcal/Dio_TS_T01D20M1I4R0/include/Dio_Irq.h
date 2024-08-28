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
 *  \file     Dio_Irq.h                                                                                 *
 *  \brief    This file contains interface header for DIO MCAL driver.                                  *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date                 <th>Version                                                             *
 * <tr><td>2023/07/06           <td>1.0.0                                                               *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifndef DIO_IRQ_H
#define DIO_IRQ_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Compiler.h"
#include "Compiler_Cfg.h"

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
/** *****************************************************************************************************
 * \brief Dio captures external levels and triggers interrupts.
 *
 * \verbatim
 * Syntax             : void DIO_Irq1Handler(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : When the CPU enters hib/sleep mode,
 *                      it can only be awakened through asynchronous interrupts.
 * \endverbatim
 *******************************************************************************************************/
ISR(DIO_Irq1Handler);

/** *****************************************************************************************************
 * \brief Dio captures external levels and triggers interrupts.
 *
 * \verbatim
 * Syntax             : void DIO_Irq2Handler(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : When the CPU enters hib/sleep mode,
 *                      it can only be awakened through asynchronous interrupts.
 * \endverbatim
 *******************************************************************************************************/
ISR(DIO_Irq2Handler);

/** *****************************************************************************************************
 * \brief Dio captures external levels and triggers interrupts.
 *
 * \verbatim
 * Syntax             : void DIO_Irq3Handler(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : When the CPU enters hib/sleep mode,
 *                      it can only be awakened through asynchronous interrupts.
 * \endverbatim
 *******************************************************************************************************/
ISR(DIO_Irq3Handler);

/** *****************************************************************************************************
 * \brief Dio captures external levels and triggers interrupts.
 *
 * \verbatim
 * Syntax             : void DIO_Irq4Handler(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : When the CPU enters hib/sleep mode,
 *                      it can only be awakened through asynchronous interrupts.
 * \endverbatim
 *******************************************************************************************************/
ISR(DIO_Irq4Handler);

/** *****************************************************************************************************
 * \brief Dio captures external levels and triggers interrupts.
 *
 * \verbatim
 * Syntax             : void DIO_Irq5Handler(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : When the CPU enters hib/sleep mode,
 *                      it can only be awakened through asynchronous interrupts.
 * \endverbatim
 *******************************************************************************************************/
ISR(DIO_Irq5Handler);

/** *****************************************************************************************************
 * \brief Dio captures external levels and triggers interrupts.
 *
 * \verbatim
 * Syntax             : ISR(DIO_SFIrqHandler)
 *
 * Service ID[hex]    : 0x13
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : When the CPU enters hib/sleep mode,
 *                      it can only be awakened through asynchronous interrupts.
 * \endverbatim
 *******************************************************************************************************/
ISR(DIO_SFIrqHandler);

#ifndef SEMIDRIVE_E3_LITE_SERIES
/** *****************************************************************************************************
 * \brief Dio captures external levels and triggers interrupts.
 *
 * \verbatim
 * Syntax             : void DIO_Irq6Handler(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : When the CPU enters hib/sleep mode,
 *                      it can only be awakened through asynchronous interrupts.
 * \endverbatim
 *******************************************************************************************************/
ISR(DIO_Irq6Handler);

/** *****************************************************************************************************
 * \brief Dio captures external levels and triggers interrupts.
 *
 * \verbatim
 * Syntax             : void DIO_Irq7Handler(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : When the CPU enters hib/sleep mode,
 *                      it can only be awakened through asynchronous interrupts.
 * \endverbatim
 *******************************************************************************************************/
ISR(DIO_Irq7Handler);

/** *****************************************************************************************************
 * \brief Dio captures external levels and triggers interrupts.
 *
 * \verbatim
 * Syntax             : void DIO_Irq8Handler(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : When the CPU enters hib/sleep mode,
 *                      it can only be awakened through asynchronous interrupts.
 * \endverbatim
 *******************************************************************************************************/
ISR(DIO_Irq8Handler);

/** *****************************************************************************************************
 * \brief Dio captures external levels and triggers interrupts.
 *
 * \verbatim
 * Syntax             : ISR(DIO_APIrqHandler)
 *
 * Service ID[hex]    : 0x14
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : When the CPU enters hib/sleep mode,
 *                      it can only be awakened through asynchronous interrupts.
 * \endverbatim
 *******************************************************************************************************/
ISR(DIO_APIrqHandler);
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES */

#ifdef __cplusplus
}
#endif

#endif /* DIO_IRQ_H */

/* End of file */
