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

#ifndef MCU_DCDC_LDO_H
#define MCU_DCDC_LDO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "Platform_Types.h"

void Mcu_DCDC_MODE_SET(void);
int dcdc_set_vout(uint32 mv);

#ifndef SEMIDRIVE_E3_LITE_SERIES
int ldo_set_hp_vout(uint32 mv);
#endif

#ifdef __cplusplus
}
#endif

#endif  /* ifndef _MCU_DCDC_LDO_H_ */
