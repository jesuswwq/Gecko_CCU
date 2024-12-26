/********************************************************
 *        Copyright(c) 2020    Semidrive                *
 *        All rights reserved.                          *
 ********************************************************/
#include "RegHelper.h"
#include "Mcu_Mpu.h"
#include "RegBase.h"
#include "RegHelper.h"
#include "Mcu_ScrBits.h"
#include "Mcu_Scr.h"
#include "lnk_sym.h"
#include "debug.h"

scr_signal_t g_adc_mux_scr[] = {
    SCR_SF_ANA_SF_CFG_AMUX_ADC1_CH5N_CSEL_3,
    SCR_SF_ANA_SF_CFG_AMUX_ADC1_CH5P_CSEL_3,
    SCR_SF_ANA_SF_CFG_AMUX_ADC2_CH4N_CSEL_3,
    SCR_SF_ANA_SF_CFG_AMUX_ADC2_CH4P_CSEL_3,
    SCR_SF_ANA_SF_CFG_AMUX_ADC2_CH5N_CSEL_3,
    SCR_SF_ANA_SF_CFG_AMUX_ADC2_CH5P_CSEL_3,
    SCR_SF_ANA_SF_CFG_AMUX_ADC2_CH6N_CSEL_3,
    SCR_SF_ANA_SF_CFG_AMUX_ADC3_CH5N_CSEL_3,
    SCR_SF_ANA_SF_CFG_AMUX_ADC3_CH5P_CSEL_3,
};

scr_signal_t g_adc_apad_scr[] = {
    SCR_SF_ANA_SF_CFG_APD_A_A4_CTRL_3_0,
    SCR_SF_ANA_SF_CFG_APD_A_A5_CTRL_3_0,
    SCR_SF_ANA_SF_CFG_APD_A_A6_CTRL_3_0,
    SCR_SF_ANA_SF_CFG_APD_A_A7_CTRL_3_0,
    SCR_SF_ANA_SF_CFG_APD_A_A12_CTRL_3_0,
    SCR_SF_ANA_SF_CFG_APD_A_A13_CTRL_3_0,
    SCR_SF_ANA_SF_CFG_APD_A_A14_CTRL_3_0,
    SCR_SF_ANA_SF_CFG_APD_A_A15_CTRL_3_0,

    SCR_SF_ANA_SF_CFG_APD_A_B10_CTRL_3_0,
    SCR_SF_ANA_SF_CFG_APD_A_B11_CTRL_3_0,

    SCR_SF_ANA_SF_CFG_APD_A_C0_CTRL_3_0,
    SCR_SF_ANA_SF_CFG_APD_A_C1_CTRL_3_0,
    SCR_SF_ANA_SF_CFG_APD_A_C2_CTRL_3_0,
    SCR_SF_ANA_SF_CFG_APD_A_C3_CTRL_3_0,
    SCR_SF_ANA_SF_CFG_APD_A_C4_CTRL_3_0,
    SCR_SF_ANA_SF_CFG_APD_A_C5_CTRL_3_0,
    SCR_SF_ANA_SF_CFG_APD_A_C6_CTRL_3_0,
    SCR_SF_ANA_SF_CFG_APD_A_C7_CTRL_3_0,
};

/* Config adc analog scr */
void board_scr_init(void)
{
    for (uint8 cnt =  0; cnt < sizeof(g_adc_mux_scr) / sizeof(scr_signal_t); cnt++) {
        Mcu_ScrSetBit(&g_adc_mux_scr[cnt], 0);
    }

    for (uint8 cnt = 0; cnt < sizeof(g_adc_apad_scr) / sizeof(scr_signal_t); cnt++) {
        Mcu_ScrSetBit(&g_adc_apad_scr[cnt], 1);
    }
}
uint32 board_init(void)
{
    /* display mux need clr rterm_en if GPIOLx is not used for display */
    uint32 reg;

    for (uint32 i = 0; i < 5; i++) {
        reg = readl(APB_DISP_MUX_BASE + 0x1010 + i * 4);
        reg &= (~0x02);
        writel(reg, APB_DISP_MUX_BASE + 0x1010 + i * 4);
    }

    /* */
    board_scr_init();

    return 0;
}

void mpu_init(void)
{
    int ret = 0;
    uint8 region = 0;

    mpu_enable(FALSE);

    mpu_reset();

    ret = mpu_add_region(region++, 0, 0x100000000, MPU_REGION_DEVICE);
    if (ret != 0) {
        while (1) {}
    }

    /*RAM1/RAM2/IRAM3/IRAM4*/
    ret = mpu_add_region(region++, 0x400000, 0x400000, MPU_REGION_NORMAL);
    if (ret != 0) {
        while (1) {}
    }

    /*GAMA*/
    ret = mpu_add_region(region++, 0x1000000, 0x400000, MPU_REGION_STRONGORDERED);
    if (ret != 0) {
        while (1) {}
    }

    /*TCM and Cache*/
    ret = mpu_add_region(region++, 0x0, 0x20000, MPU_REGION_NORMAL);
    if (ret != 0) {
        while (1) {}
    }

    /*override the vector table region for protection */
    ret = mpu_add_region(region++, 0x0, 0x40, MPU_REGION_READONLY);
    if (ret != 0) {
        while (1) {}
    }
#if (!defined PROJECT_APP)
    /*Flash region 16MB max*/
    ret = mpu_add_region(region++, 0x10000000, 0x1000000, MPU_REGION_NORMAL);
    if (ret != 0) {
        while (1) {}
    }
#else
    ret = mpu_add_region(region++, 0, 0x400000, MPU_REGION_NORMAL);
    if (ret != 0) {
        while (1) {}
    }
#endif
    /*Peripheral*/
    ret = mpu_add_region(region++, 0xf0000000,0x10000000, MPU_REGION_DEVICE);
    if (ret != 0) {
        while (1) {}
    }

    /*DMA Buffer*/
    ret = mpu_add_region(region++, (uint32)__dma_buffer_start, (uint32)__dma_buffer_end - (uint32)__dma_buffer_start, MPU_REGION_STRONGORDERED);
    if (ret != 0) {
        while (1) {}
    }

    /*hsm*/
    ret = mpu_add_region(region++, 0x02100000,0x100000, MPU_REGION_DEVICE);
    if (ret != 0) {
        while (1) {}
    }

    mpu_enable(TRUE);
}
