/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Rte_Address.c>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for ${tmpl} Module>
 *
 *  @author     <Your Name>
 *  @date       <2023-11-24 17:15:08>
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
#define RTE_ADDRESS_C
/*@}*/
/*=======[I N C L U D E S]====================================================*/
/*=======[Includes]===========================================================*/
/*@{*/
#include "Rte_Address.h"
#include "FL.h"
#include "Rte_Inc.h"

/*@}*/
/*=======[Private define]=====================================================*/
/*@{*/
#define RTE_APP_START_FLASH_OFFSET RTE_CFG_APP_START_FLASH_OFFSET
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
/******************************************************************************/
/*
 * @brief              [Rte_Appl_ConvertAddress description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [address                 description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
uint32 Rte_Appl_ConvertAddress(uint32 address)
{
    uint32 converAddress = address;

    /* ----------------projectCfg---------------- */
#if (RTE_PARTITION_SWAP_ON == STD_ON)
    if(TRUE == Rte_ABSwap_isA() && TRUE == FL_GetFLDownloaded())
    {
        converAddress += RTE_APP_START_FLASH_OFFSET;
    }
#endif
    /* ----------------projectCfg end---------------- */

    return converAddress;
}
/******************************************************************************/
/*
 * @brief              [Rte_Appl_ConvertSize description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [sz                   description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
uint32 Rte_Appl_ConvertSize(uint32 sz)
{
    /* ----------------projectCfg---------------- */
    uint32 conversz = sz;
    /* ----------------projectCfg end---------------- */

    return conversz;
}
/******************************************************************************/
/*
 * @brief              [Rte_Appl_CheckAddrAndLen description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [addr                     description]
 *                     [len                      description]
 *                     [tarAddr                  description]
 *                     [tarLen                   description]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_Appl_CheckAddrAndLen(uint32 addr, uint32 len, uint32 tarAddr, uint32 tarLen)
{
    boolean ret = FALSE;

    if (((addr + len) > addr)
        && ((tarAddr + tarLen) > tarAddr)
        && (addr >= tarAddr)
        && (addr + len) <= (tarAddr + tarLen))
    {
        ret = TRUE;
    }

    return ret;
}
/*=======[E N D   O F   F I L E]==============================================*/
