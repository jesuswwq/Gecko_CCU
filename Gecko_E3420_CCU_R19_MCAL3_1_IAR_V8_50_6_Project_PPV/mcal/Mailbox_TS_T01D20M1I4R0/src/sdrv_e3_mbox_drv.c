/**
 * @file sdrv_e3_mbox_drv.c
 *
 * Copyright (c) 2021 Semidrive Semiconductor.
 * All rights reserved.
 *
 * Description: mbox driver.
 *
 * Revision History:
 * -----------------
 */

#include "sdrv_e3_mbox_drv.h"
#include <sdrv_mbox.h>
#include <irq.h>
#include <spinlock.h>
#include "_assert.h"
#include "bits.h"
#include "Mcu.h"
#include "mbox_core.h"
#include "mini_libc.h"

#define MAILBOX_DBG(...)
#define EXTRA_FMT   "sdrv_mbox:"

#define MAILBOX_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Mailbox_MemMap.h"

#define MAILBOX_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Mailbox_MemMap.h"

extern struct mailbox_handle_cb core_handle_cb[MAX_CPUS_SUPPORT];

static void sdrv_mbox_init(mbox_dev_t *dev);
static boolean sdrv_mbox_startup(mbox_chan_t *chan, void *priv_data);
static void sdrv_mbox_shutdown(mbox_chan_t *chan);
static int sdrv_mbox_send(mbox_chan_t *chan, uint8 *data, uint32 len);
static int sdrv_mbox_send_mask(mbox_chan_t *chan, uint8 *data, uint32 len, uint16 dstmask);
static uint8 *sdrv_mbox_alloc_buffer(mbox_chan_t *chan, uint32 len);
static int sdrv_mbox_send_nocopy(mbox_chan_t *chan, uint8 *data, uint32 len);
static int sdrv_mbox_send_nobuf(mbox_chan_t *chan, uint8 *data, uint32 len);
static void sdrv_mbox_cancel_send(mbox_chan_t *chan);
static boolean sdrv_mbox_tx_done(mbox_chan_t *chan, uint32 timeout);

#define MAILBOX_START_SEC_VAR_INIT_UNSPECIFIED
#include "Mailbox_MemMap.h"

static mbox_ops_t g_sdrv_mbox_ops = {
    .init = sdrv_mbox_init,
    .startup = sdrv_mbox_startup,
    .shutdown = sdrv_mbox_shutdown,
    .send = sdrv_mbox_send,
    .send_mask = sdrv_mbox_send_mask,
    .alloc_buf = sdrv_mbox_alloc_buffer,
    .send_nocopy = sdrv_mbox_send_nocopy,
    .send_nobuf = sdrv_mbox_send_nobuf,
    .cancel_send = sdrv_mbox_cancel_send,
    .tx_done = sdrv_mbox_tx_done,
};

#define MAILBOX_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Mailbox_MemMap.h"

#define MAILBOX_START_SEC_CODE
#include "Mailbox_MemMap.h"

/**
 * @brief sdrv mbox alloc message
 *
 * @param[in] sdrv_mbox sdrv mbox
 * return alloc msg id
 */
static int sdrv_mbox_alloc_message(sdrv_mbox_dev_t *sdrv_mbox)
{
    uint8 msg_id;

    for (msg_id = 0; msg_id < SDRV_MBOX_MSG_NUM; msg_id++) {
        if (!BIT_SET(sdrv_mbox->msg_bitmap, msg_id)) {
            sdrv_mbox->msg_bitmap |= (1 << msg_id);
            return msg_id;
        }
    }

    return -1;
}

/**
 * @brief sdrv mbox free message
 *
 * @param[in] sdrv_mbox sdrv mbox
 * @param[in] msg_id msg id
 */
static void sdrv_mbox_free_message(sdrv_mbox_dev_t *sdrv_mbox, uint8 msg_id)
{
    sdrv_mbox->msg_bitmap &= ~(1 << msg_id);
}

/**
 * @brief sdrv mbox receive data
 *
 * @param[in] dev mbox dev
 * @param[in] rproc rproc id
 * @param[in] msg_id msg id
 */
static void sdrv_mbox_receive(mbox_dev_t *dev, uint8 rproc, uint8 msg_id)
{
    sdrv_mbox_dev_t *sdrv_mbox = dev->priv;
    sdrv_mbox_chan_t *sdrv_chan;
    uint64 short_data;
    uint32 short_msg;
    uint16 mb_len;
    uint8 mbm;
    uint8 *rx_buf = NULL;
    int chan_id;

    short_data = sdrv_mbox_lld_get_short_msg(dev->base, rproc, msg_id);
    mb_len = sdrv_mbox_lld_get_msg_head(dev->base, rproc, msg_id, &mbm);

    if (mbm != 0) {

#if CONFIG_MBOX_FLUSH_CACHE
        rx_buf = sdrv_mbox_lld_get_rxbuf(dev->mem_base, rproc, msg_id);
        arch_invalidate_cache_range((volatile uint32)rx_buf, mb_len);
#else
        rx_buf = sdrv_mbox_lld_get_rxbuf(dev->mem_base, rproc, msg_id);
#endif

    }

    for (chan_id = 0; chan_id < SDRV_MBOX_CHN_NUM; chan_id++) {
        sdrv_chan = &sdrv_mbox->priv[chan_id];

        if (sdrv_chan->used == TRUE &&
            (sdrv_chan->src_addr == MBOX_ADDR_RAW)) {
            if (rx_buf) {
                mbox_received(&dev->chan[chan_id], rx_buf, mb_len, rproc);
            } else {
                short_msg = (uint32)short_data;
                mbox_received(&dev->chan[chan_id], (uint8 *)&short_msg, mb_len, rproc);
            }
        }
    }
}

/**
 * @brief sdrv mbox channel irq handler
 *
 * @param[in] irq irq number
 * @param[in] arg irq arg
 * return irq handler result
 */
#if defined(NON_AUTOSAR_STANDARD_IRQ_HANDLER)
static int sdrv_mbox_irq_handler(uint32 irq, void *arg)
#else
static ISR(sdrv_mbox_irq_handler)
#endif
{
#if defined(NON_AUTOSAR_STANDARD_IRQ_HANDLER)
    mbox_dev_t *dev = arg;
#else
    mbox_dev_t *dev = core_handle_cb[Mcu_GetCoreID()].mbox_dev;
#endif
    sdrv_mbox_dev_t *sdrv_mbox;
    irq_state_t flag;
    uint32 state;
    uint8 rproc, msg_mask, msg_id;

    ASSERT(dev);

    sdrv_mbox = dev->priv;

    flag = spin_lock_irqsave(&sdrv_mbox->lock);

    state = sdrv_mbox_lld_get_status(dev->base);

    for (rproc = 0; rproc < SDRV_MBOX_RPROC_NUM; rproc++) {
        msg_mask = 0xf & (state >> (rproc << 2));

        while (msg_mask) {
            msg_id = ffs32(msg_mask) - 1;
            msg_mask &= (msg_mask - 1);

            MAILBOX_DBG("recv: %d msg: %d\n", rproc, msg_id);
            sdrv_mbox_receive(dev, rproc, msg_id);
            sdrv_mbox_lld_ack(dev->base, rproc, msg_id);
            MAILBOX_DBG("ack: %d msg: %d\n", rproc, msg_id);
        }
    }

    spin_unlock_irqrestore(&sdrv_mbox->lock, flag);

#if defined(NON_AUTOSAR_STANDARD_IRQ_HANDLER)
    return 0;
#endif
}

/**
 * @brief sdrv mbox channel send short data
 *
 * @param[in] chan mbox channel
 * @param[in] data data ptr
 * @param[in] len data len
 * return send result
 */
static int sdrv_mbox_send_nobuf(mbox_chan_t *chan, uint8 *data, uint32 len)
{
    mbox_dev_t *dev = chan->dev;
    sdrv_mbox_dev_t *sdrv_mbox = dev->priv;
    sdrv_mbox_chan_t *sdrv_chan = chan->priv;
    uint64 short_msg = 0;
    irq_state_t flag;
    int msg_id;

    if (len > SDRV_MBOX_SHORT_BUF_LEN) {
        MAILBOX_DBG("send short message length too large\n");
        return -1;
    }

    flag = spin_lock_irqsave(&sdrv_mbox->lock);

    msg_id = sdrv_mbox_alloc_message(sdrv_mbox);

    if (msg_id < 0) {
        spin_unlock_irqrestore(&sdrv_mbox->lock, flag);
        MAILBOX_DBG("no message buffer\n");
        return -1;
    }

    sdrv_chan->msg_id = (uint8)msg_id;

    sdrv_mbox_lld_fill_msg_head(dev->base, sdrv_chan->msg_id,
                                (1 << sdrv_chan->rproc), 0, len);

    for (uint8 i = 0; i < len; i++) {
        short_msg |= ((uint64) data[i] << (i * 8));
    }

    short_msg |= (uint64)sdrv_chan->src_addr << 32;
    short_msg |= (uint64)sdrv_chan->dest_addr << 48;

    sdrv_mbox_lld_fill_short_msg(dev->base, short_msg);

    sdrv_mbox_lld_send(dev->base, sdrv_chan->msg_id);

    spin_unlock_irqrestore(&sdrv_mbox->lock, flag);

    return 0;
}
/**
 * @brief sdrv mbox channel send data use message buf
 *
 * @param[in] chan mbox channel
 * @param[in] data data ptr
 * @param[in] len data len
 * return send result
 */
static int sdrv_mbox_send_mask(mbox_chan_t *chan, uint8 *data, uint32 len, uint16 dstmask)
{
    mbox_dev_t *dev = chan->dev;
    sdrv_mbox_dev_t *sdrv_mbox = dev->priv;
    sdrv_mbox_chan_t *sdrv_chan = chan->priv;
    uint8 *tx_buf;
    irq_state_t flag;
    int msg_id;

    if (len > SDRV_MBOX_BANK_LEN) {
        MAILBOX_DBG("send message length too large\n");
        return -1;
    }

    flag = spin_lock_irqsave(&sdrv_mbox->lock);

    msg_id = sdrv_mbox_alloc_message(sdrv_mbox);

    if (msg_id < 0) {
        spin_unlock_irqrestore(&sdrv_mbox->lock, flag);
        MAILBOX_DBG("no message buffer\n");
        return -1;
    }

    sdrv_chan->msg_id = (uint8)msg_id;

    sdrv_mbox_lld_fill_msg_head(dev->base, sdrv_chan->msg_id,
                                dstmask, (1 << sdrv_chan->msg_id), len);

    sdrv_mbox_lld_fill_short_msg(dev->base,
                                 (((uint64)sdrv_chan->dest_addr << 48) | ((uint64)sdrv_chan->src_addr << 32)));

#if CONFIG_MBOX_FLUSH_CACHE
    tx_buf = sdrv_mbox_lld_get_txbuf(dev->mem_base, sdrv_chan->msg_id);
    memcpy(tx_buf, data, len);
    arch_clean_cache_range((volatile uint32)tx_buf, len);
#else
    tx_buf = sdrv_mbox_lld_get_txbuf(dev->mem_base, sdrv_chan->msg_id);
    memcpy(tx_buf, data, len);
#endif

    sdrv_mbox_lld_send(dev->base, sdrv_chan->msg_id);

    spin_unlock_irqrestore(&sdrv_mbox->lock, flag);

    return 0;
}

/**
 * @brief sdrv mbox channel send data use message buf
 *
 * @param[in] chan mbox channel
 * @param[in] data data ptr
 * @param[in] len data len
 * return send result
 */
static int sdrv_mbox_send(mbox_chan_t *chan, uint8 *data, uint32 len)
{
    mbox_dev_t *dev = chan->dev;
    sdrv_mbox_dev_t *sdrv_mbox = dev->priv;
    sdrv_mbox_chan_t *sdrv_chan = chan->priv;
    uint8 *tx_buf;
    irq_state_t flag;
    int msg_id;

    if (len > SDRV_MBOX_BANK_LEN) {
        MAILBOX_DBG("send message length too large\n");
        return -1;
    }

    flag = spin_lock_irqsave(&sdrv_mbox->lock);

    msg_id = sdrv_mbox_alloc_message(sdrv_mbox);

    if (msg_id < 0) {
        spin_unlock_irqrestore(&sdrv_mbox->lock, flag);
        MAILBOX_DBG("no message buffer\n");
        return -1;
    }

    sdrv_chan->msg_id = (uint8)msg_id;

    sdrv_mbox_lld_fill_msg_head(dev->base, sdrv_chan->msg_id,
                                (1 << sdrv_chan->rproc),
                                (1 << sdrv_chan->msg_id), len);

    sdrv_mbox_lld_fill_short_msg(dev->base,
                                 (((uint64)sdrv_chan->dest_addr << 48) | ((uint64)sdrv_chan->src_addr << 32)));

#if CONFIG_MBOX_FLUSH_CACHE
    tx_buf = sdrv_mbox_lld_get_txbuf(dev->mem_base, sdrv_chan->msg_id);
    memcpy(tx_buf, data, len);
    arch_clean_cache_range((volatile uint32)tx_buf, len);
#else
    tx_buf = sdrv_mbox_lld_get_txbuf(dev->mem_base, sdrv_chan->msg_id);
    memcpy(tx_buf, data, len);
#endif

    sdrv_mbox_lld_send(dev->base, sdrv_chan->msg_id);

    spin_unlock_irqrestore(&sdrv_mbox->lock, flag);

    return 0;
}

/**
 * @brief sdrv mbox channel alloc buffer
 *
 * @param[in] chan mbox channel
 * @param[in] len data len
 * return buffer address
 */
static uint8 *sdrv_mbox_alloc_buffer(mbox_chan_t *chan, uint32 len)
{
    mbox_dev_t *dev = chan->dev;
    sdrv_mbox_dev_t *sdrv_mbox = dev->priv;
    sdrv_mbox_chan_t *sdrv_chan = chan->priv;
    uint8 *tx_buf;
    irq_state_t flag;
    int msg_id;

    if (len > SDRV_MBOX_BANK_LEN) {
        MAILBOX_DBG("send message length too large\n");
        return NULL;
    }

    flag = spin_lock_irqsave(&sdrv_mbox->lock);

    msg_id = sdrv_mbox_alloc_message(sdrv_mbox);

    if (msg_id < 0) {
        spin_unlock_irqrestore(&sdrv_mbox->lock, flag);
        MAILBOX_DBG("no message buffer\n");
        return NULL;
    }

    sdrv_chan->msg_id = (uint8)msg_id;

    sdrv_mbox_lld_fill_msg_head(dev->base, sdrv_chan->msg_id,
                                (1 << sdrv_chan->rproc),
                                (1 << sdrv_chan->msg_id), len);

    sdrv_mbox_lld_fill_short_msg(dev->base,
                                 (((uint64)sdrv_chan->dest_addr << 48) + ((uint64)sdrv_chan->src_addr << 32)));

#if CONFIG_MBOX_FLUSH_CACHE
    tx_buf = sdrv_mbox_lld_get_txbuf(dev->mem_base, sdrv_chan->msg_id);
#else
    tx_buf = sdrv_mbox_lld_get_txbuf(dev->mem_base, sdrv_chan->msg_id);
#endif

    spin_unlock_irqrestore(&sdrv_mbox->lock, flag);

    return tx_buf;
}

/**
 * @brief sdrv mbox channel send data no copy
 *
 * @param[in] chan mbox channel
 * @param[in] data data ptr
 * @param[in] len data len
 * return send result
 */
static int sdrv_mbox_send_nocopy(mbox_chan_t *chan, uint8 *data, uint32 len)
{
    mbox_dev_t *dev = chan->dev;
    sdrv_mbox_dev_t *sdrv_mbox = dev->priv;
    sdrv_mbox_chan_t *sdrv_chan = chan->priv;
    irq_state_t flag;

    flag = spin_lock_irqsave(&sdrv_mbox->lock);

#if CONFIG_MBOX_FLUSH_CACHE
    arch_clean_cache_range((volatile uint32)data, len);
#endif

    sdrv_mbox_lld_send(dev->base, sdrv_chan->msg_id);

    spin_unlock_irqrestore(&sdrv_mbox->lock, flag);

    return 0;
}

/**
 * @brief check sdrv mbox channel tx done
 *
 * @param[in] chan mbox channel
 * @param[in] timeout if 0 will not need wait finish
 * return tx done result
 */
static boolean sdrv_mbox_tx_done(mbox_chan_t *chan, uint32 timeout)
{
    mbox_dev_t *dev = chan->dev;
    sdrv_mbox_dev_t *sdrv_mbox = dev->priv;
    sdrv_mbox_chan_t *sdrv_chan = chan->priv;
    irq_state_t flag;
    boolean ret;
    ret = sdrv_mbox_lld_tx_done(dev->base, sdrv_chan->msg_id);

    if (ret || !timeout) {
        flag = spin_lock_irqsave(&sdrv_mbox->lock);
        sdrv_mbox_free_message(sdrv_mbox, sdrv_chan->msg_id);
        spin_unlock_irqrestore(&sdrv_mbox->lock, flag);
    }

    return ret;
}

/**
 * @brief sdrv mbox channel cancel send
 *
 * @param[in] chan mbox channel
 */
static void sdrv_mbox_cancel_send(mbox_chan_t *chan)
{
    mbox_dev_t *dev = chan->dev;
    sdrv_mbox_dev_t *sdrv_mbox = dev->priv;
    sdrv_mbox_chan_t *sdrv_chan = chan->priv;
    irq_state_t flag;

    sdrv_mbox_lld_cancel_send(dev->base, sdrv_chan->msg_id);

    flag = spin_lock_irqsave(&sdrv_mbox->lock);
    sdrv_mbox_free_message(sdrv_mbox, sdrv_chan->msg_id);
    spin_unlock_irqrestore(&sdrv_mbox->lock, flag);
}

/**
 * @brief sdrv mbox channel startup
 *
 * @param[in] chan mbox channel
 * @param[in] priv_data startup data
 * return startup result
 */
static boolean sdrv_mbox_startup(mbox_chan_t *chan, void *priv_data)
{
    sdrv_mbox_chan_req_t *chan_req = priv_data;
    sdrv_mbox_chan_t *sdrv_chan = chan->priv;

    if (chan_req->rproc >= SDRV_MBOX_RPROC_NUM) {
        return FALSE;
    }

    sdrv_chan->rproc = chan_req->rproc;

    sdrv_chan->src_addr = chan_req->src_addr;
    sdrv_chan->dest_addr = chan_req->dest_addr;
    sdrv_chan->used = TRUE;

    return TRUE;
}

/**
 * @brief sdrv mbox channel shutdown
 *
 * @param[in] chan mbox channel
 */
static void sdrv_mbox_shutdown(mbox_chan_t *chan)
{
    sdrv_mbox_chan_t *sdrv_chan = chan->priv;

    sdrv_chan->used = FALSE;
}

/**
 * @brief sdrv mbox init
 *
 * @param[in] dev mbox dev
 */
static void sdrv_mbox_init(mbox_dev_t *dev)
{
    sdrv_mbox_dev_t *sdrv_mbox = dev->priv;

    spin_lock_init(&sdrv_mbox->lock);
    sdrv_mbox->msg_bitmap = 0;

    sdrv_mbox_lld_init(dev->base, dev->set_masterid_num);
#if defined(BOARD_E3_ref_gateway_E3640) || defined(BOARD_E3_ref_gateway_E3648)
    sdrv_mbox_lld_buff_clr(dev->mem_base + SDRV_MBOX_TX_BUF(arch_get_cpuid()) , SDRV_MBOX_BUF_LEN);
#else
    sdrv_mbox_lld_buff_clr(dev->mem_base + SDRV_MBOX_TX_BUF(Mcu_GetCoreID()) , SDRV_MBOX_BUF_LEN);
#endif
    if (dev->irq >= 0) {
        irq_attach(dev->irq, (irq_handler)sdrv_mbox_irq_handler, (void *)dev);
        irq_enable(dev->irq);
    }
}

/**
 * @brief sdrv mbox probe
 *
 * @param[in] sdrv_mbox sdrv mbox dev
 * @param[in] cfg mbox config
 * return mbox dev
 */
mbox_dev_t *sdrv_mbox_probe(sdrv_mbox_dev_t *sdrv_mbox,
                            const mbox_config_t *cfg)
{
    uint8 cnt;

    mbox_dev_t * mbox = &sdrv_mbox->dev;
    mbox->priv = sdrv_mbox;
    mbox->ops = &g_sdrv_mbox_ops;
    mbox->chan_num = SDRV_MBOX_CHN_NUM;
    mbox->chan = sdrv_mbox->chan;

    for (cnt = 0; cnt < mbox->chan_num; cnt++) {
        mbox->chan[cnt].priv = &sdrv_mbox->priv[cnt];
    }

    mbox->mtu = SDRV_MBOX_BANK_LEN;

    mbox_init(mbox, cfg);

    return mbox;
}

#define MAILBOX_STOP_SEC_CODE
#include "Mailbox_MemMap.h"
