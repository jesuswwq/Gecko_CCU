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

#ifndef E3_CLK_H_
#define E3_CLK_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef uint32 clk_rate_t;

typedef struct clk_ops clk_ops_t;

/**
 * @brief Clk core type, clock core may be a clock source or frequency divider.
 */
typedef struct clk_core {
    uint32 type;
    paddr_t base;
    struct clk_ops *ops;
    void *private;
} clk_core_t;

/**
 * @brief Clk node type.
 */
typedef struct clk_node {
    struct clk_core *core;
    uint32 id;
    clk_rate_t rate;
    uint8 parents_num;
    uint8 mux;
    struct clk_node *parent;
    struct clk_node *parents[8];
} clk_node_t;

/**
 * @brief Clk core operation interface type.
 */
struct clk_ops {
    int (*prepare)(clk_node_t *clk);
    int (*enable)(clk_node_t *clk);
    int (*disable)(clk_node_t *clk);
    bool (*is_gated)(clk_node_t *clk);
    clk_rate_t (*get_rate)(clk_node_t *clk);
    int (*set_rate)(clk_node_t *clk, clk_rate_t rate);
    int (*select_parent)(clk_node_t *clk, clk_rate_t rate, uint32 *best_div);
    /* only for pll */
    bool (*is_locked)(clk_node_t *clk);
    int (*lowpower_cgset)(clk_node_t *clk, uint8 lp_mode, uint32 val);
};

/**
 * @brief Clk prepare interface.
 * @details Used for generate clock tree's node by platform or borad code,
 *          other code like app or driver should not use this ops.
 * @param[in] clk Clk node data.
 * @return int
 * @retval 0: sucess
 * @retval other: failed
 * @note The api not find the most suitable parent clock node,
 *       so if user specify a improper parent clock source,
 *       the clock actual frequency may has a big bias to target frequency.
 *       If you not consider clock divisible, and need high accuracy clock
 *       frequency, you can get the actual frequency use clk_get_rate api.
 * @par Example
 * @code{c}
 *   // Clk_core_t data.
 *   clk_core_t g_pll2 = {
 *       .base = APB_PLL2_BASE,
 *       .ops = &sc_pfpll_ops,
 *   };
 *
 *   // Parent clock node.
 *   clk_node_t g_ref_24m = {
 *       .core = NULL,
 *       .config = {
 *           .id = 0,
 *           .rate = 24000000u,
 *           // Not need clock source mux.
 *           .mux = UINT32_MAX,
 *       },
 *       .parent = NULL,
 *   };
 *
 *   // clock node to be set
 *   clk_node_t g_pll2_vco = {
 *       .core = &g_pll_2,
 *       .config = {
 *           .id = SC_PFPLL_ID_NUM_VCO,
 *           .rate = 1599999999u,
 *           .mux = 0,
 *       },
 *       .parent = &g_ref_24m,
 *   };
 *
 *   clk_prepare(&g_pll2_vco);
 *
 *   // You can get the actual rate like this.
 *   clk_rate_t rate = clk_get_rate(g_pll2_vco_node);
 * @endcode
 */
int clk_prepare(clk_node_t *clk);

/**
 * @brief Clk set rate interface, set one clk node rate.
 * @param[in] clk Clk node data.
 * @param[in] rate The clk rate to be set.
 * @return int
 * @retval 0: sucess
 * @retval other: failed
 * @note This api not set the parent clock node, but will use the parent clock
 *       node's rate to calculate divider's param.
 * @warning Some clk node may be not support clock_set_rate api when it has child node.
 *          This api always used for clock tree leaf node.
 * @par Example
 * @code{c}
 *   // About clock_node param, reference clk_prepare function example.
 *   clk_set_rate(&g_ckgen_saf_ip_timer1, 398000000u);
 *
 *   // You can get the actual rate like this.
 *   clk_rate_t rate = clk_get_rate(g_ckgen_saf_ip_timer1_node);
 * @endcode
 */
int clk_set_rate(clk_node_t *clk, clk_rate_t rate);

/**
 * @brief Clk get rate interface, get one clk node rate.
 * @param[in] clk Clk node data.
 * @return clk_rate_t Clk rate value.
 */
clk_rate_t clk_get_rate(clk_node_t *clk);

/**
 * @brief Clk enable interface, enable one clk node if it has clock gate capacity.
 * @param[in] clk Clk node data.
 * @return int
 * @retval 0: sucess
 * @retval other: failed
 * @par Example
 * @code{c}
 *   // About clock_node param, reference clk_prepare function example.
 *   clk_enable(g_ckgen_saf_ip_timer1_node);
 * @endcode
 */
int clk_enable(clk_node_t *clk);

/**
 * @brief Clk disable interface, disable one clk node if it has clock gate capacity.
 * @param[in] clk Clk node data.
 * @warning Some clk node may be not support clock_set_rate api when it has child node.
 *          This api always used for clock tree leaf node.
 *          node's rate to calculate divider's param.
 * @par Example
 * @code{c}
 *   // About clock_node param, reference clk_prepare function example.
 *   clk_disable(g_ckgen_saf_ip_timer1_node);
 * @endcode
 */
int clk_disable(clk_node_t *clk);

/**
 * @brief Clk check gated interface.
 * @param[in] clk Clk node data.
 * @par Example
 * @code{c}
 *   // About clock_node param, reference clk_prepare function example.
 *   clk_is_gated(g_ckgen_saf_ip_timer1_node);
 * @endcode
 */
bool clk_is_gated(clk_node_t *clk);

/**
 * @brief pll check locked interface.
 * @param[in] clk Clk node data.
 * @par Example
 * @code{c}
 *   // About clock_node param, reference clk_prepare function example.
 *   clk_is_gated(g_pll2_vco_node);
 * @endcode
 */
bool clk_is_locked(clk_node_t *clk);

#ifdef __cplusplus
}
#endif
#endif /* CLK_H_ */
