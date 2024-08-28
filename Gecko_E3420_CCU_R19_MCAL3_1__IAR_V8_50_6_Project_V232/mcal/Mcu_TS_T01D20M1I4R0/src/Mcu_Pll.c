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
 * \file     Mcu_Pll.c                                                                                  *
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
#include "RegHelper.h"
#include "Mcu_Pll.h"
#include "Mcu_GeneralTypes.h"

/********************************************************************************************************
 *                                  Global Constant Declarations                                        *
 *******************************************************************************************************/
#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"
/* PRQA S 3218 1*/
static const uint32 Mcu_PllpostDivList[3U] = {2U, 4U, 2U};
#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
/********************************************************************************************************
 *                                  Private Function Declarations                                       *
 *******************************************************************************************************/
static uint32 Mcu_Ip_PllGetBestDiv(uint32 fRef, uint32 freq)
{
    uint32 divNum = UINT32_MAX;

    if (0U != freq)
    {
        divNum = MCU_DIV_ROUND_UP(fRef, freq);

        if (divNum > 1U)
        {
            if (((divNum * freq) - fRef) > (fRef - ((divNum - 1U) * freq)))
            {
                divNum--;
            } /* else not needed */
        } /* else not needed */
    } /* else not needed */

    /* The divNum greater than 1 and less than UINT32_MAX. */
    return divNum;
}

static void Mcu_Ip_PllVcoEnable(uint32 base)
{
    uint32 reg = base + PLL_CTRL;
    uint32 val;

    val = readl(reg);

    val |= ((uint32)1U << PLL_CTRL_RESETN);
    val &= ~((uint32)1U << PLL_CTRL_PD);

    writel(val, reg);
}

static void Mcu_Ip_PllVcoDisable(uint32 base)
{
    uint32 reg = base + PLL_CTRL;
    uint32 val;

    val = readl(reg);

    val &= ~((uint32)1U << PLL_CTRL_RESETN);
    val |= ((uint32)1U << PLL_CTRL_PD);

    writel(val, reg);
}

static Mcu_PllRateType Mcu_Ip_PllGetVcoRate(uint32 base, Mcu_PllRateType srcRate)
{
    uint32 reg = base + PLL_CTRL;
    Mcu_PllRateType fVco;
    uint32 val;
    boolean isIntMode;
    uint32 postDiv;
    uint32 mVal;
    uint32 nVal;
    uint32 tmpU32;
    uint64 tmpU64;

    val = readl(reg);

    if (1U == ((val >> PLL_CTRL_LOCK_MODE) & 0x1U))
    {
        isIntMode = TRUE;
    }
    else
    {
        isIntMode = FALSE;
    }

    postDiv = (1U == ((val >> PLL_CTRL_POSTDIV) & 0x1U)) ? 2U : 1U;

    val = readl(base + PLL_N_NUM);
    nVal = (val >> PLL_N_NUM_VAL_LSB) & PLL_N_NUM_VAL_MASK;

    tmpU32 = srcRate / postDiv;
    fVco = tmpU32 * nVal;

    if (FALSE == isIntMode)
    {
        val = readl(base + PLL_M_NUM);
        mVal = (val >> PLL_M_NUM_VAL_LSB) & PLL_M_NUM_VAL_MASK;
        tmpU64 = (uint64)tmpU32 * (uint64)mVal;
        fVco += (uint32)(tmpU64 >> 24U);
    } /* else not needed */

    return fVco;
}

static Std_ReturnType Mcu_Ip_PllVcoGetBestPostDiv(Mcu_PllRateType srcRate, Mcu_PllRateType rate,
        uint32 *postDivPtr, uint32 *mValPtr, uint32 *nValPtr)
{
    uint32 i;
    uint64 vcoOut;
    uint32 fracVal;
    uint64 tmpU64;
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;
    boolean flag = FALSE;

    if ((NULL_PTR != postDivPtr) && (NULL_PTR != mValPtr) && (NULL_PTR != nValPtr))
    {
        for (i = 0U; i < 3U; i++)
        {
            *postDivPtr = Mcu_PllpostDivList[i];
            vcoOut = ((uint64)rate * (uint64)(*postDivPtr));

            if (vcoOut > PLL_VCO_FMAX)
            {
                continue;
            } /* else not needed */

            if ((i != 2U) && (vcoOut < PLL_VCO_BAND))
            {
                continue;
            } /* else not needed */

            vcoOut /= 2U;
            *nValPtr = (uint32)(vcoOut / srcRate);
            fracVal = (uint32)(vcoOut % srcRate);

            /* integer mode */
            if (0U == fracVal)
            {
                *mValPtr = 0;
                errStatus = E_OK;
                flag = TRUE;
            } /* else not needed */

            if (FALSE == flag)
            {
                /* fractional mode */
                tmpU64 = (uint64)fracVal << 24U;
                tmpU64 = tmpU64 / (uint64)srcRate;

                if (tmpU64 > PLL_M_NUM_VAL_MASK)
                {
                    continue;
                } /* else not needed */

                *mValPtr = (uint32)tmpU64;
                errStatus = E_OK;
                flag = TRUE;
            } /* else not needed */

            if (TRUE == flag)
            {
                break;
            } /* else not needed */
        }
    }

    return errStatus;
}

/** Traceability       : SW_SM005 SW_MCU_SM010*/
static Std_ReturnType Mcu_Ip_PllVcoPrepare(uint32 base, Mcu_PllRateType srcRate,
        Mcu_PllRateType rate, boolean dsmEn)
{
    uint32 ctrlVal;
    uint32 mRegVal;
    uint32 postDiv = 0U;
    uint32 mVal = 0U;
    uint32 nVal = 0U;
    boolean recfg = FALSE;
    uint64 vcoOut;
    Std_ReturnType errStatus;
    uint32 valuePd;
    uint32 valueRst;

    ctrlVal = readl(base + PLL_CTRL);
    valuePd = MCU_BIT(ctrlVal, PLL_CTRL_PD);
    valueRst = MCU_BIT(ctrlVal, PLL_CTRL_RESETN);

    if ((0U == valuePd) &&  (0U != valueRst))
    {
        RMWREG32(base + PLL_CTRL, PLL_CTRL_FORCE_BYPASS, 1U, 1U);
        recfg = TRUE;
    } /* else not needed */

    Mcu_Ip_PllVcoDisable(base);

    errStatus = Mcu_Ip_PllVcoGetBestPostDiv(srcRate, rate, &postDiv, &mVal, &nVal);

    if (E_OK == errStatus)
    {

        RMWREG32(base + PLL_N_NUM, PLL_N_NUM_VAL_LSB, 7U, nVal);

        mRegVal = readl(base + PLL_M_NUM);
        mRegVal &= ~(PLL_M_NUM_VAL_MASK + ((uint32)1U << PLL_M_NUM_SW_READY));
        mRegVal |= (mVal + ((uint32)1U << PLL_M_NUM_SW_READY));
        writel(mRegVal, base + PLL_M_NUM);

        ctrlVal = readl(base + PLL_CTRL);

        /*LOCK_MODE need alaways be set to 0, fractional mode, to improve robustness,
          when set to 1, pll unlock may occur at low temperatures*/
        if ((mVal != 0U) || (TRUE == dsmEn))
        {
            ctrlVal &= ~((uint32)1U << PLL_CTRL_DSM_DISABLE);
            ctrlVal &= ~((uint32)1U << PLL_CTRL_LOCK_MODE);
        }
        else
        {
            ctrlVal |= ((uint32)1U << PLL_CTRL_DSM_DISABLE);
            ctrlVal &= ~((uint32)1U << PLL_CTRL_LOCK_MODE);
        }

        if (2U == postDiv)
        {
            ctrlVal &= ~((uint32)1U << PLL_CTRL_POSTDIV);
        }
        else
        {
            ctrlVal |= ((uint32)1U << PLL_CTRL_POSTDIV);
        }

        ctrlVal &= ~((uint32)7U << PLL_CTRL_VCO_BAND_LSB);

        vcoOut = (uint64)rate * postDiv;

        if (vcoOut >= PLL_VCO_BAND)
        {
            ctrlVal |= ((uint32)7U << PLL_CTRL_VCO_BAND_LSB);
        }
        else
        {
            ctrlVal |= ((uint32)4U << PLL_CTRL_VCO_BAND_LSB);
        }

        writel(ctrlVal, base + PLL_CTRL);

        Mcu_Ip_PllVcoEnable(base);

        if (FALSE == Mcu_Ip_WaitForBitTimes(base + PLL_STATUS, PLL_STATUS_LOCK, 1U,
                                            PLL_WAIT_TIME))
        {
            errStatus = MCU_E_TIMEOUT;
        } /* else not needed */

        if (TRUE == recfg)
        {
            RMWREG32(base + PLL_CTRL, PLL_CTRL_FORCE_BYPASS, 1U, 0U);
        } /* else not needed */
    } /* else not needed */

    return errStatus;
}

static Std_ReturnType Mcu_Ip_PllLvdsEnable(uint32 base, uint32 id)
{
    uint32 reg;
    uint32 val;
    Std_ReturnType errStatus = E_OK;

    reg = base + PLL_LVDS_CTL;

    val = readl(reg);

    if (PLL_ID_NUM_LVDS_CLK_0 == id)
    {
        val |= ((uint32)1U << PLL_LVDS_CTL_GATING_EN);
    }
    else if (PLL_ID_NUM_LVDS_CLK_1 == id )
    {
        val |= ((uint32)1U << PLL_LVDS_CTL_DIV2_GATING_EN);
    }
    else if (PLL_ID_NUM_LVDS_CLK_2 == id )
    {
        val |= ((uint32)1U << PLL_LVDS_CTL_DIV7_GATING_EN);
    }
    else if (PLL_ID_NUM_LVDS_CKGEN == id )
    {
        val |= ((uint32)1U << PLL_LVDS_CTL_CKGEN_GATING_EN);
    }
    else
    {
        errStatus = MCU_E_PARAM_CONFIG;
    }

    if (E_OK == errStatus)
    {
        writel(val, reg);
    } /* else not needed */

    return errStatus;
}

static Std_ReturnType Mcu_Ip_PllLvdsDisable(uint32 base, uint32 id)
{
    uint32 reg;
    uint32 val;
    Std_ReturnType errStatus = E_OK;

    reg = base + PLL_LVDS_CTL;

    val = readl(reg);

    if (PLL_ID_NUM_LVDS_CLK_0 == id)
    {
        val &= ~((uint32)1U << PLL_LVDS_CTL_GATING_EN);
    }
    else if (PLL_ID_NUM_LVDS_CLK_1 == id )
    {
        val &= ~((uint32)1U << PLL_LVDS_CTL_DIV2_GATING_EN);
    }
    else if (PLL_ID_NUM_LVDS_CLK_2 == id )
    {
        val &= ~((uint32)1U << PLL_LVDS_CTL_DIV7_GATING_EN);
    }
    else if (PLL_ID_NUM_LVDS_CKGEN == id )
    {
        val &= ~((uint32)1U << PLL_LVDS_CTL_CKGEN_GATING_EN);
    }
    else
    {
        errStatus = MCU_E_PARAM_CONFIG;
    }

    if (E_OK == errStatus)
    {
        writel(val, reg);
    } /* else not needed */

    return errStatus;
}

/** Traceability       : SW_SM005*/
static Std_ReturnType Mcu_Ip_PllSetLvdsRate(uint32 base, uint32 id,
        uint32 srcRate, uint32 rate)
{
    uint32 reg;
    uint32 divNum;
    uint32 busyOffset;
    uint32 divOffset;
    uint32 divMax = PLL_LVDS_OUT_DIV_MAX;
    Std_ReturnType errStatus = E_OK;


    if (PLL_ID_NUM_LVDS_CLK_0 == id)
    {
        errStatus = E_OK;
    }
    else
    {
        divNum = Mcu_Ip_PllGetBestDiv(srcRate, rate);

        if (UINT32_MAX == divNum)
        {
            errStatus = MCU_E_OUTRANGE;
        }
        else
        {
            reg = base + PLL_LVDS_CTL;

            if (PLL_ID_NUM_LVDS_CLK_1 == id )
            {
                busyOffset = PLL_LVDS_CTL_DIV2_CHG_BUSY;
                divOffset = PLL_LVDS_CTL_DIV2_NUM_LSB;
            }
            else if (PLL_ID_NUM_LVDS_CLK_2 == id )
            {
                busyOffset = PLL_LVDS_CTL_DIV7_CHG_BUSY;
                divOffset = PLL_LVDS_CTL_DIV7_NUM_LSB;
            }
            else if (PLL_ID_NUM_LVDS_CKGEN == id )
            {
                busyOffset = PLL_LVDS_CTL_CKGEN_CHG_BUSY;
                divOffset = PLL_LVDS_CTL_CKGEN_DIV_NUM_LSB;
                divMax = PLL_LVDS_CKGEN_IN_DIV_MAX;
            }
            else
            {
                errStatus = MCU_E_PARAM_CONFIG;
            }

            if ((E_OK == errStatus) && ((divNum >= PLL_LVDS_OUT_DIV_MIN) && (divNum <= divMax)))
            {
                RMWREG32(reg, divOffset, 5U, divNum - 1U);

                if (FALSE == Mcu_Ip_WaitForBitTimes(reg, busyOffset, 0U, PLL_WAIT_TIME))
                {
                    errStatus = MCU_E_TIMEOUT;
                } /* else not needed */
            }
            else
            {
                errStatus = MCU_E_PARAM_CONFIG;
            }
        }
    }

    return errStatus;
}


static Mcu_PllRateType Mcu_Ip_PllGetLvdsRate(uint32 base, uint32 id, Mcu_PllRateType srcRate)
{
    uint32 reg;
    uint32 val;
    uint32 divNum;
    Mcu_PllRateType rate;

    if (PLL_ID_NUM_LVDS_CLK_0 == id)
    {
        rate = srcRate;
    }
    else
    {
        reg = base + PLL_LVDS_CTL;
        val = readl(reg);

        if (PLL_ID_NUM_LVDS_CLK_1 == id )
        {
            divNum = (val >> PLL_LVDS_CTL_DIV2_NUM_LSB) & PLL_LVDS_CTL_DIV2_NUM_MASK;
            rate = srcRate / (divNum + 1U);
        }
        else if (PLL_ID_NUM_LVDS_CLK_2 == id )
        {
            divNum = (val >> PLL_LVDS_CTL_DIV7_NUM_LSB) & PLL_LVDS_CTL_DIV7_NUM_MASK;
            rate = srcRate / (divNum + 1U);
        }
        else if (PLL_ID_NUM_LVDS_CKGEN == id )
        {
            divNum = (val >> PLL_LVDS_CTL_CKGEN_DIV_NUM_LSB) & PLL_LVDS_CTL_CKGEN_DIV_NUM_MASK;
            rate = srcRate / (divNum + 1U);
        }
        else
        {
            rate = UINT32_MAX;
        }
    }

    return rate;
}

static Std_ReturnType Mcu_Ip_PllLvdsPrepare(uint32 base, uint32 id,
        Mcu_PllRateType srcRate,
        Mcu_PllRateType rate)
{
    Std_ReturnType errStatus;

    errStatus = Mcu_Ip_PllSetLvdsRate(base, id, srcRate, rate);

    if (E_OK == errStatus)
    {
        errStatus = Mcu_Ip_PllLvdsEnable(base, id);
    } /* else not needed */

    return errStatus;
}
/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
Std_ReturnType Mcu_Ip_PllEnable(uint32 base, uint32 id)
{
    Std_ReturnType errStatus = E_OK;

    if (id == PLL_ID_NUM_VCO)
    {
        Mcu_Ip_PllVcoEnable(base);
    }
    else if (id <= PLL_ID_NUM_LVDS_CKGEN)
    {
        errStatus = Mcu_Ip_PllLvdsEnable(base, id);
    }
    else
    {
        errStatus = MCU_E_PARAM_CONFIG;
    }

    return errStatus;
}

Std_ReturnType Mcu_Ip_PllDisable(uint32 base, uint32 id)
{
    Std_ReturnType errStatus = E_OK;

    if (id == PLL_ID_NUM_VCO)
    {
        Mcu_Ip_PllVcoDisable(base);
    }
    else if (id <= PLL_ID_NUM_LVDS_CKGEN)
    {
        errStatus = Mcu_Ip_PllLvdsDisable(base, id);
    }
    else
    {
        errStatus = MCU_E_PARAM_CONFIG;
    }

    return errStatus;
}

Std_ReturnType Mcu_Ip_PllPrepare(uint32 base, uint32 id,
                                 Mcu_PllRateType srcRate,
                                 Mcu_PllRateType rate, boolean dsmEn)
{
    Std_ReturnType errStatus;

    if (id == PLL_ID_NUM_VCO)
    {
        errStatus = Mcu_Ip_PllVcoPrepare(base, srcRate, rate, dsmEn);
    }
    else if (id <= PLL_ID_NUM_LVDS_CKGEN)
    {
        errStatus = Mcu_Ip_PllLvdsPrepare(base, id, srcRate, rate);
    }
    else
    {
        errStatus = MCU_E_PARAM_CONFIG;
    }

    return errStatus;
}

Mcu_PllRateType Mcu_Ip_PllGetRate(uint32 base, uint32 id,
                                  Mcu_PllRateType srcRate)
{
    Mcu_PllRateType rate;

    if (id == PLL_ID_NUM_VCO)
    {
        rate = Mcu_Ip_PllGetVcoRate(base, srcRate);
    }
    else if (id <= PLL_ID_NUM_LVDS_CKGEN)
    {
        rate = Mcu_Ip_PllGetLvdsRate(base, id, srcRate);
    }
    else
    {
        rate =  UINT32_MAX;
    }

    return rate;
}

Std_ReturnType Mcu_Ip_PllSetRate(uint32 base, uint32 id,
                                 Mcu_PllRateType srcRate,
                                 Mcu_PllRateType rate)
{
    Std_ReturnType errStatus;

    if ((id == PLL_ID_NUM_VCO) || (id > PLL_ID_NUM_LVDS_CKGEN))
    {
        /* Not support set the VCO rate. */
        errStatus = MCU_E_PARAM_CONFIG;
    }
    else
    {
        errStatus = Mcu_Ip_PllSetLvdsRate(base, id, srcRate, rate);
    }

    return errStatus;
}

boolean Mcu_Ip_PllIsLocked(uint32 base)
{
    boolean ret;

    if (0U != MCU_BIT(readl(base + PLL_STATUS), PLL_STATUS_LOCK))
    {
        ret = TRUE;
    }
    else
    {
        ret = FALSE;
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function set/cancle PLL force bypass.
 *
 * \verbatim
 * Syntax             : void Mcu_Ip_PllForceBypass(uint32 base, boolean enable)
 *
 * Service ID[hex]    : -
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : enable - TRUE- set pll bypass; FALSE- cancel pll bypass.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : -
 *
 * Description        : This function set/cancle PLL force bypass.
 *                      Pll force bypass, pll output force to fs24M refclock.
 *                      set and cancle need use in pairs.
 * \endverbatim
 * Traceability       : SWSR_MCU_004
 *******************************************************************************************************/
void Mcu_Ip_PllForceBypass(uint32 base, boolean enable)
{
    uint32 ctrlVal = readl(base + PLL_CTRL);
    uint32 pdStatus;
    uint32 rstStatus;
    uint32 bypassStatus;

    if(TRUE == enable)
    {
        pdStatus = MCU_BIT(ctrlVal, PLL_CTRL_PD);
        rstStatus = MCU_BIT(ctrlVal, PLL_CTRL_RESETN);
        if ((0U == pdStatus) && (rstStatus != 0U))
        {
            RMWREG32(base + PLL_CTRL, PLL_CTRL_FORCE_BYPASS, 1U, 1U);
        }
    }
    else
    {
        bypassStatus = MCU_BIT(ctrlVal, PLL_CTRL_FORCE_BYPASS);
        if (bypassStatus != 0U)
        {
            RMWREG32(base + PLL_CTRL, PLL_CTRL_FORCE_BYPASS, 1U, 0U);
        }
    }
}

/**
 * \brief Set PLL spread amplitude.
 *
 * This function set SSC amplitude for specific pll.
 *
 * \param [in] base PLL base.
 * \param [in] amplitude SSC amplitude 0-31 represents 0.1% - 3.2%.
 */
void Mcu_Ip_PllSetSscAmplitude(uint32 base, Mcu_CkgenSscAmplitudeType amplitude)
{
    uint32 reg;

    reg = base + PLL_DSM;

    RMWREG32(reg, PLL_DSM_SSC_DEP_LSB, 5U, amplitude);

    return;
}

/**
 * \brief Set PLL spread frequency.
 *
 * This function set SSC frequency for specific pll.
 *
 * \param [in] base PLL base.
 * \param [in] ssc_freq SSC modulation frequency.
 */
void Mcu_Ip_PllSetSscFrequency(uint32 base, Mcu_CkgenSscFreqType sscFreq)
{
    uint32 reg;

    reg = base + PLL_DSM;

    RMWREG32(reg, PLL_DSM_SSC_FREQ_LSB, 2U, sscFreq);
}

/**
 * \brief Set PLL spread mode.
 *
 * This function set SSC mode for specific pll. This function will check PLL work mode first,
 * if pll config DSM_DISABLE, set spread mode will failed.
 *
 * \param [in] base PLL base.
 * \param [in] sscMode SSC mode.
 * \return 0 represents success, otherwise failed.
 */
Std_ReturnType Mcu_Ip_PllSetSscMode(uint32 base, Mcu_CkgenSscModeType sscMode)
{
    Std_ReturnType errStatus;

    if ((0U != MCU_BIT(readl(base + PLL_CTRL), PLL_CTRL_DSM_DISABLE)) && (CKGEN_NO_SSC != sscMode))
    {
        errStatus = MCU_E_PARAM_CONFIG;
    }
    else
    {
        RMWREG32(base + PLL_DSM, PLL_DSM_SSC_MODE_LSB, 2U, sscMode);
        errStatus = E_OK;
    }

    return errStatus;
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
/* End of file */
