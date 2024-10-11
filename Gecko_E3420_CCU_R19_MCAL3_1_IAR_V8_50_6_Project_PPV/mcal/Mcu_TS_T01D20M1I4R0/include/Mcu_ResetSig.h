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
 *  \file     Mcu_ResetSig.h                                                                            *
 *  \brief    This file contains interface header for MCU MCAL driver                                   *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/09/09     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef MCU_RESETSIG_H
#define MCU_RESETSIG_H

#include "Mcu_Reset.h"
#ifdef SEMIDRIVE_E3_LITE_SERIES
extern const Mcu_ResetSigType rstsig_cr5_saf;
extern const Mcu_ResetSigType rstsig_boot;
extern const Mcu_ResetSigType rstsig_ss;
extern const Mcu_ResetSigType rstsig_pll;
extern const Mcu_ResetSigType rstsig_ana_sf;
extern const Mcu_ResetSigType rstsig_iram_mix;
extern const Mcu_ResetSigType rstsig_dcdc_mix;
extern const Mcu_ResetSigType rstsig_ap_mix;
extern const Mcu_ResetSigType rstsig_canfd16;
extern const Mcu_ResetSigType rstsig_canfd21;
extern const Mcu_ResetSigType rstsig_canfd3;
extern const Mcu_ResetSigType rstsig_canfd4;
extern const Mcu_ResetSigType rstsig_canfd5;
extern const Mcu_ResetSigType rstsig_canfd6;
extern const Mcu_ResetSigType rstsig_canfd7;
extern const Mcu_ResetSigType rstsig_canfd23;
extern const Mcu_ResetSigType rstsig_xspi1a;
extern const Mcu_ResetSigType rstsig_xspi1b;
extern const Mcu_ResetSigType rstsig_dma_rst0;
extern const Mcu_ResetSigType rstsig_dma_rst1;
extern const Mcu_ResetSigType rstsig_enet1;
extern const Mcu_ResetSigType rstsig_vic1;
extern const Mcu_ResetSigType rstsig_xspi_slv;
extern const Mcu_ResetSigType rstsig_xtrg;
extern const Mcu_ResetSigType rstsig_saci1;
extern const Mcu_ResetSigType rstsig_sehc1;
extern const Mcu_ResetSigType rstsig_usb;
extern const Mcu_ResetSigType rstsig_seip;
extern const Mcu_ResetSigType rstsig_cslite;

extern const Mcu_ResetGlbCtlType rstctl_glb;

extern const Mcu_ResetGeneralRegType reset_general_reg_sf_boot;
extern const Mcu_ResetGeneralRegType reset_general_reg_rom_ctrl;
extern const Mcu_ResetGeneralRegType reset_general_reg_sf_remap;
extern const Mcu_ResetGeneralRegType reset_general_reg_sf_test;
#else
extern const Mcu_ResetGlbCtlType rstctl_glb;
extern const Mcu_ResetSigType rstsig_rstgen_ap;
extern const Mcu_ResetSigType rstsig_cr5_saf;
extern const Mcu_ResetSigType rstsig_cr5_sp0;
extern const Mcu_ResetSigType rstsig_cr5_sp1;
extern const Mcu_ResetSigType rstsig_cr5_sx0;
extern const Mcu_ResetSigType rstsig_cr5_sx1;
extern const Mcu_ResetSigType rstsig_mac;
extern const Mcu_ResetSigType rstsig_scr_boot;
extern const Mcu_ResetSigType rstsig_gpio_sf;
extern const Mcu_ResetSigType rstsig_wdt1_2;
extern const Mcu_ResetSigType rstsig_sem;
extern const Mcu_ResetSigType rstsig_saf_mission0;
extern const Mcu_ResetSigType rstsig_saf_mission1;
extern const Mcu_ResetSigType rstsig_saf_mission2;
extern const Mcu_ResetSigType rstsig_uart;
extern const Mcu_ResetSigType rstsig_spi;
extern const Mcu_ResetSigType rstsig_i2c;
extern const Mcu_ResetSigType rstsig_flexray;
extern const Mcu_ResetSigType rstsig_wdt5_6;
extern const Mcu_ResetSigType rstsig_saf_mission4;
extern const Mcu_ResetSigType rstsig_wdt3_4;
extern const Mcu_ResetSigType rstsig_saf_mission8;
extern const Mcu_ResetSigType rstsig_saf_mission9;
extern const Mcu_ResetSigType rstsig_canfd1;
extern const Mcu_ResetSigType rstsig_canfd2;
extern const Mcu_ResetSigType rstsig_canfd3_4;
extern const Mcu_ResetSigType rstsig_canfd5_8;
extern const Mcu_ResetSigType rstsig_canfd9_16;
extern const Mcu_ResetSigType rstsig_canfd17_24;
extern const Mcu_ResetSigType rstsig_xspi1a;
extern const Mcu_ResetSigType rstsig_xspi1b;
extern const Mcu_ResetSigType rstsig_xspi2a;
extern const Mcu_ResetSigType rstsig_xspi2b;
extern const Mcu_ResetSigType rstsig_dma_rst0;
extern const Mcu_ResetSigType rstsig_dma_rst1;
extern const Mcu_ResetSigType rstsig_ahb_syncup_gama1;
extern const Mcu_ResetSigType rstsig_enet1;
extern const Mcu_ResetSigType rstsig_enet2;
extern const Mcu_ResetSigType rstsig_gama1;
extern const Mcu_ResetSigType rstsig_gama2;
extern const Mcu_ResetSigType rstsig_ahb_syncup_gama2;
extern const Mcu_ResetSigType rstsig_vic1;
extern const Mcu_ResetSigType rstsig_vic2_porta;
extern const Mcu_ResetSigType rstsig_vic2_portb;
extern const Mcu_ResetSigType rstsig_vic3_porta;
extern const Mcu_ResetSigType rstsig_vic3_portb;
extern const Mcu_ResetSigType rstsig_xspi_slv;
extern const Mcu_ResetSigType rstsig_mb;
extern const Mcu_ResetSigType rstsig_xtrg;
extern const Mcu_ResetSigType rstsig_ap_mission0;
extern const Mcu_ResetSigType rstsig_disp_mux;
extern const Mcu_ResetSigType rstsig_gpio_ap;
extern const Mcu_ResetSigType rstsig_wdt8;
extern const Mcu_ResetSigType rstsig_scr_ap;
extern const Mcu_ResetSigType rstsig_csi;
extern const Mcu_ResetSigType rstsig_dc;
extern const Mcu_ResetSigType rstsig_g2d;
extern const Mcu_ResetSigType rstsig_sdramc;
extern const Mcu_ResetSigType rstsig_saci1;
extern const Mcu_ResetSigType rstsig_saci2;
extern const Mcu_ResetSigType rstsig_dma_ap;
extern const Mcu_ResetSigType rstsig_sehc1;
extern const Mcu_ResetSigType rstsig_sehc2;
extern const Mcu_ResetSigType rstsig_usb;
extern const Mcu_ResetSigType rstsig_seip;
extern const Mcu_ResetSigType rstsig_lvds_ss;

extern const Mcu_ResetSigType rstsig_saf_mission6;
extern const Mcu_ResetSigType rstsig_ap_mission1;
extern const Mcu_ResetSigType rstsig_saf_debug;
extern const Mcu_ResetSigType rstsig_ap_debug;

extern const Mcu_ResetGeneralRegType reset_general_reg_sf_boot;
extern const Mcu_ResetGeneralRegType reset_general_reg_rom_ctrl;
extern const Mcu_ResetGeneralRegType reset_general_reg_sf_remap;
extern const Mcu_ResetGeneralRegType reset_general_reg_sf_test;

#endif /** #ifdef SEMIDRIVE_E3_LITE_SERIES*/
#endif /* MCU_RESETSIG_H */

/* End of file */
