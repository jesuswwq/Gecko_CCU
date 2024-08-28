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
 * @file  e3_adc.h
 * @brief Semidrive. adc
 */

#ifndef E3_ADC_H_
#define E3_ADC_H_

#ifdef __cplusplus
extern "C" {
#endif

#define ADC_MAX_CHANNEL_NUM (1<<9)

#include "__adc.h"

#define ADC_CH_POLAR_POS        1u
#define ADC_CH_POLAR_NEG        0u

/* Single Mode */
#define ADC_CH_SEL_E3(ch, polar, mux)                              \
            ((((mux) & 0x7u) << 6) | (((polar) & 0x1u) << 3) | ((ch) & 0x7u))
/* Differential Mode */
#define ADC_DCH_SEL_E3(ch_p, ch_n, mux)                            \
            ((((mux) & 0x7u) << 6) | (((ch_p) & 0x7u) << 3) | ((ch_n) & 0x7u))


enum adc1_ch5n_mux {
    ADC1_CH5N_MUX_A0 = 0u,
    ADC1_CH5N_MUX_A2,
    ADC1_CH5N_MUX_A4,
    ADC1_CH5N_MUX_A6,
    ADC1_CH5N_MUX_A8,
    ADC1_CH5N_MUX_A10,
    ADC1_CH5N_MUX_A12,
    ADC1_CH5N_MUX_A14
};

enum adc1_ch5p_mux {
    ADC1_CH5P_MUX_A1 = 0u,
    ADC1_CH5P_MUX_A3,
    ADC1_CH5P_MUX_A5,
    ADC1_CH5P_MUX_A7,
    ADC1_CH5P_MUX_A9,
    ADC1_CH5P_MUX_A11,
    ADC1_CH5P_MUX_A13,
    ADC1_CH5P_MUX_A15
};

enum adc2_ch4n_mux {
    ADC2_CH4N_MUX_A0 = 0u,
    ADC2_CH4N_MUX_A2,
    ADC2_CH4N_MUX_A4,
    ADC2_CH4N_MUX_A6,
    ADC2_CH4N_MUX_A8,
    ADC2_CH4N_MUX_A10,
    ADC2_CH4N_MUX_A12,
    ADC2_CH4N_MUX_A14
};

enum adc2_ch4p_mux {
    ADC2_CH4P_MUX_A1 = 0u,
    ADC2_CH4P_MUX_A3,
    ADC2_CH4P_MUX_A5,
    ADC2_CH4P_MUX_A7,
    ADC2_CH4P_MUX_A9,
    ADC2_CH4P_MUX_A11,
    ADC2_CH4P_MUX_A13,
    ADC2_CH4P_MUX_A15
};

enum adc2_ch5n_mux {
    ADC2_CH5N_MUX_C0 = 0u,
    ADC2_CH5N_MUX_C2,
    ADC2_CH5N_MUX_C4,
    ADC2_CH5N_MUX_C6,
    ADC2_CH5N_MUX_C8,
    ADC2_CH5N_MUX_C10,
    ADC2_CH5N_MUX_C12,
    ADC2_CH5N_MUX_C14
};

enum adc2_ch5p_mux {
    ADC2_CH5P_MUX_C1 = 0u,
    ADC2_CH5P_MUX_C3,
    ADC2_CH5P_MUX_C5,
    ADC2_CH5P_MUX_C7,
    ADC2_CH5P_MUX_C9,
    ADC2_CH5P_MUX_C11,
    ADC2_CH5P_MUX_C13,
    ADC2_CH5P_MUX_C15
};

enum adc2_ch6n_mux {
    ADC2_CH6N_MUX_B8 = 0u,
    ADC2_CH6N_MUX_B9,
    ADC2_CH6N_MUX_B10,
    ADC2_CH6N_MUX_B11,
    ADC2_CH6N_MUX_B12,
    ADC2_CH6N_MUX_B13,
    ADC2_CH6N_MUX_B14,
    ADC2_CH6N_MUX_B15
};

enum adc3_ch5n_mux {
    ADC3_CH5N_MUX_C0 = 0u,
    ADC3_CH5N_MUX_C2,
    ADC3_CH5N_MUX_C4,
    ADC3_CH5N_MUX_C6,
    ADC3_CH5N_MUX_C8,
    ADC3_CH5N_MUX_C10,
    ADC3_CH5N_MUX_C12,
    ADC3_CH5N_MUX_C14
};

enum adc3_ch5p_mux {
    ADC3_CH5P_MUX_C1 = 0u,
    ADC3_CH5P_MUX_C3,
    ADC3_CH5P_MUX_C5,
    ADC3_CH5P_MUX_C7,
    ADC3_CH5P_MUX_C9,
    ADC3_CH5P_MUX_C11,
    ADC3_CH5P_MUX_C13,
    ADC3_CH5P_MUX_C15
};


int e3_adc_probe(adc_dev_t *device, const adc_config_t *cfg);

#ifdef __cplusplus
}
#endif

#endif /* _ADC_H */

