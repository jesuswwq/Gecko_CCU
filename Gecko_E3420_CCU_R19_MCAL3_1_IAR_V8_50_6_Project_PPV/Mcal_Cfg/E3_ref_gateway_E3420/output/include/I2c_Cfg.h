/**
 * @file I2c_Cfg.h
 * @brief I2c template generate header file.
 * @details Compatible to "Specification of CDD Driver, CP, 4.3.1"
 * @date 2024-03-08 16:29:00
 */

/********************************************************
 *        Copyright(c) 2020    Semidrive                *
 *        All rights reserved.                          *
 ********************************************************/

#ifndef I2c_CFG_H
#define I2c_CFG_H

#include "I2c.h"
#include "Sdrv_I2c_drv.h"

#define I2C_VERSION_INFO_API (STD_OFF)

#define I2C_DEV_ERROR_DETECT (STD_OFF)

#define SDRV_I2C_MSG_NUM_MAX 2U

#define I2C_CHN_NUM 4U


/*------------------[Symbolic Names of Channels]-----------------------*/
#define I2cConf_I2cChannel_I2cChannel_I2C1 (0u)
#define I2cConf_I2cChannel_I2cChannel_I2C2 (1u)
#define I2cConf_I2cChannel_I2cChannel_I2C3 (2u)
#define I2cConf_I2cChannel_I2cChannel_I2C8 (3u)

extern sdrv_I2c_dev_t I2c_sdrv_dev[I2C_CHN_NUM];
extern I2c_adap_dev_t *I2cGlobalDev[I2C_CHN_NUM];
extern struct I2c_msg I2c_msgs[I2C_CHN_NUM][SDRV_I2C_MSG_NUM_MAX];
extern CONST(I2c_adap_cfg_t, I2C_CONST) I2c_aChannelCfg[I2C_CHN_NUM];

#endif
