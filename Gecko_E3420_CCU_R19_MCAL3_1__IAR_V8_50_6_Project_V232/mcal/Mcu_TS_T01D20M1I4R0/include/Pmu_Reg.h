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
 *  \file     Pmu_Reg.h                                                                                 *
 *  \brief    This file contains interface header for MCU MCAL driver, ...                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/03     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef PMU_REG_H
#define PMU_REG_H

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/

/* Register define Start */
//--------------------------------------------------------------------------
// Register Name   : BC_VLD_WINDOW
// Register Offset : 0x0
// Description     : ON or OFF valid window setting for ButtonControl pin
//--------------------------------------------------------------------------
#define BC_VLD_WINDOW   0x0U

#define FM_BC_VLD_WINDOW_BC_OFF_VLD_MAX ((uint32)0xffU << 24U)
#define FV_BC_VLD_WINDOW_BC_OFF_VLD_MAX(v) \
    ((((uint32)(v)) << 24U) & FM_BC_VLD_WINDOW_BC_OFF_VLD_MAX)
#define GFV_BC_VLD_WINDOW_BC_OFF_VLD_MAX(v) \
    (((v) & FM_BC_VLD_WINDOW_BC_OFF_VLD_MAX) >> 24U)

#define FM_BC_VLD_WINDOW_BC_OFF_VLD_MIN ((uint32)0xffU << 16U)
#define FV_BC_VLD_WINDOW_BC_OFF_VLD_MIN(v) \
    ((((uint32)(v)) << 16U) & FM_BC_VLD_WINDOW_BC_OFF_VLD_MIN)
#define GFV_BC_VLD_WINDOW_BC_OFF_VLD_MIN(v) \
    (((v) & FM_BC_VLD_WINDOW_BC_OFF_VLD_MIN) >> 16U)

#define FM_BC_VLD_WINDOW_BC_ON_VLD_MAX  ((uint32)0xffU << 8U)
#define FV_BC_VLD_WINDOW_BC_ON_VLD_MAX(v) \
    ((((uint32)(v)) << 8U) & FM_BC_VLD_WINDOW_BC_ON_VLD_MAX)
#define GFV_BC_VLD_WINDOW_BC_ON_VLD_MAX(v) \
    (((v) & FM_BC_VLD_WINDOW_BC_ON_VLD_MAX) >> 8U)

#define FM_BC_VLD_WINDOW_BC_ON_VLD_MIN  ((uint32)0xffU << 0U)
#define FV_BC_VLD_WINDOW_BC_ON_VLD_MIN(v) \
    ((((uint32)(v)) << 0U) & FM_BC_VLD_WINDOW_BC_ON_VLD_MIN)
#define GFV_BC_VLD_WINDOW_BC_ON_VLD_MIN(v) \
    (((v) & FM_BC_VLD_WINDOW_BC_ON_VLD_MIN) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : BC_CTRL_SET
// Register Offset : 0x4
// Description     : control settings for ButtonControl pin
//--------------------------------------------------------------------------
#define BC_CTRL_SET 0x4U

#define FM_BC_CTRL_SET_PWR_DWN_HW_REQ_ENABLE    ((uint32)0xffU << 24U)
#define FV_BC_CTRL_SET_PWR_DWN_HW_REQ_ENABLE(v) \
    ((((uint32)(v)) << 24U) & FM_BC_CTRL_SET_PWR_DWN_HW_REQ_ENABLE)
#define GFV_BC_CTRL_SET_PWR_DWN_HW_REQ_ENABLE(v) \
    (((v) & FM_BC_CTRL_SET_PWR_DWN_HW_REQ_ENABLE) >> 24U)

#define BM_BC_CTRL_SET_PWR_DWN_REQ_SOFT ((uint32)0x01U << 23U)

#define FM_BC_CTRL_SET_BC_FILTER_EDGE   ((uint32)0x3U << 21U)
#define FV_BC_CTRL_SET_BC_FILTER_EDGE(v) \
    ((((uint32)(v)) << 21U) & FM_BC_CTRL_SET_BC_FILTER_EDGE)
#define GFV_BC_CTRL_SET_BC_FILTER_EDGE(v) \
    (((v) & FM_BC_CTRL_SET_BC_FILTER_EDGE) >> 21U)

#define FM_BC_CTRL_SET_BC_FILTER_CNT    ((uint32)0xfU << 17U)
#define FV_BC_CTRL_SET_BC_FILTER_CNT(v) \
    ((((uint32)(v)) << 17U) & FM_BC_CTRL_SET_BC_FILTER_CNT)
#define GFV_BC_CTRL_SET_BC_FILTER_CNT(v) \
    (((v) & FM_BC_CTRL_SET_BC_FILTER_CNT) >> 17U)

#define FM_BC_CTRL_SET_BC_SAMPLE_INTERVAL   ((uint32)0x7U << 14U)
#define FV_BC_CTRL_SET_BC_SAMPLE_INTERVAL(v) \
    ((((uint32)(v)) << 14U) & FM_BC_CTRL_SET_BC_SAMPLE_INTERVAL)
#define GFV_BC_CTRL_SET_BC_SAMPLE_INTERVAL(v) \
    (((v) & FM_BC_CTRL_SET_BC_SAMPLE_INTERVAL) >> 14U)

#define BM_BC_CTRL_SET_BC_FILTER_BYPASS ((uint32)0x01U << 13U)

#define BM_BC_CTRL_SET_BC_DISABLE_LOCK  ((uint32)0x01U << 12U)

#define BM_BC_CTRL_SET_BC_DISABLE   ((uint32)0x01U << 11U)

#define BM_BC_CTRL_SET_BC_FSM_ENABLE    ((uint32)0x01U << 10U)

#define BM_BC_CTRL_SET_BC_OFF_EDGE  ((uint32)0x01U << 9U)

#define BM_BC_CTRL_SET_BC_ON_EDGE   ((uint32)0x01U << 8U)

#define BM_BC_CTRL_SET_BC_OFF_POL   ((uint32)0x01U << 7U)

#define BM_BC_CTRL_SET_BC_ON_POL    ((uint32)0x01U << 6U)

#define BM_BC_CTRL_SET_BC_OFF_VLD_MAX_DISABLE   ((uint32)0x01U << 5U)

#define BM_BC_CTRL_SET_BC_ON_VLD_MAX_DISABLE    ((uint32)0x01U << 4U)

#define FM_BC_CTRL_SET_BC_CNT_UNIT  ((uint32)0xfU << 0U)
#define FV_BC_CTRL_SET_BC_CNT_UNIT(v) \
    ((((uint32)(v)) << 0U) & FM_BC_CTRL_SET_BC_CNT_UNIT)
#define GFV_BC_CTRL_SET_BC_CNT_UNIT(v) \
    (((v) & FM_BC_CTRL_SET_BC_CNT_UNIT) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : WAKEUP_CTRL
// Register Offset : 0x8
// Description     : control settins for Wakeup pin 0/1
//--------------------------------------------------------------------------
#define WAKEUP_CTRL 0x8U

#define BM_WAKEUP_CTRL_WKUP01_AND_ENABLE    ((uint32)0x01U << 31U)

#define BM_WAKEUP_CTRL_WKUP1_DISABLE    ((uint32)0x01U << 30U)

#define BM_WAKEUP_CTRL_WKUP0_DISABLE    ((uint32)0x01U << 29U)

#define BM_WAKEUP_CTRL_WKUP1_POL    ((uint32)0x01U << 28U)

#define BM_WAKEUP_CTRL_WKUP0_POL    ((uint32)0x01U << 27U)

#define BM_WAKEUP_CTRL_WKUP1_EDGE   ((uint32)0x01U << 26U)

#define BM_WAKEUP_CTRL_WKUP0_EDGE   ((uint32)0x01U << 25U)

#define BM_WAKEUP_CTRL_WAKEUP_IN_RTC_LATCH  ((uint32)0x01U << 22U)

#define BM_WAKEUP_CTRL_EXT_WAKEUP_EN    ((uint32)0x01U << 21U)

#define BM_WAKEUP_CTRL_INT_WAKEUP_EN    ((uint32)0x01U << 20U)

#define BM_SW_OVRRIDE_OFFSET 0x54U

#define FM_WAKEUP_CTRL_WKUP1_FILTER_EDGE    ((uint32)0x3U << 18U)
#define FV_WAKEUP_CTRL_WKUP1_FILTER_EDGE(v) \
    ((((uint32)(v)) << 18U) & FM_WAKEUP_CTRL_WKUP1_FILTER_EDGE)
#define GFV_WAKEUP_CTRL_WKUP1_FILTER_EDGE(v) \
    (((v) & FM_WAKEUP_CTRL_WKUP1_FILTER_EDGE) >> 18U)

#define FM_WAKEUP_CTRL_WKUP1_FILTER_CNT ((uint32)0xfU << 14U)
#define FV_WAKEUP_CTRL_WKUP1_FILTER_CNT(v) \
    ((((uint32)(v)) << 14U) & FM_WAKEUP_CTRL_WKUP1_FILTER_CNT)
#define GFV_WAKEUP_CTRL_WKUP1_FILTER_CNT(v) \
    (((v) & FM_WAKEUP_CTRL_WKUP1_FILTER_CNT) >> 14U)

#define FM_WAKEUP_CTRL_WKUP1_SAMPLE_INTERVAL    ((uint32)0x7U << 11U)
#define FV_WAKEUP_CTRL_WKUP1_SAMPLE_INTERVAL(v) \
    ((((uint32)(v)) << 11U) & FM_WAKEUP_CTRL_WKUP1_SAMPLE_INTERVAL)
#define GFV_WAKEUP_CTRL_WKUP1_SAMPLE_INTERVAL(v) \
    (((v) & FM_WAKEUP_CTRL_WKUP1_SAMPLE_INTERVAL) >> 11U)

#define BM_WAKEUP_CTRL_WKUP1_FILTER_BYPASS  ((uint32)0x01U << 10U)

#define FM_WAKEUP_CTRL_WKUP0_FILTER_EDGE    ((uint32)0x3U << 8U)
#define FV_WAKEUP_CTRL_WKUP0_FILTER_EDGE(v) \
    ((((uint32)(v)) << 8U) & FM_WAKEUP_CTRL_WKUP0_FILTER_EDGE)
#define GFV_WAKEUP_CTRL_WKUP0_FILTER_EDGE(v) \
    (((v) & FM_WAKEUP_CTRL_WKUP0_FILTER_EDGE) >> 8U)

#define FM_WAKEUP_CTRL_WKUP0_FILTER_CNT ((uint32)0xfU << 4U)
#define FV_WAKEUP_CTRL_WKUP0_FILTER_CNT(v) \
    ((((uint32)(v)) << 4U) & FM_WAKEUP_CTRL_WKUP0_FILTER_CNT)
#define GFV_WAKEUP_CTRL_WKUP0_FILTER_CNT(v) \
    (((v) & FM_WAKEUP_CTRL_WKUP0_FILTER_CNT) >> 4U)

#define FM_WAKEUP_CTRL_WKUP0_SAMPLE_INTERVAL    ((uint32)0x7U << 1U)
#define FV_WAKEUP_CTRL_WKUP0_SAMPLE_INTERVAL(v) \
    ((((uint32)(v)) << 1U) & FM_WAKEUP_CTRL_WKUP0_SAMPLE_INTERVAL)
#define GFV_WAKEUP_CTRL_WKUP0_SAMPLE_INTERVAL(v) \
    (((v) & FM_WAKEUP_CTRL_WKUP0_SAMPLE_INTERVAL) >> 1U)

#define BM_WAKEUP_CTRL_WKUP0_FILTER_BYPASS  ((uint32)0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : PWR_CTRL_SET0
// Register Offset : 0x10
// Description     : setting0 for pwr_ctrl0~3
//--------------------------------------------------------------------------
#define PWR_CTRL_SET0   0x10U

#define FM_PWR_CTRL_SET0_PWR_CTRL_SET_MASK  (0x3U)
#define BM_PWR_CTRL_SET0_RTC_PWR_CTRL       (24U)
#define BM_PWR_CTRL_SET0_RUN_PWR_CTRL       (16U)
#define BM_PWR_CTRL_SET0_SLEEP_PWR_CTRL     (8U)
#define BM_PWR_CTRL_SET0_HIBERNATE_PWR_CTRL (0U)

#define FM_PWR_CTRL_SET0_RTC_PWR_CTRL_SET0  ((uint32)0xffU << 24U)
#define FV_PWR_CTRL_SET0_RTC_PWR_CTRL_SET0(v) \
    ((((uint32)(v)) << 24U) & FM_PWR_CTRL_SET0_RTC_PWR_CTRL_SET0)
#define GFV_PWR_CTRL_SET0_RTC_PWR_CTRL_SET0(v) \
    (((v) & FM_PWR_CTRL_SET0_RTC_PWR_CTRL_SET0) >> 24U)

#define FM_PWR_CTRL_SET0_RUN_PWR_CTRL_SET0  ((uint32)0xffU << 16U)
#define FV_PWR_CTRL_SET0_RUN_PWR_CTRL_SET0(v) \
    ((((uint32)(v)) << 16U) & FM_PWR_CTRL_SET0_RUN_PWR_CTRL_SET0)
#define GFV_PWR_CTRL_SET0_RUN_PWR_CTRL_SET0(v) \
    (((v) & FM_PWR_CTRL_SET0_RUN_PWR_CTRL_SET0) >> 16U)

#define FM_PWR_CTRL_SET0_SLEEP_PWR_CTRL_SET0    ((uint32)0xffU << 8U)
#define FV_PWR_CTRL_SET0_SLEEP_PWR_CTRL_SET0(v) \
    ((((uint32)(v)) << 8U) & FM_PWR_CTRL_SET0_SLEEP_PWR_CTRL_SET0)
#define GFV_PWR_CTRL_SET0_SLEEP_PWR_CTRL_SET0(v) \
    (((v) & FM_PWR_CTRL_SET0_SLEEP_PWR_CTRL_SET0) >> 8U)

#define FM_PWR_CTRL_SET0_HIBERNATE_PWR_CTRL_SET0    ((uint32)0xffU << 0U)
#define FV_PWR_CTRL_SET0_HIBERNATE_PWR_CTRL_SET0(v) \
    ((((uint32)(v)) << 0U) & FM_PWR_CTRL_SET0_HIBERNATE_PWR_CTRL_SET0)
#define GFV_PWR_CTRL_SET0_HIBERNATE_PWR_CTRL_SET0(v) \
    (((v) & FM_PWR_CTRL_SET0_HIBERNATE_PWR_CTRL_SET0) >> 0U)

#define FM_BC_VLD_WINDOW_BC_ON_VLD_MAX  ((uint32)0xffU << 8U)
#define FV_BC_VLD_WINDOW_BC_ON_VLD_MAX(v) \
    ((((uint32)(v)) << 8U) & FM_BC_VLD_WINDOW_BC_ON_VLD_MAX)


//--------------------------------------------------------------------------
// Register Name   : PWR_CTRL_SET1
// Register Offset : 0x14
// Description     : setting1 for pwr_ctrl0~3
//--------------------------------------------------------------------------
#define PWR_CTRL_SET1       0x14U

#define BM_PWR_CTRL_SET1_PWR_UP_RUN_MIN_DELAY_ENABLE    ((uint32)0x01U << 31U)

#define BM_PWR_CTRL_SET1_SLEEP_RUN_MIN_DELAY_ENABLE ((uint32)0x01U << 30U)

#define BM_PWR_CTRL_SET1_HIBERNATE_RUN_MIN_DELAY_ENABLE ((uint32)0x01U << 29U)

#define BM_PWR_CTRL_SET1_PWR_CTRL_POL     (20U)
#define BM_PWR_CTRL_SET1_SW_PWR_CTRL_EN   (12U)
#define BM_PWR_CTRL_SET1_SW_PWR_CTRL      (8U)

#define FM_PWR_CTRL_SET1_PWR_CTRL_POL   ((uint32)0xfU << 20U)
#define FV_PWR_CTRL_SET1_PWR_CTRL_POL(v) \
    ((((uint32)(v)) << 20U) & FM_PWR_CTRL_SET1_PWR_CTRL_POL)
#define GFV_PWR_CTRL_SET1_PWR_CTRL_POL(v) \
    (((v) & FM_PWR_CTRL_SET1_PWR_CTRL_POL) >> 20U)

#define FM_PWR_CTRL_SET1_SW_PWR_CTRL_EN ((uint32)0xfU << 12U)
#define FV_PWR_CTRL_SET1_SW_PWR_CTRL_EN(v) \
    ((((uint32)(v)) << 12U) & FM_PWR_CTRL_SET1_SW_PWR_CTRL_EN)
#define GFV_PWR_CTRL_SET1_SW_PWR_CTRL_EN(v) \
    (((v) & FM_PWR_CTRL_SET1_SW_PWR_CTRL_EN) >> 12U)

#define FM_PWR_CTRL_SET1_SW_PWR_CTRL    ((uint32)0xfU << 8U)
#define FV_PWR_CTRL_SET1_SW_PWR_CTRL(v) \
    ((((uint32)(v)) << 8U) & FM_PWR_CTRL_SET1_SW_PWR_CTRL)
#define GFV_PWR_CTRL_SET1_SW_PWR_CTRL(v) \
    (((v) & FM_PWR_CTRL_SET1_SW_PWR_CTRL) >> 8U)

//--------------------------------------------------------------------------
// Register Name   : PWR_UP_PWR_CTRL_DELAY
// Register Offset : 0x18
// Description     : delay setting in PWR_UP state for pwr_ctrl0-3
//--------------------------------------------------------------------------
#define PWR_UP_PWR_CTRL_DELAY   0x18U

#define FM_PWR_UP_PWR_CTRL_DELAY_PWR_UP_PWR_CTRL_MAX    ((uint32)0x3U << 30U)
#define FV_PWR_UP_PWR_CTRL_DELAY_PWR_UP_PWR_CTRL_MAX(v) \
    ((((uint32)(v)) << 30U) & FM_PWR_UP_PWR_CTRL_DELAY_PWR_UP_PWR_CTRL_MAX)
#define GFV_PWR_UP_PWR_CTRL_DELAY_PWR_UP_PWR_CTRL_MAX(v) \
    (((v) & FM_PWR_UP_PWR_CTRL_DELAY_PWR_UP_PWR_CTRL_MAX) >> 30U)

#define FM_PWR_UP_PWR_CTRL_DELAY_PWR_UP_PWR_CTRL_DELAY  ((uint32)0xffffffU << 0U)
#define FV_PWR_UP_PWR_CTRL_DELAY_PWR_UP_PWR_CTRL_DELAY(v) \
    ((((uint32)(v)) << 0U) & FM_PWR_UP_PWR_CTRL_DELAY_PWR_UP_PWR_CTRL_DELAY)
#define GFV_PWR_UP_PWR_CTRL_DELAY_PWR_UP_PWR_CTRL_DELAY(v) \
    (((v) & FM_PWR_UP_PWR_CTRL_DELAY_PWR_UP_PWR_CTRL_DELAY) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : RUN_PWR_CTRL_DELAY
// Register Offset : 0x1c
// Description     : delay setting in RUN state for pwr_ctrl0-3
//--------------------------------------------------------------------------
#define RUN_PWR_CTRL_DELAY  0x1cU

#define FM_RUN_PWR_CTRL_DELAY_RUN_PWR_CTRL_MAX  ((uint32)0x3U << 30U)
#define FV_RUN_PWR_CTRL_DELAY_RUN_PWR_CTRL_MAX(v) \
    ((((uint32)(v)) << 30U) & FM_RUN_PWR_CTRL_DELAY_RUN_PWR_CTRL_MAX)
#define GFV_RUN_PWR_CTRL_DELAY_RUN_PWR_CTRL_MAX(v) \
    (((v) & FM_RUN_PWR_CTRL_DELAY_RUN_PWR_CTRL_MAX) >> 30U)

#define FM_RUN_PWR_CTRL_DELAY_RUN_PWR_CTRL_DELAY    ((uint32)0xffffffU << 0U)
#define FV_RUN_PWR_CTRL_DELAY_RUN_PWR_CTRL_DELAY(v) \
    ((((uint32)(v)) << 0U) & FM_RUN_PWR_CTRL_DELAY_RUN_PWR_CTRL_DELAY)
#define GFV_RUN_PWR_CTRL_DELAY_RUN_PWR_CTRL_DELAY(v) \
    (((v) & FM_RUN_PWR_CTRL_DELAY_RUN_PWR_CTRL_DELAY) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : SLEEP_PWR_CTRL_DELAY
// Register Offset : 0x20
// Description     : delay setting in SLEEP state for pwr_ctrl0-3
//--------------------------------------------------------------------------
#define SLEEP_PWR_CTRL_DELAY    0x20U

#define FM_SLEEP_PWR_CTRL_DELAY_SLEEP_PWR_CTRL_MAX  ((uint32)0x3U << 30U)
#define FV_SLEEP_PWR_CTRL_DELAY_SLEEP_PWR_CTRL_MAX(v) \
    ((((uint32)(v)) << 30U) & FM_SLEEP_PWR_CTRL_DELAY_SLEEP_PWR_CTRL_MAX)
#define GFV_SLEEP_PWR_CTRL_DELAY_SLEEP_PWR_CTRL_MAX(v) \
    (((v) & FM_SLEEP_PWR_CTRL_DELAY_SLEEP_PWR_CTRL_MAX) >> 30U)

#define FM_SLEEP_PWR_CTRL_DELAY_SLEEP_PWR_CTRL_DELAY    ((uint32)0xffffffU << 0U)
#define FV_SLEEP_PWR_CTRL_DELAY_SLEEP_PWR_CTRL_DELAY(v) \
    ((((uint32)(v)) << 0U) & FM_SLEEP_PWR_CTRL_DELAY_SLEEP_PWR_CTRL_DELAY)
#define GFV_SLEEP_PWR_CTRL_DELAY_SLEEP_PWR_CTRL_DELAY(v) \
    (((v) & FM_SLEEP_PWR_CTRL_DELAY_SLEEP_PWR_CTRL_DELAY) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : HIBERNATE_PWR_CTRL_DELAY
// Register Offset : 0x24
// Description     : delay setting in HIBERNATE state for pwr_ctrl0-3
//--------------------------------------------------------------------------
#define HIBERNATE_PWR_CTRL_DELAY    0x24U

#define FM_HIBERNATE_PWR_CTRL_DELAY_HIBERNATE_PWR_CTRL_MAX  ((uint32)0x3U << 30U)
#define FV_HIBERNATE_PWR_CTRL_DELAY_HIBERNATE_PWR_CTRL_MAX(v) \
    ((((uint32)(v)) << 30U) & FM_HIBERNATE_PWR_CTRL_DELAY_HIBERNATE_PWR_CTRL_MAX)
#define GFV_HIBERNATE_PWR_CTRL_DELAY_HIBERNATE_PWR_CTRL_MAX(v) \
    (((v) & FM_HIBERNATE_PWR_CTRL_DELAY_HIBERNATE_PWR_CTRL_MAX) >> 30U)

#define FM_HIBERNATE_PWR_CTRL_DELAY_HIBERNATE_PWR_CTRL_DELAY    ((uint32)0xffffffU << 0U)
#define FV_HIBERNATE_PWR_CTRL_DELAY_HIBERNATE_PWR_CTRL_DELAY(v) \
    ((((uint32)(v)) << 0U) & FM_HIBERNATE_PWR_CTRL_DELAY_HIBERNATE_PWR_CTRL_DELAY)
#define GFV_HIBERNATE_PWR_CTRL_DELAY_HIBERNATE_PWR_CTRL_DELAY(v) \
    (((v) & FM_HIBERNATE_PWR_CTRL_DELAY_HIBERNATE_PWR_CTRL_DELAY) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : RTC_PWR_CTRL_DELAY
// Register Offset : 0x28
// Description     : delay setting in RTC state for pwr_ctrl0-3
//--------------------------------------------------------------------------
#define RTC_PWR_CTRL_DELAY  0x28U

#define FM_RTC_PWR_CTRL_DELAY_RTC_PWR_CTRL_MAX  ((uint32)0x3U << 30U)
#define FV_RTC_PWR_CTRL_DELAY_RTC_PWR_CTRL_MAX(v) \
    ((((uint32)(v)) << 30U) & FM_RTC_PWR_CTRL_DELAY_RTC_PWR_CTRL_MAX)
#define GFV_RTC_PWR_CTRL_DELAY_RTC_PWR_CTRL_MAX(v) \
    (((v) & FM_RTC_PWR_CTRL_DELAY_RTC_PWR_CTRL_MAX) >> 30U)

#define FM_RTC_PWR_CTRL_DELAY_RTC_PWR_CTRL_DELAY    ((uint32)0xffffffU << 0U)
#define FV_RTC_PWR_CTRL_DELAY_RTC_PWR_CTRL_DELAY(v) \
    ((((uint32)(v)) << 0U) & FM_RTC_PWR_CTRL_DELAY_RTC_PWR_CTRL_DELAY)
#define GFV_RTC_PWR_CTRL_DELAY_RTC_PWR_CTRL_DELAY(v) \
    (((v) & FM_RTC_PWR_CTRL_DELAY_RTC_PWR_CTRL_DELAY) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : RUN_PWR_ON_SET
// Register Offset : 0x30
// Description     : setting for pwr_on0~3 in RUN state
//--------------------------------------------------------------------------
#define RUN_PWR_ON_SET  0x30U

#define FM_RUN_PWR_ON_SET_RUN_PWR_ON0_SET   ((uint32)0xfU << 0U)
#define FV_RUN_PWR_ON_SET_RUN_PWR_ON0_SET(v) \
    ((((uint32)(v)) << 0U) & FM_RUN_PWR_ON_SET_RUN_PWR_ON0_SET)
#define GFV_RUN_PWR_ON_SET_RUN_PWR_ON0_SET(v) \
    (((v) & FM_RUN_PWR_ON_SET_RUN_PWR_ON_SET) >> 0U)

#define BM_RUN_PWR_ON_SET_SF_PWR_ON_SET  ((uint32)0x1U << 17U)
#define BM_RUN_PWR_ON_SET_AP_PWR_ON_SET  ((uint32)0x1U << 16U)

//--------------------------------------------------------------------------
// Register Name   : SLEEP_PWR_ON_SET
// Register Offset : 0x34
// Description     : setting for pwr_on0~3 in SLEEP state
//--------------------------------------------------------------------------
#define SLEEP_PWR_ON_SET    0x34U

#define FM_SLEEP_PWR_ON_SET_SLEEP_PWR_ON0_SET   ((uint32)0xfU << 0U)
#define FV_SLEEP_PWR_ON_SET_SLEEP_PWR_ON0_SET(v) \
    ((((uint32)(v)) << 0U) & FM_SLEEP_PWR_ON_SET_SLEEP_PWR_ON0_SET)
#define GFV_SLEEP_PWR_ON_SET_SLEEP_PWR_ON0_SET(v) \
    (((v) & FM_SLEEP_PWR_ON_SET_SLEEP_PWR_ON_SET) >> 0U)

#define BM_SLEEP_PWR_ON_SET_AP_PWR_ON_SET    ((uint32)0x1U << 16U)
#define BM_SLEEP_PWR_ON_SET_SF_PWR_ON_SET    ((uint32)0x1U << 17U)

//--------------------------------------------------------------------------
// Register Name   : HIBERNATE_PWR_ON_SET
// Register Offset : 0x38
// Description     : setting for pwr_on0~3 in HIBERNATE state
//--------------------------------------------------------------------------
#define HIBERNATE_PWR_ON_SET    0x38U

#define FM_HIBERNATE_PWR_ON_SET_HIBERNATE_PWR_ON0_SET   ((uint32)0xfU << 0U)

#define FV_HIBERNATE_PWR_ON_SET_HIBERNATE_PWR_ON0_SET(v) \
    ((((uint32)(v)) << 0U) & FM_HIBERNATE_PWR_ON_SET_HIBERNATE_PWR_ON0_SET)
#define GFV_HIBERNATE_PWR_ON_SET_HIBERNATE_PWR_ON0_SET(v) \
    (((v) & FM_HIBERNATE_PWR_ON_SET_HIBERNATE_PWR_ON_SET) >> 0U)

#define BM_HIBERNATE_PWR_ON_SET_AP_PWR_ON_SET    ((uint32)0x1U << 16U)
#define BM_HIBERNATE_PWR_ON_SET_SF_PWR_ON_SET    ((uint32)0x1U << 17U)

//--------------------------------------------------------------------------
// Register Name   : RTC_PWR_ON_SET
// Register Offset : 0x3c
// Description     : setting for pwr_on0~3 in RTC state
//--------------------------------------------------------------------------
#define RTC_PWR_ON_SET  0x3cU

#define FM_RTC_PWR_ON_SET_RTC_PWR_ON0_SET   ((uint32)0xfU << 0U)
#define FV_RTC_PWR_ON_SET_RTC_PWR_ON0_SET(v) \
    ((((uint32)(v)) << 0U) & FM_RTC_PWR_ON_SET_RTC_PWR_ON0_SET)
#define GFV_RTC_PWR_ON_SET_RTC_PWR_ON0_SET(v) \
    (((v) & FM_RTC_PWR_ON_SET_RTC_PWR_ON_SET) >> 0U)

#define FM_RTC_PWR_ON_SET_RTC_PWR_ON1_SET   ((uint32)0xfU << 4U)
#define FV_RTC_PWR_ON_SET_RTC_PWR_ON1_SET(v) \
    ((((uint32)(v)) << 4U) & FM_RTC_PWR_ON_SET_RTC_PWR_ON1_SET)
#define GFV_RTC_PWR_ON_SET_RTC_PWR_ON1_SET(v) \
    (((v) & FM_RTC_PWR_ON_SET_RTC_PWR_ON1_SET) >> 4U)

#define FM_RTC_PWR_ON_SET_RTC_PWR_ON2_SET   ((uint32)0xfU << 8U)
#define FV_RTC_PWR_ON_SET_RTC_PWR_ON2_SET(v) \
    ((((uint32)(v)) << 8U) & FM_RTC_PWR_ON_SET_RTC_PWR_ON2_SET)
#define GFV_RTC_PWR_ON_SET_RTC_PWR_ON2_SET(v) \
    (((v) & FM_RTC_PWR_ON_SET_RTC_PWR_ON2_SET) >> 8U)

#define FM_RTC_PWR_ON_SET_RTC_PWR_ON3_SET   ((uint32)0xfU << 12U)
#define FV_RTC_PWR_ON_SET_RTC_PWR_ON3_SET(v) \
    ((((uint32)(v)) << 12U) & FM_RTC_PWR_ON_SET_RTC_PWR_ON3_SET)
#define GFV_RTC_PWR_ON_SET_RTC_PWR_ON3_SET(v) \
    (((v) & FM_RTC_PWR_ON_SET_RTC_PWR_ON3_SET) >> 12U)

#define BM_RTC_PWR_ON_SET_AP_PWR_ON_SET  ((uint32)0x1U << 16U)

#define BM_RTC_PWR_ON_SET_SF_PWR_ON_SET  ((uint32)0x1U << 17U)

#define BM_RTC_PWR_ON_SET_RTC_TO_OFF_AP_LV_PG_DISABLE  ((uint32)0x01U << 28U)

#define BM_RTC_PWR_ON_SET_RTC_TO_OFF_AP_HV_PG_DISABLE  ((uint32)0x01U << 29U)

#define BM_RTC_PWR_ON_SET_RTC_TO_OFF_SF_LV_PG_DISABLE  ((uint32)0x01U << 30U)

#define BM_RTC_PWR_ON_SET_RTC_TO_OFF_SF_HV_PG_DISABLE  ((uint32)0x01U << 31U)

//--------------------------------------------------------------------------
// Register Name   : PWR_UP_PWR_ON_DELAY
// Register Offset : 0x40
// Description     : Delay setting of pwr_on0~3 in PWR_UP state
//--------------------------------------------------------------------------
#define PWR_UP_PWR_ON_DELAY 0x40U

#define FM_PWR_UP_PWR_ON_DELAY_PWR_UP_PWR_ON_AP_MAX ((uint32)0x3U << 30U)
#define FV_PWR_UP_PWR_ON_DELAY_PWR_UP_PWR_ON_AP_MAX(v) \
    ((((uint32)(v)) << 30U) & FM_PWR_UP_PWR_ON_DELAY_PWR_UP_PWR_ON_AP_MAX)
#define GFV_PWR_UP_PWR_ON_DELAY_PWR_UP_PWR_ON_AP_MAX(v) \
    (((v) & FM_PWR_UP_PWR_ON_DELAY_PWR_UP_PWR_ON_AP_MAX) >> 30U)

#define FM_PWR_UP_PWR_ON_DELAY_PWR_UP_PWR_ON_SF_MAX ((uint32)0x3U << 28U)
#define FV_PWR_UP_PWR_ON_DELAY_PWR_UP_PWR_ON_SF_MAX(v) \
    ((((uint32)(v)) << 28U) & FM_PWR_UP_PWR_ON_DELAY_PWR_UP_PWR_ON_SF_MAX)
#define GFV_PWR_UP_PWR_ON_DELAY_PWR_UP_PWR_ON_SF_MAX(v) \
    (((v) & FM_PWR_UP_PWR_ON_DELAY_PWR_UP_PWR_ON_SF_MAX) >> 28U)

#define FM_PWR_UP_PWR_ON_DELAY_PWR_UP_PWR_ON_DELAY  ((uint32)0xffffffU << 0U)
#define FV_PWR_UP_PWR_ON_DELAY_PWR_UP_PWR_ON_DELAY(v) \
    ((((uint32)(v)) << 0U) & FM_PWR_UP_PWR_ON_DELAY_PWR_UP_PWR_ON_DELAY)
#define GFV_PWR_UP_PWR_ON_DELAY_PWR_UP_PWR_ON_DELAY(v) \
    (((v) & FM_PWR_UP_PWR_ON_DELAY_PWR_UP_PWR_ON_DELAY) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : RUN_PWR_ON_DELAY
// Register Offset : 0x44
// Description     : Delay setting of pwr_on0~3 in RUN state
//--------------------------------------------------------------------------
#define RUN_PWR_ON_DELAY    0x44U

#define FM_RUN_PWR_ON_DELAY_RUN_PWR_ON_AP_MAX   ((uint32)0x3U << 30U)
#define FV_RUN_PWR_ON_DELAY_RUN_PWR_ON_AP_MAX(v) \
    ((((uint32)(v)) << 30U) & FM_RUN_PWR_ON_DELAY_RUN_PWR_ON_AP_MAX)
#define GFV_RUN_PWR_ON_DELAY_RUN_PWR_ON_AP_MAX(v) \
    (((v) & FM_RUN_PWR_ON_DELAY_RUN_PWR_ON_AP_MAX) >> 30U)

#define FM_RUN_PWR_ON_DELAY_RUN_PWR_ON_SF_MAX   ((uint32)0x3U << 28U)
#define FV_RUN_PWR_ON_DELAY_RUN_PWR_ON_SF_MAX(v) \
    ((((uint32)(v)) << 28U) & FM_RUN_PWR_ON_DELAY_RUN_PWR_ON_SF_MAX)
#define GFV_RUN_PWR_ON_DELAY_RUN_PWR_ON_SF_MAX(v) \
    (((v) & FM_RUN_PWR_ON_DELAY_RUN_PWR_ON_SF_MAX) >> 28U)

#define FM_RUN_PWR_ON_DELAY_RUN_PWR_ON_DELAY    ((uint32)0xffffffU << 0U)
#define FV_RUN_PWR_ON_DELAY_RUN_PWR_ON_DELAY(v) \
    ((((uint32)(v)) << 0U) & FM_RUN_PWR_ON_DELAY_RUN_PWR_ON_DELAY)
#define GFV_RUN_PWR_ON_DELAY_RUN_PWR_ON_DELAY(v) \
    (((v) & FM_RUN_PWR_ON_DELAY_RUN_PWR_ON_DELAY) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : SLEEP_PWR_ON_DELAY
// Register Offset : 0x48
// Description     : Delay setting of pwr_on0~3 in SLEEP state
//--------------------------------------------------------------------------
#define SLEEP_PWR_ON_DELAY  0x48U

#define FM_SLEEP_PWR_ON_DELAY_SLEEP_PWR_ON_AP_MAX   ((uint32)0x3U << 30U)
#define FV_SLEEP_PWR_ON_DELAY_SLEEP_PWR_ON_AP_MAX(v) \
    ((((uint32)(v)) << 30U) & FM_SLEEP_PWR_ON_DELAY_SLEEP_PWR_ON_AP_MAX)
#define GFV_SLEEP_PWR_ON_DELAY_SLEEP_PWR_ON_AP_MAX(v) \
    (((v) & FM_SLEEP_PWR_ON_DELAY_SLEEP_PWR_ON_AP_MAX) >> 30U)

#define FM_SLEEP_PWR_ON_DELAY_SLEEP_PWR_ON_SF_MAX   ((uint32)0x3U << 28U)
#define FV_SLEEP_PWR_ON_DELAY_SLEEP_PWR_ON_SF_MAX(v) \
    ((((uint32)(v)) << 28U) & FM_SLEEP_PWR_ON_DELAY_SLEEP_PWR_ON_SF_MAX)
#define GFV_SLEEP_PWR_ON_DELAY_SLEEP_PWR_ON_SF_MAX(v) \
    (((v) & FM_SLEEP_PWR_ON_DELAY_SLEEP_PWR_ON_SF_MAX) >> 28U)

#define FM_SLEEP_PWR_ON_DELAY_SLEEP_PWR_ON_DELAY    ((uint32)0xffffffU << 0U)
#define FV_SLEEP_PWR_ON_DELAY_SLEEP_PWR_ON_DELAY(v) \
    ((((uint32)(v)) << 0U) & FM_SLEEP_PWR_ON_DELAY_SLEEP_PWR_ON_DELAY)
#define GFV_SLEEP_PWR_ON_DELAY_SLEEP_PWR_ON_DELAY(v) \
    (((v) & FM_SLEEP_PWR_ON_DELAY_SLEEP_PWR_ON_DELAY) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : RTC_PWR_ON_DELAY
// Register Offset : 0x50
// Description     : Delay setting of pwr_on0~3 in RTC state
//--------------------------------------------------------------------------
#define RTC_PWR_ON_DELAY    0x50U

#define FM_RTC_PWR_ON_DELAY_RTC_PWR_ON_AP_MAX   ((uint32)0x3U << 30U)
#define FV_RTC_PWR_ON_DELAY_RTC_PWR_ON_AP_MAX(v) \
    ((((uint32)(v)) << 30U) & FM_RTC_PWR_ON_DELAY_RTC_PWR_ON_AP_MAX)
#define GFV_RTC_PWR_ON_DELAY_RTC_PWR_ON_AP_MAX(v) \
    (((v) & FM_RTC_PWR_ON_DELAY_RTC_PWR_ON_AP_MAX) >> 30U)

#define FM_RTC_PWR_ON_DELAY_RTC_PWR_ON_SF_MAX   ((uint32)0x3U << 28U)
#define FV_RTC_PWR_ON_DELAY_RTC_PWR_ON_SF_MAX(v) \
    ((((uint32)(v)) << 28U) & FM_RTC_PWR_ON_DELAY_RTC_PWR_ON_SF_MAX)
#define GFV_RTC_PWR_ON_DELAY_RTC_PWR_ON_SF_MAX(v) \
    (((v) & FM_RTC_PWR_ON_DELAY_RTC_PWR_ON_SF_MAX) >> 28U)

#define FM_RTC_PWR_ON_DELAY_RTC_PWR_ON_DELAY    ((uint32)0xffffffU << 0U)
#define FV_RTC_PWR_ON_DELAY_RTC_PWR_ON_DELAY(v) \
    ((((uint32)(v)) << 0U) & FM_RTC_PWR_ON_DELAY_RTC_PWR_ON_DELAY)
#define GFV_RTC_PWR_ON_DELAY_RTC_PWR_ON_DELAY(v) \
    (((v) & FM_RTC_PWR_ON_DELAY_RTC_PWR_ON_DELAY) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : PG_LP_MODE_CTRL
// Register Offset : 0x58
// Description     : power good and lp_mode controls
//--------------------------------------------------------------------------
#define PG_LP_MODE_CTRL             0x58U

#define FM_PG_LP_MODE_CTRL_RUN_LP_MODE  ((uint32)0xfU << 28U)

#define FV_PG_LP_MODE_CTRL_RUN_LP_MODE(v) \
    ((((uint32)(v)) << 28U) & FM_PG_LP_MODE_CTRL_RUN_LP_MODE)

#define GFV_PG_LP_MODE_CTRL_RUN_LP_MODE(v) \
    (((v) & FM_PG_LP_MODE_CTRL_RUN_LP_MODE) >> 28U)

#define FM_PG_LP_MODE_CTRL_SLEEP_LP_MODE    ((uint32)0xfU << 24U)
#define FV_PG_LP_MODE_CTRL_SLEEP_LP_MODE(v) \
    ((((uint32)(v)) << 24U) & FM_PG_LP_MODE_CTRL_SLEEP_LP_MODE)
#define GFV_PG_LP_MODE_CTRL_SLEEP_LP_MODE(v) \
    (((v) & FM_PG_LP_MODE_CTRL_SLEEP_LP_MODE) >> 24U)

#define FM_PG_LP_MODE_CTRL_HIBERNATE_LP_MODE    ((uint32)0xfU << 20U)
#define FV_PG_LP_MODE_CTRL_HIBERNATE_LP_MODE(v) \
    ((((uint32)(v)) << 20U) & FM_PG_LP_MODE_CTRL_HIBERNATE_LP_MODE)
#define GFV_PG_LP_MODE_CTRL_HIBERNATE_LP_MODE(v) \
    (((v) & FM_PG_LP_MODE_CTRL_HIBERNATE_LP_MODE) >> 20U)

#define BM_PG_LP_MODE_CTRL_RTC_LV_MONITOR   ((uint32)0x01U << 17U)

#define BM_PG_LP_MODE_CTRL_RTC_HV_MONITOR   ((uint32)0x01U << 16U)

#define BM_PG_LP_MODE_CTRL_RTC_SF_HV_PG_DISABLE ((uint32)0x01U << 15U)

#define BM_PG_LP_MODE_CTRL_SF_HV_PG_DISABLE ((uint32)0x01U << 14U)

#define BM_PG_LP_MODE_CTRL_RTC_AP_HV_PG_DISABLE ((uint32)0x01U << 13U)

#define BM_PG_LP_MODE_CTRL_AP_HV_PG_DISABLE ((uint32)0x01U << 12U)

#define BM_PG_LP_MODE_CTRL_RTC_SF_LV_PG_DISABLE ((uint32)0x01U << 11U)

#define BM_PG_LP_MODE_CTRL_SF_LV_PG_DISABLE ((uint32)0x01U << 10U)

#define BM_PG_LP_MODE_CTRL_RTC_AP_LV_PG_DISABLE ((uint32)0x01U << 9U)

#define BM_PG_LP_MODE_CTRL_AP_LV_PG_DISABLE ((uint32)0x01U << 8U)

#define FM_PG_LP_MODE_CTRL_SW_LP_MODE_EN    ((uint32)0xfU << 4U)
#define FV_PG_LP_MODE_CTRL_SW_LP_MODE_EN(v) \
    ((((uint32)(v)) << 4U) & FM_PG_LP_MODE_CTRL_SW_LP_MODE_EN)
#define GFV_PG_LP_MODE_CTRL_SW_LP_MODE_EN(v) \
    (((v) & FM_PG_LP_MODE_CTRL_SW_LP_MODE_EN) >> 4U)

#define FM_PG_LP_MODE_CTRL_SW_LP_MODE   ((uint32)0xfU << 0U)
#define FV_PG_LP_MODE_CTRL_SW_LP_MODE(v) \
    ((((uint32)(v)) << 0U) & FM_PG_LP_MODE_CTRL_SW_LP_MODE)
#define GFV_PG_LP_MODE_CTRL_SW_LP_MODE(v) \
    (((v) & FM_PG_LP_MODE_CTRL_SW_LP_MODE) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : PMU_INT
// Register Offset : 0x68
// Description     : Interrupt of PMU
//--------------------------------------------------------------------------
#define PMU_INT 0x68U

#define FM_PMU_INT_PMU_INT_EN   ((uint32)0x1fffU << 16U)
#define FV_PMU_INT_PMU_INT_EN(v) \
    ((((uint32)(v)) << 16U) & FM_PMU_INT_PMU_INT_EN)
#define GFV_PMU_INT_PMU_INT_EN(v) \
    (((v) & FM_PMU_INT_PMU_INT_EN) >> 16U)

#define BM_PMU_INT_PWR_DOWN_REQ ((uint32)0x01U << 12U)

#define BM_PMU_INT_SWM_FATAL    ((uint32)0x01U << 11U)

#define BM_PMU_INT_SWM_WARN ((uint32)0x01U << 10U)

#define BM_PMU_INT_RSV1 ((uint32)0x01U << 9U)

#define BM_PMU_INT_RSV0 ((uint32)0x01U << 8U)

#define BM_PMU_INT_LOCKSTEP_ERR_REBOOTED    ((uint32)0x01U << 7U)

#define BM_PMU_INT_HIBERNATE_TO_RUN_REBOOTED    ((uint32)0x01U << 6U)

#define BM_PMU_INT_SLEEP_TO_RUN_REBOOTED    ((uint32)0x01U << 5U)

#define BM_PMU_INT_PWRUP_TO_RUN_REBOOTED    ((uint32)0x01U << 4U)

#define BM_PMU_INT_PWR_ON3_WDT_ERR  ((uint32)0x01U << 3U)

#define BM_PMU_INT_PWR_ON2_WDT_ERR  ((uint32)0x01U << 2U)

#define BM_PMU_INT_PWR_ON1_WDT_ERR  ((uint32)0x01U << 1U)

#define BM_PMU_INT_PWR_ON0_WDT_ERR  ((uint32)0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : SRCS_BITS
// Register Offset : 0x70
// Description     : 32bits state retention bits
//--------------------------------------------------------------------------
#define SRCS_BITS   0x70U

#define FM_SRCS_BITS_SRCS_BITS  ((uint32)0xffffffffU << 0U)
#define FV_SRCS_BITS_SRCS_BITS(v) \
    ((((uint32)(v)) << 0U) & FM_SRCS_BITS_SRCS_BITS)
#define GFV_SRCS_BITS_SRCS_BITS(v) \
    (((v) & FM_SRCS_BITS_SRCS_BITS) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : SRCS_BITS_SET
// Register Offset : 0x74
// Description     : 32bits state retention bits.
//--------------------------------------------------------------------------
#define SRCS_BITS_SET       0x74U

#define FM_SRCS_BITS_SET_SRCS_BITS  ((uint32)0xffffffffU << 0U)
#define FV_SRCS_BITS_SET_SRCS_BITS(v) \
    ((((uint32)(v)) << 0U) & FM_SRCS_BITS_SET_SRCS_BITS)
#define GFV_SRCS_BITS_SET_SRCS_BITS(v) \
    (((v) & FM_SRCS_BITS_SET_SRCS_BITS) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : SRCS_BITS_CLR
// Register Offset : 0x78
// Description     : 32bits state retention bits.
//--------------------------------------------------------------------------
#define SRCS_BITS_CLR   0x78U

#define FM_SRCS_BITS_CLR_SRCS_BITS  ((uint32)0xffffffffU << 0U)
#define FV_SRCS_BITS_CLR_SRCS_BITS(v) \
    ((((uint32)(v)) << 0U) & FM_SRCS_BITS_CLR_SRCS_BITS)
#define GFV_SRCS_BITS_CLR_SRCS_BITS(v) \
    (((v) & FM_SRCS_BITS_CLR_SRCS_BITS) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : SRCS_BITS_TOG
// Register Offset : 0x7c
// Description     : 32bits state retention bits.
//--------------------------------------------------------------------------
#define SRCS_BITS_TOG   0x7cU

#define FM_SRCS_BITS_TOG_SRCS_BITS  ((uint32)0xffffffffU << 0U)
#define FV_SRCS_BITS_TOG_SRCS_BITS(v) \
    ((((uint32)(v)) << 0U) & FM_SRCS_BITS_TOG_SRCS_BITS)
#define GFV_SRCS_BITS_TOG_SRCS_BITS(v) \
    (((v) & FM_SRCS_BITS_TOG_SRCS_BITS) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : PMU_DOWN_UP_STATUS
// Register Offset : 0x80
// Description     : PMU power down request and wake up event source status
//--------------------------------------------------------------------------
#define PMU_DOWN_UP_STATUS  0x80U

#define BM_PMU_DOWN_UP_STATUS_PWR_DWN_SOURCE11  ((uint32)0x01U << 15U)

#define BM_PMU_DOWN_UP_STATUS_PWR_DWN_SOURCE10  ((uint32)0x01U << 14U)

#define BM_PMU_DOWN_UP_STATUS_PWR_DWN_SOURCE9   ((uint32)0x01U << 13U)

#define BM_PMU_DOWN_UP_STATUS_PWR_DWN_SOURCE8   ((uint32)0x01U << 12U)

#define BM_PMU_DOWN_UP_STATUS_PWR_DWN_SOURCE7   ((uint32)0x01U << 11U)

#define BM_PMU_DOWN_UP_STATUS_PWR_DWN_SOURCE6   ((uint32)0x01U << 10U)

#define BM_PMU_DOWN_UP_STATUS_PWR_DWN_SOURCE5   ((uint32)0x01U << 9U)

#define BM_PMU_DOWN_UP_STATUS_PWR_DWN_SOURCE4   ((uint32)0x01U << 8U)

#define BM_PMU_DOWN_UP_STATUS_PWR_DWN_SOURCE3   ((uint32)0x01U << 7U)

#define BM_PMU_DOWN_UP_STATUS_PWR_DWN_SOURCE2   ((uint32)0x01U << 6U)

#define BM_PMU_DOWN_UP_STATUS_PWR_DWN_SOURCE1   ((uint32)0x01U << 5U)

#define BM_PMU_DOWN_UP_STATUS_PWR_DWN_SOURCE0   ((uint32)0x01U << 4U)

#define BM_PMU_DOWN_UP_STATUS_WAKEUP_SOURCE3    ((uint32)0x01U << 3U)

#define BM_PMU_DOWN_UP_STATUS_WAKEUP_SOURCE2    ((uint32)0x01U << 2U)

#define BM_PMU_DOWN_UP_STATUS_WAKEUP_SOURCE1    ((uint32)0x01U << 1U)

#define BM_PMU_DOWN_UP_STATUS_WAKEUP_SOURCE0    ((uint32)0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : PMU_STATE
// Register Offset : 0x84
// Description     : PMU internal state machine
//--------------------------------------------------------------------------
#define PMU_STATE   0x84U

#define BM_PMU_STATE_RTC_AP_HV_PG   ((uint32)0x01U << 15U)

#define BM_PMU_STATE_RTC_AP_LV_PG   ((uint32)0x01U << 14U)

#define BM_PMU_STATE_RTC_SF_HV_PG   ((uint32)0x01U << 13U)

#define BM_PMU_STATE_RTC_SF_LV_PG   ((uint32)0x01U << 12U)

#define BM_PMU_STATE_AP_HV_PG   ((uint32)0x01U << 11U)

#define BM_PMU_STATE_AP_LV_PG   ((uint32)0x01U << 10U)

#define BM_PMU_STATE_SF_HV_PG   ((uint32)0x01U << 9U)

#define BM_PMU_STATE_SF_LV_PG   ((uint32)0x01U << 8U)

#define FM_PMU_STATE_PWR_RDY    ((uint32)0xfU << 4U)
#define FV_PMU_STATE_PWR_RDY(v) \
    ((((uint32)(v)) << 4U) & FM_PMU_STATE_PWR_RDY)
#define GFV_PMU_STATE_PWR_RDY(v) \
    (((v) & FM_PMU_STATE_PWR_RDY) >> 4U)

#define FM_PMU_STATE_PMU_STATE  ((uint32)0x7U << 0U)
#define FV_PMU_STATE_PMU_STATE(v) \
    ((((uint32)(v)) << 0U) & FM_PMU_STATE_PMU_STATE)
#define GFV_PMU_STATE_PMU_STATE(v) \
    (((v) & FM_PMU_STATE_PMU_STATE) >> 0U)

#ifdef __cplusplus
}
#endif

#endif /* PMU_REG_H */
/* End of file */
