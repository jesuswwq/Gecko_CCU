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

#include "Compiler.h"

#if defined(_IAR_C_)
        SECTION .text:CODE(2)
        ARM
#else
        .section ".text"
        .arm
#endif

    ASM_PUBLIC read_pmccntr
ASM_FUNCTION(read_pmccntr)   /* counter frequency register */
    mrc p15, 0, r0, c9, c13, 0
    isb
    bx lr

    ASM_PUBLIC write_pmcr
ASM_FUNCTION(write_pmcr)  /* counter frequency register */
    mcr p15, 0, r0, c9, c12, 0
    bx lr

    ASM_PUBLIC write_pmcntenset
ASM_FUNCTION(write_pmcntenset)  /* virtual timer value register */
    mcr p15, 0, r0, c9, c12, 1
    bx lr

    ASM_PUBLIC read_pmcnten
ASM_FUNCTION(read_pmcnten)  /* virtual timer value register */
    mrc p15, 0, r0, c9, c12, 1
    bx lr

#if defined(_IAR_C_)
        END
#endif

