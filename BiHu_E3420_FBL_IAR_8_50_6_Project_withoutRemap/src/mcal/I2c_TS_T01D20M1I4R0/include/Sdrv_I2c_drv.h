/**
 * @file sdrv_I2c_drv.h
 * @brief sdrv I2c driver header file.
 *
 * @Copyright (c) 2020  Semidrive Semiconductor.
 * @All rights reserved.
 *
 */

#ifndef SDRV_I2C_DRV_H_
#define SDRV_I2C_DRV_H_

#include "I2c.h"
#include "Mcu_Delay.h"

#define SDRV_I2C_RETRY 3
#define SDRV_I2C_TIMEOUT 3000
#define SDRV_I2C_MSG_IDLE 0
#define SDRV_I2C_MSG_RW 1
#define SDRV_I2C_SLV_ADDR 0x34

#define min(a, b)   (a) < (b) ? a : b

#define CAL_BASE(value, clk_khz)     (value * clk_khz / 1000000)
#define CAL_SCLL(value, clk_khz)     (CAL_BASE(value, clk_khz))
#define CAL_TA(value, clk_khz)       (CAL_BASE(value, clk_khz))
#define CAL_DVDAT(value, clk_khz)    (CAL_BASE(value, clk_khz) / 2 - 1)
#define CAL_UNIT(value)              (value)
#define CAL_MEXT(value, clk_khz)     (CAL_BASE(value, clk_khz))
#define CAL_SEXT(value, clk_khz)     (CAL_BASE(value, clk_khz))
#define CAL_STUCK(value, clk_khz)    (value * clk_khz / 65536)
#define CAL_SDARXHLD(value, clk_khz) (CAL_BASE(value, clk_khz))
#define CAL_DATSPL(value)            (value)
#define CAL_BUF(value, clk_khz)      ((uint32)log2(CAL_BASE(value, clk_khz) / 4))
#define CAL_IDLE(value, clk_khz)     (CAL_BASE(value, clk_khz))

typedef struct sdrv_I2c_timing_cfg {
    uint32 timscll;
    uint32 timtasclh;
    uint32 timtascll;
    uint32 timtasdal;
    uint32 timdvdat;
    uint32 timscll_h;
    uint32 timtasclh_h;
    uint32 timtascll_h;
    uint32 timtasdal_h;
    uint32 timdvdat_h;
    uint32 timunit;
    uint32 timmext;
    uint32 timsext;
    uint32 timstuck;
    uint32 timsdarxhld;
    uint32 timdatspl;
    uint32 timbuf;
    uint32 timidle;
} sdrv_I2c_timing_cfg_t;

typedef struct sdrv_I2c_timing {
    uint32 divs;
    uint32 pcr2;
    uint32 pcr3;
    uint32 pcr4;
    uint32 pcr5;
} sdrv_I2c_timing_t;

typedef struct sdrv_I2c_mdev {
    uint32 timeout;
    void* event;
    int status;
    struct I2c_msg *msgs;
    int num;
    struct I2c_msg *cur_msg;
    int cur_msg_idx;
    int cur_msg_stat;
    int cur_cmd_done;
    uint16 cur_msg_len;
} sdrv_I2c_mdev_t;

typedef struct sdrv_I2c_sdev {
    bool ctlbyte_det;
    enum I2c_slv_event rw_event;
    bool first_read_req;
    uint32 rw_req_len;
    uint8 slv_buf_pos;
    uint8 slv_buf[255];
} sdrv_I2c_sdev_t;

typedef union sdrv_I2c_dev_type {
    sdrv_I2c_mdev_t mdev;
    sdrv_I2c_sdev_t sdev;
} sdrv_I2c_dev_type_t;

typedef struct sdrv_I2c_dev {
    I2c_adap_dev_t adap;
    sdrv_I2c_dev_type_t dev_type;
} sdrv_I2c_dev_t;

int sdrv_I2c_master_irq_handler(uint32 irq, void *arg);
int sdrv_I2c_slave_irq_handler(uint32 irq, void *arg);
I2c_adap_dev_t *sdrv_I2c_adap_probe(sdrv_I2c_dev_t *dev, const I2c_adap_cfg_t *cfg, int id);
void I2c_MainFunctionHandling(uint8 I2cId);

#endif
