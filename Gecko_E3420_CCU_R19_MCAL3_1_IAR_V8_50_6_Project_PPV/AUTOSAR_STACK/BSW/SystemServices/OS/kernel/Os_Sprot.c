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
**  FILENAME    : Os_Sprot.c                                                  **
**                                                                            **
**  Created on  :                                                             **
**  Author      : shi.shu                                                     **
**  Vendor      :                                                             **
**  DESCRIPTION : AutoSar Protection Managment                                **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>    <AUTHOR>    <REVISION LOG>
 *  V0.1.0     2016-03-29    shi.shu     Initial version.
 *  V0.2.0     2019-08-21    shun.li & zhiqiang.huang   Functional safety initial version.
 *  V1.0.0     2019-11-21    shun.li     Functional safety version.
 *  V1.0.1     2022-03-15    shun.li     repair terminate task in service protection.
 */
/*============================================================================*/

/*=======[I N C L U D E S]====================================================*/
#include "Os_Internal.h"

/*=======[M A C R O S]========================================================*/

/*=======[E X T E R N A L   D A T A]==========================================*/
/* PRQA S 1514,3332++ */ /* MISRA Rule 8.9,20.9 */
#if (CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE0 > 0U)
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(TrustedFunctionIndexType, OS_VAR)
Os_TrustedFuncNestQueueCore0[CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE0];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif /* CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE0 > 0U */

#if (CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE1 > 0U)
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(TrustedFunctionIndexType, OS_VAR)
Os_TrustedFuncNestQueueCore1[CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE1];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif /* CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE1 > 0U */

#if (CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE2 > 0U)
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(TrustedFunctionIndexType, OS_VAR)
Os_TrustedFuncNestQueueCore2[CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE2];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif /* CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE2 > 0U */

#if (CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE3 > 0U)
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(TrustedFunctionIndexType, OS_VAR)
Os_TrustedFuncNestQueueCore3[CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE3];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif /* CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE3 > 0U */

#if (CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE4 > 0U)
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(TrustedFunctionIndexType, OS_VAR)
Os_TrustedFuncNestQueueCore4[CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE4];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif /* CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE4 > 0U */

#if (CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE5 > 0U)
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(TrustedFunctionIndexType, OS_VAR)
Os_TrustedFuncNestQueueCore5[CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE5];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif                     /* CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE5 > 0U */
/* PRQA S 1514锛�3332-- */ /* MISRA Rule 8.9,20.9 */

#if (CFG_TRUSTED_SYSTEM_SERVICE_MAX > 0U)
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
P2VAR(TrustedFunctionIndexType, AUTOMATIC, OS_VAR)
Os_TrustedFuncNestQueue = NULL_PTR;
/* PRQA S 3432 */ /* MISRA Rule 20.7 */
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
static VAR(TrustedFunctionIndexType, OS_VAR) Os_CfgTrustedServiceMax = 0U;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
VAR(uint8, OS_VAR) Os_TrustedFuncNest = 0U;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#endif /* CFG_TRUSTED_SYSTEM_SERVICE_MAX > 0U */

#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
#define OS_START_SEC_CODE
#include "Os_MemMap.h"

/*=======[I N T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/
#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
static FUNC(void, OS_CODE) Os_SProTerminateTask(void);
#endif /* TRUE == CFG_SERVICE_PROTECTION_ENABLE */

/*=======[F U N C T I O N   I M P L E M E N T A T I O N S]====================*/
#if (CFG_TRUSTED_SYSTEM_SERVICE_MAX > 0U)
/******************************************************************************/
/*
 * Brief                <Init the TrustedFunction>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * PreCondition         <None>
 * CallByAPI            <Os_InitSystem>
 * REQ ID               <DD_1_0864, DD_1_0865>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_InitTrustedFunction(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    uint8 i;

    switch (Os_SCB.sysCore)
    {
#if (CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE0 > 0U)
    case 0:
        Os_TrustedFuncNestQueue = Os_TrustedFuncNestQueueCore0;
        Os_CfgTrustedServiceMax = CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE0;
        for (i = 0u; i < CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE0; i++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            Os_TrustedFuncNestQueue[i] = OS_APPLICATION_INVALID;
        }
        break;
#endif /* CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE0 > 0U */

#if (CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE1 > 0U)
    case 1:
        Os_TrustedFuncNestQueue = Os_TrustedFuncNestQueueCore1;
        Os_CfgTrustedServiceMax = CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE1;
        for (i = 0u; i < CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE1; i++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            Os_TrustedFuncNestQueue[i] = OS_APPLICATION_INVALID;
        }
        break;
#endif /* CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE1 > 0U */

#if (CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE2 > 0U)
    case 2:
        Os_TrustedFuncNestQueue = Os_TrustedFuncNestQueueCore2;
        Os_CfgTrustedServiceMax = CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE2;
        for (i = 0u; i < CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE2; i++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            Os_TrustedFuncNestQueue[i] = OS_APPLICATION_INVALID;
        }
        break;
#endif /* CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE2 > 0U */

#if (CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE3 > 0U)
    case 3:
        Os_TrustedFuncNestQueue = Os_TrustedFuncNestQueueCore3;
        Os_CfgTrustedServiceMax = CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE3;
        for (i = 0u; i < CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE3; i++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            Os_TrustedFuncNestQueue[i] = OS_APPLICATION_INVALID;
        }
        break;
#endif /* CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE3 > 0U */

#if (CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE4 > 0U)
    case 4:
        Os_TrustedFuncNestQueue = Os_TrustedFuncNestQueueCore4;
        Os_CfgTrustedServiceMax = CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE4;
        for (i = 0u; i < CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE4; i++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            Os_TrustedFuncNestQueue[i] = OS_APPLICATION_INVALID;
        }
        break;
#endif /* CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE4 > 0U */

#if (CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE5 > 0U)
    case 5:
        Os_TrustedFuncNestQueue = Os_TrustedFuncNestQueueCore5;
        Os_CfgTrustedServiceMax = CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE5;
        for (i = 0u; i < CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE5; i++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            Os_TrustedFuncNestQueue[i] = OS_APPLICATION_INVALID;
        }
        break;
#endif /* CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE5 > 0U */

    /*add comments to pass QAC.*/
    default:
        /* Nothing to do. */
        break;
    }
}

/********************************************************************/
/*
 * Brief                <Call Trusted Function>
 * Service ID           <OSServiceId_CallTrustedFunction>
 * Sync/Async           <Depends on called function. If called function is synchronous then serviec
 *                       is synchronous.May cause reschduling>
 * Reentrancy           <Yes>
 * param-eventId[in]    <FunctionIndex>
 *                      <FunctionParams>
 * Param-Name[out]      <void>
 * Param-Name[in/out]   <None>
 * return               <E_OK>
 *                      <E_OS_SERVICEID>
 * PreCondition         <None>
 * CallByAPI            <None>
 * REQ ID               <DD_1_0432, DD_1_1533, DD_1_1535, DD_1_1535, DD_1_1023, DD_1_0433,
 *                       DD_1_0434, DD_1_0441, DD_1_1597, DD_1_1679, DD_1_0443, DD_1_0014,
 *                       DD_1_0032, DD_1_0033>
 */
/********************************************************************/
/* PRQA S 1503++ */ /* MISRA Rule 2.1 */
FUNC(StatusType, OS_CODE)
CallTrustedFunction(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)
/* PRQA S 1503-- */ /* MISRA Rule 2.1 */
{
    OS_ARCH_DECLARE_CRITICAL();
    OS_CALLTRUSTEDFUN_DEFINE();
#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */
    StatusType OsReturnErr = E_OK;

    OS_CALLTRUSTEDFUN_ENTRY();
#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    if (Os_WrongContext(OS_CONTEXT_CALL_TRUSTED_FUNCTION) != TRUE)
    {
        OsReturnErr = E_OS_CALLEVEL;
    }
    else if (Os_AddressWritable((uint8*)FunctionParams) != TRUE)
    {
        OsReturnErr = E_OS_ILLEGAL_ADDRESS;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        OsReturnErr = E_OS_DISABLEDINT;
    }
    else
#endif /* #if (TRUE == CFG_SERVICE_PROTECTION_ENABLE) */
    {
/* On a Multi-Core system, these trusted function calls from
 * one OS-Application to another are limited to the same core.*/
#if (OS_AUTOSAR_CORES > 1)
        if (Os_SCB.sysCore != Os_GetObjCoreId(FunctionIndex))
        {
#if (TRUE == CFG_ERRORHOOK)
            Os_CallErrorHook(E_OS_CORE);
#endif /* TRUE == CFG_ERRORHOOK */

            OsReturnErr = E_OS_CORE;
        }
        else
#endif /*OS_AUTOSAR_CORES > 1*/
        {
            OS_ARCH_ENTRY_CRITICAL();
            /* Save Trusted Function host App ID. */
            Os_TrustedFuncNestQueue[Os_TrustedFuncNest] = (0x0F00u & FunctionIndex) >> 8u;
            Os_TrustedFuncNest++;
            OS_ARCH_EXIT_CRITICAL();

            FunctionIndex = 0x00FFU & FunctionIndex;
            /*OS292,CFG_MAX_SYSTEM_SERVICE is generate by tool*/
            if (FunctionIndex >= Os_CfgTrustedServiceMax)
            {
#if (TRUE == CFG_ERRORHOOK)
                Os_CallErrorHook(E_OS_SERVICEID);
#endif /* TRUE == CFG_ERRORHOOK */

                OsReturnErr = E_OS_SERVICEID;
            }
            else
            {
                /*Os_TrustedServiceList is generate by tool*/
                (*(Os_TrustedServiceList[FunctionIndex]))(FunctionIndex, FunctionParams);
            }
            OS_ARCH_ENTRY_CRITICAL();
            Os_TrustedFuncNest--;
            Os_TrustedFuncNestQueue[Os_TrustedFuncNest] = OS_APPLICATION_INVALID;
            OS_ARCH_EXIT_CRITICAL();
        }
    }

    OS_CALLTRUSTEDFUN_EXIT();
    return OsReturnErr;
}
#endif /* CFG_TRUSTED_SYSTEM_SERVICE_MAX > 0 */

/* Service protection */
#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
/********************************************************************/
/*
 * Brief                <If interrupts are disabled/suspended, OS service should ignore>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <None>
 * param-eventId[in]    <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <E_OS_DISABLEDINT>
 * PreCondition         <None>
 * CallByAPI            <GetAlarm and so on>
 * REQ ID               <DD_1_0866, DD_1_1224, DD_1_0867, DD_1_0027>
 */
/********************************************************************/
FUNC(boolean, OS_CODE) Os_IgnoreService(void)
{
    boolean status = TRUE;
    /*OS093*/
    if (OS_LEVEL_TASK == Os_SCB.sysOsLevel)
    {
        if ((Os_SCB.sysRunningTCB->taskDisableAllCount > 0u) || (Os_SCB.sysRunningTCB->taskSuspendAllCount > 0u)
            || (Os_SCB.sysRunningTCB->taskSuspendOSCount > 0u))
        {
            status = FALSE; /*FALSE:ignore*/
        }
        else
        {
            status = TRUE;
        }
    }
    else if (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel)
    {
        if ((Os_ICB[Os_SCB.sysRunningIsrCat2Id].isrC2DisableAllCount > 0u)
            || (Os_ICB[Os_SCB.sysRunningIsrCat2Id].isrC2SuspendAllCount > 0u)
            || (Os_ICB[Os_SCB.sysRunningIsrCat2Id].isrC2SuspendOSCount > 0u))
        {
            status = FALSE;
        }
        else
        {
            status = TRUE;
        }
    }
    else
    {
        /* Intentionally Empty */
    }

    return status;
}

/********************************************************************/
/*
 * Brief                <Indicate the address if writable by this OS-App>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <None>
 * param-eventId[in]    <Address>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <E_OS_ILLEGAL_ADDRESS>
 * PreCondition         <None>
 * CallByAPI            <GetAlarm and so on>
 * REQ ID               <DD_1_0868, DD_1_1222, DD_1_0869>
 */
/********************************************************************/
FUNC(boolean, OS_CODE)
Os_AddressWritable(P2VAR(uint8, AUTOMATIC, OS_VAR) Address /* PRQA S 3432 */ /* MISRA Rule 20.7 */
)
{
    Os_CoreIdType Core_Id;
    Os_CoreIdType Core_Index;
    Os_TaskType TaskID = Os_SCB.sysRunningTaskID;
    Os_IsrType Isr2ID = Os_SCB.sysRunningIsrCat2Id;
    Os_ObjectTypeType ObjType = Os_SCB.sysRunningAppObj;
    AccessType Access = 0U;
    Core_Id = Os_SCB.sysCore;
    Core_Index = Core_Id << 12;
    boolean Status = TRUE; /* PRQA S 2981 */ /* MISRA Rule 2.2 */

    /*null pointer check*/
    if (NULL_PTR == Address)
    {
#if (TRUE == CFG_ERRORHOOK)
        Os_CallErrorHook(E_OS_ILLEGAL_ADDRESS);
#endif /* TRUE == CFG_ERRORHOOK */

        Status = FALSE;
    }
    else
    {
        /*OS051*/
        if (OBJECT_TASK == ObjType)
        {
            if (((uint8*)(Os_TaskStack[TaskID].stackTop) >= Address) && ((uint8*)(Os_TaskStack[TaskID].stackBottom) <= Address))
            {
                Access = OSMEMORY_SET_WRITEABLE(Access);
            }
            else
            {
                Access = CheckTaskMemoryAccess((Core_Index | TaskID), Address, 0);
            }
        }
        else if (OBJECT_ISR == ObjType)
        {
            if (((uint8*)(Os_ISR2Stack[Isr2ID].stackTop) >= Address) && ((uint8*)(Os_ISR2Stack[Isr2ID].stackBottom) <= Address))
            {
                Access = OSMEMORY_SET_WRITEABLE(Access);
            }
            else
            {
                Access = CheckISRMemoryAccess((Core_Index | Isr2ID), Address, 0);
            }
        }
        else
        {
            Access = OSMEMORY_SET_WRITEABLE(Access);
        }

        if (0U != OSMEMORY_IS_WRITEABLE(Access))
        {
            Status = TRUE;
        }
        else
        {
            Status = FALSE;
        }
    }

    return Status;
}

/********************************************************************/
/*
 * Brief                <Indicate the service if in right context>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <None>
 * param-eventId[in]    <AllowedContext>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <E_OS_DISABLEDINT>
 * PreCondition         <None>
 * CallByAPI            <GetAlarm and so on>
 * REQ ID               <DD_1_0870, DD_1_1221, DD_1_1532, DD_1_0871>
 */
/********************************************************************/
FUNC(boolean, OS_CODE) Os_WrongContext(uint16 AllowedContext)
{
    uint16 Os_LevelBit;
    boolean Status = FALSE;
    switch (Os_SCB.sysOsLevel)
    {
    case OS_LEVEL_ERRORHOOK_APP:
        Os_LevelBit = OS_LEVEL_BIT_ERRORHOOK_APP;
        break;

    case OS_LEVEL_TASK:
        Os_LevelBit = OS_LEVEL_BIT_TASK;
        break;

    case OS_LEVEL_ISR1:
        Os_LevelBit = OS_LEVEL_BIT_ISR1;
        break;

    case OS_LEVEL_ISR2:
        Os_LevelBit = OS_LEVEL_BIT_ISR2;
        break;

    case OS_LEVEL_ERRORHOOK:
        Os_LevelBit = OS_LEVEL_BIT_ERRORHOOK;
        break;

    case OS_LEVEL_PRETASKHOOK:
        Os_LevelBit = OS_LEVEL_BIT_PRETASKHOOK;
        break;

    case OS_LEVEL_POSTTASKHOOK:
        Os_LevelBit = OS_LEVEL_BIT_POSTTASKHOOK;
        break;

    case OS_LEVEL_STARTUPHOOK:
        Os_LevelBit = OS_LEVEL_BIT_STARTUPHOOK;
        break;

    case OS_LEVEL_SHUTDOWNHOOK:
        Os_LevelBit = OS_LEVEL_BIT_SHUTDOWNHOOK;
        break;

    case OS_LEVEL_ALARMCALLBACK:
        Os_LevelBit = OS_LEVEL_BIT_ALARMCALLBACK;
        break;

    case OS_LEVEL_PROTECTIONHOOK:
        Os_LevelBit = OS_LEVEL_BIT_PROTECTIONHOOK;
        break;

    default:
        Os_LevelBit = (uint16)OS_LEVEL_MAIN;
        break;
    }

    if ((uint16)OS_LEVEL_MAIN == Os_LevelBit)
    {
        if ((OS_CONTEXT_START_CORE == AllowedContext) || (OS_CONTEXT_START_NON_AUTOSAR_CORE == AllowedContext))
        {
            Status = TRUE;
        }
    }

    if ((boolean)FALSE == Status)
    {
        /*OS088*/
        if ((Os_LevelBit & AllowedContext) > 0U)
        {
            Status = TRUE;
        }
        else
        {
            Status = FALSE; /*FALSE:Wrong context*/
        }
    }

    return Status;
}

/********************************************************************/
/*
 * Brief                <Service protection terminates the task>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <None>
 * param-eventId[in]    <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_TaskEndNoTerminate>
 * REQ ID               <DD_1_0984, DD_1_1212>
 */
/********************************************************************/
static FUNC(void, OS_CODE) Os_SProTerminateTask(void)
{
/*Reference to current Task CB*/
#if (CFG_STD_RESOURCE_MAX > 0U)
    P2VAR(Os_TCBType const volatile, AUTOMATIC, OS_VAR) pCurTaskTcb;
    Os_ResourceType taskResCountTmp;
    Os_CoreIdType Core_Id;
    Os_CoreIdType Core_Index;
#endif /* CFG_STD_RESOURCE_MAX > 0U */

    OS_ARCH_DECLARE_CRITICAL();

#if (CFG_STD_RESOURCE_MAX > 0U)
    pCurTaskTcb = Os_SCB.sysRunningTCB;
#endif /* CFG_STD_RESOURCE_MAX > 0U */

#if (CFG_STD_RESOURCE_MAX > 0U)
    taskResCountTmp = pCurTaskTcb->taskResCount;

    if (taskResCountTmp > 0U)
    {
        Os_ResourceType OsResLoopi;

        Core_Id = Os_SCB.sysCore;
        Core_Index = Core_Id << 12;
        for (OsResLoopi = taskResCountTmp; OsResLoopi > 0U; OsResLoopi--)
        {
            (void)ReleaseResource(Core_Index | pCurTaskTcb->taskResourceStack[OsResLoopi - 1U]);
        }
    }
#endif /* #if (CFG_STD_RESOURCE_MAX > 0U) */

    OS_ARCH_ENTRY_CRITICAL();
#if (TRUE == CFG_POSTTASKHOOK)
    Os_CallPostTaskHook();
#endif /* TRUE == CFG_POSTTASKHOOK */

#if (CFG_INTERNAL_RESOURCE_MAX > 0U)
    Os_ReleaseInternalResource(Os_SCB.sysRunningTaskID);
#endif /* CFG_INTERNAL_RESOURCE_MAX > 0U */

#if ((OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC))
    Os_SCB.sysRunningTCB->taskState = TASK_STATE_SUSPENDED;

#else
    if (Os_SCB.sysRunningTCB->taskActCount > 0U)
    {
        Os_SCB.sysRunningTCB->taskActCount = Os_SCB.sysRunningTCB->taskActCount - 1U;
    }
    if (Os_SCB.sysRunningTCB->taskSelfActCount > 0U)
    {
        Os_SCB.sysRunningTCB->taskSelfActCount = Os_SCB.sysRunningTCB->taskSelfActCount - 1U;
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

    Os_ReadyQueueRemove(OS_LEVEL_TASK, Os_TCB[Os_SCB.sysRunningTaskID].taskRunPrio);

#if (CFG_STD_RESOURCE_MAX > 0U)
    Os_SCB.sysRunningTCB->taskResCount = 0U;
#endif /* CFG_STD_RESOURCE_MAX > 0U */

    Os_SCB.sysRunningTCB->taskRunPrio = Os_TaskCfg[Os_SCB.sysRunningTaskID].osTaskPriority;

#if (CFG_EXTENDED_TASK_MAX > 0U)
    if (Os_SCB.sysRunningTaskID < Os_CfgExtendTaskMax)
    {
        Os_ECB[Os_SCB.sysRunningTaskID].eventSetEvent = 0U;
        Os_ECB[Os_SCB.sysRunningTaskID].eventWaitEvent = 0U;
    }
#endif                                                                     /* CFG_EXTENDED_TASK_MAX > 0U */

    if (Os_SCB.sysHighTaskID == Os_SCB.sysRunningTaskID) /* PRQA S 0404 */ /* MISRA Rule 1.3,13.2 */
    {
        Os_SCB.sysHighPrio = Os_GetHighPrio();
        Os_SCB.sysHighTaskID = Os_ReadyQueueGetFirst(Os_SCB.sysHighPrio);
    }

/* Timing protection: reset task exe time. */
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
    Os_TmProtTaskEnd(Os_SCB.sysRunningTaskID, TP_TASK_EXE);
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */

/*OS069*/
#if (TRUE == CFG_ERRORHOOK)
    Os_CallErrorHook(E_OS_MISSINGEND);
#endif /* TRUE == CFG_ERRORHOOK */

    Os_SCB.sysDispatchLocker = 0U;
    Os_Dispatch(); /* PRQA S 3335 */ /* MISRA Rule 17.3 */
    OS_ARCH_EXIT_CRITICAL();

    return;
}

/********************************************************************/
/*
 * Brief                <Task ends without calling a TerminateTask or ChainTask>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <None>
 * param-eventId[in]    <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * PreCondition         <None>
 * CallByAPI            <Os_TaskErrBack>
 * REQ ID               <DD_1_0872, DD_1_1213, DD_1_0873>
 */
/********************************************************************/
FUNC(void, OS_CODE) Os_TaskEndNoTerminate(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
/*OS239*/
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
    Os_ArchEnableAllInt_ButTimingProtInt();
#else
    Os_ArchEnableInt(); /* PRQA S 3335 */ /* MISRA Rule 17.3 */
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */

    /*OS052,OS070*/
    Os_SProTerminateTask();
}

/********************************************************************/
/*
 * Brief                <ISR2 ends with locked interrupts or allocated
 *                       resources>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <None>
 * param-eventId[in]    <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * PreCondition         <None>
 * CallByAPI            <None>
 * REQ ID               <DD_1_0874, DD_1_1214, DD_1_1512, DD_1_0875, DD_1_0020>
 */
/********************************************************************/
FUNC(void, OS_CODE) Os_Isr2OccupyIntRes(void)
{
#if (CFG_STD_RESOURCE_MAX > 0)
    Os_CoreIdType Core_Id;
    Os_CoreIdType Core_Index;
#endif /* CFG_STD_RESOURCE_MAX > 0 */
    Os_ICBType volatile* pOsICB;
#if (CFG_STD_RESOURCE_MAX > 0)
    Os_ResourceType isr2ResCountTmp;
#endif /* CFG_STD_RESOURCE_MAX > 0 */
#if (CFG_SPINLOCK_MAX > 0U)
    SpinlockIdType SpinlockId;
    SpinlockIdType spinLockIdx;
#endif                                                              /* CFG_SPINLOCK_MAX > 0U */

    pOsICB = &Os_ICB[Os_SCB.sysRunningIsrCat2Id]; /* PRQA S 0404 */ /* MISRA Rule 1.3,13.2 */
#if (CFG_STD_RESOURCE_MAX > 0)
    isr2ResCountTmp = pOsICB->IsrC2ResCount;
    /*OS369*/
    /* free the resources occupied on the ISRs*/
    if (isr2ResCountTmp > 0U)
    {
        Os_ResourceType OsResLoopi;
        Core_Id = Os_SCB.sysCore;
        Core_Index = Core_Id << 12;
        for (OsResLoopi = isr2ResCountTmp; OsResLoopi > 0U; OsResLoopi--)
        {
            (void)ReleaseResource(Core_Index | pOsICB->IsrC2ResourceStack[OsResLoopi - 1U]);
        }
        pOsICB->IsrC2ResCount = 0u;

#if (TRUE == CFG_ERRORHOOK)
        Os_CallErrorHook(E_OS_RESOURCE);
#endif /*End TRUE == CFG_ERRORHOOK*/
    }
#endif /* CFG_STD_RESOURCE_MAX > 0 */

    /*OS368*/
    if ((pOsICB->isrC2DisableAllCount > 0U) || (pOsICB->isrC2SuspendAllCount > 0U)
        || (pOsICB->isrC2SuspendOSCount > 0U))
    {
        if (pOsICB->isrC2DisableAllCount > 0U)
        {
            EnableAllInterrupts();
        }
        while (pOsICB->isrC2SuspendAllCount > 0U)
        {
            ResumeAllInterrupts();
        }
        while (pOsICB->isrC2SuspendOSCount > 0U)
        {
            ResumeOSInterrupts();
        }
#if (TRUE == CFG_ERRORHOOK)
        Os_CallErrorHook(E_OS_DISABLEDINT);
#endif /* TRUE == CFG_ERRORHOOK*/
    }

#if (CFG_SPINLOCK_MAX > 0U)
    for (spinLockIdx = pOsICB->isr2CriticalZoneCount; spinLockIdx > 0u; spinLockIdx--)
    {
        if (OBJECT_SPINLOCK == pOsICB->isr2CriticalZoneType[pOsICB->isr2CriticalZoneCount - 1u])
        {
            SpinlockId = pOsICB->isr2CriticalZoneStack[pOsICB->isr2CriticalZoneCount - 1u];
            (void)ReleaseSpinlock(SpinlockId);

#if (TRUE == CFG_ERRORHOOK)
            Os_CallErrorHook(E_OS_SPINLOCK);
#endif /*End TRUE == CFG_ERRORHOOK*/
        }
    }
#endif /* CFG_SPINLOCK_MAX > 0U */
}

/********************************************************************/
/*
 * Brief                <Check object access to the calling Task/Isr2>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <None>
 * param-eventId[in]    <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * PreCondition         <None>
 * CallByAPI            <GetAlarm>
 * REQ ID               <DD_1_0876, DD_1_1223, DD_1_1156, DD_1_0877>
 */
/********************************************************************/
FUNC(boolean, OS_CODE) Os_CheckObjAcs(ObjectTypeType ObjectType, Os_AppObjectId ObjectID)
{
    boolean Status = TRUE;
    /*OS056*/
    if ((OS_LEVEL_TASK == Os_SCB.sysOsLevel) || (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel))
    {
        if (NO_ACCESS == CheckObjectAccess(Os_SCB.sysRunningAppID, ObjectType, ObjectID))
        {
            Status = FALSE; /*no access*/
        }
        else
        {
            Status = TRUE;
        }
    }

    return Status;
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#endif /* TRUE == CFG_SERVICE_PROTECTION_ENABLE */
#endif /*(OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC)*/
