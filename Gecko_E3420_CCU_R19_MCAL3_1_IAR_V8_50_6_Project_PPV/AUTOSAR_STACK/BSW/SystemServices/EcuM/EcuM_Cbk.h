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
**  FILENAME    : EcuM_Cbk.c                                                 **
**                                                                            **
**  Created on  :                                                             **
**  Author      : qinchun.yang                                                **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*  <VERSION>    <DATE>      <AUTHOR>        <REVISION LOG>
 *  V1.0.0       2020-06-28  qinchun.yang    R19_11 EcuM initial version.
 *  V2.0.0       2021-04-08  qinchun.yang    R1911 stable version.
 */
#ifndef ECUM_CBK_H
#define ECUM_CBK_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "EcuM_Types.h"
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
 * Sets the wakeup event.
 * Sets (OR-operation) all events passed as a bit set in the sources in parameter
 * (EcuM_WakeupSourceType bitmask) in the internal pending wakeup events variable.
 * Start the wakeup validation timeout timer.
 * Shall ignore all events passed in the sources parameter not associated to the
 * selected sleep mode.
 * Must be callable from interrupt context, from OS context and an OS-free context.
 * Service ID[hex]: 0x0c
 * Sync/Async: Synchronous
 * Reentrancy: Non-Reentrant, Non-Interruptible
 * Parameters (in): sources, value to be set
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_SETWAKEUPEVENT_CODE) EcuM_SetWakeupEvent(EcuM_WakeupSourceType sources);

/**
 * After wakeup, the ECU State Manager will stop the process during the WAKEUP
 * VALIDATION state/sequence to wait for validation of the wakeup event.
 * This API service is used to indicate to the ECU Manager module that the wakeup
 * events indicated in the sources parameter have been validated.
 * Service ID[hex]: 0x14
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): sources, events that have been validated
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_VALIDATEWAKEUPEVENT_CODE) EcuM_ValidateWakeupEvent(EcuM_WakeupSourceType sources);

/**
 * This callout is called by the EcuM to poll a wakeup source.
 * It shall also be called by the ISR of a wakeup source to set up the PLL and
 * check other wakeup sources that may be connected to the same interrupt.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): wakeupSource
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_CHECKWAKEUP_CODE) EcuM_CheckWakeup(EcuM_WakeupSourceType wakeupSource);

#endif /* ECUM_CBK_H */
