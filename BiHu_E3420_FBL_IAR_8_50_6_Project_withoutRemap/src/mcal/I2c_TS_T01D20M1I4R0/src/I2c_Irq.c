/**
 * @file I2c_Irq.c
 * @brief I2c interrupt driver interface file.
 *
 * @Copyright (c) 2020  Semidrive Semiconductor.
 * @All rights reserved.
 **/

#include "I2c_Irq.h"

#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

/**
 * @brief I2c1-I2c8 interrupt service routine.
 */
/* PRQA S 2877 EOF */
I2C_ISR(1)
I2C_ISR(2)
I2C_ISR(3)
I2C_ISR(4)
I2C_ISR(5)
I2C_ISR(6)
I2C_ISR(7)
I2C_ISR(8)

I2c_irq_handle_t I2c_IrqHandle[I2C_HWCHANNEL_NUMBER] = {
    I2c1_IrqHandler,
    I2c2_IrqHandler,
    I2c3_IrqHandler,
    I2c4_IrqHandler,
    I2c5_IrqHandler,
    I2c6_IrqHandler,
    I2c7_IrqHandler,
    I2c8_IrqHandler,
};

I2c_irq_handle_t I2c_Get_Irq_Handle(uint8 I2cId)
{
    return I2c_IrqHandle[I2cId - 1];
}

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"
