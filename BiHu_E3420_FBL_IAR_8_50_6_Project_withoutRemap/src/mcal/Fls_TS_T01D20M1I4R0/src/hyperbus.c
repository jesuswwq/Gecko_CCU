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
* @file  hyperbus.c
* @brief Semidrive. AUTOSAR 4.3.1 MCAL Fls plugins.
*/

#ifdef __cplusplus
extern "C" {
#endif

#include <Compiler.h>
#include <cdefs.h>

#include "Fls.h"
#include "Mcu_Delay.h"
#include "Fls_Cfg.h"
#include "debug.h"
#include "Mcal.h"

#define PROTO(_opcode, _dq) \
        (_opcode << SNOR_OPCODE_PROTO_LSB | _dq)
#define ID_PROTO(dummy, _dq) \
        (dummy << SNOR_READID_DUMMY_LSB | _dq)

#define SPINOR_ID_CAPACITY_OFFSET 2

#define FLS_START_SEC_VAR_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

uint8 training_pattern[32] ALIGNED(32) = {
    0x44, 0x1c, 0x39, 0x05, 0xd3, 0x7a, 0x3c, 0x04,
    0x16, 0x42, 0x0c, 0x8b, 0x7d, 0x12, 0x89, 0xa2,
    0xb8, 0xb1, 0xf7, 0xe8, 0xb7, 0x49, 0xca, 0x1c,
    0xaa, 0x9b, 0xf2, 0x7e, 0x01, 0x97, 0x60, 0x8c
};
uint8 training_buf[32] ALIGNED(32) = {0};

struct hyperflash_cmd hyper_read_status = {
    .name = "read status",
    .is_read = true,
    .num = 1,
    .ca = {{0x555, 0x70}},
};

struct hyperflash_cmd hyper_read_vol_reg1 = {
    .name = "read vol reg1",
    .is_read = true,
    .num = 3,
    .ca = {{0x555, 0xAA}, {0x2AA, 0x55}, {0x555, 0xC7}},
};

struct hyperflash_cmd hyper_write_vol_reg1 = {
    .name = "write vol reg1",
    .is_read = true,
    .num = 3,
    .ca = {{0x555, 0xAA}, {0x2AA, 0x55}, {0x555, 0x38}},
};

struct hyperflash_cmd hyper_read_vol_reg2 = {
    .name = "read vol reg2",
    .is_read = true,
    .num = 3,
    .ca = {{0x555, 0xAA}, {0x2AA, 0x55}, {0x555, 0xC9}},
};

struct hyperflash_cmd hyper_write_vol_reg2 = {
    .name = "write vol reg2",
    .is_read = false,
    .num = 3,
    .ca = {{0x555, 0xAA}, {0x2AA, 0x55}, {0x555, 0x3A}},
};

struct hyperflash_cmd hyper_read_ecc_reg = {
    .name = "read ecc reg",
    .is_read = true,
    .num = 3,
    .ca = {{0x555, 0xAA}, {0x2AA, 0x55}, {0x555, 0x75}},
};

struct hyperflash_cmd hyper_read_id = {
    .name = "read device id",
    .is_read = true,
    .num = 4,
    .ca = {{0x555, 0xAA}, {0x2AA, 0x55}, {0x555, 0x90}, {0x555, 0x98}},
};

struct hyperflash_cmd hyper_sector_erase = {
    .name = "sector_erase",
    .is_read = false,
    .num = 5,
    .ca = {{0x555, 0xAA}, {0x2AA, 0x55}, {0x555, 0x80}, {0x555, 0xAA}, {0x2AA, 0x55}},
};

struct hyperflash_cmd hyper_word_program = {
    .name = "word_program",
    .is_read = false,
    .num = 3,
    .ca = {{0x555, 0xAA}, {0x2AA, 0x55}, {0x555, 0xA0}},
};

#define FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"

static int s26h_default_init(struct spi_nor *nor);

static int hyperbus_wait_idle(struct spi_nor *nor);
static int hyperbus_write_enable(struct spi_nor *nor, boolean enable);
static int hyperbus_init(struct spi_nor *nor, struct spi_nor_host *host,
                 const struct spi_nor_config *config);
static void hyperbus_deinit(struct spi_nor *nor);
static int hyperbus_read(struct spi_nor *nor, flash_addr_t addr, uint8 *buf,
                 flash_size_t size);
static int hyperbus_write(struct spi_nor *nor, flash_addr_t addr, const uint8 *buf,
                  flash_size_t size);
static int hyperbus_erase(struct spi_nor *nor, flash_addr_t addr, flash_size_t size);
static int hyperbus_busy_status(struct spi_nor *nor);
static int hyperbus_cancel(struct spi_nor *nor);
static void hyperbus_main_function(struct spi_nor *nor);

#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

Fls_OpsType hyperbus_ops = {
    .fls_wait_idle= hyperbus_wait_idle,
    .fls_write_enable= hyperbus_write_enable,
    .fls_init= hyperbus_init,
    .fls_deinit= hyperbus_deinit,
    .fls_read= hyperbus_read,
    .fls_write= hyperbus_write,
    .fls_erase= hyperbus_erase,
    .fls_busy_status= hyperbus_busy_status,
    .fls_cancel= hyperbus_cancel,
    .fls_main_function= hyperbus_main_function,
    .fls_setup_handler= spi_nor_setup_handler,
    .fls_get_result= spi_nor_get_result,
    .fls_get_info= spi_nor_get_info,
};

static struct flash_info hyperbus_ids[] = {
    {
        .name = "default",
        /* The 0x00, 0xff, 0x00, 0xff, is a dummy device ID */
        .flash_id = {0x00, 0xff, 0x00, 0xff},
        .read_proto = PROTO(0u, SNOR_PROTO_8_8_8_DTR),
        .write_proto = PROTO(0u, SNOR_PROTO_8_8_8_DTR),
        .read_dummy = 16,
        .write_dummy = 0,
        .page_size = 256,
    },
    {
        .name = "hyperram",
        /* The 0x00, 0xff, 0x00, 0xff, is a dummy device ID */
        .flash_id = {0x00, 0xff, 0x00, 0xff},
        .read_proto = PROTO(0u, SNOR_PROTO_8_8_8_DTR),
        .write_proto = PROTO(0u, SNOR_PROTO_8_8_8_DTR),
        .read_dummy = 5,
        .write_dummy = 5,
    },
    /* cypress */
    {
        .name = "s26hs",
        .flash_id = {0x34, 0x00, 0x7B, 0x00},
        .read_proto = PROTO(0u, SNOR_PROTO_8_8_8_DTR),
        .write_proto = PROTO(0u, SNOR_PROTO_8_8_8_DTR),
        .sector_size = SPINOR_SECTOR_256K_SIZE,
        .sector_type = SPI_NOR_SECTOR_256KB,
        .read_dummy = 16,
        .write_dummy = 0,
        .page_size = 256,
        .default_init = s26h_default_init,
    },
    {
        .name = "s26hl",
        .flash_id = {0x34, 0x00, 0x6a, 0x00},
        .read_proto = PROTO(0u, SNOR_PROTO_8_8_8_DTR),
        .write_proto = PROTO(0u, SNOR_PROTO_8_8_8_DTR),
        .sector_size = SPINOR_SECTOR_256K_SIZE,
        .sector_type = SPI_NOR_SECTOR_256KB,
        .read_dummy = 16,
        .write_dummy = 0,
        .page_size = 256,
        .default_init = s26h_default_init,
    },
    {
        .name = "s26ks",
        .flash_id = {0x01, 0x00, 0x7E, 0x00},
        .read_proto = PROTO(0u, SNOR_PROTO_8_8_8_DTR),
        .write_proto = PROTO(0u, SNOR_PROTO_8_8_8_DTR),
        .sector_size = SPINOR_SECTOR_256K_SIZE,
        .sector_type = SPI_NOR_SECTOR_256KB,
        .read_dummy = 16,
        .write_dummy = 0,
        .page_size = 256,
    },
};

#define FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"

static int hyperbus_write_enable(struct spi_nor *nor, boolean enable)
{
    struct hyperbus_ca *ca = hyper_word_program.ca;

    nor->host->hyper_ops->set_pre_transaction(nor, false, false, 3u, &ca);

    return 0;
}

static int spi_nor_get_status(struct spi_nor *nor, uint16 *status)
{
    int ret;
    uint16 reg = 0u;
    struct hyperbus_ca *ca = hyper_read_status.ca;

    nor->host->ops->prepare(nor, SPI_NOR_OPS_LOCK);
    nor->host->hyper_ops->set_pre_transaction(nor, true, false, 1u, &ca);
    ret = nor->host->hyper_ops->read16(nor, 0u, &reg);
    nor->host->ops->unprepare(nor, SPI_NOR_OPS_LOCK);
    *status = reg;
    return ret;
}

static int hyperbus_busy_status(struct spi_nor *nor)
{
    int ret = 0;
    uint16 flash_status;

    ret = spi_nor_get_status(nor, &flash_status);

    if (ret) {
        DBG("spi_nor get flash status failed, ret: %d!\n", ret);
        return ret;
    }

    if (!(flash_status & BIT(7)))
        return -1;

    return ret;
}

static int hyperbus_wait_idle(struct spi_nor *nor)
{
    int ret = 0;
    uint16 flash_status;
    uint32 tick_count = 0;
    uint32 parallel_count = 0;

    while (1) {
        ret = spi_nor_get_status(nor, &flash_status);

        if (ret) {
            if ((nor->dev_mode == SPI_NOR_DEV_PARALLEL_MODE)
                && (parallel_count < 1000000)) {
                parallel_count++;
                Mcu_udelay(1);
                continue;
            } else {
                DBG("hyperbus get flash status failed, ret: %d!\n", ret);
                break;
            }
        }

        if ((flash_status & BIT(7)))
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

static int spi_nor_id_read(struct spi_nor *nor)
{
    int ret = 0;
    uint8 id[8];
    struct flash_info *info;

    struct spi_nor_cmd read_cmd = {
        .opcode = 0x9Fu,
        .dummy = 0,
    };

    read_cmd.dummy = (ID_PROTO(0, SNOR_PROTO_1_1_1) >> SNOR_READID_DUMMY_LSB) & 0xff;
    read_cmd.inst_type = SNOR_INST_LANS(ID_PROTO(0, SNOR_PROTO_1_1_1));

    nor->host->ops->prepare(nor, SPI_NOR_OPS_LOCK);
    ret = nor->host->ops->reg_read(nor, &read_cmd, 0, id, 6);
    nor->host->ops->unprepare(nor, SPI_NOR_OPS_LOCK);

    if (ret) return ret;

    DBG("id0: %x, id1: %x, id2: %x\n", id[0], id[2],
        id[4]);

    for (uint32 i = 0; i < ARRAY_SZ(hyperbus_ids); i++) {
        info = &hyperbus_ids[i];

        if (!mini_memcmp_s(info->flash_id, id, 4)) {
            mini_memcpy_s(&nor->info, info, sizeof(struct flash_info));
            nor->info.size = 1 << id[SPINOR_ID_CAPACITY_OFFSET];
            return 0;
        }
    }

    return -1;
}

static int hyperflash_id_read(struct spi_nor *nor)
{
    int ret = 0;
    /* Hyper bus device ID is uint16 */
    uint16 id[4] = {0};
    struct flash_info *info;
    uint32 aso_exit_data = 0xF0u;
    struct hyperbus_ca *ca = hyper_read_id.ca;
    mini_memcpy_s(&nor->info, &hyperbus_ids[0], sizeof(struct flash_info));

    nor->host->ops->prepare(nor, SPI_NOR_OPS_LOCK);
    nor->host->hyper_ops->set_pre_transaction(nor, true, false, 3u, &ca);
    ret |= nor->host->hyper_ops->read16(nor, 0x800, id);
    ret |= nor->host->hyper_ops->read16(nor, 0x801, id + 1);
    ret |= nor->host->hyper_ops->read16(nor, 0x802, id + 2);
    nor->host->hyper_ops->write16(nor, 0, (uint16 *)(&aso_exit_data));

    nor->host->ops->unprepare(nor, SPI_NOR_OPS_LOCK);

    if (ret)
        return -2;

    DBG("id0: %x, id1: %x, id2: %x\n", id[0], id[1],
        id[2]);

    for (uint32 i = 1; i < ARRAY_SZ(hyperbus_ids); i++) {
        info = &hyperbus_ids[i];

        if (!mini_memcmp_s(info->flash_id, id, 4u)) {
            mini_memcpy_s(&nor->info, info, sizeof(struct flash_info));
            nor->info.size = 1 << id[SPINOR_ID_CAPACITY_OFFSET];
            return 0;
        }
    }

    return -1;
}

static int hyperflash_cfi_id_read(struct spi_nor *nor)
{
    int ret = 0;
    /* Hyper bus device ID is uint16 */
    uint16 id[4] = {0};
    struct flash_info *info;
    // uint16 aso_exit_data = 0xF0u;
    VAR_ALIGN(uint16 aso_exit_data, 4) = 0xF0u;
    struct hyperbus_ca *ca = hyper_read_id.ca;
    mini_memcpy_s(&nor->info, &hyperbus_ids[0], sizeof(struct flash_info));

    nor->host->ops->prepare(nor, SPI_NOR_OPS_LOCK);
    nor->host->hyper_ops->set_pre_transaction(nor, true, false, 3u, &ca);
    ret |= nor->host->hyper_ops->read16(nor, 0x0, id);
    ret |= nor->host->hyper_ops->read16(nor, 0x1, id + 1);
    ret |= nor->host->hyper_ops->read16(nor, 0x27, id + 2);
    nor->host->hyper_ops->write16(nor, 0, &aso_exit_data);

    nor->host->ops->unprepare(nor, SPI_NOR_OPS_LOCK);

    if (ret)
        return -2;

    DBG("id0: %x, id1: %x, id2: %x\n", id[0], id[1],
        id[2]);

    for (uint32 i = 1; i < ARRAY_SZ(hyperbus_ids); i++) {
        info = &hyperbus_ids[i];

        if (!mini_memcmp_s(info->flash_id, id, 4u)) {
            mini_memcpy_s(&nor->info, info, sizeof(struct flash_info));
            nor->info.size = 1 << id[SPINOR_ID_CAPACITY_OFFSET];
            return 0;
        }
    }

    return -1;
}

static int hyperbus_interface_enable(struct spi_nor *nor)
{
    int ret = 0;
    uint8 data[2] = {0};

    struct spi_nor_cmd r_cmd = {
        .opcode = 0x65,
        .addr_bytes = 3,
        .inst_type = 0,
        .dummy = 8,
    };

    nor->host->ops->prepare(nor, SPI_NOR_OPS_LOCK);
    ret = nor->host->ops->reg_read(nor, &r_cmd, 0x4, data, 1);
    nor->host->ops->unprepare(nor, SPI_NOR_OPS_LOCK);

    if (ret) {
        return ret;
    }

    DBG("legacy x1 CFR4N register value 0x%x\n", data[0]);

    struct spi_nor_cmd wr_en_cmd = {
        .opcode = 0x06,
        .addr_bytes = 0,
        .inst_type = 0,
        .dummy = 0,
    };

    nor->host->ops->prepare(nor, SPI_NOR_OPS_LOCK);
    ret = nor->host->ops->reg_write(nor, &wr_en_cmd, 0, 0, 0);
    nor->host->ops->unprepare(nor, SPI_NOR_OPS_LOCK);

    if (ret) {
        return ret;
    }

    struct spi_nor_cmd w_cmd = {
        .opcode = 0x71,
        .addr_bytes = 3,
        .inst_type = 0,
        .dummy = 0,
    };

    data[0] |= BIT(1);

    DBG("enable hyperbus mode\n");

    nor->host->ops->prepare(nor, SPI_NOR_OPS_LOCK);

    ret = nor->host->ops->reg_write(nor, &w_cmd, 0x4, data, 1);

    nor->host->ops->unprepare(nor, SPI_NOR_OPS_LOCK);

    return ret;
}

static int hyperbus_flash_init(struct spi_nor *nor) {
    int ret = 0;

    DBG("hyperbus: try read id by legacy x1 interface\n");

	ret = spi_nor_id_read(nor);
    if (!ret) {
        hyperbus_interface_enable(nor);
    }

    nor->hyperbus_mode = true;
    nor->reg_proto = SNOR_PROTO_8_8_8_DTR;
    nor->addr_width = 4u;
    nor->octal_dtr_en = 1u;
    nor->dqs_en = true;

    DBG("hyperbus: try read id by cfi interface\n");
    ret = hyperflash_cfi_id_read(nor);

    if (ret) {
        DBG("hyperbus: try read id by SFDP interface\n");
        ret = hyperflash_id_read(nor);
    }

    DBG("flash type is hyperflash\n");
    nor->mem_type = SPI_HYPERFLASH;

    return ret;
}

static int hyperbus_ram_init(struct spi_nor *nor) {
    nor->hyperbus_mode = true;
    nor->reg_proto = SNOR_PROTO_8_8_8_DTR;
    nor->addr_width = 4u;
    nor->octal_dtr_en = 1u;
    nor->dqs_en = true;

    mini_memcpy_s(&nor->info, &hyperbus_ids[1], sizeof(struct flash_info));
    nor->mem_type = SPI_HYPERRAM;
    DBG("flash type is hyperam\n");
    /* For hyperram driver not get size info, set 128M */
    nor->info.size = 0x8000000;
    nor->host->hyper_ops->hyperram_en(nor, nor->cs, 5u, 5u);

    return 0;
}

static int hyperbus_init(struct spi_nor *nor, struct spi_nor_host *host,
                 const struct spi_nor_config *config)
{
    int ret = 0;
    uint32 training_len = 32;
    flash_addr_t training_addr;
    Fls_ContextType* pCtx = ((Fls_ContextType*)nor->parent);

    nor->id = config->id;
    nor->baudrate = config->baudrate;
    nor->xfer_mode = config->xfer_mode;
    nor->dev_mode = config->dev_mode;

    nor->host = host;
    nor->sw_rst = config->sw_rst;


    switch (pCtx->ControllerConfig->FlsSpecialFlag) {
    case FLS_SPECIAL_HYPERRAM:
        ret = hyperbus_ram_init(nor);
        break;
    case FLS_SPECIAL_MCP:
        if (nor->cs == 0u) {
            ret = hyperbus_flash_init(nor);
        } else {
            ret = hyperbus_ram_init(nor);
        }
        break;
    case FLS_SPECIAL_AUTO:
    default:
        ret = hyperbus_flash_init(nor);
        if (ret == -1) {
            ret = hyperbus_ram_init(nor);
        }
        break;
    }

    if (ret) {
        return ret;
    }

    if (nor->dev_mode == SPI_NOR_DEV_PARALLEL_MODE) {
        nor->info.sector_size *= 2u;
        if (nor->mem_type != SPI_HYPERRAM) {
            nor->info.size *= 2u;
        }
    }

    DBG("flash size: %llx\n", nor->info.size);

    /* set dummy ... */
    if (nor->info.default_init) {
        nor->info.default_init(nor);
    }

    if (nor->host->ops->training) {
        training_addr = nor->info.sector_size;
        hyperbus_read(nor, training_addr, training_buf, 32);

        if (0u != mini_memcmp_s(training_pattern, training_buf, training_len)) {
            if (nor->mem_type != SPI_HYPERRAM) {
                if (hyperbus_erase(nor, training_addr, nor->info.sector_size)) {
                    return -1;
                }
            }
#ifdef CONFIG_FLS_HAL_POLLING
            /* wait for flash idle */
            ret = hyperbus_wait_idle(nor);
            if (ret)
                return -1;
#endif

            if (hyperbus_write(nor, training_addr, training_pattern, training_len)) {
                return -1;
            }
#ifdef CONFIG_FLS_HAL_POLLING
            /* wait for flash idle */
            ret = hyperbus_wait_idle(nor);
            if (ret)
                return -1;
#endif

        }

        if (nor->host->clk != NULL) {
            clk_set_rate(nor->host->clk, nor->host->ref_clk_hz);
            DBG("spinor host clock rate is %u!\n",
                clk_get_rate(nor->host->clk));
        }

        nor->host->ops->prepare(nor, SPI_NOR_OPS_LOCK);
        ret = nor->host->ops->training(nor, training_addr, training_buf,
                                       training_pattern, training_len);
        nor->host->ops->unprepare(nor, SPI_NOR_OPS_LOCK);
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

static int hyperbus_read(struct spi_nor *nor, flash_addr_t addr, uint8 *buf,
                 flash_size_t size)
{
    int ret;

    nor->host->ops->prepare(nor, SPI_NOR_OPS_READ);
    spi_nor_setup_xfer(nor, FLASH_OPT_READ, addr, buf, size);
    ret = nor->host->hyper_ops->read(nor, addr, buf, size);

    if (ret) {
        spi_nor_xfer_error(nor);
    } else if (!nor->async_mode) {
        spi_nor_xfer_comp(nor);
    }

    return ret;
}

static int hyperbus_write(struct spi_nor *nor, flash_addr_t addr, const uint8 *buf,
                  flash_size_t size)
{
    int ret;

    nor->host->ops->prepare(nor, SPI_NOR_OPS_WRITE);
    spi_nor_setup_xfer(nor, FLASH_OPT_WRITE, addr, (uint8 *)buf, size);
    ret = nor->host->hyper_ops->write(nor, addr, buf, size);

    if (ret) {
        spi_nor_xfer_error(nor);
    } else if (!nor->async_mode) {
        spi_nor_xfer_comp(nor);
    }

    return ret;
}

/* the arguments erase length and dst address must 4K alined */
static int hyperbus_erase(struct spi_nor *nor, flash_addr_t addr, flash_size_t size)
{
    int ret = 0;
    struct hyperbus_ca *ca;
    uint32 erase_cmd_data = 0x30u;
    struct hyperbus_host_ops *hyper_ops = nor->host->hyper_ops;

    nor->host->ops->prepare(nor, SPI_NOR_OPS_ERASE);
    nor->host->ops->cache_flush(nor, addr, size);
    spi_nor_setup_xfer(nor, FLASH_OPT_ERASE, addr, NULL, size);
    nor->xfer_info.size = size;

    if (nor->dev_mode == SPI_NOR_DEV_PARALLEL_MODE) {
        nor->xfer_info.addr = nor->xfer_info.addr / 2u;
    }

    if (!nor->async_mode) {
        while (nor->xfer_info.size) {
            ca = hyper_sector_erase.ca;

            hyper_ops->set_pre_transaction(nor, false, false, 5u, &ca);
            /* erase addr need convert to word addr */
            ret = hyper_ops->write16(nor, (nor->xfer_info.addr - nor->info.reg_offset) / 2u,
                                     (uint16 *)(&erase_cmd_data));

            if (ret)
                break;

#ifndef CONFIG_FLS_HAL_POLLING
            /* wait for flash idle */
            ret = hyperbus_wait_idle(nor);

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

static int hyperbus_cancel(struct spi_nor *nor)
{
    if (nor->host->ops->cancel) {
        return nor->host->ops->cancel(nor);
    } else {
        return 0;
    }
}

static void hyperbus_erase_polling(struct spi_nor *nor)
{
    int ret = 0;
    uint16 flash_status;
    uint32 sector_size = nor->info.sector_size;

    if (nor->xfer_info.size != 0) {
        ret = spi_nor_get_status(nor, &flash_status);

        if (ret) {
            spi_nor_xfer_error(nor);
        } else if (!(flash_status & BIT(0))) {
            ret = hyperbus_erase(nor, nor->xfer_info.addr, sector_size);

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

static void hyperbus_main_function(struct spi_nor *nor)
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
            hyperbus_erase_polling(nor);
        }
    } else {
        if (nor->xfer_info.opt_type) {
            nor->host->ops->unprepare(nor, (enum spi_nor_ops)nor->xfer_info.opt_type);
            nor->xfer_info.opt_type = (enum flash_opt)0;
        }
    }
}

static int s26h_default_init(struct spi_nor *nor)
{
    int ret = 0;
    VAR_ALIGN(uint16 reg, 4) = 0x0u;

    struct hyperbus_ca *ca = hyper_read_vol_reg2.ca;

    nor->host->ops->prepare(nor, SPI_NOR_OPS_LOCK);
    nor->host->hyper_ops->set_pre_transaction(nor, true, false, 3u, &ca);
    ret |= nor->host->hyper_ops->read16(nor, 0u, &reg);
    nor->host->ops->unprepare(nor, SPI_NOR_OPS_LOCK);

#ifdef CONFIG_HYPERBUS_DIFFERENTIAL_CLK_EN
    /* Enable differential clock mode */
    reg &= ~BIT(0);
#endif
#ifdef CONFIG_HYPERBUS_INCREMENTAL_PROGRAM_EN
    /*
     * If 2bit ECC detect enable, program one page two times without erase
     * will result in a program error.
     */
    reg |= BIT(5);
#endif
    ca = hyper_write_vol_reg2.ca;
    nor->host->ops->prepare(nor, SPI_NOR_OPS_LOCK);
    nor->host->hyper_ops->set_pre_transaction(nor, false, false, 3u, &ca);
    ret |= nor->host->hyper_ops->write16(nor, 0u, &reg);
    nor->host->ops->unprepare(nor, SPI_NOR_OPS_LOCK);

    ca = hyper_read_vol_reg2.ca;
    nor->host->ops->prepare(nor, SPI_NOR_OPS_LOCK);
    nor->host->hyper_ops->set_pre_transaction(nor, true, false, 3u, &ca);
    ret |= nor->host->hyper_ops->read16(nor, 0u, &reg);
    nor->host->ops->unprepare(nor, SPI_NOR_OPS_LOCK);
    DBG("cypress vol regster2 0x%x\n", reg);

    return ret;
}

static void hyperbus_deinit(struct spi_nor *nor)
{
    return;
}

#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#ifdef __cplusplus
}
#endif
