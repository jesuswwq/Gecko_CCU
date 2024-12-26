/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2023)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : Appl_Callout.c                                              **
**                                                                            **
**  Created on  : 2024/04/11 14:04:03                                         **
**  Author      : long.zhu                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Implementation for Appl .                                   **
**                                                                            **
**  SPECIFICATION(S) : NONE                                                   **
**                                                                            **
*******************************************************************************/
/******************************************************************************
**                      Revision Control History                             **
******************************************************************************/
/*  <VERSION>    <DATE>      <AUTHOR>     <REVISION LOG>
 *   V1.0.0     20230818     long.zhu        Initial version
 */

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Appl_Callout.h"
#include "CanIf.h"
#include "CanTp.h"
#include "GptIf.h"
#include "WdgIf.h"
#include "Can_Trcv.h"
#include "Rte_Inc.h"
#include "Mcu.h"
#include "Port.h"
#include "MemIf_Types.h"
#include "IrqM_Cfg.h"
#include "Spi.h"
#include "I2c.h"
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/** timer counter for ECU shut down */
#if (APPL_SLEEP_TIMER > 0u)
static uint32 ApplShutDownTimer;
#endif
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/**********************************************************************************************/
/**
 * @brief               <ECU Dependency Driver Initialization>
 * <This routine should be called by the boot code to initialize the ECU Dependency Driver> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/**********************************************************************************************/
void Appl_EcuDrvInit(void)
{

#if (RTE_CFG_JUMP_APP_RESET_ENABLE == STD_ON)
    Rte_ResetJump_Check();
#endif    
    /* ECU Driver Initialization */
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK EcuDrvInit>
    */
#if 0
    Mcu_Init(&Mcu_Cfg);
    Mcu_InitClock(0);
    while (MCU_PLL_LOCKED != Mcu_GetPllStatus())
    {
        /* Busy wait until the System PLL is locked */
    }
    Mcu_DistributePllClock();
    Mcu_SetMode(MCU_MODE_RUN);
    Port_Init((&Port_Cfg);
#endif
    //Spi_Init(Spi_Config);
    I2c_Init();


    CanTrcv_Init();

    GptIf_Init();

#if (APPL_ENABLE_WATCHDOG_MONITORING_IN_BOOT == STD_ON)
    WdgIf_Init();
#endif

    IrqM_Init();

    arch_disable_cache(ICACHE | DCACHE);
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
    //Rte_Test();
}

/**********************************************************************************************/
/**
 * @brief               <ECU Network Bus initialize>
 * <This routine should be called by the boot code to initialize the network bus protocol> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/**********************************************************************************************/
void Appl_EcuNetBusInit(void)
{
    /* CanIf Module Init */
    CanIf_Init();
    /* CAN Transport Protocol Initialization */
    CanTp_Init();
    #if (APPL_SLEEP_TIMER > 0u)
    /* set ECU shut down timer */
    ApplShutDownTimer = (uint32)(APPL_SLEEP_TIMER / GPT_PERIOD_TIME);
    #endif
}

/**********************************************************************************************/
/**
 * @brief               <ECU Dependency Driver Deinitialization>
 * <This routine should be called by the boot code to deinitialize the ECU Dependency Driver> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/**********************************************************************************************/
void Appl_EcuDrvDeinit(void)
{
    /* ECU Driver deinitialization */
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK EcuDrvDeinit>
    */
    CanIf_DeInit();
    CanTrcv_DeInit();
    GptIf_Deinit();
	WdgIf_Deinit();
    IrqM_DeInit();
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
}

/******************************************************************************/
/**
 * @brief               <check application software Dependence>
 *
 * <This routine shall be called by the flashloader to check whether the
 *  individual parts (logical blocks) that make up the application software of
 *  an ECU are consistent with each other.> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_ResultType>
 */
/******************************************************************************/
FL_ResultType Appl_CheckDependence(void)
{
    FL_ResultType retVal;
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK CheckDependence>
    */
    /* to do. */
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
    retVal = (uint8)FL_OK;
    return retVal;
}

/******************************************************************************/
/**
 * @brief               <jump to application software>
 *
 * <jump to application software> .
 * @param[in]           <address:Jump address.>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Appl_AdaptiveJumpApp(uint32 address)
{
    /* The jump application software corresponds to the chip implementation.*/
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK JumpApp>
    */
    Rte_Jump();
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
}
#if (APPL_SLEEP_TIMER > 0u)
/******************************************************************************/
/**
 * @brief               <ECU goto sleep mode>
 *
 * <This routine shall be called by the flash loader to shut down the ECU condition(put
 *  the ECU to sleep).> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <retVal:TRUE/FALSE>
 */
/******************************************************************************/
boolean Appl_EcuShutdownCondition(void)
{
    boolean retVal = FALSE;
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK ShutdownCondition>
    */
    /* to do. */
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
    return retVal;
}

/******************************************************************************/
/**
 * @brief               <ECU goto sleep mode>
 *
 * <This routine shall be called by the flash loader to shut down the ECU (put
 *  the ECU to sleep).> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Appl_EcuShutdown(void)
{
    /* do nothing */
    /* reserved for user, application related */
    return;
}
#endif

#if (APPL_ENABLE_WATCHDOG_MONITORING_IN_BOOT == STD_ON)
/******************************************************************************/
/**
 * @brief               <Timeout watchdog feed the dog.>
 *
 * <Timeout watchdog feed the dog.> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Appl_wdTriggerFct(void)
{
    /* Timeout watchdog feed the dog. */
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK wdTrigger>
    */
    WdgIf_MainFunction();
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
}
#endif
#if(FL_ABSWAP_ENABLE == STD_ON)
/******************************************************************************/
/**
 * @brief               <AB swap>
 * <> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Appl_SwapSwitch(void)
{
}

/******************************************************************************/
/**
 * @brief               <get external swap request.>
 *
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <boolean>
 */
/******************************************************************************/
boolean Appl_GetExternalABSWapRequested(void)
{
    boolean retVal = FALSE;
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK ExternalABSWapRequested>
    */
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
    return retVal;
}
/******************************************************************************/
/**
 * @brief               <Check whether the partition peripherals are successfully started.>
 *
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <boolean>
 */
/******************************************************************************/
boolean Appl_GetABSWapEnableStatus(void)
{
    boolean retVal = TRUE;
    /*to do*/
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK ABSWapEnableStatus>
    */
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
    return retVal;
}
#endif
/******************************************************************************/
/**
 * @brief               <convert address, only used for triCore Platform>
 * <> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <address>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <uint32>
 */
/******************************************************************************/
uint32 Appl_ConvertAddress(uint32 address)
{
    uint32 converAddress = address;
    /* convert the address 0x8xxxxxxx to 0xAxxxxxxx */
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK ConvertAddress>
    */
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
    return converAddress;
}
/******************************************************************************/
/**
 * @brief               <convert logic address>
 * <> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Reentrant>
 * @param[in]           <address>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <uint32>
 */
/******************************************************************************/
uint32 Appl_ConvertLogicAddress(uint32 address)
{
    uint32 converAddress = address;
    /** DO NOT CHANGE THIS COMMENT!
    * <USERBLOCK ConvertLogicAddress>
    */
    /** DO NOT CHANGE THIS COMMENT!
    * </USERBLOCK>
    */
    return converAddress;
}
/******************************************************************************/
/*
 * @brief              [Rte_Reset description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
void Rte_Reset(void)
{
    uint32 _1024msFlag = 0;

    Mcu_PerformReset();
    /* wait until reset */
    for (;;)
    {

        if ((++_1024msFlag & (((uint32)1u << 10) - 1u)) == (((uint32)1u << 10) - 1u))
        {

        }
    }
}
/******************************************************************************/
/*
 * @brief              [Rte_isWarmStart description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [description]
 */
/******************************************************************************/
boolean Rte_isWarmStart(void)
{
    boolean ret = FALSE;
    Mcu_ResetType resetType = Mcu_GetResetReason();
    if (MCU_COLD_RESET == resetType)
    {

    }
    else if (MCU_SW_RESET == resetType || MCU_WATCHDOG_RESET == resetType)
    {
        ret = TRUE;
    }
    return ret;
}
/******************************************************************************/
/*
 * @brief              [Mcu_PflashTrapDisable description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
void Mcu_PflashTrapDisable(void)
{
}
/******************************************************************************/
/*
 * @brief              [Mcu_PflashTrapEnable description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
void Mcu_PflashTrapEnable(void)
{
}
/*=======[E N D   O F   F I L E]==============================================*/
