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
#include "UDS.h"

/****************************************************************
         UDS:ReadDataByPeriodicIdentifier  (2A hex) service
 ***************************************************************/
#if (STD_ON == DCM_UDS_SERVICE0X2A_ENABLED)
typedef struct
{
    P2VAR(uint8, AUTOMATIC, DCM_APPL_CONST) DidSupportNum; /* PRQA S 3432 */        /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, DCM_APPL_CONST) DidSessionSupportNum; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
} Dcm_0x2ATypes;

#define DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"
static VAR(SchedulerQueueTypes, DCM_VAR_NOINIT) SchedulerQueue[DCM_DSP_MAX_PERIODIC_DID_SCHEDULER];
#define DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"

#if (STD_ON == DCM_UDS_SERVICE0X2A_ENABLED)
#define DCM_START_SEC_VAR_POWER_ON_INIT_16
#include "Dcm_MemMap.h"
static VAR(uint16, DCM_VAR_POWER_ON_INIT) SchedulerNum = 0U;
#define DCM_STOP_SEC_VAR_POWER_ON_INIT_16
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_POWER_ON_INIT_16
#include "Dcm_MemMap.h"
static VAR(uint16, DCM_VAR_POWER_ON_INIT) SchedulerIndex = 0U;
#define DCM_STOP_SEC_VAR_POWER_ON_INIT_16
#include "Dcm_MemMap.h"
#endif

#define DCM_START_SEC_VAR_POWER_ON_INIT_16
#include "Dcm_MemMap.h"
static VAR(uint16, DCM_VAR_POWER_ON_INIT) SchedulerPengingDid = 0u;
#define DCM_STOP_SEC_VAR_POWER_ON_INIT_16
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_POWER_ON_INIT_8 /* PRQA S 0791 */ /* MISRA Rule 5.4 */
#include "Dcm_MemMap.h"
static VAR(boolean, DCM_VAR_POWER_ON_INIT) SchedulerPengingDDDid = FALSE;
#define DCM_STOP_SEC_VAR_POWER_ON_INIT_8 /* PRQA S 0791 */ /* MISRA Rule 5.4 */
#include "Dcm_MemMap.h"

typedef struct
{
    uint16 Did;
    uint16 Length;
    boolean DDDid;
} DidRxQueueTypes;

#if (DCM_DSP_MAX_PERIODIC_DID_TO_READ != 0xFFFFu)
#define DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"
static VAR(DidRxQueueTypes, DCM_VAR_NOINIT) DidRxQueue[DCM_DSP_MAX_PERIODIC_DID_TO_READ];
#define DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"
#endif

#if (DCM_DSP_DDDID_MAX_NUMBER > 0u)
/*************************************************************************/
/*
 * Brief               <UDS  0x2A service DDDid Read Data Did>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) DspInternalUDS0x2A_DDDid_Read_Data_Did(
    Dcm_OpStatusType OpStatus,
    P2CONST(Dcm_DDDidElementsDataTypes, TYPEDEF, DCM_CONST) DDDid,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) Data) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    uint8 DidSignalIndex;
    uint8 DidSignalNum;
    P2CONST(Dcm_DspDataType, TYPEDEF, DCM_CONST) pDspDidData;
    Std_ReturnType ret = E_OK;
    uint8 NewData[DCM_TEMP_BUFFER_LENGTH] = {0};
    uint16 Did;
    uint8 Pos;
    uint8 Index;
    uint16 pDidCfgIndex;
    uint16 DidSignalPos = 0;
    uint16 Size = 0;
    Dcm_NegativeResponseCodeType ErrorCode;

    Did = (uint16)(DDDid->Data & 0xFFFFUL);
    Pos = (uint8)((DDDid->Data & 0xFF0000UL) >> 16u);
    for (Index = 0; (Index < Dcm_DspCfg.DcmDspDidNum) && (ret == E_OK); Index++)
    {
        /*single did check*/
        if ((Did == Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidId) && (TRUE == Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidUsed))
        {
            pDidCfgIndex = Index;
            break;
        }
    }

    DidSignalNum = Dcm_DspCfg.pDcmDspDid[pDidCfgIndex].DcmDspDidSignalNum;
    for (DidSignalIndex = 0; (DidSignalIndex < DidSignalNum) && (ret == E_OK); DidSignalIndex++)
    {
        pDspDidData = Dcm_DspCfg.pDcmDspDid[pDidCfgIndex].pDcmDspDidSignal[DidSignalIndex].pDcmDspDidData;
        if (DCM_UINT8_DYN == pDspDidData->DcmDspDataType)
        {
            /*DidDataSize is dynamic*/
            if (NULL_PTR == pDspDidData->DcmDspDataReadDataLengthFnc)
            {
                ret = E_NOT_OK;
            }
            else
            {
                ret = pDspDidData->DcmDspDataReadDataLengthFnc(OpStatus, &Size);
            }
        }
        else
        {
            /*DidDataSize is fixed*/
            Size = ((pDspDidData->DcmDspDataSize + 7u) >> 3u);
        }
        if (E_OK == ret)
        {
            DidSignalPos +=
                ((Dcm_DspCfg.pDcmDspDid[pDidCfgIndex].pDcmDspDidSignal[DidSignalIndex].DcmDspDidDataPos + 7u) >> 3u);
            if ((NULL_PTR == pDspDidData->DcmDspDataReadFnc) || (Size > DCM_TEMP_BUFFER_LENGTH))
            {
                ret = E_NOT_OK;
            }
            else
            {
                ret = pDspDidData->DcmDspDataReadFnc(OpStatus, &NewData[DidSignalPos], &ErrorCode);
            }
            DidSignalPos += Size;
        }
    }
    Dcm_MemoryCopy(&(NewData[Pos]), Data, DDDid->Size);
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

#if (DCM_DSP_DDDID_MAX_NUMBER > 0u)
/*************************************************************************/
/*
 * Brief               <UDS  0x2A service DDDid Read Data Did>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE)
    DspInternalUDS0x2A_DDDid_Read_Data(Dcm_OpStatusType OpStatus, uint16 SchedulerQueueIndex)
{
    Std_ReturnType ret = E_OK;
    P2VAR(Dcm_DDDidElementsDataTypes, TYPEDEF, DCM_CONST) DDDid; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    uint8 DDDidNum;
    uint8 iloop;
    uint8 DDDidIndex;
    uint8 IdInfoIndex;
    uint8 RangeInfoIndex;
    P2CONST(Dcm_DspReadMemoryRangeInfoType, AUTOMATIC, DCM_VAR_NOINIT)
    pDcmDspReadMemoryRangeInfo;
    P2CONST(Dcm_DspMemoryIdInfoType, AUTOMATIC, DCM_VAR_NOINIT)
    pDcmDspMemoryIdInfo;
    uint8 MemoryIdentifier;
    boolean Find = FALSE;
    Dcm_NegativeResponseCodeType ErrorCode;
    uint16 RecDid = SchedulerQueue[SchedulerQueueIndex].Did;
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) Data; /* PRQA S 3432 */ /* MISRA Rule 20.7 */

    for (iloop = 0; (iloop < DCM_DSP_DDDID_MAX_NUMBER) && (Find == FALSE); iloop++)
    {
        if (RecDid == Dcm_DDDid[iloop].DDDid)
        {
            Find = TRUE;
            DDDidIndex = iloop;
        }
    }
    if (Find == TRUE)
    {
        SchedulerQueue[SchedulerQueueIndex].Length = 0;
        DDDidNum = Dcm_DDDid[DDDidIndex].DDDIDNumOfElements;
        for (iloop = 0; iloop < DDDidNum; iloop++)
        {
            DDDid = &Dcm_DDDid[DDDidIndex].DcmDspAlternativeArgumentData[iloop];
            Data = &(SchedulerQueue[SchedulerQueueIndex].Data[SchedulerQueue[SchedulerQueueIndex].Length + 1u]);
            if (DDDid->Subfunction == DCM_UDS0X2C_01_DDBYDID)
            {
                ret = DspInternalUDS0x2A_DDDid_Read_Data_Did(OpStatus, DDDid, Data);
            }
            else if (DDDid->Subfunction == DCM_UDS0X2C_02_DDBYMEMORY)
            {
                for (IdInfoIndex = 0u; IdInfoIndex < Dcm_DspCfg.pDcmDspMemory->DcmDspMemoryIdInfoNum; IdInfoIndex++)
                {
                    pDcmDspMemoryIdInfo = &(Dcm_DspCfg.pDcmDspMemory->DcmDspMemoryIdInfo[IdInfoIndex]);
                    if (pDcmDspMemoryIdInfo != NULL_PTR)
                    {
                        for (RangeInfoIndex = 0; RangeInfoIndex < pDcmDspMemoryIdInfo->DcmDspReadMemoryRangeInfoNum;
                             RangeInfoIndex++)
                        {
                            pDcmDspReadMemoryRangeInfo =
                                &(pDcmDspMemoryIdInfo->DcmDspReadMemoryRangeInfo[RangeInfoIndex]);
                            if ((pDcmDspReadMemoryRangeInfo != NULL_PTR)
                                && ((pDcmDspReadMemoryRangeInfo->DcmDspReadMemoryRangeLow <= DDDid->Data)
                                    && (pDcmDspReadMemoryRangeInfo->DcmDspReadMemoryRangeHigh
                                        >= (DDDid->Data + DDDid->Size - 1u))))
                            {
                                MemoryIdentifier =
                                    Dcm_DspCfg.pDcmDspMemory->DcmDspMemoryIdInfo[IdInfoIndex].DcmDspMemoryIdValue;
                            }
                        }
                    }
                }
                ret = Dcm_ReadMemory(OpStatus, MemoryIdentifier, DDDid->Data, (uint32)DDDid->Size, Data, &ErrorCode);
                if (DCM_READ_FAILED == ret)
                {
                    ret = E_NOT_OK;
                }
                else if ((DCM_READ_FORCE_RCRRP == ret) || (DCM_READ_PENDING == ret))
                {
                    ret = DCM_E_PENDING;
                }
                else
                {
                    /*idle*/
                }
            }
            else
            {
                ret = E_NOT_OK;
            }
            SchedulerQueue[SchedulerQueueIndex].Length += DDDid->Size;
        }
    }
    else
    {
        ret = E_NOT_OK;
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif
/*************************************************************************/
/*
 * Brief               <UDS  0x2A service DDDid Read Data Did>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) DspInternalUDS0x2A_Did_Read_Data(uint16 SchedulerQueueIndex)
{
    uint16 DidSignalPos = 0;
    uint8 DidSignalIndex;
    uint8 DidSignalNum;
    P2CONST(Dcm_DspDataType, TYPEDEF, DCM_CONST) pDspDidData;
    Std_ReturnType ret = E_NOT_OK;
    uint16 Size;
    uint8 Index;
    boolean Flag = FALSE;
    uint16 DidCfgIndex = 0;
    Dcm_NegativeResponseCodeType ErrorCode;
    uint16 RecDid = SchedulerQueue[SchedulerQueueIndex].Did;
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) Data = &(SchedulerQueue[SchedulerQueueIndex].Data[1]);
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */

    for (Index = 0; (Index < Dcm_DspCfg.DcmDspDidNum) && (FALSE == Flag); Index++)
    {
        /*single did check*/
        if ((RecDid == Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidId)
            && (TRUE == Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidUsed))
        {
            Flag = TRUE;
            DidCfgIndex = Index;
            ret = E_OK;
        }
    }

    if (ret == E_OK)
    {
        SchedulerQueue[SchedulerQueueIndex].Length = 0;
        DidSignalNum = Dcm_DspCfg.pDcmDspDid[DidCfgIndex].DcmDspDidSignalNum;
        for (DidSignalIndex = 0; DidSignalIndex < DidSignalNum; DidSignalIndex++)
        {
            pDspDidData = Dcm_DspCfg.pDcmDspDid[DidCfgIndex].pDcmDspDidSignal[DidSignalIndex].pDcmDspDidData;
            Size = 0;
            if (DCM_UINT8_DYN == pDspDidData->DcmDspDataType)
            {
                /*DidDataSize is dynamic*/
                if (NULL_PTR == pDspDidData->DcmDspDataReadDataLengthFnc)
                {
                    ret = E_NOT_OK;
                }
                else
                {
                    ret = pDspDidData->DcmDspDataReadDataLengthFnc(DCM_INITIAL, &Size);
                }
            }
            else
            {
                /*DidDataSize is fixed*/
                Size = ((pDspDidData->DcmDspDataSize + 7u) >> 3u);
            }
            if (E_OK == ret)
            {
                DidSignalPos +=
                    ((Dcm_DspCfg.pDcmDspDid[DidCfgIndex].pDcmDspDidSignal[DidSignalIndex].DcmDspDidDataPos + 7u) >> 3u);
                if ((NULL_PTR == pDspDidData->DcmDspDataReadFnc) || (Size > DCM_TEMP_BUFFER_LENGTH))
                {
                    ret = E_NOT_OK;
                }
                else
                {
                    ret = pDspDidData->DcmDspDataReadFnc(DCM_INITIAL, &Data[DidSignalPos], &ErrorCode);
                }
                /*ResOffset equal to last position add last size of the signal of did*/
                DidSignalPos += Size;
                SchedulerQueue[SchedulerQueueIndex].Length += Size;
            }
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*************************************************************************/
/*
 * Brief               <UDS  0x2A service Init>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(void, DCM_CODE) Dcm_Scheduler_0x2A_Init(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    uint16 Index;
    for (Index = 0; Index < DCM_DSP_MAX_PERIODIC_DID_SCHEDULER; Index++)
    {
        SchedulerQueue[Index].Did = 0;
        SchedulerQueue[Index].Counter = 0;
        SchedulerQueue[Index].SubFunction = 0;
        SchedulerQueue[Index].Length = 0;
        SchedulerQueue[Index].ProtocolCtrlId = 0xFF;
        SchedulerQueue[Index].Data[0] = 0;
        SchedulerQueue[Index].Data[1] = 0;
        SchedulerQueue[Index].Data[2] = 0;
        SchedulerQueue[Index].Data[3] = 0;
        SchedulerQueue[Index].Data[4] = 0;
        SchedulerQueue[Index].Data[5] = 0;
        SchedulerQueue[Index].Data[6] = 0;
        SchedulerQueue[Index].Data[7] = 0;
        SchedulerQueue[Index].DDDid = FALSE;
    }
    for (Index = 0; Index < DCM_PERIODICCONNECTION_NUM; Index++)
    {
        Scheduler_0x2A_Transmit[Index].PduId = 0xFF;
        Scheduler_0x2A_Transmit[Index].Transmit = FALSE;
    }
}
/**********************************************************************/
/*
 * Brief
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/***********************************************************************/
static FUNC(boolean, DCM_CODE) Dcm_MainFunction_0x2A_SubDeal(
    uint16 iloop,
    uint16 index,
    P2CONST(Dcm_DslMainConnectionType, TYPEDEF, DCM_CONST) pDcmDslMainConnection)
{
    boolean Find = FALSE;
    uint16 cnt;
    PduInfoType PduInfo;
    Std_ReturnType ret;
    PduIdType TxPduID;
    Std_ReturnType result;
#if (STD_ON == DCM_GENERIC_CONNECTION)
    uint8 metadata[5];
#endif

    if (SchedulerQueue[iloop].Counter == 0u)
    {
        if (SchedulerQueue[iloop].DDDid == TRUE)
        {
#if (DCM_DSP_DDDID_MAX_NUMBER > 0u)
            ret = DspInternalUDS0x2A_DDDid_Read_Data(DCM_INITIAL, iloop);
#endif
        }
        else
        {
            ret = DspInternalUDS0x2A_Did_Read_Data(iloop);
        }
        if (ret == E_OK)
        {
            SchedulerQueue[iloop].Data[0] = (uint8)(SchedulerQueue[iloop].Did);
            PduInfo.SduDataPtr = &(SchedulerQueue[iloop].Data[0]);
            PduInfo.SduLength = SchedulerQueue[iloop].Length + 1u;
            TxPduID = pDcmDslMainConnection->pDcmDslPeriodicTranmissionConRef->DcmDslPeriodicConnection[index]
                          .DcmDslTxPduRPduId;
#if (STD_ON == DCM_GENERIC_CONNECTION)
            if ((pDcmDslMainConnection->pDcmDslPeriodicTranmissionConRef->DcmDslPeriodicConnection[index]
                     .DcmDslMetaDataFlag
                 & DCM_METADATA_LENGTH_MASK)
                > 0u)
            {
                PduInfo.MetaDataPtr = metadata;
#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
                metadata[0u] = (uint8)((SchedulerQueue[iloop].TA & 0xFF00u) >> 8u);
                metadata[1u] = (uint8)(SchedulerQueue[iloop].TA & 0xFFu);
                metadata[2u] = (uint8)((SchedulerQueue[iloop].SA & 0xFF00u) >> 8u);
                metadata[3u] = (uint8)(SchedulerQueue[iloop].SA & 0xFFu);
#else
                metadata[0u] = (uint8)(SchedulerQueue[iloop].TA & 0xFFu);
                metadata[1u] = (uint8)((SchedulerQueue[iloop].TA & 0xFF00u) >> 8u);
                metadata[2u] = (uint8)(SchedulerQueue[iloop].SA & 0xFFu);
                metadata[3u] = (uint8)((SchedulerQueue[iloop].SA & 0xFF00u) >> 8u);
#endif
            }
#else
            PduInfo.MetaDataPtr = NULL_PTR;
#endif
            for (cnt = 0u; cnt < DCM_PERIODICCONNECTION_NUM; cnt++)
            {
                if (Scheduler_0x2A_Transmit[cnt].PduId
                    == pDcmDslMainConnection->pDcmDslPeriodicTranmissionConRef->DcmDslPeriodicConnection[index]
                           .DcmDslPeriodicTxConfirmationPduId)
                {
                    Scheduler_0x2A_Transmit[cnt].Transmit = TRUE;
                }
            }
            result = PduR_DcmTransmit(TxPduID, &PduInfo);
            if (result != E_OK)
            {
                for (cnt = 0; cnt < DCM_PERIODICCONNECTION_NUM; cnt++)
                {
                    if (Scheduler_0x2A_Transmit[cnt].PduId
                        == pDcmDslMainConnection->pDcmDslPeriodicTranmissionConRef->DcmDslPeriodicConnection[index]
                               .DcmDslPeriodicTxConfirmationPduId)
                    {
                        Scheduler_0x2A_Transmit[cnt].Transmit = FALSE;
                    }
                }
            }
            switch (SchedulerQueue[iloop].SubFunction)
            {
            case DCM_UDS0X2A_01_SLOW:
                SchedulerQueue[iloop].Counter =
                    (uint8)(Dcm_DspCfg.Dcm_DspPeriodicTransmission->DcmDspPeriodicTransmissionSlowRate
                            / Dcm_GeneralCfg.DcmTaskTime);
                break;
            case DCM_UDS0X2A_02_MEDIUM:
                SchedulerQueue[iloop].Counter =
                    (uint8)(Dcm_DspCfg.Dcm_DspPeriodicTransmission->DcmDspPeriodicTransmissionMediumRate
                            / Dcm_GeneralCfg.DcmTaskTime);
                break;
            case DCM_UDS0X2A_03_FAST:
                SchedulerQueue[iloop].Counter =
                    (uint8)(Dcm_DspCfg.Dcm_DspPeriodicTransmission->DcmDspPeriodicTransmissionFastRate
                            / Dcm_GeneralCfg.DcmTaskTime);
                break;
            default:
                /*idle*/
                break;
            }
            Find = TRUE;
            SchedulerIndex = iloop;
            SchedulerPengingDid = 0;
            SchedulerPengingDDDid = FALSE;
        }
        else if (ret == E_NOT_OK)
        {
            SchedulerIndex = iloop;
            SchedulerPengingDDDid = FALSE;
            SchedulerPengingDid = 0;
        }
        else if (ret == DCM_E_PENDING)
        {
            SchedulerPengingDid = SchedulerQueue[iloop].Did;
            SchedulerPengingDDDid = SchedulerQueue[iloop].DDDid;
            Find = TRUE;
        }
        else
        {
            /*idle*/
        }
    }
    return Find;
}

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
/**********************************************************************/
/*
 * Brief
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/***********************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(void, DCM_CODE) Dcm_MainFunction_Scheduler_0x2A(uint8 ProtocolCtrlId) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    boolean Find;
    boolean ProcessContinue = TRUE;
    uint16 iloop;
    uint16 index;
    uint16 cnt;
    P2CONST(Dcm_DslMainConnectionType, TYPEDEF, DCM_CONST) pDcmDslMainConnection;

    for (iloop = 0u; iloop < SchedulerNum; iloop++)
    {
        if ((SchedulerQueue[iloop].Counter != 0u) && (ProtocolCtrlId == SchedulerQueue[iloop].ProtocolCtrlId))
        {
            SchedulerQueue[iloop].Counter--;
        }
    }
    if ((SchedulerNum == 0U) && (SchedulerPengingDid != 0u) && (SchedulerPengingDDDid == TRUE))
    {
#if (DCM_DSP_DDDID_MAX_NUMBER > 0u)
        (void)DspInternalUDS0x2A_DDDid_Read_Data(DCM_CANCEL, iloop);
#endif
        SchedulerPengingDid = 0;
        SchedulerPengingDDDid = FALSE;
    }
    pDcmDslMainConnection =
        Dcm_DslCfg.pDcmDslProtocol->pDcmDslProtocolRow[ProtocolCtrlId].pDcmDslConnection->pDcmDslMainConnection;
    if ((pDcmDslMainConnection == NULL_PTR) || (pDcmDslMainConnection->pDcmDslPeriodicTranmissionConRef == NULL_PTR))
    {
        ProcessContinue = FALSE;
    }
    if (ProcessContinue == TRUE)
    {
        for (index = 0u; index < DCM_MAINCONNECTION_NUM; index++)
        {
            if ((Dcm_CommCtrl[index].DcmDslProtocolComMChannelId == pDcmDslMainConnection->DcmDslProtocolComMChannelId)
                && (Dcm_CommCtrl[index].Dcm_CommState != DCM_COMM_FULL_COMMUNICATION))
            {
                ProcessContinue = FALSE;
            }
        }
    }
    if (ProcessContinue == TRUE)
    {
        for (index = 0; index < pDcmDslMainConnection->pDcmDslPeriodicTranmissionConRef->DcmPeriodicTxPduIdNum; index++)
        {
            for (cnt = 0u; cnt < DCM_PERIODICCONNECTION_NUM; cnt++)
            {
                if ((Scheduler_0x2A_Transmit[cnt].PduId
                     == pDcmDslMainConnection->pDcmDslPeriodicTranmissionConRef->DcmDslPeriodicConnection[index]
                            .DcmDslPeriodicTxConfirmationPduId)
                    && (Scheduler_0x2A_Transmit[cnt].Transmit == TRUE))
                {
                    ProcessContinue = FALSE;
                }
            }
            if (ProcessContinue == TRUE)
            {
                Find = FALSE;
                for (iloop = SchedulerIndex; (iloop < SchedulerNum) && (Find == FALSE); iloop++)
                {
                    Find = Dcm_MainFunction_0x2A_SubDeal(iloop, index, pDcmDslMainConnection);
                }
                if (SchedulerIndex >= (SchedulerNum - 1u))
                {
                    SchedulerIndex = 0u;
                }
            }
        }
    }
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/**********************************************************************/
/*
 * Brief
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/***********************************************************************/
/***************************/
#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static Std_ReturnType DspInternalUDS0x2A_DidCheck(
    uint16 RecDid,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) pDidCfgIndex
#if (DCM_DSP_DDDID_MAX_NUMBER > 0u)
    ,
    P2VAR(boolean, AUTOMATIC, AUTOMATIC) DDDid,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) DDDidIndex
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
#endif
)
{
    uint8 Index;
#if (DCM_DSP_DDDID_MAX_NUMBER > 0u)
    uint8 iloop;
#endif
    Std_ReturnType ret = E_NOT_OK;

    if ((RecDid >= 0xF200u) && (RecDid <= 0xF2FFu))
    {
        /*find the corresponding DID in configuration*/
        for (Index = 0; (Index < Dcm_DspCfg.DcmDspDidNum) && (E_NOT_OK == ret); Index++)
        {
            /*single did check*/
            if ((RecDid == Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidId)
                && (TRUE == Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidUsed))
            {
                if ((Dcm_DspCfg.pDcmDspDidInfo[Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidInfoIndex]
                         .DcmDspDidDynamicallyDefined
                     == TRUE)
                    && (Dcm_DspCfg.pDcmDspDidInfo[Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidInfoIndex]
                            .DcmDspDDDIDMaxElements
                        > 0u))
                {

#if (DCM_DSP_DDDID_MAX_NUMBER > 0u)
                    for (iloop = 0; (iloop < DCM_DSP_DDDID_MAX_NUMBER) && (E_NOT_OK == ret); iloop++)
                    {
                        if (RecDid == Dcm_DDDid[iloop].DDDid)
                        {
                            *DDDid = TRUE;
                            *DDDidIndex = iloop;
                            *pDidCfgIndex = Index;
                            ret = E_OK;
                        }
                    }
#endif
                }
                else
                {
                    *pDidCfgIndex = Index;
                    ret = E_OK;
                }
            }
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

/**********************************************************************/
/*
 * Brief
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/***********************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(void, DCM_CODE) DspInternalUDS0x2A_Clear_SchedulerQueue(uint16 Index)
{
    SchedulerQueue[Index].Did = 0;
    SchedulerQueue[Index].Counter = 0;
    SchedulerQueue[Index].SubFunction = 0;
    SchedulerQueue[Index].Length = 0;
    SchedulerQueue[Index].ProtocolCtrlId = 0xFF;
    SchedulerQueue[Index].Data[0] = 0;
    SchedulerQueue[Index].Data[1] = 0;
    SchedulerQueue[Index].Data[2] = 0;
    SchedulerQueue[Index].Data[3] = 0;
    SchedulerQueue[Index].Data[4] = 0;
    SchedulerQueue[Index].Data[5] = 0;
    SchedulerQueue[Index].Data[6] = 0;
    SchedulerQueue[Index].Data[7] = 0;
    SchedulerQueue[Index].DDDid = FALSE;
#if (STD_ON == DCM_GENERIC_CONNECTION)
    SchedulerQueue[Index].TA = 0;
    SchedulerQueue[Index].SA = 0;
#endif
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/**********************************************************************/
/*
 * Brief
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/***********************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(void, DCM_CODE) DspInternalUDS0x2A_Move_SchedulerQueue(uint16 Index)
{
    uint16 Cnt;
    for (Cnt = Index; (Cnt < (SchedulerNum - 1u)) && (SchedulerNum <= DCM_DSP_MAX_PERIODIC_DID_SCHEDULER); Cnt++)
    {
        SchedulerQueue[Cnt].Did = SchedulerQueue[Cnt + 1u].Did;
        SchedulerQueue[Cnt].Counter = SchedulerQueue[Cnt + 1u].Counter;
        SchedulerQueue[Cnt].SubFunction = SchedulerQueue[Cnt + 1u].SubFunction;
        SchedulerQueue[Cnt].Length = SchedulerQueue[Cnt + 1u].Length;
        SchedulerQueue[Cnt].ProtocolCtrlId = SchedulerQueue[Cnt + 1u].ProtocolCtrlId;
        SchedulerQueue[Cnt].DDDid = SchedulerQueue[Cnt + 1u].DDDid;
#if (STD_ON == DCM_GENERIC_CONNECTION)
        SchedulerQueue[Cnt].TA = SchedulerQueue[Cnt + 1u].TA;
        SchedulerQueue[Cnt].SA = SchedulerQueue[Cnt + 1u].SA;
#endif
    }
    DspInternalUDS0x2A_Clear_SchedulerQueue(Cnt);
    if (SchedulerIndex >= Index)
    {
        SchedulerIndex--;
    }
    SchedulerNum -= 1u;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/**********************************************************************/
/*
 * Brief
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/***********************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(void, DCM_CODE) Dcm_UDS0x2ACheckNewSecurity(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    boolean SecSupport;
    boolean DDDidSupport = TRUE;
    uint16 Index;
    uint16 iloop;
    uint8 DidInfoCfgIndex;
    uint8 Idx;
    P2CONST(Dcm_DspDidReadType, AUTOMATIC, DCM_APPL_CONST) pDspDidRead;
#if ((STD_ON == DCM_UDS_SERVICE0X2C_ENABLED) && (DCM_DSP_DDDID_MAX_NUMBER > 0u))
    Dcm_NegativeResponseCodeType ErrorCode;
    Std_ReturnType ret;
#endif

    for (Index = 0; Index < SchedulerNum; Index++)
    {
        SecSupport = FALSE;
        for (iloop = 0; iloop < Dcm_DspCfg.DcmDspDidNum; iloop++)
        {
            if ((SchedulerQueue[Index].Did == Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidId)
                && (TRUE == Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidUsed))
            {
                DidInfoCfgIndex = Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidInfoIndex;
                pDspDidRead = Dcm_DspCfg.pDcmDspDidInfo[DidInfoCfgIndex].pDcmDspDidRead;
                if (NULL_PTR != pDspDidRead)
                {
                    if (pDspDidRead->DcmDspDidReadSecurityLevelRefNum != 0u)
                    {
                        for (Idx = 0; (Idx < pDspDidRead->DcmDspDidReadSecurityLevelRefNum) && (FALSE == SecSupport);
                             Idx++)
                        {
                            if (Dcm_MkCtrl.Dcm_ActiveSec == pDspDidRead->pDcmDspDidReadSecurityLevelRow[Idx])
                            {
                                SecSupport = TRUE;
                            }
                        }
                    }
                    else
                    {
                        SecSupport = TRUE;
                    }
#if ((STD_ON == DCM_UDS_SERVICE0X2C_ENABLED) && (DCM_DSP_DDDID_MAX_NUMBER > 0u))
                    if ((SchedulerQueue[Index].DDDid == TRUE) && (Dcm_DspCfg.DcmDspDDDIDcheckPerSourceDID != NULL_PTR)
                        && (TRUE == (*(Dcm_DspCfg.DcmDspDDDIDcheckPerSourceDID))))
                    {
                        for (Idx = 0; (Idx < DCM_DSP_DDDID_MAX_NUMBER); Idx++)
                        {
                            ret = DsdInternal_DDDIDcheckPerSourceDID(Idx, &ErrorCode);
                            if ((SchedulerQueue[Index].Did == Dcm_DDDid[Idx].DDDid) && (E_NOT_OK == ret))
                            {
                                DDDidSupport = FALSE;
                            }
                        }
                    }
#endif
                }
            }
        }

        if ((SecSupport == FALSE) || (DDDidSupport == FALSE))
        {
            DspInternalUDS0x2A_Clear_SchedulerQueue(Index);
            DspInternalUDS0x2A_Move_SchedulerQueue(Index);
            Index--; /* PRQA S 2469 */ /* MISRA Rule 14.2 */
        }
    }
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/**********************************************************************/
/*
 * Brief
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/***********************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(void, DCM_CODE) Dcm_UDS0x2ACheckNewSession_SubDeal(
    uint16 Index,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(boolean, AUTOMATIC, DCM_VAR) SesSupport,
    P2VAR(boolean, AUTOMATIC, DCM_VAR) SecSupport
#if ((STD_ON == DCM_UDS_SERVICE0X2C_ENABLED) && (DCM_DSP_DDDID_MAX_NUMBER > 0u))
    ,
    P2VAR(boolean, AUTOMATIC, DCM_VAR) DDDidSupport
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
#endif
)
{
    uint8 DidInfoCfgIndex;
    uint8 Idx;
    P2CONST(Dcm_DspDidReadType, AUTOMATIC, DCM_APPL_CONST) pDspDidRead;
#if ((STD_ON == DCM_UDS_SERVICE0X2C_ENABLED) && (DCM_DSP_DDDID_MAX_NUMBER > 0u))
    Dcm_NegativeResponseCodeType ErrorCode;
    Std_ReturnType ret;
#endif

    DidInfoCfgIndex = Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidInfoIndex;
    pDspDidRead = Dcm_DspCfg.pDcmDspDidInfo[DidInfoCfgIndex].pDcmDspDidRead;
    if ((SchedulerQueue[Index].Did == Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidId)
        && (TRUE == Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidUsed) && (NULL_PTR != pDspDidRead))
    {
        if (pDspDidRead->DcmDspDidReadSessionRefNum != 0u)
        {
            for (Idx = 0; (Idx < (pDspDidRead->DcmDspDidReadSessionRefNum)) && (FALSE == *SesSupport); Idx++)
            {
                if (Dcm_MkCtrl.Dcm_ActiveSes == pDspDidRead->pDcmDspDidReadSessionRow[Idx])
                {
                    *SesSupport = TRUE;
                }
            }
        }
        else
        {
            *SesSupport = TRUE;
        }
        if (pDspDidRead->DcmDspDidReadSecurityLevelRefNum != 0u)
        {
            for (Idx = 0; (Idx < pDspDidRead->DcmDspDidReadSecurityLevelRefNum) && (FALSE == *SecSupport); Idx++)
            {
                if (Dcm_MkCtrl.Dcm_ActiveSec == pDspDidRead->pDcmDspDidReadSecurityLevelRow[Idx])
                {
                    *SecSupport = TRUE;
                }
            }
        }
        else
        {
            *SecSupport = TRUE;
        }
#if ((STD_ON == DCM_UDS_SERVICE0X2C_ENABLED) && (DCM_DSP_DDDID_MAX_NUMBER > 0u))
        if ((SchedulerQueue[Index].DDDid == TRUE) && (Dcm_DspCfg.DcmDspDDDIDcheckPerSourceDID != NULL_PTR)
            && (TRUE == (*(Dcm_DspCfg.DcmDspDDDIDcheckPerSourceDID))))
        {
            for (Idx = 0; (Idx < DCM_DSP_DDDID_MAX_NUMBER); Idx++)
            {
                ret = DsdInternal_DDDIDcheckPerSourceDID(Idx, &ErrorCode);
                if ((SchedulerQueue[Index].Did == Dcm_DDDid[Idx].DDDid) && (E_NOT_OK == ret))
                {
                    *DDDidSupport = FALSE;
                }
            }
        }
#endif
    }
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/**********************************************************************/
/*
 * Brief
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/***********************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(void, DCM_CODE) Dcm_UDS0x2ACheckNewSession(Dcm_SesCtrlType NewSes) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    boolean SesSupport;
    boolean SecSupport;
    boolean DDDidSupport = TRUE;
    uint16 Index;
    uint16 iloop;

    if (DCM_DEFAULT_SESSION == NewSes)
    {
        for (Index = 0; Index < SchedulerNum; Index++)
        {
            if ((SchedulerPengingDid == SchedulerQueue[Index].Did) && (SchedulerPengingDDDid == TRUE))
            {
#if (DCM_DSP_DDDID_MAX_NUMBER > 0u)
                (void)DspInternalUDS0x2A_DDDid_Read_Data(DCM_CANCEL, Index);
#endif
                SchedulerPengingDid = 0;
                SchedulerPengingDDDid = FALSE;
            }
            DspInternalUDS0x2A_Clear_SchedulerQueue(Index);
        }
    }
    else
    {
        for (Index = 0; Index < SchedulerNum; Index++)
        {
            SesSupport = FALSE;
            SecSupport = FALSE;
            for (iloop = 0; iloop < Dcm_DspCfg.DcmDspDidNum; iloop++)
            {
                Dcm_UDS0x2ACheckNewSession_SubDeal(
                    Index,
                    &SesSupport,
                    &SecSupport
#if ((STD_ON == DCM_UDS_SERVICE0X2C_ENABLED) && (DCM_DSP_DDDID_MAX_NUMBER > 0u))
                    ,
                    &DDDidSupport
#endif
                );
            }

            if ((SesSupport == FALSE) || (SecSupport == FALSE) || (DDDidSupport == FALSE))
            {
                if ((SchedulerPengingDid == SchedulerQueue[Index].Did) && (SchedulerPengingDDDid == TRUE))
                {
#if (DCM_DSP_DDDID_MAX_NUMBER > 0u)
                    (void)DspInternalUDS0x2A_DDDid_Read_Data(DCM_CANCEL, iloop);
#endif
                    SchedulerPengingDid = 0;
                    SchedulerPengingDDDid = FALSE;
                }
                DspInternalUDS0x2A_Clear_SchedulerQueue(Index);
                DspInternalUDS0x2A_Move_SchedulerQueue(Index);
                Index--; /* PRQA S 2469 */ /* MISRA Rule 14.2 */
            }
        }
    }
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/**********************************************************************/
/*
 * Brief
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/***********************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x2A_SubFunSubDeal(
    Dcm_OpStatusType OpStatus,
    uint8 DidSupportNum,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    Std_ReturnType ret = E_OK;
    P2CONST(Dcm_DspDataType, TYPEDEF, DCM_CONST) pDspDidData;
    uint8 DidCfgIndex = 0;
    uint8 index;
    uint16 Size = 0;

    /*call the ConditionCheckRead function*/
    for (index = 0; index < Dcm_DspCfg.pDcmDspDid[DidCfgIndex].DcmDspDidSignalNum; index++)
    {
        pDspDidData = Dcm_DspCfg.pDcmDspDid[DidCfgIndex].pDcmDspDidSignal[index].pDcmDspDidData;
        if ((pDspDidData->DcmConditionCheckReadFncUsed == TRUE)
            && (pDspDidData->DcmDspDataConditionCheckReadFnc != NULL_PTR))
        {
            ret = pDspDidData->DcmDspDataConditionCheckReadFnc(OpStatus, ErrorCode);
        }
        if (E_OK == ret)
        {
            if (pDspDidData->DcmDspDataType == DCM_UINT8_DYN)
            {
                /*DidDataSize is dynamic*/
                if (NULL_PTR == pDspDidData->DcmDspDataReadDataLengthFnc)
                {
                    /*DcmDspDidReadDataLengthFnc is NULL,send NRC 0x22*/
                    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                    ret = E_NOT_OK;
                }
                else
                {
                    ret = pDspDidData->DcmDspDataReadDataLengthFnc(OpStatus, &Size);
                }
                DidRxQueue[DidSupportNum].Length += Size;
            }
            else
            {
                DidRxQueue[DidSupportNum].Length = ((pDspDidData->DcmDspDataSize + 7u) >> 3u);
            }
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/**********************************************************************/
/*
 * Brief
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/***********************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x2A_SubFunDeal_0x01_0x03(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    Dcm_0x2ATypes* Dcm_0x2AType,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    Std_ReturnType ret = E_OK;
    uint8 MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    uint8 iloop;
    uint8 index;
    uint8 cnt;
    uint8 DidNum = (uint8)(Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen - 2u);
    uint16 RecDid;
    boolean Find;
    uint8 DidInfoCfgIndex;
    boolean DDDid = FALSE;
    uint8 DDDidIndex = 0;
    uint8 DidCfgIndex = 0;

    for (iloop = 0; iloop < DidNum; iloop++)
    {
        /*get the required DID from request message*/
        RecDid = (uint16)((uint16)(0xF2u) << 8u) | ((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2u + iloop]);
        /*Repetition of the same periodicDataIdentifier in a single request message is not
         * allowed and the server shall ignore them all except one periodicDataIdentifer if
         * the client breaks this rule.*/
        Find = FALSE;
        for (index = 0; (index < DCM_DSP_MAX_PERIODIC_DID_TO_READ) && (Find == FALSE); index++)
        {
            if (DidRxQueue[index].Did == RecDid)
            {
                Find = TRUE;
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                ret = E_NOT_OK;
            }
        }
        /* PRQA S 3415++ */ /* MISRA Rule 13.5 */
        if ((Find == FALSE)
            && (E_OK
                == DspInternalUDS0x2A_DidCheck(
                    RecDid,
                    &DidCfgIndex
#if (DCM_DSP_DDDID_MAX_NUMBER > 0u)
                    ,
                    &DDDid,
                    &DDDidIndex
#endif
                    )))
        /* PRQA S 3415-- */ /* MISRA Rule 13.5 */
        {
            DidInfoCfgIndex = Dcm_DspCfg.pDcmDspDid[DidCfgIndex].DcmDspDidInfoIndex;
            if (Dcm_DspCfg.pDcmDspDidInfo[DidInfoCfgIndex].pDcmDspDidRead != NULL_PTR)
            {
#if ((STD_ON == DCM_SESSION_FUNC_ENABLED) && (STD_ON == DCM_DSP_DID_FUNC_ENABLED))
                ret = DsdInternal_DidSessionCheck(DidInfoCfgIndex, ErrorCode);
#endif
                if (E_OK == ret)
                {
                    (*Dcm_0x2AType->DidSessionSupportNum)++;
                    /*check the current security level*/
#if ((STD_ON == DCM_SECURITY_FUNC_ENABLED) && (STD_ON == DCM_DSP_DID_FUNC_ENABLED))
                    ret = DsdInternal_DidSecurityCheck(DidInfoCfgIndex, ErrorCode);
#endif
                    if (E_OK == ret)
                    {
#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED) && (STD_ON == DCM_UDS_SERVICE0X2C_ENABLED)
                        if ((DDDid == TRUE) && (*(Dcm_DspCfg.DcmDspDDDIDcheckPerSourceDID) == TRUE))
                        {
                            ret = DsdInternal_DDDIDcheckPerSourceDID(DDDidIndex, ErrorCode);
                        }
                        if ((DDDid == TRUE) && (E_OK == ret))
                        {
                            for (cnt = 0; cnt < Dcm_DDDid[DDDidIndex].DDDIDNumOfElements; cnt++)
                            {
                                DidRxQueue[*Dcm_0x2AType->DidSupportNum].Length +=
                                    Dcm_DDDid[DDDidIndex].DcmDspAlternativeArgumentData[cnt].Size;
                            }
                            DidRxQueue[*Dcm_0x2AType->DidSupportNum].DDDid = TRUE;
                        }
                        else
#endif
                            if (DDDid == FALSE)
                        {
                            ret = Dcm_UDS0x2A_SubFunSubDeal(OpStatus, *Dcm_0x2AType->DidSupportNum, ErrorCode);
                        }
                        else
                        {
                            /*idle*/
                        }
                        if (DidRxQueue[*Dcm_0x2AType->DidSupportNum].Length > 7u)
                        {
                            /*can only transfer IF PDU*/
                            DidRxQueue[*Dcm_0x2AType->DidSupportNum].Length = 0;
                            DidRxQueue[*Dcm_0x2AType->DidSupportNum].DDDid = FALSE;
                        }
                        else
                        {
                            DidRxQueue[*Dcm_0x2AType->DidSupportNum].Did = RecDid;
                            (*Dcm_0x2AType->DidSupportNum) += 1u;
                        }
                    }
                }
            }
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/**********************************************************************/
/*
 * Brief
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/***********************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x2A_SubFunDeal(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, DCM_APPL_CONST) DidSupportNum,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    Std_ReturnType ret = E_OK;
    uint8 DidSessionSupportNum = 0;
    uint8 DidInfoCfgIndex;
    uint8 MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    uint8 Subfunction = Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[1u];
    uint8 iloop;
    uint8 DidNum = (uint8)(Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen - 2u);
    uint16 RecDid;
    uint8 index;
    Dcm_0x2ATypes Dcm_0x2AType;
#if (DCM_DSP_DDDID_MAX_NUMBER > 0u)
    boolean DDDid = FALSE;
    uint8 DDDidIndex = 0;
#endif
    uint8 DidCfgIndex = 0;

    switch (Subfunction)
    {
    case DCM_UDS0X2A_01_SLOW:
    case DCM_UDS0X2A_02_MEDIUM:
    case DCM_UDS0X2A_03_FAST:
        Dcm_0x2AType.DidSupportNum = DidSupportNum;
        Dcm_0x2AType.DidSessionSupportNum = &DidSessionSupportNum;
        ret = Dcm_UDS0x2A_SubFunDeal_0x01_0x03(OpStatus, ProtocolCtrlId, &Dcm_0x2AType, ErrorCode);
        break;
    case DCM_UDS0X2A_04_STOP:
        if (DidNum == 0u)
        {
            for (iloop = 0; iloop < DCM_DSP_MAX_PERIODIC_DID_SCHEDULER; iloop++)
            {
                DspInternalUDS0x2A_Clear_SchedulerQueue(iloop);
            }
            SchedulerNum = 0;
            SchedulerIndex = 0;
            DidSessionSupportNum++;
        }
        else
        {
            for (iloop = 0; iloop < DidNum; iloop++)
            {
                RecDid = (uint16)(((uint16)0xF2) << 8u) | (Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2u + iloop]);
                if (E_OK
                    == DspInternalUDS0x2A_DidCheck(
                        RecDid,
                        &DidCfgIndex
#if (DCM_DSP_DDDID_MAX_NUMBER > 0u)
                        ,
                        &DDDid,
                        &DDDidIndex
#endif
                        ))
                {
                    DidInfoCfgIndex = Dcm_DspCfg.pDcmDspDid[DidCfgIndex].DcmDspDidInfoIndex;
#if ((STD_ON == DCM_SESSION_FUNC_ENABLED) && (STD_ON == DCM_DSP_DID_FUNC_ENABLED))
                    ret = DsdInternal_DidSessionCheck(DidInfoCfgIndex, ErrorCode);
#endif
                    if (E_OK == ret)
                    {
                        for (index = 0; index < SchedulerNum; index++)
                        {
                            if (SchedulerQueue[index].Did == RecDid)
                            {
                                DspInternalUDS0x2A_Move_SchedulerQueue(index);
                                DidSessionSupportNum++;
                            }
                        }
                    }
                }
            }
        }
        break;
    default:
        /*idle*/
        break;
    }

    if (DidSessionSupportNum == 0u)
    {
        /*at least one DID is supported in the active session,not then send NRC 0x31*/
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        ret = E_NOT_OK;
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/**********************************************************************/
/*
 * Brief
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/***********************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dcm_Uds0x2AServiceConditionCheck(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, DCM_APPL_CONST) DidSupportNum,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
/* PRQA S 3432-- */                              /* MISRA Rule 20.7 */
{
    Std_ReturnType ret = E_OK; /* PRQA S 2981 */ /* MISRA Rule 2.2 */
#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
    uint8 iloop;
#endif
    uint8 MsgCtrlId;
    uint8 Subfunction;
    /*if the required protocol is configured,get the index of runtime datum*/
    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    Subfunction = Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[1u];

#if (STD_ON == DCM_SESSION_FUNC_ENABLED)
    /*session check,check whether the current session supports the request service*/
    ret = DsdInternal_SesCheck(ProtocolCtrlId, SID_READ_DATA_BY_PERIODIC_IDENTIFER);
    if (E_NOT_OK == ret)
    {
        /*the current session does not support the request service,send NRC = 0x7F*/
        *ErrorCode = DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION;
    }
#endif
#if (STD_ON == DCM_SECURITY_FUNC_ENABLED)
    if (E_OK == ret)
    {
        /*security check,check whether the current security supports the request service*/
        ret = DsdInternal_SecurityCheck(ProtocolCtrlId, SID_READ_DATA_BY_PERIODIC_IDENTIFER);
        if (E_NOT_OK == ret)
        {
            *ErrorCode = DCM_E_SECURITYACCESSDENIED; /*NRC = 0x33*/
        }
    }
#endif
    if ((E_OK == ret)
        && ((Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen < DCM_UDS0X2A_SUBFUNC0X04_REQ_DATA_MINLENGTH)
            || ((Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen < DCM_UDS0X2A_REQ_DATA_MINLENGTH)
                && ((DCM_UDS0X2A_01_SLOW == Subfunction) || (DCM_UDS0X2A_02_MEDIUM == Subfunction)
                    || (DCM_UDS0X2A_03_FAST == Subfunction)))
            || ((uint32)((uint32)Dcm_DspCfg.DcmDspMaxPeriodicDidToRead + 2u)
                < Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen)))
    {
        /*check the massage length*/
        /*the length of massage is not correct,send NRC 0x13*/
        *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        ret = E_NOT_OK;
    }
    if (E_OK == ret)
	{
		ret = RTE_PreConditonCheck(Dcm_MsgCtrl[MsgCtrlId].SID,Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData);
		if (E_OK != ret)
		{
			*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
			ret = E_NOT_OK;
		}
	}
    if ((E_OK == ret) && ((Subfunction < DCM_UDS0X2A_01_SLOW) || (Subfunction > DCM_UDS0X2A_04_STOP)))
    {
        /*check transmissionMode*/
        /*if transmissionMode not supported,send NRC 0x31*/
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        ret = E_NOT_OK;
    }
#if (STD_OFF == DCM_DSP_DID_FUNC_ENABLED)
    if (E_OK == ret)
    { /*NRC 0x31:request out of range*/
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        ret = E_NOT_OK;
    }

#else
    if (E_OK == ret)
    {
        for (iloop = 0; iloop < DCM_DSP_MAX_PERIODIC_DID_TO_READ; iloop++)
        {
            DidRxQueue[iloop].Did = 0;
            DidRxQueue[iloop].Length = 0;
            DidRxQueue[iloop].DDDid = FALSE;
        }
        ret = Dcm_UDS0x2A_SubFunDeal(OpStatus, ProtocolCtrlId, DidSupportNum, ErrorCode);
    }
#endif
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/**********************************************************************/
/*
 * Brief
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/***********************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(Std_ReturnType, DCM_CODE)
/* PRQA S 1532,3432++ */ /* MISRA Rule 8.7,20.7 */
Dcm_UDS0x2A(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
/* PRQA S 1532,3432-- */ /* MISRA Rule 8.7,20.7 */
{
#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
    uint32 Offset;
    uint8 iloop;
    uint8 index;
    uint8 TxChannelCtrlIndex;
    uint8 TxChannelCfgIndex;
    uint8 DidSupportNum = 0;
    uint8 DidSupportNumStored = 0;
#endif
    uint8 MsgCtrlId;
    Std_ReturnType ret;
    uint8 Subfunction;
    boolean Find;
    static boolean SchedulerIndexChanged = FALSE;
    /*if the required protocol is configured,get the index of runtime datum*/
    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    Subfunction = Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[1u];
    TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex;
    TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;
    Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;

    ret = Dcm_Uds0x2AServiceConditionCheck(OpStatus, ProtocolCtrlId, &DidSupportNum, ErrorCode);
#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
    if ((E_OK == ret) && (DCM_UDS0X2A_04_STOP != Subfunction))
    {
        for (index = 0; index < DidSupportNum; index++)
        {
            Find = FALSE;
            for (iloop = 0; (iloop < DCM_DSP_MAX_PERIODIC_DID_SCHEDULER) && (Find == FALSE); iloop++)
            {
                if (SchedulerQueue[iloop].Did == DidRxQueue[index].Did)
                {
                    Find = TRUE;
                    DidSupportNumStored += 1u;
                }
            }
        }
        if (((uint16)SchedulerNum + (uint16)DidSupportNum - (uint16)DidSupportNumStored)
            > (uint16)DCM_DSP_MAX_PERIODIC_DID_SCHEDULER)
        {
            /*scheduler free to store all supported pDIDs requested,not then send NRC 0x31*/
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            ret = E_NOT_OK;
        }
        for (index = 0; (index < DidSupportNum) && (E_OK == ret); index++)
        {
            Find = FALSE;
            for (iloop = 0; (iloop < DCM_DSP_MAX_PERIODIC_DID_SCHEDULER) && (Find == FALSE); iloop++)
            {
                if (SchedulerQueue[iloop].Did == DidRxQueue[index].Did)
                {
                    Find = TRUE;
                    SchedulerQueue[iloop].SubFunction = Subfunction;
                    SchedulerQueue[iloop].Length = DidRxQueue[index].Length + 1u;
                    switch (Subfunction)
                    {
                    case DCM_UDS0X2A_01_SLOW:
                        SchedulerQueue[iloop].Counter =
                            (uint8)(Dcm_DspCfg.Dcm_DspPeriodicTransmission->DcmDspPeriodicTransmissionSlowRate
                                    / Dcm_GeneralCfg.DcmTaskTime);
                        break;
                    case DCM_UDS0X2A_02_MEDIUM:
                        SchedulerQueue[iloop].Counter =
                            (uint8)(Dcm_DspCfg.Dcm_DspPeriodicTransmission->DcmDspPeriodicTransmissionMediumRate
                                    / Dcm_GeneralCfg.DcmTaskTime);
                        break;
                    case DCM_UDS0X2A_03_FAST:
                        SchedulerQueue[iloop].Counter =
                            (uint8)(Dcm_DspCfg.Dcm_DspPeriodicTransmission->DcmDspPeriodicTransmissionFastRate
                                    / Dcm_GeneralCfg.DcmTaskTime);
                        break;
                    default:
                        /*idle*/
                        break;
                    }
                    SchedulerQueue[iloop].ProtocolCtrlId = ProtocolCtrlId;
                    SchedulerQueue[iloop].DDDid = DidRxQueue[index].DDDid;
                }
            }
            if (Find == FALSE)
            {
                for (iloop = 0; (iloop < DCM_DSP_MAX_PERIODIC_DID_SCHEDULER) && (Find == FALSE); iloop++)
                {
                    if (SchedulerQueue[iloop].Did == 0u)
                    {
                        Find = TRUE;
                        SchedulerQueue[iloop].Did = DidRxQueue[index].Did;
                        SchedulerQueue[iloop].SubFunction = Subfunction;
                        SchedulerQueue[iloop].Length = DidRxQueue[index].Length + 1u;
                        switch (Subfunction)
                        {
                        case DCM_UDS0X2A_01_SLOW:
                            SchedulerQueue[iloop].Counter =
                                (uint8)(Dcm_DspCfg.Dcm_DspPeriodicTransmission->DcmDspPeriodicTransmissionSlowRate
                                        / Dcm_GeneralCfg.DcmTaskTime);
                            break;
                        case DCM_UDS0X2A_02_MEDIUM:
                            SchedulerQueue[iloop].Counter =
                                (uint8)(Dcm_DspCfg.Dcm_DspPeriodicTransmission->DcmDspPeriodicTransmissionMediumRate
                                        / Dcm_GeneralCfg.DcmTaskTime);
                            break;
                        case DCM_UDS0X2A_03_FAST:
                            SchedulerQueue[iloop].Counter =
                                (uint8)(Dcm_DspCfg.Dcm_DspPeriodicTransmission->DcmDspPeriodicTransmissionFastRate
                                        / Dcm_GeneralCfg.DcmTaskTime);
                            break;
                        default:
                            /*idle*/
                            break;
                        }
                        SchedulerQueue[iloop].ProtocolCtrlId = ProtocolCtrlId;
                        SchedulerQueue[iloop].DDDid = DidRxQueue[index].DDDid;
#if (STD_ON == DCM_GENERIC_CONNECTION)
                        SchedulerQueue[iloop].TA = Dcm_MsgCtrl[MsgCtrlId].Dcm_MetaData_TA;
                        SchedulerQueue[iloop].SA = Dcm_MsgCtrl[MsgCtrlId].Dcm_MetaData_SA;
#endif
                        if (SchedulerIndexChanged == FALSE)
                        {
                            SchedulerIndexChanged = TRUE;
                            SchedulerIndex = iloop;
                        }
                        SchedulerNum += 1u;
                    }
                }
            }
        }
    }
    if ((E_OK == ret) && ((1u) > (Dcm_DslCfg.pDcmChannelCfg[TxChannelCfgIndex].Dcm_DslBufferSize)))
    {
        /*assemble and send positive response*/
        /* check tx data length */
        /*Pdu length is bigger than buffer size,ignore the request message */
        *ErrorCode = DCM_E_RESPONSETOOLONG;
        ret = E_NOT_OK;
    }
    if (E_OK == ret)
    {
        SchedulerIndexChanged = FALSE;
        SchM_Enter_Dcm(Dcm_Channel);
        Dcm_Channel[Offset] = 0x6A;
        SchM_Exit_Dcm(Dcm_Channel);
        SchM_Enter_Dcm(Dcm_MsgCtrl);
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResMaxDataLen = 1u;
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResDataLen = 1u;
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.pResData = &Dcm_Channel[Offset];
        SchM_Exit_Dcm(Dcm_MsgCtrl);
        DsdInternal_ProcessingDone(ProtocolCtrlId);
    }
#endif
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif
