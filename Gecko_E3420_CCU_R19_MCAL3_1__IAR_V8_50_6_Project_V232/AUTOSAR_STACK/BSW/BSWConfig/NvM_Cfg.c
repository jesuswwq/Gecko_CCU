
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
**  FILENAME    : NvM_Cfg.c                                                   **
**                                                                            **
**  Created on  : 2024/06/03 14:59:25                                 **
**  Author      : <>                                                          **
**  Vendor      :                                                             **
**  DESCRIPTION : Post-build configuration parameter of NvM                   **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/ 
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "NvM_Types.h"
#include "NvM_Cfg.h"

#include "Rte_Dem.h"

/********************************************************
 ****Container for NvmMultiBlockCallback
 ********************************************************/
#define NVM_START_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"
/* PRQA S 3408++ */ /* MISRA Rule 8.4 */
CONST(NvM_MultiBlockCallbackType, NVM_CONST) NvmMultiBlockCallback = NULL_PTR;
/* PRQA S 3408-- */ /* MISRA Rule 8.4 */
#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"

#define NVM_START_SEC_VAR_CLEARED_8
#include "NvM_MemMap.h"

/* PRQA S 1504++ */ /* MISRA Rule 8.7 */
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer1[2];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer2[17];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer3[30];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer4[16];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer5[16];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer6[9];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer7[16];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer8[1];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer9[7];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer10[12];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer11[8];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer12[5];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer13[40];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer14[5];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer15[5];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer16[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer17[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer18[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer19[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer20[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer21[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer22[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer23[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer24[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer25[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer26[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer27[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer28[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer29[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer30[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer31[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer32[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer33[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer34[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer35[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer36[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer37[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer38[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer39[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer40[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer41[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer42[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer43[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer44[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer45[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer46[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer47[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer48[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer49[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer50[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer51[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer52[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer53[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer54[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer55[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer56[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer57[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer58[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer59[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer60[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer61[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer62[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer63[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer64[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer65[36];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer66[588];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer67[16];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer68[64];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer69[256];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer70[20];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer71[10];
VAR(uint8, NVM_VAR_NOINIT) NvMBlockRamBuffer72[256];
/* PRQA S 1504-- */ /* MISRA Rule 8.7 */
#define NVM_STOP_SEC_VAR_CLEARED_8
#include "NvM_MemMap.h"

/********************************************************
 ****Container for a management structure to configure the
composition of a given NVRAM Block Management Type.
 ********************************************************/
#define NVM_START_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"
/* PRQA S 3408++ */ /* MISRA Rule 8.4 */
CONST(NvM_BlockDescriptorType, NVM_CONST) NvM_BlockDescriptor[NVM_BLOCK_NUM_ALL] =
/* PRQA S 3408-- */ /* MISRA Rule 8.4 */
{
    /*NvMBlock_ConfigID*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_REDUNDANT,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x3c,
       /*
        * Bit 0:NvmWriteBlockOnce
        * Bit 1:NvmBlockWriteProt
        * Bit 2:NvmCalcRamBlockCrc
        * Bit 3:NvmResistantToChangedSw
        * Bit 4:NvmSelectBlockForReadall
        * Bit 5:NvmSelectBlockForWriteall
        * Bit 6:NvMStaticBlockIDCheck
        * Bit 7:NvMWriteVerification
        * Bit 8:NvMBlockUseAutoValidation
        * Bit 9:NvMBlockUseCRCCompMechanism
        * Bit 10:NvMBlockUseSetRamBlockStatus
        * Bit 11:NvMBlockUseSyncMechanism
        * Bit 12:NvMBswMBlockStatusInformation
        */
        NVM_CRC16,    /*NvmBlockCRCType*/
        4,    /*NvmNvBlockBaseNumber*/
        2,    /*NvmNvBlockLength*/
        2,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
        /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer1),    /*NvmRamBlockDataAddress*/
        NULL_PTR,   /*NvmRomBlockDataAddress*/
         /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvmInitBlockCallback*/
        NULL_PTR,   /*NvmSingleBlockCallback*/
        NULL_PTR,   /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,   /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock1_DID_F190*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        8,    /*NvmNvBlockBaseNumber*/
        17,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer2),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock2_DID_F101*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        12,    /*NvmNvBlockBaseNumber*/
        30,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer3),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock3_DID_F157*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x22c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        16,    /*NvmNvBlockBaseNumber*/
        16,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer4),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock4_DID_F158*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        20,    /*NvmNvBlockBaseNumber*/
        16,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer5),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock5_DID_F086*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        24,    /*NvmNvBlockBaseNumber*/
        9,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer6),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock6_DID_F13A*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        28,    /*NvmNvBlockBaseNumber*/
        16,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer7),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock7_DID_F13B*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        32,    /*NvmNvBlockBaseNumber*/
        1,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer8),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock8_DID_F13C*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        36,    /*NvmNvBlockBaseNumber*/
        7,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer9),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock9_DID_F13D*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        40,    /*NvmNvBlockBaseNumber*/
        12,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer10),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock10_DID_F13E*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        44,    /*NvmNvBlockBaseNumber*/
        8,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer11),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock11_27Counter_Level1*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x3c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        48,    /*NvmNvBlockBaseNumber*/
        5,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer12),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock12_BL*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x3c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        52,    /*NvmNvBlockBaseNumber*/
        40,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer13),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock11_27Counter_Level5*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x3c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        64,    /*NvmNvBlockBaseNumber*/
        5,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer14),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock11_27Counter_Level7*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x3c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        68,    /*NvmNvBlockBaseNumber*/
        5,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer15),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_1*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        72,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer16),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_2*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        76,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer17),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_3*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        80,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer18),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_4*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        84,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer19),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_5*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        88,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer20),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_6*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        92,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer21),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_7*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        96,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer22),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_8*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        100,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer23),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_9*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        104,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer24),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_10*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        108,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer25),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_11*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        112,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer26),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_12*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        116,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer27),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_13*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        120,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer28),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_14*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        124,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer29),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_15*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        128,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer30),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_16*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        132,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer31),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_17*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        136,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer32),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_18*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        140,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer33),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_19*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        144,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer34),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_20*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        148,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer35),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_21*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        152,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer36),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_22*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        156,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer37),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_23*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        160,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer38),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_24*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        164,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer39),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_25*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        168,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer40),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_26*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        172,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer41),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_27*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        176,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer42),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_28*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        180,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer43),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_29*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        184,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer44),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_30*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        188,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer45),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_31*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        192,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer46),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_32*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        196,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer47),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_33*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        200,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer48),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_34*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        204,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer49),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_35*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        208,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer50),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_36*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        212,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer51),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_37*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        216,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer52),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_38*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        220,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer53),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_39*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        224,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer54),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_40*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        228,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer55),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_41*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        232,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer56),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_42*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x23c,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        236,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer57),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_43*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        240,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer58),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_44*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        244,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer59),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_45*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        248,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer60),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_46*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        252,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer61),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_47*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        256,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer62),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_48*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        260,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer63),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_49*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        264,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer64),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_EventEntryPrimary_50*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        268,    /*NvmNvBlockBaseNumber*/
        36,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer65),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_UDS_InternalData*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        272,    /*NvmNvBlockBaseNumber*/
        588,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer66),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_OBD_InternalData*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x234,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        276,    /*NvmNvBlockBaseNumber*/
        16,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer67),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_Swc_VCU_01_64*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x224,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        280,    /*NvmNvBlockBaseNumber*/
        64,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer68),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_Swc_TMS*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x224,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        284,    /*NvmNvBlockBaseNumber*/
        256,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer69),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_Swc_BCM_IMM_20*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x224,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        287,    /*NvmNvBlockBaseNumber*/
        20,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer70),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_Swc_BCM_PD_10*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x224,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        291,    /*NvmNvBlockBaseNumber*/
        10,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer71),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
    /*NvMBlock_Swc_BCM_PEPS_256*/
    {
        0,    /*NvMNvramDeviceId*/
        NVM_BLOCK_NATIVE,    /*NvmBlockManagementType*/
        #if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
        1,      /*NvmBlockJobPriority*/
        #endif
        0x224,
        /*
         * Bit 0:NvmWriteBlockOnce
         * Bit 1:NvmBlockWriteProt 
         * Bit 2:NvmCalcRamBlockCrc
         * Bit 3:NvmResistantToChangedSw 
         * Bit 4:NvmSelectBlockForReadall 
         * Bit 5:NvmSelectBlockForWriteall 
         * Bit 6:NvMStaticBlockIDCheck
         * Bit 7:NvMWriteVerification
         * Bit 8:NvMBlockUseAutoValidation
         * Bit 9:NvMBlockUseCRCCompMechanism
         * Bit 10:NvMBlockUseSetRamBlockStatus
         * Bit 11:NvMBlockUseSyncMechanism
         * Bit 12:NvMBswMBlockStatusInformation
         */    
        NVM_CRC16,    /*NvmBlockCRCType*/
        295,    /*NvmNvBlockBaseNumber*/
        256,    /*NvmNvBlockLength*/
        1,    /*NvmNvBlockNum*/
        0,    /*NvmRomBlockNum*/
        3,    /*NvMMaxNumOfReadRetries*/
        3,    /*NvMMaxNumOfWriteRetries*/
        0,    /*NvMWriteVerificationDataSize*/
         /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        (P2VAR(uint8, AUTOMATIC, NVM_APPL_CODE))(NvMBlockRamBuffer72),    /*NvMRamBlockDataAddress*/
        NULL_PTR,   /*NvMRomBlockDataAddress*/
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        NULL_PTR,   /*NvMInitBlockCallback*/
        NULL_PTR,    /*NvmSingleBlockCallback*/
        NULL_PTR,    /*NvM_ReadRamBlockFromNvmCallbackType*/
        NULL_PTR,       /*NvM_WriteRamBlockToNvmCallbackType*/
    },
};
#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"

#if ((NVM_API_CONFIG_CLASS_1!=NVM_API_CONFIG_CLASS)&&(STD_ON==NVM_JOB_PRIORITIZATION))
#define NVM_START_SEC_VAR_POWER_ON_INIT_16
#include "NvM_MemMap.h"
/* PRQA S 3408++ */ /* MISRA Rule 8.4 */
VAR(uint16, NVM_VAR_POWER_ON_INIT) NvM_PriorityTable[2][NVM_TABLE_SIZE_PRIORITY] =
/* PRQA S 3408-- */ /* MISRA Rule 8.4 */
{

    {
        0x0000U,0x0000U
    },
    {
        0x0000U,0x0000U
    }
};
#define NVM_STOP_SEC_VAR_POWER_ON_INIT_16
#include "NvM_MemMap.h"
#endif
/*******************************************************************************
**                           End Of File                                      **
*******************************************************************************/

