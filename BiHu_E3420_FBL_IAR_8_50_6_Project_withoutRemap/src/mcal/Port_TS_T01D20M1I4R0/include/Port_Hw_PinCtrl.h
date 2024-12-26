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

#ifndef PINCTRL_H_
#define PINCTRL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "_assert.h"

/**
 * @brief Common PINCTRL configuration parameters.
 */
typedef enum pinctrl_config {
    /* PAD function. */
    PINCTRL_CONFIG_FUNCTION,
    /* Pull up, pull down, or no-pull. */
    PINCTRL_CONFIG_PULL,
    /* Open drain, open source, or push pull. */
    PINCTRL_CONFIG_DRIVE,
    /* Drive strength. */
    PINCTRL_CONFIG_DRIVE_STRENGTH,
    /* Enable schmitt-trigger input mode. */
    PINCTRL_CONFIG_INPUT_SCHMITT,
    /* Slew rate. */
    PINCTRL_CONFIG_SLEW_RATE,
    /* Force input. */
    PINCTRL_CONFIG_FORCE_INPUT,
    /* Mode select, analog digital combo io only */
    PINCTRL_CONFIG_MODE_SELECT,
    PINCTRL_CONFIG_MAX,
} pinctrl_config_e;

/* PINCTRL_CONFIG_FUNCTION values are hardware specific. */

/* PINCTRL_CONFIG_PULL values. */
#define PINCTRL_PULL_NOPULL             0
#define PINCTRL_PULL_DOWN               1
#define PINCTRL_PULL_UP                 2

/* PINCTRL_CONFIG_DRIVE values. */
#define PINCTRL_DRIVE_OPEN_DRAIN        0
#define PINCTRL_DRIVE_OPEN_SOURCE       1
#define PINCTRL_DRIVE_PUSH_PULL         2

/* PINCTRL_CONFIG_DRIVE_STRENGTH values are hardware specific. */

/* PINCTRL_CONFIG_INPUT_SCHMITT values. */
#define PINCTRL_INPUT_SCHMITT_DISABLE   0
#define PINCTRL_INPUT_SCHMITT_ENABLE    1

/* PINCTRL_CONFIG_SLEW_RATE values are hardware specific. */

/* PINCTRL_CONFIG_FORCE_INPUT */
#define PINCTRL_FORCE_INPUT_NORMAL  0
#define PINCTRL_FORCE_INPUT_ENABLE  1
#define PINCTRL_FORCE_INPUT_HIGH    2
#define PINCTRL_FORCE_INPUT_LOW     3

struct pinctrl;

/**
 * @brief Common pinctrl device operation APIs.
 */
typedef struct pinctrl_ops {
    /* Controller initialization. */
    void (*init)(const struct pinctrl *pinctrl);

    /* Controller de-initialization. */
    void (*deinit)(const struct pinctrl *pinctrl);

    /*
     * Configure pin parameters. Note that the pin index is controller
     * local index.
     */
    void (*config)(const struct pinctrl *pinctrl, unsigned int pin,
                   pinctrl_config_e config, unsigned int value);
} pinctrl_ops_t;

/**
 * @brief Common pinctrl device structure.
 */
typedef struct pinctrl {
    /* Range of SOC pins controlled by this device. */
    const unsigned int    pin_start;
    const unsigned int    pin_nr;

    /* hardware device structure, used by drivers. */
    const void            *dev;
    pinctrl_ops_t   *ops;
} pinctrl_t;

/**
 * @brief This function returns TRUE if the SOC pin is controlled by
 *        specified pinctrl device.
 *
 * @param[in] pinctrl The pinctrl device.
 * @param[in] soc_pin SOC pin index.
 */
static inline boolean is_ctrl_pin(const pinctrl_t *pinctrl, unsigned int soc_pin)
{
    return soc_pin >= pinctrl->pin_start &&
           soc_pin < pinctrl->pin_start + pinctrl->pin_nr;
}

/**
 * @brief Convert pinctrl local pin index to SOC pin index.
 *
 * @param[in] pinctrl The pinctrl device.
 * @param[in] ctrl_pin Controller local pin index.
 */
static inline unsigned int
to_soc_pin(const struct pinctrl *pinctrl, unsigned int ctrl_pin)
{
    return pinctrl->pin_start + ctrl_pin;
}

/**
 * @brief Convert SOC pin index to pinctl local pin index.
 *
 * @param[in] pinctrl The pinctrl device.
 * @param[in] soc_pin SOC pin index.
 */
static inline unsigned int
to_ctrl_pin(const struct pinctrl *pinctrl, unsigned int soc_pin)
{
    return soc_pin - pinctrl->pin_start;
}

/**
 * @brief Initialize the pinctrl device.
 *
 * @param[in] pinctrl Pinctrl device which controls the pin.
 */
static inline void pinctrl_init(const pinctrl_t *pinctrl)
{
    ASSERT(pinctrl && pinctrl->ops && pinctrl->ops->init);
    pinctrl->ops->init(pinctrl);
}

/**
 * @brief De-initialize the pinctrl device.
 *
 * @param[in] pinctrl Pinctrl device which controls the pin.
 */
static inline void pinctrl_deinit(const pinctrl_t *pinctrl)
{
    ASSERT(pinctrl && pinctrl->ops && pinctrl->ops->deinit);
    pinctrl->ops->deinit(pinctrl);
}

/**
 * @brief Configure pin.
 *
 * @param[in] pinctrl Pinctrl device which controls the pin.
 * @param[in] pin SOC pin index.
 * @param[in] config Configuration type.
 * @param[in] value Configuration value, depending on config type.
 */
static inline void pinctrl_config(const struct pinctrl *pinctrl, unsigned int pin,
                                  pinctrl_config_e config, unsigned int value)
{
    ASSERT(pinctrl && pinctrl->ops && pinctrl->ops->config);
    ASSERT(is_ctrl_pin(pinctrl, pin));
    pinctrl->ops->config(pinctrl, to_ctrl_pin(pinctrl, pin), config, value);
}

#ifdef __cplusplus
}
#endif

#endif /* PINCTRL_H_ */
