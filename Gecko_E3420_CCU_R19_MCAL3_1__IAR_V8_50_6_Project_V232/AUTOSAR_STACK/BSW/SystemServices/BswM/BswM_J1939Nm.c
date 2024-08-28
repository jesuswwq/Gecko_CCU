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
**  FILENAME    : BswM_J1939Nm.c                                              **
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
#include "BswM_J1939Nm.h"
#if (BSWM_J1939NM_ENABLED == STD_ON)
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
/*Initialize BswMJ1939NmIndication request port*/
FUNC(void, BSWM_J1939NM_CODE)
BswM_InitJ1939NmRequestPorts(void)
{
    P2CONST(BswM_ModeRqstPortPCCfgType, AUTOMATIC, BSWM_CONST) modeRqstPCfgPtr;
    P2CONST(BswM_ModeRqstPortRuntimeType, AUTOMATIC, BSWM_VAR_CLEARED) modeRqstPtr;
    ApplicationType partIdx;
    boolean result;
    NetworkHandleType numOfJ1939NmInd;
    NetworkHandleType chIdx;

    result = BswM_GetPartitionIdx(&partIdx);
    if ((boolean)TRUE == result)
    {
        modeRqstPCfgPtr = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].modeRqstPCCfg;
        modeRqstPtr = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].modeRqstPortRunPtr;
        numOfJ1939NmInd = modeRqstPCfgPtr->numOfJ1939NmInd;
        for (chIdx = 0u; chIdx < numOfJ1939NmInd; chIdx++)
        {
            if (NULL_PTR != modeRqstPCfgPtr->j1939NmInitState)
            {
                modeRqstPtr->j1939NmIndiStatus[chIdx] = *(modeRqstPCfgPtr->j1939NmInitState);
            }
            else
            {
                break;
            }
        }
    }
#if (BSWM_DEV_ERROR_DETECT == STD_ON)
    else
    {
        (void)Det_ReportError(BSWM_MODULE_ID, BSWM_INSTANCE_ID, BSWM_API_ID_INIT, BSWM_E_INIT_FAILED);
    }
#endif /*(BSWM_DEV_ERROR_DETECT == STD_ON)*/
}

/**
 * Notification of current J1939Nm state after state changes.
 * Service ID: 0x18
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): Network, Identification of the J1939 channel
 *                 Node,   Identification of the J1939 node
 *                 NmState, Current (new) state of the J1939 node
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_J1939NM_CODE)
BswM_J1939Nm_StateChangeNotification(NetworkHandleType Network, uint8 Node, Nm_StateType NmState)
{
    P2CONST(BswM_ModeRqstPortPCCfgType, AUTOMATIC, BSWM_CONST) modeRqstPCfgPtr;
    P2CONST(BswM_ModeRqstPortLCfgType, AUTOMATIC, BSWM_CONST) modeRqstLCfgPtr;
    P2CONST(BswM_ModeRqstPortRuntimeType, AUTOMATIC, BSWM_VAR_CLEARED) modeRqstPtr;
    P2CONST(BswM_RuleLcCfgType, AUTOMATIC, BSWM_CONST) ruleLCfgPtr;
    BswM_RuleIndexType numOfRules;
    BswM_RuleIndexType idx;
    BswM_RuleIndexType ruleIdx;
    ApplicationType partIdx;
    boolean result;
    NetworkHandleType numOfJ1939NmInd;
    NetworkHandleType chIdx;

#if (BSWM_DEV_ERROR_DETECT == STD_ON)
    if ((Std_ReturnType)E_OK == BswM_DetChkJ1939NmInd())
#endif /*(BSWM_DEV_ERROR_DETECT == STD_ON)*/
    {
        result = BswM_GetPartitionIdx(&partIdx);
        if ((boolean)TRUE == result)
        {
            modeRqstPCfgPtr = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].modeRqstPCCfg;
            modeRqstLCfgPtr = BswM_RuntimeStatus.bswmPartLCfgs[partIdx].modeRqstLCfg;
            numOfJ1939NmInd = modeRqstPCfgPtr->numOfJ1939NmInd;
            for (chIdx = 0u; chIdx < numOfJ1939NmInd; chIdx++)
            {
                if ((Network == modeRqstLCfgPtr->j1939NmChRef[chIdx])
                    && (Node == modeRqstLCfgPtr->j1939NmNodeRef[chIdx]))
                {
                    modeRqstPtr = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].modeRqstPortRunPtr;
                    modeRqstPtr->j1939NmIndiStatus[chIdx] = NmState;
                    if (BSWM_IMMEDIATE == modeRqstLCfgPtr->j1939NmInd[chIdx].process)
                    {
                        numOfRules = modeRqstLCfgPtr->j1939NmInd[chIdx].belongToRlueNum;
                        ruleLCfgPtr = BswM_RuntimeStatus.bswmPartLCfgs[partIdx].ruleLCfg;
                        for (idx = 0u; idx < numOfRules; idx++)
                        {
                            ruleIdx = modeRqstLCfgPtr->j1939NmInd[chIdx].belongToRlue[idx];
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

/*Get J1939Nm indicate status*/
FUNC(Nm_StateType, BSWM_J1939NM_CODE)
BswM_GetJ1939NmStatus(NetworkHandleType j1939ChIdx)
{
    Nm_StateType retStatus = NM_STATE_UNINIT;
    ApplicationType partIdx;
    boolean result;

    result = BswM_GetPartitionIdx(&partIdx);
    if ((boolean)TRUE == result)
    {
        retStatus = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].modeRqstPortRunPtr->j1939NmIndiStatus[j1939ChIdx];
    }
    return retStatus;
}
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

#endif /*(BSWM_J1939NM_ENABLED == STD_ON)*/
