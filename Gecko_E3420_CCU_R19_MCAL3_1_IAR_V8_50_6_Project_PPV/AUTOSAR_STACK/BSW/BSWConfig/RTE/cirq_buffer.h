/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <cirq_buffer.h>
 *  @brief      <>
 *
 *  
 *  @author     <>
 */
/*============================================================================*/

/* cirq_buffer.h */

#ifndef CIRQ_BUFFER_H
#define CIRQ_BUFFER_H

/*******************************************************************************
 **                        Revision Control History                           **
******************************************************************************/

/*******************************************************************************
 **                        Version Information                                **
******************************************************************************/

/*******************************************************************************
 **                        Include Section                                    **
******************************************************************************/
#include "Platform_Types.h"

typedef struct {
    uint8 maxCnt;
    uint8 currCnt;
    uint32 dataSize;
    void *head;
    void *tail;
    void *bufStart;
    void *bufEnd;
}CirqBufferType;
CirqBufferType CirqBuffStatCreate(void *buffer, uint8 maxCnt, uint32 dataSize);
Std_ReturnType CirqBuffPush(CirqBufferType *cPtr, void *dataPtr );
Std_ReturnType CirqBuffPop(CirqBufferType *cPtr, void *dataPtr );
void CirqBuff_Init(CirqBufferType *cirqbuffer, void *buffer, uint8 maxCnt, uint32 dataSize);

#endif

