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

#ifndef MEMORY_MAP_H
#define MEMORY_MAP_H
#ifdef __cplusplus
extern "C" {
#endif

#include "__regs_base.h"
/* Version and Check Begin */
/* Version Info Begin */
#define MEMORY_MAP_H_VENDOR_ID    0x8C
#define MEMORY_MAP_H_AR_RELEASE_MAJOR_VERSION    4
#define MEMORY_MAP_H_AR_RELEASE_MINOR_VERSION    3
#define MEMORY_MAP_H_AR_RELEASE_REVISION_VERSION 1
#define MEMORY_MAP_H_SW_MAJOR_VERSION    1
#define MEMORY_MAP_H_SW_MINOR_VERSION    0
#define MEMORY_MAP_H_SW_PATCH_VERSION    0
/* Version Info End */
/* Version and Check End */

#define ATCM_BASE_SF   0x1940000
#define BTCM_BASE_SF   0x1930000


#define ATCM_BASE_SP0   0x1840000
#define BTCM_BASE_SP0   0x1838000


#define ATCM_BASE_SP1   0x18C0000
#define BTCM_BASE_SP1   0x18B8000

#define ATCM_BASE_SX0   0x1A40000
#define BTCM_BASE_SX0   0x1A38000


#define ATCM_BASE_SX1   0x1AC0000
#define BTCM_BASE_SX1   0x1AB8000


#define TCM_BASE    0
#define TCM_SZ      0x20000
#define TCM_END     (TCM_BASE + TCM_SZ - 1)

#define SEC_TCM_SYSTEM_ADDR     0x3B0000
#define SAF_TCM_SYSTEM_ADDR     0x330000

#if defined(CORE_sec)
#define SYS_ICACHE_BASE  R5_SEC_CACHE_BASE
#else
#define SYS_ICACHE_BASE  R5_SAF_CACHE_BASE
#endif
#define SYS_DCACHE_BASE  (SYS_ICACHE_BASE + 0x8000)

#if defined(CORE_safe)
#define OSPI_MEM_BASE       OSPI2_BASE
#else
#define OSPI_MEM_BASE       OSPI1_BASE
#endif
#define OSPI_MEM_SZ         0x4000000
#define OSPI_MEM_END       (OSPI_MEM_BASE + OSPI_MEM_SZ - 1)
#define OSPI_ADDR_WIDTH    26

#define TB_TRIG_CMD_ADDR    0x4CFFC0
#define TB_TRIG_ARG1_ADDR   0x4CFFD0
#define TB_TRIG_ARG2_ADDR   0x4CFFE0

#if !defined(CFG_MULTI_CORE_OS)
#if defined(CORE_sec)
#define IRAM_BASE       IRAM2_BASE
#define SCR_RBASE       APB_SCR_SEC_BASE
#define ROMC_RBASE      APB_ROMC2_BASE
#define RSTGEN_RBASE    APB_RSTGEN_SEC_BASE
#define CORE_RESET_B_INDEX  RSTGEN_SEC_CORE_RST_B_CR5_SEC_INDEX
#define SCR_REMAP_CR5_AR_ADDR_OFF_L32_START_BIT \
            SCR_SEC_REMAP_CR5_SEC_AR_ADDR_OFFSET_19_0_L31_START_BIT
#define SCR_REMAP_CR5_REMAP_OVRD_EN_L31_START_BIT \
            SCR_SEC_REMAP_CR5_SEC_AR_REMAP_OVRD_EN_L31_START_BIT
#else
#define IRAM_BASE       IRAM1_BASE
#define SCR_RBASE       0//APB_SCR_SAF_BASE
#define ROMC_RBASE      0//APB_ROMC1_BASE
#define RSTGEN_RBASE    0//APB_RSTGEN_SAF_BASE
#define CORE_RESET_B_INDEX  RSTGEN_SAF_CORE_RST_B_CR5_SAF_INDEX
#define SCR_REMAP_CR5_AR_ADDR_OFF_L32_START_BIT \
            SCR_SAF_REMAP_CR5_SAF_AR_ADDR_OFFSET_19_0_L31_START_BIT
#define SCR_REMAP_CR5_REMAP_OVRD_EN_L31_START_BIT \
            SCR_SAF_REMAP_CR5_SAF_AR_REMAP_OVRD_EN_L31_START_BIT
#endif  /* defined(CORE_sec) */
#endif  /* !defined(CFG_MULTI_CORE_OS */


#ifdef __cplusplus
}
#endif

#endif /* MEMORY_MAP_H */
