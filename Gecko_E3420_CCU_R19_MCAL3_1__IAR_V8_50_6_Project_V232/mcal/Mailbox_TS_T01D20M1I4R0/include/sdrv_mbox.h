/**
 * @file sdrv_mbox.h
 *
 * Copyright (c) 2021 Semidrive Semiconductor.
 * All rights reserved.
 *
 * Description: sdrv mailbox driver interface.
 *
 * Revision History:
 * -----------------
 */

#ifndef DRV_LLD_SDRV_MBOX_H
#define DRV_LLD_SDRV_MBOX_H

/** @name Register Map
 *
 * Register offsets from the base address of the device.
 *
 * @{
 */
#define SDRV_MBOX_TMH0                  0x0
#define SDRV_MBOX_TMH1                  0x4
#define SDRV_MBOX_TMH2                  0x8
#define SDRV_MBOX_TMC(id)               (0xc + (id * 0x4))
#define SDRV_MBOX_TMS                   0x1c
#define SDRV_MBOX_TPWES                 0x20
#define SDRV_MBOX_RMC                   0x24
#define SDRV_MBOX_RWC                   0x28
#define SDRV_MBOX_RMH(id, n, m)         ((0x2c + (id * 0x4)) +  (m * 0xc) + (n * 0x30))
#define SDRV_MBOX_MASTERID(id)          (0x500 + (id * 0x4))

#if defined(CONFIG_MBOX_FLUSH_CACHE)
#define SDRV_MBOX_TX_BUF                0x0
#define SDRV_MBOX_RX_BUF(n)             (0x1000 + (n * 0x1000))
#else
#define SDRV_MBOX_TX_BUF                0x1000
#define SDRV_MBOX_RX_BUF(n)             (0x2000 + (n * 0x1000))
#endif
#define SDRV_MBOX_TX_BUF_DIFF           0x1000

#define SDRV_MBOX_SEMAG(id)             (0x200 + (id * 0x8))
#define SDRV_MBOX_SEMAGPC(id)           (0x204 + (id * 0x8))
#define SDRV_MBOX_SGR                   0x400
#define SDRV_MBOX_SGI                   0x404

#define SDRV_MBOX_CPUUSERID             0x600
#define SDRV_MBOX_ERR_INJ_CTRL          0x604
#define SDRV_MBOX_INTEN                 0x7f0
#define SDRV_MBOX_INTCLR                0x7f4
#define SDRV_MBOX_INTSTAT               0x7f8

/* @} */

/** @name Transmit Message Header 0 Register
 * Transmit Message Header 0 Register definitions
 * @{
 */
#define SDRV_MBOX_TMH0_MID_SHIFT        24
#define SDRV_MBOX_TMH0_MDP_SHIFT        16
#define SDRV_MBOX_TMH0_MBM_SHIFT        12
#define SDRV_MBOX_TMH0_MB_SHIFT         11
#define SDRV_MBOX_TMH0_LEN_SHIFT        0
/* @} */

/** @name Transmit Message Control Register
 * Transmit Message Control Register definitions
 * @{
 */
#define SDRV_MBOX_TMC_WAK_SHIFT         16
#define SDRV_MBOX_TMC_CANCEL_SHIFT      8
#define SDRV_MBOX_TMC_SEND_SHIFT        0
/* @} */

/** @name Receive Message Header 0 Register
 * Receive Message Header 0 Register definitions
 * @{
 */
#define SDRV_MBOX_RMH0_IDX_SHIFT        24
#define SDRV_MBOX_RMH0_MV_SHIFT         16
#define SDRV_MBOX_RMH0_MBM_SHIFT        12
#define SDRV_MBOX_RMH0_MB_SHIFT         11
#define SDRV_MBOX_RMH0_MB_MASK          0xf
#define SDRV_MBOX_RMH0_LEN_SHIFT        0
#define SDRV_MBOX_RMH0_LEN_MASK         0x7ff
/* @} */

#define SDRV_MBOX_SEMAG_SGC_SHIFT       0
#define SDRV_MBOX_SEMAG_IESGSC_SHIFT    9
#define SDRV_MBOX_SEMAG_SGLS_SHIFT      16
#define SDRV_MBOX_SEMAG_SGLS_SIZE       8

#define SDRV_MBOX_REMOTE_NUM            8
#define SDRV_MBOX_MSG_NUM               4
#define SDRV_MBOX_BUF_LEN               4096
#define SDRV_MBOX_BANK_LEN              (SDRV_MBOX_BUF_LEN/SDRV_MBOX_MSG_NUM)
#define SDRV_MBOX_SHORT_BUF_LEN         4

#ifndef ASSEMBLY

//__BEGIN_CDECLS

/**
 * @brief sdrv mbox buff clear.
 *
 * @param[in] base start base
 * @param[in] size clear size
 */
void sdrv_mbox_lld_buff_clr(volatile uint32 base, uint32 size);

/**
 * @brief sdrv mbox init.
 *
 * @param[in] lld sdrv mbox dev
 * @param[in] base sdrv mbox address
 * @param[in] set_masterid_num sdrv mbox set master id number
 */
void sdrv_mbox_lld_init(volatile uint32 base, uint8 set_masterid_num);

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
                                 uint8 mbm, uint16 len);

/**
 * @brief sdrv mbox fill short msg.
 *
 * @param[in] base sdrv mbox address
 * @param[in] data short msg data
 */
void sdrv_mbox_lld_fill_short_msg(volatile uint32 base, uint64 data);

/**
 * @brief sdrv mbox free tx message.
 *
 * @param[in] base sdrv mbox lld address
 * @param[in] msg_id message id
 */
void sdrv_mbox_lld_send(volatile uint32 base, uint8 msg_id);

/**
 * @brief sdrv mbox get send status.
 *
 * @param[in] base sdrv mbox address
 * @param[in] msg_id message id
 */
boolean sdrv_mbox_lld_tx_done(volatile uint32 base, uint8 msg_id);

/**
 * @brief sdrv mbox cancel send.
 *
 * @param[in] base sdrv mbox address
 * @param[in] msg_id message id
 */
void sdrv_mbox_lld_cancel_send(volatile uint32 base, uint8 msg_id);

/**
 * @brief sdrv mbox set wakeup message.
 *
 * @param[in] base sdrv mbox lld address
 * @param[in] msg_id message id
 * @param[in] mdp rproc id
 */
void sdrv_mbox_lld_wakeup(volatile uint32 base, uint8 msg_id, uint8 mdp);

/**
 * @brief sdrv mbox get rx status.
 *
 * @param[in] base sdrv mbox address
 * @return rx msg id
 */
uint32 sdrv_mbox_lld_get_status(volatile uint32 base);

/**
 * @brief sdrv mbox get rx status.
 *
 * @param[in] base sdrv mbox address
 * @param[in] remote remote proc id
 * @param[in] msg_id message id
 */
void sdrv_mbox_lld_ack(volatile uint32 base, uint8 remote, uint8 msg_id);

/**
 * @brief sdrv mbox get short msg.
 *
 * @param[in] base sdrv mbox address
 * @param[in] remote remote cpu
 * @param[in] msg_id message id
 * @return short msg data
 */
uint64 sdrv_mbox_lld_get_short_msg(volatile uint32 base, uint8 remote, uint8 msg_id);

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
                                    uint8 *mbm);

/**
 * @brief sdrv mbox get tx buffer.
 *
 * @param[in] base sdrv mbox address
 * @param[in] buf_id buf start index
 * @return buffer address
 */
uint8 *sdrv_mbox_lld_get_txbuf(volatile uint32 base, uint8 buf_id);

/**
 * @brief sdrv mbox get rx buffer.
 *
 * @param[in] base sdrv mbox address
 * @param[in] remote remote cpu
 * @param[in] buf_id buf start index
 * @return buffer address
 */
uint8 *sdrv_mbox_lld_get_rxbuf(volatile uint32 base, uint8 remote, uint8 buf_id);

/**
 * @brief sdrv mbox enable sem gate status change interrupt
 *
 * @param[in] base sdrv mbox address
 * @param[in] semag_id sem gate id
 * @param[in] enable enable interrupt
 */
void sdrv_mbox_lld_semag_status_change_int(volatile uint32 base, uint32 semag_id, boolean enable);

/**
 * @brief sdrv mbox request lock semag
 *
 * @param[in] base sdrv mbox address
 * @param[in] semag_id sem gate id
 */
void sdrv_mbox_lld_semag_request_lock(volatile uint32 base, uint32 semag_id);

/**
 * @brief sdrv mbox release semag
 *
 * @param[in] base sdrv mbox address
 * @param[in] semag_id sem gate id
 */
void sdrv_mbox_lld_semag_release_lock(volatile uint32 base, uint32 semag_id);

/**
 * @brief sdrv mbox get semag lock status
 *
 * @param[in] base sdrv mbox address
 * @param[in] semag_id sem gate id
 * @return lock status
 */
uint8 sdrv_mbox_lld_semag_get_lock_status(volatile uint32 base, uint32 semag_id);

/**
 * @brief sdrv mbox get SGI register
 *
 * @param[in] base sdrv mbox address
 * @return SGI register value
 */
uint32 sdrv_mbox_lld_semag_get_sgi(volatile uint32 base);

/**
 * @brief sdrv mbox set SGI register
 *
 * @param[in] base sdrv mbox address
 * @param[in] val set value
 */
void sdrv_mbox_lld_semag_set_sgi(volatile uint32 base, uint32 val);

/**
 * @brief sdrv mbox get semag lock status
 *
 * @param[in] base sdrv mbox address
 * @param[in] semag_id sem gate id
 * @return lock status
 */
uint32 sdrv_mbox_lld_semag_get_sgls(volatile uint32 base, uint32 semag_id);

//__END_CDECLS

#endif

#endif
