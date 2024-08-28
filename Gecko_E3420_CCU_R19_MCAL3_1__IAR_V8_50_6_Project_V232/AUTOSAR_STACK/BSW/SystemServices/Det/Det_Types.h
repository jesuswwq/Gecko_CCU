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
**  FILENAME    : Det_Types.h                                                 **
**                                                                            **
**  Created on  :                                                             **
**  Author      : Haibin.shao                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Data Type definition for DET                                **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
#ifndef DET_TYPE_H_
#define DET_TYPE_H_

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"

typedef P2FUNC(
    Std_ReturnType,
    DET_CODE,
    Det_ErrorHookFncType)(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);
typedef P2FUNC(
    Std_ReturnType,
    DET_CODE,
    Det_CalloutFncType)(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);
typedef P2FUNC(void, DET_CODE, Det_CallbackFncType)(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* structure used to configure filters and store log data, using 0xFF for a filter item means don't care */
typedef struct
{
    uint16 mModuleId;
    uint8 mInstanceId;
    uint8 mApiId;
    uint8 mErrorId;
} DetInfoType;

/* structure to control the operation of DET debug extension */
typedef struct
{
    /* FALSE: global filters disabled, TRUE: global filters enabled */
    boolean globalFilterActive;
    /* FALSE: logging disabled, TRUE: logging enabled */
    boolean logActive;
    /* FALSE: break on log buffer overrun disabled, TRUE: break on log buffer overrun enabled */
    boolean breakOnLogOverrun;
    /* FALSE: break filters disabled, TRUE: break filters enabled */
    boolean breakFilterActive;
    /* FALSE: break, TRUE: unlock break, can be used to unlock endless loop */
    boolean unlockBreak;
    /* FALSE: dlt filters disabled, TRUE: dlt filters enabled */
    boolean dltFilterActive;
    /* do not modify: last index in array where data was logged, range: 0..DET_LOGBUFFERSIZE-1 */
    uint8 logIndex;
} DetStatusType;

typedef struct
{
    uint8 module_index;
    Det_ErrorHookFncType ErrorHookNotifyFnc;
} Det_ErrorHookNotifyType;

typedef struct
{
    uint8 module_index;
    Det_CalloutFncType ErrorCalloutFnc;
} Det_ErrorCalloutType;

typedef enum
{
    DET_UNINITIALIZED = 0,
    DET_INITIALIZED = 1,
    DET_STARTED = 2
} Det_StateType;

/* Type used to store errors */
typedef struct
{
    uint16 moduleId;
    uint8 instanceId;
    uint8 apiId;
    uint8 errorId;
} Det_EntryType;

typedef struct
{
    uint16 ModuleId;
    uint16 InstanceConfigNbr;
    P2CONST(uint8, AUTOMATIC, DET_APPL_CONST) InstanceConfigPtr;
} Det_ModuleType;

typedef struct
{
    uint16 ModuleConfigNbr;
    P2CONST(Det_ModuleType, AUTOMATIC, DET_APPL_CONST) ModuleConfigPtr;
} Det_ConfigType;

#endif
