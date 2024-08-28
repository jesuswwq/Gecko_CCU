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
 *  \file     Pwm_Type.h                                                                                *
 *  \brief    This file contains interface header for PWM MCAL driver                                   *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/18     <td>3.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifndef PWM_TYPE_H
#define PWM_TYPE_H

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Mcal.h"
#include "Std_Types.h"

/**
 *  \addtogroup MCAL_PWM_MACRO PWM macro
 *  \{
 */
/** \{ */
/** \brief Cache line length are 32 bytes */
#define PWM_CONFIG_ARCH_CACHE_LINE                                      (32U)
/** \} */
/** \} */

/**
 *  \addtogroup MCAL_PWM_CFG PWM Configuration
 *  \{
 */
/** \{ */
/** \brief   Numeric identifier of a Pwm channel. */
/** Traceability       : SWSR_PWM_017 */
typedef uint8 Pwm_ChannelType;

/** \brief  Definition of the period of a Pwm channel. */
/** Traceability       : SWSR_PWM_018 */
typedef uint32 Pwm_PeriodType;

/** \brief  Numeric identifier of Core Id. */
typedef uint8 Pwm_CoreIdType;
/** \} */
/** \} */

/**
 *  \addtogroup MCAL_PWM_MACRO PWM macro
 *  \{
 */
/** \{ */
/** \brief  ERROR:API Pwm_Init service called with wrong parameter. */
/** Traceability       : SWSR_PWM_013 */
#define PWM_E_INIT_FAILED                                               ((uint8)0x10U)
/** \brief  ERROR:API service used without module initialization. */
/** Traceability       : SWSR_PWM_013 */
#define PWM_E_UNINIT                                                    ((uint8)0x11U)
/** \brief  ERROR:API service used with an invalid channel Identifier. */
/** Traceability       : SWSR_PWM_013 */
#define PWM_E_PARAM_CHANNEL                                             ((uint8)0x12U)
/** \brief  ERROR:Usage of unauthorized Pwm service on Pwm channel configured a fixed period. */
/** Traceability       : SWSR_PWM_013 */
#define PWM_E_PERIOD_UNCHANGEABLE                                       ((uint8)0x13U)
/** \brief  ERROR:API Pwm_Init service called while the Pwm driver has already been initialised. */
/** Traceability       : SWSR_PWM_013 */
#define PWM_E_ALREADY_INITIALIZED                                       ((uint8)0x14U)
/** \brief  ERROR:API Pwm_GetVersionInfo is called with a NULL_PTR parameter. */
/** Traceability       : SWSR_PWM_013 */
#define PWM_E_PARAM_POINTER                                             ((uint8)0x15U)
/** \brief  ERROR:The requested power state is not supported by the Pwm module. */
/** Traceability       : SWSR_PWM_013 */
#define PWM_E_POWER_STATE_NOT_SUPPORTED                                 ((uint8)0x17U)
/** \brief  ERROR:The requested power state is not reachable from the current one. */
/** Traceability       : SWSR_PWM_013 */
#define PWM_E_TRANSITION_NOT_POSSIBLE                                   ((uint8)0x18U)
/** \brief  ERROR:API Pwm_SetPowerState has been called without having called the API Pwm_PreparePowerState before.. */
/** Traceability       : SWSR_PWM_013 */
#define PWM_E_PERIPHERAL_NOT_PREPARED                                   ((uint8)0x19U)
/** \brief  ERROR:DutyCycle of out range */
/** Traceability       : SWSR_PWM_013 */
#define PWM_E_DUTYCYCLE_OUT_OF_RANGE                                    ((uint8)0x1AU)
/** \brief  ERROR:Multi core illegal access*/
/** Traceability       : SWSR_PWM_013 */
#define PWM_E_ILLEGAL_RES                                               ((uint8)0x1BU)
/** \brief  ERROR:Error due to wait Pwm clock valid timeout */
/** Traceability       : SWSR_PWM_013 */
#define PWM_E_CONFIG_CLK_TIMEOUT                                        ((uint8)0x80U)
/** \brief  ERROR:Counter value of out range */
/** Traceability       : SWSR_PWM_013 */
#define PWM_E_COUNTER_OUT_OF_RANGE                                      ((uint8)0x81U)
/** \brief  ERROR:Compare value of out range */
/** Traceability       : SWSR_PWM_013 */
#define PWM_E_COMPARE_OUT_OF_RANGE                                      ((uint8)0x82U)
/** \brief  ERROR:Configure Dma channle failed */
/** Traceability       : SWSR_PWM_013 */
#define PWM_E_CONFIG_DMA_CHANNEL                                        ((uint8)0x83U)
/** \brief  ERROR:Error due to invalid Pwm config option type */
/** Traceability       : SWSR_PWM_013 */
#define PWM_E_CONFIG_EDGE_TYPE                                          ((uint8)0x84U)
/** \} */
/** \} */

/**
 *  \addtogroup MCAL_PWM_CFG Pwm Configuration
 *  \{
 */
/** \{ */
/** \brief  Output state of a Pwm channel. */
/** Traceability       : SWSR_PWM_019 */
typedef enum
{
    /** Pwm channel output low */
    PWM_LOW = 0,
    /** Pwm channel output high */
    PWM_HIGH
} Pwm_OutputStateType;

/** \brief  Definition of the type of edge notification of a Pwm channel. */
/** Traceability       : SWSR_PWM_020 */
typedef enum
{
    /** Pwm rising edge notification */
    PWM_RISING_EDGE = 1,
    /** Pwm falling edge notification */
    PWM_FALLING_EDGE,
    /** Pwm rising and falling edge notification */
    PWM_BOTH_EDGES
} Pwm_EdgeNotificationType;

/** \brief  Defines the class of a Pwm channel. */
/** Traceability       : SWSR_PWM_021 */
typedef enum
{
    /** Pwm channel class variable period */
    PWM_VARIABLE_PERIOD = 0,
    /** Pwm channel class fixed period */
    PWM_FIXED_PERIOD,
    /** Pwm channel class fixed period shifted */
    PWM_FIXED_PERIOD_SHIFTED
} Pwm_ChannelClassType;

/** \brief  Defines Pwm hardware controller index */
typedef enum
{
    /** Pwm hardware controller EPWM 1 */
    EPWM1_MODULE_INDEX = 0x00,
    /** Pwm hardware controller EPWM 2 */
    EPWM2_MODULE_INDEX,
    /** Pwm hardware controller EPWM 3 */
    EPWM3_MODULE_INDEX,
    /** Pwm hardware controller EPWM 4 */
    EPWM4_MODULE_INDEX,
    /** Pwm hardware controller ETIMER 1 */
    ETIMER1_MODULE_INDEX,
    /** Pwm hardware controller ETIMER 2 */
    ETIMER2_MODULE_INDEX,
    /** Pwm hardware controller ETIMER 3 */
    ETIMER3_MODULE_INDEX,
    /** Pwm hardware controller ETIMER 4 */
    ETIMER4_MODULE_INDEX
} Pwm_HrdControllerType;

/** \brief  Defines Pwm hardware controller irq index */
typedef enum
{
    /** Pwm hardware controller IRQ 0 */
    PWM1_MODULE_IRQ_INDEX = 0x00,
    /** Pwm hardware controller IRQ 1 */
    PWM2_MODULE_IRQ_INDEX,
    /** Pwm hardware controller IRQ 2 */
    PWM3_MODULE_IRQ_INDEX,
    /** Pwm hardware controller IRQ 3 */
    PWM4_MODULE_IRQ_INDEX,
    /** Pwm hardware controller IRQ 4 */
    PWM5_MODULE_IRQ_INDEX,
    /** Pwm hardware controller IRQ 5 */
    PWM6_MODULE_IRQ_INDEX,
    /** Pwm hardware controller IRQ 6 */
    PWM7_MODULE_IRQ_INDEX,
    /** Pwm hardware controller IRQ 7 */
    PWM8_MODULE_IRQ_INDEX
} Pwm_HrdControllerIrqType;

/** \brief  Defines Pwm counter type */
typedef enum
{
    /** Pwm counter type G0 */
    PWM_CNT_G0 = 0x00,
    /** Pwm counter type G1 */
    PWM_CNT_G1,
    /** Pwm counter type LCNT A */
    PWM_LCNT_A,
    /** Pwm counter type LCNT B */
    PWM_LCNT_B,
    /** Pwm counter type LCNT C */
    PWM_LCNT_C,
    /** Pwm counter type LCNT D */
    PWM_LCNT_D
} Pwm_CntType;

/** \brief  Defines Pwm global init status */
typedef enum
{
    /** Pwm uninitialized */
    PWM_STATE_UNINIT = 0x00,
    /** DMA already initialized */
    PWM_STATE_INIT
} Pwm_GlobalStateType;

/** \brief  Numeric identifier of a Pwm channel. */
typedef uint8 Pwm_ModuleType;

/** \brief  Pwm notification callback type. */
typedef void (*Pwm_NotifyType)(void);

/** \brief  Pwm channel DMA configutations type. */
typedef struct
{
    /** DMA enable or not */
    boolean enableDma;
    /** DMA FIFO watermark level */
    uint8 fifoWml;
    /** Total word number of pwm with dma transfer */
    uint32 totalNum;
    /** Point to source address */
    uint32* srcDataPtr;
} Pwm_ChannelDmaCfgType;

/** \brief  Pwm subchannel configutations type. */
typedef struct
{
    /** Pwm duty cycle, 0-0x8000 */
    uint16 dutyCycle;
    /** Pwm output polarity */
    Pwm_OutputStateType polarity;
    /** Pwm output idle status */
    Pwm_OutputStateType idleStatus;
} Pwm_SubChannelConfigType;

/** \brief  Pwm channel configutations type. */
typedef struct
{
    /** Channel Id */
    uint8 channelId;
    /** Counter G0/G1 or Local Counter A/B/C/D select */
    Pwm_CntType counterSelect;
    /** Only cmp0 output or Both cmp0 and cmp1 out */
    boolean bothCmpOutput;
    /** Subchannel configuration */
    Pwm_SubChannelConfigType subChannelGroup[2];
    /** DMA configuration */
    Pwm_ChannelDmaCfgType dmaCfg;
} Pwm_ChannelConfigType;

/** \brief  Pwm channel group configutations type. */
typedef struct
{
    /** Pwm channel configutations group */
    Pwm_ChannelConfigType channelGroup[4];
} Pwm_ChannelGroupType;

/** \brief  Pwm hardware module configutations type. */
typedef struct
{
    /** Pwm controller clock frequency */
    uint32 moduleClk;
    /** Pwm controller clock source */
    uint8 scrClkSel;
    /** Pwm controller clock divider value */
    uint16 dividerNum;
} Pwm_HwModuleConfigType;

/** \brief  Pwm hardware module counter configutations type. */
typedef struct
{
    /** The class of a Pwm channel */
    Pwm_ChannelClassType channelClass;
    /** The period of a Pwm channel (ns) */
    Pwm_PeriodType period;
} Pwm_HwModuleCntType;

/** \brief  Pwm module EID configutations type. */
typedef struct
{
    /** EID enable */
    boolean eidEnable;
    /** EID value */
    uint8 eidValue;
} Pwm_EIDType;

/** \brief  Pwm module configutations type. */
typedef struct
{
    /** Pwm hardware module id */
    Pwm_HrdControllerType moduleId;
    /** Number of Pwm channel */
    Pwm_ChannelType channelNum;
    /** Two Counter are used */
    boolean twoCounterUsed;
    /** Counter configuration */
    Pwm_HwModuleCntType countCfg[6];
    /** Pwm notification callback */
    Pwm_NotifyType notificationPtr;
    /** Pwm channel configuration */
    const Pwm_ChannelGroupType* channelGroupCfgPtr;
    /** Module Core Id*/
    Pwm_CoreIdType coreId;
    /** EID configuration */
    Pwm_EIDType eidConfig;
} Pwm_ModuleConfigType;

/** \brief  Pwm configutations type. */
/** Traceability       : SWSR_PWM_022 SWSR_PWM_023 */
typedef struct
{
    /** Number of Pwm module */
    Pwm_ModuleType moduleNum;
    /** Hardware(IP) related configure */
    const Pwm_HwModuleConfigType* moduleHwCfgPtr;
    /** Hardware independent configuration */
    const Pwm_ModuleConfigType* moduleCfgPtr;
} Pwm_ConfigType;

/** \brief  Pwm handler configutations type. */
typedef struct
{
    /** Pwm controller base address */
    uint32 baseAddr[8];
    /** Pwm Cnt overflow value */
    uint32 counterOvfValue[8][6];
    /** Pwm configure pointer */
    const Pwm_ConfigType* configPtr;
    /** Pwm Global init status */
    Pwm_GlobalStateType globalState;
    /** Pwm required DMA channel */
    uint32 dmaChannel[32];
    /** Pwm DMA initialize sequence */
    uint8 dmaInitSeq;
    /** Pwm DMA de-initialize sequence */
    uint8 dmaDeinitSeq;
} Pwm_HandlerConfigType LOCATE_ALIGNED(PWM_CONFIG_ARCH_CACHE_LINE);
/** \} */
/** \} */

#ifdef __cplusplus
}
#endif

#endif /* PWM_TYPE_H */
/* End of file */
