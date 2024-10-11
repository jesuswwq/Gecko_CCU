/*===========================================================================================================================*/
/*** Copyright (C) 2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *
 *  @file       <Eep__Eep_62_Cfg.h>
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
#ifndef EEP_Eep_62_CFG_H_
#define EEP_Eep_62_CFG_H_

/*=======================[I N C L U D E S]===================================================================================*/
#include "Eep_62_Cfg.h"

/* Switches to activate or deactivate write cycle reduction 
(EEPROM value is read and compared before being overwritten). */
#define EEP_Eep_62_WRITE_CYCLE_REDUCTION     STD_OFF

/* Specifies the device numbers of this module instance. */
#define EEP_Eep_62_DIVICE_NUMBERS                     1

#endif /* EEP_Eep_62_CFG_H_ */

