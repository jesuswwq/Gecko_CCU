/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2023)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : Rte_Dcm.c                                                   **
**                                                                            **
**  Created on  : 2024/02/29 16:48:47                                         **
**  Author      : chunjun.hua                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Callout function for Dcm                                    **
**                                                                            **
**  SPECIFICATION(S) :   NONE                                                 **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *  V1.0.0      20231207   chunjun.hua       Initial Version
 */

/*******************************************************************************
**                      Include                                               **
*******************************************************************************/
#include "Rte_Dcm.h"
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
#include "Fee.h"
#include "Rte_Inc.h"
/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

#define DataLength_DcmDspData_0xF084 10u
#define DataLength_DcmDspData_0xF085 10u
#define DataLength_DcmDspData_0xF15B 10u
static const uint8 defaultValue0xF084[DataLength_DcmDspData_0xF084] ={ 0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,};
static const uint8 defaultValue0xF085[DataLength_DcmDspData_0xF085] ={ 0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,};
static const uint8 defaultValue0xF15B[DataLength_DcmDspData_0xF15B] ={ 0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,};
static const did_Group_Type didF15A = {RTE_DID_STORAGE_IN_EEP, DataLength_DcmDspData_0xF15B, 0xF15Au, RTE_DATA_DIDF15A_ADDR};
static const did_Group_Type didF15B = {RTE_DID_STORAGE_IN_EEP, DataLength_DcmDspData_0xF15B, 0xF15Bu, RTE_DATA_DIDF15B_ADDR};

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/**
 *         const did_Group_Type didF183 = {RTE_DID_STORAGE_IN_RAM, RTE_DATA_FINGER_LEN, 0xF183, (uint32)&BootloaderFingerTemp};
 *         FL_ResultType FL_ReadDIDGroupXXXX(uint8* readData,uint16* readLength)
 *         {
 *             FL_ResultType ret;
 *             boolean     processContinue = FALSE;
 *             processContinue = Rte_FL_ReadDidGroup(&didGroupXXXX,readData, readLength);
 *             if(TRUE == processContinue)
 *             {
 *                 ret = FL_OK;
 *             }
 *             else
 *             {
 *                 ret = FL_FAILED;
 *             }
 *             return (ret);
 *         }
 *         FL_ResultType FL_WriteDIDGroupXXXX(const uint8 *data, const uint16 length)
 *         {
 *             FL_ResultType ret;
 *             boolean     processContinue = FALSE;
 *             processContinue = Rte_FL_WriteDidGroup(&DID_ADDR_XXXX,data, length);
 *             if(TRUE == processContinue)
 *             {
 *                 ret = FL_OK;
 *             }
 *             else
 *             {
 *                 ret = FL_FAILED;
 *             }
 *             return (ret);
 *         }
 */
/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*==============================22 Service ===================================*/
/******************************************************************************/
/*
 * @brief              [Rte_Dcm_0xF084_ReadData description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [readData                description]
 *                     [readLength              description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
FL_ResultType Rte_Dcm_0xF084_ReadData(uint8* readData, uint16* readLength)
{
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK 0xF084_ReadData>
    */
    FL_ResultType ret;
    boolean     processContinue = FALSE;/*PRQA S 2981*/
#if (RTE_PARTITION_SWAP_ON == STD_ON)
    if(TRUE == Rte_ABSwap_isA())
    {
        processContinue = Rte_Data_Read_FingerprintB((uint8*)readData);
    }
    else
    {
        processContinue = Rte_Data_Read_Fingerprint((uint8*)readData);
    }
#endif
    *readLength = DataLength_DcmDspData_0xF084;
    if(TRUE == processContinue)
    {
        ret = FL_OK;
    }
    else
    {
        DP_Memcpy(readData,defaultValue0xF084,DataLength_DcmDspData_0xF084);
        ret = FL_OK;
    }
    return (ret);
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
}
/******************************************************************************/
/*
 * @brief              [Rte_Dcm_0xF085_ReadData description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [readData                description]
 *                     [readLength              description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
FL_ResultType Rte_Dcm_0xF085_ReadData(uint8* readData, uint16* readLength)
{
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK 0xF085_ReadData>
    */
    FL_ResultType ret;
    boolean     processContinue = FALSE;/*PRQA S 2981*/
#if (RTE_PARTITION_SWAP_ON == STD_ON)
    if(TRUE == Rte_ABSwap_isA())
    {
        processContinue = Rte_Data_Read_Fingerprint((uint8*)readData);
    }
    else
    {
        processContinue = Rte_Data_Read_FingerprintB((uint8*)readData);
    }
#endif
    *readLength = DataLength_DcmDspData_0xF085;
    if(TRUE == processContinue)
    {
        ret = FL_OK;
    }
    else
    {
        DP_Memcpy(readData,defaultValue0xF085,DataLength_DcmDspData_0xF085);
        ret = FL_OK;
    }
    return (ret);
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
}
/******************************************************************************/
/*
 * @brief              [Rte_Dcm_0xF15B_ReadData description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [readData                description]
 *                     [readLength              description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
FL_ResultType Rte_Dcm_0xF15B_ReadData(uint8* readData,uint16* readLength)
{
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK 0xF15B_ReadData>
    */
    FL_ResultType ret;
    boolean     processContinue = FALSE;/*PRQA S 2981*/
#if (RTE_PARTITION_SWAP_ON == STD_ON)
    if(TRUE == Rte_ABSwap_isA())
    {
        processContinue = Rte_Data_Read_Fingerprint((uint8*)readData);
    }
    else
    {
        processContinue = Rte_Data_Read_FingerprintB((uint8*)readData);
    }
#else	
    processContinue = Rte_FL_ReadDidGroup(&didF15B,readData, readLength);
#endif
    *readLength = DataLength_DcmDspData_0xF15B;
    if(TRUE == processContinue)
    {
        ret = FL_OK;
    }
    else
    {
        DP_Memcpy(readData,defaultValue0xF15B,DataLength_DcmDspData_0xF15B);
        ret = FL_OK;
    }
    return (ret);
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
}
/*==============================2E Service ===================================*/
/******************************************************************************/
/*
 * @brief              [Rte_Dcm_FingerPrint_0xF15A_WriteData description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [data                                 description]
 *                     [length                               description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
FL_ResultType Rte_Dcm_FingerPrint_0xF15A_WriteData(const uint8* data, const uint16 length) /*PRQA S 3206*/
{
    FL_ResultType ret = FL_CONDITIONS_NOT_CORRECT; 
    boolean     processContinue = FALSE;
    uint8 tempData[DataLength_DcmDspData_0xF15B];
    if(TRUE == FL_GetFLDownloaded())
    {
        processContinue = TRUE;
    }

    if(TRUE == processContinue)
    {
        ret = FL_FAILED;
        tempData[0] = 0u;
        DP_Memcpy(&tempData[1],data,length);
        Dcm_SendPending();
#if (RTE_PARTITION_SWAP_ON == STD_ON)
        if(TRUE == Rte_ABSwap_isA())
        {
            processContinue = Rte_Data_Write_FingerprintB((uint8*)tempData);
        }
        else
        {
            processContinue = Rte_Data_Write_Fingerprint((uint8*)tempData);
        }
        Rte_Data_Write_Fingerprint_to_App();
#else
        processContinue = Rte_FL_WriteDidGroup(&didF15A,(uint8*)tempData, sizeof(tempData));
#endif
    }

    if(TRUE == processContinue)
    {
        Dcm_SetFingerPrintWrittenStatus();
        ret = FL_OK;
    }
    return (ret);
}
/*==============================27 Service ===================================*/
/******************************************************************************/
/**
 * @brief               <compute key>
 *
 * <compute key before compute key> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <seed (IN), k (IN)>
 * @param[out]          <key (OUT)>
 * @param[in/out]       <NONE>
 * @return              <SecM_StatusType>
 */
/******************************************************************************/

SecM_StatusType Rte_Dcm_SecMComputeKey(const SecM_SeedType* seed, const SecM_WordType mask, SecM_KeyType* key)
{
    SecM_StatusType retVal = SECM_OK;
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK SecMComputeKey>
    */
    SecM_ComputeKey_BiHu(seed, DCM_SEED_MAX_LENGTH,
                          mask, SECM_SECCONST_LENGTH,
                          key, DCM_KEY_MAX_LENGTH);
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
    return retVal;
}

/*==============================31 Service ===================================*/
void Rte_Dcm_CheckProgPreCondition_0xFF02(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff)
{
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK 0xFF02>
    */
    Dcm_CheckProgPreCondition(rxBuff,txBuff);
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
}

void Rte_Dcm_EraseMemory_0xFF00(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff)
{
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK 0xFF00>
    */
    Dcm_EraseMemory(rxBuff,txBuff);
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
}

void Rte_Dcm_CheckMemory_0xF001(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff)
{
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK 0xF001>
    */
    Dcm_CheckMemory(rxBuff,txBuff);
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
}

void Rte_Dcm_CheckProgDependencies_0xFF01(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff)
{
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK 0xFF01>
    */
    Dcm_CheckProgDependencies(rxBuff,txBuff);
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
}

void Rte_Dcm_SwapSwitch_0xF017(const Dcm_BuffType* rxBuff, Dcm_BuffType* txBuff)
{
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK 0xF017>
    */
    Dcm_SwapSwitch(rxBuff,txBuff);
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
}

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

/*=======[E N D   O F   F I L E]==============================================*/
