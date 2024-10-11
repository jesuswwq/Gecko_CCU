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

#ifndef MCU_USER_CALLOUT_H
#define MCU_USER_CALLOUT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#if ((MCU_HIBERNATE_MODE_API == STD_ON) || (MCU_SLEEP_MODE_API == STD_ON))
#include "irq_num.h"
#endif /* MCU_SLEEP_MODE_API == STD_ON || MCU_HIBERNATE_MODE_API == STD_ON */

/**
 * @brief   User application realized in this callout.
 *
 */
FUNC(void, MCU_CODE) Mcu_SuspendUserCallouts
(
    VAR(uint8, AUTOMATIC) McuMode
);

/**
 * @brief   User application realized in this callout.
 *
 */
FUNC(void, MCU_CODE) Mcu_ResumeUserCallouts
(
    VAR(uint8, AUTOMATIC) McuMode
);

#ifdef __cplusplus
}
#endif

#endif
