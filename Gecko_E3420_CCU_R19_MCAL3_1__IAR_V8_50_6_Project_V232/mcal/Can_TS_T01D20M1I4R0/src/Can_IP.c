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
 * @file  Can_IP.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Can Driver.
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Mcal.h"
#include "Det.h"
#include "RegBase.h"
#include "Mcu_Soc.h"
#include "Mcu_ScrBits.h"
#include "Mcu_Scr.h"
#include "Can.h"
#include "CanIf_Cbk.h"
#include "SchM_Can.h"
#include "Can_IP_Reg.h"
#include "Mcu_Delay.h"
#include "Can_IP.h"
/* Version and Check Begin */
/* Version Info Begin */
#define CAN_IP_C_VENDOR_ID    0x8C
#define CAN_IP_C_AR_RELEASE_MAJOR_VERSION    4
#define CAN_IP_C_AR_RELEASE_MINOR_VERSION    3
#define CAN_IP_C_AR_RELEASE_REVISION_VERSION 1
#define CAN_IP_C_SW_MAJOR_VERSION    1
#define CAN_IP_C_SW_MINOR_VERSION    0
#define CAN_IP_C_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((CAN_IP_C_AR_RELEASE_MAJOR_VERSION != MCAL_H_AR_RELEASE_MAJOR_VERSION)\
    || (CAN_IP_C_AR_RELEASE_MINOR_VERSION != MCAL_H_AR_RELEASE_MINOR_VERSION)\
    || (CAN_IP_C_AR_RELEASE_REVISION_VERSION != MCAL_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Can_IP.c and Mcal.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((CAN_IP_C_SW_MAJOR_VERSION != MCAL_H_SW_MAJOR_VERSION)\
    || (CAN_IP_C_SW_MINOR_VERSION != MCAL_H_SW_MINOR_VERSION)\
    || (CAN_IP_C_SW_PATCH_VERSION != MCAL_H_SW_PATCH_VERSION))
#error "Opps, Can_IP.c and Mcal.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((CAN_IP_C_AR_RELEASE_MAJOR_VERSION != DET_H_AR_RELEASE_MAJOR_VERSION)\
    || (CAN_IP_C_AR_RELEASE_MINOR_VERSION != DET_H_AR_RELEASE_MINOR_VERSION)\
    || (CAN_IP_C_AR_RELEASE_REVISION_VERSION != DET_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Can_IP.c and Det.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((CAN_IP_C_SW_MAJOR_VERSION != DET_H_SW_MAJOR_VERSION)\
    || (CAN_IP_C_SW_MINOR_VERSION != DET_H_SW_MINOR_VERSION)\
    || (CAN_IP_C_SW_PATCH_VERSION != DET_H_SW_PATCH_VERSION))
#error "Opps, Can_IP.c and Det.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((CAN_IP_C_AR_RELEASE_MAJOR_VERSION != REGBASE_H_AR_RELEASE_MAJOR_VERSION)\
    || (CAN_IP_C_AR_RELEASE_MINOR_VERSION != REGBASE_H_AR_RELEASE_MINOR_VERSION)\
    || (CAN_IP_C_AR_RELEASE_REVISION_VERSION != REGBASE_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Can_IP.c and RegBase.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((CAN_IP_C_SW_MAJOR_VERSION != REGBASE_H_SW_MAJOR_VERSION)\
    || (CAN_IP_C_SW_MINOR_VERSION != REGBASE_H_SW_MINOR_VERSION)\
    || (CAN_IP_C_SW_PATCH_VERSION != REGBASE_H_SW_PATCH_VERSION))
#error "Opps, Can_IP.c and RegBase.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((CAN_IP_C_AR_RELEASE_MAJOR_VERSION != MCU_SOC_H_AR_RELEASE_MAJOR_VERSION)\
    || (CAN_IP_C_AR_RELEASE_MINOR_VERSION != MCU_SOC_H_AR_RELEASE_MINOR_VERSION)\
    || (CAN_IP_C_AR_RELEASE_REVISION_VERSION != MCU_SOC_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Can_IP.c and Mcu_Soc.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((CAN_IP_C_SW_MAJOR_VERSION != MCU_SOC_H_SW_MAJOR_VERSION)\
    || (CAN_IP_C_SW_MINOR_VERSION != MCU_SOC_H_SW_MINOR_VERSION)\
    || (CAN_IP_C_SW_PATCH_VERSION != MCU_SOC_H_SW_PATCH_VERSION))
#error "Opps, Can_IP.c and Mcu_Soc.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((CAN_IP_C_AR_RELEASE_MAJOR_VERSION != MCU_SCRBITS_H_AR_RELEASE_MAJOR_VERSION)\
    || (CAN_IP_C_AR_RELEASE_MINOR_VERSION != MCU_SCRBITS_H_AR_RELEASE_MINOR_VERSION)\
    || (CAN_IP_C_AR_RELEASE_REVISION_VERSION != MCU_SCRBITS_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Can_IP.c and Mcu_ScrBits.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((CAN_IP_C_SW_MAJOR_VERSION != MCU_SCRBITS_H_SW_MAJOR_VERSION)\
    || (CAN_IP_C_SW_MINOR_VERSION != MCU_SCRBITS_H_SW_MINOR_VERSION)\
    || (CAN_IP_C_SW_PATCH_VERSION != MCU_SCRBITS_H_SW_PATCH_VERSION))
#error "Opps, Can_IP.c and Mcu_ScrBits.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((CAN_IP_C_AR_RELEASE_MAJOR_VERSION != MCU_SCR_H_AR_RELEASE_MAJOR_VERSION)\
    || (CAN_IP_C_AR_RELEASE_MINOR_VERSION != MCU_SCR_H_AR_RELEASE_MINOR_VERSION)\
    || (CAN_IP_C_AR_RELEASE_REVISION_VERSION != MCU_SCR_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Can_IP.c and Mcu_Scr.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((CAN_IP_C_SW_MAJOR_VERSION != MCU_SCR_H_SW_MAJOR_VERSION)\
    || (CAN_IP_C_SW_MINOR_VERSION != MCU_SCR_H_SW_MINOR_VERSION)\
    || (CAN_IP_C_SW_PATCH_VERSION != MCU_SCR_H_SW_PATCH_VERSION))
#error "Opps, Can_IP.c and Mcu_Scr.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((CAN_IP_C_AR_RELEASE_MAJOR_VERSION != CAN_H_AR_RELEASE_MAJOR_VERSION)\
    || (CAN_IP_C_AR_RELEASE_MINOR_VERSION != CAN_H_AR_RELEASE_MINOR_VERSION)\
    || (CAN_IP_C_AR_RELEASE_REVISION_VERSION != CAN_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Can_IP.c and Can.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((CAN_IP_C_SW_MAJOR_VERSION != CAN_H_SW_MAJOR_VERSION)\
    || (CAN_IP_C_SW_MINOR_VERSION != CAN_H_SW_MINOR_VERSION)\
    || (CAN_IP_C_SW_PATCH_VERSION != CAN_H_SW_PATCH_VERSION))
#error "Opps, Can_IP.c and Can.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((CAN_IP_C_AR_RELEASE_MAJOR_VERSION != CANIF_CBK_H_AR_RELEASE_MAJOR_VERSION)\
    || (CAN_IP_C_AR_RELEASE_MINOR_VERSION != CANIF_CBK_H_AR_RELEASE_MINOR_VERSION)\
    || (CAN_IP_C_AR_RELEASE_REVISION_VERSION != CANIF_CBK_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Can_IP.c and CanIf_Cbk.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((CAN_IP_C_SW_MAJOR_VERSION != CANIF_CBK_H_SW_MAJOR_VERSION)\
    || (CAN_IP_C_SW_MINOR_VERSION != CANIF_CBK_H_SW_MINOR_VERSION)\
    || (CAN_IP_C_SW_PATCH_VERSION != CANIF_CBK_H_SW_PATCH_VERSION))
#error "Opps, Can_IP.c and CanIf_Cbk.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((CAN_IP_C_AR_RELEASE_MAJOR_VERSION != SCHM_CAN_H_AR_RELEASE_MAJOR_VERSION)\
    || (CAN_IP_C_AR_RELEASE_MINOR_VERSION != SCHM_CAN_H_AR_RELEASE_MINOR_VERSION)\
    || (CAN_IP_C_AR_RELEASE_REVISION_VERSION != SCHM_CAN_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Can_IP.c and SchM_Can.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((CAN_IP_C_SW_MAJOR_VERSION != SCHM_CAN_H_SW_MAJOR_VERSION)\
    || (CAN_IP_C_SW_MINOR_VERSION != SCHM_CAN_H_SW_MINOR_VERSION)\
    || (CAN_IP_C_SW_PATCH_VERSION != SCHM_CAN_H_SW_PATCH_VERSION))
#error "Opps, Can_IP.c and SchM_Can.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((CAN_IP_C_AR_RELEASE_MAJOR_VERSION != CAN_IP_REG_H_AR_RELEASE_MAJOR_VERSION)\
    || (CAN_IP_C_AR_RELEASE_MINOR_VERSION != CAN_IP_REG_H_AR_RELEASE_MINOR_VERSION)\
    || (CAN_IP_C_AR_RELEASE_REVISION_VERSION != CAN_IP_REG_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Can_IP.c and Can_IP_Reg.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((CAN_IP_C_SW_MAJOR_VERSION != CAN_IP_REG_H_SW_MAJOR_VERSION)\
    || (CAN_IP_C_SW_MINOR_VERSION != CAN_IP_REG_H_SW_MINOR_VERSION)\
    || (CAN_IP_C_SW_PATCH_VERSION != CAN_IP_REG_H_SW_PATCH_VERSION))
#error "Opps, Can_IP.c and Can_IP_Reg.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((CAN_IP_C_AR_RELEASE_MAJOR_VERSION != CAN_IP_H_AR_RELEASE_MAJOR_VERSION)\
    || (CAN_IP_C_AR_RELEASE_MINOR_VERSION != CAN_IP_H_AR_RELEASE_MINOR_VERSION)\
    || (CAN_IP_C_AR_RELEASE_REVISION_VERSION != CAN_IP_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Can_IP.c and Can_IP.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((CAN_IP_C_SW_MAJOR_VERSION != CAN_IP_H_SW_MAJOR_VERSION)\
    || (CAN_IP_C_SW_MINOR_VERSION != CAN_IP_H_SW_MINOR_VERSION)\
    || (CAN_IP_C_SW_PATCH_VERSION != CAN_IP_H_SW_PATCH_VERSION))
#error "Opps, Can_IP.c and Can_IP.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

/**
 * @brief Doze mode feature definition.
 */
#define FLEXCAN_HAS_DOZE_MODE   1

/**
 * @brief Wakeup source filter feature definition.
 */
#define FLEXCAN_HAS_WAKEUP_SOURCE_FILTER    1

/**
 * @brief Basic configuration definition.
 */
#define LOOP_BACK_EN            (1U << 0)
#define LISTEN_ONLY_EN          (1U << 1)
#define SELF_WAKE_UP_EN         (1U << 2)
#define PE_CLOCK_FROM_OSC       (1U << 3)
#define INDIVIDUAL_RX_MASK_EN   (1U << 4)
#define DOZE_MODE_EN            (1U << 5)
#define RX_FIFO_EN              (1U << 6)
#define LOWEST_NUM_MB_FISRT_EN  (1U << 7)

/**
 * @brief CAN FD basic configuration definition.
 */
#define CAN_FD_EN               (1U << 0)
#define ISO_CAN_FD_EN           (1U << 1)
#define TX_BRS_EN               (1U << 2)
#define TDC_EN                  (1U << 3)

/**
 * @brief CAN fault confinement state.
 */
#define CAN_ESR1_FLTCONF_ERROR_ACTIVE   (0U)
#define CAN_ESR1_FLTCONF_ERROR_PASSIVE  (0x10U)

/**
 * @brief FlexCAN message buffer CODE for Rx buffers.
 */
#define FLEXCAN_RX_MB_INACTIVE  0x0U   /*!< MB is not active.*/
#define FLEXCAN_RX_MB_FULL      0x2U   /*!< MB is full.*/
#define FLEXCAN_RX_MB_EMPTY     0x4U   /*!< MB is active and empty.*/
#define FLEXCAN_RX_MB_OVERRUN   0x6U   /*!< MB is overwritten into a full buffer.*/
#define FLEXCAN_RX_MB_BUSY      0x8U   /*!< FlexCAN is updating the contents of the MB.*/
/*!  The CPU must not access the MB.*/
#define FLEXCAN_RX_MB_RANSWER   0xAU   /*!< MB is configured to recognize a Remote Request Frame*/
/*!  and transmit a Response Frame in return.*/
#define FLEXCAN_RX_MB_NOT_USED  0xFU   /*!< Not used*/

/**
 * @brief FlexCAN message buffer CODE FOR Tx buffers.
 */
#define FLEXCAN_TX_MB_INACTIVE          0x8U    /*!< MB is not active.*/
#define FLEXCAN_TX_MB_ABORT             0x9U    /*!< MB is aborted.*/
#define FLEXCAN_TX_MB_DATA_OR_REMOTE    0xCU    /*!< MB is a TX Data Frame(when MB RTR = 0) or*/
/*!< MB is a TX Remote Request Frame (when MB RTR = 1).*/
#define FLEXCAN_TX_MB_TANSWER           0xEU    /*!< MB is a TX Response Request Frame from.*/
/*!  an incoming Remote Request Frame.*/
#define FLEXCAN_TX_MB_NOT_USED          0xFU    /*!< Not used*/

/*!
 * @brief FlexCAN Rx FIFO status flags.
 *
 * The FlexCAN Rx FIFO Status enumerations is used to ditermine the status of
 * Rx FIFO. Because Rx FIFO occupy the MB0 ~ MB7(Rx Fifo filter will also occupy
 * more Message Buffer space), Rx FIFO status flags are maped to corresponding
 * Message Buffer status flags.
 */
#define FLEXCAN_RX_FIFO_OVERFLOW_FLAG           CAN_IFLAG1_BUF7I_MASK /*!< Rx FIFO overflow flag. */
#define FLEXCAN_RX_FIFO_WARNING_FLAG            CAN_IFLAG1_BUF6I_MASK /*!< Rx FIFO almost full flag. */
#define FLEXCAN_RX_FIFO_FRAME_AVAILABLE_FLAG    CAN_IFLAG1_BUF5I_MASK /*!< Frames available in Rx FIFO flag. */

/*!
 * @brief FlexCAN interrupt configuration structure, default settings all disabled.
 *
 * This structure contains the settings for all of the FlexCAN Module interrupt configurations.
 * Note: FlexCAN Message Buffers and Rx FIFO have their own interrupts.
 */
#define FLEXCAN_BUSOFF_INT_ENABLE       CAN_CTRL1_BOFFMSK_MASK   /*!< Bus Off interrupt. */
#define FLEXCAN_ERROR_INT_ENABLE        CAN_CTRL1_ERRMSK_MASK    /*!< Error interrupt. */
#define FLEXCAN_RX_WARNING_INT_ENABLE   CAN_CTRL1_RWRNMSK_MASK   /*!< Rx Warning interrupt. */
#define FLEXCAN_TX_WARNING_INT_ENABLE   CAN_CTRL1_TWRNMSK_MASK   /*!< Tx Warning interrupt. */
#define FLEXCAN_WAKEUP_INT_ENABLE       CAN_MCR_WAKMSK_MASK      /*!< CAN_MCR_WAKMSK_MASK, Wake Up interrupt. */

/**
 * @brief low power/freeze mode regiter operator counter.
 */
#define FLEXCAN_TIMEOUT_CNT 1000000u

/**
 * @brief register mode, throught the scr bit control can internal bit enter doze/stop mode, gate partily clk
 *        interface mode, gate the clk from clkgen, all clk to can ip gated,\
 *        user can only  select one mode after driver inited.
 */
#define FLEXCAN_LOWPOWER_REGISTER_MODE

#define CAN_LOW_POWER_SUPPORT

#if !defined(SEMIDRIVE_E3_LITE_SERIES)
#define CAN_MAX_CONTROLLER_CNT 24
#else
#define CAN_MAX_CONTROLLER_CNT 8u
#endif /* #if !defined(SEMIDRIVE_E3_LITE_SERIES) */
/**
 * @brief CAN controller interrupt mask structure.
 */
typedef struct
{
    uint32 errIntMask;
    uint32 wakeUpIntMask;
    uint32 mb_0_31_IntMask;
    uint32 mb_32_63_IntMask;
} Can_ControllerIntMaskType;

/**
 * @brief MB type: Rx or Tx.
 */
typedef enum
{
    MB_UNUSED = 0U,
    MB_RX,
    MB_TX
} Can_MBTypeType;

/**
 * @brief MB state.
 */
typedef enum
{
    MB_IDLE = 0U,
    MB_BUSY
} Can_MBStateType;

/**
 * @brief MB information structure.
 */
typedef struct
{
    uint16 hwObjId;
    PduIdType canIfPduId;
    Can_MBTypeType mbType;
    Can_MBStateType mbState;
} Can_MBInfoType;

/**
 * @brief CAN controller information structure.
 */
typedef struct
{
    Can_ControllerIntMaskType intMask;
    Can_MBInfoType mbInfo[FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBER];
    uint16 pollingMBConfigIndex[FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBER];
    uint8 pollingMBNum;
    uint8 firstTxPollingMBPos;
    boolean rxFifoUsePolling;
#if (CAN_MULTIPLE_READ_PERIOD == STD_ON)
    uint8 rxFifoPollingPeriodId;
#endif
} Can_ControllerInfoType;

/**
 * @brief Rx frame structure.
 */
typedef struct
{
    Can_IdType id;
    uint8 data[64];
    uint8 length;
} Can_RxFrameType;

/**
 * @brief CAN stop/doze bits in SCR.
 */
typedef struct
{
    uint32 can_addr;
    scr_signal_t can_scr;
} Can_ScrBitsType;

/**
 * @brief CAN sleep mode type.
 */
typedef enum
{
    DOZE_MODE = 0U,
    STOP_MODE
} Can_SleepModeType;

#ifdef CanLPduReceiveCalloutFunction
extern FUNC(Std_ReturnType, CAN_CODE) CanLPduReceiveCalloutFunction
(
    VAR(uint16, AUTOMATIC) Hrh,
    VAR(Can_IdType, AUTOMATIC) CanId,
    VAR(uint8, AUTOMATIC) Dlc,
    P2CONST(uint8, AUTOMATIC, CAN_APPL_CONST) SduPtr
);
#endif

#define CAN_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Can_MemMap.h"

VAR(uint8, CAN_VAR) g_eControllerBusoffState[CAN_CONTROLLER_COUNT];

static VAR(Can_ControllerInfoType, CAN_VAR) g_CanControllerInfo[CAN_CONTROLLER_COUNT];

#define CAN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Can_MemMap.h"

/* SCR register information lookup table used by CAN sleep. */
#define SCR_CAN_INO(id) \
    {APB_CANFD##id##_BASE, SCR_SF_CANFD##id##_STOP_DOZE_SEL}

#define CAN_START_SEC_CONST_UNSPECIFIED
#include "Can_MemMap.h"

#if !defined(SEMIDRIVE_E3_LITE_SERIES)
static const VAR(Can_ScrBitsType, CAN_VAR) g_CanScrinfo[CAN_MAX_CONTROLLER_CNT] =
{
    SCR_CAN_INO(1), SCR_CAN_INO(2), SCR_CAN_INO(3), SCR_CAN_INO(4),
    SCR_CAN_INO(5), SCR_CAN_INO(6), SCR_CAN_INO(7), SCR_CAN_INO(8),
    SCR_CAN_INO(9), SCR_CAN_INO(10), SCR_CAN_INO(11), SCR_CAN_INO(12),
    SCR_CAN_INO(13), SCR_CAN_INO(14), SCR_CAN_INO(15), SCR_CAN_INO(16),
    SCR_CAN_INO(17), SCR_CAN_INO(18), SCR_CAN_INO(19), SCR_CAN_INO(20),
    SCR_CAN_INO(21), SCR_CAN_INO(22), SCR_CAN_INO(23), SCR_CAN_INO(24)
};
#else
static const VAR(Can_ScrBitsType, CAN_VAR) g_CanScrinfo[CAN_MAX_CONTROLLER_CNT] =
{
    SCR_CAN_INO(16), SCR_CAN_INO(21), SCR_CAN_INO(3), SCR_CAN_INO(4),
    SCR_CAN_INO(5), SCR_CAN_INO(6), SCR_CAN_INO(7), SCR_CAN_INO(23),
};
#endif

/* DLC lookup table. */
CONST(uint8, AUTOMATIC) dlc_code[65] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U,
                                         /* 9 to 12 payload have DLC Code 12 Bytes */
                                         CAN_DLC_VALUE_12_BYTES, CAN_DLC_VALUE_12_BYTES, CAN_DLC_VALUE_12_BYTES, CAN_DLC_VALUE_12_BYTES,
                                         /* 13 to 16 payload have DLC Code 16 Bytes */
                                         CAN_DLC_VALUE_16_BYTES, CAN_DLC_VALUE_16_BYTES, CAN_DLC_VALUE_16_BYTES, CAN_DLC_VALUE_16_BYTES,
                                         /* 17 to 20 payload have DLC Code 20 Bytes */
                                         CAN_DLC_VALUE_20_BYTES, CAN_DLC_VALUE_20_BYTES, CAN_DLC_VALUE_20_BYTES, CAN_DLC_VALUE_20_BYTES,
                                         /* 21 to 24 payload have DLC Code 24 Bytes */
                                         CAN_DLC_VALUE_24_BYTES, CAN_DLC_VALUE_24_BYTES, CAN_DLC_VALUE_24_BYTES, CAN_DLC_VALUE_24_BYTES,
                                         /* 25 to 32 payload have DLC Code 32 Bytes */
                                         CAN_DLC_VALUE_32_BYTES, CAN_DLC_VALUE_32_BYTES, CAN_DLC_VALUE_32_BYTES, CAN_DLC_VALUE_32_BYTES,
                                         CAN_DLC_VALUE_32_BYTES, CAN_DLC_VALUE_32_BYTES, CAN_DLC_VALUE_32_BYTES, CAN_DLC_VALUE_32_BYTES,
                                         /* 33 to 48 payload have DLC Code 48 Bytes */
                                         CAN_DLC_VALUE_48_BYTES, CAN_DLC_VALUE_48_BYTES, CAN_DLC_VALUE_48_BYTES, CAN_DLC_VALUE_48_BYTES,
                                         CAN_DLC_VALUE_48_BYTES, CAN_DLC_VALUE_48_BYTES, CAN_DLC_VALUE_48_BYTES, CAN_DLC_VALUE_48_BYTES,
                                         CAN_DLC_VALUE_48_BYTES, CAN_DLC_VALUE_48_BYTES, CAN_DLC_VALUE_48_BYTES, CAN_DLC_VALUE_48_BYTES,
                                         CAN_DLC_VALUE_48_BYTES, CAN_DLC_VALUE_48_BYTES, CAN_DLC_VALUE_48_BYTES, CAN_DLC_VALUE_48_BYTES,
                                         /* 49 to 64 payload have DLC Code 64 Bytes */
                                         CAN_DLC_VALUE_64_BYTES, CAN_DLC_VALUE_64_BYTES, CAN_DLC_VALUE_64_BYTES, CAN_DLC_VALUE_64_BYTES,
                                         CAN_DLC_VALUE_64_BYTES, CAN_DLC_VALUE_64_BYTES, CAN_DLC_VALUE_64_BYTES, CAN_DLC_VALUE_64_BYTES,
                                         CAN_DLC_VALUE_64_BYTES, CAN_DLC_VALUE_64_BYTES, CAN_DLC_VALUE_64_BYTES, CAN_DLC_VALUE_64_BYTES,
                                         CAN_DLC_VALUE_64_BYTES, CAN_DLC_VALUE_64_BYTES, CAN_DLC_VALUE_64_BYTES, CAN_DLC_VALUE_64_BYTES
                                       };

#define CAN_STOP_SEC_CONST_UNSPECIFIED
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"

static FUNC(void, CAN_CODE) Can_IP_MemSet
(
    P2VAR(void, AUTOMATIC, CAN_APPL_DATA) Start,
    VAR(uint8, AUTOMATIC) Val,
    VAR(uint32, AUTOMATIC) Size
);

static FUNC(void, CAN_CODE) Can_IP_Reset
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr
);

static FUNC(void, CAN_CODE) Can_IP_Enable
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr
);

static FUNC(void, CAN_CODE) Can_IP_Disable
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr
);

static FUNC(void, CAN_CODE) Can_IP_FDClearSmbRegion
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr
);

static FUNC(Std_ReturnType, CAN_CODE) Can_IP_EnterFreezeMode
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr
);

static FUNC(Std_ReturnType, CAN_CODE) Can_IP_ExitFreezeMode
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr
);

static FUNC(Std_ReturnType, CAN_CODE) Can_IP_EnterStopMode
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr
);

static FUNC(Std_ReturnType, CAN_CODE) Can_IP_ExitStopMode
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr
);

static FUNC(void, CAN_CODE) Can_IP_BasicConfig
(
    VAR(uint8, AUTOMATIC) ControllerId
);

static FUNC(void, CAN_CODE) Can_IP_BaudRateConfig
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr,
    P2CONST(Can_BaudRateConfigType, AUTOMATIC, CAN_APPL_DATA) Config
);

static FUNC(void, CAN_CODE) Can_IP_MBConfig
(
    VAR(uint8, AUTOMATIC) ControllerId
);

#if (CAN_RXFIFO_SUPPORT == STD_ON)
static FUNC(void, CAN_CODE) Can_IP_RxFifoConfig
(
    VAR(uint8, AUTOMATIC) ControllerId
);
#endif

#if (CAN_RXFIFO_SUPPORT == STD_ON)
static FUNC(void, AUTOMATIC) Can_IP_ConfigRxFifoFilterNumber
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) ControllerBaseAddr,
    P2CONST(Can_RxFifoConfigType, AUTOMATIC, CAN_APPL_DATA) RxFIFOConfig
);
#endif

#if (CAN_RXFIFO_SUPPORT == STD_ON)
static FUNC(void, CAN_CODE) Can_IP_ConfigRxFifoFilterTable
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) ControllerBaseAddr,
    P2CONST(Can_RxFifoConfigType, AUTOMATIC, CAN_APPL_DATA) RxFIFOConfig
);
#endif

#if (CAN_RXFIFO_SUPPORT == STD_ON)
static FUNC(void, CAN_CODE) Can_IP_ConfigRxFifoGlobalMask
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) ControllerBaseAddr,
    P2CONST(Can_RxFifoConfigType, AUTOMATIC, CAN_APPL_DATA) RxFIFOConfig
);
#endif

#if (CAN_RXFIFO_SUPPORT == STD_ON)
LOCAL_INLINE FUNC(void, CAN_CODE) Can_IP_ClearRxFifoGlobalMask
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) ControllerBaseAddr
);
#endif

LOCAL_INLINE FUNC(boolean, CAN_CODE) Can_IP_IsFDEnabled
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr
);

LOCAL_INLINE FUNC(boolean, CAN_CODE) Can_IP_IsIndividualRxMaskEnabled
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr
);

LOCAL_INLINE FUNC(boolean, CAN_CODE) Can_IP_IsRxFIFOEnabled
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr
);

static FUNC_P2VAR(uint32, CAN_CODE, CAN_CODE) Can_IP_GetMBStartAddr
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr,
    VAR(uint8, AUTOMATIC) MBId
);

LOCAL_INLINE FUNC(void, CAN_CODE) Can_IP_ConfigIndividualRxMask
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr,
    VAR(uint8, AUTOMATIC) MBId, VAR(uint32, AUTOMATIC) FilterMask
);

static FUNC(void, CAN_CODE) Can_IP_ConfigRxMB
(
    P2VAR(uint32, AUTOMATIC, CAN_APPL_DATA) MBBaseAddr,
    VAR(Can_IdTypeType, AUTOMATIC) IdType,
    VAR(uint32, AUTOMATIC) FrameId
);

static FUNC(void, CAN_CODE) Can_IP_ConfigTxMB
(
    P2VAR(uint32, AUTOMATIC, CAN_APPL_DATA) MBBaseAddr
);

#if defined(CAN_LOW_POWER_SUPPORT)
LOCAL_INLINE FUNC(boolean, CAN_CODE) Can_IP_IsDozeModeEnabled
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr
);
#endif

static FUNC(Std_ReturnType, CAN_CODE) Can_IP_SetSleepRequest
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr
);

static FUNC(Std_ReturnType, CAN_CODE) Can_IP_ClearSleepRequest
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr
);

static FUNC(uint8, CAN_CODE) Can_IP_ComputeDLCVal
(
    VAR(uint8, AUTOMATIC) PayloadSize
);

static FUNC(uint8, CAN_CODE) Can_IP_ComputeMessageLen
(
    VAR(uint8, AUTOMATIC) DLCVal
);

static FUNC(Std_ReturnType, CAN_CODE) Can_IP_ReadRxMB
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr,
    VAR(uint8, AUTOMATIC) MBId,
    P2VAR(Can_RxFrameType, AUTOMATIC, CAN_APPL_DATA) frameBuffer
);

static FUNC(Std_ReturnType, CAN_CODE) Can_IP_WriteTxMB
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr,
    VAR(uint8, AUTOMATIC) MBId,
    VAR(Can_IdType, AUTOMATIC) CanId,
    VAR(uint8, AUTOMATIC) DataLength,
    P2VAR(uint8, AUTOMATIC, CAN_APPL_DATA) DataBuffer,
    VAR(uint8, AUTOMATIC)PaddingVal
);

static FUNC(Std_ReturnType, CAN_CODE) Can_IP_ReadRxFIFO
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr,
    P2VAR(Can_RxFrameType, AUTOMATIC, CAN_APPL_DATA) frameBuffer
);

LOCAL_INLINE FUNC(void, CAN_CODE) Can_IP_BusOffNotification
(
    VAR(uint8, AUTOMATIC) ControllerId
);

static FUNC(boolean, CAN_CODE) Can_IP_GetMBIntFlag
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr,
    VAR(uint8, AUTOMATIC) MBId
);

static FUNC(void, CAN_CODE) Can_IP_ClearMBIntFlag
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr,
    VAR(uint8, AUTOMATIC) MBId
);

LOCAL_INLINE FUNC(void, CAN_CODE) Can_IP_RxIndication
(
    VAR(uint8, AUTOMATIC) ControllerId,
    VAR(uint8, AUTOMATIC) MBId,
    P2VAR(Can_RxFrameType, AUTOMATIC, CAN_APPL_DATA) RxFrameBuffer
);

LOCAL_INLINE FUNC(void, CAN_CODE) Can_IP_TxConfirmation
(
    VAR(uint8, AUTOMATIC) ControllerId,
    VAR(uint8, AUTOMATIC) MBId
);
/**
 * @brief Initialize CAN controller.
 * @param ControllerId Controller ID.
 * @return Initialization result.
 *  @retval E_OK Initialize successfully.
 *  @retval E_NOT_OK Initialize failed.
 */
FUNC(Std_ReturnType, CAN_CODE) Can_IP_InitController
(
    VAR(uint8, AUTOMATIC) ControllerId
)
{
    /* Initialization result. */
    VAR(Std_ReturnType, AUTOMATIC) ret_result = E_OK;
    /* Pointer to the configuration of the controller. */
    P2CONST(Can_ControllerConfigType, AUTOMATIC,
          CAN_APPL_DATA) ctrllerCfg = &Can_pCurConfig->controllerConfig[ControllerId];
    /* Base address of memory mapped for the controller. */
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) regBase = (Can_RegType *)(
                unsigned long)ctrllerCfg->baseAddr;
    /* Variable used for indexing baud rate configuration array. */
    VAR(uint16, AUTOMATIC) baudRateIdx = 0U;
    /* Pointer to baud rate configuration. */
    P2CONST(Can_BaudRateConfigType, AUTOMATIC, CAN_APPL_DATA) baudRateCfg = NULL_PTR;
#if (CAN_FD_SUPPORT == STD_ON)
    /* Save current FDCTRL value. */
    VAR(uint32, AUTOMATIC) fdctrlTemp;
#endif

    /* (1) Initialize global variables. */
    /* PRQA S 0326 ++ */
    Can_IP_MemSet((void *)(unsigned long)&g_CanControllerInfo[ControllerId], 0U,
                  sizeof(Can_ControllerInfoType));
    /* Set the position of the first Tx polling MB to invalid value. */
    g_CanControllerInfo[ControllerId].firstTxPollingMBPos = 0xFFU;

    if (ctrllerCfg->busoffProcType == INTERRUPT)
    {
        g_CanControllerInfo[ControllerId].intMask.errIntMask |= FLEXCAN_BUSOFF_INT_ENABLE;
    }

    if (ctrllerCfg->wakeupProcType == INTERRUPT)
    {
        g_CanControllerInfo[ControllerId].intMask.wakeUpIntMask |= FLEXCAN_WAKEUP_INT_ENABLE;
    }

    /* (2) Execute soft reset, and set registers to known value. */
    Can_IP_Reset(regBase);

    /* (3) Protocol-Engine clock source selection, This bit must be set
     * when FlexCAN module in disable mode.
     */
    if ((ctrllerCfg->option & PE_CLOCK_FROM_OSC) != 0U)
    {
        regBase->CTRL1 &= ~CAN_CTRL1_CLKSRC_MASK;
    }
    else
    {
        regBase->CTRL1 |= CAN_CTRL1_CLKSRC_MASK;
    }

    /* (4) Enable FlexCAN module before configuration. */
    Can_IP_Enable(regBase);

    /* (5) Enter freeze mode. */
    ret_result = Can_IP_EnterFreezeMode(regBase);

    /* (6) Configure CAN basic features. */
    Can_IP_BasicConfig(ControllerId);

    /* (7) Configure baud rate. */
    for (baudRateIdx = 0; baudRateIdx < ctrllerCfg->baudRateConfigCount; baudRateIdx++)
    {
        baudRateCfg = &ctrllerCfg->baudRateConfig[baudRateIdx];

        if (baudRateCfg->baudRateConfigId == Can_gu16CurBaudRateConfigId[ControllerId])
        {
            Can_IP_BaudRateConfig(regBase, baudRateCfg);
            break;
        }
    }

#if (CAN_FD_SUPPORT == STD_ON)
    /* (8) Configure CAN FD MBDSRs. */
    fdctrlTemp = regBase->FDCTRL;
    fdctrlTemp &= ~(CAN_FDCTRL_MBDSR0_MASK | CAN_FDCTRL_MBDSR1_MASK);
    fdctrlTemp |= ctrllerCfg->mbdsrVal;
    regBase->FDCTRL = fdctrlTemp;
#endif

    /* (9) Configure MBs. */
    if (Can_pCurConfig->mbConfig != NULL_PTR)
    {
        Can_IP_MBConfig(ControllerId);
    }

    /* (10) Configure Rx FIFOs. */
#if (CAN_RXFIFO_SUPPORT == STD_ON)

    if (Can_pCurConfig->rxFifoConfig != NULL_PTR)
    {
        Can_IP_RxFifoConfig(ControllerId);
    }

#endif

    /* (11) unmask interrupt */
    if (Can_gu8ControllerIntsDisableCnt[ControllerId] == 0U)
    {
        Can_IP_EnableInterrupts(ControllerId);
    }

    /* (12) ERRATA: mask access reserved address(0xc) error */
    regBase->ERR_IRQ_STATUS_EN &= ~APB_PSLVERR_INT_STAT_EN_MASK;

    return ret_result;
}

/**
 * @brief De-initialize the controller.
 * @param ControllerId Controller ID.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_IP_DeInitController
(
    VAR(uint8, AUTOMATIC) ControllerId
)
{
    /* Base address of memory mapped for the controller. */
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) regBase = (Can_RegType *)(
                unsigned long)Can_pCurConfig->controllerConfig[ControllerId].baseAddr;
#if (defined(AUTOSAR_VERSION_421)) || (defined(AUTOSAR_VERSION_403))

    if (Can_gControllerState[ControllerId] == CAN_T_SLEEP)
    {
#else

    if (Can_gControllerState[ControllerId] == CAN_CS_SLEEP)
    {
#endif
        /* Clear sleep request. */
        (void)Can_IP_ClearSleepRequest(regBase);
    }

    Can_IP_Reset(regBase);
}

/**
 * @brief Set the controller mode to CAN_CS_STARTED.
 * @param ControllerId Controller ID.
 * @return Start mode setting result.
 *  @retval E_OK Set the controller mode to CAN_CS_STARTED successfully.
 *  @retval E_NOT_OK Set the controller mode to CAN_CS_STARTED failed.
 */
#if (defined(AUTOSAR_VERSION_421)) || (defined(AUTOSAR_VERSION_403))
FUNC(Std_ReturnType, CAN_CODE) Can_IP_SetStartMode
(
    VAR(uint8, AUTOMATIC) ControllerId
)
{
    /* Return value. */
    VAR(Std_ReturnType, AUTOMATIC) ret_result = E_NOT_OK;

    /* start to start */
    if (CAN_T_START == Can_gControllerState[ControllerId])
    {
        ret_result = E_OK;
    }
    else
    {
        /* stop to start */
        if (CAN_T_STOP == Can_gControllerState[ControllerId])
        {
            /*busoff occur, reinit controller */
            if (TRUE == g_eControllerBusoffState[ControllerId])
            {
                Can_IP_InitController(ControllerId);
                g_eControllerBusoffState[ControllerId] = FALSE;
            }

            ret_result = Can_IP_ExitFreezeMode((Can_RegType *)(unsigned long)
                                               Can_pCurConfig->controllerConfig[ControllerId].baseAddr);
        }

#if (CAN_DEV_ERROR_DETECT == STD_ON)
        else
        {
            (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_SET_CONTROLLER_MODE,
                                  CAN_E_TRANSITION);
        }

#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
    }

    return ret_result;
}
#elif (defined(AUTOSAR_VERSION_431))
FUNC(Std_ReturnType, CAN_CODE) Can_IP_SetStartMode
(
    VAR(uint8, AUTOMATIC) ControllerId
)
{
    /* Return value. */
    VAR(Std_ReturnType, AUTOMATIC) ret_result = E_NOT_OK;

    /* start to start */
    if (CAN_CS_STARTED == Can_gControllerState[ControllerId])
    {
        ret_result = E_OK;
    }
    else
    {
        /* stop to start */
        if (CAN_CS_STOPPED == Can_gControllerState[ControllerId])
        {
            /*busoff occur, reinit controller */
            if (TRUE == g_eControllerBusoffState[ControllerId])
            {
                Can_IP_InitController(ControllerId);
                g_eControllerBusoffState[ControllerId] = FALSE;
            }

            ret_result = Can_IP_ExitFreezeMode((Can_RegType *)(unsigned long)
                                               Can_pCurConfig->controllerConfig[ControllerId].baseAddr);
        }

#if (CAN_DEV_ERROR_DETECT == STD_ON)
        else
        {
            (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_SET_CONTROLLER_MODE,
                                  CAN_E_TRANSITION);
        }

#endif
    }

    return ret_result;
}
#endif

/**
 * @brief Set the controller mode to CAN_CS_SLEEP.
 * @param ControllerId Controller ID.
 * @return Sleep mode setting result.
 *  @retval E_OK Set the controller mode to CAN_CS_SLEEP successfully.
 *  @retval E_NOT_OK Set the controller mode to CAN_CS_SLEEP failed.
 */
#if (defined(AUTOSAR_VERSION_421)) || (defined(AUTOSAR_VERSION_403))
FUNC(Std_ReturnType, CAN_CODE) Can_IP_SetSleepMode
(
    VAR(uint8, AUTOMATIC) ControllerId
)
{
    /* Return value. */
    VAR(Std_ReturnType, AUTOMATIC) ret_result = E_NOT_OK;
    /* Base address of the controller. */
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) regBase = (Can_RegType *)
            Can_pCurConfig->controllerConfig[ControllerId].baseAddr;
    VAR(uint8, AUTOMATIC) basicCfg = Can_pCurConfig->controllerConfig[ControllerId].option;

    /* sleep to sleep */
    if (CAN_T_SLEEP == Can_gControllerState[ControllerId])
    {
        ret_result = E_OK;
    }
    else
    {
        /* stop to sleep */
        if (CAN_T_STOP == Can_gControllerState[ControllerId])
        {
            /* ERRATA: wakeup interrupt glitch error, Configure self wake-up. */
            if ((basicCfg & SELF_WAKE_UP_EN) != 0U)
            {
                regBase->MCR |= CAN_MCR_SLFWAK_MASK;
            }
            else
            {
                regBase->MCR &= ~CAN_MCR_SLFWAK_MASK;
            }
            ret_result = Can_IP_SetSleepRequest(regBase);
        }

#if (CAN_DEV_ERROR_DETECT == STD_ON)
        else
        {
            (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_SET_CONTROLLER_MODE,
                                  CAN_E_TRANSITION);
        }

#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
    }

    return ret_result;
}
#elif (defined(AUTOSAR_VERSION_431))
FUNC(Std_ReturnType, CAN_CODE) Can_IP_SetSleepMode
(
    VAR(uint8, AUTOMATIC) ControllerId
)
{
    /* Return value. */
    VAR(Std_ReturnType, AUTOMATIC) ret_result = E_NOT_OK;
    /* Base address of the controller. */
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) regBase = (Can_RegType *)
            Can_pCurConfig->controllerConfig[ControllerId].baseAddr;
    VAR(uint8, AUTOMATIC) basicCfg = Can_pCurConfig->controllerConfig[ControllerId].option;

    /* sleep to sleep */
    if (CAN_CS_SLEEP == Can_gControllerState[ControllerId])
    {
        ret_result = E_OK;
    }
    else
    {
        /* stop to sleep */
        if (CAN_CS_STOPPED == Can_gControllerState[ControllerId])
        {
            /* ERRATA: wakeup interrupt glitch error, Configure self wake-up. */
            if ((basicCfg & SELF_WAKE_UP_EN) != 0U)
            {
                regBase->MCR |= CAN_MCR_SLFWAK_MASK;
            }
            else
            {
                regBase->MCR &= ~CAN_MCR_SLFWAK_MASK;
            }
            ret_result = Can_IP_SetSleepRequest(regBase);
        }

#if (CAN_DEV_ERROR_DETECT == STD_ON)
        else
        {
            (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_SET_CONTROLLER_MODE,
                                  CAN_E_TRANSITION);
        }

#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
    }

    return ret_result;
}
#endif

/**
 * @brief Set the controller mode to CAN_CS_STOPPED.
 * @param ControllerId Controller ID.
 * @return Stop mode setting result.
 *  @retval E_OK Set the controller mode to CAN_CS_STOPPED successfully.
 *  @retval E_NOT_OK Set the controller mode to CAN_CS_STOPPED failed.
 */
#if (defined(AUTOSAR_VERSION_421)) || (defined(AUTOSAR_VERSION_403))
FUNC(Std_ReturnType, CAN_CODE) Can_IP_SetStopMode
(
    VAR(uint8, AUTOMATIC) ControllerId
)
{
    /* Return value. */
    VAR(Std_ReturnType, AUTOMATIC) ret_result = E_NOT_OK;

    /* stop to stop */
    if (CAN_T_STOP == Can_gControllerState[ControllerId])
    {
        ret_result = E_OK;
    }
    else
    {
        /* start to stop */
        if (CAN_T_START == Can_gControllerState[ControllerId])
        {
            ret_result = Can_IP_EnterFreezeMode((Can_RegType *)
                                                Can_pCurConfig->controllerConfig[ControllerId].baseAddr);
        }

#if (CAN_DEV_ERROR_DETECT == STD_ON)
        else
        {
            (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_SET_CONTROLLER_MODE,
                                  CAN_E_TRANSITION);
        }

#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
    }

    return ret_result;
}
#elif (defined(AUTOSAR_VERSION_431))
FUNC(Std_ReturnType, CAN_CODE) Can_IP_SetStopMode
(
    VAR(uint8, AUTOMATIC) ControllerId
)
{
    /* Return value. */
    VAR(Std_ReturnType, AUTOMATIC) ret_result = E_NOT_OK;

    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) regBase = (Can_RegType *)
            Can_pCurConfig->controllerConfig[ControllerId].baseAddr;

    /* still stop, do nothing */
    if (CAN_CS_STOPPED == Can_gControllerState[ControllerId])
    {
        ret_result = E_OK;
    }
    else
    {
        /* form start to stop */
        if (CAN_CS_STARTED == Can_gControllerState[ControllerId])
        {
            ret_result = Can_IP_EnterFreezeMode((Can_RegType *)
                                                Can_pCurConfig->controllerConfig[ControllerId].baseAddr);
        }
        else
        {
            /* from sleep to stop */
            if (CAN_CS_SLEEP == Can_gControllerState[ControllerId])
            {
                ret_result = Can_IP_ClearSleepRequest(regBase);

                if (E_OK == ret_result)
                {
                    ret_result = Can_IP_EnterFreezeMode((Can_RegType *)
                                                        Can_pCurConfig->controllerConfig[ControllerId].baseAddr);
                }
                else
                {
                    ret_result = E_NOT_OK;
                }
            }
            else
            {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_SET_CONTROLLER_MODE,
                                      CAN_E_TRANSITION);
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
            }
        }
    }

    return ret_result;
}
#endif

/**
 * @brief Set the controller mode to CAN_T_WAKEUP.
 * @param ControllerId Controller ID.
 * @return Sleep mode setting result.
 *  @retval E_OK Set the controller mode to CAN_CS_SLEEP successfully.
 *  @retval E_NOT_OK Set the controller mode to CAN_CS_SLEEP failed.
 */
#if (defined(AUTOSAR_VERSION_421)) || (defined(AUTOSAR_VERSION_403))
FUNC(Std_ReturnType, CAN_CODE) Can_IP_WakeUp
(
    VAR(uint8, AUTOMATIC) ControllerId
)
{
    /* Return value. */
    VAR(Std_ReturnType, AUTOMATIC) ret_result = E_NOT_OK;
    /* Base address of the controller. */
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) regBase = (Can_RegType *)
            Can_pCurConfig->controllerConfig[ControllerId].baseAddr;

    if (CAN_T_STOP == Can_gControllerState[ControllerId])
    {
        ret_result = E_OK;
    }
    else
    {
        if (CAN_T_SLEEP == Can_gControllerState[ControllerId])
        {
            ret_result = Can_IP_ClearSleepRequest(regBase);
        }

#if (CAN_DEV_ERROR_DETECT == STD_ON)
        else
        {
            (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_SET_CONTROLLER_MODE,
                                  CAN_E_TRANSITION);
        }

#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
    }

    return ret_result;
}
#endif


/**
 * @brief Disable all interupts of the controller.
 * @param ControllerId Controller ID.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_IP_DisableInterrupts
(
    VAR(uint8, AUTOMATIC) ControllerId
)
{
    /* Base address of the controller. */
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) controllerBaseAddr =
        (Can_RegType *)(unsigned long)Can_pCurConfig->controllerConfig[ControllerId].baseAddr;

    controllerBaseAddr->CTRL1 &= ~(FLEXCAN_BUSOFF_INT_ENABLE | FLEXCAN_ERROR_INT_ENABLE |
                                   FLEXCAN_RX_WARNING_INT_ENABLE | FLEXCAN_TX_WARNING_INT_ENABLE);
    controllerBaseAddr->MCR &= ~CAN_MCR_WAKMSK_MASK;
    controllerBaseAddr->IMASK1 = 0U;
    controllerBaseAddr->IMASK2 = 0U;
}

/**
 * @brief Enable all needed interrupts of the controller.
 * @param ControllerId Controller ID.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_IP_EnableInterrupts
(
    VAR(uint8, AUTOMATIC) ControllerId
)
{
    /* Base address of the controller. */
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) controllerBaseAddr =
        (Can_RegType *)(unsigned long)Can_pCurConfig->controllerConfig[ControllerId].baseAddr;
    /* Pointer to information of the controller. */
    P2VAR(Can_ControllerInfoType, AUTOMATIC,
          CAN_APPL_DATA) controllerInfo = &g_CanControllerInfo[ControllerId];

    controllerBaseAddr->CTRL1 |= controllerInfo->intMask.errIntMask;
    controllerBaseAddr->MCR |= controllerInfo->intMask.wakeUpIntMask;
    controllerBaseAddr->IMASK1 = controllerInfo->intMask.mb_0_31_IntMask;
    controllerBaseAddr->IMASK2 = controllerInfo->intMask.mb_32_63_IntMask;
}

/**
 * @brief Get error state of the controller.
 * @param ControllerId Controller ID.
 * @return error state.
 *  @retval CAN_ERRORSTATE_ACTIVE active error.
 *  @retval CAN_ERRORSTATE_PASSIVE passive error.
 *  @retval CAN_ERRORSTATE_BUSOFF bus off.
 */
FUNC(Can_ErrorStateType, CAN_CODE) Can_IP_GetErrorState
(
    VAR(uint8, AUTOMATIC) ControllerId
)
{
    /* Return value. */
    VAR(Can_ErrorStateType, AUTOMATIC) ret_result = CAN_ERRORSTATE_BUSOFF;
    /* ESR1 value. */
    VAR(uint32, AUTOMATIC) esr1Val = ((Can_RegType *)(unsigned long)
                                      Can_pCurConfig->controllerConfig[ControllerId].baseAddr)->ESR1;

    switch (esr1Val & CAN_ESR1_FLTCONF_MASK)
    {
    case CAN_ESR1_FLTCONF_ERROR_ACTIVE:
        ret_result = CAN_ERRORSTATE_ACTIVE;
        break;

    case CAN_ESR1_FLTCONF_ERROR_PASSIVE:
        ret_result = CAN_ERRORSTATE_PASSIVE;
        break;

    default:
        break;
    }

    return ret_result;
}

/**
 * @brief Transmit a CAN message.
 * @param Hth Hardware-transmit handle.
 * @param PduInfo Pointer to SDU user memory, data length and identifier.
 * @return API calling result.
 *  @retval E_OK Write CAN MB successfully.
 *  @retval E_NOT_OK Write CAN MB failed.
 */
FUNC(Std_ReturnType, CAN_CODE) Can_IP_Write
(
    VAR(Can_HwHandleType, AUTOMATIC) Hth,
    P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_DATA) PduInfo
)
{
    /* Return result. */
    VAR(Std_ReturnType, AUTOMATIC) ret_result = E_NOT_OK;
    /* Variable used for indexing Tx MBs. */
    VAR(uint16, AUTOMATIC) txMBIdx = 0U;
    /* Pointer to MB configuration. */
    P2CONST(Can_MBConfigType, AUTOMATIC, CAN_APPL_DATA) mbConfig = NULL_PTR;
    /* Variable to specify whether Hth is found in the MB configuration array. */
    VAR(boolean, AUTOMATIC) isHthFound = FALSE;
    /* Variable to specify whether CAN FD is enabled or not. */
    VAR(boolean, AUTOMATIC) isFDEnabled = FALSE;
    /* Variable used for recording controller ID. */
    VAR(uint8, AUTOMATIC) controllerId = 0U;
    /* Base address of the controller. */
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) baseAddr = NULL_PTR;
    /* Variable used for recording MB ID. */
    VAR(uint8, AUTOMATIC) mbId = 0U;
    /* Pointer to information of MB. */
    P2VAR(Can_MBInfoType, AUTOMATIC, CAN_APPL_DATA) mbInfo = NULL_PTR;
#if (CAN_TRIGGER_TRANSMIT_EN == STD_ON)
    /* Variable used as parameter when calling CanIf_TriggerTransmit. */
    VAR(PduInfoType, AUTOMATIC) triggerTxPduInfo;
    triggerTxPduInfo.SduDataPtr = NULL_PTR;
    triggerTxPduInfo.SduLength  = 0U;
#endif
    /* The length of data to be written. */
    VAR(uint8, AUTOMATIC) dataLen = 0U;

    for (txMBIdx = Can_pCurConfig->firstHthIndex; txMBIdx < CAN_MB_COUNT; txMBIdx++)
    {
        mbConfig = &Can_pCurConfig->mbConfig[txMBIdx];

        if (mbConfig->canObjId == Hth)
        {
            controllerId = mbConfig->controllerId;
            baseAddr = (Can_RegType *)(unsigned long)
                       Can_pCurConfig->controllerConfig[controllerId].baseAddr;
            mbId = mbConfig->mbId;
            mbInfo = &g_CanControllerInfo[controllerId].mbInfo[mbId];

            isHthFound = TRUE;

            isFDEnabled = Can_IP_IsFDEnabled((Can_RegType *)(unsigned long)
                                             Can_pCurConfig->controllerConfig[controllerId].baseAddr);

            if ((PduInfo->length > 64U) || (PduInfo->length > mbConfig->payloadSize) ||
                    ((PduInfo->length > 8U) && ((isFDEnabled == (boolean)FALSE) ||
                                                ((PduInfo->id & CAN_FD_ID_MASK) == 0U))))
            {
                ret_result = E_NOT_OK;
#if (CAN_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_WRITE,
                                      CAN_E_PARAM_DATA_LENGTH);
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
            }
            else
            {
                /* Enter exclusive access state. */
                SchM_Enter_Can_CAN_EXCLUSIVE_AREA_00();

                if (mbInfo->mbState == MB_IDLE)
                {
                    mbInfo->mbState = MB_BUSY;
                    /* Exit exclusive access state. */
                    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_00();
                    mbInfo->canIfPduId = PduInfo->swPduHandle;
                    dataLen = PduInfo->length;
#if (CAN_TRIGGER_TRANSMIT_EN == STD_ON)

                    if (PduInfo->sdu == NULL_PTR)
                    {
                        if (mbConfig->triggerTransmitEnable == (boolean)FALSE)
                        {
                            mbInfo->mbState = MB_IDLE;
                            ret_result = E_NOT_OK;
#if (CAN_DEV_ERROR_DETECT == STD_ON)
                            (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_WRITE,
                                                  CAN_E_PARAM_POINTER);
#endif
                        }
                        else
                        {
                            triggerTxPduInfo.SduDataPtr = mb_data_start_addr(Can_IP_GetMBStartAddr(baseAddr, mbId));
                            triggerTxPduInfo.SduLength = mbConfig->payloadSize;

                            if (E_OK != CanIf_TriggerTransmit(PduInfo->swPduHandle, &triggerTxPduInfo))
                            {
                                mbInfo->mbState = MB_IDLE;
                                ret_result = E_NOT_OK;
                            }
                            else
                            {
                                dataLen = (uint8)triggerTxPduInfo.SduLength;
                                ret_result = E_OK;
                            }
                        }
                    }
                    else
                    {
                        ret_result = E_OK;
                    }

                    if (ret_result == E_OK)
                    {
#endif /* CAN_TRIGGER_TRANSMIT_EN == STD_ON */
                        ret_result = Can_IP_WriteTxMB(baseAddr, mbId, PduInfo->id, dataLen,
                                                      PduInfo->sdu, mbConfig->fdPaddingVal);
#if (CAN_TRIGGER_TRANSMIT_EN == STD_ON)
                    }

#endif /* CAN_TRIGGER_TRANSMIT_EN == STD_ON */
                }
                else
                {
                    /* Exit exclusive access state. */
                    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_00();
                    ret_result = CAN_BUSY;
                }
            }


#if (CAN_MULTIPLEXED_TRANSMISSION == STD_ON)

            if (ret_result == E_OK)
            {
                break;
            }

#else /* CAN_MULTIPLEXED_TRANSMISSION = STD_OFF */
            break;
#endif /* CAN_MULTIPLEXED_TRANSMISSION == STD_ON */
        }
    }



    if (isHthFound == (boolean)FALSE)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_WRITE,
                              CAN_E_PARAM_HANDLE);
#endif
    }



    return ret_result;
}

#if (CAN_MULTIPLE_WRITE_PERIOD == STD_ON)
/**
 * @brief Polling of Tx MBs of the controller at the given period.
 * @param ControllerId Controller ID.
 * @param PeriodId Period ID.
 * @param MatchPeriod Whether match period or not.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_IP_TxPolling
(
    VAR(uint8, AUTOMATIC) ControllerId,
    VAR(uint8, AUTOMATIC) PeriodId,
    VAR(boolean, AUTOMATIC) MatchPeriod
)
#else
/**
 * @brief Polling of Tx MBs of the controller.
 * @param ControllerId Controller ID.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_IP_TxPolling
(
    VAR(uint8, AUTOMATIC) ControllerId
)
#endif
{
    /* Variable used for indexing polling MB position. */
    VAR(uint16, AUTOMATIC) pollingMBPosIdx = 0U;
    /* Pointer to controller information. */
    P2VAR(Can_ControllerInfoType, AUTOMATIC,
          CAN_APPL_DATA) controllerInfo = &g_CanControllerInfo[ControllerId];
    /* Base address of the controller. */
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) controllerBaseAddr = (Can_RegType *)(
                unsigned long)Can_pCurConfig->controllerConfig[ControllerId].baseAddr;
    /* Variable used for indexing MB configuration array. */
    VAR(uint16, AUTOMATIC) mbConfigIdx = 0U;
    /* MB ID. */
    VAR(uint8, AUTOMATIC) mbId = 0U;

    for (pollingMBPosIdx = controllerInfo->firstTxPollingMBPos;
            pollingMBPosIdx < controllerInfo->pollingMBNum;
            pollingMBPosIdx++)
    {
        mbConfigIdx = controllerInfo->pollingMBConfigIndex[pollingMBPosIdx];
        mbId = Can_pCurConfig->mbConfig[mbConfigIdx].mbId;
#if (CAN_MULTIPLE_WRITE_PERIOD == STD_ON)

        if ((MatchPeriod == (boolean)FALSE)
                || (Can_pCurConfig->mbConfig[mbConfigIdx].pollingPeriodId == PeriodId))
        {
#endif

            if ((boolean)TRUE == Can_IP_GetMBIntFlag(controllerBaseAddr, mbId))
            {
                g_CanControllerInfo[ControllerId].mbInfo[mbId].mbState = MB_IDLE;
                Can_IP_ClearMBIntFlag(controllerBaseAddr, mbId);
                Can_IP_TxConfirmation(ControllerId, mbId);
            }

#if (CAN_MULTIPLE_WRITE_PERIOD == STD_ON)
        }

#endif
    }
}

#if (CAN_MULTIPLE_READ_PERIOD == STD_ON)
/**
 * @brief Polling of Rx MBs or Rx FIFO of the controller at the given period.
 * @param ControllerId Controller ID.
 * @param PeriodId Period ID.
 * @param MatchPeriod Whether match period ID or not.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_IP_RxPolling
(
    VAR(uint8, AUTOMATIC) ControllerId,
    VAR(uint8, AUTOMATIC) PeriodId,
    VAR(boolean, AUTOMATIC) MatchPeriod
)
#else
/**
 * @brief Polling of Rx MBs or Rx FIFO of the controller.
 * @param ControllerId Controller ID.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_IP_RxPolling
(
    VAR(uint8, AUTOMATIC) ControllerId
)
#endif
{
    /* Variable used for indexing polling MB position. */
    VAR(uint16, AUTOMATIC) pollingMBPosIdx = 0U;
    /* Pointer to controller information. */
    P2VAR(Can_ControllerInfoType, AUTOMATIC,
          CAN_APPL_DATA) controllerInfo = &g_CanControllerInfo[ControllerId];
    /* Base address of the controller. */
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) controllerBaseAddr = (Can_RegType *)(
                unsigned long)Can_pCurConfig->controllerConfig[ControllerId].baseAddr;
    /* Variable used for indexing MB configuration array. */
    VAR(uint16, AUTOMATIC) mbConfigIdx = 0U;
    /* MB ID. */
    VAR(uint8, AUTOMATIC) mbId = 0U;
    /* Frame buffer. */
    VAR(Can_RxFrameType, AUTOMATIC) rxFrame = {0U};

    /* Rx MBs polling. */
    for (pollingMBPosIdx = 0U;
            pollingMBPosIdx < controllerInfo->firstTxPollingMBPos;
            pollingMBPosIdx++)
    {
        mbConfigIdx = controllerInfo->pollingMBConfigIndex[pollingMBPosIdx];
#if (CAN_MULTIPLE_READ_PERIOD == STD_ON)

        if ((MatchPeriod == (boolean)FALSE)
                || (Can_pCurConfig->mbConfig[mbConfigIdx].pollingPeriodId == PeriodId))
        {
#endif
            mbId = Can_pCurConfig->mbConfig[mbConfigIdx].mbId;

            if ((boolean)TRUE == Can_IP_GetMBIntFlag(controllerBaseAddr, mbId))
            {
                (void)Can_IP_ReadRxMB(controllerBaseAddr, mbId, &rxFrame);
                Can_IP_RxIndication(ControllerId, mbId, &rxFrame);
            }

#if (CAN_MULTIPLE_READ_PERIOD == STD_ON)
        }

#endif
    }

    /* Rx FIFO polling. */
#if (CAN_MULTIPLE_READ_PERIOD == STD_ON)

    if ((MatchPeriod == (boolean)FALSE) || (controllerInfo->rxFifoPollingPeriodId == PeriodId))
    {
#endif

        if (controllerInfo->rxFifoUsePolling == (boolean)TRUE)
        {
            while ((boolean)TRUE == Can_IP_GetMBIntFlag(controllerBaseAddr, RX_FIFO_OVERFLOW_MB_ID))
            {
                (void)Can_IP_ReadRxFIFO(controllerBaseAddr, &rxFrame);
                Can_IP_RxIndication(ControllerId, RX_FIFO_MB_ID, &rxFrame);
                Can_IP_ClearMBIntFlag(controllerBaseAddr, RX_FIFO_OVERFLOW_MB_ID);
                Can_IP_ClearMBIntFlag(controllerBaseAddr, RX_FIFO_ALMOST_FULL_MB_ID);
                Can_IP_ClearMBIntFlag(controllerBaseAddr, RX_FIFO_FRAME_AVL_MB_ID);
            }

            while ((boolean)TRUE == Can_IP_GetMBIntFlag(controllerBaseAddr, RX_FIFO_ALMOST_FULL_MB_ID))
            {
                (void)Can_IP_ReadRxFIFO(controllerBaseAddr, &rxFrame);
                Can_IP_RxIndication(ControllerId, RX_FIFO_MB_ID, &rxFrame);
                Can_IP_ClearMBIntFlag(controllerBaseAddr, RX_FIFO_ALMOST_FULL_MB_ID);
                Can_IP_ClearMBIntFlag(controllerBaseAddr, RX_FIFO_FRAME_AVL_MB_ID);
            }

            while ((boolean)TRUE == Can_IP_GetMBIntFlag(controllerBaseAddr, RX_FIFO_FRAME_AVL_MB_ID))
            {
                (void)Can_IP_ReadRxFIFO(controllerBaseAddr, &rxFrame);
                Can_IP_RxIndication(ControllerId, RX_FIFO_MB_ID, &rxFrame);
                Can_IP_ClearMBIntFlag(controllerBaseAddr, RX_FIFO_FRAME_AVL_MB_ID);
            }
        }

#if (CAN_MULTIPLE_READ_PERIOD == STD_ON)
    }

#endif
}

/**
 * @brief Polling of bus-off event.
 * @param none.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_IP_BusOffPolling
(
    VAR(uint8, AUTOMATIC) ControllerId
)
{
    /* Pointer to the base address of the controller. */
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) controllerBaseAddr = (Can_RegType *)(
                unsigned long)Can_pCurConfig->controllerConfig[ControllerId].baseAddr;
    /* ESR1 value. */
    VAR(uint32, AUTOMATIC) esr1Val = controllerBaseAddr->ESR1;

    if ((esr1Val & CAN_ESR1_BOFFINT_MASK) != 0U)
    {
        /* Clear bus-off interrupt flag. */
        controllerBaseAddr->ESR1 = CAN_ESR1_BOFFINT_MASK;
#if (defined(AUTOSAR_VERSION_421)) || (defined(AUTOSAR_VERSION_403))
        Can_gControllerState[ControllerId] = CAN_T_STOP;
#else
        Can_gControllerState[ControllerId] = CAN_CS_STOPPED;
#endif
        Can_IP_BusOffNotification(ControllerId);
    }
}

/**
 * @brief Polling of wake-up event.
 * @param none.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_IP_WakeUpPolling
(
    VAR(uint8, AUTOMATIC) ControllerId
)
{
    /* Pointer to the base address of the controller. */
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) controllerBaseAddr = (Can_RegType *)(
                unsigned long)Can_pCurConfig->controllerConfig[ControllerId].baseAddr;
    /* ESR1 value. */
    VAR(uint32, AUTOMATIC) esr1Val = controllerBaseAddr->ESR1;

    if ((esr1Val & CAN_ESR1_WAKINT_MASK) != 0U)
    {
        /* Clear bus-off interrupt flag. */
        controllerBaseAddr->ESR1 = CAN_ESR1_WAKINT_MASK;
        /* Clear sleep request. */
        (void)Can_IP_ClearSleepRequest(controllerBaseAddr);
        /* Controller state transits to STOPPED from SLEEP when waking up. */
#if (defined(AUTOSAR_VERSION_421)) || (defined(AUTOSAR_VERSION_403))
        Can_gControllerState[ControllerId] = CAN_T_STOP;
#else
        Can_gControllerState[ControllerId] = CAN_CS_STOPPED;
#endif
    }
}

/**
 * @brief Polling of controller mode transitions.
 * @param none.
 * @return none.
 */
#if (defined(AUTOSAR_VERSION_421)) || (defined(AUTOSAR_VERSION_403))
FUNC(void, CAN_CODE) Can_IP_ControllerModePolling
(
    VAR(uint8, AUTOMATIC) ControllerId
)
{
    /* Base address of the controller. */
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) controllerBaseAddr = (Can_RegType *)(
                unsigned long)Can_pCurConfig->controllerConfig[ControllerId].baseAddr;
    /* If the controller is not ready. */
    VAR(boolean, AUTOMATIC) controllerNotReady = ((controllerBaseAddr->MCR & CAN_MCR_NOTRDY_MASK) != 0U)
            ?
            (boolean)TRUE : (boolean)FALSE;

    if (Can_gControllerState[ControllerId] != CAN_T_SLEEP)
    {
        if ((controllerNotReady == (boolean)TRUE) && (Can_gControllerState[ControllerId] == CAN_T_START))
        {
            Can_gControllerState[ControllerId] = CAN_T_STOP;
            CanIf_ControllerModeIndication(ControllerId, CANIF_CS_STOPPED);
        }
        else if ((controllerNotReady == (boolean)FALSE)
                 && (Can_gControllerState[ControllerId] == CAN_T_STOP))
        {
            Can_gControllerState[ControllerId] = CAN_T_START;
            CanIf_ControllerModeIndication(ControllerId, CANIF_CS_STARTED);
        }
        else
        {
            /* Do nothing. */
        }
    }
}
#else
FUNC(void, CAN_CODE) Can_IP_ControllerModePolling
(
    VAR(uint8, AUTOMATIC) ControllerId
)
{
    /* Base address of the controller. */
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) controllerBaseAddr = (Can_RegType *)(
                unsigned long)Can_pCurConfig->controllerConfig[ControllerId].baseAddr;
    /* If the controller is not ready. */
    VAR(boolean, AUTOMATIC) controllerNotReady = ((controllerBaseAddr->MCR & CAN_MCR_NOTRDY_MASK) != 0U)
            ?
            (boolean)TRUE : (boolean)FALSE;

    if (Can_gControllerState[ControllerId] != CAN_CS_SLEEP)
    {
        if ((controllerNotReady == (boolean)TRUE)
                && (Can_gControllerState[ControllerId] == CAN_CS_STARTED))
        {
            Can_gControllerState[ControllerId] = CAN_CS_STOPPED;
            CanIf_ControllerModeIndication(ControllerId, CAN_CS_STOPPED);
        }
        else if ((controllerNotReady == (boolean)FALSE)
                 && (Can_gControllerState[ControllerId] == CAN_CS_STOPPED))
        {
            Can_gControllerState[ControllerId] = CAN_CS_STARTED;
            CanIf_ControllerModeIndication(ControllerId, CAN_CS_STARTED);
        }
        else
        {
            /* Do nothing. */
        }
    }
}
#endif
/**
 * @brief CAN ISR.
 * @param ControllerId Controller ID.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_IP_IrqHandler
(
    VAR(uint8, AUTOMATIC) ControllerId
)
{
    /* Pointer to controller configuration. */
    P2CONST(Can_ControllerConfigType, AUTOMATIC,
          CAN_APPL_DATA) controllerConfig = &Can_pCurConfig->controllerConfig[ControllerId];
    /* Pointer to the base address of the controller. */
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) controllerBaseAddr = (Can_RegType *)(
                unsigned long)controllerConfig->baseAddr;
    /* MCR value. */
    VAR(uint32, AUTOMATIC) mcrVal = controllerBaseAddr->MCR;
    /* CTRL1 value. */
    VAR(uint32, AUTOMATIC) ctrl1Val = controllerBaseAddr->CTRL1;
    /* ESR1 value. */
    VAR(uint32, AUTOMATIC) esr1Val = controllerBaseAddr->ESR1;
    /* ERR_IRQ_STATUS value. */
    VAR(uint32, AUTOMATIC) errStatus = controllerBaseAddr->ERR_IRQ_STATUS;
    /* Variable used for indexing MBs. */
    VAR(uint8, AUTOMATIC) mbIdx = 0U;
    /* Variable used to indicate whether MB interrupt flag is set. */
    VAR(boolean, AUTOMATIC) isMBIntSet = FALSE;
    /* Variable used to indicate whether MB interrupt is enabled. */
    VAR(boolean, AUTOMATIC) isMBIntEnabled = FALSE;
    /* Frame buffer. */
    VAR(Can_RxFrameType, AUTOMATIC) rxFrame = {0U};
    /* iFlag value. */
    VAR(uint32, AUTOMATIC) iFlag1Val, iFlag2Val;
    /* iMask value. */
    VAR(uint32, AUTOMATIC) iMask1Val, iMask2Val;

    /* FlexCAN error interrupt handling. */
    if (((esr1Val & CAN_ESR1_BOFFINT_MASK) != 0U) && ((ctrl1Val & CAN_CTRL1_BOFFMSK_MASK) != 0U))
    {
        /* Clear all error interrupt flags. */
        controllerBaseAddr->ESR1 = CAN_ESR1_BOFFINT_MASK | CAN_ESR1_TWRNINT_MASK |
                                   CAN_ESR1_RWRNINT_MASK | CAN_ESR1_ERRINT_FAST_MASK |
                                   CAN_ESR1_BOFFDONEINT_MASK;
#if (defined(AUTOSAR_VERSION_421)) || (defined(AUTOSAR_VERSION_403))
        Can_gControllerState[ControllerId] = CAN_T_STOP;
#else
        Can_gControllerState[ControllerId] = CAN_CS_STOPPED;
#endif
        Can_IP_BusOffNotification(ControllerId);
    }

    /* ERRATA: access to reserved address error */
    if (errStatus)
    {
        /* w1c clear */
        controllerBaseAddr->ERR_IRQ_STATUS = errStatus;
    }

    /* CAN wake-up interrupt handling. */
    if (((esr1Val & CAN_ESR1_WAKINT_MASK) != 0U) && ((mcrVal & CAN_MCR_WAKMSK_MASK) != 0U))
    {
        /* ERRATA: wakeup interrupt glitch error */
        /* Disable self wakeup feature */
        controllerBaseAddr->MCR &= ~CAN_MCR_SLFWAK_MASK;
        /* Clear wake-up interrupt flag. */
        controllerBaseAddr->ESR1 = CAN_ESR1_WAKINT_MASK;
        /* Clear sleep request. */
        (void)Can_IP_ClearSleepRequest(controllerBaseAddr);
        /* Controller state transits to STOPPED from SLEEP when waking up. */
#if (defined(AUTOSAR_VERSION_421)) || (defined(AUTOSAR_VERSION_403))
        Can_gControllerState[ControllerId] = CAN_T_STOP;
#else
        Can_gControllerState[ControllerId] = CAN_CS_STOPPED;
#endif
    }

    iFlag1Val = controllerBaseAddr->IFLAG1;
    iFlag2Val = controllerBaseAddr->IFLAG2;

    iMask1Val = controllerBaseAddr->IMASK1;
    iMask2Val = controllerBaseAddr->IMASK2;

    /* CAN TX/RX interrupt handing */
    if ((0U != (iFlag1Val & iMask1Val)) || (0U != (iFlag2Val & iMask2Val)))
    {
        for (mbIdx = 0U; mbIdx < controllerConfig->maxMBNum; mbIdx++)
        {
            /* Get the right physical MB ID */
            if (mbIdx <= 31U)
            {
                isMBIntSet = (boolean)((iFlag1Val >> mbIdx) & 1U);
                isMBIntEnabled = (boolean)((iMask1Val >> mbIdx) & 1U);
            }
            else if (mbIdx <= 63U)
            {
                isMBIntSet = (boolean)((iFlag2Val >> (mbIdx % 32U)) & 1U);
                isMBIntEnabled = (boolean)((iMask2Val >> (mbIdx % 32U)) & 1U);
            }
            else
            {
                /* not used */
            }

            if ((isMBIntSet == (boolean)TRUE) && (isMBIntEnabled == (boolean)TRUE))
            {
                if (((controllerConfig->option & RX_FIFO_EN) != 0U)
                        && (mbIdx >= RX_FIFO_FRAME_AVL_MB_ID) && (mbIdx <= RX_FIFO_OVERFLOW_MB_ID))
                {
                    while ((boolean)TRUE == Can_IP_GetMBIntFlag(controllerBaseAddr, mbIdx))
                    {
                        switch (1U << mbIdx)
                        {
                        case FLEXCAN_RX_FIFO_OVERFLOW_FLAG:
                            (void)Can_IP_ReadRxFIFO(controllerBaseAddr, &rxFrame);
                            break;

                        case FLEXCAN_RX_FIFO_WARNING_FLAG:
                            (void)Can_IP_ReadRxFIFO(controllerBaseAddr, &rxFrame);
                            break;

                        case FLEXCAN_RX_FIFO_FRAME_AVAILABLE_FLAG:
                            (void)Can_IP_ReadRxFIFO(controllerBaseAddr, &rxFrame);
                            break;

                        default:
                            break;
                        }

                        Can_IP_RxIndication(ControllerId, RX_FIFO_MB_ID, &rxFrame);

                        Can_IP_ClearMBIntFlag(controllerBaseAddr, RX_FIFO_FRAME_AVL_MB_ID);
                        Can_IP_ClearMBIntFlag(controllerBaseAddr, RX_FIFO_ALMOST_FULL_MB_ID);
                        Can_IP_ClearMBIntFlag(controllerBaseAddr, RX_FIFO_OVERFLOW_MB_ID);
                    }
                }
                else
                {
                    switch (g_CanControllerInfo[ControllerId].mbInfo[mbIdx].mbType)
                    {
                    case MB_RX:
                        (void)Can_IP_ReadRxMB(controllerBaseAddr, mbIdx, &rxFrame);
#if 0
                    if(0 == ControllerId)
                    {
                        uint32 counter = 0;
                        if(0x40000125 == rxFrame.id)
                        {
                            counter_0x125++;
                            counter = counter_0x125;
                            rxFrame.data[0]=(uint8)(counter >> 24);
                            rxFrame.data[1]=(uint8)(counter >> 16);
                            rxFrame.data[2]=(uint8)(counter >> 8);
                            rxFrame.data[3]=counter;
                        }
                        if(0x40000134 == rxFrame.id)
                        {
                            counter_0x134++;
                            counter = counter_0x134;
                            rxFrame.data[0]=(uint8)(counter >> 24);
                            rxFrame.data[1]=(uint8)(counter >> 16);
                            rxFrame.data[2]=(uint8)(counter >> 8);
                            rxFrame.data[3]=counter;
                        }
                        if(0x40000150 == rxFrame.id)
                        {
                            counter_0x150++;
                            counter = counter_0x150;
                            rxFrame.data[0]=(uint8)(counter >> 24);
                            rxFrame.data[1]=(uint8)(counter >> 16);
                            rxFrame.data[2]=(uint8)(counter >> 8);
                            rxFrame.data[3]=counter;
                        }
                        if(0x40000165 == rxFrame.id)
                        {
                            counter_0x165++;
                            counter = counter_0x165;
                            rxFrame.data[0]=(uint8)(counter >> 24);
                            rxFrame.data[1]=(uint8)(counter >> 16);
                            rxFrame.data[2]=(uint8)(counter >> 8);
                            rxFrame.data[3]=counter;
                        }
                        if(0x40000175 == rxFrame.id)
                        {
                            counter_0x175++;
                            counter = counter_0x175;
                            rxFrame.data[0]=(uint8)(counter >> 24);
                            rxFrame.data[1]=(uint8)(counter >> 16);
                            rxFrame.data[2]=(uint8)(counter >> 8);
                            rxFrame.data[3]=counter;
                        }
                        if(0x40000180 == rxFrame.id)
                        {
                            counter_0x180++;
                            counter = counter_0x180;
                            rxFrame.data[0]=(uint8)(counter >> 24);
                            rxFrame.data[1]=(uint8)(counter >> 16);
                            rxFrame.data[2]=(uint8)(counter >> 8);
                            rxFrame.data[3]=counter;
                        }
                        if(0x40000186 == rxFrame.id)
                        {
                            counter_0x186++;
                            counter = counter_0x186;
                            rxFrame.data[0]=(uint8)(counter >> 24);
                            rxFrame.data[1]=(uint8)(counter >> 16);
                            rxFrame.data[2]=(uint8)(counter >> 8);
                            rxFrame.data[3]=counter;
                        }
                        if(0x40000193 == rxFrame.id)
                        {
                            counter_0x193++;
                            counter = counter_0x193;
                            rxFrame.data[0]=(uint8)(counter >> 24);
                            rxFrame.data[1]=(uint8)(counter >> 16);
                            rxFrame.data[2]=(uint8)(counter >> 8);
                            rxFrame.data[3]=counter;
                        }
                        if(0x400002B8 == rxFrame.id)
                        {
                            counter_0x2B8++;
                            counter = counter_0x2B8;
                            rxFrame.data[0]=(uint8)(counter >> 24);
                            rxFrame.data[1]=(uint8)(counter >> 16);
                            rxFrame.data[2]=(uint8)(counter >> 8);
                            rxFrame.data[3]=counter;
                        }
                        if(0x400002BE == rxFrame.id)
                        {
                            counter_0x2BE++;
                            counter = counter_0x2BE;
                            rxFrame.data[0]=(uint8)(counter >> 24);
                            rxFrame.data[1]=(uint8)(counter >> 16);
                            rxFrame.data[2]=(uint8)(counter >> 8);
                            rxFrame.data[3]=counter;
                        }
                        if(0x400002BF == rxFrame.id)
                        {
                            counter_0x2BF++;
                            counter = counter_0x2BF;
                            rxFrame.data[0]=(uint8)(counter >> 24);
                            rxFrame.data[1]=(uint8)(counter >> 16);
                            rxFrame.data[2]=(uint8)(counter >> 8);
                            rxFrame.data[3]=counter;
                        }
                        if(0x400002C1 == rxFrame.id)
                        {
                            counter_0x2C1++;
                            counter = counter_0x2C1;
                            rxFrame.data[0]=(uint8)(counter >> 24);
                            rxFrame.data[1]=(uint8)(counter >> 16);
                            rxFrame.data[2]=(uint8)(counter >> 8);
                            rxFrame.data[3]=counter;
                        }
                    }
 #endif
                        Can_IP_RxIndication(ControllerId, mbIdx, &rxFrame);
                        break;

                    case MB_TX:
                        g_CanControllerInfo[ControllerId].mbInfo[mbIdx].mbState = MB_IDLE;
                        Can_IP_ClearMBIntFlag(controllerBaseAddr, mbIdx);
                        Can_IP_TxConfirmation(ControllerId, mbIdx);
                        break;

                    default:
                        break;
                    }
                }
            }
        }
    }
}

/*#############################Internal function definitions#############################*/
static FUNC(void, CAN_CODE) Can_IP_MemSet
(
    P2VAR(void, AUTOMATIC, CAN_APPL_DATA) Start,
    VAR(uint8, AUTOMATIC) Val,
    VAR(uint32, AUTOMATIC) Size
)
{
    /* Index memory to be set. */
    VAR(uint32, AUTOMATIC) index = 0U;
    /* Base address of memory to be set. */
    P2VAR(uint8, AUTOMATIC, CAN_APPL_DATA) addr = (uint8 *)Start;
    /* Length of memory has been written. */
    VAR(uint32, AUTOMATIC) write_len = 0U;

    for (index = 0U; index < Size / 4U; index++)
    {
        /*PRQA S 3305 2*/
        *((uint32 *)addr) = (Val << 24) | (Val << 16) |
                            (Val << 8) | Val;
        addr += 4U;
        write_len += 4U;
    }

    if (write_len < Size)
    {
        for (index = 0U; index < (Size - write_len); index++)
        {
            *addr = Val;
            addr++;
        }
    }
}

static FUNC(void, CAN_CODE) Can_IP_Reset
(
    VAR(Can_RegType *, AUTOMATIC) BaseAddr
)
{
    volatile uint32 tms = 0;

    /* Variable used for MB indexing. */
    VAR(uint8, AUTOMATIC) mb_idx = 0U;


    /* The module must first exit from low power
     * mode, and then soft reset can be applied.
     */
    BaseAddr->LOWPOWER_MODE = 0x1u;

    /* operate soft reset of SemidDrive enhancements. */
    BaseAddr->SOFT_RESET = 0x0;

    BaseAddr->MCR &= ~CAN_MCR_MDIS_MASK;
#if FLEXCAN_HAS_DOZE_MODE
    BaseAddr->MCR &= ~CAN_MCR_DOZE_MASK;
#endif

    /* Wait until FlexCAN exit from any Low Power Mode. */
    while (((BaseAddr->MCR & CAN_MCR_LPMACK_MASK) != 0U) && (tms < FLEXCAN_TIMEOUT_CNT))
    {
        /* timeout processing. */
        tms++;
    }

#if (CAN_DEV_ERROR_DETECT == STD_ON)

    if (tms >= FLEXCAN_TIMEOUT_CNT)
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_IP_RESET,
                              CAN_E_INIT_FAILED);
    }

#endif /* CAN_DEV_ERROR_DETECT == STD_ON */

    /* Assert Soft Reset Signal. */
    BaseAddr->MCR |= CAN_MCR_SOFTRST_MASK;

    /* Wait until FlexCAN reset completes. */
    tms = 0;

    while (((BaseAddr->MCR & CAN_MCR_SOFTRST_MASK) != 0U) && (tms < FLEXCAN_TIMEOUT_CNT))
    {
        /* timeout processing. */
        tms++;
    }

#if (CAN_DEV_ERROR_DETECT == STD_ON)

    if (tms >= FLEXCAN_TIMEOUT_CNT)
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_IP_RESET,
                              CAN_E_INIT_FAILED);
    }

#endif /* CAN_DEV_ERROR_DETECT == STD_ON */

    /* Reset MCR rigister. */
#if FLEXCAN_HAS_WAKEUP_SOURCE_FILTER
    BaseAddr->MCR |= CAN_MCR_WRNEN_MASK | CAN_MCR_WAKSRC_MASK
                     | CAN_MCR_MAXMB(FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBER - 1U);
#else
    BaseAddr->MCR |= CAN_MCR_WRNEN_MASK
                     | CAN_MCR_MAXMB(FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBER - 1U);
#endif

    /* Reset CTRL1 and CTRL2 rigister. */
    BaseAddr->CTRL1 = 0U;
    BaseAddr->CTRL2 = CAN_CTRL2_TASD(0x16) | CAN_CTRL2_RRS_MASK |
                      CAN_CTRL2_EACEN_MASK;

    /* Enable unrestricted write access to FlexCAN memory. */
    BaseAddr->CTRL2 |= CAN_CTRL2_WRMFRZ_MASK;

    for (mb_idx = 0; mb_idx < FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBER; mb_idx++)
    {
        /* Clean all individual Rx Mask of Message Buffers. */
        BaseAddr->RXIMR[mb_idx] = 0xFFFFFFFFU;
        /* Clean Message Buffer region. */
        BaseAddr->MB[mb_idx].CS = 0x0U;
        BaseAddr->MB[mb_idx].ID = 0x0U;
        BaseAddr->MB[mb_idx].WORD0 = 0x0U;
        BaseAddr->MB[mb_idx].WORD1 = 0x0U;
    }

    /* avoid ecc error, clean reserved area 96Byte */
    for (uint8 i = 0; i < 24; i++)
    {
        *(((uint32 *)&BaseAddr->RESERVED_4[0]) + i) = 0x0U;
    }

    /*  IP behavior:global mask value must be set after the "RESERVED_4" area cleaned, */
    /* Set Global Mask of Message Buffers.  */
    BaseAddr->RXMGMASK = 0xBFFFFFFFU;
    /* Set Global Mask of Message Buffer 14. */
    BaseAddr->RX14MASK = 0xBFFFFFFFU;
    /* Set Global Mask of Message Buffer 15. */
    BaseAddr->RX15MASK = 0xBFFFFFFFU;
    /* Set Global Mask of Rx FIFO. */
    BaseAddr->RXFGMASK = 0xFFFFFFFFU;

    /* Reset FDCTRL register. */
    BaseAddr->FDCTRL = 0x80000000U;

    /* Clean CAN FD SMB region. */
    Can_IP_FDClearSmbRegion(BaseAddr);

    /* Enable write access restriction. */
    BaseAddr->CTRL2 &= ~CAN_CTRL2_WRMFRZ_MASK;

    /* Disable FlexCAN. */
    Can_IP_Disable(BaseAddr);
}

static FUNC(void, CAN_CODE) Can_IP_Enable
(
    VAR(Can_RegType *, AUTOMATIC) BaseAddr
)
{
    volatile uint32 tms = 0;
    BaseAddr->MCR &= ~CAN_MCR_MDIS_MASK;

    /* Wait FlexCAN exit from low-power mode. */
    while (((BaseAddr->MCR & CAN_MCR_LPMACK_MASK) != 0U) && (tms < FLEXCAN_TIMEOUT_CNT))
    {
        /* timeout processing. */
        tms++;
    }

#if (CAN_DEV_ERROR_DETECT == STD_ON)

    if (tms >= FLEXCAN_TIMEOUT_CNT)
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_IP_ENABLE,
                              CAN_E_TRANSITION);
    }

#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
}

static FUNC(void, CAN_CODE) Can_IP_Disable
(
    VAR(Can_RegType *, AUTOMATIC) BaseAddr
)
{
    volatile uint32 tms = 0;
    BaseAddr->MCR |= CAN_MCR_MDIS_MASK;

    /* Wait FlexCAN enter low-power mode. */
    while (((BaseAddr->MCR & CAN_MCR_LPMACK_MASK) == 0U) && (tms < FLEXCAN_TIMEOUT_CNT))
    {
        /* timeout processing. */
        tms++;
    }

#if (CAN_DEV_ERROR_DETECT == STD_ON)

    if (tms >= FLEXCAN_TIMEOUT_CNT)
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_IP_DISABLE,
                              CAN_E_TRANSITION);
    }

#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
}

static FUNC(void, CAN_CODE) Can_IP_FDClearSmbRegion
(
    VAR(Can_RegType *, AUTOMATIC) BaseAddr
)
{
    /* CAN FD SMB region offset. */
    VAR(uint16, AUTOMATIC) start = CAN_FD_SMB_START_ADDR_OFFSET;

    /* Clear CAN FD SMB region to avoid non-correctable errors. */
    while (start < CAN_FD_SMB_END_ADDR_OFFSET)
    {
        *((uint32 *)(unsigned long)((uint8 *)BaseAddr + start)) = 0U;
        start += 4U;
    }
}

static FUNC(Std_ReturnType, CAN_CODE) Can_IP_EnterFreezeMode
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr
)
{
    Std_ReturnType ret = E_OK;
    volatile uint32 tms = 0;

    /* Set Freeze, Halt bits. */
    if ((BaseAddr->MCR & CAN_MCR_FRZ_MASK) == 0)
    {
        BaseAddr->MCR |= CAN_MCR_FRZ_MASK | CAN_MCR_HALT_MASK;

        /* Wait until the FlexCAN Module enter freeze mode. */
        while (((BaseAddr->MCR & CAN_MCR_FRZACK_MASK) == 0U) && (tms < FLEXCAN_TIMEOUT_CNT))
        {
            /* timeout processing. */
            tms++;
        }

        if (tms >= FLEXCAN_TIMEOUT_CNT)
        {
            ret = E_NOT_OK;
        }
    }
    else
    {
        /* Do nothing */
    }

    return ret;
}

static FUNC(Std_ReturnType, CAN_CODE) Can_IP_ExitFreezeMode
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr
)
{
    Std_ReturnType ret = E_OK;
    volatile uint32 tms = 0;

    if ((BaseAddr->MCR & CAN_MCR_FRZ_MASK) != 0U)
    {
        /* Clear Freeze, Halt bits. */
        BaseAddr->MCR &= ~(CAN_MCR_FRZ_MASK | CAN_MCR_HALT_MASK);

        /* Wait until the FlexCAN Module exit freeze mode. */
        while (((BaseAddr->MCR & CAN_MCR_FRZACK_MASK) != 0U) && (tms < FLEXCAN_TIMEOUT_CNT))
        {
            /* timeout processing. */
            tms++;
        }

        if (tms >= FLEXCAN_TIMEOUT_CNT)
        {
            ret = E_NOT_OK;
        }
    }
    else
    {
        /* Do nothing */
    }

    return ret;
}

static FUNC(Std_ReturnType, CAN_CODE) Can_IP_EnterStopMode
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr
)
{
    Std_ReturnType ret_result = E_OK;
    /* Variable used for indexing SCR information. */
    VAR(uint8, AUTOMATIC) idx = 0U;
    volatile uint32 tms = 0;

    for (idx = 0; idx < CAN_MAX_CONTROLLER_CNT; idx++)
    {
        if ((Can_RegType *)g_CanScrinfo[idx].can_addr == BaseAddr)
        {
            break;
        }
    }

    /* 0:stop 1:doze */
    if ((boolean)TRUE == Can_IP_IsDozeModeEnabled(BaseAddr))
    {
        Mcu_ScrSetBit(&g_CanScrinfo[idx].can_scr, 1U);
    }
    else
    {
        Mcu_ScrSetBit(&g_CanScrinfo[idx].can_scr, 0U);
    }

    BaseAddr->LOWPOWER_MODE = 0x3u;

    while ((!(BaseAddr->MCR & CAN_MCR_LPMACK_MASK)) && (tms < FLEXCAN_TIMEOUT_CNT))
    {
        /* timeout processing. */
        tms++;
    }

    if (tms >= FLEXCAN_TIMEOUT_CNT)
    {
        ret_result = E_NOT_OK;
    }

    return ret_result;
}

static FUNC(Std_ReturnType, CAN_CODE) Can_IP_ExitStopMode
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr
)
{
    Std_ReturnType ret_result = E_OK;
    /* Variable used for indexing SCR information. */
    volatile uint32 tms = 0;

    BaseAddr->LOWPOWER_MODE = 0x1u;

    while ((!!(BaseAddr->MCR & CAN_MCR_LPMACK_MASK)) && (tms < FLEXCAN_TIMEOUT_CNT))
    {
        /* timeout processing. */
        tms++;
    }

    if (tms >= FLEXCAN_TIMEOUT_CNT)
    {
        ret_result = E_NOT_OK;
    }

    return ret_result;
}

static FUNC(void, CAN_CODE) Can_IP_BasicConfig
(
    VAR(uint8, AUTOMATIC) ControllerId
)
{
    /* Pointer to configuration of the controller. */
    P2CONST(Can_ControllerConfigType, AUTOMATIC,
          CAN_APPL_DATA) controllerConfig = &Can_pCurConfig->controllerConfig[ControllerId];
    /* Base address of memory mapped for the controller. */
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) regBase = (Can_RegType *)(
                unsigned long)controllerConfig->baseAddr;
    /* Save current CTRL1 value. */
    VAR(uint32, AUTOMATIC) ctrl1Temp = regBase->CTRL1;
    /* Save current MCR value. */
    VAR(uint32, AUTOMATIC) mcrTemp = regBase->MCR;
    /* Basic configuration. */
    VAR(uint8, AUTOMATIC) basicCfg = controllerConfig->option;

    /* Disable automatic recovering from Bus Off state according to AutoSAR specification. */
    ctrl1Temp |= CAN_CTRL1_BOFFREC_MASK;

    /* Configure maxium MB number. */
    mcrTemp = (mcrTemp & ~CAN_MCR_MAXMB_MASK) | CAN_MCR_MAXMB((uint32)controllerConfig->maxMBNum - 1U);

    /* Configure Loop-back/Listen-only mode. */
    if ((basicCfg & LOOP_BACK_EN) != 0U)
    {
        ctrl1Temp &= ~CAN_CTRL1_LOM_MASK;
        ctrl1Temp |= CAN_CTRL1_LPB_MASK;
        mcrTemp &= ~CAN_MCR_SRXDIS_MASK;
    }
    else
    {
        ctrl1Temp &= ~CAN_CTRL1_LPB_MASK;
        mcrTemp |= CAN_MCR_SRXDIS_MASK;

        if ((basicCfg & LISTEN_ONLY_EN) != 0U)
        {
            ctrl1Temp |= CAN_CTRL1_LOM_MASK;
        }
        else
        {
            ctrl1Temp &= ~CAN_CTRL1_LOM_MASK;
        }
    }

    /* Configure individual Rx mask. */
    if ((basicCfg & INDIVIDUAL_RX_MASK_EN) != 0U)
    {
        mcrTemp |= CAN_MCR_IRMQ_MASK;
    }
    else
    {
        mcrTemp &= ~CAN_MCR_IRMQ_MASK;
    }

#if FLEXCAN_HAS_DOZE_MODE

    /* Configure doze mode. */
    if ((basicCfg & DOZE_MODE_EN) != 0U)
    {
        mcrTemp |= CAN_MCR_DOZE_MASK;
    }
    else
    {
        mcrTemp &= ~CAN_MCR_DOZE_MASK;
    }

#endif

    /* Configure Rx FIFO. When CAN FD is enabled, RFEN can not be set. */
    if (((basicCfg & RX_FIFO_EN) != 0U)
#if (CAN_FD_SUPPORT == STD_ON)
            && ((controllerConfig->
                 baudRateConfig[Can_gu16CurBaudRateConfigId[ControllerId]].fdConfig.option
                 & CAN_FD_EN) == 0U)
#endif
       )
    {
        /* Enable Rx FIFO. */
        mcrTemp |= CAN_MCR_RFEN_MASK;
        /* Configure Rx FIFO filter table format. */
        mcrTemp |= (mcrTemp & (~CAN_MCR_IDAM_MASK)) | CAN_MCR_IDAM(
                       controllerConfig->rxFifoFilterTableFormat);
    }
    else
    {
        /* Disable Rx FIFO. */
        mcrTemp &= ~CAN_MCR_RFEN_MASK;
    }

    /* Configure MB priority arbitration. */
    if ((basicCfg & LOWEST_NUM_MB_FISRT_EN) != 0U)
    {
        ctrl1Temp |= CAN_CTRL1_LBUF_MASK;
    }
    else
    {
        ctrl1Temp &= ~CAN_CTRL1_LBUF_MASK;
    }

    /* Configure MB reception priority. */
    regBase->CTRL2 = (regBase->CTRL2 & (~CAN_CTRL2_MRP_MASK)) | CAN_CTRL2_MRP(
                         controllerConfig->mbPriority);

    /* Save CTRL1 configuration. */
    regBase->CTRL1 = ctrl1Temp;
    /* Save MCR configuation. */
    regBase->MCR = mcrTemp;
}

static FUNC(void, CAN_CODE) Can_IP_BaudRateConfig
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr,
    P2CONST(Can_BaudRateConfigType, AUTOMATIC, CAN_APPL_DATA) Config
)
{
    /* Variable used for saving current CBT value. */
    VAR(uint32, AUTOMATIC) cbtTemp = 0U;
#if (CAN_FD_SUPPORT == STD_ON)
    /* Pointer to CAN FD configuration. */
    P2CONST(Can_FDConfigType, AUTOMATIC, CAN_APPL_DATA) canFdCfg = &Config->fdConfig;
    /* Variable used for saving current FDCBT value. */
    VAR(uint32, AUTOMATIC) fdcbtTemp = 0U;
    /* Variable used for saving current FDCTRL value. */
    VAR(uint32, AUTOMATIC) fdctrlTemp = 0U;
#endif /* CAN_FD_SUPPORT == STD_ON */
    /* Variable used for saving current CTRL1 value. */
    VAR(uint32, AUTOMATIC) ctrl1Temp = 0U;

#if (CAN_FD_SUPPORT == STD_ON)

    if ((canFdCfg->option & CAN_FD_EN) != 0U)
    {
        BaseAddr->MCR |= CAN_MCR_FDEN_MASK;
        /* Configure arbitration phase baud rate. */
        cbtTemp = BaseAddr->CBT;
        cbtTemp &= ~(CAN_CBT_EPRESDIV_MASK | CAN_CBT_ERJW_MASK |
                     CAN_CBT_EPSEG1_MASK | CAN_CBT_EPSEG2_MASK |
                     CAN_CBT_EPROPSEG_MASK);
        cbtTemp |= CAN_CBT_BTF(1U) |  /* Use CBT instead of CTRL1. */
                   Config->nominalBitTimingRegAlt;
        BaseAddr->CBT = cbtTemp;
        /* Configure data phase baud rate. */
        fdcbtTemp = BaseAddr->FDCBT;
        fdcbtTemp &= ~(CAN_FDCBT_FPRESDIV_MASK | CAN_FDCBT_FRJW_MASK |
                       CAN_FDCBT_FPSEG1_MASK | CAN_FDCBT_FPSEG2_MASK |
                       CAN_FDCBT_FPROPSEG_MASK);
        fdcbtTemp |= canFdCfg->dataBitTimingRegAlt;
        BaseAddr->FDCBT = fdcbtTemp;

        /* Configure CAN FD features. */
        if ((canFdCfg->option & ISO_CAN_FD_EN) != 0U)
        {
            BaseAddr->CTRL2 |= CAN_CTRL2_ISOCANFDEN_MASK;
        }
        else
        {
            BaseAddr->CTRL2 &= ~CAN_CTRL2_ISOCANFDEN_MASK;
        }

        fdctrlTemp = BaseAddr->FDCTRL;

        if ((canFdCfg->option & TX_BRS_EN) != 0U)
        {
            fdctrlTemp |= CAN_FDCTRL_FDRATE_MASK;
        }
        else
        {
            fdctrlTemp &= ~CAN_FDCTRL_FDRATE_MASK;
        }

        if (canFdCfg->tdcOffset != 0U)
        {
            fdctrlTemp |= CAN_FDCTRL_TDCEN_MASK;
            /* Set TDC offset. */
            fdctrlTemp &= ~CAN_FDCTRL_TDCOFF_MASK;
            fdctrlTemp |= CAN_FDCTRL_TDCOFF(canFdCfg->tdcOffset);
        }
        else
        {
            fdctrlTemp &= ~CAN_FDCTRL_TDCEN_MASK;
        }

        BaseAddr->FDCTRL = fdctrlTemp;
    }
    else
    {
#endif /* CAN_FD_SUPPORT == STD_ON */

        if (Config->extendBitTimingFormat != 0)
        {
            /* Configure arbitration phase baud rate. */
            cbtTemp = BaseAddr->CBT;
            cbtTemp &= ~(CAN_CBT_EPRESDIV_MASK | CAN_CBT_ERJW_MASK |
                         CAN_CBT_EPSEG1_MASK | CAN_CBT_EPSEG2_MASK |
                         CAN_CBT_EPROPSEG_MASK);
            cbtTemp |= CAN_CBT_BTF(1U) |  /* Use CBT instead of CTRL1. */
                       Config->nominalBitTimingRegAlt;
            BaseAddr->CBT = cbtTemp;
        }
        else
        {
            BaseAddr->CBT &= ~CAN_CBT_BTF_MASK;
            ctrl1Temp = BaseAddr->CTRL1;
            ctrl1Temp &= ~(CAN_CTRL1_PRESDIV_MASK | CAN_CTRL1_RJW_MASK |
                           CAN_CTRL1_PSEG1_MASK | CAN_CTRL1_PSEG2_MASK |
                           CAN_CTRL1_PROPSEG_MASK);
            ctrl1Temp |= Config->nominalBitTimingRegAlt;
            BaseAddr->CTRL1 = ctrl1Temp;
        }

#if (CAN_FD_SUPPORT == STD_ON)
    }

#endif /* CAN_FD_SUPPORT == STD_ON */
}

static FUNC(void, CAN_CODE) Can_IP_MBConfig
(
    VAR(uint8, AUTOMATIC) ControllerId
)
{
    /* Variable used for indexing MB configuration array. */
    VAR(uint16, AUTOMATIC) mbCfgIdx = 0U;
    /* Pointer to the start address of the controller. */
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) ctrllerBaseAddr = (Can_RegType *)(
                unsigned long)Can_pCurConfig->controllerConfig[ControllerId].baseAddr;
    /* Pointer to each MB configuration. */
    P2CONST(Can_MBConfigType, AUTOMATIC, CAN_APPL_DATA) mbCfg = NULL_PTR;
    /* Variable used for recording MB ID. */
    VAR(uint8, AUTOMATIC) mbId = 0U;
    /* Pointer to the start address of MB. */
    P2VAR(uint32, AUTOMATIC, CAN_APPL_DATA) mbStartAddr = NULL_PTR;
    /* Pointer to information of the controller. */
    P2VAR(Can_ControllerInfoType, AUTOMATIC, CAN_APPL_DATA) controllerInfo = NULL_PTR;

    /* Configure all configured MBs of the controller. */
    for (mbCfgIdx = 0U; mbCfgIdx < CAN_MB_COUNT; mbCfgIdx++)
    {
        mbCfg = &Can_pCurConfig->mbConfig[mbCfgIdx];

        if (mbCfg->controllerId == ControllerId)
        {
            mbId = mbCfg->mbId;
            mbStartAddr = Can_IP_GetMBStartAddr(ctrllerBaseAddr, mbId);
            controllerInfo = &g_CanControllerInfo[ControllerId];

            if (mbCfg->hohType == RECEIVE)
            {
                if ((boolean)TRUE == Can_IP_IsIndividualRxMaskEnabled(ctrllerBaseAddr))
                {
                    Can_IP_ConfigIndividualRxMask(ctrllerBaseAddr, mbId, mbCfg->filterMask);
                }

                Can_IP_ConfigRxMB(mbStartAddr, mbCfg->idType, mbCfg->filterCode);
                controllerInfo->mbInfo[mbId].mbType = MB_RX;
            }
            else
            {
                Can_IP_ConfigTxMB(mbStartAddr);
                controllerInfo->mbInfo[mbId].mbType = MB_TX;

                if (controllerInfo->firstTxPollingMBPos == 0xFFU)
                {
                    controllerInfo->firstTxPollingMBPos = controllerInfo->pollingMBNum;
                }
            }

            controllerInfo->mbInfo[mbId].hwObjId = mbCfg->canObjId;

            if (mbCfg->usePolling == (boolean)FALSE)
            {
                if ((mbId / 32U) == 0U)
                {
                    controllerInfo->intMask.mb_0_31_IntMask |= (1UL << mbId);
                }
                else
                {
                    controllerInfo->intMask.mb_32_63_IntMask |= (1UL << (mbId % 32U));
                }
            }
            else
            {
                controllerInfo->pollingMBConfigIndex[controllerInfo->pollingMBNum] = mbCfgIdx;
                controllerInfo->pollingMBNum++;
            }
        }
    }
}

#if (CAN_RXFIFO_SUPPORT == STD_ON)
static FUNC(void, CAN_CODE) Can_IP_RxFifoConfig
(
    VAR(uint8, AUTOMATIC) ControllerId
)
{
    /* Base address of the controller. */
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) controllerBaseAddr = (Can_RegType *)(unsigned long)
            Can_pCurConfig->controllerConfig[ControllerId].baseAddr;
    /* Variable used for indexing Rx FIFO configuration array. */
    VAR(uint8, AUTOMATIC) rxFifoCfgIdx;
    /* Pointer to Rx FIFO configuration. */
    P2CONST(Can_RxFifoConfigType, AUTOMATIC, CAN_APPL_DATA) rxFifoConfig = NULL_PTR;
    /* Pointer to information of the controller. */
    P2VAR(Can_ControllerInfoType, AUTOMATIC, CAN_APPL_DATA) controllerInfo = NULL_PTR;

    if ((boolean)TRUE == Can_IP_IsRxFIFOEnabled(controllerBaseAddr))
    {
        for (rxFifoCfgIdx = 0U; rxFifoCfgIdx < CAN_RX_FIFO_COUNT; rxFifoCfgIdx++)
        {
            rxFifoConfig = &Can_pCurConfig->rxFifoConfig[rxFifoCfgIdx];

            if (rxFifoConfig->controllerId == ControllerId)
            {
                Can_IP_ConfigRxFifoFilterNumber(controllerBaseAddr, rxFifoConfig);
                Can_IP_ConfigRxFifoFilterTable(controllerBaseAddr, rxFifoConfig);

                controllerInfo = &g_CanControllerInfo[ControllerId];
                controllerInfo->mbInfo[RX_FIFO_MB_ID].hwObjId = rxFifoConfig->canObjId;

                if (rxFifoConfig->usePolling == (boolean)FALSE)
                {
                    controllerInfo->intMask.mb_0_31_IntMask |= (1U << RX_FIFO_FRAME_AVL_MB_ID) |
                            (1U << RX_FIFO_ALMOST_FULL_MB_ID) |
                            (1U << RX_FIFO_OVERFLOW_MB_ID);
                    controllerInfo->rxFifoUsePolling = FALSE;
                }
                else
                {
                    controllerInfo->rxFifoUsePolling = TRUE;
                }

#if (CAN_MULTIPLE_READ_PERIOD == STD_ON)
                controllerInfo->rxFifoPollingPeriodId = rxFifoConfig->pollingPeriodId;
#endif
                break;
            }
        }
    }
}
#endif

#if (CAN_RXFIFO_SUPPORT == STD_ON)
static FUNC(void, AUTOMATIC) Can_IP_ConfigRxFifoFilterNumber
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) ControllerBaseAddr,
    P2CONST(Can_RxFifoConfigType, AUTOMATIC, CAN_APPL_DATA) RxFIFOConfig
)
{
    /* CTRL2 value. */
    VAR(uint32, AUTOMATIC) ctrl2Temp = ControllerBaseAddr->CTRL2;

    ctrl2Temp &= ~CAN_CTRL2_RFFN_MASK;
    /* The configuration tool guarantees number of Rx FIFO occupied MBs
    is not less than 8 and is even. */
    ctrl2Temp |= (uint32)(((uint32)RxFIFOConfig->usedMBNum - 8U) / 2U) << 24;
    ControllerBaseAddr->CTRL2 = ctrl2Temp;
}

static FUNC(void, CAN_CODE) Can_IP_ConfigRxFifoFilterTable
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) ControllerBaseAddr,
    P2CONST(Can_RxFifoConfigType, AUTOMATIC, CAN_APPL_DATA) RxFIFOConfig
)
{
    /* The number of MB used by Rx FIFO. */
    VAR(uint8, AUTOMATIC) rxFifoUsedMBNum = RxFIFOConfig->usedMBNum;
    /* The maxium number of filter table elements. */
    VAR(uint8, AUTOMATIC) maxFilterElements = 0U;
    /* Variable used for indexing ID filter table elements. */
    VAR(uint8, AUTOMATIC) filterTableIdx = 0U;
    /* Specify whether individual Rx mask is enabled or not. */
    VAR(boolean, AUTOMATIC) isIndividualRxMaskEn = Can_IP_IsIndividualRxMaskEnabled(ControllerBaseAddr);
    /* ID fliter table start address. */
    P2VAR(uint32, AUTOMATIC, CAN_APPL_DATA) rxFifoFilterTable = (uint32 *)(
                unsigned long)&ControllerBaseAddr->MB[6];

    if (RxFIFOConfig->filterTable != NULL_PTR)
    {
        maxFilterElements = (rxFifoUsedMBNum - 6U) * 4U;

        /* Rx FIFO filter table elements [0~(rxFifoUsedMBNum-1)] are affected by individual Rx masks,
        [rxFifoUsedMBNum~(maxFilterElements-1)] are affected by Rx FIFO global mask. */
        for (filterTableIdx = 0U; filterTableIdx < maxFilterElements; filterTableIdx ++)
        {
            if (filterTableIdx < RxFIFOConfig->fliterCodeNum)
            {
                if ((filterTableIdx < rxFifoUsedMBNum) && (isIndividualRxMaskEn == (boolean)TRUE))
                {
                    Can_IP_ConfigIndividualRxMask(ControllerBaseAddr, filterTableIdx,
                                                  RxFIFOConfig->filterTable[filterTableIdx].filterMask);
                }

                rxFifoFilterTable[filterTableIdx] = RxFIFOConfig->filterTable[filterTableIdx].filterCode;
            }
            else
            {
                /* If no filter code is configured for an filter element, this element will not
                match any ID. */
                if ((filterTableIdx < rxFifoUsedMBNum) && (isIndividualRxMaskEn == (boolean)TRUE))
                {
                    Can_IP_ConfigIndividualRxMask(ControllerBaseAddr, filterTableIdx, 0xFFFFFFFFU);
                }

                rxFifoFilterTable[filterTableIdx] = 0U;
            }
        }

        if ((maxFilterElements > rxFifoUsedMBNum) || (isIndividualRxMaskEn == (boolean)FALSE))
        {
            Can_IP_ConfigRxFifoGlobalMask(ControllerBaseAddr, RxFIFOConfig);
        }
    }
    else
    {
        /* Set Rx FIFO filter mask to 0, i.e. accept all frames, when no filter code is configured. */
        if ((filterTableIdx < rxFifoUsedMBNum) && (isIndividualRxMaskEn == (boolean)TRUE))
        {
            Can_IP_ConfigIndividualRxMask(ControllerBaseAddr, filterTableIdx, 0U);
        }
        else
        {
            Can_IP_ClearRxFifoGlobalMask(ControllerBaseAddr);
        }
    }
}
#endif

#if (CAN_RXFIFO_SUPPORT == STD_ON)
static FUNC(void, CAN_CODE) Can_IP_ConfigRxFifoGlobalMask
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) ControllerBaseAddr,
    P2CONST(Can_RxFifoConfigType, AUTOMATIC, CAN_APPL_DATA) RxFIFOConfig
)
{
    /* RXGMASK has been intialized to 0xFFFFFFFF during controller initialization. */
    if (RxFIFOConfig->idType == CAN_ID_MIXED)
    {
        if (Can_pCurConfig->controllerConfig[RxFIFOConfig->controllerId].
                rxFifoFilterTableFormat == RX_FIFO_FILTER_TYPE_A)
        {
            /* Not checking IDE bit. */
            ControllerBaseAddr->RXFGMASK = 0xBFFFFFFFU;
        }
        else if (Can_pCurConfig->controllerConfig[RxFIFOConfig->controllerId].
                 rxFifoFilterTableFormat == RX_FIFO_FILTER_TYPE_B)
        {
            /* Not checking IDE bit. */
            ControllerBaseAddr->RXFGMASK = 0xBFFFBFFFU;
        }
        else
        {
            /*
             *Type C can not distinguish standard and extended ID,
             *so do nothing.
             */
        }
    }
}
#endif

#if (CAN_RXFIFO_SUPPORT == STD_ON)
LOCAL_INLINE FUNC(void, CAN_CODE) Can_IP_ClearRxFifoGlobalMask
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) ControllerBaseAddr
)
{
    ControllerBaseAddr->RXFGMASK = 0U;
}
#endif

LOCAL_INLINE FUNC(boolean, CAN_CODE) Can_IP_IsFDEnabled
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr
)
{
    return (((BaseAddr->MCR & CAN_MCR_FDEN_MASK) != 0U) ? (boolean)TRUE : (boolean)FALSE);
}

LOCAL_INLINE FUNC(boolean, CAN_CODE) Can_IP_IsIndividualRxMaskEnabled
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr
)
{
    return (((BaseAddr->MCR & CAN_MCR_IRMQ_MASK) != 0U) ? (boolean)TRUE : (boolean)FALSE);
}

LOCAL_INLINE FUNC(boolean, CAN_CODE) Can_IP_IsRxFIFOEnabled
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr
)
{
    return (((BaseAddr->MCR & CAN_MCR_RFEN_MASK) != 0U) ? (boolean)TRUE : (boolean)FALSE);
}

static FUNC_P2VAR(uint32, CAN_CODE, CAN_CODE) Can_IP_GetMBStartAddr
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr,
    VAR(uint8, AUTOMATIC) MBId
)
{
    /* Return value. */
    P2VAR(uint32, AUTOMATIC, CAN_APPL_DATA) ret_addr = NULL_PTR;

    if ((boolean)TRUE == Can_IP_IsFDEnabled(BaseAddr))
    {
        /* Variable used for indexing MB region. */
        VAR(uint8, AUTOMATIC) MBRegionIdx = 0U;
        /* Variable used for record MBDSR value in FDCTLR. */
        VAR(uint8, AUTOMATIC) MBDSRx = 0U;
        /* Variable used for record the pay load size in bytes of the MB. */
        VAR(uint8, AUTOMATIC) PayloadSize = 0U;
        /* Variable used for record the size in word of the MB. */
        VAR(uint8, AUTOMATIC) MBSize = 0U;
        /* Variable used for record the maxium number of MBs in the region. */
        VAR(uint8, AUTOMATIC) RegionMaxMBNum = 0U;

        ret_addr = (uint32 *)(unsigned long)BaseAddr->MB;

        for (MBRegionIdx = 0U; MBRegionIdx < REGION_NUM; MBRegionIdx++)
        {
            /* Get MBDSRx bits from FDCTRL register. */
            MBDSRx = (uint8)(((BaseAddr->FDCTRL) >> (16U + MBRegionIdx * 3U)) & 3U);
            /* Get message buffer data size in bytes. */
            PayloadSize = 1U << (MBDSRx + 3U);
            /* Get message buffer size in words. */
            MBSize = (PayloadSize + 8U) >> 2U;

            /* Maxium MB index in the region. */
            if (MBDSRx == 0U)
            {
                RegionMaxMBNum = REGION_8BYTES_MB_NUM;
            }
            else if (MBDSRx == 1U)
            {
                RegionMaxMBNum = REGION_16BYTES_MB_NUM;
            }
            else if (MBDSRx == 2U)
            {
                RegionMaxMBNum = REGION_32BYTES_MB_NUM;
            }
            else
            {
                RegionMaxMBNum = REGION_64BYTES_MB_NUM;
            }

            if (MBId < RegionMaxMBNum)
            {
                ret_addr += (MBId * MBSize);
                break;
            }
            else
            {
                ret_addr += PER_REGION_SIZE_IN_WORD;
                MBId -= RegionMaxMBNum;
            }
        }
    }
    else
    {
        ret_addr = (uint32 *)(unsigned long)&BaseAddr->MB[MBId];
    }

    return ret_addr;
}

LOCAL_INLINE FUNC(void, CAN_CODE) Can_IP_ConfigIndividualRxMask
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr,
    VAR(uint8, AUTOMATIC) MBId,
    VAR(uint32, AUTOMATIC) FilterMask
)
{
    BaseAddr->RXIMR[MBId] = FilterMask;
}

static FUNC(void, CAN_CODE) Can_IP_ConfigRxMB
(
    P2VAR(uint32, AUTOMATIC, CAN_APPL_DATA) MBBaseAddr,
    VAR(Can_IdTypeType, AUTOMATIC) IdType,
    VAR(uint32, AUTOMATIC) FrameId
)
{
    /* CS field value to be set. */
    VAR(uint32, AUTOMATIC) csTemp = 0U;

    /* CS field: Inactivate Message Buffer. */
    mb_cs_field(MBBaseAddr) = 0U;
    /* ID field: Clean Message Buffer content. */
    mb_id_field(MBBaseAddr) = 0U;

    if (IdType != CAN_ID_EXTENDED)
    {
        /* Setup Message Buffer ID. */
        mb_id_field(MBBaseAddr) = (FrameId << CAN_ID_STD_SHIFT) & CAN_ID_STD_MASK;
    }
    else
    {
        /* Setup Message Buffer ID. */
        mb_id_field(MBBaseAddr) = FrameId & (CAN_ID_EXT_MASK | CAN_ID_STD_MASK);
        /* Setup Message Buffer format. */
        csTemp |= CAN_CS_IDE_MASK;
    }

    /* Activate Rx Message Buffer. */
    csTemp |= CAN_CS_CODE(FLEXCAN_RX_MB_EMPTY);
    mb_cs_field(MBBaseAddr) = csTemp;
}

static FUNC(void, CAN_CODE) Can_IP_ConfigTxMB
(
    P2VAR(uint32, AUTOMATIC, CAN_APPL_DATA) MBBaseAddr
)
{
    /* CS filed: Inactivate Message Buffer. */
    mb_cs_field(MBBaseAddr) = CAN_CS_CODE(FLEXCAN_TX_MB_INACTIVE);

    /* Clean Message Buffer content. */
    mb_id_field(MBBaseAddr) = 0U;    /* ID filed */
}

#if defined(CAN_LOW_POWER_SUPPORT)
LOCAL_INLINE FUNC(boolean, CAN_CODE) Can_IP_IsDozeModeEnabled
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr
)
{
    return (((BaseAddr->MCR & CAN_MCR_DOZE_MASK) != 0U) ? (boolean)TRUE : (boolean)FALSE);
}
#endif

static FUNC(Std_ReturnType, CAN_CODE) Can_IP_SetSleepRequest
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr
)
{
    /* Return value. */
    VAR(Std_ReturnType, AUTOMATIC) ret_result = E_OK;

#if defined(FLEXCAN_LOWPOWER_REGISTER_MODE)
    ret_result = Can_IP_EnterStopMode(BaseAddr);
#else
    /* hardware sync make sure the value update to ip */
    BaseAddr->LOWPOWER_MODE = 0x2u;
#endif

    return ret_result;
}

static FUNC(Std_ReturnType, CAN_CODE) Can_IP_ClearSleepRequest
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr
)
{
    /* Return value. */
    VAR(Std_ReturnType, AUTOMATIC) ret_result = E_OK;

#if defined(FLEXCAN_LOWPOWER_REGISTER_MODE)
    ret_result = Can_IP_ExitStopMode(BaseAddr);
#else
    /* hardware sync make sure the value update to ip */
    BaseAddr->LOWPOWER_MODE = 0x0u;
#endif
    return ret_result;
}

static FUNC(uint8, CAN_CODE) Can_IP_ComputeDLCVal
(
    VAR(uint8, AUTOMATIC) PayloadSize
)
{
    return dlc_code[PayloadSize];
}

static FUNC(uint8, CAN_CODE) Can_IP_ComputeMessageLen
(
    VAR(uint8, AUTOMATIC) DLCVal
)
{
    /* Return result. */
    VAR(uint8, AUTOMATIC) ret_result = 0U;

    if (DLCVal <= 8U)
    {
        ret_result = DLCVal;
    }
    else if (DLCVal == CAN_DLC_VALUE_12_BYTES)
    {
        ret_result = 12U;
    }
    else if (DLCVal == CAN_DLC_VALUE_16_BYTES)
    {
        ret_result = 16U;
    }
    else if (DLCVal == CAN_DLC_VALUE_20_BYTES)
    {
        ret_result = 20U;
    }
    else if (DLCVal == CAN_DLC_VALUE_24_BYTES)
    {
        ret_result = 24U;
    }
    else if (DLCVal == CAN_DLC_VALUE_32_BYTES)
    {
        ret_result = 32U;
    }
    else if (DLCVal == CAN_DLC_VALUE_48_BYTES)
    {
        ret_result = 48U;
    }
    else if (DLCVal == CAN_DLC_VALUE_64_BYTES)
    {
        ret_result = 64U;
    }
    else
    {
        /* Do nothing. */
    }

    return ret_result;
}

static FUNC(Std_ReturnType, CAN_CODE) Can_IP_ReadRxMB
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr,
    VAR(uint8, AUTOMATIC) MBId,
    P2VAR(Can_RxFrameType, AUTOMATIC, CAN_APPL_DATA) frameBuffer
)
{
    /* Return result. */
    VAR(Std_ReturnType, AUTOMATIC) ret_result = E_OK;
    /* Base address of the MB. */
    P2VAR(uint32, AUTOMATIC, CAN_APPL_DATA)mbBaseAddr = Can_IP_GetMBStartAddr(BaseAddr, MBId);
    /* 1.Read CS field of the MB and lock it.
       2.Read the Free Running Timer to unlock the mailbox.*/
    VAR(uint32, AUTOMATIC) csTemp = mb_cs_field(mbBaseAddr);
    /* CODE bits value in CS field. */
    VAR(uint8, AUTOMATIC) code = (uint8)((csTemp & CAN_CS_CODE_MASK) >> CAN_CS_CODE_SHIFT);
    /* DLC bits value in CS field. */
    VAR(uint8, AUTOMATIC) dlcVal = (uint8)((csTemp & CAN_CS_DLC_MASK) >> CAN_CS_DLC_SHIFT);
    /* Variable used for indexing frame data. */
    VAR(uint8, AUTOMATIC) dataIdx = 0U;
    /* MB data field start address. */
    P2VAR(uint8, AUTOMATIC, CAN_APPL_DATA) mbData = mb_data_start_addr(mbBaseAddr);

    /* Check if Message Buffer has received a message. */
    if ((code == FLEXCAN_RX_MB_FULL) || (code == FLEXCAN_RX_MB_OVERRUN))
    {
        /* Get frame ID. */
        if ((csTemp & CAN_CS_IDE_MASK) != 0U)
        {
            frameBuffer->id = CAN_EXTENDED_ID_MASK | (mb_id_field(mbBaseAddr) & (CAN_ID_EXT_MASK |
                              CAN_ID_STD_MASK));
        }
        else
        {
            frameBuffer->id = (mb_id_field(mbBaseAddr) & CAN_ID_STD_MASK) >> CAN_ID_STD_SHIFT;
        }

        if ((csTemp & CAN_CS_EDL_MASK) != 0U)
        {
            frameBuffer->id |= CAN_FD_ID_MASK;
        }

        /* Get frame length. */
        frameBuffer->length = Can_IP_ComputeMessageLen(dlcVal);

        /* 3.Read the contents of the mailbox.  After the mailbox is locked, its contents won’t be modified by FlexCAN Move-in processes. */
        for (dataIdx = 0U; dataIdx < frameBuffer->length; dataIdx++)
        {
            frameBuffer->data[dataIdx] = mbData[IDX_CONVERT(dataIdx)];
        }

        /* 4.Acknowledge the proper flag at the CAN_ IFLAG registers. Then clear corresponding IFLAG */
        Can_IP_ClearMBIntFlag(BaseAddr, MBId);

        /* 5.Read the Free Running Timer to unlock the mailbox. */
        (void)BaseAddr->TIMER;

    }
    else
    {
        /* Read free-running timer to unlock Rx Message Buffer. */
        (void)BaseAddr->TIMER;

        /* The MB didn't receive a message, return not ok. */
        ret_result = E_NOT_OK;
    }

    return ret_result;
}

static FUNC(Std_ReturnType, CAN_CODE) Can_IP_WriteTxMB
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr,
    VAR(uint8, AUTOMATIC) MBId,
    VAR(Can_IdType, AUTOMATIC) CanId,
    VAR(uint8, AUTOMATIC) DataLength,
    P2VAR(uint8, AUTOMATIC, CAN_APPL_DATA) DataBuffer,
    VAR(uint8, AUTOMATIC) PaddingVal
)
{
    /* Return result. */
    VAR(Std_ReturnType, AUTOMATIC) ret_result = E_OK;
    /* Base address of the MB. */
    P2VAR(uint32, AUTOMATIC, CAN_APPL_DATA) mbBaseAddr = Can_IP_GetMBStartAddr(BaseAddr, MBId);
    /* MB CS value to be set. */
    VAR(uint32, AUTOMATIC) csTemp = 0U;
    /* DLC value. */
    VAR(uint8, AUTOMATIC) dlcVal = Can_IP_ComputeDLCVal(DataLength);
    /* Variable used for indexing payload. */
    VAR(uint8, AUTOMATIC) dataIdx = 0U;
    /* MB data field start address. */
    P2VAR(uint8, AUTOMATIC, CAN_APPL_DATA) mbData = mb_data_start_addr(mbBaseAddr);
    /* Message length. */
    VAR(uint8, AUTOMATIC) messageLen = Can_IP_ComputeMessageLen(dlcVal);

    /* Check if Message Buffer is busy. */
    if (CAN_CS_CODE(FLEXCAN_TX_MB_DATA_OR_REMOTE) != (mb_cs_field(mbBaseAddr) & CAN_CS_CODE_MASK))
    {
        /* Inactive Tx Message Buffer. */
        mb_cs_field(mbBaseAddr) = (mb_cs_field(mbBaseAddr) & ~CAN_CS_CODE_MASK) | CAN_CS_CODE(
                                      FLEXCAN_TX_MB_INACTIVE);

        /* Set CS and ID field. */
        if ((CanId & CAN_FD_ID_MASK) != 0U)
        {
            csTemp |= CAN_CS_EDL_MASK | CAN_CS_SRR_MASK | CAN_CS_BRS_MASK;
        }

        if ((CanId & CAN_EXTENDED_ID_MASK) != 0U)
        {
            mb_id_field(mbBaseAddr) = CanId & CAN_ID_MASK;
            csTemp |= CAN_CS_SRR_MASK | CAN_CS_IDE_MASK;
        }
        else
        {
            mb_id_field(mbBaseAddr) = ((CanId & CAN_ID_MASK) << CAN_ID_STD_SHIFT) & CAN_ID_STD_MASK;

        }

        csTemp |= CAN_CS_CODE(FLEXCAN_TX_MB_DATA_OR_REMOTE) | CAN_CS_DLC(dlcVal);

        /* Copy payload for no-trigger transmission. */
        if (DataBuffer != NULL_PTR)
        {
            if ((CanId & CAN_FD_ID_MASK) != 0U)
            {
                for (dataIdx = 0U; dataIdx < DataLength; dataIdx++)
                {
                    mbData[IDX_CONVERT(dataIdx)] = DataBuffer[dataIdx];
                }
            }
            else
            {
                /* limited standard can frame size <=8  */
                DataLength = DataLength > 8u ? 8u : DataLength;

                for (dataIdx = 0U; dataIdx < DataLength; dataIdx++)
                {
                    mbData[IDX_CONVERT(dataIdx)] = DataBuffer[dataIdx];
                }
            }
        }

        /* Pad unspecified data in CAN FD frames > 8 bytes. */
        for (dataIdx = DataLength; dataIdx < messageLen; dataIdx++)
        {
            mbData[IDX_CONVERT(dataIdx)] = PaddingVal;
        }

        /* Activate Tx Message Buffer. */
        mb_cs_field(mbBaseAddr) = csTemp;
    }
    else
    {
        /* The MB is transmitting a message, return not ok. */
        ret_result = E_NOT_OK;
    }

    return ret_result;
}

static FUNC(Std_ReturnType, CAN_CODE) Can_IP_ReadRxFIFO
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr,
    P2VAR(Can_RxFrameType, AUTOMATIC, CAN_APPL_DATA) frameBuffer
)
{
    /* Return value. */
    VAR(Std_ReturnType, AUTOMATIC) ret_result = E_OK;
    /* Base address of the Rx FIFO. */
    P2VAR(uint32, AUTOMATIC, CAN_APPL_DATA) rxFifoBaseAddr = (uint32 *)(unsigned long)
            &BaseAddr->MB[RX_FIFO_MB_ID];
    /* CS field of the Rx FIFO. */
    VAR(uint32, AUTOMATIC) csTemp = 0U;
    /* Variable used for indexing frame data. */
    VAR(uint8, AUTOMATIC) dataIdx = 0U;
    /* Start address of the Rx FIFO data field. */
    P2VAR(uint8, AUTOMATIC, CAN_APPL_DATA) rxFifoData = mb_data_start_addr(rxFifoBaseAddr);

    if ((boolean)TRUE == Can_IP_IsRxFIFOEnabled(BaseAddr))
    {
        /* Read CS field to lock the MB. */
        csTemp = mb_cs_field(rxFifoBaseAddr);

        /* Get frame ID. */
        if ((csTemp & CAN_CS_IDE_MASK) != 0U)
        {
            frameBuffer->id = CAN_EXTENDED_ID_MASK | (mb_id_field(rxFifoBaseAddr) &
                              (CAN_ID_EXT_MASK | CAN_ID_STD_MASK));
        }
        else
        {
            frameBuffer->id = (mb_id_field(rxFifoBaseAddr) & CAN_ID_STD_MASK) >> CAN_ID_STD_SHIFT;
        }

        /* Get frame length. Because CAN FD is disabled when Rx FIFO enabled,
         * so DLC conversion is not needed.
         */
        frameBuffer->length = (uint8)((csTemp & CAN_CS_DLC_MASK) >> CAN_CS_DLC_SHIFT);

        /* Copy frame data. */
        for (dataIdx = 0U; dataIdx < frameBuffer->length; dataIdx++)
        {
            frameBuffer->data[dataIdx] = rxFifoData[IDX_CONVERT(dataIdx)];
        }

        /* Read free-running timer to unlock Rx Message Buffer. */
        (void)BaseAddr->TIMER;
    }
    else
    {
        ret_result = E_NOT_OK;
    }

    return ret_result;
}

LOCAL_INLINE FUNC(void, CAN_CODE) Can_IP_BusOffNotification
(
    VAR(uint8, AUTOMATIC) ControllerId
)
{
    /* Base address of the controller. */
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) controllerBaseAddr = (Can_RegType *)(
                unsigned long)Can_pCurConfig->controllerConfig[ControllerId].baseAddr;
    Can_IP_EnterFreezeMode(controllerBaseAddr);
    /* Clear error counter. */
    controllerBaseAddr->ECR = 0U;
    /* mark busoff occur */
    g_eControllerBusoffState[ControllerId] = TRUE;
    CanIf_ControllerBusOff(ControllerId);
}

static FUNC(boolean, CAN_CODE) Can_IP_GetMBIntFlag
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr,
    VAR(uint8, AUTOMATIC) MBId
)
{
    /* Return value. */
    VAR(boolean, AUTOMATIC) ret_result = FALSE;

    if (MBId <= 31U)
    {
        ret_result = (boolean)(((BaseAddr->IFLAG1) >> MBId) & 1U);
    }

#if (FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBER > 32U)
    else if (MBId <= 63U)
    {
        ret_result = (boolean)(((BaseAddr->IFLAG2) >> (MBId % 32U)) & 1U);
    }

#endif
#if (FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBER > 64U)
    else if (MBId <= 95U)
    {
        ret_result = (boolean)(((BaseAddr->IFLAG3) >> (MBId % 32U)) & 1U);
    }

#endif
#if (FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBER > 96U)
    else if (MBId <= 128U)
    {
        ret_result = (boolean)(((BaseAddr->IFLAG4) >> (MBId % 32U)) & 1U);
    }

#endif
    else
    {
        /* Do nothing. */
    }

    return ret_result;
}

static FUNC(void, CAN_CODE) Can_IP_ClearMBIntFlag
(
    P2VAR(Can_RegType, AUTOMATIC, CAN_APPL_DATA) BaseAddr,
    VAR(uint8, AUTOMATIC) MBId
)
{
    /* Interrupt flag mask. */
    VAR(uint32, AUTOMATIC) mask = 1UL << (MBId % 32U);

    if (MBId <= 31U)
    {
        BaseAddr->IFLAG1 = mask;
    }

#if (FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBER > 32U)
    else if (MBId <= 63U)
    {
        BaseAddr->IFLAG2 = mask;
    }

#endif
#if (FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBER > 64U)
    else if (MBId <= 95U)
    {
        BaseAddr->IFLAG3 = mask;
    }

#endif
#if (FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBER > 96U)
    else if (MBId <= 128U)
    {
        BaseAddr->IFLAG4 = mask;
    }

#endif
    else
    {
        /* Do nothing. */
    }
}

LOCAL_INLINE FUNC(void, CAN_CODE) Can_IP_RxIndication
(
    VAR(uint8, AUTOMATIC) ControllerId,
    VAR(uint8, AUTOMATIC) MBId,
    P2VAR(Can_RxFrameType, AUTOMATIC, CAN_APPL_DATA) RxFrameBuffer
)
{
#ifdef CanLPduReceiveCalloutFunction

    if (E_OK == CanLPduReceiveCalloutFunction(g_CanControllerInfo[ControllerId].mbInfo[MBId].hwObjId,
            RxFrameBuffer->id, RxFrameBuffer->length, RxFrameBuffer->data))
    {
#endif
        /* HRH and controller information structure. */
        CONST(Can_HwType, AUTOMATIC) hwInfo = {RxFrameBuffer->id,
                                               g_CanControllerInfo[ControllerId].mbInfo[MBId].hwObjId,
                                               ControllerId
                                              };
        /* The received L-PDU. */
        VAR(PduInfoType, AUTOMATIC) pduInfo;
        pduInfo.SduDataPtr = RxFrameBuffer->data;
        pduInfo.SduLength  = RxFrameBuffer->length;
#if (defined AUTOSAR_VERSION_403)
        CanIf_RxIndication(hwInfo.Hoh, hwInfo.CanId, pduInfo.SduLength, pduInfo.SduDataPtr);
#elif (defined AUTOSAR_VERSION_421) || (defined AUTOSAR_VERSION_431)
        CanIf_RxIndication(&hwInfo, (const PduInfoType *)&pduInfo);
#else
        CanIf_RxIndication(&hwInfo, (const PduInfoType *)&pduInfo);
#endif
#ifdef CanLPduReceiveCalloutFunction
    }

#endif
}

LOCAL_INLINE FUNC(void, CAN_CODE) Can_IP_TxConfirmation
(
    VAR(uint8, AUTOMATIC) ControllerId,
    VAR(uint8, AUTOMATIC) MBId
)
{
    CanIf_TxConfirmation(g_CanControllerInfo[ControllerId].mbInfo[MBId].canIfPduId);
}

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#ifdef __cplusplus
}
#endif
