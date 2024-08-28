/** *****************************************************************************************************
 * SEMIDRIVE Copyright Statement                                                                        *
 * Copyright (c) SEMIDRIVE. All rights reserved                                                         *
 *                                                                                                      *
 * This software and all rights therein are owned by SEMIDRIVE, and are                                 *
 * protected by copyright law and other relevant laws, regulations and                                  *
 * protection. Without SEMIDRIVE's prior written consent and/or related rights,                         *
 * please do not use this software or any potion thereof in any form or by any                          *
 * means. You may not reproduce, modify or distribute this software except in                           *
 * compliance with the License. Unless required by applicable law or agreed to                          *
 * in writing, software distributed under the License is distributed on                                 *
 * an 'AS IS' basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.                         *
 *                                                                                                      *
 *******************************************************************************************************/
/** *****************************************************************************************************
 * \file     Mcu_PvtSens.c                                                                              *
 * \brief    AUTOSAR 4.3.1 MCAL Mcu Driver                                                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/02     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "RegHelper.h"
#include "Mcal.h"
#include "RegBase.h"
#include "Mcu_GeneralTypes.h"
#include "Mcu_PvtSens.h"
#include "Mcu.h"

/********************************************************************************************************
 *                                 Private Macro definition                                             *
 *******************************************************************************************************/
/* Length of PVT DOUT and Threshold register bits. */
#define PVT_THRESH_BITS (12U)

/* PVT registers */
#define PVT_CORE_REG_OFFSET (0x34U)
#define PVT_CORE_REGISTER(core, reg) (((uint32)(core)*PVT_CORE_REG_OFFSET) + (reg))

#define PVT_CTRL (0x0U)
#define PVT_CTRL_PDTSEN 1U
#define PVT_CTRL_PTSEL 4U
#define PVT_CTRL_HL_MODE_EN(core) (8U + ((uint32)(core)*2U))
#define PVT_CTRL_RF_MODE_EN(core) (9U + ((uint32)(core)*2U))

#define PVT_DOUT (0x4U)
#define PVT_DOUT_VALID 0U
#define PVT_DOUT_DOUT 1U

#define PVT_HYST_H(core) PVT_CORE_REGISTER(core, 0x8U)
#define PVT_HYST_H_THRESH_H 0U
#define PVT_HYST_H_THRESH_L 12U

#define PVT_HYST_L(core) PVT_CORE_REGISTER(core, 0xcU)
#define PVT_HYST_L_THRESH_H 0U
#define PVT_HYST_L_THRESH_L 12U

#define PVT_HYST_R(core) PVT_CORE_REGISTER(core, 0x10U)
#define PVT_HYST_R_ALARM 0U
#define PVT_HYST_R_HYST 12U

#define PVT_HYST_F(core) PVT_CORE_REGISTER(core, 0x14U)
#define PVT_HYST_F_ALARM 0U
#define PVT_HYST_F_HYST 12U

#define PVT_INT_EN(core) PVT_CORE_REGISTER(core, 0x30U)
#define PVT_INT_STATUS(core) PVT_CORE_REGISTER(core, 0x34U)
#define PVT_INT_CLR(core) PVT_CORE_REGISTER(core, 0x38U)

#define PVT_ALARM_INT(alarm) (uint32)(alarm)

#define PVT_BIT_SET(x, bit) ((0U != ((x) & ((uint32)1UL << (bit)))) ? 1U : 0U)

static void Mcu_Ip_PvtIrqHandler(uint8 controllerId);

#define PVT_ISR(id) \
ISR(PVT_Controller##id##IrqHandler)\
{\
    Mcu_Ip_PvtIrqHandler( id##U );\
}

PVT_ISR(1)
PVT_ISR(2)
PVT_ISR(3)
/********************************************************************************************************
 *                                  Global Constant Declarations                                        *
 *******************************************************************************************************/
#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"
static Mcu_PvtType Mcu_PvtSfDev =
{
    .base = APB_PT_SNS_SF_BASE,
};

#ifndef SEMIDRIVE_E3_LITE_SERIES
static Mcu_PvtType Mcu_PvtApDev =
{
    .base = APB_PT_SNS_AP_BASE,
};

/* PRQA S 3218 1*/
static boolean PvtApInitFlag = FALSE;
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/

#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"
/********************************************************************************************************
 *                                  Private Function Declarations                                       *
 *******************************************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

static inline Mcu_PvtCoreType *Mcu_Ip_PvtCore(Mcu_PvtType *devPtr,
        Mcu_PvtCoreIdType core)
{
    /* PRQA S 0311 1*/
    return (Mcu_PvtCoreType *) & (devPtr->core[core]);
}

/* Convert DOUT register value to Celsius. */
static inline float Mcu_Ip_PvtDoutToCelsius(uint32 dout)
{
    uint32 value = dout;
    value &= MCU_BIT_MASK(PVT_THRESH_BITS);
    return (306.76f * (float)value / (float)4096U) - 75.98f;
}

/* Convert Celsius to DOUT register value. */
static inline uint32 Mcu_Ip_PvtCelsiusToDout(float celsius)
{
    /* PRQA S 4395 1*/
    uint32 dout = (uint32)(((celsius + 75.98f) * 4096.0f) / 306.76f);
    return dout & MCU_BIT_MASK(PVT_THRESH_BITS);
}

/* PRQA S 3673 1 */
static boolean Mcu_Ip_PvtIsTempSensorRunning(Mcu_PvtType *devPtr)
{
    boolean ret;
    uint32 ctrl = readl(devPtr->base + PVT_CTRL);

    if ((0U == PVT_BIT_SET(ctrl, (uint32)PVT_CTRL_PDTSEN))
            && (0U == PVT_BIT_SET(ctrl, (uint32)PVT_CTRL_PTSEL)))
    {
        ret = TRUE;
    }
    else
    {
        ret = FALSE;
    }

    return ret;
}

/** Traceability       : SW_SM003 SW_SM004*/
static void Mcu_Ip_PvtIrqHandler(uint8 controllerId)
{
    uint8 core;
    Mcu_PvtType *devPtr;
    /* PRQA S 3678 1 */
    Mcu_PvtCoreType *corePtr;
    uint32 base;
    uint32 alarm;
    uint32 en, ent;
    uint32 status, statust;
    Std_ReturnType ret;
    boolean isRun;
    Mcu_PvtAlarmCbType alarmCallBack;

    if (controllerId < ((uint8)PVT_CORE_NR * 2U))
    {
        if (controllerId < (uint8)PVT_CORE_NR)
        {
            devPtr = &Mcu_PvtSfDev;
            core = controllerId;
        }

#ifndef SEMIDRIVE_E3_LITE_SERIES
        else
        {
            devPtr = &Mcu_PvtApDev;
            core = (controllerId - (uint8)PVT_CORE_NR);
        }

#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/
        corePtr = &(devPtr->core[core]);
        base = devPtr->base;

        en = readl(base + PVT_INT_EN(core));
        status = readl(base + PVT_INT_STATUS(core));

        ret = Mcu_EnterCheck(MCU_SID_INIT_PVT);
        isRun = Mcu_Ip_PvtIsTempSensorRunning(devPtr);

        if ((E_OK != ret) || (FALSE == isRun) || (0U == (en & status)))
        {
            RMWREG32(base + PVT_INT_CLR(core), PVT_ALARM_INT(0U), (uint32)PVT_ALARM_NR, 0xFU);
            RMWREG32(base + PVT_INT_CLR(core), PVT_ALARM_INT(0U), (uint32)PVT_ALARM_NR, 0U);
            (void)Mcu_Ip_PvtDeinit(devPtr);
        }
        else
        {
            /* Handle alarm IRQ, if it's enabled. */
            for (alarm = (uint32)PVT_HIGH_LEVEL_ALARM; alarm < (uint32)PVT_ALARM_NR; alarm++)
            {
                ent = PVT_BIT_SET(en, alarm);
                statust = PVT_BIT_SET(status, alarm);
                if ((1U == ent) && (1U == statust))
                {
                    alarmCallBack = corePtr->alarmCb;
                    if (alarmCallBack != NULL_PTR)
                    {
                        /* Call user alarm callback. */
                        /* PRQA S 4342 1*/
                        alarmCallBack(devPtr, (Mcu_PvtCoreIdType)core, (Mcu_PvtAlarmType)alarm, corePtr->cbArg);
                    } /* else not needed */

                    /*
                    * Try to clear interrupt status. Level interrupt status are
                    * cleared when INT_CLR bits are set, and DOUT has returned to
                    * normal range. Edge interrupt status are cleared when INT_CLR
                    * bits are set.
                    *
                    * Note that INT_CLR itself is not auto cleared, so we have to
                    * clear INT_CLR manually.
                    */
                    RMWREG32(base + PVT_INT_CLR(core), alarm, 1U, 1U);
                    RMWREG32(base + PVT_INT_CLR(core), alarm, 1U, 0U);
                } /* else not needed */
            }
        }
    }

    return;
}

static Std_ReturnType Mcu_Ip_PvtUpdateAlarmIrq(Mcu_PvtType *devPtr, Mcu_PvtCoreIdType core)
{
    /* PRQA S 3678 1 */
    Mcu_PvtCoreType *corePtr;
    uint32 base;
    Mcu_PvtAlarmType alarm;
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;

    if ((devPtr != NULL_PTR) && (core < PVT_CORE_NR))
    {
        base = devPtr->base;
        corePtr = Mcu_Ip_PvtCore(devPtr, core);

        if (corePtr != NULL_PTR)
        {
            /* Update High/Low mode bit in PVT_CTRL register, which controls
            * Temperature and Process High/Low modes.
            */
            if ((1U == PVT_BIT_SET(corePtr->alarmEnableMask, (uint32)PVT_HIGH_LEVEL_ALARM)) ||
                    (1U == PVT_BIT_SET(corePtr->alarmEnableMask, (uint32)PVT_LOW_LEVEL_ALARM)))
            {
                RMWREG32(base + PVT_CTRL, PVT_CTRL_HL_MODE_EN(core), 1U, 1U);
            }
            else
            {
                RMWREG32(base + PVT_CTRL, PVT_CTRL_HL_MODE_EN(core), 1U, 0U);
            }

            /* Enable alarm interrupt if necessary. */
            if (corePtr->alarmEnableMask != 0U)
            {
                /* PRQA S 4527 1*/
                for (alarm = PVT_HIGH_LEVEL_ALARM; alarm < PVT_ALARM_NR; alarm++)
                {
                    if ((1U == PVT_BIT_SET(corePtr->alarmEnableMask, (uint32)alarm)))
                    {
                        RMWREG32(base + PVT_INT_EN(core), PVT_ALARM_INT(alarm), 1U, 1U);
                    }
                    else
                    {
                        RMWREG32(base + PVT_INT_EN(core), PVT_ALARM_INT(alarm), 1U, 0U);
                    }
                }

            }

            errStatus = E_OK;
        } /* else not needed */
    } /* else not needed */

    return errStatus;
}

static Std_ReturnType Mcu_Ip_PvtUpdateAlarmMode(Mcu_PvtType *devPtr, Mcu_PvtCoreIdType core,
        Mcu_PvtAlarmType alarm, boolean enable)
{
    Mcu_PvtCoreType *corePtr;
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;

    if ((devPtr != NULL_PTR) && (core < PVT_CORE_NR))
    {
        corePtr = Mcu_Ip_PvtCore(devPtr, core);

        if (corePtr != NULL_PTR)
        {
            if (TRUE == enable)
            {
                corePtr->alarmEnableMask |= ((uint32)1U << (uint32)alarm);
            }
            else
            {
                corePtr->alarmEnableMask &= ~((uint32)1U << (uint32)alarm);
            }

            errStatus = Mcu_Ip_PvtUpdateAlarmIrq(devPtr, core);
        } /* else not needed */
    } /* else not needed */

    return errStatus;
}

static boolean
Mcu_Ip_PvtIsValidLevelAlarmConfig(const Mcu_PvtLevelAlarmConfigType *configPtr)
{

    boolean ret;

    if ((configPtr != NULL_PTR)
            && (Mcu_Ip_PvtCelsiusToDout(configPtr->threshLow) <= Mcu_Ip_PvtCelsiusToDout(
                    configPtr->threshHigh)))
    {
        ret = TRUE;
    }
    else
    {
        ret = FALSE;
    }

    return ret;
}

static Std_ReturnType Mcu_Ip_PvtEnableLevelAlarm(Mcu_PvtType *devPtr, Mcu_PvtCoreIdType core,
        Mcu_PvtAlarmType alarm,
        const Mcu_PvtLevelAlarmConfigType *configPtr,
        boolean enable)
{
    uint32 base;
    Std_ReturnType errStatus = E_OK;

    if ((devPtr != NULL_PTR) && (core < PVT_CORE_NR) && ((PVT_HIGH_LEVEL_ALARM == alarm)
            || (PVT_LOW_LEVEL_ALARM == alarm)))
    {
        base = devPtr->base;

        if (TRUE == enable)
        {
            if (FALSE == Mcu_Ip_PvtIsValidLevelAlarmConfig(configPtr))
            {
                errStatus = MCU_E_PARAM_CONFIG;
            }
            else
            {
                /* Update High/Low alarm thresholds. */
                if (PVT_HIGH_LEVEL_ALARM == alarm)
                {
                    RMWREG32(base + PVT_HYST_H(core), PVT_HYST_H_THRESH_H,
                             PVT_THRESH_BITS, Mcu_Ip_PvtCelsiusToDout(configPtr->threshHigh));
                    RMWREG32(base + PVT_HYST_H(core), PVT_HYST_H_THRESH_L,
                             PVT_THRESH_BITS, Mcu_Ip_PvtCelsiusToDout(configPtr->threshLow));
                }
                else
                {
                    /* PVT_LOW_LEVEL_ALARM */
                    RMWREG32(base + PVT_HYST_L(core), PVT_HYST_L_THRESH_H,
                             PVT_THRESH_BITS, Mcu_Ip_PvtCelsiusToDout(configPtr->threshHigh));
                    RMWREG32(base + PVT_HYST_L(core), PVT_HYST_L_THRESH_L,
                             PVT_THRESH_BITS, Mcu_Ip_PvtCelsiusToDout(configPtr->threshLow));
                }

            }
        } /* else not needed */

        if (E_OK == errStatus)
        {
            errStatus = Mcu_Ip_PvtUpdateAlarmMode(devPtr, core, alarm, enable);
        } /* else not needed */
    }
    else
    {
        errStatus = MCU_E_PARAM_POINTER;
    }

    return errStatus;
}

/** Traceability       : SW_SM006*/
static Std_ReturnType Mcu_Ip_PvtInit(Mcu_PvtType *devPtr)
{
    Std_ReturnType errStatus = E_OK;
    uint32 base;
    uint32 core;
    Mcu_PvtCoreType *corePtr;

    if (NULL_PTR == devPtr)
    {
        errStatus = MCU_E_PARAM_POINTER;
    }
    else
    {
        base = devPtr->base;

        for (core = (uint32)PVT_CORE0; core < (uint32)PVT_CORE_NR; core++)
        {
            /* PRQA S 4342 1*/
            corePtr = Mcu_Ip_PvtCore(devPtr, (Mcu_PvtCoreIdType)core);

            /* Disable all interrupts by default. */
            writel(0U, base + PVT_INT_EN(core));

            corePtr->alarmCb = NULL_PTR;
            corePtr->cbArg = NULL_PTR;
            corePtr->alarmEnableMask = 0U;
        }
    }

    return errStatus;
}

/* PRQA S 3673 2 */
/** Traceability       : SW_SM006*/
static Std_ReturnType Mcu_Ip_PvtStart(Mcu_PvtType *devPtr)
{
    Std_ReturnType errStatus = E_OK;
    uint32 base;

    if (NULL_PTR == devPtr)
    {
        errStatus = MCU_E_PARAM_POINTER;
    }
    else
    {
        base = devPtr->base;

        /* Disable T sensor */
        RMWREG32(base + PVT_CTRL, PVT_CTRL_PDTSEN, 1U, 1U);

        /* Select temperature sensor output. */
        RMWREG32(base + PVT_CTRL, PVT_CTRL_PTSEL, 1U, 0U);

        /* Enable T sensor. */
        RMWREG32(base + PVT_CTRL, PVT_CTRL_PDTSEN, 1U, 0U);
    }

    return errStatus;
}

/** Traceability       : SW_SM006*/
static Std_ReturnType Mcu_Ip_PvtRegisterAlarmCb(Mcu_PvtType *devPtr, Mcu_PvtCoreIdType core,
        Mcu_PvtAlarmCbType alarmCb, void *argPtr)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;
    Mcu_PvtCoreType *corePtr;

    if ((NULL_PTR != devPtr) && (core < PVT_CORE_NR))
    {
        corePtr = Mcu_Ip_PvtCore(devPtr, core);

        if (NULL_PTR != corePtr)
        {
            corePtr->alarmCb = alarmCb;
            corePtr->cbArg = argPtr;
            errStatus = Mcu_Ip_PvtUpdateAlarmIrq(devPtr, core);
        } /* else not needed */
    } /* else not needed */

    return errStatus;
}

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
/** Traceability       : SW_SM006*/
/*PRQA S 1505 1*/
Std_ReturnType Mcu_Ip_PvtEnableAlarm(Mcu_PvtType *devPtr, Mcu_PvtCoreIdType core,
                                     Mcu_PvtAlarmType alarm, const Mcu_PvtAlarmConfigType *configPtr)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;

    if ((devPtr != NULL_PTR) && (core < PVT_CORE_NR) && (configPtr != NULL_PTR))
    {
        if (FALSE == Mcu_Ip_PvtIsTempSensorRunning(devPtr))
        {
            errStatus = MCU_E_PARAM_CONFIG;
        }
        else
        {
            switch (alarm)
            {
            case PVT_HIGH_LEVEL_ALARM:
            case PVT_LOW_LEVEL_ALARM:
                errStatus = Mcu_Ip_PvtEnableLevelAlarm(devPtr, core, alarm, &configPtr->levelAlarm, TRUE);
                break;

            default:
                errStatus = MCU_E_PARAM_CONFIG;
                break;
            }
        }
    } /* else not needed */

    return errStatus;
}
Std_ReturnType Mcu_Ip_PvtDisableAlarm(Mcu_PvtType *devPtr, Mcu_PvtCoreIdType core,
                                      Mcu_PvtAlarmType alarm)
{
    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;

    if ((devPtr != NULL_PTR) && (core < PVT_CORE_NR))
    {

        switch (alarm)
        {
        case PVT_HIGH_LEVEL_ALARM:
        case PVT_LOW_LEVEL_ALARM:
            errStatus = Mcu_Ip_PvtEnableLevelAlarm(devPtr, core, alarm, NULL, FALSE);
            break;

        default:
            errStatus = MCU_E_PARAM_CONFIG;
            break;
        }
    } /* else not needed */

    return errStatus;
}
/*PRQA S 1505 1*/
Std_ReturnType Mcu_Ip_PvtDeinit(Mcu_PvtType *devPtr)
{
    Std_ReturnType errStatus = E_OK;
    uint32 base;
    uint32 core;
    Mcu_PvtCoreType *corePtr;

    if (NULL_PTR == devPtr)
    {
        errStatus = MCU_E_PARAM_POINTER;
    }
    else
    {
        base = devPtr->base;

        for (core = (uint32)PVT_CORE0; core < (uint32)PVT_CORE_NR; core++)
        {
            /* PRQA S 4342 1*/
            corePtr = Mcu_Ip_PvtCore(devPtr, (Mcu_PvtCoreIdType)core);

            /* Disable all interrupts. */
            writel(0U, base + PVT_INT_EN(core));

            corePtr->alarmCb = NULL_PTR;
            corePtr->cbArg = NULL_PTR;
            corePtr->alarmEnableMask = 0U;
        }
    }

    return errStatus;
}

/* PRQA S 3673 1 */
Std_ReturnType Mcu_Ip_PvtStop(Mcu_PvtType *devPtr)
{
    Std_ReturnType errStatus = E_OK;

    if (NULL_PTR == devPtr)
    {
        errStatus = MCU_E_PARAM_POINTER;
    }
    else
    {
        /* Disable T sensor */
        RMWREG32(devPtr->base + PVT_CTRL, PVT_CTRL_PDTSEN, 1, 1);
    }

    return errStatus;
}

Std_ReturnType Mcu_Ip_PvtGet(Mcu_PvtType *devPtr, float *temperaturePtr)
{
    Std_ReturnType errStatus = E_OK;
    uint32 dout;

    if ((NULL_PTR == devPtr) || (NULL_PTR == temperaturePtr))
    {
        errStatus = MCU_E_PARAM_POINTER;
    }
    else
    {
        if (FALSE == Mcu_Ip_PvtIsTempSensorRunning(devPtr))
        {
            errStatus = MCU_E_PARAM_CONFIG;
        }
        else
        {
            /*
            * Read temperaturePtr data. PVT_DOUT is automatically updated every 280ms
            * after Mcu_Ip_PvtStart() is called.
            */
            dout = (readl(devPtr->base + PVT_DOUT) >> PVT_DOUT_DOUT) &
                   MCU_BIT_MASK(PVT_THRESH_BITS);

            /* Convert data to Celsius. */
            *temperaturePtr = Mcu_Ip_PvtDoutToCelsius(dout);
        }
    }

    return errStatus;
}

/**
* \brief   get SF PVT sensor device.
* \return  SF PVT sensor device
*/
Mcu_PvtType *Mcu_Ip_PvtGetSfDevice(void)
{
    return &Mcu_PvtSfDev;
}

/**
* \brief   get AP PVT sensor device.
* \return  AP PVT sensor device
*/
#ifndef SEMIDRIVE_E3_LITE_SERIES
Mcu_PvtType *Mcu_Ip_PvtGetApDevice(void)
{
    return &Mcu_PvtApDev;
}
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/

/* PRQA S 3673 1 */
Std_ReturnType Mcu_Ip_PvtClearStatus(Mcu_PvtType *devPtr, Mcu_PvtCoreIdType core,
                                     Mcu_PvtAlarmType alarm)
{
    Std_ReturnType errStatus = E_OK;

    if (NULL_PTR == devPtr)
    {
        errStatus = MCU_E_PARAM_POINTER;
    }
    else
    {
        RMWREG32(devPtr->base + PVT_INT_CLR(core), PVT_ALARM_INT(alarm), 1U, 1U);
        RMWREG32(devPtr->base + PVT_INT_CLR(core), PVT_ALARM_INT(alarm), 1U, 0U);
    }

    return errStatus;
}
/**
* \brief   Set Temperature monitoring of PVT sensor.
* \details Configure the temperature alarm type and threshold on EB;
1 Temperature highest thresholds alarm configuration:
            - After exceeding highest thresholds trigger a system reset.
2 Temperature high alarm configuration:
            - After exceeding thresholds, a warning is triggered,User alarm settings can be made in the function "Mcu_Ip_PvtAlarmCb".
3 Temperature rise alarm configuration:
            - After exceeding T1 degrees, the hardware starts the high temperature alarm monitoring,
            - After exceeding T2 degrees, a temperature rise warning is triggered,User alarm settings can be made in the function "Mcu_Ip_PvtAlarmCb".
4 Temperature low alarm configuration:
            - After below thresholds, a warning is triggered,User alarm settings can be made in the function "Mcu_Ip_PvtAlarmCb".
5 Temperature fall alarm configuration:<p/>
            - After below T1 degrees, the hardware starts the low temperature alarm monitoring,
            - After below T2 degrees, a temperature fall warning is triggered,User alarm settings can be made in the function "Mcu_Ip_PvtAlarmCb".
            Note: Choose one of the four 2)-5)
                  Mcu_PvtApDev is disabled by default,Configure the Mcu_PvtApDev enable on EB.
*/

Std_ReturnType Mcu_Ip_PvtPrepare(void)
{
    Std_ReturnType errStatus;
    Mcu_PvtAlarmConfigType highestLevelCfg;
    Mcu_PvtAlarmConfigType levelCfg;
#ifndef SEMIDRIVE_E3_LITE_SERIES
#if (STD_ON == MCU_PVT_AP_ENABLE)
    Mcu_PvtAlarmConfigType levelCfgAp;
#endif
#endif

    highestLevelCfg.levelAlarm.threshLow = (Mcu_PvtCfg.highest - 0.1f);
    highestLevelCfg.levelAlarm.threshHigh = Mcu_PvtCfg.highest;

    levelCfg.levelAlarm.threshLow = (Mcu_PvtCfg.T1 - 0.1f);
    levelCfg.levelAlarm.threshHigh = Mcu_PvtCfg.T1;

    errStatus = Mcu_Ip_PvtInit(&Mcu_PvtSfDev);

    /*use core0 as reset when temp over highest*/
    /*PRQA S 2991,2995 2*/
    CALL_RET_CHECK(errStatus, Mcu_Ip_PvtRegisterAlarmCb(&Mcu_PvtSfDev, PVT_CORE0,
                   Mcu_PvtCfg.pvtNotificationPtr, NULL_PTR));

    /*use core1 as alarm when temp over threshold*/
    /*PRQA S 2991,2995 2*/
    CALL_RET_CHECK(errStatus, Mcu_Ip_PvtRegisterAlarmCb(&Mcu_PvtSfDev, PVT_CORE1,
                   Mcu_PvtCfg.pvtNotificationPtr, NULL_PTR));
    /*PRQA S 2991,2995 1*/
    CALL_RET_CHECK(errStatus, Mcu_Ip_PvtStart(&Mcu_PvtSfDev));
    /*PRQA S 2991,2995 2*/
    CALL_RET_CHECK(errStatus, Mcu_Ip_PvtEnableAlarm(&Mcu_PvtSfDev, PVT_CORE0, PVT_HIGH_LEVEL_ALARM,
                   &highestLevelCfg));
    /*PRQA S 2991,2995 2*/
    CALL_RET_CHECK(errStatus, Mcu_Ip_PvtEnableAlarm(&Mcu_PvtSfDev, PVT_CORE1, Mcu_PvtCfg.type,
                   &levelCfg));

#ifndef SEMIDRIVE_E3_LITE_SERIES
    /*add Mcu_PvtApDev enable configPtr in EB, and Mcu_PvtApDev type/threshold can configPtr*/
#if (STD_ON == MCU_PVT_AP_ENABLE)

    levelCfgAp.levelAlarm.threshLow = (Mcu_PvtCfg_AP.T1 - 0.1f);
    levelCfgAp.levelAlarm.threshHigh = Mcu_PvtCfg_AP.T1;

    if (FALSE == PvtApInitFlag)
    {
        /*PRQA S 2991,2995 1*/
        CALL_RET_CHECK(errStatus, Mcu_Ip_PvtInit(&Mcu_PvtApDev));
        PvtApInitFlag = TRUE;
    } /** else is not needed*/

    /*PRQA S 2991,2995 2*/
    CALL_RET_CHECK(errStatus, Mcu_Ip_PvtRegisterAlarmCb(&Mcu_PvtApDev, PVT_CORE0,
                   Mcu_PvtCfg_AP.pvtNotificationPtr, NULL_PTR));
    /*PRQA S 2991,2995 1*/
    CALL_RET_CHECK(errStatus, Mcu_Ip_PvtStart(&Mcu_PvtApDev));

    /*use core1 as alarm when temp over threshold*/
    /*PRQA S 2991,2995 2*/
    CALL_RET_CHECK(errStatus, Mcu_Ip_PvtEnableAlarm(&Mcu_PvtApDev, PVT_CORE0, Mcu_PvtCfg_AP.type,
                   &levelCfgAp));

#endif
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/
    return errStatus;
}
#ifndef SEMIDRIVE_E3_LITE_SERIES
Std_ReturnType Mcu_Ip_PvtForVdInit(const Mcu_PvtForVdType *vDconfigPtr)
{
    Std_ReturnType errStatus = E_OK;

    if (NULL_PTR == vDconfigPtr)
    {
        errStatus = MCU_E_PARAM_POINTER;
    }
    else
    {
        if (FALSE == PvtApInitFlag)
        {
            errStatus = Mcu_Ip_PvtInit(&Mcu_PvtApDev);
            PvtApInitFlag = TRUE;
        } /** else is not needed*/
        /*PRQA S 2991,2995 2*/
        CALL_RET_CHECK(errStatus, Mcu_Ip_PvtRegisterAlarmCb(&Mcu_PvtApDev, PVT_CORE1,
                       vDconfigPtr->pvtNotificationPtr, vDconfigPtr->arg));
        /*PRQA S 2991,2995 2*/
        CALL_RET_CHECK(errStatus, Mcu_Ip_PvtStart(&Mcu_PvtApDev));

        /*use core1 as vd alarm when temp over threshold*/
        /*PRQA S 2991,2995 2*/
        CALL_RET_CHECK(errStatus, Mcu_Ip_PvtEnableAlarm(&Mcu_PvtApDev, PVT_CORE1, PVT_HIGH_LEVEL_ALARM,
                       &(vDconfigPtr->levelCfgHigh)));
        /*PRQA S 2991,2995 2*/
        CALL_RET_CHECK(errStatus, Mcu_Ip_PvtEnableAlarm(&Mcu_PvtApDev, PVT_CORE1, PVT_LOW_LEVEL_ALARM,
                       &(vDconfigPtr->levelCfgLow)));
    }

    return errStatus;
}
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif
/* End of file */
