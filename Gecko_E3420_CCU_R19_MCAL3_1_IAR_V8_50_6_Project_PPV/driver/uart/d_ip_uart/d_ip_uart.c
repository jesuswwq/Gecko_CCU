/********************************************************
 *      Copyright(c) 2019   Semidrive  Semiconductor    *
 *      All rights reserved.                            *
 ********************************************************/

#include "uart.h"
#include "uart_reg.h"
#include "RegHelper.h"


/* uart rx may wait the data arrived, so refresh the watchdog every 50ms if needed */
#define CFG_UART_RX_WDOG_CYCLE    50000

static sint32 d_ip_uart_init(unsigned long b, uart_cfg_t *cfg)
{
    if (NULL_PTR == cfg) {
        return -1;
    }

    /* Set MCR0.MODEN to 0x0 (disable module) */
    uint32 mcr0 = readl(b + MCR0_OFF);
    mcr0 &= ~BM_MCR0_MODEN;
    writel(mcr0, b + MCR0_OFF);
    /* Reset module by set MCR0.MODRST to 0x1 */
    mcr0 |= BM_MCR0_MODRST;
    writel(mcr0, b + MCR0_OFF);

    /* Wait software reset auto clear (MCR0.MODRST) */
    while ((mcr0 = readl(b + MCR0_OFF)) & BM_MCR0_MODRST);

    mcr0 &= ~FM_MCR0_OPMOD;
    mcr0 |= FV_MCR0_OPMOD(0);  /* Asynchronous Serial mode */
    writel(mcr0, b + MCR0_OFF);
    /* full-duplex, no flow ctl, 8-n-1, baudrate detection enabled with 8 tries (0xaa),
     * LSB, 16x sampling */
    uint32 rate = 115200u;;

    if (0u != cfg->baud_rate) {
        rate = cfg->baud_rate;
    }

    /* 24 bits divider shall be quite enough */
    /* for 16x sampling, the lower 4 bits are frac bits, thus no need to div 16 here */
    uint32 div_i = UART_ROOT_CLK_FREQ / rate;
#if defined(BOARD_E3_z1)
    div_i /= 16;    /* z1's virtual uart issue */
#endif
    uint32 pcr1 = FV_PCR1_BAUDRATECNT(div_i);
    writel(pcr1, b + PCR1_OFF);
    uint32 pcr0 = 0;

    if (cfg->auto_br) {
        pcr0 = FV_PCR0_ABRCTL1(0)   /* one match byte */
               | FV_PCR0_ABRCTL0(0)
               | BM_PCR0_ABREN;
        writel(pcr0, b + PCR0_OFF);
    }

#ifdef EN_UNIFIED_IMAGE
    uint32 inten0 = readl(b + FCR1_OFF);
    inten0 &= ~FM_FCR1_RXWMLVL;
    inten0 |=  FV_FCR1_RXWMLVL(0)|BM_FCR1_CLRRXF;
    writel(inten0, b + FCR1_OFF);

    inten0 = readl(b + INTEN0_OFF);
    inten0 |=  BM_INTEN0_RXFWFE;
    writel(inten0, b + INTEN0_OFF);

#endif


    uint32 per8 = readl(b + PCR8_OFF);
    writel(per8 | BM_PCR8_RXSYNCEN,b+PCR8_OFF);

    pcr0 |= BM_PCR0_RXEN;
    writel(pcr0, b + PCR0_OFF);
    mcr0 |= BM_MCR0_MODEN;
    writel(mcr0, b + MCR0_OFF);

    return 0;
}

static void d_ip_uart_enable_auto_br(unsigned long b)
{
    uint32 v = readl(b + PCR0_OFF);
    v |= BM_PCR0_ABREN;
    writel(v, b + PCR0_OFF);
}

static void d_ip_uart_disable_auto_br(unsigned long b)
{
    uint32 v = readl(b + PCR0_OFF);
    v &= ~BM_PCR0_ABREN;
    writel(v, b + PCR0_OFF);

}

static void d_ip_uart_clr_rx_fifo(unsigned long b)
{
    uint32 v = readl(b + FCR1_OFF);
    v |= BM_FCR1_CLRRXF;
    /* This bit will be auto cleared one APB bus clock cycle later */
    writel(v, b + FCR1_OFF);
}

static sint32 d_ip_uart_chk_auto_br(unsigned long b)
{
    sint32 res = 0;
    uint32 intr0 = readl(b + INTR0_OFF);

    if (intr0 & BM_INTR0_ABRFAIL) {
        res = -1; /*failed*/
    } else if (intr0 & BM_INTR0_ABRPASS) { /* succeed */
        uint32 v = readl(b + PSR1_OFF);
        v = FV_PSR1_AUTOBAUDRATE(v);
        res = UART_ROOT_CLK_FREQ / v;
    }

    return res;
}

static sint32 d_ip_uart_tx(unsigned long b, uint8 *data, uint32 sz)
{
    uint32 v = readl(b + PCR0_OFF);
    v |= BM_PCR0_TXEN;
    writel(v, b + PCR0_OFF);

    while (sz) {
        if (0 == (BM_FSR0_FULL & readl(b + FSR0_OFF))) {
            writel(*data, b + TXDR_OFF);
            data++;
            sz--;
        }
    }

    /* shall not disable TX here otherwise data in fifo will never be sent out */

    return 0;
}

static sint32 d_ip_uart_rx(unsigned long b, uint8 *data, uint32 sz)
{
    while (sz) {
        if (0u != FV_FSR1_FILLLVL(readl(b + FSR1_OFF))) {
            *data++ = readl(b + RXDR_OFF);
            sz--;
        }
    }

    return 0;
}
#ifdef EN_UNIFIED_IMAGE
uint32 uart_rx_irq(unsigned long b, uint8 *data, uint32 sz)
{
    uint32 len=0;
    while(0 != FV_FSR1_FILLLVL(readl(b + FSR1_OFF))) {
        *data++ = readl(b + RXDR_OFF);
        len++;
        if(sz <= len)
            break;
    }
    uint32 reg_v = readl(b + INTR0_OFF);
    writel(reg_v, b + INTR0_OFF);
    return len;
}
#endif
uart_ops_t uart_ctl = {
    .init = d_ip_uart_init,
    .uart_tx = d_ip_uart_tx,
    .uart_rx = d_ip_uart_rx,
    .uart_enable_auto_br = d_ip_uart_enable_auto_br,
    .uart_disable_auto_br = d_ip_uart_disable_auto_br,
    .uart_chk_auto_br = d_ip_uart_chk_auto_br,
    .uart_clr_rx_fifo = d_ip_uart_clr_rx_fifo,
};
