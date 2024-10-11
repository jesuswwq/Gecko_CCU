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
 * @file  EthDesc.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Eth plugins.
 */

#ifndef ETH_DESC_RING_H_
#define ETH_DESC_RING_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "Eth.h"
#include "Compiler.h"

#define min(a,b) (((a) < (b) )? (a):(b))
enum {
    DESC_TX = 0,
    DESC_RX,
    DESC_TYPE_MAX
};

#define GET_TX_DESC_INDEX(CtrlIdx,Ch,tdesc)  \
    ((((uint32)tdesc) - (uint32)&Eth_Desc_Buf[CtrlIdx][(Ch)][DESC_TX].desc[0])/sizeof(struct dma_desc))

#define GET_RX_DESC_INDEX(CtrlIdx,Ch,tdesc)  \
    ((((uint32)tdesc) - (uint32)&Eth_Desc_Buf[CtrlIdx][(Ch)][DESC_RX].desc[0])/sizeof(struct dma_desc))

extern VAR(dma_desc_ring_t, ETH_VAR)          \
Eth_Desc_Buf[ETH_MAXCTRLS_SUPPORTED][ETH_MAX_DMA_CHANNEL][DESC_TYPE_MAX];


void desc_ring_init(uint8 CtrlIdx);
struct dma_desc *alloc_dma_desc(uint8 CtrlIdx, uint8 channel, boolean rx);
sint32 free_dma_desc(uint8 CtrlIdx, uint8 channel, boolean rx);
sint32 locked_desc_put(uint8 CtrlIdx, uint8 channel, locked_desc_t *descp, boolean rx);
sint32 locked_desc_get(uint8 CtrlIdx, uint8 channel, locked_desc_t **descpp, boolean rx);
sint32 locked_desc_touch(uint8 CtrlIdx, uint8 channel, locked_desc_t **descpp, boolean rx);
struct dma_desc *get_dma_desc(uint8 CtrlIdx, uint8 channel, uint32 curidx, boolean rx);
struct dma_desc *get_dma_desc_next(uint8 CtrlIdx, uint8 channel, uint32 curidx, boolean rx);

#ifdef __cplusplus
}
#endif

#endif
