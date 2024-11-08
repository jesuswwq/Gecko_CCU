/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Os_Intvet.c>
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
 *   V2.0.0       20170503     zuxiong.ding Multicore
 *   V3.0.0       20191121     shun.li      Functional safety version
 */
/*============================================================================*/

/*=======[I N C L U D E S]====================================================*/
#include "Os_Cfg.h"
#include "Os_Internal.h"
#include "Os_Processor.h"

/*=======[V E R S I O N   I N F O R M A T I O N]===============================*/
#define OS_VECTOR_C_AR_MAJOR_VERSION     4U
#define OS_VECTOR_C_AR_MINOR_VERSION     2U
#define OS_VECTOR_C_AR_PATCH_VERSION     2U
#define OS_VECTOR_C_SW_MAJOR_VERSION     1U
#define OS_VECTOR_C_SW_MINOR_VERSION     0U
#define OS_VECTOR_C_SW_PATCH_VERSION     0U

/*=======[V E R S I O N  C H E C K]===========================================*/
#if (OS_VECTOR_C_AR_MAJOR_VERSION != OS_CFG_H_AR_MAJOR_VERSION)
    #error "Os_Intvet.c:Mismatch in Specification Major Version"
#endif
#if (OS_VECTOR_C_AR_MINOR_VERSION != OS_CFG_H_AR_MINOR_VERSION)
    #error "Os_Intvet.c:Mismatch in Specification Minor Version"
#endif
#if (OS_VECTOR_C_AR_PATCH_VERSION != OS_CFG_H_AR_PATCH_VERSION)
    #error "Os_Intvet.c:Mismatch in Specification Patch Version"
#endif
#if (OS_VECTOR_C_SW_MAJOR_VERSION != OS_CFG_H_SW_MAJOR_VERSION)
    #error "Os_Intvet.c:Mismatch in Specification Major Version"
#endif
#if (OS_VECTOR_C_SW_MINOR_VERSION != OS_CFG_H_SW_MINOR_VERSION)
    #error "Os_Intvet.c:Mismatch in Specification Minor Version"
#endif

/*=======[M A C R O S]========================================================*/
#define     OS_ARCH_INT_CORE0              OS_ARCH_INT_CPU0
#define     OS_ARCH_INT_CORE1              OS_ARCH_INT_CPU1
#define     OS_ARCH_INT_CORE2              OS_ARCH_INT_CPU2

/*==========[I S R]===========================================================*/
#define OS_START_SEC_CODE_FAST
#include "Os_MemMap.h"
/* --------------------CORE0-------------------- */
FUNC(void, OS_CODE_FAST) Os_ISR_REMOTECALL0(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_REMOTECALL_CORE0_ID));
    Os_ArchRemoteClear();
    Os_InterCoreOperation(Os_SCB.sysCore);
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) Os_SysTick_Handler0(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_SYS_TIMER_CORE0_ID));
    Os_SystickIsrClearFlag();
    Os_ArchSystemTimerCore0();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) Os_ISR_CANFD3_CANFD(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_ISR_CANFD3_CANFD_ID));
    ISR_CANFD3_CANFD();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) Os_ISR_CANFD4_CANFD(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_ISR_CANFD4_CANFD_ID));
    ISR_CANFD4_CANFD();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) Os_ISR_CANFD5_CANFD(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_ISR_CANFD5_CANFD_ID));
    ISR_CANFD5_CANFD();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) Os_ISR_CANFD6_CANFD(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_ISR_CANFD6_CANFD_ID));
    ISR_CANFD6_CANFD();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) Os_ISR_CANFD7_CANFD(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_ISR_CANFD7_CANFD_ID));
    ISR_CANFD7_CANFD();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) Os_ISR_CANFD8_CANFD(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_ISR_CANFD8_CANFD_ID));
    ISR_CANFD8_CANFD();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) Os_ISR_ETMR2_CHN_B(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_ISR_ETMR2_CHN_B_ID));
    ISR_ETMR2_CHN_B();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) Os_ISR_GPIO_AP_SYNC_DGPIO(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_ISR_GPIO_AP_SYNC_DGPIO_ID));
    ISR_GPIO_AP_SYNC_DGPIO();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) Os_ISR_SADC1_O_SADC(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_ISR_SADC1_O_SADC_ID));
    ISR_SADC1_O_SADC();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) Os_ISR_SADC2_O_SADC(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_ISR_SADC2_O_SADC_ID));
    ISR_SADC2_O_SADC();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) Os_ISR_SPI7_SPI(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_ISR_SPI7_SPI_ID));
    ISR_SPI7_SPI();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) Os_ISR_UART3(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_ISR_UART3_ID));
    ISR_UART3();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) Os_ISR_UART11(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_ISR_UART11_ID));
    ISR_UART11();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) Os_ISR_UART14(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_ISR_UART14_ID));
    ISR_UART14();
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) Os_ISR_WDT1_WDT(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_ISR_WDT1_WDT_ID));
    ISR_WDT1_WDT();
    OS_ARCH_ISR2_EPILOGUE();
}
/* --------------------CORE1-------------------- */
FUNC(void, OS_CODE_FAST) Os_ISR_REMOTECALL1(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_REMOTECALL_CORE1_ID));
    Os_ArchRemoteClear();
    Os_InterCoreOperation(Os_SCB.sysCore);
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) Os_SysTick_Handler1(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_SYS_TIMER_CORE1_ID));
    Os_SystickIsrClearFlag();
    Os_ArchSystemTimerCore1();
    OS_ARCH_ISR2_EPILOGUE();
}
/* --------------------CORE2-------------------- */
FUNC(void, OS_CODE_FAST) Os_ISR_REMOTECALL2(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_REMOTECALL_CORE2_ID));
    Os_ArchRemoteClear();
    Os_InterCoreOperation(Os_SCB.sysCore);
    OS_ARCH_ISR2_EPILOGUE();
}
FUNC(void, OS_CODE_FAST) Os_SysTick_Handler2(void)
{
    OS_ARCH_ISR2_PROLOGUE(Os_GetObjLocalId(CFG_SYS_TIMER_CORE2_ID));
    Os_SystickIsrClearFlag();
    Os_ArchSystemTimerCore2();
    OS_ARCH_ISR2_EPILOGUE();
}
/* ------------------Interrupt install-------------------- */
FUNC(void, OS_CODE) Os_IntHandler(void)
{
    /* Just ignore this interrupt.  */
    while(1){}
}
#define OS_STOP_SEC_CODE_FAST
#include "Os_MemMap.h"

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
FUNC(void, OS_CODE) Os_ArchInitIntPrio(void)
{
    Os_CoreIdType coreID = Os_SCB.sysCore;
    switch(coreID)
    {
        case 0:
                    Os_InterruptInstall(MB_SEMAPHORE_LOCK_FAIL, 1U, 0, Os_ISR_REMOTECALL0);
                    Os_InterruptInstall(BTM1_O_BTM, 10U, 0, Os_SysTick_Handler0);
                    Os_InterruptInstall(CANFD3_CANFD, 5U, 0, Os_ISR_CANFD3_CANFD);
                    Os_InterruptInstall(CANFD4_CANFD, 5U, 0, Os_ISR_CANFD4_CANFD);
                    Os_InterruptInstall(CANFD5_CANFD, 5U, 0, Os_ISR_CANFD5_CANFD);
                    Os_InterruptInstall(CANFD6_CANFD, 5U, 0, Os_ISR_CANFD6_CANFD);
                    Os_InterruptInstall(CANFD7_CANFD, 5U, 0, Os_ISR_CANFD7_CANFD);
                    Os_InterruptInstall(CANFD8_CANFD, 5U, 0, Os_ISR_CANFD8_CANFD);
                    Os_InterruptInstall(ETMR2_CHN_B, 4U, 0, Os_ISR_ETMR2_CHN_B);
                    Os_InterruptInstall(GPIO_AP_SYNC_DGPIO, 5U, 0, Os_ISR_GPIO_AP_SYNC_DGPIO);
                    Os_InterruptInstall(SADC1_O_SADC, 5U, 0, Os_ISR_SADC1_O_SADC);
                    Os_InterruptInstall(SADC2_O_SADC, 5U, 0, Os_ISR_SADC2_O_SADC);
                    Os_InterruptInstall(SPI7_SPI, 6U, 0, Os_ISR_SPI7_SPI);
                    Os_InterruptInstall(UART3, 5U, 0, Os_ISR_UART3);
                    Os_InterruptInstall(UART11, 5U, 0, Os_ISR_UART11);
                    Os_InterruptInstall(UART14, 5U, 0, Os_ISR_UART14);
                    Os_InterruptInstall(WDT1_WDT, 6U, 0, Os_ISR_WDT1_WDT);
        break;
        case 1:
                    Os_InterruptInstall(MB_SEMAPHORE_LOCK_FAIL, 1U, 0, Os_ISR_REMOTECALL1);
                    Os_InterruptInstall(BTM2_O_BTM, 10U, 0, Os_SysTick_Handler1);
        break;
        case 2:
                    Os_InterruptInstall(MB_SEMAPHORE_LOCK_FAIL, 1U, 0, Os_ISR_REMOTECALL2);
                    Os_InterruptInstall(BTM3_O_BTM, 10U, 0, Os_SysTick_Handler2);
        break;
        default:
        break;
    }
    return;
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
/*=======[E N D   O F   F I L E]==============================================*/

