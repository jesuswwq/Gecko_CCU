
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
**  FILENAME    : FL_Cfg.h                                                    **
**                                                                            **
**  Created on  : 2023/09/20 13:23:56                                         **
**  Author      : long.zhu                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Flash Loader Configuration.                                 **
**                                                                            **
**  SPECIFICATION(S) : NONE                                                   **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *  V1.0.0     20230818    long.zhu          Initial Version
 */

#ifndef FL_CFG_H
#define FL_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Appl_Cfg.h"
#include "Std_Types.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/*===============[A P P   I N F O]============================================*/
/* Total number of program blocks of this project,
 * should configure for the max number;
 * @type:uint8 range:1~255 note:reference to number of FL_BlkInfo;
 */
#define FL_NUM_LOGICAL_BLOCKS       1u

/* Maximum of segment in one block.
 * @type:uint8 range:1~255 note:NONE ;
 */
#define FL_MAX_SEGMENTS             60u

/* code flash size that should program once time;
 * @type:uint32 range:NONE
 */
#define FL_PROGRAM_SIZE             256

/* Value for fill gap */
/* @type:uint8 range:0x00~0xFF */
#define FL_GAP_FILL_VALUE           0xffu

/* Application Start address,
 * the start code of APP.
 * @type:uint32
 */
#define FL_APP_START_ADDR           0x101c0000u

/*===============[A P P   I N F O]============================================*/

/* BOOTLAODER information global address in DFlash,or PFlash ;
 * the detail information should see FL_BlkIntegrityNvmInfoType ;
 * the detail information should see FL_SecurityAccessNvmInfoType ;
 * the detail information should see FL_ProgramMarkNvmInfoType ;
 * @type:uint32 range:NONE
 */
#define FL_BLOCK_INTEGRITY_INFO_ADDRESS         (0x0u)

#define FL_SECURITYACCESS_NVM_INFO_ADDRESS      (0x0u)

#define FL_PROGRAMMARK_NVM_INFO_ADDRESS         (0x0u)

/* Number of security access levels supported */
/* @type:uint16 range:1~65535 note:NONE */
#define FL_SECURITY_ACCESS_LEVELS_NUM    1u

/** Length of finger print information */
/* @type:uint16 range:1~65535 note:NONE */
#define FL_FINGER_PRINT_LENGTH         0xau

/* Finger print write enable or not. */
#define FL_FINGER_PRINT_WRITE_ENABLE     STD_ON

/* Structure alignment length. */
#define FL_PROGRAMMARKNVMINFOTYPE_ALIGN_LENGTH  0x1u

/* 38 Service enable or not */
#define FL_SERVICE_0X38_ENABLE          STD_OFF

/* AB swap enable or not */
#define FL_ABSWAP_ENABLE                    STD_ON

/*===============[A P P   I N F O]============================================*/

#define FL_PROG_PRE_CONDITION_USED     STD_OFF

/*=======[F L A S H   D R I V E R]============================================*/
/** Start address of flash driver in RAM. LOCAL address */
/* @type:uint32 range:0x00000000~0xFFFFFFFF note:NONE */
#define FL_FLASH_DRIVER_BASE_ADDRESS        0x484000u

/** Length of flash driver in RAM. */
/* NORMAL IS 8K BYTES*/
/* @type:uint32 range:0x00000000~0xFFFFFFFF note:NONE */
#define FL_FLASH_DRIVER_SIZE                0x4b000u

/* Value indicate flash driver integrity validity check. */
#define FL_FLASH_DRIVER_INTEGRITY_VALID_CHECK   STD_ON

/* Value indicate flash driver integrity validity length. */
#define FL_FLASH_DRIVER_INTEGRITY_VALID_LENGTH                     0x4u /*PRQA S 0791*/

/* Value indicate flash driver integrity validity address. */
#define FL_FLASH_DRIVER_INTEGRITY_VALID_ADDRESS                    (FL_FLASH_DRIVER_BASE_ADDRESS+FL_FLASH_DRIVER_SIZE-FL_FLASH_DRIVER_INTEGRITY_VALID_LENGTH) /*PRQA S 0791*/

/*=======[F L A S H   D R I V E R]============================================*/

/* PFLASH maximum number of sectors erased per time */
/* Each sector in programming FLASH is 16K ,that is 0x4000 */
/* If set erasing max sector number is 0x40000, that is 16 sectors */
#define FL_MAX_SECTORS_PER_ERASE            0x40000u

/* Segmentation sector erase function is enabled */
#define FL_SPLIT_SECTORS_ERASE_ENABLED      STD_ON

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

#if (FL_FLASH_DRIVER_INTEGRITY_VALID_CHECK == STD_ON)
extern const uint8 FL_flashdriverintegrityvalid[FL_FLASH_DRIVER_INTEGRITY_VALID_LENGTH];
#endif

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#endif/* endif of FL_CFG_H */

