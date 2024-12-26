/*
* SEMIDRIVE Copyright Statement
* Copyright (c) SEMIDRIVE. All rights reserved
*
* This software and all rights therein are owned by SEMIDRIVE, and are
* protected by copyright law and other relevant laws, regulations and
* protection. Without SEMIDRIVE's prior written consent and/or related rights,
* please do not use this software or any potion thereof in any form or by any
* means. You may not reproduce, modify or distribute this software except in
* compliance with the License. Unless required by applicable law or agreed to
* in writing, software distributed under the License is distributed on
* an "AS IS" basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.
*
* You should have received a copy of the License along with this program.
* If not, see <http://www.semidrive.com/licenses/>.
*/

/*
* @file  Fls.c
* @brief Semidrive. AUTOSAR 4.3.1 MCAL Fls plugins.
*/

#ifdef __cplusplus
extern "C" {
#endif

#include "Fls.h"
#include "Det.h"
#include <cdefs.h>
#include "cdefs.h"
#include "mini_libc.h"

/* Macros*/
#define FLS_MAX_STACK_BUFFER_SIZE       (256U)
#if (FLS_DEV_ERROR_DETECT == STD_OFF)
#define Det_ReportError(ModuleId, InstanceId, ApiId, ErrorId)
#endif /*FLS_DEV_ERROR_DETECT == STD_ON*/

/* Job state */
typedef enum {
    FLS_NONE,
    FLS_COMPARE,
    FLS_ERASE,
    FLS_READ,
    FLS_WRITE,
    FLS_BLANKCHECK
} Fls_JobType;

/* the runtime data structure of flash */
typedef struct {
    Fls_JobType           JobType;
    Fls_AddressType       StartAddr;
    Fls_LengthType        Length;
    Fls_LengthType        numBytesDone;
    Fls_LengthType        numBytestoWrite;
    Fls_LengthType        numBytesWriteDone;
    Fls_stReturnInfo      JobStatus;
    /* Buffer pointers*/
    const uint8 *Read_ptr;
    const uint8 *Write_ptr;
    Fls_ContextType *pCtx;
    struct spi_nor *nor;
    Fls_SectorConfigType *sectorCfg;
} Fls_InfoType;

#define FLS_START_SEC_VAR_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

static MemIf_StatusType      Fls_stGlobal = MEMIF_UNINIT;

#define FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

const Fls_ConfigType *Fls_ConfigPtr;
static MemIf_JobResultType   Fls_JobResult;
static Fls_InfoType Fls_PendingJob;
static uint8  Fls_stCancel;
#if ((FLS_COMPARE_API == STD_ON) || (FLS_BLANK_CHECK_API == STD_ON) || (FLS_WRITE_VERIFICATION_ENABLED == STD_ON) || (FLS_ERASE_VERIFICATION_ENABLED == STD_ON))
static uint8 out_buf_v1[FLS_MAX_STACK_BUFFER_SIZE] ALIGNED(32);
#endif

#define FLS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"

/* local supporting functions*/
static Fls_ContextType* Fls_GetDevice(Fls_AddressType BeginAddress, Fls_LengthType Len);

static boolean Fls_CheckConfiguration(const Fls_ConfigType *ConfigPtr);
#if (FLS_ADDRESS_ALIGNED_CHECK_ENABLED == STD_ON)
static boolean Fls_CheckSectorAlign(Fls_AddressType addr, const Fls_SectorConfigType *sectorCfg);
static boolean Fls_CheckSectorEndAlign(Fls_AddressType addr, const Fls_SectorConfigType *sectorCfg);
static boolean Fls_CheckPageAlign(Fls_AddressType addr, const Fls_SectorConfigType *sectorCfg);
static boolean Fls_CheckPageEndAlign(Fls_AddressType addr, const Fls_SectorConfigType *sectorCfg);
#endif
static void Fls_ResetOrders(void);
static void Fls_Job_End(Fls_stReturnInfo stRet);
static Std_ReturnType Fls_Job_Prepare(Fls_AddressType TargetAddress, Fls_LengthType Length, uint8 ApiId);

/* Functions which call the Hardware Driver callbacks*/
static Fls_stReturnInfo Fls_Write_proc(void);
static Fls_stReturnInfo Fls_Erase_proc(void);
static Fls_stReturnInfo Fls_Read_Proc(void);
#if (FLS_COMPARE_API == STD_ON)
static Fls_stReturnInfo Fls_Compare_Proc(void);
#endif
#if (FLS_BLANK_CHECK_API == STD_ON)
static Fls_stReturnInfo Fls_BlankCheck_proc(void);
#endif
#if (FLS_CANCEL_API == STD_ON)
static Fls_stReturnInfo Fls_Cancel_proc(void);
#endif

/******************************************************************************
** Service name        : Fls_Init                                              **
** Parameters (in)     : ConfigPtr  Pointer to flash driver configuration set  **
** Parameters (out)    : None                                                  **
** Return value        : None                                                  **
** Description         : Initializes the Flash Driver                          **
******************************************************************************/
void Fls_Init(const Fls_ConfigType *ConfigPtr )
{
    Std_ReturnType stReturn = E_NOT_OK;
    uint8 idexController;
    uint8 idxSector;
    Fls_LengthType TotalSize = 0;

    if (Fls_stGlobal != MEMIF_UNINIT ) {
        Det_ReportError(FLS_MODULE_ID, 0, FLS_INIT_ID, FLS_E_PARAM_CONFIG);
        return;
    } else if (ConfigPtr == NULL_PTR) {
        Det_ReportError(FLS_MODULE_ID, 0, FLS_INIT_ID, FLS_E_PARAM_POINTER);
        return;
    } else if (FALSE == Fls_CheckConfiguration(ConfigPtr)) {
        Det_ReportError(FLS_MODULE_ID, 0, FLS_INIT_ID, FLS_E_PARAM_CONFIG);
        return;
    }

    /* initialize all flash hardware devices */
    for (idexController = 0; idexController < ConfigPtr->NumberOfController; idexController++) {
        Fls_ContextType *pCtx = ConfigPtr->OSPIController[idexController].FlsPrivateData;
        board_norflash_init(&pCtx->host, &ConfigPtr->OSPIController[idexController].HostConfig);
        if (pCtx->ops && pCtx->ops->fls_init) {
            for (uint8 i = 0; i < PORT_MAX_FLASH_NUM; i++) {
                stReturn = pCtx->ops->fls_init(&pCtx->nor[i], &pCtx->host, &ConfigPtr->OSPIController[idexController].HostConfig);
                if (stReturn != E_OK) {
                    break;
                }
                pCtx->nor[i].info.reg_offset = pCtx->TotalSize;
                pCtx->TotalSize += pCtx->nor[i].info.size;
                pCtx->FlashNum++;
                if (ConfigPtr->OSPIController[idexController].HostConfig.dev_mode != SPI_NOR_DEV_SWITCH_MODE) {
                    break;
                }
            }
            if (stReturn != E_OK) {
                break;
            }
        } else {
          stReturn = E_NOT_OK;
          break;
        }
        pCtx->FlsBaseAddr = TotalSize;
        TotalSize += pCtx->TotalSize;

        /* bind sector & fls context */
        for (idxSector = 0; idxSector < ConfigPtr->Flash.FlsSectorListSize; idxSector++) {
            Fls_SectorConfigType *Sector = &(ConfigPtr->Flash.FlsSectorList[idxSector]);
            Fls_AddressType Addr = Sector->FlsSectorStartAddr + FLS_BASE_ADDRESS;
            if ((Sector->ControllerIndex < 0)
                && (Addr >= pCtx->FlsBaseAddr)
                && ((Addr + Sector->FlsTotalSize) <= (pCtx->FlsBaseAddr + pCtx->TotalSize))) {
                Sector->ControllerIndex = pCtx->index;
                break;
            }
        }
    }

    Fls_ResetOrders ();

    if (stReturn == E_OK) {
        Fls_stGlobal    = MEMIF_IDLE;
        Fls_ConfigPtr = ConfigPtr;
    }

    Fls_JobResult   = MEMIF_JOB_OK;
    Fls_stCancel    = FLS_NOT_REQUESTED_CANCEL;
#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
    /* Enable timeout handling */
    Fls_StateType  *StatePtr;
    /* Initialise Local variables */
    StatePtr = Fls_ConfigPtr->Flash.FlsStateVarPtr;
    StatePtr->FlsTimeoutControl = 1U;
#endif /* FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON */

}

// #define CONFIG_NORFLASH_TESTER
#ifdef CONFIG_NORFLASH_TESTER
uint8 count[SPI_NOR_SECTOR_TYPE_MAX] = { 0 };
#endif

/******************************************************************************
** Service name        : Fls_Erase                                              **
** Parameters (in)     : Fls_AddressType TargetAddress: Target address in flash **
**                                                   memory                     **
**                      Fls_LengthType Length: Number of bytes to erase         **
** Parameters (out)    : None                                                   **
** Return value        : Std_ReturnType E_OK: erase command has been accepted   **
**                                   E_NOT_OK: erase command has not been       **
**                                               accepted                       **
** Description         : Erases flash sector(s)                                 **
******************************************************************************/
Std_ReturnType Fls_Erase(   Fls_AddressType TargetAddress,
                            Fls_LengthType Length )
{
    Std_ReturnType ret = Fls_Job_Prepare(TargetAddress, Length, FLS_ERASE_ID);

    if (ret == E_OK) {
#if (FLS_ADDRESS_ALIGNED_CHECK_ENABLED == STD_ON)

        if (FALSE == Fls_CheckSectorAlign(TargetAddress, Fls_PendingJob.sectorCfg)) {
            Det_ReportError(FLS_MODULE_ID, 0, FLS_ERASE_ID, FLS_E_PARAM_ADDRESS);
            Fls_Job_End(FLS_ERROR_E);
            return E_NOT_OK;
        } else if ((Length <= 0U)
                || (FALSE == Fls_CheckSectorEndAlign(TargetAddress + Length - 1U, Fls_PendingJob.sectorCfg))) {
            Det_ReportError(FLS_MODULE_ID, 0, FLS_ERASE_ID, FLS_E_PARAM_LENGTH);
            Fls_Job_End(FLS_ERROR_E);
            return E_NOT_OK;
        }

#endif

        if (Fls_PendingJob.JobType == FLS_NONE) {
            Fls_stGlobal     = MEMIF_BUSY;
        } else {
#if (FLS_CANCEL_API == STD_ON)

            if (Fls_stCancel == FLS_REQUESTED_CANCEL) {
            } else
#endif
            {
                /* Enable Interrupts*/
                return E_NOT_OK;
            }
        }

        Fls_JobResult  = MEMIF_JOB_PENDING;
        Fls_stCancel = FLS_NOT_REQUESTED_CANCEL;
        Fls_PendingJob.JobType       = FLS_ERASE;
        Fls_PendingJob.JobStatus     = FLS_IDLE_E;
#ifdef CONFIG_NORFLASH_TESTER
        mini_memclr_s(count, sizeof(count));
#endif


#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
        Fls_StateType  *StatePtr;
        /* Initialise Local variables */
        StatePtr = Fls_ConfigPtr->Flash.FlsStateVarPtr;

        if (StatePtr->FlsTimeoutControl != 0U) {
            /* Update Timeout count for erase */
            StatePtr->FlsEraseTimeoutCycleCount = (uint32)(FLS_ERASE_TIME / Fls_ConfigPtr->Flash.FlsCallCycle);

            if ((FLS_ERASE_TIME % Fls_ConfigPtr->Flash.FlsCallCycle) != 0U) {
                StatePtr->FlsEraseTimeoutCycleCount++;
            }
        }

#endif /* FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON */
    }

    return ret;
}

/******************************************************************************
** Service name        : Fls_Write                                              **
** Parameters (in)     : Fls_AddressType TargetAddress: Target address in flash **
**                                                   memory                     **
**                      uint8* SourceAddressPtr: Pointer to source data buffer  **
**                      Fls_LengthType Length: Number of bytes to write         **
** Parameters (out)    : None                                                   **
** Return value        : Std_ReturnType E_OK: write command has been accepted   **
**                                   E_NOT_OK: write command has not been       **
**                                               accepted                       **
** Description        : Writes one or more complete flash page                  **
******************************************************************************/
Std_ReturnType Fls_Write(   Fls_AddressType TargetAddress,
                            const uint8 *SourceAddressPtr,
                            Fls_LengthType Length)
{
    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR == SourceAddressPtr) {
        Det_ReportError(FLS_MODULE_ID, 0, FLS_WRITE_ID, FLS_E_PARAM_DATA);
        Fls_Job_End(FLS_ERROR_E);
        return ret;
    }

    ret = Fls_Job_Prepare(TargetAddress, Length, FLS_WRITE_ID);
    if (ret == E_OK) {
#if (FLS_ADDRESS_ALIGNED_CHECK_ENABLED == STD_ON)

        if (FALSE == Fls_CheckPageAlign(TargetAddress, Fls_PendingJob.sectorCfg)) {
            Det_ReportError(FLS_MODULE_ID, 0, FLS_WRITE_ID, FLS_E_PARAM_ADDRESS);
            Fls_Job_End(FLS_ERROR_E);
            return E_NOT_OK;
        } else if ((Length <= 0U)
                || (FALSE == Fls_CheckPageEndAlign(TargetAddress + Length - 1U, Fls_PendingJob.sectorCfg))) {
            Det_ReportError(FLS_MODULE_ID, 0, FLS_WRITE_ID, FLS_E_PARAM_LENGTH);
            Fls_Job_End(FLS_ERROR_E);
            return E_NOT_OK;
        }

#endif
        if (Fls_PendingJob.JobType == FLS_NONE) {
            Fls_stGlobal     = MEMIF_BUSY;
        } else {
#if (FLS_CANCEL_API == STD_ON)

            if (Fls_stCancel == FLS_REQUESTED_CANCEL) {
            } else
#endif
            {
                /* Enable Interrupts*/
                return E_NOT_OK;
            }
        }
        Fls_JobResult  = MEMIF_JOB_PENDING;
        Fls_stCancel = FLS_NOT_REQUESTED_CANCEL;
        Fls_PendingJob.Write_ptr     = SourceAddressPtr;
        Fls_PendingJob.JobType       = FLS_WRITE;
        Fls_PendingJob.numBytestoWrite = 0U;
        Fls_PendingJob.numBytesWriteDone = 0U;
        Fls_PendingJob.JobStatus     = FLS_IDLE_E;
#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
        Fls_StateType  *StatePtr;
        /* Initialise Local variables */
        StatePtr = Fls_ConfigPtr->Flash.FlsStateVarPtr;

        if (StatePtr->FlsTimeoutControl != 0U) {
            /* Update Timeout count for erase */
            StatePtr->FlsWriteTimeoutCycleCount =
                (uint32)(FLS_WRITE_TIME / Fls_ConfigPtr->Flash.FlsCallCycle);

            if ((FLS_WRITE_TIME % Fls_ConfigPtr->Flash.FlsCallCycle) != 0U) {
                StatePtr->FlsWriteTimeoutCycleCount++;
            }
        }

#endif /* FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON */
    }

    return ret;
}

/******************************************************************************
** Service name        : Fls_Read                                               **
** Parameters (in)     : Fls_AddressType SourceAddress :Source address in flash **
**                                                      memory                  **
**                      uint8* TargetAddressPtr :Pointer to target data buffer  **
**                    Fls_LengthType Length : Number of bytes to read           **
** Parameters (out)    : None                                                   **
** Return value        : Std_ReturnType ( E_OK / E_NOT_OK )                     **
** Description         : Reads from flash memory                                **
******************************************************************************/
Std_ReturnType Fls_Read(    Fls_AddressType SourceAddress,
                            uint8 *TargetAddressPtr,
                            Fls_LengthType Length)
{
    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR == TargetAddressPtr) {
        Det_ReportError(FLS_MODULE_ID, 0, FLS_READ_ID, FLS_E_PARAM_DATA);
        Fls_Job_End(FLS_ERROR_E);
        return ret;
    }

    ret = Fls_Job_Prepare(SourceAddress, Length, FLS_READ_ID);
    if (ret == E_OK) {
        if (Fls_PendingJob.JobType == FLS_NONE) {
            Fls_stGlobal     = MEMIF_BUSY;
        } else {
#if (FLS_CANCEL_API == STD_ON)

            if (Fls_stCancel == FLS_REQUESTED_CANCEL) {
            } else
#endif
            {
                /* Enable Interrupts*/
                return E_NOT_OK;
            }
        }
        Fls_JobResult  = MEMIF_JOB_PENDING;
        Fls_stCancel = FLS_NOT_REQUESTED_CANCEL;
        Fls_PendingJob.Read_ptr      = TargetAddressPtr;
        Fls_PendingJob.JobType       = FLS_READ;
    }

    return ret;
}

/******************************************************************************
** Service name        : Fls_Compare                                            **
** Parameters (in)     : Fls_AddressType SourceAddress                          **
**                      const uint8* TargetAddressPtr                           **
**                    Fls_LengthType Length    : Number of bytes to compare     **
** Parameters (out)    : None                                                   **
** Return value        : Std_ReturnType ( E_OK / E_NOT_OK )                     **
** Description        : Compares the contents of an area of flash memory with   **
**                    that of an application data buffer                        **
******************************************************************************/
#if (FLS_COMPARE_API == STD_ON)
Std_ReturnType Fls_Compare(  Fls_AddressType SourceAddress,
                             const uint8 *TargetAddressPtr,
                             Fls_LengthType Length
                          )
{
    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR == TargetAddressPtr) {
        Det_ReportError(FLS_MODULE_ID, 0, FLS_COMPARE_ID, FLS_E_PARAM_DATA);
        Fls_Job_End(FLS_ERROR_E);
        return ret;
    }

    ret = Fls_Job_Prepare(SourceAddress, Length, FLS_COMPARE_ID);
    if (ret == E_OK) {
        if (Fls_PendingJob.JobType == FLS_NONE) {
            Fls_stGlobal     = MEMIF_BUSY;
        } else {
#if (FLS_CANCEL_API == STD_ON)

            if (Fls_stCancel == FLS_REQUESTED_CANCEL) {
            } else
#endif
            {
                /* Enable Interrupts*/
                return E_NOT_OK;
            }
        }
        Fls_JobResult  = MEMIF_JOB_PENDING;
        Fls_stCancel = FLS_NOT_REQUESTED_CANCEL;
        Fls_PendingJob.Read_ptr      = TargetAddressPtr;
        Fls_PendingJob.JobType       = FLS_COMPARE;
    }

    return ret;
}
#endif

/******************************************************************************
** Service name        : Fls_BlankCheck                                         **
** Parameters (in)     : Fls_AddressType TargetAddress                          **
**                    Fls_LengthType Length    : Number of bytes to compare     **
** Parameters (out)    : None                                                   **
** Return value        : Std_ReturnType ( E_OK / E_NOT_OK )                     **
** Description         : The function Fls_BlankCheck shall verify, whether a    **
                      given memory area has been erased but not (yet)           **
                      programmed.                                               **
******************************************************************************/
#if (FLS_BLANK_CHECK_API == STD_ON)
Std_ReturnType Fls_BlankCheck( Fls_AddressType TargetAddress,
                               Fls_LengthType Length
                             )
{
    Std_ReturnType ret = E_NOT_OK;

    ret = Fls_Job_Prepare(TargetAddress, Length, FLS_BLANKCHECK_ID);
    if (ret == E_OK) {

        if (Fls_PendingJob.JobType == FLS_NONE) {
            Fls_stGlobal     = MEMIF_BUSY;
        } else {
            if (Fls_stCancel == FLS_REQUESTED_CANCEL) {
            } else {
                return E_NOT_OK;
            }
        }
        Fls_JobResult  = MEMIF_JOB_PENDING;
        Fls_stCancel = FLS_NOT_REQUESTED_CANCEL;
        Fls_PendingJob.JobType = FLS_BLANKCHECK;
    }


    return ret;
}
#endif

/******************************************************************************
** Service name        : Fls_Cancel                                             **
** Parameters (in)     : None                                                   **
** Parameters (out)    : None                                                   **
** Return value        : None                                                   **
** Description         : Cancels an ongoing job                                 **
******************************************************************************/
#if (FLS_CANCEL_API == STD_ON)
void Fls_Cancel( void )
{
    if (MEMIF_UNINIT == Fls_stGlobal) {
        Det_ReportError(FLS_MODULE_ID, 0, FLS_CANCEL_ID, FLS_E_UNINIT);
        Fls_Job_End(FLS_ERROR_E);
        return;
    } else {
        /* Disable Interrupts*/
        if (Fls_JobResult == MEMIF_JOB_PENDING) {
            Fls_stCancel = FLS_REQUESTED_CANCEL;
            Fls_JobResult = MEMIF_JOB_CANCELED;
        }
        const Fls_Flash_ConfigType *pFlash =
                    (Fls_PendingJob.pCtx != NULL_PTR) ?
                    Fls_PendingJob.pCtx->FlashConfig : NULL_PTR;
        if (FLS_OK_E == Fls_Cancel_proc()) {
            if (pFlash != NULL_PTR) {
                pFlash->FlsProgDesc->FlsJobErrorNotification();
            }
        }
    }
}
#endif

/******************************************************************************
** Service name        : Fls_GetStatus                                          **
** Parameters (in)     : None                                                   **
** Parameters (out)    : None                                                   **
** Return value        : MemIf_StatusType                                       **
** Description         : Returns the driver state                               **
******************************************************************************/
#if (STD_ON == FLS_GET_STATUS_API)
MemIf_StatusType Fls_GetStatus( void )
{
    MemIf_StatusType status;

    if (MEMIF_UNINIT == Fls_stGlobal) {
        status = MEMIF_UNINIT;
    } else {
        status = Fls_stGlobal;
    }

    return status;
}
#endif

/******************************************************************************
** Service name        : Fls_GetJobResult                                       **
** Parameters (in)     : None                                                   **
** Parameters (out)    : None                                                   **
** Return value        : MemIf_JobResultType                                    **
** Description         : Returns the result of the last job                     **
******************************************************************************/
#if (STD_ON == FLS_GET_JOB_RESULT_API)
MemIf_JobResultType Fls_GetJobResult( void )
{
    MemIf_JobResultType jobResult;

    if (MEMIF_UNINIT == Fls_stGlobal) {
        jobResult = MEMIF_JOB_FAILED;
        Det_ReportError(FLS_MODULE_ID, 0, FLS_GET_JOB_RESULT_ID, FLS_E_UNINIT);
    } else {
        jobResult = Fls_JobResult;
    }

    return jobResult;
}
#endif

/******************************************************************************
** Service name        : Fls_SetMode                                            **
** Parameters (in)     : MemIf_ModeType Mode (Mode MEMIF_MODE_SLOW /            **
**                                         MEMIF_MODE_FAST)                     **
** Parameters (out)    : None                                                   **
** Return value        : void                                                   **
** Description        : Sets the flash driver's operation mode                  **
********** *******************************************************************/
#if (FLS_SET_MODE_API == STD_ON)
void Fls_SetMode( MemIf_ModeType Mode )
{
    if ( !(Fls_stGlobal != MEMIF_UNINIT ) ) {
        Det_ReportError(FLS_MODULE_ID, 0, FLS_SET_MODE_ID, FLS_E_UNINIT);
        return;
    } else if ( !(Fls_stGlobal != MEMIF_BUSY) ) {
        Det_ReportError(FLS_MODULE_ID, 0, FLS_SET_MODE_ID, FLS_E_BUSY);
        return;
    } else if (Fls_PendingJob.pCtx == NULL_PTR) {
        Det_ReportError(FLS_MODULE_ID, 0, FLS_SET_MODE_ID, FLS_E_PARAM_POINTER);
        return;
    }

    const Fls_Flash_ConfigType *pFlash = Fls_PendingJob.pCtx->FlashConfig;
    Fls_PendingJob.pCtx->MemIfMode = Mode;
    if (MEMIF_MODE_SLOW == Mode) {
        Fls_PendingJob.pCtx->MaxNumBytesRead = pFlash->FlsMaxReadNormalMode;
        Fls_PendingJob.pCtx->MaxNumBytesWrite = pFlash->FlsMaxWriteNormalMode;
    } else {
        Fls_PendingJob.pCtx->MaxNumBytesRead = pFlash->FlsMaxReadFastMode;
        Fls_PendingJob.pCtx->MaxNumBytesWrite = pFlash->FlsMaxWriteFastMode;
    }
}
#endif

/******************************************************************************
** Service name        : Fls_GetVersionInfo                                     **
** Parameters (in)     : Std_VersionInfoType Pointer to version structure       **
** Parameters (out)    : None                                                   **
** Return value        : void                                                   **
** Description        : Sets the flash driver's operation mode                  **
********** *******************************************************************/
#if ( FLS_VERSION_INFO_API == STD_ON )
void Fls_GetVersionInfo( Std_VersionInfoType *VersioninfoPtr )
{
    if (VersioninfoPtr == NULL_PTR) {
        /* Lin transceiver not initialized*/
        Det_ReportError(FLS_MODULE_ID, 0, FLS_GET_VERSION_INFO_ID, FLS_E_PARAM_POINTER);
        return ;
    }

    VersioninfoPtr->vendorID = 0x8c;
    VersioninfoPtr->moduleID = FLS_MODULE_ID;
    VersioninfoPtr->sw_major_version = FLS_SW_MAJOR_VERSION;
    VersioninfoPtr->sw_minor_version = FLS_SW_MINOR_VERSION;
    VersioninfoPtr->sw_patch_version = FLS_SW_PATCH_VERSION;
}
#endif

/******************************************************************************
** Service name        : Fls_MainFunction                                       **
** Parameters (in)     : None                                                   **
** Parameters (out)    : None                                                   **
** Return value        : None                                                   **
** Description        : Performs the processing of jobs                         **
******************************************************************************/
void Fls_MainFunction( void )
{
    Fls_stReturnInfo stRet;

    if (MEMIF_UNINIT == Fls_stGlobal) {
        Det_ReportError(FLS_MODULE_ID, 0, FLS_MAIN_FUNCTION_ID, FLS_E_UNINIT);
        return;
    }

#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
    uint8 ErrorTimeoutFlag;
    ErrorTimeoutFlag = Fls_TimeOut(FLS_TIMEOUT_ID);

    if (ErrorTimeoutFlag == E_OK)
#endif  /* #if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON) */
    {
        if (MEMIF_JOB_PENDING == Fls_JobResult) {
            switch (Fls_PendingJob.JobType) {
            case FLS_WRITE: {
                stRet = Fls_Write_proc();
#if (FLS_CANCEL_API == STD_ON)

                if ((Fls_stCancel == FLS_REQUESTED_CANCEL) && (stRet != FLS_WRITE_E)) {
                    Fls_stCancel = FLS_NOT_REQUESTED_CANCEL;
                } else
#endif
                    if (stRet == FLS_BUSY_E) {
                        /* Do nothing. */
                    } else {
                        Fls_Job_End(stRet);
                    }

                break;
            }

            case FLS_ERASE: {
                stRet = Fls_Erase_proc();
#if (FLS_CANCEL_API == STD_ON)

                if ((Fls_stCancel == FLS_REQUESTED_CANCEL) && (stRet != FLS_ERASE_E)) {
                    Fls_stCancel = FLS_NOT_REQUESTED_CANCEL;
                } else
#endif
                    if (stRet == FLS_BUSY_E) {
                        /* Do nothing. */
                    } else {
                        Fls_Job_End(stRet);
                    }

                break;
            }

#if (FLS_COMPARE_API == STD_ON)

            case FLS_COMPARE: {
                stRet = Fls_Compare_Proc();
#if (FLS_CANCEL_API == STD_ON)

                if ((Fls_stCancel == FLS_REQUESTED_CANCEL) && (stRet != FLS_COMPARE_E )) {
                    Fls_stCancel = FLS_NOT_REQUESTED_CANCEL;
                } else
#endif
                {
                    Fls_Job_End(stRet);
                }

                break;
            }

#endif  /* FLS_COMPARE_API == STD_ON */

            case FLS_READ: {
                stRet = Fls_Read_Proc();
#if (FLS_CANCEL_API == STD_ON)

                if ((Fls_stCancel == FLS_REQUESTED_CANCEL) && (stRet != FLS_READ_E)) {
                    Fls_stCancel = FLS_NOT_REQUESTED_CANCEL;
                } else
#endif
                {
                    Fls_Job_End(stRet);
                }

                break;
            }

#if (FLS_BLANK_CHECK_API == STD_ON)

            case FLS_BLANKCHECK: {
                stRet = Fls_BlankCheck_proc();
#if (FLS_CANCEL_API == STD_ON)

                if ((Fls_stCancel == FLS_REQUESTED_CANCEL) && (stRet != FLS_BLANKCHECK_E)) {
                    Fls_stCancel = FLS_NOT_REQUESTED_CANCEL;
                } else
#endif
                {
                    Fls_Job_End(stRet);
                }

                break;
            }

#endif  /* FLS_BLANK_CHECK_API == STD_ON */

            case FLS_NONE:
                /* Do nothing */
                break;

            default: {
                Fls_ResetOrders();
                break;
            }
            }
        }
    }
}

static Fls_SectorConfigType *Fls_FindSectorConfig(Fls_AddressType addr)
{
    uint32 i;
    Fls_AddressType sectorStartAddr;
    Fls_LengthType totalSize;
    Fls_SectorConfigType *sectorConfig = NULL_PTR;
    const Fls_Flash_ConfigType *pFlashConfig = &(Fls_ConfigPtr->Flash);

    for (i = 0; i < pFlashConfig->FlsSectorListSize; i++) {
        sectorStartAddr = pFlashConfig->FlsSectorList[i].FlsSectorStartAddr;
        totalSize = pFlashConfig->FlsSectorList[i].FlsTotalSize;

        if ((addr >= sectorStartAddr) && (addr < (sectorStartAddr + totalSize))) {
            sectorConfig = &(pFlashConfig->FlsSectorList[i]);
            break;
        }
    }

    return sectorConfig;
}

static boolean Fls_CheckConfiguration(const Fls_ConfigType *ConfigPtr)
{
    boolean Ret = TRUE;
    uint8 ConId;
    uint8 PortInUse[FLS_CONTROLLER_ID_MAX] = { 0 };

    for (ConId = 0; ConId < ConfigPtr->NumberOfController; ConId++) {
        const Fls_OSPIController_ConfigType *pControllerConfig = &(ConfigPtr->OSPIController[ConId]);
        if ((pControllerConfig->HostConfig.dev_mode == SPI_NOR_DEV_LOCKSTEP_MODE)
            || (pControllerConfig->HostConfig.dev_mode == SPI_NOR_DEV_PARALLEL_MODE)) {
            if (pControllerConfig->ID != FLS_XSPI1_PORTA && pControllerConfig->ID != FLS_XSPI2_PORTA) {
                Ret = FALSE;
                break;
            } else if (PortInUse[pControllerConfig->ID] || PortInUse[pControllerConfig->ID + 1]) {
                Ret = FALSE;
                break;
            }
        } else if (PortInUse[pControllerConfig->ID]) {
            Ret = FALSE;
            break;
        }
        PortInUse[pControllerConfig->ID]++;

        Fls_ContextType *pCtx = pControllerConfig->FlsPrivateData;
        pCtx->ControllerConfig = pControllerConfig;
        pCtx->FlashConfig = &(ConfigPtr->Flash);
        pCtx->MemIfMode = ConfigPtr->Flash.FlsDefaultMode;
        if (MEMIF_MODE_SLOW == pCtx->MemIfMode) {
            pCtx->MaxNumBytesRead = ConfigPtr->Flash.FlsMaxReadNormalMode;
            pCtx->MaxNumBytesWrite = ConfigPtr->Flash.FlsMaxWriteNormalMode;
        } else {
            pCtx->MaxNumBytesRead = ConfigPtr->Flash.FlsMaxReadFastMode;
            pCtx->MaxNumBytesWrite = ConfigPtr->Flash.FlsMaxWriteFastMode;
        }
        for (uint8 i = 0; i < PORT_MAX_FLASH_NUM; i++) {
            mini_memclr_s(&pCtx->nor[i], sizeof(struct spi_nor));
            pCtx->nor[i].parent = pCtx;
            pCtx->nor[i].ops = pCtx->ops;
            pCtx->nor[i].cs = i;
        }
        pCtx->TotalSize = 0;
        pCtx->FlashNum = 0;
    }

    return Ret;
}

#if (FLS_ADDRESS_ALIGNED_CHECK_ENABLED == STD_ON)
static boolean Fls_CheckPageAlign(Fls_AddressType addr, const Fls_SectorConfigType *sectorCfg)
{
    boolean ret = FALSE;

    if ((NULL_PTR != sectorCfg) &&
        (0U == ((addr - sectorCfg->FlsSectorStartAddr) % sectorCfg->FlsPageSize))) {
        ret = TRUE;
    }

    return ret;
}

static boolean Fls_CheckPageEndAlign(Fls_AddressType addr, const Fls_SectorConfigType *sectorCfg)
{
    boolean ret = FALSE;

    if ((NULL_PTR != sectorCfg) &&
        (0U == ((addr + 1U - sectorCfg->FlsSectorStartAddr) % sectorCfg->FlsPageSize))) {
        ret = TRUE;
    }

    return ret;
}

static boolean Fls_CheckSectorAlign(Fls_AddressType addr, const Fls_SectorConfigType *sectorCfg)
{
    boolean ret = FALSE;

    if ((NULL_PTR != sectorCfg) &&
        (0U == ((addr - sectorCfg->FlsSectorStartAddr) % sectorCfg->FlsSectorSize))) {
        ret = TRUE;
    }

    return ret;
}

static boolean Fls_CheckSectorEndAlign(Fls_AddressType addr, const Fls_SectorConfigType *sectorCfg)
{
    boolean ret = FALSE;

    if ((NULL_PTR != sectorCfg) &&
        (0U == ((addr + 1U - sectorCfg->FlsSectorStartAddr) % sectorCfg->FlsSectorSize))) {
        ret = TRUE;
    }

    return ret;
}
#endif

static Fls_ContextType* Fls_GetDevice(Fls_AddressType BeginAddress, Fls_LengthType Len)
{
    Fls_SectorConfigType *pSector = Fls_FindSectorConfig(BeginAddress);
    if (pSector != NULL_PTR) {
        if ((pSector->ControllerIndex >= 0)
            && ((BeginAddress + Len) <= pSector->FlsSectorStartAddr + pSector->FlsTotalSize)) {
            Fls_ContextType *pCtx = Fls_ConfigPtr->OSPIController[pSector->ControllerIndex].FlsPrivateData;
            pCtx->CurrentSector = pSector;
            return pCtx;
        }
    }

    return NULL_PTR;
}

static struct spi_nor* Fls_GetFlash(Fls_ContextType *pCtx, Fls_AddressType BeginAddress, Fls_LengthType Len)
{
    for (uint8 i = 0; i < pCtx->FlashNum; i++) {
        if ((BeginAddress < (pCtx->nor[i].info.reg_offset + pCtx->nor[i].info.size)) &&
        ((BeginAddress + Len) <= (pCtx->nor[i].info.reg_offset + pCtx->nor[i].info.size))) {
            return &pCtx->nor[i];
        }
    }
    return NULL_PTR;
}

static void Fls_ResetOrders(void)
{
    Fls_PendingJob.JobType  = FLS_NONE;
    Fls_PendingJob.StartAddr  = 0;
    Fls_PendingJob.Length  = 0;
    Fls_PendingJob.numBytesDone  = 0;
    Fls_PendingJob.pCtx  = NULL_PTR;
    Fls_PendingJob.JobStatus = FLS_IDLE_E;
}

static void Fls_Job_End(Fls_stReturnInfo stRet)
{
    const Fls_Flash_ConfigType *pFlash = (Fls_PendingJob.pCtx != NULL_PTR) ?
                                        Fls_PendingJob.pCtx->FlashConfig : NULL_PTR;
    if (Fls_stCancel != FLS_REQUESTED_CANCEL) {
        if (stRet == FLS_OK_E) {
            if (Fls_PendingJob.numBytesDone >=
                Fls_PendingJob.Length) {

                if (MEMIF_JOB_PENDING == Fls_JobResult) {
                    Fls_stGlobal = MEMIF_IDLE;
                    Fls_JobResult = MEMIF_JOB_OK;
                }

                Fls_ResetOrders();

                if ((pFlash != NULL_PTR) &&
                    (pFlash->FlsProgDesc->FlsJobEndNotification != NULL_PTR)) {
                    pFlash->FlsProgDesc->FlsJobEndNotification();
                }
            } else {
                Fls_PendingJob.JobStatus = FLS_IDLE_E;
            }
        } else {
            if (FLS_COMPARE_E == stRet) {
                Fls_JobResult = MEMIF_BLOCK_INCONSISTENT;
            } else {
                Fls_JobResult = MEMIF_JOB_FAILED;
            }

            if (Fls_stGlobal != MEMIF_UNINIT) {
                Fls_stGlobal = MEMIF_IDLE;
            }
            Fls_ResetOrders();

            if ((pFlash != NULL_PTR) &&
                (pFlash->FlsProgDesc->FlsJobErrorNotification != NULL_PTR)) {
                pFlash->FlsProgDesc->FlsJobErrorNotification();
            }
        }
    }
}

static Std_ReturnType Fls_Job_Prepare(Fls_AddressType TargetAddress, Fls_LengthType Length, uint8 ApiId) {
    Std_ReturnType ret = E_OK;
    Fls_ContextType *pCtx = NULL_PTR;

    if (MEMIF_UNINIT == Fls_stGlobal) {
        Det_ReportError(FLS_MODULE_ID, 0, ApiId, FLS_E_UNINIT);
        return E_NOT_OK;
    } else if (MEMIF_BUSY == Fls_stGlobal) {
        Det_ReportError(FLS_MODULE_ID, 0, ApiId, FLS_E_BUSY);
        return E_NOT_OK;
    } else if (0u == Length) {
        Det_ReportError(FLS_MODULE_ID, 0, ApiId, FLS_E_PARAM_LENGTH);
        return E_NOT_OK;
    }

    pCtx = Fls_GetDevice(TargetAddress, Length);
    if (NULL_PTR == pCtx) {
        Det_ReportError(FLS_MODULE_ID, 0, ApiId, FLS_E_PARAM_ADDRESS);
        return E_NOT_OK;
    }

    Fls_PendingJob.StartAddr     = TargetAddress + FLS_BASE_ADDRESS - pCtx->FlsBaseAddr;
    Fls_PendingJob.Length        = Length;
    Fls_PendingJob.numBytesDone  = 0;
    Fls_PendingJob.pCtx = pCtx;
    Fls_PendingJob.sectorCfg = pCtx->CurrentSector;
    Fls_PendingJob.nor = Fls_GetFlash(pCtx, Fls_PendingJob.StartAddr, Length);
    if (NULL_PTR == Fls_PendingJob.nor) {
        Det_ReportError(FLS_MODULE_ID, 0, ApiId, FLS_E_PARAM_ADDRESS);
        return E_NOT_OK;
    }

    return ret;
}

static Fls_stReturnInfo Fls_Write_proc(void)
{
    Fls_stReturnInfo stRet = FLS_WRITE_E;
    uint32 currentStartAddr = Fls_PendingJob.StartAddr + Fls_PendingJob.numBytesDone +
                              Fls_PendingJob.numBytesWriteDone;
    const uint8 *sourceAddr = (uint8 *)&Fls_PendingJob.Write_ptr[Fls_PendingJob.numBytesDone +
                                                          Fls_PendingJob.numBytesWriteDone];
    uint32 residualSize = Fls_PendingJob.Length - Fls_PendingJob.numBytesDone;
    int stDriverReturn;
    uint32 write_size = 0U;

    /* Get flash status */
    stRet = Fls_PendingJob.pCtx->ops->fls_busy_status(Fls_PendingJob.nor) == 0U ? FLS_OK_E : FLS_BUSY_E;

    if (FLS_OK_E == stRet) {
        switch (Fls_PendingJob.JobStatus) {
        case FLS_IDLE_E : {
            if (0U == Fls_PendingJob.numBytestoWrite) {
                if (residualSize > Fls_PendingJob.pCtx->MaxNumBytesWrite) {
                    residualSize = Fls_PendingJob.pCtx->MaxNumBytesWrite;
                }

                Fls_PendingJob.numBytestoWrite = residualSize;
            }

            Fls_PendingJob.JobStatus = FLS_CMD_SEND_E;
            stRet = FLS_BUSY_E;
            break;
        }

        case FLS_CMD_SEND_E : {
            if (Fls_PendingJob.numBytesWriteDone < Fls_PendingJob.numBytestoWrite) {
                write_size = _MIN((Fls_PendingJob.nor->info.page_size - currentStartAddr % Fls_PendingJob.nor->info.page_size),
                                 Fls_PendingJob.numBytestoWrite - Fls_PendingJob.numBytesWriteDone);

#if (FLS_ERASE_VERIFICATION_ENABLED == STD_ON)
                Std_ReturnType EraseRet = Fls_EraseVerification(currentStartAddr, write_size);

                if (EraseRet != E_OK) {
                    Det_ReportRuntimeError(FLS_MODULE_ID, 0, FLS_WRITE_ID, FLS_E_VERIFY_ERASE_FAILED);
                    stRet = FLS_WRITE_E;
                    return stRet;
                }

#endif  /* FLS_ERASE_VERIFICATION_ENABLED == STD_ON */

                stDriverReturn = Fls_PendingJob.pCtx->ops->fls_write(Fls_PendingJob.nor,
                                 currentStartAddr,
                                 sourceAddr,
                                 write_size);

                if (0 == stDriverReturn) {
                    stRet = FLS_BUSY_E;
                    Fls_PendingJob.JobStatus = FLS_WRITE_DONE_E;
                } else {
                    Det_ReportTransientFault(FLS_MODULE_ID, 0, FLS_WRITE_ID, FLS_E_WRITE_FAILED);
                    stRet = FLS_WRITE_E;
                }
            }

            break;
        }

        case FLS_WRITE_DONE_E : {
            write_size = _MIN((Fls_PendingJob.nor->info.page_size - currentStartAddr % Fls_PendingJob.nor->info.page_size),
                             Fls_PendingJob.numBytestoWrite - Fls_PendingJob.numBytesWriteDone);

#if (FLS_WRITE_VERIFICATION_ENABLED == STD_ON)
            Std_ReturnType WriteRet = Fls_WriteVerification(currentStartAddr,
                                         sourceAddr,
                                         write_size);

            if (WriteRet != E_OK) {
                Det_ReportRuntimeError(FLS_MODULE_ID, 0, FLS_WRITE_ID, FLS_E_VERIFY_WRITE_FAILED);
                return FLS_WRITE_E;
            }

#endif  /* FLS_WRITE_VERIFICATION_ENABLED == STD_ON */

            Fls_PendingJob.numBytesWriteDone += write_size;

            if (Fls_PendingJob.numBytesWriteDone < Fls_PendingJob.numBytestoWrite) {
                Fls_PendingJob.JobStatus = FLS_CMD_SEND_E;
                stRet = FLS_BUSY_E;
            } else {
                Fls_PendingJob.numBytesDone += Fls_PendingJob.numBytesWriteDone;
                Fls_PendingJob.numBytesWriteDone = 0U;
                Fls_PendingJob.numBytestoWrite = 0U;
                Fls_PendingJob.JobStatus = FLS_OK_E;
                stRet = FLS_OK_E;
            }

            break;
        }

        default:
            break;
        }
    }

    return stRet;
}

/******************************************************************************
** Service name        : Fls_Erase_proc                                         **
** Parameters (in)     : None                                                   **
** Parameters (out)    : None                                                   **
** Return value        : None                                                   **
** Description         : To erase a sector, we suppose the start address        **
                        and the sector size of user configured is aligned.      **
******************************************************************************/
static Fls_stReturnInfo Fls_Erase_proc(void)
{
    Fls_stReturnInfo stRet = FLS_ERROR_E;
    uint32 currentStartAddr = Fls_PendingJob.StartAddr + Fls_PendingJob.numBytesDone;
    int stDriverReturn;

    /* Get flash status */
    stRet = Fls_PendingJob.pCtx->ops->fls_busy_status(Fls_PendingJob.nor) == 0U ? FLS_OK_E : FLS_BUSY_E;

    if (FLS_OK_E == stRet) {
        switch (Fls_PendingJob.JobStatus) {
        case FLS_IDLE_E : {
            /* Only one sector can be erased in one call cycle.*/
            do {
                if (!Fls_PendingJob.nor->hyperbus_mode) {  // spi nor flash need to change erases sector dynamically
                    for (int i = SPI_NOR_SECTOR_TYPE_MAX - 1; i >= 0; i--) {
                        if ((Fls_PendingJob.nor->info.erase_proto[i] != 0)
                            && (IS_ALIGNED(currentStartAddr, SECTOR_TYPE_TO_SIZE(i)))
                            && ((Fls_PendingJob.Length - Fls_PendingJob.numBytesDone) >> SECTOR_TYPE_TO_POST(i))) {
                            Fls_PendingJob.nor->info.sector_size = SECTOR_TYPE_TO_SIZE(i);
                            Fls_PendingJob.nor->info.sector_type = (spi_nor_sector_type)i;
                            break;
                        }
                    }
                }

                /*To erase a sector*/
                stDriverReturn = Fls_PendingJob.pCtx->ops->fls_erase(Fls_PendingJob.nor,
                                 currentStartAddr, Fls_PendingJob.nor->info.sector_size);

                if (stDriverReturn == 0) {
                    stRet = FLS_BUSY_E;
                    Fls_PendingJob.JobStatus = FLS_CMD_SEND_E;
                } else {
                    if (stDriverReturn != 1) {
                        stRet = FLS_ERASE_E;
                        break;
                    }
                }

            } while (0);

            break;
        }

        case FLS_CMD_SEND_E : {
#if (FLS_ERASE_VERIFICATION_ENABLED == STD_ON)

            if (Fls_EraseVerification(currentStartAddr, Fls_PendingJob.nor->info.sector_size) != E_OK) {
                Det_ReportRuntimeError(FLS_MODULE_ID, 0, FLS_ERASE_ID, FLS_E_VERIFY_ERASE_FAILED);
                stRet = FLS_ERASE_E;
            }

#endif
            Fls_PendingJob.numBytesDone += Fls_PendingJob.nor->info.sector_size;
            Fls_PendingJob.JobStatus = FLS_OK_E;
#ifdef CONFIG_NORFLASH_TESTER
            count[Fls_PendingJob.nor->info.sector_type]++;
            DBG(">>>>4k:%d, 32k:%d, 64k:%d, 128k:%d, 256k:%d<<<<\n",
                count[0], count[1], count[2], count[3], count[4]);
#endif
        }

        default:
            break;
        }

    }

    if ((stRet != FLS_OK_E) && (stRet != FLS_BUSY_E)) {
        Det_ReportTransientFault(FLS_MODULE_ID, 0, FLS_ERASE_ID, FLS_E_ERASE_FAILED);
    }

    return stRet;
}

static Fls_stReturnInfo Fls_Read_Proc(void)
{
    Fls_stReturnInfo stRet;
    uint32 currentStartAddr = Fls_PendingJob.StartAddr + Fls_PendingJob.numBytesDone;
    uint8 *targetAddr = (uint8 *)&Fls_PendingJob.Read_ptr[Fls_PendingJob.numBytesDone];
    uint32 residualSize = Fls_PendingJob.Length - Fls_PendingJob.numBytesDone;
    int returnVal;

    if (residualSize > Fls_PendingJob.pCtx->MaxNumBytesRead) {
        residualSize = Fls_PendingJob.pCtx->MaxNumBytesRead;
    }

    returnVal = Fls_PendingJob.pCtx->ops->fls_read(Fls_PendingJob.nor,
                currentStartAddr,
                targetAddr,
                residualSize);

    if (returnVal == 0) {
        Fls_PendingJob.numBytesDone += residualSize;
        stRet = FLS_OK_E;
    } else {
        Det_ReportTransientFault(FLS_MODULE_ID, 0, FLS_READ_ID, FLS_E_READ_FAILED);
        stRet = FLS_READ_E;
    }

    return stRet;
}

#if (FLS_COMPARE_API == STD_ON)
static Fls_stReturnInfo Fls_Compare_Proc(void)
{
    uint32 currentStartAddr = Fls_PendingJob.StartAddr + Fls_PendingJob.numBytesDone;
    uint32 bytesDone = Fls_PendingJob.numBytesDone;
    uint32 residualSize = Fls_PendingJob.Length - Fls_PendingJob.numBytesDone;
    uint32 this_step_length;
    uint32 done_length = 0;
    Fls_stReturnInfo stRet = FLS_OK_E;
    int returnVal;

    if (residualSize > Fls_PendingJob.pCtx->MaxNumBytesRead) {
        residualSize = Fls_PendingJob.pCtx->MaxNumBytesRead;
    }

    Fls_PendingJob.numBytesDone += residualSize;

    do {
        if (residualSize <= FLS_MAX_STACK_BUFFER_SIZE) {
            this_step_length = residualSize;
            residualSize = 0;
        } else {
            residualSize -= FLS_MAX_STACK_BUFFER_SIZE;
            this_step_length = FLS_MAX_STACK_BUFFER_SIZE;
        }

        returnVal = Fls_PendingJob.pCtx->ops->fls_read(Fls_PendingJob.nor,
                    (uint32)currentStartAddr + done_length,
                    (uint8 *)out_buf_v1,
                    this_step_length);

        if (returnVal != 0) {
            stRet = FLS_COMPARE_E;
            break;
        }

        for (uint32 i = 0; i < this_step_length; i++) {
            if (out_buf_v1[i] != Fls_PendingJob.Read_ptr[bytesDone + done_length + i]) {
                stRet = FLS_COMPARE_E;
                returnVal = -1;
                break;
            }
        }

        done_length += this_step_length;
    } while ((residualSize > 0U) && (returnVal == 0));

    if (FLS_OK_E != stRet) {
        Det_ReportTransientFault(FLS_MODULE_ID, 0, FLS_COMPARE_ID, FLS_E_COMPARE_FAILED);
    }

    return stRet;
}
#endif  /* FLS_COMPARE_API == STD_ON */

#if (FLS_BLANK_CHECK_API == STD_ON)
static Fls_stReturnInfo Fls_BlankCheck_proc(void)
{
    uint32 currentStartAddr = Fls_PendingJob.StartAddr + Fls_PendingJob.numBytesDone;
    uint32 residualSize = Fls_PendingJob.Length - Fls_PendingJob.numBytesDone;
    uint32 this_step_length;
    uint32 done_length = 0;
    Fls_stReturnInfo stRet = FLS_OK_E;
    int returnVal;

    if (residualSize > Fls_PendingJob.pCtx->MaxNumBytesRead) {
        residualSize = Fls_PendingJob.pCtx->MaxNumBytesRead;
    }

    Fls_PendingJob.numBytesDone += residualSize;

    do {
        if (residualSize <= FLS_MAX_STACK_BUFFER_SIZE) {
            this_step_length = residualSize;
            residualSize = 0;
        } else {
            residualSize -= FLS_MAX_STACK_BUFFER_SIZE;
            this_step_length = FLS_MAX_STACK_BUFFER_SIZE;
        }

        returnVal = Fls_PendingJob.pCtx->ops->fls_read(Fls_PendingJob.nor,
                    (uint32)currentStartAddr + done_length,
                    (uint8 *)out_buf_v1,
                    this_step_length
                                                                       );

        if (returnVal != 0) {
            stRet = FLS_BLANKCHECK_E;
            break;
        }

        for (uint32 i = 0; i < this_step_length; i++) {
            if (out_buf_v1[i] != 0xffU) {
                stRet = FLS_BLANKCHECK_E;
                returnVal = -1;
                break;
            }
        }

        done_length += this_step_length;
    } while ((residualSize > 0U) && (returnVal == 0));

    if (FLS_OK_E != stRet) {
        Det_ReportTransientFault(FLS_MODULE_ID, 0, FLS_BLANKCHECK_ID, FLS_E_BLANK_CHECK_FAILED_ID);
    }

    return stRet;
}
#endif  /* FLS_BLANK_CHECK_API == STD_ON */

#if (FLS_CANCEL_API == STD_ON)
static Fls_stReturnInfo Fls_Cancel_proc(void)
{
    Fls_stReturnInfo stRet;
    int retStatus;
    retStatus = Fls_PendingJob.pCtx->ops->fls_cancel(Fls_PendingJob.nor);

    if (retStatus == 0) {
        stRet = FLS_OK_E;
    } else {
        stRet = FLS_ERROR_E;
    }

    Fls_stGlobal = MEMIF_IDLE;
    Fls_ResetOrders();

    return stRet;
}
#endif  /* FLS_CANCEL_API == STD_ON */

/******************************************************************************
** Service name        : Fls_WriteVerification                                  **
** Parameters (in)     : Fls_AddressType TargetAddress: Target address in flash **
**                                                   memory                     **
**                      uint8* SourceAddressPtr: Pointer to source data buffer  **
**                      Fls_LengthType Length: Number of bytes to write         **
** Parameters (out)    : None                                                   **
** Return value        : Std_ReturnType E_OK: write command has been accepted   **
**                                   E_NOT_OK: write command has not been       **
**                                               accepted                       **
** Description         : Verifies writen contents of complete flash page        **
******************************************************************************/
#if (FLS_WRITE_VERIFICATION_ENABLED == STD_ON)
Std_ReturnType Fls_WriteVerification(Fls_AddressType TargetAddress,
                                     const uint8 *SourceAddressPtr,
                                     Fls_LengthType Length )
{
    uint32 residualSize = Length;
    uint32 this_step_length;
    uint32 done_length = 0;
    Std_ReturnType stRet = E_OK;
    int returnVal;

    do {
        if (residualSize <= FLS_MAX_STACK_BUFFER_SIZE) {
            this_step_length = residualSize;
            residualSize = 0;
        } else {
            residualSize -= FLS_MAX_STACK_BUFFER_SIZE;
            this_step_length = FLS_MAX_STACK_BUFFER_SIZE;
        }

        returnVal = Fls_PendingJob.pCtx->ops->fls_read(Fls_PendingJob.nor,
                    TargetAddress + done_length,
                    (uint8 *)out_buf_v1,
                    this_step_length);

        if (returnVal != 0) {
            stRet = E_NOT_OK;
            break;
        }

        for (uint32 i = 0; i < this_step_length; i++) {
            if (out_buf_v1[i] != SourceAddressPtr[i + done_length]) {
                Det_ReportError(FLS_MODULE_ID, 0,  FLS_WRITE_ID, FLS_E_VERIFY_WRITE_FAILED);
                stRet = E_NOT_OK;
                returnVal = -1;
                break;
            }
        }

        done_length += this_step_length;
    } while ((residualSize > 0) && (returnVal == 0));

    return stRet;
}
#endif  /* FLS_WRITE_VERIFICATION_ENABLED == STD_ON */

/******************************************************************************
** Service name        : Fls_EraseVerification                                  **
** Parameters (in)     : Fls_AddressType TargetAddress: Target address in flash **
**                                                   memory                     **
**                      Fls_LengthType Length: Number of bytes to erase         **
** Parameters (out)    : None                                                   **
** Return value        : Std_ReturnType E_OK: erase command has been accepted   **
**                                   E_NOT_OK: erase command has not been       **
**                                               accepted                       **
** Description         : verifies  Erases of flash sector(s)                    **
******************************************************************************/
#if (FLS_ERASE_VERIFICATION_ENABLED == STD_ON)
Std_ReturnType Fls_EraseVerification(Fls_AddressType TargetAddress, Fls_LengthType Length)
{
    uint32 residualSize = Length;
    uint32 this_step_length;
    uint32 done_length = 0;
    Std_ReturnType stRet = E_OK;
    int returnVal;

    do {
        if (residualSize <= FLS_MAX_STACK_BUFFER_SIZE) {
            this_step_length = residualSize;
            residualSize = 0;
        } else {
            residualSize -= FLS_MAX_STACK_BUFFER_SIZE;
            this_step_length = FLS_MAX_STACK_BUFFER_SIZE;
        }

        returnVal = Fls_PendingJob.pCtx->ops->fls_read(Fls_PendingJob.nor,
                    (uint32)TargetAddress + done_length,
                    (uint8 *)out_buf_v1,
                    this_step_length
                                                                       );

        if (returnVal != 0) {
            stRet = E_NOT_OK;
            break;
        }

        for (uint32 i = 0; i < this_step_length; i++) {
            if (out_buf_v1[i] != 0xffU) {
                stRet = E_NOT_OK;
                returnVal = -1;
                break;
            }
        }

        done_length += this_step_length;
    } while ((residualSize > 0) && (returnVal == 0));

    return stRet;
}
#endif  /* FLS_ERASE_VERIFICATION_ENABLED == STD_ON */

/*******************************************************************************
** Syntax: static uint8 Fls_lTimeOutDET( const uint8 ServiceID )              **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : ServiceID                                                **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : ErrorFlag - DET has occured (1) or not (0)               **
**                                                                            **
** Description : This routine performs the TIMEOUT DET check                  **
*******************************************************************************/
#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
uint8 Fls_TimeOut(const uint8 ServiceID)
{
    Fls_StateType  *StatePtr;
    uint8 ErrorFlag;

    StatePtr = Fls_ConfigPtr->Flash.FlsStateVarPtr;
    ErrorFlag = E_OK;

    if (StatePtr->FlsTimeoutControl != E_OK) {
        if (Fls_PendingJob.JobType == FLS_ERASE) {
            if (StatePtr->FlsEraseTimeoutCycleCount == E_OK) {
                ErrorFlag = E_NOT_OK;
            } else {
                StatePtr->FlsEraseTimeoutCycleCount--;
            }
        }

        if (Fls_PendingJob.JobType == FLS_WRITE) {
            if (StatePtr->FlsWriteTimeoutCycleCount == E_OK) {
                ErrorFlag = E_NOT_OK;
            } else {
                StatePtr->FlsWriteTimeoutCycleCount--;
            }
        }

        if (ErrorFlag == E_NOT_OK) {
            Det_ReportError( FLS_MODULE_ID,
                             0, ServiceID,
                             FLS_E_TIMEOUT);
            /* Report to DET */
        }
    }

    return ErrorFlag;
}
#endif  /* FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON */

Std_ReturnType Fls_GetSector( Fls_AddressType TargetAddress, const Fls_SectorConfigType** SectorConfig ) {
    Fls_SectorConfigType *pSector = Fls_FindSectorConfig(TargetAddress);
    if (NULL_PTR == pSector) {
        return E_NOT_OK;
    } else {
        if (SectorConfig != NULL_PTR) {
            *SectorConfig = pSector;
        }
        return E_OK;
    }
}

#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#ifdef __cplusplus
}
#endif
