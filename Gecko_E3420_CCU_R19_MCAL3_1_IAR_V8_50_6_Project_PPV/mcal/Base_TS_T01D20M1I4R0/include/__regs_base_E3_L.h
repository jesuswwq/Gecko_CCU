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
 *  \file     __regs_base_E3_L.h                                                                        *
 *  \brief    This file contains interface header for MCAL driver                                       *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/09/09     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef __REGS_BASE_E3_L_H
#define __REGS_BASE_E3_L_H


/*-------------------------------------------------------*/
/* autoreg base address list                             */
/*-------------------------------------------------------*/

#define VIC1_BASE                                                    (0xf1c00000u)
#define APB_GPV_AP_BASE                                              (0xf0c60000u)
#define APB_SEIP_BASE                                                (0xf0c50000u)
#define APB_GPIO_SF_BASE                                             (0xf0c40000u)
#define APB_USB_BASE                                                 (0xf0c30000u)
#define APB_SACI1_BASE                                               (0xf0c20000u)
#define APB_SEHC1_BASE                                               (0xf0c10000u)
#define APB_APB_MUX4_BASE                                            (0xf0c00000u)
#define APB_IRAMC1_BASE                                              (0xf0be0000u)
#define APB_SEM2_BASE                                                (0xf0ba0000u)
#define APB_SEM1_BASE                                                (0xf0b90000u)
#define APB_ADC3_BASE                                                (0xf0b80000u)
#define APB_ADC2_BASE                                                (0xf0b70000u)
#define APB_ADC1_BASE                                                (0xf0b60000u)
#define APB_GPV_XB_BASE                                              (0xf0b50000u)
#define APB_GPV_SF_BASE                                              (0xf0b40000u)
#define APB_MAC_BASE                                                 (0xf0b30000u)
#define APB_WDT8_BASE                                                (0xf0b10000u)
#define APB_WDT2_BASE                                                (0xf0ae0000u)
#define APB_WDT1_BASE                                                (0xf0ad0000u)
#define APB_ACMP4_BASE                                               (0xf0ac0000u)
#define APB_ACMP3_BASE                                               (0xf0ab0000u)
#define APB_ACMP2_BASE                                               (0xf0aa0000u)
#define APB_ACMP1_BASE                                               (0xf0a90000u)
#define APB_I2C6_BASE                                                (0xf0a80000u)
#define APB_I2C5_BASE                                                (0xf0a70000u)
#define APB_I2C4_BASE                                                (0xf0a60000u)
#define APB_I2C3_BASE                                                (0xf0a50000u)
#define APB_I2C2_BASE                                                (0xf0a40000u)
#define APB_I2C1_BASE                                                (0xf0a30000u)
#define APB_CSSYS_BASE                                               (0xf0a00000u)
#define APB_DMA_SF1_BASE                                             (0xf09b0000u)
#define APB_DMA_SF0_BASE                                             (0xf0970000u)
#define APB_XSPI_SLV_BASE                                            (0xf0950000u)
#define APB_ETH1_BASE                                               (0xf0930000u)
#define APB_PT_SNS_SF_BASE                                           (0xf0920000u)
#define APB_VD_SF_BASE                                               (0xf0910000u)
#define APB_PLL3_BASE                                                (0xf0900000u)
#define APB_PLL2_BASE                                                (0xf08f0000u)
#define APB_PLL1_BASE                                                (0xf08e0000u)
#define APB_CKGEN_SF_BASE                                            (0xf08d0000u)
#define APB_RSTGEN_SF_BASE                                           (0xf08c0000u)
#define APB_SCR_SF_BASE                                              (0xf08b0000u)
#define APB_IROMC_BASE                                               (0xf08a0000u)
#define APB_FS_24M_BASE                                              (0xf0890000u)
#define APB_POR_SF_BASE                                              (0xf0880000u)
#define APB_SMC_BASE                                                 (0xf0870000u)
#define APB_IOMUXC_SF_BASE                                           (0xf0860000u)
#define APB_ISTC_BASE                                                (0xf0850000u)
#define APB_EIC_SF_BASE                                              (0xf0840000u)
#define APB_DCDC1_BASE                                               (0xf0830000u)
#define APB_EFUSEC_BASE                                              (0xf0820000u)
#define APB_APB_MUX3_BASE                                            (0xf0800000u)
#define APB_XSPI1PORTB_BASE                                          (0xf0780000u)
#define APB_XSPI1PORTA_BASE                                          (0xf0770000u)
#define APB_IOC_BASE                                                 (0xf0750000u)
#define APB_UART12_BASE                                              (0xf06b0000u)
#define APB_UART11_BASE                                              (0xf06a0000u)
#define APB_UART10_BASE                                              (0xf0690000u)
#define APB_UART9_BASE                                               (0xf0680000u)
#define APB_UART8_BASE                                               (0xf0670000u)
#define APB_UART7_BASE                                               (0xf0660000u)
#define APB_UART6_BASE                                               (0xf0650000u)
#define APB_UART5_BASE                                               (0xf0640000u)
#define APB_UART4_BASE                                               (0xf0630000u)
#define APB_UART3_BASE                                               (0xf0620000u)
#define APB_UART2_BASE                                               (0xf0610000u)
#define APB_UART1_BASE                                               (0xf0600000u)
#define APB_SPI6_BASE                                                (0xf05d0000u)
#define APB_SPI5_BASE                                                (0xf05c0000u)
#define APB_SPI4_BASE                                                (0xf05b0000u)
#define APB_SPI3_BASE                                                (0xf05a0000u)
#define APB_SPI2_BASE                                                (0xf0590000u)
#define APB_SPI1_BASE                                                (0xf0580000u)
#define APB_CANFD23_BASE                                              (0xf0570000u)
#define APB_CANFD7_BASE                                              (0xf0560000u)
#define APB_CANFD6_BASE                                              (0xf0550000u)
#define APB_CANFD5_BASE                                              (0xf0540000u)
#define APB_CANFD4_BASE                                              (0xf0530000u)
#define APB_CANFD3_BASE                                              (0xf0520000u)
#define APB_CANFD21_BASE                                              (0xf0510000u)
#define APB_CANFD16_BASE                                              (0xf0500000u)
#define APB_ETMR2_BASE                                               (0xf04d0000u)
#define APB_ETMR1_BASE                                               (0xf04c0000u)
#define APB_EPWM2_BASE                                               (0xf0490000u)
#define APB_EPWM1_BASE                                               (0xf0480000u)
#define APB_BTM4_BASE                                                (0xf0450000u)
#define APB_BTM3_BASE                                                (0xf0440000u)
#define APB_BTM2_BASE                                                (0xf0430000u)
#define APB_BTM1_BASE                                                (0xf0420000u)
#define APB_XTRG_BASE                                                (0xf0410000u)
#define APB_APB_MUX2_BASE                                            (0xf0400000u)
#define APB_SEC_STORAGE_BASE                                         (0xf00a0000u)
#define APB_TM_BASE                                                  (0xf0080000u)
#define APB_IOMUXC_RTC_BASE                                          (0xf0070000u)
#define APB_PMU_CORE_BASE                                            (0xf0060000u)
#define APB_TB_CTRL_BASE                                             (0xf0040000u)
#define APB_FS_32K_BASE                                              (0xf0030000u)
#define APB_RTC2_BASE                                                (0xf0020000u)
#define APB_RTC1_BASE                                                (0xf0010000u)
#define PERIPHERALSF_BASE                                            (0xf0000000u)
#define APB_APB_MUX1_BASE                                            (0xf0000000u)
#define XSPI1_XSPI1PORTB_BASE                                        (0x18000000u)
#define XSPI1_BASE                                                   (0x10000000u)
#define XSPI1_XSPI1PORTA_BASE                                        (0x10000000u)
#define SEIP_SEIPSECUREDKEYBUFFER_BASE                               (0x02200000u)
#define APB_KBUF_BASE                                                (0xf21de000u)
#define APB_APBSYSTEMREG_BASE                                        (0xf21dd800u)
#define APB_SEIP_UART0_BASE                                          (0xf21dd000u)
#define APB_SEIP_MAILBOX_BASE                                        (0xf21d8000u)
#define APB_AHBSYSTEMREG_BASE                                        (0xf21d0000u)
#define APB_SEIP_HFE_BASE                                            (0xf21cc000u)
#define APB_SEIP_SKE_BASE                                            (0xf21c8000u)
#define APB_SEIP_TRNG_BASE                                           (0xf21c4000u)
#define APB_SEIP_PKE_BASE                                            (0xf21c0000u)
#define APB_SEIP_SRAM1_BASE                                          (0xf21a0000u)
#define APB_SEIP_SRAM0_BASE                                          (0xf2180000u)
#define APB_SEIP_CPU_FIO_BASE                                        (0xf2160000u)
#define APB_SEIP_CPU_PLIC_BASE                                       (0xf2150000u)
#define APB_SEIP_CPU_CLINT_BASE                                      (0xf2140000u)
#define APB_SEIP_DTCM_BASE                                           (0xf2120000u)
#define APB_SEIP_ITCM_BASE                                           (0xf2100000u)
#define SEIP_BASE                                                    (0x02100000u)
#define SEIP_SEIP_BASE                                               (0x02100000u)
#define R5_SF_CACHE_R5_SF_DCACHE_BASE                                (0x01978000u)
#define R5_SF_CACHE_BASE                                             (0x01970000u)
#define R5_SF_CACHE_R5_SF_ICACHE_BASE                                (0x01970000u)
#define R5_SF_TCM_R5_SF_TCMA_BASE                                    (0x01940000u)
#define R5_SF_TCM_BASE                                               (0x01930000u)
#define R5_SF_TCM_R5_SF_TCMB_BASE                                    (0x01930000u)
#define IRAM1ALIASED_IRAM1_BASE                                      (0x00c00000u)
#define IRAM1ALIASED_BASE                                            (0x00c00000u)
#define IRAM1_ECCALIASED_IRAM1WHENNOECC_BASE                         (0x00be0000u)
#define IRAM1_ECCALIASED_BASE                                        (0x00be0000u)
#define IRAM1_IRAM1_BASE                                             (0x00500000u)
#define IRAM1_BASE                                                   (0x00500000u)
#define IRAM1_ECC_IRAM1WHENNOECC_BASE                                (0x004e0000u)
#define IRAM1_ECC_BASE                                               (0x004e0000u)
#define ROMC1_BOOTROM1_BASE                                          (0x00000000u)
#define ROMC1_BASE                                                   (0x00000000u)

#endif /* __REGS_BASE_E3_L_H */
/* End of file */
