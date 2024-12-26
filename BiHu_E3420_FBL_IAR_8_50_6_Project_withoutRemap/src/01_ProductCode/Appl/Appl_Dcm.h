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
**  FILENAME    : FLashIf.h                                                   **
**                                                                            **
**  Created on  :                                                             **
**  Author      : long.zhu                                               	  **
**  Vendor      :                                                             **
**  DESCRIPTION : This Diagnostic Communication Manager file contained UDS    **
**                services which used for bootloader project.                 **
**                                                                            **
**  SPECIFICATION(S) :  ISO 14229-1-2020 Road vehicles -Unified diagnostic    **
**                     services (UDS) -Part 1 Application layer.pdf           **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *  V1.0.0     20200409   Lianren.Wu        Initial version
 *  V1.0.1     20231208   Long.Zhu          1.Delete BootSWReferenceNumber
 *  , ProgramSuccessCounter, ProgramAttemptCounter, RepairShopCode definitions and functions.
 *  V1.0.2     20240402    Long.Zhu        Code comment review
 */
#ifndef DCM_APPL_H_
#define DCM_APPL_H_

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "FL.h"
#include "Dcm.h"
#include "Appl.h"
#include "SecM.h"
#include "Dcm_Internel.h"
#include "Rte_Dcm.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/
extern uint32 Dcm_SecMSeedCount;


/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
/*==============================31 Service ===================================*/
/******************************************************************************/
/**
 * @brief               <handle service 0x31 checksum>
 *
 * <handle service 0x31 checksum> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <rxBuff: Received diagnostic data cache buff.>
 * @param[out]          <txBuff: Send diagnostic data cache buff.>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Dcm_CheckMemory(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);
/******************************************************************************/
/**
 * @brief               <handle service 0x31 erase block>
 *
 * <handle service 0x31 erase block> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <rxBuff: Received diagnostic data cache buff.>
 * @param[out]          <txBuff: Send diagnostic data cache buff.>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Dcm_EraseMemory(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);
/******************************************************************************/
/**
 * @brief               <handle service 0x31 check dependency>
 *
 * <handle service 0x31 check dependency> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <rxBuff: Received diagnostic data cache buff.>
 * @param[out]          <txBuff: Send diagnostic data cache buff.>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Dcm_CheckProgDependencies(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);
/******************************************************************************/
/**
 * @brief               <handle service 0x31 check program pre-condition>
 *
 * <handle service 0x31 check program pre-condition> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <rxBuff: Received diagnostic data cache buff.>
 * @param[out]          <txBuff: Send diagnostic data cache buff.>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Dcm_CheckProgPreCondition(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);

/******************************************************************************/
/**
 * @brief               <Perform partition Switching >
 *
 * <Perform partition Switching > .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <rxBuff>
 * @param[out]          <txBuff>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Dcm_SwapSwitch(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);
/******************************************************************************/
/**
 * @brief               <Perform partition Rollback >
 *
 * <Perform partition Rollback > .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <rxBuff>
 * @param[out]          <txBuff>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Dcm_SwapRollBack(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);

/*==============================27 Service ===================================*/
/******************************************************************************/
/**
 * @brief               <generate seed for UDS>
 *
 * <Needed by the UDS module,generate seed> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <seed:Seed data pointer.>
 * @param[in/out]       <NONE>
 * @return              <SecM_StatusType>
 */
/******************************************************************************/
extern SecM_StatusType Dcm_SecMGenerateSeed(SecM_SeedType* seed);
/******************************************************************************/
/**
 * @brief               <compare key>
 *
 * <Needed by the UDS module,compare seed> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <KeyLength: Key length.
 * 						 key:Key data pointer.
 * 						 seed:seed data pointer. >
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <SECM_OK/SECM_NOT_OK:Compare key success or failure>
 */
/******************************************************************************/
extern SecM_StatusType Dcm_SecMCompareKey(uint8 KeyLength, const SecM_KeyType* key, const SecM_SeedType* seed);

#if (STD_ON == FL_FINGER_PRINT_WRITE_ENABLE)
/******************************************************************************/
/*
 * Brief               <Set finger print written status.>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <NONE>
 * Param-Name[out]     <NONE>
 * Param-Name[in/out]  <NONE >
 * Return              <NONE>
 */
/******************************************************************************/
extern void Dcm_SetFingerPrintWrittenStatus(void);
/******************************************************************************/
/*
 * Brief               <Clear finger print written status.>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <NONE>
 * Param-Name[out]     <NONE>
 * Param-Name[in/out]  <NONE >
 * Return              <NONE>
 */
/******************************************************************************/
extern void Dcm_ClearFingerPrintWrittenStatus(void);
/******************************************************************************/
/*
 * Brief               <Get finger print written status.>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <NONE>
 * Param-Name[out]     <NONE>
 * Param-Name[in/out]  <NONE >
 * Return              <boolean.>
 */
/******************************************************************************/
extern boolean Dcm_GetFingerPrintWrittenStatus(void);
#endif
#endif
