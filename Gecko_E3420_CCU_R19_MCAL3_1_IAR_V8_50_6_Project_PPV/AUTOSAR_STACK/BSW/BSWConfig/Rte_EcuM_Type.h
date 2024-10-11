
/******************************************************************************
**                                                                           **
** Copyright (C) iSOFT   (2022)                                              **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to iSOFT.        **
** Passing on and copying of this document, and communication                **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Rte_EcuM_Type.h                                            **
**                                                                           **
**  AUTHOR      :                                                            **
**                                                                           **
**  VENDOR      :                                                            **
**                                                                           **
**  DESCRIPTION :This file is partly ECU dependent.                          **
**                                                                           **
**                                                                           **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R1911                      **
**                                                                           **
******************************************************************************/
#ifndef RTE_ECUM_TYPE_H
#define RTE_ECUM_TYPE_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/*ERROR Code of Std_ReturnType for an earlier alarm is already set*/
#define ECUM_E_EARLIER_ACTIVE 0x03u
/*ERROR Code of Std_ReturnType for the given point in time has already passed*/
#define ECUM_E_PAST           0x04u
/*ERROR Code of Std_ReturnType for no active alarm found*/
#define ECUM_E_NOT_ACTIVE     0x05u

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/*ECUM Mode, represents the modes of the ECU State Manager module that will be
 * notified to the SW-Cs*/
typedef uint8 EcuM_ModeType;
#define ECUM_MODE_STARTUP    0x00u
#define ECUM_MODE_RUN        0x01u
#define ECUM_MODE_POST_RUN   0x02u
#define ECUM_MODE_SLEEP      0x03u
#define ECUM_MODE_SHUTDOWN   0x04u
#define ECUM_MODE_WAKE_SLEEP 0x05u

/*Unique value for each user.
 *The integrator shall define a unique value for each user at system generation time.
 */
typedef uint8 EcuM_UserType;

/*This type describes the cause for a shutdown by the ECU State Manager.
 *It can be extended by configuration.*/
typedef uint8 EcuM_ShutdownCauseType;
#define ECUM_CAUSE_UNKNOWN    (EcuM_ShutdownCauseType)0u
#define ECUM_CAUSE_ECU_STATE  (EcuM_ShutdownCauseType)1u
#define ECUM_CAUSE_WDGM       (EcuM_ShutdownCauseType)2u
#define ECUM_CAUSE_DCM        (EcuM_ShutdownCauseType)3u

/*This data type represents the modes of the ECU Manager module*/
typedef uint16 EcuM_ShutdownModeType;

/*This data type represents the time of the ECU Manager module*/
typedef uint32 EcuM_TimeType;

typedef uint8 EcuM_ShutdownTargetType;
typedef EcuM_ShutdownTargetType       EcuM_DefaultShutdownTargetType;
#define ECUM_SHUTDOWN_TARGET_SLEEP    (uint8)0u
#define ECUM_SHUTDOWN_TARGET_RESET    (uint8)1u
#define ECUM_SHUTDOWN_TARGET_OFF      (uint8)2u

/*This type represents the boot targets the ECU Manager module can be configured with.*/
typedef uint8 EcuM_BootTargetType;
#define ECUM_BOOT_TARGET_APP               (EcuM_BootTargetType)0u
#define ECUM_BOOT_TARGET_OEM_BOOTLOADER    (EcuM_BootTargetType)1u
#define ECUM_BOOT_TARGET_SYS_BOOTLOADER    (EcuM_BootTargetType)2u

#endif /* RTE_ECUM_TYPE_H */

