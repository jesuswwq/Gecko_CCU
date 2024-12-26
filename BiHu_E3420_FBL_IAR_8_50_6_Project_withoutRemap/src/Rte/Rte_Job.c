/*============================================================================*/
/** Copyright (C) 2009-2022, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Rte_Job.c>
 *  @brief      <>
 *
 *  <Compiler: don't care     MCU: don't care >
 *  @brief      <Macro and function declarations for ${tmpl} Module>
 *
 *  @author     <Your Name>
 *  @date       <2024-04-03 14:44:50>
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
#define RTE_JOB_C
/*@}*/
/*=======[I N C L U D E S]====================================================*/
/*=======[Includes]===========================================================*/
/*@{*/
#include "Rte_Job.h"
#include "GptIf.h"
#include "CanIf.h"
#include "Appl_Callout.h"
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
/*@{*/
/*@}*/

void Rte_Job_FastMainfunction(void)
{
    GptIf_Random_Updata();
}

void Rte_Job_Mainfunction(void)
{
    static volatile uint16 i = 0;

    GptIf_Random_Updata();

    ++i;

#ifdef PROJECT_APP
    static uint16 _1024msFlag = 0;

    if ((++_1024msFlag & ((1 << 10) - 1)) == ((1 << 10) - 1))
    {
        CanIf_TestSend(0x677);
    }

#endif
#ifdef DEBUGTIMEOVER
    static uint32 tick = 0;
    static uint32 lasttick = 0;
    static uint32 timeOverI = 0;
    static uint32 timeOverCI = 0;
    static struct
    {
        uint32 state;
        uint32 index;
        uint32 cnt;
    } timeOverC[10];
    static uint32 timeOverB[100] = {0};
    tick = GptIf_GetTick();

    if ((tick - lasttick) > 1)
    {
        timeOverI++;
        timeOverB[timeOverI % 100] = (tick - lasttick);

        if (timeOverC[timeOverCI % 10].state == 0)
        {
            timeOverC[timeOverCI % 10].state = 1;
        }
    }
    else
    {
        if (timeOverC[timeOverCI % 10].state == 1)
        {
            timeOverC[timeOverCI % 10].state = 0;
            timeOverC[timeOverCI % 10].index = timeOverI;
            timeOverCI++;
        }

        timeOverC[timeOverCI % 10].cnt++;
    }

    lasttick = tick;
#endif
}

void Rte_Test(void)
{
#if 0
    boolean ret = FALSE;
    (void)ret;
    static uint16 _1024msFlag = 0;
    static uint16 _1024msFlagCouter = 0;
    uint8 rs = Rte_isWarmStart();
    CanIf_Init();
#ifndef DEBUGAPPFLAG
    NvMemTest();
#endif
#ifdef PROJECT_FLS_ENABLE
    Rte_FlsTest();
#endif

    for (;;)
    {
        Rte_Job_FastMainfunction();

        if (TRUE == GptIf_GetFlag())
        {
            Rte_Job_Mainfunction();

            CanIf_MainFunction();

            if ((++_1024msFlag & ((1 << 10) - 1)) == ((1 << 10) - 1))
            {
#ifdef DEBUGAPPFLAG
                static uint32 step = 0;
                static uint8 ProgSignature[RTE_CFG_PROGRAM_FLAG_LEN] = {RTE_CFG_PROG_REQUEST_RECEIVED};
                static uint8 ProgReqReadBuf[RTE_CFG_PROGRAM_FLAG_LEN] = {0};
                uint8 debugData[8] = {0xFFU, 0xFFU, 0xFFU, 0xFFU, rs, 0x6, 0x07U, 0x08};
                static uint8 ret;

                switch (step)
                {
                case 0:
                    CanIf_TestSendData(0x7a1, debugData, 8);
                    break;

                case 1:
                    if (rs != 0)
                    {
                        ret = Rte_Data_Read_PROGRAM_Flag(&ProgReqReadBuf[0]);
                        CanIf_TestSendData(0x7a2, (uint8 *)&ProgReqReadBuf, 4);
                        DP_Memset(ProgReqReadBuf, 0, RTE_CFG_PROGRAM_FLAG_LEN);
                    }
                    break;

                case 2:
                    ret = Rte_Data_Write_PROGRAM_Flag(&ProgSignature[0]);
                    CanIf_TestSendData(0x7a3, (uint8 *)&ProgReqReadBuf, 4);
                    break;

                case 3:
                    ret = Rte_Data_Read_PROGRAM_Flag(&ProgReqReadBuf[0]);
                    CanIf_TestSendData(0x7a4, (uint8 *)&ProgReqReadBuf, 4);
                    break;
                    break;

                case 4:
                    CanIf_TestSend(0x7a7);
                    break;

                default:

                    Rte_Reset();
                    break;
                }

                step++;
#endif
                _1024msFlagCouter++;

                if (_1024msFlagCouter % 10 == 9)
                {

                    for (int i = 0; i < 20; ++i)
                    {

                        if (i % 8 == 7)
                        {
                        }
                    }

    extern void CanIf_TestSend(uint32 id)  ;
                    CanIf_TestSend(0x777);
                }
            }
        }
    }
#endif
}
/*=======[E N D   O F   F I L E]==============================================*/
