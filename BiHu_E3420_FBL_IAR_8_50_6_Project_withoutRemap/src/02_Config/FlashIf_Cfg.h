
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
**  FILENAME    : FlashIf_Cfg.h                                               **
**                                                                            **
**  Created on  : 2023/02/06 10:03:19                                         **
**  Author      : long.zhu                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Configuration parameter of FlashIf                          **
**                                                                            **
**  SPECIFICATION(S) :  NONE                                                  **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *  V1.0.0     20230818    long.zhu          Initial Version
 */
#ifndef FLASHIF_CFG_H
#define FLASHIF_CFG_H

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/

#define FLS_USED                        STD_OFF

/*hardware version information*/
/* mcu type */
/** Motorola Star12 */
#define FLASH_DRIVER_VERSION_MCUTYPE   0x12u

/** some mask number */
#define FLASH_DRIVER_VERSION_MASKTYPE  0xabu

/** interface version number */
#define FLASH_DRIVER_VERSION_INTERFACE 0x1u

/*software version information */
/** major version number / interface */
#define FLASH_DRIVER_VERSION_MAJOR      0x1u

/** minor version number / internal */
#define FLASH_DRIVER_VERSION_MINOR      0x1u

/** bugfix / patchlevel */
#define FLASH_DRIVER_VERSION_PATCH      0x0u

/** config if flash driver is compiled */
#define FLASH_COMPILED                STD_OFF

/* Eight 16k, one 128k nine 256k */
#define FLASH_ONE_SECTOR               (16384u)

#define FLASH_ONE_PHRASE               (8u)

/* address of api set in flash driver */
#define FLASH_INFO_ADDRESS             0x484000u

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#endif /* end of FLASHIF_CFG_H */

