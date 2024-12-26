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
 * @file  Can_PBCfg.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Can Driver.
 * @date 2024-12-20 13:44:18
 */
#ifdef __cplusplus
extern "C" {
#endif
#include "Can.h"

/* Version and Check Begin */
/* Version Info Begin */
#define CAN_PBCFG_C_VENDOR_ID    0x8C
#define CAN_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4
#define CAN_PBCFG_C_AR_RELEASE_MINOR_VERSION    3
#define CAN_PBCFG_C_AR_RELEASE_REVISION_VERSION 1
#define CAN_PBCFG_C_SW_MAJOR_VERSION    1
#define CAN_PBCFG_C_SW_MINOR_VERSION    0
#define CAN_PBCFG_C_SW_PATCH_VERSION    0
/* Version Info End */
/* Version and Check End */

#define CAN_START_SEC_CONST_UNSPECIFIED
#include "Can_MemMap.h"
/* CAN controller ID 0 baud rate configurations. */
static const VAR(Can_BaudRateConfigType, CAN_VAR) Can0_BaudRateConfig[] = {
    {   /* Config0 */
        0U, /* baudRateConfigId */
        1U, /* extendBitTimingFormat */
        (CBT_PRESDIV(1U) << 21) | (CBT_RJW(9U) << 16) | (CBT_PROPSEG(20U) << 10) | (CBT_PSEG1(18U) << 5) | CBT_PSEG2(9U),    /* nominalBitTimingRegAlt */
        {   /* fdConfig */
            1U | (1U << 1) | (1U << 2),
            10U,  /* tdcOffset */
            (FDCBT_PRESDIV(1U) << 20) | (FDCBT_RJW(2U) << 16) | (FDCBT_PROPSEG(5U) << 10) | (FDCBT_PSEG1(4U) << 5U) | FDCBT_PSEG2(2U)  /* dataBitTimingRegAlt */
        }
    },  /*CAN FD ON, arbitration baud rate: 500kbps, data baud rate: 2000kbps*/

};

/* CAN controller ID 1 baud rate configurations. */
static const VAR(Can_BaudRateConfigType, CAN_VAR) Can1_BaudRateConfig[] = {
    {   /* Config0 */
        0U, /* baudRateConfigId */
        1U, /* extendBitTimingFormat */
        (CBT_PRESDIV(1U) << 21) | (CBT_RJW(9U) << 16) | (CBT_PROPSEG(20U) << 10) | (CBT_PSEG1(18U) << 5) | CBT_PSEG2(9U),    /* nominalBitTimingRegAlt */
        {   /* fdConfig */
            1U | (1U << 1) | (1U << 2),
            10U,  /* tdcOffset */
            (FDCBT_PRESDIV(1U) << 20) | (FDCBT_RJW(2U) << 16) | (FDCBT_PROPSEG(5U) << 10) | (FDCBT_PSEG1(4U) << 5U) | FDCBT_PSEG2(2U)  /* dataBitTimingRegAlt */
        }
    },  /*CAN FD ON, arbitration baud rate: 500kbps, data baud rate: 2000kbps*/

};

/* CAN controller ID 2 baud rate configurations. */
static const VAR(Can_BaudRateConfigType, CAN_VAR) Can2_BaudRateConfig[] = {
    {   /* Config0 */
        0U, /* baudRateConfigId */
        1U, /* extendBitTimingFormat */
        (CBT_PRESDIV(1U) << 21) | (CBT_RJW(9U) << 16) | (CBT_PROPSEG(20U) << 10) | (CBT_PSEG1(18U) << 5) | CBT_PSEG2(9U),    /* nominalBitTimingRegAlt */
        {   /* fdConfig */
            1U | (1U << 1) | (1U << 2),
            10U,  /* tdcOffset */
            (FDCBT_PRESDIV(1U) << 20) | (FDCBT_RJW(2U) << 16) | (FDCBT_PROPSEG(5U) << 10) | (FDCBT_PSEG1(4U) << 5U) | FDCBT_PSEG2(2U)  /* dataBitTimingRegAlt */
        }
    },  /*CAN FD ON, arbitration baud rate: 500kbps, data baud rate: 2000kbps*/

};

/* CAN controller ID 3 baud rate configurations. */
static const VAR(Can_BaudRateConfigType, CAN_VAR) Can3_BaudRateConfig[] = {
    {   /* Config0 */
        0U, /* baudRateConfigId */
        1U, /* extendBitTimingFormat */
        (CBT_PRESDIV(1U) << 21) | (CBT_RJW(9U) << 16) | (CBT_PROPSEG(20U) << 10) | (CBT_PSEG1(18U) << 5) | CBT_PSEG2(9U),    /* nominalBitTimingRegAlt */
        {   /* fdConfig */
            1U | (1U << 1) | (1U << 2),
            10U,  /* tdcOffset */
            (FDCBT_PRESDIV(1U) << 20) | (FDCBT_RJW(2U) << 16) | (FDCBT_PROPSEG(5U) << 10) | (FDCBT_PSEG1(4U) << 5U) | FDCBT_PSEG2(2U)  /* dataBitTimingRegAlt */
        }
    },  /*CAN FD ON, arbitration baud rate: 500kbps, data baud rate: 2000kbps*/

};

/* CAN controller ID 4 baud rate configurations. */
static const VAR(Can_BaudRateConfigType, CAN_VAR) Can4_BaudRateConfig[] = {
    {   /* Config0 */
        0U, /* baudRateConfigId */
        1U, /* extendBitTimingFormat */
        (CBT_PRESDIV(1U) << 21) | (CBT_RJW(9U) << 16) | (CBT_PROPSEG(20U) << 10) | (CBT_PSEG1(18U) << 5) | CBT_PSEG2(9U),    /* nominalBitTimingRegAlt */
        {   /* fdConfig */
            1U | (1U << 1) | (1U << 2),
            10U,  /* tdcOffset */
            (FDCBT_PRESDIV(1U) << 20) | (FDCBT_RJW(2U) << 16) | (FDCBT_PROPSEG(5U) << 10) | (FDCBT_PSEG1(4U) << 5U) | FDCBT_PSEG2(2U)  /* dataBitTimingRegAlt */
        }
    },  /*CAN FD ON, arbitration baud rate: 500kbps, data baud rate: 2000kbps*/

};

/* CAN controller ID 5 baud rate configurations. */
static const VAR(Can_BaudRateConfigType, CAN_VAR) Can5_BaudRateConfig[] = {
    {   /* Config0 */
        0U, /* baudRateConfigId */
        1U, /* extendBitTimingFormat */
        (CBT_PRESDIV(1U) << 21) | (CBT_RJW(9U) << 16) | (CBT_PROPSEG(20U) << 10) | (CBT_PSEG1(18U) << 5) | CBT_PSEG2(9U),    /* nominalBitTimingRegAlt */
        {   /* fdConfig */
            1U | (1U << 1) | (1U << 2),
            10U,  /* tdcOffset */
            (FDCBT_PRESDIV(1U) << 20) | (FDCBT_RJW(2U) << 16) | (FDCBT_PROPSEG(5U) << 10) | (FDCBT_PSEG1(4U) << 5U) | FDCBT_PSEG2(2U)  /* dataBitTimingRegAlt */
        }
    },  /*CAN FD ON, arbitration baud rate: 500kbps, data baud rate: 2000kbps*/

};

/* Controllers configuration. */
static const VAR(Can_ControllerConfigType, CAN_VAR) Can_ControllerConfig[] = {
    {   /* Controllre ID 0 */
        (boolean)TRUE,   /* Contoller is used=1 or not_used=0*/
        0xf05a0000U,  /* baseAddr */
        INTERRUPT,  /* rxProcType */
        INTERRUPT,  /* txProcType */
        INTERRUPT,  /* busoffProcType */
        INTERRUPT,  /* wakeupProcType */
        0U,  /* controllerId */
        14U,  /* maxMBNum */
        (1U << 4) | (1U << 5), /* option */
        0U,   /* defaultBaudRateId */
        1U,  /* baudRateConfigCount */
        Can0_BaudRateConfig, /* baudRateConfig */
        (3U << 16) | (3U << 19),    /* mbdsrVal */
        RX_FIFO_FILTER_TYPE_A,    /* rxFifoFilterTableFormat */
        MB_PRIORITY_HIGH /* mbPriority */
    },

    {   /* Controllre ID 1 */
        (boolean)TRUE,   /* Contoller is used=1 or not_used=0*/
        0xf05b0000U,  /* baseAddr */
        INTERRUPT,  /* rxProcType */
        INTERRUPT,  /* txProcType */
        INTERRUPT,  /* busoffProcType */
        INTERRUPT,  /* wakeupProcType */
        1U,  /* controllerId */
        64U,  /* maxMBNum */
        (1U << 4) | (1U << 5), /* option */
        0U,   /* defaultBaudRateId */
        1U,  /* baudRateConfigCount */
        Can1_BaudRateConfig, /* baudRateConfig */
        (0U << 16) | (0U << 19),    /* mbdsrVal */
        RX_FIFO_FILTER_TYPE_A,    /* rxFifoFilterTableFormat */
        MB_PRIORITY_HIGH /* mbPriority */
    },

    {   /* Controllre ID 2 */
        (boolean)TRUE,   /* Contoller is used=1 or not_used=0*/
        0xf0ad0000U,  /* baseAddr */
        INTERRUPT,  /* rxProcType */
        INTERRUPT,  /* txProcType */
        INTERRUPT,  /* busoffProcType */
        INTERRUPT,  /* wakeupProcType */
        2U,  /* controllerId */
        14U,  /* maxMBNum */
        (1U << 4) | (1U << 5), /* option */
        0U,   /* defaultBaudRateId */
        1U,  /* baudRateConfigCount */
        Can2_BaudRateConfig, /* baudRateConfig */
        (3U << 16) | (3U << 19),    /* mbdsrVal */
        RX_FIFO_FILTER_TYPE_A,    /* rxFifoFilterTableFormat */
        MB_PRIORITY_HIGH /* mbPriority */
    },

    {   /* Controllre ID 3 */
        (boolean)TRUE,   /* Contoller is used=1 or not_used=0*/
        0xf0eb0000U,  /* baseAddr */
        INTERRUPT,  /* rxProcType */
        INTERRUPT,  /* txProcType */
        INTERRUPT,  /* busoffProcType */
        INTERRUPT,  /* wakeupProcType */
        3U,  /* controllerId */
        64U,  /* maxMBNum */
        (1U << 4) | (1U << 5), /* option */
        0U,   /* defaultBaudRateId */
        1U,  /* baudRateConfigCount */
        Can3_BaudRateConfig, /* baudRateConfig */
        (0U << 16) | (0U << 19),    /* mbdsrVal */
        RX_FIFO_FILTER_TYPE_A,    /* rxFifoFilterTableFormat */
        MB_PRIORITY_HIGH /* mbPriority */
    },

    {   /* Controllre ID 4 */
        (boolean)TRUE,   /* Contoller is used=1 or not_used=0*/
        0xf0ae0000U,  /* baseAddr */
        INTERRUPT,  /* rxProcType */
        INTERRUPT,  /* txProcType */
        INTERRUPT,  /* busoffProcType */
        INTERRUPT,  /* wakeupProcType */
        4U,  /* controllerId */
        39U,  /* maxMBNum */
        (1U << 4) | (1U << 5), /* option */
        0U,   /* defaultBaudRateId */
        1U,  /* baudRateConfigCount */
        Can4_BaudRateConfig, /* baudRateConfig */
        (0U << 16) | (3U << 19),    /* mbdsrVal */
        RX_FIFO_FILTER_TYPE_A,    /* rxFifoFilterTableFormat */
        MB_PRIORITY_HIGH /* mbPriority */
    },

    {   /* Controllre ID 5 */
        (boolean)TRUE,   /* Contoller is used=1 or not_used=0*/
        0xf0ec0000U,  /* baseAddr */
        INTERRUPT,  /* rxProcType */
        INTERRUPT,  /* txProcType */
        INTERRUPT,  /* busoffProcType */
        INTERRUPT,  /* wakeupProcType */
        5U,  /* controllerId */
        19U,  /* maxMBNum */
        (1U << 4) | (1U << 5), /* option */
        0U,   /* defaultBaudRateId */
        1U,  /* baudRateConfigCount */
        Can5_BaudRateConfig, /* baudRateConfig */
        (2U << 16) | (3U << 19),    /* mbdsrVal */
        RX_FIFO_FILTER_TYPE_A,    /* rxFifoFilterTableFormat */
        MB_PRIORITY_HIGH /* mbPriority */
    },

};

/* MB configuration. */
static const VAR(Can_MBConfigType, CAN_VAR) Can_MBConfig[] = {
    {   /* CanHardwareObject_CAN5_0_0x15x0x18x0x19x_CHA */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        0U,  /* canObjId */
        0U,  /* controllerId */
        0U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x100U,   /* filterCode */
        (0x720U << 18) | 0xC0000000U | 0x3FFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CAN5_0_0x12x0x16x_CHA */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        1U,  /* canObjId */
        0U,  /* controllerId */
        1U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x120U,   /* filterCode */
        (0x730U << 18) | 0xC0000000U | 0x3FFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CAN5_0_0X2BF_CHA */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        2U,  /* canObjId */
        0U,  /* controllerId */
        2U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x2bfU,   /* filterCode */
        (0x7ffU << 18) | 0xC0000000U | 0x3FFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CAN5_0_0x13x0x17x_CHA */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        3U,  /* canObjId */
        0U,  /* controllerId */
        3U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x130U,   /* filterCode */
        (0x730U << 18) | 0xC0000000U | 0x3FFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD3_CAN5_0_0x2BE_CHA */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        4U,  /* canObjId */
        0U,  /* controllerId */
        4U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x2beU,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CAN5_0_0x2C1_0x2B8_Rx_CHA */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        5U,  /* canObjId */
        0U,  /* controllerId */
        5U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x280U,   /* filterCode */
        (0x786U << 18) | 0xC0000000U | 0x3FFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD3_CAN5_0_CHA_NM_RX */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        6U,  /* canObjId */
        0U,  /* controllerId */
        6U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x400U,   /* filterCode */
        (0x780U << 18) | 0xC0000000U | 0x3FFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CAN5_1_0x0Ax_CANFD_CHA */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        7U,  /* canObjId */
        0U,  /* controllerId */
        7U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0xa0U,   /* filterCode */
        (0x7f8U << 18) | 0xC0000000U | 0x3FFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CAN5_1_0x3XX_CHA */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        8U,  /* canObjId */
        0U,  /* controllerId */
        8U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x300U,   /* filterCode */
        (0x700U << 18) | 0xC0000000U | 0x3FFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CAN5_1_Diag_0x7xx_Rx_CHA */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        9U,  /* canObjId */
        0U,  /* controllerId */
        9U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x7b0U,   /* filterCode */
        (0x7b0U << 18) | 0xC0000000U | 0x3FFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD5_CAN6_BOD_NM_RX */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        11U,  /* canObjId */
        1U,  /* controllerId */
        0U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x400U,   /* filterCode */
        (0x780U << 18) | 0xC0000000U | 0x3FFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD5_CAN6_ACCM_Version_BOD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        12U,  /* canObjId */
        1U,  /* controllerId */
        1U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x597U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD5_CAN6_AVAS_State_BOD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        13U,  /* canObjId */
        1U,  /* controllerId */
        2U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x311U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD5_CAN6_CCP_PanelStatus_BOD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        14U,  /* canObjId */
        1U,  /* controllerId */
        3U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x1b0U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD5_CAN6_COMP_AC_BOD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        15U,  /* canObjId */
        1U,  /* controllerId */
        4U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x20bU,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD5_CAN6_Diag_Resp_ACCM_BOD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        16U,  /* canObjId */
        1U,  /* controllerId */
        5U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x797U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD5_CAN6_Diag_Resp_AVAS_BOD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        17U,  /* canObjId */
        1U,  /* controllerId */
        6U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x795U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD5_CAN6_Diag_Resp_CCP_BOD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        18U,  /* canObjId */
        1U,  /* controllerId */
        7U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x794U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD5_CAN6_Diag_Resp_ESCL_BOD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        19U,  /* canObjId */
        1U,  /* controllerId */
        8U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x796U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD5_CAN6_Diag_Resp_PTC_BOD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        20U,  /* canObjId */
        1U,  /* controllerId */
        9U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x792U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD5_CAN6_Diag_Resp_SCS_BOD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        21U,  /* canObjId */
        1U,  /* controllerId */
        10U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x793U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD5_CAN6_Diag_Resp_TPMS_BOD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        22U,  /* canObjId */
        1U,  /* controllerId */
        11U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x799U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD5_CAN6_ESCL_ESCLStatus_BOD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        23U,  /* canObjId */
        1U,  /* controllerId */
        12U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x18cU,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD5_CAN6_HVCH_Status1_BOD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        24U,  /* canObjId */
        1U,  /* controllerId */
        13U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x268U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD5_CAN6_HVCH_Status2_BOD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        25U,  /* canObjId */
        1U,  /* controllerId */
        14U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x269U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD5_CAN6_SCS_LeSwitchSts_BOD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        26U,  /* canObjId */
        1U,  /* controllerId */
        15U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x1faU,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD5_CAN6_SCS_RiSwitchSts_BOD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        27U,  /* canObjId */
        1U,  /* controllerId */
        16U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x16aU,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD5_CAN6_TPMS_Info_BOD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        28U,  /* canObjId */
        1U,  /* controllerId */
        17U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x332U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD4_CAN4_XCP_RX */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        30U,  /* canObjId */
        2U,  /* controllerId */
        0U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x667U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_EPT_NM_RX */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        32U,  /* canObjId */
        3U,  /* controllerId */
        0U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x400U,   /* filterCode */
        (0x780U << 18) | 0xC0000000U | 0x3FFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_BMS_10_DC_ChargeStates_EPT */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        33U,  /* canObjId */
        3U,  /* controllerId */
        1U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x15aU,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_BMS_1_MainState_EPT */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        34U,  /* canObjId */
        3U,  /* controllerId */
        2U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x11dU,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_BMS_2_BatState_EPT */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        35U,  /* canObjId */
        3U,  /* controllerId */
        3U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x12aU,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_BMS_3_DC_ChargeState_EPT */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        36U,  /* canObjId */
        3U,  /* controllerId */
        4U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x13aU,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_BMS_4_AC_ChargeState_EPT */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        37U,  /* canObjId */
        3U,  /* controllerId */
        5U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x145U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_BMS_5_BatTemp_EPT */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        38U,  /* canObjId */
        3U,  /* controllerId */
        6U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x1baU,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_BMS_6_DischrgRecup_EPT */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        39U,  /* canObjId */
        3U,  /* controllerId */
        7U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x21dU,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_BMS_7_CellVolt_EPT */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        40U,  /* canObjId */
        3U,  /* controllerId */
        8U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x22eU,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_BMS_8_TempVoltLimit_EPT */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        41U,  /* canObjId */
        3U,  /* controllerId */
        9U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x239U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_BMS_9_BattInfo_EPT */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        42U,  /* canObjId */
        3U,  /* controllerId */
        10U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x271U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_BMS_A_GB_EPT */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        43U,  /* canObjId */
        3U,  /* controllerId */
        11U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x3fcU,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_BMS_B_GB_EPT */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        44U,  /* canObjId */
        3U,  /* controllerId */
        12U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x3fdU,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_BMS_C_GB_EPT */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        45U,  /* canObjId */
        3U,  /* controllerId */
        13U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x3feU,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_BMS_D_GB_EPT */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        46U,  /* canObjId */
        3U,  /* controllerId */
        14U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x3ffU,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_Diag_Resp_BMS_EPT */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        47U,  /* canObjId */
        3U,  /* controllerId */
        15U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x783U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_Diag_Resp_IPUDCC_EPT */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        48U,  /* canObjId */
        3U,  /* controllerId */
        16U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x78dU,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_Diag_Resp_MCU_EPT */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        49U,  /* canObjId */
        3U,  /* controllerId */
        17U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x782U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_INV_1_Value_EPT */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        50U,  /* canObjId */
        3U,  /* controllerId */
        18U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0xf1U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_INV_2_Value_EPT */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        51U,  /* canObjId */
        3U,  /* controllerId */
        19U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0xf2U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_INV_3_Value_EPT */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        52U,  /* canObjId */
        3U,  /* controllerId */
        20U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0xf3U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_INV_4_Value_EPT */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        53U,  /* canObjId */
        3U,  /* controllerId */
        21U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0xf4U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_INV_5_Values_EPT */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        54U,  /* canObjId */
        3U,  /* controllerId */
        22U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x101U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_INV_IMMO_Req_EPT */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        55U,  /* canObjId */
        3U,  /* controllerId */
        23U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x338U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_IPU_DCC_1_State_EPT */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        56U,  /* canObjId */
        3U,  /* controllerId */
        24U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x230U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_IPU_DCC_2_ChrgInValue_EPT */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        57U,  /* canObjId */
        3U,  /* controllerId */
        25U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x280U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_IPU_OBC_1_State_EPT */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        58U,  /* canObjId */
        3U,  /* controllerId */
        26U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x238U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_IPU_OBC_2_Inlet_EPT */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        59U,  /* canObjId */
        3U,  /* controllerId */
        27U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x329U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_IPU_OBC_3_CP_CC_EPT */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        60U,  /* canObjId */
        3U,  /* controllerId */
        28U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x22aU,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_IPU_OBC_4_state_EPT */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        61U,  /* canObjId */
        3U,  /* controllerId */
        29U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x32aU,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_BMS_HMI_EPT */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        62U,  /* canObjId */
        3U,  /* controllerId */
        30U,   /* mbId */
        32U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x2fdU,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_BMS_BEM_EPT */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        63U,  /* canObjId */
        3U,  /* controllerId */
        32U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x30aU,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_BMS_CEM_EPT */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        64U,  /* canObjId */
        3U,  /* controllerId */
        33U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x30bU,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_BMS_BST_EPT */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        65U,  /* canObjId */
        3U,  /* controllerId */
        34U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x30cU,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_BMS_CST_EPT */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        66U,  /* canObjId */
        3U,  /* controllerId */
        35U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x30dU,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_CCU_OBD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        68U,  /* canObjId */
        4U,  /* controllerId */
        32U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x701U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_MCU_OBD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        69U,  /* canObjId */
        4U,  /* controllerId */
        0U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x702U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_BMS_OBD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        70U,  /* canObjId */
        4U,  /* controllerId */
        1U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x703U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_IPUDCC_OBD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        71U,  /* canObjId */
        4U,  /* controllerId */
        2U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x70dU,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_PTC_OBD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        72U,  /* canObjId */
        4U,  /* controllerId */
        3U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x712U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_SCS_OBD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        73U,  /* canObjId */
        4U,  /* controllerId */
        4U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x713U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_CCP_OBD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        74U,  /* canObjId */
        4U,  /* controllerId */
        5U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x714U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_AVAS_OBD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        75U,  /* canObjId */
        4U,  /* controllerId */
        6U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x715U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_ESCL_OBD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        76U,  /* canObjId */
        4U,  /* controllerId */
        7U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x716U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_ACCM_OBD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        77U,  /* canObjId */
        4U,  /* controllerId */
        8U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x717U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_TPMS_OBD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        78U,  /* canObjId */
        4U,  /* controllerId */
        9U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x719U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_CDCICU_OBD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        79U,  /* canObjId */
        4U,  /* controllerId */
        10U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x722U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_ESC_OBD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        80U,  /* canObjId */
        4U,  /* controllerId */
        11U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x732U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_EHB_OBD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        81U,  /* canObjId */
        4U,  /* controllerId */
        12U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x733U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_EPS_OBD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        82U,  /* canObjId */
        4U,  /* controllerId */
        13U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x734U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_PP_OBD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        83U,  /* canObjId */
        4U,  /* controllerId */
        14U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x735U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_FCM_OBD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        84U,  /* canObjId */
        4U,  /* controllerId */
        33U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x736U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_FRM_OBD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        85U,  /* canObjId */
        4U,  /* controllerId */
        15U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x737U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_CRRL_OBD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        86U,  /* canObjId */
        4U,  /* controllerId */
        16U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x73eU,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_CRRR_OBD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        87U,  /* canObjId */
        4U,  /* controllerId */
        17U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x73fU,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_0X7E0_OBD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        88U,  /* canObjId */
        4U,  /* controllerId */
        18U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x7e0U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD7_CAN3_Diag_PhyReq_SRS_OBD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        89U,  /* canObjId */
        4U,  /* controllerId */
        19U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x7f1U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD7_CAN3_Diag_FuncReq_OBD */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        90U,  /* canObjId */
        4U,  /* controllerId */
        20U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x7dfU,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD8_CAN1_BAC_NM_RX */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        92U,  /* canObjId */
        5U,  /* controllerId */
        0U,   /* mbId */
        32U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x400U,   /* filterCode */
        (0x780U << 18) | 0xC0000000U | 0x3FFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_HU_A_BAC */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        93U,  /* canObjId */
        5U,  /* controllerId */
        12U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x1ebU,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_HU_B_BAC */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        94U,  /* canObjId */
        5U,  /* controllerId */
        1U,   /* mbId */
        32U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x1d0U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_HU_C_BAC */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        95U,  /* canObjId */
        5U,  /* controllerId */
        2U,   /* mbId */
        32U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x2fbU,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_ICU_2_Odo_BAC */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        96U,  /* canObjId */
        5U,  /* controllerId */
        3U,   /* mbId */
        32U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x26eU,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_ICU_Info_BAC */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        97U,  /* canObjId */
        5U,  /* controllerId */
        4U,   /* mbId */
        32U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x12fU,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_TBOX_BJS_Time_BAC */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        98U,  /* canObjId */
        5U,  /* controllerId */
        5U,   /* mbId */
        32U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x3b3U,   /* filterCode */
        0xFFFFFFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CANFD8_CAN1_Diag_Rx_BAC */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        99U,  /* canObjId */
        5U,  /* controllerId */
        13U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x700U,   /* filterCode */
        (0x700U << 18) | 0xC0000000U | 0x3FFFFU,  /* filterMask */
    },

    {   /* CanHardwareObject_CAN5_1_Tx_CHA */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        10U,  /* canObjId */
        0U,  /* controllerId */
        10U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CAN5_1_Tx_CHA */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        10U,  /* canObjId */
        0U,  /* controllerId */
        11U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CAN5_1_Tx_CHA */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        10U,  /* canObjId */
        0U,  /* controllerId */
        12U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CAN5_1_Tx_CHA */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        10U,  /* canObjId */
        0U,  /* controllerId */
        13U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD5_CAN6_BOD_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        29U,  /* canObjId */
        1U,  /* controllerId */
        32U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD5_CAN6_BOD_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        29U,  /* canObjId */
        1U,  /* controllerId */
        33U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD5_CAN6_BOD_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        29U,  /* canObjId */
        1U,  /* controllerId */
        34U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD5_CAN6_BOD_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        29U,  /* canObjId */
        1U,  /* controllerId */
        35U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD5_CAN6_BOD_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        29U,  /* canObjId */
        1U,  /* controllerId */
        36U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD5_CAN6_BOD_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        29U,  /* canObjId */
        1U,  /* controllerId */
        37U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD5_CAN6_BOD_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        29U,  /* canObjId */
        1U,  /* controllerId */
        38U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD5_CAN6_BOD_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        29U,  /* canObjId */
        1U,  /* controllerId */
        39U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD5_CAN6_BOD_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        29U,  /* canObjId */
        1U,  /* controllerId */
        40U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD5_CAN6_BOD_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        29U,  /* canObjId */
        1U,  /* controllerId */
        41U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD5_CAN6_BOD_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        29U,  /* canObjId */
        1U,  /* controllerId */
        42U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD5_CAN6_BOD_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        29U,  /* canObjId */
        1U,  /* controllerId */
        43U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD5_CAN6_BOD_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        29U,  /* canObjId */
        1U,  /* controllerId */
        44U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD5_CAN6_BOD_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        29U,  /* canObjId */
        1U,  /* controllerId */
        45U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD5_CAN6_BOD_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        29U,  /* canObjId */
        1U,  /* controllerId */
        46U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD5_CAN6_BOD_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        29U,  /* canObjId */
        1U,  /* controllerId */
        47U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD4_CAN4_XCP_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        31U,  /* canObjId */
        2U,  /* controllerId */
        7U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD4_CAN4_XCP_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        31U,  /* canObjId */
        2U,  /* controllerId */
        8U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD4_CAN4_XCP_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        31U,  /* canObjId */
        2U,  /* controllerId */
        9U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD4_CAN4_XCP_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        31U,  /* canObjId */
        2U,  /* controllerId */
        10U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD4_CAN4_XCP_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        31U,  /* canObjId */
        2U,  /* controllerId */
        11U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_EPT_NM_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        67U,  /* canObjId */
        3U,  /* controllerId */
        36U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_EPT_NM_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        67U,  /* canObjId */
        3U,  /* controllerId */
        37U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_EPT_NM_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        67U,  /* canObjId */
        3U,  /* controllerId */
        38U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_EPT_NM_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        67U,  /* canObjId */
        3U,  /* controllerId */
        39U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_EPT_NM_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        67U,  /* canObjId */
        3U,  /* controllerId */
        40U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_EPT_NM_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        67U,  /* canObjId */
        3U,  /* controllerId */
        41U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_EPT_NM_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        67U,  /* canObjId */
        3U,  /* controllerId */
        42U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_EPT_NM_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        67U,  /* canObjId */
        3U,  /* controllerId */
        43U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_EPT_NM_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        67U,  /* canObjId */
        3U,  /* controllerId */
        44U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_EPT_NM_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        67U,  /* canObjId */
        3U,  /* controllerId */
        45U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_EPT_NM_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        67U,  /* canObjId */
        3U,  /* controllerId */
        46U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_EPT_NM_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        67U,  /* canObjId */
        3U,  /* controllerId */
        47U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_EPT_NM_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        67U,  /* canObjId */
        3U,  /* controllerId */
        48U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_EPT_NM_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        67U,  /* canObjId */
        3U,  /* controllerId */
        49U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD6_CAN2_EPT_NM_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        67U,  /* canObjId */
        3U,  /* controllerId */
        50U,   /* mbId */
        8U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD7_CAN3_OBD_Diag_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        91U,  /* canObjId */
        4U,  /* controllerId */
        34U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD7_CAN3_OBD_Diag_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        91U,  /* canObjId */
        4U,  /* controllerId */
        35U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD7_CAN3_OBD_Diag_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        91U,  /* canObjId */
        4U,  /* controllerId */
        36U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD7_CAN3_OBD_Diag_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        91U,  /* canObjId */
        4U,  /* controllerId */
        37U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD7_CAN3_OBD_Diag_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        91U,  /* canObjId */
        4U,  /* controllerId */
        38U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD8_BAC_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        100U,  /* canObjId */
        5U,  /* controllerId */
        6U,   /* mbId */
        32U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD8_BAC_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        100U,  /* canObjId */
        5U,  /* controllerId */
        7U,   /* mbId */
        32U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD8_BAC_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        100U,  /* canObjId */
        5U,  /* controllerId */
        8U,   /* mbId */
        32U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD8_BAC_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        100U,  /* canObjId */
        5U,  /* controllerId */
        9U,   /* mbId */
        32U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD8_BAC_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        100U,  /* canObjId */
        5U,  /* controllerId */
        10U,   /* mbId */
        32U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD8_BAC_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        100U,  /* canObjId */
        5U,  /* controllerId */
        11U,   /* mbId */
        32U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD64_CAN1_BAC_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        101U,  /* canObjId */
        5U,  /* controllerId */
        14U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD64_CAN1_BAC_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        101U,  /* canObjId */
        5U,  /* controllerId */
        15U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD64_CAN1_BAC_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        101U,  /* canObjId */
        5U,  /* controllerId */
        16U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD64_CAN1_BAC_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        101U,  /* canObjId */
        5U,  /* controllerId */
        17U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CanHardwareObject_CANFD64_CAN1_BAC_TX */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        101U,  /* canObjId */
        5U,  /* controllerId */
        18U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

};

/* CAN configuration. */
CONST(Can_ConfigType, CAN_VAR) Can_Config = {
    Can_ControllerConfig,
    Can_MBConfig,
    NULL_PTR,
    FIRST_HTH_INDEX
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
#include "Can_MemMap.h"


#ifdef __cplusplus
}
#endif
