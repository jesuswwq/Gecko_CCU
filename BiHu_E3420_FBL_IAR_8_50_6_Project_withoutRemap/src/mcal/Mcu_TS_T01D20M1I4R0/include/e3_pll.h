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

#ifndef E3_PLL_LLD_H_
#define E3_PLL_LLD_H_

/* PLL index */
#define PLL_ID_NUM_LSB                  (0u)
#define PLL_ID_NUM_VCO                  (0u)
#define PLL_ID_NUM_LVDS_CLK_0           (1u)
#define PLL_ID_NUM_LVDS_CLK_1           (2u)
#define PLL_ID_NUM_LVDS_CLK_2           (3u)
#define PLL_ID_NUM_LVDS_CKGEN           (4u)
#define PLL_ID_NUM_MASK                 (0xFF)

/* Control register */
#define PLL_CTRL                        (0x0u)
#define PLL_CTRL_PD                     (0u)
#define PLL_CTRL_GATING_MODE            (1u)
#define PLL_CTRL_LOCK_MODE              (2u)
#define PLL_CTRL_LOCK_TIME_LSB          (3u)
#define PLL_CTRL_LOCK_TIME_MASK         (0xFu)
#define PLL_CTRL_POSTDIV                (7u)
#define PLL_CTRL_FORCE_LOCK             (8u)
#define PLL_CTRL_DSM_DISABLE            (9u)
#define PLL_CTRL_RESETN                 (10u)
#define PLL_CTRL_RESETN_SEL             (11u)
#define PLL_CTRL_ICP_LSB                (16u)
#define PLL_CTRL_ICP_MASK               (0x7u)
#define PLL_CTRL_LDO_V0P8_LSB           (19u)
#define PLL_CTRL_LDO_V0P8_MASK          (0x3u)
#define PLL_CTRL_VCO_BAND_LSB           (21u)
#define PLL_CTRL_VCO_BAND_MASK          (0x7u)
#define PLL_CTRL_RESETN_DLY_LSB         (25u)
#define PLL_CTRL_RESETN_DLY_MASK        (0xFu)
#define PLL_CTRL_FORCE_BYPASS           (29u)
#define PLL_CTRL_SEM_SWITCH_EN          (30u)
#define PLL_CTRL_SEMM_SWITCH_SRC_SEL    (31u)

/* N Number register */
#define PLL_N_NUM                       (0x4u)
#define PLL_N_NUM_VAL_LSB               (0u)
#define PLL_N_NUM_VAL_MASK              (0x7Fu)

/* M Number register */
#define PLL_M_NUM                       (0x8u)
#define PLL_M_NUM_VAL_LSB               (0u)
#define PLL_M_NUM_VAL_MASK              (0x3FFFFFFu)
#define PLL_M_NUM_SW_READY              (30u)
#define PLL_M_NUM_READY_SEL             (31u)

/* DSM register */
#define PLL_DSM                         (0xCu)
#define PLL_DSM_SSC_OFFSET_LSB          (0u)
#define PLL_DSM_SSc_OFFSET_MASK         (0x3u)
#define PLL_DSM_SSC_FREQ_LSB            (2u)
#define PLL_DSM_SSC_FREQ_MASK           (0x3u)
#define PLL_DSM_SSC_MODE_LSB            (4u)
#define PLL_DSM_SSC_MODE_MASK           (0x3u)
#define PLL_DSM_SSC_DEP_LSB             (6u)
#define PLL_DSM_SSC_DEP_MASK            (0x1Fu)

/* DTEST register */
#define PLL_DTEST                       (0x10u)
#define PLL_DTEST_EN                    (0u)
#define PLL_DTEST_SEL_LSB               (1u)
#define PLL_DTEST_SEL_MASK              (0x3u)
#define PLL_DTEST_REF_TEST_SEL          (3u)
#define PLL_DTEST_DTESTO                (31u)

/* ATEST register */
#define PLL_ATEST                       (0x14u)
#define PLL_ATEST_EN                    (0u)
#define PLL_ATEST_SEL_LSB               (1u)
#define PLL_ATEST_SEL_MASK              (0x3u)

/* STATUS register */
#define PLL_STATUS                      (0x20u)
#define PLL_STATUS_LOCK                 (0u)
#define PLL_STATUS_DUTY_DET             (1u)
#define PLL_STATUS_NO_REFCK             (2u)
#define PLL_STATUS_PLL_M_READY          (3u)
#define PLL_STATUS_LOCK_LOSS            (8u)
#define PLL_STATUS_DUTY_LOSS            (9u)
#define PLL_STATUS_REFCK_LOSS           (10u)

/* LVDS_CTL register */
#define PLL_LVDS_CTL                    (0xA0u)
#define PLL_LVDS_CTL_DIV2_GATING_EN     (0u)
#define PLL_LVDS_CTL_DIV7_GATING_EN     (1u)
#define PLL_LVDS_CTL_DIV2_NUM_LSB       (2u)
#define PLL_LVDS_CTL_DIV2_NUM_MASK      (0x1Fu)
#define PLL_LVDS_CTL_DIV7_NUM_LSB       (7u)
#define PLL_LVDS_CTL_DIV7_NUM_MASK      (0x1Fu)
#define PLL_LVDS_CTL_GATING_EN          (12u)
#define PLL_LVDS_CTL_CKGEN_GATING_EN    (16u)
#define PLL_LVDS_CTL_CKGEN_DIV_NUM_LSB  (17u)
#define PLL_LVDS_CTL_CKGEN_DIV_NUM_MASK (0xFu)
#define PLL_LVDS_CTL_CKGEN_GATING_STATUS  (25u)
#define PLL_LVDS_CTL_CKGEN_CHG_BUSY       (26u)
#define PLL_LVDS_CTL_GATING_STATUS      (27u)
#define PLL_LVDS_CTL_DIV7_GATING_STATUS (28u)
#define PLL_LVDS_CTL_DIV2_GATING_STATUS (29u)
#define PLL_LVDS_CTL_DIV7_CHG_BUSY      (30u)
#define PLL_LVDS_CTL_DIV2_CHG_BUSY      (31u)

#define PLL_LVDS_OUT_DIV_MIN            (1u)
#define PLL_LVDS_OUT_DIV_MAX            (32u)
#define PLL_LVDS_CKGEN_IN_DIV_MAX       (16u)

#define PLL_VCO_FMAX                    2400000000ul
#define PLL_VCO_FMIN                    500000000ul
#define PLL_VCO_BAND                    1000000000ul

#define PLL_WAIT_TIME                   10000u

/**
 * @brief PLL Spread amplitude.
 *
 */
typedef enum sdrv_ckgen_ssc_amplitude {
    CKGEN_SSC_0P0_PERCENT = 0,     /**< SSC_DEP 0.0% */
    CKGEN_SSC_0P1_PERCENT,         /**< SSC_DEP 0.1% */
    CKGEN_SSC_0P2_PERCENT,         /**< SSC_DEP 0.2% */
    CKGEN_SSC_0P3_PERCENT,         /**< SSC_DEP 0.3% */
    CKGEN_SSC_0P4_PERCENT,         /**< SSC_DEP 0.4% */
    CKGEN_SSC_0P5_PERCENT,         /**< SSC_DEP 0.5% */
    CKGEN_SSC_0P6_PERCENT,         /**< SSC_DEP 0.6% */
    CKGEN_SSC_0P7_PERCENT,         /**< SSC_DEP 0.7% */
    CKGEN_SSC_0P8_PERCENT,         /**< SSC_DEP 0.8% */
    CKGEN_SSC_0P9_PERCENT,         /**< SSC_DEP 0.9% */
    CKGEN_SSC_1P0_PERCENT,         /**< SSC_DEP 1.0% */
    CKGEN_SSC_1P1_PERCENT,         /**< SSC_DEP 1.1% */
    CKGEN_SSC_1P2_PERCENT,         /**< SSC_DEP 1.2% */
    CKGEN_SSC_1P3_PERCENT,         /**< SSC_DEP 1.3% */
    CKGEN_SSC_1P4_PERCENT,         /**< SSC_DEP 1.4% */
    CKGEN_SSC_1P5_PERCENT,         /**< SSC_DEP 1.5% */
    CKGEN_SSC_1P6_PERCENT,         /**< SSC_DEP 1.6% */
    CKGEN_SSC_1P7_PERCENT,         /**< SSC_DEP 1.7% */
    CKGEN_SSC_1P8_PERCENT,         /**< SSC_DEP 1.8% */
    CKGEN_SSC_1P9_PERCENT,         /**< SSC_DEP 1.9% */
    CKGEN_SSC_2P0_PERCENT,         /**< SSC_DEP 2.0% */
    CKGEN_SSC_2P1_PERCENT,         /**< SSC_DEP 2.1% */
    CKGEN_SSC_2P2_PERCENT,         /**< SSC_DEP 2.2% */
    CKGEN_SSC_2P3_PERCENT,         /**< SSC_DEP 2.3% */
    CKGEN_SSC_2P4_PERCENT,         /**< SSC_DEP 2.4% */
    CKGEN_SSC_2P5_PERCENT,         /**< SSC_DEP 2.5% */
    CKGEN_SSC_2P6_PERCENT,         /**< SSC_DEP 2.6% */
    CKGEN_SSC_2P7_PERCENT,         /**< SSC_DEP 2.7% */
    CKGEN_SSC_2P8_PERCENT,         /**< SSC_DEP 2.8% */
    CKGEN_SSC_2P9_PERCENT,         /**< SSC_DEP 2.9% */
    CKGEN_SSC_3P0_PERCENT,         /**< SSC_DEP 3.0% */
    CKGEN_SSC_3P1_PERCENT,         /**< SSC_DEP 3.1% */
} sdrv_ckgen_ssc_amplitude_e;

/**
 * @brief PLL Spread mode.
 *
 */
typedef enum sdrv_ckgen_ssc_mode {
    CKGEN_NO_SSC = 0,         /**< PLL no spread */
    CKGEN_DOWN_SPREADING,     /**< PLL down spread */
    CKGEN_CENTER_SPREADING,   /**< PLL center spread */
} sdrv_ckgen_ssc_mode_e;

/**
 * @brief PLL Spread Modulation frequency.
 *
 */
typedef enum sdrv_ckgen_ssc_freq {
    CKGEN_FREF_DIV_507 = 0,     /**< For 16MHz ref. It's 31.5KHz */
    CKGEN_FREF_DIV_761,         /**< For 24MHz ref. It's 31.5KHz */
    CKGEN_FREF_DIV_793,         /**< For 25MHz ref. It's 31.5KHz */
    CKGEN_FREF_DIV_857,         /**< For 27MHz ref. It's 31.5KHz */
} sdrv_ckgen_ssc_freq_e;

typedef uint32 pll_rate_t;

int pll_enable(paddr_t base, uint32 id);

int pll_disable(paddr_t base, uint32 id);

int pll_prepare(paddr_t base, uint32 id,
                pll_rate_t src_rate,
                pll_rate_t rate);

pll_rate_t pll_get_rate(paddr_t base, uint32 id,
                        pll_rate_t src_rate);

int pll_set_rate(paddr_t base, uint32 id,
                 pll_rate_t src_rate,
                 pll_rate_t rate);

bool pll_is_locked(paddr_t base);

void pll_set_ssc_amplitude(uint32 base, sdrv_ckgen_ssc_amplitude_e amplitude);
void pll_set_ssc_frequency(uint32 base, sdrv_ckgen_ssc_freq_e ssc_freq);
int pll_set_ssc_mode(uint32 base, sdrv_ckgen_ssc_mode_e ssc_mode);

#endif /* E3_PLL_LLD_H_ */
