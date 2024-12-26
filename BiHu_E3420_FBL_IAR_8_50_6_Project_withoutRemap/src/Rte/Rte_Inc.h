/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Rte_Inc.h>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for Rte_Inc Module>
 *
 *  @author     <your Name>
 *  @date       <2024-01-03>
 *
 *
 *
 *  May be changed by User [yes/no]: no
 */
/*============================================================================*/
#ifndef RTE_INC_H
#define RTE_INC_H
#ifdef __cplusplus
extern "C" {
#endif /* cplusplus */
/*@{*/
/* 
 * #define RTE_INC_C 
 */
/*@}*/
#ifndef RTE_INC_C
#define RTE_INC_EXPT extern
#else
#define RTE_INC_EXPT
#endif
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/** <VERSION>   <DATE>      <AUTHOR>     <REVISION LOG>*/
/*============================================================================*/
/*=======[ Includes ]=========================================================*/
#include "Rte_Fl_Cfg.h"
#include "Rte_Job.h"
#include "Rte_Address.h"
#include "Rte_BlockM.h"
#include "Rte_ResetJump.h"
#include "Rte_App.h"
#include "Rte_Did.h"
#include "Rte_SecM.h"
#include "Rte_Alg_Bihu.h"
#include "Rte_Algorithms.h"
#include "Rte_ProgCounter.h"
#include "Rte_SegmentCheck.h"
#include "Rte_ABSwap.h"
#include "Rte_FL.h"
#include "Rte_Step_Check.h"
#include "NvMem.h"
/*=======[ Exported define ]==================================================*/
/*=======[ Exported types ]===================================================*/
/*=======[ Exported variables ]===============================================*/
/*=======[ Exported functions ]===============================================*/
#ifdef __cplusplus
}
#endif /* cplusplus */
#endif
/*=======[E N D   O F   F I L E]==============================================*/

