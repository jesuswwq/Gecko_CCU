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
 * @file EthTrcv_PBCfg.c
 * @brief EthTrcv Configuration.
 * @details Semidrive. AUTOSAR 4.3.1 EthTrcv plugins
 * @date 2024-03-08 16:29:00
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "EthTrcv.h"
#include "EthTrcv_PBCfg.h"

/* Version and Check Begin */
/* Version Info Begin */
#define ETHTRCV_PBCFG_C_VENDOR_ID    0x8C
#define ETHTRCV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4
#define ETHTRCV_PBCFG_C_AR_RELEASE_MINOR_VERSION    3
#define ETHTRCV_PBCFG_C_AR_RELEASE_REVISION_VERSION 1
#define ETHTRCV_PBCFG_C_SW_MAJOR_VERSION    1
#define ETHTRCV_PBCFG_C_SW_MINOR_VERSION    0
#define ETHTRCV_PBCFG_C_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((ETHTRCV_PBCFG_C_AR_RELEASE_MAJOR_VERSION != ETHTRCV_AR_RELEASE_MAJOR_VERSION)\
    || (ETHTRCV_PBCFG_C_AR_RELEASE_MINOR_VERSION != ETHTRCV_AR_RELEASE_MINOR_VERSION)\
    || (ETHTRCV_PBCFG_C_AR_RELEASE_REVISION_VERSION != ETHTRCV_AR_RELEASE_REVISION_VERSION))
    #error "Opps, EthTrcv_PBCfg.c and EthTrcv.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((ETHTRCV_PBCFG_C_SW_MAJOR_VERSION != ETHTRCV_SW_MAJOR_VERSION)\
    || (ETHTRCV_PBCFG_C_SW_MINOR_VERSION != ETHTRCV_SW_MINOR_VERSION)\
    || (ETHTRCV_PBCFG_C_SW_PATCH_VERSION != ETHTRCV_SW_PATCH_VERSION))
    #error "Opps, EthTrcv_PBCfg.c and EthTrcv.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */


#define ETHTRCV_START_SEC_CONST_UNSPECIFIED
#include "EthTrcv_MemMap.h"


CONST(EthTrcvConfigType, ETH_CONST) EthTrcvConfig_Core0[2] = {
    {
        .AutoNegotiation = (boolean)FALSE,
        .ConnNegMode = TRCV_CONN_NEG_MASTER,
        .DuplexMode = ETHTRCV_DUPLEX_MODE_FULL,
        .Speed = TRCV_SPEED_1000,
        .TrcvIdx = 0U,
        .CtrlIdx = 0U,
        .PhyAddr = 0,
        .PhyIsc45 = (boolean)FALSE,
        .PhyIsSwtPort =   (boolean)FALSE,
        .phy_type = ETHTRCV_TYPE_RTL9010AA,
    },
    {
        .AutoNegotiation = (boolean)FALSE,
        .ConnNegMode = TRCV_CONN_NEG_MASTER,
        .DuplexMode = ETHTRCV_DUPLEX_MODE_FULL,
        .Speed = TRCV_SPEED_100,
        .TrcvIdx = 1U,
        .CtrlIdx = 1U,
        .PhyAddr = 4,
        .PhyIsc45 = (boolean)FALSE,
        .PhyIsSwtPort =   (boolean)FALSE,
        .phy_type = ETHTRCV_TYPE_DP83848,
    },
};

CONST(EthTrcv_CoreConfigType, ETH_CONST) EthTrcvCoreControlConfig_Core0 = {
    .EthTrcvConfigPtr = EthTrcvConfig_Core0,
    .EthTrcvCount = 2
};

CONST(EthTrcv_ConfigType, ETH_CONST) EthTrcv_Config = {
    .EthTrcvCoreConfig={
        &EthTrcvCoreControlConfig_Core0,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR
    }
};

#define ETHTRCV_STOP_SEC_CONST_UNSPECIFIED
#include "EthTrcv_MemMap.h"

#ifdef __cplusplus
}
#endif
