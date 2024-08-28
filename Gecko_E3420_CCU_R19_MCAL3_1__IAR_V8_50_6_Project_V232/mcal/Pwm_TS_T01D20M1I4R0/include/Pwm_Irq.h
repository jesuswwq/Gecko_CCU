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
 *  \file     Pwm_Irq.h                                                                                 *
 *  \brief    This file contains interface header for PWM MCAL driver                                   *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/18     <td>3.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifndef PWM_IRQ_H
#define PWM_IRQ_H

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Mcal.h"

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/

/** *****************************************************************************************************
 * \brief EPWM1 interrupt service routine.
 *
 * \verbatim
 * Syntax             : void Pwm_Irq1Handler(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : EPWM1 interrupt service routine.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_079
 *******************************************************************************************************/
ISR(Pwm_Irq1Handler);

/** *****************************************************************************************************
 * \brief EPWM2 interrupt service routine.
 *
 * \verbatim
 * Syntax             : void Pwm_Irq2Handler(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : EPWM2 interrupt service routine.
 *
 * \endverbatim
 * Traceability       :  SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_079
 *******************************************************************************************************/
ISR(Pwm_Irq2Handler);

/** *****************************************************************************************************
 * \brief EPWM3 interrupt service routine.
 *
 * \verbatim
 * Syntax             : void Pwm_Irq3Handler(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : EPWM3 interrupt service routine.
 *
 * \endverbatim
 * Traceability       :  SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_079
 *******************************************************************************************************/
ISR(Pwm_Irq3Handler);

/** *****************************************************************************************************
 * \brief EPWM4 interrupt service routine.
 *
 * \verbatim
 * Syntax             : void Pwm_Irq4Handler(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : EPWM4 interrupt service routine.
 *
 * \endverbatim
 * Traceability       :  SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_079
 *******************************************************************************************************/
ISR(Pwm_Irq4Handler);

/** *****************************************************************************************************
 * \brief ETIMER1 interrupt service routine.
 *
 * \verbatim
 * Syntax             : void Pwm_Irq5Handler(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : ETIMER1 interrupt service routine.
 *
 * \endverbatim
 * Traceability       :  SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_079
 *******************************************************************************************************/
ISR(Pwm_Irq5Handler);

/** *****************************************************************************************************
 * \brief ETIMER2 interrupt service routine.
 *
 * \verbatim
 * Syntax             : void Pwm_Irq6Handler(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : ETIMER2 interrupt service routine.
 *
 * \endverbatim
 * Traceability       :  SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_079
 *******************************************************************************************************/
ISR(Pwm_Irq6Handler);

/** *****************************************************************************************************
 * \brief ETIMER3 interrupt service routine.
 *
 * \verbatim
 * Syntax             : void Pwm_Irq7Handler(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : ETIMER3 interrupt service routine.
 *
 * \endverbatim
 * Traceability       :  SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_079
 *******************************************************************************************************/
ISR(Pwm_Irq7Handler);

/** *****************************************************************************************************
 * \brief ETIMER4 interrupt service routine.
 *
 * \verbatim
 * Syntax             : void Pwm_Irq8Handler(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : ETIMER4 interrupt service routine.
 *
 * \endverbatim
 * Traceability       :  SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_079
 *******************************************************************************************************/
ISR(Pwm_Irq8Handler);

#ifdef __cplusplus
}
#endif

#endif /* PWM_IRQ_H */
/* End of file */
