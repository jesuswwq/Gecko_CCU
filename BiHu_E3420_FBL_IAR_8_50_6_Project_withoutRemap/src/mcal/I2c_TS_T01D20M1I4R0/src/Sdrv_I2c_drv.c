/**
 * @file sdrv_I2c_drv.c
 * @brief sdrv I2c driver interface file.
 *
 * @Copyright (c) 2020  Semidrive Semiconductor.
 * @All rights reserved.
 **/

#include <irq.h>
#include <math.h>
#include "Sdrv_I2c_drv.h"
#include "Sdrv_I2c.h"
#include "I2c_Irq.h"
#include "I2c.h"
#if (I2C_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */

#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

static int sdrv_I2c_write(I2c_adap_dev_t *adap, uint8 *buf,
                           uint16 wlen, uint16 *cur_len)
{
    uint32 flen = 0U, len = 0u;

    if ((NULL_PTR == adap) || (NULL_PTR == buf) || (wlen < 1U)) {
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)I2C_INSTANCE_ID, (uint8)I2C_WRITE_ID, (uint8)I2C_E_PARAM_INVALID);
#endif /* I2C_DEV_ERROR_DETECT */
        return -1;
    }

    uint8 *tbuf = buf + *cur_len;

    flen = sdrv_i2c_lld_get_wspace(adap->base);
    len = min(flen, wlen - *cur_len);
    *cur_len += len;

    while (len--)
        sdrv_i2c_lld_send_data(adap->base, *tbuf++);

    return 0;
}

static int sdrv_I2c_read(I2c_adap_dev_t *adap, uint8 *buf,
                          uint16 rlen, uint16 *cur_len)
{
    uint32 flen = 0U, len = 0u;

    if ((NULL_PTR == adap) || (NULL_PTR == buf) || (rlen < 1U)) {
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)I2C_INSTANCE_ID, (uint8)I2C_READ_ID, (uint8)I2C_E_PARAM_INVALID);
#endif /* I2C_DEV_ERROR_DETECT */
        return -1;
    }

    uint8 *rbuf = buf + *cur_len;

    flen = sdrv_i2c_lld_get_rspace(adap->base);
    len = min(flen, rlen - *cur_len);
    *cur_len += len;

    while (len--)
        *rbuf++ = sdrv_i2c_lld_recv_data(adap->base);

    return 0;
}

static int sdrv_I2c_pwrite(I2c_adap_dev_t *adap,  uint8 *buf, uint16 wlen)
{
    uint32 len = 0U, timeout = 0U;
    sdrv_I2c_dev_t *dev = NULL_PTR;

    if ((NULL_PTR == adap) || (NULL_PTR == buf) || (wlen < 1U)) {
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)I2C_INSTANCE_ID, (uint8)I2C_WRITE_ID, (uint8)I2C_E_PARAM_INVALID);
#endif /* I2C_DEV_ERROR_DETECT */
        return -1;
    }

    dev = (sdrv_I2c_dev_t *)adap->priv;
    timeout = dev->dev_type.mdev.timeout;

    while (wlen) {
        uint32 flen = sdrv_i2c_lld_get_wspace(adap->base);

        if (!flen) {
            Mcu_udelay(1);

            if (timeout--)
                continue;
            else
                return -1;
        }

        timeout = dev->dev_type.mdev.timeout;
        len = min(flen, wlen);
        wlen -= len;

        while (len--)
            sdrv_i2c_lld_send_data(adap->base, *buf++);
    }

    timeout = dev->dev_type.mdev.timeout;
    do {
        uint32 int_st = sdrv_i2c_lld_get_int0_stat(adap->base);

        if (int_st & SDRV_I2C_INT0_APBCMDDONE) {
            break;
        } else if (int_st & SDRV_I2C_INT0_ERR_STAT) {
            return -2;
        }

        Mcu_udelay(10);
    } while (timeout--);

    if (timeout <= 0)
        return -2;

    return 0;
}

static int sdrv_I2c_pread(I2c_adap_dev_t *adap, uint8 *buf, uint16 rlen)
{
    uint32 len = 0U, timeout = 0U;
    sdrv_I2c_dev_t *dev = NULL_PTR;

    if ((NULL_PTR == adap) || (NULL_PTR == buf) || (rlen < 1U)) {
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)I2C_INSTANCE_ID, (uint8)I2C_READ_ID, (uint8)I2C_E_PARAM_INVALID);
#endif /* I2C_DEV_ERROR_DETECT */
        return -1;
    }

    dev = (sdrv_I2c_dev_t *)adap->priv;
    timeout = dev->dev_type.mdev.timeout;

    while (rlen) {
        uint32 flen = sdrv_i2c_lld_get_rspace(adap->base);

        if (!flen) {
            Mcu_udelay(1);

            if (timeout--)
                continue;
            else
                return -1;
        }

        timeout = dev->dev_type.mdev.timeout;
        len = min(flen, rlen);
        rlen -= len;

        while (len--)
            *buf++ = sdrv_i2c_lld_recv_data(adap->base);
    }

    timeout = dev->dev_type.mdev.timeout;
    do {
        uint32 int_st = sdrv_i2c_lld_get_int0_stat(adap->base);

        if (int_st & SDRV_I2C_INT0_APBCMDDONE) {
            break;
        } else if (int_st & SDRV_I2C_INT0_ERR_STAT) {
            return -2;
        }

        Mcu_udelay(10);
    } while (timeout--);

    if (timeout <= 0)
        return -2;

    return 0;
}

static void sdrv_I2c_disable_int_all(I2c_adap_dev_t *adap)
{
    sdrv_i2c_lld_unmask_int0(adap->base, 0x0);
    sdrv_i2c_lld_unmask_int1(adap->base, 0x0);
    sdrv_i2c_lld_unmask_int2(adap->base, 0x0);
    sdrv_i2c_lld_unmask_int3(adap->base, 0x0);
}

static int sdrv_I2c_xfer(I2c_adap_dev_t *adap, struct I2c_msg *msgs, int num)
{
    int ret = 0;

    if ((NULL_PTR == adap) || (NULL_PTR == msgs) || (num < 1) || (num > SDRV_I2C_MSG_NUM_MAX)) {
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)I2C_INSTANCE_ID, (uint8)I2C_TRANSFER_ID, (uint8)I2C_E_PARAM_INVALID);
#endif /* I2C_DEV_ERROR_DETECT */
        return -1;
    }

    sdrv_I2c_dev_t *dev = (sdrv_I2c_dev_t *)adap->priv;
    sdrv_I2c_mdev_t *mdev = &dev->dev_type.mdev;

    for (int msgid = 0; msgid < num; msgid++) {
        mdev->msgs[msgid].addr = msgs[msgid].addr;
        mdev->msgs[msgid].buf = msgs[msgid].buf;
        mdev->msgs[msgid].len = msgs[msgid].len;
        mdev->msgs[msgid].rw_flag = msgs[msgid].rw_flag;
    }

    mdev->num = num;
    mdev->status = 0;
    mdev->cur_msg_idx = 0;
    mdev->cur_msg_len = 0;
    mdev->cur_cmd_done = 0;
    mdev->cur_msg_stat = SDRV_I2C_MSG_IDLE;

    sdrv_I2c_disable_int_all(adap);
    sdrv_i2c_lld_clear_int(adap->base);
    if (sdrv_i2c_lld_clear_fifo(adap->base)) {
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)I2C_INSTANCE_ID, (uint8)I2C_TRANSFER_ID, (uint8)I2C_E_CLEAR_FIFO_FAILURE);
#endif /* I2C_DEV_ERROR_DETECT */
        return -1;
    }

    if (mdev->msgs[0].polling == I2C_POLLING_MOD) {
        for (int trans = 0; trans < mdev->num; trans++) {
            sdrv_i2c_lld_clear_int(adap->base);
            mdev->cur_msg = &mdev->msgs[trans];

            /* set SlaveAddr, 7/10bit, read/write flag, data length */
            sdrv_i2c_lld_set_cmdcsr2(adap->base,
                ((mdev->cur_msg->addr & I2C_CMDCSR2_TAR_MASK) << I2C_CMDCSR2_TAR_BIT) |
                ((mdev->cur_msg->addr_flag & I2C_CMDCSR2_TARTYP_MASK) << I2C_CMDCSR2_TARTYP_BIT) |
                ((mdev->cur_msg->rw_flag & I2C_CMDCSR2_RWB_MASK) << I2C_CMDCSR2_RWB_BIT) |
                ((mdev->cur_msg->len & I2C_CMDCSR2_DATBYTENUM_MASK) << I2C_CMDCSR2_DATBYTENUM_BIT));

            /* auto strans stop bit, if current message is last */
            if (trans == mdev->num - 1)
                sdrv_i2c_lld_set_cmdcsr0(adap->base,
                    ((I2C_MASTER_DOORBELL & I2C_CMDCSR0_DOORBELL_MASK) << I2C_CMDCSR0_DOORBELL_BIT) |
                    ((0x1U & I2C_CMDCSR0_AUTOSTOP_MASK) << I2C_CMDCSR0_AUTOSTOP_BIT));
            else
                sdrv_i2c_lld_set_cmdcsr0(adap->base,
                    ((I2C_MASTER_DOORBELL & I2C_CMDCSR0_DOORBELL_MASK) << I2C_CMDCSR0_DOORBELL_BIT));

            if (mdev->cur_msg->rw_flag)
                ret = sdrv_I2c_pread(adap, mdev->cur_msg->buf, mdev->cur_msg->len);
            else
                ret = sdrv_I2c_pwrite(adap, mdev->cur_msg->buf, mdev->cur_msg->len);

            if (ret < 0) {
#if (I2C_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)I2C_INSTANCE_ID, (uint8)I2C_TRANSFER_ID, (uint8)I2C_E_TRANSMIT_EXCEPTION);
#endif /* I2C_DEV_ERROR_DETECT */
                return ret;
            }
        }
    } else if (mdev->msgs[0].polling == I2C_MAINFUN_MOD) {
        adap->trans_state = I2C_BUSY_STATE;

    } else if (mdev->msgs[0].polling == I2C_INTR_MOD) {
        adap->trans_state = I2C_BUSY_STATE;
        sdrv_i2c_lld_unmask_int0(adap->base, SDRV_I2C_INT0_DEFAULT_MASK);
    } else
        ret = -1;

    return ret;
}

static int sdrv_I2c_get_timing_cfg(enum I2c_speed speed, uint32 clk,
                                   sdrv_I2c_timing_t *timing)
{
    sdrv_I2c_timing_cfg_t cfg = {0};
    uint32 clk_khz = clk / 1000;
    timing->divs = clk_khz / 108000;

    if (timing->divs)
        clk_khz /= (timing->divs + 1);

    if (speed == I2C_SSPEED) {
        cfg.timscll = CAL_SCLL(5000, clk_khz);
        cfg.timtasclh = CAL_TA(150, clk_khz);
        cfg.timtascll = CAL_TA(150, clk_khz);
        cfg.timtasdal = CAL_TA(150, clk_khz);
        cfg.timdvdat = CAL_DVDAT(3400, clk_khz);
        cfg.timunit = CAL_UNIT(6);
        cfg.timmext = CAL_MEXT(0, clk_khz);
        cfg.timsext = CAL_SEXT(0, clk_khz);
        cfg.timstuck = CAL_STUCK(5000, clk_khz);
        cfg.timsdarxhld = CAL_SDARXHLD(300, clk_khz);
        cfg.timdatspl = CAL_DATSPL(2);
        cfg.timbuf = CAL_BUF(5000, clk_khz);
        cfg.timidle = CAL_IDLE(0, clk_khz);
    } else if (speed == I2C_FSPEED) {
        cfg.timscll = CAL_SCLL(1300, clk_khz);
        cfg.timtasclh = CAL_TA(150, clk_khz);
        cfg.timtascll = CAL_TA(150, clk_khz);
        cfg.timtasdal = CAL_TA(150, clk_khz);
        cfg.timdvdat = CAL_DVDAT(900, clk_khz);
        cfg.timunit = CAL_UNIT(6);
        cfg.timmext = CAL_MEXT(0, clk_khz);
        cfg.timsext = CAL_SEXT(0, clk_khz);
        cfg.timstuck = CAL_STUCK(5000, clk_khz);
        cfg.timsdarxhld = CAL_SDARXHLD(300, clk_khz);
        cfg.timdatspl = CAL_DATSPL(2);
        cfg.timbuf = CAL_BUF(5000, clk_khz);
        cfg.timidle = CAL_IDLE(0, clk_khz);
    } else if (speed == I2C_PSPEED) {
        cfg.timscll = CAL_SCLL(500, clk_khz);
        cfg.timtasclh = CAL_TA(60, clk_khz);
        cfg.timtascll = CAL_TA(60, clk_khz);
        cfg.timtasdal = CAL_TA(60, clk_khz);
        cfg.timdvdat = CAL_DVDAT(450, clk_khz);
        cfg.timunit = CAL_UNIT(6);
        cfg.timmext = CAL_MEXT(0, clk_khz);
        cfg.timsext = CAL_SEXT(0, clk_khz);
        cfg.timstuck = CAL_STUCK(5000, clk_khz);
        cfg.timsdarxhld = CAL_SDARXHLD(120, clk_khz);
        cfg.timdatspl = CAL_DATSPL(2);
        cfg.timbuf = CAL_BUF(5000, clk_khz);
        cfg.timidle = CAL_IDLE(0, clk_khz);
    } else if (speed == I2C_HSPEED) {
        cfg.timscll = CAL_SCLL(1300, clk_khz);
        cfg.timtasclh = CAL_TA(150, clk_khz);
        cfg.timtascll = CAL_TA(150, clk_khz);
        cfg.timtasdal = CAL_TA(150, clk_khz);
        cfg.timdvdat = CAL_DVDAT(900, clk_khz);
        cfg.timscll_h = CAL_SCLL(160, clk_khz);
        cfg.timtasclh_h = CAL_TA(30, clk_khz);
        cfg.timtascll_h = CAL_TA(30, clk_khz);
        cfg.timtasdal_h = CAL_TA(30, clk_khz);
        cfg.timdvdat_h = CAL_DVDAT(40, clk_khz);
        cfg.timunit = CAL_UNIT(6);
        cfg.timmext = CAL_MEXT(0, clk_khz);
        cfg.timsext = CAL_SEXT(0, clk_khz);
        cfg.timstuck = CAL_STUCK(5000, clk_khz);
        cfg.timsdarxhld = CAL_SDARXHLD(60, clk_khz);
        cfg.timdatspl = CAL_DATSPL(2);
        cfg.timbuf = CAL_BUF(5000, clk_khz);
        cfg.timidle = CAL_IDLE(0, clk_khz);
    } else if (speed == I2C_USPEED) {
        cfg.timscll = CAL_SCLL(125, clk_khz);
        cfg.timtasclh = CAL_TA(25, clk_khz);
        cfg.timtascll = CAL_TA(25, clk_khz);
        cfg.timtasdal = CAL_TA(25, clk_khz);
        cfg.timdvdat = CAL_DVDAT(20, clk_khz);
        cfg.timunit = CAL_UNIT(6);
        cfg.timmext = CAL_MEXT(0, clk_khz);
        cfg.timsext = CAL_SEXT(0, clk_khz);
        cfg.timstuck = CAL_STUCK(5000, clk_khz);
        cfg.timsdarxhld = CAL_SDARXHLD(20, clk_khz);
        cfg.timdatspl = CAL_DATSPL(0);
        cfg.timbuf = CAL_BUF(5000, clk_khz);
        cfg.timidle = CAL_IDLE(0, clk_khz);
    } else {
        return -1;
    }

    timing->pcr2 =  ((cfg.timscll & I2C_PCR2_3_TIMSCLL_MASK) << I2C_PCR2_3_TIMSCLL_BIT) |
                    ((cfg.timtasclh & I2C_PCR2_3_TIMTASCLH_MASK) << I2C_PCR2_3_TIMTASCLH_BIT) |
                    ((cfg.timtascll & I2C_PCR2_3_TIMTASCLL_MASK) << I2C_PCR2_3_TIMTASCLL_BIT) |
                    ((cfg.timtasdal & I2C_PCR2_3_TIMTASDAL_MASK) << I2C_PCR2_3_TIMTASDAL_BIT) |
                    ((cfg.timdvdat & I2C_PCR2_3_TIMDVDAT_MASK) << I2C_PCR2_3_TIMDVDAT_BIT);

    timing->pcr3 =  ((cfg.timscll_h & I2C_PCR2_3_TIMSCLL_MASK) << I2C_PCR2_3_TIMSCLL_BIT) |
                    ((cfg.timtasclh_h & I2C_PCR2_3_TIMTASCLH_MASK) << I2C_PCR2_3_TIMTASCLH_BIT) |
                    ((cfg.timtascll_h & I2C_PCR2_3_TIMTASCLL_MASK) << I2C_PCR2_3_TIMTASCLL_BIT) |
                    ((cfg.timtasdal_h & I2C_PCR2_3_TIMTASDAL_MASK) << I2C_PCR2_3_TIMTASDAL_BIT) |
                    ((cfg.timdvdat_h & I2C_PCR2_3_TIMDVDAT_MASK) << I2C_PCR2_3_TIMDVDAT_BIT);

    timing->pcr4 =  ((cfg.timunit & I2C_PCR4_TIMUNIT_MASK) << I2C_PCR4_TIMUNIT_BIT) |
                    ((cfg.timmext & I2C_PCR4_TIMMEXT_MASK) << I2C_PCR4_TIMMEXT_BIT) |
                    ((cfg.timsext & I2C_PCR4_TIMSEXT_MASK) << I2C_PCR4_TIMSEXT_BIT) |
                    ((cfg.timstuck & I2C_PCR4_TIMSTUCK_MASK) << I2C_PCR4_TIMSTUCK_BIT);

    timing->pcr5 =  ((cfg.timsdarxhld & I2C_PCR5_TIMSDARXHLD_MASK) << I2C_PCR5_TIMSDARXHLD_BIT) |
                    ((cfg.timdatspl & I2C_PCR5_TIMDATSMPL_MASK) << I2C_PCR5_TIMDATSMPL_BIT) |
                    ((cfg.timbuf & I2C_PCR5_TIMBUF_MASK) << I2C_PCR5_TIMBUF_BIT) |
                    ((cfg.timidle & I2C_PCR5_TIMIDLE_MASK) << I2C_PCR5_TIMIDLE_BIT);

    return 0;
}

int sdrv_I2c_master_irq_handler(uint32 irq, void *arg)
{
    I2c_adap_dev_t *adap = arg;
    sdrv_I2c_dev_t *dev = adap->priv;
    sdrv_I2c_mdev_t *mdev = &dev->dev_type.mdev;
    uint32 int_stat = sdrv_i2c_lld_get_int0_stat(adap->base);
    sdrv_i2c_lld_clear_int(adap->base);

    if (int_stat & SDRV_I2C_INT0_ERR_STAT) {
        mdev->status = -1;
        adap->trans_state = I2C_FAIL_STATE;
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)I2C_INSTANCE_ID, (uint8)I2C_MASTER_IRQ_HANDLER_ID, (uint8)I2C_E_TRANSMIT_EXCEPTION);
#endif /* I2C_DEV_ERROR_DETECT */
        goto done;
    }

    if (int_stat & SDRV_I2C_INT0_APBCMDDONE)
        mdev->cur_cmd_done = 1;
    else
        mdev->cur_cmd_done = 0;

    if ((mdev->cur_msg_stat == SDRV_I2C_MSG_IDLE) && (mdev->cur_msg_idx < mdev->num)) {
        mdev->cur_msg = &mdev->msgs[mdev->cur_msg_idx];

        /* set SlaveAddr, 7/10bit, read/write flag, data length */
        sdrv_i2c_lld_set_cmdcsr2(adap->base,
            ((mdev->cur_msg->addr & I2C_CMDCSR2_TAR_MASK) << I2C_CMDCSR2_TAR_BIT) |
            ((mdev->cur_msg->addr_flag & I2C_CMDCSR2_TARTYP_MASK) << I2C_CMDCSR2_TARTYP_BIT) |
            ((mdev->cur_msg->rw_flag & I2C_CMDCSR2_RWB_MASK) << I2C_CMDCSR2_RWB_BIT) |
            ((mdev->cur_msg->len & I2C_CMDCSR2_DATBYTENUM_MASK) << I2C_CMDCSR2_DATBYTENUM_BIT));

        /* auto strans stop bit, if current message is last */
        if (mdev->cur_msg_idx == mdev->num - 1)
            sdrv_i2c_lld_set_cmdcsr0(adap->base,
                ((I2C_MASTER_DOORBELL & I2C_CMDCSR0_DOORBELL_MASK) << I2C_CMDCSR0_DOORBELL_BIT) |
                ((0x1U & I2C_CMDCSR0_AUTOSTOP_MASK) << I2C_CMDCSR0_AUTOSTOP_BIT));
        else
            sdrv_i2c_lld_set_cmdcsr0(adap->base,
                ((I2C_MASTER_DOORBELL & I2C_CMDCSR0_DOORBELL_MASK) << I2C_CMDCSR0_DOORBELL_BIT));

        if (mdev->cur_msg->rw_flag)
            sdrv_i2c_lld_unmask_int0(adap->base,
                                     SDRV_I2C_INT0_DEFAULT_MASK & ~SDRV_I2C_INT0_TXFWE);
        else
            sdrv_i2c_lld_unmask_int0(adap->base,
                                     SDRV_I2C_INT0_DEFAULT_MASK & ~SDRV_I2C_INT0_RXFWF);
    }

    if (mdev->cur_msg_idx < mdev->num) {
        mdev->cur_msg_stat = SDRV_I2C_MSG_RW;

        if (mdev->cur_msg->rw_flag)
            sdrv_I2c_read(adap, mdev->cur_msg->buf, mdev->cur_msg->len, &mdev->cur_msg_len);
        else
            sdrv_I2c_write(adap, mdev->cur_msg->buf, mdev->cur_msg->len, &mdev->cur_msg_len);
    }

    if (mdev->cur_msg_len >= mdev->cur_msg->len) {
        sdrv_i2c_lld_unmask_int0(adap->base,
                                 SDRV_I2C_INT0_DEFAULT_MASK & ~(SDRV_I2C_INT0_RXFWF | SDRV_I2C_INT0_TXFWE));
        mdev->cur_msg_stat = SDRV_I2C_MSG_IDLE;
        mdev->cur_msg_len = 0;
        mdev->cur_msg_idx++;
    }

    if (mdev->cur_msg_idx >= mdev->num && mdev->cur_cmd_done) {
        adap->trans_state = I2C_IDLE_STATE;
        goto done;
    }

    return 0;
done:
    sdrv_I2c_disable_int_all(adap);
    return 0;
}

static void sdrv_I2c_slave_reset(I2c_adap_dev_t *adap, sdrv_I2c_sdev_t *sdev)
{
    sdrv_i2c_lld_unmask_int0(adap->base, SDRV_I2C_INT0_SLV_DEFAULT_MASK);
    sdrv_i2c_lld_clear_fifo(adap->base);
    sdrv_i2c_lld_clear_int(adap->base);
    sdrv_i2c_lld_set_cmdcsr1(adap->base, SDRV_I2C_CMD1_SLV_MASK);
    sdrv_i2c_lld_set_cmdcsr2(adap->base, SDRV_I2C_CMD2_SLV_MASK);
    sdrv_i2c_lld_set_cmdcsr3(adap->base, SDRV_I2C_CMD3_SLV_MASK);
    sdev->ctlbyte_det = FALSE;
    sdev->rw_event = I2C_SLV_RW_NONE;
    sdev->first_read_req = TRUE;
    sdev->slv_buf_pos = 0;
}

int sdrv_I2c_slave_irq_handler(uint32 irq, void *arg)
{
    uint32 int0_stat, int2_stat;
    I2c_adap_dev_t *adap = arg;
    sdrv_I2c_dev_t *dev = adap->priv;
    sdrv_I2c_sdev_t *sdev = &dev->dev_type.sdev;

    int0_stat = sdrv_i2c_lld_get_int0_stat(adap->base);
    int2_stat = sdrv_i2c_lld_get_int2_stat(adap->base);

    if (int0_stat & SDRV_I2C_INT0_ERR_STAT) {
        sdrv_I2c_slave_reset(adap, sdev);
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)I2C_INSTANCE_ID, (uint8)I2C_SLAVE_IRQ_HANDLER_ID, (uint8)I2C_E_TRANSMIT_EXCEPTION);
#endif /* I2C_DEV_ERROR_DETECT */
        return 0;
    }

    if (int2_stat & SDRV_I2C_INT2_STOPDET) {
        sdrv_I2c_slave_reset(adap, sdev);

    } else if (int2_stat & SDRV_I2C_INT2_SLVRDREQDET) {
        if (sdev->ctlbyte_det)
            sdev->rw_event = I2C_SLV_RD_REQUEST;

        sdrv_i2c_lld_unmask_int0(adap->base, SDRV_I2C_INT0_SLV_DEFAULT_MASK | SDRV_I2C_INT0_TXFWE);
        sdrv_i2c_lld_write_reg(adap->base, I2C_INTR2, int2_stat & SDRV_I2C_INT2_SLVRDREQDET);

    } else if (int2_stat & SDRV_I2C_INT2_SLVWRREQDET) {
        if (sdev->ctlbyte_det)
            sdev->rw_event = I2C_SLV_WR_RECEIVE;

        sdrv_i2c_lld_unmask_int0(adap->base, SDRV_I2C_INT0_SLV_DEFAULT_MASK | SDRV_I2C_INT0_RXFWF);
        sdrv_i2c_lld_write_reg(adap->base, I2C_INTR2, int2_stat & SDRV_I2C_INT2_SLVWRREQDET);

    } else if (int2_stat & SDRV_I2C_INT2_CTLBYTEDET) {
        sdev->ctlbyte_det = TRUE;
        sdrv_i2c_lld_clear_fifo(adap->base);
        sdev->rw_req_len = sdrv_i2c_lld_get_cmdcsr1(adap->base);
        sdrv_i2c_lld_set_cmdcsr2(adap->base, (sdev->rw_req_len << 16) | SDRV_I2C_SLV_ADDR);
        sdrv_i2c_lld_set_cmdcsr3(adap->base, (sdev->rw_req_len << 16) | SDRV_I2C_SLV_ADDR);
        sdrv_i2c_lld_write_reg(adap->base, I2C_INTR2, int2_stat & SDRV_I2C_INT2_CTLBYTEDET);
    }

    if (int0_stat & SDRV_I2C_INT0_RXFWF) {
        if (sdev->rw_event == I2C_SLV_WR_RECEIVE) {
            int flen = sdrv_i2c_lld_get_rspace(adap->base);

            if (sdev->rw_req_len - sdev->slv_buf_pos >= flen) {
                while (flen--)
                    sdev->slv_buf[sdev->slv_buf_pos++] = sdrv_i2c_lld_recv_data(adap->base);
            }

            sdrv_i2c_lld_write_reg(adap->base, I2C_INTR0, int0_stat & SDRV_I2C_INT0_RXFWF);
        }
    }

    if (int0_stat & SDRV_I2C_INT0_SLVWRTRANSDONE) {
        if (sdev->rw_event == I2C_SLV_WR_RECEIVE) {
            int flen = sdrv_i2c_lld_get_rspace(adap->base);

            if (sdev->rw_req_len - sdev->slv_buf_pos >= flen) {
                while (flen--)
                    sdev->slv_buf[sdev->slv_buf_pos++] = sdrv_i2c_lld_recv_data(adap->base);
            }

            sdrv_I2c_slave_reset(adap, sdev);

            if (adap->slv_cb)
                adap->slv_cb(adap, I2C_SLV_WR_RECEIVE, sdev->slv_buf, sdev->rw_req_len);
        } else {
            sdrv_i2c_lld_write_reg(adap->base, I2C_INTR0, int0_stat & SDRV_I2C_INT0_SLVWRTRANSDONE);
        }
    }

    if (sdev->rw_event == I2C_SLV_RD_REQUEST) {
        if (int0_stat & SDRV_I2C_INT0_TXFWE) {
            if (sdev->first_read_req) {
                adap->slv_cb(adap, I2C_SLV_RD_REQUEST, sdev->slv_buf, sdev->rw_req_len);
                sdev->first_read_req = FALSE;
            }

            if (sdev->slv_buf_pos < sdev->rw_req_len) {
                int flen = sdrv_i2c_lld_get_wspace(adap->base);
                int len = min(flen, sdev->rw_req_len - sdev->slv_buf_pos);

                while (len--)
                    sdrv_i2c_lld_send_data(adap->base, sdev->slv_buf[sdev->slv_buf_pos++]);
            } else {
                sdrv_i2c_lld_unmask_int0(adap->base, SDRV_I2C_INT0_SLV_DEFAULT_MASK);
            }

            sdrv_i2c_lld_write_reg(adap->base, I2C_INTR0, int0_stat & SDRV_I2C_INT0_TXFWE);
        }

        if (int0_stat & SDRV_I2C_INT0_SLVRDTRANSDONE) {
            sdrv_I2c_slave_reset(adap, sdev);
        }
    }

    return 0;
}

static void I2c_JobHandleFuntion(uint8 I2cId)
{
    I2c_adap_dev_t *adap = I2cGlobalDev[I2cId];
    sdrv_I2c_dev_t *dev = adap->priv;
    sdrv_I2c_mdev_t *mdev = &dev->dev_type.mdev;
    uint32 int_stat = sdrv_i2c_lld_get_int0_stat(adap->base);
    sdrv_i2c_lld_clear_int(adap->base);

    if (int_stat & SDRV_I2C_INT0_ERR_STAT) {
        mdev->status = -1;
        adap->trans_state = I2C_FAIL_STATE;
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)I2C_INSTANCE_ID, (uint8)I2C_JOBFUNCTION_ID, (uint8)I2C_E_TRANSMIT_EXCEPTION);
#endif /* I2C_DEV_ERROR_DETECT */
        return;
    }

    if (int_stat & SDRV_I2C_INT0_APBCMDDONE)
        mdev->cur_cmd_done = 1;
    else
        mdev->cur_cmd_done = 0;

    if ((mdev->cur_msg_stat == SDRV_I2C_MSG_IDLE) && (mdev->cur_msg_idx < mdev->num)) {
        mdev->cur_msg = &mdev->msgs[mdev->cur_msg_idx];

        /* set SlaveAddr, 7/10bit, read/write flag, data length */
        sdrv_i2c_lld_set_cmdcsr2(adap->base,
            ((mdev->cur_msg->addr & I2C_CMDCSR2_TAR_MASK) << I2C_CMDCSR2_TAR_BIT) |
            ((mdev->cur_msg->addr_flag & I2C_CMDCSR2_TARTYP_MASK) << I2C_CMDCSR2_TARTYP_BIT) |
            ((mdev->cur_msg->rw_flag & I2C_CMDCSR2_RWB_MASK) << I2C_CMDCSR2_RWB_BIT) |
            ((mdev->cur_msg->len & I2C_CMDCSR2_DATBYTENUM_MASK) << I2C_CMDCSR2_DATBYTENUM_BIT));

        /* auto strans stop bit, if current message is last */
        if (mdev->cur_msg_idx == mdev->num - 1)
            sdrv_i2c_lld_set_cmdcsr0(adap->base,
                ((I2C_MASTER_DOORBELL & I2C_CMDCSR0_DOORBELL_MASK) << I2C_CMDCSR0_DOORBELL_BIT) |
                ((0x1U & I2C_CMDCSR0_AUTOSTOP_MASK) << I2C_CMDCSR0_AUTOSTOP_BIT));
        else
            sdrv_i2c_lld_set_cmdcsr0(adap->base,
                ((I2C_MASTER_DOORBELL & I2C_CMDCSR0_DOORBELL_MASK) << I2C_CMDCSR0_DOORBELL_BIT));
    }

    if (mdev->cur_msg_idx < mdev->num) {
        mdev->cur_msg_stat = SDRV_I2C_MSG_RW;

        if (mdev->cur_msg->rw_flag)
            sdrv_I2c_read(adap, mdev->cur_msg->buf, mdev->cur_msg->len, &mdev->cur_msg_len);
        else
            sdrv_I2c_write(adap, mdev->cur_msg->buf, mdev->cur_msg->len, &mdev->cur_msg_len);
    }

    if (mdev->cur_msg_len >= mdev->cur_msg->len) {
        mdev->cur_msg_stat = SDRV_I2C_MSG_IDLE;
        mdev->cur_msg_len = 0;
        mdev->cur_msg_idx++;
    }

    if (mdev->cur_msg_idx >= mdev->num && mdev->cur_cmd_done) {
        adap->trans_state = I2C_IDLE_STATE;
    }

    return;
}

static int sdrv_I2c_do_init(I2c_adap_dev_t *adap)
{
    sdrv_I2c_timing_t timing = {0};
    sdrv_I2c_dev_t *dev = adap->priv;

    if (adap->opmode == I2C_MASTER) {
        dev->dev_type.mdev.timeout = SDRV_I2C_TIMEOUT;
        dev->dev_type.mdev.event = NULL;
        dev->dev_type.mdev.status = 0;
    } else {
        dev->dev_type.sdev.ctlbyte_det = FALSE;
        dev->dev_type.sdev.rw_event = I2C_SLV_RW_NONE;
        dev->dev_type.sdev.first_read_req = TRUE;
        dev->dev_type.sdev.rw_req_len = 0;
        dev->dev_type.sdev.slv_buf_pos = 0;
    }

    /* calculate controller internal timing */
    if (sdrv_I2c_get_timing_cfg(adap->speed, adap->clk, &timing)) {
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)I2C_INSTANCE_ID, (uint8)I2C_INIT_ID, (uint8)I2C_E_TIMMING_EXCEPTION);
#endif /* I2C_DEV_ERROR_DETECT */
        return I2C_UNINIT_STATE;
    }

    /* disable and reset controller; recommended to handle it first */
    sdrv_i2c_lld_disable(adap->base);
    if (0U != sdrv_i2c_lld_reset(adap->base)) {
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)I2C_INSTANCE_ID, (uint8)I2C_INIT_ID, (uint8)I2C_E_RESET_EXCEPTION);
#endif /* I2C_DEV_ERROR_DETECT */
        return I2C_UNINIT_STATE;
    }

    /* set controller operation mode */
    if (adap->opmode == I2C_MASTER) {
        sdrv_i2c_lld_set_opmode(adap->base, SDRV_I2C_MASTER);
    } else if (adap->opmode == I2C_SLAVE) {
        sdrv_i2c_lld_set_opmode(adap->base, SDRV_I2C_SLAVE);
    } else {
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)I2C_INSTANCE_ID, (uint8)I2C_INIT_ID, (uint8)I2C_E_PARAM_INVALID);
#endif /* I2C_DEV_ERROR_DETECT */
        return I2C_UNINIT_STATE;
    }

    /* set controller speed mode and perscale value */
    if (adap->speed == I2C_HSPEED)
        sdrv_i2c_lld_set_speed(adap->base, ((SDRV_I2C_HSPEED & I2C_PCR0_SPEED_MASK) << I2C_PCR0_SPEED_BIT) |
            ((timing.divs & I2C_PCR0_PRESCALE_MASK) << I2C_PCR0_PRESCALE_BIT));
    else if (adap->speed == I2C_USPEED)
        sdrv_i2c_lld_set_speed(adap->base, ((SDRV_I2C_USPEED & I2C_PCR0_SPEED_MASK) << I2C_PCR0_SPEED_BIT) |
            ((timing.divs & I2C_PCR0_PRESCALE_MASK) << I2C_PCR0_PRESCALE_BIT));
    else
        sdrv_i2c_lld_set_speed(adap->base, ((SDRV_I2C_NSPEED & I2C_PCR0_SPEED_MASK) << I2C_PCR0_SPEED_BIT) |
            ((timing.divs & I2C_PCR0_PRESCALE_MASK) << I2C_PCR0_PRESCALE_BIT));

    /* set controller Slave addr */
    if (adap->opmode == I2C_SLAVE) {
        sdrv_i2c_lld_set_slvaddr(adap->base, SDRV_I2C_SLV_ADDR);
    }

    /* set controller timing parameter */
    sdrv_i2c_lld_set_timing(adap->base,
                            timing.pcr2, timing.pcr3, timing.pcr4, timing.pcr5);

    /* set controller fifo watermark */
    sdrv_i2c_lld_set_watermark(adap->base, SDRV_I2C_TX_WML, SDRV_I2C_RX_WML);

    if (adap->opmode == I2C_MASTER) {
#if defined(NON_AUTOSAR_STANDARD_IRQ_HANDLER)
        irq_attach(adap->irq, sdrv_I2c_master_irq_handler, adap);
#else
        irq_attach(adap->irq, I2c_IrqHandle[(adap->id) - 1], NULL_PTR);
#endif
    } else {
        sdrv_i2c_lld_set_cmdcsr1(adap->base, SDRV_I2C_CMD1_SLV_MASK);
        sdrv_i2c_lld_set_cmdcsr2(adap->base, SDRV_I2C_CMD2_SLV_MASK);
        sdrv_i2c_lld_set_cmdcsr3(adap->base, SDRV_I2C_CMD3_SLV_MASK);
        sdrv_i2c_lld_unmask_int0(adap->base, SDRV_I2C_INT0_SLV_DEFAULT_MASK);
        sdrv_i2c_lld_unmask_int2(adap->base, SDRV_I2C_INT2_SLV_MASK);
        sdrv_i2c_lld_clear_int(adap->base);
#if defined(NON_AUTOSAR_STANDARD_IRQ_HANDLER)
        irq_attach(adap->irq, sdrv_I2c_slave_irq_handler, adap);
#else
        irq_attach(adap->irq, I2c_IrqHandle[(adap->id) - 1], NULL_PTR);
#endif
    }

    irq_set_priority(adap->irq, 10);
    irq_enable(adap->irq);
    Mcu_PmuCounterInit();

    /* recommended to enable the controller after initialization */
    sdrv_i2c_lld_enable(adap->base);
    adap->trans_state = I2C_IDLE_STATE;
    adap->adap_State = I2C_ADAP_IDLE;
    return I2C_INIT_STATE;
}

static int sdrv_I2c_init(I2c_adap_dev_t *adap)
{
    int ret;

    if (adap->opmode == I2C_MASTER || adap->opmode == I2C_SLAVE)
        ret = sdrv_I2c_do_init(adap);
    else {
        ret = I2C_UNINIT_STATE;
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)I2C_INSTANCE_ID, (uint8)I2C_INIT_ID, (uint8)I2C_E_PARAM_INVALID);
#endif /* I2C_DEV_ERROR_DETECT */
    }

    return ret;
}

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"

#define I2C_START_SEC_CONST_UNSPECIFIED
#include "I2c_MemMap.h"

static const I2c_adap_ops_t sdrv_I2c_adap_ops = {
    .I2c_init = sdrv_I2c_init,
    .I2c_xfer = sdrv_I2c_xfer,
};

#define I2C_STOP_SEC_CONST_UNSPECIFIED
#include "I2c_MemMap.h"

#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

I2c_adap_dev_t *sdrv_I2c_adap_probe(sdrv_I2c_dev_t *dev, const I2c_adap_cfg_t *cfg, int id)
{
    I2c_adap_dev_t *adap = &dev->adap;

    adap->id = id;
    adap->ops = &sdrv_I2c_adap_ops;
    adap->retry = SDRV_I2C_RETRY;
    adap->priv = dev;

    if (I2c_adap_earlyinit(adap, cfg) < 0)
        return NULL_PTR;
    else
        return adap;
}

void I2c_MainFunctionHandling(uint8 I2cId)
{
    if ((I2c_get_initstate(I2cGlobalDev[I2cId]) == I2C_INIT_STATE) &&
        (I2c_get_transtate(I2cGlobalDev[I2cId]) == I2C_BUSY_STATE)) {

        sdrv_I2c_dev_t *dev = I2cGlobalDev[I2cId]->priv;
        uint8 trans_mod = dev->dev_type.mdev.msgs[0].polling;

        if (trans_mod == I2C_MAINFUN_MOD)
            I2c_JobHandleFuntion(I2cId);
    }
}

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"
