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
 * @file EthTrcv_PBCfg.h
 * @brief EthTrcv Configuration.
 * @details Semidrive. AUTOSAR 4.3.1 EthTrcv plugins
 * @date 2024-03-08 16:29:00
 */

#ifndef ETHTRCV_CFG_H
#define ETHTRCV_CFG_H

#ifdef __cplusplus
extern "C" {
#endif
#include "Mcal.h"
#include "Std_Types.h"
#include "Eth_GeneralTypes.h"
#include "Det.h"

/* Version and Check Begin */
/* Version Info Begin */
#define ETHTRCV_CFG_H_VENDOR_ID    0x8C
#define ETHTRCV_CFG_H__MODULE_ID     73
#define ETHTRCV_CFG_H_AR_RELEASE_MAJOR_VERSION    4
#define ETHTRCV_CFG_H_AR_RELEASE_MINOR_VERSION    3
#define ETHTRCV_CFG_H_AR_RELEASE_REVISION_VERSION 1
#define ETHTRCV_CFG_H_SW_MAJOR_VERSION    1
#define ETHTRCV_CFG_H_SW_MINOR_VERSION    0
#define ETHTRCV_CFG_H_SW_PATCH_VERSION    0
/* Version Info End */

/* Macro Config */
#define ETHTRCV_DEV_ERROR_DETECT (STD_ON)

#define ETHTRCV_GET_BAUDRATE_API (STD_ON)

#define ETHTRCV_GET_DUPLEXMODE_API (STD_ON)

#define ETHTRCV_GET_LINKSTATE_API (STD_ON)

#define ETHTRCV_GET_IDENTIFIER_API (STD_ON)

#define ETHTRCV_GET_SIGNALQUALITY_API (STD_ON)

#define ETHTRCV_GET_TRANSCEIVERMODE_API (STD_ON)


#define ETHTRCV_GET_WAKEUPMODE_API (STD_OFF)

#define ETHTRCV_SET_TESTMODE_API (STD_ON)

#define ETHTRCV_GET_VERSION_API (STD_ON)

#define ETHTRCV_SET_STARTAUTONEGOTIA_API (STD_ON)

#define ETHTRCV_MAXTRCV_SUPPORTED (2U)

#define ETHTRCV_DRIVER_INSTANCE (0U)

#define ETHTRCV_Q21XX_SUPPORTED (STD_ON)

#define ETHTRCV_DP83848X_SUPPORTED (STD_ON)

#define ETHTRCV_RTL9010X_SUPPORTED (STD_ON)

#define ETHTRCV_RTL820F_SUPPORTED (STD_ON)

#define ETHTRCV_MAX_CORES   (5U)

enum phy_type {
    ETHTRCV_TYPE_DUMMY = 0,
#if ETHTRCV_Q21XX_SUPPORTED == STD_ON
    ETHTRCV_TYPE_Q2112,
#endif
#if ETHTRCV_DP83848X_SUPPORTED == STD_ON
    ETHTRCV_TYPE_DP83848,
#endif
#if ETHTRCV_RTL9010X_SUPPORTED == STD_ON
    ETHTRCV_TYPE_RTL9010AA,
#endif
#if ETHTRCV_RTL820F_SUPPORTED == STD_ON
    ETHTRCV_TYPE_RTL820F,
#endif
    ETHTRCV_TYPE_MAX,
};

typedef struct {

    const uint32 ConnNegMode;
    const uint32 DuplexMode;
    const uint32 Speed;
    const boolean AutoNegotiation;
    const uint8 TrcvIdx;
    const uint8 CtrlIdx;
    const uint8 PhyAddr;
    const uint32  MacLayerSpeed;
    const uint32  MacLayerType;
    const uint32  MacLayerSubType;
    const PhysLayerType  PhysLayerType;
    const boolean PhyIsc45;
    const boolean PhyIsSwtPort;
    const uint8 SwtPort;
    const uint8 SwtIdx;
    const enum phy_type phy_type;
}EthTrcvConfigType;


typedef struct
{
  /* Store address of controller configuration for the current core */
  const EthTrcvConfigType* EthTrcvConfigPtr;
  /* Store maximum controllers allocated to current core */
  const uint8          EthTrcvCount;
}EthTrcv_CoreConfigType ;

typedef struct
{
  /* Array to store starting addresses of Core Configuration */
  const EthTrcv_CoreConfigType* EthTrcvCoreConfig[ETHTRCV_MAX_CORES];

}EthTrcv_ConfigType;


extern CONST(EthTrcv_ConfigType, ETH_CONST) EthTrcv_Config;

#ifdef __cplusplus
}
#endif

#endif /*ETHTRCV_CFG_H*/
