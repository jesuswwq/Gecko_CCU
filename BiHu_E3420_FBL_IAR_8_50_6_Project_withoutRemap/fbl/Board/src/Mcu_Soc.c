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

#include "Std_Types.h"
#include "RegHelper.h"
#include "Mcu.h"
#include "Mcu_Ckgen.h"
#include "Rstgen_Idx.h"
#include "e3_clk.h"
#include "e3_clock_cfg_nd.h"
#include "Mcu_UserCallouts.h"
#include "Mcu_Mpu.h"
#include "debug.h"
#include "taishan_rstgen.h"
#include "debug.h"
#include "reset.h"

/* Version and Check Begin */
/* Version Info Begin */
#define MCU_SOC_C_VENDOR_ID    0x8C
#define MCU_SOC_C_AR_RELEASE_MAJOR_VERSION    4
#define MCU_SOC_C_AR_RELEASE_MINOR_VERSION    3
#define MCU_SOC_C_AR_RELEASE_REVISION_VERSION 1
#define MCU_SOC_C_SW_MAJOR_VERSION    1
#define MCU_SOC_C_SW_MINOR_VERSION    0
#define MCU_SOC_C_SW_PATCH_VERSION    0
/* Version Info End */

#ifdef __cplusplus
extern "C" {
#endif
#define DDR_MEMORY_END       APB_GPIO1_BASE

/*Macro for RTC IO PAD*/
#define PAD_CONFIG_SYS_MODE0 0x1000U
#define PAD_CONFIG_SYS_MODE1 0x1004U
#define PAD_CONFIG_SYS_POR_B 0x1008U
#define PAD_CONFIG_SYS_BUTTON 0x100cU
#define PAD_CONFIG_SYS_WAKEUP0 0x1010U
#define PAD_CONFIG_SYS_WAKEUP1 0x1014U
#define PAD_CONFIG_SYS_CTRL0 0x1018U
#define PAD_CONFIG_SYS_CTRL1 0x101cU
#define PAD_CONFIG_SYS_CTRL2 0x1020U
#define PAD_CONFIG_SYS_CTRL3 0x1024U

extern const reset_sig_t *xspi_reset_array[];
extern uint32 Mcu_GetXspiResetArraySize(void);

#define MCU_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

static clk_rate_t sf_clock, sp_clock, sx_clock;

#define MCU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"
/*
      In order to avoid data abort caused by the probability of bus error due to the
    misalignment of byte loading when XIP is not open when the cache is not open.
*/
static const uint32 core_mapping[CPU_ID_MAX] = {CPU_ID_SF, CPU_ID_SP0, CPU_ID_SP1, CPU_ID_SX0, CPU_ID_SX1};

#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

uint8 Mcu_GetCoreID(void)
{
    return core_mapping[arch_get_cpuid()];
}
/*
    This interface is only used for mailbox or hardware CoreId scenarios.
*/
uint8 Mcu_CoreId2HwId(uint8 coreid)
{
    if (coreid == CPU_ID_SP0)
        coreid = CPU_ID_SX0;
    else if (coreid == CPU_ID_SP1)
        coreid = CPU_ID_SX1;
    else if (coreid == CPU_ID_SX0)
        coreid = CPU_ID_SP0;
    else if (coreid == CPU_ID_SX1)
        coreid = CPU_ID_SP1;

    return coreid;
}

/* reset btm module */
static void soc_btm_reset(uint32 base)
{
    /* disable G0 */
    writel(0, base + BTM_G0_EN_OFFSET);
    /* disable G1 */
    writel(0, base + BTM_G1_EN_OFFSET);
    /* disable int */
    writel(0, base + BTM_INT_STA_EN_OFFSET);
    writel(0, base + BTM_INT_SIG_EN_OFFSET);
    /* clear int sta */
    writel(0xFFFFFFFF, base + BTM_INT_STA_OFFSET);
}

/* reset etimer counter module */
static void soc_etimer_reset(uint32 base)
{
    /* disable cpt module */
    writel(0, base + ETIMER_CPT_CTRL_OFFSET);
    /* disable cmp module */
    writel(0, base + ETIMER_CMP_CTRL_OFFSET);
    /* disable G0 */
    writel(0, base + ETIMER_G0_EN_OFFSET);
    /* disable G1 */
    writel(0, base + ETIMER_G1_EN_OFFSET);
    /* disable lcnt_a */
    writel(0, base + ETIMER_LCNT_A_EN_OFFSET);
    /* disable lcnt_b */
    writel(0, base + ETIMER_LCNT_B_EN_OFFSET);
    /* disable lcnt_c */
    writel(0, base + ETIMER_LCNT_C_EN_OFFSET);
    /* disable lcnt_d */
    writel(0, base + ETIMER_LCNT_D_EN_OFFSET);
    /* reset all counter to 0 */
    writel(0x3F, base + ETIMER_SW_RST_OFFSET);
    /* reset dma config */
    writel(0, base + ETIMER_DMA_CTRL_OFFSET);
    /* disable int */
    writel(0, base + ETIMER_INT_STA_EN_OFFSET);
    writel(0, base + ETIMER_INT_SIG_EN_OFFSET);
    /* clear int sta */
    writel(0xFFFFFFFF, base + ETIMER_INT_STA_OFFSET);
}

/* reset epwm counter module */
static void soc_epwm_reset(uint32 base)
{
    /* disable cmp module */
    writel(0, base + EPWM_CMP_CTRL_OFFSET);
    /* disable G0 */
    writel(0, base + EPWM_G0_EN_OFFSET);
    /* disable G1 */
    writel(0, base + EPWM_G1_EN_OFFSET);
    /* reset all counter and fifo to 0 */
    writel(0x3FF, base + EPWM_SW_RST_OFFSET);
    /* reset dma config */
    writel(0, base + EPWM_DMA_CTRL_OFFSET);
    /* disable int */
    writel(0, base + EPWM_INT_STA_EN_OFFSET);
    writel(0, base + EPWM_INT_SIG_EN_OFFSET);
    /* clear int sta */
    writel(0xFFFFFFFF, base + EPWM_INT_STA_OFFSET);
}

/* reset adc module */
static void soc_adc_reset(uint32 base)
{
    /* Reset adc analog and digital soft reset. */
    REG_RMW32(base + 0x00, 1, 1, 0);
    REG_RMW32(base + 0x00, 0, 1, 1);
    REG_RMW32(base + 0x00, 1, 1, 1);
    REG_RMW32(base + 0x00, 0, 1, 0);

    /* reset adc rc0/1/2/3 timer */
    REG_RMW32(base + 0x00, 2, 1, 1);
    REG_RMW32(base + 0x00, 3, 1, 1);
    REG_RMW32(base + 0x00, 4, 1, 1);
    REG_RMW32(base + 0x00, 5, 1, 1);

    REG_RMW32(base + 0x00, 2, 1, 0);
    REG_RMW32(base + 0x00, 3, 1, 0);
    REG_RMW32(base + 0x00, 4, 1, 0);
    REG_RMW32(base + 0x00, 5, 1, 0);

}

uint32 soc_get_tcm_base(void)
{
    uint32 Base;
    uint32 CpuId = Mcu_GetCoreID();

    if (CpuId == CPU_ID_SP0) {
        Base = R5_SP0TCM_BASE;
    } else if (CpuId == CPU_ID_SP1) {
        Base = R5_SP1TCM_BASE;
    } else if (CpuId == CPU_ID_SX0) {
        Base = R5_SX0TCM_BASE;
    } else if (CpuId == CPU_ID_SX1) {
        Base = R5_SX1TCM_BASE;
    } else {
        Base = R5_SF_TCM_BASE;
    }

    return Base;
}
uint32 soc_to_dma_address(uint32 cpu_addr)
{
    uint32 dma_addr = cpu_addr;
    uint32 TcmSize = Mcu_GetTcmSize();
    uint32 TcmBase = Mcu_GetTcmBase();

    if ((cpu_addr >= TcmBase ) && (cpu_addr < (TcmBase + TcmSize))) {
        dma_addr = soc_get_tcm_base() + (cpu_addr - TcmBase);
    }

    return dma_addr;
}


uint32 soc_get_core_freq(void)
{
    clk_rate_t core_freq = 0U;
    uint8 CoreId = Mcu_GetCoreID();

    if (CoreId == CPU_ID_SF) {
        core_freq = EXPECT_CORE_CLOCK_SF;
    } else if ((CoreId == CPU_ID_SP0) || (CoreId == CPU_ID_SP1)) {
        core_freq = EXPECT_CORE_CLOCK_SP;
    } else if ((CoreId == CPU_ID_SX0) || (CoreId == CPU_ID_SX1)) {
        core_freq = EXPECT_CORE_CLOCK_SX;
    } else {

    }

    return core_freq;
}

void soc_reset_btm(void)
{
    /*deinit btm*/
    /* for some reason, the user enable the freeruning btm timer and interrupt
    register, when reset with the debuger, the core reset, but BTM module and
    VIC not reset, so a btm nterrupt signal will rise, after the vic enable but
    btm no register, the core will exception. */
    soc_btm_reset(APB_BTM1_BASE);
    soc_btm_reset(APB_BTM2_BASE);
    soc_btm_reset(APB_BTM3_BASE);
    soc_btm_reset(APB_BTM4_BASE);
    soc_btm_reset(APB_BTM5_BASE);
    soc_btm_reset(APB_BTM6_BASE);
}

void soc_reset_latent_ip(Mcu_ModuleType m)
{
    switch (m) {
    case EPWM1:
        (void)soc_epwm_reset(APB_EPWM1_BASE);
        break;

    case EPWM2:
        (void)soc_epwm_reset(APB_EPWM2_BASE);
        break;

    case EPWM3:
        (void)soc_epwm_reset(APB_EPWM3_BASE);
        break;

    case EPWM4:
        (void)soc_epwm_reset(APB_EPWM4_BASE);
        break;

    case ETIMER1:
        (void)soc_etimer_reset(APB_ETMR1_BASE);
        break;

    case ETIMER2:
        (void)soc_etimer_reset(APB_ETMR2_BASE);
        break;

    case ETIMER3:
        (void)soc_etimer_reset(APB_ETMR3_BASE);
        break;

    case ETIMER4:
        (void)soc_etimer_reset(APB_ETMR4_BASE);
        break;

    default:
        break;
    }
}

void soc_reset_adc(Mcu_ModuleType m)
{
    switch (m) {
    case ADC1:
        (void)soc_adc_reset(APB_ADC1_BASE);
        break;

    case ADC2:
        (void)soc_adc_reset(APB_ADC2_BASE);
        break;

    case ADC3:
        (void)soc_adc_reset(APB_ADC3_BASE);
        break;


    default:
        break;
    }
}

void Mcu_RtcpadPinMuxConfig(pmu_polarity_e wakeup0, pmu_polarity_e wakeup1, pmu_polarity_e bc)
{
    rmw32(APB_IOMUXC_RTC_BASE + PAD_CONFIG_SYS_CTRL0, 0, 2, 0x1); /* pull down */
    rmw32(APB_IOMUXC_RTC_BASE + PAD_CONFIG_SYS_CTRL1, 0, 2, 0x1); /* pull down */
    rmw32(APB_IOMUXC_RTC_BASE + PAD_CONFIG_SYS_CTRL2, 0, 2, 0x1); /* pull down */
    rmw32(APB_IOMUXC_RTC_BASE + PAD_CONFIG_SYS_CTRL3, 0, 2, 0x1); /* pull down */

    if (wakeup0 == PMU_LOW_ACTIVE) {
        rmw32(APB_IOMUXC_RTC_BASE + PAD_CONFIG_SYS_WAKEUP0, 0, 2, 0x3); /* pull up */
    } else {
        rmw32(APB_IOMUXC_RTC_BASE + PAD_CONFIG_SYS_WAKEUP0, 0, 2, 0x1); /* pull down */
    }

    if (wakeup1 == PMU_LOW_ACTIVE) {
        rmw32(APB_IOMUXC_RTC_BASE + PAD_CONFIG_SYS_WAKEUP1, 0, 2, 0x3); /* pull up */
    } else {
        rmw32(APB_IOMUXC_RTC_BASE + PAD_CONFIG_SYS_WAKEUP1, 0, 2, 0x1); /* pull down */
    }

    rmw32(APB_IOMUXC_RTC_BASE + PAD_CONFIG_SYS_POR_B, 0, 2, 0x3); /* pull up */

    rmw32(APB_IOMUXC_RTC_BASE + PAD_CONFIG_SYS_MODE0, 0, 2, 0x1); /* pull down */
    rmw32(APB_IOMUXC_RTC_BASE + PAD_CONFIG_SYS_MODE1, 0, 2, 0x1); /* pull down */

    if (bc == PMU_LOW_ACTIVE) {
        rmw32(APB_IOMUXC_RTC_BASE + PAD_CONFIG_SYS_BUTTON, 0, 2, 0x3); /* pull up */
    } else {
        rmw32(APB_IOMUXC_RTC_BASE + PAD_CONFIG_SYS_BUTTON, 0, 2, 0x1); /* pull down */
    }
}

void Mcu_RtcWakeupConfig(rtc_alarm_t *manual, const rtc_alarm_t *rtc, uint8 en)
{
    if (en == SOC_WAKEUP_SRC_ENABLE) {
        if ( rtc->channel == RTC1 ) {
            /* Set RTC alarm time and enable wakeup */
            if (manual->timer1 != 0x0u)
                Rtc_SetSleepTime(APB_RTC1_BASE, manual->timer1, manual->timermode1);
            else
                Rtc_SetSleepTime(APB_RTC1_BASE, rtc->timer1, rtc->timermode1);
        } else if (rtc->channel == RTC2) {
            /* Set RTC alarm time and enable wakeup */
            if (manual->timer2 != 0x0u)
                Rtc_SetSleepTime(APB_RTC2_BASE, manual->timer2, manual->timermode2);
            else
                Rtc_SetSleepTime(APB_RTC2_BASE, rtc->timer2, rtc->timermode2);
        } else if (rtc->channel == ALL) {
            /* Set RTC alarm time and enable wakeup */
            if (manual->timer1 != 0x0u)
                Rtc_SetSleepTime(APB_RTC1_BASE, manual->timer1, manual->timermode1);
            else
                Rtc_SetSleepTime(APB_RTC1_BASE, rtc->timer1, rtc->timermode1);

            /* Set RTC alarm time and enable wakeup */
            if (manual->timer2 != 0x0u)
                Rtc_SetSleepTime(APB_RTC2_BASE, manual->timer2, manual->timermode2);
            else
                Rtc_SetSleepTime(APB_RTC2_BASE, rtc->timer2, rtc->timermode2);
        }
    } else {
        ;
    }

    manual->timer1 = 0;
    manual->timer2 = 0;
}

void Mcu_BCButtonWakeupConfig(const pmu_button_ctrl_t *bc, pmu_wakeup_src_enable_e en)
{
    if (en == PMU_WAKEUP_SRC_ENABLE) {
        /* Init ButtonControl Config. */
        Mcu_PmuButtonControlInit(bc);
    } else {
        ;
    }
}

void Mcu_Wakep0PinWakeupConfig(const pmu_pin_ctrl_t *wakeup0, pmu_wakeup_src_enable_e en)
{
    if (en == PMU_WAKEUP_SRC_ENABLE) {
        /* Init Wakeup 0 Config. */
        Mcu_PmuEnableWakeup0Wakeup(wakeup0);
    } else {
        ;
    }
}

void Mcu_Wakep1PinWakeupConfig(const pmu_pin_ctrl_t *wakeup1, pmu_wakeup_src_enable_e en)
{
    if (en == PMU_WAKEUP_SRC_ENABLE) {
        /* Init Wakeup 0 Config. */
        Mcu_PmuEnableWakeup1Wakeup(wakeup1);
    } else {
        ;
    }
}

void Mcu_PmuWakeupSourceEnableConfig(const pmu_wakeup_src_t *wkupsrc)
{
    /* RTC wakeup Enable Check */
    if (wkupsrc->rtcsrc == PMU_WAKEUP_SRC_ENABLE) {
        /* Enable RTC wakeup */
        Mcu_PmuEnableIntWakeupSrc(PMU_WAKEUP_SRC_ENABLE);

        /* Set RTC wakeup Source */
        //Mcu_PmuSetWakeupSource( PMU_WAKEUPSRC_RTC );
    } else {
        ;
    }

    /* wakeup0 pin and wakeup1 pin wakeup Enable Check */
    if ((wkupsrc->wakeup0src == PMU_WAKEUP_SRC_ENABLE)
        || (wkupsrc->wakeup1src == PMU_WAKEUP_SRC_ENABLE)) {
        /* Set Wakeup Source */
        //Mcu_PmuSetWakeupSource( PMU_WAKEUPSRC_WAKEUP_PIN );

        /* wakeup0 pin and wakeup1 pin logic check Config*/
        if (wkupsrc->wakeup01sel == PMU_LOGIC_AND) {
            Mcu_PmuEnableWakeup01Pin(PMU_WAKEUP_SRC_ENABLE);
        } else {
            Mcu_PmuEnableWakeup01Pin(PMU_WAKEUP_SRC_DISABLE);
        }
    } else {
        ;
    }

    /* BC Button Wakeup Enable Check */
    if (wkupsrc->BCButtonsrc == PMU_WAKEUP_SRC_ENABLE) {
        /* Enable BC Button wakeup */
        Mcu_PmuEnableExtWakeupSrc(PMU_WAKEUP_SRC_ENABLE);

        /* Set BC Button wakeup Source */
        //Mcu_PmuSetWakeupSource( PMU_WAKEUPSRC_BC_BUTTON );
    } else {
        ;
    }
}

void Mcu_UnmaskModuleInterruptBit(Mcu_ModuleType m)
{
    uint32 maskbit = 0;
    uint32 irqgroup = 0;

    switch (m) {
    case UART1:
    case UART2:
    case UART3:
    case UART4:
    case UART5:
    case UART6:
    case UART7:
    case UART8:
    case UART9:
    case UART10:
    case UART11:
    case UART12:
    case UART13:
    case UART14:
    case UART15:
    case UART16:
        maskbit = (m - UART1 + UART1_INTR_NUM - 16 ) % 32;
        irqgroup = ( m - UART1 + UART1_INTR_NUM - 16 ) / 32;
        Mcu_SmcComIrqUnMaskConfig(APB_SMC_BASE, SMC_CORE_SF, irqgroup, maskbit);
        break;

    case CAN1:
    case CAN2:
    case CAN3:
    case CAN4:
    case CAN5:
    case CAN6:
    case CAN7:
    case CAN8:
    case CAN9:
    case CAN10:
    case CAN11:
    case CAN12:
    case CAN13:
    case CAN14:
    case CAN15:
    case CAN16:
    case CAN17:
    case CAN18:
    case CAN19:
    case CAN20:
    case CAN21:
    case CAN22:
    case CAN23:
    case CAN24:
        maskbit = (m - CAN1 + CANFD1_CANFD_INTR_NUM - 16 ) % 32;
        irqgroup = ( m - CAN1 + CANFD1_CANFD_INTR_NUM - 16 ) / 32;
        Mcu_SmcComIrqUnMaskConfig(APB_SMC_BASE, SMC_CORE_SF, irqgroup, maskbit);
        break;

    case ETH1:
    case ETH2:
        maskbit = (m - ETH1 + ETH1_SBD_INTR_NUM - 16 ) % 32;
        irqgroup = ( m - ETH1 + ETH1_SBD_INTR_NUM - 16 ) / 32;
        Mcu_SmcComIrqUnMaskConfig(APB_SMC_BASE, SMC_CORE_SF, irqgroup, maskbit);
        break;

    case BTM1:
    case BTM2:
    case BTM3:
    case BTM4:
    case BTM5:
    case BTM6:
        maskbit = (m - BTM1 + BTM1_O_BTM_INTR_NUM - 16 ) % 32;
        irqgroup = ( m - BTM1 + BTM1_O_BTM_INTR_NUM - 16 ) / 32;
        Mcu_SmcComIrqUnMaskConfig(APB_SMC_BASE, SMC_CORE_SF, irqgroup, maskbit);
        break;

    default:
        break;
    }
}

void Mcu_RstgenResetAssertConfig(const Mcu_ModuleType *pModule, enum reset_lowpower_mode mode)
{
    for (uint32 i = 0; i < Mcu_GetXspiResetArraySize(); i++) {
        reset_ctl_lowpower_set((reset_sig_t *)xspi_reset_array[i], mode, 1);
    }
}

void Mcu_PmuPowerControlSignalConfig(pmu_state_e pmu_mode, const soc_pwr_sig_t *pmu)
{
    /* pwr_ctrl0 */
    if (pmu->pwr_ctrl0 != NULL_PTR) {
        Mcu_PmuSetExtPwrctrlMode(pmu_mode, PMU_PWRCTRL_0,
                                 pmu->pwr_ctrl0->automanual, pmu->pwr_ctrl0->onoff);
        Mcu_PmuSetExtPwrctrlDly(pmu_mode, PMU_PWRCTRL_0, pmu->pwr_ctrl0->delay, pmu->pwr_ctrl0->delayadj);
    } else {
        ;
    }

    /* pwr_ctrl1 */
    if (pmu->pwr_ctrl1 != NULL_PTR) {
        Mcu_PmuSetExtPwrctrlMode(pmu_mode, PMU_PWRCTRL_1,
                                 pmu->pwr_ctrl1->automanual, pmu->pwr_ctrl1->onoff);
        Mcu_PmuSetExtPwrctrlDly(pmu_mode, PMU_PWRCTRL_1, pmu->pwr_ctrl1->delay, pmu->pwr_ctrl1->delayadj);
    } else {
        ;
    }

    /* pwr_ctrl2 */
    if (pmu->pwr_ctrl2 != NULL_PTR) {
        Mcu_PmuSetExtPwrctrlMode(pmu_mode, PMU_PWRCTRL_2,
                                 pmu->pwr_ctrl2->automanual, pmu->pwr_ctrl2->onoff);
        Mcu_PmuSetExtPwrctrlDly(pmu_mode, PMU_PWRCTRL_2, pmu->pwr_ctrl2->delay, pmu->pwr_ctrl2->delayadj);
    } else {
        ;
    }

    /* pwr_ctrl3 */
    if (pmu->pwr_ctrl3 != NULL_PTR) {
        Mcu_PmuSetExtPwrctrlMode(pmu_mode, PMU_PWRCTRL_3,
                                 pmu->pwr_ctrl3->automanual, pmu->pwr_ctrl3->onoff);
        Mcu_PmuSetExtPwrctrlDly(pmu_mode, PMU_PWRCTRL_3, pmu->pwr_ctrl3->delay, pmu->pwr_ctrl3->delayadj);
    } else {
        ;
    }
}

void Mcu_PmuSetPwrCtrlConfig(const pmu_pwr_ctrl_config_t *config, const soc_pwr_sig_t *run_pmu,
                             const soc_pwr_sig_t *pwrup_pmu)
{
    if (NULL_PTR != config) {
        /* set pwr_ctrl auto polarity */
        Mcu_PmuSetExtPwrctrlPolarity(PMU_PWRCTRL_0, config->pwr_ctrl0_polarity);
        Mcu_PmuSetExtPwrctrlPolarity(PMU_PWRCTRL_1, config->pwr_ctrl1_polarity);
        Mcu_PmuSetExtPwrctrlPolarity(PMU_PWRCTRL_2, config->pwr_ctrl2_polarity);
        Mcu_PmuSetExtPwrctrlPolarity(PMU_PWRCTRL_3, config->pwr_ctrl3_polarity);
    }

    /* set pwr_ctrl for pwr_up mode */
    if (NULL_PTR != pwrup_pmu) {
        Mcu_PmuPowerControlSignalConfig(PMU_STATE_PWR_UP, pwrup_pmu);
    }

    /* set pwr_ctrl for run mode */
    if (NULL_PTR != run_pmu) {
        Mcu_PmuPowerControlSignalConfig(PMU_STATE_RUN, run_pmu);
    }
}

void Mcu_WakeupSourceEnableConfig(const soc_wkup_src_t *wkupsrc, const Mcu_ModuleType *ip,
                                  soc_ckgen_24m onoff)
{
    uint32 maskbit = 0;
    uint32 irqgroup = 0;

    /* RTC wakeup Enable Check */
    if (wkupsrc->rtcsrc == SMC_WAKEUP_SRC_ENABLE) {

        /* rtc irq unmask config */
        if (wkupsrc->rtc->channel == ALL) {
            /* rtc1 irq unmask*/
            maskbit = ( RTC1_RTC_WAKEUP_INTR_NUM - 16 ) % 32;
            irqgroup = ( RTC1_RTC_WAKEUP_INTR_NUM - 16 ) / 32;
            Mcu_SmcComIrqUnMaskConfig(APB_SMC_BASE, SMC_CORE_SF, irqgroup, maskbit);
            /* rtc2 irq unmask*/
            maskbit = ( RTC2_RTC_WAKEUP_INTR_NUM - 16 ) % 32;
            irqgroup = ( RTC2_RTC_WAKEUP_INTR_NUM - 16 ) / 32;
            Mcu_SmcComIrqUnMaskConfig(APB_SMC_BASE, SMC_CORE_SF, irqgroup, maskbit);
        } else if (wkupsrc->rtc->channel == RTC2) {
            /* rtc2 irq unmask*/
            maskbit = ( RTC2_RTC_WAKEUP_INTR_NUM - 16 ) % 32;
            irqgroup = ( RTC2_RTC_WAKEUP_INTR_NUM - 16 ) / 32;
            Mcu_SmcComIrqUnMaskConfig(APB_SMC_BASE, SMC_CORE_SF, irqgroup, maskbit);
        } else {
            /* rtc1 irq unmask*/
            maskbit = ( RTC1_RTC_WAKEUP_INTR_NUM - 16 ) % 32;
            irqgroup = ( RTC1_RTC_WAKEUP_INTR_NUM - 16 ) / 32;
            Mcu_SmcComIrqUnMaskConfig(APB_SMC_BASE, SMC_CORE_SF, irqgroup, maskbit);
        }
    } else {
        ;
    }

    /* Gpio wakeup Enable Check */
    if (wkupsrc->gpiosrc == SMC_WAKEUP_SRC_ENABLE) {

        /* GPIO_SF_Group0 */
        if (wkupsrc->gpio->sfgroup0 == TRUE) {
            /* smc irq unmask config */
            Mcu_SmcCoreIrqUnMaskConfig(APB_SMC_BASE, SMC_CORE_SF, GPIO_SF_ASYNC_GRP_0_INTR_NUM);
        } else {
            ;
        }

        /* GPIO_SF_Group1 */
        if (wkupsrc->gpio->sfgroup1 == TRUE) {
            /* smc irq unmask config */
            Mcu_SmcCoreIrqUnMaskConfig(APB_SMC_BASE, SMC_CORE_SF, GPIO_SF_ASYNC_GRP_1_INTR_NUM);
        } else {
            ;
        }

        /* GPIO_SF_Group2 */
        if (wkupsrc->gpio->sfgroup2 == TRUE) {
            /* smc irq unmask config */
            Mcu_SmcCoreIrqUnMaskConfig(APB_SMC_BASE, SMC_CORE_SF, GPIO_SF_ASYNC_GRP_2_INTR_NUM);
        } else {
            ;
        }

        /* GPIO_SF_Group3 */
        if (wkupsrc->gpio->sfgroup3 == TRUE) {
            /* smc irq unmask config */
            Mcu_SmcCoreIrqUnMaskConfig(APB_SMC_BASE, SMC_CORE_SF, GPIO_SF_ASYNC_GRP_3_INTR_NUM);
        } else {
            ;
        }

        /* GPIO_SF_Group4 */
        if (wkupsrc->gpio->sfgroup4 == TRUE) {
            /* smc irq unmask config */
            Mcu_SmcCoreIrqUnMaskConfig(APB_SMC_BASE, SMC_CORE_SF, GPIO_SF_ASYNC_GRP_4_INTR_NUM);
        } else {
            ;
        }

        /* GPIO_AP_Group0 */
        if (wkupsrc->gpio->apgroup0 == TRUE) {
            /* smc irq unmask config */
            Mcu_SmcCoreIrqUnMaskConfig(APB_SMC_BASE, SMC_CORE_SF, GPIO_AP_ASYNC_GRP_0_INTR_NUM);
        } else {
            ;
        }

        /* GPIO_AP_Group1 */
        if (wkupsrc->gpio->apgroup1 == TRUE) {
            /* smc irq unmask config */
            Mcu_SmcCoreIrqUnMaskConfig(APB_SMC_BASE, SMC_CORE_SF, GPIO_AP_ASYNC_GRP_1_INTR_NUM);
        } else {
            ;
        }

        /* GPIO_AP_Group2 */
        if (wkupsrc->gpio->apgroup2 == TRUE) {
            /* smc irq unmask config */
            Mcu_SmcCoreIrqUnMaskConfig(APB_SMC_BASE, SMC_CORE_SF, GPIO_AP_ASYNC_GRP_2_INTR_NUM);
        } else {
            ;
        }
    } else {
        ;
    }

    /* ip Wakeup Enable Check */
    if (onoff == SOC_CKGEN_24M_ON) { /* 24M On .*/
        const Mcu_ModuleType *pModule = ip;

        /* ip wakeup interrupt unmask */
        for (; *pModule != MODULE_END; pModule++) {
            Mcu_UnmaskModuleInterruptBit(*pModule);
        }
    } else {
        /* set 24M to off*/
    }
}

void Mcu_SmcAllIrqMaskConfig(void)
{
    uint32 cnt;

    /* mask all core irq */
    for ( cnt = 0; cnt < 5; cnt = cnt + 1) {
        Mcu_SmcCoreIrqMaskConfig(APB_SMC_BASE, cnt, SMC_CORE_IRQ_MASK);
    }

    /* mask all common irq */
    for ( cnt = 0; cnt < 5; cnt = cnt + 1) {
        Mcu_SmcComIrqMaskConfig(APB_SMC_BASE, cnt, SMC_COMM_IRQ_0, SMC_COMM_IRQ_MASK);
        Mcu_SmcComIrqMaskConfig(APB_SMC_BASE, cnt, SMC_COMM_IRQ_1, SMC_COMM_IRQ_MASK);
        Mcu_SmcComIrqMaskConfig(APB_SMC_BASE, cnt, SMC_COMM_IRQ_2, SMC_COMM_IRQ_MASK);
        Mcu_SmcComIrqMaskConfig(APB_SMC_BASE, cnt, SMC_COMM_IRQ_3, SMC_COMM_IRQ_MASK);
        Mcu_SmcComIrqMaskConfig(APB_SMC_BASE, cnt, SMC_COMM_IRQ_4, SMC_COMM_IRQ_MASK);
        Mcu_SmcComIrqMaskConfig(APB_SMC_BASE, cnt, SMC_COMM_IRQ_5, SMC_COMM_IRQ_MASK);
        Mcu_SmcComIrqMaskConfig(APB_SMC_BASE, cnt, SMC_COMM_IRQ_6, SMC_COMM_IRQ_MASK);
        Mcu_SmcComIrqMaskConfig(APB_SMC_BASE, cnt, SMC_COMM_IRQ_7, SMC_COMM_IRQ_MASK);
    }
}

void Mcu_SoCEnterLpConfig(const smc_ctrl_t *smc, uint8 lpmode, soc_ckgen_24m onoff)
{
    /* Note:
         If config core and core ram to power down, user need to check: whether need to save core
       and core ram data and  and resume it after wakeup.
    */
    uint32 b = APB_SMC_BASE;

    /* saf primary core set */
    Mcu_SmcSafPriCoreConfig(b, 0);

    /* saf wfi enable & lp mode */
    Mcu_SmcSafWfiConfig(b, SMC_WFI_ENABLE, smc->saf->saflp);

    if (MCU_MODE_HIB == lpmode) {
        /* core power down config */
        /* If sf/sp/sx power switch to off in sleep/hibernate mode,need:
           1. change the cpu clock to fs_24m
           2. then set SAF_LP_DLY_CTL_ISO_DIS at least 4 counter
           3. rechange the cpu clock to pll when wakeup from sleep/hibernate.
        */
        Mcu_SmcSafLpConfig(b, SMC_HIB_MODE, SMC_CORE_SF, smc->saf->sfpd);
        Mcu_SmcSafLpConfig(b, SMC_HIB_MODE, SMC_CORE_SP, smc->saf->sppd);
        Mcu_SmcSafLpConfig(b, SMC_HIB_MODE, SMC_CORE_SX, smc->saf->sxpd);
        Mcu_SmcSafLpConfig(b, SMC_HIB_MODE, SMC_CORE_GAMA1, smc->saf->gama3pd);

        /* ap & disp power gated */
        Mcu_SmcApLpConfig(b, SMC_HIB_MODE, smc->ap->appd);

        /* core ram power down config */
        Mcu_SmcSafRampdSettingConfig(b, SMC_HIB_MODE,
                                     SMC_RAM_LP_PG_EN | SMC_RAM_LP_RET1N | SMC_RAM_LP_RET2N,
                                     SMC_CORE_SF);
        Mcu_SmcSafRampdConfig(b, SMC_HIB_MODE, smc->saf->sfram, SMC_CORE_SF);

        Mcu_SmcSafRampdSettingConfig(b, SMC_HIB_MODE,
                                     SMC_RAM_LP_PG_EN | SMC_RAM_LP_RET1N | SMC_RAM_LP_RET2N,
                                     SMC_CORE_SP);
        Mcu_SmcSafRampdConfig(b, SMC_HIB_MODE, smc->saf->spram, SMC_CORE_SP);

        Mcu_SmcSafRampdSettingConfig(b, SMC_HIB_MODE,
                                     SMC_RAM_LP_PG_EN | SMC_RAM_LP_RET1N | SMC_RAM_LP_RET2N,
                                     SMC_CORE_SX);
        Mcu_SmcSafRampdConfig(b, SMC_HIB_MODE, smc->saf->sxram, SMC_CORE_SX);

        Mcu_SmcSafRampdSettingConfig(b, SMC_HIB_MODE,
                                     SMC_RAM_LP_PG_EN | SMC_RAM_LP_RET1N | SMC_RAM_LP_RET2N,
                                     SMC_CORE_GAMA1);
        Mcu_SmcSafRampdConfig(b, SMC_HIB_MODE, smc->saf->gama1ram, SMC_CORE_GAMA1);

        Mcu_SmcSafRampdSettingConfig(b, SMC_HIB_MODE,
                                     SMC_RAM_LP_PG_EN | SMC_RAM_LP_RET1N | SMC_RAM_LP_RET2N,
                                     SMC_SAF_MISC);
        Mcu_SmcSafRampdConfig(b, SMC_HIB_MODE, smc->saf->safmisc, SMC_SAF_MISC);

        Mcu_SmcApRampdSettingConfig(b, SMC_HIB_MODE, SMC_RAM_LP_PG_EN | SMC_RAM_LP_RET1N | SMC_RAM_LP_RET2N,
                                    SMC_CORE_DISP);
        Mcu_SmcApRampdConfig(b, SMC_HIB_MODE, smc->ap->apram, SMC_CORE_DISP);

        /* RC24M disable in hibernate state */
        if (onoff == SOC_CKGEN_24M_OFF) {
            Mcu_SmcSocHibrcDisConfig(b, SMC_RC_DIS_ENABLE);
        } else {
            ;
        }
    } else {
        ;
    }

    /* ap primary core set */
    Mcu_SmcApPriCoreConfig(b, 0);

    /* soc wakeup irq config */
    Mcu_SmcSocWkupirqWkupConfig(b, 0x1F, 0x1F);

    /* ap lp align with saf */
    Mcu_SmcApLpAlignSafConfig(b, smc->ap->lp);

    /* ap wakeup align with saf */
    Mcu_SmcApWkupAlignSafConfig(b, smc->ap->wkup);

    /* ap wfi enable & lp mode */
    Mcu_SmcApWfiConfig(b, SMC_WFI_ENABLE, smc->ap->aplp);

    /* ap off */
    Mcu_SmcSocGlobalConfig(b, SMC_AP_ON);
}

void Mcu_ActionToWfi(uint8 mode)
{
    __asm volatile ("wfi");

    DBG("wk from lowpower mode: %d\n", mode);
}

void Mcu_CkgenClockDisableConfig(const Mcu_ModuleType *pModule, uint8 mode, soc_ckgen_24m onoff)
{
    if (mode == MCU_MODE_SLP ) {
        /* domain clock gate */
        ckgen_sf_clk_dis(CKGEN_SLP_MODE, 0);
        ckgen_ap_clk_dis(CKGEN_SLP_MODE, 0);

        /* pll clock gate */
        ckgen_pll_dis(CKGEN_SLP_MODE, 0, CKGEN_SAF, 0);
        ckgen_pll_dis(CKGEN_SLP_MODE, 0, CKGEN_AP, 0);

        /* xtal clock gate */
        if (onoff == SOC_CKGEN_24M_OFF) {
            ckgen_xtal_dis(CKGEN_SLP_MODE, 0, CKGEN_SAF);
            ckgen_xtal_dis(CKGEN_SLP_MODE, 0, CKGEN_AP);
            ckgen_xtal_dis(CKGEN_RUN_MODE, 1, CKGEN_SAF);
            ckgen_xtal_dis(CKGEN_RUN_MODE, 1, CKGEN_AP);
        } else {
            ;
        }

    } else if (mode == MCU_MODE_HIB) {
        /* domain clock gate */
        ckgen_sf_clk_dis(CKGEN_HIB_MODE, 0);
        ckgen_ap_clk_dis(CKGEN_HIB_MODE, 0);

        /* pll clock power down */
        ckgen_pll_dis(CKGEN_HIB_MODE, 0, CKGEN_SAF, 1);
        ckgen_pll_dis(CKGEN_HIB_MODE, 0, CKGEN_AP, 1);

        /* xtal clock gate */
        if (onoff == SOC_CKGEN_24M_OFF) {
            ckgen_xtal_dis(CKGEN_HIB_MODE, 0, CKGEN_SAF);
            ckgen_xtal_dis(CKGEN_HIB_MODE, 0, CKGEN_AP);
            ckgen_xtal_dis(CKGEN_RUN_MODE, 1, CKGEN_SAF);
            ckgen_xtal_dis(CKGEN_RUN_MODE, 1, CKGEN_AP);
        } else {
            ;
        }
    } else {
        ;
    }
}

void Mcu_IramPowerConfig(const soc_iramc_pwr_mode_t *iram)
{
    /* Note:
         If config iram1/2/3/4 to power down, user need to check: whether need to save iram data
       and resume it after wakeup.
    */

    /* iram1 power mode config */
    Mcu_IramcPowerCfg(APB_IRAMC1_BASE, iram->iram1);

    /* iram2 power mode config */
    Mcu_IramcPowerCfg(APB_IRAMC2_BASE, iram->iram2);

    /* iram3 power mode config */
    Mcu_IramcPowerCfg(APB_IRAMC3_BASE, iram->iram3);

    /* iram4 power mode config */
    Mcu_IramcPowerCfg(APB_IRAMC4_BASE, iram->iram4);
}

static void ap_dom_gate(uint32 smc_base, enum smc_safety_dom dom,
                        bool gate)
{
    if (gate) {
        rmw32(smc_base + AP_LP_CTL(0), 0, 4, (uint32)0xfu);
        rmw32(smc_base + AP_LP_CTL(0), 4, 1, (uint32)1);
    } else {
        rmw32(smc_base + AP_LP_CTL(0), 4, 1, (uint32)0);
        rmw32(smc_base + AP_LP_CTL(0), 0, 4, (uint32)0);
    }
}

static void safety_dom_gate(uint32 smc_base, enum smc_safety_dom dom,
                            bool gate)
{
    if (gate) {
        rmw32(smc_base + SAF_LP_CTL(dom), 0, 4, (uint32)0xfu);
        rmw32(smc_base + SAF_LP_CTL(dom), 4, 1, (uint32)1);
    } else {
        rmw32(smc_base + SAF_LP_CTL(dom), 4, 1, (uint32)0);
        rmw32(smc_base + SAF_LP_CTL(dom), 0, 4, (uint32)0);
    }
}

static void ap_ram_gate(paddr_t smc_base, enum smc_safety_ram ram,
                        bool gate)
{
    if (gate) {
        /* normal mode gate */
        rmw32(smc_base + AP_RAM_LP_CTL(0), 2, 1, (uint32)1);
        rmw32(smc_base + AP_RAM_LP_CTL(0), 9, 3, (uint32)7);
        /* hib mode gate */
        rmw32(smc_base + AP_RAM_LP_CTL(0), 1, 1, (uint32)1);
        rmw32(smc_base + AP_RAM_LP_CTL(0), 6, 3, (uint32)7);
        /* slp mode gate */
        rmw32(smc_base + AP_RAM_LP_CTL(0), 0, 1, (uint32)1);
        rmw32(smc_base + AP_RAM_LP_CTL(0), 3, 3, (uint32)7);
    } else {
        /* normal mode gate */
        rmw32(smc_base + AP_RAM_LP_CTL(0), 9, 3, (uint32)3);
        rmw32(smc_base + AP_RAM_LP_CTL(0), 2, 1, (uint32)0);
        /* hib mode gate */
        rmw32(smc_base + AP_RAM_LP_CTL(0), 6, 3, (uint32)3);
        rmw32(smc_base + AP_RAM_LP_CTL(0), 1, 1, (uint32)0);
        /* slp mode gate */
        rmw32(smc_base + AP_RAM_LP_CTL(0), 3, 3, (uint32)3);
        rmw32(smc_base + AP_RAM_LP_CTL(0), 0, 1, (uint32)0);
    }
}

static void safety_ram_gate(paddr_t smc_base, enum smc_safety_ram ram,
                            bool gate)
{
    if (gate) {
        /* normal mode gate */
        rmw32(smc_base + SAF_RAM_LP_CTL(ram), 2, 1, (uint32)1);
        rmw32(smc_base + SAF_RAM_LP_CTL(ram), 9, 3, (uint32)7);
        /* hib mode gate */
        rmw32(smc_base + SAF_RAM_LP_CTL(ram), 1, 1, (uint32)1);
        rmw32(smc_base + SAF_RAM_LP_CTL(ram), 6, 3, (uint32)7);
        /* slp mode gate */
        rmw32(smc_base + SAF_RAM_LP_CTL(ram), 0, 1, (uint32)1);
        rmw32(smc_base + SAF_RAM_LP_CTL(ram), 3, 3, (uint32)7);
    } else {
        /* normal mode gate */
        rmw32(smc_base + SAF_RAM_LP_CTL(ram), 9, 3, (uint32)3);
        rmw32(smc_base + SAF_RAM_LP_CTL(ram), 2, 1, (uint32)0);
        /* hib mode gate */
        rmw32(smc_base + SAF_RAM_LP_CTL(ram), 6, 3, (uint32)3);
        rmw32(smc_base + SAF_RAM_LP_CTL(ram), 1, 1, (uint32)0);
        /* slp mode gate */
        rmw32(smc_base + SAF_RAM_LP_CTL(ram), 3, 3, (uint32)3);
        rmw32(smc_base + SAF_RAM_LP_CTL(ram), 0, 1, (uint32)0);
    }
}

static void ap_ana_gate(bool gate)
{
    if (gate) {
        /* PLL4/5 LVDS */
        rmw32(APB_PLL4_BASE, 0U, 1U, 1);
        rmw32(APB_PLL5_BASE, 0U, 1U, 1);
        rmw32(APB_PLL_LVDS_BASE, 0U, 1, 1);
        /* VD_AP */
        rmw32(APB_PMU_CORE_BASE + PMU_SCRS_BITS_OFFSET, 28U, 1U, 1U);
        /* POR_AP */
        rmw32(APB_PMU_CORE_BASE + PMU_SCRS_BITS_OFFSET, 27U, 1U, 1U);
        /* bgr33_ap */
        rmw32(APB_PMU_CORE_BASE + PMU_SCRS_BITS_OFFSET, 29U, 1U, 1U);
        /* bgr33_dis */
        rmw32(APB_PMU_CORE_BASE + PMU_SCRS_BITS_OFFSET, 30U, 1U, 1U);
        /* pt_sns_ap */
        rmw32(APB_PT_SNS_AP_BASE, 1U, 1U, 1U);
        rmw32(APB_PT_SNS_AP_BASE, 2U, 1U, 1U);
    } else {
        /* PLL4/5 LVDS */
        rmw32(APB_PLL4_BASE, 0U, 1U, 0U);
        rmw32(APB_PLL5_BASE, 0U, 1U, 0U);
        rmw32(APB_PLL_LVDS_BASE, 0U, 1U, 0U);
        /* VD_AP */
        rmw32(APB_PMU_CORE_BASE + PMU_SCRS_BITS_OFFSET, 28U, 1U, 0U);
        /* POR_AP */
        rmw32(APB_PMU_CORE_BASE + PMU_SCRS_BITS_OFFSET, 27U, 1U, 0U);
        /* bgr33_ap */
        rmw32(APB_PMU_CORE_BASE + PMU_SCRS_BITS_OFFSET, 29U, 1U, 0U);
        /* bgr33_dis */
        rmw32(APB_PMU_CORE_BASE + PMU_SCRS_BITS_OFFSET, 30U, 1U, 0U);
        /* pt_sns_ap */
        rmw32(APB_PT_SNS_AP_BASE, 1U, 1U, 0U);
        rmw32(APB_PT_SNS_AP_BASE, 2U, 1U, 0U);
    }
}

void soc_power_gate(enum smc_safety_dom m)
{
    switch (m) {
    case CR5_SF_DOM:
        safety_ram_gate(APB_SMC_BASE, CR5_SF_RAM, TRUE);
        safety_dom_gate(APB_SMC_BASE, CR5_SF_DOM, TRUE);
        break;

    case CR5_SX_DOM:
        safety_ram_gate(APB_SMC_BASE, CR5_SX_RAM, TRUE);
        safety_dom_gate(APB_SMC_BASE, CR5_SX_DOM, TRUE);
        break;

    case CR5_SP_DOM:
        safety_ram_gate(APB_SMC_BASE, CR5_SP_RAM, TRUE);
        safety_dom_gate(APB_SMC_BASE, CR5_SP_DOM, TRUE);
        break;

    case GAMA_DOM:
        safety_ram_gate(APB_SMC_BASE, GAMA_RAM, TRUE);
        safety_dom_gate(APB_SMC_BASE, GAMA_DOM, TRUE);
        break;

    case AP_DOM:
        ap_ana_gate(TRUE);
        ap_ram_gate(APB_SMC_BASE, AP_RAM, TRUE);
        ap_dom_gate(APB_SMC_BASE, AP_DOM, TRUE);
        break;

    default:
        break;
    }
}

/*
wakeup event is asserted at the end of lp handshake with rstgen/ckgen and before pmu
SMC may wake up rstgen/ckgen meanwhile request PMU to sleep.
SW should add this work around to all wakeup irq handlers if lowpower sequence is enable.
wakeup irq handler:
Step-1: check smc_dbg_mon(sf):
                                {12'b0,
                                saf_rstgen_swm_ack,saf_rstgen_swm_i[3:0],
                                saf_rstgen_swm_req,saf_rstgen_swm_o[3:0],
                                saf_ckgen_swm_ack,saf_ckgen_swm_i[3:0],
                                saf_ckgen_swm_req,saf_ckgen_swm_o[3:0]}

Possible Values
-- 0x0: ckgen_sf and rstgen_sf lowpower sequence haven't started, lowpower sequence abort
-- 0x21: ckgen_sf has entered lowpower and wakeup to RUN state, rstgen_sf lowpower hasn't started, SMC lowpower sequence abort.
-- 0x8421: ckgen_sf and rstgen_sf have entered lowpower state and woken up to RUN state
-- other values: un-expected failure

SW action
-- 0x0|0x21|0x8421: go ahead
-- other values: exception, need to debug

Step-2: check smc_dbg_mon(ap):
                                {12'b0,
                                ap_rstgen_swm_ack,ap_rstgen_swm_i[3:0],
                                ap_rstgen_swm_req,ap_rstgen_swm_o[3:0],
                                ap_ckgen_swm_ack,ap_ckgen_swm_i[3:0],
                                ap_ckgen_swm_req,ap_ckgen_swm_o[3:0]}
Possible Values
-- 0x0: ckgen_ap and ckgen_ap lowpower sequence haven't started, lowpower sequence abort
-- 0x21: ckgen_ap has entered lowpower and wakeup to RUN state, rstgen_ap lowpower hasn't start, SMC lowpower sequence abort.
-- 0x421: AP was reset, and AP lowpower seq is abort at this time (ckgen_ap entered lowpower and wakeup to RUN, rstgen_ap not start)
-- 0x401: ckgen_ap and rstgen_ap entered lowpower and wakeup to RUN, then AP domain was reset, and AP lowpower sequence hasn't start at this time
-- 0x8421: ckgen_ap and rstgen_ap have entered lowpower state and wake up to RUN state
-- other values: un-expected failure

SW action
-- 0x0|0x21|0x421|0x401|0x8421: go ahead
-- other values: exception, need to debug

Step-3: check smc_dbg_mon(pmu):
                                {22'b0,
                                pmu_swm_ack,pmu_swm_i[3:0],
                                pmu_swm_req,pmu_swm_o[3:0]}

Possible Values
-- 0x21: PMU is in RUN state
-- 0x32|0x34: smc sending swm_req = slp/hib, but PMU hasn't ACK
-- 0x242|0x284: at the end of lp handshake, smc has de-assert swm_req, PMU swm_ack still 1
-- 0x42|0x84: lowpower handshake is done, PMU is in sleep or hibernate state now
-- other values: exception, need to debug

SW action
-- 0x32|0x34|0x242|0x284:
1. Polling smc_dbg_mon = 0x42|0x84 to wait PMU lowpower handshake done
2. Configure SMC sw_swm register to send RUN request to PMU manually (sw_swm_en bit must be clear after handshake done)
3. Polling smc_dbg_mon = 0x21 to wait PMU wakeup handshake done
4. Polling ap_ss_rdy = 1 if AP power|ap_por_b is configured to OFF in lowpower state
-- 0x42|0x84: 2 ~ 4 steps above
-- 0x21: go ahead
-- other values: exception, need to debug"
 */
void Mcu_SmcSwmCheckAfterExitWfi(void)
{
    uint32 rdata = 0;
    uint32 timeout = 0;

    Mcu_SmcSetDebugMuxSelectMode(APB_SMC_BASE, SMC_DBG_HK_SAF);
    rdata = Mcu_SmcGetDebugMonitorStatus(APB_SMC_BASE);

    if ((rdata != 0x00) && (rdata != 0x21) && (rdata != 0x8421)) {
        ERROR("mux data: need to debug the reasion\n");
    } else {
        ;
    }

    Mcu_SmcSetDebugMuxSelectMode(APB_SMC_BASE, SMC_DBG_HK_AP);
    rdata = Mcu_SmcGetDebugMonitorStatus(APB_SMC_BASE);

    if ((rdata != 0x00) && (rdata != 0x21) && (rdata != 0x421) && (rdata != 0x401)
        && (rdata != 0x8421)) {
        ERROR("mux data: need to debug the reasion\n");
    } else {
        ;
    }

    Mcu_SmcSetDebugMuxSelectMode(APB_SMC_BASE, SMC_DBG_HK_PMU);
    rdata = Mcu_SmcGetDebugMonitorStatus(APB_SMC_BASE);

    if ((rdata == 0x32) || (rdata == 0x34) || (rdata == 0x242) || (rdata == 0x284) || (rdata == 0x221)
        || (rdata == 0x294) || (rdata == 0x252)) {
        while (((Mcu_SmcGetDebugMonitorStatus(APB_SMC_BASE)) != 0x42)
               && ((Mcu_SmcGetDebugMonitorStatus(APB_SMC_BASE)) != 0x84) && (timeout++ < 1000U));

        Mcu_SmcSetPmuSwSwmMode(APB_SMC_BASE, 0x0);

        timeout = 0;
        while (((Mcu_SmcGetDebugMonitorStatus(APB_SMC_BASE)) != 0x21) && (timeout++ < 1000U));

        timeout = 0;
        while (((taishan_rstgen_lld_get_ss_rdy(APB_RSTGEN_AP_BASE)) != 1) && (timeout++ < 1000U));
    } else if ((rdata == 0x42) || (rdata == 0x84)) {
        Mcu_SmcSetPmuSwSwmMode(APB_SMC_BASE, 0x0);

        while (((Mcu_SmcGetDebugMonitorStatus(APB_SMC_BASE)) != 0x21) && (timeout++ < 1000U));

        timeout = 0;
        while (((taishan_rstgen_lld_get_ss_rdy(APB_RSTGEN_AP_BASE)) != 1) && (timeout++ < 1000U));
    } else {
        if ((rdata != 0x21)) {
            ERROR("mux data: need to debug the reasion\n");
        } else {
            ;
        }
    }

    if (timeout >= 1000U)
        ERROR("mux data: need to debug the reasion\n");
}

void Mcu_SmcSwitchClockTo24Mhz(void)
{
    clk_node_t *clk = NULL_PTR;

    /*  switch clock to 24m  */
    clk = CLK_NODE(g_ckgen_bus_cr5_sf_div_root);
    sf_clock = clk_get_rate(clk);
    clk = CLK_NODE(g_ckgen_bus_cr5_sf_div_root_preset);
    clk_set_rate(clk, 24000000);

    clk = CLK_NODE(g_ckgen_bus_cr5_sp_div_root);
    sp_clock = clk_get_rate(clk);
    clk = CLK_NODE(g_ckgen_bus_cr5_sf_div_root_preset);
    clk_set_rate(clk, 24000000);

    clk = CLK_NODE(g_ckgen_core_cr5_sx);
    sx_clock = clk_get_rate(clk);
    clk_set_rate(clk, 24000000);
}

void Mcu_SmcSwitchClockToNormal(void)
{
    clk_node_t *clk = NULL_PTR;

    /*  switch clock to normal  */
    clk = CLK_NODE(g_ckgen_bus_cr5_sf_div_root);
    clk_set_rate(clk, sf_clock);

    clk = CLK_NODE(g_ckgen_bus_cr5_sp_div_root);
    clk_set_rate(clk, sp_clock);

    clk = CLK_NODE(g_ckgen_core_cr5_sx);
    clk_set_rate(clk, sx_clock);

#if (STD_OFF == MCU_APDOMAIN_POWERDOWN)
    /*restore AP domain clk*/
    clk_prepare(CLK_NODE(g_ckgen_bus_ap_bus_div_root_preset));
    clk_prepare(CLK_NODE(g_ckgen_bus_seip_div_root_preset));
    clk_prepare(CLK_NODE(g_pll4_root));
    clk_prepare(CLK_NODE(g_pll5_root));
    clk_prepare(CLK_NODE(g_pll_lvds_root));
    clk_prepare(CLK_NODE(g_pll_lvds_nodiv));
    clk_prepare(CLK_NODE(g_pll_lvds_div2));
    clk_prepare(CLK_NODE(g_pll_lvds_div7));
    clk_prepare(CLK_NODE(g_pll_lvds_ckgen));
    clk_prepare(CLK_NODE(g_ckgen_bus_ap_bus_div_root));
    clk_prepare(CLK_NODE(g_ckgen_bus_ap_bus_div_p));
    clk_prepare(CLK_NODE(g_ckgen_bus_ap_bus_div_n));
    clk_prepare(CLK_NODE(g_ckgen_bus_ap_bus_root));
    clk_prepare(CLK_NODE(g_ckgen_bus_seip_div_root));
    clk_prepare(CLK_NODE(g_ckgen_bus_seip_div_p));
    clk_prepare(CLK_NODE(g_ckgen_bus_seip_div_n));
    clk_prepare(CLK_NODE(g_ckgen_bus_seip_root));
    clk_prepare(CLK_NODE(g_ckgen_ip_reserved));
    clk_prepare(CLK_NODE(g_ckgen_ip_seip_test));
    clk_prepare(CLK_NODE(g_ckgen_ip_sdramc));
    clk_prepare(CLK_NODE(g_ckgen_ip_sehc1));
    clk_prepare(CLK_NODE(g_ckgen_ip_sehc2));
    clk_prepare(CLK_NODE(g_ckgen_ip_pt_sns_ap));
    clk_prepare(CLK_NODE(g_ckgen_ip_ap_test));
#endif
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif
