/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2023)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : Dcm_Dsp.h                                                   **
**                                                                            **
**  Created on  :                                                             **
**  Author      :  long.zhu                                                   **
**  Vendor      :                                                             **
**  DESCRIPTION : This Diagnostic Communication Manager file contained UDS    **
**               services which used for bootloader project.                  **
**                                                                            **
**  SPECIFICATION(S) :  UDS Service - ISO14229.      	                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *   V1.0.0     20121109    Gary             Initial version
 *   V1.0.1     20160801    cywang           update
 *   V1.0.2     20180511    CChen            update
 *   V1.0.3     20200413    Lianren.Wu       optimization
 *   V1.0.4     20200420    Lianren.Wu       delete micro DCM_SERVICE_22_ENABLE
                                             and DCM_SERVICE_11_ENABLE.
 */
#ifndef DCM_DSP_H
#define DCM_DSP_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dcm.h"
#include "Dcm_Cfg.h"
#include "FL.h"
#include "Appl_Dcm.h"
#include "DP.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
/******************************************************************************/
/**
 * @brief               <handle service 0x10 session control>
 *
 * <handle service 0x10 session control> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Dcm_RecvMsg10(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);

/******************************************************************************/
/**
 * @brief               <handle service 0x11 ECU reset>
 *
 * <handle service 0x11 ECU reset> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Dcm_RecvMsg11(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);

#if ((DCM_READDID_NUM > 0U))
/******************************************************************************/
/**
 * @brief               <handle service 0x22 read data by identifier>
 *
 * <handle service 0x22 read data by identifier> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Dcm_RecvMsg22(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);
#endif

#if (DCM_WRITEDID_NUM > 0U)
/*****************************************************************************/
/**
 * @brief               <handle service 0x2E write data by identifier>
 *
 * <handle service 0x2E write data by identifier> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Dcm_RecvMsg2E(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);
#endif

/******************************************************************************/
/**
 * @brief               <handle service 0x27 security access>
 *
 * <handle service 0x27 security access> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Dcm_RecvMsg27(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);

/******************************************************************************/
/**
 * @brief               <handle service 0x28 communication control>
 *
 * <handle service 0x28 communication control> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Dcm_RecvMsg28(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);

/******************************************************************************/
/**
 * @brief               <handle service 0x31 routine control>
 *
 * <handle service 0x31 routine control> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Dcm_RecvMsg31(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);

/******************************************************************************/
/**
 * @brief               <handle service 0x31 routine control>
 *
 * <handle service 0x31 routine control> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Dcm_RecvMsg34(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);

/******************************************************************************/
/**
 * @brief               <handle service 0x36 transfer data>
 *
 * <handle service 0x36 transfer data> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Dcm_RecvMsg36(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);

/******************************************************************************/
/**
 * @brief               <handle service 0x37 exit transfer data>
 *
 * <handle service 0x37 exit transfer data> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Dcm_RecvMsg37(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);

#if (STD_ON == DCM_SERVICE_0X38_ENABLE)
/******************************************************************************/
/**
 * @brief               <handle service 0x38 >
 *
 * <handle service 0x38 > .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Dcm_RecvMsg38(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);
#endif

/******************************************************************************/
/**
 * @brief               <handle service 0x38 >
 *
 * <handle service 0x38 > .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Dcm_RecvMsg3E(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);

#if (DCM_DTC_SET_NUM > 0U)
/******************************************************************************/
/**
 * @brief               <handle service 0x85 set DTC control>
 *
 * <handle service 0x85 set DTC control> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Dcm_RecvMsg85(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);
#endif

#if (DCM_WRITEDID_NUM > 0U)
/******************************************************************************/
/**
 * @brief               <handle service 0x85 set DTC control>
 *
 * <handle service 0x85 set DTC control> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Dcm_Pending2E(const FL_ResultType errorCode, const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);
#endif
/******************************************************************************/
/**
 * @brief               <handle service 0x36 transfer data pending finish>
 *
 * <handle service 0x36 transfer data pending finish> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <errorCode (IN),rxBuff (IN),>
 * @param[out]          <NONE>
 * @param[in/out]       <txBuff (IN/OUT)>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Dcm_Pending36(const FL_ResultType errorCode, const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);

#if (STD_ON == DCM_SERVICE_0X38_ENABLE)
/******************************************************************************/
/**
 * @brief               <handle service 0x38>
 *
 * <handle service 0x38 pending finish> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <errorCode (IN),rxBuff (IN),>
 * @param[out]          <NONE>
 * @param[in/out]       <txBuff (IN/OUT)>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Dcm_Pending38(const FL_ResultType errorCode, const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);
#endif

/******************************************************************************/
/**
 * @brief               <handle service 0x31 routine control pending finish>
 *
 * <handle service 0x31 routine control pending finish> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <errorCode (IN),rxBuff (IN),>
 * @param[out]          <NONE>
 * @param[in/out]       <txBuff (IN/OUT)>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Dcm_Pending31(const FL_ResultType errorCode, const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff);

#endif/* endif of DCM_DSP_H */
