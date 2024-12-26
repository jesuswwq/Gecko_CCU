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

#include "Platform_Types.h"
#include "e3_clk.h"
#include "e3_pll_drv.h"
#include "e3_pll.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

static int pll_drv_enable(clk_node_t *clk)
{
    return pll_enable(clk->core->base, clk->id);
}

static int pll_drv_disable(clk_node_t *clk)
{
    return pll_disable(clk->core->base, clk->id);
}

static int pll_drv_prepare(clk_node_t *clk)
{
    return pll_prepare(clk->core->base, clk->id,
                       clk->parent->rate, clk->rate);
}

static clk_rate_t pll_drv_get_rate(clk_node_t *clk)
{
    return pll_get_rate(clk->core->base, clk->id, clk->parent->rate);
}

static int pll_drv_set_rate(clk_node_t *clk, clk_rate_t rate)
{
    return pll_set_rate(clk->core->base, clk->id,
                        clk->parent->rate, rate);
}

static bool pll_drv_is_locked(clk_node_t *clk)
{
    return pll_is_locked(clk->core->base);
}

int config_pll_spread(const pll_spread_config_t *pll_config)
{
    clk_node_t *node = (clk_node_t *)pll_config->pll_node;

    pll_set_ssc_amplitude(node->core->base, pll_config->amplitude);
    pll_set_ssc_frequency(node->core->base, pll_config->frequency);
    return pll_set_ssc_mode(node->core->base, pll_config->mode);
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

struct clk_ops taishan_pll_ops = {
    .prepare = pll_drv_prepare,
    .enable = pll_drv_enable,
    .disable = pll_drv_disable,
    .get_rate = pll_drv_get_rate,
    .set_rate = pll_drv_set_rate,
    .is_locked = pll_drv_is_locked,
};

#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"
