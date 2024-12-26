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

#include <bits.h>

#include "taishan_reset_drv.h"
#include "taishan_rstgen.h"

static sint32 taishan_reset_initialize(reset_ctl_t *rst_ctl);
static sint32 taishan_reset_assert(reset_ctl_t *rst_ctl, uint32 id);
static sint32 taishan_reset_deassert(reset_ctl_t *rst_ctl, uint32 id);
static sint32 taishan_reset_reset(reset_ctl_t *rst_ctl, uint32 id);
static sint32 taishan_reset_status(reset_ctl_t *rst_ctl, uint32 id);
static uint32 taishan_reset_read_general(reset_ctl_t *rst_ctl, uint32 id);
static sint32 taishan_reset_write_general(reset_ctl_t *rst_ctl, uint32 id, uint32 val);
static void taishan_reset_global_reset(struct reset_ctl *rst_sf_ctl);
static sint32 taishan_reset_lowpower_set(struct reset_ctl *rst_ctl, uint32 id,
        enum reset_lowpower_mode mode, uint32 val);

#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

static reset_ctl_ops_t ctl_ops = {
    .init     =  taishan_reset_initialize,
    .assert   =  taishan_reset_assert,
    .deassert =  taishan_reset_deassert,
    .reset    =  taishan_reset_reset,
    .status   =  taishan_reset_status,
    .read_general  = taishan_reset_read_general,
    .write_general = taishan_reset_write_general,
    .global_reset = taishan_reset_global_reset,
    .lowpower_set  = taishan_reset_lowpower_set,
};

#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

static sint32 taishan_reset_release_ctl(reset_ctl_t *rst_ctl, uint32 id, bool release)
{
    sint32 ret = -1;
    taishan_reset_ctl_t *taishan_rst = (taishan_reset_ctl_t *)rst_ctl->priv;

    switch (TAISHAN_RESET_TYPE(id)) {
    case TAISHAN_RESET_CORE:
        ret = taishan_rstgen_lld_core_control(
                  taishan_rst->base, TAISHAN_RESET_INDEX(id), release);
        break;

    case TAISHAN_RESET_MODULE:
        ret = taishan_rstgen_lld_module_control(
                  taishan_rst->base, TAISHAN_RESET_INDEX(id), release);
        break;

    case TAISHAN_RESET_MISSION:
        ret = taishan_rstgen_lld_mission_control(
                  taishan_rst->base, TAISHAN_RESET_INDEX(id), release);
        break;

    case TAISHAN_RESET_LATENT:
        ret = taishan_rstgen_lld_latent_control(
                  taishan_rst->base, TAISHAN_RESET_INDEX(id), release);
        break;

    default:
        break;
    }

    return ret;
}

static sint32 taishan_reset_initialize(reset_ctl_t *rst_ctl)
{
    uint32 init_cfg = 0x0u;
    taishan_reset_ctl_t *taishan_rst = (taishan_reset_ctl_t *)rst_ctl->priv;

    taishan_rstgen_lld_init(taishan_rst->base, init_cfg);

    return 0;
}

static sint32 taishan_reset_assert(reset_ctl_t *rst_ctl, uint32 id)
{
    return taishan_reset_release_ctl(rst_ctl, id, false);
}

static sint32 taishan_reset_deassert(reset_ctl_t *rst_ctl, uint32 id)
{
    return taishan_reset_release_ctl(rst_ctl, id, true);
}

static sint32 taishan_reset_reset(reset_ctl_t *rst_ctl, uint32 id)
{
    sint32 ret = -1;
    taishan_reset_ctl_t *taishan_rst =
        (taishan_reset_ctl_t *)rst_ctl->priv;

    switch (TAISHAN_RESET_TYPE(id)) {
    case TAISHAN_RESET_CORE:
        ret = taishan_rstgen_lld_core_reset(taishan_rst->base, TAISHAN_RESET_INDEX(id));
        break;

    case TAISHAN_RESET_MODULE:
        ret = taishan_rstgen_lld_module_control(
                  taishan_rst->base, TAISHAN_RESET_INDEX(id), false);

        if (ret == 0) {
            ret = taishan_rstgen_lld_module_control(
                      taishan_rst->base, TAISHAN_RESET_INDEX(id), true);
        }

        break;

    case TAISHAN_RESET_MISSION:
        ret = taishan_rstgen_lld_mission_control(
                  taishan_rst->base, TAISHAN_RESET_INDEX(id), false);

        if (ret == 0) {
            ret = taishan_rstgen_lld_mission_control(
                      taishan_rst->base, TAISHAN_RESET_INDEX(id), true);
        }

        break;

    case TAISHAN_RESET_LATENT:
        ret = taishan_rstgen_lld_latent_control(
                  taishan_rst->base, TAISHAN_RESET_INDEX(id), false);

        if (ret == 0) {
            ret = taishan_rstgen_lld_latent_control(
                      taishan_rst->base, TAISHAN_RESET_INDEX(id), true);
        }

        break;

    default:
        break;
    }

    return ret;
}

static void taishan_reset_global_reset(struct reset_ctl *rst_sf_ctl)
{
    taishan_reset_ctl_t *taishan_sf_rst =
        (taishan_reset_ctl_t *)rst_sf_ctl->priv;

    taishan_rstgen_lld_global_reset(taishan_sf_rst->base);
}

static sint32 taishan_reset_status(reset_ctl_t *rst_ctl, uint32 id)
{
    sint32 ret = -1;
    taishan_reset_ctl_t *taishan_rst =
        (taishan_reset_ctl_t *)rst_ctl->priv;

    switch (TAISHAN_RESET_TYPE(id)) {
    case TAISHAN_RESET_CORE:
        ret = !taishan_rstgen_lld_get_core_reset_status(
                  taishan_rst->base, TAISHAN_RESET_INDEX(id));
        break;

    case TAISHAN_RESET_MODULE:
        ret = !taishan_rstgen_lld_get_module_reset_status(
                  taishan_rst->base, TAISHAN_RESET_INDEX(id));
        break;

    default:
        break;
    }

    return ret;
}

static uint32 taishan_reset_read_general(reset_ctl_t *rst_ctl, uint32 id)
{
    uint32 ret = 0u;
    taishan_reset_ctl_t *taishan_rst =
        (taishan_reset_ctl_t *)rst_ctl->priv;

    if (id < TAISHAN_RESET_GENERAL_REG_NUM) {
        ret = taishan_rstgen_lld_read_general_reg(taishan_rst->base, id);
    }

    return ret;
}

static sint32 taishan_reset_write_general(reset_ctl_t *rst_ctl, uint32 id, uint32 val)
{
    taishan_reset_ctl_t *taishan_rst =
        (taishan_reset_ctl_t *)rst_ctl->priv;

    if (id < TAISHAN_RESET_GENERAL_REG_NUM) {
        taishan_rstgen_lld_write_general_reg(taishan_rst->base, id, val);
        return 0;
    } else {
        return -1;
    }
}

static sint32 taishan_reset_lowpower_set(struct reset_ctl *rst_ctl, uint32 id,
        enum reset_lowpower_mode mode, uint32 val)
{
    uint32 lp_mode;
    taishan_reset_ctl_t *taishan_rst = (taishan_reset_ctl_t *)rst_ctl->priv;

    if (mode == RESET_LP_HIB) {
        lp_mode = 1;
    } else if (mode == RESET_LP_SLEEP) {
        lp_mode = 2;
    } else {
        return -1;
    }

    switch (TAISHAN_RESET_TYPE(id)) {
    case TAISHAN_RESET_CORE:
        taishan_rstgen_lld_set_core_reset_by_mode(taishan_rst->base, TAISHAN_RESET_INDEX(id), lp_mode, val);
        break;

    case TAISHAN_RESET_MODULE:
        taishan_rstgen_lld_set_module_reset_by_mode(taishan_rst->base, TAISHAN_RESET_INDEX(id), lp_mode,
                val);
        break;

    case TAISHAN_RESET_MISSION:
        taishan_rstgen_lld_set_mission_reset_by_mode(taishan_rst->base, TAISHAN_RESET_INDEX(id), lp_mode,
                val);
        break;

    case TAISHAN_RESET_LATENT:
        taishan_rstgen_lld_set_latent_reset_by_mode(taishan_rst->base, TAISHAN_RESET_INDEX(id), lp_mode,
                val);
        break;

    case TAISHAN_RESET_IST:
        taishan_rstgen_lld_set_ist_reset_by_mode(taishan_rst->base, TAISHAN_RESET_INDEX(id), lp_mode, val);
        break;

    case TAISHAN_RESET_DEBUG:
        taishan_rstgen_lld_set_debug_reset_by_mode(taishan_rst->base, TAISHAN_RESET_INDEX(id), lp_mode,
                val);
        break;

    default:
        break;
    }

    return 0;
}

/**
 * @brief Initialize the  SemiDrive RESET controller.
 *
 * @param[in] rst_ctl Common reset device.
 * @param[in] taishan_rst_ctl SemiDrive reset device.
 * @return 0 if OK, or a negative error code.
 */
sint32 taishan_reset_init(reset_ctl_t *rst_ctl, taishan_reset_ctl_t *taishan_rst_ctl)
{
    rst_ctl->ops = &ctl_ops;
    rst_ctl->priv = taishan_rst_ctl;
    return reset_ctl_init(rst_ctl);
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
