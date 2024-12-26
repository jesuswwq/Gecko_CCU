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
**  FILENAME    : Com.c                                                       **
**                                                                            **
**  Created on  :                                                             **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Implementation for COM                                      **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      REVISION   HISTORY                                    **
*******************************************************************************/
/* <VERSION>  <DATE>    <AUTHOR>      <REVISION LOG>
 *  V2.0.0    20200706  zhengfei.li   Initial version
 *                                    (Upgrade according to the R19_11 standards)
 *  V2.0.1    20211108  zhengfei.li   Optimize enumeration element names, macro names
 *  V2.0.2    20230506  fupeng.yu     Do not copy or handle additional received data
 *                                    If the received I-PDU length is greater than the
 *                                    configured/expected I-PDU length
 *  V2.0.3    20230912  rongbo.hu/fupeng.yu  Com module execution efficiency optimization
 *  V2.0.4    20230919  tong.zhao
 *    1> QAC check,code update
 *    2> Fix bug of rx signal unpack and signal gateway (JIRA: CPT-6970,CPT-6971)
 ******************************************************************************/

/**
  \page ISOFT_MISRA_Exceptions  MISRA-C:2012 Compliance Exceptions
    ModeName:Com<br>
  RuleSorce:puhua-rule.rcf 2.3.1

    \li PRQA S 3432 MISRA Rule 20.7 .<br>
    Reason:Function-like macros are used to allow more efficient code.

    \li PRQA S 2981 MISRA Rule 2.2 .<br>
    Reason:Init may be necessary for return variant.

    \li PRQA S 1532 MISRA Rule 8.7 .<br>
    Reason:In order to make the module code structure clear, the functions are classified.

    \li PRQA S 4502 MISRA Rule 10.1 .<br>
    Reason:Necessary type conversions.

    \li PRQA S 4340 MISRA Rule 10.5 .<br>
    Reason:Necessary type conversions.

    \li PRQA S 4304 MISRA Rule 10.5 .<br>
    Reason:Necessary type conversions.

    \li PRQA S 3206 MISRA Rule 2.7 .<br>
    Reason:Parameter may be used in other Configuration projects.
 */

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Com_Internal.h"
#include "Com_Cbk.h"

#include "SchM_Com.h"
#if (STD_ON == COM_DEV_ERROR_DETECT)
#include "Det.h"
#endif
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
#define COM_C_AR_MAJOR_VERSION 4u
#define COM_C_AR_MINOR_VERSION 2u
#define COM_C_AR_PATCH_VERSION 2u
#define COM_C_SW_MAJOR_VERSION 2u
#define COM_C_SW_MINOR_VERSION 0u
#define COM_C_SW_PATCH_VERSION 3u
/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/
#if (COM_C_AR_MAJOR_VERSION != COM_H_AR_MAJOR_VERSION)
#error "Com.c : Mismatch in Specification Major Version"
#endif
#if (COM_C_AR_MINOR_VERSION != COM_H_AR_MINOR_VERSION)
#error "Com.c : Mismatch in Specification Major Version"
#endif
#if (COM_C_AR_PATCH_VERSION != COM_H_AR_PATCH_VERSION)
#error "Com.c : Mismatch in Specification Major Version"
#endif
#if (COM_C_SW_MAJOR_VERSION != COM_H_SW_MAJOR_VERSION)
#error "Com.c : Mismatch in Specification Major Version"
#endif
#if (COM_C_SW_MINOR_VERSION != COM_H_SW_MINOR_VERSION)
#error "Com.c : Mismatch in Specification Major Version"
#endif
#if (COM_C_SW_PATCH_VERSION != COM_H_SW_PATCH_VERSION)
#error "Com.c : Mismatch in Specification Major Version"
#endif
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
#define COM_START_SEC_VAR_INIT_8
#include "Com_MemMap.h"
static VAR(Com_StatusType, COM_VAR_POWER_ON_INIT) Com_Status = COM_UNINIT;
#define COM_STOP_SEC_VAR_INIT_8
#include "Com_MemMap.h"

#if (COM_IPDUGROUP_NUMBER > 0u)
#define COM_START_SEC_VAR_NO_INIT_BOOLEAN
#include "Com_MemMap.h"
static VAR(boolean, COM_VAR) Com_IpduGroupDMEnable[COM_IPDUGROUP_NUMBER];
#define COM_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "Com_MemMap.h"
#endif
/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
#define COM_START_SEC_VAR_INIT_PTR
#include "Com_MemMap.h"
P2CONST(Com_ConfigType, COM_VAR, COM_CONST)
Com_ConfigStd = NULL_PTR;
#define COM_STOP_SEC_VAR_INIT_PTR
#include "Com_MemMap.h"

#if (COM_IPDUGROUP_NUMBER > 0u)
#define COM_START_SEC_VAR_NO_INIT_BOOLEAN
#include "Com_MemMap.h"
VAR(boolean, COM_VAR)
Com_IpduGroupEnable[COM_IPDUGROUP_NUMBER];
#define COM_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "Com_MemMap.h"
#endif

#if (COM_TXSIGNALGROUP_NUMBER > 0u)
#define COM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Com_MemMap.h"
VAR(Com_TxSignalGroupRunTimeStateType, COM_VAR)
Com_TxSignalGroupState[COM_TXSIGNALGROUP_NUMBER];
#define COM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Com_MemMap.h"
#endif

#if ((COM_RXSIGNAL_NUMBER + COM_RXSIGNALGROUP_NUMBER) > 0u)
#define COM_START_SEC_VAR_NO_INIT_16
#include "Com_MemMap.h"
VAR(uint16, COM_VAR)
Com_TimeOutCnt[COM_RXSIGNAL_NUMBER + COM_RXSIGNALGROUP_NUMBER];
#define COM_STOP_SEC_VAR_NO_INIT_16
#include "Com_MemMap.h"
#endif

#if (COM_GWSOURCESIGNAL_UPDATE_NUMBER > 0u)
#define COM_START_SEC_VAR_NO_INIT_BOOLEAN
#include "Com_MemMap.h"
VAR(boolean, COM_VAR)
Com_GWSourceSignalUpdate[COM_GWSOURCESIGNAL_UPDATE_NUMBER];
#define COM_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "Com_MemMap.h"
#endif

#if (COM_ONEEVERYNFILTERSIGNAL_NUMBER > 0u)
#define COM_START_SEC_VAR_NO_INIT_32
#include "Com_MemMap.h"
VAR(uint32, COM_VAR)
Com_OneEveryNcnt[COM_ONEEVERYNFILTERSIGNAL_NUMBER];
#define COM_STOP_SEC_VAR_NO_INIT_32
#include "Com_MemMap.h"
#endif

#if (COM_RXSIGNALMASKNEWDIFFERMASKOLD_NUMBER > 0u)
#define COM_START_SEC_VAR_NO_INIT_BOOLEAN
#include "Com_MemMap.h"
VAR(boolean, COM_VAR)
Com_MaskNewDifferMaskOldTimeOut[COM_RXSIGNALMASKNEWDIFFERMASKOLD_NUMBER];
#define COM_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "Com_MemMap.h"
#endif
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#pragma default_function_attributes = @".iram_func"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* called by Com_Init
 * Init the Pdu Runtime Manager and Buffer*/
static FUNC(void, COM_CODE) Com_PduRTAndBufferInit(void);
/* called by Com_Init
 * Init the Runtime RxSignal/RxGroupSignal Buffer*/
static FUNC(void, COM_CODE) Com_SignalBufferInit(void);
/* called by Com_MainFunctionRx
 * RxSignal receive timeout handle*/
#if ((0u < COM_RXIPDU_NUMBER) && (COM_RXSIGNAL_NUMBER > 0u) && (STD_ON == COM_RX_SIGNAL_TIMEOUT_ENABLE))
static FUNC(void, COM_CODE) Com_RxSignalTimeOutHandle(PduIdType rxIpduId);
#endif /* ((0u < COM_RXIPDU_NUMBER) && (COM_RXSIGNAL_NUMBER > 0u) && (STD_ON == COM_RX_SIGNAL_TIMEOUT_ENABLE)) */
/* called by Com_MainFunctionRx
 * RxSignalGroup receive timeout handle*/
#if ((0u < COM_RXIPDU_NUMBER) && (COM_RXSIGNALGROUP_NUMBER > 0u) && (STD_ON == COM_RX_SIG_GROUP_TIMEOUT_ENABLE))
static FUNC(void, COM_CODE) Com_RxSignalGroupTimeOutHandle(PduIdType rxIpduId);
#endif /* ((0u < COM_RXIPDU_NUMBER) && (COM_RXSIGNALGROUP_NUMBER > 0u) && (STD_ON == \
          COM_RX_SIG_GROUP_TIMEOUT_ENABLE)) */
/*Called by Com_MainFunctionTx.
 *Send the tx pdu in Com_MainFunctionTx*/
#if (0u < COM_TXIPDU_NUMBER)
static FUNC(void, COM_CODE) Com_MainFunction_SendPdu(PduIdType txIpduId);
#endif
/*Called by Com_ReceiveSignal.
 *Receive signal handle*/
#if (0u < COM_RXSIGNAL_NUMBER)
static FUNC(uint8, COM_CODE)
    Com_ReceiveSignalHandle(Com_SignalIdType SignalId, P2VAR(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr);
#endif
/*Called by Com_ReceiveSignal.
 *Receive group signal handle*/
#if (0u < COM_RXSIGNALGROUP_NUMBER)
static FUNC(uint8, COM_CODE)
    Com_ReceiveGroupSignalHandle(Com_SignalIdType SignalId, P2VAR(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr);
#endif
/*Called by Com_RxIndication.
 *Receive Rx Pdu handle*/
#if (0u < COM_RXIPDU_NUMBER)
static FUNC(void, COM_CODE)
    Com_RxPduHandle(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
#endif
/*Called by Com_SendSignalGroupArray.
 *Send Signal Group handle*/
#if (STD_ON == COM_ENABLE_SIGNAL_GROUP_ARRAY_API)
#if ((0u < COM_TXSIGNALGROUP_NUMBER) && (0u < COM_TXIPDU_NUMBER))
static FUNC(void, COM_CODE) Com_SendSignalGroupArrayHandle(
    Com_SignalGroupIdType SignalGroupId,
    PduIdType ipduRef,
    boolean triggerOnChange,
    uint16 rptNum);
#endif
#endif
/*Called by Com_TriggerIPDUSend,Com_TriggerIPDUSendWithMetaData.
 *Trigger IPdu Send handle*/
#if (0u < COM_TXIPDU_NUMBER)
static FUNC(Std_ReturnType, COM_CODE) Com_TriggerIPDUSendHandle(PduIdType txIpduId);
#endif

/*Called by Com_MainFunctionRouteSignals.
 *Signal/Group Signal/Dest Description Signal handle*/
#if (                                                                                   \
    (0u < COM_GWMAPPING_NUMBER) && (0u < COM_RXIPDU_NUMBER) && (0u < COM_TXIPDU_NUMBER) \
    && (STD_ON == COM_SIGNAL_GW_ENABLE))
static FUNC(void, COM_CODE) Com_RouteSignalHandle(uint16 GwMapId);
#endif /* ((0u < COM_GWMAPPING_NUMBER) && (0u < COM_RXIPDU_NUMBER) && (0u < COM_TXIPDU_NUMBER) && (STD_ON == \
          COM_SIGNAL_GW_ENABLE)) */

#if (0u < COM_RXIPDU_NUMBER)
/*Called by Com_ReceiveDynSignal.
 *Receive Dynamic Signal handle*/
#if ((0u < COM_RXSIGNAL_NUMBER) && (0u < COM_SIGNAL_8BITBUFF_SIZE)) && (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE)
static FUNC(uint8, COM_CODE) Com_ReceiveDynSignalHandle(
    Com_SignalIdType SignalId,
    P2VAR(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(uint16, AUTOMATIC, COM_APPL_CONST) Length);
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
#endif               /* ((0u < COM_RXSIGNAL_NUMBER) && (0u < COM_SIGNAL_8BITBUFF_SIZE)) && (STD_ON == \
                                      COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE) */
/*Called by Com_ReceiveDynSignal.
 *Receive Dynamic Group Signal handle*/
#if ((0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXGROUPSIGNAL_8BITBUFF_SIZE)) \
    && (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE)
static FUNC(uint8, COM_CODE) Com_ReceiveDynGroupSignalHandle(
    Com_SignalIdType SignalId,
    P2VAR(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(uint16, AUTOMATIC, COM_APPL_CONST) Length);
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
#endif               /* ((0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXGROUPSIGNAL_8BITBUFF_SIZE))&& (STD_ON == \
                                       COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE) */
#endif               /* (0u < COM_RXIPDU_NUMBER) */
/*Called by Com_ReceiveSignalGroup.
 *Receive all group signal of the SignalGroup*/
#if ((0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXIPDU_NUMBER))
static FUNC(void, COM_CODE) Com_ReceiveSignalGroupHandle(PduIdType RxPduId, Com_SignalGroupIdType SignalGroupId);
#endif
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/******************************************************************************/
/*
 * Brief               This service initializes internal and external interfaces and
 *                     variables of the AUTOSAR COM module layer for the further processing.
 *                     After calling this function the inter-ECU communication is still disabled.
 * ServiceId           0x01
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      Config: Pointer to the COM configuration data.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, COM_CODE)
Com_Init(P2CONST(Com_ConfigType, AUTOMATIC, COM_CONST_PBCFG) config)
{
    uint16 cirCnt;
#if (STD_ON == COM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (NULL_PTR == config)
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_INIT_ID, COM_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (COM_UNINIT != Com_Status))
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_INIT_ID, COM_E_INIT_FAILED);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
        Com_ConfigStd = config;
        Com_PduRTAndBufferInit();
        Com_SignalBufferInit();
#if (0u < COM_TMCTXSIGNAL_NUMBER)
        /*Init Runtime TMC of all tx signals and tx group siganls and GW dest signals,which the comfilter is not NULL*/
        for (cirCnt = 0u; cirCnt < COM_TMCTXSIGNAL_NUMBER; cirCnt++)
        {
#if (0u < COM_TMCTXGROUPSIGNAL_NUMBER)
            if (cirCnt < COM_TMCTXGROUPSIGNAL_NUMBER)
            {
                TxGroupSignalTMCBuffer[cirCnt] = Com_TxSignalInitTMC[cirCnt];
            }
#endif
            TxSignalTMCRunTime[cirCnt] = Com_TxSignalInitTMC[cirCnt];
        }
#endif /* 0u < COM_TMCTXSIGNAL_NUMBER */
#if (0u < COM_IPDUGROUP_NUMBER)
        /*set the IPdu Group to default disable state,DM disable state*/
        for (cirCnt = 0u; cirCnt < COM_IPDUGROUP_NUMBER; cirCnt++)
        {
            Com_IpduGroupEnable[cirCnt] = FALSE;
            Com_IpduGroupDMEnable[cirCnt] = FALSE;
        }
#endif /* 0u < COM_IPDUGROUP_NUMBER */
/*set all tx signal group state to don't need to trigger transmit*/
#if (0u < COM_TXSIGNALGROUP_NUMBER)
        for (cirCnt = 0u; cirCnt < COM_TXSIGNALGROUP_NUMBER; cirCnt++)
        {
            Com_TxSignalGroupState[cirCnt].NTimesTransmitNeed = FALSE;
        }
#endif /*0u < COM_TXSIGNALGROUP_NUMBER*/
/*set all rx signal,rx signal group's DM timeout counter to 0*/
#if ((COM_RXSIGNAL_NUMBER + COM_RXSIGNALGROUP_NUMBER) > 0u)
        for (cirCnt = 0u; cirCnt < (COM_RXSIGNAL_NUMBER + COM_RXSIGNALGROUP_NUMBER); cirCnt++)
        {
            Com_TimeOutCnt[cirCnt] = 0u;
        }
#endif /*(COM_RXSIGNAL_NUMBER+COM_RXSIGNALGROUP_NUMBER) > 0u*/
/*set the GW signal(source) with update state to FALSE,the state is used for GW signal*/
#if (0u < COM_GWSOURCESIGNAL_UPDATE_NUMBER)
        for (cirCnt = 0u; cirCnt < COM_GWSOURCESIGNAL_UPDATE_NUMBER; cirCnt++)
        {
            Com_GWSourceSignalUpdate[cirCnt] = FALSE;
        }
#endif /*0u < COM_GWSOURCESIGNAL_UPDATE_NUMBER*/
/*used for signal filter ONE_EVERY_N Mode(Rx and Tx)*/
#if (0u < COM_ONEEVERYNFILTERSIGNAL_NUMBER)
        for (cirCnt = 0u; cirCnt < COM_ONEEVERYNFILTERSIGNAL_NUMBER; cirCnt++)
        {
            Com_OneEveryNcnt[cirCnt] = 0u;
        }
#endif /*0u < COM_ONEEVERYNFILTERSIGNAL_NUMBER*/
/*used for signal filter MASKED_NEW_DIFFERS_MASKED_OLD Mode(Rx Signals)*/
#if (0u < COM_RXSIGNALMASKNEWDIFFERMASKOLD_NUMBER)
        for (cirCnt = 0u; cirCnt < COM_RXSIGNALMASKNEWDIFFERMASKOLD_NUMBER; cirCnt++)
        {
            Com_MaskNewDifferMaskOldTimeOut[cirCnt] = FALSE;
        }
#endif /*0u < COM_RXSIGNALMASKNEWDIFFERMASKOLD_NUMBER*/
        Com_Status = COM_INIT;
    }
    return;
}
/******************************************************************************/
/*
 * Brief               This service stops the inter-ECU communication. All started
 *                     I-PDU groups are stopped and have to be started again, if
 *                     needed, after Com_Init is called. By a call to Com_DeInit
 *                     the AUTOSAR COM module is put into an not initialized state.
 * ServiceId           0x02
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, COM_CODE)
Com_DeInit(void)
{
#if ((0u < COM_IPDUGROUP_NUMBER) || (0u < COM_RXIPDU_NUMBER) || (0u < COM_TXIPDU_NUMBER))
    uint16 cirCnt;
#endif
#if (STD_ON == COM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (COM_INIT != Com_Status)
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_DEINIT_ID, COM_E_UNINIT);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if (0u < COM_IPDUGROUP_NUMBER)
        /* clear All IPduGroup Active Flag */
        for (cirCnt = 0u; cirCnt < COM_IPDUGROUP_NUMBER; cirCnt++)
        {
            Com_IpduGroupEnable[cirCnt] = FALSE;
        }
#endif
#if (0u < COM_RXIPDU_NUMBER)
        /* clear All Rx IPdu Active Flag */
        for (cirCnt = 0u; cirCnt < COM_RXIPDU_NUMBER; cirCnt++)
        {
            Com_RxIPduRunTimeState[cirCnt].ActiveEnable = FALSE;
        }
#endif
#if (0u < COM_TXIPDU_NUMBER)
        /* clear All Tx IPdu Active Flag */
        for (cirCnt = 0u; cirCnt < COM_TXIPDU_NUMBER; cirCnt++)
        {
            Com_TxIPduRunTimeState[cirCnt].ActiveEnable = FALSE;
        }
#endif
        /* set Com_Status */
        Com_Status = COM_UNINIT;
    }
    return;
}
/******************************************************************************/
/*
 * Brief               This service starts I-PDU groups.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      ipduGroupVector: I-PDU group vector containing the activation
 *                     state (stopped = 0/started = 1) for all I-PDU groups.
 *                     initialize: flag to request initialization of the I-PDUs which are newly started
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (COM_IPDUGROUP_NUMBER > 0u)
FUNC(void, COM_CODE)
Com_IpduGroupControl(Com_IpduGroupVector ipduGroupVector, boolean initialize)
{
    Com_IpduGroupIdType ipduGroupCnt;
    uint8 value;
#if ((0u < COM_RXIPDU_NUMBER) || (0u < COM_TXIPDU_NUMBER))
    uint16 ipduCnt;
#endif
#if (STD_ON == COM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (COM_INIT != Com_Status)
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_IPDUGROUPCONTROL_ID, COM_E_UNINIT);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
        /*base ipduGroupVector,set the all i-pdu group to enable or disable */
        for (ipduGroupCnt = 0u; ipduGroupCnt < COM_IPDUGROUP_NUMBER; ipduGroupCnt++)
        {
            value = (ipduGroupVector[ipduGroupCnt >> 3u]) >> (ipduGroupCnt % 8u);
            value &= 0x01u;
            if (0x01u == value)
            {
                Com_IpduGroupEnable[ipduGroupCnt] = TRUE;
            }
            else
            {
                Com_IpduGroupEnable[ipduGroupCnt] = FALSE;
            }
        }
/*base i-pdu group state,set all rx pdu to enable or disable.
 * base initialize,select if or not init the rx pdu when state change from disable to enable*/
#if (0u < COM_RXIPDU_NUMBER)
        for (ipduCnt = 0u; ipduCnt < COM_RXIPDU_NUMBER; ipduCnt++)
        {
            Com_RxIpduController(ipduCnt, initialize);
        }
#endif
/*base i-pdu group state,set all tx pdu to enable or disable.
 * base initialize,select if or not init the tx pdu when state change from disable to enable*/
#if (0u < COM_TXIPDU_NUMBER)
        for (ipduCnt = 0u; ipduCnt < COM_TXIPDU_NUMBER; ipduCnt++)
        {
            Com_TxIpduController(ipduCnt, initialize);
        }
#endif
    }
    return;
}
#endif /*COM_IPDUGROUP_NUMBER > 0u*/
/******************************************************************************/
/*
 * Brief               This service enables or disables I-PDU group Deadline Monitoring.
 * ServiceId           0x06
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      ipduGroupVector: I-PDU group vector containing the activation
 *                     state (stopped = 0/started = 1) for all I-PDU groups.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (COM_IPDUGROUP_NUMBER > 0u)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
FUNC(void, COM_CODE)
Com_ReceptionDMControl(Com_IpduGroupVector ipduGroupVector)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
    Com_IpduGroupIdType ipduGroupCnt;
    uint8 value;
#if (0u < COM_RXIPDU_NUMBER)
    uint16 ipduCnt;
    Com_IpduGroupIdType ipduGroupRefNumber;
    Com_IpduGroupIdType index;
    boolean findDMEnableIpduGroup = FALSE;
    Com_IpduGroupIdType ipduGroupId;
#endif
#if (STD_ON == COM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (COM_INIT != Com_Status)
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_RECEPTIONDMCONTROL_ID, COM_E_UNINIT);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
        /*base ipduGroupVector,set the all i-pdu group's Rx DM to enable or disable */
        for (ipduGroupCnt = 0u; ipduGroupCnt < COM_IPDUGROUP_NUMBER; ipduGroupCnt++)
        {
            value = (ipduGroupVector[ipduGroupCnt >> 3u]) >> (ipduGroupCnt % 8u);
            value &= 0x01u;
            if (0x01u == value)
            {
                Com_IpduGroupDMEnable[ipduGroupCnt] = TRUE;
            }
            else
            {
                Com_IpduGroupDMEnable[ipduGroupCnt] = FALSE;
            }
        }
#if (0u < COM_RXIPDU_NUMBER)
        for (ipduCnt = 0u; ipduCnt < COM_RXIPDU_NUMBER; ipduCnt++)
        {
            ipduGroupRefNumber = Com_ConfigStd->ComRxIPdu[ipduCnt].ComIPduGroupsRefNumber;
            /*if the Rx Pdu not included in any Ipdu Group,the DM state is always disabled*/
            if (ipduGroupRefNumber > 0u)
            {
                for (index = 0u; (index < ipduGroupRefNumber) && (FALSE == findDMEnableIpduGroup); index++)
                {
                    ipduGroupId = Com_ConfigStd->ComRxIPdu[ipduCnt].ComIPduGroupsRef[index];
                    if (TRUE == Com_IpduGroupDMEnable[ipduGroupId])
                    {
                        findDMEnableIpduGroup = TRUE;
                    }
                }
                if (TRUE == findDMEnableIpduGroup)
                {
                    /*DM state changed from disabled to enabled*/
                    if (FALSE == Com_RxIPduRunTimeState[ipduCnt].DMEnable)
                    {
                        Com_RxIPduRunTimeState[ipduCnt].DMEnable = TRUE;
/*set the reception deadline monitoring timer for the included signals and signal groups to the configured
 * ComFirstTimeout*/
#if (COM_RXSIGNAL_NUMBER + COM_RXSIGNALGROUP_NUMBER > 0u)
                        Com_ResetRxPduTimeOut(ipduCnt);
#endif
                    }
                }
                else
                {
                    if (TRUE == Com_RxIPduRunTimeState[ipduCnt].DMEnable)
                    {
                        Com_RxIPduRunTimeState[ipduCnt].DMEnable = FALSE;
/*set the reception deadline monitoring timer for the included signals and signal groups to 0*/
#if (COM_RXSIGNAL_NUMBER + COM_RXSIGNALGROUP_NUMBER > 0u)
                        Com_DisableRxPduTimeOut(ipduCnt);
#endif
                    }
                }
            }
        }
#endif /*0u < COM_RXIPDU_NUMBER*/
    }
    return;
}
#endif /*COM_IPDUGROUP_NUMBER > 0u*/
/******************************************************************************/
/*
 * Brief               Returns the status of the AUTOSAR COM module.
 * ServiceId           0x07
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Com_StatusType(COM_UNINIT and COM_INIT)
 *                     COM_UNINIT: the AUTOSAR COM module is not initialized and not usable
 *                     COM_INIT: the AUTOSAR COM module is initialized and usable
 */
/******************************************************************************/
FUNC(Com_StatusType, COM_CODE)
Com_GetStatus(void)
{
    return Com_Status;
}
/******************************************************************************/
/*
 * Brief               This service sets all bits of the given Com_IpduGroupVector to 0.
 * ServiceId           0x1c
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     ipduGroupVector: I-PDU group vector to be cleared
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (COM_IPDUGROUP_NUMBER > 0u)
FUNC(void, COM_CODE)
Com_ClearIpduGroupVector(Com_IpduGroupVector ipduGroupVector)
{
    uint8 vectorByteLength;
    uint8 cnt;
#if (STD_ON == COM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (COM_INIT != Com_Status)
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_CLEARIPDUGROUPVECTOR_ID, COM_E_UNINIT);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
        vectorByteLength = ((COM_IPDUGROUP_NUMBER - 1u) / 8u) + 1u;
        for (cnt = 0u; cnt < vectorByteLength; cnt++)
        {
            ipduGroupVector[cnt] = 0x00u;
        }
    }
    return;
}
#endif /*COM_IPDUGROUP_NUMBER > 0u*/
/******************************************************************************/
/*
 * Brief               This service sets the value of a bit in an I-PDU group vector.
 * ServiceId           0x1d
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      ipduGroupId: ipduGroup used to identify the corresponding bit in the I-PDU group vector
 *                     bitval: New value of the corresponding bit
 * Param-Name[out]     None
 * Param-Name[in/out]  ipduGroupVector: I-PDU group vector to be modified
 * Return              None
 */
/******************************************************************************/
#if (COM_IPDUGROUP_NUMBER > 0u)
FUNC(void, COM_CODE)
Com_SetIpduGroup(Com_IpduGroupVector ipduGroupVector, Com_IpduGroupIdType ipduGroupId, boolean bitval)
{
    uint8 bitValue = 0x01u;
#if (STD_ON == COM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (COM_INIT != Com_Status)
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_SETIPDUGROUP_ID, COM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr)
#if (0u < COM_IPDUGROUP_NUMBER)
        && (ipduGroupId >= COM_IPDUGROUP_NUMBER)
#endif
    )
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_SETIPDUGROUP_ID, COM_E_PARAM);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
        bitValue = bitValue << (ipduGroupId % 8u);
        if (TRUE == bitval)
        {
            ipduGroupVector[ipduGroupId / 8u] |= bitValue;
        }
        else
        {
            ipduGroupVector[ipduGroupId / 8u] &= (uint8)(~bitValue);
        }
    }
    return;
}
#endif /*COM_IPDUGROUP_NUMBER > 0u*/
/*===================================Communication Services========================================*/
/******************************************************************************/
/*
 * Brief               The service Com_SendSignal updates the signal(include group signal) object
 *                     identified by SignalId with the signal referenced by the SignalDataPtr parameter.
 * ServiceId           0x0a
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant for the same signal. Reentrant for different signals.
 * Param-Name[in]      SignalId: Id of signal to be sent.
 *                     SignalDataPtr: Reference to the signal data to be transmitted.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              uint8(E_OK,COM_SERVICE_NOT_AVAILABLE,COM_BUSY)
 *                     E_OK: service has been accepted
 *                     COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped
 *                     (or service failed due to development error)
 *                     COM_BUSY: in case the TP-Buffer is locked for large data types handling
 */
/******************************************************************************/
FUNC(uint8, COM_CODE)
Com_SendSignal(Com_SignalIdType SignalId, P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr)
{
    uint8 ret = COM_SERVICE_NOT_AVAILABLE;
#if (0u < COM_TXIPDU_NUMBER)
#if (0u < COM_TXSIGNAL_NUMBER)
    PduIdType ipduRef;
    Com_TransferPropertyType signalTxProperty;
    boolean valueChanged;
    boolean signalIsDM;
    Com_SignalType signalType;
    uint16 signalLength;
    uint16 signalBufferId;
    uint32 updateBitPosition;
    const Com_TxSignalType* txSignalPtr;
#endif
#if (COM_TXSIGNALGROUP_NUMBER > 0u)
    Com_SignalIdType groupSignalId;
#endif
#endif /*0u < COM_TXIPDU_NUMBER*/
#if (STD_ON == COM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (COM_INIT != Com_Status)
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_SENDSIGNAL_ID, COM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr)
#if (0u < (COM_TXSIGNAL_NUMBER + COM_TXGROUPSIGNAL_NUMBER))
        && (SignalId >= (COM_TXSIGNAL_NUMBER + COM_TXGROUPSIGNAL_NUMBER))
#endif
    )
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_SENDSIGNAL_ID, COM_E_PARAM);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (NULL_PTR == SignalDataPtr))
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_SENDSIGNAL_ID, COM_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if (0u < COM_TXIPDU_NUMBER)
        /*the signal is Tx Signal*/
        if (SignalId < COM_TXSIGNAL_NUMBER)
        {
#if (0u < COM_TXSIGNAL_NUMBER)
            txSignalPtr = &Com_ConfigStd->ComTxSignal[SignalId];
            signalType = txSignalPtr->ComSignalType;
            /*dynamic signal isn't send by the API,InitialValueOnly signal don't expect to be called by any API*/
#if (STD_ON == COM_TX_SIGNAL_TYPE_UINT8_DYN_ENABLE) || (STD_ON == COM_TX_SIG_INITIAL_VALUE_ONLY_ENABLE)
            if ((COM_UINT8_DYN != signalType) && (FALSE == txSignalPtr->ComInitialValueOnly))
#endif /* (STD_ON == COM_TX_SIGNAL_TYPE_UINT8_DYN_ENABLE) || (STD_ON == COM_TX_SIG_INITIAL_VALUE_ONLY_ENABLE) */
            {
                ipduRef = txSignalPtr->ComIpduRefIndex;
/*the IPDU(TP) is sending,return busy*/
#if (STD_ON == COM_TX_IPDU_TYPE_TP_ENABLE)
                if ((COM_PDU_TP == Com_ConfigStd->ComTxIPdu[ipduRef].ComIPduType)
                    && (TRUE == Com_TxIPduRunTimeState[ipduRef].Transmiting))
                {
                    ret = COM_BUSY;
                }
                else
#endif /* (STD_ON == COM_TX_IPDU_TYPE_TP_ENABLE) */
                {
#if (STD_ON == COM_TMS_ENABLE)
                    Com_TxSignalTMHandle(SignalId, ipduRef, SignalDataPtr);
#endif /* (STD_ON == COM_TMS_ENABLE) */
                    /*signalLength is used when the signal type is COM_UINT8_N*/
                    signalLength = txSignalPtr->ComSignalLength;
                    signalBufferId = txSignalPtr->ComSignalInitValueId;
                    /*update tx signal buffer and check if the sending signal value changed*/
                    valueChanged = Com_SetTxSignalBuff(signalType, signalLength, signalBufferId, SignalDataPtr);
                    if (TRUE == valueChanged)
                    {
                        /*pack the Tx signal into ipdu Tx buffer*/
                        Com_TxSignalPack(SignalId);
                    }
#if (STD_ON == COM_TX_SIGNAL_UPDATE_BIT_ENABLE)
                    /*handle update bit function. */
                    updateBitPosition = txSignalPtr->ComUpdateBitPosition;
                    Com_SetSignalUpdateBit(ipduRef, updateBitPosition);
#endif /* (STD_ON == COM_TX_SIGNAL_UPDATE_BIT_ENABLE) */
                    /*the Tx Pdu is enabled*/
                    if (TRUE == Com_TxIPduRunTimeState[ipduRef].ActiveEnable)
                    {
#if (STD_ON == COM_TX_SIGNAL_TIMEOUT_ENABLE)
                        if (0u != txSignalPtr->ComTimeout)
                        {
                            signalIsDM = TRUE;
                        }
                        else
#endif /* (STD_ON == COM_TX_SIGNAL_TIMEOUT_ENABLE) */
                        {
                            signalIsDM = FALSE;
                        }
                        signalTxProperty = txSignalPtr->ComTransferProperty;
                        ret = Com_SendTxSignalHandle(ipduRef, signalTxProperty, signalIsDM, valueChanged);
                    }
/*the Tx Pdu is disabled*/
#if (STD_ON == COM_TX_SIGNAL_ERROR_NOTIFICATION_ENABLE)
                    else
                    {
                        /*call Tx Err Notification*/
                        if (NULL_PTR != txSignalPtr->ComErrorNotification)
                        {
                            txSignalPtr->ComErrorNotification();
                        }
                    }
#endif /* (STD_ON == COM_TX_SIGNAL_ERROR_NOTIFICATION_ENABLE) */
                }
            }
#endif /*0u < COM_TXSIGNAL_NUMBER*/
        }
        /*the signal is Tx Group Signal*/
        else
        {
#if (COM_TXSIGNALGROUP_NUMBER > 0u)
            groupSignalId = SignalId - COM_TXSIGNAL_NUMBER;
            ret = Com_SendTxGroupSignalHandle(groupSignalId, SignalDataPtr);
#endif
        }
#endif /*0u < COM_TXIPDU_NUMBER*/
    }
    COM_NOUSED(SignalId);
    COM_NOUSED(SignalDataPtr);
    return ret;
}
/******************************************************************************/
/*
 * Brief               The service Com_SendDynSignal updates the signal object identified by SignalId
 *                     with the signal referenced by the SignalDataPtr parameter.
 * ServiceId           0x21
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant for the same signal. Reentrant for different signals.
 * Param-Name[in]      SignalId: Id of signal to be sent.
 *                     SignalDataPtr: Reference to the signal data to be transmitted.
 *                     Length: Length of the dynamic length signal
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              uint8(E_OK,E_NOT_OK,COM_SERVICE_NOT_AVAILABLE,COM_BUSY)
 *                     E_OK: service has been accepted
 *                     E_NOT_OK: in case the Length is greater than the configured ComSignalLength of this sent signal
 *                     COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped (or service failed due to
 * development error) COM_BUSY: in case the TP-Buffer is locked
 */
/******************************************************************************/
FUNC(uint8, COM_CODE)
Com_SendDynSignal(Com_SignalIdType SignalId, P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr, uint16 Length)
{
    uint8 ret = COM_SERVICE_NOT_AVAILABLE;
#if (0u < COM_TXIPDU_NUMBER)
#if (0u < COM_TXSIGNAL_NUMBER)
    PduIdType ipduRef;
    Com_TransferPropertyType signalTxProperty;
    boolean valueChanged;
    boolean signalIsDM;
    uint16 signalBufferId;
    uint32 bitPosition;
    uint32 updateBitPosition;
    const Com_TxSignalType* txSignalPtr;
#endif
#if (COM_TXSIGNALGROUP_NUMBER > 0u)
    Com_SignalIdType groupSignalId;
#endif
#endif /*0u < COM_TXIPDU_NUMBER*/
#if (STD_ON == COM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (COM_INIT != Com_Status)
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_SENDDYNSIGNAL_ID, COM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr)
#if (0u < (COM_TXSIGNAL_NUMBER + COM_TXGROUPSIGNAL_NUMBER))
        && (SignalId >= (COM_TXSIGNAL_NUMBER + COM_TXGROUPSIGNAL_NUMBER))
#endif
    )
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_SENDDYNSIGNAL_ID, COM_E_PARAM);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (NULL_PTR == SignalDataPtr))
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_SENDDYNSIGNAL_ID, COM_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if (0u < COM_TXIPDU_NUMBER)
        /*the signal is Tx Signal*/
        if (SignalId < COM_TXSIGNAL_NUMBER)
        {
#if (0u < COM_TXSIGNAL_NUMBER) && (STD_ON == COM_TX_SIGNAL_TYPE_UINT8_DYN_ENABLE)
            txSignalPtr = &Com_ConfigStd->ComTxSignal[SignalId];
            /*signal(not dynamic) isn't send by the API,InitialValueOnly signal don't expect to be called by any API*/
            if ((COM_UINT8_DYN == txSignalPtr->ComSignalType) && (FALSE == txSignalPtr->ComInitialValueOnly))
            {
                ipduRef = txSignalPtr->ComIpduRefIndex;
                /*the IPDU(TP) is sending,return busy*/
#if (STD_ON == COM_TX_IPDU_TYPE_TP_ENABLE)
                if ((COM_PDU_TP == Com_ConfigStd->ComTxIPdu[ipduRef].ComIPduType)
                    && (TRUE == Com_TxIPduRunTimeState[ipduRef].Transmiting))
                {
                    ret = COM_BUSY;
                }
                else
#endif /* (STD_ON == COM_TX_IPDU_TYPE_TP_ENABLE) */
                {
                    if (Length > txSignalPtr->ComSignalLength)
                    {
#if (STD_ON == COM_DEV_ERROR_DETECT)
                        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_SENDDYNSIGNAL_ID, COM_E_PARAM);
#endif
                        ret = E_NOT_OK;
                    }
                    else
                    {
                        signalBufferId = txSignalPtr->ComSignalInitValueId;
                        /*update tx Dyn signal buffer and check if the sending signal value changed*/
                        valueChanged = Com_SetDynTxSignalBuff(ipduRef, signalBufferId, SignalDataPtr, Length);
                        if (TRUE == valueChanged)
                        {
                            bitPosition = txSignalPtr->ComBitPosition;
                            /*pack the Tx Dynamic signal into ipdu Tx buffer*/
                            Com_TxDynSignalPack(ipduRef, bitPosition, signalBufferId, Length);
                            Com_TxIPduRunTimeState[ipduRef].TxIpduLength =
                                (uint16)Com_ConfigStd->ComTxIPdu[ipduRef].IPduNoDynSignalLength + Length;
                        }
#if (STD_ON == COM_TX_SIGNAL_UPDATE_BIT_ENABLE)
                        /*handle update bit function. */
                        updateBitPosition = txSignalPtr->ComUpdateBitPosition;
                        Com_SetSignalUpdateBit(ipduRef, updateBitPosition);
#endif /* (STD_ON == COM_TX_SIGNAL_UPDATE_BIT_ENABLE) */
                        /*the Tx Pdu is enabled*/
                        if (TRUE == Com_TxIPduRunTimeState[ipduRef].ActiveEnable)
                        {
#if (STD_ON == COM_TX_SIGNAL_TIMEOUT_ENABLE)
                            if (0u != txSignalPtr->ComTimeout)
                            {
                                signalIsDM = TRUE;
                            }
                            else
#endif /* (STD_ON == COM_TX_SIGNAL_TIMEOUT_ENABLE) */
                            {
                                signalIsDM = FALSE;
                            }
                            signalTxProperty = txSignalPtr->ComTransferProperty;
                            ret = Com_SendTxSignalHandle(ipduRef, signalTxProperty, signalIsDM, valueChanged);
                        }
                        /*the Tx Pdu is disabled*/
#if (STD_ON == COM_TX_SIGNAL_ERROR_NOTIFICATION_ENABLE)
                        else
                        {
                            /*call Tx Err Notification*/
                            if (NULL_PTR != txSignalPtr->ComErrorNotification)
                            {
                                txSignalPtr->ComErrorNotification();
                            }
                        }
#endif /* (STD_ON == COM_TX_SIGNAL_ERROR_NOTIFICATION_ENABLE) */
                    }
                }
            }
#endif /* (0u < COM_TXSIGNAL_NUMBER) && (STD_ON == COM_TX_SIGNAL_TYPE_UINT8_DYN_ENABLE)*/
        }
        /*the signal is Tx Group Signal*/
        else
        {
#if (COM_TXSIGNALGROUP_NUMBER > 0u) && (STD_ON == COM_TX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE)
            groupSignalId = SignalId - COM_TXSIGNAL_NUMBER;
            ret = Com_SendTxDynGroupSignalHandle(groupSignalId, SignalDataPtr, Length);
#endif /* (COM_TXSIGNALGROUP_NUMBER > 0u) && (STD_ON == COM_TX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE) */
        }
#endif /* (0u < COM_TXIPDU_NUMBER) */
    }
    COM_NOUSED(SignalId);
    COM_NOUSED(SignalDataPtr);
    COM_NOUSED(Length);
    return ret;
}
/******************************************************************************/
/*
 * Brief               Com_ReceiveSignal copies the data of the signal identified by SignalId to the location specified
 * by SignalDataPtr. ServiceId           0x0b Sync/Async          Synchronous Reentrancy          Non Reentrant for the
 * same signal. Reentrant for different signals. Param-Name[in]      SignalId: Id of signal to be received.
 * Param-Name[out]     SignalDataPtr: Reference to the location where the received signal data shall be stored
 * Param-Name[in/out]  None
 * Return              uint8(E_OK,COM_SERVICE_NOT_AVAILABLE,COM_BUSY)
 *                     E_OK: service has been accepted
 *                     COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped (or service failed due to
 * development error) COM_BUSY: in case the TP-Buffer is locked for large data types handling
 */
/******************************************************************************/
FUNC(uint8, COM_CODE)
Com_ReceiveSignal(Com_SignalIdType SignalId, P2VAR(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr)
{
    uint8 ret = COM_SERVICE_NOT_AVAILABLE; /* PRQA S 2981 */ /* MISRA Rule 2.2 */
#if (STD_ON == COM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (COM_INIT != Com_Status)
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_RECEIVESIGNAL_ID, COM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr)
#if (0u < (COM_RXSIGNAL_NUMBER + COM_RXGROUPSIGNAL_NUMBER))
        && (SignalId >= (COM_RXSIGNAL_NUMBER + COM_RXGROUPSIGNAL_NUMBER))
#endif
    )
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_RECEIVESIGNAL_ID, COM_E_PARAM);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (NULL_PTR == SignalDataPtr))
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_RECEIVESIGNAL_ID, COM_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if (0u < COM_RXIPDU_NUMBER)
        /*the signal is Rx Signal*/
        if (SignalId < COM_RXSIGNAL_NUMBER)
        {
#if (0u < COM_RXSIGNAL_NUMBER)
            ret = Com_ReceiveSignalHandle(SignalId, SignalDataPtr);
#endif /*0u < COM_RXSIGNAL_NUMBER*/
        }
        /*the signal is Rx Group Signal*/
        else
        {
#if (0u < COM_RXSIGNALGROUP_NUMBER)
            ret = Com_ReceiveGroupSignalHandle(SignalId, SignalDataPtr);
#endif /*0u < COM_RXSIGNALGROUP_NUMBER*/
        }
#endif /*0u < COM_RXIPDU_NUMBER*/
    }
    COM_NOUSED(SignalId);
    COM_NOUSED(SignalDataPtr);
    return ret;
}
/******************************************************************************/
/*
 * Brief               Com_ReceiveDynSignal copies the data of the signal identified by SignalId to the
 *                     location specified by SignalDataPtr and stores the length of the dynamical length
 *                     signal at the position given by the Length parameter.
 * ServiceId           0x22
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant for the same signal. Reentrant for different signals.
 * Param-Name[in]      SignalId: Id of signal to be received.
 * Param-Name[out]     SignalDataPtr: reference to the location where the received signal data shall be stored
 * Param-Name[in/out]  Length
 *                     in: maximum length that could be received
 *                     out: length of the dynamic length signal
 * Return              uint8(E_OK,E_NOT_OK,COM_SERVICE_NOT_AVAILABLE,COM_BUSY)
 *                     E_OK: service has been accepted
 *                     E_NOT_OK: in case the Length (as in-parameter) is smaller than the received length of the dynamic
 * length signal COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped (or service failed due to development
 * error) COM_BUSY: in case the TP-Buffer is locked
 */
/******************************************************************************/
FUNC(uint8, COM_CODE)
Com_ReceiveDynSignal(
    Com_SignalIdType SignalId,
    P2VAR(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(uint16, AUTOMATIC, COM_APPL_CONST) Length)
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
{
    uint8 ret = COM_SERVICE_NOT_AVAILABLE; /* PRQA S 2981 */ /* MISRA Rule 2.2 */
#if (STD_ON == COM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (COM_INIT != Com_Status)
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_RECEIVEDYNSIGNAL_ID, COM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr)
#if (0u < (COM_RXSIGNAL_NUMBER + COM_RXGROUPSIGNAL_NUMBER))
        && (SignalId >= (COM_RXSIGNAL_NUMBER + COM_RXGROUPSIGNAL_NUMBER))
#endif
    )
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_RECEIVEDYNSIGNAL_ID, COM_E_PARAM);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (NULL_PTR == SignalDataPtr))
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_RECEIVEDYNSIGNAL_ID, COM_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if (0u < COM_RXIPDU_NUMBER)
        /*the signal is Rx Signal*/
        if (SignalId < COM_RXSIGNAL_NUMBER)
        {
#if ((0u < COM_RXSIGNAL_NUMBER) && (0u < COM_SIGNAL_8BITBUFF_SIZE) && (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE))
            ret = Com_ReceiveDynSignalHandle(SignalId, SignalDataPtr, Length);
#endif /* ((0u < COM_RXSIGNAL_NUMBER) && (0u < COM_SIGNAL_8BITBUFF_SIZE) && (STD_ON == \
          COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE)) */
        }
        /*the signal is Rx Group Signal*/
        else
        {
#if ((0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXGROUPSIGNAL_8BITBUFF_SIZE)) \
    && (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE)
            ret = Com_ReceiveDynGroupSignalHandle(SignalId, SignalDataPtr, Length);
#endif /* ((0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXGROUPSIGNAL_8BITBUFF_SIZE) && (STD_ON == \
          COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE)) */
        }
#endif /*0u < COM_RXIPDU_NUMBER*/
    }
    COM_NOUSED(SignalId);
    COM_NOUSED(SignalDataPtr);
    COM_NOUSED(Length);
    return ret;
}
/******************************************************************************/
/*
 * Brief               The service Com_UpdateShadowSignal updates a group signal with the data,referenced by
 * SignalDataPtr. DEPRECATED: This function will be removed in the next major release. (So the API not implement,update
 * group signal is implement in API Com_SendSignal/Com_SendDynSignal) ServiceId           0x0c Sync/Async Synchronous
 * Reentrancy          Non Reentrant for the same group signal. Reentrant for different group signals.
 * Param-Name[in]      SignalId: Id of group signal to be updated.
 *                     SignalDataPtr: Reference to the group signal data to be updated.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, COM_CODE)
Com_UpdateShadowSignal(Com_SignalIdType SignalId, P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr)
{
    COM_NOUSED(SignalId);
    COM_NOUSED(SignalDataPtr);
    return;
}
/******************************************************************************/
/*
 * Brief               The service Com_ReceiveShadowSignal updates the group signal which is referenced by SignalDataPtr
 * with the data in the shadow buffer. DEPRECATED: This function will be removed in the next major release. (So the API
 * not implement,receive group signal is implement in API Com_ReceiveSignal/Com_ReceiveDynSignal) ServiceId 0x0f
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant for the same group signal. Reentrant for different group signals.
 * Param-Name[in]      SignalId: Id of group signal to be received.
 * Param-Name[out]     SignalDataPtr: Reference to the group signal data in which to store the received data.
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, COM_CODE)
Com_ReceiveShadowSignal(Com_SignalIdType SignalId, P2VAR(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr)
{
    COM_NOUSED(SignalId);
    COM_NOUSED(SignalDataPtr);
    return;
}
/******************************************************************************/
/*
 * Brief               The service Com_InvalidateShadowSignal invalidates the group signal with the
 *                     given SignalId by setting its value to its configured ComSignalDataInvalidValue.
 *                     DEPRECATED: This function will be removed in the next major release.
 *                     (So the API not implement,transmit invalidates group signal is implement in Com_InvalidateSignal)
 * ServiceId           0x16
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant for the same group signal. Reentrant for different group signals.
 * Param-Name[in]      SignalId: Id of group signal to be sent.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, COM_CODE)
Com_InvalidateShadowSignal(Com_SignalIdType SignalId)
{
    COM_NOUSED(SignalId);
    return;
}
/******************************************************************************/
/*
 * Brief               The service Com_SendSignalGroup copies the content of the associated shadow buffer to the
 * associated I-PDU. ServiceId           0x0d Sync/Async          Asynchronous Reentrancy          Non Reentrant for the
 * same signal group. Reentrant for different signal groups. Param-Name[in]      SignalGroupId: Id of signal group to be
 * sent. Param-Name[out]     None Param-Name[in/out]  None Return uint8(E_OK,COM_SERVICE_NOT_AVAILABLE,COM_BUSY) E_OK:
 * service has been accepted COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped (or service failed due to
 * development error) COM_BUSY: in case the TP-Buffer is locked for large data types handling
 */
/******************************************************************************/
FUNC(uint8, COM_CODE)
Com_SendSignalGroup(Com_SignalGroupIdType SignalGroupId)
{
    uint8 ret = COM_SERVICE_NOT_AVAILABLE;
#if ((0u < COM_TXSIGNALGROUP_NUMBER) && (0u < COM_TXIPDU_NUMBER))
    PduIdType ipduRef;
    uint16 rptNum;
    boolean initDMCnt = FALSE;
    uint32 updateBitPosition;
    const Com_TxSignalGroupType* txSignalGroupPtr;
    const Com_TxIPduType* txIpduPtr;
    Com_TxIPduRunTimeStateType* txIpduStatePtr;
#endif
#if (STD_ON == COM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (COM_INIT != Com_Status)
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_SENDSIGNALGROUP_ID, COM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr)
#if (0u < COM_TXSIGNALGROUP_NUMBER)
        && (SignalGroupId >= COM_TXSIGNALGROUP_NUMBER)
#endif
    )
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_SENDSIGNALGROUP_ID, COM_E_PARAM);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if ((0u < COM_TXSIGNALGROUP_NUMBER) && (0u < COM_TXIPDU_NUMBER))
        txSignalGroupPtr = &Com_ConfigStd->ComTxSignalGroup[SignalGroupId];
        /*the signal group is configuration ComInitialValueOnly,don't expect to be called by any API*/
#if (STD_ON == COM_TX_SIG_GROUP_INITIAL_VALUE_ONLY_ENABLE)
        if (FALSE == txSignalGroupPtr->ComInitialValueOnly)
#endif /* (STD_ON == COM_TX_SIG_GROUP_INITIAL_VALUE_ONLY_ENABLE) */
        {
            ipduRef = txSignalGroupPtr->ComIpduRefIndex;
            txIpduPtr = &Com_ConfigStd->ComTxIPdu[ipduRef];
            txIpduStatePtr = &Com_TxIPduRunTimeState[ipduRef];
            /*the IPDU(TP) is sending*/
#if (STD_ON == COM_TX_IPDU_TYPE_TP_ENABLE)
            if ((COM_PDU_TP == txIpduPtr->ComIPduType) && (TRUE == txIpduStatePtr->Transmiting))
            {
                ret = COM_BUSY;
            }
            else
#endif /* (STD_ON == COM_TX_IPDU_TYPE_TP_ENABLE) */
            {
                /*pack the Tx signal group into ipdu Tx buffer,copy TxGroupSignalTMCBuffer to TxSignalTMCRunTime*/
                Com_TxSignalGroupPack(SignalGroupId);
                /*update the Tx Pdu length(if the signal group include dynamic group signal)*/
                txIpduStatePtr->TxIpduLength =
                    ((uint16)txIpduPtr->IPduNoDynSignalLength
                     + Com_TxSignalGroupState[SignalGroupId].DynamicSignalLength);
#if (STD_ON == COM_TX_SIG_GROUP_UPDATE_BIT_ENABLE)
                /*handle update bit function. */
                updateBitPosition = txSignalGroupPtr->ComUpdateBitPosition;
                Com_SetSignalUpdateBit(ipduRef, updateBitPosition);
#endif /* (STD_ON == COM_TX_SIG_GROUP_UPDATE_BIT_ENABLE) */
                /*calculate the TMS,store new Tx mode,get rptNum value for DIRECT/MIXED tx mode,if TMS changed will
                 * reset periodic mode counter.*/
                Com_TxIpduTMSHandle(ipduRef, &rptNum);
                /*the Tx Pdu is enabled*/
                if (TRUE == txIpduStatePtr->ActiveEnable)
                {
                    /*the signal group configuration timeout,the DM timer isn't start by other signals/signal groups,Tx
                     * Mode isn't NONE*/
                    if ((0u != txSignalGroupPtr->ComTimeout) && (COM_TX_MODE_NONE != txIpduStatePtr->ipduTxMode)
                        && (0u == txIpduStatePtr->DMCnt))
                    {
                        /*restart the tx DM timer*/
                        txIpduStatePtr->DMCnt = txIpduPtr->ComTxIpduDM;
                        initDMCnt = TRUE;
                    }
#if (STD_ON == COM_TX_MODE_DIRECT_ENABLE) || (STD_ON == COM_TX_MODE_MIXED_ENABLE)
                    if ((COM_TX_MODE_DIRECT == txIpduStatePtr->ipduTxMode)
                        || (COM_TX_MODE_MIXED == txIpduStatePtr->ipduTxMode))
                    {
                        if (TRUE == Com_TxSignalGroupState[SignalGroupId].NTimesTransmitNeed)
                        {
                            txIpduStatePtr->NTimeCnt = 0u;
                            if (TRUE == Com_TxSignalGroupState[SignalGroupId].WithoutRepetition)
                            {
                                txIpduStatePtr->RptNum = 1u;
                            }
                            else
                            {
                                txIpduStatePtr->RptNum = rptNum;
                                /*For an I-PDU with ComTxModeMode DIRECT and ComTxModeNumberOfRepetitions > 0, the
                                  AUTOSAR COM module shall reset an already running transmission deadline monitoring
                                  timer in case another send request for this I-PDU is initiated*/
                                if ((1u < rptNum) && (FALSE == initDMCnt) && (0u != txSignalGroupPtr->ComTimeout))
                                {
                                    txIpduStatePtr->DMCnt = txIpduPtr->ComTxIpduDM;
                                }
                            }
                            Com_TxSignalGroupState[SignalGroupId].NTimesTransmitNeed = FALSE;
                        }
                    }
                    else
#endif /* (STD_ON == COM_TX_MODE_DIRECT_ENABLE) || (STD_ON == COM_TX_MODE_MIXED_ENABLE) */
                    {
                        txIpduStatePtr->NTimeCnt = 0u;
                        txIpduStatePtr->RptNum = 0u;
                    }
                    ret = E_OK;
                }
#if (STD_ON == COM_TX_SIG_GROUP_ERROR_NOTIFICATION_ENABLE)
                else
                {
                    /*call Tx Err Notification*/
                    if (NULL_PTR != txSignalGroupPtr->ComErrorNotification)
                    {
                        txSignalGroupPtr->ComErrorNotification();
                    }
                }
#endif /* (STD_ON == COM_TX_SIG_GROUP_ERROR_NOTIFICATION_ENABLE) */
            }
        }
#endif /*(0u < COM_TXSIGNALGROUP_NUMBER) && (0u < COM_TXIPDU_NUMBER)*/
    }
    COM_NOUSED(SignalGroupId);
    return ret;
}
/******************************************************************************/
/*
 * Brief               The service Com_ReceiveSignalGroup copies the received signal group from the I-PDU to the shadow
 * buffer. ServiceId           0x0e Sync/Async          Synchronous Reentrancy          Non Reentrant for the same
 * signal group. Reentrant for different signal groups. Param-Name[in]      SignalGroupId: Id of signal group to be
 * received. Param-Name[out]     None Param-Name[in/out]  None Return uint8(E_OK,COM_SERVICE_NOT_AVAILABLE,COM_BUSY)
 *                     E_OK: service has been accepted
 *                     COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped (or service failed due to
 * development error) COM_BUSY: in case the TP-Buffer is locked for large data types handling
 */
/******************************************************************************/
FUNC(uint8, COM_CODE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
Com_ReceiveSignalGroup(Com_SignalGroupIdType SignalGroupId)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
    uint8 ret = COM_SERVICE_NOT_AVAILABLE;
#if ((0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXIPDU_NUMBER))
    PduIdType ipduRef;
#endif
#if (STD_ON == COM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (COM_INIT != Com_Status)
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_RECEIVESIGNALGROUP_ID, COM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr)
#if (0u < COM_RXSIGNALGROUP_NUMBER)
        && (SignalGroupId >= COM_RXSIGNALGROUP_NUMBER)
#endif
    )
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_RECEIVESIGNALGROUP_ID, COM_E_PARAM);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if ((0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXIPDU_NUMBER))
        ipduRef = Com_ConfigStd->ComRxSignalGroup[SignalGroupId].ComIpduRefIndex;
        /*IPDU is receiving data*/
        if (TRUE == Com_RxIPduRunTimeState[ipduRef].Receiving)
        {
            ret = COM_BUSY;
        }
        else
        {
            Com_ReceiveSignalGroupHandle(ipduRef, SignalGroupId);
            if (TRUE == Com_RxIPduRunTimeState[ipduRef].ActiveEnable)
            {
                ret = E_OK;
            }
        }
#endif /*(0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXIPDU_NUMBER)*/
    }
    COM_NOUSED(SignalGroupId);
    return ret;
}
/******************************************************************************/
/*
 * Brief               The service Com_SendSignalGroupArray copies the content of the provided
 *                     SignalGroupArrayPtr to the associated I-PDU. The provided data shall
 *                     correspond to the array representation of the signal group.
 * ServiceId           0x23
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant for the same signal group. Reentrant for different signal groups.
 * Param-Name[in]      SignalGroupId: Id of signal group to be sent.
 *                     SignalGroupArrayPtr: Reference to the signal group array.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              uint8(E_OK,COM_SERVICE_NOT_AVAILABLE,COM_BUSY)
 *                     E_OK: service has been accepted
 *                     COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped (or service failed due to
 * development error) COM_BUSY: in case the TP-Buffer is locked for large data types handling
 */
/******************************************************************************/
#if (STD_ON == COM_ENABLE_SIGNAL_GROUP_ARRAY_API)
FUNC(uint8, COM_CODE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
Com_SendSignalGroupArray(
    Com_SignalGroupIdType SignalGroupId,
    P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) SignalGroupArrayPtr)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
    uint8 ret = COM_SERVICE_NOT_AVAILABLE;
#if ((0u < COM_TXSIGNALGROUP_NUMBER) && (0u < COM_TXIPDU_NUMBER))
    PduIdType ipduRef;
#if (0u < COM_TXIPDUBUFF_SIZE)
    uint16 iPduSignalGroupArrayStartBufId;
    uint16 signalGroupArrayLength;
    uint16 cnt;
#endif
    uint16 txIPduBufferId;
    Com_SignalIdType groupSignalNumber;
    boolean triggerOnChange;
    uint16 rptNum;
    uint32 updateBitPosition;
    const Com_TxSignalGroupType* txSignalGroupPtr;
#endif
#if (STD_ON == COM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (COM_INIT != Com_Status)
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_SENDSIGNALGROUPARRAY_ID, COM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr)
#if (0u < COM_TXSIGNALGROUP_NUMBER)
        && (SignalGroupId >= COM_TXSIGNALGROUP_NUMBER)
#endif
    )
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_SENDSIGNALGROUPARRAY_ID, COM_E_PARAM);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (NULL_PTR == SignalGroupArrayPtr))
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_SENDSIGNALGROUPARRAY_ID, COM_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if ((0u < COM_TXSIGNALGROUP_NUMBER) && (0u < COM_TXIPDU_NUMBER))
        txSignalGroupPtr = &Com_ConfigStd->ComTxSignalGroup[SignalGroupId];
        /*the signal group isn't InitialValueOnly,the signal group is array*/
        if ((FALSE == txSignalGroupPtr->ComInitialValueOnly) && (NULL_PTR != txSignalGroupPtr->ComSignalGroupArray))
        {
            ipduRef = txSignalGroupPtr->ComIpduRefIndex;
            /*the IPDU(TP) is sending*/
#if (STD_ON == COM_TX_IPDU_TYPE_TP_ENABLE)
            if ((COM_PDU_TP == Com_ConfigStd->ComTxIPdu[ipduRef].ComIPduType)
                && (TRUE == Com_TxIPduRunTimeState[ipduRef].Transmiting))
            {
                ret = COM_BUSY;
            }
            else
#endif /* (STD_ON == COM_TX_IPDU_TYPE_TP_ENABLE) */
            {
#if (0u < COM_TXIPDUBUFF_SIZE)
                iPduSignalGroupArrayStartBufId = txSignalGroupPtr->ComSignalGroupArray->ComIPduStartBufIndex;
                signalGroupArrayLength = txSignalGroupPtr->ComSignalGroupArray->SignalGroupArrayLength;
                /*pack the Tx signal group(array) into ipdu Tx buffer*/
                for (cnt = 0u; cnt < signalGroupArrayLength; cnt++)
                {
                    Com_TxIPduRuntimeBuff[iPduSignalGroupArrayStartBufId + cnt] = SignalGroupArrayPtr[cnt];
                }
#endif
#if (STD_ON == COM_TX_SIG_GROUP_UPDATE_BIT_ENABLE)
                /*set the update bit if the signal group configuration */
                updateBitPosition = txSignalGroupPtr->ComUpdateBitPosition;
                Com_SetSignalUpdateBit(ipduRef, updateBitPosition);
#endif /* (STD_ON == COM_TX_SIG_GROUP_UPDATE_BIT_ENABLE) */
                txIPduBufferId = Com_ConfigStd->ComTxIPdu[ipduRef].ComTxIPduBufIndex;
                groupSignalNumber = txSignalGroupPtr->ComGroupSignalNumber;
                /*update every group signal buffer,calculate every TMC,return the signal group is changed or not for
                 * trigger transmit*/
                triggerOnChange = Com_UpdateTxBufferAndCalculateTMCOfEveryGroupSignal(
                    SignalGroupId,
                    groupSignalNumber,
                    txIPduBufferId);
                /*calculate the TMS,store new Tx mode,get rptNum value for DIRECT/MIXED tx mode,if TMS changed will
                 * reset periodic mode counter.*/
                Com_TxIpduTMSHandle(ipduRef, &rptNum);
                if (TRUE == Com_TxIPduRunTimeState[ipduRef].ActiveEnable)
                {
                    Com_SendSignalGroupArrayHandle(SignalGroupId, ipduRef, triggerOnChange, rptNum);
                    ret = E_OK;
                }
#if (STD_ON == COM_TX_SIG_GROUP_ERROR_NOTIFICATION_ENABLE)
                else
                {
                    /*call Tx Err Notification*/
                    if (NULL_PTR != txSignalGroupPtr->ComErrorNotification)
                    {
                        txSignalGroupPtr->ComErrorNotification();
                    }
                }
#endif /* (STD_ON == COM_TX_SIG_GROUP_ERROR_NOTIFICATION_ENABLE) */
            }
        }
#endif /*(0u < COM_TXSIGNALGROUP_NUMBER) && (0u < COM_TXIPDU_NUMBER)*/
    }
    COM_NOUSED(SignalGroupId);
    COM_NOUSED(SignalGroupArrayPtr);
    return ret;
}
#endif /* (STD_ON == COM_ENABLE_SIGNAL_GROUP_ARRAY_API) */
/******************************************************************************/
/*
 * Brief               The service Com_ReceiveSignalGroupArray copies the received signal group
 *                     array representation from the PDU to the location designated by SignalGroupArrayPtr.
 * ServiceId           0x24
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant for the same signal group. Reentrant for different signal groups.
 * Param-Name[in]      SignalGroupId: Id of signal group to be received.
 * Param-Name[out]     SignalGroupArrayPtr: reference to the location where the received signal group array shall be
 * stored. Param-Name[in/out]  None Return              uint8(E_OK,COM_SERVICE_NOT_AVAILABLE,COM_BUSY) E_OK: service has
 * been accepted COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped (or service failed due to development
 * error) COM_BUSY: in case the TP-Buffer is locked for large data types handling
 */
/******************************************************************************/
#if (STD_ON == COM_ENABLE_SIGNAL_GROUP_ARRAY_API)
FUNC(uint8, COM_CODE)
/* PRQA S 3432,1532 ++ */ /* MISRA Rule 20.7,8.7 */
Com_ReceiveSignalGroupArray(
    Com_SignalGroupIdType SignalGroupId,
    P2VAR(uint8, AUTOMATIC, COM_APPL_CONST) SignalGroupArrayPtr)
/* PRQA S 3432,1532 -- */ /* MISRA Rule 20.7,8.7 */
{
    uint8 ret = COM_SERVICE_NOT_AVAILABLE;
#if ((0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXIPDU_NUMBER))
    PduIdType ipduRef;
    uint16 iPduSignalGroupArrayStartBufId;
    uint16 signalGroupArrayLength;
    uint16 cnt;
    const Com_RxSignalGroupType* rxSignalGroupPtr;
#endif
#if (STD_ON == COM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (COM_INIT != Com_Status)
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_RECEIVESIGNALGROUPARRAY_ID, COM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr)
#if (0u < COM_RXSIGNALGROUP_NUMBER)
        && (SignalGroupId >= COM_RXSIGNALGROUP_NUMBER)
#endif
    )
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_RECEIVESIGNALGROUPARRAY_ID, COM_E_PARAM);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (NULL_PTR == SignalGroupArrayPtr))
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_RECEIVESIGNALGROUPARRAY_ID, COM_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if ((0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXIPDU_NUMBER))
        rxSignalGroupPtr = &Com_ConfigStd->ComRxSignalGroup[SignalGroupId];
        /*the signal group is array*/
        if (NULL_PTR != rxSignalGroupPtr->ComSignalGroupArray)
        {
            ipduRef = rxSignalGroupPtr->ComIpduRefIndex;
            /*the I-Pdu is receiving,cann't copy data*/
            if (TRUE == Com_RxIPduRunTimeState[ipduRef].Receiving)
            {
                ret = COM_BUSY;
            }
            else
            {
                iPduSignalGroupArrayStartBufId = rxSignalGroupPtr->ComSignalGroupArray->ComIPduStartBufIndex;
                signalGroupArrayLength = rxSignalGroupPtr->ComSignalGroupArray->SignalGroupArrayLength;
                for (cnt = 0u; cnt < signalGroupArrayLength; cnt++)
                {
                    SignalGroupArrayPtr[cnt] = Com_RxIPduRuntimeBuff[iPduSignalGroupArrayStartBufId + cnt];
                }
                if (TRUE == Com_RxIPduRunTimeState[ipduRef].ActiveEnable)
                {
                    ret = E_OK;
                }
            }
        }
#endif /*(0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXIPDU_NUMBER)*/
    }
    COM_NOUSED(SignalGroupId);
    COM_NOUSED(SignalGroupArrayPtr);
    return ret;
}
#endif /*STD_ON == COM_ENABLE_SIGNAL_GROUP_ARRAY_API*/
/******************************************************************************/
/*
 * Brief               The service Com_InvalidateSignal invalidates the signal with the given SignalId
 *                     by setting its value to its configured ComSignalDataInvalidValue.
 * ServiceId           0x10
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant for the same signal. Reentrant for different signals.
 * Param-Name[in]      SignalId: Id of signal to be invalidated.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              uint8(E_OK,COM_SERVICE_NOT_AVAILABLE,COM_BUSY)
 *                     E_OK: service has been accepted
 *                     COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group is stopped, no ComSignalDataInvalidValue
 *                     is configured for the given signalId or service fails due to development error
 *                     COM_BUSY: in case the TP-Buffer is locked
 */
/******************************************************************************/
FUNC(uint8, COM_CODE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
Com_InvalidateSignal(Com_SignalIdType SignalId)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
    uint8 ret = COM_SERVICE_NOT_AVAILABLE;
#if ((0u < COM_TXSIGNAL_NUMBER) && (0u < COM_TXIPDU_NUMBER))
    Com_SignalType signalType;
    uint16 invalidValueId;
    const Com_TxSignalType* txSignalPtr;
#if (0u < COM_SIGNAL_8BIT_INVALID_SIZE)
    uint16 invalidValueLength;
#endif
#endif
#if (STD_ON == COM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (COM_INIT != Com_Status)
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_INVALIDATESIGNAL_ID, COM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr)
#if (0u < COM_TXSIGNAL_NUMBER)
        && (SignalId >= COM_TXSIGNAL_NUMBER)
#endif
    )
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_INVALIDATESIGNAL_ID, COM_E_PARAM);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if ((0u < COM_TXSIGNAL_NUMBER) && (0u < COM_TXIPDU_NUMBER))
        txSignalPtr = &Com_ConfigStd->ComTxSignal[SignalId];
        signalType = txSignalPtr->ComSignalType;
        invalidValueId = txSignalPtr->ComSignalDataInvalidValueId;
        if ((COM_UNUSED_UINT16 != invalidValueId) && (TRUE != txSignalPtr->ComInitialValueOnly))
        {
#if (STD_ON == COM_TX_SIGNAL_TYPE_UINT8_DYN_ENABLE)
            if (COM_UINT8_DYN == signalType)
            {
#if (0u < COM_SIGNAL_8BIT_INVALID_SIZE)
                invalidValueLength = txSignalPtr->ComSignalDataInvalidValueLength;
                /*send signal use configuration invalidate value */
                ret = Com_SendDynSignal(SignalId, &(Com_Signal8BitInvalidValue[invalidValueId]), invalidValueLength);
#endif
            }
            else
#endif /* (STD_ON == COM_TX_SIGNAL_TYPE_UINT8_DYN_ENABLE) */
            {
                switch (signalType)
                {
/*send signal use configuration invalidate value */
#if (0u < COM_SIGNAL_BOOL_INVALID_SIZE)
                case COM_BOOLEAN:
                    ret = Com_SendSignal(SignalId, &(Com_SignalBoolInvalidValue[invalidValueId]));
                    break;
#endif
#if (0u < COM_SIGNAL_8BIT_INVALID_SIZE)
                case COM_SINT8:
                case COM_UINT8:
                case COM_UINT8_N:
                    ret = Com_SendSignal(SignalId, &(Com_Signal8BitInvalidValue[invalidValueId]));
                    break;
#endif
#if (0u < COM_SIGNAL_16BIT_INVALID_SIZE)
                case COM_SINT16:
                case COM_UINT16:
                    ret = Com_SendSignal(SignalId, &(Com_Signal16BitInvalidValue[invalidValueId]));
                    break;
#endif
#if (0u < COM_SIGNAL_32BIT_INVALID_SIZE)
                case COM_SINT32:
                case COM_UINT32:
                case COM_FLOAT32:
                    ret = Com_SendSignal(SignalId, &(Com_Signal32BitInvalidValue[invalidValueId]));
                    break;
#endif
#if (0u < COM_SIGNAL_64BIT_INVALID_SIZE)
                case COM_SINT64:
                case COM_UINT64:
                case COM_FLOAT64:
                    ret = Com_SendSignal(SignalId, &(Com_Signal64BitInvalidValue[invalidValueId]));
                    break;
#endif
                default:
                    /*do nothing*/
                    break;
                }
            }
        }
#endif /*(0u < COM_TXSIGNAL_NUMBER) && (0u < COM_TXIPDU_NUMBER)*/
    }
    COM_NOUSED(SignalId);
    return ret;
}
/******************************************************************************/
/*
 * Brief               The service Com_InvalidateSignalGroup invalidates all group signals of the signal
 *                     group with the given SignalGroupId by setting their values to their configured
 *                     ComSignalDataInvalidValues.
 * ServiceId           0x1b
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant for the same signal group. Reentrant for different signal groups.
 * Param-Name[in]      SignalGroupId: Id of signal group to be invalidated.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              uint8(E_OK,COM_SERVICE_NOT_AVAILABLE,COM_BUSY)
 *                     E_OK: service has been accepted
 *                     COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group is stopped, no ComSignalDataInvalidValue
 *                     is configured for any of the group signals or service fails due to development error
 *                     COM_BUSY: in case the TP-Buffer is locked
 */
/******************************************************************************/
FUNC(uint8, COM_CODE)
Com_InvalidateSignalGroup(Com_SignalGroupIdType SignalGroupId)
{
    uint8 ret = COM_SERVICE_NOT_AVAILABLE;
#if (0u < COM_TXSIGNALGROUP_NUMBER)
    PduIdType ipduRef;
    Com_SignalIdType groupSignalNumber;
    Com_SignalIdType cnt;
    Com_SignalIdType groupSignalId;
    Com_SignalType signalType;
    uint16 invalidValueId;
    const Com_TxSignalGroupType* txSignalGroupPtr;
    const Com_TxGroupSignalType* txGroupSignalPtr;
#if (0u < COM_SIGNAL_8BIT_INVALID_SIZE) && (STD_ON == COM_TX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE)
    uint16 invalidValueLength;
#endif /* #if (0u < COM_SIGNAL_8BIT_INVALID_SIZE) && (STD_ON == COM_TX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE) */
#endif
#if (STD_ON == COM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (COM_INIT != Com_Status)
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_INVALIDATESIGNALGROUP_ID, COM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr)
#if (0u < COM_TXSIGNALGROUP_NUMBER)
        && (SignalGroupId >= COM_TXSIGNALGROUP_NUMBER)
#endif
    )
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_INVALIDATESIGNALGROUP_ID, COM_E_PARAM);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if (0u < COM_TXSIGNALGROUP_NUMBER)
        txSignalGroupPtr = &Com_ConfigStd->ComTxSignalGroup[SignalGroupId];
/*the signal group is InitialValueOnly,don't expect to be called by any API*/
#if (STD_ON == COM_TX_SIG_GROUP_INITIAL_VALUE_ONLY_ENABLE)
        if (TRUE != txSignalGroupPtr->ComInitialValueOnly)
#endif /* (STD_ON == COM_TX_SIG_GROUP_INITIAL_VALUE_ONLY_ENABLE) */
        {
            ipduRef = txSignalGroupPtr->ComIpduRefIndex;
            /*the IPDU(TP) is sending,return busy*/
#if (STD_ON == COM_TX_IPDU_TYPE_TP_ENABLE)
            if ((COM_PDU_TP == Com_ConfigStd->ComTxIPdu[ipduRef].ComIPduType)
                && (TRUE == Com_TxIPduRunTimeState[ipduRef].Transmiting))
            {
                ret = COM_BUSY;
            }
            else
#endif /* (STD_ON == COM_TX_IPDU_TYPE_TP_ENABLE) */
            {
                groupSignalNumber = txSignalGroupPtr->ComGroupSignalNumber;
                for (cnt = 0u; cnt < groupSignalNumber; cnt++)
                {
                    groupSignalId = txSignalGroupPtr->ComTxGroupSignalId[cnt];
                    txGroupSignalPtr = &Com_ConfigStd->ComTxGroupSignal[groupSignalId];
                    signalType = txGroupSignalPtr->ComSignalType;
                    invalidValueId = txGroupSignalPtr->ComSignalDataInvalidValueId;
                    if (COM_UNUSED_UINT16 != invalidValueId)
                    {
#if (STD_ON == COM_TX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE)
                        if (COM_UINT8_DYN == signalType)
                        {
#if (0u < COM_SIGNAL_8BIT_INVALID_SIZE)
                            invalidValueLength = txGroupSignalPtr->ComSignalDataInvalidValueLength;
                            /*send dynamic group signal use configuration invalidate value */
                            (void)Com_SendTxDynGroupSignalHandle(
                                groupSignalId,
                                &(Com_Signal8BitInvalidValue[invalidValueId]),
                                invalidValueLength);
#endif
                        }
                        else
#endif /* (STD_ON == COM_TX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE) */
                        {
                            switch (signalType)
                            {
/*send group signal use configuration invalidate value */
#if (0u < COM_SIGNAL_BOOL_INVALID_SIZE)
                            case COM_BOOLEAN:
                                (void)Com_SendTxGroupSignalHandle(
                                    groupSignalId,
                                    &(Com_SignalBoolInvalidValue[invalidValueId]));
                                break;
#endif
#if (0u < COM_SIGNAL_8BIT_INVALID_SIZE)
                            case COM_SINT8:
                            case COM_UINT8:
                            case COM_UINT8_N:
                                (void)Com_SendTxGroupSignalHandle(
                                    groupSignalId,
                                    &(Com_Signal8BitInvalidValue[invalidValueId]));
                                break;
#endif
#if (0u < COM_SIGNAL_16BIT_INVALID_SIZE)
                            case COM_SINT16:
                            case COM_UINT16:
                                (void)Com_SendTxGroupSignalHandle(
                                    groupSignalId,
                                    &(Com_Signal16BitInvalidValue[invalidValueId]));
                                break;
#endif
#if (0u < COM_SIGNAL_32BIT_INVALID_SIZE)
                            case COM_SINT32:
                            case COM_UINT32:
                            case COM_FLOAT32:
                                (void)Com_SendTxGroupSignalHandle(
                                    groupSignalId,
                                    &(Com_Signal32BitInvalidValue[invalidValueId]));
                                break;
#endif
#if (0u < COM_SIGNAL_64BIT_INVALID_SIZE)
                            case COM_SINT64:
                            case COM_UINT64:
                            case COM_FLOAT64:
                                (void)Com_SendTxGroupSignalHandle(
                                    groupSignalId,
                                    &(Com_Signal64BitInvalidValue[invalidValueId]));
                                break;
#endif
                            default:
                                /*do nothing*/
                                break;
                            }
                        }
                    }
                }
                ret = Com_SendSignalGroup(SignalGroupId);
            }
        }
#endif /*(0u < COM_TXSIGNALGROUP_NUMBER) */
    }
    COM_NOUSED(SignalGroupId);
    return ret;
}
/******************************************************************************/
/*
 * Brief               By a call to Com_TriggerIPDUSend the I-PDU with the given ID is triggered for transmission.
 * ServiceId           0x17
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      PduId: The I-PDU-ID of the I-PDU that shall be triggered for sending
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: I-PDU was triggered for transmission
 *                     E_NOT_OK: I-PDU is stopped, the transmission could not be triggered
 */
/******************************************************************************/
FUNC(Std_ReturnType, COM_CODE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
Com_TriggerIPDUSend(PduIdType PduId)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
    Std_ReturnType returnValue = E_NOT_OK;
#if (0u < COM_TXIPDU_NUMBER)
    PduIdType txIpduId;
#endif
#if (STD_ON == COM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (COM_INIT != Com_Status)
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_TRIGGERIPDUSEND_ID, COM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && ((PduId >= (COM_RXIPDU_NUMBER + COM_TXIPDU_NUMBER)) || (PduId < COM_RXIPDU_NUMBER)))
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_TRIGGERIPDUSEND_ID, COM_E_PARAM);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if (0u < COM_TXIPDU_NUMBER)
        txIpduId = PduId - COM_RXIPDU_NUMBER;
        /*In case a stopped I-PDU is triggered for transmission, just E_NOT_OK is returned.*/
        if (TRUE == Com_TxIPduRunTimeState[txIpduId].ActiveEnable)
        {
            /*the transmit is delay by MDT or the pdu is transmitting*/
            if (
#if (STD_ON == COM_MDT_ENABLE)
                (0u < Com_TxIPduRunTimeState[txIpduId].MDTCnt) ||
#endif /* (STD_ON == COM_MDT_ENABLE) */
                (TRUE == Com_TxIPduRunTimeState[txIpduId].Transmiting))
            {
                Com_TxIPduRunTimeState[txIpduId].TxDelay = TRUE;
                returnValue = E_OK;
            }
            else
            {
                returnValue = Com_TriggerIPDUSendHandle(txIpduId);
            }
        }
        else
        {
#if (STD_ON == COM_TX_SIGNAL_ERROR_NOTIFICATION_ENABLE) || (STD_ON == COM_TX_SIG_GROUP_ERROR_NOTIFICATION_ENABLE)
            Com_InvokeErrorNotification(txIpduId);
#endif /* (STD_ON == COM_TX_SIGNAL_ERROR_NOTIFICATION_ENABLE) || (STD_ON == \
          COM_TX_SIG_GROUP_ERROR_NOTIFICATION_ENABLE) */
        }
#endif /*0u < COM_TXIPDU_NUMBER*/
    }
    COM_NOUSED(PduId);
    return returnValue;
}
/******************************************************************************/
/*
 * Brief               By a call to Com_TriggerIPDUSendWithMetaData the AUTOSAR COM module
 *                     updates its internal metadata for the I-PDU with the given ID by copying the
 *                     metadata from the given position and with respect to the globally configured metadata
 *                     length of the I-PDU. Then the I-PDU is triggered for transmission.
 * ServiceId           0x28
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      PduId: The I-PDU-ID of the I-PDU that shall be triggered for sending
 *                     MetaData: A pointer to the metadata for the triggered send-request
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: I-PDU was triggered for transmission
 *                     E_NOT_OK: I-PDU is stopped, the transmission could not be triggered
 */
/******************************************************************************/
#if (STD_ON == COM_METADATA_SUPPORT)
FUNC(Std_ReturnType, COM_CODE)
/* PRQA S 3432,1532 ++ */ /* MISRA Rule 20.7,8.7 */
Com_TriggerIPDUSendWithMetaData(PduIdType PduId, P2VAR(uint8, AUTOMATIC, COM_APPL_CONST) MetaData)
/* PRQA S 3432,1532 -- */ /* MISRA Rule 20.7,8.7 */
{
    Std_ReturnType returnValue = E_NOT_OK;
#if (0u < COM_TXIPDU_NUMBER)
    PduIdType txIpduId;
    uint16 ipduBufferId;
    uint16 metaDataStartId;
    uint8 metaDataLength;
    uint8 cnt;
    const Com_TxIPduType* txIpduPtr;
#endif
#if (STD_ON == COM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (COM_INIT != Com_Status)
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_TRIGGERIPDUSENDWITHMETADATA_ID, COM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && ((PduId >= (COM_RXIPDU_NUMBER + COM_TXIPDU_NUMBER)) || (PduId < COM_RXIPDU_NUMBER)))
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_TRIGGERIPDUSENDWITHMETADATA_ID, COM_E_PARAM);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr)
        && ((0u == Com_ConfigStd->ComTxIPdu[PduId - COM_RXIPDU_NUMBER].MetaDataLength) || (NULL_PTR == MetaData)))
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_TRIGGERIPDUSENDWITHMETADATA_ID, COM_E_PARAM);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if (0u < COM_TXIPDU_NUMBER)
        txIpduId = PduId - COM_RXIPDU_NUMBER;
        /*In case a stopped I-PDU is triggered for transmission, just E_NOT_OK is returned.*/
        if (TRUE == Com_TxIPduRunTimeState[txIpduId].ActiveEnable)
        {
            txIpduPtr = &Com_ConfigStd->ComTxIPdu[txIpduId];
            ipduBufferId = txIpduPtr->ComTxIPduBufIndex;
            metaDataLength = txIpduPtr->MetaDataLength;
            metaDataStartId =
                (uint16)txIpduPtr->IPduNoDynSignalLength + (uint16)txIpduPtr->IPduMaxDynSignalLength + ipduBufferId;
            /*update the metadata of the tx ipdu*/
            for (cnt = 0u; cnt < metaDataLength; cnt++)
            {
                Com_TxIPduRuntimeBuff[metaDataStartId + cnt] = MetaData[cnt];
            }
            /*the transmit is delay by MDT or the pdu is transmitting*/
            if (
#if (STD_ON == COM_MDT_ENABLE)
                (0u < Com_TxIPduRunTimeState[txIpduId].MDTCnt) ||
#endif /* (STD_ON == COM_MDT_ENABLE) */
                (TRUE == Com_TxIPduRunTimeState[txIpduId].Transmiting))
            {
                Com_TxIPduRunTimeState[txIpduId].TxDelay = TRUE;
                returnValue = E_OK;
            }
            else
            {
                returnValue = Com_TriggerIPDUSendHandle(txIpduId);
            }
        }
        else
        {
#if (STD_ON == COM_TX_SIGNAL_ERROR_NOTIFICATION_ENABLE) || (STD_ON == COM_TX_SIG_GROUP_ERROR_NOTIFICATION_ENABLE)
            Com_InvokeErrorNotification(txIpduId);
#endif /* (STD_ON == COM_TX_SIGNAL_ERROR_NOTIFICATION_ENABLE) || (STD_ON == \
          COM_TX_SIG_GROUP_ERROR_NOTIFICATION_ENABLE) */
        }
#endif /*0u < COM_TXIPDU_NUMBER*/
    }
    COM_NOUSED(PduId);
    COM_NOUSED(MetaData);
    return returnValue;
}
#endif /*STD_ON == COM_METADATA_SUPPORT*/
/******************************************************************************/
/*
 * Brief               The service Com_SwitchIpduTxMode sets the transmission mode of the I-PDU referenced by PduId to
 * Mode. In case the transmission mode changes, the new mode shall immediately be effective. In case the requested
 * transmission mode was already active for this I-PDU, the call will have no effect. ServiceId           0x27
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different PduIds. Non reentrant for the same PduId.
 * Param-Name[in]      PduId: Id of the I-PDU of which the transmission mode shall be changed.
 *                     Mode: the transmission mode that shall be set.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, COM_CODE)
Com_SwitchIpduTxMode(PduIdType PduId, boolean Mode) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
#if (0u < COM_TXIPDU_NUMBER)
    PduIdType txIpduId;
    const Com_TxIPduType* txIpduPtr;
#endif
#if (STD_ON == COM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (COM_INIT != Com_Status)
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_SWITCHIPDUTXMODE_ID, COM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && ((PduId >= (COM_RXIPDU_NUMBER + COM_TXIPDU_NUMBER)) || (PduId < COM_RXIPDU_NUMBER)))
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_SWITCHIPDUTXMODE_ID, COM_E_PARAM);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if (0u < COM_TXIPDU_NUMBER)
        txIpduId = PduId - COM_RXIPDU_NUMBER;
        txIpduPtr = &Com_ConfigStd->ComTxIPdu[txIpduId];
#if (STD_ON == COM_TMS_ENABLE)
        if (NULL_PTR != txIpduPtr->ComTxModeFalse)
        {
            if (TRUE == Mode)
            {
                if (FALSE == Com_TxIPduRunTimeState[txIpduId].TMS)
#endif /* (STD_ON == COM_TMS_ENABLE) */
                {
                    Com_TxIPduRunTimeState[txIpduId].TMS = TRUE;
                    Com_TxIPduRunTimeState[txIpduId].ipduTxMode = txIpduPtr->ComTxModeTrue->ComTxModeMode;
                    Com_TxIPduRunTimeState[txIpduId].PeriodCnt = txIpduPtr->ComTxModeTrue->ComTxModeTimeOffset;
                    Com_TxIPduRunTimeState[txIpduId].NTimeCnt = 0u;
                    Com_TxIPduRunTimeState[txIpduId].RptNum = 0u;
                }
#if (STD_ON == COM_TMS_ENABLE)
            }
            else
            {
                if (TRUE == Com_TxIPduRunTimeState[txIpduId].TMS)
                {
                    Com_TxIPduRunTimeState[txIpduId].TMS = FALSE;
                    Com_TxIPduRunTimeState[txIpduId].ipduTxMode = txIpduPtr->ComTxModeFalse->ComTxModeMode;
                    Com_TxIPduRunTimeState[txIpduId].PeriodCnt = txIpduPtr->ComTxModeFalse->ComTxModeTimeOffset;
                    Com_TxIPduRunTimeState[txIpduId].NTimeCnt = 0u;
                    Com_TxIPduRunTimeState[txIpduId].RptNum = 0u;
                }
            }
        }
#endif /* (STD_ON == COM_TMS_ENABLE) */
#endif /*0u < COM_TXIPDU_NUMBER*/
    }
    COM_NOUSED(PduId);
    COM_NOUSED(Mode);
    return;
}
/******************************************************************************/
/*
 * Brief               This function performs the processing of the AUTOSAR COM module's receive processing that
 *                     are not directly handled within the COM's functions invoked by the PDU-R, for example
 * Com_RxIndication. ServiceId           0x18 Sync/Async          None Reentrancy          None Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, COM_CODE)
Com_MainFunctionRx(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
#if (0u < COM_RXIPDU_NUMBER)
    PduIdType rxIpduId;
    Com_RxIPduRunTimeStateType* rxIpduStatePtr;
#endif /*0u < COM_RXIPDU_NUMBER*/
    if (COM_INIT == Com_Status)
    {
#if (0u < COM_RXIPDU_NUMBER)
        for (rxIpduId = 0u; rxIpduId < COM_RXIPDU_NUMBER; rxIpduId++)
        {
            rxIpduStatePtr = &Com_RxIPduRunTimeState[rxIpduId];
            if (TRUE == rxIpduStatePtr->ActiveEnable)
            {
                /*signal/signal group RxIndication is DEFERRED in the MainFunctionRx*/
                if (TRUE == rxIpduStatePtr->RxIndication)
                {
                    /*rx indication handle*/
                    Com_IndicationProcess(rxIpduId);
                    rxIpduStatePtr->RxIndication = FALSE;
                    /*the rx pdu include signal/signal group which need gateway*/
#if (STD_ON == COM_SIGNAL_GW_ENABLE)
                    if (TRUE == Com_ConfigStd->ComRxIPdu[rxIpduId].IPduGW)
                    {
                        rxIpduStatePtr->NeedGW = TRUE;
                    }
#endif /* (STD_ON == COM_SIGNAL_GW_ENABLE) */
                }
                /*if the rx DM is enabled*/
#if (STD_ON == COM_RX_SIGNAL_TIMEOUT_ENABLE) || (STD_ON == COM_RX_SIG_GROUP_TIMEOUT_ENABLE)
                if (TRUE == rxIpduStatePtr->DMEnable)
                {
#if (COM_RXSIGNAL_NUMBER > 0u) && (STD_ON == COM_RX_SIGNAL_TIMEOUT_ENABLE)
                    Com_RxSignalTimeOutHandle(rxIpduId);
#endif /* (COM_RXSIGNAL_NUMBER > 0u) && (STD_ON == COM_RX_SIGNAL_TIMEOUT_ENABLE) */

#if (COM_RXSIGNALGROUP_NUMBER > 0u) && (STD_ON == COM_RX_SIG_GROUP_TIMEOUT_ENABLE)
                    Com_RxSignalGroupTimeOutHandle(rxIpduId);
#endif /* (COM_RXSIGNALGROUP_NUMBER > 0u) && (STD_ON == COM_RX_SIG_GROUP_TIMEOUT_ENABLE) */
                }
#endif /* (STD_ON == COM_RX_SIGNAL_TIMEOUT_ENABLE) || (STD_ON == COM_RX_SIG_GROUP_TIMEOUT_ENABLE) */
            }
        }
#endif /*0u < COM_RXIPDU_NUMBER*/
    }
    return;
}
/******************************************************************************/
/*
 * Brief               This function performs the processing of the AUTOSAR COM module's transmission activities that
 * are not directly handled within the COM's function invoked by the RTE, for example Com_SendSignal. ServiceId 0x19
 * Sync/Async          None
 * Reentrancy          None
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, COM_CODE)
Com_MainFunctionTx(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
#if (0u < COM_TXIPDU_NUMBER)
    PduIdType txIpduId;
    boolean ipduMDTRun;
    boolean txSendFlag;
    Com_TxIPduRunTimeStateType* txIpduStatePtr;
#endif
    if (COM_INIT == Com_Status/*&& (1 == TXAllow)*/)
    {
#if (0u < COM_TXIPDU_NUMBER)
        for (txIpduId = 0u; txIpduId < COM_TXIPDU_NUMBER; txIpduId++)
        {
            txIpduStatePtr = &Com_TxIPduRunTimeState[txIpduId];
            if (TRUE == txIpduStatePtr->ActiveEnable)
            {
                ipduMDTRun = FALSE;
                txSendFlag = FALSE;
                /*Tx notification for all signals/signal groups of the Tx Pdu is DEFERRED in the MainFunctionTx*/
#if (STD_ON == COM_TX_SIGNAL_NOTIFICATION_ENABLE) || (STD_ON == COM_TX_SIG_GROUP_NOTIFICATION_ENABLE)
                if (TRUE == txIpduStatePtr->TxConfirm)
                {
                    /*Tx notification for all signals/signal groups of the Tx Pdu*/
                    Com_ConfirmationProcess(txIpduId);
                    txIpduStatePtr->TxConfirm = FALSE;
                }
#endif          /* (STD_ON == COM_TX_SIGNAL_NOTIFICATION_ENABLE) || (STD_ON == COM_TX_SIG_GROUP_NOTIFICATION_ENABLE) */
                /* Calculate DM, if DM > 0u, DM-- every mainfunction */
#if (STD_ON == COM_TX_SIGNAL_TIMEOUT_ENABLE) || (STD_ON == COM_TX_SIG_GROUP_TIMEOUT_ENABLE)
                if (txIpduStatePtr->DMCnt > 0u)
                {
                    (txIpduStatePtr->DMCnt) -= 1u;
                    /* DM_TimeOut */
                    if (0u == txIpduStatePtr->DMCnt)
                    {
#if (STD_ON == COM_TX_SIGNAL_TIMEOUT_NOTIFICATION_ENABLE) || (STD_ON == COM_TX_SIG_GROUP_TIMEOUT_NOTIFICATION_ENABLE)
                        /* ToutNotification*/
                        Com_TxDMTimeOutNotification(txIpduId);
#endif /* (STD_ON == COM_TX_SIGNAL_TIMEOUT_NOTIFICATION_ENABLE) || (STD_ON == \
          COM_TX_SIG_GROUP_TIMEOUT_NOTIFICATION_ENABLE) */
                        /* CancelTx(Direct/N component) */
                        txIpduStatePtr->RptNum = 0u;
                        txIpduStatePtr->NTimeCnt = 0u;
                        txIpduStatePtr->Transmiting = FALSE;
/*cancel the transmitting tx pdu*/
#if (STD_ON == COM_CANCELLATION_SUPPORT)
                        if (TRUE == Com_ConfigStd->ComTxIPdu[txIpduId].ComIPduCancellationSupport)
                        {
                            (void)PduR_ComCancelTransmit(Com_ConfigStd->ComTxIPdu[txIpduId].ComPduIdRef);
                        }
#endif /* (STD_ON == COM_CANCELLATION_SUPPORT) */
                    }
                }
#endif /* (STD_ON == COM_TX_SIGNAL_TIMEOUT_ENABLE) || (STD_ON == COM_TX_SIG_GROUP_TIMEOUT_ENABLE) */
#if (STD_ON == COM_MDT_ENABLE)
                /* Calculate MDT, if MDT > 0u, MDT-- every mainfunction  */
                if (txIpduStatePtr->MDTCnt > 0u)
                {
                    (txIpduStatePtr->MDTCnt) -= 1u;
                    /* MDT Timer > 0u, set MDT running flag */
                    if (txIpduStatePtr->MDTCnt != 0u)
                    {
                        ipduMDTRun = TRUE;
                    }
                }
#endif /* (STD_ON == COM_MDT_ENABLE) */
                switch (txIpduStatePtr->ipduTxMode)
                {
#if (STD_ON == COM_TX_MODE_DIRECT_ENABLE)
                case COM_TX_MODE_DIRECT:
                    txSendFlag = Com_MainFuncTxDirect(txIpduId, ipduMDTRun);
                    break;
#endif /* (STD_ON == COM_TX_MODE_DIRECT_ENABLE) */
#if (STD_ON == COM_TX_MODE_MIXED_ENABLE)
                case COM_TX_MODE_MIXED:
                    txSendFlag = Com_MainFuncTxMixed(txIpduId, ipduMDTRun);
                    break;
#endif /* (STD_ON == COM_TX_MODE_MIXED_ENABLE) */
                case COM_TX_MODE_PERIODIC:
                    txSendFlag = Com_MainFuncTxPeriod(txIpduId, ipduMDTRun);
                    break;
                default:
                    /*do nothing*/
                    break;
                }
                if (TRUE == txSendFlag)
                {
#if (STD_ON == COM_TX_IPDU_TYPE_TP_ENABLE)
                    if ((COM_PDU_TP == Com_ConfigStd->ComTxIPdu[txIpduId].ComIPduType)
                        && (TRUE == txIpduStatePtr->Transmiting))
                    {
/* in case a large I-PDU is currently transmitted and the same I-PDU is triggered for transmission again*/
#if (STD_ON == COM_DEV_ERROR_DETECT)
                        (void)Det_ReportError(
                            COM_MODULE_ID,
                            COM_INSTANCE_ID,
                            COM_MAINFUNCTIONTX_ID,
                            COM_E_SKIPPED_TRANSMISSION);
#endif
                    }
                    /*this MainFunctionTx need send the tx ipdu */
                    else
#endif /* (STD_ON == COM_TX_IPDU_TYPE_TP_ENABLE) */
                    {
                        Com_MainFunction_SendPdu(txIpduId);
                    }
                }
            }
        }
#endif /*0u < COM_TXIPDU_NUMBER*/
    }
    return;
}
/******************************************************************************/
/*
 * Brief               Calls the signal gateway part of the AUTOSAR COM module to forward received signals to be routed.
 * ServiceId           0x1a
 * Sync/Async          None
 * Reentrancy          None
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, COM_CODE)
Com_MainFunctionRouteSignals(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
#if (STD_ON == COM_SIGNAL_GW_ENABLE)
#if ((0u < COM_GWMAPPING_NUMBER) && (0u < COM_RXIPDU_NUMBER) && (0u < COM_TXIPDU_NUMBER))
    PduIdType rxIpduId;
    uint16 cnt;
#endif /* (0u < COM_GWMAPPING_NUMBER) && (0u < COM_RXIPDU_NUMBER) && (0u < COM_TXIPDU_NUMBER) */
    if (COM_INIT == Com_Status)
    {
#if ((0u < COM_GWMAPPING_NUMBER) && (0u < COM_RXIPDU_NUMBER) && (0u < COM_TXIPDU_NUMBER))
        for (cnt = 0u; cnt < COM_GWMAPPING_NUMBER; cnt++)
        {
            Com_RouteSignalHandle(cnt);
        }
        for (rxIpduId = 0u; rxIpduId < COM_RXIPDU_NUMBER; rxIpduId++)
        {
            Com_RxIPduRunTimeState[rxIpduId].NeedGW = FALSE;
        }
#if (COM_GWSOURCESIGNAL_UPDATE_NUMBER > 0u)
        for (cnt = 0u; cnt < COM_GWSOURCESIGNAL_UPDATE_NUMBER; cnt++)
        {
            Com_GWSourceSignalUpdate[cnt] = FALSE;
        }
#endif /*COM_GWSOURCESIGNAL_UPDATE_NUMBER > 0u*/
#endif /*(0u < COM_GWMAPPING_NUMBER) && (0u < COM_RXIPDU_NUMBER) && (0u < COM_TXIPDU_NUMBER)*/
    }
#endif /* (STD_ON == COM_SIGNAL_GW_ENABLE) */
    return;
}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
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
 * Return              Std_ReturnType
 *                     E_OK: SDU has been copied and SduLength indicates the number of copied bytes.
 *                     E_NOT_OK: No SDU data has been copied. PduInfoPtr must not
 *                     be used since it may contain a NULL pointer or point to invalid data.
 */
/******************************************************************************/
#define COM_START_SEC_COMTRIGGERTRANSMIT_CALLBACK_CODE
#include "Com_MemMap.h"
FUNC(Std_ReturnType, COM_CODE)
/* PRQA S 3432,1532 ++ */ /* MISRA Rule 20.7,8.7 */
Com_TriggerTransmit(PduIdType TxPduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
/* PRQA S 3432,1532 -- */ /* MISRA Rule 20.7,8.7 */
{
    Std_ReturnType returnValue = E_NOT_OK;
#if (0u < COM_TXIPDU_NUMBER)
    PduIdType txIpduId;
    uint16 txIPduLength;
    uint16 cnt;
    uint16 ipduBufferId;
    PduInfoType pduInfo;
    const Com_TxIPduType* txIpduPtr;
#if (STD_ON == COM_METADATA_SUPPORT)
    uint8 metaDataLength;
    uint16 metaDataStartId;
#endif
#endif
#if (STD_ON == COM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (COM_INIT != Com_Status)
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_TRIGGERTRANSMIT_ID, COM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && ((TxPduId >= (COM_RXIPDU_NUMBER + COM_TXIPDU_NUMBER)) || (TxPduId < COM_RXIPDU_NUMBER)))
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_TRIGGERTRANSMIT_ID, COM_E_PARAM);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && ((NULL_PTR == PduInfoPtr) || (NULL_PTR == PduInfoPtr->SduDataPtr)))
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_TRIGGERTRANSMIT_ID, COM_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr)
        && ((0u < Com_ConfigStd->ComTxIPdu[TxPduId - COM_RXIPDU_NUMBER].MetaDataLength)
            && (NULL_PTR == PduInfoPtr->MetaDataPtr)))
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_TRIGGERTRANSMIT_ID, COM_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if (0u < COM_TXIPDU_NUMBER)
        txIpduId = TxPduId - COM_RXIPDU_NUMBER;
        txIPduLength = Com_TxIPduRunTimeState[txIpduId].TxIpduLength;
        txIpduPtr = &Com_ConfigStd->ComTxIPdu[txIpduId];
        ipduBufferId = txIpduPtr->ComTxIPduBufIndex;
        if (TRUE == Com_TxIPduRunTimeState[txIpduId].ActiveEnable)
        {
            if (txIPduLength <= PduInfoPtr->SduLength)
            {
                for (cnt = 0u; cnt < txIPduLength; cnt++)
                {
                    PduInfoPtr->SduDataPtr[cnt] = Com_TxIPduRuntimeBuff[ipduBufferId + cnt];
                }
                PduInfoPtr->SduLength = txIPduLength;
#if (STD_ON == COM_METADATA_SUPPORT)
                metaDataLength = txIpduPtr->MetaDataLength;
                if ((0u < metaDataLength) && (NULL_PTR != PduInfoPtr->MetaDataPtr))
                {
                    metaDataStartId = (uint16)txIpduPtr->IPduNoDynSignalLength
                                      + (uint16)txIpduPtr->IPduMaxDynSignalLength + ipduBufferId;
                    for (cnt = 0u; cnt < metaDataLength; cnt++)
                    {
                        PduInfoPtr->MetaDataPtr[cnt] = Com_TxIPduRuntimeBuff[metaDataStartId + cnt];
                    }
                }
                else
#endif
                {
                    PduInfoPtr->MetaDataPtr = NULL_PTR;
                }
                if (NULL_PTR != txIpduPtr->ComIPduTriggerTransmitCallout)
                {
                    pduInfo.SduDataPtr = &Com_TxIPduRuntimeBuff[ipduBufferId];
                    pduInfo.SduLength = txIPduLength;
#if (STD_ON == COM_METADATA_SUPPORT)
                    if (0u < metaDataLength)
                    {
                        pduInfo.MetaDataPtr = &Com_TxIPduRuntimeBuff[metaDataStartId];
                    }
                    else
#endif
                    {
                        pduInfo.MetaDataPtr = NULL_PTR;
                    }
                    (void)(txIpduPtr->ComIPduTriggerTransmitCallout(TxPduId, &pduInfo));
                }
                if (COM_TRIGGER_TRANSMIT == txIpduPtr->ComTxIPduClearUpdateBit)
                {
#if (STD_ON == COM_TX_SIG_GROUP_UPDATE_BIT_ENABLE) || (STD_ON == COM_TX_SIGNAL_UPDATE_BIT_ENABLE) \
    || (STD_ON == COM_GW_DEST_SIG_UPDATE_BIT_ENABLE)
                    Com_ClearTxIPduUpdates(txIpduId);
#endif /* (STD_ON == COM_TX_SIG_GROUP_UPDATE_BIT_ENABLE) || (STD_ON == COM_TX_SIGNAL_UPDATE_BIT_ENABLE) || (STD_ON \
          == COM_GW_DEST_SIG_UPDATE_BIT_ENABLE) */
                }
                Com_TxIPduRunTimeState[txIpduId].Transmiting = TRUE;
                returnValue = E_OK;
            }
        }
        else
        {
#if (STD_ON == COM_TX_SIGNAL_ERROR_NOTIFICATION_ENABLE) || (STD_ON == COM_TX_SIG_GROUP_ERROR_NOTIFICATION_ENABLE)
            Com_InvokeErrorNotification(txIpduId);
#endif /* (STD_ON == COM_TX_SIGNAL_ERROR_NOTIFICATION_ENABLE) || (STD_ON == \
          COM_TX_SIG_GROUP_ERROR_NOTIFICATION_ENABLE) */
        }
#endif /*0u < COM_TXIPDU_NUMBER*/
    }
    COM_NOUSED(TxPduId);
    COM_NOUSED(PduInfoPtr);
    return returnValue;
}
#define COM_STOP_SEC_COMTRIGGERTRANSMIT_CALLBACK_CODE
#include "Com_MemMap.h"
/******************************************************************************/
/*
 * Brief               Indication of a received I-PDU from a lower layer communication interface module.
 * ServiceId           0x42
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different PduIds. Non reentrant for the same PduId.
 * Param-Name[in]      RxPduId: ID of the received I-PDU.
 *                     PduInfoPtr: Contains the length (SduLength) of the received I-PDU and a pointer to
 *                     a buffer (SduDataPtr) containing the I-PDU.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#define COM_START_SEC_COMRXINDICATION_CALLBACK_CODE
#include "Com_MemMap.h"
FUNC(void, COM_CODE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
Com_RxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
#if (0u < COM_RXIPDU_NUMBER)
    uint16 minPduLength;
    uint16 maxPduLength;
    boolean rxPduValid;
    uint8 receiveCounter;
    uint32 bitPosition;
    uint8 bitSize;
    PduInfoType rxPduInfo;
    const Com_RxIPduType* rxIpduPtr;
#endif
#if (STD_ON == COM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (COM_INIT != Com_Status)
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_RXINDICATION_ID, COM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr)
#if (0u < COM_RXIPDU_NUMBER)
        && (RxPduId >= COM_RXIPDU_NUMBER)
#endif
    )
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_RXINDICATION_ID, COM_E_PARAM);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (COM_PDU_NORMAL != Com_ConfigStd->ComRxIPdu[RxPduId].ComIPduType))
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_RXINDICATION_ID, COM_E_PARAM);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && ((NULL_PTR == PduInfoPtr) || (NULL_PTR == PduInfoPtr->SduDataPtr)))
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_RXINDICATION_ID, COM_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr)
        && ((0u < Com_ConfigStd->ComRxIPdu[RxPduId].MetaDataLength) && (NULL_PTR == PduInfoPtr->MetaDataPtr)))
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_RXINDICATION_ID, COM_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if (0u < COM_RXIPDU_NUMBER)
        rxIpduPtr = &Com_ConfigStd->ComRxIPdu[RxPduId];
        minPduLength = (uint16)rxIpduPtr->IPduNoDynSignalLength;
        maxPduLength = minPduLength + (uint16)rxIpduPtr->IPduMaxDynSignalLength;
        /*the rx pdu is active,the receive length is suited to pdu configuration length*/
        if ((TRUE == Com_RxIPduRunTimeState[RxPduId].ActiveEnable) && (PduInfoPtr->SduLength >= minPduLength))
        {
            rxPduInfo.SduDataPtr = PduInfoPtr->SduDataPtr;
            rxPduInfo.SduLength = PduInfoPtr->SduLength;
            rxPduInfo.MetaDataPtr = PduInfoPtr->MetaDataPtr;
            if (PduInfoPtr->SduLength > maxPduLength)
            {
                rxPduInfo.SduLength = maxPduLength;
            }
#if (COM_RXSIGNAL_NUMBER + COM_RXSIGNALGROUP_NUMBER > 0u) \
    && ((STD_ON == COM_RX_SIGNAL_TIMEOUT_ENABLE) || (STD_ON == COM_RX_SIG_GROUP_TIMEOUT_ENABLE))
            if (TRUE == Com_RxIPduRunTimeState[RxPduId].DMEnable)
            {
                /*reset all signals and signal groups DM time(except the signal/signal group have update bit and the
                 * update bit is not 1)*/
                Com_ResetUpdateDMTime(RxPduId, &rxPduInfo);
            }
#endif /* (COM_RXSIGNAL_NUMBER + COM_RXSIGNALGROUP_NUMBER > 0u) && ((STD_ON == COM_RX_SIGNAL_TIMEOUT_ENABLE) || \
(STD_ON == COM_RX_SIG_GROUP_TIMEOUT_ENABLE)) */
#if (STD_ON == COM_RX_IPDU_COUNTER_ENABLE)
            if (NULL_PTR != rxIpduPtr->ComIPduCounter)
            {
                /*unpack the receive pdu's counter*/
                bitPosition = rxIpduPtr->ComIPduCounter->ComIPduCounterStartPosition;
                bitSize = rxIpduPtr->ComIPduCounter->ComIPduCounterSize;
                receiveCounter = rxPduInfo.SduDataPtr[(uint16)(bitPosition >> 3u)];
                receiveCounter = receiveCounter << (8u - (((uint8)bitPosition & 0x07u) + bitSize));
                receiveCounter = receiveCounter >> (8u - bitSize);
#if (STD_ON == COM_IPDU_REPLICATION_ENABLE)
                if (NULL_PTR != rxIpduPtr->ComIPduReplication)
                {
                    /*judge the receive pdu's Replication is valid or not*/
                    rxPduValid = Com_RxPduReplicationValid(RxPduId, receiveCounter, &rxPduInfo);
                }
                else
#endif /* (STD_ON == COM_IPDU_REPLICATION_ENABLE) */
                {
                    /*judge the receive pdu's counter is valid or not*/
                    rxPduValid = Com_RxPduCounterValid(RxPduId, receiveCounter);
                    if (TRUE == rxPduValid)
                    {
                        Com_CopyPduDataToRxBuffer(RxPduId, &rxPduInfo);
                    }
                }

                if (TRUE == rxPduValid)
                {
                    Com_RxPduHandle(RxPduId, &rxPduInfo);
                }
            }
            else
#endif /* (STD_ON == COM_RX_IPDU_COUNTER_ENABLE) */
            {
                Com_CopyPduDataToRxBuffer(RxPduId, &rxPduInfo);

                Com_RxPduHandle(RxPduId, &rxPduInfo);
            }
        }
#endif /* 0u < COM_RXIPDU_NUMBER */
    }
    COM_NOUSED(RxPduId);
    COM_NOUSED(PduInfoPtr);
    return;
}
#define COM_STOP_SEC_COMRXINDICATION_CALLBACK_CODE
#include "Com_MemMap.h"
/******************************************************************************/
/*
 * Brief               Called after an I-PDU has been received via the TP API,
 *                     the result indicates whether the transmission was successful or not.
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
#define COM_START_SEC_COMTPRXINDICATION_CALLBACK_CODE
#include "Com_MemMap.h"
FUNC(void, COM_CODE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
Com_TpRxIndication(PduIdType id, Std_ReturnType result)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
#if ((0u < COM_RXIPDU_NUMBER) && (STD_ON == COM_RXTPPDU_SUPPORT))
    boolean ret = TRUE;
    PduInfoType info;
    uint16 rxPduBufferId;
#if (STD_ON == COM_METADATA_SUPPORT)
    uint16 metaDataPos;
    uint8 metaDataLength;
#endif
    uint16 cnt;
    uint8 receiveCounter;
    boolean receiveCounterIsValid;
    const Com_RxIPduType* rxIpduPtr;
#endif
#if (STD_ON == COM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (COM_INIT != Com_Status)
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_TPRXINDICATION_ID, COM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr)
#if (0u < COM_RXIPDU_NUMBER)
        && (id >= COM_RXIPDU_NUMBER)
#endif
    )
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_TPRXINDICATION_ID, COM_E_PARAM);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (COM_PDU_TP != Com_ConfigStd->ComRxIPdu[id].ComIPduType))
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_TPRXINDICATION_ID, COM_E_PARAM);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if ((0u < COM_RXIPDU_NUMBER) && (STD_ON == COM_RXTPPDU_SUPPORT))
        Com_RxIPduRunTimeState[id].Receiving = FALSE;
        if (TRUE == Com_RxIPduRunTimeState[id].ActiveEnable)
        {
            rxIpduPtr = &Com_ConfigStd->ComRxIPdu[id];
            rxPduBufferId = rxIpduPtr->ComRxIPduBufIndex;
            /*TP PDU successful receipt*/
            if (E_OK == result)
            {
                info.SduDataPtr = &Com_RxIPduRuntimeBuff[rxPduBufferId];
                info.SduLength = Com_RxIPduRunTimeState[id].RxIpduLength;
#if (STD_ON == COM_METADATA_SUPPORT)
                metaDataLength = rxIpduPtr->MetaDataLength;
                if (0u < metaDataLength)
                {
                    metaDataPos = (uint16)rxIpduPtr->IPduNoDynSignalLength + (uint16)rxIpduPtr->IPduMaxDynSignalLength
                                  + rxPduBufferId;
                    info.MetaDataPtr = &Com_RxIPduRuntimeBuff[metaDataPos];
                }
                else
#endif /* (STD_ON == COM_METADATA_SUPPORT) */
                {
                    info.MetaDataPtr = NULL_PTR;
                }
#if (COM_RXSIGNAL_NUMBER + COM_RXSIGNALGROUP_NUMBER > 0u) \
    && ((STD_ON == COM_RX_SIGNAL_TIMEOUT_ENABLE) || (STD_ON == COM_RX_SIG_GROUP_TIMEOUT_ENABLE))
                if (TRUE == Com_RxIPduRunTimeState[id].DMEnable)
                {
                    /*reset all signals and signal groups DM time(except the signal/signal group have update bit and the
                     * update bit is not 1)*/
                    Com_ResetUpdateDMTime(id, &info);
                }
#endif /*#if (COM_RXSIGNAL_NUMBER + COM_RXSIGNALGROUP_NUMBER > 0u) && ((STD_ON == COM_RX_SIGNAL_TIMEOUT_ENABLE) || \
(STD_ON == COM_RX_SIG_GROUP_TIMEOUT_ENABLE))*/
#if (STD_ON == COM_RX_IPDU_COUNTER_ENABLE)
                if (NULL_PTR != rxIpduPtr->ComIPduCounter)
                {
                    /*unpack the receive pdu's counter*/
                    receiveCounter = Com_UnPackCounterValue(id);
                    /*judge the receive pdu's counter is valid or not*/
                    receiveCounterIsValid = Com_RxPduCounterValid(id, receiveCounter);
                }
                /*not configuration rx counter*/
                else
                {
                    receiveCounterIsValid = TRUE;
                }
                if (TRUE == receiveCounterIsValid)
#endif /* (STD_ON == COM_RX_IPDU_COUNTER_ENABLE) */
                {
#if (STD_ON == COM_RX_IPDU_CALLOUT_ENABLE)
                    if (NULL_PTR != rxIpduPtr->ComIPduCallout)
                    {
                        ret = rxIpduPtr->ComIPduCallout(id, &info);
                    }
                    if (TRUE == ret)
#endif /* (STD_ON == COM_RX_IPDU_CALLOUT_ENABLE) */
                    {
                        /*signal/signal group RxIndication is made immediate*/
#if (STD_ON == COM_RX_IPDU_SIGNAL_PROCESS_IMMEDIATE_ENABLE)
                        if (COM_IMMEDIATE == rxIpduPtr->ComIPduSignalProcessing)
                        {
                            Com_RxIPduRunTimeState[id].RxIndication = FALSE;
                            /*rx indication handle*/
                            Com_IndicationProcess(id);
                        }
                        /*signal/signal group RxIndication is made in next MainFunctionRx*/
                        else
#endif /* (STD_ON == COM_RX_IPDU_SIGNAL_PROCESS_IMMEDIATE_ENABLE) */
                        {
                            Com_RxIPduRunTimeState[id].RxIndication = TRUE;
                        }
                    }
                }
            }
            /*TP PDU false receipt:the AUTOSAR COM module shall treat all signals of the
             * received large I-PDU exactly like invalidated signals.*/
            else
            {
                Com_RxIPduRunTimeState[id].RxIpduLength = Com_RxIPduInitState[id].RxIpduLength;
                rxPduBufferId = rxIpduPtr->ComRxIPduBufIndex;
                for (cnt = 0u; cnt < Com_RxIPduInitState[id].RxIpduLength; cnt++)
                {
                    Com_RxIPduRuntimeBuff[rxPduBufferId + cnt] = Com_RxIPduInitValue[rxPduBufferId + cnt];
                }
#if (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_INVALID_DATA_ENABLE)
                /*execute all configured ComDataInvalidActions for all included signals and signal groups*/
                Com_TpPduInvalidAction(id);
#endif /* (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_INVALID_DATA_ENABLE) */
            }
        }
#endif /*(0u < COM_RXIPDU_NUMBER) && (STD_ON == COM_RXTPPDU_SUPPORT)*/
    }
    COM_NOUSED(id);
    COM_NOUSED(result);
    return;
}
#define COM_STOP_SEC_COMTPRXINDICATION_CALLBACK_CODE
#include "Com_MemMap.h"
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
#define COM_START_SEC_COMTXCONFIRMATION_CALLBACK_CODE
#include "Com_MemMap.h"
FUNC(void, COM_CODE)
Com_TxConfirmation(PduIdType TxPduId) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
#if (0u < COM_TXIPDU_NUMBER)
    Com_IPduSignalProcessingType ipduSignalProcessing;
    PduIdType comTxPduId;
    boolean needAckNotif = FALSE;
    const Com_TxIPduType* txIpduPtr;
    Com_TxIPduRunTimeStateType* txIpduStatePtr;
#endif
#if (STD_ON == COM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (COM_INIT != Com_Status)
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_TXCONFIRMATION_ID, COM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && ((TxPduId >= (COM_RXIPDU_NUMBER + COM_TXIPDU_NUMBER)) || (TxPduId < COM_RXIPDU_NUMBER)))
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_TXCONFIRMATION_ID, COM_E_PARAM);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (COM_PDU_NORMAL != Com_ConfigStd->ComTxIPdu[TxPduId - COM_RXIPDU_NUMBER].ComIPduType))
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_TXCONFIRMATION_ID, COM_E_PARAM);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if (0u < COM_TXIPDU_NUMBER)
        comTxPduId = TxPduId - COM_RXIPDU_NUMBER;
        txIpduPtr = &Com_ConfigStd->ComTxIPdu[comTxPduId];
        txIpduStatePtr = &Com_TxIPduRunTimeState[comTxPduId];
        if (TRUE == txIpduStatePtr->ActiveEnable)
        {
            /*repetitions of transmission */
#if (STD_ON == COM_TX_MODE_DIRECT_ENABLE) || (STD_ON == COM_TX_MODE_MIXED_ENABLE)
            if (txIpduStatePtr->RptNum > 0u)
            {
                (txIpduStatePtr->RptNum) -= 1u;
                if (0u == txIpduStatePtr->RptNum)
                {
                    needAckNotif = TRUE;
                    txIpduStatePtr->DMCnt = 0u;
                    txIpduStatePtr->NTimeCnt = 0u;
                }
            }
            /*no repetitions of transmission */
            else
#endif /* (STD_ON == COM_TX_MODE_DIRECT_ENABLE) || (STD_ON == COM_TX_MODE_MIXED_ENABLE) */
            {
                needAckNotif = TRUE;
                txIpduStatePtr->DMCnt = 0u;
            }
#if (STD_ON == COM_TX_SIGNAL_NOTIFICATION_ENABLE) || (STD_ON == COM_TX_SIG_GROUP_NOTIFICATION_ENABLE)
            if (TRUE == needAckNotif)
            {
#if (STD_ON == COM_TX_IPDU_SIGNAL_PROCESS_IMMEDIATE_ENABLE)
                ipduSignalProcessing = txIpduPtr->ComIPduSignalProcessing;
                /*signal/signal group TxConfirmation handle is made immediate*/
                if (COM_IMMEDIATE == ipduSignalProcessing)
                {
                    /*Tx notification for all signals/signal groups of the Tx Pdu*/
                    Com_ConfirmationProcess(comTxPduId);
                    txIpduStatePtr->TxConfirm = FALSE;
                }
                else
#endif /* (STD_ON == COM_TX_IPDU_SIGNAL_PROCESS_IMMEDIATE_ENABLE) */
                {
                    /*Tx notification for all signals/signal groups of the Tx Pdu in next MainFunctionTx*/
                    txIpduStatePtr->TxConfirm = TRUE;
                }
            }
#endif /* (STD_ON == COM_TX_SIGNAL_NOTIFICATION_ENABLE) || (STD_ON == COM_TX_SIG_GROUP_NOTIFICATION_ENABLE) */
#if (STD_ON == COM_TX_SIG_GROUP_UPDATE_BIT_ENABLE) || (STD_ON == COM_TX_SIGNAL_UPDATE_BIT_ENABLE) \
    || (STD_ON == COM_GW_DEST_SIG_UPDATE_BIT_ENABLE)
            if (COM_CONFIRMATION == txIpduPtr->ComTxIPduClearUpdateBit)
            {
                /*clear all update bit of the Tx Pdu*/
                Com_ClearTxIPduUpdates(comTxPduId);
            }
#endif /* (STD_ON == COM_TX_SIG_GROUP_UPDATE_BIT_ENABLE) || (STD_ON == COM_TX_SIGNAL_UPDATE_BIT_ENABLE) || (STD_ON == \
COM_GW_DEST_SIG_UPDATE_BIT_ENABLE) */
            /*reset Tx time out counter for just NONE mode of Tx Mode*/
            if ((NULL_PTR == txIpduPtr->ComTxModeFalse)
                && (COM_TX_MODE_NONE == txIpduPtr->ComTxModeTrue->ComTxModeMode))
            {
                txIpduStatePtr->DMCnt = txIpduPtr->ComTxIpduDM;
            }
        }
        txIpduStatePtr->Transmiting = FALSE;
#endif /*0u < COM_TXIPDU_NUMBER*/
    }
    COM_NOUSED(TxPduId);
    return;
}
#define COM_STOP_SEC_COMTXCONFIRMATION_CALLBACK_CODE
#include "Com_MemMap.h"
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
#define COM_START_SEC_COMTPTXCONFIRMATION_CALLBACK_CODE
#include "Com_MemMap.h"
FUNC(void, COM_CODE)
Com_TpTxConfirmation(PduIdType id, Std_ReturnType result) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
#if ((0u < COM_TXIPDU_NUMBER) && (STD_ON == COM_TXTPPDU_SUPPORT))
    Com_IPduSignalProcessingType ipduSignalProcessing;
    PduIdType comTxPduId;
    boolean needAckNotif = FALSE;
    Com_TxIPduRunTimeStateType* txIpduStatePtr;
#endif
#if (STD_ON == COM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (COM_INIT != Com_Status)
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_TPTXCONFIRMATION_ID, COM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && ((id >= (COM_RXIPDU_NUMBER + COM_TXIPDU_NUMBER)) || (id < COM_RXIPDU_NUMBER)))
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_TPTXCONFIRMATION_ID, COM_E_PARAM);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (COM_PDU_TP != Com_ConfigStd->ComTxIPdu[id - COM_RXIPDU_NUMBER].ComIPduType))
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_TPTXCONFIRMATION_ID, COM_E_PARAM);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if ((0u < COM_TXIPDU_NUMBER) && (STD_ON == COM_TXTPPDU_SUPPORT))
        comTxPduId = id - COM_RXIPDU_NUMBER;
        txIpduStatePtr = &Com_TxIPduRunTimeState[comTxPduId];
        txIpduStatePtr->Transmiting = FALSE;
        if (TRUE == txIpduStatePtr->ActiveEnable)
        {
            txIpduStatePtr->TxOffset = 0u;
            /*TP PDU successful transmit*/
            if (E_OK == result)
            {
                /*repetitions of transmission */
#if (STD_ON == COM_TX_MODE_DIRECT_ENABLE) || (STD_ON == COM_TX_MODE_MIXED_ENABLE)
                if (txIpduStatePtr->RptNum > 0u)
                {
                    (txIpduStatePtr->RptNum) -= 1u;
                    if (0u == txIpduStatePtr->RptNum)
                    {
                        needAckNotif = TRUE;
                        txIpduStatePtr->DMCnt = 0u;
                        txIpduStatePtr->NTimeCnt = 0u;
                    }
                }
                /*no repetitions of transmission */
                else
#endif /* (STD_ON == COM_TX_MODE_DIRECT_ENABLE) || (STD_ON == COM_TX_MODE_MIXED_ENABLE) */
                {
                    needAckNotif = TRUE;
                    txIpduStatePtr->DMCnt = 0u;
                }
#if (STD_ON == COM_TX_SIGNAL_NOTIFICATION_ENABLE) || (STD_ON == COM_TX_SIG_GROUP_NOTIFICATION_ENABLE)
                if (TRUE == needAckNotif)
                {
                    ipduSignalProcessing = Com_ConfigStd->ComTxIPdu[comTxPduId].ComIPduSignalProcessing;
                    /*signal/signal group TxConfirmation handle is made immediate*/
#if (STD_ON == COM_TX_IPDU_SIGNAL_PROCESS_IMMEDIATE_ENABLE)
                    if (COM_IMMEDIATE == ipduSignalProcessing)
                    {
                        /*Tx notification for all signals/signal groups of the Tx Pdu*/
                        Com_ConfirmationProcess(comTxPduId);
                        txIpduStatePtr->TxConfirm = FALSE;
                    }
                    else
#endif /* (STD_ON == COM_TX_IPDU_SIGNAL_PROCESS_IMMEDIATE_ENABLE) */
                    {
                        /*Tx notification for all signals/signal groups of the Tx Pdu in next MainFunctionTx*/
                        txIpduStatePtr->TxConfirm = TRUE;
                    }
                }
#endif /* (STD_ON == COM_TX_SIGNAL_NOTIFICATION_ENABLE) || (STD_ON == COM_TX_SIG_GROUP_NOTIFICATION_ENABLE) */
#if (STD_ON == COM_TX_SIG_GROUP_UPDATE_BIT_ENABLE) || (STD_ON == COM_TX_SIGNAL_UPDATE_BIT_ENABLE) \
    || (STD_ON == COM_GW_DEST_SIG_UPDATE_BIT_ENABLE)
                if (COM_CONFIRMATION == Com_ConfigStd->ComTxIPdu[comTxPduId].ComTxIPduClearUpdateBit)
                {
                    /*clear all update bit of the Tx Pdu*/
                    Com_ClearTxIPduUpdates(comTxPduId);
                }
#endif /* (STD_ON == COM_TX_SIG_GROUP_UPDATE_BIT_ENABLE) || (STD_ON == COM_TX_SIGNAL_UPDATE_BIT_ENABLE) || (STD_ON == \
COM_GW_DEST_SIG_UPDATE_BIT_ENABLE) */
            }
            else
            {
                /* CancelTx(Direct/N component) */
                txIpduStatePtr->RptNum = 0u;
                txIpduStatePtr->NTimeCnt = 0u;
            }
        }
#endif /*(0u < COM_TXIPDU_NUMBER) && (STD_ON == COM_TXTPPDU_SUPPORT)*/
    }
    COM_NOUSED(id);
    COM_NOUSED(result);
    return;
}
#define COM_STOP_SEC_COMTPTXCONFIRMATION_CALLBACK_CODE
#include "Com_MemMap.h"
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
 *                     first frame or single frame of a transport protocol I-PDU reception.
 *                     Depending on the global parameter MetaDataLength, additional bytes containing
 *                     MetaData (e.g. the CAN ID) are appended after the payload data, increasing the length
 *                     accordingly. If neither first/single frame data nor MetaData
 *                     are available, this parameter is set to NULL_PTR.
 *                     TpSduLength: Total length of the N-SDU to be received.
 * Param-Name[out]     bufferSizePtr: Available receive buffer in the receiving module. This parameter will
 *                     be used to compute the Block Size (BS) in the transport protocol module.
 * Param-Name[in/out]  None
 * Return              BufReq_ReturnType(BUFREQ_OK,BUFREQ_E_NOT_OK,BUFREQ_E_OVFL)
 *                     BUFREQ_OK: Connection has been accepted. bufferSizePtr
 *                     indicates the available receive buffer; reception is continued.
 *                     If no buffer of the requested size is available, a receive buffer
 *                     size of 0 shall be indicated by bufferSizePtr.
 *                     BUFREQ_E_NOT_OK: Connection has been rejected; reception is aborted. bufferSizePtr remains
 * unchanged. BUFREQ_E_OVFL: No buffer of the required length can be provided; reception is aborted. bufferSizePtr
 * remains unchanged.
 */
/******************************************************************************/
#define COM_START_SEC_COMSTARTOFRECEPTION_CALLBACK_CODE
#include "Com_MemMap.h"
FUNC(BufReq_ReturnType, COM_CODE)
/* PRQA S 3432,1532 ++ */ /* MISRA Rule 20.7,8.7 */
Com_StartOfReception(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, COM_APPL_DATA) bufferSizePtr)
/* PRQA S 3432,1532 -- */ /* MISRA Rule 20.7,8.7 */
{
    BufReq_ReturnType bufReq = BUFREQ_E_NOT_OK;
#if ((0u < COM_RXIPDU_NUMBER) && (STD_ON == COM_RXTPPDU_SUPPORT))
    PduLengthType rxPduMaxLength;
#if (STD_ON == COM_METADATA_SUPPORT)
    uint8 metadataLength, cnt;
    uint16 metaDataPos;
#endif
    const Com_RxIPduType* rxIpduPtr;
#endif
#if (STD_ON == COM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (COM_INIT != Com_Status)
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_STARTOFRECEPTION_ID, COM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr)
#if (0u < COM_RXIPDU_NUMBER)
        && (id >= COM_RXIPDU_NUMBER)
#endif
    )
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_STARTOFRECEPTION_ID, COM_E_PARAM);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (COM_PDU_TP != Com_ConfigStd->ComRxIPdu[id].ComIPduType))
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_STARTOFRECEPTION_ID, COM_E_PARAM);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr)
        && ((0u < Com_ConfigStd->ComRxIPdu[id].MetaDataLength)
            && ((NULL_PTR == info) || (NULL_PTR == info->MetaDataPtr))))
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_STARTOFRECEPTION_ID, COM_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (NULL_PTR == bufferSizePtr))
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_STARTOFRECEPTION_ID, COM_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if ((0u < COM_RXIPDU_NUMBER) && (STD_ON == COM_RXTPPDU_SUPPORT))
        if (TRUE == Com_RxIPduRunTimeState[id].ActiveEnable)
        {
            rxIpduPtr = &Com_ConfigStd->ComRxIPdu[id];
            rxPduMaxLength = rxIpduPtr->IPduNoDynSignalLength + rxIpduPtr->IPduMaxDynSignalLength;
            /*the TP PDU length is too large than the RX PDU buffer*/
            if (TpSduLength > rxPduMaxLength)
            {
                bufReq = BUFREQ_E_OVFL;
            }
            else
            {
                /*the tp pdu is not receiving and the rx pdu length >= min length of the pdu*/
                if ((FALSE == Com_RxIPduRunTimeState[id].Receiving)
                    && (TpSduLength >= rxIpduPtr->IPduNoDynSignalLength))
                {
                    Com_RxIPduRunTimeState[id].RxIpduLength = (uint16)TpSduLength;
                    Com_RxIPduRunTimeState[id].Receiving = TRUE;
                    Com_RxIPduRunTimeState[id].RxOffset = 0u;
                    *bufferSizePtr = TpSduLength;
#if (STD_ON == COM_METADATA_SUPPORT)
                    metadataLength = rxIpduPtr->MetaDataLength;
                    if ((0u < metadataLength) && (NULL_PTR != info->MetaDataPtr))
                    {
                        metaDataPos = (uint16)rxPduMaxLength + rxIpduPtr->ComRxIPduBufIndex;
                        /*copy the metadata to RX PDU buffer*/
                        for (cnt = 0u; cnt < metadataLength; cnt++)
                        {
                            Com_RxIPduRuntimeBuff[metaDataPos + cnt] = info->MetaDataPtr[cnt];
                        }
                    }
#endif
                    bufReq = BUFREQ_OK;
                }
            }
        }
#endif /*(0u < COM_RXIPDU_NUMBER) && (STD_ON == COM_RXTPPDU_SUPPORT)*/
    }
    COM_NOUSED(id);
    COM_NOUSED(info);
    COM_NOUSED(TpSduLength);
    COM_NOUSED(bufferSizePtr);
    return bufReq;
}
#define COM_STOP_SEC_COMSTARTOFRECEPTION_CALLBACK_CODE
#include "Com_MemMap.h"
/******************************************************************************/
/*
 * Brief               This function is called to provide the received data of an I-PDU segment (N-PDU) to the upper
 * layer. Each call to this function provides the next part of the I-PDU data. The size of the remaining data is written
 * to the position indicated by bufferSizePtr. ServiceId           0x44 Sync/Async          Synchronous Reentrancy
 * Reentrant Param-Name[in]      id: Identification of the received I-PDU. info: Provides the source buffer (SduDataPtr)
 * and the number of bytes to be copied (SduLength). An SduLength of 0 can be used to query the current amount of
 * available buffer in the upper layer module. In this case, the SduDataPtr may be a NULL_PTR. Param-Name[out]
 * bufferSizePtr: Available receive buffer after data has been copied. Param-Name[in/out]  None Return BufReq_ReturnType
 *                     BUFREQ_OK: Data copied successfully
 *                     BUFREQ_E_NOT_OK: Data was not copied because an error occurred.
 */
/******************************************************************************/
#define COM_START_SEC_COMCOPYRXDATA_CALLBACK_CODE
#include "Com_MemMap.h"
FUNC(BufReq_ReturnType, COM_CODE)
/* PRQA S 3432,1532 ++ */ /* MISRA Rule 20.7,8.7 */
Com_CopyRxData(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) info,
    P2VAR(PduLengthType, AUTOMATIC, COM_APPL_DATA) bufferSizePtr)
/* PRQA S 3432,1532 -- */ /* MISRA Rule 20.7,8.7 */
{
    BufReq_ReturnType bufReq = BUFREQ_E_NOT_OK;
#if ((0u < COM_RXIPDU_NUMBER) && (STD_ON == COM_RXTPPDU_SUPPORT))
    PduLengthType cnt;
    uint16 copyStartPos;
#endif
#if (STD_ON == COM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (COM_INIT != Com_Status)
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_COPYRXDATA_ID, COM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr)
#if (0u < COM_RXIPDU_NUMBER)
        && (id >= COM_RXIPDU_NUMBER)
#endif
    )
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_COPYRXDATA_ID, COM_E_PARAM);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (COM_PDU_TP != Com_ConfigStd->ComRxIPdu[id].ComIPduType))
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_COPYRXDATA_ID, COM_E_PARAM);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && ((NULL_PTR == info) || (NULL_PTR == bufferSizePtr)))
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_COPYRXDATA_ID, COM_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && ((0u < Com_ConfigStd->ComRxIPdu[id].MetaDataLength) && (NULL_PTR == info->MetaDataPtr)))
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_COPYRXDATA_ID, COM_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if ((0u < COM_RXIPDU_NUMBER) && (STD_ON == COM_RXTPPDU_SUPPORT))
        if (TRUE == Com_RxIPduRunTimeState[id].ActiveEnable)
        {
            if ((TRUE == Com_RxIPduRunTimeState[id].Receiving)
                && ((Com_RxIPduRunTimeState[id].RxOffset + info->SduLength) <= Com_RxIPduRunTimeState[id].RxIpduLength))
            {
                copyStartPos = Com_ConfigStd->ComRxIPdu[id].ComRxIPduBufIndex + Com_RxIPduRunTimeState[id].RxOffset;
                /*copy the RX data to RX PDU buffer*/
                for (cnt = 0u; cnt < info->SduLength; cnt++)
                {
                    Com_RxIPduRuntimeBuff[copyStartPos + cnt] = info->SduDataPtr[cnt];
                }
                Com_RxIPduRunTimeState[id].RxOffset += (uint16)info->SduLength;
                *bufferSizePtr = (PduLengthType)Com_RxIPduRunTimeState[id].RxIpduLength
                                 - (PduLengthType)Com_RxIPduRunTimeState[id].RxOffset;
                bufReq = BUFREQ_OK;
            }
        }
#endif /*(0u < COM_RXIPDU_NUMBER) && (STD_ON == COM_RXTPPDU_SUPPORT)*/
    }
    COM_NOUSED(id);
    COM_NOUSED(info);
    COM_NOUSED(bufferSizePtr);
    return bufReq;
}
#define COM_STOP_SEC_COMCOPYRXDATA_CALLBACK_CODE
#include "Com_MemMap.h"
/******************************************************************************/
/*
 * Brief               This function is called to acquire the transmit data of an I-PDU segment (N-PDU).
 *                     Each call to this function provides the next part of the I-PDU data unless retry->TpDataState
 *                     is TP_DATARETRY. In this case the function restarts to copy the data beginning at the offset
 *                     from the current position indicated by retry->TxTpDataCnt. The size of the remaining data is
 *                     written to the position indicated by availableDataPtr.
 * ServiceId           0x43
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      id: Identification of the transmitted I-PDU.
 *                     retry: This parameter is used to acknowledge transmitted data or to retransmit data after
 * transmission problems. Param-Name[out]     availableDataPtr: Indicates the remaining number of bytes that are
 * available in the upper layer module's Tx buffer. availableDataPtr can be used by TP modules that support dynamic
 * payload lengths (e.g. FrIsoTp) to determine the size of the following CFs. Param-Name[in/out]  None Return
 * BufReq_ReturnType BUFREQ_OK: Data has been copied to the transmit buffer completely as requested. BUFREQ_E_BUSY:
 * Request could not be fulfilled, because the required amount of Tx data is not available. The lower layer module may
 * retry this call later on. No data has been copied. BUFREQ_E_NOT_OK: Data has not been copied. Request failed.
 */
/******************************************************************************/
#define COM_START_SEC_COMCOPYTXDATA_CALLBACK_CODE
#include "Com_MemMap.h"
FUNC(BufReq_ReturnType, COM_CODE)
/* PRQA S 3432,1532 ++ */ /* MISRA Rule 20.7,8.7 */
Com_CopyTxData(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) info,
    P2CONST(RetryInfoType, AUTOMATIC, COM_APPL_DATA) retry,
    P2VAR(PduLengthType, AUTOMATIC, COM_APPL_DATA) availableDataPtr)
/* PRQA S 3432,1532 ++ */ /* MISRA Rule 20.7,8.7 */
{
    BufReq_ReturnType bufReq = BUFREQ_E_NOT_OK;
#if ((0u < COM_TXIPDU_NUMBER) && (STD_ON == COM_TXTPPDU_SUPPORT))
    PduIdType txIpduId;
    PduLengthType cnt;
    uint16 copyStartPos;
#if (STD_ON == COM_METADATA_SUPPORT)
    uint8 metaDataLength;
    uint16 metaDataStartId;
#endif
    PduLengthType sduLength;
    const Com_TxIPduType* txIpduPtr;
    Com_TxIPduRunTimeStateType* txIpduStatePtr;
#endif
#if (STD_ON == COM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (COM_INIT != Com_Status)
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_COPYTXDATA_ID, COM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && ((id >= (COM_RXIPDU_NUMBER + COM_TXIPDU_NUMBER)) || (id < COM_RXIPDU_NUMBER)))
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_COPYTXDATA_ID, COM_E_PARAM);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && (COM_PDU_TP != Com_ConfigStd->ComTxIPdu[id - COM_RXIPDU_NUMBER].ComIPduType))
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_COPYTXDATA_ID, COM_E_PARAM);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && ((NULL_PTR == info) || (NULL_PTR == availableDataPtr)))
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_COPYTXDATA_ID, COM_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if ((TRUE == detNoErr) && ((0u < info->SduLength) && (NULL_PTR == info->SduDataPtr)))
    {
        (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_COPYTXDATA_ID, COM_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if (TRUE == detNoErr)
#endif
    {
#if ((0u < COM_TXIPDU_NUMBER) && (STD_ON == COM_TXTPPDU_SUPPORT))
        txIpduId = id - COM_RXIPDU_NUMBER;
        txIpduPtr = &Com_ConfigStd->ComTxIPdu[txIpduId];
        txIpduStatePtr = &Com_TxIPduRunTimeState[txIpduId];
        if ((TRUE == txIpduStatePtr->ActiveEnable) && (TRUE == txIpduStatePtr->Transmiting))
        {
            /*data retry offset*/
            if ((NULL_PTR != retry) && (TP_DATARETRY == retry->TpDataState))
            {
                if (txIpduStatePtr->TxOffset >= retry->TxTpDataCnt)
                {
                    txIpduStatePtr->TxOffset = txIpduStatePtr->TxOffset - (uint16)retry->TxTpDataCnt;
                }
                /*will not happen general,TP module guarantee*/
                else
                {
                    txIpduStatePtr->TxOffset = 0u;
                }
            }
            sduLength = info->SduLength;
            if ((txIpduStatePtr->TxOffset + (uint16)sduLength) <= txIpduStatePtr->TxIpduLength)
            {
                copyStartPos = txIpduPtr->ComTxIPduBufIndex + txIpduStatePtr->TxOffset;
                /*copy the TX data from TX PDU buffer*/
                for (cnt = 0u; cnt < sduLength; cnt++)
                {
                    info->SduDataPtr[cnt] = Com_TxIPduRuntimeBuff[copyStartPos + cnt];
                }
/*copy the meta data from Tx Pdu Buffer*/
#if (STD_ON == COM_METADATA_SUPPORT)
                metaDataLength = txIpduPtr->MetaDataLength;
                if ((0u < metaDataLength) && (NULL_PTR != info->MetaDataPtr))
                {
                    metaDataStartId = (uint16)txIpduPtr->IPduNoDynSignalLength
                                      + (uint16)txIpduPtr->IPduMaxDynSignalLength + txIpduPtr->ComTxIPduBufIndex;
                    for (cnt = 0u; cnt < metaDataLength; cnt++)
                    {
                        info->MetaDataPtr[cnt] = Com_TxIPduRuntimeBuff[metaDataStartId + cnt];
                    }
                }
#endif
                txIpduStatePtr->TxOffset += (uint16)sduLength;
                *availableDataPtr =
                    (PduLengthType)txIpduStatePtr->TxIpduLength - (PduLengthType)txIpduStatePtr->TxOffset;
                bufReq = BUFREQ_OK;
            }
        }
#endif /*(0u < COM_TXIPDU_NUMBER) && (STD_ON == COM_TXTPPDU_SUPPORT)*/
    }
    COM_NOUSED(id);
    COM_NOUSED(info);
    COM_NOUSED(retry);
    COM_NOUSED(availableDataPtr);
    return bufReq;
}
#define COM_STOP_SEC_COMCOPYTXDATA_CALLBACK_CODE
#include "Com_MemMap.h"
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* called by Com_Init
 * Init the Pdu Runtime Manager and Buffer*/
static FUNC(void, COM_CODE) Com_PduRTAndBufferInit(void)
{
    uint16 cirCnt;
#if (0u < COM_RXIPDU_NUMBER)
    /* Rx IPdu's RunTimeState init */
    for (cirCnt = 0u; cirCnt < COM_RXIPDU_NUMBER; cirCnt++)
    {
        Com_RxIPduRunTimeState[cirCnt] = Com_RxIPduInitState[cirCnt];
    }
#endif
#if (0u < COM_TXIPDU_NUMBER)
    /* Tx IPdu's RunTimeState init */
    for (cirCnt = 0u; cirCnt < COM_TXIPDU_NUMBER; cirCnt++)
    {
        Com_TxIPduRunTimeState[cirCnt] = Com_TxIPduInitState[cirCnt];
    }
#endif
#if (0u < COM_TXIPDUBUFF_SIZE)
    /* TxIPdu Init value, based on signal or group signal init value */
    for (cirCnt = 0u; cirCnt < COM_TXIPDUBUFF_SIZE; cirCnt++)
    {
        Com_TxIPduRuntimeBuff[cirCnt] = Com_TxIPduInitValue[cirCnt];
    }
#endif
#if (0u < COM_RXIPDUBUFF_SIZE)
    /* RxIPdu Init value, based on signal or group signal init value */
    for (cirCnt = 0u; cirCnt < COM_RXIPDUBUFF_SIZE; cirCnt++)
    {
        Com_RxIPduRuntimeBuff[cirCnt] = Com_RxIPduInitValue[cirCnt];
    }
#endif
    return;
}

/* called by Com_Init
 * Init the Runtime RxSignal/RxGroupSignal Buffer*/
static FUNC(void, COM_CODE) Com_SignalBufferInit(void)
{
    uint16 cirCnt;
#if (0u < COM_SIGNAL_BOOLBUFF_SIZE)
    /* Bool signal Runtime value, based on bool signals or dest description(source description signals are not included)
     * signals init value */
    for (cirCnt = 0u; cirCnt < COM_SIGNAL_BOOLBUFF_SIZE; cirCnt++)
    {
#if (0u < COM_RXGROUPSIGNAL_BOOLBUFF_SIZE)
        if (cirCnt < COM_RXGROUPSIGNAL_BOOLBUFF_SIZE)
        {
            Com_RxGroupSignalBoolShadowBuff[cirCnt] = Com_SignalBoolInitValue[cirCnt];
        }
#endif /*0u < COM_RXGROUPSIGNAL_BOOLBUFF_SIZE*/
        Com_SignalBoolRuntimeBuff[cirCnt] = Com_SignalBoolInitValue[cirCnt];
    }
#endif /* 0u < COM_SIGNAL_BOOLBUFF_SIZE */
#if (0u < COM_SIGNAL_8BITBUFF_SIZE)
    /* 8Bit signal Runtime value, based on uint8, sint8, uint8N,uint8DYN signals or dest description(source description
     * signals are not included) init value */
    for (cirCnt = 0u; cirCnt < COM_SIGNAL_8BITBUFF_SIZE; cirCnt++)
    {
#if (0u < COM_RXGROUPSIGNAL_8BITBUFF_SIZE)
        if (cirCnt < COM_RXGROUPSIGNAL_8BITBUFF_SIZE)
        {
            Com_RxGroupSignal8BitShadowBuff[cirCnt] = Com_Signal8BitInitValue[cirCnt];
        }
#endif /* 0u < COM_RXGROUPSIGNAL_8BITBUFF_SIZE */
        Com_Signal8BitRuntimeBuff[cirCnt] = Com_Signal8BitInitValue[cirCnt];
    }
#endif /* 0u < COM_SIGNAL_8BITBUFF_SIZE */
#if (0u < COM_SIGNAL_16BITBUFF_SIZE)
    /* 16Bit signal Runtime value, based on uint16, sint16 signals or dest description(source description signals are
     * not included) signals init value */
    for (cirCnt = 0u; cirCnt < COM_SIGNAL_16BITBUFF_SIZE; cirCnt++)
    {
#if (0u < COM_RXGROUPSIGNAL_16BITBUFF_SIZE)
        if (cirCnt < COM_RXGROUPSIGNAL_16BITBUFF_SIZE)
        {
            Com_RxGroupSignal16BitShadowBuff[cirCnt] = Com_Signal16BitInitValue[cirCnt];
        }
#endif /* 0u < COM_RXGROUPSIGNAL_16BITBUFF_SIZE */
        Com_Signal16BitRuntimeBuff[cirCnt] = Com_Signal16BitInitValue[cirCnt];
    }
#endif /* 0u < COM_SIGNAL_16BITBUFF_SIZE */
#if (0u < COM_SIGNAL_32BITBUFF_SIZE)
    /* 32Bit signal Runtime value, based on uint32, sint32,float32 signals or dest description(source description
     * signals are not included) signals init value */
    for (cirCnt = 0u; cirCnt < COM_SIGNAL_32BITBUFF_SIZE; cirCnt++)
    {
#if (0u < COM_RXGROUPSIGNAL_32BITBUFF_SIZE)
        if (cirCnt < COM_RXGROUPSIGNAL_32BITBUFF_SIZE)
        {
            Com_RxGroupSignal32BitShadowBuff[cirCnt] = Com_Signal32BitInitValue[cirCnt];
        }
#endif /* 0u < COM_RXGROUPSIGNAL_32BITBUFF_SIZE */
        Com_Signal32BitRuntimeBuff[cirCnt] = Com_Signal32BitInitValue[cirCnt];
    }
#endif /* 0u < COM_SIGNAL_32BITBUFF_SIZE */
#if (0u < COM_SIGNAL_64BITBUFF_SIZE)
    /* 64Bit signal Runtime value, based on uint64, sint64,float64 signals or dest description(source description
     * signals are not included) signals init value */
    for (cirCnt = 0u; cirCnt < COM_SIGNAL_64BITBUFF_SIZE; cirCnt++)
    {
#if (0u < COM_RXGROUPSIGNAL_64BITBUFF_SIZE)
        if (cirCnt < COM_RXGROUPSIGNAL_64BITBUFF_SIZE)
        {
            Com_RxGroupSignal64BitShadowBuff[cirCnt] = Com_Signal64BitInitValue[cirCnt];
        }
#endif /* 0u < COM_RXGROUPSIGNAL_32BITBUFF_SIZE */
        Com_Signal64BitRuntimeBuff[cirCnt] = Com_Signal64BitInitValue[cirCnt];
    }
#endif /* 0u < COM_SIGNAL_64BITBUFF_SIZE */
    return;
}

/* called by Com_MainFunctionRx
 * RxSignal receive timeout handle*/
#if ((0u < COM_RXIPDU_NUMBER) && (COM_RXSIGNAL_NUMBER > 0u) && (STD_ON == COM_RX_SIGNAL_TIMEOUT_ENABLE))
static FUNC(void, COM_CODE) Com_RxSignalTimeOutHandle(PduIdType rxIpduId)
{
    Com_SignalIdType ipduSignalRefNumber, cnt;
    Com_SignalIdType rxSignalId;
    uint16 timeCntIndex;
#if (STD_ON == COM_RX_SIGNAL_TIMEOUT_ACTION_REPLACE_ENABLE)
    Com_SignalType signalType;
    uint16 initValueLength;
    uint16 initValueId;
#endif /* #if (STD_ON == COM_RX_SIGNAL_TIMEOUT_ACTION_REPLACE_ENABLE) */
    const Com_RxIPduType* rxIpduPtr;
    const Com_RxSignalType* rxSignalPtr;
#if (COM_RXSIGNALMASKNEWDIFFERMASKOLD_NUMBER > 0u)
    Com_SignalIdType maskNewDifferMaskOldId;
#endif
    rxIpduPtr = &Com_ConfigStd->ComRxIPdu[rxIpduId];
    ipduSignalRefNumber = rxIpduPtr->ComIPduSignalsRefNumber;
    for (cnt = 0u; cnt < ipduSignalRefNumber; cnt++)
    {
        rxSignalId = rxIpduPtr->ComIPduSignalsRef[cnt];
        rxSignalPtr = &Com_ConfigStd->ComRxSignal[rxSignalId];
        timeCntIndex = rxSignalPtr->ComTimeCntIndex;
        if (Com_TimeOutCnt[timeCntIndex] > 0u)
        {
            (Com_TimeOutCnt[timeCntIndex]) -= 1u;
            if (0u == Com_TimeOutCnt[timeCntIndex])
            {
/*let pass any value for the filter MASKED_NEW_DIFFERS_MASKED_OLD after an RX deadline timeout*/
#if (COM_RXSIGNALMASKNEWDIFFERMASKOLD_NUMBER > 0u)
                if ((NULL_PTR != rxSignalPtr->ComFilter)
                    && (COM_MASKED_NEW_DIFFERS_MASKED_OLD == rxSignalPtr->ComFilter->ComFilterAlgorithm))
                {
                    maskNewDifferMaskOldId = rxSignalPtr->ComFilter->ComMaskNewDifferMaskOldId;
                    Com_MaskNewDifferMaskOldTimeOut[maskNewDifferMaskOldId] = TRUE;
                }
#endif
                /*handle the timeout replace action*/
#if (STD_ON == COM_RX_SIGNAL_TIMEOUT_ACTION_REPLACE_ENABLE)
                if (COM_TIMEOUT_ACTION_REPLACE == rxSignalPtr->ComRxDataTimeoutAction)
                {
                    initValueId = rxSignalPtr->ComSignalInitValueId;
                    signalType = rxSignalPtr->ComSignalType;
#if (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE) || (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_N_ENABLE)
                    if ((COM_UINT8_DYN != signalType) && (COM_UINT8_N != signalType))
#endif /* (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE) || (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_N_ENABLE) */
                    {
                        initValueLength = 0u;
                    }
#if (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE) || (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_N_ENABLE)
                    else
                    {
#if (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE)
                        if (COM_UINT8_DYN == signalType)
                        {
                            initValueLength = rxSignalPtr->ComSignalDataInitValueLength;
                            Com_RxIPduRunTimeState[rxIpduId].RxIpduLength =
                                (uint16)rxIpduPtr->IPduNoDynSignalLength + initValueLength;
                        }
#endif /* (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE) */
#if (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_N_ENABLE)
                        if (COM_UINT8_N == signalType)
                        {
                            initValueLength = rxSignalPtr->ComSignalLength;
                        }
#endif /* (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_N_ENABLE) */
                    }
#endif /* (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE) || (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_N_ENABLE) */
                    Com_InitSignalBuffer(signalType, initValueId, initValueLength);
                }
#endif /* (STD_ON == COM_RX_SIGNAL_TIMEOUT_ACTION_REPLACE_ENABLE) */
#if (STD_ON == COM_RX_SIGNAL_TIMEOUT_NOTIFICATION_ENABLE)
                if (NULL_PTR != rxSignalPtr->ComTimeoutNotification)
                {
                    rxSignalPtr->ComTimeoutNotification();
                }
#endif /* (STD_ON == COM_RX_SIGNAL_TIMEOUT_NOTIFICATION_ENABLE) */
                Com_TimeOutCnt[timeCntIndex] = rxSignalPtr->ComTimeout;
            }
        }
    }
    return;
}
#endif /*#if ((0u < COM_RXIPDU_NUMBER) && (COM_RXSIGNAL_NUMBER > 0u) && (STD_ON == COM_RX_SIGNAL_TIMEOUT_ENABLE))*/

/* called by Com_MainFunctionRx
 * RxSignalGroup receive timeout handle*/
#if ((0u < COM_RXIPDU_NUMBER) && (COM_RXSIGNALGROUP_NUMBER > 0u) && (STD_ON == COM_RX_SIG_GROUP_TIMEOUT_ENABLE))
static FUNC(void, COM_CODE) Com_RxSignalGroupTimeOutHandle(PduIdType rxIpduId)
{
    uint16 timeCntIndex;
    Com_SignalGroupIdType cnt;
    Com_SignalType signalType;
    uint16 initValueLength;
    uint16 initValueId;
    Com_SignalGroupIdType ipduSignalGroupNumber;
    Com_SignalGroupIdType rxSignalGroupId;
    Com_SignalIdType groupSignalNumber;
    Com_SignalIdType counter;
    Com_SignalIdType groupSignalId;
#if (STD_ON == COM_ENABLE_SIGNAL_GROUP_ARRAY_API)
    uint16 iPduStartBufferId;
    uint16 signalGroupArrayLength;
#endif /*STD_ON == COM_ENABLE_SIGNAL_GROUP_ARRAY_API*/
#if (COM_RXSIGNALMASKNEWDIFFERMASKOLD_NUMBER > 0u)
    Com_SignalIdType maskNewDifferMaskOldId;
#endif
    const Com_RxSignalGroupType* rxSignalGroupPtr;
    Com_RxGroupSignalType* rxGroupSignalPtr;
    const Com_RxIPduType* rxIpduPtr = &Com_ConfigStd->ComRxIPdu[rxIpduId];

    ipduSignalGroupNumber = rxIpduPtr->ComIPduSignalGroupsRefNumber;
    for (cnt = 0u; cnt < ipduSignalGroupNumber; cnt++)
    {
        rxSignalGroupId = rxIpduPtr->ComIPduSignalGroupsRef[cnt];
        rxSignalGroupPtr = &Com_ConfigStd->ComRxSignalGroup[rxSignalGroupId];
        timeCntIndex = rxSignalGroupPtr->ComTimeoutCntIndex;
        if (Com_TimeOutCnt[timeCntIndex] > 0u)
        {
            (Com_TimeOutCnt[timeCntIndex]) -= 1u;
            if (0u == Com_TimeOutCnt[timeCntIndex])
            {
                groupSignalNumber = rxSignalGroupPtr->ComGroupSignalNumber;
#if (COM_RXSIGNALMASKNEWDIFFERMASKOLD_NUMBER > 0u)
                for (counter = 0u; counter < groupSignalNumber; counter++)
                {
                    groupSignalId = rxSignalGroupPtr->ComRxGroupSignalId[counter];
                    rxGroupSignalPtr = &Com_ConfigStd->ComRxGroupSignal[groupSignalId];
                    if ((NULL_PTR != rxGroupSignalPtr->ComFilter)
                        && (COM_MASKED_NEW_DIFFERS_MASKED_OLD == rxGroupSignalPtr->ComFilter->ComFilterAlgorithm))
                    {
                        maskNewDifferMaskOldId = rxGroupSignalPtr->ComFilter->ComMaskNewDifferMaskOldId;
                        Com_MaskNewDifferMaskOldTimeOut[maskNewDifferMaskOldId] = TRUE;
                    }
                }
#endif
#if (STD_ON == COM_RX_SIG_GROUP_TIMEOUT_ACTION_REPLACE_ENABLE)
                if (COM_TIMEOUT_ACTION_REPLACE == rxSignalGroupPtr->ComRxDataTimeoutAction)
                {
/*replace the rx pdu buffer for signal group array*/
#if (STD_ON == COM_ENABLE_SIGNAL_GROUP_ARRAY_API)
                    if (NULL_PTR != rxSignalGroupPtr->ComSignalGroupArray)
                    {
                        iPduStartBufferId = rxSignalGroupPtr->ComSignalGroupArray->ComIPduStartBufIndex;
                        signalGroupArrayLength = rxSignalGroupPtr->ComSignalGroupArray->SignalGroupArrayLength;
                        for (counter = 0u; counter < signalGroupArrayLength; counter++)
                        {
                            Com_RxIPduRuntimeBuff[iPduStartBufferId + counter] =
                                Com_RxIPduInitValue[iPduStartBufferId + counter];
                        }
                    }
#endif
                    /*replace the signal group(include all group signals) value with init value*/
                    for (counter = 0u; counter < groupSignalNumber; counter++)
                    {
                        groupSignalId = rxSignalGroupPtr->ComRxGroupSignalId[counter];
                        rxGroupSignalPtr = &Com_ConfigStd->ComRxGroupSignal[groupSignalId];
                        initValueId = rxGroupSignalPtr->ComSignalInitValueId;
                        signalType = rxGroupSignalPtr->ComSignalType;
#if (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE)
                        if ((COM_UINT8_DYN != signalType) && (COM_UINT8_N != signalType))
#endif /* (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE) \
        */
                        {
                            initValueLength = 0u;
                        }
#if (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE)
                        else
                        {
#if (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE)
                            if (COM_UINT8_DYN == signalType)
                            {
                                initValueLength = rxGroupSignalPtr->ComSignalDataInitValueLength;
                                Com_RxIPduRunTimeState[rxIpduId].RxIpduLength =
                                    (uint16)rxIpduPtr->IPduNoDynSignalLength + initValueLength;
                            }
#endif /* (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE) */
#if (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_N_ENABLE)
                            if (COM_UINT8_N == signalType)
                            {
                                initValueLength = rxGroupSignalPtr->ComSignalLength;
                            }
#endif /* (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_N_ENABLE) */
                        }
#endif /* (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE) \
        */
                        Com_InitSignalBuffer(signalType, initValueId, initValueLength);
                    }
                }
#endif /* (STD_ON == COM_RX_SIG_GROUP_TIMEOUT_ACTION_REPLACE_ENABLE) */
#if (STD_ON == COM_RX_SIG_GROUP_TIMEOUT_NOTIFICATION_ENABLE)
                if (NULL_PTR != rxSignalGroupPtr->ComTimeoutNotification)
                {
                    rxSignalGroupPtr->ComTimeoutNotification();
                }
#endif /* (STD_ON == COM_RX_SIG_GROUP_TIMEOUT_NOTIFICATION_ENABLE) */
                Com_TimeOutCnt[timeCntIndex] = rxSignalGroupPtr->ComTimeout;
            }
        }
    }
}
#endif /*#if ((0u < COM_RXIPDU_NUMBER) && (COM_RXSIGNALGROUP_NUMBER > 0u) && (STD_ON == \
          COM_RX_SIG_GROUP_TIMEOUT_ENABLE))*/

/*Called by Com_MainFunctionTx.
 *Send the tx pdu in Com_MainFunctionTx*/
#if (0u < COM_TXIPDU_NUMBER)
static FUNC(void, COM_CODE) Com_MainFunction_SendPdu(PduIdType txIpduId)
{
    //static uint8 Com_SendFlag = 0;
    Com_TxIPduRunTimeStateType* txIpduStatePtr = &Com_TxIPduRunTimeState[txIpduId];
    const Com_TxIPduType* txIpduPtr = &Com_ConfigStd->ComTxIPdu[txIpduId];
    PduInfoType pduInfo;
    uint16 ipduBufferId = txIpduPtr->ComTxIPduBufIndex;
    uint16 ipduLength = txIpduStatePtr->TxIpduLength;
#if (STD_ON == COM_METADATA_SUPPORT)
    uint8 metaDataLength;
    uint16 metaDataPos;
#endif
    uint8 txPduCounter = 0u;
    boolean ret = TRUE;

#if (STD_ON == COM_TX_IPDU_COUNTER_ENABLE)
    if (NULL_PTR != txIpduPtr->ComIPduCounter)
    {
        /*Pack the counter value in the pdu buffer*/
        Com_PackCounterValue(txIpduId);
        /*recover the active counter value if the transmit is E_NOT_OK*/
        txPduCounter = txIpduStatePtr->TxIpduCounter;
        /*Increase the counter value by +1*/
        Com_PduCounterIncrease(TRUE, txIpduId);
    }
#endif /* (STD_ON == COM_TX_IPDU_COUNTER_ENABLE) */
    pduInfo.SduDataPtr = &Com_TxIPduRuntimeBuff[ipduBufferId];
    pduInfo.SduLength = ipduLength;
#if (STD_ON == COM_METADATA_SUPPORT)
    metaDataLength = txIpduPtr->MetaDataLength;
    if (0u < metaDataLength)
    {
        metaDataPos =
            (uint16)txIpduPtr->IPduNoDynSignalLength + (uint16)txIpduPtr->IPduMaxDynSignalLength + ipduBufferId;
        pduInfo.MetaDataPtr = &Com_TxIPduRuntimeBuff[metaDataPos];
    }
    else
#endif /* STD_ON == COM_METADATA_SUPPORT) */
    {
        pduInfo.MetaDataPtr = NULL_PTR;
    }
#if (STD_ON == COM_TX_IPDU_CALLOUT_ENABLE)
    /*invoke the callout API*/
    if (NULL_PTR != txIpduPtr->ComIPduCallout)
    {
        ret = txIpduPtr->ComIPduCallout(txIpduId + COM_RXIPDU_NUMBER, &pduInfo);
    }
    if (TRUE == ret)
#endif /* (STD_ON == COM_TX_IPDU_CALLOUT_ENABLE) */
    {
#if (STD_ON == COM_TX_IPDU_TYPE_TP_ENABLE)
        if (COM_PDU_TP == txIpduPtr->ComIPduType)
        {
            pduInfo.SduDataPtr = NULL_PTR;
        }
#endif /* (STD_ON == COM_TX_IPDU_TYPE_TP_ENABLE) */
        /*Set the Transmiting flag before call PduR_Transmit,
         *avoid the TxConfirmation come before set the Transmiting flag*/
        txIpduStatePtr->Transmiting = TRUE;
        if (E_OK == PduR_ComTransmit(txIpduPtr->ComPduIdRef, &pduInfo))
        {
            if (TRUE == txIpduStatePtr->TxDelay)
            {
                txIpduStatePtr->TxDelay = FALSE;
            }
/*Reset Tx_IPduMDT*/
#if (STD_ON == COM_ENABLE_MDT_FOR_CYCLIC_TRANSMISSION)
#if (STD_ON == COM_MDT_ENABLE)
            txIpduStatePtr->MDTCnt = txIpduPtr->ComMinimumDelayTime;
#endif /* (STD_ON == COM_MDT_ENABLE) */
#else
#if (STD_ON == COM_TX_MODE_DIRECT_ENABLE) && (STD_ON == COM_MDT_ENABLE)
            if (COM_TX_MODE_DIRECT == txIpduStatePtr->ipduTxMode)
            {
                if (1u == txIpduStatePtr->RptNum)
                {
                    txIpduStatePtr->MDTCnt = txIpduPtr->ComMinimumDelayTime;
                }
            }
#endif /* (STD_ON == COM_TX_MODE_DIRECT_ENABLE) && (STD_ON == COM_MDT_ENABLE) */
#endif /*STD_ON ==COM_ENABLE_MDT_FOR_CYCLIC_TRANSMISSION*/
#if (STD_ON == COM_TX_SIG_GROUP_UPDATE_BIT_ENABLE) || (STD_ON == COM_TX_SIGNAL_UPDATE_BIT_ENABLE) \
    || (STD_ON == COM_GW_DEST_SIG_UPDATE_BIT_ENABLE)
            if (COM_TRANSMIT == txIpduPtr->ComTxIPduClearUpdateBit)
            {
                /*clear all signal group/signal/dest description signal update bit of the Tx Pdu*/
                Com_ClearTxIPduUpdates(txIpduId);
            }
#endif /* (STD_ON == COM_TX_SIG_GROUP_UPDATE_BIT_ENABLE) || (STD_ON == COM_TX_SIGNAL_UPDATE_BIT_ENABLE) || (STD_ON == \
COM_GW_DEST_SIG_UPDATE_BIT_ENABLE) */
            txIpduStatePtr->TxOffset = 0u;
        }
        else
        {
            //ComTXCounter5MS++;
            txIpduStatePtr->Transmiting = FALSE;
#if (STD_ON == COM_TX_IPDU_COUNTER_ENABLE)
            if (NULL_PTR != txIpduPtr->ComIPduCounter)
            {
                /*transmit not OK,recover the old counter value*/
                txIpduStatePtr->TxIpduCounter = txPduCounter;
            }
#endif /* (STD_ON == COM_TX_IPDU_COUNTER_ENABLE) */
/*ComRetryFailedTransmitRequests*/
#if (STD_ON == COM_RETRY_FAILED_TRANSMIT_REQUESTS)
            txIpduStatePtr->TxDelay = TRUE;
#else
            /* CancelTx(Direct/N component) */
            txIpduStatePtr->RptNum = 0u;
            txIpduStatePtr->NTimeCnt = 0u;
/*Reset Tx_IPduMDT*/
#if (STD_ON == COM_ENABLE_MDT_FOR_CYCLIC_TRANSMISSION)
#if (STD_ON == COM_MDT_ENABLE)
            txIpduStatePtr->MDTCnt = txIpduPtr->ComMinimumDelayTime;
#endif /* (STD_ON == COM_MDT_ENABLE) */
#else
#if (STD_ON == COM_TX_MODE_DIRECT_ENABLE) && (STD_ON == COM_MDT_ENABLE)
            if (COM_TX_MODE_DIRECT == txIpduStatePtr->ipduTxMode)
            {
                if (1u == txIpduStatePtr->RptNum)
                {
                    txIpduStatePtr->MDTCnt = txIpduPtr->ComMinimumDelayTime;
                }
            }
#endif /* (STD_ON == COM_TX_MODE_DIRECT_ENABLE) && (STD_ON == COM_MDT_ENABLE) */
#endif /* STD_ON ==COM_ENABLE_MDT_FOR_CYCLIC_TRANSMISSION */
#endif /* (STD_ON == COM_RETRY_FAILED_TRANSMIT_REQUESTS) */
        }
    }
#if (STD_ON == COM_TX_IPDU_CALLOUT_ENABLE) && (STD_ON == COM_TX_IPDU_COUNTER_ENABLE)
    else
    {
        if (NULL_PTR != txIpduPtr->ComIPduCounter)
        {
            /*transmit not OK,recover the old counter value*/
            txIpduStatePtr->TxIpduCounter = txPduCounter;
        }
    }
#endif /* (STD_ON == COM_TX_IPDU_CALLOUT_ENABLE) && (STD_ON == COM_TX_IPDU_COUNTER_ENABLE) */
    return;
}
#endif /*0u < COM_TXIPDU_NUMBER*/

/*Called by Com_ReceiveSignal.
 *Receive signal handle*/
#if (0u < COM_RXSIGNAL_NUMBER)
static FUNC(uint8, COM_CODE)
    Com_ReceiveSignalHandle(Com_SignalIdType SignalId, P2VAR(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr)
{
    const Com_RxSignalType* rxSignalPtr = &Com_ConfigStd->ComRxSignal[SignalId];
    uint8 ret = COM_SERVICE_NOT_AVAILABLE;
    PduIdType ipduRef = rxSignalPtr->ComIpduRefIndex;
    uint16 signalInitValueId;
#if (0u < COM_SIGNAL_8BITBUFF_SIZE)
    uint16 valueLoop;
    uint16 signalLength;
#endif

    /*IPDU is not receiving data*/
    if (FALSE == Com_RxIPduRunTimeState[ipduRef].Receiving)
    {
        signalInitValueId = rxSignalPtr->ComSignalInitValueId;
        /* Get signal type, decide signal value is in which Runtime buffer */
        switch (rxSignalPtr->ComSignalType)
        {
#if (0u < COM_SIGNAL_BOOLBUFF_SIZE)
        case COM_BOOLEAN:
            *((boolean*)SignalDataPtr) = Com_SignalBoolRuntimeBuff[signalInitValueId];
            break;
#endif
#if (0u < COM_SIGNAL_8BITBUFF_SIZE)
        case COM_UINT8:
        case COM_SINT8:
            *((uint8*)SignalDataPtr) = Com_Signal8BitRuntimeBuff[signalInitValueId];
            break;
        case COM_UINT8_N:
            signalLength = rxSignalPtr->ComSignalLength;
            /* Copy Uint8N signal value one byte by one */
            for (valueLoop = 0u; valueLoop < signalLength; valueLoop++)
            {
                ((uint8*)SignalDataPtr)[valueLoop] = Com_Signal8BitRuntimeBuff[signalInitValueId + valueLoop];
            }
            break;
#endif
#if (0u < COM_SIGNAL_16BITBUFF_SIZE)
        case COM_UINT16:
        case COM_SINT16:
            *((uint16*)SignalDataPtr) = Com_Signal16BitRuntimeBuff[signalInitValueId];
            break;
#endif
#if (0u < COM_SIGNAL_32BITBUFF_SIZE)
        case COM_SINT32:
        case COM_UINT32:
            *((uint32*)SignalDataPtr) = Com_Signal32BitRuntimeBuff[signalInitValueId];
            break;
        case COM_FLOAT32:
            *((float32*)SignalDataPtr) = *(float32*)(&Com_Signal32BitRuntimeBuff[signalInitValueId]);
            break;
#endif
#if (0u < COM_SIGNAL_64BITBUFF_SIZE)
        case COM_SINT64:
        case COM_UINT64:
            *((uint64*)SignalDataPtr) = Com_Signal64BitRuntimeBuff[signalInitValueId];
            break;
        case COM_FLOAT64:
            *((float64*)SignalDataPtr) = *(float64*)(&Com_Signal64BitRuntimeBuff[signalInitValueId]);
            break;
#endif
        default:
            /*do nothing*/
            break;
        }
        /* Check IPdu which this Signal belonged is Active or not */
        if (TRUE == Com_RxIPduRunTimeState[ipduRef].ActiveEnable)
        {
            ret = E_OK;
        }
    }
    else
    {
        ret = COM_BUSY;
    }
    return ret;
}
#endif /*0u < COM_RXSIGNAL_NUMBER*/

/*Called by Com_ReceiveSignal.
 *Receive group signal handle*/
#if (0u < COM_RXSIGNALGROUP_NUMBER)
static FUNC(uint8, COM_CODE)
    Com_ReceiveGroupSignalHandle(Com_SignalIdType SignalId, P2VAR(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr)
{
    const Com_RxGroupSignalType* rxGroupSignalPtr = &Com_ConfigStd->ComRxGroupSignal[SignalId - COM_RXSIGNAL_NUMBER];
    Com_SignalGroupIdType signalGroupId = rxGroupSignalPtr->ComSignalGroupRef;
    uint8 ret = COM_SERVICE_NOT_AVAILABLE;
    PduIdType ipduRef = Com_ConfigStd->ComRxSignalGroup[signalGroupId].ComIpduRefIndex;
    uint16 signalInitValueId;
#if (0u < COM_RXGROUPSIGNAL_8BITBUFF_SIZE)
    uint16 valueLoop;
    uint16 signalLength;
#endif

    /*TP IPDU is not receiving data*/
    if (FALSE == Com_RxIPduRunTimeState[ipduRef].Receiving)
    {
        signalInitValueId = rxGroupSignalPtr->ComSignalInitValueId;
        /* Get signal type, decide signal value is in which Runtime buffer */
        switch (rxGroupSignalPtr->ComSignalType)
        {
#if (0u < COM_RXGROUPSIGNAL_BOOLBUFF_SIZE)
        case COM_BOOLEAN:
            *((boolean*)SignalDataPtr) = Com_RxGroupSignalBoolShadowBuff[signalInitValueId];
            break;
#endif
#if (0u < COM_RXGROUPSIGNAL_8BITBUFF_SIZE)
        case COM_UINT8:
        case COM_SINT8:
            *((uint8*)SignalDataPtr) = Com_RxGroupSignal8BitShadowBuff[signalInitValueId];
            break;
        case COM_UINT8_N:
            signalLength = rxGroupSignalPtr->ComSignalLength;
            /* Copy Uint8N signal value one byte by one */
            for (valueLoop = 0u; valueLoop < signalLength; valueLoop++)
            {
                ((uint8*)SignalDataPtr)[valueLoop] = Com_RxGroupSignal8BitShadowBuff[signalInitValueId + valueLoop];
            }
            break;
#endif
#if (0u < COM_RXGROUPSIGNAL_16BITBUFF_SIZE)
        case COM_UINT16:
        case COM_SINT16:
            *((uint16*)SignalDataPtr) = Com_RxGroupSignal16BitShadowBuff[signalInitValueId];
            break;
#endif
#if (0u < COM_RXGROUPSIGNAL_32BITBUFF_SIZE)
        case COM_SINT32:
        case COM_UINT32:
            *((uint32*)SignalDataPtr) = Com_RxGroupSignal32BitShadowBuff[signalInitValueId];
            break;
        case COM_FLOAT32:
            *((float32*)SignalDataPtr) = *(float32*)(&Com_RxGroupSignal32BitShadowBuff[signalInitValueId]);
            break;
#endif
#if (0u < COM_RXGROUPSIGNAL_64BITBUFF_SIZE)
        case COM_SINT64:
        case COM_UINT64:
            *((uint64*)SignalDataPtr) = Com_RxGroupSignal64BitShadowBuff[signalInitValueId];
            break;
        case COM_FLOAT64:
            *((float64*)SignalDataPtr) = *(float64*)(&Com_RxGroupSignal64BitShadowBuff[signalInitValueId]);
            break;
#endif
        default:
            /*do nothing*/
            break;
        }
        /* Check IPdu which this group signal belonged is Active or not */
        if (TRUE == Com_RxIPduRunTimeState[ipduRef].ActiveEnable)
        {
            ret = E_OK;
        }
    }
    else
    {
        ret = COM_BUSY;
    }
    return ret;
}
#endif /*0u < COM_RXSIGNALGROUP_NUMBER*/

/*Called by Com_RxIndication.
 *Receive Rx Pdu handle*/
#if (0u < COM_RXIPDU_NUMBER)
static FUNC(void, COM_CODE)
    Com_RxPduHandle(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    const Com_RxIPduType* rxIpduPtr = &Com_ConfigStd->ComRxIPdu[RxPduId];
    Com_RxIPduRunTimeStateType* rxIpduStatePtr = &Com_RxIPduRunTimeState[RxPduId];

#if (STD_ON == COM_RX_IPDU_CALLOUT_ENABLE)
    boolean ret = TRUE;
    if (NULL_PTR != rxIpduPtr->ComIPduCallout)
    {
        ret = rxIpduPtr->ComIPduCallout(RxPduId, PduInfoPtr);
    }
    if (TRUE == ret)
#endif /* (STD_ON == COM_RX_IPDU_CALLOUT_ENABLE) */
    {
        /*signal/signal group RxIndication is made immediate*/
#if (STD_ON == COM_RX_IPDU_SIGNAL_PROCESS_IMMEDIATE_ENABLE)
        if (COM_IMMEDIATE == rxIpduPtr->ComIPduSignalProcessing)
        {
            rxIpduStatePtr->RxIndication = FALSE;
            /*rx indication handle*/
            Com_IndicationProcess(RxPduId);
            if (TRUE == rxIpduPtr->IPduGW)
            {
                rxIpduStatePtr->NeedGW = TRUE;
            }
        }
        /*signal/signal group RxIndication is made in next MainFunctionRx*/
        else
#endif /* (STD_ON == COM_RX_IPDU_SIGNAL_PROCESS_IMMEDIATE_ENABLE) */
        {
            rxIpduStatePtr->RxIndication = TRUE;
        }
    }
    return;
}
#endif /*0u < COM_RXIPDU_NUMBER*/

/*Called by Com_SendSignalGroupArray.
 *Send Signal Group handle*/
#if (STD_ON == COM_ENABLE_SIGNAL_GROUP_ARRAY_API)
#if ((0u < COM_TXSIGNALGROUP_NUMBER) && (0u < COM_TXIPDU_NUMBER))
static FUNC(void, COM_CODE) Com_SendSignalGroupArrayHandle(
    Com_SignalGroupIdType SignalGroupId,
    PduIdType ipduRef,
    /* PRQA S 3206 ++ */ /* MISRA Rule 2.7 */
    boolean triggerOnChange,
    /* PRQA S 3206 -- */ /* MISRA Rule 2.7 */
    uint16 rptNum)
{
    boolean initDMCnt = FALSE;
    const Com_TxSignalGroupType* txSignalGroupPtr = &Com_ConfigStd->ComTxSignalGroup[SignalGroupId];
    Com_TxIPduRunTimeStateType* txIpduStatePtr = &Com_TxIPduRunTimeState[ipduRef];
    /*the signal group configuration timeout,the DM timer isn't start by other signals/signal groups,Tx Mode isn't
     * NONE*/
    if ((0u != txSignalGroupPtr->ComTimeout) && (COM_TX_MODE_NONE != txIpduStatePtr->ipduTxMode)
        && (0u == txIpduStatePtr->DMCnt))
    {
        /*restart the tx DM timer*/
        txIpduStatePtr->DMCnt = Com_ConfigStd->ComTxIPdu[ipduRef].ComTxIpduDM;
        initDMCnt = TRUE;
    }
#if (STD_ON == COM_TX_MODE_DIRECT_ENABLE) || (STD_ON == COM_TX_MODE_MIXED_ENABLE)
    if ((COM_TX_MODE_DIRECT == txIpduStatePtr->ipduTxMode) || (COM_TX_MODE_MIXED == txIpduStatePtr->ipduTxMode))
    {
        switch (txSignalGroupPtr->ComTransferProperty)
        {
#if (STD_ON == COM_TX_SIG_GROUP_PROP_TRIGGERED_ENABLE)
        case COM_TRIGGERED:
            txIpduStatePtr->NTimeCnt = 0u;
            txIpduStatePtr->RptNum = rptNum;
            /*For an I-PDU with ComTxModeMode DIRECT and ComTxModeNumberOfRepetitions > 0, the AUTOSAR COM module shall
              reset an already running transmission deadline monitoring timer in case another send request for this
              I-PDU is initiated*/
            if ((1u < rptNum) && (FALSE == initDMCnt) && (0u != txSignalGroupPtr->ComTimeout))
            {
                txIpduStatePtr->DMCnt = Com_ConfigStd->ComTxIPdu[ipduRef].ComTxIpduDM;
            }
            break;
#endif /* (STD_ON == COM_TX_SIG_GROUP_PROP_TRIGGERED_ENABLE) */
#if (STD_ON == COM_TX_SIG_GROUP_PROP_TRIGGERED_ON_CHANGE_ENABLE)
        case COM_TRIGGERED_ON_CHANGE:
            if (TRUE == triggerOnChange)
            {
                txIpduStatePtr->NTimeCnt = 0u;
                txIpduStatePtr->RptNum = rptNum;
                /*For an I-PDU with ComTxModeMode DIRECT and ComTxModeNumberOfRepetitions > 0, the AUTOSAR COM module
                  shall reset an already running transmission deadline monitoring timer in case another send request for
                  this I-PDU is initiated*/
                if ((1u < rptNum) && (FALSE == initDMCnt) && (0u != txSignalGroupPtr->ComTimeout))
                {
                    txIpduStatePtr->DMCnt = Com_ConfigStd->ComTxIPdu[ipduRef].ComTxIpduDM;
                }
            }
            break;
#endif /* (STD_ON == COM_TX_SIG_GROUP_PROP_TRIGGERED_ON_CHANGE_ENABLE) */
#if (STD_ON == COM_TX_SIG_GROUP_PROP_TRIG_ON_CH_NO_REPETITION_ENABLE)
        case COM_TRIGGERED_ON_CHANGE_WITHOUT_REPETITION:
            if (TRUE == triggerOnChange)
            {
                txIpduStatePtr->NTimeCnt = 0u;
                txIpduStatePtr->RptNum = 1u;
            }
            break;
#endif /* (STD_ON == COM_TX_SIG_GROUP_PROP_TRIG_ON_CH_NO_REPETITION_ENABLE) */
#if (STD_ON == COM_TX_SIG_GROUP_PROP_TRIG_NO_REPETITION_ENABLE)
        case COM_TRIGGERED_WITHOUT_REPETITION:
            txIpduStatePtr->NTimeCnt = 0u;
            txIpduStatePtr->RptNum = 1u;
            break;
#endif /* (STD_ON == COM_TX_SIG_GROUP_PROP_TRIG_NO_REPETITION_ENABLE) */
        default:
            /*do nothing*/
            break;
        }
    }
    else
#endif /* (STD_ON == COM_TX_MODE_DIRECT_ENABLE) || (STD_ON == COM_TX_MODE_MIXED_ENABLE) */
    {
        txIpduStatePtr->NTimeCnt = 0u;
        txIpduStatePtr->RptNum = 0u;
    }
    return;
}
#endif /*(0u < COM_TXSIGNALGROUP_NUMBER) && (0u < COM_TXIPDU_NUMBER)*/
#endif /*STD_ON == COM_ENABLE_SIGNAL_GROUP_ARRAY_API*/

/*Called by Com_TriggerIPDUSend,Com_TriggerIPDUSendWithMetaData.
 *Trigger IPdu Send handle*/
#if (0u < COM_TXIPDU_NUMBER)
static FUNC(Std_ReturnType, COM_CODE) Com_TriggerIPDUSendHandle(PduIdType txIpduId)
{
    const Com_TxIPduType* txIpduPtr = &Com_ConfigStd->ComTxIPdu[txIpduId];
    Com_TxIPduRunTimeStateType* txIpduStatePtr = &Com_TxIPduRunTimeState[txIpduId];
    uint16 ipduBufferId = txIpduPtr->ComTxIPduBufIndex;
    uint16 ipduLength = txIpduStatePtr->TxIpduLength;
#if (STD_ON == COM_METADATA_SUPPORT)
    uint8 metaDataLength;
    uint16 metaDataStartId;
#endif
    PduInfoType pduInfo;
    boolean ret = TRUE;
    uint8 txPduCounter = 0u;
    Std_ReturnType returnValue = E_NOT_OK;

#if (STD_ON == COM_TX_IPDU_COUNTER_ENABLE)
    if (NULL_PTR != txIpduPtr->ComIPduCounter)
    {
        /*Pack the counter value in the pdu buffer*/
        Com_PackCounterValue(txIpduId);
        /*recover the active counter value if the transmit is E_NOT_OK*/
        txPduCounter = txIpduStatePtr->TxIpduCounter;
        /*Increase the counter value by +1*/
        Com_PduCounterIncrease(TRUE, txIpduId);
    }
#endif /* (STD_ON == COM_TX_IPDU_COUNTER_ENABLE) */
    pduInfo.SduDataPtr = &Com_TxIPduRuntimeBuff[ipduBufferId];
    pduInfo.SduLength = (PduLengthType)ipduLength;
#if (STD_ON == COM_METADATA_SUPPORT)
    metaDataLength = txIpduPtr->MetaDataLength;
    if (0u < metaDataLength)
    {
        metaDataStartId =
            (uint16)txIpduPtr->IPduNoDynSignalLength + (uint16)txIpduPtr->IPduMaxDynSignalLength + ipduBufferId;
        pduInfo.MetaDataPtr = &Com_TxIPduRuntimeBuff[metaDataStartId];
    }
    else
#endif /* (STD_ON == COM_METADATA_SUPPORT) */
    {
        pduInfo.MetaDataPtr = NULL_PTR;
    }
#if (STD_ON == COM_TX_IPDU_CALLOUT_ENABLE)
    /*invoke the callout API*/
    if (NULL_PTR != txIpduPtr->ComIPduCallout)
    {
        ret = txIpduPtr->ComIPduCallout((txIpduId + (COM_RXIPDU_NUMBER)), &pduInfo);
    }
    if (TRUE == ret)
#endif /* (STD_ON == COM_TX_IPDU_CALLOUT_ENABLE) */
    {
#if (STD_ON == COM_TX_IPDU_TYPE_TP_ENABLE)
        if (COM_PDU_TP == txIpduPtr->ComIPduType)
        {
            pduInfo.SduDataPtr = NULL_PTR;
        }
#endif /* (STD_ON == COM_TX_IPDU_TYPE_TP_ENABLE) */
        txIpduStatePtr->Transmiting = TRUE;
        txIpduStatePtr->TxOffset = 0u;
        if (E_OK == PduR_ComTransmit(txIpduPtr->ComPduIdRef, &pduInfo))
        {
/*Reset Tx_IPduMDT*/
#if (STD_ON == COM_ENABLE_MDT_FOR_CYCLIC_TRANSMISSION)
#if (STD_ON == COM_MDT_ENABLE)
            txIpduStatePtr->MDTCnt = txIpduPtr->ComMinimumDelayTime;
#endif /* (STD_ON == COM_MDT_ENABLE) */
#else
#if (STD_ON == COM_TX_MODE_DIRECT_ENABLE) && (STD_ON == COM_MDT_ENABLE)
            if (COM_TX_MODE_DIRECT == txIpduStatePtr->ipduTxMode)
            {
                if (txIpduStatePtr->RptNum <= 1u)
                {
                    txIpduStatePtr->MDTCnt = txIpduPtr->ComMinimumDelayTime;
                }
            }
#endif /* (STD_ON == COM_TX_MODE_DIRECT_ENABLE) && (STD_ON == COM_MDT_ENABLE) */
#endif /* STD_ON == COM_ENABLE_MDT_FOR_CYCLIC_TRANSMISSION */
#if (STD_ON == COM_TX_SIG_GROUP_UPDATE_BIT_ENABLE) || (STD_ON == COM_TX_SIGNAL_UPDATE_BIT_ENABLE) \
    || (STD_ON == COM_GW_DEST_SIG_UPDATE_BIT_ENABLE)
            if (COM_TRANSMIT == txIpduPtr->ComTxIPduClearUpdateBit)
            {
                /*clear all signal group/signal/dest description signal update bit of the Tx Pdu*/
                Com_ClearTxIPduUpdates(txIpduId);
            }
#endif /* (STD_ON == COM_TX_SIG_GROUP_UPDATE_BIT_ENABLE) || (STD_ON == COM_TX_SIGNAL_UPDATE_BIT_ENABLE) || (STD_ON == \
COM_GW_DEST_SIG_UPDATE_BIT_ENABLE) */
            returnValue = E_OK;
        }
        else
        {
            txIpduStatePtr->Transmiting = FALSE;
#if (STD_ON == COM_TX_IPDU_COUNTER_ENABLE)
            if (NULL_PTR != txIpduPtr->ComIPduCounter)
            {
                /*transmit not OK,recover the old counter value*/
                txIpduStatePtr->TxIpduCounter = txPduCounter;
            }
#endif /* (STD_ON == COM_TX_IPDU_COUNTER_ENABLE) */
/*ComRetryFailedTransmitRequests*/
#if (STD_ON == COM_RETRY_FAILED_TRANSMIT_REQUESTS)
            txIpduStatePtr->TxDelay = TRUE;
            returnValue = E_OK;
#else
#if (STD_ON == COM_ENABLE_MDT_FOR_CYCLIC_TRANSMISSION)
#if (STD_ON == COM_MDT_ENABLE)
            txIpduStatePtr->MDTCnt = txIpduPtr->ComMinimumDelayTime;
#endif /* (STD_ON == COM_MDT_ENABLE) */
#else
#if (STD_ON == COM_TX_MODE_DIRECT_ENABLE) && (STD_ON == COM_MDT_ENABLE)
            if (COM_TX_MODE_DIRECT == txIpduStatePtr->ipduTxMode)
            {
                if (txIpduStatePtr->RptNum <= 1u)
                {
                    txIpduStatePtr->MDTCnt = txIpduPtr->ComMinimumDelayTime;
                }
            }
#endif /* (STD_ON == COM_TX_MODE_DIRECT_ENABLE) && (STD_ON == COM_MDT_ENABLE) */
#endif /* STD_ON == COM_ENABLE_MDT_FOR_CYCLIC_TRANSMISSION */
#endif /* (STD_ON == COM_RETRY_FAILED_TRANSMIT_REQUESTS) */
        }
    }
#if (STD_ON == COM_TX_IPDU_CALLOUT_ENABLE) && (STD_ON == COM_TX_IPDU_COUNTER_ENABLE)
    else
    {
        if (NULL_PTR != txIpduPtr->ComIPduCounter)
        {
            /*transmit not OK,recover the old counter value*/
            txIpduStatePtr->TxIpduCounter = txPduCounter;
        }
    }
#endif /* (STD_ON == COM_TX_IPDU_CALLOUT_ENABLE) && (STD_ON == COM_TX_IPDU_COUNTER_ENABLE) */
    return returnValue;
}
#endif /*0u < COM_TXIPDU_NUMBER*/

/*Called by Com_MainFunctionRouteSignals.
 *Signal/Group Signal/Dest Description Signal handle*/
#if (                                                                                   \
    (0u < COM_GWMAPPING_NUMBER) && (0u < COM_RXIPDU_NUMBER) && (0u < COM_TXIPDU_NUMBER) \
    && (STD_ON == COM_SIGNAL_GW_ENABLE))
static FUNC(void, COM_CODE) Com_RouteSignalHandle(uint16 GwMapId)
{
    const Com_GwMappingType* gwMappingPtr = &Com_ConfigStd->ComGwMapping[GwMapId];
    PduIdType rxIpduId;
    Com_GWSignalType gwSourceSignalType = gwMappingPtr->ComGwSourceSignalType;
    Com_SignalIdType gwSourceSignalId = gwMappingPtr->ComGwSourceSignalId;
    Com_SignalGroupIdType signalGroupId;
#if (COM_GWSOURCESIGNAL_UPDATE_NUMBER > 0u)
    uint32 updateBitPosition;
    uint16 gwUpdataStateId;
#endif

    switch (gwSourceSignalType)
    {
    case COM_SIGNAL:
        rxIpduId = Com_ConfigStd->ComRxSignal[gwSourceSignalId].ComIpduRefIndex;
        if (TRUE == Com_RxIPduRunTimeState[rxIpduId].NeedGW)
        {
#if (COM_GWSOURCESIGNAL_UPDATE_NUMBER > 0u) && (STD_ON == COM_RX_SIGNAL_UPDATE_BIT_ENABLE)
            updateBitPosition = Com_ConfigStd->ComRxSignal[gwSourceSignalId].ComUpdateBitPosition;
            if (COM_UNUSED_UINT32 != updateBitPosition)
            {
                gwUpdataStateId = Com_ConfigStd->ComRxSignal[gwSourceSignalId].GWUpdataStateId;
                /*the update bit is 1*/
                if (TRUE == Com_GWSourceSignalUpdate[gwUpdataStateId])
                {
                    Com_GwSignal(GwMapId, COM_SIGNAL, gwSourceSignalId);
                }
            }
            else
#endif /* (COM_GWSOURCESIGNAL_UPDATE_NUMBER > 0u) && (STD_ON == COM_RX_SIGNAL_UPDATE_BIT_ENABLE) */
            {
                Com_GwSignal(GwMapId, COM_SIGNAL, gwSourceSignalId);
            }
        }
        break;
    case COM_GROUP_SIGNAL:
        signalGroupId = Com_ConfigStd->ComRxGroupSignal[gwSourceSignalId].ComSignalGroupRef;
        rxIpduId = Com_ConfigStd->ComRxSignalGroup[signalGroupId].ComIpduRefIndex;
        if (TRUE == Com_RxIPduRunTimeState[rxIpduId].NeedGW)
        {
#if (COM_GWSOURCESIGNAL_UPDATE_NUMBER > 0u) && (STD_ON == COM_RX_SIG_GROUP_UPDATE_BIT_ENABLE)
            updateBitPosition = Com_ConfigStd->ComRxSignalGroup[signalGroupId].ComUpdateBitPosition;
            if (COM_UNUSED_UINT32 != updateBitPosition)
            {
                gwUpdataStateId = Com_ConfigStd->ComRxSignalGroup[signalGroupId].GWUpdataStateId;
                /*the update bit is 1*/
                if (TRUE == Com_GWSourceSignalUpdate[gwUpdataStateId])
                {
                    Com_GwSignal(GwMapId, COM_GROUP_SIGNAL, gwSourceSignalId);
                }
            }
            else
#endif /* (COM_GWSOURCESIGNAL_UPDATE_NUMBER > 0u) && (STD_ON == COM_RX_SIG_GROUP_UPDATE_BIT_ENABLE) */
            {
                Com_GwSignal(GwMapId, COM_GROUP_SIGNAL, gwSourceSignalId);
            }
        }
        break;
    case COM_DESCRIPTION:
        rxIpduId = Com_ConfigStd->ComSourceSignal[gwSourceSignalId].ComGwIPduRef;
        if (TRUE == Com_RxIPduRunTimeState[rxIpduId].NeedGW)
        {
#if (COM_GWSOURCESIGNAL_UPDATE_NUMBER > 0u) && (STD_ON == COM_GW_SRC_SIG_UPDATE_BIT_ENABLE)
            updateBitPosition = Com_ConfigStd->ComSourceSignal[gwSourceSignalId].ComUpdateBitPosition;
            if (COM_UNUSED_UINT32 != updateBitPosition)
            {
                gwUpdataStateId = Com_ConfigStd->ComSourceSignal[gwSourceSignalId].GWUpdataStateId;
                /*the update bit is 1*/
                if (TRUE == Com_GWSourceSignalUpdate[gwUpdataStateId])
                {
                    Com_GwSignal(GwMapId, COM_DESCRIPTION, gwSourceSignalId);
                }
            }
            else
#endif /* (COM_GWSOURCESIGNAL_UPDATE_NUMBER > 0u) && (STD_ON == COM_GW_SRC_SIG_UPDATE_BIT_ENABLE) */
            {
                Com_GwSignal(GwMapId, COM_DESCRIPTION, gwSourceSignalId);
            }
        }
        break;
    default:
        /*do nothing*/
        break;
    }
    return;
}
#endif /* ((0u < COM_GWMAPPING_NUMBER) && (0u < COM_RXIPDU_NUMBER) && (0u < COM_TXIPDU_NUMBER) && (STD_ON == \
          COM_SIGNAL_GW_ENABLE)) */

#if (0u < COM_RXIPDU_NUMBER)
/*Called by Com_ReceiveDynSignal.
 *Receive Dynamic Signal handle*/
#if ((0u < COM_RXSIGNAL_NUMBER) && (0u < COM_SIGNAL_8BITBUFF_SIZE) && (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE))
static FUNC(uint8, COM_CODE) Com_ReceiveDynSignalHandle(
    Com_SignalIdType SignalId,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr,
    P2VAR(uint16, AUTOMATIC, COM_APPL_CONST) Length)
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
{
    PduIdType ipduRef;
    uint16 valueLoop;
    uint16 signalLength;
    uint16 signalInitValueId;
    uint8 ret = COM_SERVICE_NOT_AVAILABLE;
    ipduRef = Com_ConfigStd->ComRxSignal[SignalId].ComIpduRefIndex;
    /*the signal type must be COM_UINT8_DYN */
    if (COM_UINT8_DYN == Com_ConfigStd->ComRxSignal[SignalId].ComSignalType)
    {
        /*IPDU is not receiving data*/
        if (FALSE == Com_RxIPduRunTimeState[ipduRef].Receiving)
        {
            signalLength =
                (Com_RxIPduRunTimeState[ipduRef].RxIpduLength
                 - (uint16)Com_ConfigStd->ComRxIPdu[ipduRef].IPduNoDynSignalLength);
            if (signalLength > (*Length))
            {
#if (STD_ON == COM_DEV_ERROR_DETECT)
                (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_RECEIVEDYNSIGNAL_ID, COM_E_PARAM);
#endif
                ret = E_NOT_OK;
            }
            else
            {
                signalInitValueId = Com_ConfigStd->ComRxSignal[SignalId].ComSignalInitValueId;
                /* Copy Uint8DYN signal value one byte by one */
                for (valueLoop = 0u; valueLoop < signalLength; valueLoop++)
                {
                    ((uint8*)SignalDataPtr)[valueLoop] = Com_Signal8BitRuntimeBuff[signalInitValueId + valueLoop];
                }
                *Length = signalLength;
                /* Check IPdu which this group signal belonged is Active or not*/
                if (TRUE == Com_RxIPduRunTimeState[ipduRef].ActiveEnable)
                {
                    ret = E_OK;
                }
            }
        }
        else
        {
            ret = COM_BUSY;
        }
    }
    return ret;
}
#endif /* ((0u < COM_RXSIGNAL_NUMBER) && (0u < COM_SIGNAL_8BITBUFF_SIZE) && (STD_ON == \
          COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE)) */
/*Called by Com_ReceiveDynSignal.
 *Receive Dynamic Group Signal handle*/
#if ((0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXGROUPSIGNAL_8BITBUFF_SIZE)) \
    && (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE)
static FUNC(uint8, COM_CODE) Com_ReceiveDynGroupSignalHandle(
    Com_SignalIdType SignalId,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr,
    P2VAR(uint16, AUTOMATIC, COM_APPL_CONST) Length)
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
{
    PduIdType ipduRef;
    uint16 valueLoop;
    uint16 signalLength;
    uint16 signalInitValueId;
    uint8 ret = COM_SERVICE_NOT_AVAILABLE;
    Com_SignalGroupIdType signalGroupId;
    signalGroupId = Com_ConfigStd->ComRxGroupSignal[SignalId - COM_RXSIGNAL_NUMBER].ComSignalGroupRef;
    ipduRef = Com_ConfigStd->ComRxSignalGroup[signalGroupId].ComIpduRefIndex;

    /* Check IPdu which this group signal belonged is Active or not,the group signal type must be COM_UINT8_DYN*/
    if (COM_UINT8_DYN == Com_ConfigStd->ComRxGroupSignal[SignalId - COM_RXSIGNAL_NUMBER].ComSignalType)
    {
        /*IPDU is not receiving data*/
        if (FALSE == Com_RxIPduRunTimeState[ipduRef].Receiving)
        {
            signalLength =
                (Com_RxIPduRunTimeState[ipduRef].RxIpduLength
                 - Com_ConfigStd->ComRxIPdu[ipduRef].IPduNoDynSignalLength);
            if (signalLength > (*Length))
            {
#if (STD_ON == COM_DEV_ERROR_DETECT)
                (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_RECEIVEDYNSIGNAL_ID, COM_E_PARAM);
#endif
                ret = E_NOT_OK;
            }
            else
            {
                signalInitValueId =
                    Com_ConfigStd->ComRxGroupSignal[SignalId - COM_RXSIGNAL_NUMBER].ComSignalInitValueId;
                /* Copy Uint8DYN signal value one byte by one */
                for (valueLoop = 0u; valueLoop < signalLength; valueLoop++)
                {
                    ((uint8*)SignalDataPtr)[valueLoop] = Com_RxGroupSignal8BitShadowBuff[signalInitValueId + valueLoop];
                }
                *Length = signalLength;
                /* Check IPdu which this group signal belonged is Active or not*/
                if (TRUE == Com_RxIPduRunTimeState[ipduRef].ActiveEnable)
                {
                    ret = E_OK;
                }
            }
        }
        else
        {
            ret = COM_BUSY;
        }
    }
    return ret;
}
#endif /* ((0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXGROUPSIGNAL_8BITBUFF_SIZE) && (STD_ON == \
          COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE)) */
#endif /* (0u < COM_RXIPDU_NUMBER) */

/*Called by Com_ReceiveSignalGroup.
 *Receive all group signal of the SignalGroup*/
#if ((0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXIPDU_NUMBER))
/* PRQA S 3206 ++ */ /* MISRA Rule 2.7 */
static FUNC(void, COM_CODE) Com_ReceiveSignalGroupHandle(PduIdType RxPduId, Com_SignalGroupIdType SignalGroupId)
/* PRQA S 3206 -- */ /* MISRA Rule 2.7 */
{
    const Com_RxSignalGroupType* rxSignalGroupPtr = &Com_ConfigStd->ComRxSignalGroup[SignalGroupId];
    Com_SignalIdType groupSignalNumber = rxSignalGroupPtr->ComGroupSignalNumber;
    Com_SignalIdType cnt;
    Com_SignalIdType groupSignalId;
    Com_SignalType signalType;
    uint16 signalInitValueId;
#if ((0u < COM_RXGROUPSIGNAL_8BITBUFF_SIZE) && (0u < COM_SIGNAL_8BITBUFF_SIZE))
    uint16 signalLength;
    uint16 lengthCounter;
#endif
    const Com_RxGroupSignalType* rxGroupSignalPtr;

    for (cnt = 0u; cnt < groupSignalNumber; cnt++)
    {
        groupSignalId = rxSignalGroupPtr->ComRxGroupSignalId[cnt];
        rxGroupSignalPtr = &Com_ConfigStd->ComRxGroupSignal[groupSignalId];
        signalInitValueId = rxGroupSignalPtr->ComSignalInitValueId;
        signalType = rxGroupSignalPtr->ComSignalType;
        switch (signalType)
        {
#if ((0u < COM_RXGROUPSIGNAL_BOOLBUFF_SIZE) && (0u < COM_SIGNAL_BOOLBUFF_SIZE))
        case COM_BOOLEAN:
            Com_RxGroupSignalBoolShadowBuff[signalInitValueId] = Com_SignalBoolRuntimeBuff[signalInitValueId];
            break;
#endif
#if ((0u < COM_RXGROUPSIGNAL_8BITBUFF_SIZE) && (0u < COM_SIGNAL_8BITBUFF_SIZE))
        case COM_SINT8:
        case COM_UINT8:
            Com_RxGroupSignal8BitShadowBuff[signalInitValueId] = Com_Signal8BitRuntimeBuff[signalInitValueId];
            break;
#endif
#if ((0u < COM_RXGROUPSIGNAL_16BITBUFF_SIZE) && (0u < COM_SIGNAL_16BITBUFF_SIZE))
        case COM_SINT16:
        case COM_UINT16:
            Com_RxGroupSignal16BitShadowBuff[signalInitValueId] = Com_Signal16BitRuntimeBuff[signalInitValueId];
            break;
#endif
#if ((0u < COM_RXGROUPSIGNAL_32BITBUFF_SIZE) && (0u < COM_SIGNAL_32BITBUFF_SIZE))
        case COM_SINT32:
        case COM_UINT32:
        case COM_FLOAT32:
            Com_RxGroupSignal32BitShadowBuff[signalInitValueId] = Com_Signal32BitRuntimeBuff[signalInitValueId];
            break;
#endif
#if ((0u < COM_RXGROUPSIGNAL_64BITBUFF_SIZE) && (0u < COM_SIGNAL_64BITBUFF_SIZE))
        case COM_SINT64:
        case COM_UINT64:
        case COM_FLOAT64:
            Com_RxGroupSignal64BitShadowBuff[signalInitValueId] = Com_Signal64BitRuntimeBuff[signalInitValueId];
            break;
#endif
#if ((0u < COM_RXGROUPSIGNAL_8BITBUFF_SIZE) && (0u < COM_SIGNAL_8BITBUFF_SIZE))
#if (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_N_ENABLE)
        case COM_UINT8_N:
            signalLength = rxGroupSignalPtr->ComSignalLength;
            for (lengthCounter = 0u; lengthCounter < signalLength; lengthCounter++)
            {
                Com_RxGroupSignal8BitShadowBuff[signalInitValueId + lengthCounter] =
                    Com_Signal8BitRuntimeBuff[signalInitValueId + lengthCounter];
            }
            break;
#endif /* (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_N_ENABLE) */
#if (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE)
        case COM_UINT8_DYN:
            signalLength = Com_RxIPduRunTimeState[RxPduId].RxIpduLength
                           - (uint16)Com_ConfigStd->ComRxIPdu[RxPduId].IPduNoDynSignalLength;
            for (lengthCounter = 0u; lengthCounter < signalLength; lengthCounter++)
            {
                Com_RxGroupSignal8BitShadowBuff[signalInitValueId + lengthCounter] =
                    Com_Signal8BitRuntimeBuff[signalInitValueId + lengthCounter];
            }
            break;
#endif /* (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE) */
#endif
        default:
            /*do nothing*/
            break;
        }
    }
    return;
}
#endif

#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#pragma default_function_attributes =
/*******************************************************************************
**                            General Notes                                   **
*******************************************************************************/
