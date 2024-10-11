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
**  FILENAME    : NvM.c                                                      **
**                                                                           **
**  Created on  : 2020/5/9 15:21:52                                          **
**  Author      : tao.yu                                                     **
**  Vendor      :                                                            **
**  DESCRIPTION :Containing the entire or parts of NVRAM manager code        **
**                                                                           **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                     **
**                                                                           **
**************************************************************************** */

/**
  \page ISOFT_MISRA_Exceptions  MISRA-C:2012 Compliance Exceptions
    ModeName:NvM<br>
  RuleSorce:puhua-rule.rcf 2.3.1

   \li PRQA S 2985 MISRA Rule 2.2 .<br>
    Reason:According to the configuration, the size of the variable after conversion is different, in order to adapt to
  other situations.

   \li PRQA S 2986 MISRA Rule 2.2 .<br>
    Reason:According to the configuration, the size of the variable after conversion is different, in order to adapt to
  other situations.

   \li PRQA S 2877 MISRA Dir 4.1 .<br>
    Reason:According to the configuration, the size of the variable after conversion is different, in order to adapt to
  other situations.

   \li PRQA S 3408 MISRA Rule 8.4 .<br>
    Reason:These two functions are deliberately designed to be empty, there is a unified processing of the main
  function, the function is not affected

    \li PRQA S 3432 MISRA Rule 20.7 .<br>
    Reason:Function-like macros are used to allow more efficient code.

    \li PRQA S 0311 MISRA Rule 11.8 .<br>
    Reason:Necessary format conversion, which needs to be converted to a void pointer for passing.

    \li PRQA S 1514 MISRA Rule 8.9 .<br>
    Reason:Global variables are used for application code access.

    \li PRQA S 1532 MISRA Rule 8.7 .<br>
    Reason:In order to make the module code structure clear, the functions are classified.

    \li PRQA S 1504 MISRA Rule 8.7 .<br>
    Reason:Global variables are used for application code access.

    \li PRQA S 0306 MISRA Rule 11.4 .<br>
    Reason:Necessary format conversion.
 */

/*====================[I N C L U D E S]====================*/
#include "NvM.h"      /* req NVM077 */
#include "MemIf.h"    /* req NVM077 */
#include "SchM_NvM.h" /* req NVM077 */
#include "NvM_Types.h"
#include "NvM_Inter.h"
#if ((STD_ON == NVM_BSWM_MULTIBLOCK_JOBSTATUS_INFORMATION) || (STD_ON == NVM_BSWM_SINGLEBLOCK_JOBSTATUS_INFORMATION))
#include "BswM.h"
#endif
#if (STD_ON == NVM_DEM_PRODUCTION_ERROR_DETECT)
#include "Dem.h" /* req NVM077 */
#endif
#if (STD_ON == NVM_INCLUDE_CRC)
#include "Crc.h" /* req NVM077 */
#endif
#include "Det.h" /* req NVM077 */

/*====================[V E R S I O N  C H E C K]====================*/
/* req NVM089 */
#ifndef NVM_AR_RELEASE_MAJOR_VERSION
#error " Nvm version miss"
#endif
#ifndef NVM_AR_RELEASE_MINOR_VERSION
#error " Nvm version miss"
#endif
#ifndef NVM_AR_RELEASE_PATCH_VERSION
#error " Nvm version miss"
#endif
#if ((2 != NVM_CFG_SW_MAJOR_VERSION) || (0 != NVM_CFG_SW_MINOR_VERSION) || (0 != NVM_CFG_SW_PATCH_VERSION))
#error " cfg version mismatching"
#endif

/*====================[F U N C  D E C L A R A T I O N]====================*/
#if (NVM_API_CONFIG_CLASS_1 != NVM_API_CONFIG_CLASS)
static FUNC(Std_ReturnType, NVM_CODE) NvM_CancelJobInQueue(NvM_BlockIdType BlockId);
static FUNC(Std_ReturnType, NVM_CODE) NvM_NormalQueueSort(NvM_BlockIdType BlockId);
#if (STD_ON == NVM_JOB_PRIORITIZATION)
static FUNC(Std_ReturnType, NVM_CODE) NvM_ImmedQueueSort(NvM_BlockIdType BlockId);
#endif
#endif

/*====================[F U N C  D E C L A R A T I O N]====================*/

#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"
/*
 * Brief               Service for resetting all internal variables
 * ServiceId           0x00
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      ConfigPtr
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
/* req NVM447 NVM399 NVM400 NVM192 */
FUNC(void, NVM_CODE) NvM_Init(const NvM_ConfigType* ConfigPtr)
{
    uint16 l_BlockIdLoop;
    uint8 WRITEPROT;

#if ((NVM_API_CONFIG_CLASS_1 != NVM_API_CONFIG_CLASS) && (STD_ON == NVM_JOB_PRIORITIZATION))
    uint8 l_LoopCount;
    uint8 l_ModLoop;
    uint8 l_ModLoopCount;
#endif

#if ((NVM_API_CONFIG_CLASS_1 != NVM_API_CONFIG_CLASS) && (STD_ON == NVM_JOB_PRIORITIZATION))
    l_LoopCount = (NVM_SIZE_STANDARD_JOB_QUEUE - 1U) >> 4U; /*the data used for array,so minus 1*/
    l_ModLoopCount = (NVM_SIZE_STANDARD_JOB_QUEUE - 1U) % 16U;
    NvM_QueueSpaceTalbe[NVM_TABLE_SIZE_JOB_QUEUE - 1U] = 0x0000u;
    NvM_QueueSpaceTalbe[l_LoopCount] = 0x0000u;

    for (l_BlockIdLoop = 0; l_BlockIdLoop <= l_LoopCount; l_BlockIdLoop++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
    {
#if (NVM_SIZE_STANDARD_JOB_QUEUE > 0x10u)
        if (l_BlockIdLoop < l_LoopCount)
        {
            NvM_QueueSpaceTalbe[l_BlockIdLoop] = 0xFFFFu;
            /*Each bit stand for one element of the NvM_QueueSpaceTalbe[]*/
        }
        else
#endif /* #if (NVM_SIZE_STANDARD_JOB_QUEUE > 0xFu) */
        {
            for (l_ModLoop = 0; l_ModLoop <= l_ModLoopCount; l_ModLoop++)
            {
                NvM_QueueSpaceTalbe[l_LoopCount] |= (uint16)((uint16)0x0001u << l_ModLoop);
            }
        }
        NvM_QueueSpaceTalbe[NVM_TABLE_SIZE_JOB_QUEUE - 1U] |= (uint16)((uint16)0x0001u << l_BlockIdLoop);
        /*The last element is the summary for previous 16 elements,
         *  one bit stands for one element*/
    }
#endif
    for (l_BlockIdLoop = 0; l_BlockIdLoop < (uint16)NVM_BLOCK_NUM_ALL; l_BlockIdLoop++)
    {
        NvM_AdminBlock[l_BlockIdLoop].FlagGroup = 0;
        NvM_AdminBlock[l_BlockIdLoop].CurrentIndex = 0; /* req NVM192 */
        NvM_AdminBlock[l_BlockIdLoop].ServiceID = NVM_NONE_SERV_ID;
        NvM_AdminBlock[l_BlockIdLoop].SingleReqResult = NVM_REQ_NOT_OK;
        NvM_AdminBlock[l_BlockIdLoop].ReadReq = FALSE; /* req NVM952 */

        WRITEPROT = NvM_GetWordBitState(NvM_BlockDescriptor[l_BlockIdLoop].FlagGroup, (uint8)NVM_BLOCK_DESC_WRITEPROT);
        if ((uint8)STD_ON == WRITEPROT)
        {
            NvM_SetWordBitState(&NvM_AdminBlock[l_BlockIdLoop].FlagGroup, NVM_ADMIN_NV_WRPRO, STD_ON);
        }
        else
        {
            NvM_SetWordBitState(&NvM_AdminBlock[l_BlockIdLoop].FlagGroup, NVM_ADMIN_NV_WRPRO, STD_OFF);
        }
    }
    NvM_Module.JobStep = NVM_JOB_STEP_IDLE;
    NvM_Module.Init = STD_ON;
    NVM_UNUSED(ConfigPtr);
}
#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

#if (NVM_API_CONFIG_CLASS_3 == NVM_API_CONFIG_CLASS)
/*
 * Brief               Service for setting/resetting the write protection for a NV block
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      BlockId: The block identifier uniquely identifies one
 * NVRAM block descriptor. A NVRAM block descriptor contains all needed
 *  information about a single NVRAM block.ProtectionEnabled: TRUE: Write
 *  protection shall be enabled FALSE: Write protection shall be disabled
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"
FUNC(Std_ReturnType, NVM_CODE)
NvM_SetBlockProtection(NvM_BlockIdType BlockId, boolean ProtectionEnabled) /* req NVM450 */
{
    Std_ReturnType l_ReturnValue = E_NOT_OK;
    uint8 ENQUEUE;
    uint8 WRITEBLOCKONCE;
    uint8 LOCKED;

#if (STD_ON == NVM_DEV_ERROR_DETECT)
    if ((uint8)STD_ON != NvM_Module.Init)
    {
        NVM_DET_REPORTERROR((uint8)NVM_SET_BLOCK_PROTECTION_SERV_ID, NVM_E_UNINIT);
    }
    else if (((uint16)NVM_BLOCK_NUM_ALL < BlockId) || (0U == BlockId))
    {
        NVM_DET_REPORTERROR((uint8)NVM_SET_BLOCK_PROTECTION_SERV_ID, NVM_E_PARAM_BLOCK_ID);
    }
    else
#endif
    {
        ENQUEUE = NvM_GetWordBitState(NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_ENQUEUE);
        WRITEBLOCKONCE =
            NvM_GetWordBitState(NvM_BlockDescriptor[BlockId - 1U].FlagGroup, (uint8)NVM_BLOCK_DESC_WRITEBLOCKONCE);
        LOCKED = NvM_GetWordBitState(NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_BLOCK_LOCKED);
        if ((uint8)STD_ON == ENQUEUE)
        {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
            NVM_DET_REPORTERROR((uint8)NVM_SET_BLOCK_PROTECTION_SERV_ID, NVM_E_BLOCK_PENDING);
#endif
        }
        else if ((uint8)STD_ON == WRITEBLOCKONCE)
        {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
            NVM_DET_REPORTERROR((uint8)NVM_SET_BLOCK_PROTECTION_SERV_ID, NVM_E_BLOCK_CONFIG); /* req NVM276 */
#endif
        }
        else if ((uint8)STD_ON == LOCKED)
        {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
            NVM_DET_REPORTERROR((uint8)NVM_SET_BLOCK_PROTECTION_SERV_ID, NVM_E_BLOCK_LOCKED); /* req NVM759 */
#endif
        }
        else
        {
            if (TRUE == ProtectionEnabled)
            {
                NvM_SetWordBitState(
                    &NvM_AdminBlock[BlockId - 1U].FlagGroup,
                    NVM_ADMIN_NV_WRPRO,
                    STD_ON); /* req NVM016*/
            }
            else
            {
                NvM_SetWordBitState(&NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_NV_WRPRO, STD_OFF);
            }
            l_ReturnValue = E_OK;
        }
    }
    return l_ReturnValue;
}
#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"
/*
 * Brief               Service to invalidate a NV block
 * ServiceId           0x0b
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      BlockId: The block identifier uniquely identifies one
 *  NVRAM block descriptor.
 *                               A NVRAM block descriptor contains all needed
 *                               information about a single NVRAM block.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              E_OK: request has been accepted
 *                     E_NOT_OK: request has not been accepted
 * PreCondition        None
 * CallByAPI           Up layer
 */
/* req NVM027 NVM191 NVM409 */
FUNC(Std_ReturnType, NVM_CODE)
NvM_InvalidateNvBlock(NvM_BlockIdType BlockId)
{
    Std_ReturnType l_ReturnValue = E_NOT_OK;
    uint8 ENQUEUE;
    uint8 LOCKED;
    uint8 WRPRO;
    uint8 WRITEBLOCKONCE;

#if (STD_ON == NVM_DEV_ERROR_DETECT)
    if ((uint8)STD_ON != NvM_Module.Init)
    {
        NVM_DET_REPORTERROR((uint8)NVM_INVALIDATE_NV_BLOCK_SERV_ID, NVM_E_UNINIT); /* req NVM638 */
    }
    else if (((uint16)NVM_BLOCK_NUM_ALL < BlockId) || (0U == BlockId))
    {
        NVM_DET_REPORTERROR((uint8)NVM_INVALIDATE_NV_BLOCK_SERV_ID, NVM_E_PARAM_BLOCK_ID); /* req NVM642 */
    }
    else
#endif
    {
        ENQUEUE = NvM_GetWordBitState(NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_ENQUEUE);
        LOCKED = NvM_GetWordBitState(NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_BLOCK_LOCKED);
        WRPRO = NvM_GetWordBitState(NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_NV_WRPRO);
        WRITEBLOCKONCE =
            NvM_GetWordBitState(NvM_BlockDescriptor[BlockId - 1U].FlagGroup, (uint8)NVM_BLOCK_DESC_WRITEBLOCKONCE);
        if ((uint8)STD_ON == ENQUEUE)
        {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
            /* req NVM639 */
            NVM_DET_REPORTERROR((uint8)NVM_INVALIDATE_NV_BLOCK_SERV_ID, NVM_E_BLOCK_PENDING);
#endif
        }
        else if ((uint8)STD_ON == LOCKED)
        {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
            /* req NVM756 */
            NVM_DET_REPORTERROR((uint8)NVM_INVALIDATE_NV_BLOCK_SERV_ID, NVM_E_BLOCK_LOCKED);
#endif
        }
        else if ((uint8)STD_ON == WRPRO)
        {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
            NVM_DET_REPORTERROR((uint8)NVM_INVALIDATE_NV_BLOCK_SERV_ID, NVM_E_WRITE_PROTECTED_DET);
#endif
#if (STD_ON == NVM_DEM_E_WRITE_PROTECTED)
            Dem_ReportErrorStatus(NVM_E_WRITE_PROTECTED, DEM_EVENT_STATUS_FAILED);
#endif
        }
        else if (((uint8)STD_ON == WRITEBLOCKONCE) && (NvM_AdminBlock[BlockId - 1U].ReadReq == FALSE))
        {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
            NVM_DET_REPORTERROR((uint8)NVM_INVALIDATE_NV_BLOCK_SERV_ID, NVM_E_WRITE_ONCE_STATUS_UNKNOWN);
#endif
        }
        else
        {
            if ((NVM_BLOCK_DATASET != NvM_BlockDescriptor[BlockId - 1U].NvmBlockManagementType)
                || ((NvM_BlockDescriptor[BlockId - 1U].NvmNvBlockNum > NvM_AdminBlock[BlockId - 1U].CurrentIndex)
                    && (NVM_BLOCK_DATASET == NvM_BlockDescriptor[BlockId - 1U].NvmBlockManagementType)))
            {
                l_ReturnValue = NvM_JobEnqueue(BlockId, NVM_INVALIDATE_NV_BLOCK_SERV_ID, NULL_PTR);
            }
        }
    }
    return l_ReturnValue;
}
#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

#if (STD_ON == NVM_JOB_PRIORITIZATION)
/*
 * Brief               Service to erase a NV block
 * ServiceId           0x09
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      BlockId: The block identifier uniquely identifies
 * one NVRAM block descriptor.
 *                               A NVRAM block descriptor contains all
 *                               needed information about a single NVRAM block.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              E_OK: request has been accepted
 *                     E_NOT_OK: request has not been accepted
 * PreCondition        None
 * CallByAPI           Up layer
 */
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"
FUNC(Std_ReturnType, NVM_CODE) NvM_EraseNvBlock(NvM_BlockIdType BlockId)
{
    Std_ReturnType l_ReturnValue = E_NOT_OK;
    uint8 ENQUEUE;
    uint8 LOCKED;
    uint8 WRPRO;
    uint8 WRITEBLOCKONCE;

#if (STD_ON == NVM_DEV_ERROR_DETECT)
    if ((uint8)STD_ON != NvM_Module.Init)
    {
        NVM_DET_REPORTERROR((uint8)NVM_ERASE_NV_BLOCK_SERV_ID, NVM_E_UNINIT);
    }
    else if (((uint16)NVM_BLOCK_NUM_ALL < BlockId) || (0U == BlockId))
    {
        NVM_DET_REPORTERROR((uint8)NVM_ERASE_NV_BLOCK_SERV_ID, NVM_E_PARAM_BLOCK_ID);
    }
    else
#endif
    {
        ENQUEUE = NvM_GetWordBitState(NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_ENQUEUE);
        LOCKED = NvM_GetWordBitState(NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_BLOCK_LOCKED);
        WRPRO = NvM_GetWordBitState(NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_NV_WRPRO);
        WRITEBLOCKONCE =
            NvM_GetWordBitState(NvM_BlockDescriptor[BlockId - 1U].FlagGroup, (uint8)NVM_BLOCK_DESC_WRITEBLOCKONCE);
        if ((uint8)STD_ON == ENQUEUE)
        {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
            NVM_DET_REPORTERROR((uint8)NVM_ERASE_NV_BLOCK_SERV_ID, NVM_E_BLOCK_PENDING);
#endif
        }
        else if (
            (STD_OFF == NVM_JOB_PRIORITIZATION)
            || ((0U != NvM_BlockDescriptor[BlockId - 1U].NvmBlockJobPriority) && (STD_ON == NVM_JOB_PRIORITIZATION)))
        {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
            /* req NVM357 */
            NVM_DET_REPORTERROR((uint8)NVM_ERASE_NV_BLOCK_SERV_ID, NVM_E_BLOCK_CONFIG);
#endif
        }
        else if ((uint8)STD_ON == LOCKED)
        {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
            /* req NVM757 */
            NVM_DET_REPORTERROR((uint8)NVM_ERASE_NV_BLOCK_SERV_ID, NVM_E_BLOCK_LOCKED);
#endif
        }
        else if ((uint8)STD_ON == WRPRO)
        {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
            NVM_DET_REPORTERROR((uint8)NVM_ERASE_NV_BLOCK_SERV_ID, NVM_E_WRITE_PROTECTED_DET);
#endif
#if (STD_ON == NVM_DEM_E_WRITE_PROTECTED)
            Dem_ReportErrorStatus(NVM_E_WRITE_PROTECTED, DEM_EVENT_STATUS_FAILED);
#endif
        }
        else if (((uint8)STD_ON == WRITEBLOCKONCE) && (NvM_AdminBlock[BlockId - 1U].ReadReq == FALSE))
        {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
            /* req NVM952 */
            NVM_DET_REPORTERROR((uint8)NVM_ERASE_NV_BLOCK_SERV_ID, NVM_E_WRITE_ONCE_STATUS_UNKNOWN);
#endif
        }
        else
        {
            if ((NVM_BLOCK_DATASET != NvM_BlockDescriptor[BlockId - 1U].NvmBlockManagementType)
                || ((NvM_BlockDescriptor[BlockId - 1U].NvmNvBlockNum > NvM_AdminBlock[BlockId - 1U].CurrentIndex)
                    && (NVM_BLOCK_DATASET == NvM_BlockDescriptor[BlockId - 1U].NvmBlockManagementType)))
            {
                l_ReturnValue = NvM_JobEnqueue(BlockId, NVM_ERASE_NV_BLOCK_SERV_ID, NULL_PTR);
            }
        }
    }
    return l_ReturnValue;
}
#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"
#endif

#endif
/*
 * Brief               Service to read the block dependent error/status information
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      BlockId: The block identifier uniquely identifies one
 * NVRAM block descriptor.
 *                               A NVRAM block descriptor contains all needed
 *                               information about a single NVRAM block.
 * Param-Name[out]     RequestResultPtr: Pointer to where to store the request result
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"
FUNC(Std_ReturnType, NVM_CODE)
NvM_GetErrorStatus(NvM_BlockIdType BlockId, NvM_RequestResultType* RequestResultPtr) /* req NVM451 */
{
    Std_ReturnType l_ReturnValue = E_NOT_OK;

#if (STD_ON == NVM_DEV_ERROR_DETECT)
    if ((uint8)STD_ON != NvM_Module.Init)
    {
        NVM_DET_REPORTERROR((uint8)NVM_GET_ERROR_STATUS_SERV_ID, NVM_E_UNINIT);
    }
    else if ((uint16)NVM_BLOCK_NUM_ALL < BlockId)
    {
        NVM_DET_REPORTERROR((uint8)NVM_GET_ERROR_STATUS_SERV_ID, NVM_E_PARAM_BLOCK_ID);
    }
    else if (NULL_PTR == RequestResultPtr)
    {
        NVM_DET_REPORTERROR((uint8)NVM_GET_ERROR_STATUS_SERV_ID, NVM_E_PARAM_DATA);
    }
    else
#endif
    {
        if (0U == BlockId)
        {
            /*multi job is running but not execute over,return the latest single job result*/
            *RequestResultPtr = NvM_MultiJob.ReqResult; /* req NVM015 */
            l_ReturnValue = E_OK;
        }
        else
        {
            /*single type job is running*/
            *RequestResultPtr = NvM_AdminBlock[BlockId - 1U].SingleReqResult; /* req NVM015 */
            l_ReturnValue = E_OK;
        }
    }
    return l_ReturnValue;
}
#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

#if (STD_ON == NVM_SET_RAM_BLOCK_STATUS_API)
/*
 * Brief               Service for setting the RAM block status of an NVRAM block
 * ServiceId           0x05
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      BlockId: The block identifier uniquely identifies one
 *  NVRAM block descriptor.
 *                               A NVRAM block descriptor contains all needed
 *                               information about a single NVRAM block.
 *                     BlockChanged: TRUE: Validate the RAM block and mark block as changed
 *                                 FALSE: Invalidate the RAM block and mark block as unchanged
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"
FUNC(Std_ReturnType, NVM_CODE) NvM_SetRamBlockStatus(NvM_BlockIdType BlockId, boolean BlockChanged) /* req NVM453 */
{
    Std_ReturnType l_ReturnValue = E_NOT_OK;
    uint8 WRPRO;
    uint8 ENQUEUE;
    uint8 LOCKED;
    uint8 SYNCMECHANISM;
    uint8 CALCRAMBLOCKCRC;
    uint8 REPAIR;
    uint8 SETRAMSTATUS;

#if (STD_ON == NVM_DEV_ERROR_DETECT)
    if ((uint8)STD_ON != NvM_Module.Init)
    {
        NVM_DET_REPORTERROR((uint8)NVM_SET_RAM_BLOCK_STATUS_SERV_ID, NVM_E_UNINIT);
    }
    else if (((uint16)NVM_BLOCK_NUM_ALL < BlockId) || (0U == BlockId))
    {
        NVM_DET_REPORTERROR((uint8)NVM_SET_RAM_BLOCK_STATUS_SERV_ID, NVM_E_PARAM_BLOCK_ID);
    }
    else
#endif
    {
        ENQUEUE = NvM_GetWordBitState(NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_ENQUEUE);
        LOCKED = NvM_GetWordBitState(NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_BLOCK_LOCKED);
        if ((uint8)STD_ON == ENQUEUE)
        {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
            NVM_DET_REPORTERROR((uint8)NVM_SET_RAM_BLOCK_STATUS_SERV_ID, NVM_E_BLOCK_PENDING);
#endif
        }
        else if ((uint8)STD_ON == LOCKED)
        {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
            NVM_DET_REPORTERROR((uint8)NVM_SET_RAM_BLOCK_STATUS_SERV_ID, NVM_E_BLOCK_LOCKED);
#endif
        }
        else
        {
            WRPRO = NvM_GetWordBitState(NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_NV_WRPRO);
            SYNCMECHANISM =
                NvM_GetWordBitState(NvM_BlockDescriptor[BlockId - 1U].FlagGroup, (uint8)NVM_BLOCK_DESC_SYNCMECHANISM);
            SETRAMSTATUS =
                NvM_GetWordBitState(NvM_BlockDescriptor[BlockId - 1U].FlagGroup, (uint8)NVM_BLOCK_DESC_SETRAMSTATUS);
            if (((uint8)STD_OFF == WRPRO)
                && ((NULL_PTR != NvM_BlockDescriptor[BlockId - 1U].NvmRamBlockDataAddress)
                    || ((uint8)STD_ON == SYNCMECHANISM))
                && ((uint8)STD_ON == SETRAMSTATUS))
            {
                if ((boolean)TRUE == BlockChanged)
                {
                    NvM_SetWordBitState(
                        &NvM_AdminBlock[BlockId - 1U].FlagGroup,
                        NVM_ADMIN_RAM_VALID,
                        STD_ON); /* req NVM241 NVM406 344 */
                    NvM_SetWordBitState(&NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_RAM_CHANGED, STD_ON);
                    CALCRAMBLOCKCRC = NvM_GetWordBitState(
                        NvM_BlockDescriptor[BlockId - 1U].FlagGroup,
                        (uint8)NVM_BLOCK_DESC_CALCRAMBLOCKCRC);
                    REPAIR = NvM_GetWordBitState(NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_NV_REPAIR);
                    if ((uint8)STD_ON == CALCRAMBLOCKCRC)
                    {
                        /* req NVM121 : The Req is useless,
                         * no further clarification about the use of Crc*/
                        if ((Std_ReturnType)E_NOT_OK
                            == NvM_JobEnqueue(BlockId, NVM_SET_RAM_BLOCK_STATUS_SERV_ID, NULL_PTR))
                        {
                            /*Reserved*/
                        }
                    }
                    if ((uint8)STD_ON == REPAIR)
                    {
                        NvM_SetWordBitState(&NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_NV_REPAIR, STD_OFF);
                    }
                }
                else
                {
                    NvM_SetWordBitState(
                        &NvM_AdminBlock[BlockId - 1U].FlagGroup,
                        NVM_ADMIN_RAM_VALID,
                        STD_OFF); /* req NVM405  345*/
                    NvM_SetWordBitState(
                        &NvM_AdminBlock[BlockId - 1U].FlagGroup,
                        NVM_ADMIN_RAM_CHANGED,
                        STD_OFF); /* req NVM405 */
                }
                l_ReturnValue = E_OK;
                /*please ref state diagram to complete this func*/
            }
        }
    }
    return l_ReturnValue;
}
#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"
#endif

/*
 * Brief               Service for setting the RAM block status of an NVRAM block
 * ServiceId           0x13
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      BlockId: The block identifier uniquely identifies one
 * NVRAM block descriptor.
 *                               A NVRAM block descriptor contains all needed
 *                               information about a single NVRAM block.
 *                     BlockChanged: TRUE: Validate the RAM block and mark block as changed
 *                                 FALSE: Invalidate the RAM block and mark block as unchanged
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
/* req NVM027 NVM191 NVM407 NVM408 NVM409 */
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"
FUNC(void, NVM_CODE) NvM_SetBlockLockStatus(NvM_BlockIdType BlockId, boolean BlockLocked)
{
    uint8 ENQUEUE;
    uint8 SYNCMECHANISM;
    uint8 WRITEBLOCKONCE;
#if (STD_ON == NVM_DEV_ERROR_DETECT)
    if ((uint8)STD_ON != NvM_Module.Init)
    {
        NVM_DET_REPORTERROR((uint8)NVM_SET_BLOCK_LOCK_STATUS_SERV_ID, NVM_E_UNINIT);
    }
    else if (((uint16)NVM_BLOCK_NUM_ALL < BlockId) || (0U == BlockId))
    {
        NVM_DET_REPORTERROR((uint8)NVM_SET_BLOCK_LOCK_STATUS_SERV_ID, NVM_E_PARAM_BLOCK_ID);
    }
    else
#endif
    {
        ENQUEUE = NvM_GetWordBitState(NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_ENQUEUE);
        WRITEBLOCKONCE =
            NvM_GetWordBitState(NvM_BlockDescriptor[BlockId - 1U].FlagGroup, (uint8)NVM_BLOCK_DESC_WRITEBLOCKONCE);
        if ((uint8)STD_ON == ENQUEUE)
        {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
            NVM_DET_REPORTERROR((uint8)NVM_SET_BLOCK_LOCK_STATUS_SERV_ID, NVM_E_BLOCK_PENDING);
#endif
        }
        else if ((uint8)STD_ON == WRITEBLOCKONCE)
        {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
            NVM_DET_REPORTERROR((uint8)NVM_SET_BLOCK_LOCK_STATUS_SERV_ID, NVM_E_BLOCK_CONFIG);
#endif
        }
        else
        {
            SYNCMECHANISM =
                NvM_GetWordBitState(NvM_BlockDescriptor[BlockId - 1U].FlagGroup, (uint8)NVM_BLOCK_DESC_SYNCMECHANISM);
            if (((NULL_PTR != NvM_BlockDescriptor[BlockId - 1U].NvmRamBlockDataAddress)
                 || ((uint8)STD_ON == SYNCMECHANISM)))
            {
                if ((boolean)TRUE == BlockLocked)
                {
                    NvM_SetWordBitState(&NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_BLOCK_LOCKED, STD_ON);
                }
                else
                {
                    NvM_SetWordBitState(&NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_BLOCK_LOCKED, STD_OFF);
                }
            }
        }
    }
}
#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

#if (NVM_API_CONFIG_CLASS_1 != NVM_API_CONFIG_CLASS)
/*
 * Brief               Service for setting the DataIndex of a dataset NVRAM block
 * ServiceId           0x01
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      BlockId: The block identifier uniquely identifies one
 * NVRAM block descriptor.
 *                            A NVRAM block descriptor contains all needed
information about a single NVRAM block.
 *                     DataIndex: Index position (association) of a NV/ROM block.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
/* req NVM448 NVM027 NVM191 NVM401 */
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"
FUNC(Std_ReturnType, NVM_CODE) NvM_SetDataIndex(NvM_BlockIdType BlockId, uint8 DataIndex)
{
    Std_ReturnType l_ReturnValue = E_NOT_OK;
    uint8 ENQUEUE;

#if (STD_ON == NVM_DEV_ERROR_DETECT)
    if ((uint8)STD_ON != NvM_Module.Init)
    {
        NVM_DET_REPORTERROR((uint8)NVM_SET_DATA_INDEX_SERV_ID, NVM_E_UNINIT);
    }
    else if (((uint16)NVM_BLOCK_NUM_ALL < BlockId) || (0U == BlockId))
    {
        NVM_DET_REPORTERROR((uint8)NVM_SET_DATA_INDEX_SERV_ID, NVM_E_PARAM_BLOCK_ID);
    }
    else
#endif
    {
        ENQUEUE = NvM_GetWordBitState((NvM_AdminBlock[BlockId - 1U].FlagGroup), NVM_ADMIN_ENQUEUE);
        if ((uint8)STD_ON == ENQUEUE)
        {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
            NVM_DET_REPORTERROR((uint8)NVM_SET_DATA_INDEX_SERV_ID, NVM_E_BLOCK_PENDING);
#endif
        }
        else if (
            (NvM_BlockDescriptor[BlockId - 1U].NvmNvBlockNum + NvM_BlockDescriptor[BlockId - 1U].NvmRomBlockNum)
            <= DataIndex)
        {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
            NVM_DET_REPORTERROR((uint8)NVM_SET_DATA_INDEX_SERV_ID, NVM_E_PARAM_BLOCK_DATA_IDX);
#endif
        }
        else
        {
            if (NVM_BLOCK_DATASET == NvM_BlockDescriptor[BlockId - 1U].NvmBlockManagementType)
            {
                NvM_AdminBlock[BlockId - 1U].CurrentIndex = DataIndex; /* req NVM014 */
                l_ReturnValue = E_OK;
            }
        }
    }
    return l_ReturnValue;
}
#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"
/*
 * Brief               Service for getting the currently set DataIndex of a dataset NVRAM block
 * ServiceId           0x02
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      BlockId: The block identifier uniquely identifies
 * one NVRAM block descriptor.
 *                               A NVRAM block descriptor contains all
 *                                needed information about a single NVRAM block.
 * Param-Name[out]     DataIndexPtr: Pointer to where to store the current dataset index (0..255)
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
/* req NVM027 NVM191 NVM402 */
FUNC(Std_ReturnType, NVM_CODE)
NvM_GetDataIndex(
    NvM_BlockIdType BlockId,
    P2VAR(uint8, AUTOMATIC, NVM_VAR) DataIndexPtr) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    Std_ReturnType l_ReturnValue = E_NOT_OK;

#if (STD_ON == NVM_DEV_ERROR_DETECT)
    if ((uint8)STD_ON != NvM_Module.Init)
    {
        NVM_DET_REPORTERROR((uint8)NVM_GET_DATA_INDEX_SERV_ID, NVM_E_UNINIT);
    }
    else if (((uint16)NVM_BLOCK_NUM_ALL < BlockId) || (0U == BlockId))
    {
        NVM_DET_REPORTERROR((uint8)NVM_GET_DATA_INDEX_SERV_ID, NVM_E_PARAM_BLOCK_ID);
    }
    else if (NULL_PTR == DataIndexPtr)
    {
        NVM_DET_REPORTERROR((uint8)NVM_GET_DATA_INDEX_SERV_ID, NVM_E_PARAM_DATA);
    }
    else
#endif
    {
        if (NVM_BLOCK_DATASET == NvM_BlockDescriptor[BlockId - 1U].NvmBlockManagementType)
        {
            *DataIndexPtr = NvM_AdminBlock[BlockId - 1U].CurrentIndex; /* req NVM021 */
            if ((NvM_BlockDescriptor[BlockId - 1U].NvmNvBlockNum + NvM_BlockDescriptor[BlockId - 1U].NvmRomBlockNum)
                > *DataIndexPtr)
            {
                l_ReturnValue = E_OK;
            }
        }
        else
        {
            *DataIndexPtr = 0; /* req NVM265 */
        }
    }
    return l_ReturnValue;
}
#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"
/*
 * Brief               Service to copy the data of the NV block to its corresponding RAM block
 * ServiceId           0x06
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      BlockId: The block identifier uniquely identifies one
 * NVRAM block descriptor.
 *                               A NVRAM block descriptor contains all needed
 *                               information about a single NVRAM block.
 * Param-Name[out]     NvM_DstPtr: Pointer to the RAM data block
 * Param-Name[in/out]  None
 * Return              E_OK: request has been accepted
 *                     E_NOT_OK: request has not been accepted
 * PreCondition        None
 * CallByAPI           Up layer
 */
/* req NVM027 NVM191 NVM409 */
FUNC(Std_ReturnType, NVM_CODE) NvM_ReadBlock(NvM_BlockIdType BlockId, void* NvM_DstPtr) /* req NVM454 */
{
    Std_ReturnType l_ReturnValue = E_NOT_OK;
    uint8 SYNCMECHANISM;
    uint8 ENQUEUE;

#if (STD_ON == NVM_DEV_ERROR_DETECT)
    if ((uint8)STD_ON != NvM_Module.Init)
    {
        NVM_DET_REPORTERROR((uint8)NVM_READ_BLOCK_SERV_ID, NVM_E_UNINIT); /* req NVM614 */
    }
    else if (((uint16)NVM_BLOCK_NUM_ALL < BlockId) || (0U == BlockId))
    {
        NVM_DET_REPORTERROR((uint8)NVM_READ_BLOCK_SERV_ID, NVM_E_PARAM_BLOCK_ID);
    }
    /* req NVM196 */
    else
#endif
    {
        SYNCMECHANISM =
            NvM_GetWordBitState(NvM_BlockDescriptor[BlockId - 1U].FlagGroup, (uint8)NVM_BLOCK_DESC_SYNCMECHANISM);
        ENQUEUE = NvM_GetWordBitState(NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_ENQUEUE);
        if ((NULL_PTR == NvM_DstPtr) && (NULL_PTR == NvM_BlockDescriptor[BlockId - 1U].NvmRamBlockDataAddress)
            && ((uint8)STD_OFF == SYNCMECHANISM))
        {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
            NVM_DET_REPORTERROR((uint8)NVM_READ_BLOCK_SERV_ID, NVM_E_PARAM_ADDRESS);
#endif
        }
        else if ((uint8)STD_ON == ENQUEUE) /* req NVM615 */
        {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
            NVM_DET_REPORTERROR((uint8)NVM_READ_BLOCK_SERV_ID, NVM_E_BLOCK_PENDING);
#endif
        }
        else
        {
            l_ReturnValue = NvM_JobEnqueue(BlockId, NVM_READ_BLOCK_SERV_ID, (uint8*)NvM_DstPtr);
            if ((Std_ReturnType)E_OK == l_ReturnValue)
            {
                if (((NvM_DstPtr == NvM_BlockDescriptor[BlockId - 1U].NvmRamBlockDataAddress)
                     && (NULL_PTR != NvM_DstPtr))
                    || ((NULL_PTR == NvM_DstPtr)
                        && (NULL_PTR != NvM_BlockDescriptor[BlockId - 1U].NvmRamBlockDataAddress)))
                {
                    NvM_SetWordBitState(
                        &NvM_AdminBlock[BlockId - 1U].FlagGroup,
                        NVM_ADMIN_RAM_VALID,
                        STD_OFF);                                /* req NVM198 */
                    NvM_SetWordBitState(&NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_RAM_CHANGED, STD_OFF);
                    NvM_AdminBlock[BlockId - 1U].ReadReq = TRUE; /* req NVM952 */
                }
            }
        }
    }
    return l_ReturnValue;
}
#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"
/*
 * Brief               Service to copy the data of the NV block to its
 * corresponding permanent RAM block
 * ServiceId           0x16
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      BlockId: The block identifier uniquely identifies
 * one NVRAM block descriptor.
 *                               A NVRAM block descriptor contains all
 *                               needed information about a single NVRAM block.
 * Param-Name[in/out]  None
 * Return              E_OK: request has been accepted
 *                     E_NOT_OK: request has not been accepted
 * PreCondition        None
 * CallByAPI           Up layer
 */
FUNC(Std_ReturnType, NVM_CODE) NvM_ReadPRAMBlock(NvM_BlockIdType BlockId)
{
    Std_ReturnType l_ReturnValue = E_NOT_OK;
    uint8 SYNCMECHANISM;
    uint8 ENQUEUE;

#if (STD_ON == NVM_DEV_ERROR_DETECT)
    if ((uint8)STD_ON != NvM_Module.Init)
    {
        NVM_DET_REPORTERROR((uint8)NVM_READ_PRAM_BLOCK_SERV_ID, NVM_E_UNINIT);
    }
    else if (((uint16)NVM_BLOCK_NUM_ALL < BlockId) || (0U == BlockId))
    {
        NVM_DET_REPORTERROR((uint8)NVM_READ_PRAM_BLOCK_SERV_ID, NVM_E_PARAM_BLOCK_ID);
    }
    /* req NVM196 */
    else
#endif
    {
        SYNCMECHANISM =
            NvM_GetWordBitState(NvM_BlockDescriptor[BlockId - 1U].FlagGroup, (uint8)NVM_BLOCK_DESC_SYNCMECHANISM);
        ENQUEUE = NvM_GetWordBitState(NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_ENQUEUE);
        if (((NULL_PTR == NvM_BlockDescriptor[BlockId - 1U].NvmRamBlockDataAddress)
             && ((uint8)STD_OFF == SYNCMECHANISM)))
        {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
            NVM_DET_REPORTERROR((uint8)NVM_READ_PRAM_BLOCK_SERV_ID, NVM_E_PARAM_ADDRESS);
#endif
        }
        else if ((uint8)STD_ON == ENQUEUE) /* req NVM615 */
        {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
            NVM_DET_REPORTERROR((uint8)NVM_READ_PRAM_BLOCK_SERV_ID, NVM_E_BLOCK_PENDING);
#endif
        }
        else
        {
            l_ReturnValue = NvM_JobEnqueue(BlockId, NVM_READ_PRAM_BLOCK_SERV_ID, NULL_PTR);
            if (((Std_ReturnType)E_OK == l_ReturnValue) && ((uint8)STD_OFF == SYNCMECHANISM))
            {
                /* req NVM198 */
                NvM_SetWordBitState(&NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_RAM_VALID, STD_OFF);
                NvM_SetWordBitState(&NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_RAM_CHANGED, STD_OFF);
            }
        }
    }
    return l_ReturnValue;
}
#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"
/*
 * Brief               Service to copy the data of the RAM block to its corresponding NV block
 * ServiceId           0x07
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      BlockId: The block identifier uniquely identifies
 * one NVRAM block descriptor.
 *                               A NVRAM block descriptor contains all
 *                                needed information about a single NVRAM block.
 *                     NvM_SrcPtr: Pointer to the RAM data block
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              E_OK: request has been accepted
 *                     E_NOT_OK: request has not been accepted
 * PreCondition        None
 * CallByAPI           Up layer
 */
/* req NVM027 NVM191 NVM409 */
FUNC(Std_ReturnType, NVM_CODE) NvM_WriteBlock(NvM_BlockIdType BlockId, const void* NvM_SrcPtr)
{
    Std_ReturnType l_ReturnValue = E_NOT_OK;
    uint8 SYNCMECHANISM;
    uint8 ENQUEUE;
    uint8 WRPRO;
    uint8 LOCKED;
    uint8 WRITEBLOCKONCE;

#if (STD_ON == NVM_DEV_ERROR_DETECT)
    if ((uint8)STD_ON != NvM_Module.Init)
    {
        NVM_DET_REPORTERROR((uint8)NVM_WRITE_BLOCK_SERV_ID, NVM_E_UNINIT); /* req NVM619 */
    }
    else if (((uint16)NVM_BLOCK_NUM_ALL < BlockId) || (0U == BlockId))
    {
        NVM_DET_REPORTERROR((uint8)NVM_WRITE_BLOCK_SERV_ID, NVM_E_PARAM_BLOCK_ID);
    }
    /* req NVM197 */
    else
#endif
    {
        SYNCMECHANISM =
            NvM_GetWordBitState(NvM_BlockDescriptor[BlockId - 1U].FlagGroup, (uint8)NVM_BLOCK_DESC_SYNCMECHANISM);
        ENQUEUE = NvM_GetWordBitState(NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_ENQUEUE);
        if ((NULL_PTR == NvM_SrcPtr) && (NULL_PTR == NvM_BlockDescriptor[BlockId - 1U].NvmRamBlockDataAddress)
            && ((uint8)STD_OFF == SYNCMECHANISM))
        {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
            NVM_DET_REPORTERROR((uint8)NVM_WRITE_BLOCK_SERV_ID, NVM_E_PARAM_ADDRESS);
#endif
        }
        else if ((uint8)STD_ON == ENQUEUE)
        {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
            NVM_DET_REPORTERROR((uint8)NVM_WRITE_BLOCK_SERV_ID, NVM_E_BLOCK_PENDING);
#endif
        }
        else
        {
            WRPRO = NvM_GetWordBitState(NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_NV_WRPRO);
            LOCKED = NvM_GetWordBitState(NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_BLOCK_LOCKED);
            WRITEBLOCKONCE =
                NvM_GetWordBitState(NvM_BlockDescriptor[BlockId - 1U].FlagGroup, (uint8)NVM_BLOCK_DESC_WRITEBLOCKONCE);
            /*. Beyond the Block quantity*/
            if ((NVM_BLOCK_DATASET == NvM_BlockDescriptor[BlockId - 1U].NvmBlockManagementType)
                && (NvM_BlockDescriptor[BlockId - 1U].NvmNvBlockNum <= NvM_AdminBlock[BlockId - 1U].CurrentIndex))
            {
                /*idle*/ /* req NVM411 */
            }
            else if ((uint8)STD_ON == WRPRO)
            {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
                NVM_DET_REPORTERROR((uint8)NVM_WRITE_BLOCK_SERV_ID, NVM_E_WRITE_PROTECTED_DET);
#endif
#if (STD_ON == NVM_DEM_E_WRITE_PROTECTED)
                Dem_ReportErrorStatus(NVM_E_WRITE_PROTECTED, DEM_EVENT_STATUS_FAILED);
#endif
            }
            else if ((uint8)STD_ON == LOCKED)
            {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
                /* req NVM749 */
                NVM_DET_REPORTERROR((uint8)NVM_WRITE_BLOCK_SERV_ID, NVM_E_BLOCK_LOCKED);
#endif
            }
            else if (((uint8)STD_ON == WRITEBLOCKONCE) && (NvM_AdminBlock[BlockId - 1U].ReadReq == FALSE))
            {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
                NVM_DET_REPORTERROR((uint8)NVM_WRITE_BLOCK_SERV_ID, NVM_E_WRITE_ONCE_STATUS_UNKNOWN);
#endif
            }
            else
            {
                l_ReturnValue = NvM_JobEnqueue(BlockId, NVM_WRITE_BLOCK_SERV_ID, (uint8*)NvM_SrcPtr);
                if ((Std_ReturnType)E_OK == l_ReturnValue)
                {
#if (STD_ON == NVM_JOB_PRIORITIZATION)
                    if ((0U == NvM_BlockDescriptor[BlockId - 1U].NvmBlockJobPriority)
                        && (NVM_JOB_STEP_IDLE != NvM_Module.JobStep)
                        && (NVM_JOB_TYPE_SINGLE_IMMED != NvM_Module.CurrentJobType)
                        && (NVM_JOB_TYPE_MULTI_GAP_SINGLE_IMMED != NvM_Module.CurrentJobType))
                    {
                        NvM_Module.JobStep = NVM_JOB_STEP_CANCEL; /* req NVM300 */
                        MemIf_Cancel(NvM_CurRunning.DeviceId);
                        /*re-enqueue the preempted job*/
                        (void)NvM_JobEnqueue(NvM_CurRunning.BlockId, NvM_CurRunning.ServiceId, NvM_CurRunning.RamAddr);
                    }
#endif
                    /*treat the current block as valid.*/
                    if (((NvM_SrcPtr == NvM_BlockDescriptor[BlockId - 1U].NvmRamBlockDataAddress)
                         && (NULL_PTR != NvM_SrcPtr))
                        || ((NULL_PTR == NvM_SrcPtr)
                            && (NULL_PTR != NvM_BlockDescriptor[BlockId - 1U].NvmRamBlockDataAddress)))
                    {
                        NvM_SetWordBitState(&NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_RAM_VALID, STD_ON);
                        NvM_SetWordBitState(
                            &NvM_AdminBlock[BlockId - 1U].FlagGroup,
                            NVM_ADMIN_RAM_CHANGED,
                            STD_ON); /* req NVM303 */
                    }
                }
            }
        }
    }
    return l_ReturnValue;
}
#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"
/*
 * Brief               Service to copy the data of the RAM block to its
 * corresponding permanent RAM block
 * ServiceId           0x17
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      BlockId: The block identifier uniquely identifies
 * one NVRAM block descriptor.
 *                               A NVRAM block descriptor contains all
 *                               needed information about a single NVRAM block.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              E_OK: request has been accepted
 *                     E_NOT_OK: request has not been accepted
 * PreCondition        None
 * CallByAPI           Up layer
 */
FUNC(Std_ReturnType, NVM_CODE) NvM_WritePRAMBlock(NvM_BlockIdType BlockId)
{
    Std_ReturnType l_ReturnValue = E_NOT_OK;
    uint8 SYNCMECHANISM;
    uint8 ENQUEUE;
    uint8 WRPRO;
    uint8 LOCKED;
    uint8 WRITEBLOCKONCE;

#if (STD_ON == NVM_DEV_ERROR_DETECT)
    if ((uint8)STD_ON != NvM_Module.Init)
    {
        NVM_DET_REPORTERROR((uint8)NVM_WRITE_PRAM_BLOCK_SERV_ID, NVM_E_UNINIT);
    }
    else if (((uint16)NVM_BLOCK_NUM_ALL < BlockId) || (0U == BlockId))
    {
        NVM_DET_REPORTERROR((uint8)NVM_WRITE_PRAM_BLOCK_SERV_ID, NVM_E_PARAM_BLOCK_ID);
    }
    /* req NVM197 */
    else
#endif
    {
        SYNCMECHANISM =
            NvM_GetWordBitState(NvM_BlockDescriptor[BlockId - 1U].FlagGroup, (uint8)NVM_BLOCK_DESC_SYNCMECHANISM);
        ENQUEUE = NvM_GetWordBitState(NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_ENQUEUE);
        LOCKED = NvM_GetWordBitState(NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_BLOCK_LOCKED);
        WRITEBLOCKONCE =
            NvM_GetWordBitState(NvM_BlockDescriptor[BlockId - 1U].FlagGroup, (uint8)NVM_BLOCK_DESC_WRITEBLOCKONCE);
        if ((NULL_PTR == NvM_BlockDescriptor[BlockId - 1U].NvmRamBlockDataAddress) && ((uint8)STD_OFF == SYNCMECHANISM))
        {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
            NVM_DET_REPORTERROR((uint8)NVM_WRITE_PRAM_BLOCK_SERV_ID, NVM_E_PARAM_ADDRESS);
#endif
        }
        else if ((uint8)STD_ON == ENQUEUE)
        {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
            NVM_DET_REPORTERROR((uint8)NVM_WRITE_PRAM_BLOCK_SERV_ID, NVM_E_BLOCK_PENDING);
#endif
        }
        else if ((uint8)STD_ON == LOCKED)
        {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
            NVM_DET_REPORTERROR((uint8)NVM_WRITE_PRAM_BLOCK_SERV_ID, NVM_E_BLOCK_LOCKED);
#endif
        }
        else if (((uint8)STD_ON == WRITEBLOCKONCE) && (NvM_AdminBlock[BlockId - 1U].ReadReq == FALSE))
        {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
            NVM_DET_REPORTERROR((uint8)NVM_WRITE_PRAM_BLOCK_SERV_ID, NVM_E_WRITE_ONCE_STATUS_UNKNOWN);
#endif
        }
        else
        {
            WRPRO = NvM_GetWordBitState(NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_NV_WRPRO);
            if (((NVM_BLOCK_DATASET == NvM_BlockDescriptor[BlockId - 1U].NvmBlockManagementType)
                 && (NvM_BlockDescriptor[BlockId - 1U].NvmNvBlockNum <= NvM_AdminBlock[BlockId - 1U].CurrentIndex)))
            {
                /*idle*/ /* req NVM411 */
            }
            else if ((uint8)STD_ON == WRPRO)
            {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
                NVM_DET_REPORTERROR((uint8)NVM_WRITE_PRAM_BLOCK_SERV_ID, NVM_E_WRITE_PROTECTED_DET);
#endif
#if (STD_ON == NVM_DEM_E_WRITE_PROTECTED)
                Dem_ReportErrorStatus(NVM_E_WRITE_PROTECTED, DEM_EVENT_STATUS_FAILED);
#endif
            }
            else
            {
                l_ReturnValue = NvM_JobEnqueue(BlockId, NVM_WRITE_PRAM_BLOCK_SERV_ID, NULL_PTR);
                if ((Std_ReturnType)E_OK == l_ReturnValue)
                {
#if (STD_ON == NVM_JOB_PRIORITIZATION)
                    if ((0U == NvM_BlockDescriptor[BlockId - 1U].NvmBlockJobPriority)
                        && (NVM_JOB_STEP_IDLE != NvM_Module.JobStep)
                        && (NVM_JOB_TYPE_SINGLE_IMMED != NvM_Module.CurrentJobType)
                        && (NVM_JOB_TYPE_MULTI_GAP_SINGLE_IMMED != NvM_Module.CurrentJobType))
                    {
                        NvM_Module.JobStep = NVM_JOB_STEP_CANCEL;
                        MemIf_Cancel(NvM_CurRunning.DeviceId);
                        /*re-enqueue the preempted job*/
                        (void)NvM_JobEnqueue(NvM_CurRunning.BlockId, NvM_CurRunning.ServiceId, NvM_CurRunning.RamAddr);
                    }
#endif
                    if ((uint8)STD_OFF == SYNCMECHANISM)
                    {
                        /*req NVM803*/
                        NvM_SetWordBitState(&NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_RAM_VALID, STD_ON);
                        NvM_SetWordBitState(&NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_RAM_CHANGED, STD_ON);
                    }
                }
            }
        }
    }
    return l_ReturnValue;
}
#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"
/*
 * Brief               Service to restore the default data to its corresponding RAM block
 * ServiceId           0x08
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      BlockId: The block identifier uniquely identifies one
 * NVRAM block descriptor.
 *                               A NVRAM block descriptor contains all needed
 *                               information about a single NVRAM block.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              E_OK: request has been accepted
 *                     E_NOT_OK: request has not been accepted
 * PreCondition        None
 * CallByAPI           Up layer
 */
/* req NVM027 NVM191 NVM409 */
FUNC(Std_ReturnType, NVM_CODE) NvM_RestoreBlockDefaults(NvM_BlockIdType BlockId, void* NvM_DestPtr)
{
    Std_ReturnType l_ReturnValue = E_NOT_OK;
    uint8 SYNCMECHANISM;
    uint8 ENQUEUE;

#if (STD_ON == NVM_DEV_ERROR_DETECT)
    if ((uint8)STD_ON != NvM_Module.Init)
    {
        NVM_DET_REPORTERROR((uint8)NVM_RESTORE_BLOCK_DEFAULTS_SERV_ID, NVM_E_UNINIT);
    }
    else if (((uint16)NVM_BLOCK_NUM_ALL < BlockId) || (0U == BlockId))
    {
        NVM_DET_REPORTERROR((uint8)NVM_RESTORE_BLOCK_DEFAULTS_SERV_ID, NVM_E_PARAM_BLOCK_ID);
    }
    else
#endif
    {
        SYNCMECHANISM =
            NvM_GetWordBitState(NvM_BlockDescriptor[BlockId - 1U].FlagGroup, (uint8)NVM_BLOCK_DESC_SYNCMECHANISM);
        ENQUEUE = NvM_GetWordBitState(NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_ENQUEUE);
        if (((NULL_PTR == NvM_DestPtr)
             && ((NULL_PTR == NvM_BlockDescriptor[BlockId - 1U].NvmRamBlockDataAddress)
                 && ((uint8)STD_OFF == SYNCMECHANISM))))
        {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
            NVM_DET_REPORTERROR((uint8)NVM_RESTORE_BLOCK_DEFAULTS_SERV_ID, NVM_E_PARAM_ADDRESS);
#endif
        }
        else if (
            (NULL_PTR == NvM_BlockDescriptor[BlockId - 1U].NvmRomBlockDataAddress)
            && (NULL_PTR == NvM_BlockDescriptor[BlockId - 1U].NvmInitBlockCallback))
        {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
            NVM_DET_REPORTERROR((uint8)NVM_RESTORE_BLOCK_DEFAULTS_SERV_ID, NVM_E_BLOCK_CONFIG);
            NVM_DET_REPORTERROR((uint8)NVM_RESTORE_BLOCK_DEFAULTS_SERV_ID, NVM_E_BLOCK_WITHOUT_DEFAULTS);
#endif
        }
        else if ((uint8)STD_ON == ENQUEUE)
        {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
            NVM_DET_REPORTERROR((uint8)NVM_RESTORE_BLOCK_DEFAULTS_SERV_ID, NVM_E_BLOCK_PENDING);
#endif
        }
        else
        {
            if ((((NVM_BLOCK_DATASET == NvM_BlockDescriptor[BlockId - 1U].NvmBlockManagementType)
                  && (NvM_AdminBlock[BlockId - 1U].CurrentIndex
                      < (NvM_BlockDescriptor[BlockId - 1U].NvmNvBlockNum
                         + NvM_BlockDescriptor[BlockId - 1U].NvmRomBlockNum))
                  && (NvM_BlockDescriptor[BlockId - 1U].NvmNvBlockNum <= NvM_AdminBlock[BlockId - 1U].CurrentIndex))
                 || (NVM_BLOCK_DATASET != NvM_BlockDescriptor[BlockId - 1U].NvmBlockManagementType))
                && ((NULL_PTR != NvM_BlockDescriptor[BlockId - 1U].NvmRomBlockDataAddress)
                    || (NULL_PTR != NvM_BlockDescriptor[BlockId - 1U].NvmInitBlockCallback)))
            {
                l_ReturnValue = NvM_JobEnqueue(BlockId, NVM_RESTORE_BLOCK_DEFAULTS_SERV_ID, (uint8*)NvM_DestPtr);
                /* req NVM195 */
                if ((Std_ReturnType)E_OK == l_ReturnValue)
                {
                    if (((NvM_DestPtr == NvM_BlockDescriptor[BlockId - 1U].NvmRamBlockDataAddress)
                         && (NULL_PTR != NvM_DestPtr))
                        || ((NULL_PTR == NvM_DestPtr)
                            && ((NULL_PTR != NvM_BlockDescriptor[BlockId - 1U].NvmRamBlockDataAddress)
                                || ((uint8)STD_ON == SYNCMECHANISM))))
                    {
                        NvM_SetWordBitState(&NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_RAM_VALID, STD_OFF);
                        /*req 227*/
                        NvM_SetWordBitState(&NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_RAM_CHANGED, STD_OFF);
                    }
                }
            }
        }
    }
    return l_ReturnValue;
    /*please ref state diagram to complete this func*/
}
#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"
/*
 * Brief               Service to restore the default data to its
 * corresponding Penmanent RAM block
 * ServiceId           0x18
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      BlockId: The block identifier uniquely identifies
 *  one NVRAM block descriptor.
 *                               A NVRAM block descriptor contains all
 *                               needed information about a single NVRAM block.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              E_OK: request has been accepted
 *                     E_NOT_OK: request has not been accepted
 * PreCondition        None
 * CallByAPI           Up layer
 */
/* req NVM027 NVM191 NVM409 */
FUNC(Std_ReturnType, NVM_CODE) NvM_RestorePRAMBlockDefaults(NvM_BlockIdType BlockId)
{
    Std_ReturnType l_ReturnValue = E_NOT_OK;
    uint8 SYNCMECHANISM;
    uint8 ENQUEUE;

#if (STD_ON == NVM_DEV_ERROR_DETECT)
    if ((uint8)STD_ON != NvM_Module.Init)
    {
        NVM_DET_REPORTERROR((uint8)NVM_RESTORE_PRAM_BLOCK_DEFAULTS_SERV_ID, NVM_E_UNINIT);
    }
    else if (((uint16)NVM_BLOCK_NUM_ALL < BlockId) || (0U == BlockId))
    {
        NVM_DET_REPORTERROR((uint8)NVM_RESTORE_PRAM_BLOCK_DEFAULTS_SERV_ID, NVM_E_PARAM_BLOCK_ID);
    }
    else
#endif
    {
        SYNCMECHANISM =
            NvM_GetWordBitState(NvM_BlockDescriptor[BlockId - 1U].FlagGroup, (uint8)NVM_BLOCK_DESC_SYNCMECHANISM);
        ENQUEUE = NvM_GetWordBitState(NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_ENQUEUE);
        if ((NULL_PTR == NvM_BlockDescriptor[BlockId - 1U].NvmRamBlockDataAddress) && ((uint8)STD_OFF == SYNCMECHANISM))
        {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
            NVM_DET_REPORTERROR((uint8)NVM_RESTORE_PRAM_BLOCK_DEFAULTS_SERV_ID, NVM_E_PARAM_ADDRESS);
#endif
        }
        else if (
            (NULL_PTR == NvM_BlockDescriptor[BlockId - 1U].NvmRomBlockDataAddress)
            && (NULL_PTR == NvM_BlockDescriptor[BlockId - 1U].NvmInitBlockCallback))
        {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
            /*req 886*/
            NVM_DET_REPORTERROR((uint8)NVM_RESTORE_PRAM_BLOCK_DEFAULTS_SERV_ID, NVM_E_BLOCK_CONFIG);
            NVM_DET_REPORTERROR((uint8)NVM_RESTORE_PRAM_BLOCK_DEFAULTS_SERV_ID, NVM_E_BLOCK_WITHOUT_DEFAULTS);
#endif
        }
        else if ((uint8)STD_ON == ENQUEUE)
        {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
            NVM_DET_REPORTERROR((uint8)NVM_RESTORE_PRAM_BLOCK_DEFAULTS_SERV_ID, NVM_E_BLOCK_PENDING);
#endif
        }
        else
        {
            if (((NVM_BLOCK_DATASET == NvM_BlockDescriptor[BlockId - 1U].NvmBlockManagementType)
                 && ((NvM_AdminBlock[BlockId - 1U].CurrentIndex
                      < (NvM_BlockDescriptor[BlockId - 1U].NvmNvBlockNum
                         + NvM_BlockDescriptor[BlockId - 1U].NvmRomBlockNum))
                     && (NvM_BlockDescriptor[BlockId - 1U].NvmNvBlockNum <= NvM_AdminBlock[BlockId - 1U].CurrentIndex)))
                || ((NULL_PTR != NvM_BlockDescriptor[BlockId - 1U].NvmRomBlockDataAddress)
                    || (NULL_PTR != NvM_BlockDescriptor[BlockId - 1U].NvmInitBlockCallback)))
            {
                /* req NVM195 */
                l_ReturnValue = NvM_JobEnqueue(BlockId, NVM_RESTORE_PRAM_BLOCK_DEFAULTS_SERV_ID, NULL_PTR);
                if ((Std_ReturnType)E_OK == l_ReturnValue)
                {
                    /*req 819*/
                    NvM_SetWordBitState(&NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_RAM_VALID, STD_OFF);
                    NvM_SetWordBitState(&NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_RAM_CHANGED, STD_OFF);
                }
            }
        }
    }
    return l_ReturnValue;
    /*please ref state diagram to complete this func*/
}
#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"
/*
 * Brief               Initiates a multi block validation request
 * ServiceId           0x19
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition
 * CallByAPI           Up layer
 */
FUNC(void, NVM_CODE) NvM_ValidateAll(void)
{
#if (STD_ON == NVM_DEV_ERROR_DETECT)
    if ((uint8)STD_ON != NvM_Module.Init)
    {
        NVM_DET_REPORTERROR((uint8)NVM_VALIDATE_ALL_SERV_ID, NVM_E_UNINIT);
    }
    else
#endif
    {
        if ((uint8)STD_ON != NvM_MultiJob.Enqueue)
        {
            if ((Std_ReturnType)E_NOT_OK == NvM_JobEnqueue(0, NVM_VALIDATE_ALL_SERV_ID, NULL_PTR))
            {
                /*This will not happen*/
            }
        }
        else
        {
            NVM_DET_REPORTRUNTIMEERROR((uint8)NVM_VALIDATE_ALL_SERV_ID, NVM_E_QUEUE_FULL);
        }
    }
}
#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"
/*
 * Brief               Service for getting the currently set
 * DataIndex of a dataset NVRAM block
 * ServiceId           0x10
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      BlockId: The block identifier uniquely identifies
 * one NVRAM block descriptor.
 *                               A NVRAM block descriptor contains all
 *                               needed information about a single NVRAM block.
 * Param-Name[out]     DataIndexPtr: Pointer to where to store the
 * current dataset index (0..255)
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
FUNC(Std_ReturnType, NVM_CODE) NvM_CancelJobs(NvM_BlockIdType BlockId)
{
    Std_ReturnType l_ReturnValue = E_NOT_OK;
    uint8 ENQUEUE;

#if (STD_ON == NVM_DEV_ERROR_DETECT)
    if ((uint8)STD_ON != NvM_Module.Init)
    {
        NVM_DET_REPORTERROR((uint8)NVM_CANCEL_JOBS_SERV_ID, NVM_E_UNINIT); /* req NVM648 */
    }
    else if (((uint16)NVM_BLOCK_NUM_ALL < BlockId) || (0U == BlockId))
    {
        NVM_DET_REPORTERROR((uint8)NVM_CANCEL_JOBS_SERV_ID, NVM_E_PARAM_BLOCK_ID); /* req NVM649 */
    }
    else
#endif
    {
        ENQUEUE = NvM_GetWordBitState(NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_ENQUEUE);
        if ((uint8)STD_ON == ENQUEUE)
        {

            if ((Std_ReturnType)E_OK == NvM_CancelJobInQueue(BlockId))
            {
                l_ReturnValue = E_OK;
            }
        }
    }
    return l_ReturnValue;
}
#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"
static FUNC(Std_ReturnType, NVM_CODE) NvM_CancelJobInQueue(NvM_BlockIdType BlockId)
{
    Std_ReturnType ret;
    Std_ReturnType Normalret;
#if (STD_ON == NVM_JOB_PRIORITIZATION)
    Std_ReturnType Immedret;
    volatile NvM_JobTypeType l_JobType = NVM_JOB_TYPE_NONE;
    volatile uint8 l_JobPri = 0xFFu;
    l_JobPri = NvM_BlockDescriptor[BlockId - 1U].NvmBlockJobPriority;

    if ((0U == l_JobPri)
        && ((NVM_WRITE_PRAM_BLOCK_SERV_ID == NvM_AdminBlock[BlockId - 1U].ServiceID)
            || (NVM_WRITE_BLOCK_SERV_ID == NvM_AdminBlock[BlockId - 1U].ServiceID)))
    {
        l_JobType = NVM_JOB_TYPE_SINGLE_IMMED;
    }
    else
    {
        l_JobType = NVM_JOB_TYPE_SINGLE_NORMAL;
    }
    Immedret = NvM_ImmedQueueSort(BlockId);
    Normalret = NvM_NormalQueueSort(BlockId);
    if ((l_JobType == NVM_JOB_TYPE_SINGLE_IMMED) && ((Std_ReturnType)E_OK == Immedret))
    {
        NvM_SetWordBitState(&NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_ENQUEUE, STD_OFF);
        if (BlockId != NvM_CurRunning.BlockId)
        {
            NvM_AdminBlock[BlockId - 1U].SingleReqResult = NVM_REQ_CANCELED;
        }
        ret = E_OK;
    }
    else if ((l_JobType == NVM_JOB_TYPE_SINGLE_NORMAL) && ((Std_ReturnType)E_OK == Normalret))
#else
    Normalret = NvM_NormalQueueSort(BlockId);
    if ((Std_ReturnType)E_OK == Normalret)
#endif
    {
        NvM_SetWordBitState(&NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_ENQUEUE, STD_OFF);
        if (BlockId != NvM_CurRunning.BlockId)
        {
            NvM_AdminBlock[BlockId - 1U].SingleReqResult = NVM_REQ_CANCELED;
        }
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }
    return ret;
}

#if (STD_OFF == NVM_JOB_PRIORITIZATION)
static FUNC(Std_ReturnType, NVM_CODE) NvM_NormalQueueSort(NvM_BlockIdType BlockId)
{
    uint8 l_Preindex = 0;
    uint8 l_Curindex = 0;
    uint8 l_BlockIdIndex = 0;
    uint8 l_QueueCounter = 0;
    Std_ReturnType ret = E_OK;
    uint8 l_BlockFind = FALSE;

    for (; l_Curindex < NVM_SIZE_STANDARD_JOB_QUEUE; l_Curindex++)
    {
        if (NvM_StandQueue[l_Curindex].BlockId == BlockId)
        {
            l_BlockIdIndex = l_Curindex;
            break;
        }
    }

    if (NVM_SIZE_STANDARD_JOB_QUEUE <= l_Curindex)
    {
        /*No blockID in the NvM_StandQueue,Clear the Queue*/
        NvM_SetWordBitState(&NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_ENQUEUE, STD_OFF);
        /*Should not change the Block request result of the block that currently in progress */
        if (BlockId != NvM_CurRunning.BlockId)
        {
            NvM_AdminBlock[BlockId - 1U].SingleReqResult = NVM_REQ_CANCELED;
        }
        ret = E_NOT_OK;
    }
    else
    {
        /*This block takes the last position in the NvM_ImmedQueueManage */
        if (((0 != NvM_StandQueueManage.TailIndex) && (l_BlockIdIndex == (NvM_StandQueueManage.TailIndex - 1)))
            || ((0 == NvM_StandQueueManage.TailIndex) && (l_BlockIdIndex == (NVM_SIZE_STANDARD_JOB_QUEUE - 1))))
        {
            NvM_StandQueueManage.Count--;
            if (0U < l_BlockIdIndex)
            {
                NvM_StandQueueManage.TailIndex = l_BlockIdIndex;
            }
            else
            {
                NvM_StandQueueManage.TailIndex = 0U;
            }
        }
        /*This block takes the middle or fist position of the NvM_ImmedQueueManage */
        else
        {
            /*Find the position of the block among the NvM_StandQueueManage.Count*/
            l_Curindex = NvM_StandQueueManage.HeadIndex;
            for (; l_QueueCounter < NvM_StandQueueManage.Count; l_QueueCounter++)
            {
                if (NvM_StandQueue[l_Curindex].BlockId == BlockId)
                {
                    l_Preindex = l_Curindex;
                    NvM_StandQueueManage.Count--;
                    l_BlockFind = TRUE;
                    break;
                }
                l_Curindex++;
                if (NVM_SIZE_STANDARD_JOB_QUEUE <= l_Curindex)
                {
                    l_Curindex = 0;
                }
            }
            if (l_BlockFind == TRUE)
            {
                /*Move forward*/
                for (; l_QueueCounter < NvM_StandQueueManage.Count; l_QueueCounter++)
                {
                    l_Curindex++;
                    if (NVM_SIZE_STANDARD_JOB_QUEUE <= l_Curindex)
                    {
                        l_Curindex = 0;
                    }
                    NvM_StandQueue[l_Preindex].BlockId = NvM_StandQueue[l_Curindex].BlockId;
                    NvM_StandQueue[l_Preindex].ServiceId = NvM_StandQueue[l_Curindex].ServiceId;
                    NvM_StandQueue[l_Preindex].DestSrcPtr = NvM_StandQueue[l_Curindex].DestSrcPtr;
                    l_Preindex = l_Curindex;
                }
                if (0u == NvM_StandQueueManage.TailIndex)
                {
                    NvM_StandQueueManage.TailIndex = NVM_SIZE_STANDARD_JOB_QUEUE - 1;
                }
                else
                {
                    NvM_StandQueueManage.TailIndex--;
                }
            }
            else
            {
                ret = E_NOT_OK;
            }
        }
    }
    return ret;
}
#endif

#if (STD_ON == NVM_JOB_PRIORITIZATION)
static FUNC(Std_ReturnType, NVM_CODE) NvM_NormalQueueSort(NvM_BlockIdType BlockId)
{
    uint8 l_JobPri;
    uint8 l_Preindex;
    uint8 l_Curindex = 0;
    uint8 l_BlockIdIndex;
    uint8 l_QueueCounter = 0;
    uint8 l_CurActPriTable;
    Std_ReturnType ret = E_OK;
    boolean FirstLoop = TRUE;

    l_CurActPriTable = NvM_Module.CurActPriTable;
    l_JobPri = NvM_BlockDescriptor[BlockId - 1U].NvmBlockJobPriority;

    for (; l_Curindex < NVM_SIZE_STANDARD_JOB_QUEUE; l_Curindex++)
    {
        if (NvM_StandQueue[l_Curindex].BlockId == BlockId)
        {
            l_BlockIdIndex = l_Curindex;
            break;
        }
    }
    if (NVM_SIZE_STANDARD_JOB_QUEUE <= l_Curindex)
    {
        /*No blockID in the NvM_StandQueue,Clear the Queue*/
        NvM_SetWordBitState(&NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_ENQUEUE, STD_OFF);
        NvM_AdminBlock[BlockId - 1U].SingleReqResult = NVM_REQ_CANCELED;
        ret = E_NOT_OK;
    }
    else
    {
        /*Find the blockID before this block*/
        if (l_BlockIdIndex == NvM_PriTable2Queue[l_CurActPriTable][l_JobPri].HeadIndex)
        {
            /*Only task for this priority*/
            if (NvM_StandQueue[l_BlockIdIndex].NextIndex == l_BlockIdIndex)
            {
                /* This is the last element, clear priority table flag */
                NvM_PriorityTable[l_CurActPriTable][((l_JobPri & 0xF0U) >> 4u)] &=
                    (uint16)(~(uint16)((uint16)0x01u << (l_JobPri & 0x0FU)));
                if (0U == NvM_PriorityTable[l_CurActPriTable][((l_JobPri & 0xF0U) >> 4u)])
                {
                    NvM_PriorityTable[l_CurActPriTable][NVM_TABLE_SIZE_PRIORITY - 1U] &=
                        (uint16)(~(uint16)((uint16)0x01u << (l_JobPri & 0xF0U)));
                }
            }
            else
            {
                /* Shift the first position to the next task*/
                NvM_PriTable2Queue[l_CurActPriTable][l_JobPri].HeadIndex = NvM_StandQueue[l_BlockIdIndex].NextIndex;
                NvM_StandQueue[l_BlockIdIndex].NextIndex = l_BlockIdIndex;
            }
        }
        /*More than one task for this priority or l_CurActPriTable is Another*/
        else
        {
            /*More than one task for this priority*/
            l_Curindex = NvM_StandQueue[NvM_PriTable2Queue[l_CurActPriTable][l_JobPri].HeadIndex].NextIndex;
            l_Preindex = l_Curindex;
            while ((l_Curindex != l_BlockIdIndex) && (ret == E_OK))
            {
                l_QueueCounter++;
                if (l_QueueCounter > NVM_SIZE_STANDARD_JOB_QUEUE)
                {
                    /* switch the current active priority table ,l_CurActPriTable shall only be 0 and 1*/
                    l_CurActPriTable = 1u - l_CurActPriTable;
                    l_Curindex = NvM_StandQueue[NvM_PriTable2Queue[l_CurActPriTable][l_JobPri].HeadIndex].NextIndex;
                    if (FirstLoop == FALSE)
                    {
                        /*No blockID in the NvM_StandQueue,Clear the Queue*/
                        NvM_SetWordBitState(&NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_ENQUEUE, STD_OFF);
                        NvM_AdminBlock[BlockId - 1U].SingleReqResult = NVM_REQ_CANCELED;
                        ret = E_NOT_OK;
                    }
                    l_QueueCounter = 0;
                    FirstLoop = FALSE;
                }
                else
                {
                    l_Preindex = l_Curindex;
                    l_Curindex = NvM_StandQueue[l_Preindex].NextIndex;
                }
            }
            if (ret == E_OK)
            {
                if (NvM_StandQueue[l_BlockIdIndex].NextIndex == l_BlockIdIndex)
                {
                    /*This block is the last task for this priority */
                    NvM_StandQueue[l_Preindex].NextIndex = l_Preindex;
                    NvM_PriTable2Queue[l_CurActPriTable][l_JobPri].TailIndex = l_Preindex;
                }
                else if (l_BlockIdIndex == l_Preindex)
                {
                    if (l_BlockIdIndex == NvM_PriTable2Queue[l_CurActPriTable][l_JobPri].TailIndex)
                    {
                        NvM_StandQueue[NvM_PriTable2Queue[l_CurActPriTable][l_JobPri].HeadIndex].NextIndex =
                            NvM_PriTable2Queue[l_CurActPriTable][l_JobPri].HeadIndex;
                        NvM_PriTable2Queue[l_CurActPriTable][l_JobPri].TailIndex =
                            NvM_PriTable2Queue[l_CurActPriTable][l_JobPri].HeadIndex;
                    }
                    else
                    {
                        NvM_StandQueue[NvM_PriTable2Queue[l_CurActPriTable][l_JobPri].HeadIndex].NextIndex =
                            NvM_StandQueue[l_BlockIdIndex].NextIndex;
                    }
                    NvM_StandQueue[l_BlockIdIndex].NextIndex = l_BlockIdIndex;
                }
                else
                {
                    NvM_StandQueue[l_Preindex].NextIndex = NvM_StandQueue[l_BlockIdIndex].NextIndex;
                    NvM_StandQueue[l_BlockIdIndex].NextIndex = l_BlockIdIndex;
                }
            }
        }
        if (ret == E_OK)
        {
            /*Clear the bit in NvM_QueueSpaceTalbe*/
            NvM_QueueSpaceTalbe[NVM_TABLE_SIZE_JOB_QUEUE - 1U] |=
                (uint16)((uint16)0x01U << ((l_BlockIdIndex & 0xF0U) >> 4U));
            NvM_QueueSpaceTalbe[((l_BlockIdIndex & 0xF0U) >> 4u)] |=
                /* PRQA S 2985++ */ /* MISRA Rule 2.2 */
                (uint16)((uint16)0x01U << (l_BlockIdIndex & 0x0FU));
            /* PRQA S 2985-- */     /* MISRA Rule 2.2 */
        }
    }
    return ret;
}

static FUNC(Std_ReturnType, NVM_CODE) NvM_ImmedQueueSort(NvM_BlockIdType BlockId)
{
    uint8 l_Preindex = 0;
    uint8 l_Curindex = 0;
    uint8 l_BlockIdIndex;
    uint8 l_QueueCounter = 0;
    Std_ReturnType ret = E_OK;

    for (; l_Curindex < NVM_SIZE_IMMEDIATE_JOB_QUEUE; l_Curindex++)
    {
        if (NvM_ImmedQueue[l_Curindex].BlockId == BlockId)
        {
            l_BlockIdIndex = l_Curindex;
            break;
        }
    }
    if (NVM_SIZE_IMMEDIATE_JOB_QUEUE == l_Curindex)
    {
        /*No blockID in the NvM_StandQueue,Clear the Queue*/
        NvM_SetWordBitState(&NvM_AdminBlock[BlockId - 1U].FlagGroup, NVM_ADMIN_ENQUEUE, STD_OFF);
        NvM_AdminBlock[BlockId - 1U].SingleReqResult = NVM_REQ_CANCELED;
        ret = E_NOT_OK;
    }
    else
    {
        /*This block takes the last position in the NvM_ImmedQueueManage */
        l_Curindex = NvM_ImmedQueueManage.HeadIndex;
        for (; l_QueueCounter < NvM_ImmedQueueManage.Count; l_QueueCounter++)
        {
            if (l_Curindex == l_BlockIdIndex)
            {
                l_Preindex = l_Curindex;
                break;
            }
            l_Curindex++;
            if (NVM_SIZE_IMMEDIATE_JOB_QUEUE <= l_Curindex)
            {
                l_Curindex = 0;
            }
        }
        if (l_BlockIdIndex == NvM_ImmedQueueManage.HeadIndex) /*First element*/
        {
            NvM_ImmedQueueManage.Count--;
            if ((NVM_SIZE_IMMEDIATE_JOB_QUEUE - 1U) <= NvM_ImmedQueueManage.HeadIndex)
            {
                NvM_ImmedQueueManage.HeadIndex = 0;
            }
            else
            {
                NvM_ImmedQueueManage.HeadIndex++;
            }
        }
        else if (l_QueueCounter == (NvM_ImmedQueueManage.Count - 1U)) /*Last element*/
        {
            NvM_ImmedQueueManage.Count--;
            if (NvM_ImmedQueueManage.TailIndex == 0U)
            {
                NvM_ImmedQueueManage.TailIndex = NvM_ImmedQueueManage.Count - 1u;
            }
            else
            {
                NvM_ImmedQueueManage.TailIndex--;
            }
        }
        else
        {
            for (; l_QueueCounter < (NvM_ImmedQueueManage.Count - 1U); l_QueueCounter++)
            {
                l_Curindex++;
                if (NVM_SIZE_IMMEDIATE_JOB_QUEUE <= l_Curindex)
                {
                    l_Curindex = 0;
                }
                NvM_ImmedQueue[l_Preindex].BlockId = NvM_ImmedQueue[l_Curindex].BlockId;
                NvM_ImmedQueue[l_Preindex].DestSrcPtr = NvM_ImmedQueue[l_Curindex].DestSrcPtr;
                l_Preindex = l_Curindex;
            }
            if (NvM_ImmedQueueManage.TailIndex == 0U)
            {
                NvM_ImmedQueueManage.TailIndex = (NvM_ImmedQueueManage.Count - 1U);
            }
            else
            {
                NvM_ImmedQueueManage.TailIndex--;
            }
            NvM_ImmedQueueManage.Count--;
        }
    }
    return ret;
}
#endif
#endif
#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"
/*
 * Brief               Service to cancel a running NvM_WriteAll request
 * ServiceId           0x0a
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        This request shall only be used by the ECU state manager
 * CallByAPI           Up layer
 */
/* req NVM027 NVM191 NVM409 */
FUNC(void, NVM_CODE) NvM_CancelWriteAll(void)
{
#if (STD_ON == NVM_DEV_ERROR_DETECT)
    if ((uint8)STD_ON != NvM_Module.Init)
    {
        NVM_DET_REPORTERROR((uint8)NVM_CANCEL_WRITE_ALL_SERV_ID, NVM_E_UNINIT);
    }
    else
#endif
    {
#if (NVM_API_CONFIG_CLASS_1 != NVM_API_CONFIG_CLASS)
        if (((uint8)STD_ON == NvM_MultiJob.Enqueue) && (NVM_WRITE_ALL_SERV_ID == NvM_MultiJob.ServiceId))
#else
        if (((uint8)STD_ON == NvM_MultiJob.Enqueue) && (NVM_WRITE_ALL_SERV_ID == NvM_CurRunning.ServiceId))
#endif
        {
            NvM_MultiJob.CancelWriteAll = STD_ON;
        }
    }
}
#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"
/*
 * Brief               Initiates a multi block read request
 * ServiceId           0x0c
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        This request may be triggered only
 * by the ECU state manager at system startup
 * CallByAPI           Up layer
 */
/* req NVM027 NVM191 NVM409 */
FUNC(void, NVM_CODE) NvM_ReadAll(void)
{
#if (STD_ON == NVM_DEV_ERROR_DETECT)
    if ((uint8)STD_ON != NvM_Module.Init)
    {
        NVM_DET_REPORTERROR((uint8)NVM_READ_ALL_SERV_ID, NVM_E_UNINIT);
    }
    else
#endif
    {
        if ((uint8)STD_ON != NvM_MultiJob.Enqueue)
        {
            if ((Std_ReturnType)E_NOT_OK == NvM_JobEnqueue(0, NVM_READ_ALL_SERV_ID, NULL_PTR))
            {
                /*This will not happen*/
            }
        }
        else
        {
            NVM_DET_REPORTRUNTIMEERROR((uint8)NVM_READ_ALL_SERV_ID, NVM_E_QUEUE_FULL);
        }
    }
}
#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"
/*
 * Brief               Initiates a multi block write request
 * ServiceId           0x0d
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      BlockId: The block identifier uniquely identifies
 *  one NVRAM block descriptor.
 *                               A NVRAM block descriptor contains all
 *                                needed information about a single NVRAM block.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        This request must only be triggered by
 * the ECU state manager at shutdown of the system
 * CallByAPI           Up layer
 */
/* req NVM027 NVM191 NVM409 */
FUNC(void, NVM_CODE) NvM_WriteAll(void)
{
    uint16 l_BlockIdLoop;
    boolean flag = FALSE;
    uint8 WRITEBLOCKONCE;
#if (STD_ON == NVM_DEV_ERROR_DETECT)
    if ((uint8)STD_ON != NvM_Module.Init)
    {
        NVM_DET_REPORTERROR((uint8)NVM_WRITE_ALL_SERV_ID, NVM_E_UNINIT);
    }
    else
#endif
    {
        for (l_BlockIdLoop = 0; ((l_BlockIdLoop < (uint16)NVM_BLOCK_NUM_ALL) && (flag == FALSE)); l_BlockIdLoop++)
        {
            WRITEBLOCKONCE =
                NvM_GetWordBitState(NvM_BlockDescriptor[l_BlockIdLoop].FlagGroup, (uint8)NVM_BLOCK_DESC_WRITEBLOCKONCE);
            if (((uint8)STD_ON == WRITEBLOCKONCE) && (NvM_AdminBlock[l_BlockIdLoop].ReadReq == FALSE))
            {
#if (STD_ON == NVM_DEV_ERROR_DETECT)
                NVM_DET_REPORTERROR((uint8)NVM_WRITE_ALL_SERV_ID, NVM_E_WRITE_ONCE_STATUS_UNKNOWN); /* req NVM952 */
#endif
                flag = TRUE;
            }
        }
        if (flag == FALSE)
        {
            if ((uint8)STD_ON != NvM_MultiJob.Enqueue)
            {
                if ((Std_ReturnType)E_OK == NvM_JobEnqueue(0, NVM_WRITE_ALL_SERV_ID, NULL_PTR))
                {
                    /*Nothing*/
                }
            }
            else
            {
                NVM_DET_REPORTRUNTIMEERROR((uint8)NVM_WRITE_ALL_SERV_ID, NVM_E_QUEUE_FULL);
            }
        }
    }
}
#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"
/*
 * Brief               Service for performing the processing of the NvM jobs
 * ServiceId           0x0e
 * Timing              VARIABLE_CYCLIC
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           OS
 */
FUNC(void, NVM_CODE) NvM_MainFunction(void)
{
    static CONST(NvM_VoidFuncVoidPtr, NVM_CONST) NvM_InterServFuncMatrix[] = {
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
#if (STD_ON == NVM_SET_RAM_BLOCK_STATUS_API)
        &NvM_InterSetRamStatus,
#else
        NULL_PTR,
#endif
        &NvM_InterReadBlock,
        &NvM_InterWriteBlock,
#if (NVM_API_CONFIG_CLASS_1 != NVM_API_CONFIG_CLASS)
        &NvM_InterRestoreBlockDefaults,
#else
        NULL_PTR,
#endif
#if ((NVM_API_CONFIG_CLASS_3 == NVM_API_CONFIG_CLASS) && (STD_ON == NVM_JOB_PRIORITIZATION))
        &NvM_InterEraseNvBlock,
#else
        NULL_PTR,
#endif
        NULL_PTR,
#if (NVM_API_CONFIG_CLASS_3 == NVM_API_CONFIG_CLASS)
        &NvM_InterInvalidateNvBlock,
#else
        NULL_PTR,
#endif
        &NvM_InterReadAll,
        &NvM_InterWriteAll,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        &NvM_InterReadBlock,
        &NvM_InterWriteBlock,
#if (NVM_API_CONFIG_CLASS_1 != NVM_API_CONFIG_CLASS)
        &NvM_InterRestoreBlockDefaults,
        &NvM_InterValidateAll,
#else
        NULL_PTR,
        NULL_PTR
#endif
    };

    static CONST(NvM_VoidFuncVoidPtr, NVM_CONST) NvM_AtomJobFuncMatrix[] =
        {&NvM_InterReadBlock, &NvM_InterWriteBlock, &NvM_InterReadRom, &NvM_InterCalcCrc, &NvM_InterWriteVerification};

    if ((uint8)STD_ON == NvM_Module.Init)
    {
        /*Check whether finished the previous task*/
        if (NVM_JOB_STEP_IDLE == NvM_Module.JobStep)
        {
            if ((Std_ReturnType)E_OK == NvM_JobDequeue())
            {
                NvM_Module.JobStep = NVM_JOB_STEP_PENDING;
                /*ServiceID overflow, return to the NVM_JOB_STEP_IDLE*/
                if (NVM_NONE_SERV_ID <= NvM_CurRunning.ServiceId)
                {
                    NvM_Module.JobStep = NVM_JOB_STEP_IDLE;
                }
            }
        }

        if ((NVM_JOB_STEP_IDLE != NvM_Module.JobStep) && (0U == NvM_AtomJob.Count))
        {
            (*NvM_InterServFuncMatrix[NvM_CurRunning.ServiceId])();
        }

        if (0U != NvM_AtomJob.Count)
        {

            (*NvM_AtomJobFuncMatrix[NvM_AtomJob.ReqId[NvM_AtomJob.Count]])();

            if ((NVM_JOB_STEP_IDLE == NvM_Module.JobStep) && (NVM_JOB_TYPE_MULTI == NvM_Module.CurrentJobType)
                && (NVM_REQ_OK != NvM_AdminBlock[NvM_CurRunning.BlockId - 1U].SingleReqResult)
                && (NVM_REQ_BLOCK_SKIPPED != NvM_AdminBlock[NvM_CurRunning.BlockId - 1U].SingleReqResult))
            {
#if ((NVM_API_CONFIG_CLASS_1 == NVM_API_CONFIG_CLASS) || (STD_OFF == NVM_JOB_PRIORITIZATION))
                if ((NvM_CurRunning.BlockId == 1U) && (NVM_READ_ALL_SERV_ID == NvM_CurRunning.ServiceId))
#else
                if ((NvM_CurRunning.BlockId == 1U) && (NVM_READ_ALL_SERV_ID == NvM_MultiJob.ServiceId))
#endif
                {
                    NvM_CurRunning.EMultiReqResult = NVM_REQ_OK;
                }

                else
                {
                    NvM_CurRunning.EMultiReqResult = NVM_REQ_NOT_OK;
                }
            }
        }
    }
}
#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

#define NVM_START_SEC_JOBENDNOTIFICATIONCALLBACK_CODE
#include "NvM_MemMap.h"
/*
 * Brief               Function to be used by the underlying memory
 * abstraction to signal end of job without error
 * ServiceId           0x11
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Underlying layer
 */
FUNC(void, NVM_CODE) NvM_JobEndNotification(void) /* PRQA S 3408 */ /* MISRA Rule 8.4 */
{
    return;
}
#define NVM_STOP_SEC_JOBENDNOTIFICATIONCALLBACK_CODE
#include "NvM_MemMap.h"

#define NVM_START_SEC_JOBERRORNOTIFICATIONCALLBACK_CODE
#include "NvM_MemMap.h"
/*
 * Brief               Function to be used by the underlying
 * memory abstraction to signal end of job with error
 * ServiceId           0x12
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Underlying layer
 */
FUNC(void, NVM_CODE) NvM_JobErrorNotification(void) /* PRQA S 3408 */ /* MISRA Rule 8.4 */
{
    return;
}
#define NVM_STOP_SEC_JOBERRORNOTIFICATIONCALLBACK_CODE
#include "NvM_MemMap.h"

/*====================[E N D  O F   F I L E]====================*/
