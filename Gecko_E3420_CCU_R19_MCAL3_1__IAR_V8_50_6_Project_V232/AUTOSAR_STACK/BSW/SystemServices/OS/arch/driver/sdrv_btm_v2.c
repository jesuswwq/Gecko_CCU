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
 * @file  sdrv_btm.c
 * @brief Semidrive. Btm
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <types.h>

#include "reg.h"
#include "sdrv_btm_v2.h"

/**
 * @brief sdrv btm read reg.
 *
 * @param[in] base reg base
 * @param[in] offset reg offset
 * @param[in] return reg val
 */
static inline uint32 sdrv_btm_lld_readl(uint32 base, uint32 offset)
{
    return readl(base + offset);
}

/**
 * @brief sdrv btm write reg.
 *
 * @param[in] base reg base
 * @param[in] offset reg offset
 * @param[in] val reg val
 */
static inline void sdrv_btm_lld_writel(uint32 base, uint32 offset, uint32 val)
{
    writel(val, (base + offset));
}

/**
 * @brief sdrv btm set ovf cnt.
 *
 * @param[in] tmr dev base
 * @param[in] tmr_id tmr id
 * @param[in] ovf_cnt ovf cnt value
 */
void sdrv_btm_lld_set_ovf_cnt(uint32 base, uint8 tmr_id, uint32 ovf_cnt)
{
    sdrv_btm_lld_writel(base, CNT_OVF_OFF(tmr_id), ovf_cnt);
    if (SDRV_BTM_G1 == tmr_id)
    {
        sdrv_btm_lld_writel(base, CNT_G1_UPD_FLAG_OFF, BM_CNT_G1_UPD_FLAG_OVF_WR_UPD);
    }
}

/**
 * @brief sdrv btm set cmp val.
 *
 * @param[in] tmr dev base
 * @param[in] tmr_id tmr id
 * @param[in] cmp_val cnt cmp value
 */
void sdrv_btm_lld_set_cmp_val(uint32 base, uint8 tmr_id, uint32 cmp_val)
{
    sdrv_btm_lld_writel(base, CNT_CMP_OFF(tmr_id), cmp_val);
    if (SDRV_BTM_G1 == tmr_id)
    {
        sdrv_btm_lld_writel(base, CNT_G1_UPD_FLAG_OFF, BM_CNT_G1_UPD_FLAG_CMP_WR_UPD);
    }
}

/**
 * @brief sdrv btm cnt start.
 *
 * @param[in] tmr dev base
 * @param[in] tmr_id tmr id
 * @param[in] enable check if enable
 */
void sdrv_btm_lld_cnt_en(uint32 base, uint8 tmr_id, bool enable)
{
    uint32 cnt_en;
    cnt_en = sdrv_btm_lld_readl(base, CNT_EN_OFF(tmr_id));
    if (enable)
    {
        cnt_en |= BM_CNT_EN_ENABLE;
    }
    else
    {
        cnt_en &= ~BM_CNT_EN_ENABLE;
    }
    sdrv_btm_lld_writel(base, CNT_EN_OFF(tmr_id), cnt_en);
}

/**
 * @brief sdrv btm cnt stop.
 *
 * @param[in] tmr dev base
 * @param[in] tmr_id tmr id
 * @param[in] stop check if stop
 */
void sdrv_btm_lld_cnt_stop(uint32 base, uint8 tmr_id, bool stop)
{
    uint32 cnt_en;
    cnt_en = sdrv_btm_lld_readl(base, CNT_EN_OFF(tmr_id));
    if (stop)
    {
        cnt_en |= BM_CNT_EN_STOP;
    }
    else
    {
        cnt_en &= ~BM_CNT_EN_STOP;
    }
    sdrv_btm_lld_writel(base, CNT_EN_OFF(tmr_id), cnt_en);
}

void sdrv_btm_lld_frc_rld(uint32 base, uint8 tmr_id)
{
    uint32 cnt_cfg_val;
    cnt_cfg_val = sdrv_btm_lld_readl(base, CNT_CFG_OFF(tmr_id));
    cnt_cfg_val |= BM_CNT_CFG_FRC_RLD_EN;
    sdrv_btm_lld_writel(base, CNT_CFG_OFF(tmr_id), cnt_cfg_val);
}

void sdrv_btm_lld_sw_rst(uint32 base, uint8 tmr_id)
{
    uint32 cnt_cfg_val;
    cnt_cfg_val = sdrv_btm_lld_readl(base, CNT_CFG_OFF(tmr_id));
    cnt_cfg_val |= BM_CNT_CFG_SOFT_RST;
    sdrv_btm_lld_writel(base, CNT_CFG_OFF(tmr_id), cnt_cfg_val);
}

/**
 * @brief sdrv btm cnt cfg.
 *
 * @param[in] tmr dev base
 * @param[in] tmr_id tmr id
 * @param[in] cnt_cfg counter cfg
 */
void sdrv_btm_lld_cnt_cfg(uint32 base, uint8 tmr_id, const sdrv_btm_lld_cnt_cfg_t *cnt_cfg)
{
    uint32 cnt_cfg_val;
    cnt_cfg_val = sdrv_btm_lld_readl(base, CNT_CFG_OFF(tmr_id));
    cnt_cfg_val &= ~(BM_CNT_CFG_CNT_MODE | BM_CNT_CFG_CNT_DIR | BM_CNT_CFG_CMP_USE_MODE | BM_CNT_CFG_CMP_USE_MODE |
                     BM_CNT_CFG_TERM_USE_MODE | BM_CNT_CFG_FRC_RLD_RST_CNT_EN | FM_CNT_CFG_INC_VAL | FM_CNT_CFG_SI_VAL);
    cnt_cfg_val |= ((cnt_cfg->cnt_mode << 0) | (cnt_cfg->cnt_dir << 1) | (cnt_cfg->cmp_use_mode << 2) |
                    (cnt_cfg->term_use_mode << 3));
    if (cnt_cfg->frc_rld_rst_cnt_en)
    {
        cnt_cfg_val |= BM_CNT_CFG_FRC_RLD_RST_CNT_EN;
    }
    else
    {
        cnt_cfg_val &= ~BM_CNT_CFG_FRC_RLD_RST_CNT_EN;
    }
    cnt_cfg_val |= FV_CNT_CFG_INC_VAL(cnt_cfg->inc_val);
    cnt_cfg_val |= FV_CNT_CFG_SI_VAL(cnt_cfg->si_val);
    sdrv_btm_lld_writel(base, CNT_CFG_OFF(tmr_id), cnt_cfg_val);
    if (SDRV_BTM_G1 == tmr_id)
    {
        uint32 g1_upd_flag = BM_CNT_G1_UPD_FLAG_INC_WR_UPD | BM_CNT_G1_UPD_FLAG_SI_WR_UPD;
        sdrv_btm_lld_writel(base, CNT_G1_UPD_FLAG_OFF, g1_upd_flag);
    }
}

/**
 * @brief sdrv btm cnt hold mode.
 *
 * @param[in] tmr dev base
 * @param[in] tmr_id tmr id
 * @param[in] stop check if stop
 */
void sdrv_btm_lld_set_hold_mode(uint32 base, uint8 tmr_id, sdrv_btm_cnt_hold_mode_e hold_mode)
{
    uint32 com_ctrl;
    com_ctrl = sdrv_btm_lld_readl(base, COM_CTRL_OFF);
    if (SDRV_BTM_G0 == tmr_id)
    {
        com_ctrl &= ~FM_COM_CTRL_HOLD_CAP_CFG_G0;
        com_ctrl |= FV_COM_CTRL_HOLD_CAP_CFG_G0(hold_mode);
    }
    else if (SDRV_BTM_G1 == tmr_id)
    {
        com_ctrl &= ~FM_COM_CTRL_HOLD_CAP_CFG_G1;
        com_ctrl |= FV_COM_CTRL_HOLD_CAP_CFG_G1(hold_mode);
    }
    sdrv_btm_lld_writel(base, COM_CTRL_OFF, com_ctrl);
}

/**
 * @brief sdrv btm cnt hold mode.
 *
 * @param[in] tmr dev base
 * @param[in] tmr_id tmr id
 * @param[in] stop check if stop
 */
void sdrv_btm_lld_set_g1_sync_mode(uint32 base, const sdrv_btm_lld_g1_sync_t *sync_cfg)
{
    uint32 com_ctrl;
    com_ctrl = sdrv_btm_lld_readl(base, COM_CTRL_OFF);
    com_ctrl &= ~(BM_COM_CTRL_START_SYNC | BM_COM_CTRL_FRC_RLD_SYNC | BM_COM_CTRL_STOP_SYNC);
    if (sync_cfg->start_sync)
    {
        com_ctrl |= BM_COM_CTRL_START_SYNC;
    }
    if (sync_cfg->frc_rld_sync)
    {
        com_ctrl |= BM_COM_CTRL_FRC_RLD_SYNC;
    }
    if (sync_cfg->stop_sync)
    {
        com_ctrl |= BM_COM_CTRL_STOP_SYNC;
    }
    sdrv_btm_lld_writel(base, COM_CTRL_OFF, com_ctrl);
}

/**
 * @brief sdrv btm cnt int sta en.
 *
 * @param[in] tmr dev base
 * @param[in] tmr_id tmr id
 */
void sdrv_btm_lld_set_sta_en(uint32 base, uint8 tmr_id)
{
    uint32 int_sta_en;
    int_sta_en = sdrv_btm_lld_readl(base, INT_STAT_EN_OFF);
    if (SDRV_BTM_G0 == tmr_id)
    {
        int_sta_en |= BM_INT_STAT_EN_OE_G0;
    }
    else if (SDRV_BTM_G1 == tmr_id)
    {
        int_sta_en |= BM_INT_STAT_EN_OE_G1;
    }
    sdrv_btm_lld_writel(base, INT_STAT_EN_OFF, int_sta_en);
}

/**
 * @brief sdrv btm cnt int sig en.
 *
 * @param[in] tmr dev base
 * @param[in] tmr_id tmr id
 */
void sdrv_btm_lld_set_sig_en(uint32 base, uint8 tmr_id)
{
    uint32 int_sig_en;
    int_sig_en = sdrv_btm_lld_readl(base, BTM_INT_SIG_EN_OFF);
    if (SDRV_BTM_G0 == tmr_id)
    {
        int_sig_en |= BM_INT_SIG_EN_OE_G0 | BM_INT_SIG_EN_CE_G0;
    }
    else if (SDRV_BTM_G1 == tmr_id)
    {
        int_sig_en |= BM_INT_SIG_EN_OE_G1 | BM_INT_SIG_EN_CE_G1;
    }
    sdrv_btm_lld_writel(base, BTM_INT_SIG_EN_OFF, int_sig_en);
}

/**
 * @brief sdrv btm set int sta.
 *
 * @param[in] tmr dev base
 * @param[in] int_sta sta
 */
void sdrv_btm_lld_set_int_sta(uint32 base, uint32 int_sta)
{
    sdrv_btm_lld_writel(base, INT_STAT_OFF, int_sta);
}

/**
 * @brief sdrv btm get int sta.
 *
 * @param[in] tmr dev base
 * @return int sta
 */
uint32 sdrv_btm_lld_get_int_sta(uint32 base)
{
    return sdrv_btm_lld_readl(base, INT_STAT_OFF);
}

/**
 * @brief sdrv btm get cnt val.
 *
 * @param[in] tmr dev base
 * @param[in] tmr_id tmr id
 * @return counter value
 */
uint32 sdrv_btm_lld_get_cnt_val(uint32 base, uint8 tmr_id)
{
    return sdrv_btm_lld_readl(base, CNT_OFF(tmr_id));
}

/**
 * @brief sdrv btm get hold val.
 *
 * @param[in] tmr dev base
 * @param[in] tmr_id tmr id
 * @return hold value
 */
uint32 sdrv_btm_lld_get_hold_val(uint32 base, uint8 tmr_id)
{
    return sdrv_btm_lld_readl(base, HOLD_OFF(tmr_id));
}

/**
 * @brief sdrv btm cnt init.
 *
 * @param[in] tmr dev base
 * @param[in] tmr_id tmr id
 * @param[in] cnt_cfg counter cfg
 */
void sdrv_btm_lld_init(uint32 base, uint8 tmr_id, const sdrv_btm_lld_cnt_cfg_t *cnt_cfg)
{
    /* disable the cnt */
    sdrv_btm_lld_cnt_en(base, tmr_id, false);
    /* reset the cnt value */
    sdrv_btm_lld_sw_rst(base, tmr_id);
    /* clear all interrupt value */
    sdrv_btm_lld_writel(base, INT_STAT_EN_OFF, 0x0000);
    sdrv_btm_lld_writel(base, BTM_INT_SIG_EN_OFF, 0x0000);

    /* set the cnt cfg */
    sdrv_btm_lld_cnt_cfg(base, tmr_id, cnt_cfg);
}

/**
 * @brief sdrv btm timer start.
 *
 * @param[in] tmr dev base
 * @param[in] tmr_id tmr id
 * @param[in] cnt_cfg counter value
 */
void sdrv_btm_lld_timer_start(uint32 base, uint8 tmr_id, uint32 count)
{
    /* set interrupt mask */
    sdrv_btm_lld_set_sta_en(base, tmr_id);
    sdrv_btm_lld_set_sig_en(base, tmr_id);
    /* set ovf value */
    sdrv_btm_lld_set_ovf_cnt(base, tmr_id, count);
    /* enable the cnt */
    sdrv_btm_lld_cnt_en(base, tmr_id, true);
}

/**
 * @brief sdrv btm timer stop.
 *
 * @param[in] tmr dev base
 * @param[in] tmr_id tmr id
 * @param[in] cnt_cfg counter value
 */
void sdrv_btm_lld_timer_stop(uint32 base, uint8 tmr_id)
{
    /* disable the cnt */
    sdrv_btm_lld_cnt_en(base, tmr_id, false);
    /* clear all interrupt value */
    sdrv_btm_lld_writel(base, INT_STAT_EN_OFF, 0x0000);
    sdrv_btm_lld_writel(base, BTM_INT_SIG_EN_OFF, 0x0000);
}

#ifdef __cplusplus
}
#endif
