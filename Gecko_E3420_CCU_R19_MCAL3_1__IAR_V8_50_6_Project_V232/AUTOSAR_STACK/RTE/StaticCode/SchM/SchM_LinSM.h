/******************************************************************************
**                                                                           **
** Copyright (C) iSOFT   (2022)                                              **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to iSOFT.        **
** Passing on and copying of this document, and communication                **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
**************************************************************************** **
**                                                                           **
**  FILENAME    : SchM_LinSM.h                                               **
**                                                                           **
**  Created on  :                                                            **
**  Author      :                                                            **
**  Vendor      :                                                            **
**  DESCRIPTION : LinSM                                                      **
**                                                                           **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2/R19-11               **
**                                                                           **
**************************************************************************** */
#ifndef SCHM_LINSM_H
#define SCHM_LINSM_H

#include "Std_Types.h"

#define SchM_Enter_LinSM(x, y)
#define SchM_Exit_LinSM(x, y)

/******************************************************************************/
/*
 * Brief               Periodic function that runs the timers of different
 *                     request timeouts
 * ServiceId           0x30
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      N/A
 * Param-Name[in/out]  N/A
 * Param-Name[out]     N/A
 * Return              N/A
 */
/******************************************************************************/
extern FUNC(void, LINSM_CODE) LinSM_MainFunction(void);

#endif /* SCHM_LINSM_H */
