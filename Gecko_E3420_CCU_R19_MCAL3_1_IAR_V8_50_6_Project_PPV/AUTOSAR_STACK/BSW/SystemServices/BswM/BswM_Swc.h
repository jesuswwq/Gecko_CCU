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
**  FILENAME    : BswM_Swc.h                                                  **
**                                                                            **
**  Created on  : 2020-03-24                                                  **
**  Author      : qinchun.yang                                                **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

#ifndef BSWM_SWC_H
#define BSWM_SWC_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "BswM_Internal.h"
#if (BSWM_RTE_ENABLED == STD_ON)
#include "Rte_BswM.h"
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

/**
 * This is a notification that an error occurred because the partition containing
 * the mode users of the Mode Declaration Group Prototype was restarted by the
 * RTE. Because the Mode Machine Instance holding the current mode can reside on
 * that terminated partition, the Mode Manager has to be informed about the loss
 * of this partition.
 * Service ID:
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): portId, the id of switch port
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_SWC_CODE)
BswM_SwcModeSwitchErrorNotification(uint16 portId);

/**
 * Function called when a SWC has switched a mode.
 * Service ID: 0x
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): modeGroup, the mode group in that the mode was switched
 *                 mode, the mode that was switched to.
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_SWC_CODE)
BswM_SwcModeNotification(BswM_ModeGroupType modeGroup, BswM_ModeType mode);

/**
 * Function called when a SWC request a mode.
 * Service ID: 0x
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): modeGroup, the mode group in that the mode was requested
 *                 mode, the mode that was request
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 */
FUNC(void, BSWM_SWC_CODE)
BswM_SwcModeRequest(BswM_ModeGroupType modeGroup, BswM_ModeType mode);

#endif /*(BSWM_RTE_ENABLED == STD_ON)*/
#endif /* BSWM_SWC_H */
