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
#include "RegHelper.h"

#include "e3_pll.h"

#undef BIT
#define BIT(x, bit) ((x) & (1UL << (bit)))
#define DIV_ROUND_UP(n, d) (((n) + (d) - 1u) / (d))

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

static bool wait_for_bit_times(addr_t base, uint32 offset, uint32 val,
                               uint32 count)
{
    volatile uint32 times_out = count;

    while ((times_out != 0u) &&
           (val != ((readl(base) & ((uint32)1u << offset)) >> offset))) {
        times_out--;
    }

    return times_out > 0u ? TRUE : FALSE;
}

static uint32 pll_get_best_div(uint32 f_ref, uint32 freq)
{
    uint32 div;

    if (0u == freq) {
        return UINT32_MAX;
    }

    div = DIV_ROUND_UP(f_ref, freq);

    if (div > 1u) {
        if ((div * freq - f_ref) > (f_ref - (div - 1u) * freq)) {
            div--;
        }
    }

    /* The div greater than 1 and less than UINT32_MAX. */
    return div;
}

static void pll_vco_enable(paddr_t base)
{
    uint32 reg = base + PLL_CTRL;
    uint32 val;

    val = readl(reg);

    val |= (1u << PLL_CTRL_RESETN);
    val &= ~(1u << PLL_CTRL_PD);

    writel(val, reg);
}

static void pll_vco_disable(paddr_t base)
{
    uint32 reg = base + PLL_CTRL;
    uint32 val;

    val = readl(reg);

    val &= ~(1u << PLL_CTRL_RESETN);
    val |= (1u << PLL_CTRL_PD);

    writel(val, reg);
}

static pll_rate_t pll_get_vco_rate(paddr_t base, pll_rate_t src_rate)
{
    uint32 reg = base + PLL_CTRL;
    pll_rate_t f_vco;
    uint32 val;
    bool is_int_mode;
    uint32 post_div;
    uint32 m_val;
    uint32 n_val;
    uint32 tmp_u32;
    uint64 tmp_u64;

    val = readl(reg);

    if ((val >> PLL_CTRL_LOCK_MODE) & 0x1u) {
        is_int_mode = TRUE;
    } else {
        is_int_mode = FALSE;
    }

    post_div = ((val >> PLL_CTRL_POSTDIV) & 0x1u) ? 2 : 1;

    val = readl(base + PLL_N_NUM);
    n_val = (val >> PLL_N_NUM_VAL_LSB) & PLL_N_NUM_VAL_MASK;

    tmp_u32 = src_rate / post_div;
    f_vco = tmp_u32 * n_val;

    if (!is_int_mode) {
        val = readl(base + PLL_M_NUM);
        m_val = (val >> PLL_M_NUM_VAL_LSB) & PLL_M_NUM_VAL_MASK;
        tmp_u64 = (uint64)tmp_u32 * (uint64)m_val;
        f_vco += (tmp_u64 >> 24u);
    }

    return f_vco;
}

int pll_set_vco_rate(uint32 base, uint32 src_rate,
                     uint32 rate)
{
    uint32 ctrl_val;
    uint32 m_reg_val;
    uint32 post_div;
    uint32 m_val;
    uint32 n_val;
    uint32 frac_val;
    uint32 tmp_u32;
    uint64 tmp_u64;
    bool recfg = FALSE;
    int ret = -1;

    ctrl_val = readl(base + PLL_CTRL);

    if (!BIT(ctrl_val, PLL_CTRL_PD) && BIT(ctrl_val, PLL_CTRL_RESETN)) {
        RMWREG32(base + PLL_CTRL, PLL_CTRL_FORCE_BYPASS, 1, 1);
        recfg = TRUE;
    }

    pll_vco_disable(base);

    for (post_div = 1; post_div <= 2; post_div++) {

        tmp_u32 = src_rate / post_div;

        n_val = rate / tmp_u32;

        if (n_val > PLL_N_NUM_VAL_MASK) {
            continue;
        }

        frac_val = rate % tmp_u32;

        /* integer mode */
        if (frac_val == 0u) {
            m_val = 0;
            ret = 0;
            break;
        }

        /* fractional mode */
        tmp_u64 = (uint64)frac_val << 24u;
        tmp_u64 = tmp_u64 / (uint64)tmp_u32;
	    /*PRQA S 2992,2996 2*/
        if (tmp_u64 > PLL_M_NUM_VAL_MASK) {
            continue;
        }

        m_val = (uint32)tmp_u64;
        ret = 0;
        break;
    }

    if (ret == 0) {

        RMWREG32(base + PLL_N_NUM, PLL_N_NUM_VAL_LSB, 7u, n_val);

        m_reg_val = readl(base + PLL_M_NUM);
        m_reg_val &= ~(PLL_M_NUM_VAL_MASK + (1 << PLL_M_NUM_SW_READY));
        m_reg_val |= (m_val + (1 << PLL_M_NUM_SW_READY));
        writel(m_reg_val, base + PLL_M_NUM);

        ctrl_val = readl(base + PLL_CTRL);

        if (m_val == 0) {
            ctrl_val |= (1u << PLL_CTRL_DSM_DISABLE);
            ctrl_val |= (1u << PLL_CTRL_LOCK_MODE);
        } else {
            ctrl_val &= ~(1u << PLL_CTRL_DSM_DISABLE);
            ctrl_val &= ~(1u << PLL_CTRL_LOCK_MODE);
        }

        if (post_div == 1) {
            ctrl_val &= ~(1u << PLL_CTRL_POSTDIV);
        } else {
            ctrl_val |= (1u << PLL_CTRL_POSTDIV);
        }

        if (rate > PLL_VCO_BAND) {
            ctrl_val |= (7u << PLL_CTRL_VCO_BAND_LSB);
        } else {
            ctrl_val |= (4u << PLL_CTRL_VCO_BAND_LSB);
        }

        writel(ctrl_val, base + PLL_CTRL);

        pll_vco_enable(base);

        if (recfg) {
            RMWREG32(base + PLL_CTRL, PLL_CTRL_FORCE_BYPASS, 1, 0);
        }
    }

    return ret;
}

static int pll_vco_prepare(paddr_t base, pll_rate_t src_rate,
                           pll_rate_t rate)
{
    uint32 ctrl_val;
    uint32 m_reg_val;
    uint32 post_div;
    uint32 m_val = 0u;
    uint32 n_val;
    uint32 frac_val;
    uint64 tmp_u64;
    bool recfg = FALSE;
    int ret = -1;
    uint64 vco_out;
    uint32 p_list[3] = {2, 4, 2};

    ctrl_val = readl(base + PLL_CTRL);

    if (!BIT(ctrl_val, PLL_CTRL_PD) && BIT(ctrl_val, PLL_CTRL_RESETN)) {
        RMWREG32(base + PLL_CTRL, PLL_CTRL_FORCE_BYPASS, 1, 1);
        recfg = TRUE;
    }

    pll_vco_disable(base);

    for (uint32 i = 0; i < 3; i++) {

        post_div = p_list[i];
        vco_out = (uint64)rate * post_div;

        if (vco_out > PLL_VCO_FMAX) {
            continue;
        }

        if ((i != 2) && (vco_out < PLL_VCO_BAND)) {
            continue;
        }

        vco_out /= 2;
        n_val = vco_out / src_rate;
        frac_val = vco_out % src_rate;

        /* integer mode */
        if (frac_val == 0u) {
            m_val = 0;
            ret = 0;
            break;
        }

        /* fractional mode */
        tmp_u64 = (uint64)frac_val << 24u;
        tmp_u64 = tmp_u64 / (uint64)src_rate;

        if (tmp_u64 > PLL_M_NUM_VAL_MASK) {
            continue;
        }

        m_val = (uint32)tmp_u64;
        ret = 0;
        break;
    }

    if (ret == 0) {

        RMWREG32(base + PLL_N_NUM, PLL_N_NUM_VAL_LSB, 7u, n_val);

        m_reg_val = readl(base + PLL_M_NUM);
        m_reg_val &= ~(PLL_M_NUM_VAL_MASK + (1 << PLL_M_NUM_SW_READY));
        m_reg_val |= (m_val + (1 << PLL_M_NUM_SW_READY));
        writel(m_reg_val, base + PLL_M_NUM);

        ctrl_val = readl(base + PLL_CTRL);

        if (m_val == 0) {
            ctrl_val |= (1u << PLL_CTRL_DSM_DISABLE);
            ctrl_val |= (1u << PLL_CTRL_LOCK_MODE);
        } else {
            ctrl_val &= ~(1u << PLL_CTRL_DSM_DISABLE);
            ctrl_val &= ~(1u << PLL_CTRL_LOCK_MODE);
        }

        if (post_div == 2) {
            ctrl_val &= ~(1u << PLL_CTRL_POSTDIV);
        } else {
            ctrl_val |= (1u << PLL_CTRL_POSTDIV);
        }

        ctrl_val &= ~(7u << PLL_CTRL_VCO_BAND_LSB);

        if ((vco_out * 2) >= PLL_VCO_BAND) {
            ctrl_val |= (7u << PLL_CTRL_VCO_BAND_LSB);
        } else {
            ctrl_val |= (4u << PLL_CTRL_VCO_BAND_LSB);
        }

        writel(ctrl_val, base + PLL_CTRL);

        pll_vco_enable(base);

        if (!wait_for_bit_times(base + PLL_STATUS, PLL_STATUS_LOCK, 1u,
                                PLL_WAIT_TIME)) {
            ret = -1;
        }

        if (recfg) {
            RMWREG32(base + PLL_CTRL, PLL_CTRL_FORCE_BYPASS, 1, 0);
        }
    }

    return ret;
}

static void pll_lvds_enable(paddr_t base, uint32 id)
{
    uint32 reg;
    uint32 val;

    reg = base + PLL_LVDS_CTL;

    val = readl(reg);

    if (id == PLL_ID_NUM_LVDS_CLK_0) {
        val |= (1u << PLL_LVDS_CTL_GATING_EN);
    } else if (id == PLL_ID_NUM_LVDS_CLK_1) {
        val |= (1u << PLL_LVDS_CTL_DIV2_GATING_EN);
    } else if (id == PLL_ID_NUM_LVDS_CLK_2) {
        val |= (1u << PLL_LVDS_CTL_DIV7_GATING_EN);
    } else {
        val |= (1u << PLL_LVDS_CTL_CKGEN_GATING_EN);
    }

    writel(val, reg);
}

static void pll_lvds_disable(paddr_t base, uint32 id)
{
    uint32 reg;
    uint32 val;

    reg = base + PLL_LVDS_CTL;

    val = readl(reg);

    if (id == PLL_ID_NUM_LVDS_CLK_0) {
        val &= ~(1u << PLL_LVDS_CTL_GATING_EN);
    } else if (id == PLL_ID_NUM_LVDS_CLK_1) {
        val &= ~(1u << PLL_LVDS_CTL_DIV2_GATING_EN);
    } else if (id == PLL_ID_NUM_LVDS_CLK_2) {
        val &= ~(1u << PLL_LVDS_CTL_DIV7_GATING_EN);
    } else {
        val &= ~(1u << PLL_LVDS_CTL_CKGEN_GATING_EN);
    }

    writel(val, reg);
}

static bool pll_set_lvds_rate(addr_t base, uint32 id,
                              uint32 src_rate,
                              uint32 rate)
{
    uint32 reg;
    uint32 div;
    uint32 busy_offset;
    uint32 div_offset;
    uint32 div_max = PLL_LVDS_OUT_DIV_MAX;

    if (id == PLL_ID_NUM_LVDS_CLK_0) {
        return TRUE;
    }

    div = pll_get_best_div(src_rate, rate);

    if (div == UINT32_MAX) {
        return FALSE;
    }

    reg = base + PLL_LVDS_CTL;

    if (id == PLL_ID_NUM_LVDS_CLK_1) {
        busy_offset = PLL_LVDS_CTL_DIV2_CHG_BUSY;
        div_offset = PLL_LVDS_CTL_DIV2_NUM_LSB;
    } else if (id == PLL_ID_NUM_LVDS_CLK_2) {
        busy_offset = PLL_LVDS_CTL_DIV7_CHG_BUSY;
        div_offset = PLL_LVDS_CTL_DIV7_NUM_LSB;
    } else {
        busy_offset = PLL_LVDS_CTL_CKGEN_CHG_BUSY;
        div_offset = PLL_LVDS_CTL_CKGEN_DIV_NUM_LSB;
        div_max = PLL_LVDS_CKGEN_IN_DIV_MAX;
    }

    if (div >= PLL_LVDS_OUT_DIV_MIN && div <= div_max) {
        RMWREG32(reg, div_offset, 5u, div - 1);
        return wait_for_bit_times(reg, busy_offset, 0u, PLL_WAIT_TIME);
    }

    return FALSE;
}

static pll_rate_t pll_get_lvds_rate(paddr_t base, uint32 id, pll_rate_t src_rate)
{
    uint32 reg;
    uint32 val;
    uint32 div;

    if (id == PLL_ID_NUM_LVDS_CLK_0) {
        return src_rate;
    }

    reg = base + PLL_LVDS_CTL;
    val = readl(reg);

    if (id == PLL_ID_NUM_LVDS_CLK_1) {
        div = (val >> PLL_LVDS_CTL_DIV2_NUM_LSB) & PLL_LVDS_CTL_DIV2_NUM_MASK;
    } else if (id == PLL_ID_NUM_LVDS_CLK_2) {
        div = (val >> PLL_LVDS_CTL_DIV7_NUM_LSB) & PLL_LVDS_CTL_DIV7_NUM_MASK;
    } else {
        div = (val >> PLL_LVDS_CTL_CKGEN_DIV_NUM_LSB) & PLL_LVDS_CTL_CKGEN_DIV_NUM_MASK;
    }

    return (pll_rate_t)(src_rate / (div + 1));
}

static int pll_lvds_prepare(paddr_t base, uint32 id,
                            pll_rate_t src_rate,
                            pll_rate_t rate)
{
    if (pll_set_lvds_rate(base, id, src_rate, rate)) {
        pll_lvds_enable(base, id);
        return 0;
    }

    return -1;
}

int pll_enable(paddr_t base, uint32 id)
{
    if (id == PLL_ID_NUM_VCO) {
        pll_vco_enable(base);
    } else {
        pll_lvds_enable(base, id);
    }

    return 0;
}

int pll_disable(paddr_t base, uint32 id)
{
    if (id == PLL_ID_NUM_VCO) {
        pll_vco_disable(base);
    } else {
        pll_lvds_disable(base, id);
    }

    return 0;
}

int pll_prepare(paddr_t base, uint32 id,
                pll_rate_t src_rate,
                pll_rate_t rate)
{
    if (id == PLL_ID_NUM_VCO) {
        return pll_vco_prepare(base, src_rate, rate);
    } else {
        return pll_lvds_prepare(base, id, src_rate, rate);
    }
}

pll_rate_t pll_get_rate(paddr_t base, uint32 id,
                        pll_rate_t src_rate)
{
    if (id == PLL_ID_NUM_VCO) {
        return pll_get_vco_rate(base, src_rate);
    } else {
        return pll_get_lvds_rate(base, id, src_rate);
    }
}

int pll_set_rate(paddr_t base, uint32 id,
                 pll_rate_t src_rate,
                 pll_rate_t rate)
{
    int ret = -1;

    if (id == PLL_ID_NUM_VCO) {
        /* Not support set the VCO rate. */
        return ret;
    }

    if (pll_set_lvds_rate(base, id, src_rate, rate)) {
        ret = 0;
    }

    return ret;
}

bool pll_is_locked(paddr_t base)
{
    return BIT(readl(base + PLL_STATUS), PLL_STATUS_LOCK);
}

/**
 * @brief Set PLL spread amplitude.
 *
 * This function set SSC amplitude for specific pll.
 *
 * @param [in] base PLL base.
 * @param [in] amplitude SSC amplitude 0-31 represents 0.1% - 3.2%.
 */
void pll_set_ssc_amplitude(uint32 base, sdrv_ckgen_ssc_amplitude_e amplitude)
{
    uint32 reg;

    reg = base + PLL_DSM;

    RMWREG32(reg, PLL_DSM_SSC_DEP_LSB, 5u, amplitude & PLL_DSM_SSC_DEP_MASK);

    return;
}

/**
 * @brief Set PLL spread frequency.
 *
 * This function set SSC frequency for specific pll.
 *
 * @param [in] base PLL base.
 * @param [in] ssc_freq SSC modulation frequency.
 */
void pll_set_ssc_frequency(uint32 base, sdrv_ckgen_ssc_freq_e ssc_freq)
{
    uint32 reg;

    reg = base + PLL_DSM;

    RMWREG32(reg, PLL_DSM_SSC_FREQ_LSB, 2u, ssc_freq & PLL_DSM_SSC_FREQ_MASK);
}

/**
 * @brief Set PLL spread mode.
 *
 * This function set SSC mode for specific pll. This function will check PLL work mode first,
 * if pll config DSM_DISABLE, set spread mode will failed.
 *
 * @param [in] base PLL base.
 * @param [in] ssc_mode SSC mode.
 * @return 0 represents success, otherwise failed.
 */
int pll_set_ssc_mode(uint32 base, sdrv_ckgen_ssc_mode_e ssc_mode)
{
    if ((BIT(readl(base + PLL_CTRL), PLL_CTRL_DSM_DISABLE)) && ssc_mode) {
        return -1;
    }

    RMWREG32(base + PLL_DSM, PLL_DSM_SSC_MODE_LSB, 2u, ssc_mode & PLL_DSM_SSC_MODE_MASK);

    return 0;
}



#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
