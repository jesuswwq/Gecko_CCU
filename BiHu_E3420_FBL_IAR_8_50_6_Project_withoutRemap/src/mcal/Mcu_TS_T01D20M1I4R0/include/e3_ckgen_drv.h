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

#ifndef E3_CKGEN_DRV_H_
#define E3_CKGEN_DRV_H_

#include "e3_clk.h"
#include "e3_ckgen.h"
#include "e3_ckgen_drv.h"

typedef struct taishan_ckgen_node {
    clk_node_t clk_node;
    ckgen_rs_config_t rs_config;
} taishan_ckgen_node_t;

typedef struct taishan_cg_node {
    clk_node_t clk_node;
    ckgen_rs_config_t rs_config;
    bool run_mode_en;
    bool slp_mode_en;
    bool hib_mode_en;
} taishan_cg_node_t;

extern struct clk_ops ckgen_ip_ops;

extern struct clk_ops ckgen_bus_ops;

extern struct clk_ops ckgen_core_ops;

extern struct clk_ops ckgen_gating_ops;
#ifdef CONFIG_CLK_MONITOR
int ckgen_clock_to_pad(clk_node_t *ckgen);
#endif

#define CLK_NODE(node) &(node.clk_node)

#endif /* E3_CKGEN_DRV_H_ */
