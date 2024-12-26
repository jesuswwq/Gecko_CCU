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

#ifndef TAISHAN_PINCTRL_LLD_H_
#define TAISHAN_PINCTRL_LLD_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "RegHelper.h"

static inline unsigned long pin_reg(unsigned long base, uint32 offset, uint32 pin)
{
    return base + offset + pin * 4;
}

static inline void write_pin_reg(unsigned long base, uint32 offset,
                                 uint32 pin, uint32 val)
{
    writel(val, pin_reg(base, offset, pin));
}

static inline uint32 read_pin_reg(unsigned long base, uint32 offset, uint32 pin)
{
    return readl(pin_reg(base, offset, pin));
}

static inline void modify_pin_reg(unsigned long base, uint32 offset, uint32 pin,
                                  uint32 bit, uint32 width, uint32 val)
{
    uint32 v = read_pin_reg(base, offset, pin);
    v &= ~(BIT_MASK(width) << bit);
    v |= (val & BIT_MASK(width)) << bit;
    write_pin_reg(base, offset, pin, v);
}

static inline void
taishan_pinctrl_set_function(unsigned long base, uint32 offset, unsigned int pin,
                             unsigned int value)
{
    if ((int)value >= MUX_FUNC_GPIO && value <= MUX_FUNC_ALT9) {
        modify_pin_reg(base, offset, pin, MUX_FUNC_SHIFT,
                       MUX_FUNC_WIDTH, value);
    }
}

static inline void
taishan_pinctrl_set_drive(unsigned long base, uint32 offset, unsigned int pin,
                          unsigned int value)
{
    modify_pin_reg(base, offset, pin, MUX_ODE_SHIFT, MUX_ODE_WIDTH, value);
}

static inline void
taishan_pinctrl_set_pull_gpio(unsigned long base, uint32 offset, unsigned int pin,
                              unsigned int value)
{
    modify_pin_reg(base, offset, pin, PAD_PULL_SHIFT, PAD_PULL_WIDTH, value);
}

static inline void
taishan_pinctrl_set_drive_strength_gpio(unsigned long base, uint32 offset,
                                        unsigned int pin, unsigned int value)
{
    modify_pin_reg(base, offset, pin, PAD_DS_SHIFT, PAD_DS_WIDTH, value);
}

static inline void
taishan_pinctrl_set_input_schmitt_gpio(unsigned long base, uint32 offset,
                                       unsigned int pin, unsigned int value)
{
    modify_pin_reg(base, offset, pin, PAD_IS_SHIFT, PAD_IS_WIDTH, value);
}

static inline void
taishan_pinctrl_set_slew_rate_gpio(unsigned long base, uint32 offset,
                                   unsigned int pin, unsigned int value)
{
    modify_pin_reg(base, offset, pin, PAD_SR_SHIFT, PAD_SR_WIDTH, value);
}

static inline void
taishan_pinctrl_set_force_input(unsigned long base, uint32 offset, unsigned int pin,
                                unsigned int fin, unsigned int fv)
{
    modify_pin_reg(base, offset, pin, MUX_FIN_SHIFT, MUX_FIN_WIDTH, fin);
    modify_pin_reg(base, offset, pin, MUX_FV_SHIFT, MUX_FV_WIDTH, fv);
}

static inline void
taishan_pinctrl_set_mode_select_gpio(unsigned long base, uint32 offset,
                                     unsigned int pin, unsigned int value)
{
    modify_pin_reg(base, offset, pin, PAD_MS_SHIFT, PAD_MS_WIDTH, value);
}

#endif /* TAISHAN_PINCTRL_LLD_H_ */

#ifdef __cplusplus
}
#endif