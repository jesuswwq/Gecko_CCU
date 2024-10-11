/******************************************************************************
**                                                                           **
** Copyright (C) iSOFT   (2022)                                              **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to iSOFT.        **
** Passing on and copying of this document, and communication                **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
**************************************************************************** **
**                                                                           **
**  FILENAME    : Rte_NvM_Type.h                                             **
**                                                                           **
**  Created on  : 2023/11/06 15:38:45                                        **
**  Author      :                                                            **
**  Vendor      :                                                            **
**  DESCRIPTION : Providing the types for the NvM module                     **
**                                                                           **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                      **
**                                                                           **
**************************************************************************** */

#ifndef RTE_NVM_TYPE_H_
#define RTE_NVM_TYPE_H_

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"

/*
 * This is an asynchronous request result returned by the API service NvM_GetErrorStatus.
 * The availability of an asynchronous request result can be additionally signaled
 * via a callback function.
 */
typedef enum
{
    /*The last asynchronous request has been finished successfully. This shall be the default value after rese*/
    NVM_REQ_OK,
    /*The last asynchronous read/write/control request has been finished unsuccessfully*/
    NVM_REQ_NOT_OK,
    /*An asynchronous read/write/control request is currently pending*/
    NVM_REQ_PENDING,
    /* The result of the last asynchronous request NvM_ReadBlock or
    * NvM_ReadAll is a data integrity failure.
    * In case of NvM_ReadBlock the content of the RAM block has changed but has become invalid.
    * The application is responsible to renew and validate the RAM block content.*/
    NVM_REQ_INTEGRITY_FAILED,
    /* The referenced block was skipped during execution of NvM_ReadAll or NvM_WriteAll,
     * Dataset NVRAM blocks (NvM_ReadAll) or NVRAM blocks without a permanently configured RAM block.*/
    NVM_REQ_BLOCK_SKIPPED,
    /*The referenced NV block is invalidated*/
    NVM_REQ_NV_INVALIDATED,
    /*The multi block request NvM_WriteAll was cancelled by calling NvM_CancelWriteAll.*/
    NVM_REQ_CANCELED,
    /*The required redundancy of the referenced NV block is lost*/
    NVM_REQ_REDUNDANCY_FAILED,
    /*The referenced NV block had the default values copied to the RAM image.*/
    NVM_REQ_RESTORED_FROM_ROM
} NvM_RequestResultType;

typedef uint16 NvM_BlockIdType;     /* req NVM471 */

typedef enum
{
    /*NvM_ReadBlock/ NvM_ReadPRAMBlock is requested on the block*/
    NVM_INIT_READ_BLOCK,
    /*NvM_RestoreBlockDefaults/ NvM_RestorePRAMBlockDefaults is requested on the block*/
    NVM_INIT_RESTORE_BLOCK_DEFAULTS,
    /*NvM_ReadAll is processing this block*/
    NVM_INIT_READ_ALL_BLOCK,
    /*NvM_FirstInitAll is processing this block*/
    NVM_INIT_FIRST_INIT_ALL
} NvM_InitBlockRequestType;

#define _DEFINED_TYPEDEF_FOR_NvM_InitBlockRequestType_

typedef enum
{
    /*NvM_ReadBlock/ NvM_ReadPRAMBlock was performed on the block*/
    NVM_READ_BLOCK,
    /*NvM_WriteBlock/ NvM_WritePRAMBlock was performed on the block*/
    NVM_WRITE_BLOCK,
    /*NvM_RestoreBlockDefaults/ NvM_RestorePRAMBlockDefaults was performed on the block*/
    NVM_RESTORE_BLOCK_DEFAULTS,
    /*NvM_EraseNvBlock was performed on the block*/
    NVM_ERASE_NV_BLOCK,
    /*NvM_InvalidateNvBlock was performed on the block*/
    NVM_INVALIDATE_NV_BLOCK,
    /*NvM_ReadAll has finished processing this block*/
    NVM_READ_ALL_BLOCK
} NvM_BlockRequestType;

#define _DEFINED_TYPEDEF_FOR_NvM_BlockRequestType_

#endif /* RTE_NVM_TYPE_H_ */

