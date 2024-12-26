/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Rte_SegmentCheck.h>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for Rte_SegmentCheck Module>
 *
 *  @author     <your Name>
 *  @date       <2024-01-04>
 *
 *
 *
 *  May be changed by User [yes/no]: no
 */
/*============================================================================*/
#ifndef RTE_SEGMENTCHECK_H
#define RTE_SEGMENTCHECK_H
#ifdef __cplusplus
extern "C" {
#endif /* cplusplus */
/*@{*/
//#define RTE_SEGMENTCHECK_C
/*@}*/
#ifndef RTE_SEGMENTCHECK_C
#define RTE_SEGMENTCHECK_EXPT extern
#else
#define RTE_SEGMENTCHECK_EXPT
#endif
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/** <VERSION>   <DATE>      <AUTHOR>     <REVISION LOG>*/
/*============================================================================*/
/*=======[ Includes ]=========================================================*/
#include "Std_Types.h"
#include "Fl_Type.h"
/*=======[ Exported define ]==================================================*/
/*=======[ Exported types ]===================================================*/
/*=======[ Exported variables ]===============================================*/
/*=======[ Exported functions ]===============================================*/

RTE_SEGMENTCHECK_EXPT void Rte_FL_Segement_CheckSum_Window(FL_SegmentListType*ptr_segementList,uint32 winAddr, uint32 winLen);
RTE_SEGMENTCHECK_EXPT uint8* Rte_FL_Segement_CheckSum_WindowValue(FL_SegmentListType*ptr_segementList);

#ifdef __cplusplus
}
#endif /* cplusplus */
#endif
/*=======[E N D   O F   F I L E]==============================================*/

