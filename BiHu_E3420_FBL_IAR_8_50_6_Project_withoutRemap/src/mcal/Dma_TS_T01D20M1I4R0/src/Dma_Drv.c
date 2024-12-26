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
 * @file  dma.c
 * @brief Semidrive. Dma
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <_assert.h>
#include <SchM_Dma.h>

#include "Dma_Drv.h"

#include "arch.h"

/**
 * @brief init dma control
 *
 * @param[in] dev dma control instance,for details, see dma_dev_t
 * @return 0 if OK, or a negative error code.
 */
int dma_init(dma_dev_t *dev)
{
    int ret = 0;
    ASSERT(NULL != dev);

    SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_00();
    list_initialize(&dev->channels);

    if ((NULL != dev->ops) && (NULL != dev->ops->init))
        ret = dev->ops->init(dev);

    SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_00();

    return ret;
}
/**
 * @brief request channel random
 *
 * @param[in] dev dma control instance,for details,see dma_dev_t
 * @return channel info
 */
dma_chan_t *dma_req_chan(dma_dev_t *dev)
{
    dma_chan_t *chan = NULL;
    ASSERT(NULL != dev);

    SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_00();

    if ((NULL != dev->ops) && (NULL != dev->ops->request_chan))
        chan = dev->ops->request_chan(dev, NULL);

    SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_00();

    return chan;
}

/**
 * @brief request channel by id
 *
 * @param[in] dev dma control instance,for details,see dma_dev_t
 * @param[in] id request specified channel
 * @return channel info
 */
dma_chan_t *dma_req_chan_with_id(dma_dev_t *dev, uint32 id)
{
    dma_chan_t *chan = NULL;
    ASSERT(NULL != dev);

    SchM_Enter_Dma_DMA_EXCLUSIVE_AREA_00();

    if ((NULL != dev->ops) && (NULL != dev->ops->request_chan))
        chan = dev->ops->request_chan(dev, &id);

    SchM_Exit_Dma_DMA_EXCLUSIVE_AREA_00();

    return chan;
}

/**
 * @brief free channel
 *
 * @param[in] chan requested channel info
 */
void dma_free_chan(dma_chan_t *chan)
{
    ASSERT(NULL != chan);

    if ((NULL != chan->device->ops) &&
        (NULL != chan->device->ops->release_chan))
        chan->device->ops->release_chan(chan);
}

/**
 * @brief dma device config (only for dev2mem or mem2dev)
 *
 * @param[in] chan requested channel info
 * @param[in] cfg  devcie config,for details, see dma_dev_cfg_t
 */
void dma_config_chan(dma_chan_t *chan, dma_dev_cfg_t *cfg)
{
    ASSERT((NULL != chan) && (NULL != cfg));

    if ((NULL != chan->device->ops) && (NULL != chan->device->ops->config_chan))
        chan->device->ops->config_chan(chan, cfg);
}

/**
 * @brief get mem2mem copy transfer config
 *
 * @param[in] chan requested channel info
 * @param[in] dst  dst address
 * @param[in] src  src address
 * @param[in] buf_len transfer length
 * @param[in] flags enable or disable interrupt,see dma_ctrl_flags_t
 * @return true/false
 */
bool dma_prep_memcpy(dma_chan_t *chan, void *dst, void *src, uint32 buf_len,
                     uint32 flags)
{
    ASSERT(NULL != chan);

    if ((NULL != chan->device->ops) && (NULL != chan->device->ops->prep_memcpy))
        return chan->device->ops->prep_memcpy(chan, dst, src, buf_len, flags);
    else
        return false;
}

/**
 * @brief get mem2mem set transfer config
 *
 * @param[in] chan requested channel info
 * @param[in] val  set value
 * @param[in] buf_addr  dst address
 * @param[in] buf_len transfer length
 * @param[in] flags enable or disable interrupt,see dma_ctrl_flags_t
 * @return true/false
 */
bool dma_prep_memset(dma_chan_t *chan, uint8 val, void *buf_addr,
                     uint32 buf_len, uint32 flags)
{
    ASSERT(NULL != chan);

    if ((NULL != chan->device->ops) && (NULL != chan->device->ops->prep_memset))
        return chan->device->ops->prep_memset(chan, val, buf_addr, buf_len,
                                              flags);
    else
        return false;
}

/**
 * @brief get mem2dev or dev2mem transfer config
 *
 * @param[in] chan requested channel info
 * @param[in] buf_addr  dst address or src address (with dma_dev_config api)
 * @param[in] buf_len transfer length
 * @param[in] flags enable or disable interrupt,see dma_ctrl_flags_t
 * @return true/false
 */
bool dma_prep_dev(dma_chan_t *chan, void *buf_addr, uint32 buf_len,
                  uint32 flags)
{
    ASSERT(NULL != chan);

    if ((NULL != chan->device->ops) && (NULL != chan->device->ops->prep_dev))
        return chan->device->ops->prep_dev(chan, buf_addr, buf_len, flags);
    else
        return false;
}

/**
 * @brief get mem2dev or dev2mem transfer config (loop)
 *
 * @param[in] chan requested channel info
 * @param[in] buf_addr  dst address or src address (with dma_dev_config api)
 * @param[in] buf_len transfer length
 * @param[in] period_len package data length in a time
 * @param[in] flags enable or disable interrupt,see dma_ctrl_flags_t
 * @return true/false
 */
bool dma_prep_cyclic(dma_chan_t *chan, void *buf_addr, uint32 buf_len,
                     uint32 period_len, uint32 flags)
{
    ASSERT(NULL != chan);

    if ((NULL != chan->device->ops) && (NULL != chan->device->ops->prep_cyclic))
        return chan->device->ops->prep_cyclic(chan, buf_addr, buf_len,
                                              period_len, flags);
    else
        return false;
}

/**
 * @brief start transfer
 *
 * @param[in] chan requested channel info
 */
void dma_start(dma_chan_t *chan)
{
    ASSERT(NULL != chan);

    if ((NULL != chan->device->ops) && (NULL != chan->device->ops->enable_chan))
        chan->device->ops->enable_chan(chan);
}

/**
 * @brief terminate transfer
 *
 * @param[in] chan requested channel info
 * @return true/false
 */
bool dma_stop(dma_chan_t *chan)
{
    ASSERT(NULL != chan);

    if ((NULL != chan->device->ops) &&
        (NULL != chan->device->ops->disable_chan))
        return chan->device->ops->disable_chan(chan);
    else
        return false;
}

/**
 * @brief get transfer status
 *
 * @param[in] chan arequested channel info
 * @return dma_status_e (completed in_progress err paused)
 */
dma_status_e dma_get_chan_status(dma_chan_t *chan)
{
    ASSERT(NULL != chan);

    if ((NULL != chan->device->ops) &&
        (NULL != chan->device->ops->get_ch_status))
        return chan->device->ops->get_ch_status(chan);
    else
        return DMA_ERR;
}

/**
 * @brief flush cache for prevent data inconsistency
 *
 * @param[in] dma_addr buffer address
 * @param[in] size  buffer length
 */
void dma_flush_cache(addr_t dma_addr, uint32 size)
{
    /* must align cache_line */
    ASSERT((dma_addr % CONFIG_ARCH_CACHE_LINE == 0) && (size % CONFIG_ARCH_CACHE_LINE == 0));
    arch_clean_cache_range((const void *)(uint32 *)dma_addr, size);
}

/**
 * @brief flush invalidate for prevent data inconsistency
 *
 * @param[in] dma_addr  buffer address
 * @param[in] size  buffer length
 */
void dma_invalidate_cache(addr_t dma_addr, uint32 size)
{
    /* must align cache_line */
    ASSERT((dma_addr % CONFIG_ARCH_CACHE_LINE == 0) && (size % CONFIG_ARCH_CACHE_LINE == 0));
    arch_invalidate_cache_range((const void *)(uint32 *)dma_addr, size);
}

#ifdef __cplusplus
}
#endif
