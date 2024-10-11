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
**  FILENAME    : Os_SysAsmFun.h                                              **
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
 *  V0.1.0     2021-02-26   shun.li        Initial version.
 */
/*============================================================================*/

#ifndef OS_CRITICALSECTION_H_
#define OS_CRITICALSECTION_H_
#include "Platform_Types.h"

extern uint32  Os_SaveIrq(void);
extern void    Os_RestoreIrq(uint32 saved);
extern void Os_StartUpResumeContext(void);
extern void Os_ArchResumeContext(void);
extern void Os_ISR2ResumeContext(void);
extern void SWI_Handler(void);
extern void Irq_Entry(void);
extern void Os_ISR2ResumeIsrContext(void);
extern void Os_SVCResumeContext(void);
#endif /* OS_CRITICALSECTION_H_ */
