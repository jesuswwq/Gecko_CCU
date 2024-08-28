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
 * @file  sdrv_pwm_lld.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Pwm
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <__regs_base.h>

#include "sdrv_pwm_lld.h"
#include "Mcu.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

static uint8 get_epwm_version(void)
{
#ifdef SEMIDRIVE_E3_SERIES
    return Mcu_GetChipVersion();
#else
    return  1;
#endif
}

void sdrv_epwm_lld_int_enable(volatile uint32 base, uint32 val)
{
    sdrv_epwm_lld_int_sta_enable(base, val);
    sdrv_epwm_lld_int_sig_enable(base, val);
}

void sdrv_epwm_lld_int_sta_enable(volatile uint32 base, uint32 val)
{
    uint32 sta = sdrv_epwm_lld_int_sta_en(base);
    writel(sta | val, base + EPWM_INT_STA_EN_OFF);
}

void sdrv_epwm_lld_int_sta_dis(volatile uint32 base, uint32 val)
{
    uint32 sta = sdrv_epwm_lld_int_sta_en(base);
    writel(sta & (~val), base + EPWM_INT_STA_EN_OFF);
}

void sdrv_epwm_lld_int_sig_enable(volatile uint32 base, uint32 val)
{
    uint32 sta = sdrv_epwm_lld_int_sig_en(base);
    writel(sta | val, base + EPWM_INT_SIG_EN_OFF);
}

void sdrv_epwm_lld_int_sig_dis(volatile uint32 base, uint32 val)
{
    uint32 sta = sdrv_epwm_lld_int_sig_en(base);
    writel(sta & (~val), base + EPWM_INT_SIG_EN_OFF);
}

void sdrv_epwm_lld_cor_err_int_enable(volatile uint32 base, uint32 val)
{
    sdrv_epwm_lld_cor_err_int_sta_enable(base, val);
    sdrv_epwm_lld_cor_err_int_sig_enable(base, val);
}

void sdrv_epwm_lld_cor_err_int_sta_enable(volatile uint32 base, uint32 val)
{
    uint32 sta = sdrv_epwm_lld_cor_err_int_sta_en(base);
    writel(sta | val, base + EPWM_COR_ERR_INT_STA_EN_OFF);
}

void sdrv_epwm_lld_cor_err_int_sta_dis(volatile uint32 base, uint32 val)
{
    uint32 sta = sdrv_epwm_lld_cor_err_int_sta_en(base);
    writel(sta & (~val), base + EPWM_COR_ERR_INT_STA_EN_OFF);
}

void sdrv_epwm_lld_cor_err_int_sig_enable(volatile uint32 base, uint32 val)
{
    uint32 sta = sdrv_epwm_lld_cor_err_int_sig_en(base);
    writel(sta | val, base + EPWM_COR_ERR_INT_SIG_EN_OFF);
}

void sdrv_epwm_lld_cor_err_int_sig_dis(volatile uint32 base, uint32 val)
{
    uint32 sta = sdrv_epwm_lld_cor_err_int_sig_en(base);
    writel(sta & (~val), base + EPWM_COR_ERR_INT_SIG_EN_OFF);
}

void sdrv_epwm_lld_unc_err_int_enable(volatile uint32 base, uint32 val)
{
    sdrv_epwm_lld_unc_err_int_sta_enable(base, val);
    sdrv_epwm_lld_unc_err_int_sig_enable(base, val);
}

void sdrv_epwm_lld_unc_err_int_sta_enable(volatile uint32 base, uint32 val)
{
    uint32 sta = sdrv_epwm_lld_unc_err_int_sta_en(base);
    writel(sta | val, base + EPWM_UNC_ERR_INT_STA_EN_OFF);
}

void sdrv_epwm_lld_unc_err_int_sta_dis(volatile uint32 base, uint32 val)
{
    uint32 sta = sdrv_epwm_lld_unc_err_int_sta_en(base);
    writel(sta & (~val), base + EPWM_UNC_ERR_INT_STA_EN_OFF);
}

void sdrv_epwm_lld_unc_err_int_sig_enable(volatile uint32 base, uint32 val)
{
    uint32 sta = sdrv_epwm_lld_unc_err_int_sig_en(base);
    writel(sta | val, base + EPWM_UNC_ERR_INT_SIG_EN_OFF);
}

void sdrv_epwm_lld_unc_err_int_sig_dis(volatile uint32 base, uint32 val)
{
    uint32 sta = sdrv_epwm_lld_unc_err_int_sig_en(base);
    writel(sta & (~val), base + EPWM_UNC_ERR_INT_SIG_EN_OFF);
}

void sdrv_epwm_lld_unc_int_en(volatile uint32 base, uint32 int_id)
{
    uint32 sta_en, sig_en;
    sta_en = sdrv_epwm_lld_unc_err_int_sta_en(base);
    sta_en |= SDRV_EPWM_STA_MASK(int_id);
    writel(sta_en, base + EPWM_UNC_ERR_INT_STA_EN_OFF);

    sig_en = sdrv_epwm_lld_unc_err_int_sig_en(base);
    sig_en |= SDRV_EPWM_STA_MASK(int_id);
    writel(sig_en, base + EPWM_UNC_ERR_INT_SIG_EN_OFF);
}

void sdrv_epwm_lld_fusa_cor_err_int_sta_enable(volatile uint32 base, uint32 val)
{
    uint32 sta = sdrv_epwm_lld_fusa_cor_err_int_sta_en(base);
    writel(sta | val, base + EPWM_FUSA_COR_ERR_INT_STA_EN_OFF);
}

void sdrv_epwm_lld_fusa_cor_err_int_sta_dis(volatile uint32 base, uint32 val)
{
    uint32 sta = sdrv_epwm_lld_fusa_cor_err_int_sta_en(base);
    writel(sta & (~val), base + EPWM_FUSA_COR_ERR_INT_STA_EN_OFF);
}

void sdrv_epwm_lld_fusa_cor_err_int_sig_enable(volatile uint32 base, uint32 val)
{
    uint32 sta = sdrv_epwm_lld_fusa_cor_err_int_sig_en(base);
    writel(sta | val, base + EPWM_FUSA_COR_ERR_INT_SIG_EN_OFF);
}

void sdrv_epwm_lld_fusa_cor_err_int_sig_dis(volatile uint32 base, uint32 val)
{
    uint32 sta = sdrv_epwm_lld_fusa_cor_err_int_sig_en(base);
    writel(sta & (~val), base + EPWM_FUSA_COR_ERR_INT_SIG_EN_OFF);
}

void sdrv_epwm_lld_fusa_cor_err_int_enable(volatile uint32 base, uint32 val)
{
    sdrv_epwm_lld_fusa_cor_err_int_sta_enable(base, val);
    sdrv_epwm_lld_fusa_cor_err_int_sig_enable(base, val);
}

void sdrv_epwm_lld_fusa_unc_err_int_sta_enable(volatile uint32 base, uint32 val)
{
    uint32 sta = sdrv_epwm_lld_fusa_unc_err_int_sta_en(base);
    writel(sta | val, base + EPWM_FUSA_UNC_ERR_INT_STA_EN_OFF);
}

void sdrv_epwm_lld_fusa_unc_err_int_sta_dis(volatile uint32 base, uint32 val)
{
    uint32 sta = sdrv_epwm_lld_fusa_unc_err_int_sta_en(base);
    writel(sta & (~val), base + EPWM_FUSA_UNC_ERR_INT_STA_EN_OFF);
}

void sdrv_epwm_lld_fusa_unc_err_int_sig_enable(volatile uint32 base, uint32 val)
{
    uint32 sta = sdrv_epwm_lld_fusa_unc_err_int_sig_en(base);
    writel(sta | val, base + EPWM_FUSA_UNC_ERR_INT_SIG_EN_OFF);
}

void sdrv_epwm_lld_fusa_unc_err_int_sig_dis(volatile uint32 base, uint32 val)
{
    uint32 sta = sdrv_epwm_lld_fusa_unc_err_int_sig_en(base);
    writel(sta & (~val), base + EPWM_FUSA_UNC_ERR_INT_SIG_EN_OFF);
}

void sdrv_epwm_lld_fusa_unc_err_int_enable(volatile uint32 base, uint32 val)
{
    sdrv_epwm_lld_fusa_unc_err_int_sta_enable(base, val);
    sdrv_epwm_lld_fusa_unc_err_int_sig_enable(base, val);
}

void sdrv_epwm_lld_fusa_unc_err_int_sta_1_enable(volatile uint32 base, uint32 val)
{
    uint32 sta = sdrv_epwm_lld_fusa_unc_err_int_sta_1_en(base);
    writel(sta | val, base + EPWM_FUSA_UNC_ERR_INT_STA_EN_1_OFF);
}

void sdrv_epwm_lld_fusa_unc_err_int_sta_1_dis(volatile uint32 base, uint32 val)
{
    uint32 sta = sdrv_epwm_lld_fusa_unc_err_int_sta_1_en(base);
    writel(sta & (~val), base + EPWM_FUSA_UNC_ERR_INT_STA_EN_1_OFF);
}

void sdrv_epwm_lld_fusa_unc_err_int_sig_1_enable(volatile uint32 base, uint32 val)
{
    uint32 sta = sdrv_epwm_lld_fusa_unc_err_int_sig_1_en(base);
    writel(sta | val, base + EPWM_FUSA_UNC_ERR_INT_SIG_EN_1_OFF);
}

void sdrv_epwm_lld_fusa_unc_err_int_sig_1_dis(volatile uint32 base, uint32 val)
{
    uint32 sta = sdrv_epwm_lld_fusa_unc_err_int_sig_1_en(base);
    writel(sta & (~val), base + EPWM_FUSA_UNC_ERR_INT_SIG_EN_1_OFF);
}

void sdrv_epwm_lld_fusa_unc_err_int_1_enable(volatile uint32 base, uint32 val)
{
    sdrv_epwm_lld_fusa_unc_err_int_sta_1_enable(base, val);
    sdrv_epwm_lld_fusa_unc_err_int_sig_1_enable(base, val);
}

void sdrv_epwm_lld_reg_parity_err_int_sta_enable(volatile uint32 base, uint32 val)
{
    uint32 sta = sdrv_epwm_lld_reg_parity_err_int_sta_en(base);
    writel(sta | val, base + EPWM_REG_PARITY_ERR_INT_STAT_EN_OFF);
}

void sdrv_epwm_lld_reg_parity_err_int_sta_dis(volatile uint32 base, uint32 val)
{
    uint32 sta = sdrv_epwm_lld_reg_parity_err_int_sta_en(base);
    writel(sta & (~val), base + EPWM_REG_PARITY_ERR_INT_STAT_EN_OFF);
}

void sdrv_epwm_lld_reg_parity_err_int_sig_enable(volatile uint32 base, uint32 val)
{
    uint32 sta = sdrv_epwm_lld_reg_parity_err_int_sig_en(base);
    writel(sta | val, base + EPWM_REG_PARITY_ERR_INT_SIG_EN_OFF);
}

void sdrv_epwm_lld_reg_parity_err_int_sig_dis(volatile uint32 base, uint32 val)
{
    uint32 sta = sdrv_epwm_lld_reg_parity_err_int_sig_en(base);
    writel(sta & (~val), base + EPWM_REG_PARITY_ERR_INT_SIG_EN_OFF);
}

void sdrv_epwm_lld_reg_parity_err_int_enable(volatile uint32 base, uint32 val)
{
    sdrv_epwm_lld_reg_parity_err_int_sta_enable(base, val);
    sdrv_epwm_lld_reg_parity_err_int_sig_enable(base, val);
}

void sdrv_epwm_lld_clk_config_div_num(volatile uint32 base, uint16 div_num)
{
    REG_RMW32(base + EPWM_CLK_CONFIG_OFF, 0, 16, div_num);
    REG_RMW32(base + EPWM_CLK_CONFIG_OFF, 31, 1, TRUE);
}

void sdrv_epwm_lld_clk_config(volatile uint32 base,
                              sdrv_epwm_clk_config_src_clk_sel_e src_clk_sel,
                              uint16 div_num)
{
    REG_RMW32(base + EPWM_CLK_CONFIG_OFF, 16, 2, src_clk_sel);

    sdrv_epwm_lld_clk_config_div_num(base, div_num);
}

void sdrv_epwm_lld_clk_mon_en(volatile uint32 base, boolean en_p, boolean en_n)
{
    REG_RMW32(base + EPWM_CLK_MON_EN_OFF, 0, 1, !en_p);
    REG_RMW32(base + EPWM_CLK_MON_EN_OFF, 1, 1, en_n);
    REG_RMW32(base + EPWM_CLK_MON_EN_OFF, 2, 1, TRUE);
}

void sdrv_epwm_lld_chn_dma_ctrl_cmp(volatile uint32 base, sdrv_epwm_channel_e chnl,
                                    boolean cmp_x_out_mode,
                                    sdrv_epwm_cmp_mode_e cmp_x_mode)
{
    REG_RMW32(base + EPWM_CHN_DMA_CTRL_OFF, 16 + chnl, 1, cmp_x_out_mode);
    REG_RMW32(base + EPWM_CHN_DMA_CTRL_OFF, 20 + chnl * 2, 2, cmp_x_mode);
}

void sdrv_epwm_lld_chn_dma_ctrl_two_chn_xx_mode(volatile uint32 base,
        sdrv_epwm_channel_e chnl,
        boolean en)
{
    if (chnl == SDRV_EPWM_CHANNEL_A || chnl == SDRV_EPWM_CHANNEL_C)
        REG_RMW32(base + EPWM_CHN_DMA_CTRL_OFF, 29, 1, en);
    else if (chnl == SDRV_EPWM_CHANNEL_B || chnl == SDRV_EPWM_CHANNEL_D)
        REG_RMW32(base + EPWM_CHN_DMA_CTRL_OFF, 30, 1, en);
}

void sdrv_epwm_lld_dma_wml(volatile uint32 base, sdrv_epwm_channel_e chnl, uint8 val)
{
    if (chnl == SDRV_EPWM_CHANNEL_A)
        REG_RMW32(base + EPWM_DMA_WML_OFF, 0, 6, val);
    else if (chnl == SDRV_EPWM_CHANNEL_B)
        REG_RMW32(base + EPWM_DMA_WML_OFF, 8, 5, val);
    else if (chnl == SDRV_EPWM_CHANNEL_C)
        REG_RMW32(base + EPWM_DMA_WML_OFF, 16, 4, val);
    else if (chnl == SDRV_EPWM_CHANNEL_D)
        REG_RMW32(base + EPWM_DMA_WML_OFF, 24, 4, val);
}

void sdrv_epwm_lld_config_dma_ctl_cfg(volatile uint32 base, boolean sig_mask, uint8 val)
{
    REG_RMW32(base + EPWM_CONFIG_DMA_CTL_OFF, 1, 1, sig_mask);
    REG_RMW32(base + EPWM_CONFIG_DMA_CTL_OFF, 2, 6, val & 0x3f);
}

uint32 sdrv_epwm_lld_fifo_sta_fifo(volatile uint32 base, sdrv_epwm_channel_e chnl)
{
    if (chnl == SDRV_EPWM_CHANNEL_A || chnl == SDRV_EPWM_CHANNEL_B)
        return readl(base + EPWM_FIFO_STA0_OFF);
    else if (chnl == SDRV_EPWM_CHANNEL_C || chnl == SDRV_EPWM_CHANNEL_D) {
        return readl(base + EPWM_FIFO_STA1_OFF);
    }

    return 0;
}

void sdrv_epwm_lld_cnt_cfg_set_trig_sel(
    volatile uint32 base, sdrv_epwm_cnt_gx_e cnt_gx,
    sdrv_epwm_cnt_cfg_set_upd_sel_e set_mode_sel,
    sdrv_epwm_event_trigger_mode_e set_trig_sel)
{
    REG_RMW32(base + CNT_CFG(cnt_gx), 3, 2, set_mode_sel);
    REG_RMW32(base + CNT_CFG(cnt_gx), 1, 2, set_trig_sel);
}

void sdrv_epwm_lld_cmp_config_clr_set(
    volatile uint32 base, sdrv_epwm_channel_e chnl,
    sdrv_epwm_event_trigger_mode_e cmp_set_trig_sel,
    sdrv_epwm_event_trigger_mode_e cmp_clr_trig_sel)
{

    REG_RMW32(base + CMP_CONFIG(chnl), 10, 2, cmp_set_trig_sel);
    REG_RMW32(base + CMP_CONFIG(chnl), 12, 2, cmp_clr_trig_sel);
}

void sdrv_epwm_lld_cmp_config(volatile uint32 base, sdrv_epwm_channel_e chnl,
                              sdrv_epwm_cmp_cfg_t *cfg)
{
    uint32 val = cfg->con_mode << 0 | cfg->cnt_sel << 2 |
                   cfg->rld_trig_mode << 4 | cfg->hw_rld_mode << 5;

    REG_RMW32(base + CMP_CONFIG(chnl), 0, 6, val);
    REG_RMW32(base + CMP_CONFIG(chnl), 15, 1, cfg->sw_rld_mode);
    REG_RMW32(base + CMP_CONFIG(chnl), 24, 8, cfg->refresh_intval);

    sdrv_epwm_lld_chn_dma_ctrl_cmp(base, chnl, cfg->cmp_x_out_mode,
                                   cfg->cmp_x_mode);
    sdrv_epwm_lld_cmp_event_out_mode(base, chnl, &(cfg->out_mode));
    sdrv_epwm_lld_cmp_pulse_wid0(base, chnl, &(cfg->wid0));
    sdrv_epwm_lld_cmp_pulse_wid1(base, chnl, &(cfg->wid1));
}

void sdrv_epwm_lld_cmp_event_out_mode(volatile uint32 base, sdrv_epwm_channel_e chnl,
                                      sdrv_epwm_cmp_event_out_t *out_mode)
{
    uint32 val = out_mode->cmp00 << 0 | out_mode->cmp01 << 4 |
                   out_mode->cmp10 << 8 | out_mode->cmp11 << 12 |
                   out_mode->cmp0_ovf << 16 | out_mode->cmp1_ovf << 20;

    writel(val, base + CMP_EVENT_OUT_MODE(chnl));
}

void sdrv_epwm_lld_cmp_pulse_wid0(volatile uint32 base, sdrv_epwm_channel_e chnl,
                                  sdrv_epwm_cmp_pulse_wid0_t *wid)
{
    uint32 val = (wid->cmp00 & 0xff) << 0 | (wid->cmp01 & 0xff) << 8 |
                   (wid->cmp10 & 0xff) << 16 | (wid->cmp11 & 0xff) << 24;
    writel(val, base + CMP_PULSE_WID0(chnl));
}

void sdrv_epwm_lld_cmp_pulse_wid1(volatile uint32 base, sdrv_epwm_channel_e chnl,
                                  sdrv_epwm_cmp_pulse_wid1_t *wid)
{
    uint16 val = (wid->cmp1_ovf & 0xff) << 0 | (wid->cmp0_ovf & 0xff) << 8;
    writel(val, base + CMP_PULSE_WID1(chnl));
}

void sdrv_epwm_lld_cmp_dither(volatile uint32 base, sdrv_epwm_channel_e chnl,
                              uint8 clip_rslt, uint16 init_offset)
{
    REG_RMW32(base + CMP_DITHER(chnl), 2, 4, clip_rslt);
    REG_RMW32(base + CMP_DITHER(chnl), 16, 16, init_offset);
}

void sdrv_epwm_lld_cmp_ctrl_cmp_init_status(volatile uint32 base,
        sdrv_epwm_channel_e chnl,
        boolean cmp0_init, boolean cmp1_init)
{

    REG_RMW32(base + EPWM_CMP_CTRL_OFF, chnl * 2 + 12, 1, cmp0_init);
    REG_RMW32(base + EPWM_CMP_CTRL_OFF, chnl * 2 + 13, 1, cmp1_init);
}

void sdrv_epwm_lld_cmp_sse_ctrl_cfg(volatile uint32 base, sdrv_epwm_channel_e chnl,
                                    sdrv_epwm_cmp_sse_ctrl_t *cfg)
{
    uint32 val =
        (cfg->sse_mode[0] << 1 | cfg->sse_mode[1] << 2 | cfg->sse_mode[2] << 3 |
         cfg->sse_mode[3] << 4 | cfg->sse_mode[4] << 5 | cfg->edge_sel[0] << 6 |
         cfg->edge_sel[1] << 8 | cfg->edge_sel[2] << 10 |
         cfg->edge_sel[3] << 12 | cfg->edge_sel[4] << 14) >>
        1;
    REG_RMW32(base + EPWM_SSE(chnl), 1, 15, val & 0x7fff);
}

void sdrv_epwm_lld_cmp_input_sel(volatile uint32 base, sdrv_epwm_channel_e chnl,
                                 sdrv_epwm_input_sel_t *cfg)
{
    uint8 val = cfg->set_sel | cfg->clr_sel << 4;
    REG_RMW32(base + CMP_INPUT_SEL(chnl), 0, 8, val);
}

void sdrv_epwm_lld_ext_output_sel(volatile uint32 base, sdrv_epwm_input_sel_t *cfg)
{
    uint8 val = cfg->set_sel | cfg->clr_sel << 4;
    REG_RMW32(base + EPWM_EXT_OUTPUT_SEL_OFF, 0, 8, val);
}

void sdrv_epwm_lld_trigc_pol_inv(volatile uint32 base, sdrv_epwm_trigc_pol_inv_t *cfg)
{
    uint16 val =
        cfg->trigc_pol_inv_cmp_a_set << 0 | cfg->trigc_pol_inv_cmp_a_clr << 1 |
        cfg->trigc_pol_inv_cmp_b_set << 2 | cfg->trigc_pol_inv_cmp_b_clr << 3 |
        cfg->trigc_pol_inv_cmp_c_set << 4 | cfg->trigc_pol_inv_cmp_c_clr << 5 |
        cfg->trigc_pol_inv_cmp_d_set << 6 | cfg->trigc_pol_inv_cmp_d_clr << 7 |
        cfg->trigc_pol_inv_cnt_g0_set << 8 |
        cfg->trigc_pol_inv_cnt_g0_clr << 9 |
        cfg->trigc_pol_inv_cnt_g1_set << 10 |
        cfg->trigc_pol_inv_cnt_g1_clr << 11 | cfg->trigc_pol_inv_ext_set << 12 |
        cfg->trigc_pol_inv_ext_clr << 13;

    REG_RMW32(base + EPWM_TRIGC_POL_INV_OFF, 0, 14, val & 0x3fff);
}

void sdrv_epwm_lld_cmp_sw_trig(volatile uint32 base, sdrv_epwm_cmp_sw_trig_t *cfg)
{
    uint8 val =
        cfg->cmp_sw_trig_cmp_a_set << 0 | cfg->cmp_sw_trig_cmp_b_set << 1 |
        cfg->cmp_sw_trig_cmp_c_set << 2 | cfg->cmp_sw_trig_cmp_d_set << 3 |
        cfg->cmp_sw_trig_cmp_a_clr << 4 | cfg->cmp_sw_trig_cmp_b_clr << 5 |
        cfg->cmp_sw_trig_cmp_c_clr << 6 | cfg->cmp_sw_trig_cmp_d_clr << 7;

    REG_RMW32(base + EPWM_CMP_SW_TRIG_OFF, 0, 8, val);
}

void sdrv_epwm_lld_cnt_ext_sw_trig(volatile uint32 base,
                                   sdrv_epwm_cnt_ext_sw_trig_t *cfg)
{

    uint8 val = cfg->cnt_ext_sw_trig_cnt_g0_set << 0 |
                  cfg->cnt_ext_sw_trig_cnt_g0_clr << 1 |
                  cfg->cnt_ext_sw_trig_cnt_g1_set << 2 |
                  cfg->cnt_ext_sw_trig_cnt_g1_clr << 3 |
                  cfg->cnt_ext_sw_trig_ext_set << 4 |
                  cfg->cnt_ext_sw_trig_ext_clr << 5;
    REG_RMW32(base + EPWM_CNT_EXT_SW_TRIG_OFF, 0, 6, val);
}

void sdrv_epwm_lld_sw_trig_pulse(volatile uint32 base, sdrv_epwm_channel_e chnl,
                                 sdrv_epwm_sw_trig_pulse_width_t *cfg)
{
    uint32 val1 = cfg->trig0_pulse_width << 0 | cfg->trig1_pulse_width << 16;
    uint32 val2 = cfg->trig2_pulse_width << 0 | cfg->trig3_pulse_width << 16;

    if (chnl == SDRV_EPWM_CHANNEL_A || chnl == SDRV_EPWM_CHANNEL_B)
        writel(val1, base + EPWM_SW_TRIG_PULSE0_OFF);
    else if (chnl == SDRV_EPWM_CHANNEL_C || chnl == SDRV_EPWM_CHANNEL_D)
        writel(val2, base + EPWM_SW_TRIG_PULSE1_OFF);
}

void sdrv_epwm_lld_fault_flt(volatile uint32 base, sdrv_epwm_channel_e chnl,
                             sdrv_epwm_fault_flt_t *cfg)
{
    uint32 val =
        (cfg->flt_edge_sel << 1 | (cfg->pos_band_wid - 2) << 4 |
         (cfg->neg_band_wid - 2) << 8 | (cfg->smpl_intval - 1) << 12) >>
        1;

    REG_RMW32(base + FAULT_FLT(chnl), 1, 19, val & 0x7ffff);
}

void sdrv_epwm_lld_sync_dis(volatile uint32 base, sdrv_epwm_sync_dis_t *cfg)
{

    uint8 val = cfg->sdrv_epwm_sync_dis_ext_set << 0 |
                  cfg->sdrv_epwm_sync_dis_ext_clr << 1 |
                  cfg->sdrv_epwm_sync_dis_fault0 << 2 |
                  cfg->sdrv_epwm_sync_dis_fault1 << 3 |
                  cfg->sdrv_epwm_sync_dis_fault2 << 4 |
                  cfg->sdrv_epwm_sync_dis_fault3 << 5;

    REG_RMW32(base + EPWM_SYNC_DIS_OFF, 0, 6, val & 0x3f);
}

void sdrv_epwm_lld_cmp_fault_event_ctrl_config(
    volatile uint32 base, sdrv_epwm_channel_e chnl, sdrv_epwm_sub_channel_e sub_chnl,
    sdrv_epwm_cmp_fault_event_ctrl_t *cfg)
{
    uint8 val = (cfg->fault_pol << 1 | cfg->fault_clr_mode << 2) >> 1;

    REG_RMW32(base + CMP_FAULT_EVENT_CTRL(chnl), 1 + sub_chnl * 4, 2, val & 0x3);
}

void sdrv_epwm_lld_cmp_fault_event_fs_sta_set(volatile uint32 base,
        sdrv_epwm_channel_e chnl,
        boolean cmp0_sta, boolean cmp1_sta)
{
    uint8 val = cmp0_sta | cmp1_sta << 1;
    REG_RMW32(base + CMP_DTI_CTRL(chnl), 3, 2, val);
}

void sdrv_epwm_lld_cmp_prefin_pol(volatile uint32 base, sdrv_epwm_channel_e chnl,
                                  sdrv_epwm_cmp_prefin_pol_t *prefin_pol)
{
    REG_RMW32(base + CMP_DTI_CTRL(chnl), 1, 1, prefin_pol->cmp0_pol);
    REG_RMW32(base + CMP_DTI_CTRL(chnl), 2, 1, prefin_pol->cmp1_pol);
}

void sdrv_epwm_lld_cmp_dti_wid(volatile uint32 base, sdrv_epwm_channel_e chnl,
                               uint16 dt0_wid, uint16 dt1_wid)
{
    uint32 val = dt0_wid << 0 | dt1_wid << 16;

    writel(val, base + CMP_DTI_WID(chnl));
}

void sdrv_epwm_lld_cmp_dti_cbc(volatile uint32 base, sdrv_epwm_channel_e chnl, boolean en)
{
    if (get_epwm_version() == 1) {
        uint8 index = 0;

        for (index = 0; index < 4; index++) {
            if (APB_EPWM1_BASE + 0x10000 * index == base)
                break;
        }

        REG_RMW32(EPWM_CBC_ZERO_VECTOR_BY_SCR_ADDR, CBC_POS(index, chnl), 1, en);
    }
}

void sdrv_epwm_lld_cmp_dti_zero_vector(volatile uint32 base, sdrv_epwm_channel_e chnl,
                                       boolean en)
{
    if (get_epwm_version() == 1) {
        uint8 index = 0;

        for (index = 0; index < 4; index++) {
            if (APB_EPWM1_BASE + 0x10000 * index == base)
                break;
        }

        REG_RMW32(EPWM_CBC_ZERO_VECTOR_BY_SCR_ADDR, ZERO_VECTOR_POS(index, chnl),
                  1, en);
    }
}

#ifdef SEMIDRIVE_E3_LITE_SERIES

void sdrv_epwm_lld_cmp_sw_frc_dis(volatile uint32 base, sdrv_epwm_channel_e chnl,
                                  sdrv_epwm_output_e sub_chnl, boolean en)
{
        uint8 index = 0;

        for (index = 0; index < 2; index++) {
            if (APB_EPWM1_BASE + 0x10000 * index == base)
                break;
        }

        RMWREG32(EPWM_CBC_ZERO_VECTOR_BY_SCR_ADDR, SW_FRC_DIS_POS(index, chnl, sub_chnl),
                  1, en);
}

void sdrv_epwm_lld_center_align_cmp_int_enable(volatile uint32 base, uint32 val)
{
    sdrv_epwm_lld_center_align_cmp_int_sta_enable(base, val);
    sdrv_epwm_lld_center_align_cmp_int_sig_enable(base, val);
}

void sdrv_epwm_lld_center_align_cmp_int_sta_enable(volatile uint32 base, uint32 val)
{
    uint32 sta = sdrv_epwm_lld_center_align_cmp_int_sta_en(base);
    writel(sta | val, base + EPWM_CENTER_ALIGN_CMP_INT_STA_EN_OFF);
}

void sdrv_epwm_lld_center_align_cmp_int_sta_dis(volatile uint32 base, uint32 val)
{
    uint32 sta = sdrv_epwm_lld_center_align_cmp_int_sta_en(base);
    writel(sta & (~val), base + EPWM_CENTER_ALIGN_CMP_INT_STA_EN_OFF);
}

void sdrv_epwm_lld_center_align_cmp_int_sig_enable(volatile uint32 base, uint32 val)
{
    uint32 sta = sdrv_epwm_lld_center_align_cmp_int_sta_en(base);
    writel(sta | val, base + EPWM_CENTER_ALIGN_CMP_INT_SIG_EN_OFF);
}

void sdrv_epwm_lld_center_align_cmp_int_sig_dis(volatile uint32 base, uint32 val)
{
    uint32 sta = sdrv_epwm_lld_center_align_cmp_int_sig_en(base);
    writel(sta & (~val), base + EPWM_CENTER_ALIGN_CMP_INT_SIG_EN_OFF);
}

void sdrv_epwm_lld_cmp_dti_idle_sta(volatile uint32 base, sdrv_epwm_channel_e chnl,
                                    boolean cmp0_idle_status,
                                    boolean cmp1_idle_status)
{
    uint8 val = cmp0_idle_status | cmp1_idle_status << 1;
    REG_RMW32(base + CMP_DTI_CTRL(chnl), 8, 2, val);
}

#endif

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif
