
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

#include "__regs_base.h"
#include "Port_Hw_PinCtrl.h"
#include "Port_Hw_E3.h"
#include "Port_Hw_E3_PinCtrl.h"
#include "Dio_IP.h"
#include "Port.h"
#include "RegHelper.h"

extern pinctrl_ops_t taishan_pinctrl_ops;

#define PORT_START_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

static const taishan_pinctrl_t pinctrl_safety_dev = {
    .base            = APB_IOMUXC_SF_BASE,
    .pad_reg_offset  = TAISHAN_PAD_CONFIG_REG_OFFSET,
    .mux_reg_offset  = TAISHAN_MUX_CONFIG_REG_OFFSET,
};
#ifndef SEMIDRIVE_E3_LITE_SERIES
static const taishan_pinctrl_t pinctrl_ap_dev = {
    .base            = APB_IOMUXC_AP_BASE,
    .pad_reg_offset  = TAISHAN_PAD_CONFIG_REG_OFFSET,
    .mux_reg_offset  = TAISHAN_MUX_CONFIG_REG_OFFSET,
};
#endif
const pinctrl_t g_pinctrl_safety = {
    .pin_start = TAISHAN_SAFETY_PIN_START,
    .pin_nr = TAISHAN_SAFETY_PIN_NUM,
    .dev = &pinctrl_safety_dev,
    .ops = &taishan_pinctrl_ops,
};
#ifndef SEMIDRIVE_E3_LITE_SERIES
const pinctrl_t g_pinctrl_ap = {
    .pin_start = TAISHAN_AP_PIN_START,
    .pin_nr = TAISHAN_AP_PIN_NUM,
    .dev = &pinctrl_ap_dev,
    .ops = &taishan_pinctrl_ops,
};
#endif

/* SCR register information. */

#define SCR_ETH1_COMP_PAD(id) SCR_SF_SCR_ETH1_CAP_COMP_##id##_OE

#define SCR_ETH2_COMP_PAD(id) SCR_SF_SCR_ETH2_CAP_COMP_##id##_OE

#if (PORT_ETHCOMP_PIN_ENABLE == STD_ON)
static const scr_signal_t g_ETH1_apad_scr[] = {
    SCR_ETH1_COMP_PAD(0), SCR_ETH1_COMP_PAD(1), SCR_ETH1_COMP_PAD(2), SCR_ETH1_COMP_PAD(3),
};
static const scr_signal_t g_ETH2_apad_scr[] = {
    SCR_ETH2_COMP_PAD(0), SCR_ETH2_COMP_PAD(1), SCR_ETH2_COMP_PAD(2), SCR_ETH2_COMP_PAD(3),
};
#endif

#define SCR_ANALOG_PAD(id) \
    {GPIO_##id, SCR_SF_ANA_SF_CFG_APD_A_##id##_CTRL_3_0}

#if (PORT_ANALOG_PIN_ENABLE == STD_ON)
static const taishan_analog_pinctrl_t g_adc_apad_scr[] = {
    SCR_ANALOG_PAD(A0),  SCR_ANALOG_PAD(A1),  SCR_ANALOG_PAD(A2),  SCR_ANALOG_PAD(A3),
    SCR_ANALOG_PAD(A4),  SCR_ANALOG_PAD(A5),  SCR_ANALOG_PAD(A6),  SCR_ANALOG_PAD(A7),
    SCR_ANALOG_PAD(A8),  SCR_ANALOG_PAD(A9),  SCR_ANALOG_PAD(A10), SCR_ANALOG_PAD(A11),
    SCR_ANALOG_PAD(A12), SCR_ANALOG_PAD(A13), SCR_ANALOG_PAD(A14), SCR_ANALOG_PAD(A15),
    SCR_ANALOG_PAD(B0),  SCR_ANALOG_PAD(B1),  SCR_ANALOG_PAD(B2),  SCR_ANALOG_PAD(B3),
    SCR_ANALOG_PAD(B4),  SCR_ANALOG_PAD(B5),  SCR_ANALOG_PAD(B6),  SCR_ANALOG_PAD(B7),
    SCR_ANALOG_PAD(B8),  SCR_ANALOG_PAD(B9),  SCR_ANALOG_PAD(B10), SCR_ANALOG_PAD(B11),
    SCR_ANALOG_PAD(B12), SCR_ANALOG_PAD(B13), SCR_ANALOG_PAD(B14), SCR_ANALOG_PAD(B15),
    SCR_ANALOG_PAD(C0),  SCR_ANALOG_PAD(C1),  SCR_ANALOG_PAD(C2),  SCR_ANALOG_PAD(C3),
    SCR_ANALOG_PAD(C4),  SCR_ANALOG_PAD(C5),  SCR_ANALOG_PAD(C6),  SCR_ANALOG_PAD(C7),
#ifndef SEMIDRIVE_E3_LITE_SERIES
    SCR_ANALOG_PAD(C8),  SCR_ANALOG_PAD(C9),  SCR_ANALOG_PAD(C10), SCR_ANALOG_PAD(C11),
    SCR_ANALOG_PAD(C12), SCR_ANALOG_PAD(C13), SCR_ANALOG_PAD(C14), SCR_ANALOG_PAD(C15),
#endif
};
#endif

#define PORT_STOP_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

#define PORT_START_SEC_CODE
#include "Port_MemMap.h"

void Port_Hw_Init(const pin_settings_config_t *settings, const unsigned int num)
{
    ASSERT(settings != NULL_PTR);

    for (unsigned int i = 0; i < num; i++) {
        const pin_settings_config_t *config = &settings[i];
#ifndef SEMIDRIVE_E3_LITE_SERIES
        const pinctrl_t *pinctrl = (config->pin_index < TAISHAN_SAFETY_PIN_NUM) ? &g_pinctrl_safety :
                                   &g_pinctrl_ap;
#else
        const pinctrl_t *pinctrl = &g_pinctrl_safety;
#endif
        pinctrl_config(pinctrl, config->pin_index, PINCTRL_CONFIG_FUNCTION, config->mux);
        pinctrl_config(pinctrl, config->pin_index, PINCTRL_CONFIG_DRIVE, config->open_drain);
        pinctrl_config(pinctrl, config->pin_index, PINCTRL_CONFIG_PULL, config->pull_config);
        pinctrl_config(pinctrl, config->pin_index, PINCTRL_CONFIG_DRIVE_STRENGTH, config->drive_strength);
        pinctrl_config(pinctrl, config->pin_index, PINCTRL_CONFIG_SLEW_RATE, config->slew_rate);
        pinctrl_config(pinctrl, config->pin_index, PINCTRL_CONFIG_INPUT_SCHMITT, config->input_select);
        pinctrl_config(pinctrl, config->pin_index, PINCTRL_CONFIG_FORCE_INPUT, config->force_input);

        /*set bit20 to 0 when GPIO A/B/C used as digital,
        if use default 1, will cause a partial voltage on the pin and deviate from the actual voltage*/
#ifndef SEMIDRIVE_E3_LITE_SERIES

        if ((config->pin_index >= GPIO_A0) && (config->pin_index <= GPIO_C15))
#else
        if ((config->pin_index >= GPIO_A0) && (config->pin_index <= GPIO_C7))
#endif
        {
            pinctrl_config(pinctrl, config->pin_index, PINCTRL_CONFIG_MODE_SELECT, 0u);
        }


        if (config->mux == PIN_MUX_ALT0) {

            if (config->data_direction == PIN_OUTPUT_DIRECTION) {
                Dio_Ip_WriteChannel((uint16)config->pin_index, config->initial_value);
            }

#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
            Dio_Ip_SetPinDirection((uint16)config->pin_index, (Dio_DirectionType)(config->data_direction));
#endif

#if (PORT_EN_PIN_INT_API == STD_ON)

            if ((config->data_direction == PIN_INPUT_DIRECTION)) {
                if ( PIN_INTERRUPT_DISABLED != config->interrupt_config) {
                    if (config->interrupt_config <= PIN_INTERRUPT_BOTH_EDGE) {
                        Dio_Ip_EnablePinInterruptDetect((uint16)config->pin_index, config->interrupt_config);
                    } else {
                        Dio_Ip_EnableAsyncInterruptDetect((uint16)config->pin_index,
                                                          (config->interrupt_config - PIN_INTERRUPT_BOTH_EDGE));
                    }
                }
            }

#endif

        }
    }
}
#if (PORT_ETHCOMP_PIN_ENABLE == STD_ON)
void Port_Ip_ETHCOMPPadSet(void)
{
   uint32 pin;
   /* enable ETHCOMP input */
   for (uint8 i = 0; i < NUM_OF_ETHCOMP_PINS; i++) {
        pin = g_pin_ETHCOMP_config[i].pin_index;
        if((pin >= GPIO_Y4) && (pin <= GPIO_Y7))
        {
            pin = pin - GPIO_Y4;
            Mcu_ScrSetBit(&g_ETH1_apad_scr[pin],1);
        }
        else if(pin == GPIO_G6)
        {
            pin = pin - GPIO_G6;
            Mcu_ScrSetBit(&g_ETH1_apad_scr[pin],1);
        }
        else if((pin >= GPIO_C8) && (pin <= GPIO_C11))
        {
            pin = pin - GPIO_C8;
            Mcu_ScrSetBit(&g_ETH2_apad_scr[pin],1);
        }
        else if(pin == GPIO_M6)
        {
            pin = pin - GPIO_M6;
            Mcu_ScrSetBit(&g_ETH2_apad_scr[pin],1);
        }

   }
}
#endif
#if (PORT_ANALOG_PIN_ENABLE == STD_ON)
void Port_Ip_AnalogPadInit(void)
{
    uint32 pin;

    for (uint8 i = 0; i < NUM_OF_ANALOG_PINS; i++) {
        pin = g_pin_analog_config[i].pin_index;
#ifndef SEMIDRIVE_E3_LITE_SERIES

        if ((pin >= GPIO_A0) && (pin <= GPIO_C15))
#else
        if ((pin >= GPIO_A0) && (pin <= GPIO_C7))
#endif
        {
            /* analog input 3v3 or 5v */
            pinctrl_config(&g_pinctrl_safety, pin, PINCTRL_CONFIG_MODE_SELECT,
                           g_pin_analog_config[i].input_level);

            pin = g_pin_analog_config[i].pin_index - GPIO_A0;
            /* enable analog input */
            Mcu_ScrSetBit(&g_adc_apad_scr[pin].scrbit, 1);
        }
    }
}
#endif

#if (PORT_RELEASE_DISPLAY_PIN == STD_ON)
#ifndef SEMIDRIVE_E3_LITE_SERIES
void Port_Ip_DispalyPadRelease(void)
{
    /* display mux need clr rterm_en if GPIOLx is not used for display */
    uint32 reg;

    for (uint32 i = 0; i < 5; i++) {
        reg = readl(APB_DISP_MUX_BASE + 0x1010 + i * 4);
        reg &= (uint32)(~0x2);
        writel(reg, APB_DISP_MUX_BASE + 0x1010 + i * 4);
    }
}
#endif
#endif

FUNC(void, PORT_CODE) Port_Ip_SetPinMode
(
    VAR(Port_PinType,           AUTOMATIC) Pin,
    VAR(Port_PinModeType,     AUTOMATIC) Mode
)
{
#ifndef SEMIDRIVE_E3_LITE_SERIES
    const pinctrl_t *pinctrl = (Pin < TAISHAN_SAFETY_PIN_NUM) ? &g_pinctrl_safety :
                               &g_pinctrl_ap;
#else
    const pinctrl_t *pinctrl = &g_pinctrl_safety;
#endif
    /* pad setting */
    pinctrl_config(pinctrl, Pin, PINCTRL_CONFIG_FUNCTION, Mode);
}

FUNC(void, PORT_CODE) Port_Ip_RefreshPinConfig
(
    VAR(Port_PinType,           AUTOMATIC) Pin,
    P2VAR(Port_PinConfigType, AUTOMATIC, PORT_APPL_CONST)Mode
)
{
#ifndef SEMIDRIVE_E3_LITE_SERIES
    const pinctrl_t *pinctrl = (Pin < TAISHAN_SAFETY_PIN_NUM) ? &g_pinctrl_safety :
                               &g_pinctrl_ap;
#else
    const pinctrl_t *pinctrl = &g_pinctrl_safety;
#endif
    /* pad setting */
    pinctrl_config(pinctrl, Pin, PINCTRL_CONFIG_FUNCTION, Mode->mux);
    pinctrl_config(pinctrl, Pin, PINCTRL_CONFIG_DRIVE, Mode->open_drain);
    pinctrl_config(pinctrl, Pin, PINCTRL_CONFIG_PULL, Mode->pull_config);
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)

    /* gpio setting */
    if (Mode->mux == PIN_MUX_ALT0) {

        Dio_Ip_SetPinDirection(Pin, (Dio_DirectionType)(Mode->data_direction));
    }

#endif
}

FUNC(void, PORT_CODE) Port_Ip_SetPinDirection
(
    VAR(Port_PinType,              AUTOMATIC) Pin,
    VAR(Port_PinDirectionType,   AUTOMATIC) Direction
)
{
    Dio_Ip_SetPinDirection(Pin, (Dio_DirectionType)Direction);
}

#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"

#ifdef __cplusplus
}
#endif
