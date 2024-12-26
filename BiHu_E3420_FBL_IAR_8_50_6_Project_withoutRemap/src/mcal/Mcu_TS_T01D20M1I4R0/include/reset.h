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

#ifndef RESET_H_
#define RESET_H_

#include <spinlock.h>

struct reset_ctl;

enum reset_lowpower_mode {
    RESET_LP_HIB   = 0,
    RESET_LP_SLEEP = 1,
};

/**
 * @brief reset hardware driver function table
 */
typedef struct reset_ctl_ops {
    /* initialize reset controller */
    sint32 (*init)(struct reset_ctl *rst_ctl);

    /* deinitialize reset controller */
    void (*deinit)(struct reset_ctl *rst_ctl);

    /* assert a reset signal */
    sint32 (*assert)(struct reset_ctl *rst_ctl, uint32 id);

    /* deassert a reset signal */
    sint32 (*deassert)(struct reset_ctl *rst_ctl, uint32 id);

    /* assert a reset signal, and deassert automatically */
    sint32 (*reset)(struct reset_ctl *rst_ctl, uint32 id);

    /* check reset signal status */
    sint32 (*status)(struct reset_ctl *rst_ctl, uint32 id);

    /* read reset general reg */
    uint32 (*read_general)(struct reset_ctl *rst_ctl, uint32 id);

    /* write reset general reg */
    sint32 (*write_general)(struct reset_ctl *rst_ctl, uint32 id, uint32 val);

    /* global reset */
    void (*global_reset)(struct reset_ctl *sf_rst_ctl);

    /* config reset sig assert/deassert in LP mode */
    sint32 (*lowpower_set)(struct reset_ctl *rst_ctl, uint32 id, enum reset_lowpower_mode mode,
                           uint32 val);
} reset_ctl_ops_t;

/**
 * @brief abstract reset controller
 */
typedef struct reset_ctl {
    spin_lock_t         lock;
    reset_ctl_ops_t     *ops;
    void                *priv;
} reset_ctl_t;

/**
 * @brief abstract reset signal
 */
typedef struct reset_sig {
    struct reset_ctl    *rst_ctl;
    uint32            id;
} reset_sig_t;

/**
 * @brief abstract reset general reg
 */
typedef struct reset_general_reg {
    struct reset_ctl    *rst_ctl;
    uint32            id;
} reset_general_reg_t;

/**
 * @brief global reset controller
 */
typedef struct reset_glb_ctl {
    struct reset_ctl    *rst_sf_ctl;
} reset_glb_ctl_t;

/**
 * @brief Initialize the reset controller.
 *
 * @param[in] rst_ctl Common reset controller.
 * @return 0 if OK, or a negative error code.
 */
sint32 reset_ctl_init(struct reset_ctl *rst_ctl);

/**
 * @brief Deinitialize the reset controller.
 *
 * @param[in] rst_ctl Common reset controller.
 */
void reset_ctl_deinit(struct reset_ctl *rst_ctl);

/**
 * @brief Assert a reset signal.
 * The reset singal will stay asserted until reset_deassert() is called.
 *
 * @param[in] rst_sig Reset signal.
 * @return 0 if OK, or a negative error code.
 */
sint32 reset_ctl_assert(struct reset_sig *rst_sig);

/**
 * @brief Deassert a reset signal.
 *
 * @param[in] rst_sig Reset signal.
 * @return 0 if OK, or a negative error code.
 */
sint32 reset_ctl_deassert(struct reset_sig *rst_sig);

/**
 * @brief Assert a reset signal, and deassert automatically.
 *
 * @param[in] rst_sig Reset signal.
 * @return 0 if OK, or a negative error code.
 */
sint32 reset_ctl_reset(struct reset_sig *rst_sig);

/**
 * @brief Check reset signal status.
 *
 * @param[in] rst_sig Reset signal.
 * @return 0 if deasserted, positive if asserted,
 *         or a negative error code.
 */
sint32 reset_ctl_status(struct reset_sig *rst_sig);

/**
 * @brief Read reset general reg.
 *
 * @param[in] general general reg.
 * @return general reg value.
 */
uint32 reset_ctl_general_read(struct reset_general_reg *general);

/**
 * @brief Write reset general reg.
 *
 * @param[in] general general reg.
 * @param[in] val write value.
 * @return 0 if success,
 *         or a negative error code.
 */
sint32 reset_ctl_general_write(struct reset_general_reg *general, uint32 val);

/**
 * @brief Global reset.
 *
 * @param[in] rst_glb_ctl Global reset controller.
 */
void reset_ctl_global_reset(struct reset_glb_ctl *rst_glb_ctl);

/**
 * @brief Config reset signal assert/deassert in lowpower mode.
 *
 * @param[in] rst_sig Reset signal.
 * @param[in] mode lowpower mode
 * @param[in] val 0:assert, 1:deassert
 *
 * @return 0 if OK, or a negative error code.
 */
sint32 reset_ctl_lowpower_set(struct reset_sig *rst_sig, enum reset_lowpower_mode mode, uint32 val);

#endif /* RESET_H_ */
