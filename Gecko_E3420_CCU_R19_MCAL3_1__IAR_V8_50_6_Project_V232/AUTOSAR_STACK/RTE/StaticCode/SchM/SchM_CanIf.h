/*============================================================================*/
/*  Copyright (C) 2009-2014, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <SchM_CanIf.h>
 *  @brief      <>
 *
 *  <MCU:TC1782>
 *
 *  @author     <>
 *  @date       <2015-09-22 14:42:04>
 */
/*============================================================================*/

#ifndef _SCHM_CANIF_H_
#define _SCHM_CANIF_H_

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>    <AUTHOR>    <REVISION LOG>
 *  V1.0.0       20130514   Tommy      Initial version
 */
/*============================================================================*/

/*=======[V E R S I O N  I N F O R M A T I O N]===============================*/
#define SCHM_CANIF_H_VENDOR_ID        60U
#define SCHM_CANIF_H_AR_MAJOR_VERSION 1U
#define SCHM_CANIF_H_AR_MINOR_VERSION 1U
#define SCHM_CANIF_H_AR_PATCH_VERSION 2U
#define SCHM_CANIF_H_SW_MAJOR_VERSION 1U
#define SCHM_CANIF_H_SW_MINOR_VERSION 0U
#define SCHM_CANIF_H_SW_PATCH_VERSION 0U

/*=======[I N C L U D E S]====================================================*/
#include "Os.h"

/*=======[M A C R O S]========================================================*/
#define CANIF_AREA_RXBUFFER (0)
#define CANIF_AREA_TXBUFFER (1)
#define CANIF_AREA_CAN      (2)

#define SchM_Enter_CanIf()  SuspendAllInterrupts()
#define SchM_Exit_CanIf()   ResumeAllInterrupts()

#endif                      /* _SCHM_CANIF_H_ */
/*=======[E N D   O F   F I L E]==============================================*/
