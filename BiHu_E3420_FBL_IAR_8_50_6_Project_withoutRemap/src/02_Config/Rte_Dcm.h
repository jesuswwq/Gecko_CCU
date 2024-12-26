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
**  FILENAME    : Rte_Dcm.h                                                   **
**                                                                            **
**  Created on  : 2023/12/7 16:21:42                                          **
**  Author      : chunjun.hua                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Callout function for Dcm                                    **
**                                                                            **
**  SPECIFICATION(S) :   NONE                                                 **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *  V1.0.0      20231207   chunjun.hua       Initial Version
 */

#ifndef RTEDCM_H
#define RTEDCM_H

/*******************************************************************************
**                      Include                                               **
*******************************************************************************/
#include "FL.h"
#include "Dcm.h"
#include "Appl_Dcm.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
/*==============================22 Service ===================================*/
extern FL_ResultType Rte_Dcm_0xF084_ReadData(uint8* readData, uint16* readLength);

extern FL_ResultType Rte_Dcm_0xF085_ReadData(uint8* readData, uint16* readLength);

extern FL_ResultType Rte_Dcm_0xF15B_ReadData(uint8* readData, uint16* readLength);

/*==============================2E Service ===================================*/
extern FL_ResultType Rte_Dcm_FingerPrint_0xF15A_WriteData(const uint8* data, const uint16 length);

/*==============================27 Service ===================================*/
/******************************************************************************/
/**
 * @brief               <compute key>
 *
 * <compute key before compute key> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <seed (IN), k (IN)>
 * @param[out]          <key (OUT)>
 * @param[in/out]       <NONE>
 * @return              <SecM_StatusType>
 */
/******************************************************************************/

extern SecM_StatusType Rte_Dcm_SecMComputeKey(const SecM_SeedType* seed, const SecM_WordType mask, SecM_KeyType* key);

/*==============================31 Service ===================================*/
extern void Rte_Dcm_CheckProgPreCondition_0xFF02(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);

extern void Rte_Dcm_EraseMemory_0xFF00(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);

extern void Rte_Dcm_CheckMemory_0xF001(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);

extern void Rte_Dcm_CheckProgDependencies_0xFF01(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);

extern void Rte_Dcm_SwapSwitch_0xF017(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);

#endif /*RTEDCM_H*/
