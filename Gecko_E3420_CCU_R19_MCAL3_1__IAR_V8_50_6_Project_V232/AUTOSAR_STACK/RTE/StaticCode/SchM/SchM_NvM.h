/*============================================================================*/
/*  Copyright (C) 2009-2015, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <SchM_NvM.h>
 *  @brief      <Reserves for extend.>
 *
 *  <Compiler: CodeWarrior MCU:MPC55XX>
 *
 *  @author     <SDu>
 *  @date       <2015-03-12>
 */
/*============================================================================*/

/*======================[R E V I S I O N   H I S T O R Y]=====================*/
/*  <VERSION>    <DATE>    <AUTHOR>    <REVISION LOG>
 *   V1.0.0     20150312     SDu       Initial version
 *
 *   V1.0.1     20150408     SDu       Add compiler abstrct
 *                                     Improve code effiency
 *                                     Fix bug
 */
/*============================================================================*/
#ifndef SCHM_NVM_H
#define SCHM_NVM_H

/*===================[V E R S I O N  I N F O R M A T I O N]===================*/

#define SCHM_NVM_H_AR_MAJOR_VERSION 2U
#define SCHM_NVM_H_AR_MINOR_VERSION 3U
#define SCHM_NVM_H_AR_PATCH_VERSION 0U
#define SCHM_NVM_H_SW_MAJOR_VERSION 1U
#define SCHM_NVM_H_SW_MINOR_VERSION 0U
#define SCHM_NVM_H_SW_PATCH_VERSION 1U

/*==========================[M A C R O  D E F I N E]==========================*/
#define INTERRUPT_PROTECTION_AREA 0U
#define EXCLUSIVE_AREA_1          1U
#define NVM_AREA                  2U

#define SchM_Enter_NvM(Instance, ExclusiveArea)
#define SchM_Exit_NvM(Instance, ExclusiveArea)

#endif /* End of SCHM_NVM_H*/
/*==========================[E N D   O F   F I L E]===========================*/
