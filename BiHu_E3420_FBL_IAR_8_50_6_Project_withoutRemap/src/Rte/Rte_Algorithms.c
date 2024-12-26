/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Rte_Algorithms.c>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for ${tmpl} Module>
 *
 *  @author     <Your Name>
 *  @date       <2024-01-03 18:08:54>
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
#define RTE_ALGORITHMS_C
/*@}*/
/*=======[I N C L U D E S]====================================================*/
/*=======[Includes]===========================================================*/
/*@{*/
#include "Rte_Algorithms.h"
#include "GptIf.h"
#include "Dcm.h"
#include "DP.h"
#include "Dcm_Cfg.h"
#include "stdlib.h"
#include "Rte_Inc.h"
/*@}*/
/*=======[Private define]=====================================================*/
/*@{*/
#define RTE_AG_RAMDOM_SAVE RTE_CFG_AG_RAMDOM_SAVE
#define RTE_AG_ADC_RANDOM RTE_CFG_AG_ADC_RANDOM
#define RTE_AG_DRBG_USED RTE_CFG_AG_DRBG_USED
/*@}*/
/*=======[Private types]======================================================*/
/*@{*/
/*@}*/
/*=======[Private function prototypes]========================================*/
/*@{*/
/*@}*/
/*=======[Private variables]==================================================*/
/*@{*/
/*@}*/
/*=======[Private functions]==================================================*/
/*@{*/
/*@}*/
/******************************************************************************/
/*
 * @brief              [Rte_SecM_GenerateSeed description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [seed                  description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
void Rte_SecM_GenerateSeed(uint8 *seed,const uint16 slen)
{
    static uint32 lastValue = 0u;
    static uint32 ramdom = 0u;
    /* todo: add your seed generate code here */
    /* ==========================add code=================================== */
    uint8 idx;
    uint32 tempSeed;
    uint32 RandomNumber;

    ramdom++;

#if (RTE_AG_RAMDOM_SAVE == STD_ON)
    ramdom = FL_RAMDOM_SAVE;
    ramdom++;
    FL_RAMDOM_SAVE = ramdom;
#endif

#if (RTE_AG_ADC_RANDOM == STD_ON)
    ramdom = Mcal_Adc_Read_Random() + ramdom;
#endif

    tempSeed = ramdom;
    RandomNumber = (uint32)GptIf_Random_Get() + lastValue;
    RandomNumber = tempSeed + RandomNumber;
#if (RTE_AG_DRBG_USED == STD_OFF)

    srand(RandomNumber);
    tempSeed = (((uint32)rand()) << 16u) | (uint32)rand();
    /* Get random number */
    tempSeed = tempSeed | ((((uint32)rand() + (tempSeed >> 24u)) & 0xffu) << 8u) ;

#else
    (void)ecy_HashDrbg((uint8*)&RandomNumber, 4u, (uint8*)&tempSeed, 4u);
#endif
    RandomNumber = ((tempSeed + lastValue) >> 1u);

    for(idx = 0; idx < slen; idx++)
    {
        seed[idx] = ((uint8*)&RandomNumber)[idx % sizeof(RandomNumber)] + (uint8)rand();
    }

    /* ==========================add code=================================== */
    if(lastValue > tempSeed)
    {
        tempSeed = lastValue - tempSeed;
        lastValue -= (tempSeed >> 3u);
    }
    else
    {
        tempSeed = tempSeed - lastValue;
        lastValue += (tempSeed >> 3u);
    }
}
/******************************************************************************/
/*
 * @brief              [Rte_SecM_VerificationCrc description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [verifyParam              description]
 *                     [crc                      description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
SecM_StatusType Rte_SecM_VerificationCrc(SecM_VerifyParamType* verifyParam,const uint8* crc)
{
    SecM_StatusType retVal = (uint8)SECM_OK;
    SecM_CRCType transferedCrc;
#if (CAL_CRC32 == CAL_METHOD)
    uint32 currentCRC;
#elif (CAL_CRC16 == CAL_METHOD)
    uint16 currentCRC;
#endif
    DP_Memcpy((uint8*)&currentCRC, crc, sizeof(SecM_CRCType));

    if (NULL_PTR == verifyParam->segmentList)
    {
        /* if segment list is NULL, verification is failed */
        retVal = (uint8)SECM_NOT_OK;
    }

    if ((uint8)SECM_OK == retVal)
    {
        /* get CRC transfered from client */
#if (CAL_CRC32 == CAL_METHOD)
        /* CRC32 */
        transferedCrc = DP_Get4Byte(verifyParam->verificationData);
#elif (CAL_CRC16 == CAL_METHOD)
        /* CRC16 */
        transferedCrc = ((SecM_CRCType)verifyParam->verificationData[0] << 8U);
        transferedCrc += (SecM_CRCType)verifyParam->verificationData[1];
#else
        /* CRC8 */
#endif

        /* compare CRC */
        if (transferedCrc != currentCRC)
        {
            retVal = (uint8)SECM_NOT_OK;
        }
        else
        {
            verifyParam->crcTotle = currentCRC;
            /* do nothing */
        }
    }

    return retVal;
}
#if (FL_FLASH_DRIVER_INTEGRITY_VALID_CHECK == STD_ON)
/******************************************************************************/
/*
 * @brief              [Rte_SecM_VerifyFlashdriver description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [verifyParam                description]
 *                     [crc                        description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_SecM_VerifyFlashdriver(const SecM_VerifyParamType* verifyParam)
{
    boolean retVal = FALSE;

    SecM_CRCType flashdriverInterger;
    uint32 index;
    SecM_CRCParamType crcParam;
    /* CRC value initialize */
    Cal_CrcInit(&crcParam.currentCRC);
    /* CRC value compute */
    for (index = 0; index < verifyParam->segmentList->nrOfSegments; index++)
    {
        if (verifyParam->segmentList->segmentInfo[index].address != FL_FLASH_DRIVER_INTEGRITY_VALID_ADDRESS)
        {
            crcParam.crcSourceBuffer = (uint8*)verifyParam->segmentList->segmentInfo[index].address;
            crcParam.crcByteCount = verifyParam->segmentList->segmentInfo[index].length;
            Cal_CrcCal(&crcParam.currentCRC, crcParam.crcSourceBuffer, (uint32)crcParam.crcByteCount);
        }
    }
    /* CRC value finish */
    Cal_CrcFinalize(&crcParam.currentCRC);

#if (CAL_CRC32 == CAL_METHOD)
    /* CRC32 */
    flashdriverInterger = DP_Get4Byte((uint8 *)FL_FLASH_DRIVER_INTEGRITY_VALID_ADDRESS);
#elif (CAL_CRC16 == CAL_METHOD)
    /* CRC16 */
    flashdriverInterger = (((uint8 *)FL_FLASH_DRIVER_INTEGRITY_VALID_ADDRESS)[0] << 8U) & 0xff00u;
    flashdriverInterger += (((uint8 *)FL_FLASH_DRIVER_INTEGRITY_VALID_ADDRESS)[1] << 0U);
#else
    /* CRC8 */
#endif
    if ((crcParam.currentCRC == flashdriverInterger) && (crcParam.currentCRC != 0xFFFFFFFFu))
    {
        retVal = TRUE;
    }
    return retVal;
}
#endif
/*=======[E N D   O F   F I L E]==============================================*/
