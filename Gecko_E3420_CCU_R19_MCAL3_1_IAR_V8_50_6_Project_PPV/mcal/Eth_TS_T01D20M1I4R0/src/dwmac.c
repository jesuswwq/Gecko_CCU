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
 * @file  dwmac.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Eth plugins.
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "cdefs.h"
#include "EthIf.h"
#include "EthBuff.h"
#include "EthDesc.h"
#include "dwmac_common.h"

#define  MAX_FREAM_802_3_LEN  0x0600
#define  ETHNET_II_802_3_OFFSET  0x08
#define  MAX_IRQ_RXTIMES_ETH  10
#define  MAX_SOC_SUPPORT_ETH  2

extern uint8 arch_arm_clz(uint32 x);
extern uint32 arch_arm_rbitu32(uint32 x);


#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"

/**
 * @name:
 * @Desc:
 * @param {uint8} CtrlIdx
 * @param {uint8*} fream
 * @param {uint16} freaml
 * @return {*}
 */
static  void rx_fream_parser(uint8 CtrlIdx, uint8 *fream, uint16 freaml)
{
    VAR(Eth_FrameType, AUTOMATIC) freamtype;
    VAR(boolean, AUTOMATIC) isbroadcast = 1;
    VAR(uint16, AUTOMATIC) dataoffset = MAC_HEADER_LEN;

    for (int i = 0; i < 6; i++) {
        if (fream[i] != 0xFF) {
            isbroadcast = 0;
            break;
        }
    }

    freamtype = fream[12];
    freamtype = freamtype << 8;
    freamtype |= fream[13];

    if (freamtype < MAX_FREAM_802_3_LEN) {
        // 802.3
        dataoffset += ETHNET_II_802_3_OFFSET;
        freamtype = fream[12 + ETHNET_II_802_3_OFFSET];
        freamtype = freamtype << 8;
        freamtype |= fream[13 + ETHNET_II_802_3_OFFSET];
    }

    EthIf_RxIndication(CtrlIdx, freamtype, isbroadcast, fream + 6, \
                       (Eth_DataType *)(fream + dataoffset), freaml - 18);
}
/**
 * @name:
 * @Desc:
 * @param {uint8} CtrlIdx
 * @param {locked_desc_t *} f_desc
 * @param {boolean} report
 * @return {*}
 */
static uint32 rx_fream_process(uint8 CtrlIdx, locked_desc_t *f_desc, boolean report)
{

    uint16 len;
    uint8 *freambuf;
    uint32 ret = RX_BAD;

    if (f_desc->confirm & LOCKED_DESC_RX_MASK) {
#if (ETH_NO_CACHEABLE_NEEDED == STD_OFF)
        arch_invalidate_cache_range((const void *)(uint32 *)f_desc->desc, \
                                    ROUNDUP(sizeof(struct dma_desc), CACHE_LINE));
#endif
        ret = dwmac_wrback_get_rx_status((struct dma_desc *)f_desc->desc);

        if (ret == RX_DMA_PROCESS) {
            /* desc is still in use */
            return ret;
        }

        /*
            Whether recive correctly or not, desc has been consumed.
        */
        f_desc->confirm = 0;

        if (ret != RX_GOOD) {
            /*
                  Received the packet, but there is an exception,
                do not continue to transmit to the upper layer.
            */
            return ret;
        }

        freambuf = (uint8 *)EthBuffAddr(CtrlIdx, f_desc->buf_idx, TRUE);

        if (report) {
            len = dwmac_wrback_get_rx_frame_len((struct dma_desc *)f_desc->desc);
#if (ETH_NO_CACHEABLE_NEEDED == STD_OFF)
            arch_invalidate_cache_range((const void *)(uint8 *)freambuf, \
                                        ROUNDUP(len, CACHE_LINE));
#endif
            rx_fream_parser(CtrlIdx, freambuf, len);
        } else {
            /* Not reported, the flag needs to be verified next time, so restore the flag bit */
            f_desc->confirm = LOCKED_DESC_RX_DMA;
        }
    }

    return ret;
}
/**
 * @name:
 * @Desc:
 * @param {uint8} CtrlIdx
 * @param {locked_desc_t *} f_desc
 * @param {boolean} report
 * @return {*}
 */
static  uint32 tx_fream_process(uint8 CtrlIdx, locked_desc_t *f_desc, boolean report)
{
    uint32 ret;
#if (ETH_NO_CACHEABLE_NEEDED == STD_OFF)
    arch_invalidate_cache_range((const void *)(uint32 *)f_desc->desc, \
                                ROUNDUP(sizeof(struct dma_desc), CACHE_LINE));
#endif
    ret = dwmac_wrback_get_tx_status((struct dma_desc *)f_desc->desc);

    /* dma own return */
    if (ret == TX_DMA_PROCESS ) {
        return ret;
    }

    if (report) {
        EthIf_TxConfirmation(CtrlIdx, f_desc->buf_idx, ret != TX_GOOD);

    }

    /* Whether sent correctly or not, desc has been consumed */
    f_desc->confirm = 0;
    return ret;
}

/**
 * @description:
 * @param {uint8} CtrlIdx
 * @param {uint8} Channel
 * @param {boolean} irq
 * @return {*}
 */
uint32 rx_indication(uint8 CtrlIdx, uint8 Channel)
{
    /* Probe for more packets */
    boolean pfmp = 0, need_press_desc;
    uint32 ret_dma;
    uint32  max_cnt = MAX_IRQ_RXTIMES_ETH;
    locked_desc_t *fream, *fream_n;
    uint32  ret = ETH_NOT_RECEIVED;

    do {

        if (max_cnt)
            max_cnt--;

        need_press_desc = 1;

        /* If not in poll mode,not sure there is a descriptor ok .
        so only touch it and not updata the ring cb */
        if (locked_desc_touch(CtrlIdx, Channel, &fream, TRUE)) {
            return ret;
        }

        if (fream->confirm & LOCKED_DESC_RX_MASK) {
            ret_dma = rx_fream_process(CtrlIdx, fream, !pfmp);

            /*  if irq mode there is dorp event, dorp count do not need soft dummy
             precess.in poll mode there is not exception.*/
            if ( RX_DMA_PROCESS == ret_dma) {
                return ret;
            }

            /* desc was onsumed ,TX_GOOD or other error */
            if (!pfmp) {
                /* only updata the ring cb,fream will not be modified */
                locked_desc_get(CtrlIdx, Channel, &fream, TRUE);
            }

            if (ret_dma == RX_GOOD) {
                if (!pfmp) {
                    ret = ETH_RECEIVED;
                } else {
                    need_press_desc = 0;
                    ret = ETH_RECEIVED_MORE_DATA_AVAILABLE;
                }
            } else if (pfmp) {
                locked_desc_get(CtrlIdx, Channel, &fream, TRUE);
            }
        }

        // do not need  free and realloc desc and membuf
        if (need_press_desc) {
            if (locked_desc_touch(CtrlIdx, Channel, &fream_n, TRUE)) {
                return ret;
            }
#if (ETH_NO_CACHEABLE_NEEDED == STD_OFF)
            arch_invalidate_cache_range((const void *)(uint32 *)fream_n->desc, \
                                        ROUNDUP(sizeof(struct dma_desc), CACHE_LINE));
#endif
            if (dwmac_wrback_get_rx_timestamp_status((struct dma_desc *)fream->desc,
                    (struct dma_desc *)fream_n->desc)) {
                Eth_ReInitRxDesc(CtrlIdx, fream);
                locked_desc_get(CtrlIdx, Channel, &fream_n, TRUE);
                Eth_ReInitRxDesc(CtrlIdx, fream_n);
            } else {
                Eth_ReInitRxDesc(CtrlIdx, fream);
            }
        }

        // fix recv suspend
        if (dwmac_dma_rx_state_get(ETH_CFG_CTRL_REG_BASE(CtrlIdx), \
                                   Channel) == DMX_RX_SUSPND) {
            dwmac_rx_trigger(ETH_CFG_CTRL_REG_BASE(CtrlIdx), Channel);
        }

        if (!max_cnt) {
            if (!pfmp)
                pfmp = 1;

            if (ret == ETH_RECEIVED_MORE_DATA_AVAILABLE) {
                return ret;
            }
        }
    } while (1);
}

/**
 * @name:
 * @Desc:
 * @param {uint8} CtrlIdx
 * @return {*}
 */
static  void rx_handle(uint8 CtrlIdx, uint8 Channel)
{
    rx_indication(CtrlIdx, Channel);
}
/**
 * @description:
 * @param {uint8} CtrlIdx
 * @param {uint8} Channel
 * @param {boolean} irq
 * @return {*}
 */
void tx_indication(uint8 CtrlIdx, uint8 Channel, boolean irq)
{
    uint32 ret;
    locked_desc_t *fream;

    do {
        if (irq) {
            if (locked_desc_get(CtrlIdx, Channel, &fream, FALSE)) {
                return;
            }
        } else {
            /* If not in poll mode,not sure there is a descriptor ok .
            so only touch it and not updata the ring cb */
            if (locked_desc_touch(CtrlIdx, Channel, &fream, FALSE)) {
                return;
            }
        }

        if (fream->confirm & LOCKED_DESC_TX_MASK) {
            ret = tx_fream_process(CtrlIdx, fream, fream->confirm & \
                                   LOCKED_DESC_TX_CONFIRM);

            if (ret == TX_DMA_PROCESS) {
                /* desc have not been consumed ,return */
                return;
            }

            /* desc was onsumed ,TX_GOOD or other error */
            if (!irq) {
                /* only updata the ring cb,fream will not be modified */
                locked_desc_get(CtrlIdx, Channel, &fream, FALSE);
            }
        }

        /* only when mem buf and dma desc are used need to release resources */
        EthBuffFree(CtrlIdx, fream->buf_idx, FALSE);
        free_dma_desc(CtrlIdx, Channel, FALSE);
        // the second times should polling
        irq = 0;
    } while (1);
}
/**
 * @name:
 * @Desc:
 * @param {uint8} CtrlIdx
 * @return {*}
 */
static void tx_handle(uint8 CtrlIdx, uint8 Channel)
{
    tx_indication(CtrlIdx, Channel, TRUE);
}
#ifdef ETH_RX_ERROR_RECOVER
/**
 * @description:
 * @param {uint8} CtrlIdx
 * @return {*}
 */
void dwmac_dma_reinit(uint8 CtrlIdx)
{
  int reset_ret=0;
  Eth_SetControllerMode(CtrlIdx,ETH_MODE_DOWN);
  reset_ret  = dwmac_dma_reset(ETH_CFG_CTRL_REG_BASE(CtrlIdx));
  /* It is impossible to return a negative value */
  if(reset_ret >= 0){
    /* DMA Init */
    Eth_Ctrl_Init_DMA(CtrlIdx, ETH_CFG_CTRL_RX_INT_MODE(CtrlIdx),
                      ETH_CFG_CTRL_TX_INT_MODE(CtrlIdx));
    /* MTL Init */
    Eth_Ctrl_Init_MTL(CtrlIdx);
    /* MAC Init */
    Eth_Ctrl_Init_MAC(CtrlIdx, ETH_CFG_CTRL_PARM_PTR(CtrlIdx)->Mtu,
                     ETH_CFG_CTRL_PARM_PTR(CtrlIdx)->MacLayerSpeed);
    Eth_SetControllerMode(CtrlIdx,ETH_MODE_ACTIVE);
  }
}
#endif
/**
 * @name:
 * @Desc:
 * @param {uint8} CtrlIdx
 * @param {uint8} dma_ch
 * @param {uint8} rx_mtl_ch
 * @return {*}
 */
static void ctrl_handle(uint8 CtrlIdx, uint8 rx_mtl_ch)
{
    uint8 chan;
#ifdef ETH_RX_ERROR_RECOVER
    uint32 cur_desc;
#endif
    uint32 ch_irq_en_sta;
    uint32 dma_status,rx_ctrl,intr_status;
    uint32 regbase = ETH_CFG_CTRL_REG_BASE(CtrlIdx);

    dma_status = readl(regbase + DMA_STATUS);

    if (dma_status & DMA_STATUS_MTL) {
        //MTL
        uint32 mtl_int_qx_status;

        mtl_int_qx_status = readl(regbase + MTL_INT_STATUS);

        /* Check MTL Interrupt */
        if (mtl_int_qx_status & MTL_INT_QX(rx_mtl_ch)) {
            /* read Queue x Interrupt status */
            uint32 status = readl(regbase + MTL_CHAN_INT_CTRL(rx_mtl_ch));

            if (status & MTL_RX_OVERFLOW_INT) {
                /*  clear Interrupt */
                writel(status | MTL_RX_OVERFLOW_INT,
                       regbase + MTL_CHAN_INT_CTRL(rx_mtl_ch));
                dwmac_rx_trigger(regbase, rx_mtl_ch);
#ifdef ETH_RX_ERROR_RECOVER
                /* Rx only enable ch0 */
                if(ETH_CTRL_FATAL_RETRY_NUM(CtrlIdx)){
                  cur_desc = readl(regbase + DMA_CHAN_CUR_RX_DESC(MULTI_CH_RX_CH_IDX));
                  /* SR bit still 0 and desc pointer not updated: unable to recover exception reinitialization */
                  if(ETH_CTRL_LAST_CUR_DESC(CtrlIdx) == cur_desc){
                    dwmac_dma_reinit(CtrlIdx);
                    ETH_CTRL_FATAL_RETRY_NUM(CtrlIdx) = 0;
                    ETH_CTRL_FATAL_REINIT_NUM(CtrlIdx) += 1;
                   }
                }
#endif
            }
        }
    }
#ifndef ETH_DISABLE_IRQ_PULSE
    chan = arch_arm_clz(arch_arm_rbitu32(dma_status & DMA_STATUS_CHAN0_5));

    if (dma_status & (0x1 << chan)) {

        intr_status = readl(regbase + DMA_CHAN_STATUS(chan));
        /* clear the irq flags */
        writel((intr_status & 0x3fffc7), regbase + DMA_CHAN_STATUS(chan));

        /* ABNORMAL interrupts */
        if ((intr_status & DMA_CHAN_STATUS_AIS)) {
            rx_ctrl = readl(regbase + DMA_CHAN_RX_CONTROL(chan));
            if(!( rx_ctrl& DMA_CONTROL_SR)){
              ETH_CTRL_LAST_CUR_DESC(CtrlIdx) = readl(regbase + DMA_CHAN_CUR_RX_DESC(chan));
              writel(rx_ctrl | DMA_CONTROL_SR ,regbase + DMA_CHAN_RX_CONTROL(chan));
              ETH_CTRL_FATAL_RETRY_NUM(CtrlIdx) += 1;
              /*
                  When rolling back to 0, it will cause the recovery mechanism to fail,
                and choosing to sacrifice the accuracy of exception event counting
              */
              ETH_CTRL_FATAL_RETRY_NUM(CtrlIdx) |= 0x1;
            }
        }

        /* TX/RX NORMAL interrupts */
        if ((intr_status & DMA_CHAN_STATUS_NIS)) {
            ch_irq_en_sta = readl(regbase + DMA_CHAN_INTR_ENA(chan));

            if (intr_status & (DMA_CHAN_STATUS_RI | DMA_CHAN_STATUS_RBU)) {
                if (ch_irq_en_sta & (DMA_CHAN_INTR_ENA_RIE | DMA_CHAN_INTR_ENA_RBUE)) {
                    rx_handle(CtrlIdx, chan);
                    /*
                        Any successful reception after reset the sr bit indicates that the
                        previous recovery was successful, and reset is not required for recovery.
                    */
                    ETH_CTRL_LAST_CUR_DESC(CtrlIdx) = 0xaaa55aa5;
                }
            }

            if ((intr_status & DMA_CHAN_STATUS_TI)) {
                if ((ch_irq_en_sta & DMA_CHAN_INTR_ENA_TIE)) {
                    tx_handle(CtrlIdx, chan);
                }
            }
        }
    }
#else
    for(chan =0;chan < ETH_MAX_DMA_CHANNEL ;chan++){
        intr_status = readl(regbase + DMA_CHAN_STATUS(chan));
        if(intr_status & DMA_CHAN_STATUS_PERCH){
          /* clear the irq flags */
          writel((intr_status & 0x3fffc7), regbase + DMA_CHAN_STATUS(chan));

          /* ABNORMAL interrupts */
          if ((intr_status & DMA_CHAN_STATUS_AIS)) {
            rx_ctrl = readl(regbase + DMA_CHAN_RX_CONTROL(chan));
            if(!( rx_ctrl& DMA_CONTROL_SR)){
              ETH_CTRL_LAST_CUR_DESC(CtrlIdx) = readl(regbase + DMA_CHAN_CUR_RX_DESC(chan));
              writel(rx_ctrl | DMA_CONTROL_SR ,regbase + DMA_CHAN_RX_CONTROL(chan));
              ETH_CTRL_FATAL_RETRY_NUM(CtrlIdx) += 1;
              /*
                  When rolling back to 0, it will cause the recovery mechanism to fail,
                and choosing to sacrifice the accuracy of exception event counting
              */
              ETH_CTRL_FATAL_RETRY_NUM(CtrlIdx) |= 0x1;
            }
          }

            /* TX/RX NORMAL interrupts */
            ch_irq_en_sta = readl(regbase + DMA_CHAN_INTR_ENA(chan));

            if (intr_status & (DMA_CHAN_STATUS_RI | DMA_CHAN_STATUS_RBU)) {
                if (ch_irq_en_sta & (DMA_CHAN_INTR_ENA_RIE | DMA_CHAN_INTR_ENA_RBUE)) {
                    rx_handle(CtrlIdx, chan);
                    /*
                        Any successful reception after reset the sr bit indicates that the
                        previous recovery was successful, and reset is not required for recovery.
                    */
                    ETH_CTRL_LAST_CUR_DESC(CtrlIdx) = 0xaaa55aa5;
                }
            }

            if ((intr_status & DMA_CHAN_STATUS_TI)) {
                if ((ch_irq_en_sta & DMA_CHAN_INTR_ENA_TIE)) {
                    tx_handle(CtrlIdx, chan);
                }
            }
        }
    }
#endif
    if (DMA_STATUS_MAC & dma_status) {
        mac_irq_handler(regbase);
    }
}

ISR(eth0_handle)
{
    ctrl_handle(0, 0);
}
#if (ETH_MAXCTRLS_SUPPORTED == 2U)
ISR(eth1_handle)
{
    ctrl_handle(1, 0);
}
#endif

#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#ifdef __cplusplus
}
#endif
