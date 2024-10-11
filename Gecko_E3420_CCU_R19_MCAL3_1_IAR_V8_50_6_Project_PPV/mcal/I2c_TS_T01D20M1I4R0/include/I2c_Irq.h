/**
 * @file I2c_Irq.h
 * @Common I2c interrupt driver header.
 *
 * @Copyright (c) 2020  Semidrive Semiconductor.
 * @All rights reserved.
 *
 **/

#ifndef I2c_IRQ_H
#define I2c_IRQ_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Mcal.h"
#include "I2c_Cfg.h"

#define I2C_HWCHANNEL_NUMBER    (8U)

typedef void (*I2c_irq_handle_t)(void);

#define I2C_ISR(I2cId) \
ISR(I2c##I2cId##_IrqHandler)\
{\
    /* driver not uesd irq number */\
    void *arg;\
    for(uint8 I2c_Num = 0; I2c_Num < I2C_CHN_NUM; I2c_Num++)\
    {\
        if(I2cId == I2cGlobalDev[I2c_Num]->id) {\
            arg = I2cGlobalDev[I2c_Num];\
            if(I2cGlobalDev[I2c_Num]->opmode == I2C_MASTER){\
                sdrv_I2c_master_irq_handler(0, arg);\
            }else{\
                sdrv_I2c_slave_irq_handler(0, arg);\
            }\
        }\
    }\
}

ISR(I2c1_IrqHandler);
ISR(I2c2_IrqHandler);
ISR(I2c3_IrqHandler);
ISR(I2c4_IrqHandler);
ISR(I2c5_IrqHandler);
ISR(I2c6_IrqHandler);
ISR(I2c7_IrqHandler);
ISR(I2c8_IrqHandler);

#endif /* I2c_IRQs_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
