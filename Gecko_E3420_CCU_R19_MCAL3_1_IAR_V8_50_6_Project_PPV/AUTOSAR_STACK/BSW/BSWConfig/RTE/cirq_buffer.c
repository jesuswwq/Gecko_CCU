/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <cirq_buffer.c>
 *  @brief      <>
 *
 *  
 *  @author     <>
 */
/*============================================================================*/

/* cirq_buffer.c */
/*******************************************************************************
 **                        Revision Control History                           **
******************************************************************************/

/*******************************************************************************
 **                        Version Information                                **
******************************************************************************/

/*******************************************************************************
 **                        Include Section                                    **
******************************************************************************/
#include "Os.h"
#include "cirq_buffer.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
static void Cirq_MemCopy(void * Dest,const void * Src,uint32 Size){
    uint8 * pDest = (uint8 *)Dest;
    const uint8 * pSrc = (const uint8 *)Src;
    while (Size > 0u)
    {
        Size--;
        pDest[Size] = pSrc[Size];
    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
void CirqBuff_Init(CirqBufferType *cirqbuffer, void *buffer, uint8 maxCnt, uint32 dataSize) {
    cirqbuffer->bufStart = buffer;
    cirqbuffer->maxCnt = maxCnt;
    cirqbuffer->bufEnd = ((uint8 *)cirqbuffer->bufStart) + (dataSize*maxCnt);
    cirqbuffer->head = cirqbuffer->bufStart;
    cirqbuffer->tail = cirqbuffer->bufStart;
    cirqbuffer->dataSize = dataSize;
    cirqbuffer->currCnt = 0;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
CirqBufferType CirqBuffStatCreate(void *buffer, uint8 maxCnt, uint32 dataSize) {
    CirqBufferType cirqbuffer;
    cirqbuffer.bufStart = buffer;
    cirqbuffer.maxCnt = maxCnt;
    cirqbuffer.bufEnd = ((uint8 *)cirqbuffer.bufStart) + (dataSize*maxCnt);
    cirqbuffer.head = cirqbuffer.bufStart;
    cirqbuffer.tail = cirqbuffer.bufStart;
    cirqbuffer.dataSize = dataSize;
    cirqbuffer.currCnt = 0;
    return cirqbuffer;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType CirqBuffPush(CirqBufferType *cPtr, void *dataPtr ) {
    Std_ReturnType result = E_OK;
    DisableAllInterrupts();
    if((cPtr->currCnt == cPtr->maxCnt) || (NULL_PTR == cPtr))
    {
        EnableAllInterrupts();
        result = E_NOT_OK;
    }
    else{
        Cirq_MemCopy(cPtr->head,dataPtr,cPtr->dataSize);
        cPtr->head = (uint8 *)cPtr->head + cPtr->dataSize;
        if( cPtr->head == cPtr->bufEnd) {
            cPtr->head = cPtr->bufStart;
        }
        ++cPtr->currCnt;
        EnableAllInterrupts();
    }
    return result;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
Std_ReturnType CirqBuffPop(CirqBufferType *cPtr, void *dataPtr ) {
    Std_ReturnType result = E_OK;
    DisableAllInterrupts();
    if((cPtr->currCnt == 0u) || (NULL_PTR == cPtr)) {
        EnableAllInterrupts();
        result = E_NOT_OK;
    }
    else{
        Cirq_MemCopy(dataPtr,cPtr->tail,cPtr->dataSize);
        cPtr->tail = (uint8 *)cPtr->tail + cPtr->dataSize;
        if( cPtr->tail == cPtr->bufEnd) {
            cPtr->tail = cPtr->bufStart;
        }
        --cPtr->currCnt;
        EnableAllInterrupts();
    }
    return result;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
