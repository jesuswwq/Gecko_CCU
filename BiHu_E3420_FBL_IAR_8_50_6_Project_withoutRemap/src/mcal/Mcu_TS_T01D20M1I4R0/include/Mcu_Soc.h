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

#ifndef MCU_SOC_H
#define MCU_SOC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "Mcu_Modules.h"
#include "Mcu_ScrBits.h"
#include "Memory_Map.h"
#include "Mcu_Pmu.h"
#include "Mcu_Rtc.h"
#include "Mcu_Smc.h"
#include "Mcu_Iramc.h"
#include "reset.h"

/* Version and Check Begin */
/* Version Info Begin */
#define MCU_SOC_H_VENDOR_ID    0x8C
#define MCU_SOC_H_AR_RELEASE_MAJOR_VERSION    4
#define MCU_SOC_H_AR_RELEASE_MINOR_VERSION    3
#define MCU_SOC_H_AR_RELEASE_REVISION_VERSION 1
#define MCU_SOC_H_SW_MAJOR_VERSION    1
#define MCU_SOC_H_SW_MINOR_VERSION    0
#define MCU_SOC_H_SW_PATCH_VERSION    0
/* Version Info End */

#if defined(CFG_MULTI_CORE_OS)
extern uint32 scr_rbase[];
extern uint32 romc_rbase[];
extern uint32 iram_base[];
extern const uint32 rstgen_rbase[];
extern const uint32 cr5_core_rst_idx[];
extern const uint32 cr5_remap_ar_off_start_bit[];
extern const uint32 cr5_remap_ovrd_en[];
#define IRAM_BASE   iram_base[soc_get_cpu_id()]
#define SCR_RBASE   scr_rbase[soc_get_cpu_id()]
#define ROMC_RBASE  romc_rbase[soc_get_cpu_id()]
#define RSTGEN_RBASE rstgen_rbase[soc_get_cpu_id()]
#define CORE_RESET_B_INDEX  cr5_core_rst_idx[soc_get_cpu_id()]
#define SCR_REMAP_CR5_AR_ADDR_OFF_L32_START_BIT \
            cr5_remap_ar_off_start_bit[soc_get_cpu_id()]
#define SCR_REMAP_CR5_REMAP_OVRD_EN_L31_START_BIT \
            cr5_remap_ovrd_en[soc_get_cpu_id()]
#endif /* defined(CFG_MULTI_CORE_OS) */

#define PMU_RBASE       APB_PMU_CORE_BASE
#define RTC1_RBASE      APB_RTC1_BASE

#define ROMC_STICKY_REG_OFF  0x34U

#define FM_ROM_FLAG_ROM_SELFTEST    (0x03U << 0)

#define RG_GPR_REMAP_FLAG           1   /* gpr used to store 'remap' flag */
#define REMAP_DONE                  (0x52454d50u)     /* 'REMP' */

#define RG_GPR_MCAL                 2
#define BM_SAFETY_HANDOVERED        (0x01U << 0u)

#define RG_GPR_TEST_FLAGS           7

#define BP_ROMC_STICKY_REMAP_EN     0u

#if !defined(SOC_RPC_REG_ADDR_MAP)
#define SOC_RPC_REG_ADDR_MAP(a)     ((uint32)(a))
#define SOC_IOMUX_REG_MAP(a)        SOC_RPC_REG_ADDR_MAP(a)
#define SOC_CKGEN_REG_MAP(a)        SOC_RPC_REG_ADDR_MAP(a)
#define SOC_RSTGEN_REG_MAP(a)       SOC_RPC_REG_ADDR_MAP(a)
#define SOC_SCR_REG_MAP(a)          SOC_RPC_REG_ADDR_MAP(a)
#endif

#define BTM_G0_EN_OFFSET    0x04
#define BTM_G1_EN_OFFSET    0x24
#define BTM_INT_STA_OFFSET    0x40
#define BTM_INT_STA_EN_OFFSET    0x44
#define BTM_INT_SIG_EN_OFFSET    0x48

#define ETIMER_DMA_CTRL_OFFSET      0xB8U
#define ETIMER_SW_RST_OFFSET        0xA8U
#define ETIMER_G0_EN_OFFSET         0x10CU
#define ETIMER_G1_EN_OFFSET         0x12CU
#define ETIMER_LCNT_A_EN_OFFSET     0x14CU
#define ETIMER_LCNT_B_EN_OFFSET     0x16CU
#define ETIMER_LCNT_C_EN_OFFSET     0x18CU
#define ETIMER_LCNT_D_EN_OFFSET     0x1ACU
#define ETIMER_CPT_CTRL_OFFSET      0x210U
#define ETIMER_CMP_CTRL_OFFSET      0x2E0U
#define ETIMER_INT_STA_OFFSET       0x0U
#define ETIMER_INT_STA_EN_OFFSET    0x4U
#define ETIMER_INT_SIG_EN_OFFSET    0x8U

#define EPWM_DMA_CTRL_OFFSET      0xB8U
#define EPWM_SW_RST_OFFSET        0xA8U
#define EPWM_G0_EN_OFFSET         0x10CU
#define EPWM_G1_EN_OFFSET         0x12CU
#define EPWM_CMP_CTRL_OFFSET      0x2E0U
#define EPWM_INT_STA_OFFSET       0x0U
#define EPWM_INT_STA_EN_OFFSET    0x4U
#define EPWM_INT_SIG_EN_OFFSET    0x8U

#define SOC_PLL_REFCLK_FREQ     (24UL*1000UL*1000UL)


typedef enum {
    SOC_CKGEN_24M_OFF,
    SOC_CKGEN_24M_ON,
} soc_ckgen_24m;

/**
 * @brief wakupsrc enable.
 */
typedef enum {
    SOC_WAKEUP_SRC_DISABLE,
    SOC_WAKEUP_SRC_ENABLE,
} soc_wakeup_src_enable_e;

typedef struct {
    const soc_ckgen_24m     onoff;
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
    const rtc_alarm_t           *rtc;
    const gpio_group_t          *gpio;
} soc_wkup_src_t;

/* pwr_ctl0~3 pwr_on0~3 define */
typedef struct {
    const pmu_pwr_ctrl_t    *pwr_ctrl0;
    const pmu_pwr_ctrl_t    *pwr_ctrl1;
    const pmu_pwr_ctrl_t    *pwr_ctrl2;
    const pmu_pwr_ctrl_t    *pwr_ctrl3;
} soc_pwr_sig_t;

/* iram power mode define */
typedef struct {
    iramc_power_mode_e     iram1;
    iramc_power_mode_e     iram2;
    iramc_power_mode_e     iram3;
    iramc_power_mode_e     iram4;
} soc_iramc_pwr_mode_t;

#define SAF_LP_CTL(dom) (0x1008 + dom * 0x8)
#define SAF_RAM_LP_CTL(ram) (0x1060 + ram * 0x4)

#define PMU_SCRS_BITS_OFFSET 0X70U

#define AP_LP_CTL(dom) (0x1208 + dom * 0x8)
#define AP_RAM_LP_CTL(ram) (0x1260 + ram * 0x4)

enum smc_safety_dom {
    CR5_SF_DOM,
    CR5_SP_DOM,
    CR5_SX_DOM,
    GAMA_DOM,
    SAF_MISC,
    AP_DOM,
    DOM_END,
};

enum smc_safety_ram {
    CR5_SF_RAM,
    CR5_SP_RAM,
    CR5_SX_RAM,
    GAMA_RAM,
    AP_RAM,
};

/* declared in linker script, at the begining of the image, and shall be 8 bytes aligned.*/
extern unsigned long VECTOR_TBL_BASE[];

/**
 * @brief To remap cpu address zero (from CR5's view) to physical address 'addr'.
 * @brief Usually used to remap exception vector table. When Safety Image get running, the
 *        exception vector table sits at address 0x0 where is part of Boot ROM which had
 *        been locked already. Unfortunately, Cortex-R5 has no register to override exception
 *        vector table. To address this, E3 SOC provides a HW mechanism to remap some RAM
 *        address (say IRAM/TCM) to 'zero' address. To enable this feature, some SCR register
 *        need to be manipulated and a Cortex core reset need to be triggered.
 * @param[in]   addr    The physical address where vector table will be remapped to.
 */
void Mcu_RemapZeroTo(uint32 addr);

/**
 * @brief De-assert(release) moudle's reset signal.
 * @param[in]   m   the module which reset to be de-asserted.
 */
void Mcu_DeassertModuleReset(Mcu_ModuleType m);

/**
 * @brief Setup moudle's reset signal.
 * @detial Configure module's root clock per recommended setting from Semidrive.
 * @param[in]   m   the module which root clock to be setup.
 */
void Mcu_SetupModuleClk(Mcu_ModuleType m, Mcu_ModuleFreqType freq);

/**
 * @brief Assert moudle's reset signal.
 * @param[in]   m   the module which reset to be asserted.
 */
void Mcu_AssertModuleReset(Mcu_ModuleType m);

/**
 * @brief Set a flag to AP after modules had been handovered.
 * @details Safety image set a bit in AP rstgen GPR. AP can polling this bit then access
 *          Safety resource (the resources listed in MCU configuration data).
 */
void Mcu_SetHandoverFlag(void);

/**
 * @brief To check if Handover flag being set.
 * @return  TRUE if set, false if not set.
 */
boolean Mcu_IsHandoverFlagSet(void);

/**
 * @brief To check if AP domain powered and accessible.
 * @return  TRUE if powered and accessible, false if not set.
 */
uint32 soc_get_cpu_id(void);

uint32 soc_get_tcm_base(void);

uint32 soc_to_dma_address(uint32 cpu_addr);

uint32 soc_get_core_freq(void);

void soc_reset_latent_ip(Mcu_ModuleType m);
void soc_reset_adc(Mcu_ModuleType m);
void soc_power_gate(enum smc_safety_dom m);

/**
 * @brief reset all latent module.
 */
void soc_reset_btm(void);

/**
 * @brief To setup OSPI flash remapping. Shall never call it when
 *        caller is XIP-running on the flash to be remapped.
 * @param[in]  m        shall be OSPI1 or OSPI2.
 * @param[in]  offset   the offset to be added to CPU address.
 * @param[in]  size     the size to be remapped.
 */
void Mcu_Flash_Remap(Mcu_ModuleType m, uint32 offset, uint32 size);

/**
 * @brief To config rtc pad pin .
 * @param[in]  wakeup0   wakeup0 polarity.
 * @param[in]  wakeup1   wakeup1 polarity.
 * @param[in]  bc        bc polarity.
 */
void Mcu_RtcpadPinMuxConfig(pmu_polarity_e wakeup0, pmu_polarity_e wakeup1, pmu_polarity_e bc);

/**
 * @brief To config rtc wakeup process .
 * @param[in]  manual  muanul set RTC sleep time.
 * @param[in]  rtc   include rtc channel,timer and timer mode.
 * @param[in]  en   rtc polarity.
 */
void Mcu_RtcWakeupConfig(rtc_alarm_t *manual, const rtc_alarm_t *rtc, uint8 en);

/**
 * @brief To config BC Button wakeup process .
 * @param[in]  bc   include bc button on/off mode, on/off polarity,filter and window timer.
 * @param[in]  en   bc polarity.
 */
void Mcu_BCButtonWakeupConfig(const pmu_button_ctrl_t *bc, pmu_wakeup_src_enable_e en);

/**
 * @brief To config wakeup0 pin wakeup process .
 * @param[in]  wakeup0   include wakeup0 pin sensitive,polarity,filter enable,filter edge and filter timer.
 * @param[in]  en   wakeup0 pin enable.
 */
void Mcu_Wakep0PinWakeupConfig(const pmu_pin_ctrl_t *wakeup0, pmu_wakeup_src_enable_e en);

/**
 * @brief To config wakeup1 pin wakeup process .
 * @param[in]  wakeup1   include wakeup0 pin sensitive,polarity,filter enable,filter edge and filter timer.
 * @param[in]  en   wakeup1 pin enable.
 */
void Mcu_Wakep1PinWakeupConfig(const pmu_pin_ctrl_t *wakeup0, pmu_wakeup_src_enable_e en);

/**
 * @brief To config rtc mode wakeup source enable check.
 * @param[in]  wkupsrc   include rtc, wakeup0 pin, wakeup1 pin and BC Button.
 */
void Mcu_PmuWakeupSourceEnableConfig(const pmu_wakeup_src_t *wkupsrc);

/**
 * @brief To config Rstgen Reset or not when enter sleep mode.
 * @param[in]  wkupsrc   include rtc, wakeup0 pin, wakeup1 pin, BC Button and gpio.
 */
void Mcu_RstgenResetAssertConfig(const Mcu_ModuleType *pModule, enum reset_lowpower_mode mode);

/**
 * @brief To config pmu power signal .
 * @param[in]  pmu_mode    include hib mode, sleep mode.
 * @param[in]  pmu   include pwr_ctrl0~3, pwr_ctrl0~3, saf power, ap power.
 */
void Mcu_PmuPowerControlSignalConfig(pmu_state_e pmu_mode, const soc_pwr_sig_t *pmu);

/**
 * @brief To config smc wakeup source enable.
 * @param[in]  wkupsrc   include rtc, wakeup0 pin, wakeup1 pin, BC Button and gpio.
 */
void Mcu_WakeupSourceEnableConfig(const soc_wkup_src_t *wkupsrc, const Mcu_ModuleType *ip,
                                  soc_ckgen_24m onoff);

/**
 * @brief To Mask all smc irq .
 */
void Mcu_SmcAllIrqMaskConfig(void);

/**
 * @brief To config smc wfi .
 * @param[in]  smc   saf domain, ap domain and soc control.
 */
void Mcu_SoCEnterLpConfig(const smc_ctrl_t *smc, uint8 lpmode, soc_ckgen_24m onoff);

/**
 * @brief To act the wfi commond.
 */
void Mcu_ActionToWfi(uint8 mode);

/**
 * @brief To config ckgen clock .
 * @param[in]  pModule  wakup ip.
 * @param[in]  onoff    24M on off select.
 */
void Mcu_CkgenClockDisableConfig(const Mcu_ModuleType *pModule, uint8 mode, soc_ckgen_24m onoff);

/**
 * @brief To config iram power mode .
 * @param[in]  iram    iram id.
 */
void Mcu_IramPowerConfig(const soc_iramc_pwr_mode_t *iram);
/**
 * @brief To get cpu identify index .
*/
uint8  Mcu_GetCoreID();

uint8 Mcu_CoreId2HwId(uint8 coreid);

/**
 * @brief Pmu set power control polarity and override enable .
 * @param[in]  config    power ctrl polarity and override enable.
 * @param[in]  run_pmu   run mode pmu.
 * @param[in]  pwrup_pmu pwr up mode pmu.
 */
void Mcu_PmuSetPwrCtrlConfig(const pmu_pwr_ctrl_config_t *config, const soc_pwr_sig_t *run_pmu,
                             const soc_pwr_sig_t *pwrup_pmu);

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

#ifdef __cplusplus
}
#endif

#endif  /* MCU_SOC_H */
