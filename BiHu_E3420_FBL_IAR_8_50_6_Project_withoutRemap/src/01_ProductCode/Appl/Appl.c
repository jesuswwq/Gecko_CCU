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
**  FILENAME    : Appl.c                                                      **
**                                                                            **
**  Created on  :                                                             **
**  Author      :  long.zhu                                                   **
**  Vendor      :                                                             **
**  DESCRIPTION : App Loader.                                                 **
**                                                                            **
**  SPECIFICATION(S) :   None                   		                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *   V1.0.0    20121227     Gary            Initial version
 *   V1.0.1    20161015     cywang          update
 *   V1.0.2    20180515     CChen           update
 *   V1.0.3    20200412     Lianren.wu      code optimization
 *   V1.0.4    20200426     Lianren.wu      optimization the code when the
 *                                          FL_EXT_PROG_REQUEST_RECEIVED is valid.
 *   V1.0.5    20200616     Lianren.wu      Wdg_Init should set after Mcu_Init in
 *                                          Appl_EcuStartup,so that if error the
 *                                          dog will be used.
 *   V1.0.6    20200913     Lianren.wu      add the if condition in Appl_CheckConsistency.
 *   V1.0.7    20201210     Lianren.wu      modify the function Appl_InitNvmInfo
 *                                          and Appl_CheckConsistency, according
 *                                          to the change of FL module.
 *	 V1.0.8    20231208     Long.Zhu		1.Delete unnecessary assignment logic from Appl_InitNvmInfo function.
 *											2.The security unlocking times initialization logic is reconstructed.
 *											3.The sleep logic is used as an interface.
 *											4.Compatibility check flag processing logic.
 *   V1.0.9    20231219     yaowei.shen     1.Appl_CheckConsistency add a parameter
 *                                          2.add function Appl_ConvertLogicAddress
 *   V1.0.10   20240402     Long.Zhu        Code comment review
 *   V1.0.11   20240403     Long.Zhu        The Ram area is cleared only after the flashdriver is downloaded.
 *   V1.0.12   20240403     Chunjun.hua     Rearrange app jump code
 *   V1.0.13   20230411		yaowei.shen		1.add check external program positive response suppression
 *   										2.fixed FlBootMode2 value clear  use macro APPL_EXT_PROG_POSITIVE_RSP_REQUEST_RECEIVED_LENGTH;
 *   										3.clear FlBootMode2 value after used
 *   V1.0.14   20240424     chunjun.hua     QAC fix
 */
/**
  \page ISOFT_MISRA_Exceptions  MISRA-C:2012 Compliance Exceptions
    ModeName:Appl .<br>
  RuleSorce:puhua-rule2024.rcf 1.0.2

    \li PRQA S 0306 Rule-11.4 .<br>
    Reason: The integral type expression address

    \li PRQA S 2982 Rule-2.2 .<br>
    Reason: This assignment is redundant. The value of this object is never used before being modified.

    \li PRQA S 2995 Rule-2.2 .<br>
    Reason: The result of this logical operation is always 'true'.

    \li PRQA S 2991 Rule-14.3 .<br>
    Reason: The value of this 'if' controlling expression is always 'true'.
 */
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Appl.h"
#include "GptIf.h"
#include "Rte_Inc.h"
/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#if (APPL_SLEEP_TIMER > 0u)
static void Appl_EcuShutdownTimer(void);
#endif

#if (APPL_MODE_STAY_TIME > 0u)
static void Appl_BootStayTimer(void);
#endif

static void Appl_InitNvmInfo(void);

static void Appl_GotoAppSW(uint32 address);

static void Appl_FlStartup(void);

static boolean Appl_GetExternalProgramRequested(void);

static boolean Appl_GetBootDefaultFromProgram(void);

static boolean Appl_GetApplicationUpdatedValid(void);

static void Appl_JumpApp(uint32 address);
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/** timer delay when ECU start up */
#if (APPL_MODE_STAY_TIME > 0u)
static uint32 ApplBootStayTimer;
#endif

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/
BL_AppFlagType* BL_AppFlag = (BL_AppFlagType*)BL_APP_FLAG_ADDRESS; /*PRQA S 0306*/

#if ((STD_ON == APPL_RESPONSE_1002_IN_BOOT_AFTER_RESET) && (BL_BUS_MODE == BL_BUS_MODE_ETH))
extern SEND_1002_FLAGType SEND_1002_FLAG;
#endif

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/******************************************************************************/
/**
 * @brief               <ECU initialize>
 *
 * <This routine shall be called by the boot code contained in the flash loader
 *  to initialize common hardware.> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Appl_EcuStartup(void)
{
    /*================Follow is ECU On-board drive init ======================*/
    /* ECU Dependency Driver Initialization */
    Appl_EcuDrvInit();
    /* ECU Network Protocol Initialization */
    Appl_EcuNetBusInit();
    /*==============Above is ECU On-board drive init =========================*/

    /* Diagnostic Protocol Stack Initialization */
    Dcm_Init();
    /* Flash Boot Loader Module Initialization */
    FL_Init();

#if (APPL_MODE_STAY_TIME > 0u)
    /* stay in boot time init */
    ApplBootStayTimer = (uint32)0u;
#endif
    /* Check if running object is set to reprogramming flag */
#ifndef PROJECT_APP
    /* nvmInfo Initialize */
    (void)\
    Appl_FlStartup();
#endif
}

/******************************************************************************/
/**
 * @brief               <check application software consistency>
 *
 * <This routine shall be called by the flashloader to check whether the
 *  individual parts (logical blocks) that make up the application software of
 *  an ECU are consistent with each other.> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <region>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_OK/FL_FAILED:The integrity check succeeded or failed.>
 */
/******************************************************************************/
FL_ResultType Appl_CheckConsistency(FL_Region_Type region)
{
    FL_ResultType retVal = (FL_ResultType)FL_OK;


    return retVal;
}
/******************************************************************************/
/**
 * @brief               <check application software Dependency and consistency>
 *
 * <This routine shall be called by the flashloader to check whether the
 *  individual parts (logical blocks) that make up the application software of
 *  an ECU are consistent with each other.> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <region>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_OK/FL_FAILED:The integrity check succeeded or failed.>
 */
/******************************************************************************/
FL_ResultType Appl_CheckDependencyConsistency(FL_Region_Type region)
{
	FL_ResultType retVal = (FL_ResultType)FL_OK;
	return retVal;
}

/******************************************************************************/
/**
 * @brief               <ECU reset>
 *
 * <This routine shall be called by the BOOTLOADER to reset the ECU upon
 *  request from the external programming device.>
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Appl_EcuReset(void) 
{
	/*Whether to download the flashdriver.*/
	if(FL_GetFLDownloaded() == TRUE)
	{
	    /* Clear flash driver in RAM */
	    DP_Memset((uint8*)FL_FLASH_DRIVER_BASE_ADDRESS, (uint8)0x00U, (uint32)FL_FLASH_DRIVER_SIZE); /*PRQA S 0306*/
	}

    /* perform Mcu Reset */
    Rte_Reset();
}

/******************************************************************************/
/**
 * @brief               <1ms task>
 *
 * <This routine shall be called by functions of the flash loader runtime
 *  environment and the security module at least every 500 milliseconds.> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Appl_UpdateTriggerCondition(void)
{

    /* 1ms task and watch dog trigger */
	if (TRUE == GptIf_GetFlag())
	{
	    Rte_Job_Mainfunction();

        Dcm_SecMSeedCount++;

#if (APPL_ENABLE_WATCHDOG_MONITORING_IN_BOOT == STD_ON)
        if((Dcm_SecMSeedCount%APPL_WATCHDOG_FEEDING_TIME) == 0x00u)
        {
        	Appl_wdTriggerFct();
        }
#endif
        PduR_MainFunction1ms();

        Dcm_MainFunction();

#if (APPL_SLEEP_TIMER > 0U)
        Appl_EcuShutdownTimer();
#endif
#if ((STD_ON == APPL_RESPONSE_1002_IN_BOOT_AFTER_RESET) && (BL_BUS_MODE == BL_BUS_MODE_ETH))
        /* Check if programming session flag is valid */
        if (FLAG_ROUTING_CONFIRM == SEND_1002_FLAG)
        {
            Dcm_Send_1002_Response();
        }
#endif

#if (APPL_MODE_STAY_TIME > 0U)
        Appl_BootStayTimer();
#endif
    }
	PduRIF_MainFunction();
    Rte_Job_FastMainfunction();
}

/******************************************************************************/
/**
 * @brief               <Appl Main Function>
 *
 * <Appl Main Function> .
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Appl_MainFunction(void) 
{
    Appl_UpdateTriggerCondition();
}

#if (STD_ON == FL_SPLIT_SECTORS_ERASE_ENABLED)
/******************************************************************************/
/**
 * @brief               <Net update Main Function>
 *
 * <Appl Main Function> .
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Appl_NetUpdateMainFunction(void)
{
	PduRTPIF_MainFunction();
}
#endif

/**********************************************************************************************/
/**
 * @brief               < Appl get xternal programming request positive response suppression >
 *                         < used to check if  the external program requested is valid >
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <TRUE/FALSE: External programming request yes or no.>
 */
/**********************************************************************************************/
boolean Appl_GetExternalProgramPositiveRequest(void)
{
    boolean retVal;

    retVal = DP_Memcompare(Appl_extprogpositiversprequestreceived,BL_AppFlag->FlBootMode2,APPL_EXT_PROG_POSITIVE_RSP_REQUEST_RECEIVED_LENGTH);

    return retVal;
}
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
/**********************************************************************************************/
/**
 * @brief               < Appl get external program requested >
 *                         < used to check if  the external program requested is valid >
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <TRUE/FALSE: External programming request yes or no.>
 */
/**********************************************************************************************/
static boolean Appl_GetExternalProgramRequested(void)
{
    boolean retVal;

    retVal = DP_Memcompare(Appl_extprogrequestreceived,BL_AppFlag->FlBootMode1,APPL_EXT_PROG_REQUEST_RECEIVED_LENGTH);

    return retVal;
}


/**********************************************************************************************/
/**
 * @brief               < Appl get boot default from program >
 *                         < used to check if  the default session requested is valid >
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <TRUE/FALSE: Programming session hop Default session yes or no.>
 */
/**********************************************************************************************/
static boolean Appl_GetBootDefaultFromProgram(void)
{
    boolean retVal;

    retVal = DP_Memcompare(Appl_bootdefaultfromprog,BL_AppFlag->FlBootDefaultFromProg,APPL_BOOT_DEFAULT_FROM_PROG_LENGTH);

    return retVal;
}

/**********************************************************************************************/
/**
 * @brief               < Appl get application updated valid status >
 *                         < used to check if  the Application updated is valid >
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <TRUE/FALSE: the Application updated yes or no.>
 */
/**********************************************************************************************/
static boolean Appl_GetApplicationUpdatedValid(void)
{
    boolean retVal = TRUE;

    /* callout shall be create here by user*/
    return retVal;
}

/******************************************************************************/
/**
 * @brief               <flashloader initialize>
 *
 * <This routine shall be called by the flash loader to initialize the software
 *  environment needed for ECU reprogramming (after the decision to switch to
 *  flash loader mode).> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
static void Appl_FlStartup(void)
{
    /* result of software consistency */
    FL_ResultType consist;
    FL_ResultType dependence;

    /* Copy data from non-volatile storage units to RAM */
    Rte_Appl_InitNvmInfo();

    /* check if BOOTLOADER program is requested in application,
     * if yes, then set ApplBootStayTimer */
    if ((boolean)TRUE == Rte_Appl_ReadProgrammingFlag())
    {
        /* Initialize the program of DCM, include start S3 timer .etc */
    }
    else    
#if (RTE_PARTITION_SWAP_ON == STD_ON)
    if (TRUE == Rte_ABSwap_ForceSwitch())
    {
        Dcm_StartResetTimer((uint16)APPL_MODE_STAY_TIME / GPT_PERIOD_TIME);
    }
    else
#endif
    {
        if ((boolean)TRUE == Appl_GetApplicationUpdatedValid()) /*PRQA S 2995,2991*/
        {
			Rte_Appl_CheckFactoryMode();
            /* check if application software is consistency */
            consist = Rte_Appl_CheckConsistency();

            dependence = Appl_CheckDependence();
            
#if (RTE_ALWAYSJUMP_APP_ON == STD_ON)
            consist = FL_OK;
            dependence = FL_OK;
#endif  
            /* check result */
            if (((FL_ResultType)FL_OK == consist) && ((FL_ResultType)FL_OK == dependence))
            {
#if (APPL_MODE_STAY_TIME > 0u)
                /* set boot stay timer */
                ApplBootStayTimer = (uint32)(APPL_MODE_STAY_TIME / GPT_PERIOD_TIME);
#else
                /* jump to application - no return */
                Appl_GotoAppSW((uint32)FL_APP_START_ADDR);
#endif
            }
        }
        else
        {
            /* empty */
        }
    }
}

/******************************************************************************/
/**
 * @brief               <get NVM information>
 *
 * <get information from flash about bootloader information(e.g.app valid info)> .
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
static void Appl_InitNvmInfo(void)
{

}

#if (APPL_SLEEP_TIMER > 0u)
/******************************************************************************/
/**
 * @brief               <time count for ECU shut down>
 *
 * <time count for ECU shut down> .
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
static void Appl_EcuShutdownTimer(void)
{

	if(Appl_EcuShutdownCondition() == TRUE)
	{
		Appl_EcuShutdown();
	}

}
#endif

#if (APPL_MODE_STAY_TIME > 0u)
/******************************************************************************/
/**
 * @brief               <time count for ECU stay in boot>
 * <time count for ECU stay in boot> .
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
static void Appl_BootStayTimer(void)
{
    /* current session mode */
    Dcm_SessionType currentSesMod;

    currentSesMod = Dcm_GetSessionMode();
    if (ApplBootStayTimer > 0U)
    {
        if (DCM_SESSION_DEFAULT == currentSesMod)
        {
            ApplBootStayTimer--;
            /* if boot stay time out, jump to Application */
            if (0U == ApplBootStayTimer)
            {
                Appl_GotoAppSW((uint32)FL_APP_START_ADDR);
            }
        }
        else
        {
            /* set boot stay timer;restart software timer for DiagnosticSessionControl window (20ms) */
            ApplBootStayTimer = (uint32)(APPL_MODE_STAY_TIME / GPT_PERIOD_TIME);
        }
    }
}
#endif

/******************************************************************************/
/**
 * @brief               <go to application software>
 *
 * <go to application software> .
 * @param[in]           address  - EnterPoint Address
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
static void Appl_GotoAppSW(uint32 address)
{
    /* should de-initialize hardware module first */
    /* if has interrupt, disable interrupt first
     * 1. Gpt-Deinit
     * 2. CAN-Deinit
     * 3. Prot-Deinit
     * 4. Wdg should not Deinit */
    Appl_EcuDrvDeinit();

    /* jump to APP
     * difference MCU,should case by case
     * if the MCU is S32k14x, should use value of the enter address + 4 as
     * the enterPointAddress. */
    Appl_JumpApp(address);
}

/******************************************************************************/
/**
 * @brief               <go to application software>
 *
 * <go to application software> .
 * @param[in]           address  - EnterPoint Address
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
static void Appl_JumpApp(uint32 address)
{                
    Appl_AdaptiveJumpApp(address);    
}
/*=======[E N D   O F   F I L E]==============================================*/
