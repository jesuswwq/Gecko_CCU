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
**  FILENAME    : Appl_Callout.h                                              **
**                                                                            **
**  Created on  : 2024/04/11 14:04:03                                         **
**  Author      : long.zhu                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Implementation for Appl .                                   **
**                                                                            **
**  SPECIFICATION(S) : NONE                                                   **
**                                                                            **
*******************************************************************************/
/******************************************************************************
**                      Revision Control History                             **
******************************************************************************/
/*  <VERSION>    <DATE>      <AUTHOR>     <REVISION LOG>
 *   V1.0.0     20230818     long.zhu        Initial version
 */

#ifndef APPL_CALLOUT_H_
#define APPL_CALLOUT_H_

/*******************************************************************************
**                      Includes Section                                      **
*******************************************************************************/
#include "Appl.h"
/** DO NOT CHANGE THIS COMMENT!
 * <USERBLOCK include>
 */
/*Add the project.h file.*/

/** DO NOT CHANGE THIS COMMENT!
 * </USERBLOCK>
 */

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

#define APPL_ENABLE_INTERRUPT()                      
#define APPL_DISABLE_INTERRUPT()   
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
/**********************************************************************************************/
/**
 * @brief               <ECU Dependency Driver Initialization>
 * <This routine should be called by the boot code to initialize the ECU Dependency Driver> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/**********************************************************************************************/
extern void Appl_EcuDrvInit(void);

/**********************************************************************************************/
/**
 * @brief               <ECU Network Bus initialize>
 * <This routine should be called by the boot code to initialize the network bus protocol> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/**********************************************************************************************/
extern void Appl_EcuNetBusInit(void);

/**********************************************************************************************/
/**
 * @brief               <ECU Dependency Driver Deinitialization>
 * <This routine should be called by the boot code to deinitialize the ECU Dependency Driver> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/**********************************************************************************************/
extern void Appl_EcuDrvDeinit(void);

/******************************************************************************/
/**
 * @brief               <check application software Dependence>
 *
 * <This routine shall be called by the flashloader to check whether the
 *  individual parts (logical blocks) that make up the application software of
 *  an ECU are consistent with each other.> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_ResultType>
 */
/******************************************************************************/
extern FL_ResultType Appl_CheckDependence(void);

/******************************************************************************/
/**
 * @brief               <jump to application software>
 *
 * <jump to application software> .
 * @param[in]           <address:Jump address.>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Appl_AdaptiveJumpApp(uint32 address);

#if (APPL_SLEEP_TIMER > 0u)
/******************************************************************************/
/**
 * @brief               <ECU goto sleep mode>
 *
 * <This routine shall be called by the flash loader to shut down the ECU condition(put
 *  the ECU to sleep).> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <retVal:TRUE/FALSE>
 */
/******************************************************************************/
extern boolean Appl_EcuShutdownCondition(void);

/******************************************************************************/
/**
 * @brief               <ECU goto sleep mode>
 *
 * <This routine shall be called by the flash loader to shut down the ECU (put
 *  the ECU to sleep).> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Appl_EcuShutdown(void);
#endif

#if (APPL_ENABLE_WATCHDOG_MONITORING_IN_BOOT == STD_ON)
/******************************************************************************/
/**
 * @brief               <Timeout watchdog feed the dog.>
 *
 * <Timeout watchdog feed the dog.> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Appl_wdTriggerFct(void);
#endif
/******************************************************************************/
/**
 * @brief               <return bank arrary index.>
 *
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_Bank_Type>
 */
/******************************************************************************/
extern FL_Bank_Type Appl_GetRegion(FL_Region_Type bank);

#if (FL_ABSWAP_ENABLE == STD_ON)
/******************************************************************************/
/**
 * @brief               <AB swap>
 * <> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Appl_SwapSwitch(void);

/******************************************************************************/
/**
 * @brief               <get external swap request.>
 *
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <boolean>
 */
/******************************************************************************/
extern boolean Appl_GetExternalABSWapRequested(void);
/******************************************************************************/
/**
 * @brief               <Check whether the partition peripherals are successfully started.>
 *
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <boolean>
 */
/******************************************************************************/
extern boolean Appl_GetABSWapEnableStatus(void);
#endif
/******************************************************************************/
/**
 * @brief               <convert address, only used for triCore Platform>
 * <> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           address  - IN
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <uint32>
 */
/******************************************************************************/
extern uint32 Appl_ConvertAddress(uint32 address);
/******************************************************************************/
/**
 * @brief               <convert logic address>
 * <> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <address>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <uint32>
 */
/******************************************************************************/
extern uint32 Appl_ConvertLogicAddress(uint32 address);
/******************************************************************************/
/*
 * @brief              [Rte_Reset description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
extern void Rte_Reset(void);
/******************************************************************************/
/*
 * @brief              [Rte_isWarmStart description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
extern boolean Rte_isWarmStart(void);
/******************************************************************************/
/*
 * @brief              [Mcu_PflashTrapDisable description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
extern void Mcu_PflashTrapDisable(void);
/******************************************************************************/
/*
 * @brief              [Mcu_PflashTrapEnable description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
extern void Mcu_PflashTrapEnable(void);
#endif /* APPL_CALLOUT_H_ */

