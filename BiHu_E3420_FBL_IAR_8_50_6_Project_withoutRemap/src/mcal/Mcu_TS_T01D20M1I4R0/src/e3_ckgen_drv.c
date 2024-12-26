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


#include <debug.h>
#include "Compiler.h"

#include "e3_clk.h"
#include "e3_ckgen.h"
#include "e3_ckgen_drv.h"

#define EXTRA_FMT   "taishan_ckgen:"

#define CKGEN_NODE(clk)     (taishan_ckgen_node_t *)clk

#define abs(x) (((int)(x) < 0) ? -(int)(x) : (int)(x))

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

static bool ckgen_drv_is_better_rate(uint32 rate, uint32 now, uint32 best)
{
    /* PRQA S 2856 2 */
    return abs(now - rate) <= abs(best - rate);
}

static int ckgen_drv_ip_prepare(clk_node_t *clk)
{
    taishan_ckgen_node_t *ckgen = CKGEN_NODE(clk);
    uint32 base = clk->core->base;
    uint32 id = clk->id;
    int ret;

    clk->parent = clk->parents[clk->mux];

    if (!clk->parent) {
        return -1;
    }

    ret = ckgen_ip_set_rate(base, id, clk->mux,
                            clk->parent->rate, clk->rate);

    if (ret == 0) {
        ckgen_ip_rs_config(base, id, &ckgen->rs_config);
    } else {
    }

    return ret;
}
#ifdef CONFIG_CLK_MONITOR
#else
static clk_rate_t ckgen_drv_ip_get_rate(clk_node_t *clk)
{
    return ckgen_ip_get_rate(clk->core->base, clk->id, clk->parent->rate);
}
#endif
static int ckgen_drv_ip_set_rate(clk_node_t *clk, clk_rate_t rate)
{
    int ret;

    clk->parent = clk->parents[clk->mux];

    if (!clk->parent) {
        return -1;
    }

    ret = ckgen_ip_set_rate(clk->core->base, clk->id, clk->mux,
                            clk->parent->rate, rate);

    if (ret < 0) {
    }

    return ret;
}

static int ckgen_drv_ip_select_parent(clk_node_t *clk, clk_rate_t rate, uint32 *best_div)
{
    clk_node_t *parent;
    clk_rate_t calc_rate, best_rate = 0;
    uint32 div;
    int best_index = -1;

    for (uint8 i = 0; i < clk->parents_num; i++) {
        parent = clk->parents[i];

        if (!parent) {
            continue;
        }

        if (parent->rate < rate) {
            continue;
        }

        div = ckgen_get_best_div(parent->rate, rate);

        if (div == UINT32_MAX || (div - 1u) > CKGEN_IP_CTL_DIV_NUM_MASK) {
            continue;
        }

        calc_rate = parent->rate / div;

        if (ckgen_drv_is_better_rate(rate, calc_rate, best_rate)) {
            best_rate = calc_rate;
            best_index = i;
        }

        /* if choose xtal24m best, no need check pll */
        if (rate == best_rate && i == 1) {
            break;
        }
    }

    if (best_index != -1) {
        clk->mux = best_index;
        clk->parent = clk->parents[best_index];
    } else {
    }

    return best_index;
}

static int ckgen_drv_core_prepare(clk_node_t *clk)
{
    taishan_ckgen_node_t *ckgen = CKGEN_NODE(clk);
    uint32 base = clk->core->base;
    int ret;

    clk->parent = clk->parents[clk->mux];

    if (!clk->parent) {
        return -1;
    }

    ret = ckgen_core_set_rate(base, clk, clk->rate);

    if (ret == 0) {
        ckgen_core_rs_config(base, clk->id, &ckgen->rs_config);
    } else {
    }

    return ret;
}
#ifdef CONFIG_CLK_MONITOR
#else
static clk_rate_t ckgen_drv_core_get_rate(clk_node_t *clk)
{
    return ckgen_core_get_rate(clk->core->base, clk->id, clk->parent->rate);
}
#endif
static int ckgen_drv_core_set_rate(clk_node_t *clk, clk_rate_t rate)
{
    int ret;

    ret = ckgen_core_set_rate(clk->core->base, clk, rate);

    if (ret < 0) {
    }

    return ret;
}

static int ckgen_drv_core_select_parent(clk_node_t *clk, clk_rate_t rate, uint32 *best_div)
{
    clk_node_t *parent;
    clk_rate_t calc_rate, best_rate = 0;
    uint32 div;
    int best_index = -1;

    for (uint8 i = 0; i < clk->parents_num; i++) {
        parent = clk->parents[i];

        if (!parent) {
            continue;
        }

        if (parent->rate < rate) {
            continue;
        }

        /* ckin4 no pre_div */
        if (i == 4) {
            div = 1;
        } else {
            div = ckgen_get_best_div(parent->rate, rate);
        }

        if (div == UINT32_MAX || (div - 1u) > CKGEN_CORE_CTL_DIV_NUM_MASK) {
            continue;
        }

        calc_rate = parent->rate / div;

        if (ckgen_drv_is_better_rate(rate, calc_rate, best_rate)) {
            best_rate = calc_rate;
            best_index = i;
            *best_div = div;
        }

        /* if choose xtal24m best, no need check pll */
        if (rate == best_rate && i == 1) {
            break;
        }
    }

    if (best_index != -1) {
        clk->mux = best_index;
        clk->parent = clk->parents[best_index];
    } else {
    }

    return best_index;
}

static int ckgen_drv_bus_prepare(clk_node_t *clk)
{
    taishan_ckgen_node_t *ckgen = CKGEN_NODE(clk);
    uint32 base = clk->core->base;
    int ret;

    /* if pll not ready, means this is the first config after reset,
     * don't change mux when pll is not ready. */
    if (clk->parents_num == 5 && !clk_is_locked(clk->parents[4])) {
        return -1;
    }

    clk->parent = clk->parents[clk->mux];

    if (!clk->parent) {
        return -1;
    }

    ret = ckgen_bus_set_rate(base, clk->id, clk->mux,
                             clk->parent->rate, clk->rate);

    if (ret == 0) {
        ckgen_bus_rs_config(base, clk->id, &ckgen->rs_config);
    } else {
    }

    return ret;
}
#ifdef CONFIG_CLK_MONITOR
#else
static clk_rate_t ckgen_drv_bus_get_rate(clk_node_t *clk)
{
    return ckgen_bus_get_rate(clk->core->base, clk->id, clk->parent->rate);
}
#endif
static int ckgen_drv_bus_set_rate(clk_node_t *clk, clk_rate_t rate)
{
    int ret;

    clk->parent = clk->parents[clk->mux];

    if (!clk->parent) {
        return -1;
    }

    ret = ckgen_bus_set_rate(clk->core->base, clk->id, clk->mux,
                             clk->parent->rate, rate);

    if (ret < 0) {
    }

    return ret;
}

static int ckgen_drv_bus_select_parent(clk_node_t *clk, clk_rate_t rate, uint32 *best_div)
{
    clk_node_t *parent;
    clk_rate_t calc_rate, best_rate = 0;
    uint32 div;
    int best_index = -1;

    for (uint8 i = 0; i < clk->parents_num; i++) {
        parent = clk->parents[i];

        if (!parent) {
            continue;
        }

        if (parent->rate < rate) {
            continue;
        }

        div = ckgen_get_best_div(parent->rate, rate);

        if (div == UINT32_MAX || (div - 1u) > CKGEN_BUS_SYNC_CTL_DIV_MASK) {
            continue;
        }

        calc_rate = parent->rate / div;

        if (ckgen_drv_is_better_rate(rate, calc_rate, best_rate)) {
            best_rate = calc_rate;
            best_index = i;
        }
    }

    if (best_index != -1) {
        clk->mux = best_index;
        clk->parent = clk->parents[best_index];
    } else {
    }

    return best_index;
}
#ifdef MCU_CKGEN_RESERVED_FUNCs
static int ckgen_drv_gating_prepare(clk_node_t *clk)
{
    taishan_cg_node_t *cg = (taishan_cg_node_t *)clk;
    uint32 base = clk->core->base;
    uint32 id = clk->id;
    uint32 cg_type;
    uint8 cg_state;

    cg_type = CKGEN_CG_ID_TYPE(id);
    cg_state = CKGEN_CG_STATE(cg->run_mode_en,
                              cg->hib_mode_en,
                              cg->slp_mode_en);

    if (cg_type == CKGEN_CG_ID_TYPE_PLL_TYPE) {
        return ckgen_pll_set_gating_state(base, id, cg_state);
    } else if (cg_type == CKGEN_CG_ID_TYPE_XTAL_TYPE) {
        return ckgen_xtal_set_gating_state(base, cg_state);
    } else {
        return ckgen_xcg_set_gating_state(base, id, cg_state);
    }
}
#endif

static int ckgen_drv_lowpower_cgset(clk_node_t *clk, uint8 lp_mode, uint32 val)
{
    uint32 base = clk->core->base;
    uint32 id = clk->id;
    uint32 cg_type = CKGEN_CG_ID_TYPE(id);

    if (cg_type == CKGEN_CG_ID_TYPE_PLL_TYPE) {
        return ckgen_pll_set_gating_by_mode(base, id, lp_mode, val);
    } else if (cg_type == CKGEN_CG_ID_TYPE_XTAL_TYPE) {
        return ckgen_xtal_set_gating_by_mode(base, lp_mode, val);
    } else {
        return ckgen_xcg_set_gating_by_mode(base, id, lp_mode, val);
    }
}
static int ckgen_drv_gating_enable(clk_node_t *clk)
{
    uint32 base = clk->core->base;
    uint32 id = clk->id;
    uint32 cg_type = CKGEN_CG_ID_TYPE(id);

    if (cg_type == CKGEN_CG_ID_TYPE_PLL_TYPE) {
        return ckgen_pll_set_gating_by_mode(base, id, CKGEN_RUN_MODE, 1u);
    } else if (cg_type == CKGEN_CG_ID_TYPE_XTAL_TYPE) {
        return ckgen_xtal_set_gating_by_mode(base, CKGEN_RUN_MODE, 1u);
    } else {
        return ckgen_xcg_set_gating_by_mode(base, id, CKGEN_RUN_MODE, 1u);
    }
}

static int ckgen_drv_gating_disable(clk_node_t *clk)
{
    uint32 base = clk->core->base;
    uint32 id = clk->id;
    uint32 cg_type = CKGEN_CG_ID_TYPE(id);

    if (cg_type == CKGEN_CG_ID_TYPE_PLL_TYPE) {
        return ckgen_pll_set_gating_by_mode(base, id, CKGEN_RUN_MODE, 0u);
    } else if (cg_type == CKGEN_CG_ID_TYPE_XTAL_TYPE) {
        return ckgen_xtal_set_gating_by_mode(base, CKGEN_RUN_MODE, 0u);
    } else {
        return ckgen_xcg_set_gating_by_mode(base, id, CKGEN_RUN_MODE, 0u);
    }
}
#ifdef CONFIG_CLK_MONITOR
#else
static bool ckgen_drv_gating_is_gated(clk_node_t *clk)
{
    uint32 base = clk->core->base;
    uint32 id = clk->id;
    uint32 cg_type = CKGEN_CG_ID_TYPE(id);

    if (cg_type < CKGEN_CG_ID_TYPE_PLL_TYPE) {
        return ckgen_xcg_is_gated(base, id);
    }

    return FALSE;
}
#endif
#ifdef CONFIG_CLK_MONITOR
static clk_rate_t ckgen_drv_ip_mon_get_rate(clk_node_t *clk)
{
    return ckgen_ip_mon_get_rate(clk->core->base, clk->id);
}

static clk_rate_t ckgen_drv_bus_mon_get_rate(clk_node_t *clk)
{
    return ckgen_bus_mon_get_rate(clk->core->base, clk->id);
}

static clk_rate_t ckgen_drv_core_mon_get_rate(clk_node_t *clk)
{
    return ckgen_core_mon_get_rate(clk->core->base, clk->id);
}

static bool ckgen_drv_mon_xcg_is_gated(uint32 base, uint32 id)
{
    uint32 state;

    ckgen_xcg_amon_enable(base, id, TRUE);

    state = ckgen_xcg_get_amon_state(base, id);

    ckgen_xcg_amon_enable(base, id, FALSE);

    return state ? FALSE : TRUE;
}

static bool ckgen_drv_mon_pll_is_gated(uint32 base, uint32 id)
{
    uint32 state;

    ckgen_pll_mon_enable(base, id, 0xffff);

    state = ckgen_pll_mon_get_state(base, id);

    ckgen_pll_mon_disable(base, id);

    return state ? FALSE : TRUE;
}

static bool ckgen_drv_mon_xtal_is_gated(uint32 base)
{
    uint32 state;

    ckgen_xtal_mon_enable(base, 0xffff);

    state = ckgen_xtal_mon_get_xtal_state(base);

    ckgen_xtal_mon_disable(base);

    return state ? FALSE : TRUE;
}

static bool ckgen_drv_mon_gating_is_gated(clk_node_t *clk)
{
    uint32 base = clk->core->base;
    uint32 id = clk->id;
    uint32 cg_type = CKGEN_CG_ID_TYPE(id);

    if (cg_type == CKGEN_CG_ID_TYPE_PLL_TYPE) {
        return ckgen_drv_mon_pll_is_gated(base, id);
    } else if (cg_type == CKGEN_CG_ID_TYPE_XTAL_TYPE) {
        return ckgen_drv_mon_xtal_is_gated(base);
    } else {
        return ckgen_drv_mon_xcg_is_gated(base, id);
    }
}

int ckgen_clock_to_pad(clk_node_t *ckgen)
{
    if (ckgen->core->ops == &ckgen_ip_ops) {
        ckgen_dbg_mon_ip_select(ckgen->core->base, ckgen->id);
    } else if (ckgen->core->ops == &ckgen_core_ops) {
        ckgen_dbg_mon_core_select(ckgen->core->base, ckgen->id);
    } else {
        ckgen_dbg_mon_bus_select(ckgen->core->base, ckgen->id);
    }

    return 0;
}
#endif

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

struct clk_ops ckgen_ip_ops = {
    .prepare = ckgen_drv_ip_prepare,
#ifdef CONFIG_CLK_MONITOR
    .get_rate = ckgen_drv_ip_mon_get_rate,
#else
    .get_rate = ckgen_drv_ip_get_rate,
#endif
    .set_rate = ckgen_drv_ip_set_rate,
    .select_parent = ckgen_drv_ip_select_parent,
};

struct clk_ops ckgen_bus_ops = {
    .prepare = ckgen_drv_bus_prepare,
#ifdef CONFIG_CLK_MONITOR
    .get_rate = ckgen_drv_bus_mon_get_rate,
#else
    .get_rate = ckgen_drv_bus_get_rate,
#endif
    .set_rate = ckgen_drv_bus_set_rate,
    .select_parent = ckgen_drv_bus_select_parent,
};

struct clk_ops ckgen_core_ops = {
    .prepare = ckgen_drv_core_prepare,
#ifdef CONFIG_CLK_MONITOR
    .get_rate = ckgen_drv_core_mon_get_rate,
#else
    .get_rate = ckgen_drv_core_get_rate,
#endif
    .set_rate = ckgen_drv_core_set_rate,
    .select_parent = ckgen_drv_core_select_parent,
};

struct clk_ops ckgen_gating_ops = {
#ifdef MCU_CKGEN_RESERVED_FUNCs
    .prepare = ckgen_drv_gating_prepare,
#endif
    .enable = ckgen_drv_gating_enable,
    .disable = ckgen_drv_gating_disable,
#ifdef CONFIG_CLK_MONITOR
    .is_gated = ckgen_drv_mon_gating_is_gated,
#else
    .is_gated = ckgen_drv_gating_is_gated,
#endif
    .lowpower_cgset = ckgen_drv_lowpower_cgset,
};

#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"
