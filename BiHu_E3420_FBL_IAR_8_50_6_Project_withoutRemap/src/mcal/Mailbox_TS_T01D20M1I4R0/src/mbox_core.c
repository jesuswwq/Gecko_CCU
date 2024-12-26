/**
 * @file mbox_ipi.c
 *
 * Copyright (c) 2021 Semidrive Semiconductor.
 * All rights reserved.
 *
 * Description: mailbox interface.
 *
 * Revision History:
 * -----------------
 */
#include <irq_num.h>
#include <mbox_core.h>
#include <Mcu.h>

#define MAILBOX_START_SEC_CONST_UNSPECIFIED
#include "Mailbox_MemMap.h"

static const mbox_config_t mbox_cfg = {
    .base = MB_REG_BASE,
    .mem_base = MB_MEM_BASE,
    .irq = MB_MU_MESSAGE_READY_INTR_NUM,
    .set_masterid_num = MAX_CPUS_SUPPORT,
};

#define MAILBOX_STOP_SEC_CONST_UNSPECIFIED
#include "Mailbox_MemMap.h"

#define MAILBOX_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Mailbox_MemMap.h"

struct mailbox_handle_cb core_handle_cb[MAX_CPUS_SUPPORT];

#define MAILBOX_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Mailbox_MemMap.h"

#define MAILBOX_START_SEC_CODE
#include "Mailbox_MemMap.h"

static int ipi_irq_handle(void *arg, uint8 *msg, uint32 len, uint8 from)
{
    int ret = 0;
    uint8 ipi_type = *msg;
    struct mailbox_handle_cb *ipi_handle = arg;

    if (ipi_type < IPI_MAX_IPI_TYPE && ipi_handle->ipi[ipi_type].handler) {
        ipi_handle->ipi[ipi_type].handler(from, ipi_handle->ipi[ipi_type].arg);
    } else {
        ret = -1;
    }

    return ret;
}

void mbox_core_init(mbox_rxcallback callback)
{
    uint8 cpuid = Mcu_GetCoreID();

    sdrv_mbox_chan_req_t chan_req;

    chan_req.src_addr = MBOX_ADDR_RAW;
    chan_req.dest_addr = MBOX_ADDR_RAW;
    core_handle_cb[cpuid].mbox_dev = sdrv_mbox_probe(&core_handle_cb[cpuid].sdrv_mbox_dev, &mbox_cfg);

    for (uint8 type = 0; type < CH_TYPE_MAX; type++) {
        chan_req.rproc = cpuid;
        core_handle_cb[cpuid].chan_t[type] = mbox_request_channel(core_handle_cb[cpuid].mbox_dev, &chan_req);

        /*this channel for recvie ipi form others core */
        if(type == RECV_TYPE){
            if(callback){
                mbox_set_callback(core_handle_cb[cpuid].chan_t[type],
                                callback,
                                &core_handle_cb[cpuid]);
            }else{
                mbox_set_callback(core_handle_cb[cpuid].chan_t[type],
                                &ipi_irq_handle,
                                &core_handle_cb[cpuid]);
            }
        }
    }
}

void ipi_set_handler(uint8 ipi_idx, ipi_handler_t handler, void *arg)
{
    /*
        It is forbidden to call the ipi trigger interface again in the handler.
    */
    uint8 cpuid = Mcu_GetCoreID();
    core_handle_cb[cpuid].ipi[ipi_idx].handler = handler;
    core_handle_cb[cpuid].ipi[ipi_idx].arg = arg;
}


int core_send_ipi(uint8 ipi_idx, uint32 coremask)
{
    /*
        If it is found that the last IPI has core but no ack request
    when the interface is called next time, a DET error event will be given.
    */
    int ret = 0;
    /* from is hwid sf=0,sp0/sp=1,sx/sx0=3,sp1=2,sx1=4 */
    uint8 cpuid = arch_get_cpuid();
    /* forever do not send ipi to self */
    coremask &=  ~(0x1 << cpuid);
    ret = mbox_send_mask(core_handle_cb[Mcu_GetCoreID()].chan_t[SEND_TYPE], &ipi_idx, 1, coremask);
    return ret;
}

int core_send_msg(uint8 *data,uint32 len, uint32 coremask)
{
    /*
        If it is found that the last IPI has core but no ack request
    when the interface is called next time, a DET error event will be given.
    */
    int ret = 0;
    uint8 cpuid = arch_get_cpuid();
    /* forever do not send ipi to self */
    coremask &=  ~(0x1 << cpuid);
    ret = mbox_send_data(core_handle_cb[Mcu_GetCoreID()].chan_t[SEND_TYPE], data, len, coremask);
    return ret;
}

#define MAILBOX_STOP_SEC_CODE
#include "Mailbox_MemMap.h"


