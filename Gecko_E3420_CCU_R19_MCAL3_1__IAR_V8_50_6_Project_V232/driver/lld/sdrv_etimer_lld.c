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
 * @file  sdrv_etimer_lld.c
 * @brief Semidrive. Etimer
 */

#include "types.h"

#include "sdrv_etimer_lld.h"
#include "Mcu.h"
#include "RegHelper.h"

static uint8 get_etimer_version(void)
{
#ifdef SEMIDRIVE_E3_SERIES
    return Mcu_GetChipVersion();
#else
    return  1;
#endif
}

/**
 * @brief sdrv etimer read reg.
 *
 * @param[in] base reg base
 * @param[in] offset reg offset
 * @return return reg val
 */
static inline uint32 sdrv_etimer_lld_readl(uint32 base, uint32 offset)
{
    return readl(base + offset);
}

/**
 * @brief sdrv etimer write reg.
 *
 * @param[in] base reg base
 * @param[in] offset reg offset
 * @param[in] val reg val
 */
static inline void sdrv_etimer_lld_writel(uint32 base, uint32 offset,
                                          uint32 val)
{
    writel(val, (base + offset));
}

void sdrv_etimer_lld_clk_cfg(uint32 base, clk_set_t *cfg)
{
    uint32 clk_set = 0;
    clk_set = ETMR_FV_TIM_CLK_CONFIG_DIV_NUM(cfg->div_num);
    clk_set |= ETMR_FV_TIM_CLK_CONFIG_SRC_CLK_SEL(cfg->src_clk_sel);
    clk_set |= ETMR_BM_TIM_CLK_CONFIG_CLK_CHANGE_UPD;
    sdrv_etimer_lld_writel(base, ETMR_TIM_CLK_CONFIG_OFF, clk_set);
    while (sdrv_etimer_lld_readl(base, ETMR_TIM_CLK_CONFIG_OFF) &
           ETMR_BM_TIM_CLK_CONFIG_CLK_CHANGE_UPD)
        ;
}

void sdrv_etimer_lld_clk_mon_en(uint32 base, bool enable)
{
    uint32 clk_mon;
    clk_mon = ETMR_BM_CLK_MON_EN_CMP_SET;
    enable ? (clk_mon |= ETMR_BM_CLK_MON_EN_EN_P)
           : (clk_mon |= ETMR_BM_CLK_MON_EN_EN_N);
    sdrv_etimer_lld_writel(base, ETMR_CLK_MON_EN_OFF, clk_mon);
}

static void sdrv_etimer_lld_basic_cnt_upd(uint32 base,
                                          sdrv_etimer_cnt_id_e cnt_x,
                                          bool init_flag, bool ovf_flag)
{
    if (cnt_x > SDRV_ETIMR_CNT_G1) {
        return;
    }
    uint32 cnt_cfg;
    cnt_cfg = sdrv_etimer_lld_readl(base, ETMR_CNT_CFG_OFF(cnt_x));
    if (init_flag) {
        cnt_cfg |= ETMR_BM_CNT_CFG_INIT_UPD;
    }
    if (ovf_flag) {
        cnt_cfg |= ETMR_BM_CNT_CFG_OVF_UPD;
    }
    sdrv_etimer_lld_writel(base, ETMR_CNT_CFG_OFF(cnt_x), cnt_cfg);
}

static void sdrv_etimer_lld_local_cnt_upd(uint32 base,
                                          sdrv_etimer_cnt_id_e cnt_x,
                                          bool init_flag, bool ovf_flag)
{
    if (cnt_x <= SDRV_ETIMR_CNT_G1) {
        return;
    }
    uint32 lcnt_cfg;
    lcnt_cfg = sdrv_etimer_lld_readl(base, ETMR_CNT_CFG_OFF(cnt_x));
    if (init_flag) {
        lcnt_cfg |= ETMR_BM_LCNT_CFG_INIT_UPD;
    }
    if (ovf_flag) {
        lcnt_cfg |= ETMR_BM_LCNT_CFG_OVF_UPD;
    }
    sdrv_etimer_lld_writel(base, ETMR_CNT_CFG_OFF(cnt_x), lcnt_cfg);
}

void sdrv_etimer_lld_cnt_upd(uint32 base, sdrv_etimer_cnt_id_e cnt_x,
                             bool init_flag, bool ovf_flag)
{

    switch (cnt_x) {
    case SDRV_ETIMR_CNT_G0:
    case SDRV_ETIMR_CNT_G1:
        sdrv_etimer_lld_basic_cnt_upd(base, cnt_x, init_flag, ovf_flag);
        break;
    case SDRV_ETIMR_LCNT_A:
    case SDRV_ETIMR_LCNT_B:
    case SDRV_ETIMR_LCNT_C:
    case SDRV_ETIMR_LCNT_D:
        sdrv_etimer_lld_local_cnt_upd(base, cnt_x, init_flag, ovf_flag);
        break;
    default:
        return;
    }
    uint32 cnt_cfg = sdrv_etimer_lld_readl(base, ETMR_CNT_CFG_OFF(cnt_x));
    /* Wait until the update flag takes effect */
    while ((cnt_cfg & ETMR_BM_CNT_CFG_INIT_UPD) ||
           (cnt_cfg & ETMR_BM_CNT_CFG_OVF_UPD)) {
        cnt_cfg = sdrv_etimer_lld_readl(base, ETMR_CNT_CFG_OFF(cnt_x));
    }
}

void sdrv_etimer_lld_cnt_ovf(uint32 base, sdrv_etimer_cnt_id_e cnt_x,
                             uint32 val)
{
    sdrv_etimer_lld_writel(base, ETMR_CNT_OVF_OFF(cnt_x), val);
    sdrv_etimer_lld_cnt_upd(base, cnt_x, false, true);
}

void sdrv_etimer_lld_cnt_init(uint32 base, sdrv_etimer_cnt_id_e cnt_x,
                              uint32 val)
{
    sdrv_etimer_lld_writel(base, ETMR_CNT_INIT_OFF(cnt_x), val);
    sdrv_etimer_lld_cnt_upd(base, cnt_x, true, false);
}

void sdrv_etimer_lld_cnt_en(uint32 base, sdrv_etimer_cnt_id_e cnt_x,
                            bool enable)
{
    sdrv_etimer_lld_writel(base, ETMR_CNT_EN_OFF(cnt_x), enable);
}

uint32 sdrv_etimer_lld_get_cnt_value(uint32 base,
                                       sdrv_etimer_cnt_id_e cnt_x)
{
    uint32 cnt_value = 0;
    cnt_value = sdrv_etimer_lld_readl(base, ETMR_CNT_OFF(cnt_x));
    return cnt_value;
}

uint32 sdrv_etimer_lld_get_cpt0_cnt0(uint32 base,
                                       sdrv_etimer_chn_id_e etimer_id)
{
    uint32 cpt0_cnt0_value = 0;
    cpt0_cnt0_value =
        sdrv_etimer_lld_readl(base, ETMR_CPT_CPT0_CNT0_OFF(etimer_id));
    return cpt0_cnt0_value;
}

uint32 sdrv_etimer_lld_get_cpt0_cnt1(uint32 base,
                                       sdrv_etimer_chn_id_e etimer_id)
{
    uint32 cpt0_cnt1_value = 0;
    cpt0_cnt1_value =
        sdrv_etimer_lld_readl(base, ETMR_CPT_CPT0_CNT1_OFF(etimer_id));
    return cpt0_cnt1_value;
}

uint32 sdrv_etimer_lld_get_cpt1_cnt0(uint32 base,
                                       sdrv_etimer_chn_id_e etimer_id)
{
    uint32 cpt1_cnt0_value = 0;
    cpt1_cnt0_value =
        sdrv_etimer_lld_readl(base, ETMR_CPT_CPT1_CNT0_OFF(etimer_id));
    return cpt1_cnt0_value;
}

uint32 sdrv_etimer_lld_get_cpt1_cnt1(uint32 base,
                                       sdrv_etimer_chn_id_e etimer_id)
{
    uint32 cpt1_cnt1_value = 0;
    cpt1_cnt1_value =
        sdrv_etimer_lld_readl(base, ETMR_CPT_CPT1_CNT1_OFF(etimer_id));
    return cpt1_cnt1_value;
}

void sdrv_etimer_lld_cnt_frc_rld(uint32 base, sdrv_etimer_cnt_id_e cnt_x)
{
    uint32 cnt_cfg;
    cnt_cfg = sdrv_etimer_lld_readl(base, ETMR_CNT_CFG_OFF(cnt_x));
    cnt_cfg |= ETMR_BM_CNT_CFG_FRC_RLD;
    sdrv_etimer_lld_writel(base, ETMR_CNT_CFG_OFF(cnt_x), cnt_cfg);
}

void sdrv_etimer_lld_lcnt_sig_en(uint32 base, sdrv_etimer_cnt_id_e cnt_x,
                                 bool enable)
{
    if (cnt_x <= SDRV_ETIMR_CNT_G1) {
        return;
    }
    uint32 lcnt_cfg;
    lcnt_cfg = sdrv_etimer_lld_readl(base, ETMR_CNT_CFG_OFF(cnt_x));
    enable ? (lcnt_cfg |= ETMR_BM_LCNT_CFG_SIG_EN)
           : (lcnt_cfg &= ~ETMR_BM_LCNT_CFG_SIG_EN);
    sdrv_etimer_lld_writel(base, ETMR_CNT_CFG_OFF(cnt_x), lcnt_cfg);
}

void sdrv_etimer_lld_basic_cnt_cfg(uint32 base, sdrv_etimer_cnt_id_e cnt_x,
                                   basic_cnt_config_t *cfg)
{
    if (cnt_x > SDRV_ETIMR_CNT_G1) {
        return;
    }
    uint32 cnt_cfg = 0;
    (cfg->con_mode) ? (cnt_cfg |= ETMR_BM_CNT_CFG_CON_MODE)
                    : (cnt_cfg &= ~ETMR_BM_CNT_CFG_CON_MODE);
    (cfg->ovf_rst_dis) ? (cnt_cfg |= ETMR_BM_CNT_CFG_OVF_RST_DIS)
                       : (cnt_cfg &= ~ETMR_BM_CNT_CFG_OVF_RST_DIS);
    (cfg->ce_en) ? (cnt_cfg |= ETMR_BM_CNT_CFG_CE_EN)
                 : (cnt_cfg &= ~ETMR_BM_CNT_CFG_CE_EN);
    cnt_cfg |= ETMR_FV_CNT_CFG_INTERVAL(cfg->interval);
    cnt_cfg |= ETMR_FV_CNT_CFG_CLR_TRIG_SEL(cfg->clr_trig_sel);
    cnt_cfg |= ETMR_FV_CNT_CFG_SET_TRIG_SEL(cfg->set_trig_sel);
    cnt_cfg |= ETMR_FV_CNT_CFG_SET_UPD_SEL(cfg->set_upd_sel);
    if ((cnt_x == SDRV_ETIMR_CNT_G0) && (cfg->cascade_mode)) {
        cnt_cfg |= ETMR_BM_CNT_G0_CFG_CASCADE_MODE;
    }
    (cfg->frc_rld) ? (cnt_cfg |= ETMR_BM_CNT_CFG_FRC_RLD)
                   : (cnt_cfg &= ~ETMR_BM_CNT_CFG_FRC_RLD);
    sdrv_etimer_lld_writel(base, ETMR_CNT_CFG_OFF(cnt_x), cnt_cfg);
}

void sdrv_etimer_lld_local_cnt_cfg(uint32 base, sdrv_etimer_cnt_id_e cnt_x,
                                   local_cnt_config_t *cfg)
{
    if (cnt_x <= SDRV_ETIMR_CNT_G1) {
        return;
    }
    uint32 lcnt_cfg = 0;
    (cfg->con_mode) ? (lcnt_cfg |= ETMR_BM_LCNT_CFG_CON_MODE)
                    : (lcnt_cfg &= ~ETMR_BM_LCNT_CFG_CON_MODE);
    (cfg->no_stop_ovf_mode) ? (lcnt_cfg |= ETMR_BM_LCNT_CFG_NO_STOP_OVF_MODE)
                            : (lcnt_cfg &= ~ETMR_BM_LCNT_CFG_NO_STOP_OVF_MODE);
    lcnt_cfg |= ETMR_FV_LCNT_CFG_SET_TRIG_SEL(cfg->set_trig_sel);
    lcnt_cfg |= ETMR_FV_LCNT_CFG_SET_UPD_SEL(cfg->set_upd_sel);
    lcnt_cfg |= ETMR_FV_LCNT_CFG_CLR_TRIG_SEL(cfg->clr_trig_sel);
    lcnt_cfg |= ETMR_FV_LCNT_CFG_INTERVAL(cfg->interval);
    lcnt_cfg |= ETMR_FV_LCNT_CFG_SIG_TRIG_SEL(cfg->sig_trig_sel);
    (cfg->ce_en) ? (lcnt_cfg |= ETMR_BM_LCNT_CFG_CE_EN)
                 : (lcnt_cfg &= ~ETMR_BM_LCNT_CFG_CE_EN);
    (cfg->cpt0_clr_en) ? (lcnt_cfg |= ETMR_BM_LCNT_CFG_CPT0_CLR_EN)
                       : (lcnt_cfg &= ~ETMR_BM_LCNT_CFG_CPT0_CLR_EN);
    (cfg->cpt1_clr_en) ? (lcnt_cfg |= ETMR_BM_LCNT_CFG_CPT1_CLR_EN)
                       : (lcnt_cfg &= ~ETMR_BM_LCNT_CFG_CPT1_CLR_EN);
    (cfg->start_by_first_cpt)
        ? (lcnt_cfg |= ETMR_BM_LCNT_CFG_START_BY_FIRST_CPT)
        : (lcnt_cfg &= ~ETMR_BM_LCNT_CFG_START_BY_FIRST_CPT);
    (cfg->sig_en) ? (lcnt_cfg |= ETMR_BM_LCNT_CFG_SIG_EN)
                  : (lcnt_cfg &= ~ETMR_BM_LCNT_CFG_SIG_EN);
    (cfg->delta_time_en) ? (lcnt_cfg |= ETMR_BM_LCNT_CFG_DELTA_TIME_EN)
                         : (lcnt_cfg &= ~ETMR_BM_LCNT_CFG_DELTA_TIME_EN);
    (cfg->ovf_rst_dis) ? (lcnt_cfg |= ETMR_BM_LCNT_CFG_OVF_RST_DIS)
                       : (lcnt_cfg &= ~ETMR_BM_LCNT_CFG_OVF_RST_DIS);
    (cfg->frc_rld) ? (lcnt_cfg |= ETMR_BM_LCNT_CFG_FRC_RLD)
                   : (lcnt_cfg &= ~ETMR_BM_LCNT_CFG_FRC_RLD);
    sdrv_etimer_lld_writel(base, ETMR_CNT_CFG_OFF(cnt_x), lcnt_cfg);
}

void sdrv_etimer_lld_int_en(uint32 base, uint32 bit_mask, bool enable)
{
    uint32 val_sta = sdrv_etimer_lld_readl(base, ETMR_INT_STA_EN_OFF);
    uint32 val_sig = sdrv_etimer_lld_readl(base, ETMR_INT_SIG_EN_OFF);

    val_sta = enable ? (val_sta | bit_mask) : (val_sta & (~bit_mask));
    val_sig = enable ? (val_sig | bit_mask) : (val_sig & (~bit_mask));

    sdrv_etimer_lld_writel(base, ETMR_INT_STA_EN_OFF, val_sta);
    sdrv_etimer_lld_writel(base, ETMR_INT_SIG_EN_OFF, val_sig);
}

void sdrv_etimer_lld_int_enable(uint32 base, uint32 int_sel)
{
    sdrv_etimer_lld_writel(base, ETMR_INT_STA_EN_OFF, int_sel);
    sdrv_etimer_lld_writel(base, ETMR_INT_SIG_EN_OFF, int_sel);
}

void sdrv_etimer_lld_cor_int_enable(uint32 base, uint32 int_sel)
{
    sdrv_etimer_lld_writel(base, ETMR_COR_ERR_INT_STA_EN_OFF, int_sel);
    sdrv_etimer_lld_writel(base, ETMR_COR_ERR_INT_SIG_EN_OFF, int_sel);
}

void sdrv_etimer_lld_unc_int_enable(uint32 base, uint32 int_sel)
{
    sdrv_etimer_lld_writel(base, ETMR_UNC_ERR_INT_STA_EN_OFF, int_sel);
    sdrv_etimer_lld_writel(base, ETMR_UNC_ERR_INT_SIG_EN_OFF, int_sel);
}

uint32 sdrv_etimer_lld_get_int_status(uint32 base)
{
    uint32 int_sta = sdrv_etimer_lld_readl(base, ETMR_INT_STA_OFF);
    return int_sta;
}

void sdrv_etimer_lld_clear_int_status(uint32 base, uint32 int_sta)
{
    sdrv_etimer_lld_writel(base, ETMR_INT_STA_OFF, int_sta);
}

uint32 sdrv_etimer_lld_get_cor_int_status(uint32 base)
{
    uint32 int_sta = sdrv_etimer_lld_readl(base, ETMR_COR_ERR_INT_STA_OFF);
    return int_sta;
}

void sdrv_etimer_lld_clear_cor_int_status(uint32 base, uint32 int_sta)
{
    sdrv_etimer_lld_writel(base, ETMR_COR_ERR_INT_STA_OFF, int_sta);
}

uint32 sdrv_etimer_lld_get_unc_int_status(uint32 base)
{
    uint32 int_sta = sdrv_etimer_lld_readl(base, ETMR_UNC_ERR_INT_STA_OFF);
    return int_sta;
}

void sdrv_etimer_lld_clear_unc_int_status(uint32 base, uint32 int_sta)
{
    sdrv_etimer_lld_writel(base, ETMR_UNC_ERR_INT_STA_OFF, int_sta);
}

uint32 sdrv_etimer_lld_get_fusa_cor_int_status(uint32 base)
{
    uint32 int_sta =
        sdrv_etimer_lld_readl(base, ETMR_FUSA_COR_ERR_INT_STA_OFF);
    return int_sta;
}

void sdrv_etimer_lld_clear_fusa_cor_int_status(uint32 base, uint32 int_sta)
{
    sdrv_etimer_lld_writel(base, ETMR_FUSA_COR_ERR_INT_STA_OFF, int_sta);
}

uint32 sdrv_etimer_lld_get_fusa_unc_int_status(uint32 base)
{
    uint32 int_sta =
        sdrv_etimer_lld_readl(base, ETMR_FUSA_UNC_ERR_INT_STA_OFF);
    return int_sta;
}

void sdrv_etimer_lld_clear_fusa_unc_int_status(uint32 base, uint32 int_sta)
{
    sdrv_etimer_lld_writel(base, ETMR_FUSA_UNC_ERR_INT_STA_OFF, int_sta);
}

void sdrv_etimer_lld_dma_chn_cfg(uint32 base, sdrv_etimer_chn_id_e ch,
                                 chn_etimer_dma_ctrl_t *config)
{
    uint32 dma_chn_ctrl = sdrv_etimer_lld_readl(base, ETMR_CHN_DMA_CTRL_OFF);
    dma_chn_ctrl &= ~ETMR_FM_CHN_DMA_CTRL_CHN_SEL(ch);
    dma_chn_ctrl |= ETMR_FV_CHN_DMA_CTRL_CHN_SEL(config->block_sel, ch);
    (config->chn_sig_mask)
        ? (dma_chn_ctrl |= ETMR_BM_CHN_DMA_CTRL_CHN_SIG_MASK(ch))
        : (dma_chn_ctrl &= ~ETMR_BM_CHN_DMA_CTRL_CHN_SIG_MASK(ch));
    (config->bit_mode)
        ? (dma_chn_ctrl |= ETMR_BM_CHN_DMA_CTRL_CHN_16BIT_MODE(ch))
        : (dma_chn_ctrl &= ~ETMR_BM_CHN_DMA_CTRL_CHN_16BIT_MODE(ch));
    if (config->chn_en) {
        dma_chn_ctrl |= ETMR_BM_CHN_DMA_CTRL_CHN_EN(ch);
    }
    sdrv_etimer_lld_writel(base, ETMR_CHN_DMA_CTRL_OFF, dma_chn_ctrl);
}

void sdrv_etimer_lld_dma_wml(uint32 base, sdrv_etimer_chn_id_e chn,
                             uint32 value)
{
    uint32 dma_wml_chn = sdrv_etimer_lld_readl(base, ETMR_DMA_WML_OFF);
    dma_wml_chn &= ~ETMR_FM_DMA_WML_CHN(chn);
    dma_wml_chn |= ETMR_FV_DMA_WML_CHN(value, chn);
    sdrv_etimer_lld_writel(base, ETMR_DMA_WML_OFF, dma_wml_chn);
}

void sdrv_etimer_lld_config_dma_ctrl(uint32 base, uint32 trig_sel)
{
    uint32 dma_ctl = 0;
    dma_ctl |= ETMR_FV_CONFIG_DMA_CTL_TRIG_SEL(trig_sel);
    dma_ctl |= ETMR_BM_CONFIG_DMA_CTL_EN;
    sdrv_etimer_lld_writel(base, ETMR_CONFIG_DMA_CTL_OFF, dma_ctl);
}

void sdrv_etimer_lld_out_mode(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                              etimer_cmp_event_mode_t *mode)
{
    uint32 cmp_mode = 0;
    cmp_mode |= ETMR_FV_CMP_EVENT_OUT_MODE_CMP00(mode->cmp_00_out);
    cmp_mode |= ETMR_FV_CMP_EVENT_OUT_MODE_CMP01(mode->cmp_01_out);
    cmp_mode |= ETMR_FV_CMP_EVENT_OUT_MODE_CMP10(mode->cmp_10_out);
    cmp_mode |= ETMR_FV_CMP_EVENT_OUT_MODE_CMP11(mode->cmp_11_out);
    cmp_mode |= ETMR_FV_CMP_EVENT_OUT_MODE_CMP0_OVF(mode->cmp_0_ovf_out);
    cmp_mode |= ETMR_FV_CMP_EVENT_OUT_MODE_CMP1_OVF(mode->cmp_1_ovf_out);
    sdrv_etimer_lld_writel(base, ETMR_CMP_EVENT_OUT_MODE_OFF(etimer_id),
                           cmp_mode);
}

void sdrv_etimer_lld_cmp_val(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                             sdrv_etimer_cmp_event_e group, uint32 val)
{
    sdrv_etimer_lld_writel(base, ETMR_CMP_VAL_OFF(etimer_id, group), val);
}

void sdrv_etimer_lld_cmp_pulse_wid0_set(uint32 base,
                                        sdrv_etimer_chn_id_e etimer_id,
                                        etimer_cmp_pulse_wid0_t *wid0)
{
    uint32 cmp_pulse_wid0 = 0;
    cmp_pulse_wid0 |= ETMR_FV_CMP_PULSE_WID0_CMP00(wid0->cmp_00_pluse);
    cmp_pulse_wid0 |= ETMR_FV_CMP_PULSE_WID0_CMP01(wid0->cmp_01_pluse);
    cmp_pulse_wid0 |= ETMR_FV_CMP_PULSE_WID0_CMP10(wid0->cmp_10_pluse);
    cmp_pulse_wid0 |= ETMR_FV_CMP_PULSE_WID0_CMP11(wid0->cmp_11_pluse);
    sdrv_etimer_lld_writel(base, ETMR_CMP_PULSE_WID0_OFF(etimer_id),
                           cmp_pulse_wid0);
}

void sdrv_etimer_lld_cmp_pulse_wid1_set(uint32 base,
                                        sdrv_etimer_chn_id_e etimer_id,
                                        etimer_cmp_pulse_wid1_t *wid1)
{
    uint32 cmp_pulse_wid1 = 0;
    cmp_pulse_wid1 |= ETMR_FV_CMP_PULSE_WID1_CMP1_OVF(wid1->cmp_1_ovf_pluse);
    cmp_pulse_wid1 |= ETMR_FV_CMP_PULSE_WID1_CMP0_OVF(wid1->cmp_0_ovf_pluse);
    sdrv_etimer_lld_writel(base, ETMR_CMP_PULSE_WID1_OFF(etimer_id),
                           cmp_pulse_wid1);
}

void sdrv_etimer_lld_cmp_val_upd(uint32 base, sdrv_etimer_chn_id_e etimer_id)
{
    uint32 cmp_upd = sdrv_etimer_lld_readl(base, ETMR_CMP_CTRL_OFF);
    cmp_upd |= ETMR_BM_CMP_CTRL_CMP_VAL_UPD(etimer_id);
    sdrv_etimer_lld_writel(base, ETMR_CMP_CTRL_OFF, cmp_upd);
}

void sdrv_etimer_lld_cmp_init_status(uint32 base,
                                     sdrv_etimer_chn_id_e etimer_id,
                                     etimer_cmp_init_status_t *init_sta)
{
    uint32 cmp_init_status = sdrv_etimer_lld_readl(base, ETMR_CMP_CTRL_OFF);
    if (init_sta->init_status_x0) {
        cmp_init_status |= ETMR_BM_CMP_CTRL_CMP_X0_INIT_STATUS(etimer_id);
    } else {
        cmp_init_status &= ~ETMR_BM_CMP_CTRL_CMP_X0_INIT_STATUS(etimer_id);
    }

    if (init_sta->init_status_x1) {
        cmp_init_status |= ETMR_BM_CMP_CTRL_CMP_X1_INIT_STATUS(etimer_id);
    } else {
        cmp_init_status &= ~ETMR_BM_CMP_CTRL_CMP_X1_INIT_STATUS(etimer_id);
    }

    cmp_init_status |= ETMR_BM_CMP_CTRL_CMP_X0_INIT_UPD(etimer_id);
    cmp_init_status |= ETMR_BM_CMP_CTRL_CMP_X1_INIT_UPD(etimer_id);
    sdrv_etimer_lld_writel(base, ETMR_CMP_CTRL_OFF, cmp_init_status);
}

void sdrv_etimer_lld_cmp_cfg(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                             cmp_config_t *cfg)
{
    uint32 cmp_cfg = 0;
    if (cfg->ce_en) {
        cmp_cfg |= ETMR_BM_CMP_CONFIG_CE_EN;
    }
    cmp_cfg |= ((ETMR_BM_CMP_CONFIG_OUT_MODE(cfg->out_mode)) |
                (ETMR_BM_CMP_CONFIG_CON_MODE(cfg->con_mode)) |
                (ETMR_FV_CMP_CONFIG_CMP_MODE(cfg->cmp_mode)));
    cmp_cfg |= (ETMR_FV_CMP_CONFIG_CNT_SEL(cfg->cnt_sel) |
                ETMR_FV_CMP_CONFIG_CE_TRIG_SEL(cfg->ce_trig_sel) |
                ETMR_FV_CMP_CONFIG_SET_TRIG_SEL(cfg->set_trig_sel) |
                ETMR_FV_CMP_CONFIG_CLR_TRIG_SEL(cfg->clr_trig_sel));
    cmp_cfg |= (ETMR_BM_CMP_CONFIG_RLD_TRIG_MODE(cfg->rld_trig_mode) |
                ETMR_BM_CMP_CONFIG_SW_RLD_MODE(cfg->sw_rld_mode));
    cmp_cfg |= ETMR_FV_CMP_CONFIG_REFRESH_INTVAL(cfg->ref_interval);
    sdrv_etimer_lld_writel(base, ETMR_CMP_CONFIG_OFF(etimer_id), cmp_cfg);
}

uint32 sdrv_etimer_lld_get_cmp_mode(uint32 base,
                                      sdrv_etimer_chn_id_e etimer_id)
{
    uint32 cmp_cfg =
        sdrv_etimer_lld_readl(base, ETMR_CMP_CONFIG_OFF(etimer_id));
    return ((cmp_cfg & ETMR_FM_CMP_CONFIG_CMP_MODE) >> 2);
}

void sdrv_etimer_lld_cmp_sw_rld(uint32 base, sdrv_etimer_chn_id_e etimer_id)
{
    uint32 cmp_cfg =
        sdrv_etimer_lld_readl(base, ETMR_CMP_CONFIG_OFF(etimer_id));
    cmp_cfg |= ETMR_BM_CMP_CONFIG_SW_RLD_SET;
    sdrv_etimer_lld_writel(base, ETMR_CMP_CONFIG_OFF(etimer_id), cmp_cfg);
}

void sdrv_etimer_lld_cmp_en(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                            bool enable)
{
    uint32 cmp_ctrl = sdrv_etimer_lld_readl(base, ETMR_CMP_CTRL_OFF);
    enable ? (cmp_ctrl |= ETMR_BM_CMP_CTRL_CMP_EN(etimer_id))
           : (cmp_ctrl &= ~ETMR_BM_CMP_CTRL_CMP_EN(etimer_id));
    sdrv_etimer_lld_writel(base, ETMR_CMP_CTRL_OFF, cmp_ctrl);
}

void sdrv_etimer_lld_cmp_config_set(uint32 base,
                                    sdrv_etimer_chn_id_e etimer_id)
{
    uint32 cmp_ctrl = sdrv_etimer_lld_readl(base, ETMR_CMP_CTRL_OFF);
    cmp_ctrl |= ETMR_BM_CMP_CTRL_CMP_CONFIG_SET(etimer_id);
    sdrv_etimer_lld_writel(base, ETMR_CMP_CTRL_OFF, cmp_ctrl);
}

void sdrv_etimer_lld_cpt_cfg(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                             cpt_config_t *cfg)
{
    uint32 cpt_cfg = 0;
    (cfg->ce_en) ? (cpt_cfg |= ETMR_BM_CPT_CONFIG_CE_EN)
                 : (cpt_cfg &= ~ETMR_BM_CPT_CONFIG_CE_EN);
    (cfg->con_mode) ? (cpt_cfg |= ETMR_BM_CPT_CONFIG_CON_MODE)
                    : (cpt_cfg &= ~ETMR_BM_CPT_CONFIG_CON_MODE);
    (cfg->dual_mode) ? (cpt_cfg |= ETMR_BM_CPT_CONFIG_DUAL_MODE)
                     : (cpt_cfg &= ~ETMR_BM_CPT_CONFIG_DUAL_MODE);
    cpt_cfg |= (ETMR_FV_CPT_CONFIG_CPT0_TRIG_MODE(cfg->cpt0_trig_mode) |
                ETMR_FV_CPT_CONFIG_CPT1_TRIG_MODE(cfg->cpt1_trig_mode));
    cpt_cfg |= (ETMR_FV_CPT_CONFIG_CNT_SEL(cfg->cnt_sel) |
                ETMR_FV_CPT_CONFIG_CE_TRIG_SEL(cfg->ce_trig_sel));
    sdrv_etimer_lld_writel(base, ETMR_CPT_CONFIG_OFF(etimer_id), cpt_cfg);
}

void sdrv_etimer_lld_cpt_config_set(uint32 base,
                                    sdrv_etimer_chn_id_e etimer_id)
{
    uint32 cpt_ctrl = sdrv_etimer_lld_readl(base, ETMR_CPT_CTRL_OFF);
    cpt_ctrl |= ETMR_BM_CPT_CTRL_CPT_CONFIG_SET(etimer_id);
    sdrv_etimer_lld_writel(base, ETMR_CPT_CTRL_OFF, cpt_ctrl);
}

void sdrv_etimer_lld_cpt_en(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                            bool enable)
{
    uint32 cpt_ctrl = sdrv_etimer_lld_readl(base, ETMR_CPT_CTRL_OFF);
    enable ? (cpt_ctrl |= ETMR_BM_CPT_CTRL_CPT_EN(etimer_id))
           : (cpt_ctrl &= ~(ETMR_BM_CPT_CTRL_CPT_EN(etimer_id)));
    sdrv_etimer_lld_writel(base, ETMR_CPT_CTRL_OFF, cpt_ctrl);
}

void sdrv_etimer_lld_dti_ctrl_cfg(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                                  sdrv_etimer_dti_ctrl_e ctrl_mode)
{
    uint32 dti_ctrl =
        sdrv_etimer_lld_readl(base, ETMR_CMP_DTI_CTRL_OFF(etimer_id));
    switch (ctrl_mode) { // fill bit
    case SDRV_ETIMR_CMP_0_NO_CHANGE:
        dti_ctrl &= ~ETMR_BM_CMP_DTI_CTRL_CMP0_POL;
        break;
    case SDRV_ETIMR_CMP_0_INVERT:
        dti_ctrl |= ETMR_BM_CMP_DTI_CTRL_CMP0_POL;
        break;
    case SDRV_ETIMR_CMP_1_NO_CHANGE:
        dti_ctrl &= ~ETMR_BM_CMP_DTI_CTRL_CMP1_POL;
        break;
    case SDRV_ETIMR_CMP_1_INVERT:
        dti_ctrl |= ETMR_BM_CMP_DTI_CTRL_CMP1_POL;
        break;
    case SDRV_ETIMR_CMP_1_SAME_0:
        dti_ctrl |= ETMR_BM_CMP_DTI_CTRL_CMP1_SAME_CMP0;
        dti_ctrl &= ~ETMR_BM_CMP_DTI_CTRL_CMP1_INV_CMP0;
        break;
    case SDRV_ETIMR_CMP_1_INVERT_0:
        dti_ctrl &= ~ETMR_BM_CMP_DTI_CTRL_CMP1_SAME_CMP0;
        dti_ctrl |= ETMR_BM_CMP_DTI_CTRL_CMP1_INV_CMP0;
        break;
    default:
        return;
    }
    sdrv_etimer_lld_writel(base, ETMR_CMP_DTI_CTRL_OFF(etimer_id), dti_ctrl);
}

void sdrv_etimer_lld_dti_wid(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                             uint16 wid0, uint16 wid1)
{
    uint32 dti_wid =
        (ETMR_FV_CMP_DTI_WID_DT0_WID(wid0)) | ETMR_FV_CMP_DTI_WID_DT1_WID(wid1);
    sdrv_etimer_lld_writel(base, ETMR_CMP_DTI_WID_OFF(etimer_id), dti_wid);
}

void sdrv_etimer_lld_dti_ctrl_en(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                                 bool enable)
{
    uint32 dti_ctrl =
        sdrv_etimer_lld_readl(base, ETMR_CMP_DTI_CTRL_OFF(etimer_id));
    enable ? (dti_ctrl |= ETMR_BM_CMP_DTI_CTRL_EN)
           : (dti_ctrl &= ~ETMR_BM_CMP_DTI_CTRL_EN);
    sdrv_etimer_lld_writel(base, ETMR_CMP_DTI_CTRL_OFF(etimer_id), dti_ctrl);
}

void sdrv_etimer_lld_fs_status_set(uint32 base,
                                   sdrv_etimer_chn_id_e etimer_id,
                                   sdrv_etimer_cmp_group_e group, bool enable)
{
    uint32 dti_ctrl =
        sdrv_etimer_lld_readl(base, ETMR_CMP_DTI_CTRL_OFF(etimer_id));
    if (SDRV_ETIMR_CMP_OUT_0 == group) {
        enable ? (dti_ctrl |= ETMR_BM_CMP_DTI_CTRL_CMP0_FS_STATUS)
               : (dti_ctrl &= ~ETMR_BM_CMP_DTI_CTRL_CMP0_FS_STATUS);
    } else if (SDRV_ETIMR_CMP_OUT_1 == group) {
        enable ? (dti_ctrl |= ETMR_BM_CMP_DTI_CTRL_CMP1_FS_STATUS)
               : (dti_ctrl &= ~ETMR_BM_CMP_DTI_CTRL_CMP1_FS_STATUS);
    }
    sdrv_etimer_lld_writel(base, ETMR_CMP_DTI_CTRL_OFF(etimer_id), dti_ctrl);
}

void sdrv_etimer_lld_cmp_input_sel(uint32 base,
                                   sdrv_etimer_chn_id_e etimer_id,
                                   sdrv_etimer_trig_sel_e sel,
                                   sdrv_etimer_trig_set_clr_e val)
{
    uint32 input_sel =
        sdrv_etimer_lld_readl(base, ETMR_CMP_INPUT_SEL_OFF(etimer_id));
    if (SDRV_ETIMR_TRIG_SEL_SET == sel) {
        input_sel &= ~ETMR_FM_CMP_INPUT_SEL_SET_SEL;
        input_sel |= ETMR_FV_CMP_INPUT_SEL_SET_SEL(val);
    } else if (SDRV_ETIMR_TRIG_SEL_CLR == sel) {
        input_sel &= ~ETMR_FM_CMP_INPUT_SEL_CLR_SEL;
        input_sel |= ETMR_FV_CMP_INPUT_SEL_CLR_SEL(val);
    }
    sdrv_etimer_lld_writel(base, ETMR_CMP_INPUT_SEL_OFF(etimer_id), input_sel);
}

void sdrv_etimer_lld_cmp_trig_cfg(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                                  sdrv_etimer_trig_sel_e sel,
                                  sdrv_etimer_cmp_event_trig_e val)
{
    uint32 cmp_cfg =
        sdrv_etimer_lld_readl(base, ETMR_CMP_CONFIG_OFF(etimer_id));
    if (SDRV_ETIMR_TRIG_SEL_SET == sel) {
        cmp_cfg &= ~ETMR_FM_CMP_CONFIG_SET_TRIG_SEL;
        cmp_cfg |= ETMR_FV_CMP_CONFIG_SET_TRIG_SEL(val);
    } else if (SDRV_ETIMR_TRIG_SEL_CLR == sel) {
        cmp_cfg &= ~ETMR_FM_CMP_CONFIG_CLR_TRIG_SEL;
        cmp_cfg |= ETMR_FV_CMP_CONFIG_CLR_TRIG_SEL(val);
    }
    sdrv_etimer_lld_writel(base, ETMR_CMP_CONFIG_OFF(etimer_id), cmp_cfg);
}

void sdrv_etimer_lld_lcnt_trig_cfg(uint32 base, sdrv_etimer_cnt_id_e cnt_x,
                                   sdrv_etimer_trig_sel_e sel,
                                   sdrv_etimer_cmp_event_trig_e val)
{
    uint32 lcnt_cfg = sdrv_etimer_lld_readl(base, ETMR_CNT_CFG_OFF(cnt_x));
    if (SDRV_ETIMR_TRIG_SEL_SET == sel) {
        lcnt_cfg &= ~ETMR_FM_LCNT_CFG_SET_TRIG_SEL;
        lcnt_cfg |= ETMR_FV_LCNT_CFG_SET_TRIG_SEL(val);
    } else if (SDRV_ETIMR_TRIG_SEL_CLR == sel) {
        lcnt_cfg &= ~ETMR_FM_LCNT_CFG_CLR_TRIG_SEL;
        lcnt_cfg |= ETMR_FV_LCNT_CFG_CLR_TRIG_SEL(val);
    } else if (SDRV_ETIMR_TRIG_SEL_SIG == sel) {
        lcnt_cfg &= ~ETMR_FM_LCNT_CFG_SIG_TRIG_SEL;
        lcnt_cfg |= ETMR_FV_LCNT_CFG_SIG_TRIG_SEL(val);
    }
    sdrv_etimer_lld_writel(base, ETMR_CNT_CFG_OFF(cnt_x), lcnt_cfg);
}

void sdrv_etimer_lld_lcnt_ovf_rst_en(uint32 base, sdrv_etimer_cnt_id_e cnt_x,
                                     bool enable)
{
    uint32 lcnt_cfg = sdrv_etimer_lld_readl(base, ETMR_CNT_CFG_OFF(cnt_x));
    enable ? (lcnt_cfg |= ETMR_BM_LCNT_CFG_OVF_RST_DIS)
           : (lcnt_cfg &= ~ETMR_BM_LCNT_CFG_OVF_RST_DIS);
    sdrv_etimer_lld_writel(base, ETMR_CNT_CFG_OFF(cnt_x), lcnt_cfg);
}

void sdrv_etimer_lld_lcnt_cpt_clr_en(uint32 base, sdrv_etimer_cnt_id_e cnt_x,
                                     sdrv_etimer_cpt_clr_e cpt_event,
                                     bool enable)
{
    uint32 lcnt_cfg = sdrv_etimer_lld_readl(base, ETMR_CNT_CFG_OFF(cnt_x));
    if (cpt_event == SDRV_ETIMR_LCNT_CPT_0_CLR) {
        enable ? (lcnt_cfg |= ETMR_BM_LCNT_CFG_CPT0_CLR_EN)
               : (lcnt_cfg &= ~ETMR_BM_LCNT_CFG_CPT0_CLR_EN);
    } else {
        enable ? (lcnt_cfg |= ETMR_BM_LCNT_CFG_CPT1_CLR_EN)
               : (lcnt_cfg &= ~ETMR_BM_LCNT_CFG_CPT1_CLR_EN);
    }
    sdrv_etimer_lld_writel(base, ETMR_CNT_CFG_OFF(cnt_x), lcnt_cfg);
}

void sdrv_etimer_lld_cnt_input_sel(uint32 base, sdrv_etimer_cnt_id_e cnt_x,
                                   sdrv_etimer_trig_sel_e sel,
                                   sdrv_etimer_trig_set_clr_e val)
{
    if (cnt_x > SDRV_ETIMR_CNT_G1) {
        return;
    }
    uint32 input_sel =
        sdrv_etimer_lld_readl(base, ETMR_CNT_INPUT_SEL_OFF(cnt_x));
    if (SDRV_ETIMR_TRIG_SEL_CLR == sel) {
        input_sel &= ~ETMR_FM_CNT_INPUT_SEL_CLR_SEL;
        input_sel |= ETMR_FV_CNT_INPUT_SEL_CLR_SEL(val);
    } else if (SDRV_ETIMR_TRIG_SEL_SET == sel) {
        input_sel &= ~ETMR_FM_CNT_INPUT_SEL_SET_SEL;
        input_sel |= ETMR_FV_CNT_INPUT_SEL_SET_SEL(val);
    }
    sdrv_etimer_lld_writel(base, ETMR_CNT_INPUT_SEL_OFF(cnt_x), input_sel);
}

void sdrv_etimer_lld_cpt_input_set_clr_sel(uint32 base,
                                           sdrv_etimer_chn_id_e etimer_id,
                                           sdrv_etimer_trig_sel_e sel,
                                           sdrv_etimer_trig_set_clr_e val)
{
    uint32 cpt_input =
        sdrv_etimer_lld_readl(base, ETMR_CPT_INPUT_SEL_OFF(etimer_id));
    if (SDRV_ETIMR_TRIG_SEL_SET == sel) {
        cpt_input &= ~ETMR_FM_CPT_INPUT_SEL_SET_SEL;
        cpt_input |= ETMR_FV_CPT_INPUT_SEL_SET_SEL(val);
    } else if (SDRV_ETIMR_TRIG_SEL_CLR == sel) {
        cpt_input &= ~ETMR_FM_CPT_INPUT_SEL_CLR_SEL;
        cpt_input |= ETMR_FV_CPT_INPUT_SEL_CLR_SEL(val);
    }
    sdrv_etimer_lld_writel(base, ETMR_CPT_INPUT_SEL_OFF(etimer_id), cpt_input);
}

void sdrv_etimer_lld_cpt_input_sig_sel(uint32 base,
                                       sdrv_etimer_chn_id_e etimer_id,
                                       sdrv_etimer_trig_sel_e sel,
                                       sdrv_etimer_trig_sig_e val)
{
    if (SDRV_ETIMR_TRIG_SEL_SIG != sel) {
        return;
    }
    uint32 cpt_input =
        sdrv_etimer_lld_readl(base, ETMR_CPT_INPUT_SEL_OFF(etimer_id));
    cpt_input &= ~ETMR_FM_CPT_INPUT_SEL_SIG_SEL;
    cpt_input |= ETMR_FV_CPT_INPUT_SEL_SIG_SEL(val);
    sdrv_etimer_lld_writel(base, ETMR_CPT_INPUT_SEL_OFF(etimer_id), cpt_input);
}

void sdrv_etimer_lld_cpt_input_dir_sel(uint32 base,
                                       sdrv_etimer_chn_id_e etimer_id,
                                       sdrv_etimer_trig_sel_e sel,
                                       sdrv_etimer_trig_dir_e val)
{
    if (SDRV_ETIMR_TRIG_SEL_DIR != sel) {
        return;
    }
    uint32 cpt_input =
        sdrv_etimer_lld_readl(base, ETMR_CPT_INPUT_SEL_OFF(etimer_id));
    cpt_input &= ~ETMR_FM_CPT_INPUT_SEL_DIR_SEL;
    cpt_input |= ETMR_FV_CPT_INPUT_SEL_DIR_SEL(val);
    sdrv_etimer_lld_writel(base, ETMR_CPT_INPUT_SEL_OFF(etimer_id), cpt_input);
}

void sdrv_etimer_lld_cpt_trig_cfg(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                                  sdrv_etimer_trig_sel_e sel,
                                  sdrv_etimer_cmp_event_trig_e val)
{
    uint32 cpt_cfg =
        sdrv_etimer_lld_readl(base, ETMR_CPT_CONFIG_OFF(etimer_id));
    if (SDRV_ETIMR_TRIG_SEL_SET == sel) {
        cpt_cfg &= ~ETMR_FM_CMP_CONFIG_SET_TRIG_SEL;
        cpt_cfg |= ETMR_FV_CMP_CONFIG_SET_TRIG_SEL(val);
    } else if (SDRV_ETIMR_TRIG_SEL_CLR == sel) {
        cpt_cfg &= ~ETMR_FM_CMP_CONFIG_CLR_TRIG_SEL;
        cpt_cfg |= ETMR_FV_CMP_CONFIG_CLR_TRIG_SEL(val);
    }
    sdrv_etimer_lld_writel(base, ETMR_CPT_CONFIG_OFF(etimer_id), cpt_cfg);
}

void sdrv_etimer_lld_cnt_trig_gen(uint32 base, uint32 trigger)
{
    sdrv_etimer_lld_writel(base, ETMR_CNT_EXT_SW_TRIG_OFF, trigger);
}

void sdrv_etimer_lld_sw_trig_ctrl(uint32 base,
                                  sdrv_etimer_sw_trig_sel_e trig_sel,
                                  sdrv_etimer_sw_trig_typr_e trig_type)
{
    uint32 sw_trig = sdrv_etimer_lld_readl(base, ETMR_SW_TRIG_CTRL_OFF);
    sw_trig |= ETMR_BM_SW_TRIG_CTRL_SW_TRIG0_CTRL0(trig_sel, trig_type);
    sdrv_etimer_lld_writel(base, ETMR_SW_TRIG_CTRL_OFF, sw_trig);
}

void sdrv_etimer_lld_sw_trig_pulse(uint32 base,
                                   sdrv_etimer_sw_trig_sel_e trig_sel,
                                   uint32 value)
{
    uint32 trig_pul0 = sdrv_etimer_lld_readl(base, ETMR_SW_TRIG_PULSE0_OFF);
    uint32 trig_pul1 = sdrv_etimer_lld_readl(base, ETMR_SW_TRIG_PULSE1_OFF);
    switch (trig_sel) {
    case SDRV_ETIMR_SW_TRIG0:
        trig_pul0 &= ~ETMR_FM_SW_TRIG_PULSE0_TRIG0_WIDTH;
        trig_pul0 |= ETMR_FV_SW_TRIG_PULSE0_TRIG0_WIDTH(value);
        break;
    case SDRV_ETIMR_SW_TRIG1:
        trig_pul0 &= ~ETMR_FM_SW_TRIG_PULSE0_TRIG1_WIDTH;
        trig_pul0 |= ETMR_FV_SW_TRIG_PULSE0_TRIG1_WIDTH(value);
        break;
    case SDRV_ETIMR_SW_TRIG2:
        trig_pul1 &= ~ETMR_FM_SW_TRIG_PULSE1_TRIG2_WIDTH;
        trig_pul1 |= ETMR_FV_SW_TRIG_PULSE1_TRIG2_WIDTH(value);
        break;
    case SDRV_ETIMR_SW_TRIG3:
        trig_pul1 &= ~ETMR_FM_SW_TRIG_PULSE1_TRIG3_WIDTH;
        trig_pul1 |= ETMR_FV_SW_TRIG_PULSE1_TRIG3_WIDTH(value);
        break;
    default:
        return;
    }
    sdrv_etimer_lld_writel(base, ETMR_SW_TRIG_PULSE0_OFF, trig_pul0);
    sdrv_etimer_lld_writel(base, ETMR_SW_TRIG_PULSE1_OFF, trig_pul1);
}

void sdrv_etimer_lld_cmp_sse_ctrl(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                                  const sdrv_etimer_sse_ctrl_t *cfg)
{
    uint32 cmp_sse =
        sdrv_etimer_lld_readl(base, ETMR_CMP_SSE_CTRL_OFF(etimer_id));
    uint32 sse_mode = cfg->sse_mode[0] << 0 | cfg->sse_mode[1] << 1 |
                        cfg->sse_mode[2] << 2 | cfg->sse_mode[3] << 3 |
                        cfg->sse_mode[4] << 4;
    cmp_sse &= ~ETMR_FM_CMP_SSE_CTRL_SSE_MODE;
    cmp_sse |= ETMR_FV_CMP_SSE_CTRL_SSE_MODE(sse_mode);
    uint32 sse_edge = cfg->edge_sel[0] << 0 | cfg->edge_sel[1] << 2 |
                        cfg->edge_sel[2] << 4 | cfg->edge_sel[3] << 6 |
                        cfg->edge_sel[4] << 8;
    cmp_sse &= ~ETMR_FM_CMP_SSE_CTRL_EDGE_SEL;
    cmp_sse |= ETMR_FV_CMP_SSE_CTRL_EDGE_SEL(sse_edge);
    sdrv_etimer_lld_writel(base, ETMR_CMP_SSE_CTRL_OFF(etimer_id), cmp_sse);
}

void sdrv_etimer_lld_cmp_sse_en(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                                bool enable)
{
    uint32 cmp_sse =
        sdrv_etimer_lld_readl(base, ETMR_CMP_SSE_CTRL_OFF(etimer_id));
    enable ? (cmp_sse |= ETMR_BM_CMP_SSE_CTRL_SSE_EN)
           : (cmp_sse &= ~ETMR_BM_CMP_SSE_CTRL_SSE_EN);
    sdrv_etimer_lld_writel(base, ETMR_CMP_SSE_CTRL_OFF(etimer_id), cmp_sse);
}

void sdrv_etimer_lld_cmp_fault_det_en(uint32 base,
                                      sdrv_etimer_chn_id_e etimer_id,
                                      bool enable)
{
    uint32 cmp_sse =
        sdrv_etimer_lld_readl(base, ETMR_CMP_SSE_CTRL_OFF(etimer_id));
    enable ? (cmp_sse |= ETMR_BM_CMP_SSE_CTRL_SSE_FAULT_DET_EN)
           : (cmp_sse &= ~ETMR_BM_CMP_SSE_CTRL_SSE_FAULT_DET_EN);
    sdrv_etimer_lld_writel(base, ETMR_CMP_SSE_CTRL_OFF(etimer_id), cmp_sse);
}

void sdrv_etimer_lld_cmp_fault_det_set(uint32 base,
                                       sdrv_etimer_chn_id_e etimer_id,
                                       sdrv_etimer_cmp_fault_det_e fault_det)
{
    uint32 cmp_sse =
        sdrv_etimer_lld_readl(base, ETMR_CMP_SSE_CTRL_OFF(etimer_id));
    cmp_sse &= ~ETMR_FM_CMP_SSE_CTRL_SSE_SO_DET_FAULT;
    cmp_sse |= ETMR_FV_CMP_SSE_CTRL_SSE_SO_DET_FAULT(fault_det);
    sdrv_etimer_lld_writel(base, ETMR_CMP_SSE_CTRL_OFF(etimer_id), cmp_sse);
}

void sdrv_etimer_lld_cmp_sse_val(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                                 uint32 value)
{
    sdrv_etimer_lld_writel(base, ETMR_CMP_SSE_REG_OFF(etimer_id), value);
}

void sdrv_etimer_lld_cpt_sse_ctrl(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                                  const sdrv_etimer_sse_ctrl_t *cfg)
{
    uint32 cpt_sse =
        sdrv_etimer_lld_readl(base, ETMR_CPT_SSE_CTRL_OFF(etimer_id));
    uint32 sse_mode = cfg->sse_mode[0] << 0 | cfg->sse_mode[1] << 1 |
                        cfg->sse_mode[2] << 2 | cfg->sse_mode[3] << 3 |
                        cfg->sse_mode[4] << 4;
    cpt_sse &= ~ETMR_FM_CPT_SSE_CTRL_SSE_MODE;
    cpt_sse |= ETMR_FV_CPT_SSE_CTRL_SSE_MODE(sse_mode);
    uint32 sse_edge = cfg->edge_sel[0] << 0 | cfg->edge_sel[1] << 2 |
                        cfg->edge_sel[2] << 4 | cfg->edge_sel[3] << 6 |
                        cfg->edge_sel[4] << 8;
    cpt_sse &= ~ETMR_FM_CPT_SSE_CTRL_EDGE_SEL;
    cpt_sse |= ETMR_FV_CPT_SSE_CTRL_EDGE_SEL(sse_edge);
    sdrv_etimer_lld_writel(base, ETMR_CPT_SSE_CTRL_OFF(etimer_id), cpt_sse);
}

void sdrv_etimer_lld_cpt_quad_ctrl(uint32 base, quad_ctrl_t *quad_ctrl)
{
    uint32 cpt_sse = sdrv_etimer_lld_readl(base, ETMR_CPT_SSE_CTRL_OFF(0));
    cpt_sse &= ~ETMR_FM_CPT_SSE_CTRL_QUAD_SET_SEL;
    cpt_sse |= ETMR_FV_CPT_SSE_CTRL_QUAD_SET_SEL(quad_ctrl->quad_set_sel);
    cpt_sse &= ~ETMR_FM_CPT_SSE_CTRL_QUAD_CLR_SEL;
    cpt_sse |= ETMR_FV_CPT_SSE_CTRL_QUAD_CLR_SEL(quad_ctrl->quad_clr_sel);
    (quad_ctrl->quad_home_pol)
        ? (cpt_sse |= ETMR_BM_CPT_SSE_CTRL_QUAD_HOME_POL)
        : (cpt_sse &= ~ETMR_BM_CPT_SSE_CTRL_QUAD_HOME_POL);
    (quad_ctrl->quad_index_pol)
        ? (cpt_sse |= ETMR_BM_CPT_SSE_CTRL_QUAD_INDEX_POL)
        : (cpt_sse &= ~ETMR_BM_CPT_SSE_CTRL_QUAD_INDEX_POL);
    sdrv_etimer_lld_writel(base, ETMR_CPT_SSE_CTRL_OFF(0), cpt_sse);
}

void sdrv_etimer_lld_cpt_quad_en(uint32 base, bool enable)
{
    uint32 cpt_sse = sdrv_etimer_lld_readl(base, ETMR_CPT_SSE_CTRL_OFF(0));
    enable ? (cpt_sse |= ETMR_BM_CPT_SSE_CTRL_QUAD_MODE_EN)
           : (cpt_sse &= ~ETMR_BM_CPT_SSE_CTRL_QUAD_MODE_EN);
    sdrv_etimer_lld_writel(base, ETMR_CPT_SSE_CTRL_OFF(0), cpt_sse);
}

void sdrv_etimer_lld_cpt_sse_en(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                                bool enable)
{
    uint32 cpt_sse =
        sdrv_etimer_lld_readl(base, ETMR_CPT_SSE_CTRL_OFF(etimer_id));
    enable ? (cpt_sse |= ETMR_BM_CPT_SSE_CTRL_SSE_EN)
           : (cpt_sse &= ~ETMR_BM_CPT_SSE_CTRL_SSE_EN);
    sdrv_etimer_lld_writel(base, ETMR_CPT_SSE_CTRL_OFF(etimer_id), cpt_sse);
}

void sdrv_etimer_lld_cpt_sse_val(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                                 uint32 value)
{
    sdrv_etimer_lld_writel(base, ETMR_CPT_SSE_REG_OFF(etimer_id), value);
}

void sdrv_etimer_lld_cpt_flt_cfg(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                                 flt_config_t *cfg)
{
    if (((cfg->pos_band_wid < 2) || (cfg->pos_band_wid > 17)) &&
        ((cfg->pos_band_wid == SDRV_ETIMR_FLT_POSEEDGE) ||
         (cfg->pos_band_wid == SDRV_ETIMR_FLT_BOTHEDGE))) {
        return;
    }
    if (((cfg->neg_band_wid < 2) || (cfg->neg_band_wid > 17)) &&
        ((cfg->pos_band_wid == SDRV_ETIMR_FLT_NEGEEDGE) ||
         (cfg->pos_band_wid == SDRV_ETIMR_FLT_BOTHEDGE))) {
        return;
    }
    uint32 flt_cfg = 0;
    flt_cfg |= ETMR_FV_CPT_X0_FLT_FLT_EDGE_SEL(cfg->flt_edge_sel);
    if (cfg->flt_edge_sel == SDRV_ETIMR_FLT_POSEEDGE) {
        flt_cfg |= ETMR_FV_CPT_X0_FLT_POS_BAND_WID(
            cfg->pos_band_wid - 2); /* 0-15 indicate 2-17 sample interval */
    } else if (cfg->flt_edge_sel == SDRV_ETIMR_FLT_NEGEEDGE) {
        flt_cfg |= ETMR_FV_CPT_X0_FLT_NEG_BAND_WID(
            cfg->neg_band_wid - 2); /* 0-15 indicate 2-17 sample interval */
    } else {
        flt_cfg |= ETMR_FV_CPT_X0_FLT_POS_BAND_WID(
            cfg->pos_band_wid - 2); /* 0-15 indicate 2-17 sample interval */
        flt_cfg |= ETMR_FV_CPT_X0_FLT_NEG_BAND_WID(
            cfg->neg_band_wid - 2); /* 0-15 indicate 2-17 sample interval */
    }
    flt_cfg |= ETMR_FV_CPT_X0_FLT_SMPL_INTVAL(cfg->sample_intval);
    sdrv_etimer_lld_writel(base, ETMR_CPT_X0_FLT_OFF(etimer_id), flt_cfg);
}

void sdrv_etimer_lld_cpt_flt_en(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                                bool enable)
{
    uint32 flt_cfg =
        sdrv_etimer_lld_readl(base, ETMR_CPT_X0_FLT_OFF(etimer_id));
    enable ? (flt_cfg |= ETMR_BM_CPT_X0_FLT_FLT_EN)
           : (flt_cfg &= ~ETMR_BM_CPT_X0_FLT_FLT_EN);
    sdrv_etimer_lld_writel(base, ETMR_CPT_X0_FLT_OFF(etimer_id), flt_cfg);
}

void sdrv_etimer_lld_fault_flt_cfg(uint32 base,
                                   sdrv_etimer_chn_id_e etimer_id,
                                   flt_config_t *cfg)
{
    if (((cfg->pos_band_wid < 2) || (cfg->pos_band_wid > 17)) &&
        ((cfg->pos_band_wid == SDRV_ETIMR_FLT_POSEEDGE) ||
         (cfg->pos_band_wid == SDRV_ETIMR_FLT_BOTHEDGE))) {
        return;
    }
    if (((cfg->neg_band_wid < 2) || (cfg->neg_band_wid > 17)) &&
        ((cfg->pos_band_wid == SDRV_ETIMR_FLT_NEGEEDGE) ||
         (cfg->pos_band_wid == SDRV_ETIMR_FLT_BOTHEDGE))) {
        return;
    }
    uint32 flt_cfg = 0;
    flt_cfg |= ETMR_FV_FAULT_X_FLT_FLT_EDGE_SEL(cfg->flt_edge_sel);
    flt_cfg |= ETMR_FV_FAULT_X_FLT_POS_BAND_WID(
        cfg->pos_band_wid - 2); /* 0-15 indicate 2-17 sample interval */
    flt_cfg |= ETMR_FV_FAULT_X_FLT_NEG_BAND_WID(
        cfg->neg_band_wid - 2); /* 0-15 indicate 2-17 sample interval */
    flt_cfg |= ETMR_FV_FAULT_X_FLT_SMPL_INTVAL(cfg->sample_intval);
    sdrv_etimer_lld_writel(base, ETMR_FAULT_X_FLT_OFF(etimer_id), flt_cfg);
}

void sdrv_etimer_lld_fault_flt_en(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                                  bool enable)
{
    uint32 flt_cfg =
        sdrv_etimer_lld_readl(base, ETMR_FAULT_X_FLT_OFF(etimer_id));
    enable ? (flt_cfg |= ETMR_BM_FAULT_X_FLT_FLT_EN)
           : (flt_cfg &= ~ETMR_BM_FAULT_X_FLT_FLT_EN);
    sdrv_etimer_lld_writel(base, ETMR_FAULT_X_FLT_OFF(etimer_id), flt_cfg);
}

void sdrv_etimer_lld_cnt_snap_shot(uint32 base, sdrv_etimer_cnt_id_e cnt_x,
                                   uint32 val)
{
    sdrv_etimer_lld_writel(base, ETMR_CNT_SNAP_SHOT_SEL_OFF(cnt_x), val);
}

void sdrv_etimer_lld_output_snap_shot(uint32 base, uint32 val)
{
    sdrv_etimer_lld_writel(base, ETMR_SNAP_SHOT_O_SEL_OFF, val);
}

void sdrv_etimer_lld_cmp_fault_ctrl(uint32 base,
                                    sdrv_etimer_chn_id_e etimer_id,
                                    sdrv_etimer_cmp_fault_e fault_idx,
                                    cmp_fault_ctrl_t *cfg)
{
    uint32 fault_ctrl = 0;
    (cfg->fault_pol)
        ? (fault_ctrl |= ETMR_BM_CMP_FAULT_EVENT_CTRL_FAULT_X_POL(fault_idx))
        : (fault_ctrl &= ~ETMR_BM_CMP_FAULT_EVENT_CTRL_FAULT_X_POL(fault_idx));
    (cfg->fault_clr_mode)
        ? (fault_ctrl |=
           ETMR_BM_CMP_FAULT_EVENT_CTRL_FAULT_X_CLR_MODE(fault_idx))
        : (fault_ctrl &=
           ~ETMR_BM_CMP_FAULT_EVENT_CTRL_FAULT_X_CLR_MODE(fault_idx));
    sdrv_etimer_lld_writel(base, ETMR_ETMR_CMP_FAULT_EVENT_CTRL_OFF(etimer_id),
                           fault_ctrl);
}

void sdrv_etimer_lld_cmp_fault_en(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                                  sdrv_etimer_cmp_fault_e fault_idx,
                                  bool enable)
{
    uint32 fault_ctrl = sdrv_etimer_lld_readl(
        base, ETMR_ETMR_CMP_FAULT_EVENT_CTRL_OFF(etimer_id));
    enable
        ? (fault_ctrl |= ETMR_BM_CMP_FAULT_EVENT_CTRL_FAULT_X_EN(fault_idx))
        : (fault_ctrl &= ~ETMR_BM_CMP_FAULT_EVENT_CTRL_FAULT_X_EN(fault_idx));
    sdrv_etimer_lld_writel(base, ETMR_ETMR_CMP_FAULT_EVENT_CTRL_OFF(etimer_id),
                           fault_ctrl);
}

void sdrv_etimer_lld_cmp_fault_clr(uint32 base,
                                   sdrv_etimer_chn_id_e etimer_id,
                                   sdrv_etimer_cmp_fault_e fault_idx)
{
    uint32 fault_ctrl = sdrv_etimer_lld_readl(
        base, ETMR_ETMR_CMP_FAULT_EVENT_CTRL_OFF(etimer_id));
    fault_ctrl |= ETMR_BM_CMP_FAULT_EVENT_CTRL_FAULT_X_CLR(fault_idx);
    sdrv_etimer_lld_writel(base, ETMR_ETMR_CMP_FAULT_EVENT_CTRL_OFF(etimer_id),
                           fault_ctrl);
}

void sdrv_etimer_lld_cmp_offset(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                                uint32 val)
{
    sdrv_etimer_lld_writel(base, ETMR_ETMR_CMP_OFFSET_OFF(etimer_id), val);
}

void sdrv_etimer_lld_cmp_eid(uint32 base, sdrv_etimer_cmp_event_e cmp_event,
                             uint32 val)
{
    uint32 cmp_eid = sdrv_etimer_lld_readl(base, ETMR_CMP_A_EID_OFF);
    cmp_eid &= ~ETMR_FM_CMP_A_EID_CMP(cmp_event);
    cmp_eid |= ETMR_FV_CMP_A_EID_CMP(val, cmp_event);
    sdrv_etimer_lld_writel(base, ETMR_CMP_A_EID_OFF, cmp_eid);
}

void sdrv_etimer_lld_cmp_eid_upd(uint32 base)
{
    uint32 cmp_ctrl = sdrv_etimer_lld_readl(base, ETMR_CMP_CTRL_OFF);
    cmp_ctrl |= ETMR_BM_CMP_CTRL_CMP_A_EID_UPD;
    sdrv_etimer_lld_writel(base, ETMR_CMP_CTRL_OFF, cmp_ctrl);
}

void sdrv_etimer_lld_sw_rst(uint32 base, uint32 val)
{
    sdrv_etimer_lld_writel(base, ETMR_SW_RST_OFF, val);
}

void sdrv_etimer_lld_set_sync_dis(uint32 base, uint32 val)
{
    sdrv_etimer_lld_writel(base, ETMR_SYNC_DIS_OFF, val);
}

void sdrv_etimer_lld_ext_output_dir_sel(uint32 base,
                                        sdrv_etimer_trig_sel_e sel,
                                        sdrv_etimer_ext_out_dir_e val)
{
    if (sel != SDRV_ETIMR_TRIG_SEL_DIR) {
        return;
    }
    uint32 ext_out = sdrv_etimer_lld_readl(base, ETMR_EXT_OUTPUT_SEL_OFF);
    ext_out &= ~ETMR_FM_EXT_OUTPUT_SEL_DIR_SEL;
    ext_out |= ETMR_FV_EXT_OUTPUT_SEL_DIR_SEL(val);
    sdrv_etimer_lld_writel(base, ETMR_EXT_OUTPUT_SEL_OFF, ext_out);
}

void sdrv_etimer_lld_ext_output_set_clr_sel(uint32 base,
                                            sdrv_etimer_trig_sel_e sel,
                                            sdrv_etimer_ext_out_set_clr_e val)
{
    uint32 ext_out = sdrv_etimer_lld_readl(base, ETMR_EXT_OUTPUT_SEL_OFF);
    if (sel == SDRV_ETIMR_TRIG_SEL_SET) {
        ext_out &= ~ETMR_FM_EXT_OUTPUT_SEL_SET_SEL;
        ext_out |= ETMR_FV_EXT_OUTPUT_SEL_SET_SEL(val);
    } else if (sel == SDRV_ETIMR_TRIG_SEL_CLR) {
        ext_out &= ~ETMR_FM_EXT_OUTPUT_SEL_CLR_SEL;
        ext_out |= ETMR_FV_EXT_OUTPUT_SEL_CLR_SEL(val);
    } else {
    }
    sdrv_etimer_lld_writel(base, ETMR_EXT_OUTPUT_SEL_OFF, ext_out);
}

uint32 sdrv_etimer_lld_get_fifo_req_sta(uint32 base)
{
    uint32 fifo_req_sta =
        sdrv_etimer_lld_readl(base, ETMR_FIFO_REQ_STATUS_OFF);
    return fifo_req_sta;
}

uint32 sdrv_etimer_lld_get_fifo_val(uint32 base,
                                      sdrv_etimer_chn_id_e etimer_id)
{
    uint32 fifo_val = sdrv_etimer_lld_readl(base, ETMR_FIFO_OFF(etimer_id));
    return fifo_val;
}

uint32 sdrv_etimer_lld_get_fifo_sta(uint32 base)
{
    uint32 fifo_sta = sdrv_etimer_lld_readl(base, ETMR_FIFO_STA_OFF);
    return fifo_sta;
}

void sdrv_etimer_lld_clear_fifo(uint32 base, sdrv_etimer_chn_id_e etimer_id)
{
    uint32 fifo_sta = sdrv_etimer_lld_get_fifo_sta(base);
    for (uint8 i = 0;
         i < (ETMR_GFV_FIFO_STA_FIFO_ENTRIES(fifo_sta, etimer_id)); i++) {
        sdrv_etimer_lld_get_fifo_val(base, etimer_id);
    }
}

uint32 sdrv_etimer_lld_get_sig_status(uint32 base)
{
    uint32 sig_status = sdrv_etimer_lld_readl(base, ETMR_SIGNAL_STATUS_OFF);
    return sig_status;
}

void sdrv_etimer_lld_set_self_test(uint32 base, bool enable)
{
    sdrv_etimer_lld_writel(base, ETMR_SELFTEST_MODE_OFF, enable);
}

void sdrv_etimer_lld_cmp_dti_cbc(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                                 bool enable)
{
    if (get_etimer_version()==1) {
        uint8 index = 0;
        for (index = 0; index < 4; index++) {
            if (APB_ETMR1_BASE + 0x10000 * index == base)
                break;
        }
        RMWREG32(ETMR_CBC_ZERO_VECTOR_BY_SCR_ADDR,
                 ETMR_CBC_POS(index, etimer_id), 1, enable);
    }
}

void sdrv_etimer_lld_cmp_dti_zero_vector(uint32 base,
                                         sdrv_etimer_chn_id_e etimer_id,
                                         bool enable)
{
    if (get_etimer_version()==1) {
        uint8 index = 0;
        for (index = 0; index < 4; index++) {
            if (APB_ETMR1_BASE + 0x10000 * index == base)
                break;
        }
        RMWREG32(ETMR_CBC_ZERO_VECTOR_BY_SCR_ADDR,
                 ETMR_ZERO_VECTOR_POS(index, etimer_id), 1, enable);
    }
}

#if SEMIDRIVE_E3_LITE_SERIES
void sdrv_etimer_lld_cnt_center_align_en(uint32 base,
                                         sdrv_etimer_cnt_id_e cnt_x,
                                         bool enable)
{
    uint32 cnt_reg_addr = 0;
    if (cnt_x <= SDRV_ETIMR_CNT_G1) {
        cnt_reg_addr = ETMR_CNT_CFG_OFF(cnt_x);
    } else {
        cnt_reg_addr = ETMR_LCNT_CFG1_OFF(cnt_x - 2);
    }
    uint32 cnt_cfg = sdrv_etimer_lld_readl(base, cnt_reg_addr);
    if (cnt_x <= SDRV_ETIMR_CNT_G1) {
        enable ? (cnt_cfg |= ETMR_BM_CNT_CFG_CENTER_ALIGN_MODE)
               : (cnt_cfg &= ~ETMR_BM_CNT_CFG_CENTER_ALIGN_MODE);
    } else {
        enable ? (cnt_cfg |= ETMR_BM_LCNT_CFG_CENTER_ALIGN_MODE)
               : (cnt_cfg &= ~ETMR_BM_LCNT_CFG_CENTER_ALIGN_MODE);
    }
    sdrv_etimer_lld_writel(base, cnt_reg_addr, cnt_cfg);
}

void sdrv_etimer_lld_cnt_center_align_cfg(uint32 base,
                                          sdrv_etimer_cnt_id_e cnt_x,
                                          cnt_center_align_config_t *cfg)
{
    uint32 cnt_reg_addr = 0;
    if (cnt_x <= SDRV_ETIMR_CNT_G1) {
        cnt_reg_addr = ETMR_CNT_CFG_OFF(cnt_x);
    } else {
        cnt_reg_addr = ETMR_LCNT_CFG1_OFF(cnt_x - 2);
    }
    uint32 cnt_cfg = sdrv_etimer_lld_readl(base, cnt_reg_addr);
    if (cnt_x <= SDRV_ETIMR_CNT_G1) {
        cnt_cfg &= ~ETMR_FM_CNT_CFG_CENTER_ALIGN_OVF_SEL;
        cnt_cfg &= ~ETMR_FM_CNT_CFG_CENTER_ALIGN_CE_SEL;
        cnt_cfg |= ETMR_FV_CNT_CFG_CENTER_ALIGN_OVF_SEL(cfg->ovf_sel);
        cnt_cfg |= ETMR_FV_CNT_CFG_CENTER_ALIGN_CE_SEL(cfg->ce_sel);
    } else {
        cnt_cfg &= ~ETMR_FM_LCNT_CFG_CENTER_ALIGN_OVF_SEL;
        cnt_cfg &= ~ETMR_FM_LCNT_CFG_CENTER_ALIGN_CE_SEL;
        cnt_cfg |= ETMR_FV_LCNT_CFG_CENTER_ALIGN_OVF_SEL(cfg->ovf_sel);
        cnt_cfg |= ETMR_FV_LCNT_CFG_CENTER_ALIGN_CE_SEL(cfg->ce_sel);
    }
    sdrv_etimer_lld_writel(base, cnt_reg_addr, cnt_cfg);
}

void sdrv_etimer_lld_cmp_center_align_en(uint32 base,
                                         sdrv_etimer_chn_id_e etimer_id,
                                         bool enable)
{
    uint32 cmp_cfg1 =
        sdrv_etimer_lld_readl(base, ETMR_CMP_CONFIG1_OFF(etimer_id));
    enable ? (cmp_cfg1 |= ETMR_BM_CMP_CENTER_ALIGN_MODE)
           : (cmp_cfg1 &= ~ETMR_BM_CMP_CENTER_ALIGN_MODE);
    sdrv_etimer_lld_writel(base, ETMR_CMP_CONFIG1_OFF(etimer_id), cmp_cfg1);
}

void sdrv_etimer_lld_cmp_center_align_cfg(uint32 base,
                                          sdrv_etimer_chn_id_e etimer_id,
                                          cmp_center_align_config_t *cfg)
{
    uint32 cmp_cfg1 = 0;
    cmp_cfg1 |= ETMR_FV_CMP_CENTER_ALIGN_CE_SEL(cfg->ce_sel);
    cmp_cfg1 |= ETMR_FV_CMP_CENTER_ALIGN_CMP00_IRQ_SEL(cfg->cmp00_irq);
    cmp_cfg1 |= ETMR_FV_CMP_CENTER_ALIGN_CMP01_IRQ_SEL(cfg->cmp01_irq);
    cmp_cfg1 |= ETMR_FV_CMP_CENTER_ALIGN_CMP10_IRQ_SEL(cfg->cmp10_irq);
    cmp_cfg1 |= ETMR_FV_CMP_CENTER_ALIGN_CMP11_IRQ_SEL(cfg->cmp11_irq);
    cmp_cfg1 |= ETMR_FV_CMP_CENTER_ALIGN_RLD_SEL(cfg->rld_sel);
    sdrv_etimer_lld_writel(base, ETMR_CMP_CONFIG1_OFF(etimer_id), cmp_cfg1);
}

void sdrv_etimer_lld_cmp_cen_ali_int_enable(uint32 base, uint32 int_sel)
{
    sdrv_etimer_lld_writel(base, ETMR_CENTER_ALIGN_CMP_INT_STA_EN_OFF, int_sel);
    sdrv_etimer_lld_writel(base, ETMR_CENTER_ALIGN_CMP_INT_SIG_EN_OFF, int_sel);
}

uint32 sdrv_etimer_lld_get_cmp_cen_ali_int_status(uint32 base)
{
    uint32 int_sta =
        sdrv_etimer_lld_readl(base, ETMR_CENTER_ALIGN_CMP_INT_STA_OFF);
    return int_sta;
}

void sdrv_etimer_lld_clear_cmp_cen_ali_int_status(uint32 base,
                                                  uint32 int_sta)
{
    sdrv_etimer_lld_writel(base, ETMR_CENTER_ALIGN_CMP_INT_STA_OFF, int_sta);
}

uint32 sdrv_etimer_lld_get_cmp_fault_sta(uint32 base)
{
    uint32 fault_sta =
        sdrv_etimer_lld_readl(base, ETMR_CMP_FAULT_EVENT_STA_OFF);
    return fault_sta;
}

void sdrv_etimer_lld_cmp_frc_idle(uint32 base, sdrv_etimer_chn_id_e etimer_id,
                                  sdrv_etimer_cmp_group_e group, bool enable)
{
    uint32 cmp_idle =
        sdrv_etimer_lld_readl(base, ETMR_CMP_DTI_CTRL_OFF(etimer_id));
    if (SDRV_ETIMR_CMP_OUT_0 == group) {
        enable ? (cmp_idle |= ETMR_BM_CMP_CMP0_IDLE_STA)
               : (cmp_idle &= ~ETMR_BM_CMP_CMP0_IDLE_STA);
    } else if (SDRV_ETIMR_CMP_OUT_1 == group) {
        enable ? (cmp_idle |= ETMR_BM_CMP_CMP1_IDLE_STA)
               : (cmp_idle &= ~ETMR_BM_CMP_CMP1_IDLE_STA);
    }
    sdrv_etimer_lld_writel(base, ETMR_CMP_DTI_CTRL_OFF(etimer_id), cmp_idle);
}

void sdrv_etimer_lld_cmp_sw_trig_idle(uint32 base,
                                      sdrv_etimer_chn_id_e etimer_id,
                                      bool enable)
{
    uint32 cmp_idle =
        sdrv_etimer_lld_readl(base, ETMR_CMP_DTI_CTRL_OFF(etimer_id));
    enable ? (cmp_idle |= ETMR_BM_CMP_SW_TRIG_FRC)
           : (cmp_idle &= ~ETMR_BM_CMP_SW_TRIG_FRC);
    sdrv_etimer_lld_writel(base, ETMR_CMP_DTI_CTRL_OFF(etimer_id), cmp_idle);
}

#endif
