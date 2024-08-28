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
 * \file     Rtc_Reg.h                                                                                  *
 * \brief    AUTOSAR 4.3.1 MCAL Mcu Driver                                                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/03     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef RTC_REG_H
#define RTC_REG_H


#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/

//--------------------------------------------------------------------------
// Register Name   : SEC_RTC_CTRL
// Register Offset : 0x0
// Description     : Secure RTC controller.
//                   Write and read perimission be controlled by APB pprot.
//--------------------------------------------------------------------------
#define SEC_RTC_CTRL    0x0U

#define BM_SEC_RTC_CTRL_LOCK    (0x01UL << 31U)

#define BM_SEC_RTC_CTRL_PRIVILEGE_ENABLE    (0x01U << 2U)

#define BM_SEC_RTC_CTRL_SECURE_ENABLE   (0x01U << 1U)

#define BM_SEC_RTC_CTRL_RTC_ENABLE  (0x01UL << 0U)

//--------------------------------------------------------------------------
// Register Name   : RTC_H
// Register Offset : 0x4
// Description     : 48bit- RTC high register.
//                   Write and read perimission be controlled by APB pprot.
//--------------------------------------------------------------------------
#define RTC_H   0x4U

#define FM_RTC_H_RTC_H  (0xffffU << 0U)
#define FV_RTC_H_RTC_H(v) \
    (((v) << 0U) & FM_RTC_H_RTC_H)
#define GFV_RTC_H_RTC_H(v) \
    (((v) & FM_RTC_H_RTC_H) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : RTC_L
// Register Offset : 0x8
// Description     : 48bit- RTC low register.
//                   Write perimission be controlled by APB pprot.
//--------------------------------------------------------------------------
#define RTC_L   0x8U

#define FM_RTC_L_RTC_L  (0xffffffffU << 0U)
#define FV_RTC_L_RTC_L(v) \
    (((v) << 0U) & FM_RTC_L_RTC_L)
#define GFV_RTC_L_RTC_L(v) \
    (((v) & FM_RTC_L_RTC_L) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : AUTO_ADJUST
// Register Offset : 0xc
// Description     : RTC auto adjust function controller.
//                   Write  perimission be controlled by APB pprot.
//--------------------------------------------------------------------------
#define AUTO_ADJUST 0xcU

#define FM_AUTO_ADJUST_PERIOD   (0xffUL << 16U)
#define FV_AUTO_ADJUST_PERIOD(v) \
    (((uint32)(v) << 16U) & FM_AUTO_ADJUST_PERIOD)
#define GFV_AUTO_ADJUST_PERIOD(v) \
    (((uint32)(v) & FM_AUTO_ADJUST_PERIOD) >> 16U)

#define FM_AUTO_ADJUST_CYCLE    (0xffUL << 8U)
#define FV_AUTO_ADJUST_CYCLE(v) \
    (((uint32)(v) << 8U) & FM_AUTO_ADJUST_CYCLE)
#define GFV_AUTO_ADJUST_CYCLE(v) \
    (((uint32)(v) & FM_AUTO_ADJUST_CYCLE) >> 8U)

#define BM_AUTO_ADJUST_ADJUST_DIRECTION (0x01U << 1U)

#define BM_AUTO_ADJUST_ENABLE   (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : TIMER_H
// Register Offset : 0x10
// Description     : Compare timer value 48bit high bit.
//                   Write and read perimission be controlled by APB pprot.
//--------------------------------------------------------------------------
#define TIMER_H 0x10U

#define FM_TIMER_H_TIMER_H  (0xffffU << 0U)
#define FV_TIMER_H_TIMER_H(v) \
    (((uint32)(v) << 0U) & FM_TIMER_H_TIMER_H)
#define GFV_TIMER_H_TIMER_H(v) \
    (((uint32)(v) & FM_TIMER_H_TIMER_H) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : TIMER_L
// Register Offset : 0x14
// Description     : Compare timer value 48bit low bit.
//                   Write and read perimission be controlled by APB pprot.
//                   high bit
//--------------------------------------------------------------------------
#define TIMER_L 0x14U

#define FM_TIMER_L_TIMER_L  (0xffffffffU << 0U)
#define FV_TIMER_L_TIMER_L(v) \
    (((uint32)(v) << 0U) & FM_TIMER_L_TIMER_L)
#define GFV_TIMER_L_TIMER_L(v) \
    (((uint32)(v) & FM_TIMER_L_TIMER_L) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : WAKEUP_CTRL
// Register Offset : 0x18
// Description     : Wake-up control.
//                   Write and read perimission be controlled by APB pprot.
//                   high bit
//--------------------------------------------------------------------------
#define RTC_WAKEUP_CTRL 0x18U

#define BM_WAKEUP_CTRL_DISABLE_CLEAR    (0x01U << 6U)

#define BM_WAKEUP_CTRL_OVERFLOW_CLEAR   (0x01U << 5U)

#define BM_WAKEUP_CTRL_CLEAR    (0x01U << 4U)

#define BM_WAKEUP_CTRL_STATUS   (0x01U << 3U)

#define BM_WAKEUP_CTRL_ENABLE   (0x01U << 0U)

#define BM_WAKEUP_CTRL_IRQ_ENABLE   (0x01U << 1U)

#define BM_WAKEUP_CTRL_REQ_ENABLE   (0x01U << 2U)

//--------------------------------------------------------------------------
// Register Name   : PERIODICAL_CRTL
// Register Offset : 0x1c
// Description     : Periodical irq control.
//                   Write and read perimission be controlled by APB pprot.
//--------------------------------------------------------------------------
#define PERIODICAL_CRTL 0x1cU

#define FM_PERIODICAL_CRTL_FREQ (0xfU << 3U)
#define FV_PERIODICAL_CRTL_FREQ(v) \
    (((v) << 3U) & FM_PERIODICAL_CRTL_FREQ)
#define GFV_PERIODICAL_CRTL_FREQ(v) \
    (((v) & FM_PERIODICAL_CRTL_FREQ) >> 3U)

#define BM_PERIODICAL_CRTL_IRQ_ENABLE   (0x01U << 0U)

//--------------------------------------------------------------------------
// Register Name   : VIOLATION_INT
// Register Offset : 0x20
// Description     : Violation interrupt.
//                   Write and read perimission be controlled by APB pprot.
//--------------------------------------------------------------------------
#define VIOLATION_INT   0x20U

#define BM_VIOLATION_INT_DISABLE_STATUS (0x01U << 3U)

#define BM_VIOLATION_INT_OVERFLOW_STATS (0x01U << 2U)

#define FM_VIOLATION_INT_MASK   (0x3U << 0U)
#define FV_VIOLATION_INT_MASK(v) \
    (((v) << 0U) & FM_VIOLATION_INT_MASK)
#define GFV_VIOLATION_INT_MASK(v) \
    (((v) & FM_VIOLATION_INT_MASK) >> 0U)

//--------------------------------------------------------------------------
// Register Name   : RTC_REGISTER_CROSS_CLOCK
// Register Offset : 0x60
// Description     : RTC register cross clock enable.
//--------------------------------------------------------------------------
#define RTC_REGISTER_CROSS_CLOCK    0x60U

#define BM_REGISTERR_CROSS_CLOCK_EN    (0x01UL << 0U)

//--------------------------------------------------------------------------
// Register Name   : RTC_REG_PARITY_ERR_INT_STAT_EN
// Register Offset : 0x68
// Description     : RTC register parity error interrupt status enable.
//--------------------------------------------------------------------------
#define RTC_REG_PARITY_ERR_INT_STAT_EN  0x68U

#define BM_REG_PARITY_ERR_INT_STAT_REG_PARITY_ERR   (0x1UL << 0U)

//--------------------------------------------------------------------------
// Register Name   : RTC_H_HOLD_SHADOW
// Register Offset : 0x54
// Description     : RTC timer shadow register
//--------------------------------------------------------------------------
#define RTC_REG_H_HOLD_SHADOW   0x54U
#define RTC_REG_L_HOLD_SHADOW   0x58U

#ifdef __cplusplus
}
#endif

#endif /* RTC_REG_H */
/* End of file */
