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
**  FILENAME    : BswM_NvM.h                                                  **
**                                                                            **
**  Created on  : 2020-03-24                                                  **
**  Author      : qinchun.yang                                                **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

#ifndef BSWM_NVM_H
#define BSWM_NVM_H

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
#if (BSWM_NVM_ENABLED == STD_ON)

/**
 * Function called by NvM to inform the BswM about the current state of a multi
 * block job.
 * Service ID: 0x17
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): ServiceId, Indicates whether the callback refers to multi
 *                            block services NvM_ReadAll or NvM_WriteAll
 *                 CurrentJobMode, Current state of the multi block job
 *                            indicated by parameter ServiceId
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_NVM_CODE)
BswM_NvM_CurrentJobMode(NvM_MultiBlockRequestType MultiBlockRequest, NvM_RequestResultType CurrentJobMode);

/**
 * Function called by NvM to indicate the current block mode of an NvM block.
 * To use this function integration code will be needed.
 * Service ID: 0x16
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): Block, The Block that the new NvM Mode corresponds to
 *                 CurrentBlockMode, The current block mode of the NvM block
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_NVM_CODE)
BswM_NvM_CurrentBlockMode(NvM_BlockIdType Block, NvM_RequestResultType CurrentBlockMode);

#endif /*(BSWM_NVM_ENABLED == STD_ON)*/
#endif /* BSWM_NVM_H */
