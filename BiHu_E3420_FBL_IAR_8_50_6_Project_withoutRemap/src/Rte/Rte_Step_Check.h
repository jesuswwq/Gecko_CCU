/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Rte_Step_Check.h>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for Rte_Step_Check Module>
 *
 *  @author     <your Name>
 *  @date       <2024-08-01>
 *
 *
 *
 *  May be changed by User [yes/no]: no
 */
/*============================================================================*/
#ifndef RTE_STEP_CHECK_H
#define RTE_STEP_CHECK_H
#ifdef __cplusplus
extern "C" {
#endif /* cplusplus */
/*@{*/
/*
 * #define RTE_STEP_CHECK_C
 */
/*@}*/
#ifndef RTE_STEP_CHECK_C
#define RTE_STEP_CHECK_EXPT extern
#else
#define RTE_STEP_CHECK_EXPT
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

RTE_STEP_CHECK_EXPT boolean Rte_Step_Check_Idle (void);
RTE_STEP_CHECK_EXPT boolean Rte_Step_Check_CheckSum (void);
RTE_STEP_CHECK_EXPT boolean Rte_Step_Check_CheckCompability (void);
RTE_STEP_CHECK_EXPT boolean Rte_Step_Check_Init (void);
RTE_STEP_CHECK_EXPT boolean Rte_Step_Set_erase (void);
RTE_STEP_CHECK_EXPT boolean Rte_Step_Set_CheckSUm (void);
RTE_STEP_CHECK_EXPT boolean Rte_Step_Set_CheckCompabilit (void);


#ifdef __cplusplus
}
#endif /* cplusplus */
#endif
/*=======[E N D   O F   F I L E]==============================================*/

