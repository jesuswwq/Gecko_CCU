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
**  FILENAME    : BswM_TimerControl.c                                         **
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
#include "BswM_Internal.h"

#if (BSWM_TIMER_ENABLED == STD_ON)
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
FUNC(void, BSWM_CODE) BswM_InitBswMTimer(void)
{
    P2CONST(BswM_ModeRqstPortPCCfgType, AUTOMATIC, BSWM_CONST) modeRqstPCfgPtr;
    P2CONST(BswM_ModeRqstPortRuntimeType, AUTOMATIC, BSWM_VAR_CLEARED) modeRqstPtr;
    BswM_TimerIdxType numOfBswMTimer;
    BswM_TimerIdxType timerIdx;
    ApplicationType partIdx;
    boolean result;

    result = BswM_GetPartitionIdx(&partIdx);
    if ((boolean)TRUE == result)
    {
        modeRqstPCfgPtr = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].modeRqstPCCfg;
        modeRqstPtr = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].modeRqstPortRunPtr;
        numOfBswMTimer = modeRqstPCfgPtr->numOfBswMTimer;
        for (timerIdx = 0u; timerIdx < numOfBswMTimer; timerIdx++)
        {
            /*Each BswMTimer shall be stopped (BSWM_TIMER_STOPPED) during initialization*/
            modeRqstPtr->timerStatus[timerIdx] = BSWM_TIMER_STOP;
            modeRqstPtr->timerCycle[timerIdx] = 0u;
        }
    }
#if (BSWM_DEV_ERROR_DETECT == STD_ON)
    else
    {
        (void)Det_ReportError(BSWM_MODULE_ID, BSWM_INSTANCE_ID, BSWM_API_ID_INIT, BSWM_E_INIT_FAILED);
    }
#endif /*(BSWM_DEV_ERROR_DETECT == STD_ON)*/
}

FUNC(BswM_TimerEnumType, BSWM_CODE) BswM_GerTimerStatus(BswM_TimerIdxType timerIdx)
{
    BswM_TimerEnumType timerStatus = BSWM_TIMER_START;
    ApplicationType partIdx;
    boolean result;

    result = BswM_GetPartitionIdx(&partIdx);
    if ((boolean)TRUE == result)
    {
        timerStatus = BswM_RuntimeStatus.bswmPartPCCfgs[partIdx].modeRqstPortRunPtr->timerStatus[timerIdx];
    }
    return timerStatus;
}
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

#endif /*BSWM_TIMER_ENABLED == STD_ON)*/
