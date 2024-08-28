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
**  FILENAME    : CanSM_BswM.h                                                **
**                                                                            **
**  Created on  :                                                             **
**  Author      : Wanglili                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Interfaces and the corresponding types, which are dedicated **
**                to the BswM module                                          **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      REVISION   HISTORY                                    **
*******************************************************************************/
/* <VERSION>  <DATE>    <AUTHOR>      <REVISION LOG>
 *  V2.0.0    2020-08-17  lili.wang    R19_11 initial version.
 */
#ifndef CANSM_BSWM_H
#define CANSM_BSWM_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/*Can specific communication modes / states notified to the BswM module*/
typedef enum
{
    CANSM_BSWM_NO_COMMUNICATION,
    CANSM_BSWM_SILENT_COMMUNICATION,
    CANSM_BSWM_FULL_COMMUNICATION,
    CANSM_BSWM_BUS_OFF,
    CANSM_BSWM_CHANGE_BAUDRATE
} CanSM_BswMCurrentStateType;
/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/
/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#endif /* CANSM_BSWM_H */
