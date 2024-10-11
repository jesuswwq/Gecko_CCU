
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
**  FILENAME    : Det_Cfg.h                                                   **
**                                                                            **
**  Created on  : 2023-08-29 10:41:31                                         **
**  Author      : ShaoHaiBin                                                  **
**  Vendor      : isoft                                                       **
**  DESCRIPTION : Implementation for Det                                        **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************    
** Configuration description :    
** All configurations of the DET module are not dependent on tool generation,    
** and all configuration items are fixed    
*******************************************************************************/    

/*******************************************************************************    
**                      Revision Control History                              **    
*******************************************************************************/    

#ifndef DET_CFG_H_
#define DET_CFG_H_

/*******************************************************************************    
**                       Version  information                                 **    
*******************************************************************************/    
#define DET_CFG_H_AR_MAJOR_VERSION       4U
#define DET_CFG_H_AR_MINOR_VERSION       5U
#define DET_CFG_H_AR_PATCH_VERSION       0U
#define DET_CFG_H_SW_MAJOR_VERSION       1U
#define DET_CFG_H_SW_MINOR_VERSION       0U
#define DET_CFG_H_SW_PATCH_VERSION       0U

/*******************************************************************************    
**                      Include Section                                       **    
*******************************************************************************/    
#include "Std_Types.h"
#include "Det_Types.h"

/*******************************************************************************    
*                          General Configuration    
*******************************************************************************/    

/* This configuration parameter is used to switch on or to switch off the API to get the version information. Pre-processor switch to enable / disable the API to read out the modules version information. */
#define DET_VERSION_INFO_API                        STD_OFF
/* Only if the parameter is present and set to true, the Det requires the Dlt interface and forwards it's call to the function Dlt_DetForwardErrorTrace. In this case the optional interface to Dlt_Det is required. */
#define DET_FORWARD_TO_DLT                          STD_OFF
/* Pre-processor switch to enable / disable, the Functional used to call error hook when an error is reported. */
#define DET_ERROR_HOOK_ENABLED                      STD_OFF
/* Pre-processor switch to enable / disable, the Functional used to perform callout when an runtime error is reported. */
#define DET_RUNTIME_ERROR_CALLOUT_ENABLED           STD_OFF
/* Pre-processor switch to enable / disable, the Functional used to perform callout when an transient fault is reported. */
#define DET_TRANSIENT_FAULT_CALLOUT_ENABLED         STD_OFF

#define DET_SIZE_OF_ERROR_HOOK_TABLE                (0U)
#define DET_SIZE_OF_RUNTIME_ERROR_CALLOUT_TABLE     (0U)
#define DET_SIZE_OF_TRANSIENT_FAULT_CALLOUT_TABLE   (0U)

/* Configuration of extended debug support features include filtering.  */
#define DET_USE_EXTENDED_DEBUG_SUPPORT              STD_OFF
/* Used to Dlt filter buffer size of Det module. */
#define DET_SIZE_OF_DLT_FILTER                      (0U)
/* Used to Break filter buffer size of Det module. */
#define DET_SIZE_OF_BREAK_FILTER                    (0U)
/* Used to Global filter buffer size of Det module.  */
#define DET_SIZE_OF_GLOBAL_FILTER                   (0U)
/* Used to Log buffer size of Det module. */
#define DET_SIZE_OF_LOG_BUFFER                      (0U)
/* Used to report error recursion limit of Det module. */
#define DET_REPORT_ERROR_RECURSIONLIMIT             0u
/* Used to report Runtime error recursion limit of Det module. */
#define DET_REPORT_RUNTIMEERROR_RECURSIONLIMIT      0u
/* Used to report Transient Fault recursion limit of Det module. */
#define DET_REPORT_TRANSIENTFAULT_RECURSIONLIMIT    0u

#endif  /* DET_CFG_H_ */
