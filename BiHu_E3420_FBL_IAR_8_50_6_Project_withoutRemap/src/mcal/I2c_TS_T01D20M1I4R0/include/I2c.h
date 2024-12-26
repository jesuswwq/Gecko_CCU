/**
 * @file I2c.h
 * @Common I2c driver header.
 *
 * @Copyright (c) 2020  Semidrive Semiconductor.
 * @All rights reserved.
 *
 **/

#ifndef I2C_UAPI_H_
#define I2C_UAPI_H_
#include "Platform_Types.h"

#define I2C_MODULE_ID                   (255U)
#define I2C_INSTANCE_ID                 (0u)

#define I2C_E_PARAM_INVALID             (0x01u)
#define I2C_E_UNINIT                    (0x02u)
#define I2C_E_INIT_FAILURE              (0x03u)
#define I2C_E_NOT_ENABLE                (0x04u)
#define I2C_E_CLEAR_FIFO_FAILURE        (0x05u)
#define I2C_E_TRANSMIT_EXCEPTION        (0x06u)
#define I2C_E_INTERRUPT_EXCEPTION       (0x07u)
#define I2C_E_TIMMING_EXCEPTION         (0x08u)
#define I2C_E_RESET_EXCEPTION           (0x09u)

#define I2C_TRANSTATE_ID                (0x01u)
#define I2C_INITSTATE_ID                (0x02u)
#define I2C_TRANSFER_ID                 (0x03u)
#define I2C_WRITE_ID                    (0x04u)
#define I2C_READ_ID                     (0x05u)
#define I2C_WRITE_READ_ID               (0x06u)
#define I2C_REGISTER_SLAVE_ID           (0x07u)
#define I2C_ADAP_EARLYINIT_ID           (0x08u)
#define I2C_ADAP_INIT_ID                (0x09u)
#define I2C_MASTER_IRQ_HANDLER_ID       (0x0Au)
#define I2C_SLAVE_IRQ_HANDLER_ID        (0x0Bu)
#define I2C_JOBFUNCTION_ID              (0x0Cu)
#define I2C_INIT_ID                     (0x0Du)

enum I2c_trans_st {
    I2C_IDLE_STATE,
    I2C_BUSY_STATE,
    I2C_FAIL_STATE,
};

enum I2c_init_st {
    I2C_UNINIT_STATE,
    I2C_INIT_STATE,
};

typedef enum I2c_trans_mod {
    I2C_POLLING_MOD,
    I2C_MAINFUN_MOD,
    I2C_INTR_MOD,
} I2c_trans_mod_t;

enum I2c_slv_event {
    I2C_SLV_RW_NONE,
    I2C_SLV_RD_REQUEST,
    I2C_SLV_WR_RECEIVE,
};

typedef enum I2c_speed {
    I2C_SSPEED,         /*! @brief Standard Speed 100KHz */
    I2C_FSPEED,         /*! @brief Fast Speed 400KHz */
    I2C_PSPEED,         /*! @brief Fast-Plus Speed 1MHz */
    I2C_HSPEED,         /*! @brief High Speed 5MHz */
    I2C_USPEED,         /*! @brief Ultra-Fast Speed 5MHz */
} I2c_speed_t;

typedef enum I2c_opmode {
    I2C_MASTER,
    I2C_SLAVE,
    SMB_MASTER,
    SMB_SLAVE,
    PM_MASTER,
    PM_SLAVE,
} I2c_opmode_t;

typedef enum {
    I2C_ADDR7B,
    I2C_ADDR10B,
} I2c_addr_bits_t;

typedef enum {
    I2C_M_W,
    I2C_M_R,
} I2c_rw_flag_t;

typedef enum {
    I2C_DIS,
    I2C_EN,
} I2c_chan_en_t;

typedef enum {
    I2C_ID_1 = 1,
    I2C_ID_2,
    I2C_ID_3 = 3,
    I2C_ID_4,
    I2C_ID_5,
    I2C_ID_6,
    I2C_ID_7,
    I2C_ID_8,

} I2c_chan_id;

typedef struct I2c_adap_cfg I2c_adap_cfg_t;
typedef struct I2c_adap_dev I2c_adap_dev_t;
typedef struct I2c_adap_ops I2c_adap_ops_t;
typedef int (*I2c_slv_cb_t)(I2c_adap_dev_t *adap,
                            enum I2c_slv_event slv_event, uint8 *data, uint16 len);

struct I2c_msg {
    uint16 addr;     /* slave address       */
    uint16 len;      /* msg length          */
    uint8 *buf;      /* pointer to msg data */
#define I2C_M_NOSTART       0x4000
#define I2C_M_REV_DIR_ADDR  0x2000
    uint8 addr_flag; /* I2C_ADDR7 / I2C_ADDR10 */
    uint32 rw_flag;  /* I2C_M_W / I2C_M_R / I2C_M_NOSTART / I2C_M_REV_DIR_ADDR */
    uint8 polling;   /* true for polling for special scene, otherwise ignore */
};

struct I2c_adap_cfg {
    paddr_t base;
    uint8 channelid;
    uint32 irq;
    uint32 clk;
    bool enable;
    enum I2c_opmode opmode;
    enum I2c_speed speed;
    uint8 addr_flag; /* I2C_ADDR7 / I2C_ADDR10 */
    uint8 polling;   /* true for polling for special scene, otherwise ignore */
    struct I2c_msg *msgs;
};

struct I2c_adap_ops {
    int (*I2c_init)(I2c_adap_dev_t *adap);
    int (*I2c_xfer)(I2c_adap_dev_t *adap, struct I2c_msg *msgs, int num);
};

enum I2c_AdapCurState{
    I2C_ADAP_IDLE = 0U,
    I2C_ADAP_BUSY
};

struct I2c_adap_dev {
    paddr_t base;
    uint32 irq;
    uint32 clk;
    bool enable;
    enum I2c_opmode opmode;
    enum I2c_speed speed;
    int id;
    int retry;
    const I2c_adap_ops_t *ops;
    void* lock;
    int status;
    void *priv;
    I2c_slv_cb_t slv_cb;
    enum I2c_trans_st trans_state;
    enum I2c_AdapCurState adap_State;
};

int I2c_transfer(I2c_adap_dev_t *adap, struct I2c_msg *msgs, int num);
int I2c_write(I2c_adap_dev_t *adap, uint16 addr, const uint8 *wbuf, int wlen);
int I2c_read(I2c_adap_dev_t *adap, uint16 addr, uint8 *rbuf, int rlen);
int I2c_write_read(I2c_adap_dev_t *adap, uint16 addr,
                   const uint8 *wbuf, int wlen,  uint8 *rbuf, int rlen);
int I2c_write_reg(I2c_adap_dev_t *adap, uint16 addr, uint8 reg, uint8 data);
int I2c_read_reg(I2c_adap_dev_t *adap, uint16 addr, uint8 reg, uint8 *data);
int I2c_register_slave(I2c_adap_dev_t *adap, I2c_slv_cb_t slv_cb);
int I2c_force_transtate(I2c_adap_dev_t *adap, int set_transtate);
int I2c_get_transtate(I2c_adap_dev_t *adap);
int I2c_get_initstate(I2c_adap_dev_t *adap);
void I2c_mainfunction_handling(void);
int I2c_adap_earlyinit(I2c_adap_dev_t *adap, const I2c_adap_cfg_t *cfg);
int I2c_adap_init(I2c_adap_dev_t *adap);
int I2c_Init(void);

#endif
