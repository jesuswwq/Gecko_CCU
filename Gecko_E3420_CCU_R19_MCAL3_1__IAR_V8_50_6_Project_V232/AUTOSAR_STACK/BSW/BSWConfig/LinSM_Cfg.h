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
**  FILENAME    : LinSM_Cfg.h                                                 **
**                                                                            **
**  Created on  :                                                             **
**  Author      : HuRongbo                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Pre-compile configuration parameter of LinSM                **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

#ifndef LINSM_CFG_H
#define LINSM_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* configuration variants */
#define LINSM_VARIANT_PC    0
#define LINSM_VARIANT_LT    1
#define LINSM_VARIANT_PB    2

/* configuration variants switch */
#define LINSM_VARIANT_CFG     LINSM_VARIANT_PC

/*Switches the Default Error Tracer (Det) detection and notification ON or OFF.*/
#define LINSM_DEV_ERROR_DETECT             STD_ON

/*Fixed period that the MainFunction shall be called.*/
#define LINSM_MAIN_PROCESSING_PERIOD       5u

/*Switches the LinSM_GetVersionInfo function ON or OFF.*/
#define LINSM_VERSION_INFO_API             STD_OFF

/* channel number */
#define LINSM_CHANNEL_NUM                  3u

/* switch for LinSMTransceiverPassiveMode */
/* The APIs LinIf_SetTrcvMode() will only be called when this parameter is enabled.*/
#define LINSM_TRANSCEIVER_PASSIVER_MODE_SUPPORT    STD_OFF

/* Indiacate wheater support MASTER/SLAVE node */    
#define LINSM_MASTER_NODE_SUPPORT                   STD_ON
#define LINSM_SLAVE_NODE_SUPPORT                    STD_OFF

/* Null-schedule index */
#define LINSM_NULL_SCHEDULE_INDEX           0u
#define LINSM_LinIfScheduleTable_Schedule1_LIN1  LinIfScheduleTable_Schedule1_LIN1
#define LINSM_LinIfScheduleTable_Schedule2_LIN1  LinIfScheduleTable_Schedule2_LIN1
#define LINSM_LinIfScheduleTable_Schedule1_LIN2  LinIfScheduleTable_Schedule1_LIN2
#define LINSM_LinIfScheduleTable_Schedule2_LIN2  LinIfScheduleTable_Schedule2_LIN2
#define LINSM_LinIfScheduleTable_Schedule1_LIN3  LinIfScheduleTable_Schedule1_LIN3

/* LinSM ScheduleTable Index define for BswM */
#define LinSMSchedule_Schedule1_LIN1 LINSM_LinIfScheduleTable_Schedule1_LIN1
#define LinSMSchedule_Schedule2_LIN1 LINSM_LinIfScheduleTable_Schedule2_LIN1
#define LinSMSchedule_Schedule1_LIN2 LINSM_LinIfScheduleTable_Schedule1_LIN2
#define LinSMSchedule_Schedule2_LIN2 LINSM_LinIfScheduleTable_Schedule2_LIN2
#define LinSMSchedule_Schedule1_LIN3 LINSM_LinIfScheduleTable_Schedule1_LIN3

#endif /* LINSM_CFG_H */

