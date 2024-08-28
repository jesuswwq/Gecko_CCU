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
**  FILENAME    : Os_Types.h                                                  **
**                                                                            **
**  Created on  :                                                             **
**  Author      : bo.zeng                                                     **
**  Vendor      :                                                             **
**  DESCRIPTION : OS type and macro definition                                **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
#ifndef OS_TYPES_H
#define OS_TYPES_H

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>    <AUTHOR>    <REVISION LOG>
 *  V0.1.0     2013-04-15  yaoxuan.zhang      Initial version.
 *  V0.2.0     2013-06-19  huaming            modified the format of data type and macro definition,
 *                                          and added the information about MISRAC rule.
 *  V0.3.0     2013-06-21  huaming            To be consistent with the OSEK OS protocol,added the
 *                                          definitions of Os_ResourceCfgType,ResourceCB,
 *                                          TaskStateType, TaskStateRefType and so on.
 *  V0.4.0     2013-07-02  yaoxuan.zhang      1. To be consistent with the OSEK OS protocol,added the
 *                                             definitions of EventType,EventMaskType,
 *                                             EventMaskRefType, CounterType,TickType,TickRefType,
 *                                             AlarmType,AlarmRefType,  AlarmBaseRefType;
 *                                          2. Delete the type define of Os_HookCfg struct.
 *  V0.5.0     2013-07-11  huaming            modified the format of data type and macro definition
 *                                          base on rule of i-soft.
 *  V0.6.0     2013-07-22  yaoxuan.zhang      Add OS_SrvParamType struct.
 *  V0.7.0     2013-07-23  yaoxuan.zhang      Modified the code to adapt MISRA C specification.
 *  V0.8.0     2013-07-30  huaming            add the definition of AppModeType.
 *  V0.9.0     2014-11-11  bo.zeng            code refactor.
 *  V0.10.0    2016-01-12  shi.shu            SC3,SC4 new code.
 *  V0.11.0    2019-08-21  shun.li & zhiqiang.huang   Functional safety initial version.
 *  V1.0.0     2019-11-21  shun.li            Functional safety version.
 *  V1.1.0     2020-04-21  shun.li            Add IOC function.
 *  V1.2.0     2021-04-13  shun.li            code review of IOC.
 */
/*============================================================================*/

/*=======[M I S R A C  R U L E  V I O L A T I O N]============================*/
/*  <MESSAGE ID>    <CODE LINE>    <REASON>
 *   Rule 19.4      all the file   Macro defines an unrecognized code-fragment.
 *                                 Macro defines a braced code statement block.
 */
/*============================================================================*/

/*=======[I N C L U D E S]====================================================*/
#include "Os_Marcos.h"
#include "Os_Cfg.h"

/*=======[M A C R O S]========================================================*/

/*=======[T Y P E   D E F I N I T I O N S]====================================*/

/* --------------------system-------------------- */
/* DD_1_1083 */
typedef enum
{
    OSServiceId_ActivateTask = 0,
    OSServiceId_TerminateTask = 1,
    OSServiceId_ChainTask = 2,
    OSServiceId_Schedule = 3,
    OSServiceId_GetTaskID = 4,
    OSServiceId_GetResource = 5,
    OSServiceId_ReleaseResource = 6,
    OSServiceId_SetEvent = 7,
    OSServiceId_ClearEvent = 8,
    OSServiceId_GetEvent = 9,
    OSServiceId_WaitEvent = 10,
    OSServiceId_IncrementCounter = 11,
    OSServiceId_GetCounterValue = 12,
    OSServiceId_GetElapsedValue = 13,
    OSServiceId_GetAlarmBase = 14,
    OSServiceId_GetAlarm = 15,
    OSServiceId_SetRelAlarm = 16,
    OSServiceId_SetAbsAlarm = 17,
    OSServiceId_CancelAlarm = 18,
    OSServiceId_StartOS = 19,
    OSServiceId_ShutdownOS = 20,
    OSServiceId_ErrorHook = 21,
    OSServiceId_PreTaskHook = 22,
    OSServiceId_PostTaskHook = 23,
    OSServiceId_StartupHook = 24,
    OSServiceId_ShutdownHook = 25,
    OSServiceId_GetTaskState = 26,

    /* Add: AutoSar SC2: ServiceId for ScheduleTable. */
    OSServiceId_StartScheduleTableRel = 27,
    OSServiceId_StartScheduleTableAbs = 28,
    OSServiceId_StopScheduleTable = 29,
    OSServiceId_NextScheduleTable = 30,
    OSServiceId_StartScheduleTableSynchronhron = 31,
    OSServiceId_GetScheduleTableStatus = 32,
    OSServiceId_SyncScheduleTable = 33,
    OSServiceId_SetScheduleTableAsync = 34,

    /*Add:*AutoSar SC3 and SC4:ServiceId for OS-App*/
    OSServiceId_GetApplicationID = 35,
    OSServiceId_CheckObjectAccess = 36,
    OSServiceId_CheckObjectOwnership = 37,
    OSServiceId_TerminateApplication = 38,
    OSServiceId_CallTrustedFunction = 39,
    OSServiceId_CheckISRMemoryAccess = 40,
    OSServiceId_CheckTaskMemoryAccess = 41

} Os_ServiceIdType;

/* definition of Os level of call API, add some for service protection in SC3 and SC4 */
/* DD_1_1084 */
typedef enum
{
    OS_LEVEL_MAIN = 0U,
    OS_LEVEL_ERRORHOOK_APP = 1U,
    OS_LEVEL_TASK = 2U,
    OS_LEVEL_ISR1 = 3U,
    OS_LEVEL_ISR2 = 4U,
    OS_LEVEL_ERRORHOOK = 5U,
    OS_LEVEL_PRETASKHOOK = 6U,
    OS_LEVEL_POSTTASKHOOK = 7U,
    OS_LEVEL_STARTUPHOOK = 8U,
    OS_LEVEL_SHUTDOWNHOOK = 9U,
    OS_LEVEL_ALARMCALLBACK = 10U,
    OS_LEVEL_PROTECTIONHOOK = 11U,
    OS_LEVEL_STANDARD_RESOURCE = 12U,
    OS_LEVEL_INTERNAL_RESOURCE = 13U
} Os_CallLevelType;

/* Type definition of the App mode. */
/* DD_1_0117 */
typedef uint16 Os_AppModeType;
/* DD_1_1085 */
typedef Os_AppModeType AppModeType;

/* sched lock */
/* DD_1_1086 */
typedef uint8 Os_LockerType;

/* Stack */

typedef uint16 Os_SizeType;
/* Defines stack data types. */
/* DD_1_0131 */
typedef uint32                Os_StackDataType;
/* Pointer to stack data. */
/* DD_1_0132 */
typedef uint32*               Os_StackPtrType;
/* The structure type of the stack. */
/* DD_1_0133 */
typedef struct
{
    Os_StackPtrType stackTop;
    Os_StackPtrType stackBottom;
} Os_StackType;

/* This data type identifies an object. */
/* DD_1_1088 */
typedef enum
{
    OBJECT_TASK = 0U,
    OBJECT_ISR = 1U,
    OBJECT_ALARM = 2U,
    OBJECT_COUNTER = 3U,
    OBJECT_SCHEDULETABLE = 4U,
    OBJECT_APP_MAX = 5U,

    OBJECT_RESOURCE = 5U,
    OBJECT_SPINLOCK = 6U,
    OBJECT_MAX = 7U /*The Max Value is invalid, just used in coding*/
} Os_ObjectTypeType;
/* DD_1_0036 */
typedef Os_ObjectTypeType ObjectTypeType;

/* The type definition of the core id. */
/* DD_1_0084 */
typedef uint16 Os_CoreIdType;

/* The pointer type definition of the core id. */
/* DD_1_0085 */
typedef Os_CoreIdType* Os_CoreIdRefType;

/* CoreIdType is a scalar that allows identifying a single core.
The CoreIdType shall represent the logical CoreID. */
/* DD_1_0047 */
typedef Os_CoreIdType CoreIdType;
/* DD_1_1089 */
typedef Os_CoreIdType* CoreIdRefType;

/* The type definition of the Application. */
/* DD_1_0118 */
typedef uint16 Os_ApplicationType;

/* This data type identifies the OS-Application. */
/* DD_1_0030 */
typedef Os_ApplicationType ApplicationType;

/* Type definition of OS resources. */
/* DD_1_0088 */
typedef uint16 Os_ResourceType;
/* DD_1_1090 */
typedef Os_ResourceType ResourceType;
/* DD_1_1091 */
typedef struct
{
    uint32 queueHead;
    uint32 queueTail;
} Os_ReadyQueueType;

/* -----------------------------task---------------------- */
/* This enum type identifies Task State. */
/* DD_1_0070 */
typedef enum
{
    TASK_STATE_WAITING = 0U,
    TASK_STATE_READY = 1U,
    TASK_STATE_SUSPENDED = 2U,
    TASK_STATE_RUNNING = 3U,
    /*for distinguish the autostarted task,the first activatedtask and preempted task */
    TASK_STATE_START = 4U
} Os_TaskStateType;
/* DD_1_1092 */
typedef Os_TaskStateType TaskStateType;
/* DD_1_1093 */
typedef Os_TaskStateType* TaskStateRefType;
/* DD_1_1094 */
typedef Os_TaskStateType* Os_TaskStateRefType;
/* DD_1_1095 */
typedef uint16 Os_TaskType;
/* DD_1_1096 */
typedef Os_TaskType* Os_TaskRefType;
/* DD_1_1097 */
typedef Os_TaskType TaskType;
/* DD_1_1098 */
typedef Os_TaskType* TaskRefType;
/* DD_1_1099 */
typedef uint8 Os_TaskScheduleType;
/* DD_1_1100 */
typedef uint16 Os_PriorityType;

/* DD_1_1101 */
typedef P2FUNC(void, OS_APPL_CODE, TaskEntry)(void); /* PRQA S 3432 */ /* MISRA Rule 20.7 */

/* ------------------------Alarm------------------------- */
/* DD_1_1102 */
typedef enum
{
    ALARM_AUTOSTART_ABSOLUTE = 0U,
    ALARM_AUTOSTART_RELATIVE = 1U
} Os_AlarmAutostartTypeType;

/* This type of tick. */
/* DD_1_0078 */
typedef uint32 Os_TickType;
/* DD_1_1103 */
typedef Os_TickType* Os_TickRefType;
/* DD_1_1104 */
typedef Os_TickType TickType;
/* DD_1_1105 */
typedef TickType* TickRefType;
/* DD_1_1106 */
typedef uint16 Os_CounterType;
/* This data type identifies a counter. */
/* DD_1_0043 */
typedef Os_CounterType CounterType;

/* This type of Alarm. */
/* DD_1_0081 */
typedef uint16 Os_AlarmType;
/* DD_1_1107 */
typedef Os_AlarmType* Os_AlarmRefType;
/* DD_1_1108 */
typedef Os_AlarmType AlarmType;
/* DD_1_1109 */
typedef Os_AlarmType* AlarmRefType;
/* DD_1_1110 */
typedef P2FUNC(void, OS_APPL_CODE, Os_AlarmCallbackType)(void); /* PRQA S 3432 */ /* MISRA Rule 20.7 */

/* To unify with conformance testcases */
/* DD_1_1111 */
typedef struct
{
    Os_TickType maxallowedvalue;
    Os_TickType ticksperbase;
    Os_TickType mincycle;
} Os_AlarmBaseType;
/* DD_1_1112 */
typedef Os_AlarmBaseType AlarmBaseType; /*to unify with conformance testcases*/
/* DD_1_1113 */
typedef Os_AlarmBaseType* Os_AlarmBaseRefType;
/* DD_1_1114 */
typedef Os_AlarmBaseType* AlarmBaseRefType;

/* ---------------------------resource----------------------- */
/* Property type definition of resources. */

typedef enum
{
    RES_PRO_INTERNAL = 0U,
    RES_PRO_LINKED = 1U,
    RES_PRO_STANDARD = 2U
} Os_ResourcePropertyType;

/* Definition of resource occupancy type. */
/* DD_1_0090 */
typedef enum
{
    OCCUPIED_BY_TASK = 0,             /*occupied by task*/
    OCCUPIED_BY_INTERRUPT = 1,        /*occupied by interrupt*/
    OCCUPIED_BY_TASK_OR_INTERRUPT = 2 /*occupied by task or interrupt*/
} Os_ResourceOccupyType;

/*Judge whether task or interrupt has the right to occupy a resource*/

typedef uint32 Os_ResourceOccupyMaskType;

typedef uint32 Os_ResourceIdMaskType;

/* ------------------------------Event---------------------------- */
/* This type of event. */
/* DD_1_0071 */
typedef uint32 Os_EventType;
/* DD_1_1117 */
typedef Os_EventType EventType;

/* This type of event mask. */
/* DD_1_0072 */
typedef uint32 Os_EventMaskType;
/* DD_1_1118 */
typedef Os_EventMaskType* Os_EventMaskRefType;
/* DD_1_1119 */
typedef Os_EventMaskType EventMaskType;
/* DD_1_1120 */
typedef EventMaskType* EventMaskRefType;

/* This struct type identifies the Event control block. */
/* DD_1_0073 */
typedef struct
{
    Os_EventMaskType eventSetEvent;
    Os_EventMaskType eventWaitEvent;
} Os_ECBType;

/* -----------------------------Isr------------------------------ */
/* Definition of OS interrupt category. */
/* DD_1_0095 */
typedef enum
{
    OS_ISR_CATEGORY1 = 0U,
    OS_ISR_CATEGORY2 = 1U
} Os_IsrCategoryType;

/* interrupt priority */
/* DD_1_1121 */
typedef uint16 Os_IPLType;
/* DD_1_1122 */
typedef uint16 Os_IsrType;
/* This data type identifies an interrupt service routine (ISR). */
/* DD_1_0039 */
typedef Os_IsrType ISRType;
/* DD_1_1123 */
typedef enum
{
    OS_ISR_ENABLE = 0U,
    OS_ISR_DISABLE = 1U
} Os_IsrDescriptionType;

/*  -----------------------------ScheduleTable----------------------- */
/* This type describes the status of a schedule. The status can be one of the
   following:
1. The schedule table is not started (SCHEDULETABLE_STOPPED)
2. The schedule table will be started after the end of currently running schedule
   table (schedule table was used in NextScheduleTable() service) (SCHEDULETABLE_NEXT)
3. The schedule table uses explicit synchronization, has been started and is
   waiting for the global time. (SCHEDULETABLE_WAITING)
4. The schedule table is running, but is currently not synchronous to a global
   time source (SCHEDULETABLE_RUNNING)
5. The schedule table is running and is synchronous to a global time source
   (SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS) */
/* DD_1_0062 */
typedef enum
{
    SCHEDULETABLE_STOPPED = 0U,
    SCHEDULETABLE_NEXT = 1U,
    SCHEDULETABLE_WAITING = 2U,
    SCHEDULETABLE_RUNNING = 3U,
    SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS = 4U
} Os_SchedTblStateType;
/* DD_1_0041 */
typedef Os_SchedTblStateType ScheduleTableStatusType;
/* This data type points to a variable of the data type ScheduleTableStatusType. */
/* DD_1_0042 */
typedef ScheduleTableStatusType* ScheduleTableStatusRefType;

/* DD_1_1124 */
typedef enum
{
    ST_START_ABSOLUTE = 0U,
    ST_START_RELATIVE = 1U,

#if ((OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC))
    ST_START_SYNCHRON = 2U
#endif /* (OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC) */
} Os_SchedTblAutostartType;
/* DD_1_0062 */
typedef uint16 Os_ScheduleTableType;
/* This data type identifies a schedule table. */
/* DD_1_0040 */
typedef Os_ScheduleTableType ScheduleTableType;

typedef uint16 Os_SchedTblSetEvent;

typedef Os_SchedTblSetEvent* Os_SchedTblSetEventRef;

typedef uint16 Os_SchedTblSetEventTask;

typedef Os_SchedTblSetEventTask* Os_SchedTblSetEventTaskRef;

typedef uint16 Os_SchedTblActivateTask;

typedef Os_SchedTblActivateTask* Os_SchedTblActivateTaskRef;

/* This type of Counter . */
/* DD_1_0077 */
typedef Os_CounterType Os_SchedTblCounterRefType;

/* OsScheduleTableAutostart. AutoSar3.1: AUTOSAR_SWS_OS.pdf: 10.2.23. */
/* This struct type identifies a schedule tableAutostart . */
/* DD_1_0061 */
typedef struct
{
    Os_TickType osSchedTblAbsValue;
    Os_TickType osSchedTblRelOffset;
    Os_SchedTblAutostartType osSchedTblAutostartType;

    /* Note: In AUTOSAR_SWS_OS.pdf 10.2.23, Os_SchedTblAutostart can reference more then one appmode. */
    Os_AppModeType osSchedTblAppModeBitmap;
} Os_SchedTblAutostart;

/* OsScheduleTableSync. AutoSar3.1: AUTOSAR_SWS_OS.pdf: 10.2.28. */
#if ((OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC))
/* Enumeration type of synchronization policy. */
/* DD_1_0026 */
typedef enum
{
    ST_SYNC_EXPLICIT = 0U,
    ST_SYNC_IMPLICIT = 1U,
    ST_SYNC_NONE = 2U
} Os_SchedTblSyncStrategy;

/* Schedule table synchronization type. */
/* DD_1_0029 */
typedef struct
{
    uint16 osSchedTblExplicitPrecision;
    Os_SchedTblSyncStrategy osSchedTblSyncStrategy;
} Os_SchedTblSync;
#endif /* (OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC) */

/* OsScheduleTableEventSetting. AutoSar3.1: AUTOSAR_SWS_OS.pdf: 10.2.24. */
/* This struct type identifies the reference event to set. */
/* DD_1_0067 */
typedef struct
{
    Os_EventType osSchedTblSetEventRef;
    Os_TaskType osSchedTblSetEventTaskRef;
} Os_EPSetEventAction;

/* OsScheduleTableTaskActivation. AutoSar3.1: AUTOSAR_SWS_OS.pdf: 10.2.26. */
/* This struct type identifies the reference task to activate. */
/* DD_1_0066 */
typedef struct
{
    Os_TaskType osSchedTblActivateTaskRef;
} Os_EPActivateTaskAction;

/* OsScheduleTableExpriyPoint. AutoSar3.1: AUTOSAR_SWS_OS.pdf: 10.2.25. */
/* This struct type identifies a schedule tableExpriyPoint . */
/* DD_1_0063 */
typedef struct
{
    Os_TickType osSchedTblEPOffset;
    uint16 osSetEventListSize;
    uint16 osActivateTaskListSize;
    P2CONST(Os_EPSetEventAction, OS_VAR, OS_CONST) osSetEventList;
    P2CONST(Os_EPActivateTaskAction, OS_VAR, OS_CONST) osActivateTaskList;
#if ((OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC))
    Os_TickType osSchedTblMaxAdvance;
    Os_TickType osSchedTblMaxRetard;
#endif /* (OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC) */
} Os_SchedTblEP;

/* -------------------------------Counter--------------------------- */
/* This type of Counter type. */
/* DD_1_0074 */
typedef enum
{
    COUNTER_HARDWARE = 0,
    COUNTER_SOFTWARE = 1
} Os_CounterEnumType;

/* -------------------------timing protection----------------------------*/
/* AutoSar: SC2, timing protection for task. */
#if ((OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC))
/* DD_1_1132 */
typedef enum
{
    TP_SUS_OS_INT = 0U,
    TP_SUS_ALL_INT = 1U,
    TP_DIS_ALL_INT = 2U,

    TP_OPT_BUTT = 3U
} Os_TaskIsrOptType;

/* Add: AutoSar SC2: Time protection operation type definitions. */
/* Task timing protection operation type definition. */
/* DD_1_0141 */
typedef enum
{
    TP_TASK_EXE = 0U,
    TP_TASK_ARRIVAL = 1U,
    TP_TASK_SUS_OS_INT = 2U,
    TP_TASK_SUS_ALL_INT = 3U,
    TP_TASK_DIS_ALL_INT = 4U,

    TP_OPT_TASK_BUTT = 5U /* Attention: used as index of array! */
} Os_TmProtOptTaskType;

/* Interrupt timing protection operation type definition. */
/* DD_1_0142 */
typedef enum
{
    TP_ISR_CAT2_EXE = 0U,
    TP_ISR_CAT2_ARRIVAL = 1U,
    TP_ISR_CAT2_SUS_OS_INT = 2U,
    TP_ISR_CAT2_SUS_ALL_INT = 3U,
    TP_ISR_CAT2_DIS_ALL_INT = 4U,

    TP_OPT_ISR_BUTT = 5U /* Attention: used as index of array! */
} Os_TmProtOptIsrType;

/* Timing protection: who occupy a resource, task or isr. */
/* Type definition of resource occupation. */
/* DD_1_0143 */
typedef enum
{
    TP_RES_OCCUPY_TASK = 0U,
    TP_RES_OCCUPY_ISR = 1U,

    TP_RES_OCCUPY_BUTT = 2U
} Os_TmProtResOccupyType;

/* Define resource for task locking */
/* DD_1_0144 */
typedef struct
{
    Os_TickType OsTaskResLockBudget;
    Os_ResourceType OsTaskResLockResRef;
} Os_TaskResLockType;

/* Task timing protection configuration structure type. */
/* DD_1_0145 */
typedef struct
{
    Os_TickType osTaskAllInterruptLockBudget; /* Float. Cfg tool switch to tick. */
    Os_TickType osTaskExecutionBudget;        /* Float. Cfg tool switch to tick. */
    Os_TickType osTaskOsInterruptLockBudget;  /* Float. Cfg tool switch to tick. */
    Os_TickType osTaskTimeFrame;              /* Float. Cfg tool switch to tick. */
    uint16 osTaskResLockCnt;                  /* Count of Os_TaskResLockType. */
    P2CONST(Os_TaskResLockType, OS_VAR, OS_CONST) osTaskResLockRef;
} Os_TaskTmProtCfgType;

/* OsIsrTimingProtection.  AutoSar3.1: AUTOSAR_SWS_OS.pdf: 10.2.19. */
/* Resources that define interrupt locking. */
/* DD_1_0146 */
typedef struct
{
    Os_TickType osIsrResLockBudget; /* Float. Cfg tool switch to tick count. */
    Os_ResourceType osIsrResLockResRef;
} Os_IsrResLockType;

/* Configuration type of interrupt timing protection configuration. */
/* DD_1_0147 */
typedef struct
{
    Os_TickType osIsrAllIptLockBudget; /* Float. Cfg tool switch to tick count. */
    Os_TickType osIsrExeBudget;        /* Float. Cfg tool switch to tick count. */
    Os_TickType osIsrOsIptLockBudget;  /* Float. Cfg tool switch to tick count. */
    Os_TickType osIsrTimeFrame;        /* Float. Cfg tool switch to tick count. */
    uint16 osIsrResLockCnt;            /* Count of Os_IsrResLockType. */
    P2CONST(Os_IsrResLockType, OS_VAR, OS_CONST) osIsrResLockRef;
} Os_IsrTimingProtectionType;

/* Timing protection control block data definition. */
/* DD_1_0148 */
typedef struct
{
    boolean osIsTpStart;
    uint8 osWhoHook;
    uint8 Rsv[2];

    Os_TickType osTpTime;
    Os_TickType osTpBudget;
} Os_TmProtCbDataDef;
#endif /* (OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC) */
/* -----------------------TrustedFunction-------------------------*/
/* 8.3.2 */
/* Define the base structure of the Os_TrustedFunctionIndex. */
/* DD_1_0136 */
typedef uint16 Os_TrustedFunctionIndexType;

/* This data type identifies a trusted function. */
/* DD_1_0032 */
typedef Os_TrustedFunctionIndexType TrustedFunctionIndexType;

/* 8.3.3  MISRA-C 2004 11.2  */
/* This data type points to a structure which holds the arguments for a call to a trusted function. */
/* DD_1_0033 */
typedef void* TrustedFunctionParameterRefType;

/* Used in Os_AppTrustedFunctionCfgType */
/* DD_1_1148 */
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
typedef P2FUNC(void, OS_APPL_CODE, Os_AppTrustedFunc)(TrustedFunctionIndexType ix, TrustedFunctionParameterRefType ref);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

/* ------------------------application---------------------------- */
/* 8.3.5 */
/* This data type identifies if an OS-Application has access to an object. */
/* DD_1_0035 */
typedef enum
{
    NO_ACCESS = 0U,
    ACCESS = 1U
} ObjectAccessType;

/* 8.3.15 */
/* This data type defines the use of a Restart Task after terminating an OSApplication. */
/* DD_1_0126 */
typedef enum
{
    RESTART = 0U,
    NO_RESTART = 1U
} Os_RestartType;
/* This data type defines the use of a Restart Task after terminating an OS-Application. */
/* DD_1_0045 */
typedef Os_RestartType RestartType;

/* Os_App: Remove task from ready_queue scene define. */
/* Remove task from ready_queue scene define. */
/* DD_1_0127 */
typedef enum
{
    APPL_RMV_QUEUE_S1 = 0U,
    APPL_RMV_QUEUE_S2 = 1U,
    APPL_RMV_QUEUE_S3 = 2U,

    APPL_RMV_QUEUE_BUTT = 3U
} Os_ApplRmvQueSceType;

/* This data type identifies the state of an OS-Application. */
/* DD_1_0125 */
typedef enum
{
    APPLICATION_ACCESSIBLE = 0U,
    APPLICATION_RESTARTING = 1U,
    APPLICATION_TERMINATED = 2U
} Os_ApplicationStateType;

/* The type definition of the pointer to the Application state. */
/* DD_1_0120 */
typedef Os_ApplicationStateType* Os_ApplicationStateRefType;
/*  */
/* DD_1_1133 */
typedef Os_ApplicationStateType ApplicationStateType;

/* This data type points to location where a ApplicationStateType can be stored. */
/* DD_1_0031 */
typedef Os_ApplicationStateType* ApplicationStateRefType;

/* The ID type definition of the Application object. */
/* DD_1_0121 */
typedef uint16 Os_AppObjectIDType;
/* The ID of the Application object. */
/* DD_1_0122 */
typedef uint16 Os_AppObjectId;
/*  */
/* DD_1_1134 */
typedef Os_AppObjectId AppObjectId;

/* OsApp_Hook type define, ref: 8.5 */
/* Type definition of Appl error hook. */
/* DD_1_0098 */
typedef P2FUNC(void, OS_APPL_CODE, Os_ApplErrorHookType)(StatusType Error); /* PRQA S 3432 */ /* MISRA Rule 20.7 */
/* Type definition of Appl shutdown hook. */
/* DD_1_0099 */
typedef P2FUNC(void, OS_APPL_CODE, Os_ApplShutdownHookType)(StatusType Fatalerror);
/* PRQA S 3432 */ /* MISRA Rule 20.7 */
/* Appl Start Hook Type Definition. */
/* DD_1_0100 */
typedef P2FUNC(void, OS_APPL_CODE, Os_ApplStartupHookType)(void); /* PRQA S 3432 */ /* MISRA Rule 20.7 */

/* OsApplicationHooks 10.2.10 */
/* Ref: 8.5 */
/* If not cfg a hook, then the value is NULL_PTR. */
/* From the specfication, the non-trusted_app can not call ShutdownOS,
 * so that, non-trusted_app can not cfg specific-ShutdownHook. */
/* Type definition for Appl hook configuration. */
/* DD_1_0101 */
typedef struct
{
    Os_ApplErrorHookType OsAppErrorHook;
    Os_ApplShutdownHookType OsAppShutdownHook;
    Os_ApplStartupHookType OsAppStartupHook;
} Os_AppHookCfgType;

/* OsApplicationTrustedFunction 10.2.11 */
/* DD_1_1135 */
typedef struct
{
    Os_AppTrustedFunc OsTrustedFunctionName;
} Os_AppTrustedFunctionCfgType;

/* Os-Applications 10.2.9. */
/* The type definition of the Application object. */
/* DD_1_0123 */
typedef uint16 Os_AppObjectType; /*the reference map of the objects of App*/
/* The pointer type definition of the Application object. */
/* DD_1_0124 */
typedef Os_AppObjectType* Os_AppObjectRefType;

/* --------------------------memory protection----------------------------*/
/*  */
/* DD_1_0134 */
typedef enum
{
    /*the checked space is one part of the stack*/
    /*    |    checked space     |   */
    /* |            stack           |*/
    STACK_INCLUDE_CHEKEDSPACE = 0U,

    /*the checked space cross the stack*/
    /* |  checked space    |*/
    /*    |  stack   |      */
    CHEKEDSPACE_INCLUDE_STACK = 1U,

    /*the checked space cross the stack*/
    /*|      checked space  |     */
    /*  |       stack           | */

    /*or*/
    /*|    checked space   |   */
    /*  |    stack            |*/
    STACK_CROSS_CHEKEDSPACE = 2U,

    /* the stack and checked space are not mixed*/
    /*|    checked space     |                        */
    /*                           |       stack       |*/
    STACK_NOTMIXED_CHEKEDSPACE = 3U
} Os_StackAndCheckedSpaceStatus;

/*  */
/* DD_1_0135 */
typedef enum
{
    PRO_IGNORE = 0U,
    PRO_TERMINATETASKISR = 1U,
    PRO_TERMINATEAPPL = 2U,
    PRO_TERMINATEAPPL_RESTART = 3U,
    PRO_SHUTDOWN = 4U
} Os_ProtectionReturnType;
/* This data type identifies a value which controls further actions of the OS on
return from the protection hook. */
/* DD_1_0044 */
typedef Os_ProtectionReturnType ProtectionReturnType;

/* 8.3.4 */
/* DD_1_1136 */
typedef uint16 Os_AccessType;
/* This type holds information how a specific memory region can be accessed. */
/* DD_1_0034 */
typedef Os_AccessType AccessType;

/* 8.3.7 */
/* DD_1_1137 */
typedef uint8* Os_MemoryStartAddressType;
/* This data type is a pointer which is able to point to any location in the MCU address space. */
/* DD_1_0037 */
typedef Os_MemoryStartAddressType MemoryStartAddressType;

/* 8.3.8 */
/* DD_1_1138 */
typedef uint32 Os_MemorySizeType;
/* This data type holds the size (in bytes) of a memory region. */
/* DD_1_0038 */
typedef Os_MemorySizeType MemorySizeType;

/*app address start and end*/
/* DD_1_1139 */
typedef struct
{
    uint8* APP_ADDR_START;
    uint8* APP_ADDR_END;
} OS_APP_ADDR;

/*ISR address start and end*/
/* DD_1_1140 */
typedef struct
{
    uint8* ISR_ADDR_START;
    uint8* ISR_ADDR_END;
} OS_ISR_ADDR;

/*task address start and end*/
/* DD_1_1141 */
typedef struct
{
    uint8* Task_ADDR_START;
    uint8* Task_ADDR_END;
} OS_TASK_ADDR;

/*RoData address start and end*/
/* DD_1_1142 */
typedef struct
{
    uint8* RoData_ADDR_START;
    uint8* RoData_ADDR_END;
} OS_RODATA_ADDR;

/* os_kernel memory map. */
/* DD_1_1143 */
/*os kernel memory protection config*/
/* DD_1_1144 */

typedef struct
{
    uint8* pCPU5DataRamStart; /* address range of ram */
    uint8* pCPU5DataRamEnd;

    uint8* pCPU4DataRamStart; /* address range of ram */
    uint8* pCPU4DataRamEnd;

    uint8* pCPU3DataRamStart; /* address range of ram */
    uint8* pCPU3DataRamEnd;

    uint8* pCPU2DataRamStart; /* address range of ram */
    uint8* pCPU2DataRamEnd;

    uint8* pCPU1DataRamStart; /* address range of ram */
    uint8* pCPU1DataRamEnd;

    uint8* pCPU0DataRamStart; /* address range of ram */
    uint8* pCPU0DataRamEnd;

    uint8* pGlobleRamStart; /* LMU in Tricore */
    uint8* pGlobleRamEnd;

    uint8* pDflashStart; /* DFLASH in Tricore*/
    uint8* pDflashEnd;

    uint8* pLocalDRamStart; /* DMI in Tricore*/
    uint8* pLocalDRamEnd;

    uint8* pPeripheralStart; /* PERIPHERAL in Tricore*/
    uint8* pPeripheralEnd;

    uint8* pRomStart; /* PFLASH in Tricore*/
    uint8* pRomEnd;
} Os_MemProtKnAddr;

/*os kernel memory protection config*/
/* DD_1_1144 */
typedef struct
{
    CONST(Os_MemProtKnAddr, OS_VAR) OsKernelAddr;
} Os_MemProtKnCfgType;

/* --------------------------------others------------------------------*/
/* DD_1_1145 */
typedef struct
{
    Os_TaskType taskId;
    Os_TaskRefType taskRef;
    Os_TaskStateRefType taskState;
    CounterType counterId;
    Os_TickRefType counterValue;
    Os_TickRefType counterElapsedValue;
    Os_AlarmType alarmId;
    Os_AlarmBaseRefType alarmBaseRef;
    Os_TickRefType alarmTickRef;
    Os_TickType alarmTime;
    Os_TickType alarmCycle;
    Os_ResourceType resourceId;
    Os_EventMaskType eventMask;
    Os_EventMaskRefType eventRef;
    ScheduleTableType ScheduleTableId;
    ScheduleTableStatusRefType ScheduleStatus;
    TickType ScheduleTableOffset;
    TickType ScheduleTableStart;
    Os_IsrType ISRID;
    StatusType ShutdownError;
#if (CFG_OSAPPLICATION_MAX > 0U)
    Os_ApplicationType ApplID;
    Os_AppObjectId ObjectID;
    Os_ObjectTypeType ObjectType;
    Os_RestartType RestartOption;
#endif /* CFG_OSAPPLICATION_MAX > 0U */
    Os_MemoryStartAddressType MemStartAddress;
    Os_MemorySizeType MemSize;
} Os_RunTimeSrvPrarmType;

/* ---------------------------------spinlock----------------------------------*/
/* The TryToGetSpinlockType indicates if the spinlock has been occupied or not. */
/* DD_1_0049 */
typedef enum
{
    TRYTOGETSPINLOCK_NOSUCCESS = 0U,
    TRYTOGETSPINLOCK_SUCCESS = 1U,
} TryToGetSpinlockType;

/* Type definition of the spin lock method. */
/* DD_1_0103 */
typedef enum
{
    LOCK_ALL_INTERRUPTS = 0U,
    LOCK_CAT2_INTERRUPTS = 1U,
    LOCK_NOTHING = 2U,
    LOCK_WITH_RES_SCHEDULER = 3U,
} Os_SpinlockMethod;

/* SpinlockIdType identifies a spinlock instance and is used by the API functions:
GetSpinlock, ReleaseSpinlock and TryToGetSpinlock. */
/* DD_1_0048 */
typedef uint16 SpinlockIdType;
/* The type definition of the spin lock id. */
/* DD_1_0104 */
typedef SpinlockIdType Os_SpinlockIdType;
typedef uint32 Os_SpinlockType;
/* The type definition of the spin lock pointer. */
/* DD_1_0105 */
typedef Os_SpinlockType* Os_SpinlockRefType;

/* The type definition of the spin lock control block. */
/* DD_1_0106 */
typedef struct
{
    boolean occupied;
    Os_ObjectTypeType objOccupyType;
    uint16 objOccupyId;
} Os_SLCBType; /*Spinlock contronl block*/

/* The type definition of the spin lock config. */
/* DD_1_0107 */
typedef struct
{
    Os_SpinlockMethod osSpinlockMethod;
} Os_SpinlockCfgType;

/* ----------------------------------multi-core----------------------------- */
/* This data type identifies the idle mode behavior. */
/* DD_1_0086 */
typedef enum
{
    OS_IDLE_NO_HALT = 0U,
    OS_RUN = 1U,
    OS_CORE_STATUS_INVALID = 2U
} Os_IdleModeType;

/* This data type identifies the idle mode behavior. */
/* DD_1_0050 */
typedef Os_IdleModeType IdleModeType;

/* Type definition of the CPU mode. */
/* DD_1_0087 */
typedef enum
{
    OS_CPUMODE_USER0 = 0U,
    OS_CPUMODE_USER1 = 1U,
    OS_CPUMODE_SUPERVISOR = 2U
} Os_CPUModeType;

/* Define the base structure of the memorysize */
/* DD_1_0083 */
typedef struct
{
    Os_CoreIdType coreStateActive;
    boolean coreStateSynPoint0[OS_AUTOSAR_CORES];
    boolean coreStateSynPoint1[OS_AUTOSAR_CORES];
    boolean coreStateSynPoint2[OS_AUTOSAR_CORES];
    boolean coreStateSynPoint3[OS_AUTOSAR_CORES];
    Os_AppModeType osAppMode[OS_AUTOSAR_CORES];
    Os_IdleModeType coreStatus[OS_AUTOSAR_CORES];
    Os_SpinlockIdType currentSpinlockOccupyLevel;
} Os_CoreCBType;
/* DD_1_1146 */
typedef struct
{
    StatusType interState;
    Os_ServiceIdType serviceId;
    Os_RunTimeSrvPrarmType interParam;
    StatusType remoteCoreRequest[OS_AUTOSAR_CORES];
} Os_InterCoreType;

/*=======Os configuration struct type definition==============================*/
/* Task configuration structure */
/* This struct type identifies the task configuration . */
/* DD_1_0068 */
typedef struct
{
    TaskEntry osTaskEntry;              /* Task entry */
    uint16 osTaskStackId;               /* Task stack id */
    uint16 osTaskActivation;            /* The maximum number of queued activation
                                           requests for the task*/
    uint16 osTaskPriority;              /* The priority of a task*/
    Os_TaskScheduleType osTaskSchedule; /* Defines the preemptability of the task */
    uint8 osRsv1;
    Os_AppModeType osTaskAutoStartMode; /* This container determines whether the task
                                           is activated during the system start-up
                                           procedure or not for some specific
                                           application modes */
/* AUTOSAR_SWS_OS.pdf 10.2.32: timing protection cfg for task. */
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
    P2CONST(Os_TaskTmProtCfgType, OS_VAR, OS_CONST) osTaskTmProtCfgRef;
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */
} Os_TaskCfgType;

/* Alarm configuration structure */
/* DD_1_1150 */
typedef struct
{
    Os_TickType osAlarmStartTime;
    Os_AlarmAutostartTypeType osAlarmAutostartType;
    Os_TickType osAlarmCycleTime;
    Os_AppModeType osAlarmAppMode;
} Os_AlarmAutostartCfgType;

/* This type of Alarm configuration. */
/* DD_1_0079 */
typedef struct
{
    Os_CounterType osAlarmCounter;
    P2CONST(Os_AlarmAutostartCfgType, OS_VAR, OS_CONST) osAlarmAutostartRef;
    Os_AlarmCallbackType osAlarmCallback;
} Os_AlarmCfgType;

/* Definition of resource configuration type. */
/* DD_1_0093 */
typedef struct
{
    Os_PriorityType ceiling;
    Os_ResourceOccupyType resourceOccupyType;
    uint8 rsv1;
} Os_ResourceCfgType;

/* OsIsr. AutoSar3.1: AUTOSAR_SWS_OS.pdf: 10.2.17. */
/* Type definition of interrupt configuration. */
/* DD_1_0096 */
typedef struct
{
    Os_IsrCategoryType OsIsrCatType;
    boolean OsNestedEnable;
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
    P2CONST(Os_IsrTimingProtectionType, OS_VAR, OS_CONST) OsIsrTimePt;
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */

#if (CFG_OSAPPLICATION_MAX > 0)
    uint32 OsIsrSrc;     /* Isr source register. Used in TerminateApplication. */
    uint32 OsIsrSrcType; /* Isr_src type, CPU0/CPU1/CPU2/DMA. */
#endif                   /* CFG_OSAPPLICATION_MAX > 0 */
} Os_IsrCfgType;

/* OsScheduleTable. AutoSar3.1: AUTOSAR_SWS_OS.pdf: 10.2.22. */
/* This struct type identifies a schedule table config. */
/* DD_1_0064 */
typedef struct
{
    Os_TickType osSchedTblDuration;
    boolean osSchedTblRepeating;
    Os_CounterType osSchedTblCounterRef;
    P2CONST(Os_SchedTblAutostart, OS_VAR, OS_CONST) osSchedTblAutostartRef;
    P2CONST(Os_SchedTblEP, OS_VAR, OS_CONST) osSchedTblEP;
    uint16 osSchedTblEPsize;

#if ((OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC))
    Os_SchedTblSync osSchedTblSync;
#endif /* (OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC) */
} Os_SchedTblCfgType;

/* This type of Counter Configuration . */
/* DD_1_0075 */
typedef struct
{
    Os_TickType osCounterMaxAllowedValue;
    Os_TickType osCounterMinCycle;
    Os_TickType osCounterTicksPerBase;
    Os_CounterEnumType osCounterType;
    /* To check the correctness with the configuration */
    Os_TickType osSecondsPerTick;
} Os_CounterCfgType;
typedef Os_CounterCfgType* Os_CounterCfgRefType;

/*Define the structure of the app attribute configuration of the object*/
/* Define the structure of the app attribute configuration of the object */
/* DD_1_0128 */
typedef struct
{
    ApplicationType hostApp;                              /* owner app of the object */
    ApplicationType accAppRefNodeCnt;                     /* accAppRef array node count */
    P2CONST(ApplicationType, OS_VAR, OS_CONST) accAppRef; /* Access App reference bitmap list */
} Os_ObjectAppCfgType;

/* The structure configuration type definition of the Application. */
/* DD_1_0129 */
typedef struct
{
    CoreIdType OsHostCore; /* owner core of the app */
    boolean OsTrusted;     /* true: trusted; fasle: not trusted (default). */
    /* true: OS-Application runs within a protected environment.
     * false: OS-Application has full write access (default)*/
    boolean OsTrustedAppWithProtection;
    uint16 OsAppTaskCnt;
    uint16 OsAppIsrRefCnt;
    uint16 OsAppAlarmRefCnt;
    uint16 OsAppCounterRefCnt;
    uint16 OsAppScheduleTableCnt;
    uint16 OsAppTrustedFuncCnt; /* Element count of OsAppTrustedFuncRef array */

#if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
    CONST(OS_APP_ADDR, OS_VAR) OsAppAssignedPeripheralAddr;
#endif /* TRUE == CFG_MEMORY_PROTECTION_ENABLE */
    P2CONST(Os_AppObjectRefType, OS_VAR, OS_CONST) OsAppObjectRef;
    CONST(Os_TaskType, OS_VAR) OsRestartTask;
    CONST(Os_AppHookCfgType, OS_VAR) OsApplicationHooks;
    P2CONST(Os_TrustedFunctionIndexType, OS_VAR, OS_CONST) OsAppTrustedFuncRef;
} Os_ApplicationCfgType;

/*=======Os Control Block struct type definitions ==========================================*/
/* Task control block type definitions*/
/* This struct type identifies Task control block type.  */
/* DD_1_0069 */
typedef struct
{
    Os_StackPtrType taskTop;
    Os_StackPtrType taskStackBottom;
    uint16 taskRunPrio;

#if ((OS_BCC2 == CFG_CC) || (OS_ECC2 == CFG_CC))
    uint8 taskActCount;
    uint8 taskSelfActCount;
#endif /* (OS_BCC2 == CFG_CC) || (OS_ECC2 == CFG_CC) */
    Os_TaskStateType taskState;

#if (CFG_STD_RESOURCE_MAX > 0U)
    uint8 taskResCount;
    Os_ResourceType* taskResourceStack; /* AutoSar: for protection hook. */
#endif                                  /* CFG_STD_RESOURCE_MAX > 0U */

#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
    boolean taskTpFrameflag; /* Timing Protection: inter-arrival time. Init as true. */
    Os_TaskIsrOptType taskIsrOpt;
    Os_TmProtCbDataDef osTpTask[TP_OPT_TASK_BUTT];
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */

/* Autosar: for service protection*/
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
    uint8 taskDisableAllCount;
    uint8 taskSuspendAllCount;
    uint8 taskSuspendOSCount;
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */

/*multi-core*/
#if ((CFG_SPINLOCK_MAX > 0U) || (CFG_STD_RESOURCE_MAX > 0U))
    uint16 taskCriticalZoneStack[CFG_CRITICAL_ZONE_MAX];
    uint16 taskCriticalZoneCount;
    Os_ObjectTypeType taskCriticalZoneType[CFG_CRITICAL_ZONE_MAX];
#endif /* (CFG_SPINLOCK_MAX > 0U) && (CFG_STD_RESOURCE_MAX > 0U) */
} Os_TCBType;

/* This type of Alarm control block. */
/* DD_1_0080 */
typedef struct
{
    Os_TickType alarmStart;
    Os_TickType alarmCycle;
    Os_AlarmType alarmPre;
    Os_AlarmType alarmNext;
} Os_ACBType;

/* Type definition of resource control block. */
/* DD_1_0094 */
typedef struct
{
    uint8 saveCount;
    uint8 Rsv0;
    Os_PriorityType savePrio;
    Os_CallLevelType saveLevel;
/* Timing protection: Each resource has Os_TmProtCbDataDef. When it is locked,
   it should be processed by timing protection. */
/* Timing protection: ResourceLockBudget for task and isr. */
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
#if (CFG_TASK_MAX > 0)
    Os_TickType* osTmProtResBgtTask;
#endif /* CFG_TASK_MAX > 0 */

#if (CFG_ISR2_MAX > 0)
    Os_TickType* osTmProtResBgtIsr;
#endif /* CFG_ISR2_MAX > 0 */
    Os_TmProtCbDataDef osResTpData;
    /* Which task lock this resource. */
    Os_IsrType osWhichIsrOccupy;
    Os_TaskType osWhichTaskOccupy;
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */
} Os_RCBType;

#if (CFG_ISR2_MAX > 0)
/* Add: AutoSar SC2: Isr control block type definitions. */
/* Type definition of interrupt control block. */
/* DD_1_0097 */
typedef struct
{
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
    boolean osIsrTpFrameflag;
    Os_TaskIsrOptType IsrC2IsrOpt;
    Os_TmProtCbDataDef osTpIsr[TP_OPT_ISR_BUTT];
#endif /* #if (TRUE == CFG_TIMING_PROTECTION_ENABLE) */

#if (CFG_STD_RESOURCE_MAX > 0U)
    Os_ResourceType IsrC2ResCount;
    Os_ResourceType* IsrC2ResourceStack; /* AutoSar: SC2 protection hook. */
#endif                                   /* CFG_STD_RESOURCE_MAX > 0U */
    uint8 resevred;                      /*Avoid emptiness of the Os_ICBType*/

/* Autosar: for service protection*/
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
    uint8 isrC2DisableAllCount;
    uint8 isrC2SuspendAllCount;
    uint8 isrC2SuspendOSCount;
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */

/*multi-core*/
#if ((CFG_SPINLOCK_MAX > 0U) || (CFG_STD_RESOURCE_MAX > 0U))
    uint16 isr2CriticalZoneStack[CFG_CRITICAL_ZONE_MAX];
    uint16 isr2CriticalZoneCount;
    Os_ObjectTypeType isr2CriticalZoneType[CFG_CRITICAL_ZONE_MAX];
#endif /* (CFG_SPINLOCK_MAX > 0U) && (CFG_STD_RESOURCE_MAX > 0U) */
} Os_ICBType;
#endif /* CFG_ISR2_MAX */

/* Add: AutoSar SC2: Schedule table control block type definitions. */
/* This struct type identifies a schedule tablecontrol block . */
/* DD_1_0065 */
typedef struct tagOs_STCBType
{
    Os_ScheduleTableType stId;
    boolean stIsAdjust; /* stNextEP need adjust or not. */
    /* App call SetScheduleTableAsync, OS should stop Sync. */
    boolean stIsStopAdjust;
    boolean stIsAdjAdd;
    boolean stIsStarted;
    P2CONST(Os_SchedTblEP, AUTOMATIC, OS_VAR) stNextEP;
    Os_SchedTblStateType stState;
    /* Different between driver counter and sync counter. */
    Os_TickType stDiff;
    /* Deviation, might be smaller then stDiff. */
    Os_TickType stDev;
    Os_TickType stDelay;         /* Delay of stNextEP. */
    Os_TickType stAdjDevTotal;   /* Total dev during sync process. */
    Os_TickType stStartAbsTick;
    Os_TickType stNextEpOffset;  /* EP offset after adjust. */
    Os_TickType stNextEpAbsTick; /* EP abs tick after adjust. */
    Os_TickType stFinalDelay;

    Os_ScheduleTableType NextStID;              /* Used for next state. */
    Os_ScheduleTableType PrevStID;              /* Used for next state. */

    struct tagOs_STCBType volatile* stNextNode; /* For ScheduleTable list. */
    struct tagOs_STCBType volatile* stPreNode;  /* For ScheduleTable list. */
    uint16 stEpId;                              /* ID of stNextEP. */
} Os_STCBType;

/* This type of Counter control block . */
/* DD_1_0076 */
typedef struct
{
    Os_TickType counterCurVal;
    Os_TickType counterLastVal;
    Os_AlarmType counterAlmQue;

    /* Add: AutoSar SC2: ScheduleTable list head node index reference to this counter. */
    P2VAR(Os_STCBType volatile, OS_VAR, OS_VAR) counterStListHead;
} Os_CCBType;

/* The control block type definition for the Application. */
/* DD_1_0130 */
typedef struct
{
    ApplicationStateType appState;
} Os_APPCBType;

/* System control block type definitions */
/* DD_1_0102 */
typedef struct
{
    P2VAR(Os_TCBType volatile, AUTOMATIC, OS_VAR) sysRunningTCB;
    Os_LockerType sysDispatchLocker;
    Os_PriorityType sysHighPrio;
    Os_TaskType sysHighTaskID;
    Os_TaskType sysRunningTaskID;
    Os_TaskType sysPrevTaskID;
    Os_AppModeType sysActiveAppMode;
    Os_CallLevelType sysOsLevel;
#if (TRUE == CFG_USEGETSERVICEID)
    Os_ServiceIdType sysOsServiceId;
#endif /* TRUE == CFG_USEGETSERVICEID */
#if (TRUE == CFG_USEPARAMETERACCESS)
    Os_RunTimeSrvPrarmType sysRunTimeSrvPrarm;
#endif /* TRUE == CFG_USEPARAMETERACCESS */

/* Timing protection for isr. */
#if (CFG_ISR2_MAX > 0)
    boolean sysInIsrCat2;
    Os_IsrType sysRunningIsrCat2Id;                                         /* Running isr category 2. */
    P2VAR(Os_IsrType, AUTOMATIC, OS_VAR) sysIsrNestQueue; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
#endif                                                                      /* CFG_ISR2_MAX > 0 */

#if (CFG_OSAPPLICATION_MAX > 0)
    Os_ApplicationType sysRunningAppID; /*the running application ID*/
    ObjectTypeType sysRunningAppObj;    /*the running object from the application*/
#endif                                  /* CFG_OSAPPLICATION_MAX > 0 */

    Os_CoreIdType sysCore;              /*logical CoreID*/
} Os_SCBType;

/* Define IOC data type. */
typedef uint8 Os_IocU8Type;
typedef uint16 Os_IocU16Type;
typedef uint32 Os_IocU32Type;

typedef Os_IocU8Type Os_IocInParaNumType;

typedef Os_IocU8Type Os_IocMemPoolType;
typedef Os_IocMemPoolType* Os_IocMemPoolPtrType;

typedef Os_IocU16Type Os_IocRelPipeNumType;
typedef Os_IocU16Type Os_IocMaskType;
typedef Os_IocU16Type Os_IocAbsIdType;

typedef Os_IocU32Type Os_IocDateType;
typedef Os_IocU32Type Os_IoclistCntType;

/* Rcv mask type in IOC. */
typedef Os_IocU16Type Os_IocRcvMaskType;
/* Snd mask type in IOC. */
typedef Os_IocU16Type Os_IocSndMaskType;

/* Function pointer of call-back in IOC. */
typedef P2FUNC(void, OS_APPL_CODE, Os_IocCallbackType)(void); /* PRQA S 3432 */ /* MISRA Rule 20.7 */
/* Function pointer of notify in IOC. */
typedef P2FUNC(void, OS_APPL_CODE, Os_IocExeNotifyType)(void); /* PRQA S 3432 */ /* MISRA Rule 20.7 */

/* Define the position of OS in pipe.*/
typedef enum
{
    IOC_SND_SIDE_NOS = 0,
    IOC_RCV_SIDE_NOS,
    IOC_NORMAL_COM,

    IOC_COM_INVALID
} Os_IocPipeOsPosType;

/* Define the type of data source in IOC. */
typedef struct
{
    void* IocDataPtr;
    Os_IocDateType IocDataLenth;
} Os_IocDataSourceType;

/* Define the way of the core communication. */
typedef enum
{
    CROSS_CORE_COM = 0,
    INTER_CORE_COM,

    COM_INVALID
} Os_IocCoreComType;

/* The list node of IOC communication. */
typedef struct Os_IocListNode
{
    struct Os_IocListNode* IocNextNode;
} Os_IocListNodeType;

/* Define the type of the message. */
typedef enum
{
    MSG_FORMAT_ONE = 0,
    MSG_FORMAT_TWO,

    MSG_INVALID
} Os_IocMsgFormatType;

/* Type definition of IOC message control block. */
typedef struct
{
    Os_IocMemPoolPtrType IocPtrMemPoolPosition;
    Os_IocDateType IocDataLenth;
    Os_IocListNodeType IocListNodeInfo;
    Os_IocMsgFormatType IocMsgFormat;
} Os_IocMsgCBType;

/* Define the direction of data. */
typedef enum
{
    DIRECTION_INBUFF = 0,
    DIRECTION_OUTBUFF,

    DIRECTION_INVALID
} Os_BuffDataDirectionType;

/* Define transfer type of IOC. */
typedef enum
{
    IOC_SND_SIDE = 0,
    IOC_RCV_SIDE,

    IOC_INVALID
} Os_IocTransferType;

/* Define the semantics type of IOC. */
typedef enum
{
    CAT1_UNQUEUED = 0,
    CAT2_QUEUED,

    CAT_INVALID
} Os_IocSemanticsType;

/* Define the queue com type. */
typedef enum
{
    QUEUED_FIFO = 0,
    QUEUED_LIFO,

    QUEUED_INVALID
} Os_IocQueueComType;

/* Type define of the IOC pipe property */
typedef struct
{
    Os_IocDateType IocDataLength;
#if (TRUE == CFG_IOC_INIT_VALUE) /* PRQA S 3332 */ /* MISRA Rule 20.9 */
    Os_IocDateType IocInitValue;                   /* init value */
#endif
} Os_IocDataPrpeType;

/* Type define of the IOC pipe property */
typedef struct
{
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
    /* The pipe's relational property.*/
    P2CONST(Os_IocRcvMaskType, OS_VAR, OS_CONST) IocRcvMask; /* receive mask */
    P2CONST(Os_IocSndMaskType, OS_VAR, OS_CONST) IocSndMask; /* send mask */
#endif                                                       /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */
    Os_IocCoreComType IocCfgComMark;
    Os_IocDateType IocCfgRelPipeNum;                         /* The number of IOC communication pipe. */
    Os_IocSemanticsType IocCfgSemantics;
    Os_IocQueueComType IocCfgQueueCom;
    Os_IocDateType IocMemPoolSize;
    Os_IocPipeOsPosType IocPipeOsPos;
    Os_IocInParaNumType IocCfgInParaNum;
    /* The sender's relational property.*/
    /* Notifies Function in send side. */
    Os_IocExeNotifyType IocExeNotify;
    /* The receive's relational property.*/
    Os_IocCallbackType IocReceiverPullCB;
    /* The data's relational property.*/
    P2CONST(Os_IocDataPrpeType, OS_VAR, OS_CONST) IocDataPrpeRef;
} Os_IocPipePrpeType;

/* Pointer to the config information of pipe in IOC. */
typedef struct
{
    P2CONST(Os_IocPipePrpeType, OS_VAR, OS_CONST) IocPipeCfgPtr;
} Os_IocPipeCfgType;

/* Define the control block of IOC. */
typedef struct
{
    Os_IocMemPoolPtrType IocMemPoolPtr;
    Os_IocListNodeType IocListHead;
    Os_IoclistCntType IocPipelistCnt;
    Os_IocListNodeType* IocPtrTailNode;
    Os_IocMemPoolPtrType IocMemPoolHeadPtr;
    Os_IocMemPoolPtrType IocMemPoolTailPtr;
    Os_IocDateType IocMemPoolUsage;
    Os_IocCoreComType IocCoreComMark;
    Os_IocSemanticsType IocSemantics;
    Os_IocQueueComType IocQueueCom;
    Os_IocInParaNumType IocInParaNum;
} Os_IocCBType;

/* Define the description information of pipe in IOC. */
typedef struct
{
    /* The number of IOC communication pipe. */
    Os_IocRelPipeNumType Ioc_RelPipeIndex;
    Os_IocCoreComType IocCfgCoreComMark;
} Os_IocIdDescType;

typedef struct
{
    Os_IocMemPoolType* MemPtr;
} Os_IocBuffType;

#endif /* #ifndef OS_TYPES_H */

/*=======[E N D   O F   F I L E]==============================================*/
