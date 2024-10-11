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
**  FILENAME    : Interrupt.c                                                 **
**                                                                            **
**  Created on  :                                                             **
**  Author      : yaoxuan.zhang                                               **
**  Vendor      :                                                             **
**  DESCRIPTION : interrupt manager                                           **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>    <AUTHOR>        <REVISION LOG>
 *  V0.1.0     2017-07-19    zuxiong.ding    Move from Os_Kernel.
 *  V0.2.0     2019-08-21    shun.li & zhiqiang.huang   Functional safety initial version.
 *  V1.0.0     2019-11-21    shun.li         Functional safety version.
 *  V1.0.1     2021-08-19    shun.li         Add suspend and release OS interrupts function of Spinlock module.
 */
/*============================================================================*/

/*=======[I N C L U D E S]====================================================*/
#include "Os_Internal.h"

/*=======[M A C R O S]========================================================*/

/*=======[T Y P E   D E F I N I T I O N S]====================================*/

/*=======[E X T E R N A L   D A T A]==========================================*/
#if (CFG_ISR_MAX > 0U)
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
VAR(uint16, OS_VAR) Os_CfgIsrMax = 0U;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
VAR(uint16, OS_VAR) Os_CfgIsr2Max = 0U;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
P2VAR(Os_ICBType volatile, AUTOMATIC, OS_VAR) Os_ICB = NULL_PTR;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
P2CONST(Os_StackType, AUTOMATIC, OS_VAR) Os_ISR2Stack = NULL_PTR;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
P2CONST(Os_IsrCfgType, AUTOMATIC, OS_VAR) Os_IsrCfg = NULL_PTR;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
VAR(Os_IsrType, OS_VAR) Os_IntCfgIsrId = 0U;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#endif /* #if (CFG_ISR_MAX > 0U) */

/*=======[E X T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/

/*=======[I N T E R N A L   D A T A]==========================================*/
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
/* Indicates the maximum IPL for cate 2 interrupts. */
/* DD_1_0158 */
static VAR(Os_IPLType, OS_VAR) Os_cfgIsr2IplMax = 0U;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
/* Save the interrupt call level. */
/* DD_1_0159 */
static VAR(Os_CallLevelType, OS_VAR) Os_SaveLevel = OS_LEVEL_ISR2;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#if (FALSE == CFG_TIMING_PROTECTION_ENABLE)
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
/* Save the status of all interrupts. */
/* DD_1_0160 */
static VAR(Os_ArchMsrType, OS_VAR) Os_SaveAllInt = 0U;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
/* Save the state of nestable interrupts. */
/* DD_1_0161 */
static VAR(Os_ArchMsrType, OS_VAR) Os_SaveAllIntNested = 0U;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#endif               /* FALSE == CFG_TIMING_PROTECTION_ENABLE */

/* PRQA S 1514 ++ */ /* MISRA Rule 8.9 */
#if (CFG_STD_RESOURCE_MAX_CORE0 > 0U)
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
Os_ResourceType Os_ICBIsrC2ResourceStackCore0[CFG_ISR2_MAX_CORE0][CFG_STD_RESOURCE_MAX_CORE0];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif /* CFG_STD_RESOURCE_MAX_CORE0 > 0U */

#if (CFG_STD_RESOURCE_MAX_CORE1 > 0U)
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
Os_ResourceType Os_ICBIsrC2ResourceStackCore1[CFG_ISR2_MAX_CORE1][CFG_STD_RESOURCE_MAX_CORE1];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif /* CFG_STD_RESOURCE_MAX_CORE1 > 0U */

#if (CFG_STD_RESOURCE_MAX_CORE2 > 0U)
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
Os_ResourceType Os_ICBIsrC2ResourceStackCore2[CFG_ISR2_MAX_CORE2][CFG_STD_RESOURCE_MAX_CORE2];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif /* CFG_STD_RESOURCE_MAX_CORE2 > 0U */

#if (CFG_STD_RESOURCE_MAX_CORE3 > 0U)
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
Os_ResourceType Os_ICBIsrC2ResourceStackCore3[CFG_ISR2_MAX_CORE3][CFG_STD_RESOURCE_MAX_CORE3];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif /* CFG_STD_RESOURCE_MAX_CORE3 > 0U */

#if (CFG_STD_RESOURCE_MAX_CORE4 > 0U)
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
Os_ResourceType Os_ICBIsrC2ResourceStackCore4[CFG_ISR2_MAX_CORE4][CFG_STD_RESOURCE_MAX_CORE4];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif /* CFG_STD_RESOURCE_MAX_CORE4 > 0U */

#if (CFG_STD_RESOURCE_MAX_CORE5 > 0U)
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
Os_ResourceType Os_ICBIsrC2ResourceStackCore5[CFG_ISR2_MAX_CORE5][CFG_STD_RESOURCE_MAX_CORE5];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif               /* CFG_STD_RESOURCE_MAX_CORE5 > 0U */
/* PRQA S 1514 -- */ /* MISRA Rule 8.9 */

/*=======[I N T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/

/*=======[F U N C T I O N   I M P L E M E N T A T I O N S]====================*/
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/******************************************************************************/
/*
 * Brief                <Init the Interrupt block control.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_InitSystem>
 * REQ ID               <DD_1_0809, DD_1_0810, DD_1_0157>
 */
/******************************************************************************/
#if (CFG_ISR2_MAX > 0)
FUNC(void, OS_CODE) Os_InitInterrupt(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Os_IsrType i;
#if ((CFG_SPINLOCK_MAX > 0U) && (CFG_STD_RESOURCE_MAX > 0U))
    uint16 j;
    P2VAR(Os_ICBType volatile, AUTOMATIC, OS_VAR) pICB;
#endif /* (CFG_SPINLOCK_MAX > 0U) && (CFG_STD_RESOURCE_MAX > 0U) */

    switch (Os_SCB.sysCore)
    {
#if (CFG_ISR_MAX_CORE0 > 0)
    case 0:
        Os_CfgIsrMax = CFG_ISR_MAX_CORE0;
        Os_CfgIsr2Max = CFG_ISR2_MAX_CORE0;
        Os_ICB = Os_ICBCore0;
        Os_ISR2Stack = Os_ISR2StackCore0;
        Os_IsrCfg = Os_IsrCfgCore0;
        Os_cfgIsr2IplMax = CFG_ISR2_IPL_MAX_CORE0;
#if (CFG_STD_RESOURCE_MAX_CORE0 > 0U)
        for (i = 0U; i < CFG_ISR2_MAX_CORE0; i++)
        {
            Os_ICBCore0[i].IsrC2ResourceStack = Os_ICBIsrC2ResourceStackCore0[i];
        }
#endif /* CFG_STD_RESOURCE_MAX_CORE0 > 0U */
        break;
#endif /* CFG_ISR_MAX_CORE0 > 0 */

#if (CFG_ISR_MAX_CORE1 > 0)
    case 1:
        Os_CfgIsrMax = CFG_ISR_MAX_CORE1;
        Os_CfgIsr2Max = CFG_ISR2_MAX_CORE1;
        Os_ICB = Os_ICBCore1;
        Os_ISR2Stack = Os_ISR2StackCore1;
        Os_IsrCfg = Os_IsrCfgCore1;
        Os_cfgIsr2IplMax = CFG_ISR2_IPL_MAX_CORE1;
#if (CFG_STD_RESOURCE_MAX_CORE1 > 0U)
        for (i = 0U; i < CFG_ISR2_MAX_CORE1; i++)
        {
            Os_ICBCore1[i].IsrC2ResourceStack = Os_ICBIsrC2ResourceStackCore1[i];
        }
#endif /* CFG_STD_RESOURCE_MAX_CORE1 > 0U */
        break;
#endif /* CFG_ISR_MAX_CORE1 > 0 */

#if (CFG_ISR_MAX_CORE2 > 0)
    case 2:
        Os_CfgIsrMax = CFG_ISR_MAX_CORE2;
        Os_CfgIsr2Max = CFG_ISR2_MAX_CORE2;
        Os_ICB = Os_ICBCore2;
        Os_ISR2Stack = Os_ISR2StackCore2;
        Os_IsrCfg = Os_IsrCfgCore2;
        Os_cfgIsr2IplMax = CFG_ISR2_IPL_MAX_CORE2;
#if (CFG_STD_RESOURCE_MAX_CORE2 > 0U)
        for (i = 0U; i < CFG_ISR2_MAX_CORE2; i++)
        {
            Os_ICBCore2[i].IsrC2ResourceStack = Os_ICBIsrC2ResourceStackCore2[i];
        }
#endif /* CFG_STD_RESOURCE_MAX_CORE2 > 0U */
        break;
#endif /* CFG_ISR_MAX_CORE2 > 0 */

#if (CFG_ISR_MAX_CORE3 > 0)
    case 3:
        Os_CfgIsrMax = CFG_ISR_MAX_CORE3;
        Os_CfgIsr2Max = CFG_ISR2_MAX_CORE3;
        Os_ICB = Os_ICBCore3;
        Os_ISR2Stack = Os_ISR2StackCore3;
        Os_IsrCfg = Os_IsrCfgCore3;
        Os_cfgIsr2IplMax = CFG_ISR2_IPL_MAX_CORE3;
#if (CFG_STD_RESOURCE_MAX_CORE3 > 0U)
        for (i = 0U; i < CFG_ISR2_MAX_CORE3; i++)
        {
            Os_ICBCore3[i].IsrC2ResourceStack = Os_ICBIsrC2ResourceStackCore3[i];
        }
#endif /* CFG_STD_RESOURCE_MAX_CORE3 > 0U */
        break;
#endif /* CFG_ISR_MAX_CORE3 > 0 */

#if (CFG_ISR_MAX_CORE4 > 0)
    case 4:
        Os_CfgIsrMax = CFG_ISR_MAX_CORE4;
        Os_CfgIsr2Max = CFG_ISR2_MAX_CORE4;
        Os_ICB = Os_ICBCore4;
        Os_ISR2Stack = Os_ISR2StackCore4;
        Os_IsrCfg = Os_IsrCfgCore4;
        Os_cfgIsr2IplMax = CFG_ISR2_IPL_MAX_CORE4;
#if (CFG_STD_RESOURCE_MAX_CORE4 > 0U)
        for (i = 0U; i < CFG_ISR2_MAX_CORE4; i++)
        {
            Os_ICBCore4[i].IsrC2ResourceStack = Os_ICBIsrC2ResourceStackCore4[i];
        }
#endif /* CFG_STD_RESOURCE_MAX_CORE4 > 0U */
        break;
#endif /* CFG_ISR_MAX_CORE4 > 0 */

#if (CFG_ISR_MAX_CORE5 > 0)
    case 5:
        Os_CfgIsrMax = CFG_ISR_MAX_CORE5;
        Os_CfgIsr2Max = CFG_ISR2_MAX_CORE5;
        Os_ICB = Os_ICBCore5;
        Os_ISR2Stack = Os_ISR2StackCore5;
        Os_IsrCfg = Os_IsrCfgCore5;
        Os_cfgIsr2IplMax = CFG_ISR2_IPL_MAX_CORE5;
#if (CFG_STD_RESOURCE_MAX_CORE5 > 0U)
        for (i = 0U; i < CFG_ISR2_MAX_CORE5; i++)
        {
            Os_ICBCore5[i].IsrC2ResourceStack = Os_ICBIsrC2ResourceStackCore5[i];
        }
#endif       /* CFG_STD_RESOURCE_MAX_CORE5 > 0U */
        break;
#endif       /* CFG_ISR_MAX_CORE5 > 0 */

    default: /*add comments to pass QAC.*/
        while (1)
        {
            /*nothing to do*/
        }
        break; /* PRQA S 2880 */ /* MISRA Rule 2.1 */
    }

    for (i = 0u; i < Os_CfgIsr2Max; i++)
    {
#if ((CFG_SPINLOCK_MAX > 0U) && (CFG_STD_RESOURCE_MAX > 0U))
        pICB = &Os_ICB[i];
        pICB->isr2CriticalZoneCount = 0u;
        for (j = 0u; j < CFG_CRITICAL_ZONE_MAX; j++)
        {
            pICB->isr2CriticalZoneStack[j] = OS_OBJECT_INVALID;
            pICB->isr2CriticalZoneType[j] = OBJECT_MAX;
        }
#endif /* (CFG_SPINLOCK_MAX > 0U) && (CFG_STD_RESOURCE_MAX > 0U) */

/* Init isr2 stack */
#if ((TRUE == CFG_STACK_CHECK) && (CFG_ISR2_MAX > 0U))
        Os_FillStack(Os_ISR2Stack[i]);
#endif /* (TRUE == CFG_STACK_CHECK) && (CFG_ISR2_MAX > 0U) */
    }
}
#endif /* CFG_ISR2_MAX > 0 */

/******************************************************************************/
/*
 * Brief                <disable all interrupts>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <StartOS and so on>
 * REQ ID               <DD_1_0659, DD_1_0661, DD_1_0660, DD_1_1248, DD_1_1493, DD_1_1494,
 *                       DD_1_1495>
 */
/******************************************************************************/
FUNC(void, OS_CODE) DisableAllInterrupts(void) /* PRQA S 1503 */ /* MISRA Rule 2.1 */
{
    OS_DAI_ENTRY();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
    if (OS_LEVEL_TASK == Os_SCB.sysOsLevel)
    {
        Os_SCB.sysRunningTCB->taskDisableAllCount = 1u;
    }
/*OS368*/
#if (CFG_ISR_MAX > 0)
    if (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel)
    {
        Os_ICB[Os_SCB.sysRunningIsrCat2Id].isrC2DisableAllCount = 1u;
    }
#endif /*CFG_ISR_MAX > 0*/
#endif /*(OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC)*/

/* Timing protection: resource lock. */
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
#if (CFG_ISR2_MAX > 0)
    if (TRUE == Os_SCB.sysInIsrCat2)
    {
        Os_ICB[Os_SCB.sysRunningIsrCat2Id].IsrC2IsrOpt = TP_DIS_ALL_INT;
        Os_TmProtIsrStart(Os_SCB.sysRunningIsrCat2Id, TP_ISR_CAT2_DIS_ALL_INT);
    }
    else
#endif /* #if (CFG_ISR2_MAX > 0) */
    {
        if (OS_LEVEL_TASK == Os_SCB.sysOsLevel)
        {
            Os_TCB[Os_SCB.sysRunningTaskID].taskIsrOpt = TP_DIS_ALL_INT;
            Os_TmProtTaskStart(Os_SCB.sysRunningTaskID, TP_TASK_DIS_ALL_INT);
        }
    }

    Os_ArchDisableAllInt_ButTimingProtInt();
#else
    Os_ArchSuspendInt(&Os_SaveAllInt);
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */

    OS_DAI_EXIT();
}

/******************************************************************************/
/*
 * Brief                <enable all interrupts>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <WaitEvent>
 * REQ ID               <DD_1_0656, DD_1_0658, DD_1_0657, DD_1_1249, DD_1_1496, DD_1_1497,
 *                       DD_1_1498>
 */
/******************************************************************************/
FUNC(void, OS_CODE) EnableAllInterrupts(void)
{
    OS_EAI_ENTRY();
    StatusType OsReturnErr = E_OK; /* PRQA S 2981 */ /* MISRA Rule 2.2 */

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
    if (OS_LEVEL_TASK == Os_SCB.sysOsLevel)
    {
        /*OS092*/
        if (Os_SCB.sysRunningTCB->taskDisableAllCount > 0u)
        {
            Os_SCB.sysRunningTCB->taskDisableAllCount = 0u;
        }
        else
        {
            OsReturnErr = E_NOT_OK; /* PRQA S 2983 */ /* MISRA Rule 2.2 */
        }
    }
#if (CFG_ISR_MAX > 0)
    else if (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel)
    {
        /*OS092, OS368*/
        if (Os_ICB[Os_SCB.sysRunningIsrCat2Id].isrC2DisableAllCount > 0u)
        {
            Os_ICB[Os_SCB.sysRunningIsrCat2Id].isrC2DisableAllCount = 0u;
        }
        else
        {
            OsReturnErr = E_NOT_OK; /* PRQA S 2983 */ /* MISRA Rule 2.2 */
        }
    }
#endif /*(CFG_ISR_MAX > 0)*/
    else
    {
        /*nothing to do*/
    }
#endif /*((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))*/

    if ((StatusType)E_OK == OsReturnErr)
    {
/* AutoSar SC2: Timing protection, resource lock. */
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
#if (CFG_ISR2_MAX > 0)
        if (TRUE == Os_SCB.sysInIsrCat2)
        {
            Os_ICB[Os_SCB.sysRunningIsrCat2Id].IsrC2IsrOpt = TP_OPT_BUTT;
            Os_TmProtIsrEnd(Os_SCB.sysRunningIsrCat2Id, TP_ISR_CAT2_DIS_ALL_INT);
        }
        else
#endif /* #if (CFG_ISR2_MAX > 0) */
        {
            if (OS_LEVEL_TASK == Os_SCB.sysOsLevel)
            {
                Os_TCB[Os_SCB.sysRunningTaskID].taskIsrOpt = TP_OPT_BUTT;
                Os_TmProtTaskEnd(Os_SCB.sysRunningTaskID, TP_TASK_DIS_ALL_INT);
            }
        }

        Os_ArchEnableAllInt_ButTimingProtInt();
#else
        Os_ArchRestoreInt(Os_SaveAllInt);
#endif /*TRUE == CFG_TIMING_PROTECTION_ENABLE*/
    }
    OS_EAI_EXIT();
}

/******************************************************************************/
/*
 * Brief                <resume all interrupts>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <SetRelAlarm and so on>
 * REQ ID               <DD_1_0662, DD_1_0664, DD_1_0663, DD_1_1251, DD_1_1502, DD_1_1503,
 *                       DD_1_1504>
 */
/******************************************************************************/
FUNC(void, OS_CODE) ResumeAllInterrupts(void)
{
    OS_RAI_ENTRY();
    StatusType OsReturnErr = E_OK; /* PRQA S 2981 */ /* MISRA Rule 2.2 */

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
    if (OS_LEVEL_TASK == Os_SCB.sysOsLevel)
    {
        /*OS092*/
        if (Os_SCB.sysRunningTCB->taskSuspendAllCount > 0u)
        {
            /*Os_SCB.sysRunningTCB->taskSuspendAllCount--*/
            Os_SCB.sysRunningTCB->taskSuspendAllCount = Os_SCB.sysRunningTCB->taskSuspendAllCount - 1u;
        }
        else
        {
            OsReturnErr = E_NOT_OK; /* PRQA S 2983 */ /* MISRA Rule 2.2 */
        }
    }
#if (CFG_ISR_MAX > 0)
    else if (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel)
    {
        /*OS092, OS368*/
        if (Os_ICB[Os_SCB.sysRunningIsrCat2Id].isrC2SuspendAllCount > 0u)
        {
            /*Os_ICB[Os_SCB.sysRunningIsrCat2Id].isrC2SuspendAllCount--*/
            Os_ICB[Os_SCB.sysRunningIsrCat2Id].isrC2SuspendAllCount =
                Os_ICB[Os_SCB.sysRunningIsrCat2Id].isrC2SuspendAllCount - 1u;
        }
        else
        {
            OsReturnErr = E_NOT_OK; /* PRQA S 2983 */ /* MISRA Rule 2.2 */
        }
    }
#endif /* (CFG_ISR_MAX > 0)*/
    else
    {
        /*nothing to do*/
    }
#endif /* ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))*/

    if ((StatusType)E_OK == OsReturnErr)
    {
/* AutoSar SC2: Timing protection, resource lock. */
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
#if (CFG_ISR2_MAX > 0)
        if (TRUE == Os_SCB.sysInIsrCat2)
        {
            Os_ICB[Os_SCB.sysRunningIsrCat2Id].IsrC2IsrOpt = TP_OPT_BUTT;
            Os_TmProtIsrEnd(Os_SCB.sysRunningIsrCat2Id, TP_ISR_CAT2_SUS_ALL_INT);
        }
        else
#endif /* #if (CFG_ISR2_MAX > 0) */
        {
            if (OS_LEVEL_TASK == Os_SCB.sysOsLevel)
            {
                Os_TCB[Os_SCB.sysRunningTaskID].taskIsrOpt = TP_OPT_BUTT;
                Os_TmProtTaskEnd(Os_SCB.sysRunningTaskID, TP_TASK_SUS_ALL_INT);
            }
        }

        /*Os_SuspendAllCount--*/
        Os_SuspendAllCount = Os_SuspendAllCount - 1u;
        if (0U == Os_SuspendAllCount)
        {
            Os_ArchEnableAllInt_ButTimingProtInt();
        }

#else

        /*Os_SuspendAllCount--*/
        Os_SuspendAllCount = Os_SuspendAllCount - 1u;
        if (0U == Os_SuspendAllCount)
        {
            Os_ArchRestoreInt(Os_SaveAllIntNested);
        }
#endif /*TRUE == CFG_TIMING_PROTECTION_ENABLE*/
    }
    OS_RAI_EXIT();
}

/******************************************************************************/
/*
 * Brief                <suspend all interrupts >
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <SetRelAlarm and so on>
 * REQ ID               <DD_1_0665, DD_1_0667, DD_1_0666, DD_1_1250, DD_1_1499, DD_1_1500,
 *                       DD_1_1501>
 */
/******************************************************************************/
FUNC(void, OS_CODE) SuspendAllInterrupts(void) /* PRQA S 1532,1503 */ /* MISRA Rule 8.7,2.1 */
{
    OS_SAI_ENTRY();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
    if (OS_LEVEL_TASK == Os_SCB.sysOsLevel)
    {
        /*Os_SCB.sysRunningTCB->taskSuspendAllCount++*/
        Os_SCB.sysRunningTCB->taskSuspendAllCount = Os_SCB.sysRunningTCB->taskSuspendAllCount + 1u;
    }
/*OS368*/
#if (CFG_ISR_MAX > 0)
    if (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel)
    {
        /*Os_ICB[Os_SCB.sysRunningIsrCat2Id].isrC2SuspendAllCount++*/
        Os_ICB[Os_SCB.sysRunningIsrCat2Id].isrC2SuspendAllCount =
            Os_ICB[Os_SCB.sysRunningIsrCat2Id].isrC2SuspendAllCount + 1u;
    }
#endif /*CFG_ISR_MAX > 0*/
#endif /*(OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC)*/

/* AutoSar SC2: Timing protection, resource lock. */
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
#if (CFG_ISR2_MAX > 0)
    if (TRUE == Os_SCB.sysInIsrCat2)
    {
        Os_ICB[Os_SCB.sysRunningIsrCat2Id].IsrC2IsrOpt = TP_SUS_ALL_INT;
        Os_TmProtIsrStart(Os_SCB.sysRunningIsrCat2Id, TP_ISR_CAT2_SUS_ALL_INT);
    }
    else
#endif /* #if (CFG_ISR2_MAX > 0) */
    {
        if (OS_LEVEL_TASK == Os_SCB.sysOsLevel)
        {
            Os_TCB[Os_SCB.sysRunningTaskID].taskIsrOpt = TP_SUS_ALL_INT;
            Os_TmProtTaskStart(Os_SCB.sysRunningTaskID, TP_TASK_SUS_ALL_INT);
        }
    }

    if (0U == Os_SuspendAllCount)
    {
        Os_ArchDisableAllInt_ButTimingProtInt();
    }
    Os_SuspendAllCount = Os_SuspendAllCount + 1u; /*Os_SuspendAllCount++*/

#else

    if (0U == Os_SuspendAllCount)
    {
        Os_ArchSuspendInt(&Os_SaveAllIntNested);
    }
    Os_SuspendAllCount = Os_SuspendAllCount + 1u; /*Os_SuspendAllCount++*/

#endif /*TRUE == CFG_TIMING_PROTECTION_ENABLE*/

    OS_SAI_EXIT();
}

/******************************************************************************/
/*
 * Brief                <resume os interrupts>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <None>
 * REQ ID               <DD_1_0668, DD_1_0670, DD_1_0669, DD_1_1253, DD_1_1508, DD_1_1509,
 *                       DD_1_1510>
 */
/******************************************************************************/
FUNC(void, OS_CODE) ResumeOSInterrupts(void)
{
    OS_ROI_ENTRY();
    StatusType OsReturnErr = E_OK; /* PRQA S 2981 */ /* MISRA Rule 2.2 */
#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */          /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */              /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                               /* TRUE == CFG_SRV_SHELLOS */

#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
    if (OS_LEVEL_TASK == Os_SCB.sysOsLevel)
    {
        /*OS092*/
        if (Os_SCB.sysRunningTCB->taskSuspendOSCount > 0u)
        {
            /*Os_SCB.sysRunningTCB->taskSuspendOSCount--*/
            Os_SCB.sysRunningTCB->taskSuspendOSCount = Os_SCB.sysRunningTCB->taskSuspendOSCount - 1u;
        }
        else
        {
            OsReturnErr = E_NOT_OK; /* PRQA S 2983 */ /* MISRA Rule 2.2 */
        }
    }
#if (CFG_ISR_MAX > 0)
    else if (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel)
    {
        /*OS092, OS368*/
        if (Os_ICB[Os_SCB.sysRunningIsrCat2Id].isrC2SuspendOSCount > 0u)
        {
            /*Os_ICB[Os_SCB.sysRunningIsrCat2Id].isrC2SuspendOSCount--*/
            Os_ICB[Os_SCB.sysRunningIsrCat2Id].isrC2SuspendOSCount =
                Os_ICB[Os_SCB.sysRunningIsrCat2Id].isrC2SuspendOSCount - 1u;
        }
        else
        {
            OsReturnErr = E_NOT_OK; /* PRQA S 2983 */ /* MISRA Rule 2.2 */
        }
    }
#endif /*#if (CFG_ISR_MAX > 0)*/
    else
    {
        /*nothing to do*/
    }
#endif /*#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))*/

    if ((StatusType)E_OK == OsReturnErr)
    {
/* AutoSar SC2: Timing protection, resource lock. */
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
#if (CFG_ISR2_MAX > 0)
        if (TRUE == Os_SCB.sysInIsrCat2)
        {
            Os_ICB[Os_SCB.sysRunningIsrCat2Id].IsrC2IsrOpt = TP_OPT_BUTT;
            Os_TmProtIsrEnd(Os_SCB.sysRunningIsrCat2Id, TP_ISR_CAT2_SUS_OS_INT);
        }
        else
#endif /* #if (CFG_ISR2_MAX > 0) */
        {
            if (OS_LEVEL_TASK == Os_SCB.sysOsLevel)
            {
                Os_TCB[Os_SCB.sysRunningTaskID].taskIsrOpt = TP_OPT_BUTT;
                Os_TmProtTaskEnd(Os_SCB.sysRunningTaskID, TP_TASK_SUS_OS_INT);
            }
        }

#endif                                              /*TRUE == CFG_TIMING_PROTECTION_ENABLE*/

        Os_SuspendOsCount = Os_SuspendOsCount - 1u; /*Os_SuspendOsCount--*/
        if (0U == Os_SuspendOsCount)
        {
            Os_ArchSetIpl(Os_SaveOsIntNested, OS_ISR_ENABLE);
        }
    }
    OS_ROI_EXIT();
}

/******************************************************************************/
/*
 * Brief                <suspend os interrupts>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <None>
 * REQ ID               <DD_1_0671, DD_1_0673, DD_1_0672, DD_1_1252, DD_1_1505, DD_1_1506,
 *                       DD_1_1507>
 */
/******************************************************************************/
FUNC(void, OS_CODE) SuspendOSInterrupts(void) /* PRQA S 1532,1503 */ /* MISRA Rule 8.7,2.1 */
{
    OS_SOI_ENTRY();
    OS_ARCH_DECLARE_CRITICAL();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
    if (OS_LEVEL_TASK == Os_SCB.sysOsLevel)
    {
        /*Os_SCB.sysRunningTCB->taskSuspendOSCount++*/
        Os_SCB.sysRunningTCB->taskSuspendOSCount = Os_SCB.sysRunningTCB->taskSuspendOSCount + 1u;
    }
/*OS368*/
#if (CFG_ISR2_MAX > 0)
    if (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel)
    {
        /*Os_ICB[Os_SCB.sysRunningIsrCat2Id].isrC2SuspendOSCount++*/
        Os_ICB[Os_SCB.sysRunningIsrCat2Id].isrC2SuspendOSCount =
            Os_ICB[Os_SCB.sysRunningIsrCat2Id].isrC2SuspendOSCount + 1u;
    }
#endif /*CFG_ISR_MAX > 0*/
#endif /*(OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC)*/

/* AutoSar SC2: Timing protection, resource lock. */
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
#if (CFG_ISR2_MAX > 0)
    if (TRUE == Os_SCB.sysInIsrCat2)
    {
        Os_ICB[Os_SCB.sysRunningIsrCat2Id].IsrC2IsrOpt = TP_SUS_OS_INT;
        Os_TmProtIsrStart(Os_SCB.sysRunningIsrCat2Id, TP_ISR_CAT2_SUS_OS_INT);
    }
    else
#endif /* #if (CFG_ISR2_MAX > 0) */
    {
        if (OS_LEVEL_TASK == Os_SCB.sysOsLevel)
        {
            Os_TCB[Os_SCB.sysRunningTaskID].taskIsrOpt = TP_SUS_OS_INT;
            Os_TmProtTaskStart(Os_SCB.sysRunningTaskID, TP_TASK_SUS_OS_INT);
        }
    }

#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */

    if (0U == Os_SuspendOsCount)
    {
        OS_ARCH_ENTRY_CRITICAL();
        Os_SaveOsIntNested = Os_ArchGetIpl();
        Os_ArchSetIpl(Os_cfgIsr2IplMax, OS_ISR_DISABLE);
        OS_ARCH_EXIT_CRITICAL();
    }

    Os_SuspendOsCount = Os_SuspendOsCount + 1u; /*Os_SuspendOsCount++*/

    OS_SOI_EXIT();
}

/********************************************************************/
/*
 * Brief                <GetISRID.>
 * Service ID           <None>
 * Sync/Async           <None>
 * Reentrancy           <yes>
 * param-eventId[in]    <Fatalerror>
 * Param-Name[out]      <ProtectionReturnType>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * REQ ID               <DD_1_0427, DD_1_0431, DD_1_0428, DD_1_0429, DD_1_1254, DD_1_1579,
 *                       DD_1_1660>
 */
/********************************************************************/
FUNC(ISRType, OS_CODE) GetISRID(void) /* PRQA S 1503 */ /* MISRA Rule 2.1 */
{
    ISRType osRet = OS_ISR_INVALID;
    OS_GII_ENTRY();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    if (Os_WrongContext(OS_CONTEXT_GET_ISR_ID) != TRUE)
    {
        osRet = OS_ISR_INVALID;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        osRet = OS_ISR_INVALID;
    }
    else
#endif /*#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)*/
    {
/* OS263. */
#if (CFG_ISR2_MAX > 0)
        if (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel)
        {
            if (OS_ISR_CATEGORY2 == Os_IsrCfg[Os_IntCfgIsrId].OsIsrCatType)
            {
                osRet = Os_IntCfgIsrId;
            }
        }
#endif /* #if (CFG_ISR2_MAX > 0) */
    }

    OS_GII_EXIT();
    return osRet;
}

#if (CFG_ISR2_MAX > 0)
/******************************************************************************/
/*
 * Brief                <enter ISR2>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <ISR>
 * REQ ID               <DD_1_0811, DD_1_0812, DD_1_1255, DD_1_1259, DD_1_1482>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_EnterISR2(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
#if ((TRUE == CFG_STACK_CHECK) && (CFG_ISR2_MAX > 0U))
    Os_StackPtrType StackPtr;
    if (0u == Os_IntNestISR2)
    {
        StackPtr = Os_SCB.sysRunningTCB->taskStackBottom;
        /*EnterISR2 from task.*/
        /* PRQA S 0488++ */                   /* MISRA Rule 18.4 */
        IF_STACK_CHECK_ENTER_ISR2_FORM_TASK() /* STACK CHEACK */
        /* PRQA S 0488-- */                   /* MISRA Rule 18.4 */
        {
#if (TRUE == CFG_ERRORHOOK)
            (void)Os_CallErrorHook(E_OS_STACKFAULT);
#endif
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
            (void)Os_CallProtectionHook(E_OS_STACKFAULT, OS_TMPROT_HOOK_TASK);
#else
            ShutdownOS(E_OS_STACKFAULT);
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */
        }
    }
    else
    {
        StackPtr = Os_ISR2Stack[Os_SCB.sysIsrNestQueue[Os_IntNestISR2 - 1U]].stackBottom;
        /*EnterISR2 from ISR2.*/
        /* PRQA S 0488++ */                   /* MISRA Rule 18.4 */
        IF_STACK_CHECK_ENTER_ISR2_FORM_ISR2() /* STACK CHECK */
        /* PRQA S 0488-- */                   /* MISRA Rule 18.4 */
        {
#if (TRUE == CFG_ERRORHOOK)
            (void)Os_CallErrorHook(E_OS_STACKFAULT);
#endif
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
            (void)Os_CallProtectionHook(E_OS_STACKFAULT, OS_TMPROT_HOOK_ISR);
#else
            ShutdownOS(E_OS_STACKFAULT);
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */
        }
    }
#endif /* #if (TRUE == CFG_STACK_CHECK && CFG_ISR2_MAX > 0U) */

#if (TRUE == CFG_INT_NEST_ENABLE)
    if (0U == Os_IntNestISR2)
    {
        Os_SaveLevel = Os_SCB.sysOsLevel;
        Os_SCB.sysOsLevel = OS_LEVEL_ISR2;
    }
#else
    Os_SaveLevel = Os_SCB.sysOsLevel;
    Os_SCB.sysOsLevel = OS_LEVEL_ISR2;
#endif /* #if (TRUE == CFG_INT_NEST_ENABLE) */

    Os_IntNestISR2 = Os_IntNestISR2 + 1u;
    Os_SCB.sysDispatchLocker = Os_SCB.sysDispatchLocker + 1u;

/* Timing protection for isr C2. */
#if (CFG_ISR2_MAX > 0)
    if (Os_IntCfgIsrId < Os_CfgIsrMax)
    {
        Os_SCB.sysIsrNestQueue[Os_IntNestISR2 - 1U] = Os_IntCfgIsrId;
        Os_SCB.sysRunningIsrCat2Id = Os_IntCfgIsrId;
        Os_SCB.sysInIsrCat2 = TRUE;

/*Writing the running ApplID and Object */
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
        Os_SCB.sysRunningAppID = Os_ObjectAppCfg[OBJECT_ISR][Os_SCB.sysRunningIsrCat2Id].hostApp;
        Os_SCB.sysRunningAppObj = OBJECT_ISR;
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */

#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
        Os_TmProtIsrStart(Os_IntCfgIsrId, TP_ISR_CAT2_EXE);
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */

/*if memory protection is configured*/
#if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
        if (Os_AppSysCfg != Os_SCB.sysRunningAppID)
        {
            /*Preparing to enter the ISR2 routine defined by user with its memory region table*/
            /*New ISR, defualt set register 2*/
            Os_ArchSetMemProtSet(0x02U);
            /* PRQA S 0404++ */ /* MISRA Rule 1.3,13.2 */
            Os_ArchSetIsrMemMap(
                Os_SCB.sysRunningIsrCat2Id,
                Os_SCB.sysRunningAppID,
                (uint32)Os_AppCfg[Os_SCB.sysRunningAppID].OsTrusted);
            /* PRQA S 0404-- */ /* MISRA Rule 1.3,13.2 */
        }
        else
        {
            /*SYS_APP, as OS kernel, have all access rights*/
            Os_ArchSetMemProtSet(0x00U);
        }
#endif /* TRUE == CFG_MEMORY_PROTECTION_ENABLE */
    }
#endif /* CFG_ISR2_MAX > 0 */

    return;
}

/******************************************************************************/
/*
 * Brief                <exit ISR2>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <ISR>
 * REQ ID               <DD_1_0813, DD_1_0814, DD_1_1256, DD_1_1260, DD_1_1486>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ExitISR2(void)
{
#if ((TRUE == CFG_INT_NEST_ENABLE) && (TRUE == CFG_MEMORY_PROTECTION_ENABLE))
    /*if memory protection is configured*/
    /*Preparing to enter the ISR2 outside with its memory region table*/
    Os_IsrType epilogueISR;
    Os_ApplicationType epilogueapp;
#endif /* (TRUE == CFG_INT_NEST_ENABLE) && (TRUE == CFG_MEMORY_PROTECTION_ENABLE) */

#if ((TRUE == CFG_STACK_CHECK) && (CFG_ISR2_MAX > 0U))
    Os_StackPtrType StackPtr;

    StackPtr = Os_ISR2Stack[Os_SCB.sysIsrNestQueue[Os_IntNestISR2 - 1U]].stackBottom;
    /* PRQA S 0488++ */        /* MISRA Rule 18.4 */
    IF_STACK_CHECK_EXIT_ISR2() /* STACK CHECK */
    /* PRQA S 0488-- */        /* MISRA Rule 18.4 */
    {
#if (TRUE == CFG_ERRORHOOK)
        (void)Os_CallErrorHook(E_OS_STACKFAULT);
#endif
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
        (void)Os_CallProtectionHook(E_OS_STACKFAULT, OS_TMPROT_HOOK_ISR);
#else
        ShutdownOS(E_OS_STACKFAULT);
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */
    }
#endif /* #if (TRUE == CFG_STACK_CHECK && CFG_ISR2_MAX > 0U) */

    /*Os_IntNestISR2--*/
    Os_IntNestISR2 = Os_IntNestISR2 - 1u;
    /*Os_SCB.sysDispatchLocker--*/
    Os_SCB.sysDispatchLocker = Os_SCB.sysDispatchLocker - 1u;

    /* Timing protection: stop counter for isr. */
    if (Os_SCB.sysRunningIsrCat2Id < CFG_ISR_MAX)
    {
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
        Os_TmProtIsrEnd(Os_SCB.sysRunningIsrCat2Id, TP_ISR_CAT2_EXE);
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */
    }

#if (TRUE == CFG_INT_NEST_ENABLE)
    if (0U == Os_IntNestISR2)
#endif /* #if (TRUE == CFG_INT_NEST_ENABLE) */
    {
        Os_SCB.sysInIsrCat2 = FALSE;

#if (CFG_SCHED_POLICY != OS_PREEMPTIVE_NON)
        if ((0U == Os_SCB.sysDispatchLocker)
            && ((Os_SCB.sysHighTaskID != Os_SCB.sysRunningTaskID)
/*bcc2 and ecc2*/
#if ((OS_BCC2 == CFG_CC) || (OS_ECC2 == CFG_CC))
                || (Os_SCB.sysRunningTCB->taskSelfActCount > 0u)
#endif /* bcc2 and ecc2 */
                    ))
#else  /* CFG_SCHED_POLICY == OS_PREEMPTIVE_NON */
        if ((OS_TASK_IDLE == Os_SCB.sysRunningTaskID) && (OS_TASK_IDLE != Os_SCB.sysHighTaskID))
#endif /* CFG_SCHED_POLICY != OS_PREEMPTIVE_NON */
        {
            Os_SCB.sysOsLevel = OS_LEVEL_TASK;
#if ((OS_BCC2 == CFG_CC) || (OS_ECC2 == CFG_CC))
            if (Os_SCB.sysRunningTCB->taskSelfActCount > 0u)
            {
                Os_SCB.sysRunningTCB->taskSelfActCount = Os_SCB.sysRunningTCB->taskSelfActCount - 1u;
            }
#endif /* ((OS_BCC2 == CFG_CC) || (OS_ECC2 == CFG_CC)) */
            Os_SwitchTask();
        }
        else
        {
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
            Os_SCB.sysRunningAppID = Os_ObjectAppCfg[OBJECT_TASK][Os_SCB.sysRunningTaskID].hostApp;
            Os_SCB.sysRunningAppObj = OBJECT_TASK;
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */

#if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
            if (Os_AppSysCfg != Os_SCB.sysRunningAppID)
            {
                Os_ArchSetMemProtSet(0x01U);
                /* PRQA S 0404++ */ /* MISRA Rule 1.3,13.2 */
                Os_ArchSetTaskMemMap(
                    Os_GetObjLocalId(Os_SCB.sysRunningTaskID),
                    Os_SCB.sysRunningAppID,
                    (uint32)Os_AppCfg[Os_SCB.sysRunningAppID].OsTrusted);
                /* PRQA S 0404-- */ /* MISRA Rule 1.3,13.2 */
            }
            else
            {
                /*SYS_APP, as OS kernel, have all access rights*/
                Os_ArchSetMemProtSet(0x00U);
            }
#endif /* TRUE == CFG_MEMORY_PROTECTION_ENABLE */
        }

#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
        Os_SCB.sysRunningAppID = Os_ObjectAppCfg[OBJECT_TASK][Os_SCB.sysRunningTaskID].hostApp;
        Os_SCB.sysRunningAppObj = OBJECT_TASK;
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */

        Os_SCB.sysOsLevel = Os_SaveLevel;
    }
#if (TRUE == CFG_INT_NEST_ENABLE)
    else
    {
        Os_SCB.sysRunningIsrCat2Id = Os_SCB.sysIsrNestQueue[Os_IntNestISR2 - 1U];
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
        /* IntNest: update sysRunningIsrCat2Id. */
        Os_SCB.sysRunningAppID = Os_ObjectAppCfg[OBJECT_ISR][Os_SCB.sysRunningIsrCat2Id].hostApp;
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */

#if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
        /*if memory protection is configured*/
        /*Preparing to enter the ISR2 outside with its memory region table*/
        epilogueISR = Os_SCB.sysRunningIsrCat2Id;
        epilogueapp = Os_SCB.sysRunningAppID;

        /*find pre ISR's PSW*/
        if (Os_AppSysCfg != epilogueapp)
        {
            Os_ArchSetMemProtSet(0x02U);
            /* PRQA S 0404++ */ /* MISRA Rule 1.3,13.2 */
            Os_ArchSetIsrMemMap(epilogueISR, epilogueapp, (uint32)Os_AppCfg[epilogueapp].OsTrusted);
            /* PRQA S 0404-- */ /* MISRA Rule 1.3,13.2 */
        }
        else
        {
            /*SYS_APP, as OS kernel, have all access rights*/
            Os_ArchSetMemProtSet(0x00U);
        }
#endif /* TRUE == CFG_MEMORY_PROTECTION_ENABLE */
    }
#endif /* TRUE == CFG_INT_NEST_ENABLE */

    return;
}
#endif /* #if (CFG_ISR2_MAX > 0) */

/******************************************************************************/
/*
 * Brief                <enter ISR1>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <ISR>
 * REQ ID               <DD_1_0815, DD_1_0816, DD_1_1257>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_EnterISR1(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
/* check stack overflow */
#if (TRUE == CFG_STACK_CHECK)
    Os_StackPtrType StackPtr;
    if (0u == Os_IntNestISR1)
    {
        if (0u == Os_IntNestISR2)
        {
            StackPtr = Os_SCB.sysRunningTCB->taskStackBottom;
            /*Enter ISR1 from task.*/
            /* PRQA S 0488++ */                   /* MISRA Rule 18.4 */
            IF_STACK_CHECK_ENTER_ISR1_FROM_TASK() /* STACK STACK */
            /* PRQA S 0488-- */                   /* MISRA Rule 18.4 */
            {
#if (TRUE == CFG_ERRORHOOK)
                (void)Os_CallErrorHook(E_OS_STACKFAULT);
#endif
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
                (void)Os_CallProtectionHook(E_OS_STACKFAULT, OS_TMPROT_HOOK_ISR);
#else
                ShutdownOS(E_OS_STACKFAULT);
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */
            }
        }
        else
        {
            /*Enter ISR1 from ISR2.*/
            StackPtr = Os_ISR2Stack[Os_SCB.sysIsrNestQueue[Os_IntNestISR2 - 1U]].stackBottom;
            /* PRQA S 0488++ */                   /* MISRA Rule 18.4 */
            IF_STACK_CHECK_ENTER_ISR1_FROM_ISR2() /* STACK CHECK */
            /* PRQA S 0488-- */                   /* MISRA Rule 18.4 */
            {
#if (TRUE == CFG_ERRORHOOK)
                (void)Os_CallErrorHook(E_OS_STACKFAULT);
#endif
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
                (void)Os_CallProtectionHook(E_OS_STACKFAULT, OS_TMPROT_HOOK_ISR);
#else
                ShutdownOS(E_OS_STACKFAULT);
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */
            }
        }
    }
    else
    {
        StackPtr = Os_SystemStack->stackBottom;
        /* Enter ISR1 from ISR1. */
        /* check system stack overflow */
        /* PRQA S 0488++ */                   /* MISRA Rule 18.4 */
        IF_STACK_CHECK_ENTER_ISR1_FROM_ISR1() /*STACK CHECK */
        /* PRQA S 0488-- */                   /* MISRA Rule 18.4 */
        {
#if (TRUE == CFG_ERRORHOOK)
            (void)Os_CallErrorHook(E_OS_STACKFAULT);
#endif
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
            (void)Os_CallProtectionHook(E_OS_STACKFAULT, OS_TMPROT_HOOK_ISR);
#else
            ShutdownOS(E_OS_STACKFAULT);
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */
        }
    }
#endif /* #if (TRUE == CFG_STACK_CHECK) */
}

/******************************************************************************/
/*
 * Brief                <exit ISR1>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <ISR>
 * REQ ID               <DD_1_0817, DD_1_0818, DD_1_1258>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ExitISR1(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
/* check system stack overflow. */
#if (TRUE == CFG_STACK_CHECK)
    Os_StackPtrType StackPtr;
    StackPtr = Os_SystemStack->stackBottom;
    /* PRQA S 0488++ */        /* MISRA Rule 18.4 */
    IF_STACK_CHECK_EXIT_ISR1() /* STACK CHECK */
    /* PRQA S 0488-- */        /* MISRA Rule 18.4 */
    {
#if (TRUE == CFG_ERRORHOOK)
        (void)Os_CallErrorHook(E_OS_STACKFAULT);
#endif
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
        (void)Os_CallProtectionHook(E_OS_STACKFAULT, OS_TMPROT_HOOK_ISR);
#else
        ShutdownOS(E_OS_STACKFAULT);
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */
    }
#endif /* #if (TRUE == CFG_STACK_CHECK) */
}

/******************************************************************************/
/*
 * Brief                <make the priority to ipl>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <prio:the priority value of one os object>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <IPL>
 * PreCondition         <None>
 * CallByAPI            <Os_ArchSetIpl>
 * REQ ID               <DD_1_0819, DD_1_0820>
 */
/******************************************************************************/
FUNC(Os_IPLType, OS_CODE) Os_PrioToIpl(Os_PriorityType prio)
{
    Os_IPLType Os_IPL;
    if (prio < (Os_CfgPriorityMax - 1u))
    {
        Os_IPL = 0u;
    }
    else
    {
        Os_IPL = prio - Os_CfgPriorityMax + 1u;
    }

    return Os_IPL;
}

/******************************************************************************/
/*
 * Brief                <make the ipl to priority >
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <ipl:interrupt priority level>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <the priority value>
 * PreCondition         <None>
 * CallByAPI            <GetResource and so on >
 * REQ ID               <DD_1_0821, DD_1_0822>
 */
/******************************************************************************/
FUNC(Os_PriorityType, OS_CODE) Os_IplToPrio(Os_IPLType ipl) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    return (Os_PriorityType)(ipl + Os_CfgPriorityMax - 1u);
}

#if (CFG_SPINLOCK_MAX > 0U)
/******************************************************************************/
/*
 * Brief                <resume os interrupts>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <None>
 * REQ ID               <>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_SpinlockResumeOsIsr(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Os_SuspendOsCount = Os_SuspendOsCount - 1u;                    /*Os_SuspendOsCount--*/
    if (0U == Os_SuspendOsCount)
    {
        Os_ArchSetIpl(Os_SaveOsIntNested, OS_ISR_ENABLE);
    }
}

/******************************************************************************/
/*
 * Brief                <suspend os interrupts>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <None>
 * REQ ID               <DD_1_0671, DD_1_0673, DD_1_0672, DD_1_1252, DD_1_1505, DD_1_1506,
 *                       DD_1_1507>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_SpinlockSuspendOsIsr(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    OS_ARCH_DECLARE_CRITICAL();
    if (0U == Os_SuspendOsCount)
    {
        OS_ARCH_ENTRY_CRITICAL();
        Os_SaveOsIntNested = Os_ArchGetIpl();
        Os_ArchSetIpl(Os_cfgIsr2IplMax, OS_ISR_DISABLE);
        OS_ARCH_EXIT_CRITICAL();
    }
    Os_SuspendOsCount = Os_SuspendOsCount + 1u; /*Os_SuspendOsCount++*/
}
#endif                                          /* CFG_SPINLOCK_MAX > 0U */

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
/*=======[E N D   O F   F I L E]==============================================*/
