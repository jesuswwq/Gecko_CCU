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
 * @file  Crypto_ShareMem.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Crypto
 */

#ifndef CRYPTO_SHARE_MEM_H
#define CRYPTO_SHARE_MEM_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "arch.h"

#define CRYPTO_SHARE_MEM_BLOCK_NUM         (4u)
#define CRYPTO_SHARE_MEM_SIZE              (0x4000ul)    /*16KB*/
#define CRYPTO_SHARE_BLOCK_SIZE                  (CRYPTO_SHARE_MEM_SIZE/CRYPTO_SHARE_MEM_BLOCK_NUM)

#define CRYPTO_MAX_SHARE_DATA_BLOCK_SIZE(x)     ((CRYPTO_SHARE_BLOCK_SIZE - 70u) / (x)  * (x))    /*common block: 4 bytes length + 64 bytes IV + n bytes Data*/

#define CRYPTO_SHARE_MEM_NODE_RSA_MAX 512
#define CRYPTO_SHARE_MEM_NODE_RSA_MAX_EXT 516
#define CRYPTO_SHARE_MEM_NODE_DIG_MAX 64
#define CRYPTO_SHARE_MEM_NODE_HASH_PAD_MAX 256
#define CRYPTO_SHARE_MEM_NODE_COMM_SMALL_BUFF_MAX 64
#define CRYPTO_SHARE_MEM_NODE_COMM_BUFF_MAX 516

Std_ReturnType ShareMem_Init(void);
uint8 * ShareMem_GetBlock(uint32 size);
uint8 ShareMem_ReleaseBlock(uint8 *ptr);

#ifdef __cplusplus
}
#endif

#endif /* CRYPTO_SHARE_MEM_H */
