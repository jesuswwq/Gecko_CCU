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
**  FILENAME    : Os_Hook.c                                                   **
**                                                                            **
**  Created on  :                                                             **
**  Author      :                                                             **
**  Vendor      :                                                             **
**  DESCRIPTION : hook manager                                                **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>    <AUTHOR>        <REVISION LOG>
 *  V0.1.0     2017-07-19    zuxiong.ding    Move from Os_Kernel.
 *  V0.2.0     2019-08-21    shun.li & zhiqiang.huang   Functional safety initial version.
 *  V1.0.0     2019-11-21    shun.li         Functional safety version.
 *  V1.0.1     2021-08-19    shun.li         Modify release spinlock in mutlti-core.
 */
/*============================================================================*/

/*=======[I N C L U D E S]====================================================*/
#include "Os_Internal.h"

/*=======[M A C R O S]========================================================*/

/*=======[T Y P E   D E F I N I T I O N S]====================================*/

/*=======[E X T E R N A L   D A T A]==========================================*/

/*=======[E X T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/

/*=======[I N T E R N A L   D A T A]==========================================*/

/*=======[I N T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/

/*=======[F U N C T I O N   I M P L E M E N T A T I O N S]====================*/

#if (TRUE == CFG_PROTECTIONHOOK)
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/******************************************************************************/
/*
 * Brief                <check the running task ID is legal,
 *                          running task ID < idle task ID
 *                          running Isr2 ID < CFG_ISR2_MAX>
 * Service ID   :       <Check whether the running task and interrupt ID are legitimate>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <Os_CallProtectionHook>
 * REQ ID               <DD_1_0926>
 */
/******************************************************************************/
static FUNC(Std_ReturnType, OS_CODE) Os_CheckRunningTaskIDandIsr2ID(uint32 osWhoHook)
{
    Std_ReturnType OsReturnErr = E_NOT_OK;

    if (OS_TMPROT_HOOK_TASK == osWhoHook)
    {
        if (Os_SCB.sysRunningTaskID < OS_TASK_IDLE)
        {
            OsReturnErr = E_OK;
        }
        else
        {
            OsReturnErr = E_NOT_OK;
        }
    }

#if (CFG_ISR2_MAX > 0)
    if (OS_TMPROT_HOOK_ISR == osWhoHook)
    {
        if (Os_SCB.sysRunningIsrCat2Id < Os_CfgIsr2Max)
        {
            OsReturnErr = E_OK;
        }
        else
        {
            OsReturnErr = E_NOT_OK;
        }
    }
#endif /* CFG_ISR2_MAX > 0 */

    return OsReturnErr;
}
#endif /*#if (TRUE == CFG_PROTECTIONHOOK)*/

/* Attention: this function is only called in os_kernel. Usr_app or test_case_app
 * can not call this function directly. */
#if ((TRUE == CFG_ERRORHOOK) || (TRUE == CFG_APPL_ERRORHOOK))
/******************************************************************************/
/*
 * Brief                <Call the error hook function>
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * param[in]            <Error>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <TerminateApplication and so on>
 * REQ ID               <DD_1_0791, DD_1_0792, DD_1_1546, DD_1_1243, DD_1_1244, DD_1_1245,
 *                       DD_1_1246, DD_1_1157, DD_1_1616>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_CallErrorHook(StatusType Error)
{
    Os_CallLevelType osSameLevel;
    OS_ARCH_DECLARE_CRITICAL();
#if (TRUE == CFG_APPL_ERRORHOOK)
    P2CONST(Os_ApplicationCfgType, AUTOMATIC, OS_VAR) pAppCfg;
#endif /* TRUE == CFG_APPL_ERRORHOOK */

    if (OS_LEVEL_ERRORHOOK == Os_SCB.sysOsLevel)
    {
        /*nothing to do*/
    }
    else
    {
        OS_ARCH_ENTRY_CRITICAL();

/*Triggering the error hook is Task or Isr,then update the running ApplID and Object*/
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
        if (OS_LEVEL_TASK == Os_SCB.sysOsLevel)
        {
            Os_SCB.sysRunningAppID = Os_ObjectAppCfg[OBJECT_TASK][Os_SCB.sysRunningTaskID].hostApp;
            Os_SCB.sysRunningAppObj = OBJECT_TASK;
        }
        if (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel)
        {
            Os_SCB.sysRunningAppID = Os_ObjectAppCfg[OBJECT_ISR][Os_SCB.sysRunningIsrCat2Id].hostApp;
            Os_SCB.sysRunningAppObj = OBJECT_ISR;
        }
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */

        osSameLevel = Os_SCB.sysOsLevel;
        Os_SCB.sysOsLevel = OS_LEVEL_ERRORHOOK;

#if (TRUE == CFG_ERRORHOOK)
        OS_ERRHOOK_ENTRY();
        ErrorHook(Error);
        OS_ERRHOOK_EXIT();
#endif /* TRUE == CFG_ERRORHOOK */

/* If cfg, call application_specific hook. */
#if (TRUE == CFG_APPL_ERRORHOOK)
        pAppCfg = &Os_AppCfg[Os_SCB.sysRunningAppID];

        if (NULL_PTR != pAppCfg->OsApplicationHooks.OsAppErrorHook)
        {
            Os_SCB.sysOsLevel = OS_LEVEL_ERRORHOOK_APP;
            pAppCfg->OsApplicationHooks.OsAppErrorHook(Error);
        }
#endif /* TRUE == CFG_APPL_ERRORHOOK */

        Os_SCB.sysOsLevel = osSameLevel;

        OS_ARCH_EXIT_CRITICAL();
    }
}
#endif /* (TRUE == CFG_ERRORHOOK) || (TRUE == CFG_APPL_ERRORHOOK) */

#if (TRUE == CFG_PRETASKHOOK)
/********************************************************************/
/*
 * Brief                <Call the PreTask hook function>
 * Service ID           <none>
 * Sync/Async           <none>
 * Reentrancy           <none>
 * param-eventId[in]    <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_SwitchTask>
 * REQ ID               <DD_1_0793, DD_1_0794, DD_1_1548>
 *
 */
/********************************************************************/
FUNC(void, OS_CODE) Os_CallPreTaskHook(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Os_CallLevelType osSameLevel;
    OS_ARCH_DECLARE_CRITICAL();

    OS_ARCH_ENTRY_CRITICAL();
/*if task trigger the pretask hook ,update the running ApplID and Object*/
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
    if (OS_LEVEL_TASK == Os_SCB.sysOsLevel)
    {
        Os_SCB.sysRunningAppID = Os_ObjectAppCfg[OBJECT_TASK][Os_SCB.sysRunningTaskID].hostApp;
        Os_SCB.sysRunningAppObj = OBJECT_TASK;
    }
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */

    osSameLevel = Os_SCB.sysOsLevel;
    Os_SCB.sysOsLevel = OS_LEVEL_PRETASKHOOK;

    OS_PREHOOK_ENTRY();
    PreTaskHook();
    OS_PREHOOK_EXIT();

    Os_SCB.sysOsLevel = osSameLevel;
    OS_ARCH_EXIT_CRITICAL();
}
#endif /* TRUE == CFG_PRETASKHOOK */

#if (TRUE == CFG_POSTTASKHOOK)
/******************************************************************************/
/*
 * Brief                <Call the Post Task hook function>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * param[in]            <None>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <WaitEvent and so on>
 * REQ ID               <DD_1_0795, DD_1_0796>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_CallPostTaskHook(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Os_CallLevelType osSameLevel;
    OS_ARCH_DECLARE_CRITICAL();

    OS_ARCH_ENTRY_CRITICAL();
/*if task trigger the posttask hook ,update the running ApplID and Object*/
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
    if (OS_LEVEL_TASK == Os_SCB.sysOsLevel)
    {
        Os_SCB.sysRunningAppID = Os_ObjectAppCfg[OBJECT_TASK][Os_SCB.sysRunningTaskID].hostApp;
        Os_SCB.sysRunningAppObj = OBJECT_TASK;
    }
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */

    osSameLevel = Os_SCB.sysOsLevel;
    Os_SCB.sysOsLevel = OS_LEVEL_POSTTASKHOOK;

    OS_POSTHOOK_ENTRY();
    PostTaskHook();
    OS_POSTHOOK_EXIT();

    Os_SCB.sysOsLevel = osSameLevel;
    OS_ARCH_EXIT_CRITICAL();
}
#endif /* TRUE == CFG_POSTTASKHOOK */

#if (TRUE == CFG_STARTUPHOOK)
/******************************************************************************/
/*
 * Brief                <Call the Startup hook function>
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * param[in]            <None>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <StartOS>
 * REQ ID               <DD_1_0797, DD_1_0798, DD_1_1618>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_CallStartupHook(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Os_CallLevelType osSameLevel;

    osSameLevel = Os_SCB.sysOsLevel;
    Os_SCB.sysOsLevel = OS_LEVEL_STARTUPHOOK;

    OS_STHOOK_ENTRY();
    StartupHook();
    OS_STHOOK_EXIT();

    Os_SCB.sysOsLevel = osSameLevel;
}
#endif /* TRUE == CFG_STARTUPHOOK */

#if (TRUE == CFG_SHUTDOWNHOOK)
/******************************************************************************/
/*
 * Brief                <Call the Shutdown hook function>
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * param[in]            <Error>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <ShutdownOS and so on>
 * REQ ID               <DD_1_0799, DD_1_0800, DD_1_1263, DD_1_1549>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_CallShutdownHook(StatusType Error)
{
    Os_CallLevelType osSameLevel;
    OS_ARCH_DECLARE_CRITICAL();

    OS_ARCH_ENTRY_CRITICAL();
/*Triggering the shutdown hook is Task or Isr,then update the running ApplID and Object*/
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
    if (OS_LEVEL_TASK == Os_SCB.sysOsLevel)
    {
        Os_SCB.sysRunningAppID = Os_ObjectAppCfg[OBJECT_TASK][Os_SCB.sysRunningTaskID].hostApp;
        Os_SCB.sysRunningAppObj = OBJECT_TASK;
    }
    if ((OS_LEVEL_ISR1 == Os_SCB.sysOsLevel) || (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel))
    {
        Os_SCB.sysRunningAppID = Os_ObjectAppCfg[OBJECT_ISR][Os_SCB.sysRunningIsrCat2Id].hostApp;
        Os_SCB.sysRunningAppObj = OBJECT_ISR;
    }
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */

    osSameLevel = Os_SCB.sysOsLevel;
    Os_SCB.sysOsLevel = OS_LEVEL_SHUTDOWNHOOK;

    OS_SDHOOK_ENTRY();
    ShutdownHook(Error);
    OS_SDHOOK_EXIT();

    Os_SCB.sysOsLevel = osSameLevel;
    OS_ARCH_EXIT_CRITICAL();
}
#endif /* TRUE == CFG_SHUTDOWNHOOK */

/* Application specific hook. Ref: 8.5. */
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
#if (TRUE == CFG_APPL_STARTUPHOOK)
/******************************************************************************/
/*
 * Brief                <Call Appl's startup hook function>
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * param[in]            <None>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <StartOS>
 * REQ ID               <DD_1_0801, DD_1_0802, DD_1_1239, DD_1_1240, DD_1_1615>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ApplStartupHook(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Os_ApplicationType i;
    Os_CallLevelType osSameLevel;
    P2CONST(Os_ApplicationCfgType, AUTOMATIC, OS_VAR) pAppCfg;

    osSameLevel = Os_SCB.sysOsLevel;
    Os_SCB.sysOsLevel = OS_LEVEL_STARTUPHOOK;

    /* Loop each application, if cfg startuphook, then call it. */
    for (i = 0u; i < (CFG_OSAPPLICATION_MAX - 1u); i++)
    {
        pAppCfg = &Os_AppCfg[i];

        if (NULL_PTR != pAppCfg->OsApplicationHooks.OsAppStartupHook)
        {
            if (pAppCfg->OsHostCore == Os_SCB.sysCore)
            {
                pAppCfg->OsApplicationHooks.OsAppStartupHook();
            }
        }
    }

    Os_SCB.sysRunningAppID = OS_APPLICATION_INVALID;
    Os_SCB.sysRunningAppObj = OBJECT_MAX;

    Os_SCB.sysOsLevel = osSameLevel;
}
#endif /* TRUE == CFG_APPL_STARTUPHOOK */

#if (TRUE == CFG_APPL_SHUTDOWNHOOK)
/******************************************************************************/
/*
 * Brief                <Call Appl's Shutdown hook function>
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * param[in]            <Fatalerror>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <ShutdownOS and so on>
 * REQ ID               <DD_1_0803, DD_1_0804, DD_1_1241, DD_1_1242, DD_1_1614>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ApplShutdownHook(StatusType Fatalerror)
{
    Os_ApplicationType i;
    Os_CallLevelType osSameLevel;
    P2CONST(Os_ApplicationCfgType, AUTOMATIC, OS_VAR) pAppCfg;
    OS_ARCH_DECLARE_CRITICAL();

    /*Triggering the shutdown hook is Task or Isr,then update the running ApplID and Object*/
    if (OS_LEVEL_TASK == Os_SCB.sysOsLevel)
    {
        Os_SCB.sysRunningAppID = Os_ObjectAppCfg[OBJECT_TASK][Os_SCB.sysRunningTaskID].hostApp;
        Os_SCB.sysRunningAppObj = OBJECT_TASK;
    }
    if ((OS_LEVEL_ISR1 == Os_SCB.sysOsLevel) || (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel))
    {
        Os_SCB.sysRunningAppID = Os_ObjectAppCfg[OBJECT_ISR][Os_SCB.sysRunningIsrCat2Id].hostApp;
        Os_SCB.sysRunningAppObj = OBJECT_ISR;
    }

    osSameLevel = Os_SCB.sysOsLevel;
    Os_SCB.sysOsLevel = OS_LEVEL_SHUTDOWNHOOK;

    /* Loop each application, if cfg shutdownhook, then call it. */
    for (i = 0u; i < (CFG_OSAPPLICATION_MAX - 1u); i++)
    {
        pAppCfg = &Os_AppCfg[i];

        if (NULL_PTR != pAppCfg->OsApplicationHooks.OsAppShutdownHook)
        {
            OS_ARCH_ENTRY_CRITICAL();
            pAppCfg->OsApplicationHooks.OsAppShutdownHook(Fatalerror);
            OS_ARCH_EXIT_CRITICAL();
        }
    }

    Os_SCB.sysOsLevel = osSameLevel;
}
#endif /* TRUE == CFG_APPL_SHUTDOWNHOOK */
#endif /* #if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC)) */

/* Protection Hook. */
#if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
#if (TRUE == CFG_PROTECTIONHOOK)
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
/********************************************************************/
/*
 * Brief                <Resume isr operation in protection hook.>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <Non Reentrant>
 * param-eventId[in]    <osOpt>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_ProtHookTerminateTask>
 * REQ ID               <DD_1_0805, DD_1_0806>
 */
/********************************************************************/
static FUNC(void, OS_CODE) Os_ProtHookIsrOpt(Os_TaskIsrOptType osOpt)
{
    switch (osOpt)
    {
    /* SuspendOSInterrupts */
    case TP_SUS_OS_INT:
        Os_SuspendOsCount = 1u;
        ResumeOSInterrupts();
        break;

    /* SuspendAllInterrupts */
    case TP_SUS_ALL_INT:
        Os_SuspendAllCount = 1u;
        ResumeAllInterrupts();
        break;

    /* DisableAllInterrupts */
    case TP_DIS_ALL_INT:
        EnableAllInterrupts();
        break;

    /*add comments to pass QAC.*/
    default:
        /* Nothing to do. */
        break;
    }

    return;
}
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */

/********************************************************************/
/*
 * Brief                <Terminate task in protection hook. Terminate
 *                        running task. >
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <Non Reentrant>
 * param-eventId[in]    <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_ProtHookTermTaskIsr>
 * REQ ID               <DD_1_0927>
 */
/********************************************************************/
static FUNC(void, OS_CODE) Os_ProtHookTerminateTask(StatusType osErrType)
{
#if (CFG_STD_RESOURCE_MAX > 0U)
    uint16 i;
    Os_CoreIdType Core_Id;
    Os_CoreIdType Core_Index;
#endif /* CFG_STD_RESOURCE_MAX > 0U */

#if (TRUE == CFG_PROTECTIONHOOK)
#if (CFG_SPINLOCK_MAX > 0U)
    SpinlockIdType spinLockIdx;
    SpinlockIdType SpinlockId;
#endif /* CFG_SPINLOCK_MAX > 0U */
#endif /* TRUE == CFG_PROTECTIONHOOK */

    (void)osErrType;
    Os_TaskType osRunningTaskID;
    P2CONST(Os_TCBType volatile, AUTOMATIC, OS_VAR) pRunningTaskTcb;

#if (CFG_STD_RESOURCE_MAX > 0U)
    Core_Id = Os_SCB.sysCore;
    Core_Index = Core_Id << 12;
#endif /* (CFG_STD_RESOURCE_MAX > 0U) */

    osRunningTaskID = Os_SCB.sysRunningTaskID;
    pRunningTaskTcb = &Os_TCB[osRunningTaskID];

/* Release resources occupied by running task. */
/* OESK 8.2:
   In case of multiple resource occupation within one task, the user has
   to request and release resources following the LIFO principle
   (stack like). */
#if (CFG_STD_RESOURCE_MAX > 0U)
    if (pRunningTaskTcb->taskResCount > 0u)
    {
        for (i = pRunningTaskTcb->taskResCount; i > 0u; i--)
        {
            (void)ReleaseResource(Core_Index | pRunningTaskTcb->taskResourceStack[i - 1u]);
        }
    }
#endif /* CFG_STD_RESOURCE_MAX > 0U */

#if (CFG_SPINLOCK_MAX > 0U)
    for (spinLockIdx = pRunningTaskTcb->taskCriticalZoneCount; spinLockIdx > 0u; spinLockIdx--)
    {
        if (OBJECT_SPINLOCK == pRunningTaskTcb->taskCriticalZoneType[pRunningTaskTcb->taskCriticalZoneCount - 1u])
        {
            SpinlockId = pRunningTaskTcb->taskCriticalZoneStack[pRunningTaskTcb->taskCriticalZoneCount - 1u];
            (void)ReleaseSpinlock(SpinlockId);
        }
    }
#endif /* CFG_SPINLOCK_MAX > 0U */

#if (CFG_INTERNAL_RESOURCE_MAX > 0U)
    Os_ReleaseInternalResource(osRunningTaskID);
#endif /* CFG_INTERNAL_RESOURCE_MAX > 0U */

#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
    /* Resume isr operation. */
    Os_ProtHookIsrOpt(pRunningTaskTcb->taskIsrOpt);
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */
/* Update task state. */
#if ((OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC))
    Os_SCB.sysRunningTCB->taskState = TASK_STATE_SUSPENDED;

#else
    if (Os_SCB.sysRunningTCB->taskActCount > 0u)
    {
        /*Os_SCB.sysRunningTCB->taskActCount--*/
        Os_SCB.sysRunningTCB->taskActCount = Os_SCB.sysRunningTCB->taskActCount - 1u;
    }

    if (Os_SCB.sysRunningTCB->taskActCount > 0U)
    {
        Os_SCB.sysRunningTCB->taskState = TASK_STATE_START;
    }
    else
    {
        Os_SCB.sysRunningTCB->taskState = TASK_STATE_SUSPENDED;
    }
#endif /* (OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC) */

    /* Remove task from ready queue. */
    Os_ReadyQueueRemove(OS_LEVEL_TASK, pRunningTaskTcb->taskRunPrio);

    /* Reset TCB. */
    Os_SCB.sysRunningTCB->taskTop = Os_TaskStack[Os_GetObjLocalId(Os_TaskCfg[osRunningTaskID].osTaskStackId)].stackTop;

#if (CFG_STD_RESOURCE_MAX > 0U)
    Os_SCB.sysRunningTCB->taskResCount = 0U;
#endif /* CFG_STD_RESOURCE_MAX > 0U */

    Os_SCB.sysRunningTCB->taskRunPrio = Os_TaskCfg[osRunningTaskID].osTaskPriority;

#if (CFG_EXTENDED_TASK_MAX > 0U)
    if (osRunningTaskID < Os_CfgExtendTaskMax)
    {
        Os_ECB[osRunningTaskID].eventSetEvent = 0U;
        Os_ECB[osRunningTaskID].eventWaitEvent = 0U;
    }
#endif /* CFG_EXTENDED_TASK_MAX > 0U */

    if (Os_SCB.sysHighTaskID == osRunningTaskID)
    {
        Os_SCB.sysHighPrio = Os_GetHighPrio();
        Os_SCB.sysHighTaskID = Os_ReadyQueueGetFirst(Os_SCB.sysHighPrio);
    }
#if (TRUE == CFG_STACK_CHECK)
    if (E_OS_STACKFAULT == (StatusType)osErrType)
    {
        /*nothing to do*/
    }
    else
#endif
    {
/* Timing protection: reset task exe time. */
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
        Os_TmProtTaskEnd(Os_SCB.sysRunningTaskID, TP_TASK_EXE);

        /* Set terminate_Task flag. */

        /* Timing protection do task_dispatch at the end of tm_prot_isr. */
        if ((E_OS_PROTECTION_LOCKED != (StatusType)osErrType) && (E_OS_PROTECTION_TIME != (StatusType)osErrType))
        {
            Os_SCB.sysDispatchLocker = 0U;
            /* PRQA S 3335++ */ /* MISRA Rule 17.3 */
            Os_Dispatch();
            /* PRQA S 3335-- */ /* MISRA Rule 17.3 */
        }
#else
        Os_SCB.sysDispatchLocker = 0U;
        /* PRQA S 3335++ */ /* MISRA Rule 17.3 */
        Os_Dispatch();
/* PRQA S 3335-- */         /* MISRA Rule 17.3 */
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */
    }

    return;
}

#if (CFG_ISR2_MAX > 0)
/********************************************************************/
/*
 * Brief                <Terminate isr cat2 in protection hook.>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <Non Reentrant>
 * param-eventId[in]    <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_ProtHookTermTaskIsr>
 * REQ ID               <DD_1_0928>
 */
/********************************************************************/
static FUNC(void, OS_CODE) Os_ProtHookTerminateIsrC2(StatusType osErrType)
{
#if (CFG_STD_RESOURCE_MAX > 0U)
    uint16 i;
    Os_CoreIdType Core_Id;
    Os_CoreIdType Core_Index;
#endif /* CFG_STD_RESOURCE_MAX > 0U */

#if (TRUE == CFG_PROTECTIONHOOK)
#if (CFG_SPINLOCK_MAX > 0U)
    SpinlockIdType spinLockIdx;
    SpinlockIdType SpinlockId;
#endif /* CFG_SPINLOCK_MAX > 0U */
#endif /* TRUE == CFG_PROTECTIONHOOK */

#if (FALSE == CFG_TIMING_PROTECTION_ENABLE)
    (void)osErrType;
#endif /* FALSE == CFG_TIMING_PROTECTION_ENABLE */

#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
    Os_IsrType RunIsrId = Os_SCB.sysRunningIsrCat2Id;
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */

#if ((CFG_STD_RESOURCE_MAX > 0U) || (CFG_SPINLOCK_MAX > 0U) || (TRUE == CFG_TIMING_PROTECTION_ENABLE))
    P2CONST(Os_ICBType volatile, AUTOMATIC, OS_VAR) pIcb;
#endif /* ((CFG_STD_RESOURCE_MAX > 0U) || (CFG_SPINLOCK_MAX > 0U) \
|| (TRUE == CFG_TIMING_PROTECTION_ENABLE))*/

#if (CFG_STD_RESOURCE_MAX > 0U)
    Core_Id = Os_SCB.sysCore;
    Core_Index = Core_Id << 12;
#endif /* CFG_STD_RESOURCE_MAX > 0U */

/* In timing protection, . */
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
    if ((E_OS_PROTECTION_TIME == osErrType) || (E_OS_PROTECTION_LOCKED == osErrType))
    {
        if (Os_IntNestISR2 >= OS_TMPROT_TARGET_ISR_OFFSET)
        {
            Os_SCB.sysRunningIsrCat2Id = Os_SCB.sysIsrNestQueue[Os_IntNestISR2 - OS_TMPROT_TARGET_ISR_OFFSET];
        }
    }
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */

#if ((CFG_STD_RESOURCE_MAX > 0U) || (CFG_SPINLOCK_MAX > 0U) || (TRUE == CFG_TIMING_PROTECTION_ENABLE))
    /* PRQA S 0404++ */ /* MISRA Rule 1.3,13.2 */
    pIcb = &Os_ICB[Os_SCB.sysRunningIsrCat2Id];
/* PRQA S 0404-- */     /* MISRA Rule 1.3,13.2 */
#endif                  /* ((CFG_STD_RESOURCE_MAX > 0U) || (CFG_SPINLOCK_MAX > 0U) \
                      || (TRUE == CFG_TIMING_PROTECTION_ENABLE)) */

/* Terminate resource. */
/* OESK 8.2:
   In case of multiple resource occupation within one task, the user has to request and release
   resources following the LIFO principle (stack like). */
#if (CFG_STD_RESOURCE_MAX > 0U)
    if (pIcb->IsrC2ResCount > 0u)
    {
        for (i = pIcb->IsrC2ResCount; i > 0u; i--)
        {
            (void)ReleaseResource(Core_Index | pIcb->IsrC2ResourceStack[i - 1u]);
        }
    }
#endif /* CFG_STD_RESOURCE_MAX > 0U */

#if (CFG_SPINLOCK_MAX > 0U)
    for (spinLockIdx = pIcb->isr2CriticalZoneCount; spinLockIdx > 0u; spinLockIdx--)
    {
        if (OBJECT_SPINLOCK == pIcb->isr2CriticalZoneType[pIcb->isr2CriticalZoneCount - 1u])
        {
            SpinlockId = pIcb->isr2CriticalZoneStack[pIcb->isr2CriticalZoneCount - 1u];
            (void)ReleaseSpinlock(SpinlockId);
        }
    }
#endif /* CFG_SPINLOCK_MAX > 0U */

#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
    /* Resume Interrupts. */
    Os_ProtHookIsrOpt(pIcb->IsrC2IsrOpt);

    /* Stop isr exe budget. */
    Os_TmProtIsrEnd(Os_SCB.sysRunningIsrCat2Id, TP_ISR_CAT2_EXE);

    Os_SCB.sysRunningIsrCat2Id = RunIsrId;

    /* Set terminate_isr flag. */
    Os_TprotTerminateIsr = TRUE;

    /* Timing protection do task_dispatch at the end of tm_prot_isr. */
    if ((E_OS_PROTECTION_LOCKED != osErrType) && (E_OS_PROTECTION_TIME != osErrType) && (E_OS_STACKFAULT != osErrType))
    {
        /* PRQA S 3415,3335,0306,3200,2981++ */ /* MISRA Rule 13.5,17.3,11.4,17.7,2.2 */
        OS_ARCH_ISR2_EPILOGUE();
        /* PRQA S 3415,3335,0306,3200,2981-- */ /* MISRA Rule 13.5,17.3,11.4,17.7,2.2 */
    }
#else
    if (E_OS_STACKFAULT != osErrType)
    {
        /* PRQA S 3415,3335,0306,3200,2981++ */ /* MISRA Rule 13.5,17.3,11.4,17.7,2.2 */
        OS_ARCH_ISR2_EPILOGUE();
        /* PRQA S 3415,3335,0306,3200,2981-- */ /* MISRA Rule 13.5,17.3,11.4,17.7,2.2 */
    }
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */

    return;
}
#endif /* #if (CFG_ISR2_MAX > 0) */

/********************************************************************/
/*
 * Brief                <PRO_TERMINATETASKISR: terminate task or isr in hook.>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <Non Reentrant>
 * param-eventId[in]    <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_CallProtectionHook>
 * REQ ID               <DD_1_0929>
 */
/********************************************************************/
static FUNC(void, OS_CODE) Os_ProtHookTermTaskIsr(uint32 osWhoHook, StatusType osErrType)
{
    if (OS_TMPROT_HOOK_TASK == osWhoHook)
    {
        Os_ProtHookTerminateTask(osErrType);
    }

#if (CFG_ISR2_MAX > 0)
    if (OS_TMPROT_HOOK_ISR == osWhoHook)
    {
        Os_ProtHookTerminateIsrC2(osErrType);
    }
#endif /* #if (CFG_ISR2_MAX > 0) */

    return;
}

#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
/* Terminate os_app process. */
/******************************************************************************/
/*
 * Brief                <Terminate os_app process>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * param[in]            <osErrType,RestartOption,osWhoHook>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <Os_CallProtectionHook>
 * REQ ID               <DD_1_0930>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_ProtHookTermAppl(StatusType osErrType, RestartType RestartOption, uint32 osWhoHook)
{
    (void)osWhoHook;
    (void)osErrType;
    Os_ApplicationType RunApplIdTemp;

#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
    Os_IsrType IsrId;
    Os_TaskType TaskId;
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */

    RunApplIdTemp = Os_SCB.sysRunningAppID;

/* In timing protection, the running_application maybe SYS_APP. */
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
    if ((E_OS_PROTECTION_LOCKED == osErrType) || (E_OS_PROTECTION_TIME == osErrType))
    {
        if (OS_TMPROT_HOOK_ISR == osWhoHook)
        {
            /* Update running_application_id. */
            if (Os_IntNestISR2 >= OS_TMPROT_TARGET_ISR_OFFSET)
            {
                IsrId = Os_SCB.sysIsrNestQueue[Os_IntNestISR2 - OS_TMPROT_TARGET_ISR_OFFSET];

                if (IsrId < CFG_ISR_MAX)
                {
                    Os_SCB.sysRunningAppID = Os_ObjectAppCfg[OBJECT_ISR][IsrId].hostApp;
                }
            }
        }
        else if (OS_TMPROT_HOOK_TASK == osWhoHook)
        {
            TaskId = Os_SCB.sysRunningTaskID;
            Os_SCB.sysRunningAppID = Os_ObjectAppCfg[OBJECT_TASK][TaskId].hostApp;
        }
        else
        {
            /*Nothing to do*/
        }
    }
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */

    /* Call TerminateApplication. */
    (void)TerminateApplication(Os_SCB.sysRunningAppID, RestartOption);

    Os_SCB.sysRunningAppID = RunApplIdTemp;

    return;
}
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */
#endif /* #if (TRUE == CFG_PROTECTIONHOOK) */
/* ProtHook shutdownOs process. */
static FUNC(void, OS_CODE) Os_ProtHookShutdownOS(StatusType Error)
{
    (void)Error;
#if (CFG_SPINLOCK_MAX > 0U)
    Os_TaskType i;
    P2VAR(Os_TCBType volatile, AUTOMATIC, OS_VAR) pTCB;
    P2VAR(Os_ICBType volatile, AUTOMATIC, OS_VAR) pICB;

    SpinlockIdType SpinlockId;
    Os_SpinlockType spinLockIdx;
#endif /* CFG_SPINLOCK_MAX > 0U */

    OS_SHUTDOWNOS_ENTRY();
/* SWS_Os_00586: Application specific hook. */
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
#if (TRUE == CFG_APPL_SHUTDOWNHOOK)
    Os_ApplShutdownHook(Error);
#endif /* TRUE == CFG_APPL_SHUTDOWNHOOK */
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */

/* SWS_Os_00588: Global ShutdownHook. */
#if (TRUE == CFG_SHUTDOWNHOOK)
    Os_CallShutdownHook(Error);
#endif /* #if (TRUE == CFG_SHUTDOWNHOOK) */

    OS_DisableInterrupts();
/*Os_00620*/
#if (CFG_SPINLOCK_MAX > 0U)
    for (i = 0; i < (Os_CfgTaskMax - (uint16)1); i++)
    {
        pTCB = &Os_TCB[i];
        for (spinLockIdx = pTCB->taskCriticalZoneCount; spinLockIdx > 0U; spinLockIdx--)
        {
            if (pTCB->taskCriticalZoneType[pTCB->taskCriticalZoneCount - 1U] == OBJECT_SPINLOCK)
            {
                SpinlockId = pTCB->taskCriticalZoneStack[pTCB->taskCriticalZoneCount - 1U];
                (void)ReleaseSpinlock(SpinlockId);
            }
        }
    }
    for (i = 0; i < Os_CfgIsr2Max; i++)
    {
        pICB = &Os_ICB[i];
        for (spinLockIdx = pICB->isr2CriticalZoneCount; spinLockIdx > 0U; spinLockIdx--)
        {
            if (pICB->isr2CriticalZoneType[pICB->isr2CriticalZoneCount - 1U] == OBJECT_SPINLOCK)
            {
                SpinlockId = pICB->isr2CriticalZoneStack[pICB->isr2CriticalZoneCount - 1U];
                (void)ReleaseSpinlock(SpinlockId);
            }
        }
    }
#endif /* CFG_SPINLOCK_MAX > 0U */

    Os_GetSpinlock(&Os_SpinlockSync);
    Os_CoreCB.coreStateActive &= (Os_CoreIdType)(~((Os_CoreIdType)1u << Os_SCB.sysCore));
    Os_CoreCB.coreStateSynPoint0[Os_SCB.sysCore] = FALSE;
    Os_CoreCB.coreStateSynPoint1[Os_SCB.sysCore] = FALSE;
    Os_CoreCB.coreStateSynPoint2[Os_SCB.sysCore] = FALSE;
    Os_CoreCB.coreStateSynPoint3[Os_SCB.sysCore] = FALSE;
    Os_CoreCB.osAppMode[Os_SCB.sysCore] = OS_NULL_APPMODE;
    Os_CoreCB.coreStatus[Os_SCB.sysCore] = OS_CORE_STATUS_INVALID;
    Os_ReleaseSpinlock(&Os_SpinlockSync);

    OS_SHUTDOWNOS_EXIT();

    /* SWS_Os_00715*/
    for (;;)
    {
    }
}
/********************************************************************/
/*
 * Brief                <ProtectionHook called by OS.>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <Non Reentrant>
 * param-eventId[in]    <osErrType>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <WaitEvent>
 * REQ ID               <DD_1_0807, DD_1_0808, DD_1_1247, DD_1_1264, DD_1_1265, DD_1_1266,
 *                       DD_1_1267, DD_1_1268, DD_1_1161, DD_1_0808, DD_1_1617>
 */
/********************************************************************/
FUNC(ProtectionReturnType, OS_CODE) Os_CallProtectionHook(StatusType osErrType, uint32 osWhoHook)
{
    ProtectionReturnType osRet;

#if (TRUE == CFG_PROTECTIONHOOK)
#if (CFG_SPINLOCK_MAX > 0U)
    SpinlockIdType spinLockIdx;
    uint16 obj_id;
#endif /* CFG_SPINLOCK_MAX > 0U */
#endif /* TRUE == CFG_PROTECTIONHOOK */

#if (TRUE == CFG_PROTECTIONHOOK)
    Os_CallLevelType osSameLevel;
    OS_ARCH_DECLARE_CRITICAL();

    OS_ARCH_ENTRY_CRITICAL();
    osSameLevel = Os_SCB.sysOsLevel;
    Os_SCB.sysOsLevel = OS_LEVEL_PROTECTIONHOOK;
    OS_ARCH_EXIT_CRITICAL();

    OS_PROTHOOK_ENTRY();
    OS_ARCH_ENTRY_CRITICAL();
    osRet = ProtectionHook(osErrType);
    OS_ARCH_EXIT_CRITICAL();
    OS_PROTHOOK_EXIT();

    OS_ARCH_ENTRY_CRITICAL();
    Os_SCB.sysOsLevel = osSameLevel;
    OS_ARCH_EXIT_CRITICAL();

#if (CFG_SPINLOCK_MAX > 0U)
    /*Os_00613*/
    if ((uint32)OS_NO_CARE == osWhoHook)
    {
        if ((StatusType)E_OS_SPINLOCK == osErrType)
        {
            for (spinLockIdx = 0u; spinLockIdx < CFG_SPINLOCK_MAX; spinLockIdx++)
            {
                if (Os_SLCB[spinLockIdx].objOccupyType == OBJECT_TASK)
                {
                    obj_id = Os_SLCB[spinLockIdx].objOccupyId;
                    if ((Os_GetObjLocalId(obj_id) == Os_SCB.sysRunningTaskID)
                        && (Os_SCB.sysCore == Os_GetObjCoreId(obj_id)))
                    {
                        (void)ReleaseSpinlock(spinLockIdx);
                    }
                }
            }
        }
    }
#endif /* CFG_SPINLOCK_MAX > 0U */

    /* Hook post process. */
    switch (osRet)
    {
    case PRO_IGNORE:
        /* Nothing to do. */
        break;

    case PRO_TERMINATETASKISR:
        if (E_OS_PROTECTION_ARRIVAL != osErrType)
        {
            if (E_OK == Os_CheckRunningTaskIDandIsr2ID(osWhoHook))
            {
                Os_ProtHookTermTaskIsr(osWhoHook, osErrType);
                break;
            }
/*OS243
if the reaction is to forcibly terminate the Task/Category 2 OsIsr and no Task
or OsIsr can be associated with the error,the running OS-Application is forcibly
terminated by the Operating System
*/
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
            if (Os_SCB.sysRunningAppID <= Os_AppSysCfg)
#else
            if (Os_SCB.sysRunningAppID < Os_AppSysCfg)
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */
            {
                Os_ProtHookTermAppl(osErrType, NO_RESTART, osWhoHook);
                break;
            }
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */
            ShutdownOS(osErrType);
        }
        break;

    case PRO_TERMINATEAPPL:
/*OS244
 * If the reaction is to forcibly terminate the faulty OS-Application
 * and no OS-Application can be assigned,ShutdownOS() is called.
 */
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
        if (Os_SCB.sysRunningAppID > Os_AppSysCfg)
#else
        if (Os_SCB.sysRunningAppID >= Os_AppSysCfg)
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */
        {
            ShutdownOS(osErrType);
        }
        else
        {
            Os_ProtHookTermAppl(osErrType, NO_RESTART, osWhoHook);
        }
#endif /*#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC)) */
        break;

    case PRO_TERMINATEAPPL_RESTART:
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
        if (Os_SCB.sysRunningAppID > Os_AppSysCfg)
#else
        if (Os_SCB.sysRunningAppID >= Os_AppSysCfg)
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */
        {
            ShutdownOS(osErrType);
        }
        else
        {
            Os_ProtHookTermAppl(osErrType, RESTART, osWhoHook);
        }
#endif /* #if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC)) */
        break;

    case PRO_SHUTDOWN:
        Os_ProtHookShutdownOS(osErrType);
        break; /* PRQA S 2880 */ /* MISRA Rule 2.1 */

    /*add comments to pass QAC.*/
    default:
        /* OS107: ShutdownOS. */
        Os_ProtHookShutdownOS(osErrType);
        break; /* PRQA S 2880 */ /* MISRA Rule 2.1 */
    }

#else
    (void)osWhoHook;
    /* OS107: ShutdownOS. */
    Os_ProtHookShutdownOS(osErrType);
#endif /* TRUE == CFG_PROTECTIONHOOK */

    return osRet;
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#endif /* #if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC)) */

/*=======[E N D   O F   F I L E]==============================================*/
