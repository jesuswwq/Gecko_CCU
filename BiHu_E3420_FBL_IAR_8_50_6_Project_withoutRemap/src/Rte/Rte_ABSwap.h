/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Rte_ABSwap.h>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for Rte_ABSwap Module>
 *
 *  @author     <your Name>
 *  @date       <2024-01-23>
 *
 *
 *
 *  May be changed by User [yes/no]: no
 */
/*============================================================================*/
#ifndef RTE_ABSWAP_H
#define RTE_ABSWAP_H
#ifdef __cplusplus
extern "C" {
#endif /* cplusplus */
/*@{*/
//#define RTE_ABSWAP_C
/*@}*/
#ifndef RTE_ABSWAP_C
#define RTE_ABSWAP_EXPT extern
#else
#define RTE_ABSWAP_EXPT
#endif
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/** <VERSION>   <DATE>      <AUTHOR>     <REVISION LOG>*/
/*============================================================================*/
/*=======[ Includes ]=========================================================*/
#include "Std_Types.h"
/*=======[ Exported define ]==================================================*/
#define RTE_BANK1 0
#define RTE_BANK2 1
/*=======[ Exported types ]===================================================*/
typedef uint8 Rte_Bank_Type;
/*=======[ Exported variables ]===============================================*/



/*=======[ Exported functions ]===============================================*/

RTE_ABSWAP_EXPT void Rte_ABSwap_Init(void);
RTE_ABSWAP_EXPT boolean Rte_ABSwap_SetLastBank(void);
RTE_ABSWAP_EXPT boolean Rte_ABSwap_ForceSwitch(void);
RTE_ABSWAP_EXPT boolean Rte_ABSwap_Switch(void);
RTE_ABSWAP_EXPT boolean Rte_ABSwap_SwitchBankFlag(void);
RTE_ABSWAP_EXPT boolean Rte_ABSwap_isA(void);
RTE_ABSWAP_EXPT boolean Rte_ABSwap_SetA(void);
RTE_ABSWAP_EXPT boolean Rte_ABSwap_SetB(void);

#ifdef __cplusplus
}
#endif /* cplusplus */
#endif
/*=======[E N D   O F   F I L E]==============================================*/

