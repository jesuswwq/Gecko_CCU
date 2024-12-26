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
**  FILENAME    : Cal.h                                                       **
**                                                                            **
**  Created on  :                                                             **
**  Author      : long.zhu                                               	  **
**  Vendor      :                                                             **
**  DESCRIPTION : function declarations for CRC.                              **
**                                                                            **
**  SPECIFICATION(S) :  NONE                    		                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *   V1.0.0    20121227     Gary              Initial version
 *   V1.0.1    20180511     CChen             update
 *   V1.0.2    20200408     Lianren.Wu        QAC9.5 Test
 */
#ifndef CAL_H
#define CAL_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Cal_Cfg.h"
#include "Std_Types.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/** type for Crc value */
#if (CAL_CRC32 == CAL_METHOD)
typedef uint32 SecM_CRCType;
#elif (CAL_CRC16 == CAL_METHOD)
typedef uint16 SecM_CRCType;
#else
typedef uint8 SecM_CRCType;
#endif

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
/******************************************************************************/
/**
 * @brief               <CRC32 initialize>
 *
 * <This Function Initializes the CRC algorithm> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <curCrc (IN/OUT)>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Cal_CrcInit(SecM_CRCType* curCrc);
/******************************************************************************/
/**
 * @brief               <CRC32 compute>
 *
 * <This Function computes the CRC value> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <buf (IN), size (IN)>
 * @param[out]          <NONE>
 * @param[in/out]       <curCrc (IN/OUT)>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Cal_CrcCal(SecM_CRCType* curCrc, const uint8* buf, const uint32 size);
/******************************************************************************/
/**
 * @brief               <CRC32 finish>
 *
 * <This Function finish the CRC compute.> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <curCrc (IN/OUT)>
 * @return              <NONE>
 */
/******************************************************************************/
extern void Cal_CrcFinalize(SecM_CRCType* curCrc);

#endif/* endif of CAL_H */

