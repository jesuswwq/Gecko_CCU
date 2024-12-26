/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Rte_Alg_Bihu.h>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for Rte_Alg_Bihu Module>
 *
 *  @author     <your Name>
 *  @date       <2024-01-11>
 *
 *
 *
 *  May be changed by User [yes/no]: no
 */
/*============================================================================*/
#ifndef RTE_ALG_BIHU_H
#define RTE_ALG_BIHU_H
#ifdef __cplusplus
extern "C" {
#endif /* cplusplus */
/*@{*/
//#define RTE_ALG_BIHU_C
/*@}*/
#ifndef RTE_ALG_BIHU_C
#define RTE_ALG_BIHU_EXPT extern
#else
#define RTE_ALG_BIHU_EXPT
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

RTE_ALG_BIHU_EXPT SecM_StatusType SecM_ComputeKey_BiHu(const uint8 *seed, uint8 seed_length,
                                const uint8 *security_constant, uint8 security_constant_length,
                                uint8 *key, uint8 key_length);

#ifdef __cplusplus
}
#endif /* cplusplus */
#endif
/*=======[E N D   O F   F I L E]==============================================*/

