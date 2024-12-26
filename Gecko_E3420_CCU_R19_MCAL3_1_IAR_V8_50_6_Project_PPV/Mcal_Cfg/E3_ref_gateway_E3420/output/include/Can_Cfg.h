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
 * @date 2024-08-01 14:10:22
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
 * @brief Specify whether Rx/Tx polling period 0 is supported or not.
 */
#define CAN_MAINFUNCTION_RW_PERIOD_0 (STD_OFF)

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
#define CAN_CONTROLLER_COUNT (6U)

/**
 * @brief Specify whether CAN driver should support CAN FD.
 */

#define CAN_FD_SUPPORT  (STD_ON)

/**
 * @brief The definition of HOHs.
 */
#define CanHardwareObject_CAN5_0_0x15x0x18x0x19x_CHA 0U
#define CanHardwareObject_CAN5_0_0x12x0x16x_CHA 1U
#define CanHardwareObject_CAN5_0_0X2BF_CHA 2U
#define CanHardwareObject_CAN5_0_0x13x0x17x_CHA 3U
#define CanHardwareObject_CANFD3_CAN5_0_0x2BE_CHA 4U
#define CanHardwareObject_CAN5_0_0x2C1_0x2B8_Rx_CHA 5U
#define CanHardwareObject_CANFD3_CAN5_0_CHA_NM_RX 6U
#define CanHardwareObject_CAN5_1_0x0Ax_CANFD_CHA 7U
#define CanHardwareObject_CAN5_1_0x3XX_CHA 8U
#define CanHardwareObject_CAN5_1_Diag_0x7xx_Rx_CHA 9U
#define CanHardwareObject_CAN5_1_Tx_CHA 10U
#define CanHardwareObject_CANFD5_CAN6_BOD_NM_RX 11U
#define CanHardwareObject_CANFD5_CAN6_ACCM_Version_BOD 12U
#define CanHardwareObject_CANFD5_CAN6_AVAS_State_BOD 13U
#define CanHardwareObject_CANFD5_CAN6_CCP_PanelStatus_BOD 14U
#define CanHardwareObject_CANFD5_CAN6_COMP_AC_BOD 15U
#define CanHardwareObject_CANFD5_CAN6_Diag_Resp_ACCM_BOD 16U
#define CanHardwareObject_CANFD5_CAN6_Diag_Resp_AVAS_BOD 17U
#define CanHardwareObject_CANFD5_CAN6_Diag_Resp_CCP_BOD 18U
#define CanHardwareObject_CANFD5_CAN6_Diag_Resp_ESCL_BOD 19U
#define CanHardwareObject_CANFD5_CAN6_Diag_Resp_PTC_BOD 20U
#define CanHardwareObject_CANFD5_CAN6_Diag_Resp_SCS_BOD 21U
#define CanHardwareObject_CANFD5_CAN6_Diag_Resp_TPMS_BOD 22U
#define CanHardwareObject_CANFD5_CAN6_ESCL_ESCLStatus_BOD 23U
#define CanHardwareObject_CANFD5_CAN6_HVCH_Status1_BOD 24U
#define CanHardwareObject_CANFD5_CAN6_HVCH_Status2_BOD 25U
#define CanHardwareObject_CANFD5_CAN6_SCS_LeSwitchSts_BOD 26U
#define CanHardwareObject_CANFD5_CAN6_SCS_RiSwitchSts_BOD 27U
#define CanHardwareObject_CANFD5_CAN6_TPMS_Info_BOD 28U
#define CanHardwareObject_CANFD5_CAN6_BOD_TX 29U
#define CanHardwareObject_CANFD4_CAN4_XCP_RX 30U
#define CanHardwareObject_CANFD4_CAN4_XCP_TX 31U
#define CanHardwareObject_CANFD6_CAN2_EPT_NM_RX 32U
#define CanHardwareObject_CANFD6_CAN2_BMS_10_DC_ChargeStates_EPT 33U
#define CanHardwareObject_CANFD6_CAN2_BMS_1_MainState_EPT 34U
#define CanHardwareObject_CANFD6_CAN2_BMS_2_BatState_EPT 35U
#define CanHardwareObject_CANFD6_CAN2_BMS_3_DC_ChargeState_EPT 36U
#define CanHardwareObject_CANFD6_CAN2_BMS_4_AC_ChargeState_EPT 37U
#define CanHardwareObject_CANFD6_CAN2_BMS_5_BatTemp_EPT 38U
#define CanHardwareObject_CANFD6_CAN2_BMS_6_DischrgRecup_EPT 39U
#define CanHardwareObject_CANFD6_CAN2_BMS_7_CellVolt_EPT 40U
#define CanHardwareObject_CANFD6_CAN2_BMS_8_TempVoltLimit_EPT 41U
#define CanHardwareObject_CANFD6_CAN2_BMS_9_BattInfo_EPT 42U
#define CanHardwareObject_CANFD6_CAN2_BMS_A_GB_EPT 43U
#define CanHardwareObject_CANFD6_CAN2_BMS_B_GB_EPT 44U
#define CanHardwareObject_CANFD6_CAN2_BMS_C_GB_EPT 45U
#define CanHardwareObject_CANFD6_CAN2_BMS_D_GB_EPT 46U
#define CanHardwareObject_CANFD6_CAN2_Diag_Resp_BMS_EPT 47U
#define CanHardwareObject_CANFD6_CAN2_Diag_Resp_IPUDCC_EPT 48U
#define CanHardwareObject_CANFD6_CAN2_Diag_Resp_MCU_EPT 49U
#define CanHardwareObject_CANFD6_CAN2_INV_1_Value_EPT 50U
#define CanHardwareObject_CANFD6_CAN2_INV_2_Value_EPT 51U
#define CanHardwareObject_CANFD6_CAN2_INV_3_Value_EPT 52U
#define CanHardwareObject_CANFD6_CAN2_INV_4_Value_EPT 53U
#define CanHardwareObject_CANFD6_CAN2_INV_5_Values_EPT 54U
#define CanHardwareObject_CANFD6_CAN2_INV_IMMO_Req_EPT 55U
#define CanHardwareObject_CANFD6_CAN2_IPU_DCC_1_State_EPT 56U
#define CanHardwareObject_CANFD6_CAN2_IPU_DCC_2_ChrgInValue_EPT 57U
#define CanHardwareObject_CANFD6_CAN2_IPU_OBC_1_State_EPT 58U
#define CanHardwareObject_CANFD6_CAN2_IPU_OBC_2_Inlet_EPT 59U
#define CanHardwareObject_CANFD6_CAN2_IPU_OBC_3_CP_CC_EPT 60U
#define CanHardwareObject_CANFD6_CAN2_IPU_OBC_4_state_EPT 61U
#define CanHardwareObject_CANFD6_CAN2_BMS_HMI_EPT 62U
#define CanHardwareObject_CANFD6_CAN2_BMS_BEM_EPT 63U
#define CanHardwareObject_CANFD6_CAN2_BMS_CEM_EPT 64U
#define CanHardwareObject_CANFD6_CAN2_BMS_BST_EPT 65U
#define CanHardwareObject_CANFD6_CAN2_BMS_CST_EPT 66U
#define CanHardwareObject_CANFD6_CAN2_EPT_NM_TX 67U
#define CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_CCU_OBD 68U
#define CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_MCU_OBD 69U
#define CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_BMS_OBD 70U
#define CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_IPUDCC_OBD 71U
#define CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_PTC_OBD 72U
#define CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_SCS_OBD 73U
#define CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_CCP_OBD 74U
#define CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_AVAS_OBD 75U
#define CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_ESCL_OBD 76U
#define CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_ACCM_OBD 77U
#define CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_TPMS_OBD 78U
#define CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_CDCICU_OBD 79U
#define CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_ESC_OBD 80U
#define CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_EHB_OBD 81U
#define CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_EPS_OBD 82U
#define CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_PP_OBD 83U
#define CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_FCM_OBD 84U
#define CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_FRM_OBD 85U
#define CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_CRRL_OBD 86U
#define CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_CRRR_OBD 87U
#define CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_0X7E0_OBD 88U
#define CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_SRS_OBD 89U
#define CanHardwareObject_CANFD7_CAN3_Diag_FuncReq_OBD 90U
#define CanHardwareObject_CANFD7_CAN3_OBD_Diag_TX 91U
#define CanHardwareObject_CANFD8_CAN1_BAC_NM_RX 92U
#define CanHardwareObject_HU_A_BAC 93U
#define CanHardwareObject_HU_B_BAC 94U
#define CanHardwareObject_HU_C_BAC 95U
#define CanHardwareObject_ICU_2_Odo_BAC 96U
#define CanHardwareObject_ICU_Info_BAC 97U
#define CanHardwareObject_TBOX_BJS_Time_BAC 98U
#define CanHardwareObject_CANFD8_CAN1_Diag_Rx_BAC 99U
#define CanHardwareObject_CANFD8_BAC_TX 100U
#define CanHardwareObject_CANFD64_CAN1_BAC_TX 101U

#define CAN_HOH_MAX 102U

/**
 * @brief The first HTH configuration index.
 */
#define FIRST_HTH_INDEX (95U)

/**
 * @brief The number of all Rx and Tx MBs.
 */
#define CAN_MB_COUNT (151U)

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
#define CanConf_CanController_CANFD3_CHA_CAN5 0U
#define CanConf_CanController_CANFD4_BOD_CAN4 1U
#define CanConf_CanController_CANFD5_XCP_CAN6 2U
#define CanConf_CanController_CANFD6_EPT_CAN2 3U
#define CanConf_CanController_CANFD7_OBD_CAN3 4U
#define CanConf_CanController_CANFD8_BAC_CAN1 5U




#ifdef __cplusplus
}
#endif

#endif /* CAN_CFG_H_ */
