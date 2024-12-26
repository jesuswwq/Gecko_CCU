/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Det_Api.c>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for ${tmpl} Module>
 *
 *  @author     <Your Name>
 *  @date       <2023-04-12 10:36:09>
 *
 *
 *
 *  May be changed by User [yes/no]: no
 */
/*============================================================================*/
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/** <VERSION>   <DATE>      <AUTHOR>     <REVISION LOG> */
/*@{*/
#define DET_API_C
/*@}*/
/*=======[I N C L U D E S]====================================================*/
/*=======[Includes]===========================================================*/
/*@{*/
#include "Det_Api.h"
/*@}*/
/*=======[Private define]=====================================================*/
/*=======[Private types]======================================================*/
/*=======[Private function prototypes]========================================*/
/*=======[Private variables]==================================================*/
/*=======[Private functions]==================================================*/
/**
 * @brief
 * @param  None
 * @retval None
*/
void Det_ReportError(uint8 i1, uint8 i2, uint8 i3, uint8 i4)
{
	static uint32 cnt = 0;
	cnt++;
}
/**
 * @brief
 * @param  None
 * @retval None
*/
void Det_ReportRuntimeError(uint32 i1, uint32 i2, uint32 i3, uint32 i4)
{
	static uint32 cnt = 0;
	cnt++;
}
/**
 * @brief
 * @param  None
 * @retval None
*/
void Det_ReportTransientFault(uint8 i1, uint8 i2, uint8 i3, uint8 i4)
{
	static uint32 cnt = 0;
	cnt++;
}
/*=======[E N D   O F   F I L E]==============================================*/
