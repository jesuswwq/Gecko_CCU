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
**  FILENAME    : Os_Internal.h                                               **
**                                                                            **
**  Created on  :                                                             **
**  Author      : yaoxuan.zhang                                               **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>    <AUTHOR>    <REVISION LOG>
 *  V0.1.0       2013-04-15  yaoxuan.zhang       Initial version.
 *  V0.2.0       2013-06-19  huaming             modified the format of data type and macro
 *                                             definition,  and added the information about
 *                                             MISRAC rule.
 *  V0.3.0       2013-07-02  yaoxuan.zhang       Modified error function definition.
 *  V0.4.0       2013-07-09  huaming             modified the format of parameter base on
 *                                             rule of i-soft.
 *  V0.5.0       2013-07-23  yaoxuan.zhang       Modified the code to adapt MISRA C specification.
 *  V0.6.0       2014-11-16  bo.zeng             code refactor.
 *  V0.7.0       2016-12-13  shi.shu            Multi-core Initial version.
 *  V0.8.0       2019-08-21  shun.li & zhiqiang.huang   Functional safety initial version.
 *  V1.0.0       2019-11-21  shun.li            Functional safety version.
 *  V1.0.1       2021-08-19  shun.li            Add suspend and release OS interrupts function of Spinlock module.
 */
/*============================================================================*/
#ifndef OS_INTERNAL_H
#define OS_INTERNAL_H

/*=======[M I S R A C  R U L E  V I O L A T I O N]============================*/
/*  <MESSAGE ID>    <CODE LINE>    <REASON>
 */
/*============================================================================*/

/*=======[I N C L U D E S]====================================================*/
#include "Os_TestMacros.h"
#include "Os_Processor.h"

/*=======[M A C R O S]========================================================*/
#define OS_EnableInterrupts()       Os_ArchEnableInt()        /* DD_1_0388, Enable interrupts. */
#define OS_DisableInterrupts()      Os_ArchDisableInt()       /* DD_1_0389, Disable interrupts. */
#define Os_Dispatch()               Os_ArchDispatch()         /* DD_1_0390, Run the scheduler. */
#define Os_Switch2System()          Os_ArchSwitch2System()    /* DD_1_0391, Switch to the system stack. */
#define Os_InitCPU()                Os_ArchInitCPU()          /* DD_1_0392, Initialize the CPU. */
#define Os_PreSwitch2System()       Os_ArchPreSwitch2System() /* DD_1_0393, Prepare to switch to the system stack. */
#define Os_StartScheduler()         Os_ArchStartScheduler()   /* DD_1_0394, schedule for the first time. */

#define OS_TMPROT_TARGET_ISR_OFFSET (2U)
/* Get the ready table size */
/* DD_1_0396 */
#define READY_MAP_SIZE(CFG_PRIORITY_MAX) (((CFG_PRIORITY_MAX - 1u) >> 4u) + 1u)

/*=======[T Y P E   D E F I N I T I O N S]====================================*/

/*=======[E X T E R N A L   D A T A]==========================================*/
#define OS_START_SEC_VAR_NOINIT_GLOBAL
#include "Os_MemMap.h"
extern Os_InterCoreType volatile Os_InterCore[OS_AUTOSAR_CORES];
extern Os_CoreCBType volatile Os_CoreCB;
extern Os_SpinlockType Os_SpinlockSync;
#define OS_STOP_SEC_VAR_NOINIT_GLOBAL
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_NO_INIT_CORE0_16
#include "Os_MemMap.h"
extern VAR(Os_PriorityType, OS_VAR) Os_ReadyMap_Core0[READY_MAP_SIZE((CFG_PRIORITY_MAX_CORE0))];
#define OS_STOP_SEC_VAR_NO_INIT_CORE0_16
#include "Os_MemMap.h"

#if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
#define OS_START_SEC_VAR_NO_INIT_CORE1_16
#include "Os_MemMap.h"
extern VAR(Os_PriorityType, OS_VAR) Os_ReadyMap_Core1[READY_MAP_SIZE((CFG_PRIORITY_MAX_CORE1))];
#define OS_STOP_SEC_VAR_NO_INIT_CORE1_16
#include "Os_MemMap.h"
#endif /*TRUE == CFG_CORE1_AUTOSAROS_ENABLE*/

#if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
#define OS_START_SEC_VAR_NO_INIT_CORE2_16
#include "Os_MemMap.h"
extern VAR(Os_PriorityType, OS_VAR) Os_ReadyMap_Core2[READY_MAP_SIZE((CFG_PRIORITY_MAX_CORE2))];
#define OS_STOP_SEC_VAR_NO_INIT_CORE2_16
#include "Os_MemMap.h"
#endif /*TRUE == CFG_CORE2_AUTOSAROS_ENABLE*/

#if (TRUE == CFG_CORE3_AUTOSAROS_ENABLE)
#define OS_START_SEC_VAR_NO_INIT_CORE3_16
#include "Os_MemMap.h"
extern VAR(Os_PriorityType, OS_VAR) Os_ReadyMap_Core3[READY_MAP_SIZE((CFG_PRIORITY_MAX_CORE3))];
#define OS_STOP_SEC_VAR_NO_INIT_CORE3_16
#include "Os_MemMap.h"
#endif /*TRUE == CFG_CORE3_AUTOSAROS_ENABLE*/

#if (TRUE == CFG_CORE4_AUTOSAROS_ENABLE)
#define OS_START_SEC_VAR_NO_INIT_CORE4_16
#include "Os_MemMap.h"
extern VAR(Os_PriorityType, OS_VAR) Os_ReadyMap_Core4[READY_MAP_SIZE((CFG_PRIORITY_MAX_CORE4))];
#define OS_STOP_SEC_VAR_NO_INIT_CORE4_16
#include "Os_MemMap.h"
#endif /*TRUE == CFG_CORE4_AUTOSAROS_ENABLE*/

#if (TRUE == CFG_CORE5_AUTOSAROS_ENABLE)
#define OS_START_SEC_VAR_NO_INIT_CORE5_16
#include "Os_MemMap.h"
extern VAR(Os_PriorityType, OS_VAR) Os_ReadyMap_Core5[READY_MAP_SIZE((CFG_PRIORITY_MAX_CORE5))];
#define OS_STOP_SEC_VAR_NO_INIT_CORE5_16
#include "Os_MemMap.h"
#endif /*TRUE == CFG_CORE5_AUTOSAROS_ENABLE*/

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
extern VAR(uint16, OS_VAR) Os_CfgPriorityMax;
extern P2VAR(Os_PriorityType, AUTOMATIC, OS_VAR) Os_ReadyMap; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
#if ((OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC))
extern P2VAR(Os_TaskType, AUTOMATIC, OS_VAR) Os_ReadyTable;
#else
extern P2VAR(Os_ReadyQueueType, AUTOMATIC, OS_VAR) Os_ReadyQueueMark; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
extern P2CONST(uint32, AUTOMATIC, OS_VAR) Os_ActivateQueueSize;
extern P2CONST(Os_TaskRefType, AUTOMATIC, OS_VAR) Os_ReadyQueue;
#endif /* (OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC) */

extern P2CONST(Os_PriorityType, AUTOMATIC, OS_VAR) Os_PrioGroup;
extern P2CONST(Os_PriorityType, AUTOMATIC, OS_VAR) Os_PrioMask;
extern P2CONST(Os_StackType, AUTOMATIC, OS_VAR) Os_SystemStack;

#if (CFG_TASK_MAX > 0U)
extern P2CONST(Os_TaskCfgType, AUTOMATIC, OS_VAR) Os_TaskCfg;
extern P2CONST(Os_StackType, AUTOMATIC, OS_VAR) Os_TaskStack;
extern P2VAR(Os_TCBType volatile, AUTOMATIC, OS_VAR) Os_TCB;
extern VAR(uint16, OS_VAR) OS_TASK_IDLE;
extern VAR(uint16, OS_VAR) Os_CfgTaskMax;
extern VAR(uint16, OS_VAR) Os_CfgExtendTaskMax;
#endif /* #if (CFG_TASK_MAX > 0U) */

#if (CFG_ISR_MAX > 0U)
extern VAR(uint16, OS_VAR) Os_CfgIsrMax;
extern VAR(uint16, OS_VAR) Os_CfgIsr2Max;
extern VAR(Os_IsrType, OS_VAR) Os_IntCfgIsrId;
extern P2VAR(Os_ICBType volatile, AUTOMATIC, OS_VAR) Os_ICB;
extern P2CONST(Os_StackType, AUTOMATIC, OS_VAR) Os_ISR2Stack;
extern P2CONST(Os_IsrCfgType, AUTOMATIC, OS_VAR) Os_IsrCfg;
#endif /* #if (CFG_ISR_MAX > 0U) */

#if (CFG_COUNTER_MAX > 0U)
extern P2CONST(Os_CounterCfgType, AUTOMATIC, OS_VAR) Os_CounterCfg;
extern P2VAR(Os_CCBType volatile, AUTOMATIC, OS_VAR) Os_CCB;
#endif /* CFG_COUNTER_MAX > 0U */

#if (CFG_ALARM_MAX > 0U)
extern VAR(Os_AlarmType, OS_VAR) Os_CfgAlarmMax;
#endif /* CFG_ALARM_MAX > 0U */

#if (CFG_STD_RESOURCE_MAX > 0U)
extern P2CONST(Os_ResourceCfgType, AUTOMATIC, OS_VAR) Os_ResourceCfg;
extern P2VAR(Os_RCBType volatile, AUTOMATIC, OS_VAR) Os_RCB;
extern VAR(uint16, OS_VAR) Os_CfgResourceMax;
#endif /* CFG_STD_RESOURCE_MAX > 0U) */

#if (CFG_INTERNAL_RESOURCE_MAX > 0U)
extern P2CONST(Os_PriorityType, AUTOMATIC, OS_VAR) Os_InterResCeiling;
#endif /* CFG_INTERNAL_RESOURCE_MAX > 0U */

#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
extern P2CONST(Os_ObjectAppCfgType*, AUTOMATIC, OS_VAR) Os_ObjectAppCfg;
extern VAR(ApplicationType, AUTOMATIC) Os_AppSysCfg;
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */

extern VAR(uint8, OS_VAR) Os_IntNestISR1;
extern VAR(uint8, OS_VAR) Os_IntNestISR2;
extern VAR(uint8 volatile, OS_VAR) Os_SuspendAllCount;
extern VAR(uint8 volatile, OS_VAR) Os_SuspendOsCount;
extern VAR(Os_IPLType, OS_VAR) Os_SaveOsIntNested;
/* PRQA S 3332++ */ /* MISRA Rule 20.9 */
#if (CFG_TRUSTED_SYSTEM_SERVICE_MAX > 0U)
extern P2VAR(TrustedFunctionIndexType, AUTOMATIC, OS_VAR) Os_TrustedFuncNestQueue;
/* PRQA S 3432 */ /* MISRA Rule 20.7 */
extern VAR(uint8, OS_VAR) Os_TrustedFuncNest;
#endif            /* CFG_TRUSTED_SYSTEM_SERVICE_MAX > 0U */

#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#if (CFG_STD_RESOURCE_MAX_CORE0 > 0U)
extern Os_ResourceType Os_TCBTaskResourceStackCore0[CFG_TASK_MAX_CORE0][CFG_STD_RESOURCE_MAX_CORE0];
#endif /* CFG_STD_RESOURCE_MAX_CORE0 > 0U */
#if (CFG_STD_RESOURCE_MAX_CORE1 > 0U)
extern Os_ResourceType Os_TCBTaskResourceStackCore1[CFG_TASK_MAX_CORE1][CFG_STD_RESOURCE_MAX_CORE1];
#endif /* CFG_STD_RESOURCE_MAX_CORE1 > 0U */
#if (CFG_STD_RESOURCE_MAX_CORE2 > 0U)
extern Os_ResourceType Os_TCBTaskResourceStackCore2[CFG_TASK_MAX_CORE2][CFG_STD_RESOURCE_MAX_CORE2];
#endif /* CFG_STD_RESOURCE_MAX_CORE2 > 0U */
#if (CFG_STD_RESOURCE_MAX_CORE3 > 0U)
extern Os_ResourceType Os_TCBTaskResourceStackCore3[CFG_TASK_MAX_CORE3][CFG_STD_RESOURCE_MAX_CORE3];
#endif /* CFG_STD_RESOURCE_MAX_CORE3 > 0U */
#if (CFG_STD_RESOURCE_MAX_CORE4 > 0U)
extern Os_ResourceType Os_TCBTaskResourceStackCore4[CFG_TASK_MAX_CORE4][CFG_STD_RESOURCE_MAX_CORE4];
#endif /* CFG_STD_RESOURCE_MAX_CORE4 > 0U */
#if (CFG_STD_RESOURCE_MAX_CORE5 > 0U)
extern Os_ResourceType Os_TCBTaskResourceStackCore5[CFG_TASK_MAX_CORE5][CFG_STD_RESOURCE_MAX_CORE5];
#endif /* CFG_STD_RESOURCE_MAX_CORE5 > 0U */

#if (CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE0 > 0U)
extern VAR(TrustedFunctionIndexType, OS_VAR) Os_TrustedFuncNestQueueCore0[CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE0];
#endif /* CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE0 > 0U */
#if (CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE1 > 0U)
extern VAR(TrustedFunctionIndexType, OS_VAR) Os_TrustedFuncNestQueueCore1[CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE1];
#endif /* CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE1 > 0U */
#if (CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE2 > 0U)
extern VAR(TrustedFunctionIndexType, OS_VAR) Os_TrustedFuncNestQueueCore2[CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE2];
#endif /* CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE2 > 0U */
#if (CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE3 > 0U)
extern VAR(TrustedFunctionIndexType, OS_VAR) Os_TrustedFuncNestQueueCore3[CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE3];
#endif /* CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE3 > 0U */
#if (CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE4 > 0U)
extern VAR(TrustedFunctionIndexType, OS_VAR) Os_TrustedFuncNestQueueCore4[CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE4];
#endif /* CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE4 > 0U */
#if (CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE5 > 0U)
extern VAR(TrustedFunctionIndexType, OS_VAR) Os_TrustedFuncNestQueueCore5[CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE5];
#endif /* CFG_TRUSTED_SYSTEM_SERVICE_MAX_CORE5 > 0U */

#if (CFG_STD_RESOURCE_MAX > 0U)
#if ((TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE0) && (CFG_TASK_MAX_CORE0 > 0U))
extern Os_TickType Os_RCBTmProtResBgtTaskCore0[CFG_STD_RESOURCE_MAX_CORE0][CFG_TASK_MAX_CORE0];
#endif /* (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE0) && (CFG_TASK_MAX_CORE0 > 0U) */
#if ((TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE1) && (CFG_TASK_MAX_CORE1 > 0U))
extern Os_TickType Os_RCBTmProtResBgtTaskCore1[CFG_STD_RESOURCE_MAX_CORE1][CFG_TASK_MAX_CORE1];
#endif /* (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE1) && (CFG_TASK_MAX_CORE1 > 0U) */
#if ((TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE2) && (CFG_TASK_MAX_CORE2 > 0U))
extern Os_TickType Os_RCBTmProtResBgtTaskCore2[CFG_STD_RESOURCE_MAX_CORE2][CFG_TASK_MAX_CORE2];
#endif /* (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE2) && (CFG_TASK_MAX_CORE2 > 0U) */
#if ((TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE3) && (CFG_TASK_MAX_CORE3 > 0U))
extern Os_TickType Os_RCBTmProtResBgtTaskCore3[CFG_STD_RESOURCE_MAX_CORE3][CFG_TASK_MAX_CORE3];
#endif /* (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE3) && (CFG_TASK_MAX_CORE3 > 0U) */
#if ((TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE4) && (CFG_TASK_MAX_CORE4 > 0U))
extern Os_TickType Os_RCBTmProtResBgtTaskCore4[CFG_STD_RESOURCE_MAX_CORE4][CFG_TASK_MAX_CORE4];
#endif /* (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE4) && (CFG_TASK_MAX_CORE4 > 0U) */
#if ((TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE5) && (CFG_TASK_MAX_CORE5 > 0U))
extern Os_TickType Os_RCBTmProtResBgtTaskCore5[CFG_STD_RESOURCE_MAX_CORE5][CFG_TASK_MAX_CORE5];
#endif /* (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE5) && (CFG_TASK_MAX_CORE5 > 0U) */

#if ((TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE0) && (CFG_ISR_MAX_CORE0 > 0U))
extern Os_TickType Os_RCBTmProtResBgtIsrCore0[CFG_STD_RESOURCE_MAX_CORE0][CFG_ISR_MAX_CORE0];
#endif /* (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE0) && (CFG_ISR_MAX_CORE0 > 0U) */
#if ((TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE1) && (CFG_ISR_MAX_CORE1 > 0U))
extern Os_TickType Os_RCBTmProtResBgtIsrCore1[CFG_STD_RESOURCE_MAX_CORE1][CFG_ISR_MAX_CORE1];
#endif /* (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE1) && (CFG_ISR_MAX_CORE1 > 0U) */
#if ((TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE2) && (CFG_ISR_MAX_CORE2 > 0U))
extern Os_TickType Os_RCBTmProtResBgtIsrCore2[CFG_STD_RESOURCE_MAX_CORE2][CFG_ISR_MAX_CORE2];
#endif /* (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE2) && (CFG_ISR_MAX_CORE2 > 0U) */
#if ((TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE3) && (CFG_ISR_MAX_CORE3 > 0U))
extern Os_TickType Os_RCBTmProtResBgtIsrCore3[CFG_STD_RESOURCE_MAX_CORE3][CFG_ISR_MAX_CORE3];
#endif /* (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE3) && (CFG_ISR_MAX_CORE3 > 0U) */
#if ((TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE4) && (CFG_ISR_MAX_CORE4 > 0U))
extern Os_TickType Os_RCBTmProtResBgtIsrCore4[CFG_STD_RESOURCE_MAX_CORE4][CFG_ISR_MAX_CORE4];
#endif /* (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE4) && (CFG_ISR_MAX_CORE4 > 0U) */
#if ((TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE5) && (CFG_ISR_MAX_CORE5 > 0U))
extern Os_TickType Os_RCBTmProtResBgtIsrCore5[CFG_STD_RESOURCE_MAX_CORE5][CFG_ISR_MAX_CORE5];
#endif /* (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE5) && (CFG_ISR_MAX_CORE5 > 0U) */

#endif /* CFG_STD_RESOURCE_MAX > 0U */

#if (CFG_STD_RESOURCE_MAX_CORE0 > 0U)
extern Os_ResourceType Os_ICBIsrC2ResourceStackCore0[CFG_ISR2_MAX_CORE0][CFG_STD_RESOURCE_MAX_CORE0];
#endif /* CFG_STD_RESOURCE_MAX_CORE0 > 0U */
#if (CFG_STD_RESOURCE_MAX_CORE1 > 0U)
extern Os_ResourceType Os_ICBIsrC2ResourceStackCore1[CFG_ISR2_MAX_CORE1][CFG_STD_RESOURCE_MAX_CORE1];
#endif /* CFG_STD_RESOURCE_MAX_CORE1 > 0U */
#if (CFG_STD_RESOURCE_MAX_CORE2 > 0U)
extern Os_ResourceType Os_ICBIsrC2ResourceStackCore2[CFG_ISR2_MAX_CORE2][CFG_STD_RESOURCE_MAX_CORE2];
#endif /* CFG_STD_RESOURCE_MAX_CORE2 > 0U */

/*=======[E X T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/
#define OS_START_SEC_CODE
#include "Os_MemMap.h"

/* OS internal hook handler function */
#if (TRUE == CFG_ERRORHOOK)
extern FUNC(void, OS_CODE) Os_CallErrorHook(StatusType Error);
#endif /* TRUE == CFG_ERRORHOOK */
#if (TRUE == CFG_PRETASKHOOK)
extern FUNC(void, OS_CODE) Os_CallPreTaskHook(void);
#endif /* TRUE == CFG_PRETASKHOOK */
#if (TRUE == CFG_POSTTASKHOOK)
extern FUNC(void, OS_CODE) Os_CallPostTaskHook(void);
#endif /* TRUE == CFG_POSTTASKHOOK */
#if (TRUE == CFG_SHUTDOWNHOOK)
extern FUNC(void, OS_CODE) Os_CallShutdownHook(StatusType Error);
#endif /* TRUE == CFG_SHUTDOWNHOOK */
#if (TRUE == CFG_STARTUPHOOK)
extern FUNC(void, OS_CODE) Os_CallStartupHook(void);
#endif /* TRUE == CFG_STARTUPHOOK */
#if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
extern FUNC(ProtectionReturnType, OS_CODE) Os_CallProtectionHook(StatusType osErrType, uint32 osWhoHook);
#endif /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */
#if (CFG_TASK_MAX_CORE0 > 0U)
extern FUNC(void, OS_CODE) Os_TaskEntry_IdleCore0(void);
#endif /* #if (CFG_TASK_MAX_CORE0 > 0U) */
#if (CFG_TASK_MAX_CORE1 > 0U)
extern FUNC(void, OS_CODE) Os_TaskEntry_IdleCore1(void);
#endif /* #if (CFG_TASK_MAX_CORE1 > 0U) */
#if (CFG_TASK_MAX_CORE2 > 0U)
extern FUNC(void, OS_CODE) Os_TaskEntry_IdleCore2(void);
#endif /* #if (CFG_TASK_MAX_CORE2 > 0U) */
#if (CFG_TASK_MAX_CORE3 > 0U)
extern FUNC(void, OS_CODE) Os_TaskEntry_IdleCore3(void);
#endif /* #if (CFG_TASK_MAX_CORE3 > 0U) */
#if (CFG_TASK_MAX_CORE4 > 0U)
extern FUNC(void, OS_CODE) Os_TaskEntry_IdleCore4(void);
#endif /* #if (CFG_TASK_MAX_CORE4 > 0U) */
#if (CFG_TASK_MAX_CORE5 > 0U)
extern FUNC(void, OS_CODE) Os_TaskEntry_IdleCore5(void);
#endif /* #if (CFG_TASK_MAX_CORE5 > 0U) */

#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
#if (TRUE == CFG_APPL_SHUTDOWNHOOK)
extern FUNC(void, OS_CODE) Os_ApplShutdownHook(StatusType Fatalerror);
#endif /* TRUE == CFG_APPL_SHUTDOWNHOOK */

#if (TRUE == CFG_APPL_STARTUPHOOK)
extern FUNC(void, OS_CODE) Os_ApplStartupHook(void);
#endif /* TRUE == CFG_APPL_STARTUPHOOK */
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC)*/

/* system & other */
extern FUNC(void, OS_CODE) Os_InitTask(void);
extern FUNC(void, OS_CODE) Os_InitResource(void);
extern FUNC(void, OS_CODE) Os_FillStack(Os_StackType stack);
extern FUNC(void, OS_CODE) Os_SwitchTask(void);
extern FUNC(void, OS_CODE) Os_TaskErrBack(void);
extern FUNC(void, OS_CODE) Os_MultiCoreInitProcessor(void);

/* Task priority map. */
extern FUNC(void, OS_CODE) Os_ClearPrioReadyMap(Os_PriorityType OsPrio);
extern FUNC(Os_PriorityType, OS_CODE) Os_GetHighPrio(void);
extern FUNC(void, OS_CODE) Os_ReadyQueueInsert(Os_TaskType object, Os_CallLevelType level, Os_PriorityType prio);
extern FUNC(void, OS_CODE) Os_ReadyQueueRemove(Os_CallLevelType level, Os_PriorityType prio);
extern FUNC(Os_TaskType, OS_CODE) Os_ReadyQueueGetFirst(Os_PriorityType prio);
extern FUNC(Os_IPLType, OS_CODE) Os_PrioToIpl(Os_PriorityType prio);
extern FUNC(Os_PriorityType, OS_CODE) Os_IplToPrio(Os_IPLType ipl);

/* Interrupt */
extern FUNC(void, OS_CODE) Os_InitInterrupt(void);
extern FUNC(void, OS_CODE) Os_EnterISR1(void);
extern FUNC(void, OS_CODE) Os_ExitISR1(void);
extern FUNC(void, OS_CODE) Os_EnterISR2(void);
extern FUNC(void, OS_CODE) Os_ExitISR2(void);

/* Counter */
extern FUNC(void, OS_CODE) Os_InitCounter(void);
extern FUNC(Os_TickType, OS_CODE) Os_CalcAbsTicks(Os_TickType baseTick, Os_TickType offset, Os_CounterType CounterID);
extern FUNC(Os_TickType, OS_CODE) Os_GetDistance(Os_TickType baseTick, Os_TickType destTick, Os_CounterType CounterID);
extern FUNC(StatusType, OS_CODE) Os_IncrementHardCounter(CounterType CounterID);

/* Alarm */
extern FUNC(void, OS_CODE) Os_InitAlarm(void);
extern FUNC(void, OS_CODE) Os_WorkAlarm(Os_CounterType CounterID);

/* Event */
#if (CFG_EXTENDED_TASK_MAX > 0)
extern FUNC(void, OS_CODE) Os_InitEvent(void);
#endif /* CFG_EXTENDED_TASK_MAX > 0 */

/* Resource */
extern FUNC(void, OS_CODE) Os_GetInternalResource(void);
extern FUNC(void, OS_CODE) Os_ReleaseInternalResource(Os_TaskType osTaskId);

/* Timing Protection. */
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
extern FUNC(void, OS_CODE) Os_InitTmProt(void);
extern FUNC(void, OS_CODE) Os_TmProtTaskStart(Os_TaskType osTaskId, Os_TmProtOptTaskType osOptType);
extern FUNC(void, OS_CODE) Os_TmProtTaskEnd(Os_TaskType osTaskId, Os_TmProtOptTaskType osOptType);
extern FUNC(StatusType, OS_CODE) Os_TmProtTaskFrameChk(Os_TaskType osTaskId);

/* Initialize the time protection control block. */
/* DD_1_0395 */
#define Os_TmProtInitCbData(pCbData, budget) \
    (pCbData)->osIsTpStart = FALSE;          \
    (pCbData)->osTpTime = 0u;                \
    (pCbData)->osTpBudget = (budget)

extern FUNC(void, OS_CODE) Os_TmProtMainProc(void);
#if (CFG_STD_RESOURCE_MAX > 0)
extern FUNC(void, OS_CODE) Os_TmProtResStart(ResourceType osResId, Os_TmProtResOccupyType osOccupyType);
extern FUNC(void, OS_CODE) Os_TmProtResEnd(ResourceType osResId);
#endif /* CFG_STD_RESOURCE_MAX > 0 */
#if (CFG_ISR2_MAX > 0)
extern FUNC(void, OS_CODE) Os_TmProtIsrStart(Os_IsrType osIsrId, Os_TmProtOptIsrType osOptType);
extern FUNC(void, OS_CODE) Os_TmProtIsrEnd(Os_IsrType osIsrId, Os_TmProtOptIsrType osOptType);
extern FUNC(StatusType, OS_CODE) Os_TmProtIsrFrameChk(Os_IsrType osIsrId);
#endif /* #if (CFG_ISR2_MAX > 0) */
#endif /* #if (TRUE == CFG_TIMING_PROTECTION_ENABLE) */

/* Schedule table. */
extern FUNC(void, OS_CODE) Os_InitScheduleTable(void);
extern FUNC(void, OS_CODE) Os_WorkSchedTbl(Os_CounterType CounterID);

/* Service protection*/
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
extern FUNC(boolean, OS_CODE) Os_IgnoreService(void);
extern FUNC(boolean, OS_CODE) Os_AddressWritable(P2VAR(uint8, AUTOMATIC, OS_VAR) Address);
/* PRQA S 3432 */ /* MISRA Rule 20.7 */
extern FUNC(boolean, OS_CODE) Os_WrongContext(uint16 AllowedContext);
extern FUNC(void, OS_CODE) Os_TaskEndNoTerminate(void);
extern FUNC(void, OS_CODE) Os_Isr2OccupyIntRes(void);
extern FUNC(boolean, OS_CODE) Os_CheckObjAcs(ObjectTypeType ObjectType, Os_AppObjectId ObjectID);
#endif /* TRUE == CFG_SERVICE_PROTECTION_ENABLE */
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */

/* Memory protection. */
#if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
extern FUNC(void, OS_CODE) Os_InitMemProt(void);
#endif /* TRUE == CFG_MEMORY_PROTECTION_ENABLE */

/* Applicaiton. */
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
extern FUNC(void, OS_CODE) Os_InitApplication(void);
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */

/* Trusted Function. */
#if (CFG_TRUSTED_SYSTEM_SERVICE_MAX > 0U)
extern FUNC(void, OS_CODE) Os_InitTrustedFunction(void);
#endif              /* CFG_TRUSTED_SYSTEM_SERVICE_MAX > 0U */
/* PRQA S 3332-- */ /* MISRA Rule 20.9 */
/* Spinlock. */
extern FUNC(void, OS_CODE) Os_InitSpinlock(void);
extern FUNC(void, OS_CODE) Os_GetSpinlock(Os_SpinlockRefType spinlock);
extern FUNC(void, OS_CODE) Os_ReleaseSpinlock(Os_SpinlockRefType spinlock);

#if (CFG_SPINLOCK_MAX > 0U)
extern FUNC(void, OS_CODE) Os_SpinlockResumeOsIsr(void);
extern FUNC(void, OS_CODE) Os_SpinlockSuspendOsIsr(void);
#endif /* CFG_SPINLOCK_MAX > 0U */

/* MultiCore. */
extern FUNC(CoreIdType, OS_CODE) Os_GetCoreLogID(CoreIdType phyCoreId);
extern FUNC(CoreIdType, OS_CODE) Os_GetCorePhyID(CoreIdType logCoreId);
#if (OS_AUTOSAR_CORES > 1)
extern FUNC(void, OS_CODE) Os_InterCoreOperation(Os_CoreIdType osCoreId);
#endif /* OS_AUTOSAR_CORES > 1 */
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#endif /* #ifndef OS_INTERNAL_H */
/*=======[E N D   O F   F I L E]==============================================*/
