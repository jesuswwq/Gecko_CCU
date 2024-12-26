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
 * \file     Mcu_Rstgen.c                                                                               *
 * \brief    AUTOSAR 4.3.1 MCAL Mcu Driver                                                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/02     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "RegHelper.h"
#include "Mcu_GeneralTypes.h"
#include "Mcu_Rstgen.h"

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

/**
 * \brief e3 rstgen core control
 * Reset core processor.
 *
 * \param[in] base e3 rstgen address
 * \param[in] coreIdx core index
 * \param[in] en run mode bit
 */
/** Traceability       : SW_SM005*/
Std_ReturnType Mcu_Ip_RstgenLldCoreControl(uint32 base, uint32 coreIdx, boolean en)
{
    uint32 coreRstEn = base + CORE_RESET_RS_OFF(coreIdx);
    uint32 coreSwRst = base + CORE_RESET_CONTROL_OFF(coreIdx);
    Std_ReturnType errStatus = E_OK;
    uint32 value = (readl(coreRstEn) & ((uint32)0x1U << CORE_RESET_RS_LOCK));

    /* Check the reset lock bit */
    if (0U != value)
    {
        errStatus = MCU_E_REGLOCKED;
    }
    else
    {
        /* Set core sleep/hib mode. */
        RMWREG32(coreSwRst, CORE_RESET_CONTROL_HIB_MODE, 1, en);
        RMWREG32(coreSwRst, CORE_RESET_CONTROL_SLP_MODE, 1, en);

        /* Check core SW reset status */
        if (en != ((readl(coreSwRst) & ((uint32)0x1U << CORE_RESET_CONTROL_RSTA)) >>
                   CORE_RESET_CONTROL_RSTA))
        {
            /* Set core run mode. */
            RMWREG32(coreSwRst, CORE_RESET_CONTROL_RUN_MODE, 1U, en);

            /* Wait reset done. */
            if (FALSE == Mcu_Ip_WaitForBitTimes(coreSwRst, CORE_RESET_CONTROL_RSTA,
                                                en, RSTGEN_POLLs))
            {
                errStatus = MCU_E_TIMEOUT;
            } /* else not needed */

        } /* else not needed */
    }

    return errStatus;
}

/**
 * \brief e3 rstgen core reset
 * Reset core processor.
 *
 * \param[in] base e3 rstgen address
 * \param[in] coreIdx core index
 */
/** Traceability       : SW_SM005*/
Std_ReturnType Mcu_Ip_RstgenLldCoreReset(uint32 base, uint32 coreIdx)
{
    uint32 coreRst = base + CORE_RESET_CONTROL_OFF(coreIdx);
    Std_ReturnType errStatus = E_OK;

    uint32 val = readl(coreRst);
    uint32 status = (val & ((uint32)1U << CORE_RESET_CONTROL_RSTA));

    if (0U != status)
    {
        /* Auto clear reset when the core is already running */
        writel(val | ((uint32)1U << CORE_RESET_CONTROL_AUTO_CLR_RST_B), coreRst);

        /* Trigger auto clear reset */
        if (FALSE == Mcu_Ip_WaitForBitTimes(coreRst, CORE_RESET_CONTROL_AUTO_CLR_RST_B,
                                            0U, RSTGEN_POLLs))
        {
            errStatus = MCU_E_TIMEOUT;
        } /* else not needed */
    }
    else
    {
        /* Set running mode when the core is off, and set core sleep/hib mode at the same time*/
        writel(val | ((uint32)7U << CORE_RESET_CONTROL_RUN_MODE), coreRst);

        /* Trigger real time reset status */
        if (FALSE == Mcu_Ip_WaitForBitTimes(coreRst, CORE_RESET_CONTROL_RSTA,
                                            1U, RSTGEN_POLLs))
        {
            errStatus = MCU_E_TIMEOUT;
        } /* else not needed */
    }

    return errStatus;
}

/**
 * \brief e3 rstgen module control
 * Reset IP module.
 *
 * \param[in] base e3 rstgen address
 * \param[in] moduleIdx module index
 * \param[in] en 0:module off, 1:module on
 */
/** Traceability       : SW_SM005*/
Std_ReturnType Mcu_Ip_RstgenLldModuleControl(uint32 base, uint32 moduleIdx, boolean en)
{
    uint32 moduleRst = base + MODULE_RESET_CONTROL_OFF(moduleIdx);
    uint32 val = readl(moduleRst);
    Std_ReturnType errStatus = E_OK;

    if (TRUE == en)
    {
        val |= (uint32)1U << MODULE_RESET_CONTROL_HIB_MODE;
        val |= (uint32)1U << MODULE_RESET_CONTROL_SLP_MODE;
        val |= (uint32)1U << MODULE_RESET_CONTROL_RUN_MODE;
    }
    else
    {
        val &= (uint32)(~((uint32)1U << MODULE_RESET_CONTROL_RUN_MODE));
        val &= (uint32)(~((uint32)1U << MODULE_RESET_CONTROL_HIB_MODE));
        val &= (uint32)(~((uint32)1U << MODULE_RESET_CONTROL_SLP_MODE));
    }

    writel(val, moduleRst);

    if (FALSE == Mcu_Ip_WaitForBitTimes(moduleRst, MODULE_RESET_CONTROL_RSTA,
                                        en, RSTGEN_POLLs))
    {
        errStatus = MCU_E_TIMEOUT;
    } /* else not needed */

    return errStatus;
}

/**
 * \brief e3 rstgen mission control
 *
 * \param[in] base e3 rstgen address
 * \param[in] missionIdx mission index
 * \param[in] en 0:misson off, 1:misson on
 */
/** Traceability       : SW_SM005*/
Std_ReturnType Mcu_Ip_RstgenLldMissionControl(uint32 base, uint32 missionIdx, boolean en)
{
    uint32 missionRst = base + MISSION_RESET_CONTROL_OFF(missionIdx);
    Std_ReturnType errStatus = E_OK;

    uint32 val = readl(missionRst);

    if (TRUE == en)
    {
        val |= (uint32)1U << MISSION_RESET_CONTROL_HIB_MODE;
        val |= (uint32)1U << MISSION_RESET_CONTROL_SLP_MODE;
        val |= (uint32)1U << MISSION_RESET_CONTROL_RUN_MODE;
    }
    else
    {
        val &= (uint32)(~((uint32)1U << MISSION_RESET_CONTROL_HIB_MODE));
        val &= (uint32)(~((uint32)1U << MISSION_RESET_CONTROL_SLP_MODE));
        val &= (uint32)(~((uint32)1U << MISSION_RESET_CONTROL_RUN_MODE));
    }

    writel(val, missionRst);

    if (FALSE == Mcu_Ip_WaitForBitTimes(missionRst, MISSION_RESET_CONTROL_RSTA,
                                        en, RSTGEN_POLLs))
    {
        errStatus = MCU_E_TIMEOUT;
    } /* else not needed */

    return errStatus;
}

/**
 * \brief
 *
 * \param[in] sf_base e3 rstgen sf domain address
 * \param[in] ap_base e3 rstgen ap domain address
 */
void Mcu_Ip_RstgenLldGlobalReset(uint32 sfBase)
{
    RMWREG32(sfBase + GLOBAL_RESET_CONTROL_OFF, GLOBAL_RESET_CONTROL_RST_REQ_EN, 1U, 1U);

    RMWREG32(sfBase + GLOBAL_RESET_CONTROL_OFF, GLOBAL_RESET_CONTROL_SW_GLB_RST_EN, 1U, 1U);

    RMWREG32(sfBase + GLOBAL_RESET_CONTROL_OFF, GLOBAL_RESET_CONTROL_SW_GLB_RST, 1U, 1U);
}

/**
 * \brief e3 rstgen get core reset status
 *
 * \param[in] base e3 rstgen address
 * \param[in] coreIdx core index
 * \return 1, the core reset has be released.
 *         0, the core reset hasn't be released.
 */
boolean Mcu_Ip_RstgenLldGetCoreResetStatus(uint32 base, uint32 coreIdx)
{
    boolean isRelease;
    uint32 coreRst = base + CORE_RESET_CONTROL_OFF(coreIdx);

    if (((uint32)0x1U << CORE_RESET_CONTROL_RSTA) == (readl(coreRst) & ((uint32)0x1U <<
            CORE_RESET_CONTROL_RSTA)))
    {
        isRelease = TRUE;
    }
    else
    {
        isRelease = FALSE;
    }

    return isRelease;
}

/**
 * \brief e3 rstgen get module reset status
 *
 * \param[in] base e3 rstgen address
 * \param[in] moduleIdx module index
 * \return 1, the module reset has be released.
 *         0, the module reset hasn't be released.
 */
boolean Mcu_Ip_RstgenLldGetModuleResetStatus(uint32 base, uint32 moduleIdx)
{
    boolean isRelease;
    uint32 moduleRst = base + MODULE_RESET_CONTROL_OFF(moduleIdx);

    /* RSTGEN_MODULE_RST_STA, 0 = reset, 1 = release. */
    if (((uint32)0x1U << MODULE_RESET_CONTROL_RSTA) == (readl(moduleRst) & ((
                uint32)0x1U << MODULE_RESET_CONTROL_RSTA)))
    {
        isRelease = TRUE;
    }
    else
    {
        isRelease = FALSE;
    }

    return isRelease;
}

/**
 * \brief e3 rstgen get mission reset status
 *
 * \param[in] base e3 rstgen address
 * \param[in] missionIdx mission index
 * \return 1, the mission reset has be released.
 *         0, the mission reset hasn't be released.
 */
boolean Mcu_Ip_RstgenLldGetMissionResetStatus(uint32 base, uint32 missionIdx)
{
    boolean isRelease;
    uint32 missionRst = base + MISSION_RESET_CONTROL_OFF(missionIdx);

    /* RSTGEN_MODULE_RST_STA, 0 = reset, 1 = release. */
    if (((uint32)0x1U << MISSION_RESET_CONTROL_RSTA) == (readl(missionRst) & ((
                uint32)0x1U << MISSION_RESET_CONTROL_RSTA)))
    {
        isRelease = TRUE;
    }
    else
    {
        isRelease = FALSE;
    }

    return isRelease;
}

/**
 * \brief rstgen get general reg value
 *
 * \param[in] base e3 rstgen address
 * \param[in] regIdx reg index
 * \return reg value
 */
uint32 Mcu_Ip_RstgenLldReadGeneralReg(uint32 base, uint32 regIdx)
{
    return readl(base + GENERAL_REG_OFF(regIdx));
}

/**
 * \brief e3 rstgen get general reg value
 *
 * \param[in] base e3 rstgen address
 * \param[in] regIdx reg index
 * \param[in] val write value
 * \return void
 */
void Mcu_Ip_RstgenLldWriteGeneralReg(uint32 base, uint32 regIdx, uint32 val)
{
    writel(val, base + GENERAL_REG_OFF(regIdx));
}



void Mcu_Ip_RstgenRgGlbResetEn(uint32 base, uint32 msk)
{
    uint32 v = readl(base + GLOBAL_RESET_CONTROL_OFF);
    v |= msk;
    writel(v, base + GLOBAL_RESET_CONTROL_OFF);
}

Mcu_RawResetType Mcu_Ip_GetResetRawValue(uint32 base)
{
    Mcu_RawResetType value = readl(base + GLOBAL_RESET_STA_OFF);
    return value;
}
/*------------------------------------------bihu change code ---------------------------------------------------------*/
uint8 Mcu_Ip_GetResetRawValue_bihuchange(uint32 base)
{
    uint8 value = readb(base);
    return value;
}
uint8 Mcu_Ip_GetResetReason_bihuchange(uint32 base)
{
    uint8 value = (uint8)Mcu_Ip_GetResetRawValue_bihuchange(base);
    Mcu_ResetType resetType;
    if(value == 0)
    {
        resetType = MCU_POWER_ON_RESET;
    }
    else if(value == 1)
    {
        resetType = MCU_WATCHDOG_RESET;
    }
    else if(value == 2)
    {
        resetType = MCU_SW_RESET;
    }
    else if(value == 3)
    {
        resetType = MCU_RESET_UNDEFINED;
    }   
    else if (value == 4)
    {
        resetType = MCU_SEM_RESET;
        /* code */
    }
    else if (value == 5)
    {
        resetType = MCU_DBG_RESET;
    }
    else if (value == 6)
    {
        resetType = MCU_VDC_RESET;
    }
    else if (value == 7)
    {
        resetType = MCU_EFUSE_RESET;
    }
    else if (value == 8)
    {
        resetType = MCU_COLD_RESET;
    }
    else if (value == 9)
    {
        resetType = MCU_PVT_RESET;
    }
       return resetType;
}
/*-------------------------------------------------------------------------------------------------------------------*/
Mcu_ResetType Mcu_Ip_GetResetReason(uint32 base)
{
    uint32 value = (uint32)Mcu_Ip_GetResetRawValue(base);
    Mcu_ResetType resetType;

    /* #30  get reset reason*/
    if (0U == value)
    {
        resetType = MCU_POWER_ON_RESET;
    }
    else if ((value & 0x01U) > 0U)      /* pvt reset */
    {
        resetType = MCU_PVT_RESET;
    }
    else if ((value & ((uint32)0x01U << 2U)) > 0U)      /* sem reset */
    {
        resetType = MCU_SEM_RESET;
    }
    else if ((value & ((uint32)0x01U << 3U)) > 0U)      /* voltage detect reset */
    {
        resetType = MCU_VDC_RESET;
    }
    else if ((value & ((uint32)0x01U << 4U)) > 0U)      /* efuse non valiadate reset */
    {
        resetType = MCU_EFUSE_RESET;
#ifndef SEMIDRIVE_E3_LITE_SERIES
    }
    else if ((value & ((uint32)0x01U << 5U)) > 0U)      /* cold reset */
    {
        resetType = MCU_COLD_RESET;
    }
    else if ((value & ((uint32)0x01U << 11)) > 0U)      /* sf_sw_glb reset */
    {
        resetType = MCU_SW_RESET;
    }
    else if ((value & ((uint32)0x7dfU << 14U)) > 0U)
    {
        /* bit[24:14] wdt reset:
        * bit[24:23]:wdt6
        * bit[22:21]:wdt4
        * bit[20]:wdt2
        * bit[18:17]:wdt5
        * bit[16:15]:wdt3
        * bit14:wdt1
        */
        resetType = MCU_WATCHDOG_RESET;
#else
    }
    else if ((value & ((uint32)0x01U << 6U)) > 0U)      /* sf_sw_glb reset */
    {
        resetType = MCU_SW_RESET;
    }
    else if ((value & ((uint32)0x3U << 8U)) > 0U)
    {
        /* bit9:wdt2
        * bit8:wdt1
        */
        resetType = MCU_WATCHDOG_RESET;
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/
    }
    else
    {
        resetType = MCU_RESET_UNDEFINED;
    }

    return resetType;
}


#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
/* End of file */
