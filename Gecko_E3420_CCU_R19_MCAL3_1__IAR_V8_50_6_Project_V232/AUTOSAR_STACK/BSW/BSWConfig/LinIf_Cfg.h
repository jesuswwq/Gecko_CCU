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
**  FILENAME    : LinIf_Cfg.h                                                 **
**                                                                            **
**  Created on  : 2024/01/09 10:06:23                                 **
**  Author      : HuRongbo                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Pre-compile configuration parameter of LinIf                **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform  R19-11                     **
**                                                                            **
*******************************************************************************/

#ifndef LINIF_CFG_H
#define LINIF_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* Switch to enable/disable the APIs LinIf_CancelTransmit/LinTp_CancelReceive */
#define LINIF_CANCEL_TRANSMIT_SUPPORTED STD_OFF

/* Switches the Development Error Detection ON or OFF */
#define LINIF_DEV_ERROR_DETECT          STD_ON

/* Switches the multiple drivers ON or OFF */
#define LINIF_MULTIPLE_DRIVER_SUPPORT   STD_OFF

/* Switches the multiple transceiver drivers ON or OFF */
#define LINIF_MULTIPLE_TRCV_DRIVER_SUPPORT STD_OFF

/* States if the node configuration commands Assign NAD and Conditional Change NAD are supported. */
#define LINIF_NC_OPTIONAL_REQUEST_SUPPORTED STD_OFF

#if 0
/* This parameter contains the name of the callout function that is called after
 * a response error signal change. Only applicable for LIN slave nodes.*/
#define LinIfResponseErrorSignalChangedCallout  NULL_PTR

/* This parameter contains the name of the callout function that is called when 
 * a save configuration node configuration command is processed by this slave
 * node. The service is only supported when this parameter is configured.
 * Only applicable for LIN slave nodes.*/
#define LinIfSaveConfigurationCallout  NULL_PTR
#endif

/* Switches the TP ON or OFF */
#define LINIF_TP_SUPPORTED              STD_OFF

/* States if transceiver driver support is included in the LIN Interface or not. */
#define LINIF_TRCV_DRIVER_SUPPORTED     STD_OFF

/* Switches the LinIf_GetVersionInfo function ON or OFF */
#define LINIF_VERSION_INFO_API          STD_OFF

/* Null-schedule index */
#define LINIF_NULL_SCHEDULE_INDEX       0u

#define LinIfScheduleTable_Schedule1_LIN1  1
#define LinIfScheduleTable_Schedule2_LIN1  2
#define LinIfScheduleTable_Schedule1_LIN2  3
#define LinIfScheduleTable_Schedule2_LIN2  4
#define LinIfScheduleTable_Schedule1_LIN3  5

#define LINIF_NUMBER_OF_CHANNELS        3u

#define LINIF_MASTER_CHANNEL_NUMBER     3u
#define LINIF_SLAVE_CHANNEL_NUMBER      0u
#define LINIF_MASTER_FRAME_NUM          48u
#define LINIF_SLAVE_FRAME_NUM           0u

#define LINIF_NUMBER_OF_DRIVERS         3u

/* When processing the go-to-sleep command,After this time MainFunction shall call
   the function Lin_GetStatus to check the bus state */
#define LINIF_SLEEP_MODE_FRAME_DELAY    4u

#define LINIF_LIN_CHANNEL_WAKEUP_SUPPORT        STD_ON

#define LINIF_LIN_TRCV_WAKEUP_SUPPORT            STD_OFF

#define LINIF_WAKEUP_SUPPORT            STD_ON

#define LINIF_SLAVE_SUPPORT      STD_OFF
#define LINIF_MASTER_SUPPORT     STD_ON

/* If set to true, enables the LinTp_ChangeParameterRequest Api for this Module. */
#define LINTP_CHANGE_PARAMETER_API        STD_OFF

/* Switches the LinTp_GetVersionInfo function ON or OFF */
#define LINTP_VERSION_INFO_API            STD_OFF

#define LINTP_PADDING_VALUE             0xff

#define LINTP_NUMBER_OF_CHANNELS             1u

#define LINTP_MASTER_CHANNEL_NUMBER           1u

#define LINTP_SLAVE_CHANNEL_NUMBER            0u

/* PRQA S 0791 ++ */ /* MISRA Rule 5.4 */
#define LINIF_TXPDU_HP_EXV_Cmd_LIN1      0
#define LINIF_TXPDU_BAT_EXV_Cmd_LIN1      1
#define LINIF_TXPDU_AC_EXV_Cmd_LIN1      2
#define LINIF_TXPDU_MCV_Cmd_LIN1      3
#define LINIF_TXPDU_BCV_Cmd_LIN1      4
#define LINIF_TXPDU_PMP_Cmd_LIN1      5
#define LINIF_TXPDU_AC_EXV_Cmd_LIN2      6
#define LINIF_TXPDU_BAT_EXV_Cmd_LIN2      7
#define LINIF_TXPDU_C3WV_Cmd_LIN2      8
#define LINIF_TXPDU_C5WV_Cmd_LIN2      9
#define LINIF_TXPDU_HP_EXV_Cmd_LIN2      10
#define LINIF_TXPDU_PMP_Cmd_LIN2      11
#define LINIF_TXPDU_CCU_FCLCommand_LIN3      12
#define LINIF_TXPDU_Frm_VehicleToInterlock_LIN3      13
/* PRQA S 0791 -- */ /* MISRA Rule 5.4 */

#define LINTP_RXPDU_CCU_SlaveResp      0

#define LINTP_TXPDU_CCU_MasterReq      0

#endif /* LINIF_CFG_H */

