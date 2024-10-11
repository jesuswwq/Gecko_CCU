/** *****************************************************************************************************
 * SEMIDRIVE Copyright Statement                                                                        *
 * Copyright (c) SEMIDRIVE. All rights reserved                                                         *
 *                                                                                                      *
 * This software and all rights therein are owned by SEMIDRIVE, and are                                 *
 * protected by copyright law and other relevant laws, regulations and                                  *
 * protection. Without SEMIDRIVE's prior written consent and/or related rights,                         *
 * please do not use this software or any potion thereof in any form or by any                          *
 * means. You may not reproduce, modify or distribute this software except in                           *
 * compliance with the License. Unless required by applicable law or agreed to                          *
 * in writing, software distributed under the License is distributed on                                 *
 * an 'AS IS' basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.                         *
 *                                                                                                      *
 *******************************************************************************************************/
/** *****************************************************************************************************
 * \file     Port.c                                                                                     *
 * \brief    AUTOSAR 4.3.1 MCAL Port Driver                                                             *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/14     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
/** Traceability       : SWSR_PORT_002 */
#include "Port.h"
#if (STD_ON == PORT_DEV_ERROR_DETECT)
/** Traceability       : SWSR_PORT_002 SWSR_PORT_054 */
#include "Det.h"
#endif
#if (STD_ON == PORT_SAFETY_ENABLE)
#include "FuSaMcalReportError.h"
#endif
/** Traceability       : SWSR_PORT_002 SWSR_PORT_015 */
#include "SchM_Port.h"
#include "Port_Fault.h"
/********************************************************************************************************
 *                                 Imported Compiler Switch Checks                                      *
 *******************************************************************************************************/
#ifndef PORT_SW_MAJOR_VERSION
#error "PORT_SW_MAJOR_VERSION is not defined."
#endif

#ifndef PORT_SW_MINOR_VERSION
#error "PORT_SW_MINOR_VERSION is not defined."
#endif

#ifndef PORT_SW_PATCH_VERSION
#error "PORT_SW_PATCH_VERSION is not defined."
#endif

/* AUTOSAR Secification File Version Check */
#ifndef PORT_AR_RELEASE_MAJOR_VERSION
#error "PORT_AR_RELEASE_MAJOR_VERSION is not defined."
#endif

/* AUTOSAR Secification File Version Check */
#ifndef PORT_AR_RELEASE_MINOR_VERSION
#error "PORT_AR_RELEASE_MINOR_VERSION is not defined."
#endif

/* AUTOSAR Secification File Version Check */
#ifndef PORT_AR_RELEASE_REVISION_VERSION
#error "PORT_AR_RELEASE_REVISION_VERSION is not defined."
#endif

/** \brief  AUTOSAR Major and Minor release version check. */
#if(PORT_AR_RELEASE_MAJOR_VERSION != 4U)
#error "PORT_AR_RELEASE_MAJOR_VERSION does not match."
#endif

#if(PORT_AR_RELEASE_MINOR_VERSION != 3U)
#error "PORT_AR_RELEASE_MINOR_VERSION does not match."
#endif

#if(PORT_AR_RELEASE_REVISION_VERSION != 1U)
#error "PORT_AR_RELEASE_REVISION_VERSION does not match."
#endif
/********************************************************************************************************
 *                                 Private Macro definition                                             *
 *******************************************************************************************************/
/* Dummy error id state process */
#define PORT_DUMMY_STATEMENT(state)                                      ((state) = (state))
/********************************************************************************************************
 *                                  Private Variable Declarations                                        *
 *******************************************************************************************************/
/** Traceability       : SW_SM008 */
#define PORT_START_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#include "Port_MemMap.h"
/** \brief  The configuration file pointer initialized in Port_init, and used in subsequent interfaces */
static const Port_ConfigType *Port_InitConfigPtr;
#define PORT_STOP_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#include "Port_MemMap.h"

#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
/********************************************************************************************************
 *                                  Private Function Declarations                                       *
 *******************************************************************************************************/
/** *****************************************************************************************************
 * \brief This function check whether driver is initialized.
 *
 * \verbatim
 * Syntax             : static Std_ReturnType Port_EnterCheck(uint8 serviceId)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : serviceId - Module Service Id
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Return the errorId, which record current error status.
 *
 * Description        : This function shall check whether driver is initialized, if driver is
 *                      initialized when check in  PORT_SID_INIT service, return error; otherwise if
 *                      driver is not initialized when check in other services, return error.
 * \endverbatim
 * Traceability       : SWSR_PORT_036 SW_SM001 SW_SM002 SW_SM006
 *******************************************************************************************************/
static Std_ReturnType Port_EnterCheck(const uint8 serviceId)
{
    /* ----- Local Variables ---------------------------------------------- */
    /* Variable used to store current error status */
    Std_ReturnType errStatus = E_OK;

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Check Port_Init service*/
    if (PORT_SID_INIT == serviceId)
    {
        /* If "Port_Init" was already called (i.e. driver is initialized), return error. */
        if (NULL_PTR != Port_InitConfigPtr)
        {
            errStatus = PORT_E_INIT;
        } /* else not needed */
        PortHookBegin_Port_EnterCheck1();
        PortHookEnd_Port_EnterCheck1();
    }
    /* #20 Check other services*/
    else
    {
        /* If "Port_Init" was not called (i.e driver is uninitialized), return error. */
        PortHookBegin_Port_EnterCheck2();
        if (NULL_PTR == Port_InitConfigPtr)
        {
            errStatus = PORT_E_UNINIT;
        } /* else not needed */
        PortHookEnd_Port_EnterCheck2();
    }

    return errStatus;
}

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
/** *****************************************************************************************************
 * \brief Initializes the Port Driver.
 *
 * \verbatim
 * Syntax             : void Port_Init(const Port_ConfigType* ConfigPtr)
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : ConfigPtr - Pointer to configuration set
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Driver Module Initialization function.The Initialization function shall
 *                      ALL ports and port pins with the configuration set pointed to by the parameter
 *                      ConfigPtr.
 * \endverbatim
 * Traceability       : SWSR_PORT_003 SWSR_PORT_004 SWSR_PORT_005 SWSR_PORT_006
 *                      SWSR_PORT_017 SWSR_PORT_018 SWSR_PORT_033 SWSR_PORT_034
 *                      SWSR_PORT_035 SWSR_PORT_036 SWSR_PORT_037 SWSR_PORT_038
 *                      SWSR_PORT_039 SWSR_PORT_040 SWSR_PORT_055 SWSR_PORT_056
 *                      SW_SM001 SW_SM002 SW_SM006
 *******************************************************************************************************/
void Port_Init(const Port_ConfigType *ConfigPtr)
{
    /* ----- Local Variables ---------------------------------------------- */
    /* Variable used to store current error status */
    Std_ReturnType errStatus;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module init states */
    errStatus = Port_EnterCheck(PORT_SID_INIT);

    /* #20 Check input parameters for plausibility */
    if (E_OK == errStatus)
    {
        if ((NULL_PTR != ConfigPtr) && (0U != ConfigPtr->num))
        {
            /* ----- Implementation ----------------------------------------------- */
            /* #30 Configure port pin common configuration */
            errStatus = Port_Ip_Init(ConfigPtr->padCfgPtr, ConfigPtr->num);

            if (E_OK == errStatus)
            {
                /* #40 Configure analog digital combo io*/
#if (PORT_ANALOG_PIN_ENABLE == STD_ON)
                errStatus = Port_Ip_AnalogPadInit(ConfigPtr->analogCfgPtr, ConfigPtr->analogNum);
#endif /** #if (PORT_ANALOG_PIN_ENABLE == STD_ON)*/

                if (E_OK == errStatus)
                {
                    /* #50 Save configuration pointer in global variable*/
                    Port_InitConfigPtr = ConfigPtr;
                } /* else not needed */
            } /* else not needed */
        }
        else
        {
            errStatus = PORT_E_INIT_FAILED;
        }
    } /* else not needed */

    /* ----- Development Error Report --------------------------------------- */
    /* #60 Report errors if any occurred */
#if ((STD_ON == PORT_DEV_ERROR_DETECT) || (PORT_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == PORT_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)PORT_MODULE_ID, (uint8)PORT_INSTANCE_ID, (uint8)PORT_SID_INIT,
                              (uint8)errStatus);
#endif /** #if (STD_ON == PORT_DEV_ERROR_DETECT) */
#if (STD_ON == PORT_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)PORT_MODULE_ID, (uint8)PORT_INSTANCE_ID, (uint8)PORT_SID_INIT,
                                   (uint8)errStatus);
#endif /** #if (STD_ON == PORT_SAFETY_ENABLE) */
    } /* else not needed */

#else
    {
        /* #70 Dummy assignment avoid compiler warning */
        PORT_DUMMY_STATEMENT(errStatus);
    }
#endif /** #if ((STD_ON == PORT_DEV_ERROR_DETECT) || (PORT_SAFETY_ENABLE)) */
}
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
/** *****************************************************************************************************
 * \brief Set the direction of the Pin during runtime.
 *
 * \verbatim
 * Syntax             : void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction)
 *
 * Service ID[hex]    : 0x01
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Pin - Port Pin ID number
 *                      Direction - Port Pin Direction
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : For most of the pins, the direction be controlled by IPs. For instance,
 *                      UART tx pin is an output and rx is an input. An exception here is GPIO,
 *                      which direction controlled by GPIO 'dir' and these pins are ones SW
 *                      can really set their direction. To make things less-complicate, this
 *                      func only set direction of GPIOs.
 *                      Only pin configured to directChangable can be set the port pin mode during
 *                      runtime.
 *                      This function is available if the PORT_SET_PIN_DIRECTION_API is set STD_ON
 * \endverbatim
 * Traceability       : SWSR_PORT_008 SWSR_PORT_042 SWSR_PORT_043 SWSR_PORT_044
 *                      SWSR_PORT_055 SWSR_PORT_056 SWSR_PORT_041 SW_SM001
 *******************************************************************************************************/
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction)
{
    /* ----- Local Variables ---------------------------------------------- */
    /* Variable used to store current error status */
    Std_ReturnType errStatus;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module states */
    errStatus = Port_EnterCheck(PORT_SID_SET_PIN_DIRECTION);

    if (E_OK == errStatus)
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #20 Set pin direction */
        errStatus = Port_Ip_SetPinDirection(Pin, Direction, Port_InitConfigPtr->padCfgPtr,
                                            Port_InitConfigPtr->num);
    } /* else not needed */

    /* ----- Development Error Report --------------------------------------- */
    /* #30 Report errors if any occurred */
#if ((STD_ON == PORT_DEV_ERROR_DETECT) || (PORT_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == PORT_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)PORT_MODULE_ID, (uint8)PORT_INSTANCE_ID,
                              (uint8)PORT_SID_SET_PIN_DIRECTION, (uint8)errStatus);
#endif /** #if (STD_ON == PORT_DEV_ERROR_DETECT) */
#if (STD_ON == PORT_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)PORT_MODULE_ID, (uint8)PORT_INSTANCE_ID,
                                   (uint8)PORT_SID_SET_PIN_DIRECTION, (uint8)errStatus);
#endif /** #if (STD_ON == PORT_SAFETY_ENABLE) */
    } /* else not needed */

#else
    {
        /* #40 Dummy assignment avoid compiler warning */
        PORT_DUMMY_STATEMENT(errStatus);
    }
#endif /** #if ((STD_ON == PORT_DEV_ERROR_DETECT) || (PORT_SAFETY_ENABLE)) */
}
#endif /** #if (PORT_SET_PIN_DIRECTION_API == STD_ON)*/

/** *****************************************************************************************************
 * \brief Refreshes port pin direction.
 *
 * \verbatim
 * Syntax             : void Port_RefreshPortDirection(void)
 *
 * Service ID[hex]    : 0x02
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function shall refresh the direction of all configured ports to the
 *                      configured direction.exclude those port pins from refreshing that are configured
 *                      as pin direction changeable during runtime.
 *                      This function is available if the PORT_SET_PIN_MODE_API is set STD_ON
 *
 * \endverbatim
 * Traceability       : SWSR_PORT_010 SWSR_PORT_045 SWSR_PORT_046 SWSR_PORT_055
 *                      SWSR_PORT_056 SW_SM001
 *******************************************************************************************************/
void Port_RefreshPortDirection(void)
{
    /* ----- Local Variables ---------------------------------------------- */
    /* Variable used to store current error status */
    Std_ReturnType errStatus;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module states */
    errStatus = Port_EnterCheck(PORT_SID_REFRESH_PORT_DIRECTION);

    if (E_OK == errStatus)
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #20 Set pin direction */
        errStatus = Port_Ip_RefreshPortDirection(Port_InitConfigPtr->padCfgPtr, Port_InitConfigPtr->num);
    } /* else not needed */

    /* ----- Development Error Report --------------------------------------- */
    /* #30 Report errors if any occurred */
#if ((STD_ON == PORT_DEV_ERROR_DETECT) || (PORT_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == PORT_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)PORT_MODULE_ID, (uint8)PORT_INSTANCE_ID,
                              (uint8)PORT_SID_REFRESH_PORT_DIRECTION, (uint8)errStatus);
#endif /** #if (STD_ON == PORT_DEV_ERROR_DETECT) */
#if (STD_ON == PORT_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)PORT_MODULE_ID, (uint8)PORT_INSTANCE_ID,
                                   (uint8)PORT_SID_REFRESH_PORT_DIRECTION, (uint8)errStatus);
#endif /** #if (STD_ON == PORT_SAFETY_ENABLE) */
    } /* else not needed */

#else
    {
        /* #40 Dummy assignment avoid compiler warning */
        PORT_DUMMY_STATEMENT(errStatus);
    }
#endif /** #if ((STD_ON == PORT_DEV_ERROR_DETECT) || (PORT_SAFETY_ENABLE)) */
}

#if (PORT_VERSION_INFO_API == STD_ON)
/** *****************************************************************************************************
 * \brief Get version information of this driver.
 *
 * \verbatim
 * Syntax             : void Port_GetVersionInfo(Std_VersionInfoType* versioninfo)
 *
 * Service ID[hex]    : 0x03
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : versioninfo - Pointer to where to store the version information of this module.
 *
 * Return value       : None
 *
 * Description        : This function returns the version information of this module
 *                      The version information include : Module ID, Vendor ID.
 *                      Vendor specific version numbers.
 *   -                  This function is available if the PORT_VERSION_INFO_API is set STD_ON
 *
 * \endverbatim
 * Traceability       : SWSR_PORT_017 SWSR_PORT_018 SWSR_PORT_048 SWSR_PORT_049
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
void Port_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
    /* ----- Local Variables ---------------------------------------------- */
    /* Variable used to store current error status */
    Std_ReturnType errStatus = E_OK;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check input parameters for plausibility */
    if (NULL_PTR == versioninfo)
    {
        errStatus = PORT_E_PARAM_POINTER;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #20 Retrieve version information */
        versioninfo->vendorID = PORT_VENDOR_ID;
        versioninfo->moduleID = PORT_MODULE_ID;
        versioninfo->sw_major_version = PORT_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = PORT_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = PORT_SW_PATCH_VERSION;
    }

    /* ----- Development Error Report --------------------------------------- */
    /* #30 Report errors if any occurred */
#if ((STD_ON == PORT_DEV_ERROR_DETECT) || (PORT_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == PORT_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)PORT_MODULE_ID, (uint8)PORT_INSTANCE_ID, PORT_SID_GET_VERSION_INFO,
                              PORT_E_PARAM_POINTER);
#endif /** #if STD_ON == PORT_DEV_ERROR_DETECT*/
#if (STD_ON == PORT_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)PORT_MODULE_ID, (uint8)PORT_INSTANCE_ID,
                                   PORT_SID_GET_VERSION_INFO, PORT_E_PARAM_POINTER);
#endif /** #if (STD_ON == PORT_SAFETY_ENABLE) */
    } /* else not needed */

#else
    {
        /* #40 Dummy assignment avoid compiler warning */
        PORT_DUMMY_STATEMENT(errStatus);
    }
#endif /** #if ((STD_ON == PORT_DEV_ERROR_DETECT) || (PORT_SAFETY_ENABLE)) */
}
#endif/** #if (PORT_VERSION_INFO_API == STD_ON) */

#if (STD_ON == PORT_SET_PIN_MODE_API)
/** *****************************************************************************************************
 * \brief Set the port pin mode of the referenced pin during runtime.
 *
 * \verbatim
 * Syntax             : void Port_SetPinMode(Port_PinType Pin,Port_PinModeType Mode)
 *
 * Service ID[hex]    : 0x04
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : Pin -  Port Pin ID number
 *                      Mode -  New Port Pin mode to be set on port pin.
 *
 * Return value       : None
 *
 * Description        : This function shall set the port pin mode of the referenced pin during runtime.
 *                      Only pin configured to modeChangable can be set the port pin mode during
 *                      runtime.
 *                      This function is available if the PORT_SET_PIN_MODE_API is set STD_ON
 *
 * \endverbatim
 * Traceability       : SWSR_PORT_031 SWSR_PORT_050 SWSR_PORT_051 SWSR_PORT_052
 *                      SWSR_PORT_055 SWSR_PORT_056 SW_SM001
 *******************************************************************************************************/
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode)
{
    /* ----- Local Variables ---------------------------------------------- */
    /* Variable used to store current error status */
    Std_ReturnType errStatus;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module states */
    errStatus = Port_EnterCheck(PORT_SID_SET_PIN_MODE);

    if (E_OK == errStatus)
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #20 Set pin mode */
        errStatus = Port_Ip_SetPinMode(Pin, Mode, Port_InitConfigPtr->padCfgPtr, Port_InitConfigPtr->num);
    }/* else not needed */

    /* ----- Development Error Report --------------------------------------- */
    /* #30 Report errors if any occurred */
#if ((STD_ON == PORT_DEV_ERROR_DETECT) || (PORT_SAFETY_ENABLE))

    if (E_OK != errStatus)
    {
#if (STD_ON == PORT_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)PORT_MODULE_ID, (uint8)PORT_INSTANCE_ID, (uint8)PORT_SID_SET_PIN_MODE,
                              (uint8)errStatus);
#endif /** #if (STD_ON == PORT_DEV_ERROR_DETECT) */
#if (STD_ON == PORT_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)PORT_MODULE_ID, (uint8)PORT_INSTANCE_ID,
                                   (uint8)PORT_SID_SET_PIN_MODE, (uint8)errStatus);
#endif /** #if (STD_ON == PORT_SAFETY_ENABLE) */
    }/* else not needed */

#else
    {
        /* #40 Dummy assignment avoid compiler warning */
        PORT_DUMMY_STATEMENT(errStatus);
    }
#endif /** #if ((STD_ON == PORT_DEV_ERROR_DETECT) || (PORT_SAFETY_ENABLE)) */

}
#endif /** #if (STD_ON == PORT_SET_PIN_MODE_API) */

#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"

#ifdef __cplusplus
}
#endif
/* End of file */
