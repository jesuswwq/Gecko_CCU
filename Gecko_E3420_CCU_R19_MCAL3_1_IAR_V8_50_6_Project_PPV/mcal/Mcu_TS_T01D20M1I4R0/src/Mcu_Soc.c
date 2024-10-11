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
 * \file     Mcu_Soc.c                                                                                  *
 * \brief    AUTOSAR 4.3.1 MCAL Mcu Driver                                                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/03     <td>1.0U.0U                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "RegHelper.h"
#include "RegBase.h"
#include "Mcu_Soc.h"
#include "Mcu_GeneralTypes.h"
#include "Mcu_Cfg.h"

/********************************************************************************************************
 *                                 Private Macro definition                                             *
 *******************************************************************************************************/

#define MAILBOX_WAIT_TIME  0x100000U

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
/********************************************************************************************************
 *                                  Private Function Declarations                                       *
 *******************************************************************************************************/
/* reset btm module */
static void Mcu_Ip_SocBtmReset(uint32 base)
{
    /* disable G0 */
    writel(0U, base + BTM_G0_EN_OFFSET);
    /* disable G1 */
    writel(0U, base + BTM_G1_EN_OFFSET);
    /* disable int */
    writel(0U, base + BTM_INT_STA_EN_OFFSET);
    writel(0U, base + BTM_INT_SIG_EN_OFFSET);
    /* clear int sta */
    writel(0xFFFFFFFFU, base + BTM_INT_STA_OFFSET);
}

/* reset etimer counter module */
static void Mcu_Ip_SocEtimerReset(uint32 base)
{
    /* disable cpt module */
    writel(0U, base + ETIMER_CPT_CTRL_OFFSET);
    /* disable cmp module */
    writel(0U, base + ETIMER_CMP_CTRL_OFFSET);
    /* disable G0 */
    writel(0U, base + ETIMER_G0_EN_OFFSET);
    /* disable G1 */
    writel(0U, base + ETIMER_G1_EN_OFFSET);
    /* disable lcnt_a */
    writel(0U, base + ETIMER_LCNT_A_EN_OFFSET);
    /* disable lcnt_b */
    writel(0U, base + ETIMER_LCNT_B_EN_OFFSET);
    /* disable lcnt_c */
    writel(0U, base + ETIMER_LCNT_C_EN_OFFSET);
    /* disable lcnt_d */
    writel(0U, base + ETIMER_LCNT_D_EN_OFFSET);

    /* disable cor err int */
    writel(0, base + ETIMER_COR_ERR_INT_STA_EN_OFFSET);
    writel(0, base + ETIMER_COR_ERR_INT_SIG_EN_OFFSET);
    /* clear cor err int sta */
    writel(0xFFFFFFFFU, base + ETIMER_COR_ERR_INT_STA_OFFSET);
    /* disable unc err int */
    writel(0, base + ETIMER_UNC_ERR_INT_STA_EN_OFFSET);
    writel(0, base + ETIMER_UNC_ERR_INT_SIG_EN_OFFSET);
    /* clear unc err int sta */
    writel(0xFFFFFFFFU, base + ETIMER_UNC_ERR_INT_STA_OFFSET);
    /* reset cmp a fault cfg*/
    writel(0, base + ETIMER_CMP_A_FAULT_EVENT_CTRL_OFFSET);
    /* reset cmp b fault cfg*/
    writel(0, base + ETIMER_CMP_B_FAULT_EVENT_CTRL_OFFSET);
    /* reset cmp c fault cfg*/
    writel(0, base + ETIMER_CMP_C_FAULT_EVENT_CTRL_OFFSET);
    /* reset cmp d fault cfg*/
    writel(0, base + ETIMER_CMP_D_FAULT_EVENT_CTRL_OFFSET);

    /* reset all counter to 0U */
    writel(0x3FU, base + ETIMER_SW_RST_OFFSET);
    /* reset dma config */
    writel(0U, base + ETIMER_DMA_CTRL_OFFSET);
    /* disable int */
    writel(0U, base + ETIMER_INT_STA_EN_OFFSET);
    writel(0U, base + ETIMER_INT_SIG_EN_OFFSET);
    /* clear int sta */
    writel(0xFFFFFFFFU, base + ETIMER_INT_STA_OFFSET);
}

/* reset epwm counter module */
static void Mcu_Ip_SocEpwmReset(uint32 base)
{
    /* disable cmp module */
    writel(0U, base + EPWM_CMP_CTRL_OFFSET);
    /* disable G0 */
    writel(0U, base + EPWM_G0_EN_OFFSET);
    /* disable G1 */
    writel(0U, base + EPWM_G1_EN_OFFSET);
    /* reset all counter and fifo to 0U */
    writel(0x3FF, base + EPWM_SW_RST_OFFSET);
    /* reset dma config */
    writel(0U, base + EPWM_DMA_CTRL_OFFSET);
    /* disable int */
    writel(0U, base + EPWM_INT_STA_EN_OFFSET);
    writel(0U, base + EPWM_INT_SIG_EN_OFFSET);
    /* clear int sta */
    writel(0xFFFFFFFFU, base + EPWM_INT_STA_OFFSET);
    /* reset cnt g0 cfg*/
    writel(0U, base + EPWM_CNT_G0_CFG_OFFSET);
    /* reset cnt g1 cfg*/
    writel(0U, base + EPWM_CNT_G1_CFG_OFFSET);
    /* reset cmp a cfg*/
    writel(0U, base + EPWM_CMP_A_CONFIG_OFFSET);
    /* reset cmp a mfc and dither cfg*/
    writel(0U, base + EPWM_CMP_A_DITHER_OFFSET);
    /* reset cmp b cfg*/
    writel(0U, base + EPWM_CMP_B_CONFIG_OFFSET);
    /* reset cmp b mfc and dither cfg*/
    writel(0U, base + EPWM_CMP_B_DITHER_OFFSET);
    /* reset cmp c cfg*/
    writel(0U, base + EPWM_CMP_C_CONFIG_OFFSET);
    /* reset cmp c mfc and dither cfg*/
    writel(0U, base + EPWM_CMP_C_DITHER_OFFSET);
    /* reset cmp d cfg*/
    writel(0U, base + EPWM_CMP_D_CONFIG_OFFSET);
    /* reset cmp d mfc and dither cfg*/
    writel(0U, base + EPWM_CMP_D_DITHER_OFFSET);
    /* reset cmp a sse cfg*/
    writel(0U, base + EPWM_CMP_A_SSE_CTRL_OFFSET);
    /* reset cmp b sse cfg*/
    writel(0U, base + EPWM_CMP_B_SSE_CTRL_OFFSET);
    /* reset cmp c sse cfg*/
    writel(0U, base + EPWM_CMP_C_SSE_CTRL_OFFSET);
    /* reset cmp d sse cfg*/
    writel(0U, base + EPWM_CMP_D_SSE_CTRL_OFFSET);
    /* reset fault0 cfg*/
    writel(0U, base + EPWM_FAULT0_FLT_OFFSET);
    /* reset fault1 cfg*/
    writel(0U, base + EPWM_FAULT1_FLT_OFFSET);
    /* reset fault2 cfg*/
    writel(0U, base + EPWM_FAULT2_FLT_OFFSET);
    /* reset fault3 cfg*/
    writel(0U, base + EPWM_FAULT3_FLT_OFFSET);
    /* reset cmp a fault cfg*/

    /* disable cor err int */
    writel(0, base + EPWM_COR_ERR_INT_STA_EN_OFFSET);
    writel(0, base + EPWM_COR_ERR_INT_SIG_EN_OFFSET);
    /* clear cor err int sta */
    writel(0xFFFFFFFFU, base + EPWM_COR_ERR_INT_STA_OFFSET);
    /* disable unc err int */
    writel(0, base + EPWM_UNC_ERR_INT_STA_EN_OFFSET);
    writel(0, base + EPWM_UNC_ERR_INT_SIG_EN_OFFSET);
    /* clear unc err int sta */
    writel(0xFFFFFFFFU, base + EPWM_UNC_ERR_INT_STA_OFFSET);

    writel(0U, base + EPWM_CMP_A_FAULT_EVENT_CTRL_OFFSET);
    /* reset cmp b fault cfg*/
    writel(0U, base + EPWM_CMP_B_FAULT_EVENT_CTRL_OFFSET);
    /* reset cmp c fault cfg*/
    writel(0U, base + EPWM_CMP_C_FAULT_EVENT_CTRL_OFFSET);
    /* reset cmp d fault cfg*/
    writel(0U, base + EPWM_CMP_D_FAULT_EVENT_CTRL_OFFSET);
    /* reset cmp a dti cfg*/
    writel(0U, base + EPWM_CMP_A_DTI_CTRL_OFFSET);
    /* reset cmp b dti cfg*/
    writel(0U, base + EPWM_CMP_B_DTI_CTRL_OFFSET);
    /* reset cmp c dti cfg*/
    writel(0U, base + EPWM_CMP_C_DTI_CTRL_OFFSET);
    /* reset cmp d dti cfg*/
    writel(0U, base + EPWM_CMP_D_DTI_CTRL_OFFSET);
}
#ifndef SEMIDRIVE_E3_LITE_SERIES
static void Mcu_Ip_SocApDomGate(uint32 smcBase)
{
    rmw32(smcBase + AP_LP_CTL(0U), 0U, 4U, (uint32)0xfu);
    rmw32(smcBase + AP_LP_CTL(0U), 4U, 1U, (uint32)1U);
}
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/
static void Mcu_Ip_SocSafetyDomGate(uint32 smcBase, Mcu_PowerDomType dom)
{
    rmw32(smcBase + SAF_LP_CTL(dom), 0U, 4U, (uint32)0xfu);
    rmw32(smcBase + SAF_LP_CTL(dom), 4U, 1U, (uint32)1U);
}
#ifndef SEMIDRIVE_E3_LITE_SERIES
static void Mcu_Ip_SocApRamGate(uint32 smcBase)
{
    /* normal mode gate */
    rmw32((smcBase + AP_RAM_LP_CTL(0U)), 2U, 1U, (uint32)1U);
    rmw32((smcBase + AP_RAM_LP_CTL(0U)), 9U, 3U, (uint32)7U);
    /* hib mode gate */
    rmw32((smcBase + AP_RAM_LP_CTL(0U)), 1U, 1U, (uint32)1U);
    rmw32((smcBase + AP_RAM_LP_CTL(0U)), 6U, 3U, (uint32)7U);
    /* slp mode gate */
    rmw32((smcBase + AP_RAM_LP_CTL(0U)), 0U, 1U, (uint32)1U);
    rmw32((smcBase + AP_RAM_LP_CTL(0U)), 3U, 3U, (uint32)7U);

}
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/
static void Mcu_Ip_SocSafetyRamGate(uint32 smcBase, Mcu_PowerRam ram)
{
    /* normal mode gate */
    rmw32(smcBase + SAF_RAM_LP_CTL(ram), 2U, 1U, (uint32)1U);
    rmw32(smcBase + SAF_RAM_LP_CTL(ram), 9U, 3U, (uint32)7U);
    /* hib mode gate */
    rmw32(smcBase + SAF_RAM_LP_CTL(ram), 1U, 1U, (uint32)1U);
    rmw32(smcBase + SAF_RAM_LP_CTL(ram), 6U, 3U, (uint32)7U);
    /* slp mode gate */
    rmw32(smcBase + SAF_RAM_LP_CTL(ram), 0U, 1U, (uint32)1U);
    rmw32(smcBase + SAF_RAM_LP_CTL(ram), 3U, 3U, (uint32)7U);
}
#ifndef SEMIDRIVE_E3_LITE_SERIES
static void Mcu_Ip_SocApAnaGate(void)
{
    uint32 value = 1U;

    /* PLL4/5 LVDS */
    rmw32(APB_PLL4_BASE, 0U, 1U, value);
    rmw32(APB_PLL5_BASE, 0U, 1U, value);
    rmw32(APB_PLL_LVDS_BASE, 0U, 1U, value);
    /* VD_AP */
    rmw32(APB_PMU_CORE_BASE + PMU_SCRS_BITS_OFFSET, 28U, 1U, value);
    /* POR_AP */
    rmw32(APB_PMU_CORE_BASE + PMU_SCRS_BITS_OFFSET, 27U, 1U, value);
    /* bgr33_ap */
    rmw32(APB_PMU_CORE_BASE + PMU_SCRS_BITS_OFFSET, 29U, 1U, value);
    /* bgr33_dis */
    rmw32(APB_PMU_CORE_BASE + PMU_SCRS_BITS_OFFSET, 30U, 1U, value);
    /* pt_sns_ap */
    rmw32(APB_PT_SNS_AP_BASE, 1U, 1U, value);
    rmw32(APB_PT_SNS_AP_BASE, 2U, 1U, value);
}
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/
/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
/*PRQA S 1505 1*/
uint8 Mcu_GetCoreID(void)
{
    return GetCoreID();
}

uint32 Mcu_Ip_SocGetCoreFreq(void)
{
    Mcu_ClkRateType core_freq;
    uint8 CoreId = Mcu_GetCoreID();

    if ((uint8)CPU_ID_SF == CoreId)
    {
        core_freq = EXPECT_CORE_CLOCK_SF;
    }
    else if (((uint8)CPU_ID_SP0 == CoreId) || ((uint8)CPU_ID_SP1 == CoreId))
    {
        core_freq = EXPECT_CORE_CLOCK_SP;
    }
    else if (((uint8)CPU_ID_SX0 == CoreId) || ((uint8)CPU_ID_SX1 == CoreId))
    {
        core_freq = EXPECT_CORE_CLOCK_SX;
    }
    else
    {
        core_freq = 0U;
    }

    return core_freq;
}

void Mcu_Ip_SocResetBtm(void)
{
    /*deinit btm*/
    /* for some reason, the user enable the freeruning btm timer and interrupt
    register, when reset with the debuger, the core reset, but BTM module and
    VIC not reset, so a btm nterrupt signal will rise, after the vic enable but
    btm no register, the core will exception. */
    Mcu_Ip_SocBtmReset(APB_BTM1_BASE);
    Mcu_Ip_SocBtmReset(APB_BTM2_BASE);
    Mcu_Ip_SocBtmReset(APB_BTM3_BASE);
    Mcu_Ip_SocBtmReset(APB_BTM4_BASE);
#ifndef SEMIDRIVE_E3_LITE_SERIES
    Mcu_Ip_SocBtmReset(APB_BTM5_BASE);
    Mcu_Ip_SocBtmReset(APB_BTM6_BASE);
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/
}

void Mcu_Ip_SocResetLatentIp(Mcu_ModuleType m)
{
    switch (m)
    {
    case EPWM1:
        (void)Mcu_Ip_SocEpwmReset(APB_EPWM1_BASE);
        break;

    case EPWM2:
        (void)Mcu_Ip_SocEpwmReset(APB_EPWM2_BASE);
        break;
#ifndef SEMIDRIVE_E3_LITE_SERIES

    case EPWM3:
        (void)Mcu_Ip_SocEpwmReset(APB_EPWM3_BASE);
        break;

    case EPWM4:
        (void)Mcu_Ip_SocEpwmReset(APB_EPWM4_BASE);
        break;
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/

    case ETIMER1:
        (void)Mcu_Ip_SocEtimerReset(APB_ETMR1_BASE);
        break;

    case ETIMER2:
        (void)Mcu_Ip_SocEtimerReset(APB_ETMR2_BASE);
        break;
#ifndef SEMIDRIVE_E3_LITE_SERIES

    case ETIMER3:
        (void)Mcu_Ip_SocEtimerReset(APB_ETMR3_BASE);
        break;

    case ETIMER4:
        (void)Mcu_Ip_SocEtimerReset(APB_ETMR4_BASE);
        break;
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/

    default:
        /*do nothing*/
        break;
    }
}

Std_ReturnType Mcu_Ip_SocResetMailbox(void)
{
    boolean ret;
    Std_ReturnType errStatus = E_OK;

    uint32 baseAddrr = APB_GPV_SF_BASE ;
    uint32 u32EnST = REG_READ32(baseAddrr + BM_FUSA_INTEN_OFF);
    REG_WRITE32(~(BM_INTEN_BISTDONE | BM_INTEN_MISSIONFAULT), baseAddrr + BM_FUSA_INTEN_OFF);
    /*Set BistDoneClr */
    REG_WRITE32(BM_BISTCTL_BISTDONECLR, baseAddrr + BM_BISTCTL_OFF);
    /*Clear missionfault/bistdone int */
    REG_WRITE32(BM_INTCLR_LATENTFAULT | BM_INTCLR_MISSIONFAULT, baseAddrr + BM_FUSA_INTCLR_OFF);
    REG_RMW32(baseAddrr + BM_FUSA_INTEN_OFF, 0U, 2U, (u32EnST & 0x03U));
    /* Write 1 to BistCtrl.BistStart to start BIST */
    REG_WRITE32(BM_BISTCTL_BISTSTART, baseAddrr + BM_BISTCTL_OFF);
    ret = Mcu_Ip_WaitForBitTimes(baseAddrr + BM_BISTDONE_OFF, BM_BISTDONE_BISTDONE, 1U,
                                 MAILBOX_WAIT_TIME);

    if (FALSE == ret)
    {
        errStatus = MCU_E_TIMEOUT;
    }
    else
    {
        /* Clear missionfault/bistdone int */
        REG_WRITE32(BM_INTCLR_LATENTFAULT | BM_INTCLR_MISSIONFAULT, baseAddrr + BM_FUSA_INTCLR_OFF);
        REG_WRITE32(BM_BISTCTL_BISTDONECLR, baseAddrr + BM_BISTCTL_OFF);
    }

    return errStatus;
}

void Mcu_Ip_SocPowerGate(Mcu_PowerDomType m)
{
    switch (m)
    {
    case CR5_SF_DOM:
        Mcu_Ip_SocSafetyRamGate(APB_SMC_BASE, CR5_SF_RAM);
        Mcu_Ip_SocSafetyDomGate(APB_SMC_BASE, CR5_SF_DOM);
        break;

    case CR5_SX_DOM:
        Mcu_Ip_SocSafetyRamGate(APB_SMC_BASE, CR5_SX_RAM);
        Mcu_Ip_SocSafetyDomGate(APB_SMC_BASE, CR5_SX_DOM);
        break;

    case CR5_SP_DOM:
        Mcu_Ip_SocSafetyRamGate(APB_SMC_BASE, CR5_SP_RAM);
        Mcu_Ip_SocSafetyDomGate(APB_SMC_BASE, CR5_SP_DOM);
        break;

    case GAMA_DOM:
        Mcu_Ip_SocSafetyRamGate(APB_SMC_BASE, GAMA_RAM);
        Mcu_Ip_SocSafetyDomGate(APB_SMC_BASE, GAMA_DOM);
        break;
#ifndef SEMIDRIVE_E3_LITE_SERIES

    case AP_DOM:
        Mcu_Ip_SocApAnaGate();
        Mcu_Ip_SocApRamGate(APB_SMC_BASE);
        Mcu_Ip_SocApDomGate(APB_SMC_BASE);
        break;
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/

    default:
        /*do nothing*/
        break;
    }
}

#ifndef SEMIDRIVE_E3_LITE_SERIES
#if (MCU_RELEASE_DISPLAY_PIN == STD_ON)
void MCU_Ip_SocDispalyPadRelease(void)
{
    /* display mux need clr rterm_en if GPIOLx is not used for display */
    uint32 reg;

    for (uint32 i = 0U; i < 5U; i++)
    {
        reg = readl(APB_DISP_MUX_BASE + 0x1010U + (i * 4U));
        reg &= (uint32)(~(uint32)0x2U);
        writel(reg, APB_DISP_MUX_BASE + 0x1010U + (i * 4U));
    }
}
#endif /**#if (MCU_RELEASE_DISPLAY_PIN == STD_ON)*/
#endif

#if (STD_ON == MCU_APDOMAIN_POWERDOWN)
void Mcu_Ip_SocApDomPowerDown(void)
{
    uint8 CoreId = Mcu_GetCoreID();

    if (CoreId == CPU_ID_SF)
    {
        Mcu_Ip_SocPowerGate(AP_DOM);
    } /* else not needed */
}
#endif/**#if (STD_ON == MCU_APDOMAIN_POWERDOWN)*/

uint32 soc_to_dma_address(uint32 cpuAddr)
{
    uint32 dmaAddr = Mcal_AddressConvert(cpuAddr);

    return dmaAddr;
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif
/* End of file */
