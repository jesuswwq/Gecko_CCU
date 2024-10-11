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

#ifndef DCMDSL_MSGMANAGE_H
#define DCMDSL_MSGMANAGE_H
/*============================================================================*/

/*=======[I N C L U D E S]====================================================*/
#include "Dcm_Types.h"
#include "Rte_Dcm_Type.h"
/****************************** definitions *********************************/
#define DCM_MSG_NUM DCM_DSLPROTOCOLROW_NUM_MAX /*number of Message control block*/

/**************************************************************************
 **************Data transceiver sub-function data structure***************
 *************************************************************************/
/******************************************
 ***P2Timer runtime type / control type****
 *******************************************/
typedef enum
{
    DCM_P2TIMER_ON = 0,
    DCM_P2TIMER_OFF = 1
} Dcm_P2StateType;

typedef struct
{
    uint32 Dcm_P2CurTimer;
    uint32 Dcm_P2ExpiredTimer;
    uint8 PendingNum;
    Dcm_P2StateType Dcm_P2State;
} Dcm_P2CtrlType;

/********************************************
 Channel operation status type / control type
 *******************************************/
typedef enum
{
    DCM_CH_IDLE = 0,    /*Channel "idle" state*/
    DCM_CH_OCCUPIED = 1 /*Channel "occupied" state*/
} Dcm_ChannelStateType;

typedef enum
{
    DCM_PENDING_REQUEST_NONE = 0,    /* No pending request */
    DCM_PENDING_REQUEST_RECEIVE = 1, /* Pending request is receiving */
    DCM_PENDING_REQUEST_READY = 2,   /* Pending request is ready */
    DCM_PENDING_REQUEST_PROCESS = 3  /* Pending Request is processing */
} Dcm_PendingRequestStateType;

typedef struct
{
    uint8 Dcm_ChannelCfgIndex;
    /*Static configuration channel index number, mapping connection index*/
    uint32 Dcm_BufferCunrentPosition;
    uint32 Dcm_BufferErasePosition;
    Dcm_ChannelStateType Dcm_ChannelRxState; /*Static configuration channel receiving state*/
    Dcm_ChannelStateType Dcm_ChannelTxState; /*Static configuration channel transmission status*/
} Dcm_ChannelCtrlType;

#if (STD_ON == DCM_REQUEST_QUEUED_ENABLED)
typedef struct
{
    PduIdType Dcm_QueuedRequestRxPduId;
    uint32 Dcm_QueuedRequestBufferCunrentPosition;
    uint32 Dcm_QueuedRequestLength;
    Dcm_PendingRequestStateType Dcm_PendingRequestState;
} Dcm_QueuedRequestCtrlType;
#endif /* STD_ON == DCM_REQUEST_QUEUED_ENABLED */

typedef struct
{
    uint8 Dcm_ConnectionCfgIndex;
    boolean Dcm_ConnectionActive;
} Dcm_ConnectionCtrlType;

/************************************
 Message Run-time data structures
 ************************************/
typedef uint8 Dcm_MsgItemType;
typedef Dcm_MsgItemType* Dcm_MsgType;
typedef uint32 Dcm_MsgLenType;
typedef uint8 Dcm_IdContextType;

typedef struct
{
    uint8 ReqType; /*=FALSE:physical Addressing,=TRUE:Functional Addressing*/
    boolean SuppressPosResponse;
    /*:=FALSE:Allow positive response;=TRUE:Suppress positive response*/
    boolean CancelOperation;
    /*=FALSE:Not cancel Pending, =TRUE:Cancel Pending*/
} Dcm_MsgAddInfoType;

typedef struct
{
    Dcm_MsgType pReqData;      /*Point to request data*/
    Dcm_MsgLenType ReqDataLen; /*Request data length*/
    /*Old Request data length for 3E 80 Fun to resumed last pending length*/
    Dcm_MsgType pResData;      /*Point to the response data (including the SID data)*/
    Dcm_MsgLenType ResDataLen; /*Response packet data length(including the SID data)*/
    Dcm_MsgAddInfoType MsgAddInfo;
    /*Additional information for service requests and responses*/
    Dcm_MsgLenType ResMaxDataLen; /*The maximum number of bytes of response data*/
    Dcm_IdContextType IdContext;
    PduIdType DcmRxPduId;         /*Request message identifier*/
} Dcm_MsgContextType;

typedef enum
{
    DCM_MSG_WAIT = 0,
    DCM_MSG_RECEIVED = 1,
    DCM_MSG_PROCESSED = 2,
    DCM_MSG_TRANSMISSION = 3,
    DCM_MSG_CONFIRMATION = 4
} Dcm_MsgStateType;

typedef enum
{
    DCM_POS_RSP = 0,         /*Positive response*/
    DCM_NEG_RSP = 1,         /*Negative response*/
    DCM_POS_RSP_SUPPRESS = 2 /*Positive response Suppress*/
} Dcm_RspType;

typedef struct
{
    uint8 SID;         /*Service ID*/
    uint8 Subfunction; /*Service Subfunction */
    Dcm_NegativeResponseCodeType NRC;
    /*Negative response code, default = 0xFF*/
    boolean SendFlag;              /*=TRUE: being sent;=FALSE: not sent*/
    PduIdType DcmTxPduId;
    uint8 Dcm_RxCtrlChannelIndex;  /*Message receiver channel control block index number*/
    uint8 Dcm_TxCtrlChannelIndex;  /*Message Transmit channel control block index number*/
    Dcm_RspType RspStyle;          /*Type of response*/
    Dcm_MsgContextType MsgContext; /*Request/response message content*/
    Dcm_P2CtrlType Dcm_P2Ctrl;     /*P2Timer control block*/
    Dcm_MsgStateType Dcm_MsgState; /*Message status*/
    Std_ReturnType Dcm_Ret;
    Dcm_OpStatusType Dcm_OpStatus;
#if (STD_ON == DCM_GENERIC_CONNECTION)
    uint16 Dcm_MetaData_SA;
    uint16 Dcm_MetaData_TA;
    uint8 Dcm_MetaData_AE;
    uint16 Dcm_MetaData_SA_Backup;
    uint16 Dcm_MetaData_TA_Backup;
    uint8 Dcm_MetaData_AE_Backup;
    PduIdType DcmRxPduId;
#endif
} Dcm_MsgCtrlType;

/********************************************
      function addressing buffer
 ********************************************/
typedef struct
{
    PduLengthType Length;
    uint8 Buffer[DCM_FRAME_LENGTH];
} Dcm_FunctionMessageType;

/********************************************************
*********************Resource statement*****************
********************************************************/

extern VAR(Dcm_ChannelCtrlType, DCM_VAR_NOINIT) Dcm_ChannelCtrl[DCM_CHANNEL_NUM];
/*Channel control block, one channel mapping one connection*/
extern VAR(Dcm_MsgCtrlType, DCM_VAR_NOINIT) Dcm_MsgCtrl[DCM_MSG_NUM];
/*Message control block*/
extern VAR(Dcm_ConnectionCtrlType, DCM_VAR_NOINIT) Dcm_ConnectionCtrl[DCM_CONNECTION_NUM];

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

extern FUNC(void, DCM_CODE) Dcm_MemoryCopy(
    P2CONST(uint8, AUTOMATIC, DCM_APPL_CONST) Source,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Dest,
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
    uint32 Length);
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
extern FUNC(void, DCM_CODE) DslInternal_InitChannelCtrl(uint8 ChannelCtrlId);

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

extern FUNC(void, DCM_CODE) DslInternal_InitMsgCtrl(uint8 MsgCtrlId);

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

extern FUNC(void, DCM_CODE) DslInternal_InitMkCtrl(void);

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

extern FUNC(void, DCM_CODE) DslInternal_ResetResource(uint8 ProtocolCtrlId);

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

extern FUNC(void, DCM_CODE) DslInternal_ProcessingDone(uint8 ProtocolCtrlId);

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
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
FUNC(void, DCM_CODE) DslInternal_ResponseOnOneEvent(P2VAR(PduInfoType, TYPEDEF, TYPEDEF) PduInfo, PduIdType DcmRxPduId);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
#endif

#endif /* DCMDSL_MSGMANAGE_H_ */
