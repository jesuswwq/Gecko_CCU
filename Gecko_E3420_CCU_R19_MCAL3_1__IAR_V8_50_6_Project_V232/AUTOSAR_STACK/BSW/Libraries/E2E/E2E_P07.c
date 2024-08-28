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
**  FILENAME    : E2E_P07.c                                                   **
**                                                                            **
**  Created on  :                                                             **
**  Author      : YangBo                                                      **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/* <VERSION> <DATE> <AUTHOR> <REVISION LOG>
 * V2.0.0 [2020/8/17] [YangBo] Initial Vertion.
 * V2.0.1 [2020/9/15] [YangBo] QAC FIX.
 */
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "E2E_P07.h"
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/* PRQA S 3432,4491 ++ */ /* MISRA Rule 20.7, Rule 10.6 */
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#define E2E_START_SEC_CODE
#include "E2E_MemMap.h"
static void E2E_P07Check_Seqence(
    P2CONST(E2E_P07ConfigType, AUTOMATIC, E2E_APPL_DATA) ConfigPtr,
    P2VAR(E2E_P07CheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
    uint32 ReceivedCounter);
#define E2E_STOP_SEC_CODE
#include "E2E_MemMap.h"
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/**
 * Protects the array/buffer to be transmitted using the E2E profile 7.
 * This includes checksum calculation, handling of counter and Data ID.
 * Service ID: 0x21
 * Sync/Async: synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): ConfigPtr,Pointer to static configuration.
 *                 Length,Length of the data in bytes.
 * Parameters(INOUT): StatePtr,Pointer to port/data communication state.
 *                    DataPtr,Pointer to Data to be transmitted.
 * Parameters(OUT): NA
 * Return value: Std_ReturnType,E2E_E_INPUTERR_NULL E2E_E_INPUTERR_WRONG E2E_E_INTERR E2E_E_OK.
 *
 */
#define E2E_START_SEC_CODE
#include "E2E_MemMap.h"
FUNC(Std_ReturnType, E2E_CODE)
E2E_P07Protect(
    P2CONST(E2E_P07ConfigType, AUTOMATIC, E2E_APPL_DATA) ConfigPtr,
    P2VAR(E2E_P07ProtectStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
    P2VAR(uint8, AUTOMATIC, E2E_APPL_DATA) DataPtr,
    uint32 Length)
{
    Std_ReturnType Ret;
    uint32 Offset;
    uint64 ComputedCRC;

    /*Verify inputs of the protect function return*/
    if ((ConfigPtr != NULL_PTR) && (StatePtr != NULL_PTR) && (DataPtr != NULL_PTR))
    {
        if ((Length >= (ConfigPtr->MinDataLength / 8u)) && (Length <= (ConfigPtr->MaxDataLength / 8u)))
        {
            Ret = E2E_E_OK;
        }
        else
        {
            Ret = E2E_E_INPUTERR_WRONG;
        }
    }
    else
    {
        Ret = E2E_E_INPUTERR_NULL;
    }
    if (E2E_E_OK == Ret)
    {
        /*Compute offset[*/
        Offset = ConfigPtr->Offset / 8u;
        /*Write Length*/
        DataPtr[Offset + 8u] = (uint8)(Length >> 24u);
        DataPtr[Offset + 9u] = (uint8)(Length >> 16u);
        DataPtr[Offset + 10u] = (uint8)(Length >> 8u);
        DataPtr[Offset + 11u] = (uint8)Length;
        /*Write Counter*/
        DataPtr[Offset + 12u] = (uint8)(StatePtr->Counter >> 24u);
        DataPtr[Offset + 13u] = (uint8)(StatePtr->Counter >> 16u);
        DataPtr[Offset + 14u] = (uint8)(StatePtr->Counter >> 8u);
        DataPtr[Offset + 15u] = (uint8)(StatePtr->Counter);
        /*Write DataID*/
        DataPtr[Offset + 16u] = (uint8)(ConfigPtr->DataID >> 24u);
        DataPtr[Offset + 17u] = (uint8)(ConfigPtr->DataID >> 16u);
        DataPtr[Offset + 18u] = (uint8)(ConfigPtr->DataID >> 8u);
        DataPtr[Offset + 19u] = (uint8)(ConfigPtr->DataID);
        /*Compute CRC*/
        if (ConfigPtr->Offset > 0u)
        {
            ComputedCRC = Crc_CalculateCRC64(&DataPtr[0], Offset, 0xFFFFFFFFFFFFFFFFu, TRUE);
            ComputedCRC = Crc_CalculateCRC64(&DataPtr[Offset + 8u], Length - Offset - 8u, ComputedCRC, FALSE);
        }
        else
        {
            ComputedCRC = Crc_CalculateCRC64(&DataPtr[Offset + 8u], Length - 8u, 0xFFFFFFFFFFFFFFFFu, TRUE);
        }
        /*Write CRC*/
        DataPtr[Offset] = (uint8)(ComputedCRC >> 56u);
        DataPtr[Offset + 1u] = (uint8)(ComputedCRC >> 48u);
        DataPtr[Offset + 2u] = (uint8)(ComputedCRC >> 40u);
        DataPtr[Offset + 3u] = (uint8)(ComputedCRC >> 32u);
        DataPtr[Offset + 4u] = (uint8)(ComputedCRC >> 24u);
        DataPtr[Offset + 5u] = (uint8)(ComputedCRC >> 16u);
        DataPtr[Offset + 6u] = (uint8)(ComputedCRC >> 8u);
        DataPtr[Offset + 7u] = (uint8)ComputedCRC;
        /*increment counter*/
        StatePtr->Counter++;
    }

    return Ret;
}
#define E2E_STOP_SEC_CODE
#include "E2E_MemMap.h"

/**
 * Initializes the protection state.
 * Service ID: 0x22
 * Sync/Async: synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): NA
 * Parameters(INOUT): StatePtr,Pointer to port/data communication state.
 * Parameters(OUT): NA
 * Return value: Std_ReturnType,E2E_E_INPUTERR_NULL E2E_E_INPUTERR_WRONG
 * E2E_E_INTERR E2E_E_OK.
 *
 */
#define E2E_START_SEC_CODE
#include "E2E_MemMap.h"
FUNC(Std_ReturnType, E2E_CODE) E2E_P07ProtectInit(P2VAR(E2E_P07ProtectStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr)
{
    Std_ReturnType Ret;

    if (NULL_PTR == StatePtr)
    {
        Ret = E2E_E_INPUTERR_NULL;
    }
    else
    {
        StatePtr->Counter = 0;
        Ret = E2E_E_OK;
    }
    return Ret;
}
#define E2E_STOP_SEC_CODE
#include "E2E_MemMap.h"

/**
 * Checks the Data received using the E2E profile 7.
 * This includes CRC calculation, handling of Counter.
 * Service ID: 0x2d
 * Sync/Async: synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): ConfigPtr,Pointer to static configuration.
 *                 DataPtr,Pointer to received data.
 *                 Length,Length of the data in bytes.
 * Parameters(INOUT): StatePtr,Pointer to port/data communication state.
 * Parameters(OUT): NA
 * Return value: Std_ReturnType,E2E_E_INPUTERR_NULL E2E_E_INPUTERR_WRONG E2E_E_INTERR E2E_E_OK.
 *
 */
#define E2E_START_SEC_CODE
#include "E2E_MemMap.h"
FUNC(Std_ReturnType, E2E_CODE)
E2E_P07Check(
    P2CONST(E2E_P07ConfigType, AUTOMATIC, E2E_APPL_DATA) ConfigPtr,
    P2VAR(E2E_P07CheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
    P2CONST(uint8, AUTOMATIC, E2E_APPL_DATA) DataPtr,
    uint32 Length)
{
    Std_ReturnType Ret;
    boolean NewDataAvailable;
    uint32 Offset;
    uint32 ReceivedLength;
    uint32 ReceivedCounter;
    uint32 ReceivedDataID;
    uint64 ReceivedCRC;
    uint64 ComputedCRC;

    /*Verify inputs of the check function*/
    NewDataAvailable = FALSE;
    if ((ConfigPtr != NULL_PTR) && (StatePtr != NULL_PTR))
    {
        if (((DataPtr != NULL_PTR) && (Length != 0u)) || ((NULL_PTR == DataPtr) && (0u == Length)))
        {
            if (DataPtr != NULL_PTR)
            {
                if ((Length >= (ConfigPtr->MinDataLength / 8u)) && (Length <= (ConfigPtr->MaxDataLength / 8u)))
                {
                    NewDataAvailable = TRUE;
                    Ret = E2E_E_OK;
                }
                else
                {
                    Ret = E2E_E_INPUTERR_WRONG;
                }
            }
            else
            {
                Ret = E2E_E_OK;
            }
        }
        else
        {
            Ret = E2E_E_INPUTERR_WRONG;
        }
    }
    else
    {
        Ret = E2E_E_INPUTERR_NULL;
    }

    if (E2E_E_OK == Ret)
    {
        if (TRUE == NewDataAvailable)
        {
            /*Compute offset*/
            Offset = ConfigPtr->Offset / 8u;
            /*Read Length*/
            ReceivedLength = (((uint32)DataPtr[Offset + 8u]) << 24u) + (((uint32)DataPtr[Offset + 9u]) << 16u)
                             + (((uint32)DataPtr[Offset + 10u]) << 8u) + (uint32)DataPtr[Offset + 11u];
            /*Read Counter*/
            ReceivedCounter = (((uint32)DataPtr[Offset + 12u]) << 24u) + (((uint32)DataPtr[Offset + 13u]) << 16u)
                              + (((uint32)DataPtr[Offset + 14u]) << 8u) + (uint32)DataPtr[Offset + 15u];
            /*Read DataID*/
            ReceivedDataID = (((uint32)DataPtr[Offset + 16u]) << 24u) + (((uint32)DataPtr[Offset + 17u]) << 16u)
                             + (((uint32)DataPtr[Offset + 18u]) << 8u) + (uint32)DataPtr[Offset + 19u];
            /*Read CRC*/
            ReceivedCRC = (((uint64)DataPtr[Offset]) << 56u) + (((uint64)DataPtr[Offset + 1u]) << 48u)
                          + (((uint64)DataPtr[Offset + 2u]) << 40u) + (((uint64)DataPtr[Offset + 3u]) << 32u)
                          + (((uint64)DataPtr[Offset + 4u]) << 24u) + (((uint64)DataPtr[Offset + 5u]) << 16u)
                          + (((uint64)DataPtr[Offset + 6u]) << 8u) + ((uint64)DataPtr[Offset + 7u]);
            /*Compute CRC*/
            if (ConfigPtr->Offset > 0u)
            {
                ComputedCRC = Crc_CalculateCRC64(&DataPtr[0], Offset, 0xFFFFFFFFFFFFFFFFu, TRUE);
                ComputedCRC = Crc_CalculateCRC64(&DataPtr[Offset + 8u], Length - Offset - 8u, ComputedCRC, FALSE);
            }
            else
            {
                ComputedCRC = Crc_CalculateCRC64(&DataPtr[Offset + 8u], Length - 8u, 0xFFFFFFFFFFFFFFFFu, TRUE);
            }
        }
        /*Do Checks*/
        if (TRUE == NewDataAvailable)
        {
            if (ReceivedCRC == ComputedCRC)
            {
                if (ReceivedDataID == ConfigPtr->DataID)
                {
                    if (ReceivedLength == Length)
                    {
                        E2E_P07Check_Seqence(ConfigPtr, StatePtr, ReceivedCounter);
                    }
                    else
                    {
                        StatePtr->Status = E2E_P07STATUS_ERROR;
                    }
                }
                else
                {
                    StatePtr->Status = E2E_P07STATUS_ERROR;
                }
            }
            else
            {
                StatePtr->Status = E2E_P07STATUS_ERROR;
            }
        }
        else
        {
            StatePtr->Status = E2E_P07STATUS_NONEWDATA;
        }
    }

    return Ret;
}
#define E2E_STOP_SEC_CODE
#include "E2E_MemMap.h"

/**
 * Initializes the check state
 * Service ID: 0x24
 * Sync/Async: synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): NA
 * Parameters(INOUT): State,Pointer to port/data communication state.
 * Parameters(OUT): NA
 * Return value: Std_ReturnType,E2E_E_INPUTERR_NULL E2E_E_OK.
 *
 */
#define E2E_START_SEC_CODE
#include "E2E_MemMap.h"
FUNC(Std_ReturnType, E2E_CODE) E2E_P07CheckInit(P2VAR(E2E_P07CheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr)
{
    Std_ReturnType Ret;

    if (NULL_PTR == StatePtr)
    {
        Ret = E2E_E_INPUTERR_NULL;
    }
    else
    {
        StatePtr->Counter = 0xFFFFFFFFu;
        StatePtr->Status = E2E_P07STATUS_ERROR;
        Ret = E2E_E_OK;
    }
    return Ret;
}
#define E2E_STOP_SEC_CODE
#include "E2E_MemMap.h"

/**
 * The function maps the check status of Profile 7 to a generic check status, which can be used by E2E state machine
 * check function. The E2E Profile 7 delivers a more fine-granular status, but this is not relevant for the E2E state
 * machine. Service ID: 0x25 Sync/Async: synchronous Reentrancy: Reentrant Parameters(IN): CheckReturn,Return value of
 * the E2E_P07Check function Status,Status determined by E2E_P07Check function Parameters(INOUT): NA Parameters(OUT): NA
 * Return value: E2E_PCheckStatusType,Profile-independent status of the
 * reception on one single Data in one cycle.
 *
 */
#define E2E_START_SEC_CODE
#include "E2E_MemMap.h"
FUNC(E2E_PCheckStatusType, E2E_CODE) E2E_P07MapStatusToSM(Std_ReturnType CheckReturn, E2E_P07CheckStatusType Status)
{
    E2E_PCheckStatusType Ret;

    if (CheckReturn != E2E_E_OK)
    {
        Ret = E2E_P_ERROR;
    }
    else
    {
        switch (Status)
        {
        case E2E_P07STATUS_OK:
        case E2E_P07STATUS_OKSOMELOST:
            Ret = E2E_P_OK;
            break;
        case E2E_P07STATUS_ERROR:
            Ret = E2E_P_ERROR;
            break;
        case E2E_P07STATUS_REPEATED:
            Ret = E2E_P_REPEATED;
            break;
        case E2E_P07STATUS_NONEWDATA:
            Ret = E2E_P_NONEWDATA;
            break;
        case E2E_P07STATUS_WRONGSEQUENCE:
            Ret = E2E_P_WRONGSEQUENCE;
            break;
        default:
            Ret = E2E_P_ERROR;
            break;
        }
    }
    return Ret;
}
#define E2E_STOP_SEC_CODE
#include "E2E_MemMap.h"

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
#define E2E_START_SEC_CODE
#include "E2E_MemMap.h"
static void E2E_P07Check_Seqence(
    P2CONST(E2E_P07ConfigType, AUTOMATIC, E2E_APPL_DATA) ConfigPtr,
    P2VAR(E2E_P07CheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
    uint32 ReceivedCounter)
{
    sint32 DeltaCounter;

    if (ReceivedCounter >= StatePtr->Counter)
    {
        DeltaCounter = (sint32)ReceivedCounter - (sint32)StatePtr->Counter;
    }
    else
    {
        DeltaCounter = (sint32)0xffffffffUL + (sint32)ReceivedCounter - (sint32)StatePtr->Counter + (sint32)1UL;
    }
    if ((DeltaCounter <= (sint32)ConfigPtr->MaxDeltaCounter) && (DeltaCounter >= (sint32)0))
    {
        if (DeltaCounter > 0)
        {
            if (1 == DeltaCounter)
            {
                StatePtr->Status = E2E_P07STATUS_OK;
            }
            else
            {
                StatePtr->Status = E2E_P07STATUS_OKSOMELOST;
            }
        }
        else
        {
            StatePtr->Status = E2E_P07STATUS_REPEATED;
        }
    }
    else
    {
        StatePtr->Status = E2E_P07STATUS_WRONGSEQUENCE;
    }
    StatePtr->Counter = ReceivedCounter;
}
#define E2E_STOP_SEC_CODE
#include "E2E_MemMap.h"
