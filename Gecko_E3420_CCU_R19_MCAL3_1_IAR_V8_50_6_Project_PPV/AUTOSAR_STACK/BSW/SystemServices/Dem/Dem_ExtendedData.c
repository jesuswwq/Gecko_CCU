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
**  FILENAME    : Dem_ExtendedData.c                                          **
**                                                                            **
**  Created on  :                                                             **
**  Author      : tao.yu                                                      **
**  Vendor      : i-soft                                                      **
**  DESCRIPTION : API definitions of DEM for ExtendedData                     **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Dem_Internal.h"

#if (DEM_EXTENDED_DATA_CLASS_NUM > 0)
/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Definitions                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*************************************************************************/
/*
 * Brief               Dem_GetExtendedData>
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId
 * Param-Name[out]     pBuffer
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/* PRQA S 3432,1532++ */ /* MISRA Rule 20.7,8.7 */
FUNC(void, DEM_CODE) Dem_GetExtendedData(Dem_EventIdType IntId, P2VAR(uint8, AUTOMATIC, DEM_VAR) pBuffer)
/* PRQA S 3432,1532-- */ /* MISRA Rule 20.7,8.7 */
{
    P2CONST(Dem_DTCAttributesType, AUTOMATIC, DEM_CONST) pDTCAttrCfg = Dem_EventDTCAttributesCfg(IntId);
    uint16 pExtRecord;
    uint16 index;
    P2CONST(uint8, AUTOMATIC, DEM_CONST) pExtIndex;
    uint8 iloop = 0;
    uint8 cnt;

    Dem_UpdateInternalData(IntId);

    if ((pDTCAttrCfg == NULL_PTR) || (pDTCAttrCfg->DemExtendedDataClassRef == DEM_EXTENDED_DATA_INVALID))
    {
        return;
    }
    pExtIndex = &DemExtendedDataRecordClassRef[DemExtendedDataClass[pDTCAttrCfg->DemExtendedDataClassRef].StartIndex];
    while (iloop < DemExtendedDataClass[pDTCAttrCfg->DemExtendedDataClassRef].RefNum)
    {
        if (*pExtIndex != DEM_EXTENDED_DATA_RECORD_INVALID)
        {
#if (DEM_DATA_ELEMENT_CLASS_NUM > 0)
            pExtRecord = DemExtendedDataRecordClass[*pExtIndex].DemDataElementClassIndex;
            index = 0;
            while (index < DemExtendedDataRecordClass[*pExtIndex].DemDataElementClassNum)
            {
                if (DemDataElementClass[pExtRecord].DemDataElementReadFnc != NULL_PTR)
                {
                    if (DemDataElementClass[pExtRecord].DemDataElementReadFnc(pBuffer) != E_OK)
                    {
                        Dem_MemSet(pBuffer, 0xFFu, DemDataElementClass[pExtRecord].DemDataElementDataSize);
                        DEM_DET_REPORT(DEM_SID_MAINFUNCTION, DEM_E_NODATAAVAILABLE);
                    }
                }

                for (cnt = 0; cnt < DemDataElementClass[pExtRecord].DemDataElementDataSize; cnt++)
                {
                    pBuffer++;
                }
                pExtRecord++;
                index++;
            }
#endif
        }
        pExtIndex++;
        iloop++;
    }
    return;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Dem_ExtendedDataGetFromEntry
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  BufSize
 * Return              None
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Std_ReturnType, DEM_CODE)
Dem_ExtendedDataGetFromEntry(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR) pEntry,
    uint8 RecordNum,
    P2VAR(uint8, AUTOMATIC, DEM_VAR) pBuffer,
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
    uint16* BufSize)
{
    P2CONST(Dem_DTCAttributesType, AUTOMATIC, DEM_CONST)
    pDTCAttrCfg = Dem_EventDTCAttributesCfg(Dem_GetEventInternalId(pEntry->EventId));
    P2CONST(Dem_ExtendedDataRecordClassType, AUTOMATIC, DEM_CONST) pExtRecord;
    P2CONST(uint8, AUTOMATIC, DEM_CONST) pExtIndex;
    uint8 iloop = 0;
    uint8 cnt;
    P2VAR(uint8, AUTOMATIC, DEM_VAR) pExt = pEntry->ExtData; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    Dem_EventIdType IntId = Dem_GetEventInternalId(pEntry->EventId);
    Dem_GetExtendedData(IntId, pExt);
    
    pExtIndex = &DemExtendedDataRecordClassRef[DemExtendedDataClass[pDTCAttrCfg->DemExtendedDataClassRef].StartIndex];
    while (iloop < DemExtendedDataClass[pDTCAttrCfg->DemExtendedDataClassRef].RefNum)
    {
        if (*pExtIndex != DEM_EXTENDED_DATA_RECORD_INVALID)
        {
            pExtRecord = &DemExtendedDataRecordClass[*pExtIndex];
            if (pExtRecord->DemExtendedDataRecordNumber == RecordNum)
            {
                if (0x00u == DEM_BITS_ISSET(pEntry->ExtStatus, iloop) && 0x00u == (pEntry -> AgedCounter))
                {
                    return DEM_E_NODATAAVAILABLE;
                }
                else
                {
#if (DEM_DATA_ELEMENT_CLASS_NUM > 0u)
                    Dem_UpdateInternalData(Dem_GetEventInternalId(pEntry->EventId));
                    DemDataElementClass[pExtRecord->DemDataElementClassIndex].DemDataElementReadFnc(pExt);
                    if (FALSE == DemDataElementClass[pExtRecord->DemDataElementClassIndex].DemInterFlag)
                    {
                        Dem_MemCopy(pBuffer, pExt, pExtRecord->DataSize);
                    }
                    else
                    {
                        /* get inter data now */
                        DemDataElementClass[pExtRecord->DemDataElementClassIndex].DemDataElementReadFnc(pBuffer);
                    }
#endif
                    *BufSize = pExtRecord->DataSize;
                    return E_OK;
                }
            }
            else
            {
                for (cnt = 0; cnt < pExtRecord->DataSize; cnt++)
                {
                    pExt++;
                }
            }
        }
        pExtIndex++;
        iloop++;
    }
    return DEM_E_WRONG_RECORDNUMBER;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Dem_CheckExtendedDataIsStorage
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId && Trigger
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              boolean
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/* PRQA S 1532++ */ /* MISRA Rule 8.7 */
FUNC(boolean, DEM_CODE) Dem_CheckExtendedDataIsStorage(Dem_EventIdType IntId, uint8 Trigger)
/* PRQA S 1532-- */ /* MISRA Rule 8.7 */
{
    boolean res = FALSE;
    P2CONST(Dem_DTCAttributesType, AUTOMATIC, DEM_CONST) pDTCAttrCfg = Dem_EventDTCAttributesCfg(IntId);
    P2CONST(Dem_ExtendedDataRecordClassType, AUTOMATIC, DEM_CONST) pExtRecord;
    P2CONST(uint8, AUTOMATIC, DEM_CONST) pExtIndex;
    uint8 iloop = 0;

    if ((pDTCAttrCfg == NULL_PTR) || (pDTCAttrCfg->DemExtendedDataClassRef == DEM_EXTENDED_DATA_INVALID))
    {
        return res;
    }
    pExtIndex = &DemExtendedDataRecordClassRef[DemExtendedDataClass[pDTCAttrCfg->DemExtendedDataClassRef].StartIndex];
    while ((iloop < DemExtendedDataClass[pDTCAttrCfg->DemExtendedDataClassRef].RefNum) && (res == FALSE))
    {
        if (*pExtIndex != DEM_EXTENDED_DATA_RECORD_INVALID)
        {
            pExtRecord = &DemExtendedDataRecordClass[*pExtIndex];
            if (pExtRecord->DemExtendedDataRecordTrigger == Trigger)
            {
                res = TRUE;
            }
        }
        pExtIndex++;
        iloop++;
    }
    return res;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Dem_ExtendedDataStorage
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId && pEventBuffer && Trigger
 * Param-Name[out]     None
 * Param-Name[in/out]  pEntry
 * Return              None
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(void, DEM_CODE)
/* PRQA S 1532,3432++ */ /* MISRA Rule 8.7,20.7 */
Dem_ExtendedDataStorage(
    Dem_EventIdType IntId,
    P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR) pEntry,
    CONSTP2VAR(Dem_EventDataBufferType, AUTOMATIC, DEM_VAR) pEventBuffer,
    uint8 Trigger)
/* PRQA S 1532,3432-- */ /* MISRA Rule 8.7,20.7 */
{
    P2CONST(Dem_DTCAttributesType, AUTOMATIC, DEM_CONST) pDTCAttrCfg = Dem_EventDTCAttributesCfg(IntId);
    P2CONST(Dem_ExtendedDataRecordClassType, AUTOMATIC, DEM_CONST) pExtRecord;
    P2CONST(uint8, AUTOMATIC, DEM_CONST) pExtIndex;
    uint8 iloop = 0;
    Dem_DTCOriginType pMemDest;
    uint8 Offset = 0;

    if ((pDTCAttrCfg == NULL_PTR) || (pDTCAttrCfg->DemExtendedDataClassRef == DEM_EXTENDED_DATA_INVALID))
    {
        return;
    }
#if (DEM_ENVIRONMENT_DATA_CAPTURE == DEM_CAPTURE_ASYNCHRONOUS_TO_REPORTING)
#if (DEM_EXTENDED_DATA_CLASS_NUM > 0) /*SWS_Dem_00812]*/
    Dem_GetExtendedData(IntId, pEventBuffer->ExtData);
#endif
#endif
    pExtIndex = &DemExtendedDataRecordClassRef[DemExtendedDataClass[pDTCAttrCfg->DemExtendedDataClassRef].StartIndex];
    while (iloop < DemExtendedDataClass[pDTCAttrCfg->DemExtendedDataClassRef].RefNum)
    {
        if (*pExtIndex != DEM_EXTENDED_DATA_RECORD_INVALID)
        {
            pExtRecord = &DemExtendedDataRecordClass[*pExtIndex];
            /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
            P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent = Dem_GetEventInfo(IntId);
            /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
            if ((pExtRecord->DemExtendedDataRecordTrigger == Trigger)
                && ((DEM_EVENT_STATUS_FDC_TRIGGERED != Trigger)
                    || (DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_FDC_TRIGGERED) == 0x00u))
                && ((pExtRecord->DemExtendedDataRecordUpdate == DEM_UPDATE_RECORD_YES)
                    || ((0x00u == DEM_BITS_ISSET(pEntry->ExtStatus, iloop))
                        && (pExtRecord->DemExtendedDataRecordUpdate == DEM_UPDATE_RECORD_NO))))
            {                                           /*SWS_Dem_00815] [SWS_Dem_00816] */
                DEM_BITS_SET(pEntry->ExtStatus, iloop); /*set the corresponding bit*/
                Dem_MemCopy(&(pEntry->ExtData[Offset]), &(pEventBuffer->ExtData[Offset]), pExtRecord->DataSize);
            }
            if ((pExtRecord->DemExtendedDataRecordTrigger == DEM_TRIGGER_ON_MIRROR)
                && ((pExtRecord->DemExtendedDataRecordUpdate == DEM_UPDATE_RECORD_YES)
                    || ((0x00u == DEM_BITS_ISSET(pEntry->ExtStatus, iloop))
                        && (pExtRecord->DemExtendedDataRecordUpdate == DEM_UPDATE_RECORD_NO))))
            { /*SWS_Dem_01071*/
                pMemDest = Dem_GetInternalMemDest(DEM_DTC_ORIGIN_MIRROR_MEMORY);
                if (pMemDest != DEM_MEM_DEST_INVALID)
                {
                    pEntry = Dem_MirrorEntryAllocate(IntId, pMemDest);

                    if ((pEntry != NULL_PTR)

                        && (0x00u
                            == DEM_BITS_ISSET(
                                DemMemDestInfo[pMemDest].DisableDTCRecordUpdate,
                                DemPbCfgPtr->DemEventParameter[IntId].DemDTCRef)))
                    {
                        DEM_BITS_SET(pEntry->ExtStatus, iloop); /*set the corresponding bit*/
                        Dem_MemCopy(&(pEntry->ExtData[Offset]), &(pEventBuffer->ExtData[Offset]), pExtRecord->DataSize);
                    }
                }
            }
            Offset += pExtRecord->DataSize;
        }
        pExtIndex++;
        iloop++;
    }
    return;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*******************************************************************************
**                      end of file                                           **
*******************************************************************************/
#endif
