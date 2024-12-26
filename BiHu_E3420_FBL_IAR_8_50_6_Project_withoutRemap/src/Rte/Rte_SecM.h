/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Rte_SecM.h>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for Rte_SecM Module>
 *
 *  @author     <your Name>
 *  @date       <2024-01-04>
 *
 *
 *
 *  May be changed by User [yes/no]: no
 */
/*============================================================================*/
#ifndef RTE_SECM_H
#define RTE_SECM_H
#ifdef __cplusplus
extern "C" {
#endif /* cplusplus */
/*@{*/
//#define RTE_SECM_C
/*@}*/
#ifndef RTE_SECM_C
#define RTE_SECM_EXPT extern
#else
#define RTE_SECM_EXPT
#endif
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/** <VERSION>   <DATE>      <AUTHOR>     <REVISION LOG>*/
/*============================================================================*/
/*=======[ Includes ]=========================================================*/
#include "Std_Types.h"
#include "Dcm.h"
/*=======[ Exported define ]==================================================*/
/*=======[ Exported types ]===================================================*/
/*=======[ Exported variables ]===============================================*/
/*=======[ Exported functions ]===============================================*/

RTE_SECM_EXPT void Rte_SecM_DecreaseSecurityCounter(uint8 chann);
RTE_SECM_EXPT boolean Rte_SecM_IncreaseSecurityCounter_Only(uint8 chann);
RTE_SECM_EXPT Dcm_NrcType Rte_SecM_IncreaseSecurityCounter(uint8 chann);
RTE_SECM_EXPT void Rte_SecM_ClearSecurityCounter(uint8 chann);
RTE_SECM_EXPT void Rte_SecM_InitSecurityCounter(void);

#ifdef __cplusplus
}
#endif /* cplusplus */
#endif
/*=======[E N D   O F   F I L E]==============================================*/

