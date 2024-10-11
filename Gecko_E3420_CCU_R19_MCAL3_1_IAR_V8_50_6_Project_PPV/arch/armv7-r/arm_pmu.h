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

#ifndef ARM_PMU_H
#define ARM_PMU_H

#include <Std_Types.h>
#include <Mcu_Delay.h>

/* for event description, please refer to arm cortex-r5 manual. or pmu_events.md*/

typedef enum {
    PMU_CYCLE_COUNTER = 0x80000000UL,
    PMU_EVENT_COUNTER0 = 0x1UL,
    PMU_EVENT_COUNTER1 = 0x2UL,
    PMU_EVENT_COUNTER2 = 0x4UL,
} pmu_counter_type;

/**
 * @brief init the counter, cycle counter + 1 every 64 cycle.
 *      we suppose this is enable in Mcu_PmuCounterInit which does for Mcu_udelay;
 */
static inline void arm_pmu_init(void)
{
    uint32 usr_en = 1;

    Mcu_PmuCounterInit();

    /* also enable user mode to access these counter register */
    ASM volatile("MCR p15, 0, %0, c9, c14, 0" :: "r" (usr_en));
}

/**
 * @brief reset all event counter
 */
static inline void arm_pmu_all_event_cnt_reset(void)
{
    uint32 reg = 0;
    ASM volatile("MRC p15, 0, %0, c9, c12, 0" : "=r" (reg));
    reg |= 0x2;
    ASM volatile("MCR p15, 0, %0, c9, c12, 0" :: "r" (reg));
}
/**
 * @brief reset cycle counter
 *        this function can affect Mcu_udelay, because it use PMU_CYCLE_COUNTER;
 */
static inline void arm_pmu_cycle_cnt_reset(void)
{
    uint32 reg = 0x0;
    ASM volatile("MRC p15, 0, %0, c9, c12, 0" : "=r" (reg));
    reg |= 0x4;
    ASM volatile("MCR p15, 0, %0, c9, c12, 0" :: "r" (reg));
}

/**
 * @brief enable pmu counter
 * @param[in] counter_mask pmu_counter_type, the pmu_counter_type value can logic 'or'.
 */
static inline void arm_pmu_cnt_enable_set(pmu_counter_type counter_mask)
{
    ASM volatile("MCR p15, 0, %0, c9, c12, 1" :: "r" (counter_mask));
}

/**
 * @brief disable pmu counter
 *        this function can affect Mcu_udelay, because it use PMU_CYCLE_COUNTER;
 * @param[in] counter_mask pmu_counter_type, the pmu_counter_type value can logic 'or'.
 */
static inline void arm_pmu_cnt_enable_clr(pmu_counter_type counter_mask)
{
    ASM volatile("MCR p15, 0, %0, c9, c12, 2" :: "r" (counter_mask));
}

/**
 * @brief incrase pmu counter
 * @param[in] counter_mask pmu_counter_type, the pmu_counter_type value can logic 'or'. PMU_CYCLE_COUNTER not support;.
 */
static inline void arm_pmu_cnt_soft_inc(pmu_counter_type counter_mask)
{
    ASM volatile("MCR p15, 0, %0, c9, c12, 4" :: "r" (counter_mask));
}

/**
 * @brief select a pmu counter from counter 0/1/2
 * @param[in] counter ,0/1/2 as counter 0/1/2.
 */
static inline void arm_pmu_event_cnt_select(pmu_counter_type counter)
{
    uint32 counter_num;
    switch (counter)
    {
    case PMU_EVENT_COUNTER0:
        counter_num = 0;
        break;
    case PMU_EVENT_COUNTER1:
        counter_num = 1;
        break;
    case PMU_EVENT_COUNTER2:
        counter_num = 2;
        break;
    default:
        counter_num = 0;
        break;
    }
    ASM volatile("MCR p15, 0, %0, c9, c12, 5" :: "r" (counter_num));
}

static inline uint32 arm_pmu_event_cnt_read(void)
{
    uint32 cnt;
    ASM volatile("MRC p15, 0, %0, c9, c13, 2" : "=r" (cnt));
    return cnt;
}

static inline void   arm_pmu_event_cnt_write(uint32 value)
{
    ASM volatile("MCR p15, 0, %0, c9, c13, 2" :: "r" (value));
}

static inline void   arm_pmu_event_type_select(uint32 event)
{
    ASM volatile("MCR p15, 0, %0, c9, c13, 1" :: "r" (event));
}


/* wrapper function */
static inline void arm_pmu_comb_start_event_count(pmu_counter_type counter, uint32 event)
{
    arm_pmu_cnt_enable_set(counter);
    arm_pmu_event_cnt_select(counter);
    arm_pmu_event_cnt_write(0);
    arm_pmu_event_type_select(event);
}

static inline uint32 arm_pmu_comb_read_event_counter(pmu_counter_type counter)
{
    arm_pmu_event_cnt_select(counter);
    return arm_pmu_event_cnt_read();
}

static inline uint32 arm_pmu_comb_read_cycle_counter(void)
{
    return read_pmccntr();
}

#endif /*ARM_PMU_H*/
