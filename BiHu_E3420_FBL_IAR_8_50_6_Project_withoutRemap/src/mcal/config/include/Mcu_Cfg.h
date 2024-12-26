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

/**
 * @file  Mcu_Cfg.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Mcu Driver.
 * @date 2023-09-22 17:02:48
*/
#ifndef MCU_CFG_H
#define MCU_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "Mcu_Modules.h"
#include "Mcu_Pmu.h"
#include "Mcu_Rtc.h"

#define MCU_MAX_RAMCFGS  4
#define MCU_MAX_MODECFGS 4
#define MCU_MAX_CLKCFGS  1

typedef struct {
    uint32 Idx;
    uint8 *Base;
    uint32 Size;
    uint8 DefaultValue;
} Mcu_RamConfigType;

typedef struct {
    const Mcu_ModuleType *modules;
    const Mcu_ModuleType *handovers;
} Mcu_HwIpsConfigType;

#define MCU_DEV_ERROR_DETECT (STD_OFF)
#define MCU_VERSION_INFO_API (STD_OFF)
#define MCU_PERFORM_RESET_API (STD_ON)
#define MCU_PERFORM_AP_DOMAIN_RESET_API (STD_ON)
#define MCU_GET_RAM_STATE_API (STD_OFF)

#define MCU_APDOMAIN_POWERDOWN (STD_OFF)
#define MCU_LDO_POWERDOWN (STD_OFF)
#define MCU_DCDC_POWERDOWN (STD_OFF)
#define MCU_SF_Frequency_Halved (STD_OFF)
#define MCU_SP_Frequency_Halved (STD_OFF)
#define MCU_SX_Frequency_Halved (STD_OFF)

#define MCU_PLL_SPREAD STD_OFF

#define McuConf_McuClockSettingConfig_McuClockSettingConfig_0   ((Mcu_ClockType)0U)

#define McuConf_McuModeSettingConf_Run_Mode   ((Mcu_ModeType)0U)
#define McuConf_McuModeSettingConf_Sleep_Mode   ((Mcu_ModeType)1U)
#define McuConf_McuModeSettingConf_Hibernate_Mode   ((Mcu_ModeType)2U)
#define McuConf_McuModeSettingConf_Rtc_Mode   ((Mcu_ModeType)3U)

#define McuConf_McuResetReasonConf_McuResetReasonConf_0   ((uint8)0U)
#define McuConf_McuResetReasonConf_McuResetReasonConf_1   ((uint8)0U)



#define EXPECT_CORE_CLOCK_SF  (600*1000000u)
#define EXPECT_CORE_CLOCK_SP  (600*1000000u)
#define EXPECT_CORE_CLOCK_SX  (600*1000000u)

#define MAX_CORE_NUM  3U

#ifdef __cplusplus
}
#endif

#endif /* !defined(MCU_CFG_H) */
