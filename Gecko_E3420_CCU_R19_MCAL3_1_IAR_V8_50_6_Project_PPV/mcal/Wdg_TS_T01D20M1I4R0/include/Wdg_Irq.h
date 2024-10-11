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
 *  \file     Wdg_Irq.h                                                                                 *
 *  \brief    This file contains interface header for WDG MCAL driver, ...                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/17     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef WDG_IRQ_H
#define WDG_IRQ_H

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Mcal.h"
#include "Wdg_Cfg.h"
#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/

/** \brief SemiDriver Instruments Vendor ID */
#define WDG_IRQ_H_VENDOR_ID    0x8C

/** \brief AUTOSAR Major version specification implemented by WDG Driver */
#define WDG_IRQ_H_AR_RELEASE_MAJOR_VERSION    4
/** \brief AUTOSAR Minor  version specification implemented by WDG Driver */
#define WDG_IRQ_H_AR_RELEASE_MINOR_VERSION    3
/** \brief AUTOSAR Patch version specification implemented by WDG Driver */
#define WDG_IRQ_H_AR_RELEASE_REVISION_VERSION 1

/** \brief Driver Implementation Major Version */
#define WDG_IRQ_H_SW_MAJOR_VERSION    1
/** \brief Driver Implementation Minor Version */
#define WDG_IRQ_H_SW_MINOR_VERSION    0
/** \brief Driver Implementation Patch Version */
#define WDG_IRQ_H_SW_PATCH_VERSION    0

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
#if (WDG_INSTANCE1_SUPPORT == STD_ON)
/** *****************************************************************************************************
 * \brief TThis service for the WDG instance1 interrupt handle
 *
 * \verbatim
 * Syntax             : void Wdg_Isr_Instance1(void)
 *
 * Service ID[hex]    : none
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This service for the WDG instance1 interrupt handle
 * \endverbatim
 * Traceability       : SWSR_WDG_003 SWSR_WDG_072 SWSR_WDG_074 SWSR_WDG_079 SW_SM003 SW_SM004 SW_SM006
 *******************************************************************************************************/
ISR(Wdg_Isr_Instance1);
#endif /*WDG_INSTANCE1_SUPPORT*/

#if (WDG_INSTANCE2_SUPPORT == STD_ON)
/** *****************************************************************************************************
 * \brief TThis service for the WDG instance2 interrupt handle
 *
 * \verbatim
 * Syntax             : void Wdg_Isr_Instance2(void)
 *
 * Service ID[hex]    : none
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This service for the WDG instance2 interrupt handle
 * \endverbatim
 * Traceability       : SWSR_WDG_072 SWSR_WDG_074 SWSR_WDG_079 SW_SM003 SW_SM004 SW_SM006
 *******************************************************************************************************/
ISR(Wdg_Isr_Instance2);
#endif /*WDG_INSTANCE2_SUPPORT*/

#if (WDG_INSTANCE3_SUPPORT == STD_ON)
/** *****************************************************************************************************
 * \brief TThis service for the WDG instance3 interrupt handle
 *
 * \verbatim
 * Syntax             : void Wdg_Isr_Instance3(void)
 *
 * Service ID[hex]    : none
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This service for the WDG instance3 interrupt handle
 * \endverbatim
 * Traceability       : SWSR_WDG_072 SWSR_WDG_074 SWSR_WDG_079 SW_SM003 SW_SM004 SW_SM006
 *******************************************************************************************************/
ISR(Wdg_Isr_Instance3);
#endif /*WDG_INSTANCE3_SUPPORT*/

#if (WDG_INSTANCE4_SUPPORT == STD_ON)
/** *****************************************************************************************************
 * \brief TThis service for the WDG instance4 interrupt handle
 *
 * \verbatim
 * Syntax             : void Wdg_Isr_Instance4(void)
 *
 * Service ID[hex]    : none
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This service for the WDG instance4 interrupt handle
 * \endverbatim
 * Traceability       : SWSR_WDG_072 SWSR_WDG_074 SWSR_WDG_079 SW_SM003 SW_SM004 SW_SM006
 *******************************************************************************************************/
ISR(Wdg_Isr_Instance4);
#endif /*WDG_INSTANCE4_SUPPORT*/

#if (WDG_INSTANCE5_SUPPORT == STD_ON)
/** *****************************************************************************************************
 * \brief TThis service for the WDG instance5 interrupt handle
 *
 * \verbatim
 * Syntax             : void Wdg_Isr_Instance5(void)
 *
 * Service ID[hex]    : none
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This service for the WDG instance5 interrupt handle
 * \endverbatim
 * Traceability       : SWSR_WDG_072 SWSR_WDG_074 SWSR_WDG_079 SW_SM003 SW_SM004 SW_SM006
 *******************************************************************************************************/
ISR(Wdg_Isr_Instance5);
#endif /*WDG_INSTANCE5_SUPPORT*/

#if (WDG_INSTANCE6_SUPPORT == STD_ON)
/** *****************************************************************************************************
 * \brief TThis service for the WDG instance6 interrupt handle
 *
 * \verbatim
 * Syntax             : void Wdg_Isr_Instance6(void)
 *
 * Service ID[hex]    : none
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This service for the WDG instance6 interrupt handle
 * \endverbatim
 * Traceability       : SWSR_WDG_072 SWSR_WDG_074 SWSR_WDG_079 SW_SM003 SW_SM004 SW_SM006
 *******************************************************************************************************/
ISR(Wdg_Isr_Instance6);
#endif  /*WDG_INSTANCE6_SUPPORT*/

#if (WDG_INSTANCE8_SUPPORT == STD_ON)

/** *****************************************************************************************************
 * \brief TThis service for the WDG instance8 interrupt handle
 *
 * \verbatim
 * Syntax             : void Wdg_Isr_Instance8(void)
 *
 * Service ID[hex]    : none
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This service for the WDG instance8 interrupt handle
 * \endverbatim
 * Traceability       : SWSR_WDG_072 SWSR_WDG_074 SWSR_WDG_079 SW_SM003 SW_SM004 SW_SM006
 *******************************************************************************************************/
ISR(Wdg_Isr_Instance8);
#endif  /*WDG_INSTANCE8_SUPPORT*/
#ifdef __cplusplus
}
#endif

#endif /* WDG_IRQ_H */
/* End of file */
