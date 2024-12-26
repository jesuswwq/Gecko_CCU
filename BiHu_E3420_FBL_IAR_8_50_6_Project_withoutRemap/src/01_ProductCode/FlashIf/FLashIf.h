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
**  FILENAME    : FLashIf.h                                                   **
**                                                                            **
**  Created on  :                                                             **
**  Author      : yaowei.shen                                             	  **
**  Vendor      :                                                             **
**  DESCRIPTION : Type define and function decalrations for Blflash           **
**                                                                            **
**  SPECIFICATION(S) :   his flash driver v130.pdf		                      **
**                                                                            **
*******************************************************************************/
/******************************************************************************
**                      Revision Control History                             **
******************************************************************************/
/*  <VERSION>    <DATE>   	 <AUTHOR>   	 <REVISION LOG>
 *  V1.0.0       20230719  yaowei.shen      add macro  FLASH_ENABLE_INTERRUPT/
                                            FLASH_DISABLE_INTERRUPT/FLASH_PARAM_CHECK		
 */

#ifndef FLASHIF_H
#define FLASHIF_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
#include "FlashIf_Cfg.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/**Error codes */
#define kFlashOk							0x0000u
#define kFlashFailed						0x0001u
#define Flash_E_UNINIT						0x0002u
#define Flash_E_REINIT						0x0003u
#define Flash_E_PARAM_LENGTH				0x0004u
/* API service called with a NULL pointer */
#define Flash_E_PARAM_POINTER           	0x0005u
#define Flash_E_VERSION			           	0x0006u

/* check the range of the operate address and length error */
#define Flash_E_CHECK_ADDRESS_LENGTH       	0x0007u
/*Parameter check control macro*/
#define FLASH_PARAM_CHECK                           STD_ON

/*Interrupt fun*/
#define FLASH_ENABLE_INTERRUPT                      /*interrupt fun*/
#define FLASH_DISABLE_INTERRUPT                     /*interrupt fun*/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* flash driver major version number */
typedef uint8 tMajorVersion;

/* flash driver minor version number */
typedef uint8 tMinorVersion;

/* bugfix / patchlevel number */
typedef uint8 tBugfixVersion;

/* result of flash driver routines */
typedef uint16 tFlashResult;

/* logical address */
typedef uint32 tFlashAddress;

/* length (in bytes) */
typedef uint32 tFlashLength;

/* ambiguous data */
typedef uint8 tFlashData;

/* watchdog trigger routine */
typedef void (*tWDTriggerFct)(void);

/* the status to indication the FALSH is init or not */
typedef enum
{
	FLASH_UNINIT = 0u,
	FLASH_INIT   = 1u
}Flash_StatusType;

/** initialization: input parameters */
typedef struct
{
    /* flash driver patch level version */
    tBugfixVersion patchLevel;

    /* flash driver minor version number */
    tMajorVersion minorNumber;

    /* flash driver major version number */
    tMinorVersion majorNumber;

    /* flash init status */
    Flash_StatusType flashstatus;

    /* retrun value / error code: output parameters */
    tFlashResult errorCode;

    /* reserved for future use, set to 0x0000 for now */
    uint16 reserved2;

    /* erase / write: input parameters */
    /* logical target address */
    tFlashAddress address;

    /* length information (in bytes) */
    tFlashLength length;

    /* pointer to data buffer */
    const tFlashData *  data;

    /* pointer to data buffer */
    tFlashData *  readData;

    /* pointer to watch-dog trigger routine */
    tWDTriggerFct wdTriggerFct;

} tFlashParam;

/* prototype of flash driver routine */
typedef void (*tFlashFct)(tFlashParam* flashParam);

/** flash infomation table */
typedef struct
{
    /* Motorola Star12 */
    const uint8 mcuType;

    /* some mask number */
    const uint8 maskType;

    /* byte reserved for future use */
    const uint8 reserve;

    /* interface version number */
    const uint8 interface;

    /* flash initialize function */
    const tFlashFct flashInitFct;

    /* flash de-initialize function */
    const tFlashFct flashDeInitFct;

    /* flash erase function */
    const tFlashFct flashEraseFct;

    /* flash program function */
    const tFlashFct flashWriteFct;
	
    const tFlashFct flashReadFct;
} tFlash_InfoType;

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/
extern const tFlash_InfoType* BLFlash_InfoPtr;
/**
 * extern const uint8 flsFile[];
 * extern const uint32 flsFile_length;
 */
/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#endif /* endif of FLASHIF_H */

