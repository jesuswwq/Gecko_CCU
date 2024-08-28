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
     UDS:InputOutputControlByIdentifier (2F hex) service
 ***************************************************************/
#if (STD_ON == DCM_UDS_SERVICE0X2F_ENABLED)
typedef struct
{
    uint32 Mask;
    uint16 InputDidSize;
    uint8 DidCfgIndex;
    P2CONST(Dcm_DspDidControlType, AUTOMATIC, DCM_APPL_CONST) pDspDidControl;
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) ControlStatusRecordSize; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    uint16 Offset;
    P2CONST(Dcm_DspDidSignalType, TYPEDEF, DCM_CONST) pDcmDspDidSignal;
    P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) pControlEnableMaskRecord; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) pControlStatusRecord; /* PRQA S 3432 */     /* MISRA Rule 20.7 */
    uint16 InputDataOffset;
} Dcm_0x2FTypes;

/********************************/
#if (DCM_DSP_DID_FOR_2F_NUM > 0)
#define DCM_START_SEC_VAR_POWER_ON_INIT_16
#include "Dcm_MemMap.h"
static VAR(uint16, DCM_VAR_POWER_ON_INIT) DcmOnControlDidfor2F[DCM_DSP_DID_FOR_2F_NUM] = {0};
#define DCM_STOP_SEC_VAR_POWER_ON_INIT_16
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
#if (DCM_DSP_DID_FOR_2F_NUM > 0)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(void, DCM_CODE) Dcm_UDS0x2FCheckNewSession(Dcm_SesCtrlType NewSes) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    boolean Support = FALSE;
    uint8 ProtocolCtrlIdIndex;
    uint8 SidTabId;
    uint8 Service_Num;
    uint16 SidTabIndex;
    uint16 ServiceIndex;
    uint8 SesIndex;
    uint8 iloop;
    uint16 DidIndex;
    uint8 SingalIndex;
    Dcm_NegativeResponseCodeType ErrorCode;

    for (ProtocolCtrlIdIndex = 0;
         (ProtocolCtrlIdIndex < Dcm_Cfg.pDcmDsdCfg->DcmDsdServiceTable_Num) && (FALSE == Support);
         ProtocolCtrlIdIndex++)
    {
        SidTabId = (Dcm_DslCfg.pDcmDslProtocol->pDcmDslProtocolRow)[ProtocolCtrlIdIndex].DcmDslServiceTableID;
        /*find SidTabId configuration position in the service configuration table*/
        for (SidTabIndex = 0; (SidTabIndex < Dcm_DsdCfg.DcmDsdServiceTable_Num) && (FALSE == Support); SidTabIndex++)
        {
            if (SidTabId == ((Dcm_DsdCfg.pDcmDsdServiceTable)[SidTabIndex].DcmDsdSidTabId))
            {
                Service_Num = (Dcm_DsdCfg.pDcmDsdServiceTable)[SidTabIndex].DcmDsdSidTab_ServiceNum;
                for (ServiceIndex = 0; (ServiceIndex < Service_Num) && (FALSE == Support); ServiceIndex++)
                {
                    if (0x2Fu
                        == ((Dcm_DsdCfg.pDcmDsdServiceTable)[SidTabIndex].pDcmDsdService[ServiceIndex].DcmDsdServiceId))
                    {
                        for (SesIndex = 0; (SesIndex < ((Dcm_DsdCfg.pDcmDsdServiceTable)[SidTabIndex]
                                                            .pDcmDsdService[ServiceIndex]
                                                            .DcmDsdSessionLevel_Num))
                                           && (Support == FALSE);
                             SesIndex++)
                        {
                            if (NewSes
                                == (Dcm_DsdCfg.pDcmDsdServiceTable)[SidTabIndex]
                                       .pDcmDsdService[ServiceIndex]
                                       .pDcmDsdSessionLevelRef[SesIndex])
                            {
                                Support = TRUE;
                            }
                        }
                    }
                }
            }
        }
    }

    if ((DCM_DEFAULT_SESSION == NewSes) || (Support == FALSE))
    {
        for (iloop = 0; iloop < DCM_DSP_DID_FOR_2F_NUM; iloop++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            if (DcmOnControlDidfor2F[iloop] != 0u)
            {
                for (DidIndex = 0; DidIndex < Dcm_DspCfg.DcmDspDidNum; DidIndex++)
                {
                    for (SingalIndex = 0;
                         (SingalIndex < Dcm_DspCfg.pDcmDspDid->DcmDspDidSignalNum)
                         && (DcmOnControlDidfor2F[iloop] == Dcm_DspCfg.pDcmDspDid[DidIndex].DcmDspDidId);
                         SingalIndex++)
                    {
                        if ((Dcm_DspCfg.pDcmDspDid[DidIndex]
                                 .pDcmDspDidSignal[SingalIndex]
                                 .pDcmDspDidData->DcmDspDataUsePort
                             == USE_ECU_SIGNAL)
                            && (Dcm_DspCfg.pDcmDspDid[DidIndex]
                                    .pDcmDspDidSignal[SingalIndex]
                                    .pDcmDspDidData->DcmDspDataEcuSignalFnc
                                != NULL_PTR))
                        {
                            Dcm_DspCfg.pDcmDspDid[DidIndex]
                                .pDcmDspDidSignal[SingalIndex]
                                .pDcmDspDidData->DcmDspDataEcuSignalFnc(DCM_UDS0X2F_RETURNCONTROLTOECU, 0xFF);
                        }
                        else if (
                            ((Dcm_DspCfg.pDcmDspDid[DidIndex]
                                  .pDcmDspDidSignal[SingalIndex]
                                  .pDcmDspDidData->DcmDspDataUsePort
                              == USE_DATA_SYNCH_FNC)
                             || (Dcm_DspCfg.pDcmDspDid[DidIndex]
                                     .pDcmDspDidSignal[SingalIndex]
                                     .pDcmDspDidData->DcmDspDataUsePort
                                 == USE_DATA_ASYNCH_FNC)
                             || (Dcm_DspCfg.pDcmDspDid[DidIndex]
                                     .pDcmDspDidSignal[SingalIndex]
                                     .pDcmDspDidData->DcmDspDataUsePort
                                 == USE_DATA_ASYNCH_FNC_ERROR)
                             || (Dcm_DspCfg.pDcmDspDid[DidIndex]
                                     .pDcmDspDidSignal[SingalIndex]
                                     .pDcmDspDidData->DcmDspDataUsePort
                                 == USE_DATA_SYNCH_CLIENT_SERVER)
                             || (Dcm_DspCfg.pDcmDspDid[DidIndex]
                                     .pDcmDspDidSignal[SingalIndex]
                                     .pDcmDspDidData->DcmDspDataUsePort
                                 == USE_DATA_ASYNCH_CLIENT_SERVER)
                             || (Dcm_DspCfg.pDcmDspDid[DidIndex]
                                     .pDcmDspDidSignal[SingalIndex]
                                     .pDcmDspDidData->DcmDspDataUsePort
                                 == USE_DATA_ASYNCH_CLIENT_SERVER_ERROR))
                            && (Dcm_DspCfg.pDcmDspDid[DidIndex]
                                    .pDcmDspDidSignal[SingalIndex]
                                    .pDcmDspDidData->DcmDspDataReturnControlToECUFnc
                                != NULL_PTR))
                        {
                            Dcm_DspCfg.pDcmDspDid[DidIndex]
                                .pDcmDspDidSignal[SingalIndex]
                                .pDcmDspDidData->DcmDspDataReturnControlToECUFnc(NULL_PTR, &ErrorCode);
                        }
                        else
                        {
                            /*idle*/
                        }
                    }
                }
                DcmOnControlDidfor2F[iloop] = 0;
            }
        }
    }
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
#if (DCM_DSP_DID_FOR_2F_NUM > 0)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(void, DCM_CODE) Dcm_UDS0x2FCheckNewSecurity(Dcm_SecLevelType NewSec) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    boolean Support = FALSE;
    uint8 ProtocolCtrlIdIndex;
    uint8 SidTabId;
    uint8 Service_Num;
    uint16 SidTabIndex;
    uint16 ServiceIndex;
    uint8 SesIndex;
    uint8 iloop;
    uint16 DidIndex;
    uint8 SingalIndex;
    Dcm_NegativeResponseCodeType ErrorCode;

    for (ProtocolCtrlIdIndex = 0;
         (ProtocolCtrlIdIndex < Dcm_Cfg.pDcmDsdCfg->DcmDsdServiceTable_Num) && (FALSE == Support);
         ProtocolCtrlIdIndex++)
    {
        SidTabId = (Dcm_DslCfg.pDcmDslProtocol->pDcmDslProtocolRow)[ProtocolCtrlIdIndex].DcmDslServiceTableID;
        /*find SidTabId configuration position in the service configuration table*/
        for (SidTabIndex = 0; (SidTabIndex < Dcm_DsdCfg.DcmDsdServiceTable_Num) && (FALSE == Support); SidTabIndex++)
        {
            if (SidTabId == ((Dcm_DsdCfg.pDcmDsdServiceTable)[SidTabIndex].DcmDsdSidTabId))
            {
                Service_Num = (Dcm_DsdCfg.pDcmDsdServiceTable)[SidTabIndex].DcmDsdSidTab_ServiceNum;
                for (ServiceIndex = 0; (ServiceIndex < Service_Num) && (FALSE == Support); ServiceIndex++)
                {
                    if (0x2Fu
                        == ((Dcm_DsdCfg.pDcmDsdServiceTable)[SidTabIndex].pDcmDsdService[ServiceIndex].DcmDsdServiceId))
                    {
                        for (SesIndex = 0; (SesIndex < ((Dcm_DsdCfg.pDcmDsdServiceTable)[SidTabIndex]
                                                            .pDcmDsdService[ServiceIndex]
                                                            .DcmDsdSecurityLevel_Num))
                                           && (Support == FALSE);
                             SesIndex++)
                        {
                            if (NewSec
                                == (Dcm_DsdCfg.pDcmDsdServiceTable)[SidTabIndex]
                                       .pDcmDsdService[ServiceIndex]
                                       .pDcmDsdSecurityLevelRef[SesIndex])
                            {
                                Support = TRUE;
                            }
                        }
                    }
                }
            }
        }
    }

    if (Support == FALSE)
    {
        for (iloop = 0; iloop < DCM_DSP_DID_FOR_2F_NUM; iloop++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            if (DcmOnControlDidfor2F[iloop] != 0u)
            {
                for (DidIndex = 0; DidIndex < Dcm_DspCfg.DcmDspDidNum; DidIndex++)
                {
                    for (SingalIndex = 0;
                         (SingalIndex < Dcm_DspCfg.pDcmDspDid->DcmDspDidSignalNum)
                         && (DcmOnControlDidfor2F[iloop] == Dcm_DspCfg.pDcmDspDid[DidIndex].DcmDspDidId);
                         SingalIndex++)
                    {
                        if ((Dcm_DspCfg.pDcmDspDid[DidIndex]
                                 .pDcmDspDidSignal[SingalIndex]
                                 .pDcmDspDidData->DcmDspDataUsePort
                             == USE_ECU_SIGNAL)
                            && (Dcm_DspCfg.pDcmDspDid[DidIndex]
                                    .pDcmDspDidSignal[SingalIndex]
                                    .pDcmDspDidData->DcmDspDataEcuSignalFnc
                                != NULL_PTR))
                        {
                            Dcm_DspCfg.pDcmDspDid[DidIndex]
                                .pDcmDspDidSignal[SingalIndex]
                                .pDcmDspDidData->DcmDspDataEcuSignalFnc(DCM_UDS0X2F_RETURNCONTROLTOECU, 0xFF);
                        }
                        else if (
                            ((Dcm_DspCfg.pDcmDspDid[DidIndex]
                                  .pDcmDspDidSignal[SingalIndex]
                                  .pDcmDspDidData->DcmDspDataUsePort
                              == USE_DATA_SYNCH_FNC)
                             || (Dcm_DspCfg.pDcmDspDid[DidIndex]
                                     .pDcmDspDidSignal[SingalIndex]
                                     .pDcmDspDidData->DcmDspDataUsePort
                                 == USE_DATA_ASYNCH_FNC)
                             || (Dcm_DspCfg.pDcmDspDid[DidIndex]
                                     .pDcmDspDidSignal[SingalIndex]
                                     .pDcmDspDidData->DcmDspDataUsePort
                                 == USE_DATA_ASYNCH_FNC_ERROR)
                             || (Dcm_DspCfg.pDcmDspDid[DidIndex]
                                     .pDcmDspDidSignal[SingalIndex]
                                     .pDcmDspDidData->DcmDspDataUsePort
                                 == USE_DATA_SYNCH_CLIENT_SERVER)
                             || (Dcm_DspCfg.pDcmDspDid[DidIndex]
                                     .pDcmDspDidSignal[SingalIndex]
                                     .pDcmDspDidData->DcmDspDataUsePort
                                 == USE_DATA_ASYNCH_CLIENT_SERVER)
                             || (Dcm_DspCfg.pDcmDspDid[DidIndex]
                                     .pDcmDspDidSignal[SingalIndex]
                                     .pDcmDspDidData->DcmDspDataUsePort
                                 == USE_DATA_ASYNCH_CLIENT_SERVER_ERROR))
                            && (Dcm_DspCfg.pDcmDspDid[DidIndex]
                                    .pDcmDspDidSignal[SingalIndex]
                                    .pDcmDspDidData->DcmDspDataReturnControlToECUFnc
                                != NULL_PTR))
                        {
                            Dcm_DspCfg.pDcmDspDid[DidIndex]
                                .pDcmDspDidSignal[SingalIndex]
                                .pDcmDspDidData->DcmDspDataReturnControlToECUFnc(NULL_PTR, &ErrorCode);
                        }
                        else
                        {
                            /*idle*/
                        }
                    }
                }
                DcmOnControlDidfor2F[iloop] = 0;
            }
        }
    }
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif
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
/********************************/
#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dcm_Uds0x2FServiceDidCallReadAPI(
    Dcm_OpStatusType OpStatus,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_0x2FTypes, AUTOMATIC, DCM_VAR) Dcm_0x2FType,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pNrc)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    Std_ReturnType ret = E_OK;
#if (STD_ON == DCM_SECURITY_FUNC_ENABLED)
    boolean Flag = FALSE;
    uint8 Index;
#endif /* (STD_ON == DCM_SECURITY_FUNC_ENABLED) */
#if (STD_ON == DCM_SECURITY_FUNC_ENABLED)
    /*check the current security level*/
    if (E_OK == ret)
    {
        Flag = FALSE;
        if (Dcm_0x2FType->pDspDidControl->DcmDspDidControlSecurityLevelRefNum != 0u)
        {
            for (Index = 0;
                 (Index < Dcm_0x2FType->pDspDidControl->DcmDspDidControlSecurityLevelRefNum) && (FALSE == Flag);
                 Index++)
            {
                if (Dcm_MkCtrl.Dcm_ActiveSec
                    == (Dcm_0x2FType->pDspDidControl->pDcmDspDidControlSecurityLevelRow)[Index])
                {
                    Flag = TRUE;
                }
            }
            if (FALSE == Flag)
            {
                /*if the processing is not supported in current security level,send NRC 0x33*/
                *pNrc = DCM_E_SECURITYACCESSDENIED;
                ret = E_NOT_OK;
            }
        }
    }
#endif /* STD_ON == DCM_SECURITY_FUNC_ENABLED */
    if (E_OK == ret)
    {
        if (NULL_PTR == Dcm_0x2FType->pDcmDspDidSignal->pDcmDspDidData->DcmDspDataReadFnc)
        {
            /*DcmDspDataReadFnc is NULL,send NRC 0x22*/
            *pNrc = DCM_E_CONDITIONSNOTCORRECT;
            ret = E_NOT_OK;
        }
        else
        {
            ret = Dcm_0x2FType->pDcmDspDidSignal->pDcmDspDidData->DcmDspDataReadFnc(
                OpStatus,
                Dcm_0x2FType->pControlStatusRecord,
                pNrc);
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
static FUNC(Std_ReturnType, DCM_CODE) Dcm_Uds0x2FServiceDidCallAPI_SubDeal(
    Dcm_OpStatusType OpStatus,
    Dcm_0x2FTypes* Dcm_0x2FType,
    uint8 MsgCtrlId,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    Std_ReturnType ret;
    P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) pControlOptionRecord = NULL_PTR; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    uint8 InputOutControlParameter = Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[3u];

    switch (InputOutControlParameter)
    {
    case DCM_UDS0X2F_RETURNCONTROLTOECU: /*ReturnControlToEcu*/
        if (Dcm_0x2FType->pDcmDspDidSignal->pDcmDspDidData->DcmDspDataReturnControlToECUFnc != NULL_PTR)
        {
            ret = Dcm_0x2FType->pDcmDspDidSignal->pDcmDspDidData->DcmDspDataReturnControlToECUFnc(
                Dcm_0x2FType->pControlEnableMaskRecord,
                ErrorCode);
            if (ret == E_OK)
            {
                ret = Dcm_Uds0x2FServiceDidCallReadAPI(OpStatus, Dcm_0x2FType, ErrorCode);
            }
        }
        else
        {
            ret = E_NOT_OK;
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE; /*NRC=0x31*/
        }
        break;
    case DCM_UDS0X2F_RESETTODEFAULT: /*ResetToDefault*/
        if ((Dcm_0x2FType->pDspDidControl->DcmDspDidResetToDefault == TRUE)
            && (Dcm_0x2FType->pDcmDspDidSignal->pDcmDspDidData->DcmDspDataResetToDefaultFnc != NULL_PTR))
        {
            ret = Dcm_0x2FType->pDcmDspDidSignal->pDcmDspDidData->DcmDspDataResetToDefaultFnc(
                OpStatus,
                Dcm_0x2FType->pControlEnableMaskRecord,
                ErrorCode);
            if (ret == E_OK)
            {
                ret = Dcm_Uds0x2FServiceDidCallReadAPI(OpStatus, Dcm_0x2FType, ErrorCode);
            }
        }
        else
        {
            ret = E_NOT_OK;
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE; /*NRC=0x31*/
        }
        break;
    case DCM_UDS0X2F_FREEZECURRENTSTATE: /*FreezeCurrentState*/
        if ((Dcm_0x2FType->pDspDidControl->DcmDspDidFreezeCurrentState == TRUE)
            && (Dcm_0x2FType->pDcmDspDidSignal->pDcmDspDidData->DcmDspDataFreezeCurrentStateFnc != NULL_PTR))
        {
            ret = Dcm_0x2FType->pDcmDspDidSignal->pDcmDspDidData->DcmDspDataFreezeCurrentStateFnc(
                OpStatus,
                Dcm_0x2FType->pControlEnableMaskRecord,
                ErrorCode);
            if (ret == E_OK)
            {
                ret = Dcm_Uds0x2FServiceDidCallReadAPI(OpStatus, Dcm_0x2FType, ErrorCode);
            }
        }
        else
        {
            ret = E_NOT_OK;
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE; /*NRC=0x31*/
        }
        break;
    case DCM_UDS0X2F_SHORTTERMADJUSTMENT: /*ShortTermAdjustment*/
        if (0u != Dcm_0x2FType->pDcmDspDidSignal->pDcmDspDidData->DcmDspDataSize)
        {
            pControlOptionRecord = &(Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[4u + Dcm_0x2FType->InputDataOffset]);
        }
        if ((Dcm_0x2FType->pDspDidControl->DcmDspDidShortTermAdjustement == TRUE)
            && (Dcm_0x2FType->pDcmDspDidSignal->pDcmDspDidData->DcmDspDataShortTermAdjustmentFnc != NULL_PTR))
        {
            ret = Dcm_0x2FType->pDcmDspDidSignal->pDcmDspDidData->DcmDspDataShortTermAdjustmentFnc(
                pControlOptionRecord,
                ((Dcm_0x2FType->pDcmDspDidSignal->pDcmDspDidData->DcmDspDataSize + 7u) >> 3u),
                OpStatus,
                Dcm_0x2FType->pControlEnableMaskRecord,
                ErrorCode);
            if (ret == E_OK)
            {
                ret = Dcm_Uds0x2FServiceDidCallReadAPI(OpStatus, Dcm_0x2FType, ErrorCode);
            }
        }
        else
        {
            ret = E_NOT_OK;
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE; /*NRC=0x31*/
        }
        break;
    default:
        ret = E_NOT_OK;
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE; /*NRC=0x31*/
        break;
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
static FUNC(Std_ReturnType, DCM_CODE) Dcm_Uds0x2FServiceDidCallAPI(
    Dcm_OpStatusType OpStatus,
    Dcm_0x2FTypes* Dcm_0x2FType,
    uint8 MsgCtrlId,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    uint8 SignalValue;
    Std_ReturnType ret = E_OK;
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) pControlEnableMaskRecord = NULL_PTR;
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
    uint32 Offset =
        (Dcm_DslCfg.pDcmChannelCfg)[Dcm_ChannelCtrl[Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex].Dcm_ChannelCfgIndex]
            .offset;
    uint8 InputOutControlParameter = Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[3u];

    if ((Dcm_0x2FType->pDcmDspDidSignal->pDcmDspDidData->DcmDspDataUsePort == USE_ECU_SIGNAL)
        && (Dcm_0x2FType->pDcmDspDidSignal->pDcmDspDidData->DcmDspDataEcuSignalFnc != NULL_PTR))
    {
#if (STD_ON == DCM_SECURITY_FUNC_ENABLED)
        boolean Flag = FALSE;
        uint8 Index;
#endif /* (STD_ON == DCM_SECURITY_FUNC_ENABLED) */
#if (STD_ON == DCM_SECURITY_FUNC_ENABLED)
        /*check the current security level*/
        if (E_OK == ret)
        {
            Flag = FALSE;
            if (Dcm_0x2FType->pDspDidControl->DcmDspDidControlSecurityLevelRefNum != 0u)
            {
                for (Index = 0;
                     (Index < Dcm_0x2FType->pDspDidControl->DcmDspDidControlSecurityLevelRefNum) && (FALSE == Flag);
                     Index++)
                {
                    if (Dcm_MkCtrl.Dcm_ActiveSec
                        == (Dcm_0x2FType->pDspDidControl->pDcmDspDidControlSecurityLevelRow)[Index])
                    {
                        Flag = TRUE;
                    }
                }
                if (FALSE == Flag)
                {
                    /*if the processing is not supported in current security level,send NRC 0x33*/
                    *ErrorCode = DCM_E_SECURITYACCESSDENIED;
                    ret = E_NOT_OK;
                }
            }
        }
#endif /* STD_ON == DCM_SECURITY_FUNC_ENABLED */
        if (E_OK == ret)
        {
            SignalValue = Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[4u + Dcm_0x2FType->InputDataOffset];
            ret = Dcm_0x2FType->pDcmDspDidSignal->pDcmDspDidData->DcmDspDataEcuSignalFnc(
                InputOutControlParameter,
                SignalValue);
        }
    }
    else if (
        (Dcm_0x2FType->pDcmDspDidSignal->pDcmDspDidData->DcmDspDataUsePort == USE_DATA_SYNCH_FNC)
        || (Dcm_0x2FType->pDcmDspDidSignal->pDcmDspDidData->DcmDspDataUsePort == USE_DATA_ASYNCH_FNC)
        || (Dcm_0x2FType->pDcmDspDidSignal->pDcmDspDidData->DcmDspDataUsePort == USE_DATA_ASYNCH_FNC_ERROR)
        || (Dcm_0x2FType->pDcmDspDidSignal->pDcmDspDidData->DcmDspDataUsePort == USE_DATA_SYNCH_CLIENT_SERVER)
        || (Dcm_0x2FType->pDcmDspDidSignal->pDcmDspDidData->DcmDspDataUsePort == USE_DATA_ASYNCH_CLIENT_SERVER)
        || (Dcm_0x2FType->pDcmDspDidSignal->pDcmDspDidData->DcmDspDataUsePort == USE_DATA_ASYNCH_CLIENT_SERVER_ERROR))
    {
        if (0u != Dcm_0x2FType->pDspDidControl->DcmDspDidControlMaskSize)
        {
            pControlEnableMaskRecord =
                &(Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData
                      [4u + Dcm_0x2FType->InputDataOffset
                       + ((Dcm_0x2FType->pDcmDspDidSignal->pDcmDspDidData->DcmDspDataSize + 7u) >> 3u)]);
        }
        Dcm_0x2FType->pControlEnableMaskRecord = pControlEnableMaskRecord;
        Dcm_0x2FType->pControlStatusRecord = &Dcm_Channel[Offset + 4u];
        ret = Dcm_Uds0x2FServiceDidCallAPI_SubDeal(OpStatus, Dcm_0x2FType, MsgCtrlId, ErrorCode);
        (*Dcm_0x2FType->ControlStatusRecordSize) +=
            ((Dcm_0x2FType->pDcmDspDidSignal->pDcmDspDidData->DcmDspDataSize + 7u) >> 3u);
    }
    else
    {
        /*idle*/
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
/***************************/
#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static Std_ReturnType DspInternalUDS0x2F_DidCheck(
    uint16 RecDid,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) pDidCfgIndex,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) pNrc)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    uint8 Index;
    Std_ReturnType ret = E_NOT_OK;

    /*find the corresponding DID in configuration*/
    for (Index = 0; (Index < Dcm_DspCfg.DcmDspDidNum) && (E_NOT_OK == ret); Index++)
    {
        /*single did check*/
        if ((RecDid == Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidId)
            && (TRUE == Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidUsed))
        {
            *pDidCfgIndex = Index;
            ret = E_OK;
        }
    }
    if (E_NOT_OK == ret)
    {
        /*if not found,send NRC 0x31*/
        (*pNrc) = DCM_E_REQUESTOUTOFRANGE;
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
/***************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dcm_Uds0x2FServiceConditionCheck(
    uint8 ProtocolCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) DidCfgIndex,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) InputDidSize,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
/* PRQA S 3432-- */                              /* MISRA Rule 20.7 */
{
    Std_ReturnType ret = E_OK; /* PRQA S 2981 */ /* MISRA Rule 2.2 */
    uint8 MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    P2CONST(Dcm_DspDidSignalType, TYPEDEF, DCM_CONST) pDcmDspDidSignal = NULL_PTR;
#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
    uint8 DidInfoCfgIndex;
    uint16 RecDid;
    uint8 InputOutControlParameter;
    uint8 iloop;
    P2CONST(Dcm_DspDidControlType, AUTOMATIC, DCM_APPL_CONST) pDspDidControl;
#endif

#if (STD_ON == DCM_SESSION_FUNC_ENABLED)
    boolean Flag = FALSE;
    uint8 Index;
    /*session check,check whether the current session supports the request service*/
    ret = DsdInternal_SesCheck(ProtocolCtrlId, SID_INPUT_OUTPUT_CONTROL_BY_IDENTIFIER);
    if (E_NOT_OK == ret)
    {
        /*the current session does not support the request service,send NRC = 0x7F*/
        *ErrorCode = DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION;
    }
#endif
#if (STD_ON == DCM_SECURITY_FUNC_ENABLED)
    /*security check,check whether the current security supports the request service*/
    if (E_OK == ret)
    {
        ret = DsdInternal_SecurityCheck(ProtocolCtrlId, SID_INPUT_OUTPUT_CONTROL_BY_IDENTIFIER);
        if (E_NOT_OK == ret)
        {
            *ErrorCode = DCM_E_SECURITYACCESSDENIED;
        }
    }
#endif
    /*min-length check*/
    if ((E_OK == ret) && (DCM_UDS0X2F_REQ_DATA_MINLENGTH > Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen))
    {
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
#if (STD_OFF == DCM_DSP_DID_FUNC_ENABLED)
    /*NRC 0x31:request out of range*/
    if (E_OK == ret)
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        ret = E_NOT_OK;
    }
#else
    if (E_OK == ret)
    {
        /*get the required DID from request message*/
        RecDid = (uint16)((uint16)((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[1u]) << 8u)
                 | ((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2u]);
        /*Determine if the DID is configured*/
        ret = DspInternalUDS0x2F_DidCheck(RecDid, DidCfgIndex, ErrorCode);
    }
    if (E_OK == ret)
    {
        DidInfoCfgIndex = Dcm_DspCfg.pDcmDspDid[*DidCfgIndex].DcmDspDidInfoIndex;
        /*check whether the Did can be configured*/
        pDspDidControl = Dcm_DspCfg.pDcmDspDidInfo[DidInfoCfgIndex].pDcmDspDidControl;
        if (NULL_PTR == pDspDidControl)
        {
            /*if the Did can be dynamically defined,send NRC 0x31*/
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            ret = E_NOT_OK;
        }
    }
    if (E_OK == ret)
    {
        /*check inputOutputControlParameter is supported*/
        InputOutControlParameter = Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[3u];
        if ((InputOutControlParameter > DCM_UDS0X2F_SHORTTERMADJUSTMENT)
            || ((InputOutControlParameter == DCM_UDS0X2F_SHORTTERMADJUSTMENT)
                && (pDspDidControl->DcmDspDidShortTermAdjustement == FALSE))
            || ((InputOutControlParameter == DCM_UDS0X2F_RESETTODEFAULT)
                && (pDspDidControl->DcmDspDidResetToDefault == FALSE))
            || ((InputOutControlParameter == DCM_UDS0X2F_FREEZECURRENTSTATE)
                && (pDspDidControl->DcmDspDidFreezeCurrentState == FALSE)))
        {
            /*if inputOutputControlParameter is not supported,send NRC 0x31*/
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            ret = E_NOT_OK;
        }
    }
#if (STD_ON == DCM_SESSION_FUNC_ENABLED)
    /*session check*/
    if ((E_OK == ret) && (pDspDidControl->DcmDspDidControlSessionRefNum != 0u))
    {
        for (Index = 0; (Index < pDspDidControl->DcmDspDidControlSessionRefNum) && (FALSE == Flag); Index++)
        {
            if (Dcm_MkCtrl.Dcm_ActiveSes == (pDspDidControl->pDcmDspDidControlSessionRow)[Index])
            {
                Flag = TRUE;
            }
        }
        if (FALSE == Flag)
        {
            /*if the processing is not supported in current session,send NRC 0x31*/
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            ret = E_NOT_OK;
        }
    }
#endif /* STD_ON == DCM_SESSION_FUNC_ENABLED */
    if (E_OK == ret)
    {
        /*Calculate the InputDidSize*/
        if (((Dcm_DspCfg.pDcmDspDid)[*DidCfgIndex].pDcmDspDidSignal != NULL_PTR)
            && (InputOutControlParameter == DCM_UDS0X2F_SHORTTERMADJUSTMENT))
        {
            pDcmDspDidSignal = (Dcm_DspCfg.pDcmDspDid)[*DidCfgIndex].pDcmDspDidSignal;
            for (iloop = 0; iloop < (Dcm_DspCfg.pDcmDspDid)[*DidCfgIndex].DcmDspDidSignalNum; iloop++)
            {
                (*InputDidSize) += ((pDcmDspDidSignal->pDcmDspDidData->DcmDspDataSize + 7u) >> 3u);
                pDcmDspDidSignal++;
            }
            pDcmDspDidSignal = (Dcm_DspCfg.pDcmDspDid)[*DidCfgIndex].pDcmDspDidSignal;
        }
        /*configuration check*/
        if ((NULL_PTR != pDcmDspDidSignal)
            && ((pDspDidControl->DcmDspDidControlMask != DCM_CONTROLMASK_NO)
                && ((pDcmDspDidSignal->pDcmDspDidData->DcmDspDataUsePort == USE_DATA_SENDER_RECEIVER)
                    || (pDcmDspDidSignal->pDcmDspDidData->DcmDspDataUsePort == USE_DATA_SENDER_RECEIVER_AS_SERVICE))))
        {
            /* send NRC 0x13*/
            *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            ret = E_NOT_OK;
        }
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
static FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x2FSubDeal(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    Dcm_0x2FTypes* Dcm_0x2FType,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    Std_ReturnType ret = E_OK;
    uint8 iloop;
    uint8 Postion = 0;
    uint16 InputDataOffset = 0;
    uint8 MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    uint8 InputOutControlParameter = Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[3u];
    P2CONST(Dcm_DspDidSignalType, TYPEDEF, DCM_CONST) pDcmDspDidSignal;

    /*total length check*/
    if (((Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen
          != (uint32)((uint32)((uint32)4UL + Dcm_0x2FType->InputDidSize
                               + Dcm_0x2FType->pDspDidControl->DcmDspDidControlMaskSize)))
         && (InputOutControlParameter == DCM_UDS0X2F_SHORTTERMADJUSTMENT))
        || ((Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen
             != (uint32)((uint32)((uint32)4UL + Dcm_0x2FType->pDspDidControl->DcmDspDidControlMaskSize)))
            && (InputOutControlParameter != DCM_UDS0X2F_SHORTTERMADJUSTMENT)))
    {
        /*the length of massage is not correct,send NRC 0x13*/
        *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        ret = E_NOT_OK;
    }
    if (E_OK == ret)
    {
        if ((Dcm_DspCfg.pDcmDspDid)[Dcm_0x2FType->DidCfgIndex].DcmDspDidSignalNum > 1u)
        {
            if ((Dcm_DspCfg.pDcmDspDid)[Dcm_0x2FType->DidCfgIndex].pDcmDspDidSignal != NULL_PTR)
            {
                pDcmDspDidSignal = (Dcm_DspCfg.pDcmDspDid)[Dcm_0x2FType->DidCfgIndex].pDcmDspDidSignal;
                for (iloop = 0; iloop < (Dcm_DspCfg.pDcmDspDid)[Dcm_0x2FType->DidCfgIndex].DcmDspDidSignalNum; iloop++)
                {
                    if (Dcm_0x2FType->pDspDidControl->DcmDspDidControlMask == DCM_CONTROLMASK_INTERNAL)
                    {
                        if (Dcm_0x2FType->pDspDidControl->DcmDspDidControlEnableMask != NULL_PTR)
                        {
                            Postion = Dcm_0x2FType->pDspDidControl->DcmDspDidControlEnableMask
                                          ->DcmDspDidControlMaskBitPosition;
                        }
                        else
                        {
                            switch (Dcm_0x2FType->pDspDidControl->DcmDspDidControlMaskSize)
                            {
                            case 1u:
                                Postion = 8u;
                                break;
                            case 2u:
                                Postion = 16u;
                                break;
                            case 3u:
                                Postion = 24u;
                                break;
                            case 4u:
                                Postion = 32u;
                                break;
                            default:
                                /*idle*/
                                break;
                            }
                        }
                        if ((Dcm_0x2FType->Mask & (uint32)((uint32)((uint32)0x01u << (Postion - iloop)))) != 0UL)
                        {
                            Dcm_0x2FType->InputDataOffset = InputDataOffset;
                            Dcm_0x2FType->pDcmDspDidSignal = pDcmDspDidSignal;
                            ret = Dcm_Uds0x2FServiceDidCallAPI(OpStatus, Dcm_0x2FType, MsgCtrlId, ErrorCode);
                        }
                    }
                    else
                    {
                        Dcm_0x2FType->InputDataOffset = InputDataOffset;
                        Dcm_0x2FType->pDcmDspDidSignal = pDcmDspDidSignal;
                        ret = Dcm_Uds0x2FServiceDidCallAPI(OpStatus, Dcm_0x2FType, MsgCtrlId, ErrorCode);
                    }
                    InputDataOffset += ((pDcmDspDidSignal->pDcmDspDidData->DcmDspDataSize + 7u) >> 3u);
                    pDcmDspDidSignal++;
                }
            }
            else
            {
                /*if pDcmDspDidSignal is not supported,send NRC 0x22*/
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                ret = E_NOT_OK;
            }
        }
        else if ((Dcm_DspCfg.pDcmDspDid)[Dcm_0x2FType->DidCfgIndex].DcmDspDidSignalNum == 1u)
        {
            pDcmDspDidSignal = (Dcm_DspCfg.pDcmDspDid)[Dcm_0x2FType->DidCfgIndex].pDcmDspDidSignal;
            Dcm_0x2FType->InputDataOffset = InputDataOffset;
            Dcm_0x2FType->pDcmDspDidSignal = pDcmDspDidSignal;
            ret = Dcm_Uds0x2FServiceDidCallAPI(OpStatus, Dcm_0x2FType, MsgCtrlId, ErrorCode);
        }
        else
        {
            /*if DcmDspDidSignalNum is 0,send NRC 0x22*/
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            ret = E_NOT_OK;
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
/****************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(Std_ReturnType, DCM_CODE)
Dcm_UDS0x2F(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
    uint16 RecDid;
    uint16 InputDidSize = 0;
    uint32 Offset;
    uint8 DidCfgIndex;
    uint8 DidInfoCfgIndex;
    uint8 TxChannelCtrlIndex;
    uint8 TxChannelCfgIndex;
    uint16 ControlStatusRecordSize = 0;
    uint8 InputOutControlParameter;
    P2CONST(Dcm_DspDidControlType, AUTOMATIC, DCM_APPL_CONST) pDspDidControl;
    uint8 iloop;
    uint32 Mask = 0;
    Dcm_0x2FTypes Dcm_0x2FType;
#endif
    uint8 MsgCtrlId;
    Std_ReturnType ret;

    /*if the required protocol is configured,get the index of runtime datum*/
    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;

    ret = Dcm_Uds0x2FServiceConditionCheck(ProtocolCtrlId, &DidCfgIndex, &InputDidSize, ErrorCode);

#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
    if (E_OK == ret)
    {
        /*check inputOutputControlParameter is supported*/
        InputOutControlParameter = Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[3u];
        /*get the required DID from request message*/
        RecDid = (uint16)((uint16)((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[1u]) << 8u)
                 | ((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2u]);

        DidInfoCfgIndex = Dcm_DspCfg.pDcmDspDid[DidCfgIndex].DcmDspDidInfoIndex;
        /*check whether the Did can be configured*/
        pDspDidControl = Dcm_DspCfg.pDcmDspDidInfo[DidInfoCfgIndex].pDcmDspDidControl;
        if ((pDspDidControl->DcmDspDidControlMask == DCM_CONTROLMASK_NO)
            && (pDspDidControl->DcmDspDidControlMaskSize != 0u))
        {
            /*send NRC 0x13*/
            *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            ret = E_NOT_OK;
        }
    }
    if (E_OK == ret)
    {
        TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex;
        TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;
        Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;
        /*Calculate the Mask*/
        for (iloop = 0; iloop < pDspDidControl->DcmDspDidControlMaskSize; iloop++)
        {
            Mask = Mask << 8u;
            Mask |= (uint32)(Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[4u + InputDidSize + (uint16)iloop]);
        }
        Dcm_0x2FType.Mask = Mask;
        Dcm_0x2FType.InputDidSize = InputDidSize;
        Dcm_0x2FType.DidCfgIndex = DidCfgIndex;
        Dcm_0x2FType.pDspDidControl = pDspDidControl;
        Dcm_0x2FType.ControlStatusRecordSize = &ControlStatusRecordSize;
        ret = Dcm_UDS0x2FSubDeal(OpStatus, ProtocolCtrlId, &Dcm_0x2FType, ErrorCode);
    }
#if (DCM_DSP_DID_FOR_2F_NUM > 0)
    if (E_OK == ret)
    {
        if (InputOutControlParameter != DCM_UDS0X2F_RETURNCONTROLTOECU)
        {                                                                              /*store the control DID*/
            for (iloop = 0; iloop < DCM_DSP_DID_FOR_2F_NUM; iloop++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
            {
                if (DcmOnControlDidfor2F[iloop] == 0u)
                {
                    DcmOnControlDidfor2F[iloop] = RecDid;
                    break;
                }
            }
        }
        else
        {                                                                              /*clear the control DID*/
            for (iloop = 0; iloop < DCM_DSP_DID_FOR_2F_NUM; iloop++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
            {
                if (DcmOnControlDidfor2F[iloop] == RecDid)
                {
                    DcmOnControlDidfor2F[iloop] = 0;
                    break;
                }
            }
        }
    }
#endif
    /* check tx data length */
    if ((E_OK == ret)
        && ((4u + (uint32)ControlStatusRecordSize) > Dcm_DslCfg.pDcmChannelCfg[TxChannelCfgIndex].Dcm_DslBufferSize))
    {
        /*Pdu length is bigger than buffer size,ignore the request message */
        *ErrorCode = DCM_E_RESPONSETOOLONG;
        ret = E_NOT_OK;
    }
    /* send response message */
    switch (ret)
    {
    case E_OK:
        SchM_Enter_Dcm(Dcm_Channel);
        Dcm_Channel[Offset] = 0x6F;                          /*response SID*/
        Dcm_Channel[Offset + 1u] = (uint8)(RecDid >> 8u);    /*response Did MSB*/
        Dcm_Channel[Offset + 2u] = (uint8)RecDid;            /*response Did LSB*/
        Dcm_Channel[Offset + 3u] = InputOutControlParameter; /*InputOutControlParameter*/
        SchM_Exit_Dcm(Dcm_Channel);
        SchM_Enter_Dcm(Dcm_MsgCtrl);
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResMaxDataLen = 4u + (uint32)ControlStatusRecordSize;
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResDataLen = 4u + (uint32)ControlStatusRecordSize;
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.pResData = &Dcm_Channel[Offset];
        SchM_Exit_Dcm(Dcm_MsgCtrl);
        DsdInternal_ProcessingDone(ProtocolCtrlId);
        break;
    case E_NOT_OK:
        break;
    case DCM_E_PENDING:
        Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
        break;
    default:
        /*NRC=0x22*/
        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        ret = E_NOT_OK;
        break;
    }
    return ret;
#endif
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif
