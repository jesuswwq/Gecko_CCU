/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Rte_Fl_Cfg.c>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for ${tmpl} Module>
 *
 *  @author     <Your Name>
 *  @date       <2024-01-03 15:49:23>
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
#define RTE_FL_CFG_C
/*@}*/
/*=======[I N C L U D E S]====================================================*/
/*=======[Includes]===========================================================*/
/*@{*/
#include "Rte_Fl_Cfg.h"
#include "FL.h"
#include "Rte_Inc.h"
/*@}*/
/*=======[Private define]=====================================================*/
/*@{*/
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

#if !defined PROJECT_FLS && !defined PROJECT_APP
__attribute__((section(".bootver")))
#endif
const uint8 FL_Bl_Version[RTE_CFG_VERSION_LEN] = /*PRQA S 3408*/
{
    1, 2, 23, 4
};

/*@}*/
/* distinction By block ,
 * should make memory layout first, if the 31 erase service
 * request is in the range of block */
const Rte_FL_BlockDescriptorType FL_BlkInfoExt[FL_NUM_LOGICAL_BLOCKS] =
{
    /* start global address, length, integrity info, dependence info,
     * FL download block type, if TRUE, then participate in the verification of Dependencies.*/
    {
        /* block start global address */
        (uint32)RTE_CFG_APP_START_FLASH_ADDR,
        /* block memory length */
        (uint32)RTE_CFG_APP_START_FLASH_END - RTE_CFG_APP_START_FLASH_ADDR,
        TRUE,
        FALSE
    },
};
#if (RTE_PARTITION_SWAP_ON == STD_ON)
const Rte_FL_BlockDescriptorType FL_BlkInfoExtB[FL_NUM_LOGICAL_BLOCKS] =
{
    /* start global address, length, integrity info, dependence info,
     * FL download block type, if TRUE, then participate in the verification of Dependencies.*/
    {
        /* block start global address */
        (uint32)RTE_CFG_APP_START_FLASH_ADDR+RTE_CFG_APP_START_FLASH_OFFSET,
        /* block memory length */
        (uint32)RTE_CFG_APP_START_FLASH_END-RTE_CFG_APP_START_FLASH_ADDR,
        TRUE,
        FALSE
    },
};
#endif
/*=======[E N D   O F   F I L E]==============================================*/
