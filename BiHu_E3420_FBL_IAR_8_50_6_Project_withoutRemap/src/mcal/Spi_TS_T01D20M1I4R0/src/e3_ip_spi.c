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
 * @file  e3_ip_spi.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Spi plugins.
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Spi_reg.h"
#include "e3_ip_spi.h"
#include "sdrv_dmac.h"
#include "arch.h"
#include "Dio.h"
#include "Spi_Cfg.h"
#include "Mcu.h"

#ifdef CFG_DMA_SUPPORT_STATIC_ALLOCATION
#include "Dma.h"
#else
#include "dma.h"
#endif

#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

/**
 * @description:
 * @param {spi_dev_priv*} dev
 * @return {*}
 */
static sint32 params_check_device(struct spi_dev_priv *dev)
{
    if (SPI_DATA_WIDTH_MAX < dev->width || dev->width < SPI_DATA_WIDTH_MIN) {
        return -1;
    }

    if (SPI_CLK_PRESSCALE_MAX < dev->baud_div) {
        return -2;
    }

    return 0;
}
/**
 * @description:
 * @param {spi_bus_priv*} bus_priv
 * @return {*}
 */
static sint32 params_check_spi(struct mld_spi_module *bus)
{
    const struct spi_bus_priv *bus_priv = bus->priv;

    if ((bus_priv->flags & SPI_MODE_SLAVE_ENABLE) && !bus->dev_mode) {
        // slave mode mast have dev info
        return -1;
    }

    if (bus_priv->idle > SPI_IDLE_COUNT_MAX) {
        return -2;
    }

    if (bus_priv->timeout > SPI_TIMEOUT_COUNT_MAX) {
        return -3;
    }

    if (bus_priv->slave_nss_p > SPI_POL_VEL_MAX) {
        return -4;
    }

    return 0;
}
/**
 * @description:
 * @param {mld_spi_module} *instance
 * @return {*}
 */
static sint32 sspi_init(struct mld_spi_module *bus)
{
    uint32 reg_val;
    struct spi_bus_priv *bus_priv;

    if (!bus)
        return -1;

    bus_priv = (struct spi_bus_priv *)bus->priv;

    if (params_check_spi(bus))
        return -2;

    if (bus_priv->flags & SPI_MODE_SLAVE_ENABLE && !bus->dev_mode)
        return -3;

    if (bus->dev_mode && params_check_device(bus->dev_mode))
        return -4;

    // init reg val
    reg_val = readl(bus->base + SPI_CTRL_OFF);
    // softrst hwclr
    writel(BM_SPI_CTRL_SW_RST | reg_val, bus->base + SPI_CTRL_OFF);

    while (BM_SPI_CTRL_SW_RST & readl(bus->base + SPI_CTRL_OFF));

    if (bus_priv->flags & SPI_MODE_SLAVE_ENABLE) {
        bus->state |= SPI_STATE_IS_SLAVE;
        reg_val |= BM_SPI_CTRL_SLV_MODE;
        // reg_val |= BM_SPI_CTRL_SLV_UNS_SIZE_EN;
        reg_val &= (uint32)(~FM_SPI_CTRL_NSS_POL);
        reg_val |= FV_SPI_CTRL_NSS_POL(bus_priv->slave_nss_p);
    } else {
        reg_val &= (uint32)(~BM_SPI_CTRL_SLV_MODE);
    }

    reg_val &= (uint32)(~BM_SPI_CTRL_SLV_UNS_SIZE_EN);
    /* default is disable DMA req */
    reg_val &= (uint32)(~BM_SPI_CTRL_RX_DMA_EN);
    reg_val &= (uint32)(~BM_SPI_CTRL_TX_DMA_EN);

    if (bus_priv->flags & SPI_HALF_DUPLEX_ENABLE) {
        reg_val |= BM_SPI_CTRL_HALF_MODE;
    } else {
        reg_val &= (uint32)(~BM_SPI_CTRL_HALF_MODE);
    }

    if (bus_priv->flags & SPI_SSP_MODE_ENABLE) {
        reg_val |= BM_SPI_CTRL_MODE;
        /* ssp mode cs Polarity is specified as high effective */
        reg_val &= (uint32)(~FM_SPI_CTRL_NSS_POL);
        reg_val |= FV_SPI_CTRL_NSS_POL(0xF);
        /* ti mode is not allowed to enable uns_size_mode */
        reg_val &= (uint32)(~BM_SPI_CTRL_SLV_UNS_SIZE_EN);
    } else {
        reg_val &= (uint32)(~BM_SPI_CTRL_MODE);
    }

    /* BM_SPI_CTRL_SSP_CLK_MODE Prohibited to set !!!! */
    reg_val &= (uint32)(~BM_SPI_CTRL_SSP_CLK_MODE);

    if (bus_priv->flags & SPI_SIMP_DELAY_ENABLE) {
        reg_val |= BM_SPI_CTRL_SAMPLE_POINT;
    } else {
        reg_val &= (uint32)(~BM_SPI_CTRL_SAMPLE_POINT);
    }

    /* idle */
    reg_val &= (uint32)(~FM_SPI_CTRL_IDLE);
    reg_val |= FV_SPI_CTRL_IDLE(bus_priv->idle);
    /* timeout */
    reg_val &= (uint32)(~FM_SPI_CTRL_TIMEOUT);
    reg_val |= FV_SPI_CTRL_TIMEOUT(bus_priv->timeout);
    writel(reg_val, bus->base + SPI_CTRL_OFF);
    writel(0xFFFFFFFF, bus->base + SPI_IRQ_MASK_OFF);
    /* default disable spi avoid slave mode lost bit */
    writel((uint32)(~BM_SPI_EN_ENABLE), bus->base + SPI_EN_OFF);
    return 0;
}
static void sspi_recover(struct mld_spi_module *bus)
{
    uint32 reg_val;
    /* default disable spi avoid slave mode lost bit */
    writel((uint32)(~BM_SPI_EN_ENABLE), bus->base + SPI_EN_OFF);
    // init reg val
    reg_val = readl(bus->base + SPI_CTRL_OFF);
    reg_val &= (uint32)(~BM_SPI_CTRL_SLV_UNS_SIZE_EN);
    /* only slave mode do this sclk @133M *6cycle = 50ns softrst */
    writel(reg_val | BM_SPI_CTRL_SW_RST, bus->base + SPI_CTRL_OFF);

    while (BM_SPI_CTRL_SW_RST & readl(bus->base + SPI_CTRL_OFF));

    writel(reg_val, bus->base + SPI_CTRL_OFF);
    writel(0xFFFFFFFF, bus->base + SPI_IRQ_MASK_OFF);
}

/**
 * @description:
 * @param {mld_spi_module} *instance
 * @return {*}
 */
static sint32 sspi_deinit(struct mld_spi_module *bus)
{
    if (!bus)
        return -1;

    writel(0xFFFFFFFF, bus->base + SPI_IRQ_MASK_OFF);
    writel((uint32)(~BM_SPI_EN_ENABLE), bus->base + SPI_EN_OFF);
    // softrst
    writel(BM_SPI_CTRL_SW_RST, bus->base + SPI_CTRL_OFF);

    // softrst hwclr
    while (BM_SPI_CTRL_SW_RST & readl(bus->base + SPI_CTRL_OFF));

    return 0;
}
/**
 * @description: configurate the spi clock and data phase
 * @param {void} *bus
 * @param {enum spi_mode} mode
 *          MODE0 CPOL=0 CPHA=0
 *          MODE1 CPOL=0 CPHA=1
 *          MODE2 CPOL=1 CPHA=0
 *          MODE3 CPOL=1 CPHA=1
 * @return {*}
 */
static void sspi_set_clock_polarity_and_phase(struct mld_spi_module  *bus, \
        enum spi_tim_mode mode)
{
    /* set cpol and cpha ,do not touch hardware */
    ;
}

/**
 * @description:
 * @param {void} *bus
 * @param {int} width bit count
 * @return {*}
 */
static  sint32 sspi_set_data_width(struct mld_spi_module  *bus, int width)
{
    /* set data width */
    return 0;
}
/**
 * @description:configurate the spi baud rate
 * @param {void} *bus
 * @param {int} rate
 * @return {*}
 */
static  sint32 sspi_set_baud_rate(struct mld_spi_module  *bus, int rate)
{
    /* set baud rate */
    return 0;
}
/**
 * @description:configurate the spi mode
 * @param {void} *bus
 * @param {int} mode
 *        MASTER
 *        SLAVE
 * @return {*}
 */
static  sint32 sspi_set_mode(struct mld_spi_module *bus, enum spi_mode mode)
{
    uint32 reg_val;
    // init reg val
    reg_val = readl(bus->base + SPI_CTRL_OFF);

    /* set mode */
    if (mode == MASTER)
        reg_val &= (uint32)(~BM_SPI_CTRL_SLV_MODE);
    else
        reg_val |= BM_SPI_CTRL_SLV_MODE;

    writel(reg_val, bus->base + SPI_CTRL_OFF);

    return 0;
}
/**
 * @description:configurate the spi data direction
 * @param {void} *bus
 * @param {int} dir
 *        FULL
 *        HALF
 *        RX_ONLY
 *        TX_ONLY
 * @return {*}
 */
static  sint32 sspi_set_direction(struct mld_spi_module *bus, \
                                  enum spi_com_mode dir)
{
    uint32 reg_val;
    // init reg val
    reg_val = readl(bus->base + SPI_CTRL_OFF);

    /* set the direction */
    switch (dir) {
    case FULL_DUPLEX:
    case RX_ONLY:
    case TX_ONLY:
        reg_val &= (uint32)(~BM_SPI_CTRL_HALF_MODE);
        break;

    case HALF_DUPLEX:
        reg_val |= BM_SPI_CTRL_HALF_MODE;
        break;

    default:
        break;
    }

    writel(reg_val, bus->base + SPI_CTRL_OFF);

    return 0;
}
/**
 * @description:configurate the spi nss mode
 * @param {void} *bus
 * @param {int} mode
 *        MOTOROLA
 *        TI
 * @return {*}
 */
static  sint32 sspi_set_ti_or_motorola_mode(struct mld_spi_module *bus, \
        enum spi_ssp_mode mode)
{
    uint32 reg_val;
    // init reg val
    reg_val = readl(bus->base + SPI_CTRL_OFF);

    /* set the direction */
    if (mode == MOTOROLA ) {
        reg_val &= (uint32)(~BM_SPI_CTRL_MODE);
    } else {
        reg_val |= BM_SPI_CTRL_MODE;
        /* ssp mode cs Polarity is specified as high effective */
        reg_val |= 0xF << 8;
    }

    writel(reg_val, bus->base + SPI_CTRL_OFF);

    return 0;
}
/**
 * @description:configurate the spi nss mode
 * @param {void} *bus
 * @param {int} mode
 *        MOTOROLA
 *        TI
 * @return {*}
 */
static  sint32 sspi_set_predev_parameters(struct mld_spi_module *bus, \
        struct mld_spi_device *dev)
{
    if (bus == NULL_PTR || dev == NULL_PTR) {
        SPI_DBG("bus%p not have dev.\n", bus);
        return -1;
    }

    struct spi_dev_priv  *priv = (struct spi_dev_priv *)dev->priv;

    if (!priv) {
        SPI_DBG("bus%p not have dev params.\n", bus);
        return -2;
    }

    uint32 ctrl = readl(bus->base + SPI_CTRL_OFF);

    if (priv->flags & F_DEV_NSS_HIGH)
        ctrl |= 0x01 << (priv->nss_idx + 8);
    else
        ctrl &= (uint32)(~(0x01 << (priv->nss_idx + 8)));

    writel(ctrl, bus->base + SPI_CTRL_OFF);

    return 0;
}

static void sspi_write(struct mld_spi_module  *bus, uint32 data)
{
    writel(data, bus->base + SPI_TX_FIFO_DATA_OFF);
}

static uint32 sspi_read(struct mld_spi_module  *bus)
{
    return readl(bus->base + SPI_RX_FIFO_DATA_OFF);
}

static boolean sspi_can_write(struct mld_spi_module  *bus)
{
    /*
        master mode rx fifo full stop to send,but the Slave does not have this mechanism.
        Slave should stop writing immediately when it finds that rxfifo is full in the
         process of writing data, and then read rx fifo to avoid rx fifo overflow.
    */
    return !(readl(bus->base + SPI_FIFO_STAT_OFF) & (BM_SPI_FIFO_STAT_TX_FULL |
             BM_SPI_FIFO_STAT_RX_FULL));
}

static boolean sspi_can_read(struct mld_spi_module  *bus)
{
    return !(readl(bus->base + SPI_FIFO_STAT_OFF) & BM_SPI_FIFO_STAT_RX_EMPTY);
}

static boolean sspi_tx_finished(struct mld_spi_module  *bus)
{
    return (!!(readl(bus->base + SPI_IRQ_STAT_OFF) & BM_SPI_IRQ_STAT_MST_FRM_END));
}

static inline void disable_dma_req(struct mld_spi_module  *bus, uint32 flags)
{
    uint32 reg_val;
    reg_val = readl(bus->base + SPI_CTRL_OFF);

    if (flags & SPI_DMA_RX_ENABLE) {
        reg_val &= (uint32)(~BM_SPI_CTRL_RX_DMA_EN);
        SPI_DBG("spi_dma rx disable\n");
    }

    if (flags & SPI_DMA_TX_ENABLE) {
        reg_val &= (uint32)(~BM_SPI_CTRL_TX_DMA_EN);
        SPI_DBG("spi_dma tx disable\n");
    }

    writel(reg_val, bus->base + SPI_CTRL_OFF);

}
extern void Spi_HwMainFunctionHandling(uint8 Hwidx);

static void dma_handle(uint32 dma_stat, uint32 ch_stat, void *context)
{
    uint32 xfer;
    dma_chan_t *chan = (dma_chan_t *)context;
    struct mld_spi_module  *bus = (struct mld_spi_module *)chan->context;
    struct spi_bus_priv *bus_priv = (struct spi_bus_priv *)bus->priv;
    uint8 data_width_shift = bus->async.width_type;

    /* dma_stop and dma_free_chan will be called in SPI CS inactive interrupt */
    if (!(bus->state & SPI_STATE_IS_UNS_EN)) {
        dma_stop(chan);
        dma_free_chan(chan);
    }

    if (dma_stat == DMA_COMPLETED) {
        /* fixed-length mode need this part handles  */
        if (!(bus->state & SPI_STATE_IS_UNS_EN)) {
            if (context == bus_priv->dma_ch_rx) {
                SPI_DBG("bus%d dma rx.\n", bus->idx);
                disable_dma_req(bus, SPI_DMA_RX_ENABLE);
                dma_invalidate_cache((addr_t)bus->async.prxdata.val + (bus->async.rx_cur << data_width_shift),
                                     ROUNDUP(((bus->async.expect_len - bus->async.rx_cur) << data_width_shift), CACHE_LINE));
                xfer = sdrv_dma_get_xfer_bytes(bus_priv->dma_ch_rx, true);
                xfer = xfer >> data_width_shift;

                if ((bus->async.expect_len - bus->async.rx_cur ) > xfer) {
                    bus_priv->dma_err |= SPI_RX_DMA_ERR;
                }

                bus->async.rx_cur += xfer;
                bus->async.cur_remian = bus->async.len - bus->async.rx_cur;
                bus_priv->dma_ch_rx = NULL_PTR;
            } else if (context == bus_priv->dma_ch_tx) {
                SPI_DBG("bus%d dma tx.\n", bus->idx);
                disable_dma_req(bus, SPI_DMA_TX_ENABLE);
                xfer = sdrv_dma_get_xfer_bytes(bus_priv->dma_ch_tx, true);
                xfer = xfer >> data_width_shift;

                if ((bus->async.expect_len - bus->async.tx_cur ) > xfer) {
                    bus_priv->dma_err |= SPI_TX_DMA_ERR;
                }

                bus->async.tx_cur += xfer;
                bus->async.cur_remian = bus->async.len - bus->async.tx_cur;
                bus_priv->dma_ch_tx = NULL_PTR;
            }
        }
    } else {
        /* DMA_PENDING DMA_PAUSED */
        if (context == bus_priv->dma_ch_tx)
            bus_priv->dma_err |= SPI_TX_DMA_ERR;
        else if (context == bus_priv->dma_ch_rx)
            bus_priv->dma_err |= SPI_RX_DMA_ERR;

        disable_dma_req(bus, SPI_DMA_RX_ENABLE);
        disable_dma_req(bus, SPI_DMA_TX_ENABLE);
        bus_priv->dma_ch_rx = NULL_PTR;
        bus_priv->dma_ch_tx = NULL_PTR;

    }

    Spi_HwMainFunctionHandling(bus->idx);
}

static void sspi_error_handle(struct mld_spi_module  *bus)
{
    uint32 xfer;
    uint8 data_width_shift = bus->async.width_type;
    struct spi_bus_priv *bus_priv = (struct spi_bus_priv *)bus->priv;

    if (bus_priv->dma_ch_rx) {
        disable_dma_req(bus, SPI_DMA_RX_ENABLE);
        dma_stop(bus_priv->dma_ch_rx);
        xfer = sdrv_dma_get_xfer_bytes(bus_priv->dma_ch_rx, true);
        arch_invalidate_cache_range((const void *)(uint32 *)bus->async.prxdata.val,
                                    ROUNDUP(xfer, CACHE_LINE));
        xfer >>= data_width_shift;
        bus->async.rx_cur = xfer;
        /* read the data of the remaining insufficient water level */
        spi_read_remain(bus);
        dma_free_chan(bus_priv->dma_ch_rx);
        bus_priv->dma_ch_rx = NULL_PTR;
    }

    if (bus_priv->dma_ch_tx) {
        disable_dma_req(bus, SPI_DMA_TX_ENABLE);
        dma_stop(bus_priv->dma_ch_tx);
        xfer = sdrv_dma_get_xfer_bytes(bus_priv->dma_ch_tx, true);
        xfer >>= data_width_shift;
        bus->async.tx_cur = xfer;
        dma_free_chan(bus_priv->dma_ch_tx);
        bus_priv->dma_ch_tx = NULL_PTR;
    }
}

static void spi_slave_tx_curr_quirks(struct mld_spi_module *bus)
{
    uint8 fifo_remain =  GFV_SPI_FIFO_STAT_TX_FIFO_DPTR(readl(bus->base + SPI_FIFO_STAT_OFF));

    if (!bus->async.ptxdata.val)
        return ;

    /* pipe line have space same as fifo */
    if (!bus->async.prxdata.val) {
        if (bus->async.width_type == SPI_DATA_WIDTH_BYTE) {
            fifo_remain += SPI_PIPE_LINE_SIZE_8B;
        } else {
            fifo_remain += SPI_PIPE_LINE_SIZE_OB;
        }
    }

    bus->async.tx_cur -= fifo_remain;

}

static inline void enable_dma_req(struct mld_spi_module  *bus)
{
    uint32 reg_val;
    const struct spi_bus_priv *bus_priv = (struct spi_bus_priv *)bus->priv;
    reg_val = readl(bus->base + SPI_CTRL_OFF);

    if (bus->async.prxdata.val && (bus_priv->flags & SPI_DMA_RX_ENABLE)) {
        reg_val |= BM_SPI_CTRL_RX_DMA_EN;
    } else {
        reg_val &= (uint32)(~BM_SPI_CTRL_RX_DMA_EN);
    }

    if (bus->async.ptxdata.val && (bus_priv->flags & SPI_DMA_TX_ENABLE)) {
        reg_val |= BM_SPI_CTRL_TX_DMA_EN;
    } else {
        reg_val &= (uint32)(~BM_SPI_CTRL_TX_DMA_EN);
    }

    writel(reg_val, bus->base + SPI_CTRL_OFF);
}

static void setup_spi_irq(struct mld_spi_module  *bus, uint32 mode)
{
    uint16 rx_size;
    uint32 reg_val;
    uint32 rx_thrd = 0, tx_thrd = 0;
    const struct spi_bus_priv  *bus_priv = bus->priv;

    reg_val = readl(bus->base + SPI_IRQ_STAT_OFF);
    /* clr irqs */
    writel(reg_val | 0xFFFF, bus->base + SPI_IRQ_STAT_OFF);
    reg_val = readl(bus->base + SPI_IRQ_MASK_OFF);

    if (bus->async.ptxdata.val && mode != OP_MODE_DMA ) {
        /* if size < spi_FIFO_SIZE only fream done will into irq */
        tx_thrd = SPI_FIFO_LEN / 2;
        reg_val &= (uint32)(~BM_SPI_IRQ_MASK_TX_FIFO_PRE_EMPTY);
    }

    if (bus->async.prxdata.val && mode != OP_MODE_DMA) {
        rx_size = bus->async.cur_remian - bus->async.rx_cur;
        rx_thrd = rx_size >= SPI_FIFO_LEN ? SPI_FIFO_LEN / 2 : rx_size - 1;
        /* fifo remain data this case used fream done to read */
        reg_val &= (uint32)(~BM_SPI_IRQ_MASK_RX_FIFO_PRE_FULL);
    }

    if (bus->async.prxdata.val && mode != OP_MODE_DMA) {
        reg_val &= (uint32)(~BM_SPI_IRQ_MASK_FRM_DONE);
        /* slave rx done need if not the data will lost in fifo */
    }

    if (mode != OP_MODE_DMA) {
        /* config thrd ,DMA also depends on this reg ,so this reg only can touch once */
        writel(FV_SPI_TX_FIFO_CTRL_THRD(tx_thrd), bus->base + SPI_TX_FIFO_CTRL_OFF);
        writel(FV_SPI_RX_FIFO_CTRL_THRD(rx_thrd), bus->base + SPI_RX_FIFO_CTRL_OFF);
    }

    if (bus->state & SPI_STATE_IS_SLAVE) {
        if (bus->state & SPI_STATE_BUSY_TX)
            reg_val &= (uint32)(~BM_SPI_IRQ_MASK_TX_FIFO_UDR);

        if (bus->state & SPI_STATE_BUSY_RX)
            reg_val &= (uint32)(~BM_SPI_IRQ_MASK_RX_FIFO_OVR);

#if ENABLE_SLAVE_MCS_TRIG == STD_OFF
        /* enable cs valid anyway */
        reg_val &= (uint32)(~BM_SPI_IRQ_MASK_SLV_NSS_VLD);
        bus->state |= SPI_STATE_EN_VLD_CS;
#endif
    }

    /*
        undef size mode workaround step"
            1.enable nss valid irq use to enable cs unvalid irq.
            2.enable nss unvalid irq in cs selected irq handler service.
            3.handling workaround in cs inactiveed irq handler service.
        worksround step1:
        enable cs inactive irq disable cs active irq
    */
    if (bus->state & SPI_STATE_IS_SLAVE) {
        /* undef size mode enables cs active interrupt to enable nss invalid interrupt */
        if (bus->state & SPI_STATE_IS_UNS_EN) {
            reg_val &= (uint32)(~BM_SPI_IRQ_MASK_SLV_NSS_VLD);
            bus->state |= SPI_STATE_EN_VLD_CS;
        }
    }

    /* Mask interrupt if it is in polling mode */
    if ((bus_priv->flags & SPI_TX_IRQ_ENABLE) == 0) {
        reg_val |= BM_SPI_IRQ_MASK_TX_FIFO_PRE_EMPTY;
    }

    if ((bus_priv->flags & SPI_RX_IRQ_ENABLE) == 0) {
        reg_val |= BM_SPI_IRQ_MASK_RX_FIFO_PRE_FULL;
        reg_val |= BM_SPI_IRQ_MASK_FRM_DONE;
    }

    if ((bus_priv->flags & SPI_SLV_IRQ_ENABLE) == 0) {
        reg_val |= BM_SPI_IRQ_MASK_TX_FIFO_UDR;
        reg_val |= BM_SPI_IRQ_MASK_RX_FIFO_OVR;
        reg_val |= BM_SPI_IRQ_MASK_SLV_NSS_VLD;
    }

    SPI_DBG("%s t_thrd:%d r_thrd:%d reg:%08x\n", \
            __FUNCTION__, tx_thrd, rx_thrd, reg_val);
    /* enable pre irqs*/
    writel(reg_val, bus->base + SPI_IRQ_MASK_OFF);
}

static void sspi_setup_irq_mask(struct mld_spi_module  *bus, \
                                uint32 irq_mask)
{
    uint32 reg_val = readl(bus->base + SPI_IRQ_MASK_OFF);

    if (irq_mask & SPI_RX_READ_REQ)
        reg_val |= BM_SPI_IRQ_MASK_RX_FIFO_PRE_FULL;

    if (irq_mask & SPI_TX_WRITE_REQ)
        reg_val |= BM_SPI_IRQ_MASK_TX_FIFO_PRE_EMPTY;

    if (irq_mask & SPI_CS_INVLD_REQ)
        reg_val |= BM_SPI_IRQ_MASK_SLV_NSS_INVLD;

    /*
        In indefinite length mode, the cs invalid interrupt enable
     can only be turned off after the cs invalid interrupt occurs so
     0xFFFF ===> 0xDFFF.
    */
    if (irq_mask & SPI_TRASPORT_FINISH)
        reg_val |= 0xDFFF;



    SPI_DBG("%s reg:%08x\n", __FUNCTION__, reg_val);
    /* disable pre irqs*/
    writel(reg_val, bus->base + SPI_IRQ_MASK_OFF);
}

static inline void spi_irq_update_mask(struct mld_spi_module  *bus, \
                                       uint32 set_mask, uint32 clr_mask)
{
    uint32 reg_val = readl(bus->base + SPI_IRQ_MASK_OFF);
    const struct spi_bus_priv  *bus_priv = bus->priv;
    reg_val &= (uint32)(~clr_mask);
    reg_val |= set_mask;

    if ((bus_priv->flags & SPI_SLV_IRQ_ENABLE) == 0) {
        reg_val |= BM_SPI_IRQ_MASK_TX_FIFO_UDR;
        reg_val |= BM_SPI_IRQ_MASK_RX_FIFO_OVR;
        reg_val |= BM_SPI_IRQ_MASK_SLV_NSS_VLD;
        reg_val |= BM_SPI_IRQ_MASK_SLV_NSS_INVLD;
    }

    SPI_DBG("%s reg:%08x\n", __FUNCTION__, reg_val);
    /* update pre irqs */
    writel(reg_val, bus->base + SPI_IRQ_MASK_OFF);
}

#define SPI_BURST_LEN       DMA_BURST_LEN_9

static sint32 setup_spi_dma(struct mld_spi_module  *bus, uint32 ptxdata, \
                            uint32 prxdata, uint16 size, enum fifo_width width)
{

    sint32 ret = 0;
    uint8 dma_ret, size_multiple;
    dma_chan_t *chan_rx = NULL, *chan_tx = NULL;
    dma_dev_bus_width_e dma_width;
    struct spi_bus_priv *priv = bus->priv;
    struct dma_dev_cfg dma_cfg;
    mini_memclr_s(&dma_cfg, sizeof(struct dma_dev_cfg));
    uint16 add_external = 0;
#ifdef CFG_DMA_SUPPORT_STATIC_ALLOCATION
#if DMA_DYNAMIC_CHANNEL == STD_OFF
    Dma_InsConfigType dma_static_cfg;
#endif
#endif

    if (!ptxdata && !prxdata) {
        return -1;
    }

    if (ptxdata) {
#if DMA_DYNAMIC_CHANNEL == STD_ON
        chan_tx = dma_req_chan((dma_dev_t *)priv->dma);
#else
#ifdef CFG_DMA_SUPPORT_STATIC_ALLOCATION

        if (E_OK == Dma_GetConfigParams(bus->idx, DMA_SPI_TX, DMA_MODULE_SPI, &dma_static_cfg)) {
            chan_tx = dma_req_chan_with_id(dma_static_cfg.Controller, dma_static_cfg.ChannelId);
        }

#endif
#endif
    }

    if (prxdata) {
#if DMA_DYNAMIC_CHANNEL == STD_ON
        chan_rx = dma_req_chan((dma_dev_t *)priv->dma);
#else
#ifdef CFG_DMA_SUPPORT_STATIC_ALLOCATION

        if (E_OK == Dma_GetConfigParams(bus->idx, DMA_SPI_RX, DMA_MODULE_SPI, &dma_static_cfg)) {
            chan_rx = dma_req_chan_with_id(dma_static_cfg.Controller, dma_static_cfg.ChannelId);
        }

#endif
#endif
    }

    if (prxdata && !chan_rx) {
        ret =  -2;
    }

    if (ptxdata && !chan_tx) {
        ret = -3;
    }

    if (!IS_ALIGNED(prxdata, CACHE_LINE) || !IS_ALIGNED(ptxdata, CACHE_LINE)) {
        ret = -6;
    }

    if (width == SPI_DATA_WIDTH_BYTE) {
        size_multiple = 1;
        dma_width = DMA_DEV_BUSWIDTH_1_BYTE;
    } else if (width == SPI_DATA_WIDTH_HALF_WORD) {
        size_multiple = 2;
        dma_width = DMA_DEV_BUSWIDTH_2_BYTES;
    } else {
        size_multiple = 4;
        dma_width = DMA_DEV_BUSWIDTH_4_BYTES;
    }

    ptxdata = ptxdata + (bus->async.tx_cur << width);
    prxdata = prxdata + (bus->async.rx_cur << width);

    if (!ret && chan_tx) {
        SPI_DBG("bus%p add to tx %p\n", bus, chan_tx);
        priv->dma_ch_tx = (void *)chan_tx;
        chan_tx->context = (void *)bus;
        chan_tx->irq_cb = (dma_irq_handle)&dma_handle;
        uint16 tx_thrd = size > SPI_FIFO_LEN ? SPI_FIFO_LEN / 2 : size - 1;
        /* config fifo thrd */
        writel(FV_SPI_TX_FIFO_CTRL_THRD(tx_thrd), \
               bus->base + SPI_TX_FIFO_CTRL_OFF);

        dma_cfg.direction = DMA_MEM2DEV;
        dma_cfg.src_addr = (addr_t)soc_to_dma_address(ptxdata);
        dma_cfg.dst_addr = bus->base + SPI_TX_FIFO_DATA_OFF;
        dma_cfg.src_addr_width = dma_width;
        dma_cfg.dst_addr_width = dma_width;

        dma_cfg.src_maxburst = SPI_BURST_LEN;
        dma_cfg.dst_maxburst = SPI_BURST_LEN;

        dma_config_chan(chan_tx, &dma_cfg);

        /*
                Undef size mode need to give more data to tx fifo to avoid udr of ip bug.
            always give tx FIFO more 8bytes data, even in the case of 32bit data bit width,
            it can ensure that there are two redundant data in txfifo to avoid tx fifo underflow.
        */
        if ((bus->state & (SPI_STATE_IS_SLAVE | SPI_STATE_IS_UNS_EN)) ==
            (SPI_STATE_IS_SLAVE | SPI_STATE_IS_UNS_EN)) {
            add_external = SPI_BURST_LEN;
        }

        dma_flush_cache((addr_t)ptxdata, ROUNDUP(size * size_multiple, CACHE_LINE));
        dma_ret = dma_prep_dev(chan_tx, (void *)(uint32 *)ptxdata,
                               size * size_multiple + add_external, DMA_INTERRUPT);

        if (dma_ret == FALSE)
            ret = -4;


        SPI_DBG("%s t_thrd:%d\n", \
                __FUNCTION__, tx_thrd);
    }

    if (!ret && chan_rx) {
        SPI_DBG("bus%p add to rx %p\n", bus, chan_rx);
        priv->dma_ch_rx = (void *)chan_rx;
        chan_rx->context = (void *)bus;
        chan_rx->irq_cb = (dma_irq_handle)&dma_handle;
        /* config fifo thrd */
        writel(FV_SPI_RX_FIFO_CTRL_THRD((SPI_FIFO_LEN / 2) - 1), \
               bus->base + SPI_RX_FIFO_CTRL_OFF);
        dma_cfg.direction = DMA_DEV2MEM;
        dma_cfg.src_addr = bus->base + SPI_RX_FIFO_DATA_OFF;
        dma_cfg.dst_addr = (addr_t)soc_to_dma_address(prxdata);
        dma_cfg.dst_addr_width = dma_width;
        dma_cfg.src_addr_width = dma_width;

        dma_cfg.src_maxburst = SPI_BURST_LEN;
        dma_cfg.dst_maxburst = SPI_BURST_LEN;
        dma_config_chan(chan_rx, &dma_cfg);
        dma_flush_cache((addr_t)prxdata, ROUNDUP(size * size_multiple, CACHE_LINE));
        dma_ret = dma_prep_dev(chan_rx, (void *)(uint32*)prxdata, size * size_multiple,
                               DMA_INTERRUPT);

        if (dma_ret == FALSE)
            ret = -5;

    }

    if (!ret) {

        if (chan_rx) {
            /*
                Read Simultaneous Clear Transfer Count Register
            */
            sdrv_dma_get_xfer_bytes(chan_rx, true);
            dma_start(chan_rx);
        }

        if (chan_tx) {
            /*
                Read Simultaneous Clear Transfer Count Register
            */
            sdrv_dma_get_xfer_bytes(chan_tx, true);
            dma_start(chan_tx);
        }
    } else {
        SPI_DBG("dma opt error:%d\n", ret);

        if (chan_rx) {
            dma_stop(chan_rx);
            dma_free_chan(chan_rx);
        }

        if (chan_tx) {
            dma_stop(chan_tx);
            dma_free_chan(chan_tx);
        }
    }

    return ret;
}
static void sspi_clr_irq_state(struct mld_spi_module  *bus, uint32 clr);
static sint32 update_cmd(struct mld_spi_module  *bus)
{
    uint32 fifo_e_timeout = TIMEOUT_WAIT_MST_END;
    uint32 cmd = readl(bus->base + SPI_CMD_CTRL_OFF);
    cmd &= (uint32)(~FM_SPI_CMD_CTRL_FRAM_SIZE);

    if (bus->async.cur_remian > SPI_FREAM_SIZE_MAX) {
        cmd |= FV_SPI_CMD_CTRL_FRAM_SIZE(SPI_FREAM_SIZE_MAX - 1);
        bus->async.expect_len += SPI_FREAM_SIZE_MAX;
    } else {
        /* last write */
        cmd |= FV_SPI_CMD_CTRL_FRAM_SIZE(bus->async.cur_remian - 1);
        bus->async.expect_len += bus->async.cur_remian;

        /* last default set  will limit 1024 once tansmit */
        if (!bus->async.next)
            cmd |= BM_SPI_CMD_CTRL_LAST;
    }

    fifo_e_timeout = TIMEOUT_WAIT_MST_END;

    while (!sspi_can_write(bus) && --fifo_e_timeout);

    if (fifo_e_timeout == 0) {
        /* fifo always full */
        return -1;
    }

    /* updata cmd */
    writel(cmd, bus->base + SPI_TX_FIFO_CMD_OFF);
    fifo_e_timeout = TIMEOUT_WAIT_MST_END;

    if (!(bus->state & SPI_STATE_IS_SLAVE)) {
        while (!sspi_tx_finished(bus) && --fifo_e_timeout);
    }

    if (fifo_e_timeout == 0) {
        sspi_recover(bus);
        /* exception event */
        return -2;
    }

    sspi_clr_irq_state(bus, (uint32)BM_SPI_IRQ_STAT_MST_FRM_END);
    SPI_DBG("updata cmd %08x \n", cmd);
    return 0;
}

static sint32 generate_cmd(struct mld_spi_module  *bus, struct spi_dev_priv *config)
{
    uint32 cmd = 0, is_en, fifo_e_timeout = TIMEOUT_WAIT_MST_END;

    if (config->flags & F_DEV_SWAP)
        cmd |= BM_SPI_CMD_CTRL_SWAP;

    if (config->flags & F_DEV_LSB)
        cmd |= BM_SPI_CMD_CTRL_LSB;

    if (!bus->async.ptxdata.val)
        cmd |= BM_SPI_CMD_CTRL_TX_MASK;

    if (!bus->async.prxdata.val)
        cmd |= BM_SPI_CMD_CTRL_RX_MASK;

    // mode
    switch (config->mode) {
    case MODE0:
        break;

    case MODE1:
        cmd |= BM_SPI_CMD_CTRL_SPI_CPHA;
        break;

    case MODE2:
        cmd |= BM_SPI_CMD_CTRL_SPI_CPOL;
        break;

    case MODE3:
        cmd |= BM_SPI_CMD_CTRL_SPI_CPHA | BM_SPI_CMD_CTRL_SPI_CPOL;
        break;
    }

    // fream size
    if (bus->async.len > SPI_FREAM_SIZE_MAX) {
        cmd |= FV_SPI_CMD_CTRL_FRAM_SIZE(SPI_FREAM_SIZE_MAX - 1);
        bus->async.expect_len = SPI_FREAM_SIZE_MAX;
    } else {
        cmd |= FV_SPI_CMD_CTRL_FRAM_SIZE(bus->async.len - 1);
        bus->async.expect_len = bus->async.len;

        /* last default set  will limit 1024 once tansmit */
        if (!bus->async.next)
            cmd |= BM_SPI_CMD_CTRL_LAST;
    }

    cmd |= FV_SPI_CMD_CTRL_WORD_SIZE( config->width - 1);
    cmd |= FV_SPI_CMD_CTRL_PRESSCALE(config->baud_div);
    cmd |= FV_SPI_CMD_CTRL_NSS(config->nss_idx);

    /*
            When the sclk is disturbed, the slave may enter the REAPT state.
        At this time, the new transmission CMD write cannot take effect, so the
        slave state cannot return to the normal state; therefore, in order to ensure
        the robustness of the slave, the reset guarantee is performed before each transmission
        starts. Can recover from errors, the cost is us-level time consumption before starting the transmission.
    */
    if (bus->state & SPI_STATE_IS_SLAVE)
        sspi_recover(bus);

    /*
        The workaround will be enabled when both conditions are met at the same time:
            1. chip version >1.0.
            2. Transmission length greater than SPI_FREAM_SIZE_MAX.
    */
    if ((bus->async.len > SPI_FREAM_SIZE_MAX) && (bus->state & SPI_STATE_IS_SLAVE)) {
#if ENABLE_SLAVE_MCS_TRIG == STD_ON
        /* Multiple CS is not supported for undefined lengths */
        return -1;
#else
#ifdef  SEMIDRIVE_E3_SERIES

        if (Mcu_GetChipVersion())
#endif
        {
            /* only for 1.1 */
            uint32 val = readl(bus->base + SPI_CTRL_OFF);
            writel(val | BM_SPI_CTRL_SLV_UNS_SIZE_EN,
                   bus->base + SPI_CTRL_OFF);
            bus->state |= SPI_STATE_IS_UNS_EN;
            bus->async.expect_len = bus->async.len;
            /* slave mast only one vector item  mean that next == NULL always */
            SPI_DBG("enable uns feature \n");
        }

#ifdef SEMIDRIVE_E3_SERIES
        else {
            /*
                chip version 1.0 does not support the case where the length of a single transfer exceeds SPI_FREAM_SIZE_MAX
            */
            return -1;
        }

#endif /* SEMIDRIVE_E3_SERIES */
#endif /* ENABLE_SLAVE_MCS_TRIG == STD_ON */
    }

#if ENABLE_SLAVE_MCS_TRIG == STD_OFF

    if (bus->state & SPI_STATE_IS_SLAVE) {
        /* software undef size mode */
        bus->state |= SPI_STATE_IS_UNS_EN;
    }

#endif
    fifo_e_timeout = TIMEOUT_WAIT_MST_END;

    while (!sspi_can_write(bus) && --fifo_e_timeout);

    if (fifo_e_timeout == 0) {
        sspi_recover(bus);
        /* exception event */
        return -2;
    }

    /* config cmd  */
    writel(cmd, bus->base + SPI_TX_FIFO_CMD_OFF);
    is_en = readl(bus->base + SPI_EN_OFF);
    fifo_e_timeout = TIMEOUT_WAIT_MST_END;

    /* if it is not enabled, it means it is executed for the first time, so there is no need to wait for mst_fream_end */
    if ((is_en & BM_SPI_EN_ENABLE)) {
        if (!(bus->state & SPI_STATE_IS_SLAVE)) {
            while (!sspi_tx_finished(bus) && --fifo_e_timeout);

            sspi_clr_irq_state(bus, (uint32)BM_SPI_IRQ_STAT_MST_FRM_END);
        }
    }

    if (fifo_e_timeout == 0) {
        sspi_recover(bus);
        /* exception event */
        return -2;
    }

    /* enable Spi */
    if (!(is_en & BM_SPI_EN_ENABLE))
        writel(BM_SPI_EN_ENABLE, bus->base + SPI_EN_OFF);

    SPI_DBG("first cmd %08x\n", cmd);

    return 0;
}
/**
 * @description:
 * @param {mld_spi_module } *bus
 * @param {mld_spi_device*} dev
 * @param {struct mld_spi_async *} transmit
 * @param {uint16} fream_size
 * @param {uint32} timeout
 * @return {*}
 */
static sint32 sspi_vector_transmission_ops(struct mld_spi_module  *bus, \
        struct mld_spi_device *dev, struct mld_spi_async *transmit, \
        uint32 timeout, enum spi_ops_mode mode)
{
    uint8 block = 0;
    uint16 cnt = 0;
    sint32 ret = 0;
    uint32 timeout_cnt;
    struct spi_dev_priv *dev_mode;
    const struct spi_bus_priv *bus_priv = bus->priv;

    if (!transmit->ptxdata.val && !transmit->prxdata.val) {
        return -1;
    }

    if (timeout && !dev) {
        return -2;
    }

    // half mode can't sync to tx & rx
    if (bus_priv->flags & SPI_HALF_DUPLEX_ENABLE) {
        if (transmit->ptxdata.val && transmit->prxdata.val)
            return -3;
    }

    if (dev) {
        dev_mode = (struct spi_dev_priv *)dev->priv;
    } else if (bus->dev_mode) {
        dev_mode = (struct spi_dev_priv *)bus->dev_mode;
    } else {
        return -4;
    }

    if (!dev_mode)
        return -5;

    if (!timeout)
        /* only for sync transmition */
        block = 1;

    if (!transmit->expect_len) {
        /*sync to bus */
        next_async_item_cb(transmit, &bus->async);
        /* config fifo keep default */
        writel(FV_SPI_TX_FIFO_CTRL_THRD(0), bus->base + SPI_TX_FIFO_CTRL_OFF);
        writel(FV_SPI_RX_FIFO_CTRL_THRD(0), bus->base + SPI_RX_FIFO_CTRL_OFF);
        /* config Timing */
        writel(dev_mode->tim_ctrl, bus->base + SPI_TIM_CTRL_OFF);

        /* config cmd */
        if (generate_cmd(bus, dev_mode)) {
            return -8;
        }

        /* soft cs */
        if (!(bus->state & SPI_STATE_IS_SLAVE)) {
            if (!(bus->state & SPI_STATE_CS_ACTIVEED)) {
                if (dev_mode->flags & F_DEV_NSS_SOFT) {
                    timeout_cnt = TIMEOUT_SYNC_ONE_ITEM;
                    /* Software CS needs to wait for the SPI sync pad status to be ready */
                    uint8 fsm = GFV_SPI_IRQ_STAT_SPI_FSM_ST(readl(bus->base + SPI_IRQ_STAT_OFF));

                    while ((fsm != SPI_FSM_WAIT_DATA_STA) && (fsm != SPI_FSM_M_STR_STA) &&
                           (fsm != SPI_FSM_IDLE_STA) && --timeout_cnt) {
                        fsm = GFV_SPI_IRQ_STAT_SPI_FSM_ST(readl(bus->base + SPI_IRQ_STAT_OFF));
                    }

                    if (timeout_cnt == 0) {
                        return -9;
                    }

                    /* Soft Cs mast active cs after spi mode ready */
                    if (dev_mode->flags & F_DEV_NSS_HIGH) {
                        Dio_WriteChannel((uint32)(uint32 *)bus->dev_mode, STD_HIGH);
                    } else {
                        Dio_WriteChannel((uint32)(uint32 *)bus->dev_mode, STD_LOW);
                    }

                    bus->state |= SPI_STATE_CS_ACTIVEED;
                }

                /* sample point delay  half sclk */
                uint32 reg_val = readl(bus->base + SPI_CTRL_OFF);

                if (dev_mode->flags & F_DEV_MISO_DELAY ) {
                    reg_val |= BM_SPI_CTRL_SAMPLE_POINT;
                } else {
                    reg_val &= (uint32)(~BM_SPI_CTRL_SAMPLE_POINT);
                }

                writel(reg_val, bus->base + SPI_CTRL_OFF);
            }
        }
    } else {
        if (update_cmd(bus)) {
            /* transmit finish soft state is not match to hw state so need recover hw state */
            return -10;
        }
    }

    if (mode == OP_MODE_NORMAL) {
        timeout_cnt = timeout;
        /* device mode aways block */
        SPI_DBG("Normal mode \n");
        SPI_DBG("tx:%p rx:%p\n", bus->async.ptxdata.val, bus->async.ptxdata.val);

        while ((bus->async.ptxdata.val && bus->async.tx_cur < bus->async.expect_len)  \
               || (bus->async.prxdata.val && bus->async.rx_cur < bus->async.expect_len)) {
            spi_write_remain(bus);
            spi_read_remain(bus);

            if ( !block && timeout_cnt ) {
                timeout_cnt--;
            }

            if (!block && !timeout_cnt)
                /* timeout exit */
                break;

            if (bus->state & SPI_STATE_IS_SLAVE) {
                uint32 sta_reg = readl(bus->base + SPI_IRQ_STAT_OFF);

                if (sta_reg & (BM_SPI_IRQ_STAT_RX_FIFO_OVR | BM_SPI_IRQ_STAT_TX_FIFO_UDR)) {
                    writel(sta_reg, bus->base + SPI_IRQ_STAT_OFF);
                    return -6;
                }
            }
        }

        SPI_DBG("w %d r %d l %d\n", bus->async.tx_cur, bus->async.rx_cur, bus->async.rx_cur);

        if (!timeout_cnt && !block ) {
            SPI_DBG("time out\n");
            return -7;
        }
    } else {
        SPI_DBG("Irq mode\n");

        /* slave need tx fifo not empty to avoid  too early udr */
        if (mode != OP_MODE_DMA) {
            spi_write_remain(bus);
        }

        setup_spi_irq(bus, mode);

        if (mode == OP_MODE_DMA) {
            SPI_DBG("DMA mode \n");

            if (bus->async.prxdata.val) {
                cnt = bus->async.expect_len - bus->async.rx_cur;
            } else {
                cnt = bus->async.expect_len - bus->async.tx_cur;
            }

            ret = setup_spi_dma(bus, bus->async.ptxdata.val, bus->async.prxdata.val, \
                                cnt, bus->async.width_type);

            if (ret >= 0) {
                enable_dma_req(bus);
            } else {
                /*
                    setup dma fail,need mask all irq avoid sync Mode enable irqs.
                */
                spi_irq_update_mask(bus, 0xFFFF, 0);
                return -8;
            }
        }
    }

    return 0;
}
/**
 * @description:
 * @param {mld_spi_module } *bus
 * @param {mld_spi_device*} dev
 * @param {uint32*} ptxdata
 * @param {uint32*} prxdata
 * @param {uint16} size
 * @param {uint32} timeout
 * @return {*}
 */
static sint32 sspi_transmission_ops(struct mld_spi_module  *bus, \
                                    struct mld_spi_device *dev, uint32 *ptxdata, uint32 *prxdata, \
                                    uint32 size, uint32 timeout, enum spi_ops_mode mode)
{
    sint32 cnt;
    struct mld_spi_async t_async;
    filling_async_cb(dev, ptxdata, prxdata, \
                     size, &t_async);
    cnt = sspi_vector_transmission_ops(bus, dev, &t_async, timeout, mode);
    return cnt;
}
/**
 * @description: Synchronously send and receive data,will be blocked
 * until the transfer is complete.
 * @param {void} *bus
 * @param {uint32*} ptxdata
 * @param {uint32*} prxdata
 * @param {uint32} timeout
 * @return {*}
 */
static sint32 sspi_transmit_receive(struct mld_spi_module  *bus, \
                                    struct mld_spi_device *dev, uint32 *ptxdata, uint32 *prxdata, \
                                    uint16 size, uint32 timeout)
{
    return sspi_transmission_ops(bus, dev, ptxdata, prxdata, size, timeout, OP_MODE_NORMAL);
}
/**
 * @description:Synchronously send and receive data,will return immediately.
 * @param {void} *bus
 * @param {uint32*} ptxdata
 * @param {uint32*} prxdata
 * @param {uint16} size
 * @return {*}
 */
static sint32 sspi_transmit_receive_irq(struct mld_spi_module  *bus,
                                        struct mld_spi_device *dev,
                                        uint32 *ptxdata, uint32 *prxdata,
                                        uint16 size)
{
    return sspi_transmission_ops(bus, dev, ptxdata, prxdata, size, 0, OP_MODE_IRQ);
}
/**
 * @description:Same as sspi_transmit_receive_irq() the difference is
 * that the data is handled by DMA
 * @param {void} *bus
 * @param {uint32*} ptxdata
 * @param {uint32*} prxdata
 * @param {uint16} size
 * @return {*}
 */
static sint32 sspi_transmit_receive_dma(struct mld_spi_module  *bus,
                                        struct mld_spi_device *dev, uint32 *ptxdata, uint32 *prxdata, uint16 size)
{
    return sspi_transmission_ops(bus, dev, ptxdata, prxdata, size, 0, OP_MODE_DMA);
}
/**
 * @description: Synchronously send and receive data,will be blocked
 * until the transfer is complete.
 * @param {void} *bus
 * @param {uint32*} ptxdata
 * @param {uint32*} prxdata
 * @param {uint32} timeout
 * @return {*}
 */
static sint32 sspi_vector_transmit_receive(struct mld_spi_module  *bus, \
        struct mld_spi_device *dev, struct mld_spi_async *vector, uint32 timeout)
{
    return sspi_vector_transmission_ops(bus, dev, vector, timeout, OP_MODE_NORMAL);
}
/**
 * @description:Synchronously send and receive data,will return immediately.
 * @param {void} *bus
 * @param {uint32*} ptxdata
 * @param {uint32*} prxdata
 * @param {uint16} size
 * @return {*}
 */
static sint32 sspi_vector_transmit_receive_irq(struct mld_spi_module  *bus, \
        struct mld_spi_device *dev, struct mld_spi_async *vector)
{
    return sspi_vector_transmission_ops(bus, dev, vector, 0, OP_MODE_IRQ);
}
/**
 * @description:Same as sspi_transmit_receive_irq() the difference is
 * that the data is handled by DMA
 * @param {void} *bus
 * @param {uint32*} ptxdata
 * @param {uint32*} prxdata
 * @param {uint16} size
 * @return {*}
 */
static sint32 sspi_vector_transmit_receive_dma(struct mld_spi_module  *bus,
        struct mld_spi_device *dev, struct mld_spi_async *vector)
{
    return sspi_vector_transmission_ops(bus, dev, vector, 0, OP_MODE_DMA);
}

/**
 * @description:
 * @param {mld_spi_module } *bus
 * @param {uint32*} prxdata
 * @param {uint16} size
 * @return {*}
 */
static sint32 sspi_get_status(struct mld_spi_module  *bus, uint32 *reg_vel)
{
    sint32 ret = 0;
    uint32 xfer = 0, max_read_cnt = SPI_FIFO_LEN;

    if (!bus)
        return -1;

    struct spi_bus_priv *bus_priv = (struct spi_bus_priv *)bus->priv;
    uint8 data_width_shift = bus->async.width_type;

    uint32 irq_s = readl(bus->base + SPI_IRQ_STAT_OFF);
    /* Mst fream end clr only on write cmd */
    *reg_vel = irq_s;
    *reg_vel &= (uint32)(~BM_SPI_IRQ_STAT_MST_FRM_END);
    *reg_vel &= (uint32)(~BM_SPI_IRQ_STAT_SLV_NSS_INVLD);
    *reg_vel &= (uint32)(~BM_SPI_IRQ_STAT_SLV_NSS_VLD);

    SPI_DBG("%p sta:%08x \n", bus, irq_s);

    if (bus->state & SPI_STATE_IS_SLAVE) {
        ret = SPI_TX_FIFO_WRITE | SPI_RX_FIFO_READ;
    }

    if (irq_s & BM_SPI_IRQ_STAT_FRM_DONE) {
        /* 2% Performance Improvement */
        ret |=  SPI_RX_FIFO_READ;
    } else {
        if (irq_s & BM_SPI_IRQ_STAT_RX_FIFO_PRE_FULL) {
            ret |= SPI_RX_FIFO_READ;
            SPI_DBG("rx_pre_full\n");
        }

        if (irq_s & BM_SPI_IRQ_STAT_TX_FIFO_PRE_EMPTY) {
            ret |= SPI_TX_FIFO_WRITE;
            SPI_DBG("tx_pre_empty\n");
        }
    }

    if (irq_s & BM_SPI_IRQ_STAT_TX_FIFO_UDR) {
        /* workaround spi slave mode will have a udr interrupt after the transfer is over for 1.0 and 1.1*/
        if (bus->state & SPI_STATE_DMA_TX && bus_priv->dma_ch_tx) {
            xfer = sdrv_dma_get_xfer_bytes(bus_priv->dma_ch_tx, false);
            bus->async.tx_cur = xfer >> data_width_shift;
        }

        if (bus->async.tx_cur < bus->async.expect_len) {
            ret |= SPI_TX_FIFO_UDR;
            SPI_DBG("Bus:%d UDF\n", bus->idx);
        }
    }

    if (irq_s & BM_SPI_IRQ_STAT_RX_FIFO_OVR) {
        ret |= SPI_RX_FIFO_OVR;
        SPI_DBG("Bus:%d OVR\n", bus->idx);
    }

    if ((bus->state & (SPI_STATE_IS_UNS_EN | SPI_STATE_IS_SLAVE))
        == (SPI_STATE_IS_UNS_EN | SPI_STATE_IS_SLAVE)) {
        if ((irq_s & BM_SPI_IRQ_STAT_SLV_NSS_VLD) && (bus->state & SPI_STATE_EN_VLD_CS)) {
            /*
                worksround step2:
                enable cs inactive irq disable cs active irq
            */
            spi_irq_update_mask(bus, BM_SPI_IRQ_MASK_SLV_NSS_VLD, BM_SPI_IRQ_MASK_SLV_NSS_INVLD);
            bus->state &= (uint32)(~SPI_STATE_EN_VLD_CS);
            bus->state |= SPI_STATE_CS_INVLD_EN;
            SPI_DBG("bus:%d cs vld;dis vld and enable invld\n", bus->idx);
        }

        else if (irq_s & BM_SPI_IRQ_STAT_SLV_NSS_INVLD && (bus->state & SPI_STATE_CS_INVLD_EN)) {

            /*
                worksround step3:
                disable cs inactive irq.
                handle spi reset and dma resource release related processing
            */
            spi_irq_update_mask(bus, BM_SPI_IRQ_MASK_SLV_NSS_INVLD, 0);
            bus->state &= (uint32)(~SPI_STATE_CS_INVLD_EN);

            if (bus_priv->dma_ch_rx) {
                disable_dma_req(bus, SPI_DMA_RX_ENABLE);
                dma_stop(bus_priv->dma_ch_rx);
                xfer = sdrv_dma_get_xfer_bytes(bus_priv->dma_ch_rx, true);
                arch_invalidate_cache_range((const void *)(uint32 *)bus->async.prxdata.val, ROUNDUP(xfer,
                                            CACHE_LINE));
                xfer >>= data_width_shift;
                bus->async.rx_cur = xfer;
                dma_free_chan(bus_priv->dma_ch_rx);
                bus_priv->dma_ch_rx = NULL_PTR;
            }

            if (bus_priv->dma_ch_tx) {
                disable_dma_req(bus, SPI_DMA_TX_ENABLE);
                dma_stop(bus_priv->dma_ch_tx);
                xfer = sdrv_dma_get_xfer_bytes(bus_priv->dma_ch_tx, true);
                dma_free_chan(bus_priv->dma_ch_tx);
                xfer >>= data_width_shift;
                bus->async.tx_cur = xfer;
                bus_priv->dma_ch_tx = NULL_PTR;
            }

            while (bus->bus_ops->spi_can_read(bus) && max_read_cnt) {
                spi_read_remain(bus);
                max_read_cnt--;
            }

            spi_slave_tx_curr_quirks(bus);

            /* updata expect_len and len make the transfer end */
            if (bus->state & SPI_STATE_BUSY_RX) {
                bus->async.cur_remian = 0;
                bus->async.expect_len = bus->async.rx_cur;
                bus->async.len = bus->async.expect_len;
            }

            if ((bus->state & (SPI_STATE_BUSY_RX | SPI_STATE_BUSY_TX)) == SPI_STATE_BUSY_TX) {
                bus->async.cur_remian = 0;
                bus->async.expect_len = bus->async.tx_cur;

            }

            bus->async.len = bus->async.expect_len;

            bus->state &= (uint32)(~SPI_STATE_IS_UNS_EN);
            SPI_DBG("bus:%d cs invld disable\n", bus->idx);
            /* slave mode undef size cs inactive mean that the transmition is over --- for irq  */
            ret |= SPI_RX_FIFO_READ | SPI_TX_FIFO_WRITE; /*  */
        }
    }

    /* dma error */
    ret |= bus_priv->dma_err;

    SPI_DBG("%s ret:%08x\n", __FUNCTION__, ret);
    return ret;
}

static void sspi_clr_irq_state(struct mld_spi_module  *bus, uint32 clr)
{
    writel(clr, bus->base + SPI_IRQ_STAT_OFF);
}

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#define SPI_START_SEC_CONST_UNSPECIFIED
#include "Spi_MemMap.h"

const struct mld_spi_ops semidrive_spi_bus_ops = {
    .spi_init = sspi_init,
    .spi_deinit = sspi_deinit,
    .spi_set_clock_polarity_and_phase = sspi_set_clock_polarity_and_phase,
    .spi_set_data_width =               sspi_set_data_width,
    .spi_set_baud_rate =                sspi_set_baud_rate,
    .spi_set_mode =                     sspi_set_mode,
    .spi_set_direction =                sspi_set_direction,
    .spi_set_ti_or_motorola_mode =      sspi_set_ti_or_motorola_mode,
    .spi_transmit_receive =             sspi_transmit_receive,
    .spi_transmit_receive_irq =         sspi_transmit_receive_irq,
    .spi_transmit_receive_dma =         sspi_transmit_receive_dma,
    .spi_vector_transmit_receive =      sspi_vector_transmit_receive,
    .spi_vector_transmit_receive_irq =  sspi_vector_transmit_receive_irq,
    .spi_vector_transmit_receive_dma =  sspi_vector_transmit_receive_dma,
    .spi_write_data =                   sspi_write,
    .spi_read_data =                    sspi_read,
    .spi_can_write =                    sspi_can_write,
    .spi_can_read =                     sspi_can_read,
    .spi_tx_finished =                  sspi_tx_finished,
    .spi_irq_state =                    sspi_get_status,
    .spi_setup_irq_mask =               sspi_setup_irq_mask,
    .spi_clr_irq_state =                sspi_clr_irq_state,
    .spi_set_predev_config =            sspi_set_predev_parameters,
    .spi_dma_stop =                     sspi_error_handle,
    .spi_transmit_stop =                sspi_recover,
};

#define SPI_STOP_SEC_CONST_UNSPECIFIED
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif
