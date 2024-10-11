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
 * \file     Mcu_AnalogTrim.h                                                                           *
 * \brief    AUTOSAR 4.3.1 MCAL Mcu Driver                                                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/29     <td>1.0U.0U                                                                   *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef MCU_VD_H
#define MCU_VD_H

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Std_Types.h"
#include "Platform_Types.h"

/********************************************************************************************************
 *                                 Private Macro definition                                             *
 *******************************************************************************************************/
#define VOLT_SEL (0x0u)

#define CFG_OV_THRE (0x4u)
#define CFG_UV_THRE (0x8u)

#define CFG_OV_DET_THRE_NEGATIVE_TEN_PERCENT (0<<2)
#define CFG_OV_DET_THRE_ZERO_TEN_PERCENT (1<<2)
#define CFG_OV_DET_THRE_POSITIVE_TEN_PERCENT (2<<2)
#define CFG_OV_DET_THRE_POSITIVE_TWNTY_PERCENT (3<<2)
#define CFG_OV_WARN_THRE_NEGATIVE_FIVE_PERCENT (0<<1)
#define CFG_OV_WARN_THRE_NEGATIVE_TEN_PERCENT (1<<1)

#define CFG_UV_THRE_POSITIVE_TEN_PERCENT (0<<2)
#define CFG_UV_THRE_ZERO_TEN_PERCENT (1<<2)
#define CFG_UV_THRE_NEGATIVE_TEN_PERCENT (2<<2)
#define CFG_UV_THRE_NEGATIVE_TWNTY_PERCENT (3<<2)
#define CFG_UV_WARN_THRE_POSITIVE_FIVE_PERCENT (0<<1)
#define CFG_UV_WARN_THRE_POSITIVE_TEN_PERCENT (1<<1)

#define CFG_COM (0xCu)
#define CFG_FILT (0x10u)
#define CFG_FILT_FFB_OFFSET (0x0u)
#define CFG_FILT_FFB_OFFSET_SIZE (0x4u)
#define CFG_FILT_RFB_OFFSET (0x4u)
#define CFG_FILT_RFB_OFFSET_SIZE (0x4u)
#define CFG_FILT_SI_OFFSET (0x8u)
#define CFG_FILT_SI_OFFSET_SIZE (0x8u)

#define CFG_MSK_CNT (0x14u)
#define FUSA_SELFTEST_MODE (0x18u)

#define FUNC_VDC_STAT (0x1Cu)
#define FUNC_VDC_STAT_EN (0x20u)
#define FUNC_VDC_INT_SIG_EN (0x24u)
#define FUNC_VDC_COR_SIG_EN (0x28u)
#define FUNC_UNC_SIG_EN (0x2Cu)
#define FUNC_STAT_CLR (0x30u)
#define FUNC_VDC_STAT_B_VIN0_UV_WARN (1<<0)
#define FUNC_VDC_STAT_B_VIN1_UV_WARN (1<<1)
#define FUNC_VDC_STAT_B_VIN2_UV_WARN (1<<2)
#define FUNC_VDC_STAT_B_VIN3_UV_WARN (1<<3)
#define FUNC_VDC_STAT_B_VIN0_UV_ERR (1<<4)
#define FUNC_VDC_STAT_B_VIN1_UV_ERR (1<<5)
#define FUNC_VDC_STAT_B_VIN2_UV_ERR (1<<6)
#define FUNC_VDC_STAT_B_VIN3_UV_ERR (1<<7)
#define FUNC_VDC_STAT_B_VIN0_OV_WARN (1<<8)
#define FUNC_VDC_STAT_B_VIN1_OV_WARN (1<<9)
#define FUNC_VDC_STAT_B_VIN2_OV_WARN (1<<10)
#define FUNC_VDC_STAT_B_VIN3_OV_WARN (1<<11)
#define FUNC_VDC_STAT_B_VIN0_OV_ERR (1<<12)
#define FUNC_VDC_STAT_B_VIN1_OV_ERR (1<<13)
#define FUNC_VDC_STAT_B_VIN2_OV_ERR (1<<14)
#define FUNC_VDC_STAT_B_VIN3_OV_ERR (1<<15)
#define FUNC_VDC_STAT_B_VIN_ALL (0xFFFFu)

#define FUNC_DY_STAT (0x34u)
#define FUNC_HYST_STAT (0x38u)
#define FUNC_STAT_CHK (0x3Cu)
#define FUNC_STAT_CHK_EN (0x40u)
#define FUNC_CHK_INT_SIG_EN (0x44u)
#define FUNC_CHK_B_VIN0_UV (1<<0)
#define FUNC_CHK_B_VIN1_UV (1<<1)
#define FUNC_CHK_B_VIN2_UV (1<<2)
#define FUNC_CHK_B_VIN3_UV (1<<3)
#define FUNC_CHK_B_VIN0_OV (1<<4)
#define FUNC_CHK_B_VIN1_OV (1<<5)
#define FUNC_CHK_B_VIN2_OV (1<<6)
#define FUNC_CHK_B_VIN3_OV (1<<7)
#define FUNC_CHK_B_VIN_ALL (0xFFu)

#define COR_ERR_INT_STAT (0x48u)
#define COR_ERR_INT_STAT_EN (0x4Cu)
#define COR_ERR_INT_STAT_EN_B_ALL (0x01u)

#define COR_ERR_INT_SIG_EN (0x50u)
#define UNC_ERR_INT_STAT (0x54u)
#define UNC_ERR_INT_STAT_EN (0x58u)
#define UNC_ERR_INT_STAT_EN_B_ALL (0x3Fu)

#define UNC_ERR_INT_SIG_EN (0x5Cu)
#define UNC_ERR_INT_SIG_EN_B_PWDATA_UNC (1u<<0)
#define UNC_ERR_INT_SIG_EN_B_PWDATA_FTL (1u<<1)
#define UNC_ERR_INT_SIG_EN_B_PADDR_UNC (1u<<2)
#define UNC_ERR_INT_SIG_EN_B_PCTL_UNC (1u<<3)
#define UNC_ERR_INT_SIG_EN_B_SELFTEST (1u<<4)
#define UNC_ERR_INT_SIG_EN_B_REG_PARITY (1u<<5)
#define UNC_ERR_INT_SIG_EN_B_ALL (0x3Fu)

#define REG_PARITY_ERR_INT_STAT (0x60u)
#define REG_PARITY_ERR_INT_STAT_EN (0x64u)
#define REG_PAR_ERR_INT_SIG_EN (0x68u)
#define VDC_PWDATA_INJ (0x70u)
#define VDC_PWECC_INJ (0x74u)
#define VDC_INT_ERR_INJ (0x78u)
#define ANA_TEST_MD (0x7Cu)

#define VDC_POLL_TIM (0xFFFFFu)
#define FUNC_VDC_STAT_EN_ALL (0xFFFFu)

/*vd volt_sel config type*/
typedef struct
{
    /*set vd vin0 sel thre*/
    uint8 vin0Sel;
    /*set vd vin1 sel thre*/
    uint8 vin1Sel;
    /*set vd vin2 sel thre*/
    uint8 vin2Sel;
    /*set vd vin3 sel thre*/
    uint8 vin3Sel;
} Mcu_VdVoltSelType;

/*vd ov threshold config type*/
typedef struct
{
    /*set vd vin0 ov thre*/
    uint8 vin0OvThre;
    /*set vd vin1 ov thre*/
    uint8 vin1OvThre;
    /*set vd vin2 ov thre*/
    uint8 vin2OvThre;
    /*set vd vin3 ov thre*/
    uint8 vin3OvThre;
} Mcu_VdOvThreType;

/*vd uv threshold config type*/
typedef struct
{
    /*set vd vin0 uv thre*/
    uint8 vin0UvThre;
    /*set vd vin1 uv thre*/
    uint8 vin1UvThre;
    /*set vd vin2 uv thre*/
    uint8 vin2UvThre;
    /*set vd vin3 uv thre*/
    uint8 vin3UvThre;
} Mcu_VdUvThreType;

/*vd filter config type*/
typedef struct
{
    /*set filter sample interval*/
    uint8 cfgSi;
    /*set rising edge bandwidth*/
    uint8 cfgRfb;
    /*set failling edge bandwidth*/
    uint8 cfgFfb;
} Mcu_VdFilterType;

/*vd init config type*/
typedef struct
{
    /*base address*/
    uint32 base;
    /*set VOLT_SEL*/
    Mcu_VdVoltSelType *voltSel;
    /*set ov threshold*/
    Mcu_VdOvThreType *ovThre;
    /*set uv threshold*/
    Mcu_VdUvThreType *uvThre;
    /*set filter*/
    Mcu_VdFilterType *filtCfg;
    /*set the interrupt status bit enable value*/
    uint16 intStaEn;
} Mcu_VdCfgType;

/*sw trim config type*/
typedef struct
{
    /*select need calibre bit*/
    uint16 calibreBit;
    /*select vinset*/
    uint8 vinSel;
    /*step value*/
    sint8 step;
} Mcu_VdSwtrimType;

/** **************************************************************************************
 * \brief This function is used to get vd interrupt status.

 * \verbatim
 * Syntax             : uint32 Mcu_VdGetIntSta(Mcu_VdCfgType *vdCfgPtr)

 * Service ID[hex]    : 0x00

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : vdCfgPtr - vd configuration pointer

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : uint32 - vd interrupt status

 * Description        : Get vd interrupt status
 *

 * \endverbatim
 * Traceability       : SWSR_MCU_048 SW_SM001 SW_SM006
 *****************************************************************************************/
uint32 Mcu_VdGetIntSta(Mcu_VdCfgType *vdCfgPtr);

/** **************************************************************************************
 * \brief This function is used to get vd dynamic status.

 * \verbatim
 * Syntax             : uint32 Mcu_VdGetDySta(Mcu_VdCfgType *vdCfgPtr)

 * Service ID[hex]    : 0x00

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : vdCfgPtr - vd configuration pointer

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : uint32 - vd dynamic status

 * Description        : Get vd dynamic status
 *

 * \endverbatim
 * Traceability       : SWSR_MCU_048 SW_SM001 SW_SM006
 *****************************************************************************************/
uint32 Mcu_VdGetDySta(Mcu_VdCfgType *vdCfgPtr);

/** **************************************************************************************
 * \brief This function is used to clear vd interrupt status.

 * \verbatim
 * Syntax             : void Mcu_VdClrIntSta(Mcu_VdCfgType *vdCfgPtr)

 * Service ID[hex]    : 0x00

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : vdCfgPtr - vd configuration pointer

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : Clear vd interrupt status
 *

 * \endverbatim
 * Traceability       : SWSR_MCU_048 SW_SM001 SW_SM006
 *****************************************************************************************/
void Mcu_VdClrIntSta(Mcu_VdCfgType *vdCfgPtr);

/** **************************************************************************************
 * \brief This function is used to initialize voltage detector.

 * \verbatim
 * Syntax             : Std_ReturnType Mcu_VdInit(Mcu_VdCfgType *vdCfgPtr)

 * Service ID[hex]    : 0x00

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : vdCfgPtr - vd configuration pointer

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : E_OK - Initialize voltage detector successfully
 *                      E_NOT_OK - Initialize voltage detector unsuccessfully

 * Description        : Initialize voltage detector
 *

 * \endverbatim
 * Traceability       : SWSR_MCU_048 SW_SM001 SW_SM006
 *****************************************************************************************/
Std_ReturnType Mcu_VdInit(Mcu_VdCfgType *vdCfgPtr);

#ifndef SEMIDRIVE_E3_LITE_SERIES
/** **************************************************************************************
 * \brief This function is used to software calibrates the VD module.

 * \verbatim
 * Syntax             : uint8 Mcu_VdSwTrim(Mcu_VdCfgType *vdCfgPtr,
 *                      Mcu_VdSwtrimType *VdSwTrim, uint8 VdIdealVinSet)

 * Service ID[hex]    : 0x00

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : vdCfgPtr - vd configuration pointer
 *                      VdSwTrim - vd software trim pointer
 *                      vdIdealVinSet - vd expect vin set

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : 0x0-0x7 - return vd efuse value
 *                      0xFF - vd software calibrates unsuccessfully

 * Description        : Initialize voltage detector
 *

 * \endverbatim
 * Traceability       : SWSR_MCU_048 SW_SM001 SW_SM005 SW_SM006
 *****************************************************************************************/
uint8 Mcu_VdSwTrim(Mcu_VdCfgType *vdCfgPtr, Mcu_VdSwtrimType *vdSwTrim, uint8 vdIdealVinSet);
#endif/*end of MACRO SEMIDRIVE_E3_LITE_SERIES*/

/** **************************************************************************************
 * \brief This function is used to set vd VOLT_SEL.

 * \verbatim
 * Syntax             : void Mcu_VdVoltSelSet(Mcu_VdCfgType *vdCfgPtr)

 * Service ID[hex]    : 0x00

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : vdCfgPtr - vd configuration pointer

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : Set vd VOLT_SEL
 *

 * \endverbatim
 * Traceability       : SWSR_MCU_048 SW_SM001 SW_SM006
 *****************************************************************************************/
void Mcu_VdVoltSelSet(Mcu_VdCfgType *vdCfgPtr);

/** **************************************************************************************
 * \brief This function is used to get vd VOLT_SEL.

 * \verbatim
 * Syntax             : void Mcu_VdVoltSelGet(Mcu_VdCfgType *vdCfgPtr)

 * Service ID[hex]    : 0x00

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : vdCfgPtr - vd configuration pointer

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : Get vd VOLT_SEL
 *

 * \endverbatim
 * Traceability       : SWSR_MCU_048 SW_SM001 SW_SM006
 *****************************************************************************************/
uint32 Mcu_VdVoltSelGet(Mcu_VdCfgType *vdCfgPtr);

#ifdef __cplusplus
}
#endif

#endif  /* ifndef MCU_VD_H */
/* End of file */
