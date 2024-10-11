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
**  FILENAME    : Os_SysAsmFun.s                                              **
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
 *  V0.1.0     2021-07-21   shun.li        Initial version.
 */
/*============================================================================*/
    
    PUBWEAK Os_SaveIrq
    SECTION .text:CODE:ROOT(2)

Os_SaveIrq:
    MRS     R0, CPSR
    CPSID   I
    DSB 
    bx lr

     
    PUBWEAK Os_RestoreIrq
    SECTION .text:CODE:ROOT(2)

Os_RestoreIrq:
    DSB
    MSR     CPSR_c, R0
    bx lr
 
    PUBWEAK _getCPSRValue
    SECTION .text:CODE:ROOT(2)

_getCPSRValue

        mrs   r0, CPSR
        bx    lr    
        
    END 
    