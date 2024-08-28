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
 * \file     Port_Ip.c                                                                                  *
 * \brief    AUTOSAR 4.3.1 MCAL Port Driver                                                              *
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
#include "RegHelper.h"
#include "Port_Ip.h"
#include "Port_Fault.h"
/********************************************************************************************************
 *                                 Private Macro definition                                             *
 *******************************************************************************************************/
/* Spell pin and mux into one field*/
#define PINCTRL_IS_IDX(pin, mux)   (((pin) << 8) + (mux))

/* check last ret, if ret is OK, execute function, otherwise do nothing*/
#define CALL_RET_CHECK(ret, funcall) \
    if (E_OK == (ret)) { (ret) = (funcall); }

#if (PORT_ANALOG_PIN_ENABLE == STD_ON)
#define SCR_SW_TYPE_OFFSET (0x1000U)
/* anlog pin SCR register information */
#define SCR_ANALOG_PAD(id) \
    {GPIO_##id, PORT_SCR_CFG_APD_A_##id##_CTRL_3_0}
#endif /** #if (PORT_ANALOG_PIN_ENABLE == STD_ON)*/

/********************************************************************************************************
 *                                  Private Function Declarations                                       *
 *******************************************************************************************************/
/* port pinctrl operation config function */
/** Traceability       : SW_SM008 */
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
static uint8 Port_Ip_ConfigFun(const Port_PinctrlType *pinctrlPtr, uint32 pin,
                               Port_PinConfigType config, uint32 value);
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"


/********************************************************************************************************
 *                                  Private Variable Definitions                                        *
 *******************************************************************************************************/
/** Traceability       : SW_SM008 */
#define PORT_START_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

/* port pinctrl operation define, provide to port pin controller*/
static const Port_OpsType Port_PinctrlOps =
{
    /*port pinctrl operation config function*/
    .config = Port_Ip_ConfigFun,
};

/*
* port pinctrl safety pinctrl device,
* provide safety port register base and offset information
*/
static const Port_ContrlType Port_SafetyDev =
{
    /*safety port pinctrl device base address*/
    .base          = PORT_IOMUXC_SF_BASE,
    /*safety port pinctrl device pad reg offset*/
    .padRegOffset  = PORT_PAD_CONFIG_REG_OFFSET,
    /*safety port pinctrl device mux reg offset*/
    .muxRegOffset  = PORT_MUX_CONFIG_REG_OFFSET,
};

#ifndef SEMIDRIVE_E3_LITE_SERIES
/*
port pinctrl ap pinctrl device,
provide ap port register base and offset information
*/
static const Port_ContrlType Port_ApDev =
{
    /*ap port pinctrl device base address*/
    .base          = PORT_IOMUXC_AP_BASE,
    /*ap port pinctrl device pad reg offset*/
    .padRegOffset  = PORT_PAD_CONFIG_REG_OFFSET,
    /*ap port pinctrl device mux reg offset*/
    .muxRegOffset  = PORT_MUX_CONFIG_REG_OFFSET,
};
#endif

/*port safety pinctrl controller, provide to controll safety domain pins*/
/*PRQA S 3218 1*/
static const Port_PinctrlType Port_PinctrlSafety =
{
    /*safety domain pin start index*/
    .pinStart = PORT_SAFETY_PIN_START,
    /*safety domain pin number*/
    .pinNr = PORT_SAFETY_PIN_NUM,
    /*safety domain pin device pointer*/
    .dev = &Port_SafetyDev,
    /*safety domain pin operation pointer*/
    .ops = &Port_PinctrlOps,
};
#ifndef SEMIDRIVE_E3_LITE_SERIES
/*port ap pinctrl controller, provide to controll ap domain pins*/
/*PRQA S 3218 1*/
static const Port_PinctrlType Port_PinctrlAp =
{
    /*ap domain pin start index*/
    .pinStart = PORT_AP_PIN_START,
    /*ap domain pin number*/
    .pinNr = PORT_AP_PIN_NUM,
    /*ap domain pin device pointer*/
    .dev = &Port_ApDev,
    /*ap domain pin operation pointer*/
    .ops = &Port_PinctrlOps,
};
#endif

#if (PORT_ANALOG_PIN_ENABLE == STD_ON)
/*analog port pin scr, provide analog pin scr information, fpr GPIO_A/GPIO_B/GPIO_C only. */
/*PRQA S 3218 1*/
static const Port_AnalogScrType Port_AnalogScr[PORT_ANALOG_SCR_NUM] =
{
    SCR_ANALOG_PAD(A0),  SCR_ANALOG_PAD(A1),  SCR_ANALOG_PAD(A2),  SCR_ANALOG_PAD(A3),
    SCR_ANALOG_PAD(A4),  SCR_ANALOG_PAD(A5),  SCR_ANALOG_PAD(A6),  SCR_ANALOG_PAD(A7),
    SCR_ANALOG_PAD(A8),  SCR_ANALOG_PAD(A9),  SCR_ANALOG_PAD(A10), SCR_ANALOG_PAD(A11),
    SCR_ANALOG_PAD(A12), SCR_ANALOG_PAD(A13), SCR_ANALOG_PAD(A14), SCR_ANALOG_PAD(A15),
    SCR_ANALOG_PAD(B0),  SCR_ANALOG_PAD(B1),  SCR_ANALOG_PAD(B2),  SCR_ANALOG_PAD(B3),
    SCR_ANALOG_PAD(B4),  SCR_ANALOG_PAD(B5),  SCR_ANALOG_PAD(B6),  SCR_ANALOG_PAD(B7),
    SCR_ANALOG_PAD(B8),  SCR_ANALOG_PAD(B9),  SCR_ANALOG_PAD(B10), SCR_ANALOG_PAD(B11),
    SCR_ANALOG_PAD(B12), SCR_ANALOG_PAD(B13), SCR_ANALOG_PAD(B14), SCR_ANALOG_PAD(B15),
    SCR_ANALOG_PAD(C0),  SCR_ANALOG_PAD(C1),  SCR_ANALOG_PAD(C2),  SCR_ANALOG_PAD(C3),
    SCR_ANALOG_PAD(C4),  SCR_ANALOG_PAD(C5),  SCR_ANALOG_PAD(C6),  SCR_ANALOG_PAD(C7),
#ifndef SEMIDRIVE_E3_LITE_SERIES
    SCR_ANALOG_PAD(C8),  SCR_ANALOG_PAD(C9),  SCR_ANALOG_PAD(C10), SCR_ANALOG_PAD(C11),
    SCR_ANALOG_PAD(C12), SCR_ANALOG_PAD(C13), SCR_ANALOG_PAD(C14), SCR_ANALOG_PAD(C15),
#endif /*SEMIDRIVE_E3_LITE_SERIES*/
};
#endif /** #if (PORT_ANALOG_PIN_ENABLE == STD_ON)*/

#define PORT_STOP_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
/********************************************************************************************************
 *                               Private Inline Function Declarations                                    *
 *******************************************************************************************************/
/** *****************************************************************************************************
 * Syntax             : static inline boolean
 *                      Port_Ip_IsCtrlPin(const Port_PinctrlType *pinctrlPtr, uint32 socPin)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : pinctrlPtr - Pointer to pinctrl device
 *                      socPin - soc pin index
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : TRUE - SOC pin index in the pinctrl device
                        FALSE- SOC pin index NOT in the pinctrl device
 *
 * Description        : This function returns TRUE if the SOC pin is controlled by specified pinctrl device
 * Traceability       : SWSR_PORT_003 SW_SM006
 *******************************************************************************************************/
static inline boolean Port_Ip_IsCtrlPin(const Port_PinctrlType *pinctrlPtr, uint32 socPin)
{
    boolean ret = FALSE;

    if ((socPin >= pinctrlPtr->pinStart) && (socPin < (pinctrlPtr->pinStart + pinctrlPtr->pinNr)))
    {
        ret = TRUE;
    }

    return ret;
}
/** *****************************************************************************************************
 * Syntax             : static inline uint32
 *                      Port_Ip_ToSocPin(const Port_PinctrlType *pinctrlPtr, uint32 ctrlPin)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : pinctrlPtr - Pointer to pinctrl device
 *                      ctrlPin - Controller local pin index
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : SOC pin index
 *
 * Description        : Convert pinctrl local pin index to SOC pin index.
 *******************************************************************************************************/
static inline uint32
Port_Ip_ToSocPin(const Port_PinctrlType *pinctrlPtr, uint32 ctrlPin)
{
    return pinctrlPtr->pinStart + ctrlPin;
}
/** *****************************************************************************************************
 * Syntax             : static inline uint32
 *                      Port_Ip_ToCtrlPin(const Port_PinctrlType *pinctrlPtr, uint32 socPin)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : pinctrlPtr - Pointer to pinctrl device
 *                      socPin - SOC pin index
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Controller local pin index
 *
 * Description        : Convert SOC pin index to pinctl local pin index.
 *******************************************************************************************************/
static inline uint32
Port_Ip_ToCtrlPin(const Port_PinctrlType *pinctrlPtr, uint32 socPin)
{
    return socPin - pinctrlPtr->pinStart;
}
/** *****************************************************************************************************
 * Syntax             : static inline uint8 Port_Ip_Config(const Port_PinctrlType *pinctrlPtr, uint32 pin,
 *                                                       Port_PinConfigType config, uint32 value)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : pinctrlPtr - Pointer to pinctrl device which controls the pin
 *                      pin - SOC pin index
 *                      config - Configuration options type
 *                      value - Configuration value, depending on config type.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : ErrorId
 *
 * Description        : Configure each properties of the PIN.
 * Traceability       : SWSR_PORT_003 SW_SM006
 *******************************************************************************************************/
static inline uint8 Port_Ip_Config(const Port_PinctrlType *pinctrlPtr, uint32 pin,
                                   Port_PinConfigType config, uint32 value)
{
    uint8 ret = PORT_E_PARAM_POINTER;

    if ((NULL_PTR != pinctrlPtr) &&  (NULL_PTR != pinctrlPtr->ops)
            && (NULL_PTR != pinctrlPtr->ops->config))
    {
        if (TRUE == Port_Ip_IsCtrlPin(pinctrlPtr, pin))
        {
            ret = pinctrlPtr->ops->config(pinctrlPtr, Port_Ip_ToCtrlPin(pinctrlPtr, pin), config, value);
        }
    }

    return ret;
}

/** *****************************************************************************************************
 * Syntax             : static inline uint32 Port_Ip_PinReg(uint32 base, uint32 offset, uint32 pin)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : base - pin register base address
 *                      offset - pin register offset
 *                      pin - pin index
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : port pin address
 *
 * Description        : Calculate the register address of the pin
 *******************************************************************************************************/
static inline uint32 Port_Ip_PinReg(uint32 base, uint32 offset, uint32 pin)
{
    return base + offset + (pin * 4U);
}
/** *****************************************************************************************************
 * Syntax             : static inline void
 *                      Port_Ip_WritePinReg(uint32 base, uint32 offset, uint32 pin, uint32 val)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : base - pin register base address
 *                      offset - pin register offset
 *                      pin - pin index
 *                      val - value to write
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Write value to the register address of the pin
 *******************************************************************************************************/
static inline void Port_Ip_WritePinReg(uint32 base, uint32 offset, uint32 pin, uint32 val)
{
    writel(val, Port_Ip_PinReg(base, offset, pin));
}
/** *****************************************************************************************************
 * Syntax             : static inline uint32 Port_Ip_ReadPinReg(uint32 base, uint32 offset, uint32 pin)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : base - pin register base address
 *                      offset - pin register offset
 *                      pin - pin index
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : value of pin register
 *
 * Description        : Read value from the register address of the pin
 *******************************************************************************************************/
static inline uint32 Port_Ip_ReadPinReg(uint32 base, uint32 offset, uint32 pin)
{
    return readl(Port_Ip_PinReg(base, offset, pin));
}
/** *****************************************************************************************************
 * Syntax             : static inline void Port_Ip_ModifyPinReg(uint32 base, uint32 offset, uint32 pin,
 *                                 uint32 bit, uint32 width, uint32 val)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : base - pin register base address
 *                      offset - pin register offset
 *                      pin - pin index
 *                      bit - BIT to modify
 *                      width - width to modify
 *                      val - value to write
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : modify value of the register address of the pin
 *******************************************************************************************************/
static inline void Port_Ip_ModifyPinReg(uint32 base, uint32 offset, uint32 pin,
                                        uint32 bit, uint32 width, uint32 val)
{
    uint32 v = Port_Ip_ReadPinReg(base, offset, pin);
    v &= ~(BIT_MASK(width) << bit);
    v |= (val & BIT_MASK(width)) << bit;
    Port_Ip_WritePinReg(base, offset, pin, v);
}

/** *****************************************************************************************************
 * Syntax             : static uint8 Port_Ip_SetOpenDrain(const Port_ContrlType *ctrlPtr, uint32 pin, uint32 value)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : ctrlPtr - pointer to port device
 *                      pin - controller pin index
 *                      value - open drain/push pull to set
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : ErrorId
 *
 * Description        : set open drain/push pull for the pin
 * Traceability       : SWSR_PORT_017 SWSR_PORT_018 SWSR_PORT_006 SW_SM006
 *******************************************************************************************************/
static inline uint8 Port_Ip_SetOpenDrain(const Port_ContrlType *ctrlPtr, uint32 pin, uint32 value)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint8 ret = E_OK;

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Check input parameters for plausibility */
    /* The controller must have MUX function. */
    if ((NULL_PTR == ctrlPtr) || (0U == ctrlPtr->muxRegOffset)
            || (((uint32)PORT_PIN_OPEN_DRAIN !=  value) &&  ((uint32)PORT_PIN_PUSH_PULL != value)))
    {
        ret = PORT_E_PARAM_PIN;
    }
    else
    {
        /* #20 set open drain/push pull*/
        Port_Ip_ModifyPinReg(ctrlPtr->base, ctrlPtr->muxRegOffset, pin, MUX_ODE_SHIFT, MUX_ODE_WIDTH,
                             value);
    }

    return ret;
}
/** *****************************************************************************************************
 * Syntax             : static uint8 Port_Ip_SetPull(const Port_ContrlType *ctrlPtr, uint32 pin, uint32 value)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : ctrlPtr - pointer to port device
 *                      pin - controller pin index
 *                      value - pulls to set
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : ErrorId
 *
 * Description        : set pulls mode for the pin
 * Traceability       : SWSR_PORT_017 SWSR_PORT_018 SWSR_PORT_006 SW_SM006
 *******************************************************************************************************/
static inline uint8 Port_Ip_SetPull(const Port_ContrlType *ctrlPtr, uint32 pin, uint32 value)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint8 ret = E_OK;

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Check input parameters for plausibility */
    if ((NULL_PTR == ctrlPtr) || (0U == ctrlPtr->padRegOffset) || (value > (uint32)PORT_PIN_PULL_UP))
    {
        ret = PORT_E_PARAM_PIN;
    }
    else
    {
        /* #20 set pulls mode*/
        Port_Ip_ModifyPinReg(ctrlPtr->base, ctrlPtr->padRegOffset, pin, PAD_PULL_SHIFT, PAD_PULL_WIDTH,
                             value);
    }

    return ret;
}
/** *****************************************************************************************************
 * Syntax             : static uint8 Port_Ip_SetDriveStrength(const Port_ContrlType *ctrlPtr, uint32 pin, uint32 value)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : ctrlPtr - pointer to port device
 *                      pin - controller pin index
 *                      value - drive strength to set
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : ErrorId
 *
 * Description        : set drive strength for the pin
 * Traceability       : SWSR_PORT_017 SWSR_PORT_018 SWSR_PORT_006 SW_SM006
 *******************************************************************************************************/
static inline uint8 Port_Ip_SetDriveStrength(const Port_ContrlType *ctrlPtr, uint32 pin,
        uint32 value)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint8 ret = E_OK;

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Check input parameters for plausibility */
    if ((NULL_PTR == ctrlPtr) || (0U == ctrlPtr->padRegOffset) || (value > (uint32)PORT_PIN_DS_12MA))
    {
        ret = PORT_E_PARAM_PIN;
    }
    else
    {
        /* #20 set drive strength*/
        Port_Ip_ModifyPinReg(ctrlPtr->base, ctrlPtr->padRegOffset, pin, PAD_DS_SHIFT, PAD_DS_WIDTH, value);
    }

    return ret;
}
/** *****************************************************************************************************
 * Syntax             : static uint8 Port_Ip_SetInputSchmitt(const Port_ContrlType *ctrlPtr, uint32 pin, uint32 value)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : ctrlPtr - pointer to port device
 *                      pin - controller pin index
 *                      value - schmitt mode to set
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : ErrorId
 *
 * Description        : set schmitt mode for the pin
 * Traceability       : SWSR_PORT_017 SWSR_PORT_018 SWSR_PORT_006 SW_SM006
 *******************************************************************************************************/
static inline uint8 Port_Ip_SetInputSchmitt(const Port_ContrlType *ctrlPtr, uint32 pin,
        uint32 value)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint8 ret = E_OK;

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Check input parameters for plausibility */
    if ((NULL_PTR == ctrlPtr) || (0U == ctrlPtr->padRegOffset)
            || (((uint32)PORT_PIN_IS_CMOS_SCHMITT != value) && ((uint32)PORT_PIN_IS_CMOS != value)))
    {
        ret = PORT_E_PARAM_PIN;
    }
    else
    {
        /* #20 set schmitt mode*/
        Port_Ip_ModifyPinReg(ctrlPtr->base, ctrlPtr->padRegOffset, pin, PAD_IS_SHIFT, PAD_IS_WIDTH, value);
    }

    return ret;
}
/** *****************************************************************************************************
 * Syntax             : static uint8 Port_Ip_SetSlewRate(const Port_ContrlType *ctrlPtr, uint32 pin, uint32 value)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : ctrlPtr - pointer to port device
 *                      pin - controller pin index
 *                      value - slew rate to set
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : ErrorId
 *
 * Description        : set slew rate for the pin
 * Traceability       : SWSR_PORT_017 SWSR_PORT_018 SWSR_PORT_006 SW_SM006
 *******************************************************************************************************/
static inline uint8 Port_Ip_SetSlewRate(const Port_ContrlType *ctrlPtr, uint32 pin, uint32 value)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint8 ret = E_OK;

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Check input parameters for plausibility */
    if ((NULL_PTR == ctrlPtr) || (0U == ctrlPtr->padRegOffset) || (((uint32)PORT_PIN_SR_FAST != value)
            && ((uint32)PORT_PIN_SR_SLOW != value)))
    {
        ret = PORT_E_PARAM_PIN;
    }
    else
    {
        /* #20 set slew rate*/
        Port_Ip_ModifyPinReg(ctrlPtr->base, ctrlPtr->padRegOffset, pin, PAD_SR_SHIFT, PAD_SR_WIDTH, value);
    }

    return ret;
}
/** *****************************************************************************************************
 * Syntax             : static uint8 Port_Ip_SetModeSelect(const Port_ContrlType *ctrlPtr, uint32 pin, uint32 value)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : ctrlPtr - pointer to port device
 *                      pin - controller pin index
 *                      value - mode select to set
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : ErrorId
 *
 * Description        : set mode select for the pin, for analog pin only
 * Traceability       : SWSR_PORT_017 SWSR_PORT_018 SWSR_PORT_006 SW_SM006
 *******************************************************************************************************/
static inline uint8 Port_Ip_SetModeSelect(const Port_ContrlType *ctrlPtr, uint32 pin, uint32 value)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint8 ret = E_OK;

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Check input parameters for plausibility */
    if ((NULL_PTR == ctrlPtr) || (0U == ctrlPtr->padRegOffset)
            || (((uint32)PORT_PIN_LEVEL_LOW != value) && ((uint32)PORT_PIN_LEVEL_HIGH != value)))
    {
        ret = PORT_E_PARAM_PIN;
    }
    else
    {
        /* #20 set mode select for analog pin*/
        Port_Ip_ModifyPinReg(ctrlPtr->base, ctrlPtr->padRegOffset, pin, PAD_MS_SHIFT, PAD_MS_WIDTH, value);
    }

    return ret;
}
/********************************************************************************************************
 *                                  Private Function Declarations                                       *
 *******************************************************************************************************/
/** *****************************************************************************************************
 * Syntax             : static void Port_Ip_SetInputSelectReg(uint32 pin, uint32 mux)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : pin - pin index to search input select
 *                      mux - pin mux to search input select
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : set the input select for input pin and mux
 * Traceability       : SWSR_PORT_004
 *******************************************************************************************************/
static void Port_Ip_SetInputSelectReg(uint32 pin, uint32 mux)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint32 left = 0U;
    uint32 right = (PORT_INPUT_SELECT_NUM - 1U);
    uint32 mid;
    const Port_InputSelectType *selectPtr;

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Using the dichotomy lookup table,
            the table need to be arranged in pin-mux order from smallest to largest*/
    while (left <= right)
    {
        mid = (left + right) / 2U;
        selectPtr = &Port_PinctrlIs[mid];

        /* #40 The corresponding item is found*/
        if (PINCTRL_IS_IDX(selectPtr->pin, selectPtr->mux) == PINCTRL_IS_IDX(pin, mux))
        {
            writel(selectPtr->value, selectPtr->base + selectPtr->offset);
            break;
            /* #20 Need to look in the first half*/
        }
        else if (PINCTRL_IS_IDX(selectPtr->pin, selectPtr->mux) > PINCTRL_IS_IDX(pin, mux))
        {
            right = mid - 1U;
            /* #30 Need to look in the back half*/
        }
        else
        {
            left = mid + 1U;
        }
    }
}
/** *****************************************************************************************************
 * Syntax             : static uint8 Port_Ip_SetFunction
 *                              (const Port_ContrlType *ctrlPtr, uint32 pin, uint32 value, uint32 socPin)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : ctrlPtr - pointer to port device
 *                      pin - controller pin index
 *                      value - mux to set
 *                      socPin - soc pin index
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : ErrorId
 *
 * Description        : set mux for the pin
 * Traceability       : SWSR_PORT_017 SWSR_PORT_018 SWSR_PORT_004 SW_SM006
 *******************************************************************************************************/
static uint8 Port_Ip_SetFunction(const Port_ContrlType *ctrlPtr, uint32 pin, uint32 value,
                                 uint32 socPin)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint8 ret = E_OK;

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Check input parameters for plausibility */
    /* The controller must have MUX function. */
    if ((NULL_PTR == ctrlPtr) || (0U == ctrlPtr->muxRegOffset) || (value > (uint32)PORT_PIN_MUX_ALT9))
    {
        ret = PORT_E_PARAM_PIN;
    }
    else
    {
        /* #20 set input select*/
        Port_Ip_SetInputSelectReg(socPin, value);
        /* #30 set pin mux*/
        Port_Ip_ModifyPinReg(ctrlPtr->base, ctrlPtr->muxRegOffset, pin, MUX_FUNC_SHIFT, MUX_FUNC_WIDTH,
                             value);
    }

    return ret;
}
/** *****************************************************************************************************
 * Syntax             : static uint8 Port_Ip_SetForceInput(const Port_ContrlType *ctrlPtr, uint32 pin, uint32 value)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : ctrlPtr - pointer to port device
 *                      pin - controller pin index
 *                      value - force input to set
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : ErrorId
 *
 * Description        : set force input for the pin
 * Traceability       : SWSR_PORT_017 SWSR_PORT_018 SWSR_PORT_006 SW_SM006
 *******************************************************************************************************/
static uint8 Port_Ip_SetForceInput(const Port_ContrlType *ctrlPtr, uint32 pin, uint32 value)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint8 ret = E_OK;
    uint32 fin;
    uint32 fv;

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Check input parameters for plausibility */
    if ((NULL_PTR == ctrlPtr) || (0U == ctrlPtr->muxRegOffset)
            || (value > (uint32)PORT_PIN_FORCE_INPUT_LOW))
    {
        ret = PORT_E_PARAM_PIN;
    }
    else
    {
        /* #20 Converts to register corresponding value*/
        if (value <= (uint32)PORT_PIN_FORCE_INPUT_ENABLE)
        {
            fin = value;
            fv = PAD_FORCE_INPUT_VALUE_0;
        }
        else
        {
            fin = PAD_INPUT_FORCE_DISABLE;

            if (value == (uint32)PORT_PIN_FORCE_INPUT_HIGH)
            {
                fv = PAD_FORCE_INPUT_VALUE_1;
            }
            else
            {
                fv = PAD_FORCE_INPUT_VALUE_0;
            }
        }

        /* #30 set force input, include fin and fv*/
        Port_Ip_ModifyPinReg(ctrlPtr->base, ctrlPtr->muxRegOffset, pin, MUX_FIN_SHIFT, MUX_FIN_WIDTH, fin);
        Port_Ip_ModifyPinReg(ctrlPtr->base, ctrlPtr->muxRegOffset, pin, MUX_FV_SHIFT, MUX_FV_WIDTH, fv);
    }

    return ret;
}

/** *****************************************************************************************************
 * Syntax             : static uint8 Port_Ip_ConfigFun(const Port_PinctrlType *pinctrlPtr, uint32 pin,
 *                                                       Port_PinConfigType config, uint32 value)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : pinctrlPtr - pointer to port pin controller
 *                      pin - controller pin index
 *                      config - config type
 *                      value - value to set
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : ErrorId
 *
 * Description        : Configure pin parameters. Note that the pin index is controller local index.
 * Traceability       : SWSR_PORT_017 SWSR_PORT_018 SWSR_PORT_055 SWSR_PORT_056
 *                      SWSR_PORT_006 SWSR_PORT_004 SW_SM006
 *******************************************************************************************************/
static uint8 Port_Ip_ConfigFun(const Port_PinctrlType *pinctrlPtr, uint32 pin,
                               Port_PinConfigType config, uint32 value)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint8 ret = E_OK;
    const Port_ContrlType *ctrlPtr;
    uint32 socPin;
    uint32 pinTmp = pin;

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Check input parameters for plausibility */
    if ((NULL_PTR == pinctrlPtr) || (NULL_PTR == pinctrlPtr->dev))
    {
        ret = PORT_E_PARAM_POINTER;
    }
    else
    {
        /* #20 controller local pin to soc pin*/
        ctrlPtr = pinctrlPtr->dev;
        socPin = Port_Ip_ToSocPin(pinctrlPtr, pinTmp);

        if (socPin >= PORT_PIN_NUM)
        {
            ret = PORT_E_PARAM_PIN;
        }
        else if (socPin < PORT_SAFETY_PIN_NUM)
        {
            /*safety domain pin index need +1, for SEM_FAULT(actual pin 0) is not define*/
            pinTmp++;
        }
        else
        {
            /*nothing to do*/
        }

        if (E_OK == ret)
        {
            switch (config)
            {
            case PORT_CONFIG_FUNCTION:
                /* #30 set pin mux*/
                ret = Port_Ip_SetFunction(ctrlPtr, pinTmp, value, socPin);
                break;

            case PORT_CONFIG_DRIVE:
                /* #40 set Open drain or push pull*/
                ret = Port_Ip_SetOpenDrain(ctrlPtr, pinTmp, value);
                break;

            case PORT_CONFIG_PULL:
                /* #50 set pulls mode*/
                ret = Port_Ip_SetPull(ctrlPtr, pinTmp, value);
                break;

            case PORT_CONFIG_DRIVE_STRENGTH:
                /* #60 set pulls mode*/
                ret = Port_Ip_SetDriveStrength(ctrlPtr, pinTmp, value);
                break;

            case PORT_CONFIG_INPUT_SCHMITT:
                /* #70 set schmitt mode*/
                ret = Port_Ip_SetInputSchmitt(ctrlPtr, pinTmp, value);
                break;

            case PORT_CONFIG_SLEW_RATE:
                /* #80 set slew rate*/
                ret = Port_Ip_SetSlewRate(ctrlPtr, pinTmp, value);
                break;

            case PORT_CONFIG_FORCE_INPUT:
                /* #90 set force input*/
                ret = Port_Ip_SetForceInput(ctrlPtr, pinTmp, value);
                break;

            case PORT_CONFIG_MODE_SELECT:
                /* #100 set mode select for analog pin*/
                ret = Port_Ip_SetModeSelect(ctrlPtr, pinTmp, value);
                break;

            default:
                ret = PORT_E_CONFIG_TYPE;
                break;
            }
        }
    }

    return ret;
}
#if (PORT_ANALOG_PIN_ENABLE == STD_ON)
/** *****************************************************************************************************
 * Syntax             : static void Port_Ip_AnanolgScrSetBit(const Port_ScrSignalType *signalPtr, uint32 value)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Nor reentrant
 *
 * Parameters (in)    : signalPtr - pointer to scr signal
 *                      value - value to set
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Set analog pin scr signal
 *                      This function is available if the PORT_ANALOG_PIN_ENABLE is set STD_ON
 * Traceability       : SWSR_PORT_017 SWSR_PORT_018 SWSR_PORT_006 SW_SM006
 *******************************************************************************************************/
static Std_ReturnType Port_Ip_AnanolgScrSetBit(const Port_ScrSignalType *signalPtr, uint32 value)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint32 address =  PORT_SCR_SF_BASE + SCR_SW_TYPE_OFFSET;
    Std_ReturnType ret = E_OK;

    /* ----- Implementation ----------------------------------------------- */
    if (NULL_PTR == signalPtr)
    {
        ret = PORT_E_PARAM_POINTER;
    }
    else
    {
        /* #10 Find the base address of the scrbit */
        address = address + (((uint32)signalPtr->startBit >> 5U) * 4U);
        /* #20 write value according to startbit and width */
        RMWREG32(address, (signalPtr->startBit % 32U), signalPtr->width, value);
    }

    return ret;
}
#endif /** #if (PORT_ANALOG_PIN_ENABLE == STD_ON)*/
/** *****************************************************************************************************
 * Syntax             : static uint32 Port_Ip_GetChannelBase(uint32 *channelPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : channelPtr - pointer to gpio channel
 *
 * Parameters (out)   : None
 *
 * Return value       : gpio channel base address
 *
 * Description        : get gpio channel base
 * Traceability       : SWSR_PORT_017 SWSR_PORT_018 SWSR_PORT_005 SW_SM006
 *******************************************************************************************************/
static uint32 Port_Ip_GetChannelBase(uint32 *channelPtr)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint32 baseAddr = UINT32_MAX;

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Check input parameters for plausibility */
    if (NULL_PTR != channelPtr)
    {
        if (PORT_SAFETY_PIN_NUM > *channelPtr)
        {
            /* #20 get sf domain gpio base address */
            baseAddr = PORT_GPIO_SF_BASE;
        }

#ifndef SEMIDRIVE_E3_LITE_SERIES
        else if (PORT_PIN_NUM > *channelPtr)
        {
            /* #30 get ap domain gpio base address, and get the local channel id of ap domain*/
            *channelPtr -= PORT_SAFETY_PIN_NUM;
            baseAddr = PORT_GPIO_AP_BASE;

        }

#endif
        else
        {
            /* #40 get invalid base address when channel id out of range*/
            baseAddr = UINT32_MAX;
        }
    }/* else not needed */

    return baseAddr;
}
/** *****************************************************************************************************
 * Syntax             : static uint8 Port_Ip_WriteChannel(uint32 pin, const Port_LevelType level)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : pin - channel id
 *                      level - level value to write
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : ErrorId
 *
 * Description        : write gpio channel level value
 * Traceability       : SWSR_PORT_017 SWSR_PORT_018 SWSR_PORT_055 SWSR_PORT_056
 *                      SWSR_PORT_005 SW_SM006
 *******************************************************************************************************/
static uint8 Port_Ip_WriteChannel(uint32 pin, const Port_LevelType level)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint32 gpioBaseAddr;
    uint32 bitValue;
    uint32 offset;
    uint32 channel = pin;
    uint8 ret = E_OK;

    gpioBaseAddr = Port_Ip_GetChannelBase(&channel);

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Check input parameters for plausibility */
    if (UINT32_MAX == gpioBaseAddr)
    {
        ret = PORT_E_PARAM_PIN;
    }
    else
    {
        /* #20 channel id Corresponding bit  */
        bitValue = 0x01UL << PORT_PIN_BIT(channel);
        /* #30 channel id Corresponding output level address*/
        offset = PORT_GPIO_OFFSET(PORT_GPIO_DATA_OUT, PORT_PIN_OFFSET(channel));

        if (PORT_PIN_LEVEL_HIGH == level)
        {
            /* #40 set Corresponding bit of PORT_SET_PIN register when level is high*/
            REG_WRITE32(bitValue, (gpioBaseAddr + offset + PORT_SET_PIN));
        }
        else if (PORT_PIN_LEVEL_LOW == level)
        {
            /* #50 set Corresponding bit of PORT_CLEAR_PIN register when level is low*/
            REG_WRITE32(bitValue, (gpioBaseAddr + offset + PORT_CLEAR_PIN));
        }
        else
        {
            ret = PORT_E_CONFIG_PARAM;
        }
    }

    return ret;
}
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
/** *****************************************************************************************************
 * Syntax             : static uint8 Port_Ip_SetDirection(uint32 pin, const Port_PinDirectionType direction)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : pin - channel id
 *                      direction - direction value to write
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : ErrorId
 *
 * Description        : write gpio channel direction
 * Traceability       : SWSR_PORT_017 SWSR_PORT_018 SWSR_PORT_055 SWSR_PORT_056
 *                      SWSR_PORT_005 SW_SM006
 *******************************************************************************************************/
static uint8 Port_Ip_SetDirection(uint32 pin, const Port_PinDirectionType direction)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint32 gpioBaseAddr;
    uint32 offset;
    uint32 bitValue;
    uint32 channel = pin;
    uint8 ret = E_OK;

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Check input parameters for plausibility */
    if ((PORT_PIN_OUT != direction) && (PORT_PIN_IN != direction))
    {
        ret = PORT_E_CONFIG_PARAM;
    }
    else
    {
        /* #20 channel id Corresponding base address  */
        gpioBaseAddr = Port_Ip_GetChannelBase(&channel);

        if (UINT32_MAX == gpioBaseAddr)
        {
            ret = PORT_E_PARAM_PIN;
        }
        else
        {
            /* #30 channel id Corresponding bit  */
            bitValue = 0x01UL << PORT_PIN_BIT(channel);
            /* #40 channel id Corresponding direction address*/
            offset = PORT_GPIO_OFFSET(PORT_GPIO_OEN, PORT_PIN_OFFSET(channel));

            if (direction == PORT_PIN_OUT)
            {
                /* #50 set Corresponding bit of PORT_SET_PIN register when direction is output*/
                REG_WRITE32(bitValue, gpioBaseAddr + offset + PORT_SET_PIN);
            }
            else
            {
                /* #60 set Corresponding bit of PORT_SET_PIN register when direction is input*/
                REG_WRITE32(bitValue, gpioBaseAddr + offset + PORT_CLEAR_PIN);
            }
            PortHookBegin_Port_Ip_SetDirection();
            PortHookEnd_Port_Ip_SetDirection();
        }
    }

    return ret;
}
#endif /**#if (PORT_SET_PIN_DIRECTION_API == STD_ON)*/
#if (PORT_EN_PIN_INT_API == STD_ON)
/** *****************************************************************************************************
 * Syntax             : static uint8 Port_Ip_EnableInterruptDetect
 *                                          (uint32 pin, Port_InterruptConfigType interruptType)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : pin - channel id
 *                      interruptType - sync interruptType value to write
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : ErrorId
 *
 * Description        : enable sync interrupt detect
 * Traceability       : SWSR_PORT_017 SWSR_PORT_018 SWSR_PORT_055 SWSR_PORT_056
 *                      SWSR_PORT_005 SW_SM006
 *******************************************************************************************************/
static uint8 Port_Ip_EnableInterruptDetect(uint32 pin, Port_InterruptConfigType interruptType)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint32 gpioBaseAddr;
    uint32 registerVal;
    uint32 channelId = pin;
    uint32 direction;
    uint8 ret = E_OK;

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Check input parameters for plausibility */
    if ((interruptType > PORT_PIN_INTERRUPT_BOTH_EDGE))
    {
        ret = PORT_E_CONFIG_PARAM;
    }
    else
    {
        /* #20 channel id Corresponding base address  */
        gpioBaseAddr = Port_Ip_GetChannelBase(&channelId);

        if (UINT32_MAX == gpioBaseAddr)
        {
            ret = PORT_E_PARAM_PIN;
        }
        else
        {
            /* #30 channel id Corresponding direction address*/
            registerVal = REG_READ32(gpioBaseAddr + PORT_GPIO_OFFSET(PORT_GPIO_OEN,
                                     PORT_PIN_OFFSET(channelId)));

            /* #40 channel id direction from register*/
            direction = (uint32)((registerVal >> PORT_PIN_BIT(channelId)) & 0x1U);

            /* #50 disable the interrupt when direction is output or interrupttype is disable*/
            if (((uint32)PORT_PIN_OUT == direction)
                    || (interruptType == PORT_PIN_INTERRUPT_DISABLED))
            {
                /* clear interrupt status */
                REG_WRITE32((0x1UL << PORT_PIN_BIT(channelId)),
                            (gpioBaseAddr + (PORT_GPIO_OFFSET(PORT_GPIO_SINT_EDGE_CLR,
                                             PORT_PIN_OFFSET(channelId)) + PORT_CLEAR_PIN)));
                /* disable the interrupt */
                REG_WRITE32((0x1UL << PORT_PIN_BIT(channelId)),
                            (gpioBaseAddr + (PORT_GPIO_OFFSET(PORT_GPIO_SINT_EN,
                                             PORT_PIN_OFFSET(channelId)) + PORT_CLEAR_PIN)));
            }
            else
            {
                /* #60 Configure low level interrupts*/
                REG_WRITE32((0x1UL << PORT_PIN_BIT(channelId)),
                            (gpioBaseAddr + (PORT_GPIO_OFFSET(PORT_GPIO_SINT_EN,
                                             PORT_PIN_OFFSET(channelId)) + PORT_CLEAR_PIN)));
                REG_WRITE32((0x1UL << PORT_PIN_BIT(channelId)),
                            (gpioBaseAddr + (PORT_GPIO_OFFSET(PORT_GPIO_SINT_TYPE,
                                             PORT_PIN_OFFSET(channelId)) + PORT_CLEAR_PIN)));
                REG_WRITE32((0x1UL << PORT_PIN_BIT(channelId)),
                            (gpioBaseAddr + (PORT_GPIO_OFFSET(PORT_GPIO_SINT_POL,
                                             PORT_PIN_OFFSET(channelId)) + PORT_CLEAR_PIN)));
                REG_WRITE32((0x1UL << PORT_PIN_BIT(channelId)),
                            (gpioBaseAddr + (PORT_GPIO_OFFSET(PORT_GPIO_SINT_BOTH_EDGE,
                                             PORT_PIN_OFFSET(channelId)) + PORT_CLEAR_PIN)));

                switch (interruptType)
                {
                case PORT_PIN_INTERRUPT_LOW_LEVEL:
                    /* Configure low level interrupts according to the above three sentences */
                    break;

                case PORT_PIN_INTERRUPT_HIGH_LEVEL:
                    /* #70 Configure hign level interrupts*/
                    REG_WRITE32((PORT_INT_POL_HIGH_POS << PORT_PIN_BIT(channelId)),
                                (gpioBaseAddr + (PORT_GPIO_OFFSET(PORT_GPIO_SINT_POL, PORT_PIN_OFFSET(channelId)) + PORT_SET_PIN)));
                    break;

                case PORT_PIN_INTERRUPT_RISING_EDGE:
                    /* #80 Configure rising edge interrupts*/
                    REG_WRITE32((PORT_INT_TYPE_PULSE << PORT_PIN_BIT(channelId)),
                                (gpioBaseAddr + (PORT_GPIO_OFFSET(PORT_GPIO_SINT_TYPE,
                                                 PORT_PIN_OFFSET(channelId)) + PORT_SET_PIN)));
                    REG_WRITE32((PORT_INT_POL_HIGH_POS << PORT_PIN_BIT(channelId)),
                                (gpioBaseAddr + (PORT_GPIO_OFFSET(PORT_GPIO_SINT_POL, PORT_PIN_OFFSET(channelId)) + PORT_SET_PIN)));
                    break;

                case PORT_PIN_INTERRUPT_FALLING_EDGE:
                    /* #90 Configure falling edge interrupts*/
                    REG_WRITE32((PORT_INT_TYPE_PULSE << PORT_PIN_BIT(channelId)),
                                (gpioBaseAddr + (PORT_GPIO_OFFSET(PORT_GPIO_SINT_TYPE,
                                                 PORT_PIN_OFFSET(channelId)) + PORT_SET_PIN)));
                    break;

                case PORT_PIN_INTERRUPT_BOTH_EDGE:
                    /* #100 Configure both edge interrupts*/
                    REG_WRITE32((PORT_INT_TYPE_PULSE << PORT_PIN_BIT(channelId)),
                                (gpioBaseAddr + (PORT_GPIO_OFFSET(PORT_GPIO_SINT_TYPE,
                                                 PORT_PIN_OFFSET(channelId)) + PORT_SET_PIN)));
                    REG_WRITE32((PORT_INT_BOE_BOTH_EDGE << PORT_PIN_BIT(channelId)),
                                (gpioBaseAddr + (PORT_GPIO_OFFSET(PORT_GPIO_SINT_BOTH_EDGE,
                                                 PORT_PIN_OFFSET(channelId)) + PORT_SET_PIN)));
                    break;

                default:
                    ret = PORT_E_CONFIG_PARAM;
                    break;
                }

                /* #110 clear interrupt status and enable the interrupt*/
                /*mask interrupt */
                REG_WRITE32((0x1UL << PORT_PIN_BIT(channelId)),
                            (gpioBaseAddr + (PORT_GPIO_OFFSET(PORT_GPIO_SINT_MASK,
                                             PORT_PIN_OFFSET(channelId)) + PORT_SET_PIN)));

                /* clear interrupt status */
                REG_WRITE32((0x1UL << PORT_PIN_BIT(channelId)),
                            (gpioBaseAddr + (PORT_GPIO_OFFSET(PORT_GPIO_SINT_EDGE_CLR,
                                             PORT_PIN_OFFSET(channelId)) + PORT_CLEAR_PIN)));

                /* unmask interrupt */
                REG_WRITE32((0x1UL << PORT_PIN_BIT(channelId)),
                            (gpioBaseAddr + (PORT_GPIO_OFFSET(PORT_GPIO_SINT_MASK,
                                             PORT_PIN_OFFSET(channelId)) + PORT_CLEAR_PIN)));

                /* enable interrupt */
                REG_WRITE32((0x1UL << PORT_PIN_BIT(channelId)),
                            (gpioBaseAddr + (PORT_GPIO_OFFSET(PORT_GPIO_SINT_EN, PORT_PIN_OFFSET(channelId)) + PORT_SET_PIN)));
            }
        }
    }

    return ret;

}
/** *****************************************************************************************************
 * Syntax             : static uint8 Port_Ip_EnableAsyncInterruptDetect
 *                                          (uint32 channelId, Port_InterruptConfigType interruptType)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : channel - channel id
 *                      interruptType - async interruptType value to write
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : ErrorId
 *
 * Description        : enable async interrupt detect
 * Traceability       : SWSR_PORT_017 SWSR_PORT_018 SWSR_PORT_055 SWSR_PORT_056
 *                      SWSR_PORT_005 SW_SM006
 *******************************************************************************************************/
static uint8 Port_Ip_EnableAsyncInterruptDetect(uint32 pin, Port_InterruptConfigType interruptType)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint32 gpioBaseAddr;
    uint32 registerVal;
    uint32 channelId = pin;
    uint32 direction;
    uint8 ret = E_OK;

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Check input parameters for plausibility */
    if ((PORT_PIN_INTERRUPT_DISABLED != interruptType)
            && ((interruptType < PORT_PIN_ASYC_INTERRUPT_LOW_LEVEL)
                || (interruptType > PORT_PIN_ASYC_INTERRUPT_BOTH_EDGE)))
    {
        ret = PORT_E_CONFIG_PARAM;
    }
    else
    {
        /* #20 channel id Corresponding base address  */
        gpioBaseAddr = Port_Ip_GetChannelBase(&channelId);

        if (UINT32_MAX == gpioBaseAddr)
        {
            ret = PORT_E_PARAM_PIN;
        }
        else
        {
            /* #30 channel id Corresponding direction address*/
            registerVal = REG_READ32(gpioBaseAddr + PORT_GPIO_OFFSET(PORT_GPIO_OEN,
                                     PORT_PIN_OFFSET(channelId)));

            /* #40 channel id direction from register*/
            direction = (uint32)((registerVal >> PORT_PIN_BIT(channelId)) & 0x1U);

            /* #50 disable the interrupt when direction is output or interrupttype is disable*/
            if (((uint32)PORT_PIN_OUT == direction)
                    || (interruptType == PORT_PIN_INTERRUPT_DISABLED))
            {
                /* clear interrupt status */
                REG_WRITE32((0x1UL << PORT_PIN_BIT(channelId)),
                            (gpioBaseAddr + (PORT_GPIO_OFFSET(PORT_GPIO_AINT_EDGE_CLR,
                                             PORT_PIN_OFFSET(channelId)) + PORT_CLEAR_PIN)));
                /* disable the interrupt */
                REG_WRITE32((0x1UL << PORT_PIN_BIT(channelId)),
                            (gpioBaseAddr + (PORT_GPIO_OFFSET(PORT_GPIO_AINT_EN,
                                             PORT_PIN_OFFSET(channelId)) + PORT_CLEAR_PIN)));
            }
            else
            {
                /* #60 Configure low level interrupts*/
                REG_WRITE32((0x1UL << PORT_PIN_BIT(channelId)),
                            (gpioBaseAddr + (PORT_GPIO_OFFSET(PORT_GPIO_AINT_EN,
                                             PORT_PIN_OFFSET(channelId)) + PORT_CLEAR_PIN)));
                REG_WRITE32((0x1UL << PORT_PIN_BIT(channelId)),
                            (gpioBaseAddr + (PORT_GPIO_OFFSET(PORT_GPIO_AINT_TYPE,
                                             PORT_PIN_OFFSET(channelId)) + PORT_CLEAR_PIN)));
                REG_WRITE32((0x1UL << PORT_PIN_BIT(channelId)),
                            (gpioBaseAddr + (PORT_GPIO_OFFSET(PORT_GPIO_AINT_POL,
                                             PORT_PIN_OFFSET(channelId)) + PORT_CLEAR_PIN)));
                REG_WRITE32((0x1UL << PORT_PIN_BIT(channelId)),
                            (gpioBaseAddr + (PORT_GPIO_OFFSET(PORT_GPIO_AINT_BOTH_EDGE,
                                             PORT_PIN_OFFSET(channelId)) + PORT_CLEAR_PIN)));

                switch (interruptType)
                {
                case PORT_PIN_ASYC_INTERRUPT_LOW_LEVEL:
                    /* Configure low level interrupts according to the above three sentences */
                    break;

                case PORT_PIN_ASYC_INTERRUPT_HIGH_LEVEL:
                    /* #70 Configure hign level interrupts*/
                    REG_WRITE32((PORT_INT_POL_HIGH_POS << PORT_PIN_BIT(channelId)),
                                (gpioBaseAddr + (PORT_GPIO_OFFSET(PORT_GPIO_AINT_POL, PORT_PIN_OFFSET(channelId)) + PORT_SET_PIN)));
                    break;

                case PORT_PIN_ASYC_INTERRUPT_RISING_EDGE:
                    /* #80 Configure rising edge interrupts*/
                    REG_WRITE32((PORT_INT_TYPE_PULSE << PORT_PIN_BIT(channelId)),
                                (gpioBaseAddr + (PORT_GPIO_OFFSET(PORT_GPIO_AINT_TYPE,
                                                 PORT_PIN_OFFSET(channelId)) + PORT_SET_PIN)));
                    REG_WRITE32((PORT_INT_POL_HIGH_POS << PORT_PIN_BIT(channelId)),
                                (gpioBaseAddr + (PORT_GPIO_OFFSET(PORT_GPIO_AINT_POL, PORT_PIN_OFFSET(channelId)) + PORT_SET_PIN)));
                    break;

                case PORT_PIN_ASYC_INTERRUPT_FALLING_EDGE:
                    /* #90 Configure falling edge interrupts*/
                    REG_WRITE32((PORT_INT_TYPE_PULSE << PORT_PIN_BIT(channelId)),
                                (gpioBaseAddr + (PORT_GPIO_OFFSET(PORT_GPIO_AINT_TYPE,
                                                 PORT_PIN_OFFSET(channelId)) + PORT_SET_PIN)));
                    break;

                case PORT_PIN_ASYC_INTERRUPT_BOTH_EDGE:
                    /* #100 Configure both edge interrupts*/
                    REG_WRITE32((PORT_INT_TYPE_PULSE << PORT_PIN_BIT(channelId)),
                                (gpioBaseAddr + (PORT_GPIO_OFFSET(PORT_GPIO_AINT_TYPE,
                                                 PORT_PIN_OFFSET(channelId)) + PORT_SET_PIN)));
                    REG_WRITE32((PORT_INT_BOE_BOTH_EDGE << PORT_PIN_BIT(channelId)),
                                (gpioBaseAddr + (PORT_GPIO_OFFSET(PORT_GPIO_AINT_BOTH_EDGE,
                                                 PORT_PIN_OFFSET(channelId)) + PORT_SET_PIN)));
                    break;

                default:
                    ret = PORT_E_CONFIG_PARAM;
                    break;
                }

                /* #110 clear interrupt status and enable the interrupt*/
                /*mask interrupt */
                REG_WRITE32((0x1UL << PORT_PIN_BIT(channelId)),
                            (gpioBaseAddr + (PORT_GPIO_OFFSET(PORT_GPIO_AINT_MASK,
                                             PORT_PIN_OFFSET(channelId)) + PORT_SET_PIN)));

                /* clear interrupt status */
                REG_WRITE32((0x1UL << PORT_PIN_BIT(channelId)),
                            (gpioBaseAddr + (PORT_GPIO_OFFSET(PORT_GPIO_AINT_EDGE_CLR,
                                             PORT_PIN_OFFSET(channelId)) + PORT_CLEAR_PIN)));

                /* unmask interrupt */
                REG_WRITE32((0x1UL << PORT_PIN_BIT(channelId)),
                            (gpioBaseAddr + (PORT_GPIO_OFFSET(PORT_GPIO_AINT_MASK,
                                             PORT_PIN_OFFSET(channelId)) + PORT_CLEAR_PIN)));

                /* enable interrupt */
                REG_WRITE32((0x1UL << PORT_PIN_BIT(channelId)),
                            (gpioBaseAddr + (PORT_GPIO_OFFSET(PORT_GPIO_AINT_EN, PORT_PIN_OFFSET(channelId)) + PORT_SET_PIN)));
            }
        }
    }

    return ret;

}
#endif /** #if (PORT_EN_PIN_INT_API == STD_ON)*/
/** *****************************************************************************************************
 * Syntax             : static Std_ReturnType Port_Ip_DioConfig(const Port_SettingsConfigType *configPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : configPtr - pointer to PINCTRL configuration parameters
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : ErrorId
 *
 * Description        : Dio pin config, for MUX0 only
 * Traceability       : SWSR_PORT_005 SWSR_PORT_007 SWSR_PORT_009 SWSR_PORT_017
 *                      SWSR_PORT_018 SWSR_PORT_040 SWSR_PORT_055 SWSR_PORT_056
 *                      SW_SM006
 *******************************************************************************************************/
static Std_ReturnType Port_Ip_DioConfig(const Port_SettingsConfigType *configPtr)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType ret = E_OK;

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Check input parameters for plausibility */
    if (NULL_PTR == configPtr)
    {
        ret =  PORT_E_PARAM_POINTER;
    }
    else
    {
        /* #20 set initial level value, for output direction only */
        if (PORT_PIN_OUT == configPtr->dataDirection)
        {
            ret = Port_Ip_WriteChannel(configPtr->pinIndex, configPtr->initialValue);
        }/* else not needed */

#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
        /* #30 set direction */
        CALL_RET_CHECK(ret, Port_Ip_SetDirection(configPtr->pinIndex, configPtr->dataDirection));
#endif /** #if (PORT_SET_PIN_DIRECTION_API == STD_ON)*/

#if (PORT_EN_PIN_INT_API == STD_ON)

        /* #40 set interrupt, for input direction only */
        if ((PORT_PIN_IN == configPtr->dataDirection))
        {
            if ( PORT_PIN_INTERRUPT_DISABLED != configPtr->interruptConfig)
            {
                if (configPtr->interruptConfig <= PORT_PIN_INTERRUPT_BOTH_EDGE)
                {
                    /* #50 set sync interrupt */
                    CALL_RET_CHECK(ret, Port_Ip_EnableInterruptDetect(configPtr->pinIndex, configPtr->interruptConfig));
                }
                else
                {
                    /* #40 set async interrupt */
                    CALL_RET_CHECK(ret, Port_Ip_EnableAsyncInterruptDetect(configPtr->pinIndex,
                                   (configPtr->interruptConfig)));
                }
            }/* else not needed */
        }/* else not needed */

#endif /** #if (PORT_EN_PIN_INT_API == STD_ON)*/
    }

    return ret;
}
#if ((PORT_SET_PIN_DIRECTION_API == STD_ON) || (STD_ON == PORT_SET_PIN_MODE_API))
/** *****************************************************************************************************
 * Syntax             : static uint8 Port_Ip_IndexInConfig(Port_PinType pin,
 *                              const Port_SettingsConfigType* configPtr, uint8 configNum, uint8* indexPtr)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : pin - the pin whose index to find.
 *                      configPtr - pointer to PINCTRL configuration parameters, find pin in init configuration.
 *                      configNum - init configuration settings number.
 *
 * Parameters (inout) : pIndex - pointer to pin index.
 *
 * Parameters (out)   : None
 *
 * Return value       : ErrorId
 *
 * Description        : find pin index in the init configuration.
 * Traceability       : SWSR_PORT_08 SWSR_PORT_010 SWSR_PORT_051
 *******************************************************************************************************/
static uint8 Port_Ip_IndexInConfig(Port_PinType pin, const Port_SettingsConfigType *configPtr,
                                   uint8 configNum, uint8 *indexPtr)
{
    /* ----- Local Variables ---------------------------------------------- */
    uint8 index = 0U;
    uint8 ret = E_OK;

    /* ----- Implementation ----------------------------------------------- */
    /* #10 find pin index in the init configuration */
    while (index < configNum)
    {

        if (configPtr[index].pinIndex == pin)
        {
            *indexPtr = index;
            break;
        }/* else not needed */

        index++;
    }

    /* #10 can not find the index in init configuration */
    if (index == configNum)
    {
        ret = PORT_E_PARAM_PIN;
    }/* else not needed */

    return ret;
}
#endif /**#if ((PORT_SET_PIN_DIRECTION_API == STD_ON) || (STD_ON == PORT_SET_PIN_MODE_API))*/
/** *****************************************************************************************************
 * Syntax             : static const Port_PinctrlType* Port_Ip_GetPortBase(uint32 pin)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : pin - pin index.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : pointer to pinctrl controller
 *
 * Description        : get port pin ctroller, safety Pinctrl or ap Pinctrl.
 * Traceability       : SWSR_PORT_017 SWSR_PORT_018 SWSR_PORT_003 SW_SM006
 *******************************************************************************************************/
static const Port_PinctrlType *Port_Ip_GetPortPinCtroller(uint32 pin)
{
    /* ----- Local Variables ---------------------------------------------- */
    const Port_PinctrlType *pinctrlPtr;

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Check input parameters for plausibility */
    if (PORT_SAFETY_PIN_NUM > pin)
    {
        /* #20 safety Pinctrl */
        pinctrlPtr = &Port_PinctrlSafety;
    }

#ifndef SEMIDRIVE_E3_LITE_SERIES
    else if (PORT_PIN_NUM > pin)
    {
        /* #30 ap Pinctrl */
        pinctrlPtr = &Port_PinctrlAp;
    }

#endif
    else
    {
        /* #40 invalid Pinctrl */
        pinctrlPtr = NULL_PTR;
    }

    return pinctrlPtr;
}
/*PRQA S 2755 30*/
/** *****************************************************************************************************
 * \brief This function is internal interface for port init.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Port_Ip_Init(const Port_SettingsConfigType* settingsPtr, uint8 num)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : settingsPtr - Pointer to the init configuration settings
 *                      num - init configuration settings number
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : ErrorId
 *
 * Description        : This function is internal interface for port init.
 * \endverbatim
 * Traceability       : SWSR_PORT_003 SWSR_PORT_004 SWSR_PORT_005 SWSR_PORT_006
 *                      SWSR_PORT_017 SWSR_PORT_018 SWSR_PORT_055 SWSR_PORT_056
 *                      SW_SM006
 *******************************************************************************************************/
Std_ReturnType Port_Ip_Init(const Port_SettingsConfigType *settingsPtr, uint8 num)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType ret = E_OK;
    uint32 i;
    const Port_SettingsConfigType *configPtr;
    const Port_PinctrlType *pinctrlPtr;

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Check input parameters for plausibility */
    if (NULL_PTR == settingsPtr)
    {
        ret = PORT_E_PARAM_POINTER;
    }
    else
    {
        for (i = 0; i < num; i++)
        {
            configPtr = &settingsPtr[i];

            if (configPtr->pinIndex >= PORT_PIN_NUM)
            {
                ret = PORT_E_PARAM_PIN;
            }
            else
            {
                pinctrlPtr = Port_Ip_GetPortPinCtroller(configPtr->pinIndex);
                /* #20 set pin mux */
                ret = Port_Ip_Config(pinctrlPtr, configPtr->pinIndex, PORT_CONFIG_FUNCTION, (uint32)configPtr->mux);
                /* #30 set opendrain/push pull */
                CALL_RET_CHECK(ret, Port_Ip_Config(pinctrlPtr, configPtr->pinIndex, PORT_CONFIG_DRIVE,
                                                   (uint32)configPtr->openDrain));
                /* #40 set pulls mode */
                CALL_RET_CHECK(ret, Port_Ip_Config(pinctrlPtr, configPtr->pinIndex, PORT_CONFIG_PULL,
                                                   (uint32)configPtr->pullConfig));
                /* #50 set drive strength */
                CALL_RET_CHECK(ret, Port_Ip_Config(pinctrlPtr, configPtr->pinIndex, PORT_CONFIG_DRIVE_STRENGTH,
                                                   (uint32)configPtr->driveStrength));
                /* #60 set slew rate */
                CALL_RET_CHECK(ret, Port_Ip_Config(pinctrlPtr, configPtr->pinIndex, PORT_CONFIG_SLEW_RATE,
                                                   (uint32)configPtr->slewRate));
                /* #70 set schmitt mode */
                CALL_RET_CHECK(ret, Port_Ip_Config(pinctrlPtr, configPtr->pinIndex, PORT_CONFIG_INPUT_SCHMITT,
                                                   (uint32)configPtr->inputSelect));
                /* #80 set force input */
                CALL_RET_CHECK(ret, Port_Ip_Config(pinctrlPtr, configPtr->pinIndex, PORT_CONFIG_FORCE_INPUT,
                                                   (uint32)configPtr->forceInput));
                /* #90 set MS when GPIO A/B/C used as digital*/
                /*set bit20 to 0 when GPIO A/B/C used as digital,
                if use default 1, will cause a partial voltage on the pin and deviate from the actual voltage*/
#ifndef SEMIDRIVE_E3_LITE_SERIES

                if ((configPtr->pinIndex >= GPIO_A0) && (configPtr->pinIndex <= GPIO_C15))
#else
                if ((configPtr->pinIndex >= GPIO_A0) && (configPtr->pinIndex <= GPIO_C7))
#endif
                {
                    CALL_RET_CHECK(ret, Port_Ip_Config(pinctrlPtr, configPtr->pinIndex, PORT_CONFIG_MODE_SELECT, 0U));
                }/* else not needed */

                /* #100 set dio config, include level/direction and interrupt*/
                if (configPtr->mux == PORT_PIN_MUX_ALT0)
                {
                    CALL_RET_CHECK(ret, Port_Ip_DioConfig(configPtr));
                }/* else not needed */
            }

            /* #110 any error will break the for cycle*/
            if (E_OK != ret)
            {
                break;
            }/* else not needed */
        }
    }

    return ret;
}
#if (PORT_ANALOG_PIN_ENABLE == STD_ON)
/** *****************************************************************************************************
 * \brief This function is internal interface for analog port init.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Port_Ip_AnalogPadInit
 *                                      (const Port_AnalogConfigType* settingsPtr, const uint8 num)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : settingsPtr - Pointer to the init analog configuration settings
 *                      num - init analog configuration settings number
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : ErrorId
 *
 * Description        : This function is internal interface for analog port init.
 *                      This function is available if the PORT_ANALOG_PIN_ENABLE is set STD_ON
 * \endverbatim
 * Traceability       : SWSR_PORT_003 SWSR_PORT_017 SWSR_PORT_018 SWSR_PORT_055
 *                      SWSR_PORT_056 SWSR_PORT_006 SW_SM006
 *******************************************************************************************************/
Std_ReturnType Port_Ip_AnalogPadInit(const Port_AnalogConfigType *settingsPtr, const uint8 num)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType ret;
    uint32 pin;
    uint32 i;
    const Port_AnalogConfigType *configPtr;
    const Port_PinctrlType *pinctrlPtr;
    boolean flag = FALSE;

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Check input parameters for plausibility */
    if (NULL_PTR == settingsPtr)
    {
        ret = PORT_E_PARAM_POINTER;
    }
    else if (0U == num)
    {
        ret = PORT_E_INIT_FAILED;
    }
    else
    {
        for (i = 0U; i < num; i++)
        {
            configPtr = &settingsPtr[i];

            if (configPtr->pinIndex >= PORT_PIN_NUM)
            {
                ret = PORT_E_PARAM_PIN;
                flag = TRUE;
            }
            else
            {
                pinctrlPtr = Port_Ip_GetPortPinCtroller(configPtr->pinIndex);
                /* check for analog pin*/
#ifndef SEMIDRIVE_E3_LITE_SERIES

                if (configPtr->pinIndex > GPIO_C15)
#else
                if (configPtr->pinIndex > GPIO_C7)
#endif
                {
                    ret = PORT_E_CONFIG_PARAM;
                    flag = TRUE;
                }
                else
                {
                    /* #20 set analog pin mode select*/
                    /* analog input 3v3 or 5v */
                    ret = Port_Ip_Config(pinctrlPtr, configPtr->pinIndex, PORT_CONFIG_MODE_SELECT,
                                         (uint32)configPtr->inputLevel);

                    if (E_OK == ret)
                    {
                        /* #30 set analog pin mode scr signal*/
                        pin = configPtr->pinIndex - GPIO_A0;
                        /* enable analog input */
                        ret = Port_Ip_AnanolgScrSetBit(&Port_AnalogScr[pin].scrBit, 1);

                        if (E_OK != ret)
                        {
                            /* #40 any error will break the for cycle*/
                            flag = TRUE;
                        }
                    }
                    else
                    {
                        /* #40 any error will break the for cycle*/
                        flag = TRUE;
                    }
                }
            }

            if (TRUE == flag)
            {
                break;
            }
        }
    }

    return ret;
}
#endif /** #if (PORT_ANALOG_PIN_ENABLE == STD_ON)*/

#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
/** *****************************************************************************************************
 * \brief This function is internal interface for set direction of Dio pads at runtime.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Port_Ip_SetPinDirection
 *                        (Port_PinType pin, Port_PinDirectionType direction,
 *                         const Port_SettingsConfigType* cfgPtr, uint8 num)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : pin - the pin which direction to be set
 *                      direction - the direction to be set, 0 for input and 1 for output.
 *                      cfgPtr - the pointer to the init configuration, used to check pin direction changable
 *                      num - the number of the init configuration
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : ErrorId
 *
 * Description        : This function is internal interface for set direction of Dio pads at runtime.
 *                      Only gpio pins which pin direct changable can be modifed.
 *                      This function is available if the PORT_SET_PIN_DIRECTION_API is set STD_ON
 * \endverbatim
 * Traceability       : SWSR_PORT_005 SWSR_PORT_008 SWSR_PORT_017 SWSR_PORT_018
 *                      SWSR_PORT_055 SWSR_PORT_056 SW_SM006
 *******************************************************************************************************/
Std_ReturnType Port_Ip_SetPinDirection(Port_PinType pin, Port_PinDirectionType direction,
                                       const Port_SettingsConfigType *cfgPtr, uint8 num)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType ret;
    uint8 index = 0;

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Check input parameters for plausibility */
    if (NULL_PTR == cfgPtr)
    {
        ret = PORT_E_PARAM_POINTER;
    }
    else
    {
        /* #20 find pin index in the init configuration */
        ret = Port_Ip_IndexInConfig(pin, cfgPtr, num, &index);

        if (E_OK == ret)
        {
            /* #30 check pin directChangable */
            if ((FALSE == cfgPtr[index].directChangable) || (PORT_PIN_MUX_ALT0 != cfgPtr[index].mux))
            {
                ret = PORT_E_DIRECTION_UNCHANGEABLE;
            }
            else
            {
                /* #40 modify pin direction */
                ret = Port_Ip_SetDirection(pin, direction);
            }
        }/* else not needed */
    }

    return ret;
}
#endif /** #if (PORT_SET_PIN_DIRECTION_API == STD_ON)*/
/** *****************************************************************************************************
 * \brief This function is internal interface for refresh the pin direction of Dio pads at runtime.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Port_Ip_RefreshPortDirection
 *                                          (const Port_SettingsConfigType* cfgPtr, uint8 num)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : cfgPtr - the pointer to the init configuration, used to check pin direction changable
 *                      num - the number of the init configuration
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : ErrorId
 *
 * Description        : This function is internal interface for refresh the pin direction of Dio pads at runtime.
 *                      Only gpio pins which pin direct not changable can be refreshed.
 * \endverbatim
 * Traceability       : SWSR_PORT_005  SWSR_PORT_010 SWSR_PORT_017 SWSR_PORT_018
 *                      SWSR_PORT_046  SWSR_PORT_047 SWSR_PORT_055 SWSR_PORT_056
 *                      SW_SM006
 *******************************************************************************************************/
Std_ReturnType Port_Ip_RefreshPortDirection(const Port_SettingsConfigType *cfgPtr, uint8 num)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType ret = E_OK;
    uint32 i;

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Check input parameters for plausibility */
    if (NULL_PTR == cfgPtr)
    {
        ret = PORT_E_PARAM_POINTER;
    }
    else
    {
        for (i = 0U; i < num; i++)
        {

            /* #30 check pin directChangable, for gpio setting and pin direct not changable only*/
            if ((PORT_PIN_MUX_ALT0 == cfgPtr[i].mux) && (FALSE == cfgPtr[i].directChangable))
            {
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
                /* #40 refresh pin direction*/
                ret = Port_Ip_SetDirection(cfgPtr[i].pinIndex, cfgPtr[i].dataDirection);

                if (E_OK != ret)
                {
                    /* #50 any error will break the for cycle*/
                    break;
                }/* else not needed */

#endif /** #if (PORT_SET_PIN_DIRECTION_API == STD_ON)*/
            } /* else not needed */
        }
    }

    return ret;
}

#if (STD_ON == PORT_SET_PIN_MODE_API)
/** *****************************************************************************************************
 * \brief This function is internal interface for set pin mode at runtime.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Port_Ip_SetPinMode(Port_PinType pin, Port_PinModeType mode,
 *                                                      const Port_SettingsConfigType* cfgPtr, uint8 num);
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : pin - the pin which mode to be set
 *                      mode - the mode to be set, PORT_PIN_MUX_ALT0~PORT_PIN_MUX_ALT9
 *                      cfgPtr - the pointer to the init configuration, used to check pin mode changable
 *                      num - the number of the init configuration
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : ErrorId
 *
 * Description        : This function is internal interface for set pin mode at runtime.
 *                      Only pin which mode changable can be modifed.
 *                      This function is available if the PORT_SET_PIN_MODE_API is set STD_ON
 * \endverbatim
 * Traceability       : SWSR_PORT_005 SWSR_PORT_017 SWSR_PORT_018 SWSR_PORT_051
 *                      SWSR_PORT_052 SWSR_PORT_053 SWSR_PORT_055 SWSR_PORT_056
 *                      SW_SM006
 *******************************************************************************************************/
Std_ReturnType Port_Ip_SetPinMode(Port_PinType pin, Port_PinModeType mode,
                                  const Port_SettingsConfigType *cfgPtr, uint8 num)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType ret;
    uint8 index = 0;
    const Port_PinctrlType *pinctrlPtr;

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Check input parameters for plausibility */
    if (NULL_PTR == cfgPtr)
    {
        ret = PORT_E_PARAM_POINTER;
    }
    else if (pin >= PORT_PIN_NUM)
    {
        ret = PORT_E_PARAM_PIN;
    }
    else
    {
        pinctrlPtr = Port_Ip_GetPortPinCtroller(pin);

        /* #20 find pin index in the init configuration */
        ret = Port_Ip_IndexInConfig(pin, cfgPtr, num, &index);

        if (E_OK == ret)
        {
            /* #30 check mode directChangable */
            if (FALSE == cfgPtr[index].modeChangable)
            {
                ret = PORT_E_MODE_UNCHANGEABLE;
            }
            else
            {
                /* #40 check mux range */
                if ((mode > PORT_PIN_MUX_ALT9))
                {
                    ret = PORT_E_PARAM_INVALID_MODE;
                }
                else
                {
                    /* #50 modify pin mux */
                    ret = Port_Ip_Config(pinctrlPtr, pin, PORT_CONFIG_FUNCTION, (uint32)mode);
                }
            }
        }/* else not needed */
    }

    return ret;
}
#endif /** #if (STD_ON == PORT_SET_PIN_MODE_API)*/


#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"

#ifdef __cplusplus
}
#endif

/* End of file */
