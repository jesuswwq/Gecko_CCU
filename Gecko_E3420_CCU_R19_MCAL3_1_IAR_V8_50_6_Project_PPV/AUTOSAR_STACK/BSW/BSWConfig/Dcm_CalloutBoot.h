/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Dcm_CalloutBoot.h>
 *  @brief      <>
 *  
 *  <MCU:E3420>
 *  
 *  @author     <>
 *  @date       <2023-11-13 14:42:41>
 */
/*============================================================================*/

/* Dcm_CalloutBoot.h */

#ifndef DCM_CALLOUTBOOT_H
#define DCM_CALLOUTBOOT_H

/*******************************************************************************
 **                        Revision Control History                           **
******************************************************************************/

/*******************************************************************************
 **                        Version Information                                **
******************************************************************************/

/*******************************************************************************
 **                        Include Section                                    **
******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
 **                        Global Variable Definitions                        **
******************************************************************************/
#define FOTA_ENABLE 0
typedef struct
{
    /** Value indicate an external programming request. */
    uint32 FlBootMode;

    /** Value indicate an update of the application software. */
    uint32 FlApplUpdate;

    /** Value indicate default session request from prog. of the bootloader software. */
    uint32 FlBootDefault;

#if (FOTA_ENABLE == STD_ON)
    /*active the new app*/
    uint32 ActiveFlag;

    /*rollback to the old app*/
    uint32 RollbackFlag;

    uint32 JumpAddress;
#endif
}BL_AppFlagType;

/** Value indicate an update of the application software. */
#define ACTIVE_FLAG 0xD5u

/** Value indicate default session request from prog. of the bootloader software. */
#define ROLL_BACK_FLAG       0x01U

/** The physical memory location of boot request flag. LOCAL address*/
/* @type:uint32 range:0x00000000~0xFFFFFFFF note:NONE */
#define FL_BOOT_MODE            /*TODO Need to add address*/
/** The physical memory location of application software update flag. LOCAL address*/
/* @type:uint32 range:0x00000000~0xFFFFFFFF note:NONE */
#define FL_APPL_UPDATE      /*TODO Need to add address*/

#define BL_APP_FLAG_ADDRESS /*TODO Need to add address*/

#define BUS_MODE_ETH 0x12345678u

#define BUS_MODE_CAN 0x87654321u

extern BL_AppFlagType* BL_AppFlag;

#endif /* DCM_CALLOUTBOOT_H */

