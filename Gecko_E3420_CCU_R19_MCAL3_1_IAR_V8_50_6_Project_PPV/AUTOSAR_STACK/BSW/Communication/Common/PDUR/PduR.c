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
**  FILENAME    : PduR.c                                                      **
**                                                                            **
**  Created on  :                                                             **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Implementation for PDUR                                     **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      REVISION   HISTORY                                    **
*******************************************************************************/
/* <VERSION>  <DATE>    <AUTHOR>      <REVISION LOG>
 *  V2.0.0    20200622  zhengfei.li   Initial version
 *                                    (Upgrade according to the R19_11 standards)
 *  V2.0.1    20211103  zhengfei.li   add "PDUR_" to some Macro Name
 *  V2.1.0    20211217  zhengfei.li   PB/PC configuration parameter split
 *  V2.1.1    20230901  tong.zhao     fix Bug CPT-6391
 *    In order to optimize the code execution efficiency, modify.
 ******************************************************************************/

/**
  \page ISOFT_MISRA_Exceptions  MISRA-C:2012 Compliance Exceptions
    ModeName:PduR<br>
  RuleSorce:puhua-rule.rcf 2.3.1

    \li PRQA S 3432 MISRA Rule 20.7 .<br>
    Reason:Function-like macros are used to allow more efficient code.

    \li PRQA S 1532 MISRA Rule 8.7 .<br>
    Reason:In order to make the module code structure clear, the functions are classified.

    \li PRQA S 2877 MISRA Rule 4.1 .<br>
    Reason:for loop condition is a macro definition, which varies in different projs.
 */

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "PduR_Internal.h"
#if (STD_OFF == PDUR_ZERO_COST_OPERATION)
#include "Det.h"
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
#define PDUR_C_AR_MAJOR_VERSION 4u
#define PDUR_C_AR_MINOR_VERSION 2u
#define PDUR_C_AR_PATCH_VERSION 2u
#define PDUR_C_SW_MAJOR_VERSION 2u
#define PDUR_C_SW_MINOR_VERSION 1u
#define PDUR_C_SW_PATCH_VERSION 1u
/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/
#if (PDUR_C_AR_MAJOR_VERSION != PDUR_H_AR_MAJOR_VERSION)
#error "PduR.c : Mismatch in Specification Major Version"
#endif
#if (PDUR_C_AR_MINOR_VERSION != PDUR_H_AR_MINOR_VERSION)
#error "PduR.c : Mismatch in Specification Major Version"
#endif
#if (PDUR_C_AR_PATCH_VERSION != PDUR_H_AR_PATCH_VERSION)
#error "PduR.c : Mismatch in Specification Major Version"
#endif
#if (PDUR_C_SW_MAJOR_VERSION != PDUR_H_SW_MAJOR_VERSION)
#error "PduR.c : Mismatch in Specification Major Version"
#endif
#if (PDUR_C_SW_MINOR_VERSION != PDUR_H_SW_MINOR_VERSION)
#error "PduR.c : Mismatch in Specification Major Version"
#endif
#if (PDUR_C_SW_PATCH_VERSION != PDUR_H_SW_PATCH_VERSION)
#error "PduR.c : Mismatch in Specification Major Version"
#endif
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
#pragma default_function_attributes = @".iram_func"
#if (STD_ON == PDUR_DEV_ERROR_DETECT)
#define PDUR_START_SEC_VAR_INIT_8
#include "PduR_MemMap.h"
static VAR(PduR_StateType, PDUR_VAR_POWER_ON_INIT) PduR_Status = PDUR_UNINIT;
#define PDUR_STOP_SEC_VAR_INIT_8
#include "PduR_MemMap.h"
#endif
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#define PDUR_START_SEC_CODE
#include "PduR_MemMap.h"

#if (STD_ON == PDUR_TRANSMIT_SUPPORT)
static FUNC(Std_ReturnType, PDUR_CODE)
    PduR_UpModeTransmit(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);
#endif /*STD_ON == PDUR_TRANSMIT_SUPPORT*/

#if (STD_ON == PDUR_CANCEL_TRANSMIT)
static FUNC(Std_ReturnType, PDUR_CODE) PduR_UpModeCancelTransmit(PduIdType id);
#endif /*STD_ON == PDUR_CANCEL_TRANSMIT*/

#if (STD_ON == PDUR_CHANGE_PARAMETER)
static FUNC(Std_ReturnType, PDUR_CODE)
    PduR_UpModeChangeParameter(PduIdType id, TPParameterType parameter, uint16 value);
#endif /*STD_ON == PDUR_CHANGE_PARAMETER*/

#if (STD_ON == PDUR_CANCEL_RECEIVE)
static FUNC(Std_ReturnType, PDUR_CODE) PduR_UpModeCancelReceive(PduIdType id);
#endif /*STD_ON == PDUR_CANCEL_RECEIVE*/

#if (STD_ON == PDUR_TP_STARTOFRECEPTION_TRANSMIT)
static FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LoTpStartOfReception(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    PduLengthType TpSduLength,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr);
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
#endif               /*STD_ON == PDUR_TP_STARTOFRECEPTION_TRANSMIT*/

#if (STD_ON == PDUR_TP_COPYRXDATA)
static FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LoTpCopyRxData(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr);
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
#endif               /*STD_ON == PDUR_TP_COPYRXDATA*/

#if (STD_ON == PDUR_TP_RXINDICATION)
static FUNC(void, PDUR_CODE) PduR_LoTpRxIndication(PduIdType id, Std_ReturnType result);
#endif /*STD_ON == PDUR_TP_RXINDICATION*/

#if (STD_ON == PDUR_TP_COPYTXDATA)
static FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LoTpCopyTxData(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2CONST(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr);
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
#endif               /*STD_ON == PDUR_TP_COPYTXDATA*/

#if (STD_ON == PDUR_TP_TXCONFIRMATION)
static FUNC(void, PDUR_CODE) PduR_LoTpTxConfirmation(PduIdType id, Std_ReturnType result);
#endif /*STD_ON == PDUR_TP_TXCONFIRMATION*/

/*Rx If pdu gateway to other If Pdus*/
#if (STD_ON == PDUR_RX_INDICATION)
static FUNC(void, PDUR_CODE)
    PduR_GateWayIfPdu(uint8 DestModule, PduIdType DestPduId, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) InfoPtr);
#endif /*STD_ON == PDUR_RX_INDICATION*/

/*Called by PduR_IfTriggerTransmit.
 *IfTriggerTransmit GW handle*/
#if ((STD_ON == PDUR_TRIGGER_TRANSMIT) && (PDUR_TX_BUFFER_SUM > 0u))
static FUNC(Std_ReturnType, PDUR_CODE)
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    PduR_IfTriggerTransmitGwHandle(PduIdType TxPduId, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr);
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
#endif

/*Copy RxPdu data to TxBuffer,called by PduR_EnQueueBuffer.
 * Gateway handle*/
#if ((STD_ON == PDUR_RX_INDICATION) && (PDUR_TX_BUFFER_SUM > 0u))
static FUNC(void, PDUR_CODE) PduR_CopyRxPduToTxBuffer(
#if (STD_ON == PDUR_META_DATA_SUPPORT)
    uint8 MetaDataLength,
#endif
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(PduR_TxBufferType, AUTOMATIC, PDUR_APPL_DATA) TxBufferPtr,
    /* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfo,
    PduLengthType PduLength);
#endif /*(STD_ON == PDUR_RX_INDICATION) && (PDUR_TX_BUFFER_SUM > 0u)*/

#define PDUR_STOP_SEC_CODE
#include "PduR_MemMap.h"
/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
/*PduR PB Configuration Run Time point parameter*/
#define PDUR_START_SEC_VAR_INIT_PTR
#include "PduR_MemMap.h"
P2CONST(PduR_PBConfigType, PDUR_CONST, PDUR_CONST_PBCFG) PduR_ConfigStd = NULL_PTR;
#define PDUR_STOP_SEC_VAR_INIT_PTR
#include "PduR_MemMap.h"
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define PDUR_START_SEC_CODE
#include "PduR_MemMap.h"
/******************************************************************************/
/*
 * Brief               Initializes the PDU Router
 * ServiceId           0xf0
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      ConfigPtr: Pointer to Post build configuration data.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, PDUR_CODE)
PduR_Init(P2CONST(PduR_PBConfigType, AUTOMATIC, PDUR_CONST_PBCFG) ConfigPtr)
{
#if ((0u < PDUR_TX_BUFFER_SUM) || (0u < PDUR_TP_BUFFER_SUM))
    uint16 index;
#endif
#if (STD_ON == PDUR_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (NULL_PTR == ConfigPtr)
    {
        (void)Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_INIT_ID, PDUR_E_INIT_FAILED);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
        PduR_ConfigStd = ConfigPtr;
        PduR_InitHandle();
/*Init TP Buffer*/
#if (0u < PDUR_TP_BUFFER_SUM)
        for (index = 0u; index < PDUR_TP_BUFFER_SUM; index++)
        {
            PduR_TpBuffer[index].used = FALSE;
        }
#endif
/*Init Tx Buffer*/
#if (0u < PDUR_TX_BUFFER_SUM)
        for (index = 0u; index < PDUR_TX_BUFFER_SUM; index++)
        {
            uint8 depthCnt, depth;
            depth = PduR_TxBuffer[index].PduRTxBufferDepth;
            for (depthCnt = 0u; depthCnt < depth; depthCnt++)
            {
                PduR_TxBuffer[index].PduRTxBufferRef[depthCnt].used = FALSE;
            }
        }
#endif
#if (STD_ON == PDUR_DEV_ERROR_DETECT)
        PduR_Status = PDUR_ONLINE;
#endif
    }
    return;
}
/******************************************************************************/
/*
 * Brief               Returns the unique identifier of the post-build time
 *                     configuration of the PDU Router
 * ServiceId           0xf2
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              PduR_PBConfigIdType: Identifier of the post-build time configuration
 */
/******************************************************************************/
FUNC(PduR_PBConfigIdType, PDUR_CODE)
PduR_GetConfigurationId(void)
{
#if (STD_ON == PDUR_DEV_ERROR_DETECT)
    if (PDUR_ONLINE != PduR_Status)
    {
        (void)Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_GETCONFIGURATIONID_ID, PDUR_E_UNINIT);
    }
#endif
    return PduR_ConfigStd->PduRConfigId;
}
/******************************************************************************/
/*
 * Brief               Enables a routing path table
 * ServiceId           0xf3
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      id: Identification of the routing path group.
 *                     Routing path groups are defined in the PDU router configuration
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, PDUR_CODE)
PduR_EnableRouting(PduR_RoutingPathGroupIdType id) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
#if (0u < PDUR_ROUTING_PATH_GROUP_MAX)
    PduIdType destPduId;
    PduIdType destPduNumber;
    PduIdType index;
#endif
#if (STD_ON == PDUR_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (PDUR_ONLINE != PduR_Status)
    {
        (void)Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_ENABLEROUTING_ID, PDUR_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr)
#if (0u < PDUR_ROUTING_PATH_GROUP_MAX)
        && ((id >= PDUR_ROUTING_PATH_GROUP_MAX) || (id >= PduR_ConfigStd->PduRRoutingPathGroupNum))
#endif
    )
    {
        (void)Det_ReportError(
            PDUR_MODULE_ID,
            PDUR_INSTANCE_ID,
            PDUR_ENABLEROUTING_ID,
            PDUR_E_ROUTING_PATH_GROUP_ID_INVALID);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if (0u < PDUR_ROUTING_PATH_GROUP_MAX)
        destPduNumber = PDUR_ROUTEPATHGROUP_CFG(id).PduRDestPduRefNumber;
        for (index = 0u; index < destPduNumber; index++)
        {
            destPduId = PDUR_ROUTEPATHGROUP_CFG(id).PduRDestPduIdRef[index];
            PduRIsEnabled[destPduId] = TRUE;
        }
#endif
    }
    PDUR_NOUSED(id);
    return;
}
/******************************************************************************/
/*
 * Brief               Disables a routing path table
 * ServiceId           0xf4
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      id: Identification of the routing path group.
 *                     Routing path groups are defined in the PDU router configuration
 *                     initialize (true,false)
 *                     true: initialize single buffers to the default value
 *                     false: retain current value of single buffers
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, PDUR_CODE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
PduR_DisableRouting(PduR_RoutingPathGroupIdType id, boolean initialize)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
#if (0u < PDUR_ROUTING_PATH_GROUP_MAX)
    PduIdType destPduNumber;
    PduIdType index;
    PduIdType destPduId;
#if (PDUR_TX_BUFFER_SUM > 0u)
    uint16 txBufferId;
    uint8 cnt, txBufferDepth;
    boolean clearTxBuffer;
#endif
#endif
#if (STD_ON == PDUR_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (PDUR_ONLINE != PduR_Status)
    {
        (void)Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_DISABLEROUTING_ID, PDUR_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr)
#if (0u < PDUR_ROUTING_PATH_GROUP_MAX)
        && ((id >= PDUR_ROUTING_PATH_GROUP_MAX) || (id >= PduR_ConfigStd->PduRRoutingPathGroupNum))
#endif
    )
    {
        (void)Det_ReportError(
            PDUR_MODULE_ID,
            PDUR_INSTANCE_ID,
            PDUR_DISABLEROUTING_ID,
            PDUR_E_ROUTING_PATH_GROUP_ID_INVALID);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if (0u < PDUR_ROUTING_PATH_GROUP_MAX)
        destPduNumber = PDUR_ROUTEPATHGROUP_CFG(id).PduRDestPduRefNumber;
        for (index = 0u; index < destPduNumber; index++)
        {
            destPduId = PDUR_ROUTEPATHGROUP_CFG(id).PduRDestPduIdRef[index];
            if (TRUE == PduRIsEnabled[destPduId])
            {
#if (PDUR_TX_BUFFER_SUM > 0u)
                txBufferId = PDUR_DESTPDU_CFG(destPduId).PduRDestTxBufferRef;
                if (PDUR_UNUSED_UINT16 != txBufferId)
                {
                    txBufferDepth = PduR_TxBuffer[txBufferId].PduRTxBufferDepth;
                    if (1u == txBufferDepth)
                    {
                        if (PDUR_TRIGGERTRANSMIT == PDUR_DESTPDU_CFG(destPduId).PduRDestPduDataProvision)
                        {
                            /*the according buffer shall be set to the default value*/
                            if (TRUE == initialize)
                            {
                                PduR_DestPduDefaultValueSet(destPduId, txBufferId);
                            }
                            clearTxBuffer = FALSE;
                        }
                        else
                        {
                            clearTxBuffer = TRUE;
                        }
                    }
                    else
                    {
                        clearTxBuffer = TRUE;
                    }
                    /*clear and the buffer*/
                    if (TRUE == clearTxBuffer)
                    {
                        if (TRUE == PduR_TxBuffer[txBufferId].PduRTxBufferRef[0u].used)
                        {
                            (void)Det_ReportRuntimeError(
                                PDUR_MODULE_ID,
                                PDUR_INSTANCE_ID,
                                PDUR_DISABLEROUTING_ID,
                                PDUR_E_PDU_INSTANCES_LOST);
                        }
                        for (cnt = 0u; cnt < txBufferDepth; cnt++)
                        {
                            PduR_TxBuffer[txBufferId].PduRTxBufferRef[cnt].used = FALSE;
                        }
                    }
                }
#endif /*PDUR_TX_BUFFER_SUM > 0u*/
                PduRIsEnabled[destPduId] = FALSE;
            }
        }
#endif
    }
    PDUR_NOUSED(id);
    PDUR_NOUSED(initialize);
    return;
}
/******************************************************************************/
/*
 * Brief               Requests transmission of an I-PDU.
 * ServiceId           0x49
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      id: Identification of the I-PDU.
 *                     info: Length and pointer to the buffer of the I-PDU.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType (E_OK,E_NOT_OK)
 *                     E_OK - request is accepted by the destination module; transmission is continued.
 *                     E_NOT_OK - request is not accepted by the destination module;transmission is aborted.
 */
/******************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE)
PduR_Transmit(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
    Std_ReturnType result = E_NOT_OK;
#if (STD_ON == PDUR_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (PDUR_ONLINE != PduR_Status)
    {
        (void)Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_TRANSMIT_ID, PDUR_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (NULL_PTR == info))
    {
        (void)Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_TRANSMIT_ID, PDUR_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr)
#if (0u < PDUR_ROUTINGPATH_MAX)
        && ((id >= PDUR_ROUTINGPATH_MAX) || (id >= PduR_ConfigStd->PduRRoutingPathNum))
#endif
    )
    {
        (void)Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_TRANSMIT_ID, PDUR_E_PDU_ID_INVALID);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if (STD_ON == PDUR_TRANSMIT_SUPPORT)
        result = PduR_UpModeTransmit(id, info);
#endif
    }
    PDUR_NOUSED(id);
    PDUR_NOUSED(info);
    return result;
}
/******************************************************************************/
/*
 * Brief               Requests cancellation of an ongoing transmission of an I-PDU in a lower
 *                     layer communication interface or transport protocol module.
 * ServiceId           0x4a
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      id: Identification of the I-PDU to be cancelled.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType (E_OK,E_NOT_OK)
 *                     E_OK - Cancellation was executed successfully by the destination module.
 *                     E_NOT_OK - Cancellation was rejected by the destination module.
 */
/******************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE)
PduR_CancelTransmit(PduIdType id)
{
    Std_ReturnType result = E_NOT_OK;
#if (STD_ON == PDUR_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (PDUR_ONLINE != PduR_Status)
    {
        (void)Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_CANCELTRANSMIT_ID, PDUR_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr)
#if (0u < PDUR_ROUTINGPATH_MAX)
        && ((id >= PDUR_ROUTINGPATH_MAX) || (id >= PduR_ConfigStd->PduRRoutingPathNum))
#endif
    )
    {
        (void)Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_CANCELTRANSMIT_ID, PDUR_E_PDU_ID_INVALID);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if (STD_ON == PDUR_CANCEL_TRANSMIT)
        result = PduR_UpModeCancelTransmit(id);
#endif
    }
    PDUR_NOUSED(id);
    return result;
}
/******************************************************************************/
/*
 * Brief               Request to change a specific transport protocol parameter (e.g. block size).
 * ServiceId           0x4b
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      id: Identifiaction of the I-PDU which the parameter change shall affect.
 *                     parameter: The parameter that shall change.
 *                     value: The new value of the parameter
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType (E_OK,E_NOT_OK)
 *                     E_OK: The parameter was changed successfully.
 *                     E_NOT_OK: The parameter change was rejected.
 */
/******************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE)
PduR_ChangeParameter(PduIdType id, TPParameterType parameter, uint16 value)
{
    Std_ReturnType result = E_NOT_OK;
#if (STD_ON == PDUR_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (PDUR_ONLINE != PduR_Status)
    {
        (void)Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_CHANGEPARAMETER_ID, PDUR_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr)
#if (0u < PDUR_ROUTINGPATH_MAX)
        && ((id >= PDUR_ROUTINGPATH_MAX) || (id >= PduR_ConfigStd->PduRRoutingPathNum)
            || (FALSE == PDUR_ROUTINGPATH_CFG(id).TpRoute))
#endif
    )
    {
        (void)Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_CHANGEPARAMETER_ID, PDUR_E_PDU_ID_INVALID);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if (STD_ON == PDUR_CHANGE_PARAMETER)
        result = PduR_UpModeChangeParameter(id, parameter, value);
#endif
    }
    PDUR_NOUSED(id);
    PDUR_NOUSED(parameter);
    PDUR_NOUSED(value);
    return result;
}
/******************************************************************************/
/*
 * Brief               Requests cancellation of an ongoing reception of an I-PDU in a lower layer transport protocol
 * module. ServiceId           0x4c Sync/Async          Synchronous Reentrancy          Non Reentrant Param-Name[in] id:
 * Identification of the I-PDU to be cancelled. Param-Name[out]     None Param-Name[in/out]  None Return Std_ReturnType
 * (E_OK,E_NOT_OK) E_OK: Cancellation was executed successfully by the destination module. E_NOT_OK: Cancellation was
 * rejected by the destination module.
 */
/******************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
PduR_CancelReceive(PduIdType id)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
    Std_ReturnType result = E_NOT_OK;
#if (STD_ON == PDUR_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    PduIdType pduRSourcePduId;
    if (PDUR_ONLINE != PduR_Status)
    {
        (void)Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_CANCELRECEIVE_ID, PDUR_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (id >= PduR_ConfigStd->PduRDestPduNum))
    {
        (void)Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_CANCELRECEIVE_ID, PDUR_E_PDU_ID_INVALID);
        detNoErr = FALSE;
    }
    pduRSourcePduId = PDUR_DESTPDU_CFG(id).PduRSrcPduRef;
    if ((TRUE == detNoErr) && (FALSE == PDUR_ROUTINGPATH_CFG(pduRSourcePduId).TpRoute))
    {
        (void)Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_CANCELRECEIVE_ID, PDUR_E_PDU_ID_INVALID);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if (STD_ON == PDUR_CANCEL_RECEIVE)
        result = PduR_UpModeCancelReceive(id);
#endif
    }
    PDUR_NOUSED(id);
    return result;
}

/*Store the If Rx Pdu data to buffer.
 *Just hoping to be called by PduR_Internal.c.
 *Not the AUTOSAR standard API.*/
#if ((STD_ON == PDUR_RX_INDICATION) && (PDUR_TX_BUFFER_SUM > 0u))
FUNC(void, PDUR_CODE)
PduR_EnQueueBuffer(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfo)
{
    uint8 bufferDepth;
    uint16 bufferId;
    uint8 cnt;
    boolean findIdleBuffer = FALSE;
    PduLengthType pduMaxLength;
    PduR_TxBufferType* txBufferPtr;
#if (STD_ON == PDUR_META_DATA_SUPPORT)
    uint8 metaDataLength;
    metaDataLength = PDUR_DESTPDU_CFG(PduId).MetaDataLength;
#endif
    bufferId = PDUR_DESTPDU_CFG(PduId).PduRDestTxBufferRef;
    pduMaxLength = PduR_TxBuffer[bufferId].PduRPduMaxLength;
    bufferDepth = PduR_TxBuffer[bufferId].PduRTxBufferDepth;
    if (pduMaxLength > PduInfo->SduLength)
    {
        pduMaxLength = PduInfo->SduLength;
    }
    if (1u == bufferDepth)
    {
        txBufferPtr = &(PduR_TxBuffer[bufferId].PduRTxBufferRef[0u]);
        PduR_CopyRxPduToTxBuffer(
#if (STD_ON == PDUR_META_DATA_SUPPORT)
            metaDataLength,
#endif
            txBufferPtr,
            PduInfo,
            pduMaxLength);
    }
    if (bufferDepth > 1u)
    {
        for (cnt = 0u; (cnt < bufferDepth) && (FALSE == findIdleBuffer); cnt++)
        {
            if (FALSE == PduR_TxBuffer[bufferId].PduRTxBufferRef[cnt].used)
            {
                findIdleBuffer = TRUE;
                txBufferPtr = &(PduR_TxBuffer[bufferId].PduRTxBufferRef[cnt]);
                PduR_CopyRxPduToTxBuffer(
#if (STD_ON == PDUR_META_DATA_SUPPORT)
                    metaDataLength,
#endif
                    txBufferPtr,
                    PduInfo,
                    pduMaxLength);
            }
        }
        /*all buffer is used, the FIFO is flushed */
        if (FALSE == findIdleBuffer)
        {
            txBufferPtr = &(PduR_TxBuffer[bufferId].PduRTxBufferRef[0u]);
            PduR_CopyRxPduToTxBuffer(
#if (STD_ON == PDUR_META_DATA_SUPPORT)
                metaDataLength,
#endif
                txBufferPtr,
                PduInfo,
                pduMaxLength);
            for (cnt = 1u; cnt < bufferDepth; cnt++)
            {
                PduR_TxBuffer[bufferId].PduRTxBufferRef[cnt].used = FALSE;
            }
            (void)Det_ReportRuntimeError(
                PDUR_MODULE_ID,
                PDUR_INSTANCE_ID,
                PDUR_IFRXINDICATION_ID,
                PDUR_E_PDU_INSTANCES_LOST);
        }
    }
    return;
}
#endif /*(STD_ON == PDUR_RX_INDICATION) && (PDUR_TX_BUFFER_SUM > 0u)*/

#define PDUR_STOP_SEC_CODE
#include "PduR_MemMap.h"
/******************************************************************************/
/*
 * Brief               Indication of a received I-PDU from a lower layer communication interface module.
 * ServiceId           0x42
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different PduIds. Non reentrant for the same PduId.
 * Param-Name[in]      RxPduId: ID of the received I-PDU.
 *                     PduInfoPtr: Contains the length (SduLength) of the received I-PDU and a pointer to a buffer
 * (SduDataPtr) containing the I-PDU. Param-Name[out]     None Param-Name[in/out]  None Return              None
 */
/******************************************************************************/
#define PDUR_START_SEC_IFRXINDICATION_CALLBACK_CODE
#include "PduR_MemMap.h"
FUNC(void, PDUR_CODE)
PduR_IfRxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr)
{
#if (STD_ON == PDUR_RX_INDICATION)
    uint8 cnt, pduDestSum;
    PduIdType pduRDestPduId;
    PduIdType destModulePduId;
    uint8 destModuleIndex;
    const PduRDestPduType* destPduConfigPtr;
    const PduRRoutingPathType* pdurRoutingPathCfgPtr;
    const PduIdType* destPduIdRefPtr;
#endif
#if (STD_ON == PDUR_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (PDUR_ONLINE != PduR_Status)
    {
        (void)Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_IFRXINDICATION_ID, PDUR_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr)
        && ((NULL_PTR == PduInfoPtr) || (NULL_PTR == PduInfoPtr->SduDataPtr)
#if (STD_ON == PDUR_META_DATA_SUPPORT)
            || ((0u < PDUR_SRCEPDU_CFG(RxPduId).MetaDataLength) && (NULL_PTR == PduInfoPtr->MetaDataPtr))
#endif
                ))
    {
        (void)Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_IFRXINDICATION_ID, PDUR_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr)
#if (0u < PDUR_ROUTINGPATH_MAX)
        && ((RxPduId >= PDUR_ROUTINGPATH_MAX) || (RxPduId >= PduR_ConfigStd->PduRRoutingPathNum)
            || (TRUE == PDUR_ROUTINGPATH_CFG(RxPduId).TpRoute))
#endif
    )
    {
        (void)Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_IFRXINDICATION_ID, PDUR_E_PDU_ID_INVALID);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if (STD_ON == PDUR_RX_INDICATION)
        pdurRoutingPathCfgPtr = &PDUR_ROUTINGPATH_CFG(RxPduId);
        destPduIdRefPtr = pdurRoutingPathCfgPtr->PduRDestPduIdRef;
        pduDestSum = pdurRoutingPathCfgPtr->PduDestSum;
        for (cnt = 0u; cnt < pduDestSum; cnt++)
        {
            pduRDestPduId = destPduIdRefPtr[cnt];
            destPduConfigPtr = &PDUR_DESTPDU_CFG(pduRDestPduId);
            destModulePduId = destPduConfigPtr->PduRDestModulePduIndex;
            destModuleIndex = destPduConfigPtr->BswModuleIndex;
            if (TRUE == PduRIsEnabled[pduRDestPduId])
            {
                if (FALSE == destPduConfigPtr->GateWayRoute)
                {
                    if (NULL_PTR != PduR_BswModuleConfigData[destModuleIndex].ModuleIfRxIndicationApi)
                    {
                        PduR_BswModuleConfigData[destModuleIndex].ModuleIfRxIndicationApi(destModulePduId, PduInfoPtr);
                    }
                }
                else
                {
                    PduR_GateWayIfPdu(destModuleIndex, pduRDestPduId, PduInfoPtr);
                }
            }
        }
#endif /*STD_ON == PDUR_RX_INDICATION*/
    }
    PDUR_NOUSED(RxPduId);
    PDUR_NOUSED(PduInfoPtr);
    return;
}
#define PDUR_STOP_SEC_IFRXINDICATION_CALLBACK_CODE
#include "PduR_MemMap.h"
/******************************************************************************/
/*
 * Brief               The lower layer communication interface module confirms the transmission of an IPDU.
 * ServiceId           0x40
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different PduIds. Non reentrant for the same PduId.
 * Param-Name[in]      TxPduId: ID of the I-PDU that has been transmitted.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#define PDUR_START_SEC_IFTXCONFIRMATION_CALLBACK_CODE
#include "PduR_MemMap.h"
FUNC(void, PDUR_CODE)
PduR_IfTxConfirmation(PduIdType TxPduId)
{
#if (STD_ON == PDUR_TX_CONFIRMATION)
    PduIdType srcPduId;
    uint8 srcPduModuleIndex;
    PduR_UpIfTxConfirmation_FuncPtrType pduR_UpIfTxConfirmationApi;
    const PduRSrcPduType* srcPduConfigPtr;
    const PduRDestPduType* destPduConfigPtr;
#endif
#if (STD_ON == PDUR_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (PDUR_ONLINE != PduR_Status)
    {
        (void)Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_IFTXCONFIRMATION_ID, PDUR_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (TxPduId >= PduR_ConfigStd->PduRDestPduNum))
    {
        (void)Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_IFTXCONFIRMATION_ID, PDUR_E_PDU_ID_INVALID);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if (STD_ON == PDUR_TX_CONFIRMATION)
        destPduConfigPtr = &PDUR_DESTPDU_CFG(TxPduId);
        srcPduId = destPduConfigPtr->PduRSrcPduRef;
        if (FALSE == PDUR_ROUTINGPATH_CFG(srcPduId).TpRoute)
        {
            srcPduConfigPtr = &PDUR_SRCEPDU_CFG(srcPduId);
            srcPduModuleIndex = srcPduConfigPtr->BswModuleIndex;
            /*Transmit route*/
            if (FALSE == destPduConfigPtr->GateWayRoute)
            {
                pduR_UpIfTxConfirmationApi = PduR_BswModuleConfigData[srcPduModuleIndex].ModuleTxConfirmationApi;
                if ((NULL_PTR != pduR_UpIfTxConfirmationApi) && (TRUE == srcPduConfigPtr->PduRSrcPduUpTxConf))
                {
                    PduIdType upTxStateId = srcPduConfigPtr->UpTxconfirmStateIndex;
                    PduIdType srcUpPduId = srcPduConfigPtr->PduRDestModulePduIndex;
                    /*route 1:1 Pdu from up module to lo If module*/
                    if (PDUR_UNUSED_UINT16 == upTxStateId)
                    {
                        pduR_UpIfTxConfirmationApi(srcUpPduId);
                    }
                    /*route 1:n Pdu from up module to lo If module,only the first Lo TxConfirm call Up TxConfirm*/
                    else
                    {
                        PduR_MulticastIfPduTxConfirmationHandle(upTxStateId, srcUpPduId, pduR_UpIfTxConfirmationApi);
                    }
                }
            }
            /*Gateway route*/
            else
            {
#if (PDUR_TX_BUFFER_SUM > 0u)
                PduR_IfTxConfirmationGatewayHandle(TxPduId);
#endif
            }
        }
#endif /*STD_ON == PDUR_TX_CONFIRMATION*/
    }
    PDUR_NOUSED(TxPduId);
    return;
}
#define PDUR_STOP_SEC_IFTXCONFIRMATION_CALLBACK_CODE
#include "PduR_MemMap.h"
/******************************************************************************/
/*
 * Brief               Within this API, the upper layer module (called module) shall check whether the
 *                     available data fits into the buffer size reported by PduInfoPtr->SduLength.
 *                     If it fits, it shall copy its data into the buffer provided by PduInfoPtr->SduDataPtr
 *                     and update the length of the actual copied data in PduInfoPtr->SduLength.
 *                     If not, it returns E_NOT_OK without changing PduInfoPtr.
 * ServiceId           0x41
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different PduIds. Non reentrant for the same PduId.
 * Param-Name[in]      TxPduId: ID of the SDU that is requested to be transmitted.
 * Param-Name[out]     None
 * Param-Name[in/out]  PduInfoPtr: Contains a pointer to a buffer (SduDataPtr) to where the SDU
 *                     data shall be copied, and the available buffer size in SduLengh.
 *                     On return, the service will indicate the length of the copied SDU
 *                     data in SduLength.
 * Return              None
 */
/******************************************************************************/
#define PDUR_START_SEC_IFTRIGGERTRANSMIT_CALLBACK_CODE
#include "PduR_MemMap.h"
FUNC(Std_ReturnType, PDUR_CODE)
/* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
PduR_IfTriggerTransmit(PduIdType TxPduId, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr)
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
{
    Std_ReturnType result = E_NOT_OK;
#if (STD_ON == PDUR_TRIGGER_TRANSMIT)
    PduIdType srcPduId;
    PduIdType srcUpPduId;
    uint8 srcModuleIndex;
#endif
#if (STD_ON == PDUR_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (PDUR_ONLINE != PduR_Status)
    {
        (void)Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_IFTRIGGERTRANSMIT_ID, PDUR_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (TxPduId >= PduR_ConfigStd->PduRDestPduNum))
    {
        (void)Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_IFTRIGGERTRANSMIT_ID, PDUR_E_PDU_ID_INVALID);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if (STD_ON == PDUR_TRIGGER_TRANSMIT)
        srcPduId = PDUR_DESTPDU_CFG(TxPduId).PduRSrcPduRef;
        if ((TRUE == PduRIsEnabled[TxPduId]) && (FALSE == PDUR_ROUTINGPATH_CFG(srcPduId).TpRoute))
        {
            /*Transmit route handle*/
            if (FALSE == PDUR_DESTPDU_CFG(TxPduId).GateWayRoute)
            {
                srcModuleIndex = PDUR_SRCEPDU_CFG(srcPduId).BswModuleIndex;
                if (NULL_PTR != PduR_BswModuleConfigData[srcModuleIndex].ModuleTriggertransmitApi)
                {
                    srcUpPduId = PDUR_SRCEPDU_CFG(srcPduId).PduRDestModulePduIndex;
                    result = PduR_BswModuleConfigData[srcModuleIndex].ModuleTriggertransmitApi(srcUpPduId, PduInfoPtr);
                }
            }
            /*Gateway route handle*/
            else
            {
#if (PDUR_TX_BUFFER_SUM > 0u)
                result = PduR_IfTriggerTransmitGwHandle(TxPduId, PduInfoPtr);
#endif /*PDUR_TX_BUFFER_SUM > 0u*/
            }
        }
#endif /*STD_ON == PDUR_TRIGGER_TRANSMIT*/
    }
    PDUR_NOUSED(TxPduId);
    PDUR_NOUSED(PduInfoPtr);
    return result;
}
#define PDUR_STOP_SEC_IFTRIGGERTRANSMIT_CALLBACK_CODE
#include "PduR_MemMap.h"
/******************************************************************************/
/*
 * Brief               This function is called at the start of receiving an N-SDU. The N-SDU might be
 *                     fragmented into multiple N-PDUs (FF with one or more following CFs) or might
 *                     consist of a single N-PDU (SF).
 * ServiceId           0x46
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      id: Identification of the I-PDU.
 *                     info: Pointer to a PduInfoType structure containing the payload
 *                     data (without protocol information) and payload length of the
 *                     first frame or single frame of a transport protocol I-PDU
 *                     reception. Depending on the global parameter
 *                     MetaDataLength, additional bytes containing MetaData (e.g.
 *                     the CAN ID) are appended after the payload data, increasing
 *                     the length accordingly. If neither first/single frame data nor
 *                     MetaData are available, this parameter is set to NULL_PTR.
 *                     TpSduLength: Total length of the N-SDU to be received.
 * Param-Name[out]     bufferSizePtr: Available receive buffer in the receiving module. This
 *                     parameter will be used to compute the Block Size (BS) in the transport protocol module.
 * Param-Name[in/out]  None
 * Return              BufReq_ReturnType(BUFREQ_OK,BUFREQ_E_NOT_OK,BUFREQ_E_OVFL)
 *                     BUFREQ_OK: Connection has been accepted. bufferSizePtr
 *                     indicates the available receive buffer; reception is continued.
 *                     If no buffer of the requested size is available, a receive buffer
 *                     size of 0 shall be indicated by bufferSizePtr.
 *                     BUFREQ_E_NOT_OK: Connection has been rejected;
 *                     reception is aborted. bufferSizePtr remains unchanged.
 *                     BUFREQ_E_OVFL: No buffer of the required length can be
 *                     provided; reception is aborted. bufferSizePtr remains unchanged.
 */
/******************************************************************************/
#define PDUR_START_SEC_TPSTARTOFRECEPTION_CALLBACK_CODE
#include "PduR_MemMap.h"
FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_TpStartOfReception(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    PduLengthType TpSduLength,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr)
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
{
    BufReq_ReturnType bufQeqReturn = BUFREQ_E_NOT_OK;
#if (STD_ON == PDUR_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (PDUR_ONLINE != PduR_Status)
    {
        (void)Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_TPSTARTOFRECEPTION_ID, PDUR_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr)
#if (0u < PDUR_ROUTINGPATH_MAX)
        && ((id >= PDUR_ROUTINGPATH_MAX) || (id >= PduR_ConfigStd->PduRRoutingPathNum)
            || (FALSE == PDUR_ROUTINGPATH_CFG(id).TpRoute))
#endif
    )
    {
        (void)Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_TPSTARTOFRECEPTION_ID, PDUR_E_PDU_ID_INVALID);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr)
        && ((NULL_PTR == bufferSizePtr)
#if (STD_ON == PDUR_META_DATA_SUPPORT)
            || ((0u < PDUR_SRCEPDU_CFG(id).MetaDataLength) && (NULL_PTR == info->MetaDataPtr))
#endif
                ))
    {
        (void)Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_TPSTARTOFRECEPTION_ID, PDUR_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if (STD_ON == PDUR_TP_STARTOFRECEPTION_TRANSMIT)
        bufQeqReturn = PduR_LoTpStartOfReception(id, info, TpSduLength, bufferSizePtr);
#endif
    }
    PDUR_NOUSED(id);
    PDUR_NOUSED(info);
    PDUR_NOUSED(TpSduLength);
    PDUR_NOUSED(bufferSizePtr);
    return bufQeqReturn;
}
#define PDUR_STOP_SEC_TPSTARTOFRECEPTION_CALLBACK_CODE
#include "PduR_MemMap.h"
/******************************************************************************/
/*
 * Brief               This function is called to provide the received data of an I-PDU segment (N-PDU) to the upper
 * layer. Each call to this function provides the next part of the I-PDU data. The size of the remaining data is written
 * to the position indicated by bufferSizePtr. ServiceId           0x44 Sync/Async          Synchronous Reentrancy
 * Reentrant Param-Name[in]      id: Identification of the received I-PDU. info: Provides the source buffer (SduDataPtr)
 * and the number of bytes to be copied (SduLength). An SduLength of 0 can be used to query the current amount of
 * available buffer in the upper layer module. In this case, the SduDataPtr may be a NULL_PTR. Param-Name[out]
 * bufferSizePtr: Available receive buffer after data has been copied. Param-Name[in/out]  None Return
 * BufReq_ReturnType(BUFREQ_OK,BUFREQ_E_NOT_OK) BUFREQ_OK: Data copied successfully BUFREQ_E_NOT_OK: Data was not copied
 * because an error occurred.
 */
/******************************************************************************/
#define PDUR_START_SEC_TPCOPYRXDATA_CALLBACK_CODE
#include "PduR_MemMap.h"
FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_TpCopyRxData(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr)
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
{
    BufReq_ReturnType bufQeqReturn = BUFREQ_E_NOT_OK;
#if (STD_ON == PDUR_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (PDUR_ONLINE != PduR_Status)
    {
        (void)Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_TPCOPYRXDATA_ID, PDUR_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr)
#if (0u < PDUR_ROUTINGPATH_MAX)
        && ((id >= PDUR_ROUTINGPATH_MAX) || (id >= PduR_ConfigStd->PduRRoutingPathNum)
            || (FALSE == PDUR_ROUTINGPATH_CFG(id).TpRoute))
#endif
    )
    {
        (void)Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_TPCOPYRXDATA_ID, PDUR_E_PDU_ID_INVALID);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && ((NULL_PTR == info) || (NULL_PTR == bufferSizePtr)))
    {
        (void)Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_TPCOPYRXDATA_ID, PDUR_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if (STD_ON == PDUR_TP_COPYRXDATA)
        bufQeqReturn = PduR_LoTpCopyRxData(id, info, bufferSizePtr);
#endif
    }
    PDUR_NOUSED(id);
    PDUR_NOUSED(info);
    PDUR_NOUSED(bufferSizePtr);
    return bufQeqReturn;
}
#define PDUR_STOP_SEC_TPCOPYRXDATA_CALLBACK_CODE
#include "PduR_MemMap.h"
/******************************************************************************/
/*
 * Brief               Called after an I-PDU has been received via the TP API, the result indicates
 *                     whether the transmission was successful or not.
 * ServiceId           0x45
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      id: Identification of the received I-PDU.
 *                     result: Result of the reception.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#define PDUR_START_SEC_TPRXINDICATION_CALLBACK_CODE
#include "PduR_MemMap.h"
FUNC(void, PDUR_CODE)
PduR_TpRxIndication(PduIdType id, Std_ReturnType result)
{
#if (STD_ON == PDUR_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (PDUR_ONLINE != PduR_Status)
    {
        (void)Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_TPRXINDICATION_ID, PDUR_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr)
#if (0u < PDUR_ROUTINGPATH_MAX)
        && ((id >= PDUR_ROUTINGPATH_MAX) || (id >= PduR_ConfigStd->PduRRoutingPathNum)
            || (FALSE == PDUR_ROUTINGPATH_CFG(id).TpRoute))
#endif
    )
    {
        (void)Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_TPRXINDICATION_ID, PDUR_E_PDU_ID_INVALID);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if (STD_ON == PDUR_TP_RXINDICATION)
        PduR_LoTpRxIndication(id, result);
#endif
    }
    PDUR_NOUSED(id);
    PDUR_NOUSED(result);
    return;
}
#define PDUR_STOP_SEC_TPRXINDICATION_CALLBACK_CODE
#include "PduR_MemMap.h"
/******************************************************************************/
/*
 * Brief               This function is called to acquire the transmit data of an I-PDU segment (N-PDU).
 *                     Each call to this function provides the next part of the I-PDU data unless retry-
 *                     >TpDataState is TP_DATARETRY. In this case the function restarts to copy the
 *                     data beginning at the offset from the current position indicated by retry-
 *                     >TxTpDataCnt. The size of the remaining data is written to the position indicated
 *                     by availableDataPtr.
 * ServiceId           0x43
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      id: Identification of the transmitted I-PDU.
 *                     info: Provides the destination buffer (SduDataPtr) and the number of bytes to be copied
 * (SduLength). If not enough transmit data is available, no data is copied by the upper layer module and BUFREQ_E_BUSY
 * is returned.The lower layer module may retry the call.An SduLength of 0 can be used to indicate state changes in the
 * retry parameter or to query the current amount of available data in the upper layer module. In this case, the
 * SduDataPtr may be a NULL_PTR. retry: This parameter is used to acknowledge transmitted data or to retransmit data
 * after transmission problems. If the retry parameter is a NULL_PTR, it indicates that the transmit data can be removed
 * from the buffer immediately after it has been copied. Otherwise, the retry parameter must point to a valid
 * RetryInfoType element. If TpDataState indicates TP_CONFPENDING, the previously copied data must remain in the TP
 * buffer to be available for error recovery.TP_DATACONF indicates that all data that has been copied before this call
 * is confirmed and can be removed from the TP buffer. Data copied by this API call is excluded and will be confirmed
 * later.TP_DATARETRY indicates that this API call shall copy previously copied data in order to recover from an error.
 * In this case TxTpDataCnt specifies the offset in bytes from the current data copy position. Param-Name[out]
 * availableDataPtr: Indicates the remaining number of bytes that are available in the upper layer module's Tx buffer.
 *                     availableDataPtr can be used by TP modules that support dynamic payload lengths (e.g. FrIsoTp) to
 * determine the size of the following CFs. Param-Name[in/out]  None Return              BufReq_ReturnType
 * (BUFREQ_OK,BUFREQ_E_BUSY,BUFREQ_E_NOT_OK) BUFREQ_OK: Data has been copied to the transmit buffer completely as
 * requested. BUFREQ_E_BUSY: Request could not be fulfilled, because the required amount of Tx data is not available.
 * The lower layer module may retry this call later on. No data has been copied. BUFREQ_E_NOT_OK: Data has not been
 * copied. Request failed.
 */
/******************************************************************************/
#define PDUR_START_SEC_TPCOPYTXDATA_CALLBACK_CODE
#include "PduR_MemMap.h"
FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_TpCopyTxData(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2CONST(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr)
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
{
    BufReq_ReturnType bufQeqReturn = BUFREQ_E_NOT_OK;
#if (STD_ON == PDUR_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    PduIdType srcPdu;
    srcPdu = PDUR_DESTPDU_CFG(id).PduRSrcPduRef;
    if (PDUR_ONLINE != PduR_Status)
    {
        (void)Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_TPCOPYTXDATA_ID, PDUR_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr)
        && ((id >= PduR_ConfigStd->PduRDestPduNum) || (FALSE == PDUR_ROUTINGPATH_CFG(srcPdu).TpRoute)))
    {
        (void)Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_TPCOPYTXDATA_ID, PDUR_E_PDU_ID_INVALID);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if (STD_ON == PDUR_TP_COPYTXDATA)
        bufQeqReturn = PduR_LoTpCopyTxData(id, info, retry, availableDataPtr);
#endif
    }
    PDUR_NOUSED(id);
    PDUR_NOUSED(info);
    PDUR_NOUSED(retry);
    PDUR_NOUSED(availableDataPtr);
    return bufQeqReturn;
}
#define PDUR_STOP_SEC_TPCOPYTXDATA_CALLBACK_CODE
#include "PduR_MemMap.h"
/******************************************************************************/
/*
 * Brief               This function is called after the I-PDU has been transmitted on its network, the
 *                     result indicates whether the transmission was successful or not.
 * ServiceId           0x48
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      id: Identification of the transmitted I-PDU.
 *                     result: Result of the transmission of the I-PDU.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#define PDUR_START_SEC_TPTXCONFIRMATION_CALLBACK_CODE
#include "PduR_MemMap.h"
FUNC(void, PDUR_CODE)
PduR_TpTxConfirmation(PduIdType id, Std_ReturnType result)
{
#if (STD_ON == PDUR_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    PduIdType srcPdu;
    srcPdu = PDUR_DESTPDU_CFG(id).PduRSrcPduRef;
    if (PDUR_ONLINE != PduR_Status)
    {
        (void)Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_TPTXCONFIRMATION_ID, PDUR_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr)
        && ((id >= PduR_ConfigStd->PduRDestPduNum) || (FALSE == PDUR_ROUTINGPATH_CFG(srcPdu).TpRoute)))
    {
        (void)Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_TPTXCONFIRMATION_ID, PDUR_E_PDU_ID_INVALID);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if (STD_ON == PDUR_TP_TXCONFIRMATION)
        PduR_LoTpTxConfirmation(id, result);
#endif
    }
    PDUR_NOUSED(id);
    PDUR_NOUSED(result);
    return;
}
#define PDUR_STOP_SEC_TPTXCONFIRMATION_CALLBACK_CODE
#include "PduR_MemMap.h"
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
#define PDUR_START_SEC_CODE
#include "PduR_MemMap.h"
#if (STD_ON == PDUR_TRANSMIT_SUPPORT)
static FUNC(Std_ReturnType, PDUR_CODE)
    PduR_UpModeTransmit(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
    Std_ReturnType result = E_NOT_OK;
    PduIdType pduRDestPduId;
    PduIdType loModulePduId;
    uint8 loModuleIndex;
    uint8 pduDestSum;
    uint8 cnt;
    const PduRDestPduType* destPduConfigPtr;
    const PduRRoutingPathType* pdurRoutingPathCfgPtr;
    pdurRoutingPathCfgPtr = &PDUR_ROUTINGPATH_CFG(id);
    pduDestSum = pdurRoutingPathCfgPtr->PduDestSum;
    /*route one up module pdu to tp module,just support 1:1*/
    if (TRUE == pdurRoutingPathCfgPtr->TpRoute)
    {
        if (1u == pduDestSum)
        {
            pduRDestPduId = pdurRoutingPathCfgPtr->PduRDestPduIdRef[0u];
            destPduConfigPtr = &PDUR_DESTPDU_CFG(pduRDestPduId);
            loModulePduId = destPduConfigPtr->PduRDestModulePduIndex;
            loModuleIndex = destPduConfigPtr->BswModuleIndex;
            if ((TRUE == PduRIsEnabled[pduRDestPduId])
                && (NULL_PTR != PduR_BswModuleConfigData[loModuleIndex].ModuleTpTransmitApi))
            {
                result = PduR_BswModuleConfigData[loModuleIndex].ModuleTpTransmitApi(loModulePduId, info);
            }
        }
    }
    /*route one up module pdu to if modules (pdus)*/
    else
    {
        for (cnt = 0u; cnt < pduDestSum; cnt++)
        {
            pduRDestPduId = pdurRoutingPathCfgPtr->PduRDestPduIdRef[cnt];
            destPduConfigPtr = &PDUR_DESTPDU_CFG(pduRDestPduId);
            loModulePduId = destPduConfigPtr->PduRDestModulePduIndex;
            loModuleIndex = destPduConfigPtr->BswModuleIndex;
            if ((TRUE == PduRIsEnabled[pduRDestPduId])
                && (NULL_PTR != PduR_BswModuleConfigData[loModuleIndex].ModuleIfTransmitApi))
            {
                if (E_OK == PduR_BswModuleConfigData[loModuleIndex].ModuleIfTransmitApi(loModulePduId, info))
                {
                    result = E_OK;
                }
            }
        }
        if ((1u < pduDestSum) && (E_OK == result))
        {
            PduR_MulticastIfPduTxPending(id);
        }
    }
    return result;
}
#endif /*STD_ON == PDUR_TRANSMIT_SUPPORT*/

#if (STD_ON == PDUR_CANCEL_TRANSMIT)
static FUNC(Std_ReturnType, PDUR_CODE) PduR_UpModeCancelTransmit(PduIdType id)
{
    Std_ReturnType result = E_NOT_OK;
    boolean resultOk = TRUE;
    PduIdType pduRDestPduId;
    PduIdType loModulePduId;
    uint8 loModuleIndex;
    uint8 pduDestSum;
    uint8 cnt;
    pduDestSum = PDUR_ROUTINGPATH_CFG(id).PduDestSum;
    /*Only all dest pdu cancel transmit OK,then return OK.*/
    for (cnt = 0u; (cnt < pduDestSum) && (TRUE == resultOk); cnt++)
    {
        pduRDestPduId = PDUR_ROUTINGPATH_CFG(id).PduRDestPduIdRef[cnt];
        loModulePduId = PDUR_DESTPDU_CFG(pduRDestPduId).PduRDestModulePduIndex;
        loModuleIndex = PDUR_DESTPDU_CFG(pduRDestPduId).BswModuleIndex;
        if (TRUE == PduRIsEnabled[pduRDestPduId])
        {
            if (TRUE == PDUR_ROUTINGPATH_CFG(id).TpRoute)
            {
                if (NULL_PTR != PduR_BswModuleConfigData[loModuleIndex].ModuleTpCancelTransmitApi)
                {
                    if (E_NOT_OK == PduR_BswModuleConfigData[loModuleIndex].ModuleTpCancelTransmitApi(loModulePduId))
                    {
                        resultOk = FALSE;
                    }
                }
            }
            else
            {
                if (NULL_PTR != PduR_BswModuleConfigData[loModuleIndex].ModuleIfCancelTransmitApi)
                {
                    if (E_NOT_OK == PduR_BswModuleConfigData[loModuleIndex].ModuleIfCancelTransmitApi(loModulePduId))
                    {
                        resultOk = FALSE;
                    }
                }
            }
        }
        else
        {
            resultOk = FALSE;
        }
    }
    if (TRUE == resultOk)
    {
        result = E_OK;
    }
    return result;
}
#endif /*STD_ON == PDUR_CANCEL_TRANSMIT*/

#if (STD_ON == PDUR_CHANGE_PARAMETER)
static FUNC(Std_ReturnType, PDUR_CODE) PduR_UpModeChangeParameter(PduIdType id, TPParameterType parameter, uint16 value)
{
    Std_ReturnType result = E_NOT_OK;
    PduIdType pduRSourcePduId;
    PduIdType loModulePduId;
    uint8 loModuleIndex;
    pduRSourcePduId = PDUR_DESTPDU_CFG(id).PduRSrcPduRef;
    loModulePduId = PDUR_SRCEPDU_CFG(pduRSourcePduId).PduRDestModulePduIndex;
    loModuleIndex = PDUR_SRCEPDU_CFG(pduRSourcePduId).BswModuleIndex;
    if ((TRUE == PduRIsEnabled[id]) && (NULL_PTR != PduR_BswModuleConfigData[loModuleIndex].ModuleChangeParameterApi))
    {
        result = PduR_BswModuleConfigData[loModuleIndex].ModuleChangeParameterApi(loModulePduId, parameter, value);
    }
    return result;
}
#endif /*STD_ON == PDUR_CHANGE_PARAMETER*/

#if (STD_ON == PDUR_CANCEL_RECEIVE)
static FUNC(Std_ReturnType, PDUR_CODE) PduR_UpModeCancelReceive(PduIdType id)
{
    Std_ReturnType result = E_NOT_OK;
    PduIdType pduRSourcePduId;
    PduIdType loModulePduId;
    uint8 loModuleIndex;
    pduRSourcePduId = PDUR_DESTPDU_CFG(id).PduRSrcPduRef;
    loModulePduId = PDUR_SRCEPDU_CFG(pduRSourcePduId).PduRDestModulePduIndex;
    loModuleIndex = PDUR_SRCEPDU_CFG(pduRSourcePduId).BswModuleIndex;
    if ((TRUE == PduRIsEnabled[id]) && (NULL_PTR != PduR_BswModuleConfigData[loModuleIndex].ModuleCancelReceiveApi))
    {
        result = PduR_BswModuleConfigData[loModuleIndex].ModuleCancelReceiveApi(loModulePduId);
    }
    return result;
}
#endif /*STD_ON == PDUR_CANCEL_RECEIVE*/

#if (STD_ON == PDUR_TP_STARTOFRECEPTION_TRANSMIT)
static FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LoTpStartOfReception(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    PduLengthType TpSduLength,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr)
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
{
    BufReq_ReturnType bufQeqReturn = BUFREQ_E_NOT_OK;
    uint8 pduDestSum;
    PduIdType pduRDestPduId;
    uint8 destModuleIndex;
    PduIdType upPduId;
    pduDestSum = PDUR_ROUTINGPATH_CFG(id).PduDestSum;
    /*route tp pdu 1:1*/
    if (1u == pduDestSum)
    {
        pduRDestPduId = PDUR_ROUTINGPATH_CFG(id).PduRDestPduIdRef[0u];
        if (TRUE == PduRIsEnabled[pduRDestPduId])
        {
            /*TP receive route*/
            if (FALSE == PDUR_DESTPDU_CFG(pduRDestPduId).GateWayRoute)
            {
                destModuleIndex = PDUR_DESTPDU_CFG(pduRDestPduId).BswModuleIndex;
                if (NULL_PTR != PduR_BswModuleConfigData[destModuleIndex].ModuleStartOfReceptionApi)
                {
                    upPduId = PDUR_DESTPDU_CFG(pduRDestPduId).PduRDestModulePduIndex;
                    bufQeqReturn = PduR_BswModuleConfigData[destModuleIndex]
                                       .ModuleStartOfReceptionApi(upPduId, info, TpSduLength, bufferSizePtr);
                }
            }
            /*TP gateway route*/
            else
            {
                bufQeqReturn = PduR_StartOfReceptionToOneTpHandle(id, info, TpSduLength, bufferSizePtr);
            }
        }
    }
    return bufQeqReturn;
}
#endif /*STD_ON == PDUR_TP_STARTOFRECEPTION_TRANSMIT*/

#if (STD_ON == PDUR_TP_COPYRXDATA)
static FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LoTpCopyRxData(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr)
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
{
    BufReq_ReturnType bufQeqReturn = BUFREQ_E_NOT_OK;
    uint8 pduDestSum;
    PduIdType pduRDestPduId;
    uint8 destModuleIndex;
    PduIdType upPduId;
    pduDestSum = PDUR_ROUTINGPATH_CFG(id).PduDestSum;
    /*one dest pdu*/
    if (1u == pduDestSum)
    {
        pduRDestPduId = PDUR_ROUTINGPATH_CFG(id).PduRDestPduIdRef[0u];
        if (TRUE == PduRIsEnabled[pduRDestPduId])
        {
            /*TP receive route*/
            if (FALSE == PDUR_DESTPDU_CFG(pduRDestPduId).GateWayRoute)
            {
                destModuleIndex = PDUR_DESTPDU_CFG(pduRDestPduId).BswModuleIndex;
                if (NULL_PTR != PduR_BswModuleConfigData[destModuleIndex].ModuleCopyRxDataApi)
                {
                    upPduId = PDUR_DESTPDU_CFG(pduRDestPduId).PduRDestModulePduIndex;
                    bufQeqReturn =
                        PduR_BswModuleConfigData[destModuleIndex].ModuleCopyRxDataApi(upPduId, info, bufferSizePtr);
                }
            }
            /*TP gateway route*/
            else
            {
                bufQeqReturn = PduR_CopyRxDataToOneTpHandle(
#if (0u < PDUR_TP_BUFFER_SUM)
                    id,
#endif
                    pduRDestPduId,
                    info,
                    bufferSizePtr);
            }
        }
    }
    return bufQeqReturn;
}
#endif /*STD_ON == PDUR_TP_COPYRXDATA*/

#if (STD_ON == PDUR_TP_RXINDICATION)
static FUNC(void, PDUR_CODE) PduR_LoTpRxIndication(PduIdType id, Std_ReturnType result)
{
    uint8 pduDestSum;
    PduIdType pduRDestPduId;
    uint8 destModuleIndex;
    PduIdType upPduId;
    pduDestSum = PDUR_ROUTINGPATH_CFG(id).PduDestSum;
    /*rx tp pdu to only one dest pdu*/
    if (1u == pduDestSum)
    {
        pduRDestPduId = PDUR_ROUTINGPATH_CFG(id).PduRDestPduIdRef[0u];
        /*TP receive route*/
        if (FALSE == PDUR_DESTPDU_CFG(pduRDestPduId).GateWayRoute)
        {
            destModuleIndex = PDUR_DESTPDU_CFG(pduRDestPduId).BswModuleIndex;
            if (NULL_PTR != PduR_BswModuleConfigData[destModuleIndex].ModuleTpRxIndicationApi)
            {
                upPduId = PDUR_DESTPDU_CFG(pduRDestPduId).PduRDestModulePduIndex;
                PduR_BswModuleConfigData[destModuleIndex].ModuleTpRxIndicationApi(upPduId, result);
            }
        }
        /*TP gateway route*/
        else
        {
            if ((E_OK == result) && (TRUE == PduRIsEnabled[pduRDestPduId]))
            {
                PduR_RxIndicationToOneTpHandle(id, pduRDestPduId);
            }
            else
            {
                PduR_ClearBufferAndStateOfGateWayTpPdu(id);
            }
        }
    }
    return;
}
#endif /*STD_ON == PDUR_TP_RXINDICATION*/

#if (STD_ON == PDUR_TP_COPYTXDATA)
static FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LoTpCopyTxData(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2CONST(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr)
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
{
    BufReq_ReturnType bufQeqReturn = BUFREQ_E_NOT_OK;
    PduIdType srcPdu;
    uint8 srcModuleIndex;
    PduIdType upPduId;
    srcPdu = PDUR_DESTPDU_CFG(id).PduRSrcPduRef;
    /*one dest pdu route*/
    if (1u == PDUR_ROUTINGPATH_CFG(srcPdu).PduDestSum)
    {
        if (TRUE == PduRIsEnabled[id])
        {
            /*TP transmit route*/
            if (FALSE == PDUR_DESTPDU_CFG(id).GateWayRoute)
            {
                srcModuleIndex = PDUR_SRCEPDU_CFG(srcPdu).BswModuleIndex;
                if (NULL_PTR != PduR_BswModuleConfigData[srcModuleIndex].ModuleCopyTxDataApi)
                {
                    upPduId = PDUR_SRCEPDU_CFG(srcPdu).PduRDestModulePduIndex;
                    bufQeqReturn = PduR_BswModuleConfigData[srcModuleIndex]
                                       .ModuleCopyTxDataApi(upPduId, info, retry, availableDataPtr);
                }
            }
            /*TP gateway route*/
            else
            {
                bufQeqReturn = PduR_OneDestCopyTxDataFromTpHandle(id, info, retry, availableDataPtr);
            }
        }
    }
    return bufQeqReturn;
}
#endif /*STD_ON == PDUR_TP_COPYTXDATA*/

#if (STD_ON == PDUR_TP_TXCONFIRMATION)
static FUNC(void, PDUR_CODE) PduR_LoTpTxConfirmation(PduIdType id, Std_ReturnType result)
{
    PduIdType srcPdu;
    uint8 srcModuleIndex;
    PduIdType upPduId;
    srcPdu = PDUR_DESTPDU_CFG(id).PduRSrcPduRef;
    /*one dest pdu route*/
    if (1u == PDUR_ROUTINGPATH_CFG(srcPdu).PduDestSum)
    {
        /*TP transmit route*/
        if (FALSE == PDUR_DESTPDU_CFG(id).GateWayRoute)
        {
            srcModuleIndex = PDUR_SRCEPDU_CFG(srcPdu).BswModuleIndex;
            if (NULL_PTR != PduR_BswModuleConfigData[srcModuleIndex].ModuleTpTxConfirmationApi)
            {
                upPduId = PDUR_SRCEPDU_CFG(srcPdu).PduRDestModulePduIndex;
                PduR_BswModuleConfigData[srcModuleIndex].ModuleTpTxConfirmationApi(upPduId, result);
            }
        }
        /*TP gateway route*/
        else
        {
            PduR_ClearBufferAndStateOfGateWayTpPdu(srcPdu);
        }
    }
    return;
}
#endif /*STD_ON == PDUR_TP_TXCONFIRMATION*/

#if ((STD_ON == PDUR_RX_INDICATION) && (PDUR_TX_BUFFER_SUM > 0u))
static FUNC(void, PDUR_CODE) PduR_CopyRxPduToTxBuffer(
#if (STD_ON == PDUR_META_DATA_SUPPORT)
    uint8 MetaDataLength,
#endif
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(PduR_TxBufferType, AUTOMATIC, PDUR_APPL_DATA) TxBufferPtr,
    /* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfo,
    PduLengthType PduLength)
{
    TxBufferPtr->used = TRUE;
    TxBufferPtr->SduLength = PduLength;
    PduR_Memcpy(TxBufferPtr->TxBufferData, PduInfo->SduDataPtr, PduLength);
#if (STD_ON == PDUR_META_DATA_SUPPORT)
    if (0u < MetaDataLength)
    {
        PduR_Memcpy(TxBufferPtr->MetaData, PduInfo->MetaDataPtr, (PduLengthType)MetaDataLength);
    }
#endif
    return;
}
#endif /*(STD_ON == PDUR_RX_INDICATION) && (PDUR_TX_BUFFER_SUM > 0u)*/

#if (STD_ON == PDUR_RX_INDICATION)
static FUNC(void, PDUR_CODE)
    PduR_GateWayIfPdu(uint8 DestModule, PduIdType DestPduId, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) InfoPtr)
{
    PduR_DestPduDataProvisionType provisionType;
#if (PDUR_TX_BUFFER_SUM > 0u)
    PduInfoType pduInfo;
#endif
    PduIdType destModulePduId;
    PduR_LoIfTransmit_FuncPtrType pduR_LoIfTransmitApi = PduR_BswModuleConfigData[DestModule].ModuleIfTransmitApi;
    if (NULL_PTR != pduR_LoIfTransmitApi)
    {
        provisionType = PDUR_DESTPDU_CFG(DestPduId).PduRDestPduDataProvision;
        destModulePduId = PDUR_DESTPDU_CFG(DestPduId).PduRDestModulePduIndex;
        if (PDUR_TRIGGERTRANSMIT == provisionType)
        {
#if (PDUR_TX_BUFFER_SUM > 0u)
            PduR_EnQueueBuffer(DestPduId, InfoPtr);
            pduInfo.SduDataPtr = NULL_PTR;
            pduInfo.SduLength = 0u;
            pduInfo.MetaDataPtr = InfoPtr->MetaDataPtr;
            (void)pduR_LoIfTransmitApi(destModulePduId, &pduInfo);
#endif /*PDUR_TX_BUFFER_SUM > 0u*/
        }
        else
        {
            /*don't configuration buffer*/
            if (PDUR_UNUSED_UINT16 == PDUR_DESTPDU_CFG(DestPduId).PduRDestTxBufferRef)
            {
                (void)pduR_LoIfTransmitApi(destModulePduId, InfoPtr);
            }
#if (PDUR_TX_BUFFER_SUM > 0u)
            else
            {
                PduR_GateWayDirectBufferHandle(pduR_LoIfTransmitApi, DestPduId, InfoPtr);
            }
#endif /*(PDUR_TX_BUFFER_SUM > 0u)*/
        }
    }
    return;
}
#endif /*STD_ON == PDUR_RX_INDICATION*/

/*Called by PduR_IfTriggerTransmit.
 *IfTriggerTransmit GW handle*/
#if ((STD_ON == PDUR_TRIGGER_TRANSMIT) && (PDUR_TX_BUFFER_SUM > 0u))
static FUNC(Std_ReturnType, PDUR_CODE)
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    PduR_IfTriggerTransmitGwHandle(PduIdType TxPduId, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr)
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
{
    Std_ReturnType result = E_NOT_OK;
    uint16 bufferId;
    PduInfoType pduInfo;
    uint8 moduleId;
    PduR_LoIfTransmit_FuncPtrType PduR_LoIfTransmitApi;
    bufferId = PDUR_DESTPDU_CFG(TxPduId).PduRDestTxBufferRef;
    if ((PDUR_UNUSED_UINT16 != bufferId) && (TRUE == PduR_TxBuffer[bufferId].PduRTxBufferRef[0u].used)
        && (PduInfoPtr->SduLength >= PduR_TxBuffer[bufferId].PduRTxBufferRef[0u].SduLength))
    {
        PduInfoPtr->SduLength = PduR_TxBuffer[bufferId].PduRTxBufferRef[0u].SduLength;
        PduR_Memcpy(
            PduInfoPtr->SduDataPtr,
            PduR_TxBuffer[bufferId].PduRTxBufferRef[0u].TxBufferData,
            PduInfoPtr->SduLength);
#if (STD_ON == PDUR_META_DATA_SUPPORT)
        if (0u < PDUR_DESTPDU_CFG(TxPduId).MetaDataLength)
        {
            PduR_Memcpy(
                PduInfoPtr->MetaDataPtr,
                PduR_TxBuffer[bufferId].PduRTxBufferRef[0u].MetaData,
                (PduLengthType)PDUR_DESTPDU_CFG(TxPduId).MetaDataLength);
        }
        else
#endif
        {
            PduInfoPtr->MetaDataPtr = NULL_PTR;
        }
        if (1u < PduR_TxBuffer[bufferId].PduRTxBufferDepth)
        {
            PduR_DeQueueBuffer(TxPduId);
            if (TRUE == PduR_TxBuffer[bufferId].PduRTxBufferRef[0u].used)
            {
                moduleId = PDUR_DESTPDU_CFG(TxPduId).BswModuleIndex;
                PduR_LoIfTransmitApi = PduR_BswModuleConfigData[moduleId].ModuleIfTransmitApi;
                if (NULL_PTR != PduR_LoIfTransmitApi)
                {
                    pduInfo.SduDataPtr = NULL_PTR;
                    pduInfo.SduLength = 0u;
#if (STD_ON == PDUR_META_DATA_SUPPORT)
                    if (0u < PDUR_DESTPDU_CFG(TxPduId).MetaDataLength)
                    {
                        pduInfo.MetaDataPtr = PduR_TxBuffer[bufferId].PduRTxBufferRef[0u].MetaData;
                    }
                    else
#endif
                    {
                        pduInfo.MetaDataPtr = NULL_PTR;
                    }
                    (void)PduR_LoIfTransmitApi(PDUR_DESTPDU_CFG(TxPduId).PduRDestModulePduIndex, &pduInfo);
                }
            }
        }
        result = E_OK;
    }
    return result;
}
#endif /*(STD_ON == PDUR_TRIGGER_TRANSMIT) && (PDUR_TX_BUFFER_SUM > 0u)*/

#define PDUR_STOP_SEC_CODE
#include "PduR_MemMap.h"
#pragma default_function_attributes =
#endif /* STD_OFF == PDUR_ZERO_COST_OPERATION */
/*=======[E N D   O F   F I L E]==============================================*/
