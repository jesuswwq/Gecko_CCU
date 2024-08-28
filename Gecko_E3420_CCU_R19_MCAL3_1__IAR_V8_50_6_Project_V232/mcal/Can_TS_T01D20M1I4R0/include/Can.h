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
 * @file  Can.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Can Driver.
 */
#ifndef CAN_H_
#define CAN_H_

#include "Mcal.h"
#include "ComStack_Types.h"
#include "Can_Cfg.h"
#include "Can_GeneralTypes.h"
/* Version and Check Begin */
/* Version Info Begin */
#define CAN_H_VENDOR_ID    0x8C
#define CAN_H_AR_RELEASE_MAJOR_VERSION    4
#define CAN_H_AR_RELEASE_MINOR_VERSION    3
#define CAN_H_AR_RELEASE_REVISION_VERSION 1
#define CAN_H_SW_MAJOR_VERSION    1
#define CAN_H_SW_MINOR_VERSION    0
#define CAN_H_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((CAN_H_AR_RELEASE_MAJOR_VERSION != MCAL_H_AR_RELEASE_MAJOR_VERSION)\
    || (CAN_H_AR_RELEASE_MINOR_VERSION != MCAL_H_AR_RELEASE_MINOR_VERSION)\
    || (CAN_H_AR_RELEASE_REVISION_VERSION != MCAL_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Can.h and Mcal.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((CAN_H_SW_MAJOR_VERSION != MCAL_H_SW_MAJOR_VERSION)\
    || (CAN_H_SW_MINOR_VERSION != MCAL_H_SW_MINOR_VERSION)\
    || (CAN_H_SW_PATCH_VERSION != MCAL_H_SW_PATCH_VERSION))
#error "Opps, Can.h and Mcal.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((CAN_H_AR_RELEASE_MAJOR_VERSION != COMSTACK_TYPES_H_AR_RELEASE_MAJOR_VERSION)\
    || (CAN_H_AR_RELEASE_MINOR_VERSION != COMSTACK_TYPES_H_AR_RELEASE_MINOR_VERSION)\
    || (CAN_H_AR_RELEASE_REVISION_VERSION != COMSTACK_TYPES_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Can.h and ComStack_Types.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((CAN_H_SW_MAJOR_VERSION != COMSTACK_TYPES_H_SW_MAJOR_VERSION)\
    || (CAN_H_SW_MINOR_VERSION != COMSTACK_TYPES_H_SW_MINOR_VERSION)\
    || (CAN_H_SW_PATCH_VERSION != COMSTACK_TYPES_H_SW_PATCH_VERSION))
#error "Opps, Can.h and ComStack_Types.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((CAN_H_AR_RELEASE_MAJOR_VERSION != CAN_GENERALTYPES_H_AR_RELEASE_MAJOR_VERSION)\
    || (CAN_H_AR_RELEASE_MINOR_VERSION != CAN_GENERALTYPES_H_AR_RELEASE_MINOR_VERSION)\
    || (CAN_H_AR_RELEASE_REVISION_VERSION != CAN_GENERALTYPES_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Can.h and Can_GeneralTypes.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((CAN_H_SW_MAJOR_VERSION != CAN_GENERALTYPES_H_SW_MAJOR_VERSION)\
    || (CAN_H_SW_MINOR_VERSION != CAN_GENERALTYPES_H_SW_MINOR_VERSION)\
    || (CAN_H_SW_PATCH_VERSION != CAN_GENERALTYPES_H_SW_PATCH_VERSION))
#error "Opps, Can.h and Can_GeneralTypes.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

#ifdef __cplusplus
extern "C" {
#endif

/* Module version definition. */
#define CAN_VENDOR_ID                   0x8C
#define CAN_MODULE_ID                   80
#define CAN_AR_RELEASE_MAJOR_VERSION    4
#define CAN_AR_RELEASE_MINOR_VERSION    3
#define CAN_AR_RELEASE_REVISION_VERSION 1
#define CAN_SW_MAJOR_VERSION            1
#define CAN_SW_MINOR_VERSION            0
#define CAN_SW_PATCH_VERSION            0

/**
* @brief Development errors.
*/
#define CAN_E_PARAM_POINTER      ((uint8)0x01U)
#define CAN_E_PARAM_HANDLE       ((uint8)0x02U)
#define CAN_E_PARAM_DATA_LENGTH  ((uint8)0x03U)
#define CAN_E_PARAM_CONTROLLER   ((uint8)0x04U)
#define CAN_E_UNINIT             ((uint8)0x05U)
#define CAN_E_TRANSITION         ((uint8)0x06U)
#define CAN_E_PARAM_BAUDRATE      ((uint8)0x07U)
#define CAN_E_ICOM_CONFIG_INVALID ((uint8)0x08U)
#define CAN_E_INIT_FAILED         ((uint8)0x09U)
#define CAN_E_DATALOST            ((uint8)0x01U)
#define CAN_E_INVALID_CONTROLLER ((uint8)0x0AU)

/**
* @brief Service ID (APIs) for Det reporting.
*/
#define CAN_SID_INIT                          ((uint8)0x00U)
#define CAN_SID_MAIN_FUNCTION_WRITE           ((uint8)0x01U)
#define CAN_SID_SET_CONTROLLER_MODE           ((uint8)0x03U)
#define CAN_SID_DISABLE_CONTROLLER_INTERRUPTS ((uint8)0x04U)
#define CAN_SID_ENABLE_CONTROLLER_INTERRUPTS  ((uint8)0x05U)
#define CAN_SID_WRITE                         ((uint8)0x06U)
#define CAN_SID_GET_VERSION_INFO              ((uint8)0x07U)
#define CAN_SID_MAIN_FUNCTION_READ            ((uint8)0x08U)
#define CAN_SID_MAIN_FUNCTION_BUS_OFF         ((uint8)0x09U)
#define CAN_SID_MAIN_FUNCTION_WAKEUP          ((uint8)0x0AU)
#define CAN_SID_CBK_CHECK_WAKEUP              ((uint8)0x0BU)
#define CAN_SID_MAIN_FUNCTION_MODE            ((uint8)0x0CU)
#define CAN_SID_CHANGE_BAUDRATE               ((uint8)0x0DU)
#define CAN_SID_CHECK_BAUDRATE                ((uint8)0x0EU)
#define CAN_SID_SET_BAUDRATE                  ((uint8)0x0FU)
#define CAN_SID_DEINIT                        ((uint8)0x10U)
#define CAN_SID_GETCONTROLLERERRORSTATE       ((uint8)0x11U)
#define CAN_SID_GETCONTROLLERMODE             ((uint8)0x12U)
#define CAN_SID_IP_ENABLE                     ((uint8)0x13U)
#define CAN_SID_IP_DISABLE                    ((uint8)0x14U)
#define CAN_SID_IP_RESET                      ((uint8)0x15U)

/**
* @brief Can busy.
*/
#define        CAN_BUSY  (2U)

/**
 * @brief Frmae ID parsing in PduInfo.
 */
#define CAN_FD_ID_MASK  (0x40000000U)
#define CAN_EXTENDED_ID_MASK   (0x80000000U)
#define CAN_ID_MASK (0x3FFFFFFFU)

/**
 * @brief States of CAN driver state machine.
 */
typedef enum {
    CAN_UNINIT = 0U,
    CAN_READY
} Can_DriverStateType;

/**
 * @brief CAN event, such as Rx/Tx frame, wakeup, etc., processing mode.
 */
typedef enum {
    INTERRUPT = 0U,
    POLLING,
    MIXED
} Can_EventProcessingType;

/**
 * @brief CAN ID type.
 */
typedef enum {
    CAN_ID_STANDARD = 0U,
    CAN_ID_EXTENDED,
    CAN_ID_MIXED
} Can_IdTypeType;

/**
 * @brief Hardware object type.
 */
typedef enum {
    RECEIVE = 0U,
    TRANSMIT
} Can_HohTypeType;

/**
 * @brief Rx FIFO ID filter table format.
 */
typedef enum {
    RX_FIFO_FILTER_TYPE_A = 0U,
    RX_FIFO_FILTER_TYPE_B,
    RX_FIFO_FILTER_TYPE_C,
    RX_FIFO_FILTER_TYPE_D
} Can_RxFIFOFilterTableFormatType;

/**
 * @brief Rx FIFO reception priority type.
 */
typedef enum {
    MB_PRIORITY_LOW = 0U,
    MB_PRIORITY_HIGH
} Can_MBRxPriorityType;

#if (CAN_FD_SUPPORT == STD_ON)
/**
 * @brief CAN FD configuration structure.
 */
typedef struct {
    /* CAN FD basic configuration,
     * bit0: CANFD, bit1: ISO-CANFD, bit2: TxBRS.
     */
    uint8 option;
    uint8 tdcOffset;
    uint32 dataBitTimingRegAlt;
} Can_FDConfigType;
#endif

/**
 * @brief Baud rate configuration structure.
 */
typedef struct {
    uint16 baudRateConfigId;
    uint16 extendBitTimingFormat;
    uint32 nominalBitTimingRegAlt;
#if (CAN_FD_SUPPORT == STD_ON)
    Can_FDConfigType fdConfig;
#endif
} Can_BaudRateConfigType;

/**
 * @brief CAN controller configuration structure.
 */
typedef struct {
    /**< Contoller is used=1 or not_used=0*/
    boolean controllerActive;
    uint32 baseAddr;
    Can_EventProcessingType rxProcType;
    Can_EventProcessingType txProcType;
    Can_EventProcessingType busoffProcType;
    Can_EventProcessingType wakeupProcType;
    uint8 controllerId;
    uint8 maxMBNum;
    /* Basic configuration,
     * bit0: LoopBack, bit1: ListeOnly, bit2: SelfWakeUp, bit3: PEClockFromOsc,
     * bit4: IndividualRxMask, bit5: DozeMode, bit6: RxFIFO, bit7: LowestNumberMBFirst.
     */
    uint8 option;
#if (CAN_CHECK_WAKEUP_API == STD_ON)
    boolean wakeupEnable;
#endif
    uint16 defaultBaudRateId;
    uint16 baudRateConfigCount;
    const Can_BaudRateConfigType *baudRateConfig;
#if (CAN_FD_SUPPORT == STD_ON)
    uint32 mbdsrVal;
#endif
    Can_RxFIFOFilterTableFormatType rxFifoFilterTableFormat;
    Can_MBRxPriorityType mbPriority;
} Can_ControllerConfigType;

/**
 * @brief MB configuration structure.
 */
typedef struct {
    Can_IdTypeType idType;
    Can_HohTypeType hohType;
    uint16 canObjId;
    uint8 controllerId;
    uint8 mbId;
    uint8 payloadSize;
    uint8 fdPaddingVal;
    boolean usePolling;
#if (CAN_MULTIPLE_READ_PERIOD == STD_ON) || (CAN_MULTIPLE_WRITE_PERIOD == STD_ON)
    uint8 pollingPeriodId;
#endif
#if (CAN_TRIGGER_TRANSMIT_EN == STD_ON)
    boolean triggerTransmitEnable;
#endif
    uint32 filterCode;
    uint32 filterMask;
} Can_MBConfigType;

/**
 * @brief Rx FIFO filter table structure.
 */
typedef struct {
    uint32 filterCode;
    uint32 filterMask;
} Can_RxFIFOFilterTableType;

/**
 * @brief Rx FIFO configuration structure.
 */
typedef struct {
    Can_IdTypeType idType;
    uint16 canObjId;
    uint8 controllerId;
    boolean usePolling;
#if (CAN_MULTIPLE_READ_PERIOD == STD_ON)
    uint8 pollingPeriodId;
#endif
    /* Number of MB used by Rx FIFO must be in the range [8, ControllerConfig.maxMBNum],
     * and must be even.
     */
    uint8 usedMBNum;
    /* Number of filter code must not be more than usedMBNum. */
    uint8 fliterCodeNum;
    /* Pointer to the array of Rx FIFO filter table. */
    const Can_RxFIFOFilterTableType *filterTable;
} Can_RxFifoConfigType;

/**
 * @brief CAN configuration structure.
 */
typedef struct {
    /* Pointer to the array of all controller configurations. */
    const Can_ControllerConfigType *controllerConfig;
    /* Pointer to the array of all MBs. */
    const Can_MBConfigType *mbConfig;
    /* Pointer to the array of all Rx FIFOs. */
    const Can_RxFifoConfigType *rxFifoConfig;
    /* All Rx MBs are ahead of all Tx MBs. */
    uint16 firstHthIndex;
} Can_ConfigType;

extern CONST(Can_ConfigType, CAN_VAR) Can_Config;

#if (CAN_VERSION_INFO_API == STD_ON)
/**
 * @brief Get version information of CAN driver.
 * @param versioninfo Output version information.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, CAN_APPL_DATA) versioninfo
);
#endif

/**
 * @brief Initialize all configured CAN controllers.
 * @param Config Pointer to CAN configuration.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_Init
(
    P2CONST(Can_ConfigType, AUTOMATIC, CAN_APPL_CONST) Config
);

/**
 * @brief De-initialize all configured controllers.
 * @param void no paramter.
 * @return none.
 */
#if (!defined(AUTOSAR_VERSION_421)) && (!defined(AUTOSAR_VERSION_403))
extern FUNC(void, CAN_CODE) Can_DeInit(void);
#endif

#if (CAN_SET_BAUDRATE_API == STD_ON)
/**
 * @brief Set baud rate of the controller.
 * @param Controller CAN controller ID.
 * @param BaudRateConfigID Baud rate configuration ID.
 * @return Baud rate setting result.
 *  @retval E_OK Set baud rate successfully.
 *  @retval E_NOT_OK Set baud rate failed.
 */
extern FUNC(Std_ReturnType, CAN_CODE) Can_SetBaudrate
(
    VAR(uint8, AUTOMATIC) Controller,
    VAR(uint16, AUTOMATIC) BaudRateConfigID
);
#endif

/**
 * @brief Trigger state transition of the CAN controller state machine.
 * @param Controller CAN controller ID.
 * @param Transition New CAN controller state.
 * @return State setting result.
 *  @retval E_OK State transimitted successfully.
 *  @retval E_NOT_OK State transimitted failed.
 */
#if (defined(AUTOSAR_VERSION_421)) || (defined(AUTOSAR_VERSION_403))
extern FUNC(Std_ReturnType, CAN_CODE) Can_SetControllerMode
(
    VAR(uint8, AUTOMATIC) Controller,
    VAR(Can_StateTransitionType, AUTOMATIC) Transition
);
#else
extern FUNC(Std_ReturnType, CAN_CODE) Can_SetControllerMode
(
    VAR(uint8, AUTOMATIC) Controller,
    VAR(Can_ControllerStateType, AUTOMATIC) Transition
);
#endif

/**
 * @brief Disable controller interrupts.
 * @param Controller Controller ID.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_DisableControllerInterrupts
(
    VAR(uint8, AUTOMATIC) Controller
);

/**
 * @brief Enable controller interrupts.
 * @param Controller Controller ID.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_EnableControllerInterrupts
(
    VAR(uint8, AUTOMATIC) Controller
);

#if (CAN_CHECK_WAKEUP_API == STD_ON)
/**
 * @brief Check if a wakeup has occured for the controller.
 * @param Controller Controller ID.
 * @return API calling result.
 *  @retval E_OK Wakeup is detected.
 *  @retval E_NOT_OK Wakeup is not detected.
 */
extern FUNC(Std_ReturnType, CAN_CODE) Can_CheckWakeup
(
    VAR(uint8, AUTOMATIC) Controller
);
#endif

/**
 * @brief Get error state of the controller.
 * @param ControllerId Controller ID.
 * @param ErrorStatePtr Ouput error state.
 * @return API calling result.
 *  @retval E_OK Call API successfully.
 *  @retval E_NOT_OK Call API failed.
 */
extern FUNC(Std_ReturnType, CAN_CODE) Can_GetControllerErrorState
(
    VAR(uint8, AUTOMATIC) ControllerId,
    P2VAR(Can_ErrorStateType, AUTOMATIC, CAN_APPL_DATA) ErrorStatePtr
);

/**
 * @brief Get the current state of the controller.
 * @param Controller Controller ID.
 * @param ControllerModePtr Output the current state.
 * @return API calling result.
 *  @retval E_OK Call API successfully.
 *  @retval E_NOT_OK Call API failed.
 */
#if (defined(AUTOSAR_VERSION_421)) || (defined(AUTOSAR_VERSION_403))
extern FUNC(Std_ReturnType, CAN_CODE) Can_GetControllerMode
(
    VAR(uint8, AUTOMATIC) Controller,
    P2VAR(Can_StateTransitionType, AUTOMATIC, CAN_APPL_DATA) ControllerModePtr
);
#else
extern FUNC(Std_ReturnType, CAN_CODE) Can_GetControllerMode
(
    VAR(uint8, AUTOMATIC) Controller,
    P2VAR(Can_ControllerStateType, AUTOMATIC, CAN_APPL_DATA) ControllerModePtr
);
#endif

/**
 * @brief Transmit a CAN message.
 * @param Hth Hardware-transmit handle.
 * @param PduInfo Pointer to SDU user memory, data length and identifier.
 * @return API calling result.
 *  @retval E_OK Write CAN MB successfully.
 *  @retval E_NOT_OK Write CAN MB failed.
 */
extern FUNC(Std_ReturnType, CAN_CODE) Can_Write
(
    VAR(Can_HwHandleType, AUTOMATIC) Hth,
    P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_DATA) PduInfo
);

/**
 * @brief Polling of Tx confirmation.
 * @param none.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_MainFunction_Write(void);

/**
 * @brief Polling of Rx indication.
 * @param none.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_MainFunction_Read(void);

#if (CAN_MULTIPLE_WRITE_PERIOD == STD_ON)
#if (CAN_MAINFUNCTION_RW_PERIOD_0 != STD_OFF)
/**
 * @brief Polling of Tx confirmation at period 0.
 * @param none.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_MainFunction_Write_0(void);
#endif

#if (CAN_MAINFUNCTION_RW_PERIOD_1 != STD_OFF)
/**
 * @brief Polling of Tx confirmation at period 1.
 * @param none.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_MainFunction_Write_1(void);
#endif

#if (CAN_MAINFUNCTION_RW_PERIOD_2 != STD_OFF)
/**
 * @brief Polling of Tx confirmation at period 2.
 * @param none.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_MainFunction_Write_2(void);
#endif

#if (CAN_MAINFUNCTION_RW_PERIOD_3 != STD_OFF)
/**
 * @brief Polling of Tx confirmation at period 3.
 * @param none.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_MainFunction_Write_3(void);
#endif

#if (CAN_MAINFUNCTION_RW_PERIOD_4 != STD_OFF)
/**
 * @brief Polling of Tx confirmation at period 4.
 * @param none.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_MainFunction_Write_4(void);
#endif

#if (CAN_MAINFUNCTION_RW_PERIOD_5 != STD_OFF)
/**
 * @brief Polling of Tx confirmation at period 5.
 * @param none.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_MainFunction_Write_5(void);
#endif

#if (CAN_MAINFUNCTION_RW_PERIOD_6 != STD_OFF)
/**
 * @brief Polling of Tx confirmation at period 6.
 * @param none.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_MainFunction_Write_6(void);
#endif

#if (CAN_MAINFUNCTION_RW_PERIOD_7 != STD_OFF)
/**
 * @brief Polling of Tx confirmation at period 7.
 * @param none.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_MainFunction_Write_7(void);
#endif

#if (CAN_MAINFUNCTION_RW_PERIOD_8 != STD_OFF)
/**
 * @brief Polling of Tx confirmation at period 8.
 * @param none.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_MainFunction_Write_8(void);
#endif

#if (CAN_MAINFUNCTION_RW_PERIOD_9 != STD_OFF)
/**
 * @brief Polling of Tx confirmation at period 9.
 * @param none.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_MainFunction_Write_9(void);
#endif
#endif /* CAN_MULTIPLE_WRITE_PERIOD == STD_ON */

#if (CAN_MULTIPLE_READ_PERIOD == STD_ON)
#if (CAN_MAINFUNCTION_RW_PERIOD_0 != STD_OFF)
/**
 * @brief Polling of Rx indication at period 0.
 * @param none.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_MainFunction_Read_0(void);
#endif

#if (CAN_MAINFUNCTION_RW_PERIOD_1 != STD_OFF)
/**
 * @brief Polling of Rx indication at period 1.
 * @param none.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_MainFunction_Read_1(void);
#endif

#if (CAN_MAINFUNCTION_RW_PERIOD_2 != STD_OFF)
/**
 * @brief Polling of Rx indication at period 2.
 * @param none.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_MainFunction_Read_2(void);
#endif

#if (CAN_MAINFUNCTION_RW_PERIOD_3 != STD_OFF)
/**
 * @brief Polling of Rx indication at period 3.
 * @param none.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_MainFunction_Read_3(void);
#endif

#if (CAN_MAINFUNCTION_RW_PERIOD_4 != STD_OFF)
/**
 * @brief Polling of Rx indication at period 4.
 * @param none.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_MainFunction_Read_4(void);
#endif

#if (CAN_MAINFUNCTION_RW_PERIOD_5 != STD_OFF)
/**
 * @brief Polling of Rx indication at period 5.
 * @param none.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_MainFunction_Read_5(void);
#endif

#if (CAN_MAINFUNCTION_RW_PERIOD_6 != STD_OFF)
/**
 * @brief Polling of Rx indication at period 6.
 * @param none.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_MainFunction_Read_6(void);
#endif

#if (CAN_MAINFUNCTION_RW_PERIOD_7 != STD_OFF)
/**
 * @brief Polling of Rx indication at period 7.
 * @param none.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_MainFunction_Read_7(void);
#endif

#if (CAN_MAINFUNCTION_RW_PERIOD_8 != STD_OFF)
/**
 * @brief Polling of Rx indication at period 8.
 * @param none.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_MainFunction_Read_8(void);
#endif

#if (CAN_MAINFUNCTION_RW_PERIOD_9 != STD_OFF)
/**
 * @brief Polling of Rx indication at period 9.
 * @param none.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_MainFunction_Read_9(void);
#endif
#endif /* CAN_MULTIPLE_READ_PERIOD == STD_ON */

/**
 * @brief Polling of bus-off event.
 * @param none.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_MainFunction_BusOff(void);

/**
 * @brief Polling of wake-up event.
 * @param none.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_MainFunction_Wakeup(void);

/**
 * @brief Polling of controller mode transitions.
 * @param none.
 * @return none.
 */
extern FUNC(void, CAN_CODE) Can_MainFunction_Mode(void);

/**
 * @brief CAN0 interrupt service routine.
 */
ISR(Can_Controller0IrqHandler);
/**
 * @brief CAN1 interrupt service routine.
 */
ISR(Can_Controller1IrqHandler);
/**
 * @brief CAN2 interrupt service routine.
 */
ISR(Can_Controller2IrqHandler);
/**
 * @brief CAN3 interrupt service routine.
 */
ISR(Can_Controller3IrqHandler);
/**
 * @brief CAN4 interrupt service routine.
 */
ISR(Can_Controller4IrqHandler);
/**
 * @brief CAN5 interrupt service routine.
 */
ISR(Can_Controller5IrqHandler);
/**
 * @brief CAN6 interrupt service routine.
 */
ISR(Can_Controller6IrqHandler);
/**
 * @brief CAN7 interrupt service routine.
 */
ISR(Can_Controller7IrqHandler);
/**
 * @brief CAN8 interrupt service routine.
 */
ISR(Can_Controller8IrqHandler);
/**
 * @brief CAN9 interrupt service routine.
 */
ISR(Can_Controller9IrqHandler);
/**
 * @brief CAN10 interrupt service routine.
 */
ISR(Can_Controller10IrqHandler);
/**
 * @brief CAN11 interrupt service routine.
 */
ISR(Can_Controller11IrqHandler);
/**
 * @brief CAN12 interrupt service routine.
 */
ISR(Can_Controller12IrqHandler);
/**
 * @brief CAN13 interrupt service routine.
 */
ISR(Can_Controller13IrqHandler);
/**
 * @brief CAN14 interrupt service routine.
 */
ISR(Can_Controller14IrqHandler);
/**
 * @brief CAN15 interrupt service routine.
 */
ISR(Can_Controller15IrqHandler);
/**
 * @brief CAN16 interrupt service routine.
 */
ISR(Can_Controller16IrqHandler);
/**
 * @brief CAN17 interrupt service routine.
 */
ISR(Can_Controller17IrqHandler);
/**
 * @brief CAN18 interrupt service routine.
 */
ISR(Can_Controller18IrqHandler);
/**
 * @brief CAN19 interrupt service routine.
 */
ISR(Can_Controller19IrqHandler);
/**
 * @brief CAN20 interrupt service routine.
 */
ISR(Can_Controller20IrqHandler);
/**
 * @brief CAN21 interrupt service routine.
 */
ISR(Can_Controller21IrqHandler);
/**
 * @brief CAN22 interrupt service routine.
 */
ISR(Can_Controller22IrqHandler);
/**
 * @brief CAN23 interrupt service routine.
 */
ISR(Can_Controller23IrqHandler);
#ifdef __cplusplus
}
#endif

#endif /* CANH_H_ */
