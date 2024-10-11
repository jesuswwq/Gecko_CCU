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
**  FILENAME    : BswM_LinTp.h                                                **
**                                                                            **
**  Created on  : 2020-03-24                                                  **
**  Author      : qinchun.yang                                                **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

#ifndef BSWM_LINTP_H
#define BSWM_LINTP_H

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
#if (BSWM_LINTP_ENABLED == STD_ON)

/**
 * Function called by LinTP to request a mode for the corresponding LIN channel.
 * The LinTp_Mode correlates to the LIN schedule table that should be used.
 * Service ID: 0x0b
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): Network, The LIN channel that the LinTp mode request relates to
 *                 LinTpRequestedMode, The requested LIN TP mode
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_LINTP_CODE)
BswM_LinTp_RequestMode(NetworkHandleType Network, LinTp_Mode LinTpRequestedMode);

#endif /*(BSWM_LINTP_ENABLED == STD_ON)*/
#endif /* BSWM_LINTP_H */
