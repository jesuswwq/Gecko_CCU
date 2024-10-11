/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2022)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : BswM_LinSM.h                                                **
**                                                                            **
**  Created on  : 2020-03-24                                                  **
**  Author      : qinchun.yang                                                **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

#ifndef BSWM_LINSM_H
#define BSWM_LINSM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "BswM_Internal.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
#if (BSWM_LINSM_ENABLED == STD_ON)

/**
 * Function called by LinSM to indicate the currently active schedule table for
 * a specific LIN channel.
 * Service ID: 0x0a
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): Network, The LIN channel that the schedule table switch have
 *                          occurred on.
 *                 CurrentSchedule, The currently active schedule table of the
 *                                  LIN channel
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_LINSM_CODE)
BswM_LinSM_CurrentSchedule(NetworkHandleType Network, LinIf_SchHandleType CurrentSchedule);

/**
 * Function called by LinSM to indicate its current state.
 * Service ID: 0x09
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): Network, The LIN channel that the indicated state corresponds to
 *                 CurrentState, The current state of the LIN channel
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_LINSM_CODE)
BswM_LinSM_CurrentState(NetworkHandleType Network, LinSM_ModeType CurrentState);

#endif /*(BSWM_LINSM_ENABLED == STD_ON)*/
#endif /* BSWM_LINSM_H */
