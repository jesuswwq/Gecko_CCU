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
* @file  spi_nor.c
* @brief Semidrive. AUTOSAR 4.3.1 MCAL Fls plugins.
*/

#ifdef __cplusplus
extern "C" {
#endif

#include <cdefs.h>
#include "Mcal.h"
#include "Fls.h"
#include "Mcu_Delay.h"
#include "Fls_Cfg.h"
#include "debug.h"

#define ARRAY_NUMS(array) (sizeof(array) / sizeof(array[0]))

#define PROTO(_opcode, _dq) \
        (_opcode << SNOR_OPCODE_PROTO_LSB | _dq)
#define ID_PROTO(dummy, _dq) \
        (dummy << SNOR_READID_DUMMY_LSB | _dq)

/* Flash opcodes. */
#define SPINOR_OP_WREN 0x06       /* Write enable */
#define SPINOR_OP_WRDI 0x04       /* Write disable */
#define SPINOR_OP_RDSR 0x05       /* Read status register */
#define SPINOR_OP_WRSR 0x01       /* Write status register 1 byte */
#define SPINOR_OP_RDSR2 0x3f      /* Read status register 2 */
#define SPINOR_OP_WRSR2 0x3e      /* Write status register 2 */
#define SPINOR_OP_READ 0x03       /* Read data bytes (low frequency) */
#define SPINOR_OP_READ_FAST 0x0b  /* Read data bytes (high frequency) */
#define SPINOR_OP_READ_1_1_2 0x3b /* Read data bytes (Dual Output SPI) */
#define SPINOR_OP_READ_1_2_2 0xbb /* Read data bytes (Dual I/O SPI) */
#define SPINOR_OP_READ_1_1_4 0x6b /* Read data bytes (Quad Output SPI) */
#define SPINOR_OP_READ_1_4_4 0xeb /* Read data bytes (Quad I/O SPI) */
#define SPINOR_OP_READ_1_1_8 0x8b /* Read data bytes (Octal Output SPI) */
#define SPINOR_OP_READ_1_8_8 0xcb /* Read data bytes (Octal I/O SPI) */
#define SPINOR_OP_PP 0x02         /* Page program (up to 256 bytes) */
#define SPINOR_OP_PP_1_1_4 0x32   /* Quad page program */
#define SPINOR_OP_PP_1_4_4 0x38   /* Quad page program */
#define SPINOR_OP_PP_1_1_8 0x82   /* Octal page program */
#define SPINOR_OP_PP_1_8_8 0xc2   /* Octal page program */
#define SPINOR_OP_BE_4K 0x20      /* Erase 4KiB block */
#define SPINOR_OP_BE_4K_PMC 0xd7  /* Erase 4KiB block on PMC chips */
#define SPINOR_OP_BE_32K 0x52     /* Erase 32KiB block */
#define SPINOR_OP_CHIP_ERASE 0xc7 /* Erase whole flash chip */
#define SPINOR_OP_SE 0xd8         /* Sector erase (usually 64KiB) */
#define SPINOR_OP_RDID 0x9f       /* Read JEDEC ID */
#define SPINOR_OP_RDSFDP 0x5a     /* Read SFDP */
#define SPINOR_OP_RDCR 0x35       /* Read configuration register */
#define SPINOR_OP_RDFSR 0x70      /* Read flag status register */
#define SPINOR_OP_CLFSR 0x50      /* Clear flag status register */
#define SPINOR_OP_RDEAR 0xc8      /* Read Extended Address Register */
#define SPINOR_OP_WREAR 0xc5      /* Write Extended Address Register */
#define SPINOR_OP_RSTEN 0x66      /* Reset Enable register */
#define SPINOR_OP_RSTMEM 0x99     /* Reset Memory */
#define SPINOR_OP_EN4B 0xb7       /* Enter 4-byte mode */
#define SPINOR_OP_EX4B 0xe9       /* Exit 4-byte mode */


/* 4-byte address opcodes - used on Spansion and some Macronix flashes. */
#define SPINOR_OP_READ_4B 0x13       /* Read data bytes (low frequency) */
#define SPINOR_OP_READ_FAST_4B 0x0c  /* Read data bytes (high frequency) */
#define SPINOR_OP_READ_1_1_2_4B 0x3c /* Read data bytes (Dual Output SPI) */
#define SPINOR_OP_READ_1_2_2_4B 0xbc /* Read data bytes (Dual I/O SPI) */
#define SPINOR_OP_READ_1_1_4_4B 0x6c /* Read data bytes (Quad Output SPI) */
#define SPINOR_OP_READ_1_4_4_4B 0xec /* Read data bytes (Quad I/O SPI) */
#define SPINOR_OP_READ_1_1_8_4B 0x7c /* Read data bytes (Octal Output SPI) */
#define SPINOR_OP_READ_1_8_8_4B 0xcc /* Read data bytes (Octal I/O SPI) */
#define SPINOR_OP_PP_4B 0x12         /* Page program (up to 256 bytes) */
#define SPINOR_OP_PP_1_1_4_4B 0x34   /* Quad page program */
#define SPINOR_OP_PP_1_4_4_4B 0x3e   /* Quad page program */
#define SPINOR_OP_PP_1_1_8_4B 0x84   /* Octal page program */
#define SPINOR_OP_PP_1_8_8_4B 0x8e   /* Octal page program */
#define SPINOR_OP_BE_4K_4B 0x21      /* Erase 4KiB block */
#define SPINOR_OP_BE_32K_4B 0x5c     /* Erase 32KiB block */
#define SPINOR_OP_SE_4B 0xdc         /* Sector erase (usually 64KiB) */

/* issi giga */
#define SPINOR_OP_READ_4S_4D_4D 0xed

/* giga */
#define SPINOR_OP_PP_1_4_4_GIGA 0xc2

/* Double Transfer Rate opcodes - defined in JEDEC JESD216B. */
#define SPINOR_OP_READ_1_1_1_DTR 0x0d
#define SPINOR_OP_READ_1_2_2_DTR 0xbd
#define SPINOR_OP_READ_1_4_4_DTR 0xed
#define SPINOR_OP_READ_1_1_8_DTR 0x9d

#define SPINOR_OP_READ_1_1_1_DTR_4B 0x0e
#define SPINOR_OP_READ_1_2_2_DTR_4B 0xbe
#define SPINOR_OP_READ_1_4_4_DTR_4B 0xee
#define SPINOR_OP_READ_1_8_8_DTR_4B 0xfd

#define SPINOR_ID_CAPACITY_OFFSET 2

#define FLS_START_SEC_VAR_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

static VAR_ALIGN(uint8 training_pattern[32], 32) = {
    0x44, 0x1c, 0x39, 0x05, 0xd3, 0x7a, 0x3c, 0x04,
    0x16, 0x42, 0x0c, 0x8b, 0x7d, 0x12, 0x89, 0xa2,
    0xb8, 0xb1, 0xf7, 0xe8, 0xb7, 0x49, 0xca, 0x1c,
    0xaa, 0x9b, 0xf2, 0x7e, 0x01, 0x97, 0x60, 0x8c
};

static VAR_ALIGN(uint8 training_buf[32], 32) = {0};

#define FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"

static int spi_nor_general_set_4byte_addr_mode(struct spi_nor *nor,
        boolean enable);
static int miron_default_init(struct spi_nor *nor);
static int miron_octal_dtr_enable(struct spi_nor *nor, boolean enable);
static int issi_quad_enable(struct spi_nor *nor, boolean enable);
static int issi_enter_quad(struct spi_nor *nor, boolean enable);
static int issi_default_init(struct spi_nor *nor);
static int giga_enter_quad(struct spi_nor *nor, boolean enable);
static int giga_default_init(struct spi_nor *nor);
static int giga_25q_quad_enable(struct spi_nor *nor, boolean enable);
static int giga_quad_enable(struct spi_nor *nor, boolean enable);
static inline int spibus_write_enable_locked(struct spi_nor *nor, boolean enable);

static int spibus_wait_idle(struct spi_nor *nor);
static int spibus_write_enable(struct spi_nor *nor, boolean enable);
static int spibus_init(struct spi_nor *nor, struct spi_nor_host *host,
                 const struct spi_nor_config *config);
static void spibus_deinit(struct spi_nor *nor);
static int spibus_read(struct spi_nor *nor, flash_addr_t addr, uint8 *buf,
                 flash_size_t size);
static int spibus_write(struct spi_nor *nor, flash_addr_t addr, const uint8 *buf,
                  flash_size_t size);
static int spibus_erase(struct spi_nor *nor, flash_addr_t addr, flash_size_t size);
static int spibus_busy_status(struct spi_nor *nor);
static int spibus_cancel(struct spi_nor *nor);
static void spibus_main_function(struct spi_nor *nor);

#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

Fls_OpsType spi_nor_ops = {
    .fls_wait_idle= spibus_wait_idle,
    .fls_write_enable= spibus_write_enable,
    .fls_init= spibus_init,
    .fls_deinit= spibus_deinit,
    .fls_read= spibus_read,
    .fls_write= spibus_write,
    .fls_erase= spibus_erase,
    .fls_busy_status= spibus_busy_status,
    .fls_cancel= spibus_cancel,
    .fls_main_function= spibus_main_function,
    .fls_setup_handler= spi_nor_setup_handler,
    .fls_get_result= spi_nor_get_result,
    .fls_get_info= spi_nor_get_info,
};

static struct flash_info spi_nor_ids[] = {
    /* miron */
    {
        .name = "mt35xu",
        .flash_id = {0x2c, 0x5b},
        .read_proto = PROTO((uint32)SPINOR_OP_READ_1_8_8, SNOR_PROTO_8_8_8_DTR),
        .write_proto = PROTO((uint32)SPINOR_OP_PP_1_8_8, SNOR_PROTO_8_8_8_DTR),
        .erase_proto = {    PROTO(SPINOR_OP_BE_4K, SNOR_PROTO_8_8_8_DTR),  // erase 4Kb
                            PROTO(SPINOR_OP_BE_32K, SNOR_PROTO_8_8_8_DTR),  // erase 32Kb
                            0,  // erase 64Kb, do not support this mode
                            PROTO((uint32)SPINOR_OP_SE, SNOR_PROTO_8_8_8_DTR),  // erase 128Kb
                            0,  // erase 256Kb, do not support this mode
                        },
        .sector_size = SPINOR_SECTOR_4K_SIZE,
        .sector_type = SPI_NOR_SECTOR_4KB,
        .read_dummy = 20,
        .status_dummy = 8,
        .page_size = 256,
        .set_4byte_addr_mode = spi_nor_general_set_4byte_addr_mode,
        .octal_dtr_enable = miron_octal_dtr_enable,
        .default_init = miron_default_init
    },
    /* miron */
    {
        .name = "mt35xl",
        .flash_id = {0x2c, 0x5a},
        .read_proto = PROTO((uint32)SPINOR_OP_READ_1_8_8, SNOR_PROTO_8_8_8_DTR),
        .write_proto = PROTO((uint32)SPINOR_OP_PP_1_8_8, SNOR_PROTO_8_8_8_DTR),
        .erase_proto = {    PROTO(SPINOR_OP_BE_4K, SNOR_PROTO_8_8_8_DTR),  // erase 4Kb
                            PROTO(SPINOR_OP_BE_32K, SNOR_PROTO_8_8_8_DTR),  // erase 32Kb
                            0,  // erase 64Kb, do not support this mode
                            PROTO((uint32)SPINOR_OP_SE, SNOR_PROTO_8_8_8_DTR),  // erase 128Kb
                            0,  // erase 256Kb, do not support this mode
                        },
        .sector_size = SPINOR_SECTOR_4K_SIZE,
        .sector_type = SPI_NOR_SECTOR_4KB,
        .read_dummy = 20,
        .status_dummy = 8,
        .page_size = 256,
        .set_4byte_addr_mode = spi_nor_general_set_4byte_addr_mode,
        .octal_dtr_enable = miron_octal_dtr_enable,
        .default_init = miron_default_init
    },
    /* issi */
    {
        .name = "is25wp",
        .flash_id = {0x9d, 0x70},
        .read_proto = PROTO((uint32)SPINOR_OP_READ_1_4_4, SNOR_PROTO_4_4_4),
        .write_proto = PROTO(SPINOR_OP_PP, SNOR_PROTO_4_4_4),
        .erase_proto = {    PROTO(SPINOR_OP_BE_4K, SNOR_PROTO_8_8_8_DTR),  // erase 4Kb
                            PROTO(SPINOR_OP_BE_32K, SNOR_PROTO_8_8_8_DTR),  // erase 32Kb
                            PROTO((uint32)SPINOR_OP_SE, SNOR_PROTO_8_8_8_DTR),  // erase 64Kb
                            0,  // erase 128Kb, do not support this mode
                            0,  // erase 256Kb, do not support this mode
                        },
        .sector_size = SPINOR_SECTOR_4K_SIZE,
        .sector_type = SPI_NOR_SECTOR_4KB,
        .read_dummy = 14,
        .status_dummy = 0,
        .page_size = 256,
        .set_4byte_addr_mode = spi_nor_general_set_4byte_addr_mode,
        .quad_enable = issi_quad_enable,
        .enter_quad = issi_enter_quad,
        .default_init = issi_default_init
    },
    {
        .name = "is25lp",
        .flash_id = {0x9d, 0x60},
        .read_proto = PROTO((uint32)SPINOR_OP_READ_1_4_4, SNOR_PROTO_4_4_4),
        .write_proto = PROTO(SPINOR_OP_PP, SNOR_PROTO_4_4_4),
        .erase_proto = {    PROTO(SPINOR_OP_BE_4K, SNOR_PROTO_8_8_8_DTR),  // erase 4Kb
                            PROTO(SPINOR_OP_BE_32K, SNOR_PROTO_8_8_8_DTR),  // erase 32Kb
                            PROTO((uint32)SPINOR_OP_SE, SNOR_PROTO_8_8_8_DTR),  // erase 64Kb
                            0,  // erase 128Kb, do not support this mode
                            0,  // erase 256Kb, do not support this mode
                        },
        .sector_size = SPINOR_SECTOR_4K_SIZE,
        .sector_type = SPI_NOR_SECTOR_4KB,
        .read_dummy = 14,
        .status_dummy = 0,
        .page_size = 256,
        .set_4byte_addr_mode = spi_nor_general_set_4byte_addr_mode,
        .quad_enable = issi_quad_enable,
        .enter_quad = issi_enter_quad,
        .default_init = issi_default_init
    },
    /* giga */
    {
        .name = "gd25lb",
        .flash_id = {0xc8, 0x67},
        .read_proto = PROTO(SPINOR_OP_READ_1_1_4, SNOR_PROTO_4_4_4),
        .write_proto = PROTO((uint32)SPINOR_OP_PP_1_4_4_GIGA, SNOR_PROTO_4_4_4),
        .erase_proto = {    PROTO(SPINOR_OP_BE_4K, SNOR_PROTO_8_8_8_DTR),  // erase 4Kb
                            PROTO(SPINOR_OP_BE_32K, SNOR_PROTO_8_8_8_DTR),  // erase 32Kb
                            PROTO((uint32)SPINOR_OP_SE, SNOR_PROTO_8_8_8_DTR),  // erase 64Kb
                            0,  // erase 128Kb, do not support this mode
                            0,  // erase 256Kb, do not support this mode
                        },
        .sector_size = SPINOR_SECTOR_4K_SIZE,
        .sector_type = SPI_NOR_SECTOR_4KB,
        .read_dummy = 10,
        .status_dummy = 0,
        .page_size = 256,
        .set_4byte_addr_mode = spi_nor_general_set_4byte_addr_mode,
        .enter_quad = giga_enter_quad,
        .default_init = giga_default_init
    },
    {
        .name = "gd25q",
        .flash_id = {0xc8, 0x40},
        .read_proto = PROTO(SPINOR_OP_READ_1_1_4, SNOR_PROTO_1_1_4),
        .write_proto = PROTO(SPINOR_OP_PP_1_1_4, SNOR_PROTO_1_1_4),
        .erase_proto = {    PROTO(SPINOR_OP_BE_4K, SNOR_PROTO_8_8_8_DTR),  // erase 4Kb
                            PROTO(SPINOR_OP_BE_32K, SNOR_PROTO_8_8_8_DTR),  // erase 32Kb
                            PROTO((uint32)SPINOR_OP_SE, SNOR_PROTO_8_8_8_DTR),  // erase 64Kb
                            0,  // erase 128Kb, do not support this mode
                            0,  // erase 256Kb, do not support this mode
                        },
        .sector_size = SPINOR_SECTOR_4K_SIZE,
        .sector_type = SPI_NOR_SECTOR_4KB,
        .read_dummy = 8,
        .status_dummy = 0,
        .page_size = 256,
        .set_4byte_addr_mode = spi_nor_general_set_4byte_addr_mode,
        .quad_enable = giga_25q_quad_enable,
    },
    {
        .name = "gd25f",
        .flash_id = {0xc8, 0x43},
        .read_proto = PROTO(SPINOR_OP_READ_1_1_4, SNOR_PROTO_1_1_4),
        .write_proto = PROTO(SPINOR_OP_PP_1_1_4, SNOR_PROTO_1_1_4),
        .erase_proto = {    PROTO(SPINOR_OP_BE_4K, SNOR_PROTO_8_8_8_DTR),  // erase 4Kb
                            PROTO(SPINOR_OP_BE_32K, SNOR_PROTO_8_8_8_DTR),  // erase 32Kb
                            PROTO((uint32)SPINOR_OP_SE, SNOR_PROTO_8_8_8_DTR),  // erase 64Kb
                            0,  // erase 128Kb, do not support this mode
                            0,  // erase 256Kb, do not support this mode
                        },
        .sector_size = SPINOR_SECTOR_4K_SIZE,
        .sector_type = SPI_NOR_SECTOR_4KB,
        .read_dummy = 8,
        .status_dummy = 0,
        .page_size = 256,
        .set_4byte_addr_mode = spi_nor_general_set_4byte_addr_mode,
        .quad_enable = giga_quad_enable,
    },
    {
        .name = "gd25lx",
        .flash_id = {0xc8, 0x68},
        .read_proto = PROTO((uint32)SPINOR_OP_READ_1_8_8, SNOR_PROTO_8_8_8_DTR),
        .write_proto = PROTO((uint32)SPINOR_OP_PP_1_8_8, SNOR_PROTO_8_8_8_DTR),
        .erase_proto = {    PROTO(SPINOR_OP_BE_4K, SNOR_PROTO_8_8_8_DTR),  // erase 4Kb
                            PROTO(SPINOR_OP_BE_32K, SNOR_PROTO_8_8_8_DTR),  // erase 32Kb
                            PROTO((uint32)SPINOR_OP_SE, SNOR_PROTO_8_8_8_DTR),  // erase 64Kb
                            0,  // erase 128Kb, do not support this mode
                            0,  // erase 256Kb, do not support this mode
                        },
        .sector_size = SPINOR_SECTOR_4K_SIZE,
        .read_dummy = 14,
        .status_dummy = 8,
        .page_size = 256,
        .set_4byte_addr_mode = spi_nor_general_set_4byte_addr_mode,
        .octal_dtr_enable = miron_octal_dtr_enable,
        .default_init = miron_default_init
    },
    {
        .name = "S25fl",
        .flash_id = {0x01, 0x60},
        .read_proto = PROTO(SPINOR_OP_READ_FAST, SNOR_PROTO_1_1_1),
        .write_proto = PROTO(SPINOR_OP_PP, SNOR_PROTO_1_1_1),
        .erase_proto = {    PROTO(SPINOR_OP_BE_4K, SNOR_PROTO_1_1_1),  // erase 4Kb
                            PROTO(SPINOR_OP_BE_32K, SNOR_PROTO_1_1_1),  // erase 32Kb
                            PROTO((uint32)SPINOR_OP_SE, SNOR_PROTO_1_1_1),  // erase 64Kb
                            0,  // erase 128Kb, do not support this mode
                            0,  // erase 256Kb, do not support this mode
                        },
        .sector_size = SPINOR_SECTOR_4K_SIZE,
        .sector_type = SPI_NOR_SECTOR_4KB,
        .read_dummy = 8,
        .status_dummy = 0,
        .page_size = 256,
        //.set_4byte_addr_mode = spi_nor_general_set_4byte_addr_mode,
        //.quad_enable = giga_quad_enable,
    },
};

#define FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"

static inline int spi_nor_reg_read(struct spi_nor *flash_handle,
                            struct spi_nor_cmd *cmd, flash_addr_t addr,
                            uint8 *buf, flash_size_t length)
{
    int ret;

    flash_handle->host->ops->prepare(flash_handle, SPI_NOR_OPS_LOCK);
    ret = flash_handle->host->ops->reg_read(flash_handle, cmd, addr, buf, length);
    flash_handle->host->ops->unprepare(flash_handle, SPI_NOR_OPS_LOCK);

    return ret;
}

static inline int spi_nor_reg_write(struct spi_nor *flash_handle,
                             struct spi_nor_cmd *cmd, flash_addr_t addr,
                             uint8 *buf, flash_size_t length)
{
    int ret;

    flash_handle->host->ops->prepare(flash_handle, SPI_NOR_OPS_LOCK);
    ret = flash_handle->host->ops->reg_write(flash_handle, cmd, addr, buf, length);
    flash_handle->host->ops->unprepare(flash_handle, SPI_NOR_OPS_LOCK);

    return ret;
}

static int spi_nor_get_status(struct spi_nor *nor, uint8 *status)
{
    uint8 reg[2] = {0};

    int ret;
    struct spi_nor_cmd read_cmd = {
        .opcode = SPINOR_OP_RDSR,
        .addr_bytes = 0,
        .dummy = nor->info.status_dummy,
        .inst_type = SNOR_INST_LANS(nor->reg_proto),
    };

    ret = spi_nor_reg_read(nor, &read_cmd, 0, reg, 2);

    if (ret) {
        return ret;
    }

    *status = reg[0];
    return 0;
}

static int spibus_busy_status(struct spi_nor *nor)
{
    int ret = 0;
    uint8 flash_status;

    ret = spi_nor_get_status(nor, &flash_status);

    if (ret) {
        DBG("spi_nor get flash status failed, ret: %d!\n", ret);
        return ret;
    }

    if (flash_status & BIT(0))
        return -1;

    return ret;
}

static int spibus_write_enable(struct spi_nor *nor, boolean enable)
{
    int ret;

    struct spi_nor_cmd wr_en_cmd = {
        .opcode = enable ? SPINOR_OP_WREN : SPINOR_OP_WRDI,
        .addr_bytes = 0,
        .inst_type = SNOR_INST_LANS(nor->reg_proto),
        .dummy = 0,
    };

    ret = nor->host->ops->reg_write(nor, &wr_en_cmd, 0, 0, 0);

    return ret;
}

static inline int spibus_write_enable_locked(struct spi_nor *nor, boolean enable)
{
    int ret;

    nor->host->ops->prepare(nor, SPI_NOR_OPS_LOCK);
    ret = spibus_write_enable(nor, enable);
    nor->host->ops->unprepare(nor, SPI_NOR_OPS_LOCK);

    return ret;
}

static int spibus_wait_idle(struct spi_nor *nor)
{
    int ret = 0;
    uint8 flash_status = 0;
    uint32 tick_count = 0;
    uint32 parallel_count = 0;

    while (1) {
        ret = spi_nor_get_status(nor, &flash_status);

        if (ret) {
            if ((nor->dev_mode == SPI_NOR_DEV_PARALLEL_MODE)
                && (parallel_count < 1000000)) {
                parallel_count++;
                Mcu_udelay(1);
            } else {
                DBG("spi_nor get flash status failed, ret: %d!\n", ret);
                break;
            }
        }

        if (!(flash_status & BIT(0)))
            break;

        if (tick_count > 1000000) {
            ret = -1;
            DBG("wait flash idle timeout, ret = %d!\n", ret);
            break;
        }

        Mcu_udelay(1);
        tick_count++;
    }

    return ret;
}

static int spi_nor_soft_reset(struct spi_nor *nor)
{
    int ret = 0;

    struct spi_nor_cmd rst_en_cmd = {
        .opcode = SPINOR_OP_RSTEN,
        .dummy = 0,
        .addr_bytes = 0,
        .inst_type = SNOR_INST_LANS(nor->reg_proto),
    };

    struct spi_nor_cmd rst_mem_cmd = {
        .opcode = SPINOR_OP_RSTMEM,
        .dummy = 0,
        .addr_bytes = 0,
        .inst_type = SNOR_INST_LANS(nor->reg_proto),
    };

    ret = spi_nor_reg_write(nor, &rst_en_cmd, 0, 0, 0);

    if (ret) {
        return ret;
    }

    ret = spi_nor_reg_write(nor, &rst_mem_cmd, 0, 0, 0);

    return ret;
}


int spi_nor_id_read(struct spi_nor *nor)
{
    int ret = 0;
    uint8 id[8];
    struct flash_info *info;
    uint32 reg_lans_list[] = {ID_PROTO(0, SNOR_PROTO_1_1_1), ID_PROTO(0, SNOR_PROTO_2_2_2),
                              ID_PROTO(0, SNOR_PROTO_4_4_4), ID_PROTO(8, SNOR_PROTO_8_8_8_DTR)
                             };

    struct spi_nor_cmd read_cmd = {
        .opcode = SPINOR_OP_RDID,
        .dummy = reg_lans_list[0] >> SNOR_READID_DUMMY_LSB,
                                  .addr_bytes = 0,
                                  .inst_type = SNOR_INST_LANS(reg_lans_list[0]),
    };

    for (int i = 0; i < ARRAY_SZ(reg_lans_list); i++) {
        read_cmd.dummy = (reg_lans_list[i] >> SNOR_READID_DUMMY_LSB) & 0xff;
        read_cmd.inst_type = SNOR_INST_LANS(reg_lans_list[i]);
        nor->reg_proto = reg_lans_list[i] & SNOR_PROTO_MASK;

        if (reg_lans_list[i] & SNOR_DTR_PROTO) {
            nor->octal_dtr_en = 1;
            nor->addr_width = 4;
        }

        DBG("octal_dtr_en: %d, dummy = %d, inst_type = %d, \
proto = %x\n", nor->octal_dtr_en, read_cmd.dummy, read_cmd.inst_type,
            nor->reg_proto);

        ret = spi_nor_reg_read(nor, &read_cmd, 0, id, 4);

        if (ret) return ret;

        DBG("norflash id0: %x, id1: %x, id2: %x\n", id[0], id[1],
            id[2]);

        for (uint32 j = 0; j < ARRAY_NUMS(spi_nor_ids); j++) {
            info = &spi_nor_ids[j];

            if (!mini_memcmp_s(info->flash_id, id, 2)) {
                // info->size = 1 << id[SPINOR_ID_CAPACITY_OFFSET];
                mini_memcpy_s(&nor->info, info, sizeof(struct flash_info));
                nor->info.size = 1 << id[SPINOR_ID_CAPACITY_OFFSET];
                return 0;
            }
        }
    }

    return -1;
}

static int spi_nor_octal_dtr_enable(struct spi_nor *nor, boolean enable)
{
    int ret;

    if (!nor->info.octal_dtr_enable) {
        return 0;
    }

    if (!(SNOR_PROTO_DTR(nor->info.read_proto) == SNOR_PROTO_8_8_8_DTR &&
          SNOR_PROTO_DTR(nor->info.write_proto) == SNOR_PROTO_8_8_8_DTR)) {
        return 0;
    }

    ret = nor->info.octal_dtr_enable(nor, enable);

    if (ret) {
        return ret;
    }

    if (enable) {
        nor->octal_dtr_en = 1;
        nor->dqs_en = 1;
        nor->reg_proto = SNOR_PROTO_8_8_8_DTR;
        nor->addr_width = 4;
    } else {
        nor->octal_dtr_en = 0;
        nor->dqs_en = 0;
        nor->reg_proto = SNOR_PROTO_1_1_1;
        nor->addr_width = 3;
    }

    return ret;
}


static int spi_nor_quad_enable(struct spi_nor *nor, boolean enable)
{
    int ret;

    if (!nor->info.quad_enable) {
        return 0;
    }

    if (!(SNOR_DATA_LANS(nor->info.read_proto) == 2 ||
          SNOR_DATA_LANS(nor->info.write_proto) == 2)) {
        return 0;
    }

    ret = nor->info.quad_enable(nor, enable);

    return ret;
}

static int spi_nor_enter_quad(struct spi_nor *nor, boolean enable)
{
    int ret;

    if (!nor->info.enter_quad) {
        return 0;
    }

    if (SNOR_PROTO(nor->info.read_proto) != SNOR_PROTO_4_4_4 ||
        SNOR_PROTO(nor->info.write_proto) != SNOR_PROTO_4_4_4) {
        return 0;
    }

    ret = nor->info.enter_quad(nor, enable);

    if (ret) {
        return ret;
    }

    nor->reg_proto = enable ? SNOR_PROTO_4_4_4 : SNOR_PROTO_1_1_1;

    return ret;
}

static int spi_nor_set_4byte(struct spi_nor *nor, boolean enable)
{
    int ret;

    if (!nor->info.set_4byte_addr_mode ||
        nor->info.size <= 0x1000000) {
        return 0;
    }

    ret = nor->info.set_4byte_addr_mode(nor, enable);

    if (ret) {
        return ret;
    }

    nor->addr_width = enable ? 4 : 3;

    return ret;
}

static int spibus_init(struct spi_nor *nor, struct spi_nor_host *host,
                 const struct spi_nor_config *config)
{
    int ret = 0;
    uint32 training_len = 32;
    flash_addr_t training_addr;

    nor->id = config->id;
    nor->baudrate = config->baudrate;
    nor->xfer_mode = config->xfer_mode;
    nor->dev_mode = config->dev_mode;
    nor->host = host;
    nor->sw_rst = config->sw_rst;

    nor->reg_proto = SNOR_PROTO_1_1_1;
    nor->addr_width = 3;
    nor->octal_dtr_en = 0;
    nor->dqs_en = 0;

    ret = spi_nor_id_read(nor);

    if (ret) {
        return -1;
    }

    if (nor->dev_mode == SPI_NOR_DEV_PARALLEL_MODE) {
        nor->info.sector_size *= 2u;
        nor->info.size *= 2u;
    }

    DBG("flash size: %llx\n", nor->info.size);

    if (nor->sw_rst) {
        spi_nor_soft_reset(nor);
        /* more than 200 ms */
        Mcu_udelay(500);
        nor->octal_dtr_en = 0;
        nor->reg_proto = SNOR_PROTO_1_1_1;
        nor->addr_width = 3;
        nor->dqs_en = 0;
    }

    /* set dummy ... */
    if (nor->info.default_init) {
        nor->info.default_init(nor);
    }

    /* if more than 16MB, set 4 byte mode */
    spi_nor_set_4byte(nor, true);

    spi_nor_octal_dtr_enable(nor, true);

    /* test octal ddr */
#if 0
    nor->reg_proto = SNOR_PROTO_1_1_1;
    nor->addr_width = 3;
    nor->octal_dtr_en = 0;
    nor->info = spi_nor_id_read(nor);

    if (!nor->info) {
        return -1;
    }

    if (nor->sw_rst) {
        spi_nor_soft_reset(nor);
        /* more than 200 ms */
        osDelay(500);
        nor->octal_dtr_en = 0;
        nor->reg_proto = SNOR_PROTO_1_1_1;
        nor->addr_width = 3;
        nor->dqs_en = 0;
    }

    /* set dummy ... */
    if (nor->info.default_init)
        nor->info.default_init(nor);

    /* if more than 16MB, set 4 byte mode */
    if (nor->info.size > 0x1000000) {
        if (nor->info.set_4byte_addr_mode) {
            nor->info.set_4byte_addr_mode(nor, true);
            nor->addr_width = 4;
        }
    }

    spi_nor_octal_dtr_enable(nor, true);
#endif

    spi_nor_quad_enable(nor, true);

    spi_nor_enter_quad(nor, true);

    if (nor->host->ops->training) {
        training_addr = nor->info.sector_size;
        spibus_read(nor, training_addr, training_buf, 32);

        if (0u != mini_memcmp_s(training_pattern, training_buf, training_len)) {
            if (spibus_erase(nor, training_addr, nor->info.sector_size)) {
                return -1;
            }
#ifdef CONFIG_FLS_HAL_POLLING
            /* wait for flash idle */
            ret = spibus_wait_idle(nor);
            if (ret)
                return -1;
#endif

            if (spibus_write(nor, training_addr, training_pattern, training_len)) {
                return -1;
            }
#ifdef CONFIG_FLS_HAL_POLLING
            /* wait for flash idle */
            ret = spibus_wait_idle(nor);
            if (ret)
                return -1;
#endif
        }

        if (nor->host->clk != NULL) {
            clk_set_rate(nor->host->clk, nor->host->ref_clk_hz);
            DBG("spinor host clock rate is %u!\n",
                clk_get_rate(nor->host->clk));
        }

        ret = nor->host->ops->training(nor, training_addr, training_buf,
                                       training_pattern, training_len);
    }

    /* Don't use async mode for training */
    nor->async_mode = config->async_mode;

    return ret;
}

static void inline spi_nor_setup_xfer(struct spi_nor *nor, enum flash_opt opt,
                                      flash_addr_t addr, uint8 *buf,
                                      flash_size_t size)
{
    nor->xfer_info.opt_type = opt;
    nor->xfer_info.addr = addr;
    nor->xfer_info.buf = buf;
    nor->xfer_info.size = size;
    nor->xfer_info.opt_result = FLASH_OPT_PENDING;
}

static void inline spi_nor_xfer_comp(struct spi_nor *nor)
{
    nor->xfer_info.size = 0;
    nor->xfer_info.opt_result = FLASH_OPT_COMPLETE;
    nor->host->ops->unprepare(nor, (enum spi_nor_ops)nor->xfer_info.opt_type);
    nor->xfer_info.opt_type = (enum flash_opt)0;
}

static void inline spi_nor_xfer_error(struct spi_nor *nor)
{
    nor->xfer_info.size = 0;
    nor->xfer_info.opt_result = FLASH_OPT_FAILED;
    nor->host->ops->unprepare(nor, (enum spi_nor_ops)nor->xfer_info.opt_type);
    nor->xfer_info.opt_type = (enum flash_opt)0;
    DBG("spi_nor xfer failed\n");
}

static int spibus_read(struct spi_nor *nor, flash_addr_t addr, uint8 *buf,
                 flash_size_t size)
{
    int ret;

    nor->host->ops->prepare(nor, SPI_NOR_OPS_READ);
    spi_nor_setup_xfer(nor, FLASH_OPT_READ, addr, buf, size);
    ret = nor->host->ops->read(nor, addr, buf, size);

    if (ret) {
        spi_nor_xfer_error(nor);
    } else if (!nor->async_mode) {
        spi_nor_xfer_comp(nor);
    }

    return ret;
}

static int spibus_write(struct spi_nor *nor, flash_addr_t addr, const uint8 *buf,
                  flash_size_t size)
{
    int ret;

    nor->host->ops->prepare(nor, SPI_NOR_OPS_WRITE);
    spi_nor_setup_xfer(nor, FLASH_OPT_WRITE, addr, (uint8 *)buf, size);
    ret = nor->host->ops->write(nor, addr, buf, size);

    if (ret) {
        spi_nor_xfer_error(nor);
    } else if (!nor->async_mode) {
        spi_nor_xfer_comp(nor);
    }

    return ret;
}

/* the arguments erase length and dst address must 4K alined */
static int spibus_erase(struct spi_nor *nor, flash_addr_t addr, flash_size_t size)
{
    int ret = 0;

    nor->host->ops->prepare(nor, SPI_NOR_OPS_ERASE);
    spi_nor_setup_xfer(nor, FLASH_OPT_ERASE, addr, NULL, size);

    if (!nor->async_mode) {
        while (nor->xfer_info.size) {
            ret = nor->host->ops->erase(nor, nor->xfer_info.addr);

            if (ret)
                break;

#ifndef CONFIG_FLS_HAL_POLLING
            /* wait for flash idle */
            ret = spibus_wait_idle(nor);

            if (ret)
                break;

#endif

            nor->xfer_info.addr += nor->info.sector_size;
            nor->xfer_info.size -= nor->info.sector_size;
        }

        if (ret) {
            spi_nor_xfer_error(nor);
        } else {
            spi_nor_xfer_comp(nor);
        }
    }

    return ret;
}

static int spibus_cancel(struct spi_nor *nor)
{
    if (nor->host->ops->cancel) {
        return nor->host->ops->cancel(nor);
    } else {
        return 0;
    }
}

static void spibus_erase_polling(struct spi_nor *nor)
{
    int ret = 0;
    uint8 flash_status = 0;
    uint32 sector_size = nor->info.sector_size;

    if (nor->xfer_info.size != 0) {
        ret = spi_nor_get_status(nor, &flash_status);

        if (ret) {
            spi_nor_xfer_error(nor);
        } else if (!(flash_status & BIT(0))) {
            ret = nor->host->ops->erase(nor, nor->xfer_info.addr);

            if (ret) {
                spi_nor_xfer_error(nor);
            } else {
                nor->xfer_info.size -= sector_size;
                nor->xfer_info.addr += sector_size;
            }
        }
    }

    if (nor->xfer_info.size == 0) {
        ret = spi_nor_get_status(nor, &flash_status);

        if (ret) {
            spi_nor_xfer_error(nor);
        } else if (!(flash_status & BIT(0))) {
            spi_nor_xfer_comp(nor);
        }
    }
}

extern void spi_nor_drv_main_function(struct spi_nor *nor);

static void spibus_main_function(struct spi_nor *nor)
{
    if (!nor->async_mode)
        return;

    if (nor->xfer_info.opt_result == FLASH_OPT_PENDING) {
        if (nor->xfer_info.opt_type != FLASH_OPT_ERASE) {
            /* spi nor host polling handler */
            spi_nor_drv_main_function(nor);

            if (nor->xfer_info.opt_result != FLASH_OPT_PENDING) {
                nor->host->ops->unprepare(nor, (enum spi_nor_ops)nor->xfer_info.opt_type);
                nor->xfer_info.opt_type = (enum flash_opt)0;
            }
        } else {
            spibus_erase_polling(nor);
        }
    } else {
        if (nor->xfer_info.opt_type) {
            nor->host->ops->unprepare(nor, (enum spi_nor_ops)nor->xfer_info.opt_type);
            nor->xfer_info.opt_type = (enum flash_opt)0;
        }
    }
}

extern void spi_nor_drv_deinit(struct spi_nor *nor);

static void spibus_deinit(struct spi_nor *nor)
{
    spi_nor_drv_deinit(nor);
}

static int spi_nor_general_set_4byte_addr_mode(struct spi_nor *nor,
        boolean enable)
{
    int ret;

    struct spi_nor_cmd byte_cmd = {
        .opcode = enable ? SPINOR_OP_EN4B : SPINOR_OP_EX4B,
        .addr_bytes = 0,
        .inst_type = SNOR_INST_LANS(nor->reg_proto),
        .dummy = 0,
    };

    ret = spi_nor_reg_write(nor, &byte_cmd, 0, 0, 0);

    return ret;
}

static int miron_default_init(struct spi_nor *nor)
{
    int ret;

    VAR_ALIGN(uint8 data[2], 4);

    struct spi_nor_cmd byte_cmd = {
        .opcode = 0x81,
        .addr_bytes = nor->addr_width,
        .inst_type = SNOR_INST_LANS(nor->reg_proto),
        .dummy = 0,
    };

    spibus_write_enable_locked(nor, true);

    data[0] = nor->info.read_dummy;
    ret = spi_nor_reg_write(nor, &byte_cmd, 1, data,
                            SNOR_INST_LANS(nor->reg_proto) == 3 ? 2 : 1);

    if (ret) {
        return ret;
    }

    struct spi_nor_cmd read_cmd = {
        .opcode = 0x85,
        .addr_bytes = nor->addr_width,
        .inst_type = SNOR_INST_LANS(nor->reg_proto),
        .dummy = 8,
    };

    ret = spi_nor_reg_read(nor, &read_cmd, 1, data,
                           SNOR_INST_LANS(nor->reg_proto) == 3 ? 2 : 1);

    if (ret || data[0] != nor->info.read_dummy) {
        DBG("dummy: %d, %d\n", nor->info.read_dummy, data[0]);
        return -1;
    }

    return ret;
}

static int issi_default_init(struct spi_nor *nor)
{
    int ret;
    Fls_ContextType* pCtx = ((Fls_ContextType*)nor->parent);

    VAR_ALIGN(uint8 data[2], 4);

    struct spi_nor_cmd byte_cmd = {
        .opcode = 0xc0,
        .addr_bytes = 0,
        .inst_type = SNOR_INST_LANS(nor->reg_proto),
        .dummy = 0,
    };

    spibus_write_enable_locked(nor, true);

    if (pCtx->ControllerConfig->FlsSpecialFlag == FLS_SPECIAL_IS25LP064A) {
        /* Fix up for IS25LP064A. Refer to descriptions in part.h */
        nor->info.read_dummy = 10;
        data[0] = 0x3 << 3;
    } else {
        data[0] = nor->info.read_dummy << 3;
    }

    ret = spi_nor_reg_write(nor, &byte_cmd, 1, data,
                            SNOR_INST_LANS(nor->reg_proto) == 3 ? 2 : 1);

    return ret;
}


static int miron_octal_dtr_enable(struct spi_nor *nor, boolean enable)
{
    int ret;
    VAR_ALIGN(uint8 data[3], 4);

    struct spi_nor_cmd byte_cmd = {
        .opcode = 0x81,
        .addr_bytes = nor->addr_width,
        .inst_type = SNOR_INST_LANS(nor->reg_proto),
        .dummy = 0,
    };

    spibus_write_enable_locked(nor, true);

    data[0] = enable ? 0xe7 : 0xff;
    ret = spi_nor_reg_write(nor, &byte_cmd, 0, data,
                            SNOR_INST_LANS(nor->reg_proto) == 3 ? 2 : 1);

    if (enable) {
        nor->octal_dtr_en = 1;
        nor->dqs_en = 1;

        struct spi_nor_cmd read_cmd = {
            .opcode = 0x85,
            .addr_bytes = 4,
            .inst_type = 3,
            .dummy = 8,
        };

        ret = spi_nor_reg_read(nor, &read_cmd, 0, data, 2);

        if (ret || data[0] != 0xe7) {
            DBG("I/O mode: %x, %x, ret = %d\n", data[0], data[1], ret);
            return -1;
        }
    }

    return ret;
}

static int issi_quad_enable(struct spi_nor *nor, boolean enable)
{
    int ret = 0;
    VAR_ALIGN(uint8 data[2], 4);

    struct spi_nor_cmd r_cmd = {
        .opcode = SPINOR_OP_RDSR,
        .addr_bytes = 0,
        .inst_type = SNOR_INST_LANS(nor->reg_proto),
        .dummy = 0,
    };

    ret = spi_nor_reg_read(nor, &r_cmd, 0, data,
                           SNOR_INST_LANS(nor->reg_proto) == 3 ? 2 : 1);

    if (ret) {
        // The parallel mode register is different and set to the default value
        if (nor->dev_mode == SPI_NOR_DEV_PARALLEL_MODE) {
            data[0] = 0;
            data[1] = 0;
        } else {
            return ret;
        }
    }

    if (!(data[0] & (1u << 6))) {
        struct spi_nor_cmd w_cmd = {
            .opcode = SPINOR_OP_WRSR,
            .addr_bytes = 0,
            .inst_type = SNOR_INST_LANS(nor->reg_proto),
            .dummy = 0,
        };


        spibus_write_enable_locked(nor, true);

        data[0] |= (1u << 6);
        ret = spi_nor_reg_write(nor, &w_cmd, 0, data,
                                SNOR_INST_LANS(nor->reg_proto) == 3 ? 2 : 1);
    }

    return ret;
}

static int issi_enter_quad(struct spi_nor *nor, boolean enable)
{
    int ret = 0;

    struct spi_nor_cmd q_cmd = {
        .opcode = enable ? 0x35 : 0xf5,
        .addr_bytes = 0,
        .inst_type = SNOR_INST_LANS(nor->reg_proto),
        .dummy = 0,
    };

    ret = spi_nor_reg_write(nor, &q_cmd, 0, 0, 0);

    return ret;
}


static int giga_enter_quad(struct spi_nor *nor, boolean enable)
{
    int ret = 0;

    struct spi_nor_cmd cmd = {
        .opcode = enable ? 0x38 : 0xff,
        .addr_bytes = 0,
        .inst_type = SNOR_INST_LANS(nor->reg_proto),
        .dummy = 0,
    };

    ret = spi_nor_reg_write(nor, &cmd, 0, 0, 0);

    return ret;
}

static int giga_default_init(struct spi_nor *nor)
{
    int ret;
    VAR_ALIGN(uint8 data[2], 4);

    struct spi_nor_cmd byte_cmd = {
        .opcode = 0x81,
        .addr_bytes = nor->addr_width,
        .inst_type = SNOR_INST_LANS(nor->reg_proto),
        .dummy = 0,
    };

    spibus_write_enable_locked(nor, true);

    data[0] = nor->info.read_dummy;
    ret = spi_nor_reg_write(nor, &byte_cmd, 1, data,
                            SNOR_INST_LANS(nor->reg_proto) == 3 ? 2 : 1);

    if (ret) {
        return ret;
    }

    struct spi_nor_cmd read_cmd = {
        .opcode = 0x85,
        .addr_bytes = nor->addr_width,
        .inst_type = SNOR_INST_LANS(nor->reg_proto),
        .dummy = 8,
    };

    ret = spi_nor_reg_read(nor, &read_cmd, 1, data,
                           SNOR_INST_LANS(nor->reg_proto) == 3 ? 2 : 1);

    if (ret || data[0] != nor->info.read_dummy) {
        DBG("dummy: %d, %d\n", nor->info.read_dummy, data[0]);
        return -1;
    }

    return ret;
}


static int giga_quad_enable(struct spi_nor *nor, boolean enable)
{
    int ret = 0;
    VAR_ALIGN(uint8 data[2], 4);
    VAR_ALIGN(uint8 rdata[2], 4);

    struct spi_nor_cmd r_cmd = {
        .opcode = 0x35,
        .addr_bytes = 0,
        .inst_type = SNOR_INST_LANS(nor->reg_proto),
        .dummy = 0,
    };

    ret = spi_nor_reg_read(nor, &r_cmd, 0, data,
                           SNOR_INST_LANS(nor->reg_proto) == 3 ? 2 : 1);


    if (ret) {
        // The parallel mode register is different and set to the default value
        if (nor->dev_mode == SPI_NOR_DEV_PARALLEL_MODE) {
            data[0] = 0;
            data[1] = 0;
        } else {
            return ret;
        }
    }

    if (!(data[0] & (1u << 1))) {
        struct spi_nor_cmd w_cmd = {
            .opcode = 0x31,
            .addr_bytes = 0,
            .inst_type = SNOR_INST_LANS(nor->reg_proto),
            .dummy = 0,
        };

        spibus_write_enable_locked(nor, true);
        data[0] |= (1u << 1);
        ret |= spi_nor_reg_write(nor, &w_cmd, 0, data,
                                SNOR_INST_LANS(nor->reg_proto) == 3 ? 2 : 1);
    }

    ret |= spi_nor_reg_read(nor, &r_cmd, 0, rdata,
                           SNOR_INST_LANS(nor->reg_proto) == 3 ? 2 : 1);

    if (ret || !(rdata[0] & (1u << 1))) {
        DBG("I/O mode: %x, %x, ret = %d\n", data[0], data[1], ret);
        return -1;
    }

    return ret;
}

static int giga_25q_quad_enable(struct spi_nor *nor, boolean enable)
{
    int ret = 0;
    VAR_ALIGN(uint8 data[2], 4);
    VAR_ALIGN(uint8 rdata[2], 4);

    struct spi_nor_cmd r_cmd = {
        .opcode = 0x35,
        .addr_bytes = 0,
        .inst_type = SNOR_INST_LANS(nor->reg_proto),
        .dummy = 0,
    };

    ret = spi_nor_reg_read(nor, &r_cmd, 0, rdata,
                           SNOR_INST_LANS(nor->reg_proto) == 3 ? 2 : 1);
    if (ret) {
        // The parallel mode register is different and set to the default value
        if (nor->dev_mode == SPI_NOR_DEV_PARALLEL_MODE) {
            rdata[0] = 0;
            rdata[1] = 0;
        } else {
            return ret;
        }
    }

    if (!(rdata[0] & (1u << 1))) {
        struct spi_nor_cmd w_cmd = {
            .opcode = 0x31,
            .addr_bytes = 0,
            .inst_type = SNOR_INST_LANS(nor->reg_proto),
            .dummy = 0,
        };
        flash_size_t length;

        if (nor->info.size == 0x80000) {
            w_cmd.opcode = 0x01;
            length = 2;
            ret = spi_nor_get_status(nor, &data[0]);
            if (ret)
                return -1;
            data[1] = rdata[0] | (1u << 1);
        } else {
            length = SNOR_INST_LANS(nor->reg_proto) == 3 ? 2 : 1;
            data[0] = rdata[0] | (1u << 1);
        }
        spibus_write_enable_locked(nor, true);
        ret = spi_nor_reg_write(nor, &w_cmd, 0, data, length);
        if (ret)
            return -1;
        /* wait for flash idle */
        ret = spibus_wait_idle(nor);
        if (ret)
            return -1;
    }

    ret = spi_nor_reg_read(nor, &r_cmd, 0, rdata,
                           SNOR_INST_LANS(nor->reg_proto) == 3 ? 2 : 1);

    if (ret || !(rdata[0] & (1u << 1))) {
        DBG("I/O mode: %x, %x, ret = %d\n", rdata[0], rdata[1], ret);
        return -1;
    }

    return ret;
}

#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#ifdef __cplusplus
}
#endif
