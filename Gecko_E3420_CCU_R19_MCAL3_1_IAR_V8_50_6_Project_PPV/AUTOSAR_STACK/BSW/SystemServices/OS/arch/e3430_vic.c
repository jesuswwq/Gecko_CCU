/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2016)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : Os_Gic.c                                              **
**                                                                            **
**  Created on  :                                                             **
**  Author      : shun.li                                                     **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>    <AUTHOR>        <REVISION LOG>
 *  V0.1.0     2021-07-06   shun.li        Initial version.
 */
/*============================================================================*/
#include "Os_Internal.h"

#include "e3430_vic.h"
#include "reg.h"

uint32 OS_INT_BASE[3] = {
        PERIPHERALSF_VIC1_BASE,
        PERIPHERALSF_VIC3PORTA_BASE,
        PERIPHERALSF_VIC3PORTB_BASE
};

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
isr_vec_t E3430_int_tab[255u];
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#define OS_START_SEC_CODE
#include "Os_MemMap.h"


/**
 * Invalid interrupt handler.
 */
static void VIC_DefaultFun(void)
{
   Os_IntHandler();
}

void e3430_vic_init(void)
{
    irq_initialize(OS_INT_BASE[Os_SCB.sysCore], IRQ_MAX_INTR_NUM);
}

void VIC_IsrEntry(void)
{
    #if (CFG_INT_NEST_ENABLE == TRUE)
    {
        if ((Os_IntNestISR1 == 0) && (Os_IntNestISR2 == 0))
        {
            asm("cps #0x12");
            asm("ldr sp, =Os_IsrSp"); /*According to chip, adjust sp of isr.*/
            asm("ldr sp, [sp]");
            asm("dsb");
            asm("cps #0x1f");
            asm("ldr sp, =Os_SysSp"); /*According to chip, adjust sp of isr.*/
            asm("ldr sp, [sp]");
            asm("dsb");
        }
    }
    #endif

    uint32 irqNum;
    
    irqNum  =  readl(OS_VICADDRESS);
    
    if (irqNum > 256u) while(1);
    
    if (E3430_ISR_ENTRY(irqNum).isr_entry != (void*)0)
    {
        E3430_ISR_ENTRY(irqNum).isr_entry();
    }
    else
    {
        VIC_DefaultFun();
    }
}

void Os_IntSelect(uint32 irqNum, uint16 vicIntSelect)
{
    uint8 group;
    uint8 id;
    uint32 tempIntSelect;

    group = irqNum / 32u;
    id = irqNum % 32u;

    tempIntSelect = readl(OS_VIC_INTSELECT(group));
    if (vicIntSelect == VIC_IRQ_MODE)
    {
        writel(VIC_SET_IRQ_MODE(tempIntSelect, id), OS_VIC_INTSELECT(group));
    }
    else
    {
        writel(VIC_SET_FIQ_MODE(tempIntSelect, id), OS_VIC_INTSELECT(group));
    }
}

void Os_MaskIrqPiroThreshold(uint16 threshold)
{
    uint16 savepri = 0x0;
    savepri = readl(OS_VICSWPRIORITYMASK);

    if (threshold < 16)
    {
        uint16 temp = 0xFFFF;
        temp = temp >> threshold;
        savepri &= temp;
        writel(savepri, OS_VICSWPRIORITYMASK);
    }
}

void Os_UnMaskIrqPiroThreshold(uint16 threshold)
{
    uint16 savepri = 0x0;
    savepri = readl(OS_VICSWPRIORITYMASK);

    if (threshold < 16)
    {
        uint16 temp = 0xFFFF;
        temp = temp >> threshold;
        savepri |= temp;
        writel(savepri, OS_VICSWPRIORITYMASK);
    }
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"


/*=======[E N D   O F   F I L E]==============================================*/