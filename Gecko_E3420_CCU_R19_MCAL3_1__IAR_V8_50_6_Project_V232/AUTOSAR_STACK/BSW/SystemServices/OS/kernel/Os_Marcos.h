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
**  FILENAME    : Os_Marcos.h                                                 **
**                                                                            **
**  Created on  :                                                             **
**  Author      : bo.zeng                                                     **
**  Vendor      :                                                             **
**  DESCRIPTION : Os marco definition                                         **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>    <AUTHOR>        <REVISION LOG>
 *  V0.1.0     2015-08-05    bo.zeng       Initial Version.
 *  V0.2.0     2019-08-21    shun.li & zhiqiang.huang   Functional safety initial version.
 *  V1.0.0     2019-11-21    shun.li       Functional safety version.
 */
/*============================================================================*/

#ifndef OS_MARCOS_H
#define OS_MARCOS_H

/*=======[M I S R A C  R U L E  V I O L A T I O N]============================*/
/*  <MESSAGE ID>    <CODE LINE>    <REASON>
 */
/*============================================================================*/

/*=======[I N C L U D E S]====================================================*/

/*=======[M A C R O S]========================================================*/
/* API services error type of STD OSEK */
#define E_OS_ACCESS   49U /* DD_1_0182 */
#define E_OS_CALLEVEL 2U  /* DD_1_0183 */
#define E_OS_ID       3U  /* DD_1_0184 */
#define E_OS_LIMIT    4U  /* DD_1_0185 */
#define E_OS_NOFUNC   5U  /* DD_1_0186 */
#define E_OS_RESOURCE 6U  /* DD_1_0187 */
#define E_OS_STATE    7U  /* DD_1_0188 */
#define E_OS_VALUE    8U  /* DD_1_0189 */

/* API services error type of AUTOSAR, see 7.10 */
#define E_OS_SERVICEID                     9U  /* DD_1_0190 */
#define E_OS_RATE                          10U
#define E_OS_ILLEGAL_ADDRESS               11U /* DD_1_0192 */
#define E_OS_MISSINGEND                    12U /* DD_1_0022 */
#define E_OS_DISABLEDINT                   13U /* DD_1_0193 */
#define E_OS_STACKFAULT                    14U /* DD_1_0194 */
#define E_OS_PROTECTION_MEMORY             15U /* DD_1_0195 */
#define E_OS_PROTECTION_TIME               16U /* DD_1_0196 */
#define E_OS_PROTECTION_LOCKED             17U /* DD_1_0197 */
#define E_OS_PROTECTION_EXCEPTION          18U /* DD_1_0198 */
#define E_OS_PROTECTION_RATE               19U
#define E_OS_PROTECTION_ARRIVAL            20U /* DD_1_0200 */
#define E_OS_CORE                          21U /* DD_1_0201 see SWS_Os_00589*/
#define E_OS_INTERFERENCE_DEADLOCK         22U /* DD_1_0202 multi-core*/
#define E_OS_NESTING_DEADLOCK              23U /* DD_1_0203 */
#define E_OS_SPINLOCK                      24U /* DD_1_0204 */

#define E_OS_Illegal_Opcode                25U /*it's not standard autosar error status*/
#define E_OS_Unimplemented_Opcode          26U /*it's not standard autosar error status*/
#define E_OS_Invalid_Operand               27U /*it's not standard autosar error status*/
#define E_OS_Data_Address_Align            28U /*it's not standard autosar error status*/
#define E_OS_Invalid_Local_Memory          29U /*it's not standard autosar error status*/
#define E_OS_Program_Fetch_Synchronous     30U /*it's not standard autosar error status*/
#define E_OS_Data_Access_Synchronous       31U /*it's not standard autosar error status*/
#define E_OS_Data_Acess_Asynchronous       32U /*it's not standard autosar error status*/
#define E_OS_Coprocessor_Trap_Asynchronous 33U /*it's not standard autosar error status*/
#define E_OS_Program_Memory_Integrity      34U /*it's not standard autosar error status*/
#define E_OS_Data_Memory_Integrity         35U /*it's not standard autosar error status*/
#define E_OS_Temporal_Asynchronous         36U /*it's not standard autosar error status*/
#define E_OS_Arithmetic_Overflow           37U /*it's not standard autosar error status*/
#define E_OS_Sticky_Arithmetic_Overflow    38U /*it's not standard autosar error status*/
#define E_OS_NMI                           39U /*it's not standard autosar error status*/
#define E_OS_Virtual_Address_Fill          40U /*it's not standard autosar error status*/
#define E_OS_Virtual_Address_Protection    41U /*it's not standard autosar error status*/
#define E_OS_Free_Context_List_Depletion   42U /*it's not standard autosar error status*/
#define E_OS_Call_Depth_Overflow           43U /*it's not standard autosar error status*/
#define E_OS_Call_Depth_Underflow          44U /*it's not standard autosar error status*/
#define E_OS_Free_Context_List_Underflow   45U /*it's not standard autosar error status*/
#define E_OS_Call_Stack_Underflow          46U /*it's not standard autosar error status*/
#define E_OS_Context_Type                  47U /*it's not standard autosar error status*/
#define E_OS_Nesting_Error                 48U /*it's not standard autosar error status*/

/* API services error type of IOC */
#define IOC_E_OK        0U
#define IOC_E_NOK       1U
#define IOC_E_LIMIT     130U
#define IOC_E_LOST_DATA 64U
#define IOC_E_NO_DATA   131U

/* Define Scalability Class */
#define OS_NOSC 0x0U /* DD_1_0205, No conformance classes */
#define OS_SC1  0x1U /* DD_1_0206, Define Scalability Class 1 */
#define OS_SC2  0x2U /* DD_1_0206, Define Scalability Class 2 */
#define OS_SC3  0x3U /* DD_1_0206, Define Scalability Class 3 */
#define OS_SC4  0x4U /* DD_1_0206, Define Scalability Class 4 */

/* Defines for all conformance classes */
#define OS_BCC1 0x1U /* DD_1_0207, BCC1 */
#define OS_BCC2 0x2U /* DD_1_0208, BCC2 */
#define OS_ECC1 0x3U /* DD_1_0209, ECC1 */
#define OS_ECC2 0x4U /* DD_1_0210, ECC2 */

/* Define the status of kernel */
#define OS_STATUS_STANDARD 0x00U /* DD_1_0211, Define the status of kernel */
#define OS_STATUS_EXTENDED 0x01U /* DD_1_0212, Define the status of kernel */

/* Define the scheduling strategy of kernel*/
#define OS_PREEMPTIVE_NON   0x0U /* DD_1_0213, no preemption. */
#define OS_PREEMPTIVE_FULL  0x1U /* DD_1_0214, full preemption. */
#define OS_PREEMPTIVE_MIXED 0x2U /* DD_1_0215, mixed preemption. */

/* Define the invalid parameter */
#define OS_OBJECT_INVALID   0xFFFFU                    /* DD_1_0216, invalid OBJECT. */
#define OS_CORE_INVALID     ((Os_CoreIdType)0xFFFFU)   /* DD_1_0217, invalid CORE. */
#define OS_TASK_INVALID     ((Os_TaskType)0xFFFFU)     /* DD_1_0218, invalid TASK. */
#define OS_ALARM_INVALID    ((Os_AlarmType)0xFFU)      /* DD_1_0219, invalid ALARM. */
#define OS_PRIORITY_INVALID ((Os_PriorityType)0xFFFFU) /* DD_1_0220, invalid PRIORITY. */

/* Define the APP modes */
#define OS_NULL_APPMODE ((Os_AppModeType)0x0000U) /* DD_1_0221, no APP modes. */
#define OS_ALL_APPMODE  ((Os_AppModeType)0xFFFFU) /* DD_1_0222, all APP modes. */

/* DD_1_0223, AutoSar: Ivalid ScheduleTable ID. */
#define OS_SCHEDTABLE_INVALID ((Os_ScheduleTableType)0xFFFFU)
/* DD_1_0224, AutoSar 8.4.3: Ivalid ISRID. */
#define OS_ISR_INVALID ((Os_IsrType)0xFFFFU)
/* DD_1_0226, AutoSar: Ivalid Os_TickType. */
#define OS_TICK_INVALID ((Os_TickType)0U)
/* AutoSar: Ivalid Os_CounterType. */
#define OS_COUNTER_INVALID ((Os_CounterType)0xFFFFU)
/* DD_1_0227, AutoSar: Os-Application 8.3.1 */
#define OS_APPLICATION_INVALID ((Os_ApplicationType)0xFFFFU)
#define OS_APPLICATION_VALID   ((Os_ApplicationType)0xFFFEU)
/* DD_1_0228, AutoSar: Ivalid SpinlockIdType. */
#define OS_SPINLOCK_INVALID ((SpinlockIdType)0xFFFFU)
/* For print. */

/* DD_1_0229, Null parameter. */
#define NULL_PARA ((uint32)0xFFFFFFFFU)

/*The task status for external*/
#define SUSPENDED TASK_STATE_SUSPENDED
#define READY     TASK_STATE_READY
#define RUNNING   TASK_STATE_RUNNING
#define WAITING   TASK_STATE_WAITING

/* DD_1_0234, Stack initialization filling parameters. */
#define OS_STACK_FILL_PATTERN 0xCCU

/* DD_1_0235, It doesn't care what hooks are called by. */
#define OS_NO_CARE 0U
/* DD_1_0236, Time-protected hook, called in task. */
#define OS_TMPROT_HOOK_TASK 1U
/* DD_1_0237, Time-protected hook, called in ISR. */
#define OS_TMPROT_HOOK_ISR 2U
/* DD_1_0238, Time-protected hooks are called outside task and ISR. */
#define OS_TMPROT_HOOK_OSAPP 3U

/*Service Protection Level Bit*/
#define OS_LEVEL_BIT_ERRORHOOK_APP  0x0400U /* DD_1_0239, 100 0000 0000*/
#define OS_LEVEL_BIT_TASK           0x0200U /* DD_1_0240, 010 0000 0000*/
#define OS_LEVEL_BIT_ISR1           0x0100U /* DD_1_0241, 001 0000 0000*/
#define OS_LEVEL_BIT_ISR2           0x0080U /* DD_1_0242, 000 1000 0000*/
#define OS_LEVEL_BIT_ERRORHOOK      0x0040U /* DD_1_0243, 000 0100 0000*/
#define OS_LEVEL_BIT_PRETASKHOOK    0x0020U /* DD_1_0244, 000 0010 0000*/
#define OS_LEVEL_BIT_POSTTASKHOOK   0x0010U /* DD_1_0245, 000 0001 0000*/
#define OS_LEVEL_BIT_STARTUPHOOK    0x0008U /* DD_1_0246, 000 0000 1000*/
#define OS_LEVEL_BIT_SHUTDOWNHOOK   0x0004U /* DD_1_0247, 000 0000 0100*/
#define OS_LEVEL_BIT_ALARMCALLBACK  0x0002U /* DD_1_0248, 000 0000 0010*/
#define OS_LEVEL_BIT_PROTECTIONHOOK 0x0001U /* DD_1_0249, 000 0000 0001*/

/*Service calls condtion in context*/
#define OS_CONTEXT_ACTIVATE_TASK                 0x0280U /* DD_1_0250, 010 1000 0000*/
#define OS_CONTEXT_TERMINATE_TASK                0x0200U /* DD_1_0251, 010 0000 0000*/
#define OS_CONTEXT_CHAIN_TASK                    0x0200U /* DD_1_0252, 010 0000 0000*/
#define OS_CONTEXT_SCHEDULE                      0x0200U /* DD_1_0253, 010 0000 0000*/
#define OS_CONTEXT_GET_TASK_ID                   0x06F1U /* DD_1_0254, 110 1111 0001*/
#define OS_CONTEXT_GET_TASK_STATE                0x06F0U /* DD_1_0255, 110 1111 0000*/
#define OS_CONTEXT_DISABLE_ALL_INTERRUPTS        0x07FFU /* DD_1_0256, 111 1111 1111*/
#define OS_CONTEXT_ENABLE_ALL_INTERRUPTS         0x07FFU /* DD_1_0257, 111 1111 1111*/
#define OS_CONTEXT_SUSPEND_ALL_INTERRUPTS        0x07FFU /* DD_1_0258, 111 1111 1111*/
#define OS_CONTEXT_RESUME_ALL_INTERRUPTS         0x07FFU /* DD_1_0259, 111 1111 1111*/
#define OS_CONTEXT_SUSPEND_OS_INTERRUPTS         0x07FFU /* DD_1_0260, 111 1111 1111*/
#define OS_CONTEXT_RESUME_OS_INTERRUPTS          0x07FFU /* DD_1_0261, 111 1111 1111*/
#define OS_CONTEXT_GET_RESOURCE                  0x0280U /* DD_1_0262, 010 1000 0000*/
#define OS_CONTEXT_RELEASE_RESOURCE              0x0280U /* DD_1_0263, 010 1000 0000*/
#define OS_CONTEXT_SET_EVENT                     0x0280U /* DD_1_0264, 010 1000 0000*/
#define OS_CONTEXT_CLEAR_EVENT                   0x0280U /* DD_1_0265, 010 0000 0000*/
#define OS_CONTEXT_GET_EVENT                     0x06F0U /* DD_1_0266, 110 1111 0000*/
#define OS_CONTEXT_WAIT_EVENT                    0x0200U /* DD_1_0267, 010 0000 0000*/
#define OS_CONTEXT_GET_ALARM_BASE                0x06F0U /* DD_1_0268, 110 1111 0000*/
#define OS_CONTEXT_GET_ALARM                     0x06F0U /* DD_1_0269 110 1111 0000*/
#define OS_CONTEXT_SET_REL_ALARM                 0x0280U /* DD_1_0270, 010 1000 0000*/
#define OS_CONTEXT_SET_ABS_ALARM                 0x0280U /* DD_1_0271, 010 1000 0000*/
#define OS_CONTEXT_CANCEL_ALARM                  0x0280U /* DD_1_0272, 010 1000 0000*/
#define OS_CONTEXT_GET_ACTIV_APPLICATION_MODE    0x06FCU /* DD_1_0273, 110 1111 1100*/
#define OS_CONTEXT_START_OS                      0x0000U /* DD_1_0274, 000 0000 0000*/
#define OS_CONTEXT_SHUTDOWN_OS                   0x06C8U /* DD_1_0275, 110 1100 1000*/
#define OS_CONTEXT_GET_APPLICATION_ID            0x06FDU /* DD_1_0276, 110 1111 1101*/
#define OS_CONTEXT_GET_ISR_ID                    0x06C1U /* DD_1_0277, 110 1100 0001*/
#define OS_CONTEXT_CALL_TRUSTED_FUNCTION         0x0280U /* DD_1_0278, 010 1000 0000*/
#define OS_CONTEXT_CHECK_ISR_MEMORY_ACCESS       0x06C1U /* DD_1_0279, 110 1100 0001*/
#define OS_CONTEXT_CHECK_TASK_MEMORY_ACCESS      0x06C1U /* DD_1_0280, 110 1100 0001*/
#define OS_CONTEXT_CHECK_OBJECT_ACCESS           0x06C1U /* DD_1_0281, 110 1100 0001*/
#define OS_CONTEXT_CHECK_OBJECT_OWNERSHIP        0x06C1U /* DD_1_0282, 110 1100 0001*/
#define OS_CONTEXT_START_ST_REL                  0x0280U /* DD_1_0283, 010 1000 0000*/
#define OS_CONTEXT_START_ST_ABS                  0x0280U /* DD_1_0284, 010 1000 0000*/
#define OS_CONTEXT_STOP_SCHEDULE_TABLE           0x0280U /* DD_1_0285, 010 1000 0000*/
#define OS_CONTEXT_NEXT_SCHEDULE_TABLE           0x0280U /* DD_1_0286, 010 1000 0000*/
#define OS_CONTEXT_START_ST_SYN                  0x0280U /* DD_1_0287, 010 1000 0000*/
#define OS_CONTEXT_SYNC_SCHEDULE_TABLE           0x0280U /* DD_1_0288, 010 1000 0000*/
#define OS_CONTEXT_GET_SCHEDULE_TABLE_STATUS     0x0280U /* DD_1_0289, 010 1000 0000*/
#define OS_CONTEXT_SET_SCHEDULE_TABLE_ASYNC      0x0280U /* DD_1_0290, 010 1000 0000*/
#define OS_CONTEXT_INCREMENT_COUNTER             0x0280U /* DD_1_0291, 010 1000 0000*/
#define OS_CONTEXT_GET_COUNTER_VALUE             0x0280U /* DD_1_0292, 110 1000 0000*/
#define OS_CONTEXT_GET_ELAPSED_COUNTER_VALUE     0x0280U /* DD_1_0293, 110 1000 0000*/
#define OS_CONTEXT_TERMINATE_APPLICATION         0x0680U /* DD_1_0294, 110 1000 0000*/
#define OS_CONTEXT_ALLOW_ACCESS                  0x0280U /* DD_1_0295, 110 1000 0000*/
#define OS_CONTEXT_GET_APPLICATION_STATE         0x06FDU /* DD_1_0296, 110 1111 1101*/
#define OS_CONTEXT_CONTROL_IDLE                  0x0280U /* DD_1_0297, 110 1000 0000*/
#define OS_CONTEXT_GET_CURRENT_APPLICATION_ID    0x06FDU /* DD_1_0298, 110 1111 1101*/
#define OS_CONTEXT_GET_NUMBER_OF_ACTIVATED_CORES 0x0280U /* DD_1_0299, 110 1000 0000*/
#define OS_CONTEXT_GET_CORE_ID                   0x07FFU /* DD_1_0300, 111 1111 1111*/
#define OS_CONTEXT_START_CORE                    0x0000U /* DD_1_0301, 000 0000 0000*/
#define OS_CONTEXT_START_NON_AUTOSAR_CORE        0x1000U /* DD_1_0302, 100 0000 0000*/
#define OS_CONTEXT_GET_SPINLOCK                  0x0280U /* DD_1_0303, 110 1000 0000*/
#define OS_CONTEXT_RELEASE_SPINLOCK              0x0280U /* DD_1_0304, 110 1000 0000*/
#define OS_CONTEXT_TRY_TO_GET_SPINLOCK           0x0280U /* DD_1_0305, 110 1000 0000*/
#define OS_CONTEXT_SHUTDOWN_ALLCORES             0x06C8U /* DD_1_0306, 110 1100 1000*/

/*Memory Protection option*/
/* DD_1_0400, Set the specified bit. */
#define BIT_SET(Number, pos) ((Number) | (pos))
/* Clear the specified bit. */
#define BIT_CLEAR(Number, pos) ((Number) & ~(pos))
/* DD_1_0402, Get the status of the specified bit. */
#define BIT_GET(Number, pos) (((Number) & (pos)))

/* operate enable bit in the memory protection register. */
#define READBIT       1U /* DD_1_0307, read enable bit. */
#define WRITEBIT      2U /* DD_1_0308, write enable bit. */
#define EXECUTBIT     4U /* DD_1_0309, execute enable bit. */
#define STACKSPACEBIT 8U /* DD_1_0310, stack space enable bit. */

/* Determine if the memory area is readable. */
#define OSMEMORY_IS_READABLE(Number) BIT_GET(Number, READBIT)
/* DD_1_0404, Determine if the memory area is writable. */
#define OSMEMORY_IS_WRITEABLE(Number) BIT_GET(Number, WRITEBIT)
/* Determine if the memory area is executable. */
#define OSMEMORY_IS_EXECUTABLE(Number) BIT_GET(Number, EXECUTBIT)
/* Determine if the memory area is stack space. */
#define OSMEMORY_IS_STACKSPACE(Number) BIT_GET(Number, STACKSPACEBIT)

/* DD_1_0407, Set the memory area to be readable. */
#define OSMEMORY_SET_READABLE(Number) BIT_SET(Number, READBIT)
/* DD_1_0408, Set the memory area to be writable. */
#define OSMEMORY_SET_WRITEABLE(Number) BIT_SET(Number, WRITEBIT)
/* DD_1_0409, Set the memory area to be executable. */
#define OSMEMORY_SET_EXECUTABLE(Number) BIT_SET(Number, EXECUTBIT)
/* DD_1_0410, Set the memory area to stack space. */
#define OSMEMORY_SET_STACKSPACE(Number) BIT_SET(Number, STACKSPACEBIT)
/* DD_1_0311, Indicates that memory protection is sent out without access. */
#define OSMEMORY_SET_NOACCESS(Number) 0U

/* MultiCore ID */
/* DD_1_0397, Get the core id of the object. */
#define Os_GetObjCoreId(objGlobalId) ((0xF000u & (objGlobalId)) >> 12U)
/* DD_1_0398, Get the local id of the object. */
#define Os_GetObjLocalId(objGlobalId) (0x0FFFu & (objGlobalId))
/* not used */

/*
#define Os_ChangeCoreId(ObjId,coreId)            (Os_GetObjLocalId(ObjId) | (coreId<<12))
*/

/*
 * MISRA-C:2004 Rule 19.13
 * Msg(4:0342) Using the glue operator '##'.
 */
/* Define the MACROS that used to extending*/
/* Build the task name. */
/* PRQA S 0342++ */ /* MISRA Rule 20.10 */
#define TASK(name) void Os_TaskEntry_##name(void)
/* Build an interrupt name. */
#define ISR(name) void name(void)
/* Declare the callback function. */
#define ALARMCALLBACK(name) void name(void)
/* Declare the callback function of alarm. */
#define DeclareAlarmCallback(name) extern void name(void)
/* Declare a task. */
#define DeclareTask(TaskId) extern void Os_TaskEntry_##TaskId(void)
/* PRQA S 0342-- */ /* MISRA Rule 20.10 */
/* Declare an interrupt. */
#define DeclareISR(name) extern void name(void)
#define DeclareAlarm(AlarmId)
#define DeclareEvent(EventId)
#define DeclareResource(ResourceId)
#define DeclareCounter(CounterId)

/*=======[T Y P E   D E F I N I T I O N S]====================================*/

/*=======[E X T E R N A L   D A T A]==========================================*/

/*=======[E X T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/

/*=======[I N T E R N A L   D A T A]==========================================*/

/*=======[I N T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/

#endif /* #ifndef OS_MARCOS_H */

/*=======[E N D   O F   F I L E]==============================================*/
