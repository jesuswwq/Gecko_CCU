/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <NvMem.h>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for NvMem Module>
 *
 *  @author     <your Name>
 *  @date       <2024-04-08>
 *
 *
 *
 *  May be changed by User [yes/no]: no
 */
/*============================================================================*/
#ifndef NVMEM_H
#define NVMEM_H
#ifdef __cplusplus
extern "C" {
#endif /* cplusplus */
/*@{*/
/*
 * #define NVMEM_C
 */
/*@}*/
#ifndef NVMEM_C
#define NVMEM_EXPT extern
#else
#define NVMEM_EXPT
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

#if defined PROJECT_FLS_ENABLE || defined PROJECT_FLS
NVMEM_EXPT void (*Rte_FlashPendingFct)(void);
#endif
NVMEM_EXPT boolean NvMemInit(void);
NVMEM_EXPT boolean NvMemDeInit(void);
NVMEM_EXPT boolean NvMemRead(uint32 addr, uint8 *info, uint32 len);
NVMEM_EXPT boolean NvMemWrite(uint32 addr,const uint8 *info, uint32 len);
#if defined PROJECT_FLS_ENABLE || defined PROJECT_FLS
NVMEM_EXPT boolean Rte_FlashInit(void);
NVMEM_EXPT boolean Rte_FlashDeInit(void);
NVMEM_EXPT boolean Rte_FlashErase(uint32 addr, uint32 len);
NVMEM_EXPT boolean Rte_FlashRead(uint32 addr, uint8 *info, uint32 len);
NVMEM_EXPT boolean Rte_FlashWrite(uint32 addr,const uint8 *info, uint32 len);
NVMEM_EXPT void Rte_FlsTest(void);
#endif
NVMEM_EXPT void NvMemTest(void);




#ifdef __cplusplus
}
#endif /* cplusplus */
#endif
/*=======[E N D   O F   F I L E]==============================================*/

