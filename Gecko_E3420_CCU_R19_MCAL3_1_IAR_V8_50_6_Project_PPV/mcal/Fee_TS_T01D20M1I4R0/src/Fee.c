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
 * @file  Fee.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Flash EEPROM Emulation
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "cdefs.h"
#include "Mcal.h"
#include "Fee.h"
#if (FEE_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* FEE_DEV_ERROR_DETECT == STD_ON */
#include "fee_ops.h"
#include "Fee_Cfg.h"
#include "mini_libc.h"
#include "debug.h"
#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
#include "crc16.h"
#endif

/* Job end notification routine provided by the upper layer module (declaration) */
FEE_NVM_JOB_END_NOTIFICATION_DECL

/* Job error notification routine provided by the upper layer module (declaration) */
FEE_NVM_JOB_ERROR_NOTIFICATION_DECL

#define FEE_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Fee_MemMap.h"

static struct fee_dev fee_dev[FEE_PAGE_DEV_NUMBER];

/* fee job info */
static uint16 Fee_uJobBlockIndex;
static Fls_LengthType Fee_uJobBlockOffset;
static Fls_LengthType Fee_uJobBlockLength;
static uint8 *Fee_pJobReadDataDestPtr;
static const uint8 *Fee_pJobWriteDataDestPtr;

static uint16 Fee_uJobIntSwapClrGrpIt;
static uint16 Fee_uJobBlockSwapIndex;
static Fls_LengthType Fee_uJobBlockDataOffset;
static Fls_LengthType Fee_uJobReadDataLengthSync;
#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
static Fls_LengthType Fee_uJobBlockDataLength;
static boolean Fee_uJobBlockDataSync;
static uint16 Fee_uJobReadDataChecksum;
#endif

static Fls_LengthType FeeErase_uBlockOffset;
static uint16 FeeErase_uDevIndex;
static uint16 FeeErase_uPageIndex;

/* fee device */
static uint16 Fee_uJobIntClrGrpIt;
static uint16 Fee_uJobIntClrIt;

static uint16 fee_active_page;
static uint16 fee_backup_page;
static uint16 fee_swap_flag;

#define FEE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Fee_MemMap.h"

#define FEE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Fee_MemMap.h"

/* fee job status */
static Fee_JobType Fee_eJob = FEE_JOB_DONE;                 /* fee job status */
static MemIf_StatusType Fee_eModuleStatus =
    MEMIF_UNINIT;   /* fee module status */
static MemIf_JobResultType Fee_eJobResult = MEMIF_JOB_OK;   /* fee job result */

/* fee erase job status */
static Fee_Erase_JobType FeeErase_eJob = FEE_ERASE_JOB_DONE;
static Fee_Erase_StatusType FeeErase_eStatus = FEE_ERASE_UNINIT;
static Fee_Erase_JobResultType FeeErase_eJobResult = FEE_ERASE_JOB_OK;

/* fee swap job type */
static Fee_Sawp_Type fee_swap_type = FEE_SWAP_UNINIT;

#define FEE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"

#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
extern uint8 block_buff[FEE_DATA_CACHE_SIZE + CONFIG_ARCH_CACHE_LINE];
#endif
extern struct fee_block_status block_status[FEE_BLOCKS_CFG_NUMBER];

static MemIf_JobResultType Fee_JobInt( void );
static MemIf_JobResultType Fee_JobIntCfg( void );
static MemIf_JobResultType Fee_JobIntReadPageInfo( void );
static MemIf_JobResultType Fee_JobIntCheckErasePageInfo( void );
static MemIf_JobResultType Fee_JobIntEraseSectorRead( void );
static MemIf_JobResultType Fee_JobIntEraseSectorStatusCheck( void );
static MemIf_JobResultType Fee_JobIntPageInfoEnd( void );
static MemIf_JobResultType Fee_JobIntActivePage( void );
static MemIf_JobResultType Fee_JobIntFirstCfg( void );
static MemIf_JobResultType Fee_JobIntRecordIndex( void );
static MemIf_JobResultType Fee_JobIntGetRecord( void );
static MemIf_JobResultType Fee_JobIntRecordPares( void );
#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
static MemIf_JobResultType Fee_JobIntGetDataOffset( void );
static MemIf_JobResultType Fee_JobIntCheckDataOffset( void );
#endif
static MemIf_JobResultType Fee_JobIntCheckStatus( void );
static MemIf_JobResultType Fee_JobIntFormat( void );
static MemIf_JobResultType Fee_JobIntFormatActive( void );
static MemIf_JobResultType Fee_JobIntErase( void );
static MemIf_JobResultType Fee_JobIntEraseSwap( void );
static MemIf_JobResultType Fee_JobIntSwap( void );
static MemIf_JobResultType Fee_JobIntEnd( void );

static MemIf_JobResultType Fee_JobRead( void );
#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
static MemIf_JobResultType Fee_JobReadHeadData( void );
static MemIf_JobResultType Fee_JobReadHeadDataCRC( void );
#endif
static MemIf_JobResultType Fee_JobReadRecordData( void );
static MemIf_JobResultType Fee_JobReadRecordDataSync( void );
#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
static MemIf_JobResultType Fee_JobReadRecordDataCRC( void );
static MemIf_JobResultType Fee_JobReadTailData( void );
static MemIf_JobResultType Fee_JobReadTailDataCRC( void );
static MemIf_JobResultType Fee_JobReadDataChecksum( void );
#endif
static MemIf_JobResultType Fee_JobReadEnd( void );

static MemIf_JobResultType Fee_JobWrite( void );
static MemIf_JobResultType Fee_JobWriteSwap( void );
static MemIf_JobResultType Fee_JobWriteInfo( void );
static MemIf_JobResultType Fee_JobWriteInfoSync( void );
static MemIf_JobResultType Fee_JobWriteData( void );
static MemIf_JobResultType Fee_JobWriteActice( void );
static MemIf_JobResultType Fee_JobWriteStatusSync( void );
static MemIf_JobResultType Fee_JobWriteValid( void );
static MemIf_JobResultType Fee_JobWriteEnd( void );

static MemIf_JobResultType Fee_JobSwapActivePageValid( void );
static MemIf_JobResultType Fee_JobSwapBackupPageReceive( void );
static MemIf_JobResultType Fee_JobSwapData( void );
static MemIf_JobResultType Fee_JobSwapInfo( void );
static MemIf_JobResultType Fee_JobSwapInfoSync( void );
static MemIf_JobResultType Fee_JobSwapReadData( void );
static MemIf_JobResultType Fee_JobSwapWriteData( void );
static MemIf_JobResultType Fee_JobSwapStatusSync( void );
static MemIf_JobResultType Fee_JobSwapBackupPageActive( void );
static MemIf_JobResultType Fee_JobSwapActivePageErasing( void );
static MemIf_JobResultType Fee_JobSwapActivePageErase( void );

static MemIf_JobResultType Fee_JobInvalBlock( void );
static MemIf_JobResultType Fee_JobEraseImmediate( void );

static MemIf_JobResultType Fee_JobValidCheck( uint16 uJobBlockIndex );
static MemIf_JobResultType Fee_JobInvalidCheck( uint16 uJobBlockIndex );

static Fee_Erase_JobResultType FeeErase_JobInit( void );
static Fee_Erase_JobResultType FeeErase_JobIErase( void );
static Fee_Erase_JobResultType FeeErase_JobEnd( void );

/* get BlockIndex based on BlockNumber */
static uint16 Fee_GetBlockIndex(uint16 uBlockNumber)
{
    uint16 uRetVal = FEE_BLOCK_INDEX_DEF;
    uint16 i = 0;

    for (i = 0; i < FEE_BLOCKS_CFG_NUMBER; i++) {
        if (uBlockNumber == Fee_BlockConfig[i].blockNumber) {
            uRetVal = i;
            break;
        }
    }

    return uRetVal;
}

static MemIf_JobResultType Fee_JobInt( void )
{
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    struct fee_dev *pfee_dev = NULL_PTR;
    uint16 i = 0, j = 0;

#if (FEE_PAGE_CFG_NUMBER != FEE_PAGE_NUMBER)
#error "The FEE_PAGE_CFG_NUMBER should equal to FEE_PAGE_NUMBER"
#endif

    memset(block_status, 0, sizeof(struct fee_block_status) *
           FEE_BLOCKS_CFG_NUMBER);

    /*PRQA S 2877 2*/
    for (i = 0; i < FEE_BLOCKS_CFG_NUMBER; i++) {
        block_status[i].block_number = Fee_BlockConfig[i].blockNumber;
        block_status[i].block_size = Fee_BlockConfig[i].blockSize;
    }

    /*PRQA S 2877 2*/
    for (i = 0; i < FEE_PAGE_DEV_NUMBER; i++) {
        pfee_dev = &fee_dev[i];
        memset(pfee_dev, 0x0, sizeof(struct fee_dev));

        for (j = 0; j < FEE_PAGE_CFG_NUMBER; j++) {
            pfee_dev->page_info[j].page_addr = Fee_PageDevice[i].clrPtr[j].Fls_startAddr;
            pfee_dev->page_info[j].page_size = Fee_PageDevice[i].clrPtr[j].Fls_length;
            pfee_dev->page_info[j].erase_size = Fee_PageDevice[i].clrPtr[j].Fls_eraseSize;
            pfee_dev->page_info[j].sector_size = Fee_PageDevice[i].clrPtr[j].Fls_sectorSize;
        }

        pfee_dev->fee_index = i;
        pfee_dev->disk_reserved_size = Fee_PageDevice[i].reservedSize;
        pfee_dev->disk_mem_align_size = CONFIG_ARCH_CACHE_LINE;
    }

    Fee_uJobIntClrGrpIt = 0;
    Fee_uJobIntClrIt = 0;

    FeeErase_eJob = FEE_ERASE_JOB_DONE;
    FeeErase_eStatus = FEE_ERASE_UNINIT;
    FeeErase_eJobResult = FEE_ERASE_JOB_OK;

    eRetVal = Fee_JobIntCfg();
    return eRetVal;
}

static MemIf_JobResultType Fee_JobIntCfg( void )
{
    int ret = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    struct fee_dev *pfee_dev = &fee_dev[Fee_uJobIntClrGrpIt];

    ret = fee_config(pfee_dev);

    if (ret)
        return MEMIF_JOB_FAILED;

    eRetVal = Fee_JobIntReadPageInfo();
    return eRetVal;
}

static MemIf_JobResultType Fee_JobIntReadPageInfo( void )
{
    int ret = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    struct fee_dev *pfee_dev = &fee_dev[Fee_uJobIntClrGrpIt];

    ret = fee_get_page_info(pfee_dev, Fee_uJobIntClrIt);

    if (ret)
        eRetVal = MEMIF_JOB_FAILED;
    else
        eRetVal = MEMIF_JOB_PENDING;

    Fee_eJob = FEE_JOB_INT_CHECK_ERASE_PAGE_INFO;
    return ( eRetVal );
}

static MemIf_JobResultType Fee_JobIntCheckErasePageInfo( void )
{
    boolean ret = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    struct fee_dev *pfee_dev = &fee_dev[Fee_uJobIntClrGrpIt];

    ret = fee_check_erase_page_info(pfee_dev, Fee_uJobIntClrIt);

    if (TRUE == ret) {
        FeeErase_uBlockOffset = 0;
        eRetVal = Fee_JobIntEraseSectorRead();
    }
    else {
        eRetVal = Fee_JobIntPageInfoEnd();
    }

    return ( eRetVal );
}

static MemIf_JobResultType Fee_JobIntEraseSectorRead( void )
{
    int ret = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    struct fee_dev *pfee_dev = &fee_dev[Fee_uJobIntClrGrpIt];
    uint32 sector_size = pfee_dev->page_info[Fee_uJobIntClrIt].sector_size;

    FeeErase_uBlockOffset += sector_size;
    ret = fee_get_page_sector(pfee_dev, Fee_uJobIntClrIt, FeeErase_uBlockOffset);

    if (ret)
        eRetVal = MEMIF_JOB_FAILED;
    else
        eRetVal = MEMIF_JOB_PENDING;

    Fee_eJob = FEE_JOB_INT_ERASE_SECTOR_STATUS_CHECK;
    return ( eRetVal );
}

static MemIf_JobResultType Fee_JobIntEraseSectorStatusCheck( void )
{
    int ret = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    struct fee_dev *pfee_dev = &fee_dev[Fee_uJobIntClrGrpIt];
    uint32 erase_size = pfee_dev->page_info[Fee_uJobIntClrIt].erase_size;

    ret = fee_sector_status_check(pfee_dev, Fee_uJobIntClrIt,
                                  FeeErase_uBlockOffset);

    if (ret)
        return MEMIF_JOB_FAILED;

    if (FeeErase_uBlockOffset == erase_size) {
        eRetVal = Fee_JobIntPageInfoEnd();
    }
    else {
        eRetVal = Fee_JobIntEraseSectorRead();
    }

    return ( eRetVal );
}

static MemIf_JobResultType Fee_JobIntPageInfoEnd( void )
{
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;

    Fee_uJobIntClrIt++;

    if (Fee_uJobIntClrIt == FEE_PAGE_CFG_NUMBER) {
        eRetVal = Fee_JobIntActivePage();
    }
    else {
        eRetVal = Fee_JobIntReadPageInfo();
    }

    return ( eRetVal );
}
static MemIf_JobResultType Fee_JobIntActivePage( void )
{
    int ret = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    struct fee_dev *pfee_dev = &fee_dev[Fee_uJobIntClrGrpIt];

    ret = fee_page_active_page(pfee_dev);

    if (ret)
        return MEMIF_JOB_FAILED;

    if (pfee_dev->first_flag) {
        eRetVal = Fee_JobIntFirstCfg();
    }
    else
        eRetVal = Fee_JobIntRecordIndex();

    return ( eRetVal );
}

static MemIf_JobResultType Fee_JobIntFirstCfg( void )
{
    int ret = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    struct fee_dev *pfee_dev = &fee_dev[Fee_uJobIntClrGrpIt];

    ret = fee_first_cfg(pfee_dev);

    if (ret)
        return MEMIF_JOB_FAILED;

    eRetVal = Fee_JobIntCheckStatus();
    return ( eRetVal );
}

static MemIf_JobResultType Fee_JobIntRecordIndex( void )
{
    int ret = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    struct fee_dev *pfee_dev = &fee_dev[Fee_uJobIntClrGrpIt];

    ret = fee_page_record_index_cfg(pfee_dev);

    if (ret)
        return MEMIF_JOB_FAILED;

    eRetVal = Fee_JobIntGetRecord();
    return ( eRetVal );
}

static MemIf_JobResultType Fee_JobIntGetRecord( void )
{
    int ret = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    struct fee_dev *pfee_dev = &fee_dev[Fee_uJobIntClrGrpIt];

    ret = fee_page_get_record_index(pfee_dev);

    if (ret)
        eRetVal = MEMIF_JOB_FAILED;
    else
        eRetVal = MEMIF_JOB_PENDING;

    Fee_eJob = FEE_JOB_INT_RECORD_PARES;
    return ( eRetVal );
}

static MemIf_JobResultType Fee_JobIntRecordPares( void )
{
    int ret = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    struct fee_dev *pfee_dev = &fee_dev[Fee_uJobIntClrGrpIt];
    boolean record_match = 0;
    boolean end_match = 0;

    ret = fee_page_record_index_parse(pfee_dev, &record_match, &end_match);

    if (ret)
        return MEMIF_JOB_FAILED;

    if (end_match)
        return MEMIF_JOB_FAILED;

    if (record_match) {
        if (pfee_dev->first_flag)
            eRetVal = Fee_JobIntFirstCfg();
        else
#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
            eRetVal = Fee_JobIntGetDataOffset();

#else
            eRetVal = Fee_JobIntCheckStatus();
#endif
    }
    else {
        eRetVal = Fee_JobIntGetRecord();
    }

    return ( eRetVal );
}

#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
static MemIf_JobResultType Fee_JobIntGetDataOffset( void )
{
    int ret = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    struct fee_dev *pfee_dev = &fee_dev[Fee_uJobIntClrGrpIt];

    ret = fee_page_get_data_offset(pfee_dev);

    if (ret)
        eRetVal = MEMIF_JOB_FAILED;
    else
        eRetVal = MEMIF_JOB_PENDING;

    Fee_eJob = FEE_JOB_INT_CHECK_DATA_OFFSET;
    return ( eRetVal );
}

static MemIf_JobResultType Fee_JobIntCheckDataOffset( void )
{
    int ret = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    struct fee_dev *pfee_dev = &fee_dev[Fee_uJobIntClrGrpIt];
    boolean data_offset_check = 0;

    ret = fee_page_check_data_offset(pfee_dev, &data_offset_check);

    if (ret)
        eRetVal = MEMIF_JOB_FAILED;

    if (data_offset_check) {
        eRetVal = Fee_JobIntCheckStatus();
    }
    else {
        eRetVal = Fee_JobIntGetDataOffset();
    }

    return ( eRetVal );
}
#endif

static MemIf_JobResultType Fee_JobIntCheckStatus( void )
{
    int ret = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    struct fee_dev *pfee_dev = &fee_dev[Fee_uJobIntClrGrpIt];
    fee_page_job page_job = FEE_PAGE_ERROR;

    ret = fee_page_check_status(pfee_dev, &page_job, &fee_active_page,
                                &fee_backup_page);

    if (ret)
        return MEMIF_JOB_FAILED;

#if (FEE_CHECKSUM_SUPPORTED == STD_ON)

    switch (page_job) {
        case FEE_PAGE_ERASE:
        case FEE_PAGE_ERASE_SWAP:
        case FEE_PAGE_SWAP:
        case FEE_PAGE_NORMAL:
            ret = fee_page_info_check(pfee_dev, fee_active_page);

            if (ret)
                return MEMIF_JOB_FAILED;

            break;

        case FEE_PAGE_FORMAT:
            break;

        default:
            eRetVal = MEMIF_JOB_FAILED;
    }

#endif

    switch (page_job) {
        case FEE_PAGE_FORMAT:
            Fee_uJobIntClrIt = 0;
            eRetVal = Fee_JobIntFormat();
            break;

        case FEE_PAGE_ERASE:
            eRetVal = Fee_JobIntErase();
            break;

        case FEE_PAGE_ERASE_SWAP:
            Fee_uJobIntSwapClrGrpIt = Fee_uJobIntClrGrpIt;
            eRetVal = Fee_JobIntEraseSwap();
            break;

        case FEE_PAGE_SWAP:
            Fee_uJobIntSwapClrGrpIt = Fee_uJobIntClrGrpIt;
            eRetVal = Fee_JobIntSwap();
            break;

        case FEE_PAGE_NORMAL:
            eRetVal = Fee_JobIntEnd();
            break;

        default:
            eRetVal = MEMIF_JOB_FAILED;
    }

    return ( eRetVal );
}

static MemIf_JobResultType Fee_JobIntFormat( void )
{
    int ret = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    struct fee_dev *pfee_dev = &fee_dev[Fee_uJobIntClrGrpIt];

    ret = fee_erase_page(pfee_dev, Fee_uJobIntClrIt);

    if (ret)
        eRetVal = MEMIF_JOB_FAILED;
    else
        eRetVal = MEMIF_JOB_PENDING;

    Fee_uJobIntClrIt++;

    if (Fee_uJobIntClrIt == FEE_PAGE_CFG_NUMBER) {
        Fee_eJob = FEE_JOB_INT_FORMAT_ACTIVE;
    }
    else {
        Fee_eJob = FEE_JOB_INT_FORMAT;
    }

    return ( eRetVal );
}


static MemIf_JobResultType Fee_JobIntFormatActive( void )
{
    int ret = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    struct fee_dev *pfee_dev = &fee_dev[Fee_uJobIntClrGrpIt];

    ret = fee_set_page_info(pfee_dev, 0, FEE_PAGE_ACTIVE);

    if (ret)
        eRetVal = MEMIF_JOB_FAILED;
    else
        eRetVal = MEMIF_JOB_PENDING;

    Fee_eJob = FEE_JOB_INT_END;

    return ( eRetVal );
}

static MemIf_JobResultType Fee_JobIntErase( void )
{
    if (FEE_ERASE_UNINIT != FeeErase_eStatus)
        return MEMIF_JOB_FAILED;

    FeeErase_uDevIndex = Fee_uJobIntClrGrpIt;
    FeeErase_uPageIndex = fee_backup_page;

    FeeErase_eJob = FEE_ERASE_JOB_INT;
    FeeErase_eStatus = FEE_ERASE_INIT;
    FeeErase_eJobResult = FEE_ERASE_JOB_PENDING;

    return Fee_JobIntEnd();
}

static MemIf_JobResultType Fee_JobIntEraseSwap( void )
{
    int ret = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    struct fee_dev *pfee_dev = &fee_dev[Fee_uJobIntSwapClrGrpIt];

    ret = fee_erase_page(pfee_dev, fee_backup_page);

    if (ret)
        eRetVal = MEMIF_JOB_FAILED;
    else
        eRetVal = MEMIF_JOB_PENDING;

    Fee_eJob = FEE_JOB_INT_SWAP;
    return ( eRetVal );
}

static MemIf_JobResultType Fee_JobIntSwap( void )
{
    int ret = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    struct fee_dev *pfee_dev = &fee_dev[Fee_uJobIntSwapClrGrpIt];

    ret = fee_swap_cfg(pfee_dev, &fee_active_page, &fee_backup_page);

    if (ret)
        return  MEMIF_JOB_FAILED;

    fee_swap_type = FEE_SWAP_INIT;
    fee_swap_flag = TRUE;
    eRetVal = Fee_JobSwapActivePageValid();
    return ( eRetVal );
}

static MemIf_JobResultType Fee_JobIntEnd( void )
{
    Fee_uJobIntClrIt = 0;
    Fee_uJobIntClrGrpIt++;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;

    if (Fee_uJobIntClrGrpIt == FEE_PAGE_DEV_NUMBER)
        Fee_eJob = FEE_JOB_DONE;
    else
        eRetVal = Fee_JobIntCfg();

    return ( eRetVal );
}

static MemIf_JobResultType Fee_JobRead( void )
{
    int ret = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    Fee_BlockConfigType *pblock_cof = (Fee_BlockConfigType *)
                                      &Fee_BlockConfig[Fee_uJobBlockIndex];
    struct fee_dev *pfee_dev = &fee_dev[pblock_cof->pageDevIndex];

    ret = fee_read_block_check(pfee_dev, pblock_cof->blockNumber);

    if (ret)
        return  MEMIF_JOB_FAILED;

#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
    Fee_uJobBlockDataOffset = 0;
    Fee_uJobBlockDataLength = Fee_uJobBlockOffset;
    Fee_uJobBlockDataSync = 0;
    Fee_uJobReadDataChecksum = 0;
    eRetVal = Fee_JobReadHeadData();
#else
    Fee_uJobBlockDataOffset = 0;
    eRetVal = Fee_JobReadRecordData();
#endif
    return eRetVal;
}

#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
static MemIf_JobResultType Fee_JobReadHeadData( void )
{
    Fls_LengthType rlen = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    Fee_BlockConfigType *pblock_cof = (Fee_BlockConfigType *)
                                      &Fee_BlockConfig[Fee_uJobBlockIndex];
    struct fee_dev *pfee_dev = &fee_dev[pblock_cof->pageDevIndex];
    uint8 *buff = (uint8 *)ROUNDUP((unsigned int)block_buff,
                                   CONFIG_ARCH_CACHE_LINE);

    if (Fee_uJobBlockDataOffset == Fee_uJobBlockDataLength) {
        Fee_uJobBlockDataOffset = 0;
        eRetVal = Fee_JobReadRecordData();
    }
    else {
        Fee_uJobBlockDataSync = 0;
        rlen = fee_read_block_data(pfee_dev, pblock_cof->blockNumber,
                                   Fee_uJobBlockDataOffset, buff,
                                   _MIN(Fee_uJobBlockDataLength - Fee_uJobBlockDataOffset, FEE_DATA_CACHE_SIZE),
                                   &Fee_uJobBlockDataSync);

        if (!rlen)
            eRetVal = MEMIF_JOB_FAILED;
        else
            eRetVal = MEMIF_JOB_PENDING;

        Fee_uJobReadDataLengthSync = rlen;
        Fee_eJob = FEE_JOB_READ_HEAD_DATA_CRC;
    }

    return ( eRetVal );
}

static MemIf_JobResultType Fee_JobReadHeadDataCRC( void )
{
    Fls_LengthType rlen = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    Fee_BlockConfigType *pblock_cof = (Fee_BlockConfigType *)
                                      &Fee_BlockConfig[Fee_uJobBlockIndex];
    struct fee_dev *pfee_dev = &fee_dev[pblock_cof->pageDevIndex];
    uint8 *buff = (uint8 *)ROUNDUP((unsigned int)block_buff,
                                   CONFIG_ARCH_CACHE_LINE);

    if (Fee_uJobBlockDataSync) {
        rlen = fee_read_block_data_sync(pfee_dev, pblock_cof->blockNumber,
                                        Fee_uJobBlockDataOffset, buff, Fee_uJobReadDataLengthSync);

        if (!rlen)
            return  MEMIF_JOB_FAILED;

    }

    if (Fee_uJobBlockDataOffset == 0) {
        Fee_uJobReadDataChecksum = crc16(buff, Fee_uJobReadDataLengthSync);
    }
    else {
        Fee_uJobReadDataChecksum = update_crc16(Fee_uJobReadDataChecksum, buff,
                                                Fee_uJobReadDataLengthSync);
    }

    Fee_uJobBlockDataOffset += Fee_uJobReadDataLengthSync;
    eRetVal = Fee_JobReadHeadData();

    return ( eRetVal );
}
#endif

static MemIf_JobResultType Fee_JobReadRecordData( void )
{
    Fls_LengthType rlen = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    Fee_BlockConfigType *pblock_cof = (Fee_BlockConfigType *)
                                      &Fee_BlockConfig[Fee_uJobBlockIndex];
    struct fee_dev *pfee_dev = &fee_dev[pblock_cof->pageDevIndex];
    boolean data_sync = 0;

    rlen = fee_read_block_data(pfee_dev, pblock_cof->blockNumber,
                               Fee_uJobBlockOffset + Fee_uJobBlockDataOffset,
                               (uint8 *)(Fee_pJobReadDataDestPtr + Fee_uJobBlockDataOffset),
                               Fee_uJobBlockLength - Fee_uJobBlockDataOffset, &data_sync);

    if (!rlen)
        return  MEMIF_JOB_FAILED;

    if (data_sync) {
        Fee_uJobReadDataLengthSync = rlen;
        Fee_eJob = FEE_JOB_READ_RECORD_DATA_SYNC;
    }
    else {
        if (rlen == Fee_uJobBlockLength - Fee_uJobBlockDataOffset) {
#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
            Fee_uJobBlockDataOffset = 0;
            Fee_eJob = FEE_JOB_READ_RECORD_DATA_CRC;
#else
            Fee_uJobBlockDataOffset = 0;
            Fee_eJob = FEE_JOB_READ_END;
#endif
        }
        else {
            Fee_uJobBlockDataOffset += rlen;
            Fee_eJob = FEE_JOB_READ_RECORD_DATA;
        }
    }

    eRetVal = MEMIF_JOB_PENDING;
    return ( eRetVal );
}

static MemIf_JobResultType Fee_JobReadRecordDataSync( void )
{
    Fls_LengthType rlen = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    Fee_BlockConfigType *pblock_cof = (Fee_BlockConfigType *)
                                      &Fee_BlockConfig[Fee_uJobBlockIndex];
    struct fee_dev *pfee_dev = &fee_dev[pblock_cof->pageDevIndex];

    rlen = fee_read_block_data_sync(pfee_dev, pblock_cof->blockNumber,
                                    Fee_uJobBlockOffset + Fee_uJobBlockDataOffset,
                                    (uint8 *)(Fee_pJobReadDataDestPtr + Fee_uJobBlockDataOffset),
                                    Fee_uJobReadDataLengthSync);

    if (!rlen)
        return  MEMIF_JOB_FAILED;

    if (rlen == Fee_uJobBlockLength - Fee_uJobBlockDataOffset) {
#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
        Fee_uJobBlockDataOffset = 0;
        eRetVal = Fee_JobReadRecordDataCRC();
#else
        Fee_uJobBlockDataOffset = 0;
        eRetVal = Fee_JobReadEnd();
#endif
    }
    else {
        Fee_uJobBlockDataOffset += rlen;
        eRetVal = Fee_JobReadRecordData();
    }

    return ( eRetVal );
}

#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
static MemIf_JobResultType Fee_JobReadRecordDataCRC( void )
{
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;

    if (Fee_uJobBlockOffset == 0) {
        Fee_uJobReadDataChecksum = crc16(Fee_pJobReadDataDestPtr, Fee_uJobBlockLength);
    }
    else {
        Fee_uJobReadDataChecksum = update_crc16(Fee_uJobReadDataChecksum,
                                                Fee_pJobReadDataDestPtr, Fee_uJobBlockLength);
    }

    Fee_uJobBlockDataOffset = Fee_uJobBlockOffset + Fee_uJobBlockLength;
    Fee_uJobBlockDataLength = block_status[Fee_uJobBlockIndex].block_size;
    eRetVal = Fee_JobReadTailData();

    return ( eRetVal );
}

static MemIf_JobResultType Fee_JobReadTailData( void )
{
    Fls_LengthType rlen = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    Fee_BlockConfigType *pblock_cof = (Fee_BlockConfigType *)
                                      &Fee_BlockConfig[Fee_uJobBlockIndex];
    struct fee_dev *pfee_dev = &fee_dev[pblock_cof->pageDevIndex];
    uint8 *buff = (uint8 *)ROUNDUP((unsigned int)block_buff,
                                   CONFIG_ARCH_CACHE_LINE);

    if (Fee_uJobBlockDataOffset == Fee_uJobBlockDataLength) {
        Fee_uJobBlockDataOffset = 0;
        eRetVal = Fee_JobReadDataChecksum();
    }
    else {

        Fee_uJobBlockDataSync = 0;
        rlen = fee_read_block_data(pfee_dev, pblock_cof->blockNumber,
                                   Fee_uJobBlockDataOffset, buff,
                                   _MIN(Fee_uJobBlockDataLength - Fee_uJobBlockDataOffset, FEE_DATA_CACHE_SIZE),
                                   &Fee_uJobBlockDataSync);

        if (!rlen)
            eRetVal = MEMIF_JOB_FAILED;
        else
            eRetVal = MEMIF_JOB_PENDING;

        Fee_uJobReadDataLengthSync = rlen;
        Fee_eJob = FEE_JOB_READ_TAIL_DATA_CRC;
    }

    return ( eRetVal );
}

static MemIf_JobResultType Fee_JobReadTailDataCRC( void )
{
    Fls_LengthType rlen = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    Fee_BlockConfigType *pblock_cof = (Fee_BlockConfigType *)
                                      &Fee_BlockConfig[Fee_uJobBlockIndex];
    struct fee_dev *pfee_dev = &fee_dev[pblock_cof->pageDevIndex];
    uint8 *buff = (uint8 *)ROUNDUP((unsigned int)block_buff,
                                   CONFIG_ARCH_CACHE_LINE);

    if (Fee_uJobBlockDataSync) {
        rlen = fee_read_block_data_sync(pfee_dev, pblock_cof->blockNumber,
                                        Fee_uJobBlockDataOffset, buff, Fee_uJobReadDataLengthSync);

        if (!rlen)
            return  MEMIF_JOB_FAILED;

    }

    if (Fee_uJobBlockDataOffset == 0) {
        Fee_uJobReadDataChecksum = crc16(buff, Fee_uJobReadDataLengthSync);
    }
    else {
        Fee_uJobReadDataChecksum = update_crc16(Fee_uJobReadDataChecksum, buff,
                                                Fee_uJobReadDataLengthSync);
    }

    Fee_uJobBlockDataOffset += Fee_uJobReadDataLengthSync;
    eRetVal = Fee_JobReadTailData();

    return ( eRetVal );
}
static MemIf_JobResultType Fee_JobReadDataChecksum( void )
{
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    Fee_BlockConfigType *pblock_cof = (Fee_BlockConfigType *)
                                      &Fee_BlockConfig[Fee_uJobBlockIndex];

    if (Fee_uJobReadDataChecksum == block_status[Fee_uJobBlockIndex].data_crc16) {
        eRetVal = Fee_JobReadEnd();
    }
    else {
        ERROR("Fee_JobReadDataChecksum block_index:%d blockNumber:%d Fee_uJobReadDataChecksum %x data_crc16:%x\n",
              Fee_uJobBlockIndex, pblock_cof->blockNumber, Fee_uJobReadDataChecksum,
              block_status[Fee_uJobBlockIndex].data_crc16);
        block_status[Fee_uJobBlockIndex].checksum_error = 1;
        eRetVal = MEMIF_JOB_FAILED;
    }

    return ( eRetVal );
}
#endif

static MemIf_JobResultType Fee_JobReadEnd( void )
{
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    Fee_eJob = FEE_JOB_DONE;
    return ( eRetVal );
}

static MemIf_JobResultType Fee_JobWrite( void )
{
    int ret = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    Fee_BlockConfigType *pblock_cof = (Fee_BlockConfigType *)
                                      &Fee_BlockConfig[Fee_uJobBlockIndex];
    struct fee_dev *pfee_dev = &fee_dev[pblock_cof->pageDevIndex];
    boolean page_swap = 0;

    ret = fee_write_block_check(pfee_dev, pblock_cof->blockNumber,
                                (uint8 *)Fee_pJobWriteDataDestPtr, pblock_cof->blockSize,
                                pblock_cof->immediateData, &page_swap);

    if (ret)
        return  MEMIF_JOB_FAILED;

    if (page_swap) {
        Fee_uJobIntSwapClrGrpIt = pblock_cof->pageDevIndex;

        if (FEE_ERASE_UNINIT != FeeErase_eStatus) {
            Fee_eJob = FEE_JOB_WRITE_ERASE_BACKUP;
            eRetVal = MEMIF_JOB_PENDING;
        }
        else {
            eRetVal = Fee_JobWriteSwap();
        }
    }
    else
        eRetVal = Fee_JobWriteInfo();

    return eRetVal;
}

static MemIf_JobResultType Fee_JobWriteSwap( void )
{
    int ret = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    struct fee_dev *pfee_dev = &fee_dev[Fee_uJobIntSwapClrGrpIt];

    ret = fee_swap_cfg(pfee_dev, &fee_active_page, &fee_backup_page);

    if (ret)
        return  MEMIF_JOB_FAILED;

    fee_swap_type = FEE_SWAP_WRITE;
    fee_swap_flag = TRUE;
    eRetVal = Fee_JobSwapActivePageValid();
    return ( eRetVal );
}

static MemIf_JobResultType Fee_JobSwapActivePageValid( void )
{
    int ret = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    struct fee_dev *pfee_dev = &fee_dev[Fee_uJobIntSwapClrGrpIt];

    ret = fee_set_page_status(pfee_dev, fee_active_page, FEE_PAGE_VALID);

    if (ret)
        eRetVal = MEMIF_JOB_FAILED;
    else
        eRetVal = MEMIF_JOB_PENDING;

    Fee_eJob = FEE_JOB_SWAP_BACKUP_PAGE_RECEIVE;

    return ( eRetVal );
}

static MemIf_JobResultType Fee_JobSwapBackupPageReceive( void )
{
    int ret = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    struct fee_dev *pfee_dev = &fee_dev[Fee_uJobIntSwapClrGrpIt];

    ret = fee_set_page_status(pfee_dev, fee_backup_page, FEE_PAGE_RECEIVE);

    if (ret)
        eRetVal = MEMIF_JOB_FAILED;
    else
        eRetVal = MEMIF_JOB_PENDING;

    Fee_uJobBlockSwapIndex = 0;
    Fee_eJob = FEE_JOB_SWAP_DATA;

    return ( eRetVal );
}

static MemIf_JobResultType Fee_JobSwapData( void )
{
    int ret = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    Fee_BlockConfigType *pblock_cof = NULL_PTR;
    struct fee_dev *pfee_dev = &fee_dev[Fee_uJobIntSwapClrGrpIt];

    if (Fee_uJobBlockSwapIndex == FEE_BLOCKS_CFG_NUMBER)
        return Fee_JobSwapBackupPageActive();

    while (1) {
        pblock_cof = (Fee_BlockConfigType *)&Fee_BlockConfig[Fee_uJobBlockSwapIndex];

        if (pblock_cof->pageDevIndex == Fee_uJobIntSwapClrGrpIt) {
            ret = fee_block_valid_check(pfee_dev, Fee_uJobBlockSwapIndex);

            if (ret)
                break;
        }

        Fee_uJobBlockSwapIndex++;

        if (Fee_uJobBlockSwapIndex == FEE_BLOCKS_CFG_NUMBER)
            break;
    }

    if (Fee_uJobBlockSwapIndex == FEE_BLOCKS_CFG_NUMBER)
        eRetVal = Fee_JobSwapBackupPageActive();
    else
        eRetVal = Fee_JobSwapInfo();

    return ( eRetVal );
}

static MemIf_JobResultType Fee_JobSwapInfo( void )
{
    int ret = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    Fee_BlockConfigType *pblock_cof = (Fee_BlockConfigType *)
                                      &Fee_BlockConfig[Fee_uJobBlockSwapIndex];
    struct fee_dev *pfee_dev = &fee_dev[Fee_uJobIntSwapClrGrpIt];

    uint16 length = _MIN(pblock_cof->blockSize,
                         block_status[Fee_uJobBlockSwapIndex].block_size);

#if (FEE_CHECKSUM_SUPPORTED == STD_ON)

    if (fee_block_invalid_check(pfee_dev, Fee_uJobBlockSwapIndex))
        ret = fee_write_block_info(pfee_dev, pblock_cof->blockNumber,
                                   (uint8 *)Fee_pJobWriteDataDestPtr, length, FEE_BLOCK_INVALID,
                                   block_status[Fee_uJobBlockSwapIndex].data_crc16);

    else
        ret = fee_write_block_info(pfee_dev, pblock_cof->blockNumber,
                                   (uint8 *)Fee_pJobWriteDataDestPtr, length, FEE_RECORD_VALID,
                                   block_status[Fee_uJobBlockSwapIndex].data_crc16);

#else

    if (fee_block_invalid_check(pfee_dev, Fee_uJobBlockSwapIndex))
        ret = fee_write_block_info(pfee_dev, pblock_cof->blockNumber,
                                   (uint8 *)Fee_pJobWriteDataDestPtr, length, FEE_BLOCK_INVALID);

    else
        ret = fee_write_block_info(pfee_dev, pblock_cof->blockNumber,
                                   (uint8 *)Fee_pJobWriteDataDestPtr, length, FEE_RECORD_VALID);

#endif

    if (ret)
        return  MEMIF_JOB_FAILED;

    eRetVal = MEMIF_JOB_PENDING;
    Fee_eJob = FEE_JOB_SWAP_WRITE_INFO_SYNC;
    return ( eRetVal );
}

static MemIf_JobResultType Fee_JobSwapInfoSync( void )
{
    int ret = 0;
    Fee_BlockConfigType *pblock_cof = (Fee_BlockConfigType *)
                                      &Fee_BlockConfig[Fee_uJobBlockSwapIndex];
    struct fee_dev *pfee_dev = &fee_dev[Fee_uJobIntSwapClrGrpIt];

    uint16 length = _MIN(pblock_cof->blockSize,
                         block_status[Fee_uJobBlockSwapIndex].block_size);
    ret = fee_write_block_info_sync(pfee_dev, pblock_cof->blockNumber,
                                    length);

    if (ret)
        return  MEMIF_JOB_FAILED;

    Fee_uJobBlockDataOffset = 0;
    return Fee_JobSwapReadData();
}

static MemIf_JobResultType Fee_JobSwapReadData( void )
{
    Fls_LengthType rlen = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    Fee_BlockConfigType *pblock_cof = (Fee_BlockConfigType *)
                                      &Fee_BlockConfig[Fee_uJobBlockSwapIndex];
    struct fee_dev *pfee_dev = &fee_dev[Fee_uJobIntSwapClrGrpIt];

    uint16 length = _MIN(pblock_cof->blockSize,
                         block_status[Fee_uJobBlockSwapIndex].block_size);
    rlen = fee_read_swap_data(pfee_dev, pblock_cof->blockNumber,
                              Fee_uJobBlockDataOffset, length - Fee_uJobBlockDataOffset);

    if (!rlen)
        return  MEMIF_JOB_FAILED;

    eRetVal = MEMIF_JOB_PENDING;
    Fee_eJob = FEE_JOB_SWAP_WRITE_DATA;
    return ( eRetVal );
}

static MemIf_JobResultType Fee_JobSwapWriteData( void )
{
    Fls_LengthType rlen = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    Fee_BlockConfigType *pblock_cof = (Fee_BlockConfigType *)
                                      &Fee_BlockConfig[Fee_uJobBlockSwapIndex];
    struct fee_dev *pfee_dev = &fee_dev[Fee_uJobIntSwapClrGrpIt];

    uint16 length = _MIN(pblock_cof->blockSize,
                         block_status[Fee_uJobBlockSwapIndex].block_size);
    rlen = fee_write_swap_data(pfee_dev, pblock_cof->blockNumber,
                               Fee_uJobBlockDataOffset, length - Fee_uJobBlockDataOffset);

    if (!rlen)
        return  MEMIF_JOB_FAILED;

    if (rlen >= length - Fee_uJobBlockDataOffset) {
        eRetVal = MEMIF_JOB_PENDING;
        Fee_eJob = FEE_JOB_SWAP_STATUS_SYNC;
    }
    else {
        Fee_uJobBlockDataOffset += rlen;
        Fee_eJob = FEE_JOB_SWAP_READ_DATA;
        eRetVal = MEMIF_JOB_PENDING;
    }

    return ( eRetVal );
}

static MemIf_JobResultType Fee_JobSwapStatusSync( void )
{
    int ret = 0;
    Fee_BlockConfigType *pblock_cof = (Fee_BlockConfigType *)
                                      &Fee_BlockConfig[Fee_uJobBlockSwapIndex];
    struct fee_dev *pfee_dev = &fee_dev[Fee_uJobIntSwapClrGrpIt];

    uint16 length = _MIN(pblock_cof->blockSize,
                         block_status[Fee_uJobBlockSwapIndex].block_size);
    ret = fee_write_block_data_sync(pfee_dev, pblock_cof->blockNumber,
                                    length);

    if (ret)
        return  MEMIF_JOB_FAILED;

    Fee_uJobBlockDataOffset = 0;
    Fee_uJobBlockSwapIndex++;
    return Fee_JobSwapData();
}

static MemIf_JobResultType Fee_JobSwapBackupPageActive( void )
{
    int ret = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    struct fee_dev *pfee_dev = &fee_dev[Fee_uJobIntSwapClrGrpIt];

    ret = fee_set_page_info(pfee_dev, fee_backup_page, FEE_PAGE_ACTIVE);

    if (ret)
        eRetVal = MEMIF_JOB_FAILED;
    else
        eRetVal = MEMIF_JOB_PENDING;

    Fee_eJob = FEE_JOB_SWAP_ACTIVE_PAGE_ERASING;

    return ( eRetVal );
}

static MemIf_JobResultType Fee_JobSwapActivePageErasing( void )
{
    int ret = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    struct fee_dev *pfee_dev = &fee_dev[Fee_uJobIntSwapClrGrpIt];

    fee_swap_flag = FALSE;
    ret = fee_set_page_status(pfee_dev, fee_active_page, FEE_PAGE_ERASING);

    if (ret)
        eRetVal = MEMIF_JOB_FAILED;
    else
        eRetVal = MEMIF_JOB_PENDING;

    Fee_eJob = FEE_JOB_SWAP_ACTIVE_PAGE_ERASE;

    return ( eRetVal );
}

static MemIf_JobResultType Fee_JobSwapActivePageErase( void )
{
    MemIf_JobResultType eRetVal;

    if (FEE_ERASE_UNINIT != FeeErase_eStatus)
        return MEMIF_JOB_FAILED;

    FeeErase_uDevIndex = Fee_uJobIntSwapClrGrpIt;
    FeeErase_uPageIndex = fee_active_page;

    FeeErase_eJob = FEE_ERASE_JOB_INT;
    FeeErase_eStatus = FEE_ERASE_INIT;
    FeeErase_eJobResult = FEE_ERASE_JOB_PENDING;

    switch (fee_swap_type) {
        case FEE_SWAP_INIT:
            eRetVal = Fee_JobIntEnd();
            break;

        case FEE_SWAP_WRITE:
            eRetVal = Fee_JobWriteInfo();
            break;

        case FEE_SWAP_IMMEDIATE:
            eRetVal = MEMIF_JOB_OK;
            break;

        default:
            eRetVal = MEMIF_JOB_FAILED;
            break;
    }

    return eRetVal;
}


static MemIf_JobResultType Fee_JobWriteInfo( void )
{
    int ret = 0;
#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
    uint16 data_crc16 = 0;
#endif
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    Fee_BlockConfigType *pblock_cof = (Fee_BlockConfigType *)
                                      &Fee_BlockConfig[Fee_uJobBlockIndex];
    struct fee_dev *pfee_dev = &fee_dev[pblock_cof->pageDevIndex];

#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
    data_crc16 = crc16(Fee_pJobWriteDataDestPtr, pblock_cof->blockSize);
    ret = fee_write_block_info(pfee_dev, pblock_cof->blockNumber,
                               (uint8 *)Fee_pJobWriteDataDestPtr, pblock_cof->blockSize, FEE_RECORD_INVALID,
                               data_crc16);
#else
    ret = fee_write_block_info(pfee_dev, pblock_cof->blockNumber,
                               (uint8 *)Fee_pJobWriteDataDestPtr, pblock_cof->blockSize, FEE_RECORD_INVALID);
#endif

    if (ret)
        return  MEMIF_JOB_FAILED;

    eRetVal = MEMIF_JOB_PENDING;
    Fee_eJob = FEE_JOB_WRITE_RECORD_INFO_SYNC;
    return ( eRetVal );
}

static MemIf_JobResultType Fee_JobWriteInfoSync( void )
{
    int ret = 0;
    Fee_BlockConfigType *pblock_cof = (Fee_BlockConfigType *)
                                      &Fee_BlockConfig[Fee_uJobBlockIndex];
    struct fee_dev *pfee_dev = &fee_dev[pblock_cof->pageDevIndex];

    ret = fee_write_block_info_sync(pfee_dev, pblock_cof->blockNumber,
                                    pblock_cof->blockSize);

    if (ret)
        return  MEMIF_JOB_FAILED;

    Fee_uJobBlockDataOffset = 0;
    return Fee_JobWriteData();
}

static MemIf_JobResultType Fee_JobWriteData( void )
{
    Fls_LengthType rlen = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    Fee_BlockConfigType *pblock_cof = (Fee_BlockConfigType *)
                                      &Fee_BlockConfig[Fee_uJobBlockIndex];
    struct fee_dev *pfee_dev = &fee_dev[pblock_cof->pageDevIndex];

    rlen = fee_write_block_data(pfee_dev, pblock_cof->blockNumber,
                                (uint8 *)(Fee_pJobWriteDataDestPtr + Fee_uJobBlockDataOffset),
                                pblock_cof->blockSize - Fee_uJobBlockDataOffset);

    if (!rlen)
        return  MEMIF_JOB_FAILED;

    if (rlen == pblock_cof->blockSize - Fee_uJobBlockDataOffset) {
        Fee_uJobBlockDataOffset = 0;
        Fee_eJob = FEE_JOB_WRITE_RECORD_ACTIVE;
    }
    else {
        Fee_uJobBlockDataOffset += rlen;
        Fee_eJob = FEE_JOB_WRITE_RECORD_DATA;
    }

    eRetVal = MEMIF_JOB_PENDING;
    return ( eRetVal );
}

static MemIf_JobResultType Fee_JobWriteActice( void )
{
    int ret = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    Fee_BlockConfigType *pblock_cof = (Fee_BlockConfigType *)
                                      &Fee_BlockConfig[Fee_uJobBlockIndex];
    struct fee_dev *pfee_dev = &fee_dev[pblock_cof->pageDevIndex];

    ret = fee_write_block_active(pfee_dev, pblock_cof->blockNumber);

    if (ret)
        return  MEMIF_JOB_FAILED;

    eRetVal = MEMIF_JOB_PENDING;
    Fee_eJob = FEE_JOB_WRITE_BLOCK_STATUS_SYNC;
    return ( eRetVal );
}

static MemIf_JobResultType Fee_JobWriteStatusSync( void )
{
    int ret = 0;
    Fee_BlockConfigType *pblock_cof = (Fee_BlockConfigType *)
                                      &Fee_BlockConfig[Fee_uJobBlockIndex];
    struct fee_dev *pfee_dev = &fee_dev[pblock_cof->pageDevIndex];

    ret = fee_write_block_data_sync(pfee_dev, pblock_cof->blockNumber,
                                    pblock_cof->blockSize);

    if (ret)
        return  MEMIF_JOB_FAILED;

    return Fee_JobWriteValid();
}

static MemIf_JobResultType Fee_JobWriteValid( void )
{
    int ret = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    Fee_BlockConfigType *pblock_cof = (Fee_BlockConfigType *)
                                      &Fee_BlockConfig[Fee_uJobBlockIndex];
    struct fee_dev *pfee_dev = &fee_dev[pblock_cof->pageDevIndex];
    boolean block_valid = 0;

    ret = fee_write_block_valid(pfee_dev, pblock_cof->blockNumber, &block_valid);

    if (ret)
        return  MEMIF_JOB_FAILED;

    if (block_valid) {
        eRetVal = MEMIF_JOB_PENDING;
        Fee_eJob = FEE_JOB_WRITE_END;
    }
    else {
        eRetVal = Fee_JobWriteEnd();
    }

    return ( eRetVal );
}

static MemIf_JobResultType Fee_JobWriteEnd( void )
{
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    Fee_eJob = FEE_JOB_DONE;
    return ( eRetVal );
}

static MemIf_JobResultType Fee_JobInvalBlock( void )
{
    int ret = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    Fee_BlockConfigType *pblock_cof = (Fee_BlockConfigType *)
                                      &Fee_BlockConfig[Fee_uJobBlockIndex];
    struct fee_dev *pfee_dev = &fee_dev[pblock_cof->pageDevIndex];
    boolean block_valid = 0;

    ret = fee_write_block_invalid(pfee_dev, pblock_cof->blockNumber, &block_valid);

    if (ret)
        return  MEMIF_JOB_FAILED;

    if (block_valid) {
        eRetVal = MEMIF_JOB_PENDING;
        Fee_eJob = FEE_JOB_DONE;
    }
    else {
        eRetVal = MEMIF_JOB_OK;
        Fee_eJob = FEE_JOB_DONE;
    }

    return ( eRetVal );
}

static MemIf_JobResultType Fee_JobEraseImmediate( void )
{
    int ret = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    Fee_BlockConfigType *pblock_cof = (Fee_BlockConfigType *)
                                      &Fee_BlockConfig[Fee_uJobBlockIndex];
    struct fee_dev *pfee_dev = &fee_dev[pblock_cof->pageDevIndex];
    boolean page_swap = 0;

    ret = fee_write_block_check(pfee_dev, pblock_cof->blockNumber,
                                (uint8 *)Fee_pJobWriteDataDestPtr, pblock_cof->blockSize,
                                pblock_cof->immediateData, &page_swap);

    if (ret)
        return  MEMIF_JOB_FAILED;

    if (page_swap) {
        Fee_uJobIntSwapClrGrpIt = pblock_cof->pageDevIndex;

        ret = fee_swap_cfg(pfee_dev, &fee_active_page, &fee_backup_page);

        if (ret) {
            return  MEMIF_JOB_FAILED;
        }

        fee_swap_type = FEE_SWAP_IMMEDIATE;
        fee_swap_flag = TRUE;
        eRetVal = Fee_JobSwapActivePageValid();
    }

    return ( eRetVal );
}

static MemIf_JobResultType Fee_JobValidCheck( uint16 uJobBlockIndex )
{
    int ret = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    Fee_BlockConfigType *pblock_cof = (Fee_BlockConfigType *)
                                      &Fee_BlockConfig[uJobBlockIndex];
    struct fee_dev *pfee_dev = &fee_dev[pblock_cof->pageDevIndex];

    ret = fee_block_valid_check(pfee_dev, uJobBlockIndex);

    if (!ret)
        return  MEMIF_JOB_FAILED;

    return eRetVal;
}

static MemIf_JobResultType Fee_JobInvalidCheck( uint16 uJobBlockIndex )
{
    int ret = 0;
    MemIf_JobResultType eRetVal = MEMIF_JOB_OK;
    Fee_BlockConfigType *pblock_cof = (Fee_BlockConfigType *)
                                      &Fee_BlockConfig[uJobBlockIndex];
    struct fee_dev *pfee_dev = &fee_dev[pblock_cof->pageDevIndex];

    ret = fee_block_invalid_check(pfee_dev, uJobBlockIndex);

    if (ret)
        return  MEMIF_JOB_FAILED;

    return eRetVal;
}

static Fee_Erase_JobResultType FeeErase_JobInit( void )
{
    Fee_Erase_JobResultType eRetVal = FEE_ERASE_JOB_OK;

    FeeErase_uBlockOffset = 0;
    eRetVal = FeeErase_JobIErase();
    return eRetVal;
}

static Fee_Erase_JobResultType FeeErase_JobIErase( void )
{
    int ret = 0;
    Fee_Erase_JobResultType eRetVal = FEE_ERASE_JOB_OK;
    struct fee_dev *pfee_dev = &fee_dev[FeeErase_uDevIndex];
    Fls_LengthType page_size = pfee_dev->page_info[FeeErase_uPageIndex].page_size;
    uint32 erase_size = pfee_dev->page_info[FeeErase_uPageIndex].erase_size;

    if (page_size == FeeErase_uBlockOffset) {

        FeeErase_eJob = FEE_ERASE_JOB_DONE;
        eRetVal = FeeErase_JobEnd();

    }
    else {
        erase_size = _MIN(erase_size, page_size - FeeErase_uBlockOffset);
        ret = fee_erase_page_block(pfee_dev, FeeErase_uPageIndex, FeeErase_uBlockOffset,
                                   erase_size);

        if (ret) {
            eRetVal = FEE_ERASE_JOB_PENDING;
            FeeErase_eJob = FEE_ERASE_JOB_ERASE;
        }
        else {
            eRetVal = FEE_ERASE_JOB_PENDING;
            FeeErase_eJob = FEE_ERASE_JOB_ERASE;
            FeeErase_eStatus = FEE_ERASE_BUSY;
            FeeErase_uBlockOffset += erase_size;
        }
    }

    return eRetVal;
}

static Fee_Erase_JobResultType FeeErase_JobEnd( void )
{
    Fee_Erase_JobResultType eRetVal = FEE_ERASE_JOB_OK;
    return eRetVal;
}

/******************************************************************************
** Service name        : Fee_JobSchedule                                        **
** Parameters (in)     : None                                                   **
** Parameters (out)    : None                                                   **
** Return value        : MemIf_JobResultType                                    **
** Description        : Schedule subsequent jobs                                **
******************************************************************************/
static MemIf_JobResultType Fee_JobSchedule( void )
{
    MemIf_JobResultType eRetVal = MEMIF_JOB_FAILED;

    switch ( Fee_eJob ) {
        /* Fee_Init() related jobs */
        case FEE_JOB_INT:
            eRetVal = Fee_JobInt();
            break;

        case FEE_JOB_INT_READ_PAGE_INFO:
            eRetVal = Fee_JobIntReadPageInfo();
            break;

        case FEE_JOB_INT_CHECK_ERASE_PAGE_INFO:
            eRetVal = Fee_JobIntCheckErasePageInfo();
            break;

        case FEE_JOB_INT_ERASE_SECTOR_READ:
            eRetVal = Fee_JobIntEraseSectorRead();
            break;

        case FEE_JOB_INT_ERASE_SECTOR_STATUS_CHECK:
            eRetVal = Fee_JobIntEraseSectorStatusCheck();
            break;

        case FEE_JOB_INT_ACTIVE_PAGE:
            eRetVal = Fee_JobIntActivePage();
            break;

        case FEE_JOB_INT_GET_RECORD:
            eRetVal = Fee_JobIntGetRecord();
            break;

        case FEE_JOB_INT_RECORD_PARES:
            eRetVal = Fee_JobIntRecordPares();
            break;

#if (FEE_CHECKSUM_SUPPORTED == STD_ON)

        case FEE_JOB_INT_GET_DATA_OFFSET:
            eRetVal = Fee_JobIntGetDataOffset();
            break;

        case FEE_JOB_INT_CHECK_DATA_OFFSET:
            eRetVal = Fee_JobIntCheckDataOffset();
            break;
#endif

        case FEE_JOB_INT_CHECK_STATUS:
            eRetVal = Fee_JobIntCheckStatus();
            break;

        case FEE_JOB_INT_FORMAT:
            eRetVal = Fee_JobIntFormat();
            break;

        case FEE_JOB_INT_FORMAT_ACTIVE:
            eRetVal = Fee_JobIntFormatActive();
            break;

        case FEE_JOB_INT_SWAP:
            eRetVal = Fee_JobIntSwap();
            break;

        case FEE_JOB_INT_END:
            eRetVal = Fee_JobIntEnd();
            break;

        case FEE_JOB_READ:
            eRetVal = Fee_JobRead();
            break;

#if (FEE_CHECKSUM_SUPPORTED == STD_ON)

        case FEE_JOB_READ_HEAD_DATA:
            eRetVal = Fee_JobReadHeadData();
            break;

        case FEE_JOB_READ_HEAD_DATA_CRC:
            eRetVal = Fee_JobReadHeadDataCRC();
            break;
#endif

        case FEE_JOB_READ_RECORD_DATA:
            eRetVal = Fee_JobReadRecordData();
            break;

        case FEE_JOB_READ_RECORD_DATA_SYNC:
            eRetVal = Fee_JobReadRecordDataSync();
            break;

#if (FEE_CHECKSUM_SUPPORTED == STD_ON)

        case FEE_JOB_READ_RECORD_DATA_CRC:
            eRetVal = Fee_JobReadRecordDataCRC();
            break;

        case FEE_JOB_READ_TAIL_DATA:
            eRetVal = Fee_JobReadTailData();
            break;

        case FEE_JOB_READ_TAIL_DATA_CRC:
            eRetVal = Fee_JobReadTailDataCRC();
            break;

        case FEE_JOB_READ_CHECK_DATA_CRC:
            eRetVal = Fee_JobReadDataChecksum();
            break;
#endif

        case FEE_JOB_READ_END:
            eRetVal = Fee_JobReadEnd();
            break;

        case FEE_JOB_WRITE:
            eRetVal = Fee_JobWrite();
            break;

        case FEE_JOB_WRITE_SWAP:
            eRetVal = Fee_JobWriteSwap();
            break;

        case FEE_JOB_WRITE_RECORD_INFO:
            eRetVal = Fee_JobWriteInfo();
            break;

        case FEE_JOB_WRITE_RECORD_INFO_SYNC:
            eRetVal = Fee_JobWriteInfoSync();
            break;

        case FEE_JOB_WRITE_RECORD_DATA:
            eRetVal = Fee_JobWriteData();
            break;

        case FEE_JOB_WRITE_RECORD_ACTIVE:
            eRetVal = Fee_JobWriteActice();
            break;

        case FEE_JOB_WRITE_BLOCK_STATUS_SYNC:
            eRetVal = Fee_JobWriteStatusSync();
            break;

        case FEE_JOB_WRITE_BLOCK_VALID:
            eRetVal = Fee_JobWriteValid();
            break;

        case FEE_JOB_WRITE_END:
            eRetVal = Fee_JobWriteEnd();
            break;

        case FEE_JOB_SWAP_ACTIVE_PAGE_VALID:
            eRetVal = Fee_JobSwapActivePageValid();
            break;

        case FEE_JOB_SWAP_BACKUP_PAGE_RECEIVE:
            eRetVal = Fee_JobSwapBackupPageReceive();
            break;

        case FEE_JOB_SWAP_DATA:
            eRetVal = Fee_JobSwapData();
            break;

        case FEE_JOB_SWAP_WRITE_INFO:
            eRetVal = Fee_JobSwapInfo();
            break;

        case FEE_JOB_SWAP_WRITE_INFO_SYNC:
            eRetVal = Fee_JobSwapInfoSync();
            break;

        case FEE_JOB_SWAP_READ_DATA:
            eRetVal = Fee_JobSwapReadData();
            break;

        case FEE_JOB_SWAP_WRITE_DATA:
            eRetVal = Fee_JobSwapWriteData();
            break;

        case FEE_JOB_SWAP_STATUS_SYNC:
            eRetVal = Fee_JobSwapStatusSync();
            break;

        case FEE_JOB_SWAP_BACKUP_PAGE_ACTIVE:
            eRetVal = Fee_JobSwapBackupPageActive();
            break;

        case FEE_JOB_SWAP_ACTIVE_PAGE_ERASING:
            eRetVal = Fee_JobSwapActivePageErasing();
            break;

        case FEE_JOB_SWAP_ACTIVE_PAGE_ERASE:
            eRetVal = Fee_JobSwapActivePageErase();
            break;

        case FEE_JOB_INVAL_BLOCK:
            eRetVal = Fee_JobInvalBlock();
            break;

        case FEE_JOB_ERASE_IMMEDIATE:
            eRetVal = Fee_JobEraseImmediate();
            break;

        case FEE_JOB_FAILED:
            break;

        /* if the job is finished switch case will break */
        case FEE_JOB_DONE:
            /* Do nothing */
            break;

        default:
            /* Compiler_Warning: This default branch will never be reached in FTE */
            break;
    }

    return ( eRetVal );
}

/******************************************************************************
** Service name        : Fee_Init                                               **
** Parameters (in)     : paConfigPtr  Pointer to block configuration set        **
** Parameters (out)    : None                                                   **
** Return value        : None                                                   **
** Description        : Initializes the FEE                                     **
******************************************************************************/
void Fee_Init(const Fee_ConfigType *paConfigPtr )
{
#if (FEE_DEV_ERROR_DETECT == STD_ON)

    if (NULL_PTR != paConfigPtr) {
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_INIT_ID,
                         FEE_E_PARAM_POINTER);
    }
    else if ( MEMIF_BUSY == Fee_eModuleStatus ) {
        Det_ReportRuntimeError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_INIT_ID,
                                FEE_E_BUSY );
    }
    else if ( MEMIF_BUSY_INTERNAL == Fee_eModuleStatus ) {
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_INIT_ID,
                         FEE_E_INTERNAL_BUSY);
    }

#endif  /* #if (FEE_DEV_ERROR_DETECT == STD_ON) */

    /* Schedule init job */
    Fee_eJob = FEE_JOB_INT;

    Fee_eModuleStatus = MEMIF_BUSY_INTERNAL;

    Fee_eJobResult = MEMIF_JOB_PENDING;
}

/******************************************************************************
** Service name        : Fee_SetMode                                            **
** Parameters (in)     : MemIf_ModeType Mode (Mode MEMIF_MODE_SLOW /            **
**                                         MEMIF_MODE_FAST)                     **
** Parameters (out)    : None                                                   **
** Return value        : void                                                   **
** Description        : Call the Fls_SetMode function                           **
******************************************************************************/
void Fee_SetMode( MemIf_ModeType eMode )
{
#if (FEE_DEV_ERROR_DETECT == STD_ON)

    if ( MEMIF_UNINIT == Fee_eModuleStatus ) {
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SETMODE_ID,
                         FEE_E_UNINIT );
    }
    else if ( MEMIF_BUSY == Fee_eModuleStatus ) {
        Det_ReportRuntimeError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SETMODE_ID,
                                FEE_E_BUSY );
    }
    else if ( MEMIF_BUSY_INTERNAL == Fee_eModuleStatus ) {
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SETMODE_ID,
                         FEE_E_INTERNAL_BUSY);
    }
    else
#else
    if ( MEMIF_IDLE == Fee_eModuleStatus )
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
    {
        Fls_SetMode( eMode );
    }
}

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
                                uint16 uLength )
{
    Std_ReturnType uRetVal = (Std_ReturnType)E_OK;
    uint16 uBlockIndex = Fee_GetBlockIndex(uBlockNumber);

    if ( MEMIF_UNINIT == Fee_eModuleStatus ) {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_READ_ID,
                         FEE_E_UNINIT );
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if ( MEMIF_BUSY == Fee_eModuleStatus ) {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        Det_ReportRuntimeError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_READ_ID,
                                FEE_E_BUSY );
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if ( MEMIF_BUSY_INTERNAL == Fee_eModuleStatus ) {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_READ_ID,
                         FEE_E_INTERNAL_BUSY);
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }

#if (FEE_DEV_ERROR_DETECT == STD_ON)
    else if ( FEE_BLOCK_INDEX_DEF == uBlockIndex ) {
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_READ_ID,
                         FEE_E_INVALID_BLOCK_NO);
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if ( uBlockOffset >= Fee_BlockConfig[uBlockIndex].blockSize ) {
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_READ_ID,
                         FEE_E_INVALID_BLOCK_OFS);
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if ((0U == uLength)
             || ((uBlockOffset + uLength) > Fee_BlockConfig[uBlockIndex].blockSize)) {
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_READ_ID,
                         FEE_E_INVALID_BLOCK_LEN);
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if ( uBlockOffset >= block_status[uBlockIndex].block_size ) {
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_READ_ID,
                         FEE_E_INVALID_RECORD_OFS);
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if ((uBlockOffset + uLength) > block_status[uBlockIndex].block_size) {
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_READ_ID,
                         FEE_E_INVALID_RECORD_LEN);
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if ( NULL_PTR == pDataBufferPtr ) {
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_READ_ID,
                         FEE_E_PARAM_POINTER);
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }

#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
    else if (Fee_JobValidCheck(uBlockIndex) != MEMIF_JOB_OK) {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_READ_ID,
                         FEE_E_NOT_VALID_BLOCK);
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (Fee_JobInvalidCheck(uBlockIndex) != MEMIF_JOB_OK) {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_READ_ID,
                         FEE_E_CFG_INVALID_BLOCK);
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
        uRetVal = (Std_ReturnType)E_NOT_OK;
        Fee_eJobResult = MEMIF_BLOCK_INVALID;
    }

#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
    else if (block_status[uBlockIndex].checksum_error == 1) {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_READ_ID,
                         FEE_E_CHECKSUM_ERROR);
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
        uRetVal = (Std_ReturnType)E_NOT_OK;
        Fee_eJobResult = MEMIF_BLOCK_INVALID;
    }

#endif

    else {

        /* Configure the read job */
        Fee_uJobBlockIndex = uBlockIndex;

        Fee_uJobBlockOffset = uBlockOffset;

        Fee_uJobBlockLength = uLength;
        Fee_pJobReadDataDestPtr = pDataBufferPtr;

        Fee_eJob = FEE_JOB_READ;

        Fee_eModuleStatus = MEMIF_BUSY;

        /* Execute the read job */
        Fee_eJobResult = MEMIF_JOB_PENDING;
    }

    return ( uRetVal );
}

/******************************************************************************
** Service name        : Fee_Write                                              **
** Parameters (in)     : uint16 uBlockNumber :block number                      **
**                      const uint8* pDataBufferPtr :Pointer to data buffer     **
** Parameters (out)    : None                                                   **
** Return value        : Std_ReturnType ( E_OK / E_NOT_OK )                     **
** Description        : Writes to fee block                                     **
******************************************************************************/
Std_ReturnType Fee_Write( uint16 uBlockNumber,
                          const uint8 *pDataBufferPtr )
{
    Std_ReturnType uRetVal = (Std_ReturnType)E_OK;
    uint16 uBlockIndex = Fee_GetBlockIndex(uBlockNumber);

    if ( MEMIF_UNINIT == Fee_eModuleStatus ) {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_WRITE_ID,
                         FEE_E_UNINIT );
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if ( MEMIF_BUSY == Fee_eModuleStatus ) {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        Det_ReportRuntimeError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_WRITE_ID,
                                FEE_E_BUSY );
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }

#if (FEE_DEV_ERROR_DETECT == STD_ON)
    else if ( FEE_BLOCK_INDEX_DEF == uBlockIndex ) {
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_WRITE_ID,
                         FEE_E_INVALID_BLOCK_NO);
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if ( MEMIF_BUSY_INTERNAL == Fee_eModuleStatus ) {
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_WRITE_ID,
                         FEE_E_INTERNAL_BUSY);
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if ( NULL_PTR == pDataBufferPtr ) {
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_WRITE_ID,
                         FEE_E_PARAM_POINTER);

        uRetVal = (Std_ReturnType)E_NOT_OK;
    }

#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
    else if (Fee_JobInvalidCheck(uBlockIndex) != MEMIF_JOB_OK) {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_WRITE_ID,
                         FEE_E_CFG_INVALID_BLOCK);
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
        uRetVal = (Std_ReturnType)E_NOT_OK;
        Fee_eJobResult = MEMIF_BLOCK_INVALID;
        /*PRQA S 2995 4*/
    }
    else {

        /* Configure the write job */
        Fee_uJobBlockIndex = uBlockIndex;
        Fee_pJobWriteDataDestPtr = pDataBufferPtr;

        Fee_eJob = FEE_JOB_WRITE;

        Fee_eModuleStatus = MEMIF_BUSY;

        /* Execute the write job */
        Fee_eJobResult = MEMIF_JOB_PENDING;

    }

    return ( uRetVal );
}

/******************************************************************************
** Service name        : Fee_Cancel                                             **
** Parameters (in)     : None                                                   **
** Parameters (out)    : None                                                   **
** Return value        : None                                                   **
** Description        : Cancels an ongoing job                                  **
******************************************************************************/
void Fee_Cancel( void )
{
#if (FEE_CANCEL_API == STD_OFF)
#if (FEE_DEV_ERROR_DETECT == STD_ON)
    Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_CANCEL_ID,
                     FEE_E_CANCEL_API_UNDEF );
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */

#else

#if (FEE_DEV_ERROR_DETECT == STD_ON)

    if ( MEMIF_UNINIT == Fee_eModuleStatus ) {
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_CANCEL_ID,
                         FEE_E_UNINIT );
    }
    else {
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */

        if ( MEMIF_JOB_PENDING == Fee_eJobResult ) {
            /* Cancel ongoing Fls job if any */
            if ( MEMIF_BUSY == Fee_eModuleStatus ) {
                Fee_eJobResult = MEMIF_JOB_CANCELED;
                Fee_eJob = FEE_JOB_DONE;
                Fls_Cancel();
                Fee_eModuleStatus = MEMIF_IDLE;
            }
            else {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
                Det_ReportRuntimeError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_CANCEL_ID,
                                        FEE_E_INVALID_CANCEL );
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
            }
        }
        else {
            /* Leave the job result unchanged */
        }

#if (FEE_DEV_ERROR_DETECT == STD_ON)
    }

#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */

#endif    /* FLS_CANCEL_API == STD_ON */

}

/******************************************************************************
** Service name        : Fee_GetStatus                                          **
** Parameters (in)     : None                                                   **
** Parameters (out)    : None                                                   **
** Return value        : MemIf_StatusType                                       **
** Description        : Returns the fee state                                **
******************************************************************************/
MemIf_StatusType Fee_GetStatus( void )
{
    return ( Fee_eModuleStatus );
}

/******************************************************************************
** Service name        : Fee_GetJobResult                                       **
** Parameters (in)     : None                                                   **
** Parameters (out)    : None                                                   **
** Return value        : MemIf_JobResultType                                    **
** Description        : Returns the result of the last job                      **
******************************************************************************/
MemIf_JobResultType Fee_GetJobResult( void )
{
    MemIf_JobResultType eRetVal = Fee_eJobResult;

#if (FEE_DEV_ERROR_DETECT == STD_ON)

    if ( MEMIF_UNINIT == Fee_eModuleStatus ) {
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_GETJOBRESULT_ID,
                         FEE_E_UNINIT);
        eRetVal = MEMIF_JOB_FAILED;
    }

#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */

    return ( eRetVal );
}

/******************************************************************************
** Service name        : Fee_InvalidateBlock                                    **
** Parameters (in)     : uint16 uBlockNumber :block number                      **
** Parameters (out)    : None                                                   **
** Return value        : Std_ReturnType ( E_OK / E_NOT_OK )                     **
** Description         : set fee block invalid                                  **
******************************************************************************/
Std_ReturnType Fee_InvalidateBlock( uint16 uBlockNumber )
{
    Std_ReturnType uRetVal = (Std_ReturnType)E_OK;
    uint16 uBlockIndex = Fee_GetBlockIndex(uBlockNumber);

#if (FEE_DEV_ERROR_DETECT == STD_ON)

    if ( MEMIF_UNINIT == Fee_eModuleStatus ) {
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_INVALIDATEBLOCK_ID,
                         FEE_E_UNINIT);
    }
    else if ( FEE_BLOCK_INDEX_DEF == uBlockIndex ) {
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_INVALIDATEBLOCK_ID,
                         FEE_E_INVALID_BLOCK_NO);
    }
    else if ( MEMIF_BUSY == Fee_eModuleStatus ) {
        Det_ReportRuntimeError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID,
                                FEE_INVALIDATEBLOCK_ID, FEE_E_BUSY );
    }
    else if ( MEMIF_BUSY_INTERNAL == Fee_eModuleStatus ) {
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_INVALIDATEBLOCK_ID,
                         FEE_E_INTERNAL_BUSY);
    }
    else
#else
    if ( MEMIF_IDLE == Fee_eModuleStatus )
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
    {

        /* Configure the invalidate block job */
        Fee_uJobBlockIndex = uBlockIndex;

        Fee_eJob = FEE_JOB_INVAL_BLOCK;

        Fee_eModuleStatus = MEMIF_BUSY;

        /* Execute the invalidate block job */
        Fee_eJobResult = MEMIF_JOB_PENDING;

        uRetVal = (Std_ReturnType)E_OK;
    }

    return ( uRetVal );
}

/******************************************************************************
** Service name        : Fee_GetVersionInfo                                     **
** Parameters (in)     : Std_VersionInfoType pVersionInfoPtr :                  **
**                          Pointer to VersionInfo buffer                       **
** Parameters (out)    : None                                                   **
** Return value        : None                                                   **
** Description         : get fee VersionInfo                                    **
******************************************************************************/
#if (FEE_VERSION_INFO_API == STD_ON)
void Fee_GetVersionInfo( Std_VersionInfoType *pVersionInfoPtr )
{
#if (FEE_DEV_ERROR_DETECT == STD_ON)

    if ( NULL_PTR == pVersionInfoPtr ) {
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_GETVERSIONINFO_ID,
                         FEE_E_PARAM_POINTER);

    }
    else {
#endif /* FEE_DEV_ERROR_DETECT == STD_ON */
        pVersionInfoPtr->moduleID = (uint16)FEE_MODULE_ID;
        pVersionInfoPtr->vendorID = (uint16)FEE_VENDOR_ID;
        pVersionInfoPtr->sw_major_version = (uint8)FEE_SW_MAJOR_VERSION;
        pVersionInfoPtr->sw_minor_version = (uint8)FEE_SW_MINOR_VERSION;
        pVersionInfoPtr->sw_patch_version = (uint8)FEE_SW_PATCH_VERSION;
#if (FEE_DEV_ERROR_DETECT == STD_ON)
    }

#endif /* FEE_DEV_ERROR_DETECT == STD_ON */
}
#endif

/******************************************************************************
** Service name        : Fee_EraseImmediateBlock                                **
** Parameters (in)     : uint16 uBlockNumber :block number                      **
** Parameters (out)    : None                                                   **
** Return value        : Std_ReturnType ( E_OK / E_NOT_OK )                     **
** Description         : fee erase immediate block                              **
******************************************************************************/
Std_ReturnType Fee_EraseImmediateBlock( uint16 uBlockNumber )
{
    Std_ReturnType uRetVal = (Std_ReturnType)E_OK;
    uint16 uBlockIndex = Fee_GetBlockIndex(uBlockNumber);

#if (FEE_DEV_ERROR_DETECT == STD_ON)

    if ( MEMIF_UNINIT == Fee_eModuleStatus ) {
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID,
                         FEE_ERASEIMMEDIATEBLOCK_ID, FEE_E_UNINIT);
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if ( FEE_BLOCK_INDEX_DEF == uBlockIndex ) {
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID,
                         FEE_ERASEIMMEDIATEBLOCK_ID, FEE_E_INVALID_BLOCK_NO);
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if ( (boolean)FALSE == Fee_BlockConfig[uBlockIndex].immediateData ) {
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID,
                         FEE_ERASEIMMEDIATEBLOCK_ID, FEE_E_INVALID_BLOCK_NO);
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if ( MEMIF_BUSY == Fee_eModuleStatus ) {
        Det_ReportRuntimeError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID,
                                FEE_ERASEIMMEDIATEBLOCK_ID, FEE_E_BUSY );
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if ( MEMIF_BUSY_INTERNAL == Fee_eModuleStatus ) {
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID,
                         FEE_ERASEIMMEDIATEBLOCK_ID, FEE_E_INTERNAL_BUSY);
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else {
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */

        /* Configure the erase immediate block job */
        Fee_uJobBlockIndex = uBlockIndex;

        Fee_eJob = FEE_JOB_ERASE_IMMEDIATE;

        Fee_eModuleStatus = MEMIF_BUSY;

        /* Execute the erase immediate block job */
        Fee_eJobResult = MEMIF_JOB_PENDING;
#if (FEE_DEV_ERROR_DETECT == STD_ON)
    }

#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */

    return ( uRetVal );

}

/******************************************************************************
** Service name        : Fee_GetBlockPageid                                     **
** Parameters (in)     : uint16 uBlockNumber :block number                      **
** Parameters (out)    : None                                                   **
** Return value        : None                                                   **
** Description        : The page ID currently in use                            **
******************************************************************************/
Std_ReturnType Fee_GetBlockPageid( uint16 uBlockNumber, uint16 *page_id )
{
    Std_ReturnType uRetVal = (Std_ReturnType)E_OK;
    uint16 uBlockIndex = Fee_GetBlockIndex(uBlockNumber);

    if ( FEE_BLOCK_INDEX_DEF == uBlockIndex ) {
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if ( NULL_PTR == page_id ) {
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else {

        Fee_BlockConfigType *pblock_cof = (Fee_BlockConfigType *)
                                          &Fee_BlockConfig[uBlockIndex];
        struct fee_dev *pfee_dev = &fee_dev[pblock_cof->pageDevIndex];

        *page_id = pfee_dev->current_page;
    }

    return ( uRetVal );
}

/******************************************************************************
** Service name        : Fee_GetAvailableSpace                                  **
** Parameters (in)     : uint16 uBlockNumber :block number                      **
** Parameters (out)    : None                                                   **
** Return value        : None                                                   **
** Description        : Remaining free space on the current page                **
******************************************************************************/
Std_ReturnType Fee_GetAvailableSpace( uint16 uBlockNumber,
                                      Fls_LengthType *free_size )
{
    Std_ReturnType uRetVal = (Std_ReturnType)E_OK;
    uint16 uBlockIndex = Fee_GetBlockIndex(uBlockNumber);

    if ( FEE_BLOCK_INDEX_DEF == uBlockIndex ) {
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if ( NULL_PTR == free_size ) {
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else {

        Fee_BlockConfigType *pblock_cof = (Fee_BlockConfigType *)
                                          &Fee_BlockConfig[uBlockIndex];
        struct fee_dev *pfee_dev = &fee_dev[pblock_cof->pageDevIndex];
        uint16 page_number = pfee_dev->current_page;
        /* One more record info space must be reserved for initial use of the record index offset */
        Fls_LengthType used_size = sizeof(struct fee_page_info) +
                                   pfee_dev->record_data_offset + (pfee_dev->record_info_offset * sizeof(
                                               struct fee_record_info) + sizeof(struct fee_record_info));

        if (pblock_cof->immediateData) {
            used_size += sizeof(struct fee_record_info);
        }
        else {
            used_size += (pfee_dev->disk_reserved_size + sizeof(struct fee_record_info));
        }

        if (pfee_dev->page_info[page_number].page_size > used_size)
            *free_size =  pfee_dev->page_info[page_number].page_size - used_size;
        else
            *free_size = 0;

    }

    return ( uRetVal );
}

/******************************************************************************
** Service name        : FeeErase_GetStatus                                     **
** Parameters (in)     : None                                                   **
** Parameters (out)    : None                                                   **
** Return value        : None                                                   **
** Description        : Returns the fee erase state                             **
******************************************************************************/
Fee_Erase_StatusType FeeErase_GetStatus( void )
{
    return ( FeeErase_eStatus );
}

/******************************************************************************
** Service name        : FeeErase_GetJobResult                                  **
** Parameters (in)     : None                                                   **
** Parameters (out)    : None                                                   **
** Return value        : None                                                   **
** Description        : Returns the result of the fee erase job                 **
******************************************************************************/
Fee_Erase_JobResultType FeeErase_GetJobResult( void )
{
    Fee_Erase_JobResultType eRetVal = FeeErase_eJobResult;

#if (FEE_DEV_ERROR_DETECT == STD_ON)

    if ( MEMIF_UNINIT == Fee_eModuleStatus ) {
        eRetVal = FEE_ERASE_JOB_FAILED;
    }

#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */

    return ( eRetVal );
}

/*************************************************************************************************
** Service name        : Fee_JobEndNotification                                                 **
** Parameters (in)     : None                                                                   **
** Parameters (out)    : None                                                                   **
** Return value        : None                                                                   **
** Description         : report the FEE module the successful end of an asynchronous operation  **
**************************************************************************************************/
void Fee_JobEndNotification( void )
{
    if ( MEMIF_UNINIT == Fee_eModuleStatus ) {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID,
                         FEE_JOBENDNOTIFICATION_ID, FEE_E_UNINIT);
#else
        /* Do nothing. Fee is not initialized */
#endif  /* FEE_DEV_ERROR_DETECT == STD_ON */
    }
    else {

        if ((FEE_ERASE_JOB_PENDING == FeeErase_eJobResult)
                && (FEE_ERASE_BUSY == FeeErase_eStatus)) {

            FeeErase_eJobResult = FEE_ERASE_JOB_PENDING;
            FeeErase_eStatus = FEE_ERASE_IDLE;

        }
        else if ( MEMIF_JOB_PENDING == Fee_eJobResult) {
            if ( FEE_JOB_DONE == Fee_eJob ) {
                /* Last schedule Fls job finished */
                Fee_eJobResult = Fls_GetJobResult();

                if ( MEMIF_BUSY_INTERNAL == Fee_eModuleStatus ) {
                    /* no notifications from internal jobs */
                    Fee_eModuleStatus = MEMIF_IDLE;
                }
                else {
                    Fee_eModuleStatus = MEMIF_IDLE;

                    /* Call job end notification function */
                    FEE_NVM_JOB_END_NOTIFICATION
                }
            }
            else {
                Fee_eJobResult = Fee_JobSchedule();

                if ( MEMIF_JOB_OK == Fee_eJobResult ) {
                    if ( MEMIF_BUSY_INTERNAL == Fee_eModuleStatus ) {
                        /* no notifications from internal jobs */
                        Fee_eModuleStatus = MEMIF_IDLE;
                    }
                    else {
                        Fee_eModuleStatus = MEMIF_IDLE;

                        /* Call job end notification function */
                        FEE_NVM_JOB_END_NOTIFICATION
                    }
                }
                else if ( MEMIF_JOB_PENDING == Fee_eJobResult ) {
                    /* Nothing to do (ongoing Fls job) */
                }
                else {
                    if ( MEMIF_BUSY_INTERNAL == Fee_eModuleStatus ) {
                        /* no notifications from internal jobs */
                        Fee_eModuleStatus = MEMIF_UNINIT;
                    }
                    else {
                        Fee_eModuleStatus = MEMIF_IDLE;

                        /* Call job error notification function */
                        FEE_NVM_JOB_ERROR_NOTIFICATION
                    }
                }
            }
        }
    }

}

/*************************************************************************************************
** Service name        : Fee_JobErrorNotification                                               **
** Parameters (in)     : None                                                                   **
** Parameters (out)    : None                                                                   **
** Return value        : None                                                                   **
** Description         : report the FEE module the failure end of an asynchronous operation     **
**************************************************************************************************/
void Fee_JobErrorNotification( void )
{
    if ( MEMIF_UNINIT == Fee_eModuleStatus ) {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID,
                         FEE_JOBERRORNOTIFICATION_ID, FEE_E_UNINIT);
#else
        /* Do nothing. Fee is not initialized */
#endif  /* FEE_DEV_ERROR_DETECT == STD_ON */
    }
    else {

        if ((FEE_ERASE_JOB_PENDING == FeeErase_eJobResult)
                && (FEE_ERASE_BUSY == FeeErase_eStatus)) {
            DBG("Fee_JobErrorNotification FeeErase_eStatus:%d FeeErase_eJob:%d FeeErase_eJobResult:%d\n",
                FeeErase_eStatus, FeeErase_eJob, FeeErase_eJobResult);
            FeeErase_eJobResult = FEE_ERASE_JOB_FAILED;
            FeeErase_eStatus = FEE_ERASE_FAILED;
        }
        else {
            DBG("Fee_JobErrorNotification Fee_eModuleStatus:%d Fee_eJob:%d Fee_eJobResult:%d\n",
                Fee_eModuleStatus, Fee_eJob, Fee_eJobResult);

            if ( MEMIF_JOB_CANCELED == Fee_eJobResult ) {
                /* Fls job has been canceled. Do nothing in this callback.
                The NvM_JobErrorNotification() callback will be called from
                the Fee_Cancel()function which called the Fls_Cancel() function */
            }
            else {
                switch ( Fee_eJob ) {
                    case FEE_JOB_ERASE_IMMEDIATE:
                    case FEE_JOB_WRITE:
                    case FEE_JOB_SWAP_ACTIVE_PAGE_VALID:
                    case FEE_JOB_SWAP_BACKUP_PAGE_RECEIVE:
                    case FEE_JOB_SWAP_DATA:
                    case FEE_JOB_SWAP_WRITE_INFO:
                    case FEE_JOB_SWAP_WRITE_INFO_SYNC:
                    case FEE_JOB_SWAP_READ_DATA:
                    case FEE_JOB_SWAP_WRITE_DATA:
                    case FEE_JOB_SWAP_STATUS_SYNC:
                    case FEE_JOB_SWAP_BACKUP_PAGE_ACTIVE:
                    case FEE_JOB_SWAP_ACTIVE_PAGE_ERASING:
                    case FEE_JOB_SWAP_ACTIVE_PAGE_ERASE:
                        if (TRUE == fee_swap_flag) {
                            fee_swap_recover(&fee_dev[Fee_uJobIntSwapClrGrpIt], fee_active_page);
                            fee_swap_flag = FALSE;
                        }

                    default:
                        Fee_eJobResult = Fls_GetJobResult();

                        if ( MEMIF_BUSY_INTERNAL == Fee_eModuleStatus ) {
                            /* No notifications from internal jobs */
                            Fee_eModuleStatus = MEMIF_UNINIT;
                        }
                        else {
                            Fee_eModuleStatus = MEMIF_IDLE;

                            /* Call job error notification function */
                            FEE_NVM_JOB_ERROR_NOTIFICATION
                        }

                        break;
                }
            }
        }
    }
}


/******************************************************************************
** Service name        : Fee_MainFunction                                       **
** Parameters (in)     : None                                                   **
** Parameters (out)    : None                                                   **
** Return value        : None                                                   **
** Description        : Performs the processing of jobs                         **
******************************************************************************/
void Fee_MainFunction( void )
{
#if (FEE_DEV_ERROR_DETECT == STD_ON)

    if ( MEMIF_UNINIT == Fee_eModuleStatus ) {
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_MAINFUNCTION_ID,
                         FEE_E_UNINIT);
    }
    else {
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */

        if ( MEMIF_JOB_PENDING == Fee_eJobResult
                && (FEE_ERASE_BUSY != FeeErase_eStatus)
                && (FEE_JOB_WRITE_ERASE_BACKUP != Fee_eJob)) {

            switch ( Fee_eJob ) {
                /* for all the following jobs subsequent jobs will be called in Fee job schedule
                   function based on Job */
                case FEE_JOB_INT:
                case FEE_JOB_READ:
                case FEE_JOB_WRITE:
                case FEE_JOB_INVAL_BLOCK:
                case FEE_JOB_ERASE_IMMEDIATE:
                case FEE_JOB_WRITE_SWAP:
                    Fee_eJobResult = Fee_JobSchedule();
                    break;

                /* for all the following jobs job end or job error notification will be called
                   based on the job result  */
                case FEE_JOB_INT_READ_PAGE_INFO:
                case FEE_JOB_INT_CHECK_ERASE_PAGE_INFO:
                case FEE_JOB_INT_ERASE_SECTOR_READ:
                case FEE_JOB_INT_ERASE_SECTOR_STATUS_CHECK:
                case FEE_JOB_INT_ACTIVE_PAGE:
                case FEE_JOB_INT_GET_RECORD:
                case FEE_JOB_INT_RECORD_PARES:
#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
                case FEE_JOB_INT_GET_DATA_OFFSET:
                case FEE_JOB_INT_CHECK_DATA_OFFSET:
#endif
                case FEE_JOB_INT_CHECK_STATUS:
                case FEE_JOB_INT_FORMAT:
                case FEE_JOB_INT_FORMAT_ACTIVE:
                case FEE_JOB_INT_SWAP:
                case FEE_JOB_INT_END:

#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
                case FEE_JOB_READ_HEAD_DATA:
                case FEE_JOB_READ_HEAD_DATA_CRC:
#endif
                case FEE_JOB_READ_RECORD_DATA:
                case FEE_JOB_READ_RECORD_DATA_SYNC:
#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
                case FEE_JOB_READ_RECORD_DATA_CRC:
                case FEE_JOB_READ_TAIL_DATA:
                case FEE_JOB_READ_TAIL_DATA_CRC:
                case FEE_JOB_READ_CHECK_DATA_CRC:
#endif
                case FEE_JOB_READ_END:

                case FEE_JOB_WRITE_RECORD_INFO:
                case FEE_JOB_WRITE_RECORD_INFO_SYNC:
                case FEE_JOB_WRITE_RECORD_DATA:
                case FEE_JOB_WRITE_RECORD_ACTIVE:
                case FEE_JOB_WRITE_BLOCK_STATUS_SYNC:
                case FEE_JOB_WRITE_BLOCK_VALID:
                case FEE_JOB_WRITE_END:

                case FEE_JOB_SWAP_ACTIVE_PAGE_VALID:
                case FEE_JOB_SWAP_BACKUP_PAGE_RECEIVE:
                case FEE_JOB_SWAP_DATA:
                case FEE_JOB_SWAP_WRITE_INFO:
                case FEE_JOB_SWAP_WRITE_INFO_SYNC:
                case FEE_JOB_SWAP_READ_DATA:
                case FEE_JOB_SWAP_WRITE_DATA:
                case FEE_JOB_SWAP_STATUS_SYNC:
                case FEE_JOB_SWAP_BACKUP_PAGE_ACTIVE:
                case FEE_JOB_SWAP_ACTIVE_PAGE_ERASING:
                case FEE_JOB_SWAP_ACTIVE_PAGE_ERASE:

                case FEE_JOB_FAILED:
                case FEE_JOB_DONE:
                default:
                    /* Internal or subsequent job */
                    break;
            }

            if ( MEMIF_JOB_PENDING == Fee_eJobResult ) {
                /* Nothing to do */
            }
            else if ( MEMIF_JOB_OK == Fee_eJobResult ) {
                if ( MEMIF_BUSY_INTERNAL == Fee_eModuleStatus ) {
                    /* no notifications from internal jobs */
                    Fee_eModuleStatus = MEMIF_IDLE;
                }
                else {
                    Fee_eModuleStatus = MEMIF_IDLE;

                    /* Call job end notification function */
                    FEE_NVM_JOB_END_NOTIFICATION
                }
            }
            else {
                if ( MEMIF_BUSY_INTERNAL == Fee_eModuleStatus ) {
                    /* no notifications from internal jobs */
                    Fee_eModuleStatus = MEMIF_UNINIT;
                }
                else {
                    Fee_eModuleStatus = MEMIF_IDLE;

                    /* Call job error notification function */
                    FEE_NVM_JOB_ERROR_NOTIFICATION
                }
            }
        }
        else if ((FEE_ERASE_JOB_PENDING == FeeErase_eJobResult)
                 && (FEE_ERASE_BUSY != FeeErase_eStatus)
                 && ((MEMIF_IDLE == Fee_eModuleStatus)
                     || (FEE_JOB_WRITE_ERASE_BACKUP == Fee_eJob))) {
            switch ( FeeErase_eJob ) {
                case FEE_ERASE_JOB_INT:
                    FeeErase_eJobResult = FeeErase_JobInit();
                    break;

                case FEE_ERASE_JOB_ERASE:
                    FeeErase_eJobResult = FeeErase_JobIErase();
                    break;

                case FEE_ERASE_JOB_DONE:
                    FeeErase_eJobResult = FeeErase_JobEnd();
                    break;
            }

            if ( FEE_ERASE_JOB_PENDING == FeeErase_eJobResult ) {
                /* Nothing to do */
                /*PRQA S 2995,2991 6*/
            }
            else if ( FEE_ERASE_JOB_OK == FeeErase_eJobResult ) {
                if (FEE_ERASE_JOB_DONE == FeeErase_eJob) {
                    FeeErase_eJobResult = FEE_ERASE_JOB_OK;
                    FeeErase_eStatus = FEE_ERASE_UNINIT;

                    if (FEE_JOB_WRITE_ERASE_BACKUP == Fee_eJob) {
                        Fee_eJob = FEE_JOB_WRITE_SWAP;
                    }
                }
                else {
                    FeeErase_eJobResult = FEE_ERASE_JOB_PENDING;
                    FeeErase_eStatus = FEE_ERASE_IDLE;
                }
            }
            else {
                FeeErase_eJobResult = FEE_ERASE_JOB_FAILED;
                FeeErase_eStatus = FEE_ERASE_FAILED;
            }

        }

#if (FEE_DEV_ERROR_DETECT == STD_ON)
    }

#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */

}

#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @}*/
