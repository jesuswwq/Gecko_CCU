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
**  FILENAME    : CanSM_Cbk.h                                                 **
**                                                                            **
**  Created on  :                                                             **
**  Author      : Wanglili                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : A list of functions provided for other modules              **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      REVISION   HISTORY                                    **
*******************************************************************************/
/* <VERSION>  <DATE>    <AUTHOR>      <REVISION LOG>
 *  V2.0.0    2020-08-17  lili.wang    R19_11 initial version.
 *  V2.0.1    2021-06-03  lili.wang    include head file modify.
 */
#ifndef CANSM_CBK_H
#define CANSM_CBK_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanSM_Cfg.h"
#include "CanIf_Types.h"
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

/******************************************************************************/
/*
 * Brief               This callback function notifies the CanSM about a bus-off
 *                     event on a certain CAN controller, which needs to be
 *                     considered with the specified bus-off recovery handling
 *                     for the impacted CAN network.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant (only for different CanControllers)
 * Param-Name[in]      ControllerId, CAN controller, which detected a bus-off event
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
FUNC(void, CANSM_CONTROLLERBUSOFF_CODE)
CanSM_ControllerBusOff(uint8 ControllerId);

/******************************************************************************/
/*
 * Brief               This callback shall notify the CanSM module about a CAN
 *                     controller mode change.
 * ServiceId           0x07
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant (only for different CanControllers)
 * Param-Name[in]      ControllerId, CAN controller, whose mode has changed
 *                     ControllerMode, Notified CAN controller mode
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
FUNC(void, CANSM_CONTROLLERNODEINDICATION_CODE)
CanSM_ControllerModeIndication(uint8 ControllerId, CanIf_ControllerModeType ControllerMode);

/******************************************************************************/
/*
 * Brief               This callback shall notify the CanSM module about a CAN
 *                     transceiver mode change.
 * ServiceId           0x09
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different CAN Transceivers
 * Param-Name[in]      TransceiverId, CAN transceiver, whose mode has changed
 *                     TransceiverMode, Notified CAN transceiver mode
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
FUNC(void, CANSM_TRANSCEIVERMODEINDICATION_CODE)
CanSM_TransceiverModeIndication(uint8 TransceiverId, CanTrcv_TrcvModeType TransceiverMode);

#if (STD_ON == CANSM_PNC_SUPPORT)

/******************************************************************************/
/*
 * Brief               This callback function shall indicate the CanIf_ClearTrcvWufFlag
 *                     API process end for the notified CAN Transceiver.
 * ServiceId           0x08
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different CAN Transceivers
 * Param-Name[in]      Transceiver, Requested Transceiver
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
FUNC(void, CANSM_CLEARTRCVWUFFLAGINDICATION_CODE)
CanSM_ClearTrcvWufFlagIndication(uint8 Transceiver);

/******************************************************************************/
/*
 * Brief               This callback function indicates the CheckTransceiverWakeFlag
 *                     API process end for the notified CAN Transceiver
 * ServiceId           0x0a
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different CAN Transceivers
 * Param-Name[in]      Transceiver, Requested Transceiver
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
FUNC(void, CANSM_CHECKTRANSCEIVERWAKEFLAGINDICATION_CODE)
CanSM_CheckTransceiverWakeFlagIndication(uint8 Transceiver);

/******************************************************************************/
/*
 * Brief               This callback function indicates that the transceiver is
 *                     running in PN communication mode
 * ServiceId           0x06
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      TransceiverId, CAN transceiver, which was checked for PN
 *                     availability
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
FUNC(void, CANSM_CONFIRMPNAVAILABILITY_CODE)
CanSM_ConfirmPnAvailability(uint8 TransceiverId);

#endif /*STD_ON == CANSM_PNC_SUPPORT*/

#if (STD_ON == CANSM_ICOM_SUPPORT)

/******************************************************************************/
/*
 * Brief               This service shall inform about the change of the Icom
 *                     Configuration of a CAN network.
 * ServiceId           0x10
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant only for different network handles
 * Param-Name[in]      ControllerId, CAN Controller Id, whose configuration has
 *                     changed.
 *                     ConfigurationId, Changed Configuration Id
 *                     Error, ICOM_SWITCH_E_OK: No Error
 *                            ICOM_SWITCH_E_FAILED: Switch to requested
 *                            Configuration failed. Severe Error.
 * Param-Name[in/out]  NA
 * Param-Name[out]     NA
 * Return              NA
 */
/******************************************************************************/
FUNC(void, CANSM_CURRENTICOMCONFIGURATION_CODE)
CanSM_CurrentIcomConfiguration(uint8 ControllerId, IcomConfigIdType ConfigurationId, IcomSwitch_ErrorType Error);

#endif /*STD_ON == CANSM_ICOM_SUPPORT*/
#endif /* CANSM_CBK_H */
