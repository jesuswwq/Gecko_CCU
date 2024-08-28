/**
 * @file fee_ops.c
 *
 * Copyright (c) 2022 Semidrive Semiconductor.
 * All rights reserved.
 *
 * Description:
 *
 * Revision History:
 * -----------------
 */
#include "cdefs.h"
#include "cdefs.h"
#include "Fls.h"
#include "Fee.h"
#include "fee_ops.h"
#include "Fee_Cfg.h"
#include "debug.h"
#include "mini_libc.h"
#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
#include "crc16.h"
#endif

#define FEE_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Fee_MemMap.h"

/* record info buff */
static uint8 record_info_buff[FEE_INFO_CACHE_SIZE + CONFIG_ARCH_CACHE_LINE];
static uint8 record_data_buff[FEE_DATA_CACHE_SIZE + CONFIG_ARCH_CACHE_LINE];
#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
uint8 block_buff[FEE_DATA_CACHE_SIZE + CONFIG_ARCH_CACHE_LINE];
#endif
static char page0_sector_buf[FEE_SECTOR_BUFF_SIZE + CONFIG_ARCH_CACHE_LINE];
static char page1_sector_buf[FEE_SECTOR_BUFF_SIZE + CONFIG_ARCH_CACHE_LINE];

/* page_status */
static char page0_info_buf[sizeof(struct fee_page_info) +
                                         CONFIG_ARCH_CACHE_LINE];
static char page1_info_buf[sizeof(struct fee_page_info) +
                                         CONFIG_ARCH_CACHE_LINE];
static char block_info_buff[sizeof(struct fee_record_info) +
                                          CONFIG_ARCH_CACHE_LINE];

/*fee block info*/
struct fee_block_status block_status[FEE_BLOCKS_CFG_NUMBER];

/* page index */
static uint32 g_sector_index;
static uint32 g_record_index;

static uint16 g_active_page;
static uint16 g_erase_page;

#define FEE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Fee_MemMap.h"

#define FEE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Fee_MemMap.h"

#define FEE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"

//#define FEE_INFO_DUMP 1

inline static void hexdump8_fee_ex(const void *ptr, uint32 len,
                                   uint64 disp_addr)
{
    uint32 address = (uint32)(uint32 *)ptr;
    uint32 count;
    uint32 i;

    for (count = 0 ; count < len; count += 16) {
        ERROR("0x%08llx: ", count);

        for (i = 0; i < _MIN(len - count, 16); i++) {
            ERROR("%02x ", *(const uint8 *)(address + i));
        }

        for (; i < 16; i++) {
            ERROR("   ");
        }

        ERROR("|");

        for (i = 0; i < _MIN(len - count, 16); i++) {
            char c = ((const char *)address)[i];
            ERROR("%c", ((c >= 0x20) && (c < 0x7f)) ? c : '.');
            (void)c;
        }

        ERROR("\n");
        address += 16;
    }
}

static uint16 fee_number_to_index(uint16 block_number)
{
    uint16 block_index = FEE_BLOCK_INDEX_DEF;
    uint16 i = 0;

    for (i = 0; i < FEE_BLOCKS_CFG_NUMBER; i++) {
        if (block_number == Fee_BlockConfig[i].blockNumber) {
            block_index = i;
            break;
        }
    }

    return block_index;
}

static int fee_disk_read(struct fee_dev *fee_dev, Fls_AddressType addr,
                         uint8 *dst, Fls_LengthType size)
{
#ifdef FEE_INFO_DUMP
    ERROR("fee_disk_read addr:%llx size:%llx\n", addr, size);
#endif

    if (!IS_ALIGNED(dst, fee_dev->disk_mem_align_size)) {
        ERROR("fee read dst not aligned to disk_mem_align_size\n");
        return FEE_FUN_FAILED;
    }

    if ((!IS_ALIGNED(addr, fee_dev->disk_access_size))
            || (!IS_ALIGNED(size, fee_dev->disk_access_size))) {
        ERROR("fee read addr or size not aligned to disk_access_size\n");
        return FEE_FUN_FAILED;
    }

    return Fls_Read(addr, dst, size);
}

static int fee_disk_write(struct fee_dev *fee_dev, Fls_AddressType addr,
                          const uint8 *src, Fls_LengthType size)
{
#ifdef FEE_INFO_DUMP
    ERROR("fee_disk_write addr:%llx size:%llx\n", addr, size);
#endif

    if (!IS_ALIGNED(src, fee_dev->disk_mem_align_size)) {
        ERROR("fee write src not aligned to disk_mem_align_size\n");
        return FEE_FUN_FAILED;
    }

    if ((!IS_ALIGNED(addr, fee_dev->disk_access_size))
            || (!IS_ALIGNED(size, fee_dev->disk_access_size))) {
        ERROR("fee write addr or size not aligned to disk_access_size\n");
        return FEE_FUN_FAILED;
    }


    return Fls_Write(addr, src, size);
}

static int fee_disk_erase(struct fee_dev *fee_dev, Fls_AddressType addr,
                          Fls_LengthType size)
{
#ifdef FEE_INFO_DUMP
    ERROR("fee_disk_erase addr:%llx size:%llx\n", addr, size);
#endif

    return Fls_Erase(addr, size);
}

/* get record_size record info based on record_index */
static int fee_get_sector(struct fee_dev *fee_dev, uint16 page_number,
                          uint32 record_index, uint8 *record_buff)
{
    return fee_disk_read(fee_dev,
                         fee_dev->page_info[page_number].page_addr + (record_index *
                                 fee_dev->info_buff_size), record_buff, fee_dev->info_buff_size);
}

/* configure page_info based on page_number */
int fee_set_page_info(struct fee_dev *fee_dev, uint16 page_number,
                      fee_page_status_t page_status)
{
    struct fee_page_info *page_info = NULL_PTR;
#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
    uint32 info_len = 0;
#endif

    if (page_number == 0)
        page_info = (struct fee_page_info *)ROUNDUP((unsigned int)page0_info_buf,
                    CONFIG_ARCH_CACHE_LINE);
    else
        page_info = (struct fee_page_info *)ROUNDUP((unsigned int)page1_info_buf,
                    CONFIG_ARCH_CACHE_LINE);

    memset(page_info, 0x0, sizeof(struct fee_page_info));
    page_info->page_status = page_status;
#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
    page_info->page_addr = fee_dev->page_info[page_number].page_addr;
    page_info->page_size = fee_dev->page_info[page_number].page_size;
    page_info->swap_count = fee_dev->swap_count;
    info_len = sizeof(page_info->page_addr) + sizeof(page_info->page_size) + sizeof(
                   page_info->swap_count);
    page_info->check_sum = crc16((const unsigned char *)&page_info->page_addr,
                                 info_len);
    fee_dev->swap_count++;
#endif

    return fee_disk_write(fee_dev, fee_dev->page_info[page_number].page_addr,
                          (uint8 *)page_info,
                          sizeof(struct fee_page_info));
}

/* get page_info based on page_number */
int fee_get_page_info(struct fee_dev *fee_dev, uint16 page_number)
{
    struct fee_page_info *page_info = NULL;

    if (page_number == 0)
        page_info = (struct fee_page_info *)ROUNDUP((unsigned int)page0_info_buf,
                    CONFIG_ARCH_CACHE_LINE);
    else
        page_info = (struct fee_page_info *)ROUNDUP((unsigned int)page1_info_buf,
                    CONFIG_ARCH_CACHE_LINE);

    return fee_disk_read(fee_dev, fee_dev->page_info[page_number].page_addr,
                         (uint8 *)page_info,
                         sizeof(struct fee_page_info));
}

/* configure page_status based on page_number */
int fee_set_page_status(struct fee_dev *fee_dev, uint16 page_number,
                        fee_page_status_t page_status)
{
    fee_page_status_t *page_status_tmp = 0;

    if (page_number == 0)
        page_status_tmp = (fee_page_status_t *)ROUNDUP((unsigned int)page0_info_buf,
                          CONFIG_ARCH_CACHE_LINE);
    else
        page_status_tmp = (fee_page_status_t *)ROUNDUP((unsigned int)page1_info_buf,
                          CONFIG_ARCH_CACHE_LINE);

    *page_status_tmp = page_status;
    return fee_disk_write(fee_dev, fee_dev->page_info[page_number].page_addr,
                          (uint8 *)page_status_tmp,
                          sizeof(fee_page_status_t));
}

boolean fee_check_erase_page_info(struct fee_dev *fee_dev, uint16 page_number)
{
    struct fee_page_info *page_info = NULL;

    if (page_number == 0)
        page_info = (struct fee_page_info *)ROUNDUP((unsigned int)page0_info_buf,
                    CONFIG_ARCH_CACHE_LINE);
    else
        page_info = (struct fee_page_info *)ROUNDUP((unsigned int)page1_info_buf,
                    CONFIG_ARCH_CACHE_LINE);

    if (FEE_PAGE_ERASED == page_info->page_status)
        return TRUE;
    else
        return FALSE;
}

int fee_get_page_sector(struct fee_dev *fee_dev, uint16 page_number,
                        Fls_LengthType page_offset)
{
    char *page_sector = NULL;
    Fls_AddressType addr = 0;

    if (page_number == 0)
        page_sector = (char *)ROUNDUP((unsigned int)page0_sector_buf,
                                      CONFIG_ARCH_CACHE_LINE);
    else
        page_sector = (char *)ROUNDUP((unsigned int)page1_sector_buf,
                                      CONFIG_ARCH_CACHE_LINE);

    addr = fee_dev->page_info[page_number].page_addr + page_offset -
           FEE_SECTOR_BUFF_SIZE;

    return fee_disk_read(fee_dev, addr, (uint8 *)page_sector, FEE_SECTOR_BUFF_SIZE);
}

int fee_sector_status_check(struct fee_dev *fee_dev, uint16 page_number,
                            Fls_LengthType page_offset)
{
    struct fee_page_info *page_info = NULL;
    char *page_sector = NULL;

    if (page_number == 0) {
        page_info = (struct fee_page_info *)ROUNDUP((unsigned int)page0_info_buf,
                    CONFIG_ARCH_CACHE_LINE);
        page_sector = (char *)ROUNDUP((unsigned int)page0_sector_buf,
                                      CONFIG_ARCH_CACHE_LINE);
    }
    else {
        page_info = (struct fee_page_info *)ROUNDUP((unsigned int)page1_info_buf,
                    CONFIG_ARCH_CACHE_LINE);
        page_sector = (char *)ROUNDUP((unsigned int)page1_sector_buf,
                                      CONFIG_ARCH_CACHE_LINE);
    }

    if (FEE_PAGE_ERASED == page_info->page_status) {
        for (int i = 0; i < FEE_SECTOR_BUFF_SIZE; i++) {
            if (page_sector[i] != 0xff) {
                ERROR("fee_sector_status_check change page%d FEE_PAGE_ERASED to FEE_PAGE_ERASING\n",
                      page_number);
                page_info->page_status = FEE_PAGE_ERASING;
                break;
            }
        }
    }

    return 0;
}

/* erases page based on page_number */
int fee_erase_page(struct fee_dev *fee_dev, uint16 page_number)
{
    return fee_disk_erase(fee_dev, fee_dev->page_info[page_number].page_addr,
                          fee_dev->page_info[page_number].page_size);
}

int fee_erase_page_block(struct fee_dev *fee_dev, uint16 page_number,
                         Fls_LengthType page_offset, uint32 erase_size)
{
    Fls_AddressType addr = fee_dev->page_info[page_number].page_addr +
                           fee_dev->page_info[page_number].page_size - page_offset - erase_size;

    return fee_disk_erase(fee_dev, addr, erase_size);
}

/* displays complete page information based on page_number */
int fee_page_dump(struct fee_dev *fee_dev, uint16 page_number)
{
    int ret = FEE_FUN_OK;
    uint16 i = 0;
    uint8 *buff = (uint8 *)ROUNDUP((unsigned int)record_info_buff,
                                   CONFIG_ARCH_CACHE_LINE);

    for (i = 0; i < fee_dev->page_info[page_number].page_buff_num; i++) {
        if (fee_get_sector(fee_dev, page_number, i,
                           (uint8 *)buff))
            return FEE_FUN_FAILED;

        ERROR("***************Page:%d sector:%d dump*******************\n",
              page_number, i);
        hexdump8_fee_ex(buff, fee_dev->info_buff_size,
                        (uint64)((uint32)buff));
    }

    return ret;
}

/* set record_info based on page_number and record_index */
static int fee_set_record_info(struct fee_dev *fee_dev, uint16 page_number,
                               Fls_LengthType record_index_offset, struct fee_record_info *record_info)
{
    Fls_AddressType addr = fee_dev->page_info[page_number].page_addr +
                           fee_dev->page_info[page_number].page_size;
    addr -= (record_index_offset + 1) * sizeof(struct fee_record_info);
    return fee_disk_write(fee_dev, addr, (uint8 *)record_info,
                          sizeof(struct fee_record_info));
}

/* set record_status based on page_number and record_index */
static int fee_set_record_status(struct fee_dev *fee_dev, uint16 page_number,
                                 Fls_LengthType record_index_offset, struct fee_record_info *record_info)
{
    Fls_AddressType addr = fee_dev->page_info[page_number].page_addr +
                           fee_dev->page_info[page_number].page_size;
    addr -= (record_index_offset + 1) * sizeof(struct fee_record_info);

    return fee_disk_write(fee_dev, addr, (uint8 *)record_info,
                          sizeof(fee_record_status_t) + sizeof(fee_record_sync_t));
}

/* write record data based on page_number and record_data_offset */
static Fls_LengthType fee_write_record_data(struct fee_dev *fee_dev,
        uint16 page_number,
        Fls_LengthType record_data_offset, const uint8 *data_buffer,
        Fls_LengthType length)
{
    /* Address offset, start address + page information + block addr + used data offset */
    Fls_LengthType addr = fee_dev->page_info[page_number].page_addr + sizeof(
                              struct fee_page_info) +
                          record_data_offset;

    Fls_LengthType rlen = 0;
    uint8 *buff = NULL_PTR;

    /* length smaller than disk_access_size,added to disk_access_size */
    if (length < fee_dev->disk_access_size) {
        buff = (uint8 *)ROUNDUP((unsigned int)record_data_buff,
                                CONFIG_ARCH_CACHE_LINE);
        rlen = ROUNDUP(length, fee_dev->disk_access_size);

        if (data_buffer != buff)
            memset(buff, 0xff, rlen);

        /*PRQA S 2998,2996 1*/
        memcpy(buff, data_buffer, _MIN(rlen, length));
    }
    else {
        /* mem address misaligned, data copy */
        if (IS_ALIGNED(data_buffer, fee_dev->disk_mem_align_size)) {
            buff = (uint8 *)data_buffer;
            rlen = ROUNDDOWN(length, fee_dev->disk_access_size);
        }
        else {
            buff = (uint8 *)ROUNDUP((unsigned int)record_data_buff,
                                    CONFIG_ARCH_CACHE_LINE);;
            rlen = _MIN(ROUNDDOWN(length, fee_dev->disk_access_size),
                        fee_dev->data_buff_size);
            memcpy(buff, data_buffer, rlen);
        }
    }

    if (fee_disk_write(fee_dev, addr, buff, rlen)) {
        ERROR("fee_write_record_data page_number %d record_data_offset %lld failure\n",
              page_number, record_data_offset);
        return 0;
    }

    return _MIN(rlen, length);
}

/* read record data based on page_number and record_data_offset */
static Fls_LengthType fee_read_record_data(struct fee_dev *fee_dev,
        uint16 page_number,
        Fls_LengthType record_data_offset, const uint8 *data_buffer,
        Fls_LengthType length, boolean *data_sync)
{
    /* Address offset, start address + page information + used data offset */
    Fls_LengthType addr = fee_dev->page_info[page_number].page_addr + sizeof(
                              struct fee_page_info) +
                          record_data_offset;

    Fls_LengthType rlen = 0;
    uint8 *buff = NULL_PTR;

    /* Process the unaligned portion of the address */
    if (!IS_ALIGNED(addr, fee_dev->disk_access_size)) {
        buff = (uint8 *)ROUNDUP((unsigned int)record_data_buff,
                                CONFIG_ARCH_CACHE_LINE);
        rlen = _MIN(ROUNDUP(addr, fee_dev->disk_access_size) - addr, length);
    }
    else if (length < fee_dev->disk_access_size) {
        buff = (uint8 *)ROUNDUP((unsigned int)record_data_buff,
                                CONFIG_ARCH_CACHE_LINE);
        rlen = ROUNDUP(length, fee_dev->disk_access_size);
    }
    else {
        if (IS_ALIGNED(data_buffer, fee_dev->disk_mem_align_size)) {
            buff = (uint8 *)data_buffer;
            rlen = ROUNDDOWN(length, fee_dev->disk_access_size);
        }
        else {
            buff = (uint8 *)ROUNDUP((unsigned int)record_data_buff,
                                    CONFIG_ARCH_CACHE_LINE);
            rlen = _MIN(ROUNDDOWN(length, fee_dev->disk_access_size),
                        fee_dev->data_buff_size);
        }
    }

    if (fee_disk_read(fee_dev, ROUNDDOWN(addr, fee_dev->disk_access_size), buff,
                      ROUNDUP(rlen, fee_dev->disk_access_size))) {
        ERROR("fee_read_record_data page_number %d record_data_offset %lld failure\n",
              page_number, record_data_offset);
        return 0;
    }

    if ((buff != data_buffer) && (NULL_PTR != data_sync)) {
        *data_sync = 1;
    }

    return _MIN(rlen, length);
}

int fee_block_valid_check(struct fee_dev *fee_dev, uint16 block_index)
{
    return block_status[block_index].valid_flag;
}

int fee_block_valid_set(struct fee_dev *fee_dev, uint16 block_index)
{
    block_status[block_index].valid_flag = 1;
    return FEE_FUN_OK;
}

int fee_block_invalid_check(struct fee_dev *fee_dev, uint16 block_index)
{
    return block_status[block_index].invalid_flag;
}

int fee_block_invalid_set(struct fee_dev *fee_dev, uint16 block_index)
{
    block_status[block_index].invalid_flag = 1;
    return FEE_FUN_OK;
}

int fee_page_record_index_cfg(struct fee_dev *fee_dev)
{
    uint16 page_number = fee_dev->current_page;
    /* Get the latest record_info_offset(fee_record_info aligned) */
    g_sector_index = fee_dev->page_info[page_number].page_buff_num - 1;
    return FEE_FUN_OK;
}

/* get the current record_index based on page_number */
int fee_page_get_record_index(struct fee_dev *fee_dev)
{
    int ret = FEE_FUN_OK;
    uint16 page_number = fee_dev->current_page;

    /* Get the latest record_info_offset(fee_record_info aligned) */
    struct fee_record_info *record_info = (struct fee_record_info *)ROUNDUP((
            unsigned int)record_info_buff, CONFIG_ARCH_CACHE_LINE);
    ret = fee_get_sector(fee_dev, page_number, g_sector_index,
                         (uint8 *)record_info);

    if (ret) {
        ERROR("fee get record info %d failure\n", g_sector_index);
        return ret;
    }

    return ret;
}

/* get the current record_index based on page_number */
int fee_page_record_index_parse(struct fee_dev *fee_dev, boolean *record_match,
                                boolean *end_match)
{
    int ret = FEE_FUN_OK;
    int i = 0;
    uint16 page_number = fee_dev->current_page;
    uint16 block_index = 0;
    uint32 sector_index_max = fee_dev->page_info[page_number].page_buff_num - 1;
    struct fee_record_info *record_info = (struct fee_record_info *)ROUNDUP((
            unsigned int)record_info_buff, CONFIG_ARCH_CACHE_LINE);
#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
    uint16 record_crc16 = 0;
    uint32 info_len = 0;
#endif

    g_record_index = fee_dev->record_info_num - 1;
    *record_match = 0;
#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
    info_len = sizeof(record_info->record_sync) + sizeof(record_info->record_num) +
               sizeof(record_info->record_len) + sizeof(record_info->record_address);
#endif

    for (i = g_record_index; i >= 0; i--) {
        if (record_info[i].record_status == FEE_RECORD_ERASED) {
            *record_match = 1;
            fee_dev->record_info_offset = DIVD_NUM(sector_index_max - g_sector_index,
                                                   g_record_index - i,
                                                   fee_dev->record_info_num);

            if (fee_dev->record_info_offset == 0)
                fee_dev->first_flag = 1;

            break;
        }
        else {
#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
            record_crc16 = crc16((const unsigned char *)&record_info[i].record_sync,
                                 info_len);

            if (record_info[i].record_crc16 != record_crc16) {
                ERROR("fee_page_record_index_parse block_number:%d record info crc16:%x != record_crc16:%x\n",
                      record_info[i].record_num, record_info[i].record_crc16, record_crc16);
                continue;
            }

#endif

            if (record_info[i].record_status == FEE_RECORD_VALID
                    || record_info[i].record_status == FEE_BLOCK_INVALID) {
                block_index = fee_number_to_index(record_info[i].record_num);

                if(FEE_BLOCK_INDEX_DEF == block_index) {
                    ERROR("fee_page_record_index_parse record_num:%d could not find block index\n",
                          record_info[i].record_num);
                    return FEE_FUN_FAILED;
                }

                if (block_status[block_index].block_number != record_info[i].record_num) {
                    ERROR("fee_page_record_index_parse block_status block_number:%d != record_info record_num:%d\n",
                          block_status[block_index].block_number, record_info[i].record_num);
                    return FEE_FUN_FAILED;
                }

                block_status[block_index].valid_flag = 1;
                block_status[block_index].block_size = record_info[i].record_len;
#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
                block_status[block_index].block_addr[fee_dev->current_page] =
                    record_info[i].record_address;
#else
                block_status[block_index].block_addr[fee_dev->current_page] =
                    fee_dev->record_data_offset;
#endif
                block_status[block_index].block_info_index[fee_dev->current_page] = DIVD_NUM(
                            sector_index_max - g_sector_index,
                            g_record_index - i,
                            fee_dev->record_info_num);
#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
                block_status[block_index].record_crc16 = record_info[i].record_crc16;
                block_status[block_index].data_crc16 = record_info[i].data_crc16;
#endif

                if (record_info[i].record_status == FEE_BLOCK_INVALID)
                    block_status[block_index].invalid_flag = 1;
            }

#if (FEE_CHECKSUM_SUPPORTED == STD_ON)

            if (record_info[i].record_sync == FEE_RECORD_SYNC)
                fee_dev->record_data_offset = record_info[i].record_address + ROUNDUP(
                                                  record_info[i].record_len, fee_dev->disk_access_size);

#else

            if (record_info[i].record_sync == FEE_RECORD_SYNC)
                fee_dev->record_data_offset += ROUNDUP(record_info[i].record_len,
                                                       fee_dev->disk_access_size);

#endif
        }
    }

    /*PRQA S 2995 5*/
    if (!(*record_match) && g_sector_index > 0)
        g_sector_index--;
    else if (!(*record_match) && g_sector_index == 0)
        *end_match = 1;

#ifdef FEE_INFO_DUMP
    ERROR("fee_page_record_index_parse record_info_offset %d\n",
          fee_dev->record_info_offset);
    ERROR("fee_page_record_index_parse record_data_offset %lld\n",
          fee_dev->record_data_offset);

    for (int i = 0; i < FEE_BLOCKS_CFG_NUMBER; i++)
        ERROR("fee_page_record_index_parse block index:%d block_addr %lld\n", i,
              block_status[i].block_addr[fee_dev->current_page]);

#endif
    return ret;
}

#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
/* get the current record_data_offset data */
int fee_page_get_data_offset(struct fee_dev *fee_dev)
{
    uint16 page_number = fee_dev->current_page;
    Fls_AddressType addr = fee_dev->page_info[page_number].page_addr + sizeof(
                               struct fee_page_info) +
                           fee_dev->record_data_offset;
    uint8 *buff = (uint8 *)ROUNDUP((unsigned int)record_data_buff,
                                   CONFIG_ARCH_CACHE_LINE);

    return fee_disk_read(fee_dev, addr, buff, fee_dev->info_buff_size);
}

/* check the current record_data_offset data erased */
int fee_page_check_data_offset(struct fee_dev *fee_dev, boolean *data_check)
{
    int ret = FEE_FUN_OK;
    uint8 *buff = (uint8 *)ROUNDUP((unsigned int)record_data_buff,
                                   CONFIG_ARCH_CACHE_LINE);
    Fls_LengthType len = fee_dev->info_buff_size / fee_dev->disk_access_size;
    Fls_LengthType offset = 0;
    boolean erase_check;

    for (offset = 0; offset < len; offset++) {
        erase_check = 1;

        for (int i = 0; i < fee_dev->disk_access_size; i++) {
            if (buff[offset * fee_dev->disk_access_size + i] != 0xff) {
                erase_check = 0;
                break;
            }
        }

        if (erase_check)
            break;
    }

    fee_dev->record_data_offset += offset * fee_dev->disk_access_size;
    *data_check = erase_check;
    DBG("fee_page_check_data_offset:  offset %x len %x\n",
        offset, len);
    DBG("fee_page_check_data_offset:  record_data_offset %x\n",
        fee_dev->record_data_offset);
    DBG("fee_page_check_data_offset:  data_check %x erase_check:%x\n", *data_check,
        erase_check);

    return ret;
}
#endif

/* get the current page based on page information */
int fee_page_active_page(struct fee_dev *fee_dev)
{
    int ret = FEE_FUN_OK;
    fee_page_status_t page0_status = *(fee_page_status_t *)ROUNDUP((
                                         unsigned int)page0_info_buf, CONFIG_ARCH_CACHE_LINE);
    fee_page_status_t page1_status = *(fee_page_status_t *)ROUNDUP((
                                         unsigned int)page1_info_buf, CONFIG_ARCH_CACHE_LINE);

    DBG("set current page:  page0_status %x page1_status %x\n",
        page0_status, page1_status);

    switch (page0_status) {
        case FEE_PAGE_ERASED:
            switch (page1_status) {
                case FEE_PAGE_ERASED:
                    fee_dev->first_flag = 1;
                    fee_dev->current_page = 0;
                    break;

                case FEE_PAGE_ACTIVE:
                case FEE_PAGE_VALID:
                    fee_dev->current_page = 1;
                    break;

                default:
                    goto error;
            }

            break;

        case FEE_PAGE_RECEIVE:
            switch (page1_status) {
                case FEE_PAGE_VALID:
                    fee_dev->current_page = 1;
                    break;

                default:
                    goto error;
            }

            break;

        case FEE_PAGE_ACTIVE:
            switch (page1_status) {
                case FEE_PAGE_ERASED:
                case FEE_PAGE_VALID:
                case FEE_PAGE_ERASING:
                    fee_dev->current_page = 0;
                    break;

                default:
                    fee_dev->current_page = 0;
                    goto active_error_status;
            }

            break;

        case FEE_PAGE_VALID:
            switch (page1_status) {
                case FEE_PAGE_ERASED:
                case FEE_PAGE_RECEIVE:
                    fee_dev->current_page = 0;
                    break;

                case FEE_PAGE_ACTIVE:
                    fee_dev->current_page = 1;
                    break;

                default:
                    goto error;
            }

            break;

        case FEE_PAGE_ERASING:
            switch (page1_status) {
                case FEE_PAGE_ACTIVE:
                    fee_dev->current_page = 1;
                    break;

                default:
                    goto error;
            }

            break;

        default:
            if (FEE_PAGE_ACTIVE == page1_status) {
                fee_dev->current_page = 1;
                goto active_error_status;
            }
            else {
                goto error;
            }
    }

    return ret;

active_error_status:
    ERROR("fee_page_set_two page0_status %x page1_status %x, change error_status to FEE_PAGE_ERASING\n",
          page0_status, page1_status);
    return ret;

error:
    ERROR("fee_page_set_two page0_status %x page1_status %x failure\n",
          page0_status, page1_status);
    return FEE_FUN_FAILED;
}

/* Page state information detection */
int fee_page_check_status(struct fee_dev *fee_dev, fee_page_job *page_job,
                          uint16 *fee_active_page, uint16 *fee_erase_page)
{
    int ret = FEE_FUN_OK;
    fee_page_status_t page0_status = *(fee_page_status_t *)ROUNDUP((
                                         unsigned int)page0_info_buf, CONFIG_ARCH_CACHE_LINE);
    fee_page_status_t page1_status = *(fee_page_status_t *)ROUNDUP((
                                         unsigned int)page1_info_buf, CONFIG_ARCH_CACHE_LINE);

    DBG("check current page:  page0_status %x page1_status %x\n",
        page0_status, page1_status);

    switch (page0_status) {
        case FEE_PAGE_ERASED:
            switch (page1_status) {
                case FEE_PAGE_ERASED:
                    DBG("fee dev is initialized for the first time,fee_format\n");
                    /* Power on for the first time */
                    g_active_page = 0;
                    g_erase_page = 1;
                    *fee_active_page = g_active_page;
                    *fee_erase_page = g_erase_page;
                    *page_job = FEE_PAGE_FORMAT;
                    break;

                case FEE_PAGE_ACTIVE:
                    DBG("fee page information is normal\n");
                    /* Normal boot */
                    g_active_page = 1;
                    g_erase_page = 0;
                    *fee_active_page = g_active_page;
                    *fee_erase_page = g_erase_page;
                    *page_job = FEE_PAGE_NORMAL;
                    break;

                case FEE_PAGE_VALID:
                    /* Page1 data is exchanged to Page0 */
                    DBG("fee page1 data is full, exchange data to page0\n");
                    g_active_page = 1;
                    g_erase_page = 0;
                    *fee_active_page = g_active_page;
                    *fee_erase_page = g_erase_page;
                    *page_job = FEE_PAGE_SWAP;
                    break;

                default:
                    goto error;
            }

            break;

        case FEE_PAGE_RECEIVE:
            switch (page1_status) {
                case FEE_PAGE_VALID:
                    /* Page1 data is exchanged to Page0 */
                    DBG("fee page1 data is full, erase page0 & exchange data to page0\n");
                    g_active_page = 1;
                    g_erase_page = 0;
                    *fee_active_page = g_active_page;
                    *fee_erase_page = g_erase_page;
                    *page_job = FEE_PAGE_ERASE_SWAP;
                    break;

                default:
                    goto error;
            }

            break;

        case FEE_PAGE_ACTIVE:
            switch (page1_status) {
                case FEE_PAGE_ERASED:
                    DBG( "fee page information is normal\n");
                    /* Normal boot */
                    g_active_page = 0;
                    g_erase_page = 1;
                    *fee_active_page = g_active_page;
                    *fee_erase_page = g_erase_page;
                    *page_job = FEE_PAGE_NORMAL;
                    break;

                case FEE_PAGE_VALID:
                case FEE_PAGE_ERASING:
                    DBG("fee erase page1\n");
                    g_active_page = 0;
                    g_erase_page = 1;
                    *fee_active_page = g_active_page;
                    *fee_erase_page = g_erase_page;
                    *page_job = FEE_PAGE_ERASE;
                    break;

                default:
                    DBG("fee erase page1\n");
                    g_active_page = 0;
                    g_erase_page = 1;
                    *fee_active_page = g_active_page;
                    *fee_erase_page = g_erase_page;
                    *page_job = FEE_PAGE_ERASE;
                    goto active_error_status;
            }

            break;

        case FEE_PAGE_VALID:
            switch (page1_status) {
                case FEE_PAGE_ERASED:
                    DBG( "fee page0 data is full, exchange data to page1\n");
                    /* Page0 Data is exchanged to page1 */
                    g_active_page = 0;
                    g_erase_page = 1;
                    *fee_active_page = g_active_page;
                    *fee_erase_page = g_erase_page;
                    *page_job = FEE_PAGE_SWAP;
                    break;

                case FEE_PAGE_RECEIVE:
                    /* Page0 Data is exchanged to page1 */
                    DBG("fee page0 data is full, erase page1 & exchange data to page1\n");
                    g_active_page = 0;
                    g_erase_page = 1;
                    *fee_active_page = g_active_page;
                    *fee_erase_page = g_erase_page;
                    *page_job = FEE_PAGE_ERASE_SWAP;
                    break;

                case FEE_PAGE_ACTIVE:
                    DBG("fee erase page0\n");
                    g_active_page = 1;
                    g_erase_page = 0;
                    *fee_active_page = g_active_page;
                    *fee_erase_page = g_erase_page;
                    *page_job = FEE_PAGE_ERASE;
                    break;

                default:
                    goto error;
            }

            break;

        case FEE_PAGE_ERASING:
            switch (page1_status) {
                case FEE_PAGE_ACTIVE:
                    DBG("fee erase page0\n");
                    /* Erase the page0 */
                    g_active_page = 1;
                    g_erase_page = 0;
                    *fee_active_page = g_active_page;
                    *fee_erase_page = g_erase_page;
                    *page_job = FEE_PAGE_ERASE;
                    break;

                default:
                    goto error;
            }

            break;

        default:
            if (FEE_PAGE_ACTIVE == page1_status) {
                DBG("fee erase page0\n");
                g_active_page = 1;
                g_erase_page = 0;
                *fee_active_page = g_active_page;
                *fee_erase_page = g_erase_page;
                *page_job = FEE_PAGE_ERASE;
                goto active_error_status;
            }
            else {
                goto error;
            }
    }

    return ret;

active_error_status:
    ERROR("fee_page_check_status page0_status %x page1_status %x, change error_status to FEE_PAGE_ERASING\n",
          page0_status, page1_status);
    return ret;

error:
    *page_job = FEE_PAGE_ERROR;
    ERROR("page0_status %x page1_status %x failure\n",
          page0_status, page1_status);
    return FEE_FUN_FAILED;
}

#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
int fee_page_info_check(struct fee_dev *fee_dev, uint16 page_number)
{
    struct fee_page_info *page_info = NULL;
    uint32 info_len = 0;
    uint16 info_crc16 = 0;

    if (page_number == 0)
        page_info = (struct fee_page_info *)ROUNDUP((unsigned int)page0_info_buf,
                    CONFIG_ARCH_CACHE_LINE);
    else
        page_info = (struct fee_page_info *)ROUNDUP((unsigned int)page1_info_buf,
                    CONFIG_ARCH_CACHE_LINE);

    info_len = sizeof(page_info->page_addr) + sizeof(page_info->page_size) + sizeof(
                   page_info->swap_count);
    info_crc16 = crc16((const unsigned char *)&page_info->page_addr, info_len);

    if (info_crc16 != page_info->check_sum) {
        ERROR("fee page info crc16 error, info_crc16:%d check_sum:%d page_addr:0x%x page_size:0x%x swap_count:%d\n",
              info_crc16, page_info->check_sum, page_info->page_addr, page_info->page_size,
              page_info->swap_count);
        goto error;
    }

    if (page_info->page_addr != fee_dev->page_info[page_number].page_addr) {
        ERROR("fee page info page_addr error, page_info page_addr:0x%x fee_dev page_addr:0x%x\n",
              page_info->page_addr, fee_dev->page_info[page_number].page_addr);
        goto error;
    }

    if (page_info->page_size != fee_dev->page_info[page_number].page_size) {
        ERROR("fee page info page_size error, page_info page_size:0x%x fee_dev page_size:0x%x\n",
              page_info->page_size, fee_dev->page_info[page_number].page_size);
        goto error;
    }

    fee_dev->swap_count = page_info->swap_count + 1;
    return FEE_FUN_OK;
error:
    return FEE_FUN_FAILED;
}
#endif

int fee_config(struct fee_dev *fee_dev)
{
    int ret = FEE_FUN_OK;
    int i = 0;
    /* Configure basic page information */
    fee_dev->page_number = FEE_PAGE_NUMBER;
    fee_dev->disk_access_size = FEE_ACCESS_BYTE;

    fee_dev->data_buff_size = FEE_DATA_CACHE_SIZE;
    fee_dev->info_buff_size = FEE_INFO_CACHE_SIZE;

    /*PRQA S 1573,2995,2992,2996,2880 6 */
    /* Verify that the Record INFO is aligned to the sector */
    if (!IS_ALIGNED(fee_dev->info_buff_size, sizeof(struct fee_record_info))) {
        ERROR("fee record_info buff_size %x not aligned to fee_record_info size %x\n",
              fee_dev->info_buff_size, sizeof(struct fee_record_info));
        goto error;
    }

    fee_dev->record_info_num = fee_dev->info_buff_size / sizeof(
                                   struct fee_record_info);

    for (i = 0; i < fee_dev->page_number; i++) {

        /* Verify that the Record INFO is aligned to the sector */
        if (!IS_ALIGNED(fee_dev->page_info[i].page_size, fee_dev->info_buff_size)) {
            ERROR("fee page_size %llx not aligned to info_buff_size %x\n",
                  fee_dev->page_info[i].page_size, fee_dev->info_buff_size);
            goto error;
        }

        fee_dev->page_info[i].page_buff_num = fee_dev->page_info[i].page_size /
                                              fee_dev->info_buff_size;
        DBG("page %d addr:%llx size:%llx page_buff_num:%x\n",
            i, fee_dev->page_info[i].page_addr, fee_dev->page_info[i].page_size,
            fee_dev->page_info[i].page_buff_num);
    }

    return ret;

error:
    return FEE_FUN_FAILED;
}

int fee_first_cfg(struct fee_dev *fee_dev)
{
    int ret = FEE_FUN_OK;
    /* Configure basic page information */
    fee_dev->record_info_offset = 0;
    fee_dev->record_data_offset = 0;
#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
    fee_dev->swap_count = 0;
#endif
    return ret;
}

static int fee_page_check_size(struct fee_dev *fee_dev, uint16 page_number,
                               Fls_LengthType length)
{
    /* Fee Residual space detection */
    /* One more record info space must be reserved for initial use of the record index offset */
    Fls_LengthType used_size = sizeof(struct fee_page_info) +
                               fee_dev->record_data_offset + (fee_dev->record_info_offset * sizeof(
                                           struct fee_record_info) + sizeof(struct fee_record_info));

    if (fee_dev->page_info[page_number].page_size < used_size + length)
        return FALSE;
    else
        return TRUE;
}

int fee_write_block_check(struct fee_dev *fee_dev, uint16 block_number,
                          uint8 *data_buffer, uint16 length, boolean immediate_data, boolean *page_swap)
{
    int ret = FEE_FUN_OK;
    Fls_LengthType rlen = 0;
    uint16 block_index = fee_number_to_index(block_number);

    if(FEE_BLOCK_INDEX_DEF == block_index) {
        ERROR("fee_write_block_check block_number:%d could not find block index\n",
              block_number);
        return FEE_FUN_FAILED;
    }

    if (fee_block_invalid_check(fee_dev, block_index)) {
        ERROR("fee block invalid block_number:%d\n", block_number);
        return FEE_FUN_FAILED;
    }

    if (immediate_data)
        rlen = length + sizeof(struct fee_record_info);
    else
        rlen = length + sizeof(struct fee_record_info) + fee_dev->disk_reserved_size;

    if (!fee_page_check_size(fee_dev, fee_dev->current_page, rlen)) {
        *page_swap = 1;
    }

    return ret;
}

#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
int fee_write_block_info(struct fee_dev *fee_dev, uint16 block_number,
                         uint8 *data_buffer, uint16 length, fee_record_status_t record_status,
                         uint16 data_crc16)
{
    int ret = FEE_FUN_OK;
    uint32 info_len = 0;
    uint16 block_index = fee_number_to_index(block_number);
    struct fee_record_info *record_info = NULL_PTR;

    if(FEE_BLOCK_INDEX_DEF == block_index) {
        ERROR("fee_write_block_info block_number:%d could not find block index\n",
              block_number);
        return FEE_FUN_FAILED;
    }

    record_info = (struct fee_record_info *)ROUNDUP((
                unsigned int)block_info_buff, CONFIG_ARCH_CACHE_LINE);
    record_info->record_status = record_status;
    record_info->record_sync = FEE_RECORD_SYNC;
    record_info->record_num = block_number;
    record_info->record_len = length;
    record_info->record_address = fee_dev->record_data_offset;
    info_len = sizeof(record_info->record_sync) + sizeof(record_info->record_num) +
               sizeof(record_info->record_len) + sizeof(record_info->record_address);
    record_info->record_crc16 = crc16((const unsigned char *)
                                      &record_info->record_sync, info_len);
    record_info->data_crc16 = data_crc16;

    ret = fee_set_record_info(fee_dev, fee_dev->current_page,
                              fee_dev->record_info_offset,
                              record_info);

    if (ret) {
        ERROR("fee_block_write set_record_info block_number %d failure\n",
              block_number);
        return ret;
    }

    block_status[block_index].block_info_index[fee_dev->current_page] =
        fee_dev->record_info_offset;
    block_status[block_index].block_size = length;
    block_status[block_index].record_crc16 = record_info->record_crc16;
    block_status[block_index].data_crc16 = record_info->data_crc16;

    if (block_status[block_index].checksum_error) {
        block_status[block_index].checksum_error = 0;
    }

    fee_dev->record_info_offset++;
#ifdef FEE_INFO_DUMP
    ERROR("fee_write_block_info block_index:%d record_info_offset %d data_crc16:%x\n",
          block_index, fee_dev->record_info_offset, block_status[block_index].data_crc16);
#endif
    return ret;
}
#else
int fee_write_block_info(struct fee_dev *fee_dev, uint16 block_number,
                         uint8 *data_buffer, uint16 length, fee_record_status_t record_status)
{
    int ret = FEE_FUN_OK;
    uint16 block_index = fee_number_to_index(block_number);
    struct fee_record_info *record_info = NULL_PTR;

    if(FEE_BLOCK_INDEX_DEF == block_index) {
        ERROR("fee_write_block_info block_number:%d could not find block index\n",
              block_number);
        return FEE_FUN_FAILED;
    }

    record_info = (struct fee_record_info *)ROUNDUP((
            unsigned int)block_info_buff, CONFIG_ARCH_CACHE_LINE);
    record_info->record_status = record_status;
    record_info->record_sync = FEE_RECORD_SYNC;
    record_info->record_num = block_number;
    record_info->record_len = length;

    ret = fee_set_record_info(fee_dev, fee_dev->current_page,
                              fee_dev->record_info_offset,
                              record_info);

    if (ret) {
        ERROR("fee_block_write set_record_info block_number %d failure\n",
              block_number);
        return ret;
    }

    block_status[block_index].block_info_index[fee_dev->current_page] =
        fee_dev->record_info_offset;
    block_status[block_index].block_size = length;
    fee_dev->record_info_offset++;
#ifdef FEE_INFO_DUMP
    ERROR("fee_write_block_info record_info_offset %d\n",
          fee_dev->record_info_offset);
#endif
    return ret;
}
#endif

int fee_write_block_info_sync(struct fee_dev *fee_dev, uint16 block_number,
                              uint16 length)
{
    fee_dev->record_data_offset_ops = fee_dev->record_data_offset;
    fee_dev->record_data_offset_backup = fee_dev->record_data_offset;
    fee_dev->record_data_offset += ROUNDUP(length, fee_dev->disk_access_size);
#ifdef FEE_INFO_DUMP
    ERROR("fee_write_block_info_sync record_data_offset %d\n",
          fee_dev->record_data_offset);
#endif
    return FEE_FUN_OK;
}

uint16 fee_write_block_data(struct fee_dev *fee_dev, uint16 block_number,
                            uint8 *data_buffer, uint16 length)
{
    Fls_LengthType rlen = fee_write_record_data(fee_dev, fee_dev->current_page,
                          fee_dev->record_data_offset_ops, data_buffer, length);

    if (rlen)
        fee_dev->record_data_offset_ops += ROUNDUP(rlen, fee_dev->disk_access_size);

    return rlen;
}

int fee_write_block_data_sync(struct fee_dev *fee_dev, uint16 block_number,
                              uint16 length)
{
    uint16 block_index = fee_number_to_index(block_number);

    if(FEE_BLOCK_INDEX_DEF == block_index) {
        ERROR("fee_write_block_data_sync block_number:%d could not find block index\n",
              block_number);
        return FEE_FUN_FAILED;
    }

    block_status[block_index].block_addr[fee_dev->current_page] =
        fee_dev->record_data_offset_backup;
#ifdef FEE_INFO_DUMP
    ERROR("fee_write_block_data_sync block_addr %d\n",
          block_status[block_index].block_addr[fee_dev->current_page]);
#endif
    return FEE_FUN_OK;
}

int fee_write_block_active(struct fee_dev *fee_dev, uint16 block_number)
{
    int ret = FEE_FUN_OK;
    struct fee_record_info *record_info = (struct fee_record_info *)ROUNDUP((
            unsigned int)block_info_buff, CONFIG_ARCH_CACHE_LINE);
    record_info->record_status = FEE_RECORD_VALID;
    record_info->record_sync = FEE_RECORD_SYNC;

    ret = fee_set_record_status(fee_dev, fee_dev->current_page,
                                fee_dev->record_info_offset - 1,
                                record_info);

    if (ret) {
        ERROR("fee_block_write set_record_info FEE_RECORD_VALID status block_number %d failure\n",
              block_number);
        return ret;
    }

    return ret;
}

int fee_write_block_valid(struct fee_dev *fee_dev, uint16 block_number,
                          boolean *block_valid)
{
    int ret = FEE_FUN_OK;
    uint16 block_index = fee_number_to_index(block_number);

    if(FEE_BLOCK_INDEX_DEF == block_index) {
        ERROR("fee_write_block_valid block_number:%d could not find block index\n",
              block_number);
        return FEE_FUN_FAILED;
    }

    if (!fee_block_valid_check(fee_dev, block_index)) {
        *block_valid = 0;
        ret = fee_block_valid_set(fee_dev, block_index);

        /*PRQA S 2992 2*/
        if (ret) {
            ERROR("fee_block_write set_record_info fee_block_valid status block_number %d failure\n",
                  block_number);
            return ret;
        }
    }

    return ret;
}

int fee_write_block_invalid(struct fee_dev *fee_dev, uint16 block_number,
                            boolean *block_invalid)
{
    int ret = FEE_FUN_OK;
    uint16 block_index = fee_number_to_index(block_number);

    if(FEE_BLOCK_INDEX_DEF == block_index) {
        ERROR("fee_write_block_invalid block_number:%d could not find block index\n",
              block_number);
        return FEE_FUN_FAILED;
    }

    if (!fee_block_invalid_check(fee_dev, block_index)) {
        ret = fee_block_invalid_set(fee_dev, block_index);

        /*PRQA S 2992 2*/
        if (ret) {
            ERROR("fee_block_write set_record_info fee_block_invalid status block_number %d failure\n",
                  block_number);
            return ret;
        }

        *block_invalid = 1;
        struct fee_record_info *record_info = (struct fee_record_info *)ROUNDUP((
                unsigned int)block_info_buff, CONFIG_ARCH_CACHE_LINE);
        record_info->record_status = FEE_BLOCK_INVALID;
        record_info->record_sync = FEE_RECORD_SYNC;

        ret = fee_set_record_status(fee_dev, fee_dev->current_page,
                                    block_status[block_index].block_info_index[fee_dev->current_page],
                                    record_info);

        if (ret) {
            ERROR("fee_block_write set_record_info FEE_BLOCK_INVALID status block_number %d failure\n",
                  block_number);

            return ret;
        }

    }

    return ret;
}

int fee_read_block_check(struct fee_dev *fee_dev, uint16 block_number)
{
    int ret = FEE_FUN_OK;
    uint16 block_index = fee_number_to_index(block_number);

    if(FEE_BLOCK_INDEX_DEF == block_index) {
        ERROR("fee_read_block_check block_number:%d could not find block index\n",
              block_number);
        return FEE_FUN_FAILED;
    }

    if (fee_block_invalid_check(fee_dev, block_index)) {
        ERROR("fee block invalid block_number:%d\n", block_number);
        return FEE_FUN_FAILED;
    }

    if (!fee_block_valid_check(fee_dev, block_index)) {
        ERROR("fee block not valid block_number:%d\n", block_number);
        return FEE_FUN_FAILED;
    }

    return ret;
}

uint16 fee_read_block_data(struct fee_dev *fee_dev, uint16 block_number,
                           uint16 block_offset, uint8 *data_buffer, uint16 length, boolean *data_sync)
{
    uint16 block_index = fee_number_to_index(block_number);
    Fls_LengthType block_data_offset = 0;

    if(FEE_BLOCK_INDEX_DEF == block_index) {
        ERROR("fee_read_block_data block_number:%d could not find block index\n",
              block_number);
        return 0;
    }

    block_data_offset = block_status[block_index].block_addr[fee_dev->current_page] + block_offset;
    return fee_read_record_data(fee_dev, fee_dev->current_page, block_data_offset,
                                data_buffer, length, data_sync);
}

uint16 fee_read_block_data_sync(struct fee_dev *fee_dev,
                                uint16 block_number,
                                uint16 block_offset, uint8 *data_buffer, uint16 length)
{
    uint8 *buff = (uint8 *)ROUNDUP((unsigned int)record_data_buff,
                                   CONFIG_ARCH_CACHE_LINE);
    memcpy(data_buffer, buff + (block_offset - ROUNDDOWN(block_offset,
                                fee_dev->disk_access_size)), length);
    return length;
}

int fee_swap_cfg(struct fee_dev *fee_dev, uint16 *fee_active_page,
                 uint16 *fee_erase_page)
{
    int ret = FEE_FUN_OK;
    uint16 swap_page = 0;

    if ((NULL_PTR == fee_active_page) || (NULL_PTR == fee_erase_page))
        return FEE_FUN_FAILED;

    if (fee_dev->current_page == fee_dev->page_number - 1)
        swap_page = 0;
    else
        swap_page = fee_dev->current_page + 1;

    g_active_page = fee_dev->current_page;
    g_erase_page = swap_page;
    fee_dev->current_page = g_erase_page;
    fee_dev->record_info_offset_backup = fee_dev->record_info_offset;
    fee_dev->record_data_offset_backup = fee_dev->record_data_offset;
    fee_dev->record_info_offset = 0;
    fee_dev->record_data_offset = 0;
    *fee_active_page = g_active_page;
    *fee_erase_page = g_erase_page;
    return ret;
}

int fee_swap_recover(struct fee_dev *fee_dev, uint16 fee_active_page)
{
    int ret = FEE_FUN_OK;
    fee_dev->current_page = g_active_page;
    fee_dev->record_info_offset = fee_dev->record_info_offset_backup;
    fee_dev->record_data_offset = fee_dev->record_data_offset_backup;
    return ret;
}

uint16 fee_read_swap_data(struct fee_dev *fee_dev, uint16 block_number,
                          uint16 block_offset, uint16 length)
{
    uint16 block_index = fee_number_to_index(block_number);
    Fls_LengthType block_data_offset = 0;
    uint8 *buff = NULL_PTR;

    if(FEE_BLOCK_INDEX_DEF == block_index) {
        ERROR("fee_read_swap_data block_number:%d could not find block index\n",
              block_number);
        return 0;
    }

    block_data_offset = block_status[block_index].block_addr[g_active_page];
    buff = (uint8 *)ROUNDUP((unsigned int)record_data_buff,
                                   CONFIG_ARCH_CACHE_LINE);

    memset(buff, 0xff, fee_dev->data_buff_size);
    Fls_LengthType rlen = _MIN(fee_dev->data_buff_size, ROUNDUP(length,
                               fee_dev->disk_access_size));

    rlen = fee_read_record_data(fee_dev, g_active_page,
                                block_data_offset + block_offset, buff, rlen, NULL_PTR);
    return _MIN(length, rlen);
}

uint16 fee_write_swap_data(struct fee_dev *fee_dev, uint16 block_number,
                           uint16 block_offset, uint16 length)
{
    uint8 *buff = (uint8 *)ROUNDUP((unsigned int)record_data_buff,
                                   CONFIG_ARCH_CACHE_LINE);
    Fls_LengthType rlen = _MIN(fee_dev->data_buff_size, ROUNDUP(length,
                               fee_dev->disk_access_size));
    rlen = fee_write_record_data(fee_dev, g_erase_page,
                                 fee_dev->record_data_offset_ops,
                                 buff, rlen);

    if (rlen)
        fee_dev->record_data_offset_ops += ROUNDUP(rlen, fee_dev->disk_access_size);

    return _MIN(length, rlen);
}

#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"
