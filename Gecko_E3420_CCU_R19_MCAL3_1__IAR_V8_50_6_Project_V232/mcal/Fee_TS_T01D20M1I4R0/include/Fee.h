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

/**
 * @file  Fee.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Flash EEPROM Emulation
 */

#ifndef FEE_H
#define FEE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Compiler.h"
#include "Compiler_Cfg.h"
#include "Std_Types.h"
#include "MemIf_Types.h"
#include "Fls.h"
#include "Fee_Cfg.h"

/*****************Version Information************/
#define FEE_VENDOR_ID                   140U
#define FEE_MODULE_ID                   21U
#define FEE_INSTANCE_ID                 0U

#define FEE_AR_MAJOR_VERSION            4U
#define FEE_AR_MINOR_VERSION            3U
#define FEE_AR_PATCH_VERSION            1U

#define FEE_SW_MAJOR_VERSION            1U
#define FEE_SW_MINOR_VERSION            0U
#define FEE_SW_PATCH_VERSION            0U

/* Service id's for fee functions */
#define FEE_INIT_ID                    0x00U
#define FEE_SETMODE_ID                 0x01U
#define FEE_READ_ID                    0x02U
#define FEE_WRITE_ID                   0x03U
#define FEE_CANCEL_ID                  0x04U
#define FEE_GETSTATUS_ID               0x05U
#define FEE_GETJOBRESULT_ID            0x06U
#define FEE_INVALIDATEBLOCK_ID         0x07U
#define FEE_GETVERSIONINFO_ID          0x08U
#define FEE_ERASEIMMEDIATEBLOCK_ID     0x09U
#define FEE_JOBENDNOTIFICATION_ID      0x10U
#define FEE_JOBERRORNOTIFICATION_ID    0x11U
#define FEE_MAINFUNCTION_ID            0x12U

/*Service ID for DET reporting */
/* Development Errors */
#define FEE_E_UNINIT                  0x01U
#define FEE_E_INVALID_BLOCK_NO        0x02U
#define FEE_E_INVALID_BLOCK_OFS       0x03U
#define FEE_E_PARAM_POINTER           0x04U
#define FEE_E_INVALID_BLOCK_LEN       0x05U
#define FEE_E_INIT_FAILED             0x09U

/* Runtime Errors */
#define FEE_E_BUSY                    0x06U
#define FEE_E_INVALID_CANCEL          0x08U

/* Production Errors */
#define FEE_E_VENDOR                    0x10U
#define FEE_E_INTERNAL_BUSY             ((FEE_E_VENDOR) | 0x0U)
#define FEE_E_CANCEL_API_UNDEF          ((FEE_E_VENDOR) | 0x1U)
#define FEE_E_CFG_INVALID_BLOCK         ((FEE_E_VENDOR) | 0x2U)
#define FEE_E_NOT_VALID_BLOCK           ((FEE_E_VENDOR) | 0x3U)
#define FEE_E_PAGE_FULL                 ((FEE_E_VENDOR) | 0x4U)
#define FEE_E_INVALID_RECORD_OFS        ((FEE_E_VENDOR) | 0x5U)
#define FEE_E_INVALID_RECORD_LEN        ((FEE_E_VENDOR) | 0x6U)
#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
#define FEE_E_CHECKSUM_ERROR            ((FEE_E_VENDOR) | 0x7U)
#endif

#define FEE_BLOCK_INDEX_DEF             0xFFFFU /* default block index value */

/* Job state */
typedef enum {
    FEE_JOB_INT = 0,                        /* Initialize the Fee */
    FEE_JOB_INT_READ_PAGE_INFO,             /* Read page info */
    FEE_JOB_INT_CHECK_ERASE_PAGE_INFO,      /* check erase page info */
    FEE_JOB_INT_ERASE_SECTOR_READ,          /* Read erase page sector data */
    FEE_JOB_INT_ERASE_SECTOR_STATUS_CHECK,  /* check erase page sector data */
    FEE_JOB_INT_ACTIVE_PAGE,                /* get active page number */
    FEE_JOB_INT_GET_RECORD,                 /* get record info */
    FEE_JOB_INT_RECORD_PARES,               /* analyze record info */
#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
    FEE_JOB_INT_GET_DATA_OFFSET,            /* get data offset data */
    FEE_JOB_INT_CHECK_DATA_OFFSET,          /* check data offset data */
#endif
    FEE_JOB_INT_CHECK_STATUS,               /* check the current status of Fee */
    FEE_JOB_INT_FORMAT,                     /* format Fee page */
    FEE_JOB_INT_FORMAT_ACTIVE,              /* set the formatted page to active */
    FEE_JOB_INT_SWAP,                       /* Fee initialization page swap */
    FEE_JOB_INT_END,                        /* Fee initialization complete */

    FEE_JOB_READ,                           /* read the Fee block data */
#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
    FEE_JOB_READ_HEAD_DATA,                 /* read header data */
    FEE_JOB_READ_HEAD_DATA_CRC,             /* header data crc */
#endif
    FEE_JOB_READ_RECORD_DATA,               /* read the target record data */
    FEE_JOB_READ_RECORD_DATA_SYNC,          /* Synchronous record data */
#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
    FEE_JOB_READ_RECORD_DATA_CRC,           /* calculate the crc of record data */
    FEE_JOB_READ_TAIL_DATA,                 /* read tail data */
    FEE_JOB_READ_TAIL_DATA_CRC,             /* tail data CRC */
    FEE_JOB_READ_CHECK_DATA_CRC,            /* check record data crc */
#endif
    FEE_JOB_READ_END,                       /* Fee read complete */

    FEE_JOB_WRITE,                          /* write the Fee block data */
    FEE_JOB_WRITE_ERASE_BACKUP,             /* erase backup page */
    FEE_JOB_WRITE_SWAP,                     /* write page swap */
    FEE_JOB_WRITE_RECORD_INFO,              /* write the record info */
    FEE_JOB_WRITE_RECORD_INFO_SYNC,         /* Synchronous the record info */
    FEE_JOB_WRITE_RECORD_DATA,              /* write the record data */
    FEE_JOB_WRITE_RECORD_ACTIVE,            /* active record */
    FEE_JOB_WRITE_BLOCK_STATUS_SYNC,        /* Synchronous the block data status */
    FEE_JOB_WRITE_BLOCK_VALID,              /* valid block */
    FEE_JOB_WRITE_END,                      /* Fee write complete */

    FEE_JOB_SWAP_ACTIVE_PAGE_VALID,         /* set active page valid */
    FEE_JOB_SWAP_BACKUP_PAGE_RECEIVE,       /* set backup page receive */
    FEE_JOB_SWAP_DATA,                      /* Fee swap data */
    FEE_JOB_SWAP_WRITE_INFO,                /* Fee swap write record info */
    FEE_JOB_SWAP_WRITE_INFO_SYNC,           /* Synchronous Fee swap record info */
    FEE_JOB_SWAP_READ_DATA,                 /* Fee swap read record data */
    FEE_JOB_SWAP_WRITE_DATA,                /* Fee swap write record data */
    FEE_JOB_SWAP_STATUS_SYNC,               /* Synchronous Fee swap status */
    FEE_JOB_SWAP_BACKUP_PAGE_ACTIVE,        /* set backup page active */
    FEE_JOB_SWAP_ACTIVE_PAGE_ERASING,       /* set active page eraseing */
    FEE_JOB_SWAP_ACTIVE_PAGE_ERASE,         /* enable page erase state machine of active page  */

    FEE_JOB_INVAL_BLOCK,                    /* set Fee block invalid */
    FEE_JOB_ERASE_IMMEDIATE,                /* verify that the immediate write space is free */

    FEE_JOB_FAILED,                         /* Fee JOB failure */
    FEE_JOB_DONE,                           /* Fee JOB complete */
} Fee_JobType;

typedef enum {
    FEE_ERASE_UNINIT,                               /* Fee Erase not init */
    FEE_ERASE_INIT,                                 /* Fee Erase init */
    FEE_ERASE_IDLE,                                 /* Fee erase page not in the process */
    FEE_ERASE_BUSY,                                 /* Fee erase page in the process */
    FEE_ERASE_FAILED,                               /* Fee erase page has not been finished successfully */
} Fee_Erase_StatusType;

typedef enum {
    FEE_ERASE_JOB_OK,                               /* Fee erase job has been finished successfully */
    FEE_ERASE_JOB_FAILED,                           /* Fee erase job has not been finished successfully */
    FEE_ERASE_JOB_PENDING,                          /* Fee erase job has not yet been finished */
} Fee_Erase_JobResultType;

typedef enum {
    FEE_ERASE_JOB_INT,                              /* Initialize the Fee Erase */
    FEE_ERASE_JOB_ERASE,                            /* Fee Erase erase page block */
    FEE_ERASE_JOB_DONE,
} Fee_Erase_JobType;

typedef enum {
    FEE_SWAP_UNINIT,                                /* Fee Swap not init */
    FEE_SWAP_INIT,                                  /* Fee Swap in init */
    FEE_SWAP_WRITE,                                 /* Fee Swap in write data */
    FEE_SWAP_IMMEDIATE,                             /* Fee Swap in immediate data */
} Fee_Sawp_Type;

/******************************************************************************
** Service name        : Fee_Init                                               **
** Parameters (in)     : paConfigPtr  Pointer to block configuration set        **
** Parameters (out)    : None                                                   **
** Return value        : None                                                   **
** Description        : Initializes the FEE                                     **
******************************************************************************/
extern void Fee_Init(const Fee_ConfigType *paConfigPtr );

/******************************************************************************
** Service name        : Fee_SetMode                                            **
** Parameters (in)     : MemIf_ModeType Mode (Mode MEMIF_MODE_SLOW /            **
**                                         MEMIF_MODE_FAST)                     **
** Parameters (out)    : None                                                   **
** Return value        : void                                                   **
** Description        : Call the Fls_SetMode function                           **
******************************************************************************/
#if (FEE_SETMODE_API_SUPPORTED == STD_ON)
extern void Fee_SetMode( MemIf_ModeType eMode );
#endif

/******************************************************************************
** Service name        : Fee_Read                                               **
** Parameters (in)     : uint16 uBlockNumber :block number                      **
**                      uint16 uBlockOffset : block addr offset                 **
**                      uint8* pDataBufferPtr :Pointer to data buffer           **
**                      uint16 uLength : Number of bytes to read                **
** Parameters (out)    : None                                                   **
** Return value        : Std_ReturnType ( E_OK / E_NOT_OK )                     **
** Description        : Reads from fee block                                 **
******************************************************************************/
extern Std_ReturnType Fee_Read( uint16 uBlockNumber,
                                uint16 uBlockOffset,
                                uint8 *pDataBufferPtr,
                                uint16 uLength );

/******************************************************************************
** Service name        : Fee_Write                                              **
** Parameters (in)     : uint16 uBlockNumber :block number                      **
**                      const uint8* pDataBufferPtr :Pointer to data buffer     **
** Parameters (out)    : None                                                   **
** Return value        : Std_ReturnType ( E_OK / E_NOT_OK )                     **
** Description        : Writes to fee block                                     **
******************************************************************************/
extern Std_ReturnType Fee_Write( uint16 uBlockNumber,
                                 const uint8 *pDataBufferPtr );

/******************************************************************************
** Service name        : Fee_Cancel                                             **
** Parameters (in)     : None                                                   **
** Parameters (out)    : None                                                   **
** Return value        : None                                                   **
** Description        : Cancels an ongoing job                                  **
******************************************************************************/
extern void Fee_Cancel( void );

/******************************************************************************
** Service name        : Fee_GetStatus                                          **
** Parameters (in)     : None                                                   **
** Parameters (out)    : None                                                   **
** Return value        : MemIf_StatusType                                       **
** Description        : Returns the fee state                                **
******************************************************************************/
extern MemIf_StatusType Fee_GetStatus( void );

/******************************************************************************
** Service name        : Fee_GetJobResult                                       **
** Parameters (in)     : None                                                   **
** Parameters (out)    : None                                                   **
** Return value        : MemIf_JobResultType                                    **
** Description        : Returns the result of the last job                      **
******************************************************************************/
extern MemIf_JobResultType Fee_GetJobResult( void );

/******************************************************************************
** Service name        : Fee_InvalidateBlock                                    **
** Parameters (in)     : uint16 uBlockNumber :block number                      **
** Parameters (out)    : None                                                   **
** Return value        : Std_ReturnType ( E_OK / E_NOT_OK )                     **
** Description         : set fee block invalid                                  **
******************************************************************************/
extern Std_ReturnType Fee_InvalidateBlock( uint16 uBlockNumber );

/******************************************************************************
** Service name        : Fee_GetVersionInfo                                     **
** Parameters (in)     : Std_VersionInfoType pVersionInfoPtr :                  **
**                          Pointer to VersionInfo buffer                       **
** Parameters (out)    : None                                                   **
** Return value        : None                                                   **
** Description         : get fee VersionInfo                                    **
******************************************************************************/
#if (FEE_VERSION_INFO_API == STD_ON)
extern void Fee_GetVersionInfo( Std_VersionInfoType *pVersionInfoPtr );
#endif

/******************************************************************************
** Service name        : Fee_EraseImmediateBlock                                **
** Parameters (in)     : uint16 uBlockNumber :block number                      **
** Parameters (out)    : None                                                   **
** Return value        : Std_ReturnType ( E_OK / E_NOT_OK )                     **
** Description         : fee erase immediate block                              **
******************************************************************************/
extern Std_ReturnType Fee_EraseImmediateBlock( uint16 uBlockNumber );

/******************************************************************************
** Service name        : Fee_MainFunction                                       **
** Parameters (in)     : None                                                   **
** Parameters (out)    : None                                                   **
** Return value        : None                                                   **
** Description        : Performs the processing of jobs                         **
******************************************************************************/
extern void Fee_MainFunction( void );


/******************************************************************************
** Service name        : Fee_GetBlockPageid                                     **
** Parameters (in)     : uint16 uBlockNumber :block number                      **
** Parameters (out)    : None                                                   **
** Return value        : None                                                   **
** Description        : The page ID currently in use                            **
******************************************************************************/
extern Std_ReturnType Fee_GetBlockPageid( uint16 uBlockNumber,
        uint16 *page_id );

/******************************************************************************
** Service name        : Fee_GetAvailableSpace                                  **
** Parameters (in)     : uint16 uBlockNumber :block number                      **
** Parameters (out)    : None                                                   **
** Return value        : None                                                   **
** Description        : Remaining free space on the current page                **
******************************************************************************/
extern Std_ReturnType Fee_GetAvailableSpace( uint16 uBlockNumber,
        Fls_LengthType *free_size );

/******************************************************************************
** Service name        : FeeErase_GetStatus                                     **
** Parameters (in)     : None                                                   **
** Parameters (out)    : None                                                   **
** Return value        : None                                                   **
** Description        : Returns the fee erase state                             **
******************************************************************************/
extern Fee_Erase_StatusType FeeErase_GetStatus( void );

/******************************************************************************
** Service name        : FeeErase_GetJobResult                                  **
** Parameters (in)     : None                                                   **
** Parameters (out)    : None                                                   **
** Return value        : None                                                   **
** Description        : Returns the result of the fee erase job                 **
******************************************************************************/
extern Fee_Erase_JobResultType FeeErase_GetJobResult( void );

#ifdef __cplusplus
}
#endif

#endif /* FEE_H */
/** @} */
