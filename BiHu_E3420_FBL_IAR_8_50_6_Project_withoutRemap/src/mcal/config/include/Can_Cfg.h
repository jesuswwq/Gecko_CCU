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
 * @file  Can_Cfg.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Can Driver.
 * @date 2023-09-22 17:02:48
 */

#ifndef CAN_CFG_H_
#define CAN_CFG_H_

#ifdef __cplusplus
extern "C"{
#endif


/* Version and Check Begin */
/* Version Info Begin */
#define CAN_CFG_H_VENDOR_ID    0x8C
#define CAN_CFG_H_AR_RELEASE_MAJOR_VERSION    4
#define CAN_CFG_H_AR_RELEASE_MINOR_VERSION    3
#define CAN_CFG_H_AR_RELEASE_REVISION_VERSION 1
#define CAN_CFG_H_SW_MAJOR_VERSION    1
#define CAN_CFG_H_SW_MINOR_VERSION    0
#define CAN_CFG_H_SW_PATCH_VERSION    0
/* Version Info End */
/* Version and Check End */

/**
 * @brief Specify whether pre-compile is supported.
 */
 #define CAN_PRECOMPILE_SUPPORT     (STD_OFF)

/**
 * @brief specific the AUTOSAR CAN driver version 
 * 
 */
#define AUTOSAR_VERSION_431 1u

/**
 * @brief Switches the development error detection and notification on or off.
 */
#define CAN_DEV_ERROR_DETECT     (STD_OFF)

/**
 * @brief Instance number of the driver, used by Det_ReportError.
 */
#define CAN_INSTANCE (0U)

/**
 * @brief Period for cyclic call to Can_MainFunction_Mode. Unit is millisecond.
 */
#define CAN_MAIN_FUNCTION_MODE_PERIOD (10U)

/**
 * @brief Specifies if multiplexed transmission shall be supported.
 */
#define CAN_MULTIPLEXED_TRANSMISSION     (STD_ON)

/**
 * @brief Specify the maximum time for blocking function until a timeout is detected.
 * Unit is microsecond.
 */
#define CAN_TIMEOUT_DURATION (1000000U)

/**
 * @brief Switches the Can_GetVersionInfo() API ON or OFF.
 */
#define CAN_VERSION_INFO_API     (STD_OFF)

/**
 * @brief The period of cyclic call to Can_MainFunction_Busoff.
 * Unit is milliseconds.
 */

/**
 * @brief The period of cyclic call to Can_MainFunction_Wakeup.
 * Unit is milliseconds.
 */

/**
 * @brief Support of Can_SetBaudrate API.
 */
#define CAN_SET_BAUDRATE_API (STD_OFF)
/**
 * @brief Specify whether multiple read period is supported or not.
 */
#define CAN_MULTIPLE_READ_PERIOD (STD_OFF)

/**
 * @brief Specify whether multiple write period is supported or not.
 */
#define CAN_MULTIPLE_WRITE_PERIOD (STD_OFF)

/**
 * @brief Rx & Tx polling period 0. Unit: millisecond.
 */
#define CAN_MAINFUNCTION_RW_PERIOD_0 (1000U)

/**
 * @brief Specify whether Rx/Tx polling period 1 is supported or not.
 */
#define CAN_MAINFUNCTION_RW_PERIOD_1 (STD_OFF)

/**
 * @brief Specify whether Rx/Tx polling period 2 is supported or not.
 */
#define CAN_MAINFUNCTION_RW_PERIOD_2 (STD_OFF)

/**
 * @brief Specify whether Rx/Tx polling period 3 is supported or not.
 */
#define CAN_MAINFUNCTION_RW_PERIOD_3 (STD_OFF)

/**
 * @brief Specify whether Rx/Tx polling period 4 is supported or not.
 */
#define CAN_MAINFUNCTION_RW_PERIOD_4 (STD_OFF)

/**
 * @brief Specify whether Rx/Tx polling period 5 is supported or not.
 */
#define CAN_MAINFUNCTION_RW_PERIOD_5 (STD_OFF)

/**
 * @brief Specify whether Rx/Tx polling period 6 is supported or not.
 */
#define CAN_MAINFUNCTION_RW_PERIOD_6 (STD_OFF)

/**
 * @brief Specify whether Rx/Tx polling period 7 is supported or not.
 */
#define CAN_MAINFUNCTION_RW_PERIOD_7 (STD_OFF)

/**
 * @brief Specify whether Rx/Tx polling period 8 is supported or not.
 */
#define CAN_MAINFUNCTION_RW_PERIOD_8 (STD_OFF)

/**
 * @brief Specify whether Rx/Tx polling period 9 is supported or not.
 */
#define CAN_MAINFUNCTION_RW_PERIOD_9 (STD_OFF)

/**
 * @brief Support of Can_CheckWakeup API.
 */
#define CAN_CHECK_WAKEUP_API (STD_OFF)

/**
 * @brief Support of trigger-transmit.
 */
#define CAN_TRIGGER_TRANSMIT_EN (STD_OFF)

/**
 * @brief The number of CAN controller configured.
 */
#define CAN_CONTROLLER_COUNT (2U)

/**
 * @brief Specify whether CAN driver should support CAN FD.
 */

#define CAN_FD_SUPPORT  (STD_ON)

/**
 * @brief The definition of HOHs.
 */
#define CAN_HRH_RX_PHY 0U
#define CAN_HTH_RX_FUNC 1U
#define CAN_HRH_TX_RESP 2U
#define CAN_HRH_RX_PHY_OTA 3U
#define CAN_HTH_RX_FUNC_OTA 4U
#define CAN_HRH_TX_RESP_OTA 5U

#define CAN_HOH_MAX 6U

/**
 * @brief The first HTH configuration index.
 */
#define FIRST_HTH_INDEX (4U)

/**
 * @brief The number of all Rx and Tx MBs.
 */
#define CAN_MB_COUNT (6U)

/**
 * @brief The number of all Rx FIFOs.
 */
#define CAN_RX_FIFO_COUNT (0U)

/**
 * @brief Specify whether CAN driver should support CAN FD.
 */
#define CAN_RXFIFO_SUPPORT  (STD_OFF)

#define CBT_PRESDIV(x)  ((x) - 1U)
#define CBT_RJW(x)      ((x) - 1U)
#define CBT_PROPSEG(x)  ((x) - 1U)
#define CBT_PSEG1(x)    ((x) - 1U)
#define CBT_PSEG2(x)    ((x) - 1U)

#define FDCBT_PRESDIV(x)    ((x) - 1U)
#define FDCBT_RJW(x)        ((x) - 1U)
#define FDCBT_PROPSEG(x)    (x)
#define FDCBT_PSEG1(x)      ((x) - 1U)
#define FDCBT_PSEG2(x)      ((x) - 1U)

/**
 * @brief Specify Can Controller index.
 */
#define CanConf_CanController_CANFD7 0U
#define CanConf_CanController_CANFD8 1U




#ifdef __cplusplus
}
#endif

#endif /* CAN_CFG_H_ */
