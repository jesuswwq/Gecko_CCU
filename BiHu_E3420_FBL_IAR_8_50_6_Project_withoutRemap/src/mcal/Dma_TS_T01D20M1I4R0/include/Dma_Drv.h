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
 * @file  dma.h
 * @brief Semidrive. Dma
 */

#ifndef __DMA_DRV_H__
#define __DMA_DRV_H__

#ifdef __cplusplus
extern "C" {
#endif


#include <__list.h>
#include "debug.h"
#include "Mcu.h"

#define CONFIG_ARCH_CACHE_LINE 32
/**
 * @brief dma status.
 */
typedef enum dma_status {
    DMA_COMPLETED = 0,
    DMA_IN_PROGRESS,
    DMA_PAUSED,
    DMA_ERR,
    DMA_PENDING,
    DMA_MAD_CRC_ERROR,
} dma_status_e;

/**
 * @brief dma transfer direction.
 */
typedef enum dma_tr_direction {
    DMA_MEM2MEM = 0,
    DMA_MEM2DEV,
    DMA_DEV2MEM,
    DMA_DEV2DEV,
} dma_tr_direction_e;

typedef enum {
    DMA_NO_MAD_CRC = 0,     /**< DMA channel disable mad crc */
    DMA_CHECK_CURR_MAD = 1, /**< DMA channel enable mad crc */
} dma_crc_mode_e;

/**
 * @brief dma transaction type.
 */
typedef enum dma_transaction_type {
    DMA_MEMCPY = 0,
    DMA_MEMSET = 1,
    DMA_DEVICE = 2,
    DMA_CYCLIC = 3,
    DMA_TYPE_END,
} dma_transaction_type_e;

/**
 * @brief dma transfer bus width.
 */
typedef enum dma_dev_bus_width {
    DMA_DEV_BUSWIDTH_UNDEFINED = 0,
    DMA_DEV_BUSWIDTH_1_BYTE = 1,
    DMA_DEV_BUSWIDTH_2_BYTES = 2,
    DMA_DEV_BUSWIDTH_4_BYTES = 4,
    DMA_DEV_BUSWIDTH_8_BYTES = 8,
    DMA_DEV_BUSWIDTH_16_BYTES = 16,
    DMA_DEV_BUSWIDTH_32_BYTES = 32,
    DMA_DEV_BUSWIDTH_64_BYTES = 64,
} dma_dev_bus_width_e;

/**
 * @brief dma transfer flag(enable or disable interrupt).
 */
typedef enum dma_ctrl_flags {
    DMA_INTERRUPT = (1 << 0),
    DMA_PENDING_TIMEOUT = (1 << 1),
} dma_ctrl_flags_t;

/**
 * @brief abstract dma channel for common driver.
 */
typedef struct dma_dev dma_dev_t;
typedef void (*dma_irq_handle)(uint32 status, uint32 param, void *context);

typedef struct dma_chan {
    struct list_node node;
    dma_dev_t *device;
    uint8 priority;
    uint32 chan_id;
    uint16 allocated;
    dma_status_e chan_status;
    dma_ctrl_flags_t flags;
    dma_irq_handle irq_cb;
    uint32 irq_id;
    void *context;
} dma_chan_t;

/**
 * @brief dma transfer config (dev2mem/mem2dev).
 */
typedef struct dma_dev_cfg {
    dma_tr_direction_e direction;
    addr_t src_addr;
    addr_t dst_addr;
    dma_dev_bus_width_e src_addr_width;
    dma_dev_bus_width_e dst_addr_width;
    /* Maximum number of words (in units of the dma_dev_bus_width_e, not bytes)
     * sent in one DMA req.
     */
    uint32 src_maxburst;
    uint32 dst_maxburst;
    bool custom_muxid_flag;
    sint32 custom_muxid;
    dma_crc_mode_e mad_crc_mode;
} dma_dev_cfg_t;

/**
 * @brief abstract dma ops.
 */
typedef struct dma_ops {
    /* init the controller. */
    int (*init)(dma_dev_t *dev);
    /* request transfer chan with/without specific channel. */
    dma_chan_t *(*request_chan)(dma_dev_t *dev, uint32 *id);
    /* free requested chan. */
    void (*release_chan)(dma_chan_t *chan);
    /* get memcpy dma transfer config. */
    bool (*prep_memcpy)(dma_chan_t *chan, void *dst, void *src, uint32 buf_len,
                        uint32 flags);
    /* get memset dma transfer config. */
    bool (*prep_memset)(dma_chan_t *chan, uint8 val, void *buf_addr,
                        uint32 buf_len, uint32 flags);
    /* get mem2dev/dev2mem dma transfer config. */
    bool (*prep_dev)(dma_chan_t *chan, void *buf_addr, uint32 buf_len,
                     uint32 flags);
    /* get mem2dev/dev2mem loop dma transfer config. */
    bool (*prep_cyclic)(dma_chan_t *chan, void *buf_addr, uint32 buf_len,
                        uint32 period_len, uint32 flags);
    /* set dma transfer config. */
    void (*config_chan)(dma_chan_t *chan, dma_dev_cfg_t *cfg);
    /* enable dma ch. */
    void (*enable_chan)(dma_chan_t *chan);
    /* disable dma ch. */
    bool (*disable_chan)(dma_chan_t *chan);
    /* get transfer status. */
    dma_status_e (*get_ch_status)(dma_chan_t *chan);
    /* deint control. */
    void (*deinit)(dma_dev_t *dev);
} dma_ops_t;

/**
 * @brief abstract dma control device.
 */
struct dma_dev {
    paddr_t dma_base;
    paddr_t mux_base;
    uint32 irq_id;
    uint8 priority;
    struct list_node channels;
    uint32 channel_nr;
    dma_ops_t *ops;
    void *priv;
};

extern __attribute__((__aligned__(CONFIG_ARCH_CACHE_LINE))) dma_dev_t dma_sf0[CPU_ID_MAX];
#if (STD_OFF == DMA_LOCK_STEP_MODE)
extern __attribute__((__aligned__(CONFIG_ARCH_CACHE_LINE))) dma_dev_t dma_sf1[CPU_ID_MAX];
#endif /* #if (STD_OFF == DMA_LOCK_STEP_MODE) */
#ifndef SEMIDRIVE_E3_LITE_SERIES
extern __attribute__((__aligned__(CONFIG_ARCH_CACHE_LINE))) dma_dev_t dma_ap0[CPU_ID_MAX];
#endif /* #ifndef SEMIDRIVE_E3_LITE_SERIES */
/**
 * @brief init dma control
 *
 * @param[in] dev dma control instance,for details, see dma_dev_t
 * @return 0 if OK, or a negative error code.
 */
int dma_init(dma_dev_t *dev);

/**
 * @brief request channel random
 *
 * @param[in] dev dma control instance,for details,see dma_dev_t
 * @return channel info
 */
dma_chan_t *dma_req_chan(dma_dev_t *dev);

/**
 * @brief request channel by id
 *
 * @param[in] dev dma control instance,for details,see dma_dev_t
 * @param[in] id request specified channel
 * @return channel info
 */
dma_chan_t *dma_req_chan_with_id(dma_dev_t *dev, uint32 id);

/**
 * @brief free channel
 *
 * @param[in] chan requested channel info
 */
void dma_free_chan(dma_chan_t *chan);

/**
 * @brief dma device config (only for dev2mem or mem2dev)
 *
 * @param[in] chan requested channel info
 * @param[in] cfg  devcie config,for details, see dma_dev_cfg_t
 */
void dma_config_chan(dma_chan_t *chan, dma_dev_cfg_t *cfg);

/**
 * @brief get mem2mem copy config
 *
 * @param[in] chan requested channel info
 * @param[in] dst  dst address
 * @param[in] src  src address
 * @param[in] buf_len transfer length
 * @param[in] flags enable or disable interrupt,see dma_ctrl_flags_t
 * @return true/false
 */
bool dma_prep_memcpy(dma_chan_t *chan, void *dst, void *src, uint32 buf_len,
                     uint32 flags);

/**
 * @brief get mem2mem set config
 *
 * @param[in] chan requested channel info
 * @param[in] val  set value
 * @param[in] buf_addr  dst address
 * @param[in] buf_len transfer length
 * @param[in] flags enable or disable interrupt,see dma_ctrl_flags_t
 * @return true/false
 */
bool dma_prep_memset(dma_chan_t *chan, uint8 val, void *buf_addr,
                     uint32 buf_len, uint32 flags);

/**
 * @brief get mem2dev or dev2mem transfer config
 *
 * @param[in] chan requested channel info
 * @param[in] buf_addr  dst address or src address (with dma_dev_config api)
 * @param[in] buf_len transfer length
 * @param[in] flags enable or disable interrupt,see dma_ctrl_flags_t
 * @return true/false
 */
bool dma_prep_dev(dma_chan_t *chan, void *buf_addr, uint32 buf_len,
                  uint32 flags);

/**
 * @brief get mem2dev or dev2mem transfer config (loop)
 *
 * @param[in] chan requested channel info
 * @param[in] buf_addr  dst address or src address (with dma_dev_config api)
 * @param[in] buf_len transfer length
 * @param[in] period_len package data length in a time
 * @param[in] flags enable or disable interrupt,see dma_ctrl_flags_t
 * @return true/false
 */
bool dma_prep_cyclic(dma_chan_t *chan, void *buf_addr, uint32 buf_len,
                     uint32 period_len, uint32 flags);

/**
 * @brief start transfer
 *
 * @param[in] chan requested channel info
 */
void dma_start(dma_chan_t *chan);

/**
 * @brief terminate transfer
 *
 * @param[in] chan requested channel info
 * @return true/false
 */
bool dma_stop(dma_chan_t *chan);

/**
 * @brief get transfer status
 *
 * @param[in] chan arequested channel info
 * @return dma_status_e (completed in_progress err paused)
 */
dma_status_e dma_get_chan_status(dma_chan_t *chan);

/**
 * @brief flush cache for prevent data inconsistency
 *
 * @param[in] dma_addr buffer address
 * @param[in] size  buffer length
 */
void dma_flush_cache(addr_t dma_addr, uint32 size);

/**
 * @brief flush invalidate for prevent data inconsistency
 *
 * @param[in] dma_addr  buffer address
 * @param[in] size  buffer length
 */
void dma_invalidate_cache(addr_t dma_addr, uint32 size);

#endif

#ifdef __cplusplus
}
#endif
