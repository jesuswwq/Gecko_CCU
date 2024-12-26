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
 * @file  sdrv_dma.c
 * @brief Semidrive. Dma
*/

#ifdef __cplusplus
extern "C" {
#endif


#include <_assert.h>
#include <cdefs.h>
#include <SchM_Dma.h>
#include "sdrv_dma.h"
#include "bits.h"
#include "irq.h"
#include "irq_num.h"
#include "sdrv_dmac.h"
#include "Mcal.h"
#include "Mcu.h"
#include "arch.h"
#include "Dma_Helper.h"

#define CONFIG_ARCH_CACHE_LINE 32
#define SDRV_DMA_LOG 0
#define SDRV_DMA_LLI_BUF_MAX_LEN (ROUNDUP(64, CONFIG_ARCH_CACHE_LINE))

#define SDRV_DMA_LLI_BUF_LBC_MAX_LEN (ROUNDUP(64, CONFIG_ARCH_CACHE_LINE))
#define DMA_FIFO_OFFSET 0xA000
#define FIFO_WORDS  (8192 / 4)

#ifndef SEMIDRIVE_E3_LITE_SERIES
#define DMA_CHANNEL_NUMBER      24u
#else
#define DMA_CHANNEL_NUMBER      16u
#endif /* #ifndef SEMIDRIVE_E3_LITE_SERIES */

static int ctz32(uint32 x)
{
    for (int i = 0; i != 32; ++i)
        if (x >> i & 1) return i;

    return 0;
}

/**
 * @brief abstract link list
 */
typedef struct lli_list {
    uint32 phy_addr;
    struct list_node lli_node; /* lli_node */
    struct list_node lli_head; /* lli_list */
    sdrv_dmac_lli_node_t lli_item;
    int bitmap_index;
} lli_list_t;


static unsigned long
sdrv_dma_lli_bitmap[MAX_CORE_NUM][BITMAP_NUM_WORDS(SDRV_DMA_LLI_BUF_MAX_LEN)]
__attribute__((__aligned__(CONFIG_ARCH_CACHE_LINE))) = {0};
static unsigned long
sdrv_dma_local_buf_bitmap[MAX_CORE_NUM][BITMAP_NUM_WORDS(SDRV_DMA_LLI_BUF_LBC_MAX_LEN)]
__attribute__((__aligned__(CONFIG_ARCH_CACHE_LINE))) = {0};
static lli_list_t sdrv_dma_lli_buf[MAX_CORE_NUM][SDRV_DMA_LLI_BUF_MAX_LEN]
__attribute__((__aligned__(CONFIG_ARCH_CACHE_LINE))) = {0};

typedef struct lli_desc {
    uint32 phy_addr;
    lli_list_t *mem_base;
    unsigned long *mem_bitmap;
    uint32 mem_size;
} lli_desc_t;

/**
 * @brief abstract dmac config.
 */
typedef struct dmac_coeff {
    paddr_t base;              /* dmac base address */
    sdrv_dma_cfg_t *hw_cfg;    /* dmac hardware config */
    sdrv_dmac_ch_cfg_t ch_cfg; /* dmac channel config */
} dmac_coeff_t;

/**
 * @brief abstract sdrv_dma channel
 */
typedef struct sdrv_dma_chan {
    dma_chan_t chan;
    dma_dev_cfg_t dev_cfg;
    dma_tr_direction_e direction;
    dma_transaction_type_e tr_type;
    uint8 memset_val;
    uint32 blk_size;
    uint32 len;
    uint32 ps_cnt;
    dmac_coeff_t dmac_cfg;
    lli_desc_t lli_desc;
} sdrv_dma_chan_t;

/**
 * @brief transfer dma_chan_t to sdrv_dma_chan_t.
 *
 * @param[in] chan  abstracted dma channel info
 * @return sdrv_dma_chan_t data point
 */
static inline sdrv_dma_chan_t *to_sdrv_dma_chan(dma_chan_t *chan)
{
    /*PRQA S 2810 6*/
    return containerof(chan, sdrv_dma_chan_t, chan);
}

static sdrv_dma_chan_t sdrv_dma_sf0_chan[MAX_CORE_NUM][DMA_CHANNEL_NUMBER] __attribute__((__aligned__
        (CONFIG_ARCH_CACHE_LINE))) = {0};
#if (STD_OFF == DMA_LOCK_STEP_MODE)
static sdrv_dma_chan_t sdrv_dma_sf1_chan[MAX_CORE_NUM][DMA_CHANNEL_NUMBER] __attribute__((__aligned__
        (CONFIG_ARCH_CACHE_LINE))) = {0};
#endif /* #if (STD_OFF == DMA_LOCK_STEP_MODE) */
#ifndef SEMIDRIVE_E3_LITE_SERIES
static sdrv_dma_chan_t sdrv_dma_ap_chan[MAX_CORE_NUM][8] __attribute__((__aligned__
        (CONFIG_ARCH_CACHE_LINE))) = {0};
#endif /* #ifndef SEMIDRIVE_E3_LITE_SERIES */

/*!> Staic functions */
static Std_ReturnType sdrv_dma_prepare_mad_crc(uint32 init_value, sdrv_dmac_lli_node_t *head);

/**
 * @brief dma_sf0 irq callback
 *
 * @param[in] irq irq id
 */
static int sdrv_dma_sf0_irq_handler(uint32 irq)
{
    dma_dev_t *dev = &dma_sf0[Mcu_GetCoreID()];
    uint32 chan_id = 0;
    uint32 chan_int_sta = 0;
    dma_chan_t *cptr = NULL;
    /*PRQA S 2810 6*/
    list_for_every_entry (&dev->channels, cptr, dma_chan_t, node) {
        if (irq == cptr->irq_id) {
            chan_id = cptr->chan_id;
            chan_int_sta = sdrv_dmac_get_int_state(dev->dma_base, chan_id);
            sdrv_dmac_clr_int(dev->dma_base, chan_id, chan_int_sta);

            if (cptr->irq_cb) {
                cptr->irq_cb(sdrv_dmac_irq_status_handle(chan_int_sta),
                             chan_int_sta, cptr);
            }
        }
    }

    return 0;
}

#if (STD_OFF == DMA_LOCK_STEP_MODE)
/**
 * @brief dma_sf1 irq callback
 *
 * @param[in] irq irq id
 */
static int sdrv_dma_sf1_irq_handler(uint32 irq)
{
    dma_dev_t *dev = &dma_sf1[Mcu_GetCoreID()];
    uint32 chan_id = 0;
    uint32 chan_int_sta = 0;
    dma_chan_t *cptr = NULL;
    /*PRQA S 2810 6*/
    list_for_every_entry (&dev->channels, cptr, dma_chan_t, node) {
        if (irq == cptr->irq_id) {
            chan_id = cptr->chan_id;
            chan_int_sta = sdrv_dmac_get_int_state(dev->dma_base, chan_id);
            sdrv_dmac_clr_int(dev->dma_base, chan_id, chan_int_sta);

            if (cptr->irq_cb) {
                cptr->irq_cb(sdrv_dmac_irq_status_handle(chan_int_sta),
                             chan_int_sta, cptr);
            }
        }
    }

    return 0;
}
#endif /* #if (STD_OFF == DMA_LOCK_STEP_MODE) */

#ifndef SEMIDRIVE_E3_LITE_SERIES
/**
 * @brief dma_ap0 irq callback
 *
 * @param[in] irq irq id
 */
static int sdrv_dma_ap0_irq_handler(uint32 irq)
{
    dma_dev_t *dev = &dma_ap0[Mcu_GetCoreID()];
    uint32 chan_id = 0;
    uint32 chan_int_sta = 0;
    dma_chan_t *cptr = NULL;

    /*PRQA S 2810 6*/
    list_for_every_entry (&dev->channels, cptr, dma_chan_t, node) {
        if (irq == cptr->irq_id) {
            chan_id = cptr->chan_id;
            chan_int_sta = sdrv_dmac_get_int_state(dev->dma_base, chan_id);
            sdrv_dmac_clr_int(dev->dma_base, chan_id, chan_int_sta);

            if (cptr->irq_cb) {
                cptr->irq_cb(sdrv_dmac_irq_status_handle(chan_int_sta),
                             chan_int_sta, cptr);
            }
        }
    }

    return 0;
}
#endif/* #ifndef SEMIDRIVE_E3_LITE_SERIES */

#define DMA_SF0_ISR(id) \
ISR(sdrv_dma_sf0_irq##id##_handler)\
{\
    sdrv_dma_sf0_irq_handler(DMA_SF_DMA0_CH_##id##_INTR_NUM);\
}

DMA_SF0_ISR(0)
DMA_SF0_ISR(1)
DMA_SF0_ISR(2)
DMA_SF0_ISR(3)
DMA_SF0_ISR(4)
DMA_SF0_ISR(5)
DMA_SF0_ISR(6)
DMA_SF0_ISR(7)
DMA_SF0_ISR(8)
DMA_SF0_ISR(9)
DMA_SF0_ISR(10)
DMA_SF0_ISR(11)
DMA_SF0_ISR(12)
DMA_SF0_ISR(13)
DMA_SF0_ISR(14)
DMA_SF0_ISR(15)

#ifndef SEMIDRIVE_E3_LITE_SERIES
DMA_SF0_ISR(16)
DMA_SF0_ISR(17)
DMA_SF0_ISR(18)
DMA_SF0_ISR(19)
DMA_SF0_ISR(20)
DMA_SF0_ISR(21)
DMA_SF0_ISR(22)
DMA_SF0_ISR(23)
#endif /* #ifndef SEMIDRIVE_E3_LITE_SERIES */

#define DMA_SF1_ISR(id) \
ISR(sdrv_dma_sf1_irq##id##_handler)\
{\
    sdrv_dma_sf1_irq_handler(DMA_SF_DMA1_CH_##id##_INTR_NUM);\
}
#if (STD_OFF == DMA_LOCK_STEP_MODE)
DMA_SF1_ISR(0)
DMA_SF1_ISR(1)
DMA_SF1_ISR(2)
DMA_SF1_ISR(3)
DMA_SF1_ISR(4)
DMA_SF1_ISR(5)
DMA_SF1_ISR(6)
DMA_SF1_ISR(7)
DMA_SF1_ISR(8)
DMA_SF1_ISR(9)
DMA_SF1_ISR(10)
DMA_SF1_ISR(11)
DMA_SF1_ISR(12)
DMA_SF1_ISR(13)
DMA_SF1_ISR(14)
DMA_SF1_ISR(15)

#ifndef SEMIDRIVE_E3_LITE_SERIES
DMA_SF1_ISR(16)
DMA_SF1_ISR(17)
DMA_SF1_ISR(18)
DMA_SF1_ISR(19)
DMA_SF1_ISR(20)
DMA_SF1_ISR(21)
DMA_SF1_ISR(22)
DMA_SF1_ISR(23)
#endif /* #ifndef SEMIDRIVE_E3_LITE_SERIES */
#endif /* #if (STD_OFF == DMA_LOCK_STEP_MODE) */
#ifndef SEMIDRIVE_E3_LITE_SERIES
#define DMA_AP0_ISR(id) \
ISR(sdrv_dma_ap0_irq##id##_handler)\
{\
    sdrv_dma_ap0_irq_handler(DMA_AP_DMA_CH_##id##_INTR_NUM);\
}

DMA_AP0_ISR(0)
DMA_AP0_ISR(1)
DMA_AP0_ISR(2)
DMA_AP0_ISR(3)
DMA_AP0_ISR(4)
DMA_AP0_ISR(5)
DMA_AP0_ISR(6)
DMA_AP0_ISR(7)
#endif /* #ifndef SEMIDRIVE_E3_LITE_SERIES */

/**
 * @brief dma_sf0 irq greister
 *
 */
#if defined(AUTOSAR_OS_NOT_USED)
static void sdrv_dma_irq_register(void)
{
    uint8 index = 0U;
    /* #10 Get total number which need to be registe interrupt */
    uint8 lendth = Dma_ChannelAllocateOnCoreTable[Mcu_GetCoreID()].SF0_Channel_Allocate_length +
                   Dma_ChannelAllocateOnCoreTable[Mcu_GetCoreID()].SF1_Channel_Allocate_length +
                   Dma_ChannelAllocateOnCoreTable[Mcu_GetCoreID()].AP_Channel_Allocate_length;

    for (index = 0U; index < lendth; index++) {
        if ((0xFFFFFFFFU ==
             Dma_ChannelAllocateOnCoreTable[Mcu_GetCoreID()].InterruptParams[index].InterruptNumber) &&
            (NULL_PTR    ==
             Dma_ChannelAllocateOnCoreTable[Mcu_GetCoreID()].InterruptParams[index].InterruptRoutine)) {
            /*!> TODO: add error process */
        } else {
            /* #20 Registe interrupt routine */
            irq_attach(Dma_ChannelAllocateOnCoreTable[Mcu_GetCoreID()].InterruptParams[index].InterruptNumber,
                       (irq_handler)
                       Dma_ChannelAllocateOnCoreTable[Mcu_GetCoreID()].InterruptParams[index].InterruptRoutine, NULL);
            /* #30 Enable the interrupt */
            irq_enable(Dma_ChannelAllocateOnCoreTable[Mcu_GetCoreID()].InterruptParams[index].InterruptNumber);
        }
    }
}
#endif
/**
 * @brief sdrv_dma chan request
 *
 * @param[in] dev dma control instance
 * @param[in] id  random if null
 * @return chan info
 */
static dma_chan_t *sdrv_dma_chan_req(dma_dev_t *dev, uint32 *id)
{
    dma_chan_t *cptr = NULL;
    sdrv_dma_chan_t *dmac = NULL;
    sint32 req_ret = 0;

    /*PRQA S 2810 6*/
    list_for_every_entry (&dev->channels, cptr, dma_chan_t, node) {
        if (0 == cptr->allocated) {
            cptr->irq_cb = NULL;
            cptr->context = NULL;
            cptr->chan_status = DMA_COMPLETED;

            if ((NULL == id) || (*id == cptr->chan_id)) {
                cptr->allocated = 1;
                req_ret = 1;
                break;
            }
        }
    }

    if (req_ret && cptr) {
        dmac = to_sdrv_dma_chan(cptr);
        dmac->dmac_cfg.ch_cfg.ps_cnt =
            sdrv_dmac_get_ch_pscnt(dev->dma_base, cptr->chan_id);
        return cptr;
    } else {
        return NULL;
    }
}

/**
 * @brief set dma device config (only for mem2dev/dev2mem)
 *
 * @param[in] chan requested chan info
 * @param[in] cfg device config
 */
static void sdrv_dma_dev_config(dma_chan_t *chan, dma_dev_cfg_t *cfg)
{
    /*PRQA S 2991,2995,2996 2*/
    if ((NULL == chan) || (NULL == cfg)) {
        ASSERT((NULL != chan) && (NULL != cfg));
    } else {
        SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_00();
        sdrv_dma_chan_t *dmac = to_sdrv_dma_chan(chan);

        memcpy(&dmac->dev_cfg, cfg, sizeof(*cfg));

        SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_00();
    }
}

/**
 * @brief: reclaim memory for continued use by subsequent applications
 *
 * @param {lli_desc_t *} lli_desc
 * @return {*}
 */
static void sdrv_dma_free_lli_desc(lli_desc_t *lli_desc)
{
    lli_list_t *curr = NULL;
    lli_list_t *first = (lli_list_t *)lli_desc->phy_addr;
    lli_list_t *next = NULL;

    if (first == NULL)
        return;

    IRQ_SAVE
    /*PRQA S 2810 6*/
    list_for_every_entry_safe (&first->lli_head, curr, next, lli_list_t,
                               lli_node) {
        list_delete(&curr->lli_node);

        bitmap_clear(lli_desc->mem_bitmap, curr->bitmap_index);
    }
    lli_desc->phy_addr = 0;
    IRQ_RESTORE
}

/**
 * @brief: alloc linklist node memory, memory base relate by lli_desc
 *
 * @param {lli_desc_t *} lli_desc
 * @return {lli_list_t*} linklist node memory base
 */
static lli_list_t *sdrv_dma_get_lli_desc(lli_desc_t *lli_desc)
{
    lli_list_t *lli_ptr = NULL;
    int index = 0;

    SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_00();

    index = bitmap_ffz(lli_desc->mem_bitmap, lli_desc->mem_size);

    if (-1 != index) {
        lli_ptr = &lli_desc->mem_base[index];

        list_initialize(&lli_ptr->lli_head);

        lli_ptr->phy_addr = (uint32)(addr_t)(&lli_ptr->lli_item);
        lli_ptr->bitmap_index = index;

        bitmap_set(lli_desc->mem_bitmap, index);
    }

    SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_00();

    return lli_ptr;
}

static sint32 sdrv_dma_get_muxid(sdrv_dma_mux_param_t *tbl, uint32 tbl_len,
                                 DMA_MUX_DIR direct, paddr_t periph_addr)
{
    sint32 mux_id = -1;

    for (int i = 0; i < tbl_len; i++) {
        if (periph_addr == tbl[i].start_addr + tbl[i].len) {
            if ((direct & tbl[i].direct) > 0) {
                mux_id = tbl[i].port;
                break;
            }
        }
    }

    return mux_id;
}

static Std_ReturnType sdrv_dma_prepare_mad_crc(uint32 init_value,
        sdrv_dmac_lli_node_t *head)
{
    sdrv_dmac_lli_node_t *current = head;
    uint32 crc_res[SDRV_DMA_MAD_CRC_REGISTERS];

    while (1) {
        // format data
        crc_res[0] = current->link_addr;
        crc_res[1] = current->operat_data;
        crc_res[2] = current->operat_mode;
        crc_res[3] = current->block_cfg;
        crc_res[4] = current->transaction_ctrl;
        crc_res[5] = current->dst_addr;
        crc_res[6] = current->src_addr;

        init_value = sdrv_dma_crc32(init_value, (const sint8 *)crc_res,
                                    (unsigned int)SDRV_DMA_MAD_CRC_REGISTERS *
                                    sizeof(sint32));
        current->mad_crc = init_value;
        arch_clean_cache_range((void *)current,
                               sizeof(sdrv_dmac_lli_node_t));

        current = (sdrv_dmac_lli_node_t *)(current->link_addr);

        if (current == NULL || current == head)
            break;
    }

    return E_OK;
}

/**
 * @brief: get the largest multiple of 2
 *         such as input 65 return 64.
 *
 * @param {uint32} value
 * @return {*}
 */
static uint32 get_align_sz(uint32 value)
{
    uint32 val = 0;
    val = 31 - clz32(value);
    val = 1 << val;
    return val;
}

/**
 * @brief set link list
 *
 * @param[in] dmac_cfg abstracted dmac config info
 * @param[in] len      data size
 * @param[in] blk_size single maximum length
 * @param[in] param for differnt transaction type,represent different parameters
 * @param[in] type transaction type
 * @param[in] direction transfer direction
 */
static lli_list_t *sdrv_dma_set_lli(dmac_coeff_t *dmac_cfg, uint32 len,
                                    uint32 blk_size, void *param,
                                    dma_transaction_type_e type,
                                    dma_tr_direction_e direction,
                                    lli_desc_t *lli_desc,
                                    dma_crc_mode_e mad_crc_mode)
{
    lli_list_t *first = NULL;
    lli_list_t *curr = NULL;
    lli_list_t *prev = NULL;
    uint32 offset = 0;
    uint32 tr_len = 0;
    uint32 period_len = ((DMA_CYCLIC == type) ? * ((uint32 *)param) : 0);
    sdrv_dmac_ll_cfg_t ll_config;

    if (NULL_PTR == dmac_cfg) {
        goto err_lli;
    } else {
        memcpy(&ll_config, &dmac_cfg->ch_cfg.ll_config, sizeof(sdrv_dmac_ll_cfg_t));
    }

    while (offset < len) {
        curr = sdrv_dma_get_lli_desc(lli_desc);

        if (!curr)
            goto err_lli;

        memset(&curr->lli_item, 0, sizeof(sdrv_dmac_lli_node_t));

        switch (type) {
        case DMA_CYCLIC:
        case DMA_DEVICE:
            if (DMA_MEM2DEV == direction) {
                curr->lli_item.src_addr =
                    (uint32)(dmac_cfg->ch_cfg.ll_config.src + offset);
                curr->lli_item.dst_addr =
                    (uint32)(dmac_cfg->ch_cfg.ll_config.dst);

            } else { // dev -> mem
                curr->lli_item.src_addr =
                    (uint32)(dmac_cfg->ch_cfg.ll_config.src);
                curr->lli_item.dst_addr =
                    (uint32)(dmac_cfg->ch_cfg.ll_config.dst + offset);
            }

            break;

        case DMA_MEMCPY:
            curr->lli_item.src_addr =
                (uint32)(dmac_cfg->ch_cfg.ll_config.src + offset);
            curr->lli_item.dst_addr =
                (uint32)(dmac_cfg->ch_cfg.ll_config.dst + offset);

            if (first)
                ll_config.lli_trig_mode = DMA_TRIGGER_BY_INTERNAL_EVENT;

            break;

        case DMA_MEMSET:
            curr->lli_item.src_addr =
                (uint32)(dmac_cfg->ch_cfg.ll_config.src);
            curr->lli_item.dst_addr =
                (uint32)(dmac_cfg->ch_cfg.ll_config.dst + offset);

            if (first)
                ll_config.lli_trig_mode = DMA_TRIGGER_BY_INTERNAL_EVENT;

            break;

        default:
            break;
        }

        if (DMA_CYCLIC == type) {
            tr_len = period_len;
        } else {
            tr_len = len > blk_size ? blk_size : len;

            if (offset + tr_len >= len) { // last
                switch (dmac_cfg->ch_cfg.ll_config.lop_mode) {
                case DMA_LOOP_MODE_0: // memcpy memset
                    tr_len = len - offset;

                    break;

                case DMA_LOOP_MODE_2: // mem2dev dev2mem
                    tr_len = get_align_sz(len - offset);
                    break;

                default:
                    DBG("unsupport loop mode \n");
                    break;
                }
            }
        }

        ll_config.buf_size = tr_len;

        if (!first) {
            first = curr;
            dmac_cfg->ch_cfg.ll_config.linklist_addr =
                (uint32)&first->lli_item;
        } else {
            prev->lli_item.link_addr = soc_to_dma_address((uint32)&curr->lli_item);
            arch_clean_cache_range((void *)&prev->lli_item,
                                   sizeof(sdrv_dmac_lli_node_t));
        }

        if (DMA_CYCLIC != type) {
            if (offset + tr_len >= len) {
                ll_config.last_mad = 1;
                ll_config.first_mad = 0;
            } else if (offset == 0) {
                ll_config.first_mad = 1;
                ll_config.last_mad = 0;
            } else {
                ll_config.first_mad = 0;
            }
        }

        sdrv_dmac_format_mad(&ll_config, &curr->lli_item, mad_crc_mode); // format mad memory
        list_add_tail(&first->lli_head, &curr->lli_node);
        prev = curr;
        offset += tr_len;
    }

    lli_desc->phy_addr = (uint32)first; // Virtual addresses are not supported

    if (DMA_CYCLIC == type) {
        curr->lli_item.link_addr = soc_to_dma_address((uint32)&first->lli_item);
    } else {
        curr->lli_item.link_addr = 0;
    }

    arch_clean_cache_range((void *)&first->lli_item,
                           sizeof(sdrv_dmac_lli_node_t));
    arch_clean_cache_range((void *)&curr->lli_item,
                           sizeof(sdrv_dmac_lli_node_t));
    return first;

err_lli:

    if (NULL != first)
        sdrv_dma_free_lli_desc(lli_desc);

    return NULL;
}

/**
 * @brief set dma common config
 *
 * @param[in] dmac_cfg abstracted dmac config info
 * @param[in] chan     requested dma channel info
 */
static void sdrv_dma_set_dmac_common_cfg(dmac_coeff_t *dmac_cfg,
        dma_chan_t *chan)
{
    uint32 xfer_items = 0;
    sdrv_dma_chan_t *dmac = to_sdrv_dma_chan(chan);
    dmac_cfg->base = chan->device->dma_base;
    dmac_cfg->ch_cfg.chan_id = chan->chan_id;
    dmac_cfg->ch_cfg.ll_config.src_bl =
        dmac->dev_cfg.src_maxburst * dmac->dev_cfg.src_addr_width;
    dmac_cfg->ch_cfg.ll_config.dst_bl =
        dmac->dev_cfg.dst_maxburst * dmac->dev_cfg.dst_addr_width;
    dmac_cfg->ch_cfg.ll_config.transfer_mode = DMA_TRANSFER_MODE_LINKLIST;
    dmac_cfg->ch_cfg.ll_config.buffer_mode = DMA_SINGLE_BUFFER;
    dmac_cfg->ch_cfg.ll_config.lop_mode = DMA_LOOP_MODE_2;

    /* check src/dst burst len */
    xfer_items = 1u << (31 - clz32(dmac->dev_cfg.src_maxburst));

    if (xfer_items != dmac->dev_cfg.src_maxburst)
        DBG("WARNING, src items not a multiple of 2, every req will xfer %d "
            "items \n",
            xfer_items);

    xfer_items = 1u << (31 - clz32(dmac->dev_cfg.dst_maxburst));

    if (xfer_items != dmac->dev_cfg.dst_maxburst)
        DBG("WARNING, dst items not a multiple of 2, every req will xfer %d "
            "items \n",
            xfer_items);
}

/**
 * @brief dma transfer config
 *
 * @param[in] chan abstracted dma channel info
 * @param[in] addr src buffer address
 * @param[in] len  data size
 * @param[in] param for differnt transaction type,represent different parameters
 * @param[in] flags  enable/disable interrupt
 * @param[in] type  transaction type
 * @return true/false
 */
static bool sdrv_dma_config_transfer(dma_chan_t *chan, void *addr, uint32 len,
                                     void *param, uint32 flags,
                                     dma_transaction_type_e type)
{
    sdrv_dma_chan_t *dmac = to_sdrv_dma_chan(chan);
    dmac_coeff_t dmac_cfg = {0};
    sdrv_dmac_ch_cfg_t *ch_cfg = NULL;
    lli_list_t *lli_ptr = NULL;
    sint32 muxid = -1;

    if (NULL == addr || 0 == len) {
        return false;
    }

    dmac->tr_type = type;
    dmac_cfg.hw_cfg = dmac->dmac_cfg.hw_cfg; // dma control desc, such as irq
    // num and muxid table and etc....
    ch_cfg = &dmac_cfg.ch_cfg;

    if (DMA_MEMCPY == type || DMA_MEMSET == type) {
        dma_local_buf_t lbc;
        sdrv_dmac_get_local_buf_prop(chan->device->dma_base, &lbc);
        dmac->dev_cfg.direction = DMA_MEM2MEM;
#ifndef SEMIDRIVE_E3_LITE_SERIES

        if (Mcu_GetChipVersion() == 0x01) {
#endif
            dmac->lli_desc.mem_base = (lli_list_t *)(lbc.buf_base);
            dmac->lli_desc.mem_bitmap = &sdrv_dma_local_buf_bitmap[Mcu_GetCoreID()][0U];
            dmac->lli_desc.mem_size = SDRV_DMA_LLI_BUF_LBC_MAX_LEN;
#ifndef SEMIDRIVE_E3_LITE_SERIES
        } else {
            dmac->lli_desc.mem_base = &sdrv_dma_lli_buf[Mcu_GetCoreID()][0U];
            dmac->lli_desc.mem_bitmap = &sdrv_dma_lli_bitmap[Mcu_GetCoreID()][0U];
            dmac->lli_desc.mem_size = SDRV_DMA_LLI_BUF_MAX_LEN;
        }

#endif
    } else {
        dmac->lli_desc.mem_base = &sdrv_dma_lli_buf[Mcu_GetCoreID()][0U];
        dmac->lli_desc.mem_bitmap = &sdrv_dma_lli_bitmap[Mcu_GetCoreID()][0U];
        dmac->lli_desc.mem_size = SDRV_DMA_LLI_BUF_MAX_LEN;
    }

    sdrv_dma_set_dmac_common_cfg(&dmac_cfg, chan);

    switch (dmac->dev_cfg.direction) {
    case DMA_MEM2MEM:
        if (DMA_MEMCPY == type) {
            ch_cfg->ll_config.lop_mode = DMA_LOOP_MODE_0; // high performance
            ch_cfg->ll_config.switch_event_ctrl =
                DMA_SWT_EVT_CTL_CONTINUE_WTH_INT;
            ch_cfg->ll_config.src = (uint8 *)addr;
            ch_cfg->ll_config.dst = (uint8 *)param;
            ch_cfg->ll_config.src_bz = DMA_BEAT_SIZE_8_BYTES;
            ch_cfg->ll_config.dst_bz = DMA_BEAT_SIZE_8_BYTES;
            ch_cfg->ll_config.src_port_sel = DMA_PORT_AXI64;
            ch_cfg->ll_config.dst_port_sel = DMA_PORT_AXI64;
            ch_cfg->ll_config.src_bt = DMA_BURST_INCREMENTAL;
            ch_cfg->ll_config.dst_bt = DMA_BURST_INCREMENTAL;
            ch_cfg->ll_config.flow_ctrl = DMA_DIR_MEM2MEM;
            ch_cfg->ll_config.lli_trig_mode = DMA_TRIGGER_BY_SOFTWARE;
            // memcpy high performance
            ch_cfg->ll_config.src_cache = 0;
            ch_cfg->ll_config.dst_cache = 1;
            sdrv_dmac_set_ch_rd_outstanding(chan->device->dma_base,
                                            chan->chan_id, 0xf);
            sdrv_dmac_set_ch_wr_outstanding(chan->device->dma_base,
                                            chan->chan_id, 0xf);
        } else if (DMA_MEMSET == type) {
            dmac->memset_val = *((uint8 *)param);
            uint32 memset_val = dmac->memset_val | dmac->memset_val << 8 |
                                dmac->memset_val << 16 |
                                dmac->memset_val << 24;
            ch_cfg->ll_config.lop_mode = DMA_LOOP_MODE_0; // high performance
            ch_cfg->ll_config.switch_event_ctrl =
                DMA_SWT_EVT_CTL_CONTINUE_WTH_INT;
            ch_cfg->ll_config.src = 0x0;
            ch_cfg->ll_config.dst = (uint8 *)addr;
            ch_cfg->ll_config.src_bz = DMA_BEAT_SIZE_8_BYTES;
            ch_cfg->ll_config.dst_bz = DMA_BEAT_SIZE_8_BYTES;
            ch_cfg->ll_config.src_port_sel = DMA_PORT_AXI64;
            ch_cfg->ll_config.dst_port_sel = DMA_PORT_AXI64;
            ch_cfg->ll_config.src_bt = DMA_BURST_FIXED;
            ch_cfg->ll_config.dst_bt = DMA_BURST_INCREMENTAL;
            ch_cfg->ll_config.flow_ctrl = DMA_DIR_REG2MEM;
            ch_cfg->ll_config.lli_trig_mode = DMA_TRIGGER_BY_SOFTWARE;
            sdrv_dmac_set_local_val(chan->device->dma_base, chan->chan_id,
                                    memset_val);
            // memset high performance
            ch_cfg->ll_config.src_cache = 0;
            ch_cfg->ll_config.dst_cache = 1;
            sdrv_dmac_set_ch_rd_outstanding(chan->device->dma_base,
                                            chan->chan_id, 0xf);
            sdrv_dmac_set_ch_wr_outstanding(chan->device->dma_base,
                                            chan->chan_id, 0xf);
        }

        break;

    case DMA_MEM2DEV:
        ch_cfg->ll_config.switch_event_ctrl = DMA_SWT_EVT_CTL_CONTINUE_WTH_INT;
        ch_cfg->ll_config.src = (uint8 *)addr;
        ch_cfg->ll_config.dst = (uint8 *)dmac->dev_cfg.dst_addr;

        ch_cfg->ll_config.src_bz = ctz32(dmac->dev_cfg.src_addr_width);
        ch_cfg->ll_config.dst_bz = ctz32(dmac->dev_cfg.dst_addr_width);
        ch_cfg->ll_config.src_port_sel = DMA_PORT_AXI64;
        ch_cfg->ll_config.dst_port_sel = DMA_PORT_AHB32;
        ch_cfg->ll_config.src_bt = DMA_BURST_INCREMENTAL;
        ch_cfg->ll_config.dst_bt = DMA_BURST_FIXED;
        ch_cfg->ll_config.flow_ctrl = DMA_DIR_MEM2DEV;
        ch_cfg->ll_config.lli_trig_mode = DMA_TRIGGER_BY_HARDWARE;
        ch_cfg->ll_config.src_cache = 0;
        ch_cfg->ll_config.dst_cache = 0;

        if (dmac->dev_cfg.custom_muxid_flag == true) {
            muxid = dmac->dev_cfg.custom_muxid;
        } else {
            muxid = sdrv_dma_get_muxid(dmac_cfg.hw_cfg->mux_table,
                                       dmac_cfg.hw_cfg->mux_table_len, DMA_MUX_WR,
                                       (uint32)ch_cfg->ll_config.dst);
        }

        if (muxid >= 0) {
            ch_cfg->ll_config.mux_id = muxid;
            sdrv_dmac_set_ch_muxid(chan->device->dma_base, chan->chan_id,
                                   ch_cfg->ll_config.mux_id);
        } else {
            return false;
        }

        break;

    case DMA_DEV2MEM:
        ch_cfg->ll_config.src = (uint8 *)dmac->dev_cfg.src_addr;
        ch_cfg->ll_config.dst = (uint8 *)addr;

        ch_cfg->ll_config.switch_event_ctrl = DMA_SWT_EVT_CTL_CONTINUE_WTH_INT;
        ch_cfg->ll_config.src_bz = ctz32(dmac->dev_cfg.src_addr_width);
        ch_cfg->ll_config.dst_bz = ctz32(dmac->dev_cfg.dst_addr_width);
        ch_cfg->ll_config.src_port_sel = DMA_PORT_AHB32;
        ch_cfg->ll_config.dst_port_sel = DMA_PORT_AXI64;
        ch_cfg->ll_config.src_bt = DMA_BURST_FIXED;
        ch_cfg->ll_config.dst_bt = DMA_BURST_INCREMENTAL;
        ch_cfg->ll_config.flow_ctrl = DMA_DIR_DEV2MEM;
        ch_cfg->ll_config.lli_trig_mode = DMA_TRIGGER_BY_HARDWARE;
        ch_cfg->ll_config.src_cache = 0;
        ch_cfg->ll_config.dst_cache = 0;

        if (dmac->dev_cfg.custom_muxid_flag == true) {
            muxid = dmac->dev_cfg.custom_muxid;
        } else {
            muxid = sdrv_dma_get_muxid(dmac_cfg.hw_cfg->mux_table,
                                       dmac_cfg.hw_cfg->mux_table_len, DMA_MUX_RD,
                                       (uint32)ch_cfg->ll_config.src);
        }

        if (muxid >= 0) {
            ch_cfg->ll_config.mux_id = muxid;
            sdrv_dmac_set_ch_muxid(chan->device->dma_base, chan->chan_id,
                                   ch_cfg->ll_config.mux_id);
        } else {
            return false;
        }

        break;

    default:
        break;
    }

    if (DMA_INTERRUPT & flags) {

        uint32 int_type = DMA_CH_INT_EN_CH_ABORT;

        if (type == DMA_CYCLIC) {
            int_type = int_type | DMA_CH_INT_EN_EVERY_MAD_DONE;
        } else {
            int_type = int_type | DMA_CH_INT_EN_LST_MAD_DONE;
        }

        sdrv_dmac_set_int_state(chan->device->dma_base, chan->chan_id,
                                int_type);
    }

    if (DMA_MEMCPY == type || DMA_MEMSET == type) {
        lli_ptr = sdrv_dma_set_lli(
                      &dmac_cfg, len,
                      sdrv_dmac_get_max_block_size((enum dma_loop_mode_t)ch_cfg->ll_config.lop_mode), param,
                      type, dmac->dev_cfg.direction, &dmac->lli_desc, dmac->dev_cfg.mad_crc_mode);
    } else {
        lli_ptr = sdrv_dma_set_lli(&dmac_cfg, len, dmac->blk_size, param, type,
                                   dmac->dev_cfg.direction, &dmac->lli_desc, dmac->dev_cfg.mad_crc_mode);
    }

    if (NULL == lli_ptr) {
        return false;
    }

    SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_00();
    dmac->chan.flags = (dma_ctrl_flags_t)flags;
    dmac->len = len;

    if (DMA_CHECK_CURR_MAD == dmac->dev_cfg.mad_crc_mode) {
        /* Calc dma mad crc */
        sdrv_dma_prepare_mad_crc(0U, &lli_ptr->lli_item);
    } else {
        /* Do Nothing */
    }

    sdrv_dmac_set_mad(chan->device->dma_base, chan->chan_id,
                      &lli_ptr->lli_item);
    SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_00();

    return true;
}

/**
 * @brief dma memcpy transfer config
 *
 * @param[in] chan requested dma channel info
 * @param[in] dst dst address
 * @param[in] src src address
 * @param[in] buf_len  data size
 * @param[in] flags  enable/disable interrupt
 * @return true/false
 */
static bool sdrv_dma_prep_memcpy(dma_chan_t *chan, void *dst, void *src,
                                 uint32 buf_len, uint32 flags)
{
    return sdrv_dma_config_transfer(chan, src, buf_len, dst, flags, DMA_MEMCPY);
}

/**
 * @brief dma memset transfer config
 *
 * @param[in] chan requested dma channel info
 * @param[in] val set value
 * @param[in] buf_addr dst address
 * @param[in] buf_len  data size
 * @param[in] flags  enable/disable interrupt
 * @return true/false
 */
static bool sdrv_dma_prep_memset(dma_chan_t *chan, uint8 val, void *buf_addr,
                                 uint32 buf_len, uint32 flags)
{
    return sdrv_dma_config_transfer(chan, buf_addr, buf_len, &val, flags,
                                    DMA_MEMSET);
}

/**
 * @brief dma dev2mem/mem2dev transfer config
 *
 * @param[in] chan requested dma channel info
 * @param[in] buf_addr src/dst address
 * @param[in] buf_len  data size
 * @param[in] flags  enable/disable interrupt
 * @return true/false
 */
static bool sdrv_dma_prep_dev(dma_chan_t *chan, void *buf_addr, uint32 buf_len,
                              uint32 flags)
{
    return sdrv_dma_config_transfer(chan, buf_addr, buf_len, NULL, flags,
                                    DMA_DEVICE);
}

/**
 * @brief dma dev2mem/mem2dev loop transfer config
 *
 * @param[in] chan requested dma channel info
 * @param[in] buf_addr src/dst address
 * @param[in] buf_len  data size
 * @param[in] flags  enable/disable interrupt
 * @return true/false
 */
static bool sdrv_dma_prep_cyclic(dma_chan_t *chan, void *buf_addr,
                                 uint32 buf_len, uint32 period_len,
                                 uint32 flags)
{
    return sdrv_dma_config_transfer(chan, buf_addr, buf_len, &period_len, flags,
                                    DMA_CYCLIC);
}

/**
 * @brief enable channel
 *
 * @param[in] chan requested channel info
 */
static void sdrv_dma_ch_enable(dma_chan_t *chan)
{
    /*PRQA S 2991,2995,2996 2*/
    if (NULL == chan) {
        ASSERT(NULL != chan);
    } else {
        sdrv_dma_chan_t *dmac = to_sdrv_dma_chan(chan);

        SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_00();

        dmac->chan.chan_status = DMA_IN_PROGRESS;
        sdrv_dmac_enable_ch(chan->device->dma_base, chan->chan_id,
                            dmac->dmac_cfg.ch_cfg.ps_cnt);

        if (dmac->dev_cfg.direction == DMA_MEM2MEM)
            sdrv_dmac_set_ch_sw_handshake(chan->device->dma_base, chan->chan_id);

        SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_00();
    }

}

/**
 * @brief disable channel
 *
 * @param[in] chan requested channel info
 */
static bool sdrv_dma_ch_disable(dma_chan_t *chan)
{
    bool ret = true;
    uint32 chann_en = 0;

    if (NULL == chan) {
        ret = false;
    } else {
        sdrv_dma_chan_t *dmac = to_sdrv_dma_chan(chan);

        SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_00();
        chann_en = sdrv_dmac_get_ch_en(chan->device->dma_base, chan->chan_id);

        if (chann_en) {
            ret = sdrv_dmac_set_ch_cmd(chan->device->dma_base, chan->chan_id,
                                       DMA_CH_CTL_STAT_ABORT) == 0
                  ? true
                  : false;
        }

        dmac->dmac_cfg.ch_cfg.ps_cnt =
            sdrv_dmac_get_ch_pscnt(chan->device->dma_base, chan->chan_id);
        dmac->chan.chan_status = DMA_COMPLETED;
        SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_00();
    }


    return ret;
}

/**
 * @brief sdrv_dma chan free
 *
 * @param[in] chan requested chan info
 */
static void sdrv_dma_chan_free(dma_chan_t *chan)
{

    /*PRQA S 2991,2995,2996 2*/
    if (NULL == chan) {
        ASSERT(NULL != chan);
    } else {
        sdrv_dma_chan_t *sdc = to_sdrv_dma_chan(chan);

        SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_00();

        chan->allocated = 0;

        SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_00();

        sdrv_dma_free_lli_desc(&sdc->lli_desc);
    }
}

/**
 * @brief get channel status when linklist single
 *
 * @param[in] chan requested channel info
 */
static dma_status_e sdrv_dmac_get_chan_status(dma_chan_t *chan)
{
    ASSERT(NULL != chan);

    // Don't change channel status here
    if (sdrv_dmac_get_ch_lastmad_done(chan->device->dma_base, chan->chan_id))
        return DMA_COMPLETED;
    else
        return DMA_IN_PROGRESS;
}

/**
 * @brief dma ops
 *
 */
static dma_ops_t dma_ops = {
    .request_chan = sdrv_dma_chan_req,
    .release_chan = sdrv_dma_chan_free,
    .prep_memcpy = sdrv_dma_prep_memcpy,
    .prep_memset = sdrv_dma_prep_memset,
    .prep_dev = sdrv_dma_prep_dev,
    .prep_cyclic = sdrv_dma_prep_cyclic,
    .config_chan = sdrv_dma_dev_config,
    .enable_chan = sdrv_dma_ch_enable,
    .disable_chan = sdrv_dma_ch_disable,
    .get_ch_status = sdrv_dmac_get_chan_status,
};


/**
 * @brief sdrv_dma init
 *
 * @param[in] dev dma control instance
 * @param[in] cfg dma control config,see sdrv_dma_cfg_t
 */
void sdrv_dma_init(dma_dev_t *dev, sdrv_dma_cfg_t *cfg)
{
    sdrv_dma_chan_t *sdrv_chan;

    /*PRQA S 2991,2995,2996 2*/
    if (NULL == dev) {
        ASSERT(NULL != dev);
    } else {
        dev->ops = &dma_ops;
        dma_init(dev);

        uint32 *dma_fifo_addr = (uint32 *)((dev->dma_base) + DMA_FIFO_OFFSET);

        for (int i = 0; i < FIFO_WORDS; i++) {
            dma_fifo_addr[i] = 0;
        }

        sdrv_dmac_core_reset_irq_sta(dev->dma_base);

        for (int i = 0; i < dev->channel_nr; i++) {
            if (dev->dma_base == APB_DMA_SF0_BASE) {
                sdrv_chan = &sdrv_dma_sf0_chan[Mcu_GetCoreID()][i];
            }

#if (STD_OFF == DMA_LOCK_STEP_MODE)
            else if (dev->dma_base == APB_DMA_SF1_BASE)  {
                sdrv_chan = &sdrv_dma_sf1_chan[Mcu_GetCoreID()][i];
            }

#endif /* #if (STD_OFF == DMA_LOCK_STEP_MODE) */
#ifndef SEMIDRIVE_E3_LITE_SERIES
            else if (dev->dma_base == APB_DMA_AP_BASE) {
                sdrv_chan = &sdrv_dma_ap_chan[Mcu_GetCoreID()][i];
            }

#endif /* #ifndef SEMIDRIVE_E3_LITE_SERIES */
            else {
                sdrv_chan = NULL_PTR;
            }

            if (sdrv_chan != NULL) {
                sdrv_chan->chan.chan_id = cfg->irq_id_table[i];

                if (APB_DMA_SF0_BASE == dev->dma_base) {
                    sdrv_chan->chan.irq_id = (cfg->irq_id_table[i] +
                                              DMA_SF_DMA0_CH_0_INTR_NUM);/* irq_id_table context is DMA channel Id, add 23 is interrupt number */
                }

#if (STD_OFF == DMA_LOCK_STEP_MODE)
                else if (APB_DMA_SF1_BASE == dev->dma_base) {
                    sdrv_chan->chan.irq_id = (cfg->irq_id_table[i] +
                                              DMA_SF_DMA1_CH_0_INTR_NUM);/* irq_id_table context is DMA channel Id, add 48 is interrupt number */
                }

#endif /* #if (STD_OFF == DMA_LOCK_STEP_MODE) */
#ifndef SEMIDRIVE_E3_LITE_SERIES
                else if (APB_DMA_AP_BASE == dev->dma_base) {
                    sdrv_chan->chan.irq_id = (cfg->irq_id_table[i] +
                                              DMA_AP_DMA_CH_0_INTR_NUM);/* irq_id_table context is DMA channel Id, add 73 is interrupt number */
                }

#endif /* #ifndef SEMIDRIVE_E3_LITE_SERIES */
                else {
                    /* Do Nothing */
                }

                sdrv_chan->chan.allocated = 0;
                sdrv_chan->chan.device = dev;
                sdrv_chan->chan.chan_status = DMA_COMPLETED;
                sdrv_chan->chan.priority = dev->priority;
                sdrv_chan->blk_size = SDRV_DMAC_MAX_BLK_SIZE;

                // Notice: cfg don't local variables, must global variables or heap
                sdrv_chan->dmac_cfg.hw_cfg  = cfg;
                list_add_tail(&dev->channels, &sdrv_chan->chan.node);
            }
        }

#if defined(AUTOSAR_OS_NOT_USED)
        /* Registe interrupt via core id */
        sdrv_dma_irq_register();
#endif
    }
}

uint32 sdrv_dma_get_xfer_bytes(dma_chan_t *chan, uint8 do_clr)
{
    ASSERT(NULL != chan);

    /*PRQA S 2996,2992 1*/
    if (NULL == chan) {
        return 0;
    } else {
        return sdrv_dmac_get_xfer_num(chan->device->dma_base, chan->chan_id, do_clr);
    }
}

#ifdef __cplusplus
}
#endif
