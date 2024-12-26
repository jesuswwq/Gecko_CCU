/**
 * @file remap.c
 * @brief remap source file
 *
 * @copyright Copyright (c) 2022  Semidrive Semiconductor.
 *            All rights reserved.
 */
#include "remap.h"
#include "Mcu_Scr.h"
#include "Mcu_ScrBits.h"
#include "__regs_base.h"
#include "Mcu_Reset.h"
#include "Mcu_Mpu.h"
#include "arch_irq.h"
#include "arch_irq.h"
#include "RegHelper.h"

static scr_signal_t sf_remap_scr[] = {
    SCR_SF_REMAP_CR5_SF_AR_ADDR_OFFSET_19_0,
    SCR_SF_REMAP_CR5_SF_AR_REMAP_EN,
    SCR_SF_REMAP_CR5_SF_AW_ADDR_OFFSET_19_0,
    SCR_SF_SCR_REMAP_CR5_SF_REMAP_EN,
};

static scr_signal_t sp0_remap_scr[] = {
    SCR_SF_REMAP_CR5_SP_AR0_ADDR_OFFSET_19_0,
    SCR_SF_REMAP_CR5_SP_AR0_REMAP_EN,
    SCR_SF_REMAP_CR5_SP_AW0_ADDR_OFFSET_19_0,
    SCR_SF_REMAP_CR5_SP_AW0_REMAP_EN,
};

static scr_signal_t sp1_remap_scr[] = {
    SCR_SF_REMAP_CR5_SP_AR1_ADDR_OFFSET_19_0,
    SCR_SF_REMAP_CR5_SP_AR1_REMAP_EN,
    SCR_SF_REMAP_CR5_SP_AW1_ADDR_OFFSET_19_0,
    SCR_SF_REMAP_CR5_SP_AW1_REMAP_EN,
};

static scr_signal_t sx0_remap_scr[] = {
    SCR_SF_REMAP_CR5_SX_AR0_ADDR_OFFSET_19_0,
    SCR_SF_REMAP_CR5_SX_AR0_REMAP_EN,
    SCR_SF_REMAP_CR5_SX_AW0_ADDR_OFFSET_19_0,
    SCR_SF_REMAP_CR5_SX_AW0_REMAP_EN,
};

static scr_signal_t sx1_remap_scr[] = {
    SCR_SF_REMAP_CR5_SX_AR1_ADDR_OFFSET_19_0,
    SCR_SF_REMAP_CR5_SX_AR1_REMAP_EN,
    SCR_SF_REMAP_CR5_SX_AW1_ADDR_OFFSET_19_0,
    SCR_SF_REMAP_CR5_SX_AW1_REMAP_EN,
};

static enum sdrv_remap_status sdrv_core_remap_scr_config(scr_signal_t *scrs,
                                                         uint32 mem_base)
{
    mem_base >>= 12U;
    if ((Mcu_ScrGetBit(&scrs[0]) == mem_base) &&
        (Mcu_ScrGetBit(&scrs[2]) == mem_base) &&
        (Mcu_ScrGetBit(&scrs[1]) == 0x1U) &&
        (Mcu_ScrGetBit(&scrs[3]) == 0x1U)) {
        return SDRV_REMAP_FAIL;
    }

    Mcu_ScrSetBit(&scrs[0], mem_base);
    Mcu_ScrSetBit(&scrs[1], 0x1U);
    Mcu_ScrSetBit(&scrs[2], mem_base);
    Mcu_ScrSetBit(&scrs[3], 0x1U);

    return SDRV_REMAP_OK;

    // if ((scr_get(&scr_ctrl, &scrs[0]) == mem_base) &&
    //     (scr_get(&scr_ctrl, &scrs[2]) == mem_base) &&
    //     (scr_get(&scr_ctrl, &scrs[1]) == 0x1U) &&
    //     (scr_get(&scr_ctrl, &scrs[3]) == 0x1U)) {
    //     return SDRV_REMAP_FAIL;
    // }

    // scr_set(&scr_ctrl, &scrs[0], mem_base);
    // scr_set(&scr_ctrl, &scrs[1], 0x1U);
    // scr_set(&scr_ctrl, &scrs[2], mem_base);
    // scr_set(&scr_ctrl, &scrs[3], 0x1U);

    // return SDRV_REMAP_OK;
}

/**
 * @brief Remap specific memory to exception table.
 *
 * This function remap memory to exception vector, after call this
 * function, core will be reset.
 *
 * @param [in] core core to be remap
 * @param [in] mem_base memory base
 * @return SDRV_REMAP_OK: reset core success, SDRV_REMAP_FAIL: reset core fail
 */
enum sdrv_remap_status sdrv_core_remap(sdrv_remap_core_e core,
                                       uint32 mem_base)
{
    enum sdrv_remap_status ret = SDRV_REMAP_OK;
    scr_signal_t *scrs;
    reset_sig_t *rst_sig;
    irq_state_t irq_stat;

    if (mem_base & 0xFFF != 0)
        return SDRV_REMAP_FAIL;

    switch (core) {
    case SDRV_REMAP_SF:
        scrs = &sf_remap_scr[0];
        rst_sig = &rstsig_cr5_saf;
        break;

    case SDRV_REMAP_SP0:
        scrs = &sp0_remap_scr[0];
        rst_sig = &rstsig_cr5_sp0;
        break;

    case SDRV_REMAP_SP1:
        scrs = &sp1_remap_scr[0];
        rst_sig = &rstsig_cr5_sp1;
        break;

    case SDRV_REMAP_SX0:
        scrs = &sx0_remap_scr[0];
        rst_sig = &rstsig_cr5_sx0;
        break;

    case SDRV_REMAP_SX1:
        scrs = &sx1_remap_scr[0];
        rst_sig = &rstsig_cr5_sx1;
        break;

    default:
        return SDRV_REMAP_FAIL;
    }

    irq_stat = arch_irq_save();

    ret = sdrv_core_remap_scr_config(scrs, mem_base);
    if (ret == SDRV_REMAP_OK) {
        if (core == SDRV_REMAP_SF) {
            RMWREG32(APB_IROMC_BASE + 0x4, 0, 1, 1);
        }

        DSB;
        ISB;

        // sdrv_rstgen_reset(rst_sig);
        reset_ctl_reset(rst_sig);
    }

    arch_irq_restore(irq_stat);

    return ret;
}

/**
 * @brief Force Remap specific memory to exception table.
 *
 * This function remap memory to exception vector, after call this
 * function, core will be reset. This function will force remap
 * and reset.
 *
 * @param [in] core core to be remap
 * @param [in] mem_base memory base
 * @return SDRV_REMAP_OK: reset core success, SDRV_REMAP_FAIL: reset core fail
 */
enum sdrv_remap_status sdrv_core_force_remap(sdrv_remap_core_e core,
                                             uint32 mem_base)
{
    scr_signal_t *scrs;
    reset_sig_t *rst_sig;
    irq_state_t irq_stat;

    if ((mem_base & 0xFFF) != 0)
        return SDRV_REMAP_FAIL;

    switch (core) {
    case SDRV_REMAP_SF:
        scrs = &sf_remap_scr[0];
        rst_sig = &rstsig_cr5_saf;
        break;

    case SDRV_REMAP_SP0:
        scrs = &sp0_remap_scr[0];
        rst_sig = &rstsig_cr5_sp0;
        break;

    case SDRV_REMAP_SP1:
        scrs = &sp1_remap_scr[0];
        rst_sig = &rstsig_cr5_sp1;
        break;

    case SDRV_REMAP_SX0:
        scrs = &sx0_remap_scr[0];
        rst_sig = &rstsig_cr5_sx0;
        break;

    case SDRV_REMAP_SX1:
        scrs = &sx1_remap_scr[0];
        rst_sig = &rstsig_cr5_sx1;
        break;

    default:
        return SDRV_REMAP_FAIL;
    }

    irq_stat = arch_irq_save();

    sdrv_core_remap_scr_config(scrs, mem_base);

    if (core == SDRV_REMAP_SF) {
        RMWREG32(APB_IROMC_BASE + 0x4, 0, 1, 1);
    }
    DSB;
    ISB;

    // sdrv_rstgen_reset(rst_sig);
    reset_ctl_reset(rst_sig);

    arch_irq_restore(irq_stat);

    return SDRV_REMAP_OK;
}
