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
 * @file  Lin_PbCfg.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Lin
 * @date 2024-03-08 16:29:00
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Lin_Types_E3.h"
#include "Lin_Hw.h"
#include "ioc_index.h"

#define LIN_START_SEC_CONST_UNSPECIFIED
#include "Lin_MemMap.h"

    

/* UART configuration for different nodes */
static const Lin_Uart Lin_ChannelHwCfg[3] =
{
    {
        {
            .auto_br = TRUE,
            .icu_abr = FALSE,
            .icu_abr_chn = 0,
            .baud_rate = (19200U),
            .frequency = (83250000),
            .mode = LIN_UART_MASTER,
            .cs_mode = LIN_UART_ENHANCED_CS,
            .stop = LIN_UART_STOP_1BIT,
            .parity = LIN_UART_PARITY_NONE,
        },
        
        /* gpio info only be used when LIN_TX_ERROR_DETECT is on */
        {
            .gpio_tx = IOC_GPIO_S0_UART11_TXD,
            .gpio_rx = IOC_GPIO_S1_UART11_RXD,
        },
        
        (Mcu_ModuleType)(UART11)
    },
    {
        {
            .auto_br = TRUE,
            .icu_abr = FALSE,
            .icu_abr_chn = 0,
            .baud_rate = (19200U),
            .frequency = (83250000),
            .mode = LIN_UART_MASTER,
            .cs_mode = LIN_UART_ENHANCED_CS,
            .stop = LIN_UART_STOP_1BIT,
            .parity = LIN_UART_PARITY_NONE,
        },
        
        /* gpio info only be used when LIN_TX_ERROR_DETECT is on */
        {
            .gpio_tx = IOC_GPIO_M4_UART14_TXD,
            .gpio_rx = IOC_GPIO_M5_UART14_RXD,
        },
        
        (Mcu_ModuleType)(UART14)
    },
    {
        {
            .auto_br = TRUE,
            .icu_abr = FALSE,
            .icu_abr_chn = 0,
            .baud_rate = (19200U),
            .frequency = (83250000),
            .mode = LIN_UART_MASTER,
            .cs_mode = LIN_UART_ENHANCED_CS,
            .stop = LIN_UART_STOP_1BIT,
            .parity = LIN_UART_PARITY_NONE,
        },
        
        /* gpio info only be used when LIN_TX_ERROR_DETECT is on */
        {
            .gpio_tx = IOC_GPIO_B10_UART3_TXD,
            .gpio_rx = IOC_GPIO_B11_UART3_RXD,
        },
        
        (Mcu_ModuleType)(UART3)
    },
};

CONST(Lin_ConfigType, LIN_CONST) LinGlobalConfig =
{
    .numberOfNodes = 3U,
    .channels = Lin_ChannelHwCfg
};

#define LIN_STOP_SEC_CONST_UNSPECIFIED
#include "Lin_MemMap.h"

#ifdef __cplusplus
}
#endif
