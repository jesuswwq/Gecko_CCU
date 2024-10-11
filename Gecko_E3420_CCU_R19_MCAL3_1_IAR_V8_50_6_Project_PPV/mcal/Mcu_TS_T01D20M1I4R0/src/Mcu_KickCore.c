/** *****************************************************************************************************
 * SEMIDRIVE Copyright Statement                                                                        *
 * Copyright (c) SEMIDRIVE. All rights reserved                                                         *
 *                                                                                                      *
 * This software and all rights therein are owned by SEMIDRIVE, and are                                 *
 * protected by copyright law and other relevant laws, regulations and                                  *
 * protection. Without SEMIDRIVE's prior written consent and/or related rights,                         *
 * please do not use this software or any potion thereof in any form or by any                          *
 * means. You may not reproduce, modify or distribute this software except in                           *
 * compliance with the License. Unless required by applicable law or agreed to                          *
 * in writing, software distributed under the License is distributed on                                 *
 * an 'AS IS' basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.                         *
 *                                                                                                      *
 *******************************************************************************************************/
/** *****************************************************************************************************
 * \file     Mcu_KickCore.c                                                                             *
 * \brief    AUTOSAR 4.3.1 MCAL Mcu Driver                                                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/02     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "RegBase.h"
#include "Mcu_ResetSig.h"
#include "Mcu_ClkCfgNd.h"
#include "Mcu_GeneralTypes.h"
#include "Mcu_Reset.h"
#include "Mcu_Clk.h"
#include "Mcu_KickCore.h"
#include "Mcal.h"

/********************************************************************************************************
 *                                 Private Macro definition                                             *
 *******************************************************************************************************/
#define BP_ROMC_STICKY_REMAP_EN     0U

/********************************************************************************************************
 *                                  Global Constant Declarations                                        *
 *******************************************************************************************************/
#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

/* PRQA S 3218 55*/
static const Mcu_ScrSignalType signalScrSfRemapAr =  MCU_SCR_SF_REMAP_CR5_SF_AR_ADDR_OFFSET_19_0;
static const Mcu_ScrSignalType signalScrSfRemapAw =  MCU_SCR_SF_REMAP_CR5_SF_AW_ADDR_OFFSET_19_0;
static const Mcu_ScrSignalType signalScrSfRemapEn =  MCU_SCR_SF_SCR_REMAP_CR5_SF_REMAP_EN;
static const Mcu_ScrSignalType signalScrSfDccminp =  MCU_SCR_SF_SCR_CR5_SF_DCCMINP_0;
#ifndef SEMIDRIVE_E3_LITE_SERIES
static const Mcu_ScrSignalType signalScrSpRemapAr0 =  MCU_SCR_SF_REMAP_CR5_SP_AR0_ADDR_OFFSET_19_0;
static const Mcu_ScrSignalType signalScrSpRemapAr0En =  MCU_SCR_SF_REMAP_CR5_SP_AR0_REMAP_EN;
static const Mcu_ScrSignalType signalScrSpRemapAw0 =  MCU_SCR_SF_REMAP_CR5_SP_AW0_ADDR_OFFSET_19_0;
static const Mcu_ScrSignalType signalScrSpRemapAw0En =  MCU_SCR_SF_REMAP_CR5_SP_AW0_REMAP_EN;
static const Mcu_ScrSignalType signalScrSpRemapAr1 =  MCU_SCR_SF_REMAP_CR5_SP_AR1_ADDR_OFFSET_19_0;
static const Mcu_ScrSignalType signalScrSpRemapAr1En =  MCU_SCR_SF_REMAP_CR5_SP_AR1_REMAP_EN;
static const Mcu_ScrSignalType signalScrSpRemapAw1 =  MCU_SCR_SF_REMAP_CR5_SP_AW1_ADDR_OFFSET_19_0;
static const Mcu_ScrSignalType signalScrSpRemapAw1En =  MCU_SCR_SF_REMAP_CR5_SP_AW1_REMAP_EN;
static const Mcu_ScrSignalType signalScrSxRemapAr0 =  MCU_SCR_SF_REMAP_CR5_SX_AR0_ADDR_OFFSET_19_0;
static const Mcu_ScrSignalType signalScrSxRemapAr0En =  MCU_SCR_SF_REMAP_CR5_SX_AR0_REMAP_EN;
static const Mcu_ScrSignalType signalScrSxRemapAw0 =  MCU_SCR_SF_REMAP_CR5_SX_AW0_ADDR_OFFSET_19_0;
static const Mcu_ScrSignalType signalScrSxRemapAw0En =  MCU_SCR_SF_REMAP_CR5_SX_AW0_REMAP_EN;
static const Mcu_ScrSignalType signalScrSxRemapAr1 =  MCU_SCR_SF_REMAP_CR5_SX_AR1_ADDR_OFFSET_19_0;
static const Mcu_ScrSignalType signalScrSxRemapAr1En =  MCU_SCR_SF_REMAP_CR5_SX_AR1_REMAP_EN;
static const Mcu_ScrSignalType signalScrSxRemapAw1 =  MCU_SCR_SF_REMAP_CR5_SX_AW1_ADDR_OFFSET_19_0;
static const Mcu_ScrSignalType signalScrSxRemapAw1En =  MCU_SCR_SF_REMAP_CR5_SX_AW1_REMAP_EN;
static const Mcu_ScrSignalType signalScrSpLsDisable =  MCU_SCR_SF_SCR_CR5_SP_LS_DISABLE;
static const Mcu_ScrSignalType signalScrSpSlclampDisable =  MCU_SCR_SF_SCR_CR5_SP_SLCLAMP_DISABLE;
static const Mcu_ScrSignalType signalScrSpVic2Ls =  MCU_SCR_SF_VIC2_IS_LOCKSTEP_MODE_P;
static const Mcu_ScrSignalType signalScrSpDccminp0 =  MCU_SCR_SF_CR5_SP_DCCMINP_0;
static const Mcu_ScrSignalType signalScrSpDccminp2 =  MCU_SCR_SF_CR5_SP_DCCMINP2_0;
static const Mcu_ScrSignalType signalScrSxLsDisable =  MCU_SCR_SF_SCR_CR5_SX_LS_DISABLE;
static const Mcu_ScrSignalType signalScrSxSlclampDisable =  MCU_SCR_SF_SCR_CR5_SX_SLCLAMP_DISABLE;
static const Mcu_ScrSignalType signalScrSxVic2Ls =  MCU_SCR_SF_VIC3_IS_LOCKSTEP_MODE_P;
static const Mcu_ScrSignalType signalScrSxDccminp0 =  MCU_SCR_SF_CR5_SX_DCCMINP_0;
static const Mcu_ScrSignalType signalScrSxDccminp2 =  MCU_SCR_SF_CR5_SX_DCCMINP2_0;
static const Mcu_ScrSignalType signalScrSxM0BtiEn =  MCU_SCR_SF_BTI_SX_M0_BTI_EN;
static const Mcu_ScrSignalType signalScrSxP0BtiEn =  MCU_SCR_SF_BTI_SX_P0_BTI_EN;
static const Mcu_ScrSignalType signalScrSxM1BtiEn =  MCU_SCR_SF_BTI_SX_M1_BTI_EN;
static const Mcu_ScrSignalType signalScrSxP1BtiEn =  MCU_SCR_SF_BTI_SX_P1_BTI_EN;
static const Mcu_ScrSignalType signalScrSxAhbBtiEn =  MCU_SCR_SF_BTI_SX_AHB_BTI_EN;
static const Mcu_ScrSignalType signalScrSxM0BtiTimeout =  MCU_SCR_SF_BTI_SX_M0_TIMEOUT_DIV_7_0;
static const Mcu_ScrSignalType signalScrSxP0BtiTimeout =  MCU_SCR_SF_BTI_SX_P0_TIMEOUT_DIV_7_0;
static const Mcu_ScrSignalType signalScrSxM1BtiTimeout =  MCU_SCR_SF_BTI_SX_M1_TIMEOUT_DIV_7_0;
static const Mcu_ScrSignalType signalScrSxP1BtiTimeout =  MCU_SCR_SF_BTI_SX_P1_TIMEOUT_DIV_7_0;
static const Mcu_ScrSignalType signalScrSxAhbBtiTimeout = MCU_SCR_SF_BTI_SX_AHB_TIMEOUT_DIV_7_0;
static const Mcu_ScrSignalType signalScrSpM0BtiEn =  MCU_SCR_SF_BTI_SP_M0_BTI_EN;
static const Mcu_ScrSignalType signalScrSpP0BtiEn =  MCU_SCR_SF_BTI_SP_P0_BTI_EN;
static const Mcu_ScrSignalType signalScrSpAhbBtiEn =  MCU_SCR_SF_BTI_SP0_AHB_BTI_EN;
static const Mcu_ScrSignalType signalScrSpM1BtiEn =  MCU_SCR_SF_BTI_SP_M1_BTI_EN;
static const Mcu_ScrSignalType signalScrSpP1BtiEn =  MCU_SCR_SF_BTI_SP_P1_BTI_EN;
static const Mcu_ScrSignalType signalScrSpM0BtiTimeout =  MCU_SCR_SF_BTI_SP_M0_TIMEOUT_DIV_7_0;
static const Mcu_ScrSignalType signalScrSpP0BtiTimeout =  MCU_SCR_SF_BTI_SP_P0_TIMEOUT_DIV_7_0;
static const Mcu_ScrSignalType signalScrSpM1BtiTimeout =  MCU_SCR_SF_BTI_SP_M1_TIMEOUT_DIV_7_0;
static const Mcu_ScrSignalType signalScrSpP1BtiTimeout =  MCU_SCR_SF_BTI_SP_P1_TIMEOUT_DIV_7_0;
static const Mcu_ScrSignalType signalScrSpAhbBtiTimeout = MCU_SCR_SF_BTI_SP0_AHB_TIMEOUT_DIV_7_0;
static const Mcu_ScrSignalType signalScrDispTimeout =  MCU_SCR_SF_BTI_DISPSF_TIMEOUT_DIV_7_0;
static const Mcu_ScrSignalType signalScrDispEn =  MCU_SCR_SF_BTI_DISPSF_BTI_EN;
static const Mcu_ScrSignalType signalScrApTimeout =  MCU_SCR_SF_BTI_APSF_TIMEOUT_DIV_7_0;
static const Mcu_ScrSignalType signalScrApEn =  MCU_SCR_SF_BTI_APSF_BTI_EN;
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES */
#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

/********************************************************************************************************
 *                                  Private Function Declarations                                       *
 *******************************************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
void Mcu_Ip_SocScrSetBit(const Mcu_ScrSignalType *signalPtr, uint32 value)
{
    uint32 address = APB_SCR_SF_BASE;
    uint32 val;

    if (MCU_TYPE_RW == signalPtr->type)
    {
        address = address +  MCU_SCR_SW_TYPE_OFFSET;
        address = address + (((uint32)signalPtr->startBit >> 5U) * 4U);
        RMWREG32(address, (signalPtr->startBit % 32U), signalPtr->width, value);
    }
    else if (MCU_TYPE_L31 == signalPtr->type)
    {
        address = address +  MCU_SCR_L31_TYPE_OFFSET;
        address = address + (((uint32)signalPtr->startBit >> 5U) * 4U);
        val = REG_READ32(address);

        if (0U == ((val & (1UL << 31U)) >> 31U))
        {
            RMWREG32(address, (signalPtr->startBit % 32U), signalPtr->width, value);
        } /* else not needed */
    }
    else if (MCU_TYPE_R16W16 == signalPtr->type)
    {
        address = address +  MCU_SCR_R16W16_TYPE_OFFSET;
        address = address + (((uint32)signalPtr->startBit >> 5U) * 4U);

        /* Read only bits are considered locked.*/
        if ((signalPtr->startBit % 32U) < 16U)
        {
            RMWREG32(address, (signalPtr->startBit % 32U), signalPtr->width, value);
        } /* else not needed */
    }
    else
    {
        /*do nothing*/
    }
}

#ifndef SEMIDRIVE_E3_LITE_SERIES
static uint32 Mcu_Ip_SocScrGetBit(const Mcu_ScrSignalType *signalPtr)
{
    uint32 address = APB_SCR_SF_BASE + MCU_SCR_R16W16_TYPE_OFFSET;
    uint32 val = 0U;

    if (MCU_TYPE_R16W16 == signalPtr->type)
    {
        address = address + (((uint32)signalPtr->startBit >> 5U) * 4U);
        val = ((readl(address) >> (signalPtr->startBit % 32U)) & BIT_MASK(signalPtr->width));
    }
    else
    {
        /*do nothing*/
    }

    return val;
}
#endif /* SEMIDRIVE_E3_LITE_SERIES */

static void Mcu_Ip_SocRemapToZero(uint32 addr)
{
    uint32 address = addr;

    /* actually, the remapping been enabled by a register bit in ROMC. */
    address = address >> 12;

    Mcu_Ip_SocScrSetBit(&signalScrSfRemapAr, address);

    Mcu_Ip_SocScrSetBit(&signalScrSfRemapAw, address);

    Mcu_Ip_SocScrSetBit(&signalScrSfRemapEn, 1U);

}
#ifndef SEMIDRIVE_E3_LITE_SERIES
static void Mcu_Ip_SocRemapCoreSp(Mcu_KickCoreType core, uint32 addr)
{
    uint32 address = addr;

    if ((KICK_CR5_SP0 == core) || (KICK_CR5_SP == core))
    {
        address = address >> 12;

        Mcu_Ip_SocScrSetBit(&signalScrSpRemapAr0, address);
        Mcu_Ip_SocScrSetBit(&signalScrSpRemapAr0En, 1U);
        Mcu_Ip_SocScrSetBit(&signalScrSpRemapAw0, address);
        Mcu_Ip_SocScrSetBit(&signalScrSpRemapAw0En, 1U);
    }
    else if (KICK_CR5_SP1 == core)
    {
        address = address >> 12;
        Mcu_Ip_SocScrSetBit(&signalScrSpRemapAr1, address);
        Mcu_Ip_SocScrSetBit(&signalScrSpRemapAr1En, 1U);
        Mcu_Ip_SocScrSetBit(&signalScrSpRemapAw1, address);
        Mcu_Ip_SocScrSetBit(&signalScrSpRemapAw1En, 1U);
    }
    else
    {
        /*do nothing*/
    }
}

static void Mcu_Ip_SocRemapCoreSx(Mcu_KickCoreType core, uint32 addr)
{
    uint32 address = addr;

    if ((KICK_CR5_SX0 == core) || (KICK_CR5_SX == core))
    {
        address = address >> 12;
        Mcu_Ip_SocScrSetBit(&signalScrSxRemapAr0, address);
        Mcu_Ip_SocScrSetBit(&signalScrSxRemapAr0En, 1U);
        Mcu_Ip_SocScrSetBit(&signalScrSxRemapAw0, address);
        Mcu_Ip_SocScrSetBit(&signalScrSxRemapAw0En, 1U);
    }
    else if (KICK_CR5_SX1 == core)
    {
        address = address >> 12;
        Mcu_Ip_SocScrSetBit(&signalScrSxRemapAr1, address);
        Mcu_Ip_SocScrSetBit(&signalScrSxRemapAr1En, 1U);
        Mcu_Ip_SocScrSetBit(&signalScrSxRemapAw1, address);
        Mcu_Ip_SocScrSetBit(&signalScrSxRemapAw1En, 1U);
    }
    else
    {
        /*do nothing*/
    }
}
#endif
static Std_ReturnType Mcu_Ip_SocRemapCoreVbar(Mcu_KickCoreType core, uint32 addr)
{
    Std_ReturnType errStatus = E_OK;
    uint32 address = addr;

    if (KICK_CR5_SF == core)
    {
        Mcu_Ip_SocRemapToZero(address);
    }

#ifndef SEMIDRIVE_E3_LITE_SERIES
    else if (core < KICK_CORE_MAX)
    {
        Mcu_Ip_SocRemapCoreSp(core, addr);
        Mcu_Ip_SocRemapCoreSx(core, addr);
    }

#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/
    else
    {
        errStatus = MCU_E_PARAM_CONFIG;
    }

    return errStatus;
}

static void Mcu_Ip_RamFuncRomFixSetStickyBit(uint32 pos)
{
    uint32 b = APB_IROMC_BASE;
    /*to avoid calling func in ROM */
    uint32 v = readl(b + STICKY_REG_OFF);
    v |= ((uint32)0x01U << pos);
    writel(v, b + STICKY_REG_OFF);
}
#ifndef SEMIDRIVE_E3_LITE_SERIES
static void Mcu_Ip_SocCoreLockStepSp(Mcu_KickCoreType core)
{

    /* cores are in lockstep mode by default */
    if ((KICK_CR5_SP0 == core) || (KICK_CR5_SP1 == core))
    {
        Mcu_Ip_SocScrSetBit(&signalScrSpLsDisable, 1U);
        Mcu_Ip_SocScrSetBit(&signalScrSpSlclampDisable, 1U);
        Mcu_Ip_SocScrSetBit(&signalScrSpVic2Ls, 1U);
    }
    else if (KICK_CR5_SP == core)
    {
        Mcu_Ip_SocScrSetBit(&signalScrSpDccminp0, 0U);
        Mcu_Ip_SocScrSetBit(&signalScrSpDccminp2, 0U);
        Mcu_Ip_SocScrSetBit(&signalScrSpLsDisable, 0U);
        Mcu_Ip_SocScrSetBit(&signalScrSpSlclampDisable, 0U);
        Mcu_Ip_SocScrSetBit(&signalScrSpVic2Ls, 0U);
    }
    else
    {
        /*do nothing*/
    }
}
static void Mcu_Ip_SocCoreLockStepSx(Mcu_KickCoreType core)
{

    /* cores are in lockstep mode by default */
    if ((KICK_CR5_SX0 == core) || (KICK_CR5_SX1 == core))
    {
        Mcu_Ip_SocScrSetBit(&signalScrSxLsDisable, 1U);
        Mcu_Ip_SocScrSetBit(&signalScrSxSlclampDisable, 1U);
        Mcu_Ip_SocScrSetBit(&signalScrSxVic2Ls, 1U);
    }
    else if (KICK_CR5_SX == core)
    {
        /* disable cr5_sx_dccm before issue a reset */
        Mcu_Ip_SocScrSetBit(&signalScrSxDccminp0, 0U);
        Mcu_Ip_SocScrSetBit(&signalScrSxDccminp2, 0U);
        Mcu_Ip_SocScrSetBit(&signalScrSxLsDisable, 0U);
        Mcu_Ip_SocScrSetBit(&signalScrSxSlclampDisable, 0U);
        Mcu_Ip_SocScrSetBit(&signalScrSxVic2Ls, 0U);
    }
    else
    {
        /*do nothing*/
    }
}
#endif

void Mcu_Ip_SocBtiEnableSf(void)
{
    /*  BTI_EN shall set before the core reset,
        while the BTI_EN of the main core in the current project is not set to default 1 as expected. so,
        1. Before the BTI EN command is executed, the previous transmission shall complete.
        2. BTI EN instruction shall complete, then transmit other instruction.
    */
    /*  m0_timeout 0-7, btien 8,
        p0_timeout 0-7, btien 8,
        ahb_timeout 0-7, btien 8,
    */
    ASM_KEYWORD("isb sy");
    ASM_KEYWORD("dsb sy");
    writel(0x101FFU, APB_SCR_SF_BASE + MCU_SCR_R16W16_TYPE_OFFSET);
    ASM_KEYWORD("isb sy");
    ASM_KEYWORD("dsb sy");
    writel(0x101FFU, (APB_SCR_SF_BASE + MCU_SCR_R16W16_TYPE_OFFSET + 4U));
    ASM_KEYWORD("isb sy");
    ASM_KEYWORD("dsb sy");
    writel(0x101FFU, (APB_SCR_SF_BASE + MCU_SCR_R16W16_TYPE_OFFSET + 8U));
    ASM_KEYWORD("isb sy");
    ASM_KEYWORD("dsb sy");
}
#ifndef SEMIDRIVE_E3_LITE_SERIES
static void Mcu_Ip_SocBtiEnableSx(void)
{
    uint32 signalSxM0BtiEn;

    signalSxM0BtiEn = Mcu_Ip_SocScrGetBit(&signalScrSxM0BtiEn);

    if (1U != signalSxM0BtiEn)
    {
        Mcu_Ip_SocScrSetBit(&signalScrSxM0BtiTimeout, 0xFFU);
        Mcu_Ip_SocScrSetBit(&signalScrSxM0BtiEn, 1U);
        Mcu_Ip_SocScrSetBit(&signalScrSxP0BtiTimeout, 0xFFU);
        Mcu_Ip_SocScrSetBit(&signalScrSxP0BtiEn, 1U);
        Mcu_Ip_SocScrSetBit(&signalScrSxAhbBtiTimeout, 0xFFU);
        Mcu_Ip_SocScrSetBit(&signalScrSxAhbBtiEn, 1U);
        Mcu_Ip_SocScrSetBit(&signalScrSxM1BtiTimeout, 0xFFU);
        Mcu_Ip_SocScrSetBit(&signalScrSxM1BtiEn, 1U);
        Mcu_Ip_SocScrSetBit(&signalScrSxP1BtiTimeout, 0xFFU);
        Mcu_Ip_SocScrSetBit(&signalScrSxP1BtiEn, 1U);
    }

}
static void Mcu_Ip_SocBtiEnableSp(void)
{
    uint32 signalSpM0BtiEn;

    signalSpM0BtiEn = Mcu_Ip_SocScrGetBit(&signalScrSpM0BtiEn);

    if (1U != signalSpM0BtiEn)
    {
        Mcu_Ip_SocScrSetBit(&signalScrSpM0BtiTimeout, 0xFFU);
        Mcu_Ip_SocScrSetBit(&signalScrSpM0BtiEn, 1U);
        Mcu_Ip_SocScrSetBit(&signalScrSpP0BtiTimeout, 0xFFU);
        Mcu_Ip_SocScrSetBit(&signalScrSpP0BtiEn, 1U);
        Mcu_Ip_SocScrSetBit(&signalScrSpAhbBtiTimeout, 0xFFU);
        Mcu_Ip_SocScrSetBit(&signalScrSpAhbBtiEn, 1U);
        Mcu_Ip_SocScrSetBit(&signalScrSpM1BtiTimeout, 0xFFU);
        Mcu_Ip_SocScrSetBit(&signalScrSpM1BtiEn, 1U);
        Mcu_Ip_SocScrSetBit(&signalScrSpP1BtiTimeout, 0xFFU);
        Mcu_Ip_SocScrSetBit(&signalScrSpP1BtiEn, 1U);
    }
}

static void Mcu_Ip_SocBtiEnableApDisp(void)
{
    uint32 signalApBtiEn;

    signalApBtiEn = Mcu_Ip_SocScrGetBit(&signalScrApEn);

    if (1U != signalApBtiEn)
    {
        Mcu_Ip_SocScrSetBit(&signalScrDispTimeout, 0xFFU);
        Mcu_Ip_SocScrSetBit(&signalScrDispEn, 0x1U);
        Mcu_Ip_SocScrSetBit(&signalScrApTimeout, 0xFFU);
        Mcu_Ip_SocScrSetBit(&signalScrApEn, 1U);
    }

}

/* lockstep and split mode switch,
    1.vic and core need in same mode
    1) assert vic and core; 2) switch mode; 3) release core 4) release vic
    keep the flow to aviod SEM error

    2.ensure that both SP0/SP1 are in the reset state,and the corresponding BTI SP0/SP1 will also be in the reset state
    1) split->lockstep: sp1/sp0 shall assert, assert sp1 first; 2)switch mode; 3) reset sp0
    2) lockstep->split: sp1/sp0 shall assert, assert sp1 first; 2)switch mode; 3) reset sp0/sp1, sp0 reset first*/

static Std_ReturnType Mcu_Ip_SocKickcorePreAssert(Mcu_KickCoreType core)
{
    Std_ReturnType errStatus = E_OK;

    if ((KICK_CR5_SP0 == core) || (KICK_CR5_SP == core))
    {
        errStatus = Mcu_Ip_ResetCtlAssert(&rstsig_vic2_portb);
        errStatus |= Mcu_Ip_ResetCtlAssert(&rstsig_cr5_sp1);
        errStatus |= Mcu_Ip_ResetCtlAssert(&rstsig_vic2_porta);
        errStatus |= Mcu_Ip_ResetCtlAssert(&rstsig_cr5_sp0);
    }
    else if (KICK_CR5_SP1 == core)
    {
        errStatus = Mcu_Ip_ResetCtlAssert(&rstsig_vic2_portb);
        errStatus |= Mcu_Ip_ResetCtlAssert(&rstsig_cr5_sp1);
    }
    else if ((KICK_CR5_SX0 == core) || (KICK_CR5_SX == core))
    {
        errStatus = Mcu_Ip_ResetCtlAssert(&rstsig_vic3_portb);
        errStatus |= Mcu_Ip_ResetCtlAssert(&rstsig_cr5_sx1);
        errStatus |= Mcu_Ip_ResetCtlAssert(&rstsig_vic3_porta);
        errStatus |= Mcu_Ip_ResetCtlAssert(&rstsig_cr5_sx0);
    }
    else if (KICK_CR5_SX1 == core)
    {
        errStatus = Mcu_Ip_ResetCtlAssert(&rstsig_vic3_portb);
        errStatus |= Mcu_Ip_ResetCtlAssert(&rstsig_cr5_sx1);
    }
    else
    {
        /* do nothing */
    }

    return errStatus;
}
#endif
/* when bus busy, kickcore may fail,
before kickcore, need enable bti, ensure bus transfer over
sf will set the bti of other cores at initialization, when other cores assert,
the bti of sf will set in start.s */
void Mcu_Ip_SocBtiEnable(void)
{
    /** Mcu_Ip_SocBtiEnableSf();  */
#ifndef SEMIDRIVE_E3_LITE_SERIES
    Mcu_Ip_SocBtiEnableSx();
    Mcu_Ip_SocBtiEnableSp();
    Mcu_Ip_SocBtiEnableApDisp();
#endif
}

Std_ReturnType Mcu_Ip_SocKickCore(Mcu_KickCoreType core, uint32 entry)
{
    Std_ReturnType errStatus;
    /*
        SP0 and SP1, you cannot kick SP1 without kicking SP0,
        SX0 and SX1, you cannot kick SX1 without kicking SX0,
        violating the above rules will result in an undefined exception.
    */
    errStatus = Mcu_Ip_SocRemapCoreVbar(core, entry);

    if (E_OK == errStatus)
    {
#ifndef SEMIDRIVE_E3_LITE_SERIES
        errStatus = Mcu_Ip_SocKickcorePreAssert(core);

        if (E_OK == errStatus)
        {
            Mcu_Ip_SocCoreLockStepSp(core);
            Mcu_Ip_SocCoreLockStepSx(core);

            if ((KICK_CR5_SX0 == core) || (KICK_CR5_SX == core))
            {
                errStatus = Mcu_Ip_ResetCtlReset(&rstsig_cr5_sx0);
                errStatus |= Mcu_Ip_ResetCtlDeassert(&rstsig_vic3_porta);
            }
            else if (KICK_CR5_SX1 == core)
            {
                errStatus = Mcu_Ip_ResetCtlReset(&rstsig_cr5_sx1);
                errStatus |= Mcu_Ip_ResetCtlDeassert(&rstsig_vic3_portb);
            }
            else if ((KICK_CR5_SP0 == core) || (KICK_CR5_SP == core))
            {
                errStatus = Mcu_Ip_ResetCtlReset(&rstsig_cr5_sp0);
                errStatus |= Mcu_Ip_ResetCtlDeassert(&rstsig_vic2_porta);
            }
            else if (KICK_CR5_SP1 == core)
            {
                errStatus = Mcu_Ip_ResetCtlReset(&rstsig_cr5_sp1);
                errStatus |= Mcu_Ip_ResetCtlDeassert(&rstsig_vic2_portb);
            }
            else if (KICK_CR5_SF == core)
            {
                Mcu_Ip_RamFuncRomFixSetStickyBit(BP_ROMC_STICKY_REMAP_EN);
                /* disable cr5_sf_dccm before issue a reset */
                Mcu_Ip_SocScrSetBit(&signalScrSfDccminp, 0U);
                errStatus = Mcu_Ip_ResetCtlReset(&rstsig_cr5_saf);
            }
            else
            {
                errStatus = MCU_E_PARAM_CONFIG;
            }
        }

#else

        if (KICK_CR5_SF == core)
        {
            Mcu_Ip_RamFuncRomFixSetStickyBit(BP_ROMC_STICKY_REMAP_EN);
            /* disable cr5_sf_dccm before issue a reset */
            Mcu_Ip_SocScrSetBit(&signalScrSfDccminp, 0U);
            errStatus = Mcu_Ip_ResetCtlReset(&rstsig_cr5_saf);
        } /* else not needed */

#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/
    }

    return errStatus;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
/* End of file */
