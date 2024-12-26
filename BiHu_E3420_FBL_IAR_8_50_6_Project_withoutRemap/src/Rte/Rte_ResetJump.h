/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Rte_ResetJump.h>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for Rte_ResetJump Module>
 *
 *  @author     <your Name>
 *  @date       <2023-12-04>
 *
 *
 *
 *  May be changed by User [yes/no]: no
 */
/*============================================================================*/
#ifndef RTE_RESETJUMP_H
#define RTE_RESETJUMP_H
#ifdef __cplusplus
extern "C" {
#endif /* cplusplus */
/*@{*/
//#define RTE_RESETJUMP_C
/*@}*/
#ifndef RTE_RESETJUMP_C
#define RTE_RESETJUMP_EXPT extern
#else
#define RTE_RESETJUMP_EXPT
#endif
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/** <VERSION>   <DATE>      <AUTHOR>     <REVISION LOG>*/
/*============================================================================*/
/*=======[ Includes ]=========================================================*/
#include "Std_Types.h"
#include "Rte_Fl_Cfg.h"
/*=======[ Exported define ]==================================================*/
#define RTE_JUMP_APP_RESET_ENABLE RTE_CFG_JUMP_APP_RESET_ENABLE
/*=======[ Exported types ]===================================================*/
/*=======[ Exported variables ]===============================================*/
/*=======[ Exported functions ]===============================================*/

RTE_RESETJUMP_EXPT void Rte_Jump(void);
#if (RTE_JUMP_APP_RESET_ENABLE == STD_ON)
RTE_RESETJUMP_EXPT void Rte_ResetJump_Check(void);
#endif

#ifdef __cplusplus
}
#endif /* cplusplus */
#endif
/*=======[E N D   O F   F I L E]==============================================*/

