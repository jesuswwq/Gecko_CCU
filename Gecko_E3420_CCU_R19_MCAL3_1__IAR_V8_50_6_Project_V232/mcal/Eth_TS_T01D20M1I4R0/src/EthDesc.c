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
 * @file  EthDesc.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Eth plugins.
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "EthDesc.h"
#include "Std_Types.h"
#include "mini_libc.h"

#define ETH_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Eth_MemMap.h"

VAR(locked_desc_ring_t, ETH_VAR)        Eth_Buf_Confirm\
[ETH_MAXCTRLS_SUPPORTED]\
[ETH_MAX_DMA_CHANNEL][DESC_TYPE_MAX];

#define ETH_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Eth_MemMap.h"

#if (ETH_NO_CACHEABLE_NEEDED == STD_ON)
#define ETH_START_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#else
#define ETH_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#include "Eth_MemMap.h"
VAR_ALIGN(dma_desc_ring_t Eth_Desc_Buf \
          [ETH_MAXCTRLS_SUPPORTED]\
          [ETH_MAX_DMA_CHANNEL][DESC_TYPE_MAX], \
          CACHE_LINE);

#if (ETH_NO_CACHEABLE_NEEDED == STD_ON)
#define ETH_STOP_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#else
#define ETH_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"

/**
 * @description:
 * @param {ring_t} *ring
 * @param {uint32} sizepower
 * @return {*}
 */
static void ring_clr(ring_t *ring, uint32 sizepower)
{
    ring->size = (0x00000001 << sizepower);
    ring->front = ring->rear = 0;
}
/**
 * @description:
 * @param {ring_t} *ring
 * @return {*}
 */
static uint32 ring_remain(ring_t *ring)
{
    return (uint32)(ring->size + ring->front - ring->rear);
}
/**
 * @description:
 * @param {ring_t} *ring
 * @return {*}
 */
static uint32 ring_used(ring_t *ring)
{
    return (uint32)(ring->rear - ring->front);
}
/**
 * @description:
 * @param {ring_t} *ring
 * @return {*}
 */
static sint32 ring_get_next_index(ring_t *ring)
{
    if (ring_used(ring)) {
        return (uint32)(ring->front % ring->size);
    }

    return -1;
}
/*
    DMA DESC ring apis wrapper
*/
/**
 * @description:
 * @param {uint8} CtrlIdx
 * @return {*}
 */
static void desc_ring_clr(uint8 CtrlIdx)
{
    ring_t *ring;
    dma_desc_ring_t *desc_ring;

    /*PRQA S 2877 2*/
    for (uint8 ch = 0; ch < ETH_MAX_DMA_CHANNEL; ch++) {

        desc_ring = &Eth_Desc_Buf[CtrlIdx][ch][DESC_TX];
        // do this to not rely on c evn clean bss and clean cache.
        mini_memclr_s(desc_ring->desc,sizeof(desc_ring->desc));
#if (ETH_NO_CACHEABLE_NEEDED == STD_OFF)
        arch_clean_cache_range(desc_ring->desc,sizeof(desc_ring->desc));
#endif
        ring = &desc_ring->ringcb;
        ring_clr(ring, MAX_RING_SIZE_POWER);


        desc_ring = &Eth_Desc_Buf[CtrlIdx][ch][DESC_RX];
        // do this to not rely on c evn clean bss and clean cache.
        mini_memclr_s(desc_ring->desc,sizeof(desc_ring->desc));
#if (ETH_NO_CACHEABLE_NEEDED == STD_OFF)
        arch_clean_cache_range(desc_ring->desc,sizeof(desc_ring->desc));
#endif
        ring = &desc_ring->ringcb;
        ring_clr(ring, MAX_RING_SIZE_POWER);
    }
}
/**
 * @description:
 * @param {dma_desc_ring_t} *desc_ring
 * @param {sint32} cnt
 * @return {*}
 */
static struct dma_desc *dma_desc_ring_alloc(dma_desc_ring_t *desc_ring, uint32 cnt)
{

    ring_t *ring = &desc_ring->ringcb;

    struct dma_desc  *tdesc = (struct dma_desc *)0;
    /* Lock first */

    SchM_Enter_Eth_ETH_EXCLUSIVE_AREA_00();

    if (ring_remain(ring) < cnt) {
        tdesc = NULL_PTR;
    } else {
        tdesc = &desc_ring->desc[ring->rear % ring->size];
        ring->rear += cnt;
    }

    SchM_Exit_Eth_ETH_EXCLUSIVE_AREA_00();

    return tdesc;
}
/**
 * @description:
 * @param {dma_desc_ring_t} *desc_ring
 * @param {sint32} cnt
 * @return {*}
 */
static sint32 dma_desc_ring_free(dma_desc_ring_t *desc_ring, uint32 cnt)
{
    sint32 ret = 0;
    ring_t *ring = &desc_ring->ringcb;
    /* Lock first */

    SchM_Enter_Eth_ETH_EXCLUSIVE_AREA_00();

    if (ring_used(ring) < cnt) {
        ret = -1;
    } else {
        ring->front += cnt;
    }

    SchM_Exit_Eth_ETH_EXCLUSIVE_AREA_00();

    return ret;
}
/**
 * @description: touch special desc
 * @param {dma_desc_ring_t} *desc_ring
 * @param {uint32} index
 * @return {*}
 */
static struct dma_desc *dma_desc_ring_touch(dma_desc_ring_t *desc_ring, uint32 index)
{
    ring_t *ring;
    struct dma_desc *desc;

    ring = &desc_ring->ringcb;

    if (index > ring->size) {
        desc = (struct dma_desc *)0;
    }

    desc = &desc_ring->desc[index];
    return desc;
}
/*
    DMA DESC ring apis end
*/

/*
    DMA DESC locked ring apis wrapper
*/
/**
 * @description:
 * @param {uint8} CtrlIdx
 * @return {*}
 */
static void locked_desc_clr(uint8 CtrlIdx)
{
    ring_t *ring;
    locked_desc_ring_t *locked_ring;

    /*PRQA S 2877 2*/
    for (uint8 ch = 0; ch < ETH_MAX_DMA_CHANNEL; ch++) {

        locked_ring = &Eth_Buf_Confirm[CtrlIdx][ch][DESC_RX];
        ring = &locked_ring->ringcb;
        ring_clr(ring, MAX_RING_SIZE_POWER);

        locked_ring = &Eth_Buf_Confirm[CtrlIdx][ch][DESC_TX];
        ring = &locked_ring->ringcb;
        ring_clr(ring, MAX_RING_SIZE_POWER);
    }
}
/**
 * @description:
 * @param {locked_desc_ring_t} *desc_ring
 * @param {sint32} cnt
 * @return {*}
 */
static locked_desc_t *locked_desc_ring_alloc(locked_desc_ring_t *desc_ring, uint32 cnt)
{

    ring_t *ring;
    locked_desc_t *locked;
    ring = &desc_ring->ringcb;

    if (ring_remain(ring) < cnt) {
        locked = (locked_desc_t *)0;
    } else {
        locked = &desc_ring->array[ring->rear % ring->size];
        ring->rear += cnt;
    }

    return locked;
}
/**
 * @description:
 * @param {*}
 * @return {*}
 */
static locked_desc_t *locked_desc_ring_free(locked_desc_ring_t *desc_ring, \
        uint32 cnt)
{

    ring_t *ring;
    locked_desc_t *locked;
    ring = &desc_ring->ringcb;

    SchM_Enter_Eth_ETH_EXCLUSIVE_AREA_02();

    if (ring_used(ring) < cnt) {
        locked = (locked_desc_t *)0;
    } else {
        locked = &desc_ring->array[ring->front % ring->size];
        ring->front += cnt;
    }

    SchM_Exit_Eth_ETH_EXCLUSIVE_AREA_02();

    return locked;
}
/**
 * @description:
 * @param {*}
 * @return {*}
 */
static locked_desc_t *locked_desc_ring_touch(locked_desc_ring_t *desc_ring)
{
    sint32 index;
    locked_desc_t *locked;
    index = ring_get_next_index(&desc_ring->ringcb);

    if (index != -1) {
        locked = &desc_ring->array[index];
    } else {
        locked = (locked_desc_t *)0;
    }

    return locked;
}
/*
    DMA DESC locked ring apis wrapper end
*/

/*
    exported api
*/
/**
 * @description: desc ring init
 * @param {uint8} CtrlIdx
 * @return {*}
 */
void desc_ring_init(uint8 CtrlIdx)
{
    desc_ring_clr(CtrlIdx);
    locked_desc_clr(CtrlIdx);
}
/**
 * @description:alloc dma desc
 * @param {uint8} CtrlIdx
 * @param {boolean} rx
 * @return {*}
 */
struct dma_desc *alloc_dma_desc(uint8 CtrlIdx, uint8 channel, boolean rx)
{
    dma_desc_ring_t *desc_ring;

    if (rx) {
        desc_ring = &Eth_Desc_Buf[CtrlIdx][channel][DESC_RX];
    } else {
        desc_ring = &Eth_Desc_Buf[CtrlIdx][channel][DESC_TX];
    }

    return dma_desc_ring_alloc(desc_ring, 1);
}
/**
 * @description:free dma desc
 * @param {uint8} CtrlIdx
 * @param {boolean} rx
 * @return {*}
 */
sint32 free_dma_desc(uint8 CtrlIdx, uint8 channel, boolean rx)
{
    dma_desc_ring_t *desc_ring;

    if (rx) {
        desc_ring = &Eth_Desc_Buf[CtrlIdx][channel][DESC_RX];
    } else {
        desc_ring = &Eth_Desc_Buf[CtrlIdx][channel][DESC_TX];
    }

    return dma_desc_ring_free(desc_ring, 1);
}
/**
 * @description: get specify desc buf addr
 * @param {uint8} CtrlIdx
 * @param {uint16} index
 * @param {boolean} rx
 * @return {*}
 */
struct dma_desc *dma_desc_touch(uint8 CtrlIdx, uint8 channel,
                                uint16 index, boolean rx)
{

    dma_desc_ring_t *desc_ring;

    if (rx) {
        desc_ring = &Eth_Desc_Buf[CtrlIdx][channel][DESC_RX];
    } else {
        desc_ring = &Eth_Desc_Buf[CtrlIdx][channel][DESC_TX];
    }

    return dma_desc_ring_touch(desc_ring, index);
}
/**
 * @description:push an item
 * @param {uint8} CtrlIdx
 * @param {locked_desc_t} *descp
 * @param {boolean} rx
 * @return {*}
 */
sint32 locked_desc_put(uint8 CtrlIdx, uint8 channel,
                       locked_desc_t *descp, boolean rx)
{
    locked_desc_t *locked;
    locked_desc_ring_t *locked_ring;

    if (rx) {
        locked_ring = &Eth_Buf_Confirm[CtrlIdx][channel][DESC_RX];
    } else {
        locked_ring = &Eth_Buf_Confirm[CtrlIdx][channel][DESC_TX];
    }

    SchM_Enter_Eth_ETH_EXCLUSIVE_AREA_02();
    locked = locked_desc_ring_alloc(locked_ring, 1);

    if (locked) {
        locked->desc = descp->desc;
        locked->buf_idx = descp->buf_idx;
        locked->confirm = descp->confirm;
        SchM_Exit_Eth_ETH_EXCLUSIVE_AREA_02();
        return 0;
    }

    SchM_Exit_Eth_ETH_EXCLUSIVE_AREA_02();

    return -1;
}
/**
 * @description:pop an item
 * @param {uint8} CtrlIdx
 * @param {locked_desc_t} *
 * @param {boolean} rx
 * @return {*}
 */
sint32 locked_desc_get(uint8 CtrlIdx, uint8 channel,
                       locked_desc_t **descpp, boolean rx)
{
    locked_desc_t *locked;
    locked_desc_ring_t *locked_ring;

    if (rx) {
        locked_ring = &Eth_Buf_Confirm[CtrlIdx][channel][DESC_RX];
    } else {
        locked_ring = &Eth_Buf_Confirm[CtrlIdx][channel][DESC_TX];
    }

    locked = locked_desc_ring_free(locked_ring, 1);

    if (locked) {
        *descpp = locked;
        return 0;
    }

    return -1;
}
/**
 * @description:get specify desc buf addr
 * @param {uint8} CtrlIdx
 * @param {locked_desc_t} *
 * @param {uint16} index
 * @param {boolean} rx
 * @return {*}
 */
sint32 locked_desc_touch(uint8 CtrlIdx, uint8 channel,
                         locked_desc_t **descpp, boolean rx)
{
    locked_desc_t *locked;
    locked_desc_ring_t *locked_ring;

    if (rx) {
        locked_ring = &Eth_Buf_Confirm[CtrlIdx][channel][DESC_RX];
    } else {
        locked_ring = &Eth_Buf_Confirm[CtrlIdx][channel][DESC_TX];
    }

    locked = locked_desc_ring_touch(locked_ring);

    if (locked) {
        *descpp = locked;
        return 0;
    }

    return -1;
}
/**
 * @description:get specify desc buf addr from desc idx
 * @param {uint8} CtrlIdx
 * @param {uint32} index
 * @param {boolean} is_rx
 * @return {*dma_desc}
 */
struct dma_desc *get_dma_desc(uint8 CtrlIdx,
                              uint8 channel, uint32 curidx, boolean rx)
{
    dma_desc_ring_t *ring;

    if (rx) {
        ring = &Eth_Desc_Buf[CtrlIdx][channel][DESC_RX];
    } else {
        ring = &Eth_Desc_Buf[CtrlIdx][channel][DESC_TX];
    }

    return &ring->desc[curidx];
}
/**
 * @description:get specify desc next desc buf addr from desc idx
 * @param {uint8} CtrlIdx
 * @param {uint32} index
 * @param {boolean} is_rx
 * @return {*dma_desc}
 */
struct dma_desc *get_dma_desc_next(uint8 CtrlIdx,
                                   uint8 channel, uint32 curidx, boolean rx)
{
    uint32 next = curidx + 1;
    dma_desc_ring_t *ring;

    if (rx) {
        ring = &Eth_Desc_Buf[CtrlIdx][channel][DESC_RX];
    } else {
        ring = &Eth_Desc_Buf[CtrlIdx][channel][DESC_TX];
    }

    if (next >= MAX_ETH_RING_LENTH) {
        next = 0;
    }

    return &ring->desc[next];
}
/*
    exported api end
*/

#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#ifdef __cplusplus
}
#endif
