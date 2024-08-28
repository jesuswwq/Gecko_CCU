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
 * \file     Firewall_Mpc_Cfg.c                                                                         *
 * \brief    This file contains configuration source for Firewall MPC MCAL driver                       *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date                 <th>Version                                                             *
 * <tr><td>2024-03-08 16:29:01      <td>1.0.0 R                                                         *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

#include "Firewall_Mpc_Cfg.h"

#define FIREWALL_START_SEC_CONST_UNSPECIFIED
#include "Firewall_MemMap.h"
/********************************************************************************************************
 *                                  Private Constant Definitions                                        *
 *******************************************************************************************************/

/** \brief The configuration of regions for the memory port. */
static const Firewall_MpcRegionConfigType Firewall_MpcMemPort1Cfg[] =
{
    {
        0x00U, 0x1ffffU,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE
    }
};

/** \brief The configuration of regions for the memory port. */
static const Firewall_MpcRegionConfigType Firewall_MpcMemPort2Cfg[] =
{
    {
        0x00U, 0xfffffU,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE
    }
};

/** \brief The configuration of regions for the memory port. */
static const Firewall_MpcRegionConfigType Firewall_MpcMemPort3Cfg[] =
{
    {
        0x00U, 0x1fffffU,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE
    }
};

/** \brief The configuration of regions for the memory port. */
static const Firewall_MpcRegionConfigType Firewall_MpcMemPort4Cfg[] =
{
    {
        0x00U, 0xfffffU,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE
    }
};

/** \brief The configuration of regions for the memory port. */
static const Firewall_MpcRegionConfigType Firewall_MpcMemPort5Cfg[] =
{
    {
        0x00U, 0xfffffU,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE
    }
};

/** \brief The configuration of regions for the memory port. */
static const Firewall_MpcRegionConfigType Firewall_MpcMemPort6Cfg[] =
{
    {
        0x00U, 0xbfffffffU,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE
    }
};

/** \brief The configuration of regions for the memory port. */
static const Firewall_MpcRegionConfigType Firewall_MpcMemPort7Cfg[] =
{
    {
        0x00U, 0x7ffffffU,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE
    }
};

/** \brief The configuration of regions for the memory port. */
static const Firewall_MpcRegionConfigType Firewall_MpcMemPort8Cfg[] =
{
    {
        0x00U, 0x7ffffffU,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE
    }
};

/** \brief The configuration of regions for the memory port. */
static const Firewall_MpcRegionConfigType Firewall_MpcMemPort9Cfg[] =
{
    {
        0x00U, 0x7ffffffU,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE
    }
};

/** \brief The configuration of regions for the memory port. */
static const Firewall_MpcRegionConfigType Firewall_MpcMemPort10Cfg[] =
{
    {
        0x00U, 0x7ffffffU,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE
    }
};
    /* mailbox region, not configure*/
static const Firewall_MpcRegionConfigType Firewall_MpcMemPort11Cfg[] =
{
    {
        0x00U, 0x00U,
        (FIREWALL_PERMISSION_RW << 2U) | FIREWALL_PERMISSION_RW,
        (FIREWALL_PERMISSION_RW << 2U) | FIREWALL_PERMISSION_RW,
        (FIREWALL_PERMISSION_RW << 2U) | FIREWALL_PERMISSION_RW,
        (FIREWALL_PERMISSION_RW << 2U) | FIREWALL_PERMISSION_RW,
        (FIREWALL_PERMISSION_RW << 2U) | FIREWALL_PERMISSION_RW,
        (FIREWALL_PERMISSION_RW << 2U) | FIREWALL_PERMISSION_RW,
        (FIREWALL_PERMISSION_RW << 2U) | FIREWALL_PERMISSION_RW,
        (FIREWALL_PERMISSION_RW << 2U) | FIREWALL_PERMISSION_RW
    }
};

/** \brief The configuration of regions for the memory port. */
static const Firewall_MpcRegionConfigType Firewall_MpcMemPort12Cfg[] =
{
    {
        0x00U, 0xffffU,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE
    }
};

/** \brief The configuration of regions for the memory port. */
static const Firewall_MpcRegionConfigType Firewall_MpcMemPort13Cfg[] =
{
    {
        0x00U, 0xffffU,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE
    }
};

/** \brief The configuration of regions for the memory port. */
static const Firewall_MpcRegionConfigType Firewall_MpcMemPort14Cfg[] =
{
    {
        0x00U, 0xffffU,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE
    }
};

/** \brief The configuration of regions for the memory port. */
static const Firewall_MpcRegionConfigType Firewall_MpcMemPort15Cfg[] =
{
    {
        0x00U, 0xffffU,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE
    }
};

/** \brief The configuration of regions for the memory port. */
static const Firewall_MpcRegionConfigType Firewall_MpcMemPort16Cfg[] =
{
    {
        0x00U, 0xffffU,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE
    }
};

/** \brief The configuration of regions for the memory port. */
static const Firewall_MpcRegionConfigType Firewall_MpcMemPort17Cfg[] =
{
    {
        0x1930000U, 0x197ffffU,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE
    }
};

/** \brief The configuration of regions for the memory port. */
static const Firewall_MpcRegionConfigType Firewall_MpcMemPort18Cfg[] =
{
    {
        0x1838000U, 0x187ffffU,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE
    }
};

/** \brief The configuration of regions for the memory port. */
static const Firewall_MpcRegionConfigType Firewall_MpcMemPort19Cfg[] =
{
    {
        0x18b8000U, 0x18fffffU,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE
    }
};

/** \brief The configuration of regions for the memory port. */
static const Firewall_MpcRegionConfigType Firewall_MpcMemPort20Cfg[] =
{
    {
        0x1a38000U, 0x1a7ffffU,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE
    }
};

/** \brief The configuration of regions for the memory port. */
static const Firewall_MpcRegionConfigType Firewall_MpcMemPort21Cfg[] =
{
    {
        0x1ab8000U, 0x1afffffU,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE
    }
};

/** \brief The configuration of regions for the memory port. */
static const Firewall_MpcRegionConfigType Firewall_MpcMemPort22Cfg[] =
{
    {
        0x2100000U, 0x2200fffU,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE
    }
};

/** \brief The configuration of regions for the memory port. */
static const Firewall_MpcRegionConfigType Firewall_MpcMemPort23Cfg[] =
{
    {
        0x1000000U, 0x13fffffU,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE,
        (FIREWALL_PERMISSION_NONE << 2U) | FIREWALL_PERMISSION_NONE
    }
};
/********************************************************************************************************
 *                                  Global Constant Declarations                                        *
 *******************************************************************************************************/
/*PRQA S 1531 4*/
/** \brief The configuration of the firewall MPC module.
 * Traceability: SWSR_FIREWALL_010 SWSR_FIREWALL_011 SWSR_FIREWALL_012
 */
const Firewall_MpcMemPortConfigType Firewall_MpcCfg[FIREWALL_MPC_MEMPORT_NUM] =
{
    {
        .mpcRegionNum = 1U,
        .mpcBaseOffset = 0x800U,
        .mpcRegionCfgPtr = &Firewall_MpcMemPort1Cfg[0],
    },
    {
        .mpcRegionNum = 1U,
        .mpcBaseOffset = 0xc00U,
        .mpcRegionCfgPtr = &Firewall_MpcMemPort2Cfg[0],
    },
    {
        .mpcRegionNum = 1U,
        .mpcBaseOffset = 0x1000U,
        .mpcRegionCfgPtr = &Firewall_MpcMemPort3Cfg[0],
    },
    {
        .mpcRegionNum = 1U,
        .mpcBaseOffset = 0x1400U,
        .mpcRegionCfgPtr = &Firewall_MpcMemPort4Cfg[0],
    },
    {
        .mpcRegionNum = 1U,
        .mpcBaseOffset = 0x1800U,
        .mpcRegionCfgPtr = &Firewall_MpcMemPort5Cfg[0],
    },
    {
        .mpcRegionNum = 1U,
        .mpcBaseOffset = 0x1c00U,
        .mpcRegionCfgPtr = &Firewall_MpcMemPort6Cfg[0],
    },
    {
        .mpcRegionNum = 1U,
        .mpcBaseOffset = 0x2000U,
        .mpcRegionCfgPtr = &Firewall_MpcMemPort7Cfg[0],
    },
    {
        .mpcRegionNum = 1U,
        .mpcBaseOffset = 0x2400U,
        .mpcRegionCfgPtr = &Firewall_MpcMemPort8Cfg[0],
    },
    {
        .mpcRegionNum = 1U,
        .mpcBaseOffset = 0x2800U,
        .mpcRegionCfgPtr = &Firewall_MpcMemPort9Cfg[0],
    },
    {
        .mpcRegionNum = 1U,
        .mpcBaseOffset = 0x2c00U,
        .mpcRegionCfgPtr = &Firewall_MpcMemPort10Cfg[0],
    },
    {
        .mpcRegionNum = 1U,
        .mpcBaseOffset = 0x3000U,
        .mpcRegionCfgPtr = &Firewall_MpcMemPort11Cfg[0],
    },
    {
        .mpcRegionNum = 1U,
        .mpcBaseOffset = 0x3400U,
        .mpcRegionCfgPtr = &Firewall_MpcMemPort12Cfg[0],
    },
    {
        .mpcRegionNum = 1U,
        .mpcBaseOffset = 0x3800U,
        .mpcRegionCfgPtr = &Firewall_MpcMemPort13Cfg[0],
    },
    {
        .mpcRegionNum = 1U,
        .mpcBaseOffset = 0x3c00U,
        .mpcRegionCfgPtr = &Firewall_MpcMemPort14Cfg[0],
    },
    {
        .mpcRegionNum = 1U,
        .mpcBaseOffset = 0x4000U,
        .mpcRegionCfgPtr = &Firewall_MpcMemPort15Cfg[0],
    },
    {
        .mpcRegionNum = 1U,
        .mpcBaseOffset = 0x4400U,
        .mpcRegionCfgPtr = &Firewall_MpcMemPort16Cfg[0],
    },
    {
        .mpcRegionNum = 1U,
        .mpcBaseOffset = 0x4c00U,
        .mpcRegionCfgPtr = &Firewall_MpcMemPort17Cfg[0],
    },
    {
        .mpcRegionNum = 1U,
        .mpcBaseOffset = 0x5000U,
        .mpcRegionCfgPtr = &Firewall_MpcMemPort18Cfg[0],
    },
    {
        .mpcRegionNum = 1U,
        .mpcBaseOffset = 0x5400U,
        .mpcRegionCfgPtr = &Firewall_MpcMemPort19Cfg[0],
    },
    {
        .mpcRegionNum = 1U,
        .mpcBaseOffset = 0x5800U,
        .mpcRegionCfgPtr = &Firewall_MpcMemPort20Cfg[0],
    },
    {
        .mpcRegionNum = 1U,
        .mpcBaseOffset = 0x5c00U,
        .mpcRegionCfgPtr = &Firewall_MpcMemPort21Cfg[0],
    },
    {
        .mpcRegionNum = 1U,
        .mpcBaseOffset = 0x6000U,
        .mpcRegionCfgPtr = &Firewall_MpcMemPort22Cfg[0],
    },
    {
        .mpcRegionNum = 1U,
        .mpcBaseOffset = 0x6400U,
        .mpcRegionCfgPtr = &Firewall_MpcMemPort23Cfg[0],
    },
};

#define FIREWALL_STOP_SEC_CONST_UNSPECIFIED
#include "Firewall_MemMap.h"

#ifdef __cplusplus
}
#endif
/* End of file */
