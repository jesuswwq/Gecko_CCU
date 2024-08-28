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
 * @file  Fee_Type.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Flash EEPROM Emulation
 */

#ifndef FEE_TYPES_H
#define FEE_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "MemIf_Types.h"
#include "Fls.h"

#define FEE_PAGE_CFG_NUMBER                     2U

/* Fee block cfg */
typedef struct {
    uint16 blockNumber;                       /* Fee block number */
    uint16 blockSize;                         /* Size of Fee block */
    uint16 pageDevIndex;                      /* Fee page device Index */
    boolean immediateData;                         /* immediate data block flag */
} Fee_BlockConfigType;

/* Fee page cfg */
typedef struct {
    Fls_AddressType Fls_startAddr;              /* Fee page address */
    Fls_LengthType Fls_length;                  /* Fee page size */
    Fls_LengthType Fls_eraseSize;               /* Fee page erase size */
    Fls_LengthType Fls_sectorSize;              /* Fee page sector size */
} Fee_PageType;

/* Fee page device cfg */
typedef struct {
    const Fee_PageType *clrPtr;                       /* Fee page cfg */
    Fls_LengthType reservedSize;                /* Fee page reserved size */
} Fee_PageDeviceType;

typedef Fee_BlockConfigType Fee_ConfigType;

#ifdef __cplusplus
}
#endif

#endif /* FEE_TYPES_H */
