/**
 * @file sdrv_mbox.c
 *
 * Copyright (c) 2021 Semidrive Semiconductor.
 * All rights reserved.
 *
 * Description: sdrv mailbox driver.
 *
 * Revision History:
 * -----------------
 */

#include <cdefs.h>
#include "RegHelper.h"
#include <sdrv_mbox.h>
#include "Compiler.h"
#include "arch.h"
#include "Mcu_Soc.h"
#define MAILBOX_START_SEC_CODE
#include "Mailbox_MemMap.h"

/**
 * @brief sdrv mbox read reg.
 *
 * @param[in] base reg base
 * @param[in] offset reg offset
 * @param[in] return reg val
 */
static inline uint32 sdrv_mbox_lld_readl(volatile uint32 base, uint32 offset)
{
    return readl(base + offset);
}

/**
 * @brief sdrv mbox write reg.
 *
 * @param[in] base reg base
 * @param[in] offset reg offset
 * @param[in] val reg val
 */
static inline void sdrv_mbox_lld_writel(volatile uint32 base, uint32 offset, uint32 val)
{
    writel(val, (base + offset));
}

/**
 * @brief sdrv mbox buff clear.
 *
 * @param[in] base start base
 * @param[in] size clear size
 */
void sdrv_mbox_lld_buff_clr(volatile uint32 base, uint32 size)
{
    uint32 addr;

    /* Each store must be 32 bits aligned. */
    for (addr = base; addr < base + size; addr += 4) {
      writel((uint32)0x0U,addr);
    }
}

/**
 * @brief sdrv mbox init.
 *
 * @param[in] lld sdrv mbox dev
 * @param[in] base sdrv mbox address
 * @param[in] set_masterid_num sdrv mbox set master id number
 */
void sdrv_mbox_lld_init(volatile uint32 base, uint8 set_masterid_num)
{
    uint32 i, v;

    for (i = 0; i < set_masterid_num; i++) {
        /* set 4 id the same value for each master */
        v = (i << 24) | (i << 16) | (i << 8) | i;

        writel(v, base + SDRV_MBOX_MASTERID(i));
    }
}

/**
 * @brief sdrv mbox free tx message.
 *
 * @param[in] base sdrv mbox lld address
 * @param[in] mid message id
 * @param[in] mdp remote bitmap
 * @param[in] mbm message buffer bitmap
 * @param[in] len message len
 */
void sdrv_mbox_lld_fill_msg_head(volatile uint32 base, uint8 mid, uint8 mdp,
                                 uint8 mbm, uint16 len)
{
    uint32 tmh0;

    tmh0 = (mid << SDRV_MBOX_TMH0_MID_SHIFT) |
           (mdp << SDRV_MBOX_TMH0_MDP_SHIFT) |
           (mbm << SDRV_MBOX_TMH0_MBM_SHIFT) |
           (((ALIGN(len, 2)) / 2) << SDRV_MBOX_TMH0_LEN_SHIFT);

    if (mbm != 0) {
        tmh0 |= (1 << SDRV_MBOX_TMH0_MB_SHIFT);
    }

    sdrv_mbox_lld_writel(base, SDRV_MBOX_TMH0, tmh0);
}

/**
 * @brief sdrv mbox fill short msg.
 *
 * @param[in] base sdrv mbox address
 * @param[in] data short msg data
 */
void sdrv_mbox_lld_fill_short_msg(volatile uint32 base, uint64 data)
{
    sdrv_mbox_lld_writel(base, SDRV_MBOX_TMH1, (uint32)data);
    sdrv_mbox_lld_writel(base, SDRV_MBOX_TMH2, (uint32)(data >> 32));
}

/**
 * @brief sdrv mbox free tx message.
 *
 * @param[in] base sdrv mbox lld address
 * @param[in] msg_id message id
 */
void sdrv_mbox_lld_send(volatile uint32 base, uint8 msg_id)
{
    uint32 tmc;

    tmc = sdrv_mbox_lld_readl(base, SDRV_MBOX_TMC(msg_id));
    tmc |= (1 << SDRV_MBOX_TMC_SEND_SHIFT);
    sdrv_mbox_lld_writel(base, SDRV_MBOX_TMC(msg_id), tmc);
}

/**
 * @brief sdrv mbox get send status.
 *
 * @param[in] base sdrv mbox address
 * @param[in] msg_id message id
 */
boolean sdrv_mbox_lld_tx_done(volatile uint32 base, uint8 msg_id)
{
    uint32 tmc;

    tmc = sdrv_mbox_lld_readl(base, SDRV_MBOX_TMC(msg_id));
    return !(tmc & (1 << SDRV_MBOX_TMC_SEND_SHIFT));
}

/**
 * @brief sdrv mbox cancel send.
 *
 * @param[in] base sdrv mbox address
 * @param[in] msg_id message id
 */
void sdrv_mbox_lld_cancel_send(volatile uint32 base, uint8 msg_id)
{
    uint32 tmc;

    tmc = sdrv_mbox_lld_readl(base, SDRV_MBOX_TMC(msg_id));
    tmc |= (1 << SDRV_MBOX_TMC_CANCEL_SHIFT);
    sdrv_mbox_lld_writel(base, SDRV_MBOX_TMC(msg_id), tmc);
}

/**
 * @brief sdrv mbox set wakeup message.
 *
 * @param[in] base sdrv mbox lld address
 * @param[in] msg_id message id
 * @param[in] mdp rproc id
 */
void sdrv_mbox_lld_wakeup(volatile uint32 base, uint8 msg_id, uint8 mdp)
{
    uint32 tmc;

    tmc = sdrv_mbox_lld_readl(base, SDRV_MBOX_TMC(msg_id));
    tmc |= ((1 << mdp) << SDRV_MBOX_TMC_WAK_SHIFT);
    sdrv_mbox_lld_writel(base, SDRV_MBOX_TMC(msg_id), tmc);
}

/**
 * @brief sdrv mbox get rx status.
 *
 * @param[in] base sdrv mbox address
 * @return rx msg id
 */
uint32 sdrv_mbox_lld_get_status(volatile uint32 base)
{
    return sdrv_mbox_lld_readl(base, SDRV_MBOX_TMS);
}

/**
 * @brief sdrv mbox get rx status.
 *
 * @param[in] base sdrv mbox address
 * @param[in] remote remote proc id
 * @param[in] msg_id message id
 */
void sdrv_mbox_lld_ack(volatile uint32 base, uint8 remote, uint8 msg_id)
{
    uint32 rmc;

    rmc = sdrv_mbox_lld_readl(base, SDRV_MBOX_RMC);
    rmc |= (1 << ((remote << 2) + msg_id));
    sdrv_mbox_lld_writel(base, SDRV_MBOX_RMC, rmc);
}

/**
 * @brief sdrv mbox get short msg.
 *
 * @param[in] base sdrv mbox address
 * @param[in] remote remote cpu
 * @param[in] msg_id message id
 * @return short msg data
 */
uint64 sdrv_mbox_lld_get_short_msg(volatile uint32 base, uint8 remote, uint8 msg_id)
{
    uint32 data_l, data_h;
    data_l = sdrv_mbox_lld_readl(base, SDRV_MBOX_RMH(1, remote, msg_id));
    data_h = sdrv_mbox_lld_readl(base, SDRV_MBOX_RMH(2, remote, msg_id));
    return ((uint64)data_h << 32) + data_l;
}

/**
 * @brief sdrv mbox get msg head.
 *
 * @param[in] base sdrv mbox address
 * @param[in] remote remote cpu
 * @param[in] msg_id message id
 * @param[out] mbm mbm bitmap
 * @return message len
 */
uint16 sdrv_mbox_lld_get_msg_head(volatile uint32 base, uint8 remote, uint8 msg_id,
                                    uint8 *mbm)
{
    uint32 rmh0;

    rmh0 = sdrv_mbox_lld_readl(base, SDRV_MBOX_RMH(0, remote, msg_id));
    *mbm = (rmh0 >> SDRV_MBOX_RMH0_MBM_SHIFT) & SDRV_MBOX_RMH0_MB_MASK;
    return (rmh0 & SDRV_MBOX_RMH0_LEN_MASK) * 2;
}

/**
 * @brief sdrv mbox get tx buffer.
 *
 * @param[in] mem_base sdrv mbox memory address
 * @param[in] buf_id buf start index
 * @return buffer address
 */
uint8 *sdrv_mbox_lld_get_txbuf(volatile uint32 mem_base, uint8 buf_id)
{
#if defined(BOARD_E3_ref_gateway_E3640) || defined(BOARD_E3_ref_gateway_E3648)
    return (uint8 *)mem_base
           + SDRV_MBOX_TX_BUF(arch_get_cpuid())
           + (buf_id * SDRV_MBOX_BANK_LEN);
#else
    return (uint8 *)mem_base
           + SDRV_MBOX_TX_BUF(Mcu_GetCoreID())
           + (buf_id * SDRV_MBOX_BANK_LEN);
#endif
}

/**
 * @brief sdrv mbox get rx buffer.
 *
 * @param[in] mem_base sdrv mbox memory address
 * @param[in] remote remote cpu
 * @param[in] buf_id buf start index
 * @return buffer address
 */
uint8 *sdrv_mbox_lld_get_rxbuf(volatile uint32 mem_base, uint8 remote, uint8 buf_id)
{
#if defined(BOARD_E3_ref_gateway_E3430) || defined(BOARD_E3_ref_gateway_E3420)
    if (remote)
    {
        remote >>= 1;
    }
#endif
    return (uint8 *)mem_base
           + SDRV_MBOX_RX_BUF(remote)
           + (buf_id * SDRV_MBOX_BANK_LEN);
}

/**
 * @brief sdrv mbox enable sem gate status change interrupt
 *
 * @param[in] base sdrv mbox address
 * @param[in] semag_id sem gate id
 * @param[in] enable enable interrupt
 */
void sdrv_mbox_lld_semag_status_change_int(volatile uint32 base, uint32 semag_id, boolean enable)
{
    RMWREG32(base + SDRV_MBOX_SEMAG(semag_id), SDRV_MBOX_SEMAG_IESGSC_SHIFT, 1, enable & 0x1);
}

/**
 * @brief sdrv mbox request lock semag
 *
 * @param[in] base sdrv mbox address
 * @param[in] semag_id sem gate id
 */
void sdrv_mbox_lld_semag_request_lock(volatile uint32 base, uint32 semag_id)
{
    RMWREG32(base + SDRV_MBOX_SEMAG(semag_id), SDRV_MBOX_SEMAG_SGC_SHIFT, 1, 1);
}

/**
 * @brief sdrv mbox release semag
 *
 * @param[in] base sdrv mbox address
 * @param[in] semag_id sem gate id
 */
void sdrv_mbox_lld_semag_release_lock(volatile uint32 base, uint32 semag_id)
{
    RMWREG32(base + SDRV_MBOX_SEMAG(semag_id), SDRV_MBOX_SEMAG_SGC_SHIFT, 1, 0);
}

/**
 * @brief sdrv mbox get semag lock status
 *
 * @param[in] base sdrv mbox address
 * @param[in] semag_id sem gate id
 * @return lock status
 */
uint8 sdrv_mbox_lld_semag_get_lock_status(volatile uint32 base, uint32 semag_id)
{
    return sdrv_mbox_lld_readl(base, SDRV_MBOX_SEMAG(semag_id))
           & (0x1u << SDRV_MBOX_SEMAG_SGC_SHIFT);
}

/**
 * @brief sdrv mbox get SGI register
 *
 * @param[in] base sdrv mbox address
 * @return SGI register value
 */
uint32 sdrv_mbox_lld_semag_get_sgi(volatile uint32 base)
{
    return sdrv_mbox_lld_readl(base, SDRV_MBOX_SGI);
}

/**
 * @brief sdrv mbox set SGI register
 *
 * @param[in] base sdrv mbox address
 * @param[in] val set value
 */
void sdrv_mbox_lld_semag_set_sgi(volatile uint32 base, uint32 val)
{
    sdrv_mbox_lld_writel(base, SDRV_MBOX_SGI, val);
}

/**
 * @brief sdrv mbox get semag lock status
 *
 * @param[in] base sdrv mbox address
 * @param[in] semag_id sem gate id
 * @return lock status
 */
uint32 sdrv_mbox_lld_semag_get_sgls(volatile uint32 base, uint32 semag_id)
{
    uint32 v;

    v = sdrv_mbox_lld_readl(base, SDRV_MBOX_SEMAG(semag_id));
    v >>= SDRV_MBOX_SEMAG_SGLS_SHIFT;
    v &= ((0x1u << SDRV_MBOX_SEMAG_SGLS_SIZE) - 1u);

    return v;
}

#define MAILBOX_STOP_SEC_CODE
#include "Mailbox_MemMap.h"
