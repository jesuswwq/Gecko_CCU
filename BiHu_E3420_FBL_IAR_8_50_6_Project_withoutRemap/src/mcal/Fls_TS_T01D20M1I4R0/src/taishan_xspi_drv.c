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
* @file  taishan_xspi_drv.c
* @brief Semidrive. AUTOSAR 4.3.1 MCAL Fls plugins.
*/

#ifdef __cplusplus
extern "C" {
#endif

#include <debug.h>
#include <cdefs.h>
#include <taishan_xspi_drv.h>
#if defined(CFG_DMA_SUPPORT_STATIC_ALLOCATION)
#include <Dma.h>
#else
#include "dma.h"
#include "dma_cfg.h"
#include "sdrv_dmac.h"
#endif
#include <taishan_xspi.h>
#include <irq.h>
#include "arch.h"
#include "Mcu.h"
#include "Mcu_Scr.h"
#include "Mcu_Soc.h"
#include "Mcu_ScrBits.h"
#include "Mcu_Scr.h"
#include "Mcu_Mpu.h"
#include "Mcu_Delay.h"
#include "e3_clk.h"
#include "irq_num.h"
#include "__regs_base.h"
#include "e3_clock_cfg_nd.h"
#include "reset.h"
#include "Mcu_Reset.h"
#include "Fls.h"
#include "Fls_Cfg.h"
#include "cdefs.h"

/* default use direct read mode */
#ifndef XSPI_USE_DIRECT_MODE
#define XSPI_USE_DIRECT_MODE (1)
#endif

#define SPI_NOR_XFER_COMPLETE (0x1u)

#define FLS_START_SEC_VAR_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

static uint32 s_lockstep_err = 0;

#define FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

static struct xspi_pdata xspi_table[FLS_CONTROLLER_ID_MAX];

static uint32 g_enable_event;

#define FLS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

static struct xspi_config host_config[FLS_CONTROLLER_ID_MAX] = {
    [FLS_XSPI1_PORTA] = {
        .id = 0,
        .irq = XSPI1_IRQ0_INTR_NUM,
        .apb_base = APB_XSPI1PORTA_BASE,
        .direct_base = XSPI1_XSPI1PORTA_BASE,
        .clk = CLK_NODE(g_ckgen_ip_xspi1a),
    },
    [FLS_XSPI1_PORTB] = {
        .id = 0,
        .irq = XSPI1_IRQ1_INTR_NUM,
        .apb_base = APB_XSPI1PORTB_BASE,
        .direct_base = XSPI1_XSPI1PORTB_BASE,
        .clk = CLK_NODE(g_ckgen_ip_xspi1b)
    },
#if (XSPI_RESOURE_NUM >= 2)
    [FLS_XSPI2_PORTA] = {
        .id = 0,
        .irq = XSPI2_IRQ0_INTR_NUM,
        .apb_base = APB_XSPI2PORTA_BASE,
        .direct_base = XSPI2_XSPI2PORTA_BASE,
        .clk = CLK_NODE(g_ckgen_ip_xspi2a)
    },
    [FLS_XSPI2_PORTB] = {
        .id = 0,
        .irq = XSPI2_IRQ1_INTR_NUM,
        .apb_base = APB_XSPI2PORTB_BASE,
        .direct_base = XSPI2_XSPI2PORTB_BASE,
        .clk = CLK_NODE(g_ckgen_ip_xspi2b)
    },
#endif
};

#define FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"

int xspi_host_init(struct spi_nor_host *host, struct xspi_pdata *xspi,
                   struct xspi_config *config);

static void xspi_cache_flush(struct spi_nor *nor, flash_addr_t addr,
                             flash_size_t length);
void xspi_lockstep_enable(boolean flag, uint8 id)
{
    scr_signal_t signal;
    reset_sig_t *xspi_porta, *xspi_portb;

    switch (id) {
    case FLS_XSPI1_PORTA:
        signal = (scr_signal_t)SCR_SF_XSPI1_SRC_CFG_LOCKSTEP_MODE_N;
        xspi_porta = &rstsig_xspi1a;
        xspi_portb = &rstsig_xspi1b;
        break;
#if (XSPI_RESOURE_NUM >= 2)
    case FLS_XSPI2_PORTA:
        signal = (scr_signal_t)SCR_SF_XSPI2_SRC_CFG_LOCKSTEP_MODE_N;
        xspi_porta = &rstsig_xspi2a;
        xspi_portb = &rstsig_xspi2b;
        break;
#endif
    default:
        DBG("xspi %d unsupport lockstep mode", id);
        return;
    }

    reset_ctl_assert(xspi_portb);
    reset_ctl_assert(xspi_porta);
    DSB;
    udelay(10);
    Mcu_ScrSetBit(&signal, !flag);
    udelay(10);
    DSB;
    reset_ctl_deassert(xspi_porta);
    reset_ctl_deassert(xspi_portb);
}

void xspi_parallel_enable(boolean flag, uint8 id)
{
    scr_signal_t signal;
    reset_sig_t *xspi_porta, * xspi_portb;

    switch (id) {
    case FLS_XSPI1_PORTA:
        signal = (scr_signal_t)SCR_SF_XSPI1_SRC_CFG_PARALLEL_MODE;
        xspi_porta = &rstsig_xspi1a;
        xspi_portb = &rstsig_xspi1b;
        break;
#if (XSPI_RESOURE_NUM >= 2)
    case FLS_XSPI2_PORTA:
        signal = (scr_signal_t)SCR_SF_XSPI2_SRC_CFG_PARALLEL_MODE;
        xspi_porta = &rstsig_xspi2a;
        xspi_portb = &rstsig_xspi2b;
        break;
#endif
    default:
        DBG("xspi %d unsupport parallel mode", id);
        return;
    }

    reset_ctl_assert(xspi_portb);
    reset_ctl_assert(xspi_porta);
    DSB;
    udelay(10);
    Mcu_ScrSetBit(&signal, flag);
    udelay(10);
    DSB;
    reset_ctl_deassert(xspi_porta);
    reset_ctl_deassert(xspi_portb);
}

int board_norflash_init(struct spi_nor_host *host, const struct spi_nor_config *config)
{
    int ret = 0;
    boolean locksetp_mode = FALSE;
    boolean parallel_mode = FALSE;
    clk_node_t *clk = host_config[config->id].clk;

    switch (config->dev_mode) {
    case SPI_NOR_DEV_LOCKSTEP_MODE:
        locksetp_mode = TRUE;
        break;

    case SPI_NOR_DEV_PARALLEL_MODE:
        parallel_mode = TRUE;
        break;

    default:
        break;
    }

    xspi_lockstep_enable(locksetp_mode, config->id);
    xspi_parallel_enable(parallel_mode, config->id);

    host_config[config->id].ref_clk = clk_get_rate(clk);
    ret = xspi_host_init(host, &xspi_table[config->id], &host_config[config->id]);
    if (ret == 0) {
        host->clk = clk;

        ret = clk_set_rate(clk, config->baudrate);
        DBG("xspi clock rate is %u!\n", clk_get_rate(clk));
    }

    return ret;
}

extern void xspi_lld_rx_config(struct xspi_pdata *xspi, uint32 mode);

static inline uint8 xspi_compromise_alg(unsigned int x)
{
    uint8 left = 0, right = 31, mid = 0;

    while (left < right) {
        mid = (left + right) >> 1;

        if ((0xffffffffU - ((1u << (mid + 1)) - 1)) & x) {
            left = mid + 1;
        } else if (x & (1u << mid)) {
            return mid;
        } else {
            right = mid - 1;
        }
    }

    return left;
}

static int xspi_polling_handler(void *arg)
{
    int ret = 0;
    struct spi_nor *nor = arg;
    struct xspi_pdata *xspi = nor->host->priv_data;

    if (nor->xfer_info_bottom.opt_result == FLASH_OPT_PENDING) {
        if (nor->xfer_info_bottom.opt_type == FLASH_OPT_READ) {
            ret = xspi_lld_rx_polling(nor);
        } else if (nor->xfer_info_bottom.opt_type == FLASH_OPT_WRITE) {
            ret = xspi_lld_tx_polling(nor);
        }
    }

    nor->xfer_info_bottom.opt_result = ret ? FLASH_OPT_FAILED : FLASH_OPT_PENDING;

    if ((nor->xfer_info_bottom.size == 0 || nor->xfer_info_bottom.buf == NULL) &&
        nor->xfer_info_bottom.opt_result == FLASH_OPT_PENDING) {
        nor->xfer_info_bottom.opt_result = FLASH_OPT_COMPLETE;

        if ((nor->xfer_mode == SPI_NOR_XFER_POLLING_MODE)
            || (nor->xfer_info_bottom.opt_type == FLASH_OPT_READ)) {
            xspi_writel(0u, xspi->apb_base + XSPI_INT_EN_FUC);

            if (nor->async_mode) {
                if (nor->event_handler)
                    nor->event_handler(nor->xfer_info_bottom.opt_type,
                                       nor->xfer_info_bottom.opt_result);
            } else {
                /* Set xfer complete flag when read opt */
                g_enable_event = 1;
            }
        }
    }

    return (int)nor->xfer_info_bottom.opt_result;
}

static void xspi_wait_xfer_done(struct spi_nor *nor)
{
    struct xspi_pdata *xspi = nor->host->priv_data;
    uint32 try_count = 0;

    if (nor->xfer_mode != SPI_NOR_XFER_POLLING_MODE) {
        while ((!g_enable_event) && (try_count < 1000000U)) {
            Mcu_udelay(1);  // wait 1s for indirect write(<=256B) or read(nB)
            try_count++;
        }
        if (try_count >= 1000000U) {
            ERROR("xspi wait 0x%u us, exit\n", try_count);
            nor->xfer_info_bottom.opt_result = FLASH_OPT_FAILED;
        }
        g_enable_event = 0;
        s_lockstep_err = xspi_readl(xspi->apb_base + XSPI_LSP_ERR_ST);

        if (s_lockstep_err != 0) {
            writel(s_lockstep_err, xspi->apb_base + XSPI_LSP_ERR_ST);
            DBG("xspi lsp error status = 0x%x\n", s_lockstep_err);
        }
    } else {
        while (1) {
            xspi_polling_handler(nor);

            if (g_enable_event == 1) {
                g_enable_event = 0;
                s_lockstep_err = xspi_readl(xspi->apb_base + XSPI_LSP_ERR_ST);

                if (s_lockstep_err != 0) {
                    writel(s_lockstep_err, xspi->apb_base + XSPI_LSP_ERR_ST);
                    DBG("xspi lsp error status = 0x%x\n", s_lockstep_err);
                }

                break;
            } else if (try_count++ >= 10000000U) {
                nor->xfer_info_bottom.opt_result = FLASH_OPT_FAILED;
                ERROR("xspi polling 0x%u times, exit\n", try_count);
                break;
            }
        }
    }
    xspi_lld_release_xfer(nor);
}

static inline void para_data_prep(const uint8 *raw, uint8 *dst, uint32 len)
{
    if ((raw == NULL_PTR) || (dst == NULL_PTR)) {
        return;
    }

    for (int i = 0; i < len / 2; i++) {
        *(dst + 2 * i) = *(raw + i);
        *(dst + 2 * i + 1) = *(raw + i);
    }
}

static inline int para_data_parse(const uint8 *raw, uint8 *dst, uint32 len)
{
    int ret = 0;
    if ((raw == NULL_PTR) || (dst == NULL_PTR)) {
        return -1;
    }

    for (int i = 0; i < len / 2; i++) {
        if (*(raw + 2 * i) != *(raw + 2 * i + 1)) {
            DBG("xspi parallel read register data error!\n");
            ret = -1;
        }

        *(dst + i) = *(raw + 2 * i);
    }

    return ret;
}

static int xspi_command_read(struct spi_nor *nor, struct spi_nor_cmd *cmd,
                             flash_addr_t addr, uint8 *buf, flash_size_t len)
{
    uint32 irq_trig_level;
    struct xspi_pdata *xspi = nor->host->priv_data;

    uint8 *ptr = buf;
    uint8 local_buf[32] = {0};
    flash_size_t read_length = len;
    flash_addr_t read_addr = addr;

    if (nor->dev_mode == SPI_NOR_DEV_PARALLEL_MODE) {
        ptr = local_buf;
        read_length = _MAX(4u, len * 2);
        read_addr = 2u * addr;
    } else if (nor->dev_mode == SPI_NOR_DEV_SWITCH_MODE) {
        read_addr += nor->info.reg_offset;
    }

    xspi_lld_setup_xfer(nor, FLASH_OPT_READ, read_addr, ptr, read_length);

    xspi_lld_proto_setup(nor, cmd, XSPI_INDIRECT_ACCESS_MODE,
                         SPI_NOR_OPS_READ);

    irq_trig_level = _MIN(xspi->fifo_depth / 2, DIV_ROUND_UP(read_length, 4u));

    REG_RMW32(xspi->apb_base + XSPI_INDIRECT_RD_DMA,
              XSPI_INDIRECT_DMA_TRIG_WML_LSB, 8u, irq_trig_level);

    xspi_lld_int_unmask(xspi, XSPI_INT_EN_FUC, XSPI_INT_ST_FUC_RX_FRE_FULL |
                        XSPI_INT_ST_FUC_INDIRECT_RD_DONE);

    xspi_lld_indirect_trigger(xspi, read_addr, read_length, INDIRECT_READ_FLAG);

    xspi_wait_xfer_done(nor);
    if (FLASH_OPT_FAILED == nor->xfer_info_bottom.opt_result) {
        return -1;
    }
    if (nor->dev_mode == SPI_NOR_DEV_PARALLEL_MODE) {
        return para_data_parse(local_buf, buf, read_length);
    }

    return 0;
}

static int xspi_command_write(struct spi_nor *nor, struct spi_nor_cmd *cmd,
                              flash_addr_t addr, const uint8 *buf,
                              flash_size_t len)
{
    uint32 tx_size;
    uint32 irq_trig_level;
    struct xspi_pdata *xspi = nor->host->priv_data;
    uint8 *ptr = (uint8 *)buf;
    uint8 local_buf[32] = {0};
    flash_size_t write_length = len;
    flash_addr_t write_addr = addr;

    if (nor->dev_mode == SPI_NOR_DEV_PARALLEL_MODE) {
        if (len != 0u) {
            write_length = len * 2u;
            para_data_prep(buf, local_buf, write_length);
            ptr = local_buf;
        }

        write_addr = addr * 2u;
    } else if (nor->dev_mode == SPI_NOR_DEV_SWITCH_MODE) {
        write_addr += nor->info.reg_offset;
    }

    xspi_lld_setup_xfer(nor, FLASH_OPT_WRITE, write_addr, ptr, write_length);

    xspi_lld_proto_setup(nor, cmd, XSPI_INDIRECT_ACCESS_MODE, SPI_NOR_OPS_WRITE);

    if ((nor->xfer_info_bottom.buf != NULL) &&
        (nor->xfer_info_bottom.size > 0u)) {
        tx_size = xspi_lld_write_fifo(xspi, nor->xfer_info_bottom.buf,
                                      nor->xfer_info_bottom.size);
        nor->xfer_info_bottom.buf += tx_size;
        nor->xfer_info_bottom.size -= tx_size;
    }

    xspi_lld_indirect_trigger(xspi, write_addr, write_length, INDIRECT_WRITE_FLAG);

    xspi_lld_int_unmask(xspi, XSPI_INT_EN_FUC, XSPI_INT_ST_FUC_INDIRECT_WR_DONE);

    if (buf != NULL) {
        irq_trig_level = _MIN(xspi->fifo_depth, DIV_ROUND_UP(write_length, 4u));

        REG_RMW32(xspi->apb_base + XSPI_INDIRECT_WR_DMA,
                  XSPI_INDIRECT_DMA_TRIG_WML_LSB, 8u, irq_trig_level);
    }

    xspi_wait_xfer_done(nor);

    if (FLASH_OPT_FAILED == nor->xfer_info_bottom.opt_result) {
        return -1;
    } else {
        return 0;
    }
}

#if defined(NON_AUTOSAR_STANDARD_IRQ_HANDLER)
int xspi_irq_handler(uint32 irq, void *arg)
{
    struct spi_nor_host *host = arg;
    struct xspi_pdata *xspi = host->priv_data;
    struct spi_nor *nor = host->dev;
    uint32 status;

    status = xspi_readl(xspi->apb_base + XSPI_INT_ST_ERR);
    writel(status, xspi->apb_base + XSPI_INT_ST_ERR);

    status = xspi_readl(xspi->apb_base + XSPI_INT_ST_FUC);
    DBG("xspi irq status = 0x%x\n", status);

    if ((status & (XSPI_INT_ST_FUC_IND_COMP)) != 0u) {
        nor->xfer_info_bottom.opt_result = FLASH_OPT_COMPLETE;

        if (nor->async_mode) {
            if (nor->event_handler)
                nor->event_handler(nor->xfer_info_bottom.opt_type,
                                   nor->xfer_info_bottom.opt_result);
        } else {
            g_enable_event = 1;
        }

        xspi_writel(0u, xspi->apb_base + XSPI_INT_EN_FUC);
    } else if (status &
               (XSPI_INT_ST_FUC_FIFO_LEVEL_TRIG | XSPI_INT_ST_FUC_INDIRECT_RD_DONE)) {
        xspi_polling_handler((void *)nor);
    }

    writel(status, xspi->apb_base + XSPI_INT_ST_FUC);
    return 0;
}
#else
void xspi_irq_handler(void)
{
    struct spi_nor_host *host =
        &(((Fls_ContextType*)(Fls_ConfigData.OSPIController[0].FlsPrivateData))->host);
    struct xspi_pdata *xspi = host->priv_data;
    struct spi_nor *nor = host->dev;
    uint32 status;

    status = xspi_readl(xspi->apb_base + XSPI_INT_ST_ERR);
    writel(status, xspi->apb_base + XSPI_INT_ST_ERR);

    status = xspi_readl(xspi->apb_base + XSPI_INT_ST_FUC);
    DBG("xspi irq status = 0x%x\n", status);

    if ((status & (XSPI_INT_ST_FUC_IND_COMP)) != 0u) {
        nor->xfer_info_bottom.opt_result = FLASH_OPT_COMPLETE;

        if (nor->async_mode) {
            if (nor->event_handler)
                nor->event_handler(nor->xfer_info_bottom.opt_type,
                                   nor->xfer_info_bottom.opt_result);
        } else {
            g_enable_event = 1;
        }

        xspi_writel(0u, xspi->apb_base + XSPI_INT_EN_FUC);
    } else if (status &
               (XSPI_INT_ST_FUC_FIFO_LEVEL_TRIG | XSPI_INT_ST_FUC_INDIRECT_RD_DONE)) {
        xspi_polling_handler((void *)nor);
    }

    writel(status, xspi->apb_base + XSPI_INT_ST_FUC);
}
#endif

static int xspi_lock(struct spi_nor *nor, enum spi_nor_ops ops)
{
    struct xspi_pdata *xspi = nor->host->priv_data;

    xspi_lld_indr_pre_trans_clean(nor);

    if (NULL == nor->host->dev) {
        nor->host->dev = nor;
        xspi_lld_nor_setup(nor, ops);

        if (nor->xfer_mode != SPI_NOR_XFER_POLLING_MODE) {
            DBG("irq enable!\n");
            irq_enable(xspi->irq);
        }

        return 0;
    } else {
        return -1;
    }
}

static void xspi_unlock(struct spi_nor *nor, enum spi_nor_ops ops)
{
    struct xspi_pdata *xspi = nor->host->priv_data;

    if (nor->xfer_mode != SPI_NOR_XFER_POLLING_MODE) {
        DBG("irq disable!\n");
        irq_disable(xspi->irq);
    }

    nor->host->dev = NULL;
}

#ifdef CONFIG_DMA
static void dma_transfer_every_mad_done(uint32 status, uint32 param,
                                        void *context)
{
    DBG(" xspi set dma transfer done\r\n");
}

void xspi_dma_config(struct spi_nor *nor, flash_addr_t addr, uint8 *buf,
                     uint32 len, boolean is_read_flag, boolean is_direct_flag)
{
    int ret;
    uint32 burst_lens;
    uint32 loop_lens;
    dma_dev_bus_width_e burst_width;
    struct xspi_pdata *xspi = nor->host->priv_data;
    struct dma_dev_cfg dma_cfg;

    mini_memclr_s(&dma_cfg, sizeof(struct dma_dev_cfg));

    burst_width = DMA_DEV_BUSWIDTH_4_BYTES;
    burst_lens = ROUNDDOWN(len, burst_width);

    /* workaround dma not support single req */
    if (len < 32u) {
        burst_lens = 4u;
    }

    loop_lens = _MIN(burst_lens, 32u);
    loop_lens = 1u << (xspi_compromise_alg(loop_lens));
    burst_lens = loop_lens;
    DBG("burst lens is %d\n", burst_lens);

    if (is_read_flag) {
        DBG("dev2mem\n");
        dma_cfg.direction = DMA_DEV2MEM;
        dma_cfg.src_addr = (addr_t)xspi->apb_base + XSPI_INDIRECT_RDATA;
        dma_cfg.dst_addr = (addr_t)buf;
    } else {
        DBG("mem2dev\n");
        dma_cfg.direction = DMA_MEM2DEV;
        dma_cfg.dst_addr = (addr_t)xspi->apb_base + XSPI_INDIRECT_WDATA;
        dma_cfg.src_addr = (addr_t)buf;
    }

    dma_cfg.src_addr_width = burst_width;
    dma_cfg.dst_addr_width = burst_width;
    dma_cfg.src_maxburst = burst_lens / burst_width;
    dma_cfg.dst_maxburst = burst_lens / burst_width;
#if defined(CFG_DMA_SUPPORT_STATIC_ALLOCATION)
#if (DMA_DYNAMIC_CHANNEL == STD_ON)
        extern dma_dev_t dma_sf0;
        xspi->xspi_chan = dma_req_chan(&dma_sf0);
#else
    Dma_InsConfigType dmaALConfigData;
    Dma_SubIdEnumType subType;
    if (is_read_flag) {
        if (nor->id % 2) {
            subType = DMA_XSPI_PORTB_RD;
        } else {
            subType = DMA_XSPI_PORTA_RD;
        }
    } else {
        if (nor->id % 2) {
            subType = DMA_XSPI_PORTB_WR;
        } else {
            subType = DMA_XSPI_PORTA_WR;
        }
    }
    if (E_OK == Dma_GetConfigParams(nor->id / 2, subType, DMA_MODULE_XSPI, &dmaALConfigData)) {
        xspi->xspi_chan = dma_req_chan_with_id(dmaALConfigData.Controller, dmaALConfigData.ChannelId);
    } else {
        xspi->xspi_chan = NULL_PTR;
    }
#endif /* #if (DMA_DYNAMIC_CHANNEL == STD_ON) */
#else
    extern dma_dev_t dma_sf0;
    xspi->xspi_chan = dma_req_chan(&dma_sf0);
#endif
    if (!xspi->xspi_chan) {
        DBG(" xspi_chan is null\r\n");
        return;
    }

    xspi->xspi_chan->irq_cb = dma_transfer_every_mad_done;
    dma_config_chan(xspi->xspi_chan, &dma_cfg);
    ret = dma_prep_dev(xspi->xspi_chan, buf, len, DMA_INTERRUPT);

    if (ret == 0) {
        DBG(" xspi set dma transfer config err\r\n");
    }

    dma_start(xspi->xspi_chan);
}
#endif

static inline void readsl(uint32 *addr, uint32 *data, uint32 len)
{
    while (len-- != 0u) {
        *data++ = readl(addr++);
    }
}

static int xspi_read(struct spi_nor *nor, flash_addr_t addr, uint8 *buf,
                     flash_size_t size)
{
    uint32 rel_data;
    uint32 irq_trig_level;
    uint32 mask = 0u;
    flash_size_t limit_size = size;
    flash_size_t read_size = 0;
    flash_addr_t current_addr = addr;
    flash_size_t size_done = 0;
    struct xspi_pdata *xspi = nor->host->priv_data;

    if (!IS_ALIGNED(addr, 4) || !IS_ALIGNED(buf, 4)) {
        return FLASH_OPT_FAILED;
    }

    if (addr < xspi->direct_range_size && XSPI_USE_DIRECT_MODE && !nor->async_mode) {
        /* direct access */
        arch_invalidate_cache_range((uint32 *)(xspi->direct_base + (uint32)addr), ROUNDUP(size, 32));
        /*PRQA S 3305 2*/
        readsl((uint32 *)(xspi->direct_base + (uint32)addr), (uint32 *)buf, size / 4);

        if (0 != (size % 4)) {
            readsl((uint32 *)(xspi->direct_base + (uint32)addr + (uint32)size / 4 * 4), &rel_data, 1);
            mini_memcpy_s(buf + (uint32)size / 4 * 4, &rel_data, size % 4);
        }

        return 0;
    } else {
#ifdef SEMIDRIVE_E3_LITE_SERIES
        uint8 chipver = Mcu_GetChipVersion();
        if (chipver == 0)
#endif
        {
            if ((nor->dev_mode == SPI_NOR_DEV_PARALLEL_MODE)) {
                limit_size = xspi->fifo_depth * xspi->fifo_width;
            }
        }

        while (size_done < size) {
            if ((size - size_done) > limit_size) {
                read_size = limit_size;
            } else {
                read_size = size - size_done;
            }
            xspi_lld_setup_xfer(nor, FLASH_OPT_READ, current_addr, buf + size_done, read_size);
            xspi_lld_proto_setup(nor, NULL, XSPI_INDIRECT_ACCESS_MODE,
                                SPI_NOR_OPS_READ);

            irq_trig_level = _MIN(xspi->fifo_depth / 2u, DIV_ROUND_UP(read_size, 4u));
            irq_trig_level = 1u << xspi_compromise_alg(irq_trig_level);

            /* workaround dma not support single req */
            if (size < 32u) {
                irq_trig_level = 1;
            }

            REG_RMW32(xspi->apb_base + XSPI_INDIRECT_RD_DMA,
                    XSPI_INDIRECT_DMA_TRIG_WML_LSB, 8u, irq_trig_level);
#ifdef CONFIG_DMA

            if (nor->xfer_mode == SPI_NOR_XFER_DMA_MODE) {
                arch_invalidate_cache_range((uint8 *)buf + size_done, ROUNDUP(read_size, 32));
                xspi_lld_dma_enable(xspi);
                DBG("indirect read length %lld, dma trig level %d\n", read_size, irq_trig_level);
                xspi_dma_config(nor, current_addr, buf + size_done, read_size, true, false);
                if (NULL_PTR == xspi->xspi_chan) {
                    xspi_lld_dma_disable(xspi);
                    return -1;
                }
                mask |= XSPI_INT_ST_FUC_INDIRECT_DMA_RD_DONE;
            } else {
                mask |= XSPI_INT_ST_FUC_RX_FRE_FULL | XSPI_INT_ST_FUC_INDIRECT_RD_DONE;
            }

#else
            mask |= XSPI_INT_ST_FUC_RX_FRE_FULL | XSPI_INT_ST_FUC_INDIRECT_RD_DONE;
#endif

            xspi_lld_int_unmask(xspi, XSPI_INT_EN_FUC, mask);
            xspi_lld_indirect_trigger(xspi, current_addr, read_size, INDIRECT_READ_FLAG);

            if (!nor->async_mode) {
                xspi_wait_xfer_done(nor);
#ifdef CONFIG_DMA

                if (nor->xfer_mode == SPI_NOR_XFER_DMA_MODE) {
                    xspi_lld_dma_disable(xspi);
                    dma_stop(xspi->xspi_chan);
                    dma_free_chan(xspi->xspi_chan);
                }

#endif
            }
            if (FLASH_OPT_FAILED == nor->xfer_info_bottom.opt_result) {
                break;
            } else {
                current_addr += read_size;
                size_done += read_size;
            }
        }
        return nor->xfer_info_bottom.opt_result;
    }
}

static int xspi_write(struct spi_nor *nor, flash_addr_t addr,
                      const uint8 *buf, flash_size_t size)
{
#ifndef CONFIG_FLS_HAL_POLLING
    int ret;
#endif
    uint32 irq_trig_level;
    uint32 mask = 0u;
    uint32 addr_tmp = addr;
    uint32 buf_index = 0;
    uint32 size_tmp = size;
    uint32 write_size = 0;
    boolean hyperram_mode = false;

    if (!IS_ALIGNED(addr, 4) || !IS_ALIGNED(buf, 4) || !IS_ALIGNED(size, 4)) {
        return FLASH_OPT_FAILED;
    }

    hyperram_mode = nor->mem_type == SPI_HYPERRAM ? true : false;

    struct xspi_pdata *xspi = nor->host->priv_data;

    xspi_cache_flush(nor, addr, size);

    if (addr < xspi->direct_range_size && XSPI_USE_DIRECT_MODE && hyperram_mode && !nor->async_mode) {
        /* direct access */
        mini_memcpy_s((uint8 *)xspi->direct_base + addr, buf, size);
        arch_clean_invalidate_cache_range((uint32 *)(xspi->direct_base + (uint32)addr), ROUNDUP(size, 32));
        nor->xfer_info_bottom.opt_result = FLASH_OPT_COMPLETE;

        return 0;
    } else {
#ifdef CONFIG_DMA

        if (nor->xfer_mode == SPI_NOR_XFER_DMA_MODE) {
            arch_clean_cache_range((uint8 *)buf, ROUNDUP(size, 32));
        }

#endif

        while (size_tmp > 0) {
            write_size = _MIN((nor->info.page_size - addr_tmp % nor->info.page_size), size_tmp);
            spi_nor_write_enable(nor, true);

            xspi_lld_setup_xfer(nor, FLASH_OPT_WRITE, addr_tmp, (uint8 *)buf + buf_index, write_size);
            xspi_lld_proto_setup(nor, NULL, XSPI_INDIRECT_ACCESS_MODE,
                                 SPI_NOR_OPS_WRITE);

            irq_trig_level = _MIN(xspi->fifo_depth / 2u, DIV_ROUND_UP(size, 4u));
            irq_trig_level =  1u << xspi_compromise_alg(irq_trig_level);
            REG_RMW32(xspi->apb_base + XSPI_INDIRECT_WR_DMA,
                      XSPI_INDIRECT_DMA_TRIG_WML_LSB, 8u, irq_trig_level);
#ifdef CONFIG_DMA

            if (nor->xfer_mode == SPI_NOR_XFER_DMA_MODE) {
                xspi_lld_dma_enable(xspi);
                xspi_dma_config(nor, addr_tmp, (uint8 *)buf + buf_index, write_size, false, false);
                if (NULL_PTR == xspi->xspi_chan) {
                    xspi_lld_dma_disable(xspi);
                    return -1;
                }
                mask |= XSPI_INT_ST_FUC_INDIRECT_WR_DONE;
            } else {
                mask |= XSPI_INT_ST_FUC_TX_FRE_EMPTY | XSPI_INT_ST_FUC_INDIRECT_WR_DONE;
            }

#else
            mask |= XSPI_INT_ST_FUC_TX_FRE_EMPTY | XSPI_INT_ST_FUC_INDIRECT_WR_DONE;
#endif
            xspi_lld_indirect_trigger(xspi, addr_tmp, write_size, INDIRECT_WRITE_FLAG);
            xspi_lld_int_unmask(xspi, XSPI_INT_EN_FUC, mask);

            if (!nor->async_mode) {
                xspi_wait_xfer_done(nor);
#ifdef CONFIG_DMA

                if (nor->xfer_mode == SPI_NOR_XFER_DMA_MODE) {
                    xspi_lld_dma_disable(xspi);
                    dma_stop(xspi->xspi_chan);
                    dma_free_chan(xspi->xspi_chan);
                }

#endif

#ifndef CONFIG_FLS_HAL_POLLING

                /* wait for flash idle */
                do {
                    ret = spi_nor_wait_idle(nor);

                    if (ret) {
                        nor->xfer_info_bottom.opt_result = FLASH_OPT_FAILED;
                    }
                } while (s_lockstep_err != 0u);

#endif
            }

            if (FLASH_OPT_FAILED == nor->xfer_info_bottom.opt_result) {
                break;
            } else {
                addr_tmp += write_size;
                size_tmp -= write_size;
                buf_index += write_size;
            }
        }

        return nor->xfer_info_bottom.opt_result;
    }
}

static void xspi_cache_flush(struct spi_nor *nor, flash_addr_t addr,
                             flash_size_t length)
{
    struct xspi_pdata *xspi = nor->host->priv_data;

    arch_invalidate_cache_range((uint32 *)(xspi->direct_base + (uint32)addr),
                                ROUNDUP(length, CONFIG_ARCH_CACHE_LINE));
    xspi_prefetch_flush(xspi, 0);
    xspi_prefetch_flush(xspi, 1);
}

int xspi_erase(struct spi_nor *nor, flash_addr_t offset)
{
    int ret;
    flash_addr_t erase_addr = offset;

    if (nor->dev_mode == SPI_NOR_DEV_PARALLEL_MODE) {
        erase_addr = offset / 2u;
    }

    xspi_cache_flush(nor, erase_addr, nor->info.sector_size);

    struct spi_nor_cmd write_enable_cmd = {
        .opcode = 0x6u,
        .addr_bytes = 0,
        /* the write enable cmd inst_width need aline with erase cmd */
        .inst_type = SNOR_INST_LANS(nor->reg_proto),
    };

    ret = xspi_command_write(nor, &write_enable_cmd, 0, NULL, 0);

    if (ret != 0)
        return ret;

    struct spi_nor_cmd erase_cmd = {
        .opcode = (uint8)(nor->info.erase_proto[nor->info.sector_type] >> SNOR_OPCODE_PROTO_LSB),
        .addr_bytes = (uint8)nor->addr_width,
        /* the write enable cmd inst_width need aline with erase cmd */
        .inst_type = SNOR_INST_LANS(nor->reg_proto),
    };

    if (nor->dev_mode == SPI_NOR_DEV_SWITCH_MODE) {
        erase_addr -= nor->info.reg_offset;
    }
    ret = xspi_command_write(nor, &erase_cmd, erase_addr, NULL, 0);

    if (ret != 0)
        return ret;

#ifndef CONFIG_FLS_HAL_POLLING

    /* wait for flash idle */
    do {
        ret = spi_nor_wait_idle(nor);

        if (ret) {
            nor->xfer_info_bottom.opt_result = FLASH_OPT_FAILED;
        }
    } while (s_lockstep_err != 0u);

#endif

    return ret;
}

static int xspi_do_training(struct spi_nor *nor, flash_addr_t addr,
                            uint8 *buf, const uint8 *pattern,
                            flash_size_t size)
{
    int ret = 0;
    uint32 rx_delay;
    uint32 rx_delay_start = 0;
    boolean train_ok = false;
    struct xspi_pdata *xspi = nor->host->priv_data;

    for (rx_delay = 0u; rx_delay <= 0x7fu; rx_delay++) {
        xspi_lld_dll_enable(xspi, 0u, rx_delay, true);
        xspi_lld_dll_enable(xspi, 1u, rx_delay, true);
        spi_nor_read(nor, addr, buf, size);

        s_lockstep_err = xspi_readl(xspi->apb_base + XSPI_LSP_ERR_ST);

        if (s_lockstep_err != 0) {
            writel(s_lockstep_err, xspi->apb_base + XSPI_LSP_ERR_ST);
            DBG("xspi lsp error status = 0x%x\n", s_lockstep_err);
        }

        if (mini_memcmp_s(buf, pattern, (uint32)size) == 0) {
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
#ifdef SEMIDRIVE_E3_SERIES
        /* get chip version */
        uint8 chipver = Mcu_GetChipVersion();
        if (chipver == 0x00) {
            rx_delay = (rx_delay_start + rx_delay) / 2u - 4;
        } else
#endif
        {
            rx_delay = (rx_delay_start + rx_delay) / 2u;
        }
        xspi_lld_dll_enable(xspi, 0u, rx_delay, true);
        xspi_lld_dll_enable(xspi, 1u, rx_delay, true);
        DBG("xspi phy training pass!\n");
        ret = 0;
    } else {
        xspi_lld_dll_enable(xspi, 0u, 0u, false);
        xspi_lld_dll_enable(xspi, 1u, 0u, false);
        DBG("xspi phy training failed, disable dll!\n");
        ret = -1;
    }

    return ret;
}

void spi_nor_drv_main_function(struct spi_nor *nor)
{
    if (nor->xfer_mode == SPI_NOR_XFER_POLLING_MODE) {
        xspi_polling_handler(nor);
    }
}

struct spi_nor_host_ops xspi_host_ops = {
    .reg_read = xspi_command_read,
    .reg_write = xspi_command_write,
    .read = xspi_read,
    .write = xspi_write,
    .erase = xspi_erase,
    .training = xspi_do_training,
    .prepare = xspi_lock,
    .unprepare = xspi_unlock,
    .cache_flush = xspi_cache_flush,
};

static int xspi_hyper_read16(struct spi_nor *nor, flash_addr_t addr, uint16 *buf)
{
    int ret = 0;

    struct spi_nor_cmd read_cmd = {
        .opcode = 0,
        .dummy = nor->info.read_dummy,
        .addr_bytes = nor->addr_width,
        .inst_type = SNOR_INST_LANS(nor->reg_proto),
    };

   ret = xspi_command_read(nor, &read_cmd, addr * 2u, (uint8 *)buf, 2u);

    if (ret)
        return -1;

    return 0;
}

static int xspi_hyper_write16(struct spi_nor *nor, flash_addr_t addr, uint16 *buf)
{
    int ret = 0;

    struct spi_nor_cmd write_cmd = {
        .opcode = 0,
        .dummy = 0,
        .addr_bytes = nor->addr_width,
        .inst_type = SNOR_INST_LANS(nor->reg_proto),
    };

    ret = xspi_command_write(nor, &write_cmd, addr * 2u, (uint8 *)buf, 2u);

    if (ret)
        return -1;

    return 0;
}

static void xspi_hyper_set_pre_transaction(struct spi_nor *nor, boolean is_read,
        boolean is_direct, uint32 num, struct hyperbus_ca **ca_array)
{
    uint32 addr;
    uint32 data;
    addr_t ptc_addr;
    addr_t pta_base_addr;
    addr_t ptd_base_addr;
    struct hyperbus_ca *ca_ptr = *ca_array;
    struct xspi_pdata *xspi = nor->host->priv_data;

    if (nor->mem_type == SPI_HYPERBUS_MCP) {
        for (int i = 0u; i < num; i++) {
            addr = ca_ptr->addr;
            data = ca_ptr->data;
            xspi_hyper_write16(nor, addr, (uint16 *)(&data));
            ca_ptr += 1;
        }
    } else {
        if (is_read) {
            if (is_direct) {
                ptc_addr = xspi->apb_base + XSPI_DIRECT_RD_PTC;
                pta_base_addr = xspi->apb_base + XSPI_DIRECT_RD_PTA;
                ptd_base_addr = xspi->apb_base + XSPI_DIRECT_RD_PTD;
            } else {
                ptc_addr = xspi->apb_base + XSPI_INDR_RD_PTC;
                pta_base_addr = xspi->apb_base + XSPI_INDR_RD_PTA;
                ptd_base_addr = xspi->apb_base + XSPI_INDR_RD_PTD;
            }
        } else {
            if (is_direct) {
                ptc_addr = xspi->apb_base + XSPI_DIRECT_WR_PTC;
                pta_base_addr = xspi->apb_base + XSPI_DIRECT_WR_PTA;
                ptd_base_addr = xspi->apb_base + XSPI_DIRECT_WR_PTD;
            } else {
                ptc_addr = xspi->apb_base + XSPI_INDR_WR_PTC;
                pta_base_addr = xspi->apb_base + XSPI_INDR_WR_PTA;
                ptd_base_addr = xspi->apb_base + XSPI_INDR_WR_PTD;
            }
        }

        for (int i = 0u; i < num; i++) {
            addr = ca_ptr->addr;
            data = ca_ptr->data;
            xspi_writel(addr, pta_base_addr);
            xspi_writel(data, ptd_base_addr);

            pta_base_addr += 0x20;
            ptd_base_addr += 0x20;
            ca_ptr += 1;
        }

        /* set pre-tansaction num */
        xspi_writel(num << 8u, ptc_addr);
    }
}

struct hyperbus_host_ops xspi_hyperbus_ops = {
    .read16 = xspi_hyper_read16,
    .write16 = xspi_hyper_write16,
    .read = xspi_read,
    .write = xspi_write,
    .hyperram_en = xspi_lld_hyperram_enable,
    .set_pre_transaction = xspi_hyper_set_pre_transaction,
    .cache_flush = xspi_cache_flush,
};

int xspi_host_init(struct spi_nor_host *host, struct xspi_pdata *xspi,
                   struct xspi_config *config)
{
    if (!host || !xspi || !config) {
        DBG("%s: point is null\n", __FUNCTION__);
        return -1;
    }

    mini_memclr_s(host, sizeof(struct spi_nor_host));
    mini_memclr_s(xspi, sizeof(struct xspi_pdata));

    xspi->id = config->id;
    xspi->apb_base = config->apb_base;
    xspi->direct_range_size = 0x8000000;
    xspi->direct_base = config->direct_base;
    xspi->irq = config->irq;
    xspi->ref_clk_hz = config->ref_clk;

    // xspi->bus_event = osEventFlagsNew(NULL);
    // xspi->bus_mutex = osMutexNew(NULL);

    g_enable_event = 0;
    host->ref_clk_hz = config->ref_clk;
    host->priv_data = xspi;
    host->ops = &xspi_host_ops;
    host->hyper_ops = &xspi_hyperbus_ops;

    if (xspi->irq) {
        DBG("xspi irq num = %d\n", xspi->irq);
        irq_attach(xspi->irq, xspi_irq_handler, (void *)host);
        // irq_enable(xspi->irq);
    }

    if (xspi_lld_init(xspi) == NULL) {
        return -1;
    }

    return 0;
}

void spi_nor_drv_deinit(struct spi_nor *nor)
{
#ifdef SPI_NOR_DMA_ENABLE
#endif
    return;
}

#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#ifdef __cplusplus
}
#endif
