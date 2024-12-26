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
 * @file  Can.c
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Can Driver.
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Can.h"
#include "Det.h"
#include "Can_IP.h"
#include "CanIf_Cbk.h"

/* Version and Check Begin */
/* Version Info Begin */
#define CAN_C_VENDOR_ID    0x8C
#define CAN_C_AR_RELEASE_MAJOR_VERSION    4
#define CAN_C_AR_RELEASE_MINOR_VERSION    3
#define CAN_C_AR_RELEASE_REVISION_VERSION 1
#define CAN_C_SW_MAJOR_VERSION    1
#define CAN_C_SW_MINOR_VERSION    0
#define CAN_C_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((CAN_C_AR_RELEASE_MAJOR_VERSION != CAN_H_AR_RELEASE_MAJOR_VERSION)\
    || (CAN_C_AR_RELEASE_MINOR_VERSION != CAN_H_AR_RELEASE_MINOR_VERSION)\
    || (CAN_C_AR_RELEASE_REVISION_VERSION != CAN_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Can.c and Can.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((CAN_C_SW_MAJOR_VERSION != CAN_H_SW_MAJOR_VERSION)\
    || (CAN_C_SW_MINOR_VERSION != CAN_H_SW_MINOR_VERSION)\
    || (CAN_C_SW_PATCH_VERSION != CAN_H_SW_PATCH_VERSION))
#error "Opps, Can.c and Can.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((CAN_C_AR_RELEASE_MAJOR_VERSION != DET_H_AR_RELEASE_MAJOR_VERSION)\
    || (CAN_C_AR_RELEASE_MINOR_VERSION != DET_H_AR_RELEASE_MINOR_VERSION)\
    || (CAN_C_AR_RELEASE_REVISION_VERSION != DET_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Can.c and Det.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((CAN_C_SW_MAJOR_VERSION != DET_H_SW_MAJOR_VERSION)\
    || (CAN_C_SW_MINOR_VERSION != DET_H_SW_MINOR_VERSION)\
    || (CAN_C_SW_PATCH_VERSION != DET_H_SW_PATCH_VERSION))
#error "Opps, Can.c and Det.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((CAN_C_AR_RELEASE_MAJOR_VERSION != CAN_IP_H_AR_RELEASE_MAJOR_VERSION)\
    || (CAN_C_AR_RELEASE_MINOR_VERSION != CAN_IP_H_AR_RELEASE_MINOR_VERSION)\
    || (CAN_C_AR_RELEASE_REVISION_VERSION != CAN_IP_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Can.c and Can_IP.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((CAN_C_SW_MAJOR_VERSION != CAN_IP_H_SW_MAJOR_VERSION)\
    || (CAN_C_SW_MINOR_VERSION != CAN_IP_H_SW_MINOR_VERSION)\
    || (CAN_C_SW_PATCH_VERSION != CAN_IP_H_SW_PATCH_VERSION))
#error "Opps, Can.c and Can_IP.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

/*########################Global variables########################*/

#define CAN_START_SEC_VAR_INIT_UNSPECIFIED
#include "Can_MemMap.h"
#pragma default_function_attributes = @".iram_func"
/**
 * @brief Controller state machine variable.
 */
#if (defined(AUTOSAR_VERSION_421)) || (defined(AUTOSAR_VERSION_403))
volatile VAR(Can_StateTransitionType, CAN_VAR) Can_gControllerState[CAN_CONTROLLER_COUNT] = {(Can_StateTransitionType)CAN_T_UNINIT};
#endif

#define CAN_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Can_MemMap.h"

/**
 * @brief Current configuration.
 */
P2CONST(Can_ConfigType, CAN_VAR, CAN_APPL_CONST) Can_pCurConfig;

#if (!defined(AUTOSAR_VERSION_421)) && (!defined(AUTOSAR_VERSION_403))
volatile VAR(Can_ControllerStateType, CAN_VAR) Can_gControllerState[CAN_CONTROLLER_COUNT];
#endif

/**
 * @brief Baud rate configuration ID for each controller.
 */
VAR(uint16, CAN_VAR) Can_gu16CurBaudRateConfigId[CAN_CONTROLLER_COUNT];


/**
 * @brief The times that controller interrupts are disabled.
 */
VAR(uint8, CAN_VAR) Can_gu8ControllerIntsDisableCnt[CAN_CONTROLLER_COUNT];

/*########################Internal variables########################*/

/**
 * @brief Driver state machine variable.
 */
static VAR(Can_DriverStateType, CAN_VAR) Can_gCanDriverState;

#define CAN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"

/*########################Internal function declarations########################*/
#if (CAN_SET_BAUDRATE_API == STD_ON)
/**
 * @brief Check if the baud rate configuration ID is valid.
 */
static FUNC(Std_ReturnType, CAN_CODE) Can_ValidateBaudRateConfigID
(
    P2CONST(Can_ControllerConfigType, AUTOMATIC, CAN_APPL_DATA) ControllerConfig,
    VAR(uint16, AUTOMATIC) BaudRateConfigID
);
#endif

/*########################Function implementations########################*/
#if (CAN_VERSION_INFO_API == STD_ON)
/**
 * @brief Get version information of CAN driver.
 * @param versioninfo Output version information.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, CAN_APPL_DATA) versioninfo
)
{
#if (CAN_DEV_ERROR_DETECT == STD_ON)

    if (versioninfo == NULL_PTR) {
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_GET_VERSION_INFO,
                              CAN_E_PARAM_POINTER);
    } else {
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
        versioninfo->vendorID = CAN_VENDOR_ID;
        versioninfo->moduleID = CAN_MODULE_ID;
        versioninfo->sw_major_version = CAN_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = CAN_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = CAN_SW_PATCH_VERSION;
#if (CAN_DEV_ERROR_DETECT == STD_ON)
    }

#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
}
#endif /* CAN_VERSION_INFO_API == STD_ON */

/**
 * @brief Initialize all configured CAN controllers.
 * @param Config Pointer to CAN configuration.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_Init
(
    P2CONST(Can_ConfigType, AUTOMATIC, CAN_APPL_CONST) Config
)
{
    /* Variable for indexing configured controllers. */
    VAR(uint8, AUTOMATIC) ctrller_idx = 0U;

    if (Can_gCanDriverState == CAN_READY) {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_INIT, CAN_E_TRANSITION);
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
    } else {
        if (Config == NULL_PTR) {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_INIT,
                                  CAN_E_PARAM_POINTER);
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
        } else {
            Can_pCurConfig = Config;

            for (ctrller_idx = 0U; ctrller_idx < CAN_CONTROLLER_COUNT; ctrller_idx++) {
                Can_gu16CurBaudRateConfigId[ctrller_idx] =
                    Can_pCurConfig->controllerConfig[ctrller_idx].defaultBaudRateId;
                if (TRUE == Can_pCurConfig->controllerConfig->controllerActive) {
                    if (E_OK == Can_IP_InitController(ctrller_idx)) {
#if (defined(AUTOSAR_VERSION_421)) || (defined(AUTOSAR_VERSION_403))
                        Can_gControllerState[ctrller_idx] = CAN_T_STOP;
#else
                        Can_gControllerState[ctrller_idx] = CAN_CS_STOPPED;
#endif
                    }
                } else {
                    /* Do Nothing */
                }
            }

            for (ctrller_idx = 0U; ctrller_idx < CAN_CONTROLLER_COUNT; ctrller_idx++) {
#if (defined(AUTOSAR_VERSION_421)) || (defined(AUTOSAR_VERSION_403))
                if (CAN_T_UNINIT != Can_gControllerState[ctrller_idx]) {
#else
                if (CAN_CS_UNINIT != Can_gControllerState[ctrller_idx]) {
#endif
                    Can_gCanDriverState = CAN_READY;
                } else {
                    /* Do Nothing */
                }
            }

        }
    }
}

/**
 * @brief De-initialize all configured controllers.
 * @param void no paramter.
 * @return none.
 */
#if (!defined(AUTOSAR_VERSION_421)) && (!defined(AUTOSAR_VERSION_403))
FUNC(void, CAN_CODE) Can_DeInit(void)
{
    /* Variable used for indexing configured controllers. */
    VAR(uint8, AUTOMATIC) ctrller_idx = 0U;
    /* Variable used to indicate whether any controller is in CAN_CS_STARTED state. */
    VAR(boolean, AUTOMATIC) can_busy = FALSE;

    if (Can_gCanDriverState != CAN_READY) {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_DEINIT, CAN_E_TRANSITION);
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
    } else {
        for (ctrller_idx = 0U; ctrller_idx < CAN_CONTROLLER_COUNT; ctrller_idx++) {
            if (Can_gControllerState[ctrller_idx] == CAN_CS_STARTED) {
                can_busy = TRUE;
#if (CAN_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_DEINIT, CAN_E_TRANSITION);
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
                break;
            }
        }

        if (can_busy == (boolean)FALSE) {
            /* (CAN91009) The function Can_DeInit shall change the module state to
             * CAN_UNINIT before de-initializing all controllers inside the HW unit.
             */
            Can_gCanDriverState = CAN_UNINIT;

            for (ctrller_idx = 0U; ctrller_idx < CAN_CONTROLLER_COUNT; ctrller_idx++) {
                Can_IP_DeInitController(ctrller_idx);
                Can_gControllerState[ctrller_idx] = CAN_CS_UNINIT;
            }
        }
    }
}
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
#if (defined(AUTOSAR_VERSION_421)) || (defined(AUTOSAR_VERSION_403))
FUNC(Std_ReturnType, CAN_CODE) Can_SetBaudrate
(
    VAR(uint8, AUTOMATIC) Controller,
    VAR(uint16, AUTOMATIC) BaudRateConfigID
)
{
    /* Function return value. */
    VAR(Std_ReturnType, AUTOMATIC) ret_result = E_NOT_OK;

    if (Can_gCanDriverState != CAN_READY) {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE,
                              CAN_SID_SET_BAUDRATE, CAN_E_UNINIT);
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
    } else if (Controller >= CAN_CONTROLLER_COUNT) {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_SET_BAUDRATE,
                              CAN_E_PARAM_CONTROLLER);
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
    } else if (Can_gControllerState[Controller] != CAN_T_STOP) {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_SET_BAUDRATE,
                              CAN_E_TRANSITION);
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
    } else if (E_OK != Can_ValidateBaudRateConfigID(&Can_pCurConfig->controllerConfig[Controller],
               BaudRateConfigID)) {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_SET_BAUDRATE,
                              CAN_E_PARAM_BAUDRATE);
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
    } else {
        Can_gu16CurBaudRateConfigId[Controller] = BaudRateConfigID;
        ret_result = Can_IP_InitController(Controller);
    }

    return ret_result;
}
#else
FUNC(Std_ReturnType, CAN_CODE) Can_SetBaudrate
(
    VAR(uint8, AUTOMATIC) Controller,
    VAR(uint16, AUTOMATIC) BaudRateConfigID
)
{
    /* Function return value. */
    VAR(Std_ReturnType, AUTOMATIC) ret_result = E_NOT_OK;

    if (Controller >= CAN_CONTROLLER_COUNT) {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_SET_BAUDRATE,
                              CAN_E_PARAM_CONTROLLER);
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
    } else if (Can_gControllerState[Controller] == CAN_CS_UNINIT) {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_SET_BAUDRATE,
                              CAN_E_UNINIT);
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
    } else if (Can_gControllerState[Controller] != CAN_CS_STOPPED) {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_SET_BAUDRATE,
                              CAN_E_TRANSITION);
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
    } else if (E_OK != Can_ValidateBaudRateConfigID(&Can_pCurConfig->controllerConfig[Controller],
               BaudRateConfigID)) {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_SET_BAUDRATE,
                              CAN_E_PARAM_BAUDRATE);
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
    } else {
        Can_gu16CurBaudRateConfigId[Controller] = BaudRateConfigID;
        ret_result = Can_IP_InitController(Controller);
    }

    return ret_result;
}
#endif
#endif /* CAN_SET_BAUDRATE_API == STD_ON */

/**
 * @brief Trigger state transition of the CAN controller state machine.
 * @param Controller CAN controller ID.
 * @param Transition New CAN controller state.
 * @return State setting result.
 *  @retval E_OK State transimitted successfully.
 *  @retval E_NOT_OK State transimitted failed.
 */
#if (defined(AUTOSAR_VERSION_421)) || (defined(AUTOSAR_VERSION_403))
FUNC(Std_ReturnType, CAN_CODE) Can_SetControllerMode
(
    VAR(uint8, AUTOMATIC) Controller,
    VAR(Can_StateTransitionType, AUTOMATIC) Transition
)
{
    /* Return value. */
    VAR(Std_ReturnType, AUTOMATIC) ret_result = E_NOT_OK;

    if (Can_gCanDriverState != CAN_READY) {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE,
                              CAN_SID_SET_CONTROLLER_MODE, CAN_E_UNINIT);
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
    } else if (Controller >= CAN_CONTROLLER_COUNT) {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_SET_CONTROLLER_MODE,
                              CAN_E_PARAM_CONTROLLER);
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
    } else if (Transition > CAN_T_WAKEUP) {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_SET_CONTROLLER_MODE,
                              CAN_E_TRANSITION);
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
    } else {
        switch (Transition) {
        case CAN_T_START:
            if (E_OK == Can_IP_SetStartMode(Controller)) {
                Can_gControllerState[Controller] = CAN_T_START;
                CanIf_ControllerModeIndication(Controller, CANIF_CS_STARTED);
                ret_result = E_OK;
            }

            break;

        case CAN_T_SLEEP:
            if (E_OK == Can_IP_SetSleepMode(Controller)) {
                Can_gControllerState[Controller] = CAN_T_SLEEP;
                CanIf_ControllerModeIndication(Controller, CANIF_CS_SLEEP);
                ret_result = E_OK;
            }

            break;

        case CAN_T_STOP:
            if (E_OK == Can_IP_SetStopMode(Controller)) {
                Can_gControllerState[Controller] = CAN_T_STOP;
                CanIf_ControllerModeIndication(Controller, CANIF_CS_STOPPED);
                ret_result = E_OK;
            }

            break;

        case CAN_T_WAKEUP:
            if (E_OK == Can_IP_WakeUp(Controller)) {
                Can_gControllerState[Controller] = CAN_T_STOP;
                CanIf_ControllerModeIndication(Controller, CANIF_CS_STOPPED);
                ret_result = E_OK;
            }

            break;

        default:
            break;
        }
    }

    return ret_result;
}
#else
FUNC(Std_ReturnType, CAN_CODE) Can_SetControllerMode
(
    VAR(uint8, AUTOMATIC) Controller,
    VAR(Can_ControllerStateType, AUTOMATIC) Transition
)
{
    /* Return value. */
    VAR(Std_ReturnType, AUTOMATIC) ret_result = E_NOT_OK;

    if (Can_gCanDriverState != CAN_READY) {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE,
                              CAN_SID_SET_CONTROLLER_MODE, CAN_E_UNINIT);
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
    } else if (Controller >= CAN_CONTROLLER_COUNT) {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_SET_CONTROLLER_MODE,
                              CAN_E_PARAM_CONTROLLER);
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
    } else if (Can_gControllerState[Controller] == CAN_CS_UNINIT) {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_SET_CONTROLLER_MODE,
                              CAN_E_UNINIT);
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
    } else if (Transition > CAN_CS_SLEEP) {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_SET_CONTROLLER_MODE,
                              CAN_E_TRANSITION);
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
    } else {
        switch (Transition) {
        case CAN_CS_STARTED:
            if (E_OK == Can_IP_SetStartMode(Controller)) {
                Can_gControllerState[Controller] = CAN_CS_STARTED;
                CanIf_ControllerModeIndication(Controller, CAN_CS_STARTED);
                ret_result = E_OK;
            }

            break;

        case CAN_CS_SLEEP:
            if (E_OK == Can_IP_SetSleepMode(Controller)) {
                Can_gControllerState[Controller] = CAN_CS_SLEEP;
                CanIf_ControllerModeIndication(Controller, CAN_CS_SLEEP);
                ret_result = E_OK;
            }

            break;

        case CAN_CS_STOPPED:
            if (E_OK == Can_IP_SetStopMode(Controller)) {
                Can_gControllerState[Controller] = CAN_CS_STOPPED;
                CanIf_ControllerModeIndication(Controller, CAN_CS_STOPPED);
                ret_result = E_OK;
            }

            break;

        default:
            break;
        }
    }

    return ret_result;
}

#endif

/**
 * @brief Disable controller interrupts.
 * @param Controller Controller ID.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_DisableControllerInterrupts
(
    VAR(uint8, AUTOMATIC) Controller
)
{
#if (CAN_DEV_ERROR_DETECT == STD_ON)

    if (Can_gCanDriverState != CAN_READY) {
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE,
                              CAN_SID_DISABLE_CONTROLLER_INTERRUPTS, CAN_E_UNINIT);
    } else if (Controller >= CAN_CONTROLLER_COUNT) {
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE,
                              CAN_SID_DISABLE_CONTROLLER_INTERRUPTS, CAN_E_PARAM_CONTROLLER);
    } else {
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */

        if (Can_gu8ControllerIntsDisableCnt[Controller] == 0U) {
            Can_IP_DisableInterrupts(Controller);
        }

        Can_gu8ControllerIntsDisableCnt[Controller]++;
#if (CAN_DEV_ERROR_DETECT == STD_ON)
    }

#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
}

/**
 * @brief Enable controller interrupts.
 * @param Controller Controller ID.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_EnableControllerInterrupts
(
    VAR(uint8, AUTOMATIC) Controller
)
{
#if (CAN_DEV_ERROR_DETECT == STD_ON)

    if (Can_gCanDriverState != CAN_READY) {
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE,
                              CAN_SID_ENABLE_CONTROLLER_INTERRUPTS, CAN_E_UNINIT);
    } else if (Controller >= CAN_CONTROLLER_COUNT) {
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE,
                              CAN_SID_ENABLE_CONTROLLER_INTERRUPTS, CAN_E_PARAM_CONTROLLER);
    } else {
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */

        /* (CAN208) The function Can_EnableControllerInterrupts shall perform no action
         * when Can_DisableControllerInterrupts has not been called before.
         */
        if (Can_gu8ControllerIntsDisableCnt[Controller] > 0U) {
            Can_gu8ControllerIntsDisableCnt[Controller]--;

            if (Can_gu8ControllerIntsDisableCnt[Controller] == 0U) {
                Can_IP_EnableInterrupts(Controller);
            }
        }

#if (CAN_DEV_ERROR_DETECT == STD_ON)
    }

#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
}

#if (CAN_CHECK_WAKEUP_API == STD_ON)
/**
 * @brief Check if a wakeup has occured for the controller.
 * @param Controller Controller ID.
 * @return API calling result.
 *  @retval E_OK Wakeup is detected.
 *  @retval E_NOT_OK Wakeup is not detected.
 */
FUNC(Std_ReturnType, CAN_CODE) Can_CheckWakeup
(
    VAR(uint8, AUTOMATIC) Controller
)
{
    /* Return value. */
    VAR(Std_ReturnType, AUTOMATIC) ret_result = E_NOT_OK;

    if (Can_gCanDriverState != CAN_READY) {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_CBK_CHECK_WAKEUP,
                              CAN_E_UNINIT);
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
    } else if (Controller >= CAN_CONTROLLER_COUNT) {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_CBK_CHECK_WAKEUP,
                              CAN_E_PARAM_CONTROLLER);
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
    } else {

        if (Can_pCurConfig->controllerConfig[Controller].wakeupEnable == (boolean)TRUE) {
#if (defined(AUTOSAR_VERSION_421)) || (defined(AUTOSAR_VERSION_403))

            if (Can_gControllerState[Controller] != CAN_T_SLEEP) {
#else

            if (Can_gControllerState[Controller] != CAN_CS_SLEEP) {
#endif
                ret_result = E_OK;
            }
        }
    }

    return ret_result;
}

#endif /* CAN_CHECK_WAKEUP_API == STD_ON */

/**
 * @brief Get error state of the controller.
 * @param ControllerId Controller ID.
 * @param ErrorStatePtr Ouput error state.
 * @return API calling result.
 *  @retval E_OK Call API successfully.
 *  @retval E_NOT_OK Call API failed.
 */
FUNC(Std_ReturnType, CAN_CODE) Can_GetControllerErrorState
(
    VAR(uint8, AUTOMATIC) ControllerId,
    P2VAR(Can_ErrorStateType, AUTOMATIC, CAN_APPL_DATA) ErrorStatePtr
)
{
    /* Return result. */
    VAR(Std_ReturnType, AUTOMATIC) ret_result = E_NOT_OK;

    if (Can_gCanDriverState != CAN_READY) {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_GETCONTROLLERERRORSTATE,
                              CAN_E_UNINIT);
#endif
    } else if (ControllerId >= CAN_CONTROLLER_COUNT) {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_GETCONTROLLERERRORSTATE,
                              CAN_E_PARAM_CONTROLLER);
#endif
    } else if (ErrorStatePtr == NULL_PTR) {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_GETCONTROLLERERRORSTATE,
                              CAN_E_PARAM_POINTER);
#endif
    } else {
        *ErrorStatePtr = Can_IP_GetErrorState(ControllerId);
        ret_result = E_OK;
    }

    return ret_result;
}

/**
 * @brief Get the current state of the controller.
 * @param Controller Controller ID.
 * @param ControllerModePtr Output the current state.
 * @return API calling result.
 *  @retval E_OK Call API successfully.
 *  @retval E_NOT_OK Call API failed.
 */
#if (defined(AUTOSAR_VERSION_421)) || (defined(AUTOSAR_VERSION_403))
FUNC(Std_ReturnType, CAN_CODE) Can_GetControllerMode
(
    VAR(uint8, AUTOMATIC) Controller,
    P2VAR(Can_StateTransitionType, AUTOMATIC, CAN_APPL_DATA) ControllerModePtr
)
#else
FUNC(Std_ReturnType, CAN_CODE) Can_GetControllerMode
(
    VAR(uint8, AUTOMATIC) Controller,
    P2VAR(Can_ControllerStateType, AUTOMATIC, CAN_APPL_DATA) ControllerModePtr
)
#endif
{
    /* Return result. */
    VAR(Std_ReturnType, AUTOMATIC) ret_result = E_NOT_OK;

    if (Can_gCanDriverState != CAN_READY) {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_GETCONTROLLERMODE,
                              CAN_E_UNINIT);
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
    } else if (Controller >= CAN_CONTROLLER_COUNT) {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_GETCONTROLLERMODE,
                              CAN_E_PARAM_CONTROLLER);
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
    } else if (ControllerModePtr == NULL_PTR) {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_GETCONTROLLERMODE,
                              CAN_E_PARAM_POINTER);
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
    } else {
        *ControllerModePtr = Can_gControllerState[Controller];
        ret_result = E_OK;
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
FUNC(Std_ReturnType, CAN_CODE) Can_Write
(
    VAR(Can_HwHandleType, AUTOMATIC) Hth,
    P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_DATA) PduInfo
)
{
    /* Return result. */
    VAR(Std_ReturnType, AUTOMATIC) ret_result = E_NOT_OK;

    if (Can_gCanDriverState != CAN_READY) {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_WRITE, CAN_E_UNINIT);
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
    } else if (Hth >= CAN_HOH_MAX) {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_WRITE,
                              CAN_E_PARAM_HANDLE);
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
    } else if (PduInfo == NULL_PTR) {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_WRITE,
                              CAN_E_PARAM_POINTER);
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
    }

#if (CAN_TRIGGER_TRANSMIT_EN == STD_OFF)
    else if (PduInfo->sdu == NULL_PTR) {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, (uint8)CAN_INSTANCE, CAN_SID_WRITE,
                              CAN_E_PARAM_POINTER);
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */
    }

#endif /* CAN_TRIGGER_TRANSMIT_EN == STD_ON */
    else {
        ret_result = Can_IP_Write(Hth, PduInfo);
    }

    return ret_result;
}

/**
 * @brief Polling of Tx confirmation.
 * @param none.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_MainFunction_Write(void)
{
    /* Variable used for indexing controllers. */
    VAR(uint8, AUTOMATIC) controllerIdx = 0U;

    if (NULL_PTR != Can_pCurConfig) {
        for (controllerIdx = 0U; controllerIdx < CAN_CONTROLLER_COUNT; controllerIdx++) {
            if (Can_pCurConfig->controllerConfig[controllerIdx].txProcType != INTERRUPT) {
#if (CAN_MULTIPLE_WRITE_PERIOD == STD_ON)
                Can_IP_TxPolling(controllerIdx, 0U, FALSE);
#else
                Can_IP_TxPolling(controllerIdx);
#endif
            }
        }
    }
}

/**
 * @brief Polling of Rx indication.
 * @param none.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_MainFunction_Read(void)
{
    /* Variable used for indexing controllers. */
    VAR(uint8, AUTOMATIC) controllerIdx = 0U;

    if (NULL_PTR != Can_pCurConfig) {
        for (controllerIdx = 0U; controllerIdx < CAN_CONTROLLER_COUNT; controllerIdx++) {
            if (Can_pCurConfig->controllerConfig[controllerIdx].rxProcType != INTERRUPT) {
#if (CAN_MULTIPLE_READ_PERIOD == STD_ON)
                Can_IP_RxPolling(controllerIdx, 0U, FALSE);
#else
                Can_IP_RxPolling(controllerIdx);
#endif
            }
        }
    }
}

#if (CAN_MULTIPLE_WRITE_PERIOD == STD_ON)
#if (CAN_MAINFUNCTION_RW_PERIOD_0 != STD_OFF)
/**
 * @brief Polling of Tx confirmation at period 0.
 * @param none.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_MainFunction_Write_0(void)
{
    /* Variable used for indexing controllers. */
    VAR(uint8, AUTOMATIC) controllerIdx = 0U;

    if (NULL_PTR != Can_pCurConfig) {
        for (controllerIdx = 0U; controllerIdx < CAN_CONTROLLER_COUNT; controllerIdx++) {
            if (Can_pCurConfig->controllerConfig[controllerIdx].txProcType != INTERRUPT) {
                Can_IP_TxPolling(controllerIdx, 0U, TRUE);
            }
        }
    }
}
#endif /* CAN_MAINFUNCTION_RW_PERIOD_0 != STD_OFF */

#if (CAN_MAINFUNCTION_RW_PERIOD_1 != STD_OFF)
/**
 * @brief Polling of Tx confirmation at period 1.
 * @param none.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_MainFunction_Write_1(void)
{
    /* Variable used for indexing controllers. */
    VAR(uint8, AUTOMATIC) controllerIdx = 0U;

    if (NULL_PTR != Can_pCurConfig) {
        for (controllerIdx = 0U; controllerIdx < CAN_CONTROLLER_COUNT; controllerIdx++) {
            if (Can_pCurConfig->controllerConfig[controllerIdx].txProcType != INTERRUPT) {
                Can_IP_TxPolling(controllerIdx, 1U, TRUE);
            }
        }
    }
}
#endif /* CAN_MAINFUNCTION_RW_PERIOD_1 != STD_OFF */

#if (CAN_MAINFUNCTION_RW_PERIOD_2 != STD_OFF)
/**
 * @brief Polling of Tx confirmation at period 2.
 * @param none.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_MainFunction_Write_2(void)
{
    /* Variable used for indexing controllers. */
    VAR(uint8, AUTOMATIC) controllerIdx = 0U;

    if (NULL_PTR != Can_pCurConfig) {
        for (controllerIdx = 0U; controllerIdx < CAN_CONTROLLER_COUNT; controllerIdx++) {
            if (Can_pCurConfig->controllerConfig[controllerIdx].txProcType != INTERRUPT) {
                Can_IP_TxPolling(controllerIdx, 2U, TRUE);
            }
        }
    }
}
#endif /* CAN_MAINFUNCTION_RW_PERIOD_2 != STD_OFF */

#if (CAN_MAINFUNCTION_RW_PERIOD_3 != STD_OFF)
/**
 * @brief Polling of Tx confirmation at period 3.
 * @param none.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_MainFunction_Write_3(void)
{
    /* Variable used for indexing controllers. */
    VAR(uint8, AUTOMATIC) controllerIdx = 0U;

    if (NULL_PTR != Can_pCurConfig) {
        for (controllerIdx = 0U; controllerIdx < CAN_CONTROLLER_COUNT; controllerIdx++) {
            if (Can_pCurConfig->controllerConfig[controllerIdx].txProcType != INTERRUPT) {
                Can_IP_TxPolling(controllerIdx, 3U, TRUE);
            }
        }
    }
}
#endif /* CAN_MAINFUNCTION_RW_PERIOD_3 != STD_OFF */

#if (CAN_MAINFUNCTION_RW_PERIOD_4 != STD_OFF)
/**
 * @brief Polling of Tx confirmation at period 4.
 * @param none.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_MainFunction_Write_4(void)
{
    /* Variable used for indexing controllers. */
    VAR(uint8, AUTOMATIC) controllerIdx = 0U;

    if (NULL_PTR != Can_pCurConfig) {
        for (controllerIdx = 0U; controllerIdx < CAN_CONTROLLER_COUNT; controllerIdx++) {
            if (Can_pCurConfig->controllerConfig[controllerIdx].txProcType != INTERRUPT) {
                Can_IP_TxPolling(controllerIdx, 4U, TRUE);
            }
        }
    }
}
#endif /* CAN_MAINFUNCTION_RW_PERIOD_4 != STD_OFF */

#if (CAN_MAINFUNCTION_RW_PERIOD_5 != STD_OFF)
/**
 * @brief Polling of Tx confirmation at period 5.
 * @param none.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_MainFunction_Write_5(void)
{
    /* Variable used for indexing controllers. */
    VAR(uint8, AUTOMATIC) controllerIdx = 0U;

    if (NULL_PTR != Can_pCurConfig) {
        for (controllerIdx = 0U; controllerIdx < CAN_CONTROLLER_COUNT; controllerIdx++) {
            if (Can_pCurConfig->controllerConfig[controllerIdx].txProcType != INTERRUPT) {
                Can_IP_TxPolling(controllerIdx, 5U, TRUE);
            }
        }
    }
}
#endif /* CAN_MAINFUNCTION_RW_PERIOD_5 != STD_OFF */

#if (CAN_MAINFUNCTION_RW_PERIOD_6 != STD_OFF)
/**
 * @brief Polling of Tx confirmation at period 6.
 * @param none.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_MainFunction_Write_6(void)
{
    /* Variable used for indexing controllers. */
    VAR(uint8, AUTOMATIC) controllerIdx = 0U;

    if (NULL_PTR != Can_pCurConfig) {
        for (controllerIdx = 0U; controllerIdx < CAN_CONTROLLER_COUNT; controllerIdx++) {
            if (Can_pCurConfig->controllerConfig[controllerIdx].txProcType != INTERRUPT) {
                Can_IP_TxPolling(controllerIdx, 6U, TRUE);
            }
        }
    }
}
#endif /* CAN_MAINFUNCTION_RW_PERIOD_6 != STD_OFF */

#if (CAN_MAINFUNCTION_RW_PERIOD_7 != STD_OFF)
/**
 * @brief Polling of Tx confirmation at period 7.
 * @param none.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_MainFunction_Write_7(void)
{
    /* Variable used for indexing controllers. */
    VAR(uint8, AUTOMATIC) controllerIdx = 0U;

    if (NULL_PTR != Can_pCurConfig) {
        for (controllerIdx = 0U; controllerIdx < CAN_CONTROLLER_COUNT; controllerIdx++) {
            if (Can_pCurConfig->controllerConfig[controllerIdx].txProcType != INTERRUPT) {
                Can_IP_TxPolling(controllerIdx, 7U, TRUE);
            }
        }
    }
}
#endif /* CAN_MAINFUNCTION_RW_PERIOD_7 != STD_OFF */

#if (CAN_MAINFUNCTION_RW_PERIOD_0 != STD_OFF)
/**
 * @brief Polling of Tx confirmation at period 8.
 * @param none.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_MainFunction_Write_8(void)
{
    /* Variable used for indexing controllers. */
    VAR(uint8, AUTOMATIC) controllerIdx = 0U;

    if (NULL_PTR != Can_pCurConfig) {
        for (controllerIdx = 0U; controllerIdx < CAN_CONTROLLER_COUNT; controllerIdx++) {
            if (Can_pCurConfig->controllerConfig[controllerIdx].txProcType != INTERRUPT) {
                Can_IP_TxPolling(controllerIdx, 8U, TRUE);
            }
        }
    }
}
#endif /* CAN_MAINFUNCTION_RW_PERIOD_8 != STD_OFF */

#if (CAN_MAINFUNCTION_RW_PERIOD_0 != STD_OFF)
/**
 * @brief Polling of Tx confirmation at period 9.
 * @param none.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_MainFunction_Write_9(void)
{
    /* Variable used for indexing controllers. */
    VAR(uint8, AUTOMATIC) controllerIdx = 0U;

    if (NULL_PTR != Can_pCurConfig) {
        for (controllerIdx = 0U; controllerIdx < CAN_CONTROLLER_COUNT; controllerIdx++) {
            if (Can_pCurConfig->controllerConfig[controllerIdx].txProcType != INTERRUPT) {
                Can_IP_TxPolling(controllerIdx, 9U, TRUE);
            }
        }
    }
}
#endif /* CAN_MAINFUNCTION_RW_PERIOD_9 != STD_OFF */
#endif /* CAN_MULTIPLE_WRITE_PERIOD == STD_ON */

#if (CAN_MULTIPLE_READ_PERIOD == STD_ON)
#if (CAN_MAINFUNCTION_RW_PERIOD_0 != STD_OFF)
/**
 * @brief Polling of Rx indication at period 0.
 * @param none.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_MainFunction_Read_0(void)
{
    /* Variable used for indexing controllers. */
    VAR(uint8, AUTOMATIC) controllerIdx = 0U;

    if (NULL_PTR != Can_pCurConfig) {
        for (controllerIdx = 0U; controllerIdx < CAN_CONTROLLER_COUNT; controllerIdx++) {
            if (Can_pCurConfig->controllerConfig[controllerIdx].rxProcType != INTERRUPT) {
                Can_IP_RxPolling(controllerIdx, 0U, TRUE);
            }
        }
    }
}
#endif /* CAN_MAINFUNCTION_RW_PERIOD_0 != STD_OFF */

#if (CAN_MAINFUNCTION_RW_PERIOD_1 != STD_OFF)
/**
 * @brief Polling of Rx indication at period 1.
 * @param none.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_MainFunction_Read_1(void)
{
    /* Variable used for indexing controllers. */
    VAR(uint8, AUTOMATIC) controllerIdx = 0U;

    if (NULL_PTR != Can_pCurConfig) {
        for (controllerIdx = 0U; controllerIdx < CAN_CONTROLLER_COUNT; controllerIdx++) {
            if (Can_pCurConfig->controllerConfig[controllerIdx].rxProcType != INTERRUPT) {
                Can_IP_RxPolling(controllerIdx, 1U, TRUE);
            }
        }
    }
}
#endif /* CAN_MAINFUNCTION_RW_PERIOD_1 != STD_OFF */

#if (CAN_MAINFUNCTION_RW_PERIOD_2 != STD_OFF)
/**
 * @brief Polling of Rx indication at period 2.
 * @param none.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_MainFunction_Read_2(void)
{
    /* Variable used for indexing controllers. */
    VAR(uint8, AUTOMATIC) controllerIdx = 0U;

    if (NULL_PTR != Can_pCurConfig) {
        for (controllerIdx = 0U; controllerIdx < CAN_CONTROLLER_COUNT; controllerIdx++) {
            if (Can_pCurConfig->controllerConfig[controllerIdx].rxProcType != INTERRUPT) {
                Can_IP_RxPolling(controllerIdx, 2U, TRUE);
            }
        }
    }
}
#endif /* CAN_MAINFUNCTION_RW_PERIOD_2 != STD_OFF */

#if (CAN_MAINFUNCTION_RW_PERIOD_3 != STD_OFF)
/**
 * @brief Polling of Rx indication at period 3.
 * @param none.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_MainFunction_Read_3(void)
{
    /* Variable used for indexing controllers. */
    VAR(uint8, AUTOMATIC) controllerIdx = 0U;

    if (NULL_PTR != Can_pCurConfig) {
        for (controllerIdx = 0U; controllerIdx < CAN_CONTROLLER_COUNT; controllerIdx++) {
            if (Can_pCurConfig->controllerConfig[controllerIdx].rxProcType != INTERRUPT) {
                Can_IP_RxPolling(controllerIdx, 3U, TRUE);
            }
        }
    }
}
#endif /* CAN_MAINFUNCTION_RW_PERIOD_3 != STD_OFF */

#if (CAN_MAINFUNCTION_RW_PERIOD_4 != STD_OFF)
/**
 * @brief Polling of Rx indication at period 4.
 * @param none.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_MainFunction_Read_4(void)
{
    /* Variable used for indexing controllers. */
    VAR(uint8, AUTOMATIC) controllerIdx = 0U;

    if (NULL_PTR != Can_pCurConfig) {
        for (controllerIdx = 0U; controllerIdx < CAN_CONTROLLER_COUNT; controllerIdx++) {
            if (Can_pCurConfig->controllerConfig[controllerIdx].rxProcType != INTERRUPT) {
                Can_IP_RxPolling(controllerIdx, 4U, TRUE);
            }
        }
    }
}
#endif /* CAN_MAINFUNCTION_RW_PERIOD_4 != STD_OFF */

#if (CAN_MAINFUNCTION_RW_PERIOD_5 != STD_OFF)
/**
 * @brief Polling of Rx indication at period 5.
 * @param none.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_MainFunction_Read_5(void)
{
    /* Variable used for indexing controllers. */
    VAR(uint8, AUTOMATIC) controllerIdx = 0U;

    if (NULL_PTR != Can_pCurConfig) {
        for (controllerIdx = 0U; controllerIdx < CAN_CONTROLLER_COUNT; controllerIdx++) {
            if (Can_pCurConfig->controllerConfig[controllerIdx].rxProcType != INTERRUPT) {
                Can_IP_RxPolling(controllerIdx, 5U, TRUE);
            }
        }
    }
}
#endif /* CAN_MAINFUNCTION_RW_PERIOD_5 != STD_OFF */

#if (CAN_MAINFUNCTION_RW_PERIOD_6 != STD_OFF)
/**
 * @brief Polling of Rx indication at period 6.
 * @param none.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_MainFunction_Read_6(void)
{
    /* Variable used for indexing controllers. */
    VAR(uint8, AUTOMATIC) controllerIdx = 0U;

    if (NULL_PTR != Can_pCurConfig) {
        for (controllerIdx = 0U; controllerIdx < CAN_CONTROLLER_COUNT; controllerIdx++) {
            if (Can_pCurConfig->controllerConfig[controllerIdx].rxProcType != INTERRUPT) {
                Can_IP_RxPolling(controllerIdx, 6U, TRUE);
            }
        }
    }
}
#endif /* CAN_MAINFUNCTION_RW_PERIOD_6 != STD_OFF */

#if (CAN_MAINFUNCTION_RW_PERIOD_7 != STD_OFF)
/**
 * @brief Polling of Rx indication at period 7.
 * @param none.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_MainFunction_Read_7(void)
{
    /* Variable used for indexing controllers. */
    VAR(uint8, AUTOMATIC) controllerIdx = 0U;

    if (NULL_PTR != Can_pCurConfig) {
        for (controllerIdx = 0U; controllerIdx < CAN_CONTROLLER_COUNT; controllerIdx++) {
            if (Can_pCurConfig->controllerConfig[controllerIdx].rxProcType != INTERRUPT) {
                Can_IP_RxPolling(controllerIdx, 7U, TRUE);
            }
        }
    }
}
#endif /* CAN_MAINFUNCTION_RW_PERIOD_7 != STD_OFF */

#if (CAN_MAINFUNCTION_RW_PERIOD_8 != STD_OFF)
/**
 * @brief Polling of Rx indication at period 8.
 * @param none.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_MainFunction_Read_8(void)
{
    /* Variable used for indexing controllers. */
    VAR(uint8, AUTOMATIC) controllerIdx = 0U;

    if (NULL_PTR != Can_pCurConfig) {
        for (controllerIdx = 0U; controllerIdx < CAN_CONTROLLER_COUNT; controllerIdx++) {
            if (Can_pCurConfig->controllerConfig[controllerIdx].rxProcType != INTERRUPT) {
                Can_IP_RxPolling(controllerIdx, 8U, TRUE);
            }
        }
    }
}
#endif /* CAN_MAINFUNCTION_RW_PERIOD_8 != STD_OFF */

#if (CAN_MAINFUNCTION_RW_PERIOD_9 != STD_OFF)
/**
 * @brief Polling of Rx indication at period 9.
 * @param none.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_MainFunction_Read_9(void)
{
    /* Variable used for indexing controllers. */
    VAR(uint8, AUTOMATIC) controllerIdx = 0U;

    if (NULL_PTR != Can_pCurConfig) {
        for (controllerIdx = 0U; controllerIdx < CAN_CONTROLLER_COUNT; controllerIdx++) {
            if (Can_pCurConfig->controllerConfig[controllerIdx].rxProcType != INTERRUPT) {
                Can_IP_RxPolling(controllerIdx, 9U, TRUE);
            }
        }
    }
}
#endif /* CAN_MAINFUNCTION_RW_PERIOD_9 != STD_OFF */
#endif /* CAN_MULTIPLE_READ_PERIOD == STD_ON */

/**
 * @brief Polling of bus-off event.
 * @param none.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_MainFunction_BusOff(void)
{
    /* Variable used for indexing controllers. */
    VAR(uint8, AUTOMATIC) controllerIdx = 0U;

    if (NULL_PTR != Can_pCurConfig) {
        for (controllerIdx = 0U; controllerIdx < CAN_CONTROLLER_COUNT; controllerIdx++) {
            if (Can_pCurConfig->controllerConfig[controllerIdx].busoffProcType == POLLING) {
                Can_IP_BusOffPolling(controllerIdx);
            }
        }
    }
}

/**
 * @brief Polling of wake-up event.
 * @param none.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_MainFunction_Wakeup(void)
{
    /* Variable used for indexing controllers. */
    VAR(uint8, AUTOMATIC) controllerIdx = 0U;

    if (NULL_PTR != Can_pCurConfig) {
        for (controllerIdx = 0U; controllerIdx < CAN_CONTROLLER_COUNT; controllerIdx++) {
            if (Can_pCurConfig->controllerConfig[controllerIdx].wakeupProcType == POLLING) {
                Can_IP_WakeUpPolling(controllerIdx);
            }
        }
    }
}

/**
 * @brief Polling of controller mode transitions.
 * @param none.
 * @return none.
 */
FUNC(void, CAN_CODE) Can_MainFunction_Mode(void)
{
    /* Variable used for indexing controllers. */
    VAR(uint8, AUTOMATIC) controllerIdx = 0U;

    if (NULL_PTR != Can_pCurConfig) {
        for (controllerIdx = 0U; controllerIdx < CAN_CONTROLLER_COUNT; controllerIdx++) {
            Can_IP_ControllerModePolling(controllerIdx);
        }
    }
}

/*########################Internal Function implementations########################*/
#if (CAN_SET_BAUDRATE_API == STD_ON)
static FUNC(Std_ReturnType, CAN_CODE) Can_ValidateBaudRateConfigID
(
    P2CONST(Can_ControllerConfigType, AUTOMATIC, CAN_APPL_DATA) ControllerConfig,
    VAR(uint16, AUTOMATIC) BaudRateConfigID
)
{
    /* Return value. */
    VAR(Std_ReturnType, AUTOMATIC) ret_result = E_NOT_OK;
    /* Variable used for indexing baud rate configuration. */
    VAR(uint16, AUTOMATIC) baudRateCfgIdx = 0U;

    for (baudRateCfgIdx = 0; baudRateCfgIdx < ControllerConfig->baudRateConfigCount; baudRateCfgIdx++) {
        if (ControllerConfig->baudRateConfig[baudRateCfgIdx].baudRateConfigId == BaudRateConfigID) {
            ret_result = E_OK;
            break;
        }
    }

    return ret_result;
}
#endif

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#ifdef __cplusplus
}
#endif
#pragma default_function_attributes =