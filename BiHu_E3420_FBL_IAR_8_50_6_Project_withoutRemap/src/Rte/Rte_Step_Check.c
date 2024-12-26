/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Rte_Step_Check.c>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for ${tmpl} Module>
 *
 *  @author     <Your Name>
 *  @date       <2024-08-01 16:57:27>
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
#define RTE_STEP_CHECK_C
/*@}*/
/*=======[I N C L U D E S]====================================================*/
/*=======[Includes]===========================================================*/
/*@{*/
#include "Rte_Step_Check.h"
/*@}*/
/*=======[Private define]=====================================================*/
/*@{*/
#define RTE_STEP_IDLE 0u
#define RTE_STEP_ERASE 1u
#define RTE_STEP_CHECKSUM 2u
#define RTE_STEP_CHECKCOM 3u
/*@}*/
/*=======[Private types]======================================================*/
/*@{*/
static uint8 step;
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
 * @brief              [Rte_Step_Check_Idle  description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_Step_Check_Idle (void)
{
	boolean ret;

	if (step == RTE_STEP_IDLE)
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
 * @brief              [Rte_Step_Check_CheckSum  description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_Step_Check_CheckSum (void)
{
	boolean ret;

	if (step == RTE_STEP_CHECKSUM)
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
 * @brief              [Rte_Step_Check_CheckCompability  description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_Step_Check_CheckCompability (void)
{
	boolean ret;

	if (step == RTE_STEP_CHECKCOM)
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
 * @brief              [Rte_Step_Check_Init  description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_Step_Check_Init (void)
{
	boolean ret;

	step = RTE_STEP_IDLE;

	return ret;
}
/******************************************************************************/
/*
 * @brief              [Rte_Step_Set_CheckSUm  description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_Step_Set_erase (void)
{
	boolean ret;

	step = RTE_STEP_ERASE;

	return ret;
}
/******************************************************************************/
/*
 * @brief              [Rte_Step_Set_CheckSUm  description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_Step_Set_CheckSUm (void)
{
	boolean ret;

	step = RTE_STEP_CHECKSUM;

	return ret;
}
/******************************************************************************/
/*
 * @brief              [Rte_Step_Set_CheckCompabilit  description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_Step_Set_CheckCompabilit (void)
{
	boolean ret;

	step = RTE_STEP_CHECKCOM;

	return ret;
}
/*=======[E N D   O F   F I L E]==============================================*/
