/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Rte_ProgCounter.h>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for Rte_ProgCounter Module>
 *
 *  @author     <your Name>
 *  @date       <2024-01-04>
 *
 *
 *
 *  May be changed by User [yes/no]: no
 */
/*============================================================================*/
#ifndef RTE_PROGCOUNTER_H
#define RTE_PROGCOUNTER_H
#ifdef __cplusplus
extern "C" {
#endif /* cplusplus */
/*@{*/
//#define RTE_PROGCOUNTER_C
/*@}*/
#ifndef RTE_PROGCOUNTER_C
#define RTE_PROGCOUNTER_EXPT extern
#else
#define RTE_PROGCOUNTER_EXPT
#endif
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/** <VERSION>   <DATE>      <AUTHOR>     <REVISION LOG>*/
/*============================================================================*/
/*=======[ Includes ]=========================================================*/
#include "Std_Types.h"
#include "FL_Type.h"
#include "Rte_Fl_Cfg.h"
/*=======[ Exported define ]==================================================*/
#define RTE_PROG_COUNTER_ONECE RTE_CFG_PROG_COUNTER_ONECE
/*=======[ Exported types ]===================================================*/
/*=======[ Exported variables ]===============================================*/
/*=======[ Exported functions ]===============================================*/

RTE_PROGCOUNTER_EXPT void Rte_ProgCounter_Init();
RTE_PROGCOUNTER_EXPT FL_ResultType Rte_ProgSuccessAdd(void);
RTE_PROGCOUNTER_EXPT FL_ResultType Rte_ProgAttemptAdd(void);
#if (RTE_PROG_COUNTER_ONECE == STD_ON )       
RTE_PROGCOUNTER_EXPT void Rte_ProgAttemptOneceClear(void);
RTE_PROGCOUNTER_EXPT void Rte_ProgSuccessOneceClear(void);
#endif


#ifdef __cplusplus
}
#endif /* cplusplus */
#endif
/*=======[E N D   O F   F I L E]==============================================*/

