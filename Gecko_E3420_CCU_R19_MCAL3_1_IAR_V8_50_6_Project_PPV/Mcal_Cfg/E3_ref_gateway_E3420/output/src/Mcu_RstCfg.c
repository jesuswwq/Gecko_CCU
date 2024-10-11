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
 * \file     Mcu_RstCfg.c                                                                               *
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
#include "Mcu_ResetDrv.h"
#include "Mcu_ResetSig.h"
#include "Mcu_Cfg.h"


#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"
/* PRQA S 4424,1533,1504,1531 EOF */


static const Mcu_ResetCtlType Mcu_RstgenSaf = {
    .ops = &Mcu_RstCtlOps,
    .base = APB_RSTGEN_SF_BASE,
};

static const Mcu_ResetCtlType Mcu_RstgenAp = {
    .ops = &Mcu_RstCtlOps,
    .base = APB_RSTGEN_AP_BASE,
};

const Mcu_ResetGlbCtlType rstctl_glb= {
    .rstSfCtl = &Mcu_RstgenSaf,
};

/* SAF core */
const Mcu_ResetSigType rstsig_rstgen_ap = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_RSTGEN_AP,
};

const Mcu_ResetSigType rstsig_cr5_saf = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_CR5_SAF,
};

const Mcu_ResetSigType rstsig_cr5_sp0 = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_CR5_SP0,
};

const Mcu_ResetSigType rstsig_cr5_sp1 = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_CR5_SP1,
};

const Mcu_ResetSigType rstsig_cr5_sx0 = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_CR5_SX0,
};

const Mcu_ResetSigType rstsig_cr5_sx1 = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_CR5_SX1,
};

/**
 * @brief SAF latent
 *
 * latent signals will reset automatically after power on.
 *
 * signals in SAF latent:
 * MAC
 * SCR_BOOT
 * EIC_BOOT
 * FUSE_LSP_CMP
 * AHB2APB1
 * AHB2APB2
 * AHB2APB3
 * AHB2APB4
 * APBMUX2
 * APBMUX3
 * APBMUX4
 * IROMC
 * GPIO_SF
 * IOMUXC_SF
 * WDT1
 * WDT2
 * SEM1
 * SEM2
 * VD_SF_DIG
 * IOC
 * ETMR1
 * ETMR2
 * ETMR3
 * ETMR4
 * EPWM1
 * EPWM2
 * EPWM3
 * EPWM4
 * MPC_XSPI1A
 * MPC_XSPI1B
 * PPC_APBMUX2
 * PPC_APBMUX3
 * PPC_APBMUX4
 * PPC_APBMUX1
 * MPC_ROMC
 * XB_SF
 * POR_SF_DIG
 * PT_SNS_SF_DIG
 * APB_MAC_SP_SLV
 * APB_MAC_AP_SLV
 * APB_APBMUX1_SLV
 * MPC_VIC1
 * MPC_VIC3A
 * MPC_VIC3B
 * BTM1
 * BTM2
 * BTM3
 * BTM4
 * BTM5
 * BTM6
 * AAPB_XSPI1A
 * AAPB_XSPI1B
*/
const Mcu_ResetSigType rstsig_mac = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_MAC,
};

const Mcu_ResetSigType rstsig_scr_boot = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_SCR_BOOT,
};

const Mcu_ResetSigType rstsig_gpio_sf = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_GPIO_SF,
};

const Mcu_ResetSigType rstsig_wdt1_2 = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_WDT1_2,
};

const Mcu_ResetSigType rstsig_sem = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_SEM,
};

/*
 * @brief SAF mission
 *
 * SAF mission signals will reset automatically after power on.
 *
 */

/**
 * @brief SAF mission 0
 *
 * signals in SAF mission 0:
 * FAB_SF
 * IOMUXC_SF
 * SCR_SF
 * SMC
 * MPC_CR5_SF
 * MPC_CR5_SX0
 * MPC_CR5_SX1
 * PMU_CORE
 * APB_APBMUX1_MST
 * APB_PMUX2_DEC_SLV
 * APB_PMUX2_DEC_MST
*/
const Mcu_ResetSigType rstsig_saf_mission0 = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_MISSION0,
};


/**
 * @brief SAF mission 1
 *
 * signals in mission 1:
 * PLL1
 * PLL2
 * PLL3
 */
const Mcu_ResetSigType rstsig_saf_mission1 = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_MISSION1,
};

/**
 * @brief SAF mission 2
 *
 * signals in SAF mission 2:
 * ANA_SF_SADC1
 * ANA_SF_SADC2
 * ANA_SF_SADC3
 * ANA_SF_ACMP1
 * ANA_SF_ACMP2
 * ANA_SF_ACMP3
 * ANA_SF_ACMP4
 */
const Mcu_ResetSigType rstsig_saf_mission2 = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_MISSION2,
};

/**
 * @brief SAF mission 3
 *
 * signals in SAF mission 3:
 * APBMUX3
 * APBMUX4
 * IOMUXC_SF_COMP
 * EIC_SF
 * UART1
 * UART2
 * UART3
 * UART4
 * UART5
 * UART6
 * UART7
 * UART8
 * UART9
 * UART10
 * UART11
 * UART12
 * UART13
 * UART14
 * UART15
 * UART16
 * SPI1
 * SPI2
 * SPI3
 * SPI4
 * SPI5
 * SPI6
 * SPI7
 * SPI8
 * I2C1
 * I2C2
 * I2C3
 * I2C4
 * I2C5
 * I2C6
 * I2C7
 * I2C8
 * MPC_XSPI2A
 * MPC_XSPI2B
 * FLEXRAY1
 * FLEXRAY2
 * WDT5
 * WDT6
 * MPC_MB
 * AAPB_XSPI2A
 * AAPB_XSPI2B
 * APB_APBMUX3_SLV
 * APB_APBMUX3_MST
 * APB_APBMUX4_SLV
 * APB_APBMUX4_MST
 * APB_SEIP_NVM_MST
 * APB_SEIP_NVM_SLV
 * ADB_SFAP_SLV
 * ADB_SFAP_MST
 * ADB_APSF_SLV
 * ADB_APSF_MST
 * ADB_DISPSF_SLV
 * ADB_DISPSF_MST
 * BTI_DISPSF
 * BTI_APSF
 */
const Mcu_ResetSigType rstsig_uart = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_UART,
};

const Mcu_ResetSigType rstsig_spi = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_SPI,
};

const Mcu_ResetSigType rstsig_i2c = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_I2C,
};

const Mcu_ResetSigType rstsig_flexray = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_FLEXRAY,
};

const Mcu_ResetSigType rstsig_wdt5_6 = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_WDT5_6,
};

/**
 * @brief SAF mission 4
 *
 * signals in SAF mission 4:
 * IRAMC1
 * IRAMC2
 * IRAMC3
 * IRAM_MUX
 * MPC_IRAMC1
 * MPC_IRAMC2
 * MPC_IRAMC3
 */
const Mcu_ResetSigType rstsig_saf_mission4 = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_MISSION4,
};

/**
 * @brief SAF mission 5
 *
 * signals in SAF mission 5:
 * IRAMC4
 * APBMUX5
 * WDT3
 * WDT4
 * PTB
 * FAB_SP
 * MPC_IRAMC4
 * MPC_CR5_SP0
 * MPC_CR5_SP1
 * PPC_APBMUX5
 * MPC_VIC2A
 * MPC_VIC2B
 * EIC_SP
 * CSLITE
 * AAHB_SPSF_SLV
 * AAHB_SPSF_MST
 * APB_MAC_SP_SLV
 * APB_MAC_SP_MST
 * ADB_SPAP_SLV
 * ADB_SPAP_MST
 */
const Mcu_ResetSigType rstsig_wdt3_4 = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_WDT3_4,
};

/**
 * @brief SAF mission 6
 *
 * signals in SAF mission 6:
 * reserved
 */
const Mcu_ResetSigType rstsig_saf_mission6 = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_MISSION6,
};

/**
 * @brief SAF mission 8
 *
 * signals in SAF mission 8:
 * LDO_DIG
 * APB_LDO_DIG_MST
 * APB_LDO_DIG_SLV
 */
const Mcu_ResetSigType rstsig_saf_mission8 = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_LDO,
};

/**
 * @brief SAF mission 9
 *
 * signals in SAF mission 9:
 * DCDC1
 * APB_DCDC1_MST
 * APB_DCDC1_SLV
 */
const Mcu_ResetSigType rstsig_saf_mission9 = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_DCDC,
};

/* SAF module */
const Mcu_ResetSigType rstsig_canfd1 = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_CANFD1,
};

const Mcu_ResetSigType rstsig_canfd2 = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_CANFD2,
};

const Mcu_ResetSigType rstsig_canfd3_4 = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_CANFD3_4,
};

const Mcu_ResetSigType rstsig_canfd5_8 = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_CANFD5_8,
};

const Mcu_ResetSigType rstsig_canfd9_16 = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_CANFD9_16,
};

const Mcu_ResetSigType rstsig_canfd17_24 = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_CANFD17_24,
};

const Mcu_ResetSigType rstsig_xspi1a = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_XSPI1A,
};

const Mcu_ResetSigType rstsig_xspi1b = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_XSPI1B,
};

const Mcu_ResetSigType rstsig_xspi2a = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_XSPI2A,
};

const Mcu_ResetSigType rstsig_xspi2b = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_XSPI2B,
};

const Mcu_ResetSigType rstsig_dma_rst0 = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_DMA_RST0,
};

const Mcu_ResetSigType rstsig_dma_rst1 = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_DMA_RST1,
};

const Mcu_ResetSigType rstsig_ahb_syncup_gama1 = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_AHB_SYNCUP_GAMA1,
};

const Mcu_ResetSigType rstsig_enet1 = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_ENET1,
};

const Mcu_ResetSigType rstsig_enet2 = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_ENET2,
};

const Mcu_ResetSigType rstsig_gama1 = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_GAMA1,
};

const Mcu_ResetSigType rstsig_gama2 = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_GAMA2,
};

const Mcu_ResetSigType rstsig_ahb_syncup_gama2 = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_AHB_SYNCUP_GAMA2,
};

const Mcu_ResetSigType rstsig_vic1 = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_VIC1,
};

const Mcu_ResetSigType rstsig_vic2_porta = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_VIC2_PORTA,
};

const Mcu_ResetSigType rstsig_vic2_portb = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_VIC2_PORTB,
};

const Mcu_ResetSigType rstsig_vic3_porta = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_VIC3_PORTA,
};

const Mcu_ResetSigType rstsig_vic3_portb = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_VIC3_PORTB,
};

const Mcu_ResetSigType rstsig_xspi_slv = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_XSPI_SLV,
};

const Mcu_ResetSigType rstsig_mb = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_MB,
};

const Mcu_ResetSigType rstsig_xtrg = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_XTRG,
};

/*
 * @brief AP mission
 *
 * AP mission signals will reset automatically after power on.
 *
 */

/**
 * @brief AP mision 0
 *
 * signals in AP mission 0:
 * PLL4
 * PLL5
 * PLL_LVDS
 */
const Mcu_ResetSigType rstsig_ap_mission0 = {
    .rstCtl = &Mcu_RstgenAp,
    .id      = RSTSIG_AP_MISSION0,
};

/**
 * @brief AP mision 1
 *
 * signals in AP mission 1:
 * APBMUX7
 * DISP_MUX
 * FAB_AP
 * VD_AP
 * APBMUX6
 * GPIO_AP
 * IOMUXC_AP
 * WDT8
 * MPC_SEIP
 * MPC_SDRAMC
 * PPC_APBMUX6
 * PPC_APBMUX7
 * FAB_DISP
 * AHBDEC_SEIP
 * PT_SNS_AP
 * POR_AP
 * SCR_AP
 * RSTGEN_AP
 * APB_MAC_AP_SLV
 * APB_MAC_AP_MST
 * APB_APBMUX7_SLV
 * APB_APBMUX7_MST
 * APB_SEC_STORAGE1_SLV
 * APB_SEC_STORAGE1_MST
 * APB_SEIP_NVM_MST
 * APB_SEIP_NVM_SLV
 * ADB_SPAP_SLV
 * ADB_SPAP_MST
 * ADB_SFAP_SLV
 * ADB_SFAP_MST
 * ADB_APSF_SLV
 * ADB_APSF_MST
 * ADB_DISPSF_SLV
 * ADB_DISPSF_MST
 * BTI_DISPSF
 * BTI_APSF
 */
const Mcu_ResetSigType rstsig_disp_mux = {
    .rstCtl = &Mcu_RstgenAp,
    .id      = RSTSIG_AP_DISP_MUX,
};

const Mcu_ResetSigType rstsig_gpio_ap = {
    .rstCtl = &Mcu_RstgenAp,
    .id      = RSTSIG_AP_GPIO_AP,
};

const Mcu_ResetSigType rstsig_wdt8 = {
    .rstCtl = &Mcu_RstgenAp,
    .id      = RSTSIG_AP_WDT8,
};

const Mcu_ResetSigType rstsig_scr_ap = {
    .rstCtl = &Mcu_RstgenAp,
    .id      = RSTSIG_AP_SCR_AP,
};

/* AP module */
const Mcu_ResetSigType rstsig_csi = {
    .rstCtl = &Mcu_RstgenAp,
    .id      = RSTSIG_AP_CSI,
};

const Mcu_ResetSigType rstsig_dc = {
    .rstCtl = &Mcu_RstgenAp,
    .id      = RSTSIG_AP_DC,
};

const Mcu_ResetSigType rstsig_g2d = {
    .rstCtl = &Mcu_RstgenAp,
    .id      = RSTSIG_AP_G2D,
};

const Mcu_ResetSigType rstsig_sdramc = {
    .rstCtl = &Mcu_RstgenAp,
    .id      = RSTSIG_AP_SDRAMC,
};

const Mcu_ResetSigType rstsig_saci1 = {
    .rstCtl = &Mcu_RstgenAp,
    .id      = RSTSIG_AP_SACI1,
};

const Mcu_ResetSigType rstsig_saci2 = {
    .rstCtl = &Mcu_RstgenAp,
    .id      = RSTSIG_AP_SACI2,
};

const Mcu_ResetSigType rstsig_dma_ap = {
    .rstCtl = &Mcu_RstgenAp,
    .id      = RSTSIG_AP_DMA_AP,
};

const Mcu_ResetSigType rstsig_sehc1 = {
    .rstCtl = &Mcu_RstgenAp,
    .id      = RSTSIG_AP_SEHC1,
};

const Mcu_ResetSigType rstsig_sehc2 = {
    .rstCtl = &Mcu_RstgenAp,
    .id      = RSTSIG_AP_SEHC2,
};

const Mcu_ResetSigType rstsig_usb = {
    .rstCtl = &Mcu_RstgenAp,
    .id      = RSTSIG_AP_USB,
};

const Mcu_ResetSigType rstsig_seip = {
    .rstCtl = &Mcu_RstgenAp,
    .id      = RSTSIG_AP_SEIP,
};

const Mcu_ResetSigType rstsig_lvds_ss = {
    .rstCtl = &Mcu_RstgenAp,
    .id      = RSTSIG_AP_LVDS_SS,
};

const Mcu_ResetSigType rstsig_ap_mission1 = {
    .rstCtl = &Mcu_RstgenAp,
    .id      = RSTSIG_AP_MISSION1,
};

const Mcu_ResetSigType rstsig_saf_debug = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = RSTSIG_SAF_DEBUG,
};

const Mcu_ResetSigType rstsig_ap_debug = {
    .rstCtl = &Mcu_RstgenAp,
    .id      = RSTSIG_AP_DEBUG,
};


const Mcu_ResetGeneralRegType reset_general_reg_sf_boot = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = 7U,
};

const Mcu_ResetGeneralRegType reset_general_reg_rom_ctrl = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = 0U,
};

const Mcu_ResetGeneralRegType reset_general_reg_sf_remap = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = 1U,
};

const Mcu_ResetGeneralRegType reset_general_reg_sf_test = {
    .rstCtl = &Mcu_RstgenSaf,
    .id      = 2U,
};

const Mcu_ResetSigType * const Mcu_XspiResetArray[] = {
    &rstsig_xspi1a,
    &rstsig_xspi1b,
    &rstsig_xspi2a,
    &rstsig_xspi2b,
};

const Mcu_ResetSigType * const Mcu_DeassertArray[] = {
    &rstsig_uart,
    &rstsig_saf_mission2,
    &rstsig_saf_mission8,
    &rstsig_saf_mission9,
    &rstsig_canfd3_4,
    &rstsig_canfd5_8,
    &rstsig_dma_rst0,
    &rstsig_dma_rst1,
    &rstsig_vic1,
    &rstsig_vic2_porta,
    &rstsig_vic2_portb,
    &rstsig_vic3_porta,
    &rstsig_vic3_portb,
#ifndef CFG_XIP
    &rstsig_xspi1a,
    &rstsig_xspi1b,
    &rstsig_xspi2a,
    &rstsig_xspi2b,
#endif /** #ifndef CFG_XIP*/
    &rstsig_mb,
    &rstsig_xtrg,
    &rstsig_usb,
    &rstsig_seip,
};

const Mcu_ResetSigType * const Mcu_AssertArray[] = {
    &rstsig_cr5_sp0,
    &rstsig_cr5_sp1,
    &rstsig_canfd1,
    &rstsig_canfd2,
#ifndef CFG_XIP
#endif /** #ifndef CFG_XIP*/
    &rstsig_saci1,
    &rstsig_saci2,
    &rstsig_csi,
    &rstsig_g2d,
    &rstsig_lvds_ss,
    &rstsig_sdramc,
    &rstsig_ahb_syncup_gama1,
    &rstsig_gama1,
    &rstsig_gama2,
    &rstsig_ahb_syncup_gama2,
    &rstsig_saf_mission6,
    &rstsig_dc,
    &rstsig_dma_ap,
    &rstsig_xspi_slv,
};

#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

uint32 Mcu_GetDeassertArraySize(void)
{
    return sizeof(Mcu_DeassertArray) / sizeof(Mcu_DeassertArray[0]);
}

uint32 Mcu_GetAssertArraySize(void)
{
    return sizeof(Mcu_AssertArray) / sizeof(Mcu_AssertArray[0]);
}

uint32 Mcu_GetXspiResetArraySize(void)
{
    return sizeof(Mcu_XspiResetArray) / sizeof(Mcu_XspiResetArray[0]);
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif
/* End of file */
