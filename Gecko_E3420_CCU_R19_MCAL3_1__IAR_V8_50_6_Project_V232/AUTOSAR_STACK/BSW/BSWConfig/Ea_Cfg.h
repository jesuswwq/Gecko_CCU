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
**  FILENAME    : Ea_Cfg.h                                                    **
**                                                                            **
**  Created on  : 2024/06/03 13:57:00                                         **
**  Author      : tao.yu                                                      **
**  Vendor      :                                                             **
**  DESCRIPTION : Ea pre compile globle macro define                          **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
#ifndef EA_CFG_H
#define EA_CFG_H

#include "Eep.h"

/*==============================================================================
*                           VERSION INFORMATION
==============================================================================*/
#define EA_CFG_SW_MAJOR_VERSION 2U
#define EA_CFG_SW_MINOR_VERSION 0U
#define EA_CFG_SW_PATCH_VERSION 0U

/*Switches the development error detection and notification on or off.*/
#define EA_DEV_ERROR_DETECT                                  (STD_ON)

/*Pre-processor switch to enable / disable the API to read out the modules version information.*/
#define EA_VERSION_INFO_API                                  (STD_OFF)

/*Pre-processor switch to enable and disable the polling mode for this module.*/
#define EA_POLLING_MODE                                      (STD_OFF)

/*Compile switch to enable / disable the function Ea_SetMode.*/
#define EA_SETMODE_API                                       (STD_ON)

/*The size in bytes to which logical blocks shall be aligned.*/
#define EA_VIRTUAL_PAGE_SIZE                                 (32u)

#define EA_NUMBER_OF_BLOCKS                                  (0x49u)

/*Management overhead per logical block in bytes.*/
#define EA_BLOCK_OVER_HEAD                                   (14U)

/*Management overhead per page in bytes.*/
#define EA_PAGE_OVER_HEAD                                    (0U)

#define EA_BLOCK_MAX_SIZE                                    (594U)

#endif /* EA_CFG_H */
