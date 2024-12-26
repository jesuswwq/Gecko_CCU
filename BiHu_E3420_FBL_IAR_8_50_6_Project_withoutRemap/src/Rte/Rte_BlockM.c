/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Rte_BlockM.c>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for ${tmpl} Module>
 *
 *  @author     <Your Name>
 *  @date       <2024-01-03 10:49:59>
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
#define RTE_BLOCKM_C
/*@}*/
/*=======[I N C L U D E S]====================================================*/
/*=======[Includes]===========================================================*/
/*@{*/
#include "Rte_BlockM.h"
#include "DP.h"
#include "Rte_Inc.h"
/*@}*/
/*=======[Private define]=====================================================*/
/*@{*/
#define RTE_BLK_STORAGE_ERASE_STATUS RTE_CFG_BLK_STORAGE_ERASE_STATUS
#define RTE_BLK_ERASE_BLOCK_SUPPORT_CROSS_ZONE RTE_CFG_BLK_ERASE_BLOCK_SUPPORT_CROSS_ZONE
/*@}*/
/*=======[Private types]======================================================*/
/*@{*/
#define FL_BLK_PROGRAM_IDLE                     0x0u
#define FL_BLK_PROGRAM_ERASING                  0x1u
#define FL_BLK_PROGRAM_ERASED                   0x2u
#define FL_BLK_PROGRAM_DOWNLOADING              0x3u
#define FL_BLK_PROGRAM_FINISHED                 0x4u
typedef uint8 Rte_FL_Blk_ProgramStateType;

typedef struct
{
    boolean checkFlag;

    Rte_FL_Blk_ProgramStateType downloadState;

    uint8 Reserved[RESERVED_CAL_SIZE(uint8, (sizeof(boolean) + sizeof(Rte_FL_Blk_ProgramStateType)))];

} blockRuntimeType;

typedef struct
{
    Rte_FL_NvmInfoType nvmInfo;
    struct
    {
        Rte_FL_Blk_ProgramStateType programState;
        blockRuntimeType blockInfo[FL_NUM_LOGICAL_BLOCKS];

        uint8 Reserved[RESERVED_CAL_SIZE(uint8, sizeof(Rte_FL_Blk_ProgramStateType))];
    } runtime;
    struct
    {
        Rte_FL_BlockDescriptorType* blockInfo;
    } cfgInfo;
} Rte_FL_blockManagerType;
/*@}*/
/*=======[Private function prototypes]========================================*/
/*@{*/
/*@}*/
/*=======[Private variables]==================================================*/
/*@{*/
extern const Rte_FL_BlockDescriptorType FL_BlkInfoExt[FL_NUM_LOGICAL_BLOCKS];
#if (RTE_PARTITION_SWAP_ON == STD_ON)
extern const Rte_FL_BlockDescriptorType FL_BlkInfoExtB[FL_NUM_LOGICAL_BLOCKS];
#endif
static Rte_FL_blockManagerType blockManager = {.cfgInfo.blockInfo = (Rte_FL_BlockDescriptorType*)FL_BlkInfoExt};
static uint32 g_startAddr;
static uint32 g_eraselen;
/*@}*/
/*=======[Private functions]==================================================*/
/*@{*/
/*@}*/
/******************************************************************************/
/*
 * @brief              [Rte_BlkM_GetNvmInfo description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
Rte_FL_NvmInfoType * Rte_BlkM_GetNvmInfo(void)
{
    return &(blockManager.nvmInfo);
}
/******************************************************************************/
/*
 * @brief              [Rte_BlkM_GetCfgInfo description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
Rte_FL_BlockDescriptorType * Rte_BlkM_GetCfgInfo(void)
{
    return blockManager.cfgInfo.blockInfo;
}
#if (RTE_PARTITION_SWAP_ON == STD_ON)
/******************************************************************************/
/*
 * @brief              [Rte_BlkM_InitCfgInfo description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
const Rte_FL_BlockDescriptorType * Rte_BlkM_InitCfgInfo(void)
{
    const Rte_FL_BlockDescriptorType * p;
    if (TRUE == Rte_ABSwap_isA())
    {
        p = FL_BlkInfoExtB;
    }
    else
    {
        p = FL_BlkInfoExt;
    }
    return p;
}
#endif
/******************************************************************************/
/*
 * @brief              [Rte_BlkM_UpdateNvm description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
FL_ResultType Rte_BlkM_UpdateNvm(void)
{
    FL_ResultType     ret = (uint8)FL_ERR_MEMORY;

    if(TRUE == Rte_Data_Write_NvmInfo((uint8*)&blockManager.nvmInfo))
    {
        ret = FL_OK;
    }

    return ret;
}
/******************************************************************************/
/*
 * @brief              [Rte_BlkM_InitBlockInfo description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
void Rte_BlkM_InitBlockInfo(void)
{
    boolean ret = FALSE;
    uint8 index;
#if (RTE_PARTITION_SWAP_ON == STD_ON)
    blockManager.cfgInfo.blockInfo = (Rte_FL_BlockDescriptorType * )Rte_BlkM_InitCfgInfo();
#endif
    /*1st read nvmInfo */
    ret = Rte_Data_Read_NvmInfo((uint8*)&blockManager.nvmInfo);

    if (FALSE == ret)
    {
        /* if there is no information in NVM, then initialize the information */
        DP_Memset((uint8 *)&blockManager.nvmInfo, 0, sizeof(blockManager.nvmInfo));
    }

    /*2st clear blockManager */
    DP_Memset((uint8 *)&blockManager.runtime, 0, sizeof(blockManager.runtime));

    /*3st fill blockManager by nvmInfo */
    for (index = 0u; index < FL_NUM_LOGICAL_BLOCKS; index++)
    {
        blockManager.runtime.blockInfo[index].checkFlag = blockManager.cfgInfo.blockInfo[index].checkFlag;
#if (RTE_BLK_STORAGE_ERASE_STATUS == STD_ON)

        if(blockManager.nvmInfo.blockInfo[index].erase == TRUE && TRUE == ret)
        {
            blockManager.runtime.blockInfo[index].downloadState = FL_BLK_PROGRAM_ERASED;
        }
        else
#endif
        {
            blockManager.nvmInfo.blockInfo[index].erased = FALSE;
        }
    }

    /* 4st syn flag
    blockManager.nvmInfo.intergrity
    blockManager.nvmInfo.compatibility */
    // Rte_BlkM_CheckCompatibility();
}
/******************************************************************************/
/*
 * @brief              [Rte_BlkM_ActiveBlockInfo description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_BlkM_ActiveBlockInfo(void)
{
    boolean ret = FALSE;
    uint8 index;
    Rte_FL_NvmInfoType *nvmInfo = Rte_BlkM_GetNvmInfo();
    Rte_FL_BlockDescriptorType *cfgInfo = Rte_BlkM_GetCfgInfo();

    for (index = 0u; index < FL_NUM_LOGICAL_BLOCKS; index++)
    {
        nvmInfo->blockInfo[index].intergrity = TRUE;
        nvmInfo->blockInfo[index].compatibility = TRUE;
#if (RTE_BLK_STORAGE_SIGNATURE == STD_ON)
        Rte_BlkM_SetBlockSignatrue(index, (uint8 *)cfgInfo[index].signatureAddr, cfgInfo[index].signatureSize);
#endif
    }

    nvmInfo->compatibility = TRUE;
    nvmInfo->intergrity = TRUE;
    nvmInfo->valid = TRUE;

    if (FL_OK == Rte_BlkM_UpdateNvm())
    {
        ret = TRUE;
    }
    else
    {
        ret = FALSE;
    }

    return ret;
}
/******************************************************************************/
/*
 * @brief              [Rte_BlkM_SetBlockInValid description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [index                    description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
void Rte_BlkM_SetBlockInValid(uint8 index)
{
    if (index < FL_NUM_LOGICAL_BLOCKS)
    {
        /* set current block is invalid */
        blockManager.nvmInfo.compatibility = FALSE;

        if(TRUE == blockManager.cfgInfo.blockInfo[index].checkFlag)
        {
            blockManager.nvmInfo.valid = FALSE;
            blockManager.nvmInfo.intergrity = FALSE;
        }

        blockManager.nvmInfo.blockInfo[index].erased = FALSE;

#if (RTE_BLK_STORAGE_SIGNATURE == STD_ON)
        Appl_Memset((uint8 *) & (blockManager.nvmInfo.blockInfo[index].signatrue[0]), 0xFF, SECM_SIGNATURE_LENGTH);
#endif

        if (blockManager.runtime.blockInfo[index].checkFlag == FALSE
            && blockManager.cfgInfo.blockInfo[index].checkFlagCanbeChanged == TRUE)
        {
            blockManager.runtime.blockInfo[index].checkFlag = TRUE;
        }

        /* change and initialize status of the programmed block */
        blockManager.runtime.blockInfo[index].downloadState = FL_BLK_PROGRAM_ERASING;
        blockManager.nvmInfo.blockInfo[index].intergrity = FALSE;
        blockManager.nvmInfo.blockInfo[index].compatibility = FALSE;

        blockManager.runtime.programState = FL_BLK_PROGRAM_ERASING;
    }
}
/******************************************************************************/
/*
 * @brief              [Rte_BlkM_SetBlockDownloading description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [requesetAddr                 description]
 *                     [requesetlen                  description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
FL_ResultType Rte_BlkM_SetBlockDownloading(uint32 requesetAddr, uint32  requesetlen)
{
    FL_ResultType ret = FL_ERR_ADDR_LENGTH;

    sint8 startIdx;
    sint8 endIdx;

    ret = Rte_BlkM_SearchBlock(requesetAddr, requesetlen, &startIdx, &endIdx);

    if (ret == FL_OK)
    {
        if(blockManager.runtime.programState != FL_BLK_PROGRAM_DOWNLOADING)
        {
            blockManager.runtime.programState = FL_BLK_PROGRAM_DOWNLOADING;
        }

        for (; ret == FL_OK && startIdx <= endIdx; startIdx++)
        {
            if(blockManager.runtime.blockInfo[startIdx].downloadState == FL_BLK_PROGRAM_ERASED)
            {
                if(blockManager.nvmInfo.blockInfo[startIdx].erased == TRUE)
                {
                    blockManager.nvmInfo.blockInfo[startIdx].erased = FALSE;
#if (RTE_BLK_STORAGE_ERASE_STATUS == STD_ON)
                    ret = Rte_BlkM_UpdateNvm();
#endif
                }

                blockManager.runtime.blockInfo[startIdx].downloadState = FL_BLK_PROGRAM_DOWNLOADING;
            }
        }
    }

    return ret;
}
/******************************************************************************/
/*
 * @brief              [Rte_BlkM_SetBlockCompatibility description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [index                          description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
void Rte_BlkM_SetBlockCompatibility(uint8 index)
{
    if (index < FL_NUM_LOGICAL_BLOCKS)
    {
        if (blockManager.runtime.blockInfo[index].downloadState == FL_BLK_PROGRAM_DOWNLOADING)
        {
            blockManager.nvmInfo.blockInfo[index].compatibility = TRUE;
        }
    }
}
/******************************************************************************/
/*
 * @brief              [Rte_BlkM_SetBlockIntergrity description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [index                       description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
void Rte_BlkM_SetBlockIntergrity(uint8 index)
{
    if (index < FL_NUM_LOGICAL_BLOCKS)
    {
        if (blockManager.runtime.blockInfo[index].downloadState == FL_BLK_PROGRAM_DOWNLOADING)
        {
            blockManager.nvmInfo.blockInfo[index].intergrity = TRUE;
        }
    }
}
/******************************************************************************/
/*
 * @brief              [Rte_BlkM_SetBlocksDownloadFinish description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
void Rte_BlkM_SetBlocksDownloadFinish(void)
{
    uint8 index = 0;

    for (index = 0; index < FL_NUM_LOGICAL_BLOCKS; index++)
    {
        if (blockManager.runtime.blockInfo[index].downloadState == FL_BLK_PROGRAM_DOWNLOADING)
        {
            blockManager.runtime.blockInfo[index].downloadState = FL_BLK_PROGRAM_IDLE;
        }
    }

}
/******************************************************************************/
/*
 * @brief              [Rte_BlkM_SetIfAppValid description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
FL_ResultType Rte_BlkM_SetIfAppValid(void)
{
    FL_ResultType ret = (FL_ResultType)FL_FAILED;

    if(((boolean)TRUE == blockManager.nvmInfo.intergrity)
       && ((boolean)TRUE == blockManager.nvmInfo.compatibility))
    {
        blockManager.nvmInfo.valid = TRUE;
        ret = FL_OK;
    }

    return ret;
}
/******************************************************************************/
/*
 * @brief              [Rte_BlkM_CheckCompatibility description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
FL_ResultType Rte_BlkM_CheckCompatibility(void)
{
    FL_ResultType ret = FL_OK;
    /* block number */
    uint8 index ;
    uint8 counter ;

    for (index = 0u, counter = 0u; index < FL_NUM_LOGICAL_BLOCKS; index++)
    {
        if (TRUE == blockManager.cfgInfo.blockInfo[index].checkFlag)
        {
            ++counter;
        }

        /* check if all block is valid */
        if(TRUE == blockManager.runtime.blockInfo[index].checkFlag)
        {
            if (((TRUE != blockManager.nvmInfo.blockInfo[index].intergrity)
                 || (TRUE != blockManager.nvmInfo.blockInfo[index].compatibility)))
            {
                ret = (uint8)FL_FAILED;
            }
            else if (TRUE == blockManager.cfgInfo.blockInfo[index].checkFlag)
            {
                if(counter > 0u)
                {
                    --counter;
                }
            }
        }
    }

    if(counter == 0u)
    {
        blockManager.nvmInfo.intergrity = TRUE;
    }

    if(FL_OK == ret)
    {
        blockManager.nvmInfo.compatibility = TRUE;

        if(blockManager.runtime.programState == FL_BLK_PROGRAM_DOWNLOADING)
        {
            blockManager.runtime.programState = FL_BLK_PROGRAM_FINISHED;
        }
    }

    return ret;
}
/******************************************************************************/
/*
 * @brief              [Rte_BlkM_GetCompatibility description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_BlkM_GetCompatibility(void)
{
    return blockManager.nvmInfo.compatibility;
}
/******************************************************************************/
/*
 * @brief              [Rte_BlkM_GetIntergrity description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_BlkM_GetIntergrity(void)
{
    return blockManager.nvmInfo.intergrity;
}
/******************************************************************************/
/*
 * @brief              [Rte_BlkM_GetAppValid description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_BlkM_GetAppValid(void)
{
    return blockManager.nvmInfo.valid;
}
/******************************************************************************/
/*
 * @brief              [Rte_BlkM_GetIsProgramed description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_BlkM_GetIsProgramed(void)
{
    return blockManager.runtime.programState == FL_BLK_PROGRAM_FINISHED;
}
/******************************************************************************/
/*
 * @brief              [Rte_BlkM_GetIsProgramming description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_BlkM_GetIsProgramming(void)
{
    return blockManager.runtime.programState != FL_BLK_PROGRAM_IDLE;
}
/******************************************************************************/
/*
 * @brief              [Rte_BlkM_GetBlockIsProgramming description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [index                          description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_BlkM_GetBlockIsProgramming(uint8 index)
{
    return blockManager.runtime.blockInfo[index].downloadState == FL_BLK_PROGRAM_DOWNLOADING;
}
#if (RTE_BLK_STORAGE_SIGNATURE == STD_ON)
/******************************************************************************/
/*
 * @brief              [Rte_BlkM_SetBlockSignatrue description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [index                      description]
 *                     [signatrue                  description]
 *                     [len                        description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
void Rte_BlkM_SetBlockSignatrue(uint8 index, uint8 * signatrue, uint16 len)
{
    if (index < FL_NUM_LOGICAL_BLOCKS && signatrue != NULL_PTR && len != 0 && len <= blockManager.cfgInfo.blockInfo[index].signatureSize)
    {
        Appl_Memcpy((uint8 *) & (blockManager.nvmInfo.blockInfo[index].signatrue[0]), signatrue, len);
    }
}
/******************************************************************************/
/*
 * @brief              [Rte_BlkM_GetBlockSignatrue description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [index                      description]
 *                     [signatrue                  description]
 *                     [len                        description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
void Rte_BlkM_GetBlockSignatrue(uint8 index, uint8 * signatrue, uint16 len)
{
    if (index < FL_NUM_LOGICAL_BLOCKS && signatrue != NULL_PTR && len != 0 && len <= blockManager.cfgInfo.blockInfo[index].signatureSize)
    {
        Appl_Memcpy((uint8 *) & (blockManager.nvmInfo.blockInfo[index].signatrue[0]), signatrue, len);
    }
}
#endif
/******************************************************************************/
/*
 * @brief              [Rte_FL_Set_EraseInfo description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [addr                 description]
 *                     [len                  description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
void Rte_FL_Set_EraseInfo(uint32 addr, uint32 len)
{
    g_startAddr = addr;
    g_eraselen = len;
}
/******************************************************************************/
/*
 * @brief              [Rte_BlkM_GetBlockEraseStatus description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [index                        description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_BlkM_GetBlockEraseStatus(uint8 index)
{
    boolean ret = FALSE;

    if (index < FL_NUM_LOGICAL_BLOCKS)
    {
        if(blockManager.runtime.blockInfo[index].downloadState == FL_BLK_PROGRAM_ERASED
           || blockManager.runtime.blockInfo[index].downloadState == FL_BLK_PROGRAM_DOWNLOADING)
        {
            ret = TRUE;
        }
    }

    return ret;
}
/******************************************************************************/
/*
 * @brief              [Rte_BlkM_SetBlockEraseStatus description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_BlkM_SetBlockEraseStatus(void)
{
    boolean ret = FALSE;
    uint8 index = 0;

    for (index = 0; index < FL_NUM_LOGICAL_BLOCKS; index++)
    {
        if(
            (blockManager.cfgInfo.blockInfo[index].address <= g_startAddr)
            && (blockManager.cfgInfo.blockInfo[index].address + blockManager.cfgInfo.blockInfo[index].length >= g_startAddr + g_eraselen)
        )
        {
            if (blockManager.runtime.blockInfo[index].downloadState == FL_BLK_PROGRAM_ERASING)
            {
                blockManager.runtime.blockInfo[index].downloadState = FL_BLK_PROGRAM_ERASED;
                ret = TRUE;

                if(blockManager.nvmInfo.blockInfo[index].erased == FALSE)
                {
                    blockManager.nvmInfo.blockInfo[index].erased = TRUE;
#if (RTE_BLK_STORAGE_ERASE_STATUS == STD_ON)

                    if (FL_OK == Rte_BlkM_UpdateNvm())
                    {
                        ret = TRUE;
                    }
                    else
                    {
                        ret = FALSE;
                    }

#endif
                }
            }
        }
    }

    return ret;
}
/******************************************************************************/
/*
 * @brief              [Rte_BlkM_SearchBlock description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [eraseAddress         description]
 *                     [eraseLength          description]
 *                     [StartIdx             description]
 *                     [EndIdx               description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
FL_ResultType Rte_BlkM_SearchBlock(uint32 eraseAddress, uint32 eraseLength
                                   , sint8 *StartIdx
                                   , sint8 *EndIdx
                                  )
{
    FL_ResultType eraseRet = FL_ERR_ADDR_LENGTH;
    uint8 index;
    sint8 continueIdx = -1;
    uint32 blockstartAddress;
    uint32 blockendAddress;
#if (RTE_BLK_ERASE_BLOCK_SUPPORT_CROSS_ZONE == STD_ON)
    uint32 tempAddress;
#endif

    for (index = 0u; index < FL_NUM_LOGICAL_BLOCKS; index++)
    {
        blockstartAddress = blockManager.cfgInfo.blockInfo[index].address;
        blockendAddress = blockstartAddress + blockManager.cfgInfo.blockInfo[index].length;

        if ((blockendAddress <= blockstartAddress) || (eraseAddress + eraseLength <= eraseAddress))
        {
            eraseRet = FL_INVALID_DATA;
            break;
        }

        if (continueIdx == -1)
        {
            /* check if download start address in a config block area */
            if (eraseAddress >= blockstartAddress && eraseAddress < blockendAddress)
            {
                /* check if download end address in a config block area */
                if (eraseAddress + eraseLength <= blockendAddress)
                {
                    eraseRet = FL_OK;
                    continueIdx = index;
                    break;
                }
                else
                {
#if (RTE_BLK_ERASE_BLOCK_SUPPORT_CROSS_ZONE == STD_ON)
                    /* Probably spanned two consecutive blocks */
                    continueIdx = index;
                    tempAddress = blockendAddress;
#else
                    break;
#endif
                }
            }
        }

#if (RTE_BLK_ERASE_BLOCK_SUPPORT_CROSS_ZONE == STD_ON)
        else
        {
            /* If two blocks are consecutive */
            if (tempAddress == blockstartAddress)
            {
                if ((eraseAddress + eraseLength) <= blockendAddress)
                {
                    eraseRet = FL_OK;
                    break;
                }
                else
                {
                    tempAddress = blockendAddress;
                }
            }
            else
            {
                eraseRet = FL_INVALID_DATA;
                break;
            }
        }

#endif
    }

    if(NULL_PTR != StartIdx && FL_OK == eraseRet)
    {
        *StartIdx = continueIdx;
    }


    if(NULL_PTR != EndIdx && FL_OK == eraseRet)
    {
        *EndIdx = index;
    }

    return eraseRet;
}
/*=======[E N D   O F   F I L E]==============================================*/
