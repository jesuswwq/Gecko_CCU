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
**  FILENAME    : BswM_J1939Dcm.h                                             **
**                                                                            **
**  Created on  : 2020-03-24                                                  **
**  Author      : qinchun.yang                                                **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

#ifndef BSWM_J1939DCM_H
#define BSWM_J1939DCM_H

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
#if (BSWM_J1939DCM_ENABLED == STD_ON)

/**
 * This API tells the BswM the desired communication status of the available
 * networks. The status will typically be activated via COM I-PDU group switches.
 * Service ID: 0x1b
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): NetworkMask, Mask containing one bit for each available
 *                              network. 1: Network enabled 0: Network disabled
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_J1939DCM_CODE)
BswM_J1939DcmBroadcastStatus(uint16 NetworkMask);

#endif /*(BSWM_J1939DCM_ENABLED == STD_ON)*/
#endif /* BSWM_J1939DCM_H */
