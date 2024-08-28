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
 * \file     Pwm_Irq.c                                                                                  *
 * \brief    AUTOSAR 4.3.1 MCAL PWM Driver                                                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/18     <td>3.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Pwm_Irq.h"
#include "Pwm_Ip.h"
/** Traceability       : SWSR_PWM_005 */
#include "Pwm.h"

#define PWM_START_SEC_CODE
/** Traceability       : SWSR_PWM_005 */
#include "Pwm_MemMap.h"

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
#define PWM_ISR(id) \
ISR(Pwm_Irq##id##Handler) \
{ \
    Pwm_Ip_Irq((Pwm_HrdControllerIrqType)PWM##id##_MODULE_IRQ_INDEX); \
}

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
PWM_ISR(1)

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
 * Traceability       : SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_079
 *******************************************************************************************************/
PWM_ISR(2)

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
 * Traceability       : SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_079
 *******************************************************************************************************/
PWM_ISR(3)

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
 * Traceability       : SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_079
 *******************************************************************************************************/
PWM_ISR(4)

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
 * Traceability       : SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_079
 *******************************************************************************************************/
PWM_ISR(5)

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
 * Traceability       : SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_079
 *******************************************************************************************************/
PWM_ISR(6)

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
 * Traceability       : SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_079
 *******************************************************************************************************/
PWM_ISR(7)

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
 * Traceability       : SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_079
 *******************************************************************************************************/
PWM_ISR(8)

#define PWM_STOP_SEC_CODE
/** Traceability       : SWSR_PWM_005 */
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif
/* End of file */
