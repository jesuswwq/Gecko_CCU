/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2023)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : Appl.h                                                      **
**                                                                            **
**  Created on  :                                                             **
**  Author      : long.zhu                                               	  **
**  Vendor      :                                                             **
**  DESCRIPTION : function declarations for Appl                              **
**                                                                            **
**  SPECIFICATION(S) :   None                   		                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *  V1.0.0      20121227    Gary            Initial version
 *  V1.0.1      20180511    CChen           update
 *  V1.0.2      20200412    Lianren.wu      code optimization
 *  V1.0.3     20240402    Long.Zhu        Code comment review
 */
#ifndef APPL_H
#define APPL_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Appl_Cfg.h"
#include "Appl_Dcm.h"
#include "FL_Cfg.h"
#include "SecM.h"
#include "Dcm.h"
#include "Dcm_Internel.h"
#include "PduR_Callout.h"
#include "DP.h"
#include "Appl_Callout.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/*Interrupt fun*/                  
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

/******************************************************************************/
/**
 * @brief               <ECU initialize>
 *
 * <This routine shall be called by the boot code contained in the flash loader
 *  to initialize common hardware.> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Appl_EcuStartup(void);

/******************************************************************************/
/**
 * @brief               <check application software consistency>
 *
 * <This routine shall be called by the flashloader to check whether the
 *  individual parts (logical blocks) that make up the application software of
 *  an ECU are consistent with each other.> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <region>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_OK/FL_FAILED:The integrity check succeeded or failed.>
 */
/******************************************************************************/
extern FL_ResultType Appl_CheckConsistency(FL_Region_Type region);

/******************************************************************************/
/**
 * @brief               <check application software Dependency and consistency>
 *
 * <This routine shall be called by the flashloader to check whether the
 *  individual parts (logical blocks) that make up the application software of
 *  an ECU are consistent with each other.> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <region>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_OK/FL_FAILED:The integrity check succeeded or failed.>
 */
/******************************************************************************/
extern FL_ResultType Appl_CheckDependencyConsistency(FL_Region_Type region);
/******************************************************************************/
/**
 * @brief               <ECU reset>
 *
 * <This routine shall be called by the BOOTLOADER to reset the ECU upon
 *  request from the external programming device.>
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Appl_EcuReset(void);

/******************************************************************************/
/**
 * @brief               <Appl Main Function>
 *
 * <Appl Main Function> .
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Appl_MainFunction(void);

#if (STD_ON == FL_SPLIT_SECTORS_ERASE_ENABLED)
/******************************************************************************/
/**
 * @brief               <Net update Main Function>
 *
 * <Appl Main Function> .
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Appl_NetUpdateMainFunction(void);
#endif

/******************************************************************************/
/**
 * @brief               <1ms task>
 *
 * <This routine shall be called by functions of the flash loader runtime
 *  environment and the security module at least every 500 milliseconds.> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Appl_UpdateTriggerCondition(void);


#endif/* end of APPL_H */
