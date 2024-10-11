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
 * @file  Can_IP.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Can Driver.
 */
#ifndef CAN_IP_H_
#define CAN_IP_H_

#ifdef __cplusplus
extern "C" {
#endif
/* Version and Check Begin */
/* Version Info Begin */
#define CAN_IP_H_VENDOR_ID    0x8C
#define CAN_IP_H_AR_RELEASE_MAJOR_VERSION    4
#define CAN_IP_H_AR_RELEASE_MINOR_VERSION    3
#define CAN_IP_H_AR_RELEASE_REVISION_VERSION 1
#define CAN_IP_H_SW_MAJOR_VERSION    1
#define CAN_IP_H_SW_MINOR_VERSION    0
#define CAN_IP_H_SW_PATCH_VERSION    0
/* Version Info End */
/* Version and Check End */

/**
 * @brief The maxium number of Message Buffers in each controller.
 */
#define FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBER 64U

/**
 * @brief little endian.
 */
#define CORE_LITTLE_ENDIAN  1

/* FlexCAN freezing timeout counter. */
#define FLEXCAN_TIMEOUT_COUNTER 50000U

/* CAN FD SMB region. */
#define CAN_FD_SMB_START_ADDR_OFFSET    0xF28U
#define CAN_FD_SMB_END_ADDR_OFFSET      0xFFFU

/* Get message buffer fields. */
#define mb_cs_field(x)  (*((uint32*)(x)))
#define mb_id_field(x)  (*((uint32*)(x)+1))
#define mb_data_start_addr(x)   ((uint8*)((uint32*)(x)+2))

/* Number of message buffer region. */
#if FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBER <= 32
#define REGION_NUM  1U
#elif FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBER <= 64
#define REGION_NUM  2U
#elif FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBER <= 96
#define REGION_NUM  3U
#else
#define REGION_NUM  4U
#endif

/* Number of message buffer per region. */
#define REGION_8BYTES_MB_NUM    32U
#define REGION_16BYTES_MB_NUM   21U
#define REGION_32BYTES_MB_NUM   12U
#define REGION_64BYTES_MB_NUM   7U

/* Region size in word. */
#define PER_REGION_SIZE_IN_WORD (4U * 32U)

/* CAN FD extended data length DLC encoding */
#define CAN_DLC_VALUE_12_BYTES                   9U
#define CAN_DLC_VALUE_16_BYTES                   10U
#define CAN_DLC_VALUE_20_BYTES                   11U
#define CAN_DLC_VALUE_24_BYTES                   12U
#define CAN_DLC_VALUE_32_BYTES                   13U
#define CAN_DLC_VALUE_48_BYTES                   14U
#define CAN_DLC_VALUE_64_BYTES                   15U

/* Data index converting between frame and MB. */
#if CORE_LITTLE_ENDIAN
#define IDX_CONVERT(x)  (((x) & 0xFCU) + 3U - ((x) & 3U))
#else
#define IDX_CONVERT(x)  (x)
#endif

/* Rx FIFO message buffer ID definition. */
#define RX_FIFO_MB_ID                            0U

/* Rx FIFO interrupt ID definitions. */
#define RX_FIFO_FRAME_AVL_MB_ID                  5U
#define RX_FIFO_ALMOST_FULL_MB_ID                6U
#define RX_FIFO_OVERFLOW_MB_ID                   7U

extern P2CONST(Can_ConfigType, CAN_VAR, CAN_APPL_CONST) Can_pCurConfig;
#if (defined(AUTOSAR_VERSION_421)) || (defined(AUTOSAR_VERSION_403))
extern volatile VAR(Can_StateTransitionType, CAN_VAR) Can_gControllerState[CAN_CONTROLLER_COUNT];
#else
extern volatile VAR(Can_ControllerStateType, CAN_VAR) Can_gControllerState[CAN_CONTROLLER_COUNT];
#endif

extern VAR(uint16, CAN_VAR) Can_gu16CurBaudRateConfigId[CAN_CONTROLLER_COUNT];
extern VAR(uint8, CAN_VAR) Can_gu8ControllerIntsDisableCnt[CAN_CONTROLLER_COUNT];

extern VAR(uint8, CAN_VAR) g_eControllerBusoffState[CAN_CONTROLLER_COUNT];

/**
 * @brief Initialize CAN controller.
 * @param ControllerId Controller ID.
 * @return Initialization result.
 *  @retval E_OK Initialize successfully.
 *  @retval E_NOT_OK Initialize failed.
 */
extern FUNC(Std_ReturnType, CAN_CODE) Can_IP_InitController
(
    VAR(uint8, AUTOMATIC) ControllerId
);

/**
 * @brief De-initialize the controller.
 * @param ControllerId Controller ID.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_IP_DeInitController
(
    VAR(uint8, AUTOMATIC) ControllerId
);

/**
 * @brief Set the controller mode to CAN_CS_STARTED.
 * @param ControllerId Controller ID.
 * @return Start mode setting result.
 *  @retval E_OK Set the controller mode to CAN_CS_STARTED successfully.
 *  @retval E_NOT_OK Set the controller mode to CAN_CS_STARTED failed.
 */
extern FUNC(Std_ReturnType, CAN_CODE) Can_IP_SetStartMode
(
    VAR(uint8, AUTOMATIC) ControllerId
);

/**
 * @brief Set the controller mode to CAN_CS_SLEEP.
 * @param ControllerId Controller ID.
 * @return Sleep mode setting result.
 *  @retval E_OK Set the controller mode to CAN_CS_SLEEP successfully.
 *  @retval E_NOT_OK Set the controller mode to CAN_CS_SLEEP failed.
 */
extern FUNC(Std_ReturnType, CAN_CODE) Can_IP_SetSleepMode
(
    VAR(uint8, AUTOMATIC) ControllerId
);

/**
 * @brief Set the controller mode to CAN_CS_STOPPED.
 * @param ControllerId Controller ID.
 * @return Stop mode setting result.
 *  @retval E_OK Set the controller mode to CAN_CS_STOPPED successfully.
 *  @retval E_NOT_OK Set the controller mode to CAN_CS_STOPPED failed.
 */
extern FUNC(Std_ReturnType, CAN_CODE) Can_IP_SetStopMode
(
    VAR(uint8, AUTOMATIC) ControllerId
);

/**
 * @brief Set the controller mode to CAN_CS_STOPPED.
 * @param ControllerId Controller ID.
 * @return Stop mode setting result.
 *  @retval E_OK Set the controller mode to CAN_CS_STOPPED successfully.
 *  @retval E_NOT_OK Set the controller mode to CAN_CS_STOPPED failed.
 */
extern FUNC(Std_ReturnType, CAN_CODE) Can_IP_WakeUp
(
    VAR(uint8, AUTOMATIC) ControllerId
);


/**
 * @brief Disable all interupts of the controller.
 * @param ControllerId Controller ID.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_IP_DisableInterrupts
(
    VAR(uint8, AUTOMATIC) ControllerId
);

/**
 * @brief Enable all needed interrupts of the controller.
 * @param ControllerId Controller ID.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_IP_EnableInterrupts
(
    VAR(uint8, AUTOMATIC) ControllerId
);

/**
 * @brief Get error state of the controller.
 * @param ControllerId Controller ID.
 * @return error state.
 *  @retval CAN_ERRORSTATE_ACTIVE active error.
 *  @retval CAN_ERRORSTATE_PASSIVE passive error.
 *  @retval CAN_ERRORSTATE_BUSOFF bus off.
 */
extern FUNC(Can_ErrorStateType, CAN_CODE) Can_IP_GetErrorState
(
    VAR(uint8, AUTOMATIC) ControllerId
);

/**
 * @brief Transmit a CAN message.
 * @param Hth Hardware-transmit handle.
 * @param PduInfo Pointer to SDU user memory, data length and identifier.
 * @return API calling result.
 *  @retval E_OK Write CAN MB successfully.
 *  @retval E_NOT_OK Write CAN MB failed.
 */
extern FUNC(Std_ReturnType, CAN_CODE) Can_IP_Write
(
    VAR(Can_HwHandleType, AUTOMATIC) Hth,
    P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_DATA) PduInfo
);

#if (CAN_MULTIPLE_WRITE_PERIOD == STD_ON)
/**
 * @brief Polling of Tx MBs of the controller at the given period.
 * @param ControllerId Controller ID.
 * @param PeriodId Period ID.
 * @param MatchPeriod Whether match period or not.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_IP_TxPolling
(
    VAR(uint8, AUTOMATIC) ControllerId,
    VAR(uint8, AUTOMATIC) PeriodId,
    VAR(boolean, AUTOMATIC) MatchPeriod
);
#else
/**
 * @brief Polling of Tx MBs of the controller.
 * @param ControllerId Controller ID.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_IP_TxPolling
(
    VAR(uint8, AUTOMATIC) ControllerId
);
#endif

#if (CAN_MULTIPLE_READ_PERIOD == STD_ON)
/**
 * @brief Polling of Rx MBs or Rx FIFO of the controller at the given period.
 * @param ControllerId Controller ID.
 * @param PeriodId Period ID.
 * @param MatchPeriod Whether match period ID or not.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_IP_RxPolling
(
    VAR(uint8, AUTOMATIC) ControllerId,
    VAR(uint8, AUTOMATIC) PeriodId,
    VAR(boolean, AUTOMATIC) MatchPeriod
);
#else
/**
 * @brief Polling of Rx MBs or Rx FIFO of the controller.
 * @param ControllerId Controller ID.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_IP_RxPolling
(
    VAR(uint8, AUTOMATIC) ControllerId
);
#endif

/**
 * @brief Polling of bus-off event.
 * @param none.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_IP_BusOffPolling
(
    VAR(uint8, AUTOMATIC) ControllerId
);

/**
 * @brief Polling of wake-up event.
 * @param none.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_IP_WakeUpPolling
(
    VAR(uint8, AUTOMATIC) ControllerId
);

/**
 * @brief Polling of controller mode transitions.
 * @param none.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_IP_ControllerModePolling
(
    VAR(uint8, AUTOMATIC) ControllerId
);

/**
 * @brief CAN ISR.
 * @param ControllerId Controller ID.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_IP_IrqHandler
(
    VAR(uint8, AUTOMATIC) ControllerId
);

#ifdef __cplusplus
}
#endif

#endif /* CAN_IP_H_ */
