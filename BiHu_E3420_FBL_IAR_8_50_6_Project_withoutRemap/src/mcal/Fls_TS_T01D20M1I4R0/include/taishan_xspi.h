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
* @file  taishan_xspi.h
* @brief Semidrive. AUTOSAR 4.3.1 MCAL Fls plugins.
*/

#ifndef TAISHAN_XSPI_H_
#define TAISHAN_XSPI_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <spi_nor.h>
#include "taishan_xspi_drv.h"
#include "RegHelper.h"
#include "Std_Types.h"
#include <debug.h>

#define INDIRECT_READ_FLAG  (0)
#define INDIRECT_WRITE_FLAG (1)

#define XSPI_DLL_USE_OVERRIDE_MODE (1)

#undef BIT
#define BIT(nr) ((uint32)1u << (nr))

#define XSPI_NS_2_TICKS(hz, ns) (((hz) / 1000u * (ns) + 1000000u) / 1000000u)
#define XSPI_MS_2_TICKS(hz, ms) (((hz) * (ms) + 1000000u) / 1000000u)

extern volatile int g_xspi_debug;

// #define WITH_XSPI_DEBUG
#ifdef WITH_XSPI_DEBUG
#define xspi_readl(reg)                                                        \
            readl(reg);                                                        \
            if (g_xspi_debug) { \
            DBG("r(0x%x, r(0x%08x)\n", reg, readl(reg));}
#define xspi_writel(val, reg)                                                  \
            writel(val, reg);                                                          \
            if (g_xspi_debug) { \
            DBG("w(0x%x, 0x%08x), r(0x%08x)\n", reg, val,          \
                        readl(reg)); }
#else
#define xspi_writel(val, reg) writel(val, reg)
#define xspi_readl(reg)       readl(reg)
#endif

#ifndef udelay
#define udelay(x)                                      \
        {                                                  \
            volatile uint64 count = 20ull * (uint64)x; \
            while (count != 0ull)                          \
                count--;                                   \
        }
#endif

enum xspi_access_mode {
    XSPI_DIRECT_ACCESS_MODE,
    XSPI_INDIRECT_ACCESS_MODE
};

#define XSPI_C_LINE(x) ((x) << 0)
#define XSPI_C_RATE(x) ((x) << 2)
#define XSPI_C_SIZE(x) ((x) << 3)
#define XSPI_C_EN      (1u << 5)

#define XSPI_A_LINE(x) ((x) << 8)
#define XSPI_A_RATE(x) ((x) << 10)
#define XSPI_A_SIZE(x) ((x) << 11)
#define XSPI_A_EN      (1u << 13)

#define XSPI_D_LINE(x) ((x) << 24)
#define XSPI_D_RATE(x) ((x) << 26)
#define XSPI_D_EN      (1u << 27)


/* Operation timeout value */
#define XSPI_IDLE_TIMEOUT_CYCLES (10000u)

#define XSPI_MODE_CTRL (0x0u)
#define XSPI_MODE_CTRL_SW_RST BIT(31)
#define XSPI_MODE_CTRL_IDLE BIT(30)
#define XSPI_MODE_CTRL_XIP BIT(9)
#define XSPI_MODE_CTRL_RX_MODE BIT(8)

#define XSPI_DEV_SIZE (0x4u)
#define XSPI_DEV_SIZE_SIZE_LSB (8u)
#define XSPI_DEV_SIZE_SIZE_MASK (0xFu)

#define XSPI_INT_ST_FUC (0x10u)
#define XSPI_INT_ST_FUC_INDIRECT_DMA_RD_DONE BIT(10u)
#define XSPI_INT_ST_FUC_TX_FRE_EMPTY BIT(9u)
#define XSPI_INT_ST_FUC_RX_FRE_FULL BIT(8u)
#define XSPI_INT_ST_FUC_FIFO_LEVEL_TRIG (XSPI_INT_ST_FUC_RX_FRE_FULL | XSPI_INT_ST_FUC_TX_FRE_EMPTY)
#define XSPI_INT_ST_FUC_DIRECT_RD_DONE BIT(3u)
#define XSPI_INT_ST_FUC_DIRECT_WR_DONE BIT(2u)
#define XSPI_INT_ST_FUC_INDIRECT_RD_DONE BIT(1u)
#define XSPI_INT_ST_FUC_INDIRECT_WR_DONE BIT(0u)
#define XSPI_INT_ST_FUC_IND_COMP    \
         (XSPI_INT_ST_FUC_INDIRECT_DMA_RD_DONE | XSPI_INT_ST_FUC_INDIRECT_WR_DONE)


#define XSPI_INT_EN_FUC (0x14u)

#define XSPI_INT_ST_ERR (0x18u)

#define XSPI_INT_EN_ERR (0x1Cu)

#define XSPI_INT_EN_ERR_FUC (0x20u)

#define XSPI_DATA_INIEGRITY (0x30u)

#define XSPI_IO_FMUX1 (0x40u)

#define XSPI_IO_FMUX2 (0x44u)

#define XSPI_IO1_FMUX1 (0x48u)

#define XSPI_IO1_FMUX2 (0x4Cu)

#define XSPI_IO_CTRL (0x60u)

#define XSPI_ADDR_OFFSET (0x70u)

#define XSPI_MISC (0x80u)
#define XSPI_MISC_INDIRECT_AXI_RD_EN BIT(11u)
#define XSPI_MISC_INDIRECT_AXI_WR_EN BIT(10u)

#define XSPI_AXI_CTRL (0x84u)

#define XSPI_SCLK_CTRL (0xC0u)
#define XSPI_SCLK_CTRL_RX_SEL_MASK (3u)
#define XSPI_SCLK_CTRL_RX_SEL_LSB (2u)

#define XSPI_CS_CTRL (0xC4u)
#define XSPI_CS_CTRL_SEL_MASK (0xFu)
#define XSPI_CS_CTRL_HW_SEL_MASK (0x3u)
#define XSPI_CS_CTRL_HW_SEL_DEV1 (0x2u)
#define XSPI_CS_CTRL_HW_SEL_DEV2 (0x1u)
#define XSPI_CS_CTRL_HW_SEL_AUTO (0x3u)
#define XSPI_CS_CTRL_HW_SEL_LSB (27u)
#define XSPI_CS_CTRL_SW_SEL_MASK (0x3u)
#define XSPI_CS_CTRL_SW_SEL_DEV1 (0x2u)
#define XSPI_CS_CTRL_SW_SEL_DEV2 (0x1u
#define XSPI_CS_CTRL_SW_SEL_LSB (25u)
#define XSPI_CS_CTRL_SW BIT(24)
#define XSPI_CS_CTRL_TIME_DELAY_MASK (0xFu)
#define XSPI_CS_CTRL_TIME_SHSL_DELAY_MASK (0x1Fu)
#define XSPI_CS_CTRL_TSLCH_LSB (16u)
#define XSPI_CS_CTRL_TSHSL_LSB (8u)
#define XSPI_CS_CTRL_TCHSH_LSB (0u)

#define XSPI_HYPERBUS_CTRL (0xD0u)

#define XSPI_DLL_CTRL (0xE0u)

#define XSPI_STATUS (0xE4u)

#define XSPI_DLL1_CTRL (0xE8u)

#define XSPI_DLL1_STATUS (0xECu)

#define XSPI_DIRECT_RD_PH_CTRL (0x100u)
#define XSPI_DIRECT_WR_PH_CTRL (0x104u)
#define XSPI_DIRECT_DATA_DDR_RATE BIT(26)
#define XSPI_DIRECT_DATA_LINE_MASK (0x3u)
#define XSPI_DIRECT_DATA_LINE_LSB (24u)
#define XSPI_DIRECT_MODE_EN BIT(21)
#define XSPI_DIRECT_MODE_SIZE_MASK (0x3u)
#define XSPI_DIRECT_MODE_SIZE_LSB (19u)
#define XSPI_DIRECT_MODE_DDR_RATE BIT(18)
#define XSPI_DIRECT_MODE_LINE_MASK (0x3u)
#define XSPI_DIRECT_MODE_LINE_LSB (16u)
#define XSPI_DIRECT_ADDR_SIZE_MASK (0x3u)
#define XSPI_DIRECT_ADDR_SIZE_LSB (11u)
#define XSPI_DIRECT_ADDR_DDR_RATE BIT(10)
#define XSPI_DIRECT_ADDR_LINE_MASK (0x3u)
#define XSPI_DIRECT_ADDR_LINE_LSB (8u)
#define XSPI_DIRECT_CMD_EN BIT(5)
#define XSPI_DIRECT_CMD_SIZE_MASK (0x3u)
#define XSPI_DIRECT_CMD_SIZE_LSB (3u)
#define XSPI_DIRECT_CMD_DDR_RATE BIT(2)
#define XSPI_DIRECT_CMD_LINE_MASK (0x3u)
#define XSPI_DIRECT_CMD_LINE_LSB (0u)

#define XSPI_DIRECT_C_CODE (0x114u)

#define XSPI_DIRECT_WREN (0x118u)

#define XSPI_DIRECT_M_CODE (0x11Cu)

#define XSPI_DIRECT_D_CYC (0x120u)
#define XSPI_DIRECT_D_CYC_RD_LSB (0u)
#define XSPI_DIRECT_D_CYC_RD_MASK (0x1Fu)
#define XSPI_DIRECT_D_CYC_WR_LSB (8u)
#define XSPI_DIRECT_D_CYC_WR_MASK (0x1Fu)

#define XSPI_INDIRECT_WR_CTRL (0x200u)

#define XSPI_INDIRECT_WR_PH_CTRL (0x204u)
#define XSPI_INDIRECT_RD_PH_CTRL (0x304u)
#define XSPI_INDIRECT_DATA_EN BIT(27)
#define XSPI_INDIRECT_DATA_DDR_RATE BIT(26)
#define XSPI_INDIRECT_DATA_LINE_MASK (0x3u)
#define XSPI_INDIRECT_DATA_LINE_LSB (24u)
#define XSPI_INDIRECT_ADDR_EN BIT(13)
#define XSPI_INDIRECT_ADDR_SIZE_MASK (0x3u)
#define XSPI_INDIRECT_ADDR_SIZE_LSB (11u)
#define XSPI_INDIRECT_ADDR_DDR_RATE BIT(10)
#define XSPI_INDIRECT_ADDR_LINE_MASK (0x3u)
#define XSPI_INDIRECT_ADDR_LINE_LSB (8u)
#define XSPI_INDIRECT_CMD_EN BIT(5)
#define XSPI_INDIRECT_CMD_SIZE_2_BYTES BIT(3u)
#define XSPI_INDIRECT_CMD_DDR_RATE BIT(2)
#define XSPI_INDIRECT_CMD_LINE_MASK (0x3u)
#define XSPI_INDIRECT_CMD_LINE_LSB (0u)

#define XSPI_INDIRECT_WR_CMD_CODE (0x208u)

#define XSPI_INDIRECT_WR_ADDR (0x20Cu)

#define XSPI_INDIRECT_WR_SIZE (0x210u)

#define XSPI_INDIRECT_WR_CYC (0x214u)

#define XSPI_INDIRECT_WR_DMA (0x220u)
#define XSPI_INDIRECT_RD_DMA (0x320u)
#define XSPI_INDIRECT_DMA_TRIG_WML_MASK (0x1Fu)
#define XSPI_INDIRECT_DMA_TRIG_WML_LSB (8u)
#define XSPI_INDIRECT_DMA_SW_ACK BIT(2)
#define XSPI_INDIRECT_DMA_SINGLE_EN BIT(1)
#define XSPI_INDIRECT_DMA_REQ_EN BIT(0)

#define XSPI_INDIRECT_TX_BUF (0x240u)
#define XSPI_INDIRECT_TX_BUF_ENTRY_MASK (0xFFu)
#define XSPI_INDIRECT_TX_BUF_ENTRY_LSB (16)
#define XSPI_INDIRECT_TX_BUF_LEVEL_MASK (0xFFu)
#define XSPI_INDIRECT_TX_BUF_LEVEL_LSB (8)


#define XSPI_INDIRECT_WDATA (0x280u)

#define XSPI_INDIRECT_RD_CTRL (0x300u)

#define XSPI_INDIRECT_RD_CMD_CODE (0x308u)

#define XSPI_INDIRECT_RD_ADDR (0x30Cu)

#define XSPI_INDIRECT_RD_SIZE (0x310u)

#define XSPI_INDIRECT_RD_CYC (0x314u)

#define XSPI_INDIRECT_RD_M_CODE (0x318u)

#define XSPI_INDIRECT_P_VALUE (0x330u)

#define XSPI_INDIRECT_P_MASK (0x334u)

#define XSPI_INDIRECT_P_TIME (0x338u)

#define XSPI_INDIRECT_RX_BUF (0x340u)
#define XSPI_INDIRECT_RX_BUF_ENTRY_MASK (0xFFu)
#define XSPI_INDIRECT_RX_BUF_ENTRY_LSB (16)
#define XSPI_INDIRECT_RX_BUF_LEVEL_MASK (0xFFu)
#define XSPI_INDIRECT_RX_BUF_LEVEL_LSB (8)

#define XSPI_INDIRECT_RDATA (0x380u)

#define XSPI_RBUF_HIT_CNTR (0x390u)

#define XSPI_RBUF_MISS_CNTR (0x394u)

#define XSPI_GROUP_MERGE (0x3A0u)

#define XSPI_RBUF_CTRL (0x400u)

#define XSPI_GID_MASK (0x404u)

#define XSPI_GID_MATCH (0x408u)

#define XSPI_IMG_REGION_START (0x500u)

#define XSPI_IMG_REGION_END_ADDR (0x504u)

#define XSPI_IMG_REGION_CTRL (0x508u)

#define XSPI_IMG_REGION_NONCE0 (0x510u)

#define XSPI_IMG_REGION_NONCE1 (0x514u)

#define XSPI_IMG_REGION_NONCE2 (0x518u)

#define XSPI_IMG_REGION_NONCE3 (0x51Cu)

#define XSPI_IMG_RFD (0x590u)

#define XSPI_MON_OP_TIME (0x600u)

#define XSPI_CMD_MON_CTRL (0x610u)

#define XSPI_MON_REGION_START_ADDR (0x614u)

#define XSPI_MON_REGION_END_ADDR (0x618u)

#define XSPI_MON_CMD_VALUE (0x654u)

#define XSPI_MS_CTRL (0x800u)

#define XSPI_MS_WAIT_TIME (0x810u)

#define XSPI_MS_TIMEOUT (0x81Cu)

#define XSPI_MS_INT_ST (0x820u)

#define XSPI_MS_INT_EN (0x828u)

#define XSPI_INDR_WR_PTC (0x900u)

#define XSPI_INDR_RD_PTC (0x904u)

#define XSPI_DIRECT_WR_PTC (0x908u)

#define XSPI_DIRECT_RD_PTC (0x90Cu)

#define XSPI_INDR_WR_PTA (0x920u)

#define XSPI_INDR_WR_PTD (0x924u)

#define XSPI_INDR_RD_PTA (0x928u)

#define XSPI_INDR_RD_PTD (0x92Cu)

#define XSPI_DIRECT_WR_PTA (0x930)

#define XSPI_DIRECT_WR_PTD (0x934)

#define XSPI_DIRECT_RD_PTA (0x938)

#define XSPI_DIRECT_RD_PTD (0x93C)

#define XSPI_ERR_INJ_EN (0xC00)

#define XSPI_INJ_DATA (0xC04)

#define XSPI_INJ_CODE (0xC08)

#define XSPI_FATAL_ERR_ST (0xC20)

#define XSPI_FATAL_ERR_EN (0xC28)

#define XSPI_CORE_ERR_ST (0xC30)

#define XSPI_AXI_UNC_ERR_ST (0xC34)

#define XSPI_APB_UNC_ERR_ST (0xC38)

#define XSPI_DMA_ERR_ST (0xC3C)

#define XSPI_COR_ERR_EN (0xC50)

#define XSPI_AXI_UNC_ERR_EN (0xC54)

#define XSPI_APB_UNC_ERR_EN (0xC58)

#define XSPI_DMA_ERR_EN (0xC5C)

#define XSPI_CTRL_ERR_ST (0xC60)

#define XSPI_CTRL_ERR_EN (0xC68)

#define XSPI_LSP_ERR_INJ_EN (0x1000)

#define XSPI_LSP_CMP_ERR_INJ (0x1004)

#define XSPI_LSP_ERR_ST (0x1010)

#define XSPI_LSP_ERR_EN (0x1014)

static inline void xspi_lld_indr_pre_trans_clean(struct spi_nor *nor)
{
    struct xspi_pdata *xspi = nor->host->priv_data;

    /* Config indirect read pre-transaction to 0 */
    xspi_writel(0, xspi->apb_base + XSPI_INDR_RD_PTC);

    /* Config direct write pre-transaction to 0 */
    xspi_writel(0, xspi->apb_base + XSPI_INDR_WR_PTC);
}

void *xspi_lld_init(struct xspi_pdata *xspi);
void xspi_lld_nor_setup(struct spi_nor *nor, enum spi_nor_ops ops);
void xspi_lld_proto_setup(struct spi_nor *nor, struct spi_nor_cmd *cmd,
                          enum xspi_access_mode access_mode,
                          enum spi_nor_ops ops);
void xspi_lld_int_unmask(struct xspi_pdata *xspi, addr_t addr, uint32 mask);
void xspi_lld_indirect_trigger(const struct xspi_pdata *xspi, uint32 addr,
                               uint32 size, int flag);
void xspi_lld_setup_xfer(struct spi_nor *nor, enum flash_opt opt,
                         flash_addr_t addr, uint8 *buf, flash_size_t size);
void xspi_lld_release_xfer(struct spi_nor *nor);
uint32 xspi_lld_write_fifo(struct xspi_pdata *xspi, const uint8 *buf,
                           flash_size_t size);
int xspi_lld_rx_polling(struct spi_nor *nor);
int xspi_lld_tx_polling(struct spi_nor *nor);
void xspi_lld_dma_enable(struct xspi_pdata *xspi);
void xspi_lld_dma_disable(struct xspi_pdata *xspi);
void xspi_lld_dll_enable(struct xspi_pdata *xspi, int dll_num, int value,
                         bool enable);
void xspi_lld_hyperram_enable(struct spi_nor *nor, uint8 cs,
                              uint8 read_dummy, uint8 write_dummy);
void xspi_prefetch_flush(struct xspi_pdata *xspi, uint32 channel);
int xspi_direct_access_training(addr_t apb_base, uint8 *addr,
                                uint8 *buf, const uint8 *pattern,
                                flash_size_t size);

#ifdef __cplusplus
}
#endif
#endif /* SDRV_XSPI_H_ */
