/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <CanTp_Cfg.h>
 *  @brief      <>
 *  
 *  <MCU:E3420>
 *  
 *  @author     <>
 *  @date       <2024-01-31 17:53:40>
 */
/*============================================================================*/

/*============================================================================*/
#ifndef CANTP_CFG_H
#define CANTP_CFG_H

/*======== [I N C L U D E S]========================*/
#include "Std_Types.h"

/*========[M A C R O S] ==========================*/
/* Switches the Development Error Detection and Notification ON or OFF */
#define CANTP_DEV_ERROR_DETECT                     STD_ON

/* Switches the time service ON or OFF */
#define CANTP_TM                                   STD_OFF

/* The time for MainFunction,expressed as the value with ms */
#define CANTP_MAIN_FUNCTION_PERIOD                 0x0u

/* Used for the initialization of unused bytes with a certain value */
#define CANTP_PADDING_BYTE                         0x55u

/* Preprocessor switch for enabling Transmit Cancellation and Receive Cancellation. */
#define CANTP_TC                                   STD_OFF

/* Preprocessor switch for enabling CanTp_ChangeParameterRequest Api*/
#define CANTP_CHANGE_PARAMETER                     STD_ON

/* Preprocessor switch for enabling CanTpReadParameterApi Api*/
#define CANTP_READ_PARAMETER                       STD_OFF

#define CANTP_VERSION_INFO_API                     STD_OFF

/*Enable support for CAN FD frames*/
#define CANTP_FD                                   STD_ON

#define CANTP_DYN_ID_SUPPORT                       STD_OFF
#define CANTP_GENERIC_CONNECTION_SUPPORT           STD_OFF

/* Total number of channel used in CanTp module. */
#define CANTP_MAX_CHANNEL_NUMBER                   0x2u

/* diag gateway response function */
#define CANTP_DIAG_GW_RES_ENABLE                    STD_OFF

/* Synchronous/Asynchronous RxIndication Handle */
#define CANTP_SYNCHRONOUS_RXINDICATION              STD_OFF

#endif /* CANTP_CFG_H */
