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
 * @file  mld_spi.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Spi plugins.
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "mld_spi.h"
#include "arch.h"
#ifdef SPI_DMA
#include "sdrv_dmac.h"
#endif

#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

/**
 * @description:
 * @param {mld_spi_module} *bus
 * @return {*}
 */
sint32 mld_spi_init(struct mld_spi_module *bus)
{
    sint32 ret = 0;


    if (bus && bus->bus_ops && bus->bus_ops->spi_init) {
        bus->state = 0;
        ret = bus->bus_ops->spi_init(bus);

        if (!ret) {
            bus->state |= SPI_STATE_INITED;
        } else {
            SPI_DBG("%s error: %d\n", __FUNCTION__, ret);
            ret = -ERR_LOW_LEVEL;
        }
    } else {
        SPI_DBG("%s error no bus or ops \n", __FUNCTION__);
        ret = -ERR_NO_BUS;
    }

    return ret;
}
/**
 * @description:
 * @param {mld_spi_module} *bus
 * @return {*}
 */
sint32 mld_spi_deinit(struct mld_spi_module *bus)
{
    sint32 ret = 0;

    if (bus && bus->bus_ops && bus->bus_ops->spi_deinit) {
        bus->state = 0;

        ret = bus->bus_ops->spi_deinit(bus);

        if (ret != 0) {
            SPI_DBG("%s error: %d\n", __FUNCTION__, ret);
            ret = -ERR_LOW_LEVEL;
        }
    } else {
        SPI_DBG("%s error no bus or ops \n", __FUNCTION__);
        ret = -ERR_NO_BUS;
    }

    return ret;
}
/**
 * @description:
 * @param {mld_spi_module} *bus
 * @param {enum spi_tim_mode} mode
 * @return {*}
 */
sint32 mld_spi_set_clock_polarity_and_phase(struct mld_spi_module *bus, \
        enum spi_tim_mode mode)
{
    sint32 ret = 0;

    if (bus && bus->bus_ops && \
        bus->bus_ops->spi_set_clock_polarity_and_phase) {
        if (bus->state & SPI_STATE_INITED) {
            bus->bus_ops->spi_set_clock_polarity_and_phase(bus, mode);
        } else {
            ret = -ERR_NO_INIT;
        }
    } else {
        ret = -ERR_NO_BUS;
    }

    return ret;
}
/**
 * @description:
 * @param {mld_spi_module} *bus
 * @param {uint8} width
 * @return {*}
 */
sint32 mld_spi_set_data_width(struct mld_spi_module *bus, uint8 width)
{
    sint32 ret = 0;

    if (bus && bus->bus_ops && \
        bus->bus_ops->spi_set_data_width ) {
        if (bus->state & SPI_STATE_INITED) {
            ret = bus->bus_ops->spi_set_data_width(bus, width);

            if (ret) {
                SPI_DBG("%s error: %d\n", __FUNCTION__, ret);
                ret = -ERR_LOW_LEVEL;
            }
        } else {
            ret = -ERR_NO_INIT;
        }
    } else {
        ret = -ERR_NO_BUS;
    }

    return ret;
}
/**
 * @description:
 * @param {mld_spi_module} *bus
 * @param {uint32} rate
 * @return {*}
 */
sint32 mld_spi_set_baud_rate(struct mld_spi_module *bus, uint32 rate)
{
    sint32 ret = 0;

    if (bus && bus->bus_ops && \
        bus->bus_ops->spi_set_baud_rate ) {
        if (bus->state & SPI_STATE_INITED) {
            ret = bus->bus_ops->spi_set_baud_rate(bus, rate);

            if (ret) {
                SPI_DBG("%s error: %d\n", __FUNCTION__, ret);
                ret = -ERR_LOW_LEVEL;
            }
        } else {
            ret = -ERR_NO_INIT;
        }
    } else {
        ret = -ERR_NO_BUS;
    }

    return ret;
}
/**
 * @description:
 * @param {mld_spi_module} *bus
 * @param {enum spi_mode} mode
 * @return {*}
 */
sint32 mld_spi_set_mode(struct mld_spi_module *bus, enum spi_mode mode)
{
    sint32 ret = 0;

    if (bus && bus->bus_ops && \
        bus->bus_ops->spi_set_mode) {
        if (bus->state & SPI_STATE_INITED) {
            ret = bus->bus_ops->spi_set_mode(bus, mode);

            if (ret) {
                SPI_DBG("%s error: %d\n", __FUNCTION__, ret);
                ret = -ERR_LOW_LEVEL;
            }
        } else {
            ret = -ERR_NO_INIT;
        }
    } else {
        ret = -ERR_NO_BUS;
    }

    return ret;
}
/**
 * @description:abort a bus,this api must called in critical section.
 * @param {mld_spi_module} *bus
 * @return None
 */
void mld_spi_stop(struct mld_spi_module *bus)
{
    uint32 keep_bits;

    if (bus && bus->bus_ops && \
        bus->bus_ops->spi_dma_stop && bus->bus_ops->spi_transmit_stop) {
        if (bus->state & SPI_STATE_INITED) {
            bus->bus_ops->spi_dma_stop(bus);
            bus->bus_ops->spi_transmit_stop(bus);
            keep_bits = bus->state & SPI_STATE_IS_SLAVE;
            bus->state = SPI_STATE_INITED;
            bus->state |= keep_bits;
        }
    }
}
/**
 * @description:
 * @param {mld_spi_module} *bus
 * @param {enum spi_com_mode} dir
 * @return {*}
 */
sint32 mld_spi_set_direction(struct mld_spi_module *bus, \
                             enum spi_com_mode dir)
{
    sint32 ret = 0;

    if (bus && bus->bus_ops && \
        bus->bus_ops->spi_set_direction ) {
        if (bus->state & SPI_STATE_INITED) {
            ret = bus->bus_ops->spi_set_direction(bus, dir);

            if (ret) {
                SPI_DBG("%s error: %d\n", __FUNCTION__, ret);
                ret = -ERR_LOW_LEVEL;
            }
        } else {
            ret = -ERR_NO_INIT;
        }
    } else {
        ret = -ERR_NO_BUS;
    }

    return ret;
}
/**
 * @description:
 * @param {mld_spi_module} *bus
 * @param {enum spi_ssp_mode} mode
 * @return {*}
 */
sint32 mld_spi_set_ti_or_motorola_mode(struct mld_spi_module *bus, \
                                       enum spi_ssp_mode mode)
{
    sint32 ret = 0;

    if (bus && bus->bus_ops && \
        bus->bus_ops->spi_set_ti_or_motorola_mode ) {
        if (bus->state & SPI_STATE_INITED) {
            ret = bus->bus_ops->spi_set_ti_or_motorola_mode(bus, mode);

            if (ret) {
                SPI_DBG("%s error: %d\n", __FUNCTION__, ret);
                ret = -ERR_LOW_LEVEL;
            }
        }
    } else {
        ret = -ERR_NO_BUS;
    }

    return ret;
}
/**
 * @description:Duplex mode transmit receive
 * @param {mld_spi_device*} dev
 * @param {uint32*} ptxdata
 * @param {uint32*} prxdata
 * @param {uint16} size
 * @param {uint32} timeout
 * @return {*}
 */
sint32 mld_spi_transmit_receive(struct mld_spi_module *bus,
                                struct mld_spi_device *dev, uint32 *ptxdata,
                                uint32 *prxdata, uint16 size, uint32 timeout)
{
    sint32 ret = 0;

    if (dev && dev->bus) {
        bus = dev->bus;

        if (!timeout)
            return  -ERR_API_OPS;
    } else {
        timeout = 0;
    }

    if (!bus || !bus->bus_ops || \
        !bus->bus_ops->spi_transmit_receive) {
        ret = -ERR_NO_BUS;
    } else if (bus->state & SPI_STATE_INITED) {
        if (!timeout) {
            if (ptxdata)
                bus->state |= SPI_STATE_BUSY_TX;

            if (prxdata)
                bus->state |= SPI_STATE_BUSY_RX;
        }

        if (!(bus->state & BUS_BUSY_MASK)) {
            ret = bus->bus_ops->spi_transmit_receive(bus, dev, ptxdata, prxdata, \
                    size, timeout);

            if (ret < 0 ) {
                SPI_DBG("%s error: %d\n", __FUNCTION__, ret);
                ret = -ERR_LOW_LEVEL;
                bus->state &= (uint32)(~(BUS_BUSY_MASK | BUS_BUSY_IRQ_MASK | SPI_STATE_EXT_FLAGS));
            }
        } else {
            SPI_DBG("%s E:%d\n", __FUNCTION__, -ERR_BUSY);
            ret = -ERR_BUSY;
        }
    } else {
        SPI_DBG("%s E:%d\n", __FUNCTION__, -ERR_NO_INIT);
        ret = -ERR_NO_INIT;
    }

    return ret;
}
/**
 * @description:
 * @param {mld_spi_device*} dev
 * @param {uint32} *ptxdata
 * @param {uint32} *prxdata
 * @param {uint16} size
 * @return {*}
 */
sint32 mld_spi_transmit_receive_irq(struct mld_spi_module *bus, \
                                    struct mld_spi_device *dev, uint32 *ptxdata, \
                                    uint32 *prxdata, uint16 size)
{
    sint32 ret = 0;

    if (dev && dev->bus)
        bus = dev->bus;

    if (!bus || !bus->bus_ops || \
        !bus->bus_ops->spi_transmit_receive_irq) {
        ret = -ERR_NO_BUS;
    } else if (bus->state & SPI_STATE_INITED) {
        if (!(bus->state & BUS_BUSY_MASK)) {
            if (ptxdata)
                bus->state |= SPI_STATE_IRQ_TX | SPI_STATE_BUSY_TX;

            if (prxdata)
                bus->state |= SPI_STATE_IRQ_RX | SPI_STATE_BUSY_RX;

            ret = bus->bus_ops->spi_transmit_receive_irq(bus, dev, ptxdata, prxdata, size);

            if (ret < 0) {
                SPI_DBG("%s error: %d\n", __FUNCTION__, ret);
                ret = -ERR_LOW_LEVEL;
                bus->state &= (uint32)(~(BUS_BUSY_MASK | BUS_BUSY_IRQ_MASK | SPI_STATE_EXT_FLAGS));
            }
        } else {
            ret = -ERR_BUSY;
        }
    } else {
        ret = -ERR_NO_INIT;
    }

    return ret;
}
sint32 mld_spi_transmit_receive_dma(struct mld_spi_module *bus, \
                                    struct mld_spi_device *dev, uint32 *ptxdata, \
                                    uint32 *prxdata, uint16 size)
{
    sint32 ret = 0;

    if (dev && dev->bus)
        bus = dev->bus;

    if (!bus || !bus->bus_ops || \
        !bus->bus_ops->spi_transmit_receive_dma) {
        ret = -ERR_NO_BUS;
    } else if (bus->state & SPI_STATE_INITED) {
        if (!(bus->state & BUS_BUSY_MASK)) {
            if (ptxdata)
                bus->state |= SPI_STATE_BUSY_TX | SPI_STATE_DMA_TX;

            if (prxdata)
                bus->state |= SPI_STATE_BUSY_RX | SPI_STATE_DMA_RX;

            ret = bus->bus_ops->spi_transmit_receive_dma(bus, dev, ptxdata, prxdata, size);

            if (ret < 0) {
                SPI_DBG("%s error: %d\n", __FUNCTION__, ret);
                ret = -ERR_LOW_LEVEL;
                bus->state &= (uint32)(~(BUS_BUSY_MASK | BUS_BUSY_IRQ_MASK | SPI_STATE_EXT_FLAGS));
            }

            SPI_DBG("%s dma bus%p @%p len%d\n", __FUNCTION__, \
                    bus, bus->async.prxdata, bus->async.len);
        } else {
            ret = -ERR_BUSY;
            SPI_DBG("%s E:%d\n", __FUNCTION__, -ERR_BUSY);
        }
    } else {
        ret = -ERR_NO_INIT;
        SPI_DBG("%s E:%d\n", __FUNCTION__, -ERR_NO_INIT);
    }

    return ret;
}
/**
 * @description:vector transmission mode transmit receive
 * @param {mld_spi_device*} dev
 * @param {uint32*} ptxdata
 * @param {uint32*} prxdata
 * @param {uint16} size
 * @param {uint32} timeout
 * @return {*}
 */
sint32 mld_spi_vector_transmit_receive(struct mld_spi_module *bus,
                                       struct mld_spi_device *dev,
                                       struct mld_spi_async *vector)
{

    sint32 ret = 0;
    uint32 cur, timeout = TIMEOUT_WAIT_FIFO_EMPTY;
    struct mld_spi_async *tmp;

    if (dev && dev->bus)
        bus = dev->bus;

    if (!bus || !bus->bus_ops || \
        !bus->bus_ops->spi_vector_transmit_receive) {
        ret = -ERR_NO_BUS;
    } else if (bus->state & SPI_STATE_INITED) {
        if (!(bus->state & BUS_BUSY_MASK)) {
            /* async mode will check and clean it */
            if (vector->ptxdata.val)
                bus->state |= SPI_STATE_BUSY_TX;

            if (vector->prxdata.val)
                bus->state |= SPI_STATE_BUSY_RX;

            vector->priv = dev;
            vector->expect_len =  0;
            tmp = vector;

            do {
                ret = bus->bus_ops->spi_vector_transmit_receive(bus, dev,
                        tmp, bus->state & SPI_STATE_IS_SLAVE ? 0 : tmp->len * TIMEOUT_SYNC_ONE_ITEM);

                if (ret >= 0) {
                    if (tmp->prxdata.val)
                        cur = bus->async.rx_cur;
                    else
                        cur = bus->async.tx_cur;

                    if (cur < bus->async.len) {
                        /* update remain and except */
                        bus->async.cur_remian = bus->async.len - cur;
                        tmp = &bus->async;
                    } else {
                        tmp = bus->async.next;

                        if (tmp)
                            tmp->expect_len =  0;
                    }
                }
            } while (tmp != NULL && ret >= 0);

            /*
                In software CS mode, if you do not wait for the FIFO data transmission to complete,\
              the CS pin may be prematurely inactive.
            */
            if (!ret && !(bus->state & SPI_STATE_IS_SLAVE))
                while (!bus->bus_ops->spi_tx_finished(bus) && --timeout);

            if (ret < 0 || timeout == 0) {
                SPI_DBG("%s error: %d\n", __FUNCTION__, ret);
                bus->state &= (uint32)(~(BUS_BUSY_MASK | BUS_BUSY_IRQ_MASK | SPI_STATE_EXT_FLAGS));
                ret = -ERR_LOW_LEVEL;
            }

            sync_finished_callback(bus);
        } else {
            SPI_DBG("%s E:%d\n", __FUNCTION__, -ERR_BUSY);
            ret = -ERR_BUSY;
        }
    } else {
        SPI_DBG("%s E:%d\n", __FUNCTION__, -ERR_NO_INIT);
        ret = -ERR_NO_INIT;
    }

    return ret;
}
/**
 * @description:vector transmission mode transmit receive
 * @param {mld_spi_device*} dev
 * @param {uint32*} ptxdata
 * @param {uint32*} prxdata
 * @param {uint16} size
 * @param {uint32} timeout
 * @return {*}
 */
sint32 mld_spi_vector_transmit_receive_irq(struct mld_spi_module *bus,
        struct mld_spi_device *dev, \
        struct mld_spi_async *vector)
{
    sint32 ret = 0;

    if (dev && dev->bus) {
        bus = dev->bus;
    }

    if (!bus || !bus->bus_ops || \
        !bus->bus_ops->spi_vector_transmit_receive_irq) {
        ret = -ERR_NO_BUS;
    } else if (bus->state & SPI_STATE_INITED) {
        if (!(bus->state & BUS_BUSY_MASK)) {
            if (vector->ptxdata.val)
                bus->state |= SPI_STATE_BUSY_TX | SPI_STATE_IRQ_TX;

            if (vector->prxdata.val)
                bus->state |= SPI_STATE_BUSY_RX | SPI_STATE_IRQ_RX;

            vector->priv = dev;
            vector->expect_len =  0;
            ret = bus->bus_ops->spi_vector_transmit_receive_irq(bus, dev, vector);

            if (ret < 0) {
                bus->state &= (uint32)(~(BUS_BUSY_MASK | BUS_BUSY_IRQ_MASK | SPI_STATE_EXT_FLAGS));
                SPI_DBG("%s error: %d\n", __FUNCTION__, ret);
                ret = -ERR_LOW_LEVEL;
            } else {
                /* async mode will check and clean it */
            }
        } else {
            SPI_DBG("%s E:%d\n", __FUNCTION__, -ERR_BUSY);
            ret = -ERR_BUSY;
        }
    } else {
        SPI_DBG("%s E:%d\n", __FUNCTION__, -ERR_NO_INIT);
        ret = -ERR_NO_INIT;
    }

    return ret;
}
/**
 * @description:vector transmission mode transmit receive
 * @param {mld_spi_device*} dev
 * @param {uint32*} ptxdata
 * @param {uint32*} prxdata
 * @param {uint16} size
 * @param {uint32} timeout
 * @return {*}
 */
sint32 mld_spi_vector_transmit_receive_dma(struct mld_spi_module *bus,
        struct mld_spi_device *dev, \
        struct mld_spi_async *vector)
{
    sint32 ret = 0;

    if (dev && dev->bus) {
        bus = dev->bus;
    }

    if (!bus || !bus->bus_ops || \
        !bus->bus_ops->spi_vector_transmit_receive_dma) {
        ret = -ERR_NO_BUS;
    } else if (bus->state & SPI_STATE_INITED) {
        if (!(bus->state & BUS_BUSY_MASK)) {
            /* async mode will check and clean it */
            if (vector->ptxdata.val)
                bus->state |= SPI_STATE_BUSY_TX | SPI_STATE_DMA_TX;

            if (vector->prxdata.val)
                bus->state |= SPI_STATE_BUSY_RX | SPI_STATE_DMA_RX;

            vector->priv = dev;
            vector->expect_len =  0;
            ret = bus->bus_ops->spi_vector_transmit_receive_dma(bus, dev, vector);

            if (ret < 0) {
                bus->state &= (uint32)(~(BUS_BUSY_MASK | BUS_BUSY_DMA_MASK | SPI_STATE_EXT_FLAGS));
                SPI_DBG("%s error: %d\n", __FUNCTION__, ret);
                ret = -ERR_LOW_LEVEL;
            }
        } else {
            SPI_DBG("%s E:%d\n", __FUNCTION__, -ERR_BUSY);
            ret = -ERR_BUSY;
        }
    } else {
        SPI_DBG("%s E:%d\n", __FUNCTION__, -ERR_NO_INIT);
        ret = -ERR_NO_INIT;
    }

    return ret;
}

static void mld_spi_bus_error_handle(struct mld_spi_module *bus)
{
    bus->state &= (uint32)(~BUS_BUSY_STATUS_MASK);
    bus->state &= (uint32)(~SPI_STATE_EXT_FLAGS);
    bus->state |= SPI_STATE_ERR_END;
    bus->bus_ops->spi_setup_irq_mask(bus, \
                                     SPI_TX_WRITE_REQ | SPI_RX_READ_REQ | \
                                     SPI_TRASPORT_FINISH | SPI_CS_INVLD_REQ);
    bus->bus_ops->spi_dma_stop(bus);
}

static void mld_spi_polling(struct mld_spi_module *bus)
{
    sint32 ret = -1;
    sint32 ops_ret, timeout = TIMEOUT_WAIT_FIFO_EMPTY;
    uint32 irq_state;
    struct mld_spi_async *inherit;

    if (!(bus->state & SPI_STATE_INITED)) {
        SPI_DBG("%s error not inited\n", __FUNCTION__);
        return ;
    }

    if (bus->bus_ops && bus->bus_ops->spi_irq_state) {
        /* dam error will stained */
        ret = bus->bus_ops->spi_irq_state(bus, &irq_state);
    }

    if (ret < 0) {
        SPI_DBG("%s error: %d\n", __FUNCTION__, ret);
    } else {
        if (bus->state & BUS_BUSY_DMA_MASK) {
            ret |= SPI_TX_FIFO_WRITE | SPI_RX_FIFO_READ;
        }

        /* Slave Mode OverFlow or UnderFlow error */
        if (ret & BUS_FIFO_STATE_ERR_MASK) {
            mld_spi_bus_error_handle(bus);

            if (bus->bus_ops->spi_clr_irq_state)
                bus->bus_ops->spi_clr_irq_state(bus, irq_state);

            return ;
        }

        if (bus->state & SPI_STATE_BUSY_TX && \
            (ret & SPI_TX_FIFO_WRITE)) {
            if ((bus->async.tx_cur < bus->async.expect_len) && \
                !(bus->state & SPI_STATE_DMA_TX)) {
                /* feed data to hw ,dma mode soft do not need do this */
                spi_write_remain(bus);
            }

            if (bus->async.tx_cur >= bus->async.expect_len) {
                /* tx except satisfy ,If you need to receive,
                    just turn off the send trigger, otherwise all turn off*/
                if (bus->state & SPI_STATE_BUSY_RX)
                    bus->bus_ops->spi_setup_irq_mask(bus, \
                                                     SPI_TX_WRITE_REQ);
                else
                    bus->bus_ops->spi_setup_irq_mask(bus, \
                                                     SPI_TX_WRITE_REQ | SPI_TRASPORT_FINISH | SPI_CS_INVLD_REQ);

                if (bus->async.expect_len == bus->async.len) {
                    /* vector item end check next need to transmit ? */
                    if (!bus->async.next) {
                        /*
                            vector end and not have others need to process
                            ,Tx Finished
                        */
                        bus->state &= (uint32)(~SPI_STATE_DMA_TX);
                        bus->state &= (uint32)(~SPI_STATE_IRQ_TX);
                        bus->state &= (uint32)(~SPI_STATE_BUSY_TX);
                        bus->state &= (uint32)(~SPI_STATE_CS_ACTIVEED);

                        if (!(bus->state & (SPI_STATE_IS_SLAVE | SPI_STATE_BUSY_RX))) {
                            while (!bus->bus_ops->spi_tx_finished(bus) && --timeout);

                            if (timeout == 0 ) {
                                mld_spi_bus_error_handle(bus);
                            }
                        }

                        SPI_DBG("%s bus%p tx pass\n", __FUNCTION__, bus);
                    } else {
                        /* vector next */
                        if (bus->state & SPI_STATE_BUSY_RX) {
                            /* do not start a new transmit, Should be started
                                when the reception is complete */
                        } else {
                            /* inherit from last item dev */
                            inherit = bus->async.next;
                            inherit->priv = bus->async.priv;
                            inherit->expect_len = 0;

                            if (bus->state & BUS_BUSY_DMA_MASK) {
                                update_bus_state(bus);
                                ops_ret = bus->bus_ops->spi_vector_transmit_receive_dma(\
                                          bus, bus->async.priv, bus->async.next);

                                if (ops_ret < 0) {
                                    mld_spi_bus_error_handle(bus);
                                    return ;
                                }
                            } else {
                                update_bus_state(bus);
                                ops_ret = bus->bus_ops->spi_vector_transmit_receive_irq(\
                                          bus, bus->async.priv, bus->async.next);

                                if (ops_ret < 0) {
                                    mld_spi_bus_error_handle(bus);
                                    return ;
                                }
                            }
                        }
                    }
                } else {
                    /* vector item continue  */
                    if (bus->state & SPI_STATE_BUSY_RX) {
                        /* do not start a new transmit, Should be started
                            when the reception is complete */
                    } else {
                        bus->async.cur_remian = bus->async.len - bus->async.tx_cur;

                        if (bus->state & BUS_BUSY_DMA_MASK) {
                            ops_ret = bus->bus_ops->spi_vector_transmit_receive_dma(\
                                      bus, bus->async.priv, &bus->async);

                            if (ops_ret < 0) {
                                mld_spi_bus_error_handle(bus);
                                SPI_DBG("ops_ret %d\n", ops_ret);
                            }
                        } else {
                            ops_ret = bus->bus_ops->spi_vector_transmit_receive_irq(\
                                      bus, bus->async.priv, &bus->async);

                            if (ops_ret < 0) {
                                mld_spi_bus_error_handle(bus);
                                SPI_DBG("ops_ret %d\n", ops_ret);
                            }

                        }
                    }
                }
            }
        }

        if (bus->state & SPI_STATE_BUSY_RX && \
            (ret & SPI_RX_FIFO_READ)) {
            /* check next need to transmit ? */
            if ((bus->async.rx_cur < bus->async.expect_len) && \
                !(bus->state & SPI_STATE_DMA_RX)) {
                /* read data to hw ,dma mode do not need to do anything */
                spi_read_remain(bus);
            }

            /* !!! Cannot be implemented using if-else must independent to check  */
            if (bus->async.rx_cur == bus->async.expect_len) {
                /* rx except satisfy , all turn off*/
                bus->bus_ops->spi_setup_irq_mask(bus, \
                                                 SPI_TX_WRITE_REQ | SPI_RX_READ_REQ | \
                                                 SPI_TRASPORT_FINISH | SPI_CS_INVLD_REQ);

                if (bus->async.expect_len == bus->async.len) {
                    /* vector item end check next need to transmit ? */
                    if (!bus->async.next) {
                        /*
                            vector end and not have others  need to process
                            ,Rx Finished
                        */
                        bus->state &= (uint32)(~SPI_STATE_DMA_RX);
                        bus->state &= (uint32)(~SPI_STATE_IRQ_RX);
                        bus->state &= (uint32)(~SPI_STATE_BUSY_RX);
                        bus->state &= (uint32)(~SPI_STATE_CS_ACTIVEED);
                        SPI_DBG("%s bus%p rx pass\n", __FUNCTION__, bus);
                    } else {
                        inherit = bus->async.next;
                        inherit->priv = bus->async.priv;
                        inherit->expect_len = 0;

                        /* vector next */
                        if (bus->state & BUS_BUSY_DMA_MASK) {
                            update_bus_state(bus);
                            ops_ret = bus->bus_ops->spi_vector_transmit_receive_dma(\
                                      bus, bus->async.priv, bus->async.next);

                            if (ops_ret < 0) {
                                mld_spi_bus_error_handle(bus);
                                return ;
                            }
                        } else {
                            update_bus_state(bus);
                            ops_ret = bus->bus_ops->spi_vector_transmit_receive_irq(\
                                      bus, bus->async.priv, bus->async.next);

                            if (ops_ret < 0) {
                                mld_spi_bus_error_handle(bus);
                                return ;
                            }
                        }
                    }
                } else {
                    bus->async.cur_remian = bus->async.len - bus->async.rx_cur;

                    /* vector item continue  */
                    if (bus->state & BUS_BUSY_DMA_MASK) {
                        ops_ret = bus->bus_ops->spi_vector_transmit_receive_dma(\
                                  bus, bus->async.priv, &bus->async);

                        if (ops_ret < 0) {
                            mld_spi_bus_error_handle(bus);
                            SPI_DBG("ops_ret %d\n", ops_ret);
                        }
                    } else {
                        ops_ret = bus->bus_ops->spi_vector_transmit_receive_irq(\
                                  bus, bus->async.priv, &bus->async);

                        if (ops_ret < 0) {
                            mld_spi_bus_error_handle(bus);
                            SPI_DBG("ops_ret %d\n", ops_ret);
                        }
                    }

                }
            }
        }

        if (bus->bus_ops->spi_clr_irq_state)
            bus->bus_ops->spi_clr_irq_state(bus, irq_state);
    }

    (void)ops_ret;
}
/**
 * @description:
 * @param {mld_spi_module} *bus
 * @param {uint32*} prxdata
 * @param {uint16} size
 * @return {*}
 */
sint32 mld_spi_async_polling(struct mld_spi_module *bus)
{
    sint32 ret = -1;

    if (bus->state & SPI_STATE_INITED) {
        if (bus->state & BUS_BUSY_ASYNC_MASK)
            mld_spi_polling(bus);

        if (bus->state & BUS_BUSY_ASYNC_MASK)
            ret = 1;
        else
            ret = 0;
    } else {
        ret = -ERR_NO_INIT;
        SPI_DBG("%s E:%d\n", __FUNCTION__, -ERR_NO_INIT);
    }

    return ret;
}

int mld_spi_handle_irq(uint32 irq, void *arg)
{
    struct mld_spi_module *bus = (struct mld_spi_module *)arg;

    if (bus->state & SPI_STATE_INITED) {
        mld_spi_polling(bus);
    }

    return 0;
}

sint32 spi_write_remain(struct mld_spi_module *bus)
{
    uint32 remain;
    uint32 len = 0;

    if (!bus)
        return -1;

    if (!bus->async.ptxdata.val)
        return 0;

    remain = bus->async.expect_len -  bus->async.tx_cur;

    if (remain <= 0)
        return 0;

    if (bus->bus_ops->spi_can_write && bus->bus_ops->spi_write_data) {
        while (remain && bus->bus_ops->spi_can_write(bus)) {
            if (bus->async.width_type == SPI_DATA_WIDTH_BYTE) {
                bus->bus_ops->spi_write_data(bus, *(bus->async.ptxdata.u8_ptr + bus->async.tx_cur));
            } else if (bus->async.width_type == SPI_DATA_WIDTH_HALF_WORD) {
                bus->bus_ops->spi_write_data(bus, *(bus->async.ptxdata.u16_ptr + bus->async.tx_cur));
            } else {
                bus->bus_ops->spi_write_data(bus, *(bus->async.ptxdata.u32_ptr + bus->async.tx_cur));
            }

            bus->async.tx_cur++;
            len++;
            remain--;
        }
    } else {
        return -1;
    }

    SPI_DBG("%s bus %d %d\n", __FUNCTION__, bus->idx, len);
    return len;
}

sint32 spi_read_remain(struct mld_spi_module *bus)
{
    uint32 remain;
    uint32 len = 0;

    if (!bus)
        return -1;

    if (!bus->async.prxdata.val)
        return 0;

    remain = bus->async.expect_len -  bus->async.rx_cur;

    if ( remain <= 0)
        return 0;

    if (bus->bus_ops->spi_read_data && bus->bus_ops->spi_can_read) {
        while (remain && bus->bus_ops->spi_can_read(bus)) {
            if (bus->async.width_type == SPI_DATA_WIDTH_BYTE) {
                *(bus->async.prxdata.u8_ptr + bus->async.rx_cur) = bus->bus_ops->spi_read_data(bus);
            } else if (bus->async.width_type == SPI_DATA_WIDTH_HALF_WORD) {
                *(bus->async.prxdata.u16_ptr + bus->async.rx_cur) = bus->bus_ops->spi_read_data(bus);
            } else {
                *(bus->async.prxdata.u32_ptr + bus->async.rx_cur) = bus->bus_ops->spi_read_data(bus);
            }

            bus->async.rx_cur++;
            len++;
            remain--;
        }
    } else {
        return -1;
    }

    SPI_DBG("%s bus %d %d\n", __FUNCTION__, bus->idx, len);
    return len;
}

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif
