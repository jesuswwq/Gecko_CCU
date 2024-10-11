/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte.h>
 *  @brief      <>
 *
 *  
 *  @author     <>
 */
/*============================================================================*/

/* Rte.h */

#ifndef RTE_H
#define RTE_H

/*******************************************************************************
 **                        Revision Control History                           **
******************************************************************************/

/*******************************************************************************
 **                        Version Information                                **
******************************************************************************/

/*******************************************************************************
 **                        Include Section                                    **
******************************************************************************/
#include "Std_Types.h"

/* Errors */
#define RTE_E_OK                    ((Std_ReturnType) 0U)
#define RTE_E_INVALID               ((Std_ReturnType) 1U)
#define RTE_E_COM_STOPPED           ((Std_ReturnType) 128U)
#define RTE_E_COM_BUSY              ((Std_ReturnType) 141U)
#define RTE_E_TIMEOUT               ((Std_ReturnType) 129U)
#define RTE_E_LIMIT                 ((Std_ReturnType) 130U)
#define RTE_E_NO_DATA               ((Std_ReturnType) 131U)
#define RTE_E_TRANSMIT_ACK          ((Std_ReturnType) 132U)
#define RTE_E_NEVER_RECEIVED        ((Std_ReturnType) 133U)
#define RTE_E_UNCONNECTED           ((Std_ReturnType) 134U)
#define RTE_E_SEG_FAULT             ((Std_ReturnType) 136U)
#define RTE_E_HARD_TRANSFORMER_ERROR            ((Std_ReturnType) 138U)
#define RTE_E_SOFT_TRANSFORMER_ERROR  ((Std_ReturnType) 140U)
#define RTE_E_WAITING               ((Std_ReturnType) 142U)
/* Overlayd errors */
#define RTE_E_LOST_DATA             ((Std_ReturnType) 64U)
#define RTE_E_MAX_AGE_EXCEEDED      ((Std_ReturnType) 64U)
#define Rte_IsInfrastructureError(status) ((status & 128U) !=0U)
#define Rte_HasOverlayedError(status) ((status & 64U) != 0U)
#define Rte_ApplicationError(status) (status & 63U)
#define RTE_FLAG_INVALID            (uint8) 2
#define RTE_FLAG_COM_STOPPED        (uint8) 4
#define RTE_FLAG_TX_TIMEOUT         (uint8) 8
#define RTE_FLAG_RX_TIMEOUT         (uint8) 16
#define RTE_FLAG_TRANSMIT_ACK       (uint8) 64
typedef uint8 Rte_TransformerErrorCode;
typedef uint8 Rte_TransformerClass;
typedef struct  {
   Rte_TransformerErrorCode errorCode;
   Rte_TransformerClass transformerClass;
}Rte_TransformerError;
#define RTE_TRANSFORMER_UNSPECIFIED     ((Rte_TransformerClass)0u)
#define RTE_TRANSFORMER_SERIALIZER      ((Rte_TransformerClass)1u)
#define RTE_TRANSFORMER_SAFETY          ((Rte_TransformerClass)2u)
#define RTE_TRANSFORMER_SECURITY        ((Rte_TransformerClass)3u)
#define RTE_TRANSFORMER_CUSTOM          ((Rte_TransformerClass)255u)
/* SchM Errors */
#define SCHM_E_OK                   ((Std_ReturnType) 0U)
#define SCHM_E_LIMIT                ((Std_ReturnType) 130U)
#define SCHM_E_NO_DATA              ((Std_ReturnType) 131U)
#define SCHM_E_TRANSMIT_ACK         ((Std_ReturnType) 132U)
#define SCHM_E_IN_EXCLUSIVE_AREA    ((Std_ReturnType) 135U)
#define SCHM_E_IN_TIMEOUT           ((Std_ReturnType) 129U)
#define SCHM_E_DEV_DEFECT           ((Std_ReturnType) 191U)

#endif

