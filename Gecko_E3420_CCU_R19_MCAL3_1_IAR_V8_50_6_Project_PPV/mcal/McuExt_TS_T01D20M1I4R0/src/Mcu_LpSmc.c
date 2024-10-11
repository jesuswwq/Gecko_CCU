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

#include "Std_Types.h"
#include "RegHelper.h"
#include "Mcu_ClkCfgNd.h"
#include "debug.h"
#include "Mcu_LpSmc.h"
#include "irq.h"
#include "Mcu_Soc.h"
#include "irq_num.h"
#include "Mcu_Extend.h"
#include "__regs_base.h"
#include "Mcu_UserCallouts.h"
#include "soc.h"
#include "McuExt_Cfg.h"
#include "Mcu_Mpu.h"

/* Version and Check Begin */
/* Version Info Begin */
#define MCU_SOC_C_VENDOR_ID    0x8C
#define MCU_SOC_C_AR_RELEASE_MAJOR_VERSION    4
#define MCU_SOC_C_AR_RELEASE_MINOR_VERSION    3
#define MCU_SOC_C_AR_RELEASE_REVISION_VERSION 1
#define MCU_SOC_C_SW_MAJOR_VERSION    1
#define MCU_SOC_C_SW_MINOR_VERSION    0
#define MCU_SOC_C_SW_PATCH_VERSION    0
/* Version Info End */

#define PCG_TYPE        0U
#define BCG_TYPE        1U
#define CCG_TYPE        2U

#define SF_PCG_NUM         334U
#define SF_BCG_NUM         15U
#define SF_CCG_NUM         5U
#ifndef SEMIDRIVE_E3_LITE_SERIES
#define AP_PCG_NUM         60U
#define AP_BCG_NUM         7U
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/

#ifdef __cplusplus
extern "C" {
#endif
extern const Mcu_SleepModeConfigType Mcu_SleepModecfg;
extern const Mcu_HibernateModeConfigType Mcu_HibernateModecfg;
//const Mcu_SleepModeConfigType Mcu_SleepModecfg;
//const Mcu_HibernateModeConfigType Mcu_HibernateModecfg;
#if ((MCU_HIBERNATE_MODE_API == STD_ON) || (MCU_SLEEP_MODE_API == STD_ON))
extern uint32 Mcu_GetXspiResetArraySize(void);

#define MCU_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"
#ifndef SEMIDRIVE_E3_LITE_SERIES
static Mcu_ClkRateType sf_clock, sp_clock, sx_clock, sf_m_clock, sp_m_clock, sf_ratio, sp_ratio;
#else
static Mcu_ClkRateType sf_clock, sf_m_clock, sf_ratio;
#endif
#define MCU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"
const char Mcu_ExtErrorInfo[64] = "mux data: need to debug the reasion";
#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

Std_ReturnType Mcu_Ip_CkgenXtalSetGatingByMode(uint32 base, uint8 lpMode, boolean en)
{
    uint32 xtalCtrl = base + CKGEN_XTAL_CTL;
    Std_ReturnType errStatus = MCU_E_PARAM_CONFIG;

    if ((CKGEN_RUN_MODE == lpMode) || (CKGEN_HIB_MODE == lpMode) || (CKGEN_SLP_MODE == lpMode))
    {
        RMWREG32(xtalCtrl, CKGEN_XTAL_CTL_IGNORE, 1U, 0U);
        RMWREG32(xtalCtrl, lpMode, 1U, en);
        errStatus = E_OK;
    } /* else not needed */

    return errStatus;
}

Std_ReturnType Mcu_CkgenXtalDis(uint8 mode, boolean onOff, uint8 ckgenSel)
{
    uint32 baseAddr = 0U;
    Std_ReturnType errStatus = E_NOT_OK;

    if (0U == ckgenSel)
    {
        baseAddr = APB_CKGEN_SF_BASE;
    }
#ifndef SEMIDRIVE_E3_LITE_SERIES
    else
    {
        baseAddr = APB_CKGEN_AP_BASE;
    }
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/

    if (0U != baseAddr)
    {
        errStatus = Mcu_Ip_CkgenXtalSetGatingByMode(baseAddr, mode, onOff);
    }

    return errStatus;
}

Std_ReturnType Mcu_Ip_CkgenPllSetGatingByMode(uint32 base, uint32 id, uint8 lpMode, boolean en)
{
    Std_ReturnType errStatus = MCU_E_PARAM_CONFIG;

    if ((CKGEN_RUN_MODE == lpMode) || (CKGEN_HIB_MODE == lpMode) || (CKGEN_SLP_MODE == lpMode))
    {
        uint32 pllCtrl = CKGEN_PLL_CTL_BASE(base, id);

        RMWREG32(pllCtrl, CKGEN_PLL_CTL_IGNORE, 1U, 0U);
        RMWREG32(pllCtrl, lpMode, 1U, en);
        errStatus = E_OK;
    } /* else not needed */

    return errStatus;
}

static Std_ReturnType Mcu_Ip_CkgenPllSetPdState(uint32 base, uint32 id, uint8 lpMode,
        boolean pdState)
{
    Std_ReturnType errStatus = MCU_E_PARAM_CONFIG;

    if ((lpMode == CKGEN_PD_RUN_MODE) || (lpMode == CKGEN_PD_HIB_MODE) || (lpMode == CKGEN_PD_SLP_MODE))
    {
        RMWREG32(CKGEN_PLL_CTL_BASE(base, id), lpMode, 1U, pdState);
        errStatus = E_OK;
    } /* else not needed */

    return errStatus;
}

Std_ReturnType Mcu_CkgenPllDis(uint8 mode, boolean onOff, uint8 ckgenSel, boolean disOrPd)
{
    uint32 baseAddr = 0U;
    uint32 index;
    Std_ReturnType errStatus;

    if (0U == ckgenSel)
    {
        baseAddr = APB_CKGEN_SF_BASE;
    }
#ifndef SEMIDRIVE_E3_LITE_SERIES
    else
    {
        baseAddr = APB_CKGEN_AP_BASE;
    }
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/

    if (0U != baseAddr)
    {
        for (index = 0U; index < 3U; index++)
        {
            errStatus = Mcu_Ip_CkgenPllSetGatingByMode(baseAddr, index, mode, onOff);
            errStatus = errStatus | Mcu_Ip_CkgenPllSetPdState(baseAddr, index, (mode + 4U), disOrPd);
        }
    }

    return errStatus;
}

Std_ReturnType Mcu_CkgenSfClkDis(uint8 mode, boolean onOff)
{
    uint32 baseAddr = APB_CKGEN_SF_BASE;
    Std_ReturnType errStatus = E_OK;
    uint32 index;
    uint32 i;

    //CCG
    index = ((uint32)CCG_TYPE << 24U);

    for (i = index; i < (index + SF_CCG_NUM); i++)
    {
        if (E_OK == errStatus)
        {
            errStatus = Mcu_CkgenXcgSetGatingByMode(baseAddr, i, mode, onOff);
        }
        else
        {
            break;
        }
    }

    //PCG CTL
    index = ((uint32)PCG_TYPE << 24U);

    for (i = index; i < (index + SF_PCG_NUM); i++)
    {
        if (E_OK == errStatus)
        {
            errStatus =  Mcu_CkgenXcgSetGatingByMode(baseAddr, i, mode, onOff);
        }
        else
        {
            break;
        }
    }

    //BCG
    index = ((uint32)BCG_TYPE << 24U);

    for (i = index; i < (index + SF_BCG_NUM); i++)
    {
        if (E_OK == errStatus)
        {
            errStatus = Mcu_CkgenXcgSetGatingByMode(baseAddr, i, mode, onOff);
        }
        else
        {
            break;
        }
    }

    return errStatus;

}
#ifndef SEMIDRIVE_E3_LITE_SERIES
Std_ReturnType Mcu_CkgenApClkDis(uint8 mode, boolean onOff)
{
    uint32 baseAddr = APB_CKGEN_AP_BASE;
    Std_ReturnType errStatus = E_OK;
    uint32 index;
    uint32 i;

    //PCG CTL
    index = ((uint32)PCG_TYPE << 24U);

    for (i = index; i < (index + AP_PCG_NUM); i++)
    {
        if (E_OK == errStatus)
        {
            errStatus = Mcu_CkgenXcgSetGatingByMode(baseAddr, i, mode, onOff);
        }
        else
        {
            break;
        }
    }

    //BCG
    index = ((uint32)BCG_TYPE << 24U);

    for (i = index; i < (index + AP_BCG_NUM); i++)
    {
        if (E_OK == errStatus)
        {
            errStatus = Mcu_CkgenXcgSetGatingByMode(baseAddr, i, mode, onOff);
        }
        else
        {
            break;
        }
    }

    return errStatus;
}
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/

Std_ReturnType Mcu_Ip_RstgenLldSetMissionResetByMode(uint32 base, uint32 index, uint32 mode,
        uint32 val)
{
    Std_ReturnType errStatus = MCU_E_PARAM_CONFIG;

    if (mode <= MISSION_RESET_CONTROL_SLP_MODE)
    {
        RMWREG32(base + MISSION_RESET_CONTROL_OFF(index), mode, 1U, val & 0x1U);
        errStatus = E_OK;
    } /* else not needed */

    return errStatus;
}

Std_ReturnType Mcu_Ip_RstgenLldSetLatentResetByMode(uint32 base, uint32 index, uint32 mode,
        uint32 val)
{
    Std_ReturnType errStatus = MCU_E_PARAM_CONFIG;

    if (mode <= LATENT_RESET_CONTROL_SLP_MODE)
    {
        RMWREG32(base + LATENT_RESET_CONTROL_OFF(index), mode, 1U, val & 0x1U);
        errStatus = E_OK;
    } /* else not needed */

    return errStatus;
}

Std_ReturnType Mcu_Ip_RstgenLldSetModuleResetByMode(uint32 base, uint32 index, uint32 mode,
        uint32 val)
{
    Std_ReturnType errStatus = MCU_E_PARAM_CONFIG;

    if (mode <= MODULE_RESET_CONTROL_SLP_MODE)
    {
        RMWREG32(base + MODULE_RESET_CONTROL_OFF(index), mode, 1U, val & 0x1U);
        errStatus = E_OK;
    } /* else not needed */

    return errStatus;
}

Std_ReturnType Mcu_Ip_RstgenLldSetCoreResetByMode(uint32 base, uint32 index, uint32 mode,
        uint32 val)
{
    Std_ReturnType errStatus = MCU_E_PARAM_CONFIG;

    if (mode <= CORE_RESET_CONTROL_SLP_MODE)
    {
        RMWREG32(base + CORE_RESET_CONTROL_OFF(index), mode, 1U, val & 0x1U);
        errStatus = E_OK;
    } /* else not needed */

    return errStatus;
}

static Std_ReturnType Mcu_Ip_ResetDrvLowPowerSet(const struct Mcu_PreResetCtlType *rstCtlPtr,
        uint32 id,
        Mcu_ResetLowpowerModeType mode, uint32 val)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;
    uint32 lpMode;

    if (NULL_PTR != rstCtlPtr)
    {
        if (RESET_LP_HIB == mode)
        {
            lpMode = 1U;
            errStatus = E_OK;
        }
        else if (RESET_LP_SLEEP == mode)
        {
            lpMode = 2U;
            errStatus = E_OK;
        }
        else
        {
            errStatus = MCU_E_PARAM_CONFIG;
        }

        if (E_OK == errStatus)
        {
            switch (MCU_RESET_TYPE(id))
            {
            case MCU_RESET_CORE:
                errStatus = Mcu_Ip_RstgenLldSetCoreResetByMode(rstCtlPtr->base, MCU_RESET_INDEX(id), lpMode, val);
                break;

            case MCU_RESET_MODULE:
                errStatus = Mcu_Ip_RstgenLldSetModuleResetByMode(rstCtlPtr->base, MCU_RESET_INDEX(id), lpMode, val);
                break;

            case MCU_RESET_MISSION:
                errStatus = Mcu_Ip_RstgenLldSetMissionResetByMode(rstCtlPtr->base, MCU_RESET_INDEX(id), lpMode,
                            val);
                break;

            case MCU_RESET_LATENT:
                errStatus = Mcu_Ip_RstgenLldSetLatentResetByMode(rstCtlPtr->base, MCU_RESET_INDEX(id), lpMode, val);
                break;

            default:
                errStatus = MCU_E_PARAM_CONFIG;
                break;
            }
        }
    }

    return errStatus;
}

/**
 * \brief Config reset signal assert/deassert in lowpower mode.
 *
 * \param[in] rstSigPtr Reset signal.
 * \param[in] mode lowpower mode
 * \param[in] val 0:assert, 1:deassert
 *
 * \return 0 if OK, or a negative error code.
 */
Std_ReturnType Mcu_ResetCtlLowpowerSet(const Mcu_ResetSigType *rstSigPtr,
        Mcu_ResetLowpowerModeType mode, uint32 val)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;
    const Mcu_ResetCtlType *ctlPtr;

    if (NULL_PTR != rstSigPtr)
    {
        ctlPtr = rstSigPtr->rstCtl;

        if ((NULL_PTR != ctlPtr))
        {

            errStatus = Mcu_Ip_ResetDrvLowPowerSet(ctlPtr, rstSigPtr->id, mode, val);

        } /* else not needed */
    } /* else not needed */

    return errStatus;
}

uint32 Mcu_RstgenLldGetSsRdy(uint32 base)
{
    uint32 glbRstCtrl;

    glbRstCtrl = readl(base + GLOBAL_RESET_CONTROL_OFF);

    return (glbRstCtrl >> GLOBAL_RESET_CONTROL_SS_RDY);
}


void Mcu_UnmaskModuleInterruptBit(Mcu_ModuleType m)
{
    uint32 maskbit = 0;
    uint32 irqgroup = 0;

    switch (m) {
    case UART1:
    case UART2:
    case UART3:
    case UART4:
    case UART5:
    case UART6:
    case UART7:
    case UART8:
    case UART9:
    case UART10:
    case UART11:
    case UART12:
    case UART13:
    case UART14:
    case UART15:
    case UART16:
        maskbit = (m - UART1 + UART1_INTR_NUM - 16 ) % 32;
        irqgroup = ( m - UART1 + UART1_INTR_NUM - 16 ) / 32;
        Mcu_SmcComIrqUnMaskConfig(APB_SMC_BASE, SMC_CORE_SF, irqgroup, maskbit);
        break;

    case CAN1:
    case CAN2:
    case CAN3:
    case CAN4:
    case CAN5:
    case CAN6:
    case CAN7:
    case CAN8:
    case CAN9:
    case CAN10:
    case CAN11:
    case CAN12:
    case CAN13:
    case CAN14:
    case CAN15:
    case CAN16:
    case CAN17:
    case CAN18:
    case CAN19:
    case CAN20:
    case CAN21:
    case CAN22:
    case CAN23:
    case CAN24:
#ifndef SEMIDRIVE_E3_LITE_SERIES
        maskbit = (m - CAN1 + CANFD1_CANFD_INTR_NUM - 16 ) % 32;
        irqgroup = ( m - CAN1 + CANFD1_CANFD_INTR_NUM - 16 ) / 32;
#else
        maskbit = (m - CAN1 + CANFD16_CANFD_INTR_NUM - 16 ) % 32;
        irqgroup = ( m - CAN1 + CANFD16_CANFD_INTR_NUM - 16 ) / 32;
#endif
        Mcu_SmcComIrqUnMaskConfig(APB_SMC_BASE, SMC_CORE_SF, irqgroup, maskbit);
        break;

    case ETH1:
    case ETH2:
        maskbit = (m - ETH1 + ETH1_SBD_INTR_NUM - 16 ) % 32;
        irqgroup = ( m - ETH1 + ETH1_SBD_INTR_NUM - 16 ) / 32;
        Mcu_SmcComIrqUnMaskConfig(APB_SMC_BASE, SMC_CORE_SF, irqgroup, maskbit);
        break;

    case BTM1:
    case BTM2:
    case BTM3:
    case BTM4:
    case BTM5:
    case BTM6:
        maskbit = (m - BTM1 + BTM1_O_BTM_INTR_NUM - 16 ) % 32;
        irqgroup = ( m - BTM1 + BTM1_O_BTM_INTR_NUM - 16 ) / 32;
        Mcu_SmcComIrqUnMaskConfig(APB_SMC_BASE, SMC_CORE_SF, irqgroup, maskbit);
        break;

    default:
        break;
    }
}

void Mcu_RstgenResetAssertConfig(Mcu_ResetLowpowerModeType mode)
{
    for (uint32 i = 0; i < Mcu_GetXspiResetArraySize(); i++) {
        Mcu_ResetCtlLowpowerSet((Mcu_ResetSigType *)Mcu_XspiResetArray[i], mode, 1);
    }
}


void Mcu_EnableModulePcg(unsigned int mode, unsigned int on_off, uint8 ckgen_sel, Mcu_ModuleType m)
{
    uint32 base_addr = 0U;

    if (ckgen_sel == 0) {
        base_addr = APB_CKGEN_SF_BASE;
    }

#ifndef SEMIDRIVE_E3_LITE_SERIES
    else  {
        base_addr = APB_CKGEN_AP_BASE;
    }



    switch (m) {
    case UART1:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart1_sclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart1_pclk.clkNode.id, mode, on_off);
        break;

    case UART2:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart2_sclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart2_pclk.clkNode.id, mode, on_off);
        break;

    case UART3:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart3_sclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart3_pclk.clkNode.id, mode, on_off);
        break;

    case UART4:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart4_sclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart4_pclk.clkNode.id, mode, on_off);
        break;

    case UART5:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart5_sclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart5_pclk.clkNode.id, mode, on_off);
        break;

    case UART6:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart6_sclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart6_pclk.clkNode.id, mode, on_off);
        break;

    case UART7:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart7_sclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart7_pclk.clkNode.id, mode, on_off);
        break;

    case UART8:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart8_sclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart8_pclk.clkNode.id, mode, on_off);
        break;

    case UART9:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart9_sclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart9_pclk.clkNode.id, mode, on_off);
        break;

    case UART10:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart10_sclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart10_pclk.clkNode.id, mode, on_off);
        break;

    case UART11:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart11_sclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart11_pclk.clkNode.id, mode, on_off);
        break;

    case UART12:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart12_sclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart12_pclk.clkNode.id, mode, on_off);
        break;

    case UART13:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart13_sclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart13_pclk.clkNode.id, mode, on_off);
        break;

    case UART14:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart14_sclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart14_pclk.clkNode.id, mode, on_off);
        break;

    case UART15:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart15_sclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart15_pclk.clkNode.id, mode, on_off);
        break;

    case UART16:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart16_sclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart16_pclk.clkNode.id, mode, on_off);
        break;

    case CAN1:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd1_pclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd1_ipg_clk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd1_clk24m.clkNode.id, mode, on_off);
        break;

    case CAN2:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd2_pclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd2_ipg_clk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd2_clk24m.clkNode.id, mode, on_off);
        break;

    case CAN3:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd3_pclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd3_ipg_clk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd3_clk24m.clkNode.id, mode, on_off);
        break;

    case CAN4:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd4_pclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd4_ipg_clk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd4_clk24m.clkNode.id, mode, on_off);
        break;

    case CAN5:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd5_pclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd5_ipg_clk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd5_clk24m.clkNode.id, mode, on_off);
        break;

    case CAN6:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd6_pclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd6_ipg_clk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd6_clk24m.clkNode.id, mode, on_off);
        break;

    case CAN7:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd7_pclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd7_ipg_clk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd7_clk24m.clkNode.id, mode, on_off);
        break;

    case CAN8:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd8_pclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd8_ipg_clk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd8_clk24m.clkNode.id, mode, on_off);
        break;

    case CAN9:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd9_pclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd9_ipg_clk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd9_clk24m.clkNode.id, mode, on_off);
        break;

    case CAN10:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd10_pclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd10_ipg_clk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd10_clk24m.clkNode.id, mode, on_off);
        break;

    case CAN11:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd11_pclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd11_ipg_clk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd11_clk24m.clkNode.id, mode, on_off);
        break;

    case CAN12:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd12_pclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd12_ipg_clk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd12_clk24m.clkNode.id, mode, on_off);
        break;

    case CAN13:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd13_pclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd13_ipg_clk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd13_clk24m.clkNode.id, mode, on_off);
        break;

    case CAN14:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd14_pclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd14_ipg_clk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd14_clk24m.clkNode.id, mode, on_off);
        break;

    case CAN15:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd15_pclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd15_ipg_clk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd15_clk24m.clkNode.id, mode, on_off);
        break;

    case CAN16:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd16_pclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd16_ipg_clk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd16_clk24m.clkNode.id, mode, on_off);
        break;

    case CAN17:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd17_pclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd17_ipg_clk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd17_clk24m.clkNode.id, mode, on_off);
        break;

    case CAN18:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd18_pclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd18_ipg_clk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd18_clk24m.clkNode.id, mode, on_off);
        break;

    case CAN19:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd19_pclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd19_ipg_clk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd19_clk24m.clkNode.id, mode, on_off);
        break;

    case CAN20:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd20_pclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd20_ipg_clk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd20_clk24m.clkNode.id, mode, on_off);
        break;

    case CAN21:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd21_pclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd21_ipg_clk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd21_clk24m.clkNode.id, mode, on_off);
        break;

    case CAN22:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd22_pclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd22_ipg_clk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd22_clk24m.clkNode.id, mode, on_off);
        break;

    case CAN23:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd23_pclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd23_ipg_clk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd23_clk24m.clkNode.id, mode, on_off);
        break;

    case CAN24:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd24_pclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd24_ipg_clk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd24_clk24m.clkNode.id, mode, on_off);
        break;

    case ETIMER1:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_etmr1_pclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_etmr1_ahf_clk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_etmr1_hf_clk.clkNode.id, mode, on_off);
        break;

    case ETIMER2:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_etmr2_pclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_etmr2_ahf_clk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_etmr2_hf_clk.clkNode.id, mode, on_off);
        break;

    case ETIMER3:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_etmr3_pclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_etmr3_ahf_clk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_etmr3_hf_clk.clkNode.id, mode, on_off);
        break;

    case ETIMER4:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_etmr4_pclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_etmr4_ahf_clk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_etmr4_hf_clk.clkNode.id, mode, on_off);
        break;

    case ETH1:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_adma_enet1_dmaclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_enet1_ref_clk_tx.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_enet1_ptp_ref_clk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_enet1_aclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_enet1_clk_csr.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_adma_enet1_perclk.clkNode.id, mode, on_off);
        break;

    case ETH2:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_adma_enet2_dmaclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_enet2_ref_clk_tx.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_enet2_ptp_ref_clk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_enet2_aclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_enet2_clk_csr.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_adma_enet2_perclk.clkNode.id, mode, on_off);
        break;

    case BTM1:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_btm1_pclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_btm1_i_xtal24mhz_clk.clkNode.id, mode,
                                     on_off);
        break;

    case BTM2:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_btm2_pclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_btm2_i_xtal24mhz_clk.clkNode.id, mode,
                                     on_off);
        break;

    case BTM3:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_btm3_pclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_btm3_i_xtal24mhz_clk.clkNode.id, mode,
                                     on_off);
        break;

    case BTM4:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_btm4_pclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_btm4_i_xtal24mhz_clk.clkNode.id, mode,
                                     on_off);
        break;

    case BTM5:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_btm5_pclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_btm5_i_xtal24mhz_clk.clkNode.id, mode,
                                     on_off);
        break;

    case BTM6:
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_btm6_pclk.clkNode.id, mode, on_off);
        Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_btm6_i_xtal24mhz_clk.clkNode.id, mode,
                                     on_off);
        break;

    default:
        break;
    }
#else
    if (0U != base_addr)
    {
        switch (m) {
        case UART1:
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart1_i_sclk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart1_i_pclk.clkNode.id, mode, on_off);
            break;

        case UART2:
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart2_i_sclk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart2_i_pclk.clkNode.id, mode, on_off);
            break;

        case UART3:
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart3_i_sclk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart3_i_pclk.clkNode.id, mode, on_off);
            break;

        case UART4:
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart4_i_sclk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart4_i_pclk.clkNode.id, mode, on_off);
            break;

        case UART5:
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart5_i_sclk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart5_i_pclk.clkNode.id, mode, on_off);
            break;

        case UART6:
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart6_i_sclk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart6_i_pclk.clkNode.id, mode, on_off);
            break;

        case UART7:
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart7_i_sclk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart7_i_pclk.clkNode.id, mode, on_off);
            break;

        case UART8:
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart8_i_sclk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart8_i_pclk.clkNode.id, mode, on_off);
            break;

        case UART9:
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart9_i_sclk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart9_i_pclk.clkNode.id, mode, on_off);
            break;

        case UART10:
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart10_i_sclk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart10_i_pclk.clkNode.id, mode, on_off);
            break;

        case UART11:
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart11_i_sclk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart11_i_pclk.clkNode.id, mode, on_off);
            break;

        case UART12:
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart12_i_sclk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_uart12_i_pclk.clkNode.id, mode, on_off);
            break;

        case CAN16:
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd1_pclk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd1_ipg_clk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd1_clk24m.clkNode.id, mode, on_off);
            break;

        case CAN21:
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd2_pclk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd2_ipg_clk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd2_clk24m.clkNode.id, mode, on_off);
            break;

        case CAN3:
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd3_pclk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd3_ipg_clk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd3_clk24m.clkNode.id, mode, on_off);
            break;

        case CAN4:
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd4_pclk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd4_ipg_clk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd4_clk24m.clkNode.id, mode, on_off);
            break;

        case CAN5:
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd5_pclk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd5_ipg_clk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd5_clk24m.clkNode.id, mode, on_off);
            break;

        case CAN6:
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd6_pclk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd6_ipg_clk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd6_clk24m.clkNode.id, mode, on_off);
            break;

        case CAN7:
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd7_pclk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd7_ipg_clk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd7_clk24m.clkNode.id, mode, on_off);
            break;

        case CAN23:
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd8_pclk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd8_ipg_clk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_canfd8_clk24m.clkNode.id, mode, on_off);
            break;

        case ETIMER1:
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_etmr1_pclk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_etmr1_ahf_clk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_etmr1_hf_clk.clkNode.id, mode, on_off);
            break;

        case ETIMER2:
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_etmr2_pclk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_etmr2_ahf_clk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_etmr2_hf_clk.clkNode.id, mode, on_off);
            break;

        case ETH1:
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_enet1_ref_clk_tx_i.clkNode.id, mode,
                                        on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_enet1_ptp_ref_clk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_enet1_aclk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_enet1_clk_csr_i.clkNode.id, mode, on_off);
            break;

        case BTM1:
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_btm1_i_pclk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_btm1_i_xtal24mhz_clk.clkNode.id, mode,
                                        on_off);
            break;

        case BTM2:
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_btm2_i_pclk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_btm2_i_xtal24mhz_clk.clkNode.id, mode,
                                        on_off);
            break;

        case BTM3:
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_btm3_i_pclk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_btm3_i_xtal24mhz_clk.clkNode.id, mode,
                                        on_off);
            break;

        case BTM4:
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_btm4_i_pclk.clkNode.id, mode, on_off);
            Mcu_CkgenXcgSetGatingByMode(base_addr, g_ckgen_gating_btm4_i_xtal24mhz_clk.clkNode.id, mode,
                                        on_off);
            break;

        default:
            break;
        }
    }
#endif
}

void Mcu_WakeupSourceEnableConfig(const soc_wkup_src_t *wkupsrc, const Mcu_ModuleType *ip)
{
    uint32 maskbit = 0;
    uint32 irqgroup = 0;

    if (NULL_PTR != wkupsrc) {
        /* RTC wakeup Enable Check */
        if ((NULL_PTR != wkupsrc->rtc) && (wkupsrc->rtcsrc == SMC_WAKEUP_SRC_ENABLE)) {

            /* rtc irq unmask config */
            if (wkupsrc->rtc->channel == ALL) {
                /* rtc1 irq unmask*/
                maskbit = ( RTC1_RTC_WAKEUP_INTR_NUM - 16 ) % 32;
                irqgroup = ( RTC1_RTC_WAKEUP_INTR_NUM - 16 ) / 32;
                Mcu_SmcComIrqUnMaskConfig(APB_SMC_BASE, SMC_CORE_SF, irqgroup, maskbit);
                /* rtc2 irq unmask*/
                maskbit = ( RTC2_RTC_WAKEUP_INTR_NUM - 16 ) % 32;
                irqgroup = ( RTC2_RTC_WAKEUP_INTR_NUM - 16 ) / 32;
                Mcu_SmcComIrqUnMaskConfig(APB_SMC_BASE, SMC_CORE_SF, irqgroup, maskbit);
            } else if (wkupsrc->rtc->channel == RTC2) {
                /* rtc2 irq unmask*/
                maskbit = ( RTC2_RTC_WAKEUP_INTR_NUM - 16 ) % 32;
                irqgroup = ( RTC2_RTC_WAKEUP_INTR_NUM - 16 ) / 32;
                Mcu_SmcComIrqUnMaskConfig(APB_SMC_BASE, SMC_CORE_SF, irqgroup, maskbit);
            } else {
                /* rtc1 irq unmask*/
                maskbit = ( RTC1_RTC_WAKEUP_INTR_NUM - 16 ) % 32;
                irqgroup = ( RTC1_RTC_WAKEUP_INTR_NUM - 16 ) / 32;
                Mcu_SmcComIrqUnMaskConfig(APB_SMC_BASE, SMC_CORE_SF, irqgroup, maskbit);
            }
        } else {
            ;
        }

        /* Gpio wakeup Enable Check */
        if ((NULL_PTR != wkupsrc->gpio) && (wkupsrc->gpiosrc == SMC_WAKEUP_SRC_ENABLE)) {

            /* GPIO_SF_Group0 */
            if (wkupsrc->gpio->sfgroup0 == TRUE) {
                /* smc irq unmask config */
                Mcu_SmcCoreIrqUnMaskConfig(APB_SMC_BASE, SMC_CORE_SF, GPIO_SF_ASYNC_GRP_0_INTR_NUM);
            } else {
                ;
            }

            /* GPIO_SF_Group1 */
            if (wkupsrc->gpio->sfgroup1 == TRUE) {
                /* smc irq unmask config */
                Mcu_SmcCoreIrqUnMaskConfig(APB_SMC_BASE, SMC_CORE_SF, GPIO_SF_ASYNC_GRP_1_INTR_NUM);
            } else {
                ;
            }

            /* GPIO_SF_Group2 */
            if (wkupsrc->gpio->sfgroup2 == TRUE) {
                /* smc irq unmask config */
                Mcu_SmcCoreIrqUnMaskConfig(APB_SMC_BASE, SMC_CORE_SF, GPIO_SF_ASYNC_GRP_2_INTR_NUM);
            } else {
                ;
            }

            /* GPIO_SF_Group3 */
            if (wkupsrc->gpio->sfgroup3 == TRUE) {
                /* smc irq unmask config */
                Mcu_SmcCoreIrqUnMaskConfig(APB_SMC_BASE, SMC_CORE_SF, GPIO_SF_ASYNC_GRP_3_INTR_NUM);
            } else {
                ;
            }
#ifndef SEMIDRIVE_E3_LITE_SERIES
            /* GPIO_SF_Group4 */
            if (wkupsrc->gpio->sfgroup4 == TRUE) {
                /* smc irq unmask config */
                Mcu_SmcCoreIrqUnMaskConfig(APB_SMC_BASE, SMC_CORE_SF, GPIO_SF_ASYNC_GRP_4_INTR_NUM);
            } else {
                ;
            }

            /* GPIO_AP_Group0 */
            if (wkupsrc->gpio->apgroup0 == TRUE) {
                /* smc irq unmask config */
                Mcu_SmcCoreIrqUnMaskConfig(APB_SMC_BASE, SMC_CORE_SF, GPIO_AP_ASYNC_GRP_0_INTR_NUM);
            } else {
                ;
            }

            /* GPIO_AP_Group1 */
            if (wkupsrc->gpio->apgroup1 == TRUE) {
                /* smc irq unmask config */
                Mcu_SmcCoreIrqUnMaskConfig(APB_SMC_BASE, SMC_CORE_SF, GPIO_AP_ASYNC_GRP_1_INTR_NUM);
            } else {
                ;
            }

            /* GPIO_AP_Group2 */
            if (wkupsrc->gpio->apgroup2 == TRUE) {
                /* smc irq unmask config */
                Mcu_SmcCoreIrqUnMaskConfig(APB_SMC_BASE, SMC_CORE_SF, GPIO_AP_ASYNC_GRP_2_INTR_NUM);
            } else {
                ;
            }
#endif
            /* async gpio for smc */
            if ((wkupsrc->gpio->sfgroup0 == TRUE) || (wkupsrc->gpio->sfgroup1 == TRUE)
                || (wkupsrc->gpio->sfgroup2 == TRUE) || (wkupsrc->gpio->sfgroup3 == TRUE)
                || (wkupsrc->gpio->sfgroup4 == TRUE)) {
                maskbit = ( SAF_SF_ASYNC_GRP_IRQ_NUM - 16 ) % 32;
                irqgroup = ( SAF_SF_ASYNC_GRP_IRQ_NUM - 16 ) / 32;
                Mcu_SmcComIrqUnMaskConfig(APB_SMC_BASE, SMC_CORE_SF, irqgroup, maskbit);
            }
#ifndef SEMIDRIVE_E3_LITE_SERIES
            else if ((wkupsrc->gpio->apgroup0 == TRUE) || (wkupsrc->gpio->apgroup1 == TRUE)
                       || (wkupsrc->gpio->apgroup2 == TRUE)) {

                maskbit = ( SAF_AP_ASYNC_GRP_IRQ_NUM - 16 ) % 32;
                irqgroup = ( SAF_AP_ASYNC_GRP_IRQ_NUM - 16 ) / 32;
                Mcu_SmcComIrqUnMaskConfig(APB_SMC_BASE, SMC_CORE_SF, irqgroup, maskbit);
            }
#endif
            else {
                ;
            }
        }
    }

    /* ip Wakeup Enable Check */
    if (NULL_PTR != ip) {
        const Mcu_ModuleType *pModule = ip;

        /* ip wakeup interrupt unmask */
        for (; *pModule != MODULE_END; pModule++) {
            Mcu_UnmaskModuleInterruptBit(*pModule);
        }
    } else {
        /* set 24M to off*/
    }
}

void Mcu_SmcAllIrqMaskConfig(void)
{
    uint32 cnt;

    /* mask all core irq */
    for ( cnt = 0; cnt < 5; cnt = cnt + 1) {
        Mcu_SmcCoreIrqMaskConfig(APB_SMC_BASE, cnt, SMC_CORE_IRQ_MASK);
    }

    /* mask all common irq */
    for ( cnt = 0; cnt < 5; cnt = cnt + 1) {
        Mcu_SmcComIrqMaskConfig(APB_SMC_BASE, cnt, SMC_COMM_IRQ_0, SMC_COMM_IRQ_MASK);
        Mcu_SmcComIrqMaskConfig(APB_SMC_BASE, cnt, SMC_COMM_IRQ_1, SMC_COMM_IRQ_MASK);
        Mcu_SmcComIrqMaskConfig(APB_SMC_BASE, cnt, SMC_COMM_IRQ_2, SMC_COMM_IRQ_MASK);
        Mcu_SmcComIrqMaskConfig(APB_SMC_BASE, cnt, SMC_COMM_IRQ_3, SMC_COMM_IRQ_MASK);
        Mcu_SmcComIrqMaskConfig(APB_SMC_BASE, cnt, SMC_COMM_IRQ_4, SMC_COMM_IRQ_MASK);
        Mcu_SmcComIrqMaskConfig(APB_SMC_BASE, cnt, SMC_COMM_IRQ_5, SMC_COMM_IRQ_MASK);
        Mcu_SmcComIrqMaskConfig(APB_SMC_BASE, cnt, SMC_COMM_IRQ_6, SMC_COMM_IRQ_MASK);
        Mcu_SmcComIrqMaskConfig(APB_SMC_BASE, cnt, SMC_COMM_IRQ_7, SMC_COMM_IRQ_MASK);
    }
}

void Mcu_SoCPowerGateConfig(const smc_ctrl_t *smc, uint8 lpmode)
{
    /* Note:
         If config core and core ram to power down, user need to check: whether need to save core
       and core ram data and  and resume it after wakeup.
    */
    uint32 b = APB_SMC_BASE;

    /* saf primary core set */
    Mcu_SmcSafPriCoreConfig(b, 0);

    if (MCU_MODE_HIB == lpmode) {
        /* core power down config */
        /* If sf/sp/sx power switch to off in sleep/hibernate mode,need:
           1. change the cpu clock to fs_24m
           2. then set SAF_LP_DLY_CTL_ISO_DIS at least 4 counter
           3. rechange the cpu clock to pll when wakeup from sleep/hibernate.
        */
        Mcu_SmcSafLpConfig(b, SMC_HIB_MODE, SMC_CORE_SF, smc->saf->sfpd);
#ifndef SEMIDRIVE_E3_LITE_SERIES
        Mcu_SmcSafLpConfig(b, SMC_HIB_MODE, SMC_CORE_SP, smc->saf->sppd);
        Mcu_SmcSafLpConfig(b, SMC_HIB_MODE, SMC_CORE_SX, smc->saf->sxpd);
        Mcu_SmcSafLpConfig(b, SMC_HIB_MODE, SMC_CORE_GAMA1, smc->saf->gama3pd);

        /* ap & disp power gated */
        Mcu_SmcApLpConfig(b, SMC_HIB_MODE, smc->ap->appd);
#endif
        /* core ram power down config */
        Mcu_SmcSafRampdSettingConfig(b, SMC_HIB_MODE,
                                     SMC_RAM_LP_PG_EN | SMC_RAM_LP_RET1N | SMC_RAM_LP_RET2N,
                                     SMC_CORE_SF);
        Mcu_SmcSafRampdConfig(b, SMC_HIB_MODE, smc->saf->sfram, SMC_CORE_SF);
#ifndef SEMIDRIVE_E3_LITE_SERIES
        Mcu_SmcSafRampdSettingConfig(b, SMC_HIB_MODE,
                                     SMC_RAM_LP_PG_EN | SMC_RAM_LP_RET1N | SMC_RAM_LP_RET2N,
                                     SMC_CORE_SP);
        Mcu_SmcSafRampdConfig(b, SMC_HIB_MODE, smc->saf->spram, SMC_CORE_SP);

        Mcu_SmcSafRampdSettingConfig(b, SMC_HIB_MODE,
                                     SMC_RAM_LP_PG_EN | SMC_RAM_LP_RET1N | SMC_RAM_LP_RET2N,
                                     SMC_CORE_SX);
        Mcu_SmcSafRampdConfig(b, SMC_HIB_MODE, smc->saf->sxram, SMC_CORE_SX);

        Mcu_SmcSafRampdSettingConfig(b, SMC_HIB_MODE,
                                     SMC_RAM_LP_PG_EN | SMC_RAM_LP_RET1N | SMC_RAM_LP_RET2N,
                                     SMC_CORE_GAMA1);
        Mcu_SmcSafRampdConfig(b, SMC_HIB_MODE, smc->saf->gama1ram, SMC_CORE_GAMA1);

        Mcu_SmcSafRampdSettingConfig(b, SMC_HIB_MODE,
                                     SMC_RAM_LP_PG_EN | SMC_RAM_LP_RET1N | SMC_RAM_LP_RET2N,
                                     SMC_SAF_MISC);
        Mcu_SmcSafRampdConfig(b, SMC_HIB_MODE, smc->saf->safmisc, SMC_SAF_MISC);

        Mcu_SmcApRampdSettingConfig(b, SMC_HIB_MODE, SMC_RAM_LP_PG_EN | SMC_RAM_LP_RET1N | SMC_RAM_LP_RET2N,
                                    SMC_CORE_DISP);
        Mcu_SmcApRampdConfig(b, SMC_HIB_MODE, smc->ap->apram, SMC_CORE_DISP);
#endif
    } else {
        ;
    }
#ifndef SEMIDRIVE_E3_LITE_SERIES
    /* ap primary core set */
    Mcu_SmcApPriCoreConfig(b, 0);
#endif
    /* soc wakeup irq config */
    Mcu_SmcSocWkupirqWkupConfig(b, 0x1F, 0x1F);
#ifndef SEMIDRIVE_E3_LITE_SERIES
    /* ap lp align with saf */
    Mcu_SmcApLpAlignSafConfig(b, smc->ap->lp);

    /* ap wakeup align with saf */
    Mcu_SmcApWkupAlignSafConfig(b, smc->ap->wkup);

#if (STD_OFF == MCU_APDOMAIN_POWERDOWN)
#if (STD_OFF == MCU_PLL4_POWERDOWN)
    /* ap off */
    Mcu_SmcSocGlobalConfig(b, SMC_AP_ON);
#else
    Mcu_SmcSocGlobalConfig(b, SMC_AP_OFF);
#endif
#else
    Mcu_SmcSocGlobalConfig(b, SMC_AP_OFF);
#endif
#endif
}

void Mcu_SoCEnterLpConfig(const smc_ctrl_t *smc)
{
    uint32 b = APB_SMC_BASE;
#ifndef SEMIDRIVE_E3_LITE_SERIES
    if ((smc != NULL_PTR) && (smc->saf != NULL_PTR) && (smc->ap != NULL_PTR)) {
        /* saf wfi enable & low power mode */
        Mcu_SmcSafWfiConfig(b, SMC_WFI_ENABLE, smc->saf->saflp);

        /* ap wfi enable & low power mode */
        Mcu_SmcApWfiConfig(b, SMC_WFI_ENABLE, smc->ap->aplp);
    }
#else
    if ((smc != NULL_PTR) && (smc->saf != NULL_PTR)) {
        /* saf wfi enable & low power mode */
        Mcu_SmcSafWfiConfig(b, SMC_WFI_ENABLE, smc->saf->saflp);
    }
#endif
}

void Mcu_ActionToWfi(uint8 mode)
{
    DSB;
    ISB;
    __asm volatile ("wfi");

    DBG("wk from lowpower mode: %d\n", mode);
}

void Mcu_CkgenClockDisableConfig(uint8 mode, const soc_ckgen_t *ckgen, const Mcu_ModuleType *ip)
{
    uint32 counter = 0x0U;
    unsigned int ckgen_mode = CKGEN_RUN_MODE;

    if (mode == MCU_MODE_SLP ) {
        ckgen_mode = CKGEN_SLP_MODE;

    } else if (mode == MCU_MODE_HIB) {
        ckgen_mode = CKGEN_HIB_MODE;
    } else {
        ;
    }

    if (ckgen_mode != CKGEN_RUN_MODE) {
        /* domain clock gate */
        Mcu_CkgenSfClkDis(ckgen_mode, 0);
#ifndef SEMIDRIVE_E3_LITE_SERIES
        Mcu_CkgenApClkDis(ckgen_mode, 0);
#endif
        /* xtal clock gate */
        if ((NULL_PTR != ckgen) && (ckgen->xtal_24 == SOC_CKGEN_24M_OFF)) {
            Mcu_CkgenXtalDis(ckgen_mode, 0, CKGEN_SAF);
#ifndef SEMIDRIVE_E3_LITE_SERIES
            Mcu_CkgenXtalDis(ckgen_mode, 0, CKGEN_AP);
#endif
        }

        /* RC24M disable in hibernate state */
        if ((ckgen != NULL_PTR) && (ckgen_mode == CKGEN_HIB_MODE) && (ckgen->rc_24 == SOC_CKGEN_24M_OFF)) {
            Mcu_SmcSocHibrcDisConfig(APB_SMC_BASE, SMC_RC_DIS_ENABLE);
        }

        /* enable wakeup module list ckgen and pll */
        if (ip != NULL_PTR) {
            const Mcu_ModuleType *module = ip;

            for (; *module != MODULE_END; module++) {
                Mcu_EnableModulePcg(ckgen_mode, 1, CKGEN_SAF, *module);
#ifndef SEMIDRIVE_E3_LITE_SERIES
                Mcu_EnableModulePcg(ckgen_mode, 1, CKGEN_AP, *module);
#endif
                counter++;
            }
        }

        /* enable all pll, Because different part peripherals in different pll */
        if (0x0U == counter) {
            /* pll clock power down */
            Mcu_CkgenPllDis(ckgen_mode, 0, CKGEN_SAF, (ckgen_mode == CKGEN_HIB_MODE) ? 0x1U : 0x0U);
#ifndef SEMIDRIVE_E3_LITE_SERIES
            Mcu_CkgenPllDis(ckgen_mode, 0, CKGEN_AP,  (ckgen_mode == CKGEN_HIB_MODE) ? 0x1U : 0x0U);
#endif
        }

    }
}

void Mcu_IramPowerConfig(const soc_iramc_pwr_mode_t *iram)
{
    /* Note:
         If config iram1/2/3/4 to power down, user need to check: whether need to save iram data
       and resume it after wakeup.
    */

    /* iram1 power mode config */
    Mcu_IramcPowerCfg(APB_IRAMC1_BASE, iram->iram1);
#ifndef SEMIDRIVE_E3_LITE_SERIES
    /* iram2 power mode config */
    Mcu_IramcPowerCfg(APB_IRAMC2_BASE, iram->iram2);

    /* iram3 power mode config */
    Mcu_IramcPowerCfg(APB_IRAMC3_BASE, iram->iram3);

    /* iram4 power mode config */
    Mcu_IramcPowerCfg(APB_IRAMC4_BASE, iram->iram4);
#endif
}

/*
wakeup event is asserted at the end of lp handshake with rstgen/ckgen and before pmu
SMC may wake up rstgen/ckgen meanwhile request PMU to sleep.
SW should add this work around to all wakeup irq handlers if lowpower sequence is enable.
wakeup irq handler:
Step-1: check smc_dbg_mon(sf):
                                {12'b0,
                                saf_rstgen_swm_ack,saf_rstgen_swm_i[3:0],
                                saf_rstgen_swm_req,saf_rstgen_swm_o[3:0],
                                saf_ckgen_swm_ack,saf_ckgen_swm_i[3:0],
                                saf_ckgen_swm_req,saf_ckgen_swm_o[3:0]}

Possible Values
-- 0x0: ckgen_sf and rstgen_sf lowpower sequence haven't started, lowpower sequence abort
-- 0x21: ckgen_sf has entered lowpower and wakeup to RUN state, rstgen_sf lowpower hasn't started, SMC lowpower sequence abort.
-- 0x8421: ckgen_sf and rstgen_sf have entered lowpower state and woken up to RUN state
-- other values: un-expected failure

SW action
-- 0x0|0x21|0x8421: go ahead
-- other values: exception, need to debug

Step-2: check smc_dbg_mon(ap):
                                {12'b0,
                                ap_rstgen_swm_ack,ap_rstgen_swm_i[3:0],
                                ap_rstgen_swm_req,ap_rstgen_swm_o[3:0],
                                ap_ckgen_swm_ack,ap_ckgen_swm_i[3:0],
                                ap_ckgen_swm_req,ap_ckgen_swm_o[3:0]}
Possible Values
-- 0x0: ckgen_ap and ckgen_ap lowpower sequence haven't started, lowpower sequence abort
-- 0x21: ckgen_ap has entered lowpower and wakeup to RUN state, rstgen_ap lowpower hasn't start, SMC lowpower sequence abort.
-- 0x421: AP was reset, and AP lowpower seq is abort at this time (ckgen_ap entered lowpower and wakeup to RUN, rstgen_ap not start)
-- 0x401: ckgen_ap and rstgen_ap entered lowpower and wakeup to RUN, then AP domain was reset, and AP lowpower sequence hasn't start at this time
-- 0x8421: ckgen_ap and rstgen_ap have entered lowpower state and wake up to RUN state
-- other values: un-expected failure

SW action
-- 0x0|0x21|0x421|0x401|0x8421: go ahead
-- other values: exception, need to debug

Step-3: check smc_dbg_mon(pmu):
                                {22'b0,
                                pmu_swm_ack,pmu_swm_i[3:0],
                                pmu_swm_req,pmu_swm_o[3:0]}

Possible Values
-- 0x21: PMU is in RUN state
-- 0x32|0x34: smc sending swm_req = slp/hib, but PMU hasn't ACK
-- 0x242|0x284: at the end of lp handshake, smc has de-assert swm_req, PMU swm_ack still 1
-- 0x42|0x84: lowpower handshake is done, PMU is in sleep or hibernate state now
-- other values: exception, need to debug

SW action
-- 0x32|0x34|0x242|0x284:
1. Polling smc_dbg_mon = 0x42|0x84 to wait PMU lowpower handshake done
2. Configure SMC sw_swm register to send RUN request to PMU manually (sw_swm_en bit must be clear after handshake done)
3. Polling smc_dbg_mon = 0x21 to wait PMU wakeup handshake done
4. Polling ap_ss_rdy = 1 if AP power|ap_por_b is configured to OFF in lowpower state
-- 0x42|0x84: 2 ~ 4 steps above
-- 0x21: go ahead
-- other values: exception, need to debug"
 */
void Mcu_SmcSwmCheckAfterExitWfi(void)
{
    uint32 rdata = 0;
    uint32 timeout = 0;

#ifdef SEMIDRIVE_E3_LITE_SERIES
    /* e3l 1.1 smc bug has been fixed*/
    if  (Mcu_GetChipVersion() != 0x0U)
    {
        return;
    }
#endif
    Mcu_SmcSetDebugMuxSelectMode(APB_SMC_BASE, SMC_DBG_HK_SAF);
    rdata = Mcu_SmcGetDebugMonitorStatus(APB_SMC_BASE);

    if ((rdata != 0x00) && (rdata != 0x21) && (rdata != 0x8421)) {
        ERROR("%s", Mcu_ExtErrorInfo);
    } else {
        ;
    }

    Mcu_SmcSetDebugMuxSelectMode(APB_SMC_BASE, SMC_DBG_HK_AP);
    rdata = Mcu_SmcGetDebugMonitorStatus(APB_SMC_BASE);

    if ((rdata != 0x00) && (rdata != 0x21) && (rdata != 0x421) && (rdata != 0x401)
        && (rdata != 0x8421)) {
        ERROR("%s", Mcu_ExtErrorInfo);
    } else {
        ;
    }

    Mcu_SmcSetDebugMuxSelectMode(APB_SMC_BASE, SMC_DBG_HK_PMU);
    rdata = Mcu_SmcGetDebugMonitorStatus(APB_SMC_BASE);

    if ((rdata == 0x32) || (rdata == 0x34) || (rdata == 0x242) || (rdata == 0x284) || (rdata == 0x221)
        || (rdata == 0x294) || (rdata == 0x252)) {
        while (((Mcu_SmcGetDebugMonitorStatus(APB_SMC_BASE)) != 0x42)
               && ((Mcu_SmcGetDebugMonitorStatus(APB_SMC_BASE)) != 0x84) && (timeout++ < 1000U));

        Mcu_SmcSetPmuSwSwmMode(APB_SMC_BASE, 0x0);

        timeout = 0;

        while (((Mcu_SmcGetDebugMonitorStatus(APB_SMC_BASE)) != 0x21) && (timeout++ < 1000U));
#ifndef SEMIDRIVE_E3_LITE_SERIES
        timeout = 0;

        while (((Mcu_RstgenLldGetSsRdy(APB_RSTGEN_AP_BASE)) != 1) && (timeout++ < 1000U));
#endif
    } else if ((rdata == 0x42) || (rdata == 0x84)) {
        Mcu_SmcSetPmuSwSwmMode(APB_SMC_BASE, 0x0);

        while (((Mcu_SmcGetDebugMonitorStatus(APB_SMC_BASE)) != 0x21) && (timeout++ < 1000U));
#ifndef SEMIDRIVE_E3_LITE_SERIES
        timeout = 0;

        while (((Mcu_RstgenLldGetSsRdy(APB_RSTGEN_AP_BASE)) != 1) && (timeout++ < 1000U));
#endif
    } else {
        if ((rdata != 0x21)) {
            ERROR("%s", Mcu_ExtErrorInfo);
        } else {
            ;
        }
    }

    if (timeout >= 1000U)
        ERROR("%s", Mcu_ExtErrorInfo);
}

void Mcu_SmcSwitchClockTo24Mhz(void)
{
    Mcu_ClkNodeType *clk = NULL_PTR;

    /*  switch clock to 24m  */
    sf_ratio = REG_READ32(APB_CKGEN_SF_BASE + CKGEN_RES) & (1 << CKGEN_RES_RS_SF_RATIO_SEL);
    clk = CLK_NODE(g_ckgen_bus_cr5_sf_div_root);
    sf_clock = Mcu_ClkGetRate(clk);
    clk = CLK_NODE(g_ckgen_bus_cr5_sf_div_m);
    sf_m_clock = Mcu_ClkGetRate(clk);

    clk = CLK_NODE(g_ckgen_bus_cr5_sf_div_root_preset);
    Mcu_ClkSetRate(clk, 24000000);
#ifndef SEMIDRIVE_E3_LITE_SERIES
    sp_ratio = (REG_READ32(APB_CKGEN_SF_BASE + CKGEN_RES) & (1 << CKGEN_RES_RS_SP_RATIO_SEL)) >> CKGEN_RES_RS_SP_RATIO_SEL;
    clk = CLK_NODE(g_ckgen_bus_cr5_sp_div_root);
    sp_clock = Mcu_ClkGetRate(clk);
    clk = CLK_NODE(g_ckgen_bus_cr5_sp_div_m);
    sp_m_clock = Mcu_ClkGetRate(clk);

    clk = CLK_NODE(g_ckgen_bus_cr5_sp_div_root_preset);
    Mcu_ClkSetRate(clk, 24000000);

    clk = CLK_NODE(g_ckgen_core_cr5_sx);
    sx_clock = Mcu_ClkGetRate(clk);
    Mcu_ClkSetRate(clk, 24000000);
#endif
}

void Mcu_SmcSwitchClockToNormal(void)
{
    Mcu_ClkNodeType *clk = NULL_PTR;

    /* set core:axi:apb ratio to default 4:2:1*/
    RMWREG32(APB_CKGEN_SF_BASE + CKGEN_RES, CKGEN_RES_RS_SF_RATIO_SEL, 2u, 0);

    /*  switch clock to normal  */
    clk = CLK_NODE(g_ckgen_bus_cr5_sf_div_root);
    Mcu_ClkSetRate(clk, sf_clock);

    clk = CLK_NODE(g_ckgen_bus_cr5_sf_div_m);
    Mcu_ClkSetRate(clk, sf_m_clock);

    RMWREG32(APB_CKGEN_SF_BASE + CKGEN_RES, CKGEN_RES_RS_SF_RATIO_SEL, 1u, sf_ratio);
#ifndef SEMIDRIVE_E3_LITE_SERIES
    clk = CLK_NODE(g_ckgen_bus_cr5_sp_div_root);
    Mcu_ClkSetRate(clk, sp_clock);

    clk = CLK_NODE(g_ckgen_bus_cr5_sp_div_m);
    Mcu_ClkSetRate(clk, sp_m_clock);

    RMWREG32(APB_CKGEN_SF_BASE + CKGEN_RES, CKGEN_RES_RS_SP_RATIO_SEL, 1u, sp_ratio);

    clk = CLK_NODE(g_ckgen_core_cr5_sx);
    Mcu_ClkSetRate(clk, sx_clock);

#if (STD_OFF == MCU_APDOMAIN_POWERDOWN)
    /*restore AP domain clk*/
    Mcu_Ip_ClkPrepare(CLK_NODE(g_pll4_root));
    Mcu_Ip_ClkPrepare(CLK_NODE(g_pll5_root));
    Mcu_Ip_ClkPrepare(CLK_NODE(g_pll_lvds_root));
    Mcu_Ip_ClkPrepare(CLK_NODE(g_pll_lvds_nodiv));
    Mcu_Ip_ClkPrepare(CLK_NODE(g_pll_lvds_div2));
    Mcu_Ip_ClkPrepare(CLK_NODE(g_pll_lvds_div7));
    Mcu_Ip_ClkPrepare(CLK_NODE(g_pll_lvds_ckgen));
    Mcu_Ip_ClkPrepare(CLK_NODE(g_ckgen_bus_ap_bus_div_root));
    Mcu_Ip_ClkPrepare(CLK_NODE(g_ckgen_bus_ap_bus_div_p));
    Mcu_Ip_ClkPrepare(CLK_NODE(g_ckgen_bus_ap_bus_div_n));
    Mcu_Ip_ClkPrepare(CLK_NODE(g_ckgen_bus_ap_bus_root));
#if (STD_OFF == MCU_PLL4_POWERDOWN)
    Mcu_Ip_ClkPrepare(CLK_NODE(g_ckgen_bus_seip_div_root));
    Mcu_Ip_ClkPrepare(CLK_NODE(g_ckgen_bus_seip_div_p));
    Mcu_Ip_ClkPrepare(CLK_NODE(g_ckgen_bus_seip_div_n));
    Mcu_Ip_ClkPrepare(CLK_NODE(g_ckgen_bus_seip_root));
    Mcu_Ip_ClkPrepare(CLK_NODE(g_ckgen_ip_reserved));
    Mcu_Ip_ClkPrepare(CLK_NODE(g_ckgen_ip_seip_test));
#endif
#ifdef MCU_PVT_AP_ENABLE
    Mcu_Ip_ClkPrepare(CLK_NODE(g_ckgen_ip_pt_sns_ap));
#endif
    Mcu_Ip_ClkPrepare(CLK_NODE(g_ckgen_ip_ap_test));
#endif
#if (STD_ON == MCU_PLL4_POWERDOWN)
    Mcu_Ip_ClkDisable(CLK_NODE(g_pll4_root));
#endif
#if (STD_ON == MCU_PLL5_POWERDOWN)
    Mcu_Ip_ClkDisable(CLK_NODE(g_pll5_root));
#endif
#if (STD_ON == MCU_PLL_LVDS_POWERDOWN)
    Mcu_Ip_ClkDisable(CLK_NODE(g_pll_lvds_root));
#endif
#endif
}

FUNC(void, MCU_CODE) Mcu_SetLpMode(
    VAR(Mcu_LpModeType, AUTOMATIC) McuMode
)
{
    const Mcu_SleepModeConfigType *pSleepModeCfg =  &Mcu_SleepModecfg;
    const Mcu_HibernateModeConfigType *pHibernateModeCfg = &Mcu_HibernateModecfg;

    /* Enter sleep mode process */
    if ((MCU_MODE_SLP == McuMode) && (NULL_PTR != pSleepModeCfg)) {

        if (Mcu_GetCoreID() == CPU_ID_SF) {

            /*  mask all smc irq */
            Mcu_SmcAllIrqMaskConfig();

            /* wakeup source configuration */
            /* PRQA S 2995 2*/
            Mcu_WakeupSourceEnableConfig(pSleepModeCfg->wksrc,
                                            pSleepModeCfg->wkip);

            /* saf domain, ap domain and SoC lowpower Config*/
            if ((NULL_PTR != pSleepModeCfg->smc)) {
                Mcu_SoCEnterLpConfig(pSleepModeCfg->smc);
            }

            /* disable RTC parity error interrupt status, because low power need disable RTC pclk */
            Mcu_RtcDisableRegParityErrIntEnable(APB_RTC1_BASE);
            Mcu_RtcDisableRegParityErrIntEnable(APB_RTC2_BASE);

            /* rtc wakeup config*/
            if ((NULL_PTR != pSleepModeCfg->wksrc)
                && (NULL_PTR != pSleepModeCfg->wksrc->rtc)) {
                Mcu_RtcWakeupConfig(&Mcu_PwrRtcSleepTime[MCU_MODE_SLP],
                                    pSleepModeCfg->wksrc->rtc);
            }

            /*  switch clock to 24m  */
            Mcu_SmcSwitchClockTo24Mhz();

            /* Start Enter Wfi*/
            Mcu_ActionToWfi(McuMode);

            /* check saf/ap/pmu swm status */
            Mcu_SmcSwmCheckAfterExitWfi();

            /* store cpu clock */
            Mcu_SmcSwitchClockToNormal();

            /* store RTC parity error interrupt status */
            Mcu_RtcEnableRegParityErrIntEnable(APB_RTC1_BASE);
            Mcu_RtcEnableRegParityErrIntEnable(APB_RTC2_BASE);

        } else {
            /* Save the current CPU CPSR.I to avoid the failure to enter low power due
                to exiting the wfi state due to interruption */
            IRQ_SAVE
            /* Start Enter Wfi*/
            Mcu_ActionToWfi(McuMode);
            /* Resume CPU CPSR.I */
            IRQ_RESTORE
        }

    }
    /* Enter hibernate mode process */
    else if ((MCU_MODE_HIB == McuMode) && (NULL_PTR != pHibernateModeCfg)) {

        if (Mcu_GetCoreID() == CPU_ID_SF) {

            /*  mask all smc irq */
            Mcu_SmcAllIrqMaskConfig();

            /* wakeup source unmsk irq for smc vic configuration */
            /* PRQA S 2995 2*/
            Mcu_WakeupSourceEnableConfig(pHibernateModeCfg->wksrc,
                                            pHibernateModeCfg->wkip);

            /* saf domain, ap domain and SoC lowpower Config*/
            if ((NULL_PTR != pHibernateModeCfg->smc)) {
                Mcu_SoCEnterLpConfig(pHibernateModeCfg->smc);
            }

            /* usr callout: suspend process for enter hibernate mode */
            Mcu_SuspendUserCallouts(McuMode);

            /* disable RTC parity error interrupt status, because low power need disable RTC pclk */
            Mcu_RtcDisableRegParityErrIntEnable(APB_RTC1_BASE);
            Mcu_RtcDisableRegParityErrIntEnable(APB_RTC2_BASE);

            /* rtc wakeup config*/
            if ((NULL_PTR != pHibernateModeCfg->wksrc)
                && (NULL_PTR != pHibernateModeCfg->wksrc->rtc)) {
                Mcu_RtcWakeupConfig(&Mcu_PwrRtcSleepTime[MCU_MODE_HIB],
                                    pHibernateModeCfg->wksrc->rtc);
            }

            /* iram1/2/3/4 power gating mode configuration */
            if (NULL_PTR != pHibernateModeCfg->iram) {
                Mcu_IramPowerConfig(pHibernateModeCfg->iram);
            }

            /*  switch clock to 24m  */
            Mcu_SmcSwitchClockTo24Mhz();

            /* Start Enter Wfi*/
            Mcu_ActionToWfi(McuMode);

            /* check saf/ap/pmu swm status */
            Mcu_SmcSwmCheckAfterExitWfi();

            /* store cpu clock */
            Mcu_SmcSwitchClockToNormal();

            /* store RTC parity error interrupt status */
            Mcu_RtcEnableRegParityErrIntEnable(APB_RTC1_BASE);
            Mcu_RtcEnableRegParityErrIntEnable(APB_RTC2_BASE);

            /* usr callout: resume process for wakeup from hibernate mode */
            Mcu_ResumeUserCallouts(McuMode);

        } else {
            /* Save the current CPU CPSR.I to avoid the failure to enter low power due
                to exiting the wfi state due to interruption */
            IRQ_SAVE
            /* Start Enter Wfi*/
            Mcu_ActionToWfi(McuMode);
            /* Resume CPU CPSR.I */
            IRQ_RESTORE
        }

    } else {

    }

}

FUNC(void, MCU_CODE) Mcu_LowPowerSleepConfig(
    P2CONST(Mcu_SleepModeConfigType, AUTOMATIC, MCU_APPL_CONST) SleepModeConfigPtr
)
{
    if (NULL_PTR != SleepModeConfigPtr) {

        /* ckgen configuration */
        Mcu_CkgenClockDisableConfig(MCU_MODE_SLP, SleepModeConfigPtr->ckgen,
                                    SleepModeConfigPtr->wkip);

        /* rstgen configuration */
        Mcu_RstgenResetAssertConfig(RESET_LP_SLEEP);

        /* power gate configuration: primary core, core power down, core ram power down */
        if (NULL_PTR != SleepModeConfigPtr->smc) {
            Mcu_SoCPowerGateConfig(SleepModeConfigPtr->smc, MCU_MODE_SLP);
        }

        /* power control signal: pwr_ctrl0~3 configuration */
        if (NULL_PTR != SleepModeConfigPtr->pmu) {
            Mcu_PmuPowerControlSignalConfig(PMU_STATE_SLEEP, SleepModeConfigPtr->pmu);
        }
    }
}

FUNC(void, MCU_CODE) Mcu_LowPowerHibernateConfig(
    P2CONST(Mcu_HibernateModeConfigType, AUTOMATIC, MCU_APPL_CONST) HibernateModeConfigPtr
)
{
    if (NULL_PTR != HibernateModeConfigPtr) {

        /* ckgen configuration */
        Mcu_CkgenClockDisableConfig(MCU_MODE_HIB, HibernateModeConfigPtr->ckgen,
                                    HibernateModeConfigPtr->wkip);

        /* rstgen configuration */
        Mcu_RstgenResetAssertConfig(RESET_LP_HIB);

        /* power gate configuration: primary core, core power down, core ram power down */
        if (NULL_PTR != HibernateModeConfigPtr->smc) {
            Mcu_SoCPowerGateConfig(HibernateModeConfigPtr->smc, MCU_MODE_HIB);
        }

        /* power control signal: pwr_ctrl0~3 configuration */
        if (NULL_PTR != HibernateModeConfigPtr->pmu) {
            Mcu_PmuPowerControlSignalConfig(PMU_STATE_HIBERNATE, HibernateModeConfigPtr->pmu);
        }
    }
}

FUNC(void, MCU_CODE) Mcu_LowPowerInit(void)
{
    const Mcu_SleepModeConfigType *pSleepModeCfg =  &Mcu_SleepModecfg;
    const Mcu_HibernateModeConfigType *pHibernateModeCfg = &Mcu_HibernateModecfg;
    if ((NULL_PTR != pSleepModeCfg) && (NULL_PTR != pHibernateModeCfg)) {

        /* low power Sleep mode configure */
        Mcu_LowPowerSleepConfig(pSleepModeCfg);

        /* low power Hibernate mode configure */
        Mcu_LowPowerHibernateConfig(pHibernateModeCfg);

        /* configure smc timeout for lowpower handshake */
        Mcu_SmcSetTimeoutConfig(APB_SMC_BASE);
    }
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#endif /* MCU_SLEEP_MODE_API == STD_ON || MCU_HIBERNATE_MODE_API == STD_ON */

#ifdef __cplusplus
}
#endif
