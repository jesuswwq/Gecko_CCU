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
 * @file  mld_spi.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Spi plugins.
 */

#ifndef MLD_SPI_H_
#define MLD_SPI_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "debug.h"
#include "Compiler.h"

#ifdef SPI_DEBUG_LOG
#define SPI_DBG  PRINT
#else
#define SPI_DBG(...)
#endif

enum spi_tim_mode {
    MODE0 = 0,
    MODE1,
    MODE2,
    MODE3
};
enum spi_mode {
    MASTER = 0,
    SLAVE
};

enum spi_com_mode {
    FULL_DUPLEX = 0,
    HALF_DUPLEX,
    RX_ONLY,
    TX_ONLY
};

enum spi_ssp_mode {
    MOTOROLA = 0,
    TI
};

enum spi_nss_sel {
    NSS_0 = 0,
    NSS_1,
    NSS_2,
    NSS_3,
    NSS_IO
};

enum spi_state {
    SPI_STATE_UNINIT = 0x0,
    SPI_STATE_INITED = 0x1,
    SPI_STATE_BUSY_TX = 0x02,
    SPI_STATE_BUSY_RX = 0x04,
    SPI_STATE_IRQ_ACT = 0x08,
    SPI_STATE_DMA_TX = 0x10,
    SPI_STATE_DMA_RX = 0x20,
    SPI_STATE_IRQ_TX = 0x40,
    SPI_STATE_IRQ_RX = 0x80,
    SPI_STATE_IS_SLAVE = 0x100,
    SPI_STATE_IS_UNS_EN = 0x200,
    SPI_STATE_ERR_END = 0x400,
    SPI_STATE_CS_ACTIVEED = 0x800,
    SPI_STATE_CS_INVLD_EN = 0x1000,
    SPI_STATE_EN_VLD_CS = 0x2000,
};

enum ret_err {
    ERR_NONE = 0,
    ERR_NO_INIT = 1,
    ERR_API_OPS,
    ERR_NO_BUS,
    ERR_LOW_LEVEL,
    ERR_BUSY,
};

enum spi_dir {
    SPI_DIR_RX = 0,
    SPI_DIR_TX = 1,
};

enum spi_ops_mode {
    OP_MODE_NORMAL = 0,
    OP_MODE_IRQ,
    OP_MODE_DMA,
};

enum fifo_state {
    SPI_RX_FIFO_READ =  (0x01 << 0U),
    SPI_TX_FIFO_WRITE = (0x01 << 1U),
    SPI_TX_FIFO_UDR = (0x01 << 2U),
    SPI_RX_FIFO_OVR = (0x01 << 3U),
    SPI_TX_DMA_ERR = (0x01 << 4U),
    SPI_RX_DMA_ERR = (0x01 << 5U),
};

enum fifo_width {
    SPI_DATA_WIDTH_BYTE = 0,
    SPI_DATA_WIDTH_HALF_WORD,
    SPI_DATA_WIDTH_WORD
};
enum irq_type {
    SPI_TRASPORT_FINISH = 0x01 << 0,
    SPI_RX_READ_REQ = 0x01 << 1,
    SPI_TX_WRITE_REQ = 0x01 << 2,
    SPI_CS_INVLD_REQ = 0x01 << 3,
};
#define BUS_BUSY_MASK   (SPI_STATE_BUSY_TX|SPI_STATE_BUSY_RX)
#define BUS_BUSY_DMA_MASK   (SPI_STATE_DMA_TX|SPI_STATE_DMA_RX)
#define BUS_BUSY_IRQ_MASK   (SPI_STATE_IRQ_TX|SPI_STATE_IRQ_RX)
#define BUS_FIFO_STATE_MASK (SPI_RX_FIFO_READ|SPI_TX_FIFO_WRITE|SPI_TX_FIFO_UDR|SPI_RX_FIFO_OVR)
#define BUS_FIFO_STATE_ERR_MASK (SPI_TX_FIFO_UDR|SPI_RX_FIFO_OVR|SPI_TX_DMA_ERR|SPI_RX_DMA_ERR)
#define BUS_BUSY_ASYNC_MASK    (BUS_BUSY_DMA_MASK|BUS_BUSY_IRQ_MASK)
#define BUS_BUSY_STATUS_MASK    (BUS_BUSY_MASK|BUS_BUSY_ASYNC_MASK)
#define BLOCK_TIMEOUT_MAX    (0U)
#define TIMEOUT_SYNC_ONE_ITEM   (1000)
#define TIMEOUT_WAIT_FIFO_EMPTY   (TIMEOUT_SYNC_ONE_ITEM*32)

#define SPI_STATE_EXT_FLAGS     (SPI_STATE_IS_UNS_EN | SPI_STATE_CS_ACTIVEED |\
                                SPI_STATE_CS_INVLD_EN | SPI_STATE_EN_VLD_CS)

struct mld_spi_module;
struct mld_spi_device;
struct mld_spi_async;

struct mld_spi_ops {
    sint32 (*spi_init)(struct mld_spi_module *bus);
    sint32 (*spi_deinit)(struct mld_spi_module *bus);
    void (*spi_set_clock_polarity_and_phase)(struct mld_spi_module *bus, \
            enum spi_tim_mode mode);
    sint32 (*spi_set_data_width)(struct mld_spi_module *bus, int width);
    sint32 (*spi_set_baud_rate)(struct mld_spi_module *bus, int rate);
    sint32 (*spi_set_mode)(struct mld_spi_module *bus, enum spi_mode mode);
    sint32 (*spi_set_direction)(struct mld_spi_module *bus, \
                                enum spi_com_mode dir);
    void (*spi_write_data)(struct mld_spi_module  *bus, uint32 data);
    uint32 (*spi_read_data)(struct mld_spi_module  *bus);
    boolean (*spi_can_write)(struct mld_spi_module  *bus);
    boolean (*spi_can_read)(struct mld_spi_module  *bus);
    boolean (*spi_tx_finished)(struct mld_spi_module  *bus);
    void (*spi_setup_irq_mask)(struct mld_spi_module  *bus, \
                               uint32 type);
    void (*spi_clr_irq_state)(struct mld_spi_module  *bus, uint32 clr);
    sint32 (*spi_set_ti_or_motorola_mode)(struct mld_spi_module *bus, \
                                          enum spi_ssp_mode mode);
    sint32 (*spi_set_predev_config)(struct mld_spi_module *bus, \
                                    struct mld_spi_device *dev);
    sint32 (*spi_transmit_receive)(struct mld_spi_module  *bus, \
                                   struct mld_spi_device *dev, \
                                   uint32 *ptxdata, uint32 *prxdata, \
                                   uint16 size, uint32 timeout);
    sint32 (*spi_transmit_receive_irq)(struct mld_spi_module  *bus, \
                                       struct mld_spi_device *dev, \
                                       uint32 *ptxdata, uint32 *prxdata, \
                                       uint16 size);
    sint32 (*spi_transmit_receive_dma)(struct mld_spi_module  *bus, \
                                       struct mld_spi_device *dev, \
                                       uint32 *ptxdata, uint32 *prxdata, \
                                       uint16 size);
    sint32 (*spi_vector_transmit_receive)(struct mld_spi_module  *bus, \
                                          struct mld_spi_device *dev, \
                                          struct mld_spi_async *vector, \
                                          uint32 timeout);
    sint32 (*spi_vector_transmit_receive_irq)(struct mld_spi_module  *bus, \
            struct mld_spi_device *dev, \
            struct mld_spi_async *vector);
    sint32 (*spi_vector_transmit_receive_dma)(struct mld_spi_module  *bus, \
            struct mld_spi_device *dev, \
            struct mld_spi_async *vector);
    sint32 (*spi_irq_state)(struct mld_spi_module *bus, uint32 *irq_status);
    void (*spi_dma_stop)(struct mld_spi_module *bus);
    void (*spi_transmit_stop)(struct mld_spi_module *bus);
};

union spi_data_ptr {
    /* data */
    uint32  val;
    uint8  *u8_ptr;
    uint16 *u16_ptr;
    uint32 *u32_ptr;
};

struct mld_spi_async {
    /* async mode need this*/
    uint32 len;
    /* prxdata */
    union spi_data_ptr prxdata;
    /* ptxdata */
    union spi_data_ptr ptxdata;
    /* data_width */
    enum fifo_width width_type;
    /* priv */
    void *priv;
    /* priv for ssdk */
    void *msg;
    /* list to transmit */
    struct mld_spi_async *next;
    /* prxdata */
    uint32 rx_cur;
    /* ptxdata */
    uint32 tx_cur;
    /* remain of this item */
    uint32 cur_remian;
    /* once except of this item */
    uint32 expect_len;
};

struct mld_spi_module {
    volatile uint32 base;
    /* irq num */
    volatile uint32 irq;
    /* bus num */
    volatile uint32 idx;
    /* status */
    uint32      state;
    /* spi common ops*/
    struct mld_spi_ops *bus_ops;
    /* ip special ops and params */
    void *priv;
    /* slave mode params  or soft cs pin id*/
    void *dev_mode;
    /* asycn mode need this*/
    struct mld_spi_async async;
};

struct mld_spi_device {
    /* spi bus ops*/
    struct mld_spi_module *bus;
    /* device special ops and params */
    void *priv;
};

static inline void mld_set_soft_cs_id(struct mld_spi_module *bus, uint32 id)
{
    bus->dev_mode = (void *)(uint32 *)id;
}
/**
 * @description:
 * @param {mld_spi_device} *dev
 * @param {void*} priv
 * @return {*}
 */
static inline  void mld_spi_dev_init(struct mld_spi_device *dev, \
                                     void *priv)
{
    dev->priv = priv;
}
/**
 * @description:
 * @param {mld_spi_device} *dev
 * @param {mld_spi_module*} bus
 * @param {void*} priv
 * @return {*}
 */
static inline  void mld_spi_dev_attach_bus(struct mld_spi_device *dev, \
        struct mld_spi_module *bus)
{
    dev->bus = bus;

    if (bus->bus_ops && bus->bus_ops->spi_set_predev_config)
        bus->bus_ops->spi_set_predev_config(bus, dev);
}
/**
 * @description:
 * @param {mld_spi_module} *bus
 * @param {void} *bus_priv
 * @param {void*} dev_mode
 * @return {*}
 */
static inline  void mld_spi_bus_set_privdata(struct mld_spi_module *bus, \
        void *bus_priv, void *dev_mode)
{
    bus->priv = bus_priv;
    bus->dev_mode = dev_mode;
}
/**
 * @description:
 * @param {mld_spi_module} *bus
 * @param {uint32} base
 * @param {mld_spi_ops*} ops
 * @return {*}
 */
static inline void mld_spi_bus_create(struct mld_spi_module *bus, \
                                      uint32 base, uint32 irq, struct mld_spi_ops *ops)
{
    bus->base = base;
    bus->bus_ops = ops;
    bus->irq = irq;
}

int mld_spi_handle_irq(uint32 irq, void *arg);

sint32 mld_spi_init(struct mld_spi_module *bus);

sint32 mld_spi_deinit(struct mld_spi_module *bus);

sint32 mld_spi_set_clock_polarity_and_phase(struct mld_spi_module *bus, enum spi_tim_mode mode);

sint32 mld_spi_set_data_width(struct mld_spi_module *bus, uint8 width);

sint32 mld_spi_set_baud_rate(struct mld_spi_module *bus, uint32 rate);

sint32 mld_spi_set_mode(struct mld_spi_module *bus, enum spi_mode mode);

sint32 mld_spi_set_direction(struct mld_spi_module *bus, enum spi_com_mode dir);

sint32 mld_spi_set_ti_or_motorola_mode(struct mld_spi_module *bus, \
                                       enum spi_ssp_mode mode);


sint32 mld_spi_transmit_receive(struct mld_spi_module *bus, struct mld_spi_device *dev, \
                                uint32 *ptxdata, uint32 *prxdata, uint16 size, uint32 timeout);

sint32 mld_spi_transmit_receive_dma(struct mld_spi_module *bus, struct mld_spi_device *dev, \
                                    uint32 *ptxdata, uint32 *prxdata, uint16 size);

sint32 mld_spi_transmit_receive_irq(struct mld_spi_module *bus, struct mld_spi_device *dev, \
                                    uint32 *ptxdata, uint32 *prxdata, uint16 size);

sint32 mld_spi_vector_transmit_receive(struct mld_spi_module *bus, struct mld_spi_device *dev, \
                                       struct mld_spi_async *vector);

sint32 mld_spi_vector_transmit_receive_irq(struct mld_spi_module *bus, struct mld_spi_device *dev, \
        struct mld_spi_async *vector);

sint32 mld_spi_vector_transmit_receive_dma(struct mld_spi_module *bus, struct mld_spi_device *dev, \
        struct mld_spi_async *vector);

sint32 mld_spi_async_polling(struct mld_spi_module *bus);

static inline sint32 mld_spi_master_transmit_receive(struct mld_spi_device *dev, uint32 *ptxdata,
        \
        uint32 *prxdata, uint16 size, uint32 timeout)
{
    return mld_spi_transmit_receive(dev->bus, dev, ptxdata, prxdata, size, timeout);
}
static inline sint32 mld_spi_master_transmit(struct mld_spi_device *dev, uint32 *ptxdata, \
        uint16 size, uint32 timeout)
{
    return mld_spi_transmit_receive(dev->bus, dev, ptxdata, NULL, size, timeout);
}
static inline sint32 mld_spi_master_receive(struct mld_spi_device *dev, uint32 *prxdata, \
        uint16 size, uint32 timeout)
{
    return mld_spi_transmit_receive(dev->bus, dev, NULL, prxdata, size, timeout);
}

static inline sint32 mld_spi_slave_transmit_receive(struct mld_spi_module *bus,
        uint32 *ptxdata, uint32 *prxdata, uint16 size)
{
    return mld_spi_transmit_receive(bus, NULL, ptxdata, prxdata, size, 0);
}
static inline sint32 mld_spi_slave_transmit(struct mld_spi_module *bus,
        uint32 *ptxdata, uint16 size)
{
    return mld_spi_transmit_receive(bus, NULL, ptxdata, NULL, size, 0);
}
static inline sint32 mld_spi_slave_receive(struct mld_spi_module *bus,
        uint32 *prxdata, uint16 size)
{
    return mld_spi_transmit_receive(bus, NULL, NULL, prxdata, size, 0);
}

static inline sint32 mld_spi_master_transmit_receive_dma(struct mld_spi_device *dev,
        uint32 *ptxdata, \
        uint32 *prxdata, uint16 size)
{
    return mld_spi_transmit_receive_dma(dev->bus, dev, ptxdata, prxdata, size);
}
static inline sint32 mld_spi_master_transmit_dma(struct mld_spi_device *dev, uint32 *ptxdata, \
        uint16 size)
{
    return mld_spi_transmit_receive_dma(dev->bus, dev, ptxdata, NULL, size);
}
static inline sint32 mld_spi_master_receive_dma(struct mld_spi_device *dev, uint32 *prxdata, \
        uint16 size)
{
    return mld_spi_transmit_receive_dma(dev->bus, dev, NULL, prxdata, size);
}

static inline sint32 mld_spi_slave_transmit_receive_dma(struct mld_spi_module *bus,
        uint32 *ptxdata, uint32 *prxdata, uint16 size)
{
    return mld_spi_transmit_receive_dma(bus, NULL, ptxdata, prxdata, size);
}
static inline sint32 mld_spi_slave_transmit_dma(struct mld_spi_module *bus,
        uint32 *ptxdata, uint16 size)
{
    return mld_spi_transmit_receive_dma(bus, NULL, ptxdata, NULL, size);
}
static inline sint32 mld_spi_slave_receive_dma(struct mld_spi_module *bus,
        uint32 *prxdata, uint16 size)
{
    return mld_spi_transmit_receive_dma(bus, NULL, NULL, prxdata, size);
}

static inline sint32 mld_spi_master_transmit_receive_irq(struct mld_spi_device *dev,
        uint32 *ptxdata, \
        uint32 *prxdata, uint16 size)
{
    return mld_spi_transmit_receive_irq(dev->bus, dev, ptxdata, prxdata, size);
}
static inline sint32 mld_spi_master_transmit_irq(struct mld_spi_device *dev, uint32 *ptxdata, \
        uint16 size)
{
    return mld_spi_transmit_receive_irq(dev->bus, dev, ptxdata, NULL, size);
}
static inline sint32 mld_spi_master_receive_irq(struct mld_spi_device *dev, uint32 *prxdata, \
        uint16 size)
{
    return mld_spi_transmit_receive_irq(dev->bus, dev, NULL, prxdata, size);
}

static inline sint32 mld_spi_slave_transmit_receive_irq(struct mld_spi_module *bus,
        uint32 *ptxdata, uint32 *prxdata, uint16 size)
{
    return mld_spi_transmit_receive_irq(bus, NULL, ptxdata, prxdata, size);
}
static inline sint32 mld_spi_slave_transmit_irq(struct mld_spi_module *bus,
        uint32 *ptxdata, uint16 size)
{
    return mld_spi_transmit_receive_irq(bus, NULL, ptxdata, NULL, size);
}
static inline sint32 mld_spi_slave_receive_irq(struct mld_spi_module *bus,
        uint32 *prxdata, uint16 size)
{
    return mld_spi_transmit_receive_irq(bus, NULL, NULL, prxdata, size);
}

sint32 spi_write_remain(struct mld_spi_module *bus);

sint32 spi_read_remain(struct mld_spi_module *bus);

void mld_spi_stop(struct mld_spi_module *bus);

static inline void sync_finished_callback(struct mld_spi_module *bus)
{
    bus->state &= (uint32)(~(SPI_STATE_BUSY_TX | SPI_STATE_BUSY_RX));
    /* Soft CS need */
    bus->state &= (uint32)(~(SPI_STATE_CS_ACTIVEED));
}

static inline void update_bus_state(struct mld_spi_module *bus)
{
    struct mld_spi_async *item = bus->async.next;

    if (bus->state & BUS_BUSY_DMA_MASK) {
        if (item->ptxdata.val)
            bus->state |= SPI_STATE_BUSY_TX | SPI_STATE_DMA_TX;
        else
            bus->state &= (uint32)(~(SPI_STATE_BUSY_TX | SPI_STATE_DMA_TX));

        if (item->prxdata.val)
            bus->state |= SPI_STATE_BUSY_RX | SPI_STATE_DMA_RX;
        else
            bus->state &= (uint32)(~(SPI_STATE_BUSY_RX | SPI_STATE_DMA_RX));
    } else {
        if (item->ptxdata.val)
            bus->state |= SPI_STATE_BUSY_TX | SPI_STATE_IRQ_TX;
        else
            bus->state &= (uint32)(~(SPI_STATE_BUSY_TX | SPI_STATE_IRQ_TX));

        if (item->prxdata.val)
            bus->state |= SPI_STATE_BUSY_RX | SPI_STATE_IRQ_RX;
        else
            bus->state &= (uint32)(~(SPI_STATE_BUSY_RX | SPI_STATE_IRQ_RX));
    }
}

static inline void next_async_item_cb(struct mld_spi_async *src, \
                                      struct mld_spi_async *dst)
{
    dst->len = src->len;
    dst->next = src->next;
    dst->prxdata.val = src->prxdata.val;
    dst->ptxdata.val = src->ptxdata.val;
    dst->width_type = src->width_type;
    dst->priv = src->priv;
    dst->cur_remian = dst->len;
    dst->rx_cur = 0;
    dst->tx_cur = 0;
}
#ifdef __cplusplus
}
#endif

#endif

