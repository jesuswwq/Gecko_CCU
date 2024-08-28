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
**  FILENAME    : NmStack_Types.h                                             **
**                                                                            **
**  Created on  :                                                             **
**  Author      : Wanglili                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
#ifndef NMSTACK_TYPES_H_
#define NMSTACK_TYPES_H_
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* Operational modes of the network management. */
typedef uint8 Nm_ModeType;

#define NM_MODE_BUS_SLEEP         ((Nm_ModeType)0x00u)
#define NM_MODE_PREPARE_BUS_SLEEP ((Nm_ModeType)0x01u)
#define NM_MODE_SYNCHRONIZE       ((Nm_ModeType)0x02u)
#define NM_MODE_NETWORK           ((Nm_ModeType)0x03u)

/* States of the network management state machine. */
/* typedef enum
{
    NM_STATE_UNINIT             = 0u,
    NM_STATE_BUS_SLEEP,
    NM_STATE_PREPARE_BUS_SLEEP,
    NM_STATE_READY_SLEEP,
    NM_STATE_NORMAL_OPERATION,
    NM_STATE_REPEAT_MESSAGE,
    NM_STATE_SYNCHRONIZE,
    NM_STATE_OFFLINE,
} Nm_StateType; */

typedef uint8 Nm_StateType;

#define NM_STATE_UNINIT            ((Nm_StateType)0x00u)
#define NM_STATE_BUS_SLEEP         ((Nm_StateType)0x01u)
#define NM_STATE_PREPARE_BUS_SLEEP ((Nm_StateType)0x02u)
#define NM_STATE_READY_SLEEP       ((Nm_StateType)0x03u)
#define NM_STATE_NORMAL_OPERATION  ((Nm_StateType)0x04u)
#define NM_STATE_REPEAT_MESSAGE    ((Nm_StateType)0x05u)
#define NM_STATE_SYNCHRONIZE       ((Nm_StateType)0x06u)
#define NM_STATE_OFFLINE           ((Nm_StateType)0x07u)

/* BusNm Type */

typedef uint8 Nm_BusNmType;

#define NM_BUSNM_CANNM     ((Nm_BusNmType)0x01u)
#define NM_BUSNM_FRNM      ((Nm_BusNmType)0x02u)
#define NM_BUSNM_LOCALNM   ((Nm_BusNmType)0x03u)
#define NM_BUSNM_UDPNM     ((Nm_BusNmType)0x04u)
#define NM_BUSNM_GENERICNM ((Nm_BusNmType)0x05u)
#define NM_BUSNM_J1939NM   ((Nm_BusNmType)0x06u)
#define NM_BUSNM_OSEKNM    ((Nm_BusNmType)0x07u)
#define NM_BUSNM_UNDEF     ((Nm_BusNmType)0xffu)
/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/
/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
#endif /* NMSTACK_TYPES_H_ */
