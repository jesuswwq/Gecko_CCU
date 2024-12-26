/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <NvMem.c>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for ${tmpl} Module>
 *
 *  @author     <Your Name>
 *  @date       <2023-04-12 13:09:47>
 *
 *
 *
 *  May be changed by User [yes/no]: no
 */
/*============================================================================*/
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/** <VERSION>   <DATE>      <AUTHOR>     <REVISION LOG> */
/*@{*/
#define NVMEM_C
/*@}*/
/*=======[I N C L U D E S]====================================================*/
/*=======[Includes]===========================================================*/
/*@{*/
#include "Rte_Inc.h"
#include "NvMem.h"
#include "FlashIf.h"
#include "DP.h"
#include "SecM.h"
#include "FL_Cfg.h"

/* ----------------projectCfg---------------- */
#include "Fee.h"
#include "Fls.h"
#include "Rte_Inc.h"
/* ----------------projectCfg end---------------- */

/*@}*/
/*=======[Private define]=====================================================*/
/*@{*/
#define baseFlsSector       (RTE_PFLASH_SECTOR_SIZE)
#define baseStartFlsAddr    (RTE_CFG_APP_START_FLASH_ADDR)
#define baseEndFlsAddr      (RTE_CFG_APP_START_FLASH_END+RTE_CFG_APP_START_FLASH_OFFSET)
#define aligenWriteLen      (RTE_PFLASH_PAGE_SIZE)
#define aligenReadLen       (RTE_DFLASH_READ_PAGE_SIZE)
#define baseFeeSector       (RTE_DFLASH_SECTOR_SIZE)
#define baseStartFeeAddr    (RTE_DFLASH_BASE_ADDR)
#define baseEndFeeAddr      (RTE_DFLASH_BASE_ADDR+RTE_DFLASH_MAX_SIZE)
#define baseFeeMaxLen       (RTE_DFLASH_SECTOR_SIZE)
/*PRQA S 3472++*/
#define aligenW(x)          ((x)&(~(aligenWriteLen-1u)))
#define aligenWtail(x)      ((x)&((aligenWriteLen-1u)))
#define aligenR(x)          ((x)&(~(aligenReadLen-1u)))
#define aligenRtail(x)      ((x)&((aligenReadLen-1u)))
/*@}*/
/*=======[Private types]======================================================*/
/*=======[Private function prototypes]========================================*/
/*=======[Private variables]==================================================*/
static boolean feeCheckCrc32(const uint8* input, uint32 len,const uint8*crc);
static void feeCalCrc32(const uint8* input, uint32 len, uint8*crc);
#if defined PROJECT_FLS_ENABLE || defined PROJECT_FLS
void (*Rte_FlashPendingFct)(void) = NULL_PTR;
#endif


static uint8 FeeTempBuffer[baseFeeMaxLen];
#if defined PROJECT_FLS_ENABLE || defined PROJECT_FLS
static uint8 aligenFLASHBuf[aligenWriteLen];
#endif
/*=======[Private functions]==================================================*/
/*============================================================================*/
/*
 * @brief              [feeCheckCrc32 description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [input          description]
 *                     [len            description]
 *                     [crc            description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/*============================================================================*/
static boolean feeCheckCrc32(const uint8* input, uint32 len,const uint8*crc)
{
    boolean retVal = FALSE;
    SecM_CRCParamType crcParam;
    uint32 crcr;
    /* CRC value initialize */
    Cal_CrcInit(&crcParam.currentCRC);
    /* CRC value compute */
    crcParam.crcSourceBuffer = input;
    crcParam.crcByteCount = len;

    Cal_CrcCal(&crcParam.currentCRC, crcParam.crcSourceBuffer, (uint32)crcParam.crcByteCount);
    /* CRC value finish */
    Cal_CrcFinalize(&crcParam.currentCRC);
#if (CAL_CRC32 == CAL_METHOD)
    /* CRC32 */
    crcr = DP_Get4Byte(crc);
#elif (CAL_CRC16 == CAL_METHOD)
    /* CRC16 */
    crcr = ((SecM_CRCType)crc[0] << 8U);
    crcr += (SecM_CRCType)crc[1];
#else
    /* CRC8 */
#endif
    if ((crcr == crcParam.currentCRC) && (crcParam.currentCRC != 0xFFFFFFFFu))
    {
        retVal = TRUE;
    }
    return retVal;
}
/*============================================================================*/
/*
 * @brief              [feeCalCrc32 description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [input        description]
 *                     [len          description]
 *                     [crc          description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/*============================================================================*/
static void feeCalCrc32(const uint8* input, uint32 len, uint8*crc)
{
    SecM_CRCParamType crcParam;
    /* CRC value initialize */
    Cal_CrcInit(&crcParam.currentCRC);
    /* CRC value compute */
    crcParam.crcSourceBuffer = input;
    crcParam.crcByteCount = len;

    Cal_CrcCal(&crcParam.currentCRC, crcParam.crcSourceBuffer, (uint32)crcParam.crcByteCount);
    /* CRC value finish */
    Cal_CrcFinalize(&crcParam.currentCRC);
#if (CAL_CRC32 == CAL_METHOD)
    /* CRC32 */
    DP_GetUint32(crcParam.currentCRC, crc);
#elif (CAL_CRC16 == CAL_METHOD)
    /* CRC16 */
    crc[0] = (crcParam.currentCRC >> 8U) & 0xffu;
    crc[1] = crcParam.currentCRC & 0xffu;
#else
    /* CRC8 */
#endif
}
/*============================================================================*/
/*
 * @brief              [NvMemInit description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/*============================================================================*/
boolean NvMemInit(void)
{
    boolean ret = FALSE;
    
    Fls_Init(&Fls_ConfigData);
    Fee_Init(NULL_PTR);
    MemIf_JobResultType status = MEMIF_JOB_FAILED;
    while (MEMIF_JOB_PENDING == (status = Fee_GetJobResult()))
    {
        {
            Fee_MainFunction();
            Fls_MainFunction();
        }
    }

    if (MEMIF_JOB_OK == status)
    {
        ret = TRUE;
    }
    return ret;
}
/******************************************************************************/
/*
 * @brief              [NvMemDeInit description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean NvMemDeInit(void)
{
    boolean ret = FALSE;
    ret = TRUE;
    return ret;
}
/*============================================================================*/
/*
 * @brief              [NvMemRead description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [addr      description]
 *                     [info      description]
 *                     [len       description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/*============================================================================*/
boolean NvMemRead(uint32 addr, uint8 *info, uint32 len)
{
    boolean ret = FALSE;
    MemIf_JobResultType status = MEMIF_JOB_FAILED;

    do/*PRQA S 0771*/
    {
        if (addr < baseStartFeeAddr)
        {
            break;
        }

        if ((addr > baseEndFeeAddr) ||(len > (baseFeeMaxLen - SECM_CRC_LENGTH)))
        {
            break;
        }
#if 0
        DP_Memcpy(FeeTempBuffer,(uint8*)addr,len+SECM_CRC_LENGTH);
#else
        if (E_OK == Fee_Read((uint32)addr, 0, FeeTempBuffer, len+SECM_CRC_LENGTH))
        {
            while (MEMIF_JOB_PENDING == (status = Fee_GetJobResult()))
            {
                {
                    Fee_MainFunction();
                    Fls_MainFunction();
                }
            }
        }

        if(MEMIF_JOB_OK != status)
        {
            break;
        }
#endif
        if(TRUE == feeCheckCrc32(FeeTempBuffer, len, &FeeTempBuffer[len]))
        {
            DP_Memcpy(info,FeeTempBuffer,len);
            ret = TRUE;
        }
    }
    while (0);

    return ret;
}
/*============================================================================*/
/*
 * @brief              [NvMemWrite description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [addr       description]
 *                     [info       description]
 *                     [len        description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/*============================================================================*/
boolean NvMemWrite(uint32 addr,const uint8 *info, uint32 len)
{
    boolean ret = FALSE;
#if 0
    uint32 tFlashParam_u32Length;
    uint32 tFlashParam_u32Address;
#else
    MemIf_JobResultType status = MEMIF_JOB_FAILED;    
#endif
    do/*PRQA S 0771*/
    {
        if (addr < baseStartFeeAddr)
        {
            break;
        }

        if ((addr > baseEndFeeAddr) || (len > (baseFeeMaxLen - SECM_CRC_LENGTH)))
        {
            break;
        }

        if ((addr & (baseFeeSector - 1U)) > 0U)
        {
            break;
        }

#if 0
        tFlashParam_u32Length = (len/baseFeeSector);
        tFlashParam_u32Length  = ((len % baseFeeSector) > 0U) ? (tFlashParam_u32Length + 1U) : tFlashParam_u32Length;
        tFlashParam_u32Address= (addr/baseFeeSector);
        tFlashParam_u32Address*= baseFeeSector;

        if (FlsLoader_Erase(tFlashParam_u32Address, tFlashParam_u32Length) != FLSLOADER_E_OK)
        {
            break;
        }
#else
        while (MEMIF_JOB_OK == (status = Fee_GetJobResult())
               && (FEE_ERASE_JOB_PENDING == FeeErase_GetJobResult())
               )
        {
            Fee_MainFunction();
            Fls_MainFunction();
        }

        if(MEMIF_JOB_OK != status)
        {
            break;
        }
#endif

        DP_Memcpy(FeeTempBuffer, info, len);
        feeCalCrc32(FeeTempBuffer, len, &FeeTempBuffer[len]);
#if 0
        if(aligenW(len+SECM_CRC_LENGTH)!=0u)/*PRQA S 3469*/
        {
            if(FLSLOADER_E_OK != FlsLoader_Write(addr, aligenW(len+SECM_CRC_LENGTH), FeeTempBuffer))/*PRQA S 3469*/
            {
                break;
            }
        }

        if(aligenWtail(len+SECM_CRC_LENGTH)>0u)/*PRQA S 3469*/
        {
            DP_Memcpy(FeeTempBuffer,(const uint8*)&FeeTempBuffer[aligenW(len+SECM_CRC_LENGTH)],aligenWtail(len+SECM_CRC_LENGTH));/*PRQA S 3469*/
            if( FLSLOADER_E_OK != FlsLoader_Write(addr + aligenW(len+SECM_CRC_LENGTH)  , aligenWriteLen,FeeTempBuffer))/*PRQA S 3469*/
            {
                break;
            }
        }
#else
        if (E_OK == Fee_Write((uint32)addr, FeeTempBuffer))
        {
            while (MEMIF_JOB_PENDING == (status = Fee_GetJobResult()))
            {
                {
                    Fee_MainFunction();
                    Fls_MainFunction();
                }
            }
        }

        if(MEMIF_JOB_OK != status)
        {
            break;
        }
#endif
        ret = TRUE;
    }
    while (0);

    return ret;
}

#if defined PROJECT_FLS_ENABLE || defined PROJECT_FLS
static uint8 aligenFLASHBuf[aligenWriteLen];
#if defined PROJECT_FLS
#include "taishan_reset_drv.h"
extern void c_tcm_section_init(void);
extern void c_section_init(void);
extern reset_ctl_t g_rstgen_saf;
extern reset_ctl_t g_rstgen_ap;
extern sint32 taishan_reset_init(reset_ctl_t *rst_ctl, taishan_reset_ctl_t *taishan_rst_ctl);
extern taishan_reset_ctl_t taishan_rstgen_sf_dev;
extern taishan_reset_ctl_t taishan_rstgen_ap_dev;
#endif
/*============================================================================*/
/*
 * @brief              [Rte_FlashInit description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/*============================================================================*/
boolean Rte_FlashInit(void)
{
    boolean ret = FALSE;

#if defined PROJECT_FLS
    c_tcm_section_init();
    c_section_init();

    taishan_reset_init(&g_rstgen_saf, &taishan_rstgen_sf_dev);
    taishan_reset_init(&g_rstgen_ap, &taishan_rstgen_ap_dev);
#endif
    Fls_Init(&Fls_ConfigData);
    MemIf_JobResultType status = MEMIF_JOB_FAILED;
    while (MEMIF_JOB_PENDING == (status = Fls_GetJobResult()))
    {
        Fls_MainFunction();
    }
    if (MEMIF_JOB_OK == status)
    {
        ret = TRUE;
    }

    return ret;
}
/******************************************************************************/
/*
 * @brief              [Rte_FlashDeInit description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_FlashDeInit(void)
{
    boolean ret = FALSE;

    ret = TRUE;

    return ret;
}
/*============================================================================*/
/*
 * @brief              [Rte_FlashErase description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [addr           description]
 *                     [len            description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/*============================================================================*/
boolean Rte_FlashErase(uint32 addr, uint32 len)
{
    boolean ret = FALSE;
    MemIf_JobResultType status = MEMIF_JOB_FAILED;
    uint32 tFlashParam_u32Length;
    uint32 tFlashParam_u32Address;
    do/*PRQA S 0771*/
    {
        if (addr < baseStartFlsAddr)
        {
            break;
        }

        if (addr > baseEndFlsAddr || addr + len > baseEndFlsAddr)
        {
            break;
        }
        tFlashParam_u32Length=(len/baseFlsSector);
        tFlashParam_u32Length  = ((len % baseFlsSector) > 0U) ? (tFlashParam_u32Length + 1U) : tFlashParam_u32Length;
        tFlashParam_u32Length*=baseFlsSector;
        tFlashParam_u32Address=(addr/baseFlsSector);
        tFlashParam_u32Address*=baseFlsSector;

#if 0
        if (FlsLoader_Erase(tFlashParam_u32Address, tFlashParam_u32Length) != FLSLOADER_E_OK)
        {
            break;
        }
        ret = TRUE;
#else
        addr^=0x10000000;
        if (E_OK == Fls_Erase((uint32)addr, len))
        {
            while (MEMIF_JOB_PENDING == (status = Fls_GetJobResult()))
            {
                Fls_MainFunction();
                if(Rte_FlashPendingFct != NULL_PTR)
                {
                    Rte_FlashPendingFct();
                }
            }
            ret = (MEMIF_JOB_OK == status);
        }
#endif
    }
    while (0);

    return ret;
}
/*============================================================================*/
/*
 * @brief              [Rte_FlashRead description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [addr          description]
 *                     [info          description]
 *                     [len           description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/*============================================================================*/
boolean Rte_FlashRead(uint32 addr, uint8 *info, uint32 len)
{
    boolean ret = FALSE;
    MemIf_JobResultType status = MEMIF_JOB_FAILED;

    do/*PRQA S 0771*/
    {
        if (addr < baseStartFlsAddr)
        {
            break;
        }

        if (addr > baseEndFlsAddr || addr + len > baseEndFlsAddr)
        {
            break;
        }
#if 0
        DP_Memcpy(info,(uint8*)addr,len);
#else
        addr^=0x10000000;
        if (E_OK == Fls_Read((uint32)addr, info, len))
        {
            while (MEMIF_JOB_PENDING == (status = Fls_GetJobResult()))
            {
                Fls_MainFunction();
                if(Rte_FlashPendingFct != NULL_PTR)
                {
                    Rte_FlashPendingFct();
                }
            }
            ret = (MEMIF_JOB_OK == status);
        }
#endif
        ret = TRUE;
    }
    while (0);

    return ret;
}
/*============================================================================*/
/*
 * @brief              [Rte_FlashWrite description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [addr           description]
 *                     [info           description]
 *                     [len            description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/*============================================================================*/
boolean Rte_FlashWrite(uint32 addr,const uint8 *info, uint32 len)
{
    boolean ret = FALSE;

    MemIf_JobResultType status = MEMIF_JOB_FAILED;
    do/*PRQA S 0771*/
    {
        if (addr < baseStartFlsAddr)
        {
            break;
        }

        if (addr > baseEndFlsAddr || addr + len > baseEndFlsAddr)
        {
            break;
        }

        if (addr & (aligenWriteLen - 1u))
        {
            break;
        }
#if 0
        if(aligenW(len)!=0u)/*PRQA S 3469*/
        {
            if(FLSLOADER_E_OK != FlsLoader_Write( addr, aligenW(len), info))/*PRQA S 3469*/
            {
                break;
            }
        }

        if(aligenWtail(len)>0u)/*PRQA S 3469*/
        {
            DP_Memcpy(aligenFLASHBuf,(const uint8*)&info[aligenW(len)],aligenWtail(len));/*PRQA S 3469*/
            if( FLSLOADER_E_OK != FlsLoader_Write( addr + aligenW(len)  , aligenWriteLen,aligenFLASHBuf))/*PRQA S 3469*/
            {
                break;
            }
        }

        ret = TRUE;
#else
        addr^=0x10000000;
        if (E_OK == Fls_Write((uint32)addr, info, len))
        {
            while (MEMIF_JOB_PENDING == (status = Fls_GetJobResult()))
            {
                Fls_MainFunction();
                if(Rte_FlashPendingFct != NULL_PTR)
                {
                    Rte_FlashPendingFct();
                }
            }
            ret = (MEMIF_JOB_OK == status);
        }
#endif
    }
    while (0);

    return ret;
}
/*============================================================================*/
/*
 * @brief              [Rte_FlsTest description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/*============================================================================*/
void Rte_FlsTest(void)
{
	static uint8 table[aligenWriteLen+12];
    boolean ret[6] = {FALSE};
    ret[5] = Rte_FlashInit();
    ret[0] = Rte_FlashErase(baseStartFlsAddr, 0x20000);
    ret[1] = Rte_FlashWrite(baseStartFlsAddr, (const uint8 *)"abcdefghijklmnop", 12);
	ret[2] = Rte_FlashWrite(baseStartFlsAddr + 0x20000-aligenWriteLen, (const uint8 *)" abcdefghijklmno", 12);

    ret[3] = Rte_FlashRead(baseStartFlsAddr, (uint8*)table, 12);

    ret[3] = Rte_FlashRead(baseStartFlsAddr+ 0x20000-aligenWriteLen, &table[12], 12);
    ret[4] = Rte_FlashDeInit();
#ifdef PROJECT_FLS
    tFlashParam t;
    t.address = baseStartFlsAddr;
    t.data = ( uint8 *)"abcdefghijklmnop";
    t.errorCode = kFlashOk;
    t.length = 0x12;
    t.wdTriggerFct = NULL_PTR;
    t.patchLevel = FLASH_DRIVER_VERSION_PATCH;
    t.minorNumber = FLASH_DRIVER_VERSION_MINOR;
    t.majorNumber = FLASH_DRIVER_VERSION_MAJOR;
    BLFlash_InfoPtr->flashInitFct(&t);
    BLFlash_InfoPtr->flashInitFct(&t);
    BLFlash_InfoPtr->flashEraseFct(&t);
    BLFlash_InfoPtr->flashWriteFct(&t);
    BLFlash_InfoPtr->flashDeInitFct(&t);
    while(1);
#endif
    (void)ret;
}
#endif

/*============================================================================*/
/*
 * @brief              [NvMemTest description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/*============================================================================*/
void NvMemTest(void)
{
    uint8 table[10];
    boolean ret[10];
    ret[9] = NvMemInit();
    ret[0] = NvMemWrite(baseStartFeeAddr + 0x0000U, (const uint8*)"0sadasd", 8);
    ret[1] = NvMemWrite(baseStartFeeAddr + 0x2000U, (const uint8*)"1sadasd", 8);
    ret[2] = NvMemWrite(baseStartFeeAddr + 0x4000U, (const uint8*)"2sadasd", 8);
    ret[3] = NvMemWrite(baseStartFeeAddr + 0x6000U, (const uint8*)"3sadasd", 8);
    ret[4] = NvMemRead(baseStartFeeAddr + 0x0000U, table, 8);
    ret[5] = NvMemRead(baseStartFeeAddr + 0x2000U, table, 8);
    ret[6] = NvMemRead(baseStartFeeAddr + 0x4000U, table, 8);
    ret[7] = NvMemRead(baseStartFeeAddr + 0x6000U, table, 8);
    ret[8] = NvMemDeInit();
    (void)ret;
//    Can_PduType tPduInfo;
//    extern uint32 debugA;
//    tPduInfo.id = 0x555;
//    tPduInfo.swPduHandle = 0U;
//    tPduInfo.length = 8;
//    tPduInfo.sdu =ret;
//    Can_Write(2,&tPduInfo);
}
/*=======[E N D   O F   F I L E]==============================================*/
