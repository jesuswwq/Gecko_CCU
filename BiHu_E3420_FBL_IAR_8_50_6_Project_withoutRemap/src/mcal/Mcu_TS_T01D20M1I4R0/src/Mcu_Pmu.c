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

/* PRQA S 0777,0795 EOF */

#ifdef __cplusplus
extern "C" {
#endif

#include "RegHelper.h"
#include "Mcu_Pmu.h"
#include "Pmu_Reg.h"
#include "Mcu_Soc.h"
#include "Mcu.h"

/* Version and Check Begin */
/* Version Info Begin */
#define MCU_PMU_C_VENDOR_ID    0x8C
#define MCU_PMU_C_AR_RELEASE_MAJOR_VERSION    4
#define MCU_PMU_C_AR_RELEASE_MINOR_VERSION    3
#define MCU_PMU_C_AR_RELEASE_REVISION_VERSION 1
#define MCU_PMU_C_SW_MAJOR_VERSION    1
#define MCU_PMU_C_SW_MINOR_VERSION    0
#define MCU_PMU_C_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((MCU_PMU_C_AR_RELEASE_MAJOR_VERSION != MCU_PMU_H_AR_RELEASE_MAJOR_VERSION)\
    || (MCU_PMU_C_AR_RELEASE_MINOR_VERSION != MCU_PMU_H_AR_RELEASE_MINOR_VERSION)\
    || (MCU_PMU_C_AR_RELEASE_REVISION_VERSION != MCU_PMU_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Mcu_Pmu.c and Mcu_Pmu.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((MCU_PMU_C_SW_MAJOR_VERSION != MCU_PMU_H_SW_MAJOR_VERSION)\
    || (MCU_PMU_C_SW_MINOR_VERSION != MCU_PMU_H_SW_MINOR_VERSION)\
    || (MCU_PMU_C_SW_PATCH_VERSION != MCU_PMU_H_SW_PATCH_VERSION))
#error "Opps, Mcu_Pmu.c and Mcu_Pmu.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((MCU_PMU_C_AR_RELEASE_MAJOR_VERSION != PMU_REG_H_AR_RELEASE_MAJOR_VERSION)\
    || (MCU_PMU_C_AR_RELEASE_MINOR_VERSION != PMU_REG_H_AR_RELEASE_MINOR_VERSION)\
    || (MCU_PMU_C_AR_RELEASE_REVISION_VERSION != PMU_REG_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Mcu_Pmu.c and Pmu_Reg.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((MCU_PMU_C_SW_MAJOR_VERSION != PMU_REG_H_SW_MAJOR_VERSION)\
    || (MCU_PMU_C_SW_MINOR_VERSION != PMU_REG_H_SW_MINOR_VERSION)\
    || (MCU_PMU_C_SW_PATCH_VERSION != PMU_REG_H_SW_PATCH_VERSION))
#error "Opps, Mcu_Pmu.c and Pmu_Reg.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((MCU_PMU_C_AR_RELEASE_MAJOR_VERSION != MCU_SOC_H_AR_RELEASE_MAJOR_VERSION)\
    || (MCU_PMU_C_AR_RELEASE_MINOR_VERSION != MCU_SOC_H_AR_RELEASE_MINOR_VERSION)\
    || (MCU_PMU_C_AR_RELEASE_REVISION_VERSION != MCU_SOC_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Mcu_Pmu.c and Mcu_Soc.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((MCU_PMU_C_SW_MAJOR_VERSION != MCU_SOC_H_SW_MAJOR_VERSION)\
    || (MCU_PMU_C_SW_MINOR_VERSION != MCU_SOC_H_SW_MINOR_VERSION)\
    || (MCU_PMU_C_SW_PATCH_VERSION != MCU_SOC_H_SW_PATCH_VERSION))
#error "Opps, Mcu_Pmu.c and Mcu_Soc.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

#define PMU_PWR_SIGNAL_DELAY_SETTING_MASK       (0x3fU)
#define FM_PWR_ON_SET_PWR_ON_X_SET_MASK         (0xfU)

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

char *Mcu_PmuGetStateStr(pmu_state_e state)
{
    return state == PMU_STATE_PWR_UP ? "PMU_STATE_PWR_UP" :
           state == PMU_STATE_RUN ? "PMU_STATE_RUN" :
           state == PMU_STATE_SLEEP ? "PMU_STATE_SLEEP" :
           state == PMU_STATE_HIBERNATE ? "PMU_STATE_HIBERNATE" :
           state == PMU_STATE_RTC ? "PMU_STATE_RTC" :
           state == PMU_STATE_OFF ? "PMU_STATE_OFF" :
           "Invalid PMU state";
}

uint8 Mcu_PmuGetState(void)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + PMU_STATE) ;

    /* pmu internal state */
    v &= FM_PMU_STATE_PMU_STATE;

    return v;
}

void Mcu_PmuSetSfPorPgControl(pmu_pg_ctrl_e enable)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + PG_LP_MODE_CTRL);

    /* sf_hv/lv_pg disable/enable */
    if (enable == PMU_PG_ENABLE) {
        v &= ~BM_PG_LP_MODE_CTRL_SF_HV_PG_DISABLE;
        v &= ~BM_PG_LP_MODE_CTRL_SF_LV_PG_DISABLE;
    } else {
        v |= BM_PG_LP_MODE_CTRL_SF_HV_PG_DISABLE;
        v |= BM_PG_LP_MODE_CTRL_SF_LV_PG_DISABLE;
    }

    writel(v, b + PG_LP_MODE_CTRL);
}

void Mcu_PmuSetAPPorPgControl(pmu_pg_ctrl_e enable)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + PG_LP_MODE_CTRL);

    /* ap_hv/lv_pg disable/enable */
    if (enable == PMU_PG_ENABLE) {
        v &= ~BM_PG_LP_MODE_CTRL_AP_HV_PG_DISABLE;
        v &= ~BM_PG_LP_MODE_CTRL_AP_LV_PG_DISABLE;
    } else {
        v |= BM_PG_LP_MODE_CTRL_AP_HV_PG_DISABLE;
        v |= BM_PG_LP_MODE_CTRL_AP_LV_PG_DISABLE;
    }

    writel(v, b + PG_LP_MODE_CTRL);
}

uint32 Mcu_PmuGetWakeupSource(void)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + PMU_DOWN_UP_STATUS) ;
    /* wakeup event source */
    v &= PMU_WAKE_UP_SOURCE;

    return v;
}

void Mcu_PmuSetWakeupSource(pmu_wakeup_src_e src)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + PMU_DOWN_UP_STATUS) ;

    /* wakeup event source */
    v |= (0x1U << src);
    writel(v, b + PMU_DOWN_UP_STATUS);
}

uint16 Mcu_PmuGetPowerDownReqSource(void)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + PMU_DOWN_UP_STATUS) ;

    /* pmu power down request source */
    v &= PMU_POWER_DOWN_SOURCE;

    return v;
}

void Mcu_PmuSetPowerDownReqSource( pmu_powerdown_src_e src)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + PMU_DOWN_UP_STATUS) ;

    /* pmu power down request source */
    v |= (0x1U << src);
    writel(v, b + PMU_DOWN_UP_STATUS);
}

/******************************************************************************
 * button control
*****************************************************************************/
void Mcu_PmuEnableButtonCtrlFsm(pmu_bc_moni_switch_e status)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + BC_CTRL_SET);

    /* enable/disable the state monitory for ButtonControl */
    if (status == PMU_MONI_ENABLE) {
        /* enable */
        v |= BM_BC_CTRL_SET_BC_FSM_ENABLE;

    } else {
        /* disable */
        v &= ~BM_BC_CTRL_SET_BC_FSM_ENABLE;
    }

    writel(v, b + BC_CTRL_SET);
}

void Mcu_PmuEnableButtonCtrlPin(pmu_bc_switch_e status)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + BC_CTRL_SET);

    if (v & BM_BC_CTRL_SET_BC_DISABLE_LOCK)
        return ;

    /* enable/disable the ButtonControl pin */
    if (status == PMU_BC_ENABLE) {
        /* enable */
        v &= ~BM_BC_CTRL_SET_BC_DISABLE;
    } else {
        /* disable */
        v |= BM_BC_CTRL_SET_BC_DISABLE;
    }

    writel(v, b + BC_CTRL_SET);
}

void Mcu_PmuSetButtonCtrlOffPolarity(pmu_polarity_e polarity)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + BC_CTRL_SET);

    /* polarity of ButtonControl pin for off */
    if (PMU_LOW_ACTIVE == polarity) {
        /* 1:low active or falling edge OFF:high active or rising edge */
        v |= BM_BC_CTRL_SET_BC_OFF_POL;
    } else {
        /* 0:high active or rising edge OFF:low active or failing edge */
        v &= ~BM_BC_CTRL_SET_BC_OFF_POL;
    }

    writel(v, b + BC_CTRL_SET);
}

void Mcu_PmuSetButtonCtrlOnPolarity(pmu_polarity_e polarity)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + BC_CTRL_SET);

    /* polarity of ButtonControl pin for on */
    if (PMU_LOW_ACTIVE == polarity) {
        /* 1:low active or falling edge OFF:high active or rising edge */
        v |= BM_BC_CTRL_SET_BC_ON_POL;
    } else {
        /* 0:high active or rising edge OFF:low active or failing edge */
        v &= ~BM_BC_CTRL_SET_BC_ON_POL;
    }

    writel(v, b + BC_CTRL_SET);
}

void Mcu_PmuSetButtonCtrlOffSensitive(pmu_trigger_mode_e sensitive)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + BC_CTRL_SET);

    /* sensitive of ButtonControl pin for off */
    if (PMU_TRIGGER_MODE_EDGE == sensitive) {
        /* 1: Edge */
        v |= BM_BC_CTRL_SET_BC_OFF_EDGE;
    } else {
        /* 0: Level */
        v &= ~BM_BC_CTRL_SET_BC_OFF_EDGE;
    }

    writel(v, b + BC_CTRL_SET);
}

void Mcu_PmuSetButtonCtrlOnSensitive(pmu_trigger_mode_e sensitive)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + BC_CTRL_SET);

    /* sensitive of ButtonControl pin for off */
    if (PMU_TRIGGER_MODE_EDGE == sensitive) {
        /* 1: Edge */
        v |= BM_BC_CTRL_SET_BC_ON_EDGE;
    } else {
        /* 0: Level */
        v &= ~BM_BC_CTRL_SET_BC_ON_EDGE;
    }

    writel(v, b + BC_CTRL_SET);
}

void Mcu_PmuSetButtonControlFilterTimer(uint16 filterCnt, uint16 SampleInterval)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + BC_CTRL_SET);

    /* set filter (BC_FILTER_CNT+2)*(2^BC_SAMPLE_INTERVAL)=(1+2)*(2^0)=3*0.03125=0.1ms
       32K = 0.03125ms */
    v &= ~FM_BC_CTRL_SET_BC_FILTER_CNT;
    v &= ~FM_BC_CTRL_SET_BC_SAMPLE_INTERVAL;
    v |= FV_BC_CTRL_SET_BC_FILTER_CNT(filterCnt);
    v |= FV_BC_CTRL_SET_BC_SAMPLE_INTERVAL(SampleInterval);

    writel(v, b + BC_CTRL_SET);
}

void Mcu_PmuSetButtonCtrlMaxoffWindow(uint8 time)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + BC_VLD_WINDOW);

    /* max window for valid "OFF" */
    v &= ~FM_BC_VLD_WINDOW_BC_OFF_VLD_MAX;
    v |= FV_BC_VLD_WINDOW_BC_OFF_VLD_MAX(time);
    writel(v, b + BC_VLD_WINDOW);
}

void Mcu_PmuSetButtonCtrlMinOffWindow(uint8 time)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + BC_VLD_WINDOW);

    /* min window for valid "OFF" */
    v &= ~FM_BC_VLD_WINDOW_BC_OFF_VLD_MIN;
    v |= FV_BC_VLD_WINDOW_BC_OFF_VLD_MIN(time);
    writel(v, b + BC_VLD_WINDOW);
}

void Mcu_PmuSetButtonCtrlMaxOnWindow(uint8 time)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + BC_VLD_WINDOW);

    /* max window for valid "ON" */
    v &= ~FM_BC_VLD_WINDOW_BC_ON_VLD_MAX;
    v |= FV_BC_VLD_WINDOW_BC_ON_VLD_MAX(time);

    writel(v, b + BC_VLD_WINDOW);
}

void Mcu_PmuSetButtonCtrlMinOnWindow(uint8 time)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + BC_VLD_WINDOW);

    /* min window for valid "ON" */
    v &= ~FM_BC_VLD_WINDOW_BC_ON_VLD_MIN;
    v |= FV_BC_VLD_WINDOW_BC_ON_VLD_MIN(time);

    writel(v, b + BC_VLD_WINDOW);
}

void Mcu_PmuEnableButtonCtrlMaxOffWindowSwitch(pmu_bc_win_check_e status)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + BC_CTRL_SET);

    /* enable/disable max window for valid "OFF" */
    if (status == PMU_BC_WINDOW_CHECK_ENABLE) {
        /* enable */
        v &= ~BM_BC_CTRL_SET_BC_OFF_VLD_MAX_DISABLE;
    } else {
        /* disable */
        v |= BM_BC_CTRL_SET_BC_OFF_VLD_MAX_DISABLE;
    }

    writel(v, b + BC_CTRL_SET);
}

void Mcu_PmuEnableButtonCtrlMaxOnWindowSwitch(pmu_bc_win_check_e status)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + BC_CTRL_SET);

    /* enable/disable max window for valid "ON" */
    if (status == PMU_BC_WINDOW_CHECK_ENABLE) {
        /* enable */
        v &= ~BM_BC_CTRL_SET_BC_ON_VLD_MAX_DISABLE;
    } else {
        /* disable */
        v |= BM_BC_CTRL_SET_BC_ON_VLD_MAX_DISABLE;
    }

    writel(v, b + BC_CTRL_SET);
}

void Mcu_PmuSetButtonCtrlWindowTimerUnit(uint8 unit)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + BC_CTRL_SET);

    /* control unit for ButtonControl */
    v &= ~FM_BC_CTRL_SET_BC_CNT_UNIT;
    v |= FV_BC_CTRL_SET_BC_CNT_UNIT(unit);

    writel(v, b + BC_CTRL_SET);
}

void Mcu_PmuEnableButtonCtrlFilterBypass(pmu_filter_select_e en)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + BC_CTRL_SET);

    /* bypass filter for ButtonControl */
    if (en == PMU_FILTER_ENABLE) {
        /* filter is enable */
        v &= ~BM_BC_CTRL_SET_BC_FILTER_BYPASS;
    } else {
        /* bypass filter */
        v |= BM_BC_CTRL_SET_BC_FILTER_BYPASS;
    }

    writel(v, b + BC_CTRL_SET);
}

void Mcu_PmuSetButtonCtrlFilterEdge(pmu_edge_type_e edge)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + BC_CTRL_SET);

    /* select which edge need to apply the filter for ButtonControl */
    v &= ~FM_BC_CTRL_SET_BC_FILTER_EDGE;
    v |= FV_BC_CTRL_SET_BC_FILTER_EDGE(edge);

    writel(v, b + BC_CTRL_SET);
}

void Mcu_PmuButtonControlInit(const pmu_button_ctrl_t *bc)
{
    /* enable BC button fsm */
    Mcu_PmuEnableButtonCtrlFsm(PMU_MONI_DISABLE);

    /* set BC button sensitive level */
    Mcu_PmuSetButtonCtrlOffSensitive(bc->offmode);

    if (PMU_TRIGGER_MODE_LEVEL == bc->offmode) {
        Mcu_PmuSetButtonCtrlWindowTimerUnit(bc->timerunit);
        Mcu_PmuSetButtonCtrlMinOffWindow(bc->offminvldwin);

        if (PMU_BC_WINDOW_CHECK_ENABLE == bc->offmaxvldsel) {
            Mcu_PmuEnableButtonCtrlMaxOffWindowSwitch(bc->offmaxvldsel);
            Mcu_PmuSetButtonCtrlMaxoffWindow(bc->offmaxvldwin);
        }
    } else {
        /* switch BC button filter */
        Mcu_PmuEnableButtonCtrlFilterBypass(bc->filterbypass);

        if (PMU_FILTER_ENABLE == bc->filterbypass) {
            /* BC button filter edge set */
            Mcu_PmuSetButtonCtrlFilterEdge(bc->edgetype);

            /* set BC button filter timer (BC_FILTER_CNT+2)*(2^BC_SAMPLE_INTERVAL) */
            Mcu_PmuSetButtonControlFilterTimer(bc->filterCnt, bc->SampleInterval);
        } else {
            ;
        }
    }

    /* set BC button on detect mode */
    Mcu_PmuSetButtonCtrlOnSensitive(bc->onmode);

    if (PMU_TRIGGER_MODE_LEVEL == bc->onmode) {
        Mcu_PmuSetButtonCtrlWindowTimerUnit(bc->timerunit);
        Mcu_PmuSetButtonCtrlMinOnWindow(bc->onminvldwin);

        if ( PMU_BC_WINDOW_CHECK_ENABLE == bc->onmaxvldsel ) {
            Mcu_PmuEnableButtonCtrlMaxOnWindowSwitch(bc->onmaxvldsel);
            Mcu_PmuSetButtonCtrlMaxOnWindow(bc->onmaxvldwin);
        }
    } else {
        /* switch button ctrl filter */
        Mcu_PmuEnableButtonCtrlFilterBypass(bc->filterbypass);

        if (PMU_FILTER_ENABLE == bc->filterbypass) {
            /* set BC button filter edge */
            Mcu_PmuSetButtonCtrlFilterEdge(bc->edgetype);
            /* set BC button filter timer(BC_FILTER_CNT+2)*(2^BC_SAMPLE_INTERVAL) */
            Mcu_PmuSetButtonControlFilterTimer(bc->filterCnt, bc->SampleInterval);
        } else {
            ;
        }
    }

    /* set BC button off polarity */
    Mcu_PmuSetButtonCtrlOffPolarity(bc->offpol);

    /* set BC button on polarity */
    Mcu_PmuSetButtonCtrlOnPolarity(bc->onpol);

    /* enable BC button pin */
    Mcu_PmuEnableButtonCtrlPin(PMU_BC_ENABLE);
}

void Mcu_PmuSetExtPwrctrlMode(pmu_state_e pmu_mode, pmu_pwrctrl_id_e id, pmu_auto_manual_e d1,
                              pmu_on_off_e d2)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + PWR_CTRL_SET0);
    uint32 data = (d2 << 1) | d1;
    uint32 offset1 = 6 - id * 2;

    switch (pmu_mode) {
    case PMU_STATE_RTC:
        v &= ~(FM_PWR_CTRL_SET0_PWR_CTRL_SET_MASK << (BM_PWR_CTRL_SET0_RTC_PWR_CTRL + offset1));
        v |= (data << (BM_PWR_CTRL_SET0_RTC_PWR_CTRL + offset1));
        break;

    case PMU_STATE_RUN:
        v &= ~(FM_PWR_CTRL_SET0_PWR_CTRL_SET_MASK << (BM_PWR_CTRL_SET0_RUN_PWR_CTRL + offset1));
        v |= (data << (BM_PWR_CTRL_SET0_RUN_PWR_CTRL + offset1));
        break;

    case PMU_STATE_SLEEP:
        v &= ~(FM_PWR_CTRL_SET0_PWR_CTRL_SET_MASK << (BM_PWR_CTRL_SET0_SLEEP_PWR_CTRL + offset1));
        v |= (data << (BM_PWR_CTRL_SET0_SLEEP_PWR_CTRL + offset1));
        break;

    case PMU_STATE_HIBERNATE:
        v &= ~(FM_PWR_CTRL_SET0_PWR_CTRL_SET_MASK << (BM_PWR_CTRL_SET0_HIBERNATE_PWR_CTRL + offset1));
        v |= (data << (BM_PWR_CTRL_SET0_HIBERNATE_PWR_CTRL + offset1));
        break;

    default:
        break;
    }

    writel(v, b + PWR_CTRL_SET0);
}

void Mcu_PmuSetExtPwrctrlDly(pmu_state_e pmu_mode, pmu_pwrctrl_id_e id, uint8 delay,
                             uint8 delay_adj)
{
    uint32 b = PMU_RBASE;
    uint32 mode_offset = PWR_UP_PWR_CTRL_DELAY + pmu_mode * 4;
    uint32 pwrctrl_startbit = id * 6;
    uint32 v = readl(b + mode_offset);

    v &= ~(PMU_PWR_SIGNAL_DELAY_SETTING_MASK << pwrctrl_startbit);
    v |= ((((delay_adj & FM_PWR_CTRL_SET0_PWR_CTRL_SET_MASK) << 4 | delay) & PMU_PWR_SIGNAL_DELAY_SETTING_MASK) <<
          pwrctrl_startbit);

    writel(v, b + mode_offset);
}

void Mcu_PmuSetExtPwrctrlPolarity(pmu_pwrctrl_id_e id, pmu_polarity_e polarity)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + PWR_CTRL_SET1);

    if (PMU_LOW_ACTIVE == polarity) {
        v |= (1 << (BM_PWR_CTRL_SET1_PWR_CTRL_POL + id));
    } else {
        v &= ~(1 << (BM_PWR_CTRL_SET1_PWR_CTRL_POL + id));
    }

    writel(v, b + PWR_CTRL_SET1);
}

void Mcu_PmuSetExtPwrctrlOverrideEnable(pmu_pwrctrl_id_e id,
                                        const pmu_pwrctrl_select_e OverrideEnable)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + PWR_CTRL_SET1);

    if (PMU_PWRCTRL_SELECT == OverrideEnable) {
        v |= (1 << (BM_PWR_CTRL_SET1_SW_PWR_CTRL_EN + id));
    } else {
        v &= ~(1 << (BM_PWR_CTRL_SET1_SW_PWR_CTRL_EN + id));
    }

    writel(v, b + PWR_CTRL_SET1);
}

void Mcu_PmuSetExtPwrctrlOverrideValue(pmu_pwrctrl_id_e id, const pmu_polarity_e value)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + PWR_CTRL_SET1);

    if (PMU_HIGH_ACTIVE == value) {
        v |= (1 << (BM_PWR_CTRL_SET1_SW_PWR_CTRL + id));
    } else {
        v &= ~(1 << (BM_PWR_CTRL_SET1_SW_PWR_CTRL + id));
    }

    writel(v, b + PWR_CTRL_SET1);
}

void Mcu_PmuSetInternalPwronMode(pmu_state_e pmu_mode, pmu_pwron_id_e id,
                                 pmu_auto_manual_e d1, pmu_on_off_e d2, pmu_target_e d3 )
{
    uint32 b = PMU_RBASE;
    uint32 v = 0;
    uint32 data = 0;
    uint32 offset1 = 0 + id * 4;
    uint32 offset2 = 1 + id * 4;
    uint32 offset3 = 2 + id * 4;

    switch (pmu_mode) {
    case PMU_STATE_RTC:
        v = readl(b + RTC_PWR_ON_SET );
        data |= (d1 << offset1);
        data |= (d2 << offset2);
        data |= (d3 << offset3);
        v &= ~(FM_PWR_ON_SET_PWR_ON_X_SET_MASK << offset1);
        v |= data;
        writel(v, b + RTC_PWR_ON_SET);
        break;

    case PMU_STATE_RUN:
        v = readl(b + RUN_PWR_ON_SET );
        data |= (d1 << offset1);
        data |= (d2 << offset2);
        data |= (d3 << offset3);
        v &= ~(FM_PWR_ON_SET_PWR_ON_X_SET_MASK << offset1);
        v |= data;
        writel(v, b + RUN_PWR_ON_SET);
        break;

    case PMU_STATE_SLEEP:
        v = readl(b + SLEEP_PWR_ON_SET );
        data |= (d1 << offset1);
        data |= (d2 << offset2);
        data |= (d3 << offset3);
        v &= ~(FM_PWR_ON_SET_PWR_ON_X_SET_MASK << offset1);
        v |= data;
        writel(v, b + SLEEP_PWR_ON_SET);
        break;

    case PMU_STATE_HIBERNATE:
        v = readl(b + HIBERNATE_PWR_ON_SET );
        data |= (d1 << offset1);
        data |= (d2 << offset2);
        data |= (d3 << offset3);
        v &= ~(FM_PWR_ON_SET_PWR_ON_X_SET_MASK << offset1);
        v |= data;
        writel(v, b + HIBERNATE_PWR_ON_SET);
        break;

    default:
        break;
    }
}

void Mcu_PmuSetSfPowerMode(pmu_state_e pmu_mode, pmu_on_off_e d1)
{
    uint32 b = PMU_RBASE;
    uint32 v = 0;
    uint32 data = 0;
    uint32 offset1 = 17;

    switch (pmu_mode) {
    case PMU_STATE_RTC:
        v = readl(b + RTC_PWR_ON_SET );
        data |= (d1 << offset1);
        v &= ~BM_RTC_PWR_ON_SET_SF_PWR_ON_SET;
        v |= data;
        writel(v, b + RTC_PWR_ON_SET);
        break;

    case PMU_STATE_RUN:
        v = readl(b + RUN_PWR_ON_SET );
        data |= (d1 << offset1);
        v &= ~BM_RUN_PWR_ON_SET_SF_PWR_ON_SET;
        v |= data;
        writel(v, b + RUN_PWR_ON_SET);
        break;

    case PMU_STATE_SLEEP:
        v = readl(b + SLEEP_PWR_ON_SET );
        data |= (d1 << offset1);
        v &= ~BM_SLEEP_PWR_ON_SET_SF_PWR_ON_SET;
        v |= data;
        writel(v, b + SLEEP_PWR_ON_SET);
        break;

    case PMU_STATE_HIBERNATE:
        v = readl(b + HIBERNATE_PWR_ON_SET );
        data |= (d1 << offset1);
        v &= ~BM_HIBERNATE_PWR_ON_SET_SF_PWR_ON_SET;
        v |= data;
        writel(v, b + HIBERNATE_PWR_ON_SET);
        break;

    default:
        break;
    }
}

void Mcu_PmuSetApPowerMode(pmu_state_e pmu_mode, pmu_on_off_e d1)
{
    uint32 b = PMU_RBASE;
    uint32 v = 0;
    uint32 data = 0;
    uint32 offset1 = 16;

    switch (pmu_mode) {
    case PMU_STATE_RTC:
        v = readl(b + RTC_PWR_ON_SET );
        data |= (d1 << offset1);
        v &= ~BM_RTC_PWR_ON_SET_AP_PWR_ON_SET;
        v |= data;
        writel(v, b + RTC_PWR_ON_SET);
        break;

    case PMU_STATE_RUN:
        v = readl(b + RUN_PWR_ON_SET );
        data |= (d1 << offset1);
        v &= ~BM_RUN_PWR_ON_SET_AP_PWR_ON_SET;
        v |= data;
        writel(v, b + RUN_PWR_ON_SET);
        break;

    case PMU_STATE_SLEEP:
        v = readl(b + SLEEP_PWR_ON_SET );
        data |= (d1 << offset1);
        v &= ~BM_SLEEP_PWR_ON_SET_AP_PWR_ON_SET;
        v |= data;
        writel(v, b + SLEEP_PWR_ON_SET);
        break;

    case PMU_STATE_HIBERNATE:
        v = readl(b + HIBERNATE_PWR_ON_SET );
        data |= (d1 << offset1);
        v &= ~BM_HIBERNATE_PWR_ON_SET_AP_PWR_ON_SET;
        v |= data;
        writel(v, b + HIBERNATE_PWR_ON_SET);
        break;

    default:
        break;
    }
}

void Mcu_PmuSetPwronDly(pmu_state_e pmu_mode,
                        uint8 id, uint8 delay,
                        uint8 delay_adj)
{
    uint32 b = PMU_RBASE;
    uint32 mode_offset = PWR_UP_PWR_ON_DELAY + pmu_mode * 4;
    uint32 pwron_startbit = id * 6;
    uint32 v = readl(b + mode_offset);

    /* delay setting of pwr_on0~3 in pmu power state */
    v |= (((delay_adj << 4 | delay) & PMU_PWR_SIGNAL_DELAY_SETTING_MASK) << pwron_startbit) ;

    writel(v, b + mode_offset);
}

void Mcu_PmuSetIgnorePGFromSfHvPor(pmu_ignore_e status)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + RTC_PWR_ON_SET);

    if (status == PMU_IGNORE_YES) {
        /* ignore */
        v |= BM_RTC_PWR_ON_SET_RTC_TO_OFF_SF_HV_PG_DISABLE;
    } else {
        /* consider */
        v &= ~BM_RTC_PWR_ON_SET_RTC_TO_OFF_SF_HV_PG_DISABLE;
    }

    writel(v, b + RTC_PWR_ON_SET);
}

void Mcu_PmuSetIgnorePGFromSfLvPor(pmu_ignore_e status)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + RTC_PWR_ON_SET);

    if (status == PMU_IGNORE_YES) {
        /* ignore */
        v |= BM_RTC_PWR_ON_SET_RTC_TO_OFF_SF_LV_PG_DISABLE;
    } else {
        /* consider */
        v &= ~BM_RTC_PWR_ON_SET_RTC_TO_OFF_SF_LV_PG_DISABLE;
    }

    writel(v, b + RTC_PWR_ON_SET);
}

void Mcu_PmuSetIgnorePGFromApHvPor(pmu_ignore_e status)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + RTC_PWR_ON_SET);

    if (status == PMU_IGNORE_YES) {
        /* ignore */
        v |= BM_RTC_PWR_ON_SET_RTC_TO_OFF_AP_HV_PG_DISABLE;
    } else {
        /* consider */
        v &= ~BM_RTC_PWR_ON_SET_RTC_TO_OFF_AP_HV_PG_DISABLE;
    }

    writel(v, b + RTC_PWR_ON_SET);
}

void Mcu_PmuSetIgnorePGFromApLvPor(pmu_ignore_e status)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + RTC_PWR_ON_SET);

    if (status == PMU_IGNORE_YES) {
        /* ignore */
        v |= BM_RTC_PWR_ON_SET_RTC_TO_OFF_AP_LV_PG_DISABLE;
    } else {
        /* consider */
        v &= ~BM_RTC_PWR_ON_SET_RTC_TO_OFF_AP_LV_PG_DISABLE;
    }

    writel(v, b + RTC_PWR_ON_SET);
}
/******************************************************************************
 * pmu wakeup pin
 *****************************************************************************/
uint8 Mcu_PmuGetWakeup0EnableStatus(void)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + WAKEUP_CTRL) ;

    /* wakup0 pin status */
    v &= BM_WAKEUP_CTRL_WKUP0_DISABLE;

    return v;
}

uint8 Mcu_PmuGetWakeup1EnableStatus(void)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + WAKEUP_CTRL) ;

    /* wakup1 pin status */
    v &= BM_WAKEUP_CTRL_WKUP1_DISABLE;

    return v;
}

uint8 Mcu_PmuGetWakeup0Pol(void)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + WAKEUP_CTRL) ;

    /* polarity selection for wakup0 pin */
    v &= BM_WAKEUP_CTRL_WKUP0_POL;

    return v;
}

uint8 Mcu_PmuGetWakeup1Pol(void)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + WAKEUP_CTRL) ;

    /* polarity selection for wakup1 pin */
    v &= BM_WAKEUP_CTRL_WKUP1_POL;

    return v;
}

void Mcu_PmuSetWakeup0PinPolarity(pmu_polarity_e polarity)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + WAKEUP_CTRL);

    /* polarity selection for wakup0 pin */
    if (PMU_HIGH_ACTIVE == polarity) {
        /* high active (for level mode), rising edge (for edge mode ) */
        v &= ~BM_WAKEUP_CTRL_WKUP0_POL;
    } else {
        /* low active (for level mode), falling edge (for edge mode ) */
        v |= BM_WAKEUP_CTRL_WKUP0_POL;
    }

    writel(v, b + WAKEUP_CTRL);
}

void Mcu_PmuSetWakeup1PinPolarity(pmu_polarity_e polarity)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + WAKEUP_CTRL);

    /* polarity selection for wakup0 pin */
    if (PMU_HIGH_ACTIVE == polarity) {
        /* high active (for level mode), rising edge (for edge mode ) */
        v &= ~BM_WAKEUP_CTRL_WKUP1_POL;
    } else {
        /* low active (for level mode), falling edge (for edge mode ) */
        v |= BM_WAKEUP_CTRL_WKUP1_POL;
    }

    writel(v, b + WAKEUP_CTRL);
}

void Mcu_PmuSetWakeup0PinSensitive(pmu_trigger_mode_e sensitive)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + WAKEUP_CTRL);

    /* level or edge selection for wakeup0 */
    if (PMU_TRIGGER_MODE_EDGE == sensitive) {
        /* edge */
        v |= BM_WAKEUP_CTRL_WKUP0_EDGE;
    } else {
        /* level */
        v &= ~BM_WAKEUP_CTRL_WKUP0_EDGE;
    }

    writel(v, b + WAKEUP_CTRL);
}

void Mcu_PmuSetWakeup1PinSensitive(pmu_trigger_mode_e sensitive)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + WAKEUP_CTRL);

    /* level or edge selection for wakeup1 */
    if (PMU_TRIGGER_MODE_EDGE == sensitive) {
        /* edge */
        v |= BM_WAKEUP_CTRL_WKUP1_EDGE;
    } else {
        /* level */
        v &= ~BM_WAKEUP_CTRL_WKUP1_EDGE;
    }

    writel(v, b + WAKEUP_CTRL);
}

void Mcu_PmuEnableWakeup0Pin(pmu_wakeup_src_enable_e enable)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + WAKEUP_CTRL);

    /* enable/disable the wakeup0 pin */
    if (PMU_WAKEUP_SRC_ENABLE == enable) {
        /* enable */
        v &= ~BM_WAKEUP_CTRL_WKUP0_DISABLE;
    } else {
        /* disable */
        v |= BM_WAKEUP_CTRL_WKUP0_DISABLE;
    }

    writel(v, b + WAKEUP_CTRL);
}

void Mcu_PmuEnableWakeup1Pin(pmu_wakeup_src_enable_e enable)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + WAKEUP_CTRL);

    /* enable/disable the wakeup1 pin */
    if (PMU_WAKEUP_SRC_ENABLE == enable) {
        /* enable */
        v &= ~BM_WAKEUP_CTRL_WKUP1_DISABLE;
    } else {
        /* disable */
        v |= BM_WAKEUP_CTRL_WKUP1_DISABLE;
    }

    writel(v, b + WAKEUP_CTRL);
}

void Mcu_PmuEnableWakeup01Pin(pmu_wakeup_src_enable_e enable)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + WAKEUP_CTRL);

    /* when enabled,generate the wakeup event only when wakeup0 and wakeup1 are both active */
    if (PMU_WAKEUP_SRC_ENABLE == enable) {
        /* enable */
        v |= BM_WAKEUP_CTRL_WKUP01_AND_ENABLE;
    } else {
        /* disable */
        v &= ~BM_WAKEUP_CTRL_WKUP01_AND_ENABLE;
    }

    writel(v, b + WAKEUP_CTRL);
}

void Mcu_PmuEnableWakeup0FilterBypass(pmu_filter_select_e en)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + WAKEUP_CTRL);

    /* filter bypass for wakeup0 pin */
    if (en == PMU_FILTER_ENABLE) {
        /* enable the filter */
        v &= ~BM_WAKEUP_CTRL_WKUP0_FILTER_BYPASS;
    } else {
        /* filter bypass*/
        v |= BM_WAKEUP_CTRL_WKUP0_FILTER_BYPASS;
    }

    writel(v, b + WAKEUP_CTRL);
}

void Mcu_PmuEnableWakeup1FilterBypass(pmu_filter_select_e en)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + WAKEUP_CTRL);

    /* filter bypass for wakeup1 pin */
    if (en == PMU_FILTER_ENABLE) {
        /* enable the filter */
        v &= ~BM_WAKEUP_CTRL_WKUP1_FILTER_BYPASS;
    } else {
        /* filter bypass*/
        v |= BM_WAKEUP_CTRL_WKUP1_FILTER_BYPASS;
    }

    writel(v, b + WAKEUP_CTRL);
}

void Mcu_PmuSetWakeup0FilterEdge(pmu_edge_type_e edgetype)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + WAKEUP_CTRL);

    /* select which edge need to apply the filter for wakeup0 pin */
    v &= ~FM_WAKEUP_CTRL_WKUP0_FILTER_EDGE;
    v |= FV_WAKEUP_CTRL_WKUP0_FILTER_EDGE(edgetype);

    writel(v, b + WAKEUP_CTRL);
}

void Mcu_PmuSetWakeup1FilterEdge(pmu_edge_type_e edgetype)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + WAKEUP_CTRL);

    /* select which edge need to apply the filter for wakeup1 pin */
    v &= ~FM_WAKEUP_CTRL_WKUP1_FILTER_EDGE;
    v |= FV_WAKEUP_CTRL_WKUP1_FILTER_EDGE(edgetype);

    writel(v, b + WAKEUP_CTRL);
}

void Mcu_PmuSetWakeup0FilterTimer(uint16 filtercnt, uint16 sampleinterval)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + WAKEUP_CTRL);

    /* set filter (BC_FILTER_CNT+2)*(2^BC_SAMPLE_INTERVAL)=(1+2)*(2^0)=3*0.03125=0.1ms
       32K = 0.03125ms */
    v &= ~FM_WAKEUP_CTRL_WKUP0_FILTER_CNT;
    v &= ~FM_WAKEUP_CTRL_WKUP0_SAMPLE_INTERVAL;
    v |= FV_WAKEUP_CTRL_WKUP0_FILTER_CNT(filtercnt);
    v |= FV_WAKEUP_CTRL_WKUP0_SAMPLE_INTERVAL(sampleinterval);

    writel(v, b + WAKEUP_CTRL);
}

void Mcu_PmuSetWakeup1FilterTimer(uint16 filtercnt, uint16 sampleinterval)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + WAKEUP_CTRL);

    /* set filter (BC_FILTER_CNT+2)*(2^BC_SAMPLE_INTERVAL)=(1+2)*(2^0)=3*0.03125=0.1ms
       32K = 0.03125ms */
    v &= ~FM_WAKEUP_CTRL_WKUP1_FILTER_CNT;
    v &= ~FM_WAKEUP_CTRL_WKUP1_SAMPLE_INTERVAL;
    v |= FV_WAKEUP_CTRL_WKUP1_FILTER_CNT(filtercnt);
    v |= FV_WAKEUP_CTRL_WKUP1_SAMPLE_INTERVAL(sampleinterval);

    writel(v, b + WAKEUP_CTRL);
}

void Mcu_PmuLockSRCSStateRetentionBits(uint32 data)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + SRCS_BITS);

    v |= GFV_SRCS_BITS_SRCS_BITS(data);

    writel(v, b + SRCS_BITS);
}

void Mcu_PmuSetSRCSStateRetentionBits(uint32 data)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + SRCS_BITS_SET);

    v |= GFV_SRCS_BITS_SET_SRCS_BITS(data);

    writel(v, b + SRCS_BITS_SET);
}

void Mcu_PmuClrSRCSStateRetentionBits(uint32 data)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + SRCS_BITS_CLR);

    v |= GFV_SRCS_BITS_CLR_SRCS_BITS(data);

    writel(v, b + SRCS_BITS_CLR);
}

void Mcu_PmuEnableWakeup0Wakeup(const pmu_pin_ctrl_t *wakeupctl)
{
#ifndef SEMIDRIVE_E3_LITE_SERIES
    uint32 version = Mcu_GetChipVersion();

    if (version == 1) {
#endif
        if (wakeupctl->pulseedgetype == PMU_EDGE_TYPE_INVALID) {
            /* set pin detect mode */
            Mcu_PmuSetWakeup0PinSensitive(wakeupctl->sensitive);

            /* set pin edge filter data */
            if (PMU_TRIGGER_MODE_EDGE == wakeupctl->sensitive) {
                /* switch pin edge filter */
                Mcu_PmuEnableWakeup0FilterBypass(wakeupctl->filterbypass);

                if (PMU_FILTER_ENABLE == wakeupctl->filterbypass) {
                    /* set pin filter edge */
                    Mcu_PmuSetWakeup0FilterEdge(wakeupctl->edgetype);
                    /* set pin filter timer*/
                    Mcu_PmuSetWakeup0FilterTimer(wakeupctl->filtercnt, wakeupctl->sampleinterval);
                } else {
                    ;
                }
            }
        } else {
            if (PMU_EDGE_TYPE_RISING == wakeupctl->edgetype) {
                rmw32(APB_PMU_CORE_BASE + SRCS_BITS, 31, 1, 0x1);
                rmw32(APB_PMU_CORE_BASE + SRCS_BITS, 20, 1, 0x0);
            } else if (PMU_EDGE_TYPE_FALLING == wakeupctl->edgetype) {
                rmw32(APB_PMU_CORE_BASE + SRCS_BITS, 31, 1, 0x0);
                rmw32(APB_PMU_CORE_BASE + SRCS_BITS, 20, 1, 0x1);
            } else if (PMU_EDGE_TYPE_BOTH == wakeupctl->edgetype) {
                rmw32(APB_PMU_CORE_BASE + SRCS_BITS, 31, 1, 0x1);
                rmw32(APB_PMU_CORE_BASE + SRCS_BITS, 20, 1, 0x1);
            } else {
                ;
            }

            /* set pin detect mode */
            Mcu_PmuSetWakeup0PinSensitive(PMU_TRIGGER_MODE_EDGE);

            /* switch pin edge filter */
            Mcu_PmuEnableWakeup0FilterBypass(PMU_FILTER_BYPASS);
        }
#ifndef SEMIDRIVE_E3_LITE_SERIES
    } else {
        /* set pin detect mode */
        Mcu_PmuSetWakeup0PinSensitive(wakeupctl->sensitive);

        /* set pin edge filter data */
        if (PMU_TRIGGER_MODE_EDGE == wakeupctl->sensitive) {
            /* set pin edge filter */
            Mcu_PmuEnableWakeup0FilterBypass(wakeupctl->filterbypass);

            if (PMU_FILTER_ENABLE == wakeupctl->filterbypass) {
                /* set pin filter edge */
                Mcu_PmuSetWakeup0FilterEdge(wakeupctl->edgetype);
                /* set pin filter timer*/
                Mcu_PmuSetWakeup0FilterTimer(wakeupctl->filtercnt, wakeupctl->sampleinterval);
            } else {
                ;
            }
        }
    }
#endif
    /* set pin polarity */
    Mcu_PmuSetWakeup0PinPolarity(wakeupctl->polarity);

    /* enable wakeup0 pin */
    Mcu_PmuEnableWakeup0Pin(PMU_WAKEUP_SRC_ENABLE);
}

void Mcu_PmuEnableWakeup1Wakeup(const pmu_pin_ctrl_t *wakeupctl)
{
    /* set pin detect mode */
    Mcu_PmuSetWakeup1PinSensitive(wakeupctl->sensitive);

    /* set pin edge filter data */
    if (PMU_TRIGGER_MODE_EDGE == wakeupctl->sensitive) {
        /* switch pin filter */
        Mcu_PmuEnableWakeup0FilterBypass(wakeupctl->filterbypass);

        /* set pin edge filter data */
        if (PMU_FILTER_ENABLE == wakeupctl->filterbypass) {
            /* set pin filter edge */
            Mcu_PmuSetWakeup1FilterEdge(wakeupctl->edgetype);
            /* set pin filter timer */
            Mcu_PmuSetWakeup1FilterTimer(wakeupctl->filtercnt, wakeupctl->sampleinterval);
        } else {
            ;
        }
    } else {
        ;
    }

    /* set pin polarity */
    Mcu_PmuSetWakeup1PinPolarity(wakeupctl->polarity);

    /* enable wakeup1 pin */
    Mcu_PmuEnableWakeup1Pin(PMU_WAKEUP_SRC_ENABLE);
}

void Mcu_PmuEnableExtWakeupSrc(pmu_wakeup_src_enable_e enable)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + WAKEUP_CTRL);

    /* enable/disable external wakeup which is generate by ButtonControl pin */
    if (PMU_WAKEUP_SRC_ENABLE == enable) {
        /* enable */
        v |= BM_WAKEUP_CTRL_EXT_WAKEUP_EN;
    } else {
        /* disable */
        v &= ~BM_WAKEUP_CTRL_EXT_WAKEUP_EN;
    }

    writel(v, b + WAKEUP_CTRL);
}

void Mcu_PmuEnableIntWakeupSrc(pmu_wakeup_src_enable_e enable)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + WAKEUP_CTRL);

    /* enable/disable internal wakeup event which is generate by RTC periodic interrupt */
    if (PMU_WAKEUP_SRC_ENABLE == enable) {
        /* enable */
        v |= BM_WAKEUP_CTRL_INT_WAKEUP_EN;
    } else {
        /* disable */
        v &= ~BM_WAKEUP_CTRL_INT_WAKEUP_EN;
    }

    writel(v, b + WAKEUP_CTRL);
}

void Mcu_PmuPwrdown(void)
{
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + BC_CTRL_SET);

    /* Note: a rising-edge needed to trigger the power down process */
    v |= BM_BC_CTRL_SET_PWR_DWN_REQ_SOFT;
    writel(v, b + BC_CTRL_SET);
}

void Mcu_PmuResumeCb(void)
{
    /* Rising-edge needed to trigger the pwrdown. Here we clear pwrdown bit thus
     * SW don't have to wait one 32KHz cycle to wait the sync to 32K domain.
     */
    uint32 b = PMU_RBASE;
    uint32 v = readl(b + BC_CTRL_SET);
    v &= ~BM_BC_CTRL_SET_PWR_DWN_REQ_SOFT;
    writel(v, b + BC_CTRL_SET);
}

void Mcu_PmuDcdcEn(bool en)
{
    if (en) {
        rmw32(APB_PMU_CORE_BASE + BM_SW_OVRRIDE_OFFSET, 0U, 1U, 0U);
        rmw32(APB_PMU_CORE_BASE + BM_SW_OVRRIDE_OFFSET, 4U, 1U, 0U);
    } else {
        rmw32(APB_PMU_CORE_BASE + BM_SW_OVRRIDE_OFFSET, 0U, 1U, 1U);
        rmw32(APB_PMU_CORE_BASE + BM_SW_OVRRIDE_OFFSET, 4U, 1U, 1U);
    }

}

void Mcu_PmuLdoEn(bool en)
{
    if (en) {
        rmw32(APB_PMU_CORE_BASE + BM_SW_OVRRIDE_OFFSET, 2U, 1U, 0U);
        rmw32(APB_PMU_CORE_BASE + BM_SW_OVRRIDE_OFFSET, 6U, 1U, 0U);
    } else {
        rmw32(APB_PMU_CORE_BASE + BM_SW_OVRRIDE_OFFSET, 2U, 1U, 1U);
        rmw32(APB_PMU_CORE_BASE + BM_SW_OVRRIDE_OFFSET, 6U, 1U, 1U);
    }

}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif
