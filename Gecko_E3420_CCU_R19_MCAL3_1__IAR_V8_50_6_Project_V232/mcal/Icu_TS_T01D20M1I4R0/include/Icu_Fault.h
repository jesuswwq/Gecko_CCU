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
 * \file     Icu_Fault.h                                                                                *
 * \brief    AUTOSAR 4.3.1 MCAL Icu fault injection file                                                *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/09/11     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifndef ICU_FAULT_H
#define ICU_FAULT_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef ICU_FAULT_INJECTION

/* fifo err injection in single capture mode */
#define IcuHookBegin_Icu_SingleCptFifoErr()
#define IcuHookEnd_Icu_SingleCptFifoErr()


/* fifo err injection in mukti capture mode */
#define IcuHookBegin_Icu_MultiCptFifoErr()
#define IcuHookEnd_Icu_MultiCptFifoErr()

#else
#include "Icu_UserFault.h"
#endif


#ifdef __cplusplus
}
#endif

#endif /* ICU_FAULT_H */
/* End of file */
