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
#include "e3_clk.h"
#include "e3_ckgen.h"
#include "Compiler.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

int clk_prepare(clk_node_t *clk)
{
    clk_core_t *core = clk->core;

    if (core == NULL || core->ops == NULL) {
        return -1;
    }

    if (core->ops->prepare == NULL) {
        return -1;
    }

    return core->ops->prepare(clk);
}

int clk_set_rate(clk_node_t *clk, clk_rate_t rate)
{
    clk_core_t *core = clk->core;
    clk_node_t *parent = NULL;
    int ret = -1;
    uint32 div;

    if (core == NULL) {
        return -1;
    }

    if (core->ops->select_parent != NULL) {
        core->ops->select_parent(clk, rate, &div);
    }

    if (clk->parent == NULL) {
        return -1;
    }

    parent = clk->parent;

    if (core->ops != NULL && core->ops->set_rate != NULL) {
        ret = core->ops->set_rate(clk, rate);
    } else if (parent->core->ops != NULL &&
               parent->core->ops->set_rate != NULL) {
        ret = parent->core->ops->set_rate(parent, rate);
    }

    if (ret >= 0) {
        clk->rate = rate;
    }

    return ret;
}

clk_rate_t clk_get_rate(clk_node_t *clk)
{
    clk_core_t *core = clk->core;
    clk_node_t *parent = NULL;
    clk_rate_t rate = 0;

    if (core == NULL) {
        return 0;
    }

    if (clk->parent == NULL) {
        return 0;
    }

    parent = clk->parent;

    if (core->ops != NULL && core->ops->get_rate != NULL) {
        rate = core->ops->get_rate(clk);
    } else if (parent->core->ops != NULL &&
               parent->core->ops->get_rate != NULL) {
        rate = parent->core->ops->get_rate(parent);
    }

    return rate;
}

int clk_disable(clk_node_t *clk)
{
    clk_core_t *core = clk->core;

    if (core == NULL) {
        return -1;
    }

    if (core->ops->disable == NULL) {
        return -1;
    }

    if (core->ops->lowpower_cgset == NULL) {
        return -1;
    }

    int ret = core->ops->disable(clk);
    ret = ret | core->ops->lowpower_cgset(clk, CKGEN_HIB_MODE, 0u);
    ret = ret | core->ops->lowpower_cgset(clk, CKGEN_SLP_MODE, 0u);
    return ret;
}

int clk_enable(clk_node_t *clk)
{
    clk_core_t *core = clk->core;

    if (core == NULL) {
        return -1;
    }

    if (core->ops->enable == NULL) {
        return -1;
    }

    if (core->ops->lowpower_cgset == NULL) {
        return -1;
    }

    int ret = core->ops->enable(clk);
    ret = ret | core->ops->lowpower_cgset(clk, CKGEN_HIB_MODE, 1u);
    ret = ret | core->ops->lowpower_cgset(clk, CKGEN_SLP_MODE, 1u);
    return ret;
}

bool clk_is_gated(clk_node_t *clk)
{
    clk_core_t *core = clk->core;

    if (core == NULL) {
        return FALSE;
    }

    if (core->ops->is_gated == NULL) {
        return FALSE;
    }

    return core->ops->is_gated(clk);
}

bool clk_is_locked(clk_node_t *clk)
{
    clk_core_t *core = clk->core;

    if (core == NULL) {
        return FALSE;
    }

    if (core->ops->is_locked == NULL) {
        return FALSE;
    }

    return core->ops->is_locked(clk);
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
