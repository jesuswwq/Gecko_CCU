/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Os_UserInf.c>
 *  @brief      <>
 *  
 *  <MCU:E3420>
 *  
 *  @author     <>
 *  @date       <2023-09-15 14:10:12>
 */
/*============================================================================*/

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>      <DATE>     <AUTHOR>      <REVISION LOG>
 *   V1.0.0       20141111     bo.zeng      Initial version
 *   V2.0.0       20170615     shi.shu      Multicore
 *   V3.0.0       20191121     shun.li      Functional safety version
 *   V3.1.0       20200421     shun.li      Add IOC function
 */
/*============================================================================*/

/*=======[I N C L U D E S]====================================================*/
#include "Os.h"
#include "Os_Extend.h"
#include "PduR.h"
#include "Com.h"
#include "ComM.h"
#include "ComM_Internal.h"
#include "ComM_BswM.h"
#include "LinIf.h"
#include "LinSM.h"
#include "CanIf.h"
#include "CanSM.h"
#include "Can.h"
#include "Adc.h"
#include "Spi.h"
#include "Dio.h"
#include "SchM_ComM.h"
#include "SchM_LinSM.h"
#include "SchM_LinIf.h"
#include "Xcp.h"
#include "SchM_Xcp.h"
#include "XcpTest.h"
#include "CanNm.h"
#include "DR702.h"
#include "Eep_62.h"
#include "Ea.h"
#include "NvM.h"
#include "Dcm.h"
#include "Dem.h"
#include "BswM_Check_Action.h"
#include "Wdg.h"
#include "WdgM.h"
#include "WdgIf.h"
#include "ME11_ABI.h"
#include "Gpio_rte.h"
#include "Adc_rte.h"
#include "HBridge_rte.h"
#include "Pwm_rte.h"
Com_IpduGroupVector g_ComIpduGroupVector;
/*lin*/
ComM_ModeType old_LinSM0_State = COMM_NO_COMMUNICATION;
ComM_ModeType new_LinSM0_State = COMM_NO_COMMUNICATION;

Dio_LevelType iolevel = STD_LOW;
static uint8 wdg_passcnt = 0;
uint8 NvM_InitReadAll_Flag ;
//extern uint8 Counter1ms;
Mcu_ResetType resetreason;
/*=======[V E R S I O N   I N F O R M A T I O N]===============================*/
#define OS_USERAPP_C_AR_MAJOR_VERSION     4U
#define OS_USERAPP_C_AR_MINOR_VERSION     2U
#define OS_USERAPP_C_AR_PATCH_VERSION     2U
#define OS_USERAPP_C_SW_MAJOR_VERSION     1U
#define OS_USERAPP_C_SW_MINOR_VERSION     0U
#define OS_USERAPP_C_SW_PATCH_VERSION     0U

/*=======[V E R S I O N  C H E C K]===========================================*/
#if (OS_USERAPP_C_AR_MAJOR_VERSION != OS_CFG_H_AR_MAJOR_VERSION)
    #error "Os_Userapp.c:Mismatch in Specification Major Version"
#endif
#if (OS_USERAPP_C_AR_MINOR_VERSION != OS_CFG_H_AR_MINOR_VERSION)
    #error "Os_Userapp.c:Mismatch in Specification Minor Version"
#endif
#if (OS_USERAPP_C_AR_PATCH_VERSION != OS_CFG_H_AR_PATCH_VERSION)
    #error "Os_Userapp.c:Mismatch in Specification Patch Version"
#endif
#if (OS_USERAPP_C_SW_MAJOR_VERSION != OS_CFG_H_SW_MAJOR_VERSION)
    #error "Os_Userapp.c:Mismatch in Specification Major Version"
#endif
#if (OS_USERAPP_C_SW_MINOR_VERSION != OS_CFG_H_SW_MINOR_VERSION)
    #error "Os_Userapp.c:Mismatch in Specification Minor Version"
#endif

/*=======[T A S K S]==========================================*/
TASK(OsTask__Core0_100ms)
{
    /* please insert your code here ... */    

    Xcp_EventIndication(3);
    //Test_DV_Code();
    //VcuDVTest_step();
    Os_TaskEntry_Rte_OsTask__Core0_100ms();
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}
TASK(OsTask__Core0_10ms)
{
    if(60 >NM_Sleep_Counter)
    {
            NM_Sleep_Counter++; 
            if(60 == NM_Sleep_Counter)
            {
                    ComM_Req_NO_ComM = TRUE;
            }
    }
    /* please insert your code here ... */
    
    Cycle_HW_NM_Check();
    Cycle_ComM_Manage();
    ComM_MainFunction_Channel_CANFD3();
    ComM_MainFunction_Channel_CANFD4();
    ComM_MainFunction_Channel_CANFD5();
    ComM_MainFunction_Channel_CANFD6();
    ComM_MainFunction_Channel_CANFD7();
    ComM_MainFunction_Channel_CANFD8();
    ComM_MainFunction_ComMChannel_CCU_LIN1();
    ComM_MainFunction_ComMChannel_CCU_LIN2();
    ComM_MainFunction_ComMChannel_CCU_LIN3();

    Xcp_EventIndication(0);
//    XcpTest_step();

    Dcm_MainFunction();
    Dem_MainFunction();

    if(1 == NvM_InitReadAll_Flag)
    {
        NvM_MainFunction();
        Ea_MainFunction();
        Eep_62_MainFunction();
    }
  

#if WDG_FUNCTION_SWITCH
    if(wdg_passcnt < 2)
    {
      //WdgM_CheckpointReached(1, 0);
      WdgM_CheckpointReached(1, 0);
      wdg_passcnt++;
    }
    else
    {
      wdg_passcnt = 0;
      WdgM_MainFunction();
    }

#endif
    Nck2910_Task();
    // NJJ29C0_Task();
    Os_TaskEntry_Rte_OsTask__Core0_10ms();
    PEPS_Interface2CAN();
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}

TASK(OsTask__Core0_1ms)
{
    //Counter1ms++;
    CanSM_MainFunction();
    if(0 == NvM_InitReadAll_Flag)
    {
        NvM_MainFunction();
        Ea_MainFunction();
        Eep_62_MainFunction();
    }

    /* please insert your code here ... */
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}

TASK(OsTask__Core0_1s)
{
    // #if BSWM_TEST
    // uint8 tempArry[5] = {0};

    // // tempArry[1] = (uint8)(TCA9539SumTriger.ReadResult>>24);
    // // tempArry[2] = (uint8)((TCA9539SumTriger.ReadResult & 0xFF0000)>>16);
    // // tempArry[3] = (uint8)((TCA9539SumTriger.ReadResult & 0xFF00)>>8);
    // // tempArry[4] = (uint8)(TCA9539SumTriger.ReadResult & 0xFF);
    // // Com_SendSignal(AC_3_State_CHA_IPDU_COM_AC_3_State_CHA_AC_IndoorTemp_IPDU_COM_AC_3_State_CHA,&tempArry[0]);
    // // Com_SendSignal(AC_3_State_CHA_IPDU_COM_AC_3_State_CHA_AC_EnvirTemp_IPDU_COM_AC_3_State_CHA,&tempArry[1]);
    // // Com_SendSignal(AC_3_State_CHA_IPDU_COM_AC_3_State_CHA_TMS_OHXOutTmp_IPDU_COM_AC_3_State_CHA,&tempArry[2]);
    // // Com_SendSignal(AC_3_State_CHA_IPDU_COM_AC_3_State_CHA_TMS_EvapTmp_IPDU_COM_AC_3_State_CHA,&tempArry[3]);
    // // Com_SendSignal(AC_3_State_CHA_IPDU_COM_AC_3_State_CHA_TMS_EvapOutTmp_IPDU_COM_AC_3_State_CHA,&tempArry[4]);

    // // Com_SendSignal(AC_3_State_CHA_IPDU_COM_AC_3_State_CHA_TMS_ChillerOutTmp_IPDU_COM_AC_3_State_CHA,&CCUWakeupReturnValue);
    // // Com_SendSignalGroup(AC_3_State_CHA_IPDU_COM_AC_3_State_CHA);
	// #endif

    /* please insert your code here ... */
 
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }


}

TASK(OsTask__Core0_20ms)
{
    /* please insert your code here ... */

    ADC2_ReadGroup0();
    ADC2_ReadGroup1();
    Gpio_TCA9539_ReadValue();
    Gpio_Run();

  

    EcuM_MainFunction();
    BswM_MainFunction();
   // iolevel = IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B,tmpchannel);
    Xcp_EventIndication(1);
    NM_UserDataPackup();
    
    Os_TaskEntry_Rte_OsTask__Core0_20ms();
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}

TASK(OsTask__Core0_2ms)
{
    /* please insert your code here ... */
    // Nck2910_Task();
    NJJ29C0_Task();
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}
TASK(OsTask__Core0_50ms)
{
    /* please insert your code here ... */
	Xcp_EventIndication(2);
	Os_TaskEntry_Rte_OsTask__Core0_50ms();
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}
TASK(OsTask__Core0_5ms)
{  
  if(100 >= FirstWakeUpSource500ms)
  {
     FirstWakeUpSource500ms++;
  }
    /* please insert your code here ... */
    CanTp_MainFunction();
    CanNm_MainFunction();
    ADC2_ReadGroup2_4067();
    LinSM_MainFunction();
    LinIf_MainFunction();
    Com_MainFunctionTx();
    Com_MainFunctionRx();
    Xcp_MainFunction(); 

    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}
TASK(OsTask_Core0_Init)
{
    /* please insert your code here ... */
    EcuM_StartupTwo();
    
    NvM_InitReadAll_Flag = 0;

    resetreason = Mcu_GetResetReason();
    if(resetreason == MCU_WATCHDOG_RESET)
    {
       Dio_WriteChannel(DioConf_DioChannel_DioChannel_GPIO_E17, 1);
       Dio_WriteChannel(DioConf_DioChannel_DioChannel_GPIO_E17, 0);
       
    }
/*CDD initial start*/
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_GPIO_D3_SYSERR_EN,1);//add system_err_EN
    BTS7020_Init();
    BTS7120_Init();
    TCA6408_Init();
    TLE8108EM_Init();
    // TLE94103_Init();
    DR702_Init();
    MPQ6612A_Init();
    VNH5200_Init();
    // ADAU1462_Init();    
    BTS7012_Init();
    IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_A, IOEXP_TCA6424_P00, STD_LOW);
    IoExp_TCA6424_SetAllPortHigh(TCA6424_CHIP_C);
    Adc_rte_init();
    VNQ7E100_Init();
    Wdg_140_Instance1_Wdt_Init(&Wdg_Config1);
#if WDG_FUNCTION_SWITCH
    
    WdgM_Init(&WdgMConfigRoot[0]);
#endif
    
/*CDD initial end**/

    Rte_Start();
    Os_TaskEntry_Rte_OsTask_Core0_Init();

    SetRelAlarm(OsAlarm_Core0_1ms, 1, 1);
    SetRelAlarm(OsAlarm_Core0_2ms, 3, 2);
    SetRelAlarm(OsAlarm_Core0_5ms, 5, 5);
    SetRelAlarm(OsAlarm_Core0_10ms, 7, 10);
    SetRelAlarm(OsAlarm_Core0_20ms, 9, 20);
    SetRelAlarm(OsAlarm_Core0_50ms, 11, 50);
    SetRelAlarm(OsAlarm_Core0_100ms, 17, 100);
    SetRelAlarm(OsAlarm_Core0_1s, 19, 1000);
    EnableAllInterrupts();
    PEPS_KL30_RessetMonit();
    NCK2910_Init();
    PEPS_Module_Init();
    PEPS_KL30Resset_ParamWrt();
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}

TASK(OsTask__Core1_100ms)
{
    /* please insert your code here ... */
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}
TASK(OsTask__Core1_10ms)
{
    /* please insert your code here ... */
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}
TASK(OsTask__Core1_1ms)
{
    /* please insert your code here ... */
  
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}
TASK(OsTask__Core1_1s)
{
    /* please insert your code here ... */
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}
TASK(OsTask__Core1_20ms)
{
    /* please insert your code here ... */
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}
TASK(OsTask__Core1_2ms)
{
    /* please insert your code here ... */
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}
TASK(OsTask__Core1_50ms)
{
    /* please insert your code here ... */
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}
TASK(OsTask__Core1_5ms)
{
    /* please insert your code here ... */
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}
TASK(OsTask_Core1_Init)
{
    /* please insert your code here ... */
    SetRelAlarm(OsAlarm_Core1_1ms, 1, 1);
    SetRelAlarm(OsAlarm_Core1_2ms, 3, 2);
    SetRelAlarm(OsAlarm_Core1_5ms, 5, 5);
    SetRelAlarm(OsAlarm_Core1_10ms, 7, 10);
    SetRelAlarm(OsAlarm_Core1_20ms, 9, 20);
    SetRelAlarm(OsAlarm_Core1_50ms, 11, 50);
    SetRelAlarm(OsAlarm_Core1_100ms, 17, 100);
    SetRelAlarm(OsAlarm_Core1_1s, 19, 1000);
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}

TASK(OsTask__Core2_100ms)
{
    /* please insert your code here ... */
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}
TASK(OsTask__Core2_10ms)
{
    /* please insert your code here ... */
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}
TASK(OsTask__Core2_1ms)
{
    /* please insert your code here ... */
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}
TASK(OsTask__Core2_1s)
{
    /* please insert your code here ... */
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}
TASK(OsTask__Core2_20ms)
{
    /* please insert your code here ... */
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}
TASK(OsTask__Core2_2ms)
{
    /* please insert your code here ... */
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}
TASK(OsTask__Core2_50ms)
{
    /* please insert your code here ... */
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}
TASK(OsTask__Core2_5ms)
{
    /* please insert your code here ... */
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}
TASK(OsTask_Core2_Init)
{
    /* please insert your code here ... */
    SetRelAlarm(OsAlarm_Core2_1ms, 1, 1);
    SetRelAlarm(OsAlarm_Core2_2ms, 3, 2);
    SetRelAlarm(OsAlarm_Core2_5ms, 5, 5);
    SetRelAlarm(OsAlarm_Core2_10ms, 7, 10);
    SetRelAlarm(OsAlarm_Core2_20ms, 9, 20);
    SetRelAlarm(OsAlarm_Core2_50ms, 11, 50);
    SetRelAlarm(OsAlarm_Core2_100ms, 17, 100);
    SetRelAlarm(OsAlarm_Core2_1s, 19, 1000);
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}

/*=======[ALARM CALL BACK]==========================================*/

/*=======[H O O K S]================================================*/
FUNC(void, OS_APPL_CODE) IdleHook_Core0(void)
{
    /* please insert your code here ... */
}
FUNC(void, OS_APPL_CODE) IdleHook_Core1(void)
{
    /* please insert your code here ... */
}
FUNC(void, OS_APPL_CODE) IdleHook_Core2(void)
{
    /* please insert your code here ... */
}
void ErrorHook(StatusType Error)
{
    /***The code below is just for deleting the complier warning.***
    ***Please remove it and use your own code****/
    (void)Error;
    /***The code above is just for deleting the complier warning*/
    /* please insert your code here ... */
}

void StartupHook(void)
{
    /* please insert your code here ... */
}

void ShutdownHook(StatusType Error)
{
    /***The code below is just for deleting the complier warning.***
    ***Please remove it and use your own code****/
    EcuM_Shutdown();
    /***The code above is just for deleting the complier warning*/
    /* please insert your code here ... */
}

/*=======[I S R S]================================================*/
/* ISR_CANFD3_CANFD: Core0(CPU0) */
ISR(ISR_CANFD3_CANFD)
{
    Can_IP_IrqHandler(0);
    /* please insert your code here ... */
}
/* ISR_CANFD4_CANFD: Core0(CPU0) */
ISR(ISR_CANFD4_CANFD)
{
    Can_IP_IrqHandler(1);
    /* please insert your code here ... */
}
/* ISR_CANFD5_CANFD: Core0(CPU0) */
ISR(ISR_CANFD5_CANFD)
{
    Can_IP_IrqHandler(2);
    /* please insert your code here ... */
}
/* ISR_CANFD6_CANFD: Core0(CPU0) */
ISR(ISR_CANFD6_CANFD)
{
    Can_IP_IrqHandler(3);
    /* please insert your code here ... */
}
/* ISR_CANFD7_CANFD: Core0(CPU0) */
ISR(ISR_CANFD7_CANFD)
{
    Can_IP_IrqHandler(4);
    /* please insert your code here ... */
}
/* ISR_CANFD8_CANFD: Core0(CPU0) */
ISR(ISR_CANFD8_CANFD)
{
    Can_IP_IrqHandler(5);
    /* please insert your code here ... */
}
/* ISR_UART6: Core0(CPU0) */
ISR(ISR_UART3)
{
    /* please insert your code here ... */
    Lin_Irq3_Handle();
}
/* ISR_UART11: Core0(CPU0) */
ISR(ISR_UART11)
{
    /* please insert your code here ... */
    Lin_Irq11_Handle();
}
/* ISR_UART14: Core0(CPU0) */
ISR(ISR_UART14)
{
    /* please insert your code here ... */
    Lin_Irq14_Handle();
}
ISR(ISR_SPI7_SPI)
{
    /* please insert your code here ... */
  Spi7_IrqHandler();
    
}
ISR(ISR_SADC1_O_SADC)
{
  Adc_EndGroupConversion(0);
}
ISR(ISR_SADC2_O_SADC)
{
  Adc_EndGroupConversion(1);
}
/*
ISR(ISR_GPIO_AP_SYNC_DGPIO)
{
  Dio_Ip_IrqHandler(6);
}
*/

/* ISR_WDT1_WDT: Core0(CPU0) */
ISR(ISR_WDT1_WDT)
{
    /* please insert your code here ... */
}
/*=======[E N D   O F   F I L E]==============================================*/

