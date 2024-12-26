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

#include "Port_Hw_PinCtrl.h"
#include "Port_Hw_E3_PinCtrl.h"
#include "Port_Hw_E3_PinCtrl_lld.h"

#define PINCTRL_IS_IDX(pin, mux)   (((pin) << 8) + (mux))
extern const taishan_input_select_t taishan_pinctrl_is[TAISHAN_INPUT_SELECT_NUM];

#define PORT_START_SEC_CODE
#include "Port_MemMap.h"

static void taishan_set_input_select_reg(uint32 pin, uint32 mux)
{
    int left = 0;
    int right = TAISHAN_INPUT_SELECT_NUM - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        taishan_input_select_t *select = (taishan_input_select_t *)&taishan_pinctrl_is[mid];

        if (PINCTRL_IS_IDX(select->pin, select->mux) == PINCTRL_IS_IDX(pin, mux)) {
            writel(select->value, select->base + select->offset);
            break;
        } else if (PINCTRL_IS_IDX(select->pin, select->mux) > PINCTRL_IS_IDX(pin, mux)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
}

static void taishan_pinctrl_initialize(const pinctrl_t *pinctrl)
{
    ASSERT(pinctrl != NULL_PTR);
    const taishan_pinctrl_t *ctrl = pinctrl->dev;
    ASSERT(ctrl);
}

static void taishan_pinctrl_config(const pinctrl_t *pinctrl, unsigned int pin,
                                   pinctrl_config_e config, unsigned int value)
{
    ASSERT(pinctrl != NULL_PTR);
    const taishan_pinctrl_t *ctrl = pinctrl->dev;
    unsigned int soc_pin;

    ASSERT(ctrl);
    ASSERT(config < PINCTRL_CONFIG_MAX);

    soc_pin = to_soc_pin(pinctrl, pin);

    if (soc_pin < TAISHAN_SAFETY_PIN_NUM) {
        pin++;
    }

    switch (config) {
    case PINCTRL_CONFIG_FUNCTION:
        /* The controller must have MUX function. */
        ASSERT(ctrl->mux_reg_offset);
        ASSERT((int)value >= MUX_FUNC_GPIO && value <= MUX_FUNC_ALT9);

        taishan_set_input_select_reg(soc_pin, value);
        taishan_pinctrl_set_function(ctrl->base, ctrl->mux_reg_offset,
                                     pin, value);
        break;

    case PINCTRL_CONFIG_DRIVE:
        /* The controller must have MUX function. */
        ASSERT(ctrl->mux_reg_offset);
        ASSERT(value == PINCTRL_DRIVE_OPEN_DRAIN ||
               value == PINCTRL_DRIVE_PUSH_PULL);

        if (value == PINCTRL_DRIVE_OPEN_DRAIN)
            value = MUX_ODE_OPENDRAIN;
        else
            value = MUX_ODE_PUSHPULL;

        taishan_pinctrl_set_drive(ctrl->base, ctrl->mux_reg_offset,
                                  pin, value);
        break;

    case PINCTRL_CONFIG_PULL:
        ASSERT((int)value >= PINCTRL_PULL_NOPULL && value <= PINCTRL_PULL_UP);

        if (value == PINCTRL_PULL_NOPULL)
            value = PAD_NOPULL;
        else if (value == PINCTRL_PULL_UP)
            value = PAD_PULLUP;
        else
            value = PAD_PULLDOWN;

        taishan_pinctrl_set_pull_gpio(ctrl->base, ctrl->pad_reg_offset,
                                      pin, value);
        break;

    case PINCTRL_CONFIG_DRIVE_STRENGTH:
        ASSERT((int)value >= PAD_DS_2mA && value <= PAD_DS_12mA);

        taishan_pinctrl_set_drive_strength_gpio(ctrl->base,
                                                ctrl->pad_reg_offset,
                                                pin, value);
        break;

    case PINCTRL_CONFIG_INPUT_SCHMITT:
        if (value == PINCTRL_INPUT_SCHMITT_DISABLE)
            value = PAD_IS_NORMAL;
        else if (value == PINCTRL_INPUT_SCHMITT_ENABLE)
            value = PAD_IS_SCHMITT;
        else
            ASSERT(FALSE);

        taishan_pinctrl_set_input_schmitt_gpio(ctrl->base,
                                               ctrl->pad_reg_offset,
                                               pin, value);
        break;

    case PINCTRL_CONFIG_SLEW_RATE:
        ASSERT(value == PAD_SR_FAST || value == PAD_SR_SLOW);
        taishan_pinctrl_set_slew_rate_gpio(ctrl->base,
                                           ctrl->pad_reg_offset,
                                           pin, value);
        break;

    case PINCTRL_CONFIG_FORCE_INPUT: {
        ASSERT(ctrl->mux_reg_offset);
        ASSERT((int)value >= PINCTRL_FORCE_INPUT_NORMAL && value <= PINCTRL_FORCE_INPUT_LOW);

        unsigned int fin = PAD_INPUT_FORCE_DISABLE;
        unsigned int fv = PAD_FORCE_INPUT_VALUE_0;

        if (value <= PINCTRL_FORCE_INPUT_ENABLE) {
            fin = value;
        } else if (value == PINCTRL_FORCE_INPUT_HIGH) {
            fv = PAD_FORCE_INPUT_VALUE_1;
        } else {
        }

        taishan_pinctrl_set_force_input(ctrl->base, ctrl->mux_reg_offset,
                                        pin, fin, fv);
    }
    break;

    case PINCTRL_CONFIG_MODE_SELECT:
        ASSERT(value == PAD_MS_LOW || value == PAD_MS_HIGH);
        taishan_pinctrl_set_mode_select_gpio(ctrl->base,
                                             ctrl->pad_reg_offset,
                                             pin, value);
        break;

    default:
        break;
    }

    return;
}

#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"

#define PORT_START_SEC_VAR_INIT_UNSPECIFIED
#include "Port_MemMap.h"

pinctrl_ops_t taishan_pinctrl_ops = {
    .init   = taishan_pinctrl_initialize,
    .config = taishan_pinctrl_config,
};

#define PORT_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Port_MemMap.h"

#define PORT_START_SEC_CODE
#include "Port_MemMap.h"

void taishan_pinctrl_init(pinctrl_t *pinctrl, const taishan_pinctrl_t *dev)
{
    ASSERT(pinctrl != NULL);
    pinctrl->dev = dev;
    pinctrl->ops = &taishan_pinctrl_ops;
    pinctrl_init(pinctrl);
}

#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"

#ifdef __cplusplus
}
#endif
