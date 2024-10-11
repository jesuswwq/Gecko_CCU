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
 * \file     Mcu_Xtal.c                                                                                 *
 * \brief    AUTOSAR 4.3.1 MCAL Mcu Driver                                                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/03     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "RegHelper.h"
#include "Mcu_Xtal.h"
#include "Xtal_Reg.h"
#include "Mcu_Delay.h"
#include "RegBase.h"
#include "Mcu_Rtc.h"

/********************************************************************************************************
 *                                 Private Macro definition                                             *
 *******************************************************************************************************/

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

void Mcu_Ip_XtalLpvdPowerSwitch(Mcu_LpvdCtrlType pd)
{
    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    uint32 v = readl(FS_32K_BASE_ADDR + FS_32K_LPVD_CTL);

    if (LPVD_POWER_DOWN == pd)
    {
        v |= BM_FS_32K_LPVD_CTL_PD;
    }
    else
    {
        v &= ~BM_FS_32K_LPVD_CTL_PD;
    }

    writel(v, FS_32K_BASE_ADDR + FS_32K_LPVD_CTL);

    /* will read to confirm that the register has been reached */
    (void)readl(FS_32K_BASE_ADDR + FS_32K_LPVD_CTL);

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();
}

/** Traceability       : SW_SM005*/
Std_ReturnType Mcu_Ip_Fs32KTrySwitchToXtal(uint32 base)
{
    Std_ReturnType retVal = E_NOT_OK;
    uint32 timeOutCounts = 1000U, count = 0U;
    uint32 v;
    boolean flag = FALSE;

    /* RTC domain register Access hook enter function */
    RTC_DOMAIN_SS_HOOK_ENTER();

    v = readl(base + FS_32K_FS_GLB_CTL);

    /* check xtal ready */
    if (0U != (v & BM_FS_32K_FS_GLB_CTL_XTAL_RDY))
    {
        /* [1:1] 0:from osc32K
         *       1:from xtal
         */
        v |= BM_FS_32K_FS_GLB_CTL_FS_SRC_SEL;
        writel(v, base + FS_32K_FS_GLB_CTL);

        /* wait for xtal active, 32K clock 2 cycle */
        while (count < timeOutCounts)
        {
            retVal = Mcu_udelay(100U);

            if (E_OK != retVal)
            {
                flag = TRUE;
            }
            else
            {
                v = readl(base + FS_32K_FS_GLB_CTL);

                if (0U != (v & BM_FS_32K_FS_GLB_CTL_XTAL_ACTIVE))
                {
                    flag = TRUE;
                }
                else
                {
                    count++;
                }
            }

            if (TRUE == flag)
            {
                break;
            } /* else not needed */
        }

        if (count < timeOutCounts)
        {
            retVal = E_OK;
        } /* else not needed */
    } /* else not needed */

    /* will read to confirm that the register has been reached */
    (void)readl(base + FS_32K_FS_GLB_CTL);

    /* RTC domain register Access hook exit function */
    RTC_DOMAIN_SS_HOOK_EXIT();

    return retVal;
}

/** Traceability       : SW_SM005*/
Std_ReturnType Mcu_Ip_FS_TrySwitchToRC(uint32 base)
{
    Std_ReturnType retVal = E_NOT_OK;
    uint32 timeOutCounts = 1000U, count = 0U;
    uint32 v = readl(base + FS_32K_FS_GLB_CTL);
    boolean flag = FALSE;

    /* check xtal ready */
    if (0U != (v & BM_FS_32K_FS_GLB_CTL_RC_RDY))
    {
        /* [1:1] 0:from osc32K
         *       1:from xtal
         */
        v &= ~BM_FS_32K_FS_GLB_CTL_FS_SRC_SEL;
        writel(v, base + FS_32K_FS_GLB_CTL);

        /* wait for xtal active, 32K clock 2 cycle */
        while (count < timeOutCounts)
        {
            retVal = Mcu_udelay(100U);

            if (E_OK != retVal)
            {
                flag = TRUE;
            }
            else
            {
                v = readl(base + FS_32K_FS_GLB_CTL);

                if (0U != (v & BM_FS_32K_FS_GLB_CTL_RC_ACTIVE))
                {
                    flag = TRUE;
                }
                else
                {
                    count++;
                }
            }

            if (TRUE == flag)
            {
                break;
            } /* else not needed */
        }

        if (count < timeOutCounts)
        {
            retVal = E_OK;
        } /* else not needed */
    } /* else not needed */

    return retVal;
}

void Mcu_Ip_Rc24m_Trim(void)
{
    uint32 regValue;
    uint8 tuneValue;
    uint8 cpTrimSta;
    uint8 ftTrimSta;

    /*judge CP Trim and FT Trim did flag*/
    cpTrimSta = (uint8)((readl(APB_EFUSEC_BASE + MCU_FUSEMAP_RC24M_FREQ_TUNE) >> 19U) & 0x1U);
    ftTrimSta = (uint8)((readl(APB_EFUSEC_BASE + MCU_FUSEMAP_RC32K) >> 6U) & 0x1U);

    if ((1U == cpTrimSta) && (1U == ftTrimSta))
    {
        regValue = readl(APB_EFUSEC_BASE + MCU_FUSEMAP_RC24M_FREQ_TUNE);

        tuneValue = (uint8)(regValue & MCU_FUSEMAP_RC24M_FREQ_TUNE_MASK);

        writel(tuneValue, (APB_FS_24M_BASE + FS_24M_RC_CTL));
    }
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif
/* End of file */
