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
 * @file  Fee_Cfg.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Flash EEPROM Emulation
 * @date 2024-03-08 16:29:00
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Fee.h"

#define FEE_START_SEC_CONST_UNSPECIFIED
#include "Fee_MemMap.h"

/* Configuration of page FeePageDevice_0 */
const Fee_PageType FeePageDevice_0[FEE_PAGE_CFG_NUMBER] =
{
    /* FeePage0 */
    {
        66584576U,           /* Fee Page0 area start addr */
        262144U,           /* Fee Page0 area size */
        262144U,      /* Fee Page0 each erase size */
        262144U      /* Fee Page0 sector size */
    },
    /* FeePage1 */
    {
        66846720U,           /* Fee Page1 area start addr */
        262144U,           /* Fee Page1 area size */
        262144U,      /* Fee Page1 each erase size */
        262144U      /* Fee Page1 sector size */
    }
};

/* Configuration of page device set */
const Fee_PageDeviceType Fee_PageDevice[FEE_PAGE_DEV_NUMBER] =
{
    /* FeePageDevice_0 */
    {
        FeePageDevice_0, /* page set */
        512U/* Size of the reserved area */
    }
};

/* Configuration of Fee blocks */
const Fee_BlockConfigType Fee_BlockConfig[FEE_BLOCKS_CFG_NUMBER] =
{
    /* FeeBlockConfiguration_0 */
    {
        FeeBlockConfiguration_0, /* FeeBlockNumber symbol */
        512U, /* FeeBlockSize */
        0U, /* FeePageDevice */
        (boolean)FALSE    },
    /* FeeBlockConfiguration_1 */
    {
        FeeBlockConfiguration_1, /* FeeBlockNumber symbol */
        512U, /* FeeBlockSize */
        0U, /* FeePageDevice */
        (boolean)FALSE    },
    /* FeeBlockConfiguration_2 */
    {
        FeeBlockConfiguration_2, /* FeeBlockNumber symbol */
        512U, /* FeeBlockSize */
        0U, /* FeePageDevice */
        (boolean)FALSE    },
    /* FeeBlockConfiguration_3 */
    {
        FeeBlockConfiguration_3, /* FeeBlockNumber symbol */
        512U, /* FeeBlockSize */
        0U, /* FeePageDevice */
        (boolean)TRUE    }
};

#define FEE_STOP_SEC_CONST_UNSPECIFIED
#include "Fee_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @}*/
