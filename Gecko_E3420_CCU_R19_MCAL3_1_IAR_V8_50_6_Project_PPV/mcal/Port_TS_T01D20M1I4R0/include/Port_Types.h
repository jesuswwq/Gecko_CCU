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
 *  \file     Port_Types.h                                                                              *
 *  \brief    his file contains data structures header for PORT MCAL driver.                            *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/14     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef PORT_TYPES_H
#define PORT_TYPES_H
#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Std_Types.h"

/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
/* PORT REGISTER BASE ADDRESS*/
#ifndef SEMIDRIVE_E3_LITE_SERIES
#define PORT_IOMUXC_SF_BASE      (0xf0630000U)
#define PORT_IOMUXC_AP_BASE      (0xf30e0000U)
#define PORT_SCR_SF_BASE         (0xf0680000U)
#define PORT_GPIO_SF_BASE        (0xf0740000U)
#define PORT_GPIO_AP_BASE        (0xf3120000U)
#else
#define PORT_SCR_SF_BASE         (0xf08b0000u)
#define PORT_IOMUXC_SF_BASE      (0xf0860000U)
#define PORT_GPIO_SF_BASE        (0xf0c40000U)
#endif

#ifndef SEMIDRIVE_E3_LITE_SERIES
/** \brief  Port pin id define */
/** \brief safety domain pin */
#define JTAG_TDI        (0U)
#define JTAG_TDO        (1U)
#define JTAG_TRST_N     (2U)
#define JTAG_TMS        (3U)
#define JTAG_TCK        (4U)
#define GPIO_X0         (5U)
#define GPIO_X1         (6U)
#define GPIO_X2         (7U)
#define GPIO_X3         (8U)
#define GPIO_X4         (9U)
#define GPIO_X5         (10U)
#define GPIO_X6         (11U)
#define GPIO_X7         (12U)
#define GPIO_X8         (13U)
#define GPIO_X9         (14U)
#define GPIO_X10        (15U)
#define GPIO_X11        (16U)
#define GPIO_Y0         (17U)
#define GPIO_Y1         (18U)
#define GPIO_Y2         (19U)
#define GPIO_Y3         (20U)
#define GPIO_Y4         (21U)
#define GPIO_Y5         (22U)
#define GPIO_Y6         (23U)
#define GPIO_Y7         (24U)
#define GPIO_Y8         (25U)
#define GPIO_Y9         (26U)
#define GPIO_Y10        (27U)
#define GPIO_Y11        (28U)
#define GPIO_A0         (29U)
#define GPIO_A1         (30U)
#define GPIO_A2         (31U)
#define GPIO_A3         (32U)
#define GPIO_A4         (33U)
#define GPIO_A5         (34U)
#define GPIO_A6         (35U)
#define GPIO_A7         (36U)
#define GPIO_A8         (37U)
#define GPIO_A9         (38U)
#define GPIO_A10        (39U)
#define GPIO_A11        (40U)
#define GPIO_A12        (41U)
#define GPIO_A13        (42U)
#define GPIO_A14        (43U)
#define GPIO_A15        (44U)
#define GPIO_B0         (45U)
#define GPIO_B1         (46U)
#define GPIO_B2         (47U)
#define GPIO_B3         (48U)
#define GPIO_B4         (49U)
#define GPIO_B5         (50U)
#define GPIO_B6         (51U)
#define GPIO_B7         (52U)
#define GPIO_B8         (53U)
#define GPIO_B9         (54U)
#define GPIO_B10        (55U)
#define GPIO_B11        (56U)
#define GPIO_B12        (57U)
#define GPIO_B13        (58U)
#define GPIO_B14        (59U)
#define GPIO_B15        (60U)
#define GPIO_C0         (61U)
#define GPIO_C1         (62U)
#define GPIO_C2         (63U)
#define GPIO_C3         (64U)
#define GPIO_C4         (65U)
#define GPIO_C5         (66U)
#define GPIO_C6         (67U)
#define GPIO_C7         (68U)
#define GPIO_C8         (69U)
#define GPIO_C9         (70U)
#define GPIO_C10        (71U)
#define GPIO_C11        (72U)
#define GPIO_C12        (73U)
#define GPIO_C13        (74U)
#define GPIO_C14        (75U)
#define GPIO_C15        (76U)
#define GPIO_G0         (77U)
#define GPIO_G1         (78U)
#define GPIO_G2         (79U)
#define GPIO_G3         (80U)
#define GPIO_G4         (81U)
#define GPIO_G5         (82U)
#define GPIO_G6         (83U)
#define GPIO_G7         (84U)
#define GPIO_G8         (85U)
#define GPIO_G9         (86U)
#define GPIO_G10        (87U)
#define GPIO_G11        (88U)
#define GPIO_M0         (89U)
#define GPIO_M1         (90U)
#define GPIO_M2         (91U)
#define GPIO_M3         (92U)
#define GPIO_M4         (93U)
#define GPIO_M5         (94U)
#define GPIO_M6         (95U)
#define GPIO_M7         (96U)
#define GPIO_M8         (97U)
#define GPIO_M9         (98U)
#define GPIO_M10        (99U)
#define GPIO_M11        (100U)
#define GPIO_S0         (101U)
#define GPIO_S1         (102U)
#define GPIO_S2         (103U)
#define GPIO_S3         (104U)
#define GPIO_S4         (105U)
#define GPIO_S5         (106U)
#define GPIO_S6         (107U)
#define GPIO_S7         (108U)
#define GPIO_S8         (109U)
#define GPIO_S9         (110U)
#define GPIO_S10        (111U)
#define GPIO_S11        (112U)
#define GPIO_S12        (113U)
#define GPIO_S13        (114U)
#define GPIO_H0         (115U)
#define GPIO_H1         (116U)
#define GPIO_H2         (117U)
#define GPIO_H3         (118U)
#define GPIO_H4         (119U)
#define GPIO_H5         (120U)
#define GPIO_H6         (121U)
#define GPIO_H7         (122U)
#define GPIO_H8         (123U)
#define GPIO_H9         (124U)
#define GPIO_H10        (125U)
#define GPIO_H11        (126U)
#define GPIO_H12        (127U)
#define GPIO_H13        (128U)
#define GPIO_F0         (129U)
#define GPIO_F1         (130U)
#define GPIO_F2         (131U)
#define GPIO_F3         (132U)
#define GPIO_F4         (133U)
#define GPIO_F5         (134U)
/** \brief ap domain pin */
#define GPIO_L0         (135U)
#define GPIO_L1         (136U)
#define GPIO_L2         (137U)
#define GPIO_L3         (138U)
#define GPIO_L4         (139U)
#define GPIO_L5         (140U)
#define GPIO_L6         (141U)
#define GPIO_L7         (142U)
#define GPIO_L8         (143U)
#define GPIO_L9         (144U)
#define GPIO_D0         (145U)
#define GPIO_D1         (146U)
#define GPIO_D2         (147U)
#define GPIO_D3         (148U)
#define GPIO_D4         (149U)
#define GPIO_D5         (150U)
#define GPIO_D6         (151U)
#define GPIO_D7         (152U)
#define GPIO_D8         (153U)
#define GPIO_D9         (154U)
#define GPIO_D10        (155U)
#define GPIO_D11        (156U)
#define GPIO_D12        (157U)
#define GPIO_D13        (158U)
#define GPIO_D14        (159U)
#define GPIO_D15        (160U)
#define GPIO_D16        (161U)
#define GPIO_D17        (162U)
#define GPIO_D18        (163U)
#define GPIO_D19        (164U)
#define GPIO_D20        (165U)
#define GPIO_D21        (166U)
#define GPIO_D22        (167U)
#define GPIO_D23        (168U)
#define GPIO_D24        (169U)
#define GPIO_D25        (170U)
#define GPIO_D26        (171U)
#define GPIO_D27        (172U)
#define GPIO_D28        (173U)
#define GPIO_D29        (174U)
#define GPIO_D30        (175U)
#define GPIO_D31        (176U)
#define GPIO_D32        (177U)
#define GPIO_D33        (178U)
#define GPIO_D34        (179U)
#define GPIO_D35        (180U)
#define GPIO_D36        (181U)
#define GPIO_D37        (182U)
#define GPIO_D38        (183U)
#define GPIO_D39        (184U)
#define GPIO_D40        (185U)
#define GPIO_D41        (186U)
#define GPIO_E0         (187U)
#define GPIO_E1         (188U)
#define GPIO_E2         (189U)
#define GPIO_E3         (190U)
#define GPIO_E4         (191U)
#define GPIO_E5         (192U)
#define GPIO_E6         (193U)
#define GPIO_E7         (194U)
#define GPIO_E8         (195U)
#define GPIO_E9         (196U)
#define GPIO_E10        (197U)
#define GPIO_E11        (198U)
#define GPIO_E12        (199U)
#define GPIO_E13        (200U)
#define GPIO_E14        (201U)
#define GPIO_E15        (202U)
#define GPIO_E16        (203U)
#define GPIO_E17        (204U)
#define GPIO_E18        (205U)
#define GPIO_E19        (206U)
#define GPIO_E20        (207U)
#define GPIO_E21        (208U)
#define GPIO_E22        (209U)
#define GPIO_E23        (210U)
#define GPIO_E24        (211U)
#define GPIO_E25        (212U)
#define GPIO_E26        (213U)

/** \brief port pin total number*/
#define PORT_PIN_NUM                  (214U)
/** \brief safety domain port pin start index*/
#define PORT_SAFETY_PIN_START         (0U)
/** \brief safety domain port pin number*/
#define PORT_SAFETY_PIN_NUM           (135U)
/** \brief ap domain port pin start index*/
#define PORT_AP_PIN_START             (135U)
/** \brief ap domain port pin number*/
#define PORT_AP_PIN_NUM               (79U)
/** \brief analog pin scr number*/
#define PORT_ANALOG_SCR_NUM         (48U)

/** \brief port pin input select number*/
#define PORT_INPUT_SELECT_NUM         (826U)

#else
/** \brief  Port pin id define, only safety domain */
#define JTAG_TDI        (0U)
#define JTAG_TDO        (1U)
#define JTAG_TRST_N     (2U)
#define JTAG_TMS        (3U)
#define JTAG_TCK        (4U)
#define GPIO_X0         (5U)
#define GPIO_X1         (6U)
#define GPIO_X2         (7U)
#define GPIO_X3         (8U)
#define GPIO_X4         (9U)
#define GPIO_X5        (10U)
#define GPIO_X6        (11U)
#define GPIO_X7        (12U)
#define GPIO_X8        (13U)
#define GPIO_X9        (14U)
#define GPIO_X10       (15U)
#define GPIO_X11       (16U)
#define GPIO_Y0        (17U)
#define GPIO_Y1        (18U)
#define GPIO_Y2        (19U)
#define GPIO_Y3        (20U)
#define GPIO_Y4        (21U)
#define GPIO_Y5        (22U)
#define GPIO_Y6        (23U)
#define GPIO_Y7        (24U)
#define GPIO_Y8        (25U)
#define GPIO_Y9        (26U)
#define GPIO_Y10       (27U)
#define GPIO_Y11       (28U)
#define GPIO_A0        (29U)
#define GPIO_A1        (30U)
#define GPIO_A2        (31U)
#define GPIO_A3        (32U)
#define GPIO_A4        (33U)
#define GPIO_A5        (34U)
#define GPIO_A6        (35U)
#define GPIO_A7        (36U)
#define GPIO_A8        (37U)
#define GPIO_A9        (38U)
#define GPIO_A10       (39U)
#define GPIO_A11       (40U)
#define GPIO_A12       (41U)
#define GPIO_A13       (42U)
#define GPIO_A14       (43U)
#define GPIO_A15       (44U)
#define GPIO_B0        (45U)
#define GPIO_B1        (46U)
#define GPIO_B2        (47U)
#define GPIO_B3        (48U)
#define GPIO_B4        (49U)
#define GPIO_B5        (50U)
#define GPIO_B6        (51U)
#define GPIO_B7        (52U)
#define GPIO_B8        (53U)
#define GPIO_B9        (54U)
#define GPIO_B10       (55U)
#define GPIO_B11       (56U)
#define GPIO_B12       (57U)
#define GPIO_B13       (58U)
#define GPIO_B14       (59U)
#define GPIO_B15       (60U)
#define GPIO_C0        (61U)
#define GPIO_C1        (62U)
#define GPIO_C2        (63U)
#define GPIO_C3        (64U)
#define GPIO_C4        (65U)
#define GPIO_C5        (66U)
#define GPIO_C6        (67U)
#define GPIO_C7        (68U)
#define GPIO_G0        (69U)
#define GPIO_G1        (70U)
#define GPIO_G2        (71U)
#define GPIO_G3        (72U)
#define GPIO_G4        (73U)
#define GPIO_G5        (74U)
#define GPIO_G6        (75U)
#define GPIO_G7        (76U)
#define GPIO_G8        (77U)
#define GPIO_G9        (78U)
#define GPIO_G10       (79U)
#define GPIO_G11       (80U)
#define GPIO_S0        (81U)
#define GPIO_S1        (82U)
#define GPIO_S2        (83U)
#define GPIO_S3        (84U)
#define GPIO_S4        (85U)
#define GPIO_S5        (86U)
#define GPIO_S6        (87U)
#define GPIO_S7        (88U)
#define GPIO_H0        (89U)
#define GPIO_H1        (90U)
#define GPIO_H2        (91U)
#define GPIO_H3        (92U)
#define GPIO_H4        (93U)
#define GPIO_H5        (94U)
#define GPIO_H6        (95U)
#define GPIO_H7        (96U)
#define GPIO_H8        (97U)
#define GPIO_H9        (98U)
#define GPIO_H10       (99U)
#define GPIO_H11      (100U)
#define GPIO_H12      (101U)
#define GPIO_H13      (102U)
#define GPIO_F0       (103U)
#define GPIO_F1       (104U)
#define GPIO_F2       (105U)
#define GPIO_F3       (106U)
#define GPIO_F4       (107U)
#define GPIO_F5       (108U)
#define GPIO_L0       (109U)
#define GPIO_L1       (110U)
#define GPIO_L2       (111U)
#define GPIO_L3       (112U)
#define GPIO_L4       (113U)
#define GPIO_L5       (114U)
#define GPIO_L6       (115U)
#define GPIO_L7       (116U)
#define GPIO_L8       (117U)
#define GPIO_L9       (118U)
#define GPIO_E0       (119U)
#define GPIO_E1       (120U)
#define GPIO_E2       (121U)
#define GPIO_E3       (122U)
#define GPIO_E4       (123U)
#define GPIO_E5       (124U)

/** \brief port pin total number*/
#define PORT_PIN_NUM                  (125U)
/** \brief safety domain port pin start index*/
#define PORT_SAFETY_PIN_START         (0U)
/** \brief safety domain port pin number*/
#define PORT_SAFETY_PIN_NUM           (125U)
/** \brief analog pin scr number*/
#define PORT_ANALOG_SCR_NUM         (40U)

/** \brief port pin input select number*/
#define PORT_INPUT_SELECT_NUM         (494U)
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES */
/**
 *  \addtogroup MCAL_PORT_MACRO PORT Macro.
 *
 * This files defines PORT macros.
 *  @{
 */
/**
 *  \name Port Driver Error Codes.
 *
 *  The Error Codes is one of the argument to Det_ReportError function and is
 *  used to identify the type of the error.
 *  @{
 */
/** \brief Invalid Port Pin ID requested */
/** Traceability       : SWSR_PORT_016 */
#define PORT_E_PARAM_PIN                ((Std_ReturnType)0x0A)
/** \brief Port Pin not configured as changeable */
/** Traceability       : SWSR_PORT_016 */
#define PORT_E_DIRECTION_UNCHANGEABLE   ((Std_ReturnType)0x0B)
/** \brief API Port_Init service called with wrong parameter */
/** Traceability       : SWSR_PORT_016 */
#define PORT_E_INIT_FAILED              ((Std_ReturnType)0x0C)
/** \brief Port Pin Mode passed not valid */
/** Traceability       : SWSR_PORT_016 */
#define PORT_E_PARAM_INVALID_MODE       ((Std_ReturnType)0x0D)
/** \brief API Port_SetPinMode service called when mode is unchangeable */
/** Traceability       : SWSR_PORT_016 */
#define PORT_E_MODE_UNCHANGEABLE        ((Std_ReturnType)0x0E)
/** \brief API service called without module initialization */
/** Traceability       : SWSR_PORT_016 */
#define PORT_E_UNINIT                   ((Std_ReturnType)0x0F)
/** \brief APIs called with a Null Pointer */
/** Traceability       : SWSR_PORT_016 */
#define PORT_E_PARAM_POINTER            ((Std_ReturnType)0x10)

/** \brief  Error due to API duplicated invoked Port_Init() */
#define PORT_E_INIT                      ((Std_ReturnType)0x80U)
/** \brief  Error due to invalid port config option type */
#define PORT_E_CONFIG_TYPE               ((Std_ReturnType)0x81U)
/** \brief  Error due to invalid port config parameters */
#define PORT_E_CONFIG_PARAM              ((Std_ReturnType)0x82U)
/** @} */

/**
 *  \name Port Driver PIN MUX.
 *
 *  The PIN MUX is one of the argument to Port_SetPinMode function and is
 *  used to identify the type of the mux.
 *  @{
 */
/** port pin mux index 0 */
#define  PORT_PIN_MUX_ALT0  0U
/** port pin mux index 1 */
#define  PORT_PIN_MUX_ALT1  1U
/** port pin mux index 2 */
#define  PORT_PIN_MUX_ALT2  2U
/** port pin mux index 3 */
#define  PORT_PIN_MUX_ALT3  3U
/** port pin mux index 4 */
#define  PORT_PIN_MUX_ALT4  4U
/** port pin mux index 5 */
#define  PORT_PIN_MUX_ALT5  5U
/** port pin mux index 6 */
#define  PORT_PIN_MUX_ALT6  6U
/** port pin mux index 7 */
#define  PORT_PIN_MUX_ALT7  7U
/** port pin mux index 8 */
#define  PORT_PIN_MUX_ALT8  8U
/** port pin mux index 9 */
#define  PORT_PIN_MUX_ALT9  9U
/** @} */
/********************************************************************************************************
 *                                  Global Types definition                                             *
 *******************************************************************************************************/
/**
 *  \addtogroup MCAL_PORT_CFG PORT Configuration
 *  @{
 *
 */

/** \brief open drain mode of a port pin */
typedef enum
{
    /** port pin push pull mode */
    PORT_PIN_PUSH_PULL   = 0U,
    /** port pin open drain mode */
    PORT_PIN_OPEN_DRAIN  = 1U,
} Port_OpenDrainType;

/** \brief force input mode of a port pin*/
typedef enum
{
    /** port pin force input disable */
    PORT_PIN_FORCE_INPUT_NORMAL  = 0U,
    /** port pin force input enable, read back value is output value */
    PORT_PIN_FORCE_INPUT_ENABLE  = 1U,
    /** port pin force input enable, read back value is 1 */
    PORT_PIN_FORCE_INPUT_HIGH    = 2U,
    /** port pin force input enable, read back value is 0 */
    PORT_PIN_FORCE_INPUT_LOW     = 3U,
} Port_ForceInputType;

/** \brief pulls mode of a port pin */
typedef enum
{
    /** port pin no pull */
    PORT_PIN_NOPULL     = 0U,
    /** port pin pull down */
    PORT_PIN_PULL_DOWN  = 1U,
    /** port pin pull up */
    PORT_PIN_PULL_UP    = 3U,
} Port_PullConfigType;

/** \brief drive strength of a port pin */
typedef enum
{
    /** port pin drive strength 2ma */
    PORT_PIN_DS_2MA  = 0U,
    /** port pin drive strength 8ma */
    PORT_PIN_DS_8MA  = 1U,
    /** port pin drive strength 4ma */
    PORT_PIN_DS_4MA  = 2U,
    /** port pin drive strength 12ma */
    PORT_PIN_DS_12MA = 3U,
} Port_DriveStrengthType;

/** \brief slew rate of a port pin */
typedef enum
{
    /** port pin slew rate fast */
    PORT_PIN_SR_FAST  = 0U,
    /** port pin slew rate slow */
    PORT_PIN_SR_SLOW  = 1U,
} Port_SlewRateType;

/** \brief input select CMOS mode of a port pin */
typedef enum
{
    /** input select CMOS mode */
    PORT_PIN_IS_CMOS          = 0U,
    /** input select CMOS SCHMITT mode */
    PORT_PIN_IS_CMOS_SCHMITT  = 1U,
} Port_ISCmosSchmittType;

/** \brief pad mode select of a port pin, analog-digital combo IO only */
typedef enum
{
    /** analog pin mode select 3V3 */
    PORT_PIN_SETTING_ANALOG_3V3  = 0U,
    /** analog pin mode select 5V */
    PORT_PIN_SETTING_ANALOG_5V = 1U,
} Port_AnalogInputType;

/** \brief initial level value of a port pin, GPIO only */
typedef enum
{
    /** gpio pin level low */
    PORT_PIN_LEVEL_LOW  = 0U,
    /** gpio pin level high */
    PORT_PIN_LEVEL_HIGH = 1U,
} Port_LevelType;


/** \brief direction of a port pin, GPIO only*/
/** Traceability       : SWSR_PORT_026 SWSR_PORT_027 SWSR_PORT_028 */
typedef enum
{
    /** gpio pin input direction */
    PORT_PIN_IN  = 0U,
    /** gpio pin output direction */
    PORT_PIN_OUT = 1U,
} Port_PinDirectionType;

/** \brief interrupt mode of a port pin, GPIO only */
typedef enum
{
    /** interrupt disable*/
    PORT_PIN_INTERRUPT_DISABLED          = 0U,
    /** sync interrupt low level*/
    PORT_PIN_INTERRUPT_LOW_LEVEL         = 1U,
    /** sync interrupt high level*/
    PORT_PIN_INTERRUPT_HIGH_LEVEL        = 2U,
    /** sync interrupt rising edge*/
    PORT_PIN_INTERRUPT_RISING_EDGE       = 3U,
    /** sync interrupt falling edge*/
    PORT_PIN_INTERRUPT_FALLING_EDGE      = 4U,
    /** sync interrupt both edge*/
    PORT_PIN_INTERRUPT_BOTH_EDGE         = 5U,
    /** async interrupt low level*/
    PORT_PIN_ASYC_INTERRUPT_LOW_LEVEL    = 6U,
    /** async interrupt high level*/
    PORT_PIN_ASYC_INTERRUPT_HIGH_LEVEL   = 7U,
    /** async interrupt rising edge*/
    PORT_PIN_ASYC_INTERRUPT_RISING_EDGE  = 8U,
    /** async interrupt falling edge*/
    PORT_PIN_ASYC_INTERRUPT_FALLING_EDGE = 9U,
    /** async interrupt both edge*/
    PORT_PIN_ASYC_INTERRUPT_BOTH_EDGE    = 10U,
} Port_InterruptConfigType;

/** \brief Symbolic name of a port pin. */
/** Traceability       : SWSR_PORT_023 SWSR_PORT_024 SWSR_PORT_025 */
typedef uint16 Port_PinType;

/** \brief pad function pin mux of a port pin */
/** Traceability       : SWSR_PORT_029 SWSR_PORT_030 SWSR_PORT_031 SWSR_PORT_032 */
typedef uint32 Port_PinModeType;

/** \brief Common PINCTRL configuration parameters define*/
typedef struct
{
    /** port pin index */
    uint32                          pinIndex;
    /** port pin mux modeChangable*/
    boolean                         modeChangable;
    /** port pin mux*/
    Port_PinModeType                mux;
    /** port pin opendrain or push pull*/
    Port_OpenDrainType              openDrain;
    /** port pin pulls mode*/
    Port_PullConfigType             pullConfig;
    /** port pin drive strength*/
    Port_DriveStrengthType          driveStrength;
    /** port pin slew rate*/
    Port_SlewRateType               slewRate;
    /** port pin input select cmos schmitt type*/
    Port_ISCmosSchmittType          inputSelect;
    /** port pin direction, for gpio only*/
    Port_PinDirectionType           dataDirection;
    /** port pin interrupt config, for gpio only*/
    Port_InterruptConfigType        interruptConfig;
    /** port pin initial level value, for gpio only*/
    Port_LevelType                  initialValue;
    /** port pin force input*/
    Port_ForceInputType             forceInput;
    /** port pin direction changable, for gpio only*/
    boolean                         directChangable;
} Port_SettingsConfigType;

/** \brief analog configuration parameters define */
typedef struct
{
    /** port pin index */
    uint32                          pinIndex;
    /** port pin mode select, for analog pin only */
    Port_AnalogInputType            inputLevel;
} Port_AnalogConfigType;

/** \brief  Type of the external data structure containing the initialization data for port module. */
/** Traceability       : SWSR_PORT_020 SWSR_PORT_021 SWSR_PORT_022 */
typedef struct
{
    /** Number of pads (to be configured) */
    VAR(uint8, PORT_VAR) num;
    /** Pad common configuration */
    P2CONST(Port_SettingsConfigType, AUTOMATIC, PORT_APPL_CONST) padCfgPtr;
    /** Number of analog pads (to be configured) */
    VAR(uint8, PORT_VAR) analogNum;
    /** Analog pad configuration */
    P2CONST(Port_AnalogConfigType, AUTOMATIC, PORT_APPL_CONST) analogCfgPtr;
} Port_ConfigType;
/** @} */

/** \brief  input source select of a function */
typedef struct
{
    uint32  pin;
    uint32  mux;
    uint32  base;
    uint32  offset;
    uint32  value;
} Port_InputSelectType;

/********************************************************************************************************
 *                                  Global Variable Declarations                                        *
 *******************************************************************************************************/
/** \brief port pin input select table*/
extern const Port_InputSelectType Port_PinctrlIs[PORT_INPUT_SELECT_NUM];
#ifdef __cplusplus
}
#endif
/* End of file */
#endif /* PORT_TYPES_H */
