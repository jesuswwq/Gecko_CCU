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
* @file  taishan_xspi_drv.h
* @brief Semidrive. AUTOSAR 4.3.1 MCAL Fls plugins.
*/

#ifndef TAISHAN_XSPI_DRV_H_
#define TAISHAN_XSPI_DRV_H_

#ifdef __cplusplus
extern "C" {
#endif
#if defined(CFG_DMA_SUPPORT_STATIC_ALLOCATION)
#include <Dma.h>
#else
#include "dma.h"
#include "dma_cfg.h"
#include "sdrv_dmac.h"
#endif
#include "spi_nor.h"

#define CONFIG_DMA (1)

enum xspi_xfer_mode {
    XSPI_XFER_NONE = 0,
    XSPI_XFER_READ,
    XSPI_XFER_WRITE,
};

struct xspi_config {
    uint8 id;
    uint32 apb_base;
    uint32 direct_base;
    unsigned int irq;
    unsigned long ref_clk;
    clk_node_t *clk;
};

struct xspi_pdata {
    uint8 id;
    uint32 apb_base;
    uint32 direct_base;
    unsigned int irq;
    unsigned long ref_clk_hz;

    unsigned int sclk;
    uint8 dma_bus_width;
    uint32 dma_burst_size;
    bool cs_decoded;
    uint8 current_cs;
    bool dqs_en;
    uint8 fifo_depth;
    uint8 fifo_width;
    uint32 direct_range_size;
#ifdef CONFIG_DMA
    dma_chan_t *xspi_chan;
#endif
};


int xspi_host_init(struct spi_nor_host *host, struct xspi_pdata *xspi,
                   struct xspi_config *config);

int board_norflash_init(struct spi_nor_host *host, const struct spi_nor_config *config);

#if defined(NON_AUTOSAR_STANDARD_IRQ_HANDLER)
int xspi_irq_handler(uint32 irq, void *arg);
#else
void xspi_irq_handler(void);
#endif

#ifdef __cplusplus
}
#endif
#endif /* TAISHAN_XSPI_DRV_H_ */

