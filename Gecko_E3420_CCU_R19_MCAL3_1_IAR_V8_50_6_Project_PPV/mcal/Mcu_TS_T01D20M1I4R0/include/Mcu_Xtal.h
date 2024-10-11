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
 *  \file     Mcu_Xtal.h                                                                                *
 *  \brief    This file contains interface header for MCU MCAL driver, ...                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/03     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef MCU_XTAL_H
#define MCU_XTAL_H

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

#define XTAL_CTRL_STATE 0x01U
#define LPVD_POWER_STATE 0x01U
/*fuse map macro*/
#define MCU_FUSEMAP_RC32K                                 (0x1048U)
#define MCU_FUSEMAP_RC24M_FREQ_TUNE                       (0x1050U)
#define MCU_FUSEMAP_RC24M_FREQ_TUNE_OFFSET                (0x0U)
#define MCU_FUSEMAP_RC24M_FREQ_TUNE_MASK                  (0xFFU)
/********************************************************************************************************
 *                                  Global Types definition                                             *
 *******************************************************************************************************/
typedef enum
{
    XTAL_DISABLE = 0U,
    XTAL_ENABLE,
/*PRQA S 1535 1*/
} Mcu_XtalCtrlType;

typedef enum
{
    LPVD_POWER_ON = 0U,
    LPVD_POWER_DOWN,
} Mcu_LpvdCtrlType;

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/

/**
 * \brief   To switch lpvd power.
 * \details This function switch lpvd power.
 * \param[in] pd  power on/down
 */
void Mcu_Ip_XtalLpvdPowerSwitch(Mcu_LpvdCtrlType pd);

/**
 * \brief   To switch Rtc source clock from internal RC to external XTAL.
 * \details This function enable external XTAL if it not enabled yet. And switch Rtc
 *          source clock from internal RC to external XTAL if XTAL locked. If not
 *          locked, this function returns FALSE. For the first RTC power-up cycle,
 *          XTAL need ~1s to be locked.
 * \param[in] base  The base address of RTC to be set
 */
Std_ReturnType Mcu_Ip_Fs32KTrySwitchToXtal(uint32 base);

Std_ReturnType Mcu_Ip_FS_TrySwitchToRC(uint32 base);

void Mcu_Ip_Rc24m_Trim(void);

#endif /* MCU_XTAL_H */
/* End of file */
