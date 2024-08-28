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
 * You should have received a copy of the License along with this program.                              *
 * If not, see <http://www.semidrive.com/licenses/>.                                                    *
 *******************************************************************************************************/

/** *****************************************************************************************************
 * \file     FuSaMcalReportError.h                                                                      *
 * \brief    AUTOSAR 4.3.1 MCAL FuSaMcalReportError Driver                                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/13     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef FUSAMCALREPORTERROR_H
#define FUSAMCALREPORTERROR_H

/**
 *
 * \defgroup MCAL_SAFETY_API FuSa Mcal Report Error
 *
 * Functional safety module error handling function.
 * Input error parameter feedback information function.
 * Functional safety module error handling function.
 * Input error parameter feedback information function.
 */

/** @{ */

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Std_Types.h"

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
/** *****************************************************************************************************
 * \brief Service to report development errors.
 *
 * \verbatim
 * Syntax             : void FuSaMcal_ReportError(
 *                          uint16 ModuleId,
 *                          uint8 InstanceId,
 *                          uint8 ApiId,
 *                          uint8 ErrorId)
 *
 * Service ID[hex]    : 0x01
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : ModuleId - Module ID of calling module
 *                      InstanceId - The identifier of the index based instance of a module, starting from 0,
 *          If the module is a single instance module it shall pass 0 as the InstanceId.
 *                      ApiId - ID of API service in which error is detected (defined in SWS of calling module)
 *                      ErrorId - ID of detected development error (defined in SWS of calling module).
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : never returns a value, but has a return type for compatibility with services and hooks.
 *
 * Description        : Error collection function.
 *
 * \endverbatim
 *******************************************************************************************************/
Std_ReturnType FuSaMcal_ReportError(uint16 moduleId,uint8 instanceId,uint8 apiId,uint8 errorId);

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FUSAMCALREPORTERROR_H */

/* End of file */
