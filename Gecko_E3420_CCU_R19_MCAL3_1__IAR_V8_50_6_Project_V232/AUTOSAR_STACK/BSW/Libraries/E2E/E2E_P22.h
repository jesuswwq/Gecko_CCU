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
**  FILENAME    : E2E_P22.h                                                   **
**                                                                            **
**  Created on  :                                                             **
**  Author      : YangBo                                                      **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
#ifndef E2E_P22_H_
#define E2E_P22_H_

#ifdef __cplusplus

extern "C"
{
#endif
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "E2E.h"
    /*******************************************************************************
    **                      Global Symbols                                        **
    *******************************************************************************/
    /*******************************************************************************
    **                      Global Data Types                                     **
    *******************************************************************************/
    typedef struct
    {
        /*Length of Data, in bits. The value shall be a multiple of 8.*/
        uint16 DataLength;
        /*An array of appropriately chosen Data IDs for protection against
    masquerading.*/
        const uint8* DataIDList;
        /*Initial maximum allowed gap between two counter values of two
    consecutively received valid Data.*/
        uint8 MaxDeltaCounter;
        /*Offset of the E2E header in the Data[] array in bits.*/
        uint16 Offset;
    } E2E_P22ConfigType;

    typedef struct
    {
        /*Counter to be used for protecting the next Data.*/
        uint8 Counter;
    } E2E_P22ProtectStateType;

    typedef enum
    {
        /*OK: the checks of the Data in this cycle were successful (including counter check,
    which was incremented by 1).*/
        E2E_P22STATUS_OK = 0x00,
        /*Error: the Check function has been invoked but no new Data is not available since
    the last call, according to communication medium (e.g. RTE, COM). As a result, no E2E
    checks of Data have been consequently executed.*/
        E2E_P22STATUS_NONEWDATA = 0x01,
        /*Error: error not related to counters occurred (e.g. wrong crc, wrong length).*/
        E2E_P22STATUS_ERROR = 0x07,
        /*Error: the checks of the Data in this cycle were successful, with the exception of the
    repetition.*/
        E2E_P22STATUS_REPEATED = 0x08,
        /*OK: the checks of the Data in this cycle were successful (including counter check,
    which was incremented within the allowed configured delta).*/
        E2E_P22STATUS_OKSOMELOST = 0x20,
        /*Error: the checks of the Data in this cycle were successful, with the exception of
    counter jump, which changed more than the allowed delta*/
        E2E_P22STATUS_WRONGSEQUENCE = 0x40
    } E2E_P22CheckStatusType;

    typedef struct
    {
        /*Result of the verification of the Data in this cycle, determined by the
    Check function.*/
        E2E_P22CheckStatusType Status;
        /*Counter of the data in previous cycle.*/
        uint8 Counter;
    } E2E_P22CheckStateType;

    /*******************************************************************************
    **                      Global Data                                           **
    *******************************************************************************/
    /*******************************************************************************
    **                      Global Functions                                      **
    *******************************************************************************/

    extern FUNC(Std_ReturnType, E2E_CODE) E2E_P22Protect(
        P2CONST(E2E_P22ConfigType, AUTOMATIC, E2E_APPL_DATA) ConfigPtr,
        P2VAR(E2E_P22ProtectStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
        P2VAR(uint8, AUTOMATIC, E2E_APPL_DATA) DataPtr,
        uint16 Length);

    extern FUNC(Std_ReturnType, E2E_CODE)
        E2E_P22ProtectInit(P2VAR(E2E_P22ProtectStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr);

    extern FUNC(Std_ReturnType, E2E_CODE) E2E_P22Check(
        P2CONST(E2E_P22ConfigType, AUTOMATIC, E2E_APPL_DATA) ConfigPtr,
        P2VAR(E2E_P22CheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
        P2CONST(uint8, AUTOMATIC, E2E_APPL_DATA) DataPtr,
        uint16 Length);

    extern FUNC(Std_ReturnType, E2E_CODE)
        E2E_P22CheckInit(P2VAR(E2E_P22CheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr);

    extern FUNC(E2E_PCheckStatusType, E2E_CODE)
        E2E_P22MapStatusToSM(Std_ReturnType CheckReturn, E2E_P22CheckStatusType Status);

#ifdef __cplusplus
}

#endif /* end of __cplusplus */
#endif /*E2E_P22_H_ */
