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

#ifndef E3_CLOCK_CFG_ND_H
#define E3_CLOCK_CFG_ND_H

#include "e3_pll_drv.h"
#include "e3_ckgen_drv.h"

extern taishan_pll_node_t g_rc_24m;
extern taishan_pll_node_t g_fs_24m;
extern taishan_ckgen_node_t g_ckgen_bus_cr5_sf_div_root_preset;
extern taishan_ckgen_node_t g_ckgen_bus_cr5_sp_div_root_preset;
extern taishan_ckgen_node_t g_ckgen_bus_sf_test_div_root_preset;
extern taishan_ckgen_node_t g_ckgen_bus_ap_bus_div_root_preset;
extern taishan_ckgen_node_t g_ckgen_bus_disp_bus_div_root_preset;
extern taishan_ckgen_node_t g_ckgen_bus_seip_div_root_preset;
extern taishan_pll_node_t g_pll1_root;
extern taishan_pll_node_t g_pll2_root;
extern taishan_pll_node_t g_pll3_root;
extern taishan_ckgen_node_t g_ckgen_bus_cr5_sf_div_root;
extern taishan_ckgen_node_t g_ckgen_bus_cr5_sf_div_m;
extern taishan_ckgen_node_t g_ckgen_bus_cr5_sf_div_n;
extern taishan_ckgen_node_t g_ckgen_bus_cr5_sf_div_p;
extern taishan_ckgen_node_t g_ckgen_bus_cr5_sf_div_q;
extern taishan_ckgen_node_t g_ckgen_bus_cr5_sf_root;
extern taishan_ckgen_node_t g_ckgen_bus_cr5_sp_div_root;
extern taishan_ckgen_node_t g_ckgen_bus_cr5_sp_div_m;
extern taishan_ckgen_node_t g_ckgen_bus_cr5_sp_div_n;
extern taishan_ckgen_node_t g_ckgen_bus_cr5_sp_div_p;
extern taishan_ckgen_node_t g_ckgen_bus_cr5_sp_div_q;
extern taishan_ckgen_node_t g_ckgen_bus_cr5_sp_root;
extern taishan_ckgen_node_t g_ckgen_core_cr5_sx_preset;
extern taishan_ckgen_node_t g_ckgen_core_cr5_sx;
extern taishan_ckgen_node_t g_ckgen_ip_i2c_sf_1_to_4;
extern taishan_ckgen_node_t g_ckgen_ip_i2c_sf_5_to_8;
extern taishan_ckgen_node_t g_ckgen_ip_spi_sf_1_to_4;
extern taishan_ckgen_node_t g_ckgen_ip_spi_sf_5_to_8;
extern taishan_ckgen_node_t g_ckgen_ip_uart_sf_1_to_8;
extern taishan_ckgen_node_t g_ckgen_ip_uart_sf_9_to_16;
extern taishan_ckgen_node_t g_ckgen_ip_enet1_tx;
extern taishan_ckgen_node_t g_ckgen_ip_enet1_rmii;
extern taishan_ckgen_node_t g_ckgen_ip_enet1_phy_ref;
extern taishan_ckgen_node_t g_ckgen_ip_enet1_timer_sec;
extern taishan_ckgen_node_t g_ckgen_ip_enet2_tx;
extern taishan_ckgen_node_t g_ckgen_ip_enet2_rmii;
extern taishan_ckgen_node_t g_ckgen_ip_enet2_phy_ref;
extern taishan_ckgen_node_t g_ckgen_ip_xspi1a;
extern taishan_ckgen_node_t g_ckgen_ip_xspi1b;
extern taishan_ckgen_node_t g_ckgen_ip_xspi2a;
extern taishan_ckgen_node_t g_ckgen_ip_xspi2b;
extern taishan_ckgen_node_t g_ckgen_ip_xtrg;
extern taishan_ckgen_node_t g_ckgen_ip_etmr1;
extern taishan_ckgen_node_t g_ckgen_ip_etmr2;
extern taishan_ckgen_node_t g_ckgen_ip_etmr3;
extern taishan_ckgen_node_t g_ckgen_ip_etmr4;
extern taishan_ckgen_node_t g_ckgen_ip_epwm1;
extern taishan_ckgen_node_t g_ckgen_ip_epwm2;
extern taishan_ckgen_node_t g_ckgen_ip_epwm3;
extern taishan_ckgen_node_t g_ckgen_ip_epwm4;
extern taishan_ckgen_node_t g_ckgen_ip_can;
extern taishan_ckgen_node_t g_ckgen_ip_adc1;
extern taishan_ckgen_node_t g_ckgen_ip_adc2;
extern taishan_ckgen_node_t g_ckgen_ip_adc3;
extern taishan_ckgen_node_t g_ckgen_ip_acmp;
extern taishan_ckgen_node_t g_ckgen_ip_flexray;
extern taishan_ckgen_node_t g_ckgen_ip_ioc;
extern taishan_ckgen_node_t g_ckgen_ip_pt_sns_sf;
extern taishan_ckgen_node_t g_ckgen_bus_sf_test_div_root;
extern taishan_ckgen_node_t g_ckgen_bus_sf_test_div_m;
extern taishan_ckgen_node_t g_ckgen_bus_sf_test_div_n;
extern taishan_ckgen_node_t g_ckgen_bus_sf_test_div_p;
extern taishan_ckgen_node_t g_ckgen_bus_sf_test_div_q;
extern taishan_ckgen_node_t g_ckgen_bus_sf_test_root;
extern taishan_pll_node_t g_pll4_root;
extern taishan_pll_node_t g_pll5_root;
extern taishan_pll_node_t g_pll_lvds_root;
extern taishan_pll_node_t g_pll_lvds_nodiv;
extern taishan_pll_node_t g_pll_lvds_div2;
extern taishan_pll_node_t g_pll_lvds_div7;
extern taishan_pll_node_t g_pll_lvds_ckgen;
extern taishan_ckgen_node_t g_ckgen_bus_ap_bus_div_root;
extern taishan_ckgen_node_t g_ckgen_bus_ap_bus_div_m;
extern taishan_ckgen_node_t g_ckgen_bus_ap_bus_div_n;
extern taishan_ckgen_node_t g_ckgen_bus_ap_bus_div_p;
extern taishan_ckgen_node_t g_ckgen_bus_ap_bus_div_q;
extern taishan_ckgen_node_t g_ckgen_bus_ap_bus_root;
extern taishan_ckgen_node_t g_ckgen_bus_disp_bus_div_root;
extern taishan_ckgen_node_t g_ckgen_bus_disp_bus_div_m;
extern taishan_ckgen_node_t g_ckgen_bus_disp_bus_div_n;
extern taishan_ckgen_node_t g_ckgen_bus_disp_bus_div_p;
extern taishan_ckgen_node_t g_ckgen_bus_disp_bus_div_q;
extern taishan_ckgen_node_t g_ckgen_bus_disp_bus_root;
extern taishan_ckgen_node_t g_ckgen_bus_seip_div_root;
extern taishan_ckgen_node_t g_ckgen_bus_seip_div_m;
extern taishan_ckgen_node_t g_ckgen_bus_seip_div_n;
extern taishan_ckgen_node_t g_ckgen_bus_seip_div_p;
extern taishan_ckgen_node_t g_ckgen_bus_seip_div_q;
extern taishan_ckgen_node_t g_ckgen_bus_seip_root;
extern taishan_ckgen_node_t g_ckgen_ip_reserved;
extern taishan_ckgen_node_t g_ckgen_ip_seip_test;
extern taishan_ckgen_node_t g_ckgen_ip_sdramc;
extern taishan_ckgen_node_t g_ckgen_ip_sehc1;
extern taishan_ckgen_node_t g_ckgen_ip_sehc2;
extern taishan_ckgen_node_t g_ckgen_ip_i2s_mclk0;
extern taishan_ckgen_node_t g_ckgen_ip_i2s_mclk1;
extern taishan_ckgen_node_t g_ckgen_ip_saci1_clk;
extern taishan_ckgen_node_t g_ckgen_ip_saci1_pdm_clk;
extern taishan_ckgen_node_t g_ckgen_ip_saci2_clk;
extern taishan_ckgen_node_t g_ckgen_ip_saci2_pdm_clk;
extern taishan_ckgen_node_t g_ckgen_ip_dc;
extern taishan_ckgen_node_t g_ckgen_ip_csi;
extern taishan_ckgen_node_t g_ckgen_ip_csi_mclk;
extern taishan_ckgen_node_t g_ckgen_ip_dc_alt_clk;
extern taishan_ckgen_node_t g_ckgen_ip_pt_sns_ap;
extern taishan_ckgen_node_t g_ckgen_ip_ap_test;
extern taishan_cg_node_t g_ckgen_gating_sf_cr5_sxclk;
extern taishan_cg_node_t g_ckgen_gating_sx_mainclk;
extern taishan_cg_node_t g_ckgen_gating_sf_cr5_sfclk;
extern taishan_cg_node_t g_ckgen_gating_sx_sf_mainclk;
extern taishan_cg_node_t g_ckgen_gating_sf_mainclk;
extern taishan_cg_node_t g_ckgen_gating_sf_perclk;
extern taishan_cg_node_t g_ckgen_gating_sx_sf_perclk;
extern taishan_cg_node_t g_ckgen_gating_xspi1_aclk;
extern taishan_cg_node_t g_ckgen_gating_xsp1_bclk;
extern taishan_cg_node_t g_ckgen_gating_xspi2_aclk;
extern taishan_cg_node_t g_ckgen_gating_xspi2_bclk;
extern taishan_cg_node_t g_ckgen_gating_sp_cr5_spclk;
extern taishan_cg_node_t g_ckgen_gating_sp_mainclk;
extern taishan_cg_node_t g_ckgen_gating_sp_sf_mainclk;
extern taishan_cg_node_t g_ckgen_gating_sp_perclk;
extern taishan_cg_node_t g_ckgen_gating_cr5_sx0_clkin;
extern taishan_cg_node_t g_ckgen_gating_cr5_sx1_clkin;
extern taishan_cg_node_t g_ckgen_gating_cr5_sf_clkin;
extern taishan_cg_node_t g_ckgen_gating_cr5_sp0_clkin;
extern taishan_cg_node_t g_ckgen_gating_cr5_sp1_clkin;
extern taishan_cg_node_t g_ckgen_gating_iram_mux_aclk;
extern taishan_cg_node_t g_ckgen_gating_iramc1_aclk;
extern taishan_cg_node_t g_ckgen_gating_iramc2_aclk;
extern taishan_cg_node_t g_ckgen_gating_iramc3_aclk;
extern taishan_cg_node_t g_ckgen_gating_iromc_aclk;
extern taishan_cg_node_t g_ckgen_gating_sf_iram_mix_mainclk;
extern taishan_cg_node_t g_ckgen_gating_sf_periph_mainclk;
extern taishan_cg_node_t g_ckgen_gating_sf_boot_mainclk;
extern taishan_cg_node_t g_ckgen_gating_mb_clk;
extern taishan_cg_node_t g_ckgen_gating_dma_sf_clk0;
extern taishan_cg_node_t g_ckgen_gating_dma_sf_clk1;
extern taishan_cg_node_t g_ckgen_gating_dma_sf_aclk0;
extern taishan_cg_node_t g_ckgen_gating_dma_sf_aclk1;
extern taishan_cg_node_t g_ckgen_gating_dma_sf_hclk0;
extern taishan_cg_node_t g_ckgen_gating_dma_sf_hclk1;
extern taishan_cg_node_t g_ckgen_gating_flexray1_hclk;
extern taishan_cg_node_t g_ckgen_gating_flexray2_hclk;
extern taishan_cg_node_t g_ckgen_gating_i2c1_pclk;
extern taishan_cg_node_t g_ckgen_gating_i2c2_pclk;
extern taishan_cg_node_t g_ckgen_gating_i2c3_pclk;
extern taishan_cg_node_t g_ckgen_gating_i2c4_pclk;
extern taishan_cg_node_t g_ckgen_gating_i2c5_pclk;
extern taishan_cg_node_t g_ckgen_gating_i2c6_pclk;
extern taishan_cg_node_t g_ckgen_gating_i2c7_pclk;
extern taishan_cg_node_t g_ckgen_gating_i2c8_pclk;
extern taishan_cg_node_t g_ckgen_gating_spi1_pclk;
extern taishan_cg_node_t g_ckgen_gating_spi2_pclk;
extern taishan_cg_node_t g_ckgen_gating_spi3_pclk;
extern taishan_cg_node_t g_ckgen_gating_spi4_pclk;
extern taishan_cg_node_t g_ckgen_gating_spi5_pclk;
extern taishan_cg_node_t g_ckgen_gating_spi6_pclk;
extern taishan_cg_node_t g_ckgen_gating_spi7_pclk;
extern taishan_cg_node_t g_ckgen_gating_spi8_pclk;
extern taishan_cg_node_t g_ckgen_gating_uart1_pclk;
extern taishan_cg_node_t g_ckgen_gating_uart2_pclk;
extern taishan_cg_node_t g_ckgen_gating_uart3_pclk;
extern taishan_cg_node_t g_ckgen_gating_uart4_pclk;
extern taishan_cg_node_t g_ckgen_gating_uart5_pclk;
extern taishan_cg_node_t g_ckgen_gating_uart6_pclk;
extern taishan_cg_node_t g_ckgen_gating_uart7_pclk;
extern taishan_cg_node_t g_ckgen_gating_uart8_pclk;
extern taishan_cg_node_t g_ckgen_gating_uart9_pclk;
extern taishan_cg_node_t g_ckgen_gating_uart10_pclk;
extern taishan_cg_node_t g_ckgen_gating_uart11_pclk;
extern taishan_cg_node_t g_ckgen_gating_uart12_pclk;
extern taishan_cg_node_t g_ckgen_gating_uart13_pclk;
extern taishan_cg_node_t g_ckgen_gating_uart14_pclk;
extern taishan_cg_node_t g_ckgen_gating_uart15_pclk;
extern taishan_cg_node_t g_ckgen_gating_uart16_pclk;
extern taishan_cg_node_t g_ckgen_gating_canfd1_pclk;
extern taishan_cg_node_t g_ckgen_gating_canfd2_pclk;
extern taishan_cg_node_t g_ckgen_gating_canfd3_pclk;
extern taishan_cg_node_t g_ckgen_gating_canfd4_pclk;
extern taishan_cg_node_t g_ckgen_gating_canfd5_pclk;
extern taishan_cg_node_t g_ckgen_gating_canfd6_pclk;
extern taishan_cg_node_t g_ckgen_gating_canfd7_pclk;
extern taishan_cg_node_t g_ckgen_gating_canfd8_pclk;
extern taishan_cg_node_t g_ckgen_gating_canfd9_pclk;
extern taishan_cg_node_t g_ckgen_gating_canfd10_pclk;
extern taishan_cg_node_t g_ckgen_gating_canfd11_pclk;
extern taishan_cg_node_t g_ckgen_gating_canfd12_pclk;
extern taishan_cg_node_t g_ckgen_gating_canfd13_pclk;
extern taishan_cg_node_t g_ckgen_gating_canfd14_pclk;
extern taishan_cg_node_t g_ckgen_gating_canfd15_pclk;
extern taishan_cg_node_t g_ckgen_gating_canfd16_pclk;
extern taishan_cg_node_t g_ckgen_gating_canfd17_pclk;
extern taishan_cg_node_t g_ckgen_gating_canfd18_pclk;
extern taishan_cg_node_t g_ckgen_gating_canfd19_pclk;
extern taishan_cg_node_t g_ckgen_gating_canfd20_pclk;
extern taishan_cg_node_t g_ckgen_gating_canfd21_pclk;
extern taishan_cg_node_t g_ckgen_gating_canfd22_pclk;
extern taishan_cg_node_t g_ckgen_gating_canfd23_pclk;
extern taishan_cg_node_t g_ckgen_gating_canfd24_pclk;
extern taishan_cg_node_t g_ckgen_gating_etmr1_pclk;
extern taishan_cg_node_t g_ckgen_gating_etmr2_pclk;
extern taishan_cg_node_t g_ckgen_gating_etmr3_pclk;
extern taishan_cg_node_t g_ckgen_gating_etmr4_pclk;
extern taishan_cg_node_t g_ckgen_gating_pt_sns_sf_dig_i_pclk;
extern taishan_cg_node_t g_ckgen_gating_mpc_cr5_sx0_pclk;
extern taishan_cg_node_t g_ckgen_gating_mpc_cr5_sx1_pclk;
extern taishan_cg_node_t g_ckgen_gating_epwm1_pclk;
extern taishan_cg_node_t g_ckgen_gating_epwm2_pclk;
extern taishan_cg_node_t g_ckgen_gating_epwm3_pclk;
extern taishan_cg_node_t g_ckgen_gating_epwm4_pclk;
extern taishan_cg_node_t g_ckgen_gating_iram_mux_pclk;
extern taishan_cg_node_t g_ckgen_gating_iramc1_pclk;
extern taishan_cg_node_t g_ckgen_gating_iramc2_pclk;
extern taishan_cg_node_t g_ckgen_gating_iramc3_pclk;
extern taishan_cg_node_t g_ckgen_gating_iromc_pclk;
extern taishan_cg_node_t g_ckgen_gating_gpio_sf_pclk;
extern taishan_cg_node_t g_ckgen_gating_wdt1_pclk;
extern taishan_cg_node_t g_ckgen_gating_wdt2_pclk;
extern taishan_cg_node_t g_ckgen_gating_wdt1_bus_clk;
extern taishan_cg_node_t g_ckgen_gating_wdt2_bus_clk;
extern taishan_cg_node_t g_ckgen_gating_wdt5_pclk;
extern taishan_cg_node_t g_ckgen_gating_wdt5_bus_clk;
extern taishan_cg_node_t g_ckgen_gating_wdt6_pclk;
extern taishan_cg_node_t g_ckgen_gating_wdt6_bus_clk;
extern taishan_cg_node_t g_ckgen_gating_sem1_pclk;
extern taishan_cg_node_t g_ckgen_gating_sem2_pclk;
extern taishan_cg_node_t g_ckgen_gating_iomuxc_sf_pclk;
extern taishan_cg_node_t g_ckgen_gating_iomuxc_sf_comp_pclk;
extern taishan_cg_node_t g_ckgen_gating_efusec_pclk;
extern taishan_cg_node_t g_ckgen_gating_mac_pclk;
extern taishan_cg_node_t g_ckgen_gating_sf_periph_mac_pclk;
extern taishan_cg_node_t g_ckgen_gating_sf_iram_mix_mac_pclk;
extern taishan_cg_node_t g_ckgen_gating_mpc_cr5_sf_pclk;
extern taishan_cg_node_t g_ckgen_gating_scr_sf_pclk;
extern taishan_cg_node_t g_ckgen_gating_ckgen_sf_pclk;
extern taishan_cg_node_t g_ckgen_gating_rstgen_sf_pclk;
extern taishan_cg_node_t g_ckgen_gating_dma_sf_pclk0;
extern taishan_cg_node_t g_ckgen_gating_dma_sf_pclk1;
extern taishan_cg_node_t g_ckgen_gating_xb_sf_pclk;
extern taishan_cg_node_t g_ckgen_gating_apbmux2_pclk;
extern taishan_cg_node_t g_ckgen_gating_apbmux3_pclk;
extern taishan_cg_node_t g_ckgen_gating_apbmux4_pclk;
extern taishan_cg_node_t g_ckgen_gating_apbmux2_sf_pclk;
extern taishan_cg_node_t g_ckgen_gating_ppc_apbmux1_pclk;
extern taishan_cg_node_t g_ckgen_gating_ppc_apbmux2_pclk;
extern taishan_cg_node_t g_ckgen_gating_ppc_apbmux3_pclk;
extern taishan_cg_node_t g_ckgen_gating_ppc_apbmux4_pclk;
extern taishan_cg_node_t g_ckgen_gating_smc_pclk;
extern taishan_cg_node_t g_ckgen_gating_vd_sf_dig_pclk;
extern taishan_cg_node_t g_ckgen_gating_por_sf_dig_pclk;
extern taishan_cg_node_t g_ckgen_gating_xtrg_pclk;
extern taishan_cg_node_t g_ckgen_gating_apb_mac_sp_slv_src_pclk;
extern taishan_cg_node_t g_ckgen_gating_apb_mac_ap_slv_src_pclk;
extern taishan_cg_node_t g_ckgen_gating_fs_24m_pclk;
extern taishan_cg_node_t g_ckgen_gating_acmp1_pclk;
extern taishan_cg_node_t g_ckgen_gating_acmp2_pclk;
extern taishan_cg_node_t g_ckgen_gating_acmp3_pclk;
extern taishan_cg_node_t g_ckgen_gating_acmp4_pclk;
extern taishan_cg_node_t g_ckgen_gating_sadc1_pclk;
extern taishan_cg_node_t g_ckgen_gating_sadc2_pclk;
extern taishan_cg_node_t g_ckgen_gating_sadc3_pclk;
extern taishan_cg_node_t g_ckgen_gating_ioc_pclk;
extern taishan_cg_node_t g_ckgen_gating_btm1_pclk;
extern taishan_cg_node_t g_ckgen_gating_btm2_pclk;
extern taishan_cg_node_t g_ckgen_gating_btm3_pclk;
extern taishan_cg_node_t g_ckgen_gating_btm4_pclk;
extern taishan_cg_node_t g_ckgen_gating_btm5_pclk;
extern taishan_cg_node_t g_ckgen_gating_btm6_pclk;
extern taishan_cg_node_t g_ckgen_gating_eic_sf_pclk;
extern taishan_cg_node_t g_ckgen_gating_eic_boot_pclk;
extern taishan_cg_node_t g_ckgen_gating_istc_pclk;
extern taishan_cg_node_t g_ckgen_gating_sf_periph_apbmux3_pclk;
extern taishan_cg_node_t g_ckgen_gating_apb_seip_nvm_mst_dst_pclk;
extern taishan_cg_node_t g_ckgen_gating_xspi1a_dma_clk;
extern taishan_cg_node_t g_ckgen_gating_xspi1b_dma_clk;
extern taishan_cg_node_t g_ckgen_gating_xspi2a_dma_clk;
extern taishan_cg_node_t g_ckgen_gating_xspi2b_dma_clk;
extern taishan_cg_node_t g_ckgen_gating_adma_enet1_dmaclk;
extern taishan_cg_node_t g_ckgen_gating_adma_enet2_dmaclk;
extern taishan_cg_node_t g_ckgen_gating_xb_sf_hclk;
extern taishan_cg_node_t g_ckgen_gating_bti_sf_ahb_hclk;
extern taishan_cg_node_t g_ckgen_gating_aahb_spsf_mst_slvclk;
extern taishan_cg_node_t g_ckgen_gating_vic1_hclk;
extern taishan_cg_node_t g_ckgen_gating_vic3a_hclk;
extern taishan_cg_node_t g_ckgen_gating_vic3b_hclk;
extern taishan_cg_node_t g_ckgen_gating_vic_sf_irqsync;
extern taishan_cg_node_t g_ckgen_gating_i2c1_sclk;
extern taishan_cg_node_t g_ckgen_gating_i2c2_sclk;
extern taishan_cg_node_t g_ckgen_gating_i2c3_sclk;
extern taishan_cg_node_t g_ckgen_gating_i2c4_sclk;
extern taishan_cg_node_t g_ckgen_gating_i2c5_sclk;
extern taishan_cg_node_t g_ckgen_gating_i2c6_sclk;
extern taishan_cg_node_t g_ckgen_gating_i2c7_sclk;
extern taishan_cg_node_t g_ckgen_gating_i2c8_sclk;
extern taishan_cg_node_t g_ckgen_gating_spi1_spi_per_clk;
extern taishan_cg_node_t g_ckgen_gating_spi2_spi_per_clk;
extern taishan_cg_node_t g_ckgen_gating_spi3_spi_per_clk;
extern taishan_cg_node_t g_ckgen_gating_spi4_spi_per_clk;
extern taishan_cg_node_t g_ckgen_gating_spi5_spi_per_clk;
extern taishan_cg_node_t g_ckgen_gating_spi6_spi_per_clk;
extern taishan_cg_node_t g_ckgen_gating_spi7_spi_per_clk;
extern taishan_cg_node_t g_ckgen_gating_spi8_spi_per_clk;
extern taishan_cg_node_t g_ckgen_gating_uart1_sclk;
extern taishan_cg_node_t g_ckgen_gating_uart2_sclk;
extern taishan_cg_node_t g_ckgen_gating_uart3_sclk;
extern taishan_cg_node_t g_ckgen_gating_uart4_sclk;
extern taishan_cg_node_t g_ckgen_gating_uart5_sclk;
extern taishan_cg_node_t g_ckgen_gating_uart6_sclk;
extern taishan_cg_node_t g_ckgen_gating_uart7_sclk;
extern taishan_cg_node_t g_ckgen_gating_uart8_sclk;
extern taishan_cg_node_t g_ckgen_gating_uart9_sclk;
extern taishan_cg_node_t g_ckgen_gating_uart10_sclk;
extern taishan_cg_node_t g_ckgen_gating_uart11_sclk;
extern taishan_cg_node_t g_ckgen_gating_uart12_sclk;
extern taishan_cg_node_t g_ckgen_gating_uart13_sclk;
extern taishan_cg_node_t g_ckgen_gating_uart14_sclk;
extern taishan_cg_node_t g_ckgen_gating_uart15_sclk;
extern taishan_cg_node_t g_ckgen_gating_uart16_sclk;
extern taishan_cg_node_t g_ckgen_gating_enet1_ref_clk_tx;
extern taishan_cg_node_t g_ckgen_gating_enet1_ptp_ref_clk;
extern taishan_cg_node_t g_ckgen_gating_enet2_ptp_ref_clk;
extern taishan_cg_node_t g_ckgen_gating_enet2_ref_clk_tx;
extern taishan_cg_node_t g_ckgen_gating_xspi1a_clk;
extern taishan_cg_node_t g_ckgen_gating_mpc_xspi1a_aclk;
extern taishan_cg_node_t g_ckgen_gating_xspi1b_clk;
extern taishan_cg_node_t g_ckgen_gating_mpc_xspi1b_aclk;
extern taishan_cg_node_t g_ckgen_gating_xspi2a_clk;
extern taishan_cg_node_t g_ckgen_gating_mpc_xspi2a_aclk;
extern taishan_cg_node_t g_ckgen_gating_xspi2b_clk;
extern taishan_cg_node_t g_ckgen_gating_mpc_xspi2b_aclk;
extern taishan_cg_node_t g_ckgen_gating_xtrg_clk;
extern taishan_cg_node_t g_ckgen_gating_etmr1_ahf_clk;
extern taishan_cg_node_t g_ckgen_gating_etmr2_ahf_clk;
extern taishan_cg_node_t g_ckgen_gating_etmr3_ahf_clk;
extern taishan_cg_node_t g_ckgen_gating_etmr4_ahf_clk;
extern taishan_cg_node_t g_ckgen_gating_epwm1_ahf_clk;
extern taishan_cg_node_t g_ckgen_gating_epwm2_ahf_clk;
extern taishan_cg_node_t g_ckgen_gating_epwm3_ahf_clk;
extern taishan_cg_node_t g_ckgen_gating_epwm4_ahf_clk;
extern taishan_cg_node_t g_ckgen_gating_etmr1_hf_clk;
extern taishan_cg_node_t g_ckgen_gating_etmr2_hf_clk;
extern taishan_cg_node_t g_ckgen_gating_etmr3_hf_clk;
extern taishan_cg_node_t g_ckgen_gating_etmr4_hf_clk;
extern taishan_cg_node_t g_ckgen_gating_epwm1_hf_clk;
extern taishan_cg_node_t g_ckgen_gating_epwm2_hf_clk;
extern taishan_cg_node_t g_ckgen_gating_epwm3_hf_clk;
extern taishan_cg_node_t g_ckgen_gating_epwm4_hf_clk;
extern taishan_cg_node_t g_ckgen_gating_canfd1_ipg_clk;
extern taishan_cg_node_t g_ckgen_gating_canfd2_ipg_clk;
extern taishan_cg_node_t g_ckgen_gating_canfd3_ipg_clk;
extern taishan_cg_node_t g_ckgen_gating_canfd4_ipg_clk;
extern taishan_cg_node_t g_ckgen_gating_canfd5_ipg_clk;
extern taishan_cg_node_t g_ckgen_gating_canfd6_ipg_clk;
extern taishan_cg_node_t g_ckgen_gating_canfd7_ipg_clk;
extern taishan_cg_node_t g_ckgen_gating_canfd8_ipg_clk;
extern taishan_cg_node_t g_ckgen_gating_canfd9_ipg_clk;
extern taishan_cg_node_t g_ckgen_gating_canfd10_ipg_clk;
extern taishan_cg_node_t g_ckgen_gating_canfd11_ipg_clk;
extern taishan_cg_node_t g_ckgen_gating_canfd12_ipg_clk;
extern taishan_cg_node_t g_ckgen_gating_canfd13_ipg_clk;
extern taishan_cg_node_t g_ckgen_gating_canfd14_ipg_clk;
extern taishan_cg_node_t g_ckgen_gating_canfd15_ipg_clk;
extern taishan_cg_node_t g_ckgen_gating_canfd16_ipg_clk;
extern taishan_cg_node_t g_ckgen_gating_canfd17_ipg_clk;
extern taishan_cg_node_t g_ckgen_gating_canfd18_ipg_clk;
extern taishan_cg_node_t g_ckgen_gating_canfd19_ipg_clk;
extern taishan_cg_node_t g_ckgen_gating_canfd20_ipg_clk;
extern taishan_cg_node_t g_ckgen_gating_canfd21_ipg_clk;
extern taishan_cg_node_t g_ckgen_gating_canfd22_ipg_clk;
extern taishan_cg_node_t g_ckgen_gating_canfd23_ipg_clk;
extern taishan_cg_node_t g_ckgen_gating_canfd24_ipg_clk;
extern taishan_cg_node_t g_ckgen_gating_sadc1_ctrl_clk;
extern taishan_cg_node_t g_ckgen_gating_sadc2_ctrl_clk;
extern taishan_cg_node_t g_ckgen_gating_sadc3_ctrl_clk;
extern taishan_cg_node_t g_ckgen_gating_acmp1_ctrl_clk;
extern taishan_cg_node_t g_ckgen_gating_acmp2_ctrl_clk;
extern taishan_cg_node_t g_ckgen_gating_acmp3_ctrl_clk;
extern taishan_cg_node_t g_ckgen_gating_acmp4_ctrl_clk;
extern taishan_cg_node_t g_ckgen_gating_flexray1_ipg_clk;
extern taishan_cg_node_t g_ckgen_gating_flexray2_ipg_clk;
extern taishan_cg_node_t g_ckgen_gating_ioc_clk;
extern taishan_cg_node_t g_ckgen_gating_pt_sns_sf_clkin;
extern taishan_cg_node_t g_ckgen_gating_istc_i_istc_clk;
extern taishan_cg_node_t g_ckgen_gating_smc_clk_24m;
extern taishan_cg_node_t g_ckgen_gating_canfd1_clk24m;
extern taishan_cg_node_t g_ckgen_gating_canfd2_clk24m;
extern taishan_cg_node_t g_ckgen_gating_canfd3_clk24m;
extern taishan_cg_node_t g_ckgen_gating_canfd4_clk24m;
extern taishan_cg_node_t g_ckgen_gating_canfd5_clk24m;
extern taishan_cg_node_t g_ckgen_gating_canfd6_clk24m;
extern taishan_cg_node_t g_ckgen_gating_canfd7_clk24m;
extern taishan_cg_node_t g_ckgen_gating_canfd8_clk24m;
extern taishan_cg_node_t g_ckgen_gating_canfd9_clk24m;
extern taishan_cg_node_t g_ckgen_gating_canfd10_clk24m;
extern taishan_cg_node_t g_ckgen_gating_canfd11_clk24m;
extern taishan_cg_node_t g_ckgen_gating_canfd12_clk24m;
extern taishan_cg_node_t g_ckgen_gating_canfd13_clk24m;
extern taishan_cg_node_t g_ckgen_gating_canfd14_clk24m;
extern taishan_cg_node_t g_ckgen_gating_canfd15_clk24m;
extern taishan_cg_node_t g_ckgen_gating_canfd16_clk24m;
extern taishan_cg_node_t g_ckgen_gating_canfd17_clk24m;
extern taishan_cg_node_t g_ckgen_gating_canfd18_clk24m;
extern taishan_cg_node_t g_ckgen_gating_canfd19_clk24m;
extern taishan_cg_node_t g_ckgen_gating_canfd20_clk24m;
extern taishan_cg_node_t g_ckgen_gating_canfd21_clk24m;
extern taishan_cg_node_t g_ckgen_gating_canfd22_clk24m;
extern taishan_cg_node_t g_ckgen_gating_canfd23_clk24m;
extern taishan_cg_node_t g_ckgen_gating_canfd24_clk24m;
extern taishan_cg_node_t g_ckgen_gating_xtrg_wdt_clk;
extern taishan_cg_node_t g_ckgen_gating_ldo_dig_pclk;
extern taishan_cg_node_t g_ckgen_gating_dcdc1_clk_24m;
extern taishan_cg_node_t g_ckgen_gating_vic1_wdt_ref_clk;
extern taishan_cg_node_t g_ckgen_gating_vic3a_wdt_ref_clk;
extern taishan_cg_node_t g_ckgen_gating_vic3b_wdt_ref_clk;
extern taishan_cg_node_t g_ckgen_gating_wdt1_main_clk;
extern taishan_cg_node_t g_ckgen_gating_wdt2_main_clk;
extern taishan_cg_node_t g_ckgen_gating_wdt5_main_clk;
extern taishan_cg_node_t g_ckgen_gating_wdt6_main_clk;
extern taishan_cg_node_t g_ckgen_gating_btm1_i_xtal24mhz_clk;
extern taishan_cg_node_t g_ckgen_gating_btm2_i_xtal24mhz_clk;
extern taishan_cg_node_t g_ckgen_gating_btm3_i_xtal24mhz_clk;
extern taishan_cg_node_t g_ckgen_gating_btm4_i_xtal24mhz_clk;
extern taishan_cg_node_t g_ckgen_gating_btm5_i_xtal24mhz_clk;
extern taishan_cg_node_t g_ckgen_gating_btm6_i_xtal24mhz_clk;
extern taishan_cg_node_t g_ckgen_gating_pt_sns_sf_dig_clk_24m;
extern taishan_cg_node_t g_ckgen_gating_gama1_hclk;
extern taishan_cg_node_t g_ckgen_gating_xspi_slv_aclk;
extern taishan_cg_node_t g_ckgen_gating_vic2a_hclk;
extern taishan_cg_node_t g_ckgen_gating_vic2b_hclk;
extern taishan_cg_node_t g_ckgen_gating_vic_sp_irqsync;
extern taishan_cg_node_t g_ckgen_gating_enet1_aclk;
extern taishan_cg_node_t g_ckgen_gating_enet2_aclk;
extern taishan_cg_node_t g_ckgen_gating_gama1_aclk;
extern taishan_cg_node_t g_ckgen_gating_ahb_syncup_gama1_mainclk;
extern taishan_cg_node_t g_ckgen_gating_iramc4_aclk;
extern taishan_cg_node_t g_ckgen_gating_wdt3_pclk;
extern taishan_cg_node_t g_ckgen_gating_wdt3_bus_clk;
extern taishan_cg_node_t g_ckgen_gating_wdt4_pclk;
extern taishan_cg_node_t g_ckgen_gating_wdt4_bus_clk;
extern taishan_cg_node_t g_ckgen_gating_ppc_apbmux5_pclk;
extern taishan_cg_node_t g_ckgen_gating_apbmux5_pclk;
extern taishan_cg_node_t g_ckgen_gating_xspi_slv_pclk;
extern taishan_cg_node_t g_ckgen_gating_enet1_clk_csr;
extern taishan_cg_node_t g_ckgen_gating_enet2_clk_csr;
extern taishan_cg_node_t g_ckgen_gating_adma_enet1_perclk;
extern taishan_cg_node_t g_ckgen_gating_adma_enet2_perclk;
extern taishan_cg_node_t g_ckgen_gating_sp_mac_pclk;
extern taishan_cg_node_t g_ckgen_gating_cr5_sp_mix_mac_pclk;
extern taishan_cg_node_t g_ckgen_gating_eic_sp_i_pclk;
extern taishan_cg_node_t g_ckgen_gating_cslite_pclkdbg;
extern taishan_cg_node_t g_ckgen_gating_cslite_pclksys;
extern taishan_cg_node_t g_ckgen_gating_apb_cr5sx0_dbg_slv_src_pclk;
extern taishan_cg_node_t g_ckgen_gating_apb_cr5sx1_dbg_slv_src_pclk;
extern taishan_cg_node_t g_ckgen_gating_apb_cr5sf_dbg_slv_src_pclk;
extern taishan_cg_node_t g_ckgen_gating_iramc4_pclk;
extern taishan_cg_node_t g_ckgen_gating_wdt3_main_clk;
extern taishan_cg_node_t g_ckgen_gating_wdt4_main_clk;
extern taishan_cg_node_t g_ckgen_gating_vic2a_wdt_ref_clk;
extern taishan_cg_node_t g_ckgen_gating_vic2b_wdt_ref_clk;
extern taishan_cg_node_t g_ckgen_gating_rtc_pclk;
extern taishan_cg_node_t g_ckgen_gating_ap_apmainclk;
extern taishan_cg_node_t g_ckgen_gating_ap_dispclk;
extern taishan_cg_node_t g_ckgen_gating_ap_perclk;
extern taishan_cg_node_t g_ckgen_gating_ap_hsmperclk;
extern taishan_cg_node_t g_ckgen_gating_ap_sdramclk;
extern taishan_cg_node_t g_ckgen_gating_disp_mainclk;
extern taishan_cg_node_t g_ckgen_gating_disp_perclk;
extern taishan_cg_node_t g_ckgen_gating_sehc1_aclk;
extern taishan_cg_node_t g_ckgen_gating_sehc2_aclk;
extern taishan_cg_node_t g_ckgen_gating_dma_ap_clk;
extern taishan_cg_node_t g_ckgen_gating_dma_ap_aclk;
extern taishan_cg_node_t g_ckgen_gating_dma_ap_hclk;
extern taishan_cg_node_t g_ckgen_gating_seip_sh_clk;
extern taishan_cg_node_t g_ckgen_gating_apbmux6_pclk;
extern taishan_cg_node_t g_ckgen_gating_sdramc_pclk;
extern taishan_cg_node_t g_ckgen_gating_gpio_ap_pclk;
extern taishan_cg_node_t g_ckgen_gating_iomuxc_ap_pclk;
extern taishan_cg_node_t g_ckgen_gating_ckgen_ap_pclk;
extern taishan_cg_node_t g_ckgen_gating_usb2_pclk;
extern taishan_cg_node_t g_ckgen_gating_sehc1_pclk;
extern taishan_cg_node_t g_ckgen_gating_sehc2_pclk;
extern taishan_cg_node_t g_ckgen_gating_rstgen_ap_pclk;
extern taishan_cg_node_t g_ckgen_gating_wdt8_pclk;
extern taishan_cg_node_t g_ckgen_gating_wdt8_bus_clk;
extern taishan_cg_node_t g_ckgen_gating_saci1_pclk;
extern taishan_cg_node_t g_ckgen_gating_saci2_pclk;
extern taishan_cg_node_t g_ckgen_gating_dma_ap_pclk;
extern taishan_cg_node_t g_ckgen_gating_ap_mac_pclk;
extern taishan_cg_node_t g_ckgen_gating_vd_ap_pclk;
extern taishan_cg_node_t g_ckgen_gating_pt_sns_ap_pclk;
extern taishan_cg_node_t g_ckgen_gating_scr_ap_pclk;
extern taishan_cg_node_t g_ckgen_gating_por_ap_pclk;
extern taishan_cg_node_t g_ckgen_gating_seip_pclk;
extern taishan_cg_node_t g_ckgen_gating_seip_hclk;
extern taishan_cg_node_t g_ckgen_gating_seip_fd_ref_clk;
extern taishan_cg_node_t g_ckgen_gating_sdramc_aclk;
extern taishan_cg_node_t g_ckgen_gating_sehc1_main_clk;
extern taishan_cg_node_t g_ckgen_gating_sehc2_main_clk;
extern taishan_cg_node_t g_ckgen_gating_saci1_i2s_mclk;
extern taishan_cg_node_t g_ckgen_gating_saci2_i2s_mclk;
extern taishan_cg_node_t g_ckgen_gating_saci1_ext_clk;
extern taishan_cg_node_t g_ckgen_gating_saci2_ext_clk;
extern taishan_cg_node_t g_ckgen_gating_saci1_i2s_tx_clk;
extern taishan_cg_node_t g_ckgen_gating_saci2_i2s_tx_clk;
extern taishan_cg_node_t g_ckgen_gating_saci1_i2s_rx_clk;
extern taishan_cg_node_t g_ckgen_gating_saci2_i2s_rx_clk;
extern taishan_cg_node_t g_ckgen_gating_saci1_pdm_per_clk;
extern taishan_cg_node_t g_ckgen_gating_saci2_pdm_per_clk;
extern taishan_cg_node_t g_ckgen_gating_pt_sns_ap_clkin;
extern taishan_cg_node_t g_ckgen_gating_usb_phy_ref_clk;
extern taishan_cg_node_t g_ckgen_gating_wdt8_main_clk;
extern taishan_cg_node_t g_ckgen_gating_sehc1_cqe_sqs_clk;
extern taishan_cg_node_t g_ckgen_gating_sehc2_cqe_sqs_clk;
extern taishan_cg_node_t g_ckgen_gating_sehc1_tm_clk;
extern taishan_cg_node_t g_ckgen_gating_sehc2_tm_clk;
extern taishan_cg_node_t g_ckgen_gating_csi_axi_clk;
extern taishan_cg_node_t g_ckgen_gating_dc_axi_clk;
extern taishan_cg_node_t g_ckgen_gating_g2d_axi_clk;
extern taishan_cg_node_t g_ckgen_gating_csi_pclk;
extern taishan_cg_node_t g_ckgen_gating_apbmux7_pclk;
extern taishan_cg_node_t g_ckgen_gating_disp_mux_pclk;
extern taishan_cg_node_t g_ckgen_gating_dc_pix_clk;
extern taishan_cg_node_t g_ckgen_gating_csi_proc_clk;
extern taishan_cg_node_t g_ckgen_gating_disp_mux_disp_ckgen_pix_clk;
extern taishan_cg_node_t g_ckgen_gating_lvds_ch0_clk_x14;
extern taishan_cg_node_t g_ckgen_gating_lvds_ch0_clk_x7;
extern taishan_cg_node_t g_ckgen_gating_dc_dsp_clk;

extern void board_clk_init(void);


#endif