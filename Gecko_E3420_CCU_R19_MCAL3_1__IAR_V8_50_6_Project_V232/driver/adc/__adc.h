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
 * @file  __adc.h
 * @brief Semidrive. adc
 */

#ifndef ADC_H_
#define ADC_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <__compiler.h>
#include <stdarg.h>
#include <types.h>
#include <__debug.h>

#include "e3_clk.h"


typedef uint16 adc_data_size_t;
typedef uint16 adc_ch_size_t;

typedef enum
{
    ADC_XFER_INTERRUPT_MODE_E = 0,
    ADC_XFER_POLLING_MODE_E,
    ADC_XFER_DMA_MODE_E,
} adc_xfer_mod_e_t;

/**
 * @brief adc basic configurations.
 */
typedef struct adc_config {
    uint32 irq;
    addr_t base;
    uint8 resolution;
    bool inter_ref_volt;
    uint32 sample_freq;
    adc_xfer_mod_e_t xfer_mode;
    bool is_diff;
    clk_node_t *clk;
} adc_config_t;

typedef struct adc_channel_chain {
    uint8 *chain_mask;
    uint8 chain_mask_len;
} adc_channel_chain_t;

#ifdef ADC_MAX_CHANNEL_NUM
#define DEFINE_CHANNEL_MASK(name)                                           \
  uint8 name##_array[ADC_MAX_CHANNEL_NUM / 8] = { 0 };                       \
  adc_channel_chain_t name = {                                              \
      .chain_mask = name##_array,                                           \
      .chain_mask_len = ADC_MAX_CHANNEL_NUM / 8,                            \
  }
#endif

typedef struct adc_buff {
    adc_data_size_t sample_val;
    adc_ch_size_t channel;
} __PACKED adc_buff_t;

typedef void (*adc_callback_t)(adc_buff_t *buff, uint16 len, void *context);

struct adc_ops;

/**
 * @brief adc device.
 */
typedef struct adc_dev {
    adc_config_t    adc_conf;
    adc_buff_t      *buf;
    uint16        len;
    uint16        cur_len;
    uint16        fifo_size;
    adc_ch_size_t   channel_num;
    adc_callback_t  cb;
    void            *context;
    struct adc_ops  *ops;
    void *priv;
} adc_dev_t;

typedef struct adc_ops {
    int (*adc_start)(adc_dev_t *device, adc_channel_chain_t *channel_chain,
                     adc_buff_t *buf, uint16 len);
    int (*adc_stop)(adc_dev_t *device);
    int (*adc_read_sample)(adc_dev_t *device, adc_channel_chain_t *channel_chain,
                           adc_buff_t *buff, uint16 len);
    void (*adc_main_func)(adc_dev_t *device);
    int (*adc_irq_handler)(uint32 irq, void *arg);
} adc_ops_t;

/**
 * @brief adc_add_channel_mask.
 *
 * @param[in] chain mask point
 * @param[in] number of configured channels
 * @param[in] channel num
 */
void adc_add_channel_mask(adc_channel_chain_t *name, adc_ch_size_t num, ...);

/**
 * @brief adc_clear_channel_mask.
 *
 * @param[in] chain mask point
 * @param[in] number of cleared channels
 * @param[in] channel num
 */
void adc_clear_channel_mask(adc_channel_chain_t *name, adc_ch_size_t num, ...);

/**
 * @brief adc_clear_all_channel_mask.
 *
 * @param[in] chain mask point
 */
void adc_clear_all_channel_mask(adc_channel_chain_t *name);

/**
 * @brief adc init.
 *
 * @param[in] adc dev
 * @param[in] adc config
 * @return sint32
 * @retval ADC_OK: success
 * @retval ADC_ERR: fail
 */
sint32 adc_init(adc_dev_t *device, const adc_config_t *cfg);

/**
 * @brief adc deinit.
 *
 * @param[in] adc dev
 * @return sint32
 * @retval ADC_OK: success
 * @retval ADC_ERR: fail
 */
sint32 adc_deinit(adc_dev_t *device);

/**
 * @brief Read Sample from multi channel (sync).
 *
 * @param[in] adc dev
 * @param[in] adc multi channel to read data
 * @param[out] adc multi channel read sample value
 * @param[in] buf len
 * @return sint32
 * @retval ADC_OK: success
 * @retval ADC_ERR: fail
 */
sint32 adc_read_sample(adc_dev_t *device, adc_channel_chain_t *channel_chain,
                        adc_buff_t *buff, uint16 len);

/**
 * @brief Continuous read Sample from multi channel.
 *
 * @param[in] adc dev
 * @param[in] adc multi channel to read data
 * @param[in] adc buf
 * @return sint32
 * @retval ADC_OK: success
 * @retval ADC_ERR: fail
 */
sint32 adc_start(adc_dev_t *device, adc_channel_chain_t *channel_chain,
                  adc_buff_t *buf, uint16 len);

/**
 * @brief Stop continuous read Sample from multi channel.
 *
 * @param[in] adc dev
 * @return sint32
 * @retval ADC_OK: success
 * @retval ADC_ERR: fail
 */
sint32 adc_stop(adc_dev_t *device);

/**
 * @brief Set callback for async mode.
 *
 * @param[in] adc dev
 * @param[in] callback
 * @param[in] context
 */
static inline void adc_set_callback(adc_dev_t *device, adc_callback_t callback,
                      void *context)
{
    ASSERT(device);

    device->cb = callback;
    device->context = context;
}

/**
 * @brief main_func in polling mode.
 *
 * @param[in] adc dev
 */
void adc_main_func(adc_dev_t *device);

#ifdef __cplusplus
}
#endif

#endif /* _ADC_H */
