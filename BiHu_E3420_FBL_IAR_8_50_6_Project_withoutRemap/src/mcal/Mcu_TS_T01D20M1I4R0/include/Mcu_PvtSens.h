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

#ifndef MCU_PVTSENS_H
#define MCU_PVTSENS_H

#ifdef __cplusplus
extern "C" {
#endif


/* Temperature threshold range */
#define PVT_TEMPERATURE_MIN (-75.9f) /* dout_to_celsius(0x0) */
#define PVT_TEMPERATURE_MAX (230.7f) /* dout_to_celsius(0xfff) */

/**
 * @brief PVT core logics.
 *
 * The sensor has 2 cores, both of which have identical logics, but
 * different interrupt numbers.
 */
typedef enum sdrv_pvt_core_id {
    PVT_CORE0 = 0u,
    PVT_CORE1 = 1u,
    PVT_CORE_NR,
} sdrv_pvt_core_id_e;

/**
 * @brief Temperature sensor alarm modes.
 *
 * @note Do not change the order of this structure.
 */
typedef enum sdrv_pvt_alarm {
    /**< Alarm asserted when DOUT is above HYST_H thresholds. */
    PVT_HIGH_LEVEL_ALARM = 0,
    /**< Alarm asserted when DOUT is below HYST_L thresholds. */
    PVT_LOW_LEVEL_ALARM,
    /**< Alarm asserted when sensored value is rising above HYST_R. */
    PVT_RISING_EDGE_ALARM,
    /**< Alarm asserted when sensored value is falling below HYST_L. */
    PVT_FALLING_EDGE_ALARM,

    PVT_ALARM_NR,
} sdrv_pvt_alarm_e;

/**
 * @brief Level alarm configuration.
 *
 * Temperature alarm thresholds, between PVT_TEMPERATURE_MIN and
 * PVT_TEMPERATURE_MAX.
 */
typedef struct sdrv_pvt_level_alarm_config {
    /**< Low threashold temperature. */
    float thresh_low;
    /**< High threashold temperature. */
    float thresh_high;
} sdrv_pvt_level_alarm_config_t;

/**
 * @brief Edge alarm configuration.
 *
 * Temperature alarm thresholds, between PVT_TEMPERATURE_MIN and
 * PVT_TEMPERATURE_MAX.
 */
typedef struct sdrv_pvt_edge_alarm_config {
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
} sdrv_pvt_edge_alarm_config_t;

/**
 * @brief Hysterisis alarm configuration.
 */
typedef union sdrv_pvt_alarm_config {
    sdrv_pvt_level_alarm_config_t level_alarm;
    sdrv_pvt_edge_alarm_config_t edge_alarm;
} sdrv_pvt_alarm_config_t;

struct sdrv_pvt;

/**
 * @brief Temperature alarm callback.
 */
typedef void (*sdrv_pvt_alarm_cb_t)(struct sdrv_pvt *dev);

/**
 * @brief PVT core logic structure.
 *
 * The controller has 2 cores, which have unique interrupt number
 * and configuration registers.
 */
typedef struct sdrv_pvt_core {
    /**< Interrupt number of the core. */
    uint32 irq;
    /**< Interrupt callback. */
    sdrv_pvt_alarm_cb_t alarm_cb;
    /**< Interrupt callback arg. */
    void *cb_arg;
    /**< Bit mask of enabled alarms of this core, using sdrv_pvt_alarm_e
     * as bit shift. */
    uint32 alarm_enable_mask;
} sdrv_pvt_core_t;

/**
 * @brief Process and temperature sensor structure.
 */
typedef struct sdrv_pvt {
    /**< PVT controller base address. */
    paddr_t base;
    /**< Core logics. */
    sdrv_pvt_core_t core[PVT_CORE_NR];
} sdrv_pvt_t;

typedef struct sdrv_pvt_config {
    sdrv_pvt_alarm_e type;
    float highest;
    float T1;
    float T2;
    const sdrv_pvt_alarm_cb_t  pPvtNotification;
} sdrv_pvt_config_t;

/**
 * @brief alarm callback.
 *
 * @param [in] dev PVT sensor device.
 */
void pvt_alarm_cb(struct sdrv_pvt *dev);

/**
 * @brief Initialize the PVT device.
 *
 * @param [in] dev PVT sensor device.
 */
int sdrv_pvt_init(sdrv_pvt_t *dev);

/**
 * @brief De-initialize the PVT device.
 *
 * @param [in] dev PVT sensor device.
 */
int sdrv_pvt_deinit(sdrv_pvt_t *dev);

/**
 * @brief Start temperature sensor.
 *
 * After this function is called, the sensor automatically update temperature
 * value every 280ms.
 *
 * @param [in] dev PVT sensor device.
 */
int sdrv_pvt_start(sdrv_pvt_t *dev);

/**
 * @brief Stop temperature sensor.
 *
 * @param [in] dev PVT sensor device.
 */
int sdrv_pvt_stop(sdrv_pvt_t *dev);

/**
 * @brief Read temperature sensor value.
 *
 * @note Temperature value is not ready until 280ms after sdrv_pvt_start()
 *  is called.
 *
 * @param [in] dev PVT sensor device.
 * @param [out] temperature Junction temperature value.
 */
int sdrv_pvt_get(sdrv_pvt_t *dev, float *temperature);

/**
 * @brief Register temperature alarm callback.
 *
 * @param [in] dev Sensor device.
 * @param [in] core Sensor core.
 * @param [in] alarm_cb Temperature alarm callback function.
 */
int sdrv_pvt_register_alarm_cb(sdrv_pvt_t *dev, sdrv_pvt_core_id_e core,
                               sdrv_pvt_alarm_cb_t alarm_cb, void *arg);

/**
 * @brief Enable Temperature sensor alarm.
 *
 * @param [in] dev Temperature sensor device.
 * @param [in] core Temperature sensor core.
 * @param [in] alarm The alarm to enable.
 * @param [in] config Alarm configurations.
 */
int sdrv_pvt_enable_alarm(sdrv_pvt_t *dev, sdrv_pvt_core_id_e core,
                          sdrv_pvt_alarm_e alarm,
                          const sdrv_pvt_alarm_config_t *config);

/**
 * @brief Disable Temperature sensor alarm.
 *
 * @param [in] dev Temperature sensor device.
 * @param [in] core Temperature sensor core.
 * @param [in] alarm The alarm to disable.
 */
int sdrv_pvt_disable_alarm(sdrv_pvt_t *dev, sdrv_pvt_core_id_e core,
                           sdrv_pvt_alarm_e alarm);

FUNC(void, MCU_CODE) Mcu_PVTInit(void);


#ifdef __cplusplus
}
#endif

#endif  /* ifndef MCU_PMU_H */