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
 * \file     Dma_Ip.c                                                                                   *
 * \brief    This file contains DMA Ip layer MCAL driver.                                               *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/17     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "SchM_Dma.h"
#include "RegHelper.h"
#include "Dma_Ip.h"
#include "Dma_ASM.h"
#include "Dma_Reg.h"
#include "Dma_Fault.h"
/********************************************************************************************************
 *                                 Private Macro definition                                             *
 *******************************************************************************************************/
/** \brief  DMA channel bus error interrupt mask. */
#define DMA_BUS_ERROR_MASK                                              ((uint32)DMA_CH_INT_EN_AHB_RD_ERROR | \
                                                                         (uint32)DMA_CH_INT_EN_AHB_WR_ERROR | \
                                                                         (uint32)DMA_CH_INT_EN_AXI_RD_ERROR | \
                                                                         (uint32)DMA_CH_INT_EN_AXI_WR_ERROR)
/** \brief  DMA channel system error interrupt mask. */
#define DMA_SYSTEM_ERROR_MASK                                           ((uint32)DMA_CH_INT_EN_HS_E2E_COR_ERROR | \
                                                                         (uint32)DMA_CH_INT_EN_HS_E2E_UNC_ERROR | \
                                                                         (uint32)DMA_CH_INT_EN_FIFO_E2E_COR_ERROR | \
                                                                         (uint32)DMA_CH_INT_EN_FIFO_E2E_UNC_ERROR | \
                                                                         (uint32)DMA_CH_INT_EN_CH_LINK_ERROR | \
                                                                         (uint32)DMA_CH_INT_EN_FW_RD_ERROR | \
                                                                         (uint32)DMA_CH_INT_EN_FW_WR_ERROR | \
                                                                         (uint32)DMA_CH_INT_EN_PATTERN_DET_ERROR | \
                                                                         (uint32)DMA_CH_INT_EN_AXI_OUTSTD_UTID_ERROR | \
                                                                         (uint32)DMA_CH_INT_EN_PS_ERROR)
/** \brief  DMA channel CRC error interrupt mask. */
#define DMA_CRC_ERROR_MASK                                              ((uint32)DMA_CH_INT_EN_MAD_CRC_ERROR | (uint32)DMA_CH_INT_EN_DATA_CRC_ERROR)

/** \brief  DMA bitmap opeartions macro. */
#define DMA_BITMAP_BITS_PER_WORD                                        (sizeof(uint32) * 8U)
#define DMA_BITMAP_NUM_WORDS(x)                                         (((x) + (DMA_BITMAP_BITS_PER_WORD - 1U)) / DMA_BITMAP_BITS_PER_WORD)
#define DMA_BITMAP_WORD(x)                                              ((x) / DMA_BITMAP_BITS_PER_WORD)
#define DMA_BITMAP_BIT_IN_WORD(x)                                       ((x) & (DMA_BITMAP_BITS_PER_WORD - 1U))
#define DMA_BITMAP_BITS_PER_INT                                         (sizeof(uint32) * 8U)
#define DMA_BITMAP_BIT_IN_INT(x)                                        ((x) & (DMA_BITMAP_BITS_PER_INT - 1U))
#define DMA_BITMAP_INT(x)                                               ((x) / DMA_BITMAP_BITS_PER_INT)

/** \brief  Each MAD CRC calculates the value of 7 registers. */
#define DMA_IP_MAD_CRC_REGISTERS                                        (7U)

/** \brief  Round up macro. */
#define DMA_ROUNDUP(a, b)                                               (((a) + (uint32)((b)-1UL)) & (uint32)~((b)-1UL))

#define DMA_BIT_MASK(x)                                                 (((x) >= (sizeof(unsigned long) * 8U)) ? (0xFFFFFFFFU) : ((1UL << (x)) - 1UL))

/** \brief  DMA link list buffer max length. */
#define DMA_IP_LINK_LIST_BUFFER_MAX_LENGTH(x)                           (DMA_ROUNDUP((x), 8U))
#define DMA_IP_LINK_LIST_BUFFER_LBC_MAX_LENGTH(x)                       (DMA_ROUNDUP((x), 8U))

#define DMA_OFFSET_OF(type, member)                                     (uint32)&(((type*)0)->member)

#define DMA_CONTAINER_OF(ptr, type, member) \
                                                                        ((type *)((unsigned long)(ptr) - DMA_OFFSET_OF(type, member)))

/** \brief  iterates over the list, entry should be the container structure type. */
#define DMA_LIST_FOR_EVERY_ENTRY(list, entry, type, member) \
                                                                        for(entry = DMA_CONTAINER_OF((list)->next, type, member);\
                                                                            &(entry)->member != (list);\
                                                                            (entry) = DMA_CONTAINER_OF((entry)->member.next, type, member))

/** \brief  iterates over the list in a safe way for deletion of current node.
 *          entry and temp_entry should be the container structure type
 */
#define DMA_LIST_FOR_EVERY_ENTRY_SAFE(list, entry, temp_entry, type, member) \
                                                                        for(entry = DMA_CONTAINER_OF((list)->next, type, member),\
                                                                            temp_entry = DMA_CONTAINER_OF((entry)->member.next, type, member);\
                                                                            &(entry)->member != (list);\
                                                                            entry = temp_entry, temp_entry = DMA_CONTAINER_OF((temp_entry)->member.next, type, member))

/** \brief  Offset of the DMA fifo, which needs to be cleared during the initialization phase. */
#define DMA_IP_FIFO_OFFSET                                              (0xA000U)
/** \brief  DMA FIFO deepth. */
#define DMA_IP_FIFO_WORDS                                               (8192U / 4U)

/** \brief  DMA loop mode 2 max total Transfer size. */
#define DMA_IP_LP2_TOTAL_MAX                                            (0x200000U)
/** \brief  DMA loop mode 2 max transfer size at every loop. */
#define DMA_IP_LP2_LPSIZE_MAX                                           (0x8000U)
/** \brief  DMA loop mode 1 max transfer size at every loop. */
#define DMA_IP_LP1_LPSIZE_MAX                                           (0x00000FFFU)
/** \brief  DMA loop mode 0 max total size for data to be transferred at one time. */
#define DMA_IP_LP0_LPSIZE_MAX                                           (0x00FFFFFFU)
/** \brief  DMA max block size. */
#define DMA_IP_MAX_BLOCK_SIZE                                           DMA_IP_LP2_LPSIZE_MAX

/** \brief  DMA loop mode 0 total size calculation method. */
#define DMA_IP_LP0_SIZE(n)                                              ((n) - 1U)
/** \brief  DMA get loop mode 0 total size for data to be transferred at one time. */
#define DMA_IP_GET_LP0_SIZE(n)                                          ((n) + 1U)
/** \brief  DMA loop mode 1 calculation of total transmission length. */
#define DMA_IP_LP1_SIZE(n)                                              (((n) - 1U) & 0xFFFU)
/** \brief  DMA loop mode 1 calculation of loop counter. */
#define DMA_IP_LP1_CNT(n)                                               (((n) - 1U) << 12U)
/** \brief  DMA loop mode 1 get transfer size at every loop. */
#define DMA_IP_GET_LP1_SIZE(n)                                          (((n) & 0xFFF) + 1U)
/** \brief  DMA loop mode 1 get loop counter. */
#define DMA_IP_GET_LP1_CNT(n)                                           ((((n) & 0xFFF000U) >> 12U) + 1U)
/** \brief  DMA loop mode 2 calculation of total transmission length. */
#define DMA_IP_LP2_TT(n)                                                ((((n) - 1U) << 4U) & 0xFFFFF0U)
/** \brief  DMA loop mode 2 get transfer size at every loop. */
#define DMA_IP_GET_LP2_LPSIZE(n)                                        (1U << ((n) & 0xFU))
/** \brief  DMA loop mode 1 get total transfer size. */
#define DMA_IP_GET_LP2_TT(n)                                            ((((n) & 0xFFFFF0) >> 4U) + 1U)

#define DMA_IP_CHANNEL_BASE_OFFSET                                      (0x10000U)
/** \brief  CalUcate DMA channel base address. */
#define DMA_IP_CHANNEL_BASE(base, chann)                                ((0x2000UL * (chann)) + (base) + DMA_IP_CHANNEL_BASE_OFFSET)
#define DMA_IP_LOCAL_BUFFER_OFFSET                                      (0x8000U)
#define DMA_IP_LOCAL_BUFFER_MAX_BYTES                                   (4096U)

#define DMA_OUTSTANDING_VALUE                                           (0x0FU)
#define DMA_OUTSTANDING_MASK                                            (0x0FUL)

/** \brief  Used for timeout mechanism, waiting 1.66ms (31125 * 30% = 9337.5 bytes) based on CPU frequence is 600MHz. */
#define DMA_TIME_DURATION                                               (1000U*100U)
/** \brief  Maximum number of dma attempts to software handshake. */
#define DMA_HANDSHAKE_LIMIT                                             (5U)
/** \brief  Uesd for loop mode 2. */
#define DMA_BUFFER_SIZE_LOOP_COUNTER_MASK                               (0xFU)
/** \brief  Uesd for loop mode 2. */
#define DMA_BUFFER_SIZE_MASK                                            (0xFE00000FU)

/** \brief  Reset DATA_TRANSFER register value. */
#define DMA_RESET_TRANSFER_LENGTH                                       (0x00U)

#define DMA_INVALID_MUX_ID                                              (0xFFU)

#define DMA_LINK_LIST_INVALID_ADDRESS                                   (0x00000000U)

#define DMA_LOCKSTEP_REG_OFFSET                                         (0x1400U)

#define DMA_DISABLE_ALL_INTERRUPT                                       (0x00000000U)

#define DMA_CLEAR_ALL_INTERRUPT_STATUS                                  (0xFFFFFFFFU)

#define DMA_INVALID_VALUE                                               (0xFFFFFFFFU)

/** \brief  Uesd for find the first bit set. */
#define DMA_FFS_PHASE_1                                                 (0xFFFFU)
#define DMA_FFS_PHASE_2                                                 (0xFFU)
#define DMA_FFS_PHASE_3                                                 (0xFU)
#define DMA_FFS_PHASE_4                                                 (0x3U)
#define DMA_FFS_PHASE_5                                                 (0x1U)

/** \brief  Uesd for Counte Leading Zeros. */
#define DMA_MAX_BIT_NUMBER                                              (32U)
#define DMA_CLZ_PHASE_1                                                 (0xFFFF0000U)
#define DMA_CLZ_PHASE_2                                                 (0x0000FF00U)
#define DMA_CLZ_PHASE_3                                                 (0x000000F0U)
#define DMA_CLZ_PHASE_4                                                 (0x0000000CU)
#define DMA_CLZ_PHASE_5                                                 (0x00000002U)
#ifndef SEMIDRIVE_E3_LITE_SERIES
#define DMA_APB_SCR_SF_BASE                                             (0xf0680000u)
#else
#define DMA_APB_SCR_SF_BASE                                                 (0xf08b0000u)
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES */
/********************************************************************************************************
 *                                    Private Type Declarations                                         *
 *******************************************************************************************************/

/********************************************************************************************************
 *                                  Private Variable Definitions                                        *
 *******************************************************************************************************/
/** Traceability       : SWSR_DMA_013 SW_SM008 */
/* Support multicore and initialization states */
#if (DMA_CORE0_ENABLE == STD_ON)
#define DMA_CORE0_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dma_MemMap.h"
/** \brief  Dma link list bitmap, used as record link list node allocated or free. For use only peripheral from/to memory on core0. */
DMA_LOCAL uint32 Dma_LinkListBitmapCore0[DMA_BITMAP_NUM_WORDS(DMA_IP_LINK_LIST_BUFFER_MAX_LENGTH(
            DMA_LINK_LIST_LENGTH_CORE0))]LOCATE_ALIGNED(DMA_CONFIG_ARCH_CACHE_LINE);
/** \brief  Uesd as record controller SF0 channel's configuration on core0. *//* 288byte */
DMA_LOCAL Dma_ChannelRegType Dma_SF0ChannelCore0[DMA_CHANNEL_SF0_ON_CORE0_NUMBER]LOCATE_ALIGNED(
    DMA_CONFIG_ARCH_CACHE_LINE);
/** \brief  DMA controller SF0 base info on core0. */
DMA_LOCAL Dma_ControllerParamType Dma_ControllerSF0Core0 LOCATE_ALIGNED(DMA_CONFIG_ARCH_CACHE_LINE);
#define DMA_CORE0_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dma_MemMap.h"

#if (DMA_NO_CACHEABLE_NEEDED == STD_ON)
#define DMA_START_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#else
#define DMA_CORE0_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif /** #if (DMA_NO_CACHEABLE_NEEDED == STD_ON) */
#include "Dma_MemMap.h"
/** \brief  Dma static linked list data structure on core0. *//* 56 */
DMA_LOCAL Dma_linkListType Dma_LinkListBufferCore0[DMA_IP_LINK_LIST_BUFFER_MAX_LENGTH(
            DMA_LINK_LIST_LENGTH_CORE0)]LOCATE_ALIGNED(DMA_CONFIG_ARCH_CACHE_LINE);
#if (DMA_NO_CACHEABLE_NEEDED == STD_ON)
#define DMA_STOP_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#else
#define DMA_CORE0_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif /** #if (DMA_NO_CACHEABLE_NEEDED == STD_ON) */
#include "Dma_MemMap.h"
#endif /** #if (DMA_CORE0_ENABLE == STD_ON) */

#if (DMA_CORE1_ENABLE == STD_ON)
#define DMA_CORE1_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dma_MemMap.h"
/** \brief  Dma link list bitmap, used as record link list node allocated or free. For use only peripheral from/to memory on core1. */
DMA_LOCAL uint32 Dma_LinkListBitmapCore1[DMA_BITMAP_NUM_WORDS(DMA_IP_LINK_LIST_BUFFER_MAX_LENGTH(
            DMA_LINK_LIST_LENGTH_CORE0))]LOCATE_ALIGNED(DMA_CONFIG_ARCH_CACHE_LINE);
/** \brief  Uesd as record controller SF0 channel's configuration on core1. */
DMA_LOCAL Dma_ChannelRegType Dma_SF0ChannelCore1[DMA_CHANNEL_SF0_ON_CORE1_NUMBER + 1U]
LOCATE_ALIGNED(DMA_CONFIG_ARCH_CACHE_LINE);
/** \brief  DMA controller SF0 base info on core1. */
DMA_LOCAL Dma_ControllerParamType Dma_ControllerSF0Core1 LOCATE_ALIGNED(DMA_CONFIG_ARCH_CACHE_LINE);
#define DMA_CORE1_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dma_MemMap.h"

#if (DMA_NO_CACHEABLE_NEEDED == STD_ON)
#define DMA_START_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#else
#define DMA_CORE1_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif /** #if (DMA_NO_CACHEABLE_NEEDED == STD_ON) */
#include "Dma_MemMap.h"
/** \brief  Dma static linked list data structure on core1. */
DMA_LOCAL Dma_linkListType Dma_LinkListBufferCore1[DMA_IP_LINK_LIST_BUFFER_MAX_LENGTH(
            DMA_LINK_LIST_LENGTH_CORE0)]LOCATE_ALIGNED(DMA_CONFIG_ARCH_CACHE_LINE);
#if (DMA_NO_CACHEABLE_NEEDED == STD_ON)
#define DMA_STOP_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#else
#define DMA_CORE1_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif /** #if (DMA_NO_CACHEABLE_NEEDED == STD_ON) */
#include "Dma_MemMap.h"
#endif /** #if (DMA_CORE1_ENABLE == STD_ON) */

#if (DMA_CORE2_ENABLE == STD_ON)
#define DMA_CORE2_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dma_MemMap.h"
/** \brief  Dma link list bitmap, used as record link list node allocated or free. For use only peripheral from/to memory on core2. */
DMA_LOCAL uint32 Dma_LinkListBitmapCore2[DMA_BITMAP_NUM_WORDS(DMA_IP_LINK_LIST_BUFFER_MAX_LENGTH(
            DMA_LINK_LIST_LENGTH_CORE0))]LOCATE_ALIGNED(DMA_CONFIG_ARCH_CACHE_LINE);
/** \brief  Uesd as record controller SF0 channel's configuration on core2. */
DMA_LOCAL Dma_ChannelRegType Dma_SF0ChannelCore2[DMA_CHANNEL_SF0_ON_CORE2_NUMBER + 1U]
LOCATE_ALIGNED(DMA_CONFIG_ARCH_CACHE_LINE);
/** \brief  DMA controller SF0 base info on core2. */
DMA_LOCAL Dma_ControllerParamType Dma_ControllerSF0Core2 LOCATE_ALIGNED(DMA_CONFIG_ARCH_CACHE_LINE);
#define DMA_CORE2_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dma_MemMap.h"

#if (DMA_NO_CACHEABLE_NEEDED == STD_ON)
#define DMA_START_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#else
#define DMA_CORE2_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif /** #if (DMA_NO_CACHEABLE_NEEDED == STD_ON) */
#include "Dma_MemMap.h"
/** \brief  Dma static linked list data structure on core2. */
DMA_LOCAL Dma_linkListType Dma_LinkListBufferCore2[DMA_IP_LINK_LIST_BUFFER_MAX_LENGTH(
            DMA_LINK_LIST_LENGTH_CORE0)]LOCATE_ALIGNED(DMA_CONFIG_ARCH_CACHE_LINE);
#if (DMA_NO_CACHEABLE_NEEDED == STD_ON)
#define DMA_STOP_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#else
#define DMA_CORE2_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif /** #if (DMA_NO_CACHEABLE_NEEDED == STD_ON) */
#include "Dma_MemMap.h"
#endif /** #if (DMA_CORE2_ENABLE == STD_ON) */

#if (DMA_CORE3_ENABLE == STD_ON)
#define DMA_CORE3_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dma_MemMap.h"
/** \brief  Dma link list bitmap, used as record link list node allocated or free. For use only peripheral from/to memory on core3. */
DMA_LOCAL uint32 Dma_LinkListBitmapCore3[DMA_BITMAP_NUM_WORDS(DMA_IP_LINK_LIST_BUFFER_MAX_LENGTH(
            DMA_LINK_LIST_LENGTH_CORE0))]LOCATE_ALIGNED(DMA_CONFIG_ARCH_CACHE_LINE);
/** \brief  Uesd as record controller SF0 channel's configuration on core3. */
DMA_LOCAL Dma_ChannelRegType Dma_SF0ChannelCore3[DMA_CHANNEL_SF0_ON_CORE3_NUMBER + 1U]
LOCATE_ALIGNED(DMA_CONFIG_ARCH_CACHE_LINE);
/** \brief  DMA controller SF0 base info on core3. */
DMA_LOCAL Dma_ControllerParamType Dma_ControllerSF0Core3 LOCATE_ALIGNED(DMA_CONFIG_ARCH_CACHE_LINE);
#define DMA_CORE3_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dma_MemMap.h"

#if (DMA_NO_CACHEABLE_NEEDED == STD_ON)
#define DMA_START_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#else
#define DMA_CORE3_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif /** #if (DMA_NO_CACHEABLE_NEEDED == STD_ON) */
#include "Dma_MemMap.h"
/** \brief  Dma static linked list data structure on core3. */
DMA_LOCAL Dma_linkListType Dma_LinkListBufferCore3[DMA_IP_LINK_LIST_BUFFER_MAX_LENGTH(
            DMA_LINK_LIST_LENGTH_CORE0)]LOCATE_ALIGNED(DMA_CONFIG_ARCH_CACHE_LINE);
#if (DMA_NO_CACHEABLE_NEEDED == STD_ON)
#define DMA_STOP_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#else
#define DMA_CORE3_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif /** #if (DMA_NO_CACHEABLE_NEEDED == STD_ON) */
#include "Dma_MemMap.h"
#endif /** #if (DMA_CORE3_ENABLE == STD_ON) */

#if (DMA_CORE4_ENABLE == STD_ON)
#define DMA_CORE4_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dma_MemMap.h"
/** \brief  Dma link list bitmap, used as record link list node allocated or free. For use only peripheral from/to memory on core4. */
DMA_LOCAL uint32 Dma_LinkListBitmapCore4[DMA_BITMAP_NUM_WORDS(DMA_IP_LINK_LIST_BUFFER_MAX_LENGTH(
            DMA_LINK_LIST_LENGTH_CORE0))]LOCATE_ALIGNED(DMA_CONFIG_ARCH_CACHE_LINE);
/** \brief  Uesd as record controller SF0 channel's configuration on core4. */
DMA_LOCAL Dma_ChannelRegType Dma_SF0ChannelCore4[DMA_CHANNEL_SF0_ON_CORE4_NUMBER + 1U]
LOCATE_ALIGNED(DMA_CONFIG_ARCH_CACHE_LINE);
/** \brief  DMA controller SF0 base info on core4. */
DMA_LOCAL Dma_ControllerParamType Dma_ControllerSF0Core4 LOCATE_ALIGNED(DMA_CONFIG_ARCH_CACHE_LINE);
#define DMA_CORE4_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dma_MemMap.h"

#if (DMA_NO_CACHEABLE_NEEDED == STD_ON)
#define DMA_START_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#else
#define DMA_CORE4_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif /** #if (DMA_NO_CACHEABLE_NEEDED == STD_ON) */
#include "Dma_MemMap.h"
/** \brief  Dma static linked list data structure on core4. */
DMA_LOCAL Dma_linkListType Dma_LinkListBufferCore4[DMA_IP_LINK_LIST_BUFFER_MAX_LENGTH(
            DMA_LINK_LIST_LENGTH_CORE0)]LOCATE_ALIGNED(DMA_CONFIG_ARCH_CACHE_LINE);
#if (DMA_NO_CACHEABLE_NEEDED == STD_ON)
#define DMA_STOP_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#else
#define DMA_CORE4_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif /** #if (DMA_NO_CACHEABLE_NEEDED == STD_ON) */
#include "Dma_MemMap.h"
#endif /** #if (DMA_CORE4_ENABLE == STD_ON) */

#if (DMA_LOCK_STEP_MODE == STD_OFF)
#if (DMA_CORE0_ENABLE == STD_ON)
#define DMA_CORE0_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dma_MemMap.h"
/** \brief  Uesd as record controller SF1 channel's configuration on core0. */
DMA_LOCAL Dma_ChannelRegType Dma_SF1ChannelCore0[DMA_CHANNEL_SF1_ON_CORE0_NUMBER + 1U]
LOCATE_ALIGNED(DMA_CONFIG_ARCH_CACHE_LINE);
/** \brief  DMA controller SF1 base info on core0. */
DMA_LOCAL Dma_ControllerParamType Dma_ControllerSF1Core0 LOCATE_ALIGNED(DMA_CONFIG_ARCH_CACHE_LINE);
#define DMA_CORE0_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dma_MemMap.h"
#endif /** #if (DMA_CORE0_ENABLE == STD_ON) */

#if (DMA_CORE1_ENABLE == STD_ON)
#define DMA_CORE1_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dma_MemMap.h"
/** \brief  Uesd as record controller SF1 channel's configuration on core1. */
DMA_LOCAL Dma_ChannelRegType Dma_SF1ChannelCore1[DMA_CHANNEL_SF1_ON_CORE1_NUMBER + 1U]
LOCATE_ALIGNED(DMA_CONFIG_ARCH_CACHE_LINE);
/** \brief  DMA controller SF1 base info on core1. */
DMA_LOCAL Dma_ControllerParamType Dma_ControllerSF1Core1 LOCATE_ALIGNED(DMA_CONFIG_ARCH_CACHE_LINE);
#define DMA_CORE1_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dma_MemMap.h"
#endif /** #if (DMA_CORE1_ENABLE == STD_ON) */

#if (DMA_CORE2_ENABLE == STD_ON)
#define DMA_CORE2_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dma_MemMap.h"
/** \brief  Uesd as record controller SF1 channel's configuration on core2. */
DMA_LOCAL Dma_ChannelRegType Dma_SF1ChannelCore2[DMA_CHANNEL_SF1_ON_CORE2_NUMBER + 1U]
LOCATE_ALIGNED(DMA_CONFIG_ARCH_CACHE_LINE);
/** \brief  DMA controller SF1 base info on core2. */
DMA_LOCAL Dma_ControllerParamType Dma_ControllerSF1Core2 LOCATE_ALIGNED(
    DMA_CONFIG_ARCH_CACHE_LINE)LOCATE_ALIGNED(DMA_CONFIG_ARCH_CACHE_LINE);
#define DMA_CORE2_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dma_MemMap.h"
#endif /** #if (DMA_CORE2_ENABLE == STD_ON) */

#if (DMA_CORE3_ENABLE == STD_ON)
#define DMA_CORE3_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dma_MemMap.h"
/** \brief  Uesd as record controller SF1 channel's configuration on core3. */
DMA_LOCAL Dma_ChannelRegType Dma_SF1ChannelCore3[DMA_CHANNEL_SF1_ON_CORE3_NUMBER + 1U];
/** \brief  DMA controller SF1 base info on core3. */
DMA_LOCAL Dma_ControllerParamType Dma_ControllerSF1Core3 LOCATE_ALIGNED(DMA_CONFIG_ARCH_CACHE_LINE);
#define DMA_CORE3_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dma_MemMap.h"
#endif /** #if (DMA_CORE3_ENABLE == STD_ON) */

#if (DMA_CORE4_ENABLE == STD_ON)
#define DMA_CORE4_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dma_MemMap.h"
/** \brief  Uesd as record controller SF1 channel's configuration on core4. */
DMA_LOCAL Dma_ChannelRegType Dma_SF1ChannelCore4[DMA_CHANNEL_SF1_ON_CORE4_NUMBER + 1U]
LOCATE_ALIGNED(DMA_CONFIG_ARCH_CACHE_LINE);
/** \brief  DMA controller SF1 base info on core4. */
DMA_LOCAL Dma_ControllerParamType Dma_ControllerSF1Core4 LOCATE_ALIGNED(DMA_CONFIG_ARCH_CACHE_LINE);
#define DMA_CORE4_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dma_MemMap.h"
#endif /** #if (DMA_CORE4_ENABLE == STD_ON) */
#endif /** #if (DMA_LOCK_STEP_MODE == STD_OFF) */

/********************************************************************************************************
 *                                  Private Constant Definitions                                        *
 *******************************************************************************************************/
/** Traceability       : SWSR_DMA_013 SW_SM008 */
/* Support multicore and initialization states */
#define DMA_START_SEC_CONST_UNSPECIFIED
#include "Dma_MemMap.h"
/** \brief  Each link list length on cores. */
DMA_LOCAL const uint32 Dma_LinkListLengthOnCore[DMA_CPU_ID_MAX] =
{
    DMA_IP_LINK_LIST_BUFFER_MAX_LENGTH(DMA_LINK_LIST_LENGTH_CORE0),
    DMA_IP_LINK_LIST_BUFFER_MAX_LENGTH(DMA_LINK_LIST_LENGTH_CORE1),
    DMA_IP_LINK_LIST_BUFFER_MAX_LENGTH(DMA_LINK_LIST_LENGTH_CORE2),
    DMA_IP_LINK_LIST_BUFFER_MAX_LENGTH(DMA_LINK_LIST_LENGTH_CORE3),
    DMA_IP_LINK_LIST_BUFFER_MAX_LENGTH(DMA_LINK_LIST_LENGTH_CORE4)
};

/** \brief  The table pointer to the Dma link list bitmap on each core. */
DMA_LOCAL uint32 *const Dma_LinkListBitmap[DMA_CPU_ID_MAX] =
{
#if (DMA_CORE0_ENABLE == STD_ON)
    &Dma_LinkListBitmapCore0[0U],
#else
    NULL_PTR,
#endif /** #if (DMA_CORE0_ENABLE == STD_ON) */
#if (DMA_CORE1_ENABLE == STD_ON)
    &Dma_LinkListBitmapCore1[0U],
#else
    NULL_PTR,
#endif /** #if (DMA_CORE1_ENABLE == STD_ON) */
#if (DMA_CORE2_ENABLE == STD_ON)
    &Dma_LinkListBitmapCore2[0U],
#else
    NULL_PTR,
#endif /** #if (DMA_CORE2_ENABLE == STD_ON) */
#if (DMA_CORE3_ENABLE == STD_ON)
    &Dma_LinkListBitmapCore3[0U],
#else
    NULL_PTR,
#endif /** #if (DMA_CORE3_ENABLE == STD_ON) */
#if (DMA_CORE4_ENABLE == STD_ON)
    &Dma_LinkListBitmapCore4[0U],
#else
    NULL_PTR,
#endif /** #if (DMA_CORE4_ENABLE == STD_ON) */
};

/** \brief  The table pointer to the Dma link list buffer on each core. *//* PRQA S 3218 1 */
DMA_LOCAL Dma_linkListType *const Dma_LinkListBuffer[DMA_CPU_ID_MAX] =
{
#if (DMA_CORE0_ENABLE == STD_ON)
    &Dma_LinkListBufferCore0[0U],
#else
    NULL_PTR,
#endif /** #if (DMA_CORE0_ENABLE == STD_ON) */
#if (DMA_CORE1_ENABLE == STD_ON)
    &Dma_LinkListBufferCore1[0U],
#else
    NULL_PTR,
#endif /** #if (DMA_CORE1_ENABLE == STD_ON) */
#if (DMA_CORE2_ENABLE == STD_ON)
    &Dma_LinkListBufferCore2[0U],
#else
    NULL_PTR,
#endif /** #if (DMA_CORE2_ENABLE == STD_ON) */
#if (DMA_CORE3_ENABLE == STD_ON)
    &Dma_LinkListBufferCore3[0U],
#else
    NULL_PTR,
#endif /** #if (DMA_CORE3_ENABLE == STD_ON) */
#if (DMA_CORE4_ENABLE == STD_ON)
    &Dma_LinkListBufferCore4[0U],
#else
    NULL_PTR,
#endif /** #if (DMA_CORE4_ENABLE == STD_ON) */
};

/** \brief  The table pointer to the DMA controller SF0 channel's configuration on each core. *//* PRQA S 3218 1 */
DMA_LOCAL Dma_ChannelRegType *const Dma_SF0Channel[DMA_CPU_ID_MAX] =
{
#if (DMA_CORE0_ENABLE == STD_ON)
    &Dma_SF0ChannelCore0[0U],
#else
    NULL_PTR,
#endif /** #if (DMA_CORE0_ENABLE == STD_ON) */
#if (DMA_CORE1_ENABLE == STD_ON)
    &Dma_SF0ChannelCore1[0U],
#else
    NULL_PTR,
#endif /** #if (DMA_CORE1_ENABLE == STD_ON) */
#if (DMA_CORE2_ENABLE == STD_ON)
    &Dma_SF0ChannelCore2[0U],
#else
    NULL_PTR,
#endif /** #if (DMA_CORE2_ENABLE == STD_ON) */
#if (DMA_CORE3_ENABLE == STD_ON)
    &Dma_SF0ChannelCore3[0U],
#else
    NULL_PTR,
#endif /** #if (DMA_CORE3_ENABLE == STD_ON) */
#if (DMA_CORE4_ENABLE == STD_ON)
    &Dma_SF0ChannelCore4[0U],
#else
    NULL_PTR,
#endif /** #if (DMA_CORE4_ENABLE == STD_ON) */
};

/** \brief  The table pointer to the DMA controller SF0 basic configuration on each core. */
DMA_LOCAL Dma_ControllerParamType *const Dma_ControllerSF0[DMA_CPU_ID_MAX] =
{
#if (DMA_CORE0_ENABLE == STD_ON)
    &Dma_ControllerSF0Core0,
#else
    NULL_PTR,
#endif /** #if (DMA_CORE0_ENABLE == STD_ON) */
#if (DMA_CORE1_ENABLE == STD_ON)
    &Dma_ControllerSF0Core1,
#else
    NULL_PTR,
#endif /** #if (DMA_CORE1_ENABLE == STD_ON) */
#if (DMA_CORE2_ENABLE == STD_ON)
    &Dma_ControllerSF0Core2,
#else
    NULL_PTR,
#endif /** #if (DMA_CORE2_ENABLE == STD_ON) */
#if (DMA_CORE3_ENABLE == STD_ON)
    &Dma_ControllerSF0Core3,
#else
    NULL_PTR,
#endif /** #if (DMA_CORE3_ENABLE == STD_ON) */
#if (DMA_CORE4_ENABLE == STD_ON)
    &Dma_ControllerSF0Core4,
#else
    NULL_PTR,
#endif /** #if (DMA_CORE4_ENABLE == STD_ON) */
};

#if (DMA_LOCK_STEP_MODE == STD_OFF)
/** \brief  The table pointer to the DMA controller SF1 channel's configuration on each core. *//* PRQA S 3218 1 */
DMA_LOCAL Dma_ChannelRegType *const Dma_SF1Channel[DMA_CPU_ID_MAX] =
{
#if (DMA_CORE0_ENABLE == STD_ON)
    &Dma_SF1ChannelCore0[0U],
#else
    NULL_PTR,
#endif /** #if (DMA_CORE0_ENABLE == STD_ON) */
#if (DMA_CORE1_ENABLE == STD_ON)
    &Dma_SF1ChannelCore1[0U],
#else
    NULL_PTR,
#endif /** #if (DMA_CORE1_ENABLE == STD_ON) */
#if (DMA_CORE2_ENABLE == STD_ON)
    &Dma_SF1ChannelCore2[0U],
#else
    NULL_PTR,
#endif /** #if (DMA_CORE2_ENABLE == STD_ON) */
#if (DMA_CORE3_ENABLE == STD_ON)
    &Dma_SF1ChannelCore3[0U],
#else
    NULL_PTR,
#endif /** #if (DMA_CORE3_ENABLE == STD_ON) */
#if (DMA_CORE4_ENABLE == STD_ON)
    &Dma_SF1ChannelCore4[0U],
#else
    NULL_PTR,
#endif /** #if (DMA_CORE4_ENABLE == STD_ON) */
};

/** \brief  The table pointer to the DMA controller SF1 basic configuration on each core. */
DMA_LOCAL Dma_ControllerParamType *const Dma_ControllerSF1[DMA_CPU_ID_MAX] =
{
#if (DMA_CORE0_ENABLE == STD_ON)
    &Dma_ControllerSF1Core0,
#else
    NULL_PTR,
#endif /** #if (DMA_CORE0_ENABLE == STD_ON) */
#if (DMA_CORE1_ENABLE == STD_ON)
    &Dma_ControllerSF1Core1,
#else
    NULL_PTR,
#endif /** #if (DMA_CORE1_ENABLE == STD_ON) */
#if (DMA_CORE2_ENABLE == STD_ON)
    &Dma_ControllerSF1Core2,
#else
    NULL_PTR,
#endif /** #if (DMA_CORE2_ENABLE == STD_ON) */
#if (DMA_CORE3_ENABLE == STD_ON)
    &Dma_ControllerSF1Core3,
#else
    NULL_PTR,
#endif /** #if (DMA_CORE3_ENABLE == STD_ON) */
#if (DMA_CORE4_ENABLE == STD_ON)
    &Dma_ControllerSF1Core4,
#else
    NULL_PTR,
#endif /** #if (DMA_CORE4_ENABLE == STD_ON) */
};
#endif /** #if (DMA_LOCK_STEP_MODE == STD_OFF) */

/** \brief  MAD crc lookup table. *//* PRQA S 3218 1 */
DMA_LOCAL const uint32 Dma_Crc32Table[256U] =
{
    0x00000000U, 0x04C11DB7U, 0x09823B6EU, 0x0D4326D9U, 0x130476DCU, 0x17C56B6BU,
    0x1A864DB2U, 0x1E475005U, 0x2608EDB8U, 0x22C9F00FU, 0x2F8AD6D6U, 0x2B4BCB61U,
    0x350C9B64U, 0x31CD86D3U, 0x3C8EA00AU, 0x384FBDBDU, 0x4C11DB70U, 0x48D0C6C7U,
    0x4593E01EU, 0x4152FDA9U, 0x5F15ADACU, 0x5BD4B01BU, 0x569796C2U, 0x52568B75U,
    0x6A1936C8U, 0x6ED82B7FU, 0x639B0DA6U, 0x675A1011U, 0x791D4014U, 0x7DDC5DA3U,
    0x709F7B7AU, 0x745E66CDU, 0x9823B6E0U, 0x9CE2AB57U, 0x91A18D8EU, 0x95609039U,
    0x8B27C03CU, 0x8FE6DD8BU, 0x82A5FB52U, 0x8664E6E5U, 0xBE2B5B58U, 0xBAEA46EFU,
    0xB7A96036U, 0xB3687D81U, 0xAD2F2D84U, 0xA9EE3033U, 0xA4AD16EAU, 0xA06C0B5DU,
    0xD4326D90U, 0xD0F37027U, 0xDDB056FEU, 0xD9714B49U, 0xC7361B4CU, 0xC3F706FBU,
    0xCEB42022U, 0xCA753D95U, 0xF23A8028U, 0xF6FB9D9FU, 0xFBB8BB46U, 0xFF79A6F1U,
    0xE13EF6F4U, 0xE5FFEB43U, 0xE8BCCD9AU, 0xEC7DD02DU, 0x34867077U, 0x30476DC0U,
    0x3D044B19U, 0x39C556AEU, 0x278206ABU, 0x23431B1CU, 0x2E003DC5U, 0x2AC12072U,
    0x128E9DCFU, 0x164F8078U, 0x1B0CA6A1U, 0x1FCDBB16U, 0x018AEB13U, 0x054BF6A4U,
    0x0808D07DU, 0x0CC9CDCAU, 0x7897AB07U, 0x7C56B6B0U, 0x71159069U, 0x75D48DDEU,
    0x6B93DDDBU, 0x6F52C06CU, 0x6211E6B5U, 0x66D0FB02U, 0x5E9F46BFU, 0x5A5E5B08U,
    0x571D7DD1U, 0x53DC6066U, 0x4D9B3063U, 0x495A2DD4U, 0x44190B0DU, 0x40D816BAU,
    0xACA5C697U, 0xA864DB20U, 0xA527FDF9U, 0xA1E6E04EU, 0xBFA1B04BU, 0xBB60ADFCU,
    0xB6238B25U, 0xB2E29692U, 0x8AAD2B2FU, 0x8E6C3698U, 0x832F1041U, 0x87EE0DF6U,
    0x99A95DF3U, 0x9D684044U, 0x902B669DU, 0x94EA7B2AU, 0xE0B41DE7U, 0xE4750050U,
    0xE9362689U, 0xEDF73B3EU, 0xF3B06B3BU, 0xF771768CU, 0xFA325055U, 0xFEF34DE2U,
    0xC6BCF05FU, 0xC27DEDE8U, 0xCF3ECB31U, 0xCBFFD686U, 0xD5B88683U, 0xD1799B34U,
    0xDC3ABDEDU, 0xD8FBA05AU, 0x690CE0EEU, 0x6DCDFD59U, 0x608EDB80U, 0x644FC637U,
    0x7A089632U, 0x7EC98B85U, 0x738AAD5CU, 0x774BB0EBU, 0x4F040D56U, 0x4BC510E1U,
    0x46863638U, 0x42472B8FU, 0x5C007B8AU, 0x58C1663DU, 0x558240E4U, 0x51435D53U,
    0x251D3B9EU, 0x21DC2629U, 0x2C9F00F0U, 0x285E1D47U, 0x36194D42U, 0x32D850F5U,
    0x3F9B762CU, 0x3B5A6B9BU, 0x0315D626U, 0x07D4CB91U, 0x0A97ED48U, 0x0E56F0FFU,
    0x1011A0FAU, 0x14D0BD4DU, 0x19939B94U, 0x1D528623U, 0xF12F560EU, 0xF5EE4BB9U,
    0xF8AD6D60U, 0xFC6C70D7U, 0xE22B20D2U, 0xE6EA3D65U, 0xEBA91BBCU, 0xEF68060BU,
    0xD727BBB6U, 0xD3E6A601U, 0xDEA580D8U, 0xDA649D6FU, 0xC423CD6AU, 0xC0E2D0DDU,
    0xCDA1F604U, 0xC960EBB3U, 0xBD3E8D7EU, 0xB9FF90C9U, 0xB4BCB610U, 0xB07DABA7U,
    0xAE3AFBA2U, 0xAAFBE615U, 0xA7B8C0CCU, 0xA379DD7BU, 0x9B3660C6U, 0x9FF77D71U,
    0x92B45BA8U, 0x9675461FU, 0x8832161AU, 0x8CF30BADU, 0x81B02D74U, 0x857130C3U,
    0x5D8A9099U, 0x594B8D2EU, 0x5408ABF7U, 0x50C9B640U, 0x4E8EE645U, 0x4A4FFBF2U,
    0x470CDD2BU, 0x43CDC09CU, 0x7B827D21U, 0x7F436096U, 0x7200464FU, 0x76C15BF8U,
    0x68860BFDU, 0x6C47164AU, 0x61043093U, 0x65C52D24U, 0x119B4BE9U, 0x155A565EU,
    0x18197087U, 0x1CD86D30U, 0x029F3D35U, 0x065E2082U, 0x0B1D065BU, 0x0FDC1BECU,
    0x3793A651U, 0x3352BBE6U, 0x3E119D3FU, 0x3AD08088U, 0x2497D08DU, 0x2056CD3AU,
    0x2D15EBE3U, 0x29D4F654U, 0xC5A92679U, 0xC1683BCEU, 0xCC2B1D17U, 0xC8EA00A0U,
    0xD6AD50A5U, 0xD26C4D12U, 0xDF2F6BCBU, 0xDBEE767CU, 0xE3A1CBC1U, 0xE760D676U,
    0xEA23F0AFU, 0xEEE2ED18U, 0xF0A5BD1DU, 0xF464A0AAU, 0xF9278673U, 0xFDE69BC4U,
    0x89B8FD09U, 0x8D79E0BEU, 0x803AC667U, 0x84FBDBD0U, 0x9ABC8BD5U, 0x9E7D9662U,
    0x933EB0BBU, 0x97FFAD0CU, 0xAFB010B1U, 0xAB710D06U, 0xA6322BDFU, 0xA2F33668U,
    0xBCB4666DU, 0xB8757BDAU, 0xB5365D03U, 0xB1F740B4U
};
#define DMA_STOP_SEC_CONST_UNSPECIFIED
#include "Dma_MemMap.h"
/********************************************************************************************************
 *                                  Global Variable Declarations                                        *
 *******************************************************************************************************/
#define DMA_START_SEC_CODE
#include "Dma_MemMap.h"
/********************************************************************************************************
 *                                  Private Function Declarations                                       *
 *******************************************************************************************************/
DMA_LOCAL void Dma_Ip_CoreResetIrqState(uint32 dmaBaseAddress);
DMA_LOCAL uint8 Dma_Ip_GetChannelPsCnt(uint32 dmaBaseAddress, uint32 channel);
DMA_LOCAL uint32 Dma_Ip_ReadChannelRegisterBits(uint32 dmaBaseAddress, uint32 channelId,
        uint32 regOffset, uint8 offset, uint8 size);
DMA_LOCAL void Dma_Ip_WriteChannelRegister(uint32 dmaBaseAddress, uint32 channelId, uint32 value,
        uint32 regOffset);
DMA_LOCAL void Dma_Ip_WriteChannelRegisterBits(uint32 dmaBaseAddress, uint32 channelId,
        uint32 regOffset,  uint32 offset, uint32 size, uint32 value);
DMA_LOCAL void Dma_Ip_GetLocalBufferProp(uint32 dmaBaseAddress, Dma_LocalBufferType *bufferProp);
DMA_LOCAL void Dma_Ip_SetChannelReadOutstanding(uint32 dmaBaseAddress, uint32 channelId,
        uint8 value);
DMA_LOCAL void Dma_Ip_SetChannelWriteOutstanding(uint32 dmaBaseAddress, uint32 channelId,
        uint8 value);
DMA_LOCAL void Dma_Ip_SetLocalValue(uint32 dmabaseAddress, uint32 channelId, uint32 value);
DMA_LOCAL Std_ReturnType Dma_Ip_SetChannelMuxId(Dma_ChannelRegType *dmaChannelPtr,
        uint32 dmaBaseAddress, uint32 channelId);
DMA_LOCAL uint16 Dma_Ip_GetMuxId(const Dma_MuxParamType *table, uint32 tableLength,
                                 Dma_MuxDirectionType direct, uint32 peripheralAddress);
DMA_LOCAL Dma_linkListType *Dma_Ip_SetLinkList(Dma_ChannelRegType *dmaChannel, uint32 length,
        uint32 blockSize, uint32 param);
DMA_LOCAL uint32 Dma_Ip_GetMaxBlockSize(Dma_LoopModeType loopMode);
DMA_LOCAL uint32 Dma_Ip_SetChannelCmd(uint32 dmaBaseAddress, uint32 channelId,
                                      Dma_ChannelControlStateType command);
DMA_LOCAL boolean Dma_Ip_GetChannelLastMadDone(uint32 dmaBaseAddress, uint32 channelId);
DMA_LOCAL uint32 Dma_Ip_GetChannelEnable(uint32 dmaBaseAddress, uint32 channelId);
DMA_LOCAL void Dma_Ip_EnableChannel(uint32 dmaBaseAddress, uint32 channelId, uint8 psCnt);
DMA_LOCAL Std_ReturnType Dma_Ip_SetChannelSoftwareHandshake(uint32 dmaBaseAddress,
        uint32 channelId);
DMA_LOCAL void Dma_Ip_SetMad(uint32 dmabaseAddress, uint32 channelId,
                             const Dma_LinkListNodeConfigType *const item);
DMA_LOCAL Std_ReturnType Dma_Ip_CalculateMadCrc(uint32 initValue, Dma_LinkListNodeConfigType *head,
        Dma_MadCrcModeType crcMode);
DMA_LOCAL_INLINE uint32 Dma_Ip_Crc32(uint32 crc, const uint8 *buffer, uint32 length);
DMA_LOCAL Dma_linkListType *Dma_Ip_GetLinkListDesc(const Dma_LinkListDescType *const linkListDesc);
DMA_LOCAL uint32 Dma_Ip_GetBufferSize(Dma_LoopModeType loopMode, uint32 total, uint32 period);
DMA_LOCAL void Dma_Ip_FormatMad(const Dma_DeviceConfigType *const config,
                                Dma_LinkListNodeConfigType *item, Dma_MadCrcModeType madCrcMode);
DMA_LOCAL void Dma_Ip_SetInterruptState(uint32 dmaBaseAddress, uint32 channelId,
                                        const Dma_DeviceConfigType *const deviceConfigPtr);
DMA_LOCAL uint8 Dma_Ip_Clz32(uint32 param);
DMA_LOCAL Std_ReturnType Dma_Ip_FreeLinkListDesc(Dma_linkListType *linkListDesc);
DMA_LOCAL uint32 Dma_Ip_ReadChannelRegister(uint32 dmaBaseAddress, uint32 channelId,
        uint32 regOffset);
DMA_LOCAL Std_ReturnType Dma_Ip_GetCoreVarFromAddress(uint32 baseAddress,
        Dma_ControllerParamType **controllerParam);
DMA_LOCAL Std_ReturnType Dma_Ip_GetCoreVarFromControllId(Dma_HwControllerType controllerId,
        Dma_ControllerParamType **controllerParam);
DMA_LOCAL Std_ReturnType Dma_Ip_CheckAddressAndChannelValid(uint32 dmabaseAddress,
        uint32 channelId);
DMA_LOCAL Std_ReturnType Dma_Ip_CheckKernalVar(const Dma_ChannelRegType *const dmaChannel);
DMA_LOCAL uint8 Dma_Ip_Ffs32(uint32 val);
DMA_LOCAL uint8 Dma_Ip_BitmapSet(uint32 *bitmap, uint32 bit);
DMA_LOCAL boolean Dma_Ip_BitmapClear(uint32 *bitmap, uint32 bit);
DMA_LOCAL uint8 Dma_Ip_ffz(uint32 x);
DMA_LOCAL uint32 Dma_Ip_BitmapFfz(const uint32 *const bitmap, uint32 numbits);
DMA_LOCAL void Dma_Ip_SetLinkListDaughter(Dma_linkListType *current,
        Dma_DeviceConfigType *linkListConfig, const Dma_ChannelRegType *const dmaChannel,
        const Dma_linkListType *const first, uint32 offset);
DMA_LOCAL void Dma_Ip_SetMadFlag(Dma_TransactionType transactionType,
                                 Dma_DeviceConfigType *linkListConfig, uint32 offset, uint32 trLength, uint32 length);
DMA_LOCAL uint32 Dma_Ip_GetTransferLength(const Dma_ChannelRegType *const dmaChannel, uint32 offset,
        uint32 length, uint32 blockSize, uint32 periodLength);
DMA_LOCAL_INLINE Dma_ChannelRegType *Dma_Ip_ToChannel(const Dma_ChannelConfigType *const
        channelPtr);
DMA_LOCAL_INLINE void Dma_Ip_ListInitialize(struct Dma_ListNodeType *list);
DMA_LOCAL_INLINE void Dma_Ip_ListAddTail(struct Dma_ListNodeType *list, struct Dma_ListNodeType *item);
DMA_LOCAL_INLINE void Dma_Ip_ListDelete(struct Dma_ListNodeType *item);
DMA_LOCAL uint32 Dma_Ip_GetInterruptState(uint32 dmaBaseAddress, uint32 channelId);
DMA_LOCAL void Dma_Ip_ClearInterrupt(uint32 dmaBaseAddress, uint32 channelId, uint32 status);
/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
/** *****************************************************************************************************
 * \brief This function get DMA controller core variables according to base address.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_Ip_GetCoreVarFromAddress
 *                      (
 *                          uint32 baseAddress
 *                          Dma_ControllerParamType **controllerParam
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : baseAddress       - Dma controller base address.
 *
 * Parameters (inout) : **controllerParam - Pointer to a configuration structure.
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Get core variable successful.
 *                      E_NOT_OK: No dma channels are allocated on this core.
 *                      DMA_E_PARAMS: Input parameter error.
 *
 * Description        : This function get DMA controller core variables according to base address.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_049 SW_SM006
 *******************************************************************************************************/
DMA_LOCAL Std_ReturnType Dma_Ip_GetCoreVarFromAddress(uint32 baseAddress,
        Dma_ControllerParamType **controllerParam)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;
    uint8 coreId = Dma_Ip_GetCoreId();

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Returns different controller variables address depending on the Dma base address. */
    if (DMA_SF0_BASE == baseAddress)
    {
        if (NULL_PTR == Dma_ControllerSF0[coreId])
        {
            errorId = DMA_E_PARAM_POINTER;
        }
        else
        {
            (*controllerParam) = Dma_ControllerSF0[coreId];
        }
    }

#if (DMA_LOCK_STEP_MODE == STD_OFF)
    else if (DMA_SF1_BASE == baseAddress)
    {
        if (NULL_PTR == Dma_ControllerSF1[coreId])
        {
            errorId = DMA_E_PARAM_POINTER;
        }
        else
        {
            (*controllerParam) = Dma_ControllerSF1[coreId];
        }
    }

#endif /** #if (DMA_LOCK_STEP_MODE == STD_OFF) */
    else
    {
        errorId = DMA_E_PARAMS;
    }

    return errorId;
}
/** *****************************************************************************************************
 * \brief This function get DMA controller core variables according to controller id.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_Ip_GetCoreVarFromControllId
 *                      (
 *                          Dma_HwControllerType controllerId
 *                          Dma_ControllerParamType **controllerParam
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : controllerId      - Numeric identifier of the DMA controller.
 *
 * Parameters (inout) : **controllerParam - Pointer to a configuration structure.
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Get core variable successful.
 *                      E_NOT_OK: No dma channels are allocated on this core.
 *                      DMA_E_PARAMS: Input parameter error.
 *
 * Description        : This function get DMA controller core variables according to controller id.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_049 SW_SM006
 *******************************************************************************************************/
DMA_LOCAL Std_ReturnType Dma_Ip_GetCoreVarFromControllId(Dma_HwControllerType controllerId,
        Dma_ControllerParamType **controllerParam)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;
    uint8 coreId = Dma_Ip_GetCoreId();

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Returns different controller variables address depending on the Dma controller id. */
    if (DMA_HW_SF0 == controllerId)
    {
        if (NULL_PTR == Dma_ControllerSF0[coreId])
        {
            errorId = DMA_E_PARAM_POINTER;
        }
        else
        {
            (*controllerParam) = Dma_ControllerSF0[coreId];
        }
    }

#if (DMA_LOCK_STEP_MODE == STD_OFF)
    else if (DMA_HW_SF1 == controllerId)
    {
        if (NULL_PTR == Dma_ControllerSF1[coreId])
        {
            errorId = DMA_E_PARAM_POINTER;
        }
        else
        {
            (*controllerParam) = Dma_ControllerSF1[coreId];
        }
    }

#endif /** #if (DMA_LOCK_STEP_MODE == STD_OFF) */
    else
    {
        errorId = DMA_E_PARAMS;
    }

    return errorId;
}
/** *****************************************************************************************************
 * \brief This function initialize DMA controller ip layer.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_Ip_Init
 *                      (
 *                          const Dma_HwConfigType *config
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *config      - Pointer to configuration set.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Get core variable successful.
 *                      DMA_E_CONFIG_POINTER: Config pointer is NULL_PTR.
 *                      DMA_E_PARAMS: Input parameter error.
 *
 * Description        : This function initialize DMA controller ip layer.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_004 SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_049 SW_SM006
 *******************************************************************************************************/
Std_ReturnType Dma_Ip_Init(const Dma_HwConfigType *config)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;
    uint32 index;
    uint8 coreId;
    Dma_ChannelRegType *channelReg;
    uint32 *dmaFIFOAddr;
    Dma_ControllerParamType *controllerParam = NULL_PTR;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check input parameters for plausibility */
    if (NULL_PTR == config)
    {
        errorId = DMA_E_CONFIG_POINTER;
    }
    else if (E_OK != Dma_Ip_GetCoreVarFromAddress(config->baseAddress, &controllerParam))
    {
        errorId = DMA_E_PARAMS;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        coreId = Dma_Ip_GetCoreId();

        /* #20 Copy the number of base address core channels assigned to this core to the global controller variable */
        controllerParam->dmaBaseAddress = config->baseAddress;
        controllerParam->channelNumber = config->channelNumber;
        /* #30 Initial dma channel link list */
        Dma_Ip_ListInitialize(&controllerParam->channels);

        /* #40 Clear Dma FIFO *//* PRQA S 0306 1 */
        dmaFIFOAddr = (uint32 *)((config->baseAddress) + DMA_IP_FIFO_OFFSET);

        for (index = 0U; index < DMA_IP_FIFO_WORDS; index++)
        {
            dmaFIFOAddr[index] = 0U;
        }

        /* #50 Clear dma core interrupt status */
        Dma_Ip_CoreResetIrqState(controllerParam->dmaBaseAddress);

        /* #60 Initial Dma controller channels assigned to this core configuration parameters. */
        for (index = 0U; index < controllerParam->channelNumber; index++)
        {
            if (DMA_SF0_BASE == controllerParam->dmaBaseAddress)
            {
                channelReg = &Dma_SF0Channel[coreId][index];
            }

#if (DMA_LOCK_STEP_MODE == STD_OFF)
            else if (DMA_SF1_BASE == controllerParam->dmaBaseAddress)
            {
                channelReg = &Dma_SF1Channel[coreId][index];
            }

#endif /** #if (DMA_LOCK_STEP_MODE == STD_OFF) */
            else
            {
                channelReg = NULL_PTR;
            }

            if (NULL_PTR == channelReg)
            {
                errorId = DMA_E_CONFIG_POINTER;
            }
            else
            {
                channelReg->channel.channelId = config->channelIdTable[index];
                channelReg->channel.allocated = FALSE;
                channelReg->channel.device    = controllerParam;
                channelReg->channel.channelStatus = DMA_COMPLETED;
                channelReg->blockSize = DMA_IP_MAX_BLOCK_SIZE;
                channelReg->dmaConfig.hwConfig = config;
                Dma_Ip_ListAddTail(&controllerParam->channels, &channelReg->channel.node);
            }
        }
    }

    return errorId;
}
/** *****************************************************************************************************
 * \brief This function reset DMA core interrupt states.
 *
 * \verbatim
 * Syntax             : void Dma_Ip_CoreResetIrqState
 *                      (
 *                          uint32 dmaBaseAddress
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : dmaBaseAddress - Dma controller base address.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function reset DMA core interrupt states.
 *
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
DMA_LOCAL void Dma_Ip_CoreResetIrqState(uint32 dmaBaseAddress)
{
    /* ----- Implementation ----------------------------------------------- */
    /* #10 Clear dma core interrupt status */
    writel(DMA_CLEAR_ALL_INTERRUPT_STATUS, dmaBaseAddress + DMA_IP_CORE_CONT_DMA_INT_CLR_REG);
    writel(DMA_DISABLE_ALL_INTERRUPT, dmaBaseAddress + DMA_IP_CORE_CONT_DMA_INT_CLR_REG);
    writel(DMA_CLEAR_ALL_INTERRUPT_STATUS, dmaBaseAddress + DMA_IP_CORE_INT_CLR_REG);
    writel(DMA_DISABLE_ALL_INTERRUPT, dmaBaseAddress + DMA_IP_CORE_INT_CLR_REG);
}
/** *****************************************************************************************************
 * \brief This function servce to request DMA controller channel.
 *
 * \verbatim
 * Syntax             : Dma_ChannelConfigType *Dma_Ip_ChannelRequest
 *                      (
 *                          Dma_HwControllerType controllerId
 *                          uint32 channelId
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : controllerId - Dma controller base address.
 *                      channelId    - Numeric identifier of the DMA controller.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : cptr: If request channel is successful, return the channel's configuration
 *                      pointer.
 *
 * Description        : Only request channel(s) that have been configured in EB. If request is
 *                      successful, the channel will be marked as allocated.
 *
 * \endverbatim
 * Traceability       : SWSR_DMA_049 SW_SM006
 *******************************************************************************************************/
Dma_ChannelConfigType *Dma_Ip_ChannelRequest(Dma_HwControllerType controllerId, uint32 channelId)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint8 findResult = FALSE;
    Dma_ChannelConfigType *cptr;
    Dma_ChannelRegType *dmac;
    Dma_ControllerParamType *controllerParam;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check input parameters for plausibility. */
    if (E_OK != Dma_Ip_GetCoreVarFromControllId(controllerId, &controllerParam))
    {
        cptr = NULL_PTR;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #20 Check whether the requested ID has been assigned to this core. *//* PRQA S 0306, 2810, 3432 1 */
        DMA_LIST_FOR_EVERY_ENTRY ((&controllerParam->channels), cptr, Dma_ChannelConfigType, node)
        {
            if (channelId == cptr->channelId)
            {
                /* #30 Check whether the requested ID has been allocated to user. */
                if (FALSE == cptr->allocated)
                {
                    cptr->irqCallback   = NULL_PTR;
                    cptr->context       = NULL_PTR;
                    cptr->channelStatus = DMA_COMPLETED;
                    cptr->allocated = TRUE;
                    findResult = TRUE;
                }
                else
                {
                    findResult = FALSE;
                }

                break;
            } /* else not needed */
        }

        if (FALSE == findResult)
        {
            cptr = NULL_PTR;
        }
        else
        {
            dmac = Dma_Ip_ToChannel(cptr);
            /* #40 Record the channel current program sequence counter */
            dmac->psCnt = Dma_Ip_GetChannelPsCnt(controllerParam->dmaBaseAddress, cptr->channelId);
        }
    }

    return cptr;
}
/** *****************************************************************************************************
 * \brief This function servce to release DMA controller channel.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_Ip_ChannelFree
 *                      (
 *                          Dma_ChannelConfigType *channel
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *channel - Pointer to a selected channel configuration structure.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Release successful.
 *                      DMA_E_PARAM_POINTER: Pointer is NULL_PTR.
 *
 * Description        : Release the DMA channel so that the new request can succeed, if the release
 *                      is successful, the channel status is set to unallocated.
 * \endverbatim
 * Traceability       : SWSR_DMA_049 SW_SM007 SW_SM006
 *******************************************************************************************************/
Std_ReturnType Dma_Ip_ChannelFree(Dma_ChannelConfigType *channel)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId;
    Dma_ChannelRegType const *dmaChannel = Dma_Ip_ToChannel(channel);

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check input parameters for plausibility. */
    if (NULL_PTR == dmaChannel)
    {
        errorId = DMA_E_PARAM_POINTER;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_00();
        /* #20 Clear current channel allocated state. */
        channel->allocated = FALSE;
        channel->irqCallback   = NULL_PTR;
        channel->context       = NULL_PTR;
        /* #30 Free current channel link list. *//* PRQA S 0306 1 */
        errorId = Dma_Ip_FreeLinkListDesc((Dma_linkListType *)dmaChannel->linkListDesc.physisAddress);
        SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_00();
    }

    return errorId;
}
/** *****************************************************************************************************
 * \brief This function servce to set configuration pointer to an initial value.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_Ip_DeviceConfig
 *                      (
 *                          const Dma_ChannelConfigType * const channel
 *                          const Dma_DeviceConfigType * const config
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *channel - Pointer to a selected channel configuration structure.
 *                      *config  - Pointer to a user configuration parameters.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Copy configuration parameters successful.
 *                      DMA_E_PARAM_POINTER: Pointer is NULL_PTR.
 *
 * Description        : Copy DMA register configuration parameters to selected channel.
 * \endverbatim
 * Traceability       : SWSR_DMA_006 SWSR_DMA_007 SWSR_DMA_008 SWSR_DMA_009 SWSR_DMA_010 SWSR_DMA_011
 *                      SWSR_DMA_012 SWSR_DMA_014 SWSR_DMA_016 SWSR_DMA_049 SW_SM007 SW_SM006
 *******************************************************************************************************/
Std_ReturnType Dma_Ip_DeviceConfig(const Dma_ChannelConfigType *const channel,
                                   const Dma_DeviceConfigType *const config)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;
    Dma_ChannelRegType *dmaChannel = Dma_Ip_ToChannel(channel);

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check input parameters for plausibility. */
    if (NULL_PTR == dmaChannel)
    {
        errorId = DMA_E_PARAM_POINTER;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_00();
        /* #20 Copy user configurations to current channel. */
        dmaChannel->deviceConfig = (*config);
        SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_00();
    }

    return errorId;
}
/** *****************************************************************************************************
 * \brief This function servce to check channel configuration parameters for plausibility.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_Ip_CheckKernalVar
 *                      (
 *                          const Dma_ChannelRegType * const dmaChannel
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *dmaChannel - Pointer to a selected channel configuration structure.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Check configuration parameters passed.
 *                      DMA_E_PARAMS: Input parameter error.
 *                      DMA_E_PARAM_POINTER: Pointer is NULL_PTR.
 *
 * Description        : Check channel configuration parameters for plausibility.
 * \endverbatim
 * Traceability       : SWSR_DMA_049 SW_SM006
 *******************************************************************************************************/
DMA_LOCAL Std_ReturnType Dma_Ip_CheckKernalVar(const Dma_ChannelRegType *const dmaChannel)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check input parameters for plausibility. */
    if (NULL_PTR == dmaChannel)
    {
        errorId = DMA_E_PARAM_POINTER;
    }
    else if (dmaChannel->deviceConfig.transaction > DMA_CYCLIC)
    {
        errorId = DMA_E_PARAMS;
    }
    else if ((dmaChannel->deviceConfig.direction > DMA_DEVICE_TO_DEVICE)
             || (dmaChannel->deviceConfig.processMode > DMA_POLLING))
    {
        errorId = DMA_E_PARAMS;
    }
    else if ((dmaChannel->deviceConfig.srcBusWidth > DMA_BEAT_SIZE_8_BYTE)
             || (dmaChannel->deviceConfig.dstBusWidth > DMA_BEAT_SIZE_8_BYTE))
    {
        errorId = DMA_E_PARAMS;
    }
    else if ((dmaChannel->deviceConfig.srcMaxBurst > DMA_BURST_LENGTH_16)
             || (dmaChannel->deviceConfig.dstMaxBurst > DMA_BURST_LENGTH_16))
    {
        errorId = DMA_E_PARAMS;
    }
    else if ((dmaChannel->deviceConfig.srcPortSelect > DMA_PORT_AHB32)
             || (dmaChannel->deviceConfig.dstPortSelect > DMA_PORT_AHB32))
    {
        errorId = DMA_E_PARAMS;
    }
    else if ((dmaChannel->deviceConfig.srcIncDirection > DMA_BURST_FIXED)
             || (dmaChannel->deviceConfig.dstIncDirection > DMA_BURST_FIXED))
    {
        errorId = DMA_E_PARAMS;
    }
    else if ((dmaChannel->deviceConfig.srcStridePol > DMA_NEGATIVE_OFFSET)
             || (dmaChannel->deviceConfig.dstStridePol > DMA_NEGATIVE_OFFSET))
    {
        errorId = DMA_E_PARAMS;
    }
    else if ((dmaChannel->deviceConfig.srcStrideSelect > DMA_SFSTD)
             || (dmaChannel->deviceConfig.dstStrideSelect > DMA_SFSTD))
    {
        errorId = DMA_E_PARAMS;
    }
    /* #20 Only support single buffer. */
    else if ((dmaChannel->deviceConfig.bufferMode > DMA_2D_BUFFER)
             || (dmaChannel->deviceConfig.loopMode > DMA_LOOP_MODE_2))
    {
        errorId = DMA_E_PARAMS;
    }
    else if ((dmaChannel->deviceConfig.flowControl > DMA_DIR_DEVICE_TO_REGISTER)
             || (dmaChannel->deviceConfig.transferMode > DMA_TRANSFER_MODE_CHAN_LINK))
    {
        errorId = DMA_E_PARAMS;
    }
    else if ((dmaChannel->deviceConfig.linkListTriggerMode > DMA_TRIGGER_BY_INTERNAL_EVENT)
             || (dmaChannel->deviceConfig.madCrcMode > DMA_MAD_CRC))
    {
        errorId = DMA_E_PARAMS;
    }
    else if ((DMA_CYCLIC == dmaChannel->deviceConfig.transaction)
             && (DMA_TRANSFER_MODE_SINGLE == dmaChannel->deviceConfig.transferMode))
    {
        errorId = DMA_E_PARAMS;
    }
    else
    {
        /* Do Nothing */
    }

    return errorId;
}
/** *****************************************************************************************************
 * \brief This function servce to set channel register from user configuration parameters.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_Ip_ConfigTransfer
 *                      (
 *                          const Dma_ChannelConfigType * const channel
 *                          uint32 length
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *channel - Pointer to a selected channel configuration structure.
 *                      length   - Total transmit data length.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Check configuration parameters passed.
 *                      DMA_E_PARAMS: Input parameter error.
 *                      DMA_E_PARAM_POINTER: Pointer is NULL_PTR.
 *
 * Description        : Set channel register from user configuration parameters.
 * \endverbatim
 * Traceability       : SWSR_DMA_006 SWSR_DMA_007 SWSR_DMA_008 SWSR_DMA_009 SWSR_DMA_010 SWSR_DMA_011
 *                      SWSR_DMA_012 SWSR_DMA_013 SWSR_DMA_014 SWSR_DMA_015 SWSR_DMA_016 SWSR_DMA_020
 *                      SWSR_DMA_049 SW_SM007 SW_SM006
 *******************************************************************************************************/
Std_ReturnType Dma_Ip_ConfigTransfer(const Dma_ChannelConfigType *const channel, uint32 length)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;
    uint8 coreId;
    Dma_ChannelRegType *dmaChannel = Dma_Ip_ToChannel(channel);
    Dma_linkListType *linkListPtr;
    Dma_LocalBufferType localBuffer;
    uint32 memsetValue;

    /* Struct variables need to be defined first and then assigned initial values to avoid linking to
        rodata section in some compiler */
    localBuffer.bufferBaseAddress = 0UL;
    localBuffer.bufferSize = 0UL;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check input parameters for plausibility. */
    if ((Std_ReturnType)E_OK != Dma_Ip_CheckKernalVar(dmaChannel))
    {
        errorId = DMA_E_PARAMS;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        coreId = Dma_Ip_GetCoreId();

        if ((DMA_MEMCPY == dmaChannel->deviceConfig.transaction)
                || (DMA_MEMSET == dmaChannel->deviceConfig.transaction))
        {
            /* #20 Memory from/to memory. */
            Dma_Ip_GetLocalBufferProp(channel->device->dmaBaseAddress, &localBuffer);
            dmaChannel->deviceConfig.direction = DMA_MEMORY_TO_MEMORY;
            /* PRQA S 0306 1 */
            dmaChannel->linkListDesc.memBase = (Dma_linkListType *)(localBuffer.bufferBaseAddress);
            dmaChannel->linkListDesc.memBitmap = &Dma_LinkListBitmap[coreId][0U];
            dmaChannel->linkListDesc.memSize = Dma_LinkListLengthOnCore[coreId];
        }
        else
        {
            /* #30 Peripheral from/to memory. */
            dmaChannel->linkListDesc.memBase = &Dma_LinkListBuffer[coreId][0U];
            dmaChannel->linkListDesc.memBitmap = &Dma_LinkListBitmap[coreId][0U];
            dmaChannel->linkListDesc.memSize = Dma_LinkListLengthOnCore[coreId];
        }

        /* #40 Copy user configuration to channelConfig. */
        dmaChannel->dmaConfig.baseAddress = channel->device->dmaBaseAddress;
        /* #50 If enable stride and selected fine stride mode, this parameter will be set to STRIDE_CONFIG register. */

        if (DMA_MEMORY_TO_MEMORY == dmaChannel->deviceConfig.direction)
        {
            if (DMA_MEMSET == dmaChannel->deviceConfig.transaction)
            {
                /* #60 Set memset value to internal register and prepare for memory from memory transmission. */
                memsetValue = (uint32)(((uint32)dmaChannel->deviceConfig.memsetValue) | ((
                                           uint32)dmaChannel->deviceConfig.memsetValue << 8U) |
                                       ((uint32)dmaChannel->deviceConfig.memsetValue << 16U) | ((uint32)
                                               dmaChannel->deviceConfig.memsetValue << 24U));
                Dma_Ip_SetLocalValue(channel->device->dmaBaseAddress, channel->channelId, memsetValue);
            }/* else not needed */

            /* #70 Memory from/to memory high performance. */
            dmaChannel->deviceConfig.srcCache = FALSE;
            dmaChannel->deviceConfig.dstCache = TRUE;
        }
        else
        {
            /* #80 Peripheral from/to memory must set the mux id, which is hardware request signal used for handshaking between the peripheral and the dma channel. */
            errorId = Dma_Ip_SetChannelMuxId(dmaChannel, channel->device->dmaBaseAddress, channel->channelId);
        }

        if ((Std_ReturnType)E_OK == errorId)
        {
            SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_00();

            if (DMA_MEMORY_TO_MEMORY == dmaChannel->deviceConfig.direction)
            {
                /* #100 The memory from/to memory link list node address is the first MAD register SOURCE_ADDRESS. */
                linkListPtr = Dma_Ip_SetLinkList(dmaChannel, length,
                                                 Dma_Ip_GetMaxBlockSize(dmaChannel->deviceConfig.loopMode), dmaChannel->deviceConfig.periodLength);
            }
            else
            {
                /* #100 The peripheral from/to memory link list node address is link list buffer. */
                linkListPtr = Dma_Ip_SetLinkList(dmaChannel, length, dmaChannel->blockSize,
                                                 dmaChannel->deviceConfig.periodLength);

            }

            SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_00();

            if (NULL == linkListPtr)
            {
                errorId = E_NOT_OK;
            }
            else
            {
                SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_00();
                dmaChannel->channel.processMode = (Dma_EventProcessModeType)dmaChannel->deviceConfig.processMode;
                dmaChannel->length = length;

                /* #100 Calculate Dma MAD CRC value. Normally, timeout never occurrs. */
                errorId = Dma_Ip_CalculateMadCrc(0U, &linkListPtr->linkListItem,
                                                 dmaChannel->deviceConfig.madCrcMode);

                /* #110 Set MAD registers value to registers. */
                Dma_Ip_SetMad(channel->device->dmaBaseAddress, channel->channelId, &linkListPtr->linkListItem);

                SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_00();
            }
        }/* else not needed */
    }

    return errorId;
}
/** *****************************************************************************************************
 * \brief This function servce to set local value resgister, which used as memset or memclr.
 *
 * \verbatim
 * Syntax             : void Dma_Ip_SetLocalValue
 *                      (
 *                          uint32 dmabaseAddress
 *                          uint32 channelId
 *                          uint32 value
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : dmabaseAddress - Dma controller base address.
 *                      channelId      - Numeric identifier of the DMA channel.
 *                      value          - Local value will be set to register.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Set local value resgister, which used as memset or memclr. The channel transfer
 *                      direction is from local value register to user date buffer.
 *
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
DMA_LOCAL void Dma_Ip_SetLocalValue(uint32 dmabaseAddress, uint32 channelId, uint32 value)
{
    /* ----- Implementation ----------------------------------------------- */
    /* #10 Set memset value to internal register. */
    Dma_Ip_WriteChannelRegister(dmabaseAddress, channelId, value, DMA_IP_CH_FOR_FLOW_CTRL_SRC_DST_REG1);
    Dma_Ip_WriteChannelRegister(dmabaseAddress, channelId, value, DMA_IP_CH_FOR_FLOW_CTRL_SRC_DST_REG2);
}
/** *****************************************************************************************************
 * \brief This function service to start transmit data on the DMA channel.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_Ip_ChannelEnable
 *                      (
 *                          const Dma_ChannelConfigType * const channel
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *channel - Pointer to a selected channel configuration structure.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Check configuration parameters passed.
 *                      DMA_E_PARAM_POINTER: Pointer is NULL_PTR.
 *
 * Description        : Enable current DMA channel transfer. If current configuration is memory to/from
 *                      memory or memory to peripheral will start the transfer immediately, if current
 *                      configuration is peripheral to memory need to wait for hardware request.
 * \endverbatim
 * Traceability       : SWSR_DMA_049 SW_SM007 SW_SM006
 *******************************************************************************************************/
Std_ReturnType Dma_Ip_ChannelEnable(const Dma_ChannelConfigType *const channel)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;
    Dma_ChannelRegType *dmaChannel = Dma_Ip_ToChannel(channel);

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check input parameters for plausibility. */
    if (NULL_PTR == dmaChannel)
    {
        errorId = DMA_E_PARAM_POINTER;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #20 Clear current channel all interrupt status. */
        Dma_Ip_ClearInterrupt(channel->device->dmaBaseAddress, channel->channelId, 0xFFFFFFFFU);
        /* #30 Set DMA interrupt enable status. */
        Dma_Ip_SetInterruptState(channel->device->dmaBaseAddress, channel->channelId,
                                 &dmaChannel->deviceConfig);
        SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_00();
        /* #40 Mark current channel transfer status to in progress. */
        dmaChannel->channel.channelStatus = DMA_IN_PROGRESS;
        SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_00();
        /* #50 Write program sequence counter to PROGRAMM_SEQUENCE_CTRL to enable the channel to receive handshake signals. */
        Dma_Ip_EnableChannel(channel->device->dmaBaseAddress, channel->channelId, dmaChannel->psCnt);

        if (dmaChannel->deviceConfig.direction == DMA_MEMORY_TO_MEMORY)
        {
            /* #60 Launch software handshake signal. Only used for memory from/to memory. */
            errorId = Dma_Ip_SetChannelSoftwareHandshake(channel->device->dmaBaseAddress, channel->channelId);
        }/* else not needed */

    }

    return errorId;
}
/** *****************************************************************************************************
 * \brief This function service to stop transmit data on the DMA channel.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_Ip_ChannelDisable
 *                      (
 *                          const Dma_ChannelConfigType * const channel
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *channel - Pointer to a selected channel configuration structure.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Check configuration parameters passed.
 *                      DMA_E_PARAM_POINTER: Pointer is NULL_PTR.
 *
 * Description        : Disable current DMA channel transfer.
 * \endverbatim
 * Traceability       : SWSR_DMA_049 SW_SM007 SW_SM006
 *******************************************************************************************************/
Std_ReturnType Dma_Ip_ChannelDisable(const Dma_ChannelConfigType *const channel)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;
    uint32 channelEnable;
    Dma_ChannelRegType *dmacChannel = Dma_Ip_ToChannel(channel);

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check input parameters for plausibility. */
    if (NULL_PTR == dmacChannel)
    {
        errorId = DMA_E_PARAM_POINTER;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #20 Disable all interrupts. */
        Dma_Ip_WriteChannelRegister(channel->device->dmaBaseAddress, channel->channelId, 0x00000000UL,
                                DMA_IP_CH_INTERRUPT_ENABLE_REG);
        /* #30 Get the channel enable status. */
        channelEnable = Dma_Ip_GetChannelEnable(channel->device->dmaBaseAddress, channel->channelId);
        DmaHookTimeout_Dma_Ip_ChannelDisable();
        if (1U == channelEnable)
        {
            /* #40 Write abort command to the CHANNEL_CONFIG register to abort transfer immedimately. */
            if (0U == Dma_Ip_SetChannelCmd(channel->device->dmaBaseAddress, channel->channelId,
                                           DMA_CH_CTL_STAT_ABORT))
            {
                errorId = (Std_ReturnType)E_OK;
            }
            else
            {
                errorId = DMA_E_TIMEOUT;
            }

            /* #50 Flush to ack the dma request from peripherals. No need to care about the return value. */
            (void)Dma_Ip_SetChannelCmd(channel->device->dmaBaseAddress, channel->channelId,
                                       DMA_CH_CTL_STAT_REQ_FLUSH);
        }/* else not needed */
        SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_00();
        /* #60 Get the channel program sequence counter and used for next transfer. */
        dmacChannel->psCnt = Dma_Ip_GetChannelPsCnt(channel->device->dmaBaseAddress, channel->channelId);
        /* #70 Mark the channel transfer status to completed. */
        dmacChannel->channel.channelStatus = DMA_COMPLETED;
        SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_00();
    }

    return errorId;
}
/** *****************************************************************************************************
 * \brief This function service to returns the transmission status of the current channel0.
 *
 * \verbatim
 * Syntax             : Dma_ControllerStatusType Dma_Ip_GetChannelStatus
 *                      (
 *                          const Dma_ChannelConfigType * const channel
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *channel - Pointer to a selected channel configuration structure.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : DMA_COMPLETED     : Current channel transmission completed.
 *                      DMA_IN_PROGRESS   : Current channel transmission in progress.
 *
 * Description        : This function support only updating the source address, destination address an0d
 *                      transmit data length registers.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
Dma_ControllerStatusType Dma_Ip_GetChannelStatus(const Dma_ChannelConfigType *const channel)
{
    /* ----- Local Variables ---------------------------------------------- */
    Dma_ControllerStatusType status;

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Read lasd MAD done flag and judge transmission completed or not. */
    if (TRUE == Dma_Ip_GetChannelLastMadDone(channel->device->dmaBaseAddress, channel->channelId))
    {
        status = DMA_COMPLETED;
    }
    else
    {
        status = DMA_IN_PROGRESS;
    }

    return status;
}
/** *****************************************************************************************************
 * \brief This function service to get current channel last mad done status.
 *
 * \verbatim
 * Syntax             : boolean Dma_Ip_GetChannelLastMadDone
 *                      (
 *                          uint32 dmaBaseAddress
 *                          uint32 channelId
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : dmabaseAddress - Dma controller base address.
 *                      channelId      - Numeric identifier of the DMA channel.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : TRUE: Current channel transmission completed.
 *                      FALSE: Current channel transmission in progress.
 *
 * Description        : This function service to get current channel last mad done status.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
DMA_LOCAL boolean Dma_Ip_GetChannelLastMadDone(uint32 dmaBaseAddress, uint32 channelId)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint32 ret;
    /* #10 Read lasd MAD done flag. */
    uint32 channelIntStatus = Dma_Ip_GetInterruptState(dmaBaseAddress, channelId);

    /* ----- Implementation ----------------------------------------------- */
    /* #20 Check if the last MAD has been completed. */
    if ((channelIntStatus & (uint32)DMA_CH_INT_EN_LST_MAD_DONE) > 0U)
    {
        /* #30 Current channel transmission completed. */
        ret = TRUE;
    }
    else
    {
        /* #40 Current channel transmission in progress. */
        ret = FALSE;
    }

    return (boolean)ret;
}
/** *****************************************************************************************************
 * \brief This function service to get current channel interrupt states.
 *
 * \verbatim
 * Syntax             : uint32 Dma_Ip_GetInterruptState
 *                      (
 *                          uint32 dmaBaseAddress
 *                          uint32 channelId
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : dmabaseAddress - Dma controller base address.
 *                      channelId      - Numeric identifier of the DMA channel.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Return current channel's interrupt states.
 *
 * Description        : This function service to get current channel interrupt states.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
DMA_LOCAL uint32 Dma_Ip_GetInterruptState(uint32 dmaBaseAddress, uint32 channelId)
{
    /* ----- Implementation ----------------------------------------------- */
    /* #10 Read interrupt status register. */
    return Dma_Ip_ReadChannelRegister(dmaBaseAddress, channelId, DMA_IP_CH_INTERRUPT_STATUS_REG);
}
/** *****************************************************************************************************
 * \brief This function service to clear current channel interrupt states.
 *
 * \verbatim
 * Syntax             : void Dma_Ip_ClearInterrupt
 *                      (
 *                          uint32 dmaBaseAddress
 *                          uint32 channelId
 *                          uint32 status
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : dmabaseAddress - Dma controller base address.
 *                      channelId      - Numeric identifier of the DMA channel.
 *                      status         - Which state(s) you want to clear.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function service to clear current channel interrupt states.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
DMA_LOCAL void Dma_Ip_ClearInterrupt(uint32 dmaBaseAddress, uint32 channelId, uint32 status)
{
    /* ----- Implementation ----------------------------------------------- */
    /* #10 Clear interrupt flag. */
    Dma_Ip_WriteChannelRegister(dmaBaseAddress, channelId, status, DMA_IP_CH_INTERRUPT_CLEAR_REG);
}
/** *****************************************************************************************************
 * \brief This function service to get current channel enable states.
 *
 * \verbatim
 * Syntax             : uint32 Dma_Ip_GetChannelEnable
 *                      (
 *                          uint32 dmaBaseAddress
 *                          uint32 channelId
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : dmabaseAddress - Dma controller base address.
 *                      channelId      - Numeric identifier of the DMA channel.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Return channel enable states.
 *
 * Description        : This function service to get current channel enable states.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
DMA_LOCAL uint32 Dma_Ip_GetChannelEnable(uint32 dmaBaseAddress, uint32 channelId)
{
    /* ----- Implementation ----------------------------------------------- */
    /* #10 Read channel enable status. */
    return Dma_Ip_ReadChannelRegisterBits(dmaBaseAddress, channelId, DMA_IP_CHANNEL_CONFIG_REG,
                                          DMA_IP_CH_CFG_EN_FIELD_OFFSET, DMA_IP_CH_CFG_EN_FIELD_SIZE);
}
/** *****************************************************************************************************
 * \brief This function service to set current channel work states.
 *
 * \verbatim
 * Syntax             : uint32 Dma_Ip_SetChannelCmd
 *                      (
 *                          uint32 dmaBaseAddress
 *                          uint32 channelId
 *                          Dma_ChannelControlStateType command
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : dmabaseAddress - Dma controller base address.
 *                      channelId      - Numeric identifier of the DMA channel.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Return register value.
 *
 * Description        : This function service to set current channel work states.
 * \endverbatim
 * Traceability       : SWSR_DMA_043 SW_SM005
 *******************************************************************************************************/
DMA_LOCAL uint32 Dma_Ip_SetChannelCmd(uint32 dmaBaseAddress, uint32 channelId,
                                      Dma_ChannelControlStateType command)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint32 ret;
    /* Max timeout value is 1.66ms */
    uint32 timeout = DMA_TIME_DURATION;

    /* ----- Implementation ----------------------------------------------- */
    switch (command)
    {
    case DMA_CH_CTL_STAT_REQ_FLUSH:
    {
        /* #50 Flush to ack the dma request from peripherals. */
        Dma_Ip_WriteChannelRegisterBits(dmaBaseAddress, channelId, DMA_IP_CHANNEL_CONFIG_REG,
                                        DMA_IP_CH_CFG_REQUEST_FLUSH_FIELD_OFFSET, DMA_IP_CH_CFG_REQUEST_FLUSH_FIELD_SIZE, 1U);
        ret = Dma_Ip_ReadChannelRegisterBits(dmaBaseAddress, channelId, DMA_IP_CHANNEL_CONFIG_REG,
                                             DMA_IP_CH_CFG_REQUEST_FLUSH_FIELD_OFFSET, DMA_IP_CH_CFG_REQUEST_FLUSH_FIELD_SIZE);

        while ((ret == 1U) && (timeout > 0U))
        {
            ret =  Dma_Ip_ReadChannelRegisterBits(dmaBaseAddress, channelId, DMA_IP_CHANNEL_CONFIG_REG,
                                                  DMA_IP_CH_CFG_REQUEST_FLUSH_FIELD_OFFSET, DMA_IP_CH_CFG_REQUEST_FLUSH_FIELD_SIZE);
            timeout--;
        }

        if (0U == timeout)
        {
            /* #30 Timeout occurred. */
            ret = 1U;
        } /* else not needed */

        break;
    }

    case DMA_CH_CTL_STAT_ABORT:
    {
        /* #80 Set abort command to the channel. */
        Dma_Ip_WriteChannelRegisterBits(dmaBaseAddress, channelId, DMA_IP_CHANNEL_CONFIG_REG,
                                        DMA_IP_CH_CFG_ABORT_FIELD_OFFSET, DMA_IP_CH_CFG_ABORT_FIELD_SIZE, 1U);
        ret = Dma_Ip_ReadChannelRegisterBits(dmaBaseAddress, channelId, DMA_IP_CHANNEL_CONFIG_REG,
                                             DMA_IP_CH_CFG_ABORT_FIELD_OFFSET, DMA_IP_CH_CFG_ABORT_FIELD_SIZE);

        while ((ret == 1U) && (timeout > 0U))
        {
            ret =  Dma_Ip_ReadChannelRegisterBits(dmaBaseAddress, channelId, DMA_IP_CHANNEL_CONFIG_REG,
                                                  DMA_IP_CH_CFG_ABORT_FIELD_OFFSET, DMA_IP_CH_CFG_ABORT_FIELD_SIZE);
            /* #90 Check channel enable bit whether go to disable state. */
            if (0U == Dma_Ip_GetChannelEnable(dmaBaseAddress, channelId))
            {
                /* #100 If channel enable bit clear by itself, mannual set abort bits to 0. */
                Dma_Ip_WriteChannelRegisterBits(dmaBaseAddress, channelId, DMA_IP_CHANNEL_CONFIG_REG,
                                        DMA_IP_CH_CFG_ABORT_FIELD_OFFSET, DMA_IP_CH_CFG_ABORT_FIELD_SIZE, 0U);
            } /* else not needed */
            timeout--;
        }
        DmaHookTimeout_Dma_Ip_SetChannelCmd();
        if (0U == timeout)
        {
            /* #30 Timeout occurred. */
            ret = 1U;
        } /* else not needed */

        break;
    }

    default:
    {
        /* #90 Normally, the code does not run to here. */
        ret = 1U;
        break;
    }
    }

    return ret;
}
/** *****************************************************************************************************
 * \brief This function service to enable channel to start transmission or receive hardware transmission
 *        request.
 *
 * \verbatim
 * Syntax             : void Dma_Ip_EnableChannel
 *                      (
 *                          uint32 dmaBaseAddress
 *                          uint32 channelId
 *                          uint8 psCnt
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : dmabaseAddress - Dma controller base address.
 *                      channelId      - Numeric identifier of the DMA channel.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function service to enable channel to start transmission or receive hardware
 *                      transmission request. Add one to the program sequence counter every time you
 *                      configure the registers.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
DMA_LOCAL void Dma_Ip_EnableChannel(uint32 dmaBaseAddress, uint32 channelId, uint8 psCnt)
{
    /* ----- Implementation ----------------------------------------------- */
    /* #10 Before write program sequence counter to PROGRAMM_SEQUENCE_CTRL the program sequence counter must add 1. */
    Dma_Ip_WriteChannelRegisterBits(dmaBaseAddress, channelId, DMA_IP_CH_PROGRAMM_SEQUENCE_CTRL_REG,
                                    DMA_IP_CH_PROG_SEQ_CTRL_PS_CNT_FIELD_OFFSET,
                                    DMA_IP_CH_PROG_SEQ_CTRL_PS_CNT_FIELD_SIZE, ((uint32)psCnt + 1U));
    Dma_Ip_WriteChannelRegisterBits(dmaBaseAddress, channelId, DMA_IP_CHANNEL_CONFIG_REG,
                                    DMA_IP_CH_CFG_EN_FIELD_OFFSET,
                                    DMA_IP_CH_CFG_EN_FIELD_SIZE, 1U);
}
/** *****************************************************************************************************
 * \brief This function service to set software handshake signel.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_Ip_SetChannelSoftwareHandshake
 *                      (
 *                          uint32 dmaBaseAddress
 *                          uint32 channelId
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : dmabaseAddress - Dma controller base address.
 *                      channelId      - Numeric identifier of the DMA channel.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Set software handshake successful.
 *                      DMA_E_TIMEOUT: Timeout occurred, set failed.
 *
 * Description        : This function service to set software handshake signel. Only used for memory
 *                      to/from memory.
 * \endverbatim
 * Traceability       : SWSR_DMA_043 SW_SM005
 *******************************************************************************************************/
DMA_LOCAL Std_ReturnType Dma_Ip_SetChannelSoftwareHandshake(uint32 dmaBaseAddress, uint32 channelId)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;
    uint32 value;
    uint8 limit = DMA_HANDSHAKE_LIMIT;

    /* ----- Implementation ----------------------------------------------- */
    while (limit > 0U)
    {
        /* #10 Read software handshake request status and waiting for idle and complete. */
        value = Dma_Ip_ReadChannelRegister(dmaBaseAddress, channelId, DMA_IP_CH_SOFTWARE_HANDSHAKE_REG);

        if (value == 0U)
        {
            break;
        }/* else not needed */

        limit--;
    }

    if (0U == limit)
    {
        /* #20 Timeout occurred. */
        errorId = DMA_E_TIMEOUT;
    }
    else
    {
        /* #30 Set software handshake to working on request. */
        Dma_Ip_WriteChannelRegisterBits(dmaBaseAddress, channelId, DMA_IP_CH_SOFTWARE_HANDSHAKE_REG,
                                        DMA_IP_CH_SW_HS_REQ_FIELD_OFFSET, DMA_IP_CH_SW_HS_REQ_FIELD_SIZE, 1U);
    }

    return errorId;
}
/** *****************************************************************************************************
 * \brief This function service to set MAD register.
 *
 * \verbatim
 * Syntax             : void Dma_Ip_SetMad
 *                      (
 *                          uint32 dmaBaseAddress
 *                          uint32 channelId
 *                          const Dma_LinkListNodeConfigType * const item
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : dmabaseAddress - Dma controller base address.
 *                      channelId      - Numeric identifier of the DMA channel.
 *                      *item          - Pointer to MAD register configuration parameters.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Set software handshake successful.
 *                      DMA_E_TIMEOUT: Timeout occurred, set failed.
 *
 * Description        : This function service to set MAD register.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
DMA_LOCAL void Dma_Ip_SetMad(uint32 dmabaseAddress, uint32 channelId,
                             const Dma_LinkListNodeConfigType *const item)
{
    /* ----- Implementation ----------------------------------------------- */
    /* #10 Write MAD registers. */
    Dma_Ip_WriteChannelRegister(dmabaseAddress, channelId, item->srcAddress,
                                DMA_IP_CH_SOURCE_ADDRESS_REG);
    Dma_Ip_WriteChannelRegister(dmabaseAddress, channelId, item->dstAddress,
                                DMA_IP_CH_DESTINATION_ADDRESS_REG);
    Dma_Ip_WriteChannelRegister(dmabaseAddress, channelId, item->transactionControl,
                                DMA_IP_CH_TRANSACTION_CTRL_REG);
    Dma_Ip_WriteChannelRegister(dmabaseAddress, channelId, item->blockConfig,
                                DMA_IP_CH_DATA_BLOCK_CONFIG_REG);
    Dma_Ip_WriteChannelRegister(dmabaseAddress, channelId, item->operationMode,
                                DMA_IP_CH_OPERATION_MODE_REG);
    Dma_Ip_WriteChannelRegister(dmabaseAddress, channelId, item->operationData,
                                DMA_IP_CH_OPERATION_DATA_REG);
    Dma_Ip_WriteChannelRegister(dmabaseAddress, channelId, item->madCrc, DMA_IP_CH_MAD_CRC_REG);
    Dma_Ip_WriteChannelRegister(dmabaseAddress, channelId, item->linkAddress,
                                DMA_IP_CH_LINK_ADDRESS_REG);
    Dma_Ip_SetChannelReadOutstanding(dmabaseAddress, channelId, DMA_OUTSTANDING_VALUE);
    Dma_Ip_SetChannelWriteOutstanding(dmabaseAddress, channelId, DMA_OUTSTANDING_VALUE);
    Dma_Ip_WriteChannelRegisterBits(dmabaseAddress, channelId, DMA_IP_CH_CHANNEL_TURBO_REG,
                                DMA_IP_CH_CHANNEL_TURBO_PREAD_MOD_FIELD_OFFSET, DMA_IP_CH_CHANNEL_TURBO_PREAD_MOD_FIELD_SIZE,
                                0x01U);
}
/** *****************************************************************************************************
 * \brief This function service to calculate mad crc value.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_Ip_CalculateMadCrc
 *                      (
 *                          uint32 initValue
 *                          Dma_LinkListNodeConfigType *head
 *                          Dma_MadCrcModeType crcMode
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : initValue - Crc initial value, typically 0.
 *                      *head     - Pointer to link list first node.
 *                      crcMode   - DMA_NO_MAD_CRC, DMA_MAD_CRC, DMA_DATA_CRC(Not supported).
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Set software handshake successful.
 *                      DMA_E_TIMEOUT: Timeout occurred, set failed.
 *                      DMA_E_PARAM_POINTER: Pointer is NULL_PTR.
 *
 * Description        : This function service to calculate mad crc value.
 * \endverbatim
 * Traceability       : SWSR_DMA_015 SWSR_DMA_049 SW_SM006
 *******************************************************************************************************/
DMA_LOCAL Std_ReturnType Dma_Ip_CalculateMadCrc(uint32 initValue, Dma_LinkListNodeConfigType *head,
        Dma_MadCrcModeType crcMode)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;
    Dma_LinkListNodeConfigType *current = head;
    uint32 crcValue[DMA_IP_MAD_CRC_REGISTERS];
    uint32 crcResult = initValue;
    uint32 loop = Dma_LinkListLengthOnCore[Dma_Ip_GetCoreId()];

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check input parameters for plausibility. */
    if (NULL_PTR == head)
    {
        errorId = DMA_E_PARAM_POINTER;
    }
    else
    {
        /* #20 Only support MAD CRC mode. */
        if (DMA_MAD_CRC == crcMode)
        {
            while (loop > 0U)
            {
                // format data
                crcValue[0] = current->linkAddress;
                crcValue[1] = current->operationData;
                crcValue[2] = current->operationMode;
                crcValue[3] = current->blockConfig;
                crcValue[4] = current->transactionControl;
                crcValue[5] = current->dstAddress;
                crcValue[6] = current->srcAddress;

                /* #30 Calculate MAD CRC. */
                crcResult = Dma_Ip_Crc32(crcResult, (const uint8 *)crcValue,
                                         (unsigned int)DMA_IP_MAD_CRC_REGISTERS * sizeof(uint32));

                /* #40 Copy CRC result to link list current node. */
                current->madCrc = crcResult;
#if (DMA_NO_CACHEABLE_NEEDED == STD_OFF)
                /* PRQA S 0314 1 */
                Dma_CleanCacheRange((const void *)current, sizeof(Dma_LinkListNodeConfigType));
#endif /** #if (DMA_NO_CACHEABLE_NEEDED == STD_OFF) */
                /* #50 Pointer to next node continue calc MAD CRC. *//* PRQA S 0306 1 */
                current = (Dma_LinkListNodeConfigType *)(current->linkAddress);

                if ((NULL == current) || (current == head))
                {
                    break;
                } /* else not needed */

                loop--;
            }
        }/* else not needed */

        if (0U == loop)
        {
            /* #60 Timeout occurred. */
            errorId = DMA_E_TIMEOUT;
        }/* else not needed */
    }

    return errorId;
}
/** *****************************************************************************************************
 * \brief This function service to calculate mad crc value.
 *
 * \verbatim
 * Syntax             : uint32 Dma_Ip_Crc32
 *                      (
 *                          uint32 crc
 *                          const uint8 *buffer
 *                          uint32 length
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : crc      - Crc initial value, typically 0.
 *                      *buffer  - Pointer to data buffer.
 *                      length   - Date buffer length.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Return crc calculate result value.
 *
 * Description        : This function service to calculate mad crc value, using the lookup table method.
 * \endverbatim
 * Traceability       : SWSR_DMA_015
 *******************************************************************************************************/
DMA_LOCAL_INLINE uint32 Dma_Ip_Crc32(uint32 crc, const uint8 *buffer, uint32 length)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint32 crcValue = crc;
    uint32 crcLength = 0U;
    const uint8 *crcBuffer = buffer;

    do
    {
        crcValue = Dma_Crc32Table[((uint32)(crcValue >> 24U) ^ (crcBuffer[crcLength]))] ^ (crcValue << 8U);
        crcLength++;
    }
    while (crcLength < length);

    return crcValue;
}
/** *****************************************************************************************************
 * \brief This function service to get max block size depend on loop mode.
 *
 * \verbatim
 * Syntax             : uint32 Dma_Ip_GetMaxBlockSize
 *                      (
 *                          Dma_LoopModeType loopMode
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : loopMode - DMA loop mode, DMA_LOOP_MODE_0, DMA_LOOP_MODE_1, DMA_LOOP_MODE_2.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Return max block size.
 *
 * Description        : This function service to get max block size depend on loop mode.
 *                      Loop mode 0 with memory to memory.
 *                      Loop mode 1 with peripheral to memory.
 *                      Loop mode 2 with peripheral to memory.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
DMA_LOCAL uint32 Dma_Ip_GetMaxBlockSize(Dma_LoopModeType loopMode)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint32 maxSize;

    /* ----- Development Error Checks ------------------------------------- */
    switch (loopMode)
    {
    case DMA_LOOP_MODE_0:
    {
        /* #10 Get loop mode 0 max total size for data to be transferred at one time. */
        maxSize = DMA_IP_LP0_LPSIZE_MAX;
        break;
    }

    case DMA_LOOP_MODE_1:
    {
        /* #20 Get loop mode 1 max transfer size at every loop. */
        maxSize = DMA_IP_LP1_LPSIZE_MAX;
        break;
    }

    case DMA_LOOP_MODE_2:
    {
        /* #30 Get loop mode 2 max transfer size at every loop. */
        maxSize = DMA_IP_LP2_LPSIZE_MAX;
        break;
    }

    default:
    {
        /* #40 Normally, the code does not run to here. */
        maxSize = DMA_IP_LP0_LPSIZE_MAX;
        break;
    }
    }

    return maxSize;
}
/* PRQA S 2755 34 */
/** *****************************************************************************************************
 * \brief This function service to set link list node.
 *
 * \verbatim
 * Syntax             : Dma_linkListType *Dma_Ip_SetLinkList
 *                      (
 *                          Dma_ChannelRegType *dmaChannel
 *                          uint32 length
 *                          uint32 blockSize
 *                          uint32 param
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *dmaChannel - Pointer to a selected channel configuration structure.
 *                      length      - Total transmit data length.
 *                      blockSize   - Max block size.
 *                      *param      - Period length, used for cyclic transfer mode.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Return first link list node address.
 *
 * Description        : This function service to set link list node and set MAD registers.
 * \endverbatim
 * Traceability       : SWSR_DMA_012
 *******************************************************************************************************/
DMA_LOCAL Dma_linkListType *Dma_Ip_SetLinkList(Dma_ChannelRegType *dmaChannel, uint32 length,
        uint32 blockSize, uint32 param)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;
    Dma_TransactionType transactionType = dmaChannel->deviceConfig.transaction;
    Dma_LinkListDescType *linkListDesc = &dmaChannel->linkListDesc;
    Dma_MadCrcModeType madCrcMode = dmaChannel->deviceConfig.madCrcMode;
    Dma_linkListType *first = NULL_PTR;
    Dma_linkListType *current = NULL_PTR;
    Dma_linkListType *previous = NULL_PTR;
    uint32 offset = 0U;
    uint32 trLength;
    /* #10 periodLength only used for cyclic transfer mode. */
    uint32 periodLength = ((DMA_CYCLIC == transactionType) ? param : 0U);
    Dma_DeviceConfigType linkListConfig;

    /* ----- Development Error Checks ------------------------------------- */
    linkListConfig = (dmaChannel->deviceConfig);

    while ((offset < length) && ((Std_ReturnType)E_OK == errorId))
    {
        current = Dma_Ip_GetLinkListDesc(linkListDesc);

        if (NULL_PTR == current)
        {
            errorId = DMA_E_LINK_LIST;
        }
        else
        {
            /* #20 Initial MAD register. */
            current->linkListItem.srcAddress = 0U;
            current->linkListItem.dstAddress = 0U;
            current->linkListItem.transactionControl = 0U;
            current->linkListItem.blockConfig = 0U;
            current->linkListItem.operationMode = 0U;
            current->linkListItem.operationData = 0U;
            current->linkListItem.madCrc = 0U;
            current->linkListItem.linkAddress = 0U;

            /* #30 Set linkListConfig source and destination address offset. */
            Dma_Ip_SetLinkListDaughter(current, &linkListConfig, dmaChannel, first, offset);

            trLength = Dma_Ip_GetTransferLength(dmaChannel, offset, length, blockSize, periodLength);

            linkListConfig.bufferSize = trLength;

            if (NULL_PTR == first)
            {
                first = current;
                /* #100 Set first node address to the channel configuration record. *//* PRQA S 0306 1 */
                dmaChannel->deviceConfig.linkListAddress = (uint32)&first->linkListItem;
            }
            else
            {
                if (NULL_PTR == previous)
                {
                    current = NULL_PTR;
                    first = NULL_PTR;
                    break;
                }
                else
                {
                    /* PRQA S 0306 1 */
                    previous->linkListItem.linkAddress = ((uint32)&current->linkListItem);
#if (DMA_NO_CACHEABLE_NEEDED == STD_OFF)
                    /* PRQA S 0314 1 */
                    Dma_CleanCacheRange((const void *)&previous->linkListItem, sizeof(Dma_LinkListNodeConfigType));
#endif /** #if (DMA_NO_CACHEABLE_NEEDED == STD_OFF) */
                }
            }

            /* #110 Mark node MAD flag, the last MAD will be marked last mad, otherwise marked first MAD. */
            Dma_Ip_SetMadFlag(transactionType, &linkListConfig, offset, trLength, length);

            /* #120 Set format MAD memory. */
            Dma_Ip_FormatMad(&linkListConfig, &current->linkListItem, madCrcMode);
            Dma_Ip_ListAddTail(&first->linkListHead, &current->linkListNode);
            previous = current;
            offset += trLength;
        }
    }

    if (current != NULL_PTR)
    {
        /* PRQA S 0306 1 */
        linkListDesc->physisAddress = (uint32)first; // Virtual addresses are not supported

        if (DMA_CYCLIC == transactionType)
        {
            /* PRQA S 0306 1 */
            current->linkListItem.linkAddress = ((uint32)&first->linkListItem);
        }
        else
        {
            current->linkListItem.linkAddress = 0U;
        }

#if (DMA_NO_CACHEABLE_NEEDED == STD_OFF)
        /* PRQA S 0314 1 */
        Dma_CleanCacheRange((const void *)&first->linkListItem, sizeof(Dma_LinkListNodeConfigType));
        /* PRQA S 0314 1 */
        Dma_CleanCacheRange((const void *)&current->linkListItem, sizeof(Dma_LinkListNodeConfigType));
#endif /** #if (DMA_NO_CACHEABLE_NEEDED == STD_OFF) */
    } /* else not needed */

    if (errorId != E_OK)
    {
        /* No need to care about the return value. */
        (void)Dma_Ip_FreeLinkListDesc(first);
        first = NULL_PTR;
    } /* else not needed */

    return first;
}
/** *****************************************************************************************************
 * \brief This function service to calculate transfer length.
 *
 * \verbatim
 * Syntax             : uint32 Dma_Ip_GetTransferLength
 *                      (
 *                          const Dma_ChannelRegType * const dmaChannel
 *                          uint32 offset
 *                          uint32 length
 *                          uint32 blockSize
 *                          uint32 periodLength
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *dmaChannel  - Pointer to a selected channel configuration structure.
 *                      offset       - Offset of total length.
 *                      length       - Total length.
 *                      blockSize    - Max block size.
 *                      periodLength - Period transfer lgnth, used for link list mode.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Return transfer length.
 *
 * Description        : This function service to calculate transfer length.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
DMA_LOCAL uint32 Dma_Ip_GetTransferLength(const Dma_ChannelRegType *const dmaChannel, uint32 offset,
        uint32 length, uint32 blockSize, uint32 periodLength)
{
    uint32 trLength;

    if (DMA_TRANSFER_MODE_LINKLIST == dmaChannel->deviceConfig.transferMode)
    {
        if (DMA_CYCLIC == dmaChannel->deviceConfig.transaction)
        {
            trLength = periodLength;
        }
        else
        {
            trLength = (length % ((((uint32)dmaChannel->deviceConfig.srcMaxBurst) + 1U) * (1UL << ((
                                      uint32)dmaChannel->deviceConfig.srcBusWidth))));

            /* Check whether the transfer length and burst length are aligned */
            if (0U == offset)
            {
                if (0U == trLength)
                {
                    /* If over max transfer length, then transfer length equal to max length(4096 bytes). */
                    trLength = (length > DMA_IP_LP1_LPSIZE_MAX) ? DMA_IP_LP1_LPSIZE_MAX : length;
                }
                else
                {
                    if (length < ((((uint32)dmaChannel->deviceConfig.srcMaxBurst) + 1U) * (1UL << ((
                                      uint32)dmaChannel->deviceConfig.srcBusWidth))))
                    {
                        trLength = length;
                    }
                    else
                    {
                        trLength = (length > DMA_IP_LP1_LPSIZE_MAX) ? DMA_IP_LP1_LPSIZE_MAX : (length - trLength);
                    }
                }
            }
            else
            {
                trLength = length - offset;
            }
        }
    }
    else
    {
        if (length < blockSize)
        {
            trLength = length;
        }
        else
        {
            /* If over max transfer length, then transfer length equal to max length(4096 bytes). */
            trLength = blockSize;
        }
    }

    return trLength;
}
/** *****************************************************************************************************
 * \brief This function service to set MAD flag.
 *
 * \verbatim
 * Syntax             : void Dma_Ip_SetMadFlag
 *                      (
 *                          Dma_TransactionType transactionType
 *                          Dma_DeviceConfigType *linkListConfig
 *                          uint32 offset
 *                          uint32 trLength
 *                          uint32 length
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : transactionType - DMA_MEMCPY/DMA_MEMSET/DMA_DEVICE/DMA_CYCLIC
 *                      *linkListConfig - Pointer to link list configurations node.
 *                      offset          - Offset of total length.
 *                      trLength        - Transfer length of each loop.
 *                      length          - Total length.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function service to set MAD flag. Only used for link list transfer mode.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
DMA_LOCAL void Dma_Ip_SetMadFlag(Dma_TransactionType transactionType,
                                 Dma_DeviceConfigType *linkListConfig, uint32 offset, uint32 trLength, uint32 length)
{
    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Set MAD flag. Only used for link list transfer mode. */
    if (DMA_CYCLIC != transactionType)
    {
        if ((offset + trLength) >= length)
        {
            /* #20 Last MAD. */
            linkListConfig->firstMad = FALSE;
            linkListConfig->lastMad = TRUE;
        }
        else if (offset == 0u)
        {
            /* #30 Each MAD. */
            linkListConfig->firstMad = TRUE;
            linkListConfig->lastMad = FALSE;
        }
        else
        {
            /* #30 Not link list trnasfer mode. */
            linkListConfig->firstMad = FALSE;
        }
    }/* else not needed */
}
/** *****************************************************************************************************
 * \brief This function service to set MAD address increase steps.
 *
 * \verbatim
 * Syntax             : void Dma_Ip_SetLinkListDaughter
 *                      (
 *                          Dma_linkListType *current
 *                          Dma_DeviceConfigType *linkListConfig
 *                          Dma_ChannelRegType * const dmaChannel
 *                          Dma_linkListType * const first
 *                          uint32 offset
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *current        - Pointer current link list node.
 *                      *linkListConfig - Link list configuration info.
 *                      dmaChannel      - Pointer to a selected channel configuration structure.
 *                      *first          - Pointer first link list node.
 *                      offset          - Address offset.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function service to set MAD address increase steps.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
DMA_LOCAL void Dma_Ip_SetLinkListDaughter(Dma_linkListType *current,
        Dma_DeviceConfigType *linkListConfig, const Dma_ChannelRegType *const dmaChannel,
        const Dma_linkListType *const first, uint32 offset)
{
    /* ----- Local Variables ---------------------------------------------- */
    Dma_TransactionType transactionType = dmaChannel->deviceConfig.transaction;
    Dma_TransmitDirectionType direction = dmaChannel->deviceConfig.direction;

    /* ----- Development Error Checks ------------------------------------- */
    switch (transactionType)
    {
    /* #10 DMA_CYCLIC and DMA_DEVICE are all belong to peripheral from/to memory. */
    case DMA_CYCLIC:
    case DMA_DEVICE:
    {
        if (DMA_MEMORY_TO_DEVICE == direction)
        {
            /* #20 Memory to peripheral, the memory address could be increased and the peripheral address is fix. */
            current->linkListItem.srcAddress = (uint32)(dmaChannel->deviceConfig.srcAddress + offset);
            current->linkListItem.dstAddress = (uint32)(dmaChannel->deviceConfig.dstAddress);
        }
        else
        {
            /* #30 Peripheral to memory, the memory address could be increased and the peripheral address is fix. */
            current->linkListItem.srcAddress = (uint32)(dmaChannel->deviceConfig.srcAddress);
            current->linkListItem.dstAddress = (uint32)(dmaChannel->deviceConfig.dstAddress + offset);
        }

        break;
    }

    case DMA_MEMCPY:
    {
        /* #40 Memory to memory, the memory addresses may all be increased. */
        current->linkListItem.srcAddress = (uint32)(dmaChannel->deviceConfig.srcAddress + offset);
        current->linkListItem.dstAddress = (uint32)(dmaChannel->deviceConfig.dstAddress + offset);

        if (NULL_PTR != first)
        {
            /* #50 Memory to memory using internal software handshake request. */
            linkListConfig->linkListTriggerMode = DMA_TRIGGER_BY_INTERNAL_EVENT;
        }/* else not needed */

        break;
    }

    case DMA_MEMSET:
    {
        /* #60 Memory from memory, the source is local buffer and address is fix, the destination address will be increased. */
        current->linkListItem.srcAddress = (uint32)(dmaChannel->deviceConfig.srcAddress);
        current->linkListItem.dstAddress = (uint32)(dmaChannel->deviceConfig.dstAddress + offset);

        if (NULL_PTR != first)
        {
            /* #70 Memory from memory using internal software handshake request. */
            linkListConfig->linkListTriggerMode = DMA_TRIGGER_BY_INTERNAL_EVENT;
        }/* else not needed */

        break;
    }

    default :
    {
        /* #80 TransactionType has beed checked. Normally, the code does not run to here. */
        break;
    }
    }
}
/** *****************************************************************************************************
 * \brief This function service to set MAD register value to link list node.
 *
 * \verbatim
 * Syntax             : void Dma_Ip_FormatMad
 *                      (
 *                          const Dma_DeviceConfigType * const config
 *                          Dma_LinkListNodeConfigType *item
 *                          Dma_MadCrcModeType madCrcMode
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *config    - Pointer to a selected channel configuration structure.
 *                      *item      - Pointer to MAD register configuration parameters.
 *                      madCrcMode - Selected CRC mode.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function service to set MAD register value to link list node.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
DMA_LOCAL void Dma_Ip_FormatMad(const Dma_DeviceConfigType *const config,
                                Dma_LinkListNodeConfigType *item, Dma_MadCrcModeType madCrcMode)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint32 bufferSize = 0U;

    /* ----- Implementation ----------------------------------------------- */
    if (config->flowControl == DMA_DIR_MEMORY_TO_DEVICE)
    {
        bufferSize = Dma_Ip_GetBufferSize((Dma_LoopModeType)config->loopMode, config->bufferSize,
                                          (uint32)(((uint32)config->dstMaxBurst + 1U) * (1UL << (uint32)config->dstBusWidth)));
    }
    else if (config->flowControl == DMA_DIR_DEVICE_TO_MEMORY)
    {
        bufferSize = Dma_Ip_GetBufferSize((Dma_LoopModeType)config->loopMode, config->bufferSize,
                                          (uint32)(((uint32)config->srcMaxBurst + 1U) * (1UL << (uint32)config->srcBusWidth)));
    }
    else if ((config->flowControl == DMA_DIR_MEMORY_TO_MEMORY)
             || (config->flowControl == DMA_DIR_REGISTER_TO_MEMORY))
    {
        bufferSize = Dma_Ip_GetBufferSize((Dma_LoopModeType)config->loopMode, config->bufferSize,
                                          config->bufferSize);
    }
    else
    {
        /* Do Nothing */
    }

    /* #40 Copy to link list node. */
    item->transactionControl |= (
                                    DMA_IP_CH_TRANSACTION_CTRL_SRC_BL_FIELD(config->srcMaxBurst)            |
                                    DMA_IP_CH_TRANSACTION_CTRL_SRC_BSIZE_FIELD(config->srcBusWidth)         |
                                    DMA_IP_CH_TRANSACTION_CTRL_SRC_PSEL_FIELD(config->srcPortSelect)        |
                                    DMA_IP_CH_TRANSACTION_CTRL_SRC_BST_TYPE_FIELD(config->srcIncDirection)  |
                                    DMA_IP_CH_TRANSACTION_CTRL_SRC_STR_POL_FIELD(config->srcStridePol)      |
                                    DMA_IP_CH_TRANSACTION_CTRL_SRC_PORT_FIELD(0U)                           |
                                    DMA_IP_CH_TRANSACTION_CTRL_SRC_CACHE_FIELD(config->srcCache)            |
                                    DMA_IP_CH_TRANSACTION_CTRL_DST_BL_FIELD(config->dstMaxBurst)            |
                                    DMA_IP_CH_TRANSACTION_CTRL_DST_BSIZE_FIELD(config->dstBusWidth)         |
                                    DMA_IP_CH_TRANSACTION_CTRL_DST_PSEL_FIELD(config->dstPortSelect)        |
                                    DMA_IP_CH_TRANSACTION_CTRL_DST_BST_TYPE_FIELD(config->dstIncDirection)  |
                                    DMA_IP_CH_TRANSACTION_CTRL_DST_STR_POL_FIELD(config->dstStridePol)      |
                                    DMA_IP_CH_TRANSACTION_CTRL_DST_PORT_FIELD(0U)                           |
                                    DMA_IP_CH_TRANSACTION_CTRL_DST_CACHE_FIELD(config->dstCache)
                                );
    item->blockConfig |= (
                             DMA_IP_CH_DATA_BLK_CFG_BUF_SIZE_FIELD(bufferSize)                  |
                             DMA_IP_CH_DATA_BLK_CFG_LP_MOD_FIELD(config->loopMode)              |
                             DMA_IP_CH_DATA_BLK_CFG_SWT_EVT_CTR_FIELD(config->switchControl)    |
                             DMA_IP_CH_DATA_BLK_CFG_SRC_STR_EN_FIELD(config->srcStrideEnable)   |
                             DMA_IP_CH_DATA_BLK_CFG_DST_STR_EN_FIELD(config->dstStrideEnable)   |
                             DMA_IP_CH_DATA_BLK_CFG_BUF_MOD_FIELD(config->bufferMode)
                         );
    item->operationMode |= (
                               DMA_IP_CH_OP_MOD_FLOW_CTR_FIELD(config->flowControl)            |
                               DMA_IP_CH_OP_MOD_TR_MOD_FIELD(config->transferMode)             |
                               DMA_IP_CH_OP_MOD_MAD_CRC_MOD_FIELD(madCrcMode)                  |
                               DMA_IP_CH_OP_MOD_FST_MAD_FIELD(config->firstMad)                |
                               DMA_IP_CH_OP_MOD_LST_MAD_FIELD(config->lastMad)                 |
                               DMA_IP_CH_OP_MOD_SRC_STR_SEL_FIELD(config->srcStrideSelect)     |
                               DMA_IP_CH_OP_MOD_SRC_CORSE_STR_FIELD(config->srcCoarseStride)   |
                               DMA_IP_CH_OP_MOD_DST_STR_SEL_FIELD(config->dstStrideSelect)     |
                               DMA_IP_CH_OP_MOD_DST_CORSE_STR_FIELD(config->dstCoarseStride)   |
                               DMA_IP_CH_OP_MOD_MAD_INTR_FIELD(TRUE)                           |
                               DMA_IP_CH_OP_MOD_TIG_MOD_FIELD(config->linkListTriggerMode)
                           );
    item->operationData = DMA_IP_CH_OP_DATA_OPD_FIELD(0U);
    item->madCrc = DMA_IP_CH_MAD_CRC_MADCRC_FIELD(0U);
}
/** *****************************************************************************************************
 * \brief This function service to calculate different block sizes according to different loop modes.
 *
 * \verbatim
 * Syntax             : uint32 Dma_Ip_GetBufferSize
 *                      (
 *                          Dma_LoopModeType loopMode
 *                          uint32 total
 *                          uint32 period
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : loopMode - DMA loop mode, DMA_LOOP_MODE_0, DMA_LOOP_MODE_1, DMA_LOOP_MODE_2.
 *                      total    - Total transmit data length.
 *                      period   - Period length, used for cyclic transfer mode.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Return buffer size.
 *
 * Description        : This function service to calculate different block sizes according to different
 *                      loop modes.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
DMA_LOCAL uint32 Dma_Ip_GetBufferSize(Dma_LoopModeType loopMode, uint32 total, uint32 period)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint32 bufferSize;
    uint32 loopp2Size;
    uint32 loop1Cnt;
    uint32 loop1Size;
    uint8 temp;

    /* ----- Implementation ----------------------------------------------- */
    switch (loopMode)
    {
    case DMA_LOOP_MODE_2:
    {
        /* #10 Calculate loop mode 2 Loop size and total size are assembled into a buffer size. */
        temp = Dma_Ip_Clz32(period);

        if (temp < 32U)
        {
            temp = (31U - temp);
        }
        else
        {
            temp = 0U;
        }

        loopp2Size = (1UL << temp);

        temp = Dma_Ip_Ffs32(loopp2Size);

        if (temp < 32U)
        {
            temp = ((temp - 1U) & DMA_BUFFER_SIZE_LOOP_COUNTER_MASK);
        }
        else
        {
            temp = 0U;
        }

        bufferSize = (DMA_IP_LP2_TT(total) | temp);

        break;

    }

    case DMA_LOOP_MODE_1:
    {
        /* #20 Calculate loop mode 1 Loop size and total size are assembled into a buffer size. */
        if (total < period)
        {
            loop1Cnt = 0U;
            loop1Size = period - 1U;
        }
        else
        {
            loop1Cnt = total / period;
            loop1Cnt -= 1U;
            loop1Size = period - 1U;
        }

        bufferSize = (loop1Cnt << 12U) | loop1Size;
        break;
    }

    case DMA_LOOP_MODE_0:
    {
        /* #30 Calculate loop mode 0 total size is buffer size. */
        bufferSize = total - 1U;
        break;
    }

    default:
    {
        /* #40 Normally, the code does not run to here. */
        bufferSize = 0U;
        break;
    }
    }

    return bufferSize;
}
/** *****************************************************************************************************
 * \brief This function service to get link list description.
 *
 * \verbatim
 * Syntax             : Dma_linkListType *Dma_Ip_GetLinkListDesc
 *                      (
 *                          const Dma_LinkListDescType * const linkListDesc
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *linkListDesc - Pointer to link list first node.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Returns the first free node of the link list.
 *
 * Description        : This function service to get link list description.
 * \endverbatim
 * Traceability       : SW_SM007
 *******************************************************************************************************/
DMA_LOCAL Dma_linkListType *Dma_Ip_GetLinkListDesc(const Dma_LinkListDescType *const linkListDesc)
{
    /* ----- Local Variables ---------------------------------------------- */
    Dma_linkListType *linkListPtr;
    uint32 index;

    /* ----- Implementation ----------------------------------------------- */
    SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_00();
    /* #10 Fine first zero which is represents the node is free. */
    index = Dma_Ip_BitmapFfz(linkListDesc->memBitmap, linkListDesc->memSize);

    /* #20 If index = 0xFFFFFFFFU means the link list is full. */
    if (0xFFFFFFFFU != index)
    {
        linkListPtr = &linkListDesc->memBase[index];

        Dma_Ip_ListInitialize(&linkListPtr->linkListHead);

        /* PRQA S 0306 1 */
        linkListPtr->physisAddress = (uint32)(uint32)(&linkListPtr->linkListItem);
        linkListPtr->bitmapIndex = index;

        /* #30 Setting the bitmap indicates that the node is used. */
        (void)Dma_Ip_BitmapSet(linkListDesc->memBitmap, index);
    }
    else
    {
        linkListPtr = NULL_PTR;
    }

    SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_00();

    return linkListPtr;
}
/** *****************************************************************************************************
 * \brief This function service to set channel interrupt states.
 *
 * \verbatim
 * Syntax             : void Dma_Ip_SetInterruptState
 *                      (
 *                          uint32 dmaBaseAddress
 *                          uint32 channelId
 *                          const Dma_DeviceConfigType * const deviceConfigPtr
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : dmabaseAddress   - Dma controller base address.
 *                      channelId        - Numeric identifier of the DMA channel.
 *                      *deviceConfigPtr - Pointer to device configurations.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function service to set channel interrupt states.
 * \endverbatim
 * Traceability       : SWSR_DMA_010
 *******************************************************************************************************/
DMA_LOCAL void Dma_Ip_SetInterruptState(uint32 dmaBaseAddress, uint32 channelId,
                                        const Dma_DeviceConfigType *const deviceConfigPtr)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint32 interruptFlag;

    /* ----- Implementation ----------------------------------------------- */
    if (DMA_INTERRUPT == deviceConfigPtr->processMode)
    {
        /* #10 Enable basic interrupt service. */
        interruptFlag = (uint32)((uint32)DMA_CH_INT_EN_PS_ERROR |
                                 (uint32)DMA_CH_INT_EN_AHB_RD_ERROR |
                                 (uint32)DMA_CH_INT_EN_AHB_WR_ERROR |
                                 (uint32)DMA_CH_INT_EN_AXI_RD_ERROR |
                                 (uint32)DMA_CH_INT_EN_AXI_WR_ERROR);

        if (DMA_CYCLIC == deviceConfigPtr->transaction)
        {
            /* #20 If the transfer mode is cyclic, you need to enable every MAD done bit flag. */
            interruptFlag = interruptFlag | (uint32)DMA_CH_INT_EN_EVERY_MAD_DONE;
        } /* else not needed */

        /* #30 Enable last MAD done bit flag. */
        interruptFlag = interruptFlag | (uint32)DMA_CH_INT_EN_LST_MAD_DONE;

        /* #30 If MAD CRC enabled, you need to enable MAD CRC error bit flag. */
        if (DMA_MAD_CRC == deviceConfigPtr->madCrcMode)
        {
            interruptFlag = interruptFlag | (uint32)DMA_CH_INT_EN_MAD_CRC_ERROR;
        } /* else not needed */

    }
    else
    {
        /* #40 Polling process mode disable all interrupt. */
        interruptFlag = DMA_DISABLE_ALL_INTERRUPT;
    }

    /* #50 Polling process mode disable all interrupt. */
    Dma_Ip_WriteChannelRegister(dmaBaseAddress, channelId, interruptFlag,
                                DMA_IP_CH_INTERRUPT_ENABLE_REG);
}
/** *****************************************************************************************************
 * \brief This function service to set channel mux id used for hardware request signal.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_Ip_SetChannelMuxId
 *                      (
 *                          Dma_ChannelRegType *dmaChannelPtr
 *                          uint32 dmaBaseAddress
 *                          uint32 channelId
 *                          uint32 peripheralAddress
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *dmaChannelPtr - Pointer to dma channel configurations.
 *                      dmabaseAddress - Dma controller base address.
 *                      channelId      - Numeric identifier of the DMA channel.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function service to set channel mux id used for hardware request signal.
 * \endverbatim
 * Traceability       : SWSR_DMA_011
 *******************************************************************************************************/
DMA_LOCAL Std_ReturnType Dma_Ip_SetChannelMuxId(Dma_ChannelRegType *dmaChannelPtr,
        uint32 dmaBaseAddress, uint32 channelId)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;
    uint16 muxId = 0xFFU;

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Check if it is a customer-defined mux ID. */
    if (TRUE == dmaChannelPtr->deviceConfig.customMuxIdFlag)
    {
        if (dmaChannelPtr->deviceConfig.customMuxId > dmaChannelPtr->dmaConfig.hwConfig->muxTableLength)
        {
            errorId = DMA_E_MUX_ID;
        }
        else
        {
            /* #20 Get customer mux ID. */
            muxId = dmaChannelPtr->deviceConfig.customMuxId;
        }
    }
    else
    {
        /* #30 Get mux ID from Dma_SFMuxTable. */
        if (DMA_MEMORY_TO_DEVICE == dmaChannelPtr->deviceConfig.direction)
        {
            /* #40 Memory to peripheral need to write data to register or FIFO, so using DMA_MUX_WR. */
            muxId = Dma_Ip_GetMuxId(dmaChannelPtr->dmaConfig.hwConfig->muxTable,
                                    dmaChannelPtr->dmaConfig.hwConfig->muxTableLength, DMA_MUX_WR,
                                    dmaChannelPtr->deviceConfig.dstAddress);
        }
        else
        {
            /* #50 Peripheral to memory need to read data to register or FIFO, so using DMA_MUX_RD. */
            muxId = Dma_Ip_GetMuxId(dmaChannelPtr->dmaConfig.hwConfig->muxTable,
                                    dmaChannelPtr->dmaConfig.hwConfig->muxTableLength, DMA_MUX_RD,
                                    dmaChannelPtr->deviceConfig.srcAddress);
        }
    }

    if (muxId <= dmaChannelPtr->dmaConfig.hwConfig->muxTableLength)
    {
        /* #60 Write mux ID to node and PORT_CONFIG register. */
        dmaChannelPtr->deviceConfig.muxId = muxId;
        Dma_Ip_WriteChannelRegisterBits(dmaBaseAddress, channelId, DMA_IP_CH_PORT_CONFIG_REG,
                                        DMA_IP_CH_PORT_CFG_CSEL_FIELD_OFFSET, DMA_IP_CH_PORT_CFG_CSEL_FIELD_SIZE, muxId);
    }
    else
    {
        errorId = DMA_E_MUX_ID;
    }

    return errorId;
}
/** *****************************************************************************************************
 * \brief This function service to get current channel total transfer length.
 *
 * \verbatim
 * Syntax             : uint32 Dma_Ip_GetXferNumber
 *                      (
 *                          uint32 dmaBaseAddress
 *                          uint32 channelId
 *                          uint8 clearFlag
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : dmabaseAddress - Dma controller base address.
 *                      channelId      - Numeric identifier of the DMA channel.
 *                      clearFlag      - Clear data transfer length register or not.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Return total transfer length.
 *
 * Description        : This function service to get current channel total transfer length.
 * \endverbatim
 * Traceability       : SWSR_DMA_048
 *******************************************************************************************************/
uint32 Dma_Ip_GetXferNumber(uint32 dmaBaseAddress, uint32 channelId, uint8 clearFlag)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint32 length;

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Read the channel total transfer length. */
    length = Dma_Ip_ReadChannelRegister(dmaBaseAddress, channelId, DMA_IP_CH_DATA_TRANSFER_REG);

    if (TRUE == clearFlag)
    {
        /* #20 Clear the channel old total transfer length to zero. */
        Dma_Ip_WriteChannelRegister(dmaBaseAddress, channelId, DMA_RESET_TRANSFER_LENGTH,
                                    DMA_IP_CH_DATA_TRANSFER_REG);
    } /* else not needed */

    return length;
}
/** *****************************************************************************************************
 * \brief This function service to get current channel total transfer length.
 *
 * \verbatim
 * Syntax             : uint16 Dma_Ip_GetMuxId
 *                      (
 *                          const Dma_MuxParamType *table
 *                          uint32 tableLength
 *                          Dma_MuxDirectionType direct
 *                          uint32 peripheralAddress
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *table            - Pointer to mux id table.
 *                      tableLength       - Mux id table length.
 *                      direct            - Peripheral transfer direction, Read, write or both.
 *                      peripheralAddress - Peripheral FIFO address.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Return mux id.
 *
 * Description        : This function service to get current channel total transfer length.
 * \endverbatim
 * Traceability       : SWSR_DMA_049 SW_SM006
 *******************************************************************************************************/
DMA_LOCAL uint16 Dma_Ip_GetMuxId(const Dma_MuxParamType *table, uint32 tableLength,
                                 Dma_MuxDirectionType direct, uint32 peripheralAddress)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint32 index;
    uint8 findResult = FALSE;
    uint16 muxId = DMA_INVALID_MUX_ID;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check input parameters for plausibility. */
    if (NULL_PTR == table)
    {
        muxId = DMA_INVALID_MUX_ID;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #20 Search mux ID from Dma_SFMuxTable. */
        for (index = 0U; index < tableLength; index++)
        {
            if (peripheralAddress == (table[index].startAddress + table[index].length))
            {
                if (((uint8)direct & (uint8)table[index].muxDirect) > 0U)
                {
                    muxId = table[index].port;
                    /* #30 Mark Successfully get mux ID. */
                    findResult = TRUE;
                    break;
                } /* else not needed */
            } /* else not needed */
        }

        /* #30 Checking mux ID available or not. */
        if (FALSE == findResult)
        {
            muxId = DMA_INVALID_MUX_ID;
        } /* else not needed */
    }

    return muxId;
}
/** *****************************************************************************************************
 * \brief This function service to Read channel AXI reading Outstanding Limit.
 *
 * \verbatim
 * Syntax             : void Dma_Ip_SetChannelReadOutstanding
 *                      (
 *                          uint32 dmaBaseAddress
 *                          uint32 channelId
 *                          uint8 value
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : dmabaseAddress - Dma controller base address.
 *                      channelId      - Numeric identifier of the DMA channel.
 *                      value          - Set value to register.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function service to Read channel AXI reading Outstanding Limit.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
DMA_LOCAL void Dma_Ip_SetChannelReadOutstanding(uint32 dmaBaseAddress, uint32 channelId,
        uint8 value)
{
    /* ----- Implementation ----------------------------------------------- */
    /* #10 Read Outstanding bits from PORT_CONFIG register. */
    Dma_Ip_WriteChannelRegisterBits(dmaBaseAddress, channelId, DMA_IP_CH_PORT_CONFIG_REG,
                                    DMA_IP_CH_PORT_CFG_ROT_FIELD_OFFSET, DMA_IP_CH_PORT_CFG_ROT_FIELD_SIZE,
                                    ((uint32)value & DMA_OUTSTANDING_MASK));
}
/** *****************************************************************************************************
 * \brief This function service to write channel AXI reading Outstanding Limit.
 *
 * \verbatim
 * Syntax             : void Dma_Ip_SetChannelWriteOutstanding
 *                      (
 *                          uint32 dmaBaseAddress
 *                          uint32 channelId
 *                          uint8 value
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : dmabaseAddress - Dma controller base address.
 *                      channelId      - Numeric identifier of the DMA channel.
 *                      value          - Set value to register.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function service to write channel AXI reading Outstanding Limit.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
DMA_LOCAL void Dma_Ip_SetChannelWriteOutstanding(uint32 dmaBaseAddress, uint32 channelId,
        uint8 value)
{
    /* ----- Implementation ----------------------------------------------- */
    /* #10 Write Outstanding bits from PORT_CONFIG register. */
    Dma_Ip_WriteChannelRegisterBits(dmaBaseAddress, channelId, DMA_IP_CH_PORT_CONFIG_REG,
                                    DMA_IP_CH_PORT_CFG_WOT_FIELD_OFFSET, DMA_IP_CH_PORT_CFG_WOT_FIELD_SIZE,
                                    ((uint32)value & DMA_OUTSTANDING_MASK));
}
/** *****************************************************************************************************
 * \brief This function service to count the number of zeros between the highest sign bit and the first 1
 *
 * \verbatim
 * Syntax             : uint8 Dma_Ip_Clz32
 *                      (
 *                          uint32 param
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : param - 32bit values.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Return zeros number.
 *
 * Description        : This function service to count the number of zeros between the highest sign bit
 *                      and the first 1.
 *                      CLZ: Counte Leading Zeros.
 * \endverbatim
 * Traceability       : SWSR_DMA_049 SW_SM006
 *******************************************************************************************************/
DMA_LOCAL uint8 Dma_Ip_Clz32(uint32 param)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint8 value = (DMA_MAX_BIT_NUMBER - 1U);
    uint32 temp = param;

    /* ----- Development Error Checks ------------------------------------- */
    /* #20 Check input parameters for plausibility. */
    if (0U == temp)
    {
        value = DMA_MAX_BIT_NUMBER;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        if ((temp & DMA_CLZ_PHASE_1) > 0U)
        {
            value -= 16U;
            temp >>= 16U;
        } /* else not needed */

        if ((temp & DMA_CLZ_PHASE_2) > 0U)
        {
            value -= 8U;
            temp >>= 8U;
        } /* else not needed */

        if ((temp & DMA_CLZ_PHASE_3) > 0U)
        {
            value -= 4U;
            temp >>= 4U;
        } /* else not needed */

        if ((temp & DMA_CLZ_PHASE_4) > 0U)
        {
            value -= 2U;
            temp >>= 2U;
        } /* else not needed */

        if ((temp & DMA_CLZ_PHASE_5) > 0U)
        {
            value -= 1U;
        } /* else not needed */
    }

    return value;
}
/** *****************************************************************************************************
 * \brief This function service to get local buffer.
 *
 * \verbatim
 * Syntax             : void Dma_Ip_GetLocalBufferProp
 *                      (
 *                          uint32 dmaBaseAddress
 *                          Dma_LocalBufferType *bufferProp
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : dmabaseAddress - Dma controller base address.
 *
 * Parameters (inout) : *bufferProp    - Pointer to buffer.
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function service to get local buffer.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
DMA_LOCAL void Dma_Ip_GetLocalBufferProp(uint32 dmaBaseAddress, Dma_LocalBufferType *bufferProp)
{
    /* ----- Implementation ----------------------------------------------- */
    /* #10 Get localbuffer address and max size. */
    bufferProp->bufferBaseAddress = (uint32)(dmaBaseAddress + DMA_IP_LOCAL_BUFFER_OFFSET);
    bufferProp->bufferSize        = DMA_IP_LOCAL_BUFFER_MAX_BYTES;
}
/** *****************************************************************************************************
 * \brief This function service to free channel's link list node.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_Ip_FreeLinkListDesc
 *                      (
 *                          Dma_LinkListDescType *linkListDesc
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *linkListDesc - Pointer to link list node description.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Free link list node successful.
 *                      DMA_E_PARAM_POINTER: Pointer is NULL_PTR.
 *
 * Description        : This function service to free channel's link list node.
 * \endverbatim
 * Traceability       : SWSR_DMA_049 SW_SM007 SW_SM006
 *******************************************************************************************************/
DMA_LOCAL Std_ReturnType Dma_Ip_FreeLinkListDesc(Dma_linkListType *linkListDesc)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;
    Dma_linkListType *current;
    Dma_linkListType const *first = linkListDesc;
    Dma_linkListType *next;
    uint8 coreId;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check input parameters for plausibility */
    if (NULL_PTR == first)
    {
        errorId = DMA_E_PARAM_POINTER;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        coreId = Dma_Ip_GetCoreId();
        SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_00();

        if (0x00UL == first->physisAddress)
        {
            errorId = DMA_E_LINK_LIST;
        }
        else
        {
            /* PRQA S 0306, 2810, 3418, 3432 1 */
            DMA_LIST_FOR_EVERY_ENTRY_SAFE((&first->linkListHead), current, (next), Dma_linkListType,
                                          linkListNode)
            {
                /* #20 Delete link list node. */
                Dma_Ip_ListDelete(&current->linkListNode);
                /* #30 Clear the node bit map. No need to care about the return value. */
                (void)Dma_Ip_BitmapClear(&Dma_LinkListBitmap[coreId][0U], (uint32)current->bitmapIndex);
            }
            linkListDesc->physisAddress = DMA_LINK_LIST_INVALID_ADDRESS;
        }

        SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_00();
    }

    return errorId;
}
/** *****************************************************************************************************
 * \brief This function service to check dma base address and channel valid or not.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_Ip_CheckAddressAndChannelValid
 *                      (
 *                          uint32 dmabaseAddress
 *                          uint32 channelId
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : dmabaseAddress - Dma controller base address.
 *                      channelId      - Numeric identifier of the DMA channel.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Free link list node successful.
 *                      DMA_E_PARAM_CHANNEL_ID: Error due to invalid channel id(s) passed as parameter.
 *                      DMA_E_PARAM_BASE_ADDRESS: Error due to invalid Dma base address.
 *
 * Description        : This function service to check dma base address and channel valid or not.
 * \endverbatim
 * Traceability       : SWSR_DMA_049 SW_SM006
 *******************************************************************************************************/
DMA_LOCAL Std_ReturnType Dma_Ip_CheckAddressAndChannelValid(uint32 dmabaseAddress, uint32 channelId)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;

    /* ----- Implementation ----------------------------------------------- */
#if (DMA_LOCK_STEP_MODE == STD_ON)

    if (DMA_SF0_BASE == dmabaseAddress)
#else
    if ((DMA_SF0_BASE == dmabaseAddress) || (DMA_SF1_BASE == dmabaseAddress))
#endif /** #if (DMA_LOCK_STEP_MODE == STD_ON) */
    {
        if (channelId > DMA_SF_MAX_CHANNEL_NUMBER)
        {
            errorId = DMA_E_PARAM_CHANNEL_ID;
        }
        else
        {
            /* Do Nothing */
        }
    }
    else
    {
        errorId = DMA_E_PARAM_BASE_ADDRESS;
    }

    return errorId;
}
#if (DMA_UPDATE_CONFIG_API == STD_ON)
/** *****************************************************************************************************
 * \brief This function service to update transmission address and length information.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_Ip_UpdateTransmitAddressAndLength
 *                      (
 *                          const Dma_ChannelConfigType * const channel
 *                          const Dma_UpdateTransmissionType * const updateConfig
 *                          uint32 length
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *channel        - Pointer to a selected channel configuration structure.
 *                      *updateConfig   - Pointer to a update info.
 *                      length          - Total transmit data length.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Free link list node successful.
 *                      DMA_E_PARAMS: Input parameters error.
 *
 * Description        : This function support only updating the source address, destination address,
 *                      transmit data length and burst types registers. If you do not want to update
 *                      burst type, you can pass DMA_BURST_TYPE_UNDEFINED parameters to srcIncDirection
 *                      and dstIncDirection, and then ip layer function will bypass burst type
 *                      configuration.
 * \endverbatim
 * Traceability       : SWSR_DMA_015 SWSR_DMA_046 SWSR_DMA_049 SW_SM007 SW_SM006
 *******************************************************************************************************/
Std_ReturnType Dma_Ip_UpdateTransmitAddressAndLength(const Dma_ChannelConfigType *const channel,
        const Dma_UpdateTransmissionType *const updateConfig, uint32 length)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;
    Dma_ChannelRegType *dmaChannel = Dma_Ip_ToChannel(channel);
    Dma_linkListType *linkListPtr;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check input parameters for plausibility. */
    if (NULL_PTR == dmaChannel)
    {
        errorId = DMA_E_PARAM_POINTER;
    }
    else if ((Std_ReturnType)E_OK != Dma_Ip_CheckAddressAndChannelValid(
                 dmaChannel->channel.device->dmaBaseAddress, dmaChannel->channel.channelId))
    {
        errorId = DMA_E_PARAMS;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #20 Get program sequence counter for next start transmission. */
        dmaChannel->psCnt = Dma_Ip_GetChannelPsCnt(dmaChannel->channel.device->dmaBaseAddress,
                            dmaChannel->channel.channelId);

        SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_00();
        /* #30 Update new configuration parameters. */
        dmaChannel->deviceConfig.srcAddress = updateConfig->srcAddress;
        dmaChannel->deviceConfig.dstAddress = updateConfig->dstAddress;
        dmaChannel->deviceConfig.srcIncDirection = updateConfig->srcIncDirection;
        dmaChannel->deviceConfig.dstIncDirection = updateConfig->dstIncDirection;
        dmaChannel->deviceConfig.srcBusWidth = updateConfig->srcBusWidth;
        dmaChannel->deviceConfig.dstBusWidth = updateConfig->dstBusWidth;

        if (DMA_MEMORY_TO_MEMORY == dmaChannel->deviceConfig.direction)
        {
            /* PRQA S 0306 1 */
            errorId = Dma_Ip_FreeLinkListDesc((Dma_linkListType *)dmaChannel->linkListDesc.physisAddress);
            /* #40 The memory from/to memory link list node address is the first MAD register SOURCE_ADDRESS. */
            linkListPtr = Dma_Ip_SetLinkList(dmaChannel, length,
                                             Dma_Ip_GetMaxBlockSize((Dma_LoopModeType)dmaChannel->deviceConfig.loopMode),
                                             dmaChannel->deviceConfig.periodLength);
        }
        else
        {
            if (DMA_TRANSFER_MODE_SINGLE == dmaChannel->deviceConfig.transferMode)
            {
                /* #50 Update configuration to node. *//* PRQA S 0306 1 */
                linkListPtr = (Dma_linkListType *)dmaChannel->linkListDesc.physisAddress;
                linkListPtr->linkListItem.srcAddress = updateConfig->srcAddress;
                linkListPtr->linkListItem.dstAddress = updateConfig->dstAddress;
                /* #60 Update buffersize configuration and does not change loop mode. This needs to be noted by users */
                linkListPtr->linkListItem.blockConfig &= (~DMA_IP_CH_DATA_BLK_CFG_BUF_SIZE_LP2_TTSIZFIELD_MASK);
                linkListPtr->linkListItem.blockConfig |= DMA_IP_CH_DATA_BLK_CFG_BUF_SIZE_LP2_TTSIZFIELD(
                            length - 1U);

                linkListPtr->linkListItem.transactionControl &= (~
                        (DMA_IP_CH_TRANSACTION_CTRL_SRC_BST_TYPE_FIELD_MASK |
                         DMA_IP_CH_TRANSACTION_CTRL_DST_BST_TYPE_FIELD_MASK |
                         DMA_IP_CH_TRANSACTION_CTRL_SRC_BSIZE_FIELD_MASK |
                         DMA_IP_CH_TRANSACTION_CTRL_DST_BSIZE_FIELD_MASK));
                linkListPtr->linkListItem.transactionControl |= (
                            DMA_IP_CH_TRANSACTION_CTRL_SRC_BST_TYPE_FIELD(updateConfig->srcIncDirection) |
                            DMA_IP_CH_TRANSACTION_CTRL_DST_BST_TYPE_FIELD(updateConfig->dstIncDirection) |
                            DMA_IP_CH_TRANSACTION_CTRL_SRC_BSIZE_FIELD(updateConfig->srcBusWidth) |
                            DMA_IP_CH_TRANSACTION_CTRL_DST_BSIZE_FIELD(updateConfig->dstBusWidth)
                        );
            }
            else
            {
                /* #80 Free the channel link list description and then reassemble. *//* PRQA S 0306 1 */
                errorId = Dma_Ip_FreeLinkListDesc((Dma_linkListType *)dmaChannel->linkListDesc.physisAddress);

                if ((Std_ReturnType)E_OK != errorId)
                {
                    linkListPtr = NULL_PTR;
                }
                else
                {
                    /* #90 The peripheral from/to memory link list node address is link list buffer. */
                    linkListPtr = Dma_Ip_SetLinkList(dmaChannel, length, dmaChannel->blockSize,
                                                     dmaChannel->deviceConfig.periodLength);
                }

            }
        }

        SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_00();

        if (NULL_PTR == linkListPtr)
        {
            errorId = DMA_E_LINK_LIST;
        }
        else
        {
            /* #100 Write new configurations to register. */
            Dma_Ip_WriteChannelRegister(dmaChannel->channel.device->dmaBaseAddress,
                                        dmaChannel->channel.channelId, linkListPtr->linkListItem.srcAddress, DMA_IP_CH_SOURCE_ADDRESS_REG);
            Dma_Ip_WriteChannelRegister(dmaChannel->channel.device->dmaBaseAddress,
                                        dmaChannel->channel.channelId, linkListPtr->linkListItem.dstAddress,
                                        DMA_IP_CH_DESTINATION_ADDRESS_REG);
            Dma_Ip_WriteChannelRegister(dmaChannel->channel.device->dmaBaseAddress,
                                        dmaChannel->channel.channelId, linkListPtr->linkListItem.blockConfig,
                                        DMA_IP_CH_DATA_BLOCK_CONFIG_REG);
            /* #110 Update burst type register. */
            Dma_Ip_WriteChannelRegister(dmaChannel->channel.device->dmaBaseAddress,
                                        dmaChannel->channel.channelId, linkListPtr->linkListItem.transactionControl,
                                        DMA_IP_CH_TRANSACTION_CTRL_REG);

            /* #120 Checking wether link list transfer mode. */
            if (DMA_TRANSFER_MODE_LINKLIST == dmaChannel->deviceConfig.transferMode)
            {
                Dma_Ip_WriteChannelRegister(dmaChannel->channel.device->dmaBaseAddress,
                                            dmaChannel->channel.channelId, linkListPtr->linkListItem.linkAddress, DMA_IP_CH_LINK_ADDRESS_REG);
            }

            if (DMA_MAD_CRC == dmaChannel->deviceConfig.madCrcMode)
            {
                /* #130 Calculate MAD CRC result. */
                errorId = Dma_Ip_CalculateMadCrc(0U, &linkListPtr->linkListItem,
                                                 dmaChannel->deviceConfig.madCrcMode);

                if ((Std_ReturnType)E_OK == errorId)
                {
                    Dma_Ip_WriteChannelRegister(dmaChannel->channel.device->dmaBaseAddress,
                                                dmaChannel->channel.channelId, linkListPtr->linkListItem.madCrc, DMA_IP_CH_MAD_CRC_REG);
                } /* else not needed */
            } /* else not needed */
        }
    }

    return errorId;
}
#endif /** #if (DMA_UPDATE_CONFIG_API == STD_ON) */
#if (DMA_CONFIG_CHECK_API == STD_ON)
/** *****************************************************************************************************
 * \brief This function service to check configuration parameters.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_Ip_ConfigurationCheck
 *                      (
 *                          Dma_ChannelConfigType *channel
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *channel   - Pointer to a selected channel configuration structure.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Configuration check successful.
 *                      E_NOT_OK: Configuration check failed.
 *                      DMA_E_PARAMS: Input parameters error.
 *                      DMA_E_PARAM_POINTER: DMA_E_PARAM_POINTER: Pointer is NULL_PTR.
 *
 * Description        : This function service to check configuration parameters.
 * \endverbatim
 * Traceability       : SWSR_DMA_049 SWSR_DMA_052 SW_SM006
 *******************************************************************************************************/
Std_ReturnType Dma_Ip_ConfigurationCheck(Dma_ChannelConfigType *channel)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;
    Dma_ChannelRegType *dmaChannel = Dma_Ip_ToChannel(channel);
    Dma_linkListType *linkListPtr;
    Dma_LinkListNodeConfigType linkListItem;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check input parameters for plausibility. */
    if (NULL_PTR == dmaChannel)
    {
        errorId = DMA_E_PARAM_POINTER;
    }
    else if ((Std_ReturnType)E_OK != Dma_Ip_CheckAddressAndChannelValid(
                 dmaChannel->dmaConfig.baseAddress, dmaChannel->channel.channelId))
    {
        errorId = DMA_E_PARAMS;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #20 Read the channel configurations from register. */
        linkListItem.srcAddress         = Dma_Ip_ReadChannelRegister(dmaChannel->dmaConfig.baseAddress,
                                          dmaChannel->channel.channelId, DMA_IP_CH_SOURCE_ADDRESS_REG);
        linkListItem.dstAddress         = Dma_Ip_ReadChannelRegister(dmaChannel->dmaConfig.baseAddress,
                                          dmaChannel->channel.channelId, DMA_IP_CH_DESTINATION_ADDRESS_REG);
        linkListItem.transactionControl = Dma_Ip_ReadChannelRegister(dmaChannel->dmaConfig.baseAddress,
                                          dmaChannel->channel.channelId, DMA_IP_CH_TRANSACTION_CTRL_REG);
        linkListItem.blockConfig        = Dma_Ip_ReadChannelRegister(dmaChannel->dmaConfig.baseAddress,
                                          dmaChannel->channel.channelId, DMA_IP_CH_DATA_BLOCK_CONFIG_REG);
        linkListItem.operationMode      = Dma_Ip_ReadChannelRegister(dmaChannel->dmaConfig.baseAddress,
                                          dmaChannel->channel.channelId, DMA_IP_CH_OPERATION_MODE_REG);
        linkListItem.operationData      = Dma_Ip_ReadChannelRegister(dmaChannel->dmaConfig.baseAddress,
                                          dmaChannel->channel.channelId, DMA_IP_CH_OPERATION_DATA_REG);
        linkListItem.madCrc             = Dma_Ip_ReadChannelRegister(dmaChannel->dmaConfig.baseAddress,
                                          dmaChannel->channel.channelId, DMA_IP_CH_MAD_CRC_REG);
        linkListItem.linkAddress        = Dma_Ip_ReadChannelRegister(dmaChannel->dmaConfig.baseAddress,
                                          dmaChannel->channel.channelId, DMA_IP_CH_LINK_ADDRESS_REG);

        linkListPtr = (Dma_linkListType *)dmaChannel->linkListDesc.physisAddress;

        /* #30 Check MAD configuration one by one. */
        if (linkListPtr->linkListItem.srcAddress != linkListItem.srcAddress)
        {
            errorId = E_NOT_OK;
        }
        else if (linkListPtr->linkListItem.dstAddress != linkListItem.dstAddress)
        {
            errorId = E_NOT_OK;
        }
        else if (linkListPtr->linkListItem.transactionControl != linkListItem.transactionControl)
        {
            errorId = E_NOT_OK;
        }
        else if (linkListPtr->linkListItem.blockConfig != linkListItem.blockConfig)
        {
            errorId = E_NOT_OK;
        }
        else if (linkListPtr->linkListItem.operationMode != linkListItem.operationMode)
        {
            errorId = E_NOT_OK;
        }
        else if (linkListPtr->linkListItem.operationData != linkListItem.operationData)
        {
            errorId = E_NOT_OK;
        }
        else if (linkListPtr->linkListItem.madCrc != linkListItem.madCrc)
        {
            errorId = E_NOT_OK;
        }
        else if (linkListPtr->linkListItem.linkAddress != linkListItem.linkAddress)
        {
            errorId = E_NOT_OK;
        }
        else
        {
            /* Do Nothing */
        }
    }

    return errorId;
}
#endif /** #if (DMA_CONFIG_CHECK_API == STD_ON) */
/** *****************************************************************************************************
 * \brief This function servce to update MAD crc, valid only in cyclic and DMA_MAD_CRC mode.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_Ip_UpdateCyclicCRC
 *                      (
 *                          const Dma_ChannelConfigType * const channel
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *channel   - Pointer to a selected channel configuration structure.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Configuration check successful.
 *                      DMA_E_PARAMS: Input parameters error.
 *                      DMA_E_PARAM_POINTER: DMA_E_PARAM_POINTER: Pointer is NULL_PTR.
 *                      DMA_E_TIMEOUT: Unexpect recalculating CRC error occurred.
 *
 * Description        : If you are using DMA_CYCLIC transaction mode and DMA_TRANSFER_MODE_LINKLIST
 *                      transferMode mode and enable DMA_MAD_CRC, when transfer launch to the last node,
 *                      you must recalculating CRC values of all link list nodes.
 * \endverbatim
 * Traceability       : SWSR_DMA_049 SWSR_DMA_054 SW_SM006
 *******************************************************************************************************/
Std_ReturnType Dma_Ip_UpdateCyclicCRC(const Dma_ChannelConfigType *const channel)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId;
    Dma_ChannelRegType const *dmaChannel = Dma_Ip_ToChannel(channel);
    Dma_linkListType *linkListPtr;
    Dma_LinkListNodeConfigType const *shadowReg;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check input parameters for plausibility. */
    if (NULL_PTR == dmaChannel)
    {
        errorId = DMA_E_PARAM_POINTER;
    }
    else if ((Std_ReturnType)E_OK != Dma_Ip_CheckAddressAndChannelValid(
                 dmaChannel->channel.device->dmaBaseAddress, dmaChannel->channel.channelId))
    {
        errorId = DMA_E_PARAMS;
    }
    else
    {
        /* #20 Get first link list node of the channel. *//* PRQA S 0306 1 */
        linkListPtr = (Dma_linkListType *)dmaChannel->linkListDesc.physisAddress;
        /* #30 Get the last link list node of the channel. *//* PRQA S 0306 1 */
        shadowReg = (Dma_LinkListNodeConfigType *)(DMA_IP_CHANNEL_BASE(
                        dmaChannel->channel.device->dmaBaseAddress, dmaChannel->channel.channelId) + 0x40UL);
        /* #30 Recalculating CRC values of all link list nodes. */
        errorId = Dma_Ip_CalculateMadCrc(shadowReg->madCrc, &linkListPtr->linkListItem, DMA_MAD_CRC);
    }

    return errorId;
}
/** *****************************************************************************************************
 * \brief This function service to set DMA lockstep bit to soc system control register.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Dma_Ip_SocScrSetBit
 *                      (
 *                          const Dma_ScrSignalType * const signalPtr
 *                          uint32 value
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *signalPtr - Pointer to a selected signal configuration.
 *                      value      - True or False.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Configuration check successful.
 *                      DMA_E_LOCKSTEP: Error due to set lockstep failed.
 *
 * Description        : This function service to set DMA lockstep bit to soc system control register.
 * \endverbatim
 * Traceability       : SWSR_DMA_005
 *******************************************************************************************************/
Std_ReturnType Dma_Ip_SocScrSetBit(const Dma_ScrSignalType *const signalPtr, uint32 value)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;
    uint32 address = DMA_APB_SCR_SF_BASE;
    uint32 val;

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Set DMA lockstep bit. */
    if (DMA_TYPE_L31 == signalPtr->type)
    {
        address = address + DMA_LOCKSTEP_REG_OFFSET;
        address = address + (((uint32)signalPtr->startBit >> 5U) * 4U);
        val = REG_READ32(address);

        if (((val & (1UL << 31U)) >> 31U) == 0U)
        {
            RMWREG32(address, (signalPtr->startBit % 32U), signalPtr->width, value);
        }
        else
        {
            errorId = DMA_E_LOCKSTEP;
        }
    }/* else not needed */

    return errorId;
}

/** *****************************************************************************************************
 * \brief This function service to get core id.
 *
 * \verbatim
 * Syntax             : uint8 Dma_Ip_GetCoreId
 *                      (
 *                          Dma_ScrSignalType *signalPtr
 *                          uint32 value
 *                      )
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
 * Return value       : Return core id.
 *
 * Description        : This function service to get core id.
 * \endverbatim
 * Traceability       : SWSR_DMA_013
 *******************************************************************************************************/
uint8 Dma_Ip_GetCoreId(void)
{
    /* ----- Implementation ----------------------------------------------- */
    /* #10 Return the core ID. */
    return  Mcu_GetCoreID();
}

/** *****************************************************************************************************
 * \brief This function service to dma controller SF0 interrupt service routine.
 *
 * \verbatim
 * Syntax             : void Dma_Ip_SF0IrqHandler
 *                      (
 *                          uint32 channelId
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : channelId - Numeric identifier of the DMA channel.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function service to dma controller SF0 interrupt service routine.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004 SW_SM006
 *******************************************************************************************************/
void Dma_Ip_SF0IrqHandler(uint32 channelId)
{
    /* ----- Local Variables ---------------------------------------------- */
    Dma_ControllerStatusType channelStatus = DMA_PENDING;
    uint8 coreId = Dma_Ip_GetCoreId();;
    uint8 errorId = (uint8)E_NOT_OK;
    Dma_ControllerParamType const *device = Dma_ControllerSF0[coreId];
    uint32 interruptEnable;
    uint32 interruptStatus;
    Dma_ChannelConfigType *cptr;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module states and if the channel id exceeds max channel number. */
    DmaHookBegin_Dma_Ip_SFIrqHandler();
    if ((DMA_INIT != (*Dma_InitializeState[coreId])) && (channelId < DMA_SF_MAX_CHANNEL_NUMBER))
    {
        /* #20 If the initialization is not completed, disable and clear all interrupt. */
        Dma_Ip_WriteChannelRegister(DMA_IP_CHANNEL_BASE(DMA_SF0_BASE, channelId), channelId,
                                    DMA_DISABLE_ALL_INTERRUPT, DMA_IP_CH_INTERRUPT_ENABLE_REG);
        Dma_Ip_ClearInterrupt(DMA_IP_CHANNEL_BASE(DMA_SF0_BASE, channelId), channelId,
                              DMA_CLEAR_ALL_INTERRUPT_STATUS);
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #30 Check for available channel. *//* PRQA S 0306, 2810, 3432 1 */
        DMA_LIST_FOR_EVERY_ENTRY ((&device->channels), cptr, Dma_ChannelConfigType, node)
        {
            if (channelId == cptr->channelId)
            {
                errorId = (uint8)E_OK;
                break;
            }/* else not needed */
        }

        if ((uint8)E_OK == errorId)
        {
            /* #40 Read interrupt enable and status regsters. */
            interruptEnable = Dma_Ip_ReadChannelRegister(device->dmaBaseAddress, channelId,
                              DMA_IP_CH_INTERRUPT_ENABLE_REG);
            interruptStatus = Dma_Ip_GetInterruptState(device->dmaBaseAddress, channelId);
            DmaHookRegisterError_Dma_Ip_SFIrqHandler();
            /* #50 If there are no valid interrupts triggered, clear all interrupts status flags. */
            if ((interruptEnable & interruptStatus) == 0U)
            {
                Dma_Ip_ClearInterrupt(device->dmaBaseAddress, channelId, DMA_CLEAR_ALL_INTERRUPT_STATUS);
            }
            else
            {
                /* #60 Clear interrupts status flags. */
                Dma_Ip_ClearInterrupt(device->dmaBaseAddress, channelId, interruptStatus);

                /* #70 Process the channel each MAD done interrupts. */
                if (((interruptEnable & (uint32)DMA_CH_INT_EN_EVERY_MAD_DONE) > 0U)
                        && ((interruptStatus & (uint32)DMA_CH_INT_EN_EVERY_MAD_DONE) > 0U))
                {
                    channelStatus = DMA_BLOCK_DONE;
                }/* else not needed */

                /* #80 Process the channel last MAD done interrupts. */
                if (((interruptEnable & (uint32)DMA_CH_INT_EN_LST_MAD_DONE) > 0U)
                        && ((interruptStatus & (uint32)DMA_CH_INT_EN_LST_MAD_DONE) > 0U))
                {
                    channelStatus = DMA_COMPLETED;
                }/* else not needed */

                DmaHookAbortError_Dma_Ip_SFIrqHandler();

                /* #90 Process the channel abort interrupts. */
                if (((interruptEnable & (uint32)DMA_CH_INT_EN_CH_ABORT) > 0U)
                        && ((interruptStatus & (uint32)DMA_CH_INT_EN_CH_ABORT) > 0U))
                {
                    channelStatus = DMA_ABORT;
                }/* else not needed */

                DmaHookSYSError_Dma_Ip_SFIrqHandler();

                /* #100 Process the channel error interrupts. */
                if (((interruptEnable & (uint32)DMA_SYSTEM_ERROR_MASK) > 0U)
                        && ((interruptStatus & (uint32)DMA_SYSTEM_ERROR_MASK) > 0U))
                {
                    channelStatus = DMA_ERR;
                }/* else not needed */

                DmaHookBusError_Dma_Ip_SFIrqHandler();

                /* #110 Process the channel bus error interrupts. */
                if (((interruptEnable & (uint32)DMA_BUS_ERROR_MASK) > 0U)
                        && ((interruptStatus & (uint32)DMA_BUS_ERROR_MASK) > 0U))
                {
                    channelStatus = DMA_BUS_ERR;
                }/* else not needed */

                DmaHookCRCError_Dma_Ip_SFIrqHandler();

                /* #120 Process the channel CRC error interrupts. */
                if (((interruptEnable & (uint32)DMA_CRC_ERROR_MASK) > 0U)
                        && ((interruptStatus & (uint32)DMA_CRC_ERROR_MASK) > 0U))
                {
                    channelStatus = DMA_CRC_ERROR;
                }/* else not needed */

                /* #130 If there are a valid notification function then calls Callouts. */
                if (NULL_PTR != cptr->irqCallback)
                {
                    /* PRQA S 0314 1 */
                    cptr->irqCallback(channelStatus, (void *)cptr);
                }/* else not needed */
            }
        }
        else
        {
            /* #140 If error occurred just clear interrupt status. */
            Dma_Ip_ClearInterrupt(device->dmaBaseAddress, channelId, DMA_CLEAR_ALL_INTERRUPT_STATUS);
        }
    }
    DmaHookEnd_Dma_Ip_SFIrqHandler();
}
#if (DMA_LOCK_STEP_MODE == STD_OFF)
/** *****************************************************************************************************
 * \brief This function service to dma controller SF1 interrupt service routine.
 *
 * \verbatim
 * Syntax             : void Dma_Ip_SF1IrqHandler
 *                      (
 *                          uint32 channelId
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : channelId - Numeric identifier of the DMA channel.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function service to dma controller SF1 interrupt service routine.
 * \endverbatim
 * Traceability       : SWSR_DMA_013 SWSR_DMA_020 SWSR_DMA_044 SWSR_DMA_051 SW_SM003 SW_SM004 SW_SM006
 *******************************************************************************************************/
void Dma_Ip_SF1IrqHandler(uint32 channelId)
{
    /* ----- Local Variables ---------------------------------------------- */
    Dma_ControllerStatusType channelStatus = DMA_PENDING;
    uint8 coreId = Dma_Ip_GetCoreId();
    uint8 errorId = (uint8)E_NOT_OK;
    Dma_ControllerParamType const *device = Dma_ControllerSF1[coreId];
    uint32 interruptEnable;
    uint32 interruptStatus;
    Dma_ChannelConfigType *cptr;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module states and if the channel id exceeds max channel number. */
    DmaHookBegin_Dma_Ip_SFIrqHandler();
    if ((DMA_INIT != (*Dma_InitializeState[coreId])) && (channelId < DMA_SF_MAX_CHANNEL_NUMBER))
    {
        /* #20 If the initialization is not completed, disable and clear all interrupt. */
        Dma_Ip_WriteChannelRegister(DMA_IP_CHANNEL_BASE(DMA_SF1_BASE, channelId), channelId,
                                    DMA_DISABLE_ALL_INTERRUPT, DMA_IP_CH_INTERRUPT_ENABLE_REG);
        Dma_Ip_ClearInterrupt(DMA_IP_CHANNEL_BASE(DMA_SF1_BASE, channelId), channelId,
                              DMA_CLEAR_ALL_INTERRUPT_STATUS);
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #30 Check for available channel. *//* PRQA S 0306, 2810, 3432 1 */
        DMA_LIST_FOR_EVERY_ENTRY ((&device->channels), cptr, Dma_ChannelConfigType, node)
        {
            if (channelId == cptr->channelId)
            {
                errorId = (uint8)E_OK;
                break;
            }/* else not needed */
        }

        if ((uint8)E_OK == errorId)
        {
            /* #40 Read interrupt enable and status regsters. */
            interruptEnable = Dma_Ip_ReadChannelRegister(device->dmaBaseAddress, channelId,
                              DMA_IP_CH_INTERRUPT_ENABLE_REG);
            interruptStatus = Dma_Ip_GetInterruptState(device->dmaBaseAddress, channelId);
            DmaHookRegisterError_Dma_Ip_SFIrqHandler();
            /* #50 If there are no valid interrupts triggered, clear all interrupts status flags. */
            if ((interruptEnable & interruptStatus) == 0U)
            {
                Dma_Ip_ClearInterrupt(device->dmaBaseAddress, channelId, DMA_CLEAR_ALL_INTERRUPT_STATUS);
            }
            else
            {
                /* #60 Clear interrupts status flags. */
                Dma_Ip_ClearInterrupt(device->dmaBaseAddress, channelId, interruptStatus);

                /* #70 Process the channel each MAD done interrupts. */
                if (((interruptEnable & (uint32)DMA_CH_INT_EN_EVERY_MAD_DONE) > 0U)
                        && ((interruptStatus & (uint32)DMA_CH_INT_EN_EVERY_MAD_DONE) > 0U))
                {
                    channelStatus = DMA_BLOCK_DONE;
                }/* else not needed */

                /* #80 Process the channel last MAD done interrupts. */
                if (((interruptEnable & (uint32)DMA_CH_INT_EN_LST_MAD_DONE) > 0U)
                        && ((interruptStatus & (uint32)DMA_CH_INT_EN_LST_MAD_DONE) > 0U))
                {
                    channelStatus = DMA_COMPLETED;
                }/* else not needed */

                DmaHookAbortError_Dma_Ip_SFIrqHandler();

                /* #90 Process the channel abort interrupts. */
                if (((interruptEnable & (uint32)DMA_CH_INT_EN_CH_ABORT) > 0U)
                        && ((interruptStatus & (uint32)DMA_CH_INT_EN_CH_ABORT) > 0U))
                {
                    channelStatus = DMA_ABORT;
                }/* else not needed */

                DmaHookSYSError_Dma_Ip_SFIrqHandler();

                /* #100 Process the channel error interrupts. */
                if (((interruptEnable & (uint32)DMA_SYSTEM_ERROR_MASK) > 0U)
                        && ((interruptStatus & (uint32)DMA_SYSTEM_ERROR_MASK) > 0U))
                {
                    channelStatus = DMA_ERR;
                }/* else not needed */

                DmaHookBusError_Dma_Ip_SFIrqHandler();

                /* #110 Process the channel bus error interrupts. */
                if (((interruptEnable & (uint32)DMA_BUS_ERROR_MASK) > 0U)
                        && ((interruptStatus & (uint32)DMA_BUS_ERROR_MASK) > 0U))
                {
                    channelStatus = DMA_BUS_ERR;
                }/* else not needed */

                DmaHookCRCError_Dma_Ip_SFIrqHandler();

                /* #120 Process the channel CRC error interrupts. */
                if (((interruptEnable & (uint32)DMA_CRC_ERROR_MASK) > 0U)
                        && ((interruptStatus & (uint32)DMA_CRC_ERROR_MASK) > 0U))
                {
                    channelStatus = DMA_CRC_ERROR;
                }/* else not needed */

                /* #130 If there are a valid notification function then calls Callouts. */
                if (NULL_PTR != cptr->irqCallback)
                {
                    /* PRQA S 0314 1 */
                    cptr->irqCallback(channelStatus, (void *)cptr);
                }/* else not needed */
            }
        }
        else
        {
            /* #140 If error occurred just clear interrupt status. */
            Dma_Ip_ClearInterrupt(device->dmaBaseAddress, channelId, DMA_CLEAR_ALL_INTERRUPT_STATUS);
        }
    }
    DmaHookEnd_Dma_Ip_SFIrqHandler();
}
#endif /** #if (DMA_LOCK_STEP_MODE == STD_OFF) */
/** *****************************************************************************************************
 * \brief This function service to find the first bit set.
 *
 * \verbatim
 * Syntax             : uint8 Dma_Ip_Ffs32
 *                      (
 *                          uint32 val
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : val - Input select value.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Return dma channel's configurations.
 *
 * Description        : Find the first bit set, find the first bit set to 1, start from bit0 to find
 *                      whether to set to 1, 32-bit numerical value check bit31 after stopping.
 * \endverbatim
 * Traceability       : SWSR_DMA_049 SW_SM006
 *******************************************************************************************************/
DMA_LOCAL uint8 Dma_Ip_Ffs32(uint32 val)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint8 num = 1U;
    uint32 temp = val;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check input parameters for plausibility. */
    if (0U == temp)
    {
        num = 0U;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #20 Find the first bit set to 1. */
        if ((temp & DMA_FFS_PHASE_1) == 0U)
        {
            num += 16U;
            temp = (temp >> 16U);
        }

        if ((temp & DMA_FFS_PHASE_2) == 0U)
        {
            num += 8U;
            temp = (temp >> 8U);
        }

        if ((temp & DMA_FFS_PHASE_3) == 0U)
        {
            num += 4U;
            temp = (temp >> 4U);
        }

        if ((temp & DMA_FFS_PHASE_4) == 0U)
        {
            num += 2U;
            temp = (temp >> 2U);
        }

        if ((temp & DMA_FFS_PHASE_5) == 0U)
        {
            num += 1U;
        }
    }

    return num;
}
/** *****************************************************************************************************
 * \brief This function service to bit map setting.
 *
 * \verbatim
 * Syntax             : boolean Dma_Ip_BitmapSet
 *                      (
 *                          uint32* bitmap
 *                          uint32 bit
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : *bitmap - Pointer to link list bit map.
 *                      bit     - Which bit want to set.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : TRUE: Bit set successful.
 *                      FALSE: Bit set failed.
 *
 * Description        : This function service to bit map setting.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
DMA_LOCAL uint8 Dma_Ip_BitmapSet(uint32 *bitmap, uint32 bit)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint32 temp;
    boolean retValue;
    uint32 mask = 1UL << DMA_BITMAP_BIT_IN_INT(bit);

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Setting the specified bit to bit map. */
    temp = (uint32)Dma_ArchAtomicOr(&((uint32 *)bitmap)[DMA_BITMAP_INT(bit)], mask);

    if ((temp & mask) > 0U)
    {
        retValue = 1U;
    }
    else
    {
        retValue = 0U;
    }

    return retValue;
}
/** *****************************************************************************************************
 * \brief This function service to bit map clear.
 *
 * \verbatim
 * Syntax             : boolean Dma_Ip_BitmapClear
 *                      (
 *                          uint32* bitmap
 *                          uint32 bit
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : *bitmap - Pointer to link list bit map.
 *                      bit     - Which bit want to set.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : TRUE: Bit clear successful.
 *                      FALSE: Bit clear failed.
 *
 * Description        : This function service to bit map clear.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
DMA_LOCAL boolean Dma_Ip_BitmapClear(uint32 *bitmap, uint32 bit)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint32 temp;
    boolean retValue;
    uint32 mask = 1UL << DMA_BITMAP_BIT_IN_INT(bit);

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Clear the specified bit to bit map. */
    temp = (uint32)Dma_ArchAtomicAnd(&((uint32 *)bitmap)[DMA_BITMAP_INT(bit)], ~mask);

    if ((temp & mask) > 0U)
    {
        retValue = (boolean)TRUE;
    }
    else
    {
        retValue = (boolean)FALSE;
    }

    return retValue;
}
/** *****************************************************************************************************
 * \brief This function service to find first zero.
 *
 * \verbatim
 * Syntax             : uint8 Dma_Ip_ffz
 *                      (
 *                          uint32 x
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : x - Selected value.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : TRUE: Bit clear successful.
 *                      FALSE: Bit clear failed.
 *
 * Description        : This function service to find first zero.
 *
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
DMA_LOCAL uint8 Dma_Ip_ffz(uint32 x)
{
    /* ----- Implementation ----------------------------------------------- */
    /* #10 Find first zero from specified variable. */
    return (uint8)Dma_Ip_Ffs32(~x) - 1U;
}
/** *****************************************************************************************************
 * \brief This function service to set bit map of find first zero.
 *
 * \verbatim
 * Syntax             : uint32 Dma_Ip_BitmapFfz
 *                      (
 *                          const uint32 * const bitmap
 *                          uint32 numbits
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : *bitmap - Pointer to link list bit map.
 *                      numbits - Bit position.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : TRUE: Bit clear successful.
 *                      FALSE: Bit clear failed.
 *
 * Description        : This function service to set bit map of find first zero.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
DMA_LOCAL uint32 Dma_Ip_BitmapFfz(const uint32 *const bitmap, uint32 numbits)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint32 i;
    uint32 bit = DMA_INVALID_VALUE;

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Find first zero from bit map. */
    for (i = 0U; i < DMA_BITMAP_NUM_WORDS(numbits); i++)
    {
        if (bitmap[i] == ~0UL)
        {
            continue;
        } /* else not needed */

        bit = ((i * DMA_BITMAP_BITS_PER_WORD) + Dma_Ip_ffz(bitmap[i]));

        if (bit < numbits)
        {
            break;
        } /* else not needed */

        bit = DMA_INVALID_VALUE;
    }

    return bit;
}
/** *****************************************************************************************************
 * \brief This function service to search dma channel configurations.
 *
 * \verbatim
 * Syntax             : Dma_ChannelRegType *Dma_Ip_ToChannel
 *                      (
 *                          const Dma_ChannelConfigType * const channelPtr
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *channel - Pointer to a selected channel configuration structure.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Return dma channel's configurations.
 *
 * Description        : This function service to search dma channel configurations.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
DMA_LOCAL_INLINE Dma_ChannelRegType *Dma_Ip_ToChannel(const Dma_ChannelConfigType *const channelPtr)
{
    /* ----- Implementation ----------------------------------------------- */
    /* #10 Return Dma_ChannelRegType to caller. *//* PRQA S 0306, 2810, 3432 1 */
    return DMA_CONTAINER_OF((channelPtr), Dma_ChannelRegType, channel);
}
/** *****************************************************************************************************
 * \brief This function service initialize link list nodes.
 *
 * \verbatim
 * Syntax             : void Dma_Ip_ListInitialize
 *                      (
 *                          struct Dma_ListNodeType *list
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *list - Pointer to link list node.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function service initialize link list nodes.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
DMA_LOCAL_INLINE void Dma_Ip_ListInitialize(struct Dma_ListNodeType *list)
{
    list->prev = list;
    list->next = list;
}
/** *****************************************************************************************************
 * \brief This function service add link list to tail.
 *
 * \verbatim
 * Syntax             : void Dma_Ip_ListAddTail
 *                      (
 *                          struct Dma_ListNodeType *list
 *                          struct Dma_ListNodeType *item
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *list - Pointer to link list node.
 *                      *item - Pointer to node which need to add to link list.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function service add link list to tail.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
DMA_LOCAL_INLINE void Dma_Ip_ListAddTail(struct Dma_ListNodeType *list, struct Dma_ListNodeType *item)
{
    item->prev = list->prev;
    item->next = list;
    list->prev->next = item;
    list->prev = item;
}
/** *****************************************************************************************************
 * \brief This function service delete node from link list.
 *
 * \verbatim
 * Syntax             : void Dma_Ip_ListDelete
 *                      (
 *                          struct Dma_ListNodeType *item
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : *item - Pointer to node which need to add to link list.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function service delete node from link list.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
DMA_LOCAL_INLINE void Dma_Ip_ListDelete(struct Dma_ListNodeType *item)
{
    item->next->prev = item->prev;
    item->prev->next = item->next;
    item->prev = NULL_PTR;
    item->next = NULL_PTR;
}
/** *****************************************************************************************************
 * \brief This function service to search dma channel configurations.
 *
 * \verbatim
 * Syntax             : uint8 Dma_Ip_GetChannelPsCnt
 *                      (
 *                          uint32 dmaBaseAddress
 *                          uint32 channel
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : dmabaseAddress - Dma controller base address.
 *                      channelId      - Numeric identifier of the DMA channel.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Return current channel program sequence counter.
 *
 * Description        : This function service to search dma channel configurations.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
DMA_LOCAL uint8 Dma_Ip_GetChannelPsCnt(uint32 dmaBaseAddress, uint32 channel)
{
    /* ----- Implementation ----------------------------------------------- */
    /* #10 Read program sequence counter. */
    return (uint8)Dma_Ip_ReadChannelRegisterBits(dmaBaseAddress, channel,
            DMA_IP_CH_PROGRAMM_SEQUENCE_CTRL_REG,
            DMA_IP_CH_PROG_SEQ_CTRL_PS_CNT_FIELD_OFFSET, DMA_IP_CH_PROG_SEQ_CTRL_PS_CNT_FIELD_SIZE);
}
/** *****************************************************************************************************
 * \brief This function service to read register value.
 *
 * \verbatim
 * Syntax             : uint32 Dma_Ip_ReadChannelRegister
 *                      (
 *                          uint32 dmaBaseAddress
 *                          uint32 channelId
 *                          uint32 regOffset
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : dmabaseAddress - Dma controller base address.
 *                      channelId      - Numeric identifier of the DMA channel.
 *                      regOffset      - Register address offset.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Return current register value.
 *
 * Description        : This function service to read register value.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
DMA_LOCAL uint32 Dma_Ip_ReadChannelRegister(uint32 dmaBaseAddress, uint32 channelId,
        uint32 regOffset)
{
    /* ----- Implementation ----------------------------------------------- */
    /* #10 General-purpose read register functions. */
    return readl(regOffset + DMA_IP_CHANNEL_BASE(dmaBaseAddress, channelId));
}
/** *****************************************************************************************************
 * \brief This function service to read register value with bits.
 *
 * \verbatim
 * Syntax             : uint32 Dma_Ip_ReadChannelRegisterBits
 *                      (
 *                          uint32 dmaBaseAddress
 *                          uint32 channelId
 *                          uint32 regOffset
 *                          uint32 offset
 *                          uint32 size
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : dmabaseAddress - Dma controller base address.
 *                      channelId      - Numeric identifier of the DMA channel.
 *                      regOffset      - Register address offset.
 *                      offset         - Bit offset.
 *                      size           - Bit size.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Return current register value.
 *
 * Description        : This function service to read register value with bits.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
DMA_LOCAL uint32 Dma_Ip_ReadChannelRegisterBits(uint32 dmaBaseAddress, uint32 channelId,
        uint32 regOffset, uint8 offset, uint8 size)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint32 regValue;

    /* ----- Implementation ----------------------------------------------- */
    /* #10 General-purpose read register functions with bit(s) offset. */
    regValue = Dma_Ip_ReadChannelRegister(dmaBaseAddress, channelId, regOffset);

    return ((regValue >> offset) & DMA_BIT_MASK(size));
}
/** *****************************************************************************************************
 * \brief This function service to write register value.
 *
 * \verbatim
 * Syntax             : void Dma_Ip_WriteChannelRegister
 *                      (
 *                          uint32 dmaBaseAddress
 *                          uint32 channelId
 *                          uint32 value
 *                          uint32 regOffset
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : dmabaseAddress - Dma controller base address.
 *                      channelId      - Numeric identifier of the DMA channel.
 *                      value          - Values need to be written to registers.
 *                      regOffset      - Register address offset.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Return current register value.
 *
 * Description        : This function service to write register value.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
DMA_LOCAL void Dma_Ip_WriteChannelRegister(uint32 dmaBaseAddress, uint32 channelId, uint32 value,
        uint32 regOffset)
{
    /* ----- Implementation ----------------------------------------------- */
    /* #10 General-purpose write register functions. */
    writel(value, regOffset + DMA_IP_CHANNEL_BASE(dmaBaseAddress, channelId));
}
/** *****************************************************************************************************
 * \brief This function service to write register value with bits.
 *
 * \verbatim
 * Syntax             : void Dma_Ip_WriteChannelRegisterBits
 *                      (
 *                          uint32 dmaBaseAddress
 *                          uint32 channelId
 *                          uint32 regOffset
 *                          uint32 offset
 *                          uint32 size
 *                          uint32 value
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : dmabaseAddress - Dma controller base address.
 *                      channelId      - Numeric identifier of the DMA channel.
 *                      regOffset      - Register address offset.
 *                      offset         - Bit offset.
 *                      size           - Bit size.
 *                      uint32 value   - Values need to be written to registers.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Return current register value.
 *
 * Description        : This function service to write register value with bits.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
DMA_LOCAL void Dma_Ip_WriteChannelRegisterBits(uint32 dmaBaseAddress, uint32 channelId,
        uint32 regOffset,  uint32 offset, uint32 size, uint32 value)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint32 regValue = Dma_Ip_ReadChannelRegister(dmaBaseAddress, channelId, regOffset);

    /* ----- Implementation ----------------------------------------------- */
    /* #10 General-purpose write register functions with bit(s) offset. */
    regValue &= ~(DMA_BIT_MASK(size) << offset);
    regValue |= (value << offset);

    /* #20 Write value to register. */
    Dma_Ip_WriteChannelRegister(dmaBaseAddress, channelId, regValue, regOffset);
}
#define DMA_STOP_SEC_CODE
#include "Dma_MemMap.h"

#ifdef __cplusplus
}
#endif
/* End of file */
