/*******************************************************************************
**                                                                            **
** Copyright(C)iSOFT (2022)                                                   **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document,and communication                  **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : WdgIf_Types.h                                               **
**                                                                            **
**  Created on  :                                                             **
**  Author      : haibin.shao                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S):   AUTOSAR classic Platform R19-11                       **
**                                                                            **
*******************************************************************************/
#ifndef WDGIF_TYPES_H
#define WDGIF_TYPES_H

/*===========================[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>     <AUTHOR>         <REVISION LOG>
 *  V1.0.0       20150127   pinghai.xiong    Initial version
 *  V1.0.1       20221222   peng.wu          Modify the head and version info
 */
/*================================================================================================*/

/*===========================[V E R S I O N  I N F O R M A T I O N]===============================*/
#define WDGIF_TYPES_H_AR_MAJOR_VERSION 4U
#define WDGIF_TYPES_H_AR_MINOR_VERSION 5U
#define WDGIF_TYPES_H_AR_PATCH_VERSION 0U
#define WDGIF_TYPES_H_SW_MAJOR_VERSION 1U
#define WDGIF_TYPES_H_SW_MINOR_VERSION 0U
#define WDGIF_TYPES_H_SW_PATCH_VERSION 1U

/*===========================[I N C L U D E S]====================================================*/
/*===========================[M A C R O S]========================================================*/
/*===========================[T Y P E   D E F I N I T I O N S]====================================*/
/* Type of WDG Mode */
typedef enum
{
    /* OFF Mode */
    WDGIF_OFF_MODE = 0u,
    /* SLOW Mode */
    WDGIF_SLOW_MODE,
    /* FAST Mode */
    WDGIF_FAST_MODE
} WdgIf_ModeType;

/*===========================[E X T E R N A L   D A T A]==========================================*/
/*===========================[E X T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/

#endif /* WDGIF_TYPES_H */
