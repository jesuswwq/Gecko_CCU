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
**  FILENAME    : MemIf_Cfg.c                                                 **
**                                                                            **
**  Created on  : 2023/11/06 15:38:45                                         **
**  Author      :                                                             **
**  Vendor      : isoft                                                       **
**  DESCRIPTION : MemIf pre compile globle macro define                       **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "MemIf_Cfg.h"
#include "Ea.h"

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/

#define MEMIF_START_SEC_CONST_UNSPECIFIED
#include "MemIf_MemMap.h"
/* PRQA S 1531++ */ /* MISRA Rule 8.7 */
CONST(MemIf_MemHwAApi_Type, MEMIF_CONST) MemIf_MemHwaApis_at[MEMIF_NUMBER_OF_DEVICES] =
/* PRQA S 1531-- */ /* MISRA Rule 8.7 */
{

    {
        /* Device SetMode Operation API */
        Ea_SetMode,
        /* Device Read operation API */
        Ea_Read,
        /* Device Write operation API */
        Ea_Write,
        /* Device Erase Immediate operation API */
        Ea_EraseImmediateBlock,
        /* Device Invalidate operation API */
        Ea_InvalidateBlock,
        /* Device Cancel operation API */
        Ea_Cancel,
        /* Device GetStatus operation API */
        Ea_GetStatus,
        /* Device GetJobResult operation API */
        Ea_GetJobResult
    }
};

#define MEMIF_STOP_SEC_CONST_UNSPECIFIED
#include "MemIf_MemMap.h"
