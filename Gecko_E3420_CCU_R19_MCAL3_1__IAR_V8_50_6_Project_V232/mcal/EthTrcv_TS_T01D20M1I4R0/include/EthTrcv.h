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
 * @file  EthTrcv.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL EthTrcv plugins.
 */

#ifndef ETH_TRCV_H
#define ETH_TRCV_H

#ifdef __cplusplus
extern "C" {
#endif

#include "arch.h"
#include "EthTrcv_PBCfg.h"

#define ETHTRCV_VENDOR_ID   0x8C
#define ETHTRCV_MODULE_ID   73
#define ETHTRCV_AR_RELEASE_MAJOR_VERSION     4
#define ETHTRCV_AR_RELEASE_MINOR_VERSION     3
#define ETHTRCV_AR_RELEASE_REVISION_VERSION  1
#define ETHTRCV_SW_MAJOR_VERSION    1
#define ETHTRCV_SW_MINOR_VERSION    0
#define ETHTRCV_SW_PATCH_VERSION    0


#define ETHTRCV_SID_INIT 0x01
#define ETHTRCV_SID_SETTRANSCEIVERMODE 0x03
#define ETHTRCV_SID_GETTRANSCEIVERMODE 0x04
#define ETHTRCV_SID_SETTRANSCEIVERWAKEUPMODE 0x0d
#define ETHTRCV_SID_GETTRANSCEIVERWAKEUPMODE 0x0e
#define ETHTRCV_SID_CHECKWAKEUP 0x0f
#define ETHTRCV_SID_STARTAUTONEGOTIATION 0x05
#define ETHTRCV_SID_TRANSCEIVERLINKSTATEREQUEST 0x17
#define ETHTRCV_SID_GETTRANSCEIVERLINKSTATE 0x06
#define ETHTRCV_SID_GETBAUDRATE 0x07
#define ETHTRCV_SID_GETDUPLEXMODE 0x08
#define ETHTRCV_SID_SETPHYTESTMODE 0x11
#define ETHTRCV_SID_SETPHYLOOPBACKMODE 0x12
#define ETHTRCV_SID_GETPHYSIGNALQUALITY 0x10
#define ETHTRCV_SID_SETPHTTXMODE 0x13
#define ETHTRCV_SID_RUNCABLEDIAGNOSTIC 0x16
#define ETHTRCV_SID_GETRUNCABLEDIAGNOSTICRESULT 0x14
#define ETHTRCV_SID_GETPHYIDENTIFIER 0x15
#define ETHTRCV_SID_GETVERSIONINFO 0x0b

typedef struct {
    sint32 (*phy_init)(uint8 TrcvIdx, const EthTrcvConfigType *config);
    sint32 (*phy_set_mode)(uint8 TrcvIdx, EthTrcv_ModeType mode);
    EthTrcv_ModeType (*phy_get_mode)(uint8 TrcvIdx);
    sint32 (*phy_set_wakeup_mode)(uint8 TrcvIdx, EthTrcv_WakeupModeType mode);
    EthTrcv_WakeupModeType (*phy_get_wakeup_mode)(uint8 TrcvIdx);
    sint32 (*phy_checkwakeup)(uint8 TrcvIdx);
    sint32 (*phy_start_auto_negotiation)(uint8 TrcvIdx);
    sint32 (*phy_link_state_request)(uint8 TrcvIdx, EthTrcv_LinkStateType state);
    EthTrcv_LinkStateType (*phy_get_link_state)(uint8 TrcvIdx);
    EthTrcv_BaudRateType (*phy_get_rate)(uint8 TrcvIdx);
    EthTrcv_DuplexModeType (*phy_get_duplex_mode)(uint8 TrcvIdx);
    sint32 (*phy_set_test_mode)(uint8 TrcvIdx, EthTrcv_PhyTestModeType mode);
    sint32 (*phy_set_loopback_mode)(uint8 TrcvIdx, EthTrcv_PhyLoopbackModeType mode);
    sint32 (*phy_get_signal_quality)(uint8 TrcvIdx);
    sint32 (*phy_set_txmode)(uint8 TrcvIdx, EthTrcv_PhyTxModeType mode);
    sint32(*phy_trigger_cable_diagnostic)(uint8 TrcvIdx);
    EthTrcv_CableDiagResultType (*phy_get_cable_diagnostics_result)(uint8 TrcvIdx);
    sint32 (*phy_get_id)(uint8 TrcvIdx, uint32 *OrgUniqueIdPtr, \
                         uint8 *ModelNrPtr, uint8 *RevisionNrPtr);
} EthTrcv_Ops_Type;

typedef struct {
    EthTrcvConfigType   *Init_Param;
    EthTrcv_ModeType    EthTrcvMode;
    EthTrcv_StateType   EthTrcvState;
    EthTrcv_Ops_Type   *EthTrcvOps;
    uint32          Reserved[5];
} __attribute__((aligned(CACHE_LINE))) EthTransceiverCB_t;


extern VAR(EthTransceiverCB_t,
           ETHTRCV_VAR) gEthTrcv_Transceiver[ETHTRCV_MAXTRCV_SUPPORTED];

/* DET error codes */
#if STD_ON == ETHTRCV_DEV_ERROR_DETECT
/** @implements Eth_DetErrorIds_define */
enum {
    ETHTRCV_E_INV_IDX = 0x01,
    ETHTRCV_E_UNINIT,
    ETHTRCV_E_PARAM_POINTER,
    ETHTRCV_E_INV_PARAM,
    ETHTRCV_E_ACCESS_RES
};
#endif

#define ETHTRCV_STATE(TrcvIdx)     gEthTrcv_Transceiver[TrcvIdx].EthTrcvState
#define ETHTRCV_MODE(TrcvIdx)      gEthTrcv_Transceiver[TrcvIdx].EthTrcvMode
#define ETHTRCV_PHY_ADDR(TrcvIdx)  ((uint8)gEthTrcv_Transceiver[TrcvIdx].Init_Param->PhyAddr)
#define ETHTRCV_CTRL_INDEX(TrcvIdx)  ((uint8)gEthTrcv_Transceiver[TrcvIdx].Init_Param->CtrlIdx)
#define ETHTRCV_OPS(TrcvIdx)    gEthTrcv_Transceiver[TrcvIdx].EthTrcvOps

FUNC(void, ETHTRCV_CODE) EthTrcv_Init
(
    P2CONST(EthTrcv_ConfigType, AUTOMATIC, ETHTRCV_APPL_CONST) CfgPtr
);

FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_SetTransceiverMode
(
    VAR(uint8, AUTOMATIC) TrcvIdx,
    VAR(EthTrcv_ModeType, AUTOMATIC) Mode
);

#if STD_ON ==  ETHTRCV_GET_TRANSCEIVERMODE_API
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_GetTransceiverMode
(
    VAR(uint8, AUTOMATIC) TrcvIdx,
    P2VAR(EthTrcv_ModeType, AUTOMATIC, ETHTRCV_APPL_CONST) Mode
);
#endif

FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_SetTransceiverWakeupMode
(
    VAR(uint8, AUTOMATIC) TrcvIdx,
    VAR(EthTrcv_WakeupModeType, AUTOMATIC) TrcvWakeupMode
);
#if STD_ON ==  ETHTRCV_GET_WAKEUPMODE_API
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_GetTransceiverWakeupMode
(
    VAR(uint8, AUTOMATIC) TrcvIdx,
    P2VAR(EthTrcv_WakeupModeType, AUTOMATIC, ETHTRCV_APPL_CONST) TrcvWakeupModePtr
);
#endif
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_CheckWakeup
(
    VAR(uint8, AUTOMATIC) TrcvIdx
);
#if STD_ON ==  ETHTRCV_SET_STARTAUTONEGOTIA_API
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_StartAutoNegotiation
(
    VAR(uint8, AUTOMATIC) TrcvIdx
);
#endif
#if STD_ON ==  ETHTRCV_GET_LINKSTATE_API
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_TransceiverLinkStateRequest
(
    VAR(uint8, AUTOMATIC) TrcvIdx,
    VAR(EthTrcv_LinkStateType, AUTOMATIC) LinkState
);

FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_GetLinkState
(
    VAR(uint8, AUTOMATIC) TrcvIdx,
    P2VAR(EthTrcv_LinkStateType, AUTOMATIC, ETHTRCV_APPL_CONST) LinkState
);
#endif
#if STD_ON ==  ETHTRCV_GET_BAUDRATE_API
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_GetBaudRate
(
    VAR(uint8, AUTOMATIC) TrcvIdx,
    P2VAR(EthTrcv_BaudRateType, AUTOMATIC, ETHTRCV_APPL_CONST) BaudRatePtr
);
#endif
#if STD_ON ==  ETHTRCV_GET_DUPLEXMODE_API
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_GetDuplexMode
(
    VAR(uint8, AUTOMATIC) TrcvIdx,
    P2VAR(EthTrcv_DuplexModeType, AUTOMATIC, ETHTRCV_APPL_CONST) DuplexModePtr
);
#endif
#if STD_ON ==  ETHTRCV_SET_TESTMODE_API
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_SetPhyTestMode
(
    VAR(uint8, AUTOMATIC) TrcvIdx,
    VAR(EthTrcv_PhyTestModeType, AUTOMATIC) Mode
);
#endif
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_SetPhyLoopbackMode
(
    VAR(uint8, AUTOMATIC) TrcvIdx,
    VAR(EthTrcv_PhyLoopbackModeType, AUTOMATIC) Mode
);
#if STD_ON ==  ETHTRCV_GET_SIGNALQUALITY_API
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_GetPhySignalQuality
(
    VAR(uint8, AUTOMATIC) TrcvIdx,
    P2VAR(uint32, AUTOMATIC, ETHTRCV_APPL_CONST) SignalQualityPtr
);
#endif
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_SetPhyTxMode
(
    VAR(uint8, AUTOMATIC) TrcvIdx,
    VAR(EthTrcv_PhyTxModeType, AUTOMATIC) Mode
);


FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_RunCableDiagnostic
(
    VAR(uint8, AUTOMATIC) TrcvIdx
);

FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_GetCableDiagnosticsResult
(
    VAR(uint8, AUTOMATIC) TrcvIdx,
    P2VAR(EthTrcv_CableDiagResultType, AUTOMATIC, ETHTRCV_APPL_CONST) ResultPtr
);
#if STD_ON ==  ETHTRCV_GET_IDENTIFIER_API
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_GetPhyldentifier
(
    VAR(uint8, AUTOMATIC) TrcvIdx,
    P2VAR(uint32, AUTOMATIC, ETHTRCV_APPL_CONST) OrgUniqueIdPtr,
    P2VAR(uint8, AUTOMATIC, ETHTRCV_APPL_CONST) ModelNrPtr,
    P2VAR(uint8, AUTOMATIC, ETHTRCV_APPL_CONST) RevisionNrPtr
);
#endif
#if STD_ON ==  ETHTRCV_GET_VERSION_API
FUNC(void, ETHTRCV_CODE) EthTrcv_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, ETHTRCV_APPL_CONST) VersionInfoPtr
);
#endif

void EthTrcv_ReadMiiIndication(uint8 CtrlIdx,uint8 TrcvIdx,uint8 RegIdx,uint16 RegVal);
void EthTrcv_WriteMiiIndication(uint8 CtrlIdx,uint8 TrcvIdx,uint8 RegIdx);

#ifdef __cplusplus
}
#endif

#endif
