#include "BswM_Cfg.h"
#include "BswM.h"
#include "BswM_EcuM.h"
#include "ComM.h"
#include "IoExp_TCA9539_Api.h"
#include "BswM_Check_Action.h"
#include "Com.h"
#include "CanNm.h"
#include "CanNm_Internal.h"
#include "sdrv_btm_hw.h"
#include "Lin_Hw.h"
#include "CanIf_DiagRoute.h"
#include "IoExp_TCA6424A_Api.h"
#include "EcuM_Cbk.h"
#include "Mcu.h"
#include "PEPS_ABI.h"

#define WAKEUP_CHECK_SWTICH 1
#define TRIGGER_SET_BIT(bitindex, Value) Value = (Value | (0x00000001 < bitindex))

static Std_ReturnType Compare_9539_All(TCA9539SumTrigerType *TCA9539SumTrigerInfo, uint32 *TrigerValueInfo, uint8 RTCRam_Save);
uint8 NM_Sleep_Counter = 0;
NetworkHandleType Nm_Rx_NetWorkID = 0;
uint8 ComM_Req_NO_ComM = FALSE;
uint8 ComM_Request_Flag = 0;
uint8 CCUWakeupReturnValue = 0x00;
uint8 App_ComMReqFlag = 0xAA;
uint8 App_SleepReqFlag = 0xAA;
uint8 HW_Active_ComReq = 0;
uint16 HW_Trigger_Timer = 0;
uint16 RTC_Timer = 20;
uint8 FirstWakeUpSource500ms = 0;
static uint8 NMUserDataWakeupReas_Other = 0;
uint8 FirstNMFlag = 0;
uint8 ActiveNMReqFlag = 0;
bool NvM_WriteAllFlag = FALSE;

extern uint8 NvM_InitReadAll_Flag;

#define APP_COMM_SWITCH 10u
#define APP_SLEEP_SWITCH 20u
#define APP_NOREQ_COMM 0xAA
#define APP_REQ_COMM 0x55
#define APP_NOREQ_SLEEP 0xAA
#define APP_REQ_SLEEP 0x55
#define HW_REQ_SWITCH 15u
#define NM_SLEEP_SWITCH 30u
#define NVM_TIMER_START 40u

TCA9539SumTrigerType TCA9539SumSingleTriger = {{{FALSE, 0}, {FALSE, 0}}, 0};
uint32 TCA9539SumTrigerReadResult = 0;
static Std_ReturnType Read_9539_All(TCA9539SumTrigerType *TCA9539SumTrigerInfo);
static void Delay1ms(void);

void BswM_PowerON_KL15_Check_Callout(void)
{
        Std_ReturnType Ret = E_NOT_OK;
        uint32 TrigerValue = 0;
        uint32 RTC_MemoryFlag = sdrv_btm_hw_readl(0xF0010000, 0x48);
        CCUWakeupReturnValue = 0xFF;
        sdrv_btm_hw_writel(0xF0010000, 0x48, 0xAA); /**Flag for Power on which is no data in RTC ram**/
        do
        {
           while(E_NOT_OK == Read_9539_All(&TCA9539SumSingleTriger));  
           Delay1ms();
           (void)Read_9539_All(&TCA9539SumSingleTriger);         
        } while ((FALSE == TCA9539SumSingleTriger.TCA9539Triger[0].used)||(FALSE == TCA9539SumSingleTriger.TCA9539Triger[1].used)); 
        Ret = Compare_9539_All(&TCA9539SumSingleTriger,&TrigerValue,1);
        if(0x02 & Mcu_Ip_PmuGetWakeupSource()) /****wakeup by RealTimeCounter periodic interrupt****/
        {
                CCUWakeupReturnValue = 0x22;
                TRIGGER_SET_BIT(18, TCA9539SumTrigerReadResult);
        }
        if (0 == Dio_ReadChannel(DioConf_DioChannel_RKE_INT_GPIO_D37)) /****wakeup by RF****/
        {
                CCUWakeupReturnValue = 0x31;
                TRIGGER_SET_BIT(17, TCA9539SumTrigerReadResult);
        }
        if (E_OK == Ret)
        {
                /*High priority*/
                if (0x1B000000 & TrigerValue) /****IG1,IG2,OBC,BMS source for keeping COM Request*****/
                {
                        for (uint8 index = 0; index < 4; index++)
                        {
                                if ((0x1 << WakeUpSource[index].BitIndex) & TrigerValue)
                                {
                                        CCUWakeupReturnValue = WakeUpSource[index].WakeupReturnValue;
                                        break;
                                }
                        }
                        ComM_RequestComMode(ComMUser_CANFD3, COMM_FULL_COMMUNICATION);
                        ComM_RequestComMode(ComMUser_CANFD4, COMM_FULL_COMMUNICATION);
                        ComM_RequestComMode(ComMUser_CANFD5, COMM_FULL_COMMUNICATION);
                        ComM_RequestComMode(ComMUser_CANFD6, COMM_FULL_COMMUNICATION);
                        ComM_RequestComMode(ComMUser_CANFD7, COMM_FULL_COMMUNICATION);
                        ComM_RequestComMode(ComMUser_CANFD8, COMM_FULL_COMMUNICATION);
                        ComM_RequestComMode(ComMUser_CCU_LIN1, COMM_FULL_COMMUNICATION);
                        ComM_RequestComMode(ComMUser_CCU_LIN2, COMM_FULL_COMMUNICATION);
                        ComM_RequestComMode(ComMUser_CCU_LIN3, COMM_FULL_COMMUNICATION);
                }
                else if ((0x04F0F9C4 & TrigerValue) && (0xAA == RTC_MemoryFlag)) /****Source for Trigger COM Request except for KL30 Power on*****/
                {
                        for (uint8 index = 4; index < 18; index++)
                        {
                                if ((0x1 << WakeUpSource[index].BitIndex) & TrigerValue)
                                {
                                        CCUWakeupReturnValue = WakeUpSource[index].WakeupReturnValue;
                                        NMUserDataWakeupReas_Other = WakeUpSource[index].NMUserDataWakeupReas;
                                        break;
                                }
                        }
                        HW_Trigger_Timer = (2000 / 10);
                        ComM_RequestComMode(ComMUser_CANFD3, COMM_FULL_COMMUNICATION);
                        ComM_RequestComMode(ComMUser_CANFD4, COMM_FULL_COMMUNICATION);
                        ComM_RequestComMode(ComMUser_CANFD5, COMM_FULL_COMMUNICATION);
                        ComM_RequestComMode(ComMUser_CANFD6, COMM_FULL_COMMUNICATION);
                        ComM_RequestComMode(ComMUser_CANFD7, COMM_FULL_COMMUNICATION);
                        ComM_RequestComMode(ComMUser_CANFD8, COMM_FULL_COMMUNICATION);
                        ComM_RequestComMode(ComMUser_CCU_LIN1, COMM_FULL_COMMUNICATION);
                        ComM_RequestComMode(ComMUser_CCU_LIN2, COMM_FULL_COMMUNICATION);
                        ComM_RequestComMode(ComMUser_CCU_LIN3, COMM_FULL_COMMUNICATION);
                }
                else
                {
                        EcuM_SetWakeupEvent(EcuMWakeupSource_EPT);
                        EcuM_SetWakeupEvent(EcuMWakeupSource_CHA);
                        EcuM_SetWakeupEvent(EcuMWakeupSource_BAC);
                        EcuM_SetWakeupEvent(EcuMWakeupSource_BOD);
                        EcuM_SetWakeupEvent(EcuMWakeupSource_LIN);
                }
        }
        else /****source for MCU Wakeup Request except receiving PDU*****/
        {
                EcuM_SetWakeupEvent(EcuMWakeupSource_EPT);
                EcuM_SetWakeupEvent(EcuMWakeupSource_CHA);
                EcuM_SetWakeupEvent(EcuMWakeupSource_BAC);
                EcuM_SetWakeupEvent(EcuMWakeupSource_BOD);
                EcuM_SetWakeupEvent(EcuMWakeupSource_LIN);
        }
}

Std_ReturnType Read_9539_All(TCA9539SumTrigerType *TCA9539SumTrigerInfo)
{
        Std_ReturnType Read_State = E_NOT_OK;
        uint32 TCA9539PortGroup[4] = {0};
        Std_ReturnType Ret = E_NOT_OK;
#if BSWM_TEST
        if (0 == Dio_ReadChannel(DioConf_DioChannel_DioChannel_UART7_TX_GPIO_B2)) /***UT7TX****/
        {
                App_ComMReqFlag = 0x55;
                BswM_RequestMode(APP_COMM_SWITCH, APP_REQ_COMM);
        }
        else
        {
                App_ComMReqFlag = 0xAA;
                BswM_RequestMode(APP_COMM_SWITCH, APP_NOREQ_COMM);
        }

        if (0 == Dio_ReadChannel(DioConf_DioChannel_DioChannel_UART7_RX_GPIO_B3)) /***UT7RX****/
        {
                App_SleepReqFlag = 0x55;
                BswM_RequestMode(APP_SLEEP_SWITCH, APP_REQ_SLEEP);
        }
        else
        {
                App_SleepReqFlag = 0xAA;
                BswM_RequestMode(APP_SLEEP_SWITCH, APP_NOREQ_SLEEP);
        }
#endif
        for (uint8 index = 0; index < 1; index++)
        {
                Read_State = IoExp_TCA9539_GetPortInputValue(TCA9539_CHIP_A, TCA9539_PORTGROUP0, (uint8 *)&TCA9539PortGroup[0]);
                if (E_NOT_OK == Read_State)
                {
                        Ret = E_NOT_OK;
                        break;
                }
                Read_State = IoExp_TCA9539_GetPortInputValue(TCA9539_CHIP_A, TCA9539_PORTGROUP1, (uint8 *)&TCA9539PortGroup[1]);
                if (E_NOT_OK == Read_State)
                {
                        Ret = E_NOT_OK;
                        break;
                }
                Read_State = IoExp_TCA9539_GetPortInputValue(TCA9539_CHIP_B, TCA9539_PORTGROUP0, (uint8 *)&TCA9539PortGroup[2]);
                if (E_NOT_OK == Read_State)
                {
                        Ret = E_NOT_OK;
                        break;
                }
                Read_State = IoExp_TCA9539_GetPortInputValue(TCA9539_CHIP_B, TCA9539_PORTGROUP1, (uint8 *)&TCA9539PortGroup[3]);
                if (E_NOT_OK == Read_State)
                {
                        Ret = E_NOT_OK;
                        break;
                }
                Ret = E_OK;
        }

        if (E_OK == Ret)
        {
                if ((TRUE == TCA9539SumTrigerInfo->TCA9539Triger[0].used) && (FALSE == TCA9539SumTrigerInfo->TCA9539Triger[1].used))
                {
                        TCA9539SumTrigerInfo->TCA9539Triger[1].ReadResult = ((TCA9539PortGroup[3] << 24u) | (TCA9539PortGroup[2] << 16u) | (TCA9539PortGroup[1] << 8u) | TCA9539PortGroup[0]);
                        TCA9539SumTrigerInfo->TCA9539Triger[1].used = TRUE;
                        TCA9539SumTrigerInfo->new = 2;
                }
                else if ((TRUE == TCA9539SumTrigerInfo->TCA9539Triger[0].used) && (TRUE == TCA9539SumTrigerInfo->TCA9539Triger[1].used))
                {
                        if (1 == TCA9539SumTrigerInfo->new)
                        {
                                TCA9539SumTrigerInfo->TCA9539Triger[1].ReadResult = ((TCA9539PortGroup[3] << 24u) | (TCA9539PortGroup[2] << 16u) | (TCA9539PortGroup[1] << 8u) | TCA9539PortGroup[0]);
                                TCA9539SumTrigerInfo->TCA9539Triger[1].used = TRUE;
                                TCA9539SumTrigerInfo->new = 2;
                        }
                        else
                        {
                                TCA9539SumTrigerInfo->TCA9539Triger[0].ReadResult = ((TCA9539PortGroup[3] << 24u) | (TCA9539PortGroup[2] << 16u) | (TCA9539PortGroup[1] << 8u) | TCA9539PortGroup[0]);
                                TCA9539SumTrigerInfo->TCA9539Triger[0].used = TRUE;
                                TCA9539SumTrigerInfo->new = 1;
                        }
                }
                else
                {
                        TCA9539SumTrigerInfo->TCA9539Triger[0].ReadResult = ((TCA9539PortGroup[3] << 24u) | (TCA9539PortGroup[2] << 16u) | (TCA9539PortGroup[1] << 8u) | TCA9539PortGroup[0]);
                        TCA9539SumTrigerInfo->TCA9539Triger[0].used = TRUE;
                        TCA9539SumTrigerInfo->new = 1;
                }
        }
        else
        {
                TCA9539SumTrigerInfo->TCA9539Triger[0].used = FALSE;
                TCA9539SumTrigerInfo->TCA9539Triger[1].used = FALSE;
        }
        return Ret;
}

Std_ReturnType Compare_9539_All(TCA9539SumTrigerType *TCA9539SumTrigerInfo, uint32 *TrigerValueInfo, uint8 RTCRam_Save)
{
        uint32 CompareValue, tempCompareValue1, tempCompareValue2, SameValueBit = 0x00;
        uint32 Origanl9539All_Save = sdrv_btm_hw_readl(0xF0010000, 0x44);

        if ((TRUE == TCA9539SumTrigerInfo->TCA9539Triger[0].used) && (TRUE == TCA9539SumTrigerInfo->TCA9539Triger[1].used))
        {
                SameValueBit = ~(TCA9539SumTrigerInfo->TCA9539Triger[0].ReadResult ^ TCA9539SumTrigerInfo->TCA9539Triger[1].ReadResult);
                tempCompareValue1 = (SameValueBit & TCA9539SumTrigerInfo->TCA9539Triger[0].ReadResult) & 0x1FF0F9C4;
                TCA9539SumTrigerReadResult = (tempCompareValue1 | (TCA9539SumTrigerReadResult & (~SameValueBit)));
                tempCompareValue1 = (TCA9539SumTrigerReadResult & 0x04FFFFFF); /*Fall or Rise*/
                tempCompareValue2 = (TCA9539SumTrigerReadResult & 0x1B000000); /*High or Low*/
                CompareValue = tempCompareValue1 ^ Origanl9539All_Save;        /****Difference from pervious*****/
                /*************Brake Fall*************/
                if (0x00100000 == (CompareValue & 0x00100000))
                {
                        if (0x00100000 == (TCA9539SumTrigerReadResult & 0x00100000))
                        {
                                CompareValue = CompareValue & 0xFFEFFFFF;
                        }
                }
                /*************Brake Fall*************/

                /*************Brake Up*************/
                if (0x04000000 == (CompareValue & 0x04000000))
                {
                        if (0 == (TCA9539SumTrigerReadResult & 0x04000000))
                        {
                                CompareValue = CompareValue & 0xFB000000;
                        }
                }
                /*************Brake Up*************/
                CompareValue = CompareValue | tempCompareValue2;
                if ((1 == RTCRam_Save) && (tempCompareValue1 != Origanl9539All_Save))
                {
                        sdrv_btm_hw_writel(0xF0010000, 0x44, tempCompareValue1);
                }
                *TrigerValueInfo = CompareValue;
                return E_OK;
        }
        else
        {
                return E_NOT_OK;
        }
}
#pragma default_function_attributes = @".iram_func"
void Cycle_HW_NM_Check(void)
{
        uint32 TrigerValue = 0;
        volatile uint8 Nm_Sleep_Flag = E_OK;
        if (E_OK == Read_9539_All(&TCA9539SumSingleTriger))
        {
                if (E_OK == Compare_9539_All(&TCA9539SumSingleTriger, &TrigerValue, 1))
                {
                        /*High priority*/
                        if (0x1B000000 & TrigerValue) /****IG1,IG2,OBC,BMS source for keeping COM Request*****/
                        {
                                HW_Active_ComReq = 1;
                        }
                        else if (0x04F0F9C4 & TrigerValue) /****source for Trigger COM Request*****/
                        {
                                HW_Trigger_Timer = (2000 / 10);
                        }
                        else /****source for MCU Wakeup Request except receiving PDU*****/
                        {
                                HW_Active_ComReq = 0;
                        }
                }
        }
        /*******************IO isn't from Read_9539_All*********************/
        if (0 == Dio_ReadChannel(DioConf_DioChannel_RKE_INT_GPIO_D37))
        {
                TRIGGER_SET_BIT(17, TCA9539SumTrigerReadResult);
        }
        /****************ComM0,1,2,3,5 for NM Channel**************************/
        if((NM_STATE_BUS_SLEEP == CanNm_ChRunTime[0].canNmState)&&(NM_STATE_BUS_SLEEP == CanNm_ChRunTime[1].canNmState)
                &&(NM_STATE_BUS_SLEEP == CanNm_ChRunTime[2].canNmState)&&(NM_STATE_BUS_SLEEP == CanNm_ChRunTime[3].canNmState))
        {
                if ((100 <= FirstWakeUpSource500ms) && (FALSE == NvM_WriteAllFlag) && (1 == NvM_InitReadAll_Flag))
                {
                        Dem_Shutdown();
                        PEPS_NVMWrite();
                        NvM_WriteAll();
                        NvM_WriteAllFlag = TRUE;
                        BswM_RequestMode(NVM_TIMER_START, 0x55);
                }
                BswM_RequestMode(NM_SLEEP_SWITCH, 1);
                CanSM_StartWakeupSource(Channel_CANFD3);
                CanSM_StartWakeupSource(Channel_CANFD6);
                CanSM_StartWakeupSource(Channel_CANFD8);
                CanSM_StartWakeupSource(Channel_CANFD5);
        }
        else
        {
                BswM_RequestMode(NM_SLEEP_SWITCH, 0);
                if (TRUE == NvM_WriteAllFlag)
                {
                        BswM_RequestMode(NVM_TIMER_START, 0xAA);
                        NvM_CancelWriteAll();
                        Dem_SetOperationCycleState((uint8)DemOperationCycle_ID, DEM_CYCLE_STATE_START);
                        NvM_WriteAllFlag = FALSE;
                }
                // if((NM_STATE_PREPARE_BUS_SLEEP == CanNm_ChRunTime[0].canNmState)&&(NM_STATE_PREPARE_BUS_SLEEP == CanNm_ChRunTime[1].canNmState)
                // &&(NM_STATE_PREPARE_BUS_SLEEP == CanNm_ChRunTime[2].canNmState)&&(NM_STATE_PREPARE_BUS_SLEEP == CanNm_ChRunTime[3].canNmState))
                // {
                //         BswM_RequestMode(NM_SLEEP_SWITCH,2); /*Disable all the Routing excepet the NM*/
                // }
                // else if((NM_STATE_READY_SLEEP <= CanNm_ChRunTime[0].canNmState)&&(NM_STATE_READY_SLEEP <=  CanNm_ChRunTime[1].canNmState)
                // &&(NM_STATE_READY_SLEEP <=  CanNm_ChRunTime[2].canNmState)&&(NM_STATE_READY_SLEEP <=  CanNm_ChRunTime[3].canNmState))
                // {
                //         BswM_RequestMode(NM_SLEEP_SWITCH,3); /*Enable all Routing*/
                // }
        }
}

void Cycle_ComM_Manage(void)
{
        /************Diag keep Full_ComM*****************/
        if (0 < DCM_Active_Timer)
        {
                DCM_Active_Timer--;
                if (0 == DCM_Active_Timer)
                {
                        DCM_Req_ComM_Flag = 0;
                }
        }
        if ((1 == HW_Active_ComReq) || (0x55 == App_ComMReqFlag) || (0 < HW_Trigger_Timer) || (1 == DCM_Req_ComM_Flag))
        {
                if (0 < HW_Trigger_Timer)
                {
                        HW_Trigger_Timer--;
                }

                for (uint8 i = 0; i < 9; i++)
                {
                        ComM_RequestComMode(i, COMM_FULL_COMMUNICATION);
                }
                BswM_RequestMode(HW_REQ_SWITCH, 10); /*HW REQ ComM*/
                ActiveNMReqFlag = 1;
                // NM_Sleep_Counter = 0;
        }
        else
        {
                ActiveNMReqFlag = 0;
                BswM_RequestMode(HW_REQ_SWITCH, 5); /*No HW REQ ComM*/
                if (1 == ComM_Request_Flag)         /*Receive NM Pdu lead to request FULL_COMM,except itself*/
                {
                        for (uint8 i = 0; i < 9; i++)
                        {
                                if (Nm_Rx_NetWorkID == i)
                                {
                                        ComM_RequestComMode(i, COMM_NO_COMMUNICATION);
                                        continue;
                                }
                                ComM_RequestComMode(i, COMM_FULL_COMMUNICATION);
                        }
                        ComM_Request_Flag = 0;
                }
                else if (TRUE == ComM_Req_NO_ComM)
                {
                        // if(COMM_NO_COMMUNICATION != ComM_UserReqMode[0])
                        // {
                        //         for(uint8 i = 0;i < 4;i++)
                        //         {
                        //                 P2CONST(CanNm_ChannelConfigType, AUTOMATIC, CANNM_APPL_CONST)chCfgPtr = &CanNm_GetChannelConfig(i);
                        //                 CanNm_InnerChannelType* chRTPtr = &CanNm_GetChannelRTData(i);
                        //                 chRTPtr->nmTimeoutTimer = chCfgPtr->TimeoutTime / CanNm_CfgPtr->MainFunctionPeriod;
                        //         }
                        // }
                        for (uint8 i = 0; i < 9; i++)
                        {
                                ComM_RequestComMode(i, COMM_NO_COMMUNICATION);
                        }
                        ComM_Req_NO_ComM = FALSE;
                        NM_Sleep_Counter = 0;
                }
        }
}
#pragma default_function_attributes =
void NM_UserDataPackup(void)
{
        uint8 tempBMS = 0, tempIGN = 0, tempOBC = 0, tempOthers = 0;
        uint8 tempKeepBMS = 0, tempKeepIGN = 0, tempKeepOBC = 0, tempKeepSta = 0;
        if (100 >= FirstWakeUpSource500ms)
        {
                if (0x34 == CCUWakeupReturnValue) /******BMS wakeup*****/
                {
                        tempBMS = 1;
                }
                else if (0x32 == CCUWakeupReturnValue) /******IG wakeup*****/
                {
                        tempIGN = 1;
                }
                else if (0x33 == CCUWakeupReturnValue) /******OBC wakeup*****/
                {
                        tempOBC = 1;
                }
                else
                {
                        if (0 == NMUserDataWakeupReas_Other)
                        {
                                NMUserDataWakeupReas_Other = 0x1F;
                        }
                        tempOthers = NMUserDataWakeupReas_Other;
                }
                Com_SendSignal(CCU_WakeupReas_BMS_IPDU_COM_TX_NM_ASR_CCU_EPT_CANFD6_EPT_CAN2, &tempBMS);
                Com_SendSignal(CCU_WakeupReas_OBC_IPDU_COM_TX_NM_ASR_CCU_EPT_CANFD6_EPT_CAN2, &tempOBC);
                Com_SendSignal(CCU_WakeupReas_IGN_IPDU_COM_TX_NM_ASR_CCU_EPT_CANFD6_EPT_CAN2, &tempIGN);
                Com_SendSignal(CCU_WakeupReas_Others_IPDU_COM_TX_NM_ASR_CCU_EPT_CANFD6_EPT_CAN2, &tempOthers);

                Com_SendSignal(CCU_WakeupReas_BMS_IPDU_COM_TX_NM_ASR_CCU_CHA_CANFD3_CHA_CAN5, &tempBMS);
                Com_SendSignal(CCU_WakeupReas_OBC_IPDU_COM_TX_NM_ASR_CCU_CHA_CANFD3_CHA_CAN5, &tempOBC);
                Com_SendSignal(CCU_WakeupReas_IGN_IPDU_COM_TX_NM_ASR_CCU_CHA_CANFD3_CHA_CAN5, &tempIGN);
                Com_SendSignal(CCU_WakeupReas_Others_IPDU_COM_TX_NM_ASR_CCU_CHA_CANFD3_CHA_CAN5, &tempOthers);

                Com_SendSignal(CCU_WakeupReas_BMS_IPDU_COM_TX_NM_ASR_CCU_BAC_CANFD8_BAC_CAN1, &tempBMS);
                Com_SendSignal(CCU_WakeupReas_OBC_IPDU_COM_TX_NM_ASR_CCU_BAC_CANFD8_BAC_CAN1, &tempOBC);
                Com_SendSignal(CCU_WakeupReas_IGN_IPDU_COM_TX_NM_ASR_CCU_BAC_CANFD8_BAC_CAN1, &tempIGN);
                Com_SendSignal(CCU_WakeupReas_Others_IPDU_COM_TX_NM_ASR_CCU_BAC_CANFD8_BAC_CAN1, &tempOthers);

                Com_SendSignal(CCU_WakeupReas_BMS_IPDU_COM_TX_NM_ASR_CCU_BOD_CANFD5_BOD_CAN6, &tempBMS);
                Com_SendSignal(CCU_WakeupReas_OBC_IPDU_COM_TX_NM_ASR_CCU_BOD_CANFD5_BOD_CAN6, &tempOBC);
                Com_SendSignal(CCU_WakeupReas_IGN_IPDU_COM_TX_NM_ASR_CCU_BOD_CANFD5_BOD_CAN6, &tempIGN);
                Com_SendSignal(CCU_WakeupReas_Others_IPDU_COM_TX_NM_ASR_CCU_BOD_CANFD5_BOD_CAN6, &tempOthers);
        }
        if (0x10000000 & TCA9539SumTrigerReadResult) /****IG1,IG2,OBC,BMS source for keeping COM Request*****/
        {
                tempKeepBMS = 1;
        }
        if (0x03000000 & TCA9539SumTrigerReadResult) /****IG1,IG2,OBC,BMS source for keeping COM Request*****/
        {
                tempKeepIGN = 1;
        }
        if (0x08000000 & TCA9539SumTrigerReadResult) /****IG1,IG2,OBC,BMS source for keeping COM Request*****/
        {
                tempKeepOBC = 1;
        }
        Com_SendSignal(CCU_KeepAwakeReasBMS_IPDU_COM_TX_NM_ASR_CCU_EPT_CANFD6_EPT_CAN2, &tempKeepBMS);
        Com_SendSignal(CCU_KeepAwakePwrMode_IPDU_COM_TX_NM_ASR_CCU_EPT_CANFD6_EPT_CAN2, &tempKeepIGN);
        Com_SendSignal(CCU_KeepAwakeReasOBC_IPDU_COM_TX_NM_ASR_CCU_EPT_CANFD6_EPT_CAN2, &tempKeepOBC);

        Com_SendSignal(CCU_KeepAwakeReasBMS_IPDU_COM_TX_NM_ASR_CCU_CHA_CANFD3_CHA_CAN5, &tempKeepBMS);
        Com_SendSignal(CCU_KeepAwakePwrMode_IPDU_COM_TX_NM_ASR_CCU_CHA_CANFD3_CHA_CAN5, &tempKeepIGN);
        Com_SendSignal(CCU_KeepAwakeReasOBC_IPDU_COM_TX_NM_ASR_CCU_CHA_CANFD3_CHA_CAN5, &tempKeepOBC);

        Com_SendSignal(CCU_KeepAwakeReasBMS_IPDU_COM_TX_NM_ASR_CCU_BAC_CANFD8_BAC_CAN1, &tempKeepBMS);
        Com_SendSignal(CCU_KeepAwakePwrMode_IPDU_COM_TX_NM_ASR_CCU_BAC_CANFD8_BAC_CAN1, &tempKeepIGN);
        Com_SendSignal(CCU_KeepAwakeReasOBC_IPDU_COM_TX_NM_ASR_CCU_BAC_CANFD8_BAC_CAN1, &tempKeepOBC);

        Com_SendSignal(CCU_KeepAwakeReasBMS_IPDU_COM_TX_NM_ASR_CCU_BOD_CANFD5_BOD_CAN6, &tempKeepBMS);
        Com_SendSignal(CCU_KeepAwakePwrMode_IPDU_COM_TX_NM_ASR_CCU_BOD_CANFD5_BOD_CAN6, &tempKeepIGN);
        Com_SendSignal(CCU_KeepAwakeReasOBC_IPDU_COM_TX_NM_ASR_CCU_BOD_CANFD5_BOD_CAN6, &tempKeepOBC);
        if (tempKeepBMS || tempKeepIGN || tempKeepOBC || DCM_Req_ComM_Flag)
        {
                tempKeepSta = 1;
        }
        Com_SendSignal(CCU_KeepAwakeSta_IPDU_COM_TX_NM_ASR_CCU_BAC_CANFD8_BAC_CAN1, &tempKeepSta);
        Com_SendSignal(CCU_KeepAwakeSta_IPDU_COM_TX_NM_ASR_CCU_BOD_CANFD5_BOD_CAN6, &tempKeepSta);
        Com_SendSignal(CCU_KeepAwakeSta_IPDU_COM_TX_NM_ASR_CCU_CHA_CANFD3_CHA_CAN5, &tempKeepSta);
        Com_SendSignal(CCU_KeepAwakeSta_IPDU_COM_TX_NM_ASR_CCU_EPT_CANFD6_EPT_CAN2, &tempKeepSta);

        Com_SendSignal(CCU_KeepAwakeReasDiag_IPDU_COM_TX_NM_ASR_CCU_BAC_CANFD8_BAC_CAN1, &DCM_Req_ComM_Flag);
        Com_SendSignal(CCU_KeepAwakeReasDiag_IPDU_COM_TX_NM_ASR_CCU_BOD_CANFD5_BOD_CAN6, &DCM_Req_ComM_Flag);
        Com_SendSignal(CCU_KeepAwakeReasDiag_IPDU_COM_TX_NM_ASR_CCU_CHA_CANFD3_CHA_CAN5, &DCM_Req_ComM_Flag);
        Com_SendSignal(CCU_KeepAwakeReasDiag_IPDU_COM_TX_NM_ASR_CCU_EPT_CANFD6_EPT_CAN2, &DCM_Req_ComM_Flag);
}

void HW_NM_Check_BeforeRTC(void)
{
        Std_ReturnType Ret = E_NOT_OK;
        uint8 I2CCounter = 0;
        uint8 RestFlag = 0;
        uint32 TrigerLastValue = 0;
        uint8 Read_State[4] = {0};
        uint32 TCA9539PortGroup[4] = {0};
        TCA9539SumTrigerType TCA9539SumTrigerInfoLast = {{{TRUE, 0}, {TRUE, 0}}, 0};
        do
        {
                Read_State[0] = IoExp_TCA9539_GetPortInputValue(TCA9539_CHIP_A, TCA9539_PORTGROUP0, (uint8 *)&TCA9539PortGroup[0]);
                Read_State[1] = IoExp_TCA9539_GetPortInputValue(TCA9539_CHIP_A, TCA9539_PORTGROUP1, (uint8 *)&TCA9539PortGroup[1]);
                Read_State[2] = IoExp_TCA9539_GetPortInputValue(TCA9539_CHIP_B, TCA9539_PORTGROUP0, (uint8 *)&TCA9539PortGroup[2]);
                Read_State[3] = IoExp_TCA9539_GetPortInputValue(TCA9539_CHIP_B, TCA9539_PORTGROUP1, (uint8 *)&TCA9539PortGroup[3]);
                I2CCounter++;
        } while (((E_NOT_OK == Read_State[0]) || (E_NOT_OK == Read_State[1]) || (E_NOT_OK == Read_State[2]) || (E_NOT_OK == Read_State[3])) && (200 > I2CCounter));
        if (200 > I2CCounter)
        {
                TCA9539SumTrigerInfoLast.TCA9539Triger[0].ReadResult = ((TCA9539PortGroup[3] << 24u) | (TCA9539PortGroup[2] << 16u) | (TCA9539PortGroup[1] << 8u) | TCA9539PortGroup[0]);
                TCA9539SumTrigerInfoLast.TCA9539Triger[1].ReadResult = TCA9539SumTrigerInfoLast.TCA9539Triger[0].ReadResult;
                (void)Compare_9539_All(&TCA9539SumTrigerInfoLast, &TrigerLastValue, 0);
                /*High priority*/
                if (0x1FF0F9C4 & TrigerLastValue) /****All the HW wakeup except the Can&Lin*****/
                {
                        RestFlag = 1;
                }
        }
        /*******************IO isn't from Read_9539_All*********************/
        if ((0 == Dio_ReadChannel(DioConf_DioChannel_RKE_INT_GPIO_D37)) || (1 == RestFlag))
        {
                Mcu_PerformReset();
        }
}

void BswM_Run_Callout(void)
{
}
void BSWM_AppRun_Callout(void)
{
}
void BSWM_EnterAppRun(void)
{
        BswM_EcuM_CurrentState(ECUM_STATE_APP_RUN);
}

void BSWM_EnterShutDown(void)
{
        BswM_EcuM_CurrentState(ECUM_STATE_SHUTDOWN);
}

void BswM_ReadAllFinish_CallOut(void)
{
        Dem_Init(&DemPbCfg);
        Dem_SetOperationCycleState((uint8)DemOperationCycle_ID, DEM_CYCLE_STATE_START);
        NvM_InitReadAll_Flag = 1;
}

void BswM_WriteAllFinish_CallOut(void)
{
        NvM_CancelWriteAll();
        Dem_SetOperationCycleState((uint8)DemOperationCycle_ID, DEM_CYCLE_STATE_START);
        NvM_WriteAllFlag = FALSE;
        BswM_RequestMode(NVM_TIMER_START, 0xAA);
}

void Delay1ms(void)
{
        for (uint32 timerCounter = 0; timerCounter < 0x14000; timerCounter++)
        {
        }
}