/** *****************************************************************************************************
 * SEMIDRIVE Copyright Statement                                                                        *
 * Copyright (c) SEMIDRIVE. All rights reserved                                                         *
 *                                                                                                      *
 * This software and all rights therein are owned by SEMIDRIVE, and are                                 *
 * protected by copyright law and other relevant laws, regulations and                                  *
 * protection. Without SEMIDRIVE's prior written consent and/or related rights,                         *
 * please do not use this software or any potion thereof in any form or by any                          *
 * means. You may not reproduce, modify or distribute this software except in                           *
 * compliance with the License. Unless required by applicable law or agreed to                          *
 * in writing, software distributed under the License is distributed on                                 *
 * an 'AS IS' basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.                         *
 *                                                                                                      *
 *******************************************************************************************************/
/** *****************************************************************************************************
 *  \file     Fls.h                                                                           *
 *  \brief    This file contains interface header for FLS MCAL driver, ...                             *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/26     <td>1.0.0                               *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef FLS_H
#define FLS_H

#ifdef __cplusplus
extern "C" {
#endif /* #ifdef __cplusplus */

#include "Compiler.h"
#include "Compiler_Cfg.h"
#include "Std_Types.h"
#include "Fls_Bus.h"
#include "MemIf_Types.h"
#include "Fls_Cfg.h"
#include "Fls_IpDrv.h"

/*****************Version Information************/
#define FLS_AR_MAJOR_VERSION  4U
#define FLS_AR_MINOR_VERSION  3U
#define FLS_AR_PATCH_VERSION  1U

#define FLS_SW_MAJOR_VERSION  1U
#define FLS_SW_MINOR_VERSION  0U
#define FLS_SW_PATCH_VERSION  0U

#define FLS_SW_VENDOR (0x8Cu)

/*Service ID for DET reporting */
#define FLS_E_PARAM_CONFIG                 0x01U
#define FLS_E_PARAM_ADDRESS                0x02U
#define FLS_E_PARAM_LENGTH                 0x03U
#define FLS_E_PARAM_DATA                   0x04U
#define FLS_E_UNINIT                       0x05U
#define FLS_E_BUSY                         0x06U
#define FLS_E_VERIFY_ERASE_FAILED          0x07U
#define FLS_E_VERIFY_WRITE_FAILED          0x08U
#define FLS_E_TIMEOUT                      0x09U
#define FLS_E_PARAM_POINTER                0x0AU

/* Transient Faults ID*/
#define FLS_E_ERASE_FAILED                 0x01U
#define FLS_E_WRITE_FAILED                 0x02U
#define FLS_E_READ_FAILED                  0x03U
#define FLS_E_COMPARE_FAILED               0x04U
#define FLS_E_UNEXPECTED_FLASH_ID          0x05U
#define FLS_E_BLANK_CHECK_FAILED_ID        0x06U    /* The error code is not defined in specification*/

#define FLS_MODULE_ID         (0x5CU)

#define FLS_OFFSET_OF(type, member) (uint32)&(((type*)0)->member)
#define FLS_CONTAINER_OF(ptr, type, member) \
    ((type *)((unsigned long)(ptr) - FLS_OFFSET_OF(type, member)))

/* Service id's for fls functions */
typedef enum
{
    FLS_INIT_ID                  = 0x00U,
    FLS_ERASE_ID                 = 0x01U,
    FLS_WRITE_ID                 = 0x02U,
    FLS_CANCEL_ID                = 0x03U,
    FLS_GET_STATUS_ID            = 0x04U,
    FLS_GET_JOB_RESULT_ID        = 0x05U,
    FLS_MAIN_FUNCTION_ID         = 0x06U,
    FLS_READ_ID                  = 0x07U,
    FLS_COMPARE_ID               = 0x08U,
    FLS_SET_MODE_ID              = 0x09U,
    FLS_GET_VERSION_INFO_ID      = 0x10U,
    FLS_TIMEOUT_ID               = 0x0AU,
    FLS_BLANKCHECK_ID            = 0x0BU,
    FLS_GET_CAPACITY_ID          = 0x0CU,
    FLS_PROTECT_AREA_ID          = 0x0DU,
    FLS_RESOTRE_STATE_IF         = 0x0Fu,
    FLS_DEINIT_ID                = 0x11u,
    FLS_UNKNOW_ID                = 0xFFU,
} Fls_ServiceIdType;

/* Number of flash devices */
#define NUM_FLASH_DEVICES 1U
#define FLS_CANCEL_INDEX 1U
#define FLS_REQUESTED_CANCEL 0U
#define FLS_NOT_REQUESTED_CANCEL 1U

struct Fls_Context;
typedef struct Fls_Context Fls_ContextType;
struct Fls_SectorConfig;
typedef struct Fls_SectorConfig Fls_SectorConfigType;

typedef unsigned long int Fls_PointerType;

typedef enum
{
    FLS_OK_E               = 0x00,
    FLS_ERROR_E            = 0x01,
    FLS_ERASE_E            = 0x02,
    FLS_WRITE_E            = 0x03,
    FLS_READ_E             = 0x04,
    FLS_COMPARE_E          = 0x05,
    FLS_BUSY_E             = 0x06,
    FLS_BLANKCHECK_E       = 0x07,
    FLS_CANCEL_E           = 0x08,
    FLS_TIMEOUT_E          = 0x09,
    FLS_UNKNOW_ERROR_E     = 0xFF,
} Fls_ReturnInfoType;

typedef enum
{
    FLS_IDLE_E             = 0x00,
    FLS_CMD_SEND_E         = 0x01,
    FLS_VERIFY_E           = 0x02,
    FLS_UNKNOW_E           = 0xFF,
} Fls_JobStatusType;

typedef void (*Fls_JobNotifyType)(Std_ReturnType ret);

typedef struct Fls_ListNode
{
    struct Fls_ListNode *prev;
    struct Fls_ListNode *next;
} Fls_ListNodeType;

typedef struct
{
    Fls_ContextType         *pCtx;
    Fls_BusHandleType       *nor;
} Fls_SectorsBindInfoType;

/** \brief  the runtime job info structure of flash */
typedef struct
{
    Fls_ListNodeType        node;

    MemIf_StatusType        status;
    Fls_ServiceIdType       serviceId;
    Fls_AddressType         startAddr;
    Fls_LengthType          length;
    Fls_LengthType          numBytesDone;
    Fls_LengthType          numBytesWriteDone;
    Fls_JobStatusType       jobStatus;
    MemIf_JobResultType     jobResult;
    uint8                   *readPtr;  /**< Reading buffer pointers*/
    const uint8             *writePtr; /**< Writing buffer pointers*/
    Fls_ContextType         *pCtx;
    Fls_BusHandleType       *nor;
    const Fls_SectorConfigType    *sectorCfg;
#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
    uint32                  timeoutCycleCount;
    boolean                 timeoutCheckEnable;
#endif /* #if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON) */
} Fls_JobInfoType;

struct Fls_SectorConfig
{
    Fls_AddressType      sectorStartAddr;
    Fls_LengthType       sectorSize;
    Fls_LengthType       pageSize;
    Fls_LengthType       numberOfSectors;
    Fls_LengthType       totalSize;
    Fls_JobNotifyType    jobNotification;
    uint8                jobPriority;
    Fls_JobInfoType            *jobInfo;
};

typedef struct
{
    void (*jobEndNotification)(void);
    void (*jobErrorNotification)(void);
    Fls_IpClockOpsType clkOps;
} Fls_ProgramDescriptorType;

typedef enum
{
    FLS_SPECIAL_AUTO = 0U,
    FLS_SPECIAL_IS25LP064A,
    FLS_SPECIAL_HYPERRAM,
    FLS_SPECIAL_MCP,            /* device mode = SPI_NOR_DEV_SWITCH_MODE */
} Fls_FlashSpecialType;

typedef enum
{
    FLS_XSPI1_PORTA = 0U,
    FLS_XSPI1_PORTB,
    FLS_XSPI2_PORTA,
    FLS_XSPI2_PORTB,
    FLS_CONTROLLER_ID_MAX,
} Fls_ControllerIDType;

typedef struct
{
    Fls_AddressType addr;
    Fls_LengthType size;
} Fls_ProtectAreaType;

typedef struct
{
    uint32   callCycle;
    /* Modes */
    MemIf_ModeType defaultMode;
    uint32    maxReadFastMode;
    uint32    maxReadNormalMode;
    uint32    maxWriteFastMode;
    uint32    maxWriteNormalMode;
    uint32   protection;
    uint8   sectorListSize;
    uint32   totalSize;
    const Fls_SectorConfigType *sectorList;
    const Fls_ProgramDescriptorType *progDesc;
} Fls_FlashConfigType;  /* EB FlsConfigSet */

typedef struct
{
    Fls_ControllerIDType id;
    Fls_BusConfigType busConfig;
    Fls_FlashSpecialType flashSpecialFlag;
    Fls_ContextType    *pointerContex;
} Fls_ControllerConfigType; /* EB FlsController */

typedef struct
{
    uint8 asyncMode;
    Fls_FlashConfigType flashConfig;
    Fls_ControllerConfigType controllerTable[FLS_MAX_NUMBER_OF_CONTROLLER];
    uint8 controllerNumber;
} Fls_ConfigType;

#define FLS_PORT_MAX_NUM (2u)
struct Fls_Context
{
    Fls_ListNodeType pendingJobList[FLS_MAX_PRIOFITY_NUMBER];
    int index;
    Fls_BusHandleType busTable[FLS_PORT_MAX_NUM];
    uint8 flashNumber;
    Fls_IpHostType host;
    Fls_BusFlashOpsType *ops;
    const Fls_ControllerConfigType *controllerConfig;
    const Fls_FlashConfigType *flashConfig;
    Fls_AddressType      baseAddr;
    Fls_LengthType       totalSize;
    boolean protectEnable;
};

extern const Fls_ConfigType *Fls_ConfigPtr;
extern const Fls_ConfigType Fls_ConfigData;
#ifdef FLS_SPIBUS_FLASH_CNT
extern Fls_BusFlashOpsType Fls_SpibusOps;
#endif /* #ifdef FLS_SPIBUS_FLASH_CNT */
#ifdef FLS_HYPERBUS_FLASH_CNT
extern Fls_BusFlashOpsType Fls_HyperbusOps;
#endif /* #ifdef FLS_HYPERBUS_FLASH_CNT */

#ifdef FLS_PROTECTED_AREA_NUM
#if FLS_PROTECTED_AREA_NUM
extern const Fls_ProtectAreaType Fls_ProtectArea[FLS_PROTECTED_AREA_NUM];
#endif /* #if FLS_PROTECTED_AREA_NUM */
#endif /* #ifdef FLS_PROTECTED_AREA_NUM */

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/

/** *****************************************************************************************************
 * \brief This function Verifies writen contents of complete flash page.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Fls_WriteVerification( Fls_JobInfoType *pJob
 *                          Fls_AddressType TargetAddress, const uint8 *SourceAddressPtr,
 *                          Fls_LengthType Length)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : pJob - Point of job's information
 *                      TargetAddress - Source address in flash memory.
 *                      SourceAddressPtr - Pointer to target data buffer
 *                      Length - Number of bytes to Verified
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : FLS_OK_E: Operation successful
 *                      FLS_BUSY_E: Operation not completed
 *                      Others: Operation failed
 *
 * Description        : Verifies writen contents of complete flash page
 * \endverbatim
 * Traceability       : SWSR_FLS_015 SWSR_FLS_142
 *******************************************************************************************************/
extern Std_ReturnType Fls_WriteVerification(Fls_JobInfoType *pJob, Fls_AddressType TargetAddress,
        const uint8 *SourceAddressPtr, Fls_LengthType Length );

/** *****************************************************************************************************
 * \brief This function Verifies Erases of flash sector(s)
 *
 * \verbatim
 * Syntax             : Std_ReturnType Fls_EraseVerification( Fls_JobInfoType *pJob,
 *                          Fls_AddressType TargetAddress, Fls_LengthType Length)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : pJob - Point of job's information
 *                      TargetAddress - Source address in flash memory
 *                      Length - Number of bytes to Verified
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : FLS_OK_E: Operation successful
 *                      FLS_BUSY_E: Operation not completed
 *                      Others: Operation failed
 *
 * Description        : Verifies Erases of flash sector(s)
 * \endverbatim
 * Traceability       : SWSR_FLS_014 SWSR_FLS_140 SWSR_FLS_141
 *******************************************************************************************************/
extern Std_ReturnType Fls_EraseVerification(Fls_JobInfoType *pJob, Fls_AddressType TargetAddress,
        Fls_LengthType Length );

/** *****************************************************************************************************
 * \brief This function Check whether the current operation is timeout
 *
 * \verbatim
 * Syntax             : uint8 Fls_TimeOut( Fls_JobInfoType *pJob)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : pJob - Point of job's information
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Operation not timed out
 *                      E_NOT_OK: Operation timed out
 *
 * Description        : Check whether the current operation is timeout
 * \endverbatim
 * Traceability       : SWSR_FLS_016
 *******************************************************************************************************/
extern uint8 Fls_TimeOut(Fls_JobInfoType *pJob);

/** *****************************************************************************************************
 * \brief This function initialize any flash for the FLS module.
 *
 * \verbatim
 * Syntax             : void Fls_InitMask(
 *                          const Fls_ConfigType* configPtr, uint8 mask)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : configPtr - Pointer to configuration set
 *                      mask - Masks to be initialised
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        :initialize any flash for the FLS module(software).
 * \endverbatim
 * Traceability       : SWSR_FLS_021 SWSR_FLS_022 SWSR_FLS_034 SWSR_FLS_035
 *                      SWSR_FLS_036 SWSR_FLS_037 SWSR_FLS_038 SWSR_FLS_039
 *******************************************************************************************************/
extern void Fls_InitMask(const Fls_ConfigType *configPtr, uint8 mask);

/** *****************************************************************************************************
 * \brief This function initialize all flash for the FLS module.
 *
 * \verbatim
 * Syntax             : void Fls_Init(
 *                          const Fls_ConfigType* configPtr)
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : configPtr - Pointer to configuration set
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        :initialize all flash for the FLS module(software) and all flash
 *                     memory relevant registers (hardware) with parameters provided in
 *                     the given configuration set.
 * \endverbatim
 * Traceability       : SWSR_FLS_032 SWSR_FLS_033
 *******************************************************************************************************/
extern void Fls_Init(const Fls_ConfigType *ConfigPtr );

/** *****************************************************************************************************
 * \brief This function Erases flash sector.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Fls_Erase(
 *                          Fls_AddressType TargetAddress, Fls_LengthType Length)
 *
 * Service ID[hex]    : 0x01
 *
 * Sync/Async         : Asynchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : TargetAddress - Target address in flash memory
 *                      Length - Number of bytes to erase
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK - Oprational command has been accepted
 *                      E_NOT_OK - Oprational command has not been
 *
 * Description        : Erase one or more complete flash sectors
 * \endverbatim
 * Traceability       : SWSR_FLS_040 SWSR_FLS_041 SWSR_FLS_042 SWSR_FLS_043 SWSR_FLS_044
 *                      SWSR_FLS_045 SWSR_FLS_049
 *******************************************************************************************************/
extern Std_ReturnType Fls_Erase(  Fls_AddressType TargetAddress,
                                  Fls_LengthType Length);

/** *****************************************************************************************************
 * \brief This function write one or more complete flash pages to the flash device.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Fls_Write(
 *                          Fls_AddressType TargetAddress, const uint8 *SourceAddressPtr,
 *                          Fls_LengthType Length)
 *
 * Service ID[hex]    : 0x02
 *
 * Sync/Async         : Asynchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : TargetAddress - Target address in flash memory.
 *                      SourceAddressPtr - Pointer to source data buffer
 *                      Length - Number of bytes to write
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK - Oprational command has been accepted
 *                      E_NOT_OK - Oprational command has not been
 *
 * Description        : Writes one or more complete flash pages.
 * \endverbatim
 * Traceability       : SWSR_FLS_052 SWSR_FLS_053 SWSR_FLS_054 SWSR_FLS_056 SWSR_FLS_057
 *                      SWSR_FLS_064
 *******************************************************************************************************/
extern Std_ReturnType Fls_Write( Fls_AddressType TargetAddress,
                                 const uint8 *SourceAddressPtr,
                                 Fls_LengthType Length );

/** *****************************************************************************************************
 * \brief This function cancel an ongoing flash read, write, erase or compare job.
 *
 * \verbatim
 * Syntax             : void Fls_Cancel(void)
 *
 * Service ID[hex]    : 0x03
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Cancels an ongoing job.
 * \endverbatim
 * Traceability       : SWSR_FLS_065 SWSR_FLS_066 SWSR_FLS_070 SWSR_FLS_071 SWSR_FLS_073 SWSR_FLS_158
 *******************************************************************************************************/
#if (FLS_CANCEL_API == STD_ON)
extern void Fls_Cancel( void );
#endif /* #if (FLS_CANCEL_API == STD_ON) */

/** *****************************************************************************************************
 * \brief This function returns Returns the driver state.
 *
 * \verbatim
 * Syntax             : MemIf_StatusType Fls_GetStatus(void)
 *
 * Service ID[hex]    : 0x04
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Driver state (MemIf_StatusType)
 *
 * Description        : Return the FLS module state synchronously.
 * \endverbatim
 * Traceability       : SWSR_FLS_074 SWSR_FLS_075
 *******************************************************************************************************/
#if (FLS_GET_STATUS_API == STD_ON)
extern MemIf_StatusType Fls_GetStatus( void );
#endif /* #if (FLS_GET_STATUS_API == STD_ON) */

#if (FLS_GET_JOB_RESULT_API == STD_ON)
/** *****************************************************************************************************
 * \brief This function returns the the result of the last job.
 *
 * \verbatim
 * Syntax             : MemIf_JobResultType Fls_GetJobResult(void)
 *
 * Service ID[hex]    : 0x05
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Result of the last job(MemIf_JobResultType)
 *
 * Description        : return the result of the last job synchronously
 * \endverbatim
 * Traceability       : SWSR_FLS_077 SWSR_FLS_078 SWSR_FLS_079 SWSR_FLS_081
 *******************************************************************************************************/
extern MemIf_JobResultType Fls_GetJobResult( void );

/** *****************************************************************************************************
 * \brief This function returns the the result of the Specify job.
 *
 * \verbatim
 * Syntax             : MemIf_JobResultType Fls_GetJobResultById(uint8 index)
 *
 * Service ID[hex]    : 0x05
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : index - The index of sector
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Result of the Specify job(MemIf_JobResultType)
 *
 * Description        : return the result of the Specify job synchronously
 * \endverbatim
 * Traceability       : SWSR_FLS_077 SWSR_FLS_078 SWSR_FLS_079 SWSR_FLS_081
 *******************************************************************************************************/
extern MemIf_JobResultType Fls_GetJobResultById( uint8 index );
#endif /* #if (FLS_GET_JOB_RESULT_API == STD_ON) */

/** *****************************************************************************************************
 * \brief This function Performs the processing of jobs.
 *
 * \verbatim
 * Syntax             : void Fls_MainFunction(void)
 *
 * Service ID[hex]    : 0x06
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK - Oprational command has been accepted
 *                      E_NOT_OK - Oprational command has not been
 *
 * Description        : Performs the processing of jobs.
 * \endverbatim
 * Traceability       : SWSR_FLS_003 SWSR_FLS_024 SWSR_FLS_046 SWSR_FLS_058 SWSR_FLS_088 SWSR_FLS_102
 *                      SWSR_FLS_122 SWSR_FLS_130 SWSR_FLS_131 SWSR_FLS_132 SWSR_FLS_133 SWSR_FLS_145
 *                      SWSR_FLS_146 SWSR_FLS_147 SWSR_FLS_148 SWSR_FLS_149
 *******************************************************************************************************/
extern void Fls_MainFunction( void );

/** *****************************************************************************************************
 * \brief This function read from flash memory..
 *
 * \verbatim
 * Syntax             : Std_ReturnType Fls_Read(
 *                          Fls_AddressType TargetAddress, const uint8 *TargetAddressPtr,
 *                          Fls_LengthType Length)
 *
 * Service ID[hex]    : 0x07
 *
 * Sync/Async         : Asynchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : TargetAddress - Target address in flash memory.
 *                      TargetAddressPtr - Pointer to data buffer
 *                      Length - Number of bytes to read
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK - Oprational command has been accepted
 *                      E_NOT_OK - Oprational command has not been
 *
 * Description        : Reads from flash memory.
 * \endverbatim
 * Traceability       : SWSR_FLS_082 SWSR_FLS_083 SWSR_FLS_084 SWSR_FLS_086 SWSR_FLS_087
 *                      SWSR_FLS_094
 *******************************************************************************************************/
extern Std_ReturnType Fls_Read( Fls_AddressType SourceAddress,
                                uint8 *TargetAddressPtr,
                                Fls_LengthType Length );

/** *****************************************************************************************************
 * \brief This function shall compare the contents of an area of flash memory with that of
 *        an application data buffer.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Fls_Compare(
 *                          Fls_AddressType SourceAddress, const uint8 *TargetAddressPtr,
 *                          Fls_LengthType Length)
 *
 * Service ID[hex]    : 0x08
 *
 * Sync/Async         : Asynchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : SourceAddress - Target address in flash memory.
 *                      TargetAddressPtr - Pointer to data buffer
 *                      Length - Number of bytes to compare
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK - Oprational command has been accepted
 *                      E_NOT_OK - Oprational command has not been
 *
 * Description        : Compares the contents of an area of flash memory with that of an
 *                      application data buffer.
 * \endverbatim
 * Traceability       : SWSR_FLS_096 SWSR_FLS_097 SWSR_FLS_098 SWSR_FLS_100 SWSR_FLS_101
 *                      SWSR_FLS_108
 *******************************************************************************************************/
#if (FLS_COMPARE_API == STD_ON)
extern Std_ReturnType Fls_Compare( Fls_AddressType SourceAddress,
                                   const uint8 *TargetAddressPtr,
                                   Fls_LengthType Length );
#endif /* #if (FLS_COMPARE_API == STD_ON) */

/** *****************************************************************************************************
 * \brief This function Sets the flash driver's operation mode.
 *
 * \verbatim
 * Syntax             : void Fls_SetMode(
 *                          MemIf_ModeType Mode)
 *
 * Service ID[hex]    : 0x09
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : Mode - MEMIF_MODE_SLOW: Slow read access / normal SPI access.
 *                             MEMIF_MODE_FAST: Fast read access / SPI burst access.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Set the FLS module operation mode to the given Mode parameter
 * \endverbatim
 * Traceability       : SWSR_FLS_110 SWSR_FLS_111 SWSR_FLS_112
 *******************************************************************************************************/
#if (FLS_SET_MODE_API == STD_ON)
extern void Fls_SetMode( MemIf_ModeType Mode );
#endif /* #if (FLS_SET_MODE_API == STD_ON) */

/** *****************************************************************************************************
 * \brief This function verify, whether a given memory area has been erased but not
 *        (yet) re-programmed.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Fls_BlankCheck(
 *                          Fls_AddressType TargetAddress, Fls_LengthType Length)
 *
 * Service ID[hex]    : 0x0A
 *
 * Sync/Async         : Asynchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : TargetAddressPtr - Pointer to data buffer
 *                      Length - Number of bytes to compare
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK - Oprational command has been accepted
 *                      E_NOT_OK - Oprational command has not been
 *
 * Description        : The function Fls_BlankCheck shall verify, whether a given memory area
 *                      has been erased but not (yet) programmed. The function shall limit the
 *                      maximum number of checked flash cells per main function cycle to the
 *                      configured value FlsMaxReadNormalMode or FlsMaxReadFastMode respectively
 * \endverbatim
 * Traceability       : SWSR_FLS_116 SWSR_FLS_117 SWSR_FLS_118 SWSR_FLS_120 SWSR_FLS_121
 *******************************************************************************************************/
#if (FLS_COMPARE_API == STD_ON)
Std_ReturnType Fls_BlankCheck(Fls_AddressType TargetAddress, Fls_LengthType Length);
#endif /* #if (FLS_COMPARE_API == STD_ON) */

/** *****************************************************************************************************
 * \brief This function returns the version information of this module.
 *
 * \verbatim
 * Syntax             : void Fls_GetVersionInfo(
 *                          Std_VersionInfoType *VersioninfoPtr)
 *
 * Service ID[hex]    : 0x10
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : VersioninfoPtr - Pointer to where to store the version information of this module.
 *
 * Return value       : None
 *
 * Description        : Returns the version information of this module.
 * \endverbatim
 * Traceability       : SWSR_FLS_114 SWSR_FLS_115
 *******************************************************************************************************/
#if (FLS_VERSION_INFO_API == STD_ON)
void Fls_GetVersionInfo( Std_VersionInfoType *VersioninfoPtr );
#endif /* #if (FLS_VERSION_INFO_API == STD_ON) */

/** *****************************************************************************************************
 * \brief This function get the sector configuration of target address.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Fls_GetSector(
 *                          Fls_AddressType targetAddress, const Fls_SectorConfigType** sectorConfig)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : targetAddress - Address of flash memory
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : sectorConfig -  Pointer to sector configuration
 *
 * Return value       : E_OK: Operation not timed out
 *                      E_NOT_OK: Operation timed out
 *
 * Description        : Get the sector configuration of target addressr
 * \endverbatim
 * Traceability       : SWSR_FLS_171
 *******************************************************************************************************/
Std_ReturnType Fls_GetSector( Fls_AddressType targetAddress,
                              const Fls_SectorConfigType **sectorConfig );

/** *****************************************************************************************************
 * \brief This function Configure the protection area of Flash.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Fls_Protect(
 *                          Fls_AddressType TargetAddress, Fls_LengthType Length)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : TargetAddress - Address in flash memory
 *                      Length - Number of bytes to be protected.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK - Protect command has been accepted
 *                      E_NOT_OK - Protect command has not been
 *
 * Description        : Configure the protection area of Flash
 * \endverbatim
 * Traceability       : SWSR_FLS_170
 *******************************************************************************************************/
extern Std_ReturnType Fls_Protect(  Fls_AddressType TargetAddress,
                                    Fls_LengthType Length);

/** *****************************************************************************************************
 * \brief This function restores the xspi configuration of the registers.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Fls_RestoredState( void )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK - Protect command has been accepted
 *                      E_NOT_OK - Protect command has not been
 *
 * Description        : Restores the xspi configuration state of the registers,
 *                       after which you can jump directly to XIP mode.
 * \endverbatim
 *******************************************************************************************************/
extern Std_ReturnType Fls_RestoredState( void );

/** *****************************************************************************************************
 * \brief This function Implementing Data Copy.
 *
 * \verbatim
 * Syntax             : void *Fls_MemCopy(
 *                          void *dst, const void *src, uint32 size)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : dst - Target buffer address
 *                      src - Source buffer address
 *                      size - Data length
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Target buffer address
 *
 * Description        : Selecting the most appropriate alignment for copying data
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
void *Fls_MemCopy(void *dst, const void *src, uint32 size);

/** *****************************************************************************************************
 * \brief This function Implementing Data Copy.
 *
 * \verbatim
 * Syntax             : void *Fls_MemCompare(
 *                         const void *mem1, const void *mem2, uint32 size)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : mem1 - comparison buffer address
 *                      mem2 - comparison buffer address
 *                      size - comparison buffer length
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Data are the same
 *                      !0 - The data are not the same
 *
 * Description        : Selecting the most appropriate alignment for copying data
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
uint32 Fls_MemCompare(const void *mem1, const void *mem2, uint32 size);

/** *****************************************************************************************************
 * \brief This function Implementing Data clear.
 *
 * \verbatim
 * Syntax             : void Fls_MemClear(
 *                          void *dst, uint32 size)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : dst - Target buffer address
 *                      size - Data length
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Selecting the most appropriate alignment for clear data
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
void Fls_MemClear(void *dst, uint32 size);

/** *****************************************************************************************************
 * \brief This function Restore the initial state of the peripheral.
 *
 * \verbatim
 * Syntax             : void Fls_Deinit( void )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Selecting the most appropriate alignment for clear data
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
void Fls_Deinit(void);
#ifdef __cplusplus
}
#endif /* #ifdef __cplusplus */

#endif  /* #ifndef FLS_H */

/* End of file */
