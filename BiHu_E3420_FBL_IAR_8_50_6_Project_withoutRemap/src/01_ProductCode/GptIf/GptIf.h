/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <GptIf.h>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for GptIf Module>
 *
 *  @author     <your Name>
 *  @date       <2023-06-20>
 *
 *
 *
 *  May be changed by User [yes/no]: no
 */
/*============================================================================*/
#ifndef GPTIF_H
#define GPTIF_H
#ifdef __cplusplus
extern "C" {
#endif /* cplusplus */
#ifndef GPTIF_C
#define GPTIF_EXPT extern
#else
#define GPTIF_EXPT
#endif
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/** <VERSION>   <DATE>      <AUTHOR>     <REVISION LOG>*/
/*============================================================================*/
/*=======[ Includes ]=========================================================*/
#include "Std_Types.h"
#include "GptIf_Cfg.h"
/*=======[ Exported define ]==================================================*/
/*=======[ Exported types ]===================================================*/
/*=======[ Exported variables ]===============================================*/
/*=======[ Exported functions ]===============================================*/

GPTIF_EXPT void GptNotification_1ms(void);
GPTIF_EXPT void GptIf_Init(void);
GPTIF_EXPT void GptIf_Deinit(void);
GPTIF_EXPT boolean GptIf_GetFlag(void);
GPTIF_EXPT uint32 GptIf_GetTick(void);
GPTIF_EXPT void GptIf_Random_Updata(void);
GPTIF_EXPT uint32 GptIf_Random_Get(void);
GPTIF_EXPT uint32 GptIf_TickDeltaGet(uint8 index);

#ifdef __cplusplus
}
#endif /* cplusplus */
#endif
/*=======[E N D   O F   F I L E]==============================================*/

