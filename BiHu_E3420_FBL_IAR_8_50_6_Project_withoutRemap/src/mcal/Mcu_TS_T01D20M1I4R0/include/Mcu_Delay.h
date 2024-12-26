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

#ifndef MCU_DELAY_H
#define MCU_DELAY_H

#include <Std_Types.h>

extern uint32 soc_get_core_freq(void);

#define Mcu_Frequency          (soc_get_core_freq())

#define PMU_US_TO_TICK(us)      ((uint32)(((us) * (Mcu_Frequency/4000000))/16))

uint32 read_pmccntr(void);
void Mcu_PmuCounterInit(void);
boolean Mcu_Cnt_IsEnabled(void);
void Mcu_udelay(uint32 us);
uint32 Mcu_UsToTicks(uint32 us);
uint32 Mcu_TicksToUs(uint32 ticks);

#endif  /*MCU_DELAY_H*/
