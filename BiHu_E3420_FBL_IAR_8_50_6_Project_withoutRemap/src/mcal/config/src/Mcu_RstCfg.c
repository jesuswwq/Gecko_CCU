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
 * @file  Mcu_RstCfg.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Mcu Driver.
 * @date 2023-09-25 14:53:14
*/

#ifdef __cplusplus
extern "C" {
#endif

#include <taishan_reset_drv.h>
#include <__regs_base.h>

#include "Mcu_Reset.h"


#define MCU_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

reset_ctl_t g_rstgen_saf;
reset_ctl_t g_rstgen_ap;

#define MCU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"



taishan_reset_ctl_t taishan_rstgen_sf_dev = {
    .base = APB_RSTGEN_SF_BASE,
};

taishan_reset_ctl_t taishan_rstgen_ap_dev = {
    .base = APB_RSTGEN_AP_BASE,
};

reset_glb_ctl_t rstctl_glb= {
    .rst_sf_ctl = &g_rstgen_saf,
};

reset_sig_t rstsig_rstgen_ap = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_RSTGEN_AP,
};

reset_sig_t rstsig_cr5_saf = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_CR5_SAF,
};

reset_sig_t rstsig_cr5_sp0 = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_CR5_SP0,
};

reset_sig_t rstsig_cr5_sp1 = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_CR5_SP1,
};

reset_sig_t rstsig_cr5_sx0 = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_CR5_SX0,
};

reset_sig_t rstsig_cr5_sx1 = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_CR5_SX1,
};

reset_sig_t rstsig_mac = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_MAC,
};

reset_sig_t rstsig_scr_boot = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_SCR_BOOT,
};

reset_sig_t rstsig_gpio_sf = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_GPIO_SF,
};

reset_sig_t rstsig_wdt1_2 = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_WDT1_2,
};

reset_sig_t rstsig_sem = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_SEM,
};

reset_sig_t rstsig_ana_sf = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_ANA_SF,
};

reset_sig_t rstsig_scr_sf = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_SCR_SF,
};

reset_sig_t rstsig_uart = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_UART,
};

reset_sig_t rstsig_spi = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_SPI,
};

reset_sig_t rstsig_i2c = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_I2C,
};

reset_sig_t rstsig_flexray = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_FLEXRAY,
};

reset_sig_t rstsig_wdt5_6 = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_WDT5_6,
};

reset_sig_t rstsig_wdt3_4 = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_WDT3_4,
};

reset_sig_t rstsig_canfd1 = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_CANFD1,
};

reset_sig_t rstsig_canfd2 = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_CANFD2,
};

reset_sig_t rstsig_canfd3_4 = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_CANFD3_4,
};

reset_sig_t rstsig_canfd5_8 = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_CANFD5_8,
};

reset_sig_t rstsig_canfd9_16 = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_CANFD9_16,
};

reset_sig_t rstsig_canfd17_24 = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_CANFD17_24,
};

reset_sig_t rstsig_xspi1a = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_XSPI1A,
};

reset_sig_t rstsig_xspi1b = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_XSPI1B,
};

reset_sig_t rstsig_xspi2a = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_XSPI2A,
};

reset_sig_t rstsig_xspi2b = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_XSPI2B,
};

reset_sig_t rstsig_dma_rst0 = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_DMA_RST0,
};

reset_sig_t rstsig_dma_rst1 = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_DMA_RST1,
};

reset_sig_t rstsig_ahb_syncup_gama1 = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_AHB_SYNCUP_GAMA1,
};

reset_sig_t rstsig_enet1 = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_ENET1,
};

reset_sig_t rstsig_enet2 = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_ENET2,
};

reset_sig_t rstsig_gama1 = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_GAMA1,
};

reset_sig_t rstsig_gama2 = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_GAMA2,
};

reset_sig_t rstsig_ahb_syncup_gama2 = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_AHB_SYNCUP_GAMA2,
};

reset_sig_t rstsig_vic1 = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_VIC1,
};

reset_sig_t rstsig_vic2_porta = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_VIC2_PORTA,
};

reset_sig_t rstsig_vic2_portb = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_VIC2_PORTB,
};

reset_sig_t rstsig_vic3_porta = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_VIC3_PORTA,
};

reset_sig_t rstsig_vic3_portb = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_VIC3_PORTB,
};

reset_sig_t rstsig_xspi_slv = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_XSPI_SLV,
};

reset_sig_t rstsig_mb = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_MB,
};

reset_sig_t rstsig_xtrg = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_XTRG,
};

reset_sig_t rstsig_disp_mux = {
    .rst_ctl = &g_rstgen_ap,
    .id      = RSTSIG_AP_DISP_MUX,
};

reset_sig_t rstsig_gpio_ap = {
    .rst_ctl = &g_rstgen_ap,
    .id      = RSTSIG_AP_GPIO_AP,
};

reset_sig_t rstsig_wdt8 = {
    .rst_ctl = &g_rstgen_ap,
    .id      = RSTSIG_AP_WDT8,
};

reset_sig_t rstsig_scr_ap = {
    .rst_ctl = &g_rstgen_ap,
    .id      = RSTSIG_AP_SCR_AP,
};

reset_sig_t rstsig_csi = {
    .rst_ctl = &g_rstgen_ap,
    .id      = RSTSIG_AP_CSI,
};

reset_sig_t rstsig_dc = {
    .rst_ctl = &g_rstgen_ap,
    .id      = RSTSIG_AP_DC,
};

reset_sig_t rstsig_g2d = {
    .rst_ctl = &g_rstgen_ap,
    .id      = RSTSIG_AP_G2D,
};

reset_sig_t rstsig_sdramc = {
    .rst_ctl = &g_rstgen_ap,
    .id      = RSTSIG_AP_SDRAMC,
};

reset_sig_t rstsig_saci1 = {
    .rst_ctl = &g_rstgen_ap,
    .id      = RSTSIG_AP_SACI1,
};

reset_sig_t rstsig_saci2 = {
    .rst_ctl = &g_rstgen_ap,
    .id      = RSTSIG_AP_SACI2,
};

reset_sig_t rstsig_dma_ap = {
    .rst_ctl = &g_rstgen_ap,
    .id      = RSTSIG_AP_DMA_AP,
};

reset_sig_t rstsig_sehc1 = {
    .rst_ctl = &g_rstgen_ap,
    .id      = RSTSIG_AP_SEHC1,
};

reset_sig_t rstsig_sehc2 = {
    .rst_ctl = &g_rstgen_ap,
    .id      = RSTSIG_AP_SEHC2,
};

reset_sig_t rstsig_usb = {
    .rst_ctl = &g_rstgen_ap,
    .id      = RSTSIG_AP_USB,
};

reset_sig_t rstsig_seip = {
    .rst_ctl = &g_rstgen_ap,
    .id      = RSTSIG_AP_SEIP,
};

reset_sig_t rstsig_lvds_ss = {
    .rst_ctl = &g_rstgen_ap,
    .id      = RSTSIG_AP_LVDS_SS,
};

reset_sig_t rstsig_saf_mission6 = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_MISSION6,
};

reset_sig_t rstsig_ap_mission1 = {
    .rst_ctl = &g_rstgen_ap,
    .id      = RSTSIG_AP_MISSION1,
};

reset_sig_t rstsig_saf_debug = {
    .rst_ctl = &g_rstgen_saf,
    .id      = RSTSIG_SAF_DEBUG,
};

reset_sig_t rstsig_ap_debug = {
    .rst_ctl = &g_rstgen_ap,
    .id      = RSTSIG_AP_DEBUG,
};

#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

const reset_sig_t * const xspi_reset_array[] = {
    &rstsig_xspi1a,
    &rstsig_xspi1b,
    &rstsig_xspi2a,
    &rstsig_xspi2b,
};

const reset_sig_t * const deassert_array[] = {
    &rstsig_uart,
    &rstsig_canfd5_8,
    &rstsig_vic1,
    &rstsig_xspi_slv,
    &rstsig_seip,
};

const reset_sig_t * const assert_array[] = {
    &rstsig_cr5_sp0,
    &rstsig_cr5_sp1,
    &rstsig_canfd1,
    &rstsig_canfd2,
    &rstsig_saci1,
    &rstsig_csi,
    &rstsig_g2d,
    &rstsig_lvds_ss,
    &rstsig_sdramc,
    &rstsig_ahb_syncup_gama1,
    &rstsig_gama1,
    &rstsig_gama2,
    &rstsig_ahb_syncup_gama2,
    &rstsig_dc,
    &rstsig_dma_ap,
    &rstsig_usb,
};

#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

uint32 Mcu_GetDeassertArraySize(void)
{
    return sizeof(deassert_array) / sizeof(deassert_array[0]);
}

uint32 Mcu_GetAssertArraySize(void)
{
    return sizeof(assert_array) / sizeof(assert_array[0]);
}

uint32 Mcu_GetXspiResetArraySize(void)
{
    return sizeof(xspi_reset_array) / sizeof(xspi_reset_array[0]);
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif
