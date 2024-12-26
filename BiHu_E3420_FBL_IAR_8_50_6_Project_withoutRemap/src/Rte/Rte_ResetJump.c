/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Rte_ResetJump.c>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for ${tmpl} Module>
 *
 *  @author     <Your Name>
 *  @date       <2023-11-24 17:16:42>
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
#define RTE_RESETJUMP_C
/*@}*/
/*=======[I N C L U D E S]====================================================*/
/*=======[Includes]===========================================================*/
/*@{*/
#include "Rte_ResetJump.h"
#include "DP.h"
#include "FL.h"
//#include <stdlib.h>
#include "Mcu.h"
#include "e3_kick_core.h"
#include "Appl_Callout.h"
#include "Rte_Inc.h"

/*@}*/
/*=======[Private define]=====================================================*/
/*@{*/
#define RTE_JUMP_APP_ADDR RTE_CFG_JUMP_APP_ADDR
#define RTE_JUMP_APP_SIZE RTE_CFG_JUMP_APP_SIZE
#define RTE_JUMP_APP_REQUEST_RECEIVED RTE_CFG_JUMP_APP_REQUEST_RECEIVED
#define RTE_JUMP_APPB_REQUEST_RECEIVED RTE_CFG_JUMP_APPBACK_REQUEST_RECEIVED
#define RTE_APP_START_RAM_ADDR RTE_CFG_APP_START_RAM_ADDR
#define RTE_APP_START_RAM_END RTE_CFG_APP_START_RAM_END
#define RTE_APP_START_FLASH_ADDR RTE_CFG_APP_START_FLASH_ADDR
#define RTE_APP_START_FLASH_OFFSET RTE_CFG_APP_START_FLASH_OFFSET
#define Appl_JumpApp(addr)\
    do\
    {\
        ((void (*)(void))((addr)))();\
    } while (0);

/*@}*/
/*=======[Private types]======================================================*/
/*@{*/
/*@}*/
/*=======[Private function prototypes]========================================*/
/*@{*/
#if (RTE_JUMP_APP_RESET_ENABLE == STD_ON)
extern void Appl_EcuReset(void);
#endif
/*@}*/
/*=======[Private variables]==================================================*/
/*@{*/
/*@}*/
/*=======[Private functions]==================================================*/
/*@{*/
#if (RTE_JUMP_APP_RESET_ENABLE == STD_ON)
static void Rte_ResetJump_Set_Flag(void);
#endif
/*@}*/
/******************************************************************************/
/*
 * @brief              [Rte_Jump description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
void Rte_Jump(void)
{
#if (RTE_JUMP_APP_RESET_ENABLE == STD_ON)
    Rte_ResetJump_Set_Flag();
    Appl_EcuReset();
#else
#if (RTE_PARTITION_SWAP_ON == STD_ON)

    uint32 addr = RTE_APP_START_FLASH_ADDR;
    if(TRUE == Rte_ABSwap_isA())
    {
        addr=RTE_APP_START_FLASH_ADDR;
    }
    else
    {
        addr=RTE_APP_START_FLASH_ADDR+RTE_APP_START_FLASH_OFFSET;
    }

    /* tcm 64unit */
    Rte_Data_Write_JUMP_VECTOR_INFO(addr);
#if 0
    volatile uint8 i = 0;
    while(i==0);
#endif
    soc_kick_core (KICK_CR5_SF,addr);

#else
    Appl_JumpApp(RTE_APP_START_FLASH_ADDR);
#endif
#endif
}
#if (RTE_JUMP_APP_RESET_ENABLE == STD_ON)
/******************************************************************************/
/*
 * @brief              [Rte_ResetJump_Set_Flag description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
static void Rte_ResetJump_Set_Flag(void)
{
#if (RTE_PARTITION_SWAP_ON == STD_ON)
    uint8 ProgSignature[RTE_JUMP_APP_SIZE] = {RTE_JUMP_APP_REQUEST_RECEIVED};
    uint8 ProgSignatureB[RTE_JUMP_APP_SIZE] = {RTE_JUMP_APPB_REQUEST_RECEIVED};
    if(FALSE == Rte_ABSwap_isA())
    {
        Rte_Data_Write_RESET_JUMP_Flag(ProgSignatureB);
    }
    else
    {
        Rte_Data_Write_RESET_JUMP_Flag(ProgSignature);
    }
#else
    uint8 ProgSignature[RTE_JUMP_APP_SIZE] = {RTE_JUMP_APP_REQUEST_RECEIVED};
    Rte_Data_Write_RESET_JUMP_Flag(ProgSignature);
    uint8 ResetCause[RTE_DATA_RESETCAUSE_TCM_LEN] = 
    {
        0u,0u,0u,0u,
        0u,0u,0u,0u,
    };
    ResetCause[0] = Mcu_GetResetReason();
    Rte_Data_Write_RESET_CAUSE(ResetCause);
#endif
}


/******************************************************************************/
/*
 * @brief              [Rte_ResetJump_Check description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
void Rte_ResetJump_Check(void)
{
    boolean ret = FALSE;
    /* ----------------projectCfg---------------- */
#if (RTE_PARTITION_SWAP_ON == STD_ON)
    uint64 *dest;
    uint64 *source;
    uint32 length;
    uint8 ProgSignatureB[RTE_JUMP_APP_SIZE] = {RTE_JUMP_APPB_REQUEST_RECEIVED};
#endif    
    uint32 addr = RTE_APP_START_FLASH_ADDR;
    uint8 ProgSignature[RTE_JUMP_APP_SIZE] = {RTE_JUMP_APP_REQUEST_RECEIVED};
    uint8 ProgReqReadBuf[RTE_JUMP_APP_SIZE] = {0};
    if (FALSE == Rte_isWarmStart())
    {
        ; /* Not a warm start */
    }
    else
    {
        if(FALSE == Rte_Data_Read_RESET_JUMP_Flag(ProgReqReadBuf))
        {
            ;
        }
        else if (TRUE == DP_Memcompare(ProgSignature, ProgReqReadBuf, RTE_JUMP_APP_SIZE))
        {
            addr=RTE_APP_START_FLASH_ADDR;
            ret = TRUE;
        }
#if (RTE_PARTITION_SWAP_ON == STD_ON)    
        else if (TRUE == DP_Memcompare(ProgSignatureB, ProgReqReadBuf, RTE_JUMP_APP_SIZE))
        {
            addr=RTE_APP_START_FLASH_ADDR+RTE_APP_START_FLASH_OFFSET;
            ret = TRUE;
        }
#endif       
        else
        {
            ;
        }
    }
    /* tcm 64unit */
    DP_Memset(ProgReqReadBuf,0,sizeof(ProgReqReadBuf));
    Rte_Data_Write_RESET_JUMP_Flag(ProgReqReadBuf);

    if(ret == TRUE)
    {
#if (RTE_PARTITION_SWAP_ON == STD_ON)        
        Rte_Data_Write_JUMP_VECTOR_INFO(addr);
#endif        
#if (RTE_APP_START_RAM_ADDR != 0)
        DP_Memcpy((uint8 *)RTE_APP_START_RAM_ADDR, (uint8 *)addr, RTE_APP_START_RAM_END-RTE_APP_START_RAM_ADDR);
        Appl_JumpApp(RTE_APP_START_RAM_ADDR);
#else
#if (RTE_PARTITION_SWAP_ON == STD_ON) 
        dest = (uint64 *)0ul;
        length = 0x400000ul/8ul;
        while (length > 0ul)
        {
            *dest = 0ul;
            dest++;
            length--;
        }
        dest = (uint64 *)0ul;
        source = (uint64 *)addr;
        length = 0x400000ul/8ul;
        while (length > 0ul)
        {
            *dest = *source;
            dest++;
            source++;
            length--;
        }
        Appl_JumpApp(0ul);
#else        
        Appl_JumpApp(addr);
#endif        
#endif
        while(1);
    }
    /* ----------------projectCfg end---------------- */
}
#endif
/*=======[E N D   O F   F I L E]==============================================*/
