/**
 * @file Can_GeneralTypes.h
 * @brief CAN general types
 */

/********************************************************
 *        Copyright(c) 2020    Semidrive                *
 *        All rights reserved.                          *
 ********************************************************/

#ifndef CAN_GENERALTYPES_H_
#define CAN_GENERALTYPES_H_

#include <ComStack_Types.h>
#include "Can_Cfg.h"

#define CAN_T_UNINIT 0xFFU

/**
 * @brief Operating modes for the CAN Transceiver Driver.
 */
typedef enum {
	CANTRCV_TRCVMODE_NORMAL = 0U,
	CANTRCV_TRCVMODE_STANDBY,
	CANTRCV_TRCVMODE_SLEEP
} CanTrcv_TrcvModeType;	
 
/**
 * @brief This type shall be used to control the CAN transceiver concerning wake up events and wake up notifications.
 */ 
typedef enum {
	CANTRCV_WUMODE_ENABLE = 0U,
	CANTRCV_WUMODE_DISABLE,
	CANTRCV_WUMODE_CLEAR
}CanTrcv_TrcvWakeupModeType;	
 
/**
 * @brief This type denotes the wake up reason detected by the CAN transceiver in detail.
 */ 
typedef enum {
    CANTRCV_WU_ERROR = 0U,
	CANTRCV_WU_NOT_SUPPORTED,
	CANTRCV_WU_BY_BUS,
	CANTRCV_WU_INTERNALLY,
	CANTRCV_WU_RESET,
	CANTRCV_WU_POWER_ON,
	CANTRCV_WU_BY_PIN,
	CANTRCV_WU_BY_SYSERR
}CanTrcv_TrcvWakeupReasonType;

/**
 * @brief CAN controller state.
 */
typedef enum
{
    CAN_T_START,
    /**< CAN controller transition value to request state STARTED. */
    CAN_T_STOP,
    /**< CAN controller transition value to request state STOPPED. */
    CAN_T_SLEEP,
    /**< CAN controller transition value to request state SLEEP. */
    CAN_T_WAKEUP,
    /**< CAN controller transition value to request state STOPPED from state SLEEP. */
} Can_StateTransitionType;

typedef enum {
    CAN_CS_UNINIT = 0U,
    CAN_CS_STARTED,
    CAN_CS_STOPPED,
    CAN_CS_SLEEP
} Can_ControllerStateType;

typedef enum {
    CAN_UNINITED,
    CAN_STARTED,
    CAN_STOPPED,
    CAN_SLEEP,
    CAN_WAKEUP,
    CAN_INIT
} Can_ControllerSdpeStateType;

#if defined(AUTOSAR_VERSION_421)
typedef enum
{
    CAN_OK,
    /**< Success */
    CAN_NOT_OK,
    /**< Error occurred or wakeup event occurred during sleep transition */
    CAN_BUSY
    /**< Transmit request could not be processed because no transmit
      * object was available. */
} Can_ReturnType;
#elif defined(AUTOSAR_VERSION_431)
typedef enum
{
    CAN_BUSY = 0x2,
} Can_ReturnType;
#endif

/**
 * @brief CAN error state.
 */
typedef enum {
    CAN_ERRORSTATE_ACTIVE = 0U,
    CAN_ERRORSTATE_PASSIVE,
    CAN_ERRORSTATE_BUSOFF
} Can_ErrorStateType;

/**
 * @brief CAN frame ID type.
 *  This type should be defined according to CAN ID configuration(STANDARD/EXTENDED/MIXED).
 */
typedef uint32 Can_IdType;

/**
 * @brief This type unites PduId (swPduHandle), SduLength (length),
 * SduData (sdu), and CanId (id) for any CAN L-SDU.
 */
typedef struct {
    PduIdType swPduHandle;
    uint8 length;
    Can_IdType id;
    uint8 *sdu;
} Can_PduType;

/**
 * @brief Hardware object handle type.
 */
typedef uint16 Can_HwHandleType;

/**
 * @brief Can_HwType structure.
 */
typedef struct {
    Can_IdType CanId ;
    Can_HwHandleType Hoh;
    uint8 ControllerId;
} Can_HwType;

#endif
/* Version and Check Begin */
/* Version Info Begin */
#define CAN_GENERALTYPES_H_VENDOR_ID    0x8C
#define CAN_GENERALTYPES_H_AR_RELEASE_MAJOR_VERSION    4
#define CAN_GENERALTYPES_H_AR_RELEASE_MINOR_VERSION    3
#define CAN_GENERALTYPES_H_AR_RELEASE_REVISION_VERSION 1
#define CAN_GENERALTYPES_H_SW_MAJOR_VERSION    1
#define CAN_GENERALTYPES_H_SW_MINOR_VERSION    0
#define CAN_GENERALTYPES_H_SW_PATCH_VERSION    0
/* Version Info End */
/* Version and Check End */
