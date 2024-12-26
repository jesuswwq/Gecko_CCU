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

#ifndef __LNK_SYM_H__
#define __LNK_SYM_H__

#if !defined(ASSEMBLY)
#if defined(__ARMCC_VERSION)
extern unsigned long Load$$data$$Base[];
extern unsigned long Image$$data$$Base[];
extern unsigned long Image$$data$$Limit[];
extern unsigned long Image$$bss$$ZI$$Base[];
extern unsigned long Image$$bss$$ZI$$Limit[];
extern unsigned long Image$$ram_func$$Base[];
extern unsigned long Image$$ram_func$$Limit[];
extern unsigned long Load$$ram_func$$Base[];
extern unsigned long Image$$heap$$ZI$$Base[];
extern unsigned long Image$$stack$$ZI$$Base[];
extern unsigned long Image$$stack$$ZI$$Limit[];
extern unsigned long Image$$TEST_SECTION$$Base[];
extern unsigned long Image$$TEST_SECTION$$Limit[];
extern unsigned long Image$$vector$$Base[];
extern unsigned long Image$$shell_cmd$$Base[];
extern unsigned long Image$$shell_cmd$$Limit[];
#elif defined(_IAR_C_)
extern unsigned long CDATA$$Base[];
extern unsigned long CDATA$$Limit[];
extern unsigned long CDATA_init$$Base[];
extern unsigned long CDATA_init$$Limit[];
extern unsigned long CBSS$$Base[];
extern unsigned long CBSS$$Limit[];
extern unsigned long MCALDATA$$Base[];
extern unsigned long MCALDATA$$Limit[];
extern unsigned long MCALBSS$$Base[];
extern unsigned long MCALBSS$$Limit[];
extern unsigned long TCMBSS$$Base[];
extern unsigned long TCMBSS$$Limit[];
extern unsigned long IRAMBSS$$Base[];
extern unsigned long IRAMBSS$$Limit[];
extern unsigned long TCMDATA$$Base[];
extern unsigned long TCMDATA$$Limit[];
extern unsigned long TCMDATA_init$$Base[];
extern unsigned long IRAMDATA$$Base[];
extern unsigned long IRAMDATA$$Limit[];
extern unsigned long IRAMDATA_init$$Base[];
extern unsigned long TCMFUNC$$Base[];
extern unsigned long TCMFUNC$$Limit[];
extern unsigned long TCMFUNC_init$$Base[];
extern unsigned long IRAMFUNC$$Base[];
extern unsigned long IRAMFUNC$$Limit[];
extern unsigned long IRAMFUNC_init$$Base[];
extern unsigned long MCALDATA_init$$Base[];
extern unsigned long CSTACK$$Base[];
extern unsigned long CSTACK$$Limit[];
extern unsigned long DMABUFFER$$Base[];
extern unsigned long DMABUFFER$$Limit[];
extern unsigned long TEST_SECTION$$Base[];
extern unsigned long TEST_SECTION$$Limit[];
extern unsigned long HEAP$$Base[];
extern unsigned long HEAP$$Limit[];
extern unsigned long shell_cmd$$Base[];
extern unsigned long shell_cmd$$Limit[];
#else
extern unsigned long __load_data_start[];
extern unsigned long __data_start[];
extern unsigned long __data_end[];
extern unsigned long __bss_start[];
extern unsigned long __bss_end[];
extern unsigned long __iram_func_start[];
extern unsigned long __iram_func_end[];
extern unsigned long __iram_func_load_addr[];
extern unsigned long __tcm_func_start[];
extern unsigned long __tcm_func_end[];
extern unsigned long __tcm_func_load_addr[];
extern unsigned long __iram_data_start[];
extern unsigned long __iram_data_end[];
extern unsigned long __iram_data_load_addr[];
extern unsigned long __tcm_data_start[];
extern unsigned long __tcm_data_end[];
extern unsigned long __tcm_data_load_addr[];
extern unsigned long __iram_bss_start[];
extern unsigned long __iram_bss_end[];
extern unsigned long __tcm_bss_start[];
extern unsigned long __tcm_bss_end[];
extern unsigned long __dma_buffer_start[];
extern unsigned long __dma_buffer_end[];
extern unsigned long __heap_start[];
extern unsigned long __heap_end[];
extern unsigned long __stack_start[];
extern unsigned long __stack_end[];
extern unsigned long __start_TEST_SECTION[];
extern unsigned long __stop_TEST_SECTION[];
extern unsigned long __rom_end[];
extern unsigned long __start_shell_cmd[];
extern unsigned long __stop_shell_cmd[];
extern unsigned long  __load_mcaldata_start[];
extern unsigned long  __mcalbss_start[];
extern unsigned long __mcalbss_end[];
extern unsigned long __mcaldata_start[];
extern unsigned long __mcaldata_end[];
#endif
#endif

#if defined(__ARMCC_VERSION)
#define __load_data_start       Load$$data$$Base
#define __data_start            Image$$data$$Base
#define __data_end              Image$$data$$Limit
#define __bss_start             Image$$bss$$ZI$$Base
#define __bss_end               Image$$bss$$ZI$$Limit
#define __ram_func_start        Image$$ram_func$$Base
#define __ram_func_end          Image$$ram_func$$Limit
#define __load_ram_func_start   Load$$ram_func$$Base
#define __stack_start           Image$$stack$$ZI$$Base
#define __stack_end             Image$$stack$$ZI$$Limit
#define __heap_start            Image$$heap$$ZI$$Base
#define __heap_end              __stack_start
#define __start_TEST_SECTION    Image$$TEST_SECTION$$Base
#define __stop_TEST_SECTION     Image$$TEST_SECTION$$Limit
#define __vector_tbl_start        Image$$vector$$Base
#define __start_shell_cmd        Image$$shell_cmd$$Base
#define __stop_shell_cmd        Image$$shell_cmd$$Limit
#elif defined(_IAR_C_)
#define __load_data_start       CDATA_init$$Base
#define __data_start            CDATA$$Base
#define __data_end              CDATA$$Limit
#define __bss_start             CBSS$$Base
#define __bss_end               CBSS$$Limit
#define __load_mcaldata_start   MCALDATA_init$$Base
#define __mcalbss_start         MCALBSS$$Base
#define __mcalbss_end           MCALBSS$$Limit
#define __tcm_bss_start         TCMBSS$$Base
#define __tcm_bss_end           TCMBSS$$Limit
#define __iram_bss_start        IRAMBSS$$Base
#define __iram_bss_end          IRAMBSS$$Limit
#define __mcaldata_start        MCALDATA$$Base
#define __mcaldata_end          MCALDATA$$Limit
#define __tcm_data_start        TCMDATA$$Base
#define __tcm_data_end          TCMDATA$$Limit
#define __tcm_data_load_addr          TCMDATA_init$$Base
#define __iram_data_start       IRAMDATA$$Base
#define __iram_data_end         IRAMDATA$$Limit
#define __iram_data_load_addr         IRAMDATA_init$$Base
#define __tcm_func_start        TCMFUNC$$Base
#define __tcm_func_end          TCMFUNC$$Limit
#define __tcm_func_load_addr    TCMFUNC_init$$Base
#define __iram_func_start       IRAMFUNC$$Base
#define __iram_func_end         IRAMFUNC$$Limit
#define __iram_func_load_addr         IRAMFUNC_init$$Base
#define __stack_start           CSTACK$$Base
#define __stack_end             CSTACK$$Limit
#define __heap_start            HEAP$$Base
#define __heap_end              HEAP$$Limit
#define __dma_buffer_start      DMABUFFER$$Base
#define __dma_buffer_end        DMABUFFER$$Limit
#define __start_TEST_SECTION    TEST_SECTION$$Base
#define __stop_TEST_SECTION     TEST_SECTION$$Limit
#define __start_shell_cmd        shell_cmd$$Base
#define __stop_shell_cmd        shell_cmd$$Limit
#endif

#endif  /* __LNK_SYM_H__ */
