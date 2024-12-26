/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Rte_Did.h>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for Rte_Did Module>
 *
 *  @author     <your Name>
 *  @date       <2024-01-04>
 *
 *
 *
 *  May be changed by User [yes/no]: no
 */
/*============================================================================*/
#ifndef RTE_DID_H
#define RTE_DID_H
#ifdef __cplusplus
extern "C" {
#endif /* cplusplus */
/*@{*/
/* 
 * #define RTE_DID_C 
 */
/*@}*/
#ifndef RTE_DID_C
#define RTE_DID_EXPT extern
#else
#define RTE_DID_EXPT
#endif
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/** <VERSION>   <DATE>      <AUTHOR>     <REVISION LOG>*/
/*============================================================================*/
/*=======[ Includes ]=========================================================*/
#include "Std_Types.h"
/*=======[ Exported define ]==================================================*/

#define RTE_DID_STORAGE_IN_EEP   1u
#define RTE_DID_STORAGE_IN_FLS   2u
#define RTE_DID_STORAGE_IN_CONST 3u
#define RTE_DID_STORAGE_IN_RAM   4u
#define RTE_DID_STORAGE_IN_API   5u
/*=======[ Exported types ]===================================================*/
typedef uint8 storageTypedef;


typedef struct
{
    storageTypedef storageType;
    uint32 len;
    uint32 did;
    uint32 addr;
} did_Group_Type;
/*=======[ Exported variables ]===============================================*/
/*=======[ Exported functions ]===============================================*/

RTE_DID_EXPT boolean Rte_FL_WriteDidGroup(const did_Group_Type *did,const uint8 *writeData, uint16 writeLength);
RTE_DID_EXPT boolean Rte_FL_ReadDidGroup(const did_Group_Type *did, uint8 *readData, uint16 *readLength);
RTE_DID_EXPT boolean Rte_FL_ReadDidGroupCombination(did_Group_Type **didArr, uint8 didNum, uint8 *readData, uint16 *readLength);

#ifdef __cplusplus
}
#endif /* cplusplus */
#endif
/*=======[E N D   O F   F I L E]==============================================*/

