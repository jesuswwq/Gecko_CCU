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
 * \file     Mcu_CkgenDrv.c                                                                             *
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
#include "Mcu_CkgenDrv.h"
#include "Mcu_Ckgen.h"
#include "Mcu_Delay.h"

/********************************************************************************************************
 *                                 Private Macro definition                                             *
 *******************************************************************************************************/

#define ABS(x) (((sint32)(x) < 0) ? -(sint32)(x) : (sint32)(x))

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
/** Traceability       : SW_MCU_SM011*/
extern uint8 Mcu_Ip_ClkIsLocked(const Mcu_ClkNodeType *clkPtr);
/********************************************************************************************************
 *                                  Private Function Declarations                                       *
 *******************************************************************************************************/
static boolean Mcu_Ip_CkgenDrvIsBetterRate(uint32 rate, uint32 now, uint32 best)
{
    boolean ret;

    if (ABS((sint32)now - (sint32)rate) <= ABS((sint32)best - (sint32)rate))
    {
        ret = TRUE;
    }
    else
    {
        ret = FALSE;
    }

    return ret;
}

/** Traceability       : SW_SM006 SW_MCU_SM011 SW_MCU_SM012*/
static Std_ReturnType Mcu_Ip_CkgenDrvIpPrepare(Mcu_ClkNodeType *clkPtr)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;
    uint32 base;
    uint8 isLocked;

    if ((NULL_PTR != clkPtr) && (NULL_PTR != clkPtr->core))
    {
        base = clkPtr->core->base;

        /* if pll not ready, means this is the first config after reset,
        * don't change mux when pll is not ready. */
        if (5U == clkPtr->parentsNum)
        {
            isLocked = Mcu_Ip_ClkIsLocked(clkPtr->parents[4]);
        }
        else
        {
            isLocked = 1U;
        }

        if ((0U == isLocked) || (0xFFU == isLocked))
        {
            errStatus = MCU_E_PLL_NOT_LOCKED;
        }
        else
        {
            clkPtr->parent = clkPtr->parents[clkPtr->mux];

            if (NULL_PTR != clkPtr->parent)
            {
                errStatus = Mcu_Ip_CkgenIpSetRate(base, clkPtr->id, clkPtr->mux,
                                                  clkPtr->parent->rate, clkPtr->rate);
            } /* else not needed */
        }
    }

    return errStatus;
}
#ifdef CONFIG_CLK_MONITOR
/*PRQA S 3673 1*/
static Mcu_ClkRateType Mcu_Ip_CkgenDrvIpMonGetRate(Mcu_ClkNodeType *clkPtr)
{
    Mcu_ClkRateType rate = UINT32_MAX;

    if (NULL_PTR != clkPtr)
    {
        rate = Mcu_Ip_CkgenIpMonGetRate(clkPtr->core->base, clkPtr->id, clkPtr->rate);
    } /* else not needed */

    return rate;
}
#else
/*PRQA S 3673 2*/
/** Traceability       : SW_SM006*/
static Mcu_ClkRateType Mcu_Ip_CkgenDrvIpGetRate(Mcu_ClkNodeType *clkPtr)
{
    Mcu_ClkRateType rate = UINT32_MAX;

    if (NULL_PTR != clkPtr)
    {
        rate = Mcu_Ip_CkgenIpGetRate(clkPtr->core->base, clkPtr->id, clkPtr->parent->rate);
    } /* else not needed */

    return rate;
}
#endif  /** #ifdef CONFIG_CLK_MONITOR*/

/** Traceability       : SW_SM006*/
static Std_ReturnType Mcu_Ip_CkgenDrvIpSetRate(Mcu_ClkNodeType *clkPtr, Mcu_ClkRateType rate)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;

    if (NULL_PTR != clkPtr)
    {
        clkPtr->parent = clkPtr->parents[clkPtr->mux];

        if (NULL_PTR != clkPtr->parent)
        {
            errStatus = Mcu_Ip_CkgenIpSetRate(clkPtr->core->base, clkPtr->id, clkPtr->mux,
                                              clkPtr->parent->rate, rate);
        } /* else not needed */
    } /* else not needed */

    return errStatus;
}

/** Traceability       : SW_SM006*/
static uint8 Mcu_Ip_CkgenDrvIpSelectParent(Mcu_ClkNodeType *clkPtr, Mcu_ClkRateType rate,
        uint32 *bestDiv)
{
    Mcu_ClkNodeType const *parentPtr;
    Mcu_ClkRateType calcRate;
    Mcu_ClkRateType bestRate = 0;
    uint32 divNum;
    uint8 bestIndex = MCU_CLK_PARENT_NUM;
    uint8 i;

    if ((NULL_PTR != clkPtr) && (NULL_PTR != bestDiv))
    {
        for (i = 0U; i < clkPtr->parentsNum; i++)
        {
            parentPtr = clkPtr->parents[i];

            if (NULL_PTR == parentPtr)
            {
                continue;
            } /* else not needed */

            if (parentPtr->rate < rate)
            {
                continue;
            } /* else not needed */

            divNum = Mcu_Ip_CkgenGetBestDiv(parentPtr->rate, rate);

            if ((UINT32_MAX == divNum) || ((divNum - 1U) > CKGEN_IP_CTL_DIV_NUM_MASK))
            {
                continue;
            } /* else not needed */

            calcRate = parentPtr->rate / divNum;

            if (TRUE == Mcu_Ip_CkgenDrvIsBetterRate(rate, calcRate, bestRate))
            {
                bestRate = calcRate;
                bestIndex = i;
                *bestDiv = divNum;
            } /* else not needed */

            /* if choose xtal24m best, no need check pll */
            if ((rate == bestRate) && (1U == i))
            {
                break;
            } /* else not needed */
        }

        if (bestIndex < MCU_CLK_PARENT_NUM)
        {
            clkPtr->mux = bestIndex;
            clkPtr->parent = clkPtr->parents[bestIndex];
        } /* else not needed */
    }/* else not needed */

    return bestIndex;
}

/** Traceability       : SW_SM006 SW_MCU_SM011 SW_MCU_SM012*/
static Std_ReturnType Mcu_Ip_CkgenDrvCorePrepare(Mcu_ClkNodeType *clkPtr)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;
    uint32 base;
    uint8 isLocked;

    if ((NULL_PTR != clkPtr) && (NULL_PTR != clkPtr->core))
    {
        base = clkPtr->core->base;

        /* if pll not ready, means this is the first config after reset,
        * don't change mux when pll is not ready.
        * all pll is on before config, the last pll ready means all pll ready*/
        if (5U == clkPtr->parentsNum)
        {
            isLocked = Mcu_Ip_ClkIsLocked(clkPtr->parents[4]);
        }
        else
        {
            isLocked = 1U;
        }

        if ((0U == isLocked) || (0xFFU == isLocked))
        {
            errStatus = MCU_E_PLL_NOT_LOCKED;
        }
        else
        {
            clkPtr->parent = clkPtr->parents[clkPtr->mux];

            if (NULL_PTR != clkPtr->parent)
            {
                errStatus = Mcu_Ip_CkgenCoreSetRate(base, clkPtr, clkPtr->rate);

            } /* else not needed */
        }
    }/* else not needed */

    return errStatus;
}
#ifdef CONFIG_CLK_MONITOR
/*PRQA S 3673 1*/
static Mcu_ClkRateType Mcu_Ip_CkgenDrvCoreMonGetRate(Mcu_ClkNodeType *clkPtr)
{
    Mcu_ClkRateType rate = UINT32_MAX;

    if (NULL_PTR != clkPtr)
    {
        rate = Mcu_Ip_CkgenCoreMonGetRate(clkPtr->core->base, clkPtr->id);
    } /* else not needed */

    return rate;
}
#else
/*PRQA S 3673 2*/
/** Traceability       : SW_SM006*/
static Mcu_ClkRateType Mcu_Ip_CkgenDrvCoreGetRate(Mcu_ClkNodeType *clkPtr)
{
    Mcu_ClkRateType rate = UINT32_MAX;

    if (NULL_PTR != clkPtr)
    {
        rate = Mcu_Ip_CkgenCoreGetRate(clkPtr->core->base, clkPtr->id, clkPtr->parent->rate);
    } /* else not needed */

    return rate;
}
#endif /** #ifdef CONFIG_CLK_MONITOR*/

/** Traceability       : SW_SM006*/
static Std_ReturnType Mcu_Ip_CkgenDrvCoreSetRate(Mcu_ClkNodeType *clkPtr, Mcu_ClkRateType rate)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;

    if (NULL_PTR != clkPtr)
    {
        errStatus = Mcu_Ip_CkgenCoreSetRate(clkPtr->core->base, clkPtr, rate);
    } /* else not needed */

    return errStatus;
}

/** Traceability       : SW_SM006*/
static uint8 Mcu_Ip_CkgenDrvCoreSelectParent(Mcu_ClkNodeType *clkPtr, Mcu_ClkRateType rate,
        uint32 *bestDiv)
{
    Mcu_ClkNodeType const *parentPtr;
    Mcu_ClkRateType calcRate;
    Mcu_ClkRateType bestRate = 0U;
    uint32 divNum;
    uint8 bestIndex = MCU_CLK_PARENT_NUM;
    uint8 i;

    if ((NULL_PTR != clkPtr) && (NULL_PTR != bestDiv))
    {
        for (i = 0U; i < clkPtr->parentsNum; i++)
        {
            parentPtr = clkPtr->parents[i];

            if (NULL_PTR == parentPtr)
            {
                continue;
            } /* else not needed */

            if (parentPtr->rate < rate)
            {
                continue;
            } /* else not needed */

            /* ckin4 no pre_div */
            if (4U == i )
            {
                divNum = 1U;
            }
            else
            {
                divNum = Mcu_Ip_CkgenGetBestDiv(parentPtr->rate, rate);
            }

            if ((UINT32_MAX == divNum) || ((divNum - 1U) > CKGEN_CORE_CTL_DIV_NUM_MASK))
            {
                continue;
            } /* else not needed */

            calcRate = parentPtr->rate / divNum;

            if (TRUE == Mcu_Ip_CkgenDrvIsBetterRate(rate, calcRate, bestRate))
            {
                bestRate = calcRate;
                bestIndex = i;
                *bestDiv = divNum;
            } /* else not needed */

            /* if choose xtal24m best, no need check pll */
            if ((rate == bestRate) && (1U == i))
            {
                break;
            } /* else not needed */
        }

        if (bestIndex != MCU_CLK_PARENT_NUM)
        {
            clkPtr->mux = bestIndex;
            clkPtr->parent = clkPtr->parents[bestIndex];
        } /* else not needed */
    }/* else not needed */

    return bestIndex;
}

/** Traceability       : SW_SM006 SW_MCU_SM011 SW_MCU_SM012*/
static Std_ReturnType Mcu_Ip_CkgenDrvBusPrepare(Mcu_ClkNodeType *clkPtr)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;
    uint32 base;
    uint8 isLocked;

    if ((NULL_PTR != clkPtr) && (NULL_PTR != clkPtr->core))
    {
        base = clkPtr->core->base;

        /* if pll not ready, means this is the first config after reset,
        * don't change mux when pll is not ready. */
        if (5U == clkPtr->parentsNum)
        {
            isLocked = Mcu_Ip_ClkIsLocked(clkPtr->parents[4]);
        }
        else
        {
            isLocked = 1U;
        }

        if ((0U == isLocked) || (0xFFU == isLocked))
        {
            errStatus = MCU_E_PLL_NOT_LOCKED;
        }
        else
        {
            clkPtr->parent = clkPtr->parents[clkPtr->mux];

            if (NULL_PTR != clkPtr->parent)
            {
                errStatus = Mcu_Ip_CkgenBusSetRate(base, clkPtr->id, clkPtr->mux,
                                                   clkPtr->parent->rate, clkPtr->rate);
            } /* else not needed */
        }
    }/* else not needed */

    return errStatus;
}
#ifdef CONFIG_CLK_MONITOR
/*PRQA S 3673 1*/
static Mcu_ClkRateType Mcu_Ip_CkgenDrvBusMonGetRate(Mcu_ClkNodeType *clkPtr)
{
    Mcu_ClkRateType rate = UINT32_MAX;

    if ((NULL_PTR != clkPtr) && (CKGEN_BUS_ID_TYPE(clkPtr->id) <= CKGEN_BUS_ID_TYPE_DIV_Q))
    {
        rate = Mcu_Ip_CkgenBusMonGetRate(clkPtr->core->base, clkPtr->id);
    } /* else not needed */

    return rate;
}
#else
/*PRQA S 3673 2*/
/** Traceability       : SW_SM006*/
static Mcu_ClkRateType Mcu_Ip_CkgenDrvBusGetRate(Mcu_ClkNodeType *clkPtr)
{
    Mcu_ClkRateType rate = UINT32_MAX;

    if (NULL_PTR != clkPtr)
    {
        rate = Mcu_Ip_CkgenBusGetRate(clkPtr->core->base, clkPtr->id, clkPtr->parent->rate);
    } /* else not needed */

    return rate;
}
#endif /** #ifdef CONFIG_CLK_MONITOR*/

/** Traceability       : SW_SM006*/
static Std_ReturnType Mcu_Ip_CkgenDrvBusSetRate(Mcu_ClkNodeType *clkPtr, Mcu_ClkRateType rate)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;

    if (NULL_PTR != clkPtr)
    {
        clkPtr->parent = clkPtr->parents[clkPtr->mux];

        if (NULL_PTR != clkPtr->parent)
        {
            errStatus = Mcu_Ip_CkgenBusSetRate(clkPtr->core->base, clkPtr->id, clkPtr->mux,
                                               clkPtr->parent->rate, rate);
        } /* else not needed */
    } /* else not needed */

    return errStatus;
}

/** Traceability       : SW_SM006*/
static uint8 Mcu_Ip_CkgenDrvBusSelectParent(Mcu_ClkNodeType *clkPtr, Mcu_ClkRateType rate,
        uint32 *bestDiv)
{
    Mcu_ClkNodeType const *parentPtr;
    Mcu_ClkRateType calcRate;
    Mcu_ClkRateType bestRate = 0U;
    uint32 divNum;
    uint8 bestIndex = MCU_CLK_PARENT_NUM;
    uint8 i;

    if ((NULL_PTR != clkPtr) && (NULL_PTR != bestDiv))
    {
        for (i = 0U; i < clkPtr->parentsNum; i++)
        {
            parentPtr = clkPtr->parents[i];

            if (NULL_PTR == parentPtr)
            {
                continue;
            } /* else not needed */

            if (parentPtr->rate < rate)
            {
                continue;
            } /* else not needed */

            /* ckin4 no pre_div */
            if (4U == i )
            {
                divNum = 1U;
            }
            else
            {
                divNum = Mcu_Ip_CkgenGetBestDiv(parentPtr->rate, rate);
            }

            if ((UINT32_MAX == divNum) || ((divNum - 1U) > CKGEN_BUS_SYNC_CTL_DIV_MASK))
            {
                continue;
            } /* else not needed */

            calcRate = parentPtr->rate / divNum;

            if (TRUE == Mcu_Ip_CkgenDrvIsBetterRate(rate, calcRate, bestRate))
            {
                bestRate = calcRate;
                bestIndex = i;
                *bestDiv = divNum;
            } /* else not needed */

            /* if choose xtal24m best, no need check pll */
            if ((rate == bestRate) && (1U == i))
            {
                break;
            } /* else not needed */
        }

        if (bestIndex < MCU_CLK_PARENT_NUM)
        {
            clkPtr->mux = bestIndex;
            clkPtr->parent = clkPtr->parents[bestIndex];
        } /* else not needed */
    }/* else not needed */

    return bestIndex;
}

/** Traceability       : SW_SM006*/
static Std_ReturnType Mcu_Ip_CkgenDrvLowpowerCgset(const Mcu_ClkNodeType *clkPtr, uint8 lpMode,
        boolean val)
{
    uint32 base;
    uint32 id;
    uint32 cgType;
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;

    if (NULL_PTR != clkPtr)
    {
        base = clkPtr->core->base;
        id = clkPtr->id;
        cgType = CKGEN_CG_ID_TYPE(id);

        if ((CKGEN_CG_ID_TYPE_PCG_TYPE == cgType) || (CKGEN_CG_ID_TYPE_BCG_TYPE == cgType)
                || (CKGEN_CG_ID_TYPE_CCG_TYPE == cgType))
        {
            errStatus = Mcu_Ip_CkgenXcgSetGatingByMode(base, id, lpMode, val);
        }
        else
        {
            errStatus = MCU_E_PARAM_CONFIG;
        }
    }/* else not needed */

    return errStatus;
}

/** Traceability       : SW_SM006*/
static Std_ReturnType Mcu_Ip_CkgenDrvGatingEnable(const Mcu_ClkNodeType *clkPtr)
{
    uint32 base;
    uint32 id;
    uint32 cgType;
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;

    if (NULL_PTR != clkPtr)
    {
        base = clkPtr->core->base;
        id = clkPtr->id;
        cgType = CKGEN_CG_ID_TYPE(id);

        if ((CKGEN_CG_ID_TYPE_PCG_TYPE == cgType) || (CKGEN_CG_ID_TYPE_BCG_TYPE == cgType)
                || (CKGEN_CG_ID_TYPE_CCG_TYPE == cgType))
        {
            errStatus = Mcu_Ip_CkgenXcgSetGatingByMode(base, id, CKGEN_RUN_MODE, 1U);
        }
        else
        {
            errStatus = MCU_E_PARAM_CONFIG;
        }
    }/* else not needed */

    return errStatus;
}
/** Traceability       : SW_SM006*/
static Std_ReturnType Mcu_Ip_CkgenDrvGatingDisable(const Mcu_ClkNodeType *clkPtr)
{
    uint32 base;
    uint32 id;
    uint32 cgType;
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;

    if (NULL_PTR != clkPtr)
    {
        base = clkPtr->core->base;
        id = clkPtr->id;
        cgType = CKGEN_CG_ID_TYPE(id);

        if ((CKGEN_CG_ID_TYPE_PCG_TYPE == cgType) || (CKGEN_CG_ID_TYPE_BCG_TYPE == cgType)
                || (CKGEN_CG_ID_TYPE_CCG_TYPE == cgType))
        {
            errStatus = Mcu_Ip_CkgenXcgSetGatingByMode(base, id, CKGEN_RUN_MODE, 0U);
        }
        else
        {
            errStatus = MCU_E_PARAM_CONFIG;
        }
    }/* else not needed */

    return errStatus;
}

#ifdef CONFIG_CLK_MONITOR
static uint8 Mcu_Ip_CkgenDrvMonXcgIsGated(uint32 base, uint32 id)
{
    uint8 state = 0xFFu;
    Std_ReturnType errStatus;

    Mcu_Ip_CkgenXcgAmonEnable(base, id, TRUE);

    /*after cg_amon_en, need wait 2 cycle(6M for default) to get cg gate status*/
    errStatus = Mcu_udelay(1);

    if (E_OK == errStatus)
    {
        state = Mcu_Ip_CkgenXcgGetAmonState(base, id);

        if (1U == state)
        {
            state = 0U;
        }
        else
        {
            state = 1U;
        }
    } /*else not needed*/

    Mcu_Ip_CkgenXcgAmonEnable(base, id, FALSE);

    return state;
}

static uint8 Mcu_Ip_CkgenDrvMonGatingIsGated(const Mcu_ClkNodeType *clkPtr)
{
    uint32 base;
    uint32 id;
    uint32 cgType;
    uint8 gatedStatus = 0xFFu;

    if (NULL_PTR != clkPtr)
    {
        base = clkPtr->core->base;
        id = clkPtr->id;
        cgType = CKGEN_CG_ID_TYPE(id);

        if (cgType < CKGEN_CG_ID_TYPE_PLL_TYPE)
        {
            gatedStatus = Mcu_Ip_CkgenDrvMonXcgIsGated(base, id);
        } /* else not needed */
    } /* else not needed */

    return gatedStatus;
}
#else

/** Traceability       : SW_SM006*/
static uint8 Mcu_Ip_CkgenDrvGatingIsGated(const Mcu_ClkNodeType *clkPtr)
{
    uint32 base;
    uint32 id;
    uint32 cgType;
    uint8 gatedStatus = 0xFFu;

    if (NULL_PTR != clkPtr)
    {
        base = clkPtr->core->base;
        id = clkPtr->id;
        cgType = CKGEN_CG_ID_TYPE(id);

        if (cgType < CKGEN_CG_ID_TYPE_PLL_TYPE)
        {
            gatedStatus = Mcu_Ip_CkgenXcgIsGated(base, id);
        } /* else not needed */
    } /* else not needed */

    return gatedStatus;
}
#endif /** #ifdef CONFIG_CLK_MONITOR*/

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"
/********************************************************************************************************
 *                                  Global Types definition                                             *
 *******************************************************************************************************/
/** Traceability       : SW_SM006*/
const struct Mcu_PreClkOpsType Mcu_ClkIpOps =
{
    .prepare = Mcu_Ip_CkgenDrvIpPrepare,
#ifdef CONFIG_CLK_MONITOR
    .getRate = Mcu_Ip_CkgenDrvIpMonGetRate,
#else
    .getRate = Mcu_Ip_CkgenDrvIpGetRate,
#endif /** #ifdef CONFIG_CLK_MONITOR*/
    .setRate = Mcu_Ip_CkgenDrvIpSetRate,
    .selectParent = Mcu_Ip_CkgenDrvIpSelectParent,
};

/** Traceability       : SW_SM006*/
const struct Mcu_PreClkOpsType Mcu_ClkBusOps =
{
    .prepare = Mcu_Ip_CkgenDrvBusPrepare,
#ifdef CONFIG_CLK_MONITOR
    .getRate = Mcu_Ip_CkgenDrvBusMonGetRate,
#else
    .getRate = Mcu_Ip_CkgenDrvBusGetRate,
#endif /** #ifdef CONFIG_CLK_MONITOR*/
    .setRate = Mcu_Ip_CkgenDrvBusSetRate,
    .selectParent = Mcu_Ip_CkgenDrvBusSelectParent,
};

/** Traceability       : SW_SM006*/
const struct Mcu_PreClkOpsType Mcu_ClkCoreOps =
{
    .prepare = Mcu_Ip_CkgenDrvCorePrepare,
#ifdef CONFIG_CLK_MONITOR
    .getRate = Mcu_Ip_CkgenDrvCoreMonGetRate,
#else
    .getRate = Mcu_Ip_CkgenDrvCoreGetRate,
#endif /** #ifdef CONFIG_CLK_MONITOR*/
    .setRate = Mcu_Ip_CkgenDrvCoreSetRate,
    .selectParent = Mcu_Ip_CkgenDrvCoreSelectParent,
};

/** Traceability       : SW_SM006*/
/*PRQA S 1531 1*/
const struct Mcu_PreClkOpsType Mcu_ClkGatingOps =
{
    .enable = Mcu_Ip_CkgenDrvGatingEnable,
    .disable = Mcu_Ip_CkgenDrvGatingDisable,
#ifdef CONFIG_CLK_MONITOR
    .isGated = Mcu_Ip_CkgenDrvMonGatingIsGated,
#else
    .isGated = Mcu_Ip_CkgenDrvGatingIsGated,
#endif /** #ifdef CONFIG_CLK_MONITOR*/
    .lowpowerCgset = Mcu_Ip_CkgenDrvLowpowerCgset,
};

#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
#ifdef CONFIG_CLK_MONITOR
/*PRQA S 3673 1*/
Std_ReturnType Mcu_Ip_CkgenClockToPad(Mcu_ClkNodeType *ckgenPtr, uint8 divNum)
{
    Std_ReturnType errStatus = E_OK;

    if ((NULL_PTR != ckgenPtr) && (NULL_PTR != ckgenPtr->core) && (NULL_PTR != ckgenPtr->core->ops)
            && (divNum >= 1U) && (divNum <= 15U))
    {
        if (&Mcu_ClkIpOps == ckgenPtr->core->ops)
        {
            Mcu_Ip_CkgenDbgMonIpSelect(ckgenPtr->core->base, ckgenPtr->id, divNum);
        }
        else if (&Mcu_ClkCoreOps == ckgenPtr->core->ops)
        {
            Mcu_Ip_CkgenDbgMonCoreSelect(ckgenPtr->core->base, ckgenPtr->id, divNum);
        }
        else if (&Mcu_ClkBusOps == ckgenPtr->core->ops)
        {
            Mcu_Ip_CkgenDbgMonBusSelect(ckgenPtr->core->base, ckgenPtr->id, divNum);
        }
        else
        {
            errStatus = MCU_E_PARAM_CONFIG;
        }
    }
    else
    {
        errStatus = MCU_E_PARAM_POINTER;
    }

    return errStatus;
}
#endif
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
/* End of file */
