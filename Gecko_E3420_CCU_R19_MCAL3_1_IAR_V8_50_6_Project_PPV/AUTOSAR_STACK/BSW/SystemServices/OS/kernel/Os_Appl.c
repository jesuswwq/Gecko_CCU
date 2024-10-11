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
**  FILENAME    : Os_Appl.c                                                   **
**                                                                            **
**  Created on  :                                                             **
**  Author      : shun.li                                                     **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>    <AUTHOR>    <REVISION LOG>
 *  V0.1.0       2016-07-08  shun.li           Initial version.
 *  V0.2.0       2019-08-21  shun.li & zhiqiang.huang   Functional safety initial version.
 *  V1.0.0       2019-11-21  shun.li      Functional safety version.
 */
/*============================================================================*/
/*=======[I N C L U D E S]====================================================*/
#include "Os_Internal.h"

/*=======[M A C R O S]========================================================*/

/*=======[T Y P E   D E F I N I T I O N S]====================================*/

/*=======[E X T E R N A L   D A T A]==========================================*/
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
P2CONST(Os_ObjectAppCfgType*, AUTOMATIC, OS_VAR) Os_ObjectAppCfg = NULL_PTR;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
VAR(ApplicationType, AUTOMATIC) Os_AppSysCfg;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#endif /* #if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC)) */

/*=======[E X T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/

/*=======[I N T E R N A L   D A T A]==========================================*/
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
#define OS_START_SEC_CODE
#include "Os_MemMap.h"

/*=======[I N T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/

#define CFG_QUEUETASK_INVALID OS_TASK_IDLE

/* The size of the minimum access bit unit for one application */
/* DD_1_0176 */
#define OS_APPACCBITUNIT_SIZE (sizeof(ApplicationType) << 3u)

/*the access application bit position based on the access bit unit size*/
#define OS_APPGETACCESS_BP(osAppId) ((osAppId) % OS_APPACCBITUNIT_SIZE)

/*the access application bit group*/
/*(osAppId /OS_APPACCBITUNIT_SIZE)*/
#define OS_APPGETACCESS_GP(osAppId) ((osAppId) >> 4u)

/*the access mask of the application*/
#define OS_APPACCESS_MASK(osAppId) ((uint16)1u << OS_APPGETACCESS_BP(osAppId))

/**
 * Isr Objects Terminating Handling
 */
#if (CFG_ISR_MAX > 0)
static FUNC(void, OS_CODE)
    Os_TerminateISRObjectHandler(P2CONST(Os_IsrType, AUTOMATIC, OS_VAR) pOsAppIsrRef, Os_IsrType OsAppIsrCnt);
static FUNC(void, OS_CODE) Os_AppTerminateIsrKernelProc(Os_IsrType OsIsrID);
#endif /* CFG_ISR_MAX > 0 */

/**
 * Task Objects Terminating Handling
 */
static FUNC(void, OS_CODE)
    Os_TerminateTaskObjectHandler(P2CONST(Os_TaskType, AUTOMATIC, OS_VAR) pOsAppTaskRef, Os_TaskType OsAppTaskCnt);
static FUNC(StatusType, OS_CODE) Os_ApplTerminateOneTask(Os_TaskType OsTaskID);
static FUNC(void, OS_CODE) Os_ApplReadyQueRmvS1(
    Os_TaskType OsTaskID,
    uint32 OsQueueSize,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(Os_ReadyQueueType, AUTOMATIC, OS_VAR) pOsReadyQueueMark,
    P2VAR(Os_TaskType, AUTOMATIC, OS_VAR) pOsReadyQueue
    /* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
);
static FUNC(void, OS_CODE) Os_ApplReadyQueRmvS2(
    Os_TaskType OsTaskID,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(Os_ReadyQueueType, AUTOMATIC, OS_VAR) pOsReadyQueueMark,
    P2VAR(Os_TaskType, AUTOMATIC, OS_VAR) pOsReadyQueue
    /* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
);
static FUNC(void, OS_CODE) Os_ApplReadyQueRmvS3(
    Os_TaskType OsTaskID,
    uint32 OsQueueSize,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(Os_ReadyQueueType, AUTOMATIC, OS_VAR) pOsReadyQueueMark,
    P2VAR(Os_TaskType, AUTOMATIC, OS_VAR) pOsReadyQueue
    /* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
);
static FUNC(Os_ApplRmvQueSceType, OS_CODE) Os_ApplGetReadyQueRmvSec(
    uint32 OsQueueHead,
    uint32 OsQueueTail,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2CONST(Os_TaskType, AUTOMATIC, OS_VAR) pOsReadyQueue
    /* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
);
static FUNC(void, OS_CODE) Os_ApplReadyQueueRemove(Os_TaskType OsTaskID, Os_PriorityType OsQueuePriority);

static FUNC(void, OS_CODE) Os_TerminateObjects(P2CONST(Os_ApplicationCfgType, AUTOMATIC, OS_VAR) pOsCurAppCfg);
/**
 * Resources objects terminating handling controlled by its owner Task or ISR
 */
#if (CFG_STD_RESOURCE_MAX > 0)
static FUNC(void, OS_CODE)
    Os_ApplReleaseResource(ResourceType ResID, ObjectTypeType Object, Os_AppObjectIDType OsAppObjID);
#endif /* CFG_STD_RESOURCE_MAX > 0 */

/**
 * Alarm Objects Terminating Handling
 */
#if (CFG_ALARM_MAX > 0)
static FUNC(void, OS_CODE)
    Os_TerminateAlarmObjectHandler(P2CONST(Os_AlarmType, AUTOMATIC, OS_VAR) pOsAppAlarmRef, Os_AlarmType OsAppAlarmCnt);
#endif /* CFG_ALARM_MAX > 0 */

/**
 * ScheduleTable Objects Terminating Handling
 */
#if (CFG_SCHEDTBL_MAX > 0)
static FUNC(void, OS_CODE) Os_TerminateScheduleTblObjectHandler(
    P2CONST(Os_ScheduleTableType, AUTOMATIC, OS_VAR) pOsAppSchTblRef,
    Os_ScheduleTableType OsAppSchTblCnt);
#endif /* CFG_SCHEDTBL_MAX > 0 */

/*=======[F U N C T I O N   I M P L E M E N T A T I O N S]====================*/
/******************************************************************************/
/*
 * Brief                <Init the Application control block>
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * PreCondition         <None>
 * CallByAPI            <Os_InitSystem>
 * REQ ID               <DD_1_0777, DD_1_0778, DD_1_1472>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_InitApplication(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    ApplicationType i;

    switch (Os_SCB.sysCore)
    {
#if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
    case 0:
        Os_ObjectAppCfg = Os_ObjectAppCfgCore0;
        Os_AppSysCfg = APP_SYS_CORE0;
        break;
#endif /* TRUE == CFG_CORE0_AUTOSAROS_ENABLE */

#if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
    case 1:
        Os_ObjectAppCfg = Os_ObjectAppCfgCore1;
        Os_AppSysCfg = APP_SYS_CORE1;
        break;
#endif /* TRUE == CFG_CORE1_AUTOSAROS_ENABLE */

#if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
    case 2:
        Os_ObjectAppCfg = Os_ObjectAppCfgCore2;
        Os_AppSysCfg = APP_SYS_CORE2;
        break;
#endif /* TRUE == CFG_CORE2_AUTOSAROS_ENABLE */

#if (TRUE == CFG_CORE3_AUTOSAROS_ENABLE)
    case 3:
        Os_ObjectAppCfg = Os_ObjectAppCfgCore3;
        Os_AppSysCfg = APP_SYS_CORE3;
        break;
#endif /* TRUE == CFG_CORE3_AUTOSAROS_ENABLE */

#if (TRUE == CFG_CORE4_AUTOSAROS_ENABLE)
    case 4:
        Os_ObjectAppCfg = Os_ObjectAppCfgCore4;
        Os_AppSysCfg = APP_SYS_CORE4;
        break;
#endif /* TRUE == CFG_CORE4_AUTOSAROS_ENABLE */

#if (TRUE == CFG_CORE5_AUTOSAROS_ENABLE)
    case 5:
        Os_ObjectAppCfg = Os_ObjectAppCfgCore5;
        Os_AppSysCfg = APP_SYS_CORE5;
        break;
#endif /* TRUE == CFG_CORE5_AUTOSAROS_ENABLE */

    /*add comments to pass QAC.*/
    default:
        while (1)
        {
            /* nothing to do */
        }
        break; /* PRQA S 2880 */ /* MISRA Rule 2.1 */
    }

    Os_SCB.sysRunningAppID = Os_AppSysCfg;
    for (i = 0u; i < CFG_OSAPPLICATION_MAX; i++)
    {
        Os_AppCB[i].appState = APPLICATION_ACCESSIBLE;
    }
}

/******************************************************************************/
/*
 * Brief                <This service determines the OS-Application (a unique
 *                         identifier has to be allocated to each application)
 *                         where the caller originally belongs to (was configured to)>
 * Service ID           <OSServiceId_GetApplicationID>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * Return value         <OS-Application id>
 * PreCondition         <SC3 and SC4>
 * CallByAPI            <None>
 * REQ ID               <DD_1_0417, DD_1_0418, DD_1_0419, DD_1_1560, DD_1_0421, DD_1_1643>
 */
/******************************************************************************/
FUNC(ApplicationType, OS_CODE) GetApplicationID(void) /* PRQA S 1503 */ /* MISRA Rule 2.1 */
{
    ApplicationType ApplID;
    OS_ARCH_DECLARE_CRITICAL();
    OS_GAI_DEFINE();
    OS_GAI_ENTRY();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

/*service protection*/
#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    if (Os_WrongContext(OS_CONTEXT_GET_APPLICATION_ID) != TRUE)
    {
        ApplID = OS_APPLICATION_INVALID;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        ApplID = OS_APPLICATION_INVALID;
    }
    else
#endif /*TRUE == CFG_SERVICE_PROTECTION_ENABLE*/
    {
        OS_ARCH_ENTRY_CRITICAL();

/*OS261: return the identifier to which the executing Task/ISR/hook was configured*/
#if (CFG_TRUSTED_SYSTEM_SERVICE_MAX > 0U)
        if (0u != Os_TrustedFuncNest)
        {
            ApplID = Os_TrustedFuncNestQueue[Os_TrustedFuncNest - 1U];
        }
        else
#endif /* CFG_TRUSTED_SYSTEM_SERVICE_MAX > 0U */
        {
            ApplID = Os_SCB.sysRunningAppID;
        }

        if (ApplID < CFG_OSAPPLICATION_MAX) /* OS262 */
        {
            if (Os_AppSysCfg == ApplID)
            {
                ApplID = OS_APPLICATION_INVALID;
            }
        }
        else
        {
            ApplID = OS_APPLICATION_INVALID;
        }

        OS_ARCH_EXIT_CRITICAL();
    }

    OS_GAI_EXIT();
    return ApplID;
}

/******************************************************************************/
/*
 * Brief                <This service determines the currently running
 *                      OS-Application (a unique identifier has to be
 *                      allocated to each application)>
 * Service ID           <OSServiceId_GetCurrentApplicationID>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * Return value         <OS-Application id>
 * PreCondition         <SC3 and SC4>
 * CallByAPI            <None>
 * REQ ID               <DD_1_0422, DD_1_0423, DD_1_0424, DD_1_1561, DD_1_0426, DD_1_1644>
 */
/******************************************************************************/
FUNC(ApplicationType, OS_CODE) GetCurrentApplicationID(void) /* PRQA S 1503 */ /* MISRA Rule 2.1 */
{
    ApplicationType ApplID;
    OS_ARCH_DECLARE_CRITICAL();
    OS_GCAI_DEFINE();
    OS_GCAI_ENTRY();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

/*service protection*/
#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    if (Os_WrongContext(OS_CONTEXT_GET_CURRENT_APPLICATION_ID) != TRUE)
    {
        ApplID = OS_APPLICATION_INVALID;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        ApplID = OS_APPLICATION_INVALID;
    }
    else
#endif /*TRUE == CFG_SERVICE_PROTECTION_ENABLE*/
    {
        OS_ARCH_ENTRY_CRITICAL();

        /*OS798: return the identifier in which the current Task/ISR/hook is executed*/
        ApplID = Os_SCB.sysRunningAppID;
        if (ApplID < CFG_OSAPPLICATION_MAX) /* OS799 */
        {
            if (Os_AppSysCfg == ApplID)
            {
                ApplID = OS_APPLICATION_INVALID;
            }
        }
        else
        {
            ApplID = OS_APPLICATION_INVALID;
        }

        OS_ARCH_EXIT_CRITICAL();
    }

    OS_GCAI_EXIT();
    return ApplID;
}

/******************************************************************************/
/*
 * Brief                <This service sets the own state of an OS-Application
 *                         from APPLICATION_RESTARTING to APPLICATION_ACCESSIBLE.>
 * Service ID           <OSServiceId_AllowAccess>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * Return value         <StatusType>
 * PreCondition         <SC3 and SC4>
 * CallByAPI            <None>
 * REQ ID               <DD_1_0562, DD_1_0563, DD_1_0564, DD_1_1562, DD_1_0566, DD_1_1645>
 */
/******************************************************************************/
FUNC(StatusType, OS_CODE) AllowAccess(void) /* PRQA S 1503 */ /* MISRA Rule 2.1 */
{
    StatusType OsReturnErr = E_OK;
    OS_ARCH_DECLARE_CRITICAL();
    OS_AAS_DEFINE();
    OS_AAS_ENTRY();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    if (Os_WrongContext(OS_CONTEXT_ALLOW_ACCESS) != TRUE)
    {
        OsReturnErr = E_OS_CALLEVEL;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        OsReturnErr = E_OS_DISABLEDINT;
    }
    else
#endif /*#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)*/
    {
        OS_ARCH_ENTRY_CRITICAL();
        if (APPLICATION_RESTARTING != Os_AppCB[Os_SCB.sysRunningAppID].appState)
        {
            OsReturnErr = E_OS_STATE;
        }
        else
        {
            Os_AppCB[Os_SCB.sysRunningAppID].appState = APPLICATION_ACCESSIBLE;
        }
        OS_ARCH_EXIT_CRITICAL();
    }

    OS_AAS_EXIT();
    return OsReturnErr;
}

/******************************************************************************/
/*
 * Brief                <This service returns the current state of an OS-Application.>
 * Service ID           <OSServiceId_GetApplicationState>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * Return value         <StatusType>
 * PreCondition         <SC3 and SC4>
 * CallByAPI            <None>
 * REQ ID               <DD_1_0567, DD_1_1041, DD_1_0569, DD_1_1523, DD_1_1524, DD_1_1563,
 *                       DD_1_1571, DD_1_1646>
 */
/******************************************************************************/
FUNC(StatusType, OS_CODE)
GetApplicationState /* PRQA S 1503 */ /* MISRA Rule 2.1 */
    (ApplicationType Application, ApplicationStateRefType Value)
{
    StatusType OsReturnErr = E_OK;
    OS_GAS_DEFINE();
    OS_GAS_ENTRY();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    if (Os_WrongContext(OS_CONTEXT_GET_APPLICATION_STATE) != TRUE)
    {
        OsReturnErr = E_OS_CALLEVEL;
    }
    else if (Os_AddressWritable((uint8*)Value) != TRUE)
    {
        OsReturnErr = E_OS_ILLEGAL_ADDRESS;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        OsReturnErr = E_OS_DISABLEDINT;
    }
    else
#endif /*#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)*/
    {
#if (OS_STATUS_EXTENDED == CFG_STATUS)
        if (CFG_OSAPPLICATION_MAX <= Application)
        {
#if (TRUE == CFG_ERRORHOOK)
            Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

            OsReturnErr = E_OS_ID;
        }
        else
#endif /*#if (OS_STATUS_EXTENDED == CFG_STATUS)*/
        {
            *Value = Os_AppCB[Application].appState;
        }
    }

    OS_GAS_EXIT();
    return OsReturnErr;
}

/******************************************************************************/
/*
 * Brief                <This service determines if the OS-Applications,
 *                       given by ApplID, is allowed to use the IDs of a
 *                       Task, ISR, Resource, Counter, Alarm or Schedule
 *                       Table in API calls.>
 * Service ID           <OSServiceId_CheckObjectAccess>
 * Sync/Async           <Synchronous>
 * Reentrancy           < Reentrant>
 * param-Name[in]       <ApplID>
 *                      <ObjectType>
 *                      <ObjectID>
 * Return value         <ACCESS>
 *                      <NO_ACCESS>
 * PreCondition         <SC3 and SC4>
 * REQ ID               <DD_1_0456, DD_1_1026(1), DD_1_0457, DD_1_0458, DD_1_1332,
 *                       DD_1_1333, DD_1_1519, DD_1_1520, DD_1_1521, DD_1_1522,
 *                       DD_1_1564, DD_1_0461, DD_1_1647>
 */
/******************************************************************************/
FUNC(ObjectAccessType, OS_CODE)
CheckObjectAccess /* PRQA S 1532 */ /* MISRA Rule 8.7 */
    (ApplicationType ApplID, ObjectTypeType ObjectType, AppObjectId ObjectID)
{
    ObjectAccessType Ret_Access = ACCESS;
    ApplicationType osAccAppNodePos;
    ApplicationType osAccAppBitPos;
    P2CONST(ApplicationType, AUTOMATIC, OS_VAR) pOsAccAppRef;
    P2CONST(Os_AppObjectId, AUTOMATIC, OS_VAR) pObjectIDMaxTableRef;
    P2CONST(Os_ObjectAppCfgType*, AUTOMATIC, OS_VAR) pObjectAppCfgRef;
    OS_COA_DEFINE();
    OS_COA_ENTRY();

    OS_ARCH_DECLARE_CRITICAL();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

/*service protection*/
#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    if (Os_WrongContext(OS_CONTEXT_CHECK_OBJECT_ACCESS) != TRUE)
    {
        Ret_Access = NO_ACCESS;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        Ret_Access = NO_ACCESS;
    }
    else
#endif /*TRUE == CFG_SERVICE_PROTECTION_ENABLE*/
    {
        /*MultiCore: According to the Object's Core ID, get the corresponding access structure.*/
        switch (Os_GetObjCoreId(ObjectID))
        {
#if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
        case 0:
            pObjectAppCfgRef = Os_ObjectAppCfgCore0;
            pObjectIDMaxTableRef = Os_ObjectIDMaxTableCore0;
            break;
#endif /* TRUE == CFG_CORE0_AUTOSAROS_ENABLE */

#if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
        case 1:
            pObjectAppCfgRef = Os_ObjectAppCfgCore1;
            pObjectIDMaxTableRef = Os_ObjectIDMaxTableCore1;
            break;
#endif /* TRUE == CFG_CORE1_AUTOSAROS_ENABLE */

#if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
        case 2:
            pObjectAppCfgRef = Os_ObjectAppCfgCore2;
            pObjectIDMaxTableRef = Os_ObjectIDMaxTableCore2;
            break;
#endif /* TRUE == CFG_CORE2_AUTOSAROS_ENABLE */

#if (TRUE == CFG_CORE3_AUTOSAROS_ENABLE)
        case 3:
            pObjectAppCfgRef = Os_ObjectAppCfgCore3;
            pObjectIDMaxTableRef = Os_ObjectIDMaxTableCore3;
            break;
#endif /* TRUE == CFG_CORE3_AUTOSAROS_ENABLE */

#if (TRUE == CFG_CORE4_AUTOSAROS_ENABLE)
        case 4:
            pObjectAppCfgRef = Os_ObjectAppCfgCore4;
            pObjectIDMaxTableRef = Os_ObjectIDMaxTableCore4;
            break;
#endif /* TRUE == CFG_CORE4_AUTOSAROS_ENABLE */

#if (TRUE == CFG_CORE5_AUTOSAROS_ENABLE)
        case 5:
            pObjectAppCfgRef = Os_ObjectAppCfgCore5;
            pObjectIDMaxTableRef = Os_ObjectIDMaxTableCore5;
            break;
#endif /* TRUE == CFG_CORE5_AUTOSAROS_ENABLE */

        default:
            while (1)
            {
                /*nothing to do*/
            }
            break; /* PRQA S 2880 */ /* MISRA Rule 2.1 */
        }

        /*MultiCore: Change to local id*/
        ObjectID = Os_GetObjLocalId(ObjectID);

        /*OS423: if the ApplID is invalid , return NO_ACCESS*/
        if (ApplID >= CFG_OSAPPLICATION_MAX)
        {
#if (TRUE == CFG_ERRORHOOK)
            Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

            Ret_Access = NO_ACCESS;
        }
        /*OS423: if the objectType is not a valid , return NO_ACCESS*/
        else if (ObjectType >= OBJECT_MAX)
        {
#if (TRUE == CFG_ERRORHOOK)
            Os_CallErrorHook(E_OS_VALUE);
#endif /* TRUE == CFG_ERRORHOOK */

            Ret_Access = NO_ACCESS;
        }
        else if (ObjectID < pObjectIDMaxTableRef[ObjectType])
        {
            OS_ARCH_ENTRY_CRITICAL();

            if ((OBJECT_RESOURCE == ObjectType) || (OBJECT_SPINLOCK == ObjectType))
            {
                /*Object do not belong to any application*/
            }
            else
            {
                /* SWS_Os_00504, SWS_Os_00509 */
                if ((pObjectAppCfgRef[ObjectType][ObjectID].hostApp != Os_SCB.sysRunningAppID)
                    && (Os_AppCB[pObjectAppCfgRef[ObjectType][ObjectID].hostApp].appState != APPLICATION_ACCESSIBLE))
                {
                    OS_ARCH_EXIT_CRITICAL();
                    Ret_Access = NO_ACCESS;
                }
            }

            if ((ObjectAccessType)ACCESS == Ret_Access)
            {
/* OS318: if the object type is OBJECT_RESOURCE and the object is
 * RES_SCHEDULER , return ACCESS */
#if (TRUE == CFG_USERESSCHEDULER)
                if ((OBJECT_RESOURCE == ObjectType) && (RES_SCHEDULER == ObjectID))
                {
                    Ret_Access = ACCESS;
                }
                else
#endif /* TRUE == CFG_USERESSCHEDULER */
                {
                    /* ApplID in which bit_group(uint16). */
                    osAccAppNodePos = OS_APPGETACCESS_GP(ApplID);
                    /* ApplID in which bit_pos of uint16. */
                    osAccAppBitPos = OS_APPACCESS_MASK(ApplID);
                    /* Access right bit map. */
                    pOsAccAppRef = pObjectAppCfgRef[ObjectType][ObjectID].accAppRef;

                    /* Check object access right by app_id. */
                    if ((osAccAppBitPos & pOsAccAppRef[osAccAppNodePos]) > 0u)
                    {
                        Ret_Access = ACCESS;
                    }
                    else
                    {
                        Ret_Access = NO_ACCESS;
                    }
                }
                OS_ARCH_EXIT_CRITICAL();
            }
        }
        else
        {
#if (TRUE == CFG_ERRORHOOK)
            Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */
            Ret_Access = NO_ACCESS;
        }
    }

    OS_COA_EXIT();
    /*OS272: if the ApplID has no access to the queried boject , return NO_ACCESS*/
    return Ret_Access;
}

/******************************************************************************/
/*
 * Brief                <This service determines to which OS-Application
 *                      a given Task, ISR, Resource, Counter, Alarm or
 *                      Schedule Table belongs>
 * Service ID           <OSServiceId_CheckObjectOwnership>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-Name[in]       <ObjectType>
 *                      <ObjectID>
 * Return value         <OS-Application id>
 * PreCondition         <SC3 and SC4>
 * REQ ID               <DD_1_0462, DD_1_1027, DD_1_0463, DD_1_0464, DD_1_1335,
 *                       DD_1_1565, DD_1_0466, DD_1_1648>
 */
/******************************************************************************/
FUNC(ApplicationType, OS_CODE)
CheckObjectOwnership(ObjectTypeType ObjectType, AppObjectId ObjectID) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    ApplicationType ApplID = OS_APPLICATION_VALID;
    P2CONST(Os_AppObjectId, AUTOMATIC, OS_VAR) pObjectIDMaxTableRef;
    P2CONST(Os_ObjectAppCfgType*, AUTOMATIC, OS_VAR) pObjectAppCfgRef;

    OS_ARCH_DECLARE_CRITICAL();
    OS_COO_DEFINE();
    OS_COO_ENTRY();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

/*service protection*/
#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    if (Os_WrongContext(OS_CONTEXT_CHECK_OBJECT_OWNERSHIP) != TRUE)
    {
        ApplID = OS_APPLICATION_INVALID;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        ApplID = OS_APPLICATION_INVALID;
    }
    else
#endif /*TRUE == CFG_SERVICE_PROTECTION_ENABLE*/
    {
        /*MultiCore: According to the Object's Core ID, get the corresponding access structure.*/
        switch (Os_GetObjCoreId(ObjectID))
        {
#if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
        case 0:
            pObjectAppCfgRef = (const Os_ObjectAppCfgType**)Os_ObjectAppCfgCore0;
            pObjectIDMaxTableRef = Os_ObjectIDMaxTableCore0;
            break;
#endif /* TRUE == CFG_CORE0_AUTOSAROS_ENABLE */

#if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
        case 1:
            pObjectAppCfgRef = (const Os_ObjectAppCfgType**)Os_ObjectAppCfgCore1;
            pObjectIDMaxTableRef = Os_ObjectIDMaxTableCore1;
            break;
#endif /* TRUE == CFG_CORE1_AUTOSAROS_ENABLE */

#if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
        case 2:
            pObjectAppCfgRef = (const Os_ObjectAppCfgType**)Os_ObjectAppCfgCore2;
            pObjectIDMaxTableRef = Os_ObjectIDMaxTableCore2;
            break;
#endif /* TRUE == CFG_CORE2_AUTOSAROS_ENABLE */

#if (TRUE == CFG_CORE3_AUTOSAROS_ENABLE)
        case 3:
            pObjectAppCfgRef = (const Os_ObjectAppCfgType**)Os_ObjectAppCfgCore3;
            pObjectIDMaxTableRef = Os_ObjectIDMaxTableCore3;
            break;
#endif /* TRUE == CFG_CORE3_AUTOSAROS_ENABLE */

#if (TRUE == CFG_CORE4_AUTOSAROS_ENABLE)
        case 4:
            pObjectAppCfgRef = (const Os_ObjectAppCfgType**)Os_ObjectAppCfgCore4;
            pObjectIDMaxTableRef = Os_ObjectIDMaxTableCore4;
            break;
#endif /* TRUE == CFG_CORE4_AUTOSAROS_ENABLE */

#if (TRUE == CFG_CORE5_AUTOSAROS_ENABLE)
        case 5:
            pObjectAppCfgRef = (const Os_ObjectAppCfgType**)Os_ObjectAppCfgCore5;
            pObjectIDMaxTableRef = Os_ObjectIDMaxTableCore5;
            break;
#endif /* TRUE == CFG_CORE5_AUTOSAROS_ENABLE */

        default:
            /* Nothing to do. */
            ApplID = OS_APPLICATION_INVALID;
            break;
        }

        if ((ApplicationType)OS_APPLICATION_VALID == ApplID)
        {
            /*MultiCore: Change to local id*/
            ObjectID = Os_GetObjLocalId(ObjectID);

            if (ObjectType >= OBJECT_MAX)
            {
#if (TRUE == CFG_ERRORHOOK)
                Os_CallErrorHook(E_OS_VALUE);
#endif /* TRUE == CFG_ERRORHOOK */

                ApplID = OS_APPLICATION_INVALID;
            }
            else
            {
                if (ObjectID < pObjectIDMaxTableRef[ObjectType])
                {
                    OS_ARCH_ENTRY_CRITICAL();
/* OS318: if the object type is OBJECT_RESOURCE and the object is
 * RES_SCHEDULER , return ACCESS */
#if (TRUE == CFG_USERESSCHEDULER)
                    if ((OBJECT_RESOURCE == ObjectType) && (RES_SCHEDULER == ObjectID))
                    {
                        ApplID = OS_APPLICATION_INVALID;
                    }
                    else
#endif /* TRUE == CFG_USERESSCHEDULER */
                    {
                        ApplID = pObjectAppCfgRef[ObjectType][ObjectID].hostApp;
                    }
                    OS_ARCH_EXIT_CRITICAL();
                }
                else
                {
                    ApplID = OS_APPLICATION_INVALID;
#if (TRUE == CFG_ERRORHOOK)
                    Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */
                }
            }
        }
    }

    OS_COO_EXIT();
    return ApplID;
}

/******************************************************************************/
/*
 * Brief                <Terminate Application>
 * ServiceId            <OSServiceId_TerminateApplication>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Yes>
 * Param-Name[in]       <Application>
 *                      <RestartOption>
 * Return               <E_OS_CALLEVEL>
 *                      <E_OS_VALUE>
 * PreCondition         <None>
 * PreCondition         <SC3 and SC4>
 * REQ ID               <DD_1_0552, DD_1_1039, DD_1_0555, DD_1_0556, DD_1_0557,
 *                       DD_1_0558, DD_1_1328, DD_1_1329, DD_1_1330, DD_1_1331,
 *                       DD_1_1334, DD_1_1525, DD_1_1526, DD_1_1566, DD_1_0561,
 *                       DD_1_1649>
 */
/******************************************************************************/
FUNC(StatusType, OS_CODE)
TerminateApplication(ApplicationType Application, RestartType RestartOption) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Os_CoreIdType Core_Id;
    Os_CoreIdType Core_Index;
    StatusType OsReturnErr = E_OK;
    Os_CallLevelType sysCallLevel;
    ApplicationStateType TempAppState;
    P2CONST(Os_ApplicationCfgType, AUTOMATIC, OS_VAR) posCurAppCfg;
    OS_TA_DEFINE();
    OS_TA_ENTRY();

    OS_ARCH_DECLARE_CRITICAL();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

    OS_ARCH_ENTRY_CRITICAL();
    sysCallLevel = Os_SCB.sysOsLevel;
    posCurAppCfg = &Os_AppCfg[Os_SCB.sysRunningAppID];
    OS_ARCH_EXIT_CRITICAL();

#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    /*OS088*/
    if (Os_WrongContext(OS_CONTEXT_TERMINATE_APPLICATION) != TRUE)
    {
        OsReturnErr = E_OS_CALLEVEL;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        OsReturnErr = E_OS_DISABLEDINT;
    }
    else
    {
        /* nothing to do*/
    }
    if ((StatusType)E_OK == OsReturnErr)
#endif /*TRUE == CFG_SERVICE_PROTECTION_ENABLE*/
    {
#if (OS_STATUS_EXTENDED == CFG_STATUS)
        /*SWS_Os_00493*/
        if (CFG_OSAPPLICATION_MAX <= Application)
        {
#if (TRUE == CFG_ERRORHOOK)
            Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

            OsReturnErr = E_OS_ID;
        }
        else if (Application != Os_SCB.sysRunningAppID)
        {
            /* now it's not support in a application terminate another application,
             * so return E_OS_ACCESS to notify user*/
            OsReturnErr = E_OS_ACCESS;
        }
        /*SWS_Os_00459: if the <RestartOption> is invalid, return E_OS_VALUE*/
        else if ((RESTART != RestartOption) && (NO_RESTART != RestartOption))
        {
#if (CFG_ERRORHOOK == TRUE)
            OSError_Save_ServiceId(OSServiceId_TerminateApplication);
            OSError_Save_TerminateApplication(Application, RestartOption);
            Os_CallErrorHook(E_OS_VALUE);
#endif /* #if (CFG_ERRORHOOK == TRUE) */

            OsReturnErr = E_OS_VALUE;
        }
/*SWS_Os_00494 will be opened in future.*/
#if 0
        /*SWS_Os_00494*/
        else if ((FALSE == posCurAppCfg->OsTrusted) && (Os_SCB.sysRunningAppID != Application))
        {
            OsReturnErr = E_OS_ACCESS;
        }
#endif
        /*SWS_Os_00507*/
        else if (APPLICATION_TERMINATED == Os_AppCB[Application].appState)
        {
            OsReturnErr = E_OS_STATE;
        }
        else if (APPLICATION_RESTARTING == Os_AppCB[Application].appState)
        {
/*now it's not support in a application terminate another application,
 * so SWS_Os_00508 is closed.*/
#if 0
            /*SWS_Os_00508*/
            if (Os_SCB.sysRunningAppID != Application)
            {
                OsReturnErr = E_OS_STATE;
            }
            else
            {
                /*SWS_Os_00548*/
                if (RESTART == RestartOption)
                {
                    OsReturnErr = E_OS_STATE;
                }
            }
#else
            /*SWS_Os_00548*/
            if (RESTART == RestartOption)
            {
                OsReturnErr = E_OS_STATE;
            }
#endif
        }
        else
        {
            /*nothing to do*/
        }
#endif /*#if (OS_STATUS_EXTENDED == CFG_STATUS)*/

        if ((StatusType)E_OK == OsReturnErr)
        {
            OS_ARCH_ENTRY_CRITICAL();

            /*@OS287: If Called from allowed context, terminate the calling OS-Application*/
            Os_TerminateObjects(posCurAppCfg);

/* OS447: Disable the interrupt source of the OsIsrs owned by the application */
#if (CFG_ISR_MAX > 0)
            Os_ArchDisableIntInApp(posCurAppCfg);
#endif /* CFG_ISR_MAX > 0 */

            if (RESTART == RestartOption)
            {
                Os_AppCB[Application].appState = APPLICATION_RESTARTING;
            }
            else
            {
                Os_AppCB[Application].appState = APPLICATION_TERMINATED;
            }

            /*@OS346: if RESTART, activate the OsRestartTask of the application*/
            if ((RESTART == RestartOption) && (Os_CfgTaskMax > posCurAppCfg->OsRestartTask))
            {
                /* Set OsLevel to OS_LEVEL_TASK in order to call ActivateTask.
                 * ActivateTask can not be called in OS_LEVEL_ERRORHOOK_APP level. */
                if (OS_LEVEL_ERRORHOOK_APP == sysCallLevel)
                {
                    Os_SCB.sysOsLevel = OS_LEVEL_TASK;
                }
                Core_Id = Os_SCB.sysCore;
                Core_Index = Core_Id << 12;
                TempAppState = Os_AppCB[Application].appState;
                Os_AppCB[Application].appState = APPLICATION_ACCESSIBLE;
                /*Activate the RestartTask*/
                Os_SCB.sysDispatchLocker = Os_SCB.sysDispatchLocker + (Os_LockerType)1;
                (void)ActivateTask((Core_Index | posCurAppCfg->OsRestartTask));
                Os_SCB.sysDispatchLocker = Os_SCB.sysDispatchLocker - (Os_LockerType)1;
                Os_AppCB[Application].appState = TempAppState;
                /* In level OS_LEVEL_ERRORHOOK_APP, restore OsLevel. */
                if (OS_LEVEL_ERRORHOOK_APP == sysCallLevel)
                {
                    Os_SCB.sysOsLevel = sysCallLevel;
                }
            }

#if (CFG_ISR2_MAX > 0)
            if (TRUE == Os_SCB.sysInIsrCat2)
            {
                /* If this service is called by isr_c2, sysRunningTaskID can be
                 * set to IDLE_TASK, in order to call Os_SwitchTask in OS_ARCH_ISR2_EPILOGUE. */
                /* Tasks of this OsApp are all terminated, the sysRunningTaskID is also might be terminated,
                 * so Os_SwitchTask must be called in OS_ARCH_ISR2_EPILOGUE. */
                /*If called context is in ISR2, Now Exit */
                OS_ARCH_EXIT_CRITICAL();
                /* PRQA S 3415,3335,0306,3200,2981++ */ /* MISRA Rule 13.5,17.3,11.4,17.7,2.2 */
                OS_ARCH_ISR2_EPILOGUE();
                /* PRQA S 3415,3335,0306,3200,2981-- */ /* MISRA Rule 13.5,17.3,11.4,17.7,2.2 */
            }
            else
#endif /* CFG_ISR2_MAX > 0 */
            {
                /* Task dispatch. */
                Os_SCB.sysOsLevel = OS_LEVEL_TASK;
                Os_SCB.sysDispatchLocker = 0u;

                OS_START_DISPATCH();
                Os_Dispatch(); /* PRQA S 3335 */ /* MISRA Rule 17.3 */
            }

            OS_ARCH_EXIT_CRITICAL();
        }
    }

    OS_TA_EXIT();
    return OsReturnErr;
}

/******************************************************************************/
/*
 * Brief                <Terminate the objects belonging to the calling application>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Yes>
 * Param-Name[in]       <pOsCurAppCfg: the application config reference>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <TerminateApplication>
 * REQ ID               <DD_1_1013, DD_1_1014>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_TerminateObjects(P2CONST(Os_ApplicationCfgType, AUTOMATIC, OS_VAR) pOsCurAppCfg)
{
#if (CFG_ALARM_MAX > 0)
    /**
     * stop all active alarms
     */
    Os_TerminateAlarmObjectHandler(
        (Os_AlarmRefType)pOsCurAppCfg->OsAppObjectRef[OBJECT_ALARM],
        pOsCurAppCfg->OsAppAlarmRefCnt);
#endif /* CFG_ALARM_MAX > 0 */
/**
 * All other interrupt sources should be already disabled in above handling,
 * which as one precondition here.
 */
#if (CFG_ISR_MAX > 0)
    /**
     * Terminating ISR should check the current level to kill and free current
     * stack if in ISR Level, and take care if support nested ISRS. Besides,
     * As the resources occupied either on Task or ISR, here should free the resources
     * occupied on the ISR to continue the ISR terminating operation. And which occupied
     * on the Tasks will be handled while in the following terminating the Task objects.
     */
    /* MISRA-C: 17.4  Array subscripting applied to an object of pointer type.
       OsAppObjectRef is pointor of static_cfg_array, OsAppIsrRefCnt is the size of array,
       it must be used like below. */
    Os_TerminateISRObjectHandler((Os_IsrType*)pOsCurAppCfg->OsAppObjectRef[OBJECT_ISR], pOsCurAppCfg->OsAppIsrRefCnt);
#endif /* CFG_ISR_MAX > 0 */

#if (CFG_TASK_MAX > 0)
    /**
     * Terminate all the tasks of the application, kick out the queued request and free
     * all of the control block context, also will free the resources occupied on them.
     */
    Os_TerminateTaskObjectHandler(
        (Os_TaskRefType)pOsCurAppCfg->OsAppObjectRef[OBJECT_TASK],
        pOsCurAppCfg->OsAppTaskCnt);
#endif /* CFG_TASK_MAX > 0 */

#if (CFG_SCHEDTBL_MAX > 0)
    /**
     * stop all schedule tables
     */
    Os_TerminateScheduleTblObjectHandler(
        (Os_ScheduleTableType*)pOsCurAppCfg->OsAppObjectRef[OBJECT_SCHEDULETABLE],
        pOsCurAppCfg->OsAppScheduleTableCnt);
#endif /* CFG_SCHEDTBL_MAX > 0 */

    return;
}

#if (CFG_ISR_MAX > 0)
/******************************************************************************/
/*
 * Brief                <Terminate the ISR objects of the calling application>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Yes>
 * Param-Name[in]       <pOsAppIsrRef: the application specified Isrs ref>
 *                      <OsAppIsrCnt: the number or size of the Isrs >
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_TerminateObjects>
 * REQ ID               <DD_1_0903>
 */
/******************************************************************************/
static FUNC(void, OS_CODE)
    Os_TerminateISRObjectHandler(P2CONST(Os_IsrType, AUTOMATIC, OS_VAR) pOsAppIsrRef, Os_IsrType OsAppIsrCnt)
{
    Os_IsrType OsIsrLoopi;

    if ((0u == OsAppIsrCnt) || (Os_CfgIsrMax < OsAppIsrCnt))
    {
        /*nothing to do*/
    }
    else
    {
        for (OsIsrLoopi = 0u; OsIsrLoopi < OsAppIsrCnt; OsIsrLoopi++)
        {
/* MISRA-C: 17.4  Array subscripting applied to an object of pointer type.
   pOsAppIsrRef is pointor of static_cfg_array, OsAppIsrCnt is the size of array,
   it must be used like below. */

/* Arch platform related process. */
#if (TRUE == CFG_INT_NEST_ENABLE)
            Os_ArchAppTerminateIsrProc(Os_GetObjLocalId(pOsAppIsrRef[OsIsrLoopi]));
#endif /* TRUE == CFG_INT_NEST_ENABLE */
            Os_AppTerminateIsrKernelProc(Os_GetObjLocalId(pOsAppIsrRef[OsIsrLoopi]));
        }
    }

    return;
}

/******************************************************************************/
/*
 * Brief                <free the ISR running control block and the resources occupied>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Yes>
 * Param-Name[in]       <OsIsrID>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_TerminateISRObjectHandler>
 * REQ ID               <DD_1_0904, DD_1_0905>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_AppTerminateIsrKernelProc(Os_IsrType OsIsrID)
{
#if ((TRUE == CFG_TIMING_PROTECTION_ENABLE) || (CFG_STD_RESOURCE_MAX > 0) || (CFG_SPINLOCK_MAX > 0U))
    P2VAR(Os_ICBType volatile, AUTOMATIC, OS_VAR) pOsICB;
#endif /* ((TRUE == CFG_TIMING_PROTECTION_ENABLE) || (CFG_STD_RESOURCE_MAX > 0) \
|| (CFG_SPINLOCK_MAX > 0U))*/

#if (CFG_SPINLOCK_MAX > 0U)
    SpinlockIdType spinLockIdx;
    SpinlockIdType SpinlockId;
#endif /* CFG_SPINLOCK_MAX > 0U */
#if (CFG_STD_RESOURCE_MAX > 0)
    Os_IsrType i;
    Os_ResourceType osTemp;
#endif /* CFG_STD_RESOURCE_MAX > 0 */

    if (OsIsrID < Os_CfgIsr2Max)
    {
#if ((TRUE == CFG_TIMING_PROTECTION_ENABLE) || (CFG_STD_RESOURCE_MAX > 0) || (CFG_SPINLOCK_MAX > 0U))
        pOsICB = &Os_ICB[OsIsrID];
#endif /* ((TRUE == CFG_TIMING_PROTECTION_ENABLE) || (CFG_STD_RESOURCE_MAX > 0) \
|| (CFG_SPINLOCK_MAX > 0U))*/

/* Timing protection. */
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
        Os_TmProtIsrEnd(OsIsrID, TP_ISR_CAT2_EXE);

        pOsICB->IsrC2IsrOpt = TP_OPT_BUTT;

        if (pOsICB->isrC2DisableAllCount > 0u)
        {
            Os_TmProtIsrEnd(OsIsrID, TP_ISR_CAT2_DIS_ALL_INT);

            pOsICB->isrC2DisableAllCount = 0u;
            Os_ArchEnableAllInt_ButTimingProtInt();
        }

        if (pOsICB->isrC2SuspendAllCount > 0u)
        {
            Os_TmProtIsrEnd(OsIsrID, TP_ISR_CAT2_SUS_ALL_INT);

            Os_SuspendAllCount -= pOsICB->isrC2SuspendAllCount;
            if (0u == Os_SuspendAllCount)
            {
                Os_ArchEnableAllInt_ButTimingProtInt();
            }
        }

        if (pOsICB->isrC2SuspendOSCount > 0u)
        {
            Os_TmProtIsrEnd(OsIsrID, TP_ISR_CAT2_SUS_OS_INT);

            Os_SuspendOsCount -= pOsICB->isrC2SuspendOSCount;
            if (0u == Os_SuspendOsCount)
            {
                Os_ArchSetIpl(Os_SaveOsIntNested, OS_ISR_ENABLE);
            }
        }
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */

/* Release resource occupied by this isr. */
#if (CFG_STD_RESOURCE_MAX > 0)
        osTemp = pOsICB->IsrC2ResCount;

        if (osTemp > 0u)
        {
            for (i = osTemp; i > 0u; i--)
            {
                Os_ApplReleaseResource(pOsICB->IsrC2ResourceStack[i - 1u], OBJECT_ISR, OsIsrID);
            }
        }
#endif /* CFG_STD_RESOURCE_MAX > 0 */

#if (CFG_SPINLOCK_MAX > 0U)
        for (spinLockIdx = pOsICB->isr2CriticalZoneCount; spinLockIdx > 0u; spinLockIdx--)
        {
            if (OBJECT_SPINLOCK == pOsICB->isr2CriticalZoneType[pOsICB->isr2CriticalZoneCount - 1u])
            {
                SpinlockId = pOsICB->isr2CriticalZoneStack[pOsICB->isr2CriticalZoneCount - 1u];
                (void)ReleaseSpinlock(SpinlockId);
            }
        }
#endif /* CFG_SPINLOCK_MAX > 0U */
    }

    return;
}
#endif /*CFG_ISR_MAX > 0*/

/******************************************************************************/
/*
 * Brief                <Terminate the task objects of the calling application>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Yes>
 * Param-Name[in]       <pOsAppTaskRef: the application specified tasks ref>
 *                      <OsAppTaskCnt: the task count of this app.>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_TerminateObjects>
 * REQ ID               <DD_1_0906, DD_1_0907>
 */
/******************************************************************************/
static FUNC(void, OS_CODE)
    Os_TerminateTaskObjectHandler(P2CONST(Os_TaskType, AUTOMATIC, OS_VAR) pOsAppTaskRef, Os_TaskType OsAppTaskCnt)
{
    Os_TaskType i;
    Os_TaskType osTaskId;
    StatusType osRet;

    /*check the count to be valid */
    if ((0u == OsAppTaskCnt) || (Os_CfgTaskMax <= OsAppTaskCnt))
    {
        /*nothing to do*/
    }
    else
    {
        for (i = 0u; i < OsAppTaskCnt; i++)
        {
            osTaskId = Os_GetObjLocalId(pOsAppTaskRef[i]);

            osRet = Os_ApplTerminateOneTask(osTaskId);

            /* Os_App terminate task arch_related process. */
            if ((StatusType)E_OK == osRet)
            {
                Os_ArchAppTerminateTaskProc(osTaskId);
            }
        }
    }

    return;
}

/******************************************************************************/
/*
 * Brief                <Terminate one task.>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Yes>
 * Param-Name[in]       <OsTaskID>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_TerminateTaskObjectHandler>
 * REQ ID               <DD_1_0908, DD_1_0909>
 */
/******************************************************************************/
static FUNC(StatusType, OS_CODE) Os_ApplTerminateOneTask(Os_TaskType OsTaskID)
{
#if (CFG_STD_RESOURCE_MAX > 0U)
    uint16 i;
    Os_ResourceType osTemp;
#endif /* CFG_STD_RESOURCE_MAX > 0 */
#if (CFG_SPINLOCK_MAX > 0U)
    SpinlockIdType spinLockIdx;
    SpinlockIdType SpinlockId;
#endif /* CFG_SPINLOCK_MAX > 0U */
    StatusType osRet = E_OK;
    P2VAR(Os_TCBType volatile, AUTOMATIC, OS_VAR) pTcb;

    pTcb = &Os_TCB[OsTaskID];

    /* Terminated task no need to process. */
    if (TASK_STATE_SUSPENDED == pTcb->taskState)
    {
        osRet = E_NOT_OK;
    }
    else
    {
        if (TASK_STATE_START == pTcb->taskState)
        {
            osRet = E_NOT_OK;
        }
#if (CFG_INTERNAL_RESOURCE_MAX > 0U)
        Os_ReleaseInternalResource(OsTaskID);
#endif /* #if (CFG_INTERNAL_RESOURCE_MAX > 0U) */

/* Release resource occupied by this task. */
#if (CFG_STD_RESOURCE_MAX > 0u)
        if (pTcb->taskResCount > 0u)
        {
            osTemp = pTcb->taskResCount;

            for (i = osTemp; i > 0u; i--)
            {
                Os_ApplReleaseResource(pTcb->taskResourceStack[i - 1u], OBJECT_TASK, OsTaskID);
            }
        }
#endif /* CFG_STD_RESOURCE_MAX > 0 */

#if (CFG_SPINLOCK_MAX > 0U)
        for (spinLockIdx = pTcb->taskCriticalZoneCount; spinLockIdx > 0u; spinLockIdx--)
        {
            if (OBJECT_SPINLOCK == pTcb->taskCriticalZoneType[pTcb->taskCriticalZoneCount - 1u])
            {
                SpinlockId = pTcb->taskCriticalZoneStack[pTcb->taskCriticalZoneCount - 1u];
                (void)ReleaseSpinlock(SpinlockId);
            }
        }
#endif

        /* Reset task_state. */
        pTcb->taskState = TASK_STATE_SUSPENDED;

        /* Remove from ready_queue. */
        Os_ApplReadyQueueRemove(OsTaskID, pTcb->taskRunPrio);

#if (CFG_STD_RESOURCE_MAX > 0U)
        pTcb->taskResCount = 0U;
#endif /* CFG_STD_RESOURCE_MAX > 0 */

#if ((OS_BCC2 == CFG_CC) || (OS_ECC2 == CFG_CC))
        pTcb->taskActCount = 0u;
#endif /* (OS_BCC2 == CFG_CC) || (OS_ECC2 == CFG_CC) */

        pTcb->taskRunPrio = Os_TaskCfg[OsTaskID].osTaskPriority;

#if (CFG_EXTENDED_TASK_MAX > 0U)
        if (OsTaskID < Os_CfgExtendTaskMax)
        {
            Os_ECB[OsTaskID].eventSetEvent = 0U;
            Os_ECB[OsTaskID].eventWaitEvent = 0U;
        }
#endif /* CFG_EXTENDED_TASK_MAX > 0U */

        Os_SCB.sysHighPrio = Os_GetHighPrio();
        Os_SCB.sysHighTaskID = Os_ReadyQueueGetFirst(Os_SCB.sysHighPrio);

/* Timing protection. */
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)

        /* Task_exe budget. */
        Os_TmProtTaskEnd(OsTaskID, TP_TASK_EXE);

        /* Task isr_timing_protection process. */
        pTcb->taskIsrOpt = TP_OPT_BUTT;

        if (pTcb->taskDisableAllCount > 0u)
        {
            Os_TmProtTaskEnd(OsTaskID, TP_TASK_DIS_ALL_INT);

            pTcb->taskDisableAllCount = 0u;
            Os_ArchEnableAllInt_ButTimingProtInt();
        }

        if (pTcb->taskSuspendAllCount > 0u)
        {
            Os_TmProtTaskEnd(OsTaskID, TP_TASK_SUS_ALL_INT);

            Os_SuspendAllCount -= pTcb->taskSuspendAllCount;
            if (0u == Os_SuspendAllCount)
            {
                Os_ArchEnableAllInt_ButTimingProtInt();
            }
        }

        if (pTcb->taskSuspendOSCount > 0u)
        {
            Os_TmProtTaskEnd(OsTaskID, TP_TASK_SUS_OS_INT);

            Os_SuspendOsCount -= pTcb->taskSuspendOSCount;
            if (0u == Os_SuspendOsCount)
            {
                Os_ArchSetIpl(Os_SaveOsIntNested, OS_ISR_ENABLE);
            }
        }

#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */
    }

    return osRet;
}

#if ((OS_BCC2 == CFG_CC) || (OS_ECC2 == CFG_CC))
/******************************************************************************/
/*
 * Brief                <Remove task_node from ready_queue, scene_1.>
 * ServiceId           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Yes>
 * Param-Name[in]      <OsTaskID>
 *                     <OsQueueSize>
 *                     <pOsReadyQueueMark>
 *                     <pOsReadyQueue>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return              <None>
 * PreCondition         <None>
 * CallByAPI            <Os_ApplReadyQueueRemove>
 * REQ ID               <DD_1_0910, DD_1_0911>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_ApplReadyQueRmvS1(
    Os_TaskType OsTaskID,
    uint32 OsQueueSize,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(Os_ReadyQueueType, AUTOMATIC, OS_VAR) pOsReadyQueueMark,
    P2VAR(Os_TaskType, AUTOMATIC, OS_VAR) pOsReadyQueue
    /* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
)
{
    uint32 i;
    uint32 j;
    uint32 OsTemp;
    uint32 OsQueueHead;
    uint32 OsQueueTail;
    uint32 OsQueueLoopEnd;

    OsQueueHead = pOsReadyQueueMark->queueHead;
    OsQueueTail = pOsReadyQueueMark->queueTail;

    OsQueueLoopEnd = OsQueueSize + OsQueueTail;

    /* Loop each node of queue, find target task and remove this node. */
    for (i = OsQueueHead; i < OsQueueLoopEnd; i++)
    {
        OsTemp = i % OsQueueSize;

        if (OsTaskID == pOsReadyQueue[OsTemp])
        {
            /* Shift to left. */
            for (j = i; j < OsQueueLoopEnd; j++)
            {
                pOsReadyQueue[j % OsQueueSize] = pOsReadyQueue[(j + 1u) % OsQueueSize];
            }

            if (0u == OsQueueTail)
            {
                pOsReadyQueueMark->queueTail = OsQueueSize - 1u;
            }
            else
            {
                (pOsReadyQueueMark->queueTail)--;
            }

            OsQueueTail = pOsReadyQueueMark->queueTail;

            pOsReadyQueue[OsQueueTail] = OS_TASK_INVALID;
            OsQueueLoopEnd--;
        }
    }

    return;
}

/******************************************************************************/
/*
 * Brief                <Remove task_node from ready_queue, scene_2.>
 * ServiceId           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Yes>
 * Param-Name[in]      <OsTaskID>
 *                     <OsQueueSize>
 *                     <pOsReadyQueueMark>
 *                     <pOsReadyQueue>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return              <None>
 * PreCondition         <None>
 * CallByAPI            <Os_ApplReadyQueueRemove>
 * REQ ID               <DD_1_0912, DD_1_0913>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_ApplReadyQueRmvS2(
    Os_TaskType OsTaskID,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(Os_ReadyQueueType, AUTOMATIC, OS_VAR) pOsReadyQueueMark,
    P2VAR(Os_TaskType, AUTOMATIC, OS_VAR) pOsReadyQueue
    /* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
)
{
    uint32 i;
    uint32 j;
    uint32 OsQueueHead;
    uint32 OsQueueTail;

    OsQueueHead = pOsReadyQueueMark->queueHead;
    OsQueueTail = pOsReadyQueueMark->queueTail;

    /* Loop each node of queue, find target task and remove this node. */
    for (i = OsQueueHead; i < OsQueueTail; i++)
    {
        if (OsTaskID == pOsReadyQueue[i])
        {
            /* Shift to left. */
            for (j = i; j < (OsQueueTail - 1u); j++)
            {
                pOsReadyQueue[j] = pOsReadyQueue[j + 1u];
            }

            /* queueTail can not be 0. */
            (pOsReadyQueueMark->queueTail)--;

            OsQueueTail = pOsReadyQueueMark->queueTail;

            pOsReadyQueue[OsQueueTail] = OS_TASK_INVALID;
        }
    }

    return;
}

/******************************************************************************/
/*
 * Brief                <Remove task_node from ready_queue, scene_3.>
 * ServiceId           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Yes>
 * Param-Name[in]      <OsTaskID>
 *                     <OsQueueSize>
 *                     <pOsReadyQueueMark>
 *                     <pOsReadyQueue>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return              <None>
 * PreCondition         <None>
 * CallByAPI            <Os_ApplReadyQueueRemove>
 * REQ ID               <DD_1_0914, DD_1_0915>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_ApplReadyQueRmvS3(
    Os_TaskType OsTaskID,
    uint32 OsQueueSize,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(Os_ReadyQueueType, AUTOMATIC, OS_VAR) pOsReadyQueueMark,
    P2VAR(Os_TaskType, AUTOMATIC, OS_VAR) pOsReadyQueue
    /* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
)
{
    uint32 i;
    uint32 j;
    uint32 OsFindNum = 0u;
    uint32 OsQueueHead;
    uint32 OsQueueLoopEnd;

    OsQueueHead = pOsReadyQueueMark->queueHead;

    /* Queue just has one node. */
    if (1u == OsQueueSize)
    {
        pOsReadyQueue[OsQueueHead] = OS_TASK_INVALID;
    }
    else
    {
        OsQueueLoopEnd = OsQueueSize;

        /* Loop each node of queue, find target task and remove this node. */
        for (i = OsQueueHead; i < OsQueueLoopEnd; i++)
        {
            if (OsTaskID == pOsReadyQueue[i])
            {
                /* Shift to left. */
                for (j = i; j < (OsQueueLoopEnd - 1u); j++)
                {
                    pOsReadyQueue[j] = pOsReadyQueue[j + 1u];
                }

                OsFindNum++;
                OsQueueLoopEnd--;
                pOsReadyQueue[OsQueueLoopEnd] = OS_TASK_INVALID;
            }
        }

        /* Update queueTail. */
        pOsReadyQueueMark->queueTail = OsQueueSize - OsFindNum;
    }

    return;
}

/******************************************************************************/
/*
 * Brief                <Get scene of removing task_node from ready_queue.>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Yes>
 * Param-Name[in]       <OsQueueHead>
 *                      <OsQueueTail>
 *                      <pOsReadyQueue>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <Os_ApplRmvQueSceType>
 * PreCondition         <None>
 * CallByAPI            <Os_ApplReadyQueueRemove>
 * REQ ID               <DD_1_0916, DD_1_0917>
 */
/******************************************************************************/
static FUNC(Os_ApplRmvQueSceType, OS_CODE) Os_ApplGetReadyQueRmvSec(
    uint32 OsQueueHead,
    uint32 OsQueueTail,
    P2CONST(Os_TaskType, AUTOMATIC, OS_VAR) pOsReadyQueue)
{
    Os_ApplRmvQueSceType OsRet = APPL_RMV_QUEUE_BUTT;

    if (OsQueueHead > OsQueueTail)
    {
        /* Scene_1: queueTail is more then one loop. */
        OsRet = APPL_RMV_QUEUE_S1;
    }
    else if (OsQueueHead < OsQueueTail)
    {
        /* Scene_2: normal scene. */
        OsRet = APPL_RMV_QUEUE_S2;
    }
    else
    {
        /* Scene_3: queue is full. */
        if (OS_TASK_INVALID != pOsReadyQueue[OsQueueHead])
        {
            OsRet = APPL_RMV_QUEUE_S3;
        }
    }

    return OsRet;
}
#endif /*(OS_BCC2 == CFG_CC) || (OS_ECC2 == CFG_CC)*/
/******************************************************************************/
/*
 * Brief                <Removing task_node from ready_queue in TerminateApplication.>
 * ServiceId           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Yes>
 * Param-Name[in]      <OsTaskID>
 *                     <OsQueuePriority>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return              <None>
 * PreCondition         <None>
 * CallByAPI            <Os_ApplTerminateOneTask>
 * REQ ID               <DD_1_0918, DD_1_0919>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_ApplReadyQueueRemove(Os_TaskType OsTaskID, Os_PriorityType OsQueuePriority)
{
#if ((OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC))
    Os_ReadyTable[OsQueuePriority] = OS_TASK_INVALID;
    Os_ReadyMap[Os_PrioGroup[OsQueuePriority]] &= ~Os_PrioMask[OsQueuePriority];
#else

    Os_ApplRmvQueSceType OsRmvQueSce;
    uint32 OsQueueHead;
    uint32 OsQueueTail;
    uint32 OsQueueSize;
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(Os_ReadyQueueType, AUTOMATIC, OS_VAR) pOsReadyQueueMark;
    P2VAR(Os_TaskType, AUTOMATIC, OS_VAR) pOsReadyQueue;
    /* PRQA S 3432 -- */ /* MISRA Rule 20.7 */

    pOsReadyQueue = Os_ReadyQueue[OsQueuePriority];
    pOsReadyQueueMark = &Os_ReadyQueueMark[OsQueuePriority];

    /* Remove one node from Os_ReadyQueue and shift to the left. */
    OsQueueHead = pOsReadyQueueMark->queueHead;
    OsQueueTail = pOsReadyQueueMark->queueTail;

    /* Queue is empty. */
    if ((OsQueueHead == OsQueueTail) && (0u != OsQueueHead))
    {
        /*nothing to do*/
    }
    else
    {
        /* Get node end position of ReadyQueue. */
        OsRmvQueSce = Os_ApplGetReadyQueRmvSec(OsQueueHead, OsQueueTail, pOsReadyQueue);
        if (APPL_RMV_QUEUE_BUTT == OsRmvQueSce)
        {
            /*nothing to do*/
        }
        else
        {
            OsQueueSize = Os_ActivateQueueSize[OsQueuePriority];

            /* Remove queue node. */
            switch (OsRmvQueSce)
            {
            case APPL_RMV_QUEUE_S1:
                Os_ApplReadyQueRmvS1(OsTaskID, OsQueueSize, pOsReadyQueueMark, pOsReadyQueue);
                break;
            case APPL_RMV_QUEUE_S2:
                Os_ApplReadyQueRmvS2(OsTaskID, pOsReadyQueueMark, pOsReadyQueue);
                break;
            case APPL_RMV_QUEUE_S3:
                Os_ApplReadyQueRmvS3(OsTaskID, OsQueueSize, pOsReadyQueueMark, pOsReadyQueue);
                break;

            /*add comments to pass QAC.*/
            default:
                /* Nothing to do. */
                break;
            }

            /* Queue is full. */
            if (pOsReadyQueueMark->queueHead == OsQueueSize)
            {
                pOsReadyQueueMark->queueHead = 0u;
            }

            /* Queue for this prio is empty. */
            if (pOsReadyQueueMark->queueHead == pOsReadyQueueMark->queueTail)
            {
                /* Clear prio_has_task bit flag of Os_ReadyMap. */
                Os_ClearPrioReadyMap(OsQueuePriority);
            }
#endif /* (OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC) */
}
}

return;
}

#if (CFG_STD_RESOURCE_MAX > 0)
/******************************************************************************/
/*
 * Brief                <task or ISR terminate its resource occupied before>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Yes>
 * @param[in]           <ResID>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <Os_AppTerminateIsrKernelProc>
 *                      <Os_ApplTerminateOneTask>
 * REQ ID               <DD_1_0920, DD_1_0921>
 */
/******************************************************************************/
static FUNC(void, OS_CODE)
    Os_ApplReleaseResource(ResourceType ResID, ObjectTypeType Object, Os_AppObjectIDType OsAppObjID)
{
    Os_PriorityType prio;
    StatusType OsReturnErr = E_OK;
    Os_PriorityType savePrioTemp;
    P2VAR(Os_TCBType volatile, AUTOMATIC, OS_VAR) pTcb;
    P2VAR(Os_ICBType volatile, AUTOMATIC, OS_VAR) pIcb;

#if (OS_STATUS_EXTENDED == CFG_STATUS)
    /* No any resource to release */
    if (0U == Os_RCB[ResID].saveCount)
    {
        /*nothing to do*/
    }
    else
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
    {
        prio = Os_ResourceCfg[ResID].ceiling;
        savePrioTemp = Os_RCB[ResID].savePrio;

        switch (Os_ResourceCfg[ResID].resourceOccupyType)
        {
        case OCCUPIED_BY_TASK:
            pTcb = &Os_TCB[OsAppObjID];

            if (Os_TaskCfg[OsAppObjID].osTaskPriority > prio)
            {
                OsReturnErr = E_NOT_OK;
                break;
            }

            if (pTcb->taskResCount > 0u)
            {
                pTcb->taskResCount = pTcb->taskResCount - 1u; /*pTcb->taskResCount--;*/
            }

            if (prio > savePrioTemp)
            {

                Os_ReadyQueueRemove(OS_LEVEL_STANDARD_RESOURCE, Os_TCB[OsAppObjID].taskRunPrio);
                pTcb->taskRunPrio = Os_TaskCfg[OsAppObjID].osTaskPriority;
            }

            break;

        case OCCUPIED_BY_TASK_OR_INTERRUPT:
            pTcb = &Os_TCB[OsAppObjID];

            if (OBJECT_TASK == Object)
            {
                if (pTcb->taskResCount > 0u)
                {
                    pTcb->taskResCount = pTcb->taskResCount - 1u;
                }

                Os_ArchSetIpl(Os_PrioToIpl(savePrioTemp), OS_ISR_ENABLE);
                Os_SCB.sysDispatchLocker = Os_SCB.sysDispatchLocker - 1u;
            }
            else if (OBJECT_ISR == Object)
            {
                pIcb = &Os_ICB[OsAppObjID];

#if (TRUE == CFG_INT_NEST_ENABLE)
                if (prio > savePrioTemp)
                {
                    Os_ArchSetIpl(Os_PrioToIpl(savePrioTemp), OS_ISR_ENABLE);
                }
#endif /* TRUE == CFG_INT_NEST_ENABLE */

/* AutoSar: add ResID to stack. For protection hook. */
#if (CFG_ISR2_MAX > 0)
                if (pIcb->IsrC2ResCount > 0u)
                {
                    pIcb->IsrC2ResCount = pIcb->IsrC2ResCount - 1u;
                }
#endif /* CFG_ISR2_MAX > 0 */
            }
            else
            {
                /*nothing to do*/
            }
            break;

        case OCCUPIED_BY_INTERRUPT:
            pIcb = &Os_ICB[OsAppObjID];

#if (TRUE == CFG_INT_NEST_ENABLE)
            if (prio > savePrioTemp)
            {
                Os_ArchSetIpl(Os_PrioToIpl(savePrioTemp), OS_ISR_ENABLE);
            }
#endif /* TRUE == CFG_INT_NEST_ENABLE */

/* AutoSar: add ResID to stack. For protection hook. */
#if (CFG_ISR2_MAX > 0)
            if (pIcb->IsrC2ResCount > 0u)
            {
                pIcb->IsrC2ResCount = pIcb->IsrC2ResCount - 1u;
            }
#endif /* CFG_ISR2_MAX > 0 */

            break;

        /*add comments to pass QAC.*/
        default:
            /* Nothing to do */
            break;
        }

        if ((StatusType)E_OK == OsReturnErr)
        {
/* AutoSar SC2: Timing protection, resource lock. */
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
            Os_TmProtResEnd(ResID);
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */

            Os_RCB[ResID].saveCount = 0u;
            Os_RCB[ResID].savePrio = OS_PRIORITY_INVALID;
        }
    }

    return;
}
#endif /* CFG_STD_RESOURCE_MAX > 0 */

#if (CFG_ALARM_MAX > 0)
/******************************************************************************/
/*
 * Brief                <Terminate the Alarm objects of the calling application>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Yes>
 * Param-Name[in]       <pOsAppAlarmRef: the application specified Alarms ref>
 *                      <OsAppAlarmCnt : the count/size of the pOsAppAlarmRef>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_TerminateObjects>
 * REQ ID               <DD_1_0922, DD_1_0923>
 */
/******************************************************************************/
static FUNC(void, OS_CODE)
    Os_TerminateAlarmObjectHandler(P2CONST(Os_AlarmType, AUTOMATIC, OS_VAR) pOsAppAlarmRef, Os_AlarmType OsAppAlarmCnt)
{
    Os_AlarmType i;
    Os_CallLevelType sysCallLevel;

    /*check the count to be valid */
    if ((0u == OsAppAlarmCnt) || (Os_CfgAlarmMax < OsAppAlarmCnt))
    {
        /*nothing to do*/
    }
    else
    {
        /* in order to pass service protection*/
        sysCallLevel = Os_SCB.sysOsLevel;
        if (OS_LEVEL_ERRORHOOK == Os_SCB.sysOsLevel)
        {
            Os_SCB.sysOsLevel = OS_LEVEL_TASK;
        }
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
        if ((Os_IsrType)2u == Os_SCB.sysIsrNestQueue[Os_IntNestISR2 - 1u])
        {
            if (Os_IntNestISR2 >= (Os_IsrType)2u)
            {
                Os_SCB.sysOsLevel = OS_LEVEL_ISR2;
            }
            else
            {
                Os_SCB.sysOsLevel = OS_LEVEL_TASK;
            }
        }
#endif
        for (i = 0u; i < OsAppAlarmCnt; i++)
        {
            (void)CancelAlarm(pOsAppAlarmRef[i]);
        }
        Os_SCB.sysOsLevel = sysCallLevel;
    }

    return;
}
#endif /* CFG_ALARM_MAX > 0 */

#if (CFG_SCHEDTBL_MAX > 0)
/******************************************************************************/
/*
 * Brief                <Terminate the ScheduleTable objects of the calling application>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Yes>
 * Param-Name[in]       <pOsAppSchTblRef: the application specified scheduleTbls ref>
 *                      <OsAppSchTblCnt : the count/size of the pOsAppSchTblRef>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_TerminateObjects>
 * REQ ID               <DD_1_0924, DD_1_0925>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_TerminateScheduleTblObjectHandler(
    P2CONST(Os_ScheduleTableType, AUTOMATIC, OS_VAR) pOsAppSchTblRef,
    Os_ScheduleTableType OsAppSchTblCnt)
{
    Os_ScheduleTableType i;
    Os_CallLevelType sysCallLevel;

    /*check the count to be valid */
    if ((0u == OsAppSchTblCnt) || (CFG_SCHEDTBL_MAX < OsAppSchTblCnt))
    {
        /*nothing to do*/
    }
    else
    {
        /* in order to pass service protection*/
        sysCallLevel = Os_SCB.sysOsLevel;
        Os_SCB.sysOsLevel = OS_LEVEL_TASK;
        for (i = 0u; i < OsAppSchTblCnt; i++)
        {
            (void)StopScheduleTable(pOsAppSchTblRef[i]);
        }
        Os_SCB.sysOsLevel = sysCallLevel;
    }

    return;
}
#endif /* CFG_SCHEDTBL_MAX > 0 */

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#endif /* #if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC)) */

/*=======[E N D   O F   F I L E]==============================================*/
