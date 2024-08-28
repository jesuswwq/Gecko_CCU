/**
 * @file Sdrv_I2c.c
 * @low level sdrv i2c driver file.
 *
 * @Copyright (c) 2020  Semidrive Semiconductor.
 * @All rights reserved.
 *
 **/

#include "RegHelper.h"
#include "Mcu_Delay.h"
#include "Sdrv_I2c.h"

#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

uint8 sdrv_i2c_lld_recv_data(uint32 base)
{
    return REG_READ32(base + I2C_RXFIFO);
}

void sdrv_i2c_lld_send_data(uint32 base, uint8 data)
{
    REG_WRITE32(data, base + I2C_TXFIFO);
}

uint32 sdrv_i2c_lld_get_psr0_stat(uint32 base)
{
    return REG_READ32(base + I2C_PSR0);
}

uint32 sdrv_i2c_lld_get_wspace(uint32 base)
{
    return (REG_READ32(base + I2C_FSR) >> I2C_FSR_EMPTYLVL_BIT) & I2C_FSR_EMPTYLVL_MASK;
}

uint32 sdrv_i2c_lld_get_rspace(uint32 base)
{
    return (REG_READ32(base + I2C_FSR) >> I2C_FSR_FILLLVL_BIT) & I2C_FSR_FILLLVL_MASK;
}

void sdrv_i2c_lld_set_watermark(uint32 base, uint8 tx_lvl,
                                uint8 rx_lvl)
{
    REG_RMW32(base + I2C_FCR, I2C_FCR_TXWMLVL_BIT, I2C_FCR_TXWMLVL_LEN, tx_lvl);
    REG_RMW32(base + I2C_FCR, I2C_FCR_RXWMLVL_BIT, I2C_FCR_RXWMLVL_LEN, rx_lvl);
}

int sdrv_i2c_lld_clear_fifo(uint32 base)
{
    uint32 val = 0U;
    uint32 timeout = 0U;
    int retval = 0U;

    REG_RMW32(base + I2C_FCR, I2C_FCR_CLRF_BIT, I2C_FCR_CLRF_LEN, 0x1U);

    /* waiting for clear fifo finshed */
    do {
        /* wait max time 5*pclk + 5*sclk is about 1us */
        val = (REG_READ32(base + I2C_FCR) >> I2C_FCR_CLRF_BIT) & I2C_FCR_CLRF_MASK;
    } while ((0x1U == val) && (timeout++ < 1000U));

    if (timeout < 1000U)
        retval = 0;
    else
        retval = -1;

    return retval;
}

void sdrv_i2c_lld_set_cmdcsr0(uint32 base, uint32 cmdcsr0)
{
    REG_WRITE32(cmdcsr0, base + I2C_CMDCSR0);
}

void sdrv_i2c_lld_set_cmdcsr1(uint32 base, uint32 cmdcsr1)
{
    REG_WRITE32(cmdcsr1, base + I2C_CMDCSR1);
}

void sdrv_i2c_lld_set_cmdcsr2(uint32 base, uint32 cmdcsr2)
{
    REG_WRITE32(cmdcsr2, base + I2C_CMDCSR2);
}

void sdrv_i2c_lld_set_cmdcsr3(uint32 base, uint32 cmdcsr3)
{
    REG_WRITE32(cmdcsr3, base + I2C_CMDCSR3);
}

uint32 sdrv_i2c_lld_get_cmdcsr0(uint32 base)
{
    return REG_READ32(base + I2C_CMDCSR0);
}

uint32 sdrv_i2c_lld_get_cmdcsr1(uint32 base)
{
    return REG_READ32(base + I2C_CMDCSR1);
}

uint32 sdrv_i2c_lld_get_cmdcsr2(uint32 base)
{
    return REG_READ32(base + I2C_CMDCSR2);
}

uint32 sdrv_i2c_lld_get_cmdcsr3(uint32 base)
{
    return REG_READ32(base + I2C_CMDCSR3);
}

void sdrv_i2c_lld_clear_int(uint32 base)
{
    REG_WRITE32(~0x0, base + I2C_INTR0);
    REG_WRITE32(~0x0, base + I2C_INTR1);
    REG_WRITE32(~0x0, base + I2C_INTR2);
    REG_WRITE32(~0x0, base + I2C_INTR3);
}

uint32 sdrv_i2c_lld_get_int0_stat(uint32 base)
{
    return REG_READ32(base + I2C_INTR0);
}

uint32 sdrv_i2c_lld_get_int1_stat(uint32 base)
{
    return REG_READ32(base + I2C_INTR1);
}

uint32 sdrv_i2c_lld_get_int2_stat(uint32 base)
{
    return REG_READ32(base + I2C_INTR2);
}

uint32 sdrv_i2c_lld_get_int3_stat(uint32 base)
{
    return REG_READ32(base + I2C_INTR3);
}

void sdrv_i2c_lld_unmask_int0(uint32 base, uint32 int_flag)
{
    REG_WRITE32(int_flag, base + I2C_INTEN0);
}

void sdrv_i2c_lld_unmask_int1(uint32 base, uint32 int_flag)
{
    REG_WRITE32(int_flag, base + I2C_INTEN1);
}

void sdrv_i2c_lld_unmask_int2(uint32 base, uint32 int_flag)
{
    REG_WRITE32(int_flag, base + I2C_INTEN2);
}

void sdrv_i2c_lld_unmask_int3(uint32 base, uint32 int_flag)
{
    REG_WRITE32(int_flag, base + I2C_INTEN3);
}

void sdrv_i2c_lld_set_IO0(uint32 base, uint32 val)
{
    REG_WRITE32(val, base + I2C_PCR8);
}

void sdrv_i2c_lld_set_IO1(uint32 base, uint32 val)
{
    REG_WRITE32(val, base + I2C_PCR9);
}

void sdrv_i2c_lld_set_IO2(uint32 base, uint32 val)
{
    REG_WRITE32(val, base + I2C_PCR10);
}

void sdrv_i2c_lld_set_IO3(uint32 base, uint32 val)
{
    REG_WRITE32(val, base + I2C_PCR11);
}

void sdrv_i2c_lld_set_speed(uint32 base, uint32 speed_mode)
{
    REG_RMW32(base + I2C_PCR0, I2C_PCR0_SPEED_BIT, I2C_PCR0_SPEED_LEN, speed_mode);
}

void sdrv_i2c_lld_set_prescale(uint32 base, uint32 prescale)
{
    REG_RMW32(base + I2C_PCR0, I2C_PCR0_PRESCALE_BIT, I2C_PCR0_PRESCALE_LEN, prescale);
}

void sdrv_i2c_lld_set_slvaddr(uint32 base, uint16 addr)
{
    REG_RMW32(base + I2C_PCR1, I2C_PCR1_DAR_BIT, I2C_PCR1_DAR_LEN, addr);
}

void sdrv_i2c_lld_set_timing(uint32 base,
                             uint32 pcr2, uint32 pcr3, uint32 pcr4, uint32 pcr5)
{
    REG_WRITE32(pcr2, base + I2C_PCR2);
    REG_WRITE32(pcr3, base + I2C_PCR3);
    REG_WRITE32(pcr4, base + I2C_PCR4);
    REG_WRITE32(pcr5, base + I2C_PCR5);
}

void sdrv_i2c_lld_set_opmode(uint32 base, uint32 opmode)
{
    REG_RMW32(base + I2C_MCR0, I2C_MCR0_OPMOD_BIT, I2C_MCR0_OPMOD_LEN, opmode);
}

void sdrv_i2c_lld_disable(uint32 base)
{
    REG_RMW32(base + I2C_MCR0, I2C_MCR0_MODEN_BIT, I2C_MCR0_MODEN_LEN, 0x0U);
}

void sdrv_i2c_lld_enable(uint32 base)
{
    REG_RMW32(base + I2C_MCR0, I2C_MCR0_MODEN_BIT, I2C_MCR0_MODEN_LEN, 0x1U);
}

int sdrv_i2c_lld_reset(uint32 base)
{
    uint32 timeout = 0U;
    uint32 val = 0U;
    sint32 retval = 0U;

    REG_RMW32(base + I2C_MCR0, I2C_MCR0_MODRST_BIT, I2C_MCR0_MODRST_LEN, 0x1U);

    /* waiting for reset finished */
    do {
        /* wait max time 5*pclk + 5*sclk is about 1us */
        val = (REG_READ32(base + I2C_MCR0) >> I2C_MCR0_MODRST_BIT) & I2C_MCR0_MODRST_MASK;
    } while ((0x1U == val) && (timeout++ < 1000U));

    if (timeout < 1000U)
        retval = 0;
    else
        retval = -1;

    return retval;
}

void sdrv_i2c_lld_dump_reg(uint32 base, uint32 *reg_val)
{
    reg_val[0] = REG_READ32(base + I2C_MCR0);
    reg_val[1] = REG_READ32(base + I2C_INTR0);
    reg_val[2] = REG_READ32(base + I2C_INTR1);
    reg_val[3] = REG_READ32(base + I2C_INTR2);
    reg_val[4] = REG_READ32(base + I2C_INTR3);
    reg_val[5] = REG_READ32(base + I2C_INTEN0);
    reg_val[6] = REG_READ32(base + I2C_INTEN1);
    reg_val[7] = REG_READ32(base + I2C_INTEN2);
    reg_val[8] = REG_READ32(base + I2C_INTEN3);
    reg_val[9] = REG_READ32(base + I2C_CMDCSR0);
    reg_val[10] = REG_READ32(base + I2C_CMDCSR1);
    reg_val[11] = REG_READ32(base + I2C_CMDCSR2);
    reg_val[12] = REG_READ32(base + I2C_CMDCSR3);
    reg_val[13] = REG_READ32(base + I2C_FCR);
    reg_val[14] = REG_READ32(base + I2C_FSR);
    reg_val[15] = REG_READ32(base + I2C_DMACR);
    reg_val[16] = REG_READ32(base + I2C_DMASR);
    reg_val[17] = REG_READ32(base + I2C_PCR0);
    reg_val[18] = REG_READ32(base + I2C_PCR1);
    reg_val[19] = REG_READ32(base + I2C_PCR2);
    reg_val[20] = REG_READ32(base + I2C_PCR3);
    reg_val[21] = REG_READ32(base + I2C_PCR4);
    reg_val[22] = REG_READ32(base + I2C_PCR5);
    reg_val[23] = REG_READ32(base + I2C_PCR6);
    reg_val[24] = REG_READ32(base + I2C_PCR7);
    reg_val[25] = REG_READ32(base + I2C_PCR8);
    reg_val[26] = REG_READ32(base + I2C_PCR9);
    reg_val[27] = REG_READ32(base + I2C_PCR10);
    reg_val[28] = REG_READ32(base + I2C_PCR11);
    reg_val[29] = REG_READ32(base + I2C_PSR0);
}

void sdrv_i2c_lld_write_reg(uint32 base, uint32 reg, uint32 val)
{
    REG_WRITE32(val, base + reg);
}

void sdrv_i2c_lld_read_reg(uint32 base, uint32 reg, uint32 *val)
{
    if (NULL_PTR != val)
        *val = REG_READ32(base + reg);
}

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"
