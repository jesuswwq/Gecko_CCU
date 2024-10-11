
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
**  FILENAME    : Nm_Cfg.h                                                    **
**                                                                            **
**  Created on  :                                                             **
**  Author      : Wanglili                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
#ifndef NM_CFG_H_
#define NM_CFG_H_
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* NmGlobalConstants */

/* NUMBER OF NM CHANNELS ALLOWED WITHIN ONE ECU. */
#define NM_NUMBER_OF_CHANNELS                                           (4u)

/* NUMBER OF NM CLUSTER ALLOWED WITHIN ONE ECU. */
#define NM_NUMBER_OF_CLUSTERS                                           (0u)

/* NmGlobalProperties */

/* Switches the Default Error Tracer (Det) detection and notification ON or
OFF */
#define NM_DEV_ERROR_DETECT                         STD_ON

/* Pre-processor switch for enabling Version Info API support. */
#define NM_VERSION_INFO_API                        STD_OFF

/* NmGlobalFeatures */

/* Pre-processor switch for enabling support of Passive Mode of the <BusNm>s. */
/* dependency: NmPassiveModeEnable == ComMNmPassiveModeEnable */
#define NM_PASSIVE_MODE_ENABLED                                         STD_OFF

/* Pre-processor switch for enabling Remote Sleep Indication support. */
/* dependency: It must not be enabled if NM_PASSIVE_MODE_ENABLED is enabled. */
#define NM_REMOTE_SLEEP_IND_ENABLED                                      STD_OFF

/* Pre-processor switch for enabling NM Coordinator support. */
/* dependency: Only valid if NM_REMOTE_SLEEP_IND_ENABLED AND*/
#define NM_COORDINATOR_SUPPORT_ENABLED                                 STD_OFF

/* Pre-processor switch for enabling bus synchronization support of the
<BusNm>s. This feature is required for NM Coordinator nodes only. */
/* dependency: This parameter must be enabled if
NM_COORDINATOR_SUPPORT_ENABLED is enabled. */
#define NM_BUS_SYNCHRONIZATION_ENABLED                                 STD_OFF

/* link time */
/* Enables or disables CWU detection. */
#define NM_CAR_WAKE_UP_RX_ENABLED                                    STD_OFF

/* Pre-processor switch for enabling the Communication Control support. */
#define NM_COM_CONTROL_ENABLED                                      STD_ON

/* Enable/Disable setting of NMUserData via SW-C. */
#define NM_COM_USER_DATA_SUPPORT                                    STD_ON

/* link time */
/* Enables/disables the coordinator synchronisation support. */
/* dependency: NmCoordinatorSyncSupport shall only be valid if*/
#define NM_COORDINATOR_SYNC_SUPPORT                                  STD_OFF

/* Pre-processor switch for enabling transmission of the source node
identifier in NM messages. */
#define NM_NODE_ID_ENABLED                                        STD_ON

/* Pre-processor switch for enabling the Node Detection feature. */
/* dependency: Only valid if NM_NODE_ID_ENABLED is set to TRUE */
#define NM_NODE_DETECTION_ENABLED                                   STD_ON

/* Pre-processor switch for enabling the PDU Rx Indication */
#define NM_PDU_RX_INDICATION_ENABLED                               STD_ON

/* Pre-processor switch for enabling the Repeat Message Bit Indication. */
#define NM_REPEAT_MSG_IND_ENABLED                                   STD_OFF

/* Pre-processor switch for enabling the Network Management state
change notification. */
#define NM_STATE_CHANGE_IND_ENABLED                                  STD_ON

/* Pre-processor switch for enabling User Data support. */
#define NM_USER_DATA_ENABLED                                           STD_ON

/* nm support com api Com_SendSignal */
#define NM_SUPPORT_COM_SENDSIGNAL                                       STD_ON
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/
/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
#endif/* NM_CFG_H_ */

