/********************************************************************************************************
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
 *  \file     Wdg_140_Instance8_Cfg.h                                                                   *
 *  \brief    This file contains interface header for WDG8 MCAL driver, ...                             *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/17     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifndef WDG_140_INSTANCE8_CFG_H
#define WDG_140_INSTANCE8_CFG_H

/**
 *
 * \addtogroup MCAL_WDG_API WDG Driver
 *
 * The WDG Driver MCAL provides low level access to onbaord WDG peripheral
 * present on Device.Wdg's timeout behavior(RESET/INTERRUPT),timeout counter,
 * trigger condition mode(window/normal mode) and timeout externel signal
 * output support and so on.
 * The WDG Driver implements a standardized interface specified in the
 * AUTOSAR_SWS_WDGDriver document.For example Wdg_init,Wdg_SetMode,Wdg_GetVersion,
 * Wdg_SetTriggerCondition,and Wdg_SetTriggerRoutine interface,and support 
 * instanceId 1~6 and 8.So each of the above interfaces have it own independent name.
 * The WDG Driver is part of the Communication Stack in the AUTOSAR Basic
 * Software (BSW),include EcuM,WdgM,WdgIf can call corresponding interface,reference
 * AUTOSAR_SWS_WDGDriver.pdf sequence discription. 
 * The WDG Hardware Unit cntrolled by WDG Driver combines one or several WDG controllers,
 * which may be located on-chip or as external standalone devices of the same
 * type, with common or separate Hardware Objects E3 support WDT1~WDT6,WDT8 corresponding
 * the instanceId 1~6 and 8.
 */
/** @{ */


/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Wdg_Types.h"
#include "Wdg_Cfg.h"
#ifdef __cplusplus
extern "C" {
#endif

/**
 *
 * \addtogroup MCAL_WDG8_CFG WDG8 CFG Driver
 * 
 */
 /** @{ */

/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/

/**
 *  \name WDG8 CFG Driver ID Info
 *  @{
 */
/** \brief SemiDriver Instruments Vendor ID */
#define WDG_140_INSTANCE8_H_VENDOR_ID    0x8C
/* @} */

/**
 *  \name WDG8 CFG Driver Module AUTOSAR Version Info
 *  Defines for WDG8 CFG Driver AUTOSAR version used for compatibility checks
 *  @{
 */
/** \brief AUTOSAR Major version specification implemented by WDG8 CFG Driver */
#define WDG_140_INSTANCE8_H_AR_MAJOR_VERSION    4
/** \brief AUTOSAR Minor  version specification implemented by WDG8 CFG Driver */
#define WDG_140_INSTANCE8_H_AR_MINOR_VERSION    3
/** \brief AUTOSAR Patch version specification implemented by WDG8 CFG Driver */
#define WDG_140_INSTANCE8_H_AR_REVISION_VERSION 1
/* @} */

/**
 *  \name WDG8 CFG Driver Module SW Version Info
 *  Defines for WDG8 CFG Driver version used for compatibility checks
 *  @{
 */
/** \brief Driver Implementation Major Version */
#define WDG_140_INSTANCE8_H_SW_MAJOR_VERSION    1
/** \brief Driver Implementation Minor Version */
#define WDG_140_INSTANCE8_H_SW_MINOR_VERSION    0
/** \brief Driver Implementation Patch Version */
#define WDG_140_INSTANCE8_H_SW_PATCH_VERSION    0
/* @} */

/* @} */

/** @} */
#ifdef __cplusplus
}
#endif
/** @} */
#endif /*WDG_140_INSTANCE8_CFG_H*/
/* End of file */

