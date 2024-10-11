/*============================================================================*/
/*  Copyright (C) 2016, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Os_Processor.c>
 *  @brief      <>
 *  
 * <Compiler: IAR    MCU:G9X>
 *  
 *  @author     <>
 *  @date       <05-12-2014>
 */
/*============================================================================*/

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>    <AUTHOR>    <REVISION LOG>
 *  V0.1.0       2022-5-17  Shun.Li     Initial version.
 */
/*============================================================================*/

/*=======[M I S R A C  R U L E  V I O L A T I O N]============================*/
/*  <MESSAGE ID>    <CODE LINE>    <REASON>
 */
/*============================================================================*/

/*=======[I N C L U D E S]====================================================*/
#include "Os_Internal.h"
#include "e3430_vic.h"
#include "sdrv_vic.h"
/*=======[M A C R O S]========================================================*/

/*=======[E X T E R N A L   D A T A]==========================================*/

/*=======[I N T E R N A L   D A T A]==========================================*/
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/******************************************************************************/
/*
 * Brief                <Set interrupt priority>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * param[in]            <srcAddr,prio,srcType,isrProc>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <None>
 * REQ ID               <DD_1_0762>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_InterruptInstall(uint16 irqId, uint8 prio, uint16 srcType, IntFun pFun)
{
    prio--;
    prio = prio ^ 0xf;
    E3430_int_tab[irqId].isr_entry = pFun;
    irq_lld_set_priority(irqId, prio);
    Os_IntSelect(irqId, srcType);
    irq_enable(irqId);
}

/******************************************************************************/
/*
 * Brief                <Initialize interrupts and traps>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * param[in]            <None>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <Os_ArchInitCPU>
 * REQ ID               <DD_1_0902, DD_1_1298>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_InterruptInit(void)
{
    e3430_vic_init();
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
/*=======[E N D   O F   F I L E]==============================================*/
