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
 *  \file     Mcu_Pmu.h                                                                                 *
 *  \brief    This file contains interface header for MCU_Pmu MCAL driver, ...                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/03     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef MCU_PMU_H
#define MCU_PMU_H

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
/** \brief The MCU_PMU state check vaild. */
#define IS_VALID_PMU_STATE(v)  \
    (((Mcu_PmuStateType)v == PMU_STATE_PWR_UP) || ((Mcu_PmuStateType)v == PMU_STATE_RUN)    \
     || ((Mcu_PmuStateType)v == PMU_STATE_SLEEP) || ((Mcu_PmuStateType)v == PMU_STATE_HIBERNATE) \
     || ((Mcu_PmuStateType)v == PMU_STATE_RTC)|| ((Mcu_PmuStateType)v == PMU_STATE_OFF))

/** \brief The MCU_PMU wakeup status mask. */
#define PMU_WAKE_UP_SOURCE      0xFU
#define PMU_POWER_DOWN_SOURCE   0xFFF0U

/** \brief The MCU_PMU base address. */
#define PMU_RBASE       APB_PMU_CORE_BASE

/** \brief used to enable 3.3V power-off reset. */
#define MCU_3V3POWEROFF_RESET (STD_ON)
/********************************************************************************************************
 *                                  Global Types definition                                             *
 *******************************************************************************************************/
/** \brief The MCU_PMU state support. */
typedef enum
{

    PMU_STATE_PWR_UP = 0U,          /** \brief INIT, the default state of PMU */
    PMU_STATE_RUN = 1U,             /** \brief Power-up, indicationg the power-up is on-going */
    PMU_STATE_SLEEP = 2U,           /** \brief Power-up finised. Power on */
    PMU_STATE_HIBERNATE = 3U,       /** \brief Hibernate mode */
    PMU_STATE_RTC = 4U,             /** \brief Rtc mode */
    PMU_STATE_OFF = 5U,             /** @brief Power-down finished. Power off */
    PMU_STATE_INVALID = 0xffu,
} Mcu_PmuStateType;

/** \brief enumeration of PMU pwrctrl pins. */
typedef enum
{
    PMU_PWRCTRL_0 = 0U,
    PMU_PWRCTRL_1,
    PMU_PWRCTRL_2,
    PMU_PWRCTRL_3,
    PMU_PWRCTRL_MAX,
} Mcu_PmuPwrCtrlIdType;

/** \brief enumeration of PMU pwrctrl pins. */
typedef enum
{
    PMU_PWRON_0 = 0U,
    PMU_PWRON_1,
    PMU_PWRON_2,
    PMU_PWRON_3,
    PMU_PWRON_MAX,
/*PRQA S 1535 1*/
} Mcu_PmuPwrOnIdType;

/** \brief enumeration of pwr_on0~3 control target. */
typedef enum
{
    PMU_TARGET_SF = 0U,
    PMU_TARGET_AP,
    PMU_TARGET_OTHER,
/*PRQA S 1535 1*/
} Mcu_PmuTargetType;

/** \brief enumeration of pwr_ctrl0~3 use or not. */
typedef enum
{
    PMU_PWRCTRL_NOUSE = 0U,
    PMU_PWRCTRL_SELECT,
} Mcu_PmuPwrCtrlSelectType;

/** \brief auto / manual select. */
typedef enum
{
    PMU_MANUAL = 0U,
    PMU_AUTO,
} Mcu_PmuAutoManualType;

/** \brief on / off select. */
typedef enum
{
    PMU_OFF = 0U,
    PMU_ON,
    PMU_ON_OFF_INVALID,
} Mcu_PmuOnOffType;

/** \brief pm bc button fsm switch. */
typedef enum
{
    PMU_MONI_ENABLE = 0U,
    PMU_MONI_DISABLE
/*PRQA S 1535 1*/
} Mcu_PmuBcMoniSwitchType;

/** \brief pm bc button detect switch. */
typedef enum
{
    PMU_BC_ENABLE = 0U,
    PMU_BC_DISABLE
/*PRQA S 1535 1*/
} Mcu_PmuBcSwitchType;

/** \brief wakup sensitive level. */
typedef enum
{
    PMU_TRIGGER_MODE_LEVEL = 0U,
    PMU_TRIGGER_MODE_EDGE,
    PMU_TRIGGER_INVALID = 0xFFU,
} Mcu_PmuTriggerModeType;

/** \brief wakup sensitive edge. */
typedef enum
{
    PMU_EDGE_TYPE_RISING = 0U,
    PMU_EDGE_TYPE_FALLING,
    PMU_EDGE_TYPE_BOTH,
    PMU_EDGE_TYPE_INVALID = 0xFFU,
} Mcu_PmuEdgeType;

/** \brief wakup Polarity. */
typedef enum
{
    PMU_HIGH_ACTIVE = 0U,
    PMU_LOW_ACTIVE,
    PMU_POLARITY_INVALID = 0xFFU,
} Mcu_PmuPolarityType;

/** \brief wakup up source enable. */
typedef enum
{
    PMU_WAKEUP_SRC_DISABLE = 0U,
    PMU_WAKEUP_SRC_ENABLE,
} Mcu_PmuWakeupSrcEnableType;

/** \brief wakup up Pins Logic. */
typedef enum
{
    PMU_LOGIC_AND = 0U,
    PMU_LOGIC_OR,
    PMU_LOGIC_INVALID = 0xFFU,
} Mcu_PmuWakeupPinsLogicType;

/** \brief BC window check enable. */
typedef enum
{
    PMU_BC_WINDOW_CHECK_DISABLE = 0U,
    PMU_BC_WINDOW_CHECK_ENABLE,
} Mcu_PmuBcWinCheckType;

/** \brief filter enable. */
typedef enum
{
    PMU_FILTER_ENABLE = 0U,
    PMU_FILTER_BYPASS,
    PMU_FILTER_INVALID,
} Mcu_PmuFilterSelectType;


/** \brief pmu wakeup source. */
typedef enum
{
    PMU_WAKEUPSRC_BC_BUTTON = 0U,           /** \brief 0:wakeup by button control */
    PMU_WAKEUPSRC_RTC,                      /** \brief 1:rtc periodic interrupt */
    PMU_WAKEUPSRC_WAKEUP_PIN,               /** \brief 2:wakeup pin */
    PMU_WAKEUPSRC_HARDWARE_PWRDOWN_REQ,     /** \brief 3:auto wakeup which is triggered by hardware power down request. */
/*PRQA S 1535 1*/
} Mcu_PmuWakeupSourceType;


/** \brief pmu wakeup src enable select */
typedef struct
{
    Mcu_PmuWakeupSrcEnableType wakeup0Src;
    Mcu_PmuWakeupSrcEnableType wakeup1Src;
    Mcu_PmuWakeupPinsLogicType wakeup01Sel;
    Mcu_PmuWakeupSrcEnableType bcButtonSrc;
    Mcu_PmuWakeupSrcEnableType rtcSrc;
} Mcu_PmuWakeupSrcType;

/** \brief pmu pwr ctrl signal */
typedef struct
{
    Mcu_PmuAutoManualType       autoManual;
    Mcu_PmuOnOffType            onOff;
    uint8                  delay;
    uint8                  delayAdj;
} Mcu_PmuPwrCtrlType;

/** \brief pum pwr_ctrl0~3 auto.polarity and override enable*/
typedef struct
{
    Mcu_PmuPolarityType          pwrCtrl0Polarity;
    Mcu_PmuPolarityType          pwrCtrl1Polarity;
    Mcu_PmuPolarityType          pwrCtrl2Polarity;
    Mcu_PmuPolarityType          pwrCtrl3Polarity;
} Mcu_PmuPwrCtrlConfigType;



/** \brief pmu wakeup pin data */
typedef struct
{
    Mcu_PmuEdgeType pulseEdgeType;
    Mcu_PmuTriggerModeType sensitive;
    Mcu_PmuPolarityType polarity;
    Mcu_PmuFilterSelectType filterBypass;
    Mcu_PmuEdgeType edgeType;
    uint16 filterCnt;
    uint16 sampleInterval;
} Mcu_PmuPinCtrlType;

/** \brief pmu bc button data */
typedef struct
{
    Mcu_PmuTriggerModeType offMode;
    Mcu_PmuTriggerModeType onMode;
    Mcu_PmuPolarityType  offPol;
    Mcu_PmuPolarityType  onPol;
    Mcu_PmuBcWinCheckType offMaxVldSel;
    Mcu_PmuBcWinCheckType onMaxVldSel;
    uint8 offMaxVldWin;
    uint8 offMinVldWin;
    uint8 onMaxVldWin;
    uint8 onMinVldWin;
    uint8 timerUnit;
    Mcu_PmuFilterSelectType filterBypass;
    Mcu_PmuEdgeType edgeType;
    uint16 filterCnt;
    uint16 sampleInterval;
} Mcu_PmuButtonCtrlType;

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
/** *****************************************************************************************************
 * \brief This function gets the current wake source for RTC mode.
 *
 * \verbatim
 * Syntax             : uint32 Mcu_Ip_PmuGetWakeupSource
 *                      (
 *                          void
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : [0]: 1 - wakeup by external BC Button. 0 - other.
 *                      [1]: 1 - wakeup by RealTimeCounter periodic interrupt. 0 - other.
 *                      [2]: 1 - wakeup by external Wakeup Pin Button. 0 - other.
 *
 * Description        : Gets the current wake source for RTC mode.The state is saved until the user
 *                      calls the Mcu_Ip_PmuClearDownUpStatus and Mcu_Ip_PmuPwrdown function is not
 *                      cleared.
 *                      When user invokes Mcu_Ip_PmuPwrdown to enter RTC mode, the driver will actively
 *                      clear the current wakeup state.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
uint32 Mcu_Ip_PmuGetWakeupSource(void);

/** *****************************************************************************************************
 * \brief This function gets the last power down source.
 *
 * \verbatim
 * Syntax             : uint32 Mcu_Ip_PmuGetPowerDownSource
 *                      (
 *                          void
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : [15]: 1 - power down by External BC button. 0 - other.
 *                      [14]: 1 - power down by software. 0 - other.
 *                      [13]: 1 - power down by SoC internal emergency power down request[7],
 *                                efuse vio. 0 - other.
 *                      [12]: 1 - power down by SoC internal emergency power down request[6],
 *                                Ap pt senser int. 0 - other.
 *                      [11]: 1 - power down by SoC internal emergency power down request[5],
 *                                sf pt senser int. 0 - other.
 *                      [10]: 1 - power down by SoC internal emergency power down request[4],
 *                                vd_ap int. 0 - other.
 *                      [09]: 1 - power down by SoC internal emergency power down request[3],
 *                                vd_sf_int. 0 - other.
 *                      [08]: 1 - power down by SoC internal emergency power down request[2],
 *                                fs_32k_lvpg not good. 0 - other.
 *                      [07]: 1 - power down by SoC internal emergency power down request[1],
 *                                Reserved. 0 - other.
 *                      [06]: 1 - power down by SoC internal emergency power down request[0],
 *                                sem12_int. 0 - other.
 *                      [05]: 1 - power down by Reserved. 0 - other.
 *                      [04]: 1 - power down by SMC reset check fail. 0 - other.
 *
 * Description        : Gets the last power down source.The state is saved until the user calls the
 *                      Mcu_Ip_PmuClearDownUpStatus and Mcu_Ip_PmuPwrdown function is not cleared.
 *                      When user invokes Mcu_Ip_PmuPwrdown to enter RTC mode, the driver will actively
 *                      clear the current wakeup state.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
uint32 Mcu_Ip_PmuGetPowerDownSource(void);

/** *****************************************************************************************************
 * \brief This function clear the MCU_PMU.POWER_DOWN_STATUS.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuClearDownUpStatus
 *                      (
 *                          void
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : clear the last power down source value and the current wakeup source value.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
void Mcu_Ip_PmuClearDownUpStatus(void);

/** *****************************************************************************************************
 * \brief This function Initialization the BCButton for RTC mode.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_Ip_PmuButtonControlInit
 *                      (
 *                          const Mcu_PmuButtonCtrlType *bcPtr
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : bcPtr - Pointer to configuration set
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Release successful.
 *                      MCU_E_PARAM_CONFIG: The Unreasonable parameter.
 *                      MCU_E_PARAM_POINTER: Pointer is NULL_PTR.
 *
 * Description        : When the BCButton uses the level mode to enter/exit RTC mode, the input
 *                      signal must be controlled within the window period, otherwise the BCButton
 *                      cannot be used to wake up.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
Std_ReturnType Mcu_Ip_PmuButtonControlInit(const Mcu_PmuButtonCtrlType *bcPtr);

/** *****************************************************************************************************
 * \brief This function configures the pwr_ctrl signal mode.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuSetExtPwrctrlMode
 *                      (
 *                          Mcu_PmuStateType pmuMode,
 *                          Mcu_PmuPwrCtrlIdType id,
 *                          Mcu_PmuAutoManualType d1,
 *                          Mcu_PmuOnOffType d2
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : pmuMode - the target CPU mode.
 *                      id - the pwrctrl pin id.
 *                      d1 - the control mode.
 *                      d2 - the on/off control.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : If manual mode is selected, the Override function can be invoked to change
 *                      the current pwr_ctrl signal value.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
void Mcu_Ip_PmuSetExtPwrctrlMode(Mcu_PmuStateType pmuMode, Mcu_PmuPwrCtrlIdType id,
                                 Mcu_PmuAutoManualType d1,
                                 Mcu_PmuOnOffType d2);

/** *****************************************************************************************************
 * \brief This function configures the pwr_ctrl signal delay time.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuSetExtPwrctrlDly
 *                      (
 *                         Mcu_PmuStateType pmuMode,
 *                         Mcu_PmuPwrCtrlIdType id,
 *                         uint8 delay,
 *                         uint8 delayAdj
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : pmuMode - the target CPU mode.
 *                      id - the pwrctrl pin id.
 *                      delay - the delay value.
 *                      delayAdj - the delay_adj value.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The configuration does not take effect after the Override is enabled.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
void Mcu_Ip_PmuSetExtPwrctrlDly(Mcu_PmuStateType pmuMode, Mcu_PmuPwrCtrlIdType id, uint8 delay,
                                uint8 delayAdj);

/** *****************************************************************************************************
 * \brief This function configures the pwr_ctrl signal Polarity.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuSetExtPwrctrlPolarity
 *                      (
 *                         Mcu_PmuPwrCtrlIdType id,
 *                         Mcu_PmuPolarityType polarity
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : id - the pwrctrl pin id.
 *                      polarity - To specify the polarity.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The configuration does not take effect after the Override is enabled.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
void Mcu_Ip_PmuSetExtPwrctrlPolarity(Mcu_PmuPwrCtrlIdType id, Mcu_PmuPolarityType polarity);

/** *****************************************************************************************************
 * \brief This function Configure the power_ctrl signal Override enable.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuSetExtPwrctrlOverrideEnable
 *                      (
 *                         Mcu_PmuPwrCtrlIdType id,
 *                         const Mcu_PmuPwrCtrlSelectType overrideEnable
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : id - the pwrctrl pin id.
 *                      overrideEnable - To enable/disable Override.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The value set here overrides the value set in Auto and manual mode when
 *                      Override is enabled.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
void Mcu_Ip_PmuSetExtPwrctrlOverrideEnable(Mcu_PmuPwrCtrlIdType id,
        const Mcu_PmuPwrCtrlSelectType overrideEnable);

/** *****************************************************************************************************
 * \brief This function Configure the power_ctrl signal Override value.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuSetExtPwrctrlOverrideValue
 *                      (
 *                         Mcu_PmuPwrCtrlIdType id,
 *                         const Mcu_PmuPolarityType value
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : id - the pwrctrl pin id.
 *                      value - To select level value.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The value set here overrides the value set in Auto and manual mode when
 *                      Override is enabled.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
/*PRQA S 0777,0779 1*/
void Mcu_Ip_PmuSetExtPwrctrlOverrideValue(Mcu_PmuPwrCtrlIdType id, const Mcu_PmuPolarityType value);

/** *****************************************************************************************************
 * \brief This function Configure the pwr_on signal delay time for all mode.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuSetPwronDly
 *                      (
 *                         Mcu_PmuStateType pmuMode,
                           uint8 id, uint8 delay,
                           uint8 delayAdj
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : pmuMode - the target CPU mode.
 *                      id - the pwron pin id.
 *                      delay - the delay value.
 *                      delayAdj - the delay_adj value.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : When the Auto mode is selected, the pwr_on signal will change after the
 *                      preset time during different state switching processes.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
void Mcu_Ip_PmuSetPwronDly(Mcu_PmuStateType pmuMode, uint8 id, uint8 delay, uint8 delayAdj);


/** *****************************************************************************************************
 * \brief This function is used to select whether wakeup0 pin and wakeup1 pin work together to wakeup.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_Ip_PmuEnableWakeup01Pin
 *                      (
 *                         Mcu_PmuWakeupSrcEnableType enable
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : enable - enable/disable wakeup0 pin and wakeup1 pin work together to wakeup.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : When wakeup0 pin and wakeup1 pin are used together as the wake source event for
 *                      RTC mode, edge mode is strongly not recommended. When selecting edge mode at the
 *                      same time, each edge signal must be collected at the 32KHz sampling point at the
 *                      same time before it can be awakened. Otherwise, it will always be in a low power
 *                      state.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
void Mcu_Ip_PmuEnableWakeup01Pin(Mcu_PmuWakeupSrcEnableType enable);

/** *****************************************************************************************************
 * \brief This function is used to get the enable state of the wakeup0 pin.
 *
 * \verbatim
 * Syntax             : uint8 Mcu_Ip_PmuGetWakeup0EnableStatus
 *                      (
 *
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        :
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
uint8 Mcu_Ip_PmuGetWakeup0EnableStatus(void);

/** *****************************************************************************************************
 * \brief This function is used to get the enable state of the wakeup1 pin.
 *
 * \verbatim
 * Syntax             : uint8 Mcu_Ip_PmuGetWakeup1EnableStatus
 *                      (
 *
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        :
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
uint8 Mcu_Ip_PmuGetWakeup1EnableStatus(void);

/** *****************************************************************************************************
 * \brief This function is used to get the polarity selection of the wakeup0 pin.
 *
 * \verbatim
 * Syntax             : uint8 Mcu_Ip_PmuGetWakeup0Pol
 *                      (
 *
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 --  high active (for level mode), rising edge (for edge mode)
 *                      1 --  low active (for level mode), falling edge (for edge mode)
 *
 * Description        : Different trigger modes have different interpretations of the return value,
 *                      please pay attention to the relevant technical documentation.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
uint8 Mcu_Ip_PmuGetWakeup0Pol(void);

/** *****************************************************************************************************
 * \brief This function is used to get the polarity selection of the wakeup1 pin.
 *
 * \verbatim
 * Syntax             : uint8 Mcu_Ip_PmuGetWakeup1Pol
 *                      (
 *
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 --  high active (for level mode), rising edge (for edge mode)
 *                      1 --  low active (for level mode), falling edge (for edge mode)
 *
 * Description        : Different trigger modes have different interpretations of the return value,
 *                      please pay attention to the relevant technical documentation.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
uint8 Mcu_Ip_PmuGetWakeup1Pol(void);

/** *****************************************************************************************************
 * \brief This function is used to configure the properties associated with the wakeup0 pin.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_Ip_PmuEnableWakeup0Wakeup
 *                      (
 *                         const Mcu_PmuPinCtrlType *wakeupctlPtr
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : wakeupctlPtr - wakeup Pin-related attributes.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Attributes are legal.
 *                      MCU_E_PARAM_POINTER: wakeupctlPtr is NULL.
 *
 * Description        : The wakeup0 pin is only used for RTC mode wakeup. Pin-related properties
 *                      must be properly configured.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042 SWSR_MCU_054 SWSR_MCU_055
 *******************************************************************************************************/
Std_ReturnType Mcu_Ip_PmuEnableWakeup0Wakeup(const Mcu_PmuPinCtrlType *wakeupctlPtr);

/** *****************************************************************************************************
 * \brief This function is used to configure the properties associated with the wakeup1 pin.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Mcu_Ip_PmuEnableWakeup1Wakeup
 *                      (
 *                         const Mcu_PmuPinCtrlType *wakeupctlPtr
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : wakeupctlPtr - wakeup Pin-related attributes.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Attributes are legal.
 *                      MCU_E_PARAM_POINTER: wakeupctlPtr is NULL.
 *
 * Description        : The wakeup1 pin is only used for RTC mode wakeup. Pin-related properties
 *                      must be properly configured.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042 SWSR_MCU_054 SWSR_MCU_055
 *******************************************************************************************************/
Std_ReturnType Mcu_Ip_PmuEnableWakeup1Wakeup(const Mcu_PmuPinCtrlType *wakeupctlPtr);

/** *****************************************************************************************************
 * \brief This function configures whether to enable ButtonControl pin for wakeup with RTC mode.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuEnableExtWakeupSrc
 *                      (
 *                         Mcu_PmuWakeupSrcEnableType enable
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : enable - enable/disable ButtonControl pin wake up event.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This wakeup event is only used in RTC mode. The user must set a reasonable
 *                      pin attribute for the ButtonControl pin.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
void Mcu_Ip_PmuEnableExtWakeupSrc(Mcu_PmuWakeupSrcEnableType enable);

/** *****************************************************************************************************
 * \brief This function configures whether to enable RTC periodic interrupt for wakeup with RTC mode.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuEnableIntWakeupSrc
 *                      (
 *                         Mcu_PmuWakeupSrcEnableType enable
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : enable - enable/disable RTC periodic interrupt wake up event.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This wakeup event is only used in RTC mode. The RTC Timer alarm time must
 *                      be properly set.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
void Mcu_Ip_PmuEnableIntWakeupSrc(Mcu_PmuWakeupSrcEnableType enable);

/** *****************************************************************************************************
 * \brief This function is used to trigger entry into RTC mode.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuPwrdown
 *                      (
 *
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : When this function is executed, all cores will lose power except the RTC domain.
 *                      Before executing this function, the user must save the relevant data and use
 *                      the DMB,DSB,ISB synchronization instructions to ensure that the data transfer
 *                      is complete.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
void Mcu_Ip_PmuPwrdown(void);

/** *****************************************************************************************************
 * \brief This function is used to clear power down request.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuResumeCb
 *                      (
 *
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : When the bit value is 1, the power-off request is automatically triggered.
 *                      In normal cases, the hardware automatically clears this bit after waking up.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005 SWSR_MCU_042
 *******************************************************************************************************/
void Mcu_Ip_PmuResumeCb(void);

/** *****************************************************************************************************
 * \brief This function is used to enable/disable DCDC.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuDcdcEn
 *                      (
 *                         boolean en
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : en - enable/disable DCDC.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The DCDC output is controlled by the pwr_on0 signal. According to the manual control
 *                      of the enable/disable pwr_on0 signal, the user needs to select the level value
 *                      according to the actual need of his board.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005
 *******************************************************************************************************/
void Mcu_Ip_PmuDcdcEn(boolean en);

/** *****************************************************************************************************
 * \brief This function is used to enable/disable LDO.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuLdoEn
 *                      (
 *                         boolean en
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : en - enable/disable LDO.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The LDO output is controlled by the pwr_on1 signal. According to the manual control
 *                      of the enable/disable pwr_on1 signal, the user needs to select the level value
 *                      according to the actual need of his board.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005
 *******************************************************************************************************/
void Mcu_Ip_PmuLdoEn(boolean en);

/** *****************************************************************************************************
 * \brief This function is used to disable RTC mode wakeup source pin.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PmuDisableWakeupSrcPin
 *                      (
 *
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The default disable Wakeup0 Wakeup1 and BCButton pin, Reopen the back if necessary.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005
 *******************************************************************************************************/
void Mcu_Ip_PmuDisableWakeupSrcPin(void);

#if (MCU_3V3POWEROFF_RESET == STD_ON)
/** *****************************************************************************************************
 * \brief This function is used to enable 3.3V power-off reset.
 *
 * \verbatim
 * Syntax             : void Mcu_Pmu3v3PorOffReset
 *                      (
 *
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        :
 *                      enable monitor SF 0.8V power good status.
 *                      When 3.3V is powered down, the SF 0.8V Power good status is set to 0,
 *                      and 0 is detected to cause a reset.
 *                      reset means global reset,without RTC domain, and reset reason is 0.
 *
 * \endverbatim
 * Traceability       : SWSR_MCU_005
 *******************************************************************************************************/
void Mcu_Ip_Pmu3v3PorOffReset(void);
#endif /**#if (MCU_3V3POWEROFF_RESET == STD_ON)*/

#ifdef __cplusplus
}
#endif

#endif /* MCU_PMU_H */
/* End of file */
