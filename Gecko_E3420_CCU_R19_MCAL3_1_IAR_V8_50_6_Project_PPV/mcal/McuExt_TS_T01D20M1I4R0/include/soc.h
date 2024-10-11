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

#ifndef SOC_H
#define SOC_H

#include "Std_Types.h"
#include "RegHelper.h"
#include "__regs_base.h"
/** *****************************************************************************************************
 * \brief This function returns the chipversion information.
 *
 * \verbatim
 * Syntax             : static inline uint8 Mcu_GetChipVersion(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : chip version
 *
 * Description        : This function returns the chipversion information.
 *                      0x101a bit7~4 major bit3~0 minor
 * \endverbatim
 * Traceability       : SWSR SWSR_XXX_xxx
 *******************************************************************************************************/
static inline uint8 Mcu_GetChipVersion(void)
{
#ifdef SEMIDRIVE_E3_SERIES
    uint8 version = 0xFFu;
    version = (uint8)(readl(APB_EFUSEC_BASE + 0x1018U) >> 16U);
    return version;
#elif defined(SEMIDRIVE_E3_LITE_SERIES)
#define V_MINOR_MASK 0x000f0000U
#define V_MINOR_POS 16U
#define V_MINOR_L(V)  ((V)-1)
    /*
        e3l .0   0x01 @0x101a
        e3l .1   0x02 @0x101a
    */
    uint8 version = 0xFFu;
    version = (uint8)((readl(APB_EFUSEC_BASE + 0x1018) & V_MINOR_MASK) >> V_MINOR_POS);

    return V_MINOR_L(version);
#else
    return 1U;
#endif /** #ifdef SEMIDRIVE_E3_SERIES*/

}
#endif  /* SOC_H */
