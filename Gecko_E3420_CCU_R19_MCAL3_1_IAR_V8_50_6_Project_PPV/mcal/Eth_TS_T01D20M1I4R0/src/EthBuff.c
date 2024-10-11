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
 * @file  EthBuff.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Eth plugins.
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Eth.h"
#include "EthBuff.h"

#define  BYTE_BITS  (8U)

#ifndef  CTRL1_RX_BUFF_COUNT
#define  CTRL1_RX_BUFF_COUNT 0U
#endif
#ifndef  CTRL1_TX_BUFF_COUNT
#define  CTRL1_TX_BUFF_COUNT 0U
#endif
#ifndef  CTRL1_RX_BUFF_SIZE
#define  CTRL1_RX_BUFF_SIZE  0U
#endif
#ifndef  CTRL1_TX_BUFF_SIZE
#define  CTRL1_TX_BUFF_SIZE  0U
#endif

/* get max tx buff cnt */
#if CTRL0_TX_BUFF_COUNT > CTRL1_TX_BUFF_COUNT
#define CTRL_TX_BUFF_MAX CTRL0_TX_BUFF_COUNT
#else
#define CTRL_TX_BUFF_MAX CTRL1_TX_BUFF_COUNT
#endif
/* get max rx buff cnt */
#if CTRL0_RX_BUFF_COUNT > CTRL1_RX_BUFF_COUNT
#define CTRL_RX_BUFF_MAX CTRL0_RX_BUFF_COUNT
#else
#define CTRL_RX_BUFF_MAX CTRL1_RX_BUFF_COUNT
#endif
/* get max rx buff cnt */
#if CTRL_RX_BUFF_MAX > CTRL_TX_BUFF_MAX
#define CTRL_BUFF_MAX CTRL_RX_BUFF_MAX
#else
#define CTRL_BUFF_MAX CTRL_TX_BUFF_MAX
#endif
/* Make sure the structure size is not less than 32 bytes  */
#if ((CTRL_BUFF_MAX/BYTE_BITS) < 16U)
#define  FIFO_SUM_CNT_MAX   16U
#else
#define  FIFO_SUM_CNT_MAX   (CTRL_BUFF_MAX/BYTE_BITS)
#endif
/* Max retry times */
#define  FIFO_RETRY_MAX   3
typedef struct {
    uint8  membuf_state;
    uint8  membuf_bits[DIR_MAX][FIFO_SUM_CNT_MAX];
} __attribute__((aligned(CACHE_LINE))) MemBufM_t ;

#define ETH_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Eth_MemMap.h"

static MemBufM_t MemBufM[ETH_MAXCTRLS_SUPPORTED];

#define ETH_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Eth_MemMap.h"

#if (ETH_NO_CACHEABLE_NEEDED == STD_ON)
#define ETH_START_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#else
#define ETH_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#include "Eth_MemMap.h"

VAR_ALIGN(volatile uint8 membuf0[CTRL0_TX_BUFF_SIZE + CTRL0_RX_BUFF_SIZE], \
          CACHE_LINE);

#if (ETH_MAXCTRLS_SUPPORTED == 2)
VAR_ALIGN(volatile uint8 membuf1[CTRL1_TX_BUFF_SIZE + CTRL1_RX_BUFF_SIZE], \
          CACHE_LINE);
#endif

#if (ETH_NO_CACHEABLE_NEEDED == STD_ON)
#define ETH_STOP_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#else
#define ETH_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#include "Eth_MemMap.h"

#define ETH_START_SEC_CONST_UNSPECIFIED
#include "Eth_MemMap.h"

static uint8 volatile *const membufp[ETH_MAXCTRLS_SUPPORTED] = \
{
    &membuf0[0]
#if (ETH_MAXCTRLS_SUPPORTED == 2)
    , &membuf1[0]
#endif
};

#define ETH_STOP_SEC_CONST_UNSPECIFIED
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"

/**
 * @description:Calculate the total number of buf
 * @param {uint8} CtrlIdx
 * @param {boolean} rx
 * @return {*}
 */
uint32 cacul_buf_cnt(uint8 CtrlIdx, boolean rx)
{
    uint32 buf_cnt;

    if (CtrlIdx == 0) {
        if (rx) {
            buf_cnt = CTRL0_RX_BUFF_COUNT;
        } else {
            buf_cnt = CTRL0_TX_BUFF_COUNT;
        }
    } else {
        if (rx) {
            buf_cnt = CTRL1_RX_BUFF_COUNT;
        } else {
            buf_cnt = CTRL1_TX_BUFF_COUNT;
        }
    }

    return buf_cnt;
}
/**
 * @description:Calculate the total number of buf btyes
 * @param {uint8} CtrlIdx
 * @param {boolean} rx
 * @return {*}
 */
static inline uint32 cacul_buf_byte_cnt(uint8 CtrlIdx, boolean rx)
{
    uint32 btyes_cnt;

    if (CtrlIdx == 0) {
        if (rx) {
            btyes_cnt = CTRL0_RX_BUFF_SIZE;
        } else {
            btyes_cnt = CTRL0_TX_BUFF_SIZE;
        }
    } else {
        if (rx) {
            btyes_cnt = CTRL1_RX_BUFF_SIZE;
        } else {
            btyes_cnt = CTRL1_TX_BUFF_SIZE;
        }
    }

    return btyes_cnt;
}

#if (defined(DEBUG_ENABLE) && defined(DEBUG_BUFF))
/**
 * @description:
 * @param {uint8} CtrlIdx
 * @param {boolean} rx
 * @return {*}
 */
static void show_status(uint8 CtrlIdx, boolean rx)
{
    MemBufM_t *BufM = &MemBufM[CtrlIdx];
    uint32 type = rx ? DIR_RX : DIR_TX;
    uint32 bits_sum = cacul_buf_cnt(CtrlIdx, TRUE);
    DBG("sunbufitcnt %d\n", bits_sum);

    for (int de = 0; de < FIFO_SUM_CNT_MAX; de++) {
        DBG("%02x ", BufM->membuf_bits[type][de]);
    }

    DBG("\n");
}
#endif
/**
 * @description:Calculate the part before the specified fifo idx the total number bytes
 * @param {uint8} CtrlIdx
 * @param {uint8} fifoNumber
 * @param {boolean} rx
 * @return {*}
 */
static inline uint32 cacul_buf_byte_cnt_limit(uint8 CtrlIdx, uint8 fifoNumber, boolean rx)
{
    uint32 buf_cnt = 0;
    const Eth_CntrlConfigType *cfg = ETH_CFG_CTRL_PARM_PTR(CtrlIdx);
    const Eth_CtrlConfigFifoType *FifoParam;

    if (!cfg) {
        return 0;
    }

    if (rx) {
        FifoParam =  cfg->IngressFifoConfig;
    } else {
        FifoParam =  cfg->EgressFifoConfig;
    }

    for (uint16 loop = 0; loop < fifoNumber; loop++) {
        buf_cnt += FifoParam[loop].FifoBufTotal * FifoParam[loop].FifoBufLenByte;
    }

    return buf_cnt;
}
/**
 * @description:check special fifo have free space
 * @param {uint8} CtrlIdx
 * @param {const Eth_CtrlConfigFifoType} *fifoarray
 * @param {uint8} FifiIdx
 * @param {boolean} rx
 * @return {*}
 */
static uint32 fifo_have_free(uint8 CtrlIdx, const Eth_CtrlConfigFifoType *fifoarray\
                             , uint8 FifiIdx, boolean rx)
{
    uint8 part_bits;
    MemBufM_t *BufM = &MemBufM[CtrlIdx];
    uint16 loop, whole_byte = 0;
    uint32 bits_cnt = 0;
    uint32 type = rx ? DIR_RX : DIR_TX;

    if (!fifoarray) {
        return 0;
    }

    for (loop = 0; loop < FifiIdx; loop++) {
        bits_cnt += fifoarray[loop].FifoBufTotal;
    }

    /* The first fifo may be negative here*/
    if (bits_cnt) {
        whole_byte = (bits_cnt - 1) / BYTE_BITS;
    }

    part_bits = bits_cnt % BYTE_BITS;

    /*
        If part_bits is 0 and FifiIdx is not 0 ,
        the byte idx points to the bit position of the previous buf.
    */
    if (!part_bits && bits_cnt) {
        whole_byte++;
    }

    for (loop = 0; loop < fifoarray[FifiIdx].FifoBufTotal; loop++) {
        /*
           When the sum of the previous buf cnt is aligned,
           bytes idx has already been +1 at line 155. so Exclude loop==0
           and add 1 for every 8bits.
        */
        if (loop && (!((loop + part_bits) % BYTE_BITS))) {
            whole_byte++;
        }

        if (BufM->membuf_bits[type][whole_byte] &\
            (0x01 << ((part_bits + loop) % BYTE_BITS))) {
            return 1;
        }
    }

    return 0;
}
/**
 * @description:
 * @param {uint8} CtrlIdx
 * @param {const Eth_CtrlConfigFifoType*} fifoarray
 * @param {uint8} fifoidx
 * @param {boolean} rx
 * @return {*}
 */
static sint32 lock_bufmem(uint8 CtrlIdx, const Eth_CtrlConfigFifoType *fifoarray, sint16 fifoidx,
                          boolean rx)
{

    uint8 part_bits;
    uint16 loop, whole_byte = 0;
    uint32 bits_cnt = 0;
    uint32 type = rx ? DIR_RX : DIR_TX;
    MemBufM_t *BufM = &MemBufM[CtrlIdx];

    if (!fifoarray) {
        return 0;
    }

    /*
        Calculate the number of bufs before the current fifo
    */
    for (loop = 0; loop < fifoidx; loop++) {
        bits_cnt += fifoarray[loop].FifoBufTotal;
    }

    if (bits_cnt) {
        whole_byte = (bits_cnt - 1) / BYTE_BITS;
    }

    part_bits = bits_cnt % BYTE_BITS;

    /*
        If part_bits is 0 and FifiIdx is not 0 ,
        the byte idx points to the bit position of the previous buf.
    */
    if (!part_bits && bits_cnt) {
        whole_byte++;
    }

    for (loop = 0; loop < fifoarray[fifoidx].FifoBufTotal; loop++) {
        /*
           When the sum of the previous buf cnt is aligned,
           bytes idx has already been +1 at line 155. so Exclude loop==0
           and add 1 for every 8bits.
        */
        if (loop && (!((loop + part_bits) % BYTE_BITS))) {
            whole_byte++;
        }

        SchM_Enter_Eth_ETH_EXCLUSIVE_AREA_03();

        if (BufM->membuf_bits[type][whole_byte] &\
            (0x01 << ((part_bits + loop) % BYTE_BITS))) {
            // lock
            BufM->membuf_bits[type][whole_byte] \
            &= (~((0x01 << ((part_bits + loop) % BYTE_BITS))));
            SchM_Exit_Eth_ETH_EXCLUSIVE_AREA_03();
            return loop;
        }

        SchM_Exit_Eth_ETH_EXCLUSIVE_AREA_03();
    }

    return -1;
}
/**
 *
 * @description:
 * @param {uint8} CtrlIdx
 * @param {uint16} len
 * @param {boolean} rx
 * @return {*}
 */
static sint16 search_up(uint8 CtrlIdx, const Eth_CtrlConfigFifoType *fifoarray, \
                        uint8 fifocnt, uint16 *len, boolean rx, sint16 *search_down_start_index)
{
    if (!fifoarray || !len) {
        return 0;
    }

    /*
        In Eth_PBCfg.c the fifo is Sorted by size,so the larger the
        index, the larger the buf size
    */
    for (uint16 idx = 0; idx < fifocnt; idx++) {
        if (fifoarray[idx].FifoBufLenByte >= *len) {
            if (*search_down_start_index == -1) {
                /* Save the previous starting fifo type idx of
                    the upward search as the upper limit of the downward search
                */
                if (idx)
                    *search_down_start_index = idx;
            }

            if (fifo_have_free(CtrlIdx, fifoarray, idx, rx)) {
                *len = fifoarray[idx].FifoBufLenByte;
                return idx;
            } else {
                continue;
            }
        }
    }

    /* search_up fail */
    return -1;
}
/**
 * @description:
 * @param {*}
 * @return {*}
 */
static sint16 search_down(uint8 CtrlIdx, const Eth_CtrlConfigFifoType *fifoarray, \
                          uint8 fifoidx, uint16 *len, boolean rx)
{
    if (!fifoarray || !len) {
        return 0;
    }

    /*
        In Eth_PBCfg.c the fifo is Sorted by size,so the larger the
        index, the larger the buf size
    */
    for (sint16 Idx = fifoidx; Idx >= 0; Idx--) {
        if (fifoarray[Idx].FifoBufLenByte < *len) {
            if (fifo_have_free(CtrlIdx, fifoarray, Idx, rx)) {
                *len = fifoarray[Idx].FifoBufLenByte;
                return Idx;
            }
        }
    }

    /* no buf available */
    *len = 0;
    return -1;
}
/**
 * @description:
 * @param {uint8} CtrlIdx
 * @param {uint16} len
 * @param {boolean} rx
 * @return {*}
 */
static sint32 unlock_bufmem(uint8 CtrlIdx, uint16 bufidx, boolean rx)
{

    uint32 dir = rx ? DIR_RX : DIR_TX;
    MemBufM_t *BufM = &MemBufM[CtrlIdx];

    SchM_Enter_Eth_ETH_EXCLUSIVE_AREA_03();

    if (!(BufM->membuf_bits[dir][bufidx / BYTE_BITS] &\
          ((0x01 << (bufidx % BYTE_BITS))))) {
        BufM->membuf_bits[dir][bufidx / BYTE_BITS] |= \
                (0x01 << (bufidx % BYTE_BITS));
#if (defined(DEBUG_ENABLE) && defined(DEBUG_BUFF))
        show_status(CtrlIdx, rx);
#endif
        SchM_Exit_Eth_ETH_EXCLUSIVE_AREA_03();
        return 0;
    }

    SchM_Exit_Eth_ETH_EXCLUSIVE_AREA_03();
    return -1;
}
/**
 * @description:
 * @param {uint8} CtrlIdx
 * @param {sint16} fifoidx
 * @param {uint16} BufIndex
 * @param {boolean} rx
 * @return {*}
 */
static  uint8 *get_bufptr(uint8 CtrlIdx, sint16 fifoidx, uint16 BufIndex, boolean rx)
{
    uint8 *membufptr;
    uint8 offset_ptr;
    uint32 btye_offset = 0;
    const Eth_CntrlConfigType *cfg = ETH_CFG_CTRL_PARM_PTR(CtrlIdx);
    const Eth_CtrlConfigFifoType *FifoParam;

    if (!cfg) {
        return 0;
    }

    /* The RX part is in the second half */
    if (rx) {
        /*
        Note:
            mem laout: tx buf[....]---rx buf[....]
            So calculating the starting address of receiving buf
            needs to increase the size of the address space for sending buf.
        */
        btye_offset =  cacul_buf_byte_cnt(CtrlIdx, FALSE);
        FifoParam =  cfg->IngressFifoConfig;
        offset_ptr = 0;
    } else {
        FifoParam =  cfg->EgressFifoConfig;
        offset_ptr = MAC_HEADER_LEN;
    }

    btye_offset +=  cacul_buf_byte_cnt_limit(CtrlIdx, fifoidx, rx);
    btye_offset += BufIndex * FifoParam[fifoidx].FifoBufLenByte;
    membufptr = (uint8 *)membufp[CtrlIdx ];
    return &membufptr[btye_offset + offset_ptr];
}
/**
 * @description: caculate the index of buf in an fifo type (Rx type or Tx type)
 * @param {uint8} CtrlIdx
 * @param {const Eth_CtrlConfigFifoType *} fifoarray
 * @param {sint16} fifoidx
 * @param {uint16} BufIndex
 * @return {*}
 */
static sint16 get_bufidx(uint8 CtrlIdx, const Eth_CtrlConfigFifoType *fifoarray, \
                         sint16 fifoidx, uint16 BufIndex)
{

    uint16 btye_offset = 0;

    if (!fifoarray) {
        return -1;
    }

    /*
        Index is monotonic according to the type of FIFO
    */
    for (uint16 Idx = 0; Idx < fifoidx; Idx++) {
        btye_offset += fifoarray[Idx].FifoBufTotal;
    }

    return btye_offset + BufIndex;
}
/**
 * @description:get buf address by buff idx and type
 * @param {uint8} CtrlIdx
 * @param {uint16} BufIndex
 * @param {boolean} rx
 * @return {*}
 */
static uint8 *get_bufptrby_idx(uint8 CtrlIdx, uint16 BufIndex, boolean rx)
{
    uint8 *membufptr;
    uint8 FifoNumber;
    uint16 Idx;
    uint32 btye_offset = 0;
    const Eth_CntrlConfigType *cfg = ETH_CFG_CTRL_PARM_PTR(CtrlIdx);
    const Eth_CtrlConfigFifoType *FifoParam;

    if (!cfg) {
        return 0;
    }

    /* The RX part is in the second half */
    if (rx) {
        /*
        Note:
            mem laout: tx buf[....]---rx buf[....]
            So calculating the starting address of receiving buf
            needs to increase the size of the address space for sending buf.
        */
        btye_offset =  cacul_buf_byte_cnt(CtrlIdx, FALSE);
        FifoNumber = cfg->IngressFifoNumber;
        FifoParam =  cfg->IngressFifoConfig;
    } else {
        FifoNumber = cfg->EgressFifoNumber;
        FifoParam =  cfg->EgressFifoConfig;
    }



    for (Idx = 0; Idx < FifoNumber; Idx++) {
        if (BufIndex < FifoParam[Idx].FifoBufTotal) {
            break;
        }

        BufIndex -= FifoParam[Idx].FifoBufTotal;
    }

    btye_offset += cacul_buf_byte_cnt_limit(CtrlIdx, Idx, rx);
    btye_offset += FifoParam[Idx].FifoBufLenByte * BufIndex;
    membufptr = (uint8 *)membufp[CtrlIdx];
    return &membufptr[btye_offset];
}

/**
 * @description:Init buff alloctor
 * @param {uint8} CtrlIdx
 * @return {*}
 */
void EthBuffInit(uint8 CtrlIdx)
{
    uint8 byte;
    uint32 bits_sum = cacul_buf_cnt(CtrlIdx, TRUE);
    byte = 0;
    MemBufM_t *BufM = &MemBufM[CtrlIdx];

    while (bits_sum >= BYTE_BITS) {
        BufM->membuf_bits[DIR_RX][byte++] = 0xFF;
        bits_sum -= BYTE_BITS;
    }

    BufM->membuf_bits[DIR_RX][byte] = 0;
    BufM->membuf_bits[DIR_RX][byte] |= ((0x1 << (bits_sum % BYTE_BITS)) - 1);
    bits_sum = cacul_buf_cnt(CtrlIdx, FALSE);

    byte = 0;

    while (bits_sum >= BYTE_BITS) {
        BufM->membuf_bits[DIR_TX][byte++] = 0xFF;
        bits_sum -= BYTE_BITS;
    }

    BufM->membuf_bits[DIR_TX][byte] = 0;
    BufM->membuf_bits[DIR_TX][byte] |= ((0x1 << (bits_sum % BYTE_BITS)) - 1);
    BufM->membuf_state  = 1;
}
/**
 * @description:deinit the membuf alloctor
 * @param {uint8} CtrlIdx
 * @return {*}
 */
void EthBuffDeInit(uint8 CtrlIdx)
{
    MemBufM_t *BufM = &MemBufM[CtrlIdx];
    BufM->membuf_state  = 0;
}
/**
 * @description: alloc buf by size and type
 * @param {uint8} CtrlIdx
 * @param {uint16*} Len
 * @param {uint8**} Bufptr
 * @param {Eth_BufIdxType*} BufIdxptr
 * @param {boolean} rx
 * @return {*}
 */
sint32 EthBuffAlloc(uint8 CtrlIdx, uint16 *Len, uint8 **Bufptr, \
                    Eth_BufIdxType *BufIdxptr, boolean rx)
{

    uint8 FifoNumber;
    sint16 FifoIndex;
    sint16 search_down_start_index;
    sint16 local_bufindex, retry_cnt = 0;
    const Eth_CntrlConfigType *cfg = ETH_CFG_CTRL_PARM_PTR(CtrlIdx);
    const Eth_CtrlConfigFifoType *FifoParam;
    MemBufM_t *BufM = &MemBufM[CtrlIdx];

    if (!cfg) {
        return -3;
    }

    /*
        alloctor is not inited .
    */
    if (!BufM->membuf_state) {
        return -1;
    }

    if (rx) {
        FifoNumber = cfg->IngressFifoNumber;
        FifoParam =  cfg->IngressFifoConfig;
    } else {
        FifoNumber = cfg->EgressFifoNumber;
        FifoParam =  cfg->EgressFifoConfig;
    }

    /*
        If you need a buf of x bytes, the allocator can allocate a buf that is greater
        than or equal to x, but if there is no buf that is greater than or equal to,
        the allocator needs to return the size of the available buf that is less than x
    */
re_seek:
    retry_cnt++;
    search_down_start_index = -1;
    FifoIndex = search_up(CtrlIdx, FifoParam, FifoNumber, Len, rx, &search_down_start_index);

    if (FifoIndex >= 0) {
        // found it
        local_bufindex = lock_bufmem(CtrlIdx, FifoParam, FifoIndex, rx);

        if (local_bufindex == -1) {
            /* need back to resech fifo *//*PRQA S 2752 2*/
            if (retry_cnt <= FIFO_RETRY_MAX) {
                goto re_seek;
            } else {
                return -1;
            }
        }

        *BufIdxptr = get_bufidx(CtrlIdx, FifoParam, FifoIndex, local_bufindex);
        *Bufptr = get_bufptr(CtrlIdx, FifoIndex, local_bufindex, rx);
#if (defined(DEBUG_ENABLE) && defined(DEBUG_BUFF))
        show_status(CtrlIdx, rx);
#endif
        return 0;
    } else {
        /* search_down has modify the Len if have free buf */
        if (search_down_start_index != -1) {
            FifoNumber = search_down_start_index;
        }

        FifoIndex = search_down(CtrlIdx, FifoParam, FifoNumber - 1, Len, rx);

        if (FifoIndex >= 0) {
            /* Only smaller bufs are available */
            return -2;
        } else {
            /*  no buf available */
            return -1;
        }
    }
}
/**
 * @description:
 * @param {uint8} CtrlIdx
 * @param {Eth_BufIdxType} BufIdx
 * @param {boolean} rx
 * @return {*}
 */
sint32 EthBuffFree(uint8 CtrlIdx, Eth_BufIdxType BufIdx, boolean rx)
{
    MemBufM_t *BufM = &MemBufM[CtrlIdx];

    /*
        alloctor is not inited .
    */
    if (!BufM->membuf_state) {
        return -1;
    } else if (BufIdx < cacul_buf_cnt(CtrlIdx, rx)) {
        return unlock_bufmem(CtrlIdx, BufIdx, rx);
    }

    return -1;

}
/**
 * @description:
 * @param {uint8} CtrlIdx
 * @param {Eth_BufIdxType} BufIdx
 * @param {boolean} rx
 * @return {*}
 */
uint32 EthBuffAddr(uint8 CtrlIdx, Eth_BufIdxType BufIdx, boolean rx)
{
    /*
        alloctor is not inited .
    */
    MemBufM_t *BufM = &MemBufM[CtrlIdx];

    if (!BufM->membuf_state) {
        return 0;
    } else if (BufIdx < cacul_buf_cnt(CtrlIdx, rx)) {
        return (uint32)get_bufptrby_idx(CtrlIdx, BufIdx, rx);
    }

    return 0;
}
/**
 * @description:get buf address by buff idx and type
 * @param {uint8} CtrlIdx
 * @param {uint16} BufIndex
 * @param {boolean} rx
 * @return {*}
 */
static uint32 get_bufsizeby_idx(uint8 CtrlIdx, uint16 BufIndex, boolean rx)
{
    uint8 FifoNumber;
    uint16 Idx;
    const Eth_CntrlConfigType *cfg = ETH_CFG_CTRL_PARM_PTR(CtrlIdx);
    const Eth_CtrlConfigFifoType *FifoParam;

    if (!cfg) {
        return 0;
    }

    /* The RX part is in the second half */
    if (rx) {
        /*
        Note:
            mem laout: tx buf[....]---rx buf[....]
            So calculating the starting address of receiving buf
            needs to increase the size of the address space for sending buf.
        */
        FifoNumber = cfg->IngressFifoNumber;
        FifoParam =  cfg->IngressFifoConfig;
    } else {
        FifoNumber = cfg->EgressFifoNumber;
        FifoParam =  cfg->EgressFifoConfig;
    }


    for (Idx = 0; Idx < FifoNumber; Idx++) {
        if (BufIndex < FifoParam[Idx].FifoBufTotal) {
            break;
        }
    }

    return FifoParam[Idx].FifoBufLenByte;
}
/**
 * @description:
 * @param {uint8} CtrlIdx
 * @param {uint32} buffaddr
 * @param {boolean} is_rx
 * @return {*}
 */
Eth_BufIdxType get_idx_of_buff(uint8 CtrlIdx, const Eth_DataType  *buffaddr, boolean is_rx)
{
    uint32 curr_buff_addr, BufIndex;

    for (BufIndex = 0; BufIndex < cacul_buf_cnt(CtrlIdx, is_rx); BufIndex++) {
        curr_buff_addr = (uint32)get_bufptrby_idx(CtrlIdx, BufIndex, is_rx);

        if (curr_buff_addr <= (uint32)buffaddr  &&
            (curr_buff_addr + get_bufsizeby_idx(CtrlIdx, BufIndex, is_rx)) > (uint32)buffaddr ) {
            return BufIndex;
        }
    }

    return ILLEGAL_BUFF_IDX;
}

/**
 * @description:
 * @param {uint8} CtrlIdx
 * @param {Eth_BufIdxType} BufIdx
 * @param {boolean} rx
 * @return {*}
 */
Eth_BufIdxType EthBuffIdxFormAddr(uint8 CtrlIdx, const Eth_DataType *Bufaddr, boolean rx)
{
    /*
        alloctor is not inited .
    */
    MemBufM_t *BufM = &MemBufM[CtrlIdx];

    if (!BufM->membuf_state) {
        return 0;
    } else {
        return get_idx_of_buff(CtrlIdx, Bufaddr, rx);
    }
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#ifdef __cplusplus
}
#endif
