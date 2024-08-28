/**
 * @file I2c_Cfg.c
 * @brief I2c template generate file.
 * @details Compatible to "Specification of CDD Driver, CP, 4.3.1"
 * @date 2024-03-08 16:29:00
 */

/********************************************************
 *        Copyright(c) 2020    Semidrive                *
 *        All rights reserved.                          *
 ********************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#include "Mcu_Modules.h"
#include "__regs_base.h"
#include "I2c_Cfg.h"

#define I2C_START_SEC_CONST_UNSPECIFIED
#include "I2c_MemMap.h"


CONST(I2c_adap_cfg_t, I2C_CONST) I2c_aChannelCfg[I2C_CHN_NUM] = {
    {
        /* I2c base address */
        (uint32)APB_I2C1_BASE,
        (I2c_chan_id)I2C_ID_1,


        /* Clk */
        (uint32)133200000,

        /* Channel Enable */
        (I2c_chan_en_t)I2C_EN,

        /* OperatingMode */
        (I2c_opmode_t)I2C_MASTER,

        /* Channel Baud Rate */
        (I2c_speed_t)I2C_FSPEED,

        /* AddressBitConfiguration */
        (I2c_addr_bits_t)I2C_ADDR7B,

        /* Transfer Mode polling/irq/mainfunction */
        (I2c_trans_mod_t)I2C_POLLING_MOD,
    },
    {
        /* I2c base address */
        (uint32)APB_I2C2_BASE,
        (I2c_chan_id)I2C_ID_2,


        /* Clk */
        (uint32)133200000,

        /* Channel Enable */
        (I2c_chan_en_t)I2C_EN,

        /* OperatingMode */
        (I2c_opmode_t)I2C_MASTER,

        /* Channel Baud Rate */
        (I2c_speed_t)I2C_FSPEED,

        /* AddressBitConfiguration */
        (I2c_addr_bits_t)I2C_ADDR7B,

        /* Transfer Mode polling/irq/mainfunction */
        (I2c_trans_mod_t)I2C_POLLING_MOD,
    },
    {
        /* I2c base address */
        (uint32)APB_I2C3_BASE,
        (I2c_chan_id)I2C_ID_3,


        /* Clk */
        (uint32)133200000,

        /* Channel Enable */
        (I2c_chan_en_t)I2C_EN,

        /* OperatingMode */
        (I2c_opmode_t)I2C_MASTER,

        /* Channel Baud Rate */
        (I2c_speed_t)I2C_FSPEED,

        /* AddressBitConfiguration */
        (I2c_addr_bits_t)I2C_ADDR7B,

        /* Transfer Mode polling/irq/mainfunction */
        (I2c_trans_mod_t)I2C_POLLING_MOD,
    },
    {
        /* I2c base address */
        (uint32)APB_I2C8_BASE,
        (I2c_chan_id)I2C_ID_8,

        /* Clk */
        (uint32)133200000,

        /* Channel Enable */
        (I2c_chan_en_t)I2C_EN,

        /* OperatingMode */
        (I2c_opmode_t)I2C_MASTER,

        /* Channel Baud Rate */
        (I2c_speed_t)I2C_FSPEED,

        /* AddressBitConfiguration */
        (I2c_addr_bits_t)I2C_ADDR7B,

        /* Transfer Mode polling/irq/mainfunction */
        (I2c_trans_mod_t)I2C_POLLING_MOD,
    },
};


#define I2C_STOP_SEC_CONST_UNSPECIFIED
#include "I2c_MemMap.h"

#ifdef __cplusplus
}
#endif
