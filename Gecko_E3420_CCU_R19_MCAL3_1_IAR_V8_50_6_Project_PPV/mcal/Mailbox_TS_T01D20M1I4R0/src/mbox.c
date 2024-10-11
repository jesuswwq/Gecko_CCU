/**
 * @file mbox.c
 *
 * Copyright (c) 2021 Semidrive Semiconductor.
 * All rights reserved.
 *
 * Description: mailbox devices.
 *
 * Revision History:
 * -----------------
 */
#include "Det.h"
#include "RegHelper.h"
#include "debug.h"
#include <irq.h>
#include <mbox.h>
#include "SchM_Ipc.h"
#include "Mcu_Delay.h"
#include "sdrv_e3_mbox_drv.h"
#include <Mcu.h>

#define CONFIG_MBOX_TX_POLL (1*100)  /* 1ms */

#define MAILBOX_START_SEC_CODE
#include "Mailbox_MemMap.h"

/**
 * @brief mbox wait tx complete
 *
 * @param[in] chan mbox channel
 * @param[in] timeout wait timeout
 * @return complete result
 */
static int mbox_wait_tx_complete(mbox_chan_t *chan, uint32 timeout)
{
    mbox_dev_t *dev = chan->dev;
    uint32 wait_time = 0;

    if (NULL == dev->ops->tx_done) {
        return -1;
    }

    /* Fix the interface returns an error when the timeout is 0 */
    while (!dev->ops->tx_done(chan, timeout)) {
        Mcu_udelay(CONFIG_MBOX_TX_POLL);
        wait_time += CONFIG_MBOX_TX_POLL;

        if (wait_time >= timeout * 10000) {
            return -1;
        }
    }

    return 0;
}

/**
 * @brief mbox register
 *
 * @param[in] dev mbox dev
 * @param[in] cfg mbox config
 */
void mbox_init(mbox_dev_t *dev, const mbox_config_t *cfg)
{
    uint8 cnt;

    dev->base = cfg->base;
    dev->mem_base = cfg->mem_base;
    dev->irq = cfg->irq;
    dev->set_masterid_num = cfg->set_masterid_num;

    for (cnt = 0; cnt < dev->chan_num; cnt++) {
        mbox_chan_t *chan = &dev->chan[cnt];
        chan->dev = dev;
        chan->used = FALSE;
    }

    if (dev->ops->init)
        dev->ops->init(dev);
}

/**
 * @brief mbox get mtu
 *
 * @param[in] dev mbox dev
 * @return mtu
 */
uint32 mbox_mtu(mbox_dev_t *dev)
{
    return dev->mtu;
}

/**
 * @brief mbox client request channel
 *
 * @param[in] dev mbox dev
 * @param[in] priv_data priv data for special driver
 * @return mbox channel
 */
mbox_chan_t *mbox_request_channel(mbox_dev_t *dev, void *priv_data)
{
    mbox_chan_t *find_chan = NULL;
    uint8 cnt;

    SchM_Enter_Ipc_IPC_EXCLUSIVE_AREA_00();

    for (cnt = 0; cnt < dev->chan_num; cnt++) {
        mbox_chan_t *chan = &dev->chan[cnt];

        if (!chan->used) {
            if (dev->ops->startup)
                dev->ops->startup(chan, priv_data);

            chan->callback = NULL;
            chan->arg = NULL;
            chan->used = TRUE;
            chan->need_clr = 0;
            find_chan = chan;
            break;
        }
    }

    SchM_Exit_Ipc_IPC_EXCLUSIVE_AREA_00();
    return find_chan;
}

/**
 * @brief mbox client release channel
 *
 * @param[in] client mbox client
 */
void mbox_release_channel(mbox_chan_t *chan)
{
    mbox_dev_t *dev = chan->dev;

    SchM_Enter_Ipc_IPC_EXCLUSIVE_AREA_01();

    if (dev->ops->shutdown)
        dev->ops->shutdown(chan);

    chan->callback = NULL;
    chan->arg = NULL;
    chan->used = FALSE;

    SchM_Exit_Ipc_IPC_EXCLUSIVE_AREA_01();
}

/**
 * @brief mbox send message
 *
 * @param[in] chan mbox channel
 * @param[in] data msg data
 * @param[in] msg len
 * @param[in] timer_out timerout value(ms)
 * @return send result
 */
int mbox_send(mbox_chan_t *chan, uint8 *data,
              uint32 len, uint32 timeout)
{
    mbox_dev_t *dev = chan->dev;
    int ret;

    ret = dev->ops->send(chan, data, len);

    if (ret < 0 || timeout == MBOX_NO_WAIT) {
        return ret;
    }

    ret = mbox_wait_tx_complete(chan, timeout);

    if (ret < 0) {
        dev->ops->cancel_send(chan);
    }

    return ret;
}
/**
 * @brief mbox send message
 *
 * @param[in] chan mbox channel
 * @param[in] data msg data
 * @param[in] msg len
 * @param[in] timer_out timerout value(ms)
 * @return send result
 */
int mbox_send_mask(mbox_chan_t *chan, uint8 *data,
                   uint32 len, uint16 mask)
{
    mbox_dev_t *dev = chan->dev;
    int ret;

    if (chan->need_clr) {
        ret = mbox_wait_tx_complete(chan, 0);

        if (ret) {
            Det_ReportRuntimeError(MAILBOX_MODULE_ID_VALUE, MAILBOX_INSTANCE_ID, \
                                   MAILBOX_SEND_IPI_ID, MAILBOX_E_IPI_NO_ACK_ERROR);
        }

        chan->need_clr = 0;
    }

    ret = dev->ops->send_mask(chan, data, len, mask);

    if (ret < 0 ) {
        return ret;
    }

    chan->need_clr = 1;

    return ret;
}

/**
 * @brief mbox send message
 *
 * @param[in] chan mbox channel
 * @param[in] data msg data
 * @param[in] msg len
 * @param[in] timer_out timerout value(ms)
 * @return send result
 */
int mbox_send_data(mbox_chan_t *chan, uint8 *data,
                   uint32 len, uint16 mask)
{
    mbox_dev_t *dev = chan->dev;
    int ret;

    if (chan->need_clr) {
        ret = mbox_wait_tx_complete(chan, 0);

        if (ret) {
            DBG("ReportRuntimeError: Module %d, Instance %d, Api %d, Error %d\n",
                                    MAILBOX_MODULE_ID_VALUE, MAILBOX_INSTANCE_ID,
                                   MAILBOX_SEND_IPI_ID, MAILBOX_E_IPI_NO_ACK_ERROR);
            return ret;
        }

        chan->need_clr = 0;
    }

    ret = dev->ops->send_mask(chan, data, len, mask);

    if (ret < 0 ) {
        return ret;
    }

    chan->need_clr = 1;

    return ret;
}

/**
 * @brief mbox alloc message
 *
 * @param[in] chan mbox channel
 * @param[in] msg len
 * @return message address
 */
uint8 *mbox_alloc_buf(mbox_chan_t *chan, uint32 len)
{
    mbox_dev_t *dev = chan->dev;
    uint8 *buf;
    buf = dev->ops->alloc_buf(chan, len);
    return buf;
}

/**
 * @brief mbox send no copy message
 *
 * @param[in] chan mbox channel
 * @param[in] data msg data
 * @param[in] msg len
 * @param[in] timer_out timerout value(ms)
 * @return send result
 */
int mbox_send_nocopy(mbox_chan_t *chan, uint8 *data,
                     uint32 len, uint32 timeout)
{
    mbox_dev_t *dev = chan->dev;
    int ret;

    ret = dev->ops->send_nocopy(chan, data, len);

    if (ret < 0 || timeout == MBOX_NO_WAIT) {
        return ret;
    }

    ret = mbox_wait_tx_complete(chan, timeout);

    if (ret < 0) {
        dev->ops->cancel_send(chan);
    }

    return ret;
}

/**
 * @brief mbox send with message buffer
 *
 * @param[in] chan mbox channel
 * @param[in] data msg data
 * @param[in] msg len
 * @param[in] timer_out timerout value(ms)
 * @return send result
 */
int mbox_send_nobuf(mbox_chan_t *chan, uint8 *data,
                    uint32 len, uint32 timeout)
{
    mbox_dev_t *dev = chan->dev;
    int ret;

    ret = dev->ops->send_nobuf(chan, data, len);

    if (ret < 0 || timeout == MBOX_NO_WAIT) {
        return ret;
    }

    ret = mbox_wait_tx_complete(chan, timeout);

    if (ret < 0) {
        dev->ops->cancel_send(chan);
    }

    return ret;
}

/**
 * @brief mbox set callback
 *
 * @param[in] chan mbox channel
 * @param[in] callback callback function
 * @param[in] arg callback arg
 */
void mbox_set_callback(mbox_chan_t *chan, mbox_rxcallback callback, void *arg)
{
    chan->callback = callback;
    chan->arg = arg;
}

/**
 * @brief mbox receive message, used by mbox driver
 *
 * @param[in] chan mbox channel
 * @param[in] data msg data
 * @param[in] msg len
 * @return receive result
 */
int mbox_received(mbox_chan_t *chan, uint8 *data, uint32 len, uint8 from)
{
    int ret = 0;

    if (chan->callback) {
        ret = chan->callback(chan->arg, data, len, from);
    }

    return ret;
}

boolean semphore_try_lock(module_e m, uint32 id)
{
    msgsema_unit_t *mb = (msgsema_unit_t *)Mcu_GetModuleBase(m);
    sg_reg_t *sg_reg = (sg_reg_t *) & (mb->semag0);

    sg_reg[id].sg |= BM_SEMAG0_SG0C;

    uint32 v = sg_reg[id].sg;
    if ((v & BM_SEMAG0_SG0C) && (GFV_SEMAG0_SG0LS(v) == (0x01u << semphore_get_userid(m)))) {
        return TRUE;
    } else {
        return FALSE;
    }
}

boolean semphore_unlock(module_e m, uint32 id)
{
    msgsema_unit_t *mb = (msgsema_unit_t *)Mcu_GetModuleBase(m);
    sg_reg_t *sg_reg = (sg_reg_t *) & (mb->semag0);

    sg_reg[id].sg &= ~BM_SEMAG0_SG0C;

    return TRUE;
}

void semphore_init(module_e m)
{
    msgsema_unit_t *mb = (msgsema_unit_t *)Mcu_GetModuleBase(m);

    /*CPU0 SF CPU1 SP0 CPU2 SP1 CPU3 SX0 CPU4 SX1*/
    /* set 4 id the same value for each master */
    mb->cpu0_masterid = (MBOX_RPROC_SF << 24)  | (MBOX_RPROC_SF << 16)  |
                        (MBOX_RPROC_SF << 8)  | MBOX_RPROC_SF;
    mb->cpu1_masterid = (MBOX_RPROC_SP0 << 24) | (MBOX_RPROC_SP0 << 16) |
                        (MBOX_RPROC_SP0 << 8) | MBOX_RPROC_SP0;
    mb->cpu2_masterid = (MBOX_RPROC_SP1 << 24) | (MBOX_RPROC_SP1 << 16) |
                        (MBOX_RPROC_SP1 << 8) | MBOX_RPROC_SP1;
    mb->cpu3_masterid = (MBOX_RPROC_SX0 << 24) | (MBOX_RPROC_SX0 << 16) |
                        (MBOX_RPROC_SX0 << 8) | MBOX_RPROC_SX0;
    mb->cpu4_masterid = (MBOX_RPROC_SX1 << 24) | (MBOX_RPROC_SX1 << 16) |
                        (MBOX_RPROC_SX1 << 8) | MBOX_RPROC_SX1;
}

uint32 semphore_get_userid(module_e m)
{
    /* from is hwid sf=0,sp0/sp=1,sx,sx0=3,sp1=2,sx1=4 */
    return arch_get_cpuid();
}

#define MAILBOX_STOP_SEC_CODE
#include "Mailbox_MemMap.h"
