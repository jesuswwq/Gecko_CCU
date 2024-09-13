/*============================================================================*/
/*  Copyright (C) 2016, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Os_Processor.c>
 *  @brief      <>
 *  
 * <Compiler: IAR    MCU:CYT2BX>
 *  
 *  @author     <bo.zeng>
 *  @date       <05-12-2014>
 */
/*============================================================================*/

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>    <AUTHOR>    <REVISION LOG>
 *  V0.1.0       2014-12-05  bo.zeng     Initial version.
 *  V0.2.0       2016-12-13  shi.shu     Multi-core Initial version.
 *  V0.3.0       2019-08-21  shun.li & zhiqiang.huang   Functional safety initial version.
 *  V1.0.0       2019-11-21  shun.li     Functional safety version.
 */
/*============================================================================*/

/*=======[M I S R A C  R U L E  V I O L A T I O N]============================*/
/*  <MESSAGE ID>    <CODE LINE>    <REASON>
 */
/*============================================================================*/

/*=======[I N C L U D E S]====================================================*/
#include "Os_Internal.h"

/*=======[M A C R O S]========================================================*/

/*=======[E X T E R N A L   D A T A]==========================================*/
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
P2VAR(volatile Os_TCBType  * volatile , OS_VAR, OS_VAR)       Os_RunningTCB = NULL_PTR;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
P2VAR(uint32, AUTOMATIC, OS_VAR)           Os_ArchTopStkPtr    = NULL_PTR;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
VAR(volatile uint32, OS_VAR)               Os_ArchSp           = 0U;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
VAR(volatile uint32, OS_VAR)               Os_IsrSp           = 0U;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
VAR(volatile uint32, OS_VAR)                Os_SysSp           = 0U;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
VAR(Os_ArchMsrType, OS_VAR)                   cpsr_isr;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
VAR(volatile uint32, OS_VAR)               Os_TpTrusted        = 0U;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
P2VAR(Os_TaskCBExtType, AUTOMATIC, OS_VAR) Os_TaskCBExt        = NULL_PTR;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
P2CONST(OS_ISR_ADDR, AUTOMATIC, OS_VAR)    Os_IsrDAddr         = NULL_PTR;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
P2VAR(uint32, AUTOMATIC, OS_VAR)	   Os_IsrNestPcxStack  = NULL_PTR;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
P2CONST(OS_TASK_ADDR, AUTOMATIC, OS_VAR)   Os_TaskDAddr        = NULL_PTR;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

/*=======[I N T E R N A L   D A T A]==========================================*/
#if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_TaskCBExtType, OS_VAR)   Os_TaskCBExtCore0[CFG_TASK_MAX_CORE0] = {0};
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif

#if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_TaskCBExtType, OS_VAR)   Os_TaskCBExtCore1[CFG_TASK_MAX_CORE1] = {0};
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif

#if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_TaskCBExtType, OS_VAR)   Os_TaskCBExtCore2[CFG_TASK_MAX_CORE2] = {0};
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif

#if (CFG_ISR_MAX > 0U)
#if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(uint32, OS_VAR)             Os_IsrNestPcxStackCore0[CFG_ISR_MAX_CORE0] = {0};
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif

#if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(uint32, OS_VAR)             Os_IsrNestPcxStackCore1[CFG_ISR_MAX_CORE1] = {0};
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif

#if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(uint32, OS_VAR)             Os_IsrNestPcxStackCore2[CFG_ISR_MAX_CORE2] = {0};
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
VAR(uint8, OS_VAR)              Os_IntNestISR1   = 0U;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
VAR(uint8, OS_VAR)              Os_IntNestISR2   = 0U;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
VAR(Os_CallLevelType, OS_VAR)   Os_SaveLevelISR1 = OS_LEVEL_ISR1;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#endif


#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
VAR(volatile uint32, OS_VAR)                   Os_TprotTerminateIsr = FALSE;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#endif

#if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
VAR(uint32, OS_VAR)                            Os_PSW_PRS = 0u;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#endif

#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(uint32, OS_VAR)   MpuRegionSize[] = 
{
    /* obyte, 32byte, 64byte, 128byte, 256byte, 512byte, 1KB */
    0u, 32u, 64u, 128u, 256u, 512u, 1024,
    /* 2KB, 4KB, 8KB, 16KB, 32KB */
    2048u, 4096u, 8192, 16384u, 32768u, 
    /* 64KB, 128KB, 256KB, 512KB, 1MB */
    65536u, 131072u, 262144u, 524288u, 1048576u,
    /* 2MB, 4MB, 8MB, 16MB*/
    2097152u, 4194304u, 8388608u, 16777216u, 
    /* 32MB, 64MB, 128MB, 256MB */
    33554432u, 67108864u, 134217728u, 268435456u,
    /* 512MB, 1GB, 2GB, 4GB */
    536870912u, 1073741824u, 2147483648u, 4294967295u
};

CONST(uint32, OS_VAR)   MpuRegionBitMap[] =
{
     /*obyte, 32byte, 64byte, 128byte, 256byte */
    0u, MPU_SIZE_32B, MPU_SIZE_64B, MPU_SIZE_128B, MPU_SIZE_256B,
    /* 512byte, 1KB, 2KB, 4KB */
    MPU_SIZE_512B, MPU_SIZE_1KB, MPU_SIZE_2KB, MPU_SIZE_4KB,
    /* 8KB, 16KB, 32KB, 64KB */
    MPU_SIZE_8KB, MPU_SIZE_16KB, MPU_SIZE_32KB, MPU_SIZE_64KB,
    /* 128KB, 256KB, 512KB, 1MB */
    MPU_SIZE_128KB, MPU_SIZE_256KB, MPU_SIZE_512KB, MPU_SIZE_1MB,
    /* 2MB, 4MB, 8MB, 16MB */
    MPU_SIZE_2MB, MPU_SIZE_4MB, MPU_SIZE_8MB, MPU_SIZE_16MB,
    /* 32MB, 64MB, 128MB, 256MB */
    MPU_SIZE_32MB, MPU_SIZE_64MB, MPU_SIZE_128MB, MPU_SIZE_256MB,
    /* 512MB, 1GB, 2GB, 4GB */
    MPU_SIZE_512MB, MPU_SIZE_1GB, MPU_SIZE_2GB, MPU_SIZE_4GB
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
#endif

/*=======[I N T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/

#if ((CFG_OSAPPLICATION_MAX > 0) && (CFG_ISR_MAX > 0) && (TRUE == CFG_INT_NEST_ENABLE))
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
static FUNC(StatusType, OS_CODE) Os_ArchTerminateOneNestIsr(Os_IsrType OsIsrID);
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#endif

/*=======[F U N C T I O N   I M P L E M E N T A T I O N S]====================*/
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/******************************************************************************/
/*
 * Brief                <Initialize the multicore processor>
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * param[in]            <None>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <StartOS>
 * REQ ID               <DD_1_0713, DD_1_0714>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_MultiCoreInitProcessor(void)
{
    switch (Os_SCB.sysCore)
    {
        #if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
        case 0:
            Os_TaskCBExt            = Os_TaskCBExtCore0;
            Os_IsrNestPcxStack		= Os_IsrNestPcxStackCore0;
            #if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
            Os_IsrDAddr             = Os_Isr_DAddr_Core0;
            Os_TaskDAddr            = Os_Task_DAddr_Core0;
            #endif /* TRUE == CFG_MEMORY_PROTECTION_ENABLE */
            break;
        #endif
        #if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
        case 1:
            Os_TaskCBExt            = Os_TaskCBExtCore1;
            Os_IsrNestPcxStack		= Os_IsrNestPcxStackCore1;
            #if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
            Os_IsrDAddr             = Os_Isr_DAddr_Core1;
            Os_TaskDAddr            = Os_Task_DAddr_Core1;
            #endif /* TRUE == CFG_MEMORY_PROTECTION_ENABLE */
            break;
        #endif
        #if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
        case 2:
            Os_TaskCBExt            = Os_TaskCBExtCore2;
            Os_IsrNestPcxStack		= Os_IsrNestPcxStackCore2;
            #if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
            Os_IsrDAddr             = Os_Isr_DAddr_Core2;
            Os_TaskDAddr            = Os_Task_DAddr_Core2;
            #endif /* TRUE == CFG_MEMORY_PROTECTION_ENABLE */
            break;
        #endif
            
        /*add comments to pass QAC.*/
        default:
            while (1) { ; }
            break;
    }
}

/******************************************************************************/
/*
 * Brief                <Ipl greater than 0, disable interrupt otherwise enable
 *                       interrupt>
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <ipl>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <ResumeOSInterrupts and so on>
 * REQ ID               <DD_1_0715, DD_1_0716>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ArchSetIpl(Os_IPLType ipl, Os_IsrDescriptionType isrdesc)
{
    (void)isrdesc;

    OS_ARCH_DECLARE_CRITICAL();
    if (OS_ISR_DISABLE == isrdesc)
    {
        OS_ARCH_ENTRY_CRITICAL();
        Os_MaskIrqPiroThreshold(ipl);
        OS_ARCH_EXIT_CRITICAL();
    }
    else
    {
        OS_ARCH_ENTRY_CRITICAL();
        Os_UnMaskIrqPiroThreshold(ipl);
        OS_ARCH_EXIT_CRITICAL();
    }
}

/******************************************************************************/
/*
 * Brief                <get the IPL>
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <0>
 * PreCondition         <None>
 * CallByAPI            <SuspendOSInterrupts and so on>
 * REQ ID               <DD_1_0717, DD_1_0718,DD_1_1299>
 */
/******************************************************************************/
FUNC(Os_IPLType, OS_CODE) Os_ArchGetIpl(void)
{
    int i = 0;
    uint16 saveipl = 0;
    OS_ARCH_DECLARE_CRITICAL();
    OS_ARCH_ENTRY_CRITICAL();

    saveipl = readl(OS_VICSWPRIORITYMASK);
    for(i = 0; i < 16; i++)
    {
        if(saveipl & (0x8000 >> i)){
            break;
        }
    }

    OS_ARCH_EXIT_CRITICAL();

    return i;
}

/******************************************************************************/
/*
 * Brief                <Save ccr to variable msr and disable maskable interrupt>
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <SuspendAllInterrupts>
 * REQ ID               <DD_1_0719, DD_1_0720, DD_1_1300>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ArchSuspendInt
(
    P2VAR(Os_ArchMsrType, AUTOMATIC, OS_VAR) msr
)
{
    uint32 cpsr;
    ASM volatile("mrs   %0, cpsr" : "=r" (cpsr));
    ASM("cpsid I");
    *msr = cpsr;
}

/******************************************************************************/
/*
 * Brief                <transfer variable msr back to ccr>
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <ResumeAllInterrupts>
 * REQ ID               <DD_1_0721, DD_1_0722, DD_1_1301>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ArchRestoreInt(Os_ArchMsrType msr)
{
    Os_RestoreIrq(msr);
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/******************************************************************************/
/*
 * Brief                <first entry task>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_SwitchTask>
 * REQ ID               <DD_1_0723, DD_1_0724, DD_1_1306>
 */
/******************************************************************************/
#if ((OS_NOSC == CFG_SC) || (OS_SC1 == CFG_SC) || (OS_SC2 == CFG_SC))
FUNC(void, OS_CODE) Os_ArchFirstEnterTask(void)
{
    Os_StackPtrType  p_stk;
    p_stk=Os_SCB.sysRunningTCB->taskTop;

    *--Os_SCB.sysRunningTCB->taskTop  = (uint32)Os_TaskCfg[Os_SCB.sysRunningTaskID].osTaskEntry+( uint32 ) 0x04 ; /* Entry Point */
    *--Os_SCB.sysRunningTCB->taskTop  = (uint32)Os_TaskErrBack;                        /* R14 (LR) */
    *--Os_SCB.sysRunningTCB->taskTop  = (uint32)(p_stk);
    Os_SCB.sysRunningTCB->taskTop-=13;
    *--Os_SCB.sysRunningTCB->taskTop  = (uint32)0x4000001f;//0x600001f3

#ifdef CFG_ARCH_FPU
    *(--Os_SCB.sysRunningTCB->taskTop)  = (uint32)0x0;
    Os_SCB.sysRunningTCB->taskTop-=32;
#endif
}
#else
FUNC(void, OS_CODE) Os_ArchFirstEnterTask(void)
{
    Os_StackPtrType  p_stk;
    Os_SCB.sysRunningTCB->taskTop -= 10U;
    p_stk=Os_SCB.sysRunningTCB->taskTop;

    *--Os_SCB.sysRunningTCB->taskTop  = (uint32)Os_TaskCfg[Os_SCB.sysRunningTaskID].osTaskEntry+( uint32 ) 0x04 ; /* Entry Point */
    *--Os_SCB.sysRunningTCB->taskTop  = (uint32)Os_TaskErrBack;                        /* R14 (LR) */
    *--Os_SCB.sysRunningTCB->taskTop  = (uint32)(p_stk);
    Os_SCB.sysRunningTCB->taskTop-=13;
#if (CFG_SRV_SHELLOS == TRUE)
    if (FALSE == Os_AppCfg[Os_SCB.sysRunningAppID].OsTrusted)
    {
       *--Os_SCB.sysRunningTCB->taskTop  = (uint32)0x40000010;
    }
    else
    {
        *--Os_SCB.sysRunningTCB->taskTop  = (uint32)0x4000001f;//0x40000013
    }

#else
    *--Os_SCB.sysRunningTCB->taskTop  = (uint32)0x8000031F;
#endif

#ifdef CFG_ARCH_FPU
    *(--Os_SCB.sysRunningTCB->taskTop)  = (uint32)0x0;
    Os_SCB.sysRunningTCB->taskTop-=32;
#endif
}
#endif /* (OS_NOSC == CFG_SC) || (OS_SC1 == CFG_SC) || (OS_SC2 == CFG_SC) */

/*****************************************************************************/
/*
 * Brief                <do_dispatch>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <>
 */
/*****************************************************************************/
void do_dispatch(void)
{
    Os_ArchSwitch2System();
    Os_SwitchTask();
    Os_StartUpResumeContext();
}

#if (CFG_SRV_SHELLOS == TRUE)
/*****************************************************************************/
/*
 * Brief                <Os_ArchSyscall>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <>
 */
/*****************************************************************************/
FUNC(void, OS_CODE) Os_ArchSyscall(void)
{
	ASM
	(
		" svc 0					            \n"
		" nop					            \n"
	);
}
#endif /* CFG_SRV_SHELLOS == TRUE */

/******************************************************************************/
/*
 * Brief                <Os_ArchStartScheduler>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <StartOS>
 * REQ ID               <DD_1_0727, DD_1_0728>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ArchStartScheduler(void)
{  
    Os_RunningTCB = &Os_SCB.sysRunningTCB;
    Os_SwitchTask();
    Os_StartUpResumeContext();
}

#define OS_START_SEC_CODE
#include "Os_MemMap.h"

/******************************************************************************/
/*
 * Brief                <Os_ArchInitCPU>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <StartOS>
 * REQ ID               <DD_1_0732, DD_1_0733>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ArchInitCPU(void)
{
    Os_InterruptInit();
    Os_ArchInitIntPrio();
    
    #if (TRUE == CFG_SYSTEM_TIMER_ENABLE)
    Os_ArchInitSystemTimer();
    #endif /* #if (TRUE == CFG_SYSTEM_TIMER_ENABLE) */

    #if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
    Os_ArchInitTimingProtTimer();
    #endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */
    
    Os_ModeSpInit();
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

/*****************************************************************************/
/*
 * Brief                <PendSV_Handler>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_PreTask>
 */
/*****************************************************************************/
FUNC(void, OS_CODE) Os_SWI_Handler(void)
{
    Os_ArchSwitch2System();
    #if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
    Os_ArchSetTruReg();
    #endif /* ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC)) */
    Os_SwitchTask();
    Os_ArchResumeContext();
}

#if (TRUE == CFG_SYSTEM_TIMER_ENABLE)
/******************************************************************************/
/*
 * Brief                <Clear isr flag in systick isr.>
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * param[in]            <None>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <>
 * REQ ID               <>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_SystickIsrClearFlag(void)
{
    if(Os_SCB.sysCore == 0){
        sdrv_btm_hw_set_int_sta(0xf0420000u, (0x01 << 2));
        //sdrv_btm_hw_sw_rst(0xf0420000u, 0);
    }
    else if(Os_SCB.sysCore == 1){
        sdrv_btm_hw_set_int_sta(0xf0430000u, (0x01 << 2));
        // sdrv_btm_hw_sw_rst(0xf0430000u, 0);
    }
    else if(Os_SCB.sysCore == 2){
        sdrv_btm_hw_set_int_sta(0xf0440000u, (0x01 << 2));
        //sdrv_btm_hw_sw_rst(0xf0440000u, 0);
    }
}
#endif /* TRUE == CFG_SYSTEM_TIMER_ENABLE */

#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
/******************************************************************************/
/*
 * Brief                <Clear isr flag in systick isr.>
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * param[in]            <None>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <>
 * REQ ID               <>
 */
/******************************************************************************/
void Os_TimeProtClearFlag(void)
{
    if(Os_SCB.sysCore == 0){
        sdrv_btm_hw_set_int_sta(0xf0450000u, (0x01 << 2));
        sdrv_btm_hw_sw_rst(0xf0450000u, 0);
    }
    else if(Os_SCB.sysCore == 1){
        sdrv_btm_hw_set_int_sta(0xf0460000u, (0x01 << 2));
        sdrv_btm_hw_sw_rst(0xf0460000u, 0);
    }
    else if(Os_SCB.sysCore == 2){
        sdrv_btm_hw_set_int_sta(0xf0470000u, (0x01 << 2));
        sdrv_btm_hw_sw_rst(0xf0470000u, 0);
    }
}
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */
#define OS_START_SEC_CODE
#include "Os_MemMap.h"

#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
#if (CFG_ISR_MAX > 0)
/******************************************************************************/
/*
 * Brief                <TryToGetSpinlock has the same functionality as GetSpinlock with the difference
                         that if the spinlock is already occupied by a TASK on a different core the function
                         sets the OUT parameter "Success" and returns with E_OK>
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * param[in]            <None>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <TerminateApplication>
 * REQ ID               <DD_1_1076>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ArchDisableIntInApp
(
    P2CONST(Os_ApplicationCfgType, AUTOMATIC, OS_VAR) posCurAppCfg
)
{   
    uint16     i;
    uint16     osIsrRefCnt;
    Os_IsrType osIsrId;
    uint32     osIsrRegVal;
    
    osIsrRefCnt = posCurAppCfg->OsAppIsrRefCnt;
    for (i = 0u; i < osIsrRefCnt; i++)
    {
        osIsrId = posCurAppCfg->OsAppObjectRef[OBJECT_ISR][i];
        osIsrRegVal  = Os_IsrCfg[Os_GetObjLocalId(osIsrId)].OsIsrSrc;
        OS_INTERRUPT_CLEAR_PENDING(osIsrRegVal);
        OS_INTERRUPT_DISABLE(osIsrRegVal);
    }
}

#if (TRUE == CFG_INT_NEST_ENABLE)
/******************************************************************************/
/*
 * Brief                <Terminate an interrupt>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * param[in]            <OsIsrID>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <StatusType>
 * CallByAPI            <Os_ArchAppTerminateIsrProc>
 * REQ ID               <DD_1_0901>
 */
/******************************************************************************/
static FUNC(StatusType, OS_CODE) Os_ArchTerminateOneNestIsr(Os_IsrType OsIsrID)
{
    uint8 i;
    StatusType Status = E_OK;
    for (i = 0u; i < Os_IntNestISR2; i++)
    {
        /* find out the Isr nested position and reclaim its context saving area */
        if (OsIsrID == Os_SCB.sysIsrNestQueue[i])
        {
            /* Reclaim csa list used by this isr. */
            /* if OsIsrChkindex == Os_IntNestISR2, the isr is the innermost_isr,
             * can not reclaim csas here */
            break;
        }
    }

    /* Not find out the Isr Id in the IsrStack from the SCB,
        * not include outermost_isr. */
    if (i >= Os_IntNestISR2)
    {
        Status = E_NOT_OK;
    }
    else
    {
        /* Moving the following nested ISR2s to shift one position left */
        while (i < (Os_IntNestISR2 - 1u))
        {
            Os_SCB.sysIsrNestQueue[i] = Os_SCB.sysIsrNestQueue[i + 1u];

            if (i < (Os_IntNestISR2 - 2u))
            {
                Os_IsrNestPcxStack[i + 1u] = Os_IsrNestPcxStack[i + 2u];
            }

            i++;
        }
    }

    return Status;
}

/* Terminate Isr2 platform process in TerminateApplication */
/******************************************************************************/
/*
 * Brief                <Terminate the ISR objects of the calling application>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * param[in]            <OsIsrID>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <Os_TerminateISRObjectHandler>
 * REQ ID               <DD_1_1077>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ArchAppTerminateIsrProc(Os_IsrType OsIsrID)
{
    uint32 ulRet = E_OK;

    /* Isr_nest process. */
    /* Just find out the nested corresponding ISR2s(excluding the running one) */
    if (OsIsrID != Os_SCB.sysRunningIsrCat2Id)
    {
        /* Terminate one isr */
        ulRet = Os_ArchTerminateOneNestIsr(OsIsrID);
        if ((uint32)E_OK == ulRet)
        {
            if (Os_IntNestISR2 > 0u)
            {
                Os_IntNestISR2--;
            }

            if (Os_SCB.sysDispatchLocker > 0u)
            {
                /*Os_SCB.sysDispatchLocker--*/
                Os_SCB.sysDispatchLocker = Os_SCB.sysDispatchLocker - 1u;
            }
        }
    }

    return;
}
#endif     /* TRUE == CFG_INT_NEST_ENABLE */
#endif     /* #if (CFG_ISR_MAX > 0) */

/* TerminateTask arch_process in TerminateApplication. */
/******************************************************************************/
/*
 * Brief                <TerminateTask arch_process in TerminateApplication>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * param[in]            <None>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <Os_TerminateTaskObjectHandler>
 * REQ ID               <DD_1_1078>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ArchAppTerminateTaskProc(Os_TaskType OsTaskID)
{
    if ((OS_LEVEL_TASK == Os_SCB.sysOsLevel) ||
        ((OS_LEVEL_ERRORHOOK_APP == Os_SCB.sysOsLevel) && (TRUE != Os_SCB.sysInIsrCat2)))
    {
        /* If TerminateApplication is called by task or isr2 or app_error_hook,
         * the csa of running task is reclaimed in the dispatcher at the end of TerminateApplication. */
        if (OsTaskID != Os_SCB.sysRunningTaskID)
        {
            /* nothing to do. */
        }
    }
    else
    {
       /* nothing to do. */
    }

    return;
}

#endif /* #if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC)) */
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

/*=======[E X C I P T I O N]==================================================*/
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
#include <Platform_Types.h>
/* For memory protection. */
#if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
/******************************************************************************/
/*
 * Brief                <Set the memory protection properties>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * param[in]            <MpSetIdx>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <Os_ArchInitKnMemMap and so on>
 * REQ ID               <DD_1_0752, DD_1_0753>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ArchSetMemProtSet(uint32 MpSetIdx)
{
    Os_PSW_PRS = MpSetIdx << 12u;
    if (0x00 == MpSetIdx)
    {
       Os_ArchSetTruReg();
    }
}
/******************************************************************************/
/*
 * Brief                <Gets the memory protection property>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * param[in]            <None>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <Os_ArchSetIsrMemMap,Os_ArchSetTaskMemMap>
 * REQ ID               <DD_1_0754, DD_1_0755>
 */
/******************************************************************************/
FUNC(uint32, OS_CODE) Os_ArchGetMemProtSet(void)
{
    return Os_PSW_PRS;
}
/******************************************************************************/
/*
 * Brief                <Initialize memory protection related registers>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * param[in]            <None>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <Os_SwitchTask,Os_InitMemProt>
 * REQ ID               <DD_1_0756, DD_1_0757>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ArchInitKnMemMap(void)
{
    /*P2CONST(Os_MemProtKnCfgType, AUTOMATIC, OS_VAR) pKnMemMap;

    Os_Kernel default protect whole ram and rom.
    pKnMemMap = &Os_MemProtKnAddrCfg;*/
    Os_ArchSetTruReg();
    return;
}

/******************************************************************************/
/*
 * Brief                <Os_ArchSetIsrMemMap>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <Os_EnterISR2,Os_ExitISR2>
 * REQ ID               <DD_1_0758, DD_1_0759, DD_1_1308, DD_1_1309, DD_1_1310>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ArchSetIsrMemMap
(
    ISRType         IsrId, 
    ApplicationType HostAppId, 
    uint32          isTrusted
)
{
    CoreIdType coreId;
    uint32 temp = (Os_ArchGetMemProtSet() & 0x00003000U) >> 12u;
    
    coreId = Os_SCB.sysCore;

    /* Find out which register set in use  register 0 should not be used here */
    if (0x02U == temp)
    {
        /*set 2: OS_DPR_7~OS_DPR_12, OS_CPR_4~OS_CPR_6*/
        if (TRUE != isTrusted) /* Non-trusted app running. */
        {
            Os_ArchSetNonTruIsrReg(IsrId, HostAppId);
        }
        else  /* Trusted app or os_kernel running. */
        {
            /*OSTrustedApplicationWithProtection != TRUE*/
            if (Os_AppCfg[HostAppId].OsTrustedAppWithProtection != TRUE)
            {
                Os_ArchSetTruReg();
            }
            else
            {
                Os_ArchSetTruIsrProtReg(IsrId, HostAppId);
            }
        }
    }
    else
    {
        #if (TRUE == CFG_PROTECTIONHOOK)
        (void)Os_CallProtectionHook(E_OS_PROTECTION_MEMORY,
                OS_TMPROT_HOOK_OSAPP);
        #endif /* TRUE == CFG_PROTECTIONHOOK */
    }

    return;
}

/******************************************************************************/
/*
 * Brief                <MemMap for Memory Protection Settings Task>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <Os_ExitISR2, Os_SwitchTask>
 * REQ ID               <DD_1_0760, DD_1_0761, DD_1_1311, DD_1_1312, DD_1_1313>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ArchSetTaskMemMap
(
    TaskType        TaskId, 
    ApplicationType HostAppId, 
    uint32          isTrusted
)
{
    CoreIdType coreId;
    uint32 temp = (Os_ArchGetMemProtSet() & 0x00003000U) >> 12u;

    coreId = Os_SCB.sysCore;

    /* Find out which register set in use  register 0 should not be used here */
    if (0x01U == temp)
    {
        if (TRUE != isTrusted) /* Non-trusted app running. */
        {
            Os_ArchSetNonTruTskReg(TaskId, HostAppId);
        }
        else  /* Trusted app or os_kernel running. */
        {
            /*OSTrustedApplicationWithProtection != TRUE*/
            if (Os_AppCfg[HostAppId].OsTrustedAppWithProtection != TRUE)
            {
                Os_ArchSetTruReg();
            }
            else
            {
                Os_ArchSetTruTskProtReg(TaskId, HostAppId);
            }
        }
    }
    else
    {
        #if (TRUE == CFG_PROTECTIONHOOK)
        (void)Os_CallProtectionHook(E_OS_PROTECTION_MEMORY, OS_TMPROT_HOOK_OSAPP);
        #endif /* TRUE == CFG_PROTECTIONHOOK */
    }

    return;
}
#endif /* TRUE == CFG_MEMORY_PROTECTION_ENABLE */

/******************************************************************************/
/*
 * Brief                <OS_ShutdownAllCores is not provide user>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * param[in]            <None>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <GetSpinlock and so on>
 * REQ ID               <DD_1_1079>
 */
/******************************************************************************/
uint32 Os_CmpSwapW(uint32* address, uint32 compareVal, uint32 exchangedVal)
{
    uint32 lockstatus;
    uint32 ret = 1;

    OS_ARCH_DECLARE_CRITICAL();
    OS_ARCH_ENTRY_CRITICAL();
    lockstatus = semphore_try_lock(MAILBOX,6);
    if(lockstatus == 1)
    {
        if(*address == compareVal)
        {
            *address = exchangedVal;
            while(*address != exchangedVal);
            ret = 0;
        }
        semphore_unlock(MAILBOX,6);
    }
    OS_ARCH_EXIT_CRITICAL();
    return ret;
}

/******************************************************************************/
/*
 * Brief                <Os_GetCpuID_Regs>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * Return               <CoreId>
 * PreCondition         <None>
 * CallByAPI            <GetCoreID>
 * REQ ID               <DD_1_0763, DD_1_0764>
 */
/******************************************************************************/
FUNC(Os_CoreIdType, OS_CODE) Os_GetCpuID_Regs(void)
{
  
    VAR( uint8, AUTOMATIC ) retVal = (uint8)0;

    return retVal;
}
static const uint32 core_mapping[CPU_ID_MAX] = {CPU_ID_SF, CPU_ID_SP0, CPU_ID_SP1, CPU_ID_SX0, CPU_ID_SX1};
/******************************************************************************/
/*
 * Brief                <Os_ArchGetCoreID>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * Return               <CoreId>
 * PreCondition         <None>
 * CallByAPI            <GetCoreID>
 * REQ ID               <DD_1_0763, DD_1_0764>
 */
/******************************************************************************/
FUNC(Os_CoreIdType, OS_CODE) Os_ArchGetCoreID(void)
{
    // return ((Os_CoreIdType)Mcu_GetCoreID());
    return core_mapping[arch_get_cpuid()];
}

/******************************************************************************/
/*
 * Brief                <Os_ArchStartCore>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-coreId[in]     <selects the core which to start>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <StartCore>
 * REQ ID               <DD_1_0765, DD_1_0766>
 */
/******************************************************************************/
extern unsigned long VECTOR_TBL_BASE[];
FUNC(void, OS_CODE) Os_ArchStartCore(Os_CoreIdType coreId)
{
    switch (coreId)
    {
    case 0:
        break;
    case 1:
         Mcu_SocKickCore(KICK_CR5_SX0, (uint32)VECTOR_TBL_BASE);
        break;
    case 2:
         Mcu_SocKickCore(KICK_CR5_SX1, (uint32)VECTOR_TBL_BASE);
        break;
    
    default:
        break;
    }
    
}

/******************************************************************************/
/*
 * Brief                <Get the Core Mode>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-core[in]       <selects the core which to get mode>
 * Return               <Os_CoreModeType,the core mode>
 * PreCondition         <None>
 * CallByAPI            <Os_SetCoreMode>
 * REQ ID               <DD_1_0767, DD_1_0768>
 */
/******************************************************************************/
FUNC(Os_CoreModeType, OS_CODE) Os_GetCoreMode(Os_CoreIdType core)
{
    return Os_CoreCB.coreStatus[Os_SCB.sysCore];
}

/******************************************************************************/
/*
 * Brief                <Set the Core Mode>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-core[in]       <Selects the core which mode is set>
 * Return               <boolean,the result of setting>
 * PreCondition         <None>
 * CallByAPI            <ControlIdle>
 * REQ ID               <DD_1_0769, DD_1_0770>
 */
/******************************************************************************/
FUNC(boolean, OS_CODE) Os_SetCoreMode(Os_CoreIdType core,  Os_CoreModeType coreMode)
{
    (void)core;
    (void)coreMode;
    /* nothing to do. */
    
    return TRUE;
}

/******************************************************************************/
/*
 * Brief                <Get the CPU Mode>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-core[in]       <Selects the core which mode is set>
 * Return               <Os_CPUModeType,the Thread mode>
 * PreCondition         <None>
 * CallByAPI            <>
 */
/******************************************************************************/
FUNC(uint32, OS_CODE) Os_GetCpuMode()
{
    uint32 threadmode;
    ASM volatile("mrs   %0, cpsr" : "=r" (threadmode));
    if(threadmode & 0x0f)
    {
        return OS_CPUMODE_SUPERVISOR;
    }
    else
    {
        return OS_CPUMODE_USER1;
    }
}

/******************************************************************************/
/*
 * Brief                <Set the CPU Mode>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-core[in]       <Selects the core which mode is set>
 * Return               <Os_CPUModeType,the CPU mode>
 * PreCondition         <None>
 * CallByAPI            <ControlIdle>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_SetCpuMode(Os_CPUModeType mode)
{
    if (OS_CPUMODE_USER1 == mode)
    {
        asm(" cps #0x10");
    }
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#define OS_START_SEC_CODE
#include "Os_MemMap.h"

#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))                                     
FUNC(uint32 , OS_CODE) Os_CaculateMemSize(uint8 startAddr[],uint8 endAddr[])
{
    VAR(uint32, OS_VAR)   calcSize   = (uint32)0;
    VAR(uint32, OS_VAR)   memSize = (uint32)0;
    VAR(int, OS_VAR)      Idex = (int)0;
    
    calcSize=(uint32)(endAddr - startAddr);
    
    while (1)
    {
        if (MpuRegionSize[Idex] >= calcSize)
        {
            memSize = MpuRegionBitMap[Idex];
            break;
        }
        Idex++;
    }
    
    return memSize;
}
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */

extern unsigned long CSTACK$$Limit[];
FUNC(void, OS_CODE) Os_ModeSpInit(void)
{
     uint32 cstacktop = (uint32)CSTACK$$Limit;
    
    switch (Os_SCB.sysCore)
    {
    case 0:
        Os_SysSp = (volatile uint32)cstacktop;
        Os_IsrSp = (volatile uint32)(cstacktop - 0x2200);
        break;
    case 1:
        Os_SysSp = (volatile uint32)(cstacktop - 0xC000);
        Os_IsrSp = (volatile uint32)(cstacktop - 0xE200);
        break;
    case 2:
        Os_SysSp = (volatile uint32)(cstacktop - 0x10000);
        Os_IsrSp = (volatile uint32)(cstacktop - 0x12200);
        break;
    default:
        break;
    }
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
/*=======[E N D   O F   F I L E]==============================================*/
