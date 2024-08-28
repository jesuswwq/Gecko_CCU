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
#ifndef MCU_ANALOGTRIM_H
#define MCU_ANALOGTRIM_H

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Std_Types.h"
#include "Platform_Types.h"

/** \brief AnalogTrim vd sf type. */
typedef struct
{
    sint8 analogTrimVdSfVin0Uv;/*analog trim vd sf vin0 uv*/
    sint8 analogTrimVdSfVin1Uv;/*analog trim vd sf vin1 uv*/
    sint8 analogTrimVdSfVin2Uv;/*analog trim vd sf vin2 uv*/
    sint8 analogTrimVdSfVin3Uv;/*analog trim vd sf vin3 uv*/
    sint8 analogTrimVdSfVin0Ov;/*analog trim vd sf vin0 ov*/
    sint8 analogTrimVdSfVin1Ov;/*analog trim vd sf vin1 ov*/
    sint8 analogTrimVdSfVin2Ov;/*analog trim vd sf vin2 ov*/
    sint8 analogTrimVdSfVin3Ov;/*analog trim vd sf vin3 ov*/
} Mcu_AnalogTrimVdSfVinType;

/** \brief AnalogTrim vd ap type. */
typedef struct
{
    sint8 analogTrimVdApVin1Uv;/*analog trim vd ap vin1 uv*/
    sint8 analogTrimVdApVin2Uv;/*analog trim vd ap vin2 uv*/
    sint8 analogTrimVdApVin3Uv;/*analog trim vd ap vin3 uv*/
    sint8 analogTrimVdApVin1Ov;/*analog trim vd ap vin1 ov*/
    sint8 analogTrimVdApVin2Ov;/*analog trim vd ap vin2 ov*/
    sint8 analogTrimVdApVin3Ov;/*analog trim vd ap vin3 ov*/
} Mcu_AnalogTrimVdApVinType;

/** \brief vd trim type. */
typedef enum
{
    MCU_ATEVDTRIM = 0, /*ate vd trim*/
    MCU_SWVDTRIM,      /*ate sw trim*/
} Mcu_AnalogTrimVdType;

/** **************************************************************************************
 * \brief This function is used for analog trim for bgr33.

 * \verbatim
 * Syntax             : void Mcu_Ip_AnalogTrimBgr33(void)

 * Service ID[hex]    : 0x00

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : None

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : None

 * Description        : Uninitialized analog trim bgr33 may lead to vd precision reduction.
 *

 * \endverbatim
 *****************************************************************************************/
void Mcu_Ip_AnalogTrimBgr33(void);

/** **************************************************************************************
 * \brief This function is used to convert offset to trim value.

 * \verbatim
 * Syntax             : uint8 Mcu_Ip_AnalogTrimVdOffSetToVal(sint16 inVal)

 * Service ID[hex]    : 0x00

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : inVal - trim value to be converted

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : uint8 - converted value

 * Description        : Converts an offset to trim value
 *

 * \endverbatim
 *****************************************************************************************/
uint8 Mcu_Ip_AnalogTrimVdOffSetToVal(sint16 inVal);

#ifndef SEMIDRIVE_E3_LITE_SERIES
/** **************************************************************************************
 * \brief This function is used to read vd fuse value.

 * \verbatim
 * Syntax             : Std_ReturnType Mcu_AnalogTrimVd(VdTrimType TrimType,
 * Mcu_AnalogTrimVdSfVinType *vdSfTrim, Mcu_AnalogTrimVdApVinType *vdApTrim)

 * Service ID[hex]    : 0x00

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : TrimType - sw or ate trim
 *                      vdSfTrim - vd sf trim value pointer
 *                      vdApTrim - vd ap trim value pointer

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : E_OK - Read vd fuse complete
 *                      E_NOT_OK - Read vd fuse did not complete

 * Description        : Read the vd fuse value

 * \endverbatim
 *****************************************************************************************/
Std_ReturnType Mcu_AnalogTrimVd(Mcu_AnalogTrimVdType TrimType, Mcu_AnalogTrimVdSfVinType *vdSfTrim,
                                Mcu_AnalogTrimVdApVinType *vdApTrim);
#endif /** #ifndef SEMIDRIVE_E3_LITE_SERIES*/

/** **************************************************************************************
 * \brief This function is used to read vd fuse value.

 * \verbatim
 * Syntax             : Std_ReturnType Mcu_AteAnalogTrimVd(Mcu_AnalogTrimVdSfVinType *vdSfTrim)

 * Service ID[hex]    : 0x00

 * Sync/Async         : Synchronous

 * Reentrancy         : Non reentrant

 * Parameters (in)    : vdSfTrim - vd sf trim value pointer

 * Parameters (inout) : None

 * Parameters (out)   : None

 * Return value       : E_OK - Read vd fuse complete
 *                      E_NOT_OK - Read vd fuse did not complete

 * Description        : Read the vd fuse value

 * \endverbatim
 *****************************************************************************************/
Std_ReturnType Mcu_AteAnalogTrimVd(Mcu_AnalogTrimVdSfVinType *vdSfTrim);

#ifdef __cplusplus
}
#endif

#endif  /* ifndef MCU_ANALOGTRIM_H */
/* End of file */
