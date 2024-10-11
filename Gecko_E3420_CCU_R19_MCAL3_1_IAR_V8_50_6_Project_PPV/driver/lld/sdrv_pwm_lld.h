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
 * @file  sdrv_pwm_lld.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Pwm
 */

#ifndef DRV_LLD_SDRV_EPWM_H
#define DRV_LLD_SDRV_EPWM_H

#ifdef __cplusplus
extern "C" {
#endif

#include "__compiler.h"
#include "__regs_base.h"
#include "RegHelper.h"

#ifndef ASSEMBLY

__BEGIN_CDECLS

#define EPWM_INT_STA_OFF 0x0U
#define EPWM_INT_STA_EN_OFF 0x4U
#define EPWM_INT_SIG_EN_OFF 0x8U
#define EPWM_COR_ERR_INT_STA_OFF 0xcU
#define EPWM_COR_ERR_INT_STA_EN_OFF 0x10U
#define EPWM_COR_ERR_INT_SIG_EN_OFF 0x14U
#define EPWM_UNC_ERR_INT_STA_OFF 0x18U
#define EPWM_UNC_ERR_INT_STA_EN_OFF 0x1cU
#define EPWM_UNC_ERR_INT_SIG_EN_OFF 0x20U
#define EPWM_FUSA_COR_ERR_INT_STA_OFF 0x24U
#define EPWM_FUSA_COR_ERR_INT_STA_EN_OFF 0x28U
#define EPWM_FUSA_COR_ERR_INT_SIG_EN_OFF 0x2cU
#define EPWM_FUSA_UNC_ERR_INT_STA_OFF 0x30U
#define EPWM_FUSA_UNC_ERR_INT_STA_EN_OFF 0x34U
#define EPWM_FUSA_UNC_ERR_INT_SIG_EN_OFF 0x38U
#define EPWM_FUSA_UNC_ERR_INT_STA_1_OFF 0x3cU
#define EPWM_FUSA_UNC_ERR_INT_STA_EN_1_OFF 0x40U
#define EPWM_FUSA_UNC_ERR_INT_SIG_EN_1_OFF 0x44U
#define EPWM_REG_PARITY_ERR_INT_STAT_OFF 0x4cU
#define EPWM_REG_PARITY_ERR_INT_STAT_EN_OFF 0x50U
#define EPWM_REG_PARITY_ERR_INT_SIG_EN_OFF 0x54U
#define EPWM_PRDATAINJ_OFF 0x5cU
#define EPWM_RAM_RDATA_INJ_OFF 0x60U
#define EPWM_RAM_RECC_INJ_OFF 0x64U
#define EPWM_RAM_RDATA_MON_INJ_OFF 0x68U
#define EPWM_RAM_RECC_MON_INJ_OFF 0x6cU
#define EPWM_PWDATA_INJ_OFF 0x70U
#define EPWM_PWECC_INJ_OFF 0x74U
#define EPWM_DMA_FW_DATA_INJ_OFF 0x80U
#define EPWM_DMA_FW_CODE_INJ_OFF 0x84U
#define EPWM_DMA_BW_DATA_INJ_OFF 0x88U
#define EPWM_DMA_BW_CODE_INJ_OFF 0x8cU
#define EPWM_INT_ERR_INJ_OFF 0x90U
#define EPWM_CLK_MON_CMP_ERR_INJ_OFF 0x94U
#define EPWM_CLK_CONFIG_OFF 0xa0U
#define EPWM_CLK_MON_EN_OFF 0xa4U
#define EPWM_SW_RST_OFF 0xa8U
#define EPWM_CHN_DMA_CTRL_OFF 0xb0U
#define EPWM_DMA_WML_OFF 0xb4U
#define EPWM_CONFIG_DMA_CTL_OFF 0xb8U
#define EPWM_FIFO_REQ_STATUS_OFF 0xbcU
#define EPWM_FIFO_A_OFF 0xc0U
#define EPWM_FIFO_B_OFF 0xc4U
#define EPWM_FIFO_C_OFF 0xc8U
#define EPWM_FIFO_D_OFF 0xccU
#define EPWM_FIFO_STA0_OFF 0xd0U
#define EPWM_FIFO_STA1_OFF 0xd4U
#define EPWM_CNT_G0_INIT_OFF 0x100U
#define EPWM_CNT_G0_OVF_OFF 0x104U
#define EPWM_CNT_G0_CFG_OFF 0x108U
#define EPWM_CNT_G0_EN_OFF 0x10cU
#define EPWM_CNT_G0_OFF 0x110U
#define EPWM_CNT_G0_MFC_OFF 0x114U
#define EPWM_CNT_G1_INIT_OFF 0x120U
#define EPWM_CNT_G1_OVF_OFF 0x124U
#define EPWM_CNT_G1_CFG_OFF 0x128U
#define EPWM_CNT_G1_OFF 0x130U
#define EPWM_CNT_G1_MFC_OFF 0x134U
#define EPWM_CMP_A_CONFIG_OFF 0x220U
#define EPWM_CMP_A_EVENT_OUT_MODE_OFF 0x224U
#define EPWM_CMP_A_PULSE_WID0_OFF 0x228U
#define EPWM_CMP_A_PULSE_WID1_OFF 0x22cU
#define EPWM_CMP_A_00_VAL_OFF 0x230U
#define EPWM_CMP_A_01_VAL_OFF 0x234U
#define EPWM_CMP_A_10_VAL_OFF 0x238U
#define EPWM_CMP_A_11_VAL_OFF 0x23cU
#define EPWM_CMP_A_DITHER_OFF 0x240U
#define EPWM_CMP_A_OFFSET_OFF 0x244U
#define EPWM_CMP_B_CONFIG_OFF 0x250U
#define EPWM_CMP_B_EVENT_OUT_MODE_OFF 0x254U
#define EPWM_CMP_B_PULSE_WID0_OFF 0x258U
#define EPWM_CMP_B_PULSE_WID1_OFF 0x25cU
#define EPWM_CMP_B_00_VAL_OFF 0x260U
#define EPWM_CMP_B_01_VAL_OFF 0x264U
#define EPWM_CMP_B_10_VAL_OFF 0x268U
#define EPWM_CMP_B_11_VAL_OFF 0x26cU
#define EPWM_CMP_B_DITHER_OFF 0x270U
#define EPWM_CMP_B_OFFSET_OFF 0x274U
#define EPWM_CMP_C_CONFIG_OFF 0x280U
#define EPWM_CMP_C_EVENT_OUT_MODE_OFF 0x284U
#define EPWM_CMP_C_PULSE_WID0_OFF 0x288U
#define EPWM_CMP_C_PULSE_WID1_OFF 0x28cU
#define EPWM_CMP_C_00_VAL_OFF 0x290U
#define EPWM_CMP_C_01_VAL_OFF 0x294U
#define EPWM_CMP_C_10_VAL_OFF 0x298U
#define EPWM_CMP_C_11_VAL_OFF 0x29cU
#define EPWM_CMP_C_DITHER_OFF 0x2a0U
#define EPWM_CMP_C_OFFSET_OFF 0x2a4U
#define EPWM_CMP_D_CONFIG_OFF 0x2b0U
#define EPWM_CMP_D_EVENT_OUT_MODE_OFF 0x2b4U
#define EPWM_CMP_D_PULSE_WID0_OFF 0x2b8U
#define EPWM_CMP_D_PULSE_WID1_OFF 0x2bcU
#define EPWM_CMP_D_00_VAL_OFF 0x2c0U
#define EPWM_CMP_D_01_VAL_OFF 0x2c4U
#define EPWM_CMP_D_10_VAL_OFF 0x2c8U
#define EPWM_CMP_D_11_VAL_OFF 0x2ccU
#define EPWM_CMP_D_DITHER_OFF 0x2d0U
#define EPWM_CMP_D_OFFSET_OFF 0x2d4U
#define EPWM_CMP_CTRL_OFF 0x2e0U
#define EPWM_CMP_A_SSE_CTRL_OFF 0x320U
#define EPWM_CMP_A_SSE_REG_OFF 0x324U
#define EPWM_CMP_B_SSE_CTRL_OFF 0x328U
#define EPWM_CMP_B_SSE_REG_OFF 0x32cU
#define EPWM_CMP_C_SSE_CTRL_OFF 0x330U
#define EPWM_CMP_D_SSE_CTRL_OFF 0x338U
#define EPWM_CMP_D_SSE_REG_OFF 0x33cU
#define EPWM_CMP_A_INPUT_SEL_OFF 0x350U
#define EPWM_CMP_B_INPUT_SEL_OFF 0x354U
#define EPWM_CMP_C_INPUT_SEL_OFF 0x358U
#define EPWM_CMP_D_INPUT_SEL_OFF 0x35cU
#define EPWM_CNT_G0_INPUT_SEL_OFF 0x360U
#define EPWM_CNT_G1_INPUT_SEL_OFF 0x364U
#define EPWM_EXT_OUTPUT_SEL_OFF 0x368U
#define EPWM_TRIGC_POL_INV_OFF 0x36cU
#define EPWM_CMP_SW_TRIG_OFF 0x374U
#define EPWM_CNT_EXT_SW_TRIG_OFF 0x378U
#define EPWM_SW_TRIG_CTRL_OFF 0x380U
#define EPWM_SW_TRIG_STATUS_OFF 0x384U
#define EPWM_SW_TRIG_PULSE0_OFF 0x388U
#define EPWM_SW_TRIG_PULSE1_OFF 0x38cU
#define EPWM_FAULT0_FLT_OFF 0x410U
#define EPWM_FAULT1_FLT_OFF 0x414U
#define EPWM_FAULT2_FLT_OFF 0x418U
#define EPWM_FAULT3_FLT_OFF 0x41cU
#define EPWM_SYNC_DIS_OFF 0x420U
#define EPWM_CMP_A_FAULT_EVENT_CTRL_OFF 0x440U
#define EPWM_CMP_B_FAULT_EVENT_CTRL_OFF 0x444U
#define EPWM_CMP_C_FAULT_EVENT_CTRL_OFF 0x448U
#define EPWM_CMP_D_FAULT_EVENT_CTRL_OFF 0x44cU
#define EPWM_CMP_A_DTI_CTRL_OFF 0x460U
#define EPWM_CMP_A_DTI_WID_OFF 0x464U
#define EPWM_CMP_B_DTI_CTRL_OFF 0x468U
#define EPWM_CMP_B_DTI_WID_OFF 0x46cU
#define EPWM_CMP_C_DTI_CTRL_OFF 0x470U
#define EPWM_CMP_C_DTI_WID_OFF 0x474U
#define EPWM_CMP_D_DTI_CTRL_OFF 0x478U
#define EPWM_CMP_D_DTI_WID_OFF 0x47cU
#define EPWM_SIGNAL_STATUS_OFF 0x500U
#define EPWM_SELFTEST_MODE_OFF 0xffcU
#define FM_CLK_CONFIG_DIV_NUM (0xffffU << 0U)
#define BM_CLK_CONFIG_CLK_CHANGE_UPD (0x01U << 31U)
#ifndef SEMIDRIVE_E3_LITE_SERIES
#define EPWM_CBC_ZERO_VECTOR_BY_SCR_ADDR (APB_SCR_SF_BASE + 0x1000 + 0x9c)
#else
#define EPWM_CBC_ZERO_VECTOR_BY_SCR_ADDR (APB_SCR_SF_BASE + 0x1000 + 0x6c)
#endif

#ifdef SEMIDRIVE_E3_LITE_SERIES
#define EPWM_CENTER_ALIGN_CMP_INT_STA_OFF 0xf0U
#define EPWM_CENTER_ALIGN_CMP_INT_STA_EN_OFF 0xf4U
#define EPWM_CENTER_ALIGN_CMP_INT_SIG_EN_OFF 0xf8U
#define EPWM_CMP_A_EID_OFF 0x248U
#define EPWM_CMP_A_CONFIG1_OFF 0x24cU
#define EPWM_CMP_B_CONFIG1_OFF 0x27cU
#define EPWM_CMP_C_CONFIG1_OFF 0x2acU
#define EPWM_CMP_D_CONFIG1_OFF 0x2dcU
#define EPWM_CMP_FAULT_EVENT_STA_OFF 0x450U
#define EPWM_CENTER_ALIGN_CNT_DIR_OFF 0x540U
#else
#define EPWM_CMP_A_EID_OFF 0x24cU
#endif

#define FIFO(chnl) (EPWM_FIFO_A_OFF + chnl * 4)
#define CNT_INIT_VAL(cnt_gx) (EPWM_CNT_G0_INIT_OFF + cnt_gx * 0x20)
#define CNT_OVF_VAL(cnt_gx) (EPWM_CNT_G0_OVF_OFF + cnt_gx * 0x20)
#define CNT_CFG(cnt_gx) (EPWM_CNT_G0_CFG_OFF + cnt_gx * 0x20)
#define CNT_EN(cnt_gx) (EPWM_CNT_G0_EN_OFF + cnt_gx * 0x20)
#define CNT(cnt_gx) (EPWM_CNT_G0_OFF + cnt_gx * 0x20)
#define CNT_MFC(cnt_gx) (EPWM_CNT_G0_MFC_OFF + cnt_gx * 0x20)
#define CMP_CONFIG(chnl) (EPWM_CMP_A_CONFIG_OFF + chnl * 0x30)
#define CMP_EVENT_OUT_MODE(chnl) (EPWM_CMP_A_EVENT_OUT_MODE_OFF + chnl * 0x30)
#define CMP_PULSE_WID0(chnl) (EPWM_CMP_A_PULSE_WID0_OFF + chnl * 0x30)
#define CMP_PULSE_WID1(chnl) (EPWM_CMP_A_PULSE_WID1_OFF + chnl * 0x30)
#define CMP_VAL(chnl, cmp_xx)                                                  \
    (EPWM_CMP_A_00_VAL_OFF + chnl * 0x30 + cmp_xx * 0x4)
#define CMP_DITHER(chnl) (EPWM_CMP_A_DITHER_OFF + chnl * 0x30)
#define CMP_OFFSET(chnl) (EPWM_CMP_A_OFFSET_OFF + chnl * 0x30)
#define EPWM_SSE(chnl) (EPWM_CMP_A_SSE_CTRL_OFF + chnl * 0x8)
#define EPWM_SSE_REG(chnl) (EPWM_CMP_A_SSE_REG_OFF + chnl * 0x8)
#define CMP_INPUT_SEL(chnl) (EPWM_CMP_A_INPUT_SEL_OFF + chnl * 0x4)
#define CNT_INPUT_SEL(cnt_gx) (EPWM_CNT_G0_INPUT_SEL_OFF + cnt_gx * 0x4)
#define FAULT_FLT(chnl) (EPWM_FAULT0_FLT_OFF + chnl * 4)
#define CMP_FAULT_EVENT_CTRL(chnl) (EPWM_CMP_A_FAULT_EVENT_CTRL_OFF + chnl * 4)
#define CMP_DTI_CTRL(chnl) (EPWM_CMP_A_DTI_CTRL_OFF + chnl * 8)
#define CMP_DTI_WID(chnl) (EPWM_CMP_A_DTI_WID_OFF + chnl * 8)
#define SDRV_EPWM_STA_SHIFT(int_id) (int_id)
#define SDRV_EPWM_STA_MASK(int_id) (0x1 << SDRV_EPWM_STA_SHIFT(int_id))
#define SDRV_EPWM_STA_CNT_OVF_SHIFT(cnt_gx) (cnt_gx + 4)
#ifndef SEMIDRIVE_E3_LITE_SERIES
#define CBC_POS(epwm_id, chnl_id) (epwm_id * 4 + 4 + chnl_id)
#define ZERO_VECTOR_POS(epwm_id, chnl_id) (epwm_id * 4 + chnl_id)
#else
#define ZERO_VECTOR_POS(epwm_id, chnl_id) (epwm_id * 16 + chnl_id)
#define CBC_POS(epwm_id, chnl_id) (epwm_id * 16 + 4 + chnl_id)
#define SW_FRC_DIS_POS(epwm_id, chnl_id, sub_chnl)                             \
    (epwm_id * 16 + 8 + chnl_id * 2 + sub_chnl)
#endif

#ifdef SEMIDRIVE_E3_LITE_SERIES
#define CMP_CONFIG1(chnl) (EPWM_CMP_A_CONFIG1_OFF + chnl * 0x30)
#endif



/**
 * @brief sdrv_epwm_clk_config_src_clk_sel.
 *
 */
typedef enum sdrv_epwm_clk_config_src_clk_sel {
    SDRV_EPWM_HIGH_FREQUENCY_CLOCK,
    SDRV_EPWM_ALTERNATIVE_HIGH_FREQUENCY_CLOCK,
    SDRV_EPWM_EXTERNAL_CLOCK,
    SDRV_EPWM_LOW_POWER_CLOCK,
} sdrv_epwm_clk_config_src_clk_sel_e;

/**
 * @brief sdrv_epwm_clk_mon_en
 *
 */
typedef struct sdrv_epwm_clk_mon_en {
    boolean en_p;
    boolean en_n;
} sdrv_epwm_clk_mon_en_t;

/**
 * @brief sdrv_epwm channel.
 *
 */
typedef enum sdrv_epwm_channel {
    SDRV_EPWM_CHANNEL_A,
    SDRV_EPWM_CHANNEL_B,
    SDRV_EPWM_CHANNEL_C,
    SDRV_EPWM_CHANNEL_D,
    SDRV_EPWM_CHANNEL_NR
} sdrv_epwm_channel_e;


/**
 * @brief sdrv_epwm_output.
 *
 */
typedef enum sdrv_epwm_output {
    SDRV_EPWM_CMP0_OUTPUT,
    SDRV_EPWM_CMP1_OUTPUT,
} sdrv_epwm_output_e;

/**
 * @brief sdrv_epwm_sub_channel.
 *
 */
typedef enum sdrv_epwm_sub_channel {
    SDRV_EPWM_SUB_CHANNEL_A,
    SDRV_EPWM_SUB_CHANNEL_B,
    SDRV_EPWM_SUB_CHANNEL_C,
    SDRV_EPWM_SUB_CHANNEL_D,
    SDRV_EPWM_SUB_CHANNEL_NR
} sdrv_epwm_sub_channel_e;

/**
 * @brief sdrv_epwm_cnt_gx.
 *
 */
typedef enum sdrv_epwm_cnt_gx {
    SDRV_EPWM_CNT_G0,
    SDRV_EPWM_CNT_G1,
    SDRV_EPWM_CNT_MAX_NUM,
} sdrv_epwm_cnt_gx_e;

/**
 * @brief sdrv_epwm_cmp_mode.
 */
typedef enum sdrv_epwm_cmp_mode {
    SDRV_EPWM_SINGLE_COMPARE_MODE,
    SDRV_EPWM_DUAL_COMPARE_MODE,
    SDRV_EPWM_MULTIPLE_COMPARE_MODE,
    SDRV_EPWM_MULTIPLE_COMPARE_MODE_2,
} sdrv_epwm_cmp_mode_e;

/**
 * @brief sdrv_epwm_chn_dma_ctrl_cmp_x_dat_format.
 *
 */
typedef enum sdrv_epwm_chn_dma_ctrl_cmp_x_dat_format {
    SDRV_EPWM_32_BIT_COMPARE_VALUE,
    SDRV_EPWM_16_BIT_COMPARE_VALUE,
    SDRV_EPWM_8_BIT_COMPARE_VALUE,
    SDRV_EPWM_8_BIT_COMPARE_VALUE_2,
} sdrv_epwm_chn_dma_ctrl_cmp_x_dat_format_e;

/**
 * @brief sdrv_epwm_event_trigger_mode .
 *
 */
typedef enum sdrv_epwm_event_trigger_mode {
    SDRV_EPWM_EVENT_IGNORED,
    SDRV_EPWM_POSITIVE_EDGE,
    SDRV_EPWM_NEGATIVE_EDGE,
    SDRV_EPWM_LEVEL_HIGH,
} sdrv_epwm_event_trigger_mode_e;

/**
 * @brief sdrv_epwm_cnt_cfg_upd_trig_sel.
 *
 */
typedef enum sdrv_epwm_cnt_cfg_set_upd_sel {
    SDRV_EPWM_NO_UPDATE,
    SDRV_EPWM_ONLY_RELOAD_OVERFLOW_VALUE,
    SDRV_EPWM_ONLY_RELOAD_COUNTER_INITIAL_VALUE,
    SDRV_EPWM_RELOAD_BOTH_OVERFLOW_AND_INITIAL_VALUE,
} sdrv_epwm_cnt_cfg_set_upd_sel_e;

/**
 * @brief sdrv_epwm_rld_trig_mode.
 *
 */
typedef enum sdrv_epwm_rld_trig_mode {
    SDRV_EPWM_UPDATE_WHEN_OVERFLOW_EVENT_HAPPEN,
    SDRV_EPWM_UPDATE_WHEN_COMPARE_EVENT_HAPPEN,
} sdrv_epwm_rld_trig_mode_e;

/**
 * @brief sdrv_epwm_cmp_xx.
 *
 */
typedef enum sdrv_epwm_cmp_xx {
    SDRV_EPWM_CMP_00,
    SDRV_EPWM_CMP_01,
    SDRV_EPWM_CMP_10,
    SDRV_EPWM_CMP_11,
} sdrv_epwm_cmp_xx_e;

/**
 * @brief sdrv_epwm_cmp_event_out_mode.
 *
 */
typedef enum sdrv_epwm_cmp_event_out_mode {
    SDRV_EPWM_CMP_EVENT_POSITIVE_PULSE,
    SDRV_EPWM_CMP_EVENT_NEGATIVE_PULSE,
    SDRV_EPWM_CMP_EVENT_SIGNAL_TOGGLE,
    SDRV_EPWM_CMP_EVENT_LEVEL_HIGH,
    SDRV_EPWM_CMP_EVENT_LEVEL_LOW,
    SDRV_EPWM_CMP_EVENT_KEEP,
} sdrv_epwm_cmp_event_out_mode_e;

/**
 * @brief sdrv_epwm_cmp_event_out.
 *
 */
typedef struct sdrv_epwm_cmp_event_out {
    sdrv_epwm_cmp_event_out_mode_e cmp00;
    sdrv_epwm_cmp_event_out_mode_e cmp01;
    sdrv_epwm_cmp_event_out_mode_e cmp10;
    sdrv_epwm_cmp_event_out_mode_e cmp11;
    sdrv_epwm_cmp_event_out_mode_e cmp0_ovf;
    sdrv_epwm_cmp_event_out_mode_e cmp1_ovf;
} sdrv_epwm_cmp_event_out_t;

/**
 * @brief sdrv_sdrv_epwm_cmp_pulse_wid0.
 *
 */
typedef struct sdrv_epwm_cmp_pulse_wid0 {
    uint16 cmp00;
    uint16 cmp01;
    uint16 cmp10;
    uint16 cmp11;
} sdrv_epwm_cmp_pulse_wid0_t;

/**
 * @brief sdrv_epwm_cmp_pulse_wid1.
 *
 */
typedef struct sdrv_epwm_cmp_pulse_wid1 {
    uint16 cmp0_ovf;
    uint16 cmp1_ovf;
} sdrv_epwm_cmp_pulse_wid1_t;

/**
 * @brief sdrv_epwm_input_sel_trig.
 *
 */
typedef enum sdrv_epwm_input_sel_trig {
    SDRV_EPWM_INPUT_SEL_TRIG_EXT_SET,
    SDRV_EPWM_INPUT_SEL_TRIG_EXT_CLR,
    SDRV_EPWM_INPUT_SEL_TRIG_CPT_A_CE,
    SDRV_EPWM_INPUT_SEL_TRIG_CPT_B_CE,
    SDRV_EPWM_INPUT_SEL_TRIG_CPT_C_CE,
    SDRV_EPWM_INPUT_SEL_TRIG_CPT_D_CE,
    SDRV_EPWM_INPUT_SEL_TRIG_CNT_G0_CE,
    SDRV_EPWM_INPUT_SEL_TRIG_CNT_G1_CE,
    SDRV_EPWM_INPUT_SEL_TRIG_LEVEL_LOW = 9,
    SDRV_EPWM_INPUT_SEL_TRIG_LEVEL_HIGH,
    SDRV_EPWM_INPUT_SEL_TRIG_SW_PROGRAM_PULSE,
    SDRV_EPWM_INPUT_SEL_TRIG_SW_TRIG0,
    SDRV_EPWM_INPUT_SEL_TRIG_SW_TRIG1,
    SDRV_EPWM_INPUT_SEL_TRIG_SW_TRIG2,
    SDRV_EPWM_INPUT_SEL_TRIG_SW_TRIG3,
} sdrv_epwm_input_sel_trig_e;

/**
 * @brief sdrv_epwm_cmp_cfg.
 *
 */
typedef struct sdrv_epwm_cmp_cfg {
    boolean con_mode;
    sdrv_epwm_cnt_gx_e cnt_sel;
    sdrv_epwm_rld_trig_mode_e rld_trig_mode;
    boolean hw_rld_mode;
    boolean sw_rld_mode;
    uint8 refresh_intval;
    sdrv_epwm_cmp_event_out_t out_mode;
    boolean cmp_x_out_mode;
    sdrv_epwm_cmp_mode_e cmp_x_mode;
    sdrv_epwm_cmp_pulse_wid0_t wid0;
    sdrv_epwm_cmp_pulse_wid1_t wid1;
} sdrv_epwm_cmp_cfg_t;

/**
 * @brief sdrv_epwm_cmp_dither.
 *
 */
typedef struct sdrv_epwm_cmp_dither_cfg {
    uint8 clip_rslt;
    uint16 init_offset;
} sdrv_epwm_cmp_dither_cfg_t;

/**
 * @brief sdrv_epwm_cmp_x_init_status
 *
 */
typedef struct sdrv_epwm_cmp_x_init_status {
    boolean cmp_a0_init_status;
    boolean cmp_a1_init_status;
    boolean cmp_b0_init_status;
    boolean cmp_b1_init_status;
    boolean cmp_c0_init_status;
    boolean cmp_c1_init_status;
    boolean cmp_d0_init_status;
    boolean cmp_d1_init_status;
} sdrv_epwm_cmp_x_init_status_t;

/**
 * @brief sdrv_epwm_edge_sel.
 *
 */
typedef enum sdrv_epwm_edge_sel {
    SRV_EPWM_EDGE_SEL_RISING_EDGE,
    SDRV_EPWM_EDGE_SEL_FAILING_EDGE,
    SDRV_EPWM_EDGE_SEL_BOTH_EDGE,
    SDRV_EPWM_EDGE_SEL_BOTH_EDGE_2,
} sdrv_epwm_edge_sel_e;

/**
 * @brief sdrv_epwm_sse_so_det_fault  .
 *
 */
typedef enum sdrv_epwm_sse_so_det_fault {
    SDRV_EPWM_EDGE_SSE_SO_DET_FAULT_LEVEL_LOW,
    SDRV_EPWM_EDGE_SSE_SO_DET_FAULT_LEVEL_HIGH,
    SDRV_EPWM_EDGE_SSE_SO_DET_FAULT_POSEDGE,
    SDRV_EPWM_EDGE_SSE_SO_DET_FAULT_NEGEDGE,
    SDRV_EPWM_EDGE_SSE_SO_DET_FAULT_BOTH_EDGE,
} sdrv_epwm_sse_so_det_fault_e;

/**
 * @brief sdrv_epwm_cmp_sse_ctrl.
 *
 */
typedef struct sdrv_epwm_cmp_sse_ctrl {
    boolean sse_mode[5];
    sdrv_epwm_edge_sel_e edge_sel[5];
    sdrv_epwm_sse_so_det_fault_e sse_so_det_fault;
} sdrv_epwm_cmp_sse_ctrl_t;

/**
 * @brief sdrv_epwm_input_sel.
 *
 */
typedef struct sdrv_epwm_input_sel {
    sdrv_epwm_input_sel_trig_e set_sel;
    sdrv_epwm_input_sel_trig_e clr_sel;
} sdrv_epwm_input_sel_t;

/**
 * @brief sdrv_epwm_trigc_pol_inv.
 *
 */
typedef struct sdrv_epwm_trigc_pol_inv {
    boolean trigc_pol_inv_cmp_a_set;
    boolean trigc_pol_inv_cmp_a_clr;
    boolean trigc_pol_inv_cmp_b_set;
    boolean trigc_pol_inv_cmp_b_clr;
    boolean trigc_pol_inv_cmp_c_set;
    boolean trigc_pol_inv_cmp_c_clr;
    boolean trigc_pol_inv_cmp_d_set;
    boolean trigc_pol_inv_cmp_d_clr;
    boolean trigc_pol_inv_cnt_g0_set;
    boolean trigc_pol_inv_cnt_g0_clr;
    boolean trigc_pol_inv_cnt_g1_set;
    boolean trigc_pol_inv_cnt_g1_clr;
    boolean trigc_pol_inv_ext_set;
    boolean trigc_pol_inv_ext_clr;
} sdrv_epwm_trigc_pol_inv_t;

/**
 * @brief sdrv_epwm_cmp_sw_trig  .
 *
 */
typedef struct sdrv_epwm_cmp_sw_trig {
    boolean cmp_sw_trig_cmp_a_set;
    boolean cmp_sw_trig_cmp_b_set;
    boolean cmp_sw_trig_cmp_c_set;
    boolean cmp_sw_trig_cmp_d_set;
    boolean cmp_sw_trig_cmp_a_clr;
    boolean cmp_sw_trig_cmp_b_clr;
    boolean cmp_sw_trig_cmp_c_clr;
    boolean cmp_sw_trig_cmp_d_clr;
} sdrv_epwm_cmp_sw_trig_t;

/**
 * @brief sdrv_epwm_cnt_ext_sw_trig.
 *
 */
typedef struct sdrv_epwm_cnt_ext_sw_trig {
    boolean cnt_ext_sw_trig_cnt_g0_set;
    boolean cnt_ext_sw_trig_cnt_g0_clr;
    boolean cnt_ext_sw_trig_cnt_g1_set;
    boolean cnt_ext_sw_trig_cnt_g1_clr;
    boolean cnt_ext_sw_trig_ext_set;
    boolean cnt_ext_sw_trig_ext_clr;
} sdrv_epwm_cnt_ext_sw_trig_t;

/**
 * @brief sdrv_epwm_sw_trig_ctrl.
 *
 */
typedef enum sdrv_epwm_sw_trig_ctrl {
    SDRV_EPWM_SW_TRIG_PULSE,
    SDRV_EPWM_SW_TRIG_TOGGLE,
    SDRV_EPWM_SW_TRIG_LOW,
    SDRV_EPWM_SW_TRIG_HIGH,
} sdrv_epwm_sw_trig_ctrl_e;

/**
 * @brief sdrv_epwm_sw_trig_pulse_width.
 *
 */
typedef struct sdrv_epwm_sw_trig_pulse_width {
    uint16 trig0_pulse_width;
    uint16 trig1_pulse_width;
    uint16 trig2_pulse_width;
    uint16 trig3_pulse_width;
} sdrv_epwm_sw_trig_pulse_width_t;

/**
 * @brief sdrv_epwm_fault_flt.
 *
 */
typedef struct sdrv_epwm_fault_flt {
    sdrv_epwm_edge_sel_e flt_edge_sel;
    uint8 pos_band_wid;
    uint8 neg_band_wid;
    uint8 smpl_intval;
} sdrv_epwm_fault_flt_t;

/**
 * @brief sdrv_epwm_sync_dis.
 *
 */
typedef struct sdrv_epwm_sync_dis {
    boolean sdrv_epwm_sync_dis_ext_set;
    boolean sdrv_epwm_sync_dis_ext_clr;
    boolean sdrv_epwm_sync_dis_fault0;
    boolean sdrv_epwm_sync_dis_fault1;
    boolean sdrv_epwm_sync_dis_fault2;
    boolean sdrv_epwm_sync_dis_fault3;
} sdrv_epwm_sync_dis_t;

/**
 * @brief sdrv_epwm_cmp_fault_event_ctrl.
 *
 */
typedef struct sdrv_epwm_cmp_fault_event_ctrl {
    boolean fault_pol;
    boolean fault_clr_mode;
} sdrv_epwm_cmp_fault_event_ctrl_t;

/**
 * @brief sdrv_epwm_cmp_prefin_pol_sta
 *
 */
typedef enum sdrv_epwm_cmp_prefin_pol_sta {
    SDRV_EPWM_POL_KEEP,
    SDRV_EPWM_POL_INVERT,
} sdrv_epwm_cmp_prefin_pol_sta_e;

/**
 * @brief sdrv_epwm_cmp_prefin_pol.
 *
 */
typedef struct sdrv_epwm_cmp_prefin_pol {
    sdrv_epwm_cmp_prefin_pol_sta_e cmp0_pol;
    sdrv_epwm_cmp_prefin_pol_sta_e cmp1_pol;
} sdrv_epwm_cmp_prefin_pol_t;

#ifdef SEMIDRIVE_E3_LITE_SERIES

/**
 * @brief sdrv_epwm_center_align_cnt_pos.
 *
 */
typedef enum sdrv_epwm_center_align_cnt_pos {
    COUNTER_OVERFLOW_AND_UNDERRUN,
    COUNTER_OVERFLOW = 0x2,
    COUNTER_UNDERRUN,
} sdrv_epwm_center_align_cnt_pos_e;

/**
 * @brief sdrv_epwm_center_align_cmp_pos.
 *
 */
typedef enum sdrv_epwm_center_align_cmp_pos {
    COUNTER_UP_AND_DOWN,
    COUNTER_UP = 0x2,
    COUNTER_DOWN,
} sdrv_epwm_center_align_cmp_pos_e;

/**
 * @brief sdrv_epwm_center_align_cmp_irq_sel_pos.
 *
 */
typedef enum sdrv_epwm_center_align_cmp_irq_sel_pos {
    COUNTER_UP_IRQ_SEL = 0x1,
    COUNTER_DOWN_IRQ_SEL,
    COUNTER_UP_AND_DOWN_IRQ_SEL,
} sdrv_epwm_center_align_cmp_irq_sel_pos_e;
#endif

static inline uint32 sdrv_epwm_lld_int_sta_get(volatile uint32 base)
{
    return readl(base + EPWM_INT_STA_OFF);
}

static inline void sdrv_epwm_lld_int_sta_clr(volatile uint32 base, uint32 val)
{
    writel(val, base + EPWM_INT_STA_OFF);
}

static inline uint32 sdrv_epwm_lld_int_sta_en(volatile uint32 base)
{
    return readl(base + EPWM_INT_STA_EN_OFF);
}

void sdrv_epwm_lld_int_enable(volatile uint32 base, uint32 val);

void sdrv_epwm_lld_int_sta_enable(volatile uint32 base, uint32 val);

void sdrv_epwm_lld_int_sta_dis(volatile uint32 base, uint32 val);

static inline uint32 sdrv_epwm_lld_int_sig_en(volatile uint32 base)
{
    return readl(base + EPWM_INT_SIG_EN_OFF);
}

void sdrv_epwm_lld_int_sig_enable(volatile uint32 base, uint32 val);

void sdrv_epwm_lld_int_sig_dis(volatile uint32 base, uint32 val);

static inline uint32 sdrv_epwm_lld_cor_err_int_sta_get(volatile uint32 base)
{
    return readl(base + EPWM_COR_ERR_INT_STA_OFF);
}

static inline void sdrv_epwm_lld_cor_err_int_sta_clr(volatile uint32 base, uint32 val)
{
    writel(val, base + EPWM_COR_ERR_INT_STA_OFF);
}

static inline uint32 sdrv_epwm_lld_cor_err_int_sta_en(volatile uint32 base)
{
    return readl(base + EPWM_COR_ERR_INT_STA_EN_OFF);
}

void sdrv_epwm_lld_cor_err_int_enable(volatile uint32 base, uint32 val);

void sdrv_epwm_lld_cor_err_int_sta_enable(volatile uint32 base, uint32 val);

void sdrv_epwm_lld_cor_err_int_sta_dis(volatile uint32 base, uint32 val);

static inline uint32 sdrv_epwm_lld_cor_err_int_sig_en(volatile uint32 base)
{
    return readl(base + EPWM_COR_ERR_INT_SIG_EN_OFF);
}

void sdrv_epwm_lld_cor_err_int_sig_enable(volatile uint32 base, uint32 val);

void sdrv_epwm_lld_cor_err_int_sig_dis(volatile uint32 base, uint32 val);

static inline uint32 sdrv_epwm_lld_unc_err_int_sta_get(volatile uint32 base)
{
    return readl(base + EPWM_UNC_ERR_INT_STA_OFF);
}

static inline void sdrv_epwm_lld_unc_err_int_sta_clr(volatile uint32 base, uint32 val)
{
    writel(val, base + EPWM_UNC_ERR_INT_STA_OFF);
}

static inline uint32 sdrv_epwm_lld_unc_err_int_sta_en(volatile uint32 base)
{
    return readl(base + EPWM_UNC_ERR_INT_STA_EN_OFF);
}

void sdrv_epwm_lld_unc_err_int_enable(volatile uint32 base, uint32 val);

void sdrv_epwm_lld_unc_err_int_sta_enable(volatile uint32 base, uint32 val);

void sdrv_epwm_lld_unc_err_int_sta_dis(volatile uint32 base, uint32 val);

static inline uint32 sdrv_epwm_lld_unc_err_int_sig_en(volatile uint32 base)
{
    return readl(base + EPWM_UNC_ERR_INT_SIG_EN_OFF);
}

void sdrv_epwm_lld_unc_err_int_sig_enable(volatile uint32 base, uint32 val);

void sdrv_epwm_lld_unc_err_int_sig_dis(volatile uint32 base, uint32 val);

void sdrv_epwm_lld_unc_int_en(volatile uint32 base, uint32 int_id);

static inline uint32 sdrv_epwm_lld_fusa_cor_err_int_sta_get(volatile uint32 base)
{
    return readl(base + EPWM_FUSA_COR_ERR_INT_STA_OFF);
}

static inline void sdrv_epwm_lld_fusa_cor_err_int_sta_clr(volatile uint32 base,
        uint32 val)
{
    writel(val, base + EPWM_FUSA_COR_ERR_INT_STA_OFF);
}

static inline uint32 sdrv_epwm_lld_fusa_cor_err_int_sta_en(volatile uint32 base)
{
    return readl(base + EPWM_FUSA_COR_ERR_INT_STA_EN_OFF);
}

void sdrv_epwm_lld_fusa_cor_err_int_sta_enable(volatile uint32 base, uint32 val);

void sdrv_epwm_lld_fusa_cor_err_int_sta_dis(volatile uint32 base, uint32 val);

static inline uint32 sdrv_epwm_lld_fusa_cor_err_int_sig_en(volatile uint32 base)
{
    return readl(base + EPWM_FUSA_COR_ERR_INT_SIG_EN_OFF);
}

void sdrv_epwm_lld_fusa_cor_err_int_sig_enable(volatile uint32 base, uint32 val);

void sdrv_epwm_lld_fusa_cor_err_int_sig_dis(volatile uint32 base, uint32 val);

void sdrv_epwm_lld_fusa_cor_err_int_enable(volatile uint32 base, uint32 val);

static inline uint32 sdrv_epwm_lld_fusa_unc_err_int_sta_get(volatile uint32 base)
{
    return readl(base + EPWM_FUSA_UNC_ERR_INT_STA_OFF);
}

static inline void sdrv_epwm_lld_fusa_unc_err_int_sta_clr(volatile uint32 base,
        uint32 val)
{
    writel(val, base + EPWM_FUSA_UNC_ERR_INT_STA_OFF);
}

static inline uint32 sdrv_epwm_lld_fusa_unc_err_int_sta_en(volatile uint32 base)
{
    return readl(base + EPWM_FUSA_UNC_ERR_INT_STA_EN_OFF);
}

void sdrv_epwm_lld_fusa_unc_err_int_sta_enable(volatile uint32 base, uint32 val);

void sdrv_epwm_lld_fusa_unc_err_int_sta_dis(volatile uint32 base, uint32 val);

static inline uint32 sdrv_epwm_lld_fusa_unc_err_int_sig_en(volatile uint32 base)
{
    return readl(base + EPWM_FUSA_UNC_ERR_INT_SIG_EN_OFF);
}

void sdrv_epwm_lld_fusa_unc_err_int_sig_enable(volatile uint32 base, uint32 val);

void sdrv_epwm_lld_fusa_unc_err_int_sig_dis(volatile uint32 base, uint32 val);

void sdrv_epwm_lld_fusa_unc_err_int_enable(volatile uint32 base, uint32 val);

static inline uint32 sdrv_epwm_lld_fusa_unc_err_int_sta_1_get(volatile uint32 base)
{
    return readl(base + EPWM_FUSA_UNC_ERR_INT_STA_1_OFF);
}

static inline void sdrv_epwm_lld_fusa_unc_err_int_sta_1_clr(volatile uint32 base,
        uint32 val)
{
    writel(val, base + EPWM_FUSA_UNC_ERR_INT_STA_1_OFF);
}

static inline uint32 sdrv_epwm_lld_fusa_unc_err_int_sta_1_en(volatile uint32 base)
{
    return readl(base + EPWM_FUSA_UNC_ERR_INT_STA_EN_1_OFF);
}

void sdrv_epwm_lld_fusa_unc_err_int_sta_1_enable(volatile uint32 base, uint32 val);

void sdrv_epwm_lld_fusa_unc_err_int_sta_1_dis(volatile uint32 base, uint32 val);

static inline uint32 sdrv_epwm_lld_fusa_unc_err_int_sig_1_en(volatile uint32 base)
{
    return readl(base + EPWM_FUSA_UNC_ERR_INT_SIG_EN_1_OFF);
}

void sdrv_epwm_lld_fusa_unc_err_int_sig_1_enable(volatile uint32 base, uint32 val);

void sdrv_epwm_lld_fusa_unc_err_int_sig_1_dis(volatile uint32 base, uint32 val);

void sdrv_epwm_lld_fusa_unc_err_int_1_enable(volatile uint32 base, uint32 val);

static inline uint32 sdrv_epwm_lld_reg_parity_err_int_sta_get(volatile uint32 base)
{
    return readl(base + EPWM_REG_PARITY_ERR_INT_STAT_OFF);
}

static inline void sdrv_epwm_lld_reg_parity_err_int_sta_clr(volatile uint32 base,
        uint32 val)
{
    writel(val, base + EPWM_REG_PARITY_ERR_INT_STAT_OFF);
}

static inline uint32 sdrv_epwm_lld_reg_parity_err_int_sta_en(volatile uint32 base)
{
    return readl(base + EPWM_REG_PARITY_ERR_INT_STAT_EN_OFF);
}

void sdrv_epwm_lld_reg_parity_err_int_sta_enable(volatile uint32 base, uint32 val);

void sdrv_epwm_lld_reg_parity_err_int_sta_dis(volatile uint32 base, uint32 val);

static inline uint32 sdrv_epwm_lld_reg_parity_err_int_sig_en(volatile uint32 base)
{
    return readl(base + EPWM_REG_PARITY_ERR_INT_SIG_EN_OFF);
}

void sdrv_epwm_lld_reg_parity_err_int_sig_enable(volatile uint32 base, uint32 val);

void sdrv_epwm_lld_reg_parity_err_int_sig_dis(volatile uint32 base, uint32 val);

void sdrv_epwm_lld_reg_parity_err_int_enable(volatile uint32 base, uint32 val);

static inline boolean sdrv_epwm_lld_clk_config_div_num_upd_sta(volatile uint32 base)
{
    return !!(readl(base + EPWM_CLK_CONFIG_OFF) & BM_CLK_CONFIG_CLK_CHANGE_UPD);
}

static inline uint16 sdrv_epwm_lld_clk_config_get_div_num(volatile uint32 base)
{
    return readl(base + EPWM_CLK_CONFIG_OFF) & FM_CLK_CONFIG_DIV_NUM;
}

void sdrv_epwm_lld_clk_config_div_num(volatile uint32 base, uint16 div_num);

void sdrv_epwm_lld_clk_config(volatile uint32 base,
                              sdrv_epwm_clk_config_src_clk_sel_e src_clk_sel,
                              uint16 div_num);

void sdrv_epwm_lld_clk_mon_en(volatile uint32 base, boolean en_p, boolean en_n);

static inline void sdrv_epem_lld_sw_rst(volatile uint32 base, uint32 val)
{
    writel(val, base + EPWM_SW_RST_OFF);
}

static inline void sdrv_epwm_lld_chn_dma_ctrl_chn_en(volatile uint32 base,
        sdrv_epwm_channel_e chnl,
        boolean en)
{
    REG_RMW32(base + EPWM_CHN_DMA_CTRL_OFF, chnl, 1, en);
}

static inline void
sdrv_epwm_lld_chn_dma_ctrl_chn_sig_mask(volatile uint32 base, sdrv_epwm_channel_e chnl,
                                        boolean en)
{
    REG_RMW32(base + EPWM_CHN_DMA_CTRL_OFF, 4 + chnl, 1, en);
}

static inline void sdrv_epwm_lld_chn_dma_ctrl_cmp_dat_format(
    volatile uint32 base, sdrv_epwm_channel_e chnl,
    sdrv_epwm_chn_dma_ctrl_cmp_x_dat_format_e cmp_x_dat_format)
{

    REG_RMW32(base + EPWM_CHN_DMA_CTRL_OFF, 8 + chnl * 2, 2, cmp_x_dat_format);
}

void sdrv_epwm_lld_chn_dma_ctrl_cmp(volatile uint32 base, sdrv_epwm_channel_e chnl,
                                    boolean cmp_x_out_mode,
                                    sdrv_epwm_cmp_mode_e cmp_x_mode);

static inline void sdrv_epwm_lld_chn_dma_ctrl_four_chan_mode(volatile uint32 base,
        boolean en)
{
    REG_RMW32(base + EPWM_CHN_DMA_CTRL_OFF, 28, 1, en);
}

void sdrv_epwm_lld_chn_dma_ctrl_two_chn_xx_mode(volatile uint32 base,
        sdrv_epwm_channel_e chnl,
        boolean en);

void sdrv_epwm_lld_dma_wml(volatile uint32 base, sdrv_epwm_channel_e chnl, uint8 val);

void sdrv_epwm_lld_config_dma_ctl_cfg(volatile uint32 base, boolean sig_mask, uint8 val);

static inline void sdrv_epwm_lld_config_dma_ctl_en(volatile uint32 base, boolean en)
{
    REG_RMW32(base + EPWM_CONFIG_DMA_CTL_OFF, 0, 1, en);
}

static inline uint8 sdrv_epwm_lld_fifo_req_status(volatile uint32 base)
{
    return readl(base + EPWM_FIFO_REQ_STATUS_OFF) & 0xf;
}

static inline void
sdrv_epwm_lld_fifo_write(volatile uint32 base, sdrv_epwm_channel_e chnl, uint32 val)
{
    writel(val, base + FIFO(chnl));
}

static inline uint32 sdrv_epwm_lld_fifo_read(volatile uint32 base,
        sdrv_epwm_channel_e chnl)
{
    return readl(base + FIFO(chnl));
}

uint32 sdrv_epwm_lld_fifo_sta_fifo(volatile uint32 base, sdrv_epwm_channel_e chnl);

static inline void sdrv_epwm_lld_cnt_init_val(volatile uint32 base,
        sdrv_epwm_cnt_gx_e cnt_gx,
        uint32 val)
{
    writel(val, base + CNT_INIT_VAL(cnt_gx));
}

static inline void
sdrv_epwm_lld_cnt_ovf_val(volatile uint32 base, sdrv_epwm_cnt_gx_e cnt_gx, uint32 val)
{
    writel(val, base + CNT_OVF_VAL(cnt_gx));
}

static inline uint32 sdrv_epwm_lld_cnt_ovf_val_rd(volatile uint32 base,
        sdrv_epwm_cnt_gx_e cnt_gx)
{
    return readl(base + CNT_OVF_VAL(cnt_gx));
}

static inline void sdrv_epwm_lld_cnt_cfg_init_upd(volatile uint32 base,
        sdrv_epwm_cnt_gx_e cnt_gx)
{
    REG_RMW32(base + CNT_CFG(cnt_gx), 16, 1, TRUE);
}

static inline void sdrv_epwm_lld_cnt_cfg_ovf_upd(volatile uint32 base,
        sdrv_epwm_cnt_gx_e cnt_gx)
{
    REG_RMW32(base + CNT_CFG(cnt_gx), 17, 1, TRUE);
}

static inline void sdrv_epwm_lld_cnt_cfg_frc_rld(volatile uint32 base,
        sdrv_epwm_cnt_gx_e cnt_gx)
{
    REG_RMW32(base + CNT_CFG(cnt_gx), 0, 1, 1);
}

static inline void
sdrv_epwm_lld_cnt_cfg_clr_trig_sel(volatile uint32 base, sdrv_epwm_cnt_gx_e cnt_gx,
                                   sdrv_epwm_event_trigger_mode_e clr_trig_sel)
{

    REG_RMW32(base + CNT_CFG(cnt_gx), 5, 2, clr_trig_sel);
}

void sdrv_epwm_lld_cnt_cfg_set_trig_sel(
    volatile uint32 base, sdrv_epwm_cnt_gx_e cnt_gx,
    sdrv_epwm_cnt_cfg_set_upd_sel_e set_mode_sel,
    sdrv_epwm_event_trigger_mode_e set_trig_sel);

static inline void sdrv_epwm_lld_cnt_cfg_interval(volatile uint32 base,
        sdrv_epwm_cnt_gx_e cnt_gx,
        uint8 interval_num)
{
    REG_RMW32(base + CNT_CFG(cnt_gx), 8, 8, interval_num);
}

static inline void sdrv_epwm_lld_cnt_cfg_con_dis(volatile uint32 base,
        sdrv_epwm_cnt_gx_e cnt_gx,
        boolean disble)
{
    REG_RMW32(base + CNT_CFG(cnt_gx), 18, 1, disble);
}

static inline void
sdrv_epwm_lld_cnt_cfg_ce_en(volatile uint32 base, sdrv_epwm_cnt_gx_e cnt_gx, boolean en)
{
    REG_RMW32(base + CNT_CFG(cnt_gx), 7, 1, en);
}

static inline void sdrv_epwm_lld_cnt_cfg_ovf_rst_dis(volatile uint32 base,
        sdrv_epwm_cnt_gx_e cnt_gx,
        boolean dis)
{
    REG_RMW32(base + CNT_CFG(cnt_gx), 19, 1, dis);
}

static inline void sdrv_epwm_lld_cnt_en(volatile uint32 base, sdrv_epwm_cnt_gx_e cnt_gx,
                                        boolean en)
{
    REG_RMW32(base + CNT_EN(cnt_gx), 0, 1, en);
}

static inline uint32 sdrv_epwm_lld_cnt_val(volatile uint32 base,
        sdrv_epwm_cnt_gx_e cnt_gx)
{
    return readl(base + CNT(cnt_gx));
}

static inline void sdrv_epwm_lld_cnt_mfc(volatile uint32 base,
        sdrv_epwm_cnt_gx_e cnt_gx, uint8 val)
{
    REG_RMW32(base + CNT_MFC(cnt_gx), 0, 4, val & 0xf);
}

static inline void sdrv_epwm_lld_cmp_config_sw_rld_set(volatile uint32 base,
        sdrv_epwm_channel_e chnl,
        boolean en)
{
    REG_RMW32(base + CMP_CONFIG(chnl), 14, 1, en);
}

static inline void
sdrv_epwm_lld_cmp_config_ce_en(volatile uint32 base, sdrv_epwm_channel_e chnl, boolean en)
{
    REG_RMW32(base + CMP_CONFIG(chnl), 8, 1, en);
}

static inline void sdrv_epwm_lld_cmp_config_ce(volatile uint32 base,
        sdrv_epwm_channel_e chnl,
        sdrv_epwm_cmp_xx_e ce_trig_sel)
{
    REG_RMW32(base + CMP_CONFIG(chnl), 6, 2, ce_trig_sel);
}

void sdrv_epwm_lld_cmp_config_clr_set(
    volatile uint32 base, sdrv_epwm_channel_e chnl,
    sdrv_epwm_event_trigger_mode_e cmp_set_trig_sel,
    sdrv_epwm_event_trigger_mode_e cmp_clr_trig_sel);

void sdrv_epwm_lld_cmp_config(volatile uint32 base, sdrv_epwm_channel_e chnl,
                              sdrv_epwm_cmp_cfg_t *cfg);

void sdrv_epwm_lld_cmp_event_out_mode(volatile uint32 base, sdrv_epwm_channel_e chnl,
                                      sdrv_epwm_cmp_event_out_t *out_mode);

void sdrv_epwm_lld_cmp_pulse_wid0(volatile uint32 base, sdrv_epwm_channel_e chnl,
                                  sdrv_epwm_cmp_pulse_wid0_t *wid);

void sdrv_epwm_lld_cmp_pulse_wid1(volatile uint32 base, sdrv_epwm_channel_e chnl,
                                  sdrv_epwm_cmp_pulse_wid1_t *wid);

static inline void sdrv_epwm_lld_cmp_val(volatile uint32 base, sdrv_epwm_channel_e chnl,
        sdrv_epwm_cmp_xx_e cmp_xx,
        uint32 val)
{
    writel(val, base + CMP_VAL(chnl, cmp_xx));
}

static inline void
sdrv_epwm_lld_cmp_dither_en(volatile uint32 base, sdrv_epwm_channel_e chnl, boolean en)
{
    REG_RMW32(base + CMP_DITHER(chnl), 0, 1, en);
}

static inline void
sdrv_epwm_lld_cmp_dither_init_offset_en(volatile uint32 base, sdrv_epwm_channel_e chnl,
                                        boolean en)
{
    REG_RMW32(base + CMP_DITHER(chnl), 1, 1, en);
}

void sdrv_epwm_lld_cmp_dither(volatile uint32 base, sdrv_epwm_channel_e chnl,
                              uint8 clip_rslt, uint16 init_offset);

static inline void
sdrv_epwm_lld_cmp_offset(volatile uint32 base, sdrv_epwm_channel_e chnl, uint16 val)
{
    REG_RMW32(base + CMP_OFFSET(chnl), 0, 16, val);
}

static inline void
sdrv_epwm_lld_cmp_a_eid(volatile uint32 base, sdrv_epwm_cmp_xx_e cmp_xx, uint8 val)
{
    REG_RMW32(base + EPWM_CMP_A_EID_OFF, cmp_xx * 8, 8, val);
}

static inline uint8 sdrv_epwm_lld_cmp_ctrl_cmp_en_get_sta(volatile uint32 base)
{
    return readl(base + EPWM_CMP_CTRL_OFF) & 0xF;
}

static inline void
sdrv_epwm_lld_cmp_ctrl_cmp_en(volatile uint32 base, sdrv_epwm_channel_e chnl, boolean en)
{
    REG_RMW32(base + EPWM_CMP_CTRL_OFF, chnl, 1, en);
}

static inline void
sdrv_epwm_lld_cmp_ctrl_cmp_config_set(volatile uint32 base, sdrv_epwm_channel_e chnl,
                                      boolean en)
{
    REG_RMW32(base + EPWM_CMP_CTRL_OFF, chnl + 4, 1, en);
}

static inline void sdrv_epwm_lld_cmp_ctrl_cmp_val_upd(volatile uint32 base,
        sdrv_epwm_channel_e chnl)
{
    REG_RMW32(base + EPWM_CMP_CTRL_OFF, chnl + 8, 1, TRUE);
}

static inline void sdrv_epwm_lld_cmp_ctrl_cmp_eid_upd(volatile uint32 base)
{
    REG_RMW32(base + EPWM_CMP_CTRL_OFF, 28, 1, TRUE);
}

void sdrv_epwm_lld_cmp_ctrl_cmp_init_status(volatile uint32 base,
        sdrv_epwm_channel_e chnl,
        boolean cmp0_init, boolean cmp1_init);

static inline void sdrv_epwm_lld_cmp_ctrl_cmp_init_upd(volatile uint32 base,
        sdrv_epwm_channel_e chnl,
        boolean mode)
{
    REG_RMW32(base + EPWM_CMP_CTRL_OFF, chnl * 2 + mode + 20, 1, TRUE);
}

static inline void sdrv_epwm_lld_cmp_sse_ctrl_sse_en(volatile uint32 base,
        sdrv_epwm_channel_e chnl,
        boolean en)
{
    REG_RMW32(base + EPWM_SSE(chnl), 0, 1, en);
}

static inline void sdrv_epwm_lld_cmp_sse_ctrl_cfg_so_det_fault(
    volatile uint32 base, sdrv_epwm_channel_e chnl,
    sdrv_epwm_sse_so_det_fault_e sse_so_det_fault)
{
    REG_RMW32(base + EPWM_SSE(chnl), 16, 3, sse_so_det_fault);
}

void sdrv_epwm_lld_cmp_sse_ctrl_cfg(volatile uint32 base, sdrv_epwm_channel_e chnl,
                                    sdrv_epwm_cmp_sse_ctrl_t *cfg);

static inline void
sdrv_epwm_lld_cmp_sse_reg(volatile uint32 base, sdrv_epwm_channel_e chnl, uint32 val)
{
    writel(val, base + EPWM_SSE_REG(chnl));
}

void sdrv_epwm_lld_cmp_input_sel(volatile uint32 base, sdrv_epwm_channel_e chnl,
                                 sdrv_epwm_input_sel_t *cfg);

static inline void
sdrv_epwm_lld_cnt_input_sel_clr(volatile uint32 base, sdrv_epwm_cnt_gx_e cnt_gx,
                                sdrv_epwm_input_sel_trig_e clr_sel)
{
    REG_RMW32(base + CNT_INPUT_SEL(cnt_gx), 4, 4, clr_sel);
}

static inline void
sdrv_epwm_lld_cnt_input_sel_set(volatile uint32 base, sdrv_epwm_cnt_gx_e cnt_gx,
                                sdrv_epwm_input_sel_trig_e set_sel)
{
    REG_RMW32(base + CNT_INPUT_SEL(cnt_gx), 0, 3, set_sel);
}

void sdrv_epwm_lld_ext_output_sel(volatile uint32 base, sdrv_epwm_input_sel_t *cfg);

void sdrv_epwm_lld_trigc_pol_inv(volatile uint32 base, sdrv_epwm_trigc_pol_inv_t *cfg);

void sdrv_epwm_lld_cmp_sw_trig(volatile uint32 base, sdrv_epwm_cmp_sw_trig_t *cfg);

void sdrv_epwm_lld_cnt_ext_sw_trig(volatile uint32 base,
                                   sdrv_epwm_cnt_ext_sw_trig_t *cfg);

static inline void
sdrv_epwm_lld_sw_trig_ctrl(volatile uint32 base, sdrv_epwm_channel_e chnl,
                           sdrv_epwm_sw_trig_ctrl_e sw_trig_ctrl)
{
    REG_RMW32(base + EPWM_SW_TRIG_CTRL_OFF, chnl * 4 + sw_trig_ctrl, 1, TRUE);
}

static inline uint8 sdrv_epwm_lld_sw_trig_status(volatile uint32 base)
{
    return readl(base + EPWM_SW_TRIG_STATUS_OFF) & 0xf;
}

void sdrv_epwm_lld_sw_trig_pulse(volatile uint32 base, sdrv_epwm_channel_e chnl,
                                 sdrv_epwm_sw_trig_pulse_width_t *cfg);

static inline void sdrv_epwm_lld_fault_flt_en(volatile uint32 base,
        sdrv_epwm_channel_e chnl, boolean en)
{
    REG_RMW32(base + EPWM_FAULT0_FLT_OFF + chnl * 4, 0, 1, en);
}

void sdrv_epwm_lld_fault_flt(volatile uint32 base, sdrv_epwm_channel_e chnl,
                             sdrv_epwm_fault_flt_t *cfg);

void sdrv_epwm_lld_sync_dis(volatile uint32 base, sdrv_epwm_sync_dis_t *cfg);

static inline void
sdrv_epwm_lld_cmp_fault_event_ctrl_en(volatile uint32 base, sdrv_epwm_channel_e chnl,
                                      sdrv_epwm_sub_channel_e sub_chnl, boolean en)
{
    REG_RMW32(base + CMP_FAULT_EVENT_CTRL(chnl), sub_chnl * 4, 1, en);
}

static inline void
sdrv_epwm_lld_cmp_fault_event_ctrl_clr(volatile uint32 base, sdrv_epwm_channel_e chnl,
                                       sdrv_epwm_sub_channel_e sub_chnl)
{
    REG_RMW32(base + CMP_FAULT_EVENT_CTRL(chnl), 3 + sub_chnl * 4, 1, TRUE);
}

void sdrv_epwm_lld_cmp_fault_event_ctrl_config(
    volatile uint32 base, sdrv_epwm_channel_e chnl, sdrv_epwm_sub_channel_e sub_chnl,
    sdrv_epwm_cmp_fault_event_ctrl_t *cfg);

static inline void
sdrv_epwm_lld_cmp_dti_ctrl_en(volatile uint32 base, sdrv_epwm_channel_e chnl, boolean en)
{
    REG_RMW32(base + CMP_DTI_CTRL(chnl), 0, 1, en);
}

static inline void
sdrv_epwm_lld_cmp_dti_ctrl_inv(volatile uint32 base, sdrv_epwm_channel_e chnl, boolean en)
{
    REG_RMW32(base + CMP_DTI_CTRL(chnl), 6, 1, en);
}

static inline void
sdrv_epwm_lld_cmp_dti_ctrl_sam(volatile uint32 base, sdrv_epwm_channel_e chnl, boolean en)
{
    REG_RMW32(base + CMP_DTI_CTRL(chnl), 5, 1, en);
}

void sdrv_epwm_lld_cmp_prefin_pol(volatile uint32 base, sdrv_epwm_channel_e chnl,
                                  sdrv_epwm_cmp_prefin_pol_t *prefin_pol);

void sdrv_epwm_lld_cmp_fault_event_fs_sta_set(volatile uint32 base,
        sdrv_epwm_channel_e chnl,
        boolean cmp0_sta, boolean cmp1_sta);

void sdrv_epwm_lld_cmp_dti_wid(volatile uint32 base, sdrv_epwm_channel_e chnl,
                               uint16 dt0_wid, uint16 dt1_wid);

static inline uint32 sdrv_epwm_lld_signal_status(volatile uint32 base)
{
    return readl(base + EPWM_SIGNAL_STATUS_OFF) & 0xffff;
}

static inline void sdrv_epwm_lld_selftest_mode(volatile uint32 base, boolean en)
{
    REG_RMW32(base + EPWM_SELFTEST_MODE_OFF, 0, 1, en);
}

void sdrv_epwm_lld_cmp_dti_cbc(volatile uint32 base, sdrv_epwm_channel_e chnl, boolean en);

void sdrv_epwm_lld_cmp_dti_zero_vector(volatile uint32 base, sdrv_epwm_channel_e chnl,
                                       boolean en);

#ifdef SEMIDRIVE_E3_LITE_SERIES
void sdrv_epwm_lld_cmp_sw_frc_dis(volatile uint32 base, sdrv_epwm_channel_e chnl,
                                  sdrv_epwm_output_e sub_chnl, boolean en);

static inline uint32 sdrv_epwm_lld_center_align_cmp_int_sta_get(volatile uint32 base)
{
    return readl(base + EPWM_CENTER_ALIGN_CMP_INT_STA_OFF);
}

static inline void sdrv_epwm_lld_center_align_cmp_int_sta_clr(volatile uint32 base,
        uint32 val)
{
    writel(val, base + EPWM_CENTER_ALIGN_CMP_INT_STA_OFF);
}

void sdrv_epwm_lld_center_align_cmp_int_enable(volatile uint32 base, uint32 val);

static inline uint32 sdrv_epwm_lld_center_align_cmp_int_sta_en(volatile uint32 base)
{
    return readl(base + EPWM_CENTER_ALIGN_CMP_INT_STA_OFF);
}

void sdrv_epwm_lld_center_align_cmp_int_sta_enable(volatile uint32 base, uint32 val);

void sdrv_epwm_lld_center_align_cmp_int_sta_dis(volatile uint32 base, uint32 val);

static inline uint32 sdrv_epwm_lld_center_align_cmp_int_sig_en(volatile uint32 base)
{
    return readl(base + EPWM_CENTER_ALIGN_CMP_INT_SIG_EN_OFF);
}

void sdrv_epwm_lld_center_align_cmp_int_sig_enable(volatile uint32 base, uint32 val);

void sdrv_epwm_lld_center_align_cmp_int_sig_dis(volatile uint32 base, uint32 val);

static inline void
sdrv_epwm_lld_cnt_center_align_mode_en(volatile uint32 base, sdrv_epwm_cnt_gx_e cnt_gx,
                                       boolean en)
{
    REG_RMW32(base + CNT_CFG(cnt_gx), 24, 1, en);
}

static inline void
sdrv_epwm_lld_cnt_center_align_ce_sel(volatile uint32 base, sdrv_epwm_cnt_gx_e cnt_gx,
                                      sdrv_epwm_center_align_cnt_pos_e ce_sel)
{
    REG_RMW32(base + CNT_CFG(cnt_gx), 22, 2, ce_sel);
}

static inline void sdrv_epwm_lld_cnt_center_align_ovf_int_sel(
    volatile uint32 base, sdrv_epwm_cnt_gx_e cnt_gx,
    sdrv_epwm_center_align_cnt_pos_e ovf_sel_pos)
{
    REG_RMW32(base + CNT_CFG(cnt_gx), 20, 2, ovf_sel_pos);
}

static inline void
sdrv_epwm_lld_cmp_center_align_mode_en(volatile uint32 base, sdrv_epwm_channel_e chnl,
                                       boolean en)
{
    REG_RMW32(base + CMP_CONFIG1(chnl), 18, 1, en);
}

static inline void sdrv_epwm_lld_cmp_center_align_reload_sel(
    volatile uint32 base, sdrv_epwm_channel_e chnl,
    sdrv_epwm_center_align_cmp_pos_e reload_sel_pos)
{
    REG_RMW32(base + CMP_CONFIG1(chnl), 16, 2, reload_sel_pos);
}

static inline void sdrv_epwm_lld_cmp_center_align_cmp_irq_sel(
    volatile uint32 base, sdrv_epwm_channel_e chnl, sdrv_epwm_cmp_xx_e ce_trig_sel,
    sdrv_epwm_center_align_cmp_irq_sel_pos_e irq_sel_pos)
{
    REG_RMW32(base + CMP_CONFIG1(chnl), 8 + ce_trig_sel * 2, 2, irq_sel_pos);
}

static inline void
sdrv_epwm_lld_cmp_center_align_ce_sel(volatile uint32 base, sdrv_epwm_channel_e chnl,
                                      uint8 val)
{
    REG_RMW32(base + CMP_CONFIG1(chnl), 0, 8, val);
}

static inline uint8
sdrv_epwm_lld_cmp_fault_event_sta(volatile uint32 base, sdrv_epwm_channel_e chnl)
{
    return (readl(base + EPWM_CMP_FAULT_EVENT_STA_OFF) >> (4 * chnl)) & 0xf;
}

void sdrv_epwm_lld_cmp_dti_idle_sta(volatile uint32 base, sdrv_epwm_channel_e chnl,
                                    boolean cmp0_idle_status,
                                    boolean cmp1_idle_status);
static inline void
sdrv_epwm_lld_cmp_dti_idle_sw_trig_frc(volatile uint32 base, sdrv_epwm_channel_e chnl,
                                       boolean en)
{
    REG_RMW32(base + CMP_DTI_CTRL(chnl), 7, 1, en);
}

static inline boolean sdrv_epwm_lld_center_align_cnt_dir(volatile uint32 base,
        sdrv_epwm_cnt_gx_e cnt_gx)
{
    return (readl(base + EPWM_CENTER_ALIGN_CNT_DIR_OFF) >> (1 * cnt_gx)) & 0x1;
}

#endif

__END_CDECLS

#endif

#ifdef __cplusplus
}
#endif
#endif
