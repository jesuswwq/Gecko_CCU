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
 * \file     Mcu_DcdcLdo.c                                                                              *
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
#include "RegBase.h"
#include "Mcu_Delay.h"
#include "Mcu_GeneralTypes.h"
#include "Mcu_Dcdc.h"
#include "Mcu_Ldo.h"
/********************************************************************************************************
 *                                 Private Macro definition                                             *
 *******************************************************************************************************/
#define MCU_DCDC_VOUT_MAX                   (950U)
#define MCU_DCDC_VOUT_MIN                   (640U)
#define MCU_DCDC_VOUT_NORMAL                (800U)
#define MCU_DCDC_VOUT_STEP                  (10U)
#define MCU_LDO_VOUT_RATIO2_MAX             (1910U)
#define MCU_LDO_VOUT_RATIO2_MIN             (640U)
#define MCU_LDO_VOUT_RATIO4_MAX             (6360U)
#define MCU_LDO_VOUT_RATIO4_MIN             (1280U)
#define MCU_LDO_VOUT_RATIO2_STEP            (5U)
#define MCU_LDO_VOUT_RATIO4_STEP            (10U)
#define MCU_LDO_VOUT_BASE                   (320U)

/*fuse map macro*/
#define MCU_FUSEMAP_DCDC_LDO                              (0x1040U)
#define MCU_FUSEMAP_DCDC_VOUT_0P8_OFFSET                  (0x5U)
#define MCU_FUSEMAP_DCDC_VOUT_0P8_OFFSET_MASK             (0x7U)
#define MCU_FUSEMAP_DCDC_VOUT_0P8_EXTRA_OFFSET            (0x8U)
#define MCU_FUSEMAP_DCDC_VOUT_0P8_OFFSET_EXTRA_MASK       (0x3U)
#define MCU_FUSEMAP_LDO_VOUT_0P8_OFFSET                   (0x10U)
#define MCU_FUSEMAP_LDO_VOUT_0P8_OFFSET_MASK              (0x7U)
#define MCU_FUSEMAP_LDO_VOUT_0P8_EXTRA_OFFSET             (0x18U)
#define MCU_FUSEMAP_LDO_VOUT_0P8_OFFSET_EXTRA_MASK        (0x3U)
#define MCU_FUSEMAP_LDO_VOUT_1P8_OFFSET                   (0x14U)
#define MCU_FUSEMAP_LDO_VOUT_1P8_OFFSET_MASK              (0x7U)
#define MCU_FUSEMAP_LDO_VOUT_1P8_EXTRA_OFFSET             (0x1AU)
#define MCU_FUSEMAP_LDO_VOUT_1P8_OFFSET_EXTRA_MASK        (0x3U)

/********************************************************************************************************
 *                                  Private Function Declarations                                       *
 *******************************************************************************************************/
static uint8 Mcu_Ip_DcdcExtraOffset(boolean *offsetDirectionPtr)
{
    uint32 regValue;
    uint8 extraOffset;

    regValue = readl(APB_EFUSEC_BASE + MCU_FUSEMAP_DCDC_LDO);

    if ((uint8)((regValue >> MCU_FUSEMAP_DCDC_VOUT_0P8_OFFSET) & MCU_FUSEMAP_DCDC_VOUT_0P8_OFFSET_MASK)
            <= 4U)
    {
        *offsetDirectionPtr = TRUE;
    }
    else
    {
        *offsetDirectionPtr = FALSE;
    }

    extraOffset = (uint8)((regValue >> MCU_FUSEMAP_DCDC_VOUT_0P8_EXTRA_OFFSET) &
                          MCU_FUSEMAP_DCDC_VOUT_0P8_OFFSET_EXTRA_MASK);

    return extraOffset;
}

#ifndef SEMIDRIVE_E3_LITE_SERIES
static uint8 Mcu_Ip_LdoExtraOffset(boolean *offsetDirectionPtr)
{
    uint32 regValue;
    uint8 ldoMode;
    uint8 extraOffset;

    regValue = readl(APB_LDO_DIG_BASE + LDO_THRE_SEL_OFF);
    ldoMode = (uint8)((regValue & BM_LDO_THRE_SEL_LDO_MODE) >> BO_LDO_THRE_SEL_LDO_MODE);
    regValue = readl(APB_EFUSEC_BASE + MCU_FUSEMAP_DCDC_LDO);

    if (1U == ldoMode)
    {
        if ((uint8)((regValue >> MCU_FUSEMAP_LDO_VOUT_1P8_OFFSET) & MCU_FUSEMAP_LDO_VOUT_1P8_OFFSET_MASK) <=
                4U)
        {
            *offsetDirectionPtr = TRUE;
        }
        else
        {
            *offsetDirectionPtr = FALSE;
        }

        extraOffset = (uint8)((regValue >> MCU_FUSEMAP_LDO_VOUT_1P8_EXTRA_OFFSET) &
                              MCU_FUSEMAP_LDO_VOUT_1P8_OFFSET_EXTRA_MASK);
    }
    else
    {
        if ((uint8)((regValue >> MCU_FUSEMAP_LDO_VOUT_0P8_OFFSET) & MCU_FUSEMAP_LDO_VOUT_0P8_OFFSET_MASK) <=
                4U)
        {
            *offsetDirectionPtr = TRUE;
        }
        else
        {
            *offsetDirectionPtr = FALSE;
        }

        extraOffset = (uint8)((regValue >> MCU_FUSEMAP_LDO_VOUT_0P8_EXTRA_OFFSET)&
                              MCU_FUSEMAP_LDO_VOUT_0P8_OFFSET_EXTRA_MASK);
    }

    return extraOffset;
}
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES */

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

/** Traceability       : SW_SM006*/
Std_ReturnType Mcu_Ip_DcdcFaultDetect(const Dcdc_OvUvCfgType *dcdcCfgPtr)
{

    Std_ReturnType errStatus = MCU_E_PARAM_POINTER;

    if (NULL_PTR != dcdcCfgPtr)
    {
        /*set dcdc vout*/
        errStatus = Mcu_Ip_DcdcSetVout(dcdcCfgPtr->vout);

        if (E_OK == errStatus)
        {
            /*hp mod cfg1 set oc*/
            REG_RMW32(APB_DCDC1_BASE + HP_MOD_CFG1_OFF, BO_HP_MOD_CFG1_DCDC_REG_4, 2U,
                      dcdcCfgPtr->ocDetectThreshold);
            /*hp mod cfg1 set uv*/
            REG_RMW32(APB_DCDC1_BASE + HP_MOD_CFG1_OFF, 10U, 2U, dcdcCfgPtr->uvDetectThreshold);
            /*hp mod cfg1 set ov*/
            REG_RMW32(APB_DCDC1_BASE + HP_MOD_CFG1_OFF, BO_HP_MOD_CFG1_DCDC_REG_5, 2U,
                      dcdcCfgPtr->ovDetectThreshold);

            /*clear sta*/
            REG_RMW32(APB_DCDC1_BASE + FUNC_STAT_CLR_OFF, BO_FUNC_STAT_CLR_IDDQ_ERR, 11U, dcdcCfgPtr->intVal);

            /*analog need delay to give right sta status*/
            errStatus = Mcu_udelay(300U);

            if (TRUE == dcdcCfgPtr->intEn)
            {
                /*func stat en*/
                REG_RMW32(APB_DCDC1_BASE + FUNC_STAT_EN_OFF, BO_FUNC_STAT_EN_IDDQ_ERR, 11U, dcdcCfgPtr->intVal);
            } /* else not needed */
        } /* else not needed */
    } /* else not needed */

    return errStatus;
}

/*PRQA S 1505 1*/
Std_ReturnType Mcu_Ip_DcdcSetVout(uint32 mv)
{
    uint32 dcdcReg = 0U;
    uint32 diff;
    Std_ReturnType errStatus = E_OK;
    uint32 vol = mv;
    uint8 extraOffset;
    boolean direction;

    if ((vol > MCU_DCDC_VOUT_MAX) || (vol < MCU_DCDC_VOUT_MIN))
    {
        errStatus = MCU_E_PARAM_CONFIG;
    }
    else
    {
        extraOffset = Mcu_Ip_DcdcExtraOffset(&direction);

        if (vol < MCU_DCDC_VOUT_NORMAL)
        {
            dcdcReg |= 0x01U << 4U;

            if (vol > (MCU_DCDC_VOUT_NORMAL - MCU_DCDC_VOUT_STEP))
            {
                vol = (MCU_DCDC_VOUT_NORMAL - MCU_DCDC_VOUT_STEP);
            } /* else not needed */

            diff = (MCU_DCDC_VOUT_NORMAL - MCU_DCDC_VOUT_STEP) - vol;

            dcdcReg = dcdcReg | ((diff / MCU_DCDC_VOUT_STEP) & 0xfU);

            /*dcdc manual trim*/
            if (FALSE == direction)
            {
                if ((dcdcReg + extraOffset) >= 0x1FU)
                {
                    dcdcReg = 0x1FU;
                }
                else
                {
                    dcdcReg = dcdcReg + extraOffset;
                }
            }
            else
            {
                if ((dcdcReg - extraOffset) >= 0x10U)
                {
                    dcdcReg = dcdcReg - extraOffset;
                }
                else
                {
                    dcdcReg = (0xFU - (dcdcReg - extraOffset));
                }
            }

        }
        else
        {
            diff = vol - MCU_DCDC_VOUT_NORMAL;

            dcdcReg = ((diff / MCU_DCDC_VOUT_STEP) & 0xfU);

            /*dcdc manual trim*/
            if (TRUE == direction)
            {
                if ((dcdcReg + extraOffset) >= 0xfU)
                {
                    dcdcReg = 0xfU;
                }
                else
                {
                    dcdcReg = dcdcReg + extraOffset;
                }
            }
            else
            {

                if (dcdcReg < extraOffset)
                {
                    dcdcReg = (extraOffset - dcdcReg - 1U);
                    dcdcReg |= 0x01U << 4U;
                }
                else
                {
                    dcdcReg = dcdcReg - extraOffset;
                }
            }

        }

        RMWREG32(APB_DCDC1_BASE + HP_MOD_CFG0_OFF, BO_HP_MOD_CFG0_DCDC_REG_1, 5U, dcdcReg);
        RMWREG32(APB_DCDC1_BASE + LP_MOD_CFG0_OFF, BO_LP_MOD_CFG0_DCDC_REG_1, 5U, dcdcReg);
    }

    return errStatus;
}

#ifndef SEMIDRIVE_E3_LITE_SERIES

Std_ReturnType Mcu_Ip_LdoSetVout(uint32 mv)
{
    uint32 ldoReg;
    uint32 ratio;
    boolean direction;
    uint8 extraOffset;

    Std_ReturnType errStatus = E_OK;

    if ((mv > MCU_LDO_VOUT_RATIO2_MAX) && (mv <= MCU_LDO_VOUT_RATIO4_MAX))
    {
        ratio = 1U;
        ldoReg = ((mv / 4U) - MCU_LDO_VOUT_BASE) / MCU_LDO_VOUT_RATIO4_STEP;
    }
    else if ((mv <= MCU_LDO_VOUT_RATIO2_MAX) && (mv >= MCU_LDO_VOUT_RATIO2_MIN))
    {
        ratio = 0U;
        ldoReg = ((mv / 2U) - MCU_LDO_VOUT_BASE) / MCU_LDO_VOUT_RATIO2_STEP;
    }
    else
    {
        errStatus = MCU_E_PARAM_CONFIG;
    }

    if (E_OK == errStatus)
    {
        /*ldo manual trim*/
        extraOffset = Mcu_Ip_LdoExtraOffset(&direction);

        if (TRUE == direction)
        {
            ldoReg += extraOffset;
        }
        else
        {
            ldoReg -= extraOffset;
        }

        ldoReg |= ratio << 23U;

        RMWREG32(APB_LDO_DIG_BASE + LDO_HP_MODE_CFG_OFF, BO_LDO_HP_MODE_CFG_VOLT_SEL, 8U, ldoReg);
        RMWREG32(APB_LDO_DIG_BASE + LDO_LP_MODE_CFG_OFF, BO_LDO_LP_MODE_CFG_VOLT_SEL, 8U, ldoReg);
        RMWREG32(APB_LDO_DIG_BASE + LDO_THRE_SEL_OFF, BO_LDO_THRE_SEL_EN, 1U, 1U);
    } /* else not needed */

    return errStatus;
}
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/

void Mcu_Ip_DcdcModeSet(void)
{
    rmw32(APB_DCDC1_BASE + HP_MOD_CFG0_OFF, BO_HP_MOD_CFG0_DCDC_REG_3, 2U, 0x3U);
    rmw32(APB_DCDC1_BASE + LP_MOD_CFG0_OFF, BO_LP_MOD_CFG0_DCDC_REG_3, 2U, 0x3U);
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif
/* End of file */
