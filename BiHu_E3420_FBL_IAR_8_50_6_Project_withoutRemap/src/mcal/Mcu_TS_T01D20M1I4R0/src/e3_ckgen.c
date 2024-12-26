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

#include <bits.h>
#include "RegHelper.h"
#include "Compiler.h"

#include "e3_ckgen.h"

#undef BIT
#define BIT(x, bit) ((x) & (1UL << (bit)))

#define DIV_ROUND_UP(n, d)          (((n) + (d) - 1u) / (d))
#define DIV_ROUND_CLOSEST(n, d)     (((n) + (d)/2)/(d))

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

uint32 ckgen_get_best_div(uint32 f_ref, uint32 freq)
{
    uint32 clk_div;

    if (0u == freq) {
        return UINT32_MAX;
    }

    clk_div = DIV_ROUND_CLOSEST(f_ref, freq);

    /* The clk_div greater than 1 and less than UINT32_MAX. */
    return clk_div;
}

static int ckgen_bus_root_set_rate(addr_t base, uint32 id, uint8 mux,
                                   ckgen_rate_t src_rate, ckgen_rate_t rate)
{
    uint32 ctrl_reg = CKGEN_BUS_CTL_BASE(base, id);

    /* Make sure CG is enabled. */
    if (mux == 1) {
        RMWREG32(ctrl_reg, CKGEN_BUS_CTL_MAIN_EN, 1u, 1u);

        if (!wait_for_bit_times(ctrl_reg, CKGEN_BUS_CTL_MAIN_EN_STATUS,
                                1u, CKGEN_WAIT_TIME)) {
            return -1;
        }
    }

    RMWREG32(ctrl_reg, CKGEN_BUS_CTL_SRC_SEL_CKOUT, 1u, mux);

    if (!wait_for_bit_times(ctrl_reg, CKGEN_BUS_CTL_POST_MUX_D0_ACTIVE,
                            !mux, CKGEN_WAIT_TIME)) {
        return -1;
    }

    return 0;
}

static int ckgen_bus_div_root_set_rate(addr_t base, uint32 id, uint8 mux,
                                       ckgen_rate_t src_rate, ckgen_rate_t rate)
{
    uint32 ctrl_reg = CKGEN_BUS_CTL_BASE(base, id);
    uint32 sync_ctrl_reg = CKGEN_BUS_SYNC_CTL_BASE(base, id);
    uint32 ctrl_val;
    uint32 div, old_div;
    uint32 src_sel;
    uint8 old_mux;

    if (mux > 4) {
        return -1;
    }

    div = ckgen_get_best_div(src_rate, rate);

    if (div == UINT32_MAX || (div - 1u) > CKGEN_BUS_CTL_DIV_NUM_MASK) {
        return -1;
    }

    ctrl_val = readl(ctrl_reg);

    old_div = (ctrl_val >> CKGEN_BUS_CTL_DIV_NUM_LSB) & CKGEN_BUS_CTL_DIV_NUM_MASK;

    /* when new div greater than old, set div before change mux */
    if ((div - 1) >= old_div) {
        RMWREG32(ctrl_reg, CKGEN_BUS_CTL_DIV_NUM_LSB, 5u, div - 1u);

        if (!wait_for_bit_times(ctrl_reg, CKGEN_BUS_CTL_DIV_CHG_BUSY,
                                0u, CKGEN_WAIT_TIME)) {
            return -1;
        }
    }

    src_sel = (readl(ctrl_reg) >> CKGEN_BUS_CTL_SRC_SEL_LSB) & CKGEN_BUS_CTL_SRC_SEL_MASK;

    /* sel ck_in4 */
    if (src_sel & (1u << 2u)) {
        old_mux = 4;
    }
    /* sel ck_in0 ~ ck_in3 */
    else {
        old_mux = src_sel & 0x3;
    }

    /*if mux == oldmux, no need to reconfig*/
    if (mux == old_mux) {

        if ((mux == 4) && BIT(ctrl_val, CKGEN_BUS_CTL_MAIN_EN_STATUS)
            && !BIT(ctrl_val, CKGEN_BUS_CTL_PRE_MUX_D0_ACTIVE)) {

            RMWREG32(ctrl_reg, CKGEN_BUS_CTL_PRE_EN, 1u, 0u);

            if (wait_for_bit_times(ctrl_reg, CKGEN_BUS_CTL_PRE_EN_STATUS,
                                   0u, CKGEN_WAIT_TIME)) {
                return 0;
            } else {
                return -1;
            }
        } else if ((mux < 4) && BIT(ctrl_val, CKGEN_BUS_CTL_PRE_EN_STATUS)
                   && BIT(ctrl_val, CKGEN_BUS_CTL_PRE_MUX_D0_ACTIVE)) {

            RMWREG32(ctrl_reg, CKGEN_BUS_CTL_SRC_SEL_CKOUT, 1u, 0u);

            if (!wait_for_bit_times(ctrl_reg, CKGEN_BUS_CTL_POST_MUX_D0_ACTIVE,
                                    1u, CKGEN_WAIT_TIME)) {
                return -1;
            }

            RMWREG32(ctrl_reg, CKGEN_BUS_CTL_MAIN_EN, 1u, 0u);

            if (wait_for_bit_times(ctrl_reg, CKGEN_BUS_CTL_MAIN_EN_STATUS,
                                   0u, CKGEN_WAIT_TIME)) {
                return 0;
            } else {
                return -1;
            }
        }
    }

    /* sel ck_in4 first */
    if (BIT(ctrl_val, CKGEN_BUS_CTL_PRE_MUX_D0_ACTIVE)) {
        /*set m/n/p first when sel ck_in4*/
        RMWREG32(sync_ctrl_reg, CKGEN_BUS_SYNC_CTL_DIV_M_LSB, 4u, 0u);

        if (!wait_for_bit_times(sync_ctrl_reg, CKGEN_BUS_SYNC_CTL_DIV_CHG_BUSY_LSB,
                                0u, CKGEN_WAIT_TIME)) {
            return -1;
        }

        RMWREG32(sync_ctrl_reg, CKGEN_BUS_SYNC_CTL_DIV_P_LSB, 4u, 3u);

        if (!wait_for_bit_times(sync_ctrl_reg, (CKGEN_BUS_SYNC_CTL_DIV_CHG_BUSY_P_LSB),
                                0u, CKGEN_WAIT_TIME)) {
            return -1;
        }

        RMWREG32(sync_ctrl_reg, CKGEN_BUS_SYNC_CTL_DIV_N_LSB, 4u, 1u);

        if (!wait_for_bit_times(sync_ctrl_reg, CKGEN_BUS_SYNC_CTL_DIV_CHG_BUSY_N_LSB,
                                0u, CKGEN_WAIT_TIME)) {
            return -1;
        }

        /* Make sure CG is enabled. */
        RMWREG32(ctrl_reg, CKGEN_BUS_CTL_MAIN_EN, 1u, 1u);

        if (!wait_for_bit_times(ctrl_reg, CKGEN_BUS_CTL_MAIN_EN_STATUS,
                                1u, CKGEN_WAIT_TIME)) {
            return -1;
        }

        /* set clk_src_sel[2] to 1’b1. */
        RMWREG32(ctrl_reg, CKGEN_BUS_CTL_SRC_SEL_CKIN4, 1u, 1u);

        if (!wait_for_bit_times(ctrl_reg, CKGEN_BUS_CTL_PRE_MUX_D0_ACTIVE,
                                0u, CKGEN_WAIT_TIME)) {
            return -1;
        }

        RMWREG32(ctrl_reg, CKGEN_BUS_CTL_PRE_EN, 1u, 0u);

        if (!wait_for_bit_times(ctrl_reg, CKGEN_BUS_CTL_PRE_EN_STATUS,
                                0u, CKGEN_WAIT_TIME)) {
            return -1;
        }
    }

    /* sel ck_in0 to ck_in3 */
    if (mux < 4) {
        /* set clk_src_sel[1:0] to select the clock.*/
        RMWREG32(ctrl_reg, CKGEN_BUS_CTL_SRC_SEL_LSB, 2u, mux);

        /*set reg_pre_en to 1’b1, wait pre_en_ack to 1’b1.*/
        RMWREG32(ctrl_reg, CKGEN_BUS_CTL_PRE_EN, 1u, 1u);

        if (!wait_for_bit_times(ctrl_reg, CKGEN_BUS_CTL_PRE_EN_STATUS,
                                1u, CKGEN_WAIT_TIME)) {
            return -1;
        }

        /* set clk_src_sel[2] to 1’b0. */
        RMWREG32(ctrl_reg, CKGEN_BUS_CTL_SRC_SEL_CKIN4, 1u, 0u);

        RMWREG32(ctrl_reg, CKGEN_BUS_CTL_MAIN_EN, 1u, 0u);

        if (!wait_for_bit_times(ctrl_reg, CKGEN_BUS_CTL_MAIN_EN_STATUS,
                                0u, CKGEN_WAIT_TIME)) {
            return -1;
        }

        if (!wait_for_bit_times(ctrl_reg, CKGEN_BUS_CTL_PRE_MUX_D0_ACTIVE,
                                1u, CKGEN_WAIT_TIME)) {
            return -1;
        }
    }

    /* when new div less than old, set div after change mux */
    if ((div - 1) < old_div) {
        RMWREG32(ctrl_reg, CKGEN_BUS_CTL_DIV_NUM_LSB, 5u, div - 1u);

        if (!wait_for_bit_times(ctrl_reg, CKGEN_BUS_CTL_DIV_CHG_BUSY,
                                0u, CKGEN_WAIT_TIME)) {
            return -1;
        }
    }

    return 0;
}

static int ckgen_bus_div_mnpq_set_rate(addr_t base, uint32 id,
                                       ckgen_rate_t src_rate,
                                       ckgen_rate_t rate)
{
    uint32 sync_ctrl_reg = CKGEN_BUS_SYNC_CTL_BASE(base, id);
    uint32 type = CKGEN_BUS_ID_TYPE(id);
    uint32 div;
    uint32 div_offset;
    uint32 div_busy_offset;

    div = ckgen_get_best_div(src_rate, rate);

    if (div == UINT32_MAX || (div - 1u) > CKGEN_BUS_SYNC_CTL_DIV_MASK) {
        return -1;
    }

    div_offset = (type - CKGEN_BUS_ID_TYPE_DIV_M) * 4u;
    div_offset += CKGEN_BUS_SYNC_CTL_DIV_M_LSB;
    div_busy_offset = (type - CKGEN_BUS_ID_TYPE_DIV_M);
    div_busy_offset += CKGEN_BUS_SYNC_CTL_DIV_CHG_BUSY_LSB;

    RMWREG32(sync_ctrl_reg, div_offset, 4u, div - 1u);

    if (!wait_for_bit_times(sync_ctrl_reg, div_busy_offset,
                            0u, CKGEN_WAIT_TIME)) {
        return -1;
    }

    return 0;
}
#ifdef MCU_CKGEN_RESERVED_FUNCs
static int ckgen_sf_bus_set_div_rate(addr_t base, uint32 id, uint32 ratio)
{
    uint32 sync_ctrl_reg = CKGEN_BUS_SYNC_CTL_BASE(base, id);

    if (ratio == 1) {
        RMWREG32(sync_ctrl_reg, CKGEN_BUS_SYNC_CTL_DIV_M_LSB, 4u, 1u);
    } else {
        RMWREG32(sync_ctrl_reg, CKGEN_BUS_SYNC_CTL_DIV_M_LSB, 4u, 0u);
    }

    if (!wait_for_bit_times(sync_ctrl_reg,
                            CKGEN_BUS_SYNC_CTL_DIV_CHG_BUSY_LSB,
                            0u, CKGEN_WAIT_TIME)) {
        return -1;
    }

    RMWREG32(base + CKGEN_RES, CKGEN_RES_RS_SF_RATIO_SEL, 1u, ratio);
    return 0;
}

static int ckgen_sp_bus_set_div_rate(addr_t base, uint32 id, uint32 ratio)
{
    uint32 sync_ctrl_reg = CKGEN_BUS_SYNC_CTL_BASE(base, id);

    if (ratio == 1) {
        RMWREG32(sync_ctrl_reg, CKGEN_BUS_SYNC_CTL_DIV_M_LSB, 4u, 1u);
    } else {
        RMWREG32(sync_ctrl_reg, CKGEN_BUS_SYNC_CTL_DIV_M_LSB, 4u, 0u);
    }

    if (!wait_for_bit_times(sync_ctrl_reg,
                            CKGEN_BUS_SYNC_CTL_DIV_CHG_BUSY_LSB,
                            0u, CKGEN_WAIT_TIME)) {
        return -1;
    }

    RMWREG32(base + CKGEN_RES, CKGEN_RES_RS_SP_RATIO_SEL, 1u, ratio);
    return 0;
}
#endif
static ckgen_rate_t ckgen_bus_div_root_get_rate(addr_t base, uint32 id,
        ckgen_rate_t src_rate)
{
    uint32 ctrl_reg = CKGEN_BUS_CTL_BASE(base, id);
    uint32 ctrl_val;
    uint32 src_sel;
    uint32 pre_div;

    ctrl_val = readl(ctrl_reg);
    src_sel = (ctrl_val >> CKGEN_BUS_CTL_SRC_SEL_LSB) & CKGEN_BUS_CTL_SRC_SEL_MASK;

    /* sel ck_in4 */
    if (src_sel & (1u << 2u)) {
        return src_rate;
    }
    /* sel ck_in0 ~ ck_in3 */
    else {
        pre_div = (ctrl_val >> CKGEN_BUS_CTL_DIV_NUM_LSB) & CKGEN_BUS_CTL_DIV_NUM_MASK;
        return (ckgen_rate_t)src_rate / (ckgen_rate_t)(pre_div + 1u);
    }
}

static ckgen_rate_t ckgen_bus_div_mnpq_get_rate(addr_t base, uint32 id,
        ckgen_rate_t src_rate)
{
    uint32 sync_ctrl = CKGEN_BUS_SYNC_CTL_BASE(base, id);
    uint32 type = CKGEN_BUS_ID_TYPE(id);
    uint32 val;
    uint32 div;
    uint32 div_offset;

    val = readl(sync_ctrl);

    div_offset = (type - CKGEN_BUS_ID_TYPE_DIV_M) * 4u;
    div_offset += CKGEN_BUS_SYNC_CTL_DIV_M_LSB;

    div = (val >> div_offset) & CKGEN_BUS_SYNC_CTL_DIV_MASK;

    return (ckgen_rate_t)src_rate / (ckgen_rate_t)(div + 1u);
}

void ckgen_rs_config(paddr_t rs_base, ckgen_rs_config_t *config)
{
    uint32 rs_val;

    rs_val = readl(rs_base);

    if (config->rs_en) {
        rs_val &= ~(CKGEN_RS_RS_MASK << CKGEN_RS_RS_LSB);
        rs_val |= (config->rs << CKGEN_RS_RS_LSB);

        rs_val &= ~(1 << CKGEN_RS_LOCK);
        rs_val |= (config->lock << CKGEN_RS_LOCK);

        rs_val |= (1 << CKGEN_RS_EN);
    } else {
        rs_val &= (uint32)(~(1 << CKGEN_RS_EN));
    }

    writel(rs_val, rs_base);
}
#ifdef MCU_CKGEN_RESERVED_FUNCs
int ckgen_dom_perpare(paddr_t base, ckgen_dom_config_t *config)
{
    uint32 dom_reg;
    uint32 dom_lock_reg;

    if (config->rs >= CKGEN_DOM_PER_RS_NUM || \
        config->did >= CKGEN_DOM_PER_DOMAIN_NUM) {
        return -1;
    }

    dom_reg = CKGEN_DOM_PER_BASE(base, config->rs);
    dom_lock_reg = CKGEN_DOM_PER_LOCK_BASE(base, config->rs);

    RMWREG64(dom_reg, CKGEN_DOM_PER_DOMAIN_OFF(config->did),
             8u, config->permission);
    RMWREG64(dom_lock_reg, CKGEN_DOM_PER_LOCK_OFF(config->did),
             1u, config->lock);

    return 0;
}

int ckgen_sup_dom_perpare(paddr_t base, ckgen_sup_dom_config_t *config)
{
    uint32 sup_dom_reg = base + CKGEN_SUP_DOM;

    if (config->did >= CKGEN_DOM_PER_DOMAIN_NUM) {
        return -1;
    }

    RMWREG64(sup_dom_reg, CKGEN_SUP_DOM_DID_LSB, 4u, config->did);
    RMWREG64(sup_dom_reg, CKGEN_SUP_DOM_SEC_EN, 1u, config->sec_en);
    RMWREG64(sup_dom_reg, CKGEN_SUP_DOM_PPROT_LSB, 2u, config->pprot);
    RMWREG64(sup_dom_reg, CKGEN_SUP_DOM_LOCK, 1u, config->lock);

    return 0;
}
#endif
ckgen_rate_t ckgen_ip_get_rate(paddr_t base, uint32 id,
                               ckgen_rate_t src_rate)
{
    uint32 ctrl_reg = CKGEN_IP_CTL_BASE(base, id);
    uint32 ctrl_val;
    uint32 div;

    ctrl_val = readl(ctrl_reg);

    div = (ctrl_val >> CKGEN_IP_CTL_DIV_NUM_LSB) & CKGEN_IP_CTL_DIV_NUM_MASK;

    return (ckgen_rate_t)src_rate / (ckgen_rate_t)(div + 1u);
}

int ckgen_ip_set_rate(paddr_t base, uint32 id, uint8 mux,
                      ckgen_rate_t src_rate, ckgen_rate_t rate)
{
    uint32 ctrl_reg = CKGEN_IP_CTL_BASE(base, id);
    uint32 ctrl_val;
    uint32 div, old_div;

    if (mux > 4) {
        return -1;
    }

    div = ckgen_get_best_div(src_rate, rate);

    if (div == UINT32_MAX || (div - 1u) > CKGEN_IP_CTL_DIV_NUM_MASK) {
        return -1;
    }

    ctrl_val = readl(ctrl_reg);

    old_div = (ctrl_val >> CKGEN_IP_CTL_DIV_NUM_LSB) & CKGEN_IP_CTL_DIV_NUM_MASK;

    /* when new div greater than old, set div before change mux */
    if (div >= old_div) {
        RMWREG32(ctrl_reg, CKGEN_IP_CTL_DIV_NUM_LSB, 8u, div - 1u);

        if (!wait_for_bit_times(ctrl_reg, CKGEN_IP_CTL_DIV_CHG_BUSY,
                                0u, CKGEN_WAIT_TIME)) {
            return -1;
        }
    }

    /* sel ck_in4 first */
    if (BIT(ctrl_val, CKGEN_IP_CTL_D0_ACTIVE)) {
        /* Make sure CG is enabled. */
        RMWREG32(ctrl_reg, CKGEN_IP_CTL_MAIN_EN, 1u, 1u);

        if (!wait_for_bit_times(ctrl_reg, CKGEN_IP_CTL_MAIN_EN_STATUS,
                                1u, CKGEN_WAIT_TIME)) {
            return -1;
        }

        /* set clk_src_sel[2] to 1’b1. */
        RMWREG32(ctrl_reg, CKGEN_IP_CTL_SRC_SEL_CKIN4, 1u, 1u);

        if (!wait_for_bit_times(ctrl_reg, CKGEN_IP_CTL_D0_ACTIVE,
                                0u, CKGEN_WAIT_TIME)) {
            return -1;
        }

        RMWREG32(ctrl_reg, CKGEN_IP_CTL_PRE_EN, 1u, 0u);

        if (!wait_for_bit_times(ctrl_reg, CKGEN_IP_CTL_PRE_EN_STATUS,
                                0u, CKGEN_WAIT_TIME)) {
            return -1;
        }
    }

    /* sel ck_in0 to ck_in3 */
    if (mux < 4) {
        /* set clk_src_sel[1:0] to select the clock.*/
        RMWREG32(ctrl_reg, CKGEN_IP_CTL_SRC_SEL_LSB, 2u, mux);

        /*set reg_pre_en to 1’b1, wait pre_en_ack to 1’b1.*/
        RMWREG32(ctrl_reg, CKGEN_IP_CTL_PRE_EN, 1u, 1u);

        if (!wait_for_bit_times(ctrl_reg, CKGEN_IP_CTL_PRE_EN_STATUS,
                                1u, CKGEN_WAIT_TIME)) {
            return -1;
        }

        /* set clk_src_sel[2] to 1’b0. */
        RMWREG32(ctrl_reg, CKGEN_IP_CTL_SRC_SEL_CKIN4, 1u, 0u);

        RMWREG32(ctrl_reg, CKGEN_IP_CTL_MAIN_EN, 1u, 0u);

        if (!wait_for_bit_times(ctrl_reg, CKGEN_IP_CTL_MAIN_EN_STATUS,
                                0u, CKGEN_WAIT_TIME)) {
            return -1;
        }

        if (!wait_for_bit_times(ctrl_reg, CKGEN_IP_CTL_D0_ACTIVE,
                                1u, CKGEN_WAIT_TIME)) {
            return -1;
        }
    }

    /* when new div less than old, set div after change mux */
    if (div < old_div) {
        RMWREG32(ctrl_reg, CKGEN_IP_CTL_DIV_NUM_LSB, 8u, div - 1u);

        if (!wait_for_bit_times(ctrl_reg, CKGEN_IP_CTL_DIV_CHG_BUSY,
                                0u, CKGEN_WAIT_TIME)) {
            return -1;
        }
    }

    return 0;
}

void ckgen_ip_rs_config(paddr_t base, uint32 id,
                        ckgen_rs_config_t *config)
{
    uint32 rs_base = CKGEN_IP_RS_BASE(base, id);
    ckgen_rs_config(rs_base, config);
}

ckgen_rate_t ckgen_bus_get_rate(paddr_t base, uint32 id,
                                ckgen_rate_t src_rate)
{
    uint32 type = CKGEN_BUS_ID_TYPE(id);

    if (type == CKGEN_BUS_ID_TYPE_ROOT) {
        return src_rate;
    } else if (type == CKGEN_BUS_ID_TYPE_DIV_ROOT) {
        return ckgen_bus_div_root_get_rate(base, id, src_rate);
    } else {
        return ckgen_bus_div_mnpq_get_rate(base, id, src_rate);
    }
}

int ckgen_bus_set_rate(paddr_t base, uint32 id, uint8 mux,
                       ckgen_rate_t src_rate, ckgen_rate_t rate)
{
    uint32 type = CKGEN_BUS_ID_TYPE(id);

    if (type == CKGEN_BUS_ID_TYPE_ROOT) {
        return ckgen_bus_root_set_rate(base, id, mux, src_rate, rate);
    } else if (type == CKGEN_BUS_ID_TYPE_DIV_ROOT) {
        return ckgen_bus_div_root_set_rate(base, id, mux, src_rate, rate);
    }

#ifdef MCU_CKGEN_RESERVED_FUNCs
    else if (type == CKGEN_BUS_ID_TYPE_DIV_SF) {
        return ckgen_sf_bus_set_div_rate(base, id, mux);
    } else if (type == CKGEN_BUS_ID_TYPE_DIV_SP) {
        return ckgen_sp_bus_set_div_rate(base, id, mux);
    }

#endif
    else {
        return ckgen_bus_div_mnpq_set_rate(base, id, src_rate, rate);
    }
}

void ckgen_bus_rs_config(paddr_t base, uint32 id,
                         ckgen_rs_config_t *config)
{
    uint32 rs_base = CKGEN_BUS_RS_BASE(base, id);
    ckgen_rs_config(rs_base, config);
}

ckgen_rate_t ckgen_core_get_rate(paddr_t base, uint32 id,
                                 ckgen_rate_t src_rate)
{
    uint32 ctrl_reg = CKGEN_CORE_CTL_BASE(base, id);
    uint32 ctrl_val;
    uint32 div;

    ctrl_val = readl(ctrl_reg);

    div = (ctrl_val >> CKGEN_CORE_CTL_DIV_NUM_LSB) & CKGEN_CORE_CTL_DIV_NUM_MASK;

    return (ckgen_rate_t)src_rate / (ckgen_rate_t)(div + 1u);
}

int ckgen_drv_core_slice_set_mux(uint32 base, uint32 id, uint8 mux)
{
    uint32 ctrl_reg = CKGEN_CORE_CTL_BASE(base, id);
    sint32 ctrl_val = readl(ctrl_reg);

    /* sel ck_in4 first */
    if (BIT(ctrl_val, CKGEN_CORE_CTL_D0_ACTIVE)) {
        /* Make sure CG is enabled. */
        RMWREG32(ctrl_reg, CKGEN_CORE_CTL_MAIN_EN, 1u, 1u);

        if (!wait_for_bit_times(ctrl_reg, CKGEN_CORE_CTL_MAIN_EN_STATUS,
                                1u, CKGEN_WAIT_TIME)) {
            return -1;
        }

        /* set clk_src_sel[2] to 1’b1. */
        RMWREG32(ctrl_reg, CKGEN_CORE_CTL_SRC_SEL_CKIN4, 1u, 1u);

        if (!wait_for_bit_times(ctrl_reg, CKGEN_CORE_CTL_D0_ACTIVE,
                                0u, CKGEN_WAIT_TIME)) {
            return -1;
        }

        RMWREG32(ctrl_reg, CKGEN_CORE_CTL_PRE_EN, 1u, 0u);

        if (!wait_for_bit_times(ctrl_reg, CKGEN_CORE_CTL_PRE_EN_STATUS,
                                0u, CKGEN_WAIT_TIME)) {
            return -1;
        }
    }

    /* sel ck_in0 to ck_in3 */
    if (mux < 4) {
        /* set clk_src_sel[1:0] to select the clock.*/
        RMWREG32(ctrl_reg, CKGEN_CORE_CTL_SRC_SEL_LSB, 2u, mux);

        /*set reg_pre_en to 1’b1, wait pre_en_ack to 1’b1.*/
        RMWREG32(ctrl_reg, CKGEN_CORE_CTL_PRE_EN, 1u, 1u);

        if (!wait_for_bit_times(ctrl_reg, CKGEN_CORE_CTL_PRE_EN_STATUS,
                                1u, CKGEN_WAIT_TIME)) {
            return -1;
        }

        /* set clk_src_sel[2] to 1’b0. */
        RMWREG32(ctrl_reg, CKGEN_CORE_CTL_SRC_SEL_CKIN4, 1u, 0u);

        RMWREG32(ctrl_reg, CKGEN_CORE_CTL_MAIN_EN, 1u, 0u);

        if (!wait_for_bit_times(ctrl_reg, CKGEN_CORE_CTL_MAIN_EN_STATUS,
                                0u, CKGEN_WAIT_TIME)) {
            return -1;
        }

        if (!wait_for_bit_times(ctrl_reg, CKGEN_CORE_CTL_D0_ACTIVE,
                                1u, CKGEN_WAIT_TIME)) {
            return -1;
        }
    }

    return 0;
}

int ckgen_drv_core_slice_set_div(uint32 base, uint32 id, uint32 div)
{
    uint32 ctrl_reg = CKGEN_CORE_CTL_BASE(base, id);

    RMWREG32(ctrl_reg, CKGEN_CORE_CTL_DIV_NUM_LSB, 5u, div - 1u);

    if (!wait_for_bit_times(ctrl_reg, CKGEN_CORE_CTL_DIV_CHG_BUSY,
                            0u, CKGEN_WAIT_TIME)) {
        return -1;
    }

    return 0;
}

int ckgen_core_set_rate(paddr_t base, clk_node_t *clk, ckgen_rate_t rate)
{
    uint32 div;
    int mux;

    /* select the suitable parent */
    mux = clk->core->ops->select_parent(clk, rate, &div);

    if (mux < 0) {
        return -1;
    }

    /* set pre mux */
    if (ckgen_drv_core_slice_set_mux(base, clk->id, (uint8)mux) < 0) {
        return -1;
    }

    /* if mux is 0~3, set pre div */
    if (mux != 4) {
        if (ckgen_drv_core_slice_set_div(base, clk->id, div) < 0) {
            return -1;
        }
    }

    return 0;
}

void ckgen_core_rs_config(paddr_t base, uint32 id,
                          ckgen_rs_config_t *config)
{
    uint32 rs_base = CKGEN_CORE_RS_BASE(base, id);
    ckgen_rs_config(rs_base, config);
}

static inline uint32 ckgen_xcg_get_ctrl_reg(paddr_t base, uint32 id)
{
    return CKGEN_XCG_CTL_BASE(base, id, CKGEN_CG_ID_TYPE(id));
}
#ifdef MCU_CKGEN_RESERVED_FUNCs
static inline uint32 ckgen_xcg_get_rs_reg(paddr_t base, uint32 id)
{
    return CKGEN_XCG_RS_BASE(base, id, CKGEN_CG_ID_TYPE(id));
}

int ckgen_xcg_set_gating_state(paddr_t base, uint32 id, uint8 cg_state)
{
    uint32 ctrl_reg = ckgen_xcg_get_ctrl_reg(base, id);
    RMWREG32(ctrl_reg, CKGEN_CG_CTL_RUN_MODE, 3u, cg_state);
    return 0;
}
#endif
int ckgen_xcg_set_gating_by_mode(paddr_t base, uint32 id,
                                 uint8 lp_mode, bool en)
{
    uint32 ctrl_reg = ckgen_xcg_get_ctrl_reg(base, id);
    RMWREG32(ctrl_reg, lp_mode, 1u, en);
    return 0;
}

bool ckgen_xcg_is_gated(paddr_t base, uint32 id)
{
    uint32 ctrl_reg = ckgen_xcg_get_ctrl_reg(base, id);
    return (readl(ctrl_reg) >> CKGEN_CG_CTL_CG_GATED) & 0x1u;
}

int ckgen_pll_set_gating_by_mode(paddr_t base, uint32 id,
                                 uint8 lp_mode, bool en)
{
    uint32 pll_ctrl = CKGEN_PLL_CTL_BASE(base, id);

    RMWREG32(pll_ctrl, CKGEN_PLL_CTL_IGNORE, 1u, 0u);
    RMWREG32(pll_ctrl, lp_mode, 1u, en);
    return 0;
}

int ckgen_xtal_set_gating_by_mode(paddr_t base, uint8 lp_mode, bool en)
{
    uint32 xtal_ctrl = base + CKGEN_XTAL_CTL;

    RMWREG32(xtal_ctrl, CKGEN_XTAL_CTL_IGNORE, 1u, 0u);
    RMWREG32(xtal_ctrl, lp_mode, 1u, en);
    return 0;
}
#ifdef MCU_CKGEN_RESERVED_FUNCs
int ckgen_pll_set_gating_state(paddr_t base, uint32 id, uint8 cg_state)
{
    uint32 pll_ctrl = CKGEN_PLL_CTL_BASE(base, id);

    RMWREG32(pll_ctrl, CKGEN_PLL_CTL_IGNORE, 1u, 0u);
    RMWREG32(pll_ctrl, CKGEN_PLL_CTL_RUN_MODE, 3u, cg_state);
    return 0;
}

int ckgen_xtal_set_gating_state(paddr_t base, uint8 cg_state)
{
    uint32 xtal_ctrl = base + CKGEN_XTAL_CTL;

    RMWREG32(xtal_ctrl, CKGEN_XTAL_CTL_IGNORE, 1u, 0u);
    RMWREG32(xtal_ctrl, CKGEN_XTAL_CTL_RUN_MODE, 3u, cg_state);
    return 0;
}


void ckgen_xcg_lp_mask(paddr_t base, uint32 id)
{
    uint32 ctrl_reg = ckgen_xcg_get_ctrl_reg(base, id);
    RMWREG32(ctrl_reg, CKGEN_CG_CTL_LP_MASK, 1u, 1u);
}

void ckgen_xcg_lp_unmask(paddr_t base, uint32 id)
{
    uint32 ctrl_reg = ckgen_xcg_get_ctrl_reg(base, id);
    RMWREG32(ctrl_reg, CKGEN_CG_CTL_LP_MASK, 1u, 0u);
}

void ckgen_xcg_rs_config(paddr_t base, uint32 id,
                         ckgen_rs_config_t *config)
{
    uint32 rs_base = ckgen_xcg_get_rs_reg(base, id);
    ckgen_rs_config(rs_base, config);
}


int ckgen_pll_set_pd_state(paddr_t base, uint32 id, uint8 pd_state)
{
    RMWREG32(CKGEN_PLL_CTL_BASE(base, id),
             CKGEN_PLL_PD_RUN_MODE, 3u, pd_state);
    return 0;
}

void ckgen_ip_cor_int_enable(paddr_t base, uint32 id, bool en)
{
    uint32 cor_en = CKGEN_IP_CLK_COR_EN_BASE(base, (id / 32u));
    RMWREG32(cor_en, (id % 32u), 1u, en);
}

void ckgen_ip_unc_int_enable(paddr_t base, uint32 id, bool en)
{
    uint32 unc_en = CKGEN_IP_CLK_UNC_EN_BASE(base, (id / 32u));
    RMWREG32(unc_en, (id % 32u), 1u, en);
}

bool ckgen_ip_get_int_state(paddr_t base, uint32 id)
{
    uint32 state = CKGEN_IP_CLK_INT_STA_BASE(base, (id / 32u));
    return !!(readl(state) >> (id % 32u));
}

void ckgen_ip_clear_int_state(paddr_t base, uint32 id)
{
    uint32 reg = CKGEN_IP_CLK_INT_STA_BASE(base, (id / 32u));
    RMWREG32(reg, (id % 32u), 1u, 0u);
}

void ckgen_bus_cor_int_enable(paddr_t base, uint32 id, bool en)
{
    uint32 cor_en = CKGEN_BUS_CLK_COR_EN_BASE(base,
                    ((id & CKGEN_BUS_ID_NUM_MASK) / 32u));
    RMWREG32(cor_en, (id % 32u), 1u, en);
}

void ckgen_bus_unc_int_enable(paddr_t base, uint32 id, bool en)
{
    uint32 unc_en = CKGEN_BUS_CLK_UNC_EN_BASE(base,
                    ((id & CKGEN_BUS_ID_NUM_MASK) / 32u));
    RMWREG32(unc_en, (id % 32u), 1u, en);
}

bool ckgen_bus_get_int_state(paddr_t base, uint32 id)
{
    uint32 state = CKGEN_BUS_CLK_INT_STA_BASE(base,
                   ((id & CKGEN_BUS_ID_NUM_MASK) / 32u));
    return !!(readl(state) >> (id % 32u));
}

void ckgen_bus_clear_int_state(paddr_t base, uint32 id)
{
    uint32 reg = CKGEN_BUS_CLK_INT_STA_BASE(base,
                                            ((id & CKGEN_BUS_ID_NUM_MASK) / 32u));
    RMWREG32(reg, (id % 32u), 1u, 0u);
}

void ckgen_core_cor_int_enable(paddr_t base, uint32 id, bool en)
{
    uint32 cor_en = CKGEN_CORE_CLK_COR_EN_BASE(base, (id / 32u));
    RMWREG32(cor_en, (id % 32u), 1u, en);
}

void ckgen_core_unc_int_enable(paddr_t base, uint32 id, bool en)
{
    uint32 unc_en = CKGEN_CORE_CLK_UNC_EN_BASE(base, (id / 32u));
    RMWREG32(unc_en, (id % 32u), 1u, en);
}

bool ckgen_core_get_int_state(paddr_t base, uint32 id)
{
    uint32 state = CKGEN_CORE_CLK_INT_STA_BASE(base, (id / 32u));
    return !!(readl(state) >> (id % 32u));
}

void ckgen_core_clear_int_state(paddr_t base, uint32 id)
{
    uint32 reg = CKGEN_CORE_CLK_INT_STA_BASE(base, (id / 32u));
    RMWREG32(reg, (id % 32u), 1u, 0u);
}

void ckgen_xcg_cor_int_enable(paddr_t base, uint32 id, bool en)
{
    uint32 cor_en = CKGEN_XCG_COR_EN_BASE(base, (id / 32u), CKGEN_CG_ID_TYPE(id));
    RMWREG32(cor_en, (id % 32u), 1u, en);
}

void ckgen_xcg_unc_int_enable(paddr_t base, uint32 id, bool en)
{
    uint32 unc_en = CKGEN_XCG_UNC_EN_BASE(base, (id / 32u), CKGEN_CG_ID_TYPE(id));
    RMWREG32(unc_en, (id % 32u), 1u, en);
}

bool ckgen_xcg_get_int_state(paddr_t base, uint32 id)
{
    uint32 state = CKGEN_XCG_INT_STA_BASE(base, (id / 32u), CKGEN_CG_ID_TYPE(id));
    return !!(readl(state) >> (id % 32u));
}

void ckgen_xcg_clear_int_state(paddr_t base, uint32 id)
{
    uint32 state = CKGEN_XCG_INT_STA_BASE(base, (id / 32u), CKGEN_CG_ID_TYPE(id));
    RMWREG32(state, (id % 32u), 1u, 0u);
}
#endif
#ifdef CONFIG_CLK_MONITOR
static ckgen_rate_t ckgen_mon_calc_freq(paddr_t base, uint32 freq_mon, uint8 div_a_b)
{
    uint32 glb_ctrl_val;
    uint32 div_a_b_num;
    ckgen_rate_t rate = 0;

    glb_ctrl_val = readl(CKGEN_GLB_CTL_BASE(base));

    if (div_a_b) {
        /* 24M divb */
        div_a_b_num = (glb_ctrl_val >> CKGEN_GLB_CTL_24M_DIVB_NUM_LSB) & CKGEN_GLB_CTL_24M_DIVB_NUM_MASK;
    } else {
        /* 24M diva */
        div_a_b_num = (glb_ctrl_val >> CKGEN_GLB_CTL_24M_DIVA_NUM_LSB) & CKGEN_GLB_CTL_24M_DIVA_NUM_MASK;
    }

    rate = 12000000 / (div_a_b_num + 1);
    rate = rate * freq_mon;

    return rate;
}

void ckgen_set_mon_div_num(paddr_t base, uint8 div_type, uint32 div_num)
{
    uint32 glb_ctrl = CKGEN_GLB_CTL_BASE(base);
    uint32 div_off;
    uint32 div_width;

    if (div_type == CKGEN_MON_DIVA) {
        div_off = CKGEN_GLB_CTL_24M_DIVA_NUM_LSB;
        div_width = 10;
    } else if (div_type == CKGEN_MON_DIVB) {
        div_off = CKGEN_GLB_CTL_24M_DIVB_NUM_LSB;
        div_width = 10;
    } else if (div_type == CKGEN_MON_DIVC) {
        div_off = CKGEN_GLB_CTL_24M_DIVC_NUM_LSB;
        div_width = 4;
    } else {
        return;
    }

    RMWREG32(glb_ctrl, div_off, div_width, div_num);
}

ckgen_rate_t ckgen_ip_mon_get_rate(paddr_t base, uint32 id)
{
    uint32 ip_mon_ctrl = CKGEN_IP_MON_CTL_BASE(base, id);
    uint32 ip_ctrl = CKGEN_IP_CTL_BASE(base, id);
    uint32 ip_mon_ctrl_val;
    uint32 freq_mon;
    uint8 div_a_b;
    ckgen_rate_t rate = 0;

    /* disable ip mon */
    if (BIT(readl(ip_mon_ctrl), CKGEN_IP_MON_CTL_EN)) {
        RMWREG32(ip_mon_ctrl, CKGEN_IP_MON_CTL_EN, 1u, 0u);

        if (!wait_for_bit_times(ip_mon_ctrl, CKGEN_IP_MON_CTL_EN_STA,
                                0u, CKGEN_WAIT_TIME)) {
            return 0;
        }
    }

    /* clear freq mon */
    RMWREG32(ip_mon_ctrl, CKGEN_IP_MON_CTL_FREQ_LSB, 16u, 0u);
    RMWREG32(ip_mon_ctrl, CKGEN_IP_MON_CTL_FREQ_UPD, 1u, 0u);

    /* enable ip slice debug */
    RMWREG32(ip_ctrl, CKGEN_IP_CTL_DBG_EN, 1u, 1u);

    /* enable ip mon */
    RMWREG32(ip_mon_ctrl, CKGEN_IP_MON_CTL_EN, 1u, 1u);

    if (!wait_for_bit_times(ip_mon_ctrl, CKGEN_IP_MON_CTL_EN_STA,
                            1u, CKGEN_WAIT_TIME)) {
        goto ip_mon_get_rate_out;
    }

    if (!wait_for_bit_times(ip_mon_ctrl, CKGEN_IP_MON_CTL_FREQ_UPD,
                            1u, CKGEN_WAIT_TIME)) {
        goto ip_mon_get_rate_out;
    }

    ip_mon_ctrl_val = readl(ip_mon_ctrl);
    freq_mon = (ip_mon_ctrl_val >> CKGEN_IP_MON_CTL_FREQ_LSB) & CKGEN_IP_MON_CTL_FREQ_MASK;
    div_a_b = (ip_mon_ctrl_val >> CKGEN_IP_MON_CTL_SRC_SEL) & 0x1;

    rate = ckgen_mon_calc_freq(base, freq_mon, div_a_b);

ip_mon_get_rate_out:

    /* disable ip mon */
    RMWREG32(ip_mon_ctrl, CKGEN_IP_MON_CTL_EN, 1u, 0u);
    wait_for_bit_times(ip_mon_ctrl, CKGEN_IP_MON_CTL_EN_STA,
                       0u, CKGEN_WAIT_TIME);

    /* disable ip slice debug */
    RMWREG32(ip_ctrl, CKGEN_IP_CTL_DBG_EN, 1u, 0u);

    return rate;
}

void ckgen_ip_mon_set_thrd(paddr_t base, uint32 id,
                           uint16 low_thrd, uint16 high_thrd)
{
    uint32 mon_thrd = CKGEN_IP_MON_THRD_BASE(base, id);
    RMWREG32(mon_thrd, CKGEN_IP_MON_THRD_LOW_LSB, 16u, low_thrd);
    RMWREG32(mon_thrd, CKGEN_IP_MON_THRD_HIGH_LSB, 16u, high_thrd);
}

ckgen_rate_t ckgen_bus_mon_get_rate(paddr_t base, uint32 id)
{
    uint32 bus_mon_ctrl = CKGEN_BUS_MON_CTL0_BASE(base, id);
    uint32 bus_mon_out;
    uint32 bus_ctrl = CKGEN_BUS_CTL_BASE(base, id);
    uint32 type = CKGEN_BUS_ID_TYPE(id);
    uint32 freq_lsb;
    uint32 out;
    uint32 bus_mon_ctrl_val;
    uint32 freq_mon;
    uint8 div_a_b;
    ckgen_rate_t rate = 0;

    if (type == CKGEN_BUS_ID_TYPE_DIV_N) {
        out = 1;
        bus_mon_out = CKGEN_BUS_MON_CTL1_BASE(base, id);
        freq_lsb = CKGEN_BUS_MON_CTL1_FREQ1_LSB;
    } else if (type == CKGEN_BUS_ID_TYPE_DIV_P) {
        out = 2;
        bus_mon_out = CKGEN_BUS_MON_CTL2_BASE(base, id);
        freq_lsb = CKGEN_BUS_MON_CTL2_FREQ2_LSB;
    } else if (type == CKGEN_BUS_ID_TYPE_DIV_Q) {
        out = 3;
        bus_mon_out = CKGEN_BUS_MON_CTL2_BASE(base, id);
        freq_lsb = CKGEN_BUS_MON_CTL2_FREQ3_LSB;
    } else {
        out = 0;
        bus_mon_out = CKGEN_BUS_MON_CTL1_BASE(base, id);
        freq_lsb = CKGEN_BUS_MON_CTL1_FREQ0_LSB;
    }

    /* disable bus mon */
    if (BIT(readl(bus_mon_ctrl), CKGEN_BUS_MON_CTL0_EN)) {
        RMWREG32(bus_mon_ctrl, CKGEN_BUS_MON_CTL0_EN, 1u, 0u);

        if (!wait_for_bit_times(bus_mon_ctrl, CKGEN_BUS_MON_CTL0_EN_STA,
                                0u, CKGEN_WAIT_TIME)) {
            return 0;
        }
    }

    /* clear freq mon */
    writel(0u, bus_mon_out);
    RMWREG32(bus_mon_ctrl, CKGEN_BUS_MON_CTL0_FREQ_UPD(out), 1u, 0u);

    /* enable bus slice debug */
    RMWREG32(bus_ctrl, CKGEN_BUS_CTL_DBG_EN, 1u, 1u);

    /* enable bus mon */
    RMWREG32(bus_mon_ctrl, CKGEN_BUS_MON_CTL0_EN, 1u, 1u);

    if (!wait_for_bit_times(bus_mon_ctrl, CKGEN_BUS_MON_CTL0_EN_STA,
                            1u, CKGEN_WAIT_TIME)) {
        goto bus_mon_get_rate_out;
    }

    if (!wait_for_bit_times(bus_mon_ctrl, CKGEN_BUS_MON_CTL0_FREQ_UPD(out),
                            1u, CKGEN_WAIT_TIME)) {
        goto bus_mon_get_rate_out;
    }

    freq_mon = (readl(bus_mon_out) >> freq_lsb) & CKGEN_BUS_MON_CTL_FREQ_MASK;

    bus_mon_ctrl_val = readl(bus_mon_ctrl);
    div_a_b = (bus_mon_ctrl_val >> CKGEN_BUS_MON_CTL0_SRC_SEL) & 0x1;

    rate = ckgen_mon_calc_freq(base, freq_mon, div_a_b);

bus_mon_get_rate_out:

    /* disable bus mon */
    RMWREG32(bus_mon_ctrl, CKGEN_BUS_MON_CTL0_EN, 1u, 0u);
    wait_for_bit_times(bus_mon_ctrl, CKGEN_BUS_MON_CTL0_EN_STA,
                       0u, CKGEN_WAIT_TIME);

    /* disable bus slice debug */
    RMWREG32(bus_ctrl, CKGEN_BUS_CTL_DBG_EN, 1u, 0u);

    return rate;
}

void ckgen_bus_mon_set_thrd(paddr_t base, uint32 id,
                            uint16 low_thrd, uint16 high_thrd)
{
    uint32 type = CKGEN_BUS_ID_TYPE(id);
    uint32 bus_mon_thrd;

    if (type == CKGEN_BUS_ID_TYPE_DIV_N) {
        bus_mon_thrd = CKGEN_BUS_MON_THRD1_BASE(base, id);
    } else if (type == CKGEN_BUS_ID_TYPE_DIV_P) {
        bus_mon_thrd = CKGEN_BUS_MON_THRD2_BASE(base, id);
    } else if (type == CKGEN_BUS_ID_TYPE_DIV_Q) {
        bus_mon_thrd = CKGEN_BUS_MON_THRD3_BASE(base, id);
    } else {
        bus_mon_thrd = CKGEN_BUS_MON_THRD0_BASE(base, id);
    }

    RMWREG32(bus_mon_thrd, CKGEN_BUS_MON_THRD_LOW_LSB, 16u, low_thrd);
    RMWREG32(bus_mon_thrd, CKGEN_BUS_MON_THRD_HIGH_LSB, 16u, high_thrd);
}

ckgen_rate_t ckgen_core_mon_get_rate(paddr_t base, uint32 id)
{
    uint32 core_mon_ctrl = CKGEN_CORE_MON_CTL_BASE(base, id);
    uint32 core_ctrl = CKGEN_CORE_CTL_BASE(base, id);
    uint32 core_mon_ctrl_val;
    uint32 freq_mon;
    uint8 div_a_b;
    ckgen_rate_t rate = 0;

    /* disable core mon */
    if (BIT(readl(core_mon_ctrl), CKGEN_CORE_MON_CTL_EN)) {
        RMWREG32(core_mon_ctrl, CKGEN_CORE_MON_CTL_EN, 1u, 0u);

        if (!wait_for_bit_times(core_mon_ctrl, CKGEN_CORE_MON_CTL_EN_STA,
                                0u, CKGEN_WAIT_TIME)) {
            return 0;
        }
    }

    /* clear freq mon */
    RMWREG32(core_mon_ctrl, CKGEN_CORE_MON_CTL_FREQ_LSB, 16u, 0u);
    RMWREG32(core_mon_ctrl, CKGEN_CORE_MON_CTL_FREQ_UPD, 1u, 0u);

    /* enable core slice debug */
    RMWREG32(core_ctrl, CKGEN_CORE_CTL_DBG_EN, 1u, 1u);

    /* enable core mon */
    RMWREG32(core_mon_ctrl, CKGEN_CORE_MON_CTL_EN, 1u, 1u);

    if (!wait_for_bit_times(core_mon_ctrl, CKGEN_CORE_MON_CTL_EN_STA,
                            1u, CKGEN_WAIT_TIME)) {
        goto core_mon_get_rate_out;
    }

    if (!wait_for_bit_times(core_mon_ctrl, CKGEN_CORE_MON_CTL_FREQ_UPD,
                            1u, CKGEN_WAIT_TIME)) {
        goto core_mon_get_rate_out;
    }

    core_mon_ctrl_val = readl(core_mon_ctrl);
    freq_mon = (core_mon_ctrl_val >> CKGEN_CORE_MON_CTL_FREQ_LSB) & CKGEN_CORE_MON_CTL_FREQ_MASK;
    div_a_b = (core_mon_ctrl_val >> CKGEN_CORE_MON_CTL_SRC_SEL) & 0x1;

    rate = ckgen_mon_calc_freq(base, freq_mon, div_a_b);

core_mon_get_rate_out:

    /* disable core mon */
    RMWREG32(core_mon_ctrl, CKGEN_CORE_MON_CTL_EN, 1u, 0u);
    wait_for_bit_times(core_mon_ctrl, CKGEN_CORE_MON_CTL_EN_STA,
                       0u, CKGEN_WAIT_TIME);

    /* disable core slice debug */
    RMWREG32(core_ctrl, CKGEN_CORE_CTL_DBG_EN, 1u, 0u);

    return rate;
}

void ckgen_core_mon_set_thrd(paddr_t base, uint32 id,
                             uint16 low_thrd, uint16 high_thrd)
{
    uint32 mon_thrd = CKGEN_CORE_MON_THRD_BASE(base, id);
    RMWREG32(mon_thrd, CKGEN_CORE_MON_THRD_LOW_LSB, 16u, low_thrd);
    RMWREG32(mon_thrd, CKGEN_CORE_MON_THRD_HIGH_LSB, 16u, high_thrd);
}

void ckgen_xcg_debug_enable(paddr_t base, uint32 id, bool en)
{
    uint32 ctrl_reg = ckgen_xcg_get_ctrl_reg(base, id);
    RMWREG32(ctrl_reg, CKGEN_CG_CTL_DBG_EN, 1u, en);
}

void ckgen_xcg_amon_enable(paddr_t base, uint32 id, bool en)
{
    uint32 ctrl_reg = ckgen_xcg_get_ctrl_reg(base, id);
    RMWREG32(ctrl_reg, CKGEN_CG_CTL_ACTIVE_MON_EN, 1u, en);
}

uint8 ckgen_xcg_get_amon_state(paddr_t base, uint32 id)
{
    uint32 ctrl_reg = ckgen_xcg_get_ctrl_reg(base, id);
    return (readl(ctrl_reg) >> CKGEN_CG_CTL_ACTIVE_MON_STA) & 0x1u;
}

void ckgen_pll_mon_enable(paddr_t base, uint32 id, uint32 tout)
{
    uint32 mon_ctrl = CKGEN_PLL_MON_CTL_BASE(base, id);
    RMWREG32(mon_ctrl, CKGEN_PLL_MON_CTL_TOUT_VAL_LSB, 16u, tout);
    RMWREG32(mon_ctrl, CKGEN_PLL_MON_CTL_EN, 1u, 1u);
}

void ckgen_pll_mon_disable(paddr_t base, uint32 id)
{
    uint32 mon_ctrl = CKGEN_PLL_MON_CTL_BASE(base, id);
    RMWREG32(mon_ctrl, CKGEN_PLL_MON_CTL_EN, 1u, 0u);
}

uint8 ckgen_pll_mon_get_state(paddr_t base, uint32 id)
{
    uint32 mon_ctrl = CKGEN_PLL_MON_CTL_BASE(base, id);
    return (readl(mon_ctrl) >> CKGEN_PLL_MON_CTL_CLK_READY) & 0x1u;
}

void ckgen_xtal_mon_enable(paddr_t base, uint32 tout)
{
    uint32 xtal_mon = base + CKGEN_XTAL_MON_CTL;
    RMWREG32(xtal_mon, CKGEN_XTAL_MON_CTL_TOUT_VAL_LSB, 16u, tout);
    RMWREG32(xtal_mon, CKGEN_XTAL_MON_CTL_EN, 1u, 1u);
    wait_for_bit_times(xtal_mon, CKGEN_XTAL_MON_CTL_EN_STA,
                       1u, CKGEN_WAIT_TIME);
}

void ckgen_xtal_mon_disable(paddr_t base)
{
    uint32 xtal_mon = base + CKGEN_XTAL_MON_CTL;
    RMWREG32(xtal_mon, CKGEN_XTAL_MON_CTL_EN, 1u, 0u);
    wait_for_bit_times(xtal_mon, CKGEN_XTAL_MON_CTL_EN_STA,
                       0u, CKGEN_WAIT_TIME);
}

uint8 ckgen_xtal_mon_get_rc24m_state(paddr_t base)
{
    uint32 xtal_mon = base + CKGEN_XTAL_MON_CTL;
    return (readl(xtal_mon) >> CKGEN_XTAL_MON_CTL_RC24M_ACTIVE) & 0x1u;
}

uint8 ckgen_xtal_mon_get_xtal_state(paddr_t base)
{
    uint32 xtal_mon = base + CKGEN_XTAL_MON_CTL;
    return (readl(xtal_mon) >> CKGEN_XTAL_MON_CTL_XTAL_ACTIVE) & 0x1u;
}

static void ckgen_dbg_mon_src_config(paddr_t base, uint8 src, uint32 id)
{
    uint32 dbg_mon_src = base + CKGEN_DBG_MON_CLK_SRC;
    uint32 dbg_mon_ctl = base + CKGEN_DBG_MON_CTL;

    RMWREG32(dbg_mon_src, CKGEN_DBG_MON_CLK_SRC_LSB(src), 8u, id);
    RMWREG32(dbg_mon_ctl, CKGEN_DBG_MON_CTL_CLK_SEL_LSB, 2u, src);
}

static uint32 ckgen_dbg_mon_get_rate(paddr_t base, uint8 src, uint32 id)
{
    uint32 dbg_mon_ctl = base + CKGEN_DBG_MON_CTL;
    uint32 mon_ctl = base + CKGEN_MON_CTL;
    uint32 mon_ctl_val;
    uint32 freq_mon;
    uint32 div_a_b;
    uint32 rate = 0;

    if (BIT(readl(mon_ctl), CKGEN_MON_CTL_EN)) {
        RMWREG32(mon_ctl, CKGEN_MON_CTL_EN, 1u, 0u);

        if (!wait_for_bit_times(mon_ctl, CKGEN_MON_CTL_EN_STA,
                                0u, CKGEN_WAIT_TIME)) {
            return 0;
        }
    }

    ckgen_dbg_mon_src_config(base, src, id);

    RMWREG32(dbg_mon_ctl, CKGEN_DBG_MON_CTL_MON_GATING_EN, 1u, 1u);

    RMWREG32(mon_ctl, CKGEN_MON_CTL_FREQ_LSB, 16u, 0u);
    RMWREG32(mon_ctl, CKGEN_MON_CTL_FREQ_UPD, 1u, 0u);

    RMWREG32(mon_ctl, CKGEN_MON_CTL_EN, 1u, 1u);

    if (!wait_for_bit_times(mon_ctl, CKGEN_MON_CTL_EN_STA,
                            1u, CKGEN_WAIT_TIME)) {
        goto dbg_mon_get_ip_rate_out;
    }

    if (!wait_for_bit_times(mon_ctl, CKGEN_MON_CTL_FREQ_UPD,
                            1u, CKGEN_WAIT_TIME)) {
        goto dbg_mon_get_ip_rate_out;
    }

    mon_ctl_val = readl(mon_ctl);
    freq_mon = (mon_ctl_val >> CKGEN_MON_CTL_FREQ_LSB) & CKGEN_MON_CTL_FREQ_MASK;
    div_a_b = (mon_ctl_val >> CKGEN_MON_CTL_SRC_SEL) & 0x1;

    rate = ckgen_mon_calc_freq(base, freq_mon, div_a_b);

dbg_mon_get_ip_rate_out:

    RMWREG32(dbg_mon_ctl, CKGEN_DBG_MON_CTL_MON_GATING_EN, 1u, 0u);

    RMWREG32(mon_ctl, CKGEN_MON_CTL_EN, 1u, 0u);
    wait_for_bit_times(mon_ctl, CKGEN_MON_CTL_EN_STA,
                       0u, CKGEN_WAIT_TIME);

    return rate;
}

uint32 ckgen_dbg_mon_get_ip_rate(paddr_t base, uint32 id)
{
    uint32 ip_ctrl = CKGEN_IP_CTL_BASE(base, id);
    uint32 rate;

    /* enable ip slice debug */
    RMWREG32(ip_ctrl, CKGEN_IP_CTL_DBG_EN, 1u, 1u);

    rate = ckgen_dbg_mon_get_rate(base, 0, id);

    /* disable ip slice debug */
    RMWREG32(ip_ctrl, CKGEN_IP_CTL_DBG_EN, 1u, 0u);

    return rate;
}

uint32 ckgen_dbg_mon_get_bus_rate(paddr_t base, uint32 id)
{
    uint32 bus_ctrl = CKGEN_BUS_CTL_BASE(base, id);
    uint32 rate;

    /* enable bus slice debug */
    RMWREG32(bus_ctrl, CKGEN_BUS_CTL_DBG_EN, 1u, 1u);

    rate = ckgen_dbg_mon_get_rate(base, 1, id);

    /* disable bus slice debug */
    RMWREG32(bus_ctrl, CKGEN_BUS_CTL_DBG_EN, 1u, 0u);

    return rate;
}

uint32 ckgen_dbg_mon_get_core_rate(paddr_t base, uint32 id)
{
    uint32 core_ctrl = CKGEN_CORE_CTL_BASE(base, id);
    uint32 rate;

    /* enable core slice debug */
    RMWREG32(core_ctrl, CKGEN_CORE_CTL_DBG_EN, 1u, 1u);

    rate = ckgen_dbg_mon_get_rate(base, 2, id);

    /* disable core slice debug */
    RMWREG32(core_ctrl, CKGEN_CORE_CTL_DBG_EN, 1u, 0u);

    return rate;
}

uint32 ckgen_dbg_mon_get_ext_rate(paddr_t base, uint32 id)
{
    return ckgen_dbg_mon_get_rate(base, 3, id);
}

void ckgen_dbg_mon_ip_select(paddr_t base, uint32 id)
{
    uint32 ip_ctrl = CKGEN_IP_CTL_BASE(base, id);
    uint32 dbg_mon_ctl = base + CKGEN_DBG_MON_CTL;

    RMWREG32(ip_ctrl, CKGEN_IP_CTL_DBG_EN, 1u, 1u);
    ckgen_dbg_mon_src_config(base, 0, id);
    RMWREG32(dbg_mon_ctl, CKGEN_DBG_MON_CTL_DBG_GATING_EN, 1u, 1u);
}

void ckgen_dbg_mon_bus_select(paddr_t base, uint32 id)
{
    uint32 bus_ctrl = CKGEN_BUS_CTL_BASE(base, id);
    uint32 dbg_mon_ctl = base + CKGEN_DBG_MON_CTL;

    RMWREG32(bus_ctrl, CKGEN_BUS_CTL_DBG_EN, 1u, 1u);
    ckgen_dbg_mon_src_config(base, 1, id);
    RMWREG32(dbg_mon_ctl, CKGEN_DBG_MON_CTL_DBG_GATING_EN, 1u, 1u);
}

void ckgen_dbg_mon_core_select(paddr_t base, uint32 id)
{
    uint32 core_ctrl = CKGEN_CORE_CTL_BASE(base, id);
    uint32 dbg_mon_ctl = base + CKGEN_DBG_MON_CTL;

    RMWREG32(core_ctrl, CKGEN_CORE_CTL_DBG_EN, 1u, 1u);
    ckgen_dbg_mon_src_config(base, 2, id);
    RMWREG32(dbg_mon_ctl, CKGEN_DBG_MON_CTL_DBG_GATING_EN, 1u, 1u);
}

void ckgen_dbg_mon_ext_select(paddr_t base, uint32 id)
{
    uint32 dbg_mon_ctl = base + CKGEN_DBG_MON_CTL;

    ckgen_dbg_mon_src_config(base, 3, id);
    RMWREG32(dbg_mon_ctl, CKGEN_DBG_MON_CTL_DBG_GATING_EN, 1u, 1u);
}

void ckgen_cqm_enable(paddr_t base, uint32 id,
                      uint16 duty, uint16 jitter)
{
    uint32 dbg_mon_ctl = base + CKGEN_DBG_MON_CTL;
    uint32 cqm_ctl = CKGEN_CQM_CTL_BASE(base, id);

    /* enable cqm gating */
    RMWREG32(dbg_mon_ctl, CKGEN_DBG_MON_CTL_CQM_GATING_EN, 1u, 1u);

    /* config cqm jitter and duty */
    RMWREG32(cqm_ctl, CKGEN_CQM_CTL_JITTER_RATE_LSB, 6u, jitter);
    RMWREG32(cqm_ctl, CKGEN_CQM_CTL_DUTY_RATE_LSB, 6u, duty);

    /* enable cqm mon */
    RMWREG32(cqm_ctl, CKGEN_CQM_CTL_MON_EN, 1u, 1u);
}

void ckgen_cqm_disable(paddr_t base, uint32 id)
{
    uint32 dbg_mon_ctl = base + CKGEN_DBG_MON_CTL;
    uint32 cqm_ctl = CKGEN_CQM_CTL_BASE(base, id);

    RMWREG32(cqm_ctl, CKGEN_CQM_CTL_MON_EN, 1u, 0u);
    RMWREG32(dbg_mon_ctl, CKGEN_DBG_MON_CTL_CQM_GATING_EN, 1u, 0u);
}

void ckgen_cqm_cor_int_enable(paddr_t base, uint32 id, bool en)
{
    RMWREG32(base + CKGEN_CQM_COR_EN, (id % 7u), 1u, en);
}

void ckgen_cqm_unc_int_enable(paddr_t base, uint32 id, bool en)
{
    RMWREG32(base + CKGEN_CQM_UNC_EN, (id % 7u), 1u, en);
}

bool ckgen_cqm_get_duty_int_state(paddr_t base, uint32 id)
{
    return !!(readl(base + CKGEN_CQM_DUTY_INT_STA) >> (id % 7u));
}

bool ckgen_cqm_get_jitter_int_state(paddr_t base, uint32 id)
{
    return !!(readl(base + CKGEN_CQM_JITTER_INT_STA) >> (id % 7u));
}

void ckgen_cqm_clear_duty_int_state(paddr_t base, uint32 id)
{
    RMWREG32(base + CKGEN_CQM_DUTY_INT_STA, (id % 7u), 1u, 0u);
}

void ckgen_cqm_clear_jitter_int_state(paddr_t base, uint32 id)
{
    RMWREG32(base + CKGEN_CQM_JITTER_INT_STA, (id % 7u), 1u, 0u);
}

uint32 ckgen_24M_mon_get_rate(paddr_t base)
{
    uint32 low_spd_chk_ctl = base + CKGEN_LOW_SPD_CHK_CTL;
    uint32 mon_val;
    uint32 freq_mon;
    uint32 rate = 0;

    if (BIT(readl(low_spd_chk_ctl), CKGEN_LOW_SPD_CHK_CTL_MON_EN)) {
        RMWREG32(low_spd_chk_ctl, CKGEN_LOW_SPD_CHK_CTL_MON_EN, 1u, 0u);

        if (!wait_for_bit_times(low_spd_chk_ctl, CKGEN_LOW_SPD_CHK_CTL_MON_EN_STA,
                                0u, CKGEN_WAIT_TIME)) {
            return 0;
        }
    }

    /* set 32k 24m src */
    RMWREG32(low_spd_chk_ctl, CKGEN_LOW_SPD_CHK_CTL_24M_SEL, 6u, 0u);
    RMWREG32(low_spd_chk_ctl, CKGEN_LOW_SPD_CHK_CTL_32K_SEL, 6u, 0u);

    /* clear freq mon */
    RMWREG32(low_spd_chk_ctl, CKGEN_LOW_SPD_CHK_CTL_FREQ_MON_LSB, 16u, 0u);
    RMWREG32(low_spd_chk_ctl, CKGEN_LOW_SPD_CHK_CTL_MON_UPD, 1u, 0u);

    /* enable mon */
    RMWREG32(low_spd_chk_ctl, CKGEN_LOW_SPD_CHK_CTL_LOSS_DIS, 1u, 0u);
    RMWREG32(low_spd_chk_ctl, CKGEN_LOW_SPD_CHK_CTL_MON_EN, 1u, 1u);

    if (!wait_for_bit_times(low_spd_chk_ctl, CKGEN_LOW_SPD_CHK_CTL_MON_EN_STA,
                            1u, CKGEN_WAIT_TIME)) {
        goto mon_24m_rate_out;
    }

    if (!wait_for_bit_times(low_spd_chk_ctl, CKGEN_LOW_SPD_CHK_CTL_MON_UPD,
                            1u, CKGEN_WAIT_TIME)) {
        goto mon_24m_rate_out;
    }

    mon_val = readl(low_spd_chk_ctl);
    freq_mon = (mon_val >> CKGEN_LOW_SPD_CHK_CTL_FREQ_MON_LSB) & CKGEN_LOW_SPD_CHK_CTL_FREQ_MON_MASK;
    rate = freq_mon * 32000;

mon_24m_rate_out:

    RMWREG32(low_spd_chk_ctl, CKGEN_LOW_SPD_CHK_CTL_MON_EN, 1u, 0u);
    wait_for_bit_times(low_spd_chk_ctl, CKGEN_LOW_SPD_CHK_CTL_MON_EN_STA,
                       0u, CKGEN_WAIT_TIME);

    return rate;
}

#endif

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
