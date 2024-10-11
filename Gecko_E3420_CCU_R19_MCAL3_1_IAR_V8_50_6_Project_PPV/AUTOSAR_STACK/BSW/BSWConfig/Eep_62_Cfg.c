/*===========================================================================================================================*/
/*** Copyright (C) 2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *
 *  @file       <Eep_62_Cfg.c>
 *  @brief
 *
 *  <Compiler:    MCU: >
 *
 *  @author     <Haibin.Shao>
 *  @date       <2023/11/06 15:38:45 >
 */
/*===========================================================================================================================*/

/*=====================[R E V I S I O N   H I S T O R Y]=====================================================================*/
/* <VERSION>   <DATE>      <AUTHOR>       <REVISION LOG>
 *  V1.0.0     20190709    Haibin.Shao    First Version
 */
/*===========================================================================================================================*/

/******************************************************************************************************************************
**                      Include Section                                                                                      **
******************************************************************************************************************************/
#include "Eep_62_Cfg.h"

/******************************************************************************************************************************

**                      Global Variable Definitions                                                                          **
******************************************************************************************************************************/
#define EEP_62_START_SEC_CONST_UNSPECIFIED
#include "Eep_62_MemMap.h"

extern CONST(Eep_62_DeviceConfigType, EA_CONST) Eep_Eep_62_DeviceConfig[1];

/* PRQA S 1531++ */ /* MISRA Rule 8.7 */
CONST(Eep_62_DevApiType, EEP_CONST) Eep_62_DevHwApis_at[1] =
/* PRQA S 1531-- */ /* MISRA Rule 8.7 */
{

    {
        /* Device Init operation API */
        NULL_PTR,
        /* Device read operation API */
        Eep_CAV24C64_Read,
        /* Device write operation API */
        Eep_CAV24C64_Write,
        /* Device erase operation API */
        Eep_CAV24C64_Erase
    }

};
CONST(Eep_62_ConfigType,EEP_CONST) Eep_62_ConfigSet[1] =
{

    /* Device configuration item of the first EEP module */
    {
        /* defaultMode */
        MEMIF_MODE_SLOW,
        /* jobCallCycle */
        0u,
        /* jobEndNotification */
        NULL_PTR,
        /* jobErrorNotification */
        NULL_PTR,
        /* Number of device configuration */
        1,
        /* Parameter list of device configuration */
        &Eep_Eep_62_DeviceConfig[0]
    }

};

#define EEP_62_STOP_SEC_CONST_UNSPECIFIED
#include "Eep_62_MemMap.h"

