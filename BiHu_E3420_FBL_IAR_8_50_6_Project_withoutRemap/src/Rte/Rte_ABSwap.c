/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Rte_ABSwap.c>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for ${tmpl} Module>
 *
 *  @author     <Your Name>
 *  @date       <2024-01-23 16:01:24>
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
#define RTE_ABSWAP_C
/*@}*/
/*=======[I N C L U D E S]====================================================*/
/*=======[Includes]===========================================================*/
/*@{*/
#include "Rte_ABSwap.h"
#include "__regs_base.h"
#include "RegHelper.h"
#include "remap.h"
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
static uint32 bankSerialA;
static uint32 bankSerialB;
static boolean bankSwitch;
/*=======[Private functions]==================================================*/

/**
 * @brief
 * @param  None
 * @retval None
*/
void Rte_ABSwap_Init(void)
{
    boolean writeFlag = TRUE;
    bankSerialA = 1u;
    bankSerialB = 0u;
    if (FALSE == Rte_Data_Read_A_Part_Count(&bankSerialA))
    {
        ;
    }
    else if (FALSE == Rte_Data_Read_B_Part_Count(&bankSerialB))
    {
        ;
    }
    else if ((bankSerialA == bankSerialB) || ((bankSerialA != (bankSerialB + 1u)) && ((bankSerialA + 1u) != bankSerialB)))
    {
        bankSerialA = bankSerialB + 1u;
    }
    else
    {
        writeFlag = FALSE;
    }

    if(TRUE == writeFlag)
    {
        Rte_ABSwap_SetA();
    }

    if (FALSE == Rte_Data_Read_ForceSwap((uint8*)&bankSwitch))
    {
        bankSwitch = FALSE;
    }
}
/**
 * @brief
 * @param  None
 * @retval None
*/
boolean Rte_ABSwap_SetLastBank(void)
{
    boolean ret = FALSE;

    if (TRUE == Rte_ABSwap_isA())
    {
        ret = Rte_ABSwap_SetA();
    }
    else
    {
        ret = Rte_ABSwap_SetB();
    }

    return ret;
}
/**
 * @brief
 * @param  None
 * @retval None
*/
boolean Rte_ABSwap_ForceSwitch(void)
{
    boolean ret = FALSE;

    if (TRUE == bankSwitch)
    {
        bankSwitch = FALSE;
        ret = Rte_ABSwap_Switch();
        Rte_Data_Write_ForceSwap(bankSwitch);
    }
    else
    {
        ret = FALSE;
    }

    return ret;
}
/**
 * @brief
 * @param  None
 * @retval None
*/
boolean Rte_ABSwap_Switch(void)
{
    boolean ret = FALSE;

    if (TRUE == Rte_ABSwap_isA())
    {
        ret = Rte_ABSwap_SetB();
    }
    else
    {
        ret = Rte_ABSwap_SetA();
    }

    /* The reason for commenting on the following code
    is that when the partition flag is switched after
    flashing, subsequent storage operations will be
    operated to another partition, which can also be
    understood as  when the switch partition is
    successful, and it is still running on the
    current partition before it is reset */
    // if(TRUE == ret)
    // {
    //     if (TRUE == Rte_ABSwap_isA())
    //     {
    //         bankSerialB = bankSerialA + 1;
    //     }
    //     else
    //     {
    //         bankSerialA = bankSerialB + 1;
    //     }
    // }

    return ret;
}
/**
 * @brief
 * @param  None
 * @retval None
*/
boolean Rte_ABSwap_SwitchBankFlag(void)
{
    boolean ret = FALSE;
    uint32 temp = bankSerialA;
    bankSerialA = bankSerialB;
    bankSerialB = temp;
    ret = TRUE;
    return ret;
}
/**
 * @brief
 * @param  None
 * @retval None
*/
boolean Rte_ABSwap_isA(void)
{
    boolean ret = TRUE;

    if((bankSerialB - 1) == bankSerialA)
    {
        ret = FALSE;
    }

    return ret;
}
/**
 * @brief
 * @param  None
 * @retval None
*/
boolean Rte_ABSwap_SetA(void)
{
    boolean ret = TRUE;
    ret = Rte_Data_Write_A_Part_Count(bankSerialB + 1);
    return ret;
}
/**
 * @brief
 * @param  None
 * @retval None
*/
boolean Rte_ABSwap_SetB(void)
{
    boolean ret = TRUE;
    ret = Rte_Data_Write_B_Part_Count(bankSerialA + 1);
    return ret;
}
/*=======[E N D   O F   F I L E]==============================================*/

/*=======[E N D   O F   F I L E]==============================================*/
