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

#ifdef __cplusplus
extern "C" {
#endif
#include <arch.h>
#include "__regs_base.h"
#include "Mcu_PvtSens.h"
#include "RegHelper.h"
#include "irq_num.h"
#include "irq.h"
#include "Mcu_Cfg.h"
#include "debug.h"
#include "bits.h"
#include "Mcu.h"

sdrv_pvt_t pvt_sf = {.base = APB_PT_SNS_SF_BASE,
.core = {
    {.irq = PT_SNS_SF_DIG_PVT_0_INTR_NUM},
    {.irq = PT_SNS_SF_DIG_PVT_1_INTR_NUM},
}
                           };

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

/* Length of PVT DOUT and Threshold register bits. */
#define PVT_THRESH_BITS (12)

/* PVT registers */
#define PVT_CORE_REG_OFFSET (0x34)
#define PVT_CORE_REGISTER(core, reg) ((core)*PVT_CORE_REG_OFFSET + (reg))

#define PVT_CTRL (0x0)
#define PVT_CTRL_PDTSEN 1
#define PVT_CTRL_PTSEL 4
#define PVT_CTRL_HL_MODE_EN(core) (8 + (core)*2)
#define PVT_CTRL_RF_MODE_EN(core) (9 + (core)*2)

#define PVT_DOUT (0x4)
#define PVT_DOUT_VALID 0
#define PVT_DOUT_DOUT 1

#define PVT_HYST_H(core) PVT_CORE_REGISTER(core, 0x8)
#define PVT_HYST_H_THRESH_H 0
#define PVT_HYST_H_THRESH_L 12

#define PVT_HYST_L(core) PVT_CORE_REGISTER(core, 0xc)
#define PVT_HYST_L_THRESH_H 0
#define PVT_HYST_L_THRESH_L 12

#define PVT_HYST_R(core) PVT_CORE_REGISTER(core, 0x10)
#define PVT_HYST_R_ALARM 0
#define PVT_HYST_R_HYST 12

#define PVT_HYST_F(core) PVT_CORE_REGISTER(core, 0x14)
#define PVT_HYST_F_ALARM 0
#define PVT_HYST_F_HYST 12

#define PVT_INT_EN(core) PVT_CORE_REGISTER(core, 0x30)
#define PVT_INT_STATUS(core) PVT_CORE_REGISTER(core, 0x34)
#define PVT_INT_CLR(core) PVT_CORE_REGISTER(core, 0x38)

#define PVT_ALARM_INT(alarm) (uint32)(alarm)

extern const sdrv_pvt_config_t  Mcu_PvtCfg;

void pvt_alarm_cb(struct sdrv_pvt *dev)
{
    float temp = 0;

    sdrv_pvt_get(dev, &temp);

    DBG("%s: dev 0x%x, temp %f\r\n", __FUNCTION__,dev->base,temp);
}


static inline sdrv_pvt_core_t *pvt_core(sdrv_pvt_t *dev,
                                        sdrv_pvt_core_id_e core)
{
    return &dev->core[core];
}

/* Convert DOUT register value to Celsius. */
static inline float dout_to_celsius(uint32 dout)
{
    dout &= BIT_MASK(PVT_THRESH_BITS);
    return 306.76f * dout / 4096 - 75.98f;
}

/* Convert Celsius to DOUT register value. */
static inline uint32 celsius_to_dout(float celsius)
{
    uint32 dout = (uint32)((celsius + 75.98f) * 4096 / 306.76f);
    return dout & BIT_MASK(PVT_THRESH_BITS);
}

void pvt_core0_irq_handler(void)
{
    uint32 core = 0u;
    sdrv_pvt_t *dev = &pvt_sf;
    sdrv_pvt_core_t *_core = &(dev->core[core]);
    paddr_t base = APB_PT_SNS_SF_BASE;
    sdrv_pvt_alarm_e alarm;
    uint32 en, status;

    en = readl(base + PVT_INT_EN(core));
    status = readl(base + PVT_INT_STATUS(core));

    /* Handle alarm IRQ, if it's enabled. */
    for (alarm = PVT_HIGH_LEVEL_ALARM; alarm < PVT_ALARM_NR; alarm++) {
        if (BIT_SET(en, PVT_ALARM_INT(alarm)) &&
            BIT_SET(status, PVT_ALARM_INT(alarm))) {
            if (_core->alarm_cb != NULL) {
                /* Call user alarm callback. */
                _core->alarm_cb(dev);
            }

            /*
             * Try to clear interrupt status. Level interrupt status are
             * cleared when INT_CLR bits are set, and DOUT has returned to
             * normal range. Edge interrupt status are cleared when INT_CLR
             * bits are set.
             *
             * Note that INT_CLR itself is not auto cleared, so we have to
             * clear INT_CLR manually.
             */
            RMWREG32(base + PVT_INT_CLR(core), PVT_ALARM_INT(alarm), 1, 1);
            RMWREG32(base + PVT_INT_CLR(core), PVT_ALARM_INT(alarm), 1, 0);
        }
    }

    return;
}

void pvt_core1_irq_handler(void)
{
    uint32 core = 1u;
    sdrv_pvt_t *dev = &pvt_sf;
    sdrv_pvt_core_t *_core = &(dev->core[core]);
    paddr_t base = APB_PT_SNS_SF_BASE;
    sdrv_pvt_alarm_e alarm;
    uint32 en, status;

    en = readl(base + PVT_INT_EN(core));
    status = readl(base + PVT_INT_STATUS(core));

    /* Handle alarm IRQ, if it's enabled. */
    for (alarm = PVT_HIGH_LEVEL_ALARM; alarm < PVT_ALARM_NR; alarm++) {
        if (BIT_SET(en, PVT_ALARM_INT(alarm)) &&
            BIT_SET(status, PVT_ALARM_INT(alarm))) {
            if (_core->alarm_cb != NULL) {
                /* Call user alarm callback. */
                _core->alarm_cb(dev);
            }

            /*
             * Try to clear interrupt status. Level interrupt status are
             * cleared when INT_CLR bits are set, and DOUT has returned to
             * normal range. Edge interrupt status are cleared when INT_CLR
             * bits are set.
             *
             * Note that INT_CLR itself is not auto cleared, so we have to
             * clear INT_CLR manually.
             */
            RMWREG32(base + PVT_INT_CLR(core), PVT_ALARM_INT(alarm), 1, 1);
            RMWREG32(base + PVT_INT_CLR(core), PVT_ALARM_INT(alarm), 1, 0);
        }
    }

    return;
}

static int update_alarm_irq(sdrv_pvt_t *dev, sdrv_pvt_core_id_e core)
{
    sdrv_pvt_core_t *_core = pvt_core(dev, core);
    paddr_t base = dev->base;

    /* Update High/Low mode bit in PVT_CTRL register, which controls
     * Temperature and Process High/Low modes.
     */
    if (BIT_SET(_core->alarm_enable_mask, PVT_HIGH_LEVEL_ALARM) ||
        BIT_SET(_core->alarm_enable_mask, PVT_LOW_LEVEL_ALARM)) {
        RMWREG32(base + PVT_CTRL, PVT_CTRL_HL_MODE_EN(core), 1, 1);
    } else {
        RMWREG32(base + PVT_CTRL, PVT_CTRL_HL_MODE_EN(core), 1, 0);
    }

    /* Update Rising/Falling mode bit in PVT_CTRL register, which controls
     * Temperature and Process Rising/Falling modes.
     */
    if (BIT_SET(_core->alarm_enable_mask, PVT_RISING_EDGE_ALARM) ||
        BIT_SET(_core->alarm_enable_mask, PVT_FALLING_EDGE_ALARM)) {
        RMWREG32(base + PVT_CTRL, PVT_CTRL_RF_MODE_EN(core), 1, 1);
    } else {
        RMWREG32(base + PVT_CTRL, PVT_CTRL_RF_MODE_EN(core), 1, 0);
    }

    /* Enable alarm interrupt if necessary. */
    if (_core->alarm_cb != NULL && _core->alarm_enable_mask != 0) {
        sdrv_pvt_alarm_e alarm;

        for (alarm = PVT_HIGH_LEVEL_ALARM; alarm < PVT_ALARM_NR; alarm++) {
            if (BIT_SET(_core->alarm_enable_mask, alarm)) {
                RMWREG32(base + PVT_INT_EN(core), PVT_ALARM_INT(alarm), 1, 1);
            } else {
                RMWREG32(base + PVT_INT_EN(core), PVT_ALARM_INT(alarm), 1, 0);
            }
        }

        /* Enable PVT interrupt. */
        irq_enable(_core->irq);
    } else {
        /* All alarm disabled. Disable PVT interrupt. */
        irq_disable(_core->irq);
    }

    return 0;
}

static int update_alarm_mode(sdrv_pvt_t *dev, sdrv_pvt_core_id_e core,
                             sdrv_pvt_alarm_e alarm, bool enable)
{
    sdrv_pvt_core_t *_core = pvt_core(dev, core);

    if (enable) {
        _core->alarm_enable_mask |= (1ul << alarm);
    } else {
        _core->alarm_enable_mask &= ~(1ul << alarm);
    }

    return update_alarm_irq(dev, core);
}

static bool
is_valid_level_alarm_config(sdrv_pvt_alarm_e alarm,
                            const sdrv_pvt_level_alarm_config_t *config)
{
    (void)alarm;

    return config != NULL && config->thresh_low < config->thresh_high &&
           config->thresh_low >= PVT_TEMPERATURE_MIN &&
           config->thresh_high <= PVT_TEMPERATURE_MAX;
}

static bool
is_valid_edge_alarm_config(sdrv_pvt_alarm_e alarm,
                           const sdrv_pvt_edge_alarm_config_t *config)
{
    if (alarm == PVT_RISING_EDGE_ALARM) {
        return config != NULL && config->hyst < config->alarm &&
               config->hyst >= PVT_TEMPERATURE_MIN &&
               config->alarm <= PVT_TEMPERATURE_MAX;
    } else { /* PVT_FALLING_EDGE_ALARM */
        return config != NULL && config->alarm < config->hyst &&
               config->alarm >= PVT_TEMPERATURE_MIN &&
               config->hyst <= PVT_TEMPERATURE_MAX;
    }
}

static int enable_level_alarm(sdrv_pvt_t *dev, sdrv_pvt_core_id_e core,
                              sdrv_pvt_alarm_e alarm,
                              const sdrv_pvt_level_alarm_config_t *config,
                              bool enable)
{
    paddr_t base = dev->base;

    if (enable) {
        if (!is_valid_level_alarm_config(alarm, config)) {
            return -1;
        }

        /* Update High/Low alarm thresholds. */
        if (alarm == PVT_HIGH_LEVEL_ALARM) {
            RMWREG32(base + PVT_HYST_H(core), PVT_HYST_H_THRESH_H,
                     PVT_THRESH_BITS, celsius_to_dout(config->thresh_high));
            RMWREG32(base + PVT_HYST_H(core), PVT_HYST_H_THRESH_L,
                     PVT_THRESH_BITS, celsius_to_dout(config->thresh_low));
        } else { /* PVT_LOW_LEVEL_ALARM */
            RMWREG32(base + PVT_HYST_L(core), PVT_HYST_L_THRESH_H,
                     PVT_THRESH_BITS, celsius_to_dout(config->thresh_high));
            RMWREG32(base + PVT_HYST_L(core), PVT_HYST_L_THRESH_L,
                     PVT_THRESH_BITS, celsius_to_dout(config->thresh_low));
        }
    }

    return update_alarm_mode(dev, core, alarm, enable);
}

static int enable_edge_alarm(sdrv_pvt_t *dev, sdrv_pvt_core_id_e core,
                             sdrv_pvt_alarm_e alarm,
                             const sdrv_pvt_edge_alarm_config_t *config,
                             bool enable)
{
    paddr_t base = dev->base;

    if (enable) {
        if (!is_valid_edge_alarm_config(alarm, config)) {
            return -1;
        }

        /* Update Rising/Falling alarm thresholds. */
        if (alarm == PVT_RISING_EDGE_ALARM) {
            RMWREG32(base + PVT_HYST_R(core), PVT_HYST_R_ALARM, PVT_THRESH_BITS,
                     celsius_to_dout(config->alarm));
            RMWREG32(base + PVT_HYST_R(core), PVT_HYST_R_HYST, PVT_THRESH_BITS,
                     celsius_to_dout(config->hyst));
        } else { /* PVT_FALLING_EDGE_ALARM */
            RMWREG32(base + PVT_HYST_F(core), PVT_HYST_F_ALARM, PVT_THRESH_BITS,
                     celsius_to_dout(config->alarm));
            RMWREG32(base + PVT_HYST_F(core), PVT_HYST_F_HYST, PVT_THRESH_BITS,
                     celsius_to_dout(config->hyst));
        }
    }

    return update_alarm_mode(dev, core, alarm, enable);
}

static bool is_temperature_sensor_running(sdrv_pvt_t *dev)
{
    uint32 ctrl = readl(dev->base + PVT_CTRL);
    return !BIT_SET(ctrl, PVT_CTRL_PDTSEN) && !BIT_SET(ctrl, PVT_CTRL_PTSEL);
}

int sdrv_pvt_init(sdrv_pvt_t *dev)
{
    paddr_t base = dev->base;
    sdrv_pvt_core_id_e core;

    for (core = PVT_CORE0; core < PVT_CORE_NR; core++) {
        sdrv_pvt_core_t *_core = pvt_core(dev, core);

        /* Disable all interrupts by default. */
        writel(0ul, base + PVT_INT_EN(core));

        _core->alarm_cb = NULL;
        _core->cb_arg = NULL;
        _core->alarm_enable_mask = 0ul;

        if (core == PVT_CORE0) {
            irq_attach(_core->irq, pvt_core0_irq_handler, (void *)dev);
        } else {
            irq_attach(_core->irq, pvt_core1_irq_handler, (void *)dev);
        }

        irq_disable(_core->irq);
    }

    return 0;
}

int sdrv_pvt_deinit(sdrv_pvt_t *dev)
{
    paddr_t base = dev->base;
    sdrv_pvt_core_id_e core;

    for (core = PVT_CORE0; core < PVT_CORE_NR; core++) {
        sdrv_pvt_core_t *_core = pvt_core(dev, core);

        irq_disable(_core->irq);
        irq_detach(_core->irq);

        /* Disable all interrupts. */
        writel(0, base + PVT_INT_EN(core));

        _core->alarm_cb = NULL;
        _core->cb_arg = NULL;
        _core->alarm_enable_mask = 0ul;
    }

    return 0;
}

int sdrv_pvt_start(sdrv_pvt_t *dev)
{
    paddr_t base = dev->base;

    /* Disable T sensor */
    RMWREG32(base + PVT_CTRL, PVT_CTRL_PDTSEN, 1, 1);

    /* Select temperature sensor output. */
    RMWREG32(base + PVT_CTRL, PVT_CTRL_PTSEL, 1, 0);

    /* Enable T sensor. */
    RMWREG32(base + PVT_CTRL, PVT_CTRL_PDTSEN, 1, 0);

    return 0;
}

int sdrv_pvt_stop(sdrv_pvt_t *dev)
{
    /* Disable T sensor */
    RMWREG32(dev->base + PVT_CTRL, PVT_CTRL_PDTSEN, 1, 1);
    return 0;
}

int sdrv_pvt_get(sdrv_pvt_t *dev, float *temperature)
{
    uint32 dout;

    if (!is_temperature_sensor_running(dev)) {
        return -1;
    }

    /*
     * Read temperature data. PVT_DOUT is automatically updated every 280ms
     * after sdrv_pvt_start() is called.
     */
    dout = (readl(dev->base + PVT_DOUT) >> PVT_DOUT_DOUT) &
           BIT_MASK(PVT_THRESH_BITS);

    /* Convert data to Celsius. */
    *temperature = dout_to_celsius(dout);

    return 0;
}

int sdrv_pvt_register_alarm_cb(sdrv_pvt_t *dev, sdrv_pvt_core_id_e core,
                               sdrv_pvt_alarm_cb_t alarm_cb, void *arg)
{
    sdrv_pvt_core_t *_core = pvt_core(dev, core);

    _core->alarm_cb = alarm_cb;
    _core->cb_arg = arg;

    return update_alarm_irq(dev, core);
}

int sdrv_pvt_enable_alarm(sdrv_pvt_t *dev, sdrv_pvt_core_id_e core,
                          sdrv_pvt_alarm_e alarm,
                          const sdrv_pvt_alarm_config_t *config)
{
    int ret = -1;

    if (!is_temperature_sensor_running(dev)) {
        return ret;
    }

    switch (alarm) {
    case PVT_HIGH_LEVEL_ALARM:
    case PVT_LOW_LEVEL_ALARM:
        ret = enable_level_alarm(dev, core, alarm, &config->level_alarm, TRUE);
        break;

    case PVT_RISING_EDGE_ALARM:
    case PVT_FALLING_EDGE_ALARM:
        ret = enable_edge_alarm(dev, core, alarm, &config->edge_alarm, TRUE);
        break;

    default:
        break;
    }

    return ret;
}

int sdrv_pvt_disable_alarm(sdrv_pvt_t *dev, sdrv_pvt_core_id_e core,
                           sdrv_pvt_alarm_e alarm)
{
    int ret = -1;

    switch (alarm) {
    case PVT_HIGH_LEVEL_ALARM:
    case PVT_LOW_LEVEL_ALARM:
        ret = enable_level_alarm(dev, core, alarm, NULL, FALSE);
        break;

    case PVT_RISING_EDGE_ALARM:
    case PVT_FALLING_EDGE_ALARM:
        ret = enable_edge_alarm(dev, core, alarm, NULL, FALSE);
        break;

    default:
        break;
    }

    return ret;
}

/**
* @brief   Set Temperature monitoring of PVT sensor.
* @details Configure the temperature alarm type and threshold on EB;
1）Temperature highest thresholds alarm configuration:
            - After exceeding highest thresholds trigger a system reset.
2) Temperature high alarm configuration:
            - After exceeding thresholds, a warning is triggered,User alarm settings can be made in the function "pvt_alarm_cb".
3) Temperature rise alarm configuration:
            - After exceeding T1 degrees, the hardware starts the high temperature alarm monitoring,
            - After exceeding T2 degrees, a temperature rise warning is triggered,User alarm settings can be made in the function "pvt_alarm_cb".
            Note: Choose one of the two 2)/3)
*/
FUNC(void, MCU_CODE) Mcu_PVTInit(void)
{

    sdrv_pvt_alarm_config_t highest_level_cfg = {.level_alarm = {
            .thresh_low = (Mcu_PvtCfg.highest - 0.1f),
            .thresh_high = Mcu_PvtCfg.highest,
        }
    };

    sdrv_pvt_alarm_config_t high_level_cfg = {.level_alarm = {
            .thresh_low = (Mcu_PvtCfg.T1 - 0.1f),
            .thresh_high = Mcu_PvtCfg.T1,
        }
    };

    sdrv_pvt_alarm_config_t rising_edge_cfg = {.edge_alarm = {
            .hyst = Mcu_PvtCfg.T1,
            .alarm = Mcu_PvtCfg.T2,
        }
    };


    sdrv_pvt_init(&pvt_sf);

    /*use core0 as reset when temp over highest*/
    sdrv_pvt_register_alarm_cb(&pvt_sf, PVT_CORE0, Mcu_PvtCfg.pPvtNotification, NULL);

    /*use core1 as alarm when temp over threshold*/
    sdrv_pvt_register_alarm_cb(&pvt_sf, PVT_CORE1, Mcu_PvtCfg.pPvtNotification, NULL);

    sdrv_pvt_start(&pvt_sf);

    sdrv_pvt_enable_alarm(&pvt_sf, PVT_CORE0, PVT_HIGH_LEVEL_ALARM, &highest_level_cfg);

    if (Mcu_PvtCfg.type == PVT_HIGH_LEVEL_ALARM) {
        sdrv_pvt_enable_alarm(&pvt_sf, PVT_CORE1, PVT_HIGH_LEVEL_ALARM, &high_level_cfg);
    } else {
        sdrv_pvt_enable_alarm(&pvt_sf, PVT_CORE1, PVT_RISING_EDGE_ALARM, &rising_edge_cfg);
    }

    return;
}


#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif
