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
 *  \file     Dma_ASM.h                                                                               *
 *  \brief    Cache opeartions.                                                                         *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/17     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifndef DMA_ASM_H
#define DMA_ASM_H
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#if !defined(ASSEMBLY)
#include <Mcal.h>
#endif /* #if !defined(ASSEMBLY) */
/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
#define DMA_DCACHE                                                      (0x01U)
#define DMA_ICACHE                                                      (0x02U)

#define DMA_CACHE_LINE                                                  (32U)

#if !defined(ASSEMBLY)
/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
/** *****************************************************************************************************
 * \brief This function is used to clean the cache and is responsible for writing the cached dirty data
 *        back into memory.
 *
 * \verbatim
 * Syntax             : void Dma_CleanCacheRange
 *                      (
 *                          const void *start
 *                          uint32 len
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : *start - Start address.
 *                      len    - Address length.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function is used to clean the cache and is responsible for writing the
 *                      cached dirty data back into memory.
 * \endverbatim
 * Traceability       : SWSR_DMA_047
 *******************************************************************************************************/
extern void Dma_CleanCacheRange(const void *start, uint32 len);
/** *****************************************************************************************************
 * \brief This function is used to clean the cache and is responsible for writing the cached dirty data
 *        back into memory and read new date from memory to cache.
 *
 * \verbatim
 * Syntax             : void Dma_CleanInvalidateCacheRange
 *                      (
 *                          const void *start
 *                          uint32 len
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : *start - Start address.
 *                      len    - Address length.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function is used to clean the cache and is responsible for writing the
 *                      cached dirty data back into memory and read new date from memory to cache.
 * \endverbatim
 * Traceability       : SWSR_DMA_047
 *******************************************************************************************************/
extern void Dma_CleanInvalidateCacheRange(const void *start, uint32 len);
/** *****************************************************************************************************
 * \brief This function is used to clean the cache and is responsible read new date from memory to
 *        cache.
 *
 * \verbatim
 * Syntax             : void Dma_InvalidateCacheRange
 *                      (
 *                          const void *start
 *                          uint32 len
 *                      )
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : *start - Start address.
 *                      len    - Address length.
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function is used to clean the cache and is responsible read new date from
 *                      memory to cache.
 * \endverbatim
 * Traceability       : SWSR_DMA_047
 *******************************************************************************************************/
extern void Dma_InvalidateCacheRange(const void *start, uint32 len);
/** *****************************************************************************************************
 * \brief This function service to atomic and opeartion.
 *
 * \verbatim
 * Syntax             : uint32 Dma_ArchAtomicAnd
 *                      (
 *                          uint32 *ptr
 *                          uint32 val
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : *ptr - address of data A.
 *                      val  - value of data B.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : old value of data A.
 *
 * Description        : This function service to atomic and opeartion.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
extern uint32 Dma_ArchAtomicAnd(uint32 *ptr, uint32 val);
/** *****************************************************************************************************
 * \brief This function service to atomic or opeartion.
 *
 * \verbatim
 * Syntax             : uint32 Dma_ArchAtomicOr
 *                      (
 *                          uint32 *ptr
 *                          uint32 val
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : *ptr - address of data A.
 *                      val  - value of data B.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : old value of data A.
 *
 * Description        : This function service to atomic and opeartion.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
extern uint32 Dma_ArchAtomicOr(uint32 *ptr, uint32 val);

#endif /* #if !defined(ASSEMBLY) */
#endif /* #ifndef DMA_ASM_H */
/* End of file */
