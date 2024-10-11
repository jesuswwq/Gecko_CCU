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
 * @file  EthTrcv.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL EthTrcv plugins.
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "EthTrcv.h"
#if ETHTRCV_Q21XX_SUPPORTED == STD_ON
#include "q21xx.h"
#endif
#if ETHTRCV_DP83848X_SUPPORTED == STD_ON
#include "dp83848.h"
#endif
#if ETHTRCV_RTL9010X_SUPPORTED == STD_ON
#include "rtl9010x.h"
#endif

#if ETHTRCV_RTL820F_SUPPORTED == STD_ON
#include "rtl820f.h"
#endif

#include "Mcu_Soc.h"

#define ETHTRCV_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "EthTrcv_MemMap.h"

/* Control Block */
VAR(EthTransceiverCB_t, ETHTRCV_VAR) gEthTrcv_Transceiver[ETHTRCV_MAXTRCV_SUPPORTED];

#define ETHTRCV_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "EthTrcv_MemMap.h"

#define ETHTRCV_START_SEC_CONST_UNSPECIFIED
#include "EthTrcv_MemMap.h"

CONSTP2CONST(EthTrcv_Ops_Type, AUTOMATIC, ETHTRCV_APPL_CONST) EthTrcv_Drivers[ETHTRCV_TYPE_MAX] = {
    NULL_PTR,
#if ETHTRCV_Q21XX_SUPPORTED == STD_ON
    &marvell_q21xx_ops,
#endif
#if ETHTRCV_DP83848X_SUPPORTED == STD_ON
    &dp83848xx_ops,
#endif
#if ETHTRCV_RTL9010X_SUPPORTED == STD_ON
    &rtl9010x_ops,
#endif
#if ETHTRCV_RTL820F_SUPPORTED == STD_ON
    &rtl820f_ops,
#endif
};

#define ETHTRCV_STOP_SEC_CONST_UNSPECIFIED
#include "EthTrcv_MemMap.h"

#define ETHTRCV_START_SEC_CODE
#include "EthTrcv_MemMap.h"

#if STD_ON == ETHTRCV_DEV_ERROR_DETECT
LOCAL_INLINE FUNC(Std_ReturnType, ETH_CODE) EthTrcv_CheckCurCoreCanAccess(uint8 TrcvIdx)
{
    uint8 idx;
    Std_ReturnType ret = E_OK;
    uint8 Core = Mcu_GetCoreID();

    if (EthTrcv_Config.EthTrcvCoreConfig[Core]) {
        for (idx = 0 ; idx < EthTrcv_Config.EthTrcvCoreConfig[Core]->EthTrcvCount; idx++) {
            if (EthTrcv_Config.EthTrcvCoreConfig[Core]->EthTrcvConfigPtr[idx].TrcvIdx == TrcvIdx)
                break;
        }

        if (EthTrcv_Config.EthTrcvCoreConfig[Core]->EthTrcvCount <= idx) {
            ret = E_NOT_OK;
        }
    } else {
        ret = E_NOT_OK;
    }

    return ret;
}
#endif
static inline Std_ReturnType EthTrcv_Det_Check(uint8 TrcvIdx, uint8 Sid)
{
    Std_ReturnType RetVal = E_OK;
#if STD_ON == ETHTRCV_DEV_ERROR_DETECT

    if (EthTrcv_CheckCurCoreCanAccess(TrcvIdx) != E_OK) {

        (void)Det_ReportError ( \
                                (VAR(uint8, AUTOMATIC)) ETHTRCV_MODULE_ID, \
                                ETHTRCV_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                                Sid, ETHTRCV_E_ACCESS_RES \
                              );
        RetVal = E_NOT_OK;
    }

#endif /* ETHTRCV_DEV_ERROR_DETECT  */

    if (TrcvIdx >= (VAR(uint8, AUTOMATIC))ETHTRCV_MAXTRCV_SUPPORTED) {
#if STD_ON == ETHTRCV_DEV_ERROR_DETECT
        (void)Det_ReportError ( \
                                (VAR(uint8, AUTOMATIC)) ETHTRCV_MODULE_ID, \
                                ETHTRCV_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                                Sid, ETHTRCV_E_INV_IDX \
                              );
#endif /* ETHTRCV_DEV_ERROR_DETECT  */
        RetVal = E_NOT_OK;
    } else if (ETHTRCV_STATE_INIT != ETHTRCV_STATE(TrcvIdx)) {
#if STD_ON == ETHTRCV_DEV_ERROR_DETECT
        (void)Det_ReportError ( \
                                (VAR(uint8, AUTOMATIC)) ETHTRCV_MODULE_ID, \
                                ETHTRCV_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                                Sid, ETHTRCV_E_UNINIT \
                              );
#endif /* ETHTRCV_DEV_ERROR_DETECT  */
        RetVal = E_NOT_OK;
    }

    return RetVal;
}

/**
* @brief  Init the Controller priv data
*/
static FUNC(void, ETH_CODE) EthTrcv_Init_CtrlData
(
    VAR(uint8, AUTOMATIC) TrcvIdx,
    P2CONST(EthTrcvConfigType, AUTOMATIC, ETHTRCV_APPL_CONST) CfgPtr
)
{
    gEthTrcv_Transceiver[TrcvIdx].Init_Param = (EthTrcvConfigType *)CfgPtr;
    /* Not Support phy type use ETHTRCV_TYPE_MAX as type */
    gEthTrcv_Transceiver[TrcvIdx].EthTrcvOps = (EthTrcv_Ops_Type *)EthTrcv_Drivers[CfgPtr->phy_type];
}
/*
*/
FUNC(void, ETHTRCV_CODE) EthTrcv_Init
(
    P2CONST(EthTrcv_ConfigType, AUTOMATIC, ETHTRCV_APPL_CONST) CfgPtr
)
{

    VAR(uint8, AUTOMATIC)  TrcvIdx = 0U;
    VAR(uint8, AUTOMATIC)  CoreId = 0U;
    P2CONST(EthTrcvConfigType, AUTOMATIC, ETHTRCV_APPL_CONST) TrcvCfgPtr;
    P2CONST(EthTrcv_CoreConfigType, AUTOMATIC, ETHTRCV_APPL_CONST) CoreCfgPtr;



    if (NULL_PTR == CfgPtr) {
#if STD_ON == ETHTRCV_DEV_ERROR_DETECT
        (void)Det_ReportError ( \
                                (VAR(uint8, AUTOMATIC)) ETHTRCV_MODULE_ID, \
                                ETHTRCV_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) ETHTRCV_SID_INIT, \
                                ETHTRCV_E_PARAM_POINTER \
                              );
#endif /* ETHTRCV_DEV_ERROR_DETECT  */
    } else {
        CoreId = Mcu_GetCoreID();

        CoreCfgPtr = CfgPtr->EthTrcvCoreConfig[CoreId];

        for (TrcvIdx = 0; TrcvIdx < CoreCfgPtr->EthTrcvCount; TrcvIdx++) {

            TrcvCfgPtr = &CoreCfgPtr->EthTrcvConfigPtr[TrcvIdx];

            EthTrcv_Init_CtrlData(TrcvCfgPtr->TrcvIdx, TrcvCfgPtr);

            EthTrcv_Ops_Type *phy_ops = ETHTRCV_OPS(TrcvCfgPtr->TrcvIdx);

            if (phy_ops && phy_ops->phy_init &&
                        (E_OK == phy_ops->phy_init(TrcvCfgPtr->TrcvIdx, TrcvCfgPtr))) {
                ETHTRCV_STATE(TrcvCfgPtr->TrcvIdx) = ETHTRCV_STATE_INIT;
            } else {
                ETHTRCV_STATE(TrcvCfgPtr->TrcvIdx) = ETHTRCV_STATE_UNINIT;
            }
        }
    }
}
/*
*/
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_SetTransceiverMode
(
    VAR(uint8, AUTOMATIC) TrcvIdx,
    VAR(EthTrcv_ModeType, AUTOMATIC) Mode
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;

    RetVal = EthTrcv_Det_Check(TrcvIdx, ETHTRCV_SID_SETTRANSCEIVERMODE);

    if (RetVal == E_OK) {
        EthTrcv_Ops_Type *phy_ops = ETHTRCV_OPS(TrcvIdx);

        if (phy_ops && phy_ops->phy_set_mode && !phy_ops->phy_set_mode(TrcvIdx, Mode)) {
            ETHTRCV_MODE(TrcvIdx) = Mode;
        } else {
            RetVal =  E_NOT_OK;
        }
    }

    return RetVal;
}
#if STD_ON == ETHTRCV_GET_TRANSCEIVERMODE_API
/*
*/
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_GetTransceiverMode
(
    VAR(uint8, AUTOMATIC) TrcvIdx,
    P2VAR(EthTrcv_ModeType, AUTOMATIC, ETHTRCV_APPL_CONST) Mode
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;
    RetVal = EthTrcv_Det_Check(TrcvIdx, ETHTRCV_SID_GETTRANSCEIVERMODE);

    if (RetVal == E_OK) {
        if (Mode == NULL_PTR) {
#if STD_ON == ETHTRCV_DEV_ERROR_DETECT
            (void)Det_ReportError (
                (VAR(uint8, AUTOMATIC)) ETHTRCV_MODULE_ID,
                ETHTRCV_DRIVER_INSTANCE,
                (VAR(uint8, AUTOMATIC)) ETHTRCV_SID_GETTRANSCEIVERMODE,
                ETHTRCV_E_PARAM_POINTER
            );
#endif /* ETHTRCV_DEV_ERROR_DETECT  */
            RetVal = E_NOT_OK;
        } else {
            EthTrcv_Ops_Type *phy_ops = ETHTRCV_OPS(TrcvIdx);

            if (phy_ops && phy_ops->phy_get_mode) {
                *Mode = phy_ops->phy_get_mode(TrcvIdx);
            } else {
                *Mode = ETHTRCV_MODE(TrcvIdx);
            }
        }
    }

    return RetVal;
}
#endif
/*
*/
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_SetTransceiverWakeupMode
(
    VAR(uint8, AUTOMATIC) TrcvIdx,
    VAR(EthTrcv_WakeupModeType, AUTOMATIC) TrcvWakeupMode
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;

    RetVal = EthTrcv_Det_Check(TrcvIdx, ETHTRCV_SID_SETTRANSCEIVERWAKEUPMODE);

    if (RetVal == E_OK) {
        // 1.0900 3.0000
        EthTrcv_Ops_Type *phy_ops = ETHTRCV_OPS(TrcvIdx);

        if (NULL_PTR == phy_ops || NULL_PTR ==  phy_ops->phy_set_wakeup_mode || \
            phy_ops->phy_set_wakeup_mode(TrcvIdx, TrcvWakeupMode)) {
            RetVal = E_NOT_OK;
        }
    }

    return RetVal;
}
#if STD_ON == ETHTRCV_GET_WAKEUPMODE_API
/*
*/
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_GetTransceiverWakeupMode
(
    VAR(uint8, AUTOMATIC) TrcvIdx,
    P2VAR(EthTrcv_WakeupModeType, AUTOMATIC, ETHTRCV_APPL_CONST) TrcvWakeupModePtr
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;
    RetVal = EthTrcv_Det_Check(TrcvIdx, ETHTRCV_SID_GETTRANSCEIVERWAKEUPMODE);

    if (RetVal == E_OK) {
        if (TrcvWakeupModePtr == NULL_PTR) {
#if STD_ON == ETHTRCV_DEV_ERROR_DETECT
            (void)Det_ReportError (
                (VAR(uint8, AUTOMATIC)) ETHTRCV_MODULE_ID,
                ETHTRCV_DRIVER_INSTANCE,
                (VAR(uint8, AUTOMATIC)) ETHTRCV_SID_GETTRANSCEIVERWAKEUPMODE,
                ETHTRCV_E_PARAM_POINTER
            );
#endif /* ETHTRCV_DEV_ERROR_DETECT  */
            RetVal = E_NOT_OK;
        } else {
            EthTrcv_Ops_Type *phy_ops = ETHTRCV_OPS(TrcvIdx);

            if (phy_ops && phy_ops->phy_get_wakeup_mode) {
                *TrcvWakeupModePtr = phy_ops->phy_get_wakeup_mode(TrcvIdx);
            } else {
                ret = E_NOT_OK;
            }
        }
    }

    return RetVal;
}
#endif
/**
 * @description:
 * @param  {*}
 * @return {*}
 */
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_CheckWakeup
(
    VAR(uint8, AUTOMATIC) TrcvIdx
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;
    RetVal = EthTrcv_Det_Check(TrcvIdx, ETHTRCV_SID_CHECKWAKEUP);

    if (RetVal == E_OK) {
        EthTrcv_Ops_Type *phy_ops = ETHTRCV_OPS(TrcvIdx);

        if (NULL_PTR == phy_ops || NULL_PTR == phy_ops->phy_checkwakeup ||
            phy_ops->phy_checkwakeup(TrcvIdx)) {
            RetVal = E_NOT_OK;
        }
    }

    return RetVal;
}
#if STD_ON == ETHTRCV_SET_STARTAUTONEGOTIA_API
/**
 * @description:
 * @param  {*}
 * @return {*}
 */
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_StartAutoNegotiation
(
    VAR(uint8, AUTOMATIC) TrcvIdx
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;
    RetVal = EthTrcv_Det_Check(TrcvIdx, ETHTRCV_SID_STARTAUTONEGOTIATION);

    if (RetVal == E_OK) {
        EthTrcv_Ops_Type *phy_ops = ETHTRCV_OPS(TrcvIdx);

        if (!phy_ops || !phy_ops->phy_start_auto_negotiation || \
            phy_ops->phy_start_auto_negotiation(TrcvIdx)) {
            RetVal = E_NOT_OK;
        }
    }

    return RetVal;
}
#endif
#if STD_ON == ETHTRCV_GET_LINKSTATE_API
/**
 * @description:
 * @param  {*}
 * @return {*}
 */
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_TransceiverLinkStateRequest
(
    VAR(uint8, AUTOMATIC) TrcvIdx,
    VAR(EthTrcv_LinkStateType, AUTOMATIC) LinkState
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;
    RetVal = EthTrcv_Det_Check(TrcvIdx, ETHTRCV_SID_TRANSCEIVERLINKSTATEREQUEST);

    if (RetVal == E_OK) {
        EthTrcv_Ops_Type *phy_ops = ETHTRCV_OPS(TrcvIdx);

        if (NULL_PTR == phy_ops || NULL_PTR == phy_ops->phy_link_state_request || \
            phy_ops->phy_link_state_request(TrcvIdx, LinkState)) {
            RetVal = E_NOT_OK;
        }
    }

    return RetVal;
}
/*
*/
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_GetLinkState
(
    VAR(uint8, AUTOMATIC) TrcvIdx,
    P2VAR(EthTrcv_LinkStateType, AUTOMATIC, ETHTRCV_APPL_CONST) LinkState
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;
    RetVal = EthTrcv_Det_Check(TrcvIdx, ETHTRCV_SID_GETTRANSCEIVERLINKSTATE);

    if (RetVal == E_OK) {
        if (LinkState == NULL_PTR) {
#if STD_ON == ETHTRCV_DEV_ERROR_DETECT
            (void)Det_ReportError (
                (VAR(uint8, AUTOMATIC)) ETHTRCV_MODULE_ID,
                ETHTRCV_DRIVER_INSTANCE,
                (VAR(uint8, AUTOMATIC)) ETHTRCV_SID_GETTRANSCEIVERLINKSTATE,
                ETHTRCV_E_PARAM_POINTER
            );
#endif /* ETHTRCV_DEV_ERROR_DETECT  */
            RetVal = E_NOT_OK;
        } else {
            EthTrcv_Ops_Type *phy_ops = ETHTRCV_OPS(TrcvIdx);

            if (phy_ops && phy_ops->phy_get_link_state) {
                *LinkState = phy_ops->phy_get_link_state(TrcvIdx);
            } else {
                RetVal = E_NOT_OK;
            }
        }
    }

    return RetVal;
}
#endif

#if STD_ON == ETHTRCV_GET_BAUDRATE_API
/*
*/
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_GetBaudRate
(
    VAR(uint8, AUTOMATIC) TrcvIdx,
    P2VAR(EthTrcv_BaudRateType, AUTOMATIC, ETHTRCV_APPL_CONST) BaudRatePtr
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;
    RetVal = EthTrcv_Det_Check(TrcvIdx, ETHTRCV_SID_GETBAUDRATE);

    if (RetVal == E_OK) {
        if (BaudRatePtr == NULL_PTR) {
#if STD_ON == ETHTRCV_DEV_ERROR_DETECT
            (void)Det_ReportError (
                (VAR(uint8, AUTOMATIC)) ETHTRCV_MODULE_ID,
                ETHTRCV_DRIVER_INSTANCE,
                (VAR(uint8, AUTOMATIC)) ETHTRCV_SID_GETBAUDRATE,
                ETHTRCV_E_PARAM_POINTER
            );
#endif /* ETHTRCV_DEV_ERROR_DETECT  */
            RetVal = E_NOT_OK;
        } else {
            EthTrcv_Ops_Type *phy_ops = ETHTRCV_OPS(TrcvIdx);

            if (phy_ops && phy_ops->phy_get_rate) {
                *BaudRatePtr = phy_ops->phy_get_rate(TrcvIdx);
            } else {
                RetVal = E_NOT_OK;
            }
        }
    }

    return RetVal;
}
#endif

#if STD_ON == ETHTRCV_GET_DUPLEXMODE_API
/*
*/
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_GetDuplexMode
(
    VAR(uint8, AUTOMATIC) TrcvIdx,
    P2VAR(EthTrcv_DuplexModeType, AUTOMATIC, ETHTRCV_APPL_CONST) DuplexModePtr
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;
    RetVal = EthTrcv_Det_Check(TrcvIdx, ETHTRCV_SID_GETDUPLEXMODE);

    if (RetVal == E_OK) {
        if (DuplexModePtr == NULL_PTR) {
#if STD_ON == ETHTRCV_DEV_ERROR_DETECT
            (void)Det_ReportError (
                (VAR(uint8, AUTOMATIC)) ETHTRCV_MODULE_ID,
                ETHTRCV_DRIVER_INSTANCE,
                (VAR(uint8, AUTOMATIC)) ETHTRCV_SID_GETDUPLEXMODE,
                ETHTRCV_E_PARAM_POINTER
            );
#endif /* ETHTRCV_DEV_ERROR_DETECT  */
            RetVal = E_NOT_OK;
        } else {
            EthTrcv_Ops_Type *phy_ops = ETHTRCV_OPS(TrcvIdx);

            if (phy_ops && phy_ops->phy_get_duplex_mode) {
                *DuplexModePtr = phy_ops->phy_get_duplex_mode(TrcvIdx);
            } else {
                RetVal = E_NOT_OK;
            }
        }
    }

    return RetVal;
}
#endif
#if STD_ON == ETHTRCV_SET_TESTMODE_API
/*
*/
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_SetPhyTestMode
(
    VAR(uint8, AUTOMATIC) TrcvIdx,
    VAR(EthTrcv_PhyTestModeType, AUTOMATIC) Mode
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;
    RetVal = EthTrcv_Det_Check(TrcvIdx, ETHTRCV_SID_SETPHYTESTMODE);

    if (RetVal == E_OK) {
        EthTrcv_Ops_Type *phy_ops = ETHTRCV_OPS(TrcvIdx);

        if (NULL_PTR == phy_ops || NULL_PTR == phy_ops->phy_set_test_mode || \
            phy_ops->phy_set_test_mode(TrcvIdx, Mode)) {
            RetVal = E_NOT_OK;
        }
    }

    return RetVal;
}
#endif
/*
*/
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_SetPhyLoopbackMode
(
    VAR(uint8, AUTOMATIC) TrcvIdx,
    VAR(EthTrcv_PhyLoopbackModeType, AUTOMATIC) Mode
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;
    RetVal = EthTrcv_Det_Check(TrcvIdx, ETHTRCV_SID_SETPHYLOOPBACKMODE);

    if (RetVal == E_OK) {
        EthTrcv_Ops_Type *phy_ops = ETHTRCV_OPS(TrcvIdx);

        if (NULL_PTR == phy_ops || NULL_PTR == phy_ops->phy_set_loopback_mode || \
            phy_ops->phy_set_loopback_mode(TrcvIdx, Mode)) {
            RetVal = E_NOT_OK;
        }
    }

    return RetVal;
}

#if STD_ON == ETHTRCV_GET_SIGNALQUALITY_API
/*
*/
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_GetPhySignalQuality
(
    VAR(uint8, AUTOMATIC) TrcvIdx,
    P2VAR(uint32, AUTOMATIC, ETHTRCV_APPL_CONST) SignalQualityPtr
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;
    RetVal = EthTrcv_Det_Check(TrcvIdx, ETHTRCV_SID_GETPHYSIGNALQUALITY);

    if (RetVal == E_OK) {
        if (SignalQualityPtr == NULL_PTR) {
#if STD_ON == ETHTRCV_DEV_ERROR_DETECT
            (void)Det_ReportError (
                (VAR(uint8, AUTOMATIC)) ETHTRCV_MODULE_ID,
                ETHTRCV_DRIVER_INSTANCE,
                (VAR(uint8, AUTOMATIC)) ETHTRCV_SID_GETPHYSIGNALQUALITY,
                ETHTRCV_E_PARAM_POINTER
            );
#endif /* ETHTRCV_DEV_ERROR_DETECT  */
            RetVal = E_NOT_OK;
        } else {
            EthTrcv_Ops_Type *phy_ops = ETHTRCV_OPS(TrcvIdx);

            if (phy_ops && phy_ops->phy_get_signal_quality) {
                *SignalQualityPtr = phy_ops->phy_get_signal_quality(TrcvIdx);
            } else {
                RetVal = E_NOT_OK;
            }
        }
    }

    return RetVal;
}
#endif
/*
*/
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_SetPhyTxMode
(
    VAR(uint8, AUTOMATIC) TrcvIdx,
    VAR(EthTrcv_PhyTxModeType, AUTOMATIC) Mode
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;
    RetVal = EthTrcv_Det_Check(TrcvIdx, ETHTRCV_SID_SETPHTTXMODE);

    if (RetVal == E_OK) {
        EthTrcv_Ops_Type *phy_ops = ETHTRCV_OPS(TrcvIdx);

        if (NULL_PTR == phy_ops || NULL_PTR == phy_ops->phy_set_txmode || \
            phy_ops->phy_set_txmode(TrcvIdx, Mode)) {
            RetVal = E_NOT_OK;
        }
    }

    return RetVal;
}
/*
*/
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_RunCableDiagnostic
(
    VAR(uint8, AUTOMATIC) TrcvIdx
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;
    RetVal = EthTrcv_Det_Check(TrcvIdx, ETHTRCV_SID_RUNCABLEDIAGNOSTIC);

    if (RetVal == E_OK) {
        EthTrcv_Ops_Type *phy_ops = ETHTRCV_OPS(TrcvIdx);

        if (NULL_PTR == phy_ops || NULL_PTR == phy_ops->phy_trigger_cable_diagnostic || \
            phy_ops->phy_trigger_cable_diagnostic(TrcvIdx)) {
            RetVal = E_NOT_OK;
        }
    }

    return RetVal;
}
/*
*/
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_GetCableDiagnosticsResult
(
    VAR(uint8, AUTOMATIC) TrcvIdx,
    P2VAR(EthTrcv_CableDiagResultType, AUTOMATIC, ETHTRCV_APPL_CONST) ResultPtr
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;
    RetVal = EthTrcv_Det_Check(TrcvIdx, ETHTRCV_SID_GETRUNCABLEDIAGNOSTICRESULT);

    if (RetVal == E_OK) {
        if (ResultPtr == NULL_PTR) {
#if STD_ON == ETHTRCV_DEV_ERROR_DETECT
            (void)Det_ReportError (
                (VAR(uint8, AUTOMATIC)) ETHTRCV_MODULE_ID,
                ETHTRCV_DRIVER_INSTANCE,
                (VAR(uint8, AUTOMATIC)) ETHTRCV_SID_GETRUNCABLEDIAGNOSTICRESULT,
                ETHTRCV_E_PARAM_POINTER
            );
#endif /* ETHTRCV_DEV_ERROR_DETECT  */
            RetVal = E_NOT_OK;
        } else {
            EthTrcv_Ops_Type *phy_ops = ETHTRCV_OPS(TrcvIdx);

            if (phy_ops && phy_ops->phy_get_cable_diagnostics_result) {
                *ResultPtr = phy_ops->phy_get_cable_diagnostics_result(TrcvIdx);
            } else {
                RetVal = E_NOT_OK;
            }
        }
    }

    return RetVal;
}
#if STD_ON == ETHTRCV_GET_IDENTIFIER_API
/*
*/
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_GetPhyldentifier
(
    VAR(uint8, AUTOMATIC) TrcvIdx,
    P2VAR(uint32, AUTOMATIC, ETHTRCV_APPL_CONST) OrgUniqueIdPtr,
    P2VAR(uint8, AUTOMATIC, ETHTRCV_APPL_CONST) ModelNrPtr,
    P2VAR(uint8, AUTOMATIC, ETHTRCV_APPL_CONST) RevisionNrPtr
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = E_OK;
    RetVal = EthTrcv_Det_Check(TrcvIdx, ETHTRCV_SID_GETPHYIDENTIFIER);

    if (RetVal == E_OK) {
        if (OrgUniqueIdPtr == NULL_PTR || ModelNrPtr == NULL_PTR ||  RevisionNrPtr == NULL_PTR) {
#if STD_ON == ETHTRCV_DEV_ERROR_DETECT
            (void)Det_ReportError (
                (VAR(uint8, AUTOMATIC)) ETHTRCV_MODULE_ID,
                ETHTRCV_DRIVER_INSTANCE,
                (VAR(uint8, AUTOMATIC)) ETHTRCV_SID_GETPHYIDENTIFIER,
                ETHTRCV_E_PARAM_POINTER
            );
#endif /* ETHTRCV_DEV_ERROR_DETECT  */
            RetVal = E_NOT_OK;
        } else {
            EthTrcv_Ops_Type *phy_ops = ETHTRCV_OPS(TrcvIdx);

            if (phy_ops && phy_ops->phy_get_id) {
                phy_ops->phy_get_id(TrcvIdx, OrgUniqueIdPtr, ModelNrPtr, RevisionNrPtr);
            } else {
                RetVal = E_NOT_OK;
            }
        }
    }

    return RetVal;
}
#endif

#if STD_ON == ETHTRCV_GET_VERSION_API
/*
*/
FUNC(void, ETHTRCV_CODE) EthTrcv_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, ETHTRCV_APPL_CONST) VersionInfoPtr
)
{
    if (NULL_PTR == VersionInfoPtr) {
#if STD_ON == ETHTRCV_DEV_ERROR_DETECT
        (void)Det_ReportError ( \
                                (VAR(uint8, AUTOMATIC)) ETHTRCV_MODULE_ID, ETHTRCV_DRIVER_INSTANCE, \
                                (VAR(uint8, AUTOMATIC)) ETHTRCV_SID_GETVERSIONINFO, \
                                ETHTRCV_E_PARAM_POINTER \
                              );
#endif /* ETHTRCV_DEV_ERROR_DETECT */
    } else {
        VersionInfoPtr->vendorID = ETHTRCV_VENDOR_ID;
        VersionInfoPtr->moduleID = ETHTRCV_MODULE_ID;
        VersionInfoPtr->sw_major_version = ETHTRCV_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = ETHTRCV_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = ETHTRCV_SW_PATCH_VERSION;
    }
}
#endif

void EthTrcv_ReadMiiIndication(uint8 CtrlIdx,uint8 TrcvIdx,uint8 RegIdx,uint16 RegVal)
{

}
void EthTrcv_WriteMiiIndication(uint8 CtrlIdx,uint8 TrcvIdx,uint8 RegIdx)
{

}

#define ETHTRCV_STOP_SEC_CODE
#include "EthTrcv_MemMap.h"

#ifdef __cplusplus
}
#endif
