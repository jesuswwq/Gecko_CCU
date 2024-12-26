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
 * @file  sdrv_dmac.c
 * @brief Semidrive. Dma
 */

#ifndef __SDRV_DMAC_H__
#define __SDRV_DMAC_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "RegHelper.h"
#include "bits.h"
#include "sdrv_dma.h"

#define LP2_LPSIZE(n) ((ffs32(n) - 1) & 0xf)
#define LP2_TT(n) (((n - 1) << 4) & 0xfffff0)
#define LP2_TOTAL_MAX (0x200000)
#define LP1_LPSIZE_MAX (0X00000FFF)
#define LP2_LPSIZE_MAX (0x8000)
#define LP0_LPSIZE_MAX (0x00FFFFFF)
#define LP_DEFAULT_LPSIZE_MAX (0xFFFFFFFF)
#define SDRV_DMAC_MAX_BLK_SIZE LP2_LPSIZE_MAX /* Semidrive version size */

typedef struct dma_mad dmac_mad_t;

typedef struct dma_local_buffer {
    uint32 buf_base;
    uint32 buf_size;
} dma_local_buf_t;


typedef enum {
    DMA_TRANSFER_TYPE_CONTINUOUS =
        0, /*both src and dst set continuous result single type*/
    DMA_TRANSFER_TYPE_RELOAD,
    DMA_TRANSFER_TYPE_SHADOW,
    DMA_TRANSFER_TYPE_LLI,
} dma_transfer_type;

/* error code enum */
enum dma_core_err_t {
    /* core register error */
    ERR_NOT_DEFINED,

    /* APB E2E */
    CORE_APB_PW_DATA_UNC_ERR,
    CORE_APB_PW_DATA_COR_ERR,
    CORE_APB_PW_DATA_FATAL_ERR,
    CORE_APB_PCTL0_UNC_ERR,
    CORE_APB_PCTL1_UNC_ERR,
    CORE_APB_PADDR_UNC_ERR,

    /* AHB E2E */
    CORE_AHB_HRESP_UNC_ERR,
    CORE_AHB_HRDATA_UNC_ERR,
    CORE_AHB_HRDATA_COR_ERR,
    CORE_AHB_HRDATA_FATAL_ERR,

    /* AXI E2E */
    /* R channel */
    CORE_AXI_RVALID_UNC_ERR,
    CORE_AXI_RID_UNC_ERR,
    CORE_AXI_REOBI_UNC_ERR,
    CORE_AXI_RDATA_UNC_ERR,
    CORE_AXI_RDATA_COR_ERR,
    CORE_AXI_RCTL_UNC_ERR,
    CORE_AXI_RD_MONITOR_FATAL_ERR,
    /* AR channel */
    CORE_AXI_ARREADY_UNC_ERR,
    /* AW channel */
    CORE_AXI_AWREADY_UNC_ERR,
    /* B channel */
    CORE_AXI_BCTL_UNC_ERR,
    CORE_AXI_BID_UNC_ERR,
    CORE_AXI_BVALID_UNC_ERR,
    /* W channel */
    CORE_AXI_WREADY_UNC_ERR,

    /* local buffer */
    CORE_LBC_UNC_ERR,
    CORE_LBC_COR_ERR,

    /* dma channel */
    CORE_CH_UNC_ERR,
    CORE_CH_COR_ERR,

    /* dma fifo */
    CORE_FIFO_UNC_ERR,
    CORE_FIFO_COR_ERR,

    /* lock step error */
    CORE_LOCK_STEP_ERR,
    /* axi lock step err */
    CORE_LS_AXI_AW_ERR,
    CORE_LS_AXI_AR_ERR,
    CORE_LS_AXI_B_ERR,
    CORE_LS_AXI_R_ERR,
    CORE_LS_AXI_W_ERR,

    CORE_LS_CH_ERR,
    CORE_LS_LBC_ERR,
    CORE_LS_PER_ERR,
    CORE_LS_AHB_ERR,
    CORE_LS_APB_ERR,
    CORE_LS_MISC_ERR,

    CORE_CORE1_MONITOR_ERR,
    CORE_DMA_INPUT_SIG_ERR, /* dma input lock step error or selftest mode signal
                               error */
};

enum dma_core_err_inj_t {
    CORE_ERR_INJ_NOT_DEFINED,
    CORE_INT_ERR_INJ,
    CORE_INSIG_ERR_INJ,
    CORE_LOCKSTEP_ERR_INJ,
    CORE_APB_W_ECC_ERR_INJ,
    CORE_APB_WDATA_ERR_INJ,
    CORE_AXI_R_ECC_ERR_INJ,
    CORE_AXI_RDATA_ERR_INJ,
    CORE_AHB_R_ECC_ERR_INJ,
    CORE_AHB_RDATA_ERR_INJ,
    CORE_LB_DATA_ERR_INJ,
    CORE_LB_CODE_ERR_INJ,
};

enum dma_ch_err_t {
    CH_HS_E2E_COR_ERR,
    CH_HS_E2E_FATAL,
    CH_HS_E2E_UNC_ERR,
    CH_FIFO_ECC_COR_ERR,
    CH_FIFO_ECC_UNC_ERR,
    CH_AHB_READ_ERR,
    CH_AHB_WRITE_ERR,
    CH_AXI_READ_ERR,
    CH_AXI_WRITE_ERR,
    CH_LINK_ERR,
    CH_MAD_CRC_ERR,
    CH_FW_RD_ERR,
    CH_FW_WR_ERR,
    CH_DATA_CRC_ERR,
    CH_AXI_OUTSTANDING_UTID_ERR,
    CH_PROG_SEQ_ERR,
};

enum dma_ch_err_inj_t {
    /* handshake error inject */
    CH_HS_ERR_INJ,
    CH_DMA_BW_CODE_INJ,
    CH_DMA_BW_DATA_INJ,
    CH_DMA_FW_CODE_INJ,
    CH_DMA_FW_DATA_INJ,

    /* channel interrupt error inject */
    CH_INT_ERR_INJ,
};

enum dma_beat_size_t {
    DMA_BEAT_SIZE_1_BYTE = 0,
    DMA_BEAT_SIZE_2_BYTES,
    DMA_BEAT_SIZE_4_BYTES,
    DMA_BEAT_SIZE_8_BYTES,
    DMA_BEAT_SIZE_NOT_DEFINED,
};

enum dma_burst_len_t {
    DMA_BURST_LEN_1 = 0,
    DMA_BURST_LEN_2,
    DMA_BURST_LEN_3,
    DMA_BURST_LEN_4,
    DMA_BURST_LEN_5,
    DMA_BURST_LEN_6,
    DMA_BURST_LEN_7,
    DMA_BURST_LEN_8,
    DMA_BURST_LEN_9,
    DMA_BURST_LEN_10,
    DMA_BURST_LEN_11,
    DMA_BURST_LEN_12,
    DMA_BURST_LEN_13,
    DMA_BURST_LEN_14,
    DMA_BURST_LEN_15,
    DMA_BURST_LEN_16,
    DMA_BURST_LEN_NOT_DEFINED,
};

enum dma_port_sel_t {
    DMA_PORT_AXI64 = 0,
    DMA_PORT_AHB32,
    DMA_PROT_NOT_DEFINED,
};

enum dma_burst_type_t {
    DMA_BURST_INCREMENTAL = 0,
    DMA_BURST_FIXED,
    DMA_BURST_TYPE_UNDEFINED,
};

enum dma_buffer_mode_t {
    DMA_SINGLE_BUFFER = 0,
    DMA_DOUBLE_BUFFER,
    DMA_CIRCULAR_BUFFER,
    DMA_2D_BUFFER,
    DMA_BUFFER_NOT_DEFINED,
};

enum dma_loop_mode_t {
    DMA_LOOP_MODE_0 = 0,
    DMA_LOOP_MODE_1,
    DMA_LOOP_MODE_2,
    DMA_LOOP_MODE_UNDEFINED,
};

enum dma_switch_event_ctl_t {
    DMA_SWT_EVT_CTL_STOP_WTH_INT = 0,
    DMA_SWT_EVT_CTL_SUSPEND_WTH_INT,
    DMA_SWT_EVT_CTL_CONTINUE_WTH_INT,
    DMA_SWT_EVT_CTL_CONTINUE_WTHOUT_INT,
    DMA_SWT_EVT_CTL_UNDEFINED,
};

enum dma_dir_t {
    DMA_DIR_MEM2MEM = 0,
    DMA_DIR_MEM2DEV,
    DMA_DIR_DEV2MEM,
    DMA_DIR_DEV2DEV,
    DMA_DIR_REG2MEM,
    DMA_DIR_REG2DEV,
    DMA_DIR_MEM2REG,
    DMA_DIR_DEV2REG,
    DMA_DIR_NOT_DEFINED,
};

enum dma_transfer_mode_t {
    DMA_TRANSFER_MODE_SINGLE = 0,
    DMA_TRANSFER_MODE_CONTINUOUS,
    DMA_TRANSFER_MODE_LINKLIST,
    DMA_TRANSFER_MODE_CHAN_LINK,
    DMA_TRANSFER_MODE_NOT_DEFINED,
};

enum dma_trigger_mode_t {
    DMA_TRIGGER_BY_HARDWARE = 0,
    DMA_TRIGGER_BY_SOFTWARE,
    DMA_TRIGGER_BY_GTIMER,
    DMA_TRIGGER_BY_INTERNAL_EVENT, /* by linklist or channel linking */
    DMA_TRIGGER_MODE_NOT_DEFINED,
};

typedef enum ch_ctl_stat {
    DMA_CH_CTL_STAT_STOP = 0,
    DMA_CH_CTL_STAT_FLUSH = 1,
    DMA_CH_CTL_STAT_REQ_FLUSH = 2,
    DMA_CH_CTL_STAT_HALT = 3,
    DMA_CH_CTL_STAT_ENABLE = 4,
    DMA_CH_CTL_STAT_RESUME = 5,
    DMA_CH_CTL_STAT_ABORT = 6,
} ch_ctl_stat_t;

typedef enum int_enable_stat {
    DMA_CH_INT_EN_LST_MAD_DONE = 1 << 14,
    DMA_CH_INT_EN_EVERY_MAD_DONE = 1 << 15,
    DMA_CH_INT_EN_CH_HALT = 1 << 19,
    DMA_CH_INT_EN_CH_ABORT = 1 << 20,
    DMA_CH_INT_EN_HS_COMP = 1 << 23,
} int_enable_stat_t;

typedef struct dma_ll_cfg {
    uint32 mux_id;
    uint8 *src;
    uint8 *dst;
    uint32 src_bz; // beat_size
    uint32 dst_bz;
    uint32 src_bl;
    uint32 dst_bl; // burst length
    uint32 src_port_sel;
    uint32 dst_port_sel;
    uint32 src_bt; // burst_type 0 incremental/1 fixed
    uint32 dst_bt;
    sint32 src_stride;
    sint32 dst_stride;
    uint32 buffer_mode; // single double circular 2d
    uint32 buf_size;    // 4, 8, 12 = = l m h
    uint32 lop_mode;    // 0 /1 /2
    uint32 switch_event_ctrl;
    uint32 flow_ctrl;
    uint32 transfer_mode; // single continuous linklist channellink
    uint32 trig_mode;
    uint32 linklist_addr;
    enum dma_trigger_mode_t lli_trig_mode; // for linked list trigger.
    uint32 first_mad;
    uint32 last_mad;
    uint32 src_cache;
    uint32 dst_cache;
} sdrv_dmac_ll_cfg_t;

typedef struct dmac_ch_config {
    uint32 chan_id;
    sdrv_dmac_ll_cfg_t ll_config;
    uint32 ps_cnt;             // [h]times doing handshake;
    struct list_node lli_header; // maintain sg list.
} sdrv_dmac_ch_cfg_t;

typedef struct dmac_lli_config {
    uint32 src_addr;
    uint32 dst_addr;
    uint32 transaction_ctrl;
    uint32 block_cfg;
    uint32 operat_mode;
    uint32 operat_data;
    uint32 mad_crc;
    uint32 link_addr;
} sdrv_dmac_lli_node_t;

/**
 * @brief: count leading zero num
 *
 * @param {uint32} number to be counted
 * @return {*}
 */
int clz32(uint32 );

/**
 * @brief: dma channel enable should set ps cnt value,
 * before set channel register.
 *
 * @param {paddr_t} dma ip register base
 * @param {uint32} chan is dma channel num
 * @return {*}
 */
uint8 sdrv_dmac_get_ch_pscnt(paddr_t dma_base, uint32 chan);

/**
 * @brief: get last mad interrupt status, but not clear status
 *
 * @param {paddr_t} dma_base is dma ip register base
 * @param {uint32} chan is dma channel num
 * @return {0: means last mad is done
 *          1: means last mad done interrupt singal not occur}
 */
uint8 sdrv_dmac_get_ch_lastmad_done(paddr_t dma_base, uint32 chan);

/**
 * @brief: enable the dma channel, the dma will response the handshake
 *         and move the bytes.
 *
 * @param {paddr_t} dma_base is dma ip register base
 * @param {uint32} chan is dma channel num
 * @param {uint8} ps_cnt will use ps_cnt + 1 set to register
 * @return {*} enable state
 */
sint32 sdrv_dmac_enable_ch(paddr_t dma_base, uint32 chan, uint8 ps_cnt);

/**
 * @brief: disable the dma channel, the dma will not response the handshake
 *
 * @param {paddr_t} dma_base is dma ip register base
 * @param {uint32} chan is dma channel num
 * @return {disable state}
 */
sint32 sdrv_dmac_disable_ch(paddr_t dma_base, uint32 chan);

/**
 * @brief: get the channel enable state
 *
 * @param {paddr_t} dma_base is dma ip register base
 * @param {uint32} chan is dma channel num
 * @return {enable state}
 */
uint32 sdrv_dmac_get_ch_en(paddr_t dma_base, uint32 chan);

/**
 * @brief: when set dma work on some no hardware handshake,
 *         use this software handshake to trigger dma work
 *
 * @param {paddr_t} dma_base is dma ip register base
 * @param {uint32} chan_id is dma channel num
 * @return {*}
 */
void sdrv_dmac_set_ch_sw_handshake(paddr_t dma_base, uint32 chan_id);

/**
 * @brief: when set dma work on some no hardware handshake,
 *         use this software handshake to trigger dma work
 *
 * @param {paddr_t} dma_base is dma ip register base
 * @param {uint32} chan_id is dma channel num
 * @return {*}
 */
void sdrv_dmac_clr_mem2mem_ch_sw_handshake(paddr_t dma_base, uint32 chan_id);

/**
 * @brief: set the linklist first node info to mad register
 *
 * @param {paddr_t} dma_base is dma ip register base
 * @param {uint32} chan_id is dma channel num
 * @param {sdrv_dmac_lli_node_t} *item mad info
 * @return {*}
 */
void sdrv_dmac_set_mad(paddr_t dma_base, uint32 chan_id,
                       sdrv_dmac_lli_node_t *item);

/**
 * @brief: get some information form cfg and fill in other information
 *
 * @param {sdrv_dmac_ll_cfg_t} *cfg is some important information
 * @param {sdrv_dmac_lli_node_t} *item is target register info
 * @return {*}
 */
void sdrv_dmac_format_mad(sdrv_dmac_ll_cfg_t *cfg, sdrv_dmac_lli_node_t *item,
                          dma_crc_mode_e mad_crc_mode);

/**
 * @brief: dma channel support some cmd such as halt/resume/abort etc...
 *
 * @param {paddr_t} dma_base
 * @param {uint32} chan_id
 * @param {ch_ctl_stat_t} cmd
 * @return {*}
 */
uint32 sdrv_dmac_set_ch_cmd(paddr_t dma_base, uint32 chan_id,
                            ch_ctl_stat_t cmd);

/**
 * @brief: set dma channel interrupt mask
 *
 * @param {paddr_t} dma_base
 * @param {uint32} chan_id
 * @param {uint32} type
 * @return {*}
 */
void sdrv_dmac_set_int_state(paddr_t dma_base, uint32 chan_id, uint32 type);

/**
 * @brief: get the dma channel interrupt status
 *
 * @param {paddr_t} dma_base
 * @param {uint32} chan_id
 * @return {*}
 */
uint32 sdrv_dmac_get_int_state(paddr_t dma_base, uint32 chan_id);

/**
 * @brief: clear the dma channel interrupt status,
 *         if it is not cleaned up in time,
 *         part of the signal may be lost.
 *
 * @param {paddr_t} dma_base
 * @param {uint32} chan_id
 * @param {uint32} status
 * @return {*}
 */
void sdrv_dmac_clr_int(paddr_t dma_base, uint32 chan_id, uint32 status);

/**
 * @brief: parse the interrupt state
 *
 * @param {uint32} status
 * @return {*}
 */
uint32 sdrv_dmac_irq_status_handle(uint32 status);

/**
 * @brief: set the mux id for source or target ip,
 *         if mem2mem usecase not must to set.
 *
 * @param {paddr_t} dma_base
 * @param {uint32} chan_id
 * @param {uint32} mux_id
 * @return {*}
 */
void sdrv_dmac_set_ch_muxid(paddr_t dma_base, uint32 chan_id,
                            uint32 mux_id);

/**
 * @brief: set the mux id for source or target ip,
 *         if mem2mem usecase not must to set.
 *
 * @param {paddr_t} dma_base
 * @param {uint32} chan_id
 * @param {uint32} outstand value 0x0-0xf
 * @return {*}
 */
void sdrv_dmac_set_ch_rd_outstanding(paddr_t dma_base, uint32 chan_id,
                                     uint8 value);

/**
 * @brief: set the mux id for source or target ip,
 *         if mem2mem usecase not must to set.
 *
 * @param {paddr_t} dma_base
 * @param {uint32} chan_id
 * @param {uint32} outstand value 0x0-0xf
 * @return {*}
 */
void sdrv_dmac_set_ch_wr_outstanding(paddr_t dma_base, uint32 chan_id,
                                     uint8 value);

/**
 * @brief: get the dma channel transfer bytes.
 *
 * @param {paddr_t} dma_base
 * @param {uint32} chan_id
 * @return {*}
 */
uint32 sdrv_dmac_get_xfer_num(paddr_t dma_base, uint32 chan_id, uint8 need_clr);

/**
 * @brief: set the val to dma channel local register,
 *         if reg2mem mem2reg reg2dev dev2reg usecase must set it.
 *
 * @param {paddr_t} dma_base
 * @param {uint32} chan_id
 * @param {uint32} val
 * @return {*}
 */

void sdrv_dmac_set_local_val(paddr_t dma_base, uint32 chan_id, uint32 val);

/**
 * @brief: print the channels all register value
 *         high level driver may dump the channel register
 *
 * @param {paddr_t} dma_base
 * @param {uint32} chan_id
 * @return {*}
 */
void sdrv_dmac_chan_reg_dump(paddr_t dma_base, uint32 chan_id);

/**
 * @brief: abort cmd must been auto clear when dma is in enable state,
 *         this api use for clear abort register
 *         when dma channel is not in enable state but set the abort cmd
 *
 * @param {paddr_t} dma_base
 * @param {uint32} chan_id
 * @return {*}
 */
void sdrv_dmac_clr_abort_sta(paddr_t dma_base, uint32 chan_id);

/**
 * @brief: get linklist every mad trans max bytes
 *
 * @param {enum dma_loop_mode_t} lp_mode
 * @return {success return the max size, fail return -1}
 */
uint32 sdrv_dmac_get_max_block_size(enum dma_loop_mode_t lp_mode);

/**
 * @brief: get the dma control local buffer props
 *
 * @param {paddr_t} dma reg base
 * @return {dma_local_buf_t *} dma information is filled into a and returned
 */
void sdrv_dmac_get_local_buf_prop(paddr_t dma_base, dma_local_buf_t *buf_prop);

/**
 * @brief: clr dma core irq state
 *
 * @param {paddr_t} dma reg base
 * @return {void}
 */
void sdrv_dmac_core_reset_irq_sta(paddr_t dma_base);
#endif

#ifdef __cplusplus
}
#endif
