/**
 * @file sdrv_e3_mbox_drv.h
 *
 * Copyright (c) 2021 Semidrive Semiconductor.
 * All rights reserved.
 *
 * Description: sdrv mbox interface.
 *
 * Revision History:
 * -----------------
 */

#ifndef INCLUDE_DRV_SDRV_MBOX_H
#define INCLUDE_DRV_SDRV_MBOX_H

#include "arch_spinlock.h"

#include <mbox.h>

#define SDRV_MBOX_RPROC_NUM         5
#define SDRV_MBOX_CHN_NUM           5

#ifndef ASSEMBLY

//__BEGIN_CDECLS

/* sdrv mbox rproc id */
typedef enum {
    MBOX_RPROC_SF    = 0,
    MBOX_RPROC_SP0   = 1,
    MBOX_RPROC_SP1   = 2,
    MBOX_RPROC_SX0   = 3,
    MBOX_RPROC_SX1   = 4,
} sdrv_mbox_rproc_t;

/* sdrv mbox address id */
typedef enum {
    MBOX_ADDR_INVALID           = 0x0,
    MBOX_ADDR_RAW               = 0x1,
    MBOX_ADDR_IPCC              = 0x2,
    MBOX_ADDR_RPMSG             = 0x4,
    MBOX_ADDR_PM                = 0x8,
} sdrv_mbox_addr_t;

/* sdrv chan req priv data */
typedef struct sdrv_mbox_chan_req {
    uint32                rproc;
    int                     src_addr;       /* -1: any addr */
    int                     dest_addr;      /* -1: any addr */
} sdrv_mbox_chan_req_t;

/* sdrv mbox chan priv */
typedef struct sdrv_mbox_chan {
    uint8                 used;
    uint8                 msg_id;
    uint8                 rproc;
    int                     src_addr;
    int                     dest_addr;
} sdrv_mbox_chan_t;

/* sdrv mbox dev */
typedef struct sdrv_mbox_dev {
    mbox_dev_t              dev;
    mbox_chan_t             chan[SDRV_MBOX_CHN_NUM];
    sdrv_mbox_chan_t        priv[SDRV_MBOX_CHN_NUM];
    uint32                msg_bitmap;
    spin_lock_t             lock;
} sdrv_mbox_dev_t __ALIGNED(4);

/**
 * @brief sdrv mbox probe
 *
 * @param[in] sdrv_mbox sdrv mbox dev
 * @param[in] cfg mbox config
 * return mbox dev
 */
mbox_dev_t *sdrv_mbox_probe(sdrv_mbox_dev_t *sdrv_mbox,
                            const mbox_config_t *cfg);

//__END_CDECLS

#endif

#endif
