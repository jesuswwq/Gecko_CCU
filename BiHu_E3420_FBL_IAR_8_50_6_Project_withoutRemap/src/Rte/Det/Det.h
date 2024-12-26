/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Det_Api.h>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for Det_Api Module>
 *
 *  @author     <your Name>
 *  @date       <2023-04-12>
 *
 *
 *
 *  May be changed by User [yes/no]: no
 */
/*============================================================================*/
#ifndef DET_API_H
#define DET_API_H
#ifndef DET_API_C
#define DET_API_EXPT extern
#else
#define DET_API_EXPT
#endif
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/** <VERSION>   <DATE>      <AUTHOR>     <REVISION LOG>*/
/*============================================================================*/
/*=======[ Includes ]=========================================================*/
#include "Std_Types.h"
/*=======[ Exported define ]==================================================*/
#define DISABLE_MCAL_ASR_VER_CHECK
#define DISABLE_MCAL_SW_VER_CHECK
/*=======[ Exported types ]===================================================*/
/*=======[ Exported variables ]===============================================*/
/*=======[ Exported functions ]===============================================*/

DET_API_EXPT void Det_ReportError(uint8 i1, uint8 i2, uint8 i3, uint8 i4);
DET_API_EXPT void Det_ReportRuntimeError(uint32 i1, uint32 i2, uint32 i3, uint32 i4);
DET_API_EXPT void Det_ReportTransientFault(uint8 i1, uint8 i2, uint8 i3, uint8 i4);


#endif
/*=======[E N D   O F   F I L E]==============================================*/

