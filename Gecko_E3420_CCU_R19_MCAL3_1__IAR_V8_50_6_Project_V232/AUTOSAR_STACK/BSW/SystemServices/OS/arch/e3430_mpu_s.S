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
**  FILENAME    : Os_Mpu_S.S                                                  **
**                                                                            **
**  Created on  :                                                             **
**  Author      : xinglong.xu                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>    <AUTHOR>        <REVISION LOG>
 *  V0.1.0     2023-03-21   xinglong.xu        Initial version.
 */
/*============================================================================*/
    
/**********************************************************************/
    PUBWEAK  Os_MpuEnable
    SECTION .text:CODE:ROOT(2)
    Os_MpuEnable:
        mrc   p15, #0, r0, c1, c0, #0
        orr   r0,  r0, #1
        dsb
        mcr   p15, #0, r0, c1, c0, #0
        isb
        bx    lr
/**********************************************************************/       
        
    PUBWEAK  Os_MpuDisable
    SECTION .text:CODE:ROOT(2)
    Os_MpuDisable:
        mrc   p15, #0, r0, c1, c0, #0
        bic   r0,  r0, #1
        dsb
        mcr   p15, #0, r0, c1, c0, #0
        isb
        bx    lr
        
/**********************************************************************/       
    PUBWEAK  Os_MpuSetRegion
    SECTION .text:CODE:ROOT(2)
    Os_MpuSetRegion:
        and   r0,  r0, #15                  ; select region
        isb
        mcr   p15, #0, r0, c6, c2, #0
        isb
        mcr   p15, #0, r1, c6, c1, #0       ; Base Address
        isb 
        mcr   p15, #0, r3, c6, c1, #4       ; Access Attributes
        isb
        mcr   p15, #0, r2, c6, c1, #2       ; Size and Enable
        dsb
        isb
        bx    lr      
      

    END
/*=======[E N D   O F   F I L E]==============================================*/