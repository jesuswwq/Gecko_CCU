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

#ifndef COMMUNICATION_DCM_DCM_INTERNAL_H_
#define COMMUNICATION_DCM_DCM_INTERNAL_H_

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dcm_Types.h"
#include "Dcm_Cbk.h"
#include "DcmDsl.h"
#include "DcmDsd.h"
#include "DcmDsp.h"
#include "PduR_Dcm.h"
#include "Rte_Dcm.h"
#if (NVM_ENABLE == STD_ON)
#include "NvM_Types.h"
#include "NvM.h"
#endif

#define DCM_MODULE_ID   (0x35u)
#define DCM_VENDOR_ID   (62u)   /*vendor*/
#define DCM_INSTANCE_ID (0x00u) /*instance*/
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define DCM_INVALID_UINT8  (0xFFu)
#define DCM_INVALID_UINT16 (0xFFFFu)
#define DCM_INVALID_UINT32 (0xFFFFFFFFUL)
#define DCM_INVALID_PDUID  (0xFFu)
/*****************************Development error values ***********************/
#define DCM_E_INTERFACE_TIMEOUT      (0x01u) /*Application-Interface: Timeout*/
#define DCM_E_INTERFACE_RETURN_VALUE (0x02u)
/*Application-Interface: Return-value out of range*/
#define DCM_E_INTERFACE_BUFFER_OVERFLOW (0x03u) /*Application-Interface: Buffer Overflow*/
#define DCM_E_UNINIT                    (0x05u) /*Internal: DCM not initialized*/
#define DCM_E_PARAM                     (0x06u)
/*DCM API function with invalid input parameter*/
#define DCM_E_PARAM_POINTER (0x07u)
/*DCM API service invoked with NULL POINTER as parameter*/
#define DCM_E_INIT_FAILED              (0x08u) /*Dcm initialisation failed*/
#define DCM_E_SET_PROG_CONDITIONS_FAIL (0x09u) /*Storing the ProgConditions failed*/
/*******************************Dcm Module API ID*****************************/
/*#define  DCM_INIT_ID                       (0x01u)*/ /*Dcm_Init()*/
#define DCM_STARTOFRECEPTION_ID       (0x46u)
#define DCM_COPYRXDATA_ID             (0x44u)
#define DCM_TPRXINDICATION_ID         (0x45u)
#define DCM_COPYTXDATA_ID             (0x43u)
#define DCM_TPTXCONFIRMATION_ID       (0x48u)
#define DCM_TXCONFIRMATION_ID         (0x40u)
#define DCM_GETSESCTRLTYPE_ID         (0x06u) /*Dcm_GetSesCtrlType() */
#define DCM_GETSECURITYLEVEL_ID       (0x0Du) /*Dcm_GetSecurityLevel()*/
#define DCM_GETACTIVEPROTOCOL_ID      (0x0Fu) /*Dcm_GetActiveProtocol()*/
#define DCM_COMM_NOCOMMODEENTERED     (0x21u) /*Dcm_Comm_NoComModeEntered()*/
#define DCM_COMM_SILENTCOMMODEENTERED (0x22u) /*Dcm_Comm_SilentComModeEntered()*/
#define DCM_COMM_FULLCOMMODEENTERED   (0x23u) /*Dcm_Comm_FULLComModeEntered()*/
#define DCM_GETVERSIONINFO_ID         (0x24u) /*Dcm_GetVersionInfo()*/
#define DCM_GETVIN_ID                 (0x07u) /*Dcm_GetVin()*/
#define DCM_MAIN_FUNCTION_ID          (0x25u) /*Dcm_Main_Function()*/
#define DCM_DEMTRIGGERONDTCSTATUS_ID  (0x2Bu) /*Dcm_DemTriggerOnDTCStatus()*/
#define DCM_RESETTODEFAULTSESSION_ID  (0x2Au) /*Dcm_ResetToDefaultSession()*/
#define DCM_TRIGGERONEVENT_ID         (0x2Du) /*Dcm_TriggerOnEvent()*/
#define DCM_SETACTIVEDIAGNOSTIC_ID    (0x56u) /*Dcm_SetActiveDiagnostic()*/
#define DCM_INIT_ID                   (0x01u) /*Dcm_Init()*/

#if (STD_ON == DCM_GENERIC_CONNECTION)
#define DCM_METADATA_LENGTH_MASK     (uint8)0x0F

#define DCM_ADDRESS_EXTENSION_8_MASK (uint8)0x10

#define DCM_SA16_AND_TA16_MASK       (uint8)0x20
#endif

#define DCM_UNUSED(a) (void)(a)

#if (STD_ON == DCM_DEV_ERROR_DETECT)
#define DCM_DET_REPORTERROR(ApiId, ErrorId) ((void)Det_ReportError(DCM_MODULE_ID, DCM_INSTANCE_ID, (ApiId), (ErrorId)))
#endif /* STD_ON == DCM_DEV_ERROR_DETECT */

/****************************************************************************/
#ifndef E_SESSION_NOT_ALLOWED
#define E_SESSION_NOT_ALLOWED ((Std_ReturnType)4)
#endif /* E_SESSION_NOT_ALLOWED */
/*Application does not allow the session change*/
#ifndef E_PROTOCOL_NOT_ALLOWED
#define E_PROTOCOL_NOT_ALLOWED ((Std_ReturnType)5)
#endif /* E_PROTOCOL_NOT_ALLOWED */
/*Application does not allow further processing of the protocol*/
#ifndef E_REQUEST_NOT_ACCEPTED
#define E_REQUEST_NOT_ACCEPTED ((Std_ReturnType)8) /**/
#endif                                             /* E_REQUEST_NOT_ACCEPTED */
#ifndef E_REQUEST_ENV_NOK
#define E_REQUEST_ENV_NOK ((Std_ReturnType)9)      /**/
#endif                                             /* E_REQUEST_ENV_NOK */
#ifndef DCM_E_PENDING
#define DCM_E_PENDING ((Std_ReturnType)10)         /**/
#endif                                             /* DCM_E_PENDING */
#ifndef E_COMPARE_KEY_FAILED
#define E_COMPARE_KEY_FAILED ((Std_ReturnType)11)  /*Compare key failure*/
#endif                                             /* E_COMPARE_KEY_FAILED */
#if (STD_ON == DCM_DSLDIAGRESP_FORCERESPENDEN)
#ifndef DCM_E_FORCE_RCRRP
#define DCM_E_FORCE_RCRRP ((Std_ReturnType)12)
#endif /* DCM_E_FORCE_RCRRP */
/*Application requests sent immediately NRC = 0x78*/
#endif
/****************************************************************************/
typedef uint8 Dcm_StatusType;
#define DCM_E_OK                      ((Dcm_StatusType)0x00)
#define DCM_E_ROE_NOT_ACCEPTED        ((Dcm_StatusType)0x06)
#define DCM_E_PERIODICID_NOT_ACCEPTED ((Dcm_StatusType)0x07)
/****************************************************************************/
typedef uint8 Dcm_ReturnReadMemoryType;
#define DCM_READ_OK          ((Dcm_ReturnReadMemoryType)0x00)
#define DCM_READ_PENDING     ((Dcm_ReturnReadMemoryType)0x01)
#define DCM_READ_FAILED      ((Dcm_ReturnReadMemoryType)0x02)
#define DCM_READ_FORCE_RCRRP ((Dcm_ReturnReadMemoryType)0x03)
/****************************************************************************/
typedef uint8 Dcm_ReturnWriteMemoryType;
#define DCM_WRITE_OK          ((Dcm_ReturnWriteMemoryType)0x00)
#define DCM_WRITE_PENDING     ((Dcm_ReturnWriteMemoryType)0x01)
#define DCM_WRITE_FAILED      ((Dcm_ReturnWriteMemoryType)0x02)
#define DCM_WRITE_FORCE_RCRRP ((Dcm_ReturnWriteMemoryType)0x03)
/****************************************************************************/
/****************************************************************************/

#define NONE_PID          0x00u
#define SUPPORT_REQUEST   0x01u
#define NORMAL_REQUEST    0x02u
#define NEED_CALL_UDS_API 0x03u

/*in default session, delay S3 time release network*/
#if !defined(DCM_DELAY_COMM_INACTIVE)
#define DCM_DELAY_COMM_INACTIVE 0
#endif
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/********************************************
      OBD  buffer
 ********************************************/
typedef struct
{
    PduLengthType Length;
    uint8 Buffer[DCM_FRAME_LENGTH];
} Dcm_OBDMessageType;
/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
/*DcmGeneral*/
extern CONST(Dcm_GeneralCfgType, DCM_CONST) Dcm_GeneralCfg;
/*Dcm*/
extern CONST(Dcm_CfgType, DCM_CONST) Dcm_Cfg;
/*DcmDsp*/
extern CONST(Dcm_DspCfgType, DCM_CONST) Dcm_DspCfg;
/*DcmDsd*/
extern CONST(Dcm_DsdCfgType, DCM_CONST) Dcm_DsdCfg;
/*DcmDsl*/
extern CONST(Dcm_DslCfgType, DCM_CONST) Dcm_DslCfg;
extern CONST(Dcm_DslProtocolRowType, DCM_CONST) Dsl_ProtocolRowCfg[DCM_DSLPROTOCOLROW_NUM_MAX];
extern CONST(Dcm_DslProtocolRxType, DCM_CONST) Dsl_Protocol_Connection_RxCfg[DCM_DSL_RX_ID_NUM];
extern CONST(Dcm_DslProtocolTxType, DCM_CONST) Dsl_Protocol_Connection_TxCfg[DCM_DSL_TX_ID_NUM];
extern CONST(Dcm_DslConnectionType, DCM_CONST) Dsl_Protocol_ConnectionCfg[DCM_CONNECTION_NUM];
extern CONST(Dcm_DslMainConnectionType, DCM_CONST) Dsl_Protocol_MainConnectionCfg[DCM_MAINCONNECTION_NUM];

extern VAR(uint8, DCM_VAR_POWER_ON_INIT) Dcm_Channel[DCM_CHANNEL_LENGTH];

#if (STD_ON == DCM_UDS_SERVICE0X2A_ENABLED)

extern VAR(SchedulerQueueTransmitTypes, DCM_VAR_NOINIT) Scheduler_0x2A_Transmit[DCM_PERIODICCONNECTION_NUM];

#endif

extern VAR(Dcm_MkCtrlType, DCM_VAR_NOINIT) Dcm_MkCtrl; /*Module control resource*/

extern VAR(boolean, DCM_VAR_POWER_ON_INIT) gAppl_UpdataOK_ResponseFlag;

extern VAR(boolean, DCM_VAR_POWER_ON_INIT) ReProgramingRequest;

extern VAR(Dcm_ProgConditionsType, DCM_VAR_NOINIT) ProgConditions;

#if (STD_ON == DCM_PAGEDBUFFER_ENABLED)

extern VAR(Dcm_PageBufferDataType, DCM_VAR_NOINIT) Dcm_PageBufferData;

#endif

#if (STD_ON == DCM_REQUEST_QUEUED_ENABLED)
extern uint8 Dcm_QueuedIndex;
extern VAR(uint8, DCM_VAR_POWER_ON_INIT) Dcm_RequestQueuedBuffer[2u][DCM_REQUEST_QUEUED_BUFFER_SIZE];
extern Dcm_QueuedRequestCtrlType Dcm_QueuedRequestCtrl[2u];
#endif /* STD_ON == DCM_REQUEST_QUEUED_ENABLED */
/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#if (STD_ON == DCM_PAGEDBUFFER_ENABLED)
extern FUNC(void, DCM_CODE) DslInternal_InitPageBuffer(void);
#endif
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
extern FUNC(void, DCM_CODE) Dcm_ResetTime(P2VAR(uint32, AUTOMATIC, DCM_VAR) TimerPtr);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

extern Std_ReturnType Dcm_SetProgConditions(Dcm_OpStatusType OpStatus, Dcm_ProgConditionsType* ProgConditions);

/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
extern FUNC(void, DCM_CODE) Dcm_GetTimeSpan(uint32 TimerPtr, P2VAR(uint32, AUTOMATIC, DCM_VAR) TimeSpanPtr);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

extern FUNC(void, DCM_CODE) DslInternal_InitDspProgramInfo(void);

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
extern FUNC(void, DCM_CODE) DslInternal_InitChannelQueuedRequestCtrl(void);
#endif /* STD_ON == DCM_REQUEST_QUEUED_ENABLED */

#endif /* COMMUNICATION_DCM_DCM_INTERNAL_H_ */
