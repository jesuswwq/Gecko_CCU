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

#ifdef __cplusplus
extern "C" {
#endif

#include "Mcu_Modules.h"
#include "RegBase.h"

/* Version and Check Begin */
/* Version Info Begin */
#define MCU_MODULES_C_VENDOR_ID    0x8C
#define MCU_MODULES_C_AR_RELEASE_MAJOR_VERSION    4
#define MCU_MODULES_C_AR_RELEASE_MINOR_VERSION    3
#define MCU_MODULES_C_AR_RELEASE_REVISION_VERSION 1
#define MCU_MODULES_C_SW_MAJOR_VERSION    1
#define MCU_MODULES_C_SW_MINOR_VERSION    0
#define MCU_MODULES_C_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((MCU_MODULES_C_AR_RELEASE_MAJOR_VERSION != MCU_MODULES_H_AR_RELEASE_MAJOR_VERSION)\
    || (MCU_MODULES_C_AR_RELEASE_MINOR_VERSION != MCU_MODULES_H_AR_RELEASE_MINOR_VERSION)\
    || (MCU_MODULES_C_AR_RELEASE_REVISION_VERSION != MCU_MODULES_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Mcu_Modules.c and Mcu_Modules.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((MCU_MODULES_C_SW_MAJOR_VERSION != MCU_MODULES_H_SW_MAJOR_VERSION)\
    || (MCU_MODULES_C_SW_MINOR_VERSION != MCU_MODULES_H_SW_MINOR_VERSION)\
    || (MCU_MODULES_C_SW_PATCH_VERSION != MCU_MODULES_H_SW_PATCH_VERSION))
#error "Opps, Mcu_Modules.c and Mcu_Modules.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((MCU_MODULES_C_AR_RELEASE_MAJOR_VERSION != REGBASE_H_AR_RELEASE_MAJOR_VERSION)\
    || (MCU_MODULES_C_AR_RELEASE_MINOR_VERSION != REGBASE_H_AR_RELEASE_MINOR_VERSION)\
    || (MCU_MODULES_C_AR_RELEASE_REVISION_VERSION != REGBASE_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Mcu_Modules.c and RegBase.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((MCU_MODULES_C_SW_MAJOR_VERSION != REGBASE_H_SW_MAJOR_VERSION)\
    || (MCU_MODULES_C_SW_MINOR_VERSION != REGBASE_H_SW_MINOR_VERSION)\
    || (MCU_MODULES_C_SW_PATCH_VERSION != REGBASE_H_SW_PATCH_VERSION))
#error "Opps, Mcu_Modules.c and RegBase.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

CONST(uint32, MCU_CONST) bases[] = {
    [UART1] = APB_UART1_BASE,
    [UART2] = APB_UART2_BASE,
    [UART3] = APB_UART3_BASE,
    [UART4] = APB_UART4_BASE,
    [UART5] = APB_UART5_BASE,
    [UART6] = APB_UART6_BASE,
    [UART7] = APB_UART7_BASE,
    [UART8] = APB_UART8_BASE,
    [UART9] = APB_UART9_BASE,
    [UART10] = APB_UART10_BASE,
    [UART11] = APB_UART11_BASE,
    [UART12] = APB_UART12_BASE,
    [UART13] = APB_UART13_BASE,
    [UART14] = APB_UART14_BASE,
    [UART15] = APB_UART15_BASE,
    [UART16] = APB_UART16_BASE,

    [MAILBOX] = MB_REG_BASE,
    [CAN1] = APB_CANFD1_BASE,
    [CAN2] = APB_CANFD2_BASE,
    [CAN3] = APB_CANFD3_BASE,
    [CAN4] = APB_CANFD4_BASE,
    [CAN5] = APB_CANFD5_BASE,
    [CAN6] = APB_CANFD6_BASE,
    [CAN7] = APB_CANFD7_BASE,
    [CAN8] = APB_CANFD8_BASE,
    [CAN9] = APB_CANFD9_BASE,
    [CAN10] = APB_CANFD10_BASE,
    [CAN11] = APB_CANFD11_BASE,
    [CAN12] = APB_CANFD12_BASE,
    [CAN13] = APB_CANFD13_BASE,
    [CAN14] = APB_CANFD14_BASE,
    [CAN15] = APB_CANFD15_BASE,
    [CAN16] = APB_CANFD16_BASE,
    [CAN17] = APB_CANFD17_BASE,
    [CAN18] = APB_CANFD18_BASE,
    [CAN19] = APB_CANFD19_BASE,
    [CAN20] = APB_CANFD20_BASE,
    [CAN21] = APB_CANFD21_BASE,
    [CAN22] = APB_CANFD22_BASE,
    [CAN23] = APB_CANFD23_BASE,
    [CAN24] = APB_CANFD24_BASE,

    [BTM1] = APB_BTM1_BASE,
    [BTM2] = APB_BTM2_BASE,
    [BTM3] = APB_BTM3_BASE,
    [BTM4] = APB_BTM4_BASE,
    [BTM5] = APB_BTM5_BASE,
    [BTM6] = APB_BTM6_BASE,
    [ETIMER1] = APB_ETMR1_BASE,
    [ETIMER2] = APB_ETMR2_BASE,
    [ETIMER3] = APB_ETMR3_BASE,
    [ETIMER4] = APB_ETMR4_BASE,
    [SPI1] = APB_SPI1_BASE,
    [SPI2] = APB_SPI2_BASE,
    [SPI3] = APB_SPI3_BASE,
    [SPI4] = APB_SPI4_BASE,
    [SPI5] = APB_SPI5_BASE,
    [SPI6] = APB_SPI6_BASE,
    [SPI7] = APB_SPI7_BASE,
    [SPI8] = APB_SPI8_BASE,
    [ETH1] = APB_ETH1_BASE,
    [ETH2] = APB_ETH2_BASE,
    [ADC1] = APB_ADC1_BASE,
    [ADC2] = APB_ADC2_BASE,
    [ADC3] = APB_ADC3_BASE,
    [EPWM1] = APB_EPWM1_BASE,
    [EPWM2] = APB_EPWM2_BASE,
    [EPWM3] = APB_EPWM3_BASE,
    [EPWM4] = APB_EPWM4_BASE,
    [WDT1] = APB_WDT1_BASE,
    [WDT2] = APB_WDT2_BASE,
    [WDT3] = APB_WDT3_BASE,
    [WDT4] = APB_WDT4_BASE,
    [WDT5] = APB_WDT5_BASE,
    [WDT6] = APB_WDT6_BASE,
    [WDT8] = APB_WDT8_BASE,
};

#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

uint32 Mcu_GetModuleBase(Mcu_ModuleType m)
{
    return m <= sizeof(bases) / sizeof(bases[0]) ? bases[m] : 0;
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif
