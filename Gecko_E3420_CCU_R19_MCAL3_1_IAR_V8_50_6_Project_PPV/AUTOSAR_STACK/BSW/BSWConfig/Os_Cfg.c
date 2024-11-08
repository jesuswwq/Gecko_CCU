/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Os_Cfg.c>
 *  @brief      <>
 *  
 *  <MCU:E3420>
 *  
 *  @author     <>
 *  @date       <2024-11-06 18:24:50>
 */
/*============================================================================*/

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>      <DATE>     <AUTHOR>      <REVISION LOG>
 *   V1.0.0       20141111     bo.zeng      Initial version
 *   V1.1.0       20160418     shi.shu      Add SC34
 *   V2.0.0       20191121     shun.li      Functional safety version
 *   V2.1.0       20200421     shun.li      Add IOC function
 */
/*============================================================================*/

/*=======[I N C L U D E S]====================================================*/
#include "Os_Cfg.h"
#include "Os_CfgData.h"
#include "Os.h"
#include "Os_Processor.h"
#include "Os_Internal.h"

/*=======[V E R S I O N   I N F O R M A T I O N]===============================*/
#define OS_CFG_C_AR_MAJOR_VERSION     4U
#define OS_CFG_C_AR_MINOR_VERSION     2U
#define OS_CFG_C_AR_PATCH_VERSION     2U
#define OS_CFG_C_SW_MAJOR_VERSION     1U
#define OS_CFG_C_SW_MINOR_VERSION     0U
#define OS_CFG_C_SW_PATCH_VERSION     0U

/*=======[V E R S I O N  C H E C K]===========================================*/
#if (OS_CFG_C_AR_MAJOR_VERSION != OS_CFG_H_AR_MAJOR_VERSION)
    #error "Os_Cfg.c:Mismatch in Specification Major Version"
#endif
#if (OS_CFG_C_AR_MINOR_VERSION != OS_CFG_H_AR_MINOR_VERSION)
    #error "Os_Cfg.c:Mismatch in Specification Minor Version"
#endif
#if (OS_CFG_C_AR_PATCH_VERSION != OS_CFG_H_AR_PATCH_VERSION)
    #error "Os_Cfg.c:Mismatch in Specification Patch Version"
#endif
#if (OS_CFG_C_SW_MAJOR_VERSION != OS_CFG_H_SW_MAJOR_VERSION)
    #error "Os_Cfg.c:Mismatch in Specification Major Version"
#endif
#if (OS_CFG_C_SW_MINOR_VERSION != OS_CFG_H_SW_MINOR_VERSION)
    #error "Os_Cfg.c:Mismatch in Specification Minor Version"
#endif

/*=======[M A C R O S]========================================================*/
#define  OS_STACK_TOP(stack)    ((Os_StackPtrType)((&(stack)[0]) + (sizeof(stack) / sizeof((stack)[0]))))
#define  OS_STACK_BOTTOM(stack) ((Os_StackPtrType)(stack))

/*=======[I N T E R N A L   D A T A]==========================================*/
/* Ready Queue Manager */

#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core0_0[1];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core0_1[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core0_2[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core0_3[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core0_4[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core0_5[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core0_6[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core0_7[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core0_8[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core0_9[2];
VAR(Os_ReadyQueueType, OS_VAR)  Os_ReadyQueueMark_Core0[CFG_PRIORITY_MAX_CORE0];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONSTP2VAR(Os_TaskType, OS_CONST, OS_VAR) Os_ReadyQueue_Core0[CFG_PRIORITY_MAX_CORE0] =
{
    Os_ActivateQueue_Core0_0,
    Os_ActivateQueue_Core0_1,
    Os_ActivateQueue_Core0_2,
    Os_ActivateQueue_Core0_3,
    Os_ActivateQueue_Core0_4,
    Os_ActivateQueue_Core0_5,
    Os_ActivateQueue_Core0_6,
    Os_ActivateQueue_Core0_7,
    Os_ActivateQueue_Core0_8,
    Os_ActivateQueue_Core0_9,
};

CONST(uint32, OS_CONST) Os_ActivateQueueSize_Core0[CFG_PRIORITY_MAX_CORE0] =
{
    1,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core1_0[1];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core1_1[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core1_2[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core1_3[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core1_4[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core1_5[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core1_6[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core1_7[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core1_8[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core1_9[2];
VAR(Os_ReadyQueueType, OS_VAR)  Os_ReadyQueueMark_Core1[CFG_PRIORITY_MAX_CORE1];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONSTP2VAR(Os_TaskType, OS_CONST, OS_VAR) Os_ReadyQueue_Core1[CFG_PRIORITY_MAX_CORE1] =
{
    Os_ActivateQueue_Core1_0,
    Os_ActivateQueue_Core1_1,
    Os_ActivateQueue_Core1_2,
    Os_ActivateQueue_Core1_3,
    Os_ActivateQueue_Core1_4,
    Os_ActivateQueue_Core1_5,
    Os_ActivateQueue_Core1_6,
    Os_ActivateQueue_Core1_7,
    Os_ActivateQueue_Core1_8,
    Os_ActivateQueue_Core1_9,
};

CONST(uint32, OS_CONST) Os_ActivateQueueSize_Core1[CFG_PRIORITY_MAX_CORE1] =
{
    1,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core2_0[1];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core2_1[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core2_2[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core2_3[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core2_4[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core2_5[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core2_6[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core2_7[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core2_8[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core2_9[2];
VAR(Os_ReadyQueueType, OS_VAR)  Os_ReadyQueueMark_Core2[CFG_PRIORITY_MAX_CORE2];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONSTP2VAR(Os_TaskType, OS_CONST, OS_VAR) Os_ReadyQueue_Core2[CFG_PRIORITY_MAX_CORE2] =
{
    Os_ActivateQueue_Core2_0,
    Os_ActivateQueue_Core2_1,
    Os_ActivateQueue_Core2_2,
    Os_ActivateQueue_Core2_3,
    Os_ActivateQueue_Core2_4,
    Os_ActivateQueue_Core2_5,
    Os_ActivateQueue_Core2_6,
    Os_ActivateQueue_Core2_7,
    Os_ActivateQueue_Core2_8,
    Os_ActivateQueue_Core2_9,
};

CONST(uint32, OS_CONST) Os_ActivateQueueSize_Core2[CFG_PRIORITY_MAX_CORE2] =
{
    1,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_PriorityType, OS_CONST) Os_PrioGroupCore0[CFG_PRIORITY_MAX_CORE0] =
{
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
};
CONST(Os_PriorityType, OS_CONST) Os_PrioMaskCore0[CFG_PRIORITY_MAX_CORE0] =
{
    0x0001,
    0x0002,
    0x0004,
    0x0008,
    0x0010,
    0x0020,
    0x0040,
    0x0080,
    0x0100,
    0x0200,
};
CONST(Os_PriorityType, OS_CONST) Os_PrioGroupCore1[CFG_PRIORITY_MAX_CORE1] =
{
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
};
CONST(Os_PriorityType, OS_CONST) Os_PrioMaskCore1[CFG_PRIORITY_MAX_CORE1] =
{
    0x0001,
    0x0002,
    0x0004,
    0x0008,
    0x0010,
    0x0020,
    0x0040,
    0x0080,
    0x0100,
    0x0200,
};
CONST(Os_PriorityType, OS_CONST) Os_PrioGroupCore2[CFG_PRIORITY_MAX_CORE2] =
{
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
};
CONST(Os_PriorityType, OS_CONST) Os_PrioMaskCore2[CFG_PRIORITY_MAX_CORE2] =
{
    0x0001,
    0x0002,
    0x0004,
    0x0008,
    0x0010,
    0x0020,
    0x0040,
    0x0080,
    0x0100,
    0x0200,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

/* ------------------------stack Management---------------------- */
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_SysStack_Core0[1024];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_SysStack_Core1[1024];
#define OS_STOP_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_SysStack_Core2[1024];
#define OS_STOP_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_StackType, OS_CONST) Os_SystemStackCore0 =
{
    OS_STACK_TOP(Os_SysStack_Core0), OS_STACK_BOTTOM(Os_SysStack_Core0)
};
CONST(Os_StackType, OS_CONST) Os_SystemStackCore1 =
{
    OS_STACK_TOP(Os_SysStack_Core1), OS_STACK_BOTTOM(Os_SysStack_Core1)
};
CONST(Os_StackType, OS_CONST) Os_SystemStackCore2 =
{
    OS_STACK_TOP(Os_SysStack_Core2), OS_STACK_BOTTOM(Os_SysStack_Core2)
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask__Core0_100ms_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask__Core0_10ms_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask__Core0_1ms_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask__Core0_1s_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask__Core0_20ms_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask__Core0_2ms_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask__Core0_50ms_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask__Core0_5ms_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask_Core0_Init_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_TaskStack_Idle_Core0[100];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_StackType, OS_CONST) Os_TaskStackCore0[CFG_TASK_MAX_CORE0] =
{
    {OS_STACK_TOP(Os_OsTask__Core0_100ms_Stack), OS_STACK_BOTTOM(Os_OsTask__Core0_100ms_Stack)},
    {OS_STACK_TOP(Os_OsTask__Core0_10ms_Stack), OS_STACK_BOTTOM(Os_OsTask__Core0_10ms_Stack)},
    {OS_STACK_TOP(Os_OsTask__Core0_1ms_Stack), OS_STACK_BOTTOM(Os_OsTask__Core0_1ms_Stack)},
    {OS_STACK_TOP(Os_OsTask__Core0_1s_Stack), OS_STACK_BOTTOM(Os_OsTask__Core0_1s_Stack)},
    {OS_STACK_TOP(Os_OsTask__Core0_20ms_Stack), OS_STACK_BOTTOM(Os_OsTask__Core0_20ms_Stack)},
    {OS_STACK_TOP(Os_OsTask__Core0_2ms_Stack), OS_STACK_BOTTOM(Os_OsTask__Core0_2ms_Stack)},
    {OS_STACK_TOP(Os_OsTask__Core0_50ms_Stack), OS_STACK_BOTTOM(Os_OsTask__Core0_50ms_Stack)},
    {OS_STACK_TOP(Os_OsTask__Core0_5ms_Stack), OS_STACK_BOTTOM(Os_OsTask__Core0_5ms_Stack)},
    {OS_STACK_TOP(Os_OsTask_Core0_Init_Stack), OS_STACK_BOTTOM(Os_OsTask_Core0_Init_Stack)},
    {OS_STACK_TOP(Os_TaskStack_Idle_Core0), OS_STACK_BOTTOM(Os_TaskStack_Idle_Core0)}
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask__Core1_100ms_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask__Core1_10ms_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask__Core1_1ms_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask__Core1_1s_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask__Core1_20ms_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask__Core1_2ms_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask__Core1_50ms_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask__Core1_5ms_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask_Core1_Init_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_TaskStack_Idle_Core1[100];
#define OS_STOP_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_StackType, OS_CONST) Os_TaskStackCore1[CFG_TASK_MAX_CORE1] =
{
    {OS_STACK_TOP(Os_OsTask__Core1_100ms_Stack), OS_STACK_BOTTOM(Os_OsTask__Core1_100ms_Stack)},
    {OS_STACK_TOP(Os_OsTask__Core1_10ms_Stack), OS_STACK_BOTTOM(Os_OsTask__Core1_10ms_Stack)},
    {OS_STACK_TOP(Os_OsTask__Core1_1ms_Stack), OS_STACK_BOTTOM(Os_OsTask__Core1_1ms_Stack)},
    {OS_STACK_TOP(Os_OsTask__Core1_1s_Stack), OS_STACK_BOTTOM(Os_OsTask__Core1_1s_Stack)},
    {OS_STACK_TOP(Os_OsTask__Core1_20ms_Stack), OS_STACK_BOTTOM(Os_OsTask__Core1_20ms_Stack)},
    {OS_STACK_TOP(Os_OsTask__Core1_2ms_Stack), OS_STACK_BOTTOM(Os_OsTask__Core1_2ms_Stack)},
    {OS_STACK_TOP(Os_OsTask__Core1_50ms_Stack), OS_STACK_BOTTOM(Os_OsTask__Core1_50ms_Stack)},
    {OS_STACK_TOP(Os_OsTask__Core1_5ms_Stack), OS_STACK_BOTTOM(Os_OsTask__Core1_5ms_Stack)},
    {OS_STACK_TOP(Os_OsTask_Core1_Init_Stack), OS_STACK_BOTTOM(Os_OsTask_Core1_Init_Stack)},
    {OS_STACK_TOP(Os_TaskStack_Idle_Core1), OS_STACK_BOTTOM(Os_TaskStack_Idle_Core1)}
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask__Core2_100ms_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask__Core2_10ms_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask__Core2_1ms_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask__Core2_1s_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask__Core2_20ms_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask__Core2_2ms_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask__Core2_50ms_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask__Core2_5ms_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask_Core2_Init_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_TaskStack_Idle_Core2[100];
#define OS_STOP_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_StackType, OS_CONST) Os_TaskStackCore2[CFG_TASK_MAX_CORE2] =
{
    {OS_STACK_TOP(Os_OsTask__Core2_100ms_Stack), OS_STACK_BOTTOM(Os_OsTask__Core2_100ms_Stack)},
    {OS_STACK_TOP(Os_OsTask__Core2_10ms_Stack), OS_STACK_BOTTOM(Os_OsTask__Core2_10ms_Stack)},
    {OS_STACK_TOP(Os_OsTask__Core2_1ms_Stack), OS_STACK_BOTTOM(Os_OsTask__Core2_1ms_Stack)},
    {OS_STACK_TOP(Os_OsTask__Core2_1s_Stack), OS_STACK_BOTTOM(Os_OsTask__Core2_1s_Stack)},
    {OS_STACK_TOP(Os_OsTask__Core2_20ms_Stack), OS_STACK_BOTTOM(Os_OsTask__Core2_20ms_Stack)},
    {OS_STACK_TOP(Os_OsTask__Core2_2ms_Stack), OS_STACK_BOTTOM(Os_OsTask__Core2_2ms_Stack)},
    {OS_STACK_TOP(Os_OsTask__Core2_50ms_Stack), OS_STACK_BOTTOM(Os_OsTask__Core2_50ms_Stack)},
    {OS_STACK_TOP(Os_OsTask__Core2_5ms_Stack), OS_STACK_BOTTOM(Os_OsTask__Core2_5ms_Stack)},
    {OS_STACK_TOP(Os_OsTask_Core2_Init_Stack), OS_STACK_BOTTOM(Os_OsTask_Core2_Init_Stack)},
    {OS_STACK_TOP(Os_TaskStack_Idle_Core2), OS_STACK_BOTTOM(Os_TaskStack_Idle_Core2)}
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_SysTimer_Stack_Core0[512];/*system timer*/
static VAR(Os_StackDataType, OS_VAR) Os_REMOTECALL_CORE0_Stack_Core0[512];/*Remote Call Software interrupt*/
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_CANFD3_CANFD_Stack_Core0[256];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_CANFD4_CANFD_Stack_Core0[256];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_CANFD5_CANFD_Stack_Core0[256];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_CANFD6_CANFD_Stack_Core0[256];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_CANFD7_CANFD_Stack_Core0[256];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_CANFD8_CANFD_Stack_Core0[256];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_ETMR2_CHN_B_Stack_Core0[256];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_GPIO_AP_SYNC_DGPIO_Stack_Core0[256];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_SADC1_O_SADC_Stack_Core0[256];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_SADC2_O_SADC_Stack_Core0[256];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_SPI7_SPI_Stack_Core0[256];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_UART3_Stack_Core0[256];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_UART11_Stack_Core0[256];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_UART14_Stack_Core0[256];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_WDT1_WDT_Stack_Core0[256];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_StackType, OS_CONST) Os_ISR2StackCore0[CFG_ISR2_MAX_CORE0] =
{
    {OS_STACK_TOP(Os_SysTimer_Stack_Core0), OS_STACK_BOTTOM(Os_SysTimer_Stack_Core0)},/*system timer*/
    {OS_STACK_TOP(Os_REMOTECALL_CORE0_Stack_Core0), OS_STACK_BOTTOM(Os_REMOTECALL_CORE0_Stack_Core0)},/*Remote Call Software interrupt*/
    {OS_STACK_TOP(Os_CANFD3_CANFD_Stack_Core0), OS_STACK_BOTTOM(Os_CANFD3_CANFD_Stack_Core0)},
    {OS_STACK_TOP(Os_CANFD4_CANFD_Stack_Core0), OS_STACK_BOTTOM(Os_CANFD4_CANFD_Stack_Core0)},
    {OS_STACK_TOP(Os_CANFD5_CANFD_Stack_Core0), OS_STACK_BOTTOM(Os_CANFD5_CANFD_Stack_Core0)},
    {OS_STACK_TOP(Os_CANFD6_CANFD_Stack_Core0), OS_STACK_BOTTOM(Os_CANFD6_CANFD_Stack_Core0)},
    {OS_STACK_TOP(Os_CANFD7_CANFD_Stack_Core0), OS_STACK_BOTTOM(Os_CANFD7_CANFD_Stack_Core0)},
    {OS_STACK_TOP(Os_CANFD8_CANFD_Stack_Core0), OS_STACK_BOTTOM(Os_CANFD8_CANFD_Stack_Core0)},
    {OS_STACK_TOP(Os_ETMR2_CHN_B_Stack_Core0), OS_STACK_BOTTOM(Os_ETMR2_CHN_B_Stack_Core0)},
    {OS_STACK_TOP(Os_GPIO_AP_SYNC_DGPIO_Stack_Core0), OS_STACK_BOTTOM(Os_GPIO_AP_SYNC_DGPIO_Stack_Core0)},
    {OS_STACK_TOP(Os_SADC1_O_SADC_Stack_Core0), OS_STACK_BOTTOM(Os_SADC1_O_SADC_Stack_Core0)},
    {OS_STACK_TOP(Os_SADC2_O_SADC_Stack_Core0), OS_STACK_BOTTOM(Os_SADC2_O_SADC_Stack_Core0)},
    {OS_STACK_TOP(Os_SPI7_SPI_Stack_Core0), OS_STACK_BOTTOM(Os_SPI7_SPI_Stack_Core0)},
    {OS_STACK_TOP(Os_UART3_Stack_Core0), OS_STACK_BOTTOM(Os_UART3_Stack_Core0)},
    {OS_STACK_TOP(Os_UART11_Stack_Core0), OS_STACK_BOTTOM(Os_UART11_Stack_Core0)},
    {OS_STACK_TOP(Os_UART14_Stack_Core0), OS_STACK_BOTTOM(Os_UART14_Stack_Core0)},
    {OS_STACK_TOP(Os_WDT1_WDT_Stack_Core0), OS_STACK_BOTTOM(Os_WDT1_WDT_Stack_Core0)},
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_SysTimer_Stack_Core1[512];/*system timer*/
static VAR(Os_StackDataType, OS_VAR) Os_REMOTECALL_CORE1_Stack_Core1[512];/*Remote Call Software interrupt*/
#define OS_STOP_SEC_VAR_STACK_CORE1
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_StackType, OS_CONST) Os_ISR2StackCore1[CFG_ISR2_MAX_CORE1] =
{
    {OS_STACK_TOP(Os_SysTimer_Stack_Core1), OS_STACK_BOTTOM(Os_SysTimer_Stack_Core1)},/*system timer*/
    {OS_STACK_TOP(Os_REMOTECALL_CORE1_Stack_Core1), OS_STACK_BOTTOM(Os_REMOTECALL_CORE1_Stack_Core1)},/*Remote Call Software interrupt*/
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_SysTimer_Stack_Core2[512];/*system timer*/
static VAR(Os_StackDataType, OS_VAR) Os_REMOTECALL_CORE2_Stack_Core2[512];/*Remote Call Software interrupt*/
#define OS_STOP_SEC_VAR_STACK_CORE2
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_StackType, OS_CONST) Os_ISR2StackCore2[CFG_ISR2_MAX_CORE2] =
{
    {OS_STACK_TOP(Os_SysTimer_Stack_Core2), OS_STACK_BOTTOM(Os_SysTimer_Stack_Core2)},/*system timer*/
    {OS_STACK_TOP(Os_REMOTECALL_CORE2_Stack_Core2), OS_STACK_BOTTOM(Os_REMOTECALL_CORE2_Stack_Core2)},/*Remote Call Software interrupt*/
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

/* -------------------------Task Management---------------------- */
/* Core0 */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_TaskCfgType, OS_CONST) Os_TaskCfgCore0[CFG_TASK_MAX_CORE0] =
{
    {
        &Os_TaskEntry_OsTask__Core0_100ms,  /*osTaskEntry*/
        Os_GetObjLocalId(OsTask__Core0_100ms),   /*osTaskStackId*/
        1, /*osTaskActivation*/
        3,  /*osTaskPriority*/
        OS_PREEMPTIVE_FULL, /*osTaskSchedule*/
        0U,/*osRsv1*/
        OS_NULL_APPMODE,  /*osTaskAutoStartMode*/
    },
    {
        &Os_TaskEntry_OsTask__Core0_10ms,  /*osTaskEntry*/
        Os_GetObjLocalId(OsTask__Core0_10ms),   /*osTaskStackId*/
        1, /*osTaskActivation*/
        6,  /*osTaskPriority*/
        OS_PREEMPTIVE_FULL, /*osTaskSchedule*/
        0U,/*osRsv1*/
        OS_NULL_APPMODE,  /*osTaskAutoStartMode*/
    },
    {
        &Os_TaskEntry_OsTask__Core0_1ms,  /*osTaskEntry*/
        Os_GetObjLocalId(OsTask__Core0_1ms),   /*osTaskStackId*/
        1, /*osTaskActivation*/
        9,  /*osTaskPriority*/
        OS_PREEMPTIVE_FULL, /*osTaskSchedule*/
        0U,/*osRsv1*/
        OS_NULL_APPMODE,  /*osTaskAutoStartMode*/
    },
    {
        &Os_TaskEntry_OsTask__Core0_1s,  /*osTaskEntry*/
        Os_GetObjLocalId(OsTask__Core0_1s),   /*osTaskStackId*/
        1, /*osTaskActivation*/
        2,  /*osTaskPriority*/
        OS_PREEMPTIVE_FULL, /*osTaskSchedule*/
        0U,/*osRsv1*/
        OS_NULL_APPMODE,  /*osTaskAutoStartMode*/
    },
    {
        &Os_TaskEntry_OsTask__Core0_20ms,  /*osTaskEntry*/
        Os_GetObjLocalId(OsTask__Core0_20ms),   /*osTaskStackId*/
        1, /*osTaskActivation*/
        5,  /*osTaskPriority*/
        OS_PREEMPTIVE_FULL, /*osTaskSchedule*/
        0U,/*osRsv1*/
        OS_NULL_APPMODE,  /*osTaskAutoStartMode*/
    },
    {
        &Os_TaskEntry_OsTask__Core0_2ms,  /*osTaskEntry*/
        Os_GetObjLocalId(OsTask__Core0_2ms),   /*osTaskStackId*/
        1, /*osTaskActivation*/
        8,  /*osTaskPriority*/
        OS_PREEMPTIVE_FULL, /*osTaskSchedule*/
        0U,/*osRsv1*/
        OS_NULL_APPMODE,  /*osTaskAutoStartMode*/
    },
    {
        &Os_TaskEntry_OsTask__Core0_50ms,  /*osTaskEntry*/
        Os_GetObjLocalId(OsTask__Core0_50ms),   /*osTaskStackId*/
        1, /*osTaskActivation*/
        4,  /*osTaskPriority*/
        OS_PREEMPTIVE_FULL, /*osTaskSchedule*/
        0U,/*osRsv1*/
        OS_NULL_APPMODE,  /*osTaskAutoStartMode*/
    },
    {
        &Os_TaskEntry_OsTask__Core0_5ms,  /*osTaskEntry*/
        Os_GetObjLocalId(OsTask__Core0_5ms),   /*osTaskStackId*/
        1, /*osTaskActivation*/
        7,  /*osTaskPriority*/
        OS_PREEMPTIVE_FULL, /*osTaskSchedule*/
        0U,/*osRsv1*/
        OS_NULL_APPMODE,  /*osTaskAutoStartMode*/
    },
    {
        &Os_TaskEntry_OsTask_Core0_Init,  /*osTaskEntry*/
        Os_GetObjLocalId(OsTask_Core0_Init),   /*osTaskStackId*/
        1, /*osTaskActivation*/
        1,  /*osTaskPriority*/
        OS_PREEMPTIVE_NON, /*osTaskSchedule*/
        0U,/*osRsv1*/
        OSDEFAULTAPPMODE,  /*osTaskAutoStartMode*/
    },
    {
        &Os_TaskEntry_IdleCore0,    /*osTaskEntry*/
        Os_GetObjLocalId(OS_TASK_IDLE_CORE0), /*osTaskStackId*/
        1,    /*osTaskActivation*/
        0,    /*osTaskPriority*/
        OS_PREEMPTIVE_FULL,   /*osTaskSchedule*/
        0U,/*osRsv1*/
        OS_ALL_APPMODE,   /*osTaskAutoStartMode*/

    }
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
/* Core1 */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_TaskCfgType, OS_CONST) Os_TaskCfgCore1[CFG_TASK_MAX_CORE1] =
{
    {
        &Os_TaskEntry_OsTask__Core1_100ms,  /*osTaskEntry*/
        Os_GetObjLocalId(OsTask__Core1_100ms),   /*osTaskStackId*/
        1, /*osTaskActivation*/
        3,  /*osTaskPriority*/
        OS_PREEMPTIVE_FULL, /*osTaskSchedule*/
        0U,/*osRsv1*/
        OS_NULL_APPMODE,  /*osTaskAutoStartMode*/
    },
    {
        &Os_TaskEntry_OsTask__Core1_10ms,  /*osTaskEntry*/
        Os_GetObjLocalId(OsTask__Core1_10ms),   /*osTaskStackId*/
        1, /*osTaskActivation*/
        6,  /*osTaskPriority*/
        OS_PREEMPTIVE_FULL, /*osTaskSchedule*/
        0U,/*osRsv1*/
        OS_NULL_APPMODE,  /*osTaskAutoStartMode*/
    },
    {
        &Os_TaskEntry_OsTask__Core1_1ms,  /*osTaskEntry*/
        Os_GetObjLocalId(OsTask__Core1_1ms),   /*osTaskStackId*/
        1, /*osTaskActivation*/
        9,  /*osTaskPriority*/
        OS_PREEMPTIVE_FULL, /*osTaskSchedule*/
        0U,/*osRsv1*/
        OS_NULL_APPMODE,  /*osTaskAutoStartMode*/
    },
    {
        &Os_TaskEntry_OsTask__Core1_1s,  /*osTaskEntry*/
        Os_GetObjLocalId(OsTask__Core1_1s),   /*osTaskStackId*/
        1, /*osTaskActivation*/
        2,  /*osTaskPriority*/
        OS_PREEMPTIVE_FULL, /*osTaskSchedule*/
        0U,/*osRsv1*/
        OS_NULL_APPMODE,  /*osTaskAutoStartMode*/
    },
    {
        &Os_TaskEntry_OsTask__Core1_20ms,  /*osTaskEntry*/
        Os_GetObjLocalId(OsTask__Core1_20ms),   /*osTaskStackId*/
        1, /*osTaskActivation*/
        5,  /*osTaskPriority*/
        OS_PREEMPTIVE_FULL, /*osTaskSchedule*/
        0U,/*osRsv1*/
        OS_NULL_APPMODE,  /*osTaskAutoStartMode*/
    },
    {
        &Os_TaskEntry_OsTask__Core1_2ms,  /*osTaskEntry*/
        Os_GetObjLocalId(OsTask__Core1_2ms),   /*osTaskStackId*/
        1, /*osTaskActivation*/
        8,  /*osTaskPriority*/
        OS_PREEMPTIVE_FULL, /*osTaskSchedule*/
        0U,/*osRsv1*/
        OS_NULL_APPMODE,  /*osTaskAutoStartMode*/
    },
    {
        &Os_TaskEntry_OsTask__Core1_50ms,  /*osTaskEntry*/
        Os_GetObjLocalId(OsTask__Core1_50ms),   /*osTaskStackId*/
        1, /*osTaskActivation*/
        4,  /*osTaskPriority*/
        OS_PREEMPTIVE_FULL, /*osTaskSchedule*/
        0U,/*osRsv1*/
        OS_NULL_APPMODE,  /*osTaskAutoStartMode*/
    },
    {
        &Os_TaskEntry_OsTask__Core1_5ms,  /*osTaskEntry*/
        Os_GetObjLocalId(OsTask__Core1_5ms),   /*osTaskStackId*/
        1, /*osTaskActivation*/
        7,  /*osTaskPriority*/
        OS_PREEMPTIVE_FULL, /*osTaskSchedule*/
        0U,/*osRsv1*/
        OS_NULL_APPMODE,  /*osTaskAutoStartMode*/
    },
    {
        &Os_TaskEntry_OsTask_Core1_Init,  /*osTaskEntry*/
        Os_GetObjLocalId(OsTask_Core1_Init),   /*osTaskStackId*/
        1, /*osTaskActivation*/
        1,  /*osTaskPriority*/
        OS_PREEMPTIVE_NON, /*osTaskSchedule*/
        0U,/*osRsv1*/
        OSDEFAULTAPPMODE,  /*osTaskAutoStartMode*/
    },
    {
        &Os_TaskEntry_IdleCore1,    /*osTaskEntry*/
        Os_GetObjLocalId(OS_TASK_IDLE_CORE1), /*osTaskStackId*/
        1,    /*osTaskActivation*/
        0,    /*osTaskPriority*/
        OS_PREEMPTIVE_FULL,   /*osTaskSchedule*/
        0U,/*osRsv1*/
        OS_ALL_APPMODE,   /*osTaskAutoStartMode*/

    }
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
/* Core2 */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_TaskCfgType, OS_CONST) Os_TaskCfgCore2[CFG_TASK_MAX_CORE2] =
{
    {
        &Os_TaskEntry_OsTask__Core2_100ms,  /*osTaskEntry*/
        Os_GetObjLocalId(OsTask__Core2_100ms),   /*osTaskStackId*/
        1, /*osTaskActivation*/
        3,  /*osTaskPriority*/
        OS_PREEMPTIVE_FULL, /*osTaskSchedule*/
        0U,/*osRsv1*/
        OS_NULL_APPMODE,  /*osTaskAutoStartMode*/
    },
    {
        &Os_TaskEntry_OsTask__Core2_10ms,  /*osTaskEntry*/
        Os_GetObjLocalId(OsTask__Core2_10ms),   /*osTaskStackId*/
        1, /*osTaskActivation*/
        6,  /*osTaskPriority*/
        OS_PREEMPTIVE_FULL, /*osTaskSchedule*/
        0U,/*osRsv1*/
        OS_NULL_APPMODE,  /*osTaskAutoStartMode*/
    },
    {
        &Os_TaskEntry_OsTask__Core2_1ms,  /*osTaskEntry*/
        Os_GetObjLocalId(OsTask__Core2_1ms),   /*osTaskStackId*/
        1, /*osTaskActivation*/
        9,  /*osTaskPriority*/
        OS_PREEMPTIVE_FULL, /*osTaskSchedule*/
        0U,/*osRsv1*/
        OS_NULL_APPMODE,  /*osTaskAutoStartMode*/
    },
    {
        &Os_TaskEntry_OsTask__Core2_1s,  /*osTaskEntry*/
        Os_GetObjLocalId(OsTask__Core2_1s),   /*osTaskStackId*/
        1, /*osTaskActivation*/
        2,  /*osTaskPriority*/
        OS_PREEMPTIVE_FULL, /*osTaskSchedule*/
        0U,/*osRsv1*/
        OS_NULL_APPMODE,  /*osTaskAutoStartMode*/
    },
    {
        &Os_TaskEntry_OsTask__Core2_20ms,  /*osTaskEntry*/
        Os_GetObjLocalId(OsTask__Core2_20ms),   /*osTaskStackId*/
        1, /*osTaskActivation*/
        5,  /*osTaskPriority*/
        OS_PREEMPTIVE_FULL, /*osTaskSchedule*/
        0U,/*osRsv1*/
        OS_NULL_APPMODE,  /*osTaskAutoStartMode*/
    },
    {
        &Os_TaskEntry_OsTask__Core2_2ms,  /*osTaskEntry*/
        Os_GetObjLocalId(OsTask__Core2_2ms),   /*osTaskStackId*/
        1, /*osTaskActivation*/
        8,  /*osTaskPriority*/
        OS_PREEMPTIVE_FULL, /*osTaskSchedule*/
        0U,/*osRsv1*/
        OS_NULL_APPMODE,  /*osTaskAutoStartMode*/
    },
    {
        &Os_TaskEntry_OsTask__Core2_50ms,  /*osTaskEntry*/
        Os_GetObjLocalId(OsTask__Core2_50ms),   /*osTaskStackId*/
        1, /*osTaskActivation*/
        4,  /*osTaskPriority*/
        OS_PREEMPTIVE_FULL, /*osTaskSchedule*/
        0U,/*osRsv1*/
        OS_NULL_APPMODE,  /*osTaskAutoStartMode*/
    },
    {
        &Os_TaskEntry_OsTask__Core2_5ms,  /*osTaskEntry*/
        Os_GetObjLocalId(OsTask__Core2_5ms),   /*osTaskStackId*/
        1, /*osTaskActivation*/
        7,  /*osTaskPriority*/
        OS_PREEMPTIVE_FULL, /*osTaskSchedule*/
        0U,/*osRsv1*/
        OS_NULL_APPMODE,  /*osTaskAutoStartMode*/
    },
    {
        &Os_TaskEntry_OsTask_Core2_Init,  /*osTaskEntry*/
        Os_GetObjLocalId(OsTask_Core2_Init),   /*osTaskStackId*/
        1, /*osTaskActivation*/
        1,  /*osTaskPriority*/
        OS_PREEMPTIVE_NON, /*osTaskSchedule*/
        0U,/*osRsv1*/
        OSDEFAULTAPPMODE,  /*osTaskAutoStartMode*/
    },
    {
        &Os_TaskEntry_IdleCore2,    /*osTaskEntry*/
        Os_GetObjLocalId(OS_TASK_IDLE_CORE2), /*osTaskStackId*/
        1,    /*osTaskActivation*/
        0,    /*osTaskPriority*/
        OS_PREEMPTIVE_FULL,   /*osTaskSchedule*/
        0U,/*osRsv1*/
        OS_ALL_APPMODE,   /*osTaskAutoStartMode*/

    }
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

/* ------------------------Counter Management--------------------- */
/* Core0 */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_CounterCfgType, OS_CONST) Os_CounterCfgCore0[CFG_COUNTER_MAX_CORE0] =
{
    {
         65535, /*osCounterMaxAllowedValue*/
        1,    /*osCounterMinCycle*/
        1,    /*osCounterTicksPerBase*/
        COUNTER_HARDWARE, /*osCounterType*/
        1000, /*osSecondsPerTick*/
    },
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
/* Core1 */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_CounterCfgType, OS_CONST) Os_CounterCfgCore1[CFG_COUNTER_MAX_CORE1] =
{
    {
         65535, /*osCounterMaxAllowedValue*/
        1,    /*osCounterMinCycle*/
        1,    /*osCounterTicksPerBase*/
        COUNTER_HARDWARE, /*osCounterType*/
        1000, /*osSecondsPerTick*/
    },
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
/* Core2 */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_CounterCfgType, OS_CONST) Os_CounterCfgCore2[CFG_COUNTER_MAX_CORE2] =
{
    {
         65535, /*osCounterMaxAllowedValue*/
        1,    /*osCounterMinCycle*/
        1,    /*osCounterTicksPerBase*/
        COUNTER_HARDWARE, /*osCounterType*/
        1000, /*osSecondsPerTick*/
    },
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
FUNC(void, OS_CODE) Os_ArchSystemTimerCore0(void)
{
    (void)Os_IncrementHardCounter(SystemTimer_Core0);
}
FUNC(void, OS_CODE) Os_ArchSystemTimerCore1(void)
{
    (void)Os_IncrementHardCounter(SystemTimer_Core1);
}
FUNC(void, OS_CODE) Os_ArchSystemTimerCore2(void)
{
    (void)Os_IncrementHardCounter(SystemTimer_Core2);
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

/* --------------------------Alarm Management---------------------- */
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_Core0_100ms(void)
{
    (void)ActivateTask(OsTask__Core0_100ms);
}
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_Core0_10ms(void)
{
    (void)ActivateTask(OsTask__Core0_10ms);
}
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_Core0_1ms(void)
{
    (void)ActivateTask(OsTask__Core0_1ms);
}
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_Core0_1s(void)
{
    (void)ActivateTask(OsTask__Core0_1s);
}
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_Core0_20ms(void)
{
    (void)ActivateTask(OsTask__Core0_20ms);
}
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_Core0_2ms(void)
{
    (void)ActivateTask(OsTask__Core0_2ms);
}
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_Core0_50ms(void)
{
    (void)ActivateTask(OsTask__Core0_50ms);
}
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_Core0_5ms(void)
{
    (void)ActivateTask(OsTask__Core0_5ms);
}
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_Core1_100ms(void)
{
    (void)ActivateTask(OsTask__Core1_100ms);
}
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_Core1_10ms(void)
{
    (void)ActivateTask(OsTask__Core1_10ms);
}
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_Core1_1ms(void)
{
    (void)ActivateTask(OsTask__Core1_1ms);
}
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_Core1_1s(void)
{
    (void)ActivateTask(OsTask__Core1_1s);
}
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_Core1_20ms(void)
{
    (void)ActivateTask(OsTask__Core1_20ms);
}
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_Core1_2ms(void)
{
    (void)ActivateTask(OsTask__Core1_2ms);
}
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_Core1_50ms(void)
{
    (void)ActivateTask(OsTask__Core1_50ms);
}
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_Core1_5ms(void)
{
    (void)ActivateTask(OsTask__Core1_5ms);
}
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_Core2_100ms(void)
{
    (void)ActivateTask(OsTask__Core2_100ms);
}
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_Core2_10ms(void)
{
    (void)ActivateTask(OsTask__Core2_10ms);
}
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_Core2_1ms(void)
{
    (void)ActivateTask(OsTask__Core2_1ms);
}
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_Core2_1s(void)
{
    (void)ActivateTask(OsTask__Core2_1s);
}
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_Core2_20ms(void)
{
    (void)ActivateTask(OsTask__Core2_20ms);
}
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_Core2_2ms(void)
{
    (void)ActivateTask(OsTask__Core2_2ms);
}
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_Core2_50ms(void)
{
    (void)ActivateTask(OsTask__Core2_50ms);
}
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_Core2_5ms(void)
{
    (void)ActivateTask(OsTask__Core2_5ms);
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

/* Core0 */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_AlarmCfgType, OS_CONST) Os_AlarmCfgCore0[CFG_ALARM_MAX_CORE0] =
{
    {
        Os_GetObjLocalId(SystemTimer_Core0),  /*osAlarmCounter*/
        NULL_PTR,           /*osAlarmAutostartRef*/
        &AlarmCallback_OsAlarm_Core0_100ms,         /*osAlarmCallback*/
    },
    {
        Os_GetObjLocalId(SystemTimer_Core0),  /*osAlarmCounter*/
        NULL_PTR,           /*osAlarmAutostartRef*/
        &AlarmCallback_OsAlarm_Core0_10ms,          /*osAlarmCallback*/
    },
    {
        Os_GetObjLocalId(SystemTimer_Core0),  /*osAlarmCounter*/
        NULL_PTR,           /*osAlarmAutostartRef*/
        &AlarmCallback_OsAlarm_Core0_1ms,           /*osAlarmCallback*/
    },
    {
        Os_GetObjLocalId(SystemTimer_Core0),  /*osAlarmCounter*/
        NULL_PTR,           /*osAlarmAutostartRef*/
        &AlarmCallback_OsAlarm_Core0_1s,            /*osAlarmCallback*/
    },
    {
        Os_GetObjLocalId(SystemTimer_Core0),  /*osAlarmCounter*/
        NULL_PTR,           /*osAlarmAutostartRef*/
        &AlarmCallback_OsAlarm_Core0_20ms,          /*osAlarmCallback*/
    },
    {
        Os_GetObjLocalId(SystemTimer_Core0),  /*osAlarmCounter*/
        NULL_PTR,           /*osAlarmAutostartRef*/
        &AlarmCallback_OsAlarm_Core0_2ms,           /*osAlarmCallback*/
    },
    {
        Os_GetObjLocalId(SystemTimer_Core0),  /*osAlarmCounter*/
        NULL_PTR,           /*osAlarmAutostartRef*/
        &AlarmCallback_OsAlarm_Core0_50ms,          /*osAlarmCallback*/
    },
    {
        Os_GetObjLocalId(SystemTimer_Core0),  /*osAlarmCounter*/
        NULL_PTR,           /*osAlarmAutostartRef*/
        &AlarmCallback_OsAlarm_Core0_5ms,           /*osAlarmCallback*/
    },
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
/* Core1 */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_AlarmCfgType, OS_CONST) Os_AlarmCfgCore1[CFG_ALARM_MAX_CORE1] =
{
    {
        Os_GetObjLocalId(SystemTimer_Core1),  /*osAlarmCounter*/
        NULL_PTR,           /*osAlarmAutostartRef*/
        &AlarmCallback_OsAlarm_Core1_100ms,         /*osAlarmCallback*/
    },
    {
        Os_GetObjLocalId(SystemTimer_Core1),  /*osAlarmCounter*/
        NULL_PTR,           /*osAlarmAutostartRef*/
        &AlarmCallback_OsAlarm_Core1_10ms,          /*osAlarmCallback*/
    },
    {
        Os_GetObjLocalId(SystemTimer_Core1),  /*osAlarmCounter*/
        NULL_PTR,           /*osAlarmAutostartRef*/
        &AlarmCallback_OsAlarm_Core1_1ms,           /*osAlarmCallback*/
    },
    {
        Os_GetObjLocalId(SystemTimer_Core1),  /*osAlarmCounter*/
        NULL_PTR,           /*osAlarmAutostartRef*/
        &AlarmCallback_OsAlarm_Core1_1s,            /*osAlarmCallback*/
    },
    {
        Os_GetObjLocalId(SystemTimer_Core1),  /*osAlarmCounter*/
        NULL_PTR,           /*osAlarmAutostartRef*/
        &AlarmCallback_OsAlarm_Core1_20ms,          /*osAlarmCallback*/
    },
    {
        Os_GetObjLocalId(SystemTimer_Core1),  /*osAlarmCounter*/
        NULL_PTR,           /*osAlarmAutostartRef*/
        &AlarmCallback_OsAlarm_Core1_2ms,           /*osAlarmCallback*/
    },
    {
        Os_GetObjLocalId(SystemTimer_Core1),  /*osAlarmCounter*/
        NULL_PTR,           /*osAlarmAutostartRef*/
        &AlarmCallback_OsAlarm_Core1_50ms,          /*osAlarmCallback*/
    },
    {
        Os_GetObjLocalId(SystemTimer_Core1),  /*osAlarmCounter*/
        NULL_PTR,           /*osAlarmAutostartRef*/
        &AlarmCallback_OsAlarm_Core1_5ms,           /*osAlarmCallback*/
    },
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
/* Core2 */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_AlarmCfgType, OS_CONST) Os_AlarmCfgCore2[CFG_ALARM_MAX_CORE2] =
{
    {
        Os_GetObjLocalId(SystemTimer_Core2),  /*osAlarmCounter*/
        NULL_PTR,           /*osAlarmAutostartRef*/
        &AlarmCallback_OsAlarm_Core2_100ms,         /*osAlarmCallback*/
    },
    {
        Os_GetObjLocalId(SystemTimer_Core2),  /*osAlarmCounter*/
        NULL_PTR,           /*osAlarmAutostartRef*/
        &AlarmCallback_OsAlarm_Core2_10ms,          /*osAlarmCallback*/
    },
    {
        Os_GetObjLocalId(SystemTimer_Core2),  /*osAlarmCounter*/
        NULL_PTR,           /*osAlarmAutostartRef*/
        &AlarmCallback_OsAlarm_Core2_1ms,           /*osAlarmCallback*/
    },
    {
        Os_GetObjLocalId(SystemTimer_Core2),  /*osAlarmCounter*/
        NULL_PTR,           /*osAlarmAutostartRef*/
        &AlarmCallback_OsAlarm_Core2_1s,            /*osAlarmCallback*/
    },
    {
        Os_GetObjLocalId(SystemTimer_Core2),  /*osAlarmCounter*/
        NULL_PTR,           /*osAlarmAutostartRef*/
        &AlarmCallback_OsAlarm_Core2_20ms,          /*osAlarmCallback*/
    },
    {
        Os_GetObjLocalId(SystemTimer_Core2),  /*osAlarmCounter*/
        NULL_PTR,           /*osAlarmAutostartRef*/
        &AlarmCallback_OsAlarm_Core2_2ms,           /*osAlarmCallback*/
    },
    {
        Os_GetObjLocalId(SystemTimer_Core2),  /*osAlarmCounter*/
        NULL_PTR,           /*osAlarmAutostartRef*/
        &AlarmCallback_OsAlarm_Core2_50ms,          /*osAlarmCallback*/
    },
    {
        Os_GetObjLocalId(SystemTimer_Core2),  /*osAlarmCounter*/
        NULL_PTR,           /*osAlarmAutostartRef*/
        &AlarmCallback_OsAlarm_Core2_5ms,           /*osAlarmCallback*/
    },
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

/* -------------------------Resource Management------------------ */

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_ResourceCfgType, OS_CONST) Os_ResourceCfgCore0[CFG_STD_RESOURCE_MAX_CORE0] =
{
    {
     9U, /*ceiling*/
     OCCUPIED_BY_TASK,  /*resourceOccupyType*/
     0U,/*rsv1*/
     },

};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_ResourceCfgType, OS_CONST) Os_ResourceCfgCore1[CFG_STD_RESOURCE_MAX_CORE1] =
{
    {
     9U, /*ceiling*/
     OCCUPIED_BY_TASK,  /*resourceOccupyType*/
     0U,/*rsv1*/
     },

};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_ResourceCfgType, OS_CONST) Os_ResourceCfgCore2[CFG_STD_RESOURCE_MAX_CORE2] =
{
    {
     9U, /*ceiling*/
     OCCUPIED_BY_TASK,  /*resourceOccupyType*/
     0U,/*rsv1*/
     },

};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

/* -----------------------ISR Management-------------------------- */
/* Core0 */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_IsrCfgType, OS_CONST) Os_IsrCfgCore0[CFG_ISR_MAX_CORE0] =
{
    {
        OS_ISR_CATEGORY2,   /*OsIsrCatType*/
        FALSE,   /*OsNestedEnable*/
        BTM1_O_BTM, /*OsIsrSrc*/
        OS_ARCH_INT_CPU0, /*OsIsrSrcType*/
    },
    {
        OS_ISR_CATEGORY2,   /*OsIsrCatType*/
        FALSE,  /*OsNestedEnable*/
        MB_SEMAPHORE_LOCK_FAIL, /*OsIsrSrc*/
        OS_ARCH_INT_CPU0, /*OsIsrSrcType*/
    },
    {
        OS_ISR_CATEGORY2,   /*OsIsrCatType*/
        FALSE,  /*OsNestedEnable*/
        CANFD3_CANFD,   /*OsIsrSrc*/
        OS_ARCH_INT_CPU0, /*OsIsrSrcType*/
    },
    {
        OS_ISR_CATEGORY2,   /*OsIsrCatType*/
        FALSE,  /*OsNestedEnable*/
        CANFD4_CANFD,   /*OsIsrSrc*/
        OS_ARCH_INT_CPU0, /*OsIsrSrcType*/
    },
    {
        OS_ISR_CATEGORY2,   /*OsIsrCatType*/
        FALSE,  /*OsNestedEnable*/
        CANFD5_CANFD,   /*OsIsrSrc*/
        OS_ARCH_INT_CPU0, /*OsIsrSrcType*/
    },
    {
        OS_ISR_CATEGORY2,   /*OsIsrCatType*/
        FALSE,  /*OsNestedEnable*/
        CANFD6_CANFD,   /*OsIsrSrc*/
        OS_ARCH_INT_CPU0, /*OsIsrSrcType*/
    },
    {
        OS_ISR_CATEGORY2,   /*OsIsrCatType*/
        FALSE,  /*OsNestedEnable*/
        CANFD7_CANFD,   /*OsIsrSrc*/
        OS_ARCH_INT_CPU0, /*OsIsrSrcType*/
    },
    {
        OS_ISR_CATEGORY2,   /*OsIsrCatType*/
        FALSE,  /*OsNestedEnable*/
        CANFD8_CANFD,   /*OsIsrSrc*/
        OS_ARCH_INT_CPU0, /*OsIsrSrcType*/
    },
    {
        OS_ISR_CATEGORY2,   /*OsIsrCatType*/
        FALSE,  /*OsNestedEnable*/
        ETMR2_CHN_B,    /*OsIsrSrc*/
        OS_ARCH_INT_CPU0, /*OsIsrSrcType*/
    },
    {
        OS_ISR_CATEGORY2,   /*OsIsrCatType*/
        FALSE,  /*OsNestedEnable*/
        GPIO_AP_SYNC_DGPIO, /*OsIsrSrc*/
        OS_ARCH_INT_CPU0, /*OsIsrSrcType*/
    },
    {
        OS_ISR_CATEGORY2,   /*OsIsrCatType*/
        FALSE,  /*OsNestedEnable*/
        SADC1_O_SADC,   /*OsIsrSrc*/
        OS_ARCH_INT_CPU0, /*OsIsrSrcType*/
    },
    {
        OS_ISR_CATEGORY2,   /*OsIsrCatType*/
        FALSE,  /*OsNestedEnable*/
        SADC2_O_SADC,   /*OsIsrSrc*/
        OS_ARCH_INT_CPU0, /*OsIsrSrcType*/
    },
    {
        OS_ISR_CATEGORY2,   /*OsIsrCatType*/
        FALSE,  /*OsNestedEnable*/
        SPI7_SPI,   /*OsIsrSrc*/
        OS_ARCH_INT_CPU0, /*OsIsrSrcType*/
    },
    {
        OS_ISR_CATEGORY2,   /*OsIsrCatType*/
        FALSE,  /*OsNestedEnable*/
        UART3,  /*OsIsrSrc*/
        OS_ARCH_INT_CPU0, /*OsIsrSrcType*/
    },
    {
        OS_ISR_CATEGORY2,   /*OsIsrCatType*/
        FALSE,  /*OsNestedEnable*/
        UART11, /*OsIsrSrc*/
        OS_ARCH_INT_CPU0, /*OsIsrSrcType*/
    },
    {
        OS_ISR_CATEGORY2,   /*OsIsrCatType*/
        FALSE,  /*OsNestedEnable*/
        UART14, /*OsIsrSrc*/
        OS_ARCH_INT_CPU0, /*OsIsrSrcType*/
    },
    {
        OS_ISR_CATEGORY2,   /*OsIsrCatType*/
        FALSE,  /*OsNestedEnable*/
        WDT1_WDT,   /*OsIsrSrc*/
        OS_ARCH_INT_CPU0, /*OsIsrSrcType*/
    },
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ISR_STM0_SR0[1] =
{
    0x1U
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ISR_GPSR0_SR0[1] =
{
    0x1U
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ISR_CANFD3_CANFD[1] =
{
    0x0U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ISR_CANFD4_CANFD[1] =
{
    0x0U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ISR_CANFD5_CANFD[1] =
{
    0x0U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ISR_CANFD6_CANFD[1] =
{
    0x0U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ISR_CANFD7_CANFD[1] =
{
    0x0U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ISR_CANFD8_CANFD[1] =
{
    0x0U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ISR_ETMR2_CHN_B[1] =
{
    0x0U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ISR_GPIO_AP_SYNC_DGPIO[1] =
{
    0x0U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ISR_SADC1_O_SADC[1] =
{
    0x0U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ISR_SADC2_O_SADC[1] =
{
    0x0U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ISR_SPI7_SPI[1] =
{
    0x0U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ISR_UART3[1] =
{
    0x0U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ISR_UART11[1] =
{
    0x0U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ISR_UART14[1] =
{
    0x0U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ISR_WDT1_WDT[1] =
{
    0x0U,
};
P2CONST(uint16, OS_VAR, OS_CONST) Os_IsrResourceAccessMaskCore0[CFG_ISR2_MAX_CORE0] =
{
    Os_ResourceAccessMask_ISR_STM0_SR0,
    Os_ResourceAccessMask_ISR_GPSR0_SR0,
    Os_ResourceAccessMask_ISR_CANFD3_CANFD,
    Os_ResourceAccessMask_ISR_CANFD4_CANFD,
    Os_ResourceAccessMask_ISR_CANFD5_CANFD,
    Os_ResourceAccessMask_ISR_CANFD6_CANFD,
    Os_ResourceAccessMask_ISR_CANFD7_CANFD,
    Os_ResourceAccessMask_ISR_CANFD8_CANFD,
    Os_ResourceAccessMask_ISR_ETMR2_CHN_B,
    Os_ResourceAccessMask_ISR_GPIO_AP_SYNC_DGPIO,
    Os_ResourceAccessMask_ISR_SADC1_O_SADC,
    Os_ResourceAccessMask_ISR_SADC2_O_SADC,
    Os_ResourceAccessMask_ISR_SPI7_SPI,
    Os_ResourceAccessMask_ISR_UART3,
    Os_ResourceAccessMask_ISR_UART11,
    Os_ResourceAccessMask_ISR_UART14,
    Os_ResourceAccessMask_ISR_WDT1_WDT,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

/* Core1 */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_IsrCfgType, OS_CONST) Os_IsrCfgCore1[CFG_ISR_MAX_CORE1] =
{
    {
        OS_ISR_CATEGORY2,   /*OsIsrCatType*/
        FALSE,   /*OsNestedEnable*/
        BTM2_O_BTM, /*OsIsrSrc*/
        OS_ARCH_INT_CPU1, /*OsIsrSrcType*/
    },
    {
        OS_ISR_CATEGORY2,   /*OsIsrCatType*/
        FALSE,  /*OsNestedEnable*/
        MB_SEMAPHORE_LOCK_FAIL, /*OsIsrSrc*/
        OS_ARCH_INT_CPU1, /*OsIsrSrcType*/
    },
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ISR_STM1_SR0[1] =
{
    0x1U
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ISR_GPSR0_SR1[1] =
{
    0x1U
};
P2CONST(uint16, OS_VAR, OS_CONST) Os_IsrResourceAccessMaskCore1[CFG_ISR2_MAX_CORE1] =
{
    Os_ResourceAccessMask_ISR_STM1_SR0,
    Os_ResourceAccessMask_ISR_GPSR0_SR1,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

/* Core2 */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_IsrCfgType, OS_CONST) Os_IsrCfgCore2[CFG_ISR_MAX_CORE2] =
{
    {
        OS_ISR_CATEGORY2,   /*OsIsrCatType*/
        FALSE,   /*OsNestedEnable*/
        BTM3_O_BTM, /*OsIsrSrc*/
        OS_ARCH_INT_CPU2, /*OsIsrSrcType*/
    },
    {
        OS_ISR_CATEGORY2,   /*OsIsrCatType*/
        FALSE,  /*OsNestedEnable*/
        MB_SEMAPHORE_LOCK_FAIL, /*OsIsrSrc*/
        OS_ARCH_INT_CPU2, /*OsIsrSrcType*/
    },
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ISR_STM2_SR0[1] =
{
    0x1U
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ISR_GPSR0_SR2[1] =
{
    0x1U
};
P2CONST(uint16, OS_VAR, OS_CONST) Os_IsrResourceAccessMaskCore2[CFG_ISR2_MAX_CORE2] =
{
    Os_ResourceAccessMask_ISR_STM2_SR0,
    Os_ResourceAccessMask_ISR_GPSR0_SR2,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

/* -----------------Control block definition--------------------- */
/*
 * Private data,be accessed by own core.
 */
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_TCBType volatile, OS_VAR) Os_TCBCore0[CFG_TASK_MAX_CORE0];
VAR(Os_TCBType volatile, OS_VAR) Os_TCBCore1[CFG_TASK_MAX_CORE1];
VAR(Os_TCBType volatile, OS_VAR) Os_TCBCore2[CFG_TASK_MAX_CORE2];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_CCBType volatile, OS_VAR) Os_CCBCore0[CFG_COUNTER_MAX_CORE0];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_CCBType volatile, OS_VAR) Os_CCBCore1[CFG_COUNTER_MAX_CORE1];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_CCBType volatile, OS_VAR) Os_CCBCore2[CFG_COUNTER_MAX_CORE2];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_ACBType volatile, OS_VAR) Os_ACBCore0[CFG_ALARM_MAX_CORE0];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_ACBType volatile, OS_VAR) Os_ACBCore1[CFG_ALARM_MAX_CORE1];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_ACBType volatile, OS_VAR) Os_ACBCore2[CFG_ALARM_MAX_CORE2];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_RCBType volatile, OS_VAR) Os_RCBCore0[CFG_STD_RESOURCE_MAX_CORE0];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_RCBType volatile, OS_VAR) Os_RCBCore1[CFG_STD_RESOURCE_MAX_CORE1];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_RCBType volatile, OS_VAR) Os_RCBCore2[CFG_STD_RESOURCE_MAX_CORE2];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_ICBType volatile,  OS_VAR) Os_ICBCore0[CFG_ISR2_MAX_CORE0];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_ICBType volatile,  OS_VAR) Os_ICBCore1[CFG_ISR2_MAX_CORE1];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_ICBType volatile,  OS_VAR) Os_ICBCore2[CFG_ISR2_MAX_CORE2];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"

/*
 * Private data, be accessed by own core.
 */

#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_IsrType,  OS_VAR) Os_SysIsrNestQueueCore0[CFG_ISR2_MAX_CORE0];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_IsrType,  OS_VAR) Os_SysIsrNestQueueCore1[CFG_ISR2_MAX_CORE1];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_IsrType,  OS_VAR) Os_SysIsrNestQueueCore2[CFG_ISR2_MAX_CORE2];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"

/*
 * Global data, be accessed by all core.
 */
#define OS_START_SEC_VAR_NOINIT_GLOBAL
#include "Os_MemMap.h"
VAR(Os_APPCBType volatile, OS_VAR)  Os_AppCB[CFG_OSAPPLICATION_MAX];
Os_CoreCBType volatile              Os_CoreCB;
#define OS_STOP_SEC_VAR_NOINIT_GLOBAL
#include "Os_MemMap.h"

/*
 * Clone data, Each core has a copy.
 */
#define OS_START_SEC_VAR_CLONE_32
#include "Os_MemMap.h"
VAR(Os_SCBType volatile, OS_VAR)    Os_SCB;
#define OS_STOP_SEC_VAR_CLONE_32
#include "Os_MemMap.h"

/*=======[E N D   O F   F I L E]==============================================*/

