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

#include "e3_kick_core.h"
#include <arch.h>
#include <RegBase.h>
#include <Mcu_Scr.h>
#include <Mcu_ScrBits.h>
#include <Mcu_Ckgen.h>
#include <Mcu_Soc.h>
#include <RegHelper.h>
#include "reset.h"
#include "Mcu_Reset.h"


#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

#define scr_bit_set(signal_name)                                   \
        do{                                                        \
            scr_signal_t signal_scr_##signal_name = signal_name;  \
            Mcu_ScrSetBit(&signal_scr_##signal_name,1);            \
        }while(0);

#define scr_bit_clr(signal_name)                                   \
        do{                                                        \
            scr_signal_t signal_scr_##signal_name = signal_name;  \
            Mcu_ScrSetBit(&signal_scr_##signal_name,0);            \
        }while(0);

#define scr_bits_wr(signal_name,val)                               \
        do{                                                        \
            scr_signal_t signal_scr_##signal_name = signal_name;  \
            Mcu_ScrSetBit(&signal_scr_##signal_name,val);           \
        }while(0);

static void soc_remap_to_zero(uint32 addr)
{
    /* actually, the remapping been enabled by a register bit in ROMC. */
    addr = addr >> 12;

    scr_bits_wr(SCR_SF_REMAP_CR5_SF_AR_ADDR_OFFSET_19_0, addr);

    scr_bits_wr(SCR_SF_REMAP_CR5_SF_AW_ADDR_OFFSET_19_0, addr);

    scr_bit_set(SCR_SF_SCR_REMAP_CR5_SF_REMAP_EN);

    dsb();
    isb();
}

static void soc_remap_core_vbar(kick_core_e_t core, uint32 addr)
{
    if (core == KICK_CR5_SF) {
        soc_remap_to_zero(addr);
    }

#ifndef SEMIDRIVE_E3_LITE_SERIES
    else if (KICK_CR5_SP0 == core || KICK_CR5_SP == core) {
        addr = addr >> 12;
        scr_bits_wr(SCR_SF_REMAP_CR5_SP_AR0_ADDR_OFFSET_19_0, addr);
        scr_bit_set(SCR_SF_REMAP_CR5_SP_AR0_REMAP_EN);
        scr_bits_wr(SCR_SF_REMAP_CR5_SP_AW0_ADDR_OFFSET_19_0, addr);
        scr_bit_set(SCR_SF_REMAP_CR5_SP_AW0_REMAP_EN);
    } else if (KICK_CR5_SP1 == core) {
        addr = addr >> 12;
        scr_bits_wr(SCR_SF_REMAP_CR5_SP_AR1_ADDR_OFFSET_19_0, addr);
        scr_bit_set(SCR_SF_REMAP_CR5_SP_AR1_REMAP_EN);
        scr_bits_wr(SCR_SF_REMAP_CR5_SP_AW1_ADDR_OFFSET_19_0, addr);
        scr_bit_set(SCR_SF_REMAP_CR5_SP_AW1_REMAP_EN);
    } else if (KICK_CR5_SX0 == core || KICK_CR5_SX == core) {
        addr = addr >> 12;
        scr_bits_wr(SCR_SF_REMAP_CR5_SX_AR0_ADDR_OFFSET_19_0, addr);
        scr_bit_set(SCR_SF_REMAP_CR5_SX_AR0_REMAP_EN);
        scr_bits_wr(SCR_SF_REMAP_CR5_SX_AW0_ADDR_OFFSET_19_0, addr);
        scr_bit_set(SCR_SF_REMAP_CR5_SX_AW0_REMAP_EN);
    } else if (KICK_CR5_SX1 == core) {
        addr = addr >> 12;
        scr_bits_wr(SCR_SF_REMAP_CR5_SX_AR1_ADDR_OFFSET_19_0, addr);
        scr_bit_set(SCR_SF_REMAP_CR5_SX_AR1_REMAP_EN);
        scr_bits_wr(SCR_SF_REMAP_CR5_SX_AW1_ADDR_OFFSET_19_0, addr);
        scr_bit_set(SCR_SF_REMAP_CR5_SX_AW1_REMAP_EN);
    }

#endif
}

static void ramfunc_romfix_set_sticky_bit(uint32 pos)
{
    uint32 b = APB_IROMC_BASE;
    /*to avoid calling func in ROM */
    uint32 v = readl(b + STICKY_REG_OFF);
    v |= (0x01u << pos);
    writel(v, b + STICKY_REG_OFF);
}

void soc_kick_core(kick_core_e_t core, uint32 entry)
{
    /*
        SP0 and SP1, you cannot kick SP1 without kicking SP0,
        SX0 and SX1, you cannot kick SX1 without kicking SX0,
        violating the above rules will result in an undefined exception.
    */
    soc_remap_core_vbar(core, entry);
#ifndef SEMIDRIVE_E3_LITE_SERIES

    /* cores are in lockstep mode by default */
    if ((KICK_CR5_SX0 == core) || (KICK_CR5_SX1 == core)) {
        scr_bit_set(SCR_SF_SCR_CR5_SX_LS_DISABLE);
        scr_bit_set(SCR_SF_SCR_CR5_SX_SLCLAMP_DISABLE);
        scr_bit_set(SCR_SF_VIC3_IS_LOCKSTEP_MODE_P);
    } else if ((KICK_CR5_SP0 == core) || (KICK_CR5_SP1 == core)) {
        scr_bit_set(SCR_SF_SCR_CR5_SP_LS_DISABLE);
        scr_bit_set(SCR_SF_SCR_CR5_SP_SLCLAMP_DISABLE);
        scr_bit_set(SCR_SF_VIC2_IS_LOCKSTEP_MODE_P);
    } else if (KICK_CR5_SX == core) {
        /* disable cr5_sx_dccm before issue a reset */
        scr_bit_clr(SCR_SF_CR5_SX_DCCMINP_0);
        scr_bit_clr(SCR_SF_CR5_SX_DCCMINP2_0);
        scr_bit_clr(SCR_SF_SCR_CR5_SX_LS_DISABLE);
        scr_bit_clr(SCR_SF_SCR_CR5_SX_SLCLAMP_DISABLE);
        scr_bit_clr(SCR_SF_VIC3_IS_LOCKSTEP_MODE_P);
    } else if (KICK_CR5_SP == core) {
        scr_bit_clr(SCR_SF_CR5_SP_DCCMINP_0);
        scr_bit_clr(SCR_SF_CR5_SP_DCCMINP2_0);
        scr_bit_clr(SCR_SF_SCR_CR5_SP_LS_DISABLE);
        scr_bit_clr(SCR_SF_SCR_CR5_SP_SLCLAMP_DISABLE);
        scr_bit_clr(SCR_SF_VIC2_IS_LOCKSTEP_MODE_P);
    }

    if (KICK_CR5_SX0 == core || KICK_CR5_SX == core) {
        reset_ctl_reset(&rstsig_cr5_sx0);
    } else if (KICK_CR5_SX1 == core) {
        reset_ctl_reset(&rstsig_cr5_sx1);
    } else if (KICK_CR5_SP0 == core || KICK_CR5_SP == core) {
        ckgen_bus_slice_cfg(APB_CKGEN_SF_BASE,
                            SLICE_ID(1), SLICE_SRC(4), DIV(0), 0);
        reset_ctl_reset(&rstsig_cr5_sp0);
    } else if (KICK_CR5_SP1 == core) {
        reset_ctl_reset(&rstsig_cr5_sp1);
    } else if (KICK_CR5_SF == core) {
        ramfunc_romfix_set_sticky_bit(BP_ROMC_STICKY_REMAP_EN);
        /* disable cr5_sf_dccm before issue a reset */
        scr_bit_clr(SCR_SF_SCR_CR5_SF_DCCMINP_0);
        reset_ctl_reset(&rstsig_cr5_saf);
    }

#else

    if (KICK_CR5_SF == core) {
        ramfunc_romfix_set_sticky_bit(BP_ROMC_STICKY_REMAP_EN);
        /* disable cr5_sf_dccm before issue a reset */
        scr_bit_clr(SCR_SF_SCR_CR5_SF_DCCMINP_0);
        reset_ctl_reset(&rstsig_cr5_saf);
    }

#endif
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
