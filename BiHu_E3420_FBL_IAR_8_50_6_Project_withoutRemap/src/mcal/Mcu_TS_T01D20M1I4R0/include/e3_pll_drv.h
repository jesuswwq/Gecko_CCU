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

#ifndef E3_PLL_DRV_H_
#define E3_PLL_DRV_H_

#include "e3_clk.h"
#include "e3_pll.h"

typedef struct pll_spread_config {
    const clk_node_t *pll_node;
    sdrv_ckgen_ssc_amplitude_e amplitude;
    sdrv_ckgen_ssc_freq_e frequency;
    sdrv_ckgen_ssc_mode_e mode;
} pll_spread_config_t;

typedef struct taishan_pll_node {
    clk_node_t clk_node;
} taishan_pll_node_t;

extern struct clk_ops taishan_pll_ops;

int config_pll_spread(const pll_spread_config_t *pll_config);

#endif /* E3_PLL_DRV_H_ */
