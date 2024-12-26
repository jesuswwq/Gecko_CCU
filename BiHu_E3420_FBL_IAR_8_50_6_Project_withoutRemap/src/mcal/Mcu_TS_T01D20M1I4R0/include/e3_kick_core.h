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

#ifndef __E3_KICK_CORE_H_
#define __E3_KICK_CORE_H_

#include "Platform_Types.h"

/* NOTE: This enum shall be only used for core kicking scenario */
typedef enum {
    KICK_CR5_SF = 0,
    KICK_CR5_SP0,
    KICK_CR5_SP1,
    KICK_CR5_SX0,
    KICK_CR5_SX1,
    KICK_CR5_SX,
    KICK_CR5_SP,
    KICK_CORE_MAX,
} kick_core_e_t;

#define STICKY_REG_OFF   0x4u

void soc_kick_core(kick_core_e_t core, uint32 entry);

#endif
