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
**  FILENAME    : Os_IsrHandler.s                                            **
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
#include "Os_Cfg_S.h"
    EXTERN  Os_IntNestISR2
    EXTERN  Os_IntNestISR1
    EXTERN  Os_ArchSp
    EXTERN  Os_RunningTCB
    
    EXTERN  Os_SWI_Handler
    EXTERN  VIC_IsrEntry
    
/**********************************************************************/
    PUBWEAK SWI_Handler
    SECTION .text:CODE:ROOT(2)
SWI_Handler: 
    DSB
    STMDB   SP!, {R0}
    STMFD   SP,{SP}^
    DSB
    ISB
    SUB SP, SP, #4
    LDMFD   SP!,{R0}
    STMFD   R0!, {LR}
    MOV LR, R0
    LDMFD   SP!, {R0}
    STMFD   LR,{R0-LR}
    DSB
    ISB
    SUB LR, LR, #60
    MRS R0, SPSR
    STMFD   LR!, {R0}
    DSB
    ISB
    LDR R0, =Os_RunningTCB
    LDR R0, [R0]
    LDR R1, [R0]
    STR LR, [R1]
    DSB 
    b Os_SWI_Handler
    
/**********************************************************************/
#if defined(CFG_INT_NEST_S_ENABLE)
    PUBWEAK AutosarOsIrqHandler
    SECTION .text:CODE:ROOT(2)
AutosarOsIrqHandler: 
    DSB
    STMFD   SP,{R0}
    SUB SP,SP,#4
    LDR  R0,=Os_IntNestISR1
    LDRB  R0,[R0]
    CMP R0 ,#0
    BEQ GOTO_ISR_1
    BNE GOTO_ISR_2
GOTO_ISR_1
    LDMFD   SP!, {R0}
    STMFD   SP,{R0}
    SUB SP,SP,#4
    LDR  R0,=Os_IntNestISR2
    LDRB  R0, [R0]
    CMP R0 ,#0
    BEQ GOTO_TASK_SAVE_CONTEXT
    BNE GOTO_ISR_SAVE_CONTEXT
    
GOTO_TASK_SAVE_CONTEXT
    LDMFD   SP!, {R0}
    STMDB   SP!, {R0}
    STMFD   SP,{SP}^
    DSB
    SUB SP, SP, #4
    LDMFD   SP!,{R0}
    STMFD   R0!, {LR}
    MOV LR, R0
    LDMFD   SP!, {R0}
    STMFD   LR,{R0-LR}^
    DSB

    SUB LR, LR, #60
    MRS R0, SPSR
    STMFD   LR!, {R0}
#ifdef CFG_ARCH_FPU
    VSTMDB   LR!,{S0-S31}
#endif
    LDR R0, =Os_RunningTCB
    LDR R0, [R0]
    LDR R1, [R0]
    STR LR, [R1]
    ISB
    b VIC_IsrEntry
    
GOTO_ISR_SAVE_CONTEXT
    LDMFD   SP!, {R0} 
    STMFD   SP!, {R0,R1} 
    MRS R0, SPSR  
    LDR  R1,=Os_ArchSp
    STR    R0,[R1]
    LDMFD   SP!, {R0,R1}
    CPS #0x1f
    ISB
    STMFD SP!, {R0-LR}
    DSB

    LDR  R1,=Os_ArchSp
    LDR  R0,[R1]
    STMFD   SP!, {R0}
#ifdef CFG_ARCH_FPU
    VSTMDB  SP!,{S0-S31}
#endif
    CPS #0X12
    ISB
    MOV R0, LR
    LDR  R1,=Os_ArchSp
    STR    R0,[R1]
    CPS #0x1f
    ISB
    LDR  R1,=Os_ArchSp
    LDR  R0,[R1]
    STMFD   SP!, {R0}
    LDR  R1,=Os_ArchSp
    STR    SP,[R1]
    DSB

    b VIC_IsrEntry
  
GOTO_ISR_2
    LDMFD   SP!, {R0}
    STMFD   SP!, {R0,R1}
    MRS R0, SPSR
    LDR  R1,=Os_ArchSp
    STR    R0,[R1]
    LDMFD   SP!, {R0,R1}
    CPS #0x1f
    ISB
    STMFD SP!, {R0-LR}
    DSB
    LDR  R1,=Os_ArchSp
    LDR  R0,[R1]
    STMFD   SP!, {R0}
#ifdef CFG_ARCH_FPU
    VSTMDB  SP!,{S0-S31}
#endif
    CPS #0X12
    ISB
    MOV R0, LR
    LDR  R1,=Os_ArchSp
    STR    R0,[R1]
    CPS #0x1f
   
    ISB
    LDR  R1,=Os_ArchSp
    LDR  R0,[R1]
    STMFD   SP!, {R0}
    LDR  R1,=Os_ArchSp
    STR    SP,[R1]
    DSB

    b VIC_IsrEntry
#else
    PUBWEAK AutosarOsIrqHandler
    SECTION .text:CODE:ROOT(2)
AutosarOsIrqHandler:
    DSB
    STMFD   SP,{R0}
    SUB SP,SP,#4
    LDR  R0,=Os_IntNestISR1
    LDRB  R0,[R0]
    
    CMP R0 ,#0
    BEQ GOTO_ISR_1
    BNE GOTO_ISR_2
    
GOTO_ISR_1
    LDMFD   SP!, {R0}
    STMFD   SP,{R0}
    SUB SP,SP,#4
    LDR  R0,=Os_IntNestISR2
    LDRB  R0, [R0]
    CMP R0 ,#0
    BEQ GOTO_TASK_SAVE_CONTEXT
    BNE GOTO_ISR_SAVE_CONTEXT


GOTO_TASK_SAVE_CONTEXT
    LDMFD   SP!, {R0}

    STMDB   SP!, {R0}
    STMFD   SP,{SP}^

    SUB SP, SP, #4
    LDMFD   SP!,{R0}
    STMFD   R0!, {LR}
    MOV LR, R0
    LDMFD   SP!, {R0}
    STMFD   LR,{R0-LR}^
    DSB

    SUB LR, LR, #60
    MRS R0, SPSR
    STMFD   LR!, {R0}
#ifdef CFG_ARCH_FPU
    VSTMDB   LR!,{S0-S31}
#endif
    LDR R0, =Os_RunningTCB
    LDR R0, [R0]
    LDR R1, [R0]
    STR LR, [R1]
    DSB
    b VIC_IsrEntry

GOTO_ISR_SAVE_CONTEXT
    LDMFD   SP!, {R0}

    LDMFD   SP!, {R0}
    STMFD   SP,{R0-LR}
    SUB  SP,SP,#60
    MRS R0, SPSR
    STMFD   SP!, {R0}
    STMFD   SP!, {R0}
    LDR  R1,=Os_ArchSp
    STR    SP,[R1]
    DSB
    b VIC_IsrEntry
  
GOTO_ISR_2
    LDMFD   SP!, {R0}

    LDMFD   SP!, {R0}
    STMFD   SP,{R0-LR}
    SUB  SP,SP,#60
    MRS R0, SPSR
    STMFD   SP!, {R0}
    STMFD   SP!, {R0}
    LDR  R1,=Os_ArchSp
    STR    SP,[R1]
    DSB
    b VIC_IsrEntry

#endif

 /**********************************************************************/
    PUBWEAK SVC_Entry
    SECTION .text:CODE:ROOT(2)
SVC_Entry: 
    stmfd   sp!, {R0,r12,lr}
    LDR    r12, [lr, #-4]
    LDR    r14, table    
    MOV     R0, r12, lsl #8 
    LDR    r12, [r14, r0, lsr #8]
    BLX    r12 
    ldmfd   sp!, {R0,r12,pc}^

table
    DC32    jumpTable

jumpTable
    DC32    SVC_TASK
    DC32    SVC_ISR
    DC32    SVC_IRQ
         
SVC_TASK
    mrs     R0, spsr
    orr     R0, R0, #0x1f
    msr     spsr_c, R0
    DSB
    ISB
    bx      r14

SVC_ISR
    mrs     R0, spsr
    orr   R0, R0, #0x13
    /* bic R0, R0, #0x1*/
    msr   spsr_c, R0
    DSB
    ISB
    bx      r14

SVC_IRQ
    mrs     R0, spsr
    orr   R0, R0, #0x12
    msr   spsr_c, R0
    DSB
    ISB
    bx      r14
    END
/*=======[E N D   O F   F I L E]==============================================*/