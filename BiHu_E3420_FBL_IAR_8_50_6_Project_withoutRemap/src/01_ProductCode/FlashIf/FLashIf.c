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
**  FILENAME    : FlashIf.c                                                   **
**                                                                            **
**  Created on  :                                                             **
**  Author      :  yaowei.shen                                                **
**  Vendor      :                                                             **
**  DESCRIPTION : provide the environment of the Bootloader peoject           **
**                                                                            **
**  SPECIFICATION(S) :   his flash driver v130.pdf		                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *  V1.0.0      20160613   lianren.wu	     Initial Version
 *  V1.0.1		20210106   liarnen.wu		 add the error para and uninit check.
 *  V1.0.2		20230209   yaowei.shen		 modify flash init flag Flash_Status-> 
 *											 tFlashParam struct member flashstatus.
 *											 BLFlash_Info fixed address for use in boot.
 *  V1.0.2      20230727   yaowei.shen       add macro FLASH_DISABLE_INTERRUPT/FLASH_ENABLE_INTERRUPT
 */
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "FLashIf.h"
#include "FL_Cfg.h"
#include "Rte_Inc.h"
/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
#if defined PROJECT_FLS_ENABLE || defined PROJECT_FLS
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
static void FlashIf_Init(tFlashParam* flashParam);
static void FlashIf_Deinit(tFlashParam* flashParam);
static void FlashIf_Erase(tFlashParam* flashParam);
static void FlashIf_Write(tFlashParam* flashParam);
static void FlashIf_Read(tFlashParam* flashParam);
static tFlashResult Flash_CheckArea(tFlashAddress startAddress, tFlashAddress endAddress);
#endif
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/
/** flash driver header define */
#if defined PROJECT_FLS_ENABLE || defined PROJECT_FLS
#ifdef PROJECT_FLS
__attribute__((section(".BlFlash_Info_ram")))
#endif
const tFlash_InfoType BLFlash_Info =
{
	FLASH_DRIVER_VERSION_MCUTYPE,
	FLASH_DRIVER_VERSION_MASKTYPE,
    0x00,
    FLASH_DRIVER_VERSION_INTERFACE,
    &FlashIf_Init,
    &FlashIf_Deinit,
    &FlashIf_Erase,
    &FlashIf_Write,
    &FlashIf_Read
};
const tFlash_InfoType* BLFlash_InfoPtr = (tFlash_InfoType*)&BLFlash_Info;
#else
const tFlash_InfoType* BLFlash_InfoPtr = (tFlash_InfoType*)FL_FLASH_DRIVER_BASE_ADDRESS;/*PRQA S 0306*/
#endif
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
#if defined PROJECT_FLS_ENABLE || defined PROJECT_FLS
/******************************************************************************/
/*
 * Brief               <flash initialize function>
 * <process version check and flash register initialize> .
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <NONE>      
 * Param-Name[out]     <NONE>
 * Param-Name[in/out]  <flashParam (IN/OUT)>
 * Return              <NONE>  
 */
/******************************************************************************/
static void FlashIf_Init(tFlashParam* flashParam)
{
#if (FLASH_PARAM_CHECK == STD_ON)	
	if(FLASH_UNINIT != flashParam->flashstatus)
	{
		flashParam->errorCode = Flash_E_UNINIT;
	}
	else if(flashParam == NULL_PTR)
	{
		return;
	}
    /* version check */
	else if ((FLASH_DRIVER_VERSION_PATCH != flashParam->patchLevel) ||
            (FLASH_DRIVER_VERSION_MINOR != flashParam->minorNumber) ||
            (FLASH_DRIVER_VERSION_MAJOR != flashParam->majorNumber))
    {
        flashParam->errorCode = Flash_E_VERSION;
    }
    else
#endif
    {
        if(TRUE == Rte_FlashInit())
        {
	    	flashParam->flashstatus = FLASH_INIT;
	    	flashParam->errorCode = kFlashOk;
        }
    	/* init the flash or this chip here, if init failed,
    	 * should set flashParam->errorCode to kFlashFailed. */
    	/* todo */
    }

    return;
}
/******************************************************************************/
/*
 * Brief               <Flash DeInit>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <NONE>      
 * Param-Name[out]     <NONE>
 * Param-Name[in/out]  <flashParam (IN/OUT)>
 * Return              <NONE>  
 */
/******************************************************************************/
static void FlashIf_Deinit(tFlashParam* flashParam)
{
#if (FLASH_PARAM_CHECK == STD_ON)	
	if(FLASH_UNINIT == flashParam->flashstatus)
	{
		flashParam->errorCode = Flash_E_UNINIT;
	}
	else
#endif
	{
	    /* deinit the flash or this chip here, if deinit failed,
	     * should set flashParam->errorCode to kFlashFailed. */
	    /* todo */
        if(TRUE == Rte_FlashDeInit())
        {
	    	flashParam->flashstatus = FLASH_UNINIT;
	    	flashParam->errorCode = kFlashOk;
        }
	}

    return;
}

/******************************************************************************/
/*
 * Brief               <Flash Erase>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <NONE>      
 * Param-Name[out]     <NONE>
 * Param-Name[in/out]  <flashParam >
 * Return              <NONE>  
 */
/******************************************************************************/
static void FlashIf_Erase(tFlashParam* flashParam)
{
	tFlashAddress	eraseStartAddress = flashParam->address;
	tFlashAddress	eraseEndAddress   = flashParam->address + flashParam->length - 1u;
	tFlashResult	checkResult;

#if (FLASH_PARAM_CHECK == STD_ON)
	if(FLASH_UNINIT == flashParam->flashstatus)
	{
		flashParam->errorCode = Flash_E_UNINIT;
	}
	else if(flashParam->length == 0u)
	{
		flashParam->errorCode = Flash_E_PARAM_LENGTH;
	}
	else
#endif
	{
		/* Check the erase Address and length is in the range or not. */
		checkResult = Flash_CheckArea(eraseStartAddress, eraseEndAddress);

		if(checkResult == Flash_E_CHECK_ADDRESS_LENGTH)
		{
			flashParam->errorCode = Flash_E_CHECK_ADDRESS_LENGTH;
		}
		else
		{
			/* watchDog function */
			if (flashParam->wdTriggerFct != NULL_PTR )
			{
				flashParam->wdTriggerFct();
#if defined PROJECT_FLS_ENABLE || defined PROJECT_FLS
                Rte_FlashPendingFct = flashParam->wdTriggerFct;
#endif
			}
			FLASH_DISABLE_INTERRUPT;
			/* handle the erase of the input address and length */
		    /* if erase failed, should set flashParam->errorCode to kFlashFailed. */
			/* todo */

/* ----------------projectCfg---------------- */			
			if(TRUE != Rte_FlashErase(flashParam->address, flashParam->length))
            {
                flashParam->errorCode = kFlashFailed;
            }
/* ----------------projectCfg end---------------- */
			FLASH_ENABLE_INTERRUPT;
		}

	}

	return;
}
/******************************************************************************/
/*
 * Brief               <flash program function>
 * <process eeprom program for given address, data point and length in parameter
 *  flashParam> .
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <NONE>      
 * Param-Name[out]     <NONE>
 * Param-Name[in/out]  <flashParam >
 * Return              <NONE>  
 */
/******************************************************************************/
static void FlashIf_Write(tFlashParam* flashParam)
{
	tFlashAddress writeStartAddress = flashParam->address;
	tFlashAddress writeEndAddress   = flashParam->address + flashParam->length;

	tFlashResult	checkResult;

#if (FLASH_PARAM_CHECK == STD_ON)
	if(flashParam->flashstatus == FLASH_UNINIT)
	{
		flashParam->errorCode = Flash_E_UNINIT;
	}
	else if(flashParam->length == 0u)
	{
		flashParam->errorCode = Flash_E_PARAM_LENGTH;
	}
	else if(flashParam->data == NULL_PTR)
	{
		flashParam->errorCode = Flash_E_PARAM_POINTER;
	}
	else
#endif
	{
		/* Check the erase Address and length is in the range or not. */
		checkResult = Flash_CheckArea(writeStartAddress, writeEndAddress);

		if(checkResult == Flash_E_CHECK_ADDRESS_LENGTH)
		{
			flashParam->errorCode = Flash_E_CHECK_ADDRESS_LENGTH;
		}
		else
		{
			/*watchdog funcion*/
			if (flashParam->wdTriggerFct != NULL_PTR )
			{
				flashParam->wdTriggerFct();
#if defined PROJECT_FLS_ENABLE || defined PROJECT_FLS
                Rte_FlashPendingFct = flashParam->wdTriggerFct;
#endif
			}
			FLASH_DISABLE_INTERRUPT;
			/* handle the write of the input address and length */
		    /* if write failed, should set flashParam->errorCode to kFlashFailed. */
			/* todo */

/* ----------------projectCfg---------------- */			
			if(TRUE != Rte_FlashWrite(flashParam->address, flashParam->data, flashParam->length))
            {
                flashParam->errorCode = kFlashFailed;
            }
/* ----------------projectCfg end---------------- */
			FLASH_ENABLE_INTERRUPT;
		}
	}

    return;
}
/*************************************************************************/
/*
 * Brief:               Flash Program
 *
 * ServiceId:           0x03
 * Sync/Async:          Synchronous
 * Reentrancy:          Non Reentrant
 * Param-Name[in]:      None
 * Param-Name[out]:     None
 * Param-Name[in/out]:  flashParam
 * Return:              None
 * PreCondition:        Flash_Init
 * CallByAPI:           --
 */
/*************************************************************************/
static void FlashIf_Read(tFlashParam* flashParam)
{
    tFlashAddress writeStartAddress = flashParam->address;
    tFlashAddress writeEndAddress   = flashParam->address + flashParam->length-1;
    tFlashResult  checkResult;
	if(flashParam->flashstatus == FLASH_UNINIT)
    {
        flashParam->errorCode = Flash_E_UNINIT;
    }
    else if(flashParam->length == 0u)
    {
        flashParam->errorCode = Flash_E_PARAM_LENGTH;
    }
    else if(flashParam->readData == NULL_PTR)
    {
        flashParam->errorCode = Flash_E_PARAM_POINTER;
    }
    else
    {
        /* Check the erase Address and length is in the range or not. */
        checkResult = Flash_CheckArea(writeStartAddress, writeEndAddress);
        if(checkResult == kFlashFailed)
        {
            flashParam->errorCode = Flash_E_CHECK_ADDRESS_LENGTH;
        }
        else
        {
            /*watchdog function*/
            if (flashParam->wdTriggerFct != NULL_PTR )
            {
                flashParam->wdTriggerFct();
#if defined PROJECT_FLS_ENABLE || defined PROJECT_FLS
                Rte_FlashPendingFct = flashParam->wdTriggerFct;
#endif
            }
            /* handle the write of the input address and length */
            /* if write failed, should set flashParam->errorCode to kFlashFailed. */
/* ----------------projectCfg---------------- */
            if(TRUE != Rte_FlashRead(flashParam->address,flashParam->readData, flashParam->length))
            {
                flashParam->errorCode = kFlashFailed;
            }
/* ----------------projectCfg end---------------- */			
        }
    }
    return;
}

/******************************************************************************/
/*
 * Brief               <Flash check Area>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <startAddress : check start address.>    
 * 					   <endAddress   : check end address.> 
 * Param-Name[out]     <NONE>
 * Param-Name[in/out]  <NONE >
 * Return              <E_OK     : checkResult is ok.>  
 * 					   <E_NOT_OK : checkResult is not ok.>
 */
/******************************************************************************/
static tFlashResult Flash_CheckArea(tFlashAddress startAddress, tFlashAddress endAddress)
{
	tFlashResult retCheckResult = kFlashOk;
	/* check the address is in the range of operate address or not,
	 * if not return E_NOT_OK, else return E_OK */
	/* todo */

    return retCheckResult ;
}

#endif





