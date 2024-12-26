/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Rte_Data.c>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for ${tmpl} Module>
 *
 *  @author     <Your Name>
 *  @date       <2023-12-04 09:44:48>
 *
 *
 *
 *  May be changed by User [yes/no]: no
 */
/*============================================================================*/
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/** <VERSION>   <DATE>      <AUTHOR>     <REVISION LOG>
 *
 */
/*@{*/
#define RTE_FL_C
/*@}*/
/*=======[I N C L U D E S]====================================================*/
/*=======[Includes]===========================================================*/
/*@{*/
#include "Rte_Fl.h"
#include "NvMem.h"
#include "FL_Type.h"
#include "DP.h"
#include "FLashIf.h"
#include "Appl_CallOut.h"

#include "Fee.h"
#include "Rte_Inc.h"
/*@}*/
/*=======[Private define]=====================================================*/
/*@{*/
tFlashParam dFlashIfParamInfo
 = {
    (uint8)FLASH_DRIVER_VERSION_PATCH,
    (uint8)FLASH_DRIVER_VERSION_MINOR,
    (uint8)FLASH_DRIVER_VERSION_MAJOR,
    FLASH_UNINIT,
    (uint8)kFlashOk,
    (uint16)0x0000U,
    (uint32)0UL,
    (uint32)0UL,
    NULL_PTR,
    NULL_PTR,
#if (APPL_ENABLE_WATCHDOG_MONITORING_IN_BOOT == STD_ON)
    &Appl_wdTriggerFct
#else
    NULL_PTR
#endif
};
/*@}*/
/*=======[Private types]======================================================*/
/*@{*/
/*@}*/
/*=======[Private function prototypes]========================================*/
/*@{*/
FL_ResultType Rte_FL_flashInit(tFlashParam * ParamInfoPtr)
{
    FL_ResultType retVal = (uint8)FL_FAILED;
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK Rte_Dcm_flashEraseWriteFct>
    */

    if(NULL_PTR == ParamInfoPtr)
    {

    }
    else  if(((uint8)FLASH_DRIVER_VERSION_PATCH != ParamInfoPtr->patchLevel)
    ||((uint8)FLASH_DRIVER_VERSION_MINOR != ParamInfoPtr->minorNumber)
    ||((uint8)FLASH_DRIVER_VERSION_MAJOR != ParamInfoPtr->majorNumber))
    {
    }
    else if(TRUE == NvMemInit())
    {
        retVal = (uint8) FL_FAILED;
        ParamInfoPtr->flashstatus = FLASH_INIT;
    }
    else
    {
        /*do nothing*/
    }
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
    return retVal;
}
/**********************************************************************************************/
/**
 * @brief               <flash erases and writes encapsulation functions.>
 * <Flash erases and writes encapsulation functions.> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <ParamInfoPtr: Parameter information pointer.>
 * @return              <FL_ResultType>
 */
/**********************************************************************************************/
FL_ResultType Rte_FL_flashEraseWriteFct(tFlashParam * ParamInfoPtr)
{
    FL_ResultType retVal = (uint8)FL_FAILED;
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK Rte_Dcm_flashEraseWriteFct>
    */
    if(NULL_PTR == ParamInfoPtr)
    {

    }
    else if(((uint8)FLASH_DRIVER_VERSION_PATCH != ParamInfoPtr->patchLevel)
       ||((uint8)FLASH_DRIVER_VERSION_MINOR != ParamInfoPtr->minorNumber)
       ||((uint8)FLASH_DRIVER_VERSION_MAJOR != ParamInfoPtr->majorNumber))
    {
    }
    else if(ParamInfoPtr->flashstatus == FLASH_INIT)
    {
        if(TRUE == NvMemWrite(ParamInfoPtr->address,ParamInfoPtr->data,ParamInfoPtr->length))
        {
            retVal = (uint8) FL_OK;
        }
    }
    else
    {
        /*do nothing*/
    }
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
    return retVal;
}
/**********************************************************************************************/
/**
 * @brief               <flash erases and writes encapsulation functions.>
 * <Flash erases and writes encapsulation functions.> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <ParamInfoPtr: Parameter information pointer.>
 * @return              <FL_ResultType>
 */
/**********************************************************************************************/
FL_ResultType Rte_FL_flashReadFct(tFlashParam * ParamInfoPtr)
{
    FL_ResultType retVal = (uint8)FL_FAILED;
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK Rte_Dcm_flashEraseWriteFct>
    */
    if(NULL_PTR == ParamInfoPtr)
    {

    }
    else if(((uint8)FLASH_DRIVER_VERSION_PATCH != ParamInfoPtr->patchLevel)
       ||((uint8)FLASH_DRIVER_VERSION_MINOR != ParamInfoPtr->minorNumber)
       ||((uint8)FLASH_DRIVER_VERSION_MAJOR != ParamInfoPtr->majorNumber))
    {
    }
    else if(ParamInfoPtr->flashstatus == FLASH_INIT)
    {
        if(TRUE == NvMemRead(ParamInfoPtr->address,ParamInfoPtr->readData,ParamInfoPtr->length))
        {
            retVal = (uint8) FL_OK;
        }
    }
    else
    {
        /*do nothing*/
    }
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
    return retVal;
}
/*@}*/
/*=======[Private variables]==================================================*/
/*@{*/
/*@}*/
/*=======[Private functions]==================================================*/
/*@{*/
/*@}*/
/*===========================[22 Service Configure]===========================*/
/*=======[F U N C T I O N   I M P L E M E N T A T I O N S]====================*/
/******************************************************************************/
/*
 * @brief              [_Reverse16 description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [input      description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
static void reverse16(uint16* input)
{
    struct reverse16
    {
        uint8 L;
        uint8 H;
    } ;

    uint16 output = 0u;

    ((struct reverse16*) &output)->H = ((struct reverse16*) input)->L;/*PRQA S 0310*/
    ((struct reverse16*) &output)->L = ((struct reverse16*) input)->H;/*PRQA S 0310*/
    *input = output;
}

/*==============================internal Service ===================================*/
/******************************************************************************/
/*
 * @brief              [Rte_Data_Write_NvmInfo description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [info                   description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_Data_Write_NvmInfo(uint8 *info)
{
    boolean ret = FALSE;
    uint32 addr = RTE_DATA_NVMINFO_ADDR;
    uint8 len = RTE_DATA_NVMINFO_LEN;
#if (RTE_PARTITION_SWAP_ON == STD_ON)
    if(TRUE == Rte_ABSwap_isA())
    {
        addr = RTE_DATA_NVMINFO_B_ADDR;
        len = RTE_DATA_NVMINFO_B_LEN;
    }
#endif
    ret = NvMemWrite(addr, info, len);
    return ret;
}
/******************************************************************************/
/*
 * @brief              [Rte_Data_Read_NvmInfo description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [info                  description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_Data_Read_NvmInfo(uint8 *info)
{
    boolean ret = FALSE;
    uint32 addr = RTE_DATA_NVMINFO_ADDR;
    uint8 len = RTE_DATA_NVMINFO_LEN;
#if (RTE_PARTITION_SWAP_ON == STD_ON)
    if(TRUE == Rte_ABSwap_isA())
    {
        addr = RTE_DATA_NVMINFO_B_ADDR;
        len = RTE_DATA_NVMINFO_B_LEN;
    }
#endif
    ret = NvMemRead(addr, info, len);
    return ret;
}
/******************************************************************************/
/*
 * @brief              [Rte_Data_Write_Fingerprint description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [appPrint                   description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_Data_Write_Fingerprint(const uint8 *appPrint)
{
    boolean ret = FALSE;
    ret = NvMemWrite(RTE_DATA_FINGER_ADDR, appPrint, RTE_DATA_FINGER_LEN);
    return ret;
}
/******************************************************************************/
/*
 * @brief              [Rte_Data_Read_Fingerprint description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [Counter                   description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_Data_Read_Fingerprint(uint8 *Counter)
{
    boolean ret = FALSE;/*PRQA S 2981*/
    ret = NvMemRead(RTE_DATA_FINGER_ADDR, Counter, RTE_DATA_FINGER_LEN);
    return ret;
}
/******************************************************************************/
/*
 * @brief              [Rte_Data_Write_Factory description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [Counter                description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_Data_Write_Factory(uint8 Counter)
{
    boolean ret = FALSE;/*PRQA S 2981*/
    ret = NvMemWrite(RTE_DATA_FACTORY_ADDR, &Counter, RTE_DATA_FACTORY_LEN);
    return ret;
}
/******************************************************************************/
/*
 * @brief              [Rte_Data_Read_Factory description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [Counter               description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_Data_Read_Factory(uint8 *Counter)
{
    boolean ret = FALSE;/*PRQA S 2981*/
    ret = NvMemRead(RTE_DATA_FACTORY_ADDR, Counter, RTE_DATA_FACTORY_LEN);
    return ret;
}
/******************************************************************************/
/*
 * @brief              [Rte_Data_Write_ProgramAttemptCounter description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [Counter                              description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_Data_Write_ProgramAttemptCounter(uint16 Counter)
{
    boolean ret = FALSE;
    reverse16(&Counter);
    ret = NvMemWrite(RTE_DATA_PROGRAM_COUNTER_ADDR, (uint8*)&Counter, RTE_DATA_PROGRAM_COUNTER_LEN);
    return ret;
}
/******************************************************************************/
/*
 * @brief              [Rte_Data_Read_ProgramAttemptCounter description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [Counter                             description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_Data_Read_ProgramAttemptCounter(uint16 *Counter)
{
    boolean ret = FALSE;/*PRQA S 2981*/
    ret = NvMemRead(RTE_DATA_PROGRAM_COUNTER_ADDR, (uint8*)Counter, RTE_DATA_PROGRAM_COUNTER_LEN);
    reverse16(&Counter[0]);
    return ret;
}
/******************************************************************************/
/*
 * @brief              [Rte_Data_Write_ProgramSuccessCounter description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [Counter                              description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_Data_Write_ProgramSuccessCounter(uint16 Counter)
{
    boolean ret = FALSE;
    reverse16(&Counter);
    ret = NvMemWrite(RTE_DATA_PROGRAM_SUC_COUNTER_ADDR, (uint8*)&Counter, RTE_DATA_PROGRAM_SUC_COUNTER_LEN);
    return ret;
}
/******************************************************************************/
/*
 * @brief              [Rte_Data_Read_ProgramSuccessCounter description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [Counter                             description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_Data_Read_ProgramSuccessCounter(uint16 *Counter)
{
    boolean ret = FALSE;/*PRQA S 2981*/
    ret = NvMemRead(RTE_DATA_PROGRAM_SUC_COUNTER_ADDR, (uint8*)Counter, RTE_DATA_PROGRAM_SUC_COUNTER_LEN);
    reverse16(&Counter[0]);
    return ret;
}
/******************************************************************************/
/*
 * @brief              [Rte_Data_Write_SecurityAccess description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [Counter                       description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_Data_Write_SecurityAccess(uint8 idx,uint8 Counter)
{
    boolean ret = FALSE;
    ret = NvMemWrite(RTE_DATA_SEC_ERR_COUNTER_ADDR, &Counter, RTE_DATA_SEC_ERR_COUNTER_LEN);
    return ret;
}
/******************************************************************************/
/*
 * @brief              [Rte_Data_Read_SecurityAccess description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [Counter                      description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_Data_Read_SecurityAccess(uint8 idx,uint8 *Counter)
{
    boolean ret = FALSE;/*PRQA S 2981*/
    ret = NvMemRead(RTE_DATA_SEC_ERR_COUNTER_ADDR, Counter, RTE_DATA_SEC_ERR_COUNTER_LEN);
    return ret;
}
/******************************************************************************/
/*
 * @brief              [Rte_Data_Write_ClientErrStatus description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [Counter                        description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_Data_Write_ClientErrStatus(uint8 *Counter)
{
    boolean ret = FALSE;
    ret = NvMemWrite(RTE_DATA_CLIENT_ERR_ADDR, Counter, RTE_DATA_CLIENT_ERR_LEN);
    return ret;
}
/******************************************************************************/
/*
 * @brief              [Rte_Data_Read_ClientErrStatus description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [Counter                       description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_Data_Read_ClientErrStatus(uint8 *Counter)
{
    boolean ret = FALSE;
    ret = NvMemRead(RTE_DATA_CLIENT_ERR_ADDR, Counter, RTE_DATA_CLIENT_ERR_LEN);
    return ret;
}
/******************************************************************************/
/*
 * @brief              [Rte_Data_Write_PROGRAM_Flag description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [Counter                     description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_Data_Write_PROGRAM_Flag(uint8* Counter)
{
//    boolean ret = FALSE;
//    ret = NvMemWrite(RTE_DATA_PROGRAM_FLAG_ADDR, Counter, RTE_DATA_PROGRAM_FLAG_LEN);
//    return ret;
    boolean ret = FALSE;
#ifdef PROJECT_SPECIAL
    uint64 TCM_INIT = 0;
    (*(uint64 *) RTE_DATA_PROGRAM_FLAG_ADDR) = TCM_INIT;
#endif
    DP_Memcpy((uint8*)RTE_DATA_PROGRAM_FLAG_ADDR, Counter, RTE_DATA_PROGRAM_FLAG_LEN);
    ret = TRUE;
    return ret;
}
/******************************************************************************/
/*
 * @brief              [Rte_Data_Read_PROGRAM_Flag description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [Counter                    description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_Data_Read_PROGRAM_Flag(uint8 *Counter)
{
//    boolean ret = FALSE;
//    ret = NvMemRead(RTE_DATA_PROGRAM_FLAG_ADDR, Counter, RTE_DATA_PROGRAM_FLAG_LEN);
//    return ret;
    boolean ret = FALSE;
    DP_Memcpy(Counter, (uint8*)RTE_DATA_PROGRAM_FLAG_ADDR, RTE_DATA_PROGRAM_FLAG_LEN);
    ret = TRUE;
    return ret;
}
/******************************************************************************/
/*
 * @brief              [Rte_Data_Write_RESET_JUMP_Flag description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [Counter                        description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_Data_Write_RESET_JUMP_Flag(uint8* Counter)
{
    boolean ret = FALSE;
#ifdef PROJECT_SPECIAL
    uint64 TCM_INIT = 0;
    (*(uint64 *) RTE_DATA_RESET_JUMP_FLAG_ADDR) = TCM_INIT;
#endif
	DP_Memcpy((uint8*)RTE_DATA_RESET_JUMP_FLAG_ADDR, Counter, RTE_DATA_RESET_JUMP_FLAG_LEN);
    ret = TRUE;
    return ret;
}
/******************************************************************************/
/*
 * @brief              [Rte_Data_Read_RESET_JUMP_Flag description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [Counter                       description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_Data_Read_RESET_JUMP_Flag(uint8 *Counter)
{
    boolean ret = FALSE;
    DP_Memcpy(Counter, (uint8*)RTE_DATA_RESET_JUMP_FLAG_ADDR, RTE_DATA_RESET_JUMP_FLAG_LEN);
    ret = TRUE;
    return ret;
}
/******************************************************************************/
/*
 * @brief              [Rte_Data_Write_RESET_JUMP_Flag description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [Counter                        description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_Data_Write_RESET_CAUSE(uint8* Counter)
{
    boolean ret = FALSE;
#ifdef PROJECT_SPECIAL
    uint64 TCM_INIT = 0;
    (*(uint64 *) RTE_DATA_RESETCAUSE_TCM_ADDR) = TCM_INIT;
#endif
	DP_Memcpy((uint8*)RTE_DATA_RESETCAUSE_TCM_ADDR, Counter, RTE_DATA_RESETCAUSE_TCM_LEN);
    ret = TRUE;
    return ret;
}

boolean Rte_Data_Write_JUMP_VECTOR_INFO (uint32 addr)
{
    boolean ret;
#ifdef PROJECT_SPECIAL
    uint64 TCM_INIT = 0;
    (*(uint64 *) RTE_DATA_VECTOR_APP_ADDR) = TCM_INIT;
#endif
    (*(uint64 *) RTE_DATA_VECTOR_APP_ADDR) = addr;
    ret = TRUE;
    return ret;
}
boolean Rte_Data_Write_A_Part_Count(uint32 Counter)
{
    boolean ret = FALSE;
    ret = NvMemWrite(RTE_DATA_A_PART_COUNT_ADDR,(uint8 *)&Counter,RTE_DATA_A_PART_COUNT_LEN);
    return ret;
}
boolean Rte_Data_Read_A_Part_Count(uint32 *Counter)
{
    boolean ret = FALSE;
    ret = NvMemRead(RTE_DATA_A_PART_COUNT_ADDR,(uint8 *)&Counter[0],RTE_DATA_A_PART_COUNT_LEN);
    return ret;
}
boolean Rte_Data_Write_B_Part_Count(uint32 Counter)
{
    boolean ret = FALSE;
    ret = NvMemWrite(RTE_DATA_B_PART_COUNT_ADDR,(uint8 *)&Counter,RTE_DATA_B_PART_COUNT_LEN);
    return ret;
}
boolean Rte_Data_Read_B_Part_Count(uint32 *Counter)
{
    boolean ret = FALSE;
    ret = NvMemRead(RTE_DATA_B_PART_COUNT_ADDR,(uint8 *)&Counter[0],RTE_DATA_B_PART_COUNT_LEN);
    return ret;
}
boolean Rte_Data_Write_ForceSwap(uint8 Counter)
{
    boolean ret = FALSE;
    ret = NvMemWrite(RTE_DATA_FORC_SWAP_ADDR,(uint8 *)&Counter,RTE_DATA_FORC_SWAP_LEN);
    ret = TRUE;
    return ret;
}
boolean Rte_Data_Read_ForceSwap(uint8 *Counter)
{
    boolean ret = FALSE;
    ret = NvMemRead(RTE_DATA_FORC_SWAP_ADDR,(uint8 *)&Counter[0],RTE_DATA_FORC_SWAP_LEN);
    return ret;
}
boolean Rte_Data_Write_FingerprintB(uint8 *appPrint)
{
    boolean ret = FALSE;
    ret = NvMemWrite(RTE_DATA_FINGERB_ADDR, appPrint, RTE_DATA_FINGERB_LEN);
    return ret;
}
boolean Rte_Data_Read_FingerprintB(uint8 *Counter)
{
    boolean ret = FALSE;
    ret = NvMemRead(RTE_DATA_FINGERB_ADDR, Counter, RTE_DATA_FINGERB_LEN);
    return ret;
}
void Rte_Data_Write_Fingerprint_to_App(void)
{
#if (RTE_PARTITION_SWAP_ON == STD_ON)
    uint32 aAddr = 0;
    uint32 bAddr = 0;
    uint8 finger[RTE_DATA_FINGER_LEN];
    uint8 fingerB[RTE_DATA_FINGERB_LEN];
    if(TRUE == Rte_ABSwap_isA())
    {
        aAddr = RTE_DATA_FINGER_TO_ACT_TCM_ADDR;
        bAddr = RTE_DATA_FINGER_TO_IACT_TCM_ADDR;
    }
    else
    {
        aAddr = RTE_DATA_FINGER_TO_IACT_TCM_ADDR;
        bAddr = RTE_DATA_FINGER_TO_ACT_TCM_ADDR;
    }
    if(Rte_Data_Read_Fingerprint(finger))
    {
        DP_Memcpy((uint8*)aAddr,finger,RTE_DATA_FINGER_LEN);
    }
    if(Rte_Data_Read_FingerprintB(fingerB))
    {
        DP_Memcpy((uint8*)bAddr,fingerB,RTE_DATA_FINGERB_LEN);
    }
#endif
}
/*=======[E N D   O F   F I L E]==============================================*/
