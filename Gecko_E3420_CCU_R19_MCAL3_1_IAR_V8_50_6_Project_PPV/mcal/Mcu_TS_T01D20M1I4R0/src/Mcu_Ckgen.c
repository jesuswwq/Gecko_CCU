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
 * \file     Mcu_Ckgen.c                                                                                *
 * \brief    AUTOSAR 4.3.1 MCAL Mcu Driver                                                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/01     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "RegHelper.h"
#include "RegBase.h"
#include "Mcu_Ckgen.h"

/********************************************************************************************************
 *                                  Private Function Declarations                                       *
 *******************************************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

static inline uint32 Mcu_Ip_CkgenXcgGetCtrlReg(uint32 base, uint32 id)
{
    return CKGEN_XCG_CTL_BASE(base, id, CKGEN_CG_ID_TYPE(id));
}
/** Traceability       : SW_SM005*/
static Std_ReturnType Mcu_Ip_CkgenBusRootSetRate(uint32 base, uint32 id, uint8 mux)
{
    Std_ReturnType errStatus = E_OK;
    uint8 value;

    uint32 ctrlReg = CKGEN_BUS_CTL_BASE(base, id);

    /* Make sure CG is enabled. */
    if (1U == mux)
    {
        value = 0U;
        RMWREG32(ctrlReg, CKGEN_BUS_CTL_MAIN_EN, 1U, 1U);

        if (FALSE == Mcu_Ip_WaitForBitTimes(ctrlReg, CKGEN_BUS_CTL_MAIN_EN_STATUS,
                                            1U, CKGEN_WAIT_TIME))
        {
            errStatus = MCU_E_TIMEOUT;
        } /* else not needed */
    }
    else
    {
        value = 1U;
    }

    if (E_OK == errStatus)
    {
        RMWREG32(ctrlReg, CKGEN_BUS_CTL_SRC_SEL_CKOUT, 1U, mux);

        if (FALSE == Mcu_Ip_WaitForBitTimes(ctrlReg, CKGEN_BUS_CTL_POST_MUX_D0_ACTIVE,
                                            value, CKGEN_WAIT_TIME))
        {
            errStatus = MCU_E_TIMEOUT;
        } /* else not needed */
    } /* else not needed */

    return errStatus;
}
/** Traceability       : SW_SM005*/
static Std_ReturnType Mcu_Ip_CkgenBusSlicePreMuxNoChange(uint32 base, uint32 id, uint8 mux)
{
    uint32 ctrlReg = CKGEN_BUS_CTL_BASE(base, id);
    uint32 ctrlVal = readl(ctrlReg);
    Std_ReturnType errStatus = E_OK;
    uint32 mainEnStatus = MCU_BIT(ctrlVal, CKGEN_BUS_CTL_MAIN_EN_STATUS);
    uint32 preMuxD0Active = MCU_BIT(ctrlVal, CKGEN_BUS_CTL_PRE_MUX_D0_ACTIVE);
    uint32 preEnStatus = MCU_BIT(ctrlVal, CKGEN_BUS_CTL_PRE_EN_STATUS);
    uint32 waitTimeoutFlag;

    if ((mux == 4U) && (0U != mainEnStatus) && (0U == preMuxD0Active))
    {

        RMWREG32(ctrlReg, CKGEN_BUS_CTL_PRE_EN, 1U, 0U);

        if (FALSE == Mcu_Ip_WaitForBitTimes(ctrlReg, CKGEN_BUS_CTL_PRE_EN_STATUS,
                                            0U, CKGEN_WAIT_TIME))
        {
            errStatus = MCU_E_TIMEOUT;
        } /* else not needed */
    }
    else if ((mux < 4U) && (0U != preEnStatus) && (0U != preMuxD0Active))
    {

        RMWREG32(ctrlReg, CKGEN_BUS_CTL_SRC_SEL_CKOUT, 1U, 0U);

        if (FALSE == Mcu_Ip_WaitForBitTimes(ctrlReg, CKGEN_BUS_CTL_POST_MUX_D0_ACTIVE,
                                            1U, CKGEN_WAIT_TIME))
        {
            errStatus = MCU_E_TIMEOUT;
        }
        else
        {
            RMWREG32(ctrlReg, CKGEN_BUS_CTL_MAIN_EN, 1U, 0U);
            waitTimeoutFlag = Mcu_Ip_WaitForBitTimes(ctrlReg, CKGEN_BUS_CTL_MAIN_EN_STATUS,
                              0U, CKGEN_WAIT_TIME);

            if (FALSE == waitTimeoutFlag)
            {
                errStatus = MCU_E_TIMEOUT;
            } /* else not needed */
        }
    }
    else
    {
        errStatus = MCU_E_PARAM_CONFIG;
    }

    return errStatus;
}

static Std_ReturnType Mcu_Ip_CkgenSfBusSetDivRate(uint32 base, uint32 ratio)
{
    Std_ReturnType errStatus = MCU_E_PARAM_CONFIG;

    if ((0U == ratio) || (1U == ratio))
    {
        RMWREG32(base + CKGEN_RES, CKGEN_RES_RS_SF_RATIO_SEL, 1U, ratio);
        errStatus = E_OK;
    } /* else not needed */

    return errStatus;
}

static Std_ReturnType Mcu_Ip_CkgenSpBusSetDivRate(uint32 base, uint32 ratio)
{
    Std_ReturnType errStatus = MCU_E_PARAM_CONFIG;

    if ((0U == ratio) || (1U == ratio))
    {
        RMWREG32(base + CKGEN_RES, CKGEN_RES_RS_SP_RATIO_SEL, 1U, ratio);
        errStatus = E_OK;
    } /* else not needed */

    return errStatus;
}

#ifdef SEMIDRIVE_E3_SERIES
/* Bus Slice NP divider update. This function change bus slice NP div.*/
static Std_ReturnType Mcu_Ip_CkgenBusSliceSetNPUpdate(uint32 base, uint32 id, uint8 divN,
        uint8 divP)
{
    uint8 currentDivN, currentDivP;
    Std_ReturnType errStatus = E_OK;
    uint32 syncCtrl = CKGEN_BUS_SYNC_CTL_BASE(base, id);
    uint32 val;
    boolean timeoutFlag;

    val = readl(syncCtrl);

    currentDivN = ((val >> CKGEN_BUS_SYNC_CTL_DIV_N_LSB) & CKGEN_BUS_SYNC_CTL_DIV_MASK) + 1U;
    currentDivP = ((val >> CKGEN_BUS_SYNC_CTL_DIV_P_LSB) & CKGEN_BUS_SYNC_CTL_DIV_MASK) + 1U;

    if ((divN == currentDivN) && (divP == currentDivP))
    {
        errStatus = E_OK;
    }
    else
    {
        if (divN >= currentDivN)
        {
            /* frequency decrease, update divP first */
            if (divP % currentDivN)
            {
                errStatus = MCU_E_CKGEN_AP_BUS_MNPQ_RATIO_ERROR;
            }
            else
            {
                RMWREG32(syncCtrl, CKGEN_BUS_SYNC_CTL_DIV_P_LSB, 4U, (divP - 1U));
                timeoutFlag = Mcu_Ip_WaitForBitTimes(syncCtrl, CKGEN_BUS_SYNC_CTL_DIV_CHG_BUSY_P_LSB,
                                                     0U, CKGEN_WAIT_TIME);

                if (FALSE == timeoutFlag)
                {
                    errStatus = MCU_E_TIMEOUT;
                }
                else
                {
                    RMWREG32(syncCtrl, CKGEN_BUS_SYNC_CTL_DIV_N_LSB, 4U, (divN - 1U));
                    timeoutFlag = Mcu_Ip_WaitForBitTimes(syncCtrl, CKGEN_BUS_SYNC_CTL_DIV_CHG_BUSY_N_LSB,
                                                         0U, CKGEN_WAIT_TIME);

                    if (FALSE == timeoutFlag)
                    {
                        errStatus = MCU_E_TIMEOUT;
                    }
                }
            }
        }
        else
        {
            /* frequency increase, update divN first */
            if (currentDivP % divN)
            {
                errStatus = MCU_E_CKGEN_AP_BUS_MNPQ_RATIO_ERROR;
            }
            else
            {
                RMWREG32(syncCtrl, CKGEN_BUS_SYNC_CTL_DIV_N_LSB, 4U, (divN - 1U));
                timeoutFlag = Mcu_Ip_WaitForBitTimes(syncCtrl, CKGEN_BUS_SYNC_CTL_DIV_CHG_BUSY_N_LSB,
                                                     0U, CKGEN_WAIT_TIME);

                if (FALSE == timeoutFlag)
                {
                    errStatus = MCU_E_TIMEOUT;
                }
                else
                {
                    RMWREG32(syncCtrl, CKGEN_BUS_SYNC_CTL_DIV_P_LSB, 4U, (divP - 1U));
                    timeoutFlag = Mcu_Ip_WaitForBitTimes(syncCtrl, CKGEN_BUS_SYNC_CTL_DIV_CHG_BUSY_P_LSB,
                                                         0U, CKGEN_WAIT_TIME);

                    if (FALSE == timeoutFlag)
                    {
                        errStatus = MCU_E_TIMEOUT;
                    }
                }
            }
        }
    }

    return errStatus;
}
#endif

/** Traceability       : SW_SM005*/
static Std_ReturnType Mcu_Ip_CkgenBusSliceSetMnpqDivOnetime(uint32 base, uint32 id, uint8 divM,
        uint8 divN, uint8 divP, uint8 divQ)
{
    uint32 syncCtrlReg = CKGEN_BUS_SYNC_CTL_BASE(base, id);
    uint32 divFlag = 0U;
    uint32 divMnpq = readl(syncCtrlReg) & 0xFFFFU;
    Std_ReturnType errStatus = E_OK;
    volatile uint32 timesOut = CKGEN_WAIT_TIME;
    uint32 value;

    if (divM > 0U)
    {
        divFlag = 1UL << CKGEN_BUS_SYNC_CTL_DIV_CHG_BUSY_LSB;
        divMnpq &= ~((uint32)0xFU << (CKGEN_BUS_SYNC_CTL_DIV_M_LSB));
        divMnpq |= (((uint32)divM - 1U) & 0xFU) << CKGEN_BUS_SYNC_CTL_DIV_M_LSB;
    }

    if (divN > 0U)
    {
        divFlag |= 1UL << CKGEN_BUS_SYNC_CTL_DIV_CHG_BUSY_N_LSB;
        divMnpq &= ~((uint32)0xFU << (CKGEN_BUS_SYNC_CTL_DIV_N_LSB));
        divMnpq |= (((uint32)divN - 1U) & 0xFU) << CKGEN_BUS_SYNC_CTL_DIV_N_LSB;
    }

    if (divP > 0U)
    {
        divFlag |= 1UL << CKGEN_BUS_SYNC_CTL_DIV_CHG_BUSY_P_LSB;
        divMnpq &= ~((uint32)0xFU << (CKGEN_BUS_SYNC_CTL_DIV_P_LSB));
        divMnpq |= (((uint32)divP - 1U) & 0xFU) << CKGEN_BUS_SYNC_CTL_DIV_P_LSB;
    }

    if (divQ > 0U)
    {
        divFlag |= 1UL << CKGEN_BUS_SYNC_CTL_DIV_CHG_BUSY_Q_LSB;
        divMnpq &= ~((uint32)0xFU << (CKGEN_BUS_SYNC_CTL_DIV_Q_LSB));
        divMnpq |= (((uint32)divQ - 1U) & 0xFU) << CKGEN_BUS_SYNC_CTL_DIV_Q_LSB;
    }

    if (0U != divFlag)
    {
        RMWREG32(syncCtrlReg, CKGEN_BUS_SYNC_CTL_DIV_M_LSB, 16U, divMnpq);

        value = ((readl(syncCtrlReg) >> CKGEN_BUS_SYNC_CTL_DIV_CHG_BUSY_LSB) & divFlag);

        while ((timesOut != 0U) && (0U != value))
        {
            value = ((readl(syncCtrlReg) >> CKGEN_BUS_SYNC_CTL_DIV_CHG_BUSY_LSB) & divFlag);
            /*PRQA S 3387 1*/
            timesOut--;
        }

        if (timesOut == 0U)
        {
            errStatus = MCU_E_TIMEOUT;
        }/* else not needed */
    }

    return errStatus;
}
/** Traceability       : SW_SM005*/
static Std_ReturnType Mcu_Ip_CkgenBusSlicePreMuxClkIn4(uint32 base, uint32 id)
{
    Std_ReturnType errStatus = E_OK;
    uint32 ctrlReg = CKGEN_BUS_CTL_BASE(base, id);
    boolean timeoutFlag;

    /* Make sure CG is enabled. */
    RMWREG32(ctrlReg, CKGEN_BUS_CTL_MAIN_EN, 1U, 1U);

    timeoutFlag = Mcu_Ip_WaitForBitTimes(ctrlReg, CKGEN_BUS_CTL_MAIN_EN_STATUS,
                                         1U, CKGEN_WAIT_TIME);

    if (FALSE == timeoutFlag)
    {
        errStatus = MCU_E_TIMEOUT;
    }
    else
    {
        /* set clk_src_sel[2] to 1b1. */
        RMWREG32(ctrlReg, CKGEN_BUS_CTL_SRC_SEL_CKIN4, 1U, 1U);

        timeoutFlag = Mcu_Ip_WaitForBitTimes(ctrlReg, CKGEN_BUS_CTL_PRE_MUX_D0_ACTIVE,
                                             0U, CKGEN_WAIT_TIME);

        if (FALSE == timeoutFlag)
        {
            errStatus = MCU_E_TIMEOUT;
        }
        else
        {
            RMWREG32(ctrlReg, CKGEN_BUS_CTL_PRE_EN, 1U, 0U);

            timeoutFlag = Mcu_Ip_WaitForBitTimes(ctrlReg, CKGEN_BUS_CTL_PRE_EN_STATUS,
                                                 0U, CKGEN_WAIT_TIME);

            if (FALSE == timeoutFlag)
            {
                errStatus = MCU_E_TIMEOUT;
            } /* else not needed */
        }
    }

    return errStatus;
}
/** Traceability       : SW_SM005*/
static Std_ReturnType Mcu_Ip_CkgenBusSlicePreMuxNotClkIn4(uint32 base, uint32 id, uint8 mux)
{
    Std_ReturnType errStatus = E_OK;
    uint32 ctrlReg = CKGEN_BUS_CTL_BASE(base, id);
    uint32 value = ((readl(ctrlReg) & ((uint32)1U << CKGEN_BUS_CTL_PRE_EN_STATUS)) >>
                    CKGEN_BUS_CTL_PRE_EN_STATUS);

    if (1U == value)
    {
        /*set reg_pre_en to 1b0, wait pre_en_ack to 1b0.*/
        RMWREG32(ctrlReg, CKGEN_BUS_CTL_PRE_EN, 1U, 0U);

        if (FALSE == Mcu_Ip_WaitForBitTimes(ctrlReg, CKGEN_BUS_CTL_PRE_EN_STATUS,
                                            0U, CKGEN_WAIT_TIME))
        {
            errStatus = MCU_E_TIMEOUT;
        }
    }

    if (E_OK == errStatus)
    {
        /* set clk_src_sel[1:0] to select the clock.*/
        RMWREG32(ctrlReg, CKGEN_BUS_CTL_SRC_SEL_LSB, 2U, mux);

        /*set reg_pre_en to 1b1, wait pre_en_ack to 1b1.*/
        RMWREG32(ctrlReg, CKGEN_BUS_CTL_PRE_EN, 1U, 1U);

        if (FALSE == Mcu_Ip_WaitForBitTimes(ctrlReg, CKGEN_BUS_CTL_PRE_EN_STATUS,
                                            1U, CKGEN_WAIT_TIME))
        {
            errStatus = MCU_E_TIMEOUT;
        }
        else
        {
            /* set clk_src_sel[2] to 1b0. */
            RMWREG32(ctrlReg, CKGEN_BUS_CTL_SRC_SEL_CKIN4, 1U, 0U);

            if (FALSE == Mcu_Ip_WaitForBitTimes(ctrlReg, CKGEN_BUS_CTL_PRE_MUX_D0_ACTIVE,
                                                1U, CKGEN_WAIT_TIME))
            {
                errStatus = MCU_E_TIMEOUT;
            }
            else
            {
                RMWREG32(ctrlReg, CKGEN_BUS_CTL_MAIN_EN, 1U, 0U);

                if (FALSE == Mcu_Ip_WaitForBitTimes(ctrlReg, CKGEN_BUS_CTL_MAIN_EN_STATUS,
                                                    0U, CKGEN_WAIT_TIME))
                {
                    errStatus = MCU_E_TIMEOUT;
                }/* else not needed */
            }
        }
    }/* else not needed */

    return errStatus;
}

static Std_ReturnType Mcu_Ip_CkgenBusSliceSetPreMux(uint32 base, uint32 id, uint8 mux)
{
    uint32 ctrlReg = CKGEN_BUS_CTL_BASE(base, id);
    uint32 ctrlVal = readl(ctrlReg);
    uint32 srcSel;
    uint8 oldMux;
    Std_ReturnType errStatus = E_OK;
    uint32 value;

    srcSel = (readl(ctrlReg) >> CKGEN_BUS_CTL_SRC_SEL_LSB) & CKGEN_BUS_CTL_SRC_SEL_MASK;

    /* sel ck_in4 */
    if (0U != (srcSel & (1U << CKGEN_BUS_CTL_SRC_SEL_CKIN4)))
    {
        oldMux = 4U;
    }
    /* sel ck_in0 ~ ck_in3 */
    else
    {
        oldMux = (uint8)(srcSel & 0x3U);
    }

    /*if mux == oldmux, no need to reconfig*/
    if (mux == oldMux)
    {
        errStatus = Mcu_Ip_CkgenBusSlicePreMuxNoChange(base, id, mux);
    }
    else
    {
        /* sel ck_in4 first */
        value = MCU_BIT(ctrlVal, CKGEN_BUS_CTL_PRE_MUX_D0_ACTIVE);

        if (0U != value)
        {
            errStatus = Mcu_Ip_CkgenBusSlicePreMuxClkIn4(base, id);
        } /* else not needed */

        /* sel ck_in0 to ck_in3 */
        if ((mux < 4U) && (E_OK == errStatus))
        {
            errStatus = Mcu_Ip_CkgenBusSlicePreMuxNotClkIn4(base, id, mux);
        } /* else not needed */
    }

    return errStatus;
}
/** Traceability       : SW_SM005 SW_MCU_SM012*/
static Std_ReturnType Mcu_Ip_CkgenBusDivRootSetRate(uint32 base, uint32 id, uint8 mux,
        Mcu_CkgenRateType srcRate, Mcu_CkgenRateType rate)
{
    uint32 ctrlReg = CKGEN_BUS_CTL_BASE(base, id);
    uint32 divNum;
    Std_ReturnType errStatus = E_OK;

    if (mux > 4U)
    {
        errStatus = MCU_E_PARAM_CONFIG;
    }
    else
    {
        divNum = Mcu_Ip_CkgenGetBestDiv(srcRate, rate);

        if ((UINT32_MAX == divNum) || ((divNum - 1U) > CKGEN_BUS_CTL_DIV_NUM_MASK))
        {
            errStatus = MCU_E_PARAM_CONFIG;
        }
        else
        {
            if (APB_CKGEN_SF_BASE == base)
            {
                /*set core:axi:bus 4:2:1 first when set root_div*/
                if (0U == (id & 0xFFU))
                {
                    errStatus = Mcu_Ip_CkgenSfBusSetDivRate(base, 0U);
                }
                else
                {
                    errStatus = Mcu_Ip_CkgenSpBusSetDivRate(base, 0U);
                }

            }

#ifdef SEMIDRIVE_E3_SERIES

            /* set div m/n/p to avoid freq is too high */
            if ((APB_CKGEN_AP_BASE == base) && (((id) & CKGEN_BUS_ID_NUM_MASK) == 0U))
            {
                /*PRQA S 2986 1*/
                errStatus = errStatus | Mcu_Ip_CkgenBusSliceSetNPUpdate(base, id, 6U, 12U);
            }
            else
            {
                /*PRQA S 2986 1*/
                errStatus = errStatus | Mcu_Ip_CkgenBusSliceSetMnpqDivOnetime(base, id, 2U, 4U, 8U, 0U);
            }

#else
            /*PRQA S 2986 1*/
            errStatus = errStatus | Mcu_Ip_CkgenBusSliceSetMnpqDivOnetime(base, id, 2U, 4U, 8U, 0U);
#endif

            if (E_OK == errStatus)
            {
                /* set pre mux */
                errStatus = Mcu_Ip_CkgenBusSliceSetPreMux(base, id, mux);

                if (E_OK == errStatus)
                {
                    if (mux != 4U)
                    {
                        /* set pre-mux when pre-en is 1, otherwise BUSY bit cannot change  */
                        RMWREG32(ctrlReg, CKGEN_BUS_CTL_DIV_NUM_LSB, 5U, divNum - 1U);

                        if (FALSE == Mcu_Ip_WaitForBitTimes(ctrlReg, CKGEN_BUS_CTL_DIV_CHG_BUSY,
                                                            0U, CKGEN_WAIT_TIME))
                        {
                            errStatus = MCU_E_TIMEOUT;
                        } /* else not needed */
                    } /* else not needed */
                } /* else not needed */
            } /* else not needed */
        }
    }

    return errStatus;
}
/** Traceability       : SW_SM005 SW_MCU_SM012*/
static Std_ReturnType Mcu_Ip_CkgenBusDivMnpqSetRate(uint32 base, uint32 id,
        Mcu_CkgenRateType srcRate,
        Mcu_CkgenRateType rate)
{
    uint32 syncCtrlReg = CKGEN_BUS_SYNC_CTL_BASE(base, id);
    uint32 type = CKGEN_BUS_ID_TYPE(id);
    uint32 divNum;
    uint32 divOffset;
    uint32 divBusyOffset;
    Std_ReturnType errStatus = E_OK;

    divNum = Mcu_Ip_CkgenGetBestDiv(srcRate, rate);

    if ((UINT32_MAX == divNum) || ((divNum - 1U) > CKGEN_BUS_SYNC_CTL_DIV_MASK))
    {
        errStatus = MCU_E_PARAM_CONFIG;
    }
    else
    {
        if (base == APB_CKGEN_SF_BASE)
        {
            divOffset = (type - CKGEN_BUS_ID_TYPE_DIV_M) * 4U;
            divOffset += CKGEN_BUS_SYNC_CTL_DIV_M_LSB;
            divBusyOffset = (type - CKGEN_BUS_ID_TYPE_DIV_M);
            divBusyOffset += CKGEN_BUS_SYNC_CTL_DIV_CHG_BUSY_LSB;

            RMWREG32(syncCtrlReg, divOffset, 4U, divNum - 1U);

            if (FALSE == Mcu_Ip_WaitForBitTimes(syncCtrlReg, divBusyOffset,
                                                0U, CKGEN_WAIT_TIME))
            {
                errStatus = MCU_E_TIMEOUT;
            } /* else not needed */
        }

#ifdef SEMIDRIVE_E3_SERIES
        else
        {
            if (type == CKGEN_BUS_ID_TYPE_DIV_N)
            {
                if (((2U * divNum) - 1U) > CKGEN_BUS_SYNC_CTL_DIV_MASK)
                {
                    errStatus = MCU_E_PARAM_CONFIG;
                }
                else
                {
                    if (((id) & CKGEN_BUS_ID_NUM_MASK) == 0U)
                    {
                        errStatus = Mcu_Ip_CkgenBusSliceSetNPUpdate(base, id, (uint8)divNum, (2U * (uint8)divNum));

                    }
                    else
                    {
                        errStatus = Mcu_Ip_CkgenBusSliceSetMnpqDivOnetime(base, id, 0U, (uint8)divNum, (2U * (uint8)divNum),
                                    0U);
                    }
                }
            }
        }
#endif
    }



    return errStatus;
}

static Mcu_CkgenRateType Mcu_Ip_CkgenSfBusGetDivRate(uint32 base)
{
    return MCU_BIT(REG_READ32(base + CKGEN_RES),
                   CKGEN_RES_RS_SF_RATIO_SEL) >> CKGEN_RES_RS_SF_RATIO_SEL;
}

static Mcu_CkgenRateType Mcu_Ip_CkgenSpBusGetDivRate(uint32 base)
{
    return MCU_BIT(REG_READ32(base + CKGEN_RES),
                   CKGEN_RES_RS_SP_RATIO_SEL) >> CKGEN_RES_RS_SP_RATIO_SEL;
}

static Mcu_CkgenRateType Mcu_Ip_CkgenBusDivRootGetRate(uint32 base, uint32 id,
        Mcu_CkgenRateType srcRate)
{
    uint32 ctrlReg = CKGEN_BUS_CTL_BASE(base, id);
    uint32 ctrlVal;
    uint32 srcSel;
    uint32 preDiv;
    Mcu_CkgenRateType rate;

    ctrlVal = readl(ctrlReg);
    srcSel = (ctrlVal >> CKGEN_BUS_CTL_SRC_SEL_LSB) & CKGEN_BUS_CTL_SRC_SEL_MASK;

    /* sel ck_in4 */
    if (0U != (srcSel & (1U << CKGEN_BUS_CTL_SRC_SEL_CKIN4)))
    {
        rate = srcRate;
    }
    /* sel ck_in0 ~ ck_in3 */
    else
    {
        preDiv = (ctrlVal >> CKGEN_BUS_CTL_DIV_NUM_LSB) & CKGEN_BUS_CTL_DIV_NUM_MASK;
        rate = (Mcu_CkgenRateType)srcRate / (Mcu_CkgenRateType)(preDiv + 1U);
    }

    return rate;
}

static Mcu_CkgenRateType Mcu_Ip_CkgenBusDivMnpqGetRate(uint32 base, uint32 id,
        Mcu_CkgenRateType srcRate)
{
    uint32 syncCtrl = CKGEN_BUS_SYNC_CTL_BASE(base, id);
    uint32 type = CKGEN_BUS_ID_TYPE(id);
    uint32 val;
    uint32 divNum;
    uint32 divOffset;

    val = readl(syncCtrl);

    divOffset = (type - CKGEN_BUS_ID_TYPE_DIV_M) * 4U;
    divOffset += CKGEN_BUS_SYNC_CTL_DIV_M_LSB;

    divNum = (val >> divOffset) & CKGEN_BUS_SYNC_CTL_DIV_MASK;

    return (Mcu_CkgenRateType)srcRate / (Mcu_CkgenRateType)(divNum + 1U);
}

/** Traceability       : SW_SM005*/
static Std_ReturnType Mcu_Ip_CkgenIpSliceMuxNoChange(uint32 base, uint32 id, uint8 mux)
{
    uint32 ctrlReg = CKGEN_IP_CTL_BASE(base, id);
    uint32 ctrlVal = readl(ctrlReg);
    Std_ReturnType errStatus = E_OK;
    uint32 mainEnStatus = MCU_BIT(ctrlVal, CKGEN_IP_CTL_MAIN_EN_STATUS);
    uint32 preEnStatus = MCU_BIT(ctrlVal, CKGEN_IP_CTL_PRE_EN_STATUS);
    uint32 d0Active = MCU_BIT(ctrlVal, CKGEN_IP_CTL_D0_ACTIVE);


    if ((4U == mux) && (0U != mainEnStatus) && (0U == d0Active))
    {

        RMWREG32(ctrlReg, CKGEN_IP_CTL_PRE_EN, 1U, 0U);

        if (FALSE == Mcu_Ip_WaitForBitTimes(ctrlReg, CKGEN_IP_CTL_PRE_EN_STATUS,
                                            0U, CKGEN_WAIT_TIME))
        {
            errStatus = MCU_E_TIMEOUT;
        } /* else not needed */
    }
    else
    {
        if ((mux < 4U) && (0U != preEnStatus) && (0U != d0Active))
        {
            RMWREG32(ctrlReg, CKGEN_IP_CTL_MAIN_EN, 1U, 0U);

            if (FALSE == Mcu_Ip_WaitForBitTimes(ctrlReg, CKGEN_IP_CTL_MAIN_EN_STATUS,
                                                0U, CKGEN_WAIT_TIME))
            {
                errStatus = MCU_E_TIMEOUT;
            } /* else not needed */
        }
        else
        {
            errStatus = MCU_E_PARAM_CONFIG;
        }
    }

    return errStatus;
}

/** Traceability       : SW_SM005*/
static Std_ReturnType Mcu_Ip_CkgenIpSliceMuxClkIn4(uint32 base, uint32 id)
{
    uint32 ctrlReg = CKGEN_IP_CTL_BASE(base, id);
    Std_ReturnType errStatus = E_OK;

    /* Make sure CG is enabled. */
    RMWREG32(ctrlReg, CKGEN_IP_CTL_MAIN_EN, 1U, 1U);

    if (FALSE == Mcu_Ip_WaitForBitTimes(ctrlReg, CKGEN_IP_CTL_MAIN_EN_STATUS,
                                        1U, CKGEN_WAIT_TIME))
    {
        errStatus = MCU_E_TIMEOUT;
    }
    else
    {
        /* set clk_src_sel[2] to 1b1. */
        RMWREG32(ctrlReg, CKGEN_IP_CTL_SRC_SEL_CKIN4, 1U, 1U);

        if (FALSE == Mcu_Ip_WaitForBitTimes(ctrlReg, CKGEN_IP_CTL_D0_ACTIVE,
                                            0U, CKGEN_WAIT_TIME))
        {
            errStatus = MCU_E_TIMEOUT;
        }
        else
        {
            RMWREG32(ctrlReg, CKGEN_IP_CTL_PRE_EN, 1U, 0U);

            if (FALSE == Mcu_Ip_WaitForBitTimes(ctrlReg, CKGEN_IP_CTL_PRE_EN_STATUS,
                                                0U, CKGEN_WAIT_TIME))
            {
                errStatus = MCU_E_TIMEOUT;
            }/* else not needed*/
        }
    }

    return errStatus;
}

/** Traceability       : SW_SM005*/
static Std_ReturnType Mcu_Ip_CkgenIpSliceMuxNotClkIn4(uint32 base, uint32 id, uint8 mux)
{
    uint32 ctrlReg = CKGEN_IP_CTL_BASE(base, id);
    Std_ReturnType errStatus = E_OK;
    uint32 value = ((readl(ctrlReg) & ((uint32)1U << CKGEN_IP_CTL_PRE_EN_STATUS)) >>
                    CKGEN_IP_CTL_PRE_EN_STATUS);

    if (1U == value)
    {
        /*set reg_pre_en to 1b0, wait pre_en_ack to 1b0.*/
        RMWREG32(ctrlReg, CKGEN_IP_CTL_PRE_EN, 1U, 0U);

        if (FALSE == Mcu_Ip_WaitForBitTimes(ctrlReg, CKGEN_IP_CTL_PRE_EN_STATUS,
                                            0U, CKGEN_WAIT_TIME))
        {
            errStatus = MCU_E_TIMEOUT;
        }
    }

    if (E_OK == errStatus)
    {
        /* set clk_src_sel[1:0] to select the clock.*/
        RMWREG32(ctrlReg, CKGEN_IP_CTL_SRC_SEL_LSB, 2U, mux);

        /*set reg_pre_en to 1b1, wait pre_en_ack to 1b1.*/
        RMWREG32(ctrlReg, CKGEN_IP_CTL_PRE_EN, 1U, 1U);

        if (FALSE == Mcu_Ip_WaitForBitTimes(ctrlReg, CKGEN_IP_CTL_PRE_EN_STATUS,
                                            1U, CKGEN_WAIT_TIME))
        {
            errStatus = MCU_E_TIMEOUT;
        }
        else
        {

            /* set clk_src_sel[2] to 1b0. */
            RMWREG32(ctrlReg, CKGEN_IP_CTL_SRC_SEL_CKIN4, 1U, 0U);

            if (FALSE == Mcu_Ip_WaitForBitTimes(ctrlReg, CKGEN_IP_CTL_D0_ACTIVE,
                                                1U, CKGEN_WAIT_TIME))
            {
                errStatus = MCU_E_TIMEOUT;
            }
            else
            {
                RMWREG32(ctrlReg, CKGEN_IP_CTL_MAIN_EN, 1U, 0U);

                if (FALSE == Mcu_Ip_WaitForBitTimes(ctrlReg, CKGEN_IP_CTL_MAIN_EN_STATUS,
                                                    0U, CKGEN_WAIT_TIME))
                {
                    errStatus = MCU_E_TIMEOUT;
                }/* else not needed */
            }
        }
    }/* else not needed */

    return errStatus;
}

static Std_ReturnType Mcu_Ip_CkgenIpSetMux(uint32 base, uint32 id, uint8 mux)
{
    uint32 ctrlReg = CKGEN_IP_CTL_BASE(base, id);
    uint32 ctrlVal = readl(ctrlReg);
    uint32 srcSel;
    uint8 oldMux;
    Std_ReturnType errStatus = E_OK;
    uint32 value;

    srcSel = (ctrlVal >> CKGEN_IP_CTL_SRC_SEL_LSB) & CKGEN_IP_CTL_SRC_SEL_MASK;

    /* sel ck_in4 */
    if (0U != (srcSel & (1U << CKGEN_IP_CTL_SRC_SEL_CKIN4)))
    {
        oldMux = 4U;
    }
    /* sel ck_in0 ~ ck_in3 */
    else
    {
        oldMux = (uint8)(srcSel & 0x3U);
    }

    if (oldMux == mux)
    {
        errStatus = Mcu_Ip_CkgenIpSliceMuxNoChange(base, id, mux);
    }
    else
    {
        /* sel ck_in4 first */
        value = MCU_BIT(ctrlVal, CKGEN_IP_CTL_D0_ACTIVE);

        if (0U != value)
        {
            errStatus = Mcu_Ip_CkgenIpSliceMuxClkIn4(base, id);
        }

        if (E_OK == errStatus)
        {
            /* sel ck_in0 to ck_in3 */
            if (mux < 4U)
            {
                errStatus = Mcu_Ip_CkgenIpSliceMuxNotClkIn4(base, id, mux);
            } /* else not needed */
        } /* else not needed */
    }

    return errStatus;
}

/** Traceability       : SW_SM005*/
static Std_ReturnType Mcu_Ip_CkgenIpSetDiv(uint32 base, uint32 id, uint32 divNum)
{
    uint32 ctrlReg = CKGEN_IP_CTL_BASE(base, id);
    Std_ReturnType errStatus = E_OK;

    RMWREG32(ctrlReg, CKGEN_IP_CTL_DIV_NUM_LSB, 8U, divNum - 1U);

    if (FALSE == Mcu_Ip_WaitForBitTimes(ctrlReg, CKGEN_IP_CTL_DIV_CHG_BUSY,
                                        0U, CKGEN_WAIT_TIME))
    {
        errStatus = MCU_E_TIMEOUT;
    } /* else not needed */

    return errStatus;
}

/** Traceability       : SW_SM005*/
static Std_ReturnType Mcu_Ip_CkgenCoreSliceMuxNoChange(uint32 base, uint32 id, uint8 mux)
{
    uint32 ctrlReg = CKGEN_CORE_CTL_BASE(base, id);
    uint32 ctrlVal = readl(ctrlReg);
    Std_ReturnType errStatus = E_OK;
    uint32 mainEnStatus = MCU_BIT(ctrlVal, CKGEN_CORE_CTL_MAIN_EN_STATUS);
    uint32 preEnStatus = MCU_BIT(ctrlVal, CKGEN_CORE_CTL_PRE_EN_STATUS);
    uint32 d0Active = MCU_BIT(ctrlVal, CKGEN_CORE_CTL_D0_ACTIVE);

    if ((4U == mux) && (0U != mainEnStatus) && (0U == d0Active))
    {

        RMWREG32(ctrlReg, CKGEN_CORE_CTL_PRE_EN, 1U, 0U);

        if (FALSE == Mcu_Ip_WaitForBitTimes(ctrlReg, CKGEN_CORE_CTL_PRE_EN_STATUS,
                                            0U, CKGEN_WAIT_TIME))
        {
            errStatus = MCU_E_TIMEOUT;
        } /* else not needed */
    }
    else
    {
        if ((mux < 4U) && (0U != preEnStatus) && (0U != d0Active))
        {
            RMWREG32(ctrlReg, CKGEN_CORE_CTL_MAIN_EN, 1U, 0U);

            if (FALSE == Mcu_Ip_WaitForBitTimes(ctrlReg, CKGEN_CORE_CTL_MAIN_EN_STATUS,
                                                0U, CKGEN_WAIT_TIME))
            {
                errStatus = MCU_E_TIMEOUT;
            } /* else not needed */
        }
        else
        {
            errStatus = MCU_E_PARAM_CONFIG;
        }
    }

    return errStatus;
}

/** Traceability       : SW_SM005*/
static Std_ReturnType Mcu_Ip_CkgenCoreSliceMuxClkIn4(uint32 base, uint32 id)
{
    uint32 ctrlReg = CKGEN_CORE_CTL_BASE(base, id);
    Std_ReturnType errStatus = E_OK;

    /* Make sure CG is enabled. */
    RMWREG32(ctrlReg, CKGEN_CORE_CTL_MAIN_EN, 1U, 1U);

    if (FALSE == Mcu_Ip_WaitForBitTimes(ctrlReg, CKGEN_CORE_CTL_MAIN_EN_STATUS,
                                        1U, CKGEN_WAIT_TIME))
    {
        errStatus = MCU_E_TIMEOUT;
    }
    else
    {
        /* set clk_src_sel[2] to 1b1. */
        RMWREG32(ctrlReg, CKGEN_CORE_CTL_SRC_SEL_CKIN4, 1U, 1U);

        if (FALSE == Mcu_Ip_WaitForBitTimes(ctrlReg, CKGEN_CORE_CTL_D0_ACTIVE,
                                            0U, CKGEN_WAIT_TIME))
        {
            errStatus = MCU_E_TIMEOUT;
        }
        else
        {
            RMWREG32(ctrlReg, CKGEN_CORE_CTL_PRE_EN, 1U, 0U);

            if (FALSE == Mcu_Ip_WaitForBitTimes(ctrlReg, CKGEN_CORE_CTL_PRE_EN_STATUS,
                                                0U, CKGEN_WAIT_TIME))
            {
                errStatus = MCU_E_TIMEOUT;
            } /* else not needed */
        }
    }

    return errStatus;

}

/** Traceability       : SW_SM005*/
static Std_ReturnType Mcu_Ip_CkgenCoreSliceMuxNotClkIn4(uint32 base, uint32 id, uint8 mux)
{
    uint32 ctrlReg = CKGEN_CORE_CTL_BASE(base, id);
    Std_ReturnType errStatus = E_OK;
    uint32 value = ((readl(ctrlReg) & ((uint32)1U << CKGEN_CORE_CTL_PRE_EN_STATUS)) >>
                    CKGEN_CORE_CTL_PRE_EN_STATUS);

    if (1U == value)
    {
        /*set reg_pre_en to 1b0, wait pre_en_ack to 1b0.*/
        RMWREG32(ctrlReg, CKGEN_CORE_CTL_PRE_EN, 1U, 0U);

        if (FALSE == Mcu_Ip_WaitForBitTimes(ctrlReg, CKGEN_CORE_CTL_PRE_EN_STATUS,
                                            0U, CKGEN_WAIT_TIME))
        {
            errStatus = MCU_E_TIMEOUT;
        }
    }

    if (E_OK == errStatus)
    {
        /* set clk_src_sel[1:0] to select the clock.*/
        RMWREG32(ctrlReg, CKGEN_CORE_CTL_SRC_SEL_LSB, 2U, mux);

        /*set reg_pre_en to 1b1, wait pre_en_ack to 1b1.*/
        RMWREG32(ctrlReg, CKGEN_CORE_CTL_PRE_EN, 1U, 1U);

        if (FALSE == Mcu_Ip_WaitForBitTimes(ctrlReg, CKGEN_CORE_CTL_PRE_EN_STATUS,
                                            1U, CKGEN_WAIT_TIME))
        {
            errStatus = MCU_E_TIMEOUT;
        }
        else
        {
            /* set clk_src_sel[2] to 1b0. */
            RMWREG32(ctrlReg, CKGEN_CORE_CTL_SRC_SEL_CKIN4, 1U, 0U);

            if (FALSE == Mcu_Ip_WaitForBitTimes(ctrlReg, CKGEN_CORE_CTL_D0_ACTIVE,
                                                1U, CKGEN_WAIT_TIME))
            {
                errStatus = MCU_E_TIMEOUT;
            }
            else
            {
                RMWREG32(ctrlReg, CKGEN_CORE_CTL_MAIN_EN, 1U, 0U);

                if (FALSE == Mcu_Ip_WaitForBitTimes(ctrlReg, CKGEN_CORE_CTL_MAIN_EN_STATUS,
                                                    0U, CKGEN_WAIT_TIME))
                {
                    errStatus = MCU_E_TIMEOUT;
                }/* else not needed */
            }
        }
    }

    return errStatus;

}

static Std_ReturnType Mcu_Ip_CkgenDrvCoreSliceSetMux(uint32 base, uint32 id, uint8 mux)
{
    uint32 ctrlReg = CKGEN_CORE_CTL_BASE(base, id);
    uint32 ctrlVal = readl(ctrlReg);
    Std_ReturnType errStatus = E_OK;
    uint32 srcSel;
    uint8 oldMux;
    uint32 value;

    srcSel = (ctrlVal >> CKGEN_CORE_CTL_SRC_SEL_LSB) & CKGEN_CORE_CTL_SRC_SEL_MASK;

    /* sel ck_in4 */
    if (0U != (srcSel & (1U << CKGEN_CORE_CTL_SRC_SEL_CKIN4)))
    {
        oldMux = 4U;
    }
    /* sel ck_in0 ~ ck_in3 */
    else
    {
        oldMux = (uint8)(srcSel & 0x3U);
    }

    if (oldMux == mux)
    {
        errStatus = Mcu_Ip_CkgenCoreSliceMuxNoChange(base, id, mux);
    }
    else
    {
        /* sel ck_in4 first */
        value = MCU_BIT(ctrlVal, CKGEN_CORE_CTL_D0_ACTIVE);

        if (0U != value)
        {
            errStatus = Mcu_Ip_CkgenCoreSliceMuxClkIn4(base, id);
        } /* else not needed */

        if (E_OK == errStatus)
        {
            /* sel ck_in0 to ck_in3 */
            if (mux < 4U)
            {
                errStatus = Mcu_Ip_CkgenCoreSliceMuxNotClkIn4(base, id, mux);
            } /* else not needed */
        } /* else not needed */
    }

    return errStatus;
}

/** Traceability       : SW_SM005*/
static Std_ReturnType Mcu_Ip_CkgenDrvCoreSliceSetDiv(uint32 base, uint32 id, uint32 divNum)
{
    uint32 ctrlReg = CKGEN_CORE_CTL_BASE(base, id);
    Std_ReturnType errStatus = E_OK;

    RMWREG32(ctrlReg, CKGEN_CORE_CTL_DIV_NUM_LSB, 5U, divNum - 1U);

    if (FALSE == Mcu_Ip_WaitForBitTimes(ctrlReg, CKGEN_CORE_CTL_DIV_CHG_BUSY,
                                        0U, CKGEN_WAIT_TIME))
    {
        errStatus = MCU_E_TIMEOUT;
    } /* else not needed */

    return errStatus;
}



/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
/** Traceability       : SW_SM005*/
boolean Mcu_Ip_WaitForBitTimes(uint32 base, uint32 offset, uint32 val, uint32 count)
{
    volatile uint32 timesOut = count;
    boolean ret;

    while ((timesOut != 0U) &&
            (val != ((readl(base) & ((uint32)1U << offset)) >> offset)))
    {
        /*PRQA S 3387 1*/
        timesOut--;
    }

    if (timesOut > 0U)
    {
        ret = TRUE;
    }
    else
    {
        ret = FALSE;
    }

    return ret;
}
uint32 Mcu_Ip_CkgenGetBestDiv(uint32 srcRef, uint32 freq)
{
    uint32 clkDiv = UINT32_MAX;

    if (0U != freq)
    {
        clkDiv = MCU_DIV_ROUND_CLOSEST(srcRef, freq);
    } /* else not needed */

    /* The clkDiv greater than 1 and less than UINT32_MAX. */
    return clkDiv;
}

Mcu_CkgenRateType Mcu_Ip_CkgenIpGetRate(uint32 base, uint32 id, Mcu_CkgenRateType srcRate)
{
    uint32 ctrlReg = CKGEN_IP_CTL_BASE(base, id);
    uint32 ctrlVal;
    uint32 divNum;

    ctrlVal = readl(ctrlReg);

    divNum = (ctrlVal >> CKGEN_IP_CTL_DIV_NUM_LSB) & CKGEN_IP_CTL_DIV_NUM_MASK;

    return (Mcu_CkgenRateType)srcRate / (Mcu_CkgenRateType)(divNum + 1U);
}

/** Traceability       : SW_MCU_SM012*/
Std_ReturnType Mcu_Ip_CkgenIpSetRate(uint32 base, uint32 id, uint8 mux, Mcu_CkgenRateType srcRate,
                                     Mcu_CkgenRateType rate)
{
    uint32 divNum;
    Std_ReturnType errStatus;

    if (mux > 4U)
    {
        errStatus = MCU_E_PARAM_CONFIG;
    }
    else
    {
        divNum = Mcu_Ip_CkgenGetBestDiv(srcRate, rate);

        if ((UINT32_MAX == divNum) || ((divNum - 1U) > CKGEN_IP_CTL_DIV_NUM_MASK))
        {
            errStatus = MCU_E_PARAM_CONFIG;
        } /* else not needed */
        else
        {
            /* set div to avoid freq is too high */
            errStatus = Mcu_Ip_CkgenIpSetDiv(base, id, 0x7FU);

            if (E_OK == errStatus)
            {
                errStatus = Mcu_Ip_CkgenIpSetMux(base, id, mux);

                if (E_OK == errStatus)
                {
                    errStatus = Mcu_Ip_CkgenIpSetDiv(base, id, divNum);
                } /* else not needed */
            } /* else not needed */
        }
    }

    return errStatus;
}

Mcu_CkgenRateType Mcu_Ip_CkgenBusGetRate(uint32 base, uint32 id,
        Mcu_CkgenRateType srcRate)
{
    Mcu_CkgenRateType rate;
    uint32 type = CKGEN_BUS_ID_TYPE(id);

    if (type > CKGEN_BUS_ID_TYPE_DIV_SP)
    {
        rate = UINT32_MAX;
    }
    else
    {
        switch (type)
        {
        case CKGEN_BUS_ID_TYPE_ROOT:
            rate = srcRate;
            break;

        case CKGEN_BUS_ID_TYPE_DIV_ROOT:
            rate = Mcu_Ip_CkgenBusDivRootGetRate(base, id, srcRate);
            break;

        case CKGEN_BUS_ID_TYPE_DIV_SF:
            rate = Mcu_Ip_CkgenSfBusGetDivRate(base);
            break;

        case CKGEN_BUS_ID_TYPE_DIV_SP:
            rate = Mcu_Ip_CkgenSpBusGetDivRate(base);
            break;

        default:
            rate = Mcu_Ip_CkgenBusDivMnpqGetRate(base, id, srcRate);
            break;
        }
    }

    return rate;
}

/** Traceability       : SW_MCU_SM012*/
Std_ReturnType Mcu_Ip_CkgenBusSetRate(uint32 base, uint32 id, uint8 mux,
                                      Mcu_CkgenRateType srcRate, Mcu_CkgenRateType rate)
{
    Std_ReturnType errStatus;
    uint32 type = CKGEN_BUS_ID_TYPE(id);

    if (type > CKGEN_BUS_ID_TYPE_DIV_SP)
    {
        errStatus = MCU_E_PARAM_CONFIG;
    }
    else
    {
        switch (type)
        {
        case CKGEN_BUS_ID_TYPE_ROOT:
            errStatus = Mcu_Ip_CkgenBusRootSetRate(base, id, mux);
            break;

        case CKGEN_BUS_ID_TYPE_DIV_ROOT:
            errStatus = Mcu_Ip_CkgenBusDivRootSetRate(base, id, mux, srcRate, rate);
            break;

        case CKGEN_BUS_ID_TYPE_DIV_SF:
            errStatus = Mcu_Ip_CkgenSfBusSetDivRate(base, rate);
            break;

        case CKGEN_BUS_ID_TYPE_DIV_SP:
            errStatus = Mcu_Ip_CkgenSpBusSetDivRate(base, rate);
            break;

        default:
            errStatus = Mcu_Ip_CkgenBusDivMnpqSetRate(base, id, srcRate, rate);
            break;
        }
    }

    return errStatus;
}

Mcu_CkgenRateType Mcu_Ip_CkgenCoreGetRate(uint32 base, uint32 id,
        Mcu_CkgenRateType srcRate)
{
    uint32 ctrlReg = CKGEN_CORE_CTL_BASE(base, id);
    uint32 ctrlVal;
    uint32 divNum;
    uint32 srcSel;

    ctrlVal = readl(ctrlReg);
    srcSel = (ctrlVal >> CKGEN_CORE_CTL_SRC_SEL_LSB) & CKGEN_CORE_CTL_SRC_SEL_MASK;

    /* sel ck_in4 */
    if (0U != (srcSel & (1U << CKGEN_CORE_CTL_SRC_SEL_CKIN4)))
    {
        divNum = 0U;
    }
    /* sel ck_in0 ~ ck_in3 */
    else
    {
        divNum = (ctrlVal >> CKGEN_CORE_CTL_DIV_NUM_LSB) & CKGEN_CORE_CTL_DIV_NUM_MASK;
    }

    return (Mcu_CkgenRateType)srcRate / (Mcu_CkgenRateType)(divNum + 1U);
}

/** Traceability       : SW_SM005 SW_MCU_SM012*/
Std_ReturnType Mcu_Ip_CkgenCoreSetRate(uint32 base, Mcu_ClkNodeType *clkPtr, Mcu_CkgenRateType rate)
{
    uint32 divNum = 0U;
    uint8 mux;
    Std_ReturnType errStatus = E_OK;
    uint32 ctrlReg = CKGEN_CORE_CTL_BASE(base, clkPtr->id);

    /* select the suitable parent */
    mux = clkPtr->core->ops->selectParent(clkPtr, rate, &divNum);

    if (MCU_CLK_PARENT_NUM == mux)
    {
        errStatus = MCU_E_OUTRANGE;
    }
    else
    {
        /* if mux is 0~3, set pre div to avoid freq is too high first. */
        if (mux != 4U)
        {
            /*set reg_pre_en to 1b1, wait pre_en_ack to 1b1.*/
            RMWREG32(ctrlReg, CKGEN_CORE_CTL_PRE_EN, 1U, 1U);

            if (FALSE == Mcu_Ip_WaitForBitTimes(ctrlReg, CKGEN_CORE_CTL_PRE_EN_STATUS,
                                                1U, CKGEN_WAIT_TIME))
            {
                errStatus = MCU_E_TIMEOUT;
            }
            else
            {
                errStatus = Mcu_Ip_CkgenDrvCoreSliceSetDiv(base, clkPtr->id, 2U);
            }
        } /* else not needed */

        if (E_OK == errStatus)
        {
            /* set pre mux */
            errStatus = Mcu_Ip_CkgenDrvCoreSliceSetMux(base, clkPtr->id, mux);

            if (E_OK == errStatus)
            {
                /* if mux is 0~3, set pre divNum */
                if (mux != 4U)
                {
                    errStatus = Mcu_Ip_CkgenDrvCoreSliceSetDiv(base, clkPtr->id, divNum);
                } /* else not needed */
            } /* else not needed */
        }/* else not needed */
    }

    return errStatus;
}
Std_ReturnType Mcu_Ip_CkgenXcgSetGatingByMode(uint32 base, uint32 id,
        uint8 lpMode, boolean en)
{
    uint32 ctrlReg = Mcu_Ip_CkgenXcgGetCtrlReg(base, id);
    Std_ReturnType errStatus = MCU_E_PARAM_CONFIG;

    if ((CKGEN_RUN_MODE == lpMode) || (CKGEN_HIB_MODE == lpMode) || (CKGEN_SLP_MODE == lpMode))
    {
        RMWREG32(ctrlReg, lpMode, 1U, en);
        errStatus = E_OK;
    } /* else not needed */

    return errStatus;
}
#ifndef CONFIG_CLK_MONITOR
boolean Mcu_Ip_CkgenXcgIsGated(uint32 base, uint32 id)
{
    boolean ret;
    uint32 ctrlReg = Mcu_Ip_CkgenXcgGetCtrlReg(base, id);

    if (1U == ((readl(ctrlReg) >> CKGEN_CG_CTL_CG_GATED) & 0x1U))
    {
        ret = TRUE;
    }
    else
    {
        ret = FALSE;
    }

    return ret;
}
#endif
#ifdef CONFIG_CLK_MONITOR
static Mcu_CkgenRateType Mcu_Ip_CkgenMonCalcFreq(uint32 base, uint16 freqMon, uint8 divAorB)
{
    uint32 glbCtrlVal;
    uint32 divAorBNum;
    Mcu_CkgenRateType rate;

    glbCtrlVal = readl(CKGEN_GLB_CTL_BASE(base));

    if (1U == divAorB)
    {
        /* 24M divb */
        divAorBNum = (glbCtrlVal >> CKGEN_GLB_CTL_24M_DIVB_NUM_LSB) & CKGEN_GLB_CTL_24M_DIVB_NUM_MASK;
    }
    else
    {
        /* 24M diva */
        divAorBNum = (glbCtrlVal >> CKGEN_GLB_CTL_24M_DIVA_NUM_LSB) & CKGEN_GLB_CTL_24M_DIVA_NUM_MASK;
    }

    rate = 12000000U / (divAorBNum + 1U);
    rate = rate * freqMon;

    return rate;
}

static void Mcu_Ip_CkgenDbgMonSrcConfig(uint32 base, uint8 src, uint32 id)
{
    uint32 dbgMonSrc = base + CKGEN_DBG_MON_CLK_SRC;
    uint32 dbgMonCtl = base + CKGEN_DBG_MON_CTL;

    RMWREG32(dbgMonSrc, CKGEN_DBG_MON_CLK_SRC_LSB(src), 8U, id);
    RMWREG32(dbgMonCtl, CKGEN_DBG_MON_CTL_CLK_SEL_LSB, 2U, src);
}

static void Mcu_Ip_CkgenSetMonDivNum(uint32 base, uint8 divType, uint32 divNum)
{
    uint32 glbCtrl = CKGEN_GLB_CTL_BASE(base);
    uint32 divOff;
    uint32 divWidth;
    uint32 divMask;

    if (CKGEN_MON_DIVA == divType)
    {
        divOff = CKGEN_GLB_CTL_24M_DIVA_NUM_LSB;
        divWidth = 10U;
        divMask = CKGEN_GLB_CTL_24M_DIVA_NUM_MASK;

        if (((readl(glbCtrl) & (divMask << divOff) ) >> divOff) != divNum)
        {
            RMWREG32(glbCtrl, divOff, divWidth, divNum);
        } /* else not needed */
    }
    else if (CKGEN_MON_DIVB == divType)
    {
        divOff = CKGEN_GLB_CTL_24M_DIVB_NUM_LSB;
        divWidth = 10U;
        divMask = CKGEN_GLB_CTL_24M_DIVB_NUM_MASK;

        if (((readl(glbCtrl) & (divMask << divOff) ) >> divOff) != divNum)
        {
            RMWREG32(glbCtrl, divOff, divWidth, divNum);
        } /* else not needed */
    }
    else
    {
        ; /* nothing to do*/
    }


}

static void Mcu_Ip_CkgenCqmEnable(uint32 base, uint32 id,
                                  uint16 duty, uint16 jitter)
{
    uint32 dbgMonCtl = base + CKGEN_DBG_MON_CTL;
    uint32 cqmCtl = CKGEN_CQM_CTL_BASE(base, id);

    /* enable cqm gating */
    RMWREG32(dbgMonCtl, CKGEN_DBG_MON_CTL_CQM_GATING_EN, 1U, 1U);

    /* config cqm jitter and duty */
    RMWREG32(cqmCtl, CKGEN_CQM_CTL_JITTER_RATE_LSB, 6U, jitter);
    RMWREG32(cqmCtl, CKGEN_CQM_CTL_DUTY_RATE_LSB, 6U, duty);

    /* enable cqm mon */
    RMWREG32(cqmCtl, CKGEN_CQM_CTL_MON_EN, 1U, 1U);
}

static void Mcu_Ip_CkgenCqmDisable(uint32 base, Mcu_CqmType id)
{
    uint32 dbgMonCtl = base + CKGEN_DBG_MON_CTL;
    uint32 cqmCtl = CKGEN_CQM_CTL_BASE(base, (uint32)id);

    RMWREG32(cqmCtl, CKGEN_CQM_CTL_MON_EN, 1U, 0U);
    RMWREG32(dbgMonCtl, CKGEN_DBG_MON_CTL_CQM_GATING_EN, 1U, 0U);
}


static boolean Mcu_Ip_CkgenCqmGetDutyIntState(uint32 base, uint32 id)
{
    boolean ret;
    uint32 value = MCU_BIT(readl(base + CKGEN_CQM_DUTY_INT_STA), (id % 7U));

    if (0U == value)
    {
        ret = FALSE;
    }
    else
    {
        ret = TRUE;
    }

    return ret;
}

static boolean Mcu_Ip_CkgenCqmGetJitterIntState(uint32 base, uint32 id)
{
    boolean ret;
    uint32 value = MCU_BIT(readl(base + CKGEN_CQM_JITTER_INT_STA), (id % 7U));

    if (0U == value)
    {
        ret = FALSE;
    }
    else
    {
        ret = TRUE;
    }

    return ret;
}

static void Mcu_Ip_CkgenCqmClearDutyIntState(uint32 base, uint32 id)
{
    RMWREG32(base + CKGEN_CQM_DUTY_INT_STA, (id % 7U), 1U, 0U);
}

static void Mcu_Ip_CkgenCqmClearJitterIntState(uint32 base, uint32 id)
{
    RMWREG32(base + CKGEN_CQM_JITTER_INT_STA, (id % 7U), 1U, 0U);
}

/** Traceability       : SW_SM005*/
static uint32 Mcu_Ip_Ckgen24MMonGetRate(uint32 base)
{
    uint32 lowSpdChkCtl = base + CKGEN_LOW_SPD_CHK_CTL;
    uint32 mon_val;
    uint32 freqMon;
    uint32 rate = UINT32_MAX;
    boolean disableFlag = TRUE;
    uint32 value = MCU_BIT(readl(lowSpdChkCtl), CKGEN_LOW_SPD_CHK_CTL_MON_EN);

    if (0U != value)
    {
        RMWREG32(lowSpdChkCtl, CKGEN_LOW_SPD_CHK_CTL_MON_EN, 1U, 0U);

        if (FALSE == Mcu_Ip_WaitForBitTimes(lowSpdChkCtl, CKGEN_LOW_SPD_CHK_CTL_MON_EN_STA,
                                            0U, CKGEN_WAIT_TIME))
        {
            disableFlag = FALSE;
        } /* else not needed */
    }/* else not needed */

    if (TRUE == disableFlag)
    {
        /* set 32k 24m src */
        RMWREG32(lowSpdChkCtl, CKGEN_LOW_SPD_CHK_CTL_24M_SEL, 6U, 0U);
        RMWREG32(lowSpdChkCtl, CKGEN_LOW_SPD_CHK_CTL_32K_SEL, 6U, 0U);

        /* clear freq mon */
        RMWREG32(lowSpdChkCtl, CKGEN_LOW_SPD_CHK_CTL_FREQ_MON_LSB, 16U, 0U);
        RMWREG32(lowSpdChkCtl, CKGEN_LOW_SPD_CHK_CTL_MON_UPD, 1U, 0U);

        /* enable mon */
        RMWREG32(lowSpdChkCtl, CKGEN_LOW_SPD_CHK_CTL_LOSS_DIS, 1U, 0U);
        RMWREG32(lowSpdChkCtl, CKGEN_LOW_SPD_CHK_CTL_MON_EN, 1U, 1U);

        if (TRUE == Mcu_Ip_WaitForBitTimes(lowSpdChkCtl, CKGEN_LOW_SPD_CHK_CTL_MON_EN_STA, 1U,
                                           CKGEN_WAIT_TIME))
        {
            if (TRUE == Mcu_Ip_WaitForBitTimes(lowSpdChkCtl, CKGEN_LOW_SPD_CHK_CTL_MON_UPD, 1U,
                                               CKGEN_WAIT_TIME))
            {
                mon_val = readl(lowSpdChkCtl);
                freqMon = (mon_val >> CKGEN_LOW_SPD_CHK_CTL_FREQ_MON_LSB) & CKGEN_LOW_SPD_CHK_CTL_FREQ_MON_MASK;
                rate = freqMon * 32000U;
            } /* else not needed */
        } /* else not needed */

        RMWREG32(lowSpdChkCtl, CKGEN_LOW_SPD_CHK_CTL_MON_EN, 1U, 0U);

        if (FALSE == Mcu_Ip_WaitForBitTimes(lowSpdChkCtl, CKGEN_LOW_SPD_CHK_CTL_MON_EN_STA,
                                            0U, CKGEN_WAIT_TIME))
        {
            rate = UINT32_MAX;
        } /* else not needed */
    }

    return rate;
}

/**
 * \brief Get Monitor Moudel Freq interface
 *
 * \param[in] sliceType        slice type
 * \param[in] typeIndex        slice index
 * \return    Mon-freq
 */
static uint32 Mcu_Ip_CkgenGetMonitorClock(uint32 base, Mcu_ClkSliceType sliceType, uint32 typeIndex,
        uint32 rate)
{
    uint32 ui32MonBaseClk = UINT32_MAX;
    uint32 ui32GlbCtrlVal;
    uint32 ui32MonCtrl_Reg;
    uint8 ui8IpMonSrcSel;
    uint16 ui16ClkMonDiv;

    if (sliceType < MCU_MAX_TYPE)
    {
        if (MCU_XTAL_24M == sliceType)
        {
            ui32MonBaseClk = LOW_32K_FREQ;
        }
        else
        {
            if (MCU_IP_SLICE == sliceType)
            {
                ui32MonCtrl_Reg =  REG_READ32(CKGEN_IP_MON_CTL_BASE(base, (uint32)typeIndex));
            }
            else if (MCU_CORE_SLICE == sliceType)
            {
                ui32MonCtrl_Reg =  REG_READ32(CKGEN_CORE_MON_CTL_BASE(base, (uint32)typeIndex));
            }
            else
            {
                ui32MonCtrl_Reg =  REG_READ32(CKGEN_BUS_MON_CTL0_BASE(base, (uint32)typeIndex));
            }

            ui8IpMonSrcSel = (uint8)((ui32MonCtrl_Reg >> CKGEN_IP_MON_CTL_SRC_SEL) & 0x1U) ;

            /* Ip Mon src selection mon-b*/
            if (1U == ui8IpMonSrcSel)
            {
                if (rate < 1000000U)
                {
                    Mcu_Ip_CkgenSetMonDivNum(base, CKGEN_MON_DIVB, 0x3FFu);
                }
                else
                {
                    Mcu_Ip_CkgenSetMonDivNum(base, CKGEN_MON_DIVB, 0xFFu);
                }

                ui32GlbCtrlVal = REG_READ32(CKGEN_GLB_CTL_BASE(base));

                ui16ClkMonDiv = (uint16)(ui32GlbCtrlVal >> CKGEN_GLB_CTL_24M_DIVB_NUM_LSB) &
                                CKGEN_GLB_CTL_24M_DIVB_NUM_MASK;
                ui32MonBaseClk = 24000000U / ((uint32)ui16ClkMonDiv + 1U);
                ui32MonBaseClk = ui32MonBaseClk / 2U;
            }
            /* Ip Mon src selection mon-a*/
            else
            {
                if (rate < 1000000U)
                {
                    Mcu_Ip_CkgenSetMonDivNum(base, CKGEN_MON_DIVA, 0x3FFu);
                }
                else
                {
                    Mcu_Ip_CkgenSetMonDivNum(base, CKGEN_MON_DIVA, 0xFFu);
                }

                ui32GlbCtrlVal = REG_READ32(CKGEN_GLB_CTL_BASE(base));

                ui16ClkMonDiv = (uint16)(ui32GlbCtrlVal >> CKGEN_GLB_CTL_24M_DIVA_NUM_LSB) &
                                CKGEN_GLB_CTL_24M_DIVA_NUM_MASK;
                ui32MonBaseClk = 24000000U / ((uint32)ui16ClkMonDiv + 1U);
                ui32MonBaseClk = ui32MonBaseClk / 2U;
            }
        }
    }


    return ui32MonBaseClk;

}

static boolean Mcu_Ip_CkgenIpGetIntState(uint32 base, uint32 id)
{
    boolean ret;
    uint32 state = CKGEN_IP_CLK_INT_STA_BASE(base, (id / 32U));

    if (0U == MCU_BIT(readl(state), (id % 32U)))
    {
        ret = FALSE;
    }
    else
    {
        ret = TRUE;
    }

    return ret;
}

static void Mcu_Ip_CkgenIpClearIntState(uint32 base, uint32 id)
{
    uint32 reg = CKGEN_IP_CLK_INT_STA_BASE(base, (id / 32U));
    RMWREG32(reg, (id % 32U), 1U, 0U);
}

static boolean Mcu_Ip_CkgenBusGetIntState(uint32 base, uint32 id)
{
    boolean ret;
    uint32 state = CKGEN_BUS_CLK_INT_STA_BASE(base,
                   ((id & CKGEN_BUS_ID_NUM_MASK) / 32U));

    if (0U == MCU_BIT(readl(state), ((id & CKGEN_BUS_ID_NUM_MASK) % 32U)))
    {
        ret = FALSE;
    }
    else
    {
        ret = TRUE;
    }

    return ret;
}

static void Mcu_Ip_CkgenBusClearIntState(uint32 base, uint32 id)
{
    uint32 reg = CKGEN_BUS_CLK_INT_STA_BASE(base,
                                            ((id & CKGEN_BUS_ID_NUM_MASK) / 32U));
    RMWREG32(reg, ((id & CKGEN_BUS_ID_NUM_MASK) % 32U), 1U, 0U);
}

static boolean Mcu_Ip_CkgenCoreGetIntState(uint32 base, uint32 id)
{
    boolean ret;
    uint32 state = CKGEN_CORE_CLK_INT_STA_BASE(base, (id / 32U));

    if (0U == MCU_BIT(readl(state), (id % 32U)))
    {
        ret = FALSE;
    }
    else
    {
        ret = TRUE;
    }

    return ret;
}

static void Mcu_Ip_CkgenCoreClearIntState(uint32 base, uint32 id)
{
    uint32 reg = CKGEN_CORE_CLK_INT_STA_BASE(base, (id / 32U));
    RMWREG32(reg, (id % 32U), 1U, 0U);
}

static boolean Mcu_Ip_Ckgen24MGetIntState(uint32 base)
{
    boolean ret;
    uint32 state = base + CKGEN_LOW_SPD_INT_STA;

    if (0U == MCU_BIT(readl(state), 0U))
    {
        ret = FALSE;
    }
    else
    {
        ret = TRUE;
    }

    return ret;
}

static void Mcu_Ip_Ckgen24MClearIntState(uint32 base)
{
    uint32 reg = base + CKGEN_LOW_SPD_INT_STA;
    RMWREG32(reg, 0U, 1U, 0U);
}

static void Mcu_Ip_Ckgen24MMonSetThrd(uint32 base, uint16 lowThrd, uint16 highThrd)
{
    uint32 monThrd = base + CKGEN_LOW_SPD_CHK_THRD;

    RMWREG32(monThrd, CKGEN_LOW_SPD_CHK_THRD_LOW_LSB, 16U, lowThrd);
    RMWREG32(monThrd, CKGEN_LOW_SPD_CHK_THRD_HIGH_LSB, 16U, highThrd);
}

static void Mcu_Ip_CkgenSetThrdIntValue(uint32 base, Mcu_ClkSliceType sliceType, uint8 typeIndex)
{
    if (MCU_IP_SLICE == sliceType)
    {
        /* clear mon thrd */
        REG_WRITE32(0xFFFF0000U, base + CKGEN_IP_MON_THRD + ((uint32)typeIndex * 0x10U));
    }
    else if (MCU_CORE_SLICE == sliceType)
    {
        /* clear mon thrd */
        REG_WRITE32(0xFFFF0000U, base + CKGEN_CORE_MON_THRD + ((uint32)typeIndex * 0x10U));
    }
    else if (MCU_BUS_SLICE == sliceType)
    {
        /* clear mon thrd */
        REG_WRITE32(0xFFFF0000U, base + CKGEN_BUS_MON_THRD0 + ((uint32)typeIndex * 0x28U));
        REG_WRITE32(0xFFFF0000U, base + CKGEN_BUS_MON_THRD1 + ((uint32)typeIndex * 0x28U));
        REG_WRITE32(0xFFFF0000U, base + CKGEN_BUS_MON_THRD2 + ((uint32)typeIndex * 0x28U));
        REG_WRITE32(0xFFFF0000U, base + CKGEN_BUS_MON_THRD3 + ((uint32)typeIndex * 0x28U));
    }
    else if (MCU_XTAL_24M == sliceType)
    {
        /* clear mon thrd */
        REG_WRITE32(0x0BB8007Du, base + CKGEN_LOW_SPD_CHK_THRD);
    }
    else
    {
        /*do nothing*/
    }

}

static void Mcu_Ip_CkgenClearIntStatus(uint32 base, Mcu_ClkSliceType sliceType, uint8 typeIndex)
{
    switch (sliceType)
    {
    case MCU_IP_SLICE:
        /* clear mon int flag */
        Mcu_Ip_CkgenIpClearIntState(base, typeIndex);
        break;

    case MCU_CORE_SLICE:
        /* clear mon int flag */
        Mcu_Ip_CkgenCoreClearIntState(base, typeIndex);
        break;

    case MCU_BUS_SLICE:
        /* clear mon int flag */
        Mcu_Ip_CkgenBusClearIntState(base, typeIndex);
        break;

    case MCU_XTAL_24M:
        /* clear mon int flag */
        Mcu_Ip_Ckgen24MClearIntState(APB_CKGEN_SF_BASE);
        break;

    default:
        /*do nothing */
        break;
    }
}

static void Mcu_Ip_CkgenSliceMonClrBusErrStatus(uint32 base, Mcu_ClkSliceType sliceType,
        uint8 typeIndex)
{
    Mcu_Ip_CkgenSetThrdIntValue(base, sliceType, typeIndex);
    Mcu_Ip_CkgenClearIntStatus(base, sliceType, typeIndex);
}

void Mcu_Ip_CkgenDbgMonIpSelect(uint32 base, uint32 id, uint8 divNum)
{
    uint32 ipCtrl = CKGEN_IP_CTL_BASE(base, id);
    uint32 dbgMonCtl = base + CKGEN_DBG_MON_CTL;
    uint32 dbgCtl = base + CKGEN_DBG_CTL;

    RMWREG32(dbgCtl, CKGEN_DBG_CTL_DIV_LSB, CKGEN_DBG_CTL_DIV_MASK, ((uint32)divNum - 1U));
    RMWREG32(ipCtrl, CKGEN_IP_CTL_DBG_EN, 1U, 1U);
    Mcu_Ip_CkgenDbgMonSrcConfig(base, 0, id);
    RMWREG32(dbgMonCtl, CKGEN_DBG_MON_CTL_DBG_GATING_EN, 1U, 1U);
}

void Mcu_Ip_CkgenDbgMonBusSelect(uint32 base, uint32 id, uint8 divNum)
{
    uint32 busCtrl = CKGEN_BUS_CTL_BASE(base, id);
    uint32 dbgMonCtl = base + CKGEN_DBG_MON_CTL;
    uint32 dbgCtl = base + CKGEN_DBG_CTL;

    RMWREG32(dbgCtl, CKGEN_DBG_CTL_DIV_LSB, CKGEN_DBG_CTL_DIV_MASK, ((uint32)divNum - 1U));
    RMWREG32(busCtrl, CKGEN_BUS_CTL_DBG_EN, 1U, 1U);
    Mcu_Ip_CkgenDbgMonSrcConfig(base, 1, id);
    RMWREG32(dbgMonCtl, CKGEN_DBG_MON_CTL_DBG_GATING_EN, 1U, 1U);
}

void Mcu_Ip_CkgenDbgMonCoreSelect(uint32 base, uint32 id, uint8 divNum)
{
    uint32 coreCtrl = CKGEN_CORE_CTL_BASE(base, id);
    uint32 dbgMonCtl = base + CKGEN_DBG_MON_CTL;
    uint32 dbgCtl = base + CKGEN_DBG_CTL;

    RMWREG32(dbgCtl, CKGEN_DBG_CTL_DIV_LSB, CKGEN_DBG_CTL_DIV_MASK, ((uint32)divNum - 1U));
    RMWREG32(coreCtrl, CKGEN_CORE_CTL_DBG_EN, 1U, 1U);
    Mcu_Ip_CkgenDbgMonSrcConfig(base, 2, id);
    RMWREG32(dbgMonCtl, CKGEN_DBG_MON_CTL_DBG_GATING_EN, 1U, 1U);
}

/** Traceability       : SW_SM005*/
Mcu_CkgenRateType Mcu_Ip_CkgenIpMonGetRate(uint32 base, uint32 id, Mcu_ClkRateType rate)
{
    uint32 ipMonCtrl = CKGEN_IP_MON_CTL_BASE(base, id);
    uint32 ipCtrl = CKGEN_IP_CTL_BASE(base, id);
    uint32 ipMonCtrlVal;
    uint16 freqMon;
    uint8 divAorB;
    Mcu_ClkRateType rateGet = UINT32_MAX;
    boolean disableFlag = TRUE;
    uint32 value = MCU_BIT(readl(ipMonCtrl), CKGEN_IP_MON_CTL_EN);

    /* disable ip mon */
    if (0U != value)
    {
        RMWREG32(ipMonCtrl, CKGEN_IP_MON_CTL_EN, 1U, 0U);

        if (FALSE == Mcu_Ip_WaitForBitTimes(ipMonCtrl, CKGEN_IP_MON_CTL_EN_STA, 0U, CKGEN_WAIT_TIME))
        {
            disableFlag = FALSE;
        } /* else not needed */
    }/* else not needed */

    if (TRUE == disableFlag)
    {
        /* clear freq mon */
        RMWREG32(ipMonCtrl, CKGEN_IP_MON_CTL_FREQ_LSB, 16U, 0U);
        RMWREG32(ipMonCtrl, CKGEN_IP_MON_CTL_FREQ_UPD, 1U, 0U);

        if (rate < 1000000U)
        {
            Mcu_Ip_CkgenSetMonDivNum(base, CKGEN_MON_DIVA, 0x3FFu);
        }
        else
        {
            Mcu_Ip_CkgenSetMonDivNum(base, CKGEN_MON_DIVA, 0xFFu);
        }

        /* enable ip slice debug */
        RMWREG32(ipCtrl, CKGEN_IP_CTL_DBG_EN, 1U, 1U);

        /* enable ip mon */
        RMWREG32(ipMonCtrl, CKGEN_IP_MON_CTL_EN, 1U, 1U);

        if (TRUE == Mcu_Ip_WaitForBitTimes(ipMonCtrl, CKGEN_IP_MON_CTL_EN_STA, 1U, CKGEN_WAIT_TIME))
        {
            if (TRUE == Mcu_Ip_WaitForBitTimes(ipMonCtrl, CKGEN_IP_MON_CTL_FREQ_UPD, 1U, CKGEN_WAIT_TIME))
            {
                ipMonCtrlVal = readl(ipMonCtrl);
                freqMon = (uint16)((ipMonCtrlVal >> CKGEN_IP_MON_CTL_FREQ_LSB) & CKGEN_IP_MON_CTL_FREQ_MASK);
                divAorB = (uint8)((ipMonCtrlVal >> CKGEN_IP_MON_CTL_SRC_SEL) & 0x1U);

                rateGet = Mcu_Ip_CkgenMonCalcFreq(base, freqMon, divAorB);
            } /* else not needed */
        } /* else not needed */

        /* disable ip mon */
        RMWREG32(ipMonCtrl, CKGEN_IP_MON_CTL_EN, 1U, 0U);

        if (TRUE == Mcu_Ip_WaitForBitTimes(ipMonCtrl, CKGEN_IP_MON_CTL_EN_STA,
                                           0U, CKGEN_WAIT_TIME))
        {
            /* disable ip slice debug */
            RMWREG32(ipCtrl, CKGEN_IP_CTL_DBG_EN, 1U, 0U);
        }
        else
        {
            rateGet = UINT32_MAX;
        }

    }

    return rateGet;
}

static void Mcu_Ip_CkgenIpMonSetThrd(uint32 base, uint32 id,
                                     uint16 lowThrd, uint16 highThrd)
{
    uint32 monThrd = CKGEN_IP_MON_THRD_BASE(base, id);
    RMWREG32(monThrd, CKGEN_IP_MON_THRD_LOW_LSB, 16U, lowThrd);
    RMWREG32(monThrd, CKGEN_IP_MON_THRD_HIGH_LSB, 16U, highThrd);
}

static uint32 Mcu_Ip_CkgenBusMonType(uint32 base, uint32 id, uint32 *busMonOutPtr,
                                     uint32 *freqLsbPtr)
{
    uint32 type = CKGEN_BUS_ID_TYPE(id);
    uint32 out;

    if (CKGEN_BUS_ID_TYPE_DIV_N == type)
    {
        out = 1U;
        *busMonOutPtr = CKGEN_BUS_MON_CTL1_BASE(base, id);
        *freqLsbPtr = CKGEN_BUS_MON_CTL1_FREQ1_LSB;
    }
    else if (CKGEN_BUS_ID_TYPE_DIV_P == type)
    {
        out = 2U;
        *busMonOutPtr = CKGEN_BUS_MON_CTL2_BASE(base, id);
        *freqLsbPtr = CKGEN_BUS_MON_CTL2_FREQ2_LSB;
    }
    else if (CKGEN_BUS_ID_TYPE_DIV_Q == type)
    {
        out = 3U;
        *busMonOutPtr = CKGEN_BUS_MON_CTL2_BASE(base, id);
        *freqLsbPtr = CKGEN_BUS_MON_CTL2_FREQ3_LSB;
    }
    else
    {
        out = 0U;
        *busMonOutPtr = CKGEN_BUS_MON_CTL1_BASE(base, id);
        *freqLsbPtr = CKGEN_BUS_MON_CTL1_FREQ0_LSB;
    }

    return out;
}

/** Traceability       : SW_SM005*/
Mcu_CkgenRateType Mcu_Ip_CkgenBusMonGetRate(uint32 base, uint32 id)
{
    uint32 busMonCtrl = CKGEN_BUS_MON_CTL0_BASE(base, id);
    uint32 busMonOut;
    uint32 busCtrl = CKGEN_BUS_CTL_BASE(base, id);

    uint32 freqLsb;
    uint32 out;
    uint32 busMonCtrlVal;
    uint16 freqMon;
    uint8 divAorB;
    Mcu_CkgenRateType rate = UINT32_MAX;
    boolean disableFlag = TRUE;
    uint32 value = MCU_BIT(readl(busMonCtrl), CKGEN_BUS_MON_CTL0_EN);

    out = Mcu_Ip_CkgenBusMonType(base, id, &busMonOut, &freqLsb);

    /* disable bus mon */
    if (0U != value)
    {
        RMWREG32(busMonCtrl, CKGEN_BUS_MON_CTL0_EN, 1U, 0U);

        if (FALSE == Mcu_Ip_WaitForBitTimes(busMonCtrl, CKGEN_BUS_MON_CTL0_EN_STA,
                                            0U, CKGEN_WAIT_TIME))
        {
            disableFlag = FALSE;
        } /* else not needed */
    } /* else not needed */

    if (TRUE == disableFlag)
    {
        /* clear freq mon */
        writel(0U, busMonOut);
        RMWREG32(busMonCtrl, CKGEN_BUS_MON_CTL0_FREQ_UPD(out), 1U, 0U);

        /* enable bus slice debug */
        RMWREG32(busCtrl, CKGEN_BUS_CTL_DBG_EN, 1U, 1U);

        /* enable bus mon */
        RMWREG32(busMonCtrl, CKGEN_BUS_MON_CTL0_EN, 1U, 1U);

        if (TRUE == Mcu_Ip_WaitForBitTimes(busMonCtrl, CKGEN_BUS_MON_CTL0_EN_STA, 1U, CKGEN_WAIT_TIME))
        {
            if (TRUE == Mcu_Ip_WaitForBitTimes(busMonCtrl, CKGEN_BUS_MON_CTL0_FREQ_UPD(out), 1U,
                                               CKGEN_WAIT_TIME))
            {
                freqMon = (uint16)((readl(busMonOut) >> freqLsb) & CKGEN_BUS_MON_CTL_FREQ_MASK);

                busMonCtrlVal = readl(busMonCtrl);
                divAorB = (uint8)((busMonCtrlVal >> CKGEN_BUS_MON_CTL0_SRC_SEL) & 0x1U);

                rate = Mcu_Ip_CkgenMonCalcFreq(base, freqMon, divAorB);
            } /* else not needed */
        } /* else not needed */

        /* disable bus mon */
        RMWREG32(busMonCtrl, CKGEN_BUS_MON_CTL0_EN, 1U, 0U);

        if (TRUE == Mcu_Ip_WaitForBitTimes(busMonCtrl, CKGEN_BUS_MON_CTL0_EN_STA,
                                           0U, CKGEN_WAIT_TIME))
        {
            /* disable bus slice debug */
            RMWREG32(busCtrl, CKGEN_BUS_CTL_DBG_EN, 1U, 0U);
        }
        else
        {
            rate = UINT32_MAX;
        }

    }

    return rate;
}

static void Mcu_Ip_CkgenBusMonSetThrd(uint32 base, uint32 id,
                                      uint16 lowThrd, uint16 highThrd)
{
    uint32 type = CKGEN_BUS_ID_TYPE(id);
    uint32 bus_mon_thrd;

    if (CKGEN_BUS_ID_TYPE_DIV_N == type)
    {
        bus_mon_thrd = CKGEN_BUS_MON_THRD1_BASE(base, id);
    }
    else if (CKGEN_BUS_ID_TYPE_DIV_P == type)
    {
        bus_mon_thrd = CKGEN_BUS_MON_THRD2_BASE(base, id);
    }
    else if (CKGEN_BUS_ID_TYPE_DIV_Q == type)
    {
        bus_mon_thrd = CKGEN_BUS_MON_THRD3_BASE(base, id);
    }
    else
    {
        bus_mon_thrd = CKGEN_BUS_MON_THRD0_BASE(base, id);
    }

    RMWREG32(bus_mon_thrd, CKGEN_BUS_MON_THRD_LOW_LSB, 16U, lowThrd);
    RMWREG32(bus_mon_thrd, CKGEN_BUS_MON_THRD_HIGH_LSB, 16U, highThrd);
}

/** Traceability       : SW_SM005*/
Mcu_CkgenRateType Mcu_Ip_CkgenCoreMonGetRate(uint32 base, uint32 id)
{
    uint32 coreMonCtrl = CKGEN_CORE_MON_CTL_BASE(base, id);
    uint32 coreCtrl = CKGEN_CORE_CTL_BASE(base, id);
    uint32 coreMonCtrlVal;
    uint16 freqMon;
    uint8 divAorB;
    Mcu_CkgenRateType rate = UINT32_MAX;
    boolean disableFlag = TRUE;
    uint32 value = MCU_BIT(readl(coreMonCtrl), CKGEN_CORE_MON_CTL_EN);

    /* disable core mon */
    if (0U != value)
    {
        RMWREG32(coreMonCtrl, CKGEN_CORE_MON_CTL_EN, 1U, 0U);

        if (FALSE == Mcu_Ip_WaitForBitTimes(coreMonCtrl, CKGEN_CORE_MON_CTL_EN_STA,
                                            0U, CKGEN_WAIT_TIME))
        {
            disableFlag = FALSE;
        } /* else not needed */
    }/* else not needed */

    if (TRUE == disableFlag)
    {

        /* clear freq mon */
        RMWREG32(coreMonCtrl, CKGEN_CORE_MON_CTL_FREQ_LSB, 16U, 0U);
        RMWREG32(coreMonCtrl, CKGEN_CORE_MON_CTL_FREQ_UPD, 1U, 0U);

        /* enable core slice debug */
        RMWREG32(coreCtrl, CKGEN_CORE_CTL_DBG_EN, 1U, 1U);

        /* enable core mon */
        RMWREG32(coreMonCtrl, CKGEN_CORE_MON_CTL_EN, 1U, 1U);

        if (TRUE == Mcu_Ip_WaitForBitTimes(coreMonCtrl, CKGEN_CORE_MON_CTL_EN_STA, 1U, CKGEN_WAIT_TIME))
        {
            if (TRUE == Mcu_Ip_WaitForBitTimes(coreMonCtrl, CKGEN_CORE_MON_CTL_FREQ_UPD, 1U, CKGEN_WAIT_TIME))
            {
                coreMonCtrlVal = readl(coreMonCtrl);
                freqMon = (uint16)((coreMonCtrlVal >> CKGEN_CORE_MON_CTL_FREQ_LSB) &
                                   CKGEN_CORE_MON_CTL_FREQ_MASK);
                divAorB = (uint8)((coreMonCtrlVal >> CKGEN_CORE_MON_CTL_SRC_SEL) & 0x1U);

                rate = Mcu_Ip_CkgenMonCalcFreq(base, freqMon, divAorB);
            } /* else not needed */
        } /* else not needed */

        /* disable core mon */
        RMWREG32(coreMonCtrl, CKGEN_CORE_MON_CTL_EN, 1U, 0U);

        if (TRUE == Mcu_Ip_WaitForBitTimes(coreMonCtrl, CKGEN_CORE_MON_CTL_EN_STA,
                                           0U, CKGEN_WAIT_TIME))
        {
            /* disable core slice debug */
            RMWREG32(coreCtrl, CKGEN_CORE_CTL_DBG_EN, 1U, 0U);
        }
        else
        {
            rate = UINT32_MAX;
        }
    }

    return rate;
}

static void Mcu_Ip_CkgenCoreMonSetThrd(uint32 base, uint32 id,
                                       uint16 lowThrd, uint16 highThrd)
{
    uint32 monThrd = CKGEN_CORE_MON_THRD_BASE(base, id);
    RMWREG32(monThrd, CKGEN_CORE_MON_THRD_LOW_LSB, 16U, lowThrd);
    RMWREG32(monThrd, CKGEN_CORE_MON_THRD_HIGH_LSB, 16U, highThrd);
}

void Mcu_Ip_CkgenXcgAmonEnable(uint32 base, uint32 id, boolean en)
{
    uint32 ctrlReg = Mcu_Ip_CkgenXcgGetCtrlReg(base, id);
    RMWREG32(ctrlReg, CKGEN_CG_CTL_ACTIVE_MON_EN, 1U, en);
}

uint8 Mcu_Ip_CkgenXcgGetAmonState(uint32 base, uint32 id)
{
    uint32 ctrlReg = Mcu_Ip_CkgenXcgGetCtrlReg(base, id);
    return (uint8)((readl(ctrlReg) >> CKGEN_CG_CTL_ACTIVE_MON_STA) & 0x1U);
}

/**
 * \brief Monitor Slice freq high or low  interface
 *
 * \param[in] ckgenMonFreqPtr
 * \return    0:succeed     other:fail
 */
/** Traceability       : SW_SM006*/
uint8 Mcu_Ip_CkgenMonFreq(Mcu_CkgenMonFreqType *ckgenMonFreqPtr)
{
    uint8  ui8Res             = 0xFFu;
    uint32 ui32MonSampleCount;
    uint16 ui16MonThrd_Low;
    uint16 ui16MonThrd_High;
    uint32 ui32MonSampleFreq;
    uint32 base;

    if (NULL_PTR != ckgenMonFreqPtr)
    {
        if (MCU_SF_DOMAIN == ckgenMonFreqPtr->domainType)
        {
            base = APB_CKGEN_SF_BASE;
        }

#ifndef SEMIDRIVE_E3_LITE_SERIES
        else
        {
            base = APB_CKGEN_AP_BASE;
        }

#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/
        ui32MonSampleFreq = Mcu_Ip_CkgenGetMonitorClock(base, ckgenMonFreqPtr->sliceType,
                            ckgenMonFreqPtr->typeIndex, ckgenMonFreqPtr->sliceFreq);

        /* calcu the sampe count and the threshold count  */
        ui32MonSampleCount  = ckgenMonFreqPtr->sliceFreq / ui32MonSampleFreq ;
        ui16MonThrd_Low     = (uint16)(ui32MonSampleCount - (ckgenMonFreqPtr->freqTolerantRat *
                                       ui32MonSampleCount / 100U));
        ui16MonThrd_High    = (uint16)(ui32MonSampleCount + (ckgenMonFreqPtr->freqTolerantRat *
                                       ui32MonSampleCount / 100U));
        Mcu_Ip_CkgenSliceMonClrBusErrStatus(base, ckgenMonFreqPtr->sliceType,
                                            (uint8)ckgenMonFreqPtr->typeIndex);

        switch (ckgenMonFreqPtr->sliceType)
        {
        case MCU_IP_SLICE:
            /*config ip slice threshold value */
            Mcu_Ip_CkgenIpMonSetThrd(base, ckgenMonFreqPtr->typeIndex, ui16MonThrd_Low,
                                     ui16MonThrd_High);
            /*get ip slice monitor int state */
            ckgenMonFreqPtr->realFreq = Mcu_Ip_CkgenIpMonGetRate(base, ckgenMonFreqPtr->typeIndex,
                                        ckgenMonFreqPtr->sliceFreq);

            /* get ip slice mon int state */
            ckgenMonFreqPtr->monIntRes = Mcu_Ip_CkgenIpGetIntState(base,
                                         ckgenMonFreqPtr->typeIndex);
            /* clear mon int flag */
            Mcu_Ip_CkgenIpClearIntState(base, ckgenMonFreqPtr->typeIndex);
            break;

        case MCU_CORE_SLICE:
            /*config core slice threshold value */
            Mcu_Ip_CkgenCoreMonSetThrd(base, ckgenMonFreqPtr->typeIndex, ui16MonThrd_Low,
                                       ui16MonThrd_High);
            /*get core slice monitor int state */
            ckgenMonFreqPtr->realFreq = Mcu_Ip_CkgenCoreMonGetRate(base, ckgenMonFreqPtr->typeIndex);

            /* get core slice mon int state */
            ckgenMonFreqPtr->monIntRes = Mcu_Ip_CkgenCoreGetIntState(base,
                                         ckgenMonFreqPtr->typeIndex);
            /* clear mon int flag */
            Mcu_Ip_CkgenCoreClearIntState(base, ckgenMonFreqPtr->typeIndex);
            break;

        case MCU_BUS_SLICE:
            /*config bus slice threshold value */
            Mcu_Ip_CkgenBusMonSetThrd(base,  (ckgenMonFreqPtr->typeIndex), ui16MonThrd_Low,
                                      ui16MonThrd_High);
            /*get bus slice monitor int state */
            ckgenMonFreqPtr->realFreq = Mcu_Ip_CkgenBusMonGetRate(base,  (ckgenMonFreqPtr->typeIndex));
            /* get bus slice mon int state */
            ckgenMonFreqPtr->monIntRes = Mcu_Ip_CkgenBusGetIntState(base,
                                         ckgenMonFreqPtr->typeIndex);
            /* clear mon int flag */
            Mcu_Ip_CkgenBusClearIntState(base, ckgenMonFreqPtr->typeIndex);
            break;

        case MCU_XTAL_24M:
            /*config bus slice threshold value */
            Mcu_Ip_Ckgen24MMonSetThrd(APB_CKGEN_SF_BASE, ui16MonThrd_Low, ui16MonThrd_High);
            /*get bus slice monitor int state */
            ckgenMonFreqPtr->realFreq = Mcu_Ip_Ckgen24MMonGetRate(APB_CKGEN_SF_BASE);
            /* get 24M mon int state */
            ckgenMonFreqPtr->monIntRes = Mcu_Ip_Ckgen24MGetIntState(APB_CKGEN_SF_BASE);
            /* clear mon int flag */
            Mcu_Ip_Ckgen24MClearIntState(APB_CKGEN_SF_BASE);
            break;

        default:
            ckgenMonFreqPtr->monIntRes = 1U;
            break;
        }

        if (1U == ckgenMonFreqPtr->monIntRes)
        {
            ui8Res = 1U ;
        }
        else
        {
            ui8Res = 0U ;
        }
    }/* else not needed */

    return ui8Res;
}

/**
 * \brief Monitor clock duty and jitter interface
 *
 * \param[in] Mcu_CkgenCqmType   parament
 * \return    0:Duty jtter Normal      1: Duty jtter out of range
 */
uint8 Mcu_Ip_CkgenCqm(Mcu_CkgenCqmType *ckgenCqmPtr)
{
    uint8 ui8Res              = 0xFFu;
    uint8 ui8DutyConVal;
    uint8 ui8JitterConVal;
    uint8 errFlag             = 0U;

    if (NULL_PTR != ckgenCqmPtr)
    {
        /* clear cqmtype,dutyintres,jitterintes to 0*/
        ckgenCqmPtr->cqmType           = MCU_CQM_CKGEN;
        ckgenCqmPtr->dutyIntRes        = 0U;
        ckgenCqmPtr->jitterIntRes      = 0U;

        /* ip slices select  */
        if (MCU_IP_SLICE == ckgenCqmPtr->sliceType)
        {
            Mcu_Ip_CkgenDbgMonIpSelect(APB_CKGEN_SF_BASE, ckgenCqmPtr->typeIndex, 1U);
        }
        /* core slices select  */
        else if (MCU_CORE_SLICE == ckgenCqmPtr->sliceType)
        {
            Mcu_Ip_CkgenDbgMonCoreSelect(APB_CKGEN_SF_BASE, ckgenCqmPtr->typeIndex, 1U);
        }
        /* bus slices select  */
        else if (MCU_BUS_SLICE == ckgenCqmPtr->sliceType)
        {
            Mcu_Ip_CkgenDbgMonBusSelect(APB_CKGEN_SF_BASE, ckgenCqmPtr->typeIndex, 1U);
        }
        else
        {
            errFlag = 1U;
        }

        if (0U == errFlag)
        {
            /*Duty-Percent converts specific values*/
            ui8DutyConVal = ckgenCqmPtr->dutyPercent * 64U / 100U ;

            /*Jitter-Percent converts specific values*/
            ui8JitterConVal = ckgenCqmPtr->jitterPercent * 64U / 100U ;

            if (0U == ui8DutyConVal)
            {
                ui8DutyConVal = 1U ;
            } /* else not needed */

            if (0U == ui8JitterConVal)
            {
                ui8JitterConVal = 1U ;
            } /* else not needed */

            /*config cqm jitter and duty*/
            Mcu_Ip_CkgenCqmEnable(APB_CKGEN_SF_BASE, (uint32)ckgenCqmPtr->cqmType, ui8DutyConVal,
                                  ui8JitterConVal);

            /*get  cqm  duty and jitter int state */
            ckgenCqmPtr->dutyIntRes    = Mcu_Ip_CkgenCqmGetDutyIntState(APB_CKGEN_SF_BASE,
                                         (uint32)ckgenCqmPtr->cqmType);
            ckgenCqmPtr->jitterIntRes  = Mcu_Ip_CkgenCqmGetJitterIntState(APB_CKGEN_SF_BASE,
                                         (uint32)ckgenCqmPtr->cqmType);

            /*Duty and Jitter reslut judgement */
            if ((1U == ckgenCqmPtr->dutyIntRes) || (1U == ckgenCqmPtr->jitterIntRes))
            {
                ui8Res = 1U ;
            }
            else
            {
                ui8Res = 0U ;
            }

            /*Disable cqm function */
            Mcu_Ip_CkgenCqmDisable(APB_CKGEN_SF_BASE, ckgenCqmPtr->cqmType);

            /*Clear cqm duty and jitter bit flag */
            Mcu_Ip_CkgenCqmClearDutyIntState(APB_CKGEN_SF_BASE, (uint32)ckgenCqmPtr->cqmType);
            Mcu_Ip_CkgenCqmClearJitterIntState(APB_CKGEN_SF_BASE, (uint32)ckgenCqmPtr->cqmType);
        }
    }

    return ui8Res;
}

#endif /** #ifdef CONFIG_CLK_MONITOR*/

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
/* End of file */
