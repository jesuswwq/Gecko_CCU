/**
 * @file I2c.c
 * @common I2c interface file
 *
 * @Copyright (c) 2020  Semidrive Semiconductor.
 * @All rights reserved.
 *
 **/

#include "I2c.h"
#include "I2c_Cfg.h"
#include "SchM_I2c.h"
#if (I2C_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */

#define I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "I2c_MemMap.h"

sdrv_I2c_dev_t I2c_sdrv_dev[I2C_CHN_NUM];
I2c_adap_dev_t *I2cGlobalDev[I2C_CHN_NUM];
struct I2c_msg I2c_msgs[I2C_CHN_NUM][SDRV_I2C_MSG_NUM_MAX];

#define I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "I2c_MemMap.h"

#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

int I2c_force_transtate(I2c_adap_dev_t *adap, int set_transtate)
{
    if (NULL_PTR == adap) {
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)I2C_INSTANCE_ID, (uint8)I2C_TRANSTATE_ID, (uint8)I2C_E_PARAM_INVALID);
#endif /* I2C_DEV_ERROR_DETECT */
        return -1;
    }

    if ((set_transtate >= I2C_IDLE_STATE) && (set_transtate <= I2C_FAIL_STATE)) {
        adap->trans_state = (enum I2c_trans_st)set_transtate;
    }

    return 0;
}

int I2c_get_transtate(I2c_adap_dev_t *adap)
{
    if (NULL_PTR == adap) {
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)I2C_INSTANCE_ID, (uint8)I2C_TRANSTATE_ID, (uint8)I2C_E_PARAM_INVALID);
#endif /* I2C_DEV_ERROR_DETECT */
        return -1;
    }

    return adap->trans_state;
}

int I2c_get_initstate(I2c_adap_dev_t *adap)
{
    if (NULL_PTR == adap) {
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)I2C_INSTANCE_ID, (uint8)I2C_INITSTATE_ID, (uint8)I2C_E_PARAM_INVALID);
#endif /* I2C_DEV_ERROR_DETECT */
        return -1;
    }

    return adap->status;
}

int I2c_transfer(I2c_adap_dev_t *adap, struct I2c_msg *msgs, int num)
{

    int ret = 1, try = 0;
    boolean busyFlag = FALSE;

    if ((NULL_PTR == adap) || (NULL_PTR == msgs) || (num < 1) || (num > SDRV_I2C_MSG_NUM_MAX)) {
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)I2C_INSTANCE_ID, (uint8)I2C_TRANSFER_ID, (uint8)I2C_E_PARAM_INVALID);
#endif /* I2C_DEV_ERROR_DETECT */
        return -1;
    }

    if ((NULL_PTR == adap->ops->I2c_xfer) || (adap->status != I2C_INIT_STATE)) {
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)I2C_INSTANCE_ID, (uint8)I2C_TRANSFER_ID, (uint8)I2C_E_UNINIT);
#endif /* I2C_DEV_ERROR_DETECT */
        return -1;
    }

    /* check and update adap owner statue */
    SchM_Enter_I2c_I2C_EXCLUSIVE_AREA_00();
    if (adap->adap_State == I2C_ADAP_IDLE) {
        adap->adap_State = I2C_ADAP_BUSY;
        busyFlag = TRUE;
    }
    SchM_Exit_I2c_I2C_EXCLUSIVE_AREA_00();

    if (TRUE == busyFlag) {
        if (adap->trans_state == I2C_IDLE_STATE) {
            do {
                ret = adap->ops->I2c_xfer(adap, msgs, num);
                if (!ret)
                    break;
            } while (++try < adap->retry);
        }
        /* update adap owner statue */
        SchM_Enter_I2c_I2C_EXCLUSIVE_AREA_00();
        adap->adap_State = I2C_ADAP_IDLE;
        SchM_Exit_I2c_I2C_EXCLUSIVE_AREA_00();
    }
            else
        {
            //while(adap->adap_State == I2C_ADAP_BUSY)
            ret = 1;
        }
    return ret;
}

int I2c_write(I2c_adap_dev_t *adap, uint16 addr,
              const uint8 *wbuf, int wlen)
{
    int ret;
    struct I2c_msg msgs[1];
    if ((NULL_PTR == adap) || (NULL_PTR == wbuf) || (wlen < 1)) {
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)I2C_INSTANCE_ID, (uint8)I2C_WRITE_ID, (uint8)I2C_E_PARAM_INVALID);
#endif /* I2C_DEV_ERROR_DETECT */
        ret = -1;
    } else {
        msgs[0].addr = addr;
        msgs[0].buf = (uint8 *)wbuf;
        msgs[0].len = wlen;
        msgs[0].rw_flag = I2C_M_W;
        ret = I2c_transfer(adap, msgs, 1);
    }

    return ret;
}

int I2c_read(I2c_adap_dev_t *adap, uint16 addr,
             uint8 *rbuf, int rlen)
{
    int ret;
    struct I2c_msg msgs[1];
    if ((NULL_PTR == adap) || (NULL_PTR == rbuf) || (rlen < 1)) {
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)I2C_INSTANCE_ID, (uint8)I2C_READ_ID, (uint8)I2C_E_PARAM_INVALID);
#endif /* I2C_DEV_ERROR_DETECT */
        ret = -1;
    } else {
        msgs[0].addr = addr;
        msgs[0].buf = rbuf;
        msgs[0].len = rlen;
        msgs[0].rw_flag = I2C_M_R;
        ret = I2c_transfer(adap, msgs, 1);
    }

    return ret;
}

int I2c_write_read(I2c_adap_dev_t *adap, uint16 addr,
                   const uint8 *wbuf, int wlen,  uint8 *rbuf, int rlen)
{
    int ret;
    struct I2c_msg msgs[2];
    if ((NULL_PTR == adap) || (NULL_PTR == wbuf) || (NULL_PTR == rbuf) || (rlen < 1) || (wlen < 1)) {
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)I2C_INSTANCE_ID, (uint8)I2C_WRITE_READ_ID, (uint8)I2C_E_PARAM_INVALID);
#endif /* I2C_DEV_ERROR_DETECT */
        ret = -1;
    } else {
        msgs[0].addr = addr;
        msgs[0].buf = (uint8 *)wbuf;
        msgs[0].len = wlen;
        msgs[0].rw_flag = I2C_M_W;

        msgs[1].addr = addr;
        msgs[1].buf = rbuf;
        msgs[1].len = rlen;
        msgs[1].rw_flag = I2C_M_R;
        ret = I2c_transfer(adap, msgs, 2);
    }

    return ret;
}

int I2c_write_reg(I2c_adap_dev_t *adap, uint16 addr, uint8 reg, uint8 data)
{
    int ret;
    struct I2c_msg msgs[2];
    if (NULL_PTR == adap) {
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)I2C_INSTANCE_ID, (uint8)I2C_WRITE_ID, (uint8)I2C_E_PARAM_INVALID);
#endif /* I2C_DEV_ERROR_DETECT */
        ret = -1;
    } else {
        SuspendAllInterrupts();
        msgs[0].addr = addr;
        msgs[0].buf = &reg;
        msgs[0].len = 1;
        msgs[0].rw_flag = I2C_M_W;

        msgs[1].addr = addr;
        msgs[1].buf = &data;
        msgs[1].len = 1;
        msgs[1].rw_flag = I2C_M_W | I2C_M_NOSTART;
        ret = I2c_transfer(adap, msgs, 2);
        ResumeAllInterrupts();
    }

    return ret;
}

int I2c_read_reg(I2c_adap_dev_t *adap, uint16 addr, uint8 reg, uint8 *data)
{
    int ret;
    struct I2c_msg msgs[2];
    if (NULL_PTR == adap) {
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)I2C_INSTANCE_ID, (uint8)I2C_READ_ID, (uint8)I2C_E_PARAM_INVALID);
#endif /* I2C_DEV_ERROR_DETECT */
        ret = -1;
    } else {
        SuspendAllInterrupts();
        msgs[0].addr = addr;
        msgs[0].buf = &reg;
        msgs[0].len = 1;
        //msgs[0].rw_flag = I2C_M_W | I2C_M_NOSTART;
        msgs[0].rw_flag = I2C_M_W;

        msgs[1].addr = addr;
        msgs[1].buf = data;
        msgs[1].len = 1;
        msgs[1].rw_flag = I2C_M_R | I2C_M_NOSTART;
        ret = I2c_transfer(adap, msgs, 2);
        ResumeAllInterrupts();  
    }

    return ret;
}

int I2c_register_slave(I2c_adap_dev_t *adap, I2c_slv_cb_t slv_cb)
{
    if ((NULL_PTR == adap) || (NULL_PTR == slv_cb)) {
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)I2C_INSTANCE_ID, (uint8)I2C_REGISTER_SLAVE_ID, (uint8)I2C_E_PARAM_INVALID);
#endif /* I2C_DEV_ERROR_DETECT */
        return -1;
    }

    if (adap->opmode != I2C_SLAVE) {
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)I2C_INSTANCE_ID, (uint8)I2C_REGISTER_SLAVE_ID, (uint8)I2C_E_PARAM_INVALID);
#endif /* I2C_DEV_ERROR_DETECT */
        return -1;
    }

    adap->slv_cb = slv_cb;
    return 0;
}

int I2c_adap_earlyinit(I2c_adap_dev_t *adap, const I2c_adap_cfg_t *cfg)
{
    if ((NULL_PTR == adap) || (NULL_PTR == cfg)) {
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)I2C_INSTANCE_ID, (uint8)I2C_ADAP_EARLYINIT_ID, (uint8)I2C_E_PARAM_INVALID);
#endif /* I2C_DEV_ERROR_DETECT */
        return -1;
    }

    adap->base = cfg->base;
    adap->clk = cfg->clk;
    adap->enable = cfg->enable;
    adap->opmode = cfg->opmode;
    adap->speed = cfg->speed;

    return 0;
}

int I2c_adap_init(I2c_adap_dev_t *adap)
{
    if (NULL_PTR == adap) {
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)I2C_INSTANCE_ID, (uint8)I2C_ADAP_INIT_ID, (uint8)I2C_E_PARAM_INVALID);
#endif /* I2C_DEV_ERROR_DETECT */
        return -1;
    }

    if (!adap->enable) {
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)I2C_INSTANCE_ID, (uint8)I2C_ADAP_INIT_ID, (uint8)I2C_E_NOT_ENABLE);
#endif /* I2C_DEV_ERROR_DETECT */
        return -1;
    }

    if (NULL_PTR == adap->ops->I2c_init) {
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)I2C_INSTANCE_ID, (uint8)I2C_ADAP_INIT_ID, (uint8)I2C_E_PARAM_INVALID);
#endif /* I2C_DEV_ERROR_DETECT */
        return -1;
    }

    adap->status = adap->ops->I2c_init(adap);
    if ((adap->status) != I2C_INIT_STATE) {
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)I2C_INSTANCE_ID, (uint8)I2C_ADAP_INIT_ID, (uint8)I2C_E_INIT_FAILURE);
#endif /* I2C_DEV_ERROR_DETECT */
        return -1;
    }

    return 0;
}

int I2c_Init(void)
{
    int ret = 0;
    const I2c_adap_cfg_t *cfgconvert;
    sdrv_I2c_mdev_t *mdev;

    /* PRQA S 2877 2*/
    for (int I2cId = 0; I2cId < I2C_CHN_NUM; I2cId++) {
        cfgconvert = &I2c_aChannelCfg[I2cId];

        if ((cfgconvert->enable == I2C_EN) && (0 == ret)) {
            mdev = &I2c_sdrv_dev[I2cId].dev_type.mdev;
            mdev->msgs = I2c_msgs[I2cId];

            for (int msgid = 0; msgid < SDRV_I2C_MSG_NUM_MAX; msgid++) {
                mdev->msgs[msgid].addr_flag = cfgconvert->addr_flag;
                mdev->msgs[msgid].polling = cfgconvert->polling;
            }

            I2cGlobalDev[I2cId] = sdrv_I2c_adap_probe(&I2c_sdrv_dev[I2cId], cfgconvert, cfgconvert->channelid );
            ret = I2c_adap_init(I2cGlobalDev[I2cId]);
        } else {
            I2cGlobalDev[I2cId] = &I2c_sdrv_dev[I2cId].adap;
            I2cGlobalDev[I2cId]->status = I2C_UNINIT_STATE;
        }
    }

    return ret;
}

void I2c_mainfunction_handling(void)
{
    /* PRQA S 2877 2 */
    for (uint8 I2cId = 0; I2cId < I2C_CHN_NUM; I2cId++)
        I2c_MainFunctionHandling(I2cId);
}

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"
