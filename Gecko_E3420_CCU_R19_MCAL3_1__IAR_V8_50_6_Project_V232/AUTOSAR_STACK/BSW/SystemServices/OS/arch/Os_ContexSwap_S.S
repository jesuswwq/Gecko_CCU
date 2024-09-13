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
**  FILENAME    : Os_ContextSwap_S.s                                          **
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
    EXTERN  Os_RunningTCB
    EXTERN  Os_ArchSp
    EXTERN  do_dispatch
    EXTERN  Os_IsrSp

/**********************************************************************/
    PUBWEAK Os_StartUpResumeContext
    SECTION .text:CODE:ROOT(2)
Os_StartUpResumeContext:
    cps #0x13
    DSB
    ISB
    LDR     R0, =Os_RunningTCB
    LDR     R1, [R0]
    LDR     R2, [R1]
    LDR     LR, [R2]
#ifdef CFG_ARCH_FPU
    add     R4, LR,#200
    STR     R4, [R2]
    VLDM    LR!, {S0-S31}
    LDM     LR!, {R1}
    VMSR    FPSCR, R1
#else
    add     R4, LR,#68
    STR     R4, [R2]
#endif
    LDMFD   LR!, {R0}
    MSR     SPSR_CSXF, R0
    LDMFD   LR, {R0-R14}^
    LDR     LR, [LR, #+60]
    ISB
    SUBS    PC, LR, #4
        
/**********************************************************************/
    PUBWEAK Os_ISR2ResumeContext
    SECTION .text:CODE:ROOT(2)
Os_ISR2ResumeContext:
    LDR  R0,=Os_ArchSp
    LDR  SP,[R0]
    LDMFD   SP!, {R0}
    MSR     SPSR_CSXF, R0
    LDMFD   SP, {R0-R14}
    ISB
    SUBS    PC,LR,#4 
    
/**********************************************************************/    
    PUBWEAK Os_ArchResumeContext
    SECTION .text:CODE:ROOT(2)
Os_ArchResumeContext: 
    LDR     R0, =Os_RunningTCB
    LDR     R1, [R0]
    LDR     R2, [R1]
    LDR     LR, [R2]
#ifdef CFG_ARCH_FPU
    add     R4, LR,#200
    STR     R4, [R2]
    VLDM    LR!, {S0-S31}
    LDM     LR!, {R1}
    VMSR    FPSCR, R1
#else
    add     R4, LR,#68
    STR     R4, [R2]
#endif 
    DSB
    LDMFD   LR!, {R0}
    MSR     SPSR_CSXF, R0
    LDMFD   LR, {R0-R14}^
    LDR     LR, [LR, #+60]
    ISB
    SUBS    PC, LR, #4

/**********************************************************************/
    PUBWEAK Os_SVCResumeContext
    SECTION .text:CODE:ROOT(2)
Os_SVCResumeContext: 
    LDR     R0, =Os_RunningTCB
    LDR     R1, [R0]
    LDR     R2, [R1]
    LDR     LR, [R2]
    add     R4, LR,#68
    STR     R4, [R2]
    DSB
    LDMFD   LR!, {R0}
    MSR     SPSR_CSXF, R0
    LDMFD   LR, {R0-R14}^
    LDR     LR, [LR, #+60]
    ISB
    MOVS PC, LR

/**********************************************************************/
    PUBWEAK Os_ISR2ResumeIsrContext
    SECTION .text:CODE:ROOT(2)
Os_ISR2ResumeIsrContext:
    CPS #0X12
    ISB
    
    LDR  R0,=Os_ArchSp
    LDR  SP,[R0] 
    LDMFD   SP!, {R0}  
    MOV LR, R0  
#ifdef CFG_ARCH_FPU
    VLDM    SP!, {S0-S31}
    LDM     SP!, {R1}
    VMSR    FPSCR, R1
#endif
    LDMFD   SP!, {R0}   
    MSR     SPSR_CSXF, R0  
    LDR  R0,=Os_ArchSp
    STR    SP,[R0] 
    CPS #0X1f
    ISB
    LDR  R0,=Os_ArchSp
    LDR  SP,[R0]
    LDMFD   SP!, {R0-LR}
    CPS #0X12
    ISB
    
    ldr sp, =Os_IsrSp /*According to chip, adjust sp of isr.*/
    ldr sp, [sp]
    SUBS    PC,LR,#4 
    
/**********************************************************************/    
    PUBWEAK Os_ArchDispatch
    SECTION .text:CODE:ROOT(2)
Os_ArchDispatch: 
    ADD LR, LR,#4
    STMFD SP!,{LR}
    STMFD SP!,{R0-LR}
    
    MOV R0, SP
    ADD R1, R0, #64  
    ADD R2, R0, #52
    STR R1, [R2]

    MRS R0, CPSR
    STMFD   SP!, {R0}
#ifdef CFG_ARCH_FPU
    FMRX    R1,  FPSCR
    PUSH    {R1}
    VPUSH {S0-S31}
#endif
     
    LDR R0, =Os_RunningTCB
    LDR R0, [R0]
    LDR R1, [R0]
    STR SP, [R1]
    DSB

    b do_dispatch
    
    END
/*=======[E N D   O F   F I L E]==============================================*/