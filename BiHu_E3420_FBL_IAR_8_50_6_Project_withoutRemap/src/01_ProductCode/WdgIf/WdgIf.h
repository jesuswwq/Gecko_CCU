/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <WdgIf.h>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for WdgIf Module>
 *
 *  @author     <your Name>
 *  @date       <2024-04-03>
 *
 *
 *
 *  May be changed by User [yes/no]: no
 */
/*============================================================================*/
#ifndef WDGIF_H
#define WDGIF_H
#ifdef __cplusplus
extern "C" {
#endif /* cplusplus */
/*@{*/
//#define WDGIF_C
/*@}*/
#ifndef WDGIF_C
#define WDGIF_EXPT extern
#else
#define WDGIF_EXPT
#endif
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/** <VERSION>   <DATE>      <AUTHOR>     <REVISION LOG>*/
/*============================================================================*/
/*=======[ Includes ]=========================================================*/
#include "Std_Types.h"
/*=======[ Exported define ]==================================================*/
/*=======[ Exported types ]===================================================*/
/*=======[ Exported variables ]===============================================*/
/*=======[ Exported functions ]===============================================*/

WDGIF_EXPT void WdgIf_Init(void);
WDGIF_EXPT void WdgIf_Deinit(void);
WDGIF_EXPT void WdgIf_SetTriggerCondition(void);
WDGIF_EXPT void WdgIf_SetTriggerAttempt(void);
WDGIF_EXPT void WdgIf_SetTriggerForward(uint32 delt);
WDGIF_EXPT void WdgIf_MainFunction(void);

#ifdef __cplusplus
}
#endif /* cplusplus */
#endif
/*=======[E N D   O F   F I L E]==============================================*/

