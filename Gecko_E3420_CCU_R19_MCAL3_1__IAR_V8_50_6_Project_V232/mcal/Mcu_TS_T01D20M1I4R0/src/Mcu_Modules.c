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
 * \file     Mcu_Modules.c                                                                              *
 * \brief    AUTOSAR 4.3.1 MCAL MCu Driver                                                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/02     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "RegBase.h"
#include "Mcu_Modules.h"

/********************************************************************************************************
 *                                 Private Macro definition                                             *
 *******************************************************************************************************/

/********************************************************************************************************
 *                                  Private Variable Definitions                                        *
 *******************************************************************************************************/
#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"
/* PRQA S 3218 1*/
static const uint32 Mcu_ModuleBases[] =
{
    /* PRQA S 3676 1*/
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
#ifndef SEMIDRIVE_E3_LITE_SERIES
    [UART13] = APB_UART13_BASE,
    [UART14] = APB_UART14_BASE,
    [UART15] = APB_UART15_BASE,
    [UART16] = APB_UART16_BASE,
    [MAILBOX] = MB_REG_BASE,
    [CAN1] = APB_CANFD1_BASE,
    [CAN2] = APB_CANFD2_BASE,
    [CAN8] = APB_CANFD8_BASE,
#else
    [CAN1] = APB_CANFD16_BASE,
    [CAN2] = APB_CANFD21_BASE,
    [CAN8] = APB_CANFD23_BASE,
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/
    [CAN3] = APB_CANFD3_BASE,
    [CAN4] = APB_CANFD4_BASE,
    [CAN5] = APB_CANFD5_BASE,
    [CAN6] = APB_CANFD6_BASE,
    [CAN7] = APB_CANFD7_BASE,
#ifndef SEMIDRIVE_E3_LITE_SERIES
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
#endif
    [BTM1] = APB_BTM1_BASE,
    [BTM2] = APB_BTM2_BASE,
    [BTM3] = APB_BTM3_BASE,
    [BTM4] = APB_BTM4_BASE,
#ifndef SEMIDRIVE_E3_LITE_SERIES
    [BTM5] = APB_BTM5_BASE,
    [BTM6] = APB_BTM6_BASE,
#endif
    [ETIMER1] = APB_ETMR1_BASE,
    [ETIMER2] = APB_ETMR2_BASE,
#ifndef SEMIDRIVE_E3_LITE_SERIES
    [ETIMER3] = APB_ETMR3_BASE,
    [ETIMER4] = APB_ETMR4_BASE,
#endif
    [SPI1] = APB_SPI1_BASE,
    [SPI2] = APB_SPI2_BASE,
    [SPI3] = APB_SPI3_BASE,
    [SPI4] = APB_SPI4_BASE,
    [SPI5] = APB_SPI5_BASE,
    [SPI6] = APB_SPI6_BASE,
#ifndef SEMIDRIVE_E3_LITE_SERIES
    [SPI7] = APB_SPI7_BASE,
    [SPI8] = APB_SPI8_BASE,
#endif
    [ETH1] = APB_ETH1_BASE,
#ifndef SEMIDRIVE_E3_LITE_SERIES
    [ETH2] = APB_ETH2_BASE,
#endif
    [ADC1] = APB_ADC1_BASE,
    [ADC2] = APB_ADC2_BASE,
    [ADC3] = APB_ADC3_BASE,
    [EPWM1] = APB_EPWM1_BASE,
    [EPWM2] = APB_EPWM2_BASE,
#ifndef SEMIDRIVE_E3_LITE_SERIES
    [EPWM3] = APB_EPWM3_BASE,
    [EPWM4] = APB_EPWM4_BASE,
#endif
    [WDT1] = APB_WDT1_BASE,
    [WDT2] = APB_WDT2_BASE,
#ifndef SEMIDRIVE_E3_LITE_SERIES
    [WDT3] = APB_WDT3_BASE,
    [WDT4] = APB_WDT4_BASE,
    [WDT5] = APB_WDT5_BASE,
    [WDT6] = APB_WDT6_BASE,
#endif
    [WDT8] = APB_WDT8_BASE,
};

#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

uint32 Mcu_GetModuleBase(Mcu_ModuleType m)
{
    return ((uint32)m <= (sizeof(Mcu_ModuleBases) / sizeof(Mcu_ModuleBases[0]))) ? Mcu_ModuleBases[m] :
           0xFFFFFFFFU;
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif
/* End of file */
