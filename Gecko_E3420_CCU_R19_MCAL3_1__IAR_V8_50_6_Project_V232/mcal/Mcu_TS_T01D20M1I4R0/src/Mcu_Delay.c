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
 * \file     Mcu_Delay.c                                                                                *
 * \brief    AUTOSAR 4.3.1 MCAL Mcu Driver                                                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/02     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#include "Mcu_GeneralTypes.h"
#include "Mcu_Delay.h"

/********************************************************************************************************
 *                                 Private Macro definition                                             *
 *******************************************************************************************************/
#define PMU_EN_CYCLE  0x80000000U
/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

extern void write_pmcr(uint32 x);
extern void write_pmuserenr(uint32 x);
extern void write_pmcntenset(uint32 x);
extern uint32 read_pmcnten(void);
extern uint32 read_pmcr(void);

/**
 * \brief enable pmu counter
 *        this function can only called after Mcu_InitClock();
 *
 */
void Mcu_PmuCounterInit(void)
{
    /* Turn on cycle counter*/
    write_pmcntenset(PMU_EN_CYCLE);
    /* Turn on Performance Monitor, set cycle counter to 'increase 1 tick every 64 cpu cycle' */
    write_pmcr(0x9);
    /* pmu register can be accessed at user mode when the pmuserenr.en enabled */
    write_pmuserenr(0x1);
}

static boolean Mcu_Cnt_IsEnabled(void)
{
    boolean ret;

    uint32 pmcn = read_pmcnten();

    if (PMU_EN_CYCLE == (pmcn & PMU_EN_CYCLE))
    {
        ret = TRUE;
    }
    else
    {
        ret = FALSE;
    }

    return ret;
}

uint32 Mcu_UsToTicks(uint32 us)
{
    return PMU_US_TO_TICK(us);
}

uint32 Mcu_TicksToUs(uint32 ticks)
{
    return (uint32)(((ticks) * 16U) / (Mcu_Frequency / 4000000U));
}

/**
 * \brief udelay
 * \details udelay based on performance monitor unit,
 * \param[in] us delay time in us. max time is 21 s.
 */
/** Traceability       : SWSR_MCU_050 SW_SM005 SW_SM006 SW_SM001*/
Std_ReturnType Mcu_udelay(uint32 us)
{
    uint32 tickTo, startTick, currentTick;
    uint32 tmt = 0U;
    Std_ReturnType errStatus = E_OK;

    if ((0U == Mcu_Cnt_IsEnabled()) || (0U == us) || (us > 21000000UL))
    {
        errStatus = MCU_E_PARAM_CONFIG;
    }
    else
    {
        startTick = read_pmccntr();

        /* make sure cycled information: 100 loops takes ~5us */
        do
        {
            tmt++;
            currentTick = read_pmccntr();
        } while ((startTick == currentTick) && (tmt < 100U));

        if (tmt >= 100U)
        {
            errStatus = MCU_E_TIMEOUT;
        }
        else
        {
            /* timeout check is not a must here, just in case the pmccntr abnormal */
            tickTo = startTick + PMU_US_TO_TICK(us);

            if (tickTo > startTick)
            {
                /* tickTo not overflowed */
                do
                {
                    currentTick = read_pmccntr();
                }
                while ((currentTick < tickTo)
                        && (currentTick > startTick));
            }
            else
            {
                /* currentTick overflowed */
                do
                {
                    currentTick = read_pmccntr();
                }
                while ((currentTick > startTick) || (currentTick < tickTo));
            }
        }
    }

    return errStatus;
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
/* End of file */
