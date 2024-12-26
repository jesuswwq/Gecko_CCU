/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Rte_Address.h>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for Rte_Address Module>
 *
 *  @author     <your Name>
 *  @date       <2023-12-04>
 *
 *
 *
 *  May be changed by User [yes/no]: no
 */
/*============================================================================*/
#ifndef RTE_ADDRESS_H
#define RTE_ADDRESS_H
#ifdef __cplusplus
extern "C" {
#endif /* cplusplus */
/*@{*/
//#define RTE_ADDRESS_C
/*@}*/
#ifndef RTE_ADDRESS_C
#define RTE_ADDRESS_EXPT extern
#else
#define RTE_ADDRESS_EXPT
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

RTE_ADDRESS_EXPT uint32 Rte_Appl_ConvertAddress(uint32 address);
RTE_ADDRESS_EXPT uint32 Rte_Appl_ConvertSize(uint32 sz);
RTE_ADDRESS_EXPT boolean Rte_Appl_CheckAddrAndLen(uint32 addr, uint32 len, uint32 tarAddr, uint32 tarLen);

#ifdef __cplusplus
}
#endif /* cplusplus */
#endif
/*=======[E N D   O F   F I L E]==============================================*/

