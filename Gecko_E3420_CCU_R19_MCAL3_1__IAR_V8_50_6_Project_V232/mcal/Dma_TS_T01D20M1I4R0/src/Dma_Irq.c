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
 * \file     Dma_Irq.c                                                                                  *
 * \brief    AUTOSAR 4.3.1 MCAL DMA irq handler Driver.                                                 *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/18     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Mcal.h"
#include "Dma_Ip.h"
#include "Dma.h"
/********************************************************************************************************
 *                                 Private Macro definition                                             *
 *******************************************************************************************************/
/** \brief  DMA controller SF0 irq handler macro */
#define DMA_SF0_ISR(id)                                                 ISR(Dma_SF0Irq##id##Handler)\
                                                                        {\
                                                                            Dma_Ip_SF0IrqHandler((id));\
                                                                        }

#if (DMA_LOCK_STEP_MODE == STD_OFF)
/** \brief  DMA controller SF1 irq handler macro */
#define DMA_SF1_ISR(id)                                                 ISR(Dma_SF1Irq##id##Handler)\
                                                                        {\
                                                                            Dma_Ip_SF1IrqHandler((id));\
                                                                        }
#endif /** #if (DMA_LOCK_STEP_MODE == STD_OFF) */

/********************************************************************************************************
 *                                  Private Variable Definitions                                        *
 *******************************************************************************************************/
/********************************************************************************************************
 *                                  Global Variable Declarations                                        *
 *******************************************************************************************************/
/********************************************************************************************************
 *                                  Private Function Declarations                                       *
 *******************************************************************************************************/
/********************************************************************************************************
 *                               Global Inline Function Declarations                                    *
 *******************************************************************************************************/
#define DMA_START_SEC_CODE
#include "Dma_MemMap.h"
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF0_ISR(0)
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
 * Description        : DMA controller SF0 channel 0 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF0_ISR(0)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF0_ISR(1)
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
 * Description        : DMA controller SF0 channel 1 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF0_ISR(1)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF0_ISR(2)
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
 * Description        : DMA controller SF0 channel 2 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF0_ISR(2)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF0_ISR(3)
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
 * Description        : DMA controller SF0 channel 3 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF0_ISR(3)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF0_ISR(4)
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
 * Description        : DMA controller SF0 channel 4 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF0_ISR(4)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF0_ISR(5)
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
 * Description        : DMA controller SF0 channel 5 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF0_ISR(5)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF0_ISR(6)
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
 * Description        : DMA controller SF0 channel 6 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF0_ISR(6)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF0_ISR(7)
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
 * Description        : DMA controller SF0 channel 7 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF0_ISR(7)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF0_ISR(8)
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
 * Description        : DMA controller SF0 channel 8 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF0_ISR(8)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF0_ISR(9)
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
 * Description        : DMA controller SF0 channel 9 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF0_ISR(9)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF0_ISR(10)
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
 * Description        : DMA controller SF0 channel 10 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF0_ISR(10)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF0_ISR(11)
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
 * Description        : DMA controller SF0 channel 11 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF0_ISR(11)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF0_ISR(12)
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
 * Description        : DMA controller SF0 channel 12 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF0_ISR(12)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF0_ISR(13)
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
 * Description        : DMA controller SF0 channel 13 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF0_ISR(13)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF0_ISR(14)
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
 * Description        : DMA controller SF0 channel 14 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF0_ISR(14)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF0_ISR(15)
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
 * Description        : DMA controller SF0 channel 15 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF0_ISR(15)
#ifndef SEMIDRIVE_E3_LITE_SERIES
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF0_ISR(16)
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
 * Description        : DMA controller SF0 channel 16 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF0_ISR(16)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF0_ISR(17)
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
 * Description        : DMA controller SF0 channel 17 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF0_ISR(17)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF0_ISR(18)
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
 * Description        : DMA controller SF0 channel 18 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF0_ISR(18)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF0_ISR(19)
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
 * Description        : DMA controller SF0 channel 19 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF0_ISR(19)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF0_ISR(20)
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
 * Description        : DMA controller SF0 channel 20 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF0_ISR(20)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF0_ISR(21)
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
 * Description        : DMA controller SF0 channel 21 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF0_ISR(21)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF0_ISR(22)
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
 * Description        : DMA controller SF0 channel 22 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF0_ISR(22)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF0_ISR(23)
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
 * Description        : DMA controller SF0 channel 23 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF0_ISR(23)
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES */
#if (DMA_LOCK_STEP_MODE == STD_OFF)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF1_ISR(0)
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
 * Description        : DMA controller SF1 channel 0 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF1_ISR(0)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF1_ISR(1)
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
 * Description        : DMA controller SF1 channel 1 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF1_ISR(1)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF1_ISR(2)
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
 * Description        : DMA controller SF1 channel 2 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF1_ISR(2)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF1_ISR(3)
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
 * Description        : DMA controller SF1 channel 3 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF1_ISR(3)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF1_ISR(4)
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
 * Description        : DMA controller SF1 channel 4 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF1_ISR(4)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF1_ISR(5)
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
 * Description        : DMA controller SF1 channel 5 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF1_ISR(5)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF1_ISR(6)
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
 * Description        : DMA controller SF1 channel 6 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF1_ISR(6)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF1_ISR(7)
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
 * Description        : DMA controller SF1 channel 7 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF1_ISR(7)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF1_ISR(8)
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
 * Description        : DMA controller SF1 channel 8 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF1_ISR(8)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF1_ISR(9)
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
 * Description        : DMA controller SF1 channel 9 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF1_ISR(9)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF1_ISR(10)
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
 * Description        : DMA controller SF1 channel 10 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF1_ISR(10)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF1_ISR(11)
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
 * Description        : DMA controller SF1 channel 11 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF1_ISR(11)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF1_ISR(12)
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
 * Description        : DMA controller SF1 channel 12 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF1_ISR(12)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF1_ISR(13)
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
 * Description        : DMA controller SF1 channel 13 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF1_ISR(13)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF1_ISR(14)
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
 * Description        : DMA controller SF1 channel 14 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF1_ISR(14)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF1_ISR(15)
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
 * Description        : DMA controller SF1 channel 15 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF1_ISR(15)
#ifndef SEMIDRIVE_E3_LITE_SERIES
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF1_ISR(16)
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
 * Description        : DMA controller SF1 channel 16 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF1_ISR(16)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF1_ISR(17)
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
 * Description        : DMA controller SF1 channel 17 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF1_ISR(17)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF1_ISR(18)
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
 * Description        : DMA controller SF1 channel 18 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF1_ISR(18)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF1_ISR(19)
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
 * Description        : DMA controller SF1 channel 19 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF1_ISR(19)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF1_ISR(20)
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
 * Description        : DMA controller SF1 channel 20 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF1_ISR(20)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF1_ISR(21)
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
 * Description        : DMA controller SF1 channel 21 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF1_ISR(21)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF1_ISR(22)
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
 * Description        : DMA controller SF1 channel 22 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF1_ISR(22)
/** *****************************************************************************************************
 * \brief This function service to irq handler.
 *
 * \verbatim
 * Syntax             : void DMA_SF1_ISR(23)
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
 * Description        : DMA controller SF1 channel 23 irq handler.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004
 *******************************************************************************************************/
DMA_SF1_ISR(23)
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES */
#endif /** #if (DMA_LOCK_STEP_MODE == STD_OFF) */
#define DMA_STOP_SEC_CODE
#include "Dma_MemMap.h"
#ifdef __cplusplus
}
#endif
/* End of file */
