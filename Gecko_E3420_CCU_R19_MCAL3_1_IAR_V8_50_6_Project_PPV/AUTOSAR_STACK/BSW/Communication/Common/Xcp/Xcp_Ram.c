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
**  FILENAME    : Xcp_Ram.c                                                   **
**                                                                            **
**  Created on  :                                                             **
**  Author      : qinchun.yang                                                **
**  Vendor      :                                                             **
**  DESCRIPTION : Defined array variables for XCP                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
/*=======[I N C L U D E S]====================================================*/
#include "Xcp_Internal.h"
#define XCP_START_SEC_VAR_CLEARED_8
#include "Xcp_MemMap.h"
VAR(uint8, XCP_VAR_NO_INIT_8) Xcp_CmdBuffer[XCP_MAX_CTO];
#define XCP_STOP_SEC_VAR_CLEARED_8
#include "Xcp_MemMap.h"

#define XCP_START_SEC_VAR_CLEARED_8
#include "Xcp_MemMap.h"
VAR(uint8, XCP_VAR_NO_INIT_8) Xcp_RespBuffer[XCP_MAX_CTO];
#define XCP_STOP_SEC_VAR_CLEARED_8
#include "Xcp_MemMap.h"

#define XCP_START_SEC_VAR_CLEARED_8
#include "Xcp_MemMap.h"
VAR(uint8, XCP_VAR) Xcp_EvBuffer[XCP_CTO_BUFFER_SIZE];
#define XCP_STOP_SEC_VAR_CLEARED_8
#include "Xcp_MemMap.h"

#define XCP_START_SEC_VAR_CLEARED_8
#include "Xcp_MemMap.h"
VAR(uint8, XCP_VAR) Xcp_ServBuffer[XCP_CTO_BUFFER_SIZE]; /*PRQA S 1533*/
#define XCP_STOP_SEC_VAR_CLEARED_8
#include "Xcp_MemMap.h"

#if (XCP_PL_DAQ == (XCP_PL_DAQ & XCP_RESOURCE))
#define XCP_START_SEC_VAR_SAVED_ZONE_16
#include "Xcp_MemMap.h"
VAR(Xcp_DaqType, XCP_VAR) Xcp_Daq[XCP_MAX_DAQ]; /* PRQA S 1531 */ /* MISRA Rule 8.7 */
#define XCP_STOP_SEC_VAR_SAVED_ZONE_16
#include "Xcp_MemMap.h"
#endif /* (XCP_PL_DAQ == (XCP_PL_DAQ & XCP_RESOURCE)) */

/*
 * Block transfer
 * */
#if (XCP_MASTER_BLOCK_MODE == STD_ON)
#define XCP_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Xcp_MemMap.h"
VAR(Xcp_AGType, XCP_VAR) Xcp_BlockBuffer[XCP_BLOCK_BUFFER_SIZE];
#define XCP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Xcp_MemMap.h"
#endif

/*
 * CAL
 * */
#if (XCP_PL_CAL == (XCP_PL_CAL & XCP_RESOURCE))
#if (XCP_PAG_SUPPORT == STD_ON)
#define XCP_START_SEC_VAR_CLEARED_8
#include "Xcp_MemMap.h"
VAR(uint8, XCP_VAR) Xcp_ActivPagNum[XCP_MAX_SEGMENT];
#define XCP_STOP_SEC_VAR_CLEARED_8
#include "Xcp_MemMap.h"
#endif
#endif
