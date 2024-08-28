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
 *  \file     Port_Fault.h                                                                              *
 *  \brief    This file contains interface header for PORT MCAL driver.                                 *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/22     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef PORT_FAULT_H
#define PORT_FAULT_H

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Std_Types.h"

/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
#ifndef PORT_FAULT_INJECTION
/** \brief  FUNCTION:Port_EnterCheck() fault injection. */
#define PortHookBegin_Port_EnterCheck1()
#define PortHookEnd_Port_EnterCheck1()
#define PortHookBegin_Port_EnterCheck2()
#define PortHookEnd_Port_EnterCheck2()
#define PortHookBegin_Port_Ip_SetDirection()
#define PortHookEnd_Port_Ip_SetDirection()

#else
#ifdef PORT_FAULT_INJECTION_TEST0
/** \brief  FUNCTION:Port_EnterCheck() fault injection. */
extern unsigned char Port_FaultSwitch;
#define PortHookBegin_Port_EnterCheck1() (errStatus = E_OK)
#define PortHookEnd_Port_EnterCheck1()
#define PortHookBegin_Port_EnterCheck2()
#define PortHookEnd_Port_EnterCheck2()
#define PortHookBegin_Port_Ip_SetDirection()                        do\
                                                                    { \
                                                                        if (TRUE == Port_FaultSwitch) \
                                                                        { \
                                                                          REG_WRITE32(0x01UL << PORT_PIN_BIT(GPIO_S9), (PORT_GPIO_SF_BASE + PORT_GPIO_OFFSET(PORT_GPIO_DATA_OUT, PORT_PIN_OFFSET(GPIO_S9)) + PORT_SET_PIN)); \
                                                                        } \
                                                                    } while(0)

#define PortHookEnd_Port_Ip_SetDirection()
#endif
#ifdef PORT_FAULT_INJECTION_TEST1
/** \brief  FUNCTION:Port_EnterCheck() fault injection. */
#define PortHookBegin_Port_EnterCheck1()
#define PortHookEnd_Port_EnterCheck1()
#define PortHookBegin_Port_EnterCheck2()        (Port_InitConfigPtr = NULL_PTR)
#define PortHookEnd_Port_EnterCheck2()
#define PortHookBegin_Port_Ip_SetDirection()
#define PortHookEnd_Port_Ip_SetDirection()
#endif
#ifdef PORT_FAULT_INJECTION_TEST2
/** \brief  FUNCTION:Port_EnterCheck() fault injection. */
#define PortHookBegin_Port_EnterCheck1()                     (errStatus = E_OK)
#define PortHookEnd_Port_EnterCheck1()
#define PortHookBegin_Port_EnterCheck2()                     (Port_InitConfigPtr = NULL_PTR)
#define PortHookEnd_Port_EnterCheck2()
#define PortHookBegin_Port_Ip_SetDirection()
#define PortHookEnd_Port_Ip_SetDirection()
#endif
#endif
#ifdef __cplusplus
}
#endif

#endif /* PORT_FAULT_H */
/* End of file */
