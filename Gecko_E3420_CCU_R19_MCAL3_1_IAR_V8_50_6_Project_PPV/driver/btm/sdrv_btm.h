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

/**
 * @file  sdrv_btm.h
 * @brief Semidrive. Btm
 */

#ifndef INCLUDE_DRV_XLI_BTM_H
#define INCLUDE_DRV_XLI_BTM_H

#include <types.h>
#include <__compiler.h>
#include "sdrv_btm_hw.h"
#include "sdrv_btm_common.h"

#ifndef ASSEMBLY

__BEGIN_CDECLS


/* btm status */
typedef enum btm_status {
    BTM_STATUS_NULL = 0,
    BTM_STATUS_IDLE,
    BTM_STATUS_BUSY,
    BTM_STATUS_ERR
} btm_status_t;

/* btm type*/
typedef enum btm_type {
    BTM_TYPE_ONESHOT = 0,
    BTM_TYPE_PERIOD = 1,
    BTM_TYPE_ERR
} btm_type_t;

/* time type*/
typedef enum btm_time_type {
    BTM_TIME_MS = 0,
    BTM_TIME_US = 1,
    BTM_TIME_NS = 2
} btm_time_type_t;


/* btm callback */
typedef void (*btm_callback)(void *arg);


/* sdrv btm config */
typedef struct sdrv_btm_cfg {
    uint32 base;
    int irq;
    sdrv_btm_cnt_id_e tmr_id;
    sdrv_btm_hw_cnt_cfg_t tmr_cfg;
} sdrv_btm_cfg_t;


/* sdrv btm ctrl */
typedef struct sdrv_btm {
    sdrv_btm_cfg_t  *config;
    btm_status_t     status;
    btm_type_t       type;
    btm_time_type_t  time_type;
    uint32         time_out;
    btm_callback     callback;
    void             *arg;
    float         cnt_per_us;
    float         ns_per_tick;
} sdrv_btm_t;


/* sdrv btm controller module */
typedef struct sdrv_btm_controller_module {
    sdrv_btm_t *btm_bank[SDRV_BTM_NUM];
} sdrv_btm_controller_module_t;


/**
 * @brief btm init
 *
 * Initial btm module instance.
 *
 * @param[in] ctrl: btm ctrl instance
 * @param[in] cfg:  btm config
 * @return succeed:0 fail:other
 */
status_t sdrv_btm_init(sdrv_btm_t *ctrl, sdrv_btm_cfg_t *cfg);

/**
 * @brief btm deinit
 *
 * Deinitial btm module instance.
 *
 * @param[in] ctrl: btm ctrl instance
 * @return succeed:0  fail:other
 */
status_t sdrv_btm_deinit(sdrv_btm_t *ctrl);

/**
 * @brief btm start
 *
 * In one-short mode, btm will auto stop while reaches overflow value.
 * In continuous mode, btm will reset to 0 and restart once reaches overflow value.
 *
 * @param[in] ctrl: btm ctrl instance
 * @param[in] btm_type:  timer type
 * @param[in] time_type:  timeout time unit
 * @param[in] time_out:  timeout
 * @return succeed:0  fail:other
 */
status_t sdrv_btm_start(sdrv_btm_t *ctrl, btm_type_t btm_type, btm_time_type_t time_type,
                        uint32 time_out);

/**
 * @brief btm stop
 *
 * BTM stop to count.
 *
 * @param[in] ctrl: btm ctrl instance
 * @return succeed:0  fail:other
 */
status_t sdrv_btm_stop(sdrv_btm_t *ctrl);

/**
 * @brief btm setup callback funciton
 *
 * @param[in] ctrl: btm ctrl instance
 * @param[in] callback: user callback function
 * @return succeed:0  fail:other
 */
status_t sdrv_btm_set_callback(sdrv_btm_t *ctrl, btm_callback callback, void *arg);

/**
 * @brief get btm Elapsed time (us)
 *
 * @param[in] ctrl: btm ctrl instance
 * @return btm Elapsed time (us)
 */
uint32 sdrv_btm_get_current_time(sdrv_btm_t *ctrl);


/**
 * @brief get btm Elapsed time (extend)
 *
 * @param[in] ctrl: btm ctrl instance
 * @param[in] time_type: time type
 * @return btm Elapsed time (us)
 */
uint32 sdrv_btm_get_current_time_ex(sdrv_btm_t *ctrl, btm_time_type_t time_type);


/**
 * @brief btm pause
 *
 * @param[in] ctrl: btm ctrl instance
 * @return succeed:0  fail:other
 */
status_t sdrv_btm_pause(sdrv_btm_t *ctrl);

/**
 * @brief btm continue
 *
 * @param[in] ctrl: btm ctrl instance
 * @return succeed:0  fail:other
 */
status_t sdrv_btm_continue(sdrv_btm_t *ctrl);

/**
 * @brief get btm counter value
 *
 * @param[in] ctrl: btm ctrl instance
 * @return btm counter value
 */
uint32 sdrv_btm_get_counter(sdrv_btm_t *ctrl);


/**
 * @brief btm convert count to time in us
 *
 * @param[in] ctrl: btm ctrl instance
 * @param[in] cnt: btm count value
 * @return time in microseconds.
 */
uint32 sdrv_btm_count_to_us(sdrv_btm_t *ctrl, uint32 cnt);

__END_CDECLS

#endif

#endif
