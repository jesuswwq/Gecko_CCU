/**
 * @file mbox.h
 *
 * Copyright (c) 2021 Semidrive Semiconductor.
 * All rights reserved.
 *
 * Description: mailbox interface.
 *
 * Revision History:
 * -----------------
 */

#ifndef INCLUDE_DRV_MBOX_H
#define INCLUDE_DRV_MBOX_H

#include "soc_def.h"
#include "mbox_reg.h"

#define MBOX_NO_WAIT            0
#define MBOX_WAIT_FOREVER       0xffffffff

#define MAILBOX_MODULE_ID_VALUE     300U
#define MAILBOX_INSTANCE_ID         0U
#define MAILBOX_SEND_IPI_ID         0U
#define MAILBOX_E_IPI_NO_ACK_ERROR  0U

/* mbox config */
typedef struct mbox_config {
    volatile uint32         base;
    volatile uint32         mem_base;
    int                     irq;
    uint8                 set_masterid_num;
} mbox_config_t;

typedef struct mbox_ops mbox_ops_t;
typedef struct mbox_chan mbox_chan_t;

/* mbox driver */
typedef struct mbox_dev {
    const mbox_ops_t        *ops;
    volatile uint32         base;
    volatile uint32         mem_base;
    int                     irq;
    uint8                 set_masterid_num;
    uint8                 chan_num;
    mbox_chan_t             *chan;
    void                    *priv;
    uint32                mtu;
} mbox_dev_t;

/* mbox callback */
typedef int (*mbox_rxcallback)(void *arg, uint8 *data, uint32 len, uint8 from);

/* mbox channel */
struct mbox_chan {
    mbox_dev_t              *dev;
    boolean                 used;
    mbox_rxcallback         callback;
    void                    *arg;
    void                    *priv;
    boolean                    need_clr;
};

typedef struct {
    volatile uint32 sg;
    volatile uint32 sgpc;
} sg_reg_t;

/* mbox operation */
struct mbox_ops {
    void (*init)(mbox_dev_t *dev);
    boolean (*startup)(mbox_chan_t *chan, void *priv_data);
    void (*shutdown)(mbox_chan_t *chan);
    int (*send)(mbox_chan_t *chan, uint8 *data, uint32 len);
    int (*send_mask)(mbox_chan_t *chan, uint8 *data, uint32 len, uint16 mask);
    uint8 *(*alloc_buf)(mbox_chan_t *chan, uint32 len);
    int (*send_nocopy)(mbox_chan_t *chan, uint8 *data, uint32 len);
    int (*send_nobuf)(mbox_chan_t *chan, uint8 *data, uint32 len);
    void (*cancel_send)(mbox_chan_t *chan);
    boolean (*tx_done)(mbox_chan_t *chan, uint32 timeout);
};

/**
 * @brief mbox register
 *
 * @param[in] dev mbox dev
 * @param[in] cfg mbox config
 */
void mbox_init(mbox_dev_t *dev, const mbox_config_t *cfg);

/**
 * @brief mbox get mtu
 *
 * @param[in] dev mbox dev
 * @return mtu
 */
uint32 mbox_mtu(mbox_dev_t *dev);

/**
 * @brief mbox client request channel
 *
 * @param[in] dev mbox dev
 * @param[in] priv_data priv data for lower driver
 * @return mbox channel
 */
mbox_chan_t *mbox_request_channel(mbox_dev_t *dev, void *priv_data);

/**
 * @brief mbox client release channel
 *
 * @param[in] client mbox client
 */
void mbox_release_channel(mbox_chan_t *chan);

/**
 * @brief mbox set callback
 *
 * @param[in] chan mbox channel
 * @param[in] callback callback function
 * @param[in] arg callback arg
 */
void mbox_set_callback(mbox_chan_t *chan, mbox_rxcallback callback, void *arg);

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
              uint32 len, uint32 timeout);
/**
 * @brief mbox send message
 *
 * @param[in] chan mbox channel
 * @param[in] data msg data
 * @param[in] msg len
 * @param[in] timer_out timerout value(ms)
 * @return send result
 */
int mbox_send_mask(mbox_chan_t *chan, uint8 *data, uint32 len, uint16 mask);
/**
 * @brief mbox alloc message
 *
 * @param[in] chan mbox channel
 * @param[in] msg len
 * @return message address
 */
int mbox_send_data(mbox_chan_t *chan, uint8 *data, uint32 len, uint16 mask);
/**
 * @brief mbox alloc message
 *
 * @param[in] chan mbox channel
 * @param[in] msg len
 * @return message address
 */
uint8 *mbox_alloc_buf(mbox_chan_t *chan, uint32 len);

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
                     uint32 len, uint32 timeout);


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
                    uint32 len, uint32 timeout);

/**
 * @brief mbox receive message, used by mbox driver
 *
 * @param[in] chan mbox channel
 * @param[in] data msg data
 * @param[in] msg len
 * @return receive result
 */
int mbox_received(mbox_chan_t *chan, uint8 *data, uint32 len, uint8 from);

boolean semphore_try_lock(module_e m, uint32 id);

boolean semphore_unlock(module_e m, uint32 id);

void semphore_init(module_e m);

uint32 semphore_get_userid(module_e m);

#endif
