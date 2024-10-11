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
 * @file  sdrv_btm_hw.h
 * @brief Semidrive. Btm
 */

#ifndef DRV_LLD_SDRV_BTM_H
#define DRV_LLD_SDRV_BTM_H

#include <types.h>
#include <__compiler.h>

#ifndef ASSEMBLY

#define BTM_COM_CTRL_OFF 0x0U

#define BTM_FM_COM_CTRL_HOLD_CAP_CFG_G1 (0x3U << 5U)
#define BTM_FV_COM_CTRL_HOLD_CAP_CFG_G1(v) \
    (((v) << 5U) & BTM_FM_COM_CTRL_HOLD_CAP_CFG_G1)
#define BTM_GFV_COM_CTRL_HOLD_CAP_CFG_G1(v) \
    (((v)&BTM_FM_COM_CTRL_HOLD_CAP_CFG_G1) >> 5U)

#define BTM_BM_COM_CTRL_STOP_SYNC (0x01U << 4U)

#define BTM_BM_COM_CTRL_FRC_RLD_SYNC (0x01U << 3U)

#define BTM_BM_COM_CTRL_START_SYNC (0x01U << 2U)

#define BTM_FM_COM_CTRL_HOLD_CAP_CFG_G0 (0x3U << 0U)
#define BTM_FV_COM_CTRL_HOLD_CAP_CFG_G0(v) \
    (((v) << 0U) & BTM_FM_COM_CTRL_HOLD_CAP_CFG_G0)
#define BTM_GFV_COM_CTRL_HOLD_CAP_CFG_G0(v) \
    (((v)&BTM_FM_COM_CTRL_HOLD_CAP_CFG_G0) >> 0U)

#define BTM_CNT_EN_OFF(id) (0x4 + (id)*0x20)

#define BTM_BM_CNT_EN_STOP (0x01U << 1U)

#define BTM_BM_CNT_EN_ENABLE (0x01U << 0U)

#define BTM_CNT_CFG_OFF(id) (0x8 + (id)*0x20)

#define BTM_FM_CNT_CFG_SI_VAL (0xffU << 24U)
#define BTM_FV_CNT_CFG_SI_VAL(v) \
    (((v) << 24U) & BTM_FM_CNT_CFG_SI_VAL)
#define BTM_GFV_CNT_CFG_SI_VAL(v) \
    (((v)&BTM_FM_CNT_CFG_SI_VAL) >> 24U)

#define BTM_FM_CNT_CFG_INC_VAL (0xffU << 16U)
#define BTM_FV_CNT_CFG_INC_VAL(v) \
    (((v) << 16U) & BTM_FM_CNT_CFG_INC_VAL)
#define BTM_GFV_CNT_CFG_INC_VAL(v) \
    (((v)&BTM_FM_CNT_CFG_INC_VAL) >> 16U)

#define BTM_BM_CNT_CFG_SOFT_RST (0x01U << 6U)

#define BTM_BM_CNT_CFG_FRC_RLD_RST_CNT_EN (0x01U << 5U)

#define BTM_BM_CNT_CFG_FRC_RLD_EN (0x01U << 4U)

#define BTM_BM_CNT_CFG_TERM_USE_MODE (0x01U << 3U)

#define BTM_BM_CNT_CFG_CMP_USE_MODE (0x01U << 2U)

#define BTM_BM_CNT_CFG_CNT_DIR (0x01U << 1U)

#define BTM_BM_CNT_CFG_CNT_MODE (0x01U << 0U)

#define BTM_CNT_OVF_OFF(id) (0xc + (id)*0x20)

#define BTM_FM_CNT_OVF_VAL (0xffffffffU << 0U)
#define BTM_FV_CNT_OVF_VAL(v) \
    (((v) << 0U) & BTM_FM_CNT_OVF_VAL)
#define BTM_GFV_CNT_OVF_VAL(v) \
    (((v)&BTM_FM_CNT_OVF_VAL) >> 0U)

#define BTM_CNT_CMP_OFF(id) (0x10 + (id)*0x20)

#define BTM_FM_CNT_CMP_VAL (0xffffffffU << 0U)
#define BTM_FV_CNT_CMP_VAL(v) \
    (((v) << 0U) & BTM_FM_CNT_CMP_VAL)
#define BTM_GFV_CNT_CMP_VAL(v) \
    (((v)&BTM_FM_CNT_CMP_VAL) >> 0U)

#define BTM_CNT_OFF(id) (0x14 + (id)*0x20)

#define BTM_FM_CNT_VAL (0xffffffffU << 0U)
#define BTM_FV_CNT_VAL(v) \
    (((v) << 0U) & BTM_FM_CNT_VAL)
#define BTM_GFV_CNT_VAL(v) \
    (((v)&BTM_FM_CNT_VAL) >> 0U)

#define BTM_HOLD_OFF(id) (0x18 + (id)*0x24)

#define BTM_FM_HOLD_CNT (0xffffffffU << 0U)
#define BTM_FV_HOLD_CNT(v) \
    (((v) << 0U) & BTM_FM_HOLD_CNT)
#define BTM_GFV_HOLD_CNT(v) \
    (((v)&BTM_FM_HOLD_CNT) >> 0U)

#define BTM_CNT_G1_UPD_FLAG_OFF 0x38U

#define BTM_BM_CNT_G1_UPD_FLAG_INC_WR_UPD (0x01U << 3U)

#define BTM_BM_CNT_G1_UPD_FLAG_SI_WR_UPD (0x01U << 2U)

#define BTM_BM_CNT_G1_UPD_FLAG_CMP_WR_UPD (0x01U << 1U)

#define BTM_BM_CNT_G1_UPD_FLAG_OVF_WR_UPD (0x01U << 0U)

#define BTM_INT_STAT_OFF 0x40U

#define BTM_BM_INT_STAT_OE_G1 (0x01U << 3U)

#define BTM_BM_INT_STAT_OE_G0 (0x01U << 2U)

#define BTM_BM_INT_STAT_CE_G1 (0x01U << 1U)

#define BTM_BM_INT_STAT_CE_G0 (0x01U << 0U)

#define BTM_INT_STAT_EN_OFF 0x44U

#define BTM_BM_INT_STAT_EN_OE_G1 (0x01U << 3U)

#define BTM_BM_INT_STAT_EN_OE_G0 (0x01U << 2U)

#define BTM_BM_INT_STAT_EN_CE_G1 (0x01U << 1U)

#define BTM_BM_INT_STAT_EN_CE_G0 (0x01U << 0U)

#define BTM_INT_SIG_EN_OFF 0x48U

#define BTM_BM_INT_SIG_EN_OE_G1 (0x01U << 3U)

#define BTM_BM_INT_SIG_EN_OE_G0 (0x01U << 2U)

#define BTM_BM_INT_SIG_EN_CE_G1 (0x01U << 1U)

#define BTM_BM_INT_SIG_EN_CE_G0 (0x01U << 0U)

#define BTM_FUSA_COR_ERR_INT_STAT_OFF 0x4cU

#define BTM_BM_FUSA_COR_ERR_INT_STAT_PWDATA_COR_ERR (0x01U << 0U)

#define BTM_FUSA_COR_ERR_INT_STAT_EN_OFF 0x50U

#define BTM_BM_FUSA_COR_ERR_INT_STAT_EN_PWDATA_COR_ERR (0x01U << 0U)

#define BTM_FUSA_COR_ERR_INT_SIG_EN_OFF 0x54U

#define BTM_BM_FUSA_COR_ERR_INT_SIG_EN_PWDATA_COR_ERR (0x01U << 0U)

#define BTM_FUSA_UNCOR_ERR_INT_STAT_OFF 0x58U

#define BTM_BM_FUSA_UNCOR_ERR_INT_STAT_G1_CNT_PAR_ERR (0x01U << 13U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_STAT_CFG_VAL_PAR_ERR (0x01U << 12U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_STAT_ASYNC_2XTAL24M_PAR_ERR (0x01U << 11U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_STAT_ASYNC_2APB_PAR_ERR (0x01U << 10U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_STAT_LSP_G0_ERR (0x01U << 9U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_STAT_LSP_XTAL24M_ERR (0x01U << 8U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_STAT_LSP_APB_SLV_CMP_ERR (0x01U << 7U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_STAT_LSP_IRQ_CMP_ERR (0x01U << 6U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_STAT_LSP_G1_ERR (0x01U << 5U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_STAT_INPUT_ERR (0x01U << 4U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_STAT_P_CTL_UNCOR_ERR (0x01U << 3U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_STAT_PADDR_UNCOR_ERR (0x01U << 2U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_STAT_PWDATA_FATAL_ERR (0x01U << 1U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_STAT_PWDATA_UNCOR_ERR (0x01U << 0U)

#define BTM_FUSA_UNCOR_ERR_INT_STAT_EN_OFF 0x5cU

#define BTM_BM_FUSA_UNCOR_ERR_INT_STAT_EN_G1_CNT_PAR_ERR (0x01U << 13U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_STAT_EN_CFG_VAL_PAR_ERR (0x01U << 12U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_STAT_EN_ASYNC_2XTAL24M_PAR_ERR (0x01U << 11U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_STAT_EN_ASYNC_2APB_PAR_ERR (0x01U << 10U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_STAT_EN_LSP_G0_ERR (0x01U << 9U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_STAT_EN_LSP_XTAL24M_ERR (0x01U << 8U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_STAT_EN_LSP_APB_SLV_CMP_ERR (0x01U << 7U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_STAT_EN_LSP_IRQ_CMP_ERR (0x01U << 6U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_STAT_EN_LSP_G1_ERR (0x01U << 5U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_STAT_EN_INPUT_ERR (0x01U << 4U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_STAT_EN_P_CTL_UNCOR_ERR (0x01U << 3U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_STAT_EN_PADDR_UNCOR_ERR (0x01U << 2U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_STAT_EN_PWDATA_FATAL_ERR (0x01U << 1U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_STAT_EN_PWDATA_UNCOR_ERR (0x01U << 0U)

#define BTM_FUSA_UNCOR_ERR_INT_SIG_EN_OFF 0x60U

#define BTM_BM_FUSA_UNCOR_ERR_INT_SIG_EN_G1_CNT_PAR_ERR (0x01U << 13U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_SIG_EN_CFG_VAL_PAR_ERR (0x01U << 12U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_SIG_EN_ASYNC_2XTAL24M_PAR_ERR (0x01U << 11U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_SIG_EN_ASYNC_2APB_PAR_ERR (0x01U << 10U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_SIG_EN_LSP_G0_ERR (0x01U << 9U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_SIG_EN_LSP_XTAL24M_ERR (0x01U << 8U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_SIG_EN_LSP_APB_SLV_CMP_ERR (0x01U << 7U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_SIG_EN_LSP_IRQ_CMP_ERR (0x01U << 6U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_SIG_EN_LSP_G1_ERR (0x01U << 5U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_SIG_EN_INPUT_ERR (0x01U << 4U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_SIG_EN_P_CTL_UNCOR_ERR (0x01U << 3U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_SIG_EN_PADDR_UNCOR_ERR (0x01U << 2U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_SIG_EN_PWDATA_FATAL_ERR (0x01U << 1U)

#define BTM_BM_FUSA_UNCOR_ERR_INT_SIG_EN_PWDATA_UNCOR_ERR (0x01U << 0U)

#define BTM_PWDATA_OFF 0x64U

#define BTM_FM_PWDATA_INJ (0xffffffffU << 0U)
#define BTM_FV_PWDATA_INJ(v) \
    (((v) << 0U) & BTM_FM_PWDATA_INJ)
#define BTM_GFV_PWDATA_INJ(v) \
    (((v)&BTM_FM_PWDATA_INJ) >> 0U)

#define BTM_PWCODE_OFF 0x68U

#define BTM_FM_PWCODE_INJ (0x7fU << 0U)
#define BTM_FV_PWCODE_INJ(v) \
    (((v) << 0U) & BTM_FM_PWCODE_INJ)
#define BTM_GFV_PWCODE_INJ(v) \
    (((v)&BTM_FM_PWCODE_INJ) >> 0U)

#define BTM_IRQ_ERR_OFF 0x6cU

#define BTM_BM_IRQ_ERR_FUSA_UNCOR_INJ (0x01U << 2U)

#define BTM_BM_IRQ_ERR_FUSA_COR_INJ (0x01U << 1U)

#define BTM_BM_IRQ_ERR_INT_INJ (0x01U << 0U)

#define BTM_LSP_OFF 0x70U

#define BTM_FM_LSP_INJ_BIT (0xffU << 8U)
#define BTM_FV_LSP_INJ_BIT(v) \
    (((v) << 8U) & BTM_FM_LSP_INJ_BIT)
#define BTM_GFV_LSP_INJ_BIT(v) \
    (((v)&BTM_FM_LSP_INJ_BIT) >> 8U)

#define BTM_FM_LSP_INJ_SEL (0x7U << 1U)
#define BTM_FV_LSP_INJ_SEL(v) \
    (((v) << 1U) & BTM_FM_LSP_INJ_SEL)
#define BTM_GFV_LSP_INJ_SEL(v) \
    (((v)&BTM_FM_LSP_INJ_SEL) >> 1U)

#define BTM_BM_LSP_INJ_EN (0x01U << 0U)

#define BTM_SELFTEST_MODE_OFF 0x74U

#define BTM_BM_SELFTEST_MODE_EN (0x01U << 0U)

__BEGIN_CDECLS

typedef enum {
    SDRV_BTM_G0,
    SDRV_BTM_G1,
    SDRV_BTM_NUM
} sdrv_btm_cnt_id_e;

typedef enum {
    SDRV_BTM_ONESHOT_MODE,
    SDRV_BTM_CONTINOUS_MODE
} sdrv_btm_cnt_mode_e;

typedef enum {
    SDRV_BTM_CNT_UP,
    SDRV_BTM_CNT_DOWN
} sdrv_btm_cnt_dir_e;

typedef enum {
    SDRV_BTM_DIRECT,
    SDRV_BTM_SHADOW
} sdrv_btm_cnt_use_mode_e;

typedef enum {
    SDRV_BTM_HOLD_NO_CNT,
    SDRV_BTM_HOLD_SELF_ON_G0,
    SDRV_BTM_HOLD_SELF_ON_G1,
    SDRV_BTM_HOLD_BOTH_CNT
} sdrv_btm_cnt_hold_mode_e;

typedef struct sdrv_btm_hw_cnt_cfg {
    uint8 si_val;
    uint8 inc_val;
    bool frc_rld_rst_cnt_en;
    sdrv_btm_cnt_use_mode_e term_use_mode;
    sdrv_btm_cnt_use_mode_e cmp_use_mode;
    sdrv_btm_cnt_dir_e cnt_dir;
    sdrv_btm_cnt_mode_e cnt_mode;
} sdrv_btm_hw_cnt_cfg_t;

typedef struct sdrv_btm_hw_g1_sync {
    bool stop_sync;
    bool frc_rld_sync;
    bool start_sync;
} sdrv_btm_hw_g1_sync_t;

void sdrv_btm_hw_set_ovf_cnt(uint32 base, uint8 tmr_id, uint32 ovf_cnt);

void sdrv_btm_hw_set_cmp_val(uint32 base, uint8 tmr_id, uint32 cmp_val);

void sdrv_btm_hw_cnt_en(uint32 base, uint8 tmr_id, bool enable);

void sdrv_btm_hw_cnt_stop(uint32 base, uint8 tmr_id, bool stop);

void sdrv_btm_hw_cnt_cfg(uint32 base, uint8 tmr_id, const sdrv_btm_hw_cnt_cfg_t *cnt_cfg);

void sdrv_btm_hw_set_hold_mode(uint32 base, uint8 tmr_id, sdrv_btm_cnt_hold_mode_e hold_mode);

void sdrv_btm_hw_set_g1_sync_mode(uint32 base, const sdrv_btm_hw_g1_sync_t *sync_cfg);

void sdrv_btm_hw_set_sta_en(uint32 base, uint8 tmr_id);

void sdrv_btm_hw_set_sig_en(uint32 base, uint8 tmr_id);

void sdrv_btm_hw_compare_int_en(uint32 base, uint8 tmr_id, bool enable);

void sdrv_btm_hw_set_int_sta(uint32 base, uint32 int_sta);

void sdrv_btm_hw_init(uint32 base, uint8 tmr_id, const sdrv_btm_hw_cnt_cfg_t *cnt_cfg);

void sdrv_btm_hw_timer_start(uint32 base, uint8 tmr_id, uint32 count);

void sdrv_btm_hw_timer_stop(uint32 base, uint8 tmr_id);

uint32 sdrv_btm_hw_get_int_sta(uint32 base);

uint32 sdrv_btm_hw_get_cnt_val(uint32 base, uint8 tmr_id);

uint32 sdrv_btm_hw_get_hold_val(uint32 base, uint8 tmr_id);

void sdrv_btm_hw_frc_rld(uint32 base, uint8 tmr_id);

void sdrv_btm_hw_sw_rst(uint32 base, uint8 tmr_id);

uint32 sdrv_btm_hw_readl(uint32 base, uint32 offset);

void sdrv_btm_hw_writel(uint32 base, uint32 offset, uint32 val);

__END_CDECLS

#endif

#endif
