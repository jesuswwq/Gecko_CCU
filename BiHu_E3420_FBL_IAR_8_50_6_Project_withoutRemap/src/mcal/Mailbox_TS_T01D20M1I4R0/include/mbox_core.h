/**
 * @file mbox_core.h
 *
 * Copyright (c) 2021 Semidrive Semiconductor.
 * All rights reserved.
 *
 * Description: mailbox interface.
 *
 * Revision History:
 * -----------------
 */
#ifndef MAILBOX_CORE_H
#define MAILBOX_CORE_H

#include "sdrv_e3_mbox_drv.h"

#define MAX_CPUS_SUPPORT    SDRV_MBOX_RPROC_NUM
#define SELF_NODE           ((mbox_chan_t  *)0x5A5AA5A5)

typedef enum {
    MBOX_MBM_CORE_SF = 0x1U << 0U,
    MBOX_MBM_CORE_SP0 = 0x1U << 1U,
    MBOX_MBM_CORE_SP1 = 0x1U << 2U,
    MBOX_MBM_CORE_SX0 = 0x1U << 3U,
    MBOX_MBM_CORE_SX1 = 0x1U << 4U,
}mbox_mbm_mask;

enum ipi_msg_type {
    IPI_0 = 0,
    IPI_1,
    IPI_2,
    IPI_3,
    IPI_4,
    IPI_5,
    IPI_6,
    IPI_7,
    IPI_MAX_IPI_TYPE,
};

enum mailbox_cpu_mask {
    CPU_SF = 0x1 << 0,
    CPU_SP0 = 0x1 << 1,
    CPU_SP1 = 0x1 << 2,
    CPU_SX0 = 0x1 << 3,
    CPU_SX1 = 0x1 << 4,
};

enum ch_type {
    SEND_TYPE = 0,
    RECV_TYPE,
    CH_TYPE_MAX,
};

typedef int (*ipi_handler_t)(uint8 from, void *arg);


struct ipi_data {
    ipi_handler_t handler;
    void  *arg;
};

struct mailbox_handle_cb {
    sdrv_mbox_dev_t sdrv_mbox_dev;
    mbox_dev_t      *mbox_dev;
    mbox_chan_t     *chan_t[CH_TYPE_MAX];
    struct ipi_data   ipi[IPI_MAX_IPI_TYPE];
} ALIGNED(CACHE_LINE);


void mbox_core_init(mbox_rxcallback callback);
void ipi_set_handler(uint8 ipi_idx, ipi_handler_t handler, void *arg);
int  core_send_ipi(uint8 ipi_idx, uint32 coremask);
int  core_send_msg(uint8 *data,uint32 len, uint32 coremask);

#endif
