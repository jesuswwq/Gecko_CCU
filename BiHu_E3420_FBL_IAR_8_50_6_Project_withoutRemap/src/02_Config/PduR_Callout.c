
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
**  FILENAME    : PduR_Callout.c                                                  **
**                                                                            **
**  Created on  : 2023/11/23 14:59:01                                         **
**  Author      : long.zhu                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Configuration parameter of PDUR                             **
**                                                                            **
**  SPECIFICATION(S) :   NONE                                                 **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *  V1.0.0      20230818   long.zhu          Initial Version
 */

/*******************************************************************************
**                      Include                                               **
*******************************************************************************/
#include "PduR_Callout.h"
#include "CanTp.h"
#include "CanIf.h"

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/******************************************************************************/
/*
 * Brief               This function performs the processing of the transport layer task.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
void PduRIF_MainFunction(void)
{
    CanIf_MainFunction();
}

/******************************************************************************/
/*
 * Brief               This function performs the processing of the transport layer task.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
void PduRTPIF_MainFunction(void)
{
    CanIf_MainFunction();
    CanTp_MainFunction();
}

/******************************************************************************/
/*
 * Brief               This function performs the processing of the transport layer task.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
void PduR_MainFunction1ms(void)
{
    CanTp_MainFunction();
}

