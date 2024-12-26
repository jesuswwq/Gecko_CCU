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


#if defined(CFG_MULTI_CORE_OS)

#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

const uint32 scr_rbase[] = {APB_SCR_SEC_BASE, APB_SCR_SAF_BASE};
const uint32 romc_rbase[] = {APB_ROMC2_BASE, APB_ROMC1_BASE};
const uint32 rstgen_rbase[] = {APB_RSTGEN_SEC_BASE, APB_RSTGEN_SAF_BASE};
const uint32 iram_base[] = {IRAM2_BASE, IRAM1_BASE};
const uint32 cr5_core_rst_idx[] = {
    RSTGEN_SEC_CORE_RST_B_CR5_SEC_INDEX,
    RSTGEN_SAF_CORE_RST_B_CR5_SAF_INDEX,
};
const uint32 cr5_remap_ar_off_start_bit[] = {
    SCR_SEC_REMAP_CR5_SEC_AR_ADDR_OFFSET_19_0_L31_START_BIT,
    SCR_SAF_REMAP_CR5_SAF_AR_ADDR_OFFSET_19_0_L31_START_BIT,
};
const uint32 cr5_remap_ovrd_en[] = {
    SCR_SEC_REMAP_CR5_SEC_AR_REMAP_OVRD_EN_L31_START_BIT,
    SCR_SAF_REMAP_CR5_SAF_AR_REMAP_OVRD_EN_L31_START_BIT,
};

#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

#endif
