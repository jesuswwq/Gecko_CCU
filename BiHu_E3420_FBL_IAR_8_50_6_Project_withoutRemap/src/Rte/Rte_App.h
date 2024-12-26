/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Rte_App.h>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for Rte_App Module>
 *
 *  @author     <your Name>
 *  @date       <2023-12-04>
 *
 *
 *
 *  May be changed by User [yes/no]: no
 */
/*============================================================================*/
#ifndef RTE_APP_H
#define RTE_APP_H
#ifdef __cplusplus
extern "C" {
#endif /* cplusplus */
/*@{*/
//#define RTE_APP_C
/*@}*/
#ifndef RTE_APP_C
#define RTE_APP_EXPT extern
#else
#define RTE_APP_EXPT
#endif
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/** <VERSION>   <DATE>      <AUTHOR>     <REVISION LOG>*/
/*============================================================================*/
/*=======[ Includes ]=========================================================*/
#include "Std_Types.h"
#include "FL_Type.h"
/*=======[ Exported define ]==================================================*/
/*=======[ Exported types ]===================================================*/
/*=======[ Exported variables ]===============================================*/
/*=======[ Exported functions ]===============================================*/

RTE_APP_EXPT boolean Rte_Appl_ReadProgrammingFlag(void);
RTE_APP_EXPT FL_ResultType Rte_Appl_CheckConsistency(void);
RTE_APP_EXPT void Rte_Appl_InitNvmInfo(void);
RTE_APP_EXPT void Rte_Appl_CheckFactoryMode (void);
RTE_APP_EXPT void Rte_Appl_Swtich_Session(uint8 lastSession);
RTE_APP_EXPT void Rte_Appl_P3ClientTimout(void);

#ifdef __cplusplus
}
#endif /* cplusplus */
#endif
/*=======[E N D   O F   F I L E]==============================================*/

