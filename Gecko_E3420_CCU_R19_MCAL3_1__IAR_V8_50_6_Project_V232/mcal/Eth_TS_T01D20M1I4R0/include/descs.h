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
 * @file  desc.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Eth plugins.
 */

#ifndef DESCS_H
#define DESCS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "RegHelper.h"


/* TDES2 (read format) */
#define TDES2_BUFFER1_SIZE_MASK     GENMASK(13, 0)
#define TDES2_VLAN_TAG_MASK     GENMASK(15, 14)
#define TDES2_BUFFER2_SIZE_MASK     GENMASK(29, 16)
#define TDES2_BUFFER2_SIZE_MASK_SHIFT   16
#define TDES2_TIMESTAMP_ENABLE      BIT(30)
#define TDES2_INTERRUPT_ON_COMPLETION   BIT(31)

/* TDES3 (read format) */
#define TDES3_PACKET_SIZE_MASK      GENMASK(14, 0)
#define TDES3_CHECKSUM_INSERTION_MASK   GENMASK(17, 16)
#define TDES3_CHECKSUM_INSERTION_SHIFT  16
#define TDES3_TCP_PKT_PAYLOAD_MASK  GENMASK(17, 0)
#define TDES3_TCP_SEGMENTATION_ENABLE   BIT(18)
#define TDES3_HDR_LEN_SHIFT     19
#define TDES3_SLOT_NUMBER_MASK      GENMASK(22, 19)
#define TDES3_SA_INSERT_CTRL_MASK   GENMASK(25, 23)
#define TDES3_CRC_PAD_CTRL_MASK     GENMASK(27, 26)

/* TDES3 (write back format) */
#define TDES3_IP_HDR_ERROR      BIT(0)
#define TDES3_DEFERRED          BIT(1)
#define TDES3_UNDERFLOW_ERROR       BIT(2)
#define TDES3_EXCESSIVE_DEFERRAL    BIT(3)
#define TDES3_COLLISION_COUNT_MASK  GENMASK(7, 4)
#define TDES3_COLLISION_COUNT_SHIFT 4
#define TDES3_EXCESSIVE_COLLISION   BIT(8)
#define TDES3_LATE_COLLISION        BIT(9)
#define TDES3_NO_CARRIER        BIT(10)
#define TDES3_LOSS_CARRIER      BIT(11)
#define TDES3_PAYLOAD_ERROR     BIT(12)
#define TDES3_PACKET_FLUSHED        BIT(13)
#define TDES3_JABBER_TIMEOUT        BIT(14)
#define TDES3_ERROR_SUMMARY     BIT(15)
#define TDES3_TIMESTAMP_STATUS      BIT(17)
#define TDES3_TIMESTAMP_STATUS_SHIFT    17

/* TDES3 context */
#define TDES3_CTXT_TCMSSV       BIT(26)

/* TDES3 Common */
#define TDES3_RS1V          BIT(26)
#define TDES3_RS1V_SHIFT        26
#define TDES3_LAST_DESCRIPTOR       BIT(28)
#define TDES3_LAST_DESCRIPTOR_SHIFT 28
#define TDES3_FIRST_DESCRIPTOR      BIT(29)
#define TDES3_CONTEXT_TYPE      BIT(30)
#define TDES3_CONTEXT_TYPE_SHIFT    30

/* TDS3 use for both format (read and write back) */
#define TDES3_OWN           BIT(31)
#define TDES3_OWN_SHIFT         31

/* Normal receive descriptor defines (without split feature) */

/* RDES0 (write back format) */
#define RDES0_VLAN_TAG_MASK     GENMASK(15, 0)

/* RDES1 (write back format) */
#define RDES1_IP_PAYLOAD_TYPE_MASK  GENMASK(2, 0)
#define RDES1_IP_HDR_ERROR      BIT(3)
#define RDES1_IPV4_HEADER       BIT(4)
#define RDES1_IPV6_HEADER       BIT(5)
#define RDES1_IP_CSUM_BYPASSED      BIT(6)
#define RDES1_IP_CSUM_ERROR     BIT(7)
#define RDES1_PTP_MSG_TYPE_MASK     GENMASK(11, 8)
#define RDES1_PTP_PACKET_TYPE       BIT(12)
#define RDES1_PTP_VER           BIT(13)
#define RDES1_TIMESTAMP_AVAILABLE   BIT(14)
#define RDES1_TIMESTAMP_AVAILABLE_SHIFT 14
#define RDES1_TIMESTAMP_DROPPED     BIT(15)
#define RDES1_IP_TYPE1_CSUM_MASK    GENMASK(31, 16)

/* RDES2 (write back format) */
#define RDES2_L3_L4_HEADER_SIZE_MASK    GENMASK(9, 0)
#define RDES2_VLAN_FILTER_STATUS    BIT(15)
#define RDES2_SA_FILTER_FAIL        BIT(16)
#define RDES2_DA_FILTER_FAIL        BIT(17)
#define RDES2_HASH_FILTER_STATUS    BIT(18)
#define RDES2_MAC_ADDR_MATCH_MASK   GENMASK(26, 19)
#define RDES2_HASH_VALUE_MATCH_MASK GENMASK(26, 19)
#define RDES2_L3_FILTER_MATCH       BIT(27)
#define RDES2_L4_FILTER_MATCH       BIT(28)
#define RDES2_L3_L4_FILT_NB_MATCH_MASK  GENMASK(27, 26)
#define RDES2_L3_L4_FILT_NB_MATCH_SHIFT 26

/* RDES3 (write back format) */
#define RDES3_PACKET_SIZE_MASK      GENMASK(14, 0)
#define RDES3_ERROR_SUMMARY     BIT(15)
#define RDES3_PACKET_LEN_TYPE_MASK  GENMASK(18, 16)
#define RDES3_DRIBBLE_ERROR     BIT(19)
#define RDES3_RECEIVE_ERROR     BIT(20)
#define RDES3_OVERFLOW_ERROR        BIT(21)
#define RDES3_RECEIVE_WATCHDOG      BIT(22)
#define RDES3_GIANT_PACKET      BIT(23)
#define RDES3_CRC_ERROR         BIT(24)
#define RDES3_RDES0_VALID       BIT(25)
#define RDES3_RDES1_VALID       BIT(26)
#define RDES3_RDES2_VALID       BIT(27)
#define RDES3_LAST_DESCRIPTOR       BIT(28)
#define RDES3_FIRST_DESCRIPTOR      BIT(29)
#define RDES3_CONTEXT_DESCRIPTOR    BIT(30)
#define RDES3_CONTEXT_DESCRIPTOR_SHIFT  30

/* RDES3 (read format) */
#define RDES3_BUFFER1_VALID_ADDR    BIT(24)
#define RDES3_BUFFER2_VALID_ADDR    BIT(25)
#define RDES3_INT_ON_COMPLETION_EN  BIT(30)

/* TDS3 use for both format (read and write back) */
#define RDES3_OWN           BIT(31)
/* Basic descriptor structure for normal and alternate descriptors */

struct dma_desc {
    uint32 des0;
    uint32 des1;
    uint32 des2;
    uint32 des3;
    uint32 des4;
    uint32 des5;
    uint32 des6;
    uint32 des7;
} __attribute__((aligned(32)));

/* Transmit checksum insertion control */
#define TX_CIC_FULL 3   /* Include IP header and pseudoheader */


/* source address replace enable without source addr */
#define TX_SAIC_REPLACE 2
#define TDES3_TX_SAIC_REPLACE_SAIFT 23


#define TDES3_SA_REPLACE_DESCRIPTOR (TDES3_SA_INSERT_CTRL_MASK & \
        (TX_SAIC_REPLACE << TDES3_TX_SAIC_REPLACE_SAIFT));

/* crc and pad insert automaticaly by mac */
#define TX_CPC_CRC_PAD_INSER    0
/* only crc  insert automaticaly by mac */
#define TX_CPC_CRC_INSER    1
/* only pad  insert automaticaly by mac */
#define TX_CPC_PAD_INSER    2
/* crc and pad insert by software, mac only repace crc*/
#define TX_CPC_CRC_REPLACE  3

#define TDES3_TX_CPC_REPLACE_SAIFT  26


#define TDES3_CRC_PAD_INSER_DESCRIPTOR \
(TX_CPC_CRC_PAD_INSER<<TDES3_TX_CPC_REPLACE_SAIFT)
#define TDES3_CRC_INSER_DESCRIPTOR \
(TX_CPC_CRC_INSER<<TDES3_TX_CPC_REPLACE_SAIFT)
#define TDES3_PAD_INSER_DESCRIPTOR \
(TX_CPC_PAD_INSER<<TDES3_TX_CPC_REPLACE_SAIFT)
#define TDES3_CRC_REPLACE_DESCRIPTOR \
(TX_CPC_CRC_REPLACE<<TDES3_TX_CPC_REPLACE_SAIFT)




#define DESC_FLAGS_TX_FIRST     BIT(0)
#define DESC_FLAGS_TX_CHK_SHIFT     BIT(1)
#define DESC_FLAGS_TX_LAST     BIT(2)
#define DESC_FLAGS_TX_OWN     BIT(3)
#define DESC_FLAGS_TX_CPC_CRC_PAD_INSER   BIT(4)
#define DESC_FLAGS_TX_CPC_CRC_INSER         BIT(5)
#define DESC_FLAGS_TX_CPC_PAD_INSER     BIT(6)
#define DESC_FLAGS_TX_CPC_CRC_REPLA     BIT(7)
#define DESC_FLAGS_TX_SAIC_REPLA     BIT(8)
#define DESC_FLAGS_IC               BIT(9)
#define DESC_FLAGS_TIMESTAMP        BIT(10)

sint32 dwmac_wrback_get_rx_status(struct dma_desc *p);

sint32 dwmac_wrback_get_tx_status(struct dma_desc *p);

sint32 dwmac_rd_get_tx_len(struct dma_desc *p);

void dwmac_set_rx_owner(struct dma_desc *p, uint32 disable_rx_ic);

sint32 dwmac_wrback_get_rx_frame_len(struct dma_desc *p);

void dwmac_rd_enable_tx_timestamp(struct dma_desc *p);

sint32 dwmac_wrback_get_tx_timestamp_status(struct dma_desc *p);

uint32 dwmac_wrback_get_rx_timestamp_status(struct dma_desc *desc, struct dma_desc *next_desc);

void dwmac_rd_init_rx_desc(struct dma_desc *p, uint32 disable_rx_ic);

void dwmac_rd_init_tx_desc(struct dma_desc *p);

void dwmac_rd_prepare_tx_desc(struct dma_desc *p, uint32 len, \
                              uint32 tot_pkt_len, uint32 flags);

void dwmac_rd_set_tx_ic(struct dma_desc *p);

void dwmac_set_addr(struct dma_desc *p, uint32 *addr);

void dwmac_clear(struct dma_desc *p);

#ifdef __cplusplus
}
#endif

#endif

