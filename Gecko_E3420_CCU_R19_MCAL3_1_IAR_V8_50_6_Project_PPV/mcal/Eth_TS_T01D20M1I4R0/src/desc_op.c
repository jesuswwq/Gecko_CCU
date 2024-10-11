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
 * @file  desc_op.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Eth plugins.
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "arch.h"
#include "descs.h"
#include "dwmac_common.h"

#define  ETH_DEBUG(...)

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"

sint32 dwmac_wrback_get_tx_status(struct dma_desc *p)
{

    uint32 tdes3;
    sint32 ret = TX_GOOD;

    tdes3 = (p->des3);

    /* Get tx owner first */
    if ((tdes3 & TDES3_OWN))
        return TX_DMA_PROCESS;

    /* Verify tx error by looking at the last segment. */
    if ((!(tdes3 & TDES3_LAST_DESCRIPTOR)))
        return TX_NOT_LS;

    if ((tdes3 & TDES3_ERROR_SUMMARY)) {
        if ((tdes3 & TDES3_JABBER_TIMEOUT)) {
            /* tx_jabber */
        }

        if ((tdes3 & TDES3_PACKET_FLUSHED)) {
            /* tx_frame_flushed */
        }

        if ((tdes3 & TDES3_LOSS_CARRIER)) {
            /* tx_losscarrier and tx_carrier_errors */
        }

        if ((tdes3 & TDES3_NO_CARRIER)) {
            /* tx_carrier tx_carrier_errors */
        }

        if (((tdes3 & TDES3_LATE_COLLISION) ||
             (tdes3 & TDES3_EXCESSIVE_COLLISION))) {
            /*
                stats->collisions +=
                (tdes3 & TDES3_COLLISION_COUNT_MASK) >> TDES3_COLLISION_COUNT_SHIFT;
            */
        }

        if ((tdes3 & TDES3_EXCESSIVE_DEFERRAL)) {
            /* tx_deferred */
        }

        if ((tdes3 & TDES3_UNDERFLOW_ERROR)) {
            /* tx_underflow */
        }

        if ((tdes3 & TDES3_IP_HDR_ERROR)) {
            /* tx_ip_header_error */
        }

        if ((tdes3 & TDES3_PAYLOAD_ERROR)) {
            /* tx_payload_error */
        }

        ret = TX_ERROR;
    }

    if ((tdes3 & TDES3_DEFERRED)) {
        /*
            only half-duplex mode ,the MAC deferred before
            transmitting because of presence of carrier
        */
    }

    return ret;
}

sint32 dwmac_wrback_get_rx_status(struct dma_desc *p)
{

    uint32 rdes1 = (p->des1);
    uint32 rdes2 = (p->des2);
    uint32 rdes3 = (p->des3);
    sint32 message_type;
    sint32 ret = RX_GOOD;

    if ((rdes3 & RDES3_OWN)) {
        return RX_DMA_PROCESS;
    }

    /* Verify rx error by looking at the last segment. */
    if ((!(rdes3 & RDES3_LAST_DESCRIPTOR))) {
        return RX_BAD;
    }

    if ((rdes3 & RDES3_ERROR_SUMMARY)) {
        if ((rdes3 & RDES3_GIANT_PACKET)) {
            /* rx_length_errors */
        }

        if ((rdes3 & RDES3_OVERFLOW_ERROR)) {
            /* rx_gmac_overflow */
        }

        if ((rdes3 & RDES3_RECEIVE_WATCHDOG)) {
            /* rx_watchdog */
        }

        if ((rdes3 & RDES3_RECEIVE_ERROR)) {
            /* rx_mii reveive error */
        }

        if ((rdes3 & RDES3_CRC_ERROR)) {
            /* crc error */
        }

        if ((rdes3 & RDES3_DRIBBLE_ERROR)) {
            /* dribbling_bit */
        }

        ret = RX_BAD;
    }

    message_type = (rdes1 & ERDES4_MSG_TYPE_MASK) >> 8;

    if (rdes1 & RDES1_IP_HDR_ERROR) {
        /* ip_hdr_err */
    }

    if (rdes1 & RDES1_IP_CSUM_BYPASSED) {
        /* ip_csum_bypassed */
    }

    if (rdes1 & RDES1_IPV4_HEADER) {
        /* ipv4_pkt_rcvd */
    }

    if (rdes1 & RDES1_IPV6_HEADER) {
        /* ipv6_pkt_rcvd */
    }

    /*
        not check PFT bit because this bit
        availd only when timestamp is enabled
    */
    if (message_type == RDES_EXT_NO_PTP) {
        /* no_ptp_rx_msg_type_ext */
        ETH_DEBUG("Is not ptp pac\n");
    } else {
        if (message_type == RDES_EXT_SYNC) {
            /* ptp_rx_msg_type_sync */
            ETH_DEBUG("ptp sync\n");
        } else if (message_type == RDES_EXT_FOLLOW_UP) {
            /* ptp_rx_msg_type_follow_up */
            ETH_DEBUG("ptp follow_up\n");
        } else if (message_type == RDES_EXT_DELAY_REQ) {
            /* ptp_rx_msg_type_delay_req */
            ETH_DEBUG("ptp delay_req\n");
        } else if (message_type == RDES_EXT_DELAY_RESP) {
            ETH_DEBUG("ptp delay_resp\n");
            /* ptp_rx_msg_type_delay_resp */
        } else if (message_type == RDES_EXT_PDELAY_REQ) {
            /* ptp_rx_msg_type_pdelay_req */
            ETH_DEBUG("ptp pdelay_req\n");
        } else if (message_type == RDES_EXT_PDELAY_RESP) {
            /* ptp_rx_msg_type_pdelay_resp */
            ETH_DEBUG("ptp pdelay_resp\n");
        } else if (message_type == RDES_EXT_PDELAY_FOLLOW_UP) {
            /* ptp_rx_msg_type_pdelay_follow_up */
            ETH_DEBUG("ptp pdelay_follow_up\n");
        } else if (message_type == RDES_PTP_ANNOUNCE) {
            /* ptp_rx_msg_type_announce */
            ETH_DEBUG("ptp announce\n");
        } else if (message_type == RDES_PTP_MANAGEMENT) {
            /* ptp_rx_msg_type_management */
            ETH_DEBUG("ptp management\n");
        } else if (message_type == RDES_PTP_PKT_RESERVED_TYPE) {
            /* ptp_rx_msg_pkt_reserved_type */
            ETH_DEBUG("ptp reserved_type\n");
        }

        /* ptp_frame_type */
        if (rdes1 & RDES1_PTP_PACKET_TYPE) {
            ETH_DEBUG("PTP_L2\n");
        } else {
            ETH_DEBUG("PTP_L4\n");
        }

        /* ptp_ver */
        if (rdes1 & RDES1_PTP_VER) {
            ETH_DEBUG("PTP_V2\n");
        } else {
            ETH_DEBUG("PTP_V1\n");
        }
    }

    if (rdes1 & RDES1_TIMESTAMP_DROPPED) {
        /* timestamp_dropped */
    }

    if ((rdes2 & RDES2_SA_FILTER_FAIL)) {
        /* sa_rx_filter_fail */
        ret = RX_BAD;
    }

    if ((rdes2 & RDES2_DA_FILTER_FAIL)) {
        /* da_rx_filter_fail */
        ret = RX_BAD;
    }

    if (rdes2 & RDES2_L3_FILTER_MATCH) {
        /* l3_filter_match */
    }

    if (rdes2 & RDES2_L4_FILTER_MATCH) {
        /* l4_filter_match */
    }

    if ((rdes2 & RDES2_L3_L4_FILT_NB_MATCH_MASK) >> RDES2_L3_L4_FILT_NB_MATCH_SHIFT) {
        /* l3_l4_filter_no_match */
    }

    return ret;
}

sint32 dwmac_rd_get_tx_len(struct dma_desc *p)
{
    return ((p->des2) & TDES2_BUFFER1_SIZE_MASK);
}

void dwmac_set_rx_owner(struct dma_desc *p, uint32 enable_rx_ic)
{
    p->des3 = (RDES3_OWN | RDES3_BUFFER1_VALID_ADDR);

    if (enable_rx_ic)
        p->des3 |= (RDES3_INT_ON_COMPLETION_EN);
}

sint32 dwmac_wrback_get_rx_frame_len(struct dma_desc *p)
{
    return ((p->des3) & RDES3_PACKET_SIZE_MASK);
}

void dwmac_rd_enable_tx_timestamp(struct dma_desc *p)
{
    p->des2 |= (TDES2_TIMESTAMP_ENABLE);
}

sint32 dwmac_wrback_get_tx_timestamp_status(struct dma_desc *p)
{
    /* Context type from W/B descriptor must be zero */
    if ((p->des3) & TDES3_CONTEXT_TYPE)
        return 0;

    /* Tx Timestamp Status is 1 so des0 and des1'll have valid values */
    if ((p->des3) & TDES3_TIMESTAMP_STATUS)
        return 1;

    return 0;
}

static sint32 dwmac_rx_check_timestamp(struct dma_desc *d)
{
    sint32 ret;

    if (d->des3 & RDES3_OWN)
        return -1;

    if (d->des3 & RDES3_CONTEXT_DESCRIPTOR) {
        if ((d->des0 == 0xffffffff) && (d->des1 == 0xffffffff)) {
            /* Corrupted value */
            ret = 0;
        } else {
            /* A valid Timestamp is ready to be read */
            ret = 1;
        }
    } else {
        ret = 0;
    }

    return ret;
}

uint32 dwmac_wrback_get_rx_timestamp_status(struct dma_desc *d, struct dma_desc *next_d)
{
    uint8 i = 0;
    sint32 ret = 0;
    ETH_DEBUG("2dp %d desc %08x desc %08x desc %08x desc %08x\n", d, d->des0, d->des1, d->des2,
              d->des3);

    /* Get the status from normal w/b descriptor */
    if (((d->des3 & (TDES3_LAST_DESCRIPTOR | TDES3_RS1V)) ==
         (TDES3_LAST_DESCRIPTOR | TDES3_RS1V)) && ((d->des1) & RDES1_TIMESTAMP_AVAILABLE) ) {
        /* Check if timestamp is OK from context descriptor */
        do {
            ret = dwmac_rx_check_timestamp(next_d);
            i++;
        } while ((ret == -1) && (i < 10));

        if (i == 10)
            ret = -2;
    }

    if ((ret < 0))
        ret = 0;

    return ret;
}

void dwmac_rd_init_rx_desc(struct dma_desc *p, uint32 enable_rx_ic)
{
    dwmac_set_rx_owner(p, enable_rx_ic);
}

void dwmac_rd_init_tx_desc(struct dma_desc *p)
{
    p->des0 = 0;
    p->des1 = 0;
    p->des2 = 0;
    p->des3 = 0;
}

void dwmac_rd_prepare_tx_desc(struct dma_desc *p, uint32 len,
                              uint32 tot_pkt_len, uint32 flags)
{
    uint32 tdes3 = (p->des3);

    p->des2 |= (len & TDES2_BUFFER1_SIZE_MASK);

    tdes3 |= tot_pkt_len & TDES3_PACKET_SIZE_MASK;

    if (flags & DESC_FLAGS_TX_FIRST) {
        tdes3 |= TDES3_FIRST_DESCRIPTOR;

        if (flags & DESC_FLAGS_TX_CPC_CRC_INSER) {
            tdes3 |= TDES3_CRC_INSER_DESCRIPTOR;
        } else if (flags & DESC_FLAGS_TX_CPC_PAD_INSER) {
            tdes3 |= TDES3_PAD_INSER_DESCRIPTOR;
        } else if (flags & DESC_FLAGS_TX_CPC_CRC_REPLA) {
            tdes3 |= TDES3_CRC_REPLACE_DESCRIPTOR;
        }
    } else {
        tdes3 &= (uint32)(~TDES3_FIRST_DESCRIPTOR);
    }

    if (!(flags & DESC_FLAGS_TX_CPC_PAD_INSER) &&
        (flags & DESC_FLAGS_TX_SAIC_REPLA)) {
        tdes3 |= TDES3_SA_REPLACE_DESCRIPTOR;
    }

    if ((flags & DESC_FLAGS_TX_CHK_SHIFT))
        tdes3 |= (TX_CIC_FULL << TDES3_CHECKSUM_INSERTION_SHIFT);
    else
        tdes3 &= (uint32)(~(TX_CIC_FULL << TDES3_CHECKSUM_INSERTION_SHIFT));

    if (flags & DESC_FLAGS_TX_LAST)
        tdes3 |= TDES3_LAST_DESCRIPTOR;
    else
        tdes3 &= (uint32)(~TDES3_LAST_DESCRIPTOR);

    /* Finally set the OWN bit. Later the DMA will start! */
    if (flags & DESC_FLAGS_TX_OWN)
        tdes3 |= TDES3_OWN;

    if (flags & DESC_FLAGS_IC) {
        dwmac_rd_set_tx_ic(p);
    }

    if (flags & DESC_FLAGS_TIMESTAMP) {
        dwmac_rd_enable_tx_timestamp(p);
    }
    /* Finally set the OWN bit. Later the DMA will start! */
    p->des3 = tdes3;

    if ((flags & DESC_FLAGS_TX_FIRST) && (flags & DESC_FLAGS_TX_OWN))
        dmb();
}

void dwmac_rd_set_tx_ic(struct dma_desc *p)
{
    p->des2 |= (TDES2_INTERRUPT_ON_COMPLETION);
}

void dwmac_set_addr(struct dma_desc *p, uint32 *addr)
{
    p->des0 = (uint32)addr;
}

void dwmac_clear(struct dma_desc *p)
{
    p->des0 = 0;
    p->des1 = 0;
    p->des2 = 0;
    p->des3 = 0;
}

#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#ifdef __cplusplus
}
#endif
