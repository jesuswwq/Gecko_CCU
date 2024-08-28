/*===========================================================================================================================*/
/*** Copyright (C) 2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *
 *  @file       <Eep__Eep_62_Cfg.c>
 *  @brief
 *
 *  <Compiler:    MCU: >
 *
 *  @author     <Haibin.Shao>
 *  @date       <2023/11/06 15:38:45 >
 */
/*===========================================================================================================================*/

/*======================[R E V I S I O N   H I S T O R Y]====================================================================*/
/* <VERSION>   <DATE>      <AUTHOR>  <REVISION LOG>
 *  V1.0.0     20190709    Haibin.Shao     First Version
 */
/*===========================================================================================================================*/

/*=======================[I N C L U D E S]===================================================================================*/
#include "Eep_Eep_62_Cfg.h"

/******************************************************************************************************************************
**                      Global Variable Definitions                                                                          **
******************************************************************************************************************************/

#define EEP_62_START_SEC_CONST_UNSPECIFIED
#include "Eep_62_MemMap.h"

/* PRQA S 1531,3408++ */ /* MISRA Rule 8.7,Rule 8.4 */
CONST(Eep_62_DeviceConfigType, EA_CONST) Eep_Eep_62_DeviceConfig[1] =
/* PRQA S 1531,3408-- */ /* MISRA Rule 8.7,Rule 8.4 */
{
    {
      /* DeviceId */
       0,
      /* baseAddress */
        0u,
      /* the used size of EEPROM device */
        0u,
      /* fastReadBlockSize */
        32u,
      /* fastWriteBlockSize */
        32u,
      /* normalReadBlockSize */
        32u,
      /* normalWriteBlockSize */
        32u
    }
};

#define EEP_62_STOP_SEC_CONST_UNSPECIFIED
#include "Eep_62_MemMap.h"

