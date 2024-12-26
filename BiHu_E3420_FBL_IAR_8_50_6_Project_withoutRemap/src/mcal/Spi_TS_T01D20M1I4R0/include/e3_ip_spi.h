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
 * @file  e3_ip_spi.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Spi plugins.
 */

#ifndef SPI_IP_H_
#define SPI_IP_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "mld_spi.h"


#define  SPI_PIPE_LINE_SIZE_8B 3U
#define  SPI_PIPE_LINE_SIZE_4B 4U
#define  SPI_PIPE_LINE_SIZE_2B 5U
#define  SPI_PIPE_LINE_SIZE_OB 2U

#define  SPI_DATA_WIDTH_MIN 4U
#define  SPI_DATA_WIDTH_MAX 32U
#define  SPI_FREAM_SIZE_MAX 1024U
#define  SPI_CLK_PRESSCALE_MAX 0xFFU
#define  SPI_IDLE_COUNT_MAX 0x1FU
#define  SPI_TIMEOUT_COUNT_MAX 0x1FU
#define  SPI_POL_VEL_MAX 0xFU
//2 mst_idle 3 mst_start  7 mst_data wait
#define  SPI_FSM_WAIT_DATA_STA 7U
#define  SPI_FSM_M_STR_STA 3U
#define  SPI_FSM_IDLE_STA 2U
#define  SPI_BAUD_RATE_MAX  660000000U
#define  SPI_FIFO_LEN       16U
#define  TIMEOUT_WAIT_MST_END   (1000*SPI_FIFO_LEN)

#ifndef ROUNDUP
#define ROUNDUP(a, b) (((a) + ((b)-1)) & ~((b)-1))
#endif
#ifndef ROUNDDOWN
#define ROUNDDOWN(a, b) ((a) & ~((b)-1))
#endif

enum dev_flags {
    F_DEV_LSB  = 0x01U,
    F_DEV_SWAP = 0x02U,
    F_DEV_NSS_HIGH = 0x04U,
    F_DEV_NSS_SOFT = 0x08U,
    F_DEV_MISO_DELAY = 0x10U
};

enum bus_flags {
    SPI_SSP_MODE_ENABLE = (0x01 << 0U),
    SPI_DMA_RX_ENABLE = (0x01 << 1U),
    SPI_DMA_TX_ENABLE = (0x01 << 2U),
    SPI_MODE_SLAVE_ENABLE = (0x01 << 3U),
    SPI_HALF_DUPLEX_ENABLE = (0x01 << 4U),
    SPI_SIMP_DELAY_ENABLE = (0x01 << 5U),
    SPI_TX_IRQ_ENABLE = (0x01 << 6U),
    SPI_RX_IRQ_ENABLE = (0x01 << 7U),
    SPI_SLV_IRQ_ENABLE = (0x01 << 8U),
};

struct spi_dev_priv {
    enum spi_tim_mode  mode;
    uint32           flags;
    uint32           tim_ctrl;
    uint16           baud_div;
    uint8            width;
    uint8            nss_idx;
};

struct spi_bus_priv {
    uint32                    idle;
    uint32                    slave_nss_p;
    uint32                    timeout;
    uint32                    flags;
    void                       *dma;
    void                       *dma_ch_rx;
    void                       *dma_ch_tx;
    uint32                    dma_err;
};


static inline void spi_ndelay(uint32 loop)
{
    volatile uint32 i;

    for (i = 0; i <= loop; i++) {

    }
}
static inline void filling_async_cb(struct mld_spi_device *dev, uint32 *ptxdata, \
                                    uint32 *prxdata, uint32 size, struct mld_spi_async *async)
{
    async->prxdata.val = (uint32)prxdata;
    async->ptxdata.val = (uint32)ptxdata;
    async->width_type = SPI_DATA_WIDTH_WORD;
    async->next = NULL;
    async->len = size;
    async->priv = (void *)dev;
    async->cur_remian = size;
    async->expect_len = 0;
}

extern const struct mld_spi_ops semidrive_spi_bus_ops;

#ifdef __cplusplus
}
#endif

#endif
