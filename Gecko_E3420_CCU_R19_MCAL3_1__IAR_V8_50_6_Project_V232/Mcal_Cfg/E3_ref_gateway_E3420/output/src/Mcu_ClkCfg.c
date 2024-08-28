/** *****************************************************************************************************
 * SEMIDRIVE Copyright Statement                                                                        *
 * Copyright (c) SEMIDRIVE. All rights reserved                                                         *
 *                                                                                                      *
 * This software and all rights therein are owned by SEMIDRIVE, and are                                 *
 * protected by copyright law and other relevant laws, regulations and                                  *
 * protection. Without SEMIDRIVE's prior written consent and/or related rights,                         *
 * please do not use this software or any potion thereof in any form or by any                          *
 * means. You may not reproduce, modify or distribute this software except in                           *
 * compliance with the License. Unless required by applicable law or agreed to                          *
 * in writing, software distributed under the License is distributed on                                 *
 * an 'AS IS' basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.                         *
 *                                                                                                      *
 *******************************************************************************************************/
/** *****************************************************************************************************
 * \file     Mcu_ClkCfg.c                                                                               *
 * \brief    AUTOSAR 4.3.1 MCAL Mcu Driver                                                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2024-03-08 16:29:00     <td>1.0.0                                                                *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "RegBase.h"
#include "Mcu_CkgenDrv.h"
#include "Mcu_Cfg.h"
#include "Mcu_PllDrv.h"
#include "Mcu_ClkCfgNd.h"

#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"
/* PRQA S 0691,1504,1751,1531,1533 EOF */


static Mcu_ClkCoreType g_pll1_core = {
    .base = APB_PLL1_BASE,
    .ops = &Mcu_PllOps,
};

static Mcu_ClkCoreType g_pll2_core = {
    .base = APB_PLL2_BASE,
    .ops = &Mcu_PllOps,
};

static Mcu_ClkCoreType g_pll3_core = {
    .base = APB_PLL3_BASE,
    .ops = &Mcu_PllOps,
};

static Mcu_ClkCoreType g_sf_bus_core = {
    .base = APB_CKGEN_SF_BASE,
    .ops = &Mcu_ClkBusOps,
};

static Mcu_ClkCoreType g_sf_core_core = {
    .base = APB_CKGEN_SF_BASE,
    .ops = &Mcu_ClkCoreOps,
};

static Mcu_ClkCoreType g_sf_ip_core = {
    .base = APB_CKGEN_SF_BASE,
    .ops = &Mcu_ClkIpOps,
};

static Mcu_ClkCoreType Mcu_ClkSfGatingCore = {
    .base = APB_CKGEN_SF_BASE,
    .ops = &Mcu_ClkGatingOps,
};

static Mcu_ClkCoreType g_pll4_core = {
    .base = APB_PLL4_BASE,
    .ops = &Mcu_PllOps,
};

static Mcu_ClkCoreType g_pll5_core = {
    .base = APB_PLL5_BASE,
    .ops = &Mcu_PllOps,
};

static Mcu_ClkCoreType g_pll_lvds_core = {
    .base = APB_PLL_LVDS_BASE,
    .ops = &Mcu_PllOps,
};

static Mcu_ClkCoreType g_ap_bus_core = {
    .base = APB_CKGEN_AP_BASE,
    .ops = &Mcu_ClkBusOps,
};

static Mcu_ClkCoreType g_ap_ip_core = {
    .base = APB_CKGEN_AP_BASE,
    .ops = &Mcu_ClkIpOps,
};

static Mcu_ClkCoreType Mcu_ClkApGatingCore = {
    .base = APB_CKGEN_AP_BASE,
    .ops = &Mcu_ClkGatingOps,
};

Mcu_PllNodeType g_rc_24m = {
    .clkNode = {
        .core = NULL_PTR,
        .id = 0x0,
        .rate = 24000000,
        .parent = NULL_PTR,
    },
};

Mcu_PllNodeType g_fs_24m = {
    .clkNode = {
        .core = NULL_PTR,
        .id = 0x0,
        .rate = 24000000,
        .parent = NULL_PTR,
    },
};

Mcu_PllNodeType g_pll1_root = {
    .clkNode = {
        .core = &g_pll1_core,
        .id = 0x0,
        .rate = 500000000,
        .parent = CLK_NODE(g_fs_24m),
#ifdef MCU_pll1_DSM_EN
        .dsm_en = TRUE,
#endif /**#ifdef MCU_pll1_DSM_EN*/
    },
};

Mcu_PllNodeType g_pll2_root = {
    .clkNode = {
        .core = &g_pll2_core,
        .id = 0x0,
        .rate = 600000000,
        .parent = CLK_NODE(g_fs_24m),
#ifdef MCU_pll2_DSM_EN
        .dsm_en = TRUE,
#endif /**#ifdef MCU_pll2_DSM_EN*/
    },
};

Mcu_PllNodeType g_pll3_root = {
    .clkNode = {
        .core = &g_pll3_core,
        .id = 0x0,
        .rate = 667000000,
        .parent = CLK_NODE(g_fs_24m),
#ifdef MCU_pll3_DSM_EN
        .dsm_en = TRUE,
#endif /**#ifdef MCU_pll3_DSM_EN*/
    },
};

Mcu_PllNodeType g_pll4_root = {
    .clkNode = {
        .core = &g_pll4_core,
        .id = 0x0,
        .rate = 600000000,
        .parent = CLK_NODE(g_fs_24m),
#ifdef MCU_pll4_DSM_EN
        .dsm_en = TRUE,
#endif /**#ifdef MCU_pll4_DSM_EN*/
    },
};

Mcu_PllNodeType g_pll5_root = {
    .clkNode = {
        .core = &g_pll5_core,
        .id = 0x0,
        .rate = 786432000,
        .parent = CLK_NODE(g_fs_24m),
#ifdef MCU_pll5_DSM_EN
        .dsm_en = TRUE,
#endif /**#ifdef MCU_pll5_DSM_EN*/
    },
};

Mcu_PllNodeType g_pll_lvds_root = {
    .clkNode = {
        .core = &g_pll_lvds_core,
        .id = 0x0,
        .rate = 600000000,
        .parent = CLK_NODE(g_fs_24m),
#ifdef MCU_pll_lvds_DSM_EN
        .dsm_en = TRUE,
#endif /**#ifdef MCU_pll_lvds_DSM_EN*/
    },
};

Mcu_PllNodeType g_pll_lvds_nodiv = {
    .clkNode = {
        .core = &g_pll_lvds_core,
        .id = 0x1,
        .rate = 600000000,
        .parent = CLK_NODE(g_pll_lvds_root),
    },
};

Mcu_PllNodeType g_pll_lvds_div2 = {
    .clkNode = {
        .core = &g_pll_lvds_core,
        .id = 0x2,
        .rate = 300000000,
        .parent = CLK_NODE(g_pll_lvds_root),
    },
};

Mcu_PllNodeType g_pll_lvds_div7 = {
    .clkNode = {
        .core = &g_pll_lvds_core,
        .id = 0x3,
        .rate = 42857143,
        .parent = CLK_NODE(g_pll_lvds_div2),
    },
};

Mcu_PllNodeType g_pll_lvds_ckgen = {
    .clkNode = {
        .core = &g_pll_lvds_core,
        .id = 0x4,
        .rate = 300000000,
        .parent = CLK_NODE(g_pll_lvds_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_cr5_sf_div_root_preset = {
    .clkNode = {
        .core = &g_sf_bus_core,
        .id = 0x1000000,
        .rate = 24000000,
        .mux = 1,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_cr5_sp_div_root_preset = {
    .clkNode = {
        .core = &g_sf_bus_core,
        .id = 0x1000001,
        .rate = 24000000,
        .mux = 1,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_sf_test_div_root_preset = {
    .clkNode = {
        .core = &g_sf_bus_core,
        .id = 0x1000002,
        .rate = 24000000,
        .mux = 1,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll2_root),
        .parents[4] = CLK_NODE(g_pll3_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_ap_bus_div_root_preset = {
    .clkNode = {
        .core = &g_ap_bus_core,
        .id = 0x1000000,
        .rate = 24000000,
        .mux = 1,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll_lvds_ckgen),
        .parents[4] = CLK_NODE(g_pll5_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_disp_bus_div_root_preset = {
    .clkNode = {
        .core = &g_ap_bus_core,
        .id = 0x1000001,
        .rate = 24000000,
        .mux = 1,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll_lvds_ckgen),
        .parents[4] = CLK_NODE(g_pll5_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_seip_div_root_preset = {
    .clkNode = {
        .core = &g_ap_bus_core,
        .id = 0x1000002,
        .rate = 24000000,
        .mux = 1,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll_lvds_ckgen),
        .parents[4] = CLK_NODE(g_pll5_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_cr5_sf_div_root = {
    .clkNode = {
        .core = &g_sf_bus_core,
        .id = 0x1000000,
        .rate = 600000000,
        .mux = 4,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};
Mcu_CkgenNodeType g_ckgen_bus_cr5_sf_div_m = {
    .clkNode = {
        .core = &g_sf_bus_core,
        .id = 0x2000000,
        .rate = 600000000,
        .mux = 0,
        .parentsNum = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_cr5_sf_div_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_cr5_sf_div_n = {
    .clkNode = {
        .core = &g_sf_bus_core,
        .id = 0x3000000,
        .rate = 300000000,
        .mux = 0,
        .parentsNum = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_cr5_sf_div_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_cr5_sf_div_p = {
    .clkNode = {
        .core = &g_sf_bus_core,
        .id = 0x4000000,
        .rate = 150000000,
        .mux = 0,
        .parentsNum = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_cr5_sf_div_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_cr5_sf_div_q = {
    .clkNode = {
        .core = &g_sf_bus_core,
        .id = 0x5000000,
        .rate = 150000000,
        .mux = 0,
        .parentsNum = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_cr5_sf_div_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_cr5_sf_div_ratio = {
    .clkNode = {
        .core = &g_sf_bus_core,
        .id = 0x6000000,
        .rate = 1,
        .mux = 0,
        .parentsNum = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_cr5_sf_div_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_cr5_sf_root = {
    .clkNode = {
        .core = &g_sf_bus_core,
        .id = 0x0,
        .rate = 600000000,
        .mux = 0,
        .parentsNum = 2,
        .parents[0] = CLK_NODE(g_ckgen_bus_cr5_sf_div_m),
        .parents[1] = CLK_NODE(g_pll2_root),
    },
};
Mcu_CkgenNodeType g_ckgen_bus_cr5_sp_div_root = {
    .clkNode = {
        .core = &g_sf_bus_core,
        .id = 0x1000001,
        .rate = 600000000,
        .mux = 4,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_cr5_sp_div_m = {
    .clkNode = {
        .core = &g_sf_bus_core,
        .id = 0x2000001,
        .rate = 600000000,
        .mux = 0,
        .parentsNum = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_cr5_sp_div_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_cr5_sp_div_n = {
    .clkNode = {
        .core = &g_sf_bus_core,
        .id = 0x3000001,
        .rate = 300000000,
        .mux = 0,
        .parentsNum = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_cr5_sp_div_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_cr5_sp_div_p = {
    .clkNode = {
        .core = &g_sf_bus_core,
        .id = 0x4000001,
        .rate = 150000000,
        .mux = 0,
        .parentsNum = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_cr5_sp_div_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_cr5_sp_div_q = {
    .clkNode = {
        .core = &g_sf_bus_core,
        .id = 0x5000001,
        .rate = 150000000,
        .mux = 0,
        .parentsNum = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_cr5_sp_div_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_cr5_sp_div_ratio = {
    .clkNode = {
        .core = &g_sf_bus_core,
        .id = 0x7000001,
        .rate = 1,
        .mux = 0,
        .parentsNum = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_cr5_sp_div_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_cr5_sp_root = {
    .clkNode = {
        .core = &g_sf_bus_core,
        .id = 0x1,
        .rate = 600000000,
        .mux = 0,
        .parentsNum = 2,
        .parents[0] = CLK_NODE(g_ckgen_bus_cr5_sp_div_m),
        .parents[1] = CLK_NODE(g_pll2_root),
    },
};
Mcu_CkgenNodeType g_ckgen_core_cr5_sx_preset = {
    .clkNode = {
        .core = &g_sf_core_core,
        .id = 0x0,
        .rate = 24000000,
        .mux = 1,
        .parentsNum = 2,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
    },
};
Mcu_CkgenNodeType g_ckgen_core_cr5_sx = {
    .clkNode = {
        .core = &g_sf_core_core,
        .id = 0x0,
        .rate = 600000000,
        .mux = 4,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_i2c_sf_1_to_4 = {
    .clkNode = {
        .core = &g_sf_ip_core,
        .id = 0x0,
        .rate = 133200000,
        .mux = 3,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_i2c_sf_5_to_8 = {
    .clkNode = {
        .core = &g_sf_ip_core,
        .id = 0x1,
        .rate = 133200000,
        .mux = 3,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_spi_sf_1_to_4 = {
    .clkNode = {
        .core = &g_sf_ip_core,
        .id = 0x2,
        .rate = 100000000,
        .mux = 2,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_spi_sf_5_to_8 = {
    .clkNode = {
        .core = &g_sf_ip_core,
        .id = 0x3,
        .rate = 100000000,
        .mux = 2,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_uart_sf_1_to_8 = {
    .clkNode = {
        .core = &g_sf_ip_core,
        .id = 0x4,
        .rate = 83380000,
        .mux = 3,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_uart_sf_9_to_16 = {
    .clkNode = {
        .core = &g_sf_ip_core,
        .id = 0x5,
        .rate = 83380000,
        .mux = 3,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_enet1_tx = {
    .clkNode = {
        .core = &g_sf_ip_core,
        .id = 0x6,
        .rate = 250000000,
        .mux = 4,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll2_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll1_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_enet1_rmii = {
    .clkNode = {
        .core = &g_sf_ip_core,
        .id = 0x7,
        .rate = 50000000,
        .mux = 4,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll2_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll1_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_enet1_phy_ref = {
    .clkNode = {
        .core = &g_sf_ip_core,
        .id = 0x8,
        .rate = 125000000,
        .mux = 4,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll2_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll1_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_enet1_timer_sec = {
    .clkNode = {
        .core = &g_sf_ip_core,
        .id = 0x9,
        .rate = 250000000,
        .mux = 4,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll2_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll1_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_enet2_tx = {
    .clkNode = {
        .core = &g_sf_ip_core,
        .id = 0xa,
        .rate = 250000000,
        .mux = 4,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll2_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll1_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_enet2_rmii = {
    .clkNode = {
        .core = &g_sf_ip_core,
        .id = 0xb,
        .rate = 50000000,
        .mux = 4,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll2_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll1_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_enet2_phy_ref = {
    .clkNode = {
        .core = &g_sf_ip_core,
        .id = 0xc,
        .rate = 125000000,
        .mux = 4,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll2_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll1_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_xspi1a = {
    .clkNode = {
        .core = &g_sf_ip_core,
        .id = 0xd,
        .rate = 200000000,
        .mux = 4,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_xspi1b = {
    .clkNode = {
        .core = &g_sf_ip_core,
        .id = 0xe,
        .rate = 200000000,
        .mux = 4,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_xspi2a = {
    .clkNode = {
        .core = &g_sf_ip_core,
        .id = 0xf,
        .rate = 333500000,
        .mux = 3,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_xspi2b = {
    .clkNode = {
        .core = &g_sf_ip_core,
        .id = 0x10,
        .rate = 333500000,
        .mux = 3,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_xtrg = {
    .clkNode = {
        .core = &g_sf_ip_core,
        .id = 0x11,
        .rate = 200000000,
        .mux = 4,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_etmr1 = {
    .clkNode = {
        .core = &g_sf_ip_core,
        .id = 0x12,
        .rate = 200000000,
        .mux = 4,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_etmr2 = {
    .clkNode = {
        .core = &g_sf_ip_core,
        .id = 0x13,
        .rate = 200000000,
        .mux = 4,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_etmr3 = {
    .clkNode = {
        .core = &g_sf_ip_core,
        .id = 0x14,
        .rate = 200000000,
        .mux = 4,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_etmr4 = {
    .clkNode = {
        .core = &g_sf_ip_core,
        .id = 0x15,
        .rate = 200000000,
        .mux = 4,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_epwm1 = {
    .clkNode = {
        .core = &g_sf_ip_core,
        .id = 0x16,
        .rate = 200000000,
        .mux = 4,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_epwm2 = {
    .clkNode = {
        .core = &g_sf_ip_core,
        .id = 0x17,
        .rate = 200000000,
        .mux = 4,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_epwm3 = {
    .clkNode = {
        .core = &g_sf_ip_core,
        .id = 0x18,
        .rate = 200000000,
        .mux = 4,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_epwm4 = {
    .clkNode = {
        .core = &g_sf_ip_core,
        .id = 0x19,
        .rate = 200000000,
        .mux = 4,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};
#ifdef MCU_CLK_CAN24M_ENABLE
Mcu_CkgenNodeType g_ckgen_ip_can = {
    .clkNode = {
        .core = &g_sf_ip_core,
        .id = 0x1a,
        .rate = 24000000,
        .mux = 1,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};
#else
Mcu_CkgenNodeType g_ckgen_ip_can = {
    .clkNode = {
        .core = &g_sf_ip_core,
        .id = 0x1a,
        .rate = 40000000,
        .mux = 4,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};
#endif /**#ifdef MCU_CLK_CAN24M_ENABLE*/


Mcu_CkgenNodeType g_ckgen_ip_adc1 = {
    .clkNode = {
        .core = &g_sf_ip_core,
        .id = 0x1b,
        .rate = 166670000,
        .mux = 2,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_adc2 = {
    .clkNode = {
        .core = &g_sf_ip_core,
        .id = 0x1c,
        .rate = 166670000,
        .mux = 2,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_adc3 = {
    .clkNode = {
        .core = &g_sf_ip_core,
        .id = 0x1d,
        .rate = 166670000,
        .mux = 2,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_acmp = {
    .clkNode = {
        .core = &g_sf_ip_core,
        .id = 0x1e,
        .rate = 166670000,
        .mux = 2,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_flexray = {
    .clkNode = {
        .core = &g_sf_ip_core,
        .id = 0x1f,
        .rate = 40000000,
        .mux = 2,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll2_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll1_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_ioc = {
    .clkNode = {
        .core = &g_sf_ip_core,
        .id = 0x20,
        .rate = 50000000,
        .mux = 4,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_pt_sns_sf = {
    .clkNode = {
        .core = &g_sf_ip_core,
        .id = 0x21,
        .rate = 100000,
        .mux = 1,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll3_root),
        .parents[4] = CLK_NODE(g_pll2_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_sf_test_div_root = {
    .clkNode = {
        .core = &g_sf_bus_core,
        .id = 0x1000002,
        .rate = 500000000,
        .mux = 2,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll1_root),
        .parents[3] = CLK_NODE(g_pll2_root),
        .parents[4] = CLK_NODE(g_pll3_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_sf_test_div_m = {
    .clkNode = {
        .core = &g_sf_bus_core,
        .id = 0x2000002,
        .rate = 100000000,
        .mux = 0,
        .parentsNum = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_sf_test_div_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_sf_test_div_n = {
    .clkNode = {
        .core = &g_sf_bus_core,
        .id = 0x3000002,
        .rate = 83380000,
        .mux = 0,
        .parentsNum = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_sf_test_div_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_sf_test_div_p = {
    .clkNode = {
        .core = &g_sf_bus_core,
        .id = 0x4000002,
        .rate = 83380000,
        .mux = 0,
        .parentsNum = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_sf_test_div_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_sf_test_div_q = {
    .clkNode = {
        .core = &g_sf_bus_core,
        .id = 0x5000002,
        .rate = 83380000,
        .mux = 0,
        .parentsNum = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_sf_test_div_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_sf_test_root = {
    .clkNode = {
        .core = &g_sf_bus_core,
        .id = 0x2,
        .rate = 100000000,
        .mux = 0,
        .parentsNum = 2,
        .parents[0] = CLK_NODE(g_ckgen_bus_sf_test_div_m),
        .parents[1] = CLK_NODE(g_pll3_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_ap_bus_div_root = {
    .clkNode = {
        .core = &g_ap_bus_core,
        .id = 0x1000000,
        .rate = 24000000,
        .mux = 1,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll_lvds_ckgen),
        .parents[4] = CLK_NODE(g_pll5_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_ap_bus_div_m = {
    .clkNode = {
        .core = &g_ap_bus_core,
        .id = 0x2000000,
        .rate = 24000000,
        .mux = 0,
        .parentsNum = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_ap_bus_div_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_ap_bus_div_n = {
    .clkNode = {
        .core = &g_ap_bus_core,
        .id = 0x3000000,
        .rate = 24000000,
        .mux = 0,
        .parentsNum = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_ap_bus_div_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_ap_bus_div_p = {
    .clkNode = {
        .core = &g_ap_bus_core,
        .id = 0x4000000,
        .rate = 12000000,
        .mux = 0,
        .parentsNum = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_ap_bus_div_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_ap_bus_div_q = {
    .clkNode = {
        .core = &g_ap_bus_core,
        .id = 0x5000000,
        .rate = 12000000,
        .mux = 0,
        .parentsNum = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_ap_bus_div_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_ap_bus_root = {
    .clkNode = {
        .core = &g_ap_bus_core,
        .id = 0x0,
        .rate = 24000000,
        .mux = 0,
        .parentsNum = 2,
        .parents[0] = CLK_NODE(g_ckgen_bus_ap_bus_div_m),
        .parents[1] = CLK_NODE(g_pll5_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_disp_bus_div_root = {
    .clkNode = {
        .core = &g_ap_bus_core,
        .id = 0x1000001,
        .rate = 300000000,
        .mux = 2,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll_lvds_ckgen),
        .parents[4] = CLK_NODE(g_pll5_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_disp_bus_div_m = {
    .clkNode = {
        .core = &g_ap_bus_core,
        .id = 0x2000001,
        .rate = 300000000,
        .mux = 0,
        .parentsNum = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_disp_bus_div_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_disp_bus_div_n = {
    .clkNode = {
        .core = &g_ap_bus_core,
        .id = 0x3000001,
        .rate = 300000000,
        .mux = 0,
        .parentsNum = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_disp_bus_div_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_disp_bus_div_p = {
    .clkNode = {
        .core = &g_ap_bus_core,
        .id = 0x4000001,
        .rate = 150000000,
        .mux = 0,
        .parentsNum = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_disp_bus_div_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_disp_bus_div_q = {
    .clkNode = {
        .core = &g_ap_bus_core,
        .id = 0x5000001,
        .rate = 150000000,
        .mux = 0,
        .parentsNum = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_disp_bus_div_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_disp_bus_root = {
    .clkNode = {
        .core = &g_ap_bus_core,
        .id = 0x1,
        .rate = 300000000,
        .mux = 0,
        .parentsNum = 2,
        .parents[0] = CLK_NODE(g_ckgen_bus_disp_bus_div_m),
        .parents[1] = CLK_NODE(g_pll5_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_seip_div_root = {
    .clkNode = {
        .core = &g_ap_bus_core,
        .id = 0x1000002,
        .rate = 300000000,
        .mux = 2,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll_lvds_ckgen),
        .parents[4] = CLK_NODE(g_pll5_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_seip_div_m = {
    .clkNode = {
        .core = &g_ap_bus_core,
        .id = 0x2000002,
        .rate = 300000000,
        .mux = 0,
        .parentsNum = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_seip_div_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_seip_div_n = {
    .clkNode = {
        .core = &g_ap_bus_core,
        .id = 0x3000002,
        .rate = 300000000,
        .mux = 0,
        .parentsNum = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_seip_div_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_seip_div_p = {
    .clkNode = {
        .core = &g_ap_bus_core,
        .id = 0x4000002,
        .rate = 150000000,
        .mux = 0,
        .parentsNum = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_seip_div_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_seip_div_q = {
    .clkNode = {
        .core = &g_ap_bus_core,
        .id = 0x5000002,
        .rate = 150000000,
        .mux = 0,
        .parentsNum = 1,
        .parents[0] = CLK_NODE(g_ckgen_bus_seip_div_root),
    },
};

Mcu_CkgenNodeType g_ckgen_bus_seip_root = {
    .clkNode = {
        .core = &g_ap_bus_core,
        .id = 0x2,
        .rate = 300000000,
        .mux = 0,
        .parentsNum = 2,
        .parents[0] = CLK_NODE(g_ckgen_bus_seip_div_m),
        .parents[1] = CLK_NODE(g_pll5_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_reserved = {
    .clkNode = {
        .core = &g_ap_ip_core,
        .id = 0x0,
        .rate = 300000000,
        .mux = 2,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll_lvds_ckgen),
        .parents[4] = CLK_NODE(g_pll5_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_seip_test = {
    .clkNode = {
        .core = &g_ap_ip_core,
        .id = 0x1,
        .rate = 6000000,
        .mux = 1,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll5_root),
        .parents[4] = CLK_NODE(g_pll_lvds_ckgen),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_sdramc = {
    .clkNode = {
        .core = &g_ap_ip_core,
        .id = 0x2,
        .rate = 120000000,
        .mux = 2,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll_lvds_ckgen),
        .parents[4] = CLK_NODE(g_pll5_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_sehc1 = {
    .clkNode = {
        .core = &g_ap_ip_core,
        .id = 0x3,
        .rate = 50000000,
        .mux = 2,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll_lvds_ckgen),
        .parents[4] = CLK_NODE(g_pll5_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_sehc2 = {
    .clkNode = {
        .core = &g_ap_ip_core,
        .id = 0x4,
        .rate = 50000000,
        .mux = 2,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll_lvds_ckgen),
        .parents[4] = CLK_NODE(g_pll5_root),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_i2s_mclk0 = {
    .clkNode = {
        .core = &g_ap_ip_core,
        .id = 0x5,
        .rate = 12290000,
        .mux = 3,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll5_root),
        .parents[4] = CLK_NODE(g_pll_lvds_ckgen),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_i2s_mclk1 = {
    .clkNode = {
        .core = &g_ap_ip_core,
        .id = 0x6,
        .rate = 12290000,
        .mux = 3,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll5_root),
        .parents[4] = CLK_NODE(g_pll_lvds_ckgen),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_saci1_clk = {
    .clkNode = {
        .core = &g_ap_ip_core,
        .id = 0x7,
        .rate = 12290000,
        .mux = 3,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll5_root),
        .parents[4] = CLK_NODE(g_pll_lvds_ckgen),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_saci1_pdm_clk = {
    .clkNode = {
        .core = &g_ap_ip_core,
        .id = 0x8,
        .rate = 12290000,
        .mux = 3,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll5_root),
        .parents[4] = CLK_NODE(g_pll_lvds_ckgen),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_saci2_clk = {
    .clkNode = {
        .core = &g_ap_ip_core,
        .id = 0x9,
        .rate = 12290000,
        .mux = 3,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll5_root),
        .parents[4] = CLK_NODE(g_pll_lvds_ckgen),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_saci2_pdm_clk = {
    .clkNode = {
        .core = &g_ap_ip_core,
        .id = 0xa,
        .rate = 12290000,
        .mux = 3,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll5_root),
        .parents[4] = CLK_NODE(g_pll_lvds_ckgen),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_dc = {
    .clkNode = {
        .core = &g_ap_ip_core,
        .id = 0xb,
        .rate = 262140000,
        .mux = 3,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll5_root),
        .parents[4] = CLK_NODE(g_pll_lvds_ckgen),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_csi = {
    .clkNode = {
        .core = &g_ap_ip_core,
        .id = 0xc,
        .rate = 262140000,
        .mux = 3,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll5_root),
        .parents[4] = CLK_NODE(g_pll_lvds_ckgen),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_csi_mclk = {
    .clkNode = {
        .core = &g_ap_ip_core,
        .id = 0xd,
        .rate = 150000000,
        .mux = 2,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll5_root),
        .parents[4] = CLK_NODE(g_pll_lvds_ckgen),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_dc_alt_clk = {
    .clkNode = {
        .core = &g_ap_ip_core,
        .id = 0xe,
        .rate = 150000000,
        .mux = 2,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll5_root),
        .parents[4] = CLK_NODE(g_pll_lvds_ckgen),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_pt_sns_ap = {
    .clkNode = {
        .core = &g_ap_ip_core,
        .id = 0xf,
        .rate = 100000,
        .mux = 1,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll5_root),
        .parents[4] = CLK_NODE(g_pll_lvds_ckgen),
    },
};

Mcu_CkgenNodeType g_ckgen_ip_ap_test = {
    .clkNode = {
        .core = &g_ap_ip_core,
        .id = 0x10,
        .rate = 60000000,
        .mux = 2,
        .parentsNum = 5,
        .parents[0] = CLK_NODE(g_rc_24m),
        .parents[1] = CLK_NODE(g_fs_24m),
        .parents[2] = CLK_NODE(g_pll4_root),
        .parents[3] = CLK_NODE(g_pll5_root),
        .parents[4] = CLK_NODE(g_pll_lvds_ckgen),
    },
};

#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

const Mcu_CgNodeType g_ckgen_gating_sf_cr5_sxclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x1000000,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sx_mainclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x1000001,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sf_cr5_sfclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x1000002,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sx_sf_mainclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x1000003,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sf_mainclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x1000004,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sf_perclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x1000005,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sx_sf_perclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x1000006,
    },
};

const Mcu_CgNodeType g_ckgen_gating_xspi1_aclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x1000007,
    },
};

const Mcu_CgNodeType g_ckgen_gating_xsp1_bclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x1000008,
    },
};

const Mcu_CgNodeType g_ckgen_gating_xspi2_aclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x1000009,
    },
};

const Mcu_CgNodeType g_ckgen_gating_xspi2_bclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x100000a,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sp_cr5_spclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x100000b,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sp_mainclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x100000c,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sp_sf_mainclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x100000d,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sp_perclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x100000e,
    },
};

const Mcu_CgNodeType g_ckgen_gating_cr5_sx0_clkin = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x2000000,
    },
};

const Mcu_CgNodeType g_ckgen_gating_cr5_sx1_clkin = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x2000001,
    },
};

const Mcu_CgNodeType g_ckgen_gating_cr5_sf_clkin = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x2000002,
    },
};

const Mcu_CgNodeType g_ckgen_gating_cr5_sp0_clkin = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x2000003,
    },
};

const Mcu_CgNodeType g_ckgen_gating_cr5_sp1_clkin = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x2000004,
    },
};

const Mcu_CgNodeType g_ckgen_gating_iram_mux_aclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x0,
    },
};

const Mcu_CgNodeType g_ckgen_gating_iramc1_aclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x1,
    },
};

const Mcu_CgNodeType g_ckgen_gating_iramc2_aclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x2,
    },
};

const Mcu_CgNodeType g_ckgen_gating_iramc3_aclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x3,
    },
};

const Mcu_CgNodeType g_ckgen_gating_iromc_aclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x4,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sf_iram_mix_mainclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x5,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sf_periph_mainclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x6,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sf_boot_mainclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x7,
    },
};

const Mcu_CgNodeType g_ckgen_gating_mb_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x8,
    },
};

const Mcu_CgNodeType g_ckgen_gating_dma_sf_clk0 = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x9,
    },
};

const Mcu_CgNodeType g_ckgen_gating_dma_sf_clk1 = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xa,
    },
};

const Mcu_CgNodeType g_ckgen_gating_dma_sf_aclk0 = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xb,
    },
};

const Mcu_CgNodeType g_ckgen_gating_dma_sf_aclk1 = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xc,
    },
};

const Mcu_CgNodeType g_ckgen_gating_dma_sf_hclk0 = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xd,
    },
};

const Mcu_CgNodeType g_ckgen_gating_dma_sf_hclk1 = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xe,
    },
};

const Mcu_CgNodeType g_ckgen_gating_flexray1_hclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xf,
    },
};

const Mcu_CgNodeType g_ckgen_gating_flexray2_hclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x10,
    },
};

const Mcu_CgNodeType g_ckgen_gating_i2c1_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x11,
    },
};

const Mcu_CgNodeType g_ckgen_gating_i2c2_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x12,
    },
};

const Mcu_CgNodeType g_ckgen_gating_i2c3_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x13,
    },
};

const Mcu_CgNodeType g_ckgen_gating_i2c4_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x14,
    },
};

const Mcu_CgNodeType g_ckgen_gating_i2c5_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x15,
    },
};

const Mcu_CgNodeType g_ckgen_gating_i2c6_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x16,
    },
};

const Mcu_CgNodeType g_ckgen_gating_i2c7_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x17,
    },
};

const Mcu_CgNodeType g_ckgen_gating_i2c8_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x18,
    },
};

const Mcu_CgNodeType g_ckgen_gating_spi1_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x19,
    },
};

const Mcu_CgNodeType g_ckgen_gating_spi2_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x1a,
    },
};

const Mcu_CgNodeType g_ckgen_gating_spi3_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x1b,
    },
};

const Mcu_CgNodeType g_ckgen_gating_spi4_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x1c,
    },
};

const Mcu_CgNodeType g_ckgen_gating_spi5_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x1d,
    },
};

const Mcu_CgNodeType g_ckgen_gating_spi6_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x1e,
    },
};

const Mcu_CgNodeType g_ckgen_gating_spi7_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x1f,
    },
};

const Mcu_CgNodeType g_ckgen_gating_spi8_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x20,
    },
};

const Mcu_CgNodeType g_ckgen_gating_uart1_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x21,
    },
};

const Mcu_CgNodeType g_ckgen_gating_uart2_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x22,
    },
};

const Mcu_CgNodeType g_ckgen_gating_uart3_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x23,
    },
};

const Mcu_CgNodeType g_ckgen_gating_uart4_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x24,
    },
};

const Mcu_CgNodeType g_ckgen_gating_uart5_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x25,
    },
};

const Mcu_CgNodeType g_ckgen_gating_uart6_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x26,
    },
};

const Mcu_CgNodeType g_ckgen_gating_uart7_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x27,
    },
};

const Mcu_CgNodeType g_ckgen_gating_uart8_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x28,
    },
};

const Mcu_CgNodeType g_ckgen_gating_uart9_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x29,
    },
};

const Mcu_CgNodeType g_ckgen_gating_uart10_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x2a,
    },
};

const Mcu_CgNodeType g_ckgen_gating_uart11_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x2b,
    },
};

const Mcu_CgNodeType g_ckgen_gating_uart12_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x2c,
    },
};

const Mcu_CgNodeType g_ckgen_gating_uart13_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x2d,
    },
};

const Mcu_CgNodeType g_ckgen_gating_uart14_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x2e,
    },
};

const Mcu_CgNodeType g_ckgen_gating_uart15_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x2f,
    },
};

const Mcu_CgNodeType g_ckgen_gating_uart16_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x30,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd1_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x31,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd2_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x32,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd3_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x33,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd4_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x34,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd5_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x35,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd6_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x36,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd7_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x37,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd8_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x38,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd9_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x39,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd10_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x3a,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd11_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x3b,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd12_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x3c,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd13_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x3d,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd14_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x3e,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd15_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x3f,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd16_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x40,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd17_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x41,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd18_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x42,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd19_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x43,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd20_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x44,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd21_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x45,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd22_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x46,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd23_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x47,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd24_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x48,
    },
};

const Mcu_CgNodeType g_ckgen_gating_etmr1_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x49,
    },
};

const Mcu_CgNodeType g_ckgen_gating_etmr2_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x4a,
    },
};

const Mcu_CgNodeType g_ckgen_gating_etmr3_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x4b,
    },
};

const Mcu_CgNodeType g_ckgen_gating_etmr4_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x4c,
    },
};

const Mcu_CgNodeType g_ckgen_gating_pt_sns_sf_dig_i_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x4d,
    },
};

const Mcu_CgNodeType g_ckgen_gating_mpc_cr5_sx0_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x4e,
    },
};

const Mcu_CgNodeType g_ckgen_gating_mpc_cr5_sx1_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x4f,
    },
};

const Mcu_CgNodeType g_ckgen_gating_epwm1_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x50,
    },
};

const Mcu_CgNodeType g_ckgen_gating_epwm2_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x51,
    },
};

const Mcu_CgNodeType g_ckgen_gating_epwm3_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x52,
    },
};

const Mcu_CgNodeType g_ckgen_gating_epwm4_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x53,
    },
};

const Mcu_CgNodeType g_ckgen_gating_iram_mux_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x54,
    },
};

const Mcu_CgNodeType g_ckgen_gating_iramc1_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x55,
    },
};

const Mcu_CgNodeType g_ckgen_gating_iramc2_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x56,
    },
};

const Mcu_CgNodeType g_ckgen_gating_iramc3_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x57,
    },
};

const Mcu_CgNodeType g_ckgen_gating_iromc_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x58,
    },
};

const Mcu_CgNodeType g_ckgen_gating_gpio_sf_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x59,
    },
};

const Mcu_CgNodeType g_ckgen_gating_wdt1_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x5a,
    },
};

const Mcu_CgNodeType g_ckgen_gating_wdt2_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x5b,
    },
};

const Mcu_CgNodeType g_ckgen_gating_wdt1_bus_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x5c,
    },
};

const Mcu_CgNodeType g_ckgen_gating_wdt2_bus_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x5d,
    },
};

const Mcu_CgNodeType g_ckgen_gating_wdt5_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x5e,
    },
};

const Mcu_CgNodeType g_ckgen_gating_wdt5_bus_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x5f,
    },
};

const Mcu_CgNodeType g_ckgen_gating_wdt6_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x60,
    },
};

const Mcu_CgNodeType g_ckgen_gating_wdt6_bus_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x61,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sem1_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x62,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sem2_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x63,
    },
};

const Mcu_CgNodeType g_ckgen_gating_iomuxc_sf_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x64,
    },
};

const Mcu_CgNodeType g_ckgen_gating_iomuxc_sf_comp_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x65,
    },
};

const Mcu_CgNodeType g_ckgen_gating_efusec_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x66,
    },
};

const Mcu_CgNodeType g_ckgen_gating_mac_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x67,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sf_periph_mac_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x68,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sf_iram_mix_mac_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x69,
    },
};

const Mcu_CgNodeType g_ckgen_gating_mpc_cr5_sf_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x6a,
    },
};

const Mcu_CgNodeType g_ckgen_gating_scr_sf_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x6b,
    },
};

const Mcu_CgNodeType g_ckgen_gating_ckgen_sf_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x6c,
    },
};

const Mcu_CgNodeType g_ckgen_gating_rstgen_sf_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x6d,
    },
};

const Mcu_CgNodeType g_ckgen_gating_dma_sf_pclk0 = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x6e,
    },
};

const Mcu_CgNodeType g_ckgen_gating_dma_sf_pclk1 = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x6f,
    },
};

const Mcu_CgNodeType g_ckgen_gating_xb_sf_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x70,
    },
};

const Mcu_CgNodeType g_ckgen_gating_apbmux2_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x71,
    },
};

const Mcu_CgNodeType g_ckgen_gating_apbmux3_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x72,
    },
};

const Mcu_CgNodeType g_ckgen_gating_apbmux4_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x73,
    },
};

const Mcu_CgNodeType g_ckgen_gating_apbmux2_sf_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x74,
    },
};

const Mcu_CgNodeType g_ckgen_gating_ppc_apbmux1_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x75,
    },
};

const Mcu_CgNodeType g_ckgen_gating_ppc_apbmux2_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x76,
    },
};

const Mcu_CgNodeType g_ckgen_gating_ppc_apbmux3_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x77,
    },
};

const Mcu_CgNodeType g_ckgen_gating_ppc_apbmux4_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x78,
    },
};

const Mcu_CgNodeType g_ckgen_gating_smc_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x79,
    },
};

const Mcu_CgNodeType g_ckgen_gating_vd_sf_dig_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x7a,
    },
};

const Mcu_CgNodeType g_ckgen_gating_por_sf_dig_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x7b,
    },
};

const Mcu_CgNodeType g_ckgen_gating_xtrg_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x7c,
    },
};

const Mcu_CgNodeType g_ckgen_gating_apb_mac_sp_slv_src_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x7d,
    },
};

const Mcu_CgNodeType g_ckgen_gating_apb_mac_ap_slv_src_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x7e,
    },
};

const Mcu_CgNodeType g_ckgen_gating_fs_24m_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x7f,
    },
};

const Mcu_CgNodeType g_ckgen_gating_acmp1_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x80,
    },
};

const Mcu_CgNodeType g_ckgen_gating_acmp2_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x81,
    },
};

const Mcu_CgNodeType g_ckgen_gating_acmp3_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x82,
    },
};

const Mcu_CgNodeType g_ckgen_gating_acmp4_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x83,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sadc1_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x84,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sadc2_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x85,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sadc3_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x86,
    },
};

const Mcu_CgNodeType g_ckgen_gating_ioc_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x87,
    },
};

const Mcu_CgNodeType g_ckgen_gating_btm1_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x88,
    },
};

const Mcu_CgNodeType g_ckgen_gating_btm2_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x89,
    },
};

const Mcu_CgNodeType g_ckgen_gating_btm3_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x8a,
    },
};

const Mcu_CgNodeType g_ckgen_gating_btm4_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x8b,
    },
};

const Mcu_CgNodeType g_ckgen_gating_btm5_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x8c,
    },
};

const Mcu_CgNodeType g_ckgen_gating_btm6_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x8d,
    },
};

const Mcu_CgNodeType g_ckgen_gating_eic_sf_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x8e,
    },
};

const Mcu_CgNodeType g_ckgen_gating_eic_boot_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x8f,
    },
};

const Mcu_CgNodeType g_ckgen_gating_istc_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x90,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sf_periph_apbmux3_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x91,
    },
};

const Mcu_CgNodeType g_ckgen_gating_apb_seip_nvm_mst_dst_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x92,
    },
};

const Mcu_CgNodeType g_ckgen_gating_xspi1a_dma_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x93,
    },
};

const Mcu_CgNodeType g_ckgen_gating_xspi1b_dma_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x94,
    },
};

const Mcu_CgNodeType g_ckgen_gating_xspi2a_dma_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x95,
    },
};

const Mcu_CgNodeType g_ckgen_gating_xspi2b_dma_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x96,
    },
};

const Mcu_CgNodeType g_ckgen_gating_adma_enet1_dmaclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x97,
    },
};

const Mcu_CgNodeType g_ckgen_gating_adma_enet2_dmaclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x98,
    },
};

const Mcu_CgNodeType g_ckgen_gating_xb_sf_hclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x99,
    },
};

const Mcu_CgNodeType g_ckgen_gating_bti_sf_ahb_hclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x9a,
    },
};

const Mcu_CgNodeType g_ckgen_gating_aahb_spsf_mst_slvclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x9b,
    },
};

const Mcu_CgNodeType g_ckgen_gating_vic1_hclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x9c,
    },
};

const Mcu_CgNodeType g_ckgen_gating_vic3a_hclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x9d,
    },
};

const Mcu_CgNodeType g_ckgen_gating_vic3b_hclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x9e,
    },
};

const Mcu_CgNodeType g_ckgen_gating_vic_sf_irqsync = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x9f,
    },
};

const Mcu_CgNodeType g_ckgen_gating_i2c1_sclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xa0,
    },
};

const Mcu_CgNodeType g_ckgen_gating_i2c2_sclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xa1,
    },
};

const Mcu_CgNodeType g_ckgen_gating_i2c3_sclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xa2,
    },
};

const Mcu_CgNodeType g_ckgen_gating_i2c4_sclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xa3,
    },
};

const Mcu_CgNodeType g_ckgen_gating_i2c5_sclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xa4,
    },
};

const Mcu_CgNodeType g_ckgen_gating_i2c6_sclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xa5,
    },
};

const Mcu_CgNodeType g_ckgen_gating_i2c7_sclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xa6,
    },
};

const Mcu_CgNodeType g_ckgen_gating_i2c8_sclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xa7,
    },
};

const Mcu_CgNodeType g_ckgen_gating_spi1_spi_per_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xa8,
    },
};

const Mcu_CgNodeType g_ckgen_gating_spi2_spi_per_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xa9,
    },
};

const Mcu_CgNodeType g_ckgen_gating_spi3_spi_per_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xaa,
    },
};

const Mcu_CgNodeType g_ckgen_gating_spi4_spi_per_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xab,
    },
};

const Mcu_CgNodeType g_ckgen_gating_spi5_spi_per_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xac,
    },
};

const Mcu_CgNodeType g_ckgen_gating_spi6_spi_per_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xad,
    },
};

const Mcu_CgNodeType g_ckgen_gating_spi7_spi_per_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xae,
    },
};

const Mcu_CgNodeType g_ckgen_gating_spi8_spi_per_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xaf,
    },
};

const Mcu_CgNodeType g_ckgen_gating_uart1_sclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xb0,
    },
};

const Mcu_CgNodeType g_ckgen_gating_uart2_sclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xb1,
    },
};

const Mcu_CgNodeType g_ckgen_gating_uart3_sclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xb2,
    },
};

const Mcu_CgNodeType g_ckgen_gating_uart4_sclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xb3,
    },
};

const Mcu_CgNodeType g_ckgen_gating_uart5_sclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xb4,
    },
};

const Mcu_CgNodeType g_ckgen_gating_uart6_sclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xb5,
    },
};

const Mcu_CgNodeType g_ckgen_gating_uart7_sclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xb6,
    },
};

const Mcu_CgNodeType g_ckgen_gating_uart8_sclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xb7,
    },
};

const Mcu_CgNodeType g_ckgen_gating_uart9_sclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xb8,
    },
};

const Mcu_CgNodeType g_ckgen_gating_uart10_sclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xb9,
    },
};

const Mcu_CgNodeType g_ckgen_gating_uart11_sclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xba,
    },
};

const Mcu_CgNodeType g_ckgen_gating_uart12_sclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xbb,
    },
};

const Mcu_CgNodeType g_ckgen_gating_uart13_sclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xbc,
    },
};

const Mcu_CgNodeType g_ckgen_gating_uart14_sclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xbd,
    },
};

const Mcu_CgNodeType g_ckgen_gating_uart15_sclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xbe,
    },
};

const Mcu_CgNodeType g_ckgen_gating_uart16_sclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xbf,
    },
};

const Mcu_CgNodeType g_ckgen_gating_enet1_ref_clk_tx = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xc0,
    },
};

const Mcu_CgNodeType g_ckgen_gating_enet1_ptp_ref_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xc1,
    },
};

const Mcu_CgNodeType g_ckgen_gating_enet2_ptp_ref_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xc2,
    },
};

const Mcu_CgNodeType g_ckgen_gating_enet2_ref_clk_tx = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xc3,
    },
};

const Mcu_CgNodeType g_ckgen_gating_xspi1a_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xc4,
    },
};

const Mcu_CgNodeType g_ckgen_gating_mpc_xspi1a_aclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xc5,
    },
};

const Mcu_CgNodeType g_ckgen_gating_xspi1b_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xc6,
    },
};

const Mcu_CgNodeType g_ckgen_gating_mpc_xspi1b_aclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xc7,
    },
};

const Mcu_CgNodeType g_ckgen_gating_xspi2a_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xc8,
    },
};

const Mcu_CgNodeType g_ckgen_gating_mpc_xspi2a_aclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xc9,
    },
};

const Mcu_CgNodeType g_ckgen_gating_xspi2b_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xca,
    },
};

const Mcu_CgNodeType g_ckgen_gating_mpc_xspi2b_aclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xcb,
    },
};

const Mcu_CgNodeType g_ckgen_gating_xtrg_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xcc,
    },
};

const Mcu_CgNodeType g_ckgen_gating_etmr1_ahf_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xcd,
    },
};

const Mcu_CgNodeType g_ckgen_gating_etmr2_ahf_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xce,
    },
};

const Mcu_CgNodeType g_ckgen_gating_etmr3_ahf_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xcf,
    },
};

const Mcu_CgNodeType g_ckgen_gating_etmr4_ahf_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xd0,
    },
};

const Mcu_CgNodeType g_ckgen_gating_epwm1_ahf_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xd1,
    },
};

const Mcu_CgNodeType g_ckgen_gating_epwm2_ahf_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xd2,
    },
};

const Mcu_CgNodeType g_ckgen_gating_epwm3_ahf_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xd3,
    },
};

const Mcu_CgNodeType g_ckgen_gating_epwm4_ahf_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xd4,
    },
};

const Mcu_CgNodeType g_ckgen_gating_etmr1_hf_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xd5,
    },
};

const Mcu_CgNodeType g_ckgen_gating_etmr2_hf_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xd6,
    },
};

const Mcu_CgNodeType g_ckgen_gating_etmr3_hf_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xd7,
    },
};

const Mcu_CgNodeType g_ckgen_gating_etmr4_hf_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xd8,
    },
};

const Mcu_CgNodeType g_ckgen_gating_epwm1_hf_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xd9,
    },
};

const Mcu_CgNodeType g_ckgen_gating_epwm2_hf_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xda,
    },
};

const Mcu_CgNodeType g_ckgen_gating_epwm3_hf_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xdb,
    },
};

const Mcu_CgNodeType g_ckgen_gating_epwm4_hf_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xdc,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd1_ipg_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xdd,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd2_ipg_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xde,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd3_ipg_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xdf,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd4_ipg_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xe0,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd5_ipg_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xe1,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd6_ipg_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xe2,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd7_ipg_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xe3,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd8_ipg_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xe4,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd9_ipg_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xe5,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd10_ipg_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xe6,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd11_ipg_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xe7,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd12_ipg_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xe8,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd13_ipg_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xe9,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd14_ipg_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xea,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd15_ipg_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xeb,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd16_ipg_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xec,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd17_ipg_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xed,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd18_ipg_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xee,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd19_ipg_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xef,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd20_ipg_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xf0,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd21_ipg_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xf1,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd22_ipg_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xf2,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd23_ipg_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xf3,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd24_ipg_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xf4,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sadc1_ctrl_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xf5,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sadc2_ctrl_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xf6,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sadc3_ctrl_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xf7,
    },
};

const Mcu_CgNodeType g_ckgen_gating_acmp1_ctrl_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xf8,
    },
};

const Mcu_CgNodeType g_ckgen_gating_acmp2_ctrl_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xf9,
    },
};

const Mcu_CgNodeType g_ckgen_gating_acmp3_ctrl_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xfa,
    },
};

const Mcu_CgNodeType g_ckgen_gating_acmp4_ctrl_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xfb,
    },
};

const Mcu_CgNodeType g_ckgen_gating_flexray1_ipg_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xfc,
    },
};

const Mcu_CgNodeType g_ckgen_gating_flexray2_ipg_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xfd,
    },
};

const Mcu_CgNodeType g_ckgen_gating_ioc_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xfe,
    },
};

const Mcu_CgNodeType g_ckgen_gating_pt_sns_sf_clkin = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0xff,
    },
};

const Mcu_CgNodeType g_ckgen_gating_istc_i_istc_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x100,
    },
};

const Mcu_CgNodeType g_ckgen_gating_smc_clk_24m = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x101,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd1_clk24m = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x102,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd2_clk24m = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x103,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd3_clk24m = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x104,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd4_clk24m = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x105,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd5_clk24m = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x106,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd6_clk24m = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x107,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd7_clk24m = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x108,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd8_clk24m = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x109,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd9_clk24m = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x10a,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd10_clk24m = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x10b,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd11_clk24m = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x10c,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd12_clk24m = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x10d,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd13_clk24m = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x10e,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd14_clk24m = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x10f,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd15_clk24m = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x110,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd16_clk24m = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x111,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd17_clk24m = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x112,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd18_clk24m = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x113,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd19_clk24m = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x114,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd20_clk24m = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x115,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd21_clk24m = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x116,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd22_clk24m = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x117,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd23_clk24m = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x118,
    },
};

const Mcu_CgNodeType g_ckgen_gating_canfd24_clk24m = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x119,
    },
};

const Mcu_CgNodeType g_ckgen_gating_xtrg_wdt_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x11a,
    },
};

const Mcu_CgNodeType g_ckgen_gating_ldo_dig_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x11b,
    },
};

const Mcu_CgNodeType g_ckgen_gating_dcdc1_clk_24m = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x11c,
    },
};

const Mcu_CgNodeType g_ckgen_gating_vic1_wdt_ref_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x11d,
    },
};

const Mcu_CgNodeType g_ckgen_gating_vic3a_wdt_ref_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x11e,
    },
};

const Mcu_CgNodeType g_ckgen_gating_vic3b_wdt_ref_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x11f,
    },
};

const Mcu_CgNodeType g_ckgen_gating_wdt1_main_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x120,
    },
};

const Mcu_CgNodeType g_ckgen_gating_wdt2_main_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x121,
    },
};

const Mcu_CgNodeType g_ckgen_gating_wdt5_main_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x122,
    },
};

const Mcu_CgNodeType g_ckgen_gating_wdt6_main_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x123,
    },
};

const Mcu_CgNodeType g_ckgen_gating_btm1_i_xtal24mhz_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x124,
    },
};

const Mcu_CgNodeType g_ckgen_gating_btm2_i_xtal24mhz_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x125,
    },
};

const Mcu_CgNodeType g_ckgen_gating_btm3_i_xtal24mhz_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x126,
    },
};

const Mcu_CgNodeType g_ckgen_gating_btm4_i_xtal24mhz_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x127,
    },
};

const Mcu_CgNodeType g_ckgen_gating_btm5_i_xtal24mhz_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x128,
    },
};

const Mcu_CgNodeType g_ckgen_gating_btm6_i_xtal24mhz_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x129,
    },
};

const Mcu_CgNodeType g_ckgen_gating_pt_sns_sf_dig_clk_24m = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x12a,
    },
};

const Mcu_CgNodeType g_ckgen_gating_gama1_hclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x12b,
    },
};

const Mcu_CgNodeType g_ckgen_gating_xspi_slv_aclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x12c,
    },
};

const Mcu_CgNodeType g_ckgen_gating_vic2a_hclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x12d,
    },
};

const Mcu_CgNodeType g_ckgen_gating_vic2b_hclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x12e,
    },
};

const Mcu_CgNodeType g_ckgen_gating_vic_sp_irqsync = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x12f,
    },
};

const Mcu_CgNodeType g_ckgen_gating_enet1_aclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x130,
    },
};

const Mcu_CgNodeType g_ckgen_gating_enet2_aclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x131,
    },
};

const Mcu_CgNodeType g_ckgen_gating_gama1_aclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x132,
    },
};

const Mcu_CgNodeType g_ckgen_gating_ahb_syncup_gama1_mainclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x133,
    },
};

const Mcu_CgNodeType g_ckgen_gating_iramc4_aclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x134,
    },
};

const Mcu_CgNodeType g_ckgen_gating_wdt3_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x135,
    },
};

const Mcu_CgNodeType g_ckgen_gating_wdt3_bus_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x136,
    },
};

const Mcu_CgNodeType g_ckgen_gating_wdt4_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x137,
    },
};

const Mcu_CgNodeType g_ckgen_gating_wdt4_bus_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x138,
    },
};

const Mcu_CgNodeType g_ckgen_gating_ppc_apbmux5_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x139,
    },
};

const Mcu_CgNodeType g_ckgen_gating_apbmux5_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x13a,
    },
};

const Mcu_CgNodeType g_ckgen_gating_xspi_slv_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x13b,
    },
};

const Mcu_CgNodeType g_ckgen_gating_enet1_clk_csr = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x13c,
    },
};

const Mcu_CgNodeType g_ckgen_gating_enet2_clk_csr = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x13d,
    },
};

const Mcu_CgNodeType g_ckgen_gating_adma_enet1_perclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x13e,
    },
};

const Mcu_CgNodeType g_ckgen_gating_adma_enet2_perclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x13f,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sp_mac_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x140,
    },
};

const Mcu_CgNodeType g_ckgen_gating_cr5_sp_mix_mac_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x141,
    },
};

const Mcu_CgNodeType g_ckgen_gating_eic_sp_i_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x142,
    },
};

const Mcu_CgNodeType g_ckgen_gating_cslite_pclkdbg = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x143,
    },
};

const Mcu_CgNodeType g_ckgen_gating_cslite_pclksys = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x144,
    },
};

const Mcu_CgNodeType g_ckgen_gating_apb_cr5sx0_dbg_slv_src_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x145,
    },
};

const Mcu_CgNodeType g_ckgen_gating_apb_cr5sx1_dbg_slv_src_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x146,
    },
};

const Mcu_CgNodeType g_ckgen_gating_apb_cr5sf_dbg_slv_src_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x147,
    },
};

const Mcu_CgNodeType g_ckgen_gating_iramc4_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x148,
    },
};

const Mcu_CgNodeType g_ckgen_gating_wdt3_main_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x149,
    },
};

const Mcu_CgNodeType g_ckgen_gating_wdt4_main_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x14a,
    },
};

const Mcu_CgNodeType g_ckgen_gating_vic2a_wdt_ref_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x14b,
    },
};

const Mcu_CgNodeType g_ckgen_gating_vic2b_wdt_ref_clk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x14c,
    },
};

const Mcu_CgNodeType g_ckgen_gating_rtc_pclk = {
    .clkNode = {
        .core = &Mcu_ClkSfGatingCore,
        .id = 0x14d,
    },
};

const Mcu_CgNodeType g_ckgen_gating_ap_apmainclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x1000000,
    },
};

const Mcu_CgNodeType g_ckgen_gating_ap_dispclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x1000001,
    },
};

const Mcu_CgNodeType g_ckgen_gating_ap_perclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x1000002,
    },
};

const Mcu_CgNodeType g_ckgen_gating_ap_hsmperclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x1000003,
    },
};

const Mcu_CgNodeType g_ckgen_gating_ap_sdramclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x1000004,
    },
};

const Mcu_CgNodeType g_ckgen_gating_disp_mainclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x1000005,
    },
};

const Mcu_CgNodeType g_ckgen_gating_disp_perclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x1000006,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sehc1_aclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x0,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sehc2_aclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x1,
    },
};

const Mcu_CgNodeType g_ckgen_gating_dma_ap_clk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x2,
    },
};

const Mcu_CgNodeType g_ckgen_gating_dma_ap_aclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x3,
    },
};

const Mcu_CgNodeType g_ckgen_gating_dma_ap_hclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x4,
    },
};

const Mcu_CgNodeType g_ckgen_gating_seip_sh_clk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x5,
    },
};

const Mcu_CgNodeType g_ckgen_gating_apbmux6_pclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x6,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sdramc_pclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x7,
    },
};

const Mcu_CgNodeType g_ckgen_gating_gpio_ap_pclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x8,
    },
};

const Mcu_CgNodeType g_ckgen_gating_iomuxc_ap_pclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x9,
    },
};

const Mcu_CgNodeType g_ckgen_gating_ckgen_ap_pclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0xa,
    },
};

const Mcu_CgNodeType g_ckgen_gating_usb2_pclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0xb,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sehc1_pclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0xc,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sehc2_pclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0xd,
    },
};

const Mcu_CgNodeType g_ckgen_gating_rstgen_ap_pclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0xe,
    },
};

const Mcu_CgNodeType g_ckgen_gating_wdt8_pclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0xf,
    },
};

const Mcu_CgNodeType g_ckgen_gating_wdt8_bus_clk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x10,
    },
};

const Mcu_CgNodeType g_ckgen_gating_saci1_pclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x11,
    },
};

const Mcu_CgNodeType g_ckgen_gating_saci2_pclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x12,
    },
};

const Mcu_CgNodeType g_ckgen_gating_dma_ap_pclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x13,
    },
};

const Mcu_CgNodeType g_ckgen_gating_ap_mac_pclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x14,
    },
};

const Mcu_CgNodeType g_ckgen_gating_vd_ap_pclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x15,
    },
};

const Mcu_CgNodeType g_ckgen_gating_pt_sns_ap_pclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x16,
    },
};

const Mcu_CgNodeType g_ckgen_gating_scr_ap_pclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x17,
    },
};

const Mcu_CgNodeType g_ckgen_gating_por_ap_pclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x18,
    },
};

const Mcu_CgNodeType g_ckgen_gating_seip_pclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x19,
    },
};

const Mcu_CgNodeType g_ckgen_gating_seip_hclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x1a,
    },
};

const Mcu_CgNodeType g_ckgen_gating_seip_fd_ref_clk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x1b,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sdramc_aclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x1c,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sehc1_main_clk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x1d,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sehc2_main_clk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x1e,
    },
};

const Mcu_CgNodeType g_ckgen_gating_saci1_i2s_mclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x1f,
    },
};

const Mcu_CgNodeType g_ckgen_gating_saci2_i2s_mclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x20,
    },
};

const Mcu_CgNodeType g_ckgen_gating_saci1_ext_clk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x21,
    },
};

const Mcu_CgNodeType g_ckgen_gating_saci2_ext_clk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x22,
    },
};

const Mcu_CgNodeType g_ckgen_gating_saci1_i2s_tx_clk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x23,
    },
};

const Mcu_CgNodeType g_ckgen_gating_saci2_i2s_tx_clk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x24,
    },
};

const Mcu_CgNodeType g_ckgen_gating_saci1_i2s_rx_clk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x25,
    },
};

const Mcu_CgNodeType g_ckgen_gating_saci2_i2s_rx_clk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x26,
    },
};

const Mcu_CgNodeType g_ckgen_gating_saci1_pdm_per_clk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x27,
    },
};

const Mcu_CgNodeType g_ckgen_gating_saci2_pdm_per_clk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x28,
    },
};

const Mcu_CgNodeType g_ckgen_gating_pt_sns_ap_clkin = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x29,
    },
};

const Mcu_CgNodeType g_ckgen_gating_usb_phy_ref_clk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x2a,
    },
};

const Mcu_CgNodeType g_ckgen_gating_wdt8_main_clk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x2b,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sehc1_cqe_sqs_clk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x2c,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sehc2_cqe_sqs_clk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x2d,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sehc1_tm_clk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x2e,
    },
};

const Mcu_CgNodeType g_ckgen_gating_sehc2_tm_clk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x2f,
    },
};

const Mcu_CgNodeType g_ckgen_gating_csi_axi_clk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x30,
    },
};

const Mcu_CgNodeType g_ckgen_gating_dc_axi_clk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x31,
    },
};

const Mcu_CgNodeType g_ckgen_gating_g2d_axi_clk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x32,
    },
};

const Mcu_CgNodeType g_ckgen_gating_csi_pclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x33,
    },
};

const Mcu_CgNodeType g_ckgen_gating_apbmux7_pclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x34,
    },
};

const Mcu_CgNodeType g_ckgen_gating_disp_mux_pclk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x35,
    },
};

const Mcu_CgNodeType g_ckgen_gating_dc_pix_clk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x36,
    },
};

const Mcu_CgNodeType g_ckgen_gating_csi_proc_clk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x37,
    },
};

const Mcu_CgNodeType g_ckgen_gating_disp_mux_disp_ckgen_pix_clk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x38,
    },
};

const Mcu_CgNodeType g_ckgen_gating_lvds_ch0_clk_x14 = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x39,
    },
};

const Mcu_CgNodeType g_ckgen_gating_lvds_ch0_clk_x7 = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x3a,
    },
};

const Mcu_CgNodeType g_ckgen_gating_dc_dsp_clk = {
    .clkNode = {
        .core = &Mcu_ClkApGatingCore,
        .id = 0x3b,
    },
};

/*pll1 is always 500M configured by ROM*/
const Mcu_ClkNodeType * const Mcu_ClkPrepareArray[] = {
#ifndef CFG_XIP
    CLK_NODE(g_pll1_root),
    CLK_NODE(g_pll2_root),
    CLK_NODE(g_pll3_root),
#endif /** #ifndef CFG_XIP*/
    CLK_NODE(g_ckgen_bus_cr5_sf_div_root),
    CLK_NODE(g_ckgen_bus_cr5_sf_div_m),
    CLK_NODE(g_ckgen_bus_cr5_sf_div_n),
    CLK_NODE(g_ckgen_bus_cr5_sf_div_p),
    CLK_NODE(g_ckgen_bus_cr5_sf_div_q),
    CLK_NODE(g_ckgen_bus_cr5_sf_root),
    CLK_NODE(g_ckgen_core_cr5_sx),
    CLK_NODE(g_ckgen_ip_i2c_sf_1_to_4),
    CLK_NODE(g_ckgen_ip_i2c_sf_5_to_8),
    CLK_NODE(g_ckgen_ip_spi_sf_1_to_4),
    CLK_NODE(g_ckgen_ip_spi_sf_5_to_8),
    CLK_NODE(g_ckgen_ip_uart_sf_1_to_8),
    CLK_NODE(g_ckgen_ip_uart_sf_9_to_16),
#ifndef CFG_XIP
    CLK_NODE(g_ckgen_ip_xspi1a),
    CLK_NODE(g_ckgen_ip_xspi1b),
    CLK_NODE(g_ckgen_ip_xspi2a),
    CLK_NODE(g_ckgen_ip_xspi2b),
#endif /** #ifndef CFG_XIP*/
    CLK_NODE(g_ckgen_ip_xtrg),
    CLK_NODE(g_ckgen_ip_etmr1),
    CLK_NODE(g_ckgen_ip_etmr2),
    CLK_NODE(g_ckgen_ip_etmr3),
    CLK_NODE(g_ckgen_ip_etmr4),
    CLK_NODE(g_ckgen_ip_epwm1),
    CLK_NODE(g_ckgen_ip_epwm2),
    CLK_NODE(g_ckgen_ip_epwm3),
    CLK_NODE(g_ckgen_ip_epwm4),
    CLK_NODE(g_ckgen_ip_can),
    CLK_NODE(g_ckgen_ip_adc1),
    CLK_NODE(g_ckgen_ip_adc2),
    CLK_NODE(g_ckgen_ip_acmp),
    CLK_NODE(g_ckgen_ip_ioc),
    CLK_NODE(g_ckgen_ip_pt_sns_sf),
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
};

const Mcu_ClkNodeType * const Mcu_ClkEnableArray[] = {
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
    CLK_NODE(g_ckgen_gating_sf_iram_mix_mainclk),
    CLK_NODE(g_ckgen_gating_sf_periph_mainclk),
    CLK_NODE(g_ckgen_gating_sf_boot_mainclk),
    CLK_NODE(g_ckgen_gating_mb_clk),
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
    CLK_NODE(g_ckgen_gating_canfd7_pclk),
    CLK_NODE(g_ckgen_gating_canfd7_ipg_clk),
    CLK_NODE(g_ckgen_gating_canfd7_clk24m),
    CLK_NODE(g_ckgen_gating_canfd8_pclk),
    CLK_NODE(g_ckgen_gating_canfd8_ipg_clk),
    CLK_NODE(g_ckgen_gating_canfd8_clk24m),
    CLK_NODE(g_ckgen_gating_mpc_cr5_sx0_pclk),
    CLK_NODE(g_ckgen_gating_mpc_cr5_sx1_pclk),
    CLK_NODE(g_ckgen_gating_iram_mux_pclk),
    CLK_NODE(g_ckgen_gating_iramc1_pclk),
    CLK_NODE(g_ckgen_gating_iramc2_pclk),
    CLK_NODE(g_ckgen_gating_gpio_sf_pclk),
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
    CLK_NODE(g_ckgen_gating_por_sf_dig_pclk),
    CLK_NODE(g_ckgen_gating_xtrg_clk),
    CLK_NODE(g_ckgen_gating_xtrg_pclk),
    CLK_NODE(g_ckgen_gating_xtrg_wdt_clk),
    CLK_NODE(g_ckgen_gating_acmp1_pclk),
    CLK_NODE(g_ckgen_gating_acmp1_ctrl_clk),
    CLK_NODE(g_ckgen_gating_acmp2_pclk),
    CLK_NODE(g_ckgen_gating_acmp2_ctrl_clk),
    CLK_NODE(g_ckgen_gating_acmp3_pclk),
    CLK_NODE(g_ckgen_gating_acmp3_ctrl_clk),
    CLK_NODE(g_ckgen_gating_acmp4_pclk),
    CLK_NODE(g_ckgen_gating_acmp4_ctrl_clk),
    CLK_NODE(g_ckgen_gating_ioc_pclk),
    CLK_NODE(g_ckgen_gating_ioc_clk),
#ifndef CFG_XIP
    CLK_NODE(g_ckgen_gating_xspi1a_dma_clk),
    CLK_NODE(g_ckgen_gating_xspi1b_dma_clk),
    CLK_NODE(g_ckgen_gating_xspi1a_clk),
    CLK_NODE(g_ckgen_gating_xspi1b_clk),
    CLK_NODE(g_ckgen_gating_xspi2a_dma_clk),
    CLK_NODE(g_ckgen_gating_xspi2b_dma_clk),
    CLK_NODE(g_ckgen_gating_xspi2a_clk),
    CLK_NODE(g_ckgen_gating_xspi2b_clk),
#else
    CLK_NODE(g_ckgen_gating_xspi1a_dma_clk),
    CLK_NODE(g_ckgen_gating_xspi1b_dma_clk),
    CLK_NODE(g_ckgen_gating_xspi1a_clk),
    CLK_NODE(g_ckgen_gating_xspi1b_clk),
    CLK_NODE(g_ckgen_gating_xspi2a_dma_clk),
    CLK_NODE(g_ckgen_gating_xspi2b_dma_clk),
    CLK_NODE(g_ckgen_gating_xspi2a_clk),
    CLK_NODE(g_ckgen_gating_xspi2b_clk),
#endif /** #ifndef CFG_XIP*/
    CLK_NODE(g_ckgen_gating_vic1_hclk),
    CLK_NODE(g_ckgen_gating_vic1_wdt_ref_clk),
    CLK_NODE(g_ckgen_gating_vic2a_hclk),
    CLK_NODE(g_ckgen_gating_vic2a_wdt_ref_clk),
    CLK_NODE(g_ckgen_gating_vic2b_hclk),
    CLK_NODE(g_ckgen_gating_vic2b_wdt_ref_clk),
    CLK_NODE(g_ckgen_gating_vic3a_hclk),
    CLK_NODE(g_ckgen_gating_vic3a_wdt_ref_clk),
    CLK_NODE(g_ckgen_gating_vic3b_hclk),
    CLK_NODE(g_ckgen_gating_vic3b_wdt_ref_clk),
    CLK_NODE(g_ckgen_gating_i2c1_sclk),
    CLK_NODE(g_ckgen_gating_i2c1_pclk),
    CLK_NODE(g_ckgen_gating_i2c2_sclk),
    CLK_NODE(g_ckgen_gating_i2c2_pclk),
    CLK_NODE(g_ckgen_gating_i2c3_sclk),
    CLK_NODE(g_ckgen_gating_i2c3_pclk),
    CLK_NODE(g_ckgen_gating_i2c8_sclk),
    CLK_NODE(g_ckgen_gating_i2c8_pclk),
    CLK_NODE(g_ckgen_gating_spi2_pclk),
    CLK_NODE(g_ckgen_gating_spi2_spi_per_clk),
    CLK_NODE(g_ckgen_gating_spi5_pclk),
    CLK_NODE(g_ckgen_gating_spi5_spi_per_clk),
    CLK_NODE(g_ckgen_gating_spi7_pclk),
    CLK_NODE(g_ckgen_gating_spi7_spi_per_clk),
    CLK_NODE(g_ckgen_gating_uart3_sclk),
    CLK_NODE(g_ckgen_gating_uart3_pclk),
    CLK_NODE(g_ckgen_gating_uart6_sclk),
    CLK_NODE(g_ckgen_gating_uart6_pclk),
    CLK_NODE(g_ckgen_gating_uart7_sclk),
    CLK_NODE(g_ckgen_gating_uart7_pclk),
    CLK_NODE(g_ckgen_gating_uart11_sclk),
    CLK_NODE(g_ckgen_gating_uart11_pclk),
    CLK_NODE(g_ckgen_gating_uart14_sclk),
    CLK_NODE(g_ckgen_gating_uart14_pclk),
    CLK_NODE(g_ckgen_gating_etmr1_pclk),
    CLK_NODE(g_ckgen_gating_etmr1_ahf_clk),
    CLK_NODE(g_ckgen_gating_etmr1_hf_clk),
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
    CLK_NODE(g_ckgen_gating_wdt1_pclk),
    CLK_NODE(g_ckgen_gating_wdt1_bus_clk),
    CLK_NODE(g_ckgen_gating_wdt1_main_clk),
    CLK_NODE(g_ckgen_gating_wdt2_pclk),
    CLK_NODE(g_ckgen_gating_wdt2_bus_clk),
    CLK_NODE(g_ckgen_gating_wdt2_main_clk),
    CLK_NODE(g_ckgen_gating_wdt5_pclk),
    CLK_NODE(g_ckgen_gating_wdt5_bus_clk),
    CLK_NODE(g_ckgen_gating_wdt5_main_clk),
    CLK_NODE(g_ckgen_gating_wdt6_pclk),
    CLK_NODE(g_ckgen_gating_wdt6_bus_clk),
    CLK_NODE(g_ckgen_gating_wdt6_main_clk),
    CLK_NODE(g_ckgen_gating_wdt3_pclk),
    CLK_NODE(g_ckgen_gating_wdt3_bus_clk),
    CLK_NODE(g_ckgen_gating_wdt3_main_clk),
    CLK_NODE(g_ckgen_gating_wdt4_pclk),
    CLK_NODE(g_ckgen_gating_wdt4_bus_clk),
    CLK_NODE(g_ckgen_gating_wdt4_main_clk),
    CLK_NODE(g_ckgen_gating_btm1_pclk),
    CLK_NODE(g_ckgen_gating_btm1_i_xtal24mhz_clk),
    CLK_NODE(g_ckgen_gating_btm2_pclk),
    CLK_NODE(g_ckgen_gating_btm2_i_xtal24mhz_clk),
    CLK_NODE(g_ckgen_gating_btm3_pclk),
    CLK_NODE(g_ckgen_gating_btm3_i_xtal24mhz_clk),
    CLK_NODE(g_ckgen_gating_btm4_pclk),
    CLK_NODE(g_ckgen_gating_btm4_i_xtal24mhz_clk),
    CLK_NODE(g_ckgen_gating_btm5_pclk),
    CLK_NODE(g_ckgen_gating_btm5_i_xtal24mhz_clk),
    CLK_NODE(g_ckgen_gating_btm6_pclk),
    CLK_NODE(g_ckgen_gating_btm6_i_xtal24mhz_clk),
    CLK_NODE(g_ckgen_gating_ldo_dig_pclk),
    CLK_NODE(g_ckgen_gating_dcdc1_clk_24m),
    CLK_NODE(g_ckgen_gating_apb_mac_ap_slv_src_pclk),
    CLK_NODE(g_ckgen_gating_fs_24m_pclk),
    CLK_NODE(g_ckgen_gating_sf_periph_apbmux3_pclk),
    CLK_NODE(g_ckgen_gating_apb_seip_nvm_mst_dst_pclk),
    CLK_NODE(g_ckgen_gating_xb_sf_hclk),
    CLK_NODE(g_ckgen_gating_bti_sf_ahb_hclk),
    CLK_NODE(g_ckgen_gating_aahb_spsf_mst_slvclk),
    CLK_NODE(g_ckgen_gating_vic_sf_irqsync),
    CLK_NODE(g_ckgen_gating_mpc_xspi1a_aclk),
    CLK_NODE(g_ckgen_gating_mpc_xspi1b_aclk),
    CLK_NODE(g_ckgen_gating_mpc_xspi2a_aclk),
    CLK_NODE(g_ckgen_gating_mpc_xspi2b_aclk),
    CLK_NODE(g_ckgen_gating_smc_clk_24m),
    CLK_NODE(g_ckgen_gating_vic_sp_irqsync),
    CLK_NODE(g_ckgen_gating_ppc_apbmux5_pclk),
    CLK_NODE(g_ckgen_gating_apbmux5_pclk),
    CLK_NODE(g_ckgen_gating_sp_mac_pclk),
    CLK_NODE(g_ckgen_gating_cr5_sp_mix_mac_pclk),
    CLK_NODE(g_ckgen_gating_cslite_pclkdbg),
    CLK_NODE(g_ckgen_gating_cslite_pclksys),
    CLK_NODE(g_ckgen_gating_apb_cr5sx0_dbg_slv_src_pclk),
    CLK_NODE(g_ckgen_gating_apb_cr5sx1_dbg_slv_src_pclk),
    CLK_NODE(g_ckgen_gating_apb_cr5sf_dbg_slv_src_pclk),
    CLK_NODE(g_ckgen_gating_rtc_pclk),
    CLK_NODE(g_ckgen_gating_dma_sf_clk0),
    CLK_NODE(g_ckgen_gating_dma_sf_clk1),
    CLK_NODE(g_ckgen_gating_dma_sf_aclk0),
    CLK_NODE(g_ckgen_gating_dma_sf_aclk1),
    CLK_NODE(g_ckgen_gating_dma_sf_hclk0),
    CLK_NODE(g_ckgen_gating_dma_sf_hclk1),
    CLK_NODE(g_ckgen_gating_dma_sf_pclk0),
    CLK_NODE(g_ckgen_gating_dma_sf_pclk1),
    CLK_NODE(g_ckgen_gating_pt_sns_sf_dig_i_pclk),
    CLK_NODE(g_ckgen_gating_pt_sns_sf_clkin),
    CLK_NODE(g_ckgen_gating_pt_sns_sf_dig_clk_24m),
    CLK_NODE(g_ckgen_gating_vd_sf_dig_pclk),
    CLK_NODE(g_ckgen_gating_sem1_pclk),
    CLK_NODE(g_ckgen_gating_sem2_pclk),
    CLK_NODE(g_ckgen_gating_eic_sf_pclk),
    CLK_NODE(g_ckgen_gating_eic_boot_pclk),
    CLK_NODE(g_ckgen_gating_eic_sp_i_pclk),
    CLK_NODE(g_ckgen_gating_ap_apmainclk),
    CLK_NODE(g_ckgen_gating_ap_dispclk),
    CLK_NODE(g_ckgen_gating_ap_perclk),
    CLK_NODE(g_ckgen_gating_ap_hsmperclk),
    CLK_NODE(g_ckgen_gating_ap_sdramclk),
    CLK_NODE(g_ckgen_gating_apbmux6_pclk),
    CLK_NODE(g_ckgen_gating_gpio_ap_pclk),
    CLK_NODE(g_ckgen_gating_iomuxc_ap_pclk),
    CLK_NODE(g_ckgen_gating_ckgen_ap_pclk),
    CLK_NODE(g_ckgen_gating_rstgen_ap_pclk),
    CLK_NODE(g_ckgen_gating_ap_mac_pclk),
    CLK_NODE(g_ckgen_gating_scr_ap_pclk),
    CLK_NODE(g_ckgen_gating_por_ap_pclk),
    CLK_NODE(g_ckgen_gating_apbmux7_pclk),
    CLK_NODE(g_ckgen_gating_wdt8_pclk),
    CLK_NODE(g_ckgen_gating_wdt8_bus_clk),
    CLK_NODE(g_ckgen_gating_wdt8_main_clk),
    CLK_NODE(g_ckgen_gating_usb_phy_ref_clk),
    CLK_NODE(g_ckgen_gating_usb2_pclk),
    CLK_NODE(g_ckgen_gating_seip_sh_clk),
    CLK_NODE(g_ckgen_gating_seip_pclk),
    CLK_NODE(g_ckgen_gating_seip_hclk),
    CLK_NODE(g_ckgen_gating_seip_fd_ref_clk),
};

const Mcu_ClkNodeType * const Mcu_ClkDisableArray[] = {
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
    CLK_NODE(g_ckgen_gating_saci2_pclk),
    CLK_NODE(g_ckgen_gating_saci2_i2s_mclk),
    CLK_NODE(g_ckgen_gating_saci2_ext_clk),
    CLK_NODE(g_ckgen_gating_saci2_i2s_tx_clk),
    CLK_NODE(g_ckgen_gating_saci2_i2s_rx_clk),
    CLK_NODE(g_ckgen_gating_saci2_pdm_per_clk),
    CLK_NODE(g_ckgen_gating_csi_axi_clk),
    CLK_NODE(g_ckgen_gating_csi_pclk),
    CLK_NODE(g_ckgen_gating_csi_proc_clk),
    CLK_NODE(g_ckgen_gating_g2d_axi_clk),
    CLK_NODE(g_ckgen_gating_lvds_ch0_clk_x14),
    CLK_NODE(g_ckgen_gating_lvds_ch0_clk_x7),
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
    CLK_NODE(g_ckgen_gating_disp_mux_pclk),
    CLK_NODE(g_ckgen_gating_disp_mux_disp_ckgen_pix_clk),
    CLK_NODE(g_ckgen_gating_disp_mainclk),
    CLK_NODE(g_ckgen_gating_disp_perclk),
    CLK_NODE(g_ckgen_gating_iromc_aclk),
    CLK_NODE(g_ckgen_gating_iromc_pclk),
    CLK_NODE(g_ckgen_gating_istc_pclk),
    CLK_NODE(g_ckgen_gating_istc_i_istc_clk),
    CLK_NODE(g_ckgen_gating_sdramc_pclk),
    CLK_NODE(g_ckgen_gating_sdramc_aclk),
    CLK_NODE(g_ckgen_gating_flexray1_hclk),
    CLK_NODE(g_ckgen_gating_flexray1_ipg_clk),
    CLK_NODE(g_ckgen_gating_flexray2_hclk),
    CLK_NODE(g_ckgen_gating_flexray2_ipg_clk),
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
#ifndef CFG_XIP
#endif /** #ifndef CFG_XIP*/
    CLK_NODE(g_ckgen_gating_xspi_slv_aclk),
    CLK_NODE(g_ckgen_gating_xspi_slv_pclk),
    CLK_NODE(g_ckgen_gating_i2c4_sclk),
    CLK_NODE(g_ckgen_gating_i2c4_pclk),
    CLK_NODE(g_ckgen_gating_i2c5_sclk),
    CLK_NODE(g_ckgen_gating_i2c5_pclk),
    CLK_NODE(g_ckgen_gating_i2c6_sclk),
    CLK_NODE(g_ckgen_gating_i2c6_pclk),
    CLK_NODE(g_ckgen_gating_i2c7_sclk),
    CLK_NODE(g_ckgen_gating_i2c7_pclk),
    CLK_NODE(g_ckgen_gating_spi1_pclk),
    CLK_NODE(g_ckgen_gating_spi1_spi_per_clk),
    CLK_NODE(g_ckgen_gating_spi3_pclk),
    CLK_NODE(g_ckgen_gating_spi3_spi_per_clk),
    CLK_NODE(g_ckgen_gating_spi4_pclk),
    CLK_NODE(g_ckgen_gating_spi4_spi_per_clk),
    CLK_NODE(g_ckgen_gating_spi6_pclk),
    CLK_NODE(g_ckgen_gating_spi6_spi_per_clk),
    CLK_NODE(g_ckgen_gating_spi8_pclk),
    CLK_NODE(g_ckgen_gating_spi8_spi_per_clk),
    CLK_NODE(g_ckgen_gating_uart1_sclk),
    CLK_NODE(g_ckgen_gating_uart1_pclk),
    CLK_NODE(g_ckgen_gating_uart2_sclk),
    CLK_NODE(g_ckgen_gating_uart2_pclk),
    CLK_NODE(g_ckgen_gating_uart4_sclk),
    CLK_NODE(g_ckgen_gating_uart4_pclk),
    CLK_NODE(g_ckgen_gating_uart5_sclk),
    CLK_NODE(g_ckgen_gating_uart5_pclk),
    CLK_NODE(g_ckgen_gating_uart8_sclk),
    CLK_NODE(g_ckgen_gating_uart8_pclk),
    CLK_NODE(g_ckgen_gating_uart9_sclk),
    CLK_NODE(g_ckgen_gating_uart9_pclk),
    CLK_NODE(g_ckgen_gating_uart10_sclk),
    CLK_NODE(g_ckgen_gating_uart10_pclk),
    CLK_NODE(g_ckgen_gating_uart12_sclk),
    CLK_NODE(g_ckgen_gating_uart12_pclk),
    CLK_NODE(g_ckgen_gating_uart13_sclk),
    CLK_NODE(g_ckgen_gating_uart13_pclk),
    CLK_NODE(g_ckgen_gating_uart15_sclk),
    CLK_NODE(g_ckgen_gating_uart15_pclk),
    CLK_NODE(g_ckgen_gating_uart16_sclk),
    CLK_NODE(g_ckgen_gating_uart16_pclk),
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
    CLK_NODE(g_ckgen_gating_pt_sns_ap_pclk),
    CLK_NODE(g_ckgen_gating_pt_sns_ap_clkin),
    CLK_NODE(g_ckgen_gating_vd_ap_pclk),
    CLK_NODE(g_ckgen_gating_sehc1_aclk),
    CLK_NODE(g_ckgen_gating_sehc1_pclk),
    CLK_NODE(g_ckgen_gating_sehc1_main_clk),
    CLK_NODE(g_ckgen_gating_sehc1_cqe_sqs_clk),
    CLK_NODE(g_ckgen_gating_sehc1_tm_clk),
    CLK_NODE(g_ckgen_gating_sehc2_aclk),
    CLK_NODE(g_ckgen_gating_sehc2_pclk),
    CLK_NODE(g_ckgen_gating_sehc2_main_clk),
    CLK_NODE(g_ckgen_gating_sehc2_cqe_sqs_clk),
    CLK_NODE(g_ckgen_gating_sehc2_tm_clk),
};

#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

uint32 Mcu_GetClkPrepareArraySize(void)
{
    return sizeof(Mcu_ClkPrepareArray) / sizeof(Mcu_ClkPrepareArray[0]);
}

uint32 Mcu_GetClkEnableArraySize(void)
{
    return sizeof(Mcu_ClkEnableArray) / sizeof(Mcu_ClkEnableArray[0]);
}

uint32 Mcu_GetClkDisableArraySize(void)
{
    return sizeof(Mcu_ClkDisableArray) / sizeof(Mcu_ClkDisableArray[0]);
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
};
#endif
/* End of file */
