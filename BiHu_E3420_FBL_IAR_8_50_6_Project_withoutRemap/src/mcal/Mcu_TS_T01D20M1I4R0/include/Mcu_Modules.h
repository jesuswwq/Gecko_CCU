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

#ifndef MCU_MODULES_H
#define MCU_MODULES_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
/* Version and Check Begin */
/* Version Info Begin */
#define MCU_MODULES_H_VENDOR_ID    0x8C
#define MCU_MODULES_H_AR_RELEASE_MAJOR_VERSION    4
#define MCU_MODULES_H_AR_RELEASE_MINOR_VERSION    3
#define MCU_MODULES_H_AR_RELEASE_REVISION_VERSION 1
#define MCU_MODULES_H_SW_MAJOR_VERSION    1
#define MCU_MODULES_H_SW_MINOR_VERSION    0
#define MCU_MODULES_H_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((MCU_MODULES_H_AR_RELEASE_MAJOR_VERSION != STD_TYPES_H_AR_RELEASE_MAJOR_VERSION)\
    || (MCU_MODULES_H_AR_RELEASE_MINOR_VERSION != STD_TYPES_H_AR_RELEASE_MINOR_VERSION)\
    || (MCU_MODULES_H_AR_RELEASE_REVISION_VERSION != STD_TYPES_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Mcu_Modules.h and Std_Types.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((MCU_MODULES_H_SW_MAJOR_VERSION != STD_TYPES_H_SW_MAJOR_VERSION)\
    || (MCU_MODULES_H_SW_MINOR_VERSION != STD_TYPES_H_SW_MINOR_VERSION)\
    || (MCU_MODULES_H_SW_PATCH_VERSION != STD_TYPES_H_SW_PATCH_VERSION))
#error "Opps, Mcu_Modules.h and Std_Types.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

typedef enum {
    FREQ_LOW = 0,
    FREQ_MID = 1,
    FREQ_HIGH = 2,
    FREQ_ULTRA_HIGH = 3,
    OSPI_FREQ_SAFE = 4,
    OSPI_FREQ0 = 5,
    OSPI_FREQ1 = 6,
    OSPI_FREQ2 = 7,
    OSPI_FREQ3 = 8,
    OSPI_FREQ0_DIV = 9,
    OSPI_FREQ1_DIV = 10,

} Mcu_ModuleFreqType;

typedef enum {
    UART1 = 0x1u,
    UART2,
    UART3,
    UART4,
    UART5,
    UART6,
    UART7,
    UART8,
    UART9,
    UART10,
    UART11,
    UART12,
    UART13,
    UART14,
    UART15,
    UART16,
    MAILBOX,
    BTM1,
    BTM2,
    BTM3,
    BTM4,
    BTM5,
    BTM6,

    WDT1,
    WDT2,
    WDT3,
    WDT4,
    WDT5,
    WDT6,
    WDT8,

    CAN1,
    CAN2,
    CAN3,
    CAN4,
    CAN5,
    CAN6,
    CAN7,
    CAN8,
    CAN9,
    CAN10,
    CAN11,
    CAN12,
    CAN13,
    CAN14,
    CAN15,
    CAN16,
    CAN17,
    CAN18,
    CAN19,
    CAN20,
    CAN21,
    CAN22,
    CAN23,
    CAN24,

    SPI1,
    SPI2,
    SPI3,
    SPI4,
    SPI5,
    SPI6,
    SPI7,
    SPI8,

    I2C1,
    I2C2,
    I2C3,
    I2C4,
    I2C5,
    I2C6,
    I2C7,
    I2C8,
    I2C9,
    I2C10,
    I2C11,
    I2C12,
    I2C13,
    I2C14,
    I2C15,
    I2C16,

    DMA1,
    DMA2,
    DMA3,
    DMA4,
    DMA5,
    DMA6,
    DMA7,
    DMA8,

    CE1,
    CE2,

    GPIO1,
    GPIO2,
    GPIO3,
    GPIO4,
    GPIO5,

    ETH1,
    ETH2,

    GIC1,
    GIC2,

    IRAMC1,
    IRAMC2,
    IRAMC3,
    IRAMC4,

    SEM1,
    SEM2,

    EIC_SAFE,
    EIC_SEC,
    EIC_HPI,
    EIC_VSN,

    GAMA1,
    HPI,
    VIC1,
    VIC2_A,
    VIC2_B,
    VIC3_A,
    VIC3_B,
    EPWM1,
    EPWM2,
    EPWM3,
    EPWM4,
    ETIMER1,
    ETIMER2,
    ETIMER3,
    ETIMER4,
    XTRG,
    ADC1,
    ADC2,
    ADC3,

    XSPI1,
    XSPI2,
    XSPI1A,
    XSPI1B,

    MODULE_END,
} Mcu_ModuleType;

uint32 Mcu_GetModuleBase(Mcu_ModuleType m);

#ifdef __cplusplus
}
#endif

#endif  /* ifndef MCU_MODULES_H */
