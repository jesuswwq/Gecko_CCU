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
 * @date 2024-07-16 14:58:17
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
        (CBT_PRESDIV(2U) << 21) | (CBT_RJW(7U) << 16) | (CBT_PROPSEG(15U) << 10) | (CBT_PSEG1(16U) << 5) | CBT_PSEG2(8U),    /* nominalBitTimingRegAlt */
        {   /* fdConfig */
            1U | (1U << 1) | (1U << 2),
            0U,  /* tdcOffset */
            (FDCBT_PRESDIV(2U) << 20) | (FDCBT_RJW(1U) << 16) | (FDCBT_PROPSEG(3U) << 10) | (FDCBT_PSEG1(4U) << 5U) | FDCBT_PSEG2(2U)  /* dataBitTimingRegAlt */
        }
    },  /*CAN FD ON, arbitration baud rate: 500kbps, data baud rate: 2000kbps*/

};

/* CAN controller ID 1 baud rate configurations. */
static const VAR(Can_BaudRateConfigType, CAN_VAR) Can1_BaudRateConfig[] = {
    {   /* Config0 */
        0U, /* baudRateConfigId */
        1U, /* extendBitTimingFormat */
        (CBT_PRESDIV(2U) << 21) | (CBT_RJW(7U) << 16) | (CBT_PROPSEG(15U) << 10) | (CBT_PSEG1(16U) << 5) | CBT_PSEG2(8U),    /* nominalBitTimingRegAlt */
        {   /* fdConfig */
            1U | (1U << 1) | (1U << 2),
            0U,  /* tdcOffset */
            (FDCBT_PRESDIV(2U) << 20) | (FDCBT_RJW(1U) << 16) | (FDCBT_PROPSEG(3U) << 10) | (FDCBT_PSEG1(4U) << 5U) | FDCBT_PSEG2(2U)  /* dataBitTimingRegAlt */
        }
    },  /*CAN FD ON, arbitration baud rate: 500kbps, data baud rate: 2000kbps*/

};

/* Controllers configuration. */
static const VAR(Can_ControllerConfigType, CAN_VAR) Can_ControllerConfig[] = {
    {   /* Controllre ID 0 */
        (boolean)TRUE,   /* Contoller is used=1 or not_used=0*/
        0xf0ae0000U,  /* baseAddr */
        MIXED,  /* rxProcType */
        POLLING,  /* txProcType */
        INTERRUPT,  /* busoffProcType */
        INTERRUPT,  /* wakeupProcType */
        0U,  /* controllerId */
        14U,  /* maxMBNum */
        (1U << 2) | (1U << 4) | (1U << 5), /* option */
        0U,   /* defaultBaudRateId */
        1U,  /* baudRateConfigCount */
        Can0_BaudRateConfig, /* baudRateConfig */
        (3U << 16) | (3U << 19),    /* mbdsrVal */
        RX_FIFO_FILTER_TYPE_A,    /* rxFifoFilterTableFormat */
        MB_PRIORITY_HIGH /* mbPriority */
    },

    {   /* Controllre ID 1 */
        (boolean)TRUE,   /* Contoller is used=1 or not_used=0*/
        0xf0ec0000U,  /* baseAddr */
        MIXED,  /* rxProcType */
        POLLING,  /* txProcType */
        INTERRUPT,  /* busoffProcType */
        INTERRUPT,  /* wakeupProcType */
        1U,  /* controllerId */
        14U,  /* maxMBNum */
        (1U << 2) | (1U << 4) | (1U << 5), /* option */
        0U,   /* defaultBaudRateId */
        1U,  /* baudRateConfigCount */
        Can1_BaudRateConfig, /* baudRateConfig */
        (3U << 16) | (3U << 19),    /* mbdsrVal */
        RX_FIFO_FILTER_TYPE_A,    /* rxFifoFilterTableFormat */
        MB_PRIORITY_HIGH /* mbPriority */
    },

};

/* MB configuration. */
static const VAR(Can_MBConfigType, CAN_VAR) Can_MBConfig[] = {
    {   /* CAN_HRH_RX_PHY */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        0U,  /* canObjId */
        0U,  /* controllerId */
        0U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x701U,   /* filterCode */
        (0x7ffU << 18) | 0xC0000000U | 0x3FFFFU,  /* filterMask */
    },

    {   /* CAN_HTH_RX_FUNC */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        1U,  /* canObjId */
        0U,  /* controllerId */
        7U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x7dfU,   /* filterCode */
        (0x7ffU << 18) | 0xC0000000U | 0x3FFFFU,  /* filterMask */
    },

    {   /* CAN_HRH_RX_PHY_OTA */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        3U,  /* canObjId */
        1U,  /* controllerId */
        0U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x701U,   /* filterCode */
        (0x7ffU << 18) | 0xC0000000U | 0x3FFFFU,  /* filterMask */
    },

    {   /* CAN_HTH_RX_FUNC_OTA */
        CAN_ID_STANDARD, /* idType */
        RECEIVE,    /* hohType */
        4U,  /* canObjId */
        1U,  /* controllerId */
        7U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        FALSE,    /* usePolling */
        0x7dfU,   /* filterCode */
        (0x7ffU << 18) | 0xC0000000U | 0x3FFFFU,  /* filterMask */
    },

    {   /* CAN_HRH_TX_RESP */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        2U,  /* canObjId */
        0U,  /* controllerId */
        8U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        TRUE,    /* usePolling */
        0U,   /* filterCode */
        0U,   /* filterMask */
    },

    {   /* CAN_HRH_TX_RESP_OTA */
        CAN_ID_STANDARD, /* idType */
        TRANSMIT,    /* hohType */
        5U,  /* canObjId */
        1U,  /* controllerId */
        8U,   /* mbId */
        64U,  /* payloadSize */
        0U, /* fdPaddingVal */
        TRUE,    /* usePolling */
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
