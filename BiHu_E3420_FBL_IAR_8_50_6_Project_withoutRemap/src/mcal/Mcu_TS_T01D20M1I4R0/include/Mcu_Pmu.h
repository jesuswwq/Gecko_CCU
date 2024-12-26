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

#ifndef MCU_PMU_H
#define MCU_PMU_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
/* Version and Check Begin */
/* Version Info Begin */
#define MCU_PMU_H_VENDOR_ID    0x8C
#define MCU_PMU_H_AR_RELEASE_MAJOR_VERSION    4
#define MCU_PMU_H_AR_RELEASE_MINOR_VERSION    3
#define MCU_PMU_H_AR_RELEASE_REVISION_VERSION 1
#define MCU_PMU_H_SW_MAJOR_VERSION    1
#define MCU_PMU_H_SW_MINOR_VERSION    0
#define MCU_PMU_H_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((MCU_PMU_H_AR_RELEASE_MAJOR_VERSION != STD_TYPES_H_AR_RELEASE_MAJOR_VERSION)\
    || (MCU_PMU_H_AR_RELEASE_MINOR_VERSION != STD_TYPES_H_AR_RELEASE_MINOR_VERSION)\
    || (MCU_PMU_H_AR_RELEASE_REVISION_VERSION != STD_TYPES_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Mcu_Pmu.h and Std_Types.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((MCU_PMU_H_SW_MAJOR_VERSION != STD_TYPES_H_SW_MAJOR_VERSION)\
    || (MCU_PMU_H_SW_MINOR_VERSION != STD_TYPES_H_SW_MINOR_VERSION)\
    || (MCU_PMU_H_SW_PATCH_VERSION != STD_TYPES_H_SW_PATCH_VERSION))
#error "Opps, Mcu_Pmu.h and Std_Types.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

#define IS_VALID_PMU_STATE(v)  \
    (((pmu_state_e)v == PMU_STATE_PWR_UP) || ((pmu_state_e)v == PMU_STATE_RUN)    \
     || ((pmu_state_e)v == PMU_STATE_SLEEP) || ((pmu_state_e)v == PMU_STATE_HIBERNATE) \
     || ((pmu_state_e)v == PMU_STATE_RTC)|| ((pmu_state_e)v == PMU_STATE_OFF))

#define PMU_WAKE_UP_SOURCE      0xFU
#define PMU_POWER_DOWN_SOURCE   0xFFF0U

typedef enum {

    PMU_STATE_PWR_UP = 0u, /**< @brief INIT, the default state of PMU */
    PMU_STATE_RUN = 1u,     /**< @brief Power-up, indicationg the power-up is on-going */
    PMU_STATE_SLEEP = 2u,   /**< @brief Power-up finised. Power on */
    PMU_STATE_HIBERNATE = 3u,/**< @brief Hibernate mode */
    PMU_STATE_RTC = 4u,     /**< @brief Rtc mode */
    PMU_STATE_OFF = 5u,     /*< @brief Power-down finished. Power off */
    PMU_STATE_INVALID = 0xffu,
} pmu_state_e;

/**
 * @brief enumeration of PMU pwrctrl pins.
 */
typedef enum {
    PMU_PWRCTRL_0 = 0,
    PMU_PWRCTRL_1,
    PMU_PWRCTRL_2,
    PMU_PWRCTRL_3,
    PMU_PWRCTRL_MAX,
} pmu_pwrctrl_id_e;

/**
 * @brief enumeration of PMU pwrctrl pins.
 */
typedef enum {
    PMU_PWRON_0 = 0,
    PMU_PWRON_1,
    PMU_PWRON_2,
    PMU_PWRON_3,
    PMU_PWRON_MAX,
} pmu_pwron_id_e;

/**
 * @brief enumeration of pwr_on0~3 control target.
 */
typedef enum {
    PMU_TARGET_SF,
    PMU_TARGET_AP,
    PMU_TARGET_OTHER,
} pmu_target_e;

/**
 * @brief enumeration of pwr_ctrl0~3 use or not.
 */
typedef enum {
    PMU_PWRCTRL_NOUSE,
    PMU_PWRCTRL_SELECT,
} pmu_pwrctrl_select_e;

/**
 * @brief auto / manual select.
 */
typedef enum {
    PMU_MANUAL,
    PMU_AUTO,
} pmu_auto_manual_e;

/**
 * @brief auto / manual select.
 */
typedef enum {
    PMU_OFF,
    PMU_ON,
    PMU_ON_OFF_INVALID,
} pmu_on_off_e;

/**
 * @brief pm bc button fsm switch.
 */
typedef enum {
    PMU_MONI_ENABLE,
    PMU_MONI_DISABLE
} pmu_bc_moni_switch_e;

/**
 * @brief pm bc button detect switch.
 */
typedef enum {
    PMU_BC_ENABLE,
    PMU_BC_DISABLE
} pmu_bc_switch_e;

/**
 * @brief wakup sensitive level.
 */
typedef enum {
    PMU_TRIGGER_MODE_LEVEL,
    PMU_TRIGGER_MODE_EDGE,
    PMU_TRIGGER_INVALID = 0xFF,
} pmu_trigger_mode_e;

typedef enum {
    PMU_EDGE_TYPE_RISING,
    PMU_EDGE_TYPE_FALLING,
    PMU_EDGE_TYPE_BOTH,
    PMU_EDGE_TYPE_INVALID = 0xFF,
} pmu_edge_type_e;

typedef enum {
    PMU_HIGH_ACTIVE,
    PMU_LOW_ACTIVE,
    PMU_POLARITY_INVALID = 0xFF,
} pmu_polarity_e;

/**
 * @brief wakup up enable.
 */
typedef enum {
    PMU_WAKEUP_SRC_DISABLE,
    PMU_WAKEUP_SRC_ENABLE,
} pmu_wakeup_src_enable_e;

/**
 * @brief wakup up enable.
 */
typedef enum {
    PMU_LOGIC_AND,
    PMU_LOGIC_OR,
    PMU_LOGIC_INVALID = 0xFF,
} pmu_wakeup_pins_logic_e;

/**
 * @brief BC window check enable.
 */
typedef enum {
    PMU_BC_WINDOW_CHECK_DISABLE,
    PMU_BC_WINDOW_CHECK_ENABLE,
} pmu_bc_win_check_e;

/**
 * @brief filter enable.
 */
typedef enum {
    PMU_FILTER_ENABLE,
    PMU_FILTER_BYPASS,
    PMU_FILTER_INVALID,
} pmu_filter_select_e;

/**
 * @brief ignore select.
 */
typedef enum {
    PMU_IGNORE_NO,
    PMU_IGNORE_YES,
} pmu_ignore_e;

/**
 * @brief pm powergood status.
 */
typedef enum {
    SF_LV_PG,
    SF_HV_PG,
    AP_LV_PG,
    AP_HV_PG,
    RTC_SF_LV_PG,
    RTC_SF_HV_PG,
    RTC_AP_LV_PG,
    RTC_AP_HV_PG,
} pmu_pg_status_e;

/**
 * @brief pm powergood detect switch.
 */
typedef enum {
    PMU_PG_ENABLE,
    PMU_PG_DISABLE
} pmu_pg_ctrl_e;

/**
 * @brief pmu wakeup source.
 */
typedef enum {
    PMU_WAKEUPSRC_BC_BUTTON,            /**< @brief 0:wakeup by button control */
    PMU_WAKEUPSRC_RTC,                  /**< @brief 1:rtc periodic interrupt */
    PMU_WAKEUPSRC_WAKEUP_PIN,           /**< @brief 2:wakeup pin */
    PMU_WAKEUPSRC_HARDWARE_PWRDOWN_REQ, /**< @brief 3:auto wakeup which is triggered by hardware power down request. */
} pmu_wakeup_src_e;

/**
 * @brief pmu power down request source.
 */
typedef enum {
    PMU_PWRDOWN_REQ_SRC_SMC_FAILE = 4,
    PMU_PWRDOWN_REQ_SRC_RESERVED,
    PMU_PWRDOWN_REQ_SRC_INT_REQ0,
    PMU_PWRDOWN_REQ_SRC_INT_REQ1,
    PMU_PWRDOWN_REQ_SRC_INT_REQ2,
    PMU_PWRDOWN_REQ_SRC_INT_REQ3,
    PMU_PWRDOWN_REQ_SRC_INT_REQ4,
    PMU_PWRDOWN_REQ_SRC_INT_REQ5,
    PMU_PWRDOWN_REQ_SRC_INT_REQ6,
    PMU_PWRDOWN_REQ_SRC_INT_REQ7,
    PMU_PWRDOWN_REQ_SRC_SW,
    PMU_PWRDOWN_REQ_SRC_BC_BUTTON,

} pmu_powerdown_src_e;

/* Delay timer = 2^(*_delay) * (&_delay_adj *2 +1 )*/
/**
 * @brief   enumeration of PMU delays.
 */
typedef enum {
    PMU_DELAY_NONE = 0,     /* 0us */
    PMU_DELAY_31us = 0,
    PMU_DELAY_62us = 1,
    PMU_DELAY_125us = 2,
    PMU_DELAY_250us = 3,
    PMU_DELAY_500us = 4,
    PMU_DELAY_750us = 3,
    PMU_DELAY_1ms = 5,
    PMU_DELAY_2ms = 6,
    PMU_DELAY_3ms = 5,
    PMU_DELAY_4ms = 7,
    PMU_DELAY_5ms = 5,
    PMU_DELAY_6ms = 6,
    PMU_DELAY_7ms = 5,
    PMU_DELAY_8ms = 8,
    PMU_DELAY_16ms = 9,
} pmu_pwr_delay_e;

/**
 * @brief   enumeration of PMU delay adjs.
 */
typedef enum {
    PMU_DELAYADJ_NONE = 0,     /* 0us */
    PMU_DELAYADJ_31us = 0,
    PMU_DELAYADJ_62us = 0,
    PMU_DELAYADJ_125us = 0,
    PMU_DELAYADJ_250us = 0,
    PMU_DELAYADJ_500us = 0,
    PMU_DELAYADJ_750us = 1,
    PMU_DELAYADJ_1ms = 0,
    PMU_DELAYADJ_2ms = 0,
    PMU_DELAYADJ_3ms = 1,
    PMU_DELAYADJ_4ms = 0,
    PMU_DELAYADJ_5ms = 2,
    PMU_DELAYADJ_6ms = 1,
    PMU_DELAYADJ_7ms = 3,
    PMU_DELAYADJ_8ms = 0,
    PMU_DELAYADJ_16ms = 0,
} pmu_pwr_delay_adj_e;

/* Filter timer = ( 2^SAMPLE_INTERVAL) * (FILTER_CNT + 2 )*/
/**
 * @brief   enumeration of PMU delays, range : 0~15.
 */
typedef enum {
    PMU_FILTER_CNT_NONE = 0,     /* 0Ms */
    PMU_FILTER_CNT_1ms = 6,
    PMU_FILTER_CNT_2ms = 6,
    PMU_FILTER_CNT_3ms = 10,
    PMU_FILTER_CNT_4ms = 6,
    PMU_FILTER_CNT_5ms = 8,
    PMU_FILTER_CNT_6ms = 4,
    PMU_FILTER_CNT_7ms = 5,
    PMU_FILTER_CNT_8ms = 6,
    PMU_FILTER_CNT_9ms = 7,
    PMU_FILTER_CNT_10ms = 8,
    PMU_FILTER_CNT_11ms = 9,
    PMU_FILTER_CNT_12ms = 10,
    PMU_FILTER_CNT_13ms = 11,
    PMU_FILTER_CNT_14ms = 12,
    PMU_FILTER_CNT_15ms = 13,
} pmu_button_filter_cnt_e;

/**
 * @brief   enumeration of PMU delay adjs, range : 0~7.
 */
typedef enum {
    PMU_SAMPLE_INTERVAL_NONE = 0,     /* 0Ms */
    PMU_SAMPLE_INTERVAL_1ms = 1,
    PMU_SAMPLE_INTERVAL_2ms = 3,
    PMU_SAMPLE_INTERVAL_3ms = 3,
    PMU_SAMPLE_INTERVAL_4ms = 4,
    PMU_SAMPLE_INTERVAL_5ms = 4,
    PMU_SAMPLE_INTERVAL_6ms = 5,
    PMU_SAMPLE_INTERVAL_7ms = 5,
    PMU_SAMPLE_INTERVAL_8ms = 5,
    PMU_SAMPLE_INTERVAL_9ms = 5,
    PMU_SAMPLE_INTERVAL_10ms = 5,
    PMU_SAMPLE_INTERVAL_11ms = 5,
    PMU_SAMPLE_INTERVAL_12ms = 5,
    PMU_SAMPLE_INTERVAL_13ms = 5,
    PMU_SAMPLE_INTERVAL_14ms = 5,
    PMU_SAMPLE_INTERVAL_15ms = 5,
} pmu_button_sample_interval_e;

/* power good detect switch */
typedef struct {
    pmu_pg_ctrl_e lvpg;
    pmu_pg_ctrl_e hvpg;
    pmu_ignore_e  sfhv;
    pmu_ignore_e  sflv;
    pmu_ignore_e  aphv;
    pmu_ignore_e  aplv;
} pmu_pwr_good_switch_t;

/* pmu wakeup src enable select */
typedef struct {
    pmu_wakeup_src_enable_e wakeup0src;
    pmu_wakeup_src_enable_e wakeup1src;
    pmu_wakeup_pins_logic_e wakeup01sel;
    pmu_wakeup_src_enable_e BCButtonsrc;
    pmu_wakeup_src_enable_e rtcsrc;
} pmu_wakeup_src_t;

/* pmu pwr ctrl signal */
typedef struct {
    pmu_auto_manual_e       automanual;
    pmu_on_off_e            onoff;
    uint32                  delay;
    uint32                  delayadj;
} pmu_pwr_ctrl_t;

/* pum pwr_ctrl0~3 auto.polarity and override enable*/
typedef struct {
    pmu_polarity_e          pwr_ctrl0_polarity;
    pmu_polarity_e          pwr_ctrl1_polarity;
    pmu_polarity_e          pwr_ctrl2_polarity;
    pmu_polarity_e          pwr_ctrl3_polarity;
} pmu_pwr_ctrl_config_t;

/* pmu pwr on signal */
typedef struct {
    pmu_target_e            target;
    pmu_auto_manual_e       automanual;
    pmu_on_off_e            onoff;
    uint32                  delay;
    uint32                  delayadj;
} pmu_pwr_on_t;

/* pmu wakeup pin data */
typedef struct {
    pmu_edge_type_e pulseedgetype;
    pmu_trigger_mode_e sensitive;
    pmu_polarity_e polarity;
    pmu_filter_select_e filterbypass;
    pmu_edge_type_e edgetype;
    uint32 filtercnt;
    uint32 sampleinterval;
} pmu_pin_ctrl_t;

/* pmu bc button data */
typedef struct {
    pmu_trigger_mode_e offmode;
    pmu_trigger_mode_e onmode;
    pmu_polarity_e  offpol;
    pmu_polarity_e  onpol;
    pmu_bc_win_check_e offmaxvldsel;
    pmu_bc_win_check_e onmaxvldsel;
    uint32 offmaxvldwin;
    uint32 offminvldwin;
    uint32 onmaxvldwin;
    uint32 onminvldwin;
    uint32 timerunit;
    pmu_filter_select_e filterbypass;
    pmu_edge_type_e edgetype;
    uint32 filterCnt;
    uint32 SampleInterval;
} pmu_button_ctrl_t;

/**
 * @brief Get a readable string of PMU state.
 * @param[in]   state    To specify the pmu power state
 */
char *Mcu_PmuGetStateStr(pmu_state_e state);

/**
 * @brief Get PMU state.
 */
uint8 Mcu_PmuGetState(void);

/**
 * @brief Set PMU SF Por Power Good Controls.
 * @param[in] enable    To specify the por pg control enable
 */
void Mcu_PmuSetSfPorPgControl(pmu_pg_ctrl_e enable);

/**
 * @brief Set PMU AP Power Good Controls.
 * @param[in] enable    To specify the por pg control enable
 */
void Mcu_PmuSetAPPorPgControl(pmu_pg_ctrl_e enable);

/**
 * @brief Get wake up source.
 */
uint32 Mcu_PmuGetWakeupSource(void);

/**
 * @brief Set wake up source.
 * @param[in]   src    To specify the wakeup source
 */
void Mcu_PmuSetWakeupSource(pmu_wakeup_src_e src);

/**
 * @brief SRS_MCAL_E3_MCU_PMU_013:Get power-down request source.
 */
uint16 Mcu_PmuGetPowerDownReqSource(void);

/**
 * @brief Set power-down request source.
 * @param[in]   src    To specify the power down source
 */
void Mcu_PmuSetPowerDownReqSource( pmu_powerdown_src_e src);

/**
 * @brief  Set ButtonControl the state monitor Enable/Disable.
 * @param[in]   status    To specify Enable or disable
 */
void Mcu_PmuEnableButtonCtrlFsm(pmu_bc_moni_switch_e status);

/**
 * @brief  Set ButtonControl pin Enable/Disable.
 * @param[in]   status    To specify Enable or disable
 */
void Mcu_PmuEnableButtonCtrlPin(pmu_bc_switch_e status);

/**
 * @brief  Set ButtonControl Off Polarity.
 * @param[in]   polarity    To specify polarity is rising/falling or both
 */
void Mcu_PmuSetButtonCtrlOffPolarity(pmu_polarity_e polarity);

/**
 * @brief  Set ButtonControl On Polarity.
 * @param[in]   polarity    To specify polarity is rising/falling or both
 */
void Mcu_PmuSetButtonCtrlOnPolarity(pmu_polarity_e polarity);

/**
 * @brief  Set ButtonControl Polarity.
 * @param[in]   sensitive    To specify button off sensitive is edge or level
 */
void Mcu_PmuSetButtonCtrlOffSensitive(pmu_trigger_mode_e sensitive);

/**
 * @brief  Set ButtonControl Polarity.
 * @param[in]   sensitive    To specify button on sensitive is edge or level
 */
void Mcu_PmuSetButtonCtrlOnSensitive(pmu_trigger_mode_e sensitive);

/**
 * @brief  Set ButtonControl Filter Timer.
 * @param[in]   bc    To specify the timer:filter counter and sample interval.
 */
void Mcu_PmuSetButtonControlFilterTimer(uint16 filtercnt, uint16 sampleinterval);

/**
 * @brief  Set ButtonControl pin Max off valid window.
 * @param[in]   time    To specify the timer for max off window.
 */
void Mcu_PmuSetButtonCtrlMaxoffWindow(uint8 time);

/**
 * @brief  Set ButtonControl pin Min off valid window.
 * @param[in]   time    To specify delay time: delay time = BC_ON/OFF_VLD_MIN/MAX*(2^BC_CNT_UNIT)
 *                                             default value BC_CNT_UNIT = 5
 */
void Mcu_PmuSetButtonCtrlMinOffWindow(uint8 time);

/**
 * @brief  Set ButtonControl pin Max On valid window.
 * @param[in]   time    To specify delay time: delay time = BC_ON/OFF_VLD_MIN/MAX*(2^BC_CNT_UNIT)
 *                                             default value BC_CNT_UNIT = 5
 */
void Mcu_PmuSetButtonCtrlMaxOnWindow(uint8 time);

/**
 * @brief  Set ButtonControl pin Min On valid window.
 * @param[in]   time    To specify delay time: delay time = BC_ON/OFF_VLD_MIN/MAX*(2^BC_CNT_UNIT)
 *                                             default value BC_CNT_UNIT = 5
 */
void Mcu_PmuSetButtonCtrlMinOnWindow(uint8 time);

/**
 * @brief  Switch ButtonCtrl Pin max off window check.
 * @param[in]   status      To specify whether to disable bc max off valid window check
 */
void Mcu_PmuEnableButtonCtrlMaxOffWindow(pmu_bc_win_check_e status);

/**
 * @brief  Switch ButtonCtrl Pin max on window check.
 * @param[in]   status      To specify whether to disable bc max on valid window check
 */
void Mcu_PmuEnableButtonCtrlMaxOnWindowSwitch(pmu_bc_win_check_e status);

/**
 * @brief  Set Count Unit for ButtonControl.
 */
void Mcu_PmuSetButtonCtrlWindowTimerUnit(uint8 unit);

/**
 * @brief  Enable ButtonCtrl Pin filter bypass.
 * @param[in]   en      To specify whether to enable filter bypass
 */
void Mcu_PmuEnableButtonCtrlFilterBypass(pmu_filter_select_e en);

/**
 * @brief  Set ButtonCtrl Pin filter edge.
 * @param[in]   edge      To specify the filter edge.
 */
void Mcu_PmuSetButtonCtrlFilterEdge(pmu_edge_type_e edge);

/**
 * @brief  ButtonControl  Init.
 * @param[in]   bc    button set data
 */
void Mcu_PmuButtonControlInit(const pmu_button_ctrl_t *bc);

/**
* @brief  SRS_MCAL_E3_MCU_PMU_010: power control signals to external PMIC or desecrate power regulators.
* @param[in]   pmu_mode    pmu power mode
* @param[in]   id          pwrctrl_0~3
* @param[in]   mode        auto or manual
*/
void Mcu_PmuSetExtPwrctrlMode(pmu_state_e pmu_mode, pmu_pwrctrl_id_e id, pmu_auto_manual_e d1,
                              pmu_on_off_e d2);

/**
 * @brief Setup PMU power control signals up/down delays which take effect when power-downing and wakeup.
 * @param[in]   pmu_mode    pmu power mode
 * @param[in]   delay       power up delay
 * @param[in]   delay_adj   power up delay
 */
void Mcu_PmuSetExtPwrctrlDly(pmu_state_e pmu_mode,
                             pmu_pwrctrl_id_e id, uint8 delay,
                             uint8 delay_adj);

/**
 * @brief  external pwr ctrl io statu.
 * high level layer need check the mode/id/status range
 * @param[in]   id          pwr_ctrl0~3
 * @param[in]   polarity    high_active/low_active
 */
void Mcu_PmuSetExtPwrctrlPolarity(pmu_pwrctrl_id_e id, pmu_polarity_e polarity);

/**
 * @brief  external sw pwr ctrl io override enable.
 * high level layer need check the mode/id/status range
 * @param[in]   id          pwr_ctrl0~3
 * @param[in]   OverrideEnable    enable/disable
 */
void Mcu_PmuSetExtPwrctrlOverrideEnable(pmu_pwrctrl_id_e id,
                                        const pmu_pwrctrl_select_e OverrideEnable);

/**
 * @brief  external sw pwr ctrl io override value.
 * high level layer need check the mode/id/status range
 * @param[in]   id          pwr_ctrl0~3
 * @param[in]   value       HIGH/LOW
 */
void Mcu_PmuSetExtPwrctrlOverrideValue(pmu_pwrctrl_id_e id, const pmu_polarity_e value);

/**
* @brief  SRS_MCAL_E3_MCU_PMU_010: power control signals to internal DCDC/LDO.
* @param[in]   pmu_mode    power down delay
* @param[in]   id          pwron_0~3
* @param[in]   d1          auto or manual
* @param[in]   d2          on or off
* @param[in]   d3          Saf , ap  or other
*/
void Mcu_PmuSetInternalPwronMode(pmu_state_e pmu_mode, pmu_pwron_id_e id,
                                 pmu_auto_manual_e d1, pmu_on_off_e d2, pmu_target_e d3 );

/**
 * @brief  SRS_MCAL_E3_MCU_PMU_010:  configure SF power mode on  or off.
 * @param[in]   pmu_mode    power down delay
 * @param[in]   d1          on or off
 */
void Mcu_PmuSetSfPowerMode(pmu_state_e pmu_mode, pmu_on_off_e d1);

/**
 * @brief  SRS_MCAL_E3_MCU_PMU_010:  configure AP power mode on  or off.
 * @param[in]   pmu_mode    power down delay
 * @param[in]   d1          on or off
 */
void Mcu_PmuSetApPowerMode(pmu_state_e pmu_mode, pmu_on_off_e d1);

/**
 * @brief Setup PMU power on signal up/down delays which take effect when power-downing and wakeup.
 * @param[in]   pmu_mode    power down delay
 * @param[in]   delay      power up delay
 * @param[in]   delay_adj      power up delay
 */
void Mcu_PmuSetPwronDly(pmu_state_e pmu_mode, uint8 id, uint8 delay,  uint8 delay_adj);

/**
 *  SRS_MCAL_E3_MCU_PMU_006: Set to ignore power good from SF HV POR (then only RTC POR will be taken into consideration).
 * @param[in]   status      To specify whether ignore power good from AP/SF POR
 */
void Mcu_PmuSetIgnorePGFromSfHvPor(pmu_ignore_e status);

/**
 *  SRS_MCAL_E3_MCU_PMU_006: Set to ignore power good from SF LV POR (then only RTC POR will be taken into consideration).
 * @param[in]   status      To specify whether ignore power good from AP/SF POR
 */
void Mcu_PmuSetIgnorePGFromSfLvPor(pmu_ignore_e status);
/**
 *  SRS_MCAL_E3_MCU_PMU_006: Set to ignore power good from AP HV POR (then only RTC POR will be taken into consideration).
 * @param[in]   status      To specify whether ignore power good from AP/SF POR
 */
void Mcu_PmuSetIgnorePGFromApHvPor(pmu_ignore_e status);

/**
 *  SRS_MCAL_E3_MCU_PMU_006: Set to ignore power good from AP LV POR (then only RTC POR will be taken into consideration).
 * @param[in]   status      To specify whether ignore power good from AP/SF POR
 */
void Mcu_PmuSetIgnorePGFromApLvPor(pmu_ignore_e status);

/**
* @brief  SRS_MCAL_E3_MCU_PMU_012: Enable Wakeup01 to be wakeup source.
* @param[in]   enable      To Enable wakeup0 pin wakeup.
*/
void Mcu_PmuEnableWakeup01Pin(pmu_wakeup_src_enable_e enable);

/**
 * @brief  SRS_MCAL_E3_MCU_PMU_012: Disable Wakeup0 pin.
 * @param[in]   enable      To specify the wakeup0 pin wakeup whether be enable
 */
void Mcu_PmuEnableWakeup0Pin(pmu_wakeup_src_enable_e enable);

/**
 * @brief  SRS_MCAL_E3_MCU_PMU_012:Disable Wakeup1 pin.
 * @param[in]   enable      To specify the wakeup1 pin wakeup whether be enable
 */
void Mcu_PmuEnableWakeup1Pin(pmu_wakeup_src_enable_e enable);

/**
 * @brief Get wakeup0 enable status
 */
uint8 Mcu_PmuGetWakeup0EnableStatus(void);

/**
 * @brief Get Wakeup1 enable status
 */
uint8 Mcu_PmuGetWakeup1EnableStatus(void);

/**
 * @brief Get Wakeup0 pol
 */
uint8 Mcu_PmuGetWakeup0Pol(void);

/**
 * @brief Get Wakup1 pol
 */
uint8 Mcu_PmuGetWakeup1Pol(void);

/**
 * @brief  Set wakeup0 pin polarity.
 * @param[in]   polarity    high_active/low_active
 */
void Mcu_PmuSetWakeup0PinPolarity(pmu_polarity_e polarity);

/**
 * @brief  Set wakeup1 pin polarity.
 * @param[in]   polarity    high_active/low_active
 */
void Mcu_PmuSetWakeup1PinPolarity(pmu_polarity_e polarity);

/**
 * @brief  Set wakeup0 pin sensitive.
 * @param[in]   sensitive    PMU_TRIGGER_MODE_LEVEL/PMU_TRIGGER_MODE_EDGE
 */
void Mcu_PmuSetWakeup0PinSensitive(pmu_trigger_mode_e sensitive);

/**
 * @brief  Set wakeup1 pin sensitive.
 * @param[in]   sensitive    PMU_TRIGGER_MODE_LEVEL/PMU_TRIGGER_MODE_EDGE
 */
void Mcu_PmuSetWakeup1PinSensitive(pmu_trigger_mode_e sensitive);

/**
 * @brief  Enable wakeup0 pin wakeup.
 * @param[in]   enable    To specify whether enable wakeup0 pin.
 */
void Mcu_PmuEnableWakeup0Pin(pmu_wakeup_src_enable_e enable);

/**
 * @brief  Enable wakeup0 pin wakeup.
 * @param[in]   enable    To specify whether enable wakeup0 pin.
 */
void Mcu_PmuEnableWakeup1Pin(pmu_wakeup_src_enable_e enable);

/**
 * @brief  Enable wakeup01 pin wakeup.
 * @param[in]   enable    To specify the relation between wakeup0 pin and wakeup1 pin.
 */
void Mcu_PmuEnableWakeup01Pin(pmu_wakeup_src_enable_e enable);

/**
 * @brief  Enable wakeup0 pin filter bypass.
 * @param[in]   en    To specify whether enable filter.
 */
void Mcu_PmuEnableWakeup0FilterBypass(pmu_filter_select_e en);

/**
 * @brief  Enable wakeup1 pin filter bypass.
 * @param[in]   en    To specify whether enable filter.
 */
void Mcu_PmuEnableWakeup1FilterBypass(pmu_filter_select_e en);

/**
 * @brief  Set wakeup0 pin filter edge.
 * @param[in]   edgetype    To specify wakeup0 pin filter edge type.
 */
void Mcu_PmuSetWakeup0FilterEdge(pmu_edge_type_e edgetype);

/**
 * @brief  Set wakeup1 pin filter edge.
 * @param[in]   edgetype    To specify wakeup1 pin filter edge type.
 */
void Mcu_PmuSetWakeup1FilterEdge(pmu_edge_type_e edgetype);

/**
 * @brief  Set wakeup0 pin filter timer.
 * @param[in]   filtercnt    To specify wakeup0 pin filter timer WKUP0_FIELTER_CNT value.
 * @param[in]   sampleinterval    To specify wakeup0 pin filter timer WKUP0_SAMPLE_INTERVAL value.
 */
void Mcu_PmuSetWakeup0FilterTimer(uint16 filtercnt, uint16 sampleinterval);

/**
 * @brief  Set wakeup1 pin filter timer.
 * @param[in]   filtercnt    To specify wakeup1 pin filter timer WKUP1_FIELTER_CNT value.
 * @param[in]   sampleinterval    To specify wakeup1 pin filter timer WKUP1_SAMPLE_INTERVAL value.
 */
void Mcu_PmuSetWakeup1FilterTimer(uint16 filtercnt, uint16 sampleinterval);

/**
 * @brief  SRS_MCAL_E3_MCU_PMU_008:lock SRCS State Retention Control Signaling) registers..
 * @param[in]   data      To specify the lock data
 */
void Mcu_PmuLockSRCSStateRetentionBits(uint32 data);

/**
 * @brief  SRS_MCAL_E3_MCU_PMU_008:lock SRCS State Retention Control Signaling) registers..
 * @param[in]   data      To specify the lock data
 */
void Mcu_PmuSetSRCSStateRetentionBits(uint32 data);

/**
 * @brief  SRS_MCAL_E3_MCU_PMU_008:set SRCS State Retention Control Signaling) registers.
 * @param[in]   data      To specify the Set data
 */
void Mcu_PmuSetSRCSStateRetentionBits(uint32 data);

/**
 * @brief  SRS_MCAL_E3_MCU_PMU_008:clr SRCS State Retention Control Signaling) registers.
 * @param[in]   data      To specify the Clear data
 */
void Mcu_PmuClrSRCSStateRetentionBits(uint32 data);

/**
 * @brief  SRS_MCAL_E3_MCU_PMU_012: Enable Wakeup0 to be wakeup source.
 * @param[in]   *wakeupctl      include the configure that wakeup source refer detect mode, edge select, fileter etc.
 */
void Mcu_PmuEnableWakeup0Wakeup(const pmu_pin_ctrl_t *wakeupctl);

/**
* @brief  SRS_MCAL_E3_MCU_PMU_012: Enable Wakeup1 to be wakeup source.
* @param[in]   *wakeupctl      include the configure that wakeup source refer detect mode, edge select, fileter etc.
*/
void Mcu_PmuEnableWakeup1Wakeup(const pmu_pin_ctrl_t *wakeupctl);

/**
 * @brief  SRS_MCAL_E3_MCU_PMU_012: Enable BC button wakeup.
 * @param[in]   enable      To specify the rtc wakeup whether be enable
 */
void Mcu_PmuEnableExtWakeupSrc(pmu_wakeup_src_enable_e enable);

/**
 * @brief Enable rtc wakeup
 * @param[in]   enable      To specify the rtc wakeup whether be enable
 */
void Mcu_PmuEnableIntWakeupSrc(pmu_wakeup_src_enable_e enable);

/**
 * @brief power down safety/ap subsystem and enter RTC mode (PMU_STATE=OFF).
 */
void Mcu_PmuPwrdown(void);

/**
 * @brief Callback which shall be called right after a wakeup from DeepSleep.
 */
void Mcu_PmuResumeCb(void);

/**
 * @brief close/open DCDC.
 */
void Mcu_PmuDcdcEn(bool en);

/**
 * @brief close/open LDO.
 */
void Mcu_PmuLdoEn(bool en);

#ifdef __cplusplus
}
#endif

#endif  /* ifndef MCU_PMU_H */
