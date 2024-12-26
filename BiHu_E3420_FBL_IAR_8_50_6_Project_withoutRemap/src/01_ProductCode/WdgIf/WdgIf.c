/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <WdgIf.c>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for ${tmpl} Module>
 *
 *  @author     <Your Name>
 *  @date       <2024-04-03 14:28:59>
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
#define WDGIF_C
/*@}*/
/*=======[I N C L U D E S]====================================================*/
/*=======[Includes]===========================================================*/
/*@{*/
#include "WdgIf.h"
#include "Appl_Cfg.h"
/* ----------------projectCfg---------------- */


#include "Wdg_140_Instance1_Wdt.h"

/* ----------------projectCfg end---------------- */
/*@}*/
/*=======[Private define]=====================================================*/
/*@{*/
#define FeedWDGCounterMAX 5000u
#define FeedWDGCounterMin (APPL_WATCHDOG_FEEDING_TIME)
/*@}*/
/*=======[Private types]======================================================*/
/*@{*/
/*@}*/
/*=======[Private function prototypes]========================================*/
/*@{*/
/*@}*/
/*=======[Private variables]==================================================*/
/*@{*/
extern uint32 Dcm_SecMSeedCount;
/*@}*/
/*=======[Private functions]==================================================*/
/*@{*/
void WdgTimeoutNotificationFct (void)
{
    volatile uint32 test = 0;
    test++;
}
/*@}*/
/*
 * Brief               <This function initializes the Watchdog driver>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
void WdgIf_Init(void)
{
#if (APPL_ENABLE_WATCHDOG_MONITORING_IN_BOOT == STD_ON)
    Wdg_140_Instance1_Wdt_Init(&Wdg_Config1);
    Wdg_140_Instance1_Wdt_TriggerRoutine();
#endif
}

/******************************************************************************/
/*
 * Brief               <This function de-initialize Watchdog.>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
void WdgIf_Deinit(void)
{
#if (APPL_ENABLE_WATCHDOG_MONITORING_IN_BOOT == STD_ON)

    Wdg_140_Instance1_Wdt_SetMode(WDGIF_OFF_MODE);
#endif
}

/**********************************************************/
/*
 * Brief               <Timeout watchdog feed the dog.>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/*******************************************************/
void WdgIf_SetTriggerCondition(void)
{
#if (APPL_ENABLE_WATCHDOG_MONITORING_IN_BOOT == STD_ON)
    Wdg_140_Instance1_Wdt_TriggerRoutine();
#endif
}

/**********************************************************/
/*
 * Brief               <Timeout watchdog feed the dog.>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/*******************************************************/
void WdgIf_SetTriggerAttempt(void)
{
    if ((Dcm_SecMSeedCount & (FeedWDGCounterMAX - 1U)) >= FeedWDGCounterMin)
    {
        WdgIf_SetTriggerCondition();
    }
}
/**********************************************************/
/*
 * Brief               <Timeout watchdog feed the dog.>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/*******************************************************/
void WdgIf_SetTriggerForward(uint32 delt)
{
    Dcm_SecMSeedCount += delt;
    WdgIf_SetTriggerAttempt();
}
/**********************************************************/
/*
 * Brief               <Timeout watchdog feed the dog.>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/*******************************************************/
void WdgIf_MainFunction(void)
{
    if ((Dcm_SecMSeedCount++ & (FeedWDGCounterMAX - 1U)) > ((FeedWDGCounterMAX + FeedWDGCounterMin) >> 1U)) // 1024
    {
        WdgIf_SetTriggerCondition();
        Dcm_SecMSeedCount = 0;
    }
}
/*=======[E N D   O F   F I L E]==============================================*/
