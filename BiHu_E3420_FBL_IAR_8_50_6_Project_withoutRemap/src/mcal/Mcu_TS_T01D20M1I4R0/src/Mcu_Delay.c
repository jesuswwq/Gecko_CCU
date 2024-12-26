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

#include <Mcu_Delay.h>

#define PMU_EN_CYCLE  0x80000000u

extern void write_pmcr(uint32 x);
extern void write_pmcntenset(uint32 x);
extern uint32 read_pmcnten(void);
extern uint32 read_pmcr(void);

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

/**
 * @brief enable pmu counter
 *        this function can only called after Mcu_InitClock();
 *
 */
void Mcu_PmuCounterInit(void)
{
    /* Turn on cycle counter*/
    write_pmcntenset(PMU_EN_CYCLE);
    /* Turn on Performance Monitor, set cycle counter to 'increase 1 tick every 64 cpu cycle' */
    write_pmcr(0x9);
}

boolean Mcu_Cnt_IsEnabled(void)
{
    return  ((read_pmcnten() & PMU_EN_CYCLE) == PMU_EN_CYCLE);
}

uint32 Mcu_UsToTicks(uint32 us)
{
    return PMU_US_TO_TICK(us);
}

uint32 Mcu_TicksToUs(uint32 ticks)
{
    return (uint32)((ticks) * 16 / (Mcu_Frequency / 4000000));
}

/**
 * @brief udelay
 * @details udelay based on performance monitor unit,
 * @param[in] us delay time in us. max time is 340 s.
 */
void Mcu_udelay(uint32 us)
{
    uint32 tick_to, start_tick, current_tick;
    uint32 tmt = 0u;

    if ((0u == Mcu_Cnt_IsEnabled()) || (0u == us)) {
        return;
    }

    if (us > 21000000UL) {
        us = 21000000UL;
    }

    start_tick = read_pmccntr();

    /* make sure cycled information: 100 loops takes ~5us */
    while ((start_tick == read_pmccntr()) && (tmt++ < 100u));

    /* timeout check is not a must here, just in case the pmccntr abnormal */
    if (tmt < 100u) {
        tick_to = start_tick + PMU_US_TO_TICK(us);

        if (tick_to > start_tick) {
            /* tick_to not overflowed */
            do {
                current_tick = read_pmccntr();
            } while ((current_tick < tick_to)
                     && (current_tick > start_tick));
        } else {
            /* current_tick overflowed */
            do {
                current_tick = read_pmccntr();
            } while ((current_tick > start_tick) || (current_tick < tick_to));
        }
    }
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
