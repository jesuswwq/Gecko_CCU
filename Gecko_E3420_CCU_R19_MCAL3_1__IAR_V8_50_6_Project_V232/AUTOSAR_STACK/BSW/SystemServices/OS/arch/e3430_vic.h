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
#ifndef E3430_VIC_H_
#define E3430_VIC_H_
#include "irq.h"
#include "irq_num.h"
#include "__regs_base.h"

#define E3430_ISR_ENTRY(n)         E3430_int_tab[n]

#define VIC_IRQ_MODE     (0U)
#define VIC_FIQ_MODE     (1U)

#define VIC_SET_IRQ_MODE(i, j)     ((i) & (~(1u << (j))))
#define VIC_SET_FIQ_MODE(i, j)     ((i) | (1u << (j)))

#define OS_SHIFT32(v)  ((v) & 31U)
#define OS_OFFSET32(v)  (((v) >> 5) << 2)
#define OS_VICIRQSTATUS(v)         (OS_INT_BASE[Os_SCB.sysCore] + 0x0U + OS_OFFSET32(v))
#define OS_VICSWPMASK(v)           (OS_INT_BASE[Os_SCB.sysCore] + 0x180U + OS_OFFSET32(v))

#define OS_VICADDRESS              (OS_INT_BASE[Os_SCB.sysCore] + 0xF00U)
#define OS_VICSWPRIORITYMASK       (OS_INT_BASE[Os_SCB.sysCore] + 0x3C8U)

#define OS_VIC_INTSELECT(v)        (OS_INT_BASE[Os_SCB.sysCore] + 0xC0U + ((v) * 0X04))

#define OS_VICSOFTINT0(v)           (OS_INT_BASE[0] + 0x140U + OS_OFFSET32(v))
#define OS_VICSOFTINT1(v)           (OS_INT_BASE[1] + 0x140U + OS_OFFSET32(v))
#define OS_VICSOFTINT2(v)           (OS_INT_BASE[2] + 0x140U + OS_OFFSET32(v))

#define OS_VICSOFTINTCLEAR(v)      (OS_INT_BASE[Os_SCB.sysCore] + 0x200U + OS_OFFSET32(v))

extern uint32 OS_INT_BASE[3];

typedef   void (*IntFun)(void);

struct isr_vec_s
{
    IntFun  isr_entry;
};
typedef struct isr_vec_s  isr_vec_t;

extern isr_vec_t E3430_int_tab[255];


void e3430_vic_init(void);
void Os_IntSelect(uint32 irqNum, uint16 vicIntSelect);
void VIC_IsrEntry(void);
void Os_MaskIrqPiroThreshold(uint16 threshold);
void Os_UnMaskIrqPiroThreshold(uint16 threshold);
#endif