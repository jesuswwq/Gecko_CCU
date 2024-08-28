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

#ifdef __cplusplus
extern "C" {
#endif

#include "Mcu_UserCallouts.h"

#define MCU_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

#define MCU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

FUNC(void, MCU_CODE) Mcu_SuspendUserCallouts
(
    VAR(uint8, AUTOMATIC) McuMode
)
{
    /* user application here*/

    /* example: if lin ip power down, call lin_deinit function,
       and call lin init function at Mcu_ResumeUserCallouts. */

}

FUNC(void, MCU_CODE) Mcu_ResumeUserCallouts
(
    VAR(uint8, AUTOMATIC) McuMode
)
{
    /* user application here*/

    /* example: if call lin_deinit function at Mcu_SuspendUserCallouts,
       please call lin init function at Mcu_ResumeUserCallouts. */
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif


