/*
 * SEMIDRIVE Copyright Statement
 * Copyright (c) SEMIDRIVE. All rights reserved
 *
 * This software and all rights therein are owned by SEMIDRIVE, and are
 * protected by copyright law and other relevant laws, regulations and
 * protection. Without SEMIDRIVE's prior written consent and/or related rights,
 * please do not use this software or any potion thereof in any form or by any
 * means. You may not reproduce, modify or distribute this software except in
 * compliance with the License. Unless required by applicable law or agreed to
 * in writing, software distributed under the License is distributed on
 * an "AS IS" basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.
 *
 * You should have received a copy of the License along with this program.
 * If not, see <http://www.semidrive.com/licenses/>.
 */

/**
 * @file  dma_cfg.c
 * @brief Semidrive. Dma
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Dma_Drv_Cfg.h"
#include "Dma_Helper.h"
/* dma device driver headers */
#include <sdrv_dma.h>
#include "__regs_base.h"
#include "cdefs.h"
#include "Mcu_Scr.h"
#include "Mcu_ScrBits.h"
#include "Mcu_Scr.h"
#define DEVICE_BASE(dev) DMA_DEVICE_BASE(dev)
#define DMA_DEVICE_BASE(dev) APB_##dev##_BASE

typedef struct sdrv_dma_priv {
    uint32 *irq_id_tab;
    uint32 irq_num;
} sdrv_dma_priv_t;

#ifndef SEMIDRIVE_E3_LITE_SERIES
static sdrv_dma_mux_param_t sf_mux_tbl[] = {
    {DMA_MUX_ID_CANFD1, DEVICE_BASE(CANFD1), 0x80, DMA_MUX_BOTH},
    {DMA_MUX_ID_CANFD2, DEVICE_BASE(CANFD2), 0x80, DMA_MUX_BOTH},
    {DMA_MUX_ID_CANFD3, DEVICE_BASE(CANFD3), 0x80, DMA_MUX_BOTH},
    {DMA_MUX_ID_CANFD4, DEVICE_BASE(CANFD4), 0x80, DMA_MUX_BOTH},
    {DMA_MUX_ID_CANFD5, DEVICE_BASE(CANFD5), 0x80, DMA_MUX_BOTH},
    {DMA_MUX_ID_CANFD6, DEVICE_BASE(CANFD6), 0x80, DMA_MUX_BOTH},
    {DMA_MUX_ID_CANFD7, DEVICE_BASE(CANFD7), 0x80, DMA_MUX_BOTH},
    {DMA_MUX_ID_CANFD8, DEVICE_BASE(CANFD8), 0x80, DMA_MUX_BOTH},
    {DMA_MUX_ID_CANFD9, DEVICE_BASE(CANFD9), 0x80, DMA_MUX_BOTH},
    {DMA_MUX_ID_CANFD10, DEVICE_BASE(CANFD10), 0x80, DMA_MUX_BOTH},
    {DMA_MUX_ID_CANFD11, DEVICE_BASE(CANFD11), 0x80, DMA_MUX_BOTH},
    {DMA_MUX_ID_CANFD12, DEVICE_BASE(CANFD12), 0x80, DMA_MUX_BOTH},
    {DMA_MUX_ID_CANFD13, DEVICE_BASE(CANFD13), 0x80, DMA_MUX_BOTH},
    {DMA_MUX_ID_CANFD14, DEVICE_BASE(CANFD14), 0x80, DMA_MUX_BOTH},
    {DMA_MUX_ID_CANFD15, DEVICE_BASE(CANFD15), 0x80, DMA_MUX_BOTH},
    {DMA_MUX_ID_CANFD16, DEVICE_BASE(CANFD16), 0x80, DMA_MUX_BOTH},
    {DMA_MUX_ID_CANFD17, DEVICE_BASE(CANFD17), 0x80, DMA_MUX_BOTH},
    {DMA_MUX_ID_CANFD18, DEVICE_BASE(CANFD18), 0x80, DMA_MUX_BOTH},
    {DMA_MUX_ID_CANFD19, DEVICE_BASE(CANFD19), 0x80, DMA_MUX_BOTH},
    {DMA_MUX_ID_CANFD20, DEVICE_BASE(CANFD20), 0x80, DMA_MUX_BOTH},
    {DMA_MUX_ID_CANFD21, DEVICE_BASE(CANFD21), 0x80, DMA_MUX_BOTH},
    {DMA_MUX_ID_CANFD22, DEVICE_BASE(CANFD22), 0x80, DMA_MUX_BOTH},
    {DMA_MUX_ID_CANFD23, DEVICE_BASE(CANFD23), 0x80, DMA_MUX_BOTH},
    {DMA_MUX_ID_CANFD24, DEVICE_BASE(CANFD24), 0x80, DMA_MUX_BOTH},

    {DMA_MUX_ID_I2C1, DEVICE_BASE(I2C1), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_I2C2, DEVICE_BASE(I2C2), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_I2C3, DEVICE_BASE(I2C3), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_I2C4, DEVICE_BASE(I2C4), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_I2C5, DEVICE_BASE(I2C5), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_I2C6, DEVICE_BASE(I2C6), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_I2C7, DEVICE_BASE(I2C7), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_I2C8, DEVICE_BASE(I2C8), 0x200, DMA_MUX_WR},

    {DMA_MUX_ID_I2C1, DEVICE_BASE(I2C1), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_I2C2, DEVICE_BASE(I2C2), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_I2C3, DEVICE_BASE(I2C3), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_I2C4, DEVICE_BASE(I2C4), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_I2C5, DEVICE_BASE(I2C5), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_I2C6, DEVICE_BASE(I2C6), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_I2C7, DEVICE_BASE(I2C7), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_I2C8, DEVICE_BASE(I2C8), 0x300, DMA_MUX_RD},

    {DMA_MUX_ID_XSPI1_A_RD, DEVICE_BASE(XSPI1PORTA), 0x380, DMA_MUX_RD},
    {DMA_MUX_ID_XSPI1_A_WR, DEVICE_BASE(XSPI1PORTA), 0x280, DMA_MUX_WR},
    {DMA_MUX_ID_XSPI1_B_RD, DEVICE_BASE(XSPI1PORTB), 0x380, DMA_MUX_RD},
    {DMA_MUX_ID_XSPI1_B_WR, DEVICE_BASE(XSPI1PORTB), 0x280, DMA_MUX_WR},
    {DMA_MUX_ID_XSPI2_A_RD, DEVICE_BASE(XSPI2PORTA), 0x380, DMA_MUX_RD},
    {DMA_MUX_ID_XSPI2_A_WR, DEVICE_BASE(XSPI2PORTA), 0x280, DMA_MUX_WR},
    {DMA_MUX_ID_XSPI2_B_RD, DEVICE_BASE(XSPI2PORTB), 0x380, DMA_MUX_RD},
    {DMA_MUX_ID_XSPI2_B_WR, DEVICE_BASE(XSPI2PORTB), 0x280, DMA_MUX_WR},

    {DMA_MUX_ID_SPI1_RX, DEVICE_BASE(SPI1), 0x3000, DMA_MUX_RD},
    {DMA_MUX_ID_SPI1_TX, DEVICE_BASE(SPI1), 0x2000, DMA_MUX_WR},
    {DMA_MUX_ID_SPI2_RX, DEVICE_BASE(SPI2), 0x3000, DMA_MUX_RD},
    {DMA_MUX_ID_SPI2_TX, DEVICE_BASE(SPI2), 0x2000, DMA_MUX_WR},
    {DMA_MUX_ID_SPI3_RX, DEVICE_BASE(SPI3), 0x3000, DMA_MUX_RD},
    {DMA_MUX_ID_SPI3_TX, DEVICE_BASE(SPI3), 0x2000, DMA_MUX_WR},
    {DMA_MUX_ID_SPI4_RX, DEVICE_BASE(SPI4), 0x3000, DMA_MUX_RD},
    {DMA_MUX_ID_SPI4_TX, DEVICE_BASE(SPI4), 0x2000, DMA_MUX_WR},
    {DMA_MUX_ID_SPI5_RX, DEVICE_BASE(SPI5), 0x3000, DMA_MUX_RD},
    {DMA_MUX_ID_SPI5_TX, DEVICE_BASE(SPI5), 0x2000, DMA_MUX_WR},
    {DMA_MUX_ID_SPI6_RX, DEVICE_BASE(SPI6), 0x3000, DMA_MUX_RD},
    {DMA_MUX_ID_SPI6_TX, DEVICE_BASE(SPI6), 0x2000, DMA_MUX_WR},
    {DMA_MUX_ID_SPI7_RX, DEVICE_BASE(SPI7), 0x3000, DMA_MUX_RD},
    {DMA_MUX_ID_SPI7_TX, DEVICE_BASE(SPI7), 0x2000, DMA_MUX_WR},
    {DMA_MUX_ID_SPI8_RX, DEVICE_BASE(SPI8), 0x3000, DMA_MUX_RD},
    {DMA_MUX_ID_SPI8_TX, DEVICE_BASE(SPI8), 0x2000, DMA_MUX_WR},

    {DMA_MUX_ID_EPWM1_A, DEVICE_BASE(EPWM1), 0xc0, DMA_MUX_BOTH},
    {DMA_MUX_ID_EPWM1_B, DEVICE_BASE(EPWM1), 0xc4, DMA_MUX_BOTH},
    {DMA_MUX_ID_EPWM1_C, DEVICE_BASE(EPWM1), 0xc8, DMA_MUX_BOTH},
    {DMA_MUX_ID_EPWM1_D, DEVICE_BASE(EPWM1), 0xcc, DMA_MUX_BOTH},
    {DMA_MUX_ID_EPWM1_OVF, DEVICE_BASE(EPWM1), 0x104, DMA_MUX_BOTH},

    {DMA_MUX_ID_EPWM2_A, DEVICE_BASE(EPWM2), 0xc0, DMA_MUX_BOTH},
    {DMA_MUX_ID_EPWM2_B, DEVICE_BASE(EPWM2), 0xc4, DMA_MUX_BOTH},
    {DMA_MUX_ID_EPWM2_C, DEVICE_BASE(EPWM2), 0xc8, DMA_MUX_BOTH},
    {DMA_MUX_ID_EPWM2_D, DEVICE_BASE(EPWM2), 0xcc, DMA_MUX_BOTH},
    {DMA_MUX_ID_EPWM2_OVF, DEVICE_BASE(EPWM2), 0x104, DMA_MUX_BOTH},

    {DMA_MUX_ID_EPWM3_A, DEVICE_BASE(EPWM3), 0xc0, DMA_MUX_BOTH},
    {DMA_MUX_ID_EPWM3_B, DEVICE_BASE(EPWM3), 0xc4, DMA_MUX_BOTH},
    {DMA_MUX_ID_EPWM3_C, DEVICE_BASE(EPWM3), 0xc8, DMA_MUX_BOTH},
    {DMA_MUX_ID_EPWM3_D, DEVICE_BASE(EPWM3), 0xcc, DMA_MUX_BOTH},
    {DMA_MUX_ID_EPWM3_OVF, DEVICE_BASE(EPWM3), 0x104, DMA_MUX_BOTH},

    {DMA_MUX_ID_EPWM4_A, DEVICE_BASE(EPWM4), 0xc0, DMA_MUX_BOTH},
    {DMA_MUX_ID_EPWM4_B, DEVICE_BASE(EPWM4), 0xc4, DMA_MUX_BOTH},
    {DMA_MUX_ID_EPWM4_C, DEVICE_BASE(EPWM4), 0xc8, DMA_MUX_BOTH},
    {DMA_MUX_ID_EPWM4_D, DEVICE_BASE(EPWM4), 0xcc, DMA_MUX_BOTH},
    {DMA_MUX_ID_EPWM4_OVF, DEVICE_BASE(EPWM4), 0x104, DMA_MUX_BOTH},

    {DMA_MUX_ID_ETMR1_A, DEVICE_BASE(ETMR1), 0xc0, DMA_MUX_BOTH},
    {DMA_MUX_ID_ETMR1_B, DEVICE_BASE(ETMR1), 0xc4, DMA_MUX_BOTH},
    {DMA_MUX_ID_ETMR1_C, DEVICE_BASE(ETMR1), 0xc8, DMA_MUX_BOTH},
    {DMA_MUX_ID_ETMR1_D, DEVICE_BASE(ETMR1), 0xcc, DMA_MUX_BOTH},
    {DMA_MUX_ID_ETMR1_OVF, DEVICE_BASE(ETMR1), 0x104, DMA_MUX_BOTH},

    {DMA_MUX_ID_ETMR2_A, DEVICE_BASE(ETMR2), 0xc0, DMA_MUX_BOTH},
    {DMA_MUX_ID_ETMR2_B, DEVICE_BASE(ETMR2), 0xc4, DMA_MUX_BOTH},
    {DMA_MUX_ID_ETMR2_C, DEVICE_BASE(ETMR2), 0xc8, DMA_MUX_BOTH},
    {DMA_MUX_ID_ETMR2_D, DEVICE_BASE(ETMR2), 0xcc, DMA_MUX_BOTH},
    {DMA_MUX_ID_ETMR2_OVF, DEVICE_BASE(ETMR2), 0x104, DMA_MUX_BOTH},

    {DMA_MUX_ID_ETMR3_A, DEVICE_BASE(ETMR3), 0xc0, DMA_MUX_BOTH},
    {DMA_MUX_ID_ETMR3_B, DEVICE_BASE(ETMR3), 0xc4, DMA_MUX_BOTH},
    {DMA_MUX_ID_ETMR3_C, DEVICE_BASE(ETMR3), 0xc8, DMA_MUX_BOTH},
    {DMA_MUX_ID_ETMR3_D, DEVICE_BASE(ETMR3), 0xcc, DMA_MUX_BOTH},
    {DMA_MUX_ID_ETMR3_OVF, DEVICE_BASE(ETMR3), 0x104, DMA_MUX_BOTH},

    {DMA_MUX_ID_ETMR4_A, DEVICE_BASE(ETMR4), 0xc0, DMA_MUX_BOTH},
    {DMA_MUX_ID_ETMR4_B, DEVICE_BASE(ETMR4), 0xc4, DMA_MUX_BOTH},
    {DMA_MUX_ID_ETMR4_C, DEVICE_BASE(ETMR4), 0xc8, DMA_MUX_BOTH},
    {DMA_MUX_ID_ETMR4_D, DEVICE_BASE(ETMR4), 0xcc, DMA_MUX_BOTH},
    {DMA_MUX_ID_ETMR4_OVF, DEVICE_BASE(ETMR4), 0x104, DMA_MUX_BOTH},

    {DMA_MUX_ID_UART1_TX, DEVICE_BASE(UART1), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_UART1_RX, DEVICE_BASE(UART1), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_UART2_TX, DEVICE_BASE(UART2), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_UART2_RX, DEVICE_BASE(UART2), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_UART3_TX, DEVICE_BASE(UART3), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_UART3_RX, DEVICE_BASE(UART3), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_UART4_TX, DEVICE_BASE(UART4), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_UART4_RX, DEVICE_BASE(UART4), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_UART5_TX, DEVICE_BASE(UART5), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_UART5_RX, DEVICE_BASE(UART5), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_UART6_TX, DEVICE_BASE(UART6), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_UART6_RX, DEVICE_BASE(UART6), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_UART7_TX, DEVICE_BASE(UART7), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_UART7_RX, DEVICE_BASE(UART7), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_UART8_TX, DEVICE_BASE(UART8), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_UART8_RX, DEVICE_BASE(UART8), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_UART9_TX, DEVICE_BASE(UART9), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_UART9_RX, DEVICE_BASE(UART9), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_UART10_TX, DEVICE_BASE(UART10), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_UART10_RX, DEVICE_BASE(UART10), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_UART11_TX, DEVICE_BASE(UART11), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_UART11_RX, DEVICE_BASE(UART11), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_UART12_TX, DEVICE_BASE(UART12), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_UART12_RX, DEVICE_BASE(UART12), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_UART13_TX, DEVICE_BASE(UART13), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_UART13_RX, DEVICE_BASE(UART13), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_UART14_TX, DEVICE_BASE(UART14), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_UART14_RX, DEVICE_BASE(UART14), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_UART15_TX, DEVICE_BASE(UART15), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_UART15_RX, DEVICE_BASE(UART15), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_UART16_TX, DEVICE_BASE(UART16), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_UART16_RX, DEVICE_BASE(UART16), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_ADC1_0, DEVICE_BASE(ADC1), 0x3C0, DMA_MUX_BOTH},
    {DMA_MUX_ID_ADC1_1, DEVICE_BASE(ADC1), 0x3C0, DMA_MUX_BOTH},
    {DMA_MUX_ID_ADC2_0, DEVICE_BASE(ADC2), 0x3C0, DMA_MUX_BOTH},
    {DMA_MUX_ID_ADC2_1, DEVICE_BASE(ADC2), 0x3C0, DMA_MUX_BOTH},
    {DMA_MUX_ID_ADC3_0, DEVICE_BASE(ADC3), 0x3C0, DMA_MUX_BOTH},
    {DMA_MUX_ID_ADC3_1, DEVICE_BASE(ADC3), 0x3C0, DMA_MUX_BOTH},

    {DMA_MUX_ID_ISTC, DEVICE_BASE(ISTC), 0xffff, DMA_MUX_BOTH},
};

static sdrv_dma_mux_param_t ap_mux_tbl[] = {
    {DMA_MUX_ID_SACI1_TX, DEVICE_BASE(SACI1), 0x2000, DMA_MUX_WR},
    {DMA_MUX_ID_SACI1_RX, DEVICE_BASE(SACI1), 0x4000, DMA_MUX_RD},
    {DMA_MUX_ID_SACI1_PDM, DEVICE_BASE(SACI1), 0x6000, DMA_MUX_RD},
    {DMA_MUX_ID_SACI2_TX, DEVICE_BASE(SACI2), 0x2000, DMA_MUX_WR},
    {DMA_MUX_ID_SACI2_RX, DEVICE_BASE(SACI2), 0x4000, DMA_MUX_RD},
    {DMA_MUX_ID_SACI2_PDM, DEVICE_BASE(SACI2), 0x6000, DMA_MUX_RD},

};
#else
static sdrv_dma_mux_param_t sf_mux_tbl[] = {
    {DMA_MUX_ID_CANFD16, DEVICE_BASE(CANFD16), 0x80, DMA_MUX_BOTH},
    {DMA_MUX_ID_CANFD21, DEVICE_BASE(CANFD21), 0x80, DMA_MUX_BOTH},
    {DMA_MUX_ID_CANFD3, DEVICE_BASE(CANFD3), 0x80, DMA_MUX_BOTH},
    {DMA_MUX_ID_CANFD4, DEVICE_BASE(CANFD4), 0x80, DMA_MUX_BOTH},
    {DMA_MUX_ID_CANFD5, DEVICE_BASE(CANFD5), 0x80, DMA_MUX_BOTH},
    {DMA_MUX_ID_CANFD6, DEVICE_BASE(CANFD6), 0x80, DMA_MUX_BOTH},
    {DMA_MUX_ID_CANFD7, DEVICE_BASE(CANFD7), 0x80, DMA_MUX_BOTH},
    {DMA_MUX_ID_CANFD23, DEVICE_BASE(CANFD23), 0x80, DMA_MUX_BOTH},

    {DMA_MUX_ID_I2C1, DEVICE_BASE(I2C1), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_I2C2, DEVICE_BASE(I2C2), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_I2C3, DEVICE_BASE(I2C3), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_I2C4, DEVICE_BASE(I2C4), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_I2C5, DEVICE_BASE(I2C5), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_I2C6, DEVICE_BASE(I2C6), 0x200, DMA_MUX_WR},

    {DMA_MUX_ID_I2C1, DEVICE_BASE(I2C1), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_I2C2, DEVICE_BASE(I2C2), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_I2C3, DEVICE_BASE(I2C3), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_I2C4, DEVICE_BASE(I2C4), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_I2C5, DEVICE_BASE(I2C5), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_I2C6, DEVICE_BASE(I2C6), 0x300, DMA_MUX_RD},

    {DMA_MUX_ID_XSPI1_A_RD, DEVICE_BASE(XSPI1PORTA), 0x380, DMA_MUX_RD},
    {DMA_MUX_ID_XSPI1_A_WR, DEVICE_BASE(XSPI1PORTA), 0x280, DMA_MUX_WR},
    {DMA_MUX_ID_XSPI1_B_RD, DEVICE_BASE(XSPI1PORTB), 0x380, DMA_MUX_RD},
    {DMA_MUX_ID_XSPI1_B_WR, DEVICE_BASE(XSPI1PORTB), 0x280, DMA_MUX_WR},

    {DMA_MUX_ID_SPI1_RX, DEVICE_BASE(SPI1), 0x3000, DMA_MUX_RD},
    {DMA_MUX_ID_SPI1_TX, DEVICE_BASE(SPI1), 0x2000, DMA_MUX_WR},
    {DMA_MUX_ID_SPI2_RX, DEVICE_BASE(SPI2), 0x3000, DMA_MUX_RD},
    {DMA_MUX_ID_SPI2_TX, DEVICE_BASE(SPI2), 0x2000, DMA_MUX_WR},
    {DMA_MUX_ID_SPI3_RX, DEVICE_BASE(SPI3), 0x3000, DMA_MUX_RD},
    {DMA_MUX_ID_SPI3_TX, DEVICE_BASE(SPI3), 0x2000, DMA_MUX_WR},
    {DMA_MUX_ID_SPI4_RX, DEVICE_BASE(SPI4), 0x3000, DMA_MUX_RD},
    {DMA_MUX_ID_SPI4_TX, DEVICE_BASE(SPI4), 0x2000, DMA_MUX_WR},
    {DMA_MUX_ID_SPI5_RX, DEVICE_BASE(SPI5), 0x3000, DMA_MUX_RD},
    {DMA_MUX_ID_SPI5_TX, DEVICE_BASE(SPI5), 0x2000, DMA_MUX_WR},
    {DMA_MUX_ID_SPI6_RX, DEVICE_BASE(SPI6), 0x3000, DMA_MUX_RD},
    {DMA_MUX_ID_SPI6_TX, DEVICE_BASE(SPI6), 0x2000, DMA_MUX_WR},

    {DMA_MUX_ID_EPWM1_A, DEVICE_BASE(EPWM1), 0xc0, DMA_MUX_BOTH},
    {DMA_MUX_ID_EPWM1_B, DEVICE_BASE(EPWM1), 0xc4, DMA_MUX_BOTH},
    {DMA_MUX_ID_EPWM1_C, DEVICE_BASE(EPWM1), 0xc8, DMA_MUX_BOTH},
    {DMA_MUX_ID_EPWM1_D, DEVICE_BASE(EPWM1), 0xcc, DMA_MUX_BOTH},
    {DMA_MUX_ID_EPWM1_OVF, DEVICE_BASE(EPWM1), 0x104, DMA_MUX_BOTH},

    {DMA_MUX_ID_EPWM2_A, DEVICE_BASE(EPWM2), 0xc0, DMA_MUX_BOTH},
    {DMA_MUX_ID_EPWM2_B, DEVICE_BASE(EPWM2), 0xc4, DMA_MUX_BOTH},
    {DMA_MUX_ID_EPWM2_C, DEVICE_BASE(EPWM2), 0xc8, DMA_MUX_BOTH},
    {DMA_MUX_ID_EPWM2_D, DEVICE_BASE(EPWM2), 0xcc, DMA_MUX_BOTH},
    {DMA_MUX_ID_EPWM2_OVF, DEVICE_BASE(EPWM2), 0x104, DMA_MUX_BOTH},

    {DMA_MUX_ID_ETMR1_A, DEVICE_BASE(ETMR1), 0xc0, DMA_MUX_BOTH},
    {DMA_MUX_ID_ETMR1_B, DEVICE_BASE(ETMR1), 0xc4, DMA_MUX_BOTH},
    {DMA_MUX_ID_ETMR1_C, DEVICE_BASE(ETMR1), 0xc8, DMA_MUX_BOTH},
    {DMA_MUX_ID_ETMR1_D, DEVICE_BASE(ETMR1), 0xcc, DMA_MUX_BOTH},
    {DMA_MUX_ID_ETMR1_OVF, DEVICE_BASE(ETMR1), 0x104, DMA_MUX_BOTH},

    {DMA_MUX_ID_ETMR2_A, DEVICE_BASE(ETMR2), 0xc0, DMA_MUX_BOTH},
    {DMA_MUX_ID_ETMR2_B, DEVICE_BASE(ETMR2), 0xc4, DMA_MUX_BOTH},
    {DMA_MUX_ID_ETMR2_C, DEVICE_BASE(ETMR2), 0xc8, DMA_MUX_BOTH},
    {DMA_MUX_ID_ETMR2_D, DEVICE_BASE(ETMR2), 0xcc, DMA_MUX_BOTH},
    {DMA_MUX_ID_ETMR2_OVF, DEVICE_BASE(ETMR2), 0x104, DMA_MUX_BOTH},

    {DMA_MUX_ID_UART1_TX, DEVICE_BASE(UART1), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_UART1_RX, DEVICE_BASE(UART1), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_UART2_TX, DEVICE_BASE(UART2), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_UART2_RX, DEVICE_BASE(UART2), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_UART3_TX, DEVICE_BASE(UART3), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_UART3_RX, DEVICE_BASE(UART3), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_UART4_TX, DEVICE_BASE(UART4), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_UART4_RX, DEVICE_BASE(UART4), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_UART5_TX, DEVICE_BASE(UART5), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_UART5_RX, DEVICE_BASE(UART5), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_UART6_TX, DEVICE_BASE(UART6), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_UART6_RX, DEVICE_BASE(UART6), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_UART7_TX, DEVICE_BASE(UART7), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_UART7_RX, DEVICE_BASE(UART7), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_UART8_TX, DEVICE_BASE(UART8), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_UART8_RX, DEVICE_BASE(UART8), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_UART9_TX, DEVICE_BASE(UART9), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_UART9_RX, DEVICE_BASE(UART9), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_UART10_TX, DEVICE_BASE(UART10), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_UART10_RX, DEVICE_BASE(UART10), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_UART11_TX, DEVICE_BASE(UART11), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_UART11_RX, DEVICE_BASE(UART11), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_UART12_TX, DEVICE_BASE(UART12), 0x200, DMA_MUX_WR},
    {DMA_MUX_ID_UART12_RX, DEVICE_BASE(UART12), 0x300, DMA_MUX_RD},
    {DMA_MUX_ID_ADC1_0, DEVICE_BASE(ADC1), 0x3C0, DMA_MUX_BOTH},
    {DMA_MUX_ID_ADC1_1, DEVICE_BASE(ADC1), 0x3C0, DMA_MUX_BOTH},
    {DMA_MUX_ID_ADC2_0, DEVICE_BASE(ADC2), 0x3C0, DMA_MUX_BOTH},
    {DMA_MUX_ID_ADC2_1, DEVICE_BASE(ADC2), 0x3C0, DMA_MUX_BOTH},
    {DMA_MUX_ID_ADC3_0, DEVICE_BASE(ADC3), 0x3C0, DMA_MUX_BOTH},
    {DMA_MUX_ID_ADC3_1, DEVICE_BASE(ADC3), 0x3C0, DMA_MUX_BOTH},

    {DMA_MUX_ID_ISTC, DEVICE_BASE(ISTC), 0xffff, DMA_MUX_BOTH},
};

#endif

__attribute__((__aligned__(CONFIG_ARCH_CACHE_LINE))) dma_dev_t dma_sf0[CPU_ID_MAX] = {
    /* SF core */
    {
        .dma_base = APB_DMA_SF0_BASE,
        .channel_nr = DMA_CHANNEL_SF0_ON_SF_NUMBER,
    },
    /* SX0 core */
    {
        .dma_base = APB_DMA_SF0_BASE,
        .channel_nr = DMA_CHANNEL_SF0_ON_SX0_NUMBER,
    },
    /* SX1 core */
    {
        .dma_base = APB_DMA_SF0_BASE,
        .channel_nr = DMA_CHANNEL_SF0_ON_SX1_NUMBER,
    },
    /* SP0 core */
    {
        .dma_base = APB_DMA_SF0_BASE,
        .channel_nr = DMA_CHANNEL_SF0_ON_SP0_NUMBER,
    },
    /* SP1 core */
    {
        .dma_base = APB_DMA_SF0_BASE,
        .channel_nr = DMA_CHANNEL_SF0_ON_SP1_NUMBER,
    }
};

#if (STD_OFF == DMA_LOCK_STEP_MODE)
__attribute__((__aligned__(CONFIG_ARCH_CACHE_LINE))) dma_dev_t dma_sf1[CPU_ID_MAX] = {
    /* SF core */
    {
        .dma_base = APB_DMA_SF1_BASE,
        .channel_nr = DMA_CHANNEL_SF1_ON_SF_NUMBER,
    },
    /* SX0 core */
    {
        .dma_base = APB_DMA_SF1_BASE,
        .channel_nr = DMA_CHANNEL_SF1_ON_SX0_NUMBER,
    },
    /* SX1 core */
    {
        .dma_base = APB_DMA_SF1_BASE,
        .channel_nr = DMA_CHANNEL_SF1_ON_SX1_NUMBER,
    },
    /* SP0 core */
    {
        .dma_base = APB_DMA_SF1_BASE,
        .channel_nr = DMA_CHANNEL_SF1_ON_SP0_NUMBER,
    },
    /* SP1 core */
    {
        .dma_base = APB_DMA_SF1_BASE,
        .channel_nr = DMA_CHANNEL_SF1_ON_SP1_NUMBER,
    }
};
#endif /* #if (STD_OFF == DMA_LOCK_STEP_MODE) */

#ifndef SEMIDRIVE_E3_LITE_SERIES
__attribute__((__aligned__(CONFIG_ARCH_CACHE_LINE))) dma_dev_t dma_ap0[CPU_ID_MAX] = {
    /* SF core */
    {
        .dma_base = APB_DMA_AP_BASE,
        .channel_nr = DMA_CHANNEL_AP0_ON_SF_NUMBER,
    },
    /* SX0 core */
    {
        .dma_base = APB_DMA_AP_BASE,
        .channel_nr = DMA_CHANNEL_AP0_ON_SX0_NUMBER,
    },
    /* SX1 core */
    {
        .dma_base = APB_DMA_AP_BASE,
        .channel_nr = DMA_CHANNEL_AP0_ON_SX1_NUMBER,
    },
    /* SP0 core */
    {
        .dma_base = APB_DMA_AP_BASE,
        .channel_nr = DMA_CHANNEL_AP0_ON_SP0_NUMBER,
    },
    /* SP1 core */
    {
        .dma_base = APB_DMA_AP_BASE,
        .channel_nr = DMA_CHANNEL_AP0_ON_SP1_NUMBER,
    }
};
#endif /* #ifndef SEMIDRIVE_E3_LITE_SERIES */

__attribute__((__aligned__(CONFIG_ARCH_CACHE_LINE))) sdrv_dma_cfg_t dma_sf0_cfg[CPU_ID_MAX] = {
    /* SF core */
    {
        .irq_id_table = Dma_SF0AllocateOnSF,
        .irq_num = DMA_CHANNEL_SF0_ON_SF_NUMBER,
        .mux_table = sf_mux_tbl,
        .mux_table_len = ARRAY_SZ(sf_mux_tbl)
    },
    /* SX0 core */
    {
        .irq_id_table = Dma_SF0AllocateOnSX0,
        .irq_num = DMA_CHANNEL_SF0_ON_SX0_NUMBER,
        .mux_table = sf_mux_tbl,
        .mux_table_len = ARRAY_SZ(sf_mux_tbl)
    },
    /* SX1 core */
    {
        .irq_id_table = Dma_SF0AllocateOnSX1,
        .irq_num = DMA_CHANNEL_SF0_ON_SX1_NUMBER,
        .mux_table = sf_mux_tbl,
        .mux_table_len = ARRAY_SZ(sf_mux_tbl)
    },
    /* SP0 core */
    {
        .irq_id_table = Dma_SF0AllocateOnSP0,
        .irq_num = DMA_CHANNEL_SF0_ON_SP0_NUMBER,
        .mux_table = sf_mux_tbl,
        .mux_table_len = ARRAY_SZ(sf_mux_tbl)
    },
    /* SP1 core */
    {
        .irq_id_table = Dma_SF0AllocateOnSP1,
        .irq_num = DMA_CHANNEL_SF0_ON_SP1_NUMBER,
        .mux_table = sf_mux_tbl,
        .mux_table_len = ARRAY_SZ(sf_mux_tbl)
    }
};
#if (STD_OFF == DMA_LOCK_STEP_MODE)
__attribute__((__aligned__(CONFIG_ARCH_CACHE_LINE))) sdrv_dma_cfg_t dma_sf1_cfg[CPU_ID_MAX] = {
    /* SF core */
    {
        .irq_id_table = Dma_SF1AllocateOnSF,
        .irq_num = DMA_CHANNEL_SF1_ON_SF_NUMBER,
        .mux_table = sf_mux_tbl,
        .mux_table_len = ARRAY_SZ(sf_mux_tbl)
    },
    /* SX0 core */
    {
        .irq_id_table = Dma_SF1AllocateOnSX0,
        .irq_num = DMA_CHANNEL_SF1_ON_SX0_NUMBER,
        .mux_table = sf_mux_tbl,
        .mux_table_len = ARRAY_SZ(sf_mux_tbl)
    },
    /* SX1 core */
    {
        .irq_id_table = Dma_SF1AllocateOnSX1,
        .irq_num = DMA_CHANNEL_SF1_ON_SX1_NUMBER,
        .mux_table = sf_mux_tbl,
        .mux_table_len = ARRAY_SZ(sf_mux_tbl)
    },
    /* SP0 core */
    {
        .irq_id_table = Dma_SF1AllocateOnSP0,
        .irq_num = DMA_CHANNEL_SF1_ON_SP0_NUMBER,
        .mux_table = sf_mux_tbl,
        .mux_table_len = ARRAY_SZ(sf_mux_tbl)
    },
    /* SP1 core */
    {
        .irq_id_table = Dma_SF1AllocateOnSP1,
        .irq_num = DMA_CHANNEL_SF1_ON_SP1_NUMBER,
        .mux_table = sf_mux_tbl,
        .mux_table_len = ARRAY_SZ(sf_mux_tbl)
    }
};
#endif /* #if (STD_OFF == DMA_LOCK_STEP_MODE) */

#ifndef SEMIDRIVE_E3_LITE_SERIES
__attribute__((__aligned__(CONFIG_ARCH_CACHE_LINE))) sdrv_dma_cfg_t dma_ap0_cfg[CPU_ID_MAX] = {
    /* SF core */
    {
        .irq_id_table = Dma_APAllocateOnSF,
        .irq_num = DMA_CHANNEL_AP0_ON_SF_NUMBER,
        .mux_table = ap_mux_tbl,
        .mux_table_len = ARRAY_SZ(ap_mux_tbl)
    },
    /* SX0 core */
    {
        .irq_id_table = Dma_APAllocateOnSX0,
        .irq_num = DMA_CHANNEL_AP0_ON_SX0_NUMBER,
        .mux_table = ap_mux_tbl,
        .mux_table_len = ARRAY_SZ(ap_mux_tbl)
    },
    /* SX1 core */
    {
        .irq_id_table = Dma_APAllocateOnSX1,
        .irq_num = DMA_CHANNEL_AP0_ON_SX1_NUMBER,
        .mux_table = ap_mux_tbl,
        .mux_table_len = ARRAY_SZ(ap_mux_tbl)
    },
    /* SP0 core */
    {
        .irq_id_table = Dma_APAllocateOnSP0,
        .irq_num = DMA_CHANNEL_AP0_ON_SP0_NUMBER,
        .mux_table = ap_mux_tbl,
        .mux_table_len = ARRAY_SZ(ap_mux_tbl)
    },
    /* SP1 core */
    {
        .irq_id_table = Dma_APAllocateOnSP1,
        .irq_num = DMA_CHANNEL_AP0_ON_SP1_NUMBER,
        .mux_table = ap_mux_tbl,
        .mux_table_len = ARRAY_SZ(ap_mux_tbl)
    }
};
#endif

/* dma initialization */
void board_dma_init(void)
{
#if (STD_OFF == DMA_LOCK_STEP_MODE)
    /*  sf dma1 must enable scr */
    scr_signal_t signal = SCR_SF_DMA_SF_LOCK_STEP_EN_P;
    Mcu_ScrSetBit(&signal, 1);
#else
    scr_signal_t signal = SCR_SF_DMA_SF_LOCK_STEP_EN_P;
    Mcu_ScrSetBit(&signal, 0);
#endif /* #if (STD_OFF == DMA_LOCK_STEP_MODE) */

    sdrv_dma_init(&dma_sf0[Mcu_GetCoreID()], &dma_sf0_cfg[Mcu_GetCoreID()]);

#if (STD_OFF == DMA_LOCK_STEP_MODE)
    sdrv_dma_init(&dma_sf1[Mcu_GetCoreID()], &dma_sf1_cfg[Mcu_GetCoreID()]);
#endif /* #if (STD_OFF == DMA_LOCK_STEP_MODE) */

#ifndef SEMIDRIVE_E3_LITE_SERIES
#if (STD_OFF == MCU_APDOMAIN_POWERDOWN)
    sdrv_dma_init(&dma_ap0[Mcu_GetCoreID()], &dma_ap0_cfg[Mcu_GetCoreID()]);
#endif
#endif
}

#ifdef __cplusplus
}
#endif
