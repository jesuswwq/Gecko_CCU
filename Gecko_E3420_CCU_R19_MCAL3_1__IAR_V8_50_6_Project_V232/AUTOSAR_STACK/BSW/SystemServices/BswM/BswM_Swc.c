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
**  FILENAME    : BswM_Swc.c                                                  **
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
#include "BswM_Swc.h"

#if (BSWM_RTE_ENABLED == STD_ON)
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
 * This is a notification that an error occurred because the partition containing
 * the mode users of the Mode Declaration Group Prototype was restarted by the
 * RTE. Because the Mode Machine Instance holding the current mode can reside on
 * that terminated partition, the Mode Manager has to be informed about the loss
 * of this partition.
 * Service ID:
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): portId, the id of switch port
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_SWC_CODE)
BswM_SwcModeSwitchErrorNotification(uint16 portId)
{
    P2CONST(BswM_EventRqstPortLCfgType, AUTOMATIC, BSWM_CONST) evRqstLCfgPtr;
    P2VAR(BswM_EventRquestPortRuntimeType, AUTOMATIC, BSWM_VAR_CLEARED) evRqstPtr;
    P2CONST(BswM_RuleLcCfgType, AUTOMATIC, BSWM_CONST) ruleLCfgPtr;
    BswM_RuleIndexType numOfRules;
    BswM_RuleIndexType idx;
    BswM_RuleIndexType ruleIdx;
    BswM_EventRqstPortIdxType evIdx;
    ApplicationType partIdx;
    boolean result;
    uint16 numOfModeSwiErrEv;
    uint16 swcIdx;

    if (BSWM_INITED == BswM_RuntimeStatus.bswmInitState)
    {
        result = BswM_GetPartitionIdx(&partIdx);
        if ((boolean)TRUE == result)
        {
            numOfModeSwiErrEv = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].evRqstPCCfg->numOfModeSwiErrEv;
            evRqstLCfgPtr = BswM_RuntimeStatus.bswmPartLCfgs[partIdx].evRqstLCfg;
            for (swcIdx = 0u; swcIdx < numOfModeSwiErrEv; swcIdx++)
            {
                if (portId == evRqstLCfgPtr->modeSwiErrPort[swcIdx])
                {
                    evIdx = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].evRqstPCCfg->modeSwiErrEvPtr[swcIdx];
                    evRqstPtr = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].eventRqstPortRunPtr;
                    evRqstPtr[evIdx] = BSWM_EVENT_IS_SET;
                    if (BSWM_IMMEDIATE == evRqstLCfgPtr->modeSwiErr[swcIdx].process)
                    {
                        numOfRules = evRqstLCfgPtr->modeSwiErr[swcIdx].belongToRlueNum;
                        ruleLCfgPtr = BswM_RuntimeStatus.bswmPartLCfgs[partIdx].ruleLCfg;
                        for (idx = 0u; idx < numOfRules; idx++)
                        {
                            ruleIdx = evRqstLCfgPtr->modeSwiErr[swcIdx].belongToRlue[idx];
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
#endif /*(BSWM_EVENT_RQSTPORT_ENABLE == STD_ON)*/

/*Initialize swc related request port*/
FUNC(void, BSWM_SWC_CODE)
BswM_InitSwcRequestPorts(void)
{
    P2CONST(BswM_ModeRqstPortPCCfgType, AUTOMATIC, BSWM_CONST) modeRqstPCfgPtr;
    P2CONST(BswM_ModeRqstPortRuntimeType, AUTOMATIC, BSWM_VAR_CLEARED) modeRqstPtr;
    ApplicationType partIdx;
    boolean result;
    BswM_ModeGroupType numOfSwcModeNoti;
    BswM_ModeGroupType numOfSwcModeReq;
    BswM_ModeGroupType idx;

    result = BswM_GetPartitionIdx(&partIdx);
    if ((boolean)TRUE == result)
    {
        modeRqstPCfgPtr = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].modeRqstPCCfg;
        modeRqstPtr = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].modeRqstPortRunPtr;
        numOfSwcModeNoti = modeRqstPCfgPtr->numOfSwcModeNoti;
        numOfSwcModeReq = modeRqstPCfgPtr->numOfSwcModeReq;
        for (idx = 0u; idx < numOfSwcModeNoti; idx++)
        {
            if (NULL_PTR != modeRqstPCfgPtr->swcInitMode)
            {
                modeRqstPtr->swcModeNotiStatus[idx] = *(modeRqstPCfgPtr->swcInitMode);
            }
            else
            {
                break;
            }
        }
        for (idx = 0u; idx < numOfSwcModeReq; idx++)
        {
            if (NULL_PTR != modeRqstPCfgPtr->swcRqstInitMode)
            {
                modeRqstPtr->swcModeRqstStatus[idx] = *(modeRqstPCfgPtr->swcRqstInitMode);
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
 * Function called when a SWC has switched a mode.
 * Service ID: 0x
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): modeGroup, the mode group in that the mode was switched
 *                 mode, the mode that was switched to.
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_SWC_CODE)
BswM_SwcModeNotification(BswM_ModeGroupType modeGroup, BswM_ModeType mode)
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
    BswM_ModeGroupType numOfSwcModeNoti;
    BswM_ModeGroupType swcIdx;

    if (BSWM_INITED == BswM_RuntimeStatus.bswmInitState)
    {
        result = BswM_GetPartitionIdx(&partIdx);
        if ((boolean)TRUE == result)
        {
            modeRqstPCfgPtr = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].modeRqstPCCfg;
            modeRqstLCfgPtr = BswM_RuntimeStatus.bswmPartLCfgs[partIdx].modeRqstLCfg;
            numOfSwcModeNoti = modeRqstPCfgPtr->numOfSwcModeNoti;
            for (swcIdx = 0u; swcIdx < numOfSwcModeNoti; swcIdx++)
            {
                if (modeGroup == modeRqstLCfgPtr->swcModeNotisRef[swcIdx])
                {
                    modeRqstPtr = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].modeRqstPortRunPtr;
                    modeRqstPtr->swcModeNotiStatus[swcIdx] = mode;
                    if (BSWM_IMMEDIATE == modeRqstLCfgPtr->swcModeNoti[swcIdx].process)
                    {
                        numOfRules = modeRqstLCfgPtr->swcModeNoti[swcIdx].belongToRlueNum;
                        ruleLCfgPtr = BswM_RuntimeStatus.bswmPartLCfgs[partIdx].ruleLCfg;
                        for (idx = 0u; idx < numOfRules; idx++)
                        {
                            ruleIdx = modeRqstLCfgPtr->swcModeNoti[swcIdx].belongToRlue[idx];
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

/**
 * Function called when a SWC request a mode.
 * Service ID: 0x
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): modeGroup, the mode group in that the mode was requested
 *                 mode, the mode that was request
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_SWC_CODE)
BswM_SwcModeRequest(BswM_ModeGroupType modeGroup, BswM_ModeType mode)
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
    BswM_ModeGroupType numOfSwcModeReq;
    BswM_ModeGroupType swcIdx;

    if (BSWM_INITED == BswM_RuntimeStatus.bswmInitState)
    {
        result = BswM_GetPartitionIdx(&partIdx);
        if ((boolean)TRUE == result)
        {
            modeRqstPCfgPtr = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].modeRqstPCCfg;
            modeRqstLCfgPtr = BswM_RuntimeStatus.bswmPartLCfgs[partIdx].modeRqstLCfg;
            numOfSwcModeReq = modeRqstPCfgPtr->numOfSwcModeReq;
            for (swcIdx = 0u; swcIdx < numOfSwcModeReq; swcIdx++)
            {
                if (modeGroup == modeRqstLCfgPtr->swcModeRqstsRef[swcIdx])
                {
                    modeRqstPtr = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].modeRqstPortRunPtr;
                    modeRqstPtr->swcModeRqstStatus[swcIdx] = mode;
                    if (BSWM_IMMEDIATE == modeRqstLCfgPtr->swcModeRqst[swcIdx].process)
                    {
                        numOfRules = modeRqstLCfgPtr->swcModeRqst[swcIdx].belongToRlueNum;
                        ruleLCfgPtr = BswM_RuntimeStatus.bswmPartLCfgs[partIdx].ruleLCfg;
                        for (idx = 0u; idx < numOfRules; idx++)
                        {
                            ruleIdx = modeRqstLCfgPtr->swcModeRqst[swcIdx].belongToRlue[idx];
                            if ((boolean)FALSE == ruleLCfgPtr[ruleIdx].isNestExe)
                            {
                                /* An Independent rule,to be evaluated each time applicable*/
                                BswM_ArbitrateRule(ruleIdx, partIdx);
                            }
                        }
                    }
                }
            }
        }
    }
}

/*Get swc indicate status*/
FUNC(BswM_ModeType, BSWM_CANSM_CODE)
BswM_GetSwcModeIndStatus(BswM_ModeGroupType swcChIdx)
{
    BswM_ModeType retStatu = BSWM_INVALID_U8;
    ApplicationType partIdx;
    boolean result;

    result = BswM_GetPartitionIdx(&partIdx);
    if ((boolean)TRUE == result)
    {
        retStatu = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].modeRqstPortRunPtr->swcModeNotiStatus[swcChIdx];
    }
    return retStatu;
}

/*Get swc request status*/
FUNC(BswM_ModeType, BSWM_CANSM_CODE)
BswM_GetSwcRqstStatus(BswM_ModeGroupType swcChIdx)
{
    BswM_ModeType retStatu = BSWM_INVALID_U8;
    ApplicationType partIdx;
    boolean result;

    result = BswM_GetPartitionIdx(&partIdx);
    if ((boolean)TRUE == result)
    {
        retStatu = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].modeRqstPortRunPtr->swcModeRqstStatus[swcChIdx];
    }
    return retStatu;
}

#if (BSWM_EVENT_RQSTPORT_ENABLE == STD_ON)
/*Get BswMModeSwitchErrorEvent*/
FUNC(BswM_EventRquestPortRuntimeType, BSWM_NMIF_CODE)
BswM_GetModeSwiErrNoti(uint16 portId)
{
    BswM_EventRquestPortRuntimeType ret = BSWM_INVALID_U8;
    ApplicationType partIdx;
    boolean result;
    BswM_EventRquestPortRuntimeType evIdx;

    result = BswM_GetPartitionIdx(&partIdx);
    if ((boolean)TRUE == result)
    {
        evIdx = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].evRqstPCCfg->modeSwiErrEvPtr[portId];
        ret = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].eventRqstPortRunPtr[evIdx];
    }
    return ret;
}
#endif /*(BSWM_EVENT_RQSTPORT_ENABLE == STD_ON) */
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"
#endif /*(BSWM_RTE_ENABLED == STD_ON)*/
