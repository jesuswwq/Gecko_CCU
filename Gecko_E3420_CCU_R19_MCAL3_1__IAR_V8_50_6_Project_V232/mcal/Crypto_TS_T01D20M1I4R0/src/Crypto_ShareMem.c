/*
 * SEMIDRIVE Copyright Statement
 * Copyright (c) SEMIDRIVE. All rights reserved
 *
 * This software and all rights therein are owned by SEMIDRIVE, and are
 * protected by copyright law and other relevant laws, regulations and
 * protection. Without SEMIDRIVE's prior written consent and/or related rights,
 * please do not use this software or any potion thereof in any form or by any
 * means. You may not reproduce, modify or distribute this software except in
 * compliance with the License. Unless required by applicable law or agreed to
 * in writing, software distributed under the License is distributed on
 * an "AS IS" basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.
 *
 * You should have received a copy of the License along with this program.
 * If not, see <http://www.semidrive.com/licenses/>.
 */

/**
 * @file  Crypto_ShareMem.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Crypto
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Crypto_ShareMem.h"
#include "Crypto_Hsm.h"
#include "SchM_Crypto.h"
#include "cdefs.h"

#define CE_MEM_NODE_ITEM_NUM_MAX        10
#define CRYPTO_offsetof(TYPE, MEMBER)   ((unsigned int)&((TYPE *)0)->MEMBER)

#define to_mem_node(priv) container_of((priv), struct mem_node, ptr)

/**
 * container_of - cast a member of a structure out to the containing structure
 * @ptr:	the pointer to the member.
 * @type:	the type of the container struct this is embedded in.
 * @member:	the name of the member within the struct.
 *
 */
#define container_of(ptr, type, member) ({          \
  	 void *__mptr = (void *)(ptr);                  \
  	((type *)(__mptr - CRYPTO_offsetof(type, member))); })

struct mem_node {
    uint32 size;
    uint8 is_used;
    uint8 *ptr;
};

struct hsm_heap {
    uint8 item_num;
    uint8 used_num;
    uint8 used_num_max;
    struct mem_node *mem_node_list;
};

#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_ON)
#define CRYPTO_START_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#else
#define CRYPTO_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_ON) */
#include "Crypto_MemMap.h"

uint8 __attribute__((aligned(CACHE_LINE))) update_buff[ROUNDUP(CRYPTO_SHARE_MEM_NODE_DIG_MAX, CACHE_LINE)];
uint8 __attribute__((aligned(CACHE_LINE))) msg_padding[ROUNDUP(CRYPTO_SHARE_MEM_NODE_RSA_MAX, CACHE_LINE)];
uint8 __attribute__((aligned(CACHE_LINE))) rev_cpy_buf[ROUNDUP(CRYPTO_SHARE_MEM_NODE_RSA_MAX, CACHE_LINE)];
uint8 __attribute__((aligned(CACHE_LINE))) msg_padding_ext[ROUNDUP(CRYPTO_SHARE_MEM_NODE_RSA_MAX_EXT, CACHE_LINE)];
uint8 __attribute__((aligned(CACHE_LINE))) dbMask[ROUNDUP(CRYPTO_SHARE_MEM_NODE_RSA_MAX, CACHE_LINE)];
uint8 __attribute__((aligned(CACHE_LINE))) hash[ROUNDUP(CRYPTO_SHARE_MEM_NODE_DIG_MAX, CACHE_LINE)];
uint8 __attribute__((aligned(CACHE_LINE))) hash_padding[ROUNDUP(CRYPTO_SHARE_MEM_NODE_HASH_PAD_MAX, CACHE_LINE)];
uint8 __attribute__((aligned(CACHE_LINE))) comm_buff[ROUNDUP(CRYPTO_SHARE_MEM_NODE_COMM_BUFF_MAX, CACHE_LINE)];
uint8 __attribute__((aligned(CACHE_LINE))) comm_small_buff[ROUNDUP(CRYPTO_SHARE_MEM_NODE_COMM_SMALL_BUFF_MAX, CACHE_LINE)];
uint8 __attribute__((aligned(CACHE_LINE))) cmd_mac_buff[ROUNDUP(CRYPTO_SHARE_MEM_NODE_COMM_SMALL_BUFF_MAX, CACHE_LINE)];

#if (CRYPTO_NO_CACHEABLE_NEEDED == STD_ON)
#define CRYPTO_STOP_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#else
#define CRYPTO_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif /** #if (CRYPTO_NO_CACHEABLE_NEEDED == STD_ON) */
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_VAR_INIT_UNSPECIFIED
#include "Crypto_MemMap.h"

struct mem_node mem_node_vlaue[CE_MEM_NODE_ITEM_NUM_MAX]={
    {
        .size = CRYPTO_SHARE_MEM_NODE_DIG_MAX,
        .is_used = 0,
        .ptr = hash,
    },
    {
        .size = CRYPTO_SHARE_MEM_NODE_DIG_MAX,
        .is_used = 0,
        .ptr = update_buff,
    },
    {
        .size = CRYPTO_SHARE_MEM_NODE_COMM_SMALL_BUFF_MAX,
        .is_used = 0,
        .ptr = comm_small_buff,
    },
    {
        .size = CRYPTO_SHARE_MEM_NODE_COMM_SMALL_BUFF_MAX,
        .is_used = 0,
        .ptr = cmd_mac_buff,
    },
    {
        .size = CRYPTO_SHARE_MEM_NODE_HASH_PAD_MAX,
        .is_used = 0,
        .ptr = hash_padding,
    },
    {
        .size = CRYPTO_SHARE_MEM_NODE_RSA_MAX,
        .is_used = 0,
        .ptr = msg_padding,
    },
    {
        .size = CRYPTO_SHARE_MEM_NODE_RSA_MAX,
        .is_used = 0,
        .ptr = dbMask,
    },
    {
        .size = CRYPTO_SHARE_MEM_NODE_RSA_MAX,
        .is_used = 0,
        .ptr = rev_cpy_buf,
    },
    {
        .size = CRYPTO_SHARE_MEM_NODE_RSA_MAX_EXT,
        .is_used = 0,
        .ptr = msg_padding_ext,
    },
    {
        .size = CRYPTO_SHARE_MEM_NODE_COMM_BUFF_MAX,
        .is_used = 0,
        .ptr = comm_buff,
    },
};

/* hsm_heap static vars */
static struct hsm_heap inheap = {
    .item_num = CE_MEM_NODE_ITEM_NUM_MAX,
    .used_num = 0,
    .used_num_max = 0,
    .mem_node_list = &mem_node_vlaue[0],
};

#define CRYPTO_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"

Std_ReturnType ShareMem_Init(void)
{
    Std_ReturnType RetVal = E_OK;

    return RetVal;
}

uint8 * ShareMem_GetBlock(uint32 size)
{
    uint8 i = 0;
    struct mem_node *return_node = NULL;

    SchM_Enter_Crypto_CRYPTO_EXCLUSIVE_AREA_00();

    for (i = 0; i < inheap.item_num; i++) {
        if ((inheap.mem_node_list[i].size >= size) &&
            (inheap.mem_node_list[i].is_used == 0)) {
            inheap.mem_node_list[i].is_used = 1;
            inheap.used_num++;

            if (inheap.used_num > inheap.used_num_max) {
                inheap.used_num_max = inheap.used_num;
            }

            return_node = &(inheap.mem_node_list[i]);
            break;
        }
    }

    SchM_Exit_Crypto_CRYPTO_EXCLUSIVE_AREA_00();

    if (return_node != NULL){
        return return_node->ptr;
    }

    return NULL;
}

uint8 ShareMem_ReleaseBlock(uint8 *ptr)
{
    uint8 i = 0;
    uint8 RetVal = E_NOT_OK;

    SchM_Enter_Crypto_CRYPTO_EXCLUSIVE_AREA_00();
    if(ptr != NULL){
        for (i = 0; i < inheap.item_num; i++) {
            if ((inheap.mem_node_list[i].ptr == ptr) &&
                (inheap.mem_node_list[i].is_used == 1)) {
                inheap.mem_node_list[i].is_used = 0;
                inheap.used_num--;
                RetVal = E_OK;
                break;
            }
        }
    }
    SchM_Exit_Crypto_CRYPTO_EXCLUSIVE_AREA_00();
    return RetVal;
}

#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#ifdef __cplusplus
}
#endif
