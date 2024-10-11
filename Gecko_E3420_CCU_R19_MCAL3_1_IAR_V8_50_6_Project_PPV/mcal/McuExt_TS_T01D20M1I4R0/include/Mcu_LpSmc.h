
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

#ifndef __MCU_LPSMC_H__
#define __MCU_LPSMC_H__
#ifdef __cplusplus
extern "C" {
#endif

#include "Mcu_Extend.h"
#include "Mcu_Smc.h"
#include "Mcu_Iramc.h"
#include "McuExt_Cfg.h"

typedef enum {
    SOC_CKGEN_24M_OFF,
    SOC_CKGEN_24M_ON,
} soc_ckgen_24m;

/**
 * @brief wakupsrc enable.
 */


typedef struct {
    const soc_ckgen_24m     xtal_24;
    const soc_ckgen_24m     rc_24;
} soc_ckgen_t;


/* gpio interrupt smc mask bit */
typedef struct {
    boolean sfgroup0;
    boolean sfgroup1;
    boolean sfgroup2;
    boolean sfgroup3;
    boolean sfgroup4;
    boolean apgroup0;
    boolean apgroup1;
    boolean apgroup2;
} gpio_group_t;

/* smc wakeup source define */
typedef struct {
    smc_wakeup_src_enable_e     rtcsrc;
    smc_wakeup_src_enable_e     gpiosrc;
    const Mcu_RtcAlarmType           *rtc;
    const gpio_group_t          *gpio;
} soc_wkup_src_t;

/* iram power mode define */
typedef struct {
    iramc_power_mode_e     iram1;
    iramc_power_mode_e     iram2;
    iramc_power_mode_e     iram3;
    iramc_power_mode_e     iram4;
} soc_iramc_pwr_mode_t;

typedef enum {
    MCU_MODE_SLP = 1U,  /**< @brief All powers excepts Sleep been disabled */
    MCU_MODE_HIB = 2U,  /**< @brief All powers excepts Hibernate been disabled */
} Mcu_LpModeType;

/* Hibernate Struct Define */
typedef struct {
    const soc_ckgen_t       *ckgen;
    const soc_wkup_src_t    *wksrc;
    const Mcu_ModuleType    *wkip;
    const soc_iramc_pwr_mode_t *iram;
    const Mcu_PwrSigType     *pmu;
    const smc_ctrl_t        *smc;
} Mcu_HibernateModeConfigType;

/* SleepMode Struct Define */
typedef struct {
    const soc_ckgen_t       *ckgen;
    const soc_wkup_src_t    *wksrc;
    const Mcu_ModuleType    *wkip;
    const smc_ctrl_t        *smc;
    const Mcu_PwrSigType     *pmu;
} Mcu_SleepModeConfigType;
#if ((MCU_HIBERNATE_MODE_API == STD_ON) || (MCU_SLEEP_MODE_API == STD_ON))

Std_ReturnType Mcu_Ip_CkgenPllSetGatingByMode(uint32 base, uint32 id, uint8 lpMode, boolean en);

Std_ReturnType Mcu_Ip_CkgenXtalSetGatingByMode(uint32 base, uint8 lpMode, boolean en);

Std_ReturnType Mcu_CkgenPllDis(uint8 mode, boolean onOff, uint8 ckgenSel, boolean disOrPd);

Std_ReturnType Mcu_CkgenXtalDis(uint8 mode, boolean onOff, uint8 ckgenSel);

Std_ReturnType Mcu_CkgenSfClkDis(uint8 mode, boolean onOff);

#ifndef SEMIDRIVE_E3_LITE_SERIES
Std_ReturnType Mcu_CkgenApClkDis(uint8 mode, boolean onOff);
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/

Std_ReturnType Mcu_Ip_RstgenLldSetMissionResetByMode(uint32 base, uint32 index, uint32 mode,
        uint32 val);

Std_ReturnType Mcu_Ip_RstgenLldSetLatentResetByMode(uint32 base, uint32 index, uint32 mode,
        uint32 val);

Std_ReturnType Mcu_Ip_RstgenLldSetModuleResetByMode(uint32 base, uint32 index, uint32 mode,
        uint32 val);

Std_ReturnType Mcu_Ip_RstgenLldSetCoreResetByMode(uint32 base, uint32 index, uint32 mode,
        uint32 val);

/**
 * \brief Config reset signal assert/deassert in lowpower mode.
 *
 * \param[in] rst_sig Reset signal.
 * \param[in] mode lowpower mode
 * \param[in] val 0:assert, 1:deassert
 *
 * \return 0 if OK, or a negative error code.
 */

Std_ReturnType Mcu_ResetCtlLowpowerSet(const Mcu_ResetSigType *rstSigPtr,
                                       Mcu_ResetLowpowerModeType mode, uint32 val);

uint32 Mcu_RstgenLldGetSsRdy(uint32 base);
/**
 * @brief To config Rstgen Reset or not when enter sleep mode.
 * @param[in]  mode   include hib mode, sleep mode.
 */
void Mcu_RstgenResetAssertConfig(Mcu_ResetLowpowerModeType mode);


/**
 * @brief To config smc wakeup source enable.
 * @param[in]  wkupsrc   include rtc, wakeup0 pin, wakeup1 pin, BC Button and gpio.
 * @param[in]  ip   wakeup module list.
 */
void Mcu_WakeupSourceEnableConfig(const soc_wkup_src_t *wkupsrc, const Mcu_ModuleType *ip);

/**
 * @brief To Mask all smc irq .
 */
void Mcu_SmcAllIrqMaskConfig(void);

/**
 * @brief To config smc wfi .
 * @param[in]  smc   saf domain, ap domain and soc control.
 * @param[in]  lpmode   low power mode.
 */
void Mcu_SoCPowerGateConfig(const smc_ctrl_t *smc, uint8 lpmode);

/**
 * @brief To config smc wfi .
 * @param[in]  smc   saf domain, ap domain and soc control.
 */
void Mcu_SoCEnterLpConfig(const smc_ctrl_t *smc);

/**
 * @brief To act the wfi commond.
 */
void Mcu_ActionToWfi(uint8 mode);

/**
 * @brief To config ckgen clock .
 * @param[in]  pModule  wakup ip.
 * @param[in]  ckgen    24M on off select.
 * @param[in]  ip   wakeup module list.
 */
void Mcu_CkgenClockDisableConfig(uint8 mode, const soc_ckgen_t *ckgen, const Mcu_ModuleType *ip);

/**
 * @brief To config iram power mode .
 * @param[in]  iram    iram id.
 */

/**
 * @brief To get smc debug mux data.
 */
void Mcu_SmcSwmCheckAfterExitWfi(void);

/**
 * @brief smc switch sf/sp/sx clock to 24MHz.
 */
void Mcu_SmcSwitchClockTo24Mhz(void);

/**
 * @brief smc store sf/sp/sx clock.
 */
void Mcu_SmcSwitchClockToNormal(void);
void Mcu_IramPowerConfig(const soc_iramc_pwr_mode_t *iram);

FUNC(void, MCU_CODE) Mcu_SetLpMode(
    VAR(Mcu_LpModeType, AUTOMATIC) McuMode
);

/**
* @brief   Mcu init low power Hibernate routine.
* @details This function does some low power Hibernate confirure jobs, including
*          #1. mask smc irq.
*          #2. ckgen configure.
*          #3. rstgen configure.
*          #4. pwr_on configure.
*          #5. iram configure.
*          #6. wake up sourece configure.
*          #7. saf domain, ap domain and SOC lowpower configure.
* @param[in]   HibernateModeConfigPtr  pointing to configuration data of Hibernate mode.
* @return  None.
*/
FUNC(void, MCU_CODE) Mcu_LowPowerHibernateConfig(
    P2CONST(Mcu_HibernateModeConfigType, AUTOMATIC, MCU_APPL_CONST) HibernateModeConfigPtr
);

/**
* @brief   Mcu init low power Sleep routine.
* @details This function does some low power Sleep confirure jobs, including
*          #1. mask smc irq.
*          #2. ckgen configure.
*          #3. rstgen configure.
*          #4. wake up sourece configure.
*          #5. saf domain, ap domain and SOC lowpower configure.
* @param[in]   SleepModeConfigPtr  pointing to configuration data of Sleep mode.
* @return  None.
*/
FUNC(void, MCU_CODE) Mcu_LowPowerSleepConfig(
    P2CONST(Mcu_SleepModeConfigType, AUTOMATIC, MCU_APPL_CONST) SleepModeConfigPtr
);

/**
* @brief   Mcu init low power routine.
* @details This function does some low power confirure jobs, including
*          #1. Sleep mode configure.
*          #1. Hibernate mode configure.
* @param[in]   RtcModeConfigPtr  pointing to configuration data of Mcu.
* @return  None.
*/
FUNC(void, MCU_CODE) Mcu_LowPowerInit(void);
#endif /* MCU_SLEEP_MODE_API == STD_ON || MCU_HIBERNATE_MODE_API == STD_ON */
#ifdef __cplusplus
}
#endif

#endif  /* __MCU_LPSMC_H__ */
