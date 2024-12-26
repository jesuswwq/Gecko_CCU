/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2023)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : Appl_Cfg.h                                                  **
**                                                                            **
**  Created on  : 2024/05/29 11:13:33                                         **
**  Author      : long.zhu                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Configration file for Appl                                  **
**                                                                            **
**  SPECIFICATION(S) : NONE                                                   **
**                                                                            **
*******************************************************************************/
/******************************************************************************
**                      Revision Control History                             **
******************************************************************************/
/*  <VERSION>    <DATE>      <AUTHOR>     <REVISION LOG>
 *   V1.0.0     20230818     long.zhu        Initial version
 */

#ifndef APPL_CFG_H_
#define APPL_CFG_H_

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/
/** timer delay in bootloader when ECU is startup */
/* @type:uint16 range:0~65535 note:unit ms */
#define APPL_MODE_STAY_TIME                 20u

/** Sleep time count:if configured 0,then no sleep function. */
/* @type:uint16 range:0~65535 note:unit ms */
#define APPL_SLEEP_TIMER                    0u

/** Sleep time count:if configured 0,then no sleep function. */
/* @type:uint16 range:0~65535 note:unit ms */
#define APPL_MAX_PROGATTEMPT                0u

/** Start session when boot initializes. */
#define APPL_START_SESSION                  DCM_SESSION_DEFAULT

/** Start security level when boot initializes. */
#define APPL_START_SECURITY                 DCM_SECURITY_LOCKED

/** Start security access unlock delay when boot initializes. */
#define APPL_START_SECURITY_TIME            10000u

/** Value indicate an external programming request length. */
#define APPL_EXT_PROG_REQUEST_RECEIVED_LENGTH        0x4u

/** Value indicate an external programming request positive response suppression length.  */
#define APPL_EXT_PROG_POSITIVE_RSP_REQUEST_RECEIVED_LENGTH      0x4u

/** Value indicate an app has updated length. */
#define APPL_APPLICATION_UPDATED_LENGTH                     0x4u

/* Value indicate session mode changed from non default session to default session length. */
#define APPL_BOOT_DEFAULT_FROM_PROG_LENGTH           0x4u

/* Value indicate an block consistent validity length. */
#define APPL_BLOCK_CONSISTENT_VALID_LENGTH           0x4u

/* Value indicate an block integrity validity length. */
#define APPL_BLOCK_INTEGRITY_VALID_LENGTH            0x4u

/* programming request location at RAM */
#define BL_APP_FLAG_ADDRESS         0x10000u

/* when client send 10 02, the application set the FL_EXT_PROG_REQUEST_RECEIVED
 * and perform reset, do not response the 10 02 service. so the response of 10
 * 02 service should be in the boot.
 */
#define APPL_RESPONSE_1002_IN_BOOT_AFTER_RESET           (STD_ON)

/* when client send 11 01, the boot perform reset, do not
 * response the 11 01 service. so the response of 11 01
 * service should be in the application.
 */
#define APPL_RESET_RESPONSE_BY_BL   (STD_ON)

#define APPL_SYS_TIME_SEQ_DEBUG_TEST       (STD_OFF)

/* Add by haibin.shao; the macro compiler switch that corresponds to the watchdog on or off */
#define APPL_ENABLE_WATCHDOG_MONITORING_IN_BOOT          STD_ON

/* watchdog feeding time. */
#define APPL_WATCHDOG_FEEDING_TIME          500u

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/
extern const uint8 Appl_extprogrequestreceived[APPL_EXT_PROG_REQUEST_RECEIVED_LENGTH];

extern const uint8 Appl_applicationupdated[APPL_APPLICATION_UPDATED_LENGTH];

extern const uint8 Appl_extprogpositiversprequestreceived[APPL_EXT_PROG_POSITIVE_RSP_REQUEST_RECEIVED_LENGTH];

extern const uint8 Appl_bootdefaultfromprog[APPL_BOOT_DEFAULT_FROM_PROG_LENGTH];

extern const uint8 Appl_blockconsistentvalid[APPL_BLOCK_CONSISTENT_VALID_LENGTH];

extern const uint8 Appl_blockintegrityvalid[APPL_BLOCK_INTEGRITY_VALID_LENGTH];

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#endif /* APPL_CFG_H_ */

