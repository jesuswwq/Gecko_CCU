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

#define FEE_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Fee_MemMap.h"

/* record info buff */
static uint8 record_info_buff[FEE_INFO_CACHE_SIZE + CONFIG_ARCH_CACHE_LINE];
static uint8 record_data_buff[FEE_DATA_CACHE_SIZE + CONFIG_ARCH_CACHE_LINE];

/* page_status */
static char page0_status_buf[sizeof(fee_page_status_t) +
                                                       CONFIG_ARCH_CACHE_LINE];
static char page1_status_buf[sizeof(fee_page_status_t) +
                                                       CONFIG_ARCH_CACHE_LINE];
static char block_info_buff[sizeof(struct fee_record_info) +
                                          CONFIG_ARCH_CACHE_LINE];

/* block info */
static Fls_AddressType g_block_addr[FEE_PAGE_NUMBER][FEE_BLOCKS_CFG_NUMBER];
static uint8 g_block_valid[FEE_PAGE_DEV_NUMBER][FEE_BLOCK_ADDR_BIT_SIZE +
        CONFIG_ARCH_CACHE_LINE];
static uint8 g_block_invalid[FEE_PAGE_DEV_NUMBER][FEE_BLOCK_ADDR_BIT_SIZE
        + CONFIG_ARCH_CACHE_LINE];

#define FEE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Fee_MemMap.h"

#define FEE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Fee_MemMap.h"

/* page index */
static uint32 g_sector_index = 0;
static uint32 g_record_index = 0;

static uint16 g_active_page = 0;
static uint16 g_erase_page = 0;

//#define FEE_INFO_DUMP 1
#define FEE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Fee_MemMap.h"

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"

inline static void hexdump8_fee_ex(const void *ptr, uint32 len,
                                   uint64 disp_addr)
{
    addr_t address = (addr_t)(uint32 *)ptr;
    uint32 count;
    uint32 i;
    const char *addr_fmt = "0x%08llx: ";

    for (count = 0 ; count < len; count += 16) {
        DBG(addr_fmt, count);

        for (i = 0; i < _MIN(len - count, 16); i++) {
            DBG("%02x ", *(const uint8 *)(address + i));
        }

        for (; i < 16; i++) {
            DBG("   ");
        }

        DBG("|");

        for (i = 0; i < _MIN(len - count, 16); i++) {
            char c = ((const char *)address)[i];
            DBG("%c", ((c >= 0x20) && (c < 0x7f)) ? c : '.');
            (void)c;
        }

        DBG("\n");
        address += 16;
    }

    (void)addr_fmt;
}

static int fee_disk_read(struct fee_dev *fee_dev, Fls_AddressType addr,
                         uint8 *dst, Fls_LengthType size)
{
#ifdef FEE_INFO_DUMP
    DBG("fee_disk_read addr:%llx size:%llx\n", addr, size);
#endif

    if (!IS_ALIGNED(dst, fee_dev->disk_mem_align_size)) {
        DBG("fee read dst not aligned to disk_mem_align_size\n");
        return -1;
    }

    if ((!IS_ALIGNED(addr, fee_dev->disk_access_size))
            || (!IS_ALIGNED(size, fee_dev->disk_access_size))) {
        DBG("fee read addr or size not aligned to disk_access_size\n");
        return -1;
    }

    return Fls_Read(addr, dst, size);
}

static int fee_disk_write(struct fee_dev *fee_dev, Fls_AddressType addr,
                          const uint8 *src, Fls_LengthType size)
{
#ifdef FEE_INFO_DUMP
    DBG("fee_disk_write addr:%llx size:%llx\n", addr, size);
#endif

    if (!IS_ALIGNED(src, fee_dev->disk_mem_align_size)) {
        DBG("fee write src not aligned to disk_mem_align_size\n");
        return -1;
    }

    if ((!IS_ALIGNED(addr, fee_dev->disk_access_size))
            || (!IS_ALIGNED(size, fee_dev->disk_access_size))) {
        DBG("fee write addr or size not aligned to disk_access_size\n");
        return -1;
    }


    return Fls_Write(addr, src, size);
}

static int fee_disk_erase(struct fee_dev *fee_dev, Fls_AddressType addr,
                          Fls_LengthType size)
{
#ifdef FEE_INFO_DUMP
    DBG("fee_disk_erase addr:%llx size:%llx\n", addr, size);
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

/* configure page_status based on page_number */
int fee_set_page_status(struct fee_dev *fee_dev, uint16 page_number,
                        fee_page_status_t page_status)
{
    fee_page_status_t *page_status_tmp = 0;

    if (page_number == 0)
        page_status_tmp = (fee_page_status_t *)ROUNDUP((unsigned int)page0_status_buf,
                          CONFIG_ARCH_CACHE_LINE);
    else
        page_status_tmp = (fee_page_status_t *)ROUNDUP((unsigned int)page1_status_buf,
                          CONFIG_ARCH_CACHE_LINE);

    *page_status_tmp = page_status;
    return fee_disk_write(fee_dev, fee_dev->page_info[page_number].page_addr,
                          (uint8 *)page_status_tmp,
                          sizeof(fee_page_status_t));
}

/* get page_status based on page_number */
int fee_get_page_status(struct fee_dev *fee_dev, uint16 page_number)
{
    fee_page_status_t *page_status = 0;

    if (page_number == 0)
        page_status = (fee_page_status_t *)ROUNDUP((unsigned int)page0_status_buf,
                      CONFIG_ARCH_CACHE_LINE);
    else
        page_status = (fee_page_status_t *)ROUNDUP((unsigned int)page1_status_buf,
                      CONFIG_ARCH_CACHE_LINE);

    return fee_disk_read(fee_dev, fee_dev->page_info[page_number].page_addr,
                         (uint8 *)page_status,
                         sizeof(fee_page_status_t));
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
    int ret = 0;
    uint16 i = 0;
    uint8 *buff = (uint8 *)ROUNDUP((unsigned int)record_info_buff,
                                   CONFIG_ARCH_CACHE_LINE);

    for (i = 0; i < fee_dev->page_info[page_number].page_buff_num; i++) {
        if (fee_get_sector(fee_dev, page_number, i,
                           (uint8 *)buff))
            return -1;

        DBG("***************Page:%d sector:%d dump*******************\n",
            page_number, i);
        hexdump8_fee_ex(buff, fee_dev->info_buff_size,
                        (uint64)((addr_t)buff));
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
    Fls_LengthType addr = fee_dev->page_info[page_number].page_addr +
                          fee_dev->block_addr_size * 2 + sizeof(struct fee_page_info) +
                          record_data_offset;

    Fls_LengthType rlen = 0;
    uint8 *buff = NULL;

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
        DBG("fee_write_record_data page_number %d record_data_offset %lld failure\n",
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
    Fls_LengthType addr = fee_dev->page_info[page_number].page_addr +
                          fee_dev->block_addr_size * 2 + sizeof(struct fee_page_info) +
                          record_data_offset;

    Fls_LengthType rlen = 0;
    uint8 *buff = NULL;

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
        DBG("fee_read_record_data page_number %d record_data_offset %lld failure\n",
            page_number, record_data_offset);
        return 0;
    }

    if ((buff != data_buffer) && (NULL != data_sync)) {
        *data_sync = 1;
    }

    return _MIN(rlen, length);
}

static int fee_addr_mask_bit_check(uint8 *addr_mask, uint16 block_number)
{
    uint32 block_index = block_number / FEE_CHAR_BIT;
    uint32 block_offset = block_number % FEE_CHAR_BIT;

    if ((addr_mask[block_index] >> block_offset) & 0x1)
        return 1;
    else
        return 0;
}

//static
void fee_addr_mask_bit_set(uint8 *addr_mask, uint16 block_number)
{
    uint32 block_index = block_number / FEE_CHAR_BIT;
    uint32 block_offset = block_number % FEE_CHAR_BIT;

    addr_mask[block_index] |= 0x1 << block_offset;
}

static void fee_addr_mask_bit_clear(uint8 *addr_mask, uint16 block_number)
{
    uint32 block_index = block_number / FEE_CHAR_BIT;
    uint32 block_offset = block_number % FEE_CHAR_BIT;

    addr_mask[block_index] &= ~(0x1 << block_offset);
}

int fee_block_valid_check(struct fee_dev *fee_dev, uint16 block_number)
{
    uint8 *block_mask = (uint8 *)ROUNDUP((unsigned int)
                                         g_block_valid[fee_dev->fee_index],
                                         CONFIG_ARCH_CACHE_LINE);
    return !fee_addr_mask_bit_check(block_mask, block_number);
}

int fee_block_valid_set(struct fee_dev *fee_dev, uint16 page_number,
                        uint16 block_number)
{
    Fls_AddressType addr = fee_dev->page_info[page_number].page_addr + sizeof(
                               struct fee_page_info);
    uint8 *block_mask = (uint8 *)ROUNDUP((unsigned int)
                                         g_block_valid[fee_dev->fee_index],
                                         CONFIG_ARCH_CACHE_LINE);
    fee_addr_mask_bit_clear(block_mask, block_number);
    return fee_disk_write(fee_dev, addr,
                          (uint8 *)block_mask, fee_dev->block_addr_size);
}

int fee_block_invalid_check(struct fee_dev *fee_dev, uint16 block_number)
{
    uint8 *block_mask = (uint8 *)ROUNDUP((unsigned int)
                                         g_block_invalid[fee_dev->fee_index],
                                         CONFIG_ARCH_CACHE_LINE);
    return !fee_addr_mask_bit_check(block_mask, block_number);
}

int fee_block_invalid_set(struct fee_dev *fee_dev, uint16 page_number,
                          uint16 block_number)
{
    Fls_AddressType addr = fee_dev->page_info[page_number].page_addr + sizeof(
                               struct fee_page_info) + fee_dev->block_addr_size;;
    uint8 *block_mask = (uint8 *)ROUNDUP((unsigned int)
                                         g_block_invalid[fee_dev->fee_index],
                                         CONFIG_ARCH_CACHE_LINE);
    fee_addr_mask_bit_clear(block_mask, block_number);
    return fee_disk_write(fee_dev, addr,
                          (uint8 *)block_mask, fee_dev->block_addr_size);
}

int fee_page_record_index_cfg(struct fee_dev *fee_dev)
{
    uint16 page_number = fee_dev->current_page;
    /* Get the latest record_info_offset(fee_record_info aligned) */
    g_sector_index = fee_dev->page_info[page_number].page_buff_num - 1;
    return 0;
}

/* get the current record_index based on page_number */
int fee_page_get_record_index(struct fee_dev *fee_dev)
{
    int ret = 0;
    uint16 page_number = fee_dev->current_page;

    /* Get the latest record_info_offset(fee_record_info aligned) */
    struct fee_record_info *record_info = (struct fee_record_info *)ROUNDUP((
            unsigned int)record_info_buff, CONFIG_ARCH_CACHE_LINE);
    ret = fee_get_sector(fee_dev, page_number, g_sector_index,
                         (uint8 *)record_info);

    if (ret) {
        DBG("fee get record info %d failure\n", g_sector_index);
        return -1;
    }

    return ret;
}

/* get the current record_index based on page_number */
int fee_page_record_index_parse(struct fee_dev *fee_dev, boolean *record_match,
                                boolean *end_match)
{
    int ret = 0;
    int i = 0;
    uint16 page_number = fee_dev->current_page;
    uint32 sector_index_max = fee_dev->page_info[page_number].page_buff_num - 1;
    struct fee_record_info *record_info = (struct fee_record_info *)ROUNDUP((
            unsigned int)record_info_buff, CONFIG_ARCH_CACHE_LINE);

    g_record_index = fee_dev->record_info_num - 1;
    *record_match = 0;

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
            if (record_info[i].record_status == FEE_RECORD_VALID)
                g_block_addr[fee_dev->current_page][record_info[i].record_num] =
                    fee_dev->record_data_offset;

            if (record_info[i].record_sync == FEE_RECORD_SYNC)
                fee_dev->record_data_offset += ROUNDUP(record_info[i].record_len,
                                                       fee_dev->disk_access_size);
        }
    }

    /*PRQA S 2995 5*/
    if (!(*record_match) && g_sector_index > 0)
        g_sector_index--;
    else if (!(*record_match) && g_sector_index == 0)
        *end_match = 1;

#ifdef FEE_INFO_DUMP
    DBG("fee_page_record_index_parse record_info_offset %d\n",
        fee_dev->record_info_offset);
    DBG("fee_page_record_index_parse record_data_offset %lld\n",
        fee_dev->record_data_offset);

    for (int i = 0; i < FEE_BLOCKS_CFG_NUMBER; i++)
        DBG("fee_page_record_index_parse block index:%d block_addr %lld\n", i,
            g_block_addr[fee_dev->current_page][i]);

#endif
    return ret;
}

/* check block address mask bit */
int fee_block_valid_info(struct fee_dev *fee_dev)
{
    uint16 page_number = fee_dev->current_page;
    Fls_AddressType addr = fee_dev->page_info[page_number].page_addr + sizeof(
                               struct fee_page_info);
    uint8 *block_mask = (uint8 *)ROUNDUP((unsigned int)
                                         g_block_valid[fee_dev->fee_index],
                                         CONFIG_ARCH_CACHE_LINE);
    memset(block_mask, 0xff, fee_dev->block_addr_size);

    if (fee_disk_read(fee_dev, addr, (uint8 *)block_mask,
                      fee_dev->block_addr_size)) {
        DBG("fee_block_valid read info error\n");
        return -1;
    }

    return 0;
}

int fee_block_invalid_info(struct fee_dev *fee_dev)
{
    uint16 page_number = fee_dev->current_page;
    Fls_AddressType addr = fee_dev->page_info[page_number].page_addr + sizeof(
                               struct fee_page_info) + fee_dev->block_addr_size;
    uint8 *block_mask = (uint8 *)ROUNDUP((unsigned int)
                                         g_block_invalid[fee_dev->fee_index],
                                         CONFIG_ARCH_CACHE_LINE);
    memset(block_mask, 0xff, fee_dev->block_addr_size);

    if (fee_disk_read(fee_dev, addr, (uint8 *)block_mask,
                      fee_dev->block_addr_size)) {
        DBG("fee_block_invalid read info error\n");
        return -1;
    }

    return 0;
}

int fee_swap_block_info(struct fee_dev *fee_dev, uint16 page_number,
                        boolean swap_read)
{
    Fls_AddressType addr = fee_dev->page_info[page_number].page_addr + sizeof(
                               struct fee_page_info);
    uint8 *buff = (uint8 *)ROUNDUP((unsigned int)record_data_buff,
                                   CONFIG_ARCH_CACHE_LINE);

    if (swap_read) {
        memset(buff, 0x0, fee_dev->block_addr_size * 2);

        if (fee_disk_read(fee_dev, addr, (uint8 *)buff,
                          fee_dev->block_addr_size * 2)) {
            DBG("fee_block_valid read info error\n");
            return -1;
        }
    }
    else {
        if (fee_disk_write(fee_dev, addr, (uint8 *)buff,
                           fee_dev->block_addr_size * 2)) {
            DBG("fee_block_valid read info error\n");
            return -1;
        }
    }

    return 0;
}

int fee_page_swap(struct fee_dev *fee_dev, uint16 active_page,
                  uint16 erase_page)
{
    return 0;
}
/* get the current page based on page information */
int fee_page_set(struct fee_dev *fee_dev)
{
    int ret = 0;
    fee_page_status_t *page0_status_addr = (fee_page_status_t *)ROUNDUP((
            unsigned int)page0_status_buf, CONFIG_ARCH_CACHE_LINE);
    fee_page_status_t page0_status = *page0_status_addr;
    fee_page_status_t page1_status = *(fee_page_status_t *)ROUNDUP((
                                         unsigned int)page1_status_buf, CONFIG_ARCH_CACHE_LINE);

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
                    goto error;
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
            goto error;
    }

    return ret;
error:
    DBG("fee_page_set_two page0_status %x page1_status %x failure\n",
        page0_status, page1_status);
    return -1;
}

/* Page state information detection */
int fee_page_check(struct fee_dev *fee_dev, fee_page_job *page_job,
                   uint16 *fee_active_page, uint16 *fee_erase_page)
{
    int ret = 0;
    fee_page_status_t page0_status = *(fee_page_status_t *)ROUNDUP((
                                         unsigned int)page0_status_buf, CONFIG_ARCH_CACHE_LINE);
    fee_page_status_t page1_status = *(fee_page_status_t *)ROUNDUP((
                                         unsigned int)page1_status_buf, CONFIG_ARCH_CACHE_LINE);

    DBG("check current page:  page0_status %x page1_status %x\n",
        page0_status, page1_status);

    switch (page0_status) {
        case FEE_PAGE_ERASED:
            switch (page1_status) {
                case FEE_PAGE_ERASED:
                    DBG("fee dev is initialized for the first time,fee_format\n");
                    /* Power on for the first time */
                    *page_job = FEE_PAGE_FORMAT;
                    break;

                case FEE_PAGE_ACTIVE:
                    DBG("fee page information is normal\n");
                    /* Normal boot */
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
                    *page_job = FEE_PAGE_NORMAL;
                    break;

                case FEE_PAGE_VALID:
                case FEE_PAGE_ERASING:
                    DBG("fee erase page1\n");
                    g_erase_page = 1;
                    *fee_erase_page = g_erase_page;
                    *page_job = FEE_PAGE_ERASE;
                    break;

                default:
                    goto error;
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
                    g_erase_page = 0;
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
                    g_erase_page = 0;
                    *fee_erase_page = g_erase_page;
                    *page_job = FEE_PAGE_ERASE;
                    break;

                default:
                    goto error;
            }

            break;

        default:
            goto error;
    }

    return ret;
error:
    DBG("page0_status %x page1_status %x failure\n",
        page0_status, page1_status);
    return -1;
}

int fee_config(struct fee_dev *fee_dev)
{
    int ret = 0;
    int i = 0;
    /* Configure basic page information */
    fee_dev->page_number = FEE_PAGE_NUMBER;
    fee_dev->block_addr_size = FEE_BLOCK_ADDR_BIT_SIZE;
    fee_dev->disk_access_size = FEE_ACCESS_BYTE;

    fee_dev->data_buff_size = FEE_DATA_CACHE_SIZE;
    fee_dev->info_buff_size = FEE_INFO_CACHE_SIZE;

    /*PRQA S 1573,2995,2992,2996,2880 6 */
    /* Verify that the Record INFO is aligned to the sector */
    if (!IS_ALIGNED(fee_dev->info_buff_size, sizeof(struct fee_record_info))) {
        DBG("fee record_info buff_size %x not aligned to fee_record_info size %x\n",
            fee_dev->info_buff_size, sizeof(struct fee_record_info));
        goto error;
    }

    fee_dev->record_info_num = fee_dev->info_buff_size / sizeof(
                                   struct fee_record_info);

    for (i = 0; i < fee_dev->page_number; i++) {

        /* Verify that the Record INFO is aligned to the sector */
        if (!IS_ALIGNED(fee_dev->page_info[i].page_size, fee_dev->info_buff_size)) {
            DBG("fee page_size %llx not aligned to info_buff_size %x\n",
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
    return -1;
}

int fee_first_cfg(struct fee_dev *fee_dev)
{
    int ret = 0;
    /* Configure basic page information */
    fee_dev->record_info_offset = 0;
    fee_dev->record_data_offset = 0;

    uint8 *block_valid_buff = (uint8 *)ROUNDUP((unsigned int)
                              g_block_valid[fee_dev->fee_index],
                              CONFIG_ARCH_CACHE_LINE);
    memset(block_valid_buff, 0xff, fee_dev->block_addr_size);
    uint8 *block_invalid_buff = (uint8 *)ROUNDUP((unsigned int)
                                g_block_invalid[fee_dev->fee_index],
                                CONFIG_ARCH_CACHE_LINE);
    memset(block_invalid_buff, 0xff, fee_dev->block_addr_size);

    return ret;
}

static int fee_page_check_size(struct fee_dev *fee_dev, uint16 page_number,
                               Fls_LengthType length)
{
    /* Fee Residual space detection */
    /* One more record info space must be reserved for initial use of the record index offset */
    Fls_LengthType used_size = sizeof(struct fee_page_info) +
                               fee_dev->block_addr_size * 2 +
                               fee_dev->record_data_offset + (fee_dev->record_info_offset * sizeof(
                                           struct fee_record_info) + sizeof(struct fee_record_info));

    if (fee_dev->page_info[page_number].page_size < used_size + length)
        return 0;
    else
        return 1;
}

int fee_write_block_check(struct fee_dev *fee_dev, uint16 block_number,
                          uint8 *data_buffer, uint16 length, boolean immediate_data, boolean *page_swap)
{
    int ret = 0;
    Fls_LengthType rlen = 0;

    if (fee_block_invalid_check(fee_dev, block_number)) {
        DBG("fee block invalid block_number:%d\n", block_number);
        return -1;
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

int fee_write_block_info(struct fee_dev *fee_dev, uint16 block_number,
                         uint8 *data_buffer, uint16 length, fee_record_status_t record_status)
{
    int ret = 0;
    struct fee_record_info *record_info = (struct fee_record_info *)ROUNDUP((
            unsigned int)block_info_buff, CONFIG_ARCH_CACHE_LINE);
    record_info->record_status = record_status;
    record_info->record_sync = FEE_RECORD_SYNC;
    record_info->record_num = block_number;
    record_info->record_len = length;
    ret = fee_set_record_info(fee_dev, fee_dev->current_page,
                              fee_dev->record_info_offset,
                              record_info);

    if (ret) {
        DBG("fee_block_write set_record_info block_number %d failure\n", block_number);
        return -1;
    }

    fee_dev->record_info_offset++;
#ifdef FEE_INFO_DUMP
    DBG("fee_write_block_info record_info_offset %d\n",
        fee_dev->record_info_offset);
#endif
    return ret;
}

int fee_write_block_info_sync(struct fee_dev *fee_dev, uint16 block_number,
                              uint16 length)
{
    fee_dev->record_data_offset_ops = fee_dev->record_data_offset;
    fee_dev->record_data_offset_backup = fee_dev->record_data_offset;
    fee_dev->record_data_offset += ROUNDUP(length, fee_dev->disk_access_size);
#ifdef FEE_INFO_DUMP
    DBG("fee_write_block_info_sync record_data_offset %d\n",
        fee_dev->record_data_offset);
#endif
    return 0;
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
    g_block_addr[fee_dev->current_page][block_number] =
        fee_dev->record_data_offset_backup;
#ifdef FEE_INFO_DUMP
    DBG("fee_write_block_data_sync block_addr %d\n",
        g_block_addr[fee_dev->current_page][block_number]);
#endif
    return 0;
}

int fee_write_block_active(struct fee_dev *fee_dev, uint16 block_number)
{
    int ret = 0;
    struct fee_record_info *record_info = (struct fee_record_info *)ROUNDUP((
            unsigned int)block_info_buff, CONFIG_ARCH_CACHE_LINE);
    record_info->record_status = FEE_RECORD_VALID;
    record_info->record_sync = FEE_RECORD_SYNC;

    ret = fee_set_record_status(fee_dev, fee_dev->current_page,
                                fee_dev->record_info_offset - 1,
                                record_info);

    if (ret)
        DBG("fee_block_write set_record_info FEE_RECORD_VALID status block_number %d failure\n",
            block_number);

    return ret;
}

int fee_write_block_valid(struct fee_dev *fee_dev, uint16 block_number,
                          boolean *block_valid)
{
    int ret = 0;

    if (!fee_block_valid_check(fee_dev, block_number)) {
        *block_valid = 1;
        ret = fee_block_valid_set(fee_dev, fee_dev->current_page, block_number);

        if (ret)
            return ret;
    }

    return 0;
}

int fee_write_block_invalid(struct fee_dev *fee_dev, uint16 block_number,
                            boolean *block_invalid)
{
    int ret = 0;

    if (!fee_block_invalid_check(fee_dev, block_number)) {
        *block_invalid = 1;
        ret = fee_block_invalid_set(fee_dev, fee_dev->current_page, block_number);

        if (ret)
            return ret;
    }

    return 0;
}

int fee_read_block_check(struct fee_dev *fee_dev, uint16 block_number)
{
    int ret = 0;

    if (fee_block_invalid_check(fee_dev, block_number)) {
        DBG("fee block invalid block_number:%d\n", block_number);
        return -1;
    }

    if (!fee_block_valid_check(fee_dev, block_number)) {
        DBG("fee block not valid block_number:%d\n", block_number);
        return -1;
    }

    return ret;
}

uint16 fee_read_block_data(struct fee_dev *fee_dev, uint16 block_number,
                           uint16 block_offset, uint8 *data_buffer, uint16 length, boolean *data_sync)
{
    Fls_LengthType block_data_offset  =
        g_block_addr[fee_dev->current_page][block_number] + block_offset;
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
    int ret = 0;
    uint16 swap_page = 0;

    if ((NULL == fee_active_page) || (NULL == fee_erase_page))
        return -1;

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
    int ret = 0;
    fee_dev->current_page = g_active_page;
    fee_dev->record_info_offset = fee_dev->record_info_offset_backup;
    fee_dev->record_data_offset = fee_dev->record_data_offset_backup;
    return ret;
}

uint16 fee_read_swap_data(struct fee_dev *fee_dev, uint16 block_number,
                          uint16 block_offset, uint16 length)
{
    Fls_LengthType block_data_offset  = g_block_addr[g_active_page][block_number];
    uint8 *buff = (uint8 *)ROUNDUP((unsigned int)record_data_buff,
                                   CONFIG_ARCH_CACHE_LINE);
    memset(buff, 0xff, fee_dev->data_buff_size);
    Fls_LengthType rlen = _MIN(fee_dev->data_buff_size, ROUNDUP(length,
                               fee_dev->disk_access_size));

    rlen = fee_read_record_data(fee_dev, g_active_page,
                                block_data_offset + block_offset, buff, rlen, NULL);
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
