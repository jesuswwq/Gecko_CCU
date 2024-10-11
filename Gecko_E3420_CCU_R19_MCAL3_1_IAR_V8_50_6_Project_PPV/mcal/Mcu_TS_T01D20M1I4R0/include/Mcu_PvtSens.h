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
 *  \file     Mcu_PvtSens.h                                                                             *
 *  \brief    This file contains interface header for MCU MCAL driver, ...                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/02     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef MCU_PVTSENS_H
#define MCU_PVTSENS_H


#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_GeneralTypes.h"
#include "Mcal.h"

/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
/* Temperature threshold range */
#define PVT_TEMPERATURE_MIN (-75.9f) /* Mcu_Ip_PvtDoutToCelsius(0x0) */
#define PVT_TEMPERATURE_MAX (230.7f) /* Mcu_Ip_PvtDoutToCelsius(0xfff) */

/********************************************************************************************************
 *                                  Global Types definition                                             *
 *******************************************************************************************************/
/**
 * \brief Level alarm configuration.
 *
 * Temperature alarm thresholds, between PVT_TEMPERATURE_MIN and
 * PVT_TEMPERATURE_MAX.
 */
typedef struct
{
    /**< Low threashold temperature. */
    float threshLow;
    /**< High threashold temperature. */
    float threshHigh;
} Mcu_PvtLevelAlarmConfigType;

/**
 * \brief Edge alarm configuration.
 *
 * Temperature alarm thresholds, between PVT_TEMPERATURE_MIN and
 * PVT_TEMPERATURE_MAX.
 */
typedef struct
{
    /**< Hysterisis temperature. In HYST_R rising edge detection mode,
     * the sensor start monitoring edge alarm status when DOUT[11:0]
     * is above hyst. In HYST_L falling edge detection mode, the
     * sensor start monitoring edge alarm status when DOUT[11:0]
     * is below hyst.
     */
    float hyst;

    /**< Alarm temperature. Level alarm status is asserted when
     * DOUT[11:0] is above or below alarm, depending on rising
     * or falling alarm mode.
     */
    float alarm;
} Mcu_PvtEdgeAlarmConfigType;

/**
 * \brief Hysterisis alarm configuration.
 */
typedef struct
{
    Mcu_PvtLevelAlarmConfigType levelAlarm;
    Mcu_PvtEdgeAlarmConfigType edgeAlarm;
} Mcu_PvtAlarmConfigType;




typedef struct
{
    const Mcu_PvtAlarmConfigType levelCfgHigh;
    const Mcu_PvtAlarmConfigType levelCfgLow;
    const Mcu_PvtAlarmCbType  pvtNotificationPtr;
    void  *arg;
} Mcu_PvtForVdType;

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
/**
 * \brief SF PVT CORE0 interrupt service routine.
 */
ISR(PVT_Controller0IrqHandler);

/**
 * \brief SF PVT CORE1 interrupt service routine.
 */
ISR(PVT_Controller1IrqHandler);

/**
 * \brief AP PVT CORE0 interrupt service routine.
 */
ISR(PVT_Controller2IrqHandler);

/**
 * \brief AP PVT CORE1 interrupt service routine.
 */
ISR(PVT_Controller3IrqHandler);

Std_ReturnType Mcu_Ip_PvtEnableAlarm(Mcu_PvtType *devPtr, Mcu_PvtCoreIdType core,
                                     Mcu_PvtAlarmType alarm, const Mcu_PvtAlarmConfigType *configPtr);

Std_ReturnType Mcu_Ip_PvtDisableAlarm(Mcu_PvtType *devPtr, Mcu_PvtCoreIdType core,
                                      Mcu_PvtAlarmType alarm);
/**
 * \brief De-initialize the PVT device.
 *
 * \param [in] dev PVT sensor device.
 */
Std_ReturnType Mcu_Ip_PvtDeinit(Mcu_PvtType *devPtr);

/**
 * \brief Stop temperature sensor.
 *
 * \param [in] dev PVT sensor device.
 */
Std_ReturnType Mcu_Ip_PvtStop(Mcu_PvtType *devPtr);

/**
 * \brief Read temperature sensor value.
 *
 * \note Temperature value is not ready until 280ms after Mcu_Ip_PvtStart()
 *  is called.
 *
 * \param [in] dev PVT sensor device.
 * \param [out] temperature Junction temperature value.
 */
Std_ReturnType Mcu_Ip_PvtGet(Mcu_PvtType *devPtr, float *temperaturePtr);

Mcu_PvtType *Mcu_Ip_PvtGetSfDevice(void);

#ifndef SEMIDRIVE_E3_LITE_SERIES
Mcu_PvtType *Mcu_Ip_PvtGetApDevice(void);
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/

Std_ReturnType Mcu_Ip_PvtClearStatus(Mcu_PvtType *devPtr, Mcu_PvtCoreIdType core,
                                     Mcu_PvtAlarmType alarm);

Std_ReturnType Mcu_Ip_PvtPrepare(void);

#ifndef SEMIDRIVE_E3_LITE_SERIES
Std_ReturnType Mcu_Ip_PvtForVdInit(const Mcu_PvtForVdType *vDconfigPtr);
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/


#ifdef __cplusplus
}
#endif

#endif /* MCU_PVTSENS_H */
/* End of file */
