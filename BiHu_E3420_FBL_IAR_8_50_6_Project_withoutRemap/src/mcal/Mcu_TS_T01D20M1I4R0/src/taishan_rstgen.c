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

#include "RegHelper.h"
#include "taishan_rstgen.h"

#define RSTGEN_POLLs    0x10000

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

/**
 * @brief taishan rstgen init
 *
 * @param[in] base taishan rstgen address
 * @param[in] init_cfg value for global set
 */
void taishan_rstgen_lld_init(uint32 base, uint32 init_cfg)
{
    return;
}

/**
 * @brief taishan rstgen core control
 * Reset core processor.
 *
 * @param[in] base taishan rstgen address
 * @param[in] core_idx core index
 * @param[in] run_mode run mode bit
 */
sint32 taishan_rstgen_lld_core_control(uint32 base, uint32 core_idx, bool run_mode)
{
    uint32 tms = 0;
    uint32 core_rst_en = base + CORE_RESET_RS_OFF(core_idx);
    uint32 core_sw_rst = base + CORE_RESET_CONTROL_OFF(core_idx);

    /* Check the reset lock bit */
    if (readl(core_rst_en) & (0x1u << CORE_RESET_RS_LOCK))
        return -1;

    /* Set core sleep/hib mode. */
    RMWREG32(core_sw_rst, CORE_RESET_CONTROL_HIB_MODE, 1, run_mode);
    RMWREG32(core_sw_rst, CORE_RESET_CONTROL_SLP_MODE, 1, run_mode);


    /* Check core SW reset status */
    if (run_mode && (readl(core_sw_rst) & (0x1u << CORE_RESET_CONTROL_RSTA)))
        return 0;

    if (!run_mode && !(readl(core_sw_rst) & (0x1u << CORE_RESET_CONTROL_RSTA)))
        return 0;

    /* Set core run mode. */
    RMWREG32(core_sw_rst, CORE_RESET_CONTROL_RUN_MODE, 1, run_mode);

    /* Wait reset done. */
    while ((run_mode != ((readl(core_sw_rst) >> CORE_RESET_CONTROL_RSTA) & 0x1u))
           && tms++ < RSTGEN_POLLs);

    return 0;
}

/**
 * @brief taishan rstgen core reset
 * Reset core processor.
 *
 * @param[in] base taishan rstgen address
 * @param[in] core_idx core index
 */
sint32 taishan_rstgen_lld_core_reset(uint32 base, uint32 core_idx)
{
    uint32 tms = 0;
    uint32 core_rst = base + CORE_RESET_CONTROL_OFF(core_idx);

    uint32 val = readl(core_rst);

    if (val & (1 << CORE_RESET_CONTROL_RSTA)) {
        /* Auto clear reset when the core is already running */
        writel(val | (1 << CORE_RESET_CONTROL_AUTO_CLR_RST_B), core_rst);

        /* Trigger auto clear reset */
        while ((readl(core_rst) & (1 << CORE_RESET_CONTROL_AUTO_CLR_RST_B)) && tms++ < RSTGEN_POLLs);
    } else {
        /* Set running mode when the core is off */
        writel(val | (1 << CORE_RESET_CONTROL_RUN_MODE), core_rst);

        /* Trigger real time reset status */
        while (0 == (readl(core_rst) & (1 << CORE_RESET_CONTROL_RSTA)) && tms++ < RSTGEN_POLLs);
    }

    return 0;
}

/**
 * @brief taishan rstgen module control
 * Reset IP module.
 *
 * @param[in] base taishan rstgen address
 * @param[in] module_idx module index
 * @param[in] run_mode 0:module off, 1:module on
 */
sint32 taishan_rstgen_lld_module_control(uint32 base, uint32 module_idx, bool run_mode)
{
    uint32 tms = 0;
    uint32 module_rst = base + MODULE_RESET_CONTROL_OFF(module_idx);
    uint32 val = readl(module_rst);

    if (run_mode) {
        val |= 1 << MODULE_RESET_CONTROL_HIB_MODE;
        val |= 1 << MODULE_RESET_CONTROL_SLP_MODE;
        val |= 1 << MODULE_RESET_CONTROL_RUN_MODE;
    }
    else {
        val &= (uint32)(~(1 << MODULE_RESET_CONTROL_RUN_MODE));
        val &= (uint32)(~(1 << MODULE_RESET_CONTROL_HIB_MODE));
        val &= (uint32)(~(1 << MODULE_RESET_CONTROL_SLP_MODE));
    }

    writel(val, module_rst);

    if (run_mode)
        while ((!(readl(module_rst) & (0x1u << MODULE_RESET_CONTROL_RSTA))) && (tms++ < RSTGEN_POLLs));
    else
        while ((readl(module_rst) & (0x1u << MODULE_RESET_CONTROL_RSTA)) && (tms++ < RSTGEN_POLLs));

    return 0;
}

/**
 * @brief taishan rstgen mission control
 *
 * @param[in] base taishan rstgen address
 * @param[in] mission_idx mission index
 * @param[in] run_mode 0:misson off, 1:misson on
 */
sint32 taishan_rstgen_lld_mission_control(uint32 base, uint32 mission_idx, bool run_mode)
{
    uint32 tms = 0;
    uint32 mission_rst = base + MISSION_RESET_CONTROL_OFF(mission_idx);

    uint32 val = readl(mission_rst);

    if (run_mode) {
        val |= 1 << MISSION_RESET_CONTROL_HIB_MODE;
        val |= 1 << MISSION_RESET_CONTROL_SLP_MODE;
        val |= 1 << MISSION_RESET_CONTROL_RUN_MODE;
    }
    else {
        val &= (uint32)(~(1 << MISSION_RESET_CONTROL_HIB_MODE));
        val &= (uint32)(~(1 << MISSION_RESET_CONTROL_SLP_MODE));
        val &= (uint32)(~(1 << MISSION_RESET_CONTROL_RUN_MODE));
    }

    writel(val, mission_rst);

    if (run_mode) {
        while (!(readl(mission_rst) & (1 << MISSION_RESET_CONTROL_RSTA)) && (tms++ < RSTGEN_POLLs));
    } else {
        while ((readl(mission_rst) & (1 << MISSION_RESET_CONTROL_RSTA)) && (tms++ < RSTGEN_POLLs));
    }

    return 0;
}

/**
 * @brief taishan rstgen latent control
 *
 * @param[in] base taishan rstgen address
 * @param[in] latent_idx latent index
 * @param[in] run_mode 0:latent on, 1:latent off
 */
sint32 taishan_rstgen_lld_latent_control(uint32 base, uint32 latent_idx, bool run_mode)
{
    uint32 tms = 0;
    uint32 latent_rst = base + MISSION_RESET_CONTROL_OFF(latent_idx);

    uint32 val = readl(latent_rst);

    if (run_mode) {
        val |= 1 << LATENT_RESET_CONTROL_HIB_MODE;
        val |= 1 << LATENT_RESET_CONTROL_SLP_MODE;
        val |= 1 << LATENT_RESET_CONTROL_RUN_MODE;
    }
    else {
        val &= (uint32)(~(1 << LATENT_RESET_CONTROL_HIB_MODE));
        val &= (uint32)(~(1 << LATENT_RESET_CONTROL_SLP_MODE));
        val &= (uint32)(~(1 << LATENT_RESET_CONTROL_RUN_MODE));
    }

    writel(val, latent_rst);

    if (run_mode) {
        while (!(readl(latent_rst) & (1 << LATENT_RESET_CONTROL_RSTA)) && (tms++ < RSTGEN_POLLs));
    } else {
        while ((readl(latent_rst) & (1 << LATENT_RESET_CONTROL_RSTA)) && (tms++ < RSTGEN_POLLs));
    }

    return 0;
}

/**
 * @brief
 *
 * @param[in] sf_base taishan rstgen sf domain address
 * @param[in] ap_base taishan rstgen ap domain address
 */
void taishan_rstgen_lld_global_reset(uint32 sf_base)
{
    RMWREG32(sf_base + GLOBAL_RESET_CONTROL_OFF, GLOBAL_RESET_CONTROL_RST_REQ_EN, 1, 1);

    RMWREG32(sf_base + GLOBAL_RESET_CONTROL_OFF, GLOBAL_RESET_CONTROL_SW_GLB_RST_EN, 1, 1);

    RMWREG32(sf_base + GLOBAL_RESET_CONTROL_OFF, GLOBAL_RESET_CONTROL_SW_GLB_RST, 1, 1);
}

/**
 * @brief taishan rstgen get core reset status
 *
 * @param[in] base taishan rstgen address
 * @param[in] core_idx core index
 * @return 1, the core reset has be released.
 *         0, the core reset hasn't be released.
 */
sint32 taishan_rstgen_lld_get_core_reset_status(uint32 base, uint32 core_idx)
{
    uint32 core_rst = base + CORE_RESET_CONTROL_OFF(core_idx);

    return !!(readl(core_rst) & (0x1u << MODULE_RESET_CONTROL_RSTA));
}

/**
 * @brief taishan rstgen get module reset status
 *
 * @param[in] base taishan rstgen address
 * @param[in] module_idx module index
 * @return 1, the module reset has be released.
 *         0, the module reset hasn't be released.
 */
sint32 taishan_rstgen_lld_get_module_reset_status(uint32 base, uint32 module_idx)
{
    uint32 module_rst = base + MODULE_RESET_CONTROL_OFF(module_idx);

    /* RSTGEN_MODULE_RST_STA, 0 = reset, 1 = release. */
    return !!(readl(module_rst) & (0x1u << MODULE_RESET_CONTROL_RSTA));
}

/**
 * @brief taishan rstgen get mission reset status
 *
 * @param[in] base taishan rstgen address
 * @param[in] mission_idx mission index
 * @return 1, the mission reset has be released.
 *         0, the mission reset hasn't be released.
 */
sint32 taishan_rstgen_lld_get_mission_reset_status(uint32 base, uint32 mission_idx)
{
    uint32 mission_rst = base + MISSION_RESET_CONTROL_OFF(mission_idx);

    /* RSTGEN_MODULE_RST_STA, 0 = reset, 1 = release. */
    return !!(readl(mission_rst) & (0x1u << MISSION_RESET_CONTROL_RSTA));
}

/**
 * @brief taishan rstgen get latent reset status
 *
 * @param[in] base taishan rstgen address
 * @param[in] latent_idx latent index
 * @return 1, the latent reset has be released.
 *         0, the latent reset hasn't be released.
 */
sint32 taishan_rstgen_lld_get_latent_reset_status(uint32 base, uint32 latent_idx)
{
    uint32 latent_rst = base + MODULE_RESET_CONTROL_OFF(latent_idx);

    /* RSTGEN_MODULE_RST_STA, 0 = reset, 1 = release. */
    return !!(readl(latent_rst) & (0x1u << LATENT_RESET_CONTROL_RSTA));
}

/**
 * @brief taishan rstgen get general reg value
 *
 * @param[in] base taishan rstgen address
 * @param[in] reg_idx reg index
 * @return reg value
 */
uint32 taishan_rstgen_lld_read_general_reg(uint32 base, uint32 reg_idx)
{
    return readl(base + GENERAL_REG_OFF(reg_idx));
}

/**
 * @brief taishan rstgen get general reg value
 *
 * @param[in] base taishan rstgen address
 * @param[in] reg_idx reg index
 * @param[in] val write value
 * @return void
 */
void taishan_rstgen_lld_write_general_reg(uint32 base, uint32 reg_idx, uint32 val)
{
    writel(val, base + GENERAL_REG_OFF(reg_idx));
}

void taishan_rstgen_lld_set_ist_reset_by_mode(uint32 base, uint32 index, uint32 mode, uint32 val)
{
    if (mode <= IST_RESET_CONTROL_SLP_MODE) {
        RMWREG32(base + IST_RESET_CONTROL_OFF, mode, 1, val & 0x1u);
    }
}

void taishan_rstgen_lld_set_mission_reset_by_mode(uint32 base, uint32 index, uint32 mode,
        uint32 val)
{
    if (mode <= MISSION_RESET_CONTROL_SLP_MODE) {
        RMWREG32(base + MISSION_RESET_CONTROL_OFF(index), mode, 1, val & 0x1u);
    }
}

void taishan_rstgen_lld_set_latent_reset_by_mode(uint32 base, uint32 index, uint32 mode, uint32 val)
{
    if (mode <= LATENT_RESET_CONTROL_SLP_MODE) {
        RMWREG32(base + LATENT_RESET_CONTROL_OFF(index), mode, 1, val & 0x1u);
    }
}

void taishan_rstgen_lld_set_module_reset_by_mode(uint32 base, uint32 index, uint32 mode, uint32 val)
{
    if (mode <= MODULE_RESET_CONTROL_SLP_MODE) {
        RMWREG32(base + MODULE_RESET_CONTROL_OFF(index), mode, 1, val & 0x1u);
    }
}

void taishan_rstgen_lld_set_core_reset_by_mode(uint32 base, uint32 index, uint32 mode, uint32 val)
{
    if (mode <= CORE_RESET_CONTROL_SLP_MODE) {
        RMWREG32(base + CORE_RESET_CONTROL_OFF(index), mode, 1, val & 0x1u);
    }
}

void taishan_rstgen_lld_set_debug_reset_by_mode(uint32 base, uint32 index, uint32 mode, uint32 val)
{
    if (mode <= DBG_RESET_CONTROL_SLP_MODE) {
        RMWREG32(base + DBG_RESET_CONTROL_OFF, mode, 1, val & 0x1u);
    }
}

uint32 taishan_rstgen_lld_get_ss_rdy(uint32 base)
{
    uint32 glb_rst_ctrl;

    glb_rst_ctrl = readl(base + GLOBAL_RESET_CONTROL_OFF);

    return (glb_rst_ctrl >> GLOBAL_RESET_CONTROL_SS_RDY) & 0x1u;
}

uint32 taishan_rg_glb_reset_en(uint32 base, uint32 msk)
{
    uint32 v = readl(base + GLOBAL_RESET_CONTROL_OFF);
    v |= msk;
    writel(v, base + GLOBAL_RESET_CONTROL_OFF);

    return 0;
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

