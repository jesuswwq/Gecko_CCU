/**
 * @file fee_ops.h
 *
 * Copyright (c) 2022 Semidrive Semiconductor.
 * All rights reserved.
 *
 * Description:
 *
 * Revision History:
 * -----------------
 */

#ifndef FEE_OPS_H
#define FEE_OPS_H

#include "Fls.h"
#include "Fee_Cfg.h"

#define FEE_PAGE_NUMBER_TWO                     2 /* page number, two page schemes are considered to have the highest space utilization */
#define FEE_PAGE_NUMBER                         FEE_PAGE_NUMBER_TWO

#define FEE_ACCESS_BYTE                         0x4 /* flash access min bytes */

#define CONFIG_ARCH_CACHE_LINE                  32 /* Memory address alignment size */

#define FEE_RECORD_BUFF_SIZE                    0x1000  /* record buff size */
#define FEE_SECTOR_BUFF_SIZE                    0x10    /* erase page check size */

#define DIVD_NUM(div, rem, coe) ((div) * (coe) + (rem)) /* compute the dividend */
#define DIV_NUM(num, coe) ((num) / (coe))               /* calculate the divisor */
#define REM_NUM(num, coe) ((num) % (coe))               /* calculate the remainder */

#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
#define FEE_ALIGNED_SIZE    16
#else
#define FEE_ALIGNED_SIZE    4
#endif

/* page status type */
typedef uint32 fee_page_status_t;
/* page status definitions */
#define FEE_PAGE_ERASED                 ((fee_page_status_t)0xFFFFFFFF)     /* PAGE is empty */
#define FEE_PAGE_RECEIVE                ((fee_page_status_t)0xFFFFFFA5)     /* PAGE is marked to receive data */
#define FEE_PAGE_ACTIVE                 ((fee_page_status_t)0xFFFFA5A5)     /* PAGE is marked to store new data */
#define FEE_PAGE_VALID                  ((fee_page_status_t)0xFFA5A5A5)     /* PAGE is full */
#define FEE_PAGE_ERASING                ((fee_page_status_t)0xA5A5A5A5)     /* PAGE is marked to be erase */

/* page information */
struct fee_page_info {
    fee_page_status_t page_status;
#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
    Fls_AddressType page_addr;
    Fls_LengthType page_size;
    uint32 swap_count;
    uint16 check_sum;
#endif
} __attribute__((aligned(FEE_ALIGNED_SIZE)));

typedef uint16 fee_record_status_t;
typedef uint16 fee_record_sync_t;
typedef uint16 fee_record_number_t; /* block number range is 64K */
typedef uint16 fee_record_length_t; /* block size range is 64K */
typedef Fls_AddressType fee_record_addr_t; /* block size range is 64K */

/* block status definitions */
#define FEE_RECORD_ERASED                   ((fee_record_status_t)0xFFFF)     /* record is empty */
#define FEE_RECORD_INVALID                  ((fee_record_status_t)0xFFA5)     /* record is marked to invalid */
#define FEE_RECORD_VALID                    ((fee_record_status_t)0xA5A5)     /* record is marked to valid */
#define FEE_BLOCK_INVALID                   ((fee_record_status_t)0x0000)     /* block is marked to invalid */

#define FEE_RECORD_SYNC                     ((fee_record_status_t)0x0000)     /* record info sync flag */

/* record information */
struct fee_record_info {
    fee_record_status_t record_status;
    fee_record_sync_t record_sync;
    fee_record_number_t record_num;
    fee_record_length_t record_len;
#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
    fee_record_addr_t record_address;
    uint16 record_crc16;
    uint16 data_crc16;
#endif
} __attribute__((aligned(FEE_ALIGNED_SIZE)));

/* Job state */
typedef enum {
    FEE_PAGE_NORMAL = 1,
    FEE_PAGE_FORMAT,
    FEE_PAGE_SWAP,
    FEE_PAGE_ERASE_SWAP,
    FEE_PAGE_ERASE,
    FEE_PAGE_ERROR,
} fee_page_job;

/* block run-time status */
struct fee_block_status {
    uint16 block_number;
    uint16 block_size;
    Fls_AddressType block_addr[FEE_PAGE_NUMBER];
    Fls_LengthType block_info_index[FEE_PAGE_NUMBER];
#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
    uint16 record_crc16;
    uint16 data_crc16;
    uint8 checksum_error;
#endif
    uint8 valid_flag;
    uint8 invalid_flag;
};


/* page information */
struct fee_page {
    Fls_AddressType
    page_addr;         /* page start address in the physical layer device, sector_size aligned */
    Fls_LengthType page_size;         /* page size,sector_size aligned */
    Fls_LengthType erase_size;        /* page erase size, sector_size aligned */
    Fls_LengthType sector_size;       /* page sector size */
    uint16    page_buff_num;   /* number of buff in page */
};

/* fee device */
struct fee_dev {
    uint16 fee_index;

    /* disk_dev */
    Fls_LengthType disk_reserved_size;  /* disk reserved size */
    uint16 disk_mem_align_size;
    uint16 disk_access_size;          /* disk access min size */

    /* page info */
    uint16 page_number;               /* PAGE_NUMBER */
    struct fee_page page_info[FEE_PAGE_NUMBER];

    /* fee dev information at run time */
    boolean first_flag;
    uint16 current_page;                  /* current page page */
    Fls_LengthType
    record_info_offset;         /* current record_info index offset */
    Fls_LengthType record_data_offset;         /* current record_data addr offset*/
    Fls_LengthType
    record_data_offset_ops;     /* current operation record_data addr offset*/
    Fls_LengthType record_info_offset_backup;  /* record_info index offset backup */
    Fls_LengthType record_data_offset_backup;  /* record_data addr offset backup */
#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
    uint32 swap_count;
#endif

    uint16 record_info_num;                 /* number of record info in record_info_buff */
    uint16 data_buff_size;                  /* record data buff size */
    uint16 info_buff_size;                  /* record info buff size */
};

/* fee fun result */
typedef enum {
    /* The fun has been finished successfully. */
    FEE_FUN_OK,
    /* The fun has not been finished successfully. */
    FEE_FUN_FAILED,
} Fee_ResultType;

/* fee APIs */
int fee_config(struct fee_dev *fee_dev);
int fee_first_cfg(struct fee_dev *fee_dev);

int fee_page_active_page(struct fee_dev *fee_dev);
int fee_page_check_status(struct fee_dev *fee_dev, fee_page_job *page_job,
                          uint16 *fee_active_page, uint16 *fee_erase_page);

int fee_page_record_index_cfg(struct fee_dev *fee_dev);
int fee_page_get_record_index(struct fee_dev *fee_dev);
int fee_page_record_index_parse(struct fee_dev *fee_dev, boolean *record_match,
                                boolean *end_match);
#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
int fee_page_get_data_offset(struct fee_dev *fee_dev);
int fee_page_check_data_offset(struct fee_dev *fee_dev, boolean *data_check);
#endif
int fee_block_valid_check(struct fee_dev *fee_dev, uint16 block_index);
int fee_block_invalid_check(struct fee_dev *fee_dev, uint16 block_index);

int fee_erase_page(struct fee_dev *fee_dev, uint16 page_number);
int fee_erase_page_block(struct fee_dev *fee_dev, uint16 page_number,
                         Fls_LengthType page_offset, uint32 erase_size);
int fee_set_page_info(struct fee_dev *fee_dev, uint16 page_number,
                      fee_page_status_t page_status);
int fee_get_page_info(struct fee_dev *fee_dev, uint16 page_number);
int fee_set_page_status(struct fee_dev *fee_dev, uint16 page_number,
                        fee_page_status_t page_status);
#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
int fee_page_info_check(struct fee_dev *fee_dev, uint16 page_number);
#endif
boolean fee_check_erase_page_info(struct fee_dev *fee_dev, uint16 page_number);
int fee_get_page_sector(struct fee_dev *fee_dev, uint16 page_number, Fls_LengthType page_offset);
int fee_sector_status_check(struct fee_dev *fee_dev, uint16 page_number, Fls_LengthType page_offset);


/* fee block operations */
int fee_write_block_check(struct fee_dev *fee_dev, uint16 block_number,
                          uint8 *data_buffer, uint16 length, boolean immediate_data, boolean *page_swap);
#if (FEE_CHECKSUM_SUPPORTED == STD_ON)
int fee_write_block_info(struct fee_dev *fee_dev, uint16 block_number,
                         uint8 *data_buffer, uint16 length, fee_record_status_t record_status, uint16 data_crc16);
#else
int fee_write_block_info(struct fee_dev *fee_dev, uint16 block_number,
                         uint8 *data_buffer, uint16 length, fee_record_status_t record_status);
#endif
int fee_write_block_info_sync(struct fee_dev *fee_dev, uint16 block_number,
                              uint16 length);
uint16 fee_write_block_data(struct fee_dev *fee_dev, uint16 block_number,
                            uint8 *data_buffer, uint16 length);
int fee_write_block_data_sync(struct fee_dev *fee_dev, uint16 block_number,
                              uint16 length);
int fee_write_block_active(struct fee_dev *fee_dev, uint16 block_number);
int fee_write_block_valid(struct fee_dev *fee_dev, uint16 block_number,
                          boolean *block_valid);
int fee_write_block_invalid(struct fee_dev *fee_dev, uint16 block_number,
                            boolean *block_invalid);

int fee_read_block_check(struct fee_dev *fee_dev, uint16 block_number);
uint16 fee_read_block_data(struct fee_dev *fee_dev, uint16 block_number,
                           uint16 block_offset, uint8 *data_buffer, uint16 length, boolean *data_sync);
uint16 fee_read_block_data_sync(struct fee_dev *fee_dev, uint16 block_number,
                                uint16 block_offset, uint8 *data_buffer, uint16 length);

int fee_swap_cfg(struct fee_dev *fee_dev, uint16 *fee_active_page,
                 uint16 *fee_erase_page);
int fee_swap_recover(struct fee_dev *fee_dev, uint16 fee_active_page);
uint16 fee_read_swap_data(struct fee_dev *fee_dev, uint16 block_number,
                          uint16 block_offset, uint16 length);
uint16 fee_write_swap_data(struct fee_dev *fee_dev, uint16 block_number,
                           uint16 block_offset, uint16 length);

#endif /* TAISHAN_FEE_H_ */
