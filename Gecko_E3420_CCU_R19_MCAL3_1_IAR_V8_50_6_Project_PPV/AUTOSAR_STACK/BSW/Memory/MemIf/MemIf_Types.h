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
**  FILENAME    : MemIf_Types.h                                               **
**                                                                            **
**  Created on  : 2020/08/19                                                  **
**  Author      : Haibin.Shao                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : MemIf Types header description                              **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/******************************************************************************
**                      Revision Control History                             **
******************************************************************************/
/*  <VERSION>    <DATE>      <AUTHOR>        <REVISION LOG>
 *  V1.0.0     2020-08-19   Haibin.Shao   R19_11 Ea initial version.
 */
#ifndef MEMIF_TYPES_H_
#define MEMIF_TYPES_H_

/*==============================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==============================================================================*/
#include "Std_Types.h"

/*==============================================================================
*                              SOURCE FILE VERSION INFORMATION
==============================================================================*/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* A memory hardware abstraction module's state is denoted in
 * this type. Mainly used in MemIf_GetStatus and related
 * APIs of memory hardware abstraction modules.
 */
typedef enum
{
    MEMIF_UNINIT = 0,
    MEMIF_IDLE = 1,
    MEMIF_BUSY = 2,
    MEMIF_BUSY_INTERNAL = 3
} MemIf_StatusType;

/* A requested job can have one these values after it has been
 * processed. Use in MemIf_GetJobResult and related memory
 * hardware abstraction module APIs.
 */
typedef enum
{
    MEMIF_JOB_OK = 0,
    MEMIF_JOB_FAILED = 1,
    MEMIF_JOB_PENDING = 2,
    MEMIF_JOB_CANCELED = 3,
    MEMIF_BLOCK_INCONSISTENT = 4,
    MEMIF_BLOCK_INVALID = 5
} MemIf_JobResultType;

/* Specifies the processing speed of requested jobs. The exact
 * processing duration in the different modes depends on
 * configuration of the underlying memory hardware abstraction
 * modules.
 */
typedef enum
{
    MEMIF_MODE_SLOW = 0,
    MEMIF_MODE_FAST = 1
} MemIf_ModeType;

/*---- API CFG Type definitions --------------------------------------------*/
/* type definitions for referencing APIs of underlying memory hardware abstraction modules */
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
typedef P2FUNC(void, MEMIF_CODE, MemIf_SetModeType)(MemIf_ModeType Mode);
typedef P2FUNC(
    Std_ReturnType,
    MEMIF_CODE,
    MemIf_ApiReadType)(uint16 BlockNumber, uint16 BlockOffset, uint8* DataBufferPtr, uint16 Length);
typedef P2FUNC(Std_ReturnType, MEMIF_CODE, MemIf_ApiWriteType)(uint16 BlockNumber, uint8 const* DataBufferPtr);
typedef P2FUNC(Std_ReturnType, MEMIF_CODE, MemIf_ApiEraseImmediateBlockType)(uint16 BlockNumber);
typedef P2FUNC(Std_ReturnType, MEMIF_CODE, MemIf_ApiInvalidateBlockType)(uint16 BlockNumber);
typedef P2FUNC(void, MEMIF_CODE, MemIf_ApiCancelType)(void);
typedef P2FUNC(MemIf_StatusType, MEMIF_CODE, MemIf_ApiGetStatusType)(void);
typedef P2FUNC(MemIf_JobResultType, MEMIF_CODE, MemIf_ApiGetJobResultType)(void);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

/* configuration structure, handles the API mapping */
typedef struct
{
    MemIf_SetModeType SetMode;
    MemIf_ApiReadType Read;
    MemIf_ApiWriteType Write;
    MemIf_ApiEraseImmediateBlockType EraseImmediateBlock;
    MemIf_ApiInvalidateBlockType InvalidateBlock;
    MemIf_ApiCancelType Cancel;
    MemIf_ApiGetStatusType GetStatus;
    MemIf_ApiGetJobResultType GetJobResult;
} MemIf_MemHwAApi_Type;

#endif
