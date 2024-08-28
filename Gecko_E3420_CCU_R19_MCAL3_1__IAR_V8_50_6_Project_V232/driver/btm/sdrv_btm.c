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
 * @file  sdrv_btm.c
 * @brief Semidrive. Btm
 */

#include <types.h>

#include "bits.h"
#include "_assert.h"
#include "irq.h"
#include "sdrv_btm.h"
#include "__regs_base.h"

#ifndef SEMIDRIVE_E3_LITE_SERIES
#define SDRV_BTM_MODULE_NUM 6
static uint32 btm_list[SDRV_BTM_MODULE_NUM] = {APB_BTM1_BASE, APB_BTM2_BASE, APB_BTM3_BASE, APB_BTM4_BASE, APB_BTM5_BASE, APB_BTM6_BASE};
#else
#define SDRV_BTM_MODULE_NUM 4
static uint32 btm_list[SDRV_BTM_MODULE_NUM] = {APB_BTM1_BASE, APB_BTM2_BASE, APB_BTM3_BASE, APB_BTM4_BASE};
#endif
sdrv_btm_controller_module_t btm_controller[SDRV_BTM_MODULE_NUM] = {0};

#define EXTRA_FMT "sdrv_btm:"
#define SDRV_BTM_ERR(format, ...) \
    ssdk_printf(SSDK_ERR, EXTRA_FMT format, ##__VA_ARGS__)
#define SDRV_BTM_WARN(format, ...) \
    ssdk_printf(SSDK_WARNING, EXTRA_FMT format, ##__VA_ARGS__)
#define SDRV_BTM_INFO(format, ...) \
    ssdk_printf(SSDK_INFO, EXTRA_FMT format, ##__VA_ARGS__)


/**
 * @brief sdrv btm irq handle function
 *
 * @param[in] irq :irq id
 * @param[in] arg :irq arg
 */
static int sdrv_btm_irq_handle(uint32 irq, void *arg)
{
    sdrv_btm_controller_module_t *pstbtm_controller = arg;
    sdrv_btm_t *sdrv_btm_g0 = pstbtm_controller->btm_bank[SDRV_BTM_G0];
    sdrv_btm_t *sdrv_btm_g1 = pstbtm_controller->btm_bank[SDRV_BTM_G1];
    volatile uint32 int_sta = 0;

    if (sdrv_btm_g0 != NULL) {
        int_sta = sdrv_btm_hw_get_int_sta(sdrv_btm_g0->config->base);
    }
    else {
        int_sta = sdrv_btm_hw_get_int_sta(sdrv_btm_g1->config->base);
    }

    uint32 clr_int_sta;

    if (int_sta & BTM_BM_INT_STAT_OE_G0) {
        clr_int_sta = int_sta & BTM_BM_INT_STAT_OE_G0;
        sdrv_btm_hw_set_int_sta(sdrv_btm_g0->config->base, clr_int_sta);

        if (sdrv_btm_g0 != NULL) {
            if (sdrv_btm_g0->callback) {
                sdrv_btm_g0->callback(sdrv_btm_g0->arg);
            }

            /*update timer status*/
            if (sdrv_btm_g0->type == BTM_TYPE_ONESHOT) {
                sdrv_btm_g0->status = BTM_STATUS_IDLE;
            }
        }
    }

    if (int_sta & BTM_BM_INT_STAT_OE_G1) {
        clr_int_sta = int_sta & BTM_BM_INT_STAT_OE_G1;
        sdrv_btm_hw_set_int_sta(sdrv_btm_g1->config->base, clr_int_sta);

        if (sdrv_btm_g1 != NULL) {
            if (sdrv_btm_g1->callback) {
                sdrv_btm_g1->callback(sdrv_btm_g1->arg);
            }

            /*update timer status*/
            if (sdrv_btm_g1->type == BTM_TYPE_ONESHOT) {
                sdrv_btm_g1->status = BTM_STATUS_IDLE;
            }
        }
    }

    return 0;
}

#if !defined(NON_AUTOSAR_STANDARD_IRQ_HANDLER)
#define BTM_ISR(id) \
    void sdrv_btm##id##_irq_handle(void)\
{\
        sdrv_btm_irq_handle(0, &btm_controller[id]);\
}

BTM_ISR(0)
BTM_ISR(1)
BTM_ISR(2)
BTM_ISR(3)
#ifdef SEMIDRIVE_E3_SERIES
BTM_ISR(4)
BTM_ISR(5)
#endif
#endif

/**
 * @brief get btm module id
 *
 * @param[in] base: module address
 * @param[out] id : module id
 */
status_t sdrv_btm_get_module_id(uint32 base, uint8 *id)
{
    uint8 i = 0u;
    uint32 temp = 0u;

    for (i = 0u; i < SDRV_BTM_MODULE_NUM; i++) {
        temp = btm_list[i];

        if (base == temp) {
            *id = i;
            break;
        }
    }

    if (i >= SDRV_BTM_MODULE_NUM)
        return SDRV_STATUS_FAIL;
    else
        return SDRV_STATUS_OK;
}




/**
 * @brief btm init
 *
 * Initial btm module instance.
 *
 * @param[in] ctrl: btm ctrl instance
 * @param[in] cfg:  btm config
 * @return succeed:0 fail:other
 */
status_t sdrv_btm_init(sdrv_btm_t *ctrl, sdrv_btm_cfg_t *cfg)
{
    uint8 btm_max_count = 0u;
    uint8 btm_id = 0u;
    uint32 apb_clock = 0u;
    status_t status = 0;
    ASSERT(ctrl != NULL);
    ASSERT(cfg != NULL);

    ctrl->config = cfg;

    if (cfg->tmr_id == SDRV_BTM_G0) {
        apb_clock = 150000000 / 1000000;
        ctrl->cnt_per_us = (float)(apb_clock * (cfg->tmr_cfg.inc_val)) / ((cfg->tmr_cfg.si_val) + 1);

        if (cfg->tmr_cfg.inc_val != 0) {
            ctrl->ns_per_tick = (float) ((1000) / ((apb_clock * (cfg->tmr_cfg.inc_val)) / ((
                    cfg->tmr_cfg.si_val) + 1)));
        }
    }
    else if (cfg->tmr_id == SDRV_BTM_G1) {
        /* btm_g1 fre: 24M Hz */
        ctrl->cnt_per_us = (float)(24000000.0 * (cfg->tmr_cfg.inc_val)) / ((cfg->tmr_cfg.si_val) + 1) /
                           1000000;

        if (cfg->tmr_cfg.inc_val != 0) {
            ctrl->ns_per_tick = (float)((1000) / ((24.0 * (cfg->tmr_cfg.inc_val)) / ((
                    cfg->tmr_cfg.si_val) + 1)));
        }
    }
    else {
        return SDRV_STATUS_INVALID_PARAM;
    }

    btm_max_count = SDRV_BTM_MODULE_NUM;

    status = sdrv_btm_get_module_id(cfg->base, &btm_id);

    if (status == SDRV_STATUS_FAIL)
        return SDRV_STATUS_INVALID_PARAM;

    if (btm_id >= btm_max_count)
        return SDRV_STATUS_INVALID_PARAM;

    sdrv_btm_hw_init(cfg->base, cfg->tmr_id, &(cfg->tmr_cfg));

    ctrl->status    = BTM_STATUS_IDLE;
    ctrl->type      = (btm_type_t)cfg->tmr_cfg.cnt_mode;        /*oneshot or continous*/
    ctrl->time_type = BTM_TIME_US;
    ctrl->time_out  = 0;
    ctrl->callback  = NULL;

    btm_controller[btm_id].btm_bank[cfg->tmr_id] = ctrl;

    if ((cfg->irq > 0) && (cfg->base == APB_BTM1_BASE)) {
        irq_attach(cfg->irq, sdrv_btm0_irq_handle, &btm_controller[btm_id]);
        irq_enable(cfg->irq);
    }else if ((cfg->irq > 0) && (cfg->base == APB_BTM2_BASE)) {
        irq_attach(cfg->irq, sdrv_btm1_irq_handle, &btm_controller[btm_id]);
        irq_enable(cfg->irq);
    }else if ((cfg->irq > 0) && (cfg->base == APB_BTM3_BASE)) {
        irq_attach(cfg->irq, sdrv_btm2_irq_handle, &btm_controller[btm_id]);
        irq_enable(cfg->irq);
    }else if ((cfg->irq > 0) && (cfg->base == APB_BTM4_BASE)) {
        irq_attach(cfg->irq, sdrv_btm3_irq_handle, &btm_controller[btm_id]);
        irq_enable(cfg->irq);
    }
#ifndef SEMIDRIVE_E3_LITE_SERIES
    else if ((cfg->irq > 0) && (cfg->base == APB_BTM5_BASE)) {
        irq_attach(cfg->irq, sdrv_btm4_irq_handle, &btm_controller[btm_id]);
        irq_enable(cfg->irq);
    }else if ((cfg->irq > 0) && (cfg->base == APB_BTM6_BASE)) {
        irq_attach(cfg->irq, sdrv_btm5_irq_handle, &btm_controller[btm_id]);
        irq_enable(cfg->irq);
    }
#endif
    else {
        return SDRV_STATUS_INVALID_PARAM;
    }

    return SDRV_STATUS_OK;
}

/**
 * @brief btm deinit
 *
 * Deinitial btm module instance.
 *
 * @param[in] ctrl: btm ctrl instance
 * @return succeed:0  fail:other
 */
status_t sdrv_btm_deinit(sdrv_btm_t *ctrl)
{
    ASSERT(ctrl != NULL);
    sdrv_btm_hw_timer_stop(ctrl->config->base, ctrl->config->tmr_id);
    ctrl->status    = BTM_STATUS_NULL;
    ctrl->type      = BTM_TYPE_ONESHOT;
    ctrl->time_type = BTM_TIME_US;
    ctrl->time_out  = 0;
    ctrl->callback  = NULL;
    ctrl->cnt_per_us = 0.0;
    ctrl->ns_per_tick = 0.0;

    return SDRV_STATUS_OK;
}

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
                        uint32 time_out)
{
    uint32 count = 0u;
    ASSERT(ctrl != NULL);

    if (BTM_STATUS_BUSY == ctrl->status) {
        return SDRV_STATUS_BUSY;
    }

    ctrl->time_type = time_type;
    ctrl->time_out = time_out;

    switch (time_type) {
        case BTM_TIME_MS: {
            count = (uint32)(time_out * ctrl->cnt_per_us * 1000);
        }
        break;

        case BTM_TIME_US: {
            count = (uint32)(time_out * ctrl->cnt_per_us);
        }
        break;

        case BTM_TIME_NS: {
            count = (uint32)(time_out / (ctrl->ns_per_tick));
        }
        break;

        default: {
            return SDRV_STATUS_INVALID_PARAM;
        }
    }

    if (ctrl->type != btm_type) {
        ctrl->type = btm_type;
        ctrl->config->tmr_cfg.cnt_mode = (sdrv_btm_cnt_mode_e)btm_type;
        sdrv_btm_hw_init(ctrl->config->base, ctrl->config->tmr_id, &(ctrl->config->tmr_cfg));
    }

    sdrv_btm_hw_timer_start(ctrl->config->base, ctrl->config->tmr_id, count - 1);
    sdrv_btm_hw_compare_int_en(ctrl->config->base, ctrl->config->tmr_id, false);
    ctrl->status = BTM_STATUS_BUSY;
    return SDRV_STATUS_OK;
}

/**
 * @brief btm stop
 *
 * BTM stop to count.
 *
 * @param[in] ctrl: btm ctrl instance
 * @return succeed:0  fail:other
 */
status_t sdrv_btm_stop(sdrv_btm_t *ctrl)
{
    ASSERT(ctrl != NULL);
    sdrv_btm_hw_timer_stop(ctrl->config->base, ctrl->config->tmr_id);
    ctrl->status    = BTM_STATUS_IDLE;
    return SDRV_STATUS_OK;
}

/**
 * @brief btm setup callback funciton
 *
 * @param[in] ctrl: btm ctrl instance
 * @param[in] callback: user callback function
 * @return succeed:0  fail:other
 */
status_t sdrv_btm_set_callback(sdrv_btm_t *ctrl, btm_callback callback, void *arg)
{
    ASSERT(ctrl != NULL);
    ctrl->callback  = callback;
    ctrl->arg       = arg;
    return SDRV_STATUS_OK;
}

/**
 * @brief get btm Elapsed time (us)
 *
 * @param[in] ctrl: btm ctrl instance
 * @return btm Elapsed time (us)
 */
uint32 sdrv_btm_get_current_time(sdrv_btm_t *ctrl)
{
    uint32 current = 0;
    ASSERT(ctrl != NULL);

    current = sdrv_btm_hw_get_cnt_val(ctrl->config->base, ctrl->config->tmr_id);

    if ((uint32)ctrl->cnt_per_us == 0) {
        return 0;
    }
    else {
        return (uint32)(current / ctrl->cnt_per_us);
    }
}


/**
 * @brief get btm Elapsed time (extend)
 *
 * @param[in] ctrl: btm ctrl instance
 * @param[in] time_type: time type
 * @return btm Elapsed time (us)
 */
uint32 sdrv_btm_get_current_time_ex(sdrv_btm_t *ctrl, btm_time_type_t time_type)
{
    uint32 current = 0;
    ASSERT(ctrl != NULL);

    current = sdrv_btm_hw_get_cnt_val(ctrl->config->base, ctrl->config->tmr_id);

    switch (time_type) {
        case BTM_TIME_MS: {
            if ((uint32)ctrl->cnt_per_us == 0) {
                return 0;
            }
            else {
                return (uint32)(current / (1000 * ctrl->cnt_per_us));
            }
        }
        break;

        case BTM_TIME_US: {
            if ((uint32)ctrl->cnt_per_us == 0) {
                return 0;
            }
            else {
                return (uint32)(current / ctrl->cnt_per_us);
            }
        }
        break;

        case BTM_TIME_NS: {
            if ((uint32)ctrl->ns_per_tick == 0) {
                return 0;
            }
            else {
                return (uint32)(current * (ctrl->ns_per_tick));
            }
        }
        break;

        default: {
            return 0;
        }
    }
}



/**
 * @brief btm pause
 *
 * @param[in] ctrl: btm ctrl instance
 * @return succeed:0  fail:other
 */
status_t sdrv_btm_pause(sdrv_btm_t *ctrl)
{
    ASSERT(ctrl != NULL);
    sdrv_btm_hw_cnt_stop(ctrl->config->base, ctrl->config->tmr_id, true);
    ctrl->status    = BTM_STATUS_IDLE;
    return SDRV_STATUS_OK;
}

/**
 * @brief btm continue
 *
 * @param[in] ctrl: btm ctrl instance
 * @return succeed:0  fail:other
 */
status_t sdrv_btm_continue(sdrv_btm_t *ctrl)
{
    ASSERT(ctrl != NULL);
    sdrv_btm_hw_cnt_stop(ctrl->config->base, ctrl->config->tmr_id, false);
    ctrl->status    = BTM_STATUS_BUSY;
    return SDRV_STATUS_OK;
}

/**
 * @brief btm continue
 *
 * @param[in] ctrl: btm ctrl instance
 * @return    btm ctrl instance status
 */
btm_status_t sdrv_btm_get_status(sdrv_btm_t *ctrl)
{
    ASSERT(ctrl != NULL);
    return ctrl->status;
}

/**
 * @brief get btm counter value
 *
 * @param[in] ctrl: btm ctrl instance
 * @return btm counter value
 */
uint32 sdrv_btm_get_counter(sdrv_btm_t *ctrl)
{
    ASSERT(ctrl != NULL);
    return sdrv_btm_hw_get_cnt_val(ctrl->config->base, ctrl->config->tmr_id);
}

/**
 * @brief set btm overflow value
 *
 * @param[in] ctrl: btm ctrl instance
 * @param[in] val: btm overflow value
 * @return    succeed:0  fail:other
 */
status_t sdrv_btm_set_overflow(sdrv_btm_t *ctrl, uint32 val)
{
    ASSERT(ctrl != NULL);
    sdrv_btm_hw_set_ovf_cnt(ctrl->config->base, ctrl->config->tmr_id, val);
    return SDRV_STATUS_OK;
}

/**
 * @brief btm force reset counter value
 *
 * Btm force reset counter value to 0.
 *
 * @param[in] ctrl: btm ctrl instance
 * @return succeed:0  fail:other
 */
status_t sdrv_btm_force_reload(sdrv_btm_t *ctrl)
{
    ASSERT(ctrl != NULL);
    sdrv_btm_hw_frc_rld(ctrl->config->base, ctrl->config->tmr_id);
    return SDRV_STATUS_OK;
}

/**
 * @brief is btm overflow.
 *
 * Check btm overflow status.
 *
 * @param[in] ctrl: btm ctrl instance
 * @return true:overflow  fail:not overflow
 */
bool sdrv_btm_is_overflowed(sdrv_btm_t *ctrl)
{
    uint32 int_sta = 0u;
    ASSERT(ctrl != NULL);

    int_sta = sdrv_btm_hw_get_int_sta(ctrl->config->base);

    if (ctrl->config->tmr_id == SDRV_BTM_G1) {
        return (int_sta & BTM_BM_INT_STAT_OE_G1) ? true : false;
    }
    else {
        return (int_sta & BTM_BM_INT_STAT_OE_G0) ? true : false;
    }
}

/**
 * @brief btm clear interupt status
 *
 * @param[in] ctrl: btm ctrl instance
 * @return succeed:0  fail:other
 */
status_t sdrv_btm_clear_intr(sdrv_btm_t *ctrl)
{
    uint32 int_sta = 0u;
    ASSERT(ctrl != NULL);

    int_sta = sdrv_btm_hw_get_int_sta(ctrl->config->base);
    sdrv_btm_hw_set_int_sta(ctrl->config->base, int_sta);
    return SDRV_STATUS_OK;
}

/**
 * @brief btm convert count to time in us
 *
 * @param[in] ctrl: btm ctrl instance
 * @param[in] cnt: btm count value
 * @return time in microseconds.
 */
uint32 sdrv_btm_count_to_us(sdrv_btm_t *ctrl, uint32 cnt)
{
    ASSERT(ctrl != NULL);
    return (uint32)(ctrl->cnt_per_us) ? (uint32)(cnt / ctrl->cnt_per_us) : 0;
}
