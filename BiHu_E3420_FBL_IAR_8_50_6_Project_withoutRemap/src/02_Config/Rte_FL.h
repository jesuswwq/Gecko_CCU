/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Rte_FL.h>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for Rte_Data Module>
 *
 *  @author     <your Name>
 *  @date       <2023-12-04>
 *
 *
 *
 *  May be changed by User [yes/no]: no
 */
/*============================================================================*/
#ifndef RTE_FL_H
#define RTE_FL_H
#ifdef __cplusplus
extern "C" {
#endif /* cplusplus */
/*@{*/
/*
 *#define RTE_FL_C
 */
/*@}*/
#ifndef RTE_FL_C
#define RTE_FL_EXPT extern
#else
#define RTE_FL_EXPT
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

RTE_FL_EXPT boolean Rte_Data_Write_NvmInfo(uint8 *info);
RTE_FL_EXPT boolean Rte_Data_Read_NvmInfo(uint8 *info);
RTE_FL_EXPT boolean Rte_Data_Write_Fingerprint(const uint8 *appPrint);
RTE_FL_EXPT boolean Rte_Data_Read_Fingerprint(uint8 *Counter);
RTE_FL_EXPT boolean Rte_Data_Write_Factory(uint8 Counter);
RTE_FL_EXPT boolean Rte_Data_Read_Factory(uint8 *Counter);
RTE_FL_EXPT boolean Rte_Data_Write_ProgramAttemptCounter(uint16 Counter);
RTE_FL_EXPT boolean Rte_Data_Read_ProgramAttemptCounter(uint16 *Counter);
RTE_FL_EXPT boolean Rte_Data_Write_ProgramSuccessCounter(uint16 Counter);
RTE_FL_EXPT boolean Rte_Data_Read_ProgramSuccessCounter(uint16 *Counter);
RTE_FL_EXPT boolean Rte_Data_Write_SecurityAccess(uint8 idx,uint8 Counter);
RTE_FL_EXPT boolean Rte_Data_Read_SecurityAccess(uint8 idx,uint8 *Counter);
RTE_FL_EXPT boolean Rte_Data_Write_ClientErrStatus(uint8 *Counter);
RTE_FL_EXPT boolean Rte_Data_Read_ClientErrStatus(uint8 *Counter);
RTE_FL_EXPT boolean Rte_Data_Write_PROGRAM_Flag(uint8* Counter);
RTE_FL_EXPT boolean Rte_Data_Read_PROGRAM_Flag(uint8 *Counter);
RTE_FL_EXPT boolean Rte_Data_Write_RESET_JUMP_Flag(uint8* Counter);
RTE_FL_EXPT boolean Rte_Data_Read_RESET_JUMP_Flag(uint8 *Counter);
RTE_FL_EXPT boolean Rte_Data_Write_RESET_CAUSE(uint8* Counter);
RTE_FL_EXPT boolean Rte_Data_Write_JUMP_VECTOR_INFO (uint32 addr);
RTE_FL_EXPT boolean Rte_Data_Write_A_Part_Count(uint32 Counter);
RTE_FL_EXPT boolean Rte_Data_Read_A_Part_Count(uint32 *Counter);
RTE_FL_EXPT boolean Rte_Data_Write_B_Part_Count(uint32 Counter);
RTE_FL_EXPT boolean Rte_Data_Read_B_Part_Count(uint32 *Counter);
RTE_FL_EXPT boolean Rte_Data_Write_ForceSwap(uint8 Counter);
RTE_FL_EXPT boolean Rte_Data_Read_ForceSwap(uint8 *Counter);
RTE_FL_EXPT boolean Rte_Data_Write_FingerprintB(uint8 *appPrint);
RTE_FL_EXPT boolean Rte_Data_Read_FingerprintB(uint8 *Counter);
RTE_FL_EXPT void Rte_Data_Write_Fingerprint_to_App(void);

#ifdef __cplusplus
}
#endif /* cplusplus */
#endif
/*=======[E N D   O F   F I L E]==============================================*/

