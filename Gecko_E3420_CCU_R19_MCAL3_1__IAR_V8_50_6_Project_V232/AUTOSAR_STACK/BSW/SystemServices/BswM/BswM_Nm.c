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
**  FILENAME    : BswM_Nm.c                                                   **
**                                                                            **
**  Created on  : 2020-03-24                                                  **
**  Author      : qinchun.yang                                                **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "BswM_Nm.h"
#if (BSWM_NM_ENABLED == STD_ON)
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define BSWM_START_SEC_CODE
#include "BswM_MemMap.h"

#if (BSWM_EVENT_RQSTPORT_ENABLE == STD_ON)
/**
 * Function called by NmIf to indicate a CarWakeup.
 * Service ID: 0x24
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters(IN): Network, Identification of the Nm-Channel
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_NMIF_CODE)
BswM_Nm_CarWakeUpIndication(NetworkHandleType Network)
{
    P2CONST(BswM_EventRqstPortLCfgType, AUTOMATIC, BSWM_CONST) evRqstLCfgPtr;
    /* PRQA S 3432 ++*/ /* MISRA Rule 20.7 */
    P2VAR(BswM_EventRquestPortRuntimeType, AUTOMATIC, BSWM_VAR_CLEARED) evRqstPtr;
    /* PRQA S 3432 --*/ /* MISRA Rule 20.7 */
    P2CONST(BswM_RuleLcCfgType, AUTOMATIC, BSWM_CONST) ruleLCfgPtr;
    BswM_RuleIndexType numOfRules;
    BswM_RuleIndexType idx;
    BswM_RuleIndexType ruleIdx;
    BswM_EventRqstPortIdxType evIdx;
    ApplicationType partIdx;
    boolean result;
    NetworkHandleType numOfNmWkCh;
    NetworkHandleType chIdx;

#if (BSWM_DEV_ERROR_DETECT == STD_ON)
    if ((Std_ReturnType)E_OK == BswM_DetChkNmCarWkUp())
#endif /*(BSWM_DEV_ERROR_DETECT == STD_ON)*/
    {
        result = BswM_GetPartitionIdx(&partIdx);
        if ((boolean)TRUE == result)
        {
            numOfNmWkCh = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].evRqstPCCfg->numOfNmWkCh;
            evRqstLCfgPtr = BswM_RuntimeStatus.bswmPartLCfgs[partIdx].evRqstLCfg;
            for (chIdx = 0u; chIdx < numOfNmWkCh; chIdx++)
            {
                if (Network == evRqstLCfgPtr->nmWkChRef[chIdx])
                {
                    evIdx = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].evRqstPCCfg->nmWkEvPortIdxPtr[chIdx];
                    evRqstPtr = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].eventRqstPortRunPtr;
                    evRqstPtr[evIdx] = BSWM_EVENT_IS_SET;
                    if (BSWM_IMMEDIATE == evRqstLCfgPtr->nmWakeUpInd[chIdx].process)
                    {
                        numOfRules = evRqstLCfgPtr->nmWakeUpInd[chIdx].belongToRlueNum;
                        ruleLCfgPtr = BswM_RuntimeStatus.bswmPartLCfgs[partIdx].ruleLCfg;
                        for (idx = 0u; idx < numOfRules; idx++)
                        {
                            ruleIdx = evRqstLCfgPtr->nmWakeUpInd[chIdx].belongToRlue[idx];
                            if ((boolean)FALSE == ruleLCfgPtr[ruleIdx].isNestExe)
                            {
                                /* An Independent rule,to be evaluated each time applicable*/
                                BswM_ArbitrateRule(ruleIdx, partIdx);
                            }
                        }
                    }
                    break;
                }
            }
        }
    }
}

/*Get Nm wake-up indication*/
FUNC(BswM_EventRquestPortRuntimeType, BSWM_NMIF_CODE)
BswM_GetNmWkInd(NetworkHandleType nmIdx)
{
    BswM_EventRquestPortRuntimeType ret = BSWM_INVALID_U8;
    ApplicationType partIdx;
    boolean result;
    BswM_EventRquestPortRuntimeType evIdx;

    result = BswM_GetPartitionIdx(&partIdx);
    if ((boolean)TRUE == result)
    {
        evIdx = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].evRqstPCCfg->nmWkEvPortIdxPtr[nmIdx];
        ret = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].eventRqstPortRunPtr[evIdx];
    }
    return ret;
}
#endif /*(BSWM_EVENT_RQSTPORT_ENABLE == STD_ON)*/
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

#endif /*(BSWM_NM_ENABLED == STD_ON)*/
