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
 * @file  dwmac.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Eth plugins.
 */

#ifndef DWMAC_H
#define DWMAC_H

#ifdef __cplusplus
extern "C" {
#endif
#include "Mcal.h"
#include "Eth_PBCfg.h"

#define MAC_INT_FLG_RXSTSIS     BIT(14)
#define MAC_INT_FLG_TXSTSIS     BIT(13)
#define MAC_INT_FLG_TSIS        BIT(12)

#define MAC_INT_EN_RXSTSIS      BIT(14)
#define MAC_INT_EN_TXSTSIS      BIT(13)
#define MAC_INT_EN_TSIS         BIT(12)


#define MAC_RX_STATUS_RWT       BIT(8)
#define MAC_TX_STATUS_EXCOL     BIT(5)
#define MAC_TX_STATUS_LCOL      BIT(4)
#define MAC_TX_STATUS_EXDEF     BIT(3)
#define MAC_TX_STATUS_TJT       BIT(0)


#define ETH_PHY_INTF_SEL_MII        0
#define ETH_PHY_INTF_SEL_RGMII      1
#define ETH_PHY_INTF_SEL_RMII       4


#define DEFAULT_BUFSIZE 1536u
#define BUFF_SIZE_16KB 16368u
#define BUFF_SIZE_8KB 8188u
#define BUFF_SIZE_4KB 4096u
#define BUFF_SIZE_2KB 2048u


#if defined(SEMIDRIVE_E3_SERIES) || defined(SEMIDRIVE_E3_LITE_SERIES)
#define DESC_SKIP_SIZE      (2u)
#else
#define DESC_SKIP_SIZE      (1u)
#endif

enum mac_dma_ch_e {
    DMA_CH_0 = 0,
    DMA_CH_1,
    DMA_CH_2,
    DMA_CH_3,
    DMA_CH_4,
    DMA_CH_MAX
};

ISR(eth0_handle);
#if (ETH_MAXCTRLS_SUPPORTED == 2U)
ISR(eth1_handle);
#endif
uint32 rx_indication(uint8 CtrlIdx, uint8 Channel);
void tx_indication(uint8 CtrlIdx, uint8 Channel, boolean irq);
void select_eth_mii_type(uint32 eth_instance, uint32 type);

#ifdef __cplusplus
}
#endif

#endif

