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
**  DESCRIPTION :function declare                                            **
**                                                                           **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                     **
**                                                                           **
**************************************************************************** */
#ifndef NVM_H
#define NVM_H

/*====================[I N C L U D E S]====================*/
#include "NvM_Types.h"
#include "NvM_Cfg.h"
/*======================[R E V I S I O N   H I S T O R Y]=====================*/
/*  <VERSION>    <DATE>    <AUTHOR>    <REVISION LOG>
 *   V1.0.0     2020/5/9    tao.yu        Create
 *   V2.0.0     2021-4-8    tao.yu      release version
 *   V2.0.1     2023-6-7    peng.wu     Fix CPT-5670:Modify the parameter type
============================================================================*/

/*===================[V E R S I O N  I N F O R M A T I O N]===================*/
#define NVM_VENDOR_ID                62U
#define NVM_MODULE_ID                20U
#define NVM_INSTANCE_ID              0U
#define NVM_AR_RELEASE_MAJOR_VERSION 4U
#define NVM_AR_RELEASE_MINOR_VERSION 5U
#define NVM_AR_RELEASE_PATCH_VERSION 0U
#define NVM_SW_MAJOR_VERSION         2U
#define NVM_SW_MINOR_VERSION         0U
#define NVM_SW_PATCH_VERSION         1U

#define NVM_DET_REPORTRUNTIMEERROR(ApiId, ErrorId) \
    ((void)Det_ReportRuntimeError(NVM_MODULE_ID, NVM_INSTANCE_ID, (ApiId), (ErrorId)))
#if (STD_ON == NVM_DEV_ERROR_DETECT)
#define NVM_DET_REPORTERROR(ApiId, ErrorId) ((void)Det_ReportError(NVM_MODULE_ID, NVM_INSTANCE_ID, (ApiId), (ErrorId)))
#endif /* STD_ON == CANTP_DEV_ERROR_DETECT */

#if (STD_ON == NVM_VERSION_INFO_API)
/*
 * Brief               This service returns the version information of
 *                     this module
 * ServiceId           0x0f
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     Versioninfo: Pointer to where to store the version
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */

#if (STD_ON == NVM_DEV_ERROR_DETECT)
#define NvM_GetVersionInfo(VersionInfo)                             \
    do                                                              \
    {                                                               \
        if (NULL_PTR == (VersionInfo))                              \
        {                                                           \
            NVM_DET_REPORTERROR(0x0Fu, NVM_E_PARAM_POINTER);        \
        }                                                           \
        else                                                        \
        {                                                           \
            (VersionInfo)->vendorID = NVM_VENDOR_ID;                \
            (VersionInfo)->moduleID = NVM_MODULE_ID;                \
            (VersionInfo)->sw_major_version = NVM_SW_MAJOR_VERSION; \
            (VersionInfo)->sw_minor_version = NVM_SW_MINOR_VERSION; \
            (VersionInfo)->sw_patch_version = NVM_SW_PATCH_VERSION; \
        }                                                           \
    } while (0)
#else
#define NvM_GetVersionInfo(VersionInfo)                         \
    do                                                          \
    {                                                           \
        (VersionInfo)->vendorID = NVM_VENDOR_ID;                \
        (VersionInfo)->moduleID = NVM_MODULE_ID;                \
        (VersionInfo)->sw_major_version = NVM_SW_MAJOR_VERSION; \
        (VersionInfo)->sw_minor_version = NVM_SW_MINOR_VERSION; \
        (VersionInfo)->sw_patch_version = NVM_SW_PATCH_VERSION; \
    } while (0)
#endif
#endif /* STD_ON == NVM_VERSION_INFO_API */

/*====================[P R O T O T Y P E S]====================*/

extern CONST(NvM_BlockDescriptorType, NVM_CONST) NvM_BlockDescriptor[NVM_BLOCK_NUM_ALL];

extern CONST(NvM_MultiBlockCallbackType, NVM_CONST) NvmMultiBlockCallback;

#if (NVM_MAX_LENGTH_CONFIGED_RAM_MIRROR > 0)

extern VAR(uint8, NVM_VAR_NOINIT) NVM_RamMirror[NVM_MAX_LENGTH_CONFIGED_RAM_MIRROR];

#endif

/*************************************************************************/
/*
 * Brief               Service for resetting all internal variables
 * ServiceId           0x00
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]   None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern FUNC(void, NVM_CODE) NvM_Init(const NvM_ConfigType* ConfigPtr);

/*************************************************************************/
/*
 * Brief               Service to cancel a running NvM_WriteAll request
 * ServiceId           0x0a
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]   None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        This request shall only be used by the ECU state manager
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern FUNC(void, NVM_CODE) NvM_CancelWriteAll(void);

/*************************************************************************/
/*
 * Brief               Initiates a multi block read request
 * ServiceId           0x0c
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      BlockId: The block identifier uniquely identifies one NVRAM block descriptor.
 *                               A NVRAM block descriptor contains all needed information about a single NVRAM block.
 * Param-Name[out]   None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        This request may be triggered only by the ECU state manager at system startup
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern FUNC(void, NVM_CODE) NvM_ReadAll(void);

/*************************************************************************/
/*
 * Brief               Initiates a multi block write request
 * ServiceId           0x0d
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      BlockId: The block identifier uniquely identifies one NVRAM block descriptor.
 *                               A NVRAM block descriptor contains all needed information about a single NVRAM block.
 * Param-Name[out]   None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        This request must only be triggered by the ECU state manager at shutdown of the system
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern FUNC(void, NVM_CODE) NvM_WriteAll(void);

/*************************************************************************/
/*
 * Brief               Service for performing the processing of the NvM jobs
 * ServiceId           0x0e
 * Timing              VARIABLE_CYCLIC
 * Param-Name[in]      None
 * Param-Name[out]   None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern FUNC(void, NVM_CODE) NvM_MainFunction(void);

extern FUNC(Std_ReturnType, NVM_CODE) NvM_WritePRAMBlock(NvM_BlockIdType BlockId);

extern FUNC(Std_ReturnType, NVM_CODE) NvM_RestorePRAMBlockDefaults(NvM_BlockIdType BlockId);

extern FUNC(void, NVM_CODE) NvM_SetBlockLockStatus(NvM_BlockIdType BlockId, boolean BlockLocked);

#if (NVM_API_CONFIG_CLASS_1 != NVM_API_CONFIG_CLASS)
/*************************************************************************/
/*
 * Brief               Service for setting the DataIndex of a dataset NVRAM block
 * ServiceId           0x01
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      BlockId: The block identifier uniquely identifies one NVRAM block descriptor.
 *                            A NVRAM block descriptor contains all needed information about a single NVRAM block.
 *                   DataIndex: Index position (association) of a NV/ROM block.
 * Param-Name[out]   None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern FUNC(Std_ReturnType, NVM_CODE) NvM_SetDataIndex(NvM_BlockIdType BlockId, uint8 DataIndex);

/*************************************************************************/
/*
 * Brief               Service for getting the currently set DataIndex of a dataset NVRAM block
 * ServiceId           0x02
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      BlockId: The block identifier uniquely identifies one NVRAM block descriptor.
 *                               A NVRAM block descriptor contains all needed information about a single NVRAM block.
 * Param-Name[out]   DataIndexPtr: Pointer to where to store the current dataset index (0..255)
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
extern FUNC(Std_ReturnType, NVM_CODE)
    NvM_GetDataIndex(NvM_BlockIdType BlockId, P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) DataIndexPtr);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

/*************************************************************************/
/*
 * Brief               Service to copy the data of the NV block to its corresponding permanent RAM block
 * ServiceId           0x16
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      BlockId: The block identifier uniquely identifies one NVRAM block descriptor.
 *                               A NVRAM block descriptor contains all needed information about a single NVRAM block.
 * Param-Name[in/out]  None
 * Return              E_OK: request has been accepted
 *                     E_NOT_OK: request has not been accepted
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern FUNC(Std_ReturnType, NVM_CODE) NvM_ReadPRAMBlock(NvM_BlockIdType BlockId);

/*************************************************************************/
/*
 * Brief               Service to copy the data of the NV block to its corresponding RAM block
 * ServiceId           0x06
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      BlockId: The block identifier uniquely identifies one NVRAM block descriptor.
 *                               A NVRAM block descriptor contains all needed information about a single NVRAM block.
 * Param-Name[out]   NvM_DstPtr: Pointer to the RAM data block
 * Param-Name[in/out]  None
 * Return              E_OK: request has been accepted
 *                   E_NOT_OK: request has not been accepted
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern FUNC(Std_ReturnType, NVM_CODE) NvM_ReadBlock(NvM_BlockIdType BlockId, void* NvM_DstPtr);

/*************************************************************************/
/*
 * Brief               Service to copy the data of the RAM block to its corresponding NV block
 * ServiceId           0x07
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      BlockId: The block identifier uniquely identifies one NVRAM block descriptor.
 *                               A NVRAM block descriptor contains all needed information about a single NVRAM block.
 *                   NvM_SrcPtr: Pointer to the RAM data block
 * Param-Name[out]   None
 * Param-Name[in/out]  None
 * Return              E_OK: request has been accepted
 *                   E_NOT_OK: request has not been accepted
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern FUNC(Std_ReturnType, NVM_CODE) NvM_WriteBlock(NvM_BlockIdType BlockId, const void* NvM_SrcPtr);

/*************************************************************************/
/*
 * Brief               Service to restore the default data to its corresponding RAM block
 * ServiceId           0x08
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      BlockId: The block identifier uniquely identifies one NVRAM block descriptor.
 *                               A NVRAM block descriptor contains all needed information about a single NVRAM block.
 * Param-Name[out]   None
 * Param-Name[in/out]  None
 * Return              E_OK: request has been accepted
 *                   E_NOT_OK: request has not been accepted
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern FUNC(Std_ReturnType, NVM_CODE) NvM_RestoreBlockDefaults(NvM_BlockIdType BlockId, void* NvM_DestPtr);

/*************************************************************************/
/*
 * Brief               Service to read the block dependent error/status information
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      BlockId: The block identifier uniquely identifies one NVRAM block descriptor.
 *                               A NVRAM block descriptor contains all needed information about a single NVRAM block.
 * Param-Name[out]   RequestResultPtr: Pointer to where to store the request result
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern FUNC(Std_ReturnType, NVM_CODE)
    NvM_GetErrorStatus(NvM_BlockIdType BlockId, NvM_RequestResultType* RequestResultPtr);

/*************************************************************************/
/*
 * Brief               Service for getting the currently set DataIndex of a dataset NVRAM block
 * ServiceId           0x10
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      BlockId: The block identifier uniquely identifies one NVRAM block descriptor.
 *                               A NVRAM block descriptor contains all needed information about a single NVRAM block.
 * Param-Name[out]     DataIndexPtr: Pointer to where to store the current dataset index (0..255)
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern FUNC(Std_ReturnType, NVM_CODE) NvM_CancelJobs(NvM_BlockIdType BlockId);

/*************************************************************************/
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
/*************************************************************************/
extern FUNC(void, NVM_CODE) NvM_ValidateAll(void);

#if (STD_ON == NVM_SET_RAM_BLOCK_STATUS_API)
/*************************************************************************/
/*
 * Brief               Service for setting the RAM block status of an NVRAM block
 * ServiceId           0x05
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      BlockId: The block identifier uniquely identifies one NVRAM block descriptor.
 *                               A NVRAM block descriptor contains all needed information about a single NVRAM block.
 *                   BlockChanged: TRUE: Validate the RAM block and mark block as changed
 *                                 FALSE: Invalidate the RAM block and mark block as unchanged
 * Param-Name[out]   None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern FUNC(Std_ReturnType, NVM_CODE) NvM_SetRamBlockStatus(NvM_BlockIdType BlockId, boolean BlockChanged);

#endif
#endif

#if (NVM_API_CONFIG_CLASS_3 == NVM_API_CONFIG_CLASS)
/*************************************************************************/
/*
 * Brief               Service for setting/resetting the write protection for a NV block
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      BlockId: The block identifier uniquely identifies one NVRAM block descriptor.
 *                               A NVRAM block descriptor contains all needed information about a single NVRAM block.
 *                   ProtectionEnabled: TRUE: Write protection shall be enabled
 *                                      FALSE: Write protection shall be disabled
 * Param-Name[out]   None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern FUNC(Std_ReturnType, NVM_CODE) NvM_SetBlockProtection(NvM_BlockIdType BlockId, boolean ProtectionEnabled);

/*************************************************************************/
/*
 * Brief               Service to invalidate a NV block
 * ServiceId           0x0b
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      BlockId: The block identifier uniquely identifies one NVRAM block descriptor.
 *                               A NVRAM block descriptor contains all needed information about a single NVRAM block.
 * Param-Name[out]   None
 * Param-Name[in/out]  None
 * Return              E_OK: request has been accepted
 *                   E_NOT_OK: request has not been accepted
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern FUNC(Std_ReturnType, NVM_CODE) NvM_InvalidateNvBlock(NvM_BlockIdType BlockId);

#if (STD_ON == NVM_JOB_PRIORITIZATION)
/*************************************************************************/
/*
 * Brief               Service to erase a NV block
 * ServiceId           0x09
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      BlockId: The block identifier uniquely identifies one NVRAM block descriptor.
 *                               A NVRAM block descriptor contains all needed information about a single NVRAM block.
 * Param-Name[out]   None
 * Param-Name[in/out]  None
 * Return              E_OK: request has been accepted
 *                   E_NOT_OK: request has not been accepted
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern FUNC(Std_ReturnType, NVM_CODE) NvM_EraseNvBlock(NvM_BlockIdType BlockId);
#endif
#endif

#endif /* End of NVM_H*/

/*====================[E N D   O F   F I L E]====================*/
