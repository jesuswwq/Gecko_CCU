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
 *  \file     Port_Ip.h                                                                                 *
 *  \brief    Semidrive. AUTOSAR 4.3.1 MCAL Port_IP Driver                                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/14     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef PORT_IP_H
#define PORT_IP_H
#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Std_Types.h"
#include "RegHelper.h"
#include "Port_Cfg.h"

/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/

/* PORT PIN MUX CONFIG REGISTER */
#define PORT_MUX_CONFIG_REG_OFFSET      (0x2000U)
#define MUX_FUNC_SHIFT                  (0U)
#define MUX_FUNC_WIDTH                  (4U)
#define MUX_ODE_SHIFT                   (4U)
#define MUX_ODE_WIDTH                   (1U)
#define MUX_FIN_SHIFT                   (8U)
#define MUX_FIN_WIDTH                   (2U)
#define MUX_FIN_IP_SHIFT                (10U)
#define MUX_FIN_IP_WIDTH                (16U)
#define MUX_FV_SHIFT                    (29U)
#define MUX_FV_WIDTH                    (1U)
#define MUX_DO_FORCE_EN_SHIFT           (30U)
#define MUX_DO_FORCE_EN_WIDTH           (1U)
#define MUX_DO_FORCE_VALUE_SHIFT        (31U)
#define MUX_DO_FORCE_VALUE_WIDTH        (1U)

/* PORT PAD CONFIG REGISTER */
#define PORT_PAD_CONFIG_REG_OFFSET      (0x1000U)
#define PAD_PULL_SHIFT                  (0U)
#define PAD_PULL_WIDTH                  (2U)
#define PAD_DS_SHIFT                    (4U)
#define PAD_DS_WIDTH                    (2U)
#define PAD_SR_SHIFT                    (8U)
#define PAD_SR_WIDTH                    (1U)
#define PAD_IS_SHIFT                    (12U)
#define PAD_IS_WIDTH                    (1U)
#define PAD_POE_SHIFT                   (16U)
#define PAD_POE_WIDTH                   (1U)
#define PAD_MS_SHIFT                    (20U)
#define PAD_MS_WIDTH                    (1U)

/* PORT INPUT SELECT REGISTER */
#define PORT_INPUT_SELECT_REG_OFFSET    (0x3000U)
#define INPUT_SELECT_SRC_SEL_SHIFT      (0U)
#define INPUT_SELECT_SRC_SEL_WIDTH      (4U)

/* Force input ON/OFF.*/
#define PAD_INPUT_NO_FORCE           (0x0U) /* Pad input/output is selected by ALT function.*/
#define PAD_INPUT_FORCE_ENABLE       (0x1U) /* Enable pad input, regardless of ALT function.*/
#define PAD_INPUT_FORCE_DISABLE      (0x2U) /* Disable pad input. Internal IP read the value of FORCE_INPUT bit.*/

/* Force input value. Used in PAD_INPUT_FORCE_DISABLE mode. */
#define PAD_FORCE_INPUT_VALUE_0      (0U)   /*Force input value is 0*/
#define PAD_FORCE_INPUT_VALUE_1      (1U)   /*Force input value is 1*/

/* PORT GPIO CONFIG REGISTER */
#define PORT_GPIO_OEN                   (0x580U) /*gpio output enable*/
#define PORT_GPIO_DATA_IN               (0x600U) /*gpio data input*/
#define PORT_GPIO_DATA_OUT              (0x680U) /*gpio data output*/
#define PORT_GPIO_SINT_EN               (0x700U) /*gpio sync interrupt enable*/
#define PORT_GPIO_SINT_MASK             (0x780U) /*gpio sync interrupt mask*/
#define PORT_GPIO_SINT_TYPE             (0x800U) /*gpio sync interrupt type*/
#define PORT_GPIO_SINT_POL              (0x880U) /*gpio sync interrupt polarity*/
#define PORT_GPIO_SINT_BOTH_EDGE        (0x900U) /*gpio sync interrupt both edge enable*/
#define PORT_GPIO_SINT_STATUS           (0x980U) /*gpio sync interrupt status*/
#define PORT_GPIO_SINT_STATUS_UNMAS     (0xA00U) /*gpio sync interrupt unmask status*/
#define PORT_GPIO_SINT_EDGE_CLR         (0xA80U) /*gpio sync interrupt clear*/
#define PORT_GPIO_AINT_EN               (0xB00U) /*gpio async interrupt enable*/
#define PORT_GPIO_AINT_MASK             (0xB80U) /*gpio async interrupt mask*/
#define PORT_GPIO_AINT_TYPE             (0xC00U) /*gpio async interrupt type*/
#define PORT_GPIO_AINT_POL              (0xC80U) /*gpio async interrupt polarity*/
#define PORT_GPIO_AINT_BOTH_EDGE        (0xD00U) /*gpio async interrupt both edge enable*/
#define PORT_GPIO_AINT_STATUS           (0xD80U) /*gpio async interrupt status*/
#define PORT_GPIO_AINT_STATUS_UNMAS     (0xE00U) /*gpio async interrupt unmask status*/
#define PORT_GPIO_AINT_EDGE_CLR         (0xE80U) /*gpio async interrupt clear*/

/* PORT GPIO CONFIG REGISTER */
#define PORT_SET_PIN                    (0x04U)   /*gpio set offset*/
#define PORT_CLEAR_PIN                  (0x08U)   /*gpio clear offset*/
#define PORT_TOGGLE_PIN                 (0x0CU)   /*gpio toggle offset*/

/**
 * PORT GPIO INDEX.
 * define channel register bit operation, All channel(0-213) can be operate.
 */
#define PORT_PIN_OFFSET(channelId) ((channelId) / 32U)
#define PORT_PIN_BIT(channelId) ((channelId) % 32U)
#define PORT_PIN_MASK(channelId) (1UL << PORT_PIN_BIT(channelId))

/* PORT GPIO operate register define */
#define PORT_GPIO_SIZE 0x10U                                    /* gpio group register size*/
#define PORT_GPIO_OFFSET(base, n) ((base) + ((n)*PORT_GPIO_SIZE)) /* gpio group register address offset*/

/* GPIO PORT Interrupt Type */
#define PORT_INT_TYPE_LEVEL     (0x0UL)
#define PORT_INT_TYPE_PULSE     (0x1UL)
#define PORT_INT_POL_LOW_NEG    (0x0UL)
#define PORT_INT_POL_HIGH_POS   (0x1UL)
#define PORT_INT_BOE_SIG_EDGE   (0x0UL)
#define PORT_INT_BOE_BOTH_EDGE  (0x1UL)

#if (PORT_ANALOG_PIN_ENABLE == STD_ON)
/* anlog pin SCR register information */
#define PORT_SF_DOMAIN   (0U)
#define PORT_TYPE_RW     (0U)
#ifndef SEMIDRIVE_E3_LITE_SERIES
#define PORT_SCR_CFG_APD_A_A0_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 704U, 4U}
#define PORT_SCR_CFG_APD_A_A1_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 708U, 4U}
#define PORT_SCR_CFG_APD_A_A2_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 712U, 4U}
#define PORT_SCR_CFG_APD_A_A3_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 716U, 4U}
#define PORT_SCR_CFG_APD_A_A4_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 720U, 4U}
#define PORT_SCR_CFG_APD_A_A5_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 724U, 4U}
#define PORT_SCR_CFG_APD_A_A6_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 728U, 4U}
#define PORT_SCR_CFG_APD_A_A7_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 732U, 4U}
#define PORT_SCR_CFG_APD_A_A8_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 736U, 4U}
#define PORT_SCR_CFG_APD_A_A9_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 740U, 4U}
#define PORT_SCR_CFG_APD_A_A10_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 744U, 4U}
#define PORT_SCR_CFG_APD_A_A11_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 748U, 4U}
#define PORT_SCR_CFG_APD_A_A12_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 752U, 4U}
#define PORT_SCR_CFG_APD_A_A13_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 756U, 4U}
#define PORT_SCR_CFG_APD_A_A14_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 760U, 4U}
#define PORT_SCR_CFG_APD_A_A15_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 764U, 4U}
#define PORT_SCR_CFG_APD_A_B0_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 768U, 4U}
#define PORT_SCR_CFG_APD_A_B1_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 772U, 4U}
#define PORT_SCR_CFG_APD_A_B2_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 776U, 4U}
#define PORT_SCR_CFG_APD_A_B3_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 780U, 4U}
#define PORT_SCR_CFG_APD_A_B4_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 784U, 4U}
#define PORT_SCR_CFG_APD_A_B5_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 788U, 4U}
#define PORT_SCR_CFG_APD_A_B6_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 792U, 4U}
#define PORT_SCR_CFG_APD_A_B7_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 796U, 4U}
#define PORT_SCR_CFG_APD_A_B8_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 800U, 4U}
#define PORT_SCR_CFG_APD_A_B9_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 804U, 4U}
#define PORT_SCR_CFG_APD_A_B10_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 808U, 4U}
#define PORT_SCR_CFG_APD_A_B11_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 812U, 4U}
#define PORT_SCR_CFG_APD_A_B12_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 816U, 4U}
#define PORT_SCR_CFG_APD_A_B13_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 820U, 4U}
#define PORT_SCR_CFG_APD_A_B14_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 824U, 4U}
#define PORT_SCR_CFG_APD_A_B15_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 828U, 4U}
#define PORT_SCR_CFG_APD_A_C0_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 832U, 4U}
#define PORT_SCR_CFG_APD_A_C1_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 836U, 4U}
#define PORT_SCR_CFG_APD_A_C2_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 840U, 4U}
#define PORT_SCR_CFG_APD_A_C3_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 844U, 4U}
#define PORT_SCR_CFG_APD_A_C4_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 848U, 4U}
#define PORT_SCR_CFG_APD_A_C5_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 852U, 4U}
#define PORT_SCR_CFG_APD_A_C6_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 856U, 4U}
#define PORT_SCR_CFG_APD_A_C7_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 860U, 4U}
#define PORT_SCR_CFG_APD_A_C8_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 864U, 4U}
#define PORT_SCR_CFG_APD_A_C9_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 868U, 4U}
#define PORT_SCR_CFG_APD_A_C10_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 872U, 4U}
#define PORT_SCR_CFG_APD_A_C11_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 876U, 4U}
#define PORT_SCR_CFG_APD_A_C12_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 880U, 4U}
#define PORT_SCR_CFG_APD_A_C13_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 884U, 4U}
#define PORT_SCR_CFG_APD_A_C14_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 888U, 4U}
#define PORT_SCR_CFG_APD_A_C15_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 892U, 4U}
#else
#define PORT_SCR_CFG_APD_A_A0_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 544U, 4U}
#define PORT_SCR_CFG_APD_A_A1_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 548U, 4U}
#define PORT_SCR_CFG_APD_A_A2_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 552U, 4U}
#define PORT_SCR_CFG_APD_A_A3_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 556U, 4U}
#define PORT_SCR_CFG_APD_A_A4_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 560U, 4U}
#define PORT_SCR_CFG_APD_A_A5_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 564U, 4U}
#define PORT_SCR_CFG_APD_A_A6_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 568U, 4U}
#define PORT_SCR_CFG_APD_A_A7_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 572U, 4U}
#define PORT_SCR_CFG_APD_A_A8_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 576U, 4U}
#define PORT_SCR_CFG_APD_A_A9_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 580U, 4U}
#define PORT_SCR_CFG_APD_A_A10_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 584U, 4U}
#define PORT_SCR_CFG_APD_A_A11_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 588U, 4U}
#define PORT_SCR_CFG_APD_A_A12_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 592U, 4U}
#define PORT_SCR_CFG_APD_A_A13_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 596U, 4U}
#define PORT_SCR_CFG_APD_A_A14_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 600U, 4U}
#define PORT_SCR_CFG_APD_A_A15_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 604U, 4U}
#define PORT_SCR_CFG_APD_A_B0_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 608U, 4U}
#define PORT_SCR_CFG_APD_A_B1_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 612U, 4U}
#define PORT_SCR_CFG_APD_A_B2_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 616U, 4U}
#define PORT_SCR_CFG_APD_A_B3_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 620U, 4U}
#define PORT_SCR_CFG_APD_A_B4_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 624U, 4U}
#define PORT_SCR_CFG_APD_A_B5_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 628U, 4U}
#define PORT_SCR_CFG_APD_A_B6_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 632U, 4U}
#define PORT_SCR_CFG_APD_A_B7_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 636U, 4U}
#define PORT_SCR_CFG_APD_A_B8_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 640U, 4U}
#define PORT_SCR_CFG_APD_A_B9_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 644U, 4U}
#define PORT_SCR_CFG_APD_A_B10_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 648U, 4U}
#define PORT_SCR_CFG_APD_A_B11_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 652U, 4U}
#define PORT_SCR_CFG_APD_A_B12_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 656U, 4U}
#define PORT_SCR_CFG_APD_A_B13_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 660U, 4U}
#define PORT_SCR_CFG_APD_A_B14_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 664U, 4U}
#define PORT_SCR_CFG_APD_A_B15_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 668U, 4U}
#define PORT_SCR_CFG_APD_A_C0_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 672U, 4U}
#define PORT_SCR_CFG_APD_A_C1_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 676U, 4U}
#define PORT_SCR_CFG_APD_A_C2_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 680U, 4U}
#define PORT_SCR_CFG_APD_A_C3_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 684U, 4U}
#define PORT_SCR_CFG_APD_A_C4_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 688U, 4U}
#define PORT_SCR_CFG_APD_A_C5_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 692U, 4U}
#define PORT_SCR_CFG_APD_A_C6_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 696U, 4U}
#define PORT_SCR_CFG_APD_A_C7_CTRL_3_0  {PORT_SF_DOMAIN, PORT_TYPE_RW, 700U, 4U}
#endif
#endif

/********************************************************************************************************
 *                                  Global Types definition                                             *
 *******************************************************************************************************/

/* Configuration options of a port pin */
typedef enum
{
    /* PAD function. */
    PORT_CONFIG_FUNCTION = 0U,
    /* Pull up, pull down, or no-pull. */
    PORT_CONFIG_PULL,
    /* Open drain or push pull. */
    PORT_CONFIG_DRIVE,
    /* Drive strength. */
    PORT_CONFIG_DRIVE_STRENGTH,
    /* Enable schmitt-trigger input mode. */
    PORT_CONFIG_INPUT_SCHMITT,
    /* Slew rate. */
    PORT_CONFIG_SLEW_RATE,
    /* Force input. */
    PORT_CONFIG_FORCE_INPUT,
    /* Mode select, analog digital combo io only */
    PORT_CONFIG_MODE_SELECT,
    PORT_CONFIG_MAX,
} Port_PinConfigType;

/* Port pin hardware device address type */
typedef struct
{
    uint32   base;          /*pinctrl device base */
    uint32   padRegOffset;  /*pinctrl device pad reg offset */
    uint32   muxRegOffset;  /*pinctrl device mux reg offset */
} Port_ContrlType;

/* Scr signal type */
typedef struct
{
    uint8         domain;       /* scr signal domain */
    uint16        type;         /* scr signal type */
    uint16        startBit;     /* scr signal start bit */
    uint16        width;        /* scr signal width */
} Port_ScrSignalType;

/* Analog Pin scr type */
typedef struct
{
    uint32 pin;                 /* pin index */
    Port_ScrSignalType scrBit;  /* analog pin scr information */
} Port_AnalogScrType;

/* pinctrl device structure predefination*/
struct Port_Ip_PreType;

/* Common pinctrl device operation APIs.*/
typedef struct
{
    /*Configure pin parameters. Note that the pin index is controller local index.*/
    uint8 (*config)(const struct Port_Ip_PreType *pinctrlPtr, uint32 pin,
                    Port_PinConfigType config, uint32 value);
} Port_OpsType;

/* Common pinctrl controller structure.*/
typedef struct Port_Ip_PreType
{
    /* start Id of SOC pins controlled by this device. */
    const uint32            pinStart;
    /* number of SOC pins controlled by this device. */
    const uint32            pinNr;
    /* hardware device structure, used by drivers. */
    const Port_ContrlType   *dev;
    /* common pinctrl device operation APIs, used by drivers */
    const Port_OpsType      *ops;
} Port_PinctrlType;

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
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
Std_ReturnType Port_Ip_Init(const Port_SettingsConfigType *settingsPtr, uint8 num);
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
Std_ReturnType Port_Ip_AnalogPadInit(const Port_AnalogConfigType *settingsPtr, const uint8 num);
#endif   /** #if (PORT_ANALOG_PIN_ENABLE == STD_ON)*/

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
                                       const Port_SettingsConfigType *cfgPtr, uint8 num);
#endif  /** #if (PORT_SET_PIN_DIRECTION_API == STD_ON)*/
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
Std_ReturnType Port_Ip_RefreshPortDirection(const Port_SettingsConfigType *cfgPtr, uint8 num);

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
                                  const Port_SettingsConfigType *cfgPtr, uint8 num);
#endif  /** #if (STD_ON == PORT_SET_PIN_MODE_API)*/

#ifdef __cplusplus
}
#endif
/* End of file */
#endif /* PORT_IP_H */
