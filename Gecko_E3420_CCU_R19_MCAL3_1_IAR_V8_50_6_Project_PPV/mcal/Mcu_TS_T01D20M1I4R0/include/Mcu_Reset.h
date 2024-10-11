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
 *  \file     Mcu_Reset.h                                                                               *
 *  \brief    This file contains interface header for MCU MCAL driver, ...                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/02     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef MCU_RESET_H
#define MCU_RESET_H
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_GeneralTypes.h"

/********************************************************************************************************
 *                                  Global Types definition                                             *
 *******************************************************************************************************/


/**
 * \brief abstract reset general reg
 */
typedef struct
{
    const Mcu_ResetCtlType    *rstCtl;
    uint32            id;
} Mcu_ResetGeneralRegType;

/**
 * \brief global reset controller
 */
typedef struct
{
    const Mcu_ResetCtlType    *rstSfCtl;
} Mcu_ResetGlbCtlType;

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
/**
 * \brief Assert a reset signal.
 * The reset singal will stay asserted until reset_deassert() is called.
 *
 * \param[in] rst_sig Reset signal.
 * \return 0 if OK, or a negative error code.
 */
Std_ReturnType Mcu_Ip_ResetCtlAssert(const Mcu_ResetSigType *rstSigPtr);

/**
 * \brief Deassert a reset signal.
 *
 * \param[in] rst_sig Reset signal.
 * \return 0 if OK, or a negative error code.
 */
Std_ReturnType Mcu_Ip_ResetCtlDeassert(const Mcu_ResetSigType *rstSigPtr);

/**
 * \brief Assert a reset signal, and deassert automatically.
 *
 * \param[in] rst_sig Reset signal.
 * \return 0 if OK, or a negative error code.
 */
Std_ReturnType Mcu_Ip_ResetCtlReset(const Mcu_ResetSigType *rstSigPtr);

/**
 * \brief Check reset signal status.
 *
 * \param[in] rst_sig Reset signal.
 * \return 0 if deasserted, positive if asserted,
 *         or a negative error code.
 */
uint32 Mcu_Ip_ResetCtlStatus(const Mcu_ResetSigType *rstSigPtr);

/**
 * \brief Global reset.
 *
 * \param[in] rst_glb_ctl Global reset controller.
 */
Std_ReturnType Mcu_Ip_ResetCtlGlobalReset(const Mcu_ResetGlbCtlType *rstGlbCtlPrt);


#endif /* MCU_RESET_H */
/* End of file */
