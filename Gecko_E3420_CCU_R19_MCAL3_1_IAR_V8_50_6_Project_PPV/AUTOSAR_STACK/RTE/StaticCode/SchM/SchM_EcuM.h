/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2022)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : SchM_EcuM.c                                                 **
**                                                                            **
**  Created on  :                                                             **
**  Author      : qinchun.yang                                                **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*  <VERSION>    <DATE>      <AUTHOR>        <REVISION LOG>
 *  V1.0.0       2020-06-28  qinchun.yang    R19_11 EcuM initial version.
 *  V2.0.0       2021-04-08  qinchun.yang    R1911 stable version.
 */
#ifndef SCHM_ECUM_H
#define SCHM_ECUM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define SchM_Enter_EcuM_GetPendingWkEv() ((void)0)
#define SchM_Eixt_EcuM_GetPendingWkEv()  ((void)0)

#define SchM_Enter_EcuM_ClrWkEv()        ((void)0)
#define SchM_Eixt_EcuM_ClrWkEv()         ((void)0)

#define SchM_Enter_EcuM_GetValidWkEv()   ((void)0)
#define SchM_Exit_EcuM_GetValidWkEv()    ((void)0)

#define SchM_Enter_EcuM_GetExpiredWkEv() ((void)0)
#define SchM_Exit_EcuM_GetExpiredWkEv()  ((void)0)

#define SchM_Enter_EcuM_SetWkEv()        ((void)0)
#define SchM_Exit_EcuM_SetWkEv()         ((void)0)

#define SchM_Enter_EcuM_ValidWkEv()      ((void)0)
#define SchM_Exit_EcuM_ValidWkEv()       ((void)0)
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
/**
 * The purpose of this service is to implement all activities of the ECU State
 * Manager while the OS is up and running.
 * Service ID[hex]: 0x18
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_CODE) EcuM_MainFunction(void);
#endif /* SCHM_ECUM_H */
