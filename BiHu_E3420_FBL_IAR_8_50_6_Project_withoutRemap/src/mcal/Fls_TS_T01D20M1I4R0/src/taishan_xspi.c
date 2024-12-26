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

/*
* @file  taishan_xspi.c
* @brief Semidrive. AUTOSAR 4.3.1 MCAL Fls plugins.
*/

#ifdef __cplusplus
extern "C" {
#endif

#include "mini_libc.h"
#include "Mcu_Soc.h"
#include "taishan_xspi.h"
#include "debug.h"
#include "cdefs.h"
#include "Mcu.h"
#include "Mcu_Mpu.h"

#define XSPI_POLLING_INTERVAL_FACTOR 80
#define SPI_NOR_XFER_COMPLETE (0x1u)

#define FLS_START_SEC_VAR_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

volatile int g_xspi_debug = 1;

static uint32 s_lockstep_err = 0;

#define FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"

static inline uint8 my_log2_uint(uint64 val)
{
    uint8 ret = 0;

    if (val & (val - 1)) {
        DBG("val is not 2^n\n");
    }

    while (val > 1ull) {
        val >>= 1ull;
        ret++;
    }

    return ret;
}

static int xspi_wait_for_bit_times(addr_t reg, const uint32 mask, bool clear,
                                   uint32 times)
{
    uint32 val;
    uint32 count = 0;

    while (count < times) {
        val = readl(reg);

        if (clear) {
            val = ~val;
        }

        val &= mask;

        if (val == mask) {
            return 0;
        }

        count++;
    }

    return -1;
}

static inline uint32 xspi_lld_get_rd_buf_level(struct xspi_pdata *xspi)
{
    uint32 reg = xspi_readl(xspi->apb_base + XSPI_INDIRECT_RX_BUF);
    reg >>= XSPI_INDIRECT_RX_BUF_ENTRY_LSB;
    return reg & XSPI_INDIRECT_RX_BUF_ENTRY_MASK;
}

static inline uint32 xspi_lld_get_wr_buf_level(struct xspi_pdata *xspi)
{
    uint32 reg = xspi_readl(xspi->apb_base + XSPI_INDIRECT_TX_BUF);
    reg >>= XSPI_INDIRECT_TX_BUF_ENTRY_LSB;
    return reg & XSPI_INDIRECT_TX_BUF_ENTRY_MASK;
}

void xspi_lld_reset_flash(struct xspi_pdata *xspi)
{
    /* rst enable */
    REG_RMW32(xspi->apb_base + XSPI_IO_CTRL, 0, 1, 1);

    /* rst start */
    REG_RMW32(xspi->apb_base + XSPI_IO_CTRL, 1, 1, 0);
    udelay(1000u);

    /* rst end */
    REG_RMW32(xspi->apb_base + XSPI_IO_CTRL, 1, 1, 1);
    udelay(1000u);

    /* rst disable */
    REG_RMW32(xspi->apb_base + XSPI_IO_CTRL, 0, 1, 0);
    xspi_readl(xspi->apb_base + XSPI_IO_CTRL);
}

static void xspi_lld_delay_set(struct spi_nor *nor)
{
    uint32 reg, tslch, tshsl, tchsh;
    struct xspi_pdata *xspi = nor->host->priv_data;

    tslch = XSPI_NS_2_TICKS(xspi->ref_clk_hz, 10);
    tshsl = XSPI_NS_2_TICKS(xspi->ref_clk_hz, 30);
    tchsh = XSPI_NS_2_TICKS(xspi->ref_clk_hz, 10);
    tchsh = (tchsh >= 3) ? tchsh : 3;

    reg = xspi_readl(xspi->apb_base + XSPI_CS_CTRL);
    reg &= ~(XSPI_CS_CTRL_TIME_DELAY_MASK << XSPI_CS_CTRL_TSLCH_LSB);
    reg |= (tslch & XSPI_CS_CTRL_TIME_DELAY_MASK) << XSPI_CS_CTRL_TSLCH_LSB;

    reg &= ~(XSPI_CS_CTRL_TIME_SHSL_DELAY_MASK << XSPI_CS_CTRL_TSHSL_LSB);
    reg |= (tshsl & XSPI_CS_CTRL_TIME_SHSL_DELAY_MASK) << XSPI_CS_CTRL_TSHSL_LSB;

    reg &= ~(XSPI_CS_CTRL_TIME_DELAY_MASK << XSPI_CS_CTRL_TCHSH_LSB);
    reg |= (tchsh & XSPI_CS_CTRL_TIME_DELAY_MASK) << XSPI_CS_CTRL_TCHSH_LSB;
    xspi_writel(reg, xspi->apb_base + XSPI_CS_CTRL);
}

static inline uint32 xspi_lld_idle_status(struct xspi_pdata *xspi)
{
    uint32 reg;
    reg = readl(xspi->apb_base + XSPI_MODE_CTRL);
    return reg & XSPI_MODE_CTRL_IDLE;
}

/* In xip mode, this func should to put into iram. */
static int xspi_lld_wait_idle(struct xspi_pdata *xspi)
{
    uint32 idle_latency_cycles = 4;
    uint32 idle_count = 0;
    uint32 polling_cycles = 0;

    while (1) {
        if (xspi_lld_idle_status(xspi) != 0u) {
            idle_count++;
        } else {
            idle_count = 0;
        }

        /* When IDLE bit asserted, need wait 4 cycyles of ref_clk. */
        if (idle_count >= idle_latency_cycles) {
            return 0;
        } else if (polling_cycles > XSPI_IDLE_TIMEOUT_CYCLES) {
            return -1;
        }

        polling_cycles++;
    }
}

void xspi_lld_xip_enable(struct xspi_pdata *xspi)
{
    uint32 reg;
    uint32 read_dummy;

    /* Enable xip mode */
    reg = xspi_readl(xspi->apb_base + XSPI_MODE_CTRL);
    reg |= XSPI_MODE_CTRL_XIP;
    xspi_writel(reg, xspi->apb_base + XSPI_MODE_CTRL);

    xspi_writel(0u, xspi->apb_base + XSPI_DIRECT_M_CODE);

    reg = xspi_readl(xspi->apb_base + XSPI_DIRECT_RD_PH_CTRL);
    /* Set read mode phase 1 byte */
    reg &= ~(XSPI_DIRECT_MODE_SIZE_MASK << XSPI_DIRECT_MODE_SIZE_LSB);
    /* Xip mode bit sent by 8 lines */
    reg |= 0x3u << XSPI_DIRECT_MODE_LINE_LSB;
    /* Enable read mode phase */
    reg |= XSPI_DIRECT_MODE_EN;
    xspi_writel(reg, xspi->apb_base + XSPI_DIRECT_RD_PH_CTRL);

    /* Read dummy cycle - 1 */
    reg = xspi_readl(xspi->apb_base + XSPI_DIRECT_D_CYC);
    read_dummy = reg & XSPI_DIRECT_D_CYC_RD_MASK;
    reg &= ~(XSPI_DIRECT_D_CYC_RD_MASK);
    reg |= read_dummy - 1;
    xspi_writel(reg, xspi->apb_base + XSPI_DIRECT_D_CYC);
}

void xspi_lld_xip_enter(struct xspi_pdata *xspi)
{
    uint32 reg;

    /* Disable direct read cmd phase */
    reg = xspi_readl(xspi->apb_base + XSPI_DIRECT_RD_PH_CTRL);
    reg &= ~XSPI_DIRECT_CMD_EN;
    xspi_writel(reg, xspi->apb_base + XSPI_DIRECT_RD_PH_CTRL);
}

#if CONFIG_DMA
void xspi_lld_dma_enable(struct xspi_pdata *xspi)
{
    uint32 reg;

    reg = xspi_readl(xspi->apb_base + XSPI_INDIRECT_WR_DMA);
    reg |= XSPI_INDIRECT_DMA_SINGLE_EN | XSPI_INDIRECT_DMA_REQ_EN;
    xspi_writel(reg, xspi->apb_base + XSPI_INDIRECT_WR_DMA);

    reg = xspi_readl(xspi->apb_base + XSPI_INDIRECT_RD_DMA);
    reg |= XSPI_INDIRECT_DMA_SINGLE_EN | XSPI_INDIRECT_DMA_REQ_EN;
    xspi_writel(reg, xspi->apb_base + XSPI_INDIRECT_RD_DMA);
}

void xspi_lld_dma_disable(struct xspi_pdata *xspi)
{
    xspi_writel(0u, xspi->apb_base + XSPI_INDIRECT_WR_DMA);
    xspi_writel(0u, xspi->apb_base + XSPI_INDIRECT_RD_DMA);
}
#endif

void xspi_lld_rx_config(struct xspi_pdata *xspi, uint32 mode)
{
    uint32 reg;

    reg = xspi_readl(xspi->apb_base + XSPI_SCLK_CTRL);
    reg &= ~(XSPI_SCLK_CTRL_RX_SEL_MASK << XSPI_SCLK_CTRL_RX_SEL_LSB);
    reg |= mode << XSPI_SCLK_CTRL_RX_SEL_LSB;
    xspi_writel(reg, xspi->apb_base + XSPI_SCLK_CTRL);
}

#ifdef XSPI_DLL_USE_OVERRIDE_MODE
/* In xip mode, this func should to put into iram. */
void xspi_lld_dll_enable(struct xspi_pdata *xspi, int dll_num, int value,
                         bool enable)
{
    uint32 reg = 0u;
    uint32 addr;

    addr = dll_num ? XSPI_DLL1_CTRL : XSPI_DLL_CTRL;

    if (enable) {
        xspi_writel(reg, xspi->apb_base + addr);
        reg |= value << 9;
        xspi_writel(reg, xspi->apb_base + addr);
        reg |= BIT(8);
        xspi_writel(reg, xspi->apb_base + addr);
    }

    REG_RMW32(xspi->apb_base + XSPI_MODE_CTRL, 31, 1, 1);
    udelay(1);
    REG_RMW32(xspi->apb_base + XSPI_MODE_CTRL, 31, 1, 0);
    xspi_lld_wait_idle(xspi);

    /* set dll_en */
    REG_RMW32(xspi->apb_base + XSPI_SCLK_CTRL, 1, 1, enable ? 1 : 0);
    xspi_readl(xspi->apb_base + XSPI_SCLK_CTRL);
}
#else
void xspi_lld_dll_enable(struct xspi_pdata *xspi, int dll_num, int value,
                          bool enable)
{
    uint32 reg = 0u;
    int ret = 0;
    uint32 addr;

    addr = dll_num ? XSPI_DLL1_CTRL : XSPI_DLL_CTRL;

    if (enable) {
        xspi_writel(reg, xspi->apb_base + addr);
        reg |= value << 1;
        xspi_writel(reg, xspi->apb_base + addr);
        reg |= BIT(0);
        xspi_writel(reg, xspi->apb_base + addr);

        ret = xspi_wait_for_bit_times(xspi->apb_base + addr + 4, BIT(16), false,
                                           100000u);

        if (ret) {
            ERROR("dll enable err\r\n");
        }

#ifdef SEMIDRIVE_E3_LITE_SERIES
        uint8 chipver = Mcu_GetChipVersion();
        if (chipver == 0)
#endif
        {
            /* workround: XSPI DLL slave chain update should be gated during flash read operation.
                otherwise, there will be DQS (read strobe) glitch and read data will be wrong. */
            RMWREG32(xspi->apb_base + addr, 31, 1, 1);
        }
    }

    RMWREG32(xspi->apb_base + XSPI_MODE_CTRL, 31, 1, 1);
    udelay(1);
    RMWREG32(xspi->apb_base + XSPI_MODE_CTRL, 31, 1, 0);
    xspi_lld_wait_idle(xspi);

    /* set dll_en */
    RMWREG32(xspi->apb_base + XSPI_SCLK_CTRL, 1, 1, enable ? 1 : 0);
    reg = xspi_readl(xspi->apb_base + addr);
}
#endif

static void xspi_prefetch_config(struct xspi_pdata *xspi, uint32 channel,
                                 uint16 gid_mask, uint16 gid_match,
                                 uint8 block_num, uint8 group_num)
{
    uint32 reg;

    /* Entry size is 8 blocks */
    reg = block_num;
    reg |= group_num << 8;
    reg |= 1u << 19;
    xspi_writel(reg, xspi->apb_base + XSPI_RBUF_CTRL + 0x10 * channel);
    xspi_writel(gid_mask, xspi->apb_base + XSPI_GID_MASK + 0x10 * channel);
    xspi_writel(gid_match, xspi->apb_base + XSPI_GID_MATCH + 0x10 * channel);
}

void xspi_prefetch_flush(struct xspi_pdata *xspi, uint32 channel)
{
    REG_RMW32(xspi->apb_base + XSPI_RBUF_CTRL + 0x10 * channel, 17, 1, 1);
    REG_RMW32(xspi->apb_base + XSPI_RBUF_CTRL + 0x10 * channel, 17, 1, 0);
}

static void xspi_prefetch_clear(struct xspi_pdata *xspi, uint32 channel)
{
    xspi_writel(0u, xspi->apb_base + XSPI_RBUF_CTRL + 0x10 * channel);
    xspi_writel(0u, xspi->apb_base + XSPI_GID_MASK + 0x10 * channel);
    xspi_writel(0u, xspi->apb_base + XSPI_GID_MATCH + 0x10 * channel);
}

/* In xip mode, this func should to put into iram. */
static void xspi_prefetch_disable(struct xspi_pdata *xspi)
{
    xspi_prefetch_clear(xspi, 0u);
    xspi_prefetch_clear(xspi, 1u);
    xspi_prefetch_clear(xspi, 2u);
    xspi_prefetch_clear(xspi, 3u);
    xspi_prefetch_clear(xspi, 4u);
    xspi_prefetch_clear(xspi, 5u);
    xspi_prefetch_clear(xspi, 6u);
    xspi_prefetch_clear(xspi, 7u);
    xspi_writel(0, xspi->apb_base + XSPI_GROUP_MERGE);
}

/* In xip mode, this func should to put into iram. */
static void xspi_prefetch_enable(struct xspi_pdata *xspi)
{
    xspi_writel(BIT(25), xspi->apb_base + XSPI_AXI_CTRL);

    xspi_prefetch_config(xspi, 0u, 0xff00u, 0x000u, 2u, 4u);
    xspi_prefetch_config(xspi, 1u, 0xff00u, 0x000u, 2u, 4u);
    xspi_prefetch_config(xspi, 2u, 0xff00u, 0x100u, 2u, 4u);
    xspi_prefetch_config(xspi, 3u, 0xff00u, 0x200u, 2u, 4u);
    xspi_prefetch_config(xspi, 4u, 0xff00u, 0x300u, 2u, 4u);
    xspi_prefetch_config(xspi, 5u, 0xff00u, 0x400u, 2u, 4u);
    xspi_prefetch_config(xspi, 6u, 0xff00u, 0x500u, 8u, 1u);
    xspi_prefetch_config(xspi, 7u, 0xff00u, 0x800u, 8u, 1u);
    /* merge group 0-1 for sf core */
    xspi_writel(1u, xspi->apb_base + XSPI_GROUP_MERGE);
}

void *xspi_lld_init(struct xspi_pdata *xspi)
{
    /* initialize the current cs for no one */
    xspi->current_cs = 0xff;

#ifdef SEMIDRIVE_E3_LITE_SERIES
    xspi->fifo_depth = 48;
#else
    xspi->fifo_depth = 16;
#endif
    xspi->fifo_width = 4u;

    if (xspi_lld_wait_idle(xspi)) {
        return NULL;
    }

    /* Use rx mode by pop data by deafult */
    xspi_writel(XSPI_MODE_CTRL_RX_MODE, xspi->apb_base + XSPI_MODE_CTRL);

    /* Enable prefetch by default */
    xspi_prefetch_enable(xspi);

#ifdef XSPI_INDIRECT_AXI_EN
    /* indirect wr/rd enable */
    REG_RMW32(xspi->apb_base + XSPI_MISC, 10, 2, 0x3);
    xspi_readl(xspi->apb_base + XSPI_MISC);
#endif

    /* Set capture enable select to 7 clk period */
    REG_RMW32(xspi->apb_base + XSPI_MISC, 12, 3, 0x5);

    xspi_lld_reset_flash(xspi);

    /* rx_mode use internal sclk by default */
    xspi_lld_rx_config(xspi, 0x0);

    xspi_lld_dll_enable(xspi, 0, 7u, true);
    xspi_lld_dll_enable(xspi, 1, 4u, true);

    return (void *)xspi;
}

static inline void readsl(uint32 *addr, uint32 *data, uint32 len)
{
    while (len-- != 0u) {
        *data++ = readl(addr);
    }
}

static inline void writesl(uint32 *addr, uint32 const *data, uint32 len)
{
    while (len-- != 0u) {
        writel(*data, (uint32)addr);
        data++;
    }
}

static inline void readsl_increase(uint32 *addr, uint32 *data, uint32 len)
{
    while (len-- != 0u) {
        *data++ = readl(addr++);
    }
}

static inline int word_cmp(uint32 *ptr0, uint32 *ptr1, uint32 len)
{
    while (len-- != 0u) {
        if (*ptr0++ != *ptr1++)
            return -1;
    }

    return 0;
}

/* In xip mode, this func should to put into iram. */
int xspi_direct_access_training(addr_t apb_base, uint8 *addr,
                                uint8 *buf, const uint8 *pattern,
                                flash_size_t size)
{
    int ret = 0;
    uint32 rx_delay;
    uint32 rx_delay_start = 0;
    uint32 training_steps;
    bool train_ok = false;
    struct xspi_pdata host = {
        .apb_base = apb_base,
    };
    struct xspi_pdata *xspi = &host;

    DSB;
    ISB;
    xspi_prefetch_disable(xspi);

#ifdef XSPI_DLL_USE_OVERRIDE_MODE
    training_steps = 0x7fu;
#else
    training_steps = 0x1fu;
#endif

    for (rx_delay = 0u; rx_delay <= training_steps; rx_delay++) {
        xspi_lld_dll_enable(xspi, 0u, rx_delay, true);
        xspi_lld_dll_enable(xspi, 1u, rx_delay, true);

        /*PRQA S 3305 2*/
        readsl_increase((uint32 *)addr, (uint32 *)buf, size / 4u);

        s_lockstep_err = xspi_readl(xspi->apb_base + XSPI_LSP_ERR_ST);

        if (s_lockstep_err != 0) {
            writel(s_lockstep_err, xspi->apb_base + XSPI_LSP_ERR_ST);
        }

        /*PRQA S 3305 2*/
        if (word_cmp((uint32 *)buf, (uint32 *)pattern, size / 4u) == 0) {
            if (train_ok == false) {
                train_ok = true;
                rx_delay_start = rx_delay;
            }
        } else {
            if (train_ok && (rx_delay > (rx_delay_start + 10u)))
                break;
            else
                train_ok = false;
        }
    }

    if (train_ok) {
        rx_delay = (rx_delay_start + rx_delay) / 2u;
        xspi_lld_dll_enable(xspi, 0u, rx_delay, true);
        xspi_lld_dll_enable(xspi, 1u, rx_delay, true);
        ret = 0;
    } else {
        xspi_lld_dll_enable(xspi, 0u, 0u, false);
        xspi_lld_dll_enable(xspi, 1u, 0u, false);
        ret = -1;
    }

    xspi_prefetch_enable(xspi);
    DSB;
    ISB;

    return ret;
}

static void xspi_lld_size_set(struct spi_nor *nor)
{
    uint32 size = 0;
    struct xspi_pdata *xspi = nor->host->priv_data;

    uint32 reg = xspi_readl(xspi->apb_base + XSPI_DEV_SIZE);

    size = my_log2_uint(nor->info.size) & 0x1Fu;

    if ((size != 0) && (size != (reg & 0xff))) {
        REG_RMW32(xspi->apb_base + XSPI_DEV_SIZE, nor->cs * 8, 5, size);
        reg = xspi_readl(xspi->apb_base + XSPI_DEV_SIZE);
        DBG("xspi dev size reg = 0x%x\n", reg);
    }
}

void xspi_lld_proto_setup(struct spi_nor *nor, struct spi_nor_cmd *cmd,
                          enum xspi_access_mode access_mode,
                          enum spi_nor_ops ops)
{
    struct xspi_pdata *xspi = nor->host->priv_data;
    uint32 ph_ctrl = 0;
    uint16 cmd_code = 0;
    uint8 dummy = 0;

    if (!nor->hyperbus_mode) {
        ph_ctrl |= XSPI_C_EN | XSPI_C_SIZE(0u);
    }

    if (nor->octal_dtr_en || nor->hyperbus_mode) {
        ph_ctrl |= XSPI_C_RATE(1u) | XSPI_A_RATE(1u) | XSPI_D_RATE(1u) |
                   XSPI_C_SIZE(1u) | XSPI_A_SIZE(3u);
    }

    if (nor->xfer_info_bottom.size > 0) {
        ph_ctrl |= XSPI_D_EN;
    }

    if (cmd) {
        dummy = cmd->dummy;
        ph_ctrl |= XSPI_C_LINE(cmd->inst_type) | XSPI_A_LINE(cmd->inst_type) |
                   XSPI_D_LINE(cmd->inst_type);
        cmd_code = cmd->opcode;

        if (cmd->addr_bytes) {
            ph_ctrl |= XSPI_A_EN | XSPI_A_SIZE(cmd->addr_bytes - 1);
        }
    } else {
        if (nor->addr_width) {
            ph_ctrl |= XSPI_A_SIZE(nor->addr_width - 1);
        }

        if (SPI_NOR_OPS_WRITE == ops) {
            dummy = 0;
            ph_ctrl |= XSPI_C_LINE(SNOR_INST_LANS(nor->info.write_proto)) |
                       XSPI_A_LINE(SNOR_ADDR_LANS(nor->info.write_proto)) |
                       XSPI_D_LINE(SNOR_DATA_LANS(nor->info.write_proto));
            cmd_code = (nor->info.write_proto >> SNOR_OPCODE_PROTO_LSB) & 0xff;
        } else if (SPI_NOR_OPS_READ == ops) {
            dummy = nor->info.read_dummy;
            ph_ctrl |= XSPI_C_LINE(SNOR_INST_LANS(nor->info.read_proto)) |
                       XSPI_A_LINE(SNOR_ADDR_LANS(nor->info.read_proto)) |
                       XSPI_D_LINE(SNOR_DATA_LANS(nor->info.read_proto));
            cmd_code = (nor->info.read_proto >> SNOR_OPCODE_PROTO_LSB) & 0xff;
        }
    }

    /* For hyperbus mode, taishan xspi's dummy is device spec's dummy - 1 */
    if (nor->hyperbus_mode && dummy > 0u) {
        dummy = dummy - 1u;
    }

    if (nor->octal_dtr_en || nor->hyperbus_mode) {
        cmd_code |= cmd_code << 8u;
    }

    if (XSPI_DIRECT_ACCESS_MODE == access_mode) {
        if (SPI_NOR_OPS_WRITE == ops) {
            xspi_writel(ph_ctrl, xspi->apb_base + XSPI_DIRECT_WR_PH_CTRL);
            REG_RMW32(xspi->apb_base + XSPI_DIRECT_C_CODE, 16, 16, cmd_code);
            xspi_readl(xspi->apb_base + XSPI_DIRECT_C_CODE);
            REG_RMW32(xspi->apb_base + XSPI_DIRECT_D_CYC, 8, 5, dummy);
            xspi_readl(xspi->apb_base + XSPI_DIRECT_D_CYC);

            /* Hyperbus mode not need write enable */
            if (!nor->hyperbus_mode) {
                xspi_writel(0x06u << 16 | 1, xspi->apb_base + XSPI_DIRECT_WREN);
            }
        } else if (SPI_NOR_OPS_READ == ops) {
            xspi_writel(ph_ctrl, xspi->apb_base + XSPI_DIRECT_RD_PH_CTRL);
            REG_RMW32(xspi->apb_base + XSPI_DIRECT_C_CODE, 0, 16, cmd_code);
            xspi_readl(xspi->apb_base + XSPI_DIRECT_C_CODE);
            REG_RMW32(xspi->apb_base + XSPI_DIRECT_D_CYC, 0, 5, dummy);
            xspi_readl(xspi->apb_base + XSPI_DIRECT_D_CYC);
        } else {
            DBG("%s: set direct mode err. %d\n", __FUNCTION__,
                ops);
        }
    } else {
        if (!cmd) {
            ph_ctrl |= (nor->addr_width > 0 ? XSPI_A_EN : 0);
        }

        if (SPI_NOR_OPS_WRITE == ops) {
            xspi_writel(ph_ctrl, xspi->apb_base + XSPI_INDIRECT_WR_PH_CTRL);
            xspi_writel(cmd_code, xspi->apb_base + XSPI_INDIRECT_WR_CMD_CODE);
            xspi_writel(dummy, xspi->apb_base + XSPI_INDIRECT_WR_CYC);
        } else if (SPI_NOR_OPS_READ == ops) {
            xspi_writel(ph_ctrl, xspi->apb_base + XSPI_INDIRECT_RD_PH_CTRL);
            xspi_writel(cmd_code, xspi->apb_base + XSPI_INDIRECT_RD_CMD_CODE);
            xspi_writel(dummy, xspi->apb_base + XSPI_INDIRECT_RD_CYC);
        } else {
            DBG("%s: set indirect mode err. %d\n",
                __FUNCTION__, ops);
        }
    }
}

/*
static void xspi_lld_cs_set(struct spi_nor *nor)
{
    uint32 reg;
    uint8 cs;
    struct xspi_pdata *xspi = nor->host->priv_data;

    if (nor->cs == 0u) {
        cs = XSPI_CS_CTRL_HW_SEL_DEV1;
    } else {
        cs = XSPI_CS_CTRL_HW_SEL_DEV2;
    }

    reg = xspi_readl(xspi->apb_base + XSPI_CS_CTRL);
    reg &= ~(XSPI_CS_CTRL_HW_SEL_MASK << XSPI_CS_CTRL_HW_SEL_LSB);

    reg |= cs << XSPI_CS_CTRL_HW_SEL_LSB;

    xspi_writel(reg, xspi->apb_base + XSPI_CS_CTRL);
}
*/

static void xspi_lld_polling_set(struct spi_nor *nor)
{
    struct xspi_pdata *xspi = nor->host->priv_data;

    xspi_writel(1u, xspi->apb_base + XSPI_INDIRECT_P_VALUE);
    xspi_writel(0xfffffffeu, xspi->apb_base + XSPI_INDIRECT_P_MASK);
    xspi_writel(XSPI_MS_2_TICKS((uint32)xspi->ref_clk_hz / 80, 1),
                xspi->apb_base + XSPI_INDIRECT_P_TIME);
}

void xspi_lld_dqs_enable(struct xspi_pdata *xspi, bool enable)
{
    uint32 reg;

    /* For aviod dqs bug */
    REG_RMW32(xspi->apb_base + XSPI_MISC, 9u, 1u, 1);

    reg = xspi_readl(xspi->apb_base + XSPI_SCLK_CTRL);
    reg &= ~(XSPI_SCLK_CTRL_RX_SEL_MASK << XSPI_SCLK_CTRL_RX_SEL_LSB);

    if (enable) {
        /* dqs mode */
        reg |= 2u << XSPI_SCLK_CTRL_RX_SEL_LSB;
    } else {
        reg |= 0u << XSPI_SCLK_CTRL_RX_SEL_LSB;
    }

    xspi_writel(reg, xspi->apb_base + XSPI_SCLK_CTRL);
}

static inline void xspi_hyperbus_en(struct spi_nor *nor)
{
    struct xspi_pdata *xspi = nor->host->priv_data;

    uint32 reg;
    reg = xspi_readl(xspi->apb_base + 0x60);
    reg |= BIT(4);
    xspi_writel(reg, xspi->apb_base + 0x60);

    /* Set rx enable mode to half-dummy or rdata phase 0 */
    REG_RMW32(xspi->apb_base + XSPI_MISC, 9u, 1u, 1);
    xspi_readl(xspi->apb_base + XSPI_MISC);

    /* Set bytes swap */
    REG_RMW32(xspi->apb_base + XSPI_MODE_CTRL, 12u, 1u, 1);

    /* Set profile2.0 enable */
    REG_RMW32(xspi->apb_base + XSPI_HYPERBUS_CTRL, 3u, 1u, 1);

    /* Set address type divided to 2 */
    REG_RMW32(xspi->apb_base + XSPI_HYPERBUS_CTRL, 2u, 1u, 0);

    /*Set address space type memory */
    REG_RMW32(xspi->apb_base + XSPI_HYPERBUS_CTRL, 1u, 1u, 0);

    REG_RMW32(xspi->apb_base + XSPI_HYPERBUS_CTRL, 0u, 1u, nor->hyperbus_mode);
}

static void xspi_hyperbus_direct_setup(struct spi_nor *nor)
{
    struct xspi_pdata *xspi = nor->host->priv_data;

    /* Config direct read pre-transaction to 0 */
    xspi_writel(0, xspi->apb_base + XSPI_DIRECT_RD_PTC);

    /* Config direct write pre-transaction to 0 */
    xspi_writel(0, xspi->apb_base + XSPI_DIRECT_WR_PTC);

    xspi_lld_proto_setup(nor, NULL, XSPI_DIRECT_ACCESS_MODE, SPI_NOR_OPS_READ);
    xspi_lld_proto_setup(nor, NULL, XSPI_DIRECT_ACCESS_MODE, SPI_NOR_OPS_WRITE);
}

void xspi_lld_hyperram_enable(struct spi_nor *nor, uint8 cs,
                              uint8 read_dummy, uint8 write_dummy)
{
    uint32 dummy;
    struct xspi_pdata *xspi = nor->host->priv_data;

    REG_RMW32(xspi->apb_base + XSPI_DEV_SIZE, 16u + cs, 1u, 0x1u);

    /* Config direct read pre-transaction to 0 */
    xspi_writel(0, xspi->apb_base + XSPI_DIRECT_RD_PTC);

    /* Config direct write pre-transaction to 0 */
    xspi_writel(0, xspi->apb_base + XSPI_DIRECT_WR_PTC);

    dummy = ((read_dummy + 1) & XSPI_DIRECT_D_CYC_RD_MASK) << XSPI_DIRECT_D_CYC_RD_LSB;
    dummy |= ((write_dummy + 1) & XSPI_DIRECT_D_CYC_WR_MASK) << XSPI_DIRECT_D_CYC_WR_LSB;
    xspi_writel(dummy, xspi->apb_base + XSPI_DIRECT_D_CYC);

    xspi_prefetch_disable(xspi);
}

void xspi_lld_nor_setup(struct spi_nor *nor, enum spi_nor_ops ops)
{
    struct xspi_pdata *xspi = nor->host->priv_data;

    if (xspi_lld_wait_idle(xspi)) {
        DBG("%s: wait idle err.", __FUNCTION__);
        return;
    }

    if (nor->cs != xspi->current_cs && nor->info.name != 0) {
        /* cs select by hardware, based on access address */
        // xspi_lld_cs_set(nor);
        xspi_lld_delay_set(nor);

        if (nor->hyperbus_mode) {
            xspi_hyperbus_en(nor);
            xspi_lld_proto_setup(nor, NULL, XSPI_INDIRECT_ACCESS_MODE,
                                 SPI_NOR_OPS_READ);
            xspi_lld_proto_setup(nor, NULL, XSPI_INDIRECT_ACCESS_MODE,
                                 SPI_NOR_OPS_WRITE);
            xspi_hyperbus_direct_setup(nor);
        } else {
            xspi_lld_polling_set(nor);
        }

        xspi->current_cs = nor->cs;
    }

    if (nor->info.name != 0) {
        xspi_lld_size_set(nor);
    }

    if (nor->dqs_en != xspi->dqs_en) {
        xspi_lld_dll_enable(xspi, 0, 7u, nor->dqs_en);
        xspi_lld_dll_enable(xspi, 1, 7u, nor->dqs_en);
        xspi_lld_dqs_enable(xspi, nor->dqs_en);
        xspi->dqs_en = nor->dqs_en;
    }

    if (!nor->hyperbus_mode) {
        xspi_lld_proto_setup(nor, NULL, XSPI_DIRECT_ACCESS_MODE, SPI_NOR_OPS_READ);
    }

    return;
}

void xspi_lld_setup_xfer(struct spi_nor *nor, enum flash_opt opt,
                         flash_addr_t addr, uint8 *buf, flash_size_t size)

{
    nor->xfer_info_bottom.opt_type = opt;
    nor->xfer_info_bottom.addr = addr;
    nor->xfer_info_bottom.buf = buf;
    nor->xfer_info_bottom.opt_result = FLASH_OPT_PENDING;
    nor->xfer_info_bottom.size = size;
}

void xspi_lld_release_xfer(struct spi_nor *nor)
{
    nor->xfer_info_bottom.buf = NULL;
}

uint32 xspi_lld_read_fifo(struct xspi_pdata *xspi, uint8 *buf,
                          flash_size_t size)
{
    uint32 last_word;
    uint32 aligned_size;
    uint32 bytes_need_read = 0;

#ifdef XSPI_INDIRECT_AXI_EN
    uint32 addr = xspi_readl(xspi->apb_base + XSPI_INDIRECT_RD_ADDR);
    addr_t fifo_address = xspi->direct_base + ROUNDUP(addr, 4u);
#else
    addr_t fifo_address = xspi->apb_base + XSPI_INDIRECT_RDATA;
#endif

    bytes_need_read =
        xspi_lld_get_rd_buf_level(xspi) * (uint32)xspi->fifo_width;

    bytes_need_read = _MIN(bytes_need_read, size);

    if (bytes_need_read) {
        aligned_size = bytes_need_read / 4u * 4u;

        if (aligned_size == 16) {
            DBG("DBG: aligned size %d\n", aligned_size);
        }

        readsl((uint32 *)fifo_address, (void *)buf, aligned_size / 4u);

        if (bytes_need_read % 4) {
            last_word = readl(fifo_address);
            mini_memcpy_s(buf + aligned_size, &last_word, bytes_need_read % 4);
        }

        return bytes_need_read;
    }

    return 0;
}

uint32 xspi_lld_write_fifo(struct xspi_pdata *xspi, const uint8 *buf,
                           flash_size_t size)
{
    uint32 sram_level;
    uint32 write_bytes = 0;
    uint32 sram_size = (uint32)xspi->fifo_depth * xspi->fifo_width;

#ifdef XSPI_INDIRECT_AXI_EN
    uint32 addr = xspi_readl(xspi->apb_base + XSPI_INDIRECT_WR_ADDR);
    addr_t fifo_address = xspi->direct_base + ROUNDUP(addr, 4u);
#else
    addr_t fifo_address = xspi->apb_base + XSPI_INDIRECT_WDATA;
#endif

    write_bytes = _MIN(size, sram_size);

    sram_level = xspi_lld_get_wr_buf_level(xspi);

    if (0u == sram_level) {
        writesl((uint32 *)fifo_address, (void *)buf,
                DIV_ROUND_UP(write_bytes, 4u));
        return write_bytes;
    }

    return 0;
}

void xspi_lld_indirect_trigger(const struct xspi_pdata *xspi, uint32 addr,
                               uint32 size, int flag)
{
    if (flag == INDIRECT_READ_FLAG) {
        /* Set indirect read start address */
        xspi_writel(addr, xspi->apb_base + XSPI_INDIRECT_RD_ADDR);
        /* Set indirect read bytes number */
        xspi_writel(size, xspi->apb_base + XSPI_INDIRECT_RD_SIZE);
        /* Start the indirect read */
        writel(1u, xspi->apb_base + XSPI_INDIRECT_RD_CTRL);
    } else {
        /* Set indirect write start address */
        xspi_writel(addr, xspi->apb_base + XSPI_INDIRECT_WR_ADDR);
        /* Set indirect write bytes number */
        xspi_writel(size, xspi->apb_base + XSPI_INDIRECT_WR_SIZE);
        /* Start the indirect write */
        writel(1u, xspi->apb_base + XSPI_INDIRECT_WR_CTRL);
    }
}

int xspi_lld_tx_complete(struct xspi_pdata *xspi)
{
    int ret = 0;
    uint32 reg;

    ret =
        xspi_wait_for_bit_times(xspi->apb_base + XSPI_INT_ST_FUC,
                                XSPI_INT_ST_FUC_INDIRECT_WR_DONE, false, 100u);

    if (ret != 0) {
        DBG("Indirect write not complete, ret %d.\n", ret);
    } else {
        reg = xspi_readl(xspi->apb_base + XSPI_INT_ST_FUC);
        xspi_writel(reg, xspi->apb_base + XSPI_INT_ST_FUC);
    }

    return ret;
}

int xspi_lld_rx_complete(struct xspi_pdata *xspi)
{
    int ret = 0;
    uint32 reg;

    ret =
        xspi_wait_for_bit_times(xspi->apb_base + XSPI_INT_ST_FUC,
                                XSPI_INT_ST_FUC_INDIRECT_RD_DONE, false, 10000u);

    if (ret != 0) {
        DBG("Indirect read not complete, ret %d.\n", ret);
    } else {
        reg = xspi_readl(xspi->apb_base + XSPI_INT_ST_FUC);
        xspi_writel(reg, xspi->apb_base + XSPI_INT_ST_FUC);
    }

    return ret;
}

int xspi_lld_rx_polling(struct spi_nor *nor)
{
    int ret = 0;
    uint32 rx_size;
    struct xspi_pdata *xspi = nor->host->priv_data;

    if ((nor->xfer_info_bottom.buf != NULL) &&
        (nor->xfer_info_bottom.size > 0u)) {
        rx_size = xspi_lld_read_fifo(xspi, nor->xfer_info_bottom.buf,
                                     nor->xfer_info_bottom.size);
        nor->xfer_info_bottom.buf += rx_size;
        nor->xfer_info_bottom.size -= rx_size;

        if (nor->xfer_mode == SPI_NOR_XFER_POLLING_MODE) {
            if (nor->xfer_info_bottom.size == 0u) {
                ret = xspi_lld_rx_complete(xspi);
            }
        }
    } else {
        ret = xspi_lld_rx_complete(xspi);
    }

    return ret;
}

int xspi_lld_tx_polling(struct spi_nor *nor)
{
    int ret = 0;
    uint32 tx_size;
    struct xspi_pdata *xspi = nor->host->priv_data;

    if ((nor->xfer_info_bottom.buf != NULL) &&
        (nor->xfer_info_bottom.size > 0u)) {
        tx_size = xspi_lld_write_fifo(xspi, nor->xfer_info_bottom.buf,
                                      nor->xfer_info_bottom.size);
        nor->xfer_info_bottom.buf += tx_size;
        nor->xfer_info_bottom.size -= tx_size;

        if (nor->xfer_mode == SPI_NOR_XFER_POLLING_MODE) {
            if (nor->xfer_info_bottom.size == 0u) {
                ret = xspi_lld_tx_complete(xspi);
            }
        }
    } else {
        ret = xspi_lld_tx_complete(xspi);
    }

    return ret;
}

void xspi_lld_int_unmask(struct xspi_pdata *xspi, addr_t addr, uint32 mask)
{
    uint32 reg;
    reg = xspi_readl(xspi->apb_base + addr);
    reg |= mask;
    xspi_writel(reg, xspi->apb_base + addr);
}

void xspi_lld_rfd_en(struct xspi_pdata *xspi)
{
    uint32 reg;

    /* Key derivation trigger */
    reg = xspi_readl(xspi->apb_base + XSPI_IMG_RFD);
    reg |= BIT(8);
    xspi_writel(reg, xspi->apb_base + XSPI_IMG_RFD);

    /* Polling key ready */
    while (!(readl(xspi->apb_base + XSPI_IMG_RFD) & BIT(16)))
        ;

    /* Enable decryption */
    reg = xspi_readl(xspi->apb_base + XSPI_IMG_RFD);
    reg |= BIT(28);
    xspi_writel(reg, xspi->apb_base + XSPI_IMG_RFD);
}

#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#ifdef __cplusplus
}
#endif
