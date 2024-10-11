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
 * @file  sdrv_btm_common.h
 * @brief Semidrive. Btm
 */

#ifndef SDRV_COMMON_H_
#define SDRV_COMMON_H_

#include <types.h>
#include "Platform_Types.h"

/**
 * @brief Construct a status code value from a group and code number.
 * All the error statuses are negetive numbers.
 */
#define SDRV_ERROR_STATUS(group, code) (-((group) * (1000U) + (code)))

/*! @brief Status group numbers. */
enum status_groups
{
    SDRV_STATUS_GROUP_COMMON = 0,             /* Group number for common status code */
    SDRV_STATUS_GROUP_RESET = 1,              /* Group number for RESET status codes */
    SDRV_STATUS_GROUP_CLK = 2,                /* Group number for CLK status code */
    SDRV_STATUS_GROUP_VIC = 3,                /* Group number for VIC status code */
    SDRV_STATUS_GROUP_PINCTRL = 4,            /* Group number for PINCTRL status codes */
    SDRV_STATUS_GROUP_GPIO = 5,               /* Group number for GPIO status code */
    SDRV_STATUS_GROUP_DMA = 6,                /* Group number for DMA status code */
    SDRV_STATUS_GROUP_BTM = 7,                /* Group number for BTM status code */
    SDRV_STATUS_GROUP_FUSE = 8,               /* Group number for FUSE status code.*/
    SDRV_STATUS_GROUP_WATCHDOG = 9,           /* Group number for WATCHDOG status code */
    SDRV_STATUS_GROUP_CRYPTO = 10,             /* Group number for CRYPTO status code */
    SDRV_STATUS_GROUP_UART = 11,               /* Group number for UART status code */
    SDRV_STATUS_GROUP_FLEXCAN = 12,            /* Group number for FLEXCAN status code.*/
    SDRV_STATUS_GROUP_LIN = 13,                /* Group number for LIN status code */
    SDRV_STATUS_GROUP_I2C = 14,                /* Group number for I2C status code */
    SDRV_STATUS_GROUP_SPI = 15,                /* Group number for SPI status code */
    SDRV_STATUS_GROUP_ETH = 16,                /* Group number for ETH status code */
    SDRV_STATUS_GROUP_I2S = 17,                /* Group number for I2S status code */
    SDRV_STATUS_GROUP_PDM = 18,                /* Group number for PDM status codes */
    SDRV_STATUS_GROUP_EPWM = 19,               /* Group number for EPWM status codes */
    SDRV_STATUS_GROUP_ETIMER = 20,             /* Group number for ETIMER status code.*/
    SDRV_STATUS_GROUP_XTRG = 21,               /* Group number for XTRG status code */
    SDRV_STATUS_GROUP_ADC = 22,                /* Group number for ADC status code */
    SDRV_STATUS_GROUP_ACMP = 23,               /* Group number for ACMP status code */
    SDRV_STATUS_GROUP_ASW = 24,                /* Group number for ASW status code */
    SDRV_STATUS_GROUP_DISPSS = 25,             /* Group number for DISPSS status code */
    SDRV_STATUS_GROUP_CAMERA = 26,             /* Group number for CAMERA status code */
    SDRV_STATUS_GROUP_G2DLITE = 27,            /* Group number for G2DLITE status code */
    SDRV_STATUS_GROUP_PMU = 28,                /* Group number for FLEXCOMM status codes */
    SDRV_STATUS_GROUP_POWER = 29,              /* Group number for POWER status codes */
    SDRV_STATUS_GROUP_SMC = 30,                /* Group number for SMC status code */
    SDRV_STATUS_GROUP_RTC = 31,                /* Group number for RTC status codes */
    SDRV_STATUS_GROUP_SCR = 32,                /* Group number for SCR status code */
    SDRV_STATUS_GROUP_PVT = 33,                /* Group number for PVT status codes */
    SDRV_STATUS_GROUP_SDRAMC = 34,             /* Group number for SDRAMC status code */
    SDRV_STATUS_GROUP_MBOX = 35,               /* Group number for MBOX status code */
    SDRV_STATUS_GROUP_SEMAG = 36,              /* Group number for SEMAG status code */
    SDRV_STATUS_GROUP_XSPI = 37,               /* Group number for XSPI status code */
    SDRV_STATUS_GROUP_MMC = 38,                /* Group number for MMC status codes */
    SDRV_STATUS_GROUP_XSPI_MST_SLV = 39,       /* Group number for XSPI_MST_SLV status code */
    SDRV_STATUS_GROUP_OTHER = 40,              /* Group number for other module status code */
};

/**
 * @brief Common status return code
 */
enum
{
    SDRV_STATUS_OK = SDRV_ERROR_STATUS(SDRV_STATUS_GROUP_COMMON, 0),             /* Common status for OK. */
    SDRV_STATUS_FAIL = SDRV_ERROR_STATUS(SDRV_STATUS_GROUP_COMMON, 1),           /* Common status for fail. */
    SDRV_STATUS_BUSY = SDRV_ERROR_STATUS(SDRV_STATUS_GROUP_COMMON, 2),           /* Common status for busy. */
    SDRV_STATUS_TIMEOUT = SDRV_ERROR_STATUS(SDRV_STATUS_GROUP_COMMON, 3),        /* Common status for timeout. */
    SDRV_STATUS_INVALID_PARAM = SDRV_ERROR_STATUS(SDRV_STATUS_GROUP_COMMON, 4),  /* Common status for invalid paramemt. */
};

/**
 * @brief Type used for all status and error return values.
 */
typedef sint32 status_t;

#endif /* SDRV_COMMON_H_ */
