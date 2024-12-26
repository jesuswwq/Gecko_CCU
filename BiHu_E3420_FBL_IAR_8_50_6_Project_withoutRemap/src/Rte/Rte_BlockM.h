/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Rte_BlockM.h>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for Rte_BlockM Module>
 *
 *  @author     <your Name>
 *  @date       <2024-01-03>
 *
 *
 *
 *  May be changed by User [yes/no]: no
 */
/*============================================================================*/
#ifndef RTE_BLOCKM_H
#define RTE_BLOCKM_H
#ifdef __cplusplus
extern "C" {
#endif /* cplusplus */
/*@{*/
//#define RTE_BLOCKM_C
/*@}*/
#ifndef RTE_BLOCKM_C
#define RTE_BLOCKM_EXPT extern
#else
#define RTE_BLOCKM_EXPT
#endif
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/** <VERSION>   <DATE>      <AUTHOR>     <REVISION LOG>*/
/*============================================================================*/
/*=======[ Includes ]=========================================================*/
#include "Std_Types.h"
#include "FL.h"
#include "Appl_Cfg.h"
#include "Rte_Fl_Cfg.h"
/*=======[ Exported define ]==================================================*/
#define RTE_BLK_STORAGE_SIGNATURE RTE_CFG_BLK_STORAGE_SIGNATURE
#define RESERVED_CAL_SIZE(x,y) (sizeof(uint32) - (sizeof(x)*(y)) % sizeof(uint32))
/*=======[ Exported types ]===================================================*/
/* needed in the interface between flashloader runtime environment and security module */
typedef struct
{
    /* block start global address */
    const uint32 address;

    /* block length */
    const uint32 length;

#if (RTE_BLK_STORAGE_SIGNATURE == STD_ON)
    /* block signature start global address */
    const uint32 signatureAddr;

    /* block signature size */
    const uint32 signatureSize;
#endif

    /* Whether the block affects
    the validity check */
    const boolean checkFlag;

    /* Whether the "checkFlag"
    can be changed */
    const boolean checkFlagCanbeChanged;

} Rte_FL_BlockDescriptorType;

typedef struct
{
    boolean erased;

    boolean intergrity;

    boolean compatibility;

    uint8 Reserved[RESERVED_CAL_SIZE(uint8, (sizeof(boolean) * 3))];
#if (RTE_BLK_STORAGE_SIGNATURE == STD_ON)
    uint8 signatrue[SECM_SIGNATURE_LENGTH];
#endif
} Rte_FL_blockNvmInfoType;

/** Total block information */
typedef struct
{

    Rte_FL_blockNvmInfoType blockInfo[FL_NUM_LOGICAL_BLOCKS];

    boolean intergrity;

    boolean compatibility;

    boolean valid;

    uint8 Reserved[RESERVED_CAL_SIZE(uint8, (sizeof(boolean) * 3 + sizeof(uint16)))];

    uint16 checksum;
} Rte_FL_NvmInfoType;
/*=======[ Exported variables ]===============================================*/
/*=======[ Exported functions ]===============================================*/

RTE_BLOCKM_EXPT Rte_FL_NvmInfoType * Rte_BlkM_GetNvmInfo(void);
RTE_BLOCKM_EXPT Rte_FL_BlockDescriptorType * Rte_BlkM_GetCfgInfo(void);
RTE_BLOCKM_EXPT FL_ResultType Rte_BlkM_UpdateNvm(void);
RTE_BLOCKM_EXPT void Rte_BlkM_InitBlockInfo(void);
RTE_BLOCKM_EXPT boolean Rte_BlkM_ActiveBlockInfo(void);
RTE_BLOCKM_EXPT void Rte_BlkM_SetBlockInValid(uint8 index);
RTE_BLOCKM_EXPT FL_ResultType Rte_BlkM_SetBlockDownloading(uint32 requesetAddr, uint32  requesetlen);
RTE_BLOCKM_EXPT void Rte_BlkM_SetBlockCompatibility(uint8 index);
RTE_BLOCKM_EXPT void Rte_BlkM_SetBlockIntergrity(uint8 index);
RTE_BLOCKM_EXPT void Rte_BlkM_SetBlocksDownloadFinish(void);
RTE_BLOCKM_EXPT FL_ResultType Rte_BlkM_SetIfAppValid(void);
RTE_BLOCKM_EXPT FL_ResultType Rte_BlkM_CheckCompatibility(void);
RTE_BLOCKM_EXPT boolean Rte_BlkM_GetCompatibility(void);
RTE_BLOCKM_EXPT boolean Rte_BlkM_GetIntergrity(void);
RTE_BLOCKM_EXPT boolean Rte_BlkM_GetAppValid(void);
RTE_BLOCKM_EXPT boolean Rte_BlkM_GetIsProgramed(void);
RTE_BLOCKM_EXPT boolean Rte_BlkM_GetIsProgramming(void);
RTE_BLOCKM_EXPT boolean Rte_BlkM_GetBlockIsProgramming(uint8 index);
#if (RTE_BLK_STORAGE_SIGNATURE == STD_ON)
RTE_BLOCKM_EXPT void Rte_BlkM_SetBlockSignatrue(uint8 index, uint8 * signatrue, uint16 len);
RTE_BLOCKM_EXPT void Rte_BlkM_GetBlockSignatrue(uint8 index, uint8 * signatrue, uint16 len);
#endif
RTE_BLOCKM_EXPT void Rte_FL_Set_EraseInfo(uint32 addr, uint32 len);
RTE_BLOCKM_EXPT boolean Rte_BlkM_GetBlockEraseStatus(uint8 index);
RTE_BLOCKM_EXPT boolean Rte_BlkM_SetBlockEraseStatus(void);
RTE_BLOCKM_EXPT FL_ResultType Rte_BlkM_SearchBlock(uint32 eraseAddress, uint32 eraseLength
                                   , sint8 *StartIdx
                                   , sint8 *EndIdx
                                  );

#ifdef __cplusplus
}
#endif /* cplusplus */
#endif
/*=======[E N D   O F   F I L E]==============================================*/

