/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2022)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : SchM_Xcp.h                                                  **
**                                                                            **
**  Created on  :                                                             **
**  Author      : qinchun.yang                                                **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>      <AUTHOR>        <REVISION LOG>
 *  V0.0.0       2020-01-20  qinchun.yang    Initial version.
 */
/*============================================================================*/

#ifndef SCHM_XCP_H_
#define SCHM_XCP_H_

/******************************************************************************/
/*
 * @brief               <Xcp Module scheduled Function>
 *
 * <Scheduled function of the XCP module> .
 * Service ID   :       <(0x04)>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <Xcp_ConfigPtr (IN)>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 */
/******************************************************************************/
extern FUNC(void, XCP_CODE) Xcp_MainFunction(void);
#endif /* SCHM_XCP_H_ */
