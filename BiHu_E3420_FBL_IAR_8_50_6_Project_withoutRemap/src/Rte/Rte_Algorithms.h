/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Rte_Algorithms.h>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for Rte_Algorithms Module>
 *
 *  @author     <your Name>
 *  @date       <2024-01-04>
 *
 *
 *
 *  May be changed by User [yes/no]: no
 */
/*============================================================================*/
#ifndef RTE_ALGORITHMS_H
#define RTE_ALGORITHMS_H
#ifdef __cplusplus
extern "C" {
#endif /* cplusplus */
/*@{*/
/* 
 * #define RTE_ALGORITHMS_C 
 */
/*@}*/
#ifndef RTE_ALGORITHMS_C
#define RTE_ALGORITHMS_EXPT extern
#else
#define RTE_ALGORITHMS_EXPT
#endif
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/** <VERSION>   <DATE>      <AUTHOR>     <REVISION LOG>*/
/*============================================================================*/
/*=======[ Includes ]=========================================================*/
#include "Std_Types.h"
#include "SecM.h"
/*=======[ Exported define ]==================================================*/
/*=======[ Exported types ]===================================================*/
/*=======[ Exported variables ]===============================================*/
/*=======[ Exported functions ]===============================================*/

RTE_ALGORITHMS_EXPT void Rte_SecM_GenerateSeed(uint8 *seed,const uint16 slen);
RTE_ALGORITHMS_EXPT SecM_StatusType Rte_SecM_VerificationCrc(SecM_VerifyParamType* verifyParam, const uint8* crc);
RTE_ALGORITHMS_EXPT boolean Rte_SecM_VerifyFlashdriver(const SecM_VerifyParamType* verifyParam);

#ifdef __cplusplus
}
#endif /* cplusplus */
#endif
/*=======[E N D   O F   F I L E]==============================================*/

