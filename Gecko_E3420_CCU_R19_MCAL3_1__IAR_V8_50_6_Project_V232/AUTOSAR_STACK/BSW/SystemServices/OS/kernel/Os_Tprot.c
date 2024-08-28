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
**  FILENAME    : Os_Tprot.c                                                  **
**                                                                            **
**  Created on  :                                                             **
**  Author      : shun.li                                                     **
**  Vendor      :                                                             **
**  DESCRIPTION : AutoSar Protection Management                               **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>    <AUTHOR>    <REVISION LOG>
 *  V0.1.0 2015-03-23  Yan.Zhuang  Initial version, add this file.
 *  V0.2.0 2019-08-21  shun.li & zhiqiang.huang   Functional safety initial version.
 *  V1.0.0 2019-11-21  shun.li     Functional safety version.
 */
/*============================================================================*/

/*=======[M I S R A C  R U L E  V I O L A T I O N]============================*/
/*  <MESSAGE ID>    <CODE LINE>    <REASON>
 *  Rule 1.1        all the file   This in-line assembler construct is a
 *                                 language extension. The code has been ignored.
 */
/*============================================================================*/

/*=======[I N C L U D E S]====================================================*/
#include "Os_Internal.h"

#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
#define OS_START_SEC_CODE
#include "Os_MemMap.h"

/*=======[I N T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/
#if (CFG_STD_RESOURCE_MAX > 0)
static FUNC(void, OS_CODE) Os_TmProtResCounter(ResourceType osResId);
static FUNC(void, OS_CODE)
    Os_TmProtInitTaskResLock(Os_TaskType osTaskId, P2CONST(Os_TaskCfgType, AUTOMATIC, OS_VAR) pTaskCfg);
#endif /*CFG_STD_RESOURCE_MAX > 0*/

#if (CFG_ISR2_MAX > 0U)
static FUNC(void, OS_CODE) Os_TmProtIsrProc(void);
static FUNC(void, OS_CODE) Os_TmProtIsrFrameCounter(Os_IsrType osIsrId, Os_TmProtOptIsrType osOptType);
static FUNC(void, OS_CODE) Os_TmProtIsrCounter(Os_IsrType osIsrId, Os_TmProtOptIsrType osOptType);
static FUNC(void, OS_CODE) Os_InitIsrTmProt(
    Os_IsrType osIsrId,
    P2CONST(Os_IsrCfgType, AUTOMATIC, OS_VAR) pIsrCfg,
    P2VAR(Os_ICBType volatile, AUTOMATIC, OS_VAR) pIcb);
#if (CFG_STD_RESOURCE_MAX > 0)
static FUNC(void, OS_CODE)
    Os_TmProtInitIsrResLock(Os_IsrType osIsrId, P2CONST(Os_IsrCfgType, AUTOMATIC, OS_VAR) pIsrCfg);
#endif /*CFG_STD_RESOURCE_MAX > 0*/
#endif /*CFG_ISR2_MAX > 0U*/

static FUNC(void, OS_CODE) Os_TmProtTaskFrameCounter(Os_TaskType osTaskId, Os_TmProtOptTaskType osOptType);
static FUNC(void, OS_CODE) Os_TmProtTaskCounter(Os_TaskType osTaskId, Os_TmProtOptTaskType osOptType);
static FUNC(void, OS_CODE) Os_InitTaskTmProt(
    Os_TaskType osTaskId,
    P2CONST(Os_TaskCfgType, AUTOMATIC, OS_VAR) pTaskCfg,
    P2VAR(Os_TCBType volatile, AUTOMATIC, OS_VAR) pTcb);
static FUNC(void, OS_CODE) Os_TmProtTaskProc(void);

#if (CFG_STD_RESOURCE_MAX > 0)
/********************************************************************/
/*
 * Brief                <Start process for budget of resource locking.>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <None>
 * param-eventId[in]    <osResId>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <GetResource>
 * REQ ID               <DD_1_1016, DD_1_1017, DD_1_1611>
 */
/********************************************************************/
/* PRQA S 1532++ */ /* MISRA Rule 8.7 */
FUNC(void, OS_CODE) Os_TmProtResStart(ResourceType osResId, Os_TmProtResOccupyType osOccupyType)
/* PRQA S 1532-- */ /* MISRA Rule 8.7 */
{
    uint8 osWhoHook;
    Os_TickType osBudget;
    P2VAR(Os_RCBType volatile, AUTOMATIC, OS_VAR) pRcb;
    P2VAR(Os_SCBType const volatile, AUTOMATIC, OS_VAR) pScb;
    P2VAR(Os_TmProtCbDataDef volatile, AUTOMATIC, OS_VAR) pCbData;

    pRcb = &Os_RCB[osResId];
    pScb = &Os_SCB;

    /* If start timing protection. */
    if (osOccupyType < TP_RES_OCCUPY_BUTT)
    {
        /* Get budget according to osOccupyType. */
        if (TP_RES_OCCUPY_TASK == osOccupyType)                                            /* By task. */
        {
            osBudget = pRcb->osTmProtResBgtTask[pScb->sysRunningTaskID]; /* PRQA S 0404 */ /* MISRA Rule 1.3,13.2 */
            osWhoHook = OS_TMPROT_HOOK_TASK;

            /* Which task occupy this resource. */
            pRcb->osWhichTaskOccupy = pScb->sysRunningTaskID;
        }
#if (CFG_ISR2_MAX > 0)
        else /*TP_RES_OCCUPY_ISR == osOccupyType*/
        {
            osBudget = pRcb->osTmProtResBgtIsr[pScb->sysRunningIsrCat2Id]; /* PRQA S 0404 */ /* MISRA Rule 1.3,13.2 */
            osWhoHook = OS_TMPROT_HOOK_ISR;

            /* Which isr occupy this resource. */
            pRcb->osWhichIsrOccupy = pScb->sysRunningIsrCat2Id;
        }
#endif /* CFG_ISR2_MAX > 0 */

        /* Timing protection start for task or isr. */
        if (OS_TICK_INVALID != osBudget)
        {
            pCbData = &(pRcb->osResTpData);

            if (TRUE != pCbData->osIsTpStart)
            {
                pCbData->osIsTpStart = TRUE;
                pCbData->osTpTime = 0u;
                pCbData->osTpBudget = osBudget;
                pCbData->osWhoHook = osWhoHook;
            }
        }
    }

    return;
}

/********************************************************************/
/*
 * Brief                <Counter process for budget of resource locking.>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <None>
 * param-eventId[in]    <osResId>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_TmProtMainProc>
 * REQ ID               <DD_1_0985, DD_1_0986, DD_1_1287, DD_1_1288>
 */
/********************************************************************/
static FUNC(void, OS_CODE) Os_TmProtResCounter(ResourceType osResId)
{
    P2VAR(Os_RCBType volatile, AUTOMATIC, OS_VAR) pRcb;
    P2VAR(Os_TCBType const volatile, AUTOMATIC, OS_VAR) pTcb;
    P2VAR(Os_TmProtCbDataDef volatile, AUTOMATIC, OS_VAR) pCbData;
    P2VAR(Os_SCBType const volatile, AUTOMATIC, OS_VAR) pScb;
    boolean Status = TRUE;
    pRcb = &Os_RCB[osResId];
    pCbData = &(pRcb->osResTpData);
    pScb = &Os_SCB;

    /* If occupied by task, if this task is not running, resource lock
     * counter stop. */
    if (pRcb->osWhichTaskOccupy < Os_CfgTaskMax)
    {
        pTcb = &Os_TCB[pRcb->osWhichTaskOccupy]; /* PRQA S 0404 */ /* MISRA Rule 1.3,13.2 */

        if (TASK_STATE_RUNNING != pTcb->taskState)
        {
            Status = FALSE;
        }
    }
    /* If occupied by isr and this isr is pending, resource lock counter stop.*/
    else if (Os_IntNestISR2 >= OS_TMPROT_TARGET_ISR_OFFSET)
    {
        /* Current_isr: Os_IntNestISR2-1;
         * OccupyResource_isr: Os_IntNestISR2-2. */
        /* PRQA S 0404++ */ /* MISRA Rule 1.3,13.2 */
        if (pScb->sysIsrNestQueue[Os_IntNestISR2 - OS_TMPROT_TARGET_ISR_OFFSET] != pRcb->osWhichIsrOccupy)
        /* PRQA S 0404-- */ /* MISRA Rule 1.3,13.2 */
        {
            Status = FALSE;
        }
    }
    else
    {
        Status = FALSE;
    }

    /* Lock_bugdet for this resource is configured. */
    if ((boolean)TRUE == Status)
    {
        if (TRUE == pCbData->osIsTpStart)
        {
            pCbData->osTpTime += 1U;

            if (pCbData->osTpTime >= pCbData->osTpBudget) /* PRQA S 0404 */ /* MISRA Rule 1.3,13.2 */
            {
                pCbData->osTpTime = 0u;
                pCbData->osTpBudget = 0u;
                pCbData->osIsTpStart = FALSE;

                /* Hook. */
                (void)Os_CallProtectionHook(E_OS_PROTECTION_LOCKED, (uint32)pCbData->osWhoHook);
            }
        }
    }

    return;
}

/********************************************************************/
/*
 * Brief                <End process for budget of resource locking.>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <None>
 * param-eventId[in]    <osResId>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_ApplReleaseResource>
 * REQ ID               <DD_1_0880, DD_1_0881, DD_1_1610>
 */
/********************************************************************/
FUNC(void, OS_CODE) Os_TmProtResEnd(ResourceType osResId)
{
    P2VAR(Os_RCBType volatile, AUTOMATIC, OS_VAR) pRcb;
    P2VAR(Os_TmProtCbDataDef volatile, AUTOMATIC, OS_VAR) pCbData;

    pRcb = &Os_RCB[osResId];
    pCbData = &(pRcb->osResTpData);

    /* Stop timing protection for this resource. */
    if (TRUE == pCbData->osIsTpStart)
    {
        pCbData->osIsTpStart = FALSE;
        pCbData->osTpTime = 0u;
        pCbData->osTpBudget = 0u;
        pCbData->osWhoHook = 0u;
    }

    /* Clear the task/isr occupy the resource. */
    pRcb->osWhichTaskOccupy = OS_TASK_INVALID;
    pRcb->osWhichIsrOccupy = OS_ISR_INVALID;

    return;
}
#endif /* #if (CFG_STD_RESOURCE_MAX > 0) */

/********************************************************************/
/*
 * Brief                <Time frame of task: frame check process.>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <Non Reentrant>
 * param-eventId[in]    <osTaskId>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <ActivateTask>
 * REQ ID               <DD_1_0882, DD_1_0883, DD_1_1283>
 */
/********************************************************************/
FUNC(StatusType, OS_CODE) Os_TmProtTaskFrameChk(Os_TaskType osTaskId)
{
    StatusType osRet = E_OK;
    P2VAR(Os_TCBType volatile, AUTOMATIC, OS_VAR) pTcb;
    P2VAR(Os_TmProtCbDataDef volatile, AUTOMATIC, OS_VAR) pCbData;

    /* Idle task should not be protected. */
    if (OS_TASK_IDLE != osTaskId)
    {
        pTcb = &Os_TCB[osTaskId];
        pCbData = &pTcb->osTpTask[TP_TASK_ARRIVAL];

        /* Timing frame for this task is not configed. */
        if (OS_TICK_INVALID != pCbData->osTpBudget)
        {
            /* Timing frame: arrive so frequently. */
            if (TRUE != pTcb->taskTpFrameflag)
            {
                /* Hook. */
                if (PRO_IGNORE != Os_CallProtectionHook(E_OS_PROTECTION_ARRIVAL, OS_TMPROT_HOOK_TASK))
                {
                    osRet = E_OS_ID;
                }
            }
            else
            {
                pCbData->osTpTime = 0U;
                pTcb->taskTpFrameflag = FALSE;
            }
        }
    }

    return osRet;
}

/********************************************************************/
/*
 * Brief                <Time frame of task: frame counter process.>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <Non Reentrant>
 * param-eventId[in]    <osTaskId, osOptType>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_TmProtTaskCounter>
 * REQ ID               <DD_1_0987, DD_1_0988, DD_1_1551>
 */
/********************************************************************/
static FUNC(void, OS_CODE) Os_TmProtTaskFrameCounter(Os_TaskType osTaskId, Os_TmProtOptTaskType osOptType)
{
    P2VAR(Os_TCBType volatile, AUTOMATIC, OS_VAR) pTcb;
    P2VAR(Os_TmProtCbDataDef volatile, AUTOMATIC, OS_VAR) pCbData;

    pTcb = &Os_TCB[osTaskId];

    /* Task has been actived. */
    if (TRUE != pTcb->taskTpFrameflag)
    {
        pCbData = &(pTcb->osTpTask[osOptType]);

        pCbData->osTpTime += 1U;

        if (pCbData->osTpTime >= pCbData->osTpBudget) /* PRQA S 0404 */ /* MISRA Rule 1.3,13.2 */
        {
            /* Set taskTpFrameflag, so the task can be actived again. */
            pTcb->taskTpFrameflag = TRUE;
            pCbData->osTpTime = 0u;
        }
    }

    return;
}

/********************************************************************/
/*
 * Brief                <Timing protection start process of task.>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <Non Reentrant>
 * param-eventId[in]    <osTaskId, osOptType>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <DisableAllInterrupts>
 * REQ ID               <DD_1_0884, DD_1_0885, DD_1_1296>
 */
/********************************************************************/
FUNC(void, OS_CODE) Os_TmProtTaskStart(Os_TaskType osTaskId, Os_TmProtOptTaskType osOptType)
{
    P2VAR(Os_TCBType volatile, AUTOMATIC, OS_VAR) pTcb;
    P2VAR(Os_TmProtCbDataDef volatile, AUTOMATIC, OS_VAR) pCbData;

    /* Idle task should not be protected. */
    if (OS_TASK_IDLE != osTaskId)
    {
        pTcb = &Os_TCB[osTaskId];
        pCbData = &(pTcb->osTpTask[osOptType]);

        /* This task cfg timing protection. */
        if (OS_TICK_INVALID != pCbData->osTpBudget)
        {
            if (TRUE != pCbData->osIsTpStart)
            {
                pCbData->osIsTpStart = TRUE;
                pCbData->osTpTime = 0u;
            }
        }
    }

    return;
}

/********************************************************************/
/*
 * Brief                <Timing protection counter process of task.>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <Non Reentrant>
 * param-eventId[in]    <osTaskId, osOptType>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_TmProtTaskProc>
 * REQ ID               <DD_1_0989, DD_1_0990, DD_1_1282, DD_1_1292, DD_1_1293,
 *                       DD_1_1294, DD_1_1550>
 */
/********************************************************************/
static FUNC(void, OS_CODE) Os_TmProtTaskCounter(Os_TaskType osTaskId, Os_TmProtOptTaskType osOptType)
{
    StatusType osErrType;
    P2VAR(Os_TCBType volatile, AUTOMATIC, OS_VAR) pTcb;
    P2VAR(Os_TmProtCbDataDef volatile, AUTOMATIC, OS_VAR) pCbData;

    /* Inter-arrival time. */
    if (TP_TASK_ARRIVAL == osOptType)
    {
        Os_TmProtTaskFrameCounter(osTaskId, osOptType);
    }
    else /* Other budget. */
    {
        pTcb = &Os_TCB[osTaskId];

        pCbData = &(pTcb->osTpTask[osOptType]);

        if (TRUE == pCbData->osIsTpStart)
        {
            if (OS_TMPROT_TARGET_ISR_OFFSET <= Os_IntNestISR2)
            {
                /*nothing to do*/
            }
            else
            {
                pCbData->osTpTime += 1U;

                if (pCbData->osTpTime >= pCbData->osTpBudget) /* PRQA S 0404 */ /* MISRA Rule 1.3,13.2 */
                {
                    pCbData->osTpTime = 0u;
                    pCbData->osIsTpStart = FALSE;

                    /* Get error type. */
                    if (TP_TASK_EXE == osOptType)
                    {
                        osErrType = E_OS_PROTECTION_TIME;
                    }
                    else
                    {
                        osErrType = E_OS_PROTECTION_LOCKED;
                    }
                    /* Resource lock is not maintained in this function. */

                    /* Hook. */
                    (void)Os_CallProtectionHook(osErrType, OS_TMPROT_HOOK_TASK);
                }
            }
        }
    }

    return;
}

/********************************************************************/
/*
 * Brief                <Timing protection end process of task.>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <Non Reentrant>
 * param-eventId[in]    <osTaskId, osOptType>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_ApplTerminateOneTask and so on>
 * REQ ID               <DD_1_0886, DD_1_0887, DD_1_1295>
 */
/********************************************************************/
FUNC(void, OS_CODE) Os_TmProtTaskEnd(Os_TaskType osTaskId, Os_TmProtOptTaskType osOptType)
{
    P2VAR(Os_TCBType volatile, AUTOMATIC, OS_VAR) pTcb;
    P2VAR(Os_TmProtCbDataDef volatile, AUTOMATIC, OS_VAR) pCbData;

    /* Idle task should not be protected. */
    if (OS_TASK_IDLE != osTaskId)
    {
        pTcb = &Os_TCB[osTaskId];
        pCbData = &(pTcb->osTpTask[osOptType]);

        if (TRUE == pCbData->osIsTpStart)
        {
            pCbData->osIsTpStart = FALSE;
            pCbData->osTpTime = 0u;
        }
    }

    return;
}

#if (CFG_ISR2_MAX > 0U)
/********************************************************************/
/*
 * Brief                <Time frame of task: frame check process.>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <Non Reentrant>
 * param-eventId[in]    <osTaskId>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <None>
 * REQ ID               <DD_1_0888, DD_1_0889, DD_1_1284>
 */
/********************************************************************/
FUNC(StatusType, OS_CODE) Os_TmProtIsrFrameChk(Os_IsrType osIsrId) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    StatusType osRet = E_OK;
    P2VAR(Os_ICBType volatile, AUTOMATIC, OS_VAR) pIcb;
    P2VAR(Os_TmProtCbDataDef volatile, AUTOMATIC, OS_VAR) pCbData;

    /* Note: When Os_ArchSystemTimer isr arrive, Os_IntCfgIsrId is
     * not set to vaild value.
     * On tc1782, priority of Os_ArchSystemTimer isr is 255. */
    if (osIsrId < CFG_ISR_MAX)
    {
        pIcb = &Os_ICB[osIsrId];
        pCbData = &pIcb->osTpIsr[TP_ISR_CAT2_ARRIVAL];

        /* Timing frame for this isr is configed. */
        if (OS_TICK_INVALID != pCbData->osTpBudget)
        {
            /* Timing frame: arrive so frequently. */
            if (TRUE != pIcb->osIsrTpFrameflag)
            {
                /* Hook. */
                if (PRO_IGNORE != Os_CallProtectionHook(E_OS_PROTECTION_ARRIVAL, OS_TMPROT_HOOK_ISR))
                {
                    pCbData->osTpTime = 0U;
                    osRet = E_OS_ID;
                }
            }
            else
            {
                pCbData->osTpTime = 0U;
                pIcb->osIsrTpFrameflag = FALSE;
            }
        }
    }

    return osRet;
}

/********************************************************************/
/*
 * Brief                <Timing protection timing frame process of isr.>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <Non Reentrant>
 * param-eventId[in]    <osTaskId, osOptType>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_TmProtIsrCounter>
 * REQ ID               <DD_1_0991, DD_1_0992, DD_1_1490, DD_1_1491>
 */
/********************************************************************/
static FUNC(void, OS_CODE) Os_TmProtIsrFrameCounter(Os_IsrType osIsrId, Os_TmProtOptIsrType osOptType)
{
    P2VAR(Os_ICBType volatile, AUTOMATIC, OS_VAR) pIcb;
    P2VAR(Os_TmProtCbDataDef volatile, AUTOMATIC, OS_VAR) pCbData;

    pIcb = &Os_ICB[osIsrId];

    /* Isr has been called. */
    if (TRUE != pIcb->osIsrTpFrameflag)
    {
        pCbData = &(pIcb->osTpIsr[osOptType]);

        pCbData->osTpTime += 1U;

        /* Set osIsrTpFrameflag to true, so the isr can be called again. */
        if (pCbData->osTpTime >= pCbData->osTpBudget) /* PRQA S 0404 */ /* MISRA Rule 1.3,13.2 */
        {
            pIcb->osIsrTpFrameflag = TRUE;
            pCbData->osTpTime = 0U;
        }
    }

    return;
}

/********************************************************************/
/*
 * Brief                <Timing protection start process of isr.>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <Non Reentrant>
 * param-eventId[in]    <osTaskId, osOptType>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <DisableAllInterrupts>
 * REQ ID               <DD_1_0890, DD_1_0891, DD_1_1527>
 */
/********************************************************************/
/* PRQA S 1532++ */ /* MISRA Rule 8.7 */
FUNC(void, OS_CODE) Os_TmProtIsrStart(Os_IsrType osIsrId, Os_TmProtOptIsrType osOptType)
/* PRQA S 1532-- */ /* MISRA Rule 8.7 */
{
    P2VAR(Os_ICBType volatile, AUTOMATIC, OS_VAR) pIcb;
    P2VAR(Os_TmProtCbDataDef volatile, AUTOMATIC, OS_VAR) pCbData;

    pIcb = &Os_ICB[osIsrId];
    pCbData = &(pIcb->osTpIsr[osOptType]);

    /* This isr cfg timing protection. */
    if (OS_TICK_INVALID != pCbData->osTpBudget)
    {
        if (TRUE != pCbData->osIsTpStart)
        {
            pCbData->osIsTpStart = TRUE;
            pCbData->osTpTime = 0u;
        }
    }

    return;
}

/********************************************************************/
/*
 * Brief                <Timing protection counter process of isr.>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <Non Reentrant>
 * param-eventId[in]    <osTaskId, osOptType>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_TmProtIsrProc>
 * REQ ID               <DD_1_0993, DD_1_0994, DD_1_1285, DD_1_1289, DD_1_1290,
 *                       DD_1_1291, DD_1_0994>
 */
/********************************************************************/
static FUNC(void, OS_CODE) Os_TmProtIsrCounter(Os_IsrType osIsrId, Os_TmProtOptIsrType osOptType)
{
    StatusType osErrType;
    P2VAR(Os_ICBType volatile, AUTOMATIC, OS_VAR) pIcb;
    P2VAR(Os_TmProtCbDataDef volatile, AUTOMATIC, OS_VAR) pCbData;

    /* Inter-arrival time. */
    if (TP_ISR_CAT2_ARRIVAL == osOptType)
    {
        Os_TmProtIsrFrameCounter(osIsrId, osOptType);
    }
    else
    {
        pIcb = &Os_ICB[osIsrId];

        pCbData = &(pIcb->osTpIsr[osOptType]);

        if (TRUE == pCbData->osIsTpStart)
        {
            pCbData->osTpTime += 1U;

            if (pCbData->osTpTime >= pCbData->osTpBudget) /* PRQA S 0404 */ /* MISRA Rule 1.3,13.2 */
            {
                pCbData->osTpTime = 0u;
                pCbData->osIsTpStart = FALSE;

                /* Get error type. */
                if (TP_ISR_CAT2_EXE == osOptType)
                {
                    osErrType = E_OS_PROTECTION_TIME;
                }
                else
                {
                    osErrType = E_OS_PROTECTION_LOCKED;
                }
                /* TP_ISR_ARRIVAL and resource lock are not maintained
                 * in this function. */

                /* Hook. */
                (void)Os_CallProtectionHook(osErrType, OS_TMPROT_HOOK_ISR);
            }
        }
    }

    return;
}

/********************************************************************/
/*
 * Brief                <Timing protection end process of isr.>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <Non Reentrant>
 * param-eventId[in]    <osTaskId, osOptType>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_AppTerminateIsrKernelProc and so on>
 * REQ ID               <DD_1_0892, DD_1_0893, DD_1_1286>
 */
/********************************************************************/
FUNC(void, OS_CODE) Os_TmProtIsrEnd(Os_IsrType osIsrId, Os_TmProtOptIsrType osOptType)
{
    P2VAR(Os_ICBType volatile, AUTOMATIC, OS_VAR) pIcb;
    P2VAR(Os_TmProtCbDataDef volatile, AUTOMATIC, OS_VAR) pCbData;

    pIcb = &Os_ICB[osIsrId];

    pCbData = &(pIcb->osTpIsr[osOptType]);

    if (TRUE == pCbData->osIsTpStart)
    {
        pCbData->osIsTpStart = FALSE;
        pCbData->osTpTime = 0u;
    }

    return;
}

#if (CFG_STD_RESOURCE_MAX > 0)
/********************************************************************/
/*
 * Brief                <Init resource lock budget for isr.>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <None>
 * param-eventId[in]    <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_InitIsrTmProt>
 * REQ ID               <DD_1_0995, DD_1_0996>
 */
/********************************************************************/
static FUNC(void, OS_CODE)
    Os_TmProtInitIsrResLock(Os_IsrType osIsrId, P2CONST(Os_IsrCfgType, AUTOMATIC, OS_VAR) pIsrCfg)
{
    uint16 i;
    uint32 osResCnt;
    P2VAR(Os_RCBType const volatile, AUTOMATIC, OS_VAR) pRcb;
    P2CONST(Os_IsrResLockType, AUTOMATIC, OS_VAR) pResLock;

    /* If Isr cfg OsIsrResourceLock, read budget to RCB. */
    if (NULL_PTR != pIsrCfg->OsIsrTimePt)
    {
        osResCnt = pIsrCfg->OsIsrTimePt->osIsrResLockCnt;

        for (i = 0u; i < osResCnt; i++)
        {
            /* Misrac: Msg(2:0491) Array subscripting applied to an
             * object of pointer type.
             * Note: osIsrResLockRef is array. osIsrResLockCnt is variable,
             * so osIsrResLockRef must be used like below.
             */
            pResLock = &pIsrCfg->OsIsrTimePt->osIsrResLockRef[i];

            pRcb = &Os_RCB[Os_GetObjLocalId(pResLock->osIsrResLockResRef)];

            /* Read budget to RCB. */
            pRcb->osTmProtResBgtIsr[osIsrId] = pResLock->osIsrResLockBudget;
        }
    }

    return;
}
#endif /* #if (CFG_STD_RESOURCE_MAX > 0) */

/********************************************************************/
/*
 * Brief                <Init timing protection for isr.>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <None>
 * param-eventId[in]    <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_InitTmProt>
 * REQ ID               <DD_1_0997, DD_1_0998>
 */
/********************************************************************/
static FUNC(void, OS_CODE) Os_InitIsrTmProt(
    Os_IsrType osIsrId,
    P2CONST(Os_IsrCfgType, AUTOMATIC, OS_VAR) pIsrCfg,
    P2VAR(Os_ICBType volatile, AUTOMATIC, OS_VAR) pIcb)
{
    P2CONST(Os_IsrTimingProtectionType, AUTOMATIC, OS_VAR) pIsrTimePt;

    pIcb->IsrC2IsrOpt = TP_OPT_BUTT;
    pIcb->osIsrTpFrameflag = TRUE;

#if (CFG_STD_RESOURCE_MAX > 0U)
    pIcb->IsrC2ResCount = 0u;
#endif /* CFG_STD_RESOURCE_MAX > 0U */

    pIsrTimePt = pIsrCfg->OsIsrTimePt;

    /* Set budget of each type. */
    if (NULL_PTR == pIsrTimePt)
    {
        Os_TmProtInitCbData(&pIcb->osTpIsr[TP_ISR_CAT2_EXE], OS_TICK_INVALID);
        Os_TmProtInitCbData(&pIcb->osTpIsr[TP_ISR_CAT2_ARRIVAL], OS_TICK_INVALID);
        Os_TmProtInitCbData(&pIcb->osTpIsr[TP_ISR_CAT2_SUS_OS_INT], OS_TICK_INVALID);
        Os_TmProtInitCbData(&pIcb->osTpIsr[TP_ISR_CAT2_SUS_ALL_INT], OS_TICK_INVALID);
        Os_TmProtInitCbData(&pIcb->osTpIsr[TP_ISR_CAT2_DIS_ALL_INT], OS_TICK_INVALID);
    }
    else
    {
        Os_TmProtInitCbData(&pIcb->osTpIsr[TP_ISR_CAT2_EXE], pIsrTimePt->osIsrExeBudget);
        Os_TmProtInitCbData(&pIcb->osTpIsr[TP_ISR_CAT2_ARRIVAL], pIsrTimePt->osIsrTimeFrame);
        Os_TmProtInitCbData(&pIcb->osTpIsr[TP_ISR_CAT2_SUS_OS_INT], pIsrTimePt->osIsrOsIptLockBudget);
        Os_TmProtInitCbData(&pIcb->osTpIsr[TP_ISR_CAT2_SUS_ALL_INT], pIsrTimePt->osIsrAllIptLockBudget);
        Os_TmProtInitCbData(&pIcb->osTpIsr[TP_ISR_CAT2_DIS_ALL_INT], pIsrTimePt->osIsrAllIptLockBudget);
    }

/* Init resource lock budget for isr. */
#if (CFG_STD_RESOURCE_MAX > 0)
    Os_TmProtInitIsrResLock(osIsrId, pIsrCfg);
#endif /* CFG_STD_RESOURCE_MAX > 0 */

    return;
}
#endif /* #if (CFG_ISR2_MAX > 0U) */

#if (CFG_STD_RESOURCE_MAX > 0)
/********************************************************************/
/*
 * Brief                <Init resource lock budget for task.>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <None>
 * param-eventId[in]    <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_InitTaskTmProt>
 * REQ ID               <DD_1_0999, DD_1_1000>
 */
/********************************************************************/
static FUNC(void, OS_CODE)
    Os_TmProtInitTaskResLock(Os_TaskType osTaskId, P2CONST(Os_TaskCfgType, AUTOMATIC, OS_VAR) pTaskCfg)
{
    uint16 i;
    uint16 osCnt;
    P2VAR(Os_RCBType const volatile, AUTOMATIC, OS_VAR) pRcb;
    P2CONST(Os_TaskResLockType, AUTOMATIC, OS_VAR) pResLock;

    /* If task cfg OsTaskResourceLock, read budget to RCB. */
    if (NULL_PTR != pTaskCfg->osTaskTmProtCfgRef->osTaskResLockRef)
    {
        osCnt = pTaskCfg->osTaskTmProtCfgRef->osTaskResLockCnt;

        for (i = 0u; i < osCnt; i++)
        {
            /* Misrac: Msg(2:0491) Array subscripting applied to an object of
             * pointer type.
             * Note: osTaskResLockRef is array. osTaskResLockCnt is variable,
             * so osTaskResLockRef must be used like below. */
            pResLock = &pTaskCfg->osTaskTmProtCfgRef->osTaskResLockRef[i];

            pRcb = &Os_RCB[Os_GetObjLocalId(pResLock->OsTaskResLockResRef)];

            /* Read budget to RCB. */
            pRcb->osTmProtResBgtTask[osTaskId] = pResLock->OsTaskResLockBudget;
        }
    }

    return;
}
#endif /* #if (CFG_STD_RESOURCE_MAX > 0) */

/********************************************************************/
/*
 * Brief                <Init timing protection for task.>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <None>
 * param-eventId[in]    <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_InitTmProt>
 * REQ ID               <DD_1_1001, DD_1_1002>
 */
/********************************************************************/
static FUNC(void, OS_CODE) Os_InitTaskTmProt(
    Os_TaskType osTaskId,
    P2CONST(Os_TaskCfgType, AUTOMATIC, OS_VAR) pTaskCfg,
    P2VAR(Os_TCBType volatile, AUTOMATIC, OS_VAR) pTcb)
{
    P2CONST(Os_TaskTmProtCfgType, AUTOMATIC, OS_VAR) pTaskTmProtCfgRef;

    pTcb->taskIsrOpt = TP_OPT_BUTT;
    pTcb->taskTpFrameflag = TRUE;

#if (CFG_STD_RESOURCE_MAX > 0U)
    pTcb->taskResCount = 0u;
#endif /* CFG_STD_RESOURCE_MAX > 0 */

    pTaskTmProtCfgRef = pTaskCfg->osTaskTmProtCfgRef;

    /* Set budget of each type. NULL_PTR means not configed. */
    if (NULL_PTR == pTaskTmProtCfgRef)
    {
        Os_TmProtInitCbData(&pTcb->osTpTask[TP_TASK_EXE], OS_TICK_INVALID);
        Os_TmProtInitCbData(&pTcb->osTpTask[TP_TASK_ARRIVAL], OS_TICK_INVALID);
        Os_TmProtInitCbData(&pTcb->osTpTask[TP_TASK_SUS_OS_INT], OS_TICK_INVALID);
        Os_TmProtInitCbData(&pTcb->osTpTask[TP_TASK_SUS_ALL_INT], OS_TICK_INVALID);
        Os_TmProtInitCbData(&pTcb->osTpTask[TP_TASK_DIS_ALL_INT], OS_TICK_INVALID);
    }
    else
    {
        Os_TmProtInitCbData(&pTcb->osTpTask[TP_TASK_EXE], pTaskTmProtCfgRef->osTaskExecutionBudget);
        Os_TmProtInitCbData(&pTcb->osTpTask[TP_TASK_ARRIVAL], pTaskTmProtCfgRef->osTaskTimeFrame);
        Os_TmProtInitCbData(&pTcb->osTpTask[TP_TASK_SUS_OS_INT], pTaskTmProtCfgRef->osTaskOsInterruptLockBudget);
        Os_TmProtInitCbData(&pTcb->osTpTask[TP_TASK_SUS_ALL_INT], pTaskTmProtCfgRef->osTaskAllInterruptLockBudget);
        Os_TmProtInitCbData(&pTcb->osTpTask[TP_TASK_DIS_ALL_INT], pTaskTmProtCfgRef->osTaskAllInterruptLockBudget);

/* Init resource lock budget for task. */
#if (CFG_STD_RESOURCE_MAX > 0)
        Os_TmProtInitTaskResLock(osTaskId, pTaskCfg);
#endif /* CFG_STD_RESOURCE_MAX > 0 */
    }

    return;
}

/********************************************************************/
/*
 * Brief                <Init protection module.>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <None>
 * param-eventId[in]    <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_InitSystem>
 * REQ ID               <DD_1_0894, DD_1_0895>
 */
/********************************************************************/
FUNC(void, OS_CODE) Os_InitTmProt(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    uint16 i;

/* Init protection para for task. */
#if (CFG_TASK_MAX > 0)
    for (i = 0U; i < Os_CfgTaskMax; i++)
    {
        Os_InitTaskTmProt((Os_TaskType)i, &Os_TaskCfg[i], &Os_TCB[i]);
    }
#endif /* CFG_TASK_MAX > 0 */

#if (CFG_ISR2_MAX > 0U)
    /* Init protection para for Isr-Cat2. */
    for (i = 0U; i < Os_CfgIsr2Max; i++)
    {
        Os_InitIsrTmProt((Os_IsrType)i, &Os_IsrCfg[i], &Os_ICB[i]);
    }
#endif /* CFG_ISR2_MAX > 0 */

    return;
}

#if (CFG_ISR2_MAX > 0U)
/********************************************************************/
/*
 * Brief                <Timing Protection isr process.>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <None>
 * param-eventId[in]    <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_TmProtMainProc>
 * REQ ID               <DD_1_1003, DD_1_1004, DD_1_1488>
 */
/********************************************************************/
static FUNC(void, OS_CODE) Os_TmProtIsrProc(void)
{
    uint16 i;
    Os_IsrType osIsrC2Id;
    P2CONST(Os_IsrCfgType, AUTOMATIC, OS_VAR) pIsrCfg;
    P2VAR(Os_SCBType const volatile, AUTOMATIC, OS_VAR) pScb;

    pScb = &Os_SCB;

    /* IntNest: current_isr is isr for timing protection,
     * previous_isr is the target to protect. */
    if (Os_IntNestISR2 >= OS_TMPROT_TARGET_ISR_OFFSET)
    {
        osIsrC2Id = pScb->sysIsrNestQueue[Os_IntNestISR2 - OS_TMPROT_TARGET_ISR_OFFSET];
        if (osIsrC2Id < CFG_ISR_MAX)
        {
            pIsrCfg = &Os_IsrCfg[osIsrC2Id];
            if (OS_ISR_CATEGORY2 == pIsrCfg->OsIsrCatType)
            {
                Os_TmProtIsrCounter(osIsrC2Id, TP_ISR_CAT2_EXE);
                Os_TmProtIsrCounter(osIsrC2Id, TP_ISR_CAT2_SUS_OS_INT);
                Os_TmProtIsrCounter(osIsrC2Id, TP_ISR_CAT2_SUS_ALL_INT);
                Os_TmProtIsrCounter(osIsrC2Id, TP_ISR_CAT2_DIS_ALL_INT);
            }
        }
    }

/* IntNest: arrival time should be checked for each isr. */
#if (CFG_ISR2_MAX > 0U)
    for (i = (Os_CfgIsrMax - Os_CfgIsr2Max); i < Os_CfgIsr2Max; i++)
    {
        /* Current_isr is running isr, this isr is for timing counter.
         * It should not be protected. */
        if (i != pScb->sysRunningIsrCat2Id)
        {
            Os_TmProtIsrCounter(i, TP_ISR_CAT2_ARRIVAL);
        }
    }
#endif /* CFG_ISR2_MAX > 0 */

    return;
}
#endif /* CFG_ISR2_MAX > 0 */

/********************************************************************/
/*
 * Brief                <Timing Protection task process.>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <None>
 * param-eventId[in]    <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_TmProtMainProc>
 * REQ ID               <DD_1_1005, DD_1_1006, DD_1_1162>
 */
/********************************************************************/
static FUNC(void, OS_CODE) Os_TmProtTaskProc(void)
{
    uint16 i;
    Os_TaskStateType osTaskState;

#if (CFG_TASK_MAX > 0)
    for (i = 0U; i < Os_CfgTaskMax; i++)
    {
        /* Implementation-dependent: IDLE task should not be protected. */
        if (OS_TASK_IDLE != (Os_TaskType)i)
        {
            osTaskState = Os_TCB[i].taskState;

            if (TASK_STATE_RUNNING == osTaskState)
            {
                /* Exe_budget only checked in running state. */
                Os_TmProtTaskCounter((Os_TaskType)i, TP_TASK_EXE);
                Os_TmProtTaskCounter((Os_TaskType)i, TP_TASK_ARRIVAL);
                Os_TmProtTaskCounter((Os_TaskType)i, TP_TASK_SUS_OS_INT);
                Os_TmProtTaskCounter((Os_TaskType)i, TP_TASK_SUS_ALL_INT);
                Os_TmProtTaskCounter((Os_TaskType)i, TP_TASK_DIS_ALL_INT);
            }
            else
            {
                /* Time-frame is checked in running and ready states. */
                Os_TmProtTaskCounter((Os_TaskType)i, TP_TASK_ARRIVAL);
            }
        }
    }
#endif /* CFG_TASK_MAX > 0 */

    return;
}

/********************************************************************/
/*
 * Brief                <Timing Protection isr callback.>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <None>
 * param-eventId[in]    <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <ISR>
 * REQ ID               <DD_1_0896, DD_1_0897, DD_1_1163, DD_1_1528, DD_1_1484,
 *                       DD_1_1485, DD_1_1539>
 */
/********************************************************************/
FUNC(void, OS_CODE) Os_TmProtMainProc(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    uint16 i;

    /* 1: Timing Protection for task. */
    Os_TmProtTaskProc();

/* 2: Timing Protection for Resource lock. */
#if (CFG_STD_RESOURCE_MAX > 0)
    for (i = 0u; i < Os_CfgResourceMax; i++)
    {
        Os_TmProtResCounter((ResourceType)i);
    }
#endif /* #if (CFG_STD_RESOURCE_MAX > 0) */

/* 3: Timing Protection for Isr2. */
#if (CFG_ISR2_MAX > 0)
    Os_TmProtIsrProc();
#endif /* CFG_ISR2_MAX > 0 */

    return;
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#endif /* #if (TRUE == CFG_TIMING_PROTECTION_ENABLE) */

/* Misrac: Msg(3:0862) This #include "D:/TestPrj/TriCore/Include/Os_MemMap.h"
 * directive is redundant.
 * Note: For memory map, stay the same as other modules. */
