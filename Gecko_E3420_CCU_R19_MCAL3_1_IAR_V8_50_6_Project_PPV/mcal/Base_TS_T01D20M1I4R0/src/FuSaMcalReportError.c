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
 * \file     FuSaMcalReportError.c                                                                      *
 * \brief    AUTOSAR 4.3.1 MCAL FuSaMcalReportError Driver                                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/13     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "FuSaMcalReportError.h"
#include "debug.h"


uint16 FuSaMcal_ModuleId;
uint8 FuSaMcal_InstanceId;
uint8 FuSaMcal_ApiId;
uint8 FuSaMcal_ErrorId;

Std_ReturnType FuSaMcal_ReportError(uint16 moduleId,uint8 instanceId,uint8 apiId,uint8 errorId)
{
#if defined(AUTOSAR_OS_NOT_USED)
    FuSaMcal_ModuleId= moduleId;
    FuSaMcal_InstanceId = instanceId;
    FuSaMcal_ApiId = apiId;
    FuSaMcal_ErrorId = errorId;
    /* Just for temp used */
    /*PRQA S 3200 2*/
    PRINT("Det:ReportError: Module %d, Instance %d, Api %d, Error %d\n",
        moduleId, instanceId, apiId, errorId);

    /* Never return, but has a return type for compatibility */
    /*while (Det_DummyFlag == 0u);*/
#else
    while(1);
#endif
    return E_OK;
}

/* End of file */
