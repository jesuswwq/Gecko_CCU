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
 * @file  Mcu_ClkCfg.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Mcu Driver.
 * @date 2024-01-08 18:27:14
*/

#ifdef __cplusplus
extern "C" {
#endif

#include <__regs_base.h>
#include "Std_Types.h"
#include "e3_clk.h"
#include "e3_clock_cfg_nd.h"
#include "e3_ckgen_drv.h"

#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"



static clk_core_t g_pll1_core = {
    .base = APB_PLL1_BASE,
    .ops = &taishan_pll_ops,
};

static clk_core_t g_pll2_core = {
    .base = APB_PLL2_BASE,
    .ops = &taishan_pll_ops,
};

static clk_core_t g_pll3_core = {
    .base = APB_PLL3_BASE,
    .ops = &taishan_pll_ops,
};

static clk_core_t g_sf_bus_core = {
    .base = APB_CKGEN_SF_BASE,
    .ops = &ckgen_bus_ops,
};

static clk_core_t g_sf_core_core = {
    .base = APB_CKGEN_SF_BASE,
    .ops = &ckgen_core_ops,
};

static clk_core_t g_sf_ip_core = {
    .base = APB_CKGEN_SF_BASE,
    .ops = &ckgen_ip_ops,
};

static clk_core_t g_sf_gating_core = {
    .base = APB_CKGEN_SF_BASE,
    .ops = &ckgen_gating_ops,
};

static clk_core_t g_pll4_core = {
    .base = APB_PLL4_BASE,
    .ops = &taishan_pll_ops,
};

static clk_core_t g_pll5_core = {
    .base = APB_PLL5_BASE,
    .ops = &taishan_pll_ops,
};

static clk_core_t g_pll_lvds_core = {
    .base = APB_PLL_LVDS_BASE,
    .ops = &taishan_pll_ops,
};

static clk_core_t g_ap_bus_core = {
    .base = APB_CKGEN_AP_BASE,
    .ops = &ckgen_bus_ops,
};

static clk_core_t g_ap_ip_core = {
    .base = APB_CKGEN_AP_BASE,
    .ops = &ckgen_ip_ops,
};

static clk_core_t g_ap_gating_core = {
    .base = APB_CKGEN_AP_BASE,
    .ops = &ckgen_gating_ops,
};

taishan_pll_node_t g_rc_24m = {
    .clk_node = {
        .core = NULL,
        .id = 0x0,
        .rate = 24000000,
        .parent = NULL,
    },
};

taishan_pll_node_t g_fs_24m = {
    .clk_node = {
        .core = NULL,
        .id = 0x0,
        .rate = 24000000,
        .parent = NULL,
    },
};

taishan_ckgen_node_t g_ckgen_bus_cr5_sf_div_root_preset = {
    .clk_node = {
        .core = &g_sf_bus_core,
        .id = 0x1000000,
        .rate = 24000000,
        .mux = 1,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_cr5_sp_div_root_preset = {
    .clk_node = {
        .core = &g_sf_bus_core,
        .id = 0x1000001,
        .rate = 24000000,
        .mux = 1,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_sf_test_div_root_preset = {
    .clk_node = {
        .core = &g_sf_bus_core,
        .id = 0x1000002,
        .rate = 24000000,
        .mux = 1,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll2_root),
        .parents[4] = CLK_NODE(g_pll3_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_ap_bus_div_root_preset = {
    .clk_node = {
        .core = &g_ap_bus_core,
        .id = 0x1000000,
        .rate = 24000000,
        .mux = 1,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll_lvds_ckgen),
        .parents[4] = CLK_NODE(g_pll5_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_disp_bus_div_root_preset = {
    .clk_node = {
        .core = &g_ap_bus_core,
        .id = 0x1000001,
        .rate = 24000000,
        .mux = 1,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll_lvds_ckgen),
        .parents[4] = CLK_NODE(g_pll5_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_seip_div_root_preset = {
    .clk_node = {
        .core = &g_ap_bus_core,
        .id = 0x1000002,
        .rate = 24000000,
        .mux = 1,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll_lvds_ckgen),
        .parents[4] = CLK_NODE(g_pll5_root),
    },
};

taishan_pll_node_t g_pll1_root = {
    .clk_node = {
        .core = &g_pll1_core,
        .id = 0x0,
        .rate = 500000000,
        .parent = CLK_NODE(g_rc_24m),
    },
};

taishan_pll_node_t g_pll2_root = {
    .clk_node = {
        .core = &g_pll2_core,
        .id = 0x0,
        .rate = 600000000,
        .parent = CLK_NODE(g_rc_24m),
    },
};

taishan_pll_node_t g_pll3_root = {
    .clk_node = {
        .core = &g_pll3_core,
        .id = 0x0,
        .rate = 667000000,
        .parent = CLK_NODE(g_rc_24m),
    },
};

taishan_ckgen_node_t g_ckgen_bus_cr5_sf_div_root = {
    .clk_node = {
        .core = &g_sf_bus_core,
        .id = 0x1000000,
        .rate = 600000000,
        .mux = 4,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};
taishan_ckgen_node_t g_ckgen_bus_cr5_sf_div_m = {
    .clk_node = {
        .core = &g_sf_bus_core,
        .id = 0x2000000,
        .rate = 600000000,
        .mux = 0,
        .parents_num = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_cr5_sf_div_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_cr5_sf_div_n = {
    .clk_node = {
        .core = &g_sf_bus_core,
        .id = 0x3000000,
        .rate = 300000000,
        .mux = 0,
        .parents_num = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_cr5_sf_div_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_cr5_sf_div_p = {
    .clk_node = {
        .core = &g_sf_bus_core,
        .id = 0x4000000,
        .rate = 150000000,
        .mux = 0,
        .parents_num = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_cr5_sf_div_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_cr5_sf_div_q = {
    .clk_node = {
        .core = &g_sf_bus_core,
        .id = 0x5000000,
        .rate = 150000000,
        .mux = 0,
        .parents_num = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_cr5_sf_div_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_cr5_sf_root = {
    .clk_node = {
        .core = &g_sf_bus_core,
        .id = 0x0,
        .rate = 600000000,
        .mux = 0,
        .parents_num = 2,
        .parents[0] = CLK_NODE(g_ckgen_bus_cr5_sf_div_m),
        .parents[1] = CLK_NODE(g_pll2_root),
    },
};
taishan_ckgen_node_t g_ckgen_bus_cr5_sp_div_root = {
    .clk_node = {
        .core = &g_sf_bus_core,
        .id = 0x1000001,
        .rate = 600000000,
        .mux = 4,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_cr5_sp_div_m = {
    .clk_node = {
        .core = &g_sf_bus_core,
        .id = 0x2000001,
        .rate = 600000000,
        .mux = 0,
        .parents_num = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_cr5_sp_div_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_cr5_sp_div_n = {
    .clk_node = {
        .core = &g_sf_bus_core,
        .id = 0x3000001,
        .rate = 300000000,
        .mux = 0,
        .parents_num = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_cr5_sp_div_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_cr5_sp_div_p = {
    .clk_node = {
        .core = &g_sf_bus_core,
        .id = 0x4000001,
        .rate = 150000000,
        .mux = 0,
        .parents_num = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_cr5_sp_div_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_cr5_sp_div_q = {
    .clk_node = {
        .core = &g_sf_bus_core,
        .id = 0x5000001,
        .rate = 150000000,
        .mux = 0,
        .parents_num = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_cr5_sp_div_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_cr5_sp_root = {
    .clk_node = {
        .core = &g_sf_bus_core,
        .id = 0x1,
        .rate = 600000000,
        .mux = 0,
        .parents_num = 2,
        .parents[0] = CLK_NODE(g_ckgen_bus_cr5_sp_div_m),
        .parents[1] = CLK_NODE(g_pll2_root),
    },
};
taishan_ckgen_node_t g_ckgen_core_cr5_sx_preset = {
    .clk_node = {
        .core = &g_sf_core_core,
        .id = 0x0,
        .rate = 24000000,
        .mux = 1,
        .parents_num = 2,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
    },
};
taishan_ckgen_node_t g_ckgen_core_cr5_sx = {
    .clk_node = {
        .core = &g_sf_core_core,
        .id = 0x0,
        .rate = 600000000,
        .mux = 4,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_i2c_sf_1_to_4 = {
    .clk_node = {
        .core = &g_sf_ip_core,
        .id = 0x0,
        .rate = 133200000,
        .mux = 3,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_i2c_sf_5_to_8 = {
    .clk_node = {
        .core = &g_sf_ip_core,
        .id = 0x1,
        .rate = 133200000,
        .mux = 3,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_spi_sf_1_to_4 = {
    .clk_node = {
        .core = &g_sf_ip_core,
        .id = 0x2,
        .rate = 100000000,
        .mux = 2,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_spi_sf_5_to_8 = {
    .clk_node = {
        .core = &g_sf_ip_core,
        .id = 0x3,
        .rate = 100000000,
        .mux = 2,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_uart_sf_1_to_8 = {
    .clk_node = {
        .core = &g_sf_ip_core,
        .id = 0x4,
        .rate = 83380000,
        .mux = 3,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_uart_sf_9_to_16 = {
    .clk_node = {
        .core = &g_sf_ip_core,
        .id = 0x5,
        .rate = 83380000,
        .mux = 3,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_enet1_tx = {
    .clk_node = {
        .core = &g_sf_ip_core,
        .id = 0x6,
        .rate = 250000000,
        .mux = 4,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll2_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll1_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_enet1_rmii = {
    .clk_node = {
        .core = &g_sf_ip_core,
        .id = 0x7,
        .rate = 50000000,
        .mux = 4,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll2_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll1_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_enet1_phy_ref = {
    .clk_node = {
        .core = &g_sf_ip_core,
        .id = 0x8,
        .rate = 125000000,
        .mux = 4,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll2_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll1_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_enet1_timer_sec = {
    .clk_node = {
        .core = &g_sf_ip_core,
        .id = 0x9,
        .rate = 250000000,
        .mux = 4,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll2_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll1_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_enet2_tx = {
    .clk_node = {
        .core = &g_sf_ip_core,
        .id = 0xa,
        .rate = 250000000,
        .mux = 4,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll2_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll1_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_enet2_rmii = {
    .clk_node = {
        .core = &g_sf_ip_core,
        .id = 0xb,
        .rate = 50000000,
        .mux = 4,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll2_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll1_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_enet2_phy_ref = {
    .clk_node = {
        .core = &g_sf_ip_core,
        .id = 0xc,
        .rate = 125000000,
        .mux = 4,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll2_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll1_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_xspi1a = {
    .clk_node = {
        .core = &g_sf_ip_core,
        .id = 0xd,
        .rate = 200000000,
        .mux = 4,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_xspi1b = {
    .clk_node = {
        .core = &g_sf_ip_core,
        .id = 0xe,
        .rate = 200000000,
        .mux = 4,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_xspi2a = {
    .clk_node = {
        .core = &g_sf_ip_core,
        .id = 0xf,
        .rate = 333500000,
        .mux = 3,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_xspi2b = {
    .clk_node = {
        .core = &g_sf_ip_core,
        .id = 0x10,
        .rate = 333500000,
        .mux = 3,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_xtrg = {
    .clk_node = {
        .core = &g_sf_ip_core,
        .id = 0x11,
        .rate = 250000000,
        .mux = 2,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_etmr1 = {
    .clk_node = {
        .core = &g_sf_ip_core,
        .id = 0x12,
        .rate = 250000000,
        .mux = 2,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_etmr2 = {
    .clk_node = {
        .core = &g_sf_ip_core,
        .id = 0x13,
        .rate = 250000000,
        .mux = 2,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_etmr3 = {
    .clk_node = {
        .core = &g_sf_ip_core,
        .id = 0x14,
        .rate = 250000000,
        .mux = 2,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_etmr4 = {
    .clk_node = {
        .core = &g_sf_ip_core,
        .id = 0x15,
        .rate = 250000000,
        .mux = 2,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_epwm1 = {
    .clk_node = {
        .core = &g_sf_ip_core,
        .id = 0x16,
        .rate = 250000000,
        .mux = 2,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_epwm2 = {
    .clk_node = {
        .core = &g_sf_ip_core,
        .id = 0x17,
        .rate = 250000000,
        .mux = 2,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_epwm3 = {
    .clk_node = {
        .core = &g_sf_ip_core,
        .id = 0x18,
        .rate = 250000000,
        .mux = 2,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_epwm4 = {
    .clk_node = {
        .core = &g_sf_ip_core,
        .id = 0x19,
        .rate = 250000000,
        .mux = 2,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_can = {
    .clk_node = {
        .core = &g_sf_ip_core,
        .id = 0x1a,
        .rate = 40000000,
        .mux = 4,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_adc1 = {
    .clk_node = {
        .core = &g_sf_ip_core,
        .id = 0x1b,
        .rate = 166670000,
        .mux = 2,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_adc2 = {
    .clk_node = {
        .core = &g_sf_ip_core,
        .id = 0x1c,
        .rate = 166670000,
        .mux = 2,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_adc3 = {
    .clk_node = {
        .core = &g_sf_ip_core,
        .id = 0x1d,
        .rate = 166670000,
        .mux = 2,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_acmp = {
    .clk_node = {
        .core = &g_sf_ip_core,
        .id = 0x1e,
        .rate = 166670000,
        .mux = 2,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_flexray = {
    .clk_node = {
        .core = &g_sf_ip_core,
        .id = 0x1f,
        .rate = 40000000,
        .mux = 2,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll2_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll1_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_ioc = {
    .clk_node = {
        .core = &g_sf_ip_core,
        .id = 0x20,
        .rate = 50000000,
        .mux = 4,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_pt_sns_sf = {
    .clk_node = {
        .core = &g_sf_ip_core,
        .id = 0x21,
        .rate = 100000,
        .mux = 1,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_sf_test_div_root = {
    .clk_node = {
        .core = &g_sf_bus_core,
        .id = 0x1000002,
        .rate = 500000000,
        .mux = 2,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll2_root),
        .parents[4] = CLK_NODE(g_pll3_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_sf_test_div_m = {
    .clk_node = {
        .core = &g_sf_bus_core,
        .id = 0x2000002,
        .rate = 100000000,
        .mux = 0,
        .parents_num = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_sf_test_div_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_sf_test_div_n = {
    .clk_node = {
        .core = &g_sf_bus_core,
        .id = 0x3000002,
        .rate = 83380000,
        .mux = 0,
        .parents_num = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_sf_test_div_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_sf_test_div_p = {
    .clk_node = {
        .core = &g_sf_bus_core,
        .id = 0x4000002,
        .rate = 25000000,
        .mux = 0,
        .parents_num = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_sf_test_div_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_sf_test_div_q = {
    .clk_node = {
        .core = &g_sf_bus_core,
        .id = 0x5000002,
        .rate = 25000000,
        .mux = 0,
        .parents_num = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_sf_test_div_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_sf_test_root = {
    .clk_node = {
        .core = &g_sf_bus_core,
        .id = 0x2,
        .rate = 100000000,
        .mux = 0,
        .parents_num = 2,
        .parents[0] = CLK_NODE(g_ckgen_bus_sf_test_div_m),
        .parents[1] = CLK_NODE(g_pll3_root),
    },
};

taishan_pll_node_t g_pll4_root = {
    .clk_node = {
        .core = &g_pll4_core,
        .id = 0x0,
        .rate = 600000000,
        .parent = CLK_NODE(g_rc_24m),
    },
};

taishan_pll_node_t g_pll5_root = {
    .clk_node = {
        .core = &g_pll5_core,
        .id = 0x0,
        .rate = 786432000,
        .parent = CLK_NODE(g_rc_24m),
    },
};

taishan_pll_node_t g_pll_lvds_root = {
    .clk_node = {
        .core = &g_pll_lvds_core,
        .id = 0x0,
        .rate = 1039500000,
        .parent = CLK_NODE(g_rc_24m),
    },
};

taishan_pll_node_t g_pll_lvds_nodiv = {
    .clk_node = {
        .core = &g_pll_lvds_core,
        .id = 0x1,
        .rate = 1039500000,
        .parent = CLK_NODE(g_pll_lvds_root),
    },
};

taishan_pll_node_t g_pll_lvds_div2 = {
    .clk_node = {
        .core = &g_pll_lvds_core,
        .id = 0x2,
        .rate = 519750000,
        .parent = CLK_NODE(g_pll_lvds_root),
    },
};

taishan_pll_node_t g_pll_lvds_div7 = {
    .clk_node = {
        .core = &g_pll_lvds_core,
        .id = 0x3,
        .rate = 74250000,
        .parent = CLK_NODE(g_pll_lvds_div2),
    },
};

taishan_pll_node_t g_pll_lvds_ckgen = {
    .clk_node = {
        .core = &g_pll_lvds_core,
        .id = 0x4,
        .rate = 519750000,
        .parent = CLK_NODE(g_pll_lvds_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_ap_bus_div_root = {
    .clk_node = {
        .core = &g_ap_bus_core,
        .id = 0x1000000,
        .rate = 300000000,
        .mux = 2,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll_lvds_ckgen),
        .parents[4] = CLK_NODE(g_pll5_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_ap_bus_div_m = {
    .clk_node = {
        .core = &g_ap_bus_core,
        .id = 0x2000000,
        .rate = 300000000,
        .mux = 0,
        .parents_num = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_ap_bus_div_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_ap_bus_div_n = {
    .clk_node = {
        .core = &g_ap_bus_core,
        .id = 0x3000000,
        .rate = 300000000,
        .mux = 0,
        .parents_num = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_ap_bus_div_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_ap_bus_div_p = {
    .clk_node = {
        .core = &g_ap_bus_core,
        .id = 0x4000000,
        .rate = 150000000,
        .mux = 0,
        .parents_num = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_ap_bus_div_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_ap_bus_div_q = {
    .clk_node = {
        .core = &g_ap_bus_core,
        .id = 0x5000000,
        .rate = 150000000,
        .mux = 0,
        .parents_num = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_ap_bus_div_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_ap_bus_root = {
    .clk_node = {
        .core = &g_ap_bus_core,
        .id = 0x0,
        .rate = 300000000,
        .mux = 0,
        .parents_num = 2,
        .parents[0] = CLK_NODE(g_ckgen_bus_ap_bus_div_m),
        .parents[1] = CLK_NODE(g_pll5_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_disp_bus_div_root = {
    .clk_node = {
        .core = &g_ap_bus_core,
        .id = 0x1000001,
        .rate = 300000000,
        .mux = 2,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll_lvds_ckgen),
        .parents[4] = CLK_NODE(g_pll5_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_disp_bus_div_m = {
    .clk_node = {
        .core = &g_ap_bus_core,
        .id = 0x2000001,
        .rate = 300000000,
        .mux = 0,
        .parents_num = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_disp_bus_div_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_disp_bus_div_n = {
    .clk_node = {
        .core = &g_ap_bus_core,
        .id = 0x3000001,
        .rate = 300000000,
        .mux = 0,
        .parents_num = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_disp_bus_div_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_disp_bus_div_p = {
    .clk_node = {
        .core = &g_ap_bus_core,
        .id = 0x4000001,
        .rate = 150000000,
        .mux = 0,
        .parents_num = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_disp_bus_div_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_disp_bus_div_q = {
    .clk_node = {
        .core = &g_ap_bus_core,
        .id = 0x5000001,
        .rate = 150000000,
        .mux = 0,
        .parents_num = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_disp_bus_div_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_disp_bus_root = {
    .clk_node = {
        .core = &g_ap_bus_core,
        .id = 0x1,
        .rate = 300000000,
        .mux = 0,
        .parents_num = 2,
        .parents[0] = CLK_NODE(g_ckgen_bus_disp_bus_div_m),
        .parents[1] = CLK_NODE(g_pll5_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_seip_div_root = {
    .clk_node = {
        .core = &g_ap_bus_core,
        .id = 0x1000002,
        .rate = 300000000,
        .mux = 2,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll_lvds_ckgen),
        .parents[4] = CLK_NODE(g_pll5_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_seip_div_m = {
    .clk_node = {
        .core = &g_ap_bus_core,
        .id = 0x2000002,
        .rate = 300000000,
        .mux = 0,
        .parents_num = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_seip_div_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_seip_div_n = {
    .clk_node = {
        .core = &g_ap_bus_core,
        .id = 0x3000002,
        .rate = 300000000,
        .mux = 0,
        .parents_num = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_seip_div_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_seip_div_p = {
    .clk_node = {
        .core = &g_ap_bus_core,
        .id = 0x4000002,
        .rate = 150000000,
        .mux = 0,
        .parents_num = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_seip_div_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_seip_div_q = {
    .clk_node = {
        .core = &g_ap_bus_core,
        .id = 0x5000002,
        .rate = 150000000,
        .mux = 0,
        .parents_num = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_seip_div_root),
    },
};

taishan_ckgen_node_t g_ckgen_bus_seip_root = {
    .clk_node = {
        .core = &g_ap_bus_core,
        .id = 0x2,
        .rate = 300000000,
        .mux = 0,
        .parents_num = 2,
        .parents[0] = CLK_NODE(g_ckgen_bus_seip_div_m),
        .parents[1] = CLK_NODE(g_pll5_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_reserved = {
    .clk_node = {
        .core = &g_ap_ip_core,
        .id = 0x0,
        .rate = 300000000,
        .mux = 2,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll_lvds_ckgen),
        .parents[4] = CLK_NODE(g_pll5_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_seip_test = {
    .clk_node = {
        .core = &g_ap_ip_core,
        .id = 0x1,
        .rate = 6000000,
        .mux = 1,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll5_root),
        .parents[4] = CLK_NODE(g_pll_lvds_ckgen),
    },
};

taishan_ckgen_node_t g_ckgen_ip_sdramc = {
    .clk_node = {
        .core = &g_ap_ip_core,
        .id = 0x2,
        .rate = 120000000,
        .mux = 2,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll_lvds_ckgen),
        .parents[4] = CLK_NODE(g_pll5_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_sehc1 = {
    .clk_node = {
        .core = &g_ap_ip_core,
        .id = 0x3,
        .rate = 50000000,
        .mux = 2,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll_lvds_ckgen),
        .parents[4] = CLK_NODE(g_pll5_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_sehc2 = {
    .clk_node = {
        .core = &g_ap_ip_core,
        .id = 0x4,
        .rate = 50000000,
        .mux = 2,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll_lvds_ckgen),
        .parents[4] = CLK_NODE(g_pll5_root),
    },
};

taishan_ckgen_node_t g_ckgen_ip_i2s_mclk0 = {
    .clk_node = {
        .core = &g_ap_ip_core,
        .id = 0x5,
        .rate = 12290000,
        .mux = 3,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll5_root),
        .parents[4] = CLK_NODE(g_pll_lvds_ckgen),
    },
};

taishan_ckgen_node_t g_ckgen_ip_i2s_mclk1 = {
    .clk_node = {
        .core = &g_ap_ip_core,
        .id = 0x6,
        .rate = 12290000,
        .mux = 3,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll5_root),
        .parents[4] = CLK_NODE(g_pll_lvds_ckgen),
    },
};

taishan_ckgen_node_t g_ckgen_ip_saci1_clk = {
    .clk_node = {
        .core = &g_ap_ip_core,
        .id = 0x7,
        .rate = 12290000,
        .mux = 3,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll5_root),
        .parents[4] = CLK_NODE(g_pll_lvds_ckgen),
    },
};

taishan_ckgen_node_t g_ckgen_ip_saci1_pdm_clk = {
    .clk_node = {
        .core = &g_ap_ip_core,
        .id = 0x8,
        .rate = 12290000,
        .mux = 3,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll5_root),
        .parents[4] = CLK_NODE(g_pll_lvds_ckgen),
    },
};

taishan_ckgen_node_t g_ckgen_ip_saci2_clk = {
    .clk_node = {
        .core = &g_ap_ip_core,
        .id = 0x9,
        .rate = 12290000,
        .mux = 3,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll5_root),
        .parents[4] = CLK_NODE(g_pll_lvds_ckgen),
    },
};

taishan_ckgen_node_t g_ckgen_ip_saci2_pdm_clk = {
    .clk_node = {
        .core = &g_ap_ip_core,
        .id = 0xa,
        .rate = 12290000,
        .mux = 3,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll5_root),
        .parents[4] = CLK_NODE(g_pll_lvds_ckgen),
    },
};

taishan_ckgen_node_t g_ckgen_ip_dc = {
    .clk_node = {
        .core = &g_ap_ip_core,
        .id = 0xb,
        .rate = 262140000,
        .mux = 3,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll5_root),
        .parents[4] = CLK_NODE(g_pll_lvds_ckgen),
    },
};

taishan_ckgen_node_t g_ckgen_ip_csi = {
    .clk_node = {
        .core = &g_ap_ip_core,
        .id = 0xc,
        .rate = 262140000,
        .mux = 3,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll5_root),
        .parents[4] = CLK_NODE(g_pll_lvds_ckgen),
    },
};

taishan_ckgen_node_t g_ckgen_ip_csi_mclk = {
    .clk_node = {
        .core = &g_ap_ip_core,
        .id = 0xd,
        .rate = 150000000,
        .mux = 2,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll5_root),
        .parents[4] = CLK_NODE(g_pll_lvds_ckgen),
    },
};

taishan_ckgen_node_t g_ckgen_ip_dc_alt_clk = {
    .clk_node = {
        .core = &g_ap_ip_core,
        .id = 0xe,
        .rate = 150000000,
        .mux = 2,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll5_root),
        .parents[4] = CLK_NODE(g_pll_lvds_ckgen),
    },
};

taishan_ckgen_node_t g_ckgen_ip_pt_sns_ap = {
    .clk_node = {
        .core = &g_ap_ip_core,
        .id = 0xf,
        .rate = 100000,
        .mux = 1,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll5_root),
        .parents[4] = CLK_NODE(g_pll_lvds_ckgen),
    },
};

taishan_ckgen_node_t g_ckgen_ip_ap_test = {
    .clk_node = {
        .core = &g_ap_ip_core,
        .id = 0x10,
        .rate = 100000000,
        .mux = 2,
        .parents_num = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll5_root),
        .parents[4] = CLK_NODE(g_pll_lvds_ckgen),
    },
};

taishan_cg_node_t g_ckgen_gating_sf_cr5_sxclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x1000000,
    },
};

taishan_cg_node_t g_ckgen_gating_sx_mainclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x1000001,
    },
};

taishan_cg_node_t g_ckgen_gating_sf_cr5_sfclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x1000002,
    },
};

taishan_cg_node_t g_ckgen_gating_sx_sf_mainclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x1000003,
    },
};

taishan_cg_node_t g_ckgen_gating_sf_mainclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x1000004,
    },
};

taishan_cg_node_t g_ckgen_gating_sf_perclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x1000005,
    },
};

taishan_cg_node_t g_ckgen_gating_sx_sf_perclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x1000006,
    },
};

taishan_cg_node_t g_ckgen_gating_xspi1_aclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x1000007,
    },
};

taishan_cg_node_t g_ckgen_gating_xsp1_bclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x1000008,
    },
};

taishan_cg_node_t g_ckgen_gating_xspi2_aclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x1000009,
    },
};

taishan_cg_node_t g_ckgen_gating_xspi2_bclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x100000a,
    },
};

taishan_cg_node_t g_ckgen_gating_sp_cr5_spclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x100000b,
    },
};

taishan_cg_node_t g_ckgen_gating_sp_mainclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x100000c,
    },
};

taishan_cg_node_t g_ckgen_gating_sp_sf_mainclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x100000d,
    },
};

taishan_cg_node_t g_ckgen_gating_sp_perclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x100000e,
    },
};

taishan_cg_node_t g_ckgen_gating_cr5_sx0_clkin = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x2000000,
    },
};

taishan_cg_node_t g_ckgen_gating_cr5_sx1_clkin = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x2000001,
    },
};

taishan_cg_node_t g_ckgen_gating_cr5_sf_clkin = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x2000002,
    },
};

taishan_cg_node_t g_ckgen_gating_cr5_sp0_clkin = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x2000003,
    },
};

taishan_cg_node_t g_ckgen_gating_cr5_sp1_clkin = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x2000004,
    },
};

taishan_cg_node_t g_ckgen_gating_iram_mux_aclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x0,
    },
};

taishan_cg_node_t g_ckgen_gating_iramc1_aclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x1,
    },
};

taishan_cg_node_t g_ckgen_gating_iramc2_aclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x2,
    },
};

taishan_cg_node_t g_ckgen_gating_iramc3_aclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x3,
    },
};

taishan_cg_node_t g_ckgen_gating_iromc_aclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x4,
    },
};

taishan_cg_node_t g_ckgen_gating_sf_iram_mix_mainclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x5,
    },
};

taishan_cg_node_t g_ckgen_gating_sf_periph_mainclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x6,
    },
};

taishan_cg_node_t g_ckgen_gating_sf_boot_mainclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x7,
    },
};

taishan_cg_node_t g_ckgen_gating_mb_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x8,
    },
};

taishan_cg_node_t g_ckgen_gating_dma_sf_clk0 = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x9,
    },
};

taishan_cg_node_t g_ckgen_gating_dma_sf_clk1 = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xa,
    },
};

taishan_cg_node_t g_ckgen_gating_dma_sf_aclk0 = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xb,
    },
};

taishan_cg_node_t g_ckgen_gating_dma_sf_aclk1 = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xc,
    },
};

taishan_cg_node_t g_ckgen_gating_dma_sf_hclk0 = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xd,
    },
};

taishan_cg_node_t g_ckgen_gating_dma_sf_hclk1 = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xe,
    },
};

taishan_cg_node_t g_ckgen_gating_flexray1_hclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xf,
    },
};

taishan_cg_node_t g_ckgen_gating_flexray2_hclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x10,
    },
};

taishan_cg_node_t g_ckgen_gating_i2c1_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x11,
    },
};

taishan_cg_node_t g_ckgen_gating_i2c2_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x12,
    },
};

taishan_cg_node_t g_ckgen_gating_i2c3_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x13,
    },
};

taishan_cg_node_t g_ckgen_gating_i2c4_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x14,
    },
};

taishan_cg_node_t g_ckgen_gating_i2c5_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x15,
    },
};

taishan_cg_node_t g_ckgen_gating_i2c6_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x16,
    },
};

taishan_cg_node_t g_ckgen_gating_i2c7_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x17,
    },
};

taishan_cg_node_t g_ckgen_gating_i2c8_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x18,
    },
};

taishan_cg_node_t g_ckgen_gating_spi1_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x19,
    },
};

taishan_cg_node_t g_ckgen_gating_spi2_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x1a,
    },
};

taishan_cg_node_t g_ckgen_gating_spi3_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x1b,
    },
};

taishan_cg_node_t g_ckgen_gating_spi4_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x1c,
    },
};

taishan_cg_node_t g_ckgen_gating_spi5_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x1d,
    },
};

taishan_cg_node_t g_ckgen_gating_spi6_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x1e,
    },
};

taishan_cg_node_t g_ckgen_gating_spi7_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x1f,
    },
};

taishan_cg_node_t g_ckgen_gating_spi8_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x20,
    },
};

taishan_cg_node_t g_ckgen_gating_uart1_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x21,
    },
};

taishan_cg_node_t g_ckgen_gating_uart2_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x22,
    },
};

taishan_cg_node_t g_ckgen_gating_uart3_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x23,
    },
};

taishan_cg_node_t g_ckgen_gating_uart4_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x24,
    },
};

taishan_cg_node_t g_ckgen_gating_uart5_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x25,
    },
};

taishan_cg_node_t g_ckgen_gating_uart6_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x26,
    },
};

taishan_cg_node_t g_ckgen_gating_uart7_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x27,
    },
};

taishan_cg_node_t g_ckgen_gating_uart8_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x28,
    },
};

taishan_cg_node_t g_ckgen_gating_uart9_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x29,
    },
};

taishan_cg_node_t g_ckgen_gating_uart10_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x2a,
    },
};

taishan_cg_node_t g_ckgen_gating_uart11_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x2b,
    },
};

taishan_cg_node_t g_ckgen_gating_uart12_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x2c,
    },
};

taishan_cg_node_t g_ckgen_gating_uart13_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x2d,
    },
};

taishan_cg_node_t g_ckgen_gating_uart14_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x2e,
    },
};

taishan_cg_node_t g_ckgen_gating_uart15_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x2f,
    },
};

taishan_cg_node_t g_ckgen_gating_uart16_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x30,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd1_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x31,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd2_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x32,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd3_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x33,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd4_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x34,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd5_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x35,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd6_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x36,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd7_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x37,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd8_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x38,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd9_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x39,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd10_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x3a,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd11_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x3b,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd12_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x3c,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd13_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x3d,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd14_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x3e,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd15_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x3f,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd16_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x40,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd17_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x41,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd18_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x42,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd19_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x43,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd20_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x44,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd21_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x45,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd22_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x46,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd23_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x47,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd24_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x48,
    },
};

taishan_cg_node_t g_ckgen_gating_etmr1_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x49,
    },
};

taishan_cg_node_t g_ckgen_gating_etmr2_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x4a,
    },
};

taishan_cg_node_t g_ckgen_gating_etmr3_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x4b,
    },
};

taishan_cg_node_t g_ckgen_gating_etmr4_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x4c,
    },
};

taishan_cg_node_t g_ckgen_gating_pt_sns_sf_dig_i_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x4d,
    },
};

taishan_cg_node_t g_ckgen_gating_mpc_cr5_sx0_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x4e,
    },
};

taishan_cg_node_t g_ckgen_gating_mpc_cr5_sx1_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x4f,
    },
};

taishan_cg_node_t g_ckgen_gating_epwm1_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x50,
    },
};

taishan_cg_node_t g_ckgen_gating_epwm2_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x51,
    },
};

taishan_cg_node_t g_ckgen_gating_epwm3_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x52,
    },
};

taishan_cg_node_t g_ckgen_gating_epwm4_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x53,
    },
};

taishan_cg_node_t g_ckgen_gating_iram_mux_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x54,
    },
};

taishan_cg_node_t g_ckgen_gating_iramc1_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x55,
    },
};

taishan_cg_node_t g_ckgen_gating_iramc2_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x56,
    },
};

taishan_cg_node_t g_ckgen_gating_iramc3_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x57,
    },
};

taishan_cg_node_t g_ckgen_gating_iromc_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x58,
    },
};

taishan_cg_node_t g_ckgen_gating_gpio_sf_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x59,
    },
};

taishan_cg_node_t g_ckgen_gating_wdt1_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x5a,
    },
};

taishan_cg_node_t g_ckgen_gating_wdt2_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x5b,
    },
};

taishan_cg_node_t g_ckgen_gating_wdt1_bus_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x5c,
    },
};

taishan_cg_node_t g_ckgen_gating_wdt2_bus_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x5d,
    },
};

taishan_cg_node_t g_ckgen_gating_wdt5_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x5e,
    },
};

taishan_cg_node_t g_ckgen_gating_wdt5_bus_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x5f,
    },
};

taishan_cg_node_t g_ckgen_gating_wdt6_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x60,
    },
};

taishan_cg_node_t g_ckgen_gating_wdt6_bus_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x61,
    },
};

taishan_cg_node_t g_ckgen_gating_sem1_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x62,
    },
};

taishan_cg_node_t g_ckgen_gating_sem2_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x63,
    },
};

taishan_cg_node_t g_ckgen_gating_iomuxc_sf_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x64,
    },
};

taishan_cg_node_t g_ckgen_gating_iomuxc_sf_comp_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x65,
    },
};

taishan_cg_node_t g_ckgen_gating_efusec_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x66,
    },
};

taishan_cg_node_t g_ckgen_gating_mac_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x67,
    },
};

taishan_cg_node_t g_ckgen_gating_sf_periph_mac_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x68,
    },
};

taishan_cg_node_t g_ckgen_gating_sf_iram_mix_mac_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x69,
    },
};

taishan_cg_node_t g_ckgen_gating_mpc_cr5_sf_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x6a,
    },
};

taishan_cg_node_t g_ckgen_gating_scr_sf_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x6b,
    },
};

taishan_cg_node_t g_ckgen_gating_ckgen_sf_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x6c,
    },
};

taishan_cg_node_t g_ckgen_gating_rstgen_sf_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x6d,
    },
};

taishan_cg_node_t g_ckgen_gating_dma_sf_pclk0 = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x6e,
    },
};

taishan_cg_node_t g_ckgen_gating_dma_sf_pclk1 = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x6f,
    },
};

taishan_cg_node_t g_ckgen_gating_xb_sf_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x70,
    },
};

taishan_cg_node_t g_ckgen_gating_apbmux2_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x71,
    },
};

taishan_cg_node_t g_ckgen_gating_apbmux3_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x72,
    },
};

taishan_cg_node_t g_ckgen_gating_apbmux4_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x73,
    },
};

taishan_cg_node_t g_ckgen_gating_apbmux2_sf_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x74,
    },
};

taishan_cg_node_t g_ckgen_gating_ppc_apbmux1_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x75,
    },
};

taishan_cg_node_t g_ckgen_gating_ppc_apbmux2_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x76,
    },
};

taishan_cg_node_t g_ckgen_gating_ppc_apbmux3_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x77,
    },
};

taishan_cg_node_t g_ckgen_gating_ppc_apbmux4_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x78,
    },
};

taishan_cg_node_t g_ckgen_gating_smc_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x79,
    },
};

taishan_cg_node_t g_ckgen_gating_vd_sf_dig_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x7a,
    },
};

taishan_cg_node_t g_ckgen_gating_por_sf_dig_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x7b,
    },
};

taishan_cg_node_t g_ckgen_gating_xtrg_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x7c,
    },
};

taishan_cg_node_t g_ckgen_gating_apb_mac_sp_slv_src_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x7d,
    },
};

taishan_cg_node_t g_ckgen_gating_apb_mac_ap_slv_src_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x7e,
    },
};

taishan_cg_node_t g_ckgen_gating_fs_24m_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x7f,
    },
};

taishan_cg_node_t g_ckgen_gating_acmp1_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x80,
    },
};

taishan_cg_node_t g_ckgen_gating_acmp2_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x81,
    },
};

taishan_cg_node_t g_ckgen_gating_acmp3_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x82,
    },
};

taishan_cg_node_t g_ckgen_gating_acmp4_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x83,
    },
};

taishan_cg_node_t g_ckgen_gating_sadc1_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x84,
    },
};

taishan_cg_node_t g_ckgen_gating_sadc2_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x85,
    },
};

taishan_cg_node_t g_ckgen_gating_sadc3_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x86,
    },
};

taishan_cg_node_t g_ckgen_gating_ioc_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x87,
    },
};

taishan_cg_node_t g_ckgen_gating_btm1_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x88,
    },
};

taishan_cg_node_t g_ckgen_gating_btm2_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x89,
    },
};

taishan_cg_node_t g_ckgen_gating_btm3_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x8a,
    },
};

taishan_cg_node_t g_ckgen_gating_btm4_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x8b,
    },
};

taishan_cg_node_t g_ckgen_gating_btm5_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x8c,
    },
};

taishan_cg_node_t g_ckgen_gating_btm6_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x8d,
    },
};

taishan_cg_node_t g_ckgen_gating_eic_sf_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x8e,
    },
};

taishan_cg_node_t g_ckgen_gating_eic_boot_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x8f,
    },
};

taishan_cg_node_t g_ckgen_gating_istc_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x90,
    },
};

taishan_cg_node_t g_ckgen_gating_sf_periph_apbmux3_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x91,
    },
};

taishan_cg_node_t g_ckgen_gating_apb_seip_nvm_mst_dst_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x92,
    },
};

taishan_cg_node_t g_ckgen_gating_xspi1a_dma_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x93,
    },
};

taishan_cg_node_t g_ckgen_gating_xspi1b_dma_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x94,
    },
};

taishan_cg_node_t g_ckgen_gating_xspi2a_dma_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x95,
    },
};

taishan_cg_node_t g_ckgen_gating_xspi2b_dma_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x96,
    },
};

taishan_cg_node_t g_ckgen_gating_adma_enet1_dmaclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x97,
    },
};

taishan_cg_node_t g_ckgen_gating_adma_enet2_dmaclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x98,
    },
};

taishan_cg_node_t g_ckgen_gating_xb_sf_hclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x99,
    },
};

taishan_cg_node_t g_ckgen_gating_bti_sf_ahb_hclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x9a,
    },
};

taishan_cg_node_t g_ckgen_gating_aahb_spsf_mst_slvclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x9b,
    },
};

taishan_cg_node_t g_ckgen_gating_vic1_hclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x9c,
    },
};

taishan_cg_node_t g_ckgen_gating_vic3a_hclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x9d,
    },
};

taishan_cg_node_t g_ckgen_gating_vic3b_hclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x9e,
    },
};

taishan_cg_node_t g_ckgen_gating_vic_sf_irqsync = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x9f,
    },
};

taishan_cg_node_t g_ckgen_gating_i2c1_sclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xa0,
    },
};

taishan_cg_node_t g_ckgen_gating_i2c2_sclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xa1,
    },
};

taishan_cg_node_t g_ckgen_gating_i2c3_sclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xa2,
    },
};

taishan_cg_node_t g_ckgen_gating_i2c4_sclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xa3,
    },
};

taishan_cg_node_t g_ckgen_gating_i2c5_sclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xa4,
    },
};

taishan_cg_node_t g_ckgen_gating_i2c6_sclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xa5,
    },
};

taishan_cg_node_t g_ckgen_gating_i2c7_sclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xa6,
    },
};

taishan_cg_node_t g_ckgen_gating_i2c8_sclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xa7,
    },
};

taishan_cg_node_t g_ckgen_gating_spi1_spi_per_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xa8,
    },
};

taishan_cg_node_t g_ckgen_gating_spi2_spi_per_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xa9,
    },
};

taishan_cg_node_t g_ckgen_gating_spi3_spi_per_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xaa,
    },
};

taishan_cg_node_t g_ckgen_gating_spi4_spi_per_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xab,
    },
};

taishan_cg_node_t g_ckgen_gating_spi5_spi_per_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xac,
    },
};

taishan_cg_node_t g_ckgen_gating_spi6_spi_per_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xad,
    },
};

taishan_cg_node_t g_ckgen_gating_spi7_spi_per_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xae,
    },
};

taishan_cg_node_t g_ckgen_gating_spi8_spi_per_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xaf,
    },
};

taishan_cg_node_t g_ckgen_gating_uart1_sclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xb0,
    },
};

taishan_cg_node_t g_ckgen_gating_uart2_sclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xb1,
    },
};

taishan_cg_node_t g_ckgen_gating_uart3_sclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xb2,
    },
};

taishan_cg_node_t g_ckgen_gating_uart4_sclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xb3,
    },
};

taishan_cg_node_t g_ckgen_gating_uart5_sclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xb4,
    },
};

taishan_cg_node_t g_ckgen_gating_uart6_sclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xb5,
    },
};

taishan_cg_node_t g_ckgen_gating_uart7_sclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xb6,
    },
};

taishan_cg_node_t g_ckgen_gating_uart8_sclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xb7,
    },
};

taishan_cg_node_t g_ckgen_gating_uart9_sclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xb8,
    },
};

taishan_cg_node_t g_ckgen_gating_uart10_sclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xb9,
    },
};

taishan_cg_node_t g_ckgen_gating_uart11_sclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xba,
    },
};

taishan_cg_node_t g_ckgen_gating_uart12_sclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xbb,
    },
};

taishan_cg_node_t g_ckgen_gating_uart13_sclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xbc,
    },
};

taishan_cg_node_t g_ckgen_gating_uart14_sclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xbd,
    },
};

taishan_cg_node_t g_ckgen_gating_uart15_sclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xbe,
    },
};

taishan_cg_node_t g_ckgen_gating_uart16_sclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xbf,
    },
};

taishan_cg_node_t g_ckgen_gating_enet1_ref_clk_tx = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xc0,
    },
};

taishan_cg_node_t g_ckgen_gating_enet1_ptp_ref_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xc1,
    },
};

taishan_cg_node_t g_ckgen_gating_enet2_ptp_ref_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xc2,
    },
};

taishan_cg_node_t g_ckgen_gating_enet2_ref_clk_tx = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xc3,
    },
};

taishan_cg_node_t g_ckgen_gating_xspi1a_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xc4,
    },
};

taishan_cg_node_t g_ckgen_gating_mpc_xspi1a_aclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xc5,
    },
};

taishan_cg_node_t g_ckgen_gating_xspi1b_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xc6,
    },
};

taishan_cg_node_t g_ckgen_gating_mpc_xspi1b_aclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xc7,
    },
};

taishan_cg_node_t g_ckgen_gating_xspi2a_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xc8,
    },
};

taishan_cg_node_t g_ckgen_gating_mpc_xspi2a_aclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xc9,
    },
};

taishan_cg_node_t g_ckgen_gating_xspi2b_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xca,
    },
};

taishan_cg_node_t g_ckgen_gating_mpc_xspi2b_aclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xcb,
    },
};

taishan_cg_node_t g_ckgen_gating_xtrg_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xcc,
    },
};

taishan_cg_node_t g_ckgen_gating_etmr1_ahf_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xcd,
    },
};

taishan_cg_node_t g_ckgen_gating_etmr2_ahf_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xce,
    },
};

taishan_cg_node_t g_ckgen_gating_etmr3_ahf_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xcf,
    },
};

taishan_cg_node_t g_ckgen_gating_etmr4_ahf_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xd0,
    },
};

taishan_cg_node_t g_ckgen_gating_epwm1_ahf_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xd1,
    },
};

taishan_cg_node_t g_ckgen_gating_epwm2_ahf_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xd2,
    },
};

taishan_cg_node_t g_ckgen_gating_epwm3_ahf_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xd3,
    },
};

taishan_cg_node_t g_ckgen_gating_epwm4_ahf_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xd4,
    },
};

taishan_cg_node_t g_ckgen_gating_etmr1_hf_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xd5,
    },
};

taishan_cg_node_t g_ckgen_gating_etmr2_hf_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xd6,
    },
};

taishan_cg_node_t g_ckgen_gating_etmr3_hf_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xd7,
    },
};

taishan_cg_node_t g_ckgen_gating_etmr4_hf_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xd8,
    },
};

taishan_cg_node_t g_ckgen_gating_epwm1_hf_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xd9,
    },
};

taishan_cg_node_t g_ckgen_gating_epwm2_hf_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xda,
    },
};

taishan_cg_node_t g_ckgen_gating_epwm3_hf_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xdb,
    },
};

taishan_cg_node_t g_ckgen_gating_epwm4_hf_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xdc,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd1_ipg_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xdd,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd2_ipg_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xde,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd3_ipg_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xdf,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd4_ipg_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xe0,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd5_ipg_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xe1,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd6_ipg_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xe2,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd7_ipg_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xe3,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd8_ipg_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xe4,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd9_ipg_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xe5,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd10_ipg_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xe6,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd11_ipg_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xe7,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd12_ipg_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xe8,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd13_ipg_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xe9,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd14_ipg_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xea,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd15_ipg_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xeb,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd16_ipg_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xec,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd17_ipg_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xed,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd18_ipg_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xee,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd19_ipg_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xef,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd20_ipg_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xf0,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd21_ipg_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xf1,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd22_ipg_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xf2,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd23_ipg_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xf3,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd24_ipg_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xf4,
    },
};

taishan_cg_node_t g_ckgen_gating_sadc1_ctrl_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xf5,
    },
};

taishan_cg_node_t g_ckgen_gating_sadc2_ctrl_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xf6,
    },
};

taishan_cg_node_t g_ckgen_gating_sadc3_ctrl_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xf7,
    },
};

taishan_cg_node_t g_ckgen_gating_acmp1_ctrl_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xf8,
    },
};

taishan_cg_node_t g_ckgen_gating_acmp2_ctrl_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xf9,
    },
};

taishan_cg_node_t g_ckgen_gating_acmp3_ctrl_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xfa,
    },
};

taishan_cg_node_t g_ckgen_gating_acmp4_ctrl_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xfb,
    },
};

taishan_cg_node_t g_ckgen_gating_flexray1_ipg_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xfc,
    },
};

taishan_cg_node_t g_ckgen_gating_flexray2_ipg_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xfd,
    },
};

taishan_cg_node_t g_ckgen_gating_ioc_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xfe,
    },
};

taishan_cg_node_t g_ckgen_gating_pt_sns_sf_clkin = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0xff,
    },
};

taishan_cg_node_t g_ckgen_gating_istc_i_istc_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x100,
    },
};

taishan_cg_node_t g_ckgen_gating_smc_clk_24m = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x101,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd1_clk24m = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x102,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd2_clk24m = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x103,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd3_clk24m = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x104,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd4_clk24m = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x105,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd5_clk24m = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x106,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd6_clk24m = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x107,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd7_clk24m = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x108,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd8_clk24m = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x109,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd9_clk24m = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x10a,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd10_clk24m = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x10b,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd11_clk24m = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x10c,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd12_clk24m = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x10d,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd13_clk24m = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x10e,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd14_clk24m = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x10f,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd15_clk24m = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x110,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd16_clk24m = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x111,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd17_clk24m = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x112,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd18_clk24m = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x113,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd19_clk24m = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x114,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd20_clk24m = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x115,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd21_clk24m = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x116,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd22_clk24m = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x117,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd23_clk24m = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x118,
    },
};

taishan_cg_node_t g_ckgen_gating_canfd24_clk24m = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x119,
    },
};

taishan_cg_node_t g_ckgen_gating_xtrg_wdt_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x11a,
    },
};

taishan_cg_node_t g_ckgen_gating_ldo_dig_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x11b,
    },
};

taishan_cg_node_t g_ckgen_gating_dcdc1_clk_24m = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x11c,
    },
};

taishan_cg_node_t g_ckgen_gating_vic1_wdt_ref_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x11d,
    },
};

taishan_cg_node_t g_ckgen_gating_vic3a_wdt_ref_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x11e,
    },
};

taishan_cg_node_t g_ckgen_gating_vic3b_wdt_ref_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x11f,
    },
};

taishan_cg_node_t g_ckgen_gating_wdt1_main_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x120,
    },
};

taishan_cg_node_t g_ckgen_gating_wdt2_main_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x121,
    },
};

taishan_cg_node_t g_ckgen_gating_wdt5_main_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x122,
    },
};

taishan_cg_node_t g_ckgen_gating_wdt6_main_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x123,
    },
};

taishan_cg_node_t g_ckgen_gating_btm1_i_xtal24mhz_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x124,
    },
};

taishan_cg_node_t g_ckgen_gating_btm2_i_xtal24mhz_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x125,
    },
};

taishan_cg_node_t g_ckgen_gating_btm3_i_xtal24mhz_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x126,
    },
};

taishan_cg_node_t g_ckgen_gating_btm4_i_xtal24mhz_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x127,
    },
};

taishan_cg_node_t g_ckgen_gating_btm5_i_xtal24mhz_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x128,
    },
};

taishan_cg_node_t g_ckgen_gating_btm6_i_xtal24mhz_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x129,
    },
};

taishan_cg_node_t g_ckgen_gating_pt_sns_sf_dig_clk_24m = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x12a,
    },
};

taishan_cg_node_t g_ckgen_gating_gama1_hclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x12b,
    },
};

taishan_cg_node_t g_ckgen_gating_xspi_slv_aclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x12c,
    },
};

taishan_cg_node_t g_ckgen_gating_vic2a_hclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x12d,
    },
};

taishan_cg_node_t g_ckgen_gating_vic2b_hclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x12e,
    },
};

taishan_cg_node_t g_ckgen_gating_vic_sp_irqsync = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x12f,
    },
};

taishan_cg_node_t g_ckgen_gating_enet1_aclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x130,
    },
};

taishan_cg_node_t g_ckgen_gating_enet2_aclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x131,
    },
};

taishan_cg_node_t g_ckgen_gating_gama1_aclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x132,
    },
};

taishan_cg_node_t g_ckgen_gating_ahb_syncup_gama1_mainclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x133,
    },
};

taishan_cg_node_t g_ckgen_gating_iramc4_aclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x134,
    },
};

taishan_cg_node_t g_ckgen_gating_wdt3_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x135,
    },
};

taishan_cg_node_t g_ckgen_gating_wdt3_bus_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x136,
    },
};

taishan_cg_node_t g_ckgen_gating_wdt4_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x137,
    },
};

taishan_cg_node_t g_ckgen_gating_wdt4_bus_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x138,
    },
};

taishan_cg_node_t g_ckgen_gating_ppc_apbmux5_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x139,
    },
};

taishan_cg_node_t g_ckgen_gating_apbmux5_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x13a,
    },
};

taishan_cg_node_t g_ckgen_gating_xspi_slv_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x13b,
    },
};

taishan_cg_node_t g_ckgen_gating_enet1_clk_csr = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x13c,
    },
};

taishan_cg_node_t g_ckgen_gating_enet2_clk_csr = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x13d,
    },
};

taishan_cg_node_t g_ckgen_gating_adma_enet1_perclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x13e,
    },
};

taishan_cg_node_t g_ckgen_gating_adma_enet2_perclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x13f,
    },
};

taishan_cg_node_t g_ckgen_gating_sp_mac_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x140,
    },
};

taishan_cg_node_t g_ckgen_gating_cr5_sp_mix_mac_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x141,
    },
};

taishan_cg_node_t g_ckgen_gating_eic_sp_i_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x142,
    },
};

taishan_cg_node_t g_ckgen_gating_cslite_pclkdbg = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x143,
    },
};

taishan_cg_node_t g_ckgen_gating_cslite_pclksys = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x144,
    },
};

taishan_cg_node_t g_ckgen_gating_apb_cr5sx0_dbg_slv_src_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x145,
    },
};

taishan_cg_node_t g_ckgen_gating_apb_cr5sx1_dbg_slv_src_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x146,
    },
};

taishan_cg_node_t g_ckgen_gating_apb_cr5sf_dbg_slv_src_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x147,
    },
};

taishan_cg_node_t g_ckgen_gating_iramc4_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x148,
    },
};

taishan_cg_node_t g_ckgen_gating_wdt3_main_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x149,
    },
};

taishan_cg_node_t g_ckgen_gating_wdt4_main_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x14a,
    },
};

taishan_cg_node_t g_ckgen_gating_vic2a_wdt_ref_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x14b,
    },
};

taishan_cg_node_t g_ckgen_gating_vic2b_wdt_ref_clk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x14c,
    },
};

taishan_cg_node_t g_ckgen_gating_rtc_pclk = {
    .clk_node = {
        .core = &g_sf_gating_core,
        .id = 0x14d,
    },
};

taishan_cg_node_t g_ckgen_gating_ap_apmainclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x1000000,
    },
};

taishan_cg_node_t g_ckgen_gating_ap_dispclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x1000001,
    },
};

taishan_cg_node_t g_ckgen_gating_ap_perclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x1000002,
    },
};

taishan_cg_node_t g_ckgen_gating_ap_hsmperclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x1000003,
    },
};

taishan_cg_node_t g_ckgen_gating_ap_sdramclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x1000004,
    },
};

taishan_cg_node_t g_ckgen_gating_disp_mainclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x1000005,
    },
};

taishan_cg_node_t g_ckgen_gating_disp_perclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x1000006,
    },
};

taishan_cg_node_t g_ckgen_gating_sehc1_aclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x0,
    },
};

taishan_cg_node_t g_ckgen_gating_sehc2_aclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x1,
    },
};

taishan_cg_node_t g_ckgen_gating_dma_ap_clk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x2,
    },
};

taishan_cg_node_t g_ckgen_gating_dma_ap_aclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x3,
    },
};

taishan_cg_node_t g_ckgen_gating_dma_ap_hclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x4,
    },
};

taishan_cg_node_t g_ckgen_gating_seip_sh_clk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x5,
    },
};

taishan_cg_node_t g_ckgen_gating_apbmux6_pclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x6,
    },
};

taishan_cg_node_t g_ckgen_gating_sdramc_pclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x7,
    },
};

taishan_cg_node_t g_ckgen_gating_gpio_ap_pclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x8,
    },
};

taishan_cg_node_t g_ckgen_gating_iomuxc_ap_pclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x9,
    },
};

taishan_cg_node_t g_ckgen_gating_ckgen_ap_pclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0xa,
    },
};

taishan_cg_node_t g_ckgen_gating_usb2_pclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0xb,
    },
};

taishan_cg_node_t g_ckgen_gating_sehc1_pclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0xc,
    },
};

taishan_cg_node_t g_ckgen_gating_sehc2_pclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0xd,
    },
};

taishan_cg_node_t g_ckgen_gating_rstgen_ap_pclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0xe,
    },
};

taishan_cg_node_t g_ckgen_gating_wdt8_pclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0xf,
    },
};

taishan_cg_node_t g_ckgen_gating_wdt8_bus_clk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x10,
    },
};

taishan_cg_node_t g_ckgen_gating_saci1_pclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x11,
    },
};

taishan_cg_node_t g_ckgen_gating_saci2_pclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x12,
    },
};

taishan_cg_node_t g_ckgen_gating_dma_ap_pclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x13,
    },
};

taishan_cg_node_t g_ckgen_gating_ap_mac_pclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x14,
    },
};

taishan_cg_node_t g_ckgen_gating_vd_ap_pclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x15,
    },
};

taishan_cg_node_t g_ckgen_gating_pt_sns_ap_pclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x16,
    },
};

taishan_cg_node_t g_ckgen_gating_scr_ap_pclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x17,
    },
};

taishan_cg_node_t g_ckgen_gating_por_ap_pclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x18,
    },
};

taishan_cg_node_t g_ckgen_gating_seip_pclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x19,
    },
};

taishan_cg_node_t g_ckgen_gating_seip_hclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x1a,
    },
};

taishan_cg_node_t g_ckgen_gating_seip_fd_ref_clk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x1b,
    },
};

taishan_cg_node_t g_ckgen_gating_sdramc_aclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x1c,
    },
};

taishan_cg_node_t g_ckgen_gating_sehc1_main_clk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x1d,
    },
};

taishan_cg_node_t g_ckgen_gating_sehc2_main_clk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x1e,
    },
};

taishan_cg_node_t g_ckgen_gating_saci1_i2s_mclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x1f,
    },
};

taishan_cg_node_t g_ckgen_gating_saci2_i2s_mclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x20,
    },
};

taishan_cg_node_t g_ckgen_gating_saci1_ext_clk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x21,
    },
};

taishan_cg_node_t g_ckgen_gating_saci2_ext_clk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x22,
    },
};

taishan_cg_node_t g_ckgen_gating_saci1_i2s_tx_clk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x23,
    },
};

taishan_cg_node_t g_ckgen_gating_saci2_i2s_tx_clk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x24,
    },
};

taishan_cg_node_t g_ckgen_gating_saci1_i2s_rx_clk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x25,
    },
};

taishan_cg_node_t g_ckgen_gating_saci2_i2s_rx_clk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x26,
    },
};

taishan_cg_node_t g_ckgen_gating_saci1_pdm_per_clk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x27,
    },
};

taishan_cg_node_t g_ckgen_gating_saci2_pdm_per_clk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x28,
    },
};

taishan_cg_node_t g_ckgen_gating_pt_sns_ap_clkin = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x29,
    },
};

taishan_cg_node_t g_ckgen_gating_usb_phy_ref_clk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x2a,
    },
};

taishan_cg_node_t g_ckgen_gating_wdt8_main_clk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x2b,
    },
};

taishan_cg_node_t g_ckgen_gating_sehc1_cqe_sqs_clk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x2c,
    },
};

taishan_cg_node_t g_ckgen_gating_sehc2_cqe_sqs_clk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x2d,
    },
};

taishan_cg_node_t g_ckgen_gating_sehc1_tm_clk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x2e,
    },
};

taishan_cg_node_t g_ckgen_gating_sehc2_tm_clk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x2f,
    },
};

taishan_cg_node_t g_ckgen_gating_csi_axi_clk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x30,
    },
};

taishan_cg_node_t g_ckgen_gating_dc_axi_clk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x31,
    },
};

taishan_cg_node_t g_ckgen_gating_g2d_axi_clk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x32,
    },
};

taishan_cg_node_t g_ckgen_gating_csi_pclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x33,
    },
};

taishan_cg_node_t g_ckgen_gating_apbmux7_pclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x34,
    },
};

taishan_cg_node_t g_ckgen_gating_disp_mux_pclk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x35,
    },
};

taishan_cg_node_t g_ckgen_gating_dc_pix_clk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x36,
    },
};

taishan_cg_node_t g_ckgen_gating_csi_proc_clk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x37,
    },
};

taishan_cg_node_t g_ckgen_gating_disp_mux_disp_ckgen_pix_clk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x38,
    },
};

taishan_cg_node_t g_ckgen_gating_lvds_ch0_clk_x14 = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x39,
    },
};

taishan_cg_node_t g_ckgen_gating_lvds_ch0_clk_x7 = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x3a,
    },
};

taishan_cg_node_t g_ckgen_gating_dc_dsp_clk = {
    .clk_node = {
        .core = &g_ap_gating_core,
        .id = 0x3b,
    },
};

#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

/*pll1 is always 500M configured by ROM*/
const clk_node_t * const clk_prepare_array[] = {
    CLK_NODE(g_ckgen_bus_cr5_sf_div_root_preset),
    CLK_NODE(g_ckgen_bus_cr5_sp_div_root_preset),
    CLK_NODE(g_ckgen_bus_sf_test_div_root_preset),
    CLK_NODE(g_ckgen_bus_ap_bus_div_root_preset),
    CLK_NODE(g_ckgen_bus_seip_div_root_preset),
#ifndef CFG_XIP
    CLK_NODE(g_pll1_root),
    CLK_NODE(g_pll2_root),
    CLK_NODE(g_pll3_root),
#endif
    CLK_NODE(g_ckgen_bus_cr5_sf_div_root),
    CLK_NODE(g_ckgen_bus_cr5_sf_div_m),
    CLK_NODE(g_ckgen_bus_cr5_sf_div_n),
    CLK_NODE(g_ckgen_bus_cr5_sf_div_p),
    CLK_NODE(g_ckgen_bus_cr5_sf_div_q),
    CLK_NODE(g_ckgen_bus_cr5_sf_root),
    CLK_NODE(g_ckgen_bus_cr5_sp_div_root),
    CLK_NODE(g_ckgen_bus_cr5_sp_div_m),
    CLK_NODE(g_ckgen_bus_cr5_sp_div_n),
    CLK_NODE(g_ckgen_bus_cr5_sp_div_p),
    CLK_NODE(g_ckgen_bus_cr5_sp_div_q),
    CLK_NODE(g_ckgen_bus_cr5_sp_root),
    CLK_NODE(g_ckgen_core_cr5_sx),
    CLK_NODE(g_ckgen_ip_i2c_sf_1_to_4),
    CLK_NODE(g_ckgen_ip_spi_sf_5_to_8),
#ifndef CFG_XIP
    CLK_NODE(g_ckgen_ip_xspi1a),
    CLK_NODE(g_ckgen_ip_xspi1b),
    CLK_NODE(g_ckgen_ip_xspi2a),
    CLK_NODE(g_ckgen_ip_xspi2b),
#endif
    CLK_NODE(g_ckgen_ip_etmr1),
    CLK_NODE(g_ckgen_ip_can),
    CLK_NODE(g_ckgen_ip_acmp),
    CLK_NODE(g_ckgen_ip_ioc),
    CLK_NODE(g_ckgen_ip_pt_sns_sf),
    CLK_NODE(g_ckgen_bus_sf_test_div_root),
    CLK_NODE(g_ckgen_bus_sf_test_div_m),
    CLK_NODE(g_ckgen_bus_sf_test_div_n),
    CLK_NODE(g_ckgen_bus_sf_test_div_p),
    CLK_NODE(g_ckgen_bus_sf_test_div_q),
    CLK_NODE(g_ckgen_bus_sf_test_root),
    CLK_NODE(g_pll4_root),
    CLK_NODE(g_pll5_root),
    CLK_NODE(g_pll_lvds_root),
    CLK_NODE(g_pll_lvds_nodiv),
    CLK_NODE(g_pll_lvds_div2),
    CLK_NODE(g_pll_lvds_div7),
    CLK_NODE(g_pll_lvds_ckgen),
    CLK_NODE(g_ckgen_bus_ap_bus_div_root),
    CLK_NODE(g_ckgen_bus_ap_bus_div_p),
    CLK_NODE(g_ckgen_bus_ap_bus_div_n),
    CLK_NODE(g_ckgen_bus_ap_bus_root),
    CLK_NODE(g_ckgen_bus_seip_div_root),
    CLK_NODE(g_ckgen_bus_seip_div_p),
    CLK_NODE(g_ckgen_bus_seip_div_n),
    CLK_NODE(g_ckgen_bus_seip_root),
    CLK_NODE(g_ckgen_ip_reserved),
    CLK_NODE(g_ckgen_ip_seip_test),
    CLK_NODE(g_ckgen_ip_sdramc),
    CLK_NODE(g_ckgen_ip_sehc1),
    CLK_NODE(g_ckgen_ip_sehc2),
    CLK_NODE(g_ckgen_ip_pt_sns_ap),
    CLK_NODE(g_ckgen_ip_ap_test),
};

const clk_node_t * const clk_enable_array[] = {
    CLK_NODE(g_ckgen_gating_sf_cr5_sxclk),
    CLK_NODE(g_ckgen_gating_sx_mainclk),
    CLK_NODE(g_ckgen_gating_sf_cr5_sfclk),
    CLK_NODE(g_ckgen_gating_sx_sf_mainclk),
    CLK_NODE(g_ckgen_gating_sf_mainclk),
    CLK_NODE(g_ckgen_gating_sf_perclk),
    CLK_NODE(g_ckgen_gating_sx_sf_perclk),
    CLK_NODE(g_ckgen_gating_xspi1_aclk),
    CLK_NODE(g_ckgen_gating_xsp1_bclk),
    CLK_NODE(g_ckgen_gating_xspi2_aclk),
    CLK_NODE(g_ckgen_gating_xspi2_bclk),
    CLK_NODE(g_ckgen_gating_sp_mainclk),
    CLK_NODE(g_ckgen_gating_sp_sf_mainclk),
    CLK_NODE(g_ckgen_gating_sp_perclk),
    CLK_NODE(g_ckgen_gating_cr5_sx0_clkin),
    CLK_NODE(g_ckgen_gating_cr5_sx1_clkin),
    CLK_NODE(g_ckgen_gating_cr5_sf_clkin),
    CLK_NODE(g_ckgen_gating_iram_mux_aclk),
    CLK_NODE(g_ckgen_gating_iramc1_aclk),
    CLK_NODE(g_ckgen_gating_iramc2_aclk),
    CLK_NODE(g_ckgen_gating_iromc_aclk),
    CLK_NODE(g_ckgen_gating_sf_iram_mix_mainclk),
    CLK_NODE(g_ckgen_gating_sf_periph_mainclk),
    CLK_NODE(g_ckgen_gating_sf_boot_mainclk),
    CLK_NODE(g_ckgen_gating_canfd7_pclk),
    CLK_NODE(g_ckgen_gating_canfd7_ipg_clk),
    CLK_NODE(g_ckgen_gating_canfd7_clk24m),
    CLK_NODE(g_ckgen_gating_canfd8_pclk),
    CLK_NODE(g_ckgen_gating_canfd8_ipg_clk),
    CLK_NODE(g_ckgen_gating_canfd8_clk24m),
    CLK_NODE(g_ckgen_gating_pt_sns_sf_dig_i_pclk),
    CLK_NODE(g_ckgen_gating_mpc_cr5_sx0_pclk),
    CLK_NODE(g_ckgen_gating_mpc_cr5_sx1_pclk),
    CLK_NODE(g_ckgen_gating_iram_mux_pclk),
    CLK_NODE(g_ckgen_gating_iramc1_pclk),
    CLK_NODE(g_ckgen_gating_iramc2_pclk),
    CLK_NODE(g_ckgen_gating_iromc_pclk),
    CLK_NODE(g_ckgen_gating_gpio_sf_pclk),
    CLK_NODE(g_ckgen_gating_wdt1_pclk),
    CLK_NODE(g_ckgen_gating_wdt2_pclk),
    CLK_NODE(g_ckgen_gating_wdt1_bus_clk),
    CLK_NODE(g_ckgen_gating_wdt2_bus_clk),
    CLK_NODE(g_ckgen_gating_wdt5_pclk),
    CLK_NODE(g_ckgen_gating_wdt5_bus_clk),
    CLK_NODE(g_ckgen_gating_wdt6_pclk),
    CLK_NODE(g_ckgen_gating_wdt6_bus_clk),
    CLK_NODE(g_ckgen_gating_sem1_pclk),
    CLK_NODE(g_ckgen_gating_sem2_pclk),
    CLK_NODE(g_ckgen_gating_iomuxc_sf_pclk),
    CLK_NODE(g_ckgen_gating_iomuxc_sf_comp_pclk),
    CLK_NODE(g_ckgen_gating_efusec_pclk),
    CLK_NODE(g_ckgen_gating_mac_pclk),
    CLK_NODE(g_ckgen_gating_sf_periph_mac_pclk),
    CLK_NODE(g_ckgen_gating_sf_iram_mix_mac_pclk),
    CLK_NODE(g_ckgen_gating_mpc_cr5_sf_pclk),
    CLK_NODE(g_ckgen_gating_scr_sf_pclk),
    CLK_NODE(g_ckgen_gating_ckgen_sf_pclk),
    CLK_NODE(g_ckgen_gating_rstgen_sf_pclk),
    CLK_NODE(g_ckgen_gating_xb_sf_pclk),
    CLK_NODE(g_ckgen_gating_apbmux2_pclk),
    CLK_NODE(g_ckgen_gating_apbmux3_pclk),
    CLK_NODE(g_ckgen_gating_apbmux4_pclk),
    CLK_NODE(g_ckgen_gating_apbmux2_sf_pclk),
    CLK_NODE(g_ckgen_gating_ppc_apbmux1_pclk),
    CLK_NODE(g_ckgen_gating_ppc_apbmux2_pclk),
    CLK_NODE(g_ckgen_gating_ppc_apbmux3_pclk),
    CLK_NODE(g_ckgen_gating_ppc_apbmux4_pclk),
    CLK_NODE(g_ckgen_gating_smc_pclk),
    CLK_NODE(g_ckgen_gating_vd_sf_dig_pclk),
    CLK_NODE(g_ckgen_gating_por_sf_dig_pclk),
    CLK_NODE(g_ckgen_gating_apb_mac_ap_slv_src_pclk),
    CLK_NODE(g_ckgen_gating_fs_24m_pclk),
    CLK_NODE(g_ckgen_gating_acmp1_pclk),
    CLK_NODE(g_ckgen_gating_acmp2_pclk),
    CLK_NODE(g_ckgen_gating_acmp3_pclk),
    CLK_NODE(g_ckgen_gating_acmp4_pclk),
    CLK_NODE(g_ckgen_gating_ioc_pclk),
    CLK_NODE(g_ckgen_gating_btm1_pclk),
    CLK_NODE(g_ckgen_gating_btm2_pclk),
    CLK_NODE(g_ckgen_gating_btm3_pclk),
    CLK_NODE(g_ckgen_gating_btm4_pclk),
    CLK_NODE(g_ckgen_gating_btm5_pclk),
    CLK_NODE(g_ckgen_gating_btm6_pclk),
    CLK_NODE(g_ckgen_gating_eic_sf_pclk),
    CLK_NODE(g_ckgen_gating_eic_boot_pclk),
    CLK_NODE(g_ckgen_gating_istc_pclk),
    CLK_NODE(g_ckgen_gating_sf_periph_apbmux3_pclk),
    CLK_NODE(g_ckgen_gating_apb_seip_nvm_mst_dst_pclk),
    CLK_NODE(g_ckgen_gating_xspi1a_dma_clk),
    CLK_NODE(g_ckgen_gating_xspi1b_dma_clk),
    CLK_NODE(g_ckgen_gating_xspi2a_dma_clk),
    CLK_NODE(g_ckgen_gating_xspi2b_dma_clk),
    CLK_NODE(g_ckgen_gating_xb_sf_hclk),
    CLK_NODE(g_ckgen_gating_bti_sf_ahb_hclk),
    CLK_NODE(g_ckgen_gating_aahb_spsf_mst_slvclk),
    CLK_NODE(g_ckgen_gating_vic1_hclk),
    CLK_NODE(g_ckgen_gating_vic_sf_irqsync),
    CLK_NODE(g_ckgen_gating_i2c1_sclk),
    CLK_NODE(g_ckgen_gating_i2c1_pclk),
    CLK_NODE(g_ckgen_gating_spi7_pclk),
    CLK_NODE(g_ckgen_gating_spi7_spi_per_clk),
    CLK_NODE(g_ckgen_gating_xspi1a_clk),
    CLK_NODE(g_ckgen_gating_mpc_xspi1a_aclk),
    CLK_NODE(g_ckgen_gating_xspi1b_clk),
    CLK_NODE(g_ckgen_gating_mpc_xspi1b_aclk),
    CLK_NODE(g_ckgen_gating_xspi2a_clk),
    CLK_NODE(g_ckgen_gating_mpc_xspi2a_aclk),
    CLK_NODE(g_ckgen_gating_xspi2b_clk),
    CLK_NODE(g_ckgen_gating_mpc_xspi2b_aclk),
    CLK_NODE(g_ckgen_gating_etmr1_pclk),
    CLK_NODE(g_ckgen_gating_etmr1_ahf_clk),
    CLK_NODE(g_ckgen_gating_etmr1_hf_clk),
    CLK_NODE(g_ckgen_gating_acmp1_ctrl_clk),
    CLK_NODE(g_ckgen_gating_acmp2_ctrl_clk),
    CLK_NODE(g_ckgen_gating_acmp3_ctrl_clk),
    CLK_NODE(g_ckgen_gating_acmp4_ctrl_clk),
    CLK_NODE(g_ckgen_gating_ioc_clk),
    CLK_NODE(g_ckgen_gating_pt_sns_sf_clkin),
    CLK_NODE(g_ckgen_gating_istc_i_istc_clk),
    CLK_NODE(g_ckgen_gating_smc_clk_24m),
    CLK_NODE(g_ckgen_gating_xtrg_wdt_clk),
    CLK_NODE(g_ckgen_gating_ldo_dig_pclk),
    CLK_NODE(g_ckgen_gating_dcdc1_clk_24m),
    CLK_NODE(g_ckgen_gating_vic1_wdt_ref_clk),
    CLK_NODE(g_ckgen_gating_vic3a_wdt_ref_clk),
    CLK_NODE(g_ckgen_gating_vic3b_wdt_ref_clk),
    CLK_NODE(g_ckgen_gating_wdt1_main_clk),
    CLK_NODE(g_ckgen_gating_wdt2_main_clk),
    CLK_NODE(g_ckgen_gating_wdt5_main_clk),
    CLK_NODE(g_ckgen_gating_wdt6_main_clk),
    CLK_NODE(g_ckgen_gating_btm1_i_xtal24mhz_clk),
    CLK_NODE(g_ckgen_gating_btm2_i_xtal24mhz_clk),
    CLK_NODE(g_ckgen_gating_btm3_i_xtal24mhz_clk),
    CLK_NODE(g_ckgen_gating_btm4_i_xtal24mhz_clk),
    CLK_NODE(g_ckgen_gating_btm5_i_xtal24mhz_clk),
    CLK_NODE(g_ckgen_gating_btm6_i_xtal24mhz_clk),
    CLK_NODE(g_ckgen_gating_pt_sns_sf_dig_clk_24m),
    CLK_NODE(g_ckgen_gating_xspi_slv_aclk),
    CLK_NODE(g_ckgen_gating_vic_sp_irqsync),
    CLK_NODE(g_ckgen_gating_iramc4_aclk),
    CLK_NODE(g_ckgen_gating_wdt3_pclk),
    CLK_NODE(g_ckgen_gating_wdt3_bus_clk),
    CLK_NODE(g_ckgen_gating_wdt4_pclk),
    CLK_NODE(g_ckgen_gating_wdt4_bus_clk),
    CLK_NODE(g_ckgen_gating_ppc_apbmux5_pclk),
    CLK_NODE(g_ckgen_gating_apbmux5_pclk),
    CLK_NODE(g_ckgen_gating_xspi_slv_pclk),
    CLK_NODE(g_ckgen_gating_sp_mac_pclk),
    CLK_NODE(g_ckgen_gating_cr5_sp_mix_mac_pclk),
    CLK_NODE(g_ckgen_gating_eic_sp_i_pclk),
    CLK_NODE(g_ckgen_gating_cslite_pclkdbg),
    CLK_NODE(g_ckgen_gating_cslite_pclksys),
    CLK_NODE(g_ckgen_gating_apb_cr5sx0_dbg_slv_src_pclk),
    CLK_NODE(g_ckgen_gating_apb_cr5sx1_dbg_slv_src_pclk),
    CLK_NODE(g_ckgen_gating_apb_cr5sf_dbg_slv_src_pclk),
    CLK_NODE(g_ckgen_gating_wdt3_main_clk),
    CLK_NODE(g_ckgen_gating_wdt4_main_clk),
    CLK_NODE(g_ckgen_gating_vic2a_wdt_ref_clk),
    CLK_NODE(g_ckgen_gating_vic2b_wdt_ref_clk),
    CLK_NODE(g_ckgen_gating_rtc_pclk),
    CLK_NODE(g_ckgen_gating_ap_apmainclk),
    CLK_NODE(g_ckgen_gating_ap_perclk),
    CLK_NODE(g_ckgen_gating_ap_hsmperclk),
    CLK_NODE(g_ckgen_gating_ap_sdramclk),
    CLK_NODE(g_ckgen_gating_sehc1_aclk),
    CLK_NODE(g_ckgen_gating_sehc2_aclk),
    CLK_NODE(g_ckgen_gating_seip_sh_clk),
    CLK_NODE(g_ckgen_gating_apbmux6_pclk),
    CLK_NODE(g_ckgen_gating_gpio_ap_pclk),
    CLK_NODE(g_ckgen_gating_iomuxc_ap_pclk),
    CLK_NODE(g_ckgen_gating_ckgen_ap_pclk),
    CLK_NODE(g_ckgen_gating_sehc1_pclk),
    CLK_NODE(g_ckgen_gating_sehc2_pclk),
    CLK_NODE(g_ckgen_gating_rstgen_ap_pclk),
    CLK_NODE(g_ckgen_gating_wdt8_pclk),
    CLK_NODE(g_ckgen_gating_wdt8_bus_clk),
    CLK_NODE(g_ckgen_gating_ap_mac_pclk),
    CLK_NODE(g_ckgen_gating_vd_ap_pclk),
    CLK_NODE(g_ckgen_gating_pt_sns_ap_pclk),
    CLK_NODE(g_ckgen_gating_scr_ap_pclk),
    CLK_NODE(g_ckgen_gating_por_ap_pclk),
    CLK_NODE(g_ckgen_gating_seip_pclk),
    CLK_NODE(g_ckgen_gating_seip_hclk),
    CLK_NODE(g_ckgen_gating_seip_fd_ref_clk),
    CLK_NODE(g_ckgen_gating_sehc1_main_clk),
    CLK_NODE(g_ckgen_gating_sehc2_main_clk),
    CLK_NODE(g_ckgen_gating_pt_sns_ap_clkin),
    CLK_NODE(g_ckgen_gating_wdt8_main_clk),
    CLK_NODE(g_ckgen_gating_sehc1_cqe_sqs_clk),
    CLK_NODE(g_ckgen_gating_sehc2_cqe_sqs_clk),
    CLK_NODE(g_ckgen_gating_sehc1_tm_clk),
    CLK_NODE(g_ckgen_gating_sehc2_tm_clk),
    CLK_NODE(g_ckgen_gating_apbmux7_pclk),
};

const clk_node_t * const clk_disable_array[] = {
    CLK_NODE(g_ckgen_gating_sp_cr5_spclk),
    CLK_NODE(g_ckgen_gating_cr5_sp0_clkin),
    CLK_NODE(g_ckgen_gating_cr5_sp1_clkin),
    CLK_NODE(g_ckgen_gating_apb_mac_sp_slv_src_pclk),
    CLK_NODE(g_ckgen_gating_iramc3_aclk),
    CLK_NODE(g_ckgen_gating_iramc3_pclk),
    CLK_NODE(g_ckgen_gating_iramc4_aclk),
    CLK_NODE(g_ckgen_gating_iramc4_pclk),
    CLK_NODE(g_ckgen_gating_canfd1_pclk),
    CLK_NODE(g_ckgen_gating_canfd1_ipg_clk),
    CLK_NODE(g_ckgen_gating_canfd1_clk24m),
    CLK_NODE(g_ckgen_gating_canfd2_pclk),
    CLK_NODE(g_ckgen_gating_canfd2_ipg_clk),
    CLK_NODE(g_ckgen_gating_canfd2_clk24m),
    CLK_NODE(g_ckgen_gating_canfd17_pclk),
    CLK_NODE(g_ckgen_gating_canfd17_ipg_clk),
    CLK_NODE(g_ckgen_gating_canfd17_clk24m),
    CLK_NODE(g_ckgen_gating_canfd18_pclk),
    CLK_NODE(g_ckgen_gating_canfd18_ipg_clk),
    CLK_NODE(g_ckgen_gating_canfd18_clk24m),
    CLK_NODE(g_ckgen_gating_canfd19_pclk),
    CLK_NODE(g_ckgen_gating_canfd19_ipg_clk),
    CLK_NODE(g_ckgen_gating_canfd19_clk24m),
    CLK_NODE(g_ckgen_gating_canfd20_pclk),
    CLK_NODE(g_ckgen_gating_canfd20_ipg_clk),
    CLK_NODE(g_ckgen_gating_canfd20_clk24m),
    CLK_NODE(g_ckgen_gating_canfd22_pclk),
    CLK_NODE(g_ckgen_gating_canfd22_ipg_clk),
    CLK_NODE(g_ckgen_gating_canfd22_clk24m),
    CLK_NODE(g_ckgen_gating_canfd24_pclk),
    CLK_NODE(g_ckgen_gating_canfd24_ipg_clk),
    CLK_NODE(g_ckgen_gating_canfd24_clk24m),
    CLK_NODE(g_ckgen_gating_saci1_pclk),
    CLK_NODE(g_ckgen_gating_saci1_i2s_mclk),
    CLK_NODE(g_ckgen_gating_saci1_ext_clk),
    CLK_NODE(g_ckgen_gating_saci1_i2s_tx_clk),
    CLK_NODE(g_ckgen_gating_saci1_i2s_rx_clk),
    CLK_NODE(g_ckgen_gating_saci1_pdm_per_clk),
    CLK_NODE(g_ckgen_gating_csi_axi_clk),
    CLK_NODE(g_ckgen_gating_csi_pclk),
    CLK_NODE(g_ckgen_gating_csi_proc_clk),
    CLK_NODE(g_ckgen_gating_g2d_axi_clk),
    CLK_NODE(g_ckgen_gating_lvds_ch0_clk_x14),
    CLK_NODE(g_ckgen_gating_lvds_ch0_clk_x7),
    CLK_NODE(g_ckgen_gating_sdramc_pclk),
    CLK_NODE(g_ckgen_gating_sdramc_aclk),
    CLK_NODE(g_ckgen_gating_dc_axi_clk),
    CLK_NODE(g_ckgen_gating_dc_pix_clk),
    CLK_NODE(g_ckgen_gating_dc_dsp_clk),
    CLK_NODE(g_ckgen_gating_gama1_hclk),
    CLK_NODE(g_ckgen_gating_gama1_aclk),
    CLK_NODE(g_ckgen_gating_ahb_syncup_gama1_mainclk),
    CLK_NODE(g_ckgen_gating_dma_ap_clk),
    CLK_NODE(g_ckgen_gating_dma_ap_aclk),
    CLK_NODE(g_ckgen_gating_dma_ap_hclk),
    CLK_NODE(g_ckgen_gating_dma_ap_pclk),
    CLK_NODE(g_ckgen_gating_mb_clk),
    CLK_NODE(g_ckgen_gating_flexray1_hclk),
    CLK_NODE(g_ckgen_gating_flexray1_ipg_clk),
    CLK_NODE(g_ckgen_gating_flexray2_hclk),
    CLK_NODE(g_ckgen_gating_flexray2_ipg_clk),
    CLK_NODE(g_ckgen_gating_canfd3_pclk),
    CLK_NODE(g_ckgen_gating_canfd3_ipg_clk),
    CLK_NODE(g_ckgen_gating_canfd3_clk24m),
    CLK_NODE(g_ckgen_gating_canfd4_pclk),
    CLK_NODE(g_ckgen_gating_canfd4_ipg_clk),
    CLK_NODE(g_ckgen_gating_canfd4_clk24m),
    CLK_NODE(g_ckgen_gating_canfd5_pclk),
    CLK_NODE(g_ckgen_gating_canfd5_ipg_clk),
    CLK_NODE(g_ckgen_gating_canfd5_clk24m),
    CLK_NODE(g_ckgen_gating_canfd6_pclk),
    CLK_NODE(g_ckgen_gating_canfd6_ipg_clk),
    CLK_NODE(g_ckgen_gating_canfd6_clk24m),
    CLK_NODE(g_ckgen_gating_canfd9_pclk),
    CLK_NODE(g_ckgen_gating_canfd9_ipg_clk),
    CLK_NODE(g_ckgen_gating_canfd9_clk24m),
    CLK_NODE(g_ckgen_gating_canfd10_pclk),
    CLK_NODE(g_ckgen_gating_canfd10_ipg_clk),
    CLK_NODE(g_ckgen_gating_canfd10_clk24m),
    CLK_NODE(g_ckgen_gating_canfd11_pclk),
    CLK_NODE(g_ckgen_gating_canfd11_ipg_clk),
    CLK_NODE(g_ckgen_gating_canfd11_clk24m),
    CLK_NODE(g_ckgen_gating_canfd12_pclk),
    CLK_NODE(g_ckgen_gating_canfd12_ipg_clk),
    CLK_NODE(g_ckgen_gating_canfd12_clk24m),
    CLK_NODE(g_ckgen_gating_canfd13_pclk),
    CLK_NODE(g_ckgen_gating_canfd13_ipg_clk),
    CLK_NODE(g_ckgen_gating_canfd13_clk24m),
    CLK_NODE(g_ckgen_gating_canfd14_pclk),
    CLK_NODE(g_ckgen_gating_canfd14_ipg_clk),
    CLK_NODE(g_ckgen_gating_canfd14_clk24m),
    CLK_NODE(g_ckgen_gating_canfd15_pclk),
    CLK_NODE(g_ckgen_gating_canfd15_ipg_clk),
    CLK_NODE(g_ckgen_gating_canfd15_clk24m),
    CLK_NODE(g_ckgen_gating_canfd16_pclk),
    CLK_NODE(g_ckgen_gating_canfd16_ipg_clk),
    CLK_NODE(g_ckgen_gating_canfd16_clk24m),
    CLK_NODE(g_ckgen_gating_canfd21_pclk),
    CLK_NODE(g_ckgen_gating_canfd21_ipg_clk),
    CLK_NODE(g_ckgen_gating_canfd21_clk24m),
    CLK_NODE(g_ckgen_gating_canfd23_pclk),
    CLK_NODE(g_ckgen_gating_canfd23_ipg_clk),
    CLK_NODE(g_ckgen_gating_canfd23_clk24m),
    CLK_NODE(g_ckgen_gating_xtrg_clk),
    CLK_NODE(g_ckgen_gating_xtrg_pclk),
    CLK_NODE(g_ckgen_gating_vic2a_hclk),
    CLK_NODE(g_ckgen_gating_vic2b_hclk),
    CLK_NODE(g_ckgen_gating_vic3a_hclk),
    CLK_NODE(g_ckgen_gating_vic3b_hclk),
    CLK_NODE(g_ckgen_gating_i2c2_sclk),
    CLK_NODE(g_ckgen_gating_i2c2_pclk),
    CLK_NODE(g_ckgen_gating_i2c3_sclk),
    CLK_NODE(g_ckgen_gating_i2c3_pclk),
    CLK_NODE(g_ckgen_gating_i2c4_sclk),
    CLK_NODE(g_ckgen_gating_i2c4_pclk),
    CLK_NODE(g_ckgen_gating_i2c5_sclk),
    CLK_NODE(g_ckgen_gating_i2c5_pclk),
    CLK_NODE(g_ckgen_gating_i2c6_sclk),
    CLK_NODE(g_ckgen_gating_i2c6_pclk),
    CLK_NODE(g_ckgen_gating_i2c7_sclk),
    CLK_NODE(g_ckgen_gating_i2c7_pclk),
    CLK_NODE(g_ckgen_gating_i2c8_sclk),
    CLK_NODE(g_ckgen_gating_i2c8_pclk),
    CLK_NODE(g_ckgen_gating_spi1_pclk),
    CLK_NODE(g_ckgen_gating_spi1_spi_per_clk),
    CLK_NODE(g_ckgen_gating_spi2_pclk),
    CLK_NODE(g_ckgen_gating_spi2_spi_per_clk),
    CLK_NODE(g_ckgen_gating_spi3_pclk),
    CLK_NODE(g_ckgen_gating_spi3_spi_per_clk),
    CLK_NODE(g_ckgen_gating_spi4_pclk),
    CLK_NODE(g_ckgen_gating_spi4_spi_per_clk),
    CLK_NODE(g_ckgen_gating_spi5_pclk),
    CLK_NODE(g_ckgen_gating_spi5_spi_per_clk),
    CLK_NODE(g_ckgen_gating_spi6_pclk),
    CLK_NODE(g_ckgen_gating_spi6_spi_per_clk),
    CLK_NODE(g_ckgen_gating_spi8_pclk),
    CLK_NODE(g_ckgen_gating_spi8_spi_per_clk),
    CLK_NODE(g_ckgen_gating_uart1_sclk),
    CLK_NODE(g_ckgen_gating_uart1_pclk),
    CLK_NODE(g_ckgen_gating_uart2_sclk),
    CLK_NODE(g_ckgen_gating_uart2_pclk),
    CLK_NODE(g_ckgen_gating_uart3_sclk),
    CLK_NODE(g_ckgen_gating_uart3_pclk),
    CLK_NODE(g_ckgen_gating_uart4_sclk),
    CLK_NODE(g_ckgen_gating_uart4_pclk),
    CLK_NODE(g_ckgen_gating_uart5_sclk),
    CLK_NODE(g_ckgen_gating_uart5_pclk),
    CLK_NODE(g_ckgen_gating_uart6_sclk),
    CLK_NODE(g_ckgen_gating_uart6_pclk),
    CLK_NODE(g_ckgen_gating_uart7_sclk),
    CLK_NODE(g_ckgen_gating_uart7_pclk),
    CLK_NODE(g_ckgen_gating_uart8_sclk),
    CLK_NODE(g_ckgen_gating_uart8_pclk),
    CLK_NODE(g_ckgen_gating_uart9_sclk),
    CLK_NODE(g_ckgen_gating_uart9_pclk),
    CLK_NODE(g_ckgen_gating_uart10_sclk),
    CLK_NODE(g_ckgen_gating_uart10_pclk),
    CLK_NODE(g_ckgen_gating_uart11_sclk),
    CLK_NODE(g_ckgen_gating_uart11_pclk),
    CLK_NODE(g_ckgen_gating_uart12_sclk),
    CLK_NODE(g_ckgen_gating_uart12_pclk),
    CLK_NODE(g_ckgen_gating_uart13_sclk),
    CLK_NODE(g_ckgen_gating_uart13_pclk),
    CLK_NODE(g_ckgen_gating_uart14_sclk),
    CLK_NODE(g_ckgen_gating_uart14_pclk),
    CLK_NODE(g_ckgen_gating_uart15_sclk),
    CLK_NODE(g_ckgen_gating_uart15_pclk),
    CLK_NODE(g_ckgen_gating_uart16_sclk),
    CLK_NODE(g_ckgen_gating_uart16_pclk),
    CLK_NODE(g_ckgen_gating_etmr2_pclk),
    CLK_NODE(g_ckgen_gating_etmr2_ahf_clk),
    CLK_NODE(g_ckgen_gating_etmr2_hf_clk),
    CLK_NODE(g_ckgen_gating_etmr3_pclk),
    CLK_NODE(g_ckgen_gating_etmr3_ahf_clk),
    CLK_NODE(g_ckgen_gating_etmr3_hf_clk),
    CLK_NODE(g_ckgen_gating_etmr4_pclk),
    CLK_NODE(g_ckgen_gating_etmr4_ahf_clk),
    CLK_NODE(g_ckgen_gating_etmr4_hf_clk),
    CLK_NODE(g_ckgen_gating_epwm1_pclk),
    CLK_NODE(g_ckgen_gating_epwm1_ahf_clk),
    CLK_NODE(g_ckgen_gating_epwm1_hf_clk),
    CLK_NODE(g_ckgen_gating_epwm2_pclk),
    CLK_NODE(g_ckgen_gating_epwm2_ahf_clk),
    CLK_NODE(g_ckgen_gating_epwm2_hf_clk),
    CLK_NODE(g_ckgen_gating_epwm3_pclk),
    CLK_NODE(g_ckgen_gating_epwm3_ahf_clk),
    CLK_NODE(g_ckgen_gating_epwm3_hf_clk),
    CLK_NODE(g_ckgen_gating_epwm4_pclk),
    CLK_NODE(g_ckgen_gating_epwm4_ahf_clk),
    CLK_NODE(g_ckgen_gating_epwm4_hf_clk),
    CLK_NODE(g_ckgen_gating_sadc1_pclk),
    CLK_NODE(g_ckgen_gating_sadc1_ctrl_clk),
    CLK_NODE(g_ckgen_gating_sadc2_pclk),
    CLK_NODE(g_ckgen_gating_sadc2_ctrl_clk),
    CLK_NODE(g_ckgen_gating_sadc3_pclk),
    CLK_NODE(g_ckgen_gating_sadc3_ctrl_clk),
    CLK_NODE(g_ckgen_gating_adma_enet1_dmaclk),
    CLK_NODE(g_ckgen_gating_enet1_ref_clk_tx),
    CLK_NODE(g_ckgen_gating_enet1_ptp_ref_clk),
    CLK_NODE(g_ckgen_gating_enet1_aclk),
    CLK_NODE(g_ckgen_gating_enet1_clk_csr),
    CLK_NODE(g_ckgen_gating_adma_enet1_perclk),
    CLK_NODE(g_ckgen_gating_adma_enet2_dmaclk),
    CLK_NODE(g_ckgen_gating_enet2_ptp_ref_clk),
    CLK_NODE(g_ckgen_gating_enet2_ref_clk_tx),
    CLK_NODE(g_ckgen_gating_enet2_aclk),
    CLK_NODE(g_ckgen_gating_enet2_clk_csr),
    CLK_NODE(g_ckgen_gating_adma_enet2_perclk),
    CLK_NODE(g_ckgen_gating_dma_sf_clk0),
    CLK_NODE(g_ckgen_gating_dma_sf_clk1),
    CLK_NODE(g_ckgen_gating_dma_sf_aclk0),
    CLK_NODE(g_ckgen_gating_dma_sf_aclk1),
    CLK_NODE(g_ckgen_gating_dma_sf_hclk0),
    CLK_NODE(g_ckgen_gating_dma_sf_hclk1),
    CLK_NODE(g_ckgen_gating_dma_sf_pclk0),
    CLK_NODE(g_ckgen_gating_dma_sf_pclk1),
    CLK_NODE(g_ckgen_gating_usb_phy_ref_clk),
    CLK_NODE(g_ckgen_gating_usb2_pclk),
};

#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

uint32 Mcu_GetClkPrepareArraySize(void)
{
    return sizeof(clk_prepare_array) / sizeof(clk_prepare_array[0]);
}

uint32 Mcu_GetClkEnableArraySize(void)
{
    return sizeof(clk_enable_array) / sizeof(clk_enable_array[0]);
}

uint32 Mcu_GetClkDisableArraySize(void)
{
    return sizeof(clk_disable_array) / sizeof(clk_disable_array[0]);
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
};
#endif
