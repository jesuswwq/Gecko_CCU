/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Rte_SegmentCheck.c>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for ${tmpl} Module>
 *
 *  @author     <Your Name>
 *  @date       <2024-01-03 18:06:50>
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
#define RTE_SEGMENTCHECK_C
/*@}*/
/*=======[I N C L U D E S]====================================================*/
/*=======[Includes]===========================================================*/
/*@{*/
#include "Rte_SegmentCheck.h"
#include "DP.h"
#include "Sha_256.h"
#include "SecM.h"
#include "FlashIf.h"
#include "Rte_Inc.h"
/*@}*/
/*=======[Private define]=====================================================*/
/*@{*/
#define RTE_CHECKSUM_TYPE RTE_CFG_CHECKSUM_SELECT
#define RTE_CHECKSUM_CRC RTE_CFG_CHECKSUM_CRC
#define RTE_CHECKSUM_SHA256_EVERY_SEGEMENT RTE_CFG_CHECKSUM_SHA256_EVERY_SEGEMENT
/*@}*/
/*=======[Private types]======================================================*/
/*@{*/
/*@}*/
/*=======[Private function prototypes]========================================*/
/*@{*/
/*@}*/
/*=======[Private variables]==================================================*/
/*@{*/
#if (RTE_CHECKSUM_TYPE == RTE_CHECKSUM_SHA256_EVERY_SEGEMENT)
static Sha256Calc Sha256CalcValue;
#elif (RTE_CHECKSUM_TYPE == RTE_CHECKSUM_CRC)
static SecM_CRCParamType crcParamCal;
#endif
static uint8 CalData[FL_PROGRAM_SIZE];
/*@}*/
/*=======[Private functions]==================================================*/
/*@{*/
extern void Appl_UpdateTriggerCondition(void);
extern void FL_ReadFromFlash(uint32 dat,uint32 addr ,uint32 len);
#if (RTE_CHECKSUM_TYPE == RTE_CHECKSUM_SHA256_EVERY_SEGEMENT)
/******************************************************************************/
/*
 * @brief              [SecM_Sha256CalcInit description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
static void SecM_Sha256CalcInit(void)
{
    /*
     * Sha256CalcValue.wdTriggerFct = Appl_UpdateTriggerCondition;
     */
    (void)Sha256Calc_init(&Sha256CalcValue);
}
/******************************************************************************/
/*
 * @brief              [SecM_GetSha256CalcCalculateValue description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
static uint8 * SecM_GetSha256CalcCalculateValue(void)
{
    return Sha256CalcValue.Value;
}
/******************************************************************************/
/*
 * @brief              [SecM_Sha256CalcCalculate description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [dp                       description]
 *                     [dl                       description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
static uint8 * SecM_Sha256CalcCalculate(const uint8* dp, uint32 dl)
{
    Sha256Calc_calculate(&Sha256CalcValue, dp, dl);
    return Sha256CalcValue.Value;
}
#elif (RTE_CHECKSUM_TYPE == RTE_CHECKSUM_CRC)
/******************************************************************************/
/*
 * @brief              [SecM_CrcInit description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
static void SecM_CrcInit(void)
{
    crcParamCal.crcState = (uint8)SECM_CRC_INIT;
    crcParamCal.currentCRC = 0;
    Cal_CrcInit(&crcParamCal.currentCRC);
}
/******************************************************************************/
/*
 * @brief              [SecM_CrcCalculate description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [dp                description]
 *                     [dl                description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
static uint8 * SecM_CrcCalculate(const uint8* dp, uint32 dl)
{
    uint32 len = dl;
    uint32 ptrIdx = 0u;
    while(len > (sizeof(CalData)/sizeof(&CalData[0])))
    {
        FL_ReadFromFlash((uint32)&CalData[0],(uint32)(&dp[ptrIdx]),(sizeof(CalData)/sizeof(&CalData[0])));
        crcParamCal.crcState = (uint8)SECM_CRC_COMPUTE;
        crcParamCal.crcSourceBuffer = CalData;
        crcParamCal.crcByteCount = (sizeof(CalData)/sizeof(&CalData[0]));
        Cal_CrcCal(&crcParamCal.currentCRC, crcParamCal.crcSourceBuffer, crcParamCal.crcByteCount);
        len-= (sizeof(CalData)/sizeof(&CalData[0]));
        ptrIdx+=(sizeof(CalData)/sizeof(&CalData[0]));
    }

    if(len > 0U)
    {
        FL_ReadFromFlash((uint32)&CalData[0],(uint32)(&dp[ptrIdx]),len);
        crcParamCal.crcState = (uint8)SECM_CRC_COMPUTE;
        crcParamCal.crcSourceBuffer = (uint8*)CalData;
        crcParamCal.crcByteCount = len;
        Cal_CrcCal(&crcParamCal.currentCRC, crcParamCal.crcSourceBuffer, crcParamCal.crcByteCount);
    }

    return (uint8*)&crcParamCal.currentCRC;
}
/******************************************************************************/
/*
 * @brief              [SecM_CrcFinish description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
static uint8 * SecM_CrcFinish(void)
{
    crcParamCal.crcState = (uint8)SECM_CRC_FINALIZE;
    Cal_CrcFinalize(&crcParamCal.currentCRC);
    return (uint8*)&crcParamCal.currentCRC;
}
/******************************************************************************/
/*
 * @brief              [SecM_Crcget description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
static uint8 * SecM_Crcget(void)
{
    return (uint8*)&crcParamCal.currentCRC;
}
#endif
/*@}*/
/******************************************************************************/
/*
 * @brief              [calStart     description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [ptr_segementList description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
static void calStart(const FL_SegmentListType*ptr_segementList)
{
#if (RTE_CHECKSUM_TYPE == RTE_CHECKSUM_SHA256_EVERY_SEGEMENT)
	(void)ptr_segementList;
    SecM_Sha256CalcInit();
#elif (RTE_CHECKSUM_TYPE == RTE_CHECKSUM_CRC)
    if (ptr_segementList->calNrOfSegment == 0U)
    {
        SecM_CrcInit();
    }
#endif
}
/******************************************************************************/
/*
 * @brief              [calCal   description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [addr     description]
 *                     [endAddr  description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
static void calCal(uint32 addr, uint32 len)
{
#if (RTE_CHECKSUM_TYPE == RTE_CHECKSUM_SHA256_EVERY_SEGEMENT)
        SecM_Sha256CalcCalculate((uint8*)addr, len);
#elif (RTE_CHECKSUM_TYPE == RTE_CHECKSUM_CRC)
        (void)SecM_CrcCalculate((uint8*)addr, len);
#endif
}
/******************************************************************************/
/*
 * @brief              [calSave          description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [ptr_segementList description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
static void calSave(FL_SegmentListType*ptr_segementList)
{
#if (RTE_CHECKSUM_TYPE == RTE_CHECKSUM_SHA256_EVERY_SEGEMENT)
    uint8 const *CalcValue;
    CalcValue = SecM_GetSha256CalcCalculateValue();
    DP_Memcpy(ptr_segementList->segmentInfo[ptr_segementList->calNrOfSegment].checksum,
            CalcValue, SECM_CHECKSUM_LENGTH);
#elif (RTE_CHECKSUM_TYPE == RTE_CHECKSUM_CRC)
#endif
    ptr_segementList->calNrOfSegment++;
}
/******************************************************************************/
/*
 * @brief              [Rte_FL_Segement_CheckSum_Window description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [winAddr                         description]
 *                     [winLen                          description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
void Rte_FL_Segement_CheckSum_Window(FL_SegmentListType*ptr_segementList,uint32 winAddr, uint32 winLen)
{
    FL_SegmentInfoType * curSegment;
    uint32 segmentIndex = 0u;
    uint32 segmentNum = 0u;
    uint32 window_start = winAddr;
    uint32 window_end = winAddr + winLen;
    uint32 cal_start;
    uint32 cal_end;
    boolean cal_next = FALSE;
    boolean processContinue = TRUE;

    if((ptr_segementList == NULL_PTR)
       || (window_start >= window_end)
       || (ptr_segementList->calNrOfSegment == ptr_segementList->nrOfSegments))
    {
        /*do nothing*/
    }
    else
    {
        segmentIndex = ptr_segementList->calNrOfSegment;
        segmentNum = ptr_segementList->nrOfSegments;
    }

    for (; (segmentIndex < segmentNum) && (processContinue == TRUE);)/*PRQA S 2472*/
    {
        curSegment = &ptr_segementList->segmentInfo[segmentIndex];

        if ((curSegment->address < window_end)&& ((curSegment->address + curSegment->length) > window_start))
        {
            if (curSegment->address >= window_start)
            {
                cal_start = curSegment->address;

                calStart(ptr_segementList);
            }
            else
            {
                cal_start = window_start;
            }

            if ((curSegment->address + curSegment->length) < window_end)
            {
                cal_end = curSegment->address + curSegment->length;

                cal_next = TRUE;
            }
            else
            {
                /*When curSegment->address + curSegment->length == window_end,
                data may need to be stored for the next session.*/
                cal_end = window_end;
            }

            calCal(cal_start,(cal_end - cal_start));

            if(TRUE == cal_next)
            {
                cal_next = FALSE;
                calSave(ptr_segementList);
                segmentIndex++;
            }
            else
            {
                break;
            }
        }
        else
        {
            if((curSegment->address + curSegment->length) <= window_start)
            {
                /*This data was not stored from the previous session and will be stored here.*/
                calSave(ptr_segementList);
                segmentIndex++;
            }
            else
            {
                /*do nothing,Never be here*/
				processContinue = FALSE;
            }
        }
    }
}
/******************************************************************************/
/*
 * @brief              [Rte_FL_Segement_CheckSum_WindowValue description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
uint8* Rte_FL_Segement_CheckSum_WindowValue(FL_SegmentListType*ptr_segementList)
{
    if((ptr_segementList == NULL_PTR)
       || (ptr_segementList->calNrOfSegment == ptr_segementList->nrOfSegments))
    {
        /*do nothing*/
    }
    else
    {
        calSave(ptr_segementList);
    }
#if (RTE_CHECKSUM_TYPE == RTE_CHECKSUM_SHA256_EVERY_SEGEMENT)
    return NULL_PTR;
#elif (RTE_CHECKSUM_TYPE == RTE_CHECKSUM_CRC)
    (void)ptr_segementList;
    (void)SecM_CrcFinish();
    return SecM_Crcget();
#endif
}
/*=======[E N D   O F   F I L E]==============================================*/
