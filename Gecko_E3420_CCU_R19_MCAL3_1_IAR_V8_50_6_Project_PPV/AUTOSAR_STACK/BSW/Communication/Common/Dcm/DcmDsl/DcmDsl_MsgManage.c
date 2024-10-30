/******************************************************************************
**                                                                           **
** Copyright (C) iSOFT   (2022)                                              **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to iSOFT.        **
** Passing on and copying of this document, and communication                **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
**************************************************************************** **
**                                                                           **
**  FILENAME    :                                                            **
**                                                                           **
**  Created on  : 2020/5/6 14:29:43                                          **
**  Author      : tao.yu                                                     **
**  Vendor      :                                                            **
**  DESCRIPTION :                                                            **
**                                                                           **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                      **
**                                                                           **
**************************************************************************** */

/*=======[I N C L U D E S]===================================================*/
#include "Dcm_Internal.h"
#include "UDS.h"
#include "ComM_Dcm.h"

/*=======[T Y P E   D E F I N I T I O N S]====================================*/
typedef uint8 Dcm_ServiceType;
#define DCM_OBD        ((Dcm_ServiceType)0x00u)
#define DCM_UDS        ((Dcm_ServiceType)0x01u)
#define DCM_ROE        ((Dcm_ServiceType)0x02u)
#define DCM_PERIODIC   ((Dcm_ServiceType)0x03u)
#define DCM_NO_SERVICE ((Dcm_ServiceType)0x04u)

uint8 CCU_DiagTesterOnlineFlag;
uint32 CCU_DiagTesterOnlineTimer;

/******************************************/

/******************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dcm_TpRxIndication_IsFuncAddress(PduIdType DcmRxPduId);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/******************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dcm_CopyTxData_CheckCtrlStatus(PduIdType DcmTxPduId);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Dcm_ServiceType, DCM_CODE) Dcm_ClassifyServiceType(Dcm_ProtocolType protocolType);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
/********************************************************
 *******************Resource definition******************
 ********************************************************/
/*Static channel allocation of resources*/
#define DCM_START_SEC_VAR_NO_INIT_8
#include "Dcm_MemMap.h"
VAR(uint8, DCM_VAR_POWER_ON_INIT) Dcm_Channel[DCM_CHANNEL_LENGTH];
#define DCM_STOP_SEC_VAR_NO_INIT_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"
VAR(Dcm_ChannelCtrlType, DCM_VAR_NOINIT) Dcm_ChannelCtrl[DCM_CHANNEL_NUM];
/*Channel control block*/
VAR(Dcm_MsgCtrlType, DCM_VAR_NOINIT) Dcm_MsgCtrl[DCM_MSG_NUM];
/*Message control block, corresponding to uds service*/
VAR(Dcm_ConnectionCtrlType, DCM_VAR_NOINIT) Dcm_ConnectionCtrl[DCM_CONNECTION_NUM];
#define DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"
static VAR(Dcm_FunctionMessageType, DCM_VAR_NOINIT) Dcm_FunctionalMessage;
/*Function addressing packets resources,power on init*/
#define DCM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_POWER_ON_INIT_8 /* PRQA S 0791 */ /* MISRA Rule 5.4 */
#include "Dcm_MemMap.h"
static VAR(boolean, DCM_VAR_POWER_ON_INIT) StopProtocolFaild = FALSE;
/*StopProtocolFaild Then Rxindication is come shall send NRC*/
#define DCM_STOP_SEC_VAR_POWER_ON_INIT_8 /* PRQA S 0791 */ /* MISRA Rule 5.4 */
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"
static VAR(Dcm_OBDMessageType, DCM_VAR_NOINIT) Dcm_OBDMessage;
#define DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"

#if (STD_ON == DCM_REQUEST_QUEUED_ENABLED)
#define DCM_START_SEC_VAR_NO_INIT_8
#include "Dcm_MemMap.h"
uint8 Dcm_QueuedIndex;
VAR(uint8, DCM_VAR_POWER_ON_INIT) Dcm_RequestQueuedBuffer[2u][DCM_REQUEST_QUEUED_BUFFER_SIZE];
#define DCM_STOP_SEC_VAR_NO_INIT_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"
Dcm_QueuedRequestCtrlType Dcm_QueuedRequestCtrl[2u];
#define DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"
#endif /* STD_ON == DCM_REQUEST_QUEUED_ENABLED */
/****************************** implementations ********************************/
/*************************************************************************/
/*
 * Brief               Utility function:copy memory data.
 * ServiceId           N/A
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      Source memory address to copy from
 *                     Dest memory address to copy to
 *                     Length memory length to copy
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        N/A
 * CallByAPI           CanTp Internal
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(void, DCM_CODE)
Dcm_MemoryCopy(
    P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) Source,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Dest,
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
    uint32 Length)
{
    uint32 Cnt;
    for (Cnt = 0; Cnt < Length; Cnt++)
    {
        Dest[Cnt] = Source[Cnt];
    }
    return;
}
/*************************************************************************/
/*
 * Brief               <Initializing the corresponding channel control block>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <ChannelCtrlId:channel control block ID>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <Std_ReturnType>
 * PreCondition        <None>
 * CallByAPI           <Dcm_Init()>
 */
/*************************************************************************/
FUNC(void, DCM_CODE) DslInternal_InitChannelCtrl(uint8 ChannelCtrlId)
{
    if (ChannelCtrlId < DCM_CHANNEL_NUM)
    {
        SchM_Enter_Dcm(Dcm_ChannelCtrl);
        Dcm_ChannelCtrl[ChannelCtrlId].Dcm_ChannelCfgIndex = DCM_INVALID_UINT8;
#if (STD_ON == DCM_REQUEST_QUEUED_ENABLED)
        if (DCM_PENDING_REQUEST_PROCESS == Dcm_QueuedRequestCtrl[0u].Dcm_PendingRequestState)
        {
            Dcm_QueuedRequestCtrl[0u].Dcm_PendingRequestState = DCM_PENDING_REQUEST_NONE;
            Dcm_QueuedRequestCtrl[0u].Dcm_QueuedRequestBufferCunrentPosition = 0u;
        }
        else if (DCM_PENDING_REQUEST_PROCESS == Dcm_QueuedRequestCtrl[1u].Dcm_PendingRequestState)
        {
            Dcm_QueuedRequestCtrl[1u].Dcm_PendingRequestState = DCM_PENDING_REQUEST_NONE;
            Dcm_QueuedRequestCtrl[1u].Dcm_QueuedRequestBufferCunrentPosition = 0u;
        }
        else
        {
            /* idle */
        }
        if ((DCM_PENDING_REQUEST_NONE == Dcm_QueuedRequestCtrl[0u].Dcm_PendingRequestState)
            && (DCM_PENDING_REQUEST_NONE == Dcm_QueuedRequestCtrl[1u].Dcm_PendingRequestState))
        {
#endif /* STD_ON == DCM_REQUEST_QUEUED_ENABLED */
            Dcm_ChannelCtrl[ChannelCtrlId].Dcm_ChannelRxState = DCM_CH_IDLE;
#if (STD_ON == DCM_REQUEST_QUEUED_ENABLED)
        }
#endif /* STD_ON == DCM_REQUEST_QUEUED_ENABLED */
        Dcm_ChannelCtrl[ChannelCtrlId].Dcm_ChannelTxState = DCM_CH_IDLE;
        Dcm_ChannelCtrl[ChannelCtrlId].Dcm_BufferCunrentPosition = 0u;
        Dcm_ChannelCtrl[ChannelCtrlId].Dcm_BufferErasePosition = 0u;
        SchM_Exit_Dcm(Dcm_ChannelCtrl);
    }
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#if (STD_ON == DCM_REQUEST_QUEUED_ENABLED)
/*************************************************************************/
/*
 * Brief               <Initializing the corresponding channel queued reqeust control block>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <ChannelCtrlId:channel control block ID>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <Std_ReturnType>
 * PreCondition        <None>
 * CallByAPI           <Dcm_Init()>
 */
/*************************************************************************/
FUNC(void, DCM_CODE) DslInternal_InitChannelQueuedRequestCtrl(void)
{
    Dcm_QueuedRequestCtrl[0u].Dcm_PendingRequestState = DCM_PENDING_REQUEST_NONE;
    Dcm_QueuedRequestCtrl[1u].Dcm_PendingRequestState = DCM_PENDING_REQUEST_NONE;
    Dcm_QueuedRequestCtrl[0u].Dcm_QueuedRequestRxPduId = DCM_INVALID_PDUID;
    Dcm_QueuedRequestCtrl[1u].Dcm_QueuedRequestRxPduId = DCM_INVALID_PDUID;
    Dcm_QueuedRequestCtrl[0u].Dcm_QueuedRequestBufferCunrentPosition = 0u;
    Dcm_QueuedRequestCtrl[1u].Dcm_QueuedRequestBufferCunrentPosition = 0u;
    Dcm_QueuedRequestCtrl[0u].Dcm_QueuedRequestLength = 0u;
    Dcm_QueuedRequestCtrl[1u].Dcm_QueuedRequestLength = 0u;
}
#endif /* STD_ON == DCM_REQUEST_QUEUED_ENABLED */

/*************************************************************************/
/*
 * Brief               <initialization message control block>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <MsgCtrlId:message control block ID Index>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <Std_ReturnType>
 * PreCondition        <None>
 * CallByAPI           <Dcm_Init()>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(void, DCM_CODE) DslInternal_InitMsgCtrl(uint8 MsgCtrlId)
{
    if (MsgCtrlId < DCM_MSG_NUM)
    {
        SchM_Enter_Dcm(Dcm_MsgCtrl);
        Dcm_MsgCtrl[MsgCtrlId].SID = DCM_INVALID_UINT8;
        Dcm_MsgCtrl[MsgCtrlId].Subfunction = DCM_INVALID_UINT8;
        Dcm_MsgCtrl[MsgCtrlId].NRC = DCM_INVALID_UINT8;
        Dcm_MsgCtrl[MsgCtrlId].SendFlag = FALSE;
        Dcm_MsgCtrl[MsgCtrlId].RspStyle = DCM_POS_RSP;
        Dcm_MsgCtrl[MsgCtrlId].DcmTxPduId = DCM_INVALID_PDUID;
        Dcm_MsgCtrl[MsgCtrlId].Dcm_RxCtrlChannelIndex = DCM_INVALID_UINT8;
        Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex = DCM_INVALID_UINT8;
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.DcmRxPduId = DCM_INVALID_PDUID;
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData = NULL_PTR;
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen = 0;
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.pResData = NULL_PTR;
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResDataLen = DCM_INVALID_UINT32;
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.MsgAddInfo.ReqType = (uint8)DCM_PHYSICAL;
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.MsgAddInfo.SuppressPosResponse = FALSE;
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.MsgAddInfo.CancelOperation = FALSE;
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResMaxDataLen = DCM_INVALID_UINT32;
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.IdContext = DCM_INVALID_UINT8;
        Dcm_MsgCtrl[MsgCtrlId].Dcm_P2Ctrl.Dcm_P2CurTimer = DCM_INVALID_UINT32;
        Dcm_MsgCtrl[MsgCtrlId].Dcm_P2Ctrl.Dcm_P2ExpiredTimer = DCM_INVALID_UINT32;
        Dcm_MsgCtrl[MsgCtrlId].Dcm_P2Ctrl.PendingNum = 0u;
        Dcm_MsgCtrl[MsgCtrlId].Dcm_P2Ctrl.Dcm_P2State = DCM_P2TIMER_OFF;
        Dcm_MsgCtrl[MsgCtrlId].Dcm_MsgState = DCM_MSG_WAIT;
        Dcm_MsgCtrl[MsgCtrlId].Dcm_Ret = E_NOT_OK;
        Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_INITIAL;
#if (STD_ON == DCM_GENERIC_CONNECTION)
        Dcm_MsgCtrl[MsgCtrlId].Dcm_MetaData_AE = DCM_INVALID_UINT8;
        Dcm_MsgCtrl[MsgCtrlId].Dcm_MetaData_SA = DCM_INVALID_UINT16;
        Dcm_MsgCtrl[MsgCtrlId].Dcm_MetaData_TA = DCM_INVALID_UINT16;
        Dcm_MsgCtrl[MsgCtrlId].Dcm_MetaData_AE_Backup = DCM_INVALID_UINT8;
        Dcm_MsgCtrl[MsgCtrlId].Dcm_MetaData_SA_Backup = DCM_INVALID_UINT16;
        Dcm_MsgCtrl[MsgCtrlId].Dcm_MetaData_TA_Backup = DCM_INVALID_UINT16;
        Dcm_MsgCtrl[MsgCtrlId].DcmRxPduId = DCM_INVALID_PDUID;
#endif
        SchM_Exit_Dcm(Dcm_MsgCtrl);
    }
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*************************************************************************/
/*
 * Brief               <initialization module control block>
 * ServiceId           <None>
 * Sync/Async          <Synchronous/Asynchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <description...>
 * CallByAPI           <Dcm_Init()>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(void, DCM_CODE) DslInternal_InitMkCtrl(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    SchM_Enter_Dcm(Dcm_MkCtrl);
    Dcm_MkCtrl.Dcm_ActiveSes = DCM_DEFAULT_SESSION;
    Dcm_MkCtrl.Dcm_ActiveSec = DCM_SEC_LEV_LOCKED;
    Dcm_MkCtrl.Dcm_ActiveProtocol = DCM_NO_ACTIVE_PROTOCOL;
    Dcm_MkCtrl.Dcm_ActiveNetwork = DCM_INVALID_UINT8;
    Dcm_MkCtrl.Dcm_ActiveProtocolCfgCtrlId = DCM_INVALID_UINT8;
    Dcm_MkCtrl.Dcm_MkState = DCM_ON;
    SchM_Exit_Dcm(Dcm_MkCtrl);
    Dcm_OBDMessage.Length = 0u;
    Dcm_FunctionalMessage.Length = 0u;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*************************************************************************/
/*
 * Brief               <Reset protocol control block members MsgCtrlIndex +
 *                      Reset corresponding message control block +
 *                      Reset corresponding receive / transmit channel control block>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <ProtocolCtrlId:protocol control block ID>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <Std_ReturnType>
 * PreCondition        <>
 * CallByAPI           <>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(void, DCM_CODE) DslInternal_ResetResource(uint8 ProtocolCtrlId)
{
    PduIdType TxPduId;
    uint8 ConnectionCfgCtrlId;
    NetworkHandleType NetworkChannel;
    uint8 MsgCtrlIndexx;
    uint8 RxChannelCtrlIndex;
    uint8 TxChannelCtrlIndex;
    uint8 Index;
    boolean Flag;
    Dcm_ProtocolType ProtocolId;
    Dcm_ServiceType ServiceType;

    MsgCtrlIndexx = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    NetworkChannel = Dcm_MkCtrl.Dcm_ActiveNetwork;
    /**********************************************************/
    /*ComM Inactive processing*/
    if (DCM_DEFAULT_SESSION == Dcm_MkCtrl.Dcm_ActiveSes)
    {
        Flag = FALSE;
        for (Index = 0; (Index < DCM_MSG_NUM) && (FALSE == Flag); Index++)
        {
            if ((ProtocolCtrlId != Index) && (DCM_MSG_WAIT != Dcm_MsgCtrl[Index].Dcm_MsgState))
            {
                Flag = TRUE;
            }
        }
        if (FALSE == Flag)
        {
#if DCM_DELAY_COMM_INACTIVE
            /*delay S3 time to Notice ComM exit "FULL Communication"*/
            DslInternal_S3ServerStart();
#else
            /*Notice ComM exit "FULL Communication"*/
            ComM_DCM_InactiveDiagnostic(NetworkChannel);
            SchM_Enter_Dcm(Dcm_MkCtrl);
            Dcm_MkCtrl.Dcm_ActiveNetwork = DCM_INVALID_UINT8;
            SchM_Exit_Dcm(Dcm_MkCtrl);
#endif
        }
    }
    /*****************S3Serer timer****************/
#if (STD_ON == DCM_SESSION_FUNC_ENABLED)
    if (DCM_DEFAULT_SESSION != Dcm_MkCtrl.Dcm_ActiveSes)
    {
        Flag = FALSE;
        for (Index = 0; (Index < DCM_MSG_NUM) && (FALSE == Flag); Index++)
        {
            if ((ProtocolCtrlId != Index) && (DCM_MSG_WAIT != Dcm_MsgCtrl[Index].Dcm_MsgState))
            {
                Flag = TRUE;
            }
        }
        if (FALSE == Flag)
        {
            /*restart s3timer */
            DslInternal_S3ServerStart();
        }
    }
#endif
    /*****************Reset Message*****************/
    RxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_RxCtrlChannelIndex;
    TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_TxCtrlChannelIndex;

    SchM_Enter_Dcm(Dcm_ProtocolCtrl);
    Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex = DCM_INVALID_UINT8;
    SchM_Exit_Dcm(Dcm_ProtocolCtrl);
    TxPduId = Dcm_MsgCtrl[MsgCtrlIndexx].DcmTxPduId;
    for (Index = 0; Index < DCM_DSL_TX_ID_NUM; Index++)
    {
        if (TxPduId == Dsl_Protocol_Connection_TxCfg[Index].DcmDslTxPduRPduId)
        {
            ConnectionCfgCtrlId = Dsl_Protocol_Connection_TxCfg[Index].DcmDslParentConnectionCtrlId;
            DslInternal_InitConnectionCtrl(ConnectionCfgCtrlId);
        }
    }

    DslInternal_InitMsgCtrl(MsgCtrlIndexx);
    DslInternal_InitChannelCtrl(RxChannelCtrlIndex);
    DslInternal_InitChannelCtrl(TxChannelCtrlIndex);
    ProtocolId = Dsl_ProtocolRowCfg[ProtocolCtrlId].DcmDslProtocolID;
    ServiceType = Dcm_ClassifyServiceType(ProtocolId);
    if (ServiceType == DCM_OBD)
    {
        Dcm_OBDMessage.Length = 0u;
    }
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
/************************************************************************/
static FUNC(Dcm_ServiceType, DCM_CODE) Dcm_ClassifyServiceType(Dcm_ProtocolType protocolType)
{
    Dcm_ServiceType serviceType;
    switch (protocolType)
    {
    case DCM_OBD_ON_CAN:
    case DCM_OBD_ON_FLEXRAY:
    case DCM_OBD_ON_IP:
        serviceType = DCM_OBD;
        break;
    case DCM_UDS_ON_CAN:
    case DCM_UDS_ON_FLEXRAY:
    case DCM_UDS_ON_IP:
        serviceType = DCM_UDS;
        break;
    case DCM_ROE_ON_CAN:
    case DCM_ROE_ON_FLEXRAY:
    case DCM_ROE_ON_IP:
        serviceType = DCM_ROE;
        break;
    case DCM_PERIODICTRANS_ON_CAN:
    case DCM_PERIODICTRANS_ON_FLEXRAY:
    case DCM_PERIODICTRANS_ON_IP:
        serviceType = DCM_PERIODIC;
        break;
    default:
        serviceType = DCM_NO_SERVICE;
        break;
    }
    return serviceType;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dcm_CheckProtocol(uint8 ProtocolCfgId, Dcm_ServiceType ServiceType)
{
    uint8 FindProtocolCfgId;
    uint8 iloop;
    boolean FindProtocolValid = FALSE;
    uint8 OldProtocolPri;
    uint8 NewProtocolPri;
    Std_ReturnType ret = E_OK;
    Dcm_ServiceType FindServiceType;
#if (PREEMPTION_PROTOCOL_CANCEL_SUPPORT == STD_ON)
    PduIdType DcmTxPduIdx;
#endif
    if (DCM_PROTOCOL_VALID != Dcm_ProtocolCtrl[ProtocolCfgId].Dcm_ProtocolState)
    {
        /*check all protocol whether have one protocol had already started*/
        for (iloop = 0; (iloop < DCM_DSLPROTOCOLROW_NUM_MAX) && (FindProtocolValid == FALSE); iloop++)
        {
            FindProtocolCfgId = Dsl_Protocol_ConnectionCfg[iloop].DcmDslParentProtocolRowCtrlId;
            FindServiceType = Dcm_ClassifyServiceType(Dsl_ProtocolRowCfg[FindProtocolCfgId].DcmDslProtocolID);
            if ((DCM_PROTOCOL_VALID == Dcm_ProtocolCtrl[FindProtocolCfgId].Dcm_ProtocolState)
                && (FindServiceType == ServiceType))
            {
                FindProtocolValid = TRUE; /*have finded a starting protocol*/
            }
        }
        if (FindProtocolValid == TRUE)
        {
            if (ServiceType == DCM_OBD)
            {
                if (Dcm_OBDMessage.Buffer[0] == 0x3Eu)
                {
                    ret = E_NOT_OK;
                }
                else
                {
                    SchM_Enter_Dcm(Dcm_MsgCtrl);
                    Dcm_MsgCtrl[ProtocolCfgId].SID = Dcm_OBDMessage.Buffer[0];
                    SchM_Exit_Dcm(Dcm_MsgCtrl);
                }
            }
            else
            {
                if ((Dcm_MsgCtrl[ProtocolCfgId].MsgContext.pReqData)[0] == 0x3Eu)
                {
                    ret = E_NOT_OK;
                }
                else
                {
                    SchM_Enter_Dcm(Dcm_MsgCtrl);
                    Dcm_MsgCtrl[ProtocolCfgId].SID = Dcm_MsgCtrl[ProtocolCfgId].MsgContext.pReqData[0];
                    SchM_Exit_Dcm(Dcm_MsgCtrl);
                }
                OldProtocolPri = Dcm_ProtocolCtrl[FindProtocolCfgId].ProtocolPri;
                NewProtocolPri = (Dcm_DslCfg.pDcmDslProtocol->pDcmDslProtocolRow)[ProtocolCfgId].DcmDslProtocolPriority;
                if (E_OK == ret)
                {
                    if (NewProtocolPri < OldProtocolPri)
                    {
                        if (E_OK != DslInternal_ProtocolStop(FindProtocolCfgId))
                        {
                            StopProtocolFaild = TRUE;
                            ret = E_NOT_OK;
                        }
                        else
                        { /* protocol Preemption successful*/
#if (PREEMPTION_PROTOCOL_CANCEL_SUPPORT == STD_ON)
                            DcmTxPduIdx = Dcm_MsgCtrl[Dcm_ProtocolCtrl[FindProtocolCfgId].MsgCtrlIndex].DcmTxPduId;
                            switch (Dcm_MsgCtrl[FindProtocolCfgId].Dcm_MsgState)
                            {
                            case DCM_MSG_TRANSMISSION:
                                (void)PduR_DcmCancelTransmit(DcmTxPduIdx);
                                break;
                            case DCM_MSG_RECEIVED:
                                (void)PduR_DcmCancelReceive(DcmTxPduIdx);
                                break;
                            default:
                                /* idle */
                                break;
                            }
#endif
                            SchM_Enter_Dcm(Dcm_MsgCtrl);
                            Dcm_MsgCtrl[Dcm_ProtocolCtrl[FindProtocolCfgId].MsgCtrlIndex].Dcm_OpStatus = DCM_CANCEL;
                            SchM_Exit_Dcm(Dcm_MsgCtrl);
                            DslInternal_ResetResource(FindProtocolCfgId);
                        }
                    }
                    else
                    {
                        if (((Dcm_MsgCtrl[FindProtocolCfgId].Dcm_MsgState == DCM_MSG_WAIT)
                             || (Dcm_MsgCtrl[FindProtocolCfgId].Dcm_MsgState == DCM_MSG_CONFIRMATION))
#if (STD_ON == DCM_SESSION_FUNC_ENABLED)
                            && (DCM_DEFAULT_SESSION == Dcm_MkCtrl.Dcm_ActiveSes)
#endif
                        )
                        {
                            if (E_OK != DslInternal_ProtocolStop(FindProtocolCfgId))
                            {
                                StopProtocolFaild = TRUE;
                                ret = E_NOT_OK;
                            }
                            else
                            { /* protocol Preemption successful*/
                                DslInternal_ResetResource(FindProtocolCfgId);
                            }
                        }
                        else
                        {
                            ret = E_NOT_OK;
                        }
                    }
                }
            }
        }
    }
    else
    {
        /*protocol is not already started*/
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#if (STD_ON == DCM_GENERIC_CONNECTION)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(BufReq_ReturnType, DCM_CODE)
    Dcm_StartOfReception_metadata(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, DCM_VAR) info)
{
    BufReq_ReturnType bufRet = BUFREQ_OK;
    uint8 MetaDataLen;
    uint8 ConnectionCfgCtrlId;
    uint8 ProtocolCfgCtrlId;
    uint8 MsgCtrlIndex;
    Dcm_DslProtocolRxAddrType RxAddrType;

    ConnectionCfgCtrlId = Dsl_Protocol_Connection_RxCfg[id].DcmDslParentConnectionCtrlId;
    ProtocolCfgCtrlId = Dsl_Protocol_ConnectionCfg[ConnectionCfgCtrlId].DcmDslParentProtocolRowCtrlId;
    MsgCtrlIndex = ProtocolCfgCtrlId;
    RxAddrType = Dsl_Protocol_Connection_RxCfg[id].DcmDslProtocolRxAddrType;

    MetaDataLen = Dsl_Protocol_Connection_RxCfg[id].DcmDslMetaDataFlag & DCM_METADATA_LENGTH_MASK;
    if ((MetaDataLen > 0u)
        && ((DCM_ADDRESS_EXTENSION_8_MASK
             == (Dsl_Protocol_Connection_RxCfg[id].DcmDslMetaDataFlag & DCM_ADDRESS_EXTENSION_8_MASK))
            || (DCM_SA16_AND_TA16_MASK
                == (Dsl_Protocol_Connection_RxCfg[id].DcmDslMetaDataFlag & DCM_SA16_AND_TA16_MASK))))
    {
        SchM_Enter_Dcm(Dcm_MsgCtrl);
        Dcm_MsgCtrlType* pMsgCtrl = &Dcm_MsgCtrl[MsgCtrlIndex];
        if (((Dsl_Protocol_Connection_RxCfg[id].DcmDslMetaDataFlag & DCM_SA16_AND_TA16_MASK) == DCM_SA16_AND_TA16_MASK)
            && (NULL_PTR != info))
        {
            if (DCM_PHYSICAL == RxAddrType)
            {
#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
                pMsgCtrl->Dcm_MetaData_SA = (uint16)((uint16)info->MetaDataPtr[0u] << 8u) | info->MetaDataPtr[1u];
                pMsgCtrl->Dcm_MetaData_TA = (uint16)((uint16)info->MetaDataPtr[2u] << 8u) | info->MetaDataPtr[3u];
#else
                pMsgCtrl->Dcm_MetaData_SA = (uint16)((uint16)info->MetaDataPtr[1u] << 8u) | info->MetaDataPtr[0u];
                pMsgCtrl->Dcm_MetaData_TA = (uint16)((uint16)info->MetaDataPtr[3u] << 8u) | info->MetaDataPtr[2u];
#endif
            }
            else
            {
#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
                pMsgCtrl->Dcm_MetaData_SA_Backup =
                    (uint16)((uint16)info->MetaDataPtr[0u] << 8u) | info->MetaDataPtr[1u];
                pMsgCtrl->Dcm_MetaData_TA_Backup =
                    (uint16)((uint16)info->MetaDataPtr[2u] << 8u) | info->MetaDataPtr[3u];
#else
                pMsgCtrl->Dcm_MetaData_SA_Backup =
                    (uint16)((uint16)info->MetaDataPtr[1u] << 8u) | info->MetaDataPtr[0u];
                pMsgCtrl->Dcm_MetaData_TA_Backup =
                    (uint16)((uint16)info->MetaDataPtr[3u] << 8u) | info->MetaDataPtr[2u];
#endif
            }
        }
        if (((Dsl_Protocol_Connection_RxCfg[id].DcmDslMetaDataFlag & DCM_ADDRESS_EXTENSION_8_MASK)
             == DCM_ADDRESS_EXTENSION_8_MASK)
            && (NULL_PTR != info))
        {
            if (DCM_PHYSICAL == RxAddrType)
            {
                pMsgCtrl->Dcm_MetaData_AE = info->MetaDataPtr[4u];
            }
            else
            {
                pMsgCtrl->Dcm_MetaData_AE_Backup = info->MetaDataPtr[4u];
            }
        }
        SchM_Exit_Dcm(Dcm_MsgCtrl);
        if (DCM_PHYSICAL == RxAddrType)
        {
            if (pMsgCtrl->Dcm_MetaData_TA
                != Dsl_ProtocolRowCfg[ProtocolCfgCtrlId]
                       .pDcmDslConnection->pDcmDslMainConnection->DcmDslProtocolRxTesterSourceAddr)
            {
                bufRet = BUFREQ_E_NOT_OK;
            }
        }
        else
        {
            pMsgCtrl->Dcm_MetaData_TA_Backup =
                Dsl_ProtocolRowCfg[ProtocolCfgCtrlId]
                    .pDcmDslConnection->pDcmDslMainConnection->DcmDslProtocolRxTesterSourceAddr;
        }
    }
    return bufRet;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(BufReq_ReturnType, DCM_CODE) Dcm_StartOfReception_Checklength(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, DCM_VAR) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, DCM_VAR) bufferSizePtr) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    BufReq_ReturnType bufRet = BUFREQ_E_NOT_OK;
    uint8 ConnectionCfgCtrlId;
    uint8 ProtocolCfgCtrlId;
    uint8 MsgCtrlIndex;
    uint8 RxChannelCfgCtrlId;
    uint8 TxChannelCfgCtrlId;
    Dcm_ProtocolType ProtocolId;
    Dcm_ServiceType ServiceType;
    uint32 len = 0;
    Dcm_DslProtocolRxAddrType RxAddrType;
#if (STD_ON == DCM_REQUEST_QUEUED_ENABLED)
    uint8 tempQueueIndex;
#endif /* STD_ON == DCM_REQUEST_QUEUED_ENABLED */

    ConnectionCfgCtrlId = Dsl_Protocol_Connection_RxCfg[id].DcmDslParentConnectionCtrlId;
    ProtocolCfgCtrlId = Dsl_Protocol_ConnectionCfg[ConnectionCfgCtrlId].DcmDslParentProtocolRowCtrlId;
    MsgCtrlIndex = ProtocolCfgCtrlId;
    RxChannelCfgCtrlId = Dsl_ProtocolRowCfg[ProtocolCfgCtrlId].DcmDslProtocolRxBufferRef->Dcm_DslBufferId;
    TxChannelCfgCtrlId = Dsl_ProtocolRowCfg[ProtocolCfgCtrlId].DcmDslProtocolTxBufferRef->Dcm_DslBufferId;
    RxAddrType = Dsl_Protocol_Connection_RxCfg[id].DcmDslProtocolRxAddrType;
    ProtocolId = Dsl_ProtocolRowCfg[ProtocolCfgCtrlId].DcmDslProtocolID;
    ServiceType = Dcm_ClassifyServiceType(ProtocolId);

    switch (ServiceType)
    {
#if (DCM_UDS_FUNC_ENABLED == STD_ON)
    case DCM_UDS:
        len = (Dcm_DslCfg.pDcmChannelCfg)[RxChannelCfgCtrlId].Dcm_DslBufferSize;
        break;
#endif
#if (DCM_OBD_FUNC_ENABLED == STD_ON)
    case DCM_OBD:
        len = 8u;
        break;
#endif
    default:
        /*idle*/
        break;
    }
    /*Compare application buffer length and configuration of the channel length*/
    if (len < (uint32)TpSduLength)
    {
        bufRet = BUFREQ_E_OVFL;
    }
    else if (0u == TpSduLength)
    {
        /*idle*/
    }
    else
    {
#if (STD_ON == DCM_SESSION_FUNC_ENABLED)
        /*Start of a multi-frame request message or Reception of single-frame request message.*/
        /*Stop S3Server timer*/
        if (DCM_DEFAULT_SESSION != Dcm_MkCtrl.Dcm_ActiveSes)
        {
            DslInternal_S3ServerStop();
        }
#endif
        if ((Dcm_ChannelCtrl[RxChannelCfgCtrlId].Dcm_ChannelRxState == DCM_CH_OCCUPIED)
            || (Dcm_ChannelCtrl[TxChannelCfgCtrlId].Dcm_ChannelTxState == DCM_CH_OCCUPIED))
        {
#if (STD_ON == DCM_REQUEST_QUEUED_ENABLED)
            if ((TRUE == Dcm_DslCfg.pDcmDslProtocol->pDcmDslProtocolRow[ProtocolCfgCtrlId].DcmDslProtocolRequestQueued)
                && (DCM_FUNCTIONAL != RxAddrType))
            {
                if (DCM_PENDING_REQUEST_NONE == Dcm_QueuedRequestCtrl[Dcm_QueuedIndex].Dcm_PendingRequestState)
                {
                    bufRet = BUFREQ_OK;
                    Dcm_QueuedRequestCtrl[Dcm_QueuedIndex].Dcm_PendingRequestState = DCM_PENDING_REQUEST_RECEIVE;
                }
                else if (
                    (DCM_MSG_WAIT == Dcm_MsgCtrl[MsgCtrlIndex].Dcm_MsgState)
                    || (DCM_PENDING_REQUEST_PROCESS == Dcm_QueuedRequestCtrl[Dcm_QueuedIndex].Dcm_PendingRequestState))
                {
                    tempQueueIndex = (Dcm_QueuedIndex == 0u) ? 1u : 0u;
                    if (DCM_PENDING_REQUEST_NONE == Dcm_QueuedRequestCtrl[tempQueueIndex].Dcm_PendingRequestState)
                    {
                        bufRet = BUFREQ_OK;
                        Dcm_QueuedIndex = tempQueueIndex;
                        Dcm_QueuedRequestCtrl[Dcm_QueuedIndex].Dcm_PendingRequestState = DCM_PENDING_REQUEST_RECEIVE;
                    }
                }
                else
                {
                    /* idle */
                }
            }
            else
            {
#endif /* STD_ON == DCM_REQUEST_QUEUED_ENABLED */
                if (FALSE == Dcm_ConnectionCtrl[ConnectionCfgCtrlId].Dcm_ConnectionActive)
                {
                    /*new diagnostic request with different connection*/
                    if ((DCM_FUNCTIONAL == RxAddrType) && (0u == Dcm_FunctionalMessage.Length))
                    {
                        /*new diagnostic request is test present or
                         * OBD service for function addressing*/
                        bufRet = BUFREQ_OK;
                    }
                    else
                    {
                        if (TRUE == Dcm_DslCfg.pDcmDslDiagRespCfg->DcmDslDiagRespOnSecondDeclinedRequest)
                        {
                            /*the Dcm respond with a NRC 0x21*/
                            SchM_Enter_Dcm(Dcm_ProtocolCtrl);
                            Dcm_ProtocolCtrl[ProtocolCfgCtrlId].MsgCtrlIndex = MsgCtrlIndex;
                            SchM_Exit_Dcm(Dcm_ProtocolCtrl);
                            DsdInternal_SetNrc(ProtocolCfgCtrlId, DCM_E_BUSYREPEATREQUEST);
#if (STD_ON == DCM_GENERIC_CONNECTION)
                            if (DCM_INVALID_PDUID == Dcm_MsgCtrl[MsgCtrlIndex].DcmRxPduId)
                            {
                                Dcm_MsgCtrl[MsgCtrlIndex].Dcm_TxCtrlChannelIndex = TxChannelCfgCtrlId;
                                Dcm_MsgCtrl[MsgCtrlIndex].DcmRxPduId = id;
                            }
#endif /* STD_ON == DCM_GENERIC_CONNECTION */
                            DsdInternal_ProcessingDone(ProtocolCfgCtrlId);
                            bufRet = BUFREQ_OK;
                        }
                    }
                }
                else
                {
                    /*,new diagnostic request with the same DcmDslConnection*/
                    if ((DCM_FUNCTIONAL == RxAddrType) && (0u == Dcm_FunctionalMessage.Length))
                    {
                        /*functional addressing eg. concurrent Tester Present*/
                        bufRet = BUFREQ_OK;
                    }
                }
#if (STD_ON == DCM_REQUEST_QUEUED_ENABLED)
            }
#endif /* STD_ON == DCM_REQUEST_QUEUED_ENABLED */
        }
        else
        {
            /*no diagnostic request is processing*/
            bufRet = BUFREQ_OK;
        }
    } /*ENDOF len < TpSduLength*/
    if (BUFREQ_OK == bufRet)
    {
        if ((info != NULL_PTR) && (len < (uint32)info->SduLength))
        {
            *bufferSizePtr = 0;
        }
        else
        {
            *bufferSizePtr = (PduLengthType)len;
        }
#if (STD_ON == DCM_GENERIC_CONNECTION)
        bufRet = Dcm_StartOfReception_metadata(id, info);
#endif
    }
    return bufRet;
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
/*************************************************************************/
/*
 * Brief               <This function is called at the start
                        of receiving an N-SDU. The N-SDU might be
                        fragmented into multiple N-PDUs
                        (FF with one or more following CFs) or might
                        consist of a single N-PDU (SF)>
 * ServiceId           <0x46>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <DcmRxPduId:  the received data PduId;
 *                      TpSduLength: This length identifies the overall
 *                      number of bytes to be received.>
 * Param-Name[out]     <PduInfoPtr:  Pointer to pointer to PduInfoType
 * containing data pointer and length of a receive buffe>
 * Param-Name[in/out]  <None>
 * Return              <BUFREQ_OK,BUFREQ_E_NOT_OK,BUFREQ_E_OVFL,BUFREQ_E_BUSY>
 * PreCondition        <None>
 * CallByAPI           <>
 */
/*************************************************************************/
#define DCM_START_SEC_DCMSTARTOFRECEPTION_CALLBACK_CODE
#include "Dcm_MemMap.h"
FUNC(BufReq_ReturnType, DCM_CODE)
Dcm_StartOfReception(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, DCM_VAR) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, DCM_VAR) bufferSizePtr) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    uint8 ConnectionCfgCtrlId;
    uint8 ProtocolCfgCtrlId;
    uint8 MsgCtrlIndex;
    uint8 RxChannelCfgCtrlId;
    Dcm_ProtocolType ProtocolId;
    Dcm_ServiceType ServiceType;
    uint32 Offset;
    Dcm_DslProtocolRxAddrType RxAddrType;
    BufReq_ReturnType bufRet = BUFREQ_E_NOT_OK;

#if (STD_ON == DCM_DEV_ERROR_DETECT)
    /*check whether Dcm is initialized*/
    if (DCM_ON != (Dcm_MkCtrl.Dcm_MkState))
    {
        DCM_DET_REPORTERROR(DCM_STARTOFRECEPTION_ID, DCM_E_UNINIT);
    }
    else if (NULL_PTR == bufferSizePtr)
    {
        /*Entry parameter validity checks*/
        DCM_DET_REPORTERROR(DCM_STARTOFRECEPTION_ID, DCM_E_PARAM_POINTER);
    }
    else if (id >= DCM_DSL_RX_ID_NUM)
    {
        /*Entry parameter validity checks*/
        DCM_DET_REPORTERROR(DCM_STARTOFRECEPTION_ID, DCM_E_PARAM);
    }
    else
#endif
    {
        ConnectionCfgCtrlId = Dsl_Protocol_Connection_RxCfg[id].DcmDslParentConnectionCtrlId;
        ProtocolCfgCtrlId = Dsl_Protocol_ConnectionCfg[ConnectionCfgCtrlId].DcmDslParentProtocolRowCtrlId;
        MsgCtrlIndex = ProtocolCfgCtrlId;
        RxChannelCfgCtrlId = Dsl_ProtocolRowCfg[ProtocolCfgCtrlId].DcmDslProtocolRxBufferRef->Dcm_DslBufferId;
        RxAddrType = Dsl_Protocol_Connection_RxCfg[id].DcmDslProtocolRxAddrType;
        ProtocolId = Dsl_ProtocolRowCfg[ProtocolCfgCtrlId].DcmDslProtocolID;
        ServiceType = Dcm_ClassifyServiceType(ProtocolId);
#if (STD_ON == DCM_UDS_SERVICE0X86_ENABLED)
        bufRet = Dcm_UDS0x86_CheckProcessRoe(ProtocolCfgCtrlId);
        if (bufRet == BUFREQ_OK)
        {
#endif
            bufRet = Dcm_StartOfReception_Checklength(id, info, TpSduLength, bufferSizePtr);
            if (bufRet == BUFREQ_OK)
            {
                Offset = (Dcm_DslCfg.pDcmChannelCfg)[RxChannelCfgCtrlId].offset;
                if ((info != NULL_PTR) && (0u < info->SduLength))
                {
                    if (DCM_FUNCTIONAL == RxAddrType)
                    {
                        switch (ServiceType)
                        {
                        case DCM_UDS: {
                            /*The UDS protocol functions addressing message, bypass treatment*/
                            Dcm_MemoryCopy(info->SduDataPtr, &(Dcm_FunctionalMessage.Buffer[0]), info->SduLength);
                            Dcm_FunctionalMessage.Length = info->SduLength;
                            /*save request length*/
                            bufRet = BUFREQ_OK;
                            break;
                        }
                        case DCM_OBD: {
                            /*The OBD protocol only have functions addressing message*/
                            Dcm_MemoryCopy(info->SduDataPtr, &(Dcm_OBDMessage.Buffer[0]), info->SduLength);
                            Dcm_OBDMessage.Length = info->SduLength; /*save request length*/
                            bufRet = BUFREQ_OK;
                            break;
                        }
                        default:
                            /*idle*/
                            break;
                        }
                    }
                    else
#if (STD_ON == DCM_REQUEST_QUEUED_ENABLED)
                        if (DCM_PENDING_REQUEST_RECEIVE
                            != Dcm_QueuedRequestCtrl[Dcm_QueuedIndex].Dcm_PendingRequestState)
#endif /* STD_ON == DCM_REQUEST_QUEUED_ENABLED */
                    {
                        /*, lock buffer*/
                        SchM_Enter_Dcm(Dcm_ChannelCtrl);
                        Dcm_ChannelCtrl[RxChannelCfgCtrlId].Dcm_ChannelRxState = DCM_CH_OCCUPIED;
                        SchM_Exit_Dcm(Dcm_ChannelCtrl);
                        SchM_Enter_Dcm(Dcm_Channel);
                        Dcm_MemoryCopy(info->SduDataPtr, &Dcm_Channel[Offset], info->SduLength);
                        SchM_Exit_Dcm(Dcm_Channel);
                        Offset = Offset + (uint32)info->SduLength;
                        bufRet = BUFREQ_OK;
                    }
#if (STD_ON == DCM_REQUEST_QUEUED_ENABLED)
                    else
                    {
                        Dcm_MemoryCopy(info->SduDataPtr, Dcm_RequestQueuedBuffer, info->SduLength);
                        Dcm_QueuedRequestCtrl[Dcm_QueuedIndex].Dcm_QueuedRequestBufferCunrentPosition +=
                            info->SduLength;
                        bufRet = BUFREQ_OK;
                    }
#endif /* STD_ON == DCM_REQUEST_QUEUED_ENABLED */
                }
#if (STD_ON == DCM_REQUEST_QUEUED_ENABLED)
                if ((DCM_PENDING_REQUEST_NONE == Dcm_QueuedRequestCtrl[0u].Dcm_PendingRequestState)
                    && (DCM_PENDING_REQUEST_NONE == Dcm_QueuedRequestCtrl[1u].Dcm_PendingRequestState))
                {
#endif /* STD_ON == DCM_REQUEST_QUEUED_ENABLED */
                    SchM_Enter_Dcm(Dcm_MkCtrl);
                    Dcm_MkCtrl.Dcm_ActiveNetwork = Dsl_Protocol_ConnectionCfg[ConnectionCfgCtrlId]
                                                       .pDcmDslMainConnection->DcmDslProtocolComMChannelId;
                    SchM_Exit_Dcm(Dcm_MkCtrl);
                    if (DCM_PHYSICAL == RxAddrType)
                    {
                        SchM_Enter_Dcm(Dcm_MsgCtrl);
                        Dcm_MsgCtrl[MsgCtrlIndex].MsgContext.ReqDataLen = TpSduLength;
                        Dcm_MsgCtrl[MsgCtrlIndex].MsgContext.pReqData =
                            &Dcm_Channel[(Dcm_DslCfg.pDcmChannelCfg)[RxChannelCfgCtrlId].offset];
                        SchM_Exit_Dcm(Dcm_MsgCtrl);
                        SchM_Enter_Dcm(Dcm_ChannelCtrl);
                        Dcm_ChannelCtrl[RxChannelCfgCtrlId].Dcm_BufferCunrentPosition = Offset;
                        SchM_Exit_Dcm(Dcm_ChannelCtrl);
                    }
                    SchM_Enter_Dcm(Dcm_ConnectionCtrl);
                    Dcm_ConnectionCtrl[ConnectionCfgCtrlId].Dcm_ConnectionActive = TRUE;
                    SchM_Exit_Dcm(Dcm_ConnectionCtrl);
#if (STD_ON == DCM_REQUEST_QUEUED_ENABLED)
                }
                else if (DCM_PHYSICAL == RxAddrType)
                {
                    Dcm_QueuedRequestCtrl[Dcm_QueuedIndex].Dcm_QueuedRequestLength = TpSduLength;
                    Dcm_QueuedRequestCtrl[Dcm_QueuedIndex].Dcm_QueuedRequestRxPduId = id;
                }
                else
                {
                    /* idle */
                }
#endif /* STD_ON == DCM_REQUEST_QUEUED_ENABLED */
            }
#if (STD_ON == DCM_UDS_SERVICE0X86_ENABLED)
        }
#endif
    } /*ENDOF DET*/
    return bufRet;
}
#define DCM_STOP_SEC_DCMSTARTOFRECEPTION_CALLBACK_CODE
#include "Dcm_MemMap.h"
/*************************************************************************/
/*
 * Brief               <This function is called to provide the received data
 *                      of an I-PDU segment (N-PDU) to the upper layer.Each
 *                      call to this function provides the next part of the
 *                      I-PDU data.The size of the remaining data is written
 *                      to the position indicated by bufferSizePtr>
 * ServiceId           <0x44>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <DcmRxPduId:  the received data PduId;
 * Param-Name[out]     <PduInfoPtr:  Pointer to pointer to PduInfoType
 * containing data pointer and length of a receive buffe>
 * Param-Name[in/out]  <None>
 * Return              <BUFREQ_OK:
 *                      BUFREQ_E_NOT_OK:
 *                      BUFREQ_E_OVFL:
 *                      BUFREQ_E_BUSY:>
 * PreCondition        <None>
 * CallByAPI           <>
 */
/*************************************************************************/
#define DCM_START_SEC_DCMCOPYRXDATA_CALLBACK_CODE
#include "Dcm_MemMap.h"
FUNC(BufReq_ReturnType, DCM_CODE)
Dcm_CopyRxData(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, DCM_VAR) info,
    P2VAR(PduLengthType, AUTOMATIC, DCM_VAR) bufferSizePtr) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    uint8 Sid = 0;
    uint8 SubFunction;
    uint8 ConnectionCfgId;
    uint8 ProtocolCfgId;
    uint8 RxChannelCfgCtrlId;
    uint32 Offset;
    uint32 AvailableBufferSize;
    Dcm_DslProtocolRxAddrType RxAddrType;
    Dcm_ProtocolType ProtocolRowID;
    Dcm_ServiceType ServiceType;
    BufReq_ReturnType bufRet = BUFREQ_E_NOT_OK;

#if (STD_ON == DCM_DEV_ERROR_DETECT)
    /*The DCM module status check*/
    if (DCM_ON != (Dcm_MkCtrl.Dcm_MkState))
    {
        DCM_DET_REPORTERROR(DCM_COPYRXDATA_ID, DCM_E_UNINIT);
    }
    else if ((NULL_PTR == info) || (NULL_PTR == bufferSizePtr))
    {
        /*Parameter validation*/
        DCM_DET_REPORTERROR(DCM_COPYRXDATA_ID, DCM_E_PARAM_POINTER);
    }
    else if (id >= DCM_DSL_RX_ID_NUM)
    {
        /*Parameter validation*/
        DCM_DET_REPORTERROR(DCM_COPYRXDATA_ID, DCM_E_PARAM);
    }
    else
#endif
    {
        ConnectionCfgId = Dsl_Protocol_Connection_RxCfg[id].DcmDslParentConnectionCtrlId;
        ProtocolCfgId = Dsl_Protocol_ConnectionCfg[ConnectionCfgId].DcmDslParentProtocolRowCtrlId;
        RxChannelCfgCtrlId = Dsl_ProtocolRowCfg[ProtocolCfgId].DcmDslProtocolRxBufferRef->Dcm_DslBufferId;
        RxAddrType = Dsl_Protocol_Connection_RxCfg[id].DcmDslProtocolRxAddrType;
        ProtocolRowID = ((Dcm_DslCfg.pDcmDslProtocol)->pDcmDslProtocolRow)[ProtocolCfgId].DcmDslProtocolID;
        ServiceType = Dcm_ClassifyServiceType(ProtocolRowID);

        if (DCM_FUNCTIONAL == RxAddrType)
        {
            switch (ServiceType)
            {
            case DCM_UDS:
                /*The UDS protocol functions addressing message, bypass treatment*/
                Dcm_MemoryCopy(
                    info->SduDataPtr,
                    &(Dcm_FunctionalMessage.Buffer[Dcm_FunctionalMessage.Length]),
                    info->SduLength);
                Dcm_FunctionalMessage.Length += info->SduLength; /*save request length*/
                Sid = Dcm_FunctionalMessage.Buffer[0];
                SubFunction = Dcm_FunctionalMessage.Buffer[1];
                break;
            case DCM_OBD:
                /*The OBD protocol only have functions addressing message*/
                Dcm_MemoryCopy(info->SduDataPtr, &(Dcm_OBDMessage.Buffer[Dcm_OBDMessage.Length]), info->SduLength);
                Dcm_OBDMessage.Length += info->SduLength; /*save request length*/
                break;
            default:
                /*idle*/
                break;
            }
            bufRet = BUFREQ_OK;
        }
        else
        {
            Offset = Dcm_ChannelCtrl[RxChannelCfgCtrlId].Dcm_BufferCunrentPosition;
            AvailableBufferSize = Dcm_DslCfg.pDcmChannelCfg[RxChannelCfgCtrlId].Dcm_DslBufferSize
                                  - (Offset - (Dcm_DslCfg.pDcmChannelCfg)[RxChannelCfgCtrlId].offset);
            if (0u == info->SduLength)
            {
                *bufferSizePtr = (PduLengthType)AvailableBufferSize;
                bufRet = BUFREQ_OK;
            }
            else if ((uint32)info->SduLength > AvailableBufferSize)
            {
                bufRet = BUFREQ_E_NOT_OK;
            }
            else
#if (STD_ON == DCM_REQUEST_QUEUED_ENABLED)
                if (DCM_PENDING_REQUEST_RECEIVE != Dcm_QueuedRequestCtrl[Dcm_QueuedIndex].Dcm_PendingRequestState)
#endif /* STD_ON == DCM_REQUEST_QUEUED_ENABLED */
            {
                /* lock buffer*/
                SchM_Enter_Dcm(Dcm_ChannelCtrl);
                Dcm_ChannelCtrl[RxChannelCfgCtrlId].Dcm_ChannelRxState = DCM_CH_OCCUPIED;
                SchM_Exit_Dcm(Dcm_ChannelCtrl);
                SchM_Enter_Dcm(Dcm_Channel);
                Dcm_MemoryCopy(info->SduDataPtr, &Dcm_Channel[Offset], info->SduLength);
                SchM_Exit_Dcm(Dcm_Channel);
                Offset = Offset + (uint32)info->SduLength;
                SchM_Enter_Dcm(Dcm_ChannelCtrl);
                Dcm_ChannelCtrl[RxChannelCfgCtrlId].Dcm_BufferCunrentPosition = Offset;
                SchM_Exit_Dcm(Dcm_ChannelCtrl);
                *bufferSizePtr = (PduLengthType)(Dcm_DslCfg.pDcmChannelCfg[RxChannelCfgCtrlId].Dcm_DslBufferSize
                                                 - (Offset - (Dcm_DslCfg.pDcmChannelCfg)[RxChannelCfgCtrlId].offset));
                bufRet = BUFREQ_OK;
            }
#if (STD_ON == DCM_REQUEST_QUEUED_ENABLED)
            else
            {
                Offset = Dcm_QueuedRequestCtrl[Dcm_QueuedIndex].Dcm_QueuedRequestBufferCunrentPosition;
                Dcm_MemoryCopy(info->SduDataPtr, &(Dcm_RequestQueuedBuffer[Dcm_QueuedIndex][Offset]), info->SduLength);
                Dcm_QueuedRequestCtrl[Dcm_QueuedIndex].Dcm_QueuedRequestBufferCunrentPosition += info->SduLength;
                *bufferSizePtr =
                    (PduLengthType)(Dcm_DslCfg.pDcmChannelCfg[RxChannelCfgCtrlId].Dcm_DslBufferSize
                                    - Dcm_QueuedRequestCtrl[Dcm_QueuedIndex].Dcm_QueuedRequestBufferCunrentPosition);
                bufRet = BUFREQ_OK;
            }
#endif /* STD_ON == DCM_REQUEST_QUEUED_ENABLED */
        }
    }
    return bufRet;
}
#define DCM_STOP_SEC_DCMCOPYRXDATA_CALLBACK_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dcm_TpRxIndication_IsFuncAddress(PduIdType DcmRxPduId)
{
#if (STD_ON == DCM_UDS_FUNC_ENABLED)
    uint8 Sid;
    uint16 Index;
    uint8 SubFunction;
#endif
#if (STD_ON == DCM_SESSION_FUNC_ENABLED)
    boolean Flag;
#endif
    uint32 Offset;
    uint8 ProtocolCfgId;
    uint8 ConnectionCfgId;
    uint8 MsgCtrlIndex;
    uint8 RxChannelCfgCtrlId;
    Dcm_DslProtocolRxAddrType DslProtocolRxAddrType;
    Std_ReturnType ret = E_OK;

    ConnectionCfgId = Dsl_Protocol_Connection_RxCfg[DcmRxPduId].DcmDslParentConnectionCtrlId;
    ProtocolCfgId = Dsl_Protocol_ConnectionCfg[ConnectionCfgId].DcmDslParentProtocolRowCtrlId;
    MsgCtrlIndex = ProtocolCfgId;
    RxChannelCfgCtrlId = Dsl_ProtocolRowCfg[ProtocolCfgId].DcmDslProtocolRxBufferRef->Dcm_DslBufferId;
    DslProtocolRxAddrType = Dsl_Protocol_Connection_RxCfg[DcmRxPduId].DcmDslProtocolRxAddrType;
    Offset = (Dcm_DslCfg.pDcmChannelCfg)[RxChannelCfgCtrlId].offset;
    Sid = Dcm_FunctionalMessage.Buffer[0];

    if ((0x3Eu == Sid) && DCM_FUNCTIONAL == DslProtocolRxAddrType)
    {
        CCU_DiagTesterOnlineFlag = STD_ON;
        CCU_DiagTesterOnlineTimer = Frt_ReadOutMS();
        Com_SendSignal(CCU_VehInfo_BAC_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1_CCU_DiagTesterOnline_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1,&CCU_DiagTesterOnlineFlag);
        Com_SendSignal(CCU_VehInfo_BOD_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD4_BOD_CAN4_CCU_DiagTesterOnline_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD4_BOD_CAN4,&CCU_DiagTesterOnlineFlag);
        Com_SendSignal(CCU_VehInfo_EPT_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2_CCU_DiagTesterOnline_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2,&CCU_DiagTesterOnlineFlag);
        Com_SendSignal(CCU_VehInfo_CHA_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5_CCU_DiagTesterOnline_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5,&CCU_DiagTesterOnlineFlag);
    }
    if (DCM_FUNCTIONAL == DslProtocolRxAddrType)
    {
        SubFunction = Dcm_FunctionalMessage.Buffer[1];
        if ((0x3Eu == Sid) && (0x80u == SubFunction) && (0x02u == Dcm_FunctionalMessage.Length))
        {
            /*This is TesterPresent Request */
#if (STD_ON == DCM_SESSION_FUNC_ENABLED)
            if (DCM_DEFAULT_SESSION != Dcm_MkCtrl.Dcm_ActiveSes)
            {
                Flag = FALSE;
                for (Index = 0; (Index < DCM_MSG_NUM) && (FALSE == Flag); Index++)
                {
                    if (DCM_MSG_WAIT != Dcm_MsgCtrl[Index].Dcm_MsgState)
                    {
                        Flag = TRUE;
                    }
                }
                if (FALSE == Flag)
                {
                    /*restart S3timer*/
                    DslInternal_S3ServerStart();
                }
            }
#endif
            /*shall clear function buffer*/
            Dcm_FunctionalMessage.Length = 0;
            ret = E_NOT_OK;
        }
        /*(SID=0x3E + subfunction(0x00))||(SID != 0x3E),Need to be submitted to Dsd layer handle*/
        if (E_OK == ret)
        {
            if ((DCM_MSG_WAIT != Dcm_MsgCtrl[MsgCtrlIndex].Dcm_MsgState)
#if (STD_ON == DCM_REQUEST_QUEUED_ENABLED)
                || (DCM_PENDING_REQUEST_NONE != Dcm_QueuedRequestCtrl[0u].Dcm_PendingRequestState)
                || (DCM_PENDING_REQUEST_NONE != Dcm_QueuedRequestCtrl[1u].Dcm_PendingRequestState)
#endif
            )
            {
                /*The same protocol message being processed*/
                ret = E_NOT_OK;
                Dcm_FunctionalMessage.Length = 0;
            }
            else
            {
                /*The main channel is idle,copy data to main channel*/
                for (Index = 0u; Index < Dcm_FunctionalMessage.Length; Index++)
                {
                    SchM_Enter_Dcm(Dcm_Channel);
                    Dcm_Channel[Offset + Index] = Dcm_FunctionalMessage.Buffer[Index];
                    SchM_Exit_Dcm(Dcm_Channel);
                }
                SchM_Enter_Dcm(Dcm_MsgCtrl);
                Dcm_MsgCtrl[MsgCtrlIndex].MsgContext.ReqDataLen = (Dcm_MsgLenType)Dcm_FunctionalMessage.Length;
                Dcm_FunctionalMessage.Length = 0;
                Dcm_MsgCtrl[MsgCtrlIndex].MsgContext.pReqData = &Dcm_Channel[Offset];
#if (STD_ON == DCM_GENERIC_CONNECTION)
                Dcm_MsgCtrl[ProtocolCfgId].Dcm_MetaData_AE = Dcm_MsgCtrl[ProtocolCfgId].Dcm_MetaData_AE_Backup;
                Dcm_MsgCtrl[ProtocolCfgId].Dcm_MetaData_SA = Dcm_MsgCtrl[ProtocolCfgId].Dcm_MetaData_SA_Backup;
                Dcm_MsgCtrl[ProtocolCfgId].Dcm_MetaData_TA = Dcm_MsgCtrl[ProtocolCfgId].Dcm_MetaData_TA_Backup;
                Dcm_MsgCtrl[ProtocolCfgId].Dcm_MetaData_AE_Backup = DCM_INVALID_UINT8;
                Dcm_MsgCtrl[ProtocolCfgId].Dcm_MetaData_SA_Backup = DCM_INVALID_UINT16;
                Dcm_MsgCtrl[ProtocolCfgId].Dcm_MetaData_TA_Backup = DCM_INVALID_UINT16;
#endif
                SchM_Exit_Dcm(Dcm_MsgCtrl);
            }
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(void, DCM_CODE) Dcm_TpRxIndication_SubDeal(uint8 ProtocolCfgCtrlId, Dcm_ServiceType ServiceType)
{
    Std_ReturnType ret;
    /*check Protocol*/
    SchM_Enter_Dcm(Dcm_ProtocolCtrl);
    if (E_OK != Dcm_CheckProtocol(ProtocolCfgCtrlId, ServiceType))
    {
        SchM_Exit_Dcm(Dcm_ProtocolCtrl);
        if (TRUE == StopProtocolFaild)
        {
            StopProtocolFaild = FALSE;
            DsdInternal_SetNrc(ProtocolCfgCtrlId, DCM_E_CONDITIONSNOTCORRECT);
            DsdInternal_ProcessingDone(ProtocolCfgCtrlId);
        }
        else if (Dcm_DslCfg.pDcmDslDiagRespCfg->DcmDslDiagRespOnSecondDeclinedRequest == TRUE)
        {
            SchM_Enter_Dcm(Dcm_MsgCtrl);
            Dcm_MsgCtrl[ProtocolCfgCtrlId].NRC = DCM_E_BUSYREPEATREQUEST;
            Dcm_MsgCtrl[ProtocolCfgCtrlId].RspStyle = DCM_NEG_RSP;
            SchM_Exit_Dcm(Dcm_MsgCtrl);
            DsdInternal_ProcessingDone(ProtocolCfgCtrlId);
        }
        else
        {
            /* do nothing */
        }
    }
    else
    {
        /*Notice the application to check for new protocol boot environment*/
        ret = DslInternal_ProtocolStart(ProtocolCfgCtrlId);
        SchM_Exit_Dcm(Dcm_ProtocolCtrl);
        if (E_OK != ret)
        {
            DsdInternal_SetNrc(ProtocolCfgCtrlId, DCM_E_CONDITIONSNOTCORRECT);
            DsdInternal_ProcessingDone(ProtocolCfgCtrlId);
        }
        else
        {
            /*Start P2Timer Timer*/
            DslInternal_P2ServerStart(ProtocolCfgCtrlId);
            if (DCM_E_BUSYREPEATREQUEST == Dcm_MsgCtrl[ProtocolCfgCtrlId].NRC)
            {
                DsdInternal_ProcessingDone(ProtocolCfgCtrlId);
            }
            else
            {
                /* save valid Protocol ID number*/
                SchM_Enter_Dcm(Dcm_MkCtrl);
                Dcm_MkCtrl.Dcm_ActiveProtocol = Dcm_ProtocolCtrl[ProtocolCfgCtrlId].ProtocolId;
                SchM_Exit_Dcm(Dcm_MkCtrl);
                /****Notification DSD layer, and reception processing****/
                (void)DsdInternal_RxIndication(ProtocolCfgCtrlId);
            }
        }
    }
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*************************************************************************/
/*
 * Brief               <Called after an I-PDU has been received via the
 *                      TP API, the result indicates whether the
 *                      transmission was successful or not.>
 * ServiceId           <0x45>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <DcmRxPduId:ID of DCM I-PDU that has been received
 *                      Result: The result of the diagnostic request message received>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <this function must be called after
 * call of Dcm_StartOfReception() and Dcm_CopyRxData()>
 * CallByAPI           <None>
 */
/*************************************************************************/
#define DCM_START_SEC_DCMTPRXINDICATION_CALLBACK_CODE
#include "Dcm_MemMap.h"
FUNC(void, DCM_CODE) Dcm_TpRxIndication(PduIdType id, Std_ReturnType result)
{
    P2CONST(Dcm_DslConnectionType, AUTOMATIC, DCM_CONST) pDslConnection;
    Dcm_ProtocolType ProtocolId;
    Dcm_ServiceType ServiceType;
    Dcm_ChannelStateType TxChannelTxState;
    uint8 ProtocolCfgCtrlId;
    uint8 ConnectionCfgId;
    uint8 MsgCtrlIndexx;
    uint8 RxChannelCfgCtrlId;
    uint8 TxChannelCfgCtrlId;
    Dcm_DslProtocolRxAddrType DslProtocolRxAddrType;
    Std_ReturnType ret = E_OK;
    uint8 Index;
    NetworkHandleType NetworkChannel;

    ConnectionCfgId = Dsl_Protocol_Connection_RxCfg[id].DcmDslParentConnectionCtrlId;
    ProtocolCfgCtrlId = Dsl_Protocol_ConnectionCfg[ConnectionCfgId].DcmDslParentProtocolRowCtrlId;
    MsgCtrlIndexx = ProtocolCfgCtrlId;
    RxChannelCfgCtrlId = Dsl_ProtocolRowCfg[ProtocolCfgCtrlId].DcmDslProtocolRxBufferRef->Dcm_DslBufferId;

#if (STD_ON == DCM_SESSION_FUNC_ENABLED)
    boolean Flag = FALSE;
#endif

#if (STD_ON == DCM_DEV_ERROR_DETECT)
    /*To determine whether the DCM module initialization*/
    if (DCM_ON != (Dcm_MkCtrl.Dcm_MkState))
    {
        DCM_DET_REPORTERROR(DCM_TPRXINDICATION_ID, DCM_E_UNINIT);
    }
#endif
#if (STD_ON == DCM_REQUEST_QUEUED_ENABLED)
    else if (DCM_PENDING_REQUEST_RECEIVE != Dcm_QueuedRequestCtrl[Dcm_QueuedIndex].Dcm_PendingRequestState)
#else  /* STD_ON == DCM_REQUEST_QUEUED_ENABLED */
    else
#endif /* STD_ON == DCM_REQUEST_QUEUED_ENABLED */
    {
        /*To find DcmRxPduId corresponding protocol index number,
         *in the protocol configuration table */
        TxChannelCfgCtrlId = Dsl_ProtocolRowCfg[ProtocolCfgCtrlId].DcmDslProtocolTxBufferRef->Dcm_DslBufferId;
        /*Determine relationship between the message control
         * block and the corresponding protocol control block */
        SchM_Enter_Dcm(Dcm_ProtocolCtrl);
        Dcm_ProtocolCtrl[ProtocolCfgCtrlId].ProtocolId =
            (Dcm_DslCfg.pDcmDslProtocol->pDcmDslProtocolRow)[ProtocolCfgCtrlId].DcmDslProtocolID;
        Dcm_ProtocolCtrl[ProtocolCfgCtrlId].ProtocolPri =
            (Dcm_DslCfg.pDcmDslProtocol->pDcmDslProtocolRow)[ProtocolCfgCtrlId].DcmDslProtocolPriority;
        Dcm_ProtocolCtrl[ProtocolCfgCtrlId].ProtocolPreemptTime =
            (Dcm_DslCfg.pDcmDslProtocol->pDcmDslProtocolRow)[ProtocolCfgCtrlId].DcmDslProtocolPreemptTime;
        Dcm_ProtocolCtrl[ProtocolCfgCtrlId].MsgCtrlIndex = MsgCtrlIndexx;
        SchM_Exit_Dcm(Dcm_ProtocolCtrl);
        SchM_Enter_Dcm(Dcm_MsgCtrl);
        Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_RxCtrlChannelIndex = RxChannelCfgCtrlId;
        Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_TxCtrlChannelIndex = TxChannelCfgCtrlId;
        SchM_Exit_Dcm(Dcm_MsgCtrl);
        /**No MsgCtrlIndex ,ResetResource will not clear connect*/
        /*Receive complete results analysis*/
        if (result != E_OK)
        {
#if (STD_ON == DCM_SESSION_FUNC_ENABLED)
            /*session control function is enabled */
            if (DCM_DEFAULT_SESSION != Dcm_MkCtrl.Dcm_ActiveSes)
            {
                for (Index = 0; (Index < DCM_MSG_NUM) && (FALSE == Flag); Index++)
                {
                    if (DCM_MSG_WAIT != Dcm_MsgCtrl[Index].Dcm_MsgState)
                    {
                        Flag = TRUE;
                    }
                }
                if (FALSE == Flag)
                {
                    /*current session is non default session and have error.
                     * if other session state is not wait,should start S3server*/
                    /*Indicates an error during the reception of a multi-frame request message.*/
                    DslInternal_S3ServerStart();
                }
            }
#endif
            DslInternal_InitChannelCtrl(RxChannelCfgCtrlId);
        }
        else
        {
            /*functional request packet processing*/
            ProtocolId = Dsl_ProtocolRowCfg[ProtocolCfgCtrlId].DcmDslProtocolID;
            ServiceType = Dcm_ClassifyServiceType(ProtocolId);
            if (DCM_UDS == ServiceType)
            {
                /*check for UDS*/
                ret = Dcm_TpRxIndication_IsFuncAddress(id);
            }
            if (E_OK == ret)
            {
                pDslConnection = Dcm_DslCfg.pDcmDslProtocol->pDcmDslProtocolRow[ProtocolCfgCtrlId].pDcmDslConnection;
                DslProtocolRxAddrType = Dsl_Protocol_Connection_RxCfg[id].DcmDslProtocolRxAddrType;
                /* Determine relationship between the static configuration channel
                 * and receive/transmit channel control block */
                SchM_Enter_Dcm(Dcm_ChannelCtrl);
                Dcm_ChannelCtrl[TxChannelCfgCtrlId].Dcm_ChannelCfgIndex = TxChannelCfgCtrlId;
                Dcm_ChannelCtrl[RxChannelCfgCtrlId].Dcm_ChannelCfgIndex = RxChannelCfgCtrlId;
                SchM_Exit_Dcm(Dcm_ChannelCtrl);
                TxChannelTxState = Dcm_ChannelCtrl[TxChannelCfgCtrlId].Dcm_ChannelTxState;
                if (DCM_CH_OCCUPIED == TxChannelTxState)
                {
                    /*Corresponding transmit channel status is not normal*/
                    DslInternal_ResetResource(ProtocolCfgCtrlId);
                }
                else
                {
                    SchM_Enter_Dcm(Dcm_ChannelCtrl);
                    Dcm_ChannelCtrl[TxChannelCfgCtrlId].Dcm_ChannelTxState = DCM_CH_OCCUPIED;
                    SchM_Exit_Dcm(Dcm_ChannelCtrl);
                    if (Dcm_ChannelCtrl[RxChannelCfgCtrlId].Dcm_ChannelRxState != DCM_CH_OCCUPIED)
                    {
                        /*added for Fun Eth Request*/
                        SchM_Enter_Dcm(Dcm_ChannelCtrl);
                        Dcm_ChannelCtrl[RxChannelCfgCtrlId].Dcm_ChannelRxState = DCM_CH_OCCUPIED;
                        SchM_Exit_Dcm(Dcm_ChannelCtrl);
                    }
                    /*Determine relationships between the receive/transmit channel control
                     * block and the corresponding message control block */
                    if (ServiceType == DCM_OBD)
                    {
                        SchM_Enter_Dcm(Dcm_MsgCtrl);
                        Dcm_MsgCtrl[MsgCtrlIndexx].MsgContext.ReqDataLen = (Dcm_MsgLenType)Dcm_OBDMessage.Length;
                        Dcm_MsgCtrl[MsgCtrlIndexx].SID = Dcm_OBDMessage.Buffer[0];
                        Dcm_MsgCtrl[MsgCtrlIndexx].Subfunction = Dcm_OBDMessage.Buffer[1];
                        Dcm_MsgCtrl[MsgCtrlIndexx].MsgContext.pReqData = &Dcm_OBDMessage.Buffer[0];
                        SchM_Exit_Dcm(Dcm_MsgCtrl);
                    }
                    else
                    {
                        SchM_Enter_Dcm(Dcm_MsgCtrl);
                        Dcm_MsgCtrl[MsgCtrlIndexx].SID = Dcm_MsgCtrl[MsgCtrlIndexx].MsgContext.pReqData[0];
                        Dcm_MsgCtrl[MsgCtrlIndexx].Subfunction = (Dcm_MsgCtrl[MsgCtrlIndexx].MsgContext.pReqData)[1];
                        SchM_Exit_Dcm(Dcm_MsgCtrl);
                    }
                    SchM_Enter_Dcm(Dcm_MsgCtrl);
                    Dcm_MsgCtrl[MsgCtrlIndexx].MsgContext.MsgAddInfo.ReqType = (uint8)DslProtocolRxAddrType;
                    Dcm_MsgCtrl[MsgCtrlIndexx].MsgContext.DcmRxPduId = id;
                    Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_RxCtrlChannelIndex = RxChannelCfgCtrlId;
                    Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_TxCtrlChannelIndex = TxChannelCfgCtrlId;
                    if (NULL_PTR == pDslConnection->pDcmDslMainConnection->pDcmDslProtocolTx)
                    {
                        Dcm_MsgCtrl[MsgCtrlIndexx].DcmTxPduId = DCM_INVALID_UINT8;
                    }
                    else
                    {
#if (STD_ON == DCM_UDS_SERVICE0X86_ENABLED)
                        if (TRUE == Dcm_UDS0x86_GetTxPduId(&Dcm_MsgCtrl[MsgCtrlIndexx].DcmTxPduId))
#endif
                        {
                            Dcm_MsgCtrl[MsgCtrlIndexx].DcmTxPduId =
                                pDslConnection->pDcmDslMainConnection->pDcmDslProtocolTx->DcmDslTxPduRPduId;
                        }
#if (STD_ON == DCM_GENERIC_CONNECTION)
                        Dcm_MsgCtrl[MsgCtrlIndexx].DcmRxPduId = id;
#endif
                    }
                    Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_MsgState = DCM_MSG_RECEIVED;
                    SchM_Exit_Dcm(Dcm_MsgCtrl);
                    NetworkChannel = pDslConnection->pDcmDslMainConnection->DcmDslProtocolComMChannelId;
                    for (Index = 0; Index < DCM_MAINCONNECTION_NUM; Index++)
                    {
                        if (NetworkChannel == Dcm_CommCtrl[Index].DcmDslProtocolComMChannelId)
                        {
                            /*ComM interactive processing*/
                            if ((DCM_COMM_ACTIVE == Dcm_CommCtrl[Index].Dcm_ActiveDiagnostic)
                                && (DCM_DEFAULT_SESSION == Dcm_MkCtrl.Dcm_ActiveSes))
                            {
                                /*The notification ComM into the "FULL Communication"*/
                                ComM_DCM_ActiveDiagnostic(NetworkChannel);
                            }
                        }
                    }
                    Dcm_TpRxIndication_SubDeal(ProtocolCfgCtrlId, ServiceType);
                }
            }
        }
    }
#if (STD_ON == DCM_REQUEST_QUEUED_ENABLED)
    else if (E_OK == result)
    {
        Dcm_QueuedRequestCtrl[Dcm_QueuedIndex].Dcm_PendingRequestState = DCM_PENDING_REQUEST_READY;
    }
    else
    {
        Dcm_QueuedRequestCtrl[Dcm_QueuedIndex].Dcm_PendingRequestState = DCM_PENDING_REQUEST_NONE;
        Dcm_QueuedRequestCtrl[Dcm_QueuedIndex].Dcm_QueuedRequestBufferCunrentPosition = 0u;
    }
#endif /* STD_ON == DCM_REQUEST_QUEUED_ENABLED */
}
#define DCM_STOP_SEC_DCMTPRXINDICATION_CALLBACK_CODE
#include "Dcm_MemMap.h"

/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dcm_CopyTxData_CheckCtrlStatus(PduIdType DcmTxPduId)
{
    uint8 ProtocolCfgId;
    uint8 ConnectionCfgId;
    uint8 MsgCtrlId;
    uint8 RxChannelCtrlId;
    uint8 TxChannelCtrlId;
    Std_ReturnType ret = E_OK;

    /*To find DcmTxPduId corresponding Protocol index number,
     *in the protocol configuration table*/
    ConnectionCfgId = Dsl_Protocol_Connection_TxCfg[DcmTxPduId].DcmDslParentConnectionCtrlId;
    ProtocolCfgId = Dsl_Protocol_ConnectionCfg[ConnectionCfgId].DcmDslParentProtocolRowCtrlId;
    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCfgId].MsgCtrlIndex;

    if (DCM_INVALID_UINT8 == MsgCtrlId)
    {
        ret = E_NOT_OK;
    }
    else
    {
        RxChannelCtrlId = Dcm_MsgCtrl[MsgCtrlId].Dcm_RxCtrlChannelIndex;
        TxChannelCtrlId = Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex;
    }
    if ((E_OK == ret) && (DCM_MSG_TRANSMISSION != Dcm_MsgCtrl[MsgCtrlId].Dcm_MsgState)
#if (STD_ON == DCM_PAGEDBUFFER_ENABLED)
        && (Dcm_PageBufferData.TotalSize == 0UL)
#endif
    )
    {
        /*The state machine does not operate properly, return BUFREQ_E_NOT_OK*/
        ret = E_NOT_OK;
    }

    if ((E_OK == ret) && (DCM_CH_OCCUPIED != Dcm_ChannelCtrl[RxChannelCtrlId].Dcm_ChannelRxState))
    {
        /*Receiver channel status is not correct*/
        ret = E_NOT_OK;
    }
    if ((E_OK == ret) && (DCM_CH_OCCUPIED != Dcm_ChannelCtrl[TxChannelCtrlId].Dcm_ChannelTxState))
    {
        /*The send channel status is incorrect*/
        ret = E_NOT_OK;
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*************************************************************************/

#if (STD_ON == DCM_PAGEDBUFFER_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(BufReq_ReturnType, DCM_CODE) Dcm_CopyTxData_PagebufferDeal(
    uint8 ProtocolCfgId,
    P2CONST(PduInfoType, AUTOMATIC, DCM_VAR) info,
    uint8 TxChannelCtrlIndex,
    P2VAR(PduLengthType, AUTOMATIC, DCM_VAR) availableDataPtr) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    BufReq_ReturnType bufRet;
    /*check the pagebuffer timer whether timeout*/
    if (Dcm_PageBufferData.TimeOut == TRUE)
    {
        DslInternal_InitPageBuffer();
        DslInternal_ResetResource(ProtocolCfgId);
        bufRet = BUFREQ_E_NOT_OK;
    }
    else
    {
        if (Dcm_PageBufferData.Filled == FALSE)
        {
            bufRet = BUFREQ_E_BUSY;
        }
        else
        {
            if ((Dcm_PageBufferData.ThisPageTxSize + info->SduLength) > Dcm_PageBufferData.ThisPageSize)
            {
                /*last one message not has 8 byte, memory it for next page to send*/
                if ((Dcm_PageBufferData.ThisPageSize - Dcm_PageBufferData.ThisPageTxSize) != 0u)
                {
                    SchM_Enter_Dcm(Dcm_PageBufferData);
                    Dcm_PageBufferData.LastNotTxDataSize =
                        Dcm_PageBufferData.ThisPageSize - Dcm_PageBufferData.ThisPageTxSize;
                    Dcm_MemoryCopy(
                        &(Dcm_PageBufferData.pResData[Dcm_PageBufferData.ThisPageTxSize]),
                        Dcm_PageBufferData.LastNotTxData,
                        Dcm_PageBufferData.LastNotTxDataSize);
                    SchM_Exit_Dcm(Dcm_PageBufferData);
                }
                /*busy should call the api to fill the page*/
                DspInternal_DcmUpdatePage(ProtocolCfgId);
                bufRet = BUFREQ_E_BUSY;
            }
            else
            {
                if (info->SduLength != 0u)
                {
                    SchM_Enter_Dcm(Dcm_PageBufferData);
                    /*Store the response data to the corresponding transmit channel*/
                    Dcm_PageBufferData.pResData = &(
                        Dcm_Channel[(Dcm_DslCfg.pDcmChannelCfg)[Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex]
                                        .offset]);

                    if (Dcm_PageBufferData.LastNotTxDataSize != 0u)
                    {
                        /*last one message not has 8 byte,
                         * to send it with next page data filled 8 byte*/
                        Dcm_MemoryCopy(
                            Dcm_PageBufferData.LastNotTxData,
                            info->SduDataPtr,
                            Dcm_PageBufferData.LastNotTxDataSize);
                        Dcm_MemoryCopy(
                            &(Dcm_PageBufferData.pResData[Dcm_PageBufferData.ThisPageTxSize]),
                            &(info->SduDataPtr[Dcm_PageBufferData.LastNotTxDataSize]),
                            (info->SduLength - Dcm_PageBufferData.LastNotTxDataSize));
                        Dcm_PageBufferData.ThisPageTxSize += (info->SduLength - Dcm_PageBufferData.LastNotTxDataSize);
                        Dcm_PageBufferData.LastNotTxDataSize = 0u;
                    }
                    else
                    {
                        Dcm_MemoryCopy(
                            &(Dcm_PageBufferData.pResData[Dcm_PageBufferData.ThisPageTxSize]),
                            info->SduDataPtr,
                            info->SduLength);
                        Dcm_PageBufferData.ThisPageTxSize += info->SduLength;
                    }
                    Dcm_PageBufferData.AlreadyPageSize += info->SduLength;
                    SchM_Exit_Dcm(Dcm_PageBufferData);
                }
                *availableDataPtr = (PduLengthType)(Dcm_PageBufferData.TotalSize - Dcm_PageBufferData.AlreadyPageSize);
                bufRet = BUFREQ_OK;
            }
        }
    }
    return bufRet;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif
/*************************************************************************/
/*
 * Brief               <This function is called to provide the received data
 *                      of an I-PDU segment (N-PDU) to the upper layer.Each
 *                      call to this function provides the next part of the
 *                      I-PDU data.The size of the remaining data is written
 *                      to the position indicated by bufferSizePtr>
 * ServiceId           <0x43>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <DcmRxPduId:  the received data PduId;
 * Param-Name[out]     <PduInfoPtr:  Pointer to pointer to PduInfoType
 * containing data pointer and length of a receive buffe>
 *                     <retry:This parameter is used to acknowledge transmitted
 *                      data or to retransmit data after transmission problems.>
 * Param-Name[in/out]  <None>
 * Return              <BUFREQ_OK:
 *                      BUFREQ_E_NOT_OK:
 *                      BUFREQ_E_OVFL:
 *                      BUFREQ_E_BUSY:>
 * PreCondition        <None>
 * CallByAPI           <>
 */
/*************************************************************************/
#define DCM_START_SEC_DCMCOPYTXDATA_CALLBACK_CODE
#include "Dcm_MemMap.h"
FUNC(BufReq_ReturnType, DCM_CODE)
Dcm_CopyTxData(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, DCM_VAR) info,
    P2CONST(RetryInfoType, AUTOMATIC, DCM_VAR) retry,
    P2VAR(PduLengthType, AUTOMATIC, DCM_VAR) availableDataPtr) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    uint8 ProtocolCfgId;
    uint8 ConnectionCfgId;
    uint8 MsgCtrlId;
    uint8 TxChannelCtrlIndex;
    uint32 Position;
    uint32 Len;
    Std_ReturnType ret;
    BufReq_ReturnType bufRet = BUFREQ_E_NOT_OK;

#if (STD_ON == DCM_DEV_ERROR_DETECT)
    /*The DCM module status check*/
    if (DCM_ON != Dcm_MkCtrl.Dcm_MkState)
    {
        DCM_DET_REPORTERROR(DCM_COPYTXDATA_ID, DCM_E_UNINIT);
    }
    /*Parameter validation*/
    else if ((NULL_PTR == info) || (NULL_PTR == availableDataPtr))
    {
        DCM_DET_REPORTERROR(DCM_COPYTXDATA_ID, DCM_E_PARAM_POINTER);
    }
    /*Parameter validation*/
    else if (id >= DCM_DSL_TX_ID_NUM)
    {
        DCM_DET_REPORTERROR(DCM_COPYTXDATA_ID, DCM_E_PARAM);
    }
    else
#endif
    {
        ret = Dcm_CopyTxData_CheckCtrlStatus(id);
        if (E_NOT_OK == ret)
        {
            bufRet = BUFREQ_E_NOT_OK;
        }
        else
        {
            ConnectionCfgId = Dsl_Protocol_Connection_TxCfg[id].DcmDslParentConnectionCtrlId;
            ProtocolCfgId = Dsl_Protocol_ConnectionCfg[ConnectionCfgId].DcmDslParentProtocolRowCtrlId;
            MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCfgId].MsgCtrlIndex;
            TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex;
            Position = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_BufferCunrentPosition;
            Len = Position + (uint32)info->SduLength;
#if (STD_ON == DCM_PAGEDBUFFER_ENABLED)
            if (Dcm_PageBufferData.TotalSize != 0UL)
            {
                bufRet = Dcm_CopyTxData_PagebufferDeal(ProtocolCfgId, info, TxChannelCtrlIndex, availableDataPtr);
            }
            else
#endif
            {
                /*ResDataLen is total length*/
                if (Len > Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResDataLen)
                {
                    bufRet = BUFREQ_E_BUSY;
                }
                else
                {
                    if ((NULL_PTR == retry) || (TP_DATACONF == retry->TpDataState))
                    {
                        SchM_Enter_Dcm(Dcm_ChannelCtrl);
                        Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_BufferErasePosition =
                            Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_BufferCunrentPosition;
                        SchM_Exit_Dcm(Dcm_ChannelCtrl);
                    }
                    else if (TP_DATARETRY == retry->TpDataState)
                    {
                        SchM_Enter_Dcm(Dcm_ChannelCtrl);
                        Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_BufferCunrentPosition =
                            Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_BufferCunrentPosition - (uint32)retry->TxTpDataCnt;
                        SchM_Exit_Dcm(Dcm_ChannelCtrl);
                    }
                    else
                    {
                        /*TP_CONFPENDING,do nothing*/
                    }

                    if (info->SduLength != 0u)
                    {
                        Dcm_MemoryCopy(
                            &(Dcm_MsgCtrl[MsgCtrlId].MsgContext.pResData[Position]),
                            info->SduDataPtr,
                            info->SduLength);
                        SchM_Enter_Dcm(Dcm_ChannelCtrl);
                        Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_BufferCunrentPosition =
                            Position + (uint32)info->SduLength;
                        SchM_Exit_Dcm(Dcm_ChannelCtrl);
                    }

                    *availableDataPtr =
                        (PduLengthType)(Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResMaxDataLen
                                        - Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_BufferCunrentPosition);
                    bufRet = BUFREQ_OK;
                }
            }
        }
    }
    return bufRet;
}
#define DCM_STOP_SEC_DCMCOPYTXDATA_CALLBACK_CODE
#include "Dcm_MemMap.h"

/*************************************************************************/
/*
 * Brief               <This is called by the PduR to confirm a Transmit>
 * ServiceId           <0x48>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <DcmTxPduId:ID of DCM I-PDU that has been transmitted.
 *                      Result: NTFRSLT_OK: the complete N-PDU has been transmitted.
 *                              NTFRSLT_E_CANCELATION_OK: the N-PDU has been successfully
 *                              cancelled.
 *                              NTFRSLT_E_CANCELATION_NOT_OK: an error occurred when
 *                              cancelling the N-PDU.
 *                              any other value: an error occurred during transmission>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <this function must be called after call of DcmProvideTxBuffer().>
 * CallByAPI           <>
 */
/*************************************************************************/
#define DCM_START_SEC_DCMTPTXCONFIRMATION_CALLBACK_CODE
#include "Dcm_MemMap.h"
FUNC(void, DCM_CODE) Dcm_TpTxConfirmation(PduIdType id, Std_ReturnType result)
{
    uint8 ProtocolCfgCtrlId;
    uint8 ConnectionCfgId;
    uint8 MsgCtrlIndex;

#if (STD_ON == DCM_DEV_ERROR_DETECT)
    /*The DCM module status check*/
    if (DCM_ON != (Dcm_MkCtrl.Dcm_MkState))
    {
        DCM_DET_REPORTERROR(DCM_TXCONFIRMATION_ID, DCM_E_UNINIT);
    }
    else
#endif
    {
        /*find DcmTxPduId corresponding protocol index number,
         * in the protocol configuration table*/
        ConnectionCfgId = Dsl_Protocol_Connection_TxCfg[id].DcmDslParentConnectionCtrlId;
        ProtocolCfgCtrlId = Dsl_Protocol_ConnectionCfg[ConnectionCfgId].DcmDslParentProtocolRowCtrlId;
        MsgCtrlIndex = ProtocolCfgCtrlId;
        switch (result)
        {
        case E_NOT_OK:
            /*Confirmation message shows: response failed to send*/
            DslInternal_ResetResource(ProtocolCfgCtrlId);
            break;
        case E_OK:
#if (STD_ON == DCM_UDS_SERVICE0X86_ENABLED)
            if (TRUE == Dcm_UDS0x86_TxConfirmation(ProtocolCfgCtrlId))
#endif
            {
                /*Confirmation message shows: the response
                 * is sent to notify the DSD layer further confirmation*/
                /*Set corresponding to the message status = "DCM_MSG_CONFIRMATION*/
                SchM_Enter_Dcm(Dcm_MsgCtrl);
                Dcm_MsgCtrl[MsgCtrlIndex].Dcm_MsgState = DCM_MSG_CONFIRMATION;
#if (STD_ON == DCM_DSLDIAGRESP_FORCERESPENDEN)
                if (DCM_E_FORCE_RCRRP == Dcm_MsgCtrl[MsgCtrlIndex].Dcm_Ret)
                {
                    Dcm_MsgCtrl[MsgCtrlIndex].Dcm_OpStatus = DCM_FORCE_RCRRP_OK;
                }
#endif
                SchM_Exit_Dcm(Dcm_MsgCtrl);
                DsdInternal_TxConfirmation(ProtocolCfgCtrlId);
            }
            break;
        default:
            DslInternal_ResetResource(ProtocolCfgCtrlId);
            break;
        }
    }
}
#define DCM_STOP_SEC_DCMTPTXCONFIRMATION_CALLBACK_CODE
#include "Dcm_MemMap.h"
/*************************************************************************/
/*
 * Brief               <The lower layer communication interface module
 *                       confirms the transmission of an IPDU.>
 * ServiceId           <0x40>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <DcmTxPduId:ID of DCM I-PDU that has been transmitted.
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <>
 * CallByAPI           <>
 */
/*************************************************************************/
#define DCM_START_SEC_DCMTXCONFIRMATION_CALLBACK_CODE
#include "Dcm_MemMap.h"
FUNC(void, DCM_CODE) Dcm_TxConfirmation(PduIdType DcmTxPduId)
{
#if (STD_ON == DCM_DEV_ERROR_DETECT)
    /*The DCM module status check*/
    if (DCM_ON != (Dcm_MkCtrl.Dcm_MkState))
    {
        DCM_DET_REPORTERROR(DCM_TXCONFIRMATION_ID, DCM_E_UNINIT);
    }
    else
#endif
    {
#if (STD_ON == DCM_UDS_SERVICE0X2A_ENABLED)
        uint8 index;

        for (index = 0; index < DCM_PERIODICCONNECTION_NUM; index++)
        {
            if (Scheduler_0x2A_Transmit[index].PduId == DcmTxPduId)
            {
                Scheduler_0x2A_Transmit[index].Transmit = FALSE;
            }
        }
#else
        DCM_UNUSED(DcmTxPduId);
#endif
    }
}
#define DCM_STOP_SEC_DCMTXCONFIRMATION_CALLBACK_CODE
#include "Dcm_MemMap.h"
/*******************internal functions****************************/
/*************************************************************************/
/*
 * Brief               <DSL layer sends the response function>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <ProtocolCtrlId:Protocol control block index number.>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <DsdInternal_ProcessingDone>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(void, DCM_CODE) DslInternal_ProcessingDone(uint8 ProtocolCtrlId)
{
    PduIdType DcmTxPduIdx;
    PduInfoType PduInfo;
    uint8 MsgCtrlIndexx;
    Std_ReturnType ret;
    uint8 Index;
    uint8 iloop;
    boolean ProcessOn = TRUE;
#if (STD_ON == DCM_GENERIC_CONNECTION)
    PduIdType DcmRxPduIdx;
    uint8 Metadata[5];

    PduInfo.MetaDataPtr = Metadata;
#endif

    MsgCtrlIndexx = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    DcmTxPduIdx = Dcm_MsgCtrl[MsgCtrlIndexx].DcmTxPduId;
#if (STD_ON == DCM_GENERIC_CONNECTION)
    DcmRxPduIdx = Dcm_MsgCtrl[MsgCtrlIndexx].DcmRxPduId;
    if ((Dsl_Protocol_Connection_RxCfg[DcmRxPduIdx].DcmDslMetaDataFlag & DCM_METADATA_LENGTH_MASK) > 0u)
    {
        if ((Dsl_Protocol_Connection_RxCfg[DcmRxPduIdx].DcmDslMetaDataFlag & DCM_ADDRESS_EXTENSION_8_MASK)
            == DCM_ADDRESS_EXTENSION_8_MASK)
        {
            PduInfo.MetaDataPtr[4u] = Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_MetaData_AE;
        }
        if ((Dsl_Protocol_Connection_RxCfg[DcmRxPduIdx].DcmDslMetaDataFlag & DCM_SA16_AND_TA16_MASK)
            == DCM_SA16_AND_TA16_MASK)
        {
#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
            PduInfo.MetaDataPtr[0u] = (uint8)((Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_MetaData_TA & 0xFF00u) >> 8u);
            PduInfo.MetaDataPtr[1u] = (uint8)(Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_MetaData_TA & 0xFFu);
            PduInfo.MetaDataPtr[2u] = (uint8)((Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_MetaData_SA & 0xFF00u) >> 8u);
            PduInfo.MetaDataPtr[3u] = (uint8)(Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_MetaData_SA & 0xFFu);
#else
            PduInfo.MetaDataPtr[0u] = (uint8)(Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_MetaData_TA & 0xFFu);
            PduInfo.MetaDataPtr[1u] = (uint8)((Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_MetaData_TA & 0xFF00u) >> 8u);
            PduInfo.MetaDataPtr[2u] = (uint8)(Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_MetaData_SA & 0xFFu);
            PduInfo.MetaDataPtr[3u] = (uint8)((Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_MetaData_SA & 0xFF00u) >> 8u);
#endif
        }
    }
#else
    PduInfo.MetaDataPtr = NULL_PTR;
#endif
    PduInfo.SduLength = (PduLengthType)(Dcm_MsgCtrl[MsgCtrlIndexx].MsgContext.ResMaxDataLen);
    for (Index = 0; Index < DCM_CONNECTION_NUM; Index++)
    {
        if (Dsl_Protocol_ConnectionCfg[Index].DcmDslParentProtocolRowCtrlId == ProtocolCtrlId)
        {
            for (iloop = 0; iloop < DCM_MAINCONNECTION_NUM; iloop++)
            {
                if ((Dsl_Protocol_ConnectionCfg[Index].pDcmDslMainConnection != NULL_PTR)
                    && (Dsl_Protocol_ConnectionCfg[Index].pDcmDslMainConnection->DcmDslProtocolComMChannelId
                        == Dcm_CommCtrl[iloop].DcmDslProtocolComMChannelId)
                    && (Dcm_CommCtrl[iloop].Dcm_CommState != DCM_COMM_FULL_COMMUNICATION))
                {
                    ret = DslInternal_MaxIsLargerThanP2Server(ProtocolCtrlId);
                    if (E_OK == ret)
                    {
                        /*time expired*/
                        DslInternal_ResetResource(ProtocolCtrlId);
                    }
                    ProcessOn = FALSE;
                }
            }
        }
    }

    /*the Multiplicity of DcmDslProtocolTx is "0"*/
    if ((ProcessOn == TRUE) && (DcmTxPduIdx == DCM_INVALID_UINT8))
    {
        /*process the received diagnostic request without sending a response*/
        DslInternal_ResetResource(ProtocolCtrlId);
        ProcessOn = FALSE;
    }

    if (ProcessOn == TRUE)
    {
        ret = DslInternal_MinIsLargerThanP2Server(ProtocolCtrlId);
        if (E_NOT_OK == ret)
        {
            /*Response time <P2ServerMin*/
            ProcessOn = FALSE;
        }
    }
    if (ProcessOn == TRUE)
    {
        ret = PduR_DcmTransmit(DcmTxPduIdx, &PduInfo);
        if (E_NOT_OK == ret)
        {
            /*Failed to send*/
            DslInternal_ResetResource(ProtocolCtrlId);
            ProcessOn = FALSE;
        }
    }
    if (ProcessOn == TRUE)
    {
        SchM_Enter_Dcm(Dcm_MsgCtrl);
        Dcm_MsgCtrl[MsgCtrlIndexx].SendFlag = TRUE;
        SchM_Exit_Dcm(Dcm_MsgCtrl);

        /****Close P2Server Timer****/
        DslInternal_P2ServerStop(ProtocolCtrlId);
    }
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#if (STD_ON == DCM_UDS_SERVICE0X86_ENABLED)
/*************************************************************************/
/*
 * Brief               <>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <MsgPtr,MsgLen,DcmRxPduId>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(void, DCM_CODE)
/* PRQA S 3432,1532++ */ /* MISRA Rule 20.7,8.7 */
DslInternal_ResponseOnOneEvent(P2VAR(PduInfoType, TYPEDEF, TYPEDEF) PduInfo, PduIdType DcmRxPduId)
/* PRQA S 3432,1532-- */ /* MISRA Rule 20.7,8.7 */
{
    PduLengthType availabeBufferLength;
    PduLengthType DataLength = PduInfo->SduLength;
    BufReq_ReturnType ret;
    PduInfo->SduLength = 0;
    ret = Dcm_StartOfReception(DcmRxPduId, PduInfo, DataLength, &availabeBufferLength);
    PduInfo->SduLength = DataLength;
    if (ret == BUFREQ_OK)
    {
        ret = Dcm_CopyRxData(DcmRxPduId, PduInfo, &availabeBufferLength);
    }
    if (ret == BUFREQ_OK)
    {
        Dcm_TpRxIndication(DcmRxPduId, E_OK);
    }
    else
    {
        Dcm_TpRxIndication(DcmRxPduId, E_NOT_OK);
    }
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif
