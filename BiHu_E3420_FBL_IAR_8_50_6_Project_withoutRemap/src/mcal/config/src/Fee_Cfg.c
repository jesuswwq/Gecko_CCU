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
 * @date 2024-03-08 17:21:47
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
        1310720U,           /* Fee Page0 area start addr */
        262144U,           /* Fee Page0 area size */
        262144U       /* Fee Page0 each erase size */
    },
    /* FeePage1 */
    {
        1572864U,           /* Fee Page1 area start addr */
        262144U,           /* Fee Page1 area size */
        262144U       /* Fee Page1 each erase size */
    }
};

/* Configuration of page device set */
const Fee_PageDeviceType Fee_PageDevice[FEE_PAGE_DEV_NUMBER] =
{
    /* FeePageDevice_0 */
    {
        FeePageDevice_0, /* page set */
        1024U/* Size of the reserved area */
    }
};

/* Configuration of Fee blocks */
const Fee_BlockConfigType Fee_BlockConfig[FEE_BLOCKS_CFG_NUMBER] =
{
    /* FeeBlockConfiguration_NvmInfo */
    {
        FeeBlockConfiguration_NvmInfo, /* FeeBlockNumber symbol */
        64U, /* FeeBlockSize */
        0U, /* FeePageDevice */
        (boolean)FALSE    },
    /* FeeBlockConfiguration_Factory */
    {
        FeeBlockConfiguration_Factory, /* FeeBlockNumber symbol */
        64U, /* FeeBlockSize */
        0U, /* FeePageDevice */
        (boolean)FALSE    },
    /* FeeBlockConfiguration_SecurityAccess */
    {
        FeeBlockConfiguration_SecurityAccess, /* FeeBlockNumber symbol */
        64U, /* FeeBlockSize */
        0U, /* FeePageDevice */
        (boolean)FALSE    },
    /* FeeBlockConfiguration_ProgramAttempt */
    {
        FeeBlockConfiguration_ProgramAttempt, /* FeeBlockNumber symbol */
        64U, /* FeeBlockSize */
        0U, /* FeePageDevice */
        (boolean)FALSE    },
    /* FeeBlockConfiguration_ProgramSuccess */
    {
        FeeBlockConfiguration_ProgramSuccess, /* FeeBlockNumber symbol */
        64U, /* FeeBlockSize */
        0U, /* FeePageDevice */
        (boolean)FALSE    },
    /* FeeBlockConfiguration_FingerPrint */
    {
        FeeBlockConfiguration_FingerPrint, /* FeeBlockNumber symbol */
        64U, /* FeeBlockSize */
        0U, /* FeePageDevice */
        (boolean)FALSE    },
    /* FeeBlockConfiguration_ForcSwap */
    {
        FeeBlockConfiguration_ForcSwap, /* FeeBlockNumber symbol */
        64U, /* FeeBlockSize */
        0U, /* FeePageDevice */
        (boolean)FALSE    },
    /* FeeBlockConfiguration_A_Counter */
    {
        FeeBlockConfiguration_A_Counter, /* FeeBlockNumber symbol */
        64U, /* FeeBlockSize */
        0U, /* FeePageDevice */
        (boolean)FALSE    },
    /* FeeBlockConfiguration_B_Counter */
    {
        FeeBlockConfiguration_B_Counter, /* FeeBlockNumber symbol */
        64U, /* FeeBlockSize */
        0U, /* FeePageDevice */
        (boolean)FALSE    },
    /* FeeBlockConfiguration_NvmInfoB */
    {
        FeeBlockConfiguration_NvmInfoB, /* FeeBlockNumber symbol */
        64U, /* FeeBlockSize */
        0U, /* FeePageDevice */
        (boolean)FALSE    },
    /* FeeBlockConfiguration_FingerPrintB */
    {
        FeeBlockConfiguration_FingerPrintB, /* FeeBlockNumber symbol */
        64U, /* FeeBlockSize */
        0U, /* FeePageDevice */
        (boolean)FALSE    }
};

#define FEE_STOP_SEC_CONST_UNSPECIFIED
#include "Fee_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @}*/
