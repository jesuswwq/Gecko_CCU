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
**  FILENAME    : Nm_PBcfg.c                                                  **
**                                                                            **
**  Created on  :                                                             **
**  Author      : Wanglili                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Nm.h"
/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/

#define NM_START_SEC_CONST_UNSPECIFIED
#include "Nm_MemMap.h"
const Nm_ConfigType Nm_Config =  /* PRQA S 1531 */ /* MISRA Rule 8.7 */
{
    NULL_PTR /*NmEcucPartitionRef*/
};
#define NM_STOP_SEC_CONST_UNSPECIFIED
#include "Nm_MemMap.h"

