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
* @file  spi_nor.h
* @brief Semidrive. AUTOSAR 4.3.1 MCAL Fls plugins.
*/

#ifndef SPI_NOR_H
#define SPI_NOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <RegHelper.h>
#include "Std_Types.h"
#include "flash.h"
#include "e3_clk.h"

#define CONFIG_HYPERBUS_INCREMENTAL_PROGRAM_EN

#define SNOR_READID_DUMMY_LSB (24u)
#define SNOR_OPCODE_PROTO_LSB (24u)
#define SNOR_DTR_PROTO       BIT(16)

#define SNOR_INST_LANS_PROTO_LSB  (8u)
#define SNOR_INST_LANS_PROTO_MASK (0xFu)
#define SNOR_INST_SINGLE_LANS     (0u << SNOR_INST_LANS_PROTO_LSB)
#define SNOR_INST_DUAL_LANS       (1u << SNOR_INST_LANS_PROTO_LSB)
#define SNOR_INST_QUAD_LANS       (2u << SNOR_INST_LANS_PROTO_LSB)
#define SNOR_INST_OCTAL_LANS      (3u << SNOR_INST_LANS_PROTO_LSB)
#define SNOR_INST_LANS(x)         (((x) >> SNOR_INST_LANS_PROTO_LSB) & \
                                        (SNOR_INST_LANS_PROTO_MASK))

#define SNOR_ADDR_LANS_PROTO_LSB  (4u)
#define SNOR_ADDR_LANS_PROTO_MASK (0xFu)
#define SNOR_ADDR_SINGLE_LANS     (0u << SNOR_ADDR_LANS_PROTO_LSB)
#define SNOR_ADDR_DUAL_LANS       (1u << SNOR_ADDR_LANS_PROTO_LSB)
#define SNOR_ADDR_QUAD_LANS       (2u << SNOR_ADDR_LANS_PROTO_LSB)
#define SNOR_ADDR_OCTAL_LANS      (3u << SNOR_ADDR_LANS_PROTO_LSB)
#define SNOR_ADDR_LANS(x)         (((x) >> SNOR_ADDR_LANS_PROTO_LSB) & \
                                        (SNOR_ADDR_LANS_PROTO_MASK))


#define SNOR_DATA_LANS_PROTO_LSB  (0u)
#define SNOR_DATA_LANS_PROTO_MASK (0xFu)
#define SNOR_DATA_SINGLE_LANS     (0u << SNOR_DATA_LANS_PROTO_LSB)
#define SNOR_DATA_DUAL_LANS       (1u << SNOR_DATA_LANS_PROTO_LSB)
#define SNOR_DATA_QUAD_LANS       (2u << SNOR_DATA_LANS_PROTO_LSB)
#define SNOR_DATA_OCTAL_LANS      (3u << SNOR_DATA_LANS_PROTO_LSB)
#define SNOR_DATA_LANS(x)         (((x) >> SNOR_DATA_LANS_PROTO_LSB) & \
                                        (SNOR_DATA_LANS_PROTO_MASK))


#define SNOR_PROTO_1_1_1                                                       \
    (SNOR_INST_SINGLE_LANS | SNOR_ADDR_SINGLE_LANS | SNOR_DATA_SINGLE_LANS)
#define SNOR_PROTO_1_1_2                                                       \
    (SNOR_INST_SINGLE_LANS | SNOR_ADDR_SINGLE_LANS | SNOR_DATA_DUAL_LANS)
#define SNOR_PROTO_1_1_4                                                       \
    (SNOR_INST_SINGLE_LANS | SNOR_ADDR_SINGLE_LANS | SNOR_DATA_QUAD_LANS)
#define SNOR_PROTO_1_1_8                                                       \
    (SNOR_INST_SINGLE_LANS | SNOR_ADDR_SINGLE_LANS | SNOR_DATA_OCTAL_LANS)
#define SNOR_PROTO_1_2_2                                                       \
    (SNOR_INST_SINGLE_LANS | SNOR_ADDR_DUAL_LANS | SNOR_DATA_DUAL_LANS)
#define SNOR_PROTO_1_4_4                                                       \
    (SNOR_INST_SINGLE_LANS | SNOR_ADDR_QUAD_LANS | SNOR_DATA_QUAD_LANS)
#define SNOR_PROTO_1_8_8                                                       \
    (SNOR_INST_SINGLE_LANS | SNOR_ADDR_OCTAL_LANS | SNOR_DATA_OCTAL_LANS)
#define SNOR_PROTO_2_2_2                                                       \
    (SNOR_INST_DUAL_LANS | SNOR_ADDR_DUAL_LANS | SNOR_DATA_DUAL_LANS)
#define SNOR_PROTO_4_4_4                                                       \
    (SNOR_INST_QUAD_LANS | SNOR_ADDR_QUAD_LANS | SNOR_DATA_QUAD_LANS)
#define SNOR_PROTO_8_8_8                                                       \
    (SNOR_INST_OCTAL_LANS | SNOR_ADDR_OCTAL_LANS | SNOR_DATA_OCTAL_LANS)
#define SNOR_PROTO_1_1_1_DTR (SNOR_PROTO_1_1_1 | SNOR_DTR_PROTO)
#define SNOR_PROTO_1_2_2_DTR (SNOR_PROTO_1_2_2 | SNOR_DTR_PROTO)
#define SNOR_PROTO_1_4_4_DTR (SNOR_PROTO_1_4_4 | SNOR_DTR_PROTO)
#define SNOR_PROTO_4_4_4_DTR (SNOR_PROTO_4_4_4 | SNOR_DTR_PROTO)
#define SNOR_PROTO_1_1_8_DTR (SNOR_PROTO_1_1_8 | SNOR_DTR_PROTO)
#define SNOR_PROTO_1_8_8_DTR (SNOR_PROTO_1_8_8 | SNOR_DTR_PROTO)
#define SNOR_PROTO_8_8_8_DTR (SNOR_PROTO_8_8_8 | SNOR_DTR_PROTO)

#define SNOR_PROTO_DTR_MASK 0x1ffffu
#define SNOR_PROTO_MASK     0xffffu
#define SNOR_PROTO_DTR(x) ((x) & SNOR_PROTO_DTR_MASK)
#define SNOR_PROTO(x) ((x) & SNOR_PROTO_MASK)

#define SPINOR_SECTOR_4K_SIZE (0x1000)
#define SPINOR_SECTOR_32K_SIZE (0x8000)
#define SPINOR_SECTOR_64K_SIZE (0x10000)
#define SPINOR_SECTOR_128K_SIZE (0x20000)
#define SPINOR_SECTOR_256K_SIZE (0x40000)

typedef enum {
    SPI_NOR_SECTOR_4KB = 0,
    SPI_NOR_SECTOR_32KB,
    SPI_NOR_SECTOR_64KB,
    SPI_NOR_SECTOR_128KB,
    SPI_NOR_SECTOR_256KB,
    SPI_NOR_SECTOR_TYPE_MAX,
} spi_nor_sector_type;
#define SECTOR_POST_TO_SIZE(n) (1 << (n))
#define SECTOR_TYPE_TO_POST(type) (12 + (2 * (!!(type))) + (type))
#define SECTOR_TYPE_TO_SIZE(type) SECTOR_POST_TO_SIZE(SECTOR_TYPE_TO_POST(type))

struct spi_nor;

typedef enum {
    FLS_XSPI1_PORTA = 0,
    FLS_XSPI1_PORTB,
    FLS_XSPI2_PORTA,
    FLS_XSPI2_PORTB,
    FLS_CONTROLLER_ID_MAX,
} Fls_Controller_ID_t;

enum spi_nor_xfer_mode {
    SPI_NOR_XFER_POLLING_MODE = 0,
    SPI_NOR_XFER_INTERRUPT_MODE,
    SPI_NOR_XFER_DMA_MODE,
};

enum spi_nor_device_mode {
    SPI_NOR_DEV_SINGLE_MODE = 0,
    SPI_NOR_DEV_LOCKSTEP_MODE,
    SPI_NOR_DEV_PARALLEL_MODE,
    SPI_NOR_DEV_SWITCH_MODE,
};

#define SPI_NOR_MAX_ID_LEN 6

enum spi_nor_proto_type {
    SPI_NOR_PROTO_TYPE_READ = 0,
    SPI_NOR_PROTO_TYPE_WRITE,
    SPI_NOR_PROTO_TYPE_ERASE,
};

enum spi_memory_type {
    SPI_NOR_FLASH = 0,
    SPI_NAND_FLASH,
    SPI_HYPERFLASH,
    SPI_HYPERRAM,
    SPI_HYPERBUS_MCP,
};

struct spi_nor_cmd {
    uint8 opcode;
    uint8 inst_type;
    uint8 dummy;
    uint8 addr_bytes; /* 0 bytes(no need addr) 3 bytes or 4 bytes */
};

struct hyperbus_ca {
    uint16 addr;
    uint16 data;
};

#define HYPERFLSAH_CMD_MAX_NUM (6)
struct hyperflash_cmd {
    char *name;
    boolean is_read;
    uint32 num;
    struct hyperbus_ca ca[HYPERFLSAH_CMD_MAX_NUM];
};

enum spi_nor_ops {
    SPI_NOR_OPS_READ = 1,
    SPI_NOR_OPS_WRITE,
    SPI_NOR_OPS_ERASE,
    SPI_NOR_OPS_LOCK,
    SPI_NOR_OPS_UNLOCK,
};

struct spi_nor_config {
    uint8 id;
    uint8 cs;
    uint32 baudrate;
    enum spi_nor_xfer_mode xfer_mode;
    enum spi_nor_device_mode dev_mode;
    boolean async_mode;        /* Always false!! */
    boolean hyperbus_mode;
    boolean sw_rst;
};

struct flash_info {
    const char *name;
    uint8 flash_id[SPI_NOR_MAX_ID_LEN];

    uint32 read_proto;
    uint32 write_proto;
    uint32 erase_proto[SPI_NOR_SECTOR_TYPE_MAX];

    uint8 read_dummy;
    uint8 write_dummy;
    uint8 status_dummy;

    uint32 sector_size;
    uint16 page_size;
    spi_nor_sector_type sector_type;

    uint64 size;
    uint64 reg_offset;

    int (*default_init)(struct spi_nor *nor);
    int (*octal_dtr_enable)(struct spi_nor *nor, boolean enable);
    int (*quad_enable)(struct spi_nor *nor, boolean enable);
    int (*enter_quad)(struct spi_nor *nor, boolean enable);
    int (*set_4byte_addr_mode)(struct spi_nor *nor, boolean enable);
};

struct spi_nor_host_ops {
    int (*prepare)(struct spi_nor *flash_handle, enum spi_nor_ops ops);
    void (*unprepare)(struct spi_nor *flash_handle, enum spi_nor_ops ops);
    int (*reg_read)(struct spi_nor *flash_handle, struct spi_nor_cmd *cmd,
                    flash_addr_t addr, uint8 *buf, uint64 length);
    int (*reg_write)(struct spi_nor *flash_handle, struct spi_nor_cmd *cmd,
                     flash_addr_t addr, const uint8 *buf,
                     uint64 length);
    int (*read)(struct spi_nor *flash_handle, flash_addr_t addr, uint8 *buf,
                uint64 length);
    int (*write)(struct spi_nor *flash_handle, flash_addr_t addr,
                 const uint8 *buf, uint64 length);
    int (*erase)(struct spi_nor *flash_handle, flash_addr_t offset);
    int (*training)(struct spi_nor *flash_handle, flash_addr_t addr,
                    uint8 *buf, const uint8 *pattern, uint64 length);
    int (*cancel)(struct spi_nor *flash_handle);
    void (*cache_flush)(struct spi_nor *flash_handle, flash_addr_t addr,
                        flash_size_t length);
};

struct hyperbus_host_ops {
    int (*read16)(struct spi_nor *flash_handle, flash_addr_t addr, uint16 *buf);
    int (*write16)(struct spi_nor *flash_handle, flash_addr_t addr, uint16 *buf);
    void (*set_pre_transaction)(struct spi_nor *flash_handle, boolean is_read,
                                boolean is_direct, uint32 num, struct hyperbus_ca **ca_array);
    void (*hyperram_en)(struct spi_nor *flash_handle, uint8 cs,
                        uint8 read_dummy, uint8 write_dummy);
    int (*read)(struct spi_nor *flash_handle, flash_addr_t addr, uint8 *buf,
                uint64 length);
    int (*write)(struct spi_nor *flash_handle, flash_addr_t addr,
                 const uint8 *buf, uint64 length);
    void (*cache_flush)(struct spi_nor *flash_handle, flash_addr_t addr,
                        flash_size_t length);
};

struct spi_nor_host {
    uint8 id;
    addr_t base;
    unsigned int irq;
    clk_node_t *clk;
    unsigned long ref_clk_hz;

    struct spi_nor_host_ops *ops;
    struct hyperbus_host_ops *hyper_ops;

    struct spi_nor *dev;
    void *priv_data;
};

struct spi_nor {
    uint8 id;
    uint8 cs;
    uint32 baudrate;

    enum spi_memory_type mem_type;
    enum spi_nor_device_mode dev_mode;
    struct flash_info info;

    boolean phy_en;
    boolean dqs_en;
    boolean octal_dtr_en;
    boolean async_mode;               /* Always false!! */
    boolean hyperbus_mode;
    boolean sw_rst;

    uint32 reg_proto;

    uint8 addr_width;

    enum spi_nor_xfer_mode xfer_mode;
    struct flash_xfer_info xfer_info;
    struct flash_xfer_info xfer_info_bottom;
    flash_notification event_handler;

    struct spi_nor_host *host;
    void    *ops;
    void *parent;
};

typedef struct {
    int (*fls_wait_idle)(struct spi_nor *nor);
    int (*fls_write_enable)(struct spi_nor *nor, boolean enable);
    int (*fls_init)(struct spi_nor *nor, struct spi_nor_host *host,
                    const struct spi_nor_config *flash_config);
    void (*fls_deinit)(struct spi_nor *nor);
    int (*fls_read)(struct spi_nor *nor, flash_addr_t addr, uint8 *buf,
                    uint64 size);
    int (*fls_write)(struct spi_nor *nor, flash_addr_t addr,
                    const uint8 *buf, uint64 size);
    int (*fls_erase)(struct spi_nor *nor, flash_addr_t addr,
                    uint64 size);
    int (*fls_busy_status)(struct spi_nor *nor);
    int (*fls_cancel)(struct spi_nor *nor);
    void (*fls_main_function)(struct spi_nor *nor);
    void (*fls_setup_handler)(struct spi_nor *nor, flash_notification handler);
    enum flash_opt_result (*fls_get_result)(struct spi_nor *nor);
    struct flash_info* (*fls_get_info)(struct spi_nor *nor);
} Fls_OpsType;
extern Fls_OpsType spi_nor_ops;
extern Fls_OpsType hyperbus_ops;

static inline int spi_nor_wait_idle(struct spi_nor *nor) {
    return ((Fls_OpsType*)(nor->ops))->fls_wait_idle(nor);
}

static inline int spi_nor_write_enable(struct spi_nor *nor, boolean enable) {
    return ((Fls_OpsType*)(nor->ops))->fls_write_enable(nor, enable);
}

/**
  * @brief spi norflash host initialize function.
  * @details This function used for before any other spi nor APIs.
  * @param[in] host_config spi norflash host config data, will not used after function return, so this param can be in stack.
  * @return void* The host platform data.
  * @retval Null: failed
  * @retval other: sucess.
  */
//void *spi_nor_host_init(const struct spi_nor_host_config *host_config);

/**
 * @brief spi norflash instance initialization interface.
 * @details This function must used after spi_nor_host_init and before other APIs.
 * @param[in, out] flash_handle spi norflash instance contex handle, the data memory need alloc by user.
 * @param[in] flash_config spi norflash device config data, will not used after function return, so this param can be in stack.
 * @return int
 * @retval 0: sucess
 * @retval other: failed
 */
static inline int spi_nor_init(struct spi_nor *flash_handle, struct spi_nor_host *host,
                 const struct spi_nor_config *flash_config) {
    if (flash_handle && flash_handle->ops) {
        return ((Fls_OpsType*)(flash_handle->ops))->fls_init(flash_handle, host, flash_config);
    } else if (flash_config->hyperbus_mode) {
        return hyperbus_ops.fls_init(flash_handle, host, flash_config);
    } else {
        return spi_nor_ops.fls_init(flash_handle, host, flash_config);
    }
}

/**
 * @brief spi norflash instance destruction interface.
 * @param[in] flash_handle spi norflash instance contex handle.
 */
static inline void spi_nor_deinit(struct spi_nor *flash_handle) {
    ((Fls_OpsType*)(flash_handle->ops))->fls_deinit(flash_handle);
}

/**
 * @brief spi norflash read interface.
 * @details When the buffer and read size aligned with cacheline size will provide best performance.
 * @param[in] flash_handle spi norflash instance contex handle.
 * @param[in] addr spi norflash addr.
 * @param[in] buf Read buffer, alloc by user.
 * @param[in] size Read size, need aligned with 4bytes for dma limit.
 * @return int
 * @retval 0: sucess
 * @retval other: failed
 */
static inline int spi_nor_read(struct spi_nor *flash_handle, flash_addr_t addr, uint8 *buf,
                 uint64 size) {
    return ((Fls_OpsType*)(flash_handle->ops))->fls_read(flash_handle, addr, buf, size);
}

/**
 * @brief spi norflash write interface.
 * @details When the buffer and write size aligned with cacheline size will provide best performance.
 * @param[in] flash_handle spi norflash instance contex handle.
 * @param[in] addr spi norflash addr.
 * @param[in] buf Write buffer, alloc by user.
 * @param[in] size Read size, need aligned with 4bytes for dma limit.
 * @return int
 * @retval 0: sucess
 * @retval other: failed
 */
static inline int spi_nor_write(struct spi_nor *flash_handle, flash_addr_t addr,
                  const uint8 *buf, uint64 size) {
    return ((Fls_OpsType*)(flash_handle->ops))->fls_write(flash_handle, addr, buf, size);
}
/**
 * @brief spi norflash erase interface.
 * @param[in] flash_handle spi norflash instance contex handle.
 * @param[in] addr spi norflash addr.
 * @param[in] size Erase size, need aligned with sector_size what get by spi_nor_get_info API.
 * @return int
 * @retval 0: sucess
 * @retval other: failed
 */
static inline int spi_nor_erase(struct spi_nor *flash_handle, flash_addr_t addr,
                  uint64 size) {
    return ((Fls_OpsType*)(flash_handle->ops))->fls_erase(flash_handle, addr, size);
}


/**
 * @brief spi norflash get flash status interface.
 * @param[in] flash_handle spi norflash instance contex handle.
 * @return int
 * @retval 0: flash is idle
 * @retval other: flash is busy
 */
static inline int spi_nor_busy_status(struct spi_nor *flash_handle) {
    return ((Fls_OpsType*)(flash_handle->ops))->fls_busy_status(flash_handle);
}

/**
 * @brief spi norflash async cancel interface.
 * @details Used for cancel the last tansfer what like read write or erase.
 * @param[in] flash_handle spi norflash instance contex handle.
 * @return int
 * @retval 0: sucess
 * @retval other: failed
 */
static inline int spi_nor_cancel(struct spi_nor *flash_handle) {
    return ((Fls_OpsType*)(flash_handle->ops))->fls_cancel(flash_handle);
}

/**
 * @brief spi norflash async main function interface.
 * @details When use async mode, this function need be called cyclically.
 * @param[in] flash_handle spi norflash instance contex handle.
 */
static inline void spi_nor_main_function(struct spi_nor *flash_handle) {
    ((Fls_OpsType*)(flash_handle->ops))->fls_main_function(flash_handle);
}

/**
 * @brief Used for setup spi norflash async mode notification handler.
 * @details When use async mode, user can selet passive notification mode or active query mode.
 * @param[in] flash_handle spi norflash instance contex handle.
 * @param[in] handler flash notification handler.
 */
static inline void spi_nor_setup_handler(struct spi_nor *flash_handle,
                                  flash_notification handler) {
    flash_handle->event_handler = handler;
    return;
}

/**
 * @brief Used for get spi norflash async tansfer result.
 * @param[in] flash_handle spi norflash instance contex handle.
 * @return enum flash_opt_result
 * @retval FLASH_OPT_COMPLETE: last transfer sucess
 * @retval FLASH_OPT_FAILED: last tansfer failed
 * @retval FLASH_OPT_PENDING: last tansfer not complete
 * @retval FLASH_OPT_INCONSISTENT: last tansfer data error
 * @retval FLASH_OPT_INVALID: last tansfer invalid
 */
static inline enum flash_opt_result spi_nor_get_result(struct spi_nor *flash_handle) {
    if (flash_handle) {
        return flash_handle->xfer_info.opt_result;
    } else {
        return FLASH_OPT_INVALID;
    }
}

/**
 * @brief Used for get spi norflash info what like sector size, page size, and ect.
 * @param[in] flash_handle spi norflash instance contex handle.
 * @return struct flash_info* Norflash info data.
 */
static inline struct flash_info *spi_nor_get_info(struct spi_nor *flash_handle) {
    if (flash_handle) {
        return &flash_handle->info;
    } else {
        return NULL_PTR;
    }
}

#ifdef __cplusplus
}
#endif
#endif
