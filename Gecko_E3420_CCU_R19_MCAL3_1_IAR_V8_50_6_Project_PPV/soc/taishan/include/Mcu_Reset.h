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

#ifndef BOARDS_RSTGEN_CFG_H
#define BOARDS_RSTGEN_CFG_H

#define CONFIG_RESETGEN 1
#ifdef CONFIG_RESETGEN

#include <reset.h>

extern reset_glb_ctl_t rstctl_glb;
extern reset_sig_t rstsig_rstgen_ap;
extern reset_sig_t rstsig_cr5_saf;
extern reset_sig_t rstsig_cr5_sp0;
extern reset_sig_t rstsig_cr5_sp1;
extern reset_sig_t rstsig_cr5_sx0;
extern reset_sig_t rstsig_cr5_sx1;
extern reset_sig_t rstsig_mac;
extern reset_sig_t rstsig_scr_boot;
extern reset_sig_t rstsig_gpio_sf;
extern reset_sig_t rstsig_wdt1_2;
extern reset_sig_t rstsig_sem;
extern reset_sig_t rstsig_ana_sf;
extern reset_sig_t rstsig_scr_sf;
extern reset_sig_t rstsig_uart;
extern reset_sig_t rstsig_spi;
extern reset_sig_t rstsig_i2c;
extern reset_sig_t rstsig_wdt5_6;
extern reset_sig_t rstsig_wdt3_4;
extern reset_sig_t rstsig_canfd1;
extern reset_sig_t rstsig_canfd2;
extern reset_sig_t rstsig_canfd3_4;
extern reset_sig_t rstsig_canfd5_8;
extern reset_sig_t rstsig_canfd9_16;
extern reset_sig_t rstsig_canfd17_24;
extern reset_sig_t rstsig_xspi1a;
extern reset_sig_t rstsig_xspi1b;
extern reset_sig_t rstsig_xspi2a;
extern reset_sig_t rstsig_xspi2b;
extern reset_sig_t rstsig_dma_rst0;
extern reset_sig_t rstsig_dma_rst1;
extern reset_sig_t rstsig_ahb_syncup_gama1;
extern reset_sig_t rstsig_enet1;
extern reset_sig_t rstsig_enet2;
extern reset_sig_t rstsig_gama1;
extern reset_sig_t rstsig_gama2;
extern reset_sig_t rstsig_ahb_syncup_gama2;
extern reset_sig_t rstsig_vic1;
extern reset_sig_t rstsig_vic2_porta;
extern reset_sig_t rstsig_vic2_portb;
extern reset_sig_t rstsig_vic3_porta;
extern reset_sig_t rstsig_vic3_portb;
extern reset_sig_t rstsig_xspi_slv;
extern reset_sig_t rstsig_mb;
extern reset_sig_t rstsig_xtrg;
extern reset_sig_t rstsig_disp_mux;
extern reset_sig_t rstsig_gpio_ap;
extern reset_sig_t rstsig_wdt8;
extern reset_sig_t rstsig_scr_ap;
extern reset_sig_t rstsig_csi;
extern reset_sig_t rstsig_dc;
extern reset_sig_t rstsig_g2d;
extern reset_sig_t rstsig_sdramc;
extern reset_sig_t rstsig_saci1;
extern reset_sig_t rstsig_saci2;
extern reset_sig_t rstsig_dma_ap;
extern reset_sig_t rstsig_sehc1;
extern reset_sig_t rstsig_sehc2;
extern reset_sig_t rstsig_usb;
extern reset_sig_t rstsig_seip;
extern reset_sig_t rstsig_lvds_ss;

extern reset_sig_t rstsig_saf_mission6;
extern reset_sig_t rstsig_ap_mission1;
extern reset_sig_t rstsig_saf_debug;
extern reset_sig_t rstsig_ap_debug;

extern void board_reset_init(void);

#endif

#endif /* BOARDS_RSTGEN_CFG_H */
