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
**  FILENAME    : Com_RxInternal.c                                            **
**                                                                            **
**  Created on  :                                                             **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : internal implementation for COM receive                     **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Com_Internal.h"
#if (0u < COM_RXIPDU_NUMBER)
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* called by Com_RxIpduController
 * reset OCCURRENCE of filter with ComFilterAlgorithm ONE_EVERY_N*/
#if ((COM_IPDUGROUP_NUMBER > 0u) && (COM_ONEEVERYNFILTERSIGNAL_NUMBER > 0u))
static FUNC(void, COM_CODE) Com_ResetRxOccurrenceOfPduFilter(PduIdType IpduId);
#endif
/* called by Com_RxIpduController
 * init the rx ipdu buffer,all signal buffer(included in the ipdu,except source signal)*/
#if (COM_IPDUGROUP_NUMBER > 0u)
static FUNC(void, COM_CODE) Com_ResetRxPduBufferAndSignalBuffer(PduIdType IpduId);
#endif
/* called by Com_IndicationProcess.
 * unpack the rx source description signal to gateway buffer*/
#if (0u < COM_GW_SOURCE_DESCRIPTION_NUMBER)
static FUNC(void, COM_CODE)
    Com_SourceSignalUnPack(Com_SignalIdType SourceSignalId, uint16 RxDynSignalLength, uint16 IpduBufferId);
#endif
/* called by Com_IndicationProcess.
 * unpack the rx signal and notification up layer*/
#if (0u < COM_RXSIGNAL_NUMBER)
static FUNC(void, COM_CODE)
    Com_SignalRxIndication(Com_SignalIdType RxSignalId, uint16 RxDynSignalLength, uint16 IpduBufferId);
#endif
/* called by Com_SignalRxIndication.
 * unpack the rx signal(signal type is COM_UINT8_N) and notification up layer*/
#if ((0u < COM_RXSIGNAL_NUMBER) && (0u < COM_RXIPDUBUFF_SIZE) && (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_N_ENABLE))
static FUNC(void, COM_CODE) Com_Rx8NSignalHandle(Com_SignalIdType SignalId, uint16 SignalLength, uint16 BufferId);
#endif /* ((0u < COM_RXSIGNAL_NUMBER) && (0u < COM_RXIPDUBUFF_SIZE) && (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_N_ENABLE)) \
        */
/* called by Com_SignalRxIndication.
 * unpack the rx signal(signal type is COM_UINT8_DYN) and notification up layer*/
#if ((0u < COM_RXSIGNAL_NUMBER) && (0u < COM_RXIPDUBUFF_SIZE) && (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE))
static FUNC(void, COM_CODE) Com_Rx8DYNSignalHandle(Com_SignalIdType SignalId, uint16 SignalLength, uint16 BufferId);
#endif /* ((0u < COM_RXSIGNAL_NUMBER) && (0u < COM_RXIPDUBUFF_SIZE) && (STD_ON == \
          COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE)) */
/* called by Com_SignalRxIndication.
 * unpack the rx signal(signal type isn't COM_UINT8_N or COM_UINT8_DYN) and notification up layer*/
#if ((0u < COM_RXSIGNAL_NUMBER) && (0u < COM_RXIPDUBUFF_SIZE))
static FUNC(void, COM_CODE) Com_RxSignalHandle(Com_SignalIdType SignalId);
#endif
/* called by Com_RxSignalHandle.
 * unpack the rx signal(signal type isn't COM_UINT8_N or COM_UINT8_DYN)*/
#if ((0u < COM_RXSIGNAL_NUMBER) && (0u < COM_RXIPDUBUFF_SIZE))
static FUNC(uint64, COM_CODE) Com_RxSignalUnPack(Com_SignalIdType SignalId);
#endif
/* called by Com_SourceSignalUnPack.
 * unpack the rx source description signal*/
#if ((0u < COM_GW_SOURCE_DESCRIPTION_NUMBER) && (0u < COM_RXIPDUBUFF_SIZE))
static FUNC(uint64, COM_CODE) Com_SourceSignalNotArrayUnPack(Com_SignalIdType SourceSignalId);
#endif
/* called by Com_RxSignalHandle,Com_SignalGroupRxIndication.
 * judge the rx (group) signal value is invalid value or not*/
#if ((0u < COM_RXGROUPSIGNAL_NUMBER) || (0u < COM_RXSIGNAL_NUMBER)) && (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ENABLE)
static FUNC(boolean, COM_CODE)
    Com_SignalInvalidateHandle(Com_SignalType SignalType, uint16 InvalidValueId, uint64 Value);
#endif /* ((0u < COM_RXGROUPSIGNAL_NUMBER) || (0u < COM_RXSIGNAL_NUMBER)) && (STD_ON == \
          COM_RX_SIGNAL_INVALID_DATA_ENABLE) */
/* called by Com_RxSignalHandle,Com_InvalidSignalReplaceAndNotification,Com_RxSignalGroupFilter.
 * get the rx (group) signal's init value*/
#if ((0u < COM_RXSIGNAL_NUMBER) || (0u < COM_RXGROUPSIGNAL_NUMBER)) \
    && ((STD_ON == COM_RX_SIGNAL_INVALID_DATA_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_INVALID_DATA_ENABLE))
static FUNC(uint64, COM_CODE) Com_RxSignalReplaceHanlde(Com_SignalType SignalType, uint16 InitValueId);
#endif /* ((0u < COM_RXSIGNAL_NUMBER) || (0u < COM_RXGROUPSIGNAL_NUMBER)) && ((STD_ON == \
          COM_RX_SIGNAL_INVALID_DATA_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_INVALID_DATA_ENABLE)) */
/* called by Com_RxSignalHandle,Com_InvalidSignalReplaceAndNotification.
 * calculate the rx signal value is filter out or not*/
#if ((0u < COM_RXSIGNAL_NUMBER) || (0u < COM_RXGROUPSIGNAL_NUMBER)) \
    && ((STD_ON == COM_RX_SIGNAL_FILTER_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_FILTER_ENABLE))
static FUNC(boolean, COM_CODE) Com_RxSignalFilter(
    uint64 Value,
    P2CONST(Com_FilterType, AUTOMATIC, COM_APPL_CONST) ComFilter,
#if (COM_RXSIGNALMASKNEWDIFFERMASKOLD_NUMBER > 0u)
    uint16 SignalBufferId,
#endif
    Com_SignalType SignalType);
#endif /* ((0u < COM_RXSIGNAL_NUMBER) || (0u < COM_RXGROUPSIGNAL_NUMBER)) && ((STD_ON == COM_RX_SIGNAL_FILTER_ENABLE) \
          || (STD_ON == COM_RX_GRP_SIGNAL_FILTER_ENABLE)) */
/* called by Com_RxSignalHandle,Com_InvalidSignalReplaceAndNotification.
 * update the rx signal value buffer*/
#if (0u < COM_RXSIGNAL_NUMBER)
static FUNC(void, COM_CODE) Com_RxSignalBuffHanlde(uint64 Value, Com_SignalIdType Id);
#endif
/* called by Com_RxSignalHandle,Com_SignalGroupRxIndication.
 * update the gateway signal value buffer of the rx signal*/
#if ((0u < COM_RXGROUPSIGNAL_NUMBER) || (0u < COM_RXSIGNAL_NUMBER)) && (STD_ON == COM_SIGNAL_GW_ENABLE)
static FUNC(void, COM_CODE) Com_UpdateGWSignalBuffer(uint64 Value, uint16 GWSignalBufferId, Com_SignalType SignalType);
#endif /* ((0u < COM_RXGROUPSIGNAL_NUMBER) || (0u < COM_RXSIGNAL_NUMBER)) && (STD_ON == COM_SIGNAL_GW_ENABLE) */
/* called by Com_IndicationProcess.
 * handle signal group RxIndication of one rx pdu*/
#if ((0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXGROUPSIGNAL_NUMBER))
static FUNC(void, COM_CODE)
    Com_SignalGroupRxIndication(Com_SignalGroupIdType RxSignalGroupId, uint16 RxDynSignalLength, uint16 IpduBufferId);
#endif
/* called by Com_SignalGroupRxIndication,Com_RxGroupSignalBuffHanlde.
 * unpack rx group signal(signal type isn't COM_UINT8_N or COM_UINT8_DYN)*/
#if ((0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXGROUPSIGNAL_NUMBER))
static FUNC(uint64, COM_CODE) Com_RxGroupSignalUnPack(Com_SignalIdType SignalId, uint16 IpduBufferId);
#endif
/* called by Com_SignalGroupRxIndication,Com_TpPduInvalidAction.
 * judge the rx signal group value is filter out or not*/
#if ((0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXGROUPSIGNAL_NUMBER) && (STD_ON == COM_RX_GRP_SIGNAL_FILTER_ENABLE))
static FUNC(boolean, COM_CODE)
    Com_RxSignalGroupFilter(Com_SignalGroupIdType SignalGroupId, boolean InvalidSignalGroup, uint16 IpduBufferId);
#endif /* ((0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXGROUPSIGNAL_NUMBER) && (STD_ON == \
          COM_RX_GRP_SIGNAL_FILTER_ENABLE)) */
/* called by Com_SignalGroupRxIndication,Com_TpPduInvalidAction.
 * update the rx group signal value buffer*/
#if ((0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXGROUPSIGNAL_NUMBER))
static FUNC(void, COM_CODE) Com_RxGroupSignalBuffHanlde(
    boolean InvalidSignalGroup,
    Com_SignalIdType Id,
    uint16 IpduBufferId,
    uint16 RxDynSignalLength);
#endif
/* called by Com_TpPduInvalidAction.
 * rx signal value replace,and notification*/
#if ((STD_ON == COM_RXTPPDU_SUPPORT) && (0u < COM_RXSIGNAL_NUMBER) && (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ENABLE))
static FUNC(void, COM_CODE) Com_InvalidSignalReplaceAndNotification(Com_SignalIdType RxSignalId);
#endif /* ((STD_ON == COM_RXTPPDU_SUPPORT) && (0u < COM_RXSIGNAL_NUMBER) && (STD_ON == \
          COM_RX_SIGNAL_INVALID_DATA_ENABLE)) */

#if ((0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXGROUPSIGNAL_NUMBER))
/*Called by Com_SignalGroupInvalidCalculate.
 *Uint8_Dyn Group Signal Invalid Calculate*/
#if (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE) && (STD_ON == COM_RX_GRP_SIGNAL_INVALID_DATA_ENABLE)
static FUNC(void, COM_CODE) Com_Uint8DynGroupSignalInvalidCalculate(
    uint16 RxDynSignalLength,
    Com_SignalIdType groupSignalId,
    uint16 IpduBufferId,
    boolean* signalGroupInvalid);
#endif /* (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE) && (STD_ON == COM_RX_GRP_SIGNAL_INVALID_DATA_ENABLE) */
/*Called by Com_SignalGroupRxIndication.
 *Signal Group Invalid Calculate*/
#if (STD_ON == COM_RX_GRP_SIGNAL_INVALID_DATA_ENABLE)
static FUNC(boolean, COM_CODE) Com_SignalGroupInvalidCalculate(
    Com_SignalGroupIdType RxSignalGroupId,
    Com_SignalIdType groupSignalNumber,
    uint16 IpduBufferId,
    uint16 RxDynSignalLength);
#endif /* (STD_ON == COM_RX_GRP_SIGNAL_INVALID_DATA_ENABLE) */
#endif /* ((0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXGROUPSIGNAL_NUMBER)) */

#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/******************************************************************************/
/*
 * Brief               Called by Com_IpduGroupControl.
 *                     used to handle Rx Ipdu state change or not
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      IpduId,PduInfo
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (COM_IPDUGROUP_NUMBER > 0u)
FUNC(void, COM_CODE)
Com_RxIpduController(PduIdType RxPduId, boolean initialize) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    const Com_RxIPduType* rxIpduPtr = &Com_ConfigStd->ComRxIPdu[RxPduId];
    Com_IpduGroupIdType ipduGroupRefNumber = rxIpduPtr->ComIPduGroupsRefNumber;
    Com_IpduGroupIdType index;
    Com_IpduGroupIdType ipduGroupId;
    boolean findActiveIpduGroup = FALSE;

    /*if the Pdu not included in any Ipdu Group,the state is always start*/
    if (ipduGroupRefNumber > 0u)
    {
        for (index = 0u; (index < ipduGroupRefNumber) && (FALSE == findActiveIpduGroup); index++)
        {
            ipduGroupId = rxIpduPtr->ComIPduGroupsRef[index];
            if (TRUE == Com_IpduGroupEnable[ipduGroupId])
            {
                findActiveIpduGroup = TRUE;
            }
        }
        /*at least one Ipdu Group is start,the Pdu shall be active*/
        if (TRUE == findActiveIpduGroup)
        {
            /*the pdu restart*/
            if (FALSE == Com_RxIPduRunTimeState[RxPduId].ActiveEnable)
            {
                Com_RxIPduRunTimeState[RxPduId].ActiveEnable = TRUE;
/*reset rx i-pdu(all signal/signal group) DM Counter*/
#if ((COM_RXSIGNAL_NUMBER + COM_RXSIGNALGROUP_NUMBER) > 0u)
                Com_ResetRxPduTimeOut(RxPduId);
#endif
/*reset OCCURRENCE of filter with ComFilterAlgorithm ONE_EVERY_N*/
#if (COM_ONEEVERYNFILTERSIGNAL_NUMBER > 0u)
                Com_ResetRxOccurrenceOfPduFilter(RxPduId);
#endif
                if (TRUE == initialize)
                {
                    /*init the rx ipdu buffer,all signal buffer(included in the ipdu,except source signal)*/
                    Com_ResetRxPduBufferAndSignalBuffer(RxPduId);
                    if (NULL_PTR != rxIpduPtr->ComIPduCounter)
                    {
                        /*accept for I-PDUs with ComIPduDirection configured to RECEIVED any next incoming I-PDU
                         * counter*/
                        Com_RxIPduRunTimeState[RxPduId].RxAnyCounterPdu = TRUE;
                        Com_RxIPduRunTimeState[RxPduId].RxReplicationNumber = 0u;
                    }
                }
            }
        }
        else
        {
            if (TRUE == Com_RxIPduRunTimeState[RxPduId].ActiveEnable)
            {
                Com_RxIPduRunTimeState[RxPduId].ActiveEnable = FALSE;
/*disable rx i-pdu(all signal/signal group) DM Counter*/
#if ((COM_RXSIGNAL_NUMBER + COM_RXSIGNALGROUP_NUMBER) > 0u)
                Com_DisableRxPduTimeOut(RxPduId);
#endif
            }
        }
    }
    return;
}
#endif /*COM_IPDUGROUP_NUMBER > 0u*/
/******************************************************************************/
/*
 * Brief               Called by Com_RxIpduController,Com_ReceptionDMControl.
 *                     set the reception deadline monitoring timer for the
 *                     included signals and signal groups to the configured
 *                     ComFirstTimeout
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      IpduId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if ((COM_IPDUGROUP_NUMBER > 0u) && ((COM_RXSIGNAL_NUMBER + COM_RXSIGNALGROUP_NUMBER) > 0u))
FUNC(void, COM_CODE)
Com_ResetRxPduTimeOut(PduIdType IpduId)
{
    Com_SignalIdType cnt;
    uint16 timeCntIndex;
#if (COM_RXSIGNAL_NUMBER > 0u)
    Com_SignalIdType ipduSignalRefNumber;
    Com_SignalIdType rxSignalId;
    const Com_RxSignalType* rxSignalPtr;
#endif
#if (COM_RXSIGNALGROUP_NUMBER > 0u)
    Com_SignalGroupIdType ipduSignalGroupNumber;
    Com_SignalGroupIdType rxSignalGroupId;
    const Com_RxSignalGroupType* rxSignalGroupPtr;
#endif
    const Com_RxIPduType* rxIpduPtr = &Com_ConfigStd->ComRxIPdu[IpduId];

#if (COM_RXSIGNAL_NUMBER > 0u)
    ipduSignalRefNumber = rxIpduPtr->ComIPduSignalsRefNumber;
    for (cnt = 0u; cnt < ipduSignalRefNumber; cnt++)
    {
        rxSignalId = rxIpduPtr->ComIPduSignalsRef[cnt];
        rxSignalPtr = &Com_ConfigStd->ComRxSignal[rxSignalId];
        timeCntIndex = rxSignalPtr->ComTimeCntIndex;
        Com_TimeOutCnt[timeCntIndex] = rxSignalPtr->ComFirstTimeout;
    }
#endif
#if (COM_RXSIGNALGROUP_NUMBER > 0u)
    ipduSignalGroupNumber = rxIpduPtr->ComIPduSignalGroupsRefNumber;
    for (cnt = 0u; cnt < ipduSignalGroupNumber; cnt++)
    {
        rxSignalGroupId = rxIpduPtr->ComIPduSignalGroupsRef[cnt];
        rxSignalGroupPtr = &Com_ConfigStd->ComRxSignalGroup[rxSignalGroupId];
        timeCntIndex = rxSignalGroupPtr->ComTimeoutCntIndex;
        Com_TimeOutCnt[timeCntIndex] = rxSignalGroupPtr->ComFirstTimeout;
    }
#endif
    return;
}
#endif
/******************************************************************************/
/*
 * Brief               Called by Com_RxIpduController,Com_ReceptionDMControl.
 *                     set the reception deadline monitoring timer for the
 *                     included signals and signal groups to 0
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      IpduId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if ((COM_IPDUGROUP_NUMBER > 0u) && ((COM_RXSIGNAL_NUMBER + COM_RXSIGNALGROUP_NUMBER) > 0u))
FUNC(void, COM_CODE)
Com_DisableRxPduTimeOut(PduIdType IpduId)
{
    Com_SignalIdType cnt;
    uint16 timeCntIndex;
#if (COM_RXSIGNAL_NUMBER > 0u)
    Com_SignalIdType ipduSignalRefNumber;
    Com_SignalIdType rxSignalId;
#endif
#if (COM_RXSIGNALGROUP_NUMBER > 0u)
    Com_SignalGroupIdType ipduSignalGroupNumber;
    Com_SignalGroupIdType rxSignalGroupId;
#endif
    const Com_RxIPduType* rxIpduPtr = &Com_ConfigStd->ComRxIPdu[IpduId];
#if (COM_RXSIGNAL_NUMBER > 0u)
    ipduSignalRefNumber = rxIpduPtr->ComIPduSignalsRefNumber;
    for (cnt = 0u; cnt < ipduSignalRefNumber; cnt++)
    {
        rxSignalId = rxIpduPtr->ComIPduSignalsRef[cnt];
        timeCntIndex = Com_ConfigStd->ComRxSignal[rxSignalId].ComTimeCntIndex;
        Com_TimeOutCnt[timeCntIndex] = 0u;
    }
#endif
#if (COM_RXSIGNALGROUP_NUMBER > 0u)
    ipduSignalGroupNumber = rxIpduPtr->ComIPduSignalGroupsRefNumber;
    for (cnt = 0u; cnt < ipduSignalGroupNumber; cnt++)
    {
        rxSignalGroupId = rxIpduPtr->ComIPduSignalGroupsRef[cnt];
        timeCntIndex = Com_ConfigStd->ComRxSignalGroup[rxSignalGroupId].ComTimeoutCntIndex;
        Com_TimeOutCnt[timeCntIndex] = 0u;
    }
#endif
    return;
}
#endif
/******************************************************************************/
/*
 * Brief               Called by Com_RxIndication,Com_TpRxIndication.
 *                     reset receive DM timer for all signals/signal groups
 *                     (which is update) of one rx pdu
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      IpduId,PduInfo
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (COM_RXSIGNAL_NUMBER + COM_RXSIGNALGROUP_NUMBER > 0u) \
    && ((STD_ON == COM_RX_SIGNAL_TIMEOUT_ENABLE) || (STD_ON == COM_RX_SIG_GROUP_TIMEOUT_ENABLE))
FUNC(void, COM_CODE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
Com_ResetUpdateDMTime(PduIdType IpduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfo)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
    Com_SignalIdType cnt;
    uint16 timeCntIndex;
    uint32 updateBitPosition;
    uint8 updateBitOffset;
#if (COM_RXSIGNAL_NUMBER > 0u) && (STD_ON == COM_RX_SIGNAL_TIMEOUT_ENABLE)
    Com_SignalIdType ipduSignalRefNumber;
    Com_SignalIdType rxSignalId;
    const Com_RxSignalType* rxSignalPtr;
#endif
#if (COM_RXSIGNALGROUP_NUMBER > 0u) && (STD_ON == COM_RX_SIG_GROUP_TIMEOUT_ENABLE)
    Com_SignalGroupIdType ipduSignalGroupNumber;
    Com_SignalGroupIdType rxSignalGroupId;
    const Com_RxSignalGroupType* rxSignalGroupPtr;
#endif
    const Com_RxIPduType* rxIpduPtr = &Com_ConfigStd->ComRxIPdu[IpduId];

#if (COM_RXSIGNAL_NUMBER > 0u) && (STD_ON == COM_RX_SIGNAL_TIMEOUT_ENABLE)
    ipduSignalRefNumber = rxIpduPtr->ComIPduSignalsRefNumber;
    for (cnt = 0u; cnt < ipduSignalRefNumber; cnt++)
    {
        rxSignalId = rxIpduPtr->ComIPduSignalsRef[cnt];
        rxSignalPtr = &Com_ConfigStd->ComRxSignal[rxSignalId];
        timeCntIndex = rxSignalPtr->ComTimeCntIndex;
#if (STD_ON == COM_RX_SIGNAL_UPDATE_BIT_ENABLE)
        updateBitPosition = rxSignalPtr->ComUpdateBitPosition;
        /*the rx signal not have update bit*/
        if (COM_UNUSED_UINT32 == updateBitPosition)
#endif /* #if (STD_ON == COM_RX_SIGNAL_UPDATE_BIT_ENABLE) */
        {
            Com_TimeOutCnt[timeCntIndex] = rxSignalPtr->ComTimeout;
        }
/*the rx signal have update bit*/
#if (STD_ON == COM_RX_SIGNAL_UPDATE_BIT_ENABLE)
        else
        {
            updateBitOffset = rxSignalPtr->ComUpdateBitMask;
            /*update bit is 1*/
            if (updateBitOffset == ((PduInfo->SduDataPtr[updateBitPosition >> 3u]) & updateBitOffset))
            {
                Com_TimeOutCnt[timeCntIndex] = rxSignalPtr->ComTimeout;
            }
        }
#endif /* #if (STD_ON == COM_RX_SIGNAL_UPDATE_BIT_ENABLE) */
    }
#endif /* #if (COM_RXSIGNAL_NUMBER > 0u) && (STD_ON == COM_RX_SIGNAL_TIMEOUT_ENABLE) */
#if (COM_RXSIGNALGROUP_NUMBER > 0u) && (STD_ON == COM_RX_SIG_GROUP_TIMEOUT_ENABLE)
    ipduSignalGroupNumber = rxIpduPtr->ComIPduSignalGroupsRefNumber;
    for (cnt = 0u; cnt < ipduSignalGroupNumber; cnt++)
    {
        rxSignalGroupId = rxIpduPtr->ComIPduSignalGroupsRef[cnt];
        rxSignalGroupPtr = &Com_ConfigStd->ComRxSignalGroup[rxSignalGroupId];
        timeCntIndex = rxSignalGroupPtr->ComTimeoutCntIndex;
#if (STD_ON == COM_RX_SIG_GROUP_UPDATE_BIT_ENABLE)
        updateBitPosition = rxSignalGroupPtr->ComUpdateBitPosition;
        /*the rx signal group not have update bit*/
        if (COM_UNUSED_UINT32 == updateBitPosition)
#endif /* #if (STD_ON == COM_RX_SIG_GROUP_UPDATE_BIT_ENABLE) */
        {
            Com_TimeOutCnt[timeCntIndex] = rxSignalGroupPtr->ComTimeout;
        }
/*the rx signal group have update bit*/
#if (STD_ON == COM_RX_SIG_GROUP_UPDATE_BIT_ENABLE)
        else
        {
            updateBitOffset = rxSignalGroupPtr->ComUpdateBitMask;
            /*update bit is 1*/
            if (updateBitOffset == ((PduInfo->SduDataPtr[updateBitPosition >> 3u]) & updateBitOffset))
            {
                Com_TimeOutCnt[timeCntIndex] = rxSignalGroupPtr->ComTimeout;
            }
        }
#endif /* #if (STD_ON == COM_RX_SIG_GROUP_UPDATE_BIT_ENABLE) */
    }
#endif /* #if (COM_RXSIGNALGROUP_NUMBER > 0u) && (STD_ON == COM_RX_SIG_GROUP_TIMEOUT_ENABLE) */
    return;
}
#endif /*#if (COM_RXSIGNAL_NUMBER + COM_RXSIGNALGROUP_NUMBER > 0u) && ((STD_ON == COM_RX_SIGNAL_TIMEOUT_ENABLE) || \
          (STD_ON == COM_RX_SIG_GROUP_TIMEOUT_ENABLE))*/
/******************************************************************************/
/*
 * Brief               Called by Com_RxIndication,Com_TpRxIndication,Com_MainFunctionRx.
 *                     unpack the rx pdu data and invoke notification
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      RxIpduId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, COM_CODE)
Com_IndicationProcess(PduIdType RxIpduId) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    const Com_RxIPduType* rxIpduPtr = &Com_ConfigStd->ComRxIPdu[RxIpduId];
#if (0u < COM_RXSIGNAL_NUMBER)
    Com_SignalIdType signalNumber;
    Com_SignalIdType rxSignalId;
#endif
#if (0u < COM_RXSIGNALGROUP_NUMBER)
    Com_SignalGroupIdType signalGroupNumber;
    Com_SignalGroupIdType rxSignalGroupId;
#if (STD_ON == COM_RX_SIG_GROUP_UPDATE_BIT_ENABLE)
    boolean updateSignalGroup = FALSE;
#endif /* #if (STD_ON == COM_RX_SIG_GROUP_UPDATE_BIT_ENABLE) */
#endif
#if (0u < COM_GW_SOURCE_DESCRIPTION_NUMBER)
    Com_SignalIdType gwSourceSignalNumber;
    Com_SignalIdType sourceSignalId;
#endif
    uint16 cnt;
    uint16 rxDynSignalLength = Com_RxIPduRunTimeState[RxIpduId].RxIpduLength - (uint16)rxIpduPtr->IPduNoDynSignalLength;
    uint16 ipduBufferId = rxIpduPtr->ComRxIPduBufIndex;
#if ((0u < COM_RXSIGNAL_NUMBER) || (0u < COM_GW_SOURCE_DESCRIPTION_NUMBER)) \
    && ((STD_ON == COM_RX_SIGNAL_UPDATE_BIT_ENABLE) || (STD_ON == COM_GW_SRC_SIG_UPDATE_BIT_ENABLE))
    boolean updateSignal = FALSE;
#endif /* #if ((0u < COM_RXSIGNAL_NUMBER) || (0u < COM_GW_SOURCE_DESCRIPTION_NUMBER)) && ((STD_ON == \
          COM_RX_SIGNAL_UPDATE_BIT_ENABLE) || (STD_ON == COM_GW_SRC_SIG_UPDATE_BIT_ENABLE)) */
    uint32 updateBitPosition;
    uint8 updateBitOffset;
#if (COM_GWSOURCESIGNAL_UPDATE_NUMBER > 0u)
    uint16 gwUpdataStateId;
#endif
#if (STD_ON == COM_RX_SIGNAL_UPDATE_BIT_ENABLE)
    const Com_RxSignalType* rxSignalPtr;
#endif /* #if (STD_ON == COM_RX_SIGNAL_UPDATE_BIT_ENABLE) */
#if (STD_ON == COM_RX_SIG_GROUP_UPDATE_BIT_ENABLE)
    const Com_RxSignalGroupType* rxSignalGroupPtr;
#endif /* #if (STD_ON == COM_RX_SIG_GROUP_UPDATE_BIT_ENABLE) */
#if (STD_ON == COM_GW_SRC_SIG_UPDATE_BIT_ENABLE)
    const Com_GwSourceSignalType* gwSourceSignalPtr;
#endif /* #if (STD_ON == COM_GW_SRC_SIG_UPDATE_BIT_ENABLE) */

    /*store the rx dynamic signal length which really receive,not replace by any reason for gateway*/
    Com_RxIPduRunTimeState[RxIpduId].GWDynamicSignalLength = rxDynSignalLength;

#if (0u < COM_RXSIGNAL_NUMBER)
    signalNumber = rxIpduPtr->ComIPduSignalsRefNumber;
    for (cnt = 0u; cnt < signalNumber; cnt++)
    {
        rxSignalId = rxIpduPtr->ComIPduSignalsRef[cnt];
#if (STD_ON == COM_RX_SIGNAL_UPDATE_BIT_ENABLE)
        rxSignalPtr = &Com_ConfigStd->ComRxSignal[rxSignalId];
        updateBitPosition = rxSignalPtr->ComUpdateBitPosition;

        /*the rx signal not have update bit*/
        if (COM_UNUSED_UINT32 == updateBitPosition)
        {
            updateSignal = TRUE;
        }
        /*the rx signal have update bit*/
        else
        {
            updateBitOffset = rxSignalPtr->ComUpdateBitMask;
            /*update bit is 1*/
            if (updateBitOffset
                == ((Com_RxIPduRuntimeBuff[ipduBufferId + (uint16)(updateBitPosition >> 3u)]) & updateBitOffset))
            {
#if (COM_GWSOURCESIGNAL_UPDATE_NUMBER > 0u)
                gwUpdataStateId = rxSignalPtr->GWUpdataStateId;
                /*the signal need gateway and have update bit*/
                if (COM_UNUSED_UINT16 != gwUpdataStateId)
                {
                    Com_GWSourceSignalUpdate[gwUpdataStateId] = TRUE;
                }
#endif
                updateSignal = TRUE;
            }
        }

        if (TRUE == updateSignal)
#endif /* #if (STD_ON == COM_RX_SIGNAL_UPDATE_BIT_ENABLE) */
        {
            Com_SignalRxIndication(rxSignalId, rxDynSignalLength, ipduBufferId);
#if (STD_ON == COM_RX_SIGNAL_UPDATE_BIT_ENABLE)
            updateSignal = FALSE;
#endif /* #if (STD_ON == COM_RX_SIGNAL_UPDATE_BIT_ENABLE) */
        }
    }
#endif /*0u < COM_RXSIGNAL_NUMBER*/
#if ((0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXGROUPSIGNAL_NUMBER))
    signalGroupNumber = rxIpduPtr->ComIPduSignalGroupsRefNumber;
    for (cnt = 0u; cnt < signalGroupNumber; cnt++)
    {
        rxSignalGroupId = rxIpduPtr->ComIPduSignalGroupsRef[cnt];
#if (STD_ON == COM_RX_SIG_GROUP_UPDATE_BIT_ENABLE)
        rxSignalGroupPtr = &Com_ConfigStd->ComRxSignalGroup[rxSignalGroupId];
        updateBitPosition = rxSignalGroupPtr->ComUpdateBitPosition;

        /*the rx group signal not have update bit*/
        if (COM_UNUSED_UINT32 == updateBitPosition)
        {
            updateSignalGroup = TRUE;
        }
        /*the rx group signal have update bit*/
        else
        {
            updateBitOffset = rxSignalGroupPtr->ComUpdateBitMask;
            /*update bit is 1*/
            if (updateBitOffset
                == ((Com_RxIPduRuntimeBuff[ipduBufferId + (uint16)(updateBitPosition >> 3u)]) & updateBitOffset))
            {
#if (COM_GWSOURCESIGNAL_UPDATE_NUMBER > 0u)
                gwUpdataStateId = rxSignalGroupPtr->GWUpdataStateId;
                /*the signal group (or group signal included in the signal group) need gateway and have update bit*/
                if (COM_UNUSED_UINT16 != gwUpdataStateId)
                {
                    Com_GWSourceSignalUpdate[gwUpdataStateId] = TRUE;
                }
#endif
                updateSignalGroup = TRUE;
            }
        }

        if (TRUE == updateSignalGroup)
#endif /* #if (STD_ON == COM_RX_SIG_GROUP_UPDATE_BIT_ENABLE) */
        {
            Com_SignalGroupRxIndication(rxSignalGroupId, rxDynSignalLength, ipduBufferId);
#if (STD_ON == COM_RX_SIG_GROUP_UPDATE_BIT_ENABLE)
            updateSignalGroup = FALSE;
#endif /* #if (STD_ON == COM_RX_SIG_GROUP_UPDATE_BIT_ENABLE) */
        }
    }
#endif
#if (0u < COM_GW_SOURCE_DESCRIPTION_NUMBER)
    gwSourceSignalNumber = rxIpduPtr->ComIPduSourceSignalsRefNumber;
    for (cnt = 0u; cnt < gwSourceSignalNumber; cnt++)
    {
        sourceSignalId = rxIpduPtr->ComIPduSourceSignalsRef[cnt];
#if (STD_ON == COM_GW_SRC_SIG_UPDATE_BIT_ENABLE)
        gwSourceSignalPtr = &Com_ConfigStd->ComSourceSignal[sourceSignalId];
        updateBitPosition = gwSourceSignalPtr->ComUpdateBitPosition;

        /*the rx signal not have update bit*/
        if (COM_UNUSED_UINT32 == updateBitPosition)
        {
            updateSignal = TRUE;
        }
        /*the source signal have update bit*/
        else
        {
            updateBitOffset = gwSourceSignalPtr->ComUpdateBitMask;
            /*update bit is 1*/
            if (updateBitOffset
                == ((Com_RxIPduRuntimeBuff[ipduBufferId + (uint16)(updateBitPosition >> 3u)]) & updateBitOffset))
            {
#if (COM_GWSOURCESIGNAL_UPDATE_NUMBER > 0)
                gwUpdataStateId = gwSourceSignalPtr->GWUpdataStateId;
                Com_GWSourceSignalUpdate[gwUpdataStateId] = TRUE;
#endif
                updateSignal = TRUE;
            }
        }

        if (TRUE == updateSignal)
#endif /* #if (STD_ON == COM_GW_SRC_SIG_UPDATE_BIT_ENABLE) */
        {
            /*unpack the rx source description signal to gateway buffer*/
            Com_SourceSignalUnPack(sourceSignalId, rxDynSignalLength, ipduBufferId);
#if (STD_ON == COM_GW_SRC_SIG_UPDATE_BIT_ENABLE)
            updateSignal = FALSE;
#endif /* #if (STD_ON == COM_GW_SRC_SIG_UPDATE_BIT_ENABLE) */
        }
    }
#endif
    return;
}
/******************************************************************************/
/*
 * Brief               Called by Com_TpRxIndication.
 *                     execute all configured ComDataInvalidActions for all
 *                     included signals and signal groups
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      RxIpduId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (STD_ON == COM_RXTPPDU_SUPPORT) \
    && ((STD_ON == COM_RX_SIGNAL_INVALID_DATA_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_INVALID_DATA_ENABLE))
FUNC(void, COM_CODE)
Com_TpPduInvalidAction(PduIdType RxIpduId) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
#if (0u < COM_RXSIGNAL_NUMBER) && (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ENABLE)
    Com_SignalIdType signalNumber;
    Com_SignalIdType rxSignalId;
    uint16 invalidValueId;
    const Com_RxSignalType* rxSignalPtr;
#endif /* #if (0u < COM_RXSIGNAL_NUMBER) && (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ENABLE) */
#if (                                                                  \
    (0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXGROUPSIGNAL_NUMBER) \
    && (STD_ON == COM_RX_GRP_SIGNAL_INVALID_DATA_ENABLE))
    Com_SignalGroupIdType signalGroupNumber;
    Com_SignalIdType counter;
    uint16 rxDynSignalLength;
    uint16 ipduBufferId;
    Com_SignalGroupIdType rxSignalGroupId;
    Com_SignalIdType groupSignalNumber;
    Com_SignalIdType groupSignalId;
    Com_RxSignalGroupType* rxSignalGroupPtr;
#endif /* #if ((0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXGROUPSIGNAL_NUMBER) && (STD_ON == \
          COM_RX_GRP_SIGNAL_INVALID_DATA_ENABLE)) */
    Com_SignalIdType cnt;
    const Com_RxIPduType* rxIpduPtr = &Com_ConfigStd->ComRxIPdu[RxIpduId];

#if (0u < COM_RXSIGNAL_NUMBER) && (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ENABLE)
    signalNumber = rxIpduPtr->ComIPduSignalsRefNumber;
    for (cnt = 0u; cnt < signalNumber; cnt++)
    {
        rxSignalId = rxIpduPtr->ComIPduSignalsRef[cnt];
        rxSignalPtr = &Com_ConfigStd->ComRxSignal[rxSignalId];
        invalidValueId = rxSignalPtr->ComSignalDataInvalidValueId;
        if (COM_UNUSED_UINT16 != invalidValueId)
        {
#if (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ACTION_NOTIFY_ENABLE)
            if (COM_INVALID_ACTION_NOTIFY == rxSignalPtr->ComDataInvalidAction)
            {
                if (NULL_PTR != rxSignalPtr->ComInvalidNotification)
                {
                    rxSignalPtr->ComInvalidNotification();
                }
            }
            else
#endif /* #if (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ACTION_NOTIFY_ENABLE) */
            {
                Com_InvalidSignalReplaceAndNotification(rxSignalId);
            }
        }
    }
#endif /* #if (0u < COM_RXSIGNAL_NUMBER) && (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ENABLE) */
#if (                                                                  \
    (0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXGROUPSIGNAL_NUMBER) \
    && (STD_ON == COM_RX_GRP_SIGNAL_INVALID_DATA_ENABLE))
    signalGroupNumber = rxIpduPtr->ComIPduSignalGroupsRefNumber;
    for (cnt = 0u; cnt < signalGroupNumber; cnt++)
    {
        rxSignalGroupId = rxIpduPtr->ComIPduSignalGroupsRef[cnt];
        rxSignalGroupPtr = &Com_ConfigStd->ComRxSignalGroup[rxSignalGroupId];
#if (STD_ON == COM_RX_SIG_GROUP_INVALID_DATA_ACTION_NOTIFY_ENABLE)
        if (COM_INVALID_ACTION_NOTIFY == rxSignalGroupPtr->ComDataInvalidAction)
        {
            if (NULL_PTR != rxSignalGroupPtr->ComInvalidNotification)
            {
                rxSignalGroupPtr->ComInvalidNotification();
            }
        }
        else
#endif /* #if (STD_ON == COM_RX_SIG_GROUP_INVALID_DATA_ACTION_NOTIFY_ENABLE) */
        {
            ipduBufferId = rxIpduPtr->ComRxIPduBufIndex;
#if (STD_ON == COM_RX_GRP_SIGNAL_FILTER_ENABLE)
            if (TRUE == Com_RxSignalGroupFilter(rxSignalGroupId, TRUE, ipduBufferId))
#endif /* #if (STD_ON == COM_RX_GRP_SIGNAL_FILTER_ENABLE) */
            {
                rxDynSignalLength =
                    Com_RxIPduRunTimeState[RxIpduId].RxIpduLength - (uint16)rxIpduPtr->IPduNoDynSignalLength;
                groupSignalNumber = rxSignalGroupPtr->ComGroupSignalNumber;
                /* update all group signal init value into group signal runtime buffer */
                for (counter = 0u; counter < groupSignalNumber; counter++)
                {
                    groupSignalId = rxSignalGroupPtr->ComRxGroupSignalId[counter];
                    Com_RxGroupSignalBuffHanlde(TRUE, groupSignalId, ipduBufferId, rxDynSignalLength);
                }
#if (STD_ON == COM_RX_SIG_GROUP_NOTIFICATION_ENABLE)
                if (NULL_PTR != rxSignalGroupPtr->ComNotification)
                {
                    rxSignalGroupPtr->ComNotification();
                }
#endif /* #if (STD_ON == COM_RX_SIG_GROUP_NOTIFICATION_ENABLE) */
            }
        }
    }
#endif /* #if ((0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXGROUPSIGNAL_NUMBER) && (STD_ON == \
          COM_RX_GRP_SIGNAL_INVALID_DATA_ENABLE)) */
    return;
}
#endif /* #if (STD_ON == COM_RXTPPDU_SUPPORT) && ((STD_ON == COM_RX_SIGNAL_INVALID_DATA_ENABLE) || (STD_ON == \
          COM_RX_GRP_SIGNAL_INVALID_DATA_ENABLE)) */
/******************************************************************************/
/*
 * Brief               Called by Com_TpRxIndication.
 *                     unpack the receive pdu's counter
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      IpduId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (STD_ON == COM_RXTPPDU_SUPPORT) && (STD_ON == COM_RX_IPDU_COUNTER_ENABLE)
FUNC(uint8, COM_CODE)
Com_UnPackCounterValue(PduIdType IpduId) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    uint8 counterValue;
    uint16 rxPduBufferId;
    uint32 bitPosition;
    uint8 bitSize;
    const Com_RxIPduType* rxIpduPtr = &Com_ConfigStd->ComRxIPdu[IpduId];
    rxPduBufferId = rxIpduPtr->ComRxIPduBufIndex;
    bitPosition = rxIpduPtr->ComIPduCounter->ComIPduCounterStartPosition;
    bitSize = rxIpduPtr->ComIPduCounter->ComIPduCounterSize;
    counterValue = Com_RxIPduRuntimeBuff[rxPduBufferId + (uint16)(bitPosition >> 3u)];
    counterValue = counterValue << (8u - (((uint8)bitPosition & 0x07u) + bitSize));
    counterValue = counterValue >> (8u - bitSize);
    return counterValue;
}
#endif /* #if (STD_ON == COM_RXTPPDU_SUPPORT) && (STD_ON == COM_RX_IPDU_COUNTER_ENABLE) */
/******************************************************************************/
/*
 * Brief               Called by Com_TpRxIndication,Com_RxIndication.
 *                     judge the receive pdu's counter is valid or not
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      IpduId,RxCounter
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (STD_ON == COM_RX_IPDU_COUNTER_ENABLE)
FUNC(boolean, COM_CODE)
Com_RxPduCounterValid(PduIdType IpduId, uint8 RxCounter) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    boolean receiveCounterIsValid = FALSE;
    uint8 counterThreshold;
    uint8 maxCounter;
    uint8 expectedCounter;
    const Com_RxIPduType* rxIpduPtr = &Com_ConfigStd->ComRxIPdu[IpduId];

    /*accept any incoming I-PDU, regardless of the value of the I-PDU counter*/
    if (TRUE == Com_RxIPduRunTimeState[IpduId].RxAnyCounterPdu)
    {
        receiveCounterIsValid = TRUE;
        /*update the expected counter*/
        Com_RxIPduRunTimeState[IpduId].RxIpduCounter = RxCounter;
        Com_PduCounterIncrease(FALSE, IpduId);
        Com_RxIPduRunTimeState[IpduId].RxAnyCounterPdu = FALSE;
    }
    else
    {
        maxCounter = rxIpduPtr->ComIPduCounter->ComIPduMaxCounter;
        counterThreshold = rxIpduPtr->ComIPduCounter->ComIPduCounterThreshold;
        expectedCounter = Com_RxIPduRunTimeState[IpduId].RxIpduCounter;
        /*respect to counter wrap-around*/
        if ((maxCounter - expectedCounter) < counterThreshold)
        {
            if ((RxCounter >= expectedCounter) || (RxCounter < (counterThreshold - (maxCounter - expectedCounter))))
            {
                receiveCounterIsValid = TRUE;
            }
        }
        /*respect to counter not wrap-around*/
        else
        {
            if ((RxCounter >= expectedCounter) && (RxCounter <= (expectedCounter + counterThreshold)))
            {
                receiveCounterIsValid = TRUE;
            }
        }
        /*update the expected counter*/
        Com_RxIPduRunTimeState[IpduId].RxIpduCounter = RxCounter;
        Com_PduCounterIncrease(FALSE, IpduId);
        if (FALSE == receiveCounterIsValid)
        {
            if (NULL_PTR != rxIpduPtr->ComIPduCounter->ComIPduCounterErrorNotification)
            {
                rxIpduPtr->ComIPduCounter->ComIPduCounterErrorNotification(IpduId, expectedCounter, RxCounter);
            }
        }
    }
    return receiveCounterIsValid;
}
#endif /* #if (STD_ON == COM_RX_IPDU_COUNTER_ENABLE) */
/******************************************************************************/
/*
 * Brief               Called by Com_RxIndication,Com_RxPduReplicationValid.
 *                     copy the Rx Pdu data to RxPdu Buffer
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      RxPduId,PduInfoPtr
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, COM_CODE)
Com_CopyPduDataToRxBuffer(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint16 pduBufferPos;
    PduLengthType cnt;
    const Com_RxIPduType* rxIpduPtr = &Com_ConfigStd->ComRxIPdu[RxPduId];
#if (STD_ON == COM_METADATA_SUPPORT)
    uint16 metaDataStartPos;
    uint8 metadataLength;
#endif
    pduBufferPos = rxIpduPtr->ComRxIPduBufIndex;
#if (0u < COM_RXIPDUBUFF_SIZE)
    /*copy receive pdu data to rx pdu buffer*/
    for (cnt = 0u; cnt < PduInfoPtr->SduLength; cnt++)
    {
        Com_RxIPduRuntimeBuff[pduBufferPos + cnt] = PduInfoPtr->SduDataPtr[cnt];
    }
#if (STD_ON == COM_METADATA_SUPPORT)
    if ((0u < rxIpduPtr->MetaDataLength) && (NULL_PTR != PduInfoPtr->MetaDataPtr))
    {
        metadataLength = rxIpduPtr->MetaDataLength;
        metaDataStartPos =
            (uint16)rxIpduPtr->IPduNoDynSignalLength + (uint16)rxIpduPtr->IPduMaxDynSignalLength + pduBufferPos;
        /*copy meta data to rx pdu buffer*/
        for (cnt = 0u; cnt < metadataLength; cnt++)
        {
            Com_RxIPduRuntimeBuff[metaDataStartPos + cnt] = PduInfoPtr->MetaDataPtr[cnt];
        }
    }
#endif /* #if (STD_ON == COM_METADATA_SUPPORT) */
#endif /* #if (0u < COM_RXIPDUBUFF_SIZE) */

    /*update the pdu length*/
    Com_RxIPduRunTimeState[RxPduId].RxIpduLength = (uint16)PduInfoPtr->SduLength;
    return;
}
/******************************************************************************/
/*
 * Brief               Called by Com_RxIndication.
 *                     judge the receive pdu's Replication is valid or not
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      IpduId,RxCounter,PduInfoPtr
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (STD_ON == COM_IPDU_REPLICATION_ENABLE)
FUNC(boolean, COM_CODE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
Com_RxPduReplicationValid(PduIdType IpduId, uint8 RxCounter, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
    const Com_RxIPduType* rxIpduPtr = &Com_ConfigStd->ComRxIPdu[IpduId];
    boolean rxPduValid = FALSE;
    uint8 iPduReplicationQuorum = rxIpduPtr->ComIPduReplication->ComIPduReplicationQuorum;
    PduLengthType cnt;
    uint8 updateCounter;
    boolean dataEqual = TRUE;

    /*accept any incoming I-PDU, regardless of the value of the I-PDU counter*/
    if (TRUE == Com_RxIPduRunTimeState[IpduId].RxAnyCounterPdu)
    {
        Com_RxIPduRunTimeState[IpduId].RxIpduCounter = RxCounter;
        /*copy receive pdu data to rx pdu buffer*/
        Com_CopyPduDataToRxBuffer(IpduId, PduInfoPtr);
        Com_RxIPduRunTimeState[IpduId].RxReplicationNumber = 1u;
        if (1u == iPduReplicationQuorum)
        {
#if (STD_ON == COM_RX_IPDU_COUNTER_ENABLE)
            /*update the expected counter*/
            Com_PduCounterIncrease(FALSE, IpduId);
#endif /* (STD_ON == COM_RX_IPDU_COUNTER_ENABLE) */
            Com_RxIPduRunTimeState[IpduId].RxReplicationNumber = 0u;
            rxPduValid = TRUE;
        }
        Com_RxIPduRunTimeState[IpduId].RxAnyCounterPdu = FALSE;
    }
    else
    {
        /*the rx pdu counter is expect counter*/
        if (RxCounter == Com_RxIPduRunTimeState[IpduId].RxIpduCounter)
        {
            if (0u == Com_RxIPduRunTimeState[IpduId].RxReplicationNumber)
            {
                /*copy receive pdu data to rx pdu buffer*/
                Com_CopyPduDataToRxBuffer(IpduId, PduInfoPtr);
                Com_RxIPduRunTimeState[IpduId].RxReplicationNumber = 1u;
                if (1u == iPduReplicationQuorum)
                {
#if (STD_ON == COM_RX_IPDU_COUNTER_ENABLE)
                    /*update the expected counter*/
                    Com_PduCounterIncrease(FALSE, IpduId);
#endif /* (STD_ON == COM_RX_IPDU_COUNTER_ENABLE) */
                    Com_RxIPduRunTimeState[IpduId].RxReplicationNumber = 0u;
                    rxPduValid = TRUE;
                }
            }
            else
            {
                if (Com_RxIPduRunTimeState[IpduId].RxIpduLength == PduInfoPtr->SduLength)
                {
                    for (cnt = 0u; (cnt < PduInfoPtr->SduLength) && (TRUE == dataEqual); cnt++)
                    {
                        if (Com_RxIPduRuntimeBuff[rxIpduPtr->ComRxIPduBufIndex + cnt] != PduInfoPtr->SduDataPtr[cnt])
                        {
                            dataEqual = FALSE;
                        }
                    }
                }
                else
                {
                    dataEqual = FALSE;
                }
                if (TRUE == dataEqual)
                {
                    (Com_RxIPduRunTimeState[IpduId].RxReplicationNumber) += 1u;
                    if (iPduReplicationQuorum == Com_RxIPduRunTimeState[IpduId].RxReplicationNumber)
                    {
#if (STD_ON == COM_RX_IPDU_COUNTER_ENABLE)
                        /*update the expected counter*/
                        Com_PduCounterIncrease(FALSE, IpduId);
#endif /* (STD_ON == COM_RX_IPDU_COUNTER_ENABLE) */
                        Com_RxIPduRunTimeState[IpduId].RxReplicationNumber = 0u;
                        rxPduValid = TRUE;
                    }
                }
            }
        }
        /*rx counter isn't expect counter*/
        else
        {
            if (RxCounter == rxIpduPtr->ComIPduCounter->ComIPduMaxCounter)
            {
                updateCounter = 0u;
            }
            else
            {
                updateCounter = RxCounter + 1u;
            }
            if (updateCounter != Com_RxIPduRunTimeState[IpduId].RxIpduCounter)
            {
                if (NULL_PTR != rxIpduPtr->ComIPduCounter->ComIPduCounterErrorNotification)
                {
                    rxIpduPtr->ComIPduCounter->ComIPduCounterErrorNotification(
                        IpduId,
                        Com_RxIPduRunTimeState[IpduId].RxIpduCounter,
                        RxCounter);
                }
#if (STD_ON == COM_RX_IPDU_COUNTER_ENABLE)
                /*update the expected counter*/
                Com_PduCounterIncrease(FALSE, IpduId);
#endif /* (STD_ON == COM_RX_IPDU_COUNTER_ENABLE) */
                Com_RxIPduRunTimeState[IpduId].RxReplicationNumber = 0u;
            }
        }
    }
    return rxPduValid;
}
#endif /* #if (STD_ON == COM_IPDU_REPLICATION_ENABLE) */
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/******************************************************************************/
/*
 * Brief               called by Com_RxIpduController.
 *                     reset OCCURRENCE of filter with ComFilterAlgorithm
 *                     ONE_EVERY_N.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      IpduId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if ((COM_IPDUGROUP_NUMBER > 0u) && (COM_ONEEVERYNFILTERSIGNAL_NUMBER > 0u))
static FUNC(void, COM_CODE) Com_ResetRxOccurrenceOfPduFilter(PduIdType IpduId)
{
    uint16 cnt;
    Com_SignalIdType oneEveryNId;
#if (0u < COM_RXSIGNAL_NUMBER)
    Com_SignalIdType ipduSignalNumber;
    Com_SignalIdType signalId;
#endif
#if ((0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXGROUPSIGNAL_NUMBER))
    Com_SignalGroupIdType ipduSignalGroupNumber;
    Com_SignalGroupIdType signalGroupId;
    uint16 counter;
    uint16 groupSignalNumber;
    uint16 groupSignalId;
#endif
    const Com_RxIPduType* rxIpduPtr = &Com_ConfigStd->ComRxIPdu[IpduId];
/*reset signal/group signal of rx pdu which ComFilterAlgorithm is ONE_EVERY_N*/
#if (0u < COM_RXSIGNAL_NUMBER)
    ipduSignalNumber = rxIpduPtr->ComIPduSignalsRefNumber;
    for (cnt = 0u; cnt < ipduSignalNumber; cnt++)
    {
        signalId = rxIpduPtr->ComIPduSignalsRef[cnt];
        if (NULL_PTR != Com_ConfigStd->ComRxSignal[signalId].ComFilter)
        {
            oneEveryNId = Com_ConfigStd->ComRxSignal[signalId].ComFilter->ComOneEveryNId;
            if (COM_UNUSED_UINT16 != oneEveryNId)
            {
                Com_OneEveryNcnt[oneEveryNId] = 0u;
            }
        }
    }
#endif
#if ((0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXGROUPSIGNAL_NUMBER))
    ipduSignalGroupNumber = rxIpduPtr->ComIPduSignalGroupsRefNumber;
    for (cnt = 0u; cnt < ipduSignalGroupNumber; cnt++)
    {
        signalGroupId = rxIpduPtr->ComIPduSignalGroupsRef[cnt];
        groupSignalNumber = Com_ConfigStd->ComRxSignalGroup[signalGroupId].ComGroupSignalNumber;
        for (counter = 0u; counter < groupSignalNumber; counter++)
        {
            groupSignalId = Com_ConfigStd->ComRxSignalGroup[signalGroupId].ComRxGroupSignalId[counter];
            if (NULL_PTR != Com_ConfigStd->ComRxGroupSignal[groupSignalId].ComFilter)
            {
                oneEveryNId = Com_ConfigStd->ComRxGroupSignal[groupSignalId].ComFilter->ComOneEveryNId;
                if (COM_UNUSED_UINT16 != oneEveryNId)
                {
                    Com_OneEveryNcnt[oneEveryNId] = 0u;
                }
            }
        }
    }
#endif
    return;
}
#endif
/******************************************************************************/
/*
 * Brief               called by Com_RxIpduController.
 *                     init the rx ipdu buffer,all signal buffer(included in
 *                     the ipdu,except source signal).
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      IpduId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (COM_IPDUGROUP_NUMBER > 0u)
static FUNC(void, COM_CODE) Com_ResetRxPduBufferAndSignalBuffer(PduIdType IpduId)
{
#if (0u < COM_RXIPDUBUFF_SIZE)
    uint16 pduBufferId;
    uint16 initPduLength;
#endif
    uint16 cnt;
    uint16 signalInitValueId;
    Com_SignalType signalType;
    uint16 signalLength;
#if (0u < COM_RXSIGNAL_NUMBER)
    Com_SignalIdType ipduSignalNumber;
    Com_SignalIdType signalId;
    const Com_RxSignalType* rxSignalPtr;
#endif
#if ((0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXGROUPSIGNAL_NUMBER))
    Com_SignalGroupIdType ipduSignalGroupNumber;
    Com_SignalGroupIdType signalGroupId;
    uint16 counter;
    uint16 groupSignalNumber;
    uint16 groupSignalId;
    const Com_RxSignalGroupType* rxSignalGroupPtr;
    const Com_RxGroupSignalType* rxGroupSignalPtr;
#endif
    const Com_RxIPduType* rxIpduPtr = &Com_ConfigStd->ComRxIPdu[IpduId];
/*init the rx ipdu buffer,all signal buffer(included in the ipdu,except source description signal)*/
#if (0u < COM_RXIPDUBUFF_SIZE)
    pduBufferId = rxIpduPtr->ComRxIPduBufIndex;
    initPduLength = Com_RxIPduInitState[IpduId].RxIpduLength;
    /*init rx pdu buffer*/
    for (cnt = 0u; cnt < initPduLength; cnt++)
    {
        Com_RxIPduRuntimeBuff[pduBufferId + cnt] = Com_RxIPduInitValue[pduBufferId + cnt];
    }
#endif
/*init signal buffer*/
#if (0u < COM_RXSIGNAL_NUMBER)
    ipduSignalNumber = rxIpduPtr->ComIPduSignalsRefNumber;
    for (cnt = 0u; cnt < ipduSignalNumber; cnt++)
    {
        signalId = rxIpduPtr->ComIPduSignalsRef[cnt];
        rxSignalPtr = &Com_ConfigStd->ComRxSignal[signalId];
        signalInitValueId = rxSignalPtr->ComSignalInitValueId;
        signalType = rxSignalPtr->ComSignalType;
        if (signalType < COM_UINT8_DYN)
        {
            signalLength = 0u;
        }
        else
        {
            signalLength = (COM_UINT8_DYN == signalType) ? (rxSignalPtr->ComSignalDataInitValueLength)
                                                         : (rxSignalPtr->ComSignalLength);
        }
        Com_InitSignalBuffer(signalType, signalInitValueId, signalLength);
    }
#endif
/*init group signal buffer*/
#if ((0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXGROUPSIGNAL_NUMBER))
    ipduSignalGroupNumber = rxIpduPtr->ComIPduSignalGroupsRefNumber;
    for (cnt = 0u; cnt < ipduSignalGroupNumber; cnt++)
    {
        signalGroupId = rxIpduPtr->ComIPduSignalGroupsRef[cnt];
        rxSignalGroupPtr = &Com_ConfigStd->ComRxSignalGroup[signalGroupId];
        groupSignalNumber = rxSignalGroupPtr->ComGroupSignalNumber;
        for (counter = 0u; counter < groupSignalNumber; counter++)
        {
            groupSignalId = rxSignalGroupPtr->ComRxGroupSignalId[counter];
            rxGroupSignalPtr = &Com_ConfigStd->ComRxGroupSignal[groupSignalId];
            signalInitValueId = rxGroupSignalPtr->ComSignalInitValueId;
            signalType = rxGroupSignalPtr->ComSignalType;
            if (signalType < COM_UINT8_DYN)
            {
                signalLength = 0u;
            }
            else
            {
                signalLength = (COM_UINT8_DYN == signalType) ? (rxGroupSignalPtr->ComSignalDataInitValueLength)
                                                             : (rxGroupSignalPtr->ComSignalLength);
            }
            Com_InitSignalBuffer(signalType, signalInitValueId, signalLength);
        }
    }
#endif
    Com_RxIPduRunTimeState[IpduId].GWDynamicSignalLength = 0u;
    Com_RxIPduRunTimeState[IpduId].NeedGW = FALSE;
    Com_RxIPduRunTimeState[IpduId].Receiving = FALSE;
    Com_RxIPduRunTimeState[IpduId].RxIndication = FALSE;
    Com_RxIPduRunTimeState[IpduId].RxIpduLength = Com_RxIPduInitState[IpduId].RxIpduLength;
    return;
}
#endif
/******************************************************************************/
/*
 * Brief               called by Com_IndicationProcess.
 *                     unpack the rx source description signal to gateway buffer.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      SourceSignalId,SourceSignalId,IpduBufferId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (0u < COM_GW_SOURCE_DESCRIPTION_NUMBER)
static FUNC(void, COM_CODE)
    Com_SourceSignalUnPack(Com_SignalIdType SourceSignalId, uint16 RxDynSignalLength, uint16 IpduBufferId)
{
#if (0u < COM_RXIPDUBUFF_SIZE)
    const Com_GwSourceSignalType* gwSourceSignalPtr = &Com_ConfigStd->ComSourceSignal[SourceSignalId];
#if (0u < COM_GWSIGNAL_8BITBUFF_SIZE)
    uint32 bitPosition;
    uint16 cnt;
    uint16 ipduBufferPos;
    uint16 signalLength;
#endif /* #if (0u < COM_GWSIGNAL_8BITBUFF_SIZE) */
    uint16 signalBufferId = gwSourceSignalPtr->GWSignalBufferId;
    uint64 sourceSignalValue;
    Com_SignalType signalType = gwSourceSignalPtr->ComSignalType;

    if ((signalType != COM_UINT8_N) && (signalType != COM_UINT8_DYN))
    {
        sourceSignalValue = Com_SourceSignalNotArrayUnPack(SourceSignalId);
        switch (signalType)
        {
#if (0u < COM_GWSIGNAL_BOOLBUFF_SIZE)
        case COM_BOOLEAN:
            Com_GWSignalBoolBuff[signalBufferId] = (boolean)sourceSignalValue;
            break;
#endif
#if (0u < COM_GWSIGNAL_8BITBUFF_SIZE)
        case COM_SINT8:
        case COM_UINT8:
            Com_GWSignal8BitBuff[signalBufferId] = (uint8)sourceSignalValue;
            break;
#endif
#if (0u < COM_GWSIGNAL_16BITBUFF_SIZE)
        case COM_SINT16:
        case COM_UINT16:
            Com_GWSignal16BitBuff[signalBufferId] = (uint16)sourceSignalValue;
            break;
#endif
#if (0u < COM_GWSIGNAL_32BITBUFF_SIZE)
        case COM_SINT32:
        case COM_UINT32:
        case COM_FLOAT32:
            Com_GWSignal32BitBuff[signalBufferId] = (uint32)sourceSignalValue;
            break;
#endif
#if (0u < COM_GWSIGNAL_64BITBUFF_SIZE)
        case COM_SINT64:
        case COM_UINT64:
        case COM_FLOAT64:
            Com_GWSignal64BitBuff[signalBufferId] = sourceSignalValue;
            break;
#endif
        default:
            /*do nothing*/
            break;
        }
    }
    else
    {
#if (0u < COM_GWSIGNAL_8BITBUFF_SIZE)
        bitPosition = gwSourceSignalPtr->ComBitPosition;
        ipduBufferPos = IpduBufferId + (uint16)(bitPosition >> 3u);
        /* COM_UINT8_DYN or COM_UINT8_N */
        signalLength = (COM_UINT8_N == signalType) ? gwSourceSignalPtr->ComSignalLength : RxDynSignalLength;

        for (cnt = 0u; cnt < signalLength; cnt++)
        {
            Com_GWSignal8BitBuff[signalBufferId + cnt] = Com_RxIPduRuntimeBuff[ipduBufferPos + cnt];
        }
#endif /* 0u < COM_GWSIGNAL_8BITBUFF_SIZE */
    }
#endif
    return;
}
#endif
/******************************************************************************/
/*
 * Brief               called by Com_IndicationProcess.
 *                     unpack the rx signal and notification up layer.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      RxSignalId,RxDynSignalLength,IpduBufferId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (0u < COM_RXSIGNAL_NUMBER)
static FUNC(void, COM_CODE)
    Com_SignalRxIndication(Com_SignalIdType RxSignalId, uint16 RxDynSignalLength, uint16 IpduBufferId)
{
#if (0u < COM_RXIPDUBUFF_SIZE)
#if (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE)
    const Com_RxSignalType* rxSignalPtr = &Com_ConfigStd->ComRxSignal[RxSignalId];
    uint16 signalLength;
#if (0u < COM_GWSIGNAL_8BITBUFF_SIZE)
    uint16 gwSignalBufferId;
    uint16 cnt;
    uint16 ipduBufferPos;
#endif /* 0u < COM_GWSIGNAL_8BITBUFF_SIZE */
    Com_SignalType signalType = rxSignalPtr->ComSignalType;

    if ((signalType != COM_UINT8_N) && (signalType != COM_UINT8_DYN))
#endif /* #if (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE) */
    {
        Com_RxSignalHandle(RxSignalId);
    }
#if (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE)
    else
    {
        /* COM_UINT8_DYN or COM_UINT8_N */
        signalLength = (COM_UINT8_N == signalType) ? rxSignalPtr->ComSignalLength : RxDynSignalLength;
#if (0u < COM_GWSIGNAL_8BITBUFF_SIZE)
        gwSignalBufferId = rxSignalPtr->GWSignalBufferId;
        ipduBufferPos = IpduBufferId + (uint16)(rxSignalPtr->ComBitPosition >> 3U);

        /*the rx signal need to be gateway,then store the value to gateway buffer*/
        if (COM_UNUSED_UINT16 != gwSignalBufferId)
        {
            for (cnt = 0u; cnt < signalLength; cnt++)
            {
                Com_GWSignal8BitBuff[gwSignalBufferId + cnt] = Com_RxIPduRuntimeBuff[ipduBufferPos + cnt];
            }
        }
#endif /* 0u < COM_GWSIGNAL_8BITBUFF_SIZE */
#if (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_N_ENABLE)
        if (COM_UINT8_N == signalType)
        {
            Com_Rx8NSignalHandle(RxSignalId, signalLength, IpduBufferId);
        }
#endif /* #if (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_N_ENABLE) */
#if (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE)
        if (COM_UINT8_DYN == signalType)
        {
            Com_Rx8DYNSignalHandle(RxSignalId, signalLength, IpduBufferId);
        }
#endif /* #if (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE) */
    }
#endif /* #if (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_N_ENABLE)|| (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE) */
#endif
    return;
}
#endif
/******************************************************************************/
/*
 * Brief               called by Com_SignalRxIndication.
 *                     unpack the rx signal(signal type is COM_UINT8_N)
 *                     and notification up layer.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      SignalId,SignalLength,BufferId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if ((0u < COM_RXSIGNAL_NUMBER) && (0u < COM_RXIPDUBUFF_SIZE) && (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_N_ENABLE))
static FUNC(void, COM_CODE) Com_Rx8NSignalHandle(Com_SignalIdType SignalId, uint16 SignalLength, uint16 BufferId)
{
    const Com_RxSignalType* rxSignalPtr = &Com_ConfigStd->ComRxSignal[SignalId];
#if (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ENABLE)
    boolean needFilter = TRUE;
    uint16 invalidValueId = rxSignalPtr->ComSignalDataInvalidValueId;
    boolean invalidValue = TRUE;
#endif /* #if (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ENABLE) */
    uint16 cnt;
    uint16 ipduBufferPos = BufferId + (uint16)(rxSignalPtr->ComBitPosition >> 3u);
#if (0u < COM_SIGNAL_8BITBUFF_SIZE)
    uint16 initValueId = rxSignalPtr->ComSignalInitValueId;
#endif

/*the rx signal configuration invalid value*/
#if (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ENABLE)
    if (COM_UNUSED_UINT16 != invalidValueId)
    {
#if (0u < COM_SIGNAL_8BIT_INVALID_SIZE)
        for (cnt = 0u; (cnt < SignalLength) && (TRUE == invalidValue); cnt++)
        {
            if (Com_Signal8BitInvalidValue[invalidValueId + cnt] != Com_RxIPduRuntimeBuff[ipduBufferPos + cnt])
            {
                invalidValue = FALSE;
            }
        }
#endif
        if (TRUE == invalidValue)
        {
#if (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ACTION_NOTIFY_ENABLE)
            if (COM_INVALID_ACTION_NOTIFY == rxSignalPtr->ComDataInvalidAction)
            {
                if (NULL_PTR != rxSignalPtr->ComInvalidNotification)
                {
                    rxSignalPtr->ComInvalidNotification();
                }
            }
            else
#endif /* #if (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ACTION_NOTIFY_ENABLE) */
            {
#if (STD_ON == COM_RX_SIGNAL_FILTER_ENABLE)
                if ((NULL_PTR == rxSignalPtr->ComFilter)
                    || ((NULL_PTR != rxSignalPtr->ComFilter)
                        && (COM_ALWAYS == rxSignalPtr->ComFilter->ComFilterAlgorithm)))
#endif /* #if (STD_ON == COM_RX_SIGNAL_FILTER_ENABLE) */
                {
#if (0u < COM_SIGNAL_8BITBUFF_SIZE)
                    for (cnt = 0u; cnt < SignalLength; cnt++)
                    {
                        Com_Signal8BitRuntimeBuff[initValueId + cnt] = Com_Signal8BitInitValue[initValueId + cnt];
                    }
#endif
#if (STD_ON == COM_RX_SIGNAL_NOTIFICATION_ENABLE)
                    if (NULL_PTR != rxSignalPtr->ComNotification)
                    {
                        rxSignalPtr->ComNotification();
                    }
#endif /* #if (STD_ON == COM_RX_SIGNAL_NOTIFICATION_ENABLE) */
                }
            }
            needFilter = FALSE;
        }
    }
    if (TRUE == needFilter)
#endif /* #if (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ENABLE) */
    {
#if (STD_ON == COM_RX_SIGNAL_FILTER_ENABLE)
        if ((NULL_PTR == rxSignalPtr->ComFilter)
            || ((NULL_PTR != rxSignalPtr->ComFilter) && (COM_ALWAYS == rxSignalPtr->ComFilter->ComFilterAlgorithm)))
#endif /* #if (STD_ON == COM_RX_SIGNAL_FILTER_ENABLE) */
        {
#if (0u < COM_SIGNAL_8BITBUFF_SIZE)
            for (cnt = 0u; cnt < SignalLength; cnt++)
            {
                Com_Signal8BitRuntimeBuff[initValueId + cnt] = Com_RxIPduRuntimeBuff[ipduBufferPos + cnt];
            }
#endif
#if (STD_ON == COM_RX_SIGNAL_NOTIFICATION_ENABLE)
            if (NULL_PTR != rxSignalPtr->ComNotification)
            {
                rxSignalPtr->ComNotification();
            }
#endif /* #if (STD_ON == COM_RX_SIGNAL_NOTIFICATION_ENABLE) */
        }
    }
    return;
}
#endif /* #if ((0u < COM_RXSIGNAL_NUMBER) && (0u < COM_RXIPDUBUFF_SIZE) && (STD_ON == \
          COM_RX_SIGNAL_TYPE_UINT8_N_ENABLE)) */
/******************************************************************************/
/*
 * Brief               called by Com_SignalRxIndication.
 *                     unpack the rx signal(signal type is COM_UINT8_DYN)
 *                     and notification up layer.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      SignalId,SignalLength,BufferId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if ((0u < COM_RXSIGNAL_NUMBER) && (0u < COM_RXIPDUBUFF_SIZE) && (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE))
static FUNC(void, COM_CODE) Com_Rx8DYNSignalHandle(Com_SignalIdType SignalId, uint16 SignalLength, uint16 BufferId)
{
    const Com_RxSignalType* rxSignalPtr = &Com_ConfigStd->ComRxSignal[SignalId];
#if (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ENABLE)
    boolean needFilter = TRUE;
    uint16 invalidValueId = rxSignalPtr->ComSignalDataInvalidValueId;
    uint16 initValueLength = rxSignalPtr->ComSignalDataInitValueLength;
    boolean invalidValue = TRUE;
    uint16 rxIpduLength;
#endif /* #if (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ENABLE) */
    uint16 cnt;
    uint16 ipduBufferPos = BufferId + (uint16)(rxSignalPtr->ComBitPosition >> 3u);
#if (0u < COM_SIGNAL_8BITBUFF_SIZE)
    uint16 initValueId = rxSignalPtr->ComSignalInitValueId;
#endif

    /*the rx signal configuration invalid value*/
#if (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ENABLE)
    if (COM_UNUSED_UINT16 != invalidValueId)
    {
        if (SignalLength != rxSignalPtr->ComSignalDataInvalidValueLength)
        {
            invalidValue = FALSE;
        }
        else
        {
#if (0u < COM_SIGNAL_8BIT_INVALID_SIZE)
            for (cnt = 0u; (cnt < SignalLength) && (TRUE == invalidValue); cnt++)
            {
                if (Com_Signal8BitInvalidValue[invalidValueId + cnt] != Com_RxIPduRuntimeBuff[ipduBufferPos + cnt])
                {
                    invalidValue = FALSE;
                }
            }
#endif
        }
        if (TRUE == invalidValue)
        {
#if (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ACTION_NOTIFY_ENABLE)
            if (COM_INVALID_ACTION_NOTIFY == rxSignalPtr->ComDataInvalidAction)
            {
                if (NULL_PTR != rxSignalPtr->ComInvalidNotification)
                {
                    rxSignalPtr->ComInvalidNotification();
                }
            }
            else
#endif /* #if (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ACTION_NOTIFY_ENABLE) */
            {
#if (STD_ON == COM_RX_SIGNAL_FILTER_ENABLE)
                if ((NULL_PTR == rxSignalPtr->ComFilter)
                    || ((NULL_PTR != rxSignalPtr->ComFilter)
                        && (COM_ALWAYS == rxSignalPtr->ComFilter->ComFilterAlgorithm)))
#endif /* #if (STD_ON == COM_RX_SIGNAL_FILTER_ENABLE) */
                {
#if (0u < COM_SIGNAL_8BITBUFF_SIZE)
                    for (cnt = 0u; cnt < initValueLength; cnt++)
                    {
                        Com_Signal8BitRuntimeBuff[initValueId + cnt] = Com_Signal8BitInitValue[initValueId + cnt];
                    }
#endif
                    /*change the rx Ipdu length to Init rx Ipdu length*/
                    rxIpduLength = Com_RxIPduRunTimeState[rxSignalPtr->ComIpduRefIndex].RxIpduLength;
                    rxIpduLength = rxIpduLength - SignalLength + initValueLength;
                    Com_RxIPduRunTimeState[rxSignalPtr->ComIpduRefIndex].RxIpduLength = rxIpduLength;
#if (STD_ON == COM_RX_SIGNAL_NOTIFICATION_ENABLE)
                    if (NULL_PTR != rxSignalPtr->ComNotification)
                    {
                        rxSignalPtr->ComNotification();
                    }
#endif /* #if (STD_ON == COM_RX_SIGNAL_NOTIFICATION_ENABLE) */
                }
            }
            needFilter = FALSE;
        }
    }
    if (TRUE == needFilter)
#endif /* #if (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ENABLE) */
    {
#if (STD_ON == COM_RX_SIGNAL_FILTER_ENABLE)
        if ((NULL_PTR == rxSignalPtr->ComFilter)
            || ((NULL_PTR != rxSignalPtr->ComFilter) && (COM_ALWAYS == rxSignalPtr->ComFilter->ComFilterAlgorithm)))
#endif /* #if (STD_ON == COM_RX_SIGNAL_FILTER_ENABLE) */
        {
#if (0u < COM_SIGNAL_8BITBUFF_SIZE)
            for (cnt = 0u; cnt < SignalLength; cnt++)
            {
                Com_Signal8BitRuntimeBuff[initValueId + cnt] = Com_RxIPduRuntimeBuff[ipduBufferPos + cnt];
            }
#endif
#if (STD_ON == COM_RX_SIGNAL_NOTIFICATION_ENABLE)
            if (NULL_PTR != rxSignalPtr->ComNotification)
            {
                rxSignalPtr->ComNotification();
            }
#endif /* #if (STD_ON == COM_RX_SIGNAL_NOTIFICATION_ENABLE) */
        }
    }
    return;
}
#endif /* #if ((0u < COM_RXSIGNAL_NUMBER) && (0u < COM_RXIPDUBUFF_SIZE) && (STD_ON == \
          COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE)) */
/******************************************************************************/
/*
 * Brief               called by Com_SignalRxIndication.
 *                     unpack the rx signal(signal type isn't COM_UINT8_N or
 *                     COM_UINT8_DYN) and notification up layer.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      SignalId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if ((0u < COM_RXSIGNAL_NUMBER) && (0u < COM_RXIPDUBUFF_SIZE))
static FUNC(void, COM_CODE) Com_RxSignalHandle(Com_SignalIdType SignalId)
{
    const Com_RxSignalType* rxSignalPtr = &Com_ConfigStd->ComRxSignal[SignalId];
#if (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ENABLE)
    boolean needFilter = TRUE;
    boolean invalidValue;
    uint16 invalidValueId = rxSignalPtr->ComSignalDataInvalidValueId;
#endif /* #if (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ENABLE) */
    uint64 unPackValue;
#if (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ENABLE) || (COM_RXSIGNALMASKNEWDIFFERMASKOLD_NUMBER > 0u)
    uint16 initValueId = rxSignalPtr->ComSignalInitValueId;
#endif /* #if (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ENABLE) || (COM_RXSIGNALMASKNEWDIFFERMASKOLD_NUMBER > 0u) */
#if (STD_ON == COM_SIGNAL_GW_ENABLE)
    uint16 gwSignalBufferId = rxSignalPtr->GWSignalBufferId;
#endif /* #if (STD_ON == COM_SIGNAL_GW_ENABLE) */
#if (STD_ON == COM_SIGNAL_GW_ENABLE) || (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ENABLE) \
    || (STD_ON == COM_RX_SIGNAL_FILTER_ENABLE)
    Com_SignalType signalType = rxSignalPtr->ComSignalType;
#endif /* #if (STD_ON == COM_SIGNAL_GW_ENABLE) || (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ENABLE) || (STD_ON == \
          COM_RX_SIGNAL_FILTER_ENABLE) */
#if (STD_ON == COM_RX_SIGNAL_FILTER_ENABLE)
    boolean filterPass;
#endif /* #if (STD_ON == COM_RX_SIGNAL_FILTER_ENABLE) */

    /* unpack the signal value from rx ipdu buffer, and do B-End and L-End exchanging,Flag Extension
       and return the result as an uint64 value to variable 'unPackValue'. */
    unPackValue = Com_RxSignalUnPack(SignalId);
/* update signal value into GW signal buffer */
#if (STD_ON == COM_SIGNAL_GW_ENABLE)
    Com_UpdateGWSignalBuffer(unPackValue, gwSignalBufferId, signalType);
#endif /* #if (STD_ON == COM_SIGNAL_GW_ENABLE) */
/*the rx signal configuration invalid value*/
#if (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ENABLE)
    if (COM_UNUSED_UINT16 != invalidValueId)
    {
        invalidValue = Com_SignalInvalidateHandle(signalType, invalidValueId, unPackValue);
        if (TRUE == invalidValue)
        {
#if (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ACTION_NOTIFY_ENABLE)
            if (COM_INVALID_ACTION_NOTIFY == rxSignalPtr->ComDataInvalidAction)
            {
                if (NULL_PTR != rxSignalPtr->ComInvalidNotification)
                {
                    rxSignalPtr->ComInvalidNotification();
                }
                needFilter = FALSE;
            }
            else
#endif /* #if (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ACTION_NOTIFY_ENABLE) */
            {
                /*replace signal runtime buffer, with init value. */
                unPackValue = Com_RxSignalReplaceHanlde(signalType, initValueId);
            }
        }
    }
    if (TRUE == needFilter)
#endif /* #if (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ENABLE) */
    {
#if (STD_ON == COM_RX_SIGNAL_FILTER_ENABLE)
        filterPass = Com_RxSignalFilter(
            unPackValue,
            rxSignalPtr->ComFilter,
#if (COM_RXSIGNALMASKNEWDIFFERMASKOLD_NUMBER > 0u)
            initValueId,
#endif
            signalType);
        if (TRUE == filterPass)
#endif /* #if (STD_ON == COM_RX_SIGNAL_FILTER_ENABLE) */
        {
            /* update signal value into signal runtime buffer */
            Com_RxSignalBuffHanlde(unPackValue, SignalId);
/* if this signal has normal rx notification function configured,
   invoke this function. */
#if (STD_ON == COM_RX_SIGNAL_NOTIFICATION_ENABLE)
            if (NULL_PTR != rxSignalPtr->ComNotification)
            {
                rxSignalPtr->ComNotification();
            }
#endif /* #if (STD_ON == COM_RX_SIGNAL_NOTIFICATION_ENABLE) */
        }
    }
    return;
}
#endif
/******************************************************************************/
/*
 * Brief               called by Com_RxSignalHandle,Com_SignalGroupRxIndication.
 *                     judge the rx (group) signal value is invalid value or not.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      SignalType,InvalidValueId,Value
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              boolean
 */
/******************************************************************************/
#if ((0u < COM_RXGROUPSIGNAL_NUMBER) || (0u < COM_RXSIGNAL_NUMBER)) && (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ENABLE)
static FUNC(boolean, COM_CODE)
    Com_SignalInvalidateHandle(Com_SignalType SignalType, uint16 InvalidValueId, uint64 Value)
{
    boolean ret = FALSE;
    switch (SignalType)
    {
#if (0u < COM_SIGNAL_BOOL_INVALID_SIZE)
    case COM_BOOLEAN:
        if (((boolean)Value) == Com_SignalBoolInvalidValue[InvalidValueId])
        {
            ret = TRUE;
        }
        break;
#endif
#if (0u < COM_SIGNAL_8BIT_INVALID_SIZE)
    case COM_SINT8:
    case COM_UINT8:
        if (((uint8)Value) == Com_Signal8BitInvalidValue[InvalidValueId])
        {
            ret = TRUE;
        }
        break;
#endif
#if (0u < COM_SIGNAL_16BIT_INVALID_SIZE)
    case COM_SINT16:
    case COM_UINT16:
        if (((uint16)Value) == Com_Signal16BitInvalidValue[InvalidValueId])
        {
            ret = TRUE;
        }
        break;
#endif
#if (0u < COM_SIGNAL_32BIT_INVALID_SIZE)
    case COM_SINT32:
    case COM_UINT32:
    case COM_FLOAT32:
        if (((uint32)Value) == Com_Signal32BitInvalidValue[InvalidValueId])
        {
            ret = TRUE;
        }
        break;
#endif
#if (0u < COM_SIGNAL_64BIT_INVALID_SIZE)
    case COM_SINT64:
    case COM_UINT64:
    case COM_FLOAT64:
        if (Value == Com_Signal64BitInvalidValue[InvalidValueId])
        {
            ret = TRUE;
        }
        break;
#endif
    default:
        /*do nothing*/
        break;
    }
    COM_NOUSED(InvalidValueId);
    COM_NOUSED(Value);
    return ret;
}
#endif /* #if ((0u < COM_RXGROUPSIGNAL_NUMBER) || (0u < COM_RXSIGNAL_NUMBER)) && (STD_ON == \
          COM_RX_SIGNAL_INVALID_DATA_ENABLE) */
/******************************************************************************/
/*
 * Brief               called by Com_RxSignalHandle,Com_InvalidSignalReplaceAndNotification,
 *                     Com_RxSignalGroupFilter.
 *                     get the rx (group) signal's init value.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      SignalType,InitValueId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              uint64
 */
/******************************************************************************/
#if ((0u < COM_RXSIGNAL_NUMBER) || (0u < COM_RXGROUPSIGNAL_NUMBER)) \
    && ((STD_ON == COM_RX_SIGNAL_INVALID_DATA_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_INVALID_DATA_ENABLE))
static FUNC(uint64, COM_CODE) Com_RxSignalReplaceHanlde(Com_SignalType SignalType, uint16 InitValueId)
{
    uint64 unPackValue = COM_UNUSED_UINT64;
    switch (SignalType)
    {
#if (0u < COM_SIGNAL_BOOLBUFF_SIZE)
    case COM_BOOLEAN:
        /* PRQA S 4304 ++ */ /* MISRA Rule 10.5 */
        unPackValue = (uint64)Com_SignalBoolInitValue[InitValueId];
        /* PRQA S 4304 -- */ /* MISRA Rule 10.5 */
        break;
#endif
#if (0u < COM_SIGNAL_8BITBUFF_SIZE)
    case COM_SINT8:
    case COM_UINT8:
        unPackValue = (uint64)Com_Signal8BitInitValue[InitValueId];
        break;
#endif
#if (0u < COM_SIGNAL_16BITBUFF_SIZE)
    case COM_SINT16:
    case COM_UINT16:
        unPackValue = (uint64)Com_Signal16BitInitValue[InitValueId];
        break;
#endif
#if (0u < COM_SIGNAL_32BITBUFF_SIZE)
    case COM_SINT32:
    case COM_UINT32:
    case COM_FLOAT32:
        unPackValue = (uint64)Com_Signal32BitInitValue[InitValueId];
        break;
#endif
#if (0u < COM_SIGNAL_64BITBUFF_SIZE)
    case COM_SINT64:
    case COM_UINT64:
    case COM_FLOAT64:
        unPackValue = Com_Signal64BitInitValue[InitValueId];
        break;
#endif
    default:
        /*do nothing*/
        break;
    }
    return unPackValue;
}
#endif /* #if ((0u < COM_RXSIGNAL_NUMBER) || (0u < COM_RXGROUPSIGNAL_NUMBER)) && ((STD_ON == \
          COM_RX_SIGNAL_INVALID_DATA_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_INVALID_DATA_ENABLE)) */
/******************************************************************************/
/*
 * Brief               called by Com_RxSignalHandle,
 *                     Com_InvalidSignalReplaceAndNotification.
 *                     update the rx signal value buffer.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      Value,Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (0u < COM_RXSIGNAL_NUMBER)
static FUNC(void, COM_CODE) Com_RxSignalBuffHanlde(uint64 Value, Com_SignalIdType Id)
{
    const Com_RxSignalType* rxSignalPtr = &Com_ConfigStd->ComRxSignal[Id];
    uint16 initValue = rxSignalPtr->ComSignalInitValueId;
    Com_SignalType rxSignalType = rxSignalPtr->ComSignalType;

    switch (rxSignalType)
    {
#if (0u < COM_SIGNAL_BOOLBUFF_SIZE)
    case COM_BOOLEAN:
        /* PRQA S 4340 ++ */ /* MISRA Rule 10.5 */
        Com_SignalBoolRuntimeBuff[initValue] = (boolean)Value;
        /* PRQA S 4340 -- */ /* MISRA Rule 10.5 */
        break;
#endif
#if (0u < COM_SIGNAL_8BITBUFF_SIZE)
    case COM_SINT8:
    case COM_UINT8:
        Com_Signal8BitRuntimeBuff[initValue] = (uint8)Value;
        break;
#endif
#if (0u < COM_SIGNAL_16BITBUFF_SIZE)
    case COM_SINT16:
    case COM_UINT16:
        Com_Signal16BitRuntimeBuff[initValue] = (uint16)Value;
        break;
#endif
#if (0u < COM_SIGNAL_32BITBUFF_SIZE)
    case COM_SINT32:
    case COM_UINT32:
    case COM_FLOAT32:
        Com_Signal32BitRuntimeBuff[initValue] = (uint32)Value;
        break;
#endif
#if (0u < COM_SIGNAL_64BITBUFF_SIZE)
    case COM_SINT64:
    case COM_UINT64:
    case COM_FLOAT64:
        Com_Signal64BitRuntimeBuff[initValue] = (uint64)Value;
        break;
#endif
    default:
        /*do nothing*/
        break;
    }
    return;
}
#endif
/******************************************************************************/
/*
 * Brief               called by Com_RxSignalHandle,Com_SignalGroupRxIndication.
 *                     update the gateway signal value buffer of the rx signal.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      Value,GWSignalBufferId,SignalType
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if ((0u < COM_RXGROUPSIGNAL_NUMBER) || (0u < COM_RXSIGNAL_NUMBER)) && (STD_ON == COM_SIGNAL_GW_ENABLE)
static FUNC(void, COM_CODE) Com_UpdateGWSignalBuffer(uint64 Value, uint16 GWSignalBufferId, Com_SignalType SignalType)
{
    /*the rx signal need gateway,store signal value in gateway buffer*/
    if (COM_UNUSED_UINT16 != GWSignalBufferId)
    {
        switch (SignalType)
        {
#if (0u < COM_GWSIGNAL_BOOLBUFF_SIZE)
        case COM_BOOLEAN:
            Com_GWSignalBoolBuff[GWSignalBufferId] = (boolean)Value;
            break;
#endif
#if (0u < COM_GWSIGNAL_8BITBUFF_SIZE)
        case COM_SINT8:
        case COM_UINT8:
            Com_GWSignal8BitBuff[GWSignalBufferId] = (uint8)Value;
            break;
#endif
#if (0u < COM_GWSIGNAL_16BITBUFF_SIZE)
        case COM_SINT16:
        case COM_UINT16:
            Com_GWSignal16BitBuff[GWSignalBufferId] = (uint16)Value;
            break;
#endif
#if (0u < COM_GWSIGNAL_32BITBUFF_SIZE)
        case COM_SINT32:
        case COM_UINT32:
        case COM_FLOAT32:
            Com_GWSignal32BitBuff[GWSignalBufferId] = (uint32)Value;
            break;
#endif
#if (0u < COM_GWSIGNAL_64BITBUFF_SIZE)
        case COM_SINT64:
        case COM_UINT64:
        case COM_FLOAT64:
            Com_GWSignal64BitBuff[GWSignalBufferId] = (uint64)Value;
            break;
#endif
        default:
            /*do nothing*/
            break;
        }
    }
    COM_NOUSED(Value);
    return;
}
#endif /* #if ((0u < COM_RXGROUPSIGNAL_NUMBER) || (0u < COM_RXSIGNAL_NUMBER)) && (STD_ON == COM_SIGNAL_GW_ENABLE) */
/******************************************************************************/
/*
 * Brief               called by Com_IndicationProcess.
 *                     handle signal group RxIndication of one rx pdu.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      RxSignalGroupId,RxDynSignalLength,IpduBufferId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if ((0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXGROUPSIGNAL_NUMBER))
static FUNC(void, COM_CODE)
    Com_SignalGroupRxIndication(Com_SignalGroupIdType RxSignalGroupId, uint16 RxDynSignalLength, uint16 IpduBufferId)
{
    const Com_RxSignalGroupType* rxSignalGroupPtr = &Com_ConfigStd->ComRxSignalGroup[RxSignalGroupId];
    Com_SignalIdType groupSignalNumber = rxSignalGroupPtr->ComGroupSignalNumber;
    Com_SignalIdType counter;
    boolean signalGroupInvalid = FALSE;
#if (STD_ON == COM_RX_GRP_SIGNAL_INVALID_DATA_ENABLE)
    boolean needFilter = TRUE;
#endif /* #if (STD_ON == COM_RX_GRP_SIGNAL_INVALID_DATA_ENABLE) */
    Com_SignalIdType groupSignalId;
#if (STD_ON == COM_ENABLE_SIGNAL_GROUP_ARRAY_API) && (STD_ON == COM_RX_GRP_SIGNAL_INVALID_DATA_ENABLE)
    uint16 iPduSignalGroupArrayStartBufId;
    uint16 cnt, signalGroupArrayLength;
#endif /* #if (STD_ON == COM_ENABLE_SIGNAL_GROUP_ARRAY_API) && (STD_ON == COM_RX_GRP_SIGNAL_INVALID_DATA_ENABLE) */

#if (STD_ON == COM_RX_GRP_SIGNAL_INVALID_DATA_ENABLE)
    /*if the signal group have invalid signal or not*/
    signalGroupInvalid =
        Com_SignalGroupInvalidCalculate(RxSignalGroupId, groupSignalNumber, IpduBufferId, RxDynSignalLength);
    /*the signal group is invalid if at least one group signal is invalid*/
    if (TRUE == signalGroupInvalid)
    {
#if (STD_ON == COM_RX_SIG_GROUP_INVALID_DATA_ACTION_NOTIFY_ENABLE)
        if (COM_INVALID_ACTION_NOTIFY == rxSignalGroupPtr->ComDataInvalidAction)
        {
            if (NULL_PTR != rxSignalGroupPtr->ComInvalidNotification)
            {
                rxSignalGroupPtr->ComInvalidNotification();
            }
            needFilter = FALSE;
        }
        else
#endif /* #if (STD_ON == COM_RX_SIG_GROUP_INVALID_DATA_ACTION_NOTIFY_ENABLE) */
        {
/*replace the rx pdu buffer for signal group array*/
#if ((STD_ON == COM_ENABLE_SIGNAL_GROUP_ARRAY_API) && (0u < COM_RXIPDUBUFF_SIZE))
            if (NULL_PTR != rxSignalGroupPtr->ComSignalGroupArray)
            {
                iPduSignalGroupArrayStartBufId = rxSignalGroupPtr->ComSignalGroupArray->ComIPduStartBufIndex;
                signalGroupArrayLength = rxSignalGroupPtr->ComSignalGroupArray->SignalGroupArrayLength;
                for (cnt = 0u; cnt < signalGroupArrayLength; cnt++)
                {
                    Com_RxIPduRuntimeBuff[iPduSignalGroupArrayStartBufId + cnt] =
                        Com_RxIPduInitValue[iPduSignalGroupArrayStartBufId + cnt];
                }
            }
#endif
        }
    }
    if (TRUE == needFilter)
#endif /* #if (STD_ON == COM_RX_GRP_SIGNAL_INVALID_DATA_ENABLE) */
    {
#if (STD_ON == COM_RX_GRP_SIGNAL_FILTER_ENABLE)
        if (TRUE == Com_RxSignalGroupFilter(RxSignalGroupId, signalGroupInvalid, IpduBufferId))
#endif /* #if (STD_ON == COM_RX_GRP_SIGNAL_FILTER_ENABLE) */
        {
            /* update all group signal init value into group signal runtime buffer */
            for (counter = 0u; counter < groupSignalNumber; counter++)
            {
                groupSignalId = rxSignalGroupPtr->ComRxGroupSignalId[counter];
                Com_RxGroupSignalBuffHanlde(signalGroupInvalid, groupSignalId, IpduBufferId, RxDynSignalLength);
            }
            /* if this group signal has normal rx notification function configured,
            invoke this function. */
#if (STD_ON == COM_RX_SIG_GROUP_NOTIFICATION_ENABLE)
            if (NULL_PTR != rxSignalGroupPtr->ComNotification)
            {
                rxSignalGroupPtr->ComNotification();
            }
#endif /* #if (STD_ON == COM_RX_SIG_GROUP_NOTIFICATION_ENABLE) */
        }
    }
    return;
}
#endif
/******************************************************************************/
/*
 * Brief               called by Com_SignalGroupRxIndication,Com_TpPduInvalidAction.
 *                     judge the rx signal group value is filter out or not.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      SignalGroupId,InvalidSignalGroup,IpduBufferId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              boolean
 */
/******************************************************************************/
/* called by Com_SignalGroupRxIndication,Com_TpPduInvalidAction.
 * judge the rx signal group value is filter out or not*/
#if ((0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXGROUPSIGNAL_NUMBER) && (STD_ON == COM_RX_GRP_SIGNAL_FILTER_ENABLE))
static FUNC(boolean, COM_CODE)
    Com_RxSignalGroupFilter(Com_SignalGroupIdType SignalGroupId, boolean InvalidSignalGroup, uint16 IpduBufferId)
{
    const Com_RxSignalGroupType* rxSignalGroupPtr = &Com_ConfigStd->ComRxSignalGroup[SignalGroupId];
    Com_SignalIdType groupSignalNumber = rxSignalGroupPtr->ComGroupSignalNumber;
    Com_SignalIdType cnt;
    boolean signalGroupFilter = TRUE;
    Com_SignalIdType groupSignalId;
    Com_SignalType groupSignalType;
    uint16 groupSignalInitValueId;
    uint64 groupSignalValue;
    Com_RxGroupSignalType* rxGroupSignalPtr;

    for (cnt = 0u; (cnt < groupSignalNumber) && (TRUE == signalGroupFilter); cnt++)
    {
        groupSignalId = rxSignalGroupPtr->ComRxGroupSignalId[cnt];
        rxGroupSignalPtr = &Com_ConfigStd->ComRxGroupSignal[groupSignalId];
        groupSignalType = rxGroupSignalPtr->ComSignalType;
/*Other Signal types besides  COM_UINT8_DYN or COM_UINT8_DYN*/
#if (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE)
        if ((groupSignalType != COM_UINT8_N) && (groupSignalType != COM_UINT8_DYN))
#endif /* #if (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE) \
        */
        {
#if (STD_ON == COM_RX_GRP_SIGNAL_INVALID_DATA_ENABLE)
            /*the signal group value is invalid,use the init value replace*/
            if (TRUE == InvalidSignalGroup)
            {
                groupSignalInitValueId = rxGroupSignalPtr->ComSignalInitValueId;
                /*get the init value except COM_UINT8_N and UNIT8_DYN*/
                groupSignalValue = Com_RxSignalReplaceHanlde(groupSignalType, groupSignalInitValueId);
            }
            else
#endif /* (STD_ON == COM_RX_GRP_SIGNAL_INVALID_DATA_ENABLE) */
            {
#if (COM_RXSIGNALMASKNEWDIFFERMASKOLD_NUMBER > 0u)
                groupSignalInitValueId = rxGroupSignalPtr->ComSignalInitValueId;
#endif
                /*get the init value except COM_UINT8_N and UNIT8_DYN*/
                groupSignalValue = Com_RxGroupSignalUnPack(groupSignalId, IpduBufferId);
            }

            signalGroupFilter = Com_RxSignalFilter(
                groupSignalValue,
                rxGroupSignalPtr->ComFilter,
#if (COM_RXSIGNALMASKNEWDIFFERMASKOLD_NUMBER > 0u)
                groupSignalInitValueId,
#endif
                groupSignalType);
        }
/*COM_UINT8_N or COM_UINT8_DYN*/
#if (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE)
        else
        {
            if ((NULL_PTR != rxGroupSignalPtr->ComFilter)
                && (COM_NEVER == rxGroupSignalPtr->ComFilter->ComFilterAlgorithm))
            {
                signalGroupFilter = FALSE;
            }
        }
#endif /* #if (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE) \
        */
    }

    return signalGroupFilter;
}
#endif /* #if ((0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXGROUPSIGNAL_NUMBER) && (STD_ON == \
          COM_RX_GRP_SIGNAL_FILTER_ENABLE)) */
/******************************************************************************/
/*
 * Brief               called by Com_SignalGroupRxIndication,Com_TpPduInvalidAction.
 *                     update the rx group signal value buffer.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      InvalidSignalGroup,Id,IpduBufferId,RxDynSignalLength
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if ((0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXGROUPSIGNAL_NUMBER))
static FUNC(void, COM_CODE) Com_RxGroupSignalBuffHanlde(
    /* PRQA S 3206 ++ */ /* MISRA Rule 2.7 */
    boolean InvalidSignalGroup,
    /* PRQA S 3206 -- */ /* MISRA Rule 2.7 */
    Com_SignalIdType Id,
    uint16 IpduBufferId,
    uint16 RxDynSignalLength)
{
    const Com_RxGroupSignalType* rxGroupSignalPtr = &Com_ConfigStd->ComRxGroupSignal[Id];
    uint16 initValueId = rxGroupSignalPtr->ComSignalInitValueId;
    Com_SignalType signalType = rxGroupSignalPtr->ComSignalType;
    uint16 SignalLength = 0u;

/*rx signal group is invalid,use the init value update the rx group signal buffer*/
#if (STD_ON == COM_RX_GRP_SIGNAL_INVALID_DATA_ENABLE)
    if (TRUE == InvalidSignalGroup)
    {
#if (0u < COM_SIGNAL_8BITBUFF_SIZE)
#if (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_N_ENABLE)
        if (COM_UINT8_N == signalType)
        {
            SignalLength = rxGroupSignalPtr->ComSignalLength;
        }
#endif /* #if (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_N_ENABLE) */
#if (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE)
        if (COM_UINT8_DYN == signalType)
        {
            SignalLength = rxGroupSignalPtr->ComSignalDataInitValueLength;
            /*change the rx Ipdu length to Init rx Ipdu length*/
            Com_SignalGroupIdType signalGroupId = rxGroupSignalPtr->ComSignalGroupRef;
            PduIdType rxIpduId = Com_ConfigStd->ComRxSignalGroup[signalGroupId].ComIpduRefIndex;
            uint16 rxIpduMinLength = (uint16)Com_ConfigStd->ComRxIPdu[rxIpduId].IPduNoDynSignalLength;
            Com_RxIPduRunTimeState[rxIpduId].RxIpduLength = rxIpduMinLength + SignalLength;
        }
#endif /* #if (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE) */
#endif /*0u < COM_SIGNAL_8BITBUFF_SIZE*/
        Com_InitSignalBuffer(signalType, initValueId, SignalLength);
    }
    /*rx signal group is valid,use the really rx value update the rx group signal buffer*/
    else
#endif /* #if (STD_ON == COM_RX_GRP_SIGNAL_INVALID_DATA_ENABLE) */
    {
#if (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE)
        if ((signalType != COM_UINT8_N) && (signalType != COM_UINT8_DYN))
#endif /* #if (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE) \
        */
        {
            uint64 value;
            value = Com_RxGroupSignalUnPack(Id, IpduBufferId);
            switch (signalType)
            {
#if (0u < COM_SIGNAL_BOOLBUFF_SIZE)
            case COM_BOOLEAN:
                /* PRQA S 4340 ++ */ /* MISRA Rule 10.5 */
                Com_SignalBoolRuntimeBuff[initValueId] = (boolean)value;
                /* PRQA S 4340 -- */ /* MISRA Rule 10.5 */
                break;
#endif
#if (0u < COM_SIGNAL_8BITBUFF_SIZE)
            case COM_SINT8:
            case COM_UINT8:
                Com_Signal8BitRuntimeBuff[initValueId] = (uint8)value;
                break;
#endif
#if (0u < COM_SIGNAL_16BITBUFF_SIZE)
            case COM_SINT16:
            case COM_UINT16:
                Com_Signal16BitRuntimeBuff[initValueId] = (uint16)value;
                break;
#endif
#if (0u < COM_SIGNAL_32BITBUFF_SIZE)
            case COM_SINT32:
            case COM_UINT32:
            case COM_FLOAT32:
                Com_Signal32BitRuntimeBuff[initValueId] = (uint32)value;
                break;
#endif
#if (0u < COM_SIGNAL_64BITBUFF_SIZE)
            case COM_SINT64:
            case COM_UINT64:
            case COM_FLOAT64:
                Com_Signal64BitRuntimeBuff[initValueId] = value;
                break;
#endif
            default:
                /*do nothing*/
                break;
            }
        }
#if ((0u < COM_SIGNAL_8BITBUFF_SIZE) && (0u < COM_RXIPDUBUFF_SIZE))
#if (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE)
        else
        {
            uint16 ipduBufferPos;
            uint16 cnt;
            ipduBufferPos = IpduBufferId + (uint16)(rxGroupSignalPtr->ComBitPosition >> 3u);
            SignalLength = (COM_UINT8_N == signalType) ? rxGroupSignalPtr->ComSignalLength : RxDynSignalLength;
            for (cnt = 0u; cnt < SignalLength; cnt++)
            {
                Com_Signal8BitRuntimeBuff[initValueId + cnt] = Com_RxIPduRuntimeBuff[ipduBufferPos + cnt];
            }
        }
#endif /* #if (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE) \
        */
#endif /*(0u < COM_SIGNAL_8BITBUFF_SIZE) && (0u < COM_RXIPDUBUFF_SIZE)*/
    }
    return;
}
#endif
/******************************************************************************/
/*
 * Brief               called by Com_TpPduInvalidAction.
 *                     rx signal value replace,and notification.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      RxSignalId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if ((STD_ON == COM_RXTPPDU_SUPPORT) && (0u < COM_RXSIGNAL_NUMBER) && (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ENABLE))
static FUNC(void, COM_CODE) Com_InvalidSignalReplaceAndNotification(Com_SignalIdType RxSignalId)
{
    const Com_RxSignalType* rxSignalPtr = &Com_ConfigStd->ComRxSignal[RxSignalId];
    uint16 initValueId = rxSignalPtr->ComSignalInitValueId;
    uint64 initValue;
#if (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE)
    Com_SignalType signalType = rxSignalPtr->ComSignalType;

    if ((signalType != COM_UINT8_N) && (signalType != COM_UINT8_DYN))
#endif /* #if (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE) */
    {
        /*replace signal runtime buffer, with init value. */
        initValue = Com_RxSignalReplaceHanlde(signalType, initValueId);
#if (STD_ON == COM_RX_SIGNAL_FILTER_ENABLE)
        if (TRUE
            == Com_RxSignalFilter(
                initValue,
                rxSignalPtr->ComFilter,
#if (COM_RXSIGNALMASKNEWDIFFERMASKOLD_NUMBER > 0u)
                initValueId,
#endif
                signalType))
#endif /* #if (STD_ON == COM_RX_SIGNAL_FILTER_ENABLE) */
        {
            /* update signal value into signal runtime buffer */
            Com_RxSignalBuffHanlde(initValue, RxSignalId);
#if (STD_ON == COM_RX_SIGNAL_NOTIFICATION_ENABLE)
            if (NULL_PTR != rxSignalPtr->ComNotification)
            {
                rxSignalPtr->ComNotification();
            }
#endif /* #if (STD_ON == COM_RX_SIGNAL_NOTIFICATION_ENABLE) */
        }
    }
    /*COM_UINT8_N or COM_UINT8_DYN*/
#if (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE)
    else
    {
#if (STD_ON == COM_RX_SIGNAL_FILTER_ENABLE)
        if ((NULL_PTR == rxSignalPtr->ComFilter)
            || ((NULL_PTR != rxSignalPtr->ComFilter) && (COM_ALWAYS == rxSignalPtr->ComFilter->ComFilterAlgorithm)))
#endif /* #if (STD_ON == COM_RX_SIGNAL_FILTER_ENABLE) */
        {
            uint16 signalLength =
                (COM_UINT8_N == signalType) ? rxSignalPtr->ComSignalLength : rxSignalPtr->ComSignalDataInitValueLength;

#if (0u < COM_SIGNAL_8BITBUFF_SIZE)
            for (uint16 counter = 0u; counter < signalLength; counter++)
            {
                Com_Signal8BitRuntimeBuff[initValueId + counter] = Com_Signal8BitInitValue[initValueId + counter];
            }
#endif
#if (STD_ON == COM_RX_SIGNAL_NOTIFICATION_ENABLE)
            if (NULL_PTR != rxSignalPtr->ComNotification)
            {
                rxSignalPtr->ComNotification();
            }
#endif /* #if (STD_ON == COM_RX_SIGNAL_NOTIFICATION_ENABLE) */
        }
    }
#endif /* #if (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE) */

    return;
}
#endif /* #if ((STD_ON == COM_RXTPPDU_SUPPORT) && (0u < COM_RXSIGNAL_NUMBER) && (STD_ON == \
          COM_RX_SIGNAL_INVALID_DATA_ENABLE)) */
/******************************************************************************/
/*
 * Brief               called by Com_SignalGroupRxIndication,Com_RxGroupSignalBuffHanlde.
 *                     unpack rx group signal(signal type isn't COM_UINT8_N
 *                     or COM_UINT8_DYN).
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      SignalId,IpduBufferId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              uint64
 */
/******************************************************************************/
#if ((0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXGROUPSIGNAL_NUMBER))
static FUNC(uint64, COM_CODE) Com_RxGroupSignalUnPack(Com_SignalIdType SignalId, uint16 IpduBufferId)
{
    const Com_RxGroupSignalType* rxGroupSignalPtr = &Com_ConfigStd->ComRxGroupSignal[SignalId];
    uint64 signalValue;

    signalValue = Com_SignalUnPackHandle(
        rxGroupSignalPtr->ComSignalEndianness,
        rxGroupSignalPtr->ComSignalByteLength,
        &Com_RxIPduRuntimeBuff[IpduBufferId],
        rxGroupSignalPtr->ComBitPosition,
        rxGroupSignalPtr->ComBitSize,
        rxGroupSignalPtr->ComSignalType);
    return signalValue;
}
#endif /* #if ((0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXGROUPSIGNAL_NUMBER)) */
/******************************************************************************/
/*
 * Brief               called by Com_RxSignalHandle.
 *                     unpack the rx signal(signal type isn't COM_UINT8_N or
 *                     COM_UINT8_DYN).
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      SignalId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              uint64
 */
/******************************************************************************/
#if ((0u < COM_RXSIGNAL_NUMBER) && (0u < COM_RXIPDUBUFF_SIZE))
static FUNC(uint64, COM_CODE) Com_RxSignalUnPack(Com_SignalIdType SignalId)
{
    const Com_RxSignalType* rxSignalPtr = &Com_ConfigStd->ComRxSignal[SignalId];
    uint64 signalValue;
    uint16 ipduBufferIndex = Com_ConfigStd->ComRxIPdu[rxSignalPtr->ComIpduRefIndex].ComRxIPduBufIndex;

    signalValue = Com_SignalUnPackHandle(
        rxSignalPtr->ComSignalEndianness,
        rxSignalPtr->ComSignalByteLength,
        &Com_RxIPduRuntimeBuff[ipduBufferIndex],
        rxSignalPtr->ComBitPosition,
        rxSignalPtr->ComBitSize,
        rxSignalPtr->ComSignalType);
    return signalValue;
}
#endif /* #if ((0u < COM_RXSIGNAL_NUMBER) && (0u < COM_RXIPDUBUFF_SIZE)) */
/******************************************************************************/
/*
 * Brief               called by Com_SourceSignalUnPack.
 *                     unpack the rx source description signal.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      SourceSignalId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              uint64
 */
/******************************************************************************/
#if ((0u < COM_GW_SOURCE_DESCRIPTION_NUMBER) && (0u < COM_RXIPDUBUFF_SIZE))
static FUNC(uint64, COM_CODE) Com_SourceSignalNotArrayUnPack(Com_SignalIdType SourceSignalId)
{
    const Com_GwSourceSignalType* gwSourceSignalPtr = &Com_ConfigStd->ComSourceSignal[SourceSignalId];
    uint64 signalValue;
    uint16 ipduBufferIndex = Com_ConfigStd->ComRxIPdu[gwSourceSignalPtr->ComGwIPduRef].ComRxIPduBufIndex;

    signalValue = Com_SignalUnPackHandle(
        gwSourceSignalPtr->ComSignalEndianness,
        gwSourceSignalPtr->ComSignalByteLength,
        &Com_RxIPduRuntimeBuff[ipduBufferIndex],
        gwSourceSignalPtr->ComBitPosition,
        gwSourceSignalPtr->ComBitSize,
        gwSourceSignalPtr->ComSignalType);
    return signalValue;
}
#endif /* #if ((0u < COM_GW_SOURCE_DESCRIPTION_NUMBER) && (0u < COM_RXIPDUBUFF_SIZE)) */
/******************************************************************************/
/*
 * Brief               called by Com_RxSignalHandle,Com_InvalidSignalReplaceAndNotification,
 *                     Com_RxSignalGroupFilter.
 *                     calculate the rx signal value is filter out or not.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      Value,ComFilter,SignalBufferId,SignalType
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              boolean
 */
/******************************************************************************/
#if ((0u < COM_RXSIGNAL_NUMBER) || (0u < COM_RXGROUPSIGNAL_NUMBER)) \
    && ((STD_ON == COM_RX_SIGNAL_FILTER_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_FILTER_ENABLE))
static FUNC(boolean, COM_CODE) Com_RxSignalFilter(
    uint64 Value,
    P2CONST(Com_FilterType, AUTOMATIC, COM_APPL_CONST) ComFilter,
#if (COM_RXSIGNALMASKNEWDIFFERMASKOLD_NUMBER > 0u)
    uint16 SignalBufferId,
#endif
    Com_SignalType SignalType)
{
    boolean ret = TRUE;
    Com_FilterAlgorithmType filterType;
#if (COM_ONEEVERYNFILTERSIGNAL_NUMBER > 0u)
    Com_SignalIdType oneEveryNId;
    uint32 filterOffset;
    uint32 filterPeriod;
#endif
#if (COM_RXSIGNALMASKNEWDIFFERMASKOLD_NUMBER > 0u)
    Com_SignalIdType maskNewDifferMaskOldId;
#endif
    if (NULL_PTR != ComFilter)
    {
        ret = FALSE;
        filterType = ComFilter->ComFilterAlgorithm;
        switch (filterType)
        {
        case COM_ALWAYS:
            ret = TRUE;
            break;
        case COM_MASKED_NEW_EQUALS_X:
            if (((Value) & (ComFilter->ComFilterMask)) == (ComFilter->ComFilterX))
            {
                ret = TRUE;
            }
            break;
        case COM_MASKED_NEW_DIFFERS_X:
            if (((Value) & (ComFilter->ComFilterMask)) != (ComFilter->ComFilterX))
            {
                ret = TRUE;
            }
            break;
        /*COM_BOOLEAN not support WITHIN and WITHOUT*/
        case COM_NEW_IS_WITHIN:
            Com_NewIsWithinFilterCalculate(SignalType, Value, ComFilter, &ret);
            break;
        /*COM_BOOLEAN not support WITHIN and OUTSIDE*/
        case COM_NEW_IS_OUTSIDE:
            Com_NewIsWithoutFilterCalculate(SignalType, Value, ComFilter, &ret);
            break;
#if (COM_ONEEVERYNFILTERSIGNAL_NUMBER > 0u)
        case COM_ONE_EVERY_N:
            filterOffset = ComFilter->ComFilterOffset;
            filterPeriod = ComFilter->ComFilterPeriod;
            oneEveryNId = ComFilter->ComOneEveryNId;
            if (filterPeriod == Com_OneEveryNcnt[oneEveryNId])
            {
                Com_OneEveryNcnt[oneEveryNId] = 0u;
            }
            if (filterOffset == Com_OneEveryNcnt[oneEveryNId])
            {
                ret = TRUE;
            }
            Com_OneEveryNcnt[oneEveryNId]++;
            break;
#endif
#if (COM_RXSIGNALMASKNEWDIFFERMASKOLD_NUMBER > 0u)
        case COM_MASKED_NEW_DIFFERS_MASKED_OLD:
            maskNewDifferMaskOldId = ComFilter->ComMaskNewDifferMaskOldId;
            if (TRUE == Com_MaskNewDifferMaskOldTimeOut[maskNewDifferMaskOldId])
            {
                ret = TRUE;
                Com_MaskNewDifferMaskOldTimeOut[maskNewDifferMaskOldId] = FALSE;
            }
            else
            {
                ret = Com_MaskedNewDiffersMaskedOldFilterCalculate(SignalType, Value, ComFilter, SignalBufferId);
            }
            break;
#endif
        default:
            /*do nothing*/
            break;
        }
    }
    return ret;
}
#endif /* #if ((0u < COM_RXSIGNAL_NUMBER) || (0u < COM_RXGROUPSIGNAL_NUMBER)) && ((STD_ON == \
          COM_RX_SIGNAL_FILTER_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_FILTER_ENABLE)) */

#if ((0u < COM_RXSIGNALGROUP_NUMBER) && (0u < COM_RXGROUPSIGNAL_NUMBER))
/******************************************************************************/
/*
 * Brief               called by Com_SignalGroupInvalidCalculate.
 *                     Uint8_Dyn Group Signal Invalid Calculate.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      RxDynSignalLength,groupSignalId,IpduBufferId
 * Param-Name[out]     None
 * Param-Name[in/out]  signalGroupInvalid
 * Return              None
 */
/******************************************************************************/
#if (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE) && (STD_ON == COM_RX_GRP_SIGNAL_INVALID_DATA_ENABLE)
static FUNC(void, COM_CODE) Com_Uint8DynGroupSignalInvalidCalculate(
    uint16 RxDynSignalLength,
    Com_SignalIdType groupSignalId,
    uint16 IpduBufferId,
    boolean* signalGroupInvalid)
{
    const Com_RxGroupSignalType* rxGroupSignalPtr = &Com_ConfigStd->ComRxGroupSignal[groupSignalId];
#if (((0u < COM_SIGNAL_8BIT_INVALID_SIZE) || (0u < COM_GWSIGNAL_8BITBUFF_SIZE)) && (0u < COM_RXIPDUBUFF_SIZE))
    uint16 counter;
    uint32 bitPosition = rxGroupSignalPtr->ComBitPosition;
#endif
    boolean invalidValue = TRUE;
    uint16 invalidValueId = rxGroupSignalPtr->ComSignalDataInvalidValueId;
    uint16 ipduBufferPos = IpduBufferId + (uint16)(bitPosition >> 3u);

    /*the group signal need gateway,store group signal value in gateway buffer*/
#if (STD_ON == COM_SIGNAL_GW_ENABLE)
    uint16 gwSignalBufferId = rxGroupSignalPtr->GWSignalBufferId;
    if (COM_UNUSED_UINT16 != gwSignalBufferId)
    {
#if ((0u < COM_GWSIGNAL_8BITBUFF_SIZE) && (0u < COM_RXIPDUBUFF_SIZE))
        for (counter = 0u; counter < RxDynSignalLength; counter++)
        {
            Com_GWSignal8BitBuff[gwSignalBufferId + counter] = Com_RxIPduRuntimeBuff[ipduBufferPos + counter];
        }
#endif
    }
#endif /* #if (STD_ON == COM_SIGNAL_GW_ENABLE) */

    if ((COM_UNUSED_UINT16 != invalidValueId) && (FALSE == *signalGroupInvalid))
    {
        if (RxDynSignalLength != rxGroupSignalPtr->ComSignalDataInvalidValueLength)
        {
            invalidValue = FALSE;
        }
        else
        {
#if ((0u < COM_SIGNAL_8BIT_INVALID_SIZE) && (0u < COM_RXIPDUBUFF_SIZE))
            for (counter = 0u; (counter < RxDynSignalLength) && (TRUE == invalidValue); counter++)
            {
                if (Com_Signal8BitInvalidValue[invalidValueId + counter]
                    != Com_RxIPduRuntimeBuff[ipduBufferPos + counter])
                {
                    invalidValue = FALSE;
                }
            }
#endif
        }
        if (TRUE == invalidValue)
        {
            *signalGroupInvalid = TRUE;
        }
    }
    return;
}
#endif /* #if (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE) && (STD_ON == COM_RX_GRP_SIGNAL_INVALID_DATA_ENABLE) \
        */
/******************************************************************************/
/*
 * Brief               called by Com_SignalGroupRxIndication.
 *                     Signal Group Invalid Calculate.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      RxSignalGroupId,groupSignalNumber,IpduBufferId,RxDynSignalLength
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              boolean
 */
/******************************************************************************/
#if (STD_ON == COM_RX_GRP_SIGNAL_INVALID_DATA_ENABLE)
static FUNC(boolean, COM_CODE) Com_SignalGroupInvalidCalculate(
    Com_SignalGroupIdType RxSignalGroupId,
    Com_SignalIdType groupSignalNumber,
    uint16 IpduBufferId,
    uint16 RxDynSignalLength)
{
    boolean signalGroupInvalid = FALSE;
    Com_SignalIdType cnt, groupSignalId;
    boolean invalidValue;
    uint16 invalidValueId;
#if (((0u < COM_SIGNAL_8BIT_INVALID_SIZE) || (0u < COM_GWSIGNAL_8BITBUFF_SIZE)) && (0u < COM_RXIPDUBUFF_SIZE))
    uint32 bitPosition;
    uint16 counter;
    uint16 ipduBufferPos;
#endif
    uint16 gwSignalBufferId;
#if ((0u < COM_RXIPDUBUFF_SIZE) && ((0u < COM_SIGNAL_8BIT_INVALID_SIZE) || (0u < COM_GWSIGNAL_8BITBUFF_SIZE)))
    uint16 signal8NLength;
#endif
    uint64 unPackValue;
    Com_SignalType signalType;
    Com_RxGroupSignalType* rxGroupSignalPtr;

    for (cnt = 0u; cnt < groupSignalNumber; cnt++)
    {
        invalidValue = TRUE;
        groupSignalId = Com_ConfigStd->ComRxSignalGroup[RxSignalGroupId].ComRxGroupSignalId[cnt];
#if (((0u < COM_SIGNAL_8BIT_INVALID_SIZE) || (0u < COM_GWSIGNAL_8BITBUFF_SIZE)) && (0u < COM_RXIPDUBUFF_SIZE))
        bitPosition = rxGroupSignalPtr->ComBitPosition;
        ipduBufferPos = IpduBufferId + (uint16)(bitPosition >> 3u);
#endif
        invalidValueId = rxGroupSignalPtr->ComSignalDataInvalidValueId;
        gwSignalBufferId = rxGroupSignalPtr->GWSignalBufferId;
        signalType = rxGroupSignalPtr->ComSignalType;
#if (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_N_ENABLE)
        if (COM_UINT8_N == signalType)
        {
#if ((0u < COM_RXIPDUBUFF_SIZE) && ((0u < COM_SIGNAL_8BIT_INVALID_SIZE) || (0u < COM_GWSIGNAL_8BITBUFF_SIZE)))
            signal8NLength = rxGroupSignalPtr->ComSignalLength;
#endif
#if ((0u < COM_GWSIGNAL_8BITBUFF_SIZE) && (0u < COM_RXIPDUBUFF_SIZE))
            /*the group signal need gateway,store group signal value in gateway buffer*/
            if (COM_UNUSED_UINT16 != gwSignalBufferId)
            {
                for (counter = 0u; counter < signal8NLength; counter++)
                {
                    Com_GWSignal8BitBuff[gwSignalBufferId + counter] = Com_RxIPduRuntimeBuff[ipduBufferPos + counter];
                }
            }
#endif
#if ((0u < COM_SIGNAL_8BIT_INVALID_SIZE) && (0u < COM_RXIPDUBUFF_SIZE))
            if ((COM_UNUSED_UINT16 != invalidValueId) && (FALSE == signalGroupInvalid))
            {
                for (counter = 0u; (counter < signal8NLength) && (TRUE == invalidValue); counter++)
                {
                    if (Com_Signal8BitInvalidValue[invalidValueId + counter]
                        != Com_RxIPduRuntimeBuff[ipduBufferPos + counter])
                    {
                        invalidValue = FALSE;
                    }
                }
                if (TRUE == invalidValue)
                {
                    signalGroupInvalid = TRUE;
                }
            }
#endif
        }
        else
#endif /* #if (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_N_ENABLE) */
#if (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE)
            if (COM_UINT8_DYN == signalType)
        {
            Com_Uint8DynGroupSignalInvalidCalculate(
                RxDynSignalLength,
                groupSignalId,
                IpduBufferId,
                &signalGroupInvalid);
        }
        else
#endif /* #if (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE) */
        {
            unPackValue = Com_RxGroupSignalUnPack(groupSignalId, IpduBufferId);
#if (STD_ON == COM_SIGNAL_GW_ENABLE)
            Com_UpdateGWSignalBuffer(unPackValue, gwSignalBufferId, signalType);
#endif /* (STD_ON == COM_SIGNAL_GW_ENABLE) */
            if ((COM_UNUSED_UINT16 != invalidValueId) && (FALSE == signalGroupInvalid))
            {
#if (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ENABLE)
                invalidValue = Com_SignalInvalidateHandle(signalType, invalidValueId, unPackValue);
                if (TRUE == invalidValue)
                {
                    signalGroupInvalid = TRUE;
                }
#endif /* (STD_ON == COM_RX_SIGNAL_INVALID_DATA_ENABLE) */
            }
        }
    }
    return signalGroupInvalid;
}
#endif /* #if (STD_ON == COM_RX_GRP_SIGNAL_INVALID_DATA_ENABLE) */
#endif

#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#endif /*0u < COM_RXIPDU_NUMBER*/
