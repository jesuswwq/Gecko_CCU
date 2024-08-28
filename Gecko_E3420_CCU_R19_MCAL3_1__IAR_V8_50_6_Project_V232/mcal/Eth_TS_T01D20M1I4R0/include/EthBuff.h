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
 * @file  EthBuff.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Eth plugins.
 */

#ifndef ETH_BUFF_H_
#define ETH_BUFF_H_

#ifdef __cplusplus
extern "C" {
#endif

/* illegal idx */
#define  ILLEGAL_BUFF_IDX 0xFFFFFF
/**
 * @description:
 * @param {*}
 * @return {*}
 */
void EthBuffInit(uint8 CtrlIdx);
/**
 * @description:
 * @param {uint8} CtrlIdx
 * @return {*}
 */
void EthBuffDeInit(uint8 CtrlIdx);
/**
 * @description:
 * @param {*}
 * @return {*}
 */
sint32 EthBuffAlloc(uint8 CtrlIdx, uint16 *Len, uint8 **Bufptr, \
                    Eth_BufIdxType *BufIdxptr, boolean rx);
/**
 * @description:
 * @param {uint8} CtrlIdx
 * @param {Eth_BufIdxType} BufIdx
 * @param {boolean} rx
 * @return {*}
 */
sint32 EthBuffFree(uint8 CtrlIdx, Eth_BufIdxType BufIdx, boolean rx);
/**
 * @description:
 * @param {*}
 * @return {*}
 */
uint32 EthBuffAddr(uint8 CtrlIdx, Eth_BufIdxType BufIdx, boolean rx);
/**
 * @description: from buff addr get buf idx
 * @param {uint8} CtrlIdx
 * @param {Eth_DataType *} Bufaddr
 * @param {boolean} rx
 * @return Eth_BufIdxType
 */
Eth_BufIdxType EthBuffIdxFormAddr(uint8 CtrlIdx, const Eth_DataType *Bufaddr, boolean rx);
/**
 * @description:
 * @param {uint8} CtrlIdx
 * @param {boolean} rx
 * @return buf count
 */
uint32 cacul_buf_cnt(uint8 CtrlIdx, boolean rx);

#ifdef __cplusplus
}
#endif

#endif



