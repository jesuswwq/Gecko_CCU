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
**  FILENAME    : NvM_Cbk.h                                                  **
**                                                                           **
**  Created on  : 2020/5/9 15:21:52                                          **
**  Author      : tao.yu                                                     **
**  Vendor      :                                                            **
**  DESCRIPTION : callback function                                          **
**                                                                           **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                     **
**                                                                           **
**************************************************************************** */
#ifndef NVM_CBK_H
#define NVM_CBK_H

#include "NvM.h"
/**
 *Function to be used by the underlying memory abstraction to signal end of job without error.
 */

/*
 * Brief               Function to be used by the underlying memory abstraction to signal end of job without error
 * ServiceId           0x11
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]   None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Underlying API
 */

extern FUNC(void, NVM_CODE) NvM_JobEndNotification(void);

/*************************************************************************/
/*
 * Brief               Function to be used by the underlying memory abstraction to signal end of job with error
 * ServiceId           0x12
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]   None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Underlying API
 */
/*************************************************************************/

extern FUNC(void, NVM_CODE) NvM_JobErrorNotification(void);

#endif /* End of NVM_CBK_H*/
/*====================[E N D   O F   F I L E]====================*/
