/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2022)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : EcuM_Callout_Stubs.c                                        **
**                                                                            **
**  Created on  : 2023/12/18 16:48:59                                         **
**  Author      : qinchun.yang                                                **
**  Vendor      :                                                             **
**  DESCRIPTION :  Implementations for EcuM callouts                          **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19_11                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "EcuM_Internal.h"
#include "EcuM_Cbk.h"
#include "Port.h"
#include "Adc.h"
#include "Can.h"
#include "Lin.h"
#include "CanIf.h"
#include "LinIf.h"
#include "CanSM.h"
#include "LinSM.h"
#include "PduR.h"
#include "Com.h"
#include "ComM.h"
#include "ComM_Internal.h"
#include "ComM_BswM.h"
#include "Spi.h"
#include "I2c.h"
#include "Pwm.h"
#include "Xcp.h"
#include "XcpTest.h"
#include "IoExp_TCA6424A_Api.h"
#include "IoExp_TCA9539_Api.h"
#include "TLE75242_Api.h"
#include "TLE75004_Api.h"
#include "CanNm.h"
#include "Nm.h"
#include "Ea.h"
#include "NvM.h"
#include "CanTp.h"
#include "Eep_62.h"
#include "Dcm.h"
#include "Dem.h"

#include "Xtrg_Cfg.h"
#include "xtrg.h"
#include "PEPS_ABI.h"
#include "Icu.h"
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
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
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define ECUM_START_SEC_CALLOUT_CODE
#include "EcuM_MemMap.h"
#define buffersize 10
static Adc_ValueGroupType adc1_group0_tmpbuffer[buffersize] = {0};
/**
 * The ECU State Manager will call the error hook if the error codes
 * "ECUM_E_RAM_CHECK_FAILED" or "ECUM_E_CONFIGURATION_DATA_INCONSISTENT" occur.
 * In this situation it is not possible to continue processing and the ECU must
 * be stopped. The integrator may choose the modality how the ECU is stopped,
 * i.e. reset, halt, restart, safe state etc.
 * EcuM_ErrorHook is integration code and the integrator is free to define
 * additional individual error codes to be passed as the reason parameter.
 * Service ID[hex]: 0x30
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): reason, Reason for calling the error hook
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_ERRORHOOK_CODE)
EcuM_ErrorHook(
    uint16 reason)
{
    /*todo*/
    (void)reason;
}

#if (ECUM_SET_PROGRAMMABLE_INTERRUPTS == STD_ON)
/**
 * If the configuration parameter EcuMSetProgrammableInterrupts is set to true,
 * this callout EcuM_AL_SetProgrammableInterrupts is executed and shall set the
 * interrupts on ECUs with programmable interrupts.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_AL_SETPROGRAMMABLEINTERRUPTS_CODE)
EcuM_AL_SetProgrammableInterrupts(
    void)
{
    /*todo*/
}
#endif /*#if (ECUM_SET_PROGRAMMABLE_INTERRUPTS == STD_ON)*/

#if (ECUM_DRIVER_INIT_LIST_ZERO == STD_ON)
/**
 * This callout shall provide driver initialization and other hardware-related
 * startup activities for loading the post-build configuration data. Beware:
 * Here only pre-compile and link-time configurable modules may be used.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_AL_DRIVERINITZERO_CODE)
EcuM_AL_DriverInitZero(
    void)
{
    Dem_PreInit();
}
#endif /*#if (ECUM_DRIVER_INIT_LIST_ZERO == STD_ON)*/

/**
 * This callout should evaluate some condition, like port pin or NVRAM value,
 * to determine which post-build configuration shall be used in the remainder
 * of the startup process. It shall load this configuration data into a piece
 * of memory that is accessible by all BSW modules and shall return a pointer
 * to the EcuM post-build configuration as a base for all BSW module post-build
 * configurations.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: Pointer to the EcuM post-build configuration which contains
 *               pointers to all other BSW module post-build configurations.
 */
FUNC_P2CONST(EcuM_ConfigType, ECUM_CONFIG_DATA, ECUM_DETERMINEPBCONFIGURATION_CODE)
EcuM_DeterminePbConfiguration(
    void)
{
    extern CONST(EcuM_ConfigType, ECUM_VAR_NO_INIT) EcuM_Config;

    return (&EcuM_Config);
}

#if (ECUM_DRIVER_INIT_LIST_ONE == STD_ON)
/**
 * This callout shall provide driver initialization and other hardware-related
 * startup activities in case of a power on reset.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): ConfigPtr, pointer to the EcuM post-build configuration which
 *                             contains pointers to all other BSW module post-build
 *                             configurations.
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_AL_DRIVERINITONE_CODE)
EcuM_AL_DriverInitOne(
    void)
{
    uint8 portvalue = 0;
    P2CONST(EcuM_GenBSWPbCfgType, AUTOMATIC, CANIF_APPL_DATA)
    pbCfg = EcuM_ConfigPtr->modulePBCfg;
    Port_Init(&Port_Cfg);
    Adc_Init(&Adc_Config);
    Can_Init(pbCfg->canPbCfg);
    Lin_Init(pbCfg->linPbCfg);
    Icu_Init(&Icu_ConfigSet);
    Xtrg_SignalMutiplex(&Xtrg_DeviceCfg,&SmuxConfig_crashsig);
    Spi_Init(Spi_Config);
    I2c_Init();
    Pwm_Init(&Pwm_Config);

    TCA6424_Init();
    IoExp_TCA6424_SetAllPortHigh(TCA6424_CHIP_A);
    //IoExp_TCA6424_SetAllPortHigh(TCA6424_CHIP_B);
    // IoExp_TCA6424_SetAllPortHigh(TCA6424_CHIP_C);
    // IoExp_TCA6424_SetAllPortHigh(TCA6424_CHIP_D);
    // IoExp_TCA6424_SetAllPortHigh(TCA6424_CHIP_E);

    TCA9539_Init();
    // IoExp_TCA9539_SetAllPortHigh(TCA9539_CHIP_A);
    // IoExp_TCA9539_SetChannelOutLevel(TCA9539_CHIP_A,IOEXP_TCA9539_P06,STD_LOW);
    IoExp_TCA9539_GetPortInputValue(TCA9539_CHIP_B, TCA9539_PORTGROUP0, &portvalue);
    Gpio_TCA9539_ReadValue();

    TLE75004_Init();
    // TLE75004_Output(0X3);
    TLE75004_Ctrl_PortOut(TLE75004_LS_OUT0, TLE75004_CH_OFF);
    TLE75004_Ctrl_PortOut(TLE75004_LS_OUT1, TLE75004_CH_OFF);

    TLE75242_Init();
#if 0
    HS_Ctrl_75242_A_HS_OUT4_On();
	HS_Ctrl_75242_B_HS_OUT4_On();
	HS_Ctrl_75242_B_HS_OUT6_On();
        Pwm_DisableNotification(PWM_CONFIG_CHANNEL_PwmChannel_7E100B_IN0);
        Xtrg_SignalMutiplex(&Xtrg_DeviceCfg, &IOOutConfig_H5);
    TLE75242_MapPort_IN0Ctrl(TLE75242_CHIP_A,TLE75242_CH_OUT5);
    TLE75242_A_IN0Ctrl_PWMDutyPercent(30);        //30% pwm duty
#endif
#if 0
    /*Pwm output*/
    /*******Demo: set TLE75242_CHIP_B TLE75242_CH_OUT4 output pwm 100hz 50%duty *******/
    TLE75242_MapPWMToOutputChannel(TLE75242_CHIP_B,TLE75242_PWM_CH1,TLE75242_CH_OUT7);
    TLE75242_SetPWMChFrequency(TLE75242_CHIP_B,TLE75242_PWM_CH1,TLE75242_PWM_FREQ_200HZ);
    TLE75242_EnablePwmChOutput(TLE75242_CHIP_B,TLE75242_PWM_CH1);

    /*******Demo: adjust output pwm 70%duty *******/
    TLE75242_AdjustPWMChOutputDuty(TLE75242_CHIP_B,TLE75242_PWM_CH1,70);
#endif
    I2c_CanTcv_Ctr();
    // Can_Init(pbCfg->canPbCfg);
    // Lin_Init(pbCfg->linPbCfg);
    I2c_EepInit_Device();
    IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_B, IOEXP_TCA6424_P03, STD_LOW);
}
#endif /*#if (ECUM_DRIVER_INIT_LIST_ONE == STD_ON)*/
//uint8 rtb_CCaller_j1[12]={0};
FUNC(void, ECUM_AL_DRIVERINITBSWM_0_CODE)
EcuM_AL_DriverInitBswM(
    uint8 drvInitIdx)
{
    P2CONST(EcuM_GenBSWPbCfgType, AUTOMATIC, CANIF_APPL_DATA)
    pbCfg = EcuM_ConfigPtr->modulePBCfg;
    if (EcuMDriverInitListBswM == drvInitIdx)
    {
        CanIf_Init(pbCfg->canIfPbCfg);
        LinIf_Init(pbCfg->linIfPbCfg);
        CanSM_Init(pbCfg->canSmPbCfg);
        LinSM_Init(pbCfg->linSMPbCfg);
        PduR_Init(pbCfg->pduRPbCfg);
        Com_Init(pbCfg->comPbCfg);
        ComM_Init(pbCfg->comMPbCfg);
        Xcp_Init(pbCfg->xcpPbCfg);
        XcpTest_initialize();
        CanNm_Init(pbCfg->canNmPbCfg);
        Nm_Init(pbCfg->nmPbCfg);
        Eep_62_Init(Eep_62_ConfigSet);
        Ea_Init(NULL_PTR);
        NvM_Init(pbCfg->nvmPbCfg);
        CanTp_Init(pbCfg->canTpPbCfg);
        Dcm_Init(pbCfg->dcmPbCfg);
    }
    /********Initialize read important data*******/
    NvM_RequestResultType l_BlockStatus = NVM_REQ_PENDING;
    uint16 NvMCounter = 0xFFFF;
    NvM_ReadPRAMBlock(NvMBlock3_DID_F157);
    NvM_ReadPRAMBlock(NvMBlock_Swc_VCU_01_64);
    NvM_ReadPRAMBlock(NvMBlock_Swc_TMS);

    NvM_ReadPRAMBlock(NvMBlock_Swc_BCM_IMM_20);
    NvM_ReadPRAMBlock(NvMBlock_Swc_BCM_PD_10);
    NvM_ReadPRAMBlock(NvMBlock_Swc_BCM_PEPS_256);
    while ((NVM_REQ_PENDING == l_BlockStatus) && (NvMCounter > 0))
    {
        NvM_MainFunction();
        Ea_MainFunction();
        Eep_62_MainFunction();
        (void)NvM_GetErrorStatus(NvMBlock_Swc_BCM_PEPS_256, &l_BlockStatus);
        NvMCounter--;
    }
    /*Enter in RUN after initialized all BSW mode.*/

    //NvmTmsBlockReadData();
    PEPS_NVMRead();
    EcuMRunData.State = ECUM_STATE_RUN;
    BswM_EcuM_CurrentState(ECUM_STATE_RUN);
}

#if (ECUM_RESET_LOOP_DETECTION == STD_ON)
/**
 * If the configuration parameter EcuMResetLoopDetection is set to true,
 * this callout EcuM_LoopDetection is called on every startup.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: FALSE: no reset loop is detected
 *               TRUE: reset loop is detected
 */
FUNC(boolean, ECUM_LOOPDETECTION_CODE)
EcuM_LoopDetection(
    void)
{
    /*todo*/
    return FALSE;
}
#endif /*#if (ECUM_RESET_LOOP_DETECTION == STD_ON)*/

/**
 * This call allows the system designer to notify that the GO OFF I state is
 * about to be entered.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_ONGOOFFONE_CODE)
EcuM_OnGoOffOne(
    void)
{
    /*todo*/
}

/**
 * This call allows the system designer to notify that the GO OFF II state is
 * about to be entered.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_ONGOOFFTWO_CODE)
EcuM_OnGoOffTwo(
    void)
{
    /*todo*/
}

/**
 * This callout shall take the code for shutting off the power supply of the ECU.
 * If the ECU cannot unpower itself, a reset may be an adequate reaction.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_AL_SWITCHOFF_CODE)
EcuM_AL_SwitchOff(
    void)
{
    // NvM_RequestResultType l_BlockStatus = NVM_REQ_PENDING;
    uint16 DelayTemp1 = 0;
    uint16 DelayTemp2 = 0;
// uint16 NvMCounter = 0xFFFF;
// Dem_Shutdown();
#if WDG_FUNCTION_SWITCH
    WdgM_DeInit();
#endif
    // NvM_WriteAll();
    // while((NVM_REQ_PENDING == l_BlockStatus) && (NvMCounter > 0))
    // {
    //     NvM_MainFunction();
    //     Ea_MainFunction();
    //     Eep_62_MainFunction();
    //     (void)NvM_GetErrorStatus(0,&l_BlockStatus);
    //     NvMCounter--;
    // }
    Set_TCA1043_To_GoToSleep(TCA6424_CHIP_A);
    IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_A, IOEXP_TCA6424_P20, STD_LOW);
    HW_NM_Check_BeforeRTC();
    Mcu_SetMode(MCU_MODE_RTC);
    /***********************Delay power down in capacitance*******************************/
    for (DelayTemp1 = 600; DelayTemp1 > 0; DelayTemp1--)
    {
        for (DelayTemp2 = 100; DelayTemp2 > 0; DelayTemp2--)
        {
            asm("NOP");
        }
    }
    Mcu_PerformReset();
    /*todo*/
}

/**
 * This callout shall take the code for resetting the ECU.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): reset, type of reset to be performed.
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_AL_RESET_CODE)
EcuM_AL_Reset(
    EcuM_ResetType reset)
{
    Mcu_PerformReset();
}

/**
 * The ECU Manager Module calls EcuM_EnableWakeupSource to allow the system
 * designer to notify wakeup sources defined in the wakeupSource bitfield that
 * SLEEP will be entered and to adjust their source accordingly.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): wakeupSource
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_ENABLEWAKEUPSOURCES_CODE)
EcuM_EnableWakeupSources(
    EcuM_WakeupSourceType wakeupSource)
{
    switch (wakeupSource)
    {
    case EcuMWakeupSource_EPT:
        /*TODO*/
        break;
    case EcuMWakeupSource_CHA:
        break;
    case EcuMWakeupSource_BAC:
        break;
    case EcuMWakeupSource_BOD:
        break;
    case EcuMWakeupSource_LIN:
        /*TODO*/
        break;
    }
}

/**
 * Generate code for RAM integrity test.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_GENERATERAMHASH_CODE)
EcuM_GenerateRamHash(
    void)
{
    /*todo*/
}

/**
 * This callout is invoked periodically in all reduced clock sleep modes.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_SLEEPACTIVITY_CODE)
EcuM_SleepActivity(
    void)
{
    /*todo*/
}

/**
 * This API is called by the ECU Firmware to start the CheckWakeupTimer for the
 * corresponding WakeupSource. If EcuMCheckWakeupTimeout > 0 the CheckWakeupTimer
 * for the WakeupSource is started. If EcuMCheckWakeupTimeout ?? 0 the API call
 * is ignored by the EcuM.
 * Service ID[hex]: 0x28
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): wakeupSource, For this wakeup source the corresponding
 *                                CheckWakeupTimer shall be started.
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_STARTCHECKWAKEUP_CODE)
EcuM_StartCheckWakeup(
    EcuM_WakeupSourceType wakeupSource)
{
    (void)wakeupSource;
}

/**
 * This API is called by any SW Module whose wakeup source is checked
 * asynchronously (e.g. asynchronous Can Trcv Driver) and the Check of the Wakeup
 * returns a negative Result (no Wakeup by this Source). The API cancels the
 * CheckWakeupTimer for the WakeupSource. If the correponding CheckWakeupTimer is
 * canceled the check of this wakeup source is finished.
 * Service ID[hex]: 0x29
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): wakeupSource, For this wakeup source the corresponding
 *                                CheckWakeupTimer shall be canceled.
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_ENDCHECKWAKEUP_CODE)
EcuM_EndCheckWakeup(
    EcuM_WakeupSourceType WakeupSource)
{
    (void)WakeupSource;
}

/**
 * This callout is intended to provide a RAM integrity test. The goal of this
 * test is to ensure that after a long SLEEP duration, RAM contents is still
 * consistent. The check does not need to be exhaustive since this would consume
 * quite some processing time during wakeups. A well designed check will execute
 * quickly and detect RAM integrity defects with a sufficient probability.
 * The areas of RAM which will be checked have to be chosen carefully. It depends
 * on the check algorithm itself and the task structure. Stack contents of the
 * task executing the RAM check e.g. very likely cannot be checked. It is good
 * practice to have the hash generation and checking in the same task and that this
 * task is not preemptible and that there is only little activity between hash
 * generation and hash check. The RAM check itself is provided by the system
 * designer. In case of applied multi core and existence of Satellite-EcuM(s):
 * this API will be called by the Master-EcuM only.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: 0: RAM integrity test failed else: RAM integrity test passed
 */
FUNC(uint8, ECUM_CHECKRAMHASH_CODE)
EcuM_CheckRamHash(
    void)
{
    /*todo*/
    return 1;
}

/**
 * The ECU Manager Module calls EcuM_DisableWakeupSources to set the wakeup
 * source(s) defined in the wakeupSource bitfield so that they are not able to
 * wake the ECU up.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): wakeupSource
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_DISABLEWAKEUPSOURCES_CODE)
EcuM_DisableWakeupSources(
    EcuM_WakeupSourceType wakeupSource)
{
    if ((wakeupSource & EcuMWakeupSource_EPT) == EcuMWakeupSource_EPT)
    {
        /*TODO*/
    }
    else if ((wakeupSource & EcuMWakeupSource_CHA) == EcuMWakeupSource_CHA)
    {
        /*TODO*/
    }
    else if ((wakeupSource & EcuMWakeupSource_BAC) == EcuMWakeupSource_BAC)
    {
    }
    else if ((wakeupSource & EcuMWakeupSource_BOD) == EcuMWakeupSource_BOD)
    {
    }
    else if ((wakeupSource & EcuMWakeupSource_LIN) == EcuMWakeupSource_LIN)
    {
    }
}

#if (ECUM_DRIVER_RESTART_LIST == STD_ON)
/**
 * This callout shall provide driver initialization and other hardware-related
 * startup activities in the wakeup case.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): ConfigPtr, pointer to the EcuM post-build configuration which
 *                             contains pointers to all other BSW module post-build
 *                             configurations.
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_AL_DRIVERRESTART_CODE)
EcuM_AL_DriverRestart(
    void)
{
}
#endif /*#if (ECUM_DRIVER_RESTART_LIST == STD_ON)*/

/**
 * The callout shall start the given wakeup source(s) so that they are ready to
 * perform wakeup validation.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): wakeupSource
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_STARTWAKEUPSOURCES_CODE)
EcuM_StartWakeupSources(
    EcuM_WakeupSourceType wakeupSource)
{
    switch (wakeupSource)
    {
    case EcuMWakeupSource_CHA:
        CanSM_StartWakeupSource(Channel_CANFD3);
        break;

    case EcuMWakeupSource_EPT:
        CanSM_StartWakeupSource(Channel_CANFD6);
        break;

    case EcuMWakeupSource_BAC:
        CanSM_StartWakeupSource(Channel_CANFD8);
        break;

    case EcuMWakeupSource_BOD:
        CanSM_StartWakeupSource(Channel_CANFD5);
        break;
    }
}

/**
 * This callout is called by the EcuM to validate a wakeup source. If a valid
 * wakeup has been detected, it shall be reported to EcuM via EcuM_ValidateWakeupEvent().
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): wakeupSource
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_CHECKVALIDATION_CODE)
EcuM_CheckValidation(
    EcuM_WakeupSourceType wakeupSource)
{
    CanIf_CheckValidation(wakeupSource);
    // switch(wakeupSource)
    // {
    // case EcuMWakeupSource_EPT:
    //     CanIf_CheckValidation(wakeupSource);
    //     break;
    // case EcuMWakeupSource_CHA:
    //     CanIf_CheckValidation(wakeupSource);
    //     break;
    // }
}

/**
 * The callout shall stop the given wakeup source(s) after unsuccessful wakeup
 * validation.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): wakeupSource
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_STOPWAKEUPSOURCES_CODE)
EcuM_StopWakeupSources(
    EcuM_WakeupSourceType wakeupSource)
{
    (void)wakeupSource;
}
#define ECUM_STOP_SEC_CALLOUT_CODE
#include "EcuM_MemMap.h"

#define ECUM_START_SEC_CHECKWAKEUP_CALLBACK_CODE
#include "EcuM_MemMap.h"
/**
 * This callout is called by the EcuM to poll a wakeup source.
 * It shall also be called by the ISR of a wakeup source to set up the PLL and
 * check other wakeup sources that may be connected to the same interrupt.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): wakeupSource
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_CHECKWAKEUP_CODE)
EcuM_CheckWakeup(
    EcuM_WakeupSourceType wakeupSource)
{
    EcuM_StartCheckWakeup(wakeupSource);
    // switch(wakeupSource)
    // {
    // case EcuMWakeupSource_EPT:
    //     EcuM_StartCheckWakeup(EcuMWakeupSource_EPT);
    //     break;
    // case EcuMWakeupSource_CHA:
    //     EcuM_StartCheckWakeup(EcuMWakeupSource_CHA);
    //     break;
    // }
}
#define ECUM_STOP_SEC_CHECKWAKEUP_CALLBACK_CODE
#include "EcuM_MemMap.h"
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                            General Notes                                   **
*******************************************************************************/
