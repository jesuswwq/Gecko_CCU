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
**  FILENAME    : BswM_CanSM.h                                                **
**                                                                            **
**  Created on  : 2020-03-24                                                  **
**  Author      : qinchun.yang                                                **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

#ifndef BSWM_CANSM_H
#define BSWM_CANSM_H

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
#if (BSWM_CANSM_ENABLED == STD_ON)

/**
 * Function called by CanSM to indicate its current state.
 * Service ID: 0x05
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): Network, the CAN channel the indicated state corresponds to
 *                 CurrentState, the current state of the CAN channel
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_CANSM_CODE)
BswM_CanSM_CurrentState(NetworkHandleType Network, CanSM_BswMCurrentStateType CurrentState);

#if (BSWM_CANSM_ICOM_ENABLED == STD_ON)
/**
 * Function to inform BswM about the switch of Icom Configuration.
 * The interface shall be used by the CanSM to inform the BswM about the
 * activation of a new ICOM configuration for a given channel.The BswM shall match
 * the Network and Error parameters to a configured BswMCanSMIcomIndication and
 * utilize the ActiveConfiguration parameter as the value that gets evaluated in
 * the arbitration rules.
 * Service ID: 0x1a
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): Network, the CAN channel the requested state corresponds to
 *                 ActiveConfiguration, the configuration Id of the Icom configuration
 *                 Error, ICOM_SWITCH_E_OK: No Error
 *                        ICOM_SWITCH_E_FAILED: Switch to requested Configuration failed.
 *                                              Severe Error.
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_CANSM_CODE)
BswM_CanSM_CurrentIcomConfiguration(
    NetworkHandleType Network,
    IcomConfigIdType ActiveConfiguration,
    IcomSwitch_ErrorType Error);
#endif /*(BSWM_CANSM_ICOM_ENABLED == STD_ON)*/

#endif /*(BSWM_CANSM_ENABLED == STD_ON)*/
#endif /* BSWM_CANSM_H */
