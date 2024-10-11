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
**  FILENAME    : SchM_LinIf.h                                               **
**                                                                           **
**  Created on  :                                                            **
**  Author      :                                                            **
**  Vendor      :                                                            **
**  DESCRIPTION : LinIf                                                      **
**                                                                           **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2/R19-11               **
**                                                                           **
**************************************************************************** */
#ifndef SCHM_LINIF_H
#define SCHM_LINIF_H

#include "Std_Types.h"

#define SCHM_ENTER_LINIF(x, y)
#define SCHM_EXIT_LINIF(x, y)

/******************************************************************************/
/*
 * Brief               The main processing function of the LIN Interface.
 * ServiceId           0x80
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      N/A
 * Param-Name[in/out]  N/A
 * Param-Name[out]     N/A
 * Return              N/A
 */
/******************************************************************************/
extern FUNC(void, LINIF_CODE) LinIf_MainFunction(void);

#endif /* SCHM_LINIF_H */
