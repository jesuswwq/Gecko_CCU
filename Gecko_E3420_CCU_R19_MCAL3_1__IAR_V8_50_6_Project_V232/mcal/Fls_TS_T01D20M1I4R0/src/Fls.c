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
 * \file     Fls.c                                                                                      *
 * \brief    AUTOSAR 4.3.1 Fls MCAL Driver.                                                             *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/20     <td>3.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif /* #ifdef __cplusplus */

#include "Fls.h"
#if (FLS_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* #if (FLS_DEV_ERROR_DETECT == STD_ON) */
#include "SchM_Fls.h"

/* PRQA S 0306,0314,0316,0326,0488,1504,1505,2755,2877,2916,3673,4332 EOF */

/* Macros*/
#define FLS_MAX_STACK_BUFFER_SIZE       (256U)
#if (FLS_DEV_ERROR_DETECT == STD_OFF)
#define Det_ReportError(...) (0)
#define Det_ReportTransientFault(...) (0)
#define Det_ReportRuntimeError(...) (0)
#endif /*FLS_DEV_ERROR_DETECT == STD_OFF*/

#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
#define FLS_ERASE_TIMEOUT_CYCLES (FLS_ERASE_TIME / FLS_CALL_CYCLES)
#define FLS_WRITE_TIMEOUT_CYCLES (FLS_WRITE_TIME / FLS_CALL_CYCLES)
#endif /* #if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON) */

#define FLS_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

/* #define FLS_NORFLASH_TEST_ENABLE */
#ifdef FLS_NORFLASH_TEST_ENABLE
static uint8 Fls_EraseCount[FLS_BUS_SECTOR_TYPE_MAX];
#endif /* #ifdef FLS_NORFLASH_TEST_ENABLE */

const Fls_ConfigType *Fls_ConfigPtr;
static MemIf_JobResultType   Fls_LastJobResult;
static MemIf_ModeType Fls_MemIfMode;
static Fls_LengthType Fls_MaxNumBytesRead;
static Fls_LengthType Fls_MaxNumBytesWrite;

#define FLS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"

/* local supporting functions*/
static const Fls_SectorConfigType *Fls_GetDevice(Fls_AddressType beginAddress, Fls_LengthType length,
        Fls_ServiceIdType apiId);
static Fls_BusHandleType *Fls_GetFlash(Fls_ContextType *pCtx, Fls_AddressType beginAddress,
                                       Fls_LengthType length);

static boolean Fls_CheckConfiguration(const Fls_ConfigType *ConfigPtr);
#if (FLS_ADDRESS_ALIGNED_CHECK_ENABLED == STD_ON)
static boolean Fls_CheckSectorAlign(Fls_AddressType addr, const Fls_SectorConfigType *sectorCfg);
static boolean Fls_CheckPageAlign(Fls_AddressType addr, const Fls_SectorConfigType *sectorCfg);
#endif /* #if (FLS_ADDRESS_ALIGNED_CHECK_ENABLED == STD_ON) */
static void Fls_ResetOrders(Fls_JobInfoType *pJob);
static void Fls_JobEnd(Fls_JobInfoType *pJob, Fls_ReturnInfoType stRet);
static Fls_JobInfoType *Fls_JobPrepare(Fls_AddressType targetAddress, Fls_LengthType length,
                                       Fls_ServiceIdType apiId);
static boolean Fls_IsJobsPending(void);
static Fls_JobInfoType *Fls_GetPendingJob(Fls_ContextType *pCtx);
static void Fls_JobInsert(Fls_JobInfoType *pJob);
static void Fls_DoPendingJob(Fls_JobInfoType *pJob);
static uint8 Fls_JobsPreInit(const Fls_ConfigType *configData);
static void Fls_JobsInit(const Fls_ConfigType *configData);

/* Functions which call the Hardware Driver callbacks*/
static Fls_ReturnInfoType Fls_WriteProcess(Fls_JobInfoType *pJob);
static Fls_ReturnInfoType Fls_EraseProcess(Fls_JobInfoType *pJob);
static Fls_ReturnInfoType Fls_ReadProcess(Fls_JobInfoType *pJob);
#if (FLS_COMPARE_API == STD_ON)
static Fls_ReturnInfoType  Fls_CompareProcess(Fls_JobInfoType *pJob);
#endif /* #if (FLS_COMPARE_API == STD_ON) */
#if (FLS_BLANK_CHECK_API == STD_ON)
static Fls_ReturnInfoType  Fls_BlankCheckProcess(Fls_JobInfoType *pJob);
#endif /* #if (FLS_BLANK_CHECK_API == STD_ON) */
#if (FLS_CANCEL_API == STD_ON)
static Fls_ReturnInfoType  Fls_CancelProc(Fls_JobInfoType *pJob);
#endif /* #if (FLS_CANCEL_API == STD_ON) */
static void Fls_ListInitialize(Fls_ListNodeType *list);
static Fls_ListNodeType *Fls_ListRemoveHead(Fls_ListNodeType *list);
static void Fls_ListAddTail(Fls_ListNodeType *list, Fls_ListNodeType *item);
static boolean Fls_ListInList(Fls_ListNodeType *item);
static void Fls_ListDelete(Fls_ListNodeType *item);

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
void  Fls_InitMask(const Fls_ConfigType *configPtr, uint8 mask)
{
    Std_ReturnType stReturn = E_NOT_OK;
    uint8 idexController;
    uint8 idxSector;
    Fls_LengthType totalSize = 0;
    uint8 i;
    const Fls_SectorConfigType *pSector;
    Fls_AddressType address;
    Fls_ContextType *pCtx;
    uint8 ret;

    ret = Fls_JobsPreInit(configPtr);

    if (E_OK != ret)
    {
        (void) Det_ReportError(FLS_MODULE_ID, 0, (uint8)FLS_INIT_ID, ret);
    }
    else if (FALSE == Fls_CheckConfiguration(configPtr))
    {
        (void) Det_ReportError(FLS_MODULE_ID, 0, (uint8)FLS_INIT_ID, FLS_E_PARAM_CONFIG);
    }
    else
    {
        /* initialize all flash hardware devices */
        for (idexController = 0; idexController < configPtr->controllerNumber; idexController++)
        {
            if (0U == (mask & (1U << idexController)))
            {
                continue;
            }

            pCtx = configPtr->controllerTable[idexController].pointerContex;

            if ((0 == Fls_IpInit(&pCtx->host, &configPtr->controllerTable[idexController].busConfig))
                    && (NULL_PTR != pCtx->ops) && (NULL_PTR != pCtx->ops->init))
            {
                for (i = 0; i < FLS_PORT_MAX_NUM; i++)
                {
                    if (0 != pCtx->ops->init(&pCtx->busTable[i], &pCtx->host,
                                             &configPtr->controllerTable[idexController].busConfig))
                    {
                        stReturn = E_NOT_OK;
                    }
                    else
                    {
                        stReturn = E_OK;
                    }

                    pCtx->busTable[i].info.regOffset = pCtx->totalSize;
                    pCtx->totalSize += pCtx->busTable[i].info.size;
                    pCtx->flashNumber++;

                    if ((configPtr->controllerTable[idexController].busConfig.devMode != FLS_BUS_DEV_SWITCH_MODE)
                            || (E_NOT_OK == stReturn))
                    {
                        break;
                    }
                }
            }
            else
            {
                stReturn = E_NOT_OK;
            }

            if (stReturn != E_OK)
            {
                break;
            }

            pCtx->baseAddr = totalSize;
            totalSize += pCtx->totalSize;

            /* bind sector & fls context */
            for (idxSector = 0; idxSector < configPtr->flashConfig.sectorListSize; idxSector++)
            {
                pSector = &(configPtr->flashConfig.sectorList[idxSector]);
                address = pSector->sectorStartAddr;
#if (FLS_BASE_ADDRESS > 0U)
                address += FLS_BASE_ADDRESS;
#endif /* #if (FLS_BASE_ADDRESS > 0U) */

                if ((NULL_PTR == pSector->jobInfo->pCtx)
                        && (address >= pCtx->baseAddr)
                        && ((address + pSector->totalSize) <= (pCtx->baseAddr + pCtx->totalSize)))
                {
                    pSector->jobInfo->nor = Fls_GetFlash(pCtx, address, pSector->totalSize);

                    if (NULL_PTR != pSector->jobInfo->nor)
                    {
                        pSector->jobInfo->pCtx = pCtx;
                    }
                }
            }
        }

        if (stReturn == E_OK)
        {
            Fls_JobsInit(configPtr);

#if defined(FLS_PROTECTED_AREA_NUM) && (FLS_PROTECTED_AREA_NUM > 0)
#if (FLS_PROTECTED_AREA_NUM > 1)

            for (i = 0; i < FLS_PROTECTED_AREA_NUM; i++)
#else
            i = 0;

#endif /* #if (FLS_PROTECTED_AREA_NUM > 1) */
            {
                (void) Fls_Protect(Fls_ProtectArea[i].addr, Fls_ProtectArea[i].size);
            }
#endif /* #if defined(FLS_PROTECTED_AREA_NUM) && (FLS_PROTECTED_AREA_NUM > 0) */
        }
    }
}

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
void Fls_Init(const Fls_ConfigType *ConfigPtr)
{
    Fls_InitMask(ConfigPtr, 0xffu);
}

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
Std_ReturnType Fls_Erase(   Fls_AddressType TargetAddress,
                            Fls_LengthType Length )
{
    Std_ReturnType ret = E_NOT_OK;
    Fls_JobInfoType *pJob = Fls_JobPrepare(TargetAddress, Length, FLS_ERASE_ID);

    if (NULL_PTR == pJob)
    {
        /* Do nothing */
    }
    else
    {
#if (FLS_ADDRESS_ALIGNED_CHECK_ENABLED == STD_ON)

        if (FALSE == Fls_CheckSectorAlign(TargetAddress, pJob->sectorCfg))
        {
            (void) Det_ReportError(FLS_MODULE_ID, 0, (uint8)FLS_ERASE_ID, FLS_E_PARAM_ADDRESS);
            Fls_ResetOrders(pJob);
        }
        else if (FALSE == Fls_CheckSectorAlign(TargetAddress + Length, pJob->sectorCfg))
        {
            (void) Det_ReportError(FLS_MODULE_ID, 0, (uint8)FLS_ERASE_ID, FLS_E_PARAM_LENGTH);
            Fls_ResetOrders(pJob);
        }
        else
#endif /* #if (FLS_ADDRESS_ALIGNED_CHECK_ENABLED == STD_ON) */
        {
            ret = E_OK;
#ifdef FLS_NORFLASH_TEST_ENABLE
            Fls_MemClear(Fls_EraseCount, sizeof(Fls_EraseCount));
#endif /* #ifdef FLS_NORFLASH_TEST_ENABLE */
#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
            pJob->timeoutCheckEnable = TRUE;
            pJob->timeoutCycleCount = FLS_ERASE_TIMEOUT_CYCLES;
#endif /* #if FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON */
            Fls_JobInsert(pJob);
        }
    }

    return ret;
}

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
Std_ReturnType Fls_Write(   Fls_AddressType TargetAddress,
                            const uint8 *SourceAddressPtr,
                            Fls_LengthType Length)
{
    Std_ReturnType ret = E_NOT_OK;
    Fls_JobInfoType *pJob;

    if (NULL_PTR == SourceAddressPtr)
    {
        (void) Det_ReportError(FLS_MODULE_ID, 0, (uint8)FLS_WRITE_ID, FLS_E_PARAM_DATA);
    }
    else
    {
        pJob = Fls_JobPrepare(TargetAddress, Length, FLS_WRITE_ID);

        if (NULL_PTR == pJob)
        {
            /* Do nothing */
        }

#if (FLS_ADDRESS_ALIGNED_CHECK_ENABLED == STD_ON)
        else if (FALSE == Fls_CheckPageAlign(TargetAddress, pJob->sectorCfg))
        {
            (void) Det_ReportError(FLS_MODULE_ID, 0, (uint8)FLS_WRITE_ID, FLS_E_PARAM_ADDRESS);
            Fls_ResetOrders(pJob);
        }
        else if (FALSE == Fls_CheckPageAlign(TargetAddress + Length, pJob->sectorCfg))
        {
            (void) Det_ReportError(FLS_MODULE_ID, 0, (uint8)FLS_WRITE_ID, FLS_E_PARAM_LENGTH);
            Fls_ResetOrders(pJob);
        }

#endif /* #if (FLS_ADDRESS_ALIGNED_CHECK_ENABLED == STD_ON) */
        else
        {
            ret = E_OK;
            pJob->writePtr     = SourceAddressPtr;
            pJob->numBytesWriteDone = 0U;
#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
            pJob->timeoutCheckEnable = TRUE;
            pJob->timeoutCycleCount = FLS_WRITE_TIMEOUT_CYCLES;
#endif /* #if FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON */
            Fls_JobInsert(pJob);
        }
    }

    return ret;
}

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
Std_ReturnType Fls_Read(    Fls_AddressType SourceAddress,
                            uint8 *TargetAddressPtr,
                            Fls_LengthType Length)
{
    Std_ReturnType ret = E_NOT_OK;
    Fls_JobInfoType *pJob;

    if (NULL_PTR == TargetAddressPtr)
    {
        (void) Det_ReportError(FLS_MODULE_ID, 0, (uint8)FLS_READ_ID, FLS_E_PARAM_DATA);
    }
    else
    {
        pJob = Fls_JobPrepare(SourceAddress, Length, FLS_READ_ID);

        if (NULL_PTR != pJob)
        {
            ret = E_OK;
            pJob->readPtr      = TargetAddressPtr;
            Fls_JobInsert(pJob);
        }
    }

    return ret;
}

#if (FLS_COMPARE_API == STD_ON)
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
Std_ReturnType Fls_Compare(  Fls_AddressType SourceAddress,
                             const uint8 *TargetAddressPtr,
                             Fls_LengthType Length
                          )
{
    Std_ReturnType ret = E_NOT_OK;
    Fls_JobInfoType *pJob;

    if (NULL_PTR == TargetAddressPtr)
    {
        (void) Det_ReportError(FLS_MODULE_ID, 0, (uint8)FLS_COMPARE_ID, FLS_E_PARAM_DATA);
    }
    else
    {
        pJob = Fls_JobPrepare(SourceAddress, Length, FLS_COMPARE_ID);

        if (NULL_PTR != pJob)
        {
            ret = E_OK;
            pJob->writePtr      = TargetAddressPtr;
            Fls_JobInsert(pJob);
        }
    }

    return ret;
}
#endif /* #if (FLS_COMPARE_API == STD_ON) */

#if (FLS_BLANK_CHECK_API == STD_ON)
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
Std_ReturnType Fls_BlankCheck( Fls_AddressType TargetAddress,
                               Fls_LengthType Length )
{
    Std_ReturnType ret = E_NOT_OK;
    Fls_JobInfoType *pJob = Fls_JobPrepare(TargetAddress, Length, FLS_BLANKCHECK_ID);

    if (NULL_PTR != pJob)
    {
        ret = E_OK;
        Fls_JobInsert(pJob);
    }

    return ret;
}
#endif /* #if (FLS_BLANK_CHECK_API == STD_ON) */

#if (FLS_CANCEL_API == STD_ON)
/** *****************************************************************************************************
 * \brief This function cancel all ongoing flash read, write, erase or compare jobs.
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
 * Description        : Cancels all ongoing jobs.
 * \endverbatim
 * Traceability       : SWSR_FLS_065 SWSR_FLS_066 SWSR_FLS_070 SWSR_FLS_071 SWSR_FLS_073 SWSR_FLS_158
 *******************************************************************************************************/
void Fls_Cancel( void )
{
    Fls_ContextType *pCtx;
    Fls_JobInfoType *pJob;
    uint8 i;

    if (NULL_PTR == Fls_ConfigPtr)
    {
        (void) Det_ReportError(FLS_MODULE_ID, 0, (uint8)FLS_CANCEL_ID, FLS_E_UNINIT);
    }
    else
    {
        SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_00();

        for (i = 0; i < Fls_ConfigPtr->flashConfig.sectorListSize; i++)
        {
            Fls_ConfigPtr->flashConfig.sectorList[i].jobInfo->jobResult = MEMIF_JOB_CANCELED;
        }

        SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00();

        for (i = 0; i < Fls_ConfigPtr->controllerNumber; i++)
        {
            pCtx = Fls_ConfigPtr->controllerTable[i].pointerContex;
            pJob = Fls_GetPendingJob(pCtx);

            if (NULL_PTR != pJob)
            {
                if (FLS_OK_E != Fls_CancelProc(pJob))
                {
                    /* Do nothing */
                }
                else
                {
                    Fls_JobEnd(pJob, FLS_CANCEL_E);
                }
            }
        }
    }

}
#endif /* #if (FLS_CANCEL_API == STD_ON) */

#if (STD_ON == FLS_GET_STATUS_API)
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
MemIf_StatusType Fls_GetStatus( void )
{
    MemIf_StatusType status;

    if (NULL_PTR == Fls_ConfigPtr)
    {
        status = MEMIF_UNINIT;
    }
    else if (TRUE == Fls_IsJobsPending())
    {
        status = MEMIF_BUSY;
    }
    else
    {
        status = MEMIF_IDLE;
    }

    return status;
}
#endif /* #if (STD_ON == FLS_GET_STATUS_API) */

#if (STD_ON == FLS_GET_JOB_RESULT_API)
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
MemIf_JobResultType Fls_GetJobResult( void )
{
    MemIf_JobResultType jobResult;

    if (NULL_PTR == Fls_ConfigPtr)
    {
        jobResult = MEMIF_JOB_FAILED;
        (void) Det_ReportError(FLS_MODULE_ID, 0, (uint8)FLS_GET_JOB_RESULT_ID, FLS_E_UNINIT);
    }
    else if (TRUE == Fls_IsJobsPending())
    {
        jobResult = MEMIF_JOB_PENDING;
    }
    else
    {
        jobResult = Fls_LastJobResult;
    }

    return jobResult;
}

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
MemIf_JobResultType Fls_GetJobResultById( uint8 index )
{
    MemIf_JobResultType jobResult;
    const Fls_JobInfoType *pJob;

    if (NULL_PTR == Fls_ConfigPtr)
    {
        jobResult = MEMIF_JOB_FAILED;
        (void) Det_ReportError(FLS_MODULE_ID, 0, (uint8)FLS_GET_JOB_RESULT_ID, FLS_E_UNINIT);
    }
    else if (index >= Fls_ConfigPtr->flashConfig.sectorListSize)
    {
        jobResult = MEMIF_BLOCK_INVALID;
        (void) Det_ReportError(FLS_MODULE_ID, 0, (uint8)FLS_GET_JOB_RESULT_ID, FLS_E_PARAM_DATA);
    }
    else
    {
        pJob = Fls_ConfigPtr->flashConfig.sectorList[index].jobInfo;
        jobResult = pJob->jobResult;
    }

    return jobResult;
}
#endif /* #if (STD_ON == FLS_GET_JOB_RESULT_API) */

#if (FLS_SET_MODE_API == STD_ON)
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
void Fls_SetMode( MemIf_ModeType Mode )
{
    if (NULL_PTR == Fls_ConfigPtr)
    {
        (void) Det_ReportError(FLS_MODULE_ID, 0, (uint8)FLS_SET_MODE_ID, FLS_E_UNINIT);
    }
    else if (TRUE == Fls_IsJobsPending())
    {
        (void) Det_ReportError(FLS_MODULE_ID, 0, (uint8)FLS_SET_MODE_ID, FLS_E_BUSY);
    }
    else
    {
        Fls_MemIfMode = Mode;

        if (MEMIF_MODE_SLOW == Fls_MemIfMode)
        {
            Fls_MaxNumBytesRead = Fls_ConfigPtr->flashConfig.maxReadNormalMode;
            Fls_MaxNumBytesWrite = Fls_ConfigPtr->flashConfig.maxWriteNormalMode;
        }
        else
        {
            Fls_MaxNumBytesRead = Fls_ConfigPtr->flashConfig.maxReadFastMode;
            Fls_MaxNumBytesWrite = Fls_ConfigPtr->flashConfig.maxWriteFastMode;
        }
    }
}
#endif /* #if (FLS_SET_MODE_API == STD_ON) */

#if ( FLS_VERSION_INFO_API == STD_ON )
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
void Fls_GetVersionInfo( Std_VersionInfoType *VersioninfoPtr )
{
    if (VersioninfoPtr == NULL_PTR)
    {
        /* Lin transceiver not initialized*/
        (void) Det_ReportError(FLS_MODULE_ID, 0, (uint8)FLS_GET_VERSION_INFO_ID, FLS_E_PARAM_POINTER);
    }
    else
    {
        VersioninfoPtr->vendorID = FLS_SW_VENDOR;
        VersioninfoPtr->moduleID = FLS_MODULE_ID;
        VersioninfoPtr->sw_major_version = FLS_SW_MAJOR_VERSION;
        VersioninfoPtr->sw_minor_version = FLS_SW_MINOR_VERSION;
        VersioninfoPtr->sw_patch_version = FLS_SW_PATCH_VERSION;
    }
}
#endif /* #if ( FLS_VERSION_INFO_API == STD_ON ) */

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
Std_ReturnType Fls_Protect(Fls_AddressType TargetAddress, Fls_LengthType Length)
{
    Std_ReturnType ret = E_NOT_OK;
    Fls_ContextType *pCtx;
    Fls_BusHandleType *nor;
    uint32 i;

    if (NULL_PTR == Fls_ConfigPtr)
    {
        (void) Det_ReportError(FLS_MODULE_ID, 0, (uint8)FLS_PROTECT_AREA_ID, FLS_E_UNINIT);
    }
    else if (TRUE == Fls_IsJobsPending())
    {
        (void) Det_ReportError(FLS_MODULE_ID, 0, (uint8)FLS_PROTECT_AREA_ID, FLS_E_BUSY);
    }
    else
    {
        for (i = 0; i < Fls_ConfigPtr->controllerNumber; i++)
        {
            pCtx = Fls_ConfigPtr->controllerTable[i].pointerContex;

            if ((TargetAddress >= pCtx->baseAddr) &&
                    ((TargetAddress + Length) <= (pCtx->baseAddr + pCtx->totalSize)))
            {
                nor = Fls_GetFlash(pCtx, TargetAddress, Length);

                if (NULL_PTR == nor)
                {
                    /* Do nothing */
                }
                else if (0 == Fls_BusSetProtectArea(nor,
                                                    TargetAddress - pCtx->baseAddr - nor->info.regOffset, Length))
                {
                    ret = E_OK;
                    pCtx->protectEnable = TRUE;

                    if (NULL_PTR == pCtx->ops->getProtectStatus)
                    {
                        FLS_DEBUG("Note:Flash flag status monitoring is not supported\n");
                    }
                }
                else
                {
                    /* Do nothing */
                }

                break;
            }
        }
    }

    return ret;
}

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
void Fls_MainFunction( void )
{
    Fls_JobInfoType *pJob;
    Fls_ContextType *pCtx;
    uint32 i;

    if (NULL_PTR == Fls_ConfigPtr)
    {
        (void) Det_ReportError(FLS_MODULE_ID, 0, (uint8)FLS_MAIN_FUNCTION_ID, FLS_E_UNINIT);
    }
    else
    {
        for (i = 0; i < Fls_ConfigPtr->controllerNumber; i++)
        {
            pCtx = Fls_ConfigPtr->controllerTable[i].pointerContex;
            pJob = Fls_GetPendingJob(pCtx);

            if (NULL_PTR != pJob)
            {
                Fls_DoPendingJob(pJob);
            }
        }
    }
}

/** *****************************************************************************************************
 * \brief This function returns the corresponding sector structure information according to
 *        the target address
 *
 * \verbatim
 * Syntax             : const Fls_SectorConfigType* Fls_FindSectorConfig(
 *                          Fls_AddressType addr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : addr - Address in flash memory
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Pointer of Sector information
 *
 * Description        : Return the corresponding sector structure information according to
 *                      the target address
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static const Fls_SectorConfigType *Fls_FindSectorConfig(Fls_AddressType addr)
{
    uint32 i;
    Fls_AddressType sectorStartAddr;
    Fls_LengthType totalSize;
    const Fls_SectorConfigType *sectorConfig = NULL_PTR;
    const Fls_FlashConfigType *pFlashConfig = &(Fls_ConfigPtr->flashConfig);

    for (i = 0; i < pFlashConfig->sectorListSize; i++)
    {
        sectorStartAddr = pFlashConfig->sectorList[i].sectorStartAddr;
        totalSize = pFlashConfig->sectorList[i].totalSize;

        if ((addr >= sectorStartAddr) && (addr < (sectorStartAddr + totalSize)))
        {
            sectorConfig = &(pFlashConfig->sectorList[i]);
            break;
        }
    }

    return sectorConfig;
}

/** *****************************************************************************************************
 * \brief This function Check whether the configuration parameter is legal.
 *
 * \verbatim
 * Syntax             : boolean Fls_CheckConfiguration(
 *                          const Fls_ConfigType *ConfigPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Asynchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : configPtr - Pointer to configuration set
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : TRUE - The parameters are valid
 *                      FALSE - Parameter error
 *
 * Description        : Check whether the configuration parameter is legal
 * \endverbatim
 * Traceability       : SWSR_FLS_167
 *******************************************************************************************************/
static boolean Fls_CheckConfiguration(const Fls_ConfigType *ConfigPtr)
{
    boolean Ret = TRUE;
    uint8 conId;
    uint8 PortInUse[FLS_CONTROLLER_ID_MAX];
    Fls_ContextType *pCtx;
    uint8 i;

    /* Arrays need to be defined first and then assigned initial values to avoid linking to
        rodata section in some compiler */
    PortInUse[FLS_XSPI1_PORTA] = 0;
    PortInUse[FLS_XSPI1_PORTB] = 0;
    PortInUse[FLS_XSPI2_PORTA] = 0;
    PortInUse[FLS_XSPI2_PORTB] = 0;

    for (conId = 0; conId < ConfigPtr->controllerNumber; conId++)
    {
        const Fls_ControllerConfigType *pcontrollerConfig = &(ConfigPtr->controllerTable[conId]);

        if ((pcontrollerConfig->busConfig.devMode == FLS_BUS_DEV_LOCKSTEP_MODE)
                || (pcontrollerConfig->busConfig.devMode == FLS_BUS_DEV_PARALLEL_MODE))
        {
            if ((pcontrollerConfig->id != FLS_XSPI1_PORTA) && (pcontrollerConfig->id != FLS_XSPI2_PORTA))
            {
                Ret = FALSE;
            }
            else if ((PortInUse[(uint8)pcontrollerConfig->id] > 0U) ||
                     ((PortInUse[(uint8)pcontrollerConfig->id + 1U]) > 0U))
            {
                Ret = FALSE;
            }
            else
            {
                /* Do nothing */
            }
        }
        else if (PortInUse[(uint8)pcontrollerConfig->id] > 0U)
        {
            Ret = FALSE;
        }
        else
        {
            /* Do nothing */
        }

        if (FALSE == Ret)
        {
            break;
        }

        PortInUse[(uint8)pcontrollerConfig->id]++;

        pCtx = pcontrollerConfig->pointerContex;
        pCtx->controllerConfig = pcontrollerConfig;
        pCtx->flashConfig = &(ConfigPtr->flashConfig);
        Fls_MemIfMode = ConfigPtr->flashConfig.defaultMode;

        if (MEMIF_MODE_SLOW == Fls_MemIfMode)
        {
            Fls_MaxNumBytesRead = ConfigPtr->flashConfig.maxReadNormalMode;
            Fls_MaxNumBytesWrite = ConfigPtr->flashConfig.maxWriteNormalMode;
        }
        else
        {
            Fls_MaxNumBytesRead = ConfigPtr->flashConfig.maxReadFastMode;
            Fls_MaxNumBytesWrite = ConfigPtr->flashConfig.maxWriteFastMode;
        }

        for (i = 0; i < FLS_PORT_MAX_NUM; i++)
        {
            Fls_MemClear((void *)(Fls_PointerType)(&pCtx->busTable[i]), sizeof(Fls_BusHandleType));
            pCtx->busTable[i].parent = (void *)(Fls_PointerType)pCtx;
            pCtx->busTable[i].ops = pCtx->ops;
            pCtx->busTable[i].cs = i;
        }

        pCtx->totalSize = 0;
        pCtx->flashNumber = 0;
#if (FLS_MAX_PRIOFITY_NUMBER > 1U)

        for (i = 0; i < FLS_MAX_PRIOFITY_NUMBER; i++)
        {
#else
        {
            i = 0;
#endif
            Fls_ListInitialize(&pCtx->pendingJobList[i]);
        }
    }

    return Ret;
}

#if (FLS_ADDRESS_ALIGNED_CHECK_ENABLED == STD_ON)
/** *****************************************************************************************************
 * \brief This function Check whether the target address is page aligned.
 *
 * \verbatim
 * Syntax             : boolean Fls_CheckPageAlign(
 *                          Fls_AddressType addr, const Fls_SectorConfigType *sectorCfg)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : addr - Address in flash memory
 *                      sectorCfg - A pointer of sector information
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : TRUE - The address is aligned
 *                      FALSE-  The address is not aligned
 *
 * Description        : Check whether the target address is page aligned
 * \endverbatim
 * Traceability       : SWSR_FLS_061
 *******************************************************************************************************/
static boolean Fls_CheckPageAlign(Fls_AddressType addr, const Fls_SectorConfigType *sectorCfg)
{
    boolean ret = FALSE;

    if ((NULL_PTR != sectorCfg) &&
            (0U == ((addr - sectorCfg->sectorStartAddr) % sectorCfg->pageSize)))
    {
        ret = TRUE;
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Check whether the target address is sector aligned.
 *
 * \verbatim
 * Syntax             : boolean Fls_CheckSectorAlign(
 *                          Fls_AddressType addr, const Fls_SectorConfigType *sectorCfg)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : addr - Address in flash memory
 *                      sectorCfg - A pointer of sector information
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : TRUE - The address is aligned
 *                      FALSE - The address is not aligned
 *
 * Description        : Check whether the target address is sector aligned
 * \endverbatim
 * Traceability       : SWSR_FLS_048
 *******************************************************************************************************/
static boolean Fls_CheckSectorAlign(Fls_AddressType addr, const Fls_SectorConfigType *sectorCfg)
{
    boolean ret = FALSE;

    if ((NULL_PTR != sectorCfg) &&
            (0U == ((addr - sectorCfg->sectorStartAddr) % sectorCfg->sectorSize)))
    {
        ret = TRUE;
    }

    return ret;
}
#endif /* #if (FLS_ADDRESS_ALIGNED_CHECK_ENABLED == STD_ON) */

/** *****************************************************************************************************
 * \brief This function Return the sector config where the target address is located
 *
 * \verbatim
 * Syntax             : const Fls_SectorConfigType* Fls_GetDevice(
 *                          Fls_AddressType beginAddress, Fls_LengthType length
 *                          Fls_ServiceIdType apiId)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : beginAddress - Address in flash memory
 *                      length - The length of the operation
 *                      apiId - The index of interface
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Pointer to sector config
 *
 * Description        : Return the sector config where the target address is located
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static const Fls_SectorConfigType *Fls_GetDevice(Fls_AddressType beginAddress, Fls_LengthType length,
        Fls_ServiceIdType apiId)
{
    const Fls_SectorConfigType *pSector = Fls_FindSectorConfig(beginAddress);

    if (pSector != NULL_PTR)
    {
        if ((NULL_PTR != pSector->jobInfo->pCtx)
                && ((beginAddress + length) <= (pSector->sectorStartAddr + pSector->totalSize)))
        {
            pSector->jobInfo->sectorCfg = pSector;
        }
        else
        {
            pSector = NULL_PTR;
            (void) Det_ReportError(FLS_MODULE_ID, 0, (uint8)apiId, FLS_E_PARAM_LENGTH);
        }
    }
    else
    {
        (void) Det_ReportError(FLS_MODULE_ID, 0, (uint8)apiId, FLS_E_PARAM_ADDRESS);
    }

    return pSector;
}

/** *****************************************************************************************************
 * \brief This function Rerturn the bus handle where the target area is located
 *
 * \verbatim
 * Syntax             : Fls_BusHandleType* Fls_GetFlash(
 *                          Fls_ContextType *pCtx, Fls_AddressType beginAddress,
 *                          Fls_LengthType length)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : pCtx - Pointer to Module handler
 *                      beginAddress - Address in flash memory
 *                      length - The length of the operation
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Pointer to bus handle
 *
 * Description        : Rerturn the bus handle where the target area is located
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static Fls_BusHandleType *Fls_GetFlash(Fls_ContextType *pCtx, Fls_AddressType beginAddress,
                                       Fls_LengthType length)
{
    uint8 i;
    Fls_BusHandleType *ret = NULL_PTR;

    for (i = 0; i < pCtx->flashNumber; i++)
    {
        if ((beginAddress < (pCtx->busTable[i].info.regOffset + pCtx->busTable[i].info.size)) &&
                ((beginAddress + length) <=
                 (pCtx->busTable[i].info.regOffset + pCtx->busTable[i].info.size)))
        {
            ret = &pCtx->busTable[i];
            break;
        }
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Rerturn the result of Determine if there is unfinished business
 *
 * \verbatim
 * Syntax             : boolean Fls_IsJobsPending( void )
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
 * Return value       : TRUE - There is unfinished jobs
 *                      FALSE - No unfinished jobs
 *
 * Description        : Determine if there is unfinished business
 * \endverbatim
 * Traceability       : SWSR_FLS_172
 *******************************************************************************************************/
static boolean Fls_IsJobsPending( void )
{
    boolean ret = FALSE;
    uint8 i;

    if (NULL_PTR != Fls_ConfigPtr)
    {
        SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_00();

        for (i = 0; i < Fls_ConfigPtr->flashConfig.sectorListSize; i++)
        {
            if ((MEMIF_JOB_PENDING == Fls_ConfigPtr->flashConfig.sectorList[i].jobInfo->jobResult)
                    && (MEMIF_BUSY == Fls_ConfigPtr->flashConfig.sectorList[i].jobInfo->status))
            {
                ret = TRUE;
                break;
            }
        }

        SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00();
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Initialize the chain table header
 *
 * \verbatim
 * Syntax             : void Fls_ListInitialize(Fls_ListNodeType *list)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : list - Point of the chain table header
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Initialize the chain table header
 * \endverbatim
 *******************************************************************************************************/
static void Fls_ListInitialize(Fls_ListNodeType *list)
{
    list->prev = list;
    list->next = list;
}

/** *****************************************************************************************************
 * \brief This function Delete a node from the head of the chain table
 *
 * \verbatim
 * Syntax             : Fls_ListNodeType *Fls_ListRemoveHead(Fls_ListNodeType *list)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : list - Point of the chain table header
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Point of the node
 *
 * Description        : Delete a node from the head of the chain table
 * \endverbatim
 *******************************************************************************************************/
static Fls_ListNodeType *Fls_ListRemoveHead(Fls_ListNodeType *list)
{
    Fls_ListNodeType *item = NULL_PTR;

    if (list->next != list)
    {
        item = list->next;
        Fls_ListDelete(item);
    }

    return item;
}

/** *****************************************************************************************************
 * \brief This function Add a node to the end of the chain table
 *
 * \verbatim
 * Syntax             : void Fls_ListAddTail(
 *                          Fls_ListNodeType *list, Fls_ListNodeType *item)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : list - Point of the chain table header
 *                      item - Point of the node
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Add a node to the end of the chain table
 * \endverbatim
 *******************************************************************************************************/
static void Fls_ListAddTail(Fls_ListNodeType *list, Fls_ListNodeType *item)
{
    item->prev = list->prev;
    item->next = list;
    list->prev->next = item;
    list->prev = item;
}

/** *****************************************************************************************************
 * \brief This function return the result if a node is in a linked list
 *
 * \verbatim
 * Syntax             : boolean Fls_ListInList(Fls_ListNodeType *item)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : item - Point of the node
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : FALSE - node is not in a linked list
 *                      TRUE - node is in a linked list
 *
 * Description        : Determine if a node is in a linked list
 * \endverbatim
 *******************************************************************************************************/
static boolean Fls_ListInList(Fls_ListNodeType *item)
{
    boolean ret = TRUE;

    if ((NULL_PTR == item->prev) && (NULL_PTR == item->next))
    {
        ret = FALSE;
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Remove a node from a linked list
 *
 * \verbatim
 * Syntax             : void Fls_ListDelete(Fls_ListNodeType *item)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : item - Point of the node
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Remove a node from a linked list
 * \endverbatim
 *******************************************************************************************************/
static void Fls_ListDelete(Fls_ListNodeType *item)
{
    item->next->prev = item->prev;
    item->prev->next = item->next;
    item->prev = NULL_PTR;
    item->next = NULL_PTR;
}

/** *****************************************************************************************************
 * \brief This function Rerturn the point of unfinished job
 *
 * \verbatim
 * Syntax             : Fls_JobInfoType* Fls_GetPendingJob(
 *                                  Fls_ContextType *pCtx)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : pCtx - Point of mudule context
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Point of unfinished job
 *
 * Description        : Rerturn the point of unfinished job
 * \endverbatim
 * Traceability       : SWSR_FLS_172
 *******************************************************************************************************/
static Fls_JobInfoType *Fls_GetPendingJob(Fls_ContextType *pCtx)
{
    const Fls_ListNodeType *node;
    Fls_JobInfoType *pJob = NULL_PTR;
    uint32 i;
    SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_00();

    for (i = FLS_MAX_PRIOFITY_NUMBER; i > 0U; i--)
    {
        node = Fls_ListRemoveHead(&pCtx->pendingJobList[i - 1U]);

        if (NULL_PTR != node)
        {
            /* PRQA S 2810,3432 1 */
            pJob = FLS_CONTAINER_OF((node), Fls_JobInfoType, node);
            break;
        }
    }

    SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00();
    return pJob;
}

/** *****************************************************************************************************
 * \brief This function Inserting a Job into a Chained List
 *
 * \verbatim
 * Syntax             : void Fls_JobInsert(
 *                                  Fls_JobInfoType* *pJob)
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
 * Return value       : Point of unfinished job
 *
 * Description        : Inserting a Job into a Chained List
 * \endverbatim
 * Traceability       : SWSR_FLS_172
 *******************************************************************************************************/
static void Fls_JobInsert(Fls_JobInfoType *pJob)
{
    FLS_DEBUG("Insert 0x%x job (%d %d)\n", &pJob->node, pJob->serviceId, pJob->jobStatus);
    SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_00();

    if (TRUE == Fls_ListInList(&pJob->node))
    {
        /* Do nothing */
    }
    else
    {
        Fls_ListAddTail(&pJob->pCtx->pendingJobList[pJob->sectorCfg->jobPriority], &pJob->node);
    }

    SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00();
}

/** *****************************************************************************************************
 * \brief This function Processing a pending job
 *
 * \verbatim
 * Syntax             : void Fls_DoPendingJob (
 *                                  Fls_JobInfoType* *pJob)
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
 * Return value       : Point of unfinished job
 *
 * Description        : Processing a pending job
 * \endverbatim
 * Traceability       : SWSR_FLS_172
 *******************************************************************************************************/
static void Fls_DoPendingJob(Fls_JobInfoType *pJob)
{
    Fls_ReturnInfoType stRet = FLS_UNKNOW_ERROR_E;

    if (NULL_PTR == pJob)
    {
        FLS_DEBUG("Pending job is null\n");
    }
    else if (NULL_PTR == pJob->pCtx)
    {
        FLS_DEBUG("Job context is null\n");
    }
    else if (NULL_PTR == pJob->pCtx->ops)
    {
        FLS_DEBUG("Job operation function is null\n");
    }

#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
    else if (E_OK != Fls_TimeOut(pJob))
    {
        /* Timeout */
        FLS_DEBUG("Job(%x) is timeout\n", pJob);
        stRet = FLS_TIMEOUT_E;
    }

#endif /* #if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON) */
    else if (MEMIF_JOB_PENDING == pJob->jobResult)
    {
        switch (pJob->serviceId)
        {
        case FLS_WRITE_ID:
        {
            stRet =  Fls_WriteProcess(pJob);
            break;
        }

        case FLS_ERASE_ID:
        {
            stRet =  Fls_EraseProcess(pJob);
            break;
        }

#if (FLS_COMPARE_API == STD_ON)

        case FLS_COMPARE_ID:
        {
            stRet =  Fls_CompareProcess(pJob);
            break;
        }

#endif  /* FLS_COMPARE_API == STD_ON */

        case FLS_READ_ID:
        {
            stRet =  Fls_ReadProcess(pJob);
            break;
        }

#if (FLS_BLANK_CHECK_API == STD_ON)

        case FLS_BLANKCHECK_ID:
        {
            stRet =  Fls_BlankCheckProcess(pJob);
            break;
        }

#endif  /* FLS_BLANK_CHECK_API == STD_ON */

        default:
            FLS_DEBUG("Job(%x) unkown service id:%d\n", pJob, pJob->serviceId);
            break;
        }
    }

#if (FLS_CANCEL_API == STD_ON)
    else if (MEMIF_JOB_CANCELED == pJob->jobResult)
    {
        stRet = FLS_CANCEL_E;
    }

#endif /* #if (FLS_CANCEL_API == STD_ON) */
    else
    {
        /* Do nothing */
    }

    if (FLS_UNKNOW_ERROR_E == stRet)
    {
        /* Do nothing */
    }
    else if ((FLS_BUSY_E == stRet) ||
             ((FLS_OK_E == stRet) && (pJob->numBytesDone < pJob->length)))
    {
        Fls_JobInsert(pJob); /* The job needs to be continued */
    }
    else
    {
        Fls_JobEnd(pJob, stRet); /* The job has been completed */
    }
}

/** *****************************************************************************************************
 * \brief This function Restore the context of operating
 *
 * \verbatim
 * Syntax             : void Fls_ResetOrders(Fls_JobInfoType *pJob)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : pJob - Point of job's infomation (Fls_JobInfoType)
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Restore the context of operating
 * \endverbatim
 * Traceability       : SWSR_FLS_144
 *******************************************************************************************************/
static void Fls_ResetOrders(Fls_JobInfoType *pJob)
{
    SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_00();
    pJob->serviceId = FLS_UNKNOW_ID;
    pJob->startAddr  = 0;
    pJob->length  = 0;
    pJob->numBytesDone  = 0;
    pJob->jobStatus = FLS_IDLE_E;

    if (NULL_PTR != Fls_ConfigPtr)
    {
        pJob->status     = MEMIF_IDLE;
    }

    if (TRUE == Fls_ListInList(&pJob->node))
    {
        Fls_ListDelete(&pJob->node);
    }

    SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00();
}

/** *****************************************************************************************************
 * \brief This function Prepare to Initialising Jobs
 *
 * \verbatim
 * Syntax             : uint32 Fls_JobsPreInit(
 *                          const Fls_ConfigType *configData)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : pJob - Point of configuration
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Error code
 *
 * Description        : Prepare to Initialising Jobs
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static uint8 Fls_JobsPreInit(const Fls_ConfigType *configData)
{
    uint8 ret = E_OK;
    uint8 idxSector;
    const Fls_SectorConfigType *pSector;

    SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_00();

    if (NULL_PTR == configData)
    {
        ret = FLS_E_PARAM_POINTER;
    }
    else
    {
        for (idxSector = 0; idxSector < configData->flashConfig.sectorListSize; idxSector++)
        {
            pSector = &(configData->flashConfig.sectorList[idxSector]);

            if (NULL_PTR == pSector->jobInfo)
            {
                ret = FLS_E_PARAM_DATA;
            }
            else if (MEMIF_BUSY == pSector->jobInfo->status)
            {
                ret = FLS_E_BUSY;
            }
            else
            {
                /* Do nothing */
            }

            if (E_OK != ret)
            {
                break;
            }
        }

        if (E_OK == ret)
        {
            /* Job statue set to MEMIF_UNINIT */
            for (idxSector = 0; idxSector < configData->flashConfig.sectorListSize; idxSector++)
            {
                pSector = &(configData->flashConfig.sectorList[idxSector]);
                Fls_MemClear((void *)pSector->jobInfo, sizeof(Fls_JobInfoType));
            }
        }
    }

    SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00();
    return ret;
}

/** *****************************************************************************************************
 * \brief This function Initialising Jobs
 *
 * \verbatim
 * Syntax             : uint32 Fls_JobsInit(
 *                          const Fls_ConfigType *configData)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : pJob - Point of configuration
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Initialising Jobs
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static void Fls_JobsInit(const Fls_ConfigType *configData)
{
    uint8 idxSector;
    const Fls_SectorConfigType *pSector;

    if (NULL_PTR != configData)
    {
        SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_00();
        Fls_ConfigPtr = configData;
        SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00();

        /* Clear sector config jobInfo */
        for (idxSector = 0; idxSector < Fls_ConfigPtr->flashConfig.sectorListSize; idxSector++)
        {
            pSector = &(Fls_ConfigPtr->flashConfig.sectorList[idxSector]);

            if (NULL_PTR != pSector->jobInfo->pCtx)
            {
                Fls_ResetOrders(pSector->jobInfo);
                pSector->jobInfo->jobResult = MEMIF_JOB_OK;
            }
            else
            {
                (void) Det_ReportError(FLS_MODULE_ID, 0, (uint8)FLS_INIT_ID, FLS_E_PARAM_CONFIG);
            }
        }
    }

}

/** *****************************************************************************************************
 * \brief This function is Tail treatment of one operation.
 *
 * \verbatim
 * Syntax             : void Fls_JobEnd( Fls_JobInfoType *pJob
 *                          Fls_ReturnInfoType stRet)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : pJob - Point of job's infomation (Fls_JobInfoType)
 *                      stRet - The return value of the current operation
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Report the result of the operation and callback
 * \endverbatim
 * Traceability       : SWSR_FLS_135 SWSR_FLS_136 SWSR_FLS_137 SWSR_FLS_138 SWSR_FLS_139
 *                      SWSR_FLS_143 SWSR_FLS_155 SWSR_FLS_157 SWSR_FLS_158 SWSR_FLS_159
 *******************************************************************************************************/
static void Fls_JobEnd(Fls_JobInfoType *pJob, Fls_ReturnInfoType stRet)
{
    const Fls_FlashConfigType *pFlash = (NULL_PTR != pJob->pCtx) ?
                                        pJob->pCtx->flashConfig
                                        : (Fls_FlashConfigType *)NULL_PTR;
    const Fls_SectorConfigType *sectorConfig = pJob->sectorCfg;

    FLS_DEBUG("End 0x%x job (%d %d)\n", &pJob->node, pJob->serviceId, stRet);

    if (stRet == FLS_OK_E)
    {
        if (MEMIF_JOB_PENDING == pJob->jobResult)
        {
            pJob->jobResult = MEMIF_JOB_OK;
        }

        Fls_ResetOrders(pJob);
        Fls_LastJobResult = pJob->jobResult;

        /* Callback */
        if ((pFlash != NULL_PTR) &&
                (pFlash->progDesc->jobEndNotification != NULL_PTR))
        {
            pFlash->progDesc->jobEndNotification();
        }
    }
    else
    {
        if (FLS_COMPARE_E == stRet)
        {
            pJob->jobResult = MEMIF_BLOCK_INCONSISTENT;
        }
        else if (FLS_CANCEL_E == stRet)
        {
            pJob->jobResult = MEMIF_JOB_CANCELED;
        }
        else
        {
            pJob->jobResult = MEMIF_JOB_FAILED;
        }

        Fls_ResetOrders(pJob);
        Fls_LastJobResult = pJob->jobResult;

        /* Callback */
        if ((pFlash != NULL_PTR) &&
                (pFlash->progDesc->jobErrorNotification != NULL_PTR))
        {
            pFlash->progDesc->jobErrorNotification();
        }
    }

    if ((NULL_PTR != sectorConfig) && (NULL_PTR != sectorConfig->jobNotification))
    {
        sectorConfig->jobNotification((Std_ReturnType)stRet);
    }
}

/** *****************************************************************************************************
 * \brief This function is the Head treatment of one operation
 *
 * \verbatim
 * Syntax             : Fls_JobInfoType* Fls_JobPrepare(
 *                          Fls_AddressType targetAddress, Fls_LengthType length,
 *                          Fls_ServiceIdType apiId)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : targetAddress - Address in flash memory
 *                      length - The length of the operation
 *                      apiId - Operation index
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Successfully: The point of Jobs Infomation (Fls_JobInfoType);
 *                      Failed: NULL_PTR
 *
 * Description        : Checking parameters and preparing resources
 * \endverbatim
 * Traceability       : SWSR_FLS_008 SWSR_FLS_012 SWSR_FLS_013 SWSR_FLS_029 SWSR_FLS_047
 *                      SWSR_FLS_049 SWSR_FLS_050 SWSR_FLS_051 SWSR_FLS_055 SWSR_FLS_059
 *                      SWSR_FLS_060 SWSR_FLS_062 SWSR_FLS_063 SWSR_FLS_085 SWSR_FLS_089
 *                      SWSR_FLS_090 SWSR_FLS_091 SWSR_FLS_092 SWSR_FLS_093 SWSR_FLS_095
 *                      SWSR_FLS_099 SWSR_FLS_103 SWSR_FLS_104 SWSR_FLS_105 SWSR_FLS_106
 *                      SWSR_FLS_107 SWSR_FLS_119 SWSR_FLS_123 SWSR_FLS_124 SWSR_FLS_125
 *                      SWSR_FLS_126 SWSR_FLS_127
 *******************************************************************************************************/
static Fls_JobInfoType *Fls_JobPrepare(Fls_AddressType targetAddress, Fls_LengthType length,
                                       Fls_ServiceIdType apiId)
{
    const Fls_SectorConfigType *pSector;
    Fls_JobInfoType *pJob = NULL_PTR;
    Fls_AddressType startVirtualAddress;

    if (0u == length)
    {
        (void) Det_ReportError(FLS_MODULE_ID, 0, (uint8)apiId, FLS_E_PARAM_LENGTH);
    }
    else if (NULL_PTR == Fls_ConfigPtr)
    {
        (void) Det_ReportError(FLS_MODULE_ID, 0, (uint8)apiId, FLS_E_UNINIT);
    }
    else
    {
        pSector = Fls_GetDevice(targetAddress, length, apiId);
        SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_00();

        if (NULL_PTR == pSector)
        {
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00();
        }
        else if (MEMIF_UNINIT == pSector->jobInfo->status)
        {
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00();
            (void) Det_ReportError(FLS_MODULE_ID, 0, (uint8)apiId, FLS_E_UNINIT);
        }
        else if (MEMIF_BUSY == pSector->jobInfo->status)
        {
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00();
            (void) Det_ReportError(FLS_MODULE_ID, 0, (uint8)apiId, FLS_E_BUSY);
        }
        else
        {
            pJob = pSector->jobInfo;
            startVirtualAddress = targetAddress;
#if (FLS_BASE_ADDRESS > 0U)
            startVirtualAddress += FLS_BASE_ADDRESS;
#endif /* #if (FLS_BASE_ADDRESS > 0U) */
            startVirtualAddress -= pJob->pCtx->baseAddr;
            pJob->status = MEMIF_BUSY;
            pJob->startAddr = startVirtualAddress;
            pJob->length = length;
            pJob->numBytesDone = 0;
            pJob->serviceId = apiId;
            pJob->jobResult = MEMIF_JOB_PENDING;
            pJob->jobStatus = FLS_IDLE_E;
#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
            pJob->timeoutCheckEnable = FALSE; /* Default disable timeout check */
#endif /* #if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON) */
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00();
        }
    }

    return pJob;
}

/** *****************************************************************************************************
 * \brief This function is The actual operation of writing data.
 *
 * \verbatim
 * Syntax             : Fls_ReturnInfoType Fls_WriteProcess(
 *                              Fls_JobInfoType *pJob)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : pJob - Point of job's infomation
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : FLS_OK_E: Operation successful
 *                      FLS_BUSY_E: Operation not completed
 *                      Others: Operation failed
 *
 * Description        : Write data to Flash
 * \endverbatim
 * Traceability       : SWSR_FLS_018 SWSR_FLS_053 SWSR_FLS_134 SWSR_FLS_136 SWSR_FLS_141 SWSR_FLS_142
 *******************************************************************************************************/
static Fls_ReturnInfoType  Fls_WriteProcess(Fls_JobInfoType *pJob)
{
    Fls_ReturnInfoType stRet;
    uint32 currentStartAddr = pJob->startAddr +
                              pJob->numBytesDone;
    const uint8 *sourceAddr = &pJob->writePtr[pJob->numBytesDone];

    uint32 residualSize = pJob->length - pJob->numBytesDone;
    int stDriverReturn;
    uint32 writeSize;

    /* Get flash status */
    stRet = (0 == pJob->pCtx->ops->getBusyStatus(pJob->nor)) ?
            FLS_OK_E : FLS_BUSY_E;

    if (FLS_OK_E == stRet)
    {
        switch (pJob->jobStatus)
        {
        case FLS_IDLE_E :
        case FLS_CMD_SEND_E :
        {
            pJob->numBytesWriteDone = 0U;
            residualSize = FLS_MIN(residualSize, Fls_MaxNumBytesWrite);

            /* PRQA S 0771 ++ */
            do
            {
                writeSize = FLS_MIN((pJob->nor->info.pageSize -
                                     (currentStartAddr % pJob->nor->info.pageSize)),
                                    residualSize - pJob->numBytesWriteDone);

#if (FLS_ERASE_VERIFICATION_ENABLED == STD_ON)
                Std_ReturnType eraseRet = Fls_EraseVerification(pJob, currentStartAddr, writeSize);

                if (eraseRet != E_OK)
                {
                    (void) Det_ReportRuntimeError(FLS_MODULE_ID, 0, (uint8)FLS_WRITE_ID,
                                                  FLS_E_VERIFY_ERASE_FAILED);
                    stRet = FLS_WRITE_E;
                    break;
                }

#endif  /* FLS_ERASE_VERIFICATION_ENABLED == STD_ON */

                stDriverReturn = pJob->pCtx->ops->write(pJob->nor,
                                                        currentStartAddr,
                                                        sourceAddr,
                                                        writeSize);

                if (0 == stDriverReturn)
                {
                    pJob->numBytesWriteDone += writeSize;
                    currentStartAddr = pJob->startAddr +
                                       pJob->numBytesDone +
                                       pJob->numBytesWriteDone;
                    sourceAddr = &pJob->writePtr[pJob->numBytesDone +
                                                                    pJob->numBytesWriteDone];

                    stRet = FLS_BUSY_E;
                }
                else
                {
                    stRet = FLS_WRITE_E;
                    break;
                }

                if (residualSize > pJob->numBytesWriteDone)
                {
                    if (pJob->pCtx->ops->waitIdle(pJob->nor) != 0)
                    {
                        stRet = FLS_WRITE_E;
                        break;
                    }
                }

                if ((FALSE == pJob->pCtx->protectEnable))
                {
                    /* Do nothing */
                }
                else if (NULL_PTR == pJob->pCtx->ops->getProtectStatus)
                {
                    /* Do nothing */
                }
                else if (0 != pJob->pCtx->ops->getProtectStatus(pJob->nor))
                {
                    stRet = FLS_WRITE_E;
                    break;
                }
                else
                {
                    /* Do nothing */
                }
            }
            while (residualSize > pJob->numBytesWriteDone);

            if (stRet == FLS_WRITE_E)
            {
                (void) Det_ReportTransientFault(FLS_MODULE_ID, 0,
                                                (uint8)FLS_WRITE_ID, FLS_E_WRITE_FAILED);
                break;
            }

#if (FLS_WRITE_VERIFICATION_ENABLED == STD_ON)
            stRet = FLS_BUSY_E;
            pJob->jobStatus = FLS_VERIFY_E;
            break;
        }

        case FLS_VERIFY_E :
        {
            Std_ReturnType writeRet = Fls_WriteVerification(pJob,
                                      currentStartAddr, sourceAddr,
                                      pJob->numBytesWriteDone);

            if (writeRet != E_OK)
            {
                (void) Det_ReportRuntimeError(FLS_MODULE_ID, 0, (uint8)FLS_WRITE_ID,
                                              FLS_E_VERIFY_WRITE_FAILED);
                stRet = FLS_WRITE_E;
                break;
            }

#endif /* FLS_WRITE_VERIFICATION_ENABLED == STD_ON */

            pJob->numBytesDone += pJob->numBytesWriteDone;
            stRet = FLS_OK_E;
            pJob->jobStatus = FLS_IDLE_E;
            break;
        }

        default :
        {
            stRet = FLS_WRITE_E;
            break;
        }
        }
    }

    return stRet;
}

/** *****************************************************************************************************
 * \brief This function is The actual operation of erasing sector.
 *
 * \verbatim
 * Syntax             : Fls_ReturnInfoType Fls_EraseProcess(Fls_JobInfoType *pJob)
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
 * Return value       : FLS_OK_E: Operation successful
 *                      FLS_BUSY_E: Operation not completed
 *                      Others: Operation failed
 *
 * Description        : To erase a sector
 * \endverbatim
 * Traceability       : SWSR_FLS_017 SWSR_FLS_041 SWSR_FLS_135 SWSR_FLS_140 SWSR_FLS_149
 *******************************************************************************************************/
static Fls_ReturnInfoType  Fls_EraseProcess(Fls_JobInfoType *pJob)
{
    Fls_ReturnInfoType stRet;
    uint32 currentStartAddr = pJob->startAddr + pJob->numBytesDone;
    int i = 0;

    /* Get flash status */
    stRet = (0 == pJob->pCtx->ops->getBusyStatus(pJob->nor)) ? FLS_OK_E : FLS_BUSY_E;

    if (FLS_OK_E == stRet)
    {
        switch (pJob->jobStatus)
        {
        case FLS_IDLE_E :
        case FLS_CMD_SEND_E:
        {
            /* Only one sector can be erased in one call cycle.
            spi nor flash need to change erases sector dynamically*/
            if (FALSE == pJob->nor->hyperbusMode)
            {
                for (i = (int)FLS_BUS_SECTOR_TYPE_MAX - 1; i >= 0; i--)
                {
                    if ((0U != pJob->nor->info.eraseProto[i])
                            && (FLS_IS_ALIGNED(currentStartAddr, SECTOR_TYPE_TO_SIZE((uint32)i)))
                            && (0U != ((uint32)(pJob->length - pJob->numBytesDone)
                                       >> SECTOR_TYPE_TO_POST(i))))
                    {
                        pJob->nor->info.sectorSize = SECTOR_TYPE_TO_SIZE(i);
                        pJob->nor->info.sectorType = (Fls_BusSectorType)i;
                        break;
                    }
                }
            }

            if (i < 0)
            {
                stRet = FLS_ERASE_E;
                (void) Det_ReportTransientFault(FLS_MODULE_ID, 0, (uint8)FLS_ERASE_ID, FLS_E_ERASE_FAILED);
            }
            else if (0 != pJob->pCtx->ops->erase(pJob->nor,
                                                 currentStartAddr, pJob->nor->info.sectorSize))
            {
                stRet = FLS_ERASE_E;
                (void) Det_ReportTransientFault(FLS_MODULE_ID, 0, (uint8)FLS_ERASE_ID, FLS_E_ERASE_FAILED);
            }
            else if (FALSE == pJob->pCtx->protectEnable)
            {
                /* Do nothing */
            }
            else if (NULL_PTR == pJob->pCtx->ops->getProtectStatus)
            {
                /* Do nothing */
            }
            else if (0 != pJob->pCtx->ops->getProtectStatus(pJob->nor))
            {
                stRet = FLS_ERASE_E;
                (void) Det_ReportTransientFault(FLS_MODULE_ID, 0, (uint8)FLS_ERASE_ID, FLS_E_ERASE_FAILED);
            }
            else
            {
                /* Do nothing */
            }

#if (FLS_ERASE_VERIFICATION_ENABLED == STD_ON)

            if (FLS_OK_E == stRet)
            {
                stRet = FLS_BUSY_E;
                pJob->jobStatus = FLS_VERIFY_E;
            }

            break;
        }

        case FLS_VERIFY_E :
        {
            if (Fls_EraseVerification(pJob, currentStartAddr, pJob->nor->info.sectorSize) != E_OK)
            {
                (void) Det_ReportRuntimeError(FLS_MODULE_ID, 0, (uint8)FLS_ERASE_ID, FLS_E_VERIFY_ERASE_FAILED);
                stRet = FLS_ERASE_E;
            }

#endif /* #if (FLS_ERASE_VERIFICATION_ENABLED == STD_ON) */
            pJob->numBytesDone += pJob->nor->info.sectorSize;
            pJob->jobStatus = FLS_IDLE_E;
#ifdef FLS_NORFLASH_TEST_ENABLE
            Fls_EraseCount[pJob->nor->info.sectorType]++;
            FLS_DEBUG(">>>>4k:%d, 32k:%d, 64k:%d, 128k:%d, 256k:%d<<<<\n",
                      Fls_EraseCount[0], Fls_EraseCount[1], Fls_EraseCount[2],
                      Fls_EraseCount[3], Fls_EraseCount[4]);
#endif /* #ifdef FLS_NORFLASH_TEST_ENABLE */
            break;
        }

        default:
            stRet = FLS_ERASE_E;
            break;
        }

    }

    return stRet;
}

/** *****************************************************************************************************
 * \brief This function is The actual operation of reading sector.
 *
 * \verbatim
 * Syntax             : Fls_ReturnInfoType Fls_ReadProcess(
 *                              Fls_JobInfoType *pJob)
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
 * Return value       : FLS_OK_E: Operation successful
 *                      FLS_BUSY_E: Operation not completed
 *                      Others: Operation failed
 *
 * Description        : To read data from flash
 * \endverbatim
 * Traceability       : SWSR_FLS_019 SWSR_FLS_083 SWSR_FLS_134 SWSR_FLS_137
 *******************************************************************************************************/
static Fls_ReturnInfoType  Fls_ReadProcess(Fls_JobInfoType *pJob)
{
    Fls_ReturnInfoType stRet;
    uint32 currentStartAddr = pJob->startAddr + pJob->numBytesDone;
    uint8 *targetAddr = &pJob->readPtr[pJob->numBytesDone];
    uint32 residualSize = pJob->length - pJob->numBytesDone;
    int returnVal;

    /* Get flash status */
    stRet = (0 == pJob->pCtx->ops->getBusyStatus(pJob->nor)) ? FLS_OK_E : FLS_BUSY_E;

    if (FLS_OK_E == stRet)
    {
        residualSize = FLS_MIN(residualSize, Fls_MaxNumBytesRead);
        returnVal = pJob->pCtx->ops->read(pJob->nor,
                                          currentStartAddr,
                                          targetAddr,
                                          residualSize);

        if (returnVal == 0)
        {
            pJob->numBytesDone += residualSize;
        }
        else
        {
            (void) Det_ReportTransientFault(FLS_MODULE_ID, 0, (uint8)FLS_READ_ID, FLS_E_READ_FAILED);
            stRet = FLS_READ_E;
        }
    }

    return stRet;
}

#if (FLS_COMPARE_API == STD_ON)
/** *****************************************************************************************************
 * \brief This function is The actual operation of comparing the data and source buffer in Flash
 *
 * \verbatim
 * Syntax             : Fls_ReturnInfoType Fls_CompareProcess(
 *                                      Fls_JobInfoType *pJob)
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
 * Return value       : FLS_OK_E: Operation successful
 *                      FLS_BUSY_E: Operation not completed
 *                      Others: Operation failed
 *
 * Description        : To compare data with flash
 * \endverbatim
 * Traceability       : SWSR_FLS_020 SWSR_FLS_134 SWSR_FLS_138
 *******************************************************************************************************/
static Fls_ReturnInfoType  Fls_CompareProcess(Fls_JobInfoType *pJob)
{
    uint32 currentStartAddr = pJob->startAddr + pJob->numBytesDone;
    uint32 bytesDone = pJob->numBytesDone;
    uint32 residualSize = pJob->length - pJob->numBytesDone;
    uint32 thisStepLength;
    uint32 doneLength = 0;
    Fls_ReturnInfoType stRet;
    int returnVal;
    uint32 i;
    VAR_ALIGN(uint8 localBuffer[FLS_MAX_STACK_BUFFER_SIZE], 4u);

    /* Get flash status */
    stRet = (0 == pJob->pCtx->ops->getBusyStatus(pJob->nor)) ? FLS_OK_E : FLS_BUSY_E;

    if (FLS_OK_E == stRet)
    {
        if (residualSize > Fls_MaxNumBytesRead)
        {
            residualSize = Fls_MaxNumBytesRead;
        }

        pJob->numBytesDone += residualSize;

        do
        {
            if (residualSize <= FLS_MAX_STACK_BUFFER_SIZE)
            {
                thisStepLength = residualSize;
                residualSize = 0;
            }
            else
            {
                residualSize -= FLS_MAX_STACK_BUFFER_SIZE;
                thisStepLength = FLS_MAX_STACK_BUFFER_SIZE;
            }

            returnVal = pJob->pCtx->ops->read(pJob->nor,
                                              (uint32)currentStartAddr + doneLength,
                                              localBuffer,
                                              thisStepLength);

            if (returnVal != 0)
            {
                stRet = FLS_READ_E;
                (void) Det_ReportTransientFault(FLS_MODULE_ID, 0, (uint8)FLS_COMPARE_ID, FLS_E_COMPARE_FAILED);
                break;
            }

            for (i = 0; i < thisStepLength; i++)
            {
                if (localBuffer[i] != pJob->writePtr[bytesDone + doneLength + i])
                {
                    stRet = FLS_COMPARE_E;
                    returnVal = -1;
                    break;
                }
            }

            doneLength += thisStepLength;
        }
        while ((residualSize > 0U) && (returnVal == 0));
    }

    return stRet;
}
#endif  /* FLS_COMPARE_API == STD_ON */

#if (FLS_BLANK_CHECK_API == STD_ON)
/** *****************************************************************************************************
 * \brief This function is The actual operation of checking whether the target area data is blank
 *
 * \verbatim
 * Syntax             : Fls_ReturnInfoType Fls_BlankCheckProcess(
 *                          Fls_JobInfoType *pJob)
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
 * Return value       : FLS_OK_E: Operation successful
 *                      FLS_BUSY_E: Operation not completed
 *                      Others: Operation failed
 *
 * Description        : To check whether the target area data is blank
 * \endverbatim
 * Traceability       : SWSR_FLS_117 SWSR_FLS_134
 *******************************************************************************************************/
static Fls_ReturnInfoType  Fls_BlankCheckProcess(Fls_JobInfoType *pJob)
{
    uint32 currentStartAddr = pJob->startAddr + pJob->numBytesDone;
    uint32 residualSize = pJob->length - pJob->numBytesDone;
    uint32 thisStepLength;
    uint32 doneLength = 0;
    Fls_ReturnInfoType stRet;
    int returnVal;
    uint32 i;
    VAR_ALIGN(uint8 localBuffer[FLS_MAX_STACK_BUFFER_SIZE], 4u);

    /* Get flash status */
    stRet = (0 == pJob->pCtx->ops->getBusyStatus(pJob->nor)) ? FLS_OK_E : FLS_BUSY_E;

    if (FLS_OK_E == stRet)
    {
        if (residualSize > Fls_MaxNumBytesRead)
        {
            residualSize = Fls_MaxNumBytesRead;
        }

        pJob->numBytesDone += residualSize;

        do
        {
            if (residualSize <= FLS_MAX_STACK_BUFFER_SIZE)
            {
                thisStepLength = residualSize;
                residualSize = 0;
            }
            else
            {
                residualSize -= FLS_MAX_STACK_BUFFER_SIZE;
                thisStepLength = FLS_MAX_STACK_BUFFER_SIZE;
            }

            returnVal = pJob->pCtx->ops->read(pJob->nor,
                                              (uint32)currentStartAddr + doneLength,
                                              localBuffer,
                                              thisStepLength);

            if (returnVal != 0)
            {
                stRet = FLS_BLANKCHECK_E;
                break;
            }

            for (i = 0; i < thisStepLength; i++)
            {
                if (localBuffer[i] != 0xffU)
                {
                    stRet = FLS_BLANKCHECK_E;
                    returnVal = -1;
                    break;
                }
            }

            doneLength += thisStepLength;
        }
        while ((residualSize > 0U) && (returnVal == 0));

        if (FLS_OK_E != stRet)
        {
            (void) Det_ReportTransientFault(FLS_MODULE_ID, 0, (uint8)FLS_BLANKCHECK_ID,
                                            FLS_E_BLANK_CHECK_FAILED_ID);
        }
    }

    return stRet;
}
#endif  /* FLS_BLANK_CHECK_API == STD_ON */

#if (FLS_CANCEL_API == STD_ON)
/** *****************************************************************************************************
 * \brief This function is The actual operation of stopping the current operation
 *
 * \verbatim
 * Syntax             : Fls_ReturnInfoType Fls_CancelProc(Fls_JobInfoType *pJob)
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
 * Return value       : FLS_OK_E: Operation successful
 *                      FLS_BUSY_E: Operation not completed
 *                      Others: Operation failed
 *
 * Description        : stopping the current operation
 * \endverbatim
 * Traceability       : SWSR_FLS_066 SWSR_FLS_067 SWSR_FLS_068 SWSR_FLS_069
 *******************************************************************************************************/
static Fls_ReturnInfoType  Fls_CancelProc(Fls_JobInfoType *pJob)
{
    Fls_ReturnInfoType stRet;
    int retStatus;
    retStatus = pJob->pCtx->ops->cancel(pJob->nor);

    if (retStatus == 0)
    {
        stRet = FLS_OK_E;
    }
    else
    {
        stRet = FLS_CANCEL_E;
    }

    return stRet;
}
#endif  /* FLS_CANCEL_API == STD_ON */

#if (FLS_WRITE_VERIFICATION_ENABLED == STD_ON)
/** *****************************************************************************************************
 * \brief This function Verifies writen contents of complete flash page.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Fls_WriteVerification(
 *                          Fls_JobInfoType *pJob
 *                          Fls_AddressType TargetAddress,
 *                          const uint8 *SourceAddressPtr,
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
Std_ReturnType Fls_WriteVerification(Fls_JobInfoType *pJob,
                                     Fls_AddressType TargetAddress,
                                     const uint8 *SourceAddressPtr,
                                     Fls_LengthType Length )
{
    uint32 residualSize = Length;
    uint32 thisStepLength;
    uint32 doneLength = 0;
    Std_ReturnType stRet = E_OK;
    int returnVal;
    uint32 i;
    VAR_ALIGN(uint8 localBuffer[FLS_MAX_STACK_BUFFER_SIZE], 4u);

    do
    {
        if (residualSize <= FLS_MAX_STACK_BUFFER_SIZE)
        {
            thisStepLength = residualSize;
            residualSize = 0;
        }
        else
        {
            residualSize -= FLS_MAX_STACK_BUFFER_SIZE;
            thisStepLength = FLS_MAX_STACK_BUFFER_SIZE;
        }

        returnVal = pJob->pCtx->ops->read(pJob->nor,
                                          TargetAddress + doneLength,
                                          localBuffer,
                                          thisStepLength);

        if (returnVal != 0)
        {
            stRet = E_NOT_OK;
            break;
        }

        for (i = 0; i < thisStepLength; i++)
        {
            if (localBuffer[i] != SourceAddressPtr[i + doneLength])
            {
                (void) Det_ReportError(FLS_MODULE_ID, 0,  (uint8)FLS_WRITE_ID, FLS_E_VERIFY_WRITE_FAILED);
                stRet = E_NOT_OK;
                returnVal = -1;
                break;
            }
        }

        doneLength += thisStepLength;
    }
    while ((residualSize > 0U) && (returnVal == 0));

    return stRet;
}
#endif  /* FLS_WRITE_VERIFICATION_ENABLED == STD_ON */

#if (FLS_ERASE_VERIFICATION_ENABLED == STD_ON)
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
Std_ReturnType Fls_EraseVerification(Fls_JobInfoType *pJob,
                                     Fls_AddressType TargetAddress, Fls_LengthType Length)
{
    uint32 residualSize = Length;
    uint32 thisStepLength;
    uint32 doneLength = 0;
    Std_ReturnType stRet = E_OK;
    int returnVal;
    uint32 i;
    VAR_ALIGN(uint8 localBuffer[FLS_MAX_STACK_BUFFER_SIZE], 4u);

    do
    {
        if (residualSize <= FLS_MAX_STACK_BUFFER_SIZE)
        {
            thisStepLength = residualSize;
            residualSize = 0;
        }
        else
        {
            residualSize -= FLS_MAX_STACK_BUFFER_SIZE;
            thisStepLength = FLS_MAX_STACK_BUFFER_SIZE;
        }

        returnVal = pJob->pCtx->ops->read(pJob->nor,
                                          (uint32)TargetAddress + doneLength,
                                          localBuffer,
                                          thisStepLength);

        if (returnVal != 0)
        {
            stRet = E_NOT_OK;
            break;
        }

        for (i = 0; i < thisStepLength; i++)
        {
            if (localBuffer[i] != 0xffU)
            {
                stRet = E_NOT_OK;
                returnVal = -1;
                break;
            }
        }

        doneLength += thisStepLength;
    }
    while ((residualSize > 0U) && (returnVal == 0));

    return stRet;
}
#endif  /* FLS_ERASE_VERIFICATION_ENABLED == STD_ON */

#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
/** *****************************************************************************************************
 * \brief This function Check whether the current operation is timeout
 *
 * \verbatim
 * Syntax             : uint8 Fls_TimeOut(
 *                          Fls_JobInfoType *pJob)
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
uint8 Fls_TimeOut(Fls_JobInfoType *pJob)
{
    uint8 errorFlag = E_OK;

    if (TRUE == pJob->timeoutCheckEnable)
    {

        if (pJob->timeoutCycleCount > 0U)
        {
            pJob->timeoutCycleCount--;
        }
        else
        {
            errorFlag = E_NOT_OK;
        }

        if (errorFlag == E_NOT_OK)
        {
            (void) Det_ReportError( FLS_MODULE_ID, 0, (uint8)pJob->serviceId, FLS_E_TIMEOUT);
        }
    }

    return errorFlag;
}
#endif  /* FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON */

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
 * Reentrancy         : Non reentrant
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
                              const Fls_SectorConfigType **sectorConfig )
{
    Fls_SectorConfigType const *sectorConfigPtr = NULL_PTR;
    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != sectorConfig)
    {
        sectorConfigPtr = Fls_FindSectorConfig(targetAddress);
    }

    if (NULL_PTR != sectorConfigPtr)
    {
        *sectorConfig = sectorConfigPtr;
        ret = E_OK;
    }

    return ret;
}

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
void *Fls_MemCopy(void *dst, const void *src, uint32 size)
{
    uint32 alignSrc = (uint32)(Fls_PointerType)src % 4UL;
    uint32 alignDst = (uint32)(Fls_PointerType)dst % 4UL;
    uint8 *dstPtr = (uint8 *)dst;
    const uint8 *srcPtr = (const uint8 *)src;
    const uint32 *u32SrcPtr;
    uint32 *u32DstPtr;
    uint32 i;
    uint32 bytes;
    uint32 sizeTemp = size;

    if ((NULL_PTR != dstPtr) && (NULL_PTR != src))
    {
        if (alignSrc != alignDst)
        {
            for (; sizeTemp > 0U; sizeTemp--)
            {
                *dstPtr = *srcPtr;
                dstPtr++;
                srcPtr++;
            }
        }
        else
        {
            if (0U != alignSrc)
            {
                bytes = (sizeTemp > (4U - alignDst)) ? (4U - alignDst) : sizeTemp;

                for (i = 0U; i < bytes ; i++)
                {
                    *dstPtr = *srcPtr;
                    sizeTemp--;
                    dstPtr++;
                    srcPtr++;
                }
            }

            if (sizeTemp > 4U)
            {
                bytes = sizeTemp / 4U * 4U;
                u32SrcPtr = (const uint32 *)(Fls_PointerType)srcPtr;
                u32DstPtr = (uint32 *)(Fls_PointerType)dstPtr;

                for (i = 0U; i < (bytes / 4U); i++)
                {
                    *u32DstPtr = *u32SrcPtr;
                    u32DstPtr++;
                    u32SrcPtr++;
                    srcPtr += 4U;
                    dstPtr += 4U;
                }

                sizeTemp -= bytes;
            }

            for (; sizeTemp > 0U; sizeTemp--)
            {
                *dstPtr = *srcPtr;
                dstPtr++;
                srcPtr++;
            }
        }
    }

    return dst;
}

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
uint32 Fls_MemCompare(const void *mem1, const void *mem2, uint32 size)
{
    const uint8 *mem1Ptr = (const uint8 *)mem1, *mem2Ptr = (const uint8 *)mem2;
    uint32 sizeTemp = size;

    if ((NULL_PTR != mem1Ptr) && (NULL_PTR != mem2Ptr))
    {
        for (; sizeTemp > 0U; sizeTemp--)
        {
            if (*mem1Ptr != *mem2Ptr)
            {
                break;
            }

            mem1Ptr++;
            mem2Ptr++;
        }
    }

    return sizeTemp;
}

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
void Fls_MemClear(void *dst, uint32 size)
{
    uint32 align = (uint32)(Fls_PointerType)dst % 4U;
    uint32 bytes;
    uint8 *dstPtr = (uint8 *)dst;
    uint32 *u32DstPtr;
    uint32 sizeTemp = size;

    if (NULL_PTR != dstPtr)
    {
        if (align != 0U)
        {
            bytes = FLS_MIN(sizeTemp, (4U - align));

            for (; bytes > 0U; bytes--)
            {
                *dstPtr = 0U;
                sizeTemp--;
                dstPtr++;
            }
        }

        if (sizeTemp > 4U)
        {
            bytes = sizeTemp / 4U * 4U;
            u32DstPtr = (uint32 *)(Fls_PointerType)dstPtr;

            for (; bytes > 0U; bytes -= 4U)
            {
                *u32DstPtr = 0U;
                sizeTemp -= 4U;
                dstPtr += 4U;
                u32DstPtr++;
            }
        }

        for (; sizeTemp > 0U; sizeTemp--)
        {
            *dstPtr = 0U;
            dstPtr++;
        }
    }
}

#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#ifdef __cplusplus
}
#endif /* #ifdef __cplusplus */

/* End of file */
