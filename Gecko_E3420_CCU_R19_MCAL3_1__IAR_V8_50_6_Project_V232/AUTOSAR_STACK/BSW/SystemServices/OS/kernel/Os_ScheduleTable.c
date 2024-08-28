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
**  FILENAME    : Os_ScheduleTable.c                                          **
**                                                                            **
**  Created on  :                                                             **
**  Author      : i-soft-os                                                   **
**  Vendor      :                                                             **
**  DESCRIPTION : scheduleTable manager                                       **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/**
 *  <VERSION>  <DATE>    <AUTHOR>       <REVISION LOG>
 *  V0.1.0     2015-03-10 Yan.Zhuang    Initial version, add this file.
 *                                      data type and function.
 *  V0.2.0     2019-08-21  shun.li & zhiqiang.huang   Functional safety initial version.
 *  V1.0.0     2019-11-21  shun.li        Functional safety version.
 */
/*============================================================================*/

/*=======[M I S R A C  R U L E  V I O L A T I O N]============================*/
/*  <MESSAGE ID>    <CODE LINE>    <REASON>
 */
/*============================================================================*/

/*=======[I N C L U D E S]====================================================*/

#include "Os_Internal.h"

#if (CFG_SCHEDTBL_MAX > 0U)
/*=======[E X T E R N A L   D A T A]==========================================*/
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
static P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) Os_SchedTblCfg = NULL_PTR;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
static P2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) Os_STCB = NULL_PTR;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
/*=======[I N T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/
#define OS_START_SEC_CODE
#include "Os_MemMap.h"

static FUNC(void, OS_CODE) Os_InitSchedTblCB(Os_ScheduleTableType StId);
static FUNC(void, OS_CODE) Os_InsertSTNode(Os_ScheduleTableType InsertStId);
static FUNC(void, OS_CODE) Os_DelStNode(ScheduleTableType DelStId);
static FUNC(Os_TickType, OS_CODE) Os_StGetEpDelay(
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStCfgRef,
    CONSTP2CONST(Os_STCBType volatile, AUTOMATIC, OS_VAR) pStNode);

#if (TRUE == CFG_ERRORHOOK)
static FUNC(void, OS_CODE) Os_StInnerErrHook(Os_ServiceIdType osServiceId, StatusType osErrCode);
#endif /* TRUE == CFG_ERRORHOOK */

static FUNC(void, OS_CODE) Os_StInnerStart(
    Os_TickType osStartAbsTick,
    CONSTP2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pStCB,
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStCfgRef);
static FUNC(void, OS_CODE)
    Os_StEpActiveTask(P2CONST(Os_EPActivateTaskAction, AUTOMATIC, OS_VAR) pTaskList, uint16 osTaskCnt);

#if (CFG_EXTENDED_TASK_MAX > 0)
static FUNC(void, OS_CODE)
    Os_StEpSetEvent(P2CONST(Os_EPSetEventAction, AUTOMATIC, OS_VAR) pEventList, uint16 osEventCnt);
#endif /* CFG_EXTENDED_TASK_MAX > 0 */

static FUNC(boolean, OS_CODE) Os_WorkStEpProc(
    CONSTP2CONST(Os_STCBType volatile, AUTOMATIC, OS_VAR) pStNode,
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStCfgRef);
static FUNC(void, OS_CODE) Os_WorkStRepeatProc(
    CONSTP2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pStNode,
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStCfgRef);
static FUNC(void, OS_CODE) Os_WorkStToNextEp(
    CONSTP2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pStNode,
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStCfgRef);

#if ((OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC))
static FUNC(void, OS_CODE) Os_StWorkEpSyncAdjust(
    CONSTP2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pStCB,
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStCfgRef,
    P2CONST(Os_CounterCfgType, AUTOMATIC, OS_VAR) pstCounterCfg);
#endif /* (OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC) */

static FUNC(void, OS_CODE) Os_WorkStRunningState(
    CONSTP2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pStNode,
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStCfgRef,
    P2CONST(Os_CounterCfgType, AUTOMATIC, OS_VAR) pstCounterCfg);

#if ((OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC))
static FUNC(void, OS_CODE) Os_WorkStRunningSyncState(
    CONSTP2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pStNode,
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStCfgRef);
#endif /* (OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC) */

#if ((OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC))
static FUNC(void, OS_CODE) Os_StWaittingStateProc(
    Os_TickType osValue,
    Os_TickType oscounterCurVal,
    CONSTP2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pStCB,
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStCfgRef);
static FUNC(void, OS_CODE) Os_StSyncGetDiffVal(
    Os_TickType SyncVal,
    Os_TickType oscounterCurVal,
    CONSTP2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pStCB,
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStCfgRef);
static FUNC(void, OS_CODE) Os_StRunningStateProc(
    Os_TickType SyncVal,
    Os_TickType oscounterCurVal,
    CONSTP2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pStCB,
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStCfgRef);
static FUNC(void, OS_CODE) Os_StRunningSyncStateProc(
    Os_TickType SyncVal,
    Os_TickType oscounterCurVal,
    CONSTP2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pStCB,
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStCfgRef);
#endif /* (OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC) */

static FUNC(void, OS_CODE) Os_InitStAutoStart(
    CONSTP2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pStCB,
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStCfgRef);
static FUNC(boolean, OS_CODE)
    Os_InitStAutoStartChk(P2CONST(Os_SchedTblAutostart, AUTOMATIC, OS_VAR) osSchedTblAutostartRef);

/*=======[F U N C T I O N   I M P L E M E N T A T I O N S]====================*/
/********************************************************************/
/* Begin: INNER API.                                                */
/********************************************************************/

/********************************************************************/
/*
 * Brief                <Init ScheduleTable during os_startup.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_InitSystem>
 * REQ ID               <DD_1_0854, DD_1_0855, DD_1_1402, DD_1_1416>
 */
/********************************************************************/
FUNC(void, OS_CODE) Os_InitScheduleTable(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Os_ScheduleTableType i;
    P2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pStCB;
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStCfgRef;
    VAR(Os_ScheduleTableType, OS_VAR) Os_CfgSchedTblMax;
    StatusType OsReturnErr = E_OK;

    switch (Os_SCB.sysCore)
    {
#if (CFG_SCHEDTBL_MAX_CORE0 > 0U)
    case 0:
        Os_SchedTblCfg = Os_SchedTblCfgCore0;
        Os_STCB = Os_STCBCore0;
        Os_CfgSchedTblMax = CFG_SCHEDTBL_MAX_CORE0;
        break;
#endif /* CFG_SCHEDTBL_MAX_CORE0 > 0U */

#if (CFG_SCHEDTBL_MAX_CORE1 > 0U)
    case 1:
        Os_SchedTblCfg = Os_SchedTblCfgCore1;
        Os_STCB = Os_STCBCore1;
        Os_CfgSchedTblMax = CFG_SCHEDTBL_MAX_CORE1;
        break;
#endif /* CFG_SCHEDTBL_MAX_CORE1 > 0U */

#if (CFG_SCHEDTBL_MAX_CORE2 > 0U)
    case 2:
        Os_SchedTblCfg = Os_SchedTblCfgCore2;
        Os_STCB = Os_STCBCore2;
        Os_CfgSchedTblMax = CFG_SCHEDTBL_MAX_CORE2;
        break;
#endif /* CFG_SCHEDTBL_MAX_CORE2 > 0U */

#if (CFG_SCHEDTBL_MAX_CORE3 > 0U)
    case 3:
        Os_SchedTblCfg = Os_SchedTblCfgCore3;
        Os_STCB = Os_STCBCore3;
        Os_CfgSchedTblMax = CFG_SCHEDTBL_MAX_CORE3;
        break;
#endif /* CFG_SCHEDTBL_MAX_CORE3 > 0U */

#if (CFG_SCHEDTBL_MAX_CORE4 > 0U)
    case 4:
        Os_SchedTblCfg = Os_SchedTblCfgCore4;
        Os_STCB = Os_STCBCore4;
        Os_CfgSchedTblMax = CFG_SCHEDTBL_MAX_CORE4;
        break;
#endif /* CFG_SCHEDTBL_MAX_CORE4 > 0U */

#if (CFG_SCHEDTBL_MAX_CORE5 > 0U)
    case 5:
        Os_SchedTblCfg = Os_SchedTblCfgCore5;
        Os_STCB = Os_STCBCore5;
        Os_CfgSchedTblMax = CFG_SCHEDTBL_MAX_CORE5;
        break;
#endif /* CFG_SCHEDTBL_MAX_CORE5 > 0U */

    /*add comments to pass QAC.*/
    default:
        OsReturnErr = E_NOT_OK;
        break;
    }

    if ((StatusType)E_OK == OsReturnErr)
    {
#if (CFG_SCHEDTBL_MAX > 0)
        for (i = 0U; i < Os_CfgSchedTblMax; i++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            pStCB = &Os_STCB[i];
            pStCfgRef = &Os_SchedTblCfg[i];

            Os_InitSchedTblCB(i);

            /* Auto start. */
            if (TRUE == Os_InitStAutoStartChk(pStCfgRef->osSchedTblAutostartRef))
            {
                Os_InitStAutoStart(pStCB, pStCfgRef);
            }
        }
#endif /* CFG_SCHEDTBL_MAX > 0 */
    }

    return;
}

/********************************************************************/
/*
 * Brief                <Os_InitStAutoStart.>
 * Service ID           <none>
 * Sync/Async           <none>
 * Reentrancy           <none>
 * param-eventId[in]    <pStCB, pStCfgRef>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_InitScheduleTable>
 * REQ ID               <DD_1_0944, DD_1_0945, DD_1_1423>
 */
/********************************************************************/
static FUNC(void, OS_CODE) Os_InitStAutoStart(
    CONSTP2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pStCB,
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStCfgRef)
{
    Os_TickType osStartAbsTick;
    Os_SchedTblAutostartType osType;
    P2VAR(Os_CCBType const volatile, AUTOMATIC, OS_VAR) pCcb;

    osType = pStCfgRef->osSchedTblAutostartRef->osSchedTblAutostartType;
    pCcb = &Os_CCB[pStCfgRef->osSchedTblCounterRef];

    switch (osType)
    {
    case ST_START_ABSOLUTE:
        Os_StInnerStart(pStCfgRef->osSchedTblAutostartRef->osSchedTblAbsValue, pStCB, pStCfgRef);

        /* Insert ScheduleTable to list. */
        Os_InsertSTNode(pStCB->stId);
        break;

    case ST_START_RELATIVE:
        osStartAbsTick = Os_CalcAbsTicks(
            pCcb->counterCurVal,
            pStCfgRef->osSchedTblAutostartRef->osSchedTblRelOffset,
            pStCfgRef->osSchedTblCounterRef);

        Os_StInnerStart(osStartAbsTick, pStCB, pStCfgRef);

        /* Insert ScheduleTable to list. */
        Os_InsertSTNode(pStCB->stId);
        break;

#if ((OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC))
    case ST_START_SYNCHRON:
        pStCB->stState = SCHEDULETABLE_WAITING;
        break;
#endif /* (OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC) */

    /*add comments to pass QAC.*/
    default:
        /* Nothing to do. */
        break;
    }

    return;
}

/********************************************************************/
/*
 * Brief                <Check whether this st can auto start.>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <None>
 * param-eventId[in]    <osSchedTblAutostartRef>
 * Param-Name[out]      <boolean>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_InitScheduleTable>
 * REQ ID               <DD_1_0946, DD_1_0947>
 */
/********************************************************************/
static FUNC(boolean, OS_CODE)
    Os_InitStAutoStartChk(P2CONST(Os_SchedTblAutostart, AUTOMATIC, OS_VAR) osSchedTblAutostartRef)
{
    boolean bAutoStart = FALSE;

    if (NULL_PTR != osSchedTblAutostartRef)
    {
        /* Check whether appmode during StartOs in appmode bitmap. */
        if (0U != (osSchedTblAutostartRef->osSchedTblAppModeBitmap & Os_SCB.sysActiveAppMode))
        {
            bAutoStart = TRUE;
        }
    }

    return bAutoStart;
}

/********************************************************************/
/*
 * Brief                <Init ScheduleTable.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * param-eventId[in]    <StId>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_InitScheduleTable and so on>
 * REQ ID               <DD_1_0948, DD_1_0949, DD_1_1440>
 */
/********************************************************************/
static FUNC(void, OS_CODE) Os_InitSchedTblCB(Os_ScheduleTableType StId)
{
    P2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pStCB;
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStCfgRef;

    pStCB = &Os_STCB[StId];
    pStCfgRef = &Os_SchedTblCfg[StId];

    /* Init STCB */
    pStCB->stId = StId;
    pStCB->stIsAdjust = FALSE;
    pStCB->stIsAdjAdd = FALSE;
    pStCB->stIsStarted = FALSE;
    pStCB->stIsStopAdjust = FALSE;
    pStCB->stNextEP = pStCfgRef->osSchedTblEP;
    pStCB->stDiff = 0U;
    pStCB->stDev = 0U;
    pStCB->stStartAbsTick = 0U;
    pStCB->stNextEpAbsTick = 0U;
    pStCB->stState = SCHEDULETABLE_STOPPED;
    pStCB->stEpId = 0U;
    pStCB->NextStID = OS_SCHEDTABLE_INVALID;
    pStCB->PrevStID = OS_SCHEDTABLE_INVALID;
    pStCB->stNextNode = NULL_PTR;
    pStCB->stPreNode = NULL_PTR;

    pStCB->stFinalDelay =
        pStCfgRef->osSchedTblDuration - pStCfgRef->osSchedTblEP[pStCfgRef->osSchedTblEPsize - 1u].osSchedTblEPOffset;

    pStCB->stDelay = Os_StGetEpDelay(pStCfgRef, pStCB);

    return;
}

/********************************************************************/
/*
 * Brief                <Insert scheduleTable node to list(Array).>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * param-eventId[in]    <ScheduleTableID>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_InitStAutoStart and so on>
 * REQ ID               <DD_1_0950, DD_1_0951>
 */
/********************************************************************/
static FUNC(void, OS_CODE) Os_InsertSTNode(Os_ScheduleTableType InsertStId)
{
    Os_TickType InsertStEpRelTick;
    Os_CounterType stCounterId;
    P2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pInsertStCB;
    P2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pCurStCB;
    P2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pPreStCB;
    P2VAR(Os_CCBType volatile, AUTOMATIC, OS_VAR) pCcb;

    pInsertStCB = &Os_STCB[InsertStId];
    stCounterId = Os_SchedTblCfg[InsertStId].osSchedTblCounterRef;
    pCcb = &Os_CCB[stCounterId];

    /* Note: can not repeat insert. */
    if ((NULL_PTR != pInsertStCB->stNextNode) || (NULL_PTR != pInsertStCB->stPreNode))
    {
        /*nothing to do*/
    }
    /* Flexible design: if list is empty, insert node directly. */
    else if (NULL_PTR == pCcb->counterStListHead)
    {
        pInsertStCB->stNextNode = NULL_PTR;
        pCcb->counterStListHead = pInsertStCB;
    }
    else
    {
        /* If list is not empty, insert node by EP rel tick, increase order.
         * Modified, use relative ticks between current tick and EP*/
        /* PRQA S 0404++ */ /* MISRA Rule 1.3,13.2 */
        InsertStEpRelTick = Os_GetDistance(pCcb->counterLastVal, pInsertStCB->stNextEpAbsTick, stCounterId);
        /* PRQA S 0404-- */ /* MISRA Rule 1.3,13.2 */

        pCurStCB = pCcb->counterStListHead;
        pPreStCB = NULL_PTR;

        /* Find insert position. */
        while (NULL_PTR != pCurStCB)
        {
            /* Insert node by increase order. */
            /* PRQA S 0404++ */ /* MISRA Rule 1.3,13.2 */
            if (InsertStEpRelTick >= Os_GetDistance(pCcb->counterLastVal, pCurStCB->stNextEpAbsTick, stCounterId))
            /* PRQA S 0404-- */ /* MISRA Rule 1.3,13.2 */
            {
                pPreStCB = pCurStCB;
                pCurStCB = pCurStCB->stNextNode;
            }
            else
            {
                break;
            }
        }

        /* Insert to head position. */
        if (NULL_PTR == pPreStCB)
        {
            /* Update head node. */
            pCcb->counterStListHead = pInsertStCB;

            pInsertStCB->stNextNode = pCurStCB;
            pInsertStCB->stPreNode = NULL_PTR;
            pCurStCB->stPreNode = pInsertStCB;
        }
        else
        {
            /* Insert to other position. */
            pInsertStCB->stNextNode = pPreStCB->stNextNode;
            pInsertStCB->stPreNode = pPreStCB;

            pPreStCB->stNextNode = pInsertStCB;

            /* Process pCurStCB. */
            if (NULL_PTR != pCurStCB)
            {
                pCurStCB->stPreNode = pInsertStCB;
            }
        }
    }

    return;
}

/********************************************************************/
/*
 * Brief                <Insert scheduleTable node to list(Array).>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * param-eventId[in]    <ScheduleTableID>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_WorkStRepeatProc and so on>
 * REQ ID               <DD_1_0952, DD_1_0953>
 */
/********************************************************************/
static FUNC(void, OS_CODE) Os_DelStNode(ScheduleTableType DelStId)
{
    Os_CounterType stCounterId;
    P2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pDelStCB;
    P2VAR(Os_CCBType volatile, AUTOMATIC, OS_VAR) pCcb;

    stCounterId = Os_SchedTblCfg[DelStId].osSchedTblCounterRef;
    pCcb = &Os_CCB[stCounterId];

    /* If list is null, return. */
    if (NULL_PTR == pCcb->counterStListHead)
    {
        /*nothing to do*/
    }
    else
    {
        pDelStCB = &(Os_STCB[DelStId]);

        /* Flexible design: DelStId is head node. */
        if (NULL_PTR == pDelStCB->stPreNode)
        {
            pCcb->counterStListHead = pDelStCB->stNextNode;

            if (NULL_PTR != pDelStCB->stNextNode)
            {
                pDelStCB->stNextNode->stPreNode = NULL_PTR;
                pDelStCB->stNextNode = NULL_PTR;
            }
        }
        else
        {
            /* Normal delete. */
            pDelStCB->stPreNode->stNextNode = pDelStCB->stNextNode;

            if (NULL_PTR != pDelStCB->stNextNode) /* Not tail node. */
            {
                pDelStCB->stNextNode->stPreNode = pDelStCB->stPreNode;
            }

            pDelStCB->stPreNode = NULL_PTR;
        }
    }

    return;
}

/********************************************************************/
/*
 * Brief                <Insert scheduleTable node to list(Array)>
 * Service ID           <none>
 * Sync/Async           <none>
 * Reentrancy           <none>
 * param-eventId[in]    <pStCfgRef,pStNode>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_InitSchedTblCB>
 * REQ ID               <DD_1_0954, DD_1_0955>
 */
/********************************************************************/
/* Misrac: Msg(2:3408) 'Os_StGetEpDelay' has external linkage and is being defined without any
 *         previous declaration.
 * Note: Os_StGetEpDelay is called in this c file, no external linkage. */
/* Misrac: Msg(2:3673) The object addressed by the pointer parameter 'pStNode' is not modified
 *         and so the pointer could be of type 'pointer to const'.
 * Note: Os_STCB is not const type. */
/* Misrac: Msg(2:0491) Array subscripting applied to an object of pointer type.
 * Note: osSchedTblEP is defined as array. Ep number is variable, so osSchedTblEP must be used
 *       like below. */
static FUNC(Os_TickType, OS_CODE) Os_StGetEpDelay(
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStCfgRef,
    CONSTP2CONST(Os_STCBType volatile, AUTOMATIC, OS_VAR) pStNode)
{
    Os_TickType osDelay;

    /* Last Ep. Figure 7.1 */
    if (pStNode->stEpId >= (pStCfgRef->osSchedTblEPsize - 1u))
    {
        osDelay = pStNode->stFinalDelay + pStCfgRef->osSchedTblEP[0].osSchedTblEPOffset;
    }
    else
    {
        osDelay = pStCfgRef->osSchedTblEP[pStNode->stEpId + 1u].osSchedTblEPOffset
                  - pStCfgRef->osSchedTblEP[pStNode->stEpId].osSchedTblEPOffset;
    }

    return osDelay;
}

/********************************************************************/
/*
 * Brief                <Error hook.>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <Non Reentrant>
 * param-eventId[in]    <osServiceId, osErrCode>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <GetScheduleTableStatus and so on>
 * REQ ID               <DD_1_0956, DD_1_0957>
 */
/********************************************************************/
#if (TRUE == CFG_ERRORHOOK)
/* PRQA S 3206++ */ /* MISRA Rule 2.7 */
static FUNC(void, OS_CODE) Os_StInnerErrHook(Os_ServiceIdType osServiceId, StatusType osErrCode)
/* PRQA S 3206-- */ /* MISRA Rule 2.7 */
{
#if (TRUE == CFG_USEGETSERVICEID)
    OS_ARCH_DECLARE_CRITICAL();
#endif
    OSError_Save_ServiceId(osServiceId);

#if (TRUE == CFG_ERRORHOOK)
    Os_CallErrorHook(osErrCode);
#endif /* TRUE == CFG_ERRORHOOK */

    return;
}
#endif /* TRUE == CFG_ERRORHOOK */

/********************************************************************/
/*
 * Brief                <Save start para of schedule table.>
 * Service ID           <none>
 * Sync/Async           <none>
 * Reentrancy           <none>
 * param-eventId[in]    <osStartAbsTick, osCounterMaxVal, pStCB, pStCfgRef>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_InitStAutoStart and so on>
 * REQ ID               <DD_1_0958, DD_1_0959, DD_1_1434>
 */
/********************************************************************/
static FUNC(void, OS_CODE) Os_StInnerStart(
    Os_TickType osStartAbsTick,
    CONSTP2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pStCB,
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStCfgRef)
{
    Os_CounterType stCounterId;
    stCounterId = pStCfgRef->osSchedTblCounterRef;
    pStCB->stStartAbsTick = osStartAbsTick;
    pStCB->stNextEpAbsTick =
        Os_CalcAbsTicks(pStCB->stStartAbsTick, pStCfgRef->osSchedTblEP[0].osSchedTblEPOffset, stCounterId);

    pStCB->stEpId = 0u;
    pStCB->stIsStarted = TRUE;

    /* Set state to running. */
    pStCB->stState = SCHEDULETABLE_RUNNING;

/* If SyncStrategy is IMPLICIT, state should be RUNNING_AND_SYNCHRONOUS. */
#if ((OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC))
    if (ST_SYNC_IMPLICIT == pStCfgRef->osSchedTblSync.osSchedTblSyncStrategy)
    {
        pStCB->stState = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
    }
#endif /* (OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC) */

    return;
}

/********************************************************************/
/*
 * Brief                <Activate tasks at expiry points>
 * Service ID           <none>
 * Sync/Async           <none>
 * Reentrancy           <none>
 * param-eventId[in]    <pTaskList, osTaskCnt>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_WorkStEpProc>
 * REQ ID               <DD_1_0960, DD_1_0961, DD_1_1417>
 */
/********************************************************************/
static FUNC(void, OS_CODE)
    Os_StEpActiveTask(P2CONST(Os_EPActivateTaskAction, AUTOMATIC, OS_VAR) pTaskList, uint16 osTaskCnt)
{
    uint16 i;

    for (i = 0u; i < osTaskCnt; i++)
    {
        (void)ActivateTask(pTaskList[i].osSchedTblActivateTaskRef);
    }

    return;
}

#if (CFG_EXTENDED_TASK_MAX > 0)
/********************************************************************/
/*
 * Brief                <Set Event at expiry points>
 * Service ID           <none>
 * Sync/Async           <none>
 * Reentrancy           <none>
 * param-eventId[in]    <pEventList, osEventCnt>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_WorkStEpProc>
 * REQ ID               <DD_1_0962, DD_1_0963, DD_1_1427>
 */
/********************************************************************/
static FUNC(void, OS_CODE)
    Os_StEpSetEvent(P2CONST(Os_EPSetEventAction, AUTOMATIC, OS_VAR) pEventList, uint16 osEventCnt)
{
    uint16 i;

    for (i = 0u; i < osEventCnt; i++)
    {
        (void)SetEvent(pEventList[i].osSchedTblSetEventTaskRef, pEventList[i].osSchedTblSetEventRef);
    }

    return;
}
#endif /* #if (CFG_EXTENDED_TASK_MAX > 0) */

/********************************************************************/
/*
 * Brief                <Procedures for handling at expiry points>
 * Service ID           <none>
 * Sync/Async           <none>
 * Reentrancy           <none>
 * param-eventId[in]    <pStNode, pStCfgRef>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_WorkStRunningState>
 * REQ ID               <DD_1_0964, DD_1_0965, DD_1_1366, DD_1_1408>
 */
/********************************************************************/
static FUNC(boolean, OS_CODE) Os_WorkStEpProc(
    CONSTP2CONST(Os_STCBType volatile, AUTOMATIC, OS_VAR) pStNode,
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStCfgRef)
{
    boolean LastEP = FALSE;
    /* Active task. */
    Os_StEpActiveTask(pStNode->stNextEP->osActivateTaskList, pStNode->stNextEP->osActivateTaskListSize);

/* Set event. */
#if (CFG_EXTENDED_TASK_MAX > 0)
    Os_StEpSetEvent(pStNode->stNextEP->osSetEventList, pStNode->stNextEP->osSetEventListSize);
#endif /* CFG_EXTENDED_TASK_MAX > 0 */

    /* Last EP ? */
    if (pStNode->stEpId >= (pStCfgRef->osSchedTblEPsize - 1u))
    {
        LastEP = TRUE;
    }

    return LastEP;
}

/********************************************************************/
/*
 * Brief                <A schedule table may repeat after the final expiry point is processed.
 *                       So the API can work>
 * Service ID           <none>
 * Sync/Async           <none>
 * Reentrancy           <none>
 * param-eventId[in]    <counterCurval, pStNode, pStCfgRef, pstCounterCfg>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_WorkStRunningState>
 * REQ ID               <DD_1_0966, DD_1_0967>
 */
/********************************************************************/
static FUNC(void, OS_CODE) Os_WorkStRepeatProc(
    CONSTP2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pStNode,
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStCfgRef)
{
    pStNode->stNextEP = pStCfgRef->osSchedTblEP;
    pStNode->stEpId = 0u;

/* Update start abs tick. */
#if ((OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC))
    if (ST_SYNC_IMPLICIT == pStCfgRef->osSchedTblSync.osSchedTblSyncStrategy)
    {
        pStNode->stStartAbsTick = 0u;
        pStNode->stNextEpAbsTick = pStCfgRef->osSchedTblEP[0].osSchedTblEPOffset;
    }
    else
#endif                      /* (OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC) */
    {
        /* PRQA S 0404++ */ /* MISRA Rule 1.3,13.2 */
        pStNode->stNextEpAbsTick =
            Os_CalcAbsTicks(pStNode->stNextEpAbsTick, pStNode->stDelay, pStCfgRef->osSchedTblCounterRef);
        /* PRQA S 0404-- */ /* MISRA Rule 1.3,13.2 */

        pStNode->stDelay = Os_StGetEpDelay(pStCfgRef, pStNode);
    }

    /* Re-sort by abs tick of next EP. */
    Os_DelStNode(pStNode->stId);
    Os_InsertSTNode(pStNode->stId);

    return;
}

/********************************************************************/
/*
 * Brief                <Procedures for handling the next expiry point>
 * Service ID           <none>
 * Sync/Async           <none>
 * Reentrancy           <none>
 * param-eventId[in]    <pStNode, pStCfgRef>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_WorkStRunningState>
 * REQ ID               <DD_1_0968, DD_1_0969>
 */
/********************************************************************/
static FUNC(void, OS_CODE) Os_WorkStToNextEp(
    CONSTP2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pStNode,
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStCfgRef)
{
    /* Next EP. */
    pStNode->stEpId = pStNode->stEpId + 1u; /*pStNode->stEpId++;*/
    pStNode->stNextEP = &pStCfgRef->osSchedTblEP[pStNode->stEpId];

    /* PRQA S 0404++ */ /* MISRA Rule 1.3,13.2 */
    pStNode->stNextEpAbsTick =
        Os_CalcAbsTicks(pStNode->stNextEpAbsTick, pStNode->stDelay, pStCfgRef->osSchedTblCounterRef);
    /* PRQA S 0404-- */ /* MISRA Rule 1.3,13.2 */

    /* Update delay. */
    pStNode->stDelay = Os_StGetEpDelay(pStCfgRef, pStNode);

    return;
}

/* Sync adjust. */
#if ((OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC))
/********************************************************************/
/*
 * Brief                <The API can use When expiry point need synchronization>
 * Service ID           <none>
 * Sync/Async           <none>
 * Reentrancy           <none>
 * param-eventId[in]    <pStCfgRef, pstCounterCfg>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <pStCB>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_WorkStRunningState>
 * REQ ID               <DD_1_0970, DD_1_0971, DD_1_1418, DD_1_1419, DD_1_1447>
 */
/********************************************************************/
static FUNC(void, OS_CODE) Os_StWorkEpSyncAdjust(
    CONSTP2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pStCB,
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStCfgRef,
    P2CONST(Os_CounterCfgType, AUTOMATIC, OS_VAR) pstCounterCfg)
{
    Os_TickType osPreEpOffset;

    /* Offset of pre EP. */
    osPreEpOffset = ((0u == pStCB->stEpId) ? (0u) : (pStCfgRef->osSchedTblEP[pStCB->stEpId - 1u].osSchedTblEPOffset));

    /* Delay + Deviatifon. */
    if (TRUE == pStCB->stIsAdjAdd)
    {
        /* OS437 */
        if (((pStCB->stNextEP->osSchedTblEPOffset) + (pStCB->stNextEP->osSchedTblMaxAdvance))
            > (pStCfgRef->osSchedTblDuration))
        {
            /*nothing to do*/
        }
        else
        {
            /* Deviatifon. */
            pStCB->stDev =
                (((pStCB->stDiff - pStCB->stAdjDevTotal) > pStCB->stNextEP->osSchedTblMaxAdvance)
                     ? (pStCB->stNextEP->osSchedTblMaxAdvance)
                     : (pStCB->stDiff - pStCB->stAdjDevTotal));

            /* pStCB->stAdjDevTotal <= pStCB->stDiff. */
            /* PRQA S 0404++ */ /* MISRA Rule 1.3,13.2 */
            if ((pStCB->stDiff - pStCB->stAdjDevTotal) <= pStCfgRef->osSchedTblSync.osSchedTblExplicitPrecision)
            /* PRQA S 0404-- */ /* MISRA Rule 1.3,13.2 */
            {
                /* Sync success. */
                pStCB->stIsAdjust = FALSE;
                pStCB->stAdjDevTotal = 0u;
                pStCB->stDiff = 0u;
                pStCB->stDev = 0u;
            }
            else
            {
                /* stNextEP need adjust. */
                pStCB->stIsAdjust = TRUE;
                pStCB->stAdjDevTotal += pStCB->stDev;

                /* Update delay of stNextEP. */
                pStCB->stDelay += pStCB->stDev;
            }
        }
    }
    else /* Delay - Deviatifon. */
    {
        /* OS436 */
        if (((pStCB->stNextEP->osSchedTblEPOffset) - (pStCB->stNextEP->osSchedTblMaxRetard))
            < ((osPreEpOffset) + (pstCounterCfg->osCounterMinCycle)))
        {
            /*nothing to do*/
        }
        else
        {
            /* Deviatifon. */
            pStCB->stDev =
                (((pStCB->stDiff - pStCB->stAdjDevTotal) > pStCB->stNextEP->osSchedTblMaxRetard)
                     ? (pStCB->stNextEP->osSchedTblMaxRetard)
                     : (pStCB->stDiff - pStCB->stAdjDevTotal));

            /* pStCB->stAdjDevTotal <= pStCB->stDiff. */
            /* PRQA S 0404++ */ /* MISRA Rule 1.3,13.2 */
            if ((pStCB->stDiff - pStCB->stAdjDevTotal) <= pStCfgRef->osSchedTblSync.osSchedTblExplicitPrecision)
            /* PRQA S 0404-- */ /* MISRA Rule 1.3,13.2 */
            {
                /* Sync success. */
                pStCB->stIsAdjust = FALSE;
                pStCB->stAdjDevTotal = 0u;
            }
            else
            {
                /* stNextEP need adjust. */
                pStCB->stIsAdjust = TRUE;
                pStCB->stAdjDevTotal += pStCB->stDev;

                /* Update delay of stNextEP. */
                pStCB->stDelay -= pStCB->stDev;
            }
        }
    }

    return;
}
#endif /* #if ((OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC)) */

/********************************************************************/
/*
 * Brief                <Os_WorkStRunningState.>
 * Service ID           <none>
 * Sync/Async           <none>
 * Reentrancy           <none>
 * param-eventId[in]    <counterCurval, pStNode, pStCfgRef, pstCounterCfg>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_WorkSchedTbl>
 * REQ ID               <DD_1_0972, DD_1_0973, DD_1_1449, DD_1_1398, DD_1_1446>
 */
/********************************************************************/
static FUNC(void, OS_CODE) Os_WorkStRunningState(
    CONSTP2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pStNode,
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStCfgRef,
    P2CONST(Os_CounterCfgType, AUTOMATIC, OS_VAR) pstCounterCfg)
{
    boolean osIsLastEp;

    osIsLastEp = Os_WorkStEpProc(pStNode, pStCfgRef);

/* Sync: adjust. */
#if ((OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC))
    if ((FALSE == pStNode->stIsStopAdjust) && (TRUE == pStNode->stIsAdjust))
    {
        Os_StWorkEpSyncAdjust(pStNode, pStCfgRef, pstCounterCfg);

        if (TRUE != pStNode->stIsAdjust)
        {
            pStNode->stState = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
        }
    }
#endif /* (OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC) */

    /* Last EP. */
    if (TRUE == osIsLastEp)
    {
        /* Repeating. */
        /* Note: in standard, from 7.3.2.4 && Figure 7.8, we conclude that a schedule table which can synchronous
           explicitly might be repeating. But we can not conclude that explicit synchronous schedule table must be
           repeating, because there is a next state in Figure7.5. */
        if (TRUE == pStCfgRef->osSchedTblRepeating)
        {
            Os_WorkStRepeatProc(pStNode, pStCfgRef);
        }
        else
        {
            /* If has next schedule table, set state of schedule table to SCHEDULETABLE_RUNNING. */
            if (OS_SCHEDTABLE_INVALID != pStNode->NextStID)
            {
                Os_STCB[pStNode->NextStID].stState = SCHEDULETABLE_RUNNING;
            }

            /* Non-repeating, delete from list. */
            Os_DelStNode(pStNode->stId);
            Os_InitSchedTblCB(pStNode->stId);
        }
    }
    else
    {
        Os_WorkStToNextEp(pStNode, pStCfgRef);

        /* Re-sort by abs tick of next EP. */
        Os_DelStNode(pStNode->stId);
        Os_InsertSTNode(pStNode->stId);
    }

    return;
}

/********************************************************************/
/*
 * Brief                <The API will call after schedule table synchronization success>
 * Service ID           <none>
 * Sync/Async           <none>
 * Reentrancy           <none>
 * param-eventId[in]    <counterCurval, pStNode, pStCfgRef, pstCounterCfg>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_WorkSchedTbl>
 * REQ ID               <DD_1_0974, DD_1_0975, DD_1_1450, DD_1_1399, DD_1_1430>
 */
/********************************************************************/
#if ((OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC))
static FUNC(void, OS_CODE) Os_WorkStRunningSyncState(
    CONSTP2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pStNode,
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStCfgRef)
{
    boolean osIsLastEp;

    osIsLastEp = Os_WorkStEpProc(pStNode, pStCfgRef);
    if (TRUE == osIsLastEp)
    {
        if (TRUE == pStCfgRef->osSchedTblRepeating)
        {
            Os_WorkStRepeatProc(pStNode, pStCfgRef);
        }
        else
        {
            if (ST_SYNC_EXPLICIT == pStCfgRef->osSchedTblSync.osSchedTblSyncStrategy)
            {
                if (OS_SCHEDTABLE_INVALID != pStNode->NextStID)
                {
                    Os_STCB[pStNode->NextStID].stState = SCHEDULETABLE_RUNNING;
                }
            }
            else if (ST_SYNC_IMPLICIT == pStCfgRef->osSchedTblSync.osSchedTblSyncStrategy)
            {
                if (OS_SCHEDTABLE_INVALID != pStNode->NextStID)
                {
                    Os_STCB[pStNode->NextStID].stState = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
                }
            }
            else
            {
                /* nothing to do. */
            }
            /* Non-repeating, delete from list. */
            Os_DelStNode(pStNode->stId);
            Os_InitSchedTblCB(pStNode->stId);
        }
    }
    else
    {
        Os_WorkStToNextEp(pStNode, pStCfgRef);

        /* Re-sort by abs tick of next EP. */
        Os_DelStNode(pStNode->stId);
        Os_InsertSTNode(pStNode->stId);
    }

    return;
}
#endif /* (OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC) */

/* ScheduleTable Sync. */
#if ((OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC))

/********************************************************************/
/*
 * Brief                <Sync ScheduleTable: Proc waitting state.>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <Non Reentrant>
 * param-eventId[in]    <SyncVal, oscounterCurVal, pStCB, pStCfgRef, pCounterCfgType>
 * Param-Name[out]      <StatusType>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <SyncScheduleTable>
 * REQ ID               <DD_1_0976, DD_1_0977, DD_1_1439, DD_1_1432>
 */
/********************************************************************/
static FUNC(void, OS_CODE) Os_StWaittingStateProc(
    Os_TickType osValue,
    Os_TickType oscounterCurVal,
    CONSTP2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pStCB,
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStCfgRef)
{
    /* Save start Abs tick: Now + (Duration - value). */
    pStCB->stStartAbsTick =
        Os_CalcAbsTicks(oscounterCurVal, (pStCfgRef->osSchedTblDuration - osValue), pStCfgRef->osSchedTblCounterRef);

    pStCB->stNextEpAbsTick = Os_CalcAbsTicks(
        pStCB->stStartAbsTick,
        pStCfgRef->osSchedTblEP[0].osSchedTblEPOffset,
        pStCfgRef->osSchedTblCounterRef);

    /* Set state to SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS. */
    pStCB->stState = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;

    /* Insert to list. */
    Os_InsertSTNode(pStCB->stId);

    return;
}

/******************************************************************************/
/*
 * Brief                <The API can get difference value when schedule table need Sync>
 *
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param[in]            <SyncVal, oscounterCurVal, pStCB, pStCfgRef>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <Os_StRunningStateProc and so on>
 * REQ ID               <DD_1_0978, DD_1_0979, DD_1_1426>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_StSyncGetDiffVal(
    Os_TickType SyncVal,
    Os_TickType oscounterCurVal,
    CONSTP2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pStCB,
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStCfgRef)
{
    Os_TickType osDiff;
    Os_TickType osPosOnTbl;

    /* Position on Tbl. */
    osPosOnTbl = Os_GetDistance(oscounterCurVal, pStCB->stNextEpAbsTick, pStCfgRef->osSchedTblCounterRef);

    if (pStCB->stNextEP->osSchedTblEPOffset >= osPosOnTbl)
    {
        osPosOnTbl = pStCB->stNextEP->osSchedTblEPOffset - osPosOnTbl;
    }
    else
    {
        osPosOnTbl = (pStCB->stNextEP->osSchedTblEPOffset - osPosOnTbl) + pStCfgRef->osSchedTblDuration - 1u;
    }

    /* Deviation: added. */
    if (osPosOnTbl >= SyncVal)
    {
        osDiff = osPosOnTbl - SyncVal;

        pStCB->stIsAdjAdd = TRUE;
    }
    else /* Deviation: subtracted. */
    {
        osDiff = SyncVal - osPosOnTbl;

        pStCB->stIsAdjAdd = FALSE;
    }

    pStCB->stDiff = osDiff;

    return;
}

/********************************************************************/
/*
 * Brief                <Sync ScheduleTable: Proc running state.>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <Non Reentrant>
 * param-eventId[in]    <SyncVal, oscounterCurVal, pStCB, pStCfgRef, pCounterCfgType>
 * Param-Name[out]      <StatusType>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <SyncScheduleTable>
 * REQ ID               <DD_1_0980, DD_1_0981, DD_1_1400, DD_1_1425, DD_1_1428, DD_1_1444>
 */
/********************************************************************/
static FUNC(void, OS_CODE) Os_StRunningStateProc(
    Os_TickType SyncVal,
    Os_TickType oscounterCurVal,
    CONSTP2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pStCB,
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStCfgRef)
{
    /* Get diff value. */
    Os_StSyncGetDiffVal(SyncVal, oscounterCurVal, pStCB, pStCfgRef);

    /* No need sync. */
    if (pStCB->stDiff <= pStCfgRef->osSchedTblSync.osSchedTblExplicitPrecision)
    {
        pStCB->stState = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
        pStCB->stIsAdjust = FALSE;
    }
    else
    {
        /* Need sync. */
        pStCB->stIsAdjust = TRUE;

        /* OS362 */
        pStCB->stIsStopAdjust = FALSE;

        /* Re-sort. */
        Os_DelStNode(pStCB->stId);
        Os_InsertSTNode(pStCB->stId);
    }

    return;
}

/********************************************************************/
/*
 * Brief                <Sync ScheduleTable: Proc running and sync state.>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <Non Reentrant>
 * param-eventId[in]    <SyncVal, oscounterCurVal, pStCB, pStCfgRef, pCounterCfgType>
 * Param-Name[out]      <StatusType>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <SyncScheduleTable>
 * REQ ID               <DD_1_0982, DD_1_0983, DD_1_1401>
 */
/********************************************************************/
static FUNC(void, OS_CODE) Os_StRunningSyncStateProc(
    Os_TickType SyncVal,
    Os_TickType oscounterCurVal,
    CONSTP2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pStCB,
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStCfgRef)
{
    /* Get diff value. */
    Os_StSyncGetDiffVal(SyncVal, oscounterCurVal, pStCB, pStCfgRef);

    /* No need sync. */
    if (pStCB->stDiff <= pStCfgRef->osSchedTblSync.osSchedTblExplicitPrecision)
    {
        pStCB->stIsAdjust = FALSE;
    }
    else
    {
        /* Need sync. */
        pStCB->stIsAdjust = TRUE;

        /* OS362 */
        pStCB->stIsStopAdjust = FALSE;

        pStCB->stState = SCHEDULETABLE_RUNNING;

        /* Re-sort. */
        Os_DelStNode(pStCB->stId);
        Os_InsertSTNode(pStCB->stId);
    }

    return;
}

#endif /* #if ((OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC)) */

/********************************************************************/
/*
 * Brief                <Os_WorkSchedTbl.>
 * Service ID           <none>
 * Sync/Async           <none>
 * Reentrancy           <none>
 * param-eventId[in]    <CounterID>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_IncrementHardCounter and so on>
 * REQ ID               <DD_1_0856, DD_1_0857, DD_1_1412, DD_1_1415, DD_1_1422>
 */
/********************************************************************/
FUNC(void, OS_CODE) Os_WorkSchedTbl(Os_CounterType CounterID) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Os_TickType counterCurval;
    P2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pstListHead;
    P2VAR(Os_CCBType const volatile, AUTOMATIC, OS_VAR) pCcb;
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStCfgRef;
    P2CONST(Os_CounterCfgType, AUTOMATIC, OS_VAR) pstCounterCfg;
    OS_ARCH_DECLARE_CRITICAL();

#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
    Os_ApplicationType bakappID;
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */

    OS_ARCH_ENTRY_CRITICAL();
    pCcb = &Os_CCB[CounterID];
    if (NULL_PTR == pCcb->counterStListHead)
    {
        /*nothing to do*/
    }
    else
    {
        pstListHead = pCcb->counterStListHead;
        pstCounterCfg = &Os_CounterCfg[CounterID];
        counterCurval = Os_CCB[CounterID].counterCurVal;

/* Process each SchedTbl(EP) which is reach the offset. */
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
        bakappID = Os_SCB.sysRunningAppID;
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */
        /* More then one EP may have same tick value. */
        while (NULL_PTR != pstListHead)
        {
            /* PRQA S 0404++ */ /* MISRA Rule 1.3,13.2 */
            if (Os_GetDistance(pstListHead->stNextEpAbsTick, counterCurval, CounterID)
                > pstCounterCfg->osCounterMaxAllowedValue)
            /* PRQA S 0404-- */ /* MISRA Rule 1.3,13.2 */
            {
                break;
            }
            pStCfgRef = &Os_SchedTblCfg[pstListHead->stId];
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
            Os_SCB.sysRunningAppID = Os_ObjectAppCfg[OBJECT_SCHEDULETABLE][pstListHead->stId].hostApp;
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */
            /* EP process by different state. */
            switch (pstListHead->stState)
            {
            case SCHEDULETABLE_RUNNING:
                Os_WorkStRunningState(pstListHead, pStCfgRef, pstCounterCfg);
                break;

#if ((OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC))
            case SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS:
                Os_WorkStRunningSyncState(pstListHead, pStCfgRef);
                break;
#endif /* (OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC) */

            /*add comments to pass QAC.*/
            default:
                /* Nothing to do. */
                break;
            }

            pstListHead = pCcb->counterStListHead;
        }

#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
        Os_SCB.sysRunningAppID = bakappID;
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */
    }
    OS_ARCH_EXIT_CRITICAL();

    return;
}

/********************************************************************/
/* END: INNER API.                                                  */
/********************************************************************/

/********************************************************************/
/* BEGIN: SYSTEM SERVICE.                                           */
/********************************************************************/

/********************************************************************/
/*
 * Brief                <GetScheduleTableStatus.>
 * Service ID           <OSServiceId_GetScheduleTableStatus>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Yes>
 * param-eventId[in]    <ScheduleTableID, ScheduleStatus>
 * Param-Name[out]      <StatusType>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * REQ ID               <DD_1_0514, DD_1_1034, DD_1_0520:(1), DD_1_1390, DD_1_1406, DD_1_1441,
 *                       DD_1_1442, DD_1_1443, DD_1_1445, DD_1_1448, DD_1_0522:(1), DD_1_1587,
 *                       DD_1_0522, DD_1_1668>
 */
/********************************************************************/
/* PRQA S 1532++ */ /* MISRA Rule 8.7 */
FUNC(StatusType, OS_CODE)
GetScheduleTableStatus(ScheduleTableType ScheduleTableID, ScheduleTableStatusRefType ScheduleStatus)
/* PRQA S 1532-- */ /* MISRA Rule 8.7 */
{
    OS_ARCH_DECLARE_CRITICAL();

#if (OS_AUTOSAR_CORES > 1)
    Os_CoreIdType coreId;
#endif /* OS_AUTOSAR_CORES > 1 */
    P2VAR(Os_STCBType const volatile, AUTOMATIC, OS_VAR) pStCB;
    StatusType OsReturnErr = E_OK;
    OS_GSTS_ENTRY();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    if (Os_WrongContext(OS_CONTEXT_GET_SCHEDULE_TABLE_STATUS) != TRUE)
    {
        OsReturnErr = E_OS_CALLEVEL;
    }
    else if (Os_AddressWritable((uint8*)ScheduleStatus) != TRUE)
    {
        OsReturnErr = E_OS_ILLEGAL_ADDRESS;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        OsReturnErr = E_OS_DISABLEDINT;
    }
    else if (Os_CheckObjAcs(OBJECT_SCHEDULETABLE, ScheduleTableID) != TRUE)
    {
        OsReturnErr = E_OS_ACCESS;
    }
    else
#endif /* (TRUE == CFG_SERVICE_PROTECTION_ENABLE) */
    {
/* SWS_Os_00647:The API service "GetScheduleTableStatus" shall
 * be able to get the status of a schedule table that is part
 * of an OS-Application residing on a different core.  */
#if (OS_AUTOSAR_CORES > 1)
        coreId = Os_GetObjCoreId(ScheduleTableID);
        if (coreId != Os_SCB.sysCore)
        {
            if (Os_CoreCB.coreStatus[coreId] != OS_RUN)
            {
                OsReturnErr = E_OS_CORE;
            }
            else
            {
                OS_ARCH_ENTRY_CRITICAL();
                Os_InterCore[Os_SCB.sysCore].interState = E_NOT_OK;
                Os_InterCore[Os_SCB.sysCore].serviceId = OSServiceId_GetScheduleTableStatus;
                Os_InterCore[Os_SCB.sysCore].interParam.ScheduleTableId = ScheduleTableID;
                Os_InterCore[Os_SCB.sysCore].interParam.ScheduleStatus = ScheduleStatus;
                /* PRQA S 0303++ */ /* MISRA Rule 11.4 */
                Os_ArchRemoteCall(coreId);
                /* PRQA S 0303-- */ /* MISRA Rule 11.4 */
                while ((StatusType)E_NOT_OK == Os_InterCore[Os_SCB.sysCore].interState)
                {
                    /* Nothing to do. */
                }

                OsReturnErr = Os_InterCore[Os_SCB.sysCore].interState;
                OS_ARCH_EXIT_CRITICAL();
            }
        }
        else
#endif /*OS_AUTOSAR_CORES > 1*/
        {
#if (OS_AUTOSAR_CORES > 1)
            ScheduleTableID = Os_GetObjLocalId(ScheduleTableID);
#endif /*OS_AUTOSAR_CORES > 1*/

            /* Check input_pointor null is better. */
            if (NULL_PTR == ScheduleStatus)
            {
#if (TRUE == CFG_ERRORHOOK)
                Os_StInnerErrHook(OSServiceId_GetScheduleTableStatus, E_OS_ILLEGAL_ADDRESS);
#endif /* TRUE == CFG_ERRORHOOK */

                OsReturnErr = E_OS_VALUE;
            }
/* OS293 */
#if (OS_STATUS_EXTENDED == CFG_STATUS)
            else if (ScheduleTableID >= CFG_SCHEDTBL_MAX)
            {
#if (TRUE == CFG_ERRORHOOK)
                Os_StInnerErrHook(OSServiceId_GetScheduleTableStatus, E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

                OsReturnErr = E_OS_ID;
            }
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
            else
            {
                pStCB = &Os_STCB[ScheduleTableID];

                /* Return state of ScheduleTableID. */
                *ScheduleStatus = pStCB->stState;
            }
        }
    }

    OS_GSTS_EXIT();
    return OsReturnErr;
}

/********************************************************************/
/*
 * Brief                <Start schedule table in Rel mode.>
 * Service ID           <OSServiceId_StartScheduleTableRel>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * param-eventId[in]    <ScheduleTableID, Offset>
 * Param-Name[out]      <StatusType>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * REQ ID               <DD_1_0467, DD_1_1028, DD_1_0468:(1), DD_1_0469, DD_1_0470, DD_1_0471,
 *                       DD_1_0472, DD_1_1391, DD_1_1404, DD_1_1435, DD_1_1436, DD_1_1587,
 *                       DD_1_0475, DD_1_1669>
 */
/********************************************************************/
/* PRQA S 1532++ */ /* MISRA Rule 8.7 */
FUNC(StatusType, OS_CODE) StartScheduleTableRel(ScheduleTableType ScheduleTableID, TickType Offset)
/* PRQA S 1532-- */ /* MISRA Rule 8.7 */
{
    Os_TickType osCounterCurVal;
    Os_TickType osStartAbsTick;
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStCfgRef;
    P2CONST(Os_CounterCfgType, AUTOMATIC, OS_VAR) pCounterCfgRef;
    P2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pStCB = NULL_PTR;
    StatusType OsReturnErr = E_OK;
#if (OS_STATUS_EXTENDED == CFG_STATUS)
    Os_TickType stInitOffset;
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */

#if (OS_AUTOSAR_CORES > 1)
    Os_CoreIdType coreId;
#endif /* OS_AUTOSAR_CORES > 1 */

    OS_ARCH_DECLARE_CRITICAL();
    OS_SSTR_ENTRY();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    if (Os_WrongContext(OS_CONTEXT_START_ST_REL) != TRUE)
    {
        OsReturnErr = E_OS_CALLEVEL;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        OsReturnErr = E_OS_DISABLEDINT;
    }
    else if (Os_CheckObjAcs(OBJECT_SCHEDULETABLE, ScheduleTableID) != TRUE)
    {
        OsReturnErr = E_OS_ACCESS;
    }
    else
#endif /*TRUE == CFG_SERVICE_PROTECTION_ENABLE*/
    {
/* SWS_Os_00645:The API call "tartScheduleTableRel" shall
 * be able to start schedule tables of OS-Applications
 * residing on other cores. */
#if (OS_AUTOSAR_CORES > 1)
        coreId = Os_GetObjCoreId(ScheduleTableID);
        if (coreId != Os_SCB.sysCore)
        {
            if (Os_CoreCB.coreStatus[coreId] != OS_RUN)
            {
                OsReturnErr = E_OS_CORE;
            }
            else
            {
                OS_ARCH_ENTRY_CRITICAL();
                Os_InterCore[Os_SCB.sysCore].interState = E_NOT_OK;
                Os_InterCore[Os_SCB.sysCore].serviceId = OSServiceId_StartScheduleTableRel;
                Os_InterCore[Os_SCB.sysCore].interParam.ScheduleTableId = ScheduleTableID;
                Os_InterCore[Os_SCB.sysCore].interParam.ScheduleTableOffset = Offset;
                /* PRQA S 0303++ */ /* MISRA Rule 11.4 */
                Os_ArchRemoteCall(coreId);
                /* PRQA S 0303-- */ /* MISRA Rule 11.4 */
                while ((StatusType)E_NOT_OK == Os_InterCore[Os_SCB.sysCore].interState)
                {
                    /* Nothing to do. */
                }

                OsReturnErr = Os_InterCore[Os_SCB.sysCore].interState;
                OS_ARCH_EXIT_CRITICAL();
            }
        }
        else
#endif /*OS_AUTOSAR_CORES > 1*/
        {
#if (OS_AUTOSAR_CORES > 1)
            ScheduleTableID = Os_GetObjLocalId(ScheduleTableID);
#endif /*OS_AUTOSAR_CORES > 1*/

/* OS275 */
#if (OS_STATUS_EXTENDED == CFG_STATUS)
            if (ScheduleTableID >= CFG_SCHEDTBL_MAX)
            {
#if (TRUE == CFG_ERRORHOOK)
                Os_StInnerErrHook(OSServiceId_StartScheduleTableRel, E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

                OsReturnErr = E_OS_ID;
            }
            else
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
            {
                pStCfgRef = &Os_SchedTblCfg[ScheduleTableID];
                pCounterCfgRef = &Os_CounterCfg[pStCfgRef->osSchedTblCounterRef];

/* OS452 */
#if ((OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC))
                if (ST_SYNC_IMPLICIT == pStCfgRef->osSchedTblSync.osSchedTblSyncStrategy)
                {
#if (TRUE == CFG_ERRORHOOK)
                    Os_StInnerErrHook(OSServiceId_StartScheduleTableRel, E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

                    OsReturnErr = E_OS_ID;
                }
                else
#endif /* (OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC) */
                {
/* OS332 + OS276 */
#if (OS_STATUS_EXTENDED == CFG_STATUS)
                    stInitOffset = pStCfgRef->osSchedTblEP[0].osSchedTblEPOffset;

                    if ((Offset > (pCounterCfgRef->osCounterMaxAllowedValue - stInitOffset)) || (0u == Offset))
                    {
#if (TRUE == CFG_ERRORHOOK)
                        Os_StInnerErrHook(OSServiceId_StartScheduleTableRel, E_OS_VALUE);
#endif /* TRUE == CFG_ERRORHOOK */

                        OsReturnErr = E_OS_VALUE;
                    }
                    else
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
                    {
                        pStCB = &Os_STCB[ScheduleTableID];

                        /* OS277 */
                        if (SCHEDULETABLE_STOPPED != pStCB->stState)
                        {
#if (TRUE == CFG_ERRORHOOK)
                            Os_StInnerErrHook(OSServiceId_StartScheduleTableRel, E_OS_STATE);
#endif /* TRUE == CFG_ERRORHOOK */

                            OsReturnErr = E_OS_STATE;
                        }
                    }
                }
            }

            if ((StatusType)E_OK == OsReturnErr)
            {
                OS_ARCH_ENTRY_CRITICAL();
                OS_GSTS_START_CRITICAL();

                /* Timer type. */
                osCounterCurVal = Os_CCB[pStCfgRef->osSchedTblCounterRef].counterCurVal;

                /* Save abs start tick. */
                osStartAbsTick = Os_CalcAbsTicks(osCounterCurVal, Offset, pStCfgRef->osSchedTblCounterRef);

                Os_StInnerStart(osStartAbsTick, pStCB, pStCfgRef);

                /* Insert ScheduleTable to list. */
                Os_InsertSTNode(ScheduleTableID);

                OS_ARCH_EXIT_CRITICAL();
                OS_GSTS_END_CRITICAL();
            }
        }
    }

    OS_SSTR_EXIT();
    return OsReturnErr;
}

/********************************************************************/
/*
 * Brief                <Start schedule table in Abs mode.>
 * Service ID           <OSServiceId_StartScheduleTableAbs>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * param-eventId[in]    <ScheduleTableID, Start>
 * Param-Name[out]      <StatusType>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * REQ ID               <DD_1_0476, DD_1_1029, DD_1_0478, DD_1_0479, DD_1_0482, DD_1_1392
 *                       DD_1_1403, DD_1_1433, DD_1_1437, DD_1_1155, DD_1_1588, DD_1_1670>
 */
/********************************************************************/
FUNC(StatusType, OS_CODE)
StartScheduleTableAbs(ScheduleTableType ScheduleTableID, TickType Start) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStCfgRef;
    P2CONST(Os_CounterCfgType, AUTOMATIC, OS_VAR) pCounterCfgRef;
    P2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pStCB;
#if (OS_AUTOSAR_CORES > 1)
    Os_CoreIdType coreId;
#endif /* OS_AUTOSAR_CORES > 1 */
    StatusType OsReturnErr = E_OK;

    OS_ARCH_DECLARE_CRITICAL();
    OS_SSTA_ENTRY();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    if (Os_WrongContext(OS_CONTEXT_START_ST_ABS) != TRUE)
    {
        OsReturnErr = E_OS_CALLEVEL;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        OsReturnErr = E_OS_DISABLEDINT;
    }
    else if (Os_CheckObjAcs(OBJECT_SCHEDULETABLE, ScheduleTableID) != TRUE)
    {
        OsReturnErr = E_OS_ACCESS;
    }
    else
#endif /*#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)*/
    {
/* SWS_Os_00644:The API call "tartScheduleTableAbs"
 * shall be able to start schedule tables of
 * OS-Applications residing on other cores. */
#if (OS_AUTOSAR_CORES > 1)
        coreId = Os_GetObjCoreId(ScheduleTableID);
        if (coreId != Os_SCB.sysCore)
        {
            if (Os_CoreCB.coreStatus[coreId] != OS_RUN)
            {
                OsReturnErr = E_OS_CORE;
            }
            else
            {
                OS_ARCH_ENTRY_CRITICAL();
                Os_InterCore[Os_SCB.sysCore].interState = E_NOT_OK;
                Os_InterCore[Os_SCB.sysCore].serviceId = OSServiceId_StartScheduleTableAbs;
                Os_InterCore[Os_SCB.sysCore].interParam.ScheduleTableId = ScheduleTableID;
                Os_InterCore[Os_SCB.sysCore].interParam.ScheduleTableStart = Start;
                /* PRQA S 0303++ */ /* MISRA Rule 11.4 */
                Os_ArchRemoteCall(coreId);
                /* PRQA S 0303-- */ /* MISRA Rule 11.4 */
                while ((StatusType)E_NOT_OK == Os_InterCore[Os_SCB.sysCore].interState)
                {
                    /* Nothing to do. */
                }

                OsReturnErr = Os_InterCore[Os_SCB.sysCore].interState;
                OS_ARCH_EXIT_CRITICAL();
            }
        }
        else
#endif /*OS_AUTOSAR_CORES > 1*/
        {
#if (OS_AUTOSAR_CORES > 1)
            ScheduleTableID = Os_GetObjLocalId(ScheduleTableID);
#endif /*OS_AUTOSAR_CORES > 1*/

/* OS348 */
#if (OS_STATUS_EXTENDED == CFG_STATUS)
            if (ScheduleTableID >= CFG_SCHEDTBL_MAX)
            {
#if (TRUE == CFG_ERRORHOOK)
                Os_StInnerErrHook(OSServiceId_StartScheduleTableAbs, E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

                OsReturnErr = E_OS_ID;
            }
            else
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
            {
                pStCfgRef = &Os_SchedTblCfg[ScheduleTableID];
                pCounterCfgRef = &Os_CounterCfg[pStCfgRef->osSchedTblCounterRef];

/* OS349 */
#if (OS_STATUS_EXTENDED == CFG_STATUS)
                if (Start > pCounterCfgRef->osCounterMaxAllowedValue)
                {
#if (TRUE == CFG_ERRORHOOK)
                    Os_StInnerErrHook(OSServiceId_StartScheduleTableAbs, E_OS_VALUE);
#endif /* TRUE == CFG_ERRORHOOK */

                    OsReturnErr = E_OS_VALUE;
                }
                else
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
                {
                    pStCB = &Os_STCB[ScheduleTableID];

                    /* OS350 */
                    if (SCHEDULETABLE_STOPPED != pStCB->stState)
                    {
#if (TRUE == CFG_ERRORHOOK)
                        Os_StInnerErrHook(OSServiceId_StartScheduleTableAbs, E_OS_STATE);
#endif /* TRUE == CFG_ERRORHOOK */

                        OsReturnErr = E_OS_STATE;
                    }
                }
            }
            if ((StatusType)E_OK == OsReturnErr)
            {
                OS_ARCH_ENTRY_CRITICAL();
                OS_SSTR_START_CRITICAL();

                /* Save abs start tick. */
                Os_StInnerStart(Start, pStCB, pStCfgRef);

                /* Insert ScheduleTable to list. */
                Os_InsertSTNode(ScheduleTableID);

                OS_ARCH_EXIT_CRITICAL();
                OS_SSTR_END_CRITICAL();
            }
        }
    }

    OS_SSTA_EXIT();
    return OsReturnErr;
}

/********************************************************************/
/*
 * Brief                <Start schedule table in Abs mode.>
 * Service ID           <OSServiceId_StartScheduleTableAbs>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * param-eventId[in]    <ScheduleTableID, Start>
 * Param-Name[out]      <StatusType>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * REQ ID               <DD_1_0483, DD_1_0484:(1), DD_1_0485, DD_1_0486, DD_1_0488, DD_1_1030,
 *                       DD_1_1393, DD_1_1405, DD_1_1438, DD_1_1589, DD_1_1671>
 */
/********************************************************************/
FUNC(StatusType, OS_CODE) StopScheduleTable(ScheduleTableType ScheduleTableID)
{
    P2VAR(Os_STCBType const volatile, AUTOMATIC, OS_VAR) pStCB;
#if (OS_AUTOSAR_CORES > 1)
    Os_CoreIdType coreId;
#endif /* OS_AUTOSAR_CORES > 1 */
    StatusType OsReturnErr = E_OK;

    OS_ARCH_DECLARE_CRITICAL();
    OS_SST_ENTRY();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    if (Os_WrongContext(OS_CONTEXT_STOP_SCHEDULE_TABLE) != TRUE)
    {
        OsReturnErr = E_OS_CALLEVEL;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        OsReturnErr = E_OS_DISABLEDINT;
    }
    else if (Os_CheckObjAcs(OBJECT_SCHEDULETABLE, ScheduleTableID) != TRUE)
    {
        OsReturnErr = E_OS_ACCESS;
    }
    else
#endif /*#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)*/
    {
/* SWS_Os_00646:The API call StopScheduleTable
 * shall be able to stop schedule tables of
 * OS-Applications residing on other cores.  */
#if (OS_AUTOSAR_CORES > 1)
        coreId = Os_GetObjCoreId(ScheduleTableID);
        if (coreId != Os_SCB.sysCore)
        {
            if (Os_CoreCB.coreStatus[coreId] != OS_RUN)
            {
                OsReturnErr = E_OS_CORE;
            }
            else
            {
                OS_ARCH_ENTRY_CRITICAL();
                Os_InterCore[Os_SCB.sysCore].interState = E_NOT_OK;
                Os_InterCore[Os_SCB.sysCore].serviceId = OSServiceId_StopScheduleTable;
                Os_InterCore[Os_SCB.sysCore].interParam.ScheduleTableId = ScheduleTableID;
                /* PRQA S 0303++ */ /* MISRA Rule 11.4 */
                Os_ArchRemoteCall(coreId);
                /* PRQA S 0303-- */ /* MISRA Rule 11.4 */
                while ((StatusType)E_NOT_OK == Os_InterCore[Os_SCB.sysCore].interState)
                {
                    /* Nothing to do. */
                }

                OsReturnErr = Os_InterCore[Os_SCB.sysCore].interState;
                OS_ARCH_EXIT_CRITICAL();
            }
        }
        else
#endif /*OS_AUTOSAR_CORES > 1*/
        {
#if (OS_AUTOSAR_CORES > 1)
            ScheduleTableID = Os_GetObjLocalId(ScheduleTableID);
#endif /*OS_AUTOSAR_CORES > 1*/

/* OS279 */
#if (OS_STATUS_EXTENDED == CFG_STATUS)
            if (ScheduleTableID >= CFG_SCHEDTBL_MAX)
            {
#if (TRUE == CFG_ERRORHOOK)
                Os_StInnerErrHook(OSServiceId_StopScheduleTable, E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

                OsReturnErr = E_OS_ID;
            }
            else
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
            {
                pStCB = &Os_STCB[ScheduleTableID];

                /* OS280 */
                if (SCHEDULETABLE_STOPPED == pStCB->stState)
                {
#if (TRUE == CFG_ERRORHOOK)
                    Os_StInnerErrHook(OSServiceId_StopScheduleTable, E_OS_NOFUNC);
#endif /* TRUE == CFG_ERRORHOOK */

                    OsReturnErr = E_OS_NOFUNC;
                }
            }

            if ((StatusType)E_OK == OsReturnErr)
            {
                OS_ARCH_ENTRY_CRITICAL();
                OS_SST_START_CRITICAL();

                /* OS453: Delete next-ScheduleTable releted by ScheduleTableID. */
                if (OS_SCHEDTABLE_INVALID != pStCB->NextStID)
                {
                    Os_DelStNode(pStCB->NextStID);
                    Os_InitSchedTblCB(pStCB->NextStID);
                }

                /* If state is ST_STATE_NEXT, prev-st should be cared. */
                if (OS_SCHEDTABLE_INVALID != pStCB->PrevStID)
                {
                    Os_STCB[pStCB->PrevStID].NextStID = OS_SCHEDTABLE_INVALID;
                }

                /* Delete node from list. */
                Os_DelStNode(ScheduleTableID);

                /* Re-init STCB. Note: in function Os_InitSchedTblCB,
                   state will be set to ST_STATE_STOPPED. */
                Os_InitSchedTblCB(ScheduleTableID);

                OS_ARCH_EXIT_CRITICAL();
                OS_SST_END_CRITICAL();
            }
        }
    }

    OS_SST_EXIT();
    return OsReturnErr;
}

/********************************************************************/
/*
 * Brief                <Next ScheduleTable Process.>
 * Service ID           <OSServiceId_NextScheduleTable>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * param-eventId[in]    <ScheduleTableID_From, ScheduleTableID_To>
 * Param-Name[out]      <StatusType>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * REQ ID               <DD_1_0489, DD_1_0490:(1), DD_1_0492, DD_1_0493, DD_1_0494, DD_1_0496,
 *                       DD_1_0500, DD_1_1031, DD_1_1368, DD_1_1394, DD_1_1409, DD_1_1410,
 *                       DD_1_1429, DD_1_1152, DD_1_1590, DD_1_1672>
 */
/********************************************************************/
/* PRQA S 1503++ */ /* MISRA Rule 2.1 */
FUNC(StatusType, OS_CODE)
NextScheduleTable(ScheduleTableType ScheduleTableID_From, ScheduleTableType ScheduleTableID_To)
/* PRQA S 1503-- */ /* MISRA Rule 2.1 */
{
    P2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pStFromCB;
    P2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pStToCB;
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStFromCfgRef;
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStToCfgRef;
    StatusType OsReturnErr = E_OK;

    OS_ARCH_DECLARE_CRITICAL();
    OS_NST_ENTRY();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

    /* Cross core use shall be not supported. */
    if ((Os_SCB.sysCore != Os_GetObjCoreId(ScheduleTableID_From))
        || (Os_SCB.sysCore != Os_GetObjCoreId(ScheduleTableID_To)))
    {
#if (TRUE == CFG_ERRORHOOK)
        Os_CallErrorHook(E_OS_CORE);
#endif /* TRUE == CFG_ERRORHOOK */

        OsReturnErr = E_OS_CORE;
    }
#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    else if (Os_WrongContext(OS_CONTEXT_NEXT_SCHEDULE_TABLE) != TRUE)
    {
        OsReturnErr = E_OS_CALLEVEL;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        OsReturnErr = E_OS_DISABLEDINT;
    }
    else if (Os_CheckObjAcs(OBJECT_SCHEDULETABLE, ScheduleTableID_From) != TRUE)
    {
        OsReturnErr = E_OS_ACCESS;
    }
    else if (Os_CheckObjAcs(OBJECT_SCHEDULETABLE, ScheduleTableID_To) != TRUE)
    {
        OsReturnErr = E_OS_ACCESS;
    }
#endif /* (TRUE == CFG_SERVICE_PROTECTION_ENABLE) */
    else
    {
        ScheduleTableID_From = Os_GetObjLocalId(ScheduleTableID_From);
        ScheduleTableID_To = Os_GetObjLocalId(ScheduleTableID_To);

#if (OS_STATUS_EXTENDED == CFG_STATUS)
        /* OS282:If the input parameter <ScheduleTableID_From> or
         * <ScheduleTableID_To> in a call of NextScheduleTable()
         * is not valid,NextScheduleTable() shall return E_OS_ID.*/
        if ((ScheduleTableID_From >= CFG_SCHEDTBL_MAX) || (ScheduleTableID_To >= CFG_SCHEDTBL_MAX))
        {
#if (TRUE == CFG_ERRORHOOK)
            Os_StInnerErrHook(OSServiceId_NextScheduleTable, E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

            OsReturnErr = E_OS_ID;
        }
        else
#endif /* (OS_STATUS_EXTENDED == CFG_STATUS) */
        {
            pStFromCfgRef = &Os_SchedTblCfg[ScheduleTableID_From];
            pStToCfgRef = &Os_SchedTblCfg[ScheduleTableID_To];

#if (OS_STATUS_EXTENDED == CFG_STATUS)
            /* OS330:If in a call of NextScheduleTable() schedule table
             * <ScheduleTableID_To> is driven by different counter than
             * schedule table <ScheduleTableID_From> then NextScheduleTable()
             * shall return an error E_OS_ID.*/
            if (pStFromCfgRef->osSchedTblCounterRef != pStToCfgRef->osSchedTblCounterRef)
            {
#if (TRUE == CFG_ERRORHOOK)
                Os_StInnerErrHook(OSServiceId_NextScheduleTable, E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

                OsReturnErr = E_OS_ID;
            }
            else
            {
/* SWS_Os_00484:If OsScheduleTblSyncStrategy of <ScheduleTableID_To>
 * in a call of NextScheduleTable() is not equal to the
 * OsScheduleTblSyncStrategy of <ScheduleTableID_From> then
 * NextScheduleTable() shall return E_OS_ID.*/
#if ((OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC))
                if (pStFromCfgRef->osSchedTblSync.osSchedTblSyncStrategy
                    != pStToCfgRef->osSchedTblSync.osSchedTblSyncStrategy)
                {
#if (TRUE == CFG_ERRORHOOK)
                    Os_StInnerErrHook(OSServiceId_NextScheduleTable, E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

                    OsReturnErr = E_OS_ID;
                }
#endif /* (OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC) */
            }
#endif /* #if (OS_STATUS_EXTENDED == CFG_STATUS) */

            if ((StatusType)E_OK == OsReturnErr)
            {
                pStFromCB = &Os_STCB[ScheduleTableID_From];
                pStToCB = &Os_STCB[ScheduleTableID_To];

                /* OS283 */
                if ((SCHEDULETABLE_STOPPED == pStFromCB->stState) || (SCHEDULETABLE_NEXT == pStFromCB->stState))
                {
#if (TRUE == CFG_ERRORHOOK)
                    Os_StInnerErrHook(OSServiceId_NextScheduleTable, E_OS_NOFUNC);
#endif /* TRUE == CFG_ERRORHOOK */

                    OsReturnErr = E_OS_NOFUNC;
                }
                /* OS309 */
                else if (SCHEDULETABLE_STOPPED != pStToCB->stState)
                {
#if (TRUE == CFG_ERRORHOOK)
                    Os_StInnerErrHook(OSServiceId_NextScheduleTable, E_OS_STATE);
#endif /* TRUE == CFG_ERRORHOOK */

                    OsReturnErr = E_OS_STATE;
                }
                /* If ScheduleTable From is repeating, The functionality is not support. */
                else if (TRUE == pStFromCfgRef->osSchedTblRepeating)
                {
                    OsReturnErr = E_OS_STATE;
                }
                else
                {
                    /*nothing to do*/
                }
            }

            if ((StatusType)E_OK == OsReturnErr)
            {
                OS_ARCH_ENTRY_CRITICAL();
                OS_NST_START_CRITICAL();

                /* OS284 */
                pStToCB->stStartAbsTick = Os_CalcAbsTicks(
                    pStFromCB->stStartAbsTick,
                    pStFromCfgRef->osSchedTblDuration,
                    pStFromCfgRef->osSchedTblCounterRef);

                pStToCB->stNextEpAbsTick = Os_CalcAbsTicks(
                    pStToCB->stStartAbsTick,
                    pStToCfgRef->osSchedTblEP[0].osSchedTblEPOffset,
                    pStToCfgRef->osSchedTblCounterRef);

                pStToCB->stState = SCHEDULETABLE_NEXT;
                pStToCB->stIsStarted = TRUE;

                /* OS324 */
                if (OS_SCHEDTABLE_INVALID != pStFromCB->NextStID)
                {
                    Os_DelStNode(pStFromCB->NextStID);
                    Os_InitSchedTblCB(pStFromCB->NextStID);
                }

                pStFromCB->NextStID = ScheduleTableID_To;
                pStToCB->PrevStID = ScheduleTableID_From;

                /* OS284: Insert to list. */
                Os_InsertSTNode(ScheduleTableID_To);

                /* OS363: Do nothing here. */

                /* OS453: in StopScheduleTable. */

                OS_ARCH_EXIT_CRITICAL();
                OS_NST_END_CRITICAL();
            }
        }
    }

    OS_NST_EXIT();
    return OsReturnErr;
}

/* Sync. */
#if ((OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC))
/********************************************************************/
/*
 * Brief                <StartScheduleTableSynchron.>
 * Service ID           <OSServiceId_NextScheduleTable>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * param-eventId[in]    <ScheduleTableID>
 * Param-Name[out]      <StatusType>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * REQ ID               <DD_1_0501, DD_1_0502:(1), DD_1_0503, DD_1_0506, DD_1_1032, DD_1_1369
 *                       DD_1_1395, DD_1_1591, DD_1_1673>
 */
/********************************************************************/
/* PRQA S 1503++ */ /* MISRA Rule 2.1 */
FUNC(StatusType, OS_CODE) StartScheduleTableSynchron(ScheduleTableType ScheduleTableID)
/* PRQA S 1503-- */ /* MISRA Rule 2.1 */
{
    StatusType OsReturnErr = E_OK;
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStCfgRef;
    P2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pStCB;

    OS_ARCH_DECLARE_CRITICAL();
    OS_SSTS_ENTRY();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

    /* Cross core use shall be not supported. */
    if (Os_SCB.sysCore != Os_GetObjCoreId(ScheduleTableID))
    {
#if (TRUE == CFG_ERRORHOOK)
        Os_CallErrorHook(E_OS_CORE);
#endif /* TRUE == CFG_ERRORHOOK */
        OsReturnErr = E_OS_CORE;
    }
#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    else if (Os_WrongContext(OS_CONTEXT_START_ST_SYN) != TRUE)
    {
        OsReturnErr = E_OS_CALLEVEL;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        OsReturnErr = E_OS_DISABLEDINT;
    }
    else if (Os_CheckObjAcs(OBJECT_SCHEDULETABLE, ScheduleTableID) != TRUE)
    {
        OsReturnErr = E_OS_ACCESS;
    }
#endif /*#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)*/
    else
    {
        ScheduleTableID = Os_GetObjLocalId(ScheduleTableID);

/* OS387 */
#if (OS_STATUS_EXTENDED == CFG_STATUS)
        if (ScheduleTableID >= CFG_SCHEDTBL_MAX)
        {
#if (TRUE == CFG_ERRORHOOK)
            Os_StInnerErrHook(OSServiceId_StartScheduleTableSynchronhron, E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

            OsReturnErr = E_OS_ID;
        }
        else
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
        {
            pStCfgRef = &Os_SchedTblCfg[ScheduleTableID];
            pStCB = &Os_STCB[ScheduleTableID];

            /* OS387 */
            if (ST_SYNC_EXPLICIT != pStCfgRef->osSchedTblSync.osSchedTblSyncStrategy)
            {
#if (TRUE == CFG_ERRORHOOK)
                Os_StInnerErrHook(OSServiceId_StartScheduleTableSynchronhron, E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

                OsReturnErr = E_OS_ID;
            }

            /* OS388 */
            else if (SCHEDULETABLE_STOPPED != pStCB->stState)
            {
#if (TRUE == CFG_ERRORHOOK)
                Os_StInnerErrHook(OSServiceId_StartScheduleTableSynchronhron, E_OS_STATE);
#endif /* TRUE == CFG_ERRORHOOK */

                OsReturnErr = E_OS_STATE;
            }
            else
            {
                /*nothing to do*/
            }
        }

        if ((StatusType)E_OK == OsReturnErr)
        {
            OS_ARCH_ENTRY_CRITICAL();
            OS_SSTS_START_CRITICAL();
            /* OS389 */
            pStCB->stState = SCHEDULETABLE_WAITING;
            OS_ARCH_EXIT_CRITICAL();
            OS_SSTS_END_CRITICAL();
        }
    }

    OS_SSTS_EXIT();
    return OsReturnErr;
}

/********************************************************************/
/*
 * Brief                <Sync ScheduleTable.>
 * Service ID           <OSServiceId_SyncScheduleTable>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Yes>
 * param-eventId[in]    <ScheduleTableID, value>
 * Param-Name[out]      <StatusType>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * REQ ID               <DD_1_0507, DD_1_0508:(1), DD_1_0510, DD_1_0513, DD_1_1033
 *                       DD_1_1367, DD_1_1396, DD_1_1411, DD_1_1431, DD_1_1424, DD_1_1592,
 *                       DD_1_1674>
 */
/********************************************************************/
/* PRQA S 1503++ */ /* MISRA Rule 2.1 */
FUNC(StatusType, OS_CODE) SyncScheduleTable(ScheduleTableType ScheduleTableID, TickType value)
/* PRQA S 1503-- */ /* MISRA Rule 2.1 */
{
    Os_TickType counterCurval;
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStCfgRef;
    P2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pStCB;
    StatusType OsReturnErr = E_OK;

    OS_ARCH_DECLARE_CRITICAL();
    OS_SYNCST_ENTRY();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

    /* Cross core use shall be not supported. */
    if (Os_SCB.sysCore != Os_GetObjCoreId(ScheduleTableID))
    {
#if (TRUE == CFG_ERRORHOOK)
        Os_CallErrorHook(E_OS_CORE);
#endif /* TRUE == CFG_ERRORHOOK */

        OsReturnErr = E_OS_CORE;
    }
#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    else if (Os_WrongContext(OS_CONTEXT_SYNC_SCHEDULE_TABLE) != TRUE)
    {
        OsReturnErr = E_OS_CALLEVEL;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        OsReturnErr = E_OS_DISABLEDINT;
    }
    else if (Os_CheckObjAcs(OBJECT_SCHEDULETABLE, ScheduleTableID) != TRUE)
    {
        OsReturnErr = E_OS_ACCESS;
    }
#endif /*#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)*/
    else
    {
        ScheduleTableID = Os_GetObjLocalId(ScheduleTableID);

/* OS454. */
#if (OS_STATUS_EXTENDED == CFG_STATUS)
        if (ScheduleTableID >= CFG_SCHEDTBL_MAX)
        {
#if (TRUE == CFG_ERRORHOOK)
            Os_StInnerErrHook(OSServiceId_SyncScheduleTable, E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

            OsReturnErr = E_OS_ID;
        }
        else
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
        {
            pStCfgRef = &Os_SchedTblCfg[ScheduleTableID];
            pStCB = &Os_STCB[ScheduleTableID];

/* OS454. */
#if (OS_STATUS_EXTENDED == CFG_STATUS)
            if (ST_SYNC_EXPLICIT != pStCfgRef->osSchedTblSync.osSchedTblSyncStrategy)
            {
#if (TRUE == CFG_ERRORHOOK)
                Os_StInnerErrHook(OSServiceId_SyncScheduleTable, E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

                OsReturnErr = E_OS_ID;
            }
            /* OS455. */
            else if (value >= pStCfgRef->osSchedTblDuration)
            {
#if (TRUE == CFG_ERRORHOOK)
                Os_StInnerErrHook(OSServiceId_SyncScheduleTable, E_OS_VALUE);
#endif /* TRUE == CFG_ERRORHOOK */

                OsReturnErr = E_OS_VALUE;
            }
            else
            {
                /*nothing to do*/
            }
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
        }

        if ((StatusType)E_OK == OsReturnErr)
        {
            /* Get counterCB. */
            counterCurval = Os_CCB[pStCfgRef->osSchedTblCounterRef].counterCurVal;

            OS_ARCH_ENTRY_CRITICAL();
            OS_SYNCST_START_CRITICAL();

            /* Proc by different state. */
            switch (pStCB->stState)
            {
/* OS456. */
#if (OS_STATUS_EXTENDED == CFG_STATUS)
            case SCHEDULETABLE_STOPPED:
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */

            case SCHEDULETABLE_NEXT:

#if (TRUE == CFG_ERRORHOOK)
                Os_StInnerErrHook(OSServiceId_SyncScheduleTable, E_OS_STATE);
#endif /* TRUE == CFG_ERRORHOOK */
                OsReturnErr = E_OS_STATE;
                break;

            case SCHEDULETABLE_WAITING:
                Os_StWaittingStateProc(value, counterCurval, pStCB, pStCfgRef);
                break;

            case SCHEDULETABLE_RUNNING:
                Os_StRunningStateProc(value, counterCurval, pStCB, pStCfgRef);
                break;

            case SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS:
                Os_StRunningSyncStateProc(value, counterCurval, pStCB, pStCfgRef);
                break;

            /*add comments to pass QAC.*/
            default:
                /* Nothing to do. */
                break;
            }

            OS_ARCH_EXIT_CRITICAL();
            OS_SYNCST_END_CRITICAL();
        }
    }

    OS_SYNCST_EXIT();
    return OsReturnErr;
}

/********************************************************************/
/*
 * Brief                <SetScheduleTableAsync.>
 * Service ID           <OSServiceId_SetScheduleTableAsync>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Yes>
 * param-eventId[in]    <ScheduleTableID>
 * Param-Name[out]      <StatusType>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * REQ ID               <DD_1_0523, DD_1_0525, DD_1_0526, DD_1_0527, DD_1_0528,
 *                       DD_1_0529, DD_1_0530, DD_1_0530, DD_1_1035>
 */
/********************************************************************/
/* PRQA S 1503++ */ /* MISRA Rule 2.1 */
FUNC(StatusType, OS_CODE) SetScheduleTableAsync(ScheduleTableType ScheduleTableID)
/* PRQA S 1503-- */ /* MISRA Rule 2.1 */
{
    P2CONST(Os_SchedTblCfgType, AUTOMATIC, OS_VAR) pStCfgRef;
    P2VAR(Os_STCBType volatile, AUTOMATIC, OS_VAR) pStCB;
    StatusType OsReturnErr = E_OK;

    OS_ARCH_DECLARE_CRITICAL();
    OS_SSTA_ENTRY();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

    /* Cross core use shall be not supported. */
    if (Os_SCB.sysCore != Os_GetObjCoreId(ScheduleTableID))
    {
#if (TRUE == CFG_ERRORHOOK)
        Os_CallErrorHook(E_OS_CORE);
#endif /* TRUE == CFG_ERRORHOOK */

        OsReturnErr = E_OS_CORE;
    }
#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    else if (Os_WrongContext(OS_CONTEXT_SET_SCHEDULE_TABLE_ASYNC) != TRUE)
    {
        OsReturnErr = E_OS_CALLEVEL;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        OsReturnErr = E_OS_DISABLEDINT;
    }
    else if (Os_CheckObjAcs(OBJECT_SCHEDULETABLE, ScheduleTableID) != TRUE)
    {
        OsReturnErr = E_OS_ACCESS;
    }
#endif /*#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)*/
    else
    {
        ScheduleTableID = Os_GetObjLocalId(ScheduleTableID);

/*SWS_Os_00458:If OsScheduleTblSyncStrategy of <ScheduleTableID> in
 * a call of SetScheduleTableAsync() is not equal to EXPLICIT OR if
 * <ScheduleTableID> is invalid then SetScheduleTableAsync() shall
 * return E_OS_ID. */
#if (OS_STATUS_EXTENDED == CFG_STATUS)
        if (ScheduleTableID >= CFG_SCHEDTBL_MAX)
        {
#if (TRUE == CFG_ERRORHOOK)
            Os_StInnerErrHook(OSServiceId_SetScheduleTableAsync, E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

            OsReturnErr = E_OS_ID;
        }
        else
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
        {
            pStCfgRef = &Os_SchedTblCfg[ScheduleTableID];
            pStCB = &Os_STCB[ScheduleTableID];

            /* SWS_Os_00483:If state is STOPPED/NEXT/WAITTING, return E_OS_STATE. */
            if ((SCHEDULETABLE_STOPPED == pStCB->stState) || (SCHEDULETABLE_NEXT == pStCB->stState)
                || (SCHEDULETABLE_WAITING == pStCB->stState))
            {
#if (TRUE == CFG_ERRORHOOK)
                Os_StInnerErrHook(OSServiceId_SetScheduleTableAsync, E_OS_STATE);
#endif /* TRUE == CFG_ERRORHOOK */

                OsReturnErr = E_OS_STATE;
            }
        }

        if ((StatusType)E_OK == OsReturnErr)
        {
            OS_ARCH_ENTRY_CRITICAL();
            OS_SSTA_START_CRITICAL();

            /*SWS_Os_00300*/
            if (ST_SYNC_EXPLICIT == pStCfgRef->osSchedTblSync.osSchedTblSyncStrategy)
            {
                pStCB->stState = SCHEDULETABLE_RUNNING;
                /* OS362 && OS323 */
                pStCB->stIsStopAdjust = TRUE;
            }
            else /* OS458 */
            {
#if (TRUE == CFG_ERRORHOOK)
                Os_StInnerErrHook(OSServiceId_SetScheduleTableAsync, E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

                OsReturnErr = E_OS_ID;
            }

            OS_ARCH_EXIT_CRITICAL();
            OS_SSTA_END_CRITICAL();
        }
    }

    OS_SSTA_EXIT();
    return OsReturnErr;
}

#endif /* #if ((OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC)) */

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /*CFG_SCHEDTBL_MAX > 0U*/

/* Misrac: Msg(3:0862) This #include "D:/TestPrj/TriCore/Include/Os_MemMap.h" directive is redundant.
 * Note: For memory map, stay the same as other modules. */
