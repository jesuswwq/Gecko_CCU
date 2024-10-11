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
**  FILENAME    : BswM_EthIf.c                                                **
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
#include "BswM_EthIf.h"
#if (BSWM_ETHIF_ENABLED == STD_ON)
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
/*Initialize BswMEthIfPortGroupLinkStateChg request port*/
FUNC(void, BSWM_ETHIF_CODE)
BswM_InitEthIfRequestPorts(void)
{
    P2CONST(BswM_ModeRqstPortPCCfgType, AUTOMATIC, BSWM_CONST) modeRqstPCfgPtr;
    P2CONST(BswM_ModeRqstPortRuntimeType, AUTOMATIC, BSWM_VAR_CLEARED) modeRqstPtr;
    ApplicationType partIdx;
    boolean result;
    EthIf_SwitchPortGroupIdxType numOfEthIfPG;
    EthIf_SwitchPortGroupIdxType pgIdx;

    result = BswM_GetPartitionIdx(&partIdx);
    if ((boolean)TRUE == result)
    {
        modeRqstPCfgPtr = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].modeRqstPCCfg;
        modeRqstPtr = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].modeRqstPortRunPtr;
        numOfEthIfPG = modeRqstPCfgPtr->numOfEthIfPG;
        for (pgIdx = 0u; pgIdx < numOfEthIfPG; pgIdx++)
        {
            if (NULL_PTR != modeRqstPCfgPtr->ethIfPGInitState)
            {
                modeRqstPtr->ethIfPGStatus[pgIdx] = *(modeRqstPCfgPtr->ethIfPGInitState);
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
 * Function called by EthIf to indicate the link state change of a certain Ethernet switch port group.
 * Service ID: 0x26
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): PortGroupIdx, The port group index in the context of the Ethernet Interface
 *                 PortGroupState, The state of the port group. State is derived from the physical link of the
 *                                  Ethernet Transceiver: ETHTRCV_LINK_STATE_DOWN == Port group
 *                                  has link down. ETHTRCV_LINK_STATE_ACTIVE == Port group has link
 *                                  up.
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_ETHIF_CODE)
BswM_EthIf_PortGroupLinkStateChg(EthIf_SwitchPortGroupIdxType PortGroupIdx, EthTrcv_LinkStateType PortGroupState)
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
    EthIf_SwitchPortGroupIdxType numOfEthIfPG;
    EthIf_SwitchPortGroupIdxType pgIdx;

#if (BSWM_DEV_ERROR_DETECT == STD_ON)
    if ((Std_ReturnType)E_OK == BswM_DetChkEthIfPortGru(PortGroupState))
#endif /*(BSWM_DEV_ERROR_DETECT == STD_ON)*/
    {
        result = BswM_GetPartitionIdx(&partIdx);
        if ((boolean)TRUE == result)
        {
            modeRqstPCfgPtr = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].modeRqstPCCfg;
            modeRqstLCfgPtr = BswM_RuntimeStatus.bswmPartLCfgs[partIdx].modeRqstLCfg;
            numOfEthIfPG = modeRqstPCfgPtr->numOfEthIfPG;
            for (pgIdx = 0u; pgIdx < numOfEthIfPG; pgIdx++)
            {
                if (PortGroupIdx == modeRqstLCfgPtr->ethIfPortGroRef[pgIdx])
                {
                    modeRqstPtr = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].modeRqstPortRunPtr;
                    modeRqstPtr->ethIfPGStatus[pgIdx] = PortGroupState;
                    if (BSWM_IMMEDIATE == modeRqstLCfgPtr->ethIfPortGroLink[pgIdx].process)
                    {
                        numOfRules = modeRqstLCfgPtr->ethIfPortGroLink[pgIdx].belongToRlueNum;
                        ruleLCfgPtr = BswM_RuntimeStatus.bswmPartLCfgs[partIdx].ruleLCfg;
                        for (idx = 0u; idx < numOfRules; idx++)
                        {
                            ruleIdx = modeRqstLCfgPtr->ethIfPortGroLink[pgIdx].belongToRlue[idx];
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

/*Get specified ethif port group link state*/
FUNC(EthTrcv_LinkStateType, BSWM_ETHIF_CODE)
BswM_GetEthIfGruStateStatus(EthIf_SwitchPortGroupIdxType ethIdx)
{
    EthTrcv_LinkStateType ethState = ETHTRCV_LINK_STATE_DOWN;
    ApplicationType partIdx;
    boolean result;

    result = BswM_GetPartitionIdx(&partIdx);
    if ((boolean)TRUE == result)
    {
        ethState = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].modeRqstPortRunPtr->ethIfPGStatus[ethIdx];
    }
    return ethState;
}
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

#endif /*(BSWM_ETHIF_ENABLED == STD_ON)*/
