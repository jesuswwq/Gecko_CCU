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
**  FILENAME    : BswM_FrSM.h                                                 **
**                                                                            **
**  Created on  : 2020-03-24                                                  **
**  Author      : qinchun.yang                                                **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

#ifndef BSWM_FRSM_H
#define BSWM_FRSM_H

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
#if (BSWM_FRSM_ENABLED == STD_ON)

/**
 * Function called by FrSM to indicate its current state.
 * Service ID: 0x0c
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): Network, the FlexRay cluster that the indicated state corresponds to
 *                 CurrentState, the current state of the FlexRay cluster
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_FRSM_CODE)
BswM_FrSM_CurrentState(NetworkHandleType Network, FrSM_BswM_StateType CurrentState);

#endif /*(BSWM_FRSM_ENABLED == STD_ON)*/
#endif /* BSWM_FRSM_H */
