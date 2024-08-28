/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2022)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : CanIf.c                                                     **
**                                                                            **
**  Created on  :                                                             **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Implementation for CANIF                                    **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      REVISION   HISTORY                                    **
*******************************************************************************/
/* <VERSION>  <DATE>    <AUTHOR>      <REVISION LOG>
 *  V2.0.0    20200217  zhengfei.li   Initial version
 *  (Upgrade according to the R19_11 standards)
 *  V2.0.1    20210408  zhengfei.li   Optimize wake-up source detection,
 *  Modify the bug of API CanIf_CheckTrcvWakeFlag when the DET is STD_OFF.
 *  V2.0.2    20230526  tong.zhao     fix Bug CPT-459
 *    Modify the bug of invalid address access in API CanIf_RxIndicationHandle,
 *    when meta is not support and ReadRxPdu is support.
 *  V2.0.3    20230825  tong.zhao     fix Bug CPT-6391
 *    In order to optimize the code execution efficiency, modify.
 ******************************************************************************/

/**
  \page ISOFT_MISRA_Exceptions  MISRA-C:2012 Compliance Exceptions
    ModeName:CanIf<br>
  RuleSorce:puhua-rule.rcf 2.3.1

    \li PRQA S 3432 MISRA Rule 20.7 .<br>
    Reason:Function-like macros are used to allow more efficient code.

    \li PRQA S 1532 MISRA Rule 8.7 .<br>
    Reason:In order to make the module code structure clear, the functions are classified.

    \li PRQA S 2992 MISRA Rule 14.3 .<br>
    Reason:variant "controllerNotSleep" may be different in other Configuration projects.

    \li PRQA S 2996 MISRA Rule 2.2 .<br>
    Reason:The assessment has no effect, but is reserved for better readability.

    \li PRQA S 2880 MISRA Rule 2.1.<br>
    Reason:Storage mapping design is required.
 */

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "CanIf_Cbk.h"
#include "SchM_CanIf.h"
#if (STD_ON == CANIF_PUBLIC_ICOM_SUPPORT)
#include "CanSM_Cbk.h"
#endif
#include "Det.h"
#include "CanIf_DiagRoute.h"
#include "BswM_Check_Action.h"
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
#define CANIF_C_AR_MAJOR_VERSION 4u
#define CANIF_C_AR_MINOR_VERSION 2u
#define CANIF_C_AR_PATCH_VERSION 2u
#define CANIF_C_SW_MAJOR_VERSION 2u
#define CANIF_C_SW_MINOR_VERSION 0u
#define CANIF_C_SW_PATCH_VERSION 3u
/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/
#if (CANIF_C_AR_MAJOR_VERSION != CANIF_H_AR_MAJOR_VERSION)
#error "CanIf.c:Mismatch in Specification Major Version"
#endif

#if (CANIF_C_AR_MINOR_VERSION != CANIF_H_AR_MINOR_VERSION)
#error "CanIf.c:Mismatch in Specification Minor Version"
#endif

#if (CANIF_C_AR_PATCH_VERSION != CANIF_H_AR_PATCH_VERSION)
#error "CanIf.c:Mismatch in Specification Patch Version"
#endif

#if (CANIF_C_SW_MAJOR_VERSION != CANIF_H_SW_MAJOR_VERSION)
#error "CanIf.c:Mismatch in Specification Major Version"
#endif

#if (CANIF_C_SW_MINOR_VERSION != CANIF_H_SW_MINOR_VERSION)
#error "CanIf.c:Mismatch in Specification Minor Version"
#endif

#if (CANIF_C_SW_PATCH_VERSION != CANIF_H_SW_PATCH_VERSION)
#error "CanIf.c:Mismatch in Specification Patch Version"
#endif

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define CANIF_TXPDU(TxPdu_Index)            CanIf_ConfigStd->CanIfTxPduConfigRef[(TxPdu_Index)]
#define CANIF_TXBUFFER_SIZE(TxBuffer_Index) CanIf_ConfigStd->CanIfBufferSize[(TxBuffer_Index)]
#define CANIF_CONTROLLER(Controller_Index)  CanIf_ConfigStd->CanIfCtrlConfigRef[(Controller_Index)]
#define CANIF_HTH(Hth_Index)                CanIf_ConfigStd->CanIfInitHohConfigRef->CanIfHthCfgRef[(Hth_Index)]
#define CANIF_RXPDU(RxPdu_Index)            CanIf_ConfigStd->CanIfRxPduConfigRef[(RxPdu_Index)]
#define CANIF_HRH(Hrh_Index)                CanIf_ConfigStd->CanIfInitHohConfigRef->CanIfHrhCfgRef[(Hrh_Index)]
#define CANIF_TRCV(Trcv_Index)              CanIf_ConfigStd->CanIfTrcvConfigRef[(Trcv_Index)]

#if (LOW_BYTE_FIRST == CPU_BYTE_ORDER)
#define CANIF_METADATATOCANID(CanId, MetaDataPtr)                              \
    CanId =                                                                    \
        ((Can_IdType)(MetaDataPtr[0u]) | ((Can_IdType)(MetaDataPtr[1u]) << 8u) \
         | ((Can_IdType)(MetaDataPtr[2u]) << 16u) | ((Can_IdType)(MetaDataPtr[3u]) << 24u))

#define CANIF_CANIDTOMETADATA(CanId, MetaDataPtr) \
    do                                            \
    {                                             \
        MetaDataPtr[0u] = (uint8)(CanId);         \
        MetaDataPtr[1u] = (uint8)(CanId >> 8u);   \
        MetaDataPtr[2u] = (uint8)(CanId >> 16u);  \
        MetaDataPtr[3u] = (uint8)(CanId >> 24u);  \
    } while (0)
#else
#define CANIF_METADATATOCANID(CanId, MetaDataPtr)                                        \
    CanId =                                                                              \
        (((Can_IdType)(MetaDataPtr[0u]) << 24u) | ((Can_IdType)(MetaDataPtr[1u]) << 16u) \
         | ((Can_IdType)(MetaDataPtr[2u]) << 8u) | (Can_IdType)(MetaDataPtr[3u]))

#define CANIF_CANIDTOMETADATA(CanId, MetaDataPtr) \
    do                                            \
    {                                             \
        MetaDataPtr[0u] = (uint8)(CanId >> 24u);  \
        MetaDataPtr[1u] = (uint8)(CanId >> 16u);  \
        MetaDataPtr[2u] = (uint8)(CanId >> 8u);   \
        MetaDataPtr[3u] = (uint8)(CanId);         \
    } while (0)
#endif
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/* Canif init status, at first define it as CANIF_UNINIT */
#define CANIF_START_SEC_VAR_INIT_8
#include "CanIf_MemMap.h"
static VAR(CanIf_InitStatusType, CANIF_VAR_POWER_ON_INIT) CanIf_InitStatus = CANIF_UNINIT;
#define CANIF_STOP_SEC_VAR_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_INIT_PTR
#include "CanIf_MemMap.h"
static P2CONST(CanIf_ConfigType, CANIF_VAR, CANIF_CONST) CanIf_ConfigStd = NULL_PTR;
#define CANIF_STOP_SEC_VAR_INIT_PTR
#include "CanIf_MemMap.h"

/* define Tx notification status and Rx notification status*/
#if (CANIF_TXNOTIFYSTATUS_BUFFER > 0u)
#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static VAR(CanIf_NotifStatusType, CANIF_VAR) CanIf_TxNotifStatus[CANIF_TXNOTIFYSTATUS_BUFFER];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
#endif

#if (CANIF_RXNOTIFYSTATUS_BUFFER > 0u)
#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static VAR(CanIf_NotifStatusType, CANIF_VAR) CanIf_RxNotifStatus[CANIF_RXNOTIFYSTATUS_BUFFER];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
#endif

#if (STD_ON == CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT)
#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static VAR(CanIf_NotifStatusType, CANIF_VAR) CanIf_TxConfirmationState[CANIF_CANCONTROLLER_NUMBER];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
#endif

#if (CANIF_DYNAMIC_TXPDU_NUMBER > 0u)
#define CANIF_START_SEC_VAR_NO_INIT_32
#include "CanIf_MemMap.h"
static VAR(Can_IdType, CANIF_VAR) CanIf_TxPduDynamicCanIds[CANIF_DYNAMIC_TXPDU_NUMBER];
#define CANIF_STOP_SEC_VAR_NO_INIT_32
#include "CanIf_MemMap.h"
#endif

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static VAR(CanIf_PduModeType, CANIF_VAR) CanIf_PduMode[CANIF_CANCONTROLLER_NUMBER];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static VAR(CanIf_ControllerModeType, CANIF_VAR) CanIf_ControllerMode[CANIF_CANCONTROLLER_NUMBER];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#if (STD_ON == CANIF_PUBLIC_PN_SUPPORT)
#define CANIF_START_SEC_VAR_NO_INIT_BOOLEAN
#include "CanIf_MemMap.h"
static VAR(boolean, CANIF_VAR) CanIf_PnTxFilter[CANIF_CANCONTROLLER_NUMBER];
#define CANIF_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "CanIf_MemMap.h"
#endif

// #if (STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALID_SUPPORT)
// #define CANIF_START_SEC_VAR_NO_INIT_BOOLEAN
// #include "CanIf_MemMap.h"
// static VAR(boolean, CANIF_VAR) CanIf_FirstCallRxInd[CANIF_CANCONTROLLER_NUMBER];
// #define CANIF_STOP_SEC_VAR_NO_INIT_BOOLEAN
// #include "CanIf_MemMap.h"
// #endif
VAR(boolean, CANIF_VAR) CanIf_FirstCallRxInd[CANIF_CANCONTROLLER_NUMBER];
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
static FUNC(void, CANIF_CODE) CanIf_FreeBufInStopped(uint8 Controller);

static FUNC(void, CANIF_CODE) CanIf_InitAllBuffer(VAR(void, AUTOMATIC));

#if (CANIF_DYNAMIC_TXPDU_NUMBER > 0u)
static FUNC(void, CANIF_CODE) CanIf_InitDynamicTxPduCanIds(uint8 Controller);
#endif

static FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetControllStarted(uint8 Controller);

static FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetControllSleep(uint8 Controller);

static FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetControllStopped(uint8 Controller);

static FUNC(void, CANIF_CODE) CanIf_PduPack(
    PduIdType CanTxPduId,
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(Can_PduType, AUTOMATIC, AUTOMATIC) canPdu);
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */

#if (CANIF_TXBUFFER_NUMBER > 0u)
static FUNC(void, CANIF_CODE) CanIf_FreeControllerTxBuffer(uint8 Controller);

static FUNC(Std_ReturnType, CANIF_CODE) CanIf_TxBusyHandle(P2CONST(Can_PduType, AUTOMATIC, CANIF_APPL_DATA) pduPtr);
#endif /*(CANIF_TXBUFFER_NUMBER > 0u)*/

#if (                                                            \
    (0u < CANIF_RXBUFFER_NUMBER) || (0u < CANIF_TXBUFFER_NUMBER) \
    || ((STD_OFF == CANIF_RXINDICATION_AUTOSAR_PARAMETER) && (STD_ON == CANIF_META_DATA_SUPPORT)))
/* Memcpy for CanIf Mode used */
static FUNC(void, CANIF_CODE) CanIf_Memcpy(
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, CANIF_APPL_DATA) dest,
    /* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
    P2CONST(uint8, AUTOMATIC, CANIF_APPL_DATA) source,
    PduLengthType length);
#endif /*(0u < CANIF_RXBUFFER_NUMBER) || (0u < CANIF_TXBUFFER_NUMBER) || ((STD_OFF == \
          CANIF_RXINDICATION_AUTOSAR_PARAMETER) && (STD_ON == CANIF_META_DATA_SUPPORT))*/

static FUNC(Std_ReturnType, CANIF_CODE) CanIf_CanIdRangCheck(
    uint8 controllerId,
    Can_HwHandleType hrhId,
    Can_IdType canId,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(PduIdType, AUTOMATIC, AUTOMATIC) pduIdIndex);
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */

static FUNC(Std_ReturnType, CANIF_CODE) CanIf_RxPduHrhSearch(
    Can_HwHandleType hrhIndex,
    Can_IdType CanId,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(PduIdType, AUTOMATIC, AUTOMATIC) rxPduIndex);
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */

static FUNC(Std_ReturnType, CANIF_CODE)
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    CanIf_GetPduHrh(PduIdType pduIdIndex, Can_IdType CanId, P2VAR(PduIdType, AUTOMATIC, AUTOMATIC) rxPduIndex);
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */

#if ((CANIF_TXNOTIFYSTATUS_BUFFER > 0u) || (CANIF_RXNOTIFYSTATUS_BUFFER > 0u))
static FUNC(void, CANIF_CODE) CanIf_FreeRxTxNotifyStatus(uint8 Controller);
#endif

#if (0u < CANIF_RXBUFFER_NUMBER)
static FUNC(void, CANIF_CODE) CanIf_InitRxBuffer(uint8 Controller);
#endif

static FUNC(void, CANIF_CODE) CanIf_RxIndicationHandle(
    PduIdType pduIdIndex,
#if (STD_ON == CANIF_META_DATA_SUPPORT)
    Can_IdType canId,
#endif
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr);

static FUNC(Std_ReturnType, CANIF_CODE)
    CanIf_TransmitHandle(PduIdType CanIfTxSduId, P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr);

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/*************************************************************************/
/*
 * Brief               This service Initializes internal and external interfaces of the CAN Interface for the further
 * processing. ServiceId           0x01 Sync/Async          Synchronous Reentrancy          Non Reentrant Param-Name[in]
 * ConfigPtr: Pointer to configuration parameter set, used e.g. for post build parameters Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
FUNC(void, CANIF_CODE)
CanIf_Init(P2CONST(CanIf_ConfigType, AUTOMATIC, CANIF_CONST_PBCFG) ConfigPtr)
{
    uint8 canLoop;
#if (STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    /* for post build,report error if NULL_PTR */
    if (NULL_PTR == ConfigPtr)
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_INIT_ID, CANIF_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif /* STD_ON == CANIF_DEV_ERROR_DETECT */
    {
        /* CanIf Module has not been initialized */
        if (CANIF_INITED != CanIf_InitStatus)
        {
            /* save the configuration to global variable */
            CanIf_ConfigStd = ConfigPtr;
            /* Set CanIf_Init Status to CANIF_INITED*/
            CanIf_InitStatus = CANIF_INITED;
            /* set controller mode to STOPPED */
            for (canLoop = 0u; canLoop < CANIF_CANCONTROLLER_NUMBER; canLoop++)
            {
                CanIf_ControllerMode[canLoop] = CANIF_CS_STOPPED;
                CanIf_PduMode[canLoop] = CANIF_OFFLINE;
#if (STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALID_SUPPORT)
                /* Init the first call rxindication event flag */
                CanIf_FirstCallRxInd[canLoop] = FALSE;
#endif
#if (STD_ON == CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT)
                CanIf_TxConfirmationState[canLoop] = CANIF_NO_NOTIFICATION;
#endif
#if (STD_ON == CANIF_PUBLIC_PN_SUPPORT)
                if (TRUE == CANIF_CONTROLLER(canLoop).CanIfPnFilter)
                {
                    CanIf_PnTxFilter[canLoop] = TRUE;
                }
                else
                {
                    CanIf_PnTxFilter[canLoop] = FALSE;
                }
#endif
            }
            CanIf_InitAllBuffer();
        }
    }
    return;
}
/*************************************************************************/
/*
 * Brief               De-initializes the CanIf module.
 * ServiceId           0x02
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
FUNC(void, CANIF_CODE)
CanIf_DeInit(VAR(void, AUTOMATIC))
{
    if (CANIF_INITED == CanIf_InitStatus)
    {
        CanIf_ConfigStd = NULL_PTR;
        CanIf_InitStatus = CANIF_UNINIT;
    }
    return;
}
/*************************************************************************/
/*
 * Brief               This service calls the corresponding CAN Driver service
 *                     for changing of the CAN controller mode.
 * ServiceId           0x03
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant (Not for the same controller)
 * Param-Name[in]      ControllerId: Abstracted CanIf ControllerId which is assigned
 *                     to a CAN controller, which is requested for mode transition.
 *                     ControllerMode: Requested mode transition
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: Controller mode request has been accepted
 *                     E_NOT_OK: Controller mode request has not been accepted
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE)
/* PRQA S 1532++ */ /* MISRA Rule 8.7 */
CanIf_SetControllerMode(uint8 ControllerId, CanIf_ControllerModeType ControllerMode)
/* PRQA S 1532-- */ /* MISRA Rule 8.7 */
{
    Std_ReturnType result = E_NOT_OK;
#if (STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    /* check whether module been initialized */
    if (CANIF_INITED != CanIf_InitStatus)
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_SETCONTROLLER_MODE_ID, CANIF_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (ControllerId >= CANIF_CANCONTROLLER_NUMBER))
    {
        (void)Det_ReportError(
            CANIF_MODULE_ID,
            CANIF_INSTANCE_ID,
            CANIF_SETCONTROLLER_MODE_ID,
            CANIF_E_PARAM_CONTROLLERID);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && ((ControllerMode > CANIF_CS_SLEEP) || (ControllerMode <= CANIF_CS_UNINIT)))
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_SETCONTROLLER_MODE_ID, CANIF_E_PARAM_CTRLMODE);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif /* STD_ON == CANIF_DEV_ERROR_DETECT */
    {
        /* check the ControllerMode to be set*/
        switch (ControllerMode)
        {
        case CANIF_CS_STARTED:
            result = CanIf_SetControllStarted(ControllerId);
            break;
        case CANIF_CS_SLEEP:
            result = CanIf_SetControllSleep(ControllerId);
            break;
        case CANIF_CS_STOPPED:
            result = CanIf_SetControllStopped(ControllerId);
            break;
        /* invalid controller mode */
        default:
            result = E_NOT_OK;
            break;
        }
    }
    return result;
}
/*************************************************************************/
/*
 * Brief               This service reports about the current status of the requested CAN controller.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      ControllerId: Abstracted CanIf ControllerId which is assigned to a
 *                     CAN controller, which is requested for current operation mode.
 * Param-Name[out]     ControllerModePtr: Pointer to a memory location, where the current
 *                     mode of the CAN controller will be stored.
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: Controller mode request has been accepted.
 *                     E_NOT_OK: Controller mode request has not been accepted.
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE)
CanIf_GetControllerMode(
    uint8 ControllerId,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(CanIf_ControllerModeType, AUTOMATIC, CANIF_APPL_DATA) ControllerModePtr)
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
{
    Std_ReturnType result = E_NOT_OK;
#if (STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    /* check whether module been initialized */
    if (CANIF_INITED != CanIf_InitStatus)
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_GETCONTROLLER_MODE_ID, CANIF_E_UNINIT);
        detNoErr = FALSE;
    }
    /* check whether controller is over range */
    if ((TRUE == detNoErr) && (ControllerId >= CANIF_CANCONTROLLER_NUMBER))
    {
        (void)Det_ReportError(
            CANIF_MODULE_ID,
            CANIF_INSTANCE_ID,
            CANIF_GETCONTROLLER_MODE_ID,
            CANIF_E_PARAM_CONTROLLERID);
        detNoErr = FALSE;
    }
    /* check whether controller is over range */
    if ((TRUE == detNoErr) && (NULL_PTR == ControllerModePtr))
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_GETCONTROLLER_MODE_ID, CANIF_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif /* STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT */
    {
        /* get current mode */
        *ControllerModePtr = CanIf_ControllerMode[ControllerId];
        result = E_OK;
    }
    return result;
}
/*************************************************************************/
/*
 * Brief               This service initiates a request for transmission of the CAN L-PDU
 *                     specified by the CanTxSduId and CAN related data in the L-SDU structure.
 * ServiceId           0x05
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      CanIfTxSduId: L-SDU handle to be transmitted.This handle specifies the
 *                     corresponding CAN LSDU ID and implicitly the CAN Driver instance as well
 *                     as the corresponding CAN controller device.
 *                     CanIfTxInfoPtr: Pointer to a structure with CAN L-SDU related data:
 *                     DLC and pointer to CAN L-SDU buffer including the MetaData of dynamic L-PDUs.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: Transmit request has been accepted
 *                     E_NOT_OK: Transmit request has not been accepted
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE)
CanIf_Transmit(PduIdType CanIfTxSduId, P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr)
{
    Std_ReturnType result = E_NOT_OK;
    const CanIf_TxPduConfigType* txPduConfigPtr = &CANIF_TXPDU(CanIfTxSduId);
#if (STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    /* check whether module been initialized */
    if (CANIF_INITED != CanIf_InitStatus)
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_TRANSMIT_ID, CANIF_E_UNINIT);
        detNoErr = FALSE;
    }
    /* check NULL_PTR */
    if ((TRUE == detNoErr) && (NULL_PTR == PduInfoPtr))
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_TRANSMIT_ID, CANIF_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (CanIfTxSduId >= CANIF_TXPDU_NUMBER))
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_TRANSMIT_ID, CANIF_E_INVALID_TXPDUID);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (TRUE == txPduConfigPtr->CanIfTxPduRef->TxMetaDataEnable)
        && (NULL_PTR == PduInfoPtr->MetaDataPtr))
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_TRANSMIT_ID, CANIF_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif /* STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT */
    {
        boolean pduLengthValid = TRUE;
#if ((STD_ON == CANIF_TX_STANDARD_CAN_SUPPORT) || (STD_ON == CANIF_TX_EXTENDED_CAN_SUPPORT))
        if (
#if (STD_ON == CANIF_TX_STANDARD_CAN_SUPPORT)
            (CANIF_TX_STANDARD_CAN == txPduConfigPtr->CanIfTxPduCanIdType)
#endif /* (STD_ON == CANIF_TX_STANDARD_CAN_SUPPORT) */
#if ((STD_ON == CANIF_TX_STANDARD_CAN_SUPPORT) && (STD_ON == CANIF_TX_EXTENDED_CAN_SUPPORT))
            ||
#endif /* (STD_ON == CANIF_TX_STANDARD_CAN_SUPPORT) && (STD_ON == CANIF_TX_EXTENDED_CAN_SUPPORT) */
#if (STD_ON == CANIF_TX_EXTENDED_CAN_SUPPORT)
            (CANIF_TX_EXTENDED_CAN == txPduConfigPtr->CanIfTxPduCanIdType)
#endif /* STD_ON == CANIF_TX_EXTENDED_CAN_SUPPORT */
        )
        {
            if (PduInfoPtr->SduLength > 8u)
            {
                pduLengthValid = FALSE;
            }
        }
#endif /* (STD_ON == CANIF_TX_STANDARD_CAN_SUPPORT) || (STD_ON == CANIF_TX_EXTENDED_CAN_SUPPORT) */
#if (                                                                                        \
    ((STD_ON == CANIF_TX_STANDARD_CAN_SUPPORT) || (STD_ON == CANIF_TX_EXTENDED_CAN_SUPPORT)) \
    && ((STD_ON == CANIF_TX_STANDARD_FD_CAN_SUPPORT) || (STD_ON == CANIF_TX_EXTENDED_FD_CAN_SUPPORT)))
        else
#endif /* ((STD_ON == CANIF_TX_STANDARD_CAN_SUPPORT) || (STD_ON == CANIF_TX_EXTENDED_CAN_SUPPORT)) && ((STD_ON == \
          CANIF_TX_STANDARD_FD_CAN_SUPPORT) || (STD_ON == CANIF_TX_EXTENDED_FD_CAN_SUPPORT)) */
        {
#if ((STD_ON == CANIF_TX_STANDARD_FD_CAN_SUPPORT) || (STD_ON == CANIF_TX_EXTENDED_FD_CAN_SUPPORT))
            if (PduInfoPtr->SduLength > 64u)
            {
                pduLengthValid = FALSE;
            }
#endif((STD_ON == CANIF_TX_STANDARD_FD_CAN_SUPPORT) || (STD_ON == CANIF_TX_EXTENDED_FD_CAN_SUPPORT))
        }
        if (TRUE == pduLengthValid)
        {
            result = CanIf_TransmitHandle(CanIfTxSduId, PduInfoPtr);
        }
        else
        {
            (void)Det_ReportRuntimeError(
                CANIF_MODULE_ID,
                CANIF_INSTANCE_ID,
                CANIF_TRANSMIT_ID,
                CANIF_E_DATA_LENGTH_MISMATCH);
        }
    }
    return result;
}
#if (STD_ON == CANIF_PUBLIC_CANCEL_TRANSMIT_SUPPORT)
/*************************************************************************/
/*
 * Brief               This is a dummy method introduced for interface compatibility.
 * ServiceId           0x18
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      CanIfTxSduId: L-SDU handle to be transmitted.This handle specifies the
 *                     corresponding CAN LSDU ID and implicitly the CAN Driver instance as well
 *                     as the corresponding CAN controller device.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     Always return E_OK
 * PreCondition        CANIF_PUBLIC_CANCEL_TRANSMIT_SUPPORT is TRUE
 * CallByAPI           Up layer
 */
/*************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE)
CanIf_CancelTransmit(PduIdType CanIfTxSduId)
{
    Std_ReturnType result = E_OK;
#if (STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
    if (CanIfTxSduId >= CANIF_TXPDU_NUMBER)
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_CANCELTRANSMIT_ID, CANIF_E_INVALID_TXPDUID);
        result = E_NOT_OK;
    }
#endif /*STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT*/
    return result;
}
#endif /*STD_ON == CANIF_PUBLIC_CANCEL_TRANSMIT_SUPPORT*/
#if (STD_ON == CANIF_PUBLIC_READ_RX_PDU_DATA_API)
/*************************************************************************/
/*
 * Brief               This service provides the CAN DLC and the received data of the requested CanIfRxSduId to the
 * calling upper layer. ServiceId           0x06 Sync/Async          Synchronous Reentrancy          Non Reentrant
 * Param-Name[in]      CanIfRxSduId: Receive L-SDU handle specifying the corresponding CAN L-SDU ID and implicitly the
 * CAN Driver instance as well as the corresponding CAN controller device. Param-Name[out]     CanIfRxInfoPtr: Pointer
 * to a structure with CAN L-SDU related data:DLC and pointer to CAN L-SDU buffer including the MetaData of dynamic
 * L-PDUs. Param-Name[in/out]  None Return              Std_ReturnType E_OK: Request for L-SDU data has been accepted
 *                     E_NOT_OK: No valid data has been received
 * PreCondition        CANIF_PUBLIC_READ_RX_PDU_DATA_API is TRUE
 * CallByAPI           Up layer
 */
/*************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE)
CanIf_ReadRxPduData(PduIdType CanIfRxSduId, P2VAR(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) CanIfRxInfoPtr)
{
    Std_ReturnType result = E_NOT_OK;
#if (STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    /* check whether module been initialized */
    if (CANIF_INITED != CanIf_InitStatus)
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_READRXPDUDATA_ID, CANIF_E_UNINIT);
        detNoErr = FALSE;
    }
    /* check NULL PTR*/
    if ((TRUE == detNoErr) && ((NULL_PTR == CanIfRxInfoPtr) || (NULL_PTR == CanIfRxInfoPtr->SduDataPtr)))
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_READRXPDUDATA_ID, CANIF_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (CanIfRxSduId >= CANIF_RXPDU_NUMBER))
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_READRXPDUDATA_ID, CANIF_E_INVALID_RXPDUID);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif /*STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT*/
#if (0u < CANIF_RXBUFFER_NUMBER)
    {
        uint8 controllerId;
        Can_HwHandleType hrhIndex;
        CanIf_RxPduBufferType* rxPduBuffer;
        const CanIf_RxPduConfigType* rxPduConfigPtr = &CANIF_RXPDU(CanIfRxSduId);
        hrhIndex = txPduConfigPtr->CanIfRxPduHrhId;
        controllerId = CANIF_HRH(hrhIndex).CanIfHrhCanCtrlId;
        if ((CANIF_CS_STARTED == CanIf_ControllerMode[controllerId])
            && ((CANIF_OFFLINE != CanIf_PduMode[controllerId])))
        {
            rxPduBuffer = rxPduConfigPtr->CanIfRxBufferRef;
            if ((NULL_PTR != rxPduBuffer) && (0u != rxPduBuffer->length))
            {
                SchM_Enter_CanIf();
                /*copy rx buffer data to CanIfRxInfoPtr*/
                CanIfRxInfoPtr->SduLength = (PduLengthType)rxPduBuffer->length;
                CanIf_Memcpy(CanIfRxInfoPtr->SduDataPtr, rxPduBuffer->data, CanIfRxInfoPtr->SduLength);
#if (STD_ON == CANIF_META_DATA_SUPPORT)
                if (TRUE == rxPduConfigPtr->CanIfRxPduRef->RxMetaDataEnable)
                {
                    CANIF_CANIDTOMETADATA(rxPduBuffer->metaData, CanIfRxInfoPtr->MetaDataPtr);
                }
#endif
                result = E_OK;
                SchM_Exit_CanIf();
            }
        }
    }
#endif /*(0u < CANIF_RXBUFFER_NUMBER)*/
    return result;
}
#endif /* STD_ON == CANIF_PUBLIC_READ_RX_PDU_DATA_API*/
#if (STD_ON == CANIF_PUBLIC_READ_TX_PDU_NOTIFY_STATUS_API)
/*************************************************************************/
/*
 * Brief               This service returns the confirmation status (confirmation occurred or
 *                     not) of a specific static or dynamic CAN Tx L-PDU, requested by the CanIfTxSduId.
 * ServiceId           0x07
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      CanIfTxSduId: L-SDU handle to be transmitted.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              CanIf_NotifStatusType:Current confirmation status of the corresponding CAN Tx L-PDU.
 * PreCondition        CANIF_PUBLIC_READ_TX_PDU_NOTIFY_STATUS_API is TRUE
 * CallByAPI           Up layer
 */
/*************************************************************************/
FUNC(CanIf_NotifStatusType, CANIF_CODE)
CanIf_ReadTxNotifStatus(PduIdType CanIfTxSduId)
{
    CanIf_NotifStatusType result = CANIF_NO_NOTIFICATION;
#if (STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    /* check initiation */
    if (CANIF_INITED != CanIf_InitStatus)
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_READTXNOTIFSTATUS_ID, CANIF_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr)
        && ((CanIfTxSduId >= CANIF_TXPDU_NUMBER) || (FALSE == CANIF_TXPDU(CanIfTxSduId).CanIfTxPduReadNotifyStatus)))
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_READTXNOTIFSTATUS_ID, CANIF_E_INVALID_TXPDUID);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if (CANIF_TXNOTIFYSTATUS_BUFFER > 0u)
        const CanIf_TxPduConfigType* txPduConfigPtr = &CANIF_TXPDU(CanIfTxSduId);
        if (TRUE == txPduConfigPtr->CanIfTxPduReadNotifyStatus)
        {
            result = CanIf_TxNotifStatus[txPduConfigPtr->CanIfTxNotifyIndex];
            /* clear STATUS */
            CanIf_TxNotifStatus[txPduConfigPtr->CanIfTxNotifyIndex] = CANIF_NO_NOTIFICATION;
        }
#endif
    }
    return result;
}
#endif /* STD_ON == CANIF_PUBLIC_READ_TX_PDU_NOTIFY_STATUS_API */
#if (STD_ON == CANIF_PUBLIC_READ_RX_PDU_NOTIFY_STATUS_API)
/*************************************************************************/
/*
 * Brief               This service returns the indication status (indication occurred or not) of a
 *                     specific CAN Rx L-PDU, requested by the CanIfRxSduId.
 * ServiceId           0x08
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      CanIfRxSduId: Receive L-SDU handle specifying the corresponding CAN L-SDU ID and implicitly
 *                     the CAN Driver instance as well as the corresponding CAN controller device.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              CanIf_NotifStatusType:Current indication status of the corresponding CAN Rx L-PDU.
 * PreCondition        CANIF_PUBLIC_READ_RX_PDU_NOTIFY_STATUS_API is TRUE
 * CallByAPI           Up layer
 */
/*************************************************************************/
FUNC(CanIf_NotifStatusType, CANIF_CODE)
CanIf_ReadRxNotifStatus(PduIdType CanIfRxSduId)
{
    CanIf_NotifStatusType result = CANIF_NO_NOTIFICATION;
#if (STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    /* check initiation */
    if (CANIF_INITED != CanIf_InitStatus)
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_READRXNOTIFSTATUS_ID, CANIF_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr)
        && ((CanIfRxSduId >= CANIF_RXPDU_NUMBER) || (FALSE == CANIF_RXPDU(CanIfRxSduId).CanIfRxPduReadNotifyStatus)))
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_READRXNOTIFSTATUS_ID, CANIF_E_INVALID_RXPDUID);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif /*TRUE == CANIF_PUBLIC_DEV_ERROR_DETECT*/
    {
#if (CANIF_RXNOTIFYSTATUS_BUFFER > 0u)
        const CanIf_RxPduConfigType* rxPduConfigPtr = &CANIF_RXPDU(CanIfRxSduId);
        if (TRUE == rxPduConfigPtr->CanIfRxPduReadNotifyStatus)
        {
            result = CanIf_RxNotifStatus[rxPduConfigPtr->CanIfRxNotifyIndex];
            /* clear STATUS */
            CanIf_RxNotifStatus[rxPduConfigPtr->CanIfRxNotifyIndex] = CANIF_NO_NOTIFICATION;
        }
#endif
    }
    return result;
}
#endif /* STD_ON == CANIF_PUBLIC_READ_RX_PDU_NOTIFY_STATUS_API */
/*************************************************************************/
/*
 * Brief               This service sets the requested mode at the L-PDUs of a predefined logical PDU channel.
 * ServiceId           0x09
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      ControllerId: All PDUs of the own ECU connected to the corresponding CanIf ControllerId,
 *                     which is assigned to a physical CAN controller are addressed.
 *                     PduModeRequest: Requested PDU mode change
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: Request for mode transition has been accepted.
 *                     E_NOT_OK: Request for mode transition has not been accepted.
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
CanIf_SetPduMode(uint8 ControllerId, CanIf_PduModeType PduModeRequest)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
    Std_ReturnType result = E_NOT_OK;
#if (STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    /* check whether module been initialized */
    if (CANIF_INITED != CanIf_InitStatus)
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_SETPDUMODE_ID, CANIF_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (ControllerId >= CANIF_CANCONTROLLER_NUMBER))
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_SETPDUMODE_ID, CANIF_E_PARAM_CONTROLLERID);
        detNoErr = FALSE;
    }
#if (STD_ON == CANIF_TX_OFFLINE_ACTIVE_SUPPORT)
    if ((TRUE == detNoErr) && (PduModeRequest > CANIF_ONLINE))
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_SETPDUMODE_ID, CANIF_E_PARAM_PDU_MODE);
        detNoErr = FALSE;
    }
#else
    if ((TRUE == detNoErr) && ((PduModeRequest > CANIF_ONLINE) || (PduModeRequest == CANIF_TX_OFFLINE_ACTIVE)))
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_SETPDUMODE_ID, CANIF_E_PARAM_PDU_MODE);
        detNoErr = FALSE;
    }
#endif /*STD_ON == CANIF_TX_OFFLINE_ACTIVE_SUPPORT*/
    if (TRUE == detNoErr)
#endif /* STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT */
    {
        if (CANIF_CS_STARTED == CanIf_ControllerMode[ControllerId])
        {
            switch (PduModeRequest)
            {
            case CANIF_OFFLINE:
                CanIf_PduMode[ControllerId] = CANIF_OFFLINE;
                result = E_OK;
                break;
            case CANIF_TX_OFFLINE:
                CanIf_PduMode[ControllerId] = CANIF_TX_OFFLINE;
#if (STD_ON == CANIF_PUBLIC_PN_SUPPORT)
                if (TRUE == CANIF_CONTROLLER(ControllerId).CanIfPnFilter)
                {
                    CanIf_PnTxFilter[ControllerId] = TRUE;
                }
#endif /*STD_ON == CANIF_PUBLIC_PN_SUPPORT*/
                result = E_OK;
                break;
#if (STD_ON == CANIF_TX_OFFLINE_ACTIVE_SUPPORT)
            case CANIF_TX_OFFLINE_ACTIVE:
                CanIf_PduMode[ControllerId] = CANIF_TX_OFFLINE_ACTIVE;
                result = E_OK;
                break;
#endif /*STD_ON == CANIF_TX_OFFLINE_ACTIVE_SUPPORT*/
            case CANIF_ONLINE:
                CanIf_PduMode[ControllerId] = CANIF_ONLINE;
                result = E_OK;
                break;
            default:
                /* invalid pdu mode*/
                result = E_NOT_OK;
                break;
            }
        }
    }
    return result;
}
/*************************************************************************/
/*
 * Brief               This service reports the current mode of a requested PDU channel.
 * ServiceId           0x0a
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant (Not for the same channel)
 * Param-Name[in]      ControllerId: All PDUs of the own ECU connected to the corresponding CanIf
 *                     ControllerId, which is assigned to a physical CAN controller are addressed.
 * Param-Name[out]     PduModePtr: Pointer to a memory location, where the current mode of the
 *                     logical PDU channel will be stored.
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: PDU mode request has been accepted
 *                     E_NOT_OK: PDU mode request has not been accepted
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE)
/* PRQA S 3432,1532 ++ */ /* MISRA Rule 20.7,8.7 */
CanIf_GetPduMode(uint8 ControllerId, P2VAR(CanIf_PduModeType, AUTOMATIC, CANIF_APPL_DATA) PduModePtr)
/* PRQA S 3432,1532 -- */ /* MISRA Rule 20.7,8.7 */
{
    Std_ReturnType result = E_NOT_OK;
#if (STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    /* check whether module been initialized */
    if (CANIF_INITED != CanIf_InitStatus)
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_GETPDUMODE_ID, CANIF_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (ControllerId >= CANIF_CANCONTROLLER_NUMBER))
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_GETPDUMODE_ID, CANIF_E_PARAM_CONTROLLERID);
        detNoErr = FALSE;
    }
    /* check NULL PTR*/
    if (NULL_PTR == PduModePtr)
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_GETPDUMODE_ID, CANIF_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif /* STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT */
    {
        /* get current pdu mode */
        *PduModePtr = CanIf_PduMode[ControllerId];
        result = E_OK;
    }
    return result;
}
#if (STD_ON == CANIF_PUBLIC_SET_DYNAMIC_TX_ID_API)
/*************************************************************************/
/*
 * Brief               This service reconfigures the corresponding CAN identifier of the requested CAN L-PDU.
 * ServiceId           0x0c
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      CanIfTxSduId: L-SDU handle to be transmitted.This handle specifies the corresponding
 *                     CAN LSDU ID and implicitly the CAN Driver instance as well as the corresponding CAN controller
 * device. CanId: Standard/Extended CAN ID of CAN L-SDU that shall be transmitted as FD or conventional CAN frame.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        CANIF_DYNAMIC_TXPDU_NUMBER > 0
 * CallByAPI           Up layer
 */
/*************************************************************************/
FUNC(void, CANIF_CODE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
CanIf_SetDynamicTxId(PduIdType CanIfTxSduId, Can_IdType CanId)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
#if (STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    boolean canIdValid = TRUE;
    const CanIf_TxPduConfigType* txPduCfgPtr = &CANIF_TXPDU(CanIfTxSduId);
    /* check initiation */
    if (CANIF_INITED != CanIf_InitStatus)
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_SETDYNAMICTXID_ID, CANIF_E_UNINIT);
        detNoErr = FALSE;
    }
    /* check CanTxPduId valid */
    if ((TRUE == detNoErr) && ((CanIfTxSduId >= CANIF_TXPDU_NUMBER) || (CANID_DYNAMIC != txPduCfgPtr->CanIfTxPduType)))
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_SETDYNAMICTXID_ID, CANIF_E_INVALID_TXPDUID);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
    {
#if ((STD_ON == CANIF_TX_EXTENDED_CAN_SUPPORT) || (STD_ON == CANIF_TX_EXTENDED_FD_CAN_SUPPORT))
        /*  dynamic Txpdu CanId Extended */
        if (
#if (STD_ON == CANIF_TX_EXTENDED_CAN_SUPPORT)
            (CANIF_TX_EXTENDED_CAN == txPduCfgPtr->CanIfTxPduCanIdType)
#endif /* STD_ON == CANIF_TX_EXTENDED_CAN_SUPPORT */
#if ((STD_ON == CANIF_TX_EXTENDED_CAN_SUPPORT) && (STD_ON == CANIF_TX_EXTENDED_FD_CAN_SUPPORT))
            ||
#endif /* (STD_ON == CANIF_TX_EXTENDED_CAN_SUPPORT) && (STD_ON == CANIF_TX_EXTENDED_FD_CAN_SUPPORT) */
#if (STD_ON == CANIF_TX_EXTENDED_FD_CAN_SUPPORT)
            (CANIF_TX_EXTENDED_FD_CAN == txPduCfgPtr->CanIfTxPduCanIdType)
#endif /* STD_ON == CANIF_TX_EXTENDED_FD_CAN_SUPPORT */
        )
        {
            if (CanId > CANIF_EXTENDED_CANID_MAX)
            {
                canIdValid = FALSE;
            }
        }
#endif /* (STD_ON == CANIF_TX_EXTENDED_CAN_SUPPORT) || (STD_ON == CANIF_TX_EXTENDED_FD_CAN_SUPPORT) */
#if (                                                                                           \
    ((STD_ON == CANIF_TX_EXTENDED_CAN_SUPPORT) || (STD_ON == CANIF_TX_EXTENDED_FD_CAN_SUPPORT)) \
    && ((STD_ON == CANIF_TX_STANDARD_CAN_SUPPORT) || (STD_ON == CANIF_TX_STANDARD_FD_CAN_SUPPORT)))
        else
#endif /* ((STD_ON == CANIF_TX_EXTENDED_CAN_SUPPORT) || (STD_ON == CANIF_TX_EXTENDED_FD_CAN_SUPPORT)) && ((STD_ON == \
          CANIF_TX_STANDARD_CAN_SUPPORT) || (STD_ON == CANIF_TX_STANDARD_FD_CAN_SUPPORT)) */
#if ((STD_ON == CANIF_TX_STANDARD_CAN_SUPPORT) || (STD_ON == CANIF_TX_STANDARD_FD_CAN_SUPPORT))
        {
            /* Standard Can Id, check whether valid */
            if (CanId > CANIF_STANDARD_CANID_MAX)
            {
                canIdValid = FALSE;
            }
        }
#endif /* (STD_ON == CANIF_TX_STANDARD_CAN_SUPPORT) || (STD_ON == CANIF_TX_STANDARD_FD_CAN_SUPPORT) */
        if (FALSE == canIdValid)
        {
            (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_SETDYNAMICTXID_ID, CANIF_E_PARAM_CANID);
            detNoErr = FALSE;
        }
    }
    if (TRUE == detNoErr)
#endif /* STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT */
    {
#if (CANIF_DYNAMIC_TXPDU_NUMBER > 0u)
        const CanIf_TxPduConfigType* txPduConfigPtr = &CANIF_TXPDU(CanIfTxSduId);
        if (CANID_DYNAMIC == txPduConfigPtr->CanIfTxPduType)
        {
            SchM_Enter_CanIf();
            /*CanId:no FD and EXTENDED flag*/
            CanIf_TxPduDynamicCanIds[txPduConfigPtr->CanIfDynamicCanIdIndex] = CanId;
            SchM_Exit_CanIf();
        }
#endif /* CANIF_DYNAMIC_TXPDU_NUMBER > 0u */
    }
    return;
}
#endif /*STD_ON == CANIF_PUBLIC_SET_DYNAMIC_TX_ID_API*/
#if (CANIF_TRCV_NUMBER > 0u)
/*************************************************************************/
/*
 * Brief               This service changes the operation mode of the tansceiver TransceiverId,
 *                     via calling the corresponding CAN Transceiver Driver service.
 * ServiceId           0x0d
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      TransceiverId: Abstracted CanIf TransceiverId, which is assigned to a CAN
 *                     transceiver, which is requested for mode transition
 *                     TransceiverMode: Requested mode transition
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: Transceiver mode request has been accepted.
 *                     E_NOT_OK: Transceiver mode request has not been accepted.
 * PreCondition        CANIF_TRCV_NUMBER > 0
 * CallByAPI           Up layer
 */
/*************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
CanIf_SetTrcvMode(uint8 TransceiverId, CanTrcv_TrcvModeType TransceiverMode)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
    Std_ReturnType result = E_NOT_OK;
    uint8 trcvDriver;
    const CanIf_TrcvCfgType* trcvConfigPtr = &CANIF_TRCV(TransceiverId);
#if (STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    /* check whether module been initialized */
    if (CANIF_INITED != CanIf_InitStatus)
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_SETTRCVMODE_ID, CANIF_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (TransceiverId >= CANIF_TRCV_NUMBER))
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_SETTRCVMODE_ID, CANIF_E_PARAM_TRCV);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (TransceiverMode > CANTRCV_TRCVMODE_STANDBY))
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_SETTRCVMODE_ID, CANIF_E_PARAM_TRCVMODE);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif /* STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT */
    {
        trcvDriver = trcvConfigPtr->CanTrcvDriverId;
        result =
            Can_TrcvApi[trcvDriver].CanTrcvSetOpModeApi(trcvConfigPtr->CanIfTrcvCanTrcvRef->CanTrcvId, TransceiverMode);
    }
    return result;
}
/*************************************************************************/
/*
 * Brief               This function invokes CanTrcv_GetOpMode and updates the parameter
 *                     TransceiverModePtr with the value OpMode provided by CanTrcv.
 * ServiceId           0x0e
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      TransceiverId: Abstracted CanIf TransceiverId, which is assigned to a
 *                     CAN transceiver, which is requested for current operation mode.
 * Param-Name[out]     TransceiverModePtr: Requested mode of requested network the Transceiver is connected to.
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: Transceiver mode request has been accepted.
 *                     E_NOT_OK: Transceiver mode request has not been accepted.
 * PreCondition        CANIF_TRCV_NUMBER > 0
 * CallByAPI           Up layer
 */
/*************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE)
/* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
CanIf_GetTrcvMode(P2VAR(CanTrcv_TrcvModeType, AUTOMATIC, CANIF_APPL_DATA) TransceiverModePtr, uint8 TransceiverId)
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
{
    Std_ReturnType result = E_NOT_OK;
    uint8 trcvDriver;
    const CanIf_TrcvCfgType* trcvConfigPtr = &CANIF_TRCV(TransceiverId);
#if (STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    /* check whether module been initialized */
    if (CANIF_INITED != CanIf_InitStatus)
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_GETTRCVMODE_ID, CANIF_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (TransceiverId >= CANIF_TRCV_NUMBER))
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_GETTRCVMODE_ID, CANIF_E_PARAM_TRCV);
        detNoErr = FALSE;
    }
    /* check NULL PTR*/
    if (NULL_PTR == TransceiverModePtr)
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_GETTRCVMODE_ID, CANIF_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif /* STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT */
    {
        trcvDriver = trcvConfigPtr->CanTrcvDriverId;
        result = Can_TrcvApi[trcvDriver].CanTrcvGetOpModeApi(
            trcvConfigPtr->CanIfTrcvCanTrcvRef->CanTrcvId,
            TransceiverModePtr);
    }
    return result;
}
/*************************************************************************/
/*
 * Brief               This service returns the reason for the wake up of the transceiver
 *                     TransceiverId, via calling the corresponding CAN Transceiver Driver service.
 * ServiceId           0x0f
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      TransceiverId: Abstracted CanIf TransceiverId, which is assigned to a CAN
 *                     transceiver, which is requested for wake up reason.
 * Param-Name[out]     TrcvWuReasonPtr: provided pointer to where the requested transceiver wake
 *                     up reason shall be returned
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: Transceiver wake up reason request has been accepted.
 *                     E_NOT_OK: Transceiver wake up reason request has not been accepted.
 * PreCondition        CANIF_TRCV_NUMBER > 0
 * CallByAPI           Up layer
 */
/*************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE)
CanIf_GetTrcvWakeupReason(
    uint8 TransceiverId,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(CanTrcv_TrcvWakeupReasonType, AUTOMATIC, CANIF_APPL_DATA) TrcvWuReasonPtr)
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
{
    Std_ReturnType result = E_NOT_OK;
    uint8 trcvDriver;
    const CanIf_TrcvCfgType* trcvConfigPtr = &CANIF_TRCV(TransceiverId);
#if (STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    /* check whether module been initialized */
    if (CANIF_INITED != CanIf_InitStatus)
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_GETTRCVWAKEUPREASON_ID, CANIF_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (TransceiverId >= CANIF_TRCV_NUMBER))
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_GETTRCVWAKEUPREASON_ID, CANIF_E_PARAM_TRCV);
        detNoErr = FALSE;
    }
    /* check NULL PTR*/
    if (NULL_PTR == TrcvWuReasonPtr)
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_GETTRCVWAKEUPREASON_ID, CANIF_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif /* STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT */
    {
        trcvDriver = trcvConfigPtr->CanTrcvDriverId;
        result = Can_TrcvApi[trcvDriver].CanTrcvGetBusWuReasonApi(
            trcvConfigPtr->CanIfTrcvCanTrcvRef->CanTrcvId,
            TrcvWuReasonPtr);
    }
    return result;
}
/*************************************************************************/
/*
 * Brief               This function shall call CanTrcv_SetTrcvWakeupMode.
 * ServiceId           0x10
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      TransceiverId: Abstracted CanIf TransceiverId, which is assigned to a
 *                     CAN transceiver, which is requested for wake up notification mode transition.
 *                     TrcvWakeupMode: Requested transceiver wake up notification mode
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: Will be returned, if the wake up notifications state has been changed to the requested
 * mode. E_NOT_OK: Will be returned, if the wake up notifications state change has failed or the parameter is out of the
 * allowed range. The previous state has not been changed. PreCondition        CANIF_TRCV_NUMBER > 0 CallByAPI Up layer
 */
/*************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE)
CanIf_SetTrcvWakeupMode(uint8 TransceiverId, CanTrcv_TrcvWakeupModeType TrcvWakeupMode)
{
    Std_ReturnType result = E_NOT_OK;
    uint8 trcvDriver;
    const CanIf_TrcvCfgType* trcvConfigPtr = &CANIF_TRCV(TransceiverId);
#if (STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    /* check whether module been initialized */
    if (CANIF_INITED != CanIf_InitStatus)
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_SETTRCVWAKEUPMODE_ID, CANIF_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (TransceiverId >= CANIF_TRCV_NUMBER))
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_SETTRCVWAKEUPMODE_ID, CANIF_E_PARAM_TRCV);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (TrcvWakeupMode > CANTRCV_WUMODE_CLEAR))
    {
        (void)Det_ReportError(
            CANIF_MODULE_ID,
            CANIF_INSTANCE_ID,
            CANIF_SETTRCVWAKEUPMODE_ID,
            CANIF_E_PARAM_TRCVWAKEUPMODE);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif /* STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT */
    {
        trcvDriver = trcvConfigPtr->CanTrcvDriverId;
        result = Can_TrcvApi[trcvDriver].CanTrcvSetWakeupModeApi(
            trcvConfigPtr->CanIfTrcvCanTrcvRef->CanTrcvId,
            TrcvWakeupMode);
    }
    return result;
}
#endif /*CANIF_TRCV_NUMBER > 0u*/
#if (STD_ON == CANIF_WAKE_UP_SUPPORT)
/*************************************************************************/
/*
 * Brief               This service checks, whether an underlying CAN driver or a CAN
 *                     transceiver driver already signals a wakeup event.
 * ServiceId           0x11
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      WakeupSource: Source device, which initiated the wake up event:CAN controller or CAN transceiver
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: Will be returned, if the check wake up request has been accepted
 *                     E_NOT_OK: Will be returned, if the check wake up request has not been accepted
 * PreCondition        CANIF_WAKE_UP_SUPPORT is TRUE
 * CallByAPI           Up layer
 */
/*************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE)
CanIf_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
{
    Std_ReturnType result = E_NOT_OK;
#if (STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    /* CanIf not initialized */
    if (CANIF_INITED != CanIf_InitStatus)
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_CHECKWAKEUP_ID, CANIF_E_UNINIT);
        detNoErr = FALSE;
    }
    /*ECUM_WKSOURCE_POWER: bit 0,ECUM_WKSOURCE_RESET: bit 1,ECUM_WKSOURCE_INTERNAL_RESET:bit 2,
     * ECUM_WKSOURCE_INTERNAL_WDG:bit 3,ECUM_WKSOURCE_EXTERNAL_WDG:bit 4*/
    if ((TRUE == detNoErr) && (WakeupSource > CANIF_WAKEUPSOURCE_MAX))
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_CHECKWAKEUP_ID, CANIF_E_PARAM_WAKEUPSOURCE);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif /* STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT */
    {
/*all controller and Trcv need to check*/
#if ((STD_ON == CANIF_CANTRCV_WAKE_UP_SUPPORT) || (STD_ON == CANIF_CANDRV_WAKE_UP_SUPPORT))
        uint8 index;
        EcuM_WakeupSourceType wakeupSource;
        boolean controllerNotSleep = FALSE;
#endif /*(STD_ON == CANIF_CANTRCV_WAKE_UP_SUPPORT) || (STD_ON == CANIF_CANDRV_WAKE_UP_SUPPORT)*/
#if ((STD_ON == CANIF_CANDRV_WAKE_UP_SUPPORT) && (CANIF_CANCONTROLLER_NUMBER > 0u))
        uint8 canDriver;
        const CanIf_ControllerCfgType* controllerPtr;
#endif
#if ((STD_ON == CANIF_CANTRCV_WAKE_UP_SUPPORT) && (CANIF_TRCVDRIVER_NUMBER > 0u))
        uint8 trcvDriver;
        const CanIf_TrcvCfgType* trcvConfigPtr;
#endif
/*check all can controllers to find the wake-up source*/
#if ((STD_ON == CANIF_CANDRV_WAKE_UP_SUPPORT) && (CANIF_CANCONTROLLER_NUMBER > 0u))
        for (index = 0u; index < CANIF_CANCONTROLLER_NUMBER; index++)
        {
            controllerPtr = &CANIF_CONTROLLER(index);
            if (TRUE == controllerPtr->CanIfCtrlWakeupSupport)
            {
                wakeupSource = controllerPtr->CanIfCtrlCanCtrlRef->CanIfWakeUpSource;
                if (0u != (WakeupSource & wakeupSource))
                {
                    if (CANIF_CS_SLEEP != CanIf_ControllerMode[index])
                    {
                        controllerNotSleep = TRUE;
                        break;
                    }
                    else
                    {
                        canDriver = controllerPtr->CanDriverId;
                        if (NULL_PTR != Can_DriverApi[canDriver].CanCheckWakeupApi)
                        {
                            if (CAN_OK
                                == Can_DriverApi[canDriver].CanCheckWakeupApi(
                                    controllerPtr->CanIfCtrlCanCtrlRef->CanCtrlId))
                            {
                                result = E_OK;
                                break;
                            }
                        }
                    }
                }
            }
        }
#endif /*(STD_ON == CANIF_CANDRV_WAKE_UP_SUPPORT) && (CANIF_CANCONTROLLER_NUMBER > 0u)*/
/*check all cantrcvs to find the wake-up source*/
#if ((STD_ON == CANIF_CANTRCV_WAKE_UP_SUPPORT) && (CANIF_TRCVDRIVER_NUMBER > 0u))
        for (index = 0u; (index < CANIF_TRCV_NUMBER) && (result == E_NOT_OK) && (FALSE == controllerNotSleep); index++)
        {
            trcvConfigPtr = &CANIF_TRCV(index);
            if (TRUE == trcvConfigPtr->CanIfTrcvWakeupSupport)
            {
                wakeupSource = trcvConfigPtr->CanIfTrcvCanTrcvRef->CanIfWakeUpSource;
                if (0u != (WakeupSource & wakeupSource))
                {
                    trcvDriver = trcvConfigPtr->CanTrcvDriverId;
                    if (NULL_PTR != Can_TrcvApi[trcvDriver].CanTrcvCheckWakeupApi)
                    {
                        result = Can_TrcvApi[trcvDriver].CanTrcvCheckWakeupApi(
                            trcvConfigPtr->CanIfTrcvCanTrcvRef->CanTrcvId);
                    }
                }
            }
        }
#endif /*(STD_ON == CANIF_CANTRCV_WAKE_UP_SUPPORT) && (CANIF_TRCVDRIVER_NUMBER > 0u)*/
#if ((STD_ON == CANIF_CANTRCV_WAKE_UP_SUPPORT) || (STD_ON == CANIF_CANDRV_WAKE_UP_SUPPORT))
        /* PRQA S 2992,2996,2880 ++ */ /* MISRA Rule 14.3,2.2,2.1 */
        if (TRUE == controllerNotSleep)
        {
            (void)Det_ReportRuntimeError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_CHECKWAKEUP_ID, CANIF_E_NOT_SLEEP);
        }
        /* PRQA S 2992,2996,2880 -- */ /* MISRA Rule 14.3,2.2,2.1 */
#endif
    }
    return result;
}
#endif /*STD_ON == CANIF_WAKE_UP_SUPPORT*/
#if (STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALID_SUPPORT)
/*************************************************************************/
/*
 * Brief               This service is performed to validate a previous wakeup event.
 * ServiceId           0x12
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      WakeupSource: Source device which initiated the wake-up event and
 *                     which has to be validated: CAN controller or CAN transceiver
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: Will be returned, if the check validation request has been accepted.
 *                     E_NOT_OK: Will be returned, if the check validation request has not been accepted.
 * PreCondition        CANIF_PUBLIC_WAKEUP_CHECK_VALID_SUPPORT is TRUE
 * CallByAPI           Up layer
 */
/*************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE)
CanIf_CheckValidation(EcuM_WakeupSourceType WakeupSource)
{
    Std_ReturnType result = E_NOT_OK;
#if (STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    /* check initiation */
    if (CANIF_INITED != CanIf_InitStatus)
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_CHECKVALIDATION_ID, CANIF_E_UNINIT);
        detNoErr = FALSE;
    }
    /*ECUM_WKSOURCE_POWER: bit 0,ECUM_WKSOURCE_RESET: bit 1,ECUM_WKSOURCE_INTERNAL_RESET:bit 2,
     * ECUM_WKSOURCE_INTERNAL_WDG:bit 3,ECUM_WKSOURCE_EXTERNAL_WDG:bit 4*/
    if ((TRUE == detNoErr) && (WakeupSource > CANIF_WAKEUPSOURCE_MAX))
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_CHECKVALIDATION_ID, CANIF_E_PARAM_WAKEUPSOURCE);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif /*TRUE == CANIF_PUBLIC_DEV_ERROR_DETECT*/
    {
        uint8 controllerIndex;
        EcuM_WakeupSourceType wakeupSource;
        /*check all can controllers to find the wake-up source*/
        for (controllerIndex = 0u; controllerIndex < CANIF_CANCONTROLLER_NUMBER; controllerIndex++)
        {
            wakeupSource = CANIF_CONTROLLER(controllerIndex).CanIfCtrlCanCtrlRef->CanIfWakeUpSource;
            /* check wake-up source */
            if (0u != (WakeupSource & wakeupSource))
            {
                /* do check up Validation action */
                if ((CANIF_CS_STARTED == CanIf_ControllerMode[controllerIndex])
                    && (TRUE == CanIf_FirstCallRxInd[controllerIndex]))
                {
                    if (NULL_PTR != CanIf_DispatchConfigData.CanIfDispatchUserValidateWakeupEventName)
                    {
                        /* call upper(EcuM) layer function */
                        CanIf_DispatchConfigData.CanIfDispatchUserValidateWakeupEventName(WakeupSource & wakeupSource);
                    }
                    result = E_OK;
                    break;
                }
            }
        }
    }
    return result;
}
#endif /*STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALID_SUPPORT*/
#if (STD_ON == CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT)
/*************************************************************************/
/*
 * Brief               This service reports, if any TX confirmation has been done for the whole
 *                     CAN controller since the last CAN controller start.
 * ServiceId           0x19
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant (Not for the same controller)
 * Param-Name[in]      ControllerId: Abstracted CanIf ControllerId which is assigned to a CAN controller
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              CanIf_NotifStatusType:Combined TX confirmation status for all TX PDUs of the CAN controller
 * PreCondition        CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT is TRUE
 * CallByAPI           Up layer(CanSM)
 */
/*************************************************************************/
FUNC(CanIf_NotifStatusType, CANIF_CODE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
CanIf_GetTxConfirmationState(uint8 ControllerId)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
    CanIf_NotifStatusType result = CANIF_NO_NOTIFICATION;
#if (STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    /* check initiation */
    if (CANIF_INITED != CanIf_InitStatus)
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_GETTXCONFIRMATIONSTATE, CANIF_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (ControllerId >= CANIF_CANCONTROLLER_NUMBER))
    {
        (void)Det_ReportError(
            CANIF_MODULE_ID,
            CANIF_INSTANCE_ID,
            CANIF_GETTXCONFIRMATIONSTATE,
            CANIF_E_PARAM_CONTROLLERID);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif /*STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT*/
    {
        /* get the  TX confirmation state of the corresponding controller */
        result = CanIf_TxConfirmationState[ControllerId];
        /* clear the state */
        CanIf_TxConfirmationState[ControllerId] = CANIF_NO_NOTIFICATION;
    }
    return result;
}
#endif /*STD_ON == CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT*/
#if (STD_ON == CANIF_PUBLIC_PN_SUPPORT)
/*************************************************************************/
/*
 * Brief               Requests the CanIf module to clear the WUF flag of the designated CAN transceiver.
 * ServiceId           0x1e
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant for different CAN transceivers
 * Param-Name[in]      TransceiverId: Abstract CanIf TransceiverId, which is assigned to the designated CAN transceiver.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: Request has been accepted
 *                     E_NOT_OK: Request has not been accepted
 * PreCondition        CANIF_PUBLIC_PN_SUPPORT is TRUE
 * CallByAPI           Up layer(CanSM)
 */
/*************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
CanIf_ClearTrcvWufFlag(uint8 TransceiverId)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
    Std_ReturnType result = E_NOT_OK;
    uint8 trcvDriver;
    const CanIf_TrcvCfgType* trcvConfigPtr = &CANIF_TRCV(TransceiverId);
#if (STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    /* check initiation */
    if (CANIF_INITED != CanIf_InitStatus)
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_CLEARTRCVWUFFLAG_ID, CANIF_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (TransceiverId >= CANIF_TRCV_NUMBER))
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_CLEARTRCVWUFFLAG_ID, CANIF_E_PARAM_TRCV);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif /*STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT*/
    {
        trcvDriver = trcvConfigPtr->CanTrcvDriverId;
        result = Can_TrcvApi[trcvDriver].CanTrcvClearTrcvWufFlagApi(trcvConfigPtr->CanIfTrcvCanTrcvRef->CanTrcvId);
    }
    return result;
}
/*************************************************************************/
/*
 * Brief               Requests the CanIf module to check the Wake flag of the designated CAN transceiver.
 * ServiceId           0x1f
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant for different CAN transceivers
 * Param-Name[in]      TransceiverId: Abstract CanIf TransceiverId, which is assigned to the designated CAN transceiver.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: Request has been accepted
 *                     E_NOT_OK: Request has not been accepted
 * PreCondition        CANIF_PUBLIC_PN_SUPPORT is TRUE
 * CallByAPI           Up layer(CanSM)
 */
/*************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
CanIf_CheckTrcvWakeFlag(uint8 TransceiverId)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
    Std_ReturnType result = E_NOT_OK;
    uint8 trcvDriver;
    const CanIf_TrcvCfgType* trcvConfigPtr = &CANIF_TRCV(TransceiverId);
#if (STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    /* check initiation */
    if (CANIF_INITED != CanIf_InitStatus)
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_CHECKTRCVWAKEFLAG_ID, CANIF_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (TransceiverId >= CANIF_TRCV_NUMBER))
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_CHECKTRCVWAKEFLAG_ID, CANIF_E_PARAM_TRCV);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif /*STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT*/
    {
        trcvDriver = trcvConfigPtr->CanTrcvDriverId;
        result = Can_TrcvApi[trcvDriver].CanTrcvCheckWakeFlagApi(trcvConfigPtr->CanIfTrcvCanTrcvRef->CanTrcvId);
    }
    return result;
}
#endif /*STD_ON == CANIF_PUBLIC_PN_SUPPORT*/
#if (STD_ON == CANIF_SET_BAUDRATE_API)
/*************************************************************************/
/*
 * Brief               This service shall set the baud rate configuration of the CAN controller.
 *                     Depending on necessary baud rate modifications the controller might have to reset.
 * ServiceId           0x27
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different ControllerIds. Non reentrant for the same ControllerId.
 * Param-Name[in]      ControllerId: Abstract CanIf ControllerId which is assigned to a CAN controller, whose baud rate
 * shall be set. BaudRateConfigID: references a baud rate configuration by ID (see CanControllerBaudRateConfigID)
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: Service request accepted, setting of (new) baud rate started
 *                     E_NOT_OK: Service request not accepted
 * PreCondition        CANIF_SET_BAUDRATE_API is TRUE
 * CallByAPI           Up layer
 */
/*************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE)
CanIf_SetBaudrate(uint8 ControllerId, uint16 BaudRateConfigID)
{
    Std_ReturnType result = E_NOT_OK;
    uint8 canDriver;
    const CanIf_ControllerCfgType* controllerPtr = &CANIF_CONTROLLER(ControllerId);
#if (STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    /* check initiation */
    if (CANIF_INITED != CanIf_InitStatus)
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_SETBAUDRATE_ID, CANIF_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (ControllerId >= CANIF_CANCONTROLLER_NUMBER))
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_SETBAUDRATE_ID, CANIF_E_PARAM_CONTROLLERID);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif /*STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT*/
    {
        canDriver = controllerPtr->CanDriverId;
        result =
            Can_DriverApi[canDriver].CanSetBaudrateApi(controllerPtr->CanIfCtrlCanCtrlRef->CanCtrlId, BaudRateConfigID);
    }
    return result;
}
#endif /*STD_ON == CANIF_SET_BAUDRATE_API*/
#if (STD_ON == CANIF_PUBLIC_ICOM_SUPPORT)
/*************************************************************************/
/*
 * Brief               This service shall change the Icom Configuration of a CAN controller to the requested one.
 * ServiceId           0x25
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant only for different controller Ids
 * Param-Name[in]      ControllerId: Abstracted CanIf Controller Id which is assigned to a CAN controller.
 *                     ConfigurationId: Requested Configuration
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: Request accepted
 *                     E_NOT_OK: Request denied
 * PreCondition        CANIF_PUBLIC_ICOM_SUPPORT is TRUE
 * CallByAPI           Up layer
 */
/*************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE)
CanIf_SetIcomConfiguration(uint8 ControllerId, IcomConfigIdType ConfigurationId)
{
    Std_ReturnType result = E_NOT_OK;
    uint8 canDriver;
    const CanIf_ControllerCfgType* controllerPtr = &CANIF_CONTROLLER(ControllerId);
#if (STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    /* check initiation */
    if (CANIF_INITED != CanIf_InitStatus)
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_SETICOMCONFIGURATION_ID, CANIF_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (ControllerId >= CANIF_CANCONTROLLER_NUMBER))
    {
        (void)Det_ReportError(
            CANIF_MODULE_ID,
            CANIF_INSTANCE_ID,
            CANIF_SETICOMCONFIGURATION_ID,
            CANIF_E_PARAM_CONTROLLERID);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif /*STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT*/
    {
        canDriver = controllerPtr->CanDriverId;
        result = Can_DriverApi[canDriver].CanSetIcomConfigurationApi(
            controllerPtr->CanIfCtrlCanCtrlRef->CanCtrlId,
            ConfigurationId);
    }
    return result;
}
#endif /*STD_ON == CANIF_PUBLIC_ICOM_SUPPORT*/
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
/*******************************************************************************
**                      CallBack API                                          **
*******************************************************************************/
#if (STD_ON == CANIF_TRIGGER_TRANSMIT_SUPPORT)
/*************************************************************************/
/*
 * Brief               Within this API, the upper layer module (called module) shall check
 *                     whether the available data fits into the buffer size reported by PduInfoPtr-
 *                     >SduLength. If it fits, it shall copy its data into the buffer provided by
 *                     PduInfoPtr->SduDataPtr and update the length of the actual copied data in
 *                     PduInfoPtr->SduLength. If not, it returns E_NOT_OK without changing PduInfoPtr.
 * ServiceId           0x41
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different PduIds. Non reentrant for the same PduId.
 * Param-Name[in]      TxPduId: ID of the SDU that is requested to be transmitted.
 * Param-Name[out]     None
 * Param-Name[in/out]  PduInfoPtr: Contains a pointer to a buffer (SduDataPtr) to where the SDU data
 *                     shall be copied, and the available buffer size in SduLengh.On return, the
 *                     service will indicate the length of the copied SDU data in SduLength.
 * Return              Std_ReturnType
 *                     E_OK: SDU has been copied and SduLength indicates the number of copied bytes.
 *                     E_NOT_OK: No SDU data has been copied. PduInfoPtr must not be used since it may
 *                     contain a NULL pointer or point to invalid data.
 * PreCondition        CANIF_TRIGGER_TRANSMIT_SUPPORT is TRUE
 * CallByAPI           Lo layer
 */
/*************************************************************************/
#define CANIF_START_SEC_CANIFTRIGGERTRANSMIT_CALLBACK_CODE
#include "CanIf_MemMap.h"
FUNC(Std_ReturnType, CANIF_CODE)
CanIf_TriggerTransmit(PduIdType TxPduId, P2VAR(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr)
{
    Std_ReturnType result = E_NOT_OK;
    const CanIf_TxPduConfigType* txPduConfigPtr = &CANIF_TXPDU(TxPduId);
    if (TRUE == txPduConfigPtr->CanIfTxPduTriggerTransmit)
    {
        if (NULL_PTR != txPduConfigPtr->CanIfTxPduUserTriggerTransmitName)
        {
            result = txPduConfigPtr->CanIfTxPduUserTriggerTransmitName(
                txPduConfigPtr->CanIfTxPduRef->CanIfUpPduId,
                PduInfoPtr);
        }
    }
    return result;
}
#define CANIF_STOP_SEC_CANIFTRIGGERTRANSMIT_CALLBACK_CODE
#include "CanIf_MemMap.h"
#endif /*STD_ON == CANIF_TRIGGER_TRANSMIT_SUPPORT*/
/*************************************************************************/
/*
 * Brief               This service confirms a previously successfully processed transmission of a CAN TxPDU.
 * ServiceId           0x13
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      CanTxPduId: L-PDU handle of CAN L-PDU successfully transmitted.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Can driver
 */
/*************************************************************************/
#define CANIF_START_SEC_CANIFTXCONFIRMATION_CALLBACK_CODE
#include "CanIf_MemMap.h"
FUNC(void, CANIF_CODE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
CanIf_TxConfirmation(PduIdType CanTxPduId)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
    const CanIf_TxPduConfigType* txPduConfigPtr = &CANIF_TXPDU(CanTxPduId);
#if (                                                                                   \
    (CANIF_TXBUFFER_NUMBER > 0u) || (STD_ON == CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT) \
    || (STD_ON == CANIF_PUBLIC_PN_SUPPORT))
    uint8 controllerId;
    Can_HwHandleType hthIndex;
    const CanIfHthCfgType* hthPtr;
#endif /*(CANIF_TXBUFFER_NUMBER > 0u) || (STD_ON == CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT) ||(STD_ON == \
          CANIF_PUBLIC_PN_SUPPORT)*/
#if (CANIF_TXBUFFER_NUMBER > 0u)
    PduIdType txBufIndex;
    uint8 index;
    uint8 canDriver;
    uint8 txBufSize;
    uint8 txIndex = CANIF_UNUSED_UINT8;
    Can_PduType canPdu;
    Can_ReturnType canRetValue;
    Can_HwHandleType hthId;
    CanIf_TxPduBufferType* txPduBufferPtr;
#endif /*CANIF_TXBUFFER_NUMBER > 0u*/
#if (STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    /* check initiation */
    if (CANIF_INITED != CanIf_InitStatus)
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_TXCONFIRMATION_ID, CANIF_E_UNINIT);
        detNoErr = FALSE;
    }
    /* check parameter valid */
    if ((TRUE == detNoErr) && (CanTxPduId >= CANIF_TXPDU_NUMBER))
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_TXCONFIRMATION_ID, CANIF_E_PARAM_LPDU);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif /*STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT*/
    {
#if (                                                                                   \
    (CANIF_TXBUFFER_NUMBER > 0u) || (STD_ON == CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT) \
    || (STD_ON == CANIF_PUBLIC_PN_SUPPORT))
        hthIndex = txPduConfigPtr->CanIfTxPduHthId;
        hthPtr = &CANIF_HTH(hthIndex);
        controllerId = hthPtr->CanIfHthCanCtrlId;
#endif /*(CANIF_TXBUFFER_NUMBER > 0u) || (STD_ON == CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT) ||(STD_ON == \
          CANIF_PUBLIC_PN_SUPPORT)*/
#if (CANIF_TXBUFFER_NUMBER > 0u)
        txBufIndex = txPduConfigPtr->TxBufferIdndex;
        if (txBufIndex < CANIF_TXBUFFER_NUMBER)
        {
            txBufSize = CANIF_TXBUFFER_SIZE(txBufIndex);
            txPduBufferPtr = CanIf_TxBuffer[txBufIndex].CanIf_TxPduBufferRef;

            SchM_Enter_CanIf();
            for (index = 0u; index < txBufSize; index++)
            {
                if (TRUE == txPduBufferPtr[index].used)
                {
                    if (CANIF_UNUSED_UINT8 == txIndex)
                    {
                        canPdu.id = (txPduBufferPtr[index].canId) & CANIF_EXTENDED_CANID_MAX;
                        txIndex = index;
                    }
                    else
                    {
                        if (canPdu.id > ((txPduBufferPtr[index].canId) & CANIF_EXTENDED_CANID_MAX))
                        {
                            canPdu.id = (txPduBufferPtr[index].canId) & CANIF_EXTENDED_CANID_MAX;
                            txIndex = index;
                        }
                    }
                }
            }
            if (CANIF_UNUSED_UINT8 != txIndex)
            {
                hthId = hthPtr->CanIfHthIdSymRef->CanObjectId;
                canPdu.length = txPduBufferPtr[txIndex].length;
                canPdu.sdu = txPduBufferPtr[txIndex].data;
                canPdu.swPduHandle = txPduBufferPtr[txIndex].TxPduIndex;
                canPdu.id = txPduBufferPtr[txIndex].canId;
                canDriver = CANIF_CONTROLLER(controllerId).CanDriverId;
                canRetValue = Can_DriverApi[canDriver].CanWriteApi(hthId, &canPdu);
                if (CAN_OK == canRetValue)
                {
                    txPduBufferPtr[txIndex].used = FALSE;
                }
            }
            SchM_Exit_CanIf();
        }
#endif /*CANIF_TXBUFFER_NUMBER > 0u*/
/* enable notify status */
#if (CANIF_TXNOTIFYSTATUS_BUFFER > 0u)
        if (TRUE == txPduConfigPtr->CanIfTxPduReadNotifyStatus)
        {
            /* change to notify status */
            CanIf_TxNotifStatus[txPduConfigPtr->CanIfTxNotifyIndex] = CANIF_TX_RX_NOTIFICATION;
        }
#endif /*CANIF_TXNOTIFYSTATUS_BUFFER > 0u*/
#if (STD_ON == CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT)
        if (CANIF_CS_STARTED == CanIf_ControllerMode[controllerId])
        {
            CanIf_TxConfirmationState[controllerId] = CANIF_TX_RX_NOTIFICATION;
        }
#endif /*STD_ON == CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT*/
        if (NULL_PTR != txPduConfigPtr->CanIfTxPduUserTxConfirmationName)
        {
            /* call upper layer function,feedback to upper layer*/
            txPduConfigPtr->CanIfTxPduUserTxConfirmationName(txPduConfigPtr->CanIfTxPduRef->CanIfUpPduId);
        }
#if (STD_ON == CANIF_PUBLIC_PN_SUPPORT)
        if (TRUE == CANIF_CONTROLLER(controllerId).CanIfPnFilter)
        {
            CanIf_PnTxFilter[controllerId] = FALSE;
        }
#endif /*STD_ON == CANIF_PUBLIC_PN_SUPPORT*/
    }
    return;
}
#define CANIF_STOP_SEC_CANIFTXCONFIRMATION_CALLBACK_CODE
#include "CanIf_MemMap.h"
/*************************************************************************/
/*
 * Brief               This service indicates a successful reception of a received CAN Rx LPDU
 *                     to the CanIf after passing all filters and validation checks.
 * ServiceId           0x14
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      Mailbox: Identifies the HRH and its corresponding CAN Controller
 *                     PduInfoPtr: Pointer to the received L-PDU
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Can driver
 */
/*************************************************************************/
#define CANIF_START_SEC_CANIFRXINDICATION_CALLBACK_CODE
#include "CanIf_MemMap.h"
FUNC(void, CANIF_CODE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
CanIf_RxIndication(
    P2CONST(Can_HwType, AUTOMATIC, CANIF_APPL_DATA) Mailbox,
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
    PduIdType rxPduIndex = 0u;
#if (STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    /* check initiation */
    if (CANIF_INITED != CanIf_InitStatus)
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_RXINDICATION_ID, CANIF_E_UNINIT);
        detNoErr = FALSE;
    }
    /* check parameter valid */
    if ((TRUE == detNoErr) && ((NULL_PTR == Mailbox) || (NULL_PTR == PduInfoPtr)))
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_RXINDICATION_ID, CANIF_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
    {
        /*Extended Frame*/
        if (0x80000000u <= (Mailbox->CanId))
        {
            if (0x80000000u != ((Mailbox->CanId) & 0xa0000000u))
            {
                (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_RXINDICATION_ID, CANIF_E_PARAM_CANID);
                detNoErr = FALSE;
            }
        }
        /*Standard frame*/
        else
        {
            if (0x00000000u != ((Mailbox->CanId) & 0xbffff800u))
            {
                (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_RXINDICATION_ID, CANIF_E_PARAM_CANID);
                detNoErr = FALSE;
            }
        }
    }
    if (TRUE == detNoErr)
#endif /*STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT*/
    {
            if(((0xFF == CCUWakeupReturnValue)||(0x22 == CCUWakeupReturnValue)||(0x31 == CCUWakeupReturnValue))&&(0x55 != App_ComMReqFlag)&&(100 > FirstWakeUpSource500ms ))
            {
                if((((Mailbox->CanId)>= 0x40000400u)&&((Mailbox->CanId)<= 0x400004FFu)&&((0 == (Mailbox->ControllerId))||(5 == (Mailbox->ControllerId))))
                    ||(((Mailbox->CanId)>= 0x00000400u)&&((Mailbox->CanId)<= 0x000004FFu)&&(3 == (Mailbox->ControllerId))))
                {
                    CCUWakeupReturnValue = 0x11;
                }
                else
                {
                    CCUWakeupReturnValue = 0x12;
                }        
            }
        if (E_OK == CanIf_CanIdRangCheck(Mailbox->ControllerId, Mailbox->Hoh, Mailbox->CanId, &rxPduIndex))
        {
/* DLC check enabled */
#if (STD_ON == CANIF_PRIVATE_DLC_CHECK)
            if (PduInfoPtr->SduLength < (CANIF_RXPDU(rxPduIndex).CanIfRxPduDlc))
            {
                (void)Det_ReportRuntimeError(
                    CANIF_MODULE_ID,
                    CANIF_INSTANCE_ID,
                    CANIF_RXINDICATION_ID,
                    CANIF_E_INVALID_DLC);
            }
            else
#endif /*STD_ON == CANIF_PRIVATE_DLC_CHECK*/
            {
                SchM_Enter_CanIf();
                CanIf_DiagPduRoute(Mailbox->CanId,rxPduIndex,PduInfoPtr);
                CanIf_RxIndicationHandle(
                    rxPduIndex,
#if (STD_ON == CANIF_META_DATA_SUPPORT)
                    Mailbox->CanId,
#endif
                    PduInfoPtr);
                SchM_Exit_CanIf();
            }
#if (STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALID_SUPPORT)
#if (STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALID_BY_NM)
            if (TRUE == CANIF_RXPDU(rxPduIndex).CanIfRxPduForNM)
            {
                /* set first call rxindication event flag */
                CanIf_FirstCallRxInd[Mailbox->ControllerId] = TRUE;
            }
#else
            /* set first call rxindication event flag */
            CanIf_FirstCallRxInd[Mailbox->ControllerId] = TRUE;
#endif /*STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALID_BY_NM*/
#endif /*STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALID_SUPPORT*/
        }
    }
    return;
}
#define CANIF_STOP_SEC_CANIFRXINDICATION_CALLBACK_CODE
#include "CanIf_MemMap.h"
/*************************************************************************/
/*
 * Brief               This service indicates a Controller BusOff event referring to
 *                     the corresponding CAN Controller with the abstract CanIf ControllerId.
 * ServiceId           0x16
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ControllerId: Abstract CanIf ControllerId which is assigned to a CAN
 *                     controller, where a BusOff occured.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Can driver
 */
/*************************************************************************/
#define CANIF_START_SEC_CANIFCONTROLLERBUSOFF_CALLBACK_CODE
#include "CanIf_MemMap.h"
FUNC(void, CANIF_CODE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
CanIf_ControllerBusOff(uint8 ControllerId)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
#if (STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (CANIF_INITED != CanIf_InitStatus)
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_CONTROLLERBUSOFF_ID, CANIF_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (ControllerId >= CANIF_CANCONTROLLER_NUMBER))
    {
        (void)
            Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_CONTROLLERBUSOFF_ID, CANIF_E_PARAM_CONTROLLERID);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif /*STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT*/
    {
#if (STD_ON == CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT)
        CanIf_TxConfirmationState[ControllerId] = CANIF_NO_NOTIFICATION;
#endif
        /* set controller to STOP status */
        CanIf_ControllerMode[ControllerId] = CANIF_CS_STOPPED;
        /*set the PDU channel mode of the corresponding channel to CANIF_TX_OFFLINE*/
        CanIf_PduMode[ControllerId] = CANIF_TX_OFFLINE;
/* free tx buffer if enabled */
#if (CANIF_TXBUFFER_NUMBER > 0u)
        CanIf_FreeControllerTxBuffer(ControllerId);
#endif
        if (NULL_PTR != CanIf_DispatchConfigData.CanIfDispatchUserCtrlBusOffName)
        {
            CanIf_DispatchConfigData.CanIfDispatchUserCtrlBusOffName(ControllerId);
        }
    }
    return;
}
#define CANIF_STOP_SEC_CANIFCONTROLLERBUSOFF_CALLBACK_CODE
#include "CanIf_MemMap.h"
#if (STD_ON == CANIF_PUBLIC_PN_SUPPORT)
/*************************************************************************/
/*
 * Brief               This service indicates that the transceiver is running in PN
 *                     communication mode referring to the corresponding CAN transceiver
 *                     with the abstract CanIf TransceiverId.
 * ServiceId           0x1a
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      TransceiverId: Abstract CanIf TransceiverId, which is assigned to
 *                     a CAN transceiver, which was checked for PN availability.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        CANIF_PUBLIC_PN_SUPPORT is TRUE
 * CallByAPI           CanTrcv driver
 */
/*************************************************************************/
#define CANIF_START_SEC_CANIFCONFIRMPNAVAILABILITY_CALLBACK_CODE
#include "CanIf_MemMap.h"
FUNC(void, CANIF_CODE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
CanIf_ConfirmPnAvailability(uint8 TransceiverId)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
#if (STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (CANIF_INITED != CanIf_InitStatus)
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_CONFIRMPNAVAILABILITY_ID, CANIF_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (TransceiverId >= CANIF_TRCV_NUMBER))
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_CONFIRMPNAVAILABILITY_ID, CANIF_E_PARAM_TRCV);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif /*STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT*/
    {
        if (NULL_PTR != CanIf_DispatchConfigData.CanIfDispatchUserConfirmPnAvailabilityName)
        {
            CanIf_DispatchConfigData.CanIfDispatchUserConfirmPnAvailabilityName(TransceiverId);
        }
    }
    return;
}
#define CANIF_STOP_SEC_CANIFCONFIRMPNAVAILABILITY_CALLBACK_CODE
#include "CanIf_MemMap.h"
/*************************************************************************/
/*
 * Brief               This service indicates that the transceiver has cleared the WufFlag
 *                     referring to the corresponding CAN transceiver with the abstract CanIf TransceiverId.
 * ServiceId           0x20
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      TransceiverId: Abstract CanIf TransceiverId, which is assigned to a CAN transceiver,
 *                     for which this function was called.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        CANIF_PUBLIC_PN_SUPPORT is TRUE
 * CallByAPI           CanTrcv driver
 */
/*************************************************************************/
#define CANIF_START_SEC_CANIFCLEARTRCVWUFFLAGINDICATION_CALLBACK_CODE
#include "CanIf_MemMap.h"
FUNC(void, CANIF_CODE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
CanIf_ClearTrcvWufFlagIndication(uint8 TransceiverId)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
#if (STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (CANIF_INITED != CanIf_InitStatus)
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_CLEARTRCVWUFFLAGINDICATION_ID, CANIF_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (TransceiverId >= CANIF_TRCV_NUMBER))
    {
        (void)Det_ReportError(
            CANIF_MODULE_ID,
            CANIF_INSTANCE_ID,
            CANIF_CLEARTRCVWUFFLAGINDICATION_ID,
            CANIF_E_PARAM_TRCV);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif /*STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT*/
    {
        if (NULL_PTR != CanIf_DispatchConfigData.CanIfDispatchUserClearTrcvWufFlagIndicationName)
        {
            CanIf_DispatchConfigData.CanIfDispatchUserClearTrcvWufFlagIndicationName(TransceiverId);
        }
    }
    return;
}
#define CANIF_STOP_SEC_CANIFCLEARTRCVWUFFLAGINDICATION_CALLBACK_CODE
#include "CanIf_MemMap.h"
/*************************************************************************/
/*
 * Brief               This service indicates that the check of the transceiver!/s wake-up flag
 *                     has been finished by the corresponding CAN transceiver with the abstract
 *                     CanIf TransceiverId. This indication is used to cope with the asynchronous
 *                     transceiver communication.
 * ServiceId           0x21
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      TransceiverId: Abstract CanIf TransceiverId, which is assigned to a CAN
 *                     transceiver, for which this function was called.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        CANIF_PUBLIC_PN_SUPPORT is TRUE
 * CallByAPI           CanTrcv driver
 */
/*************************************************************************/
#define CANIF_START_SEC_CANIFCHECKTRCVWAKEFLAGINDICATION_CALLBACK_CODE
#include "CanIf_MemMap.h"
FUNC(void, CANIF_CODE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
CanIf_CheckTrcvWakeFlagIndication(uint8 TransceiverId)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
#if (STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (CANIF_INITED != CanIf_InitStatus)
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_CHECKTRCVWAKEFLAGINDICATION_ID, CANIF_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (TransceiverId >= CANIF_TRCV_NUMBER))
    {
        (void)Det_ReportError(
            CANIF_MODULE_ID,
            CANIF_INSTANCE_ID,
            CANIF_CHECKTRCVWAKEFLAGINDICATION_ID,
            CANIF_E_PARAM_TRCV);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif /*STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT*/
    {
        if (NULL_PTR != CanIf_DispatchConfigData.CanIfDispatchUserCheckTrcvWakeFlagIndicationName)
        {
            CanIf_DispatchConfigData.CanIfDispatchUserCheckTrcvWakeFlagIndicationName(TransceiverId);
        }
    }
    return;
}
#define CANIF_STOP_SEC_CANIFCHECKTRCVWAKEFLAGINDICATION_CALLBACK_CODE
#include "CanIf_MemMap.h"
#endif /*STD_ON == CANIF_PUBLIC_PN_SUPPORT*/
/*************************************************************************/
/*
 * Brief               This service indicates a controller state transition referring
 *                     to the corresponding CAN controller with the abstract CanIf ControllerId.
 * ServiceId           0x17
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ControllerId: Abstract CanIf ControllerId which is assigned to a
 *                     CAN controller, which state has been transitioned.
 *                     ControllerMode: Mode to which the CAN controller transitioned
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Can driver
 */
/*************************************************************************/
#define CANIF_START_SEC_CANIFCONTROLLERMODEINDICATION_CALLBACK_CODE /* PRQA S 0791 */ /* MISRA Rule 5.4 */
#include "CanIf_MemMap.h"
FUNC(void, CANIF_CODE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
CanIf_ControllerModeIndication(uint8 ControllerId, CanIf_ControllerModeType ControllerMode)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
#if (STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (CANIF_INITED != CanIf_InitStatus)
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_CONTROLLERMODEINDICATION_ID, CANIF_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (ControllerId >= CANIF_CANCONTROLLER_NUMBER))
    {
        (void)Det_ReportError(
            CANIF_MODULE_ID,
            CANIF_INSTANCE_ID,
            CANIF_CONTROLLERMODEINDICATION_ID,
            CANIF_E_PARAM_CONTROLLERID);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif /*STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT*/
    {
        /* store controller status */
        CanIf_ControllerMode[ControllerId] = ControllerMode;
        if (NULL_PTR != CanIf_DispatchConfigData.CanIfDispatchUserCtrlModeIndicationName)
        {
            CanIf_DispatchConfigData.CanIfDispatchUserCtrlModeIndicationName(ControllerId, ControllerMode);
        }
    }
    return;
}

#define CANIF_STOP_SEC_CANIFCONTROLLERMODEINDICATION_CALLBACK_CODE
#include "CanIf_MemMap.h"
#if (CANIF_TRCV_NUMBER > 0u)
/*************************************************************************/
/*
 * Brief               This service indicates a transceiver state transition referring
 *                     to the corresponding CAN transceiver with the abstract CanIf TransceiverId.
 * ServiceId           0x22
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      TransceiverId: Abstract CanIf TransceiverId, which is assigned to a
 *                     CAN transceiver, which state has been transitioned.
 *                     TransceiverMode Mode to which the CAN transceiver transitioned
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        CANIF_TRCV_NUMBER > 0
 * CallByAPI           CanTrcv driver
 */
/*************************************************************************/
#define CANIF_START_SEC_CANIFTRCVMODEINDICATION_CALLBACK_CODE
#include "CanIf_MemMap.h"
FUNC(void, CANIF_CODE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
CanIf_TrcvModeIndication(uint8 TransceiverId, CanTrcv_TrcvModeType TransceiverMode)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
#if (STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (CANIF_INITED != CanIf_InitStatus)
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_TRCVMODEINDICATION_ID, CANIF_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (TransceiverId >= CANIF_TRCV_NUMBER))
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_TRCVMODEINDICATION_ID, CANIF_E_PARAM_TRCV);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif /*STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT*/
    {
        if (NULL_PTR != CanIf_DispatchConfigData.CanIfDispatchUserTrcvModeIndicationName)
        {
            CanIf_DispatchConfigData.CanIfDispatchUserTrcvModeIndicationName(TransceiverId, TransceiverMode);
        }
    }
    return;
}
#define CANIF_STOP_SEC_CANIFTRCVMODEINDICATION_CALLBACK_CODE
#include "CanIf_MemMap.h"
#endif /*CANIF_TRCV_NUMBER >0*/
#if (STD_ON == CANIF_PUBLIC_ICOM_SUPPORT)
/*************************************************************************/
/*
 * Brief               This service shall inform about the change of the Icom Configuration of
 *                     a CAN controller using the abstract CanIf ControllerId.
 * ServiceId           0x26
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant only for different controller Ids
 * Param-Name[in]      ControllerId: Abstract CanIf ControllerId which is assigned to a CAN
 *                     controller, which informs about the Configuration Id.
 *                     ConfigurationId: Active Configuration Id.
 *                     Error:
 *                     ICOM_SWITCH_E_OK: No Error
 *                     ICOM_SWITCH_E_FAILED: Switch to requested Configuration failed. Severe Error.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        CANIF_PUBLIC_ICOM_SUPPORT is TRUE
 * CallByAPI           Can driver
 */
/*************************************************************************/
#define CANIF_START_SEC_CANIFCURRENTICOMCONFIGURATION_CALLBACK_CODE
#include "CanIf_MemMap.h"
FUNC(void, CANIF_CODE)
CanIf_CurrentIcomConfiguration(uint8 ControllerId, IcomConfigIdType ConfigurationId, IcomSwitch_ErrorType Error)
{
#if (STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (CANIF_INITED != CanIf_InitStatus)
    {
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_CURRENTICOMCONFIGURATION_ID, CANIF_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (ControllerId >= CANIF_CANCONTROLLER_NUMBER))
    {
        (void)Det_ReportError(
            CANIF_MODULE_ID,
            CANIF_INSTANCE_ID,
            CANIF_CURRENTICOMCONFIGURATION_ID,
            CANIF_E_PARAM_CONTROLLERID);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif /*STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT*/
    {
        CanSM_CurrentIcomConfiguration(ControllerId, ConfigurationId, Error);
    }
    return;
}
#define CANIF_STOP_SEC_CANIFCURRENTICOMCONFIGURATION_CALLBACK_CODE
#include "CanIf_MemMap.h"
#endif /*STD_ON == CANIF_PUBLIC_ICOM_SUPPORT*/
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
/*************************************************************************/
/*
 * Brief               Set controller state to start
 * ServiceId           None
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant (Not for the same controller)
 * Param-Name[in]      Controller: Number of controller
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 * PreCondition        None
 * CallByAPI           CanIf_SetControllerMode
 */
/*************************************************************************/
static FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetControllStarted(uint8 Controller)
{
    Std_ReturnType result = E_NOT_OK;
    uint8 controllerId;
    uint8 canDriverId;
    const CanIf_ControllerCfgType* controllerPtr = &CANIF_CONTROLLER(Controller);
    /*find which Can Driver API can be invoked*/
    canDriverId = controllerPtr->CanDriverId;
    /* get Can controller Id,defined in Can Driver */
    controllerId = controllerPtr->CanIfCtrlCanCtrlRef->CanCtrlId;
    if (CAN_OK == Can_DriverApi[canDriverId].CanSetControllerModeApi(controllerId, CAN_T_START))
    {
        result = E_OK;
    }
    return result;
}
/*************************************************************************/
/*
 * Brief               Set controller state to sleep
 * ServiceId           None
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant (Not for the same controller)
 * Param-Name[in]      Controller: Number of controller
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 * PreCondition        None
 * CallByAPI           CanIf_SetControllerMode
 */
/*************************************************************************/
static FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetControllSleep(uint8 Controller)
{
    Std_ReturnType result = E_NOT_OK;
    uint8 controllerId;
    uint8 canDriverId;
    const CanIf_ControllerCfgType* controllerPtr = &CANIF_CONTROLLER(Controller);
    /*find which Can Driver API can be invoked*/
    canDriverId = controllerPtr->CanDriverId;
    /* get Can controller Id,defined in Can Driver */
    controllerId = controllerPtr->CanIfCtrlCanCtrlRef->CanCtrlId;
    if (CAN_OK == Can_DriverApi[canDriverId].CanSetControllerModeApi(controllerId, CAN_T_SLEEP))
    {
#if (STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALID_SUPPORT)
        /* Clear first call rxindication event flag While Sleep */
        CanIf_FirstCallRxInd[Controller] = FALSE;
#endif
        /*set the PDU channel mode of the corresponding channel to CANIF_OFFLINE*/
        CanIf_PduMode[Controller] = CANIF_OFFLINE;
/* free tx buffer if enabled */
#if (CANIF_TXBUFFER_NUMBER > 0u)
        CanIf_FreeControllerTxBuffer(Controller);
#endif
#if (STD_ON == CANIF_PUBLIC_PN_SUPPORT)
        if (TRUE == controllerPtr->CanIfPnFilter)
        {
            CanIf_PnTxFilter[Controller] = TRUE;
        }
#endif
        result = E_OK;
    }
    return result;
}
/*************************************************************************/
/*
 * Brief               Set controller state to stop
 * ServiceId           None
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant (Not for the same controller)
 * Param-Name[in]      Controller: Number of controller
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 * PreCondition        None
 * CallByAPI           CanIf_SetControllerMode
 */
/*************************************************************************/
static FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetControllStopped(uint8 Controller)
{
    Std_ReturnType result = E_NOT_OK;
    uint8 controllerId;
    uint8 canDriverId;
    const CanIf_ControllerCfgType* controllerPtr = &CANIF_CONTROLLER(Controller);
    /*find which Can Driver API can be invoked*/
    canDriverId = controllerPtr->CanDriverId;
    /* get Can controller Id,defined in Can Driver */
    controllerId = controllerPtr->CanIfCtrlCanCtrlRef->CanCtrlId;
    /* current mode is SLEEP */
    if (CANIF_CS_SLEEP == CanIf_ControllerMode[Controller])
    {
        /* wake up the controller */
        if (CAN_OK == Can_DriverApi[canDriverId].CanSetControllerModeApi(controllerId, CAN_T_WAKEUP))
        {
            /*set the PDU channel mode of the corresponding channel to CANIF_TX_OFFLINE*/
            CanIf_PduMode[Controller] = CANIF_TX_OFFLINE;
            result = E_OK;
        }
    }
    else
    {
        /* set controller mode STOP */
        if (CAN_OK == Can_DriverApi[canDriverId].CanSetControllerModeApi(controllerId, CAN_T_STOP))
        {
            CanIf_FreeBufInStopped(Controller);
            /*set the PDU channel mode of the corresponding channel to CANIF_TX_OFFLINE*/
            CanIf_PduMode[Controller] = CANIF_TX_OFFLINE;
            result = E_OK;
        }
    }
    return result;
}
/*************************************************************************/
/*
 * Brief               Check (Basic Can) CanId and find the rxpduId
 * ServiceId           None
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      hrhId: ID of the corresponding hardware object
 *                     CanId: Standard/Extended CAN ID of CAN L-PDU that
 *                     has been successfully received
 * Param-Name[out]     pduIdIndex:the rx pdu that receive the can message
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 * PreCondition        None
 * CallByAPI           CanIf_RxIndication
 */
/*************************************************************************/
static FUNC(Std_ReturnType, CANIF_CODE) CanIf_CanIdRangCheck(
    uint8 controllerId,
    Can_HwHandleType hrhId,
    Can_IdType canId,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(PduIdType, AUTOMATIC, AUTOMATIC) pduIdIndex)
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
{
    Can_HwHandleType canIfHrhId;
    Can_HwHandleType cnt;
    boolean findCanIfHrh = FALSE;
    Std_ReturnType result = E_NOT_OK;
    uint8 hrhCanIdRangeNum;
    boolean hrhFilterIsOk = FALSE;
/*The controllerId is CanIf's controller index*/
#if (STD_ON == CANIF_RXINDICATION_AUTOSAR_PARAMETER)
    /*The hrhId is CanIf's HRH index*/
    if (CANIF_HRH(hrhId).CanIfHrhCanCtrlId == controllerId)
    {
        findCanIfHrh = TRUE;
        canIfHrhId = hrhId;
    }
#else
    /*The hrhId is Can's HardwareObject index*/
    uint8 canDriverId;
    if (controllerId <= CANIF_CANCONTROLLER_NUMBER)
    {
        canDriverId = CANIF_CONTROLLER(controllerId).CanDriverId;
        if (hrhId <= CanIf_CanHoh2Hrh[canDriverId].CanIfCanHohLen)
        {
            if (CanIf_CanHoh2Hrh[canDriverId].CanIfCanHoh2HrhRef[hrhId] != CANIF_UNUSED_UINT16)
            {
                canIfHrhId = (Can_HwHandleType)(CanIf_CanHoh2Hrh[canDriverId].CanIfCanHoh2HrhRef[hrhId]);
                findCanIfHrh = TRUE;
            }
        }
    }
#endif
    if (TRUE == findCanIfHrh)
    {
#if (STD_ON == CANIF_HRH_RANGE_SUPPORT)
        const CanIfHrhCfgType* hrhPtr = &CANIF_HRH(canIfHrhId);
        hrhCanIdRangeNum = hrhPtr->CanIfHrhCanIdRangeNum;
        /* if the hrh defined as Basic Can and sofware filter enabled */
        if ((CANIF_BASIC_CAN == hrhPtr->CanIfHrhIdSymRef->CanIfHrhType) && (0u < hrhCanIdRangeNum))
        {
            /* do HRH software filter*/
            for (cnt = 0u; (cnt < hrhCanIdRangeNum) && (FALSE == hrhFilterIsOk); cnt++)
            {
                if (((canId & CANIF_EXTENDED_CANID_MAX) >= hrhPtr->CanIfHrhCanIdRange[cnt].CanIfHrhRangeRxPduLowerCanId)
                    && ((canId & CANIF_EXTENDED_CANID_MAX)
                        <= hrhPtr->CanIfHrhCanIdRange[cnt].CanIfHrhRangeRxPduUpperCanId))
                {
                    hrhFilterIsOk = TRUE;
                    /* pass the Mask filter */
                    result = CanIf_RxPduHrhSearch(canIfHrhId, canId, pduIdIndex);
                }
            }
        }
        else /* FullCan */
#endif       /* STD_ON == CANIF_HRH_RANGE_SUPPORT */
        {
            /* find the rxpduId due to the hrhId */
            result = CanIf_RxPduHrhSearch(canIfHrhId, canId, pduIdIndex);
        }
    }
    else
    {
#if (STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
        (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_RXINDICATION_ID, CANIF_E_PARAM_HOH);
#endif
    }
    return result;
}
#if (CANIF_TXBUFFER_NUMBER > 0u)
/*************************************************************************/
/*
 * Brief               free the txbuffer
 * ServiceId           None
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      controller: the id of Can Controller
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        CANIF_TXBUFFER_NUMBER > 0u
 * CallByAPI           CanIf_FreeBufInStopped
 */
/*************************************************************************/
static FUNC(void, CANIF_CODE) CanIf_FreeControllerTxBuffer(uint8 Controller)
{
    PduIdType txBufferIndex;
    PduIdType txPduId;
    Can_HwHandleType hthId;
    uint8 controllerId;
    uint8 index;
    for (txBufferIndex = 0u; txBufferIndex < CANIF_TXBUFFER_NUMBER; txBufferIndex++)
    {
        for (index = 0u; index < CANIF_TXBUFFER_SIZE(txBufferIndex); index++)
        {
            /* polling txbuffer, find the one already be used */
            if (TRUE == CanIf_TxBuffer[txBufferIndex].CanIf_TxPduBufferRef[index].used)
            {
                txPduId = CanIf_TxBuffer[txBufferIndex].CanIf_TxPduBufferRef[index].TxPduIndex;
                hthId = CANIF_TXPDU(txPduId).CanIfTxPduHthId;
                controllerId = CANIF_HTH(hthId).CanIfHthCanCtrlId;
                /* check this txbuffer whether used for this controller */
                if (Controller == controllerId)
                {
                    /* set the used flag False so that this buffer can save new pdu */
                    CanIf_TxBuffer[txBufferIndex].CanIf_TxPduBufferRef[index].used = FALSE;
                }
            }
        }
    }
    return;
}
/*************************************************************************/
/*
 * Brief               CanIf call can_write which return CAN_BSUY,then set the write requece and data to tx buffer
 * ServiceId           None
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      pduPtr: CAN L-PDU to be transmitted
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK:Busy Handle,pdu saved successful
 *                     E_NOT_OK:Busy Handle,pdu saved failure
 * PreCondition        CANIF_TXBUFFER_NUMBER > 0u
 * CallByAPI           CanIf_Transmit
 */
/*************************************************************************/
static FUNC(Std_ReturnType, CANIF_CODE) CanIf_TxBusyHandle(P2CONST(Can_PduType, AUTOMATIC, CANIF_APPL_DATA) pduPtr)
{
    PduIdType txBufIndex;
    Std_ReturnType result = E_NOT_OK;
    uint8 index;
    uint8 idleBufferIndex = CANIF_UNUSED_UINT8;
    uint8 txBufferSize;
    const CanIf_TxPduConfigType* txPduConfigPtr = &CANIF_TXPDU(pduPtr->swPduHandle);
    CanIf_TxPduBufferType* txPduBufferPtr;
    txBufIndex = txPduConfigPtr->TxBufferIdndex;
    /*the pdu support Txbuffer*/
    if (txBufIndex < CANIF_TXBUFFER_NUMBER)
    {
        txBufferSize = CANIF_TXBUFFER_SIZE(txBufIndex);
        txPduBufferPtr = CanIf_TxBuffer[txBufIndex].CanIf_TxPduBufferRef;
        for (index = 0u; (index < txBufferSize) && (E_NOT_OK == result); index++)
        {
            if (txPduBufferPtr[index].TxPduIndex == pduPtr->swPduHandle)
            {
                txPduBufferPtr[index].canId = pduPtr->id;
                txPduBufferPtr[index].used = TRUE;
#if (STD_ON == CANIF_TRIGGER_TRANSMIT_SUPPORT)
                if (TRUE == txPduConfigPtr->CanIfTxPduTriggerTransmit)
                {
                    txPduBufferPtr[index].length = 0u;
                }
                else
#endif /*STD_ON == CANIF_TRIGGER_TRANSMIT_SUPPORT*/
                {
                    txPduBufferPtr[index].length = pduPtr->length;
                    CanIf_Memcpy(txPduBufferPtr[index].data, pduPtr->sdu, (PduLengthType)pduPtr->length);
                }
                result = E_OK;
            }
            if ((CANIF_UNUSED_UINT8 == idleBufferIndex) && (FALSE == txPduBufferPtr[index].used))
            {
                idleBufferIndex = index;
            }
        }
        if ((E_NOT_OK == result) && (CANIF_UNUSED_UINT8 != idleBufferIndex))
        {
            txPduBufferPtr[idleBufferIndex].canId = pduPtr->id;
            txPduBufferPtr[idleBufferIndex].used = TRUE;
            txPduBufferPtr[idleBufferIndex].TxPduIndex = pduPtr->swPduHandle;
#if (STD_ON == CANIF_TRIGGER_TRANSMIT_SUPPORT)
            if (TRUE == txPduConfigPtr->CanIfTxPduTriggerTransmit)
            {
                txPduBufferPtr[idleBufferIndex].length = 0u;
            }
            else
#endif /*STD_ON == CANIF_TRIGGER_TRANSMIT_SUPPORT*/
            {
                txPduBufferPtr[idleBufferIndex].length = pduPtr->length;
                CanIf_Memcpy(txPduBufferPtr[idleBufferIndex].data, pduPtr->sdu, (PduLengthType)pduPtr->length);
            }
            result = E_OK;
        }
    }
    return result;
}
#endif /*(CANIF_TXBUFFER_NUMBER > 0u)*/
#if (0u < CANIF_RXBUFFER_NUMBER)
/*************************************************************************/
/*
 * Brief               init the Receive Buffer
 * ServiceId           None
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      Controller:the id of can controller
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        CANIF_PUBLIC_READ_RX_PDU_DATA_API is TRUE
 * CallByAPI           CanIf_FreeBufInStopped
 */
/*************************************************************************/
static FUNC(void, CANIF_CODE) CanIf_InitRxBuffer(uint8 Controller)
{
    PduIdType rxPduIndex;
    Can_HwHandleType hrhId;
    CanIf_RxPduBufferType* rxPduBuffer;
    const CanIf_RxPduConfigType* rxPduConfigPtr;
    for (rxPduIndex = 0u; rxPduIndex < CANIF_RXPDU_NUMBER; rxPduIndex++)
    {
        rxPduConfigPtr = &CANIF_RXPDU(rxPduIndex);
        rxPduBuffer = rxPduConfigPtr->CanIfRxBufferRef;
        if (NULL_PTR != rxPduBuffer)
        {
            hrhId = rxPduConfigPtr->CanIfRxPduHrhId;
            if (Controller == CANIF_HRH(hrhId).CanIfHrhCanCtrlId)
            {
                /* init the RxBuf, set length to 0. */
                rxPduBuffer->length = 0u;
            }
        }
    }
    return;
}
#endif /*(0u < CANIF_RXBUFFER_NUMBER) */
#if (CANIF_DYNAMIC_TXPDU_NUMBER > 0u)
/*************************************************************************/
/*
 * Brief               init the Dynamic Transmit CanId
 * ServiceId           None
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      Controller: the id of can controller
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              void
 * PreCondition        CANIF_PUBLIC_SET_DYNAMIC_TX_ID_API is STD_ON
 * CallByAPI           CanIf_FreeBufInStopped
 */
/*************************************************************************/
static FUNC(void, CANIF_CODE) CanIf_InitDynamicTxPduCanIds(uint8 Controller)
{
    PduIdType txPduIndex;
    Can_HwHandleType hthId;
    uint8 controllerId;
    const CanIf_TxPduConfigType* txPduConfigPtr;
    for (txPduIndex = 0u; txPduIndex < CANIF_TXPDU_NUMBER; txPduIndex++)
    {
        txPduConfigPtr = &CANIF_TXPDU(txPduIndex);
        hthId = txPduConfigPtr->CanIfTxPduHthId;
        controllerId = CANIF_HTH(hthId).CanIfHthCanCtrlId;
        if (Controller == controllerId)
        {
            if (CANID_DYNAMIC == txPduConfigPtr->CanIfTxPduType)
            {
                /* init the DynamicTxPduCanId with the configured canId */
                CanIf_TxPduDynamicCanIds[txPduConfigPtr->CanIfDynamicCanIdIndex] = txPduConfigPtr->CanIfTxPduCanId;
            }
        }
    }
    return;
}
#endif /*CANIF_DYNAMIC_TXPDU_NUMBER > 0u*/

#if (                                                            \
    (0u < CANIF_RXBUFFER_NUMBER) || (0u < CANIF_TXBUFFER_NUMBER) \
    || ((STD_OFF == CANIF_RXINDICATION_AUTOSAR_PARAMETER) && (STD_ON == CANIF_META_DATA_SUPPORT)))
/*************************************************************************/
/*
 * Brief               MISRA C 2004 forbid to use memcpy() lib,only used  to
 *                     copy data buffer of indirect address
 * ServiceId           None
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      source:pointer to the source
 *                     length:copy how much length
 * Param-Name[out]     None
 * Param-Name[in/out]  dest:pointer to the dest
 * Return              void
 * PreCondition        None
 * CallByAPI           CanIf_RxIndicationHandle,CanIf_ReadRxPduData,CanIf_TxBusyHandle
 */
/*************************************************************************/
static FUNC(void, CANIF_CODE) CanIf_Memcpy(
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, CANIF_APPL_DATA) dest,
    /* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
    P2CONST(uint8, AUTOMATIC, CANIF_APPL_DATA) source,
    PduLengthType length)
{
    PduLengthType len = length;
    while (len > 0u)
    {
        /* MISRA-C:2004 Rule 17.4
         * Msg(4:0489) The integer value 1 is being added or subtracted from a pointer.
         */
        if ((dest != NULL_PTR) && (source != NULL_PTR))
        {
            *dest = *source;
            dest++;
            source++;
        }
        else
        {
            break;
        }
        len--;
    }
    return;
}
#endif /*(0u < CANIF_RXBUFFER_NUMBER) || (0u < CANIF_TXBUFFER_NUMBER) || ((STD_OFF == \
          CANIF_RXINDICATION_AUTOSAR_PARAMETER) && (STD_ON == CANIF_META_DATA_SUPPORT))*/
/*************************************************************************/
/*
 * Brief               Can pdu pack for transmit
 * ServiceId           None
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      CanTxPduId: the id of Tx Pdu
 *                     PduInfoPtr: Pointer to a structure with CAN L-SDU related data:
 *                     DLC and pointer to CAN L-SDU buffer including the MetaData of dynamic L-PDUs.
 * Param-Name[out]     None
 * Param-Name[in/out]  canPdu: Pointer to SDU user memory, DLC and Identifier.
 * Return              void
 * PreCondition        None
 * CallByAPI           CanIf_Transmit
 */
/*************************************************************************/
static FUNC(void, CANIF_CODE) CanIf_PduPack(
    PduIdType CanTxPduId,
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(Can_PduType, AUTOMATIC, AUTOMATIC) canPdu)
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
{
    CanIf_TxPduCanIdMode canIdMode;
    const CanIf_TxPduConfigType* txPduConfigPtr = &CANIF_TXPDU(CanTxPduId);
#if (CANIF_DYNAMIC_TXPDU_NUMBER > 0u)
    Can_IdType baseId;
#if (STD_ON == CANIF_META_DATA_SUPPORT)
    Can_IdType metaData;
    Can_IdType canIdMask;
#endif /*STD_ON == CANIF_META_DATA_SUPPORT*/
#endif /*CANIF_DYNAMIC_TXPDU_NUMBER > 0u*/
    canIdMode = txPduConfigPtr->CanIfTxPduCanIdType;
#if (CANIF_DYNAMIC_TXPDU_NUMBER > 0u)
    if (CANID_DYNAMIC == txPduConfigPtr->CanIfTxPduType)
    {
        baseId = CanIf_TxPduDynamicCanIds[txPduConfigPtr->CanIfDynamicCanIdIndex];
#if (STD_ON == CANIF_META_DATA_SUPPORT)
        if (TRUE == txPduConfigPtr->CanIfTxPduRef->TxMetaDataEnable)
        {
            canIdMask = txPduConfigPtr->CanIfTxPduCanIdMask;
            CANIF_METADATATOCANID(metaData, PduInfoPtr->MetaDataPtr); /* PRQA S 3432 */ /* MISRA Rule 20.7 */
            canPdu->id = (baseId & canIdMask) | (metaData & (~canIdMask));
        }
        else
        {
            canPdu->id = baseId;
        }
#else  /*STD_ON == CANIF_META_DATA_SUPPORT*/
        canPdu->id = baseId;
#endif /*STD_ON == CANIF_META_DATA_SUPPORT*/
    }
    else
    {
        canPdu->id = txPduConfigPtr->CanIfTxPduCanId;
    }
#else  /*CANIF_DYNAMIC_TXPDU_NUMBER > 0u*/
    canPdu->id = txPduConfigPtr->CanIfTxPduCanId;
#endif /*CANIF_DYNAMIC_TXPDU_NUMBER > 0u*/
    /*set the 2 bits of highest CanId base the CanIf_TxPduCanIdMode*/
    switch (canIdMode)
    {
#if (STD_ON == CANIF_TX_EXTENDED_CAN_SUPPORT)
    case CANIF_TX_EXTENDED_CAN:
        canPdu->id |= (Can_IdType)0x80000000u;
        break;
#endif /* STD_ON == CANIF_TX_EXTENDED_CAN_SUPPORT */
#if (STD_ON == CANIF_TX_EXTENDED_FD_CAN_SUPPORT)
    case CANIF_TX_EXTENDED_FD_CAN:
        canPdu->id |= (Can_IdType)0xc0000000u;
        break;
#endif /* STD_ON == CANIF_TX_EXTENDED_FD_CAN_SUPPORT */
#if (STD_ON == CANIF_TX_STANDARD_FD_CAN_SUPPORT)
    case CANIF_TX_STANDARD_FD_CAN:
        canPdu->id |= (Can_IdType)0x40000000u;
        break;
#endif       /* STD_ON == CANIF_TX_STANDARD_FD_CAN_SUPPORT */
    default: /*CANIF_TX_STANDARD_CAN*/
        break;
    }
    /* get PDU length */
    canPdu->length = (uint8)PduInfoPtr->SduLength;
    if ((canPdu->length) > txPduConfigPtr->CanIfTxPduRef->CanIfTxPduDlc)
    {
        canPdu->length = txPduConfigPtr->CanIfTxPduRef->CanIfTxPduDlc;
    }
    /* get PDU handle */
    canPdu->swPduHandle = CanTxPduId;
    /* get SDU */
    canPdu->sdu = PduInfoPtr->SduDataPtr;
    return;
}
/*************************************************************************/
/*
 * Brief               direct switch to Stopped Mode,and do buffer clear.
 * ServiceId           None
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      Controller: the id of can controller
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           CanIf_SetControllSleep,CanIf_SetControllStopped
 */
/*************************************************************************/
static FUNC(void, CANIF_CODE) CanIf_FreeBufInStopped(uint8 Controller)
{
/* free tx buffer if enabled */
#if (CANIF_TXBUFFER_NUMBER > 0u)
    CanIf_FreeControllerTxBuffer(Controller);
#endif
/* (re-)init the rx Buffer */
#if (0u < CANIF_RXBUFFER_NUMBER)
    /* Init CanIf RxBuffer */
    CanIf_InitRxBuffer(Controller);
#endif
#if ((CANIF_TXNOTIFYSTATUS_BUFFER > 0u) || (CANIF_RXNOTIFYSTATUS_BUFFER > 0u))
    /* set the rx and tx Notify status buffer Of this controller */
    CanIf_FreeRxTxNotifyStatus(Controller);
#endif
#if (STD_ON == CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT)
    CanIf_TxConfirmationState[Controller] = CANIF_NO_NOTIFICATION;
#endif
#if (CANIF_DYNAMIC_TXPDU_NUMBER > 0u)
    /* init dynamic CAN ID array */
    CanIf_InitDynamicTxPduCanIds(Controller);
#endif
    return;
}
/*************************************************************************/
/*
 * Brief               init all buffer
 * ServiceId           None
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           CanIf_Init
 */
/*************************************************************************/
static FUNC(void, CANIF_CODE) CanIf_InitAllBuffer(VAR(void, AUTOMATIC))
{
#if (0u < CANIF_TXBUFFER_NUMBER)
    PduIdType txBufferIndex;
    uint8 index;
#endif
#if (0u < CANIF_RXBUFFER_NUMBER)
    PduIdType rxBufferIndex;
#endif
#if (0u < CANIF_TXNOTIFYSTATUS_BUFFER)
    PduIdType txNotifyStatusIndex;
#endif
#if (0u < CANIF_RXNOTIFYSTATUS_BUFFER)
    PduIdType rxNotifyStatusIndex;
#endif
#if (0u < CANIF_DYNAMIC_TXPDU_NUMBER)
    PduIdType txPduIndex;
    const CanIf_TxPduConfigType* txPduConfigPtr;
#endif
/* free tx buffer if enabled */
#if (0u < CANIF_TXBUFFER_NUMBER)
    for (txBufferIndex = 0u; txBufferIndex < CANIF_TXBUFFER_NUMBER; txBufferIndex++)
    {
        /* polling txbuffer, find the one already be used */
        for (index = 0u; index < CANIF_TXBUFFER_SIZE(txBufferIndex); index++)
        {
            CanIf_TxBuffer[txBufferIndex].CanIf_TxPduBufferRef[index].used = FALSE;
        }
    }
#endif
/* (re-)init the rx Buffer */
#if (0u < CANIF_RXBUFFER_NUMBER)
    for (rxBufferIndex = 0u; rxBufferIndex < CANIF_RXBUFFER_NUMBER; rxBufferIndex++)
    {
        /* init the RxBuf, set length to 0. */
        CanIf_RxBuffer[rxBufferIndex].length = 0u;
    }
#endif
/* re-init the txNotifStatus Of this controller */
#if (0u < CANIF_TXNOTIFYSTATUS_BUFFER)
    for (txNotifyStatusIndex = 0u; txNotifyStatusIndex < CANIF_TXNOTIFYSTATUS_BUFFER; txNotifyStatusIndex++)
    {
        CanIf_TxNotifStatus[txNotifyStatusIndex] = CANIF_NO_NOTIFICATION;
    }
#endif
/* re-init the rxNotifStatus Of this controller */
#if (0u < CANIF_RXNOTIFYSTATUS_BUFFER)
    for (rxNotifyStatusIndex = 0u; rxNotifyStatusIndex < CANIF_RXNOTIFYSTATUS_BUFFER; rxNotifyStatusIndex++)
    {
        CanIf_RxNotifStatus[rxNotifyStatusIndex] = CANIF_NO_NOTIFICATION;
    }
#endif
/* init the DynamicTxPduCanId with the configured canId */
#if (0u < CANIF_DYNAMIC_TXPDU_NUMBER)
    for (txPduIndex = 0u; txPduIndex < CANIF_TXPDU_NUMBER; txPduIndex++)
    {
        txPduConfigPtr = &CANIF_TXPDU(txPduIndex);
        if (CANID_DYNAMIC == txPduConfigPtr->CanIfTxPduType)
        {
            CanIf_TxPduDynamicCanIds[txPduConfigPtr->CanIfDynamicCanIdIndex] = txPduConfigPtr->CanIfTxPduCanId;
        }
    }
#endif
    return;
}
/*************************************************************************/
/*
 * Brief               Search the index of RxPdu Config due to the Hrh and CanId
 * ServiceId           None
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      hrhIndex: ID of the corresponding hardware object
 *                     CanId: Standard/Extended CAN ID of CAN L-PDU that
 *                     has been successfully received
 * Param-Name[out]     rxPduIndex: the rx pdu that receive the can message
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 * PreCondition        None
 * CallByAPI           CanIf_CanIdRangCheck
 *
 */
/*************************************************************************/
static FUNC(Std_ReturnType, CANIF_CODE)
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    CanIf_RxPduHrhSearch(Can_HwHandleType hrhIndex, Can_IdType CanId, P2VAR(PduIdType, AUTOMATIC, AUTOMATIC) rxPduIndex)
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
{
    Std_ReturnType result = E_NOT_OK;
#if (CANIF_SOFTWARE_FILTER_TYPE == CANIF_SOFTWARE_FILTER_LINEAR)
    PduIdType cnt, pduIdIndex, hrhRefPduNum;
    const CanIfHrhCfgType* hrhConfigPtr = &CANIF_HRH(hrhIndex);
    hrhRefPduNum = hrhConfigPtr->CanIfRxPduRefNum;
    for (cnt = 0u; (cnt < hrhRefPduNum) && (E_NOT_OK == result); cnt++)
    {
        pduIdIndex = hrhConfigPtr->CanIfRxPduIdRef[cnt];
        result = CanIf_GetPduHrh(pduIdIndex, CanId, rxPduIndex);
    }
#endif
    return result;
}

/*************************************************************************/
/*
 * Brief               Get the index of RxPdu Config due to the pduIdIndex and CanId
 * ServiceId           None
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      pduIdIndex: ID of the pdu
 *                     CanId: Standard/Extended CAN ID of CAN L-PDU that
 *                     has been successfully received
 * Param-Name[out]     rxPduIndex: the rx pdu that receive the can message
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 * PreCondition        None
 * CallByAPI           CanIf_RxPduHrhSearch
 *
 */
/*************************************************************************/
static FUNC(Std_ReturnType, CANIF_CODE)
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    CanIf_GetPduHrh(PduIdType pduIdIndex, Can_IdType CanId, P2VAR(PduIdType, AUTOMATIC, AUTOMATIC) rxPduIndex)
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
{
    Std_ReturnType result = E_NOT_OK;
    Can_IdType mask;
    const CanIf_RxPduConfigType* rxPduConfigPtr = &CANIF_RXPDU(pduIdIndex);
    mask = rxPduConfigPtr->CanIfRxPduCanIdMask;
    if ((((rxPduConfigPtr->CanIfRxPduCanId) & mask) == (CanId & mask))
#if (STD_ON == CANIF_RXPDU_CANID_RANGE_SUPPORT)
        && ((CanId & CANIF_EXTENDED_CANID_MAX) >= rxPduConfigPtr->CanIfRxPduLowerCanId)
        && ((CanId & CANIF_EXTENDED_CANID_MAX) <= rxPduConfigPtr->CanIfRxPduUpperCanId)
#endif /* STD_ON == CANIF_RXPDU_CANID_RANGE_SUPPORT */
    )
    {
        switch (rxPduConfigPtr->CanIfRxPduCanIdType)
        {
#if (STD_ON == CANIF_RX_EXTENDED_CAN_SUPPORT)
        case CANIF_RX_EXTENDED_CAN:
            if (CanId >= 0x80000000u)
            {
                result = E_OK;
                *rxPduIndex = pduIdIndex;
            }
            break;
#endif /* STD_ON == CANIF_RX_EXTENDED_CAN_SUPPORT */
#if (STD_ON == CANIF_RX_EXTENDED_FD_CAN_SUPPORT)
        case CANIF_RX_EXTENDED_FD_CAN:
            if (CanId >= 0xc0000000u)
            {
                result = E_OK;
                *rxPduIndex = pduIdIndex;
            }
            break;
#endif /* STD_ON == CANIF_RX_EXTENDED_FD_CAN_SUPPORT */
#if (STD_ON == CANIF_RX_EXTENDED_NO_FD_CAN_SUPPORT)
        case CANIF_RX_EXTENDED_NO_FD_CAN:
            if ((CanId >= 0x80000000u) && (CanId < 0xc0000000u))
            {
                result = E_OK;
                *rxPduIndex = pduIdIndex;
            }
            break;
#endif /* STD_ON == CANIF_RX_EXTENDED_NO_FD_CAN_SUPPORT */
#if (STD_ON == CANIF_RX_STANDARD_CAN_SUPPORT)
        case CANIF_RX_STANDARD_CAN:
            if (CanId < 0x80000000u)
            {
                result = E_OK;
                *rxPduIndex = pduIdIndex;
            }
            break;
#endif /* STD_ON == CANIF_RX_STANDARD_CAN_SUPPORT */
#if (STD_ON == CANIF_RX_STANDARD_FD_CAN_SUPPORT)
        case CANIF_RX_STANDARD_FD_CAN:
            if ((CanId < 0x80000000u) && (CanId >= 0x40000000u))
            {
                result = E_OK;
                *rxPduIndex = pduIdIndex;
            }
            break;
#endif /* STD_ON == CANIF_RX_STANDARD_FD_CAN_SUPPORT */
#if (STD_ON == CANIF_RX_STANDARD_NO_FD_CAN_SUPPORT)
        case CANIF_RX_STANDARD_NO_FD_CAN:
            if (CanId < 0x40000000u)
            {
                result = E_OK;
                *rxPduIndex = pduIdIndex;
            }
            break;
#endif /* STD_ON == CANIF_RX_STANDARD_NO_FD_CAN_SUPPORT */
        default:
            /*do nothing*/
            break;
        }
    }
    return result;
}

/*************************************************************************/
/*
 * Brief               do RxIndication Handle with the correct rxPuIndex
 *                     which get by hrh and CanId through CanIf_CanIdRangCheck
 * ServiceId           None
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      pduIdIndex: Rx Pdu id
 *                     canId: 11/29 bit CanId
 *                     PduInfoPtr: Pointer to a structure with CAN L-SDU related data:
 *                     DLC and pointer to CAN L-SDU buffer including the MetaData of dynamic L-PDUs.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           CanIf_RxIndication
 */
/*************************************************************************/
static FUNC(void, CANIF_CODE) CanIf_RxIndicationHandle(
    PduIdType pduIdIndex,
#if (STD_ON == CANIF_META_DATA_SUPPORT)
    Can_IdType canId,
#endif
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr)
{
#if ((STD_OFF == CANIF_RXINDICATION_AUTOSAR_PARAMETER) && (STD_ON == CANIF_META_DATA_SUPPORT))
    boolean metaDataEnable;
    PduInfoType pduInfo;
    Can_IdType metaData;
#endif
    const CanIf_RxPduConfigType* rxPduConfigPtr = &CANIF_RXPDU(pduIdIndex);
#if (0u < CANIF_RXBUFFER_NUMBER)
    CanIf_RxPduBufferType* rxPduBuffer;
#endif
/* rx status notify enabled */
#if (CANIF_RXNOTIFYSTATUS_BUFFER > 0u)
    if (TRUE == rxPduConfigPtr->CanIfRxPduReadNotifyStatus)
    {
        /* set rx status to CANIF_TX_RX_NOTIFICATION */
        CanIf_RxNotifStatus[rxPduConfigPtr->CanIfRxNotifyIndex] = CANIF_TX_RX_NOTIFICATION;
    }
#endif /*CANIF_RXNOTIFYSTATUS_BUFFER > 0*/
#if ((STD_ON == CANIF_RXINDICATION_AUTOSAR_PARAMETER) || (STD_OFF == CANIF_META_DATA_SUPPORT))
#if (0u < CANIF_RXBUFFER_NUMBER)
    rxPduBuffer = rxPduConfigPtr->CanIfRxBufferRef;
    if (NULL_PTR != rxPduBuffer)
    {
        rxPduBuffer->length = (uint8)PduInfoPtr->SduLength;
        /* save sdu */
        CanIf_Memcpy(rxPduBuffer->data, PduInfoPtr->SduDataPtr, PduInfoPtr->SduLength);
#if (STD_ON == CANIF_META_DATA_SUPPORT)
        if (NULL_PTR != PduInfoPtr->MetaDataPtr)
        {
            CANIF_METADATATOCANID(rxPduBuffer->metaData, PduInfoPtr->MetaDataPtr);
        }
#endif /*(STD_ON == CANIF_META_DATA_SUPPORT)*/
    }
#endif /*(0u < CANIF_RXBUFFER_NUMBER)*/
    /* inform upper layer */
    if (NULL_PTR != rxPduConfigPtr->CanIfRxPduUserRxIndicationName)
    {
        rxPduConfigPtr->CanIfRxPduUserRxIndicationName(rxPduConfigPtr->CanIfRxPduRef->CanIfUpPduId, PduInfoPtr);
    }
#else /*(STD_ON == CANIF_RXINDICATION_AUTOSAR_PARAMETER) || (STD_OFF == CANIF_META_DATA_SUPPORT)*/
    metaDataEnable = rxPduConfigPtr->CanIfRxPduRef->RxMetaDataEnable;
    if (TRUE == metaDataEnable)
    {
        metaData = ((Can_IdType)CANIF_EXTENDED_CANID_MAX & canId);
        pduInfo.MetaDataPtr = (uint8*)(&metaData);
    }
    else
    {
        pduInfo.MetaDataPtr = NULL_PTR;
    }
    pduInfo.SduDataPtr = PduInfoPtr->SduDataPtr;
    pduInfo.SduLength = PduInfoPtr->SduLength;
#if (0u < CANIF_RXBUFFER_NUMBER)
    rxPduBuffer = rxPduConfigPtr->CanIfRxBufferRef;
    if (NULL_PTR != rxPduBuffer)
    {
        rxPduBuffer->length = (uint8)pduInfo.SduLength;
        /* save sdu */
        CanIf_Memcpy(rxPduBuffer->data, pduInfo.SduDataPtr, pduInfo.SduLength);
        if (TRUE == metaDataEnable)
        {
            rxPduBuffer->metaData = metaData;
        }
    }
#endif /*(0u < CANIF_RXBUFFER_NUMBER)*/
    /* inform upper layer */
    if (NULL_PTR != rxPduConfigPtr->CanIfRxPduUserRxIndicationName)
    {
        rxPduConfigPtr->CanIfRxPduUserRxIndicationName(rxPduConfigPtr->CanIfRxPduRef->CanIfUpPduId, &pduInfo);
    }
#endif /*(STD_ON == CANIF_RXINDICATION_AUTOSAR_PARAMETER) || (STD_OFF == CANIF_META_DATA_SUPPORT)*/
    return;
}
#if ((CANIF_TXNOTIFYSTATUS_BUFFER > 0u) || (CANIF_RXNOTIFYSTATUS_BUFFER > 0u))
/*************************************************************************/
/*
 * Brief               Re-init rxNotifyStatus and txNotifyStatus
 * ServiceId           None
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      Controller: the id of can controller
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        CANIF_PUBLIC_READ_TX_PDU_NOTIFY_STATUS_API is TRUE or
 *                     CANIF_PUBLIC_READ_RX_PDU_NOTIFY_STATUS_API is TRUE
 * CallByAPI           CanIf_FreeBufInStopped
 */
/*************************************************************************/
static FUNC(void, CANIF_CODE) CanIf_FreeRxTxNotifyStatus(uint8 Controller)
{
#if (CANIF_TXNOTIFYSTATUS_BUFFER > 0u)
    PduIdType txPduId;
    Can_HwHandleType hthId;
    PduIdType txNotifyIndex;
    const CanIf_TxPduConfigType* txPduConfigPtr;
#endif
#if (CANIF_RXNOTIFYSTATUS_BUFFER > 0u)
    PduIdType rxPduId;
    Can_HwHandleType hrhId;
    PduIdType rxNotifyIndex;
    const CanIf_RxPduConfigType* rxPduConfigPtr;
#endif
    uint8 controllerId;
#if (CANIF_TXNOTIFYSTATUS_BUFFER > 0u)
    /* re-init the txNotifStatus Of this controller */
    for (txPduId = 0u; txPduId < CANIF_TXPDU_NUMBER; txPduId++)
    {
        txPduConfigPtr = &CANIF_TXPDU(txPduId);
        hthId = txPduConfigPtr->CanIfTxPduHthId;
        controllerId = CANIF_HTH(hthId).CanIfHthCanCtrlId;
        if ((TRUE == txPduConfigPtr->CanIfTxPduReadNotifyStatus) && (Controller == controllerId))
        {
            txNotifyIndex = txPduConfigPtr->CanIfTxNotifyIndex;
            CanIf_TxNotifStatus[txNotifyIndex] = CANIF_NO_NOTIFICATION;
        }
    }
#endif
#if (CANIF_RXNOTIFYSTATUS_BUFFER > 0u)
    /* re-init the rxNotifStatus Of this controller */
    for (rxPduId = 0u; rxPduId < CANIF_RXPDU_NUMBER; rxPduId++)
    {
        rxPduConfigPtr = &CANIF_RXPDU(rxPduId);
        hrhId = rxPduConfigPtr->CanIfRxPduHrhId;
        controllerId = CANIF_HRH(hrhId).CanIfHrhCanCtrlId;
        if ((TRUE == rxPduConfigPtr->CanIfRxPduReadNotifyStatus) && (Controller == controllerId))
        {
            rxNotifyIndex = rxPduConfigPtr->CanIfRxNotifyIndex;
            CanIf_RxNotifStatus[rxNotifyIndex] = CANIF_NO_NOTIFICATION;
        }
    }
#endif
    return;
}
#endif /*((CANIF_TXNOTIFYSTATUS_BUFFER > 0u) || (CANIF_RXNOTIFYSTATUS_BUFFER > 0u))*/

static FUNC(Std_ReturnType, CANIF_CODE)
    CanIf_TransmitHandle(PduIdType CanIfTxSduId, P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr)
{
    Std_ReturnType result = E_NOT_OK;
    Can_ReturnType retVal = CAN_NOT_OK;
    Can_HwHandleType hthConfigIndex;
    uint8 canControllerId;
    uint8 canDriver;
    const CanIf_TxPduConfigType* txPduConfigPtr = &CANIF_TXPDU(CanIfTxSduId);
    const CanIfHthCfgType* hthPtr;
    /* Get the hth config Index */
    hthConfigIndex = txPduConfigPtr->CanIfTxPduHthId;
    /* Get the hth config */
    hthPtr = &CANIF_HTH(hthConfigIndex);
    /* get controller ID */
    canControllerId = hthPtr->CanIfHthCanCtrlId;
    if (CANIF_CS_STARTED == CanIf_ControllerMode[canControllerId])
    {
        if (CANIF_ONLINE == CanIf_PduMode[canControllerId])
        {
            Can_PduType canPdu;
            const CanIf_ControllerCfgType* controllerPtr = &CANIF_CONTROLLER(canControllerId);
            SchM_Enter_CanIf();
            CanIf_PduPack(CanIfTxSduId, PduInfoPtr, &canPdu);
            /* call lower layer CAN driver API,and get return value */
            canDriver = controllerPtr->CanDriverId;
#if (STD_ON == CANIF_PUBLIC_PN_SUPPORT)
            if ((TRUE == controllerPtr->CanIfPnFilter) && (TRUE == CanIf_PnTxFilter[canControllerId]))
            {
                if (TRUE == txPduConfigPtr->CanIfTxPduPnFilterPdu)
                {
                    retVal = Can_DriverApi[canDriver].CanWriteApi(hthPtr->CanIfHthIdSymRef->CanObjectId, &canPdu);
                }
            }
            else
#endif
            {
                retVal = Can_DriverApi[canDriver].CanWriteApi(hthPtr->CanIfHthIdSymRef->CanObjectId, &canPdu);
            }
            if (CAN_OK == retVal)
            {
                result = E_OK;
            }
/* if CAN_BUSY and buffer enabled */
#if (CANIF_TXBUFFER_NUMBER > 0u)
            else if (CAN_BUSY == retVal)
            {
                result = CanIf_TxBusyHandle(&canPdu);
                if ((E_OK == result) && ((PduInfoPtr->SduLength) > (PduLengthType)(canPdu.length)))
                {
                    (void)Det_ReportRuntimeError(
                        CANIF_MODULE_ID,
                        CANIF_INSTANCE_ID,
                        CANIF_TRANSMIT_ID,
                        CANIF_E_DATA_LENGTH_MISMATCH);
                }
            }
#endif /*(CANIF_TXBUFFER_NUMBER > 0)*/
            else
            {
                result = E_NOT_OK;
            }
            SchM_Exit_CanIf();
        }
#if (STD_ON == CANIF_TX_OFFLINE_ACTIVE_SUPPORT)
        else if (CANIF_TX_OFFLINE_ACTIVE == CanIf_PduMode[canControllerId])
        {
/* check notify enable */
#if (CANIF_TXNOTIFYSTATUS_BUFFER > 0u)
            if (TRUE == txPduConfigPtr->CanIfTxPduReadNotifyStatus)
            {
                /* change status of the coressponding CanIf_TxNotifStatus */
                CanIf_TxNotifStatus[txPduConfigPtr->CanIfTxNotifyIndex] = CANIF_TX_RX_NOTIFICATION;
            }
#endif
#if (STD_ON == CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT)
            CanIf_TxConfirmationState[canControllerId] = CANIF_TX_RX_NOTIFICATION;
#endif
            if (NULL_PTR != txPduConfigPtr->CanIfTxPduUserTxConfirmationName)
            {
                /* call call-back function,feedback to upper layer */
                txPduConfigPtr->CanIfTxPduUserTxConfirmationName(txPduConfigPtr->CanIfTxPduRef->CanIfUpPduId);
            }
            result = E_OK;
        }
#endif /*STD_ON == CANIF_TX_OFFLINE_ACTIVE_SUPPORT*/
        else
        {
            (void)Det_ReportRuntimeError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_TRANSMIT_ID, CANIF_E_STOPPED);
        }
    }
    else /* Not CANIF_CS_STARTED mode */
    {
        (void)Det_ReportRuntimeError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_TRANSMIT_ID, CANIF_E_STOPPED);
    }
    return result;
}

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
