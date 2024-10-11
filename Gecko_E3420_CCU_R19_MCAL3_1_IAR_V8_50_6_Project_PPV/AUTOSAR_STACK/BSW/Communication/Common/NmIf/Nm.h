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
**  FILENAME    : Nm.h                                                        **
**                                                                            **
**  Created on  :                                                             **
**  Author      : Wanglili                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

#ifndef NM_H_
#define NM_H_

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Nm_Cfg.h"
#include "ComStack_Types.h"
#include "NmStack_Types.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* Published information elements */
#define NM_H_AR_RELEASE_MAJOR_VERSION 4u
#define NM_H_AR_RELEASE_MINOR_VERSION 5u
#define NM_H_AR_RELEASE_PATCH_VERSION 0u

/* Error classification */
#define NM_E_UNINIT          ((uint8)(0x00u))
#define NM_E_INVALID_CHANNEL ((uint8)(0x01u))
#define NM_E_PARAM_POINTER   ((uint8)(0x02u))

/* Service ID[hex] */
#define NM_SERVICE_ID_INIT                          ((uint8)0x00u)
#define NM_SERVICE_ID_PASSIVESTARTUP                ((uint8)0x01u)
#define NM_SERVICE_ID_NETWORKREQUEST                ((uint8)0x02u)
#define NM_SERVICE_ID_NETWORKRELEASE                ((uint8)0x03u)
#define NM_SERVICE_ID_DISABLECOMMUNICATION          ((uint8)0x04u)
#define NM_SERVICE_ID_ENABLECOMMUNICATION           ((uint8)0x05u)
#define NM_SERVICE_ID_SETUSERDATA                   ((uint8)0x06u)
#define NM_SERVICE_ID_GETUSERDATA                   ((uint8)0x07u)
#define NM_SERVICE_ID_GETPDUDATA                    ((uint8)0x08u)
#define NM_SERVICE_ID_REPEATMESSAGEREQUEST          ((uint8)0x09u)
#define NM_SERVICE_ID_GETNODEIDENTIFIER             ((uint8)0x0au)
#define NM_SERVICE_ID_GETLOCALNODEIDENTIFIER        ((uint8)0x0bu)
#define NM_SERVICE_ID_CHECKREMOTESLEEPINDICATION    ((uint8)0x0du)
#define NM_SERVICE_ID_GETSTATE                      ((uint8)0x0eu)
#define NM_SERVICE_ID_GETVERSIONINFO                ((uint8)0x0fu)
#define NM_SERVICE_ID_NETWORKSTARTINDICATION        ((uint8)0x11u)
#define NM_SERVICE_ID_NETWORKMODE                   ((uint8)0x12u)
#define NM_SERVICE_ID_BUSSLEEPMODE                  ((uint8)0x14u)
#define NM_SERVICE_ID_PREPAREBUSSLEEPMODE           ((uint8)0x13u)
#define NM_SERVICE_ID_REMOTESLEEPINDICATION         ((uint8)0x17u)
#define NM_SERVICE_ID_REMOTESLEEPCANCELLATION       ((uint8)0x18u)
#define NM_SERVICE_ID_SYNCHRONIZATIONPOINT          ((uint8)0x19u)
#define NM_SERVICE_ID_COORDREADYTOSLEEPINDICATION   ((uint8)0x1eu)
#define NM_SERVICE_ID_COORDREADYTOSLEEPCANCELLATION ((uint8)0x1fu)
#define NM_SERVICE_ID_PDURXINDICATION               ((uint8)0x15u)
#define NM_SERVICE_ID_STATECHANGENOTIFICATION       ((uint8)0x16u)
#define NM_SERVICE_ID_REPEATMESSAGEINDICATION       ((uint8)0x1au)
#define NM_SERVICE_ID_TXTIMEOUTEXCEPTION            ((uint8)0x1bu)
#define NM_SERVICE_ID_CARWAKEUPINDICATION           ((uint8)0x1du)
#define NM_SERVICE_ID_MAINFUNCTION                  ((uint8)0x10u)
#define NM_SERVICE_ID_SYNCHRONIZEMODE               ((uint8)0x21u)
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/****link time configuration parameter type definitions**********/
/*********** Basic functionality provides ***********/
#if (STD_OFF == NM_PASSIVE_MODE_ENABLED)
/* <BusNm>_NetworkRequest */
typedef Std_ReturnType (*BusNm_NetworkRequest_Type)(NetworkHandleType nmNetworkHandle);
/* <BusNm>_NetworkRelease */
typedef Std_ReturnType (*BusNm_NetworkRelease_Type)(NetworkHandleType nmNetworkHandle);
#endif /* STD_OFF ==  NM_PASSIVE_MODE_ENABLED */

/* <BusNm>_PassiveStartUp function */
typedef Std_ReturnType (*BusNm_PassiveStartUp_Type)(NetworkHandleType nmNetworkHandle);

#if (STD_ON == NM_COM_CONTROL_ENABLED)
/* <BusNm>DisableCommunication */
typedef Std_ReturnType (*BusNm_DisableCommunication_Type)(NetworkHandleType nmNetworkHandle);

/* <BusNm>_EnableCommunication */
typedef Std_ReturnType (*BusNm_EnableCommunication_Type)(NetworkHandleType nmNetworkHandle);
#endif /* STD_ON ==  NM_COM_CONTROL_ENABLED */

#if ((STD_OFF == NM_COM_USER_DATA_SUPPORT) && (STD_ON == NM_USER_DATA_ENABLED) && (STD_OFF == NM_PASSIVE_MODE_ENABLED))

/* <BusNm>_SetUserData */
typedef Std_ReturnType (*BusNm_SetUserData_Type)(NetworkHandleType nmNetworkHandle, const uint8* nmUserDataPtr);
#endif /* ((STD_OFF == NM_COM_USER_DATA_SUPPORT)&& \
     (STD_ON == NM_USER_DATA_ENABLED)&&            \
     (STD_OFF == NM_PASSIVE_MODE_ENABLED)) */

#if (STD_ON == NM_USER_DATA_ENABLED)
/* <BusNm>_GetUserData */
typedef Std_ReturnType (*BusNm_GetUserData_Type)(NetworkHandleType nmNetworkHandle, uint8* nmUserDataPtr);
#endif /* STD_ON == NM_USER_DATA_ENABLED */

#if ((STD_ON == NM_COM_USER_DATA_SUPPORT) || (STD_ON == NM_NODE_ID_ENABLED))
/* <BusNm>_GetPduData */
typedef Std_ReturnType (*BusNm_GetPduData_Type)(NetworkHandleType nmNetworkHandle, uint8* nmPduData);
#endif /* ((STD_ON == NM_COM_USER_DATA_SUPPORT)|| \
 (STD_ON ==  NM_NODE_ID_ENABLED)) */

#if (STD_ON == NM_NODE_DETECTION_ENABLED)
/* <BusNm>_RepeatMessageRequest */
typedef Std_ReturnType (*BusNm_RepeatMessageRequest_Type)(NetworkHandleType nmNetworkHandle);
#endif /* STD_ON == NM_NODE_DETECTION_ENABLED */

#if (STD_ON == NM_NODE_ID_ENABLED)
/* <BusNm>_GetNodeIdentifier */
typedef Std_ReturnType (*BusNm_GetNodeIdentifier_Type)(NetworkHandleType nmNetworkHandle, uint8* nmNodeIdPtr);

/* <BusNm>_GetLocalNodeIdentifier */
typedef Std_ReturnType (*BusNm_GetLocalNodeIdentifier_Type)(NetworkHandleType nmNetworkHandle, uint8* nmNodeIdPtr);
#endif /* STD_ON == NM_NODE_ID_ENABLED */

#if (STD_ON == NM_REMOTE_SLEEP_IND_ENABLED)
/* <BusNm>_CheckRemoteSleepIndication */
typedef Std_ReturnType (
    *BusNm_CheckRemoteSleepIndType)(NetworkHandleType nmNetworkHandle, boolean* nmRemoteSleepIndPtr);
#endif /* STD_ON == NM_REMOTE_SLEEP_IND_ENABLED */

/* <BusNm>_GetState */
typedef Std_ReturnType (
    *BusNm_GetState_Type)(NetworkHandleType nmNetworkHandle, Nm_StateType* nmStatePtr, Nm_ModeType* nmModePtr);
#if (STD_ON == NM_BUS_SYNCHRONIZATION_ENABLED)
/* <BusNm>_RequestBusSynchronization */
typedef Std_ReturnType (*BusNm_RequestBusSynchronization_Type)(NetworkHandleType nmChannelHandle);
#endif /* STD_ON == NM_BUS_SYNCHRONIZATION_ENABLED */

#if (STD_ON == NM_COORDINATOR_SYNC_SUPPORT)
/* <BusNm>_SetSleepReadyBit */
typedef Std_ReturnType (*BusNm_SetSleepReadyBit_Type)(NetworkHandleType nmChannelHandle, boolean nmSleepReadyBit);
#endif /* STD_ON ==  NM_COORDINATOR_SYNC_SUPPORT */

/***********End of basic functionality provides ***********/
/* stand bus and generic bus have common low layer call api */
typedef struct
{
#if (STD_OFF == NM_PASSIVE_MODE_ENABLED)
    BusNm_NetworkRequest_Type BusNm_NetworkRequest;
    BusNm_NetworkRelease_Type BusNm_NetworkRelease;
#endif /* STD_OFF ==  NM_PASSIVE_MODE_ENABLED */
    BusNm_PassiveStartUp_Type BusNm_PassiveStartUp;

#if (STD_ON == NM_COM_CONTROL_ENABLED)
    BusNm_DisableCommunication_Type BusNm_DisableCommunication;
    BusNm_EnableCommunication_Type BusNm_EnableCommunication;
#endif /* STD_ON ==  NM_COM_CONTROL_ENABLED */

#if ((STD_OFF == NM_COM_USER_DATA_SUPPORT) && (STD_ON == NM_USER_DATA_ENABLED) && (STD_OFF == NM_PASSIVE_MODE_ENABLED))
    BusNm_SetUserData_Type BusNm_SetUserData;
#endif /* ((STD_OFF == NM_COM_USER_DATA_SUPPORT)&& \
     (STD_ON == NM_USER_DATA_ENABLED)&&            \
     (STD_OFF == NM_PASSIVE_MODE_ENABLED)) */

#if (STD_ON == NM_USER_DATA_ENABLED)
    BusNm_GetUserData_Type BusNm_GetUserData;
#endif /* STD_ON == NM_USER_DATA_ENABLED */

#if ((STD_ON == NM_COM_USER_DATA_SUPPORT) || (STD_ON == NM_NODE_ID_ENABLED))
    BusNm_GetPduData_Type BusNm_GetPduData;
#endif /* ((STD_ON == NM_COM_USER_DATA_SUPPORT)|| \
 (STD_ON ==  NM_NODE_ID_ENABLED)) */

#if (STD_ON == NM_NODE_DETECTION_ENABLED)
    BusNm_RepeatMessageRequest_Type BusNm_RepeatMessageRequest;
#endif /* STD_ON == NM_NODE_DETECTION_ENABLED */

#if (STD_ON == NM_NODE_ID_ENABLED)
    BusNm_GetNodeIdentifier_Type BusNm_GetNodeIdentifier;
    BusNm_GetLocalNodeIdentifier_Type BusNm_GetLocalNodeIdentifier;
#endif /* STD_ON == NM_NODE_ID_ENABLED */

#if (STD_ON == NM_REMOTE_SLEEP_IND_ENABLED)
    BusNm_CheckRemoteSleepIndType BusNm_CheckRemoteSleepInd;
#endif /* STD_ON == NM_REMOTE_SLEEP_IND_ENABLED */

    BusNm_GetState_Type BusNm_GetState;

#if (STD_ON == NM_BUS_SYNCHRONIZATION_ENABLED)
    BusNm_RequestBusSynchronization_Type BusNm_RequestBusSynchronization;
#endif /* STD_ON == NM_BUS_SYNCHRONIZATION_ENABLED */

#if (STD_ON == NM_COORDINATOR_SYNC_SUPPORT)
    BusNm_SetSleepReadyBit_Type BusNm_SetSleepReadyBit;
#endif /* STD_ON ==  NM_COORDINATOR_SYNC_SUPPORT */
} Nm_SpecificLowLayerApiType;

#if (STD_ON == NM_STATE_CHANGE_IND_ENABLED)
/* nm reference com signal typedef */
typedef struct
{
    /* signal id,form com module */
    uint8 sigId;
} Nm_SignalRefType;
#endif /* STD_ON == NM_STATE_CHANGE_IND_ENABLED */

/* main function call cycle time type */
typedef uint16 funcCycTimeType;
/* shutdown time type */
typedef uint16 shutDownTimeType;

typedef struct
{
    uint8 comMChannel;
} Nm_ComMChannelRefType;

typedef struct
{
    /* Generic or Standard Specifies bus type */
    Nm_BusNmType busNmType;
    /* Reference to the corresponding ComM Channel. */
    Nm_ComMChannelRefType NmComMChannelRef;

    /* call special bus network manageme  api */
    const Nm_SpecificLowLayerApiType* busNmApi;

#if (STD_ON == NM_STATE_CHANGE_IND_ENABLED)
    /* Specifies if the NMS shall be set for the corresponding network. */
    /* dependency: only available if NM_STATE_CHANGE_IND_ENABLED
    is TRUE and <Bus>NM_COM_USER_DATA_SUPPORT is configured */
    boolean NmStateReportEnabled;

    /* Reference to the signal for setting the NMS by calling
    Com_SendSignal for the respective channel. */
    Nm_SignalRefType NmStateReportSignalRef;
#endif /* STD_ON == NM_STATE_CHANGE_IND_ENABLED */

#if (STD_ON == NM_COORDINATOR_SUPPORT_ENABLED)
#if (STD_ON == NM_COORDINATOR_SYNC_SUPPORT)
    /* This parameter indicates whether a NM channel */
    /* dependency: If the NmCoordinatorSyncSupport is set to true this
    feature is available */
    boolean NmActiveCoordinator;
#endif /* STD_ON == NM_COORDINATOR_SYNC_SUPPORT */
    /* This parameter shall be set to indicate if the sleep of this network can
    be absolutely decided by the local node only and that no other nodes
    can oppose that decision */
    /* dependency: If the parameter NmCoordClusterIndex is not defined,
    this parameter is not valid. */
    boolean NmChannelSleepMaster;

    /* If this parameter is undefined for a channel, the corresponding bus
    does not belong to an NM coordination cluster. */
    uint8 NmCoordClusterIndex;

    /* If this parameter is true, then this network is a synchronizing network
    for the NM coordination cluster which it belongs to */
    boolean NmSynchronizingNetwork;

    /* special bus shutdownTimer */
    shutDownTimeType busNmShutdownTime;

#endif /* STD_ON == NM_COORDINATOR_SUPPORT_ENABLED */

} Nm_ChannelLConfigType;

#if (STD_ON == NM_CAR_WAKE_UP_RX_ENABLED)
/* Car wakeup callout function api typede */
typedef void (*NmCarWakeUpCallout_Type)(NetworkHandleType nmNetworkHandle);
#endif /* STD_ON == NM_CAR_WAKE_UP_RX_ENABLED */

#if ((STD_ON == NM_CAR_WAKE_UP_RX_ENABLED) || (STD_ON == NM_COORDINATOR_SYNC_SUPPORT))
typedef struct
{

#if (STD_ON == NM_COORDINATOR_SUPPORT_ENABLED)
    /* The period between successive calls to the Main Function of the NM
    Interface in seconds */
    /* dependency: If NmCoordinatorSupportEnabled is set to TRUE, then
    the NmCycletimeMainFunction shall be configured. */
    funcCycTimeType NmCycletimeMainFunction;
#endif /* STD_ON == NM_COORDINATOR_SUPPORT_ENABLED */

#if (STD_ON == NM_COORDINATOR_SYNC_SUPPORT)
    /* Enables/disables the coordinator synchronisation support. */
    /* dependency: NmCoordinatorSyncSupport shall only be valid if
    NM_COORDINATOR_SUPPORT_ENABLED is TRUE. */
    boolean NmCoordinatorSyncSupport;
#endif /* STD_ON == NM_COORDINATOR_SYNC_SUPPORT */

#if (STD_ON == NM_CAR_WAKE_UP_RX_ENABLED)
    /* Enables or disables CWU detection. */
    boolean NmCarWakeUpRxEnabled;
    /* Name of the callout function to be called if Nm_CarWakeUpIndication()
    is called. If this parameter is not configured, the NmIf will call
    BswM_CarWakeUpIndication. */
    NmCarWakeUpCallout_Type NmCarWakeUpCallout;
#endif /* STD_ON == NM_CAR_WAKE_UP_RX_ENABLED */

} Nm_GlobalLConfigType;
#endif /* ((STD_ON == NM_CAR_WAKE_UP_RX_ENABLED)|| \
    (STD_ON == NM_COORDINATOR_SYNC_SUPPORT)) */

/****End of link time configuration parameter type definition****/

/* Post-build configuration parameter type definitions */

#if (STD_ON == NM_COORDINATOR_SUPPORT_ENABLED)

typedef struct
{
#if (STD_ON == NM_COORDINATOR_SYNC_SUPPORT)
    /* top most coordinator */
    boolean topMostCoor;
#endif /* STD_ON == NM_COORDINATOR_SYNC_SUPPORT */
    /* have one or more sync network */
    boolean syncNetFlg;
    /* link NmCoordClusterIndex */
    uint8 coorClusterIndex;
    /* cluster include number of channel */
    uint8 incNumCh;
    /* per cluster include channel */
    const uint8* incCh;
} Nm_PerClusterConfigType;

#endif /* STD_ON == NM_COORDINATOR_SUPPORT_ENABLED */

typedef struct
{
    uint8* NmEcucPartitionRef;

#if (STD_ON == NM_COORDINATOR_SUPPORT_ENABLED)
    /* number of clusters */
    uint8 numOfClu;
    const Nm_PerClusterConfigType* perCluPtr;
#endif /* STD_ON == NM_COORDINATOR_SUPPORT_ENABLED */

} Nm_ConfigType;

/* End of post-build configuration parameter type definitions */

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

/**********Pre-compile configuration parameter declarations*************/

/**********End of pre-compile configuration parameter declarations*************/

/**********Link time configuration parameter declarations*************/
#if ((STD_ON == NM_CAR_WAKE_UP_RX_ENABLED) || (STD_ON == NM_COORDINATOR_SYNC_SUPPORT))

extern const Nm_GlobalLConfigType Nm_GlobalLConfig;

#endif /* ((STD_ON == NM_CAR_WAKE_UP_RX_ENABLED)|| \
    (STD_ON == NM_COORDINATOR_SYNC_SUPPORT)) */

#if (0u < NM_NUMBER_OF_CHANNELS)

extern const Nm_ChannelLConfigType Nm_ChLConfig[NM_NUMBER_OF_CHANNELS];

#endif /* 0u < NM_NUMBER_OF_CHANNELS */

/**********End of link time configuration parameter declarations*******/

/**********Post-Build configuration parameter declarations*************/

extern const Nm_ConfigType Nm_Config;

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
/***************************Public API Declarations****************************/

/******************************************************************************/
/*
 * Brief               This function calls the <BusNm>_PassiveStartUp function
 * ServiceId           0x01
 * Sync/Async          Asynchronous
 * Reentrancy          Non-reentrant for the same NetworkHandle, reentrant otherwise
 * Param-Name[in]      NetworkHandle, Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              E_OK: No error
 *                     E_NOT_OK: Passive startup of network management has failed
 */
/******************************************************************************/
FUNC(void, NM_CODE)
Nm_Init(P2CONST(Nm_ConfigType, AUTOMATIC, NM_APPL_DATA) ConfigPtr);

/******************************************************************************/
/*
 * Brief               This function calls the <BusNm>_PassiveStartUp function
 * ServiceId           0x01
 * Sync/Async          Asynchronous
 * Reentrancy          Non-reentrant for the same NetworkHandle, reentrant otherwise
 * Param-Name[in]      NetworkHandle, Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              E_OK: No error
 *                     E_NOT_OK: Passive startup of network management has failed
 */
/******************************************************************************/
FUNC(Std_ReturnType, NM_CODE)
Nm_PassiveStartUp(NetworkHandleType NetworkHandle);

#if (STD_OFF == NM_PASSIVE_MODE_ENABLED)
/******************************************************************************/
/*
 * Brief               This function calls the <BusNm>_NetworkRequest function
 * ServiceId           0x02
 * Sync/Async          Asynchronous
 * Reentrancy          Non-reentrant for the same NetworkHandle, reentrant otherwise
 * Param-Name[in]      NetworkHandle, Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              E_OK: No error
 *                     E_NOT_OK: Requesting of bus communication has failed
 */
/******************************************************************************/
FUNC(Std_ReturnType, NM_CODE)
Nm_NetworkRequest(NetworkHandleType NetworkHandle);

/******************************************************************************/
/*
 * Brief               This function calls the <BusNm>_NetworkRelease function
 * ServiceId           0x03
 * Sync/Async          Asynchronous
 * Reentrancy          Non-reentrant for the same NetworkHandle, reentrant otherwise
 * Param-Name[in]      NetworkHandle, Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              E_OK: No error
 *                     E_NOT_OK: Releasing of bus communication has failed
 */
/******************************************************************************/
FUNC(Std_ReturnType, NM_CODE)
Nm_NetworkRelease(NetworkHandleType NetworkHandle);
#endif /* STD_OFF == NM_PASSIVE_MODE_ENABLED */

#if (STD_ON == NM_COM_CONTROL_ENABLED)
/******************************************************************************/
/*
 * Brief               disables the NM PDU transmission ability.
 * ServiceId           0x04
 * Sync/Async          Asynchronous
 * Reentrancy          Non-reentrant for the same NetworkHandle, reentrant otherwise
 * Param-Name[in]      NetworkHandle, Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              E_OK: No error
 *                     E_NOT_OK:  Disabling of NM PDU transmission ability has
 *                     failed.
 */
/******************************************************************************/
FUNC(Std_ReturnType, NM_CODE)
Nm_DisableCommunication(NetworkHandleType NetworkHandle);

/******************************************************************************/
/*
 * Brief               Enables the NM PDU transmission ability.
 * ServiceId           0x05
 * Sync/Async          Asynchronous
 * Reentrancy          Non-reentrant for the same NetworkHandle, reentrant otherwise
 * Param-Name[in]      NetworkHandle, Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              E_OK: No error
 *                     E_NOT_OK:  Enabling of NM PDU transmission ability has
 *                     failed.
 */
/******************************************************************************/
FUNC(Std_ReturnType, NM_CODE)
Nm_EnableCommunication(NetworkHandleType NetworkHandle);
#endif /* STD_ON ==  NM_COM_CONTROL_ENABLED */

#if ((STD_OFF == NM_COM_USER_DATA_SUPPORT) && (STD_ON == NM_USER_DATA_ENABLED) && (STD_OFF == NM_PASSIVE_MODE_ENABLED))
/******************************************************************************/
/*
 * Brief               Set user data for NM messages transmitted next on the bus.
 * ServiceId           0x06
 * Sync/Async          Synchronous
 * Reentrancy          Non-reentrant for the same NetworkHandle, reentrant otherwise
 * Param-Name[in]      NetworkHandle, Identification of the NM-channel
 *                     nmUserDataPtr,User data for the next transmitted NM message
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              E_OK: No error
 *                     E_NOT_OK:  Setting of user data has failed
 */
/******************************************************************************/
FUNC(Std_ReturnType, NM_CODE)
Nm_SetUserData(NetworkHandleType NetworkHandle, P2CONST(uint8, AUTOMATIC, NM_APPL_DATA) nmUserDataPtr);
#endif /* ((STD_OFF == NM_COM_USER_DATA_SUPPORT)&& \
     (STD_ON == NM_USER_DATA_ENABLED)&&            \
     (STD_OFF == NM_PASSIVE_MODE_ENABLED)) */

#if (STD_ON == NM_USER_DATA_ENABLED)
/******************************************************************************/
/*
 * Brief               Get user data out of the last successfully received NM message
 * ServiceId           0x07
 * Sync/Async          Synchronous
 * Reentrancy          Non-reentrant for the same NetworkHandle, reentrant otherwise
 * Param-Name[in]      NetworkHandle, Identification of the NM-channel
 * Param-Name[out]     nmUserDataPtr,User data for the next transmitted NM message
 * Param-Name[in/out]  NA
 * Return              E_OK: No error
 *                     E_NOT_OK: Getting of user data has failed
 */
/******************************************************************************/
FUNC(Std_ReturnType, NM_CODE)
Nm_GetUserData(NetworkHandleType NetworkHandle, uint8* nmUserDataPtr);
#endif /* STD_ON == NM_USER_DATA_ENABLED */

#if ((STD_ON == NM_COM_USER_DATA_SUPPORT) || (STD_ON == NM_NODE_ID_ENABLED))
/******************************************************************************/
/*
 * Brief               Get the whole PDU data out of the most recently received
 *                     NM message
 * ServiceId           0x08
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      NetworkHandle, Identification of the NM-channel
 * Param-Name[out]     nmPduData,Pointer where NM PDU shall be copied to.
 * Param-Name[in/out]  NA
 * Return              E_OK: No error
 *                     E_NOT_OK:   Getting of NM PDU data has failed
 */
/******************************************************************************/
FUNC(Std_ReturnType, NM_CODE)
Nm_GetPduData(NetworkHandleType NetworkHandle, uint8* nmPduData);
#endif /* ((STD_ON == NM_COM_USER_DATA_SUPPORT)|| \
 (STD_ON ==  NM_NODE_ID_ENABLED)) */

#if (STD_ON == NM_NODE_DETECTION_ENABLED)
/******************************************************************************/
/*
 * Brief               Set Repeat Message Request Bit for NM messages transmitted
 *                     next on the bus
 * ServiceId           0x09
 * Sync/Async          Asynchronous
 * Reentrancy          Non-reentrant for the same NetworkHandle, reentrant otherwise
 * Param-Name[in]      NetworkHandle, Identification of the NM-channel
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              E_OK: No error
 *                     E_NOT_OK:  Setting of Repeat Message Request Bit has failed
 */
/******************************************************************************/
FUNC(Std_ReturnType, NM_CODE)
Nm_RepeatMessageRequest(NetworkHandleType NetworkHandle);
#endif /* STD_ON == NM_NODE_DETECTION_ENABLED */

#if (STD_ON == NM_NODE_ID_ENABLED)
/******************************************************************************/
/*
 * Brief               Get node identifier out of the last successfully received
 *                     NM Message
 * ServiceId           0x0a
 * Sync/Async          Synchronous
 * Reentrancy          Non-reentrant for the same NetworkHandle, reentrant otherwise
 * Param-Name[in]      NetworkHandle, Identification of the NM-channel
 * Param-Name[out]     nmNodeIdPtr,Pointer where node identifier out of the
 *                     last success fully received NM-message shall be copied to
 * Param-Name[in/out]  NA
 * Return              E_OK: No error
 *                     E_NOT_OK:  Getting of the node identifier out of the last
 *                     received NM-message has failed
 */
/******************************************************************************/
FUNC(Std_ReturnType, NM_CODE)
Nm_GetNodeIdentifier(NetworkHandleType NetworkHandle, uint8* nmNodeIdPtr);
#endif /* STD_ON == NM_NODE_ID_ENABLED */

#if (STD_ON == NM_NODE_ID_ENABLED)
/******************************************************************************/
/*
 * Brief               Get node identifier configured for the local node
 * ServiceId           0x0b
 * Sync/Async          Synchronous
 * Reentrancy          Non-reentrant for the same NetworkHandle, reentrant otherwise
 * Param-Name[in]      NetworkHandle, Identification of the NM-channel
 * Param-Name[out]     nmNodeIdPtr,Pointer where node identifier of the
 *                     local node shall be copied to
 * Param-Name[in/out]  NA
 * Return              E_OK: No error
 *                     E_NOT_OK:  Getting of the node identifier of the local node
 *                     has failed
 */
/******************************************************************************/
FUNC(Std_ReturnType, NM_CODE)
Nm_GetLocalNodeIdentifier(NetworkHandleType NetworkHandle, uint8* nmNodeIdPtr);
#endif /* STD_ON == NM_NODE_ID_ENABLED */

#if (STD_ON == NM_REMOTE_SLEEP_IND_ENABLED)
/******************************************************************************/
/*
 * Brief               Check if remote sleep indication takes place or not
 * ServiceId           0x0d
 * Sync/Async          Synchronous
 * Reentrancy          Non-reentrant for the same NetworkHandle, reentrant otherwise
 * Param-Name[in]      NetworkHandle, Identification of the NM-channel
 * Param-Name[out]     nmRemoteSleepIndPtr,Pointer where check result of remote
 *                     sleep indication shall be copied to
 * Param-Name[in/out]  NA
 * Return              E_OK: No error
 *                     E_NOT_OK:  Checking of remote sleep indication bits has
 *                     failed
 */
/******************************************************************************/
FUNC(Std_ReturnType, NM_CODE)
Nm_CheckRemoteSleepIndication(
    NetworkHandleType nmNetworkHandle,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(boolean, AUTOMATIC, NM_APPL_DATA) nmRemoteSleepIndPtr
    /* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
);
#endif                   /* STD_ON == NM_REMOTE_SLEEP_IND_ENABLED */

/******************************************************************************/
/*
 * Brief               Check if remote sleep indication takes place or not
 * ServiceId           0x0e
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      NetworkHandle, Identification of the NM-channel
 * Param-Name[out]     nmStatePtr,Pointer where state of the network management
 *                     shall be copied to
 *                     nmModePtr,Pointer to the location where the mode of the
 *                     network management shall be copied to
 * Param-Name[in/out]  NA
 * Return              E_OK: No error
 *                     E_NOT_OK:  Getting of NM state has failed
 */
/******************************************************************************/
FUNC(Std_ReturnType, NM_CODE)
Nm_GetState(NetworkHandleType nmNetworkHandle, Nm_StateType* nmStatePtr, Nm_ModeType* nmModePtr);

#if (STD_ON == NM_VERSION_INFO_API)
/******************************************************************************/
/*
 * Brief               This service returns the version information of this module.
 * ServiceId           0x0f
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      NA
 * Param-Name[out]     nmVerInfoPtr,Pointer to where to store the version information
 *                     of this module.
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
FUNC(void, NM_CODE)
Nm_GetVersionInfo(Std_VersionInfoType* nmVerInfoPtr);
#endif /* STD_ON == NM_VERSION_INFO_API */

#if (STD_ON == NM_COORDINATOR_SUPPORT_ENABLED)
/**
 * This function implements the processes of the NM Interface,which need a fix
 *   cyclic scheduling.
 * Service ID: 0x10
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters(IN): NA
 * Parameters(INOUT): NA
 * Parameters(OUT): NA
 * Return value: NA
 *  @SWS_Nm_00279
 */
FUNC(void, NM_CODE)
Nm_MainFunction(void);
#endif /* STD_ON == NM_COORDINATOR_SUPPORT_ENABLED */

#endif /* NM_H_ */
