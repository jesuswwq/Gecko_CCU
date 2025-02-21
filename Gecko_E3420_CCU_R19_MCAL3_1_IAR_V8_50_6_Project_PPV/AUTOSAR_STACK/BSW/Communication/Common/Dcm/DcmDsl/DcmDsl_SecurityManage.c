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

/******************************* references ************************************/
#include "Dcm_Internal.h"
#include "UDS.h"

#if (STD_ON == DCM_SECURITY_FUNC_ENABLED)

/********************************************************
 *******************************************************/
#define DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"
VAR(Dcm_SecCtrlType, DCM_VAR_NOINIT) Dcm_SecCtrl; /*Security level management control block*/
#define DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"

/*************************************************************************/
/*
 * Brief               <initial of Security level control block>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <>
 * CallByAPI           <Dcm_Init()>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(void, DCM_CODE) DslInternal_InitSecCtrl(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Std_ReturnType ret;
    P2CONST(Dcm_DspSecurityRowType, AUTOMATIC, DCM_CONST) pSecurityRow;
    uint8 SecCfgIndex;

    SchM_Enter_Dcm(Dcm_SecCtrl);
    Dcm_SecCtrl.Dcm_SubfunctionForSeed = 0u;
    Dcm_SecCtrl.Dcm_ActiveSec = DCM_SEC_LEV_LOCKED;
    Dcm_SecCtrl.Dcm_NewSec = DCM_SEC_LEV_LOCKED;
    Dcm_SecCtrl.Dcm_SecServiceState = DCM_SERVICE_IDLE;
    Dcm_SecCtrl.Dcm_SecFlag = 0;

    for (SecCfgIndex = 0; (SecCfgIndex < DCM_SECURITY_NUM)
                          && ((DCM_SEC_RESUMECALL_MASK != (Dcm_SecCtrl.Dcm_SecFlag & DCM_SEC_RESUMECALL_MASK)));
         SecCfgIndex++)
    {
        pSecurityRow = &(Dcm_DspCfg.pDcm_DspSecurity->pDcm_DspSecurityRow[SecCfgIndex]);
        if (pSecurityRow != NULL_PTR)
        {
            if ((TRUE == pSecurityRow->DcmDspSecurityAttemptCounterEnabled)
                && ((USE_ASYNCH_FNC == pSecurityRow->DcmDspSecurityUsePort)
                    || (USE_ASYNCH_CLIENT_SERVER == pSecurityRow->DcmDspSecurityUsePort)))
            {
                if (pSecurityRow->Dcm_GetSecurityAttemptCounterFnc != NULL_PTR)
                {
                    ret = pSecurityRow->Dcm_GetSecurityAttemptCounterFnc(
                        DCM_INITIAL,
                        &Dcm_SecCtrl.Dcm_FalseAcessCount[SecCfgIndex]);
                    if (DCM_E_PENDING == ret)
                    {
                        Dcm_SecCtrl.Dcm_SecFlag |= DCM_SEC_RESUMECALL_MASK;
                        Dcm_SecCtrl.Dcm_SecCfgIndex = SecCfgIndex;
                        Dcm_SecCtrl.Dcm_MaxReadoutTime = 0;
                    }
                    if (E_NOT_OK == ret)
                    {
                        Dcm_SecCtrl.Dcm_FalseAcessCount[SecCfgIndex] = pSecurityRow->DcmDspSecurityNumAttDelay;
                    }
                    // if (Dcm_SecCtrl.Dcm_FalseAcessCount[SecCfgIndex] >= pSecurityRow->DcmDspSecurityNumAttDelay)
                    // {
                    /*Add for GECKO*/
                        Dcm_ResetTime(&Dcm_SecCtrl.Dcm_RunDlyCtrl.Dcm_SecCurTimer[SecCfgIndex]);
                        Dcm_SecCtrl.Dcm_RunDlyCtrl.Dcm_SecExpiredTimer[SecCfgIndex] =
                            (Dcm_DspCfg.pDcm_DspSecurity->pDcm_DspSecurityRow)[SecCfgIndex].DcmDspSecurityDelayTime;
                        Dcm_SecCtrl.Dcm_RunDlyCtrl.Dcm_SecTimerState[SecCfgIndex] = DCM_SECTIMER_ON;
                    // }
                }
            }
        }
    }
    if (DCM_SEC_RESUMECALL_MASK != (Dcm_SecCtrl.Dcm_SecFlag & DCM_SEC_RESUMECALL_MASK))
    {
        Dcm_SecCtrl.Dcm_SecFlag |= DCM_SEC_CALL_OVER_MASK;
    }
    SchM_Exit_Dcm(Dcm_SecCtrl);
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*************************************************************************/
/*
 * Brief               <Setting the security level>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <NewSec:To be changed the security level>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(void, DCM_CODE) DslInternal_SetSecurityLevel(Dcm_SecLevelType NewSec)
{
    SchM_Enter_Dcm(Dcm_SecCtrl);
    Dcm_SecCtrl.Dcm_ActiveSec = NewSec;
    SchM_Exit_Dcm(Dcm_SecCtrl);

    SchM_Enter_Dcm(Dcm_MkCtrl);
    Dcm_MkCtrl.Dcm_ActiveSec = NewSec;
    SchM_Exit_Dcm(Dcm_MkCtrl);

#if (STD_ON == DCM_UDS_SERVICE0X2A_ENABLED)
    /*check 2A is supported in NewSec*/
    Dcm_UDS0x2ACheckNewSecurity();
#endif

#if ((DCM_DSP_DID_FOR_2F_NUM > 0) && (STD_ON == DCM_UDS_SERVICE0X2F_ENABLED))
    /*check 2F is supported in NewSec*/
    Dcm_UDS0x2FCheckNewSecurity(NewSec);
#endif
    DslInternal_InitDspProgramInfo();
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*************************************************************************/
/*
 * Brief               <Set SecurityAccess service process ,receives seed/key status>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <Status:State to be modified>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(void, DCM_CODE) DslInternal_SetSecurityAccessStatus(Dcm_SecServiceStateType Status)
{
    SchM_Enter_Dcm(Dcm_SecCtrl);
    Dcm_SecCtrl.Dcm_SecServiceState = Status;
    SchM_Exit_Dcm(Dcm_SecCtrl);
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(Std_ReturnType, DCM_CODE)
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
DslInternal_GetSecurityCfgBySecLevel(Dcm_SecLevelType Dcm_SecLevel, P2VAR(uint8, AUTOMATIC, AUTOMATIC) SecCfgIndex)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    uint8 Index;
    Std_ReturnType ret = E_NOT_OK;

    for (Index = 0; (Index < Dcm_DspCfg.pDcm_DspSecurity->DcmDspSecurityRow_Num) && (E_NOT_OK == ret); Index++)
    {
        if (Dcm_SecLevel == (Dcm_DspCfg.pDcm_DspSecurity->pDcm_DspSecurityRow)[Index].DcmDspSecurityLevel)
        {
            *SecCfgIndex = Index;
            ret = E_OK;
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif
