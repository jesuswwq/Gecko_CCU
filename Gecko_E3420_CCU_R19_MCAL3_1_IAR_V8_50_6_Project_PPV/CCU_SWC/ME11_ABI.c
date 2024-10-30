
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "ME11_ABI.h"
#include <__regs_base_E3.h>
#include "IoExp_TCA6408_Api.h"
#include "TLE75242_Api.h"

#define VCC 2600.0
#define  DataLength_BCM_IMM_NVMData 128u
#define  DataLength_BCM_PD_NVMData  10u
#define  DataLength_TMS_NVMData 256u
#define  DataLength_VCU_NVMData 64u
#define  DataLength_VCU_IMM128_NVMData 64u
// #define RTC_TEST   /*for test RTC wakeup*/
#define SWCTimer_Min 0U 
#define SWCTimer_Max 65535U

extern uint32 AD4067Avalue[adsize_4067A];
extern uint32 AD4067Bvalue[adsize_4067B];
extern uint32 AD4067Cvalue[adsize_4067C];
extern uint32 AD4067Dvalue[adsize_4067D];
extern uint32 AD4067Evalue[adsize_4067E];
extern Adc_ValueGroupType adc2_group0_resultbuffer[buffersizeAdc0];
extern Adc_ValueGroupType adc2_group1_resultbuffer[buffersizeAdc1];
extern Adc_ValueGroupType adc2_group2_resultbuffer[buffersizeAdc2];

extern uint8 tca6424A[4];
extern uint8 tca6424B[4];
extern uint8 tca6424C[4];
extern uint8 tca6424D[4];
extern uint8 tca6424E[4];
extern uint8 tle75242A;
extern uint8 tle75242B;
extern uint16 tle8108;
extern uint16 tle75004;
extern uint8 App_ComMReqFlag;
extern uint8 App_SleepReqFlag ;




uint16 ABIRTC_Timer = 0;
TLE8108EM_Data_T TLE8108EM_TX_Buffer;
uint8 u8Key_Match_flg;
uint8 key_word[256] = {0};
boolean INV_IMMO_Req_EPT_RevFlag =0;
//================BSWversion============================
uint8  VBSW_BswVer0_cnt = 24;
uint8  VBSW_BswVer1_cnt = 2;
//======================================================

/*新增高压互锁电压20241025*/
uint16 GetHw_FirsttInterLckVolt(void)  //主要高压互锁
{
	float ad_V = 0.0;
	ad_V = ((float)AD4067Evalue[9]) / 4095.0 * 3300.0 * 98.0 / 30.0;
	return ad_V;																		
}

uint16 GetHw_SecondInterLckVolt(void)  //次要高压互锁
{
	float ad_V = 0.0;
	ad_V = ((float)AD4067Dvalue[9]) / 4095.0 * 3300.0 * 98.0 / 30.0;
	return ad_V; 																
}

// 制动踏板 IN_IAN25
// 加速踏板油门踏板2信号 IN_IAN24
uint16 GetHw_AccPedCh2Volt(void)
{
	uint16 param1 = 0;
	param1 = (uint16)(((float)adc2_group0_resultbuffer[1]) / 4095.0 * 3300.0 * 1.2); 
	return param1;
}

uint8 GetHw_KL15A(void)//IGN1高电平检测
{

	return Tca9539_IOValue[TCA9539_CHIP_B][IOEXP_TCA9539_P10];
}

uint8 GetHw_KL15B(void)
{

	return Tca9539_IOValue[TCA9539_CHIP_B][IOEXP_TCA9539_P11];
}

uint8 GetHw_DrvrDoorLckSts(void)//主驾驶门锁状态
{

	return Tca9539_IOValue[TCA9539_CHIP_A][IOEXP_TCA9539_P06];
}

uint8 GetHw_DrvrDoorAjarSts(void)//主驾门状态
{

	return Tca9539_IOValue[TCA9539_CHIP_A][IOEXP_TCA9539_P07];
}

uint8 GetHw_BrkSwLo(void)//刹车开关信号（常低）
{
	
	return Tca9539_IOValue[TCA9539_CHIP_B][IOEXP_TCA9539_P12];
}

uint16 GetHw_AccPedCh1SuplyVolt(void)
{
	return 5000;
}

void SetHw_IG1RlyCls(uint8 state)//IG继电器1
{
	if (state == 1)
	{
		tle75242A = (1 << 7) | tle75242A;
		tle75242B = (1 << 5) | tle75242B;
	}
	else
	{
		tle75242A = ((1 << 7) ^ 0xFF) & tle75242A;
		tle75242B = ((1 << 5) ^ 0xFF) & tle75242B;
	}
}

void SetHw_IG2RlyCls(uint8 state)//IG继电器2
{
	if (state == 1)
	{
		tle75242B = (1 << 4) | tle75242B;
	}
	else
	{
		tle75242B = ((1 << 4) ^ 0xFF) & tle75242B;
	}
}

void SetHw_WakeupBMS(uint8 state)//唤醒BMS、 INV 75242_B_HS_OUT6
{
	if (state == 1)
	{
		// HS_Ctrl_75242_B_HS_OUT6_On();
		tle75242B = (1 << 6) | tle75242B;
	}
	else
	{
		// HS_Ctrl_75242_B_HS_OUT6_Off();
		tle75242B = ((1 << 6) ^ 0xFF) & tle75242B;
	}
}

/*#######################  New Definition  #########################*/

/***Digital Input***/
uint8 GetHw_BrkSwHi(void) // 刹车开关信号（高有效）Pin:IDL21
{
	return Tca9539_IOValue[TCA9539_CHIP_B][IOEXP_TCA9539_P04];
}

uint8 GetHw_OBCWakeup(void) // OBC硬线唤醒CCUPin:IDH2
{
	return Tca9539_IOValue[TCA9539_CHIP_B][IOEXP_TCA9539_P13];
}

uint8 GetHw_BMSWakeup(void) // BMS硬线唤醒CCUPin:IDH3
{
	return Tca9539_IOValue[TCA9539_CHIP_B][IOEXP_TCA9539_P14];
}

uint8 GetHw_EmgcyShutOff(void) // 急停开关Pin:IDX2
{
	return Tca9539_IOValue[TCA9539_CHIP_B][IOEXP_TCA9539_P17];
}

uint8 GetHw_HzrdLampSw(void) // 危险报警灯开关Pin:IDL3
{
	return Tca9539_IOValue[TCA9539_CHIP_A][IOEXP_TCA9539_P02];
}


uint8 GetHw_FrntWshrSw(void) // 洗涤开关预留OTS 改为CAN 发送
{
	//	uint8 FrntWshrSw_flg = 0;
	//	FrntWshrSw_flg = IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_A, IOEXP_TCA9539_P03);
	return Tca9539_IOValue[TCA9539_CHIP_A][IOEXP_TCA9539_P03];
}

uint8 GetHw_WiprStopPstnDtct(void) // 雨刮停止位检测Pin:IDL5
{
	return Tca9539_IOValue[TCA9539_CHIP_A][IOEXP_TCA9539_P04];
}

uint8 GetHw_AlrmHornSw(void) // 电喇叭开关Pin:IDL16
{
	return Tca9539_IOValue[TCA9539_CHIP_A][IOEXP_TCA9539_P17];
}

uint8 GetHw_PsngrDoorAjarSts(void) // 副驾门状态Pin:IDL9
{
	return Tca9539_IOValue[TCA9539_CHIP_A][IOEXP_TCA9539_P10];
}

/***Analog Input***/
uint16 GetHw_LoBeamSwSts(void) // 位置灯&近光灯开关电压检测Pin:IAN1
{
	float ad_V = 0.0;
	uint16 ad_R = 0;
	ad_V = ((float)AD4067Dvalue[5]) / 4095.0 * 3300.0 * 6.0 / 5.0;
	if (ad_V > 2400)
	{
		ad_R = 0xffff;
	}
	else
	{
		ad_R = (uint16)(ad_V / (VCC - ad_V) * 3000.0);
	}
	return ad_R;
}

uint16 GetHw_HiBeamSwSts(void) // 远光灯&超车灯开关电压检测Pin:IAN2
{
	float ad_V = 0.0;
	uint16 ad_R = 0;
	ad_V = ((float)AD4067Dvalue[0]) / 4095.0 * 3300.0 * 6.0 / 5.0;
	if (ad_V > 2400)
	{
		ad_R = 0xffff;
	}
	else
	{
		ad_R = (uint16)(ad_V / (VCC - ad_V) * 3000.0);
	}
	return ad_R;
}

uint16 GetHw_TurnLampSwSts(void) // 左右转向灯开关信号检测Pin:IAN3
{
	float ad_V = 0.0;
	uint16 ad_R = 0;
	ad_V = ((float)AD4067Dvalue[1]) / 4095.0 * 3300.0 * 6.0 / 5.0;
	if (ad_V > 2400)
	{
		ad_R = 0xffff;
	}
	else
	{
		ad_R = (uint16)(ad_V / (VCC - ad_V) * 3000.0);
	}
	return ad_R;
}

uint16 GetHw_WiprSwSts(void) // 雨刮开关电压检测Pin:IAN4
{
	float ad_V = 0.0;
	uint16 ad_R = 0;
	ad_V = ((float)AD4067Dvalue[2]) / 4095.0 * 3300.0 * 6.0 / 5.0;
	if (ad_V > 2400)
	{
		ad_R = 0xffff;
	}
	else
	{
		ad_R = (uint16)(ad_V / (VCC - ad_V) * 3000.0);
	}
	return ad_R;
}


//      换挡开关输入
uint16 GetHw_ShftPstnSwSts(void)//换挡开关输入	IN_IAN30
{
	float ad_V = 0.0;
	uint16 ad_R = 0;
	ad_V =(uint16)((float)AD4067Dvalue[4] / 4095.0 * 3300.0 * 6.0 / 5.0);
	//ad_V = ((float)(AD4067Dvalue[4] / 4095.0 * 3300.0)); /*PPV IAN30 change*/
	if (ad_V > 2600)/*ppv ian30 need to 2100*/
	{
		ad_R = 0xffff;
	}
	#if 1 /*if you wanna change ian30 , you should cancle the else if*/
	else if(ad_V > 2350)
	{
		ad_R = 38000;
	}
	#endif
	else
	{
		ad_R = (uint16)(ad_V / (VCC - ad_V) * 2000.0);
		//ad_R = (uint16)(ad_V / (VCC - ad_V) * 15000.0);/*PPV IAN30 change*/
	}

	return ad_R;
}

// 加速踏板油门踏板1信号 IN_IAN23
uint16 GetHw_AccPedCh1Volt(void)
{
	uint16 param1 = 0;
	param1 =(uint16) (((float)adc2_group0_resultbuffer[0]) / 4095.0 * 3300.0 * 1.68); // 6.0 / 5.0);
	return param1;																	  // adc1_group1_resultbuffer[0];

}

/***Digital Output***/
void SetHw_WiprOn(uint8 state) // 雨刮电源低速Pin:ODC01_NO  OUT_EXP_D_P05
{
	if (state == 1)
	{
		tca6424D[1] = 0x20 | tca6424D[1];

	}
	else
	{
		tca6424D[1] = 0xDF & tca6424D[1];

	}
}

void SetHw_WiprHiSpd(uint8 state) // 高速雨刮Pin:ODC02_NO
{
	if (state == 1)
	{
		
		tca6424D[1] = 0x04 | tca6424D[1];
	}
	else
	{
		tca6424D[1] = 0xFB & tca6424D[1];
		
	}
}

void SetHw_FrntWshrOn(uint8 state) // 前洗涤Pin:ODC03_CON
{
	if (state == 1)
	{
		tca6424D[1] = 0x80 | tca6424D[1];
		
	}
	else
	{
		tca6424D[1] = 0x7F & tca6424D[1];
		
	}
}

void SetHw_GlbDoorUnlck(uint8 state) // 四门解锁Pin:ODC05_CON
{
	if (state == 1)
	{
		tca6424D[1] = 0x02 | tca6424D[1];
		
	}
	else
	{
		tca6424D[1] = 0xFD & tca6424D[1];
	
	}
}

void SetHw_GlbDoorLck(uint8 state) // 四门上锁Pin:ODC06_CON
{
	if (state == 1)
	{
		tca6424D[1] = 0x01 | tca6424D[1];
	
	}
	else
	{
		tca6424D[1] = 0xFE & tca6424D[1];
	
	}
}

void SetHw_DrvrWinUp(uint8 state) // 主驾车窗上升Pin:ODC7_CON
{
	if (state == 1)
	{
          tca6424D[2] = 0x08 | tca6424D[2];//IN1:1  IN2:0 上升
		
	}
	else
	{
		tca6424D[2] = (0x8^0xFF) & tca6424D[2];
	
	}
}

void SetHw_DrvrWinDwn(uint8 state) // 主驾车窗下降Pin:ODC8_CON
{
	if (state == 1)
	{
		
		tca6424D[2] = 0x04 | tca6424D[2];
	}
	else
	{
		
                tca6424D[2] = 0xFB & tca6424D[2];
		//tca6424D[2] = 0xF3 & tca6424D[2];
	}
}


void SetHw_PsngrWinUp(uint8 state) // 副驾车窗上升Pin:ODC9_CON
{
	if (state == 1)
	{
		 
		tca6424D[2] = 0x02 | tca6424D[2];
	}
	else
	{
		
		tca6424D[2] = 0xFD & tca6424D[2];
	}
}

void SetHw_PsngrWinDwn(uint8 state) // 副驾车窗下降Pin:ODC10_CON
{
	if (state == 1)
	{
	
		tca6424D[1] = 0x40 | tca6424D[1];
	}
	else
	{
	
		tca6424D[1] = (0x40 ^ 0xFF) & tca6424D[1];
	}
}

void SetHw_PstnLampOn(uint8 state) // 位置灯Pin:7020_A_OUT0
{
	if (state == 1)
	{
		BTS7020_CtrlOutputChannelOn(BTS7020_CHIP_A, BTS7020_OUT0);
	}
	else
	{
		BTS7020_CtrlOutputChannelOff(BTS7020_CHIP_A, BTS7020_OUT0);
	}
}

void SetHw_TurnLampOnLeft(uint8 state) // 左转向灯Pin:7012_C_OUT0
{
	if (state == 1)
	{
		BTS7012_CtrlOutputChannelOn(BTS7012_CHIP_C, BTS7012_OUT0);
	}
	else
	{
		BTS7012_CtrlOutputChannelOff(BTS7012_CHIP_C, BTS7012_OUT0);
	}
}

void SetHw_TurnLampOnRght(uint8 state) // 右转向灯Pin:7012_C_OUT1
{
	if (state == 1)
	{
		BTS7012_CtrlOutputChannelOn(BTS7012_CHIP_C, BTS7012_OUT1);
	}
	else
	{
		BTS7012_CtrlOutputChannelOff(BTS7012_CHIP_C, BTS7012_OUT1);
	}
}

void SetHw_BrkLghtOn(uint8 state) // 刹车灯Pin:7012_B_OUT0
{
	if (state == 1)
	{
		BTS7012_CtrlOutputChannelOn(BTS7012_CHIP_B, BTS7012_OUT0);
	}
	else
	{
		BTS7012_CtrlOutputChannelOff(BTS7012_CHIP_B, BTS7012_OUT0);
	}
}

void SetHw_RvrsLampOn(uint8 state) // 倒车灯Pin:7020_B_OUT1
{
	if (state == 1)
	{
		BTS7020_CtrlOutputChannelOn(BTS7020_CHIP_B, BTS7020_OUT1);
	}
	else
	{
		BTS7020_CtrlOutputChannelOff(BTS7020_CHIP_B, BTS7020_OUT1);
	}
}

void SetHw_HzrdLampOn(uint8 state) // 危险报警灯Pin:ODH3
{
	if (state == 1)
	{
		tle75242A = (1 << 4) | tle75242A;
		// HS_Ctrl_75242_A_HS_OUT4_On();
	}
	else
	{
		tle75242A = ((1 << 4) ^ 0xFF) & tle75242A;
		// HS_Ctrl_75242_A_HS_OUT4_Off();
	}
}

void SetHw_LoBeamOn(uint8 state) // 近光灯Pin:ODL1
{
	if (state == 1)
	{
		
		TLE8108EM_TX_Buffer.SI.IN1 = 2;
	}
	else
	{
		
		TLE8108EM_TX_Buffer.SI.IN1 = 3;
	}
	tle8108 = TLE8108EM_TX_Buffer.U;
}

void SetHw_HiBeamOn(uint8 state) // 远光灯Pin:ODL2
{
	if (state == 1)
	{
		
		TLE8108EM_TX_Buffer.SI.IN2 = 2;
	}
	else
	{
		
		TLE8108EM_TX_Buffer.SI.IN2 = 3;
	}
	tle8108 = TLE8108EM_TX_Buffer.U;
}

void SetHw_AlrmHornOn(uint8 state) // 电喇叭Pin:ODL5
{
	if (state == 1)
	{
		
		TLE8108EM_TX_Buffer.SI.IN5 = 2;
	}
	else
	{
	
		TLE8108EM_TX_Buffer.SI.IN5 = 3;
	}
	tle8108 = TLE8108EM_TX_Buffer.U;
}

uint8 GetHw_FrontFogLampSw(void) // 前雾灯开关
{
	
	return Tca9539_IOValue[TCA9539_CHIP_A][IOEXP_TCA9539_P00];
}
uint8 GetHw_RearFogLampSw(void) // 后雾灯开关
{
	
	return Tca9539_IOValue[TCA9539_CHIP_A][IOEXP_TCA9539_P01];
}

void SetHw_RearFogLampOn(uint8 state) // 后雾灯
{
	if (state == 1)
	{
		BTS7020_CtrlOutputChannelOn(BTS7020_CHIP_A, BTS7020_OUT1);
	}
	else
	{
		BTS7020_CtrlOutputChannelOff(BTS7020_CHIP_A, BTS7020_OUT1);
	}
}

void SetHw_FrontFogLamps(uint8 Sts) // 前雾灯Pin:ODL3
{
  	if (Sts == 1)
	{
		TLE8108EM_TX_Buffer.SI.IN3 = 2;
	}
	else
	{
		TLE8108EM_TX_Buffer.SI.IN3 = 3;
	}
	tle8108 = TLE8108EM_TX_Buffer.U;
}
void SetHw_SavePwrEnbl(uint8 state) // 节电
{
	if (state == 1)
	{
		BTS7012_CtrlOutputChannelOn(BTS7012_CHIP_B, BTS7012_OUT1);
	}
	else
	{
		BTS7012_CtrlOutputChannelOff(BTS7012_CHIP_B, BTS7012_OUT1);
	}
}

void SetHw_DayRunLghtOn(uint8 state) // 日行灯
{
	if (state == 1)
	{
		BTS7020_CtrlOutputChannelOn(BTS7020_CHIP_B, BTS7020_OUT0);
	}
	else
	{
		BTS7020_CtrlOutputChannelOff(BTS7020_CHIP_B, BTS7020_OUT0);
	}
}

void SetHw_CabinLampPWM(uint8 frq, uint8 duty) // 驾驶室内灯8108_LS_OUT_4
{
	uint32 Frq = 0;
	TLE8108EM_TX_Buffer.SI.IN4 = 1;
	Frq = (uint32)1000000000 / 100; // frq
	TLE8108EM_PwmCtrlChannelOutput(DO_OUT_4, duty, Frq);
}

// PE test


void set_OUT_EXP_D_P27(uint8 stats)
{
	if (1 == stats)
	{
		tca6424D[3] = (0x80) | tca6424D[3];
		IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_D, IOEXP_TCA6424_P27, STD_HIGH);
	}
	else
	{
		tca6424D[3] = (0x80 ^ 0xFF) & tca6424D[3];
		IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_D, IOEXP_TCA6424_P27, STD_LOW);
	}
	// read
	// IoExp_TCA6424_GetChannelInputLevel(TCA6424_CHIP_D, IOEXP_TCA6424_P27);
}

void set_OUT_EXP_C_P00(uint8 stats)
{
	if (1 == stats)
	{
		tca6424C[1] = (0x01) | tca6424C[1];
		IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_C, IOEXP_TCA6424_P00, STD_HIGH);
	}
	else
	{
		tca6424C[1] = (0x01 ^ 0xFF) & tca6424C[1];
		IoExp_TCA6424_SetChannelOutLevel(TCA6424_CHIP_C, IOEXP_TCA6424_P00, STD_LOW);
	}
	// read
	// IoExp_TCA6424_GetChannelInputLevel(TCA6424_CHIP_C, IOEXP_TCA6424_P00);


// Ps test


// Str_PEPS_T01 Aukey;
	/* if (1==GetHw_BrkSwLo && 1==GetHw_FRPESwSta)
	{
	  Aukey.conter++;
	}
	else
	{
	  Aukey.conter=0u;
	}
	if(Aukey.conter>=100)
	{
	  Aukey.timer++;
	  u8Key_Match_flg=1u;
	}
	else
	{
	  Aukey.timer=0u;
	  u8Key_Match_flg=0u;
	}*/
}

uint8 GetHw_FRPESwSta(void)//右侧PE开关
{
	uint8 IGN1_flg = 0;
	IGN1_flg = Tca9539_IOValue[TCA9539_CHIP_B][IOEXP_TCA9539_P06];
	// IGN1_flg = IoExp_TCA9539_GetChannelInputLevel(TCA9539_CHIP_B, IOEXP_TCA9539_P06);
	// if (IGN1_flg == 1)
	// {
	// 	IGN1_flg = 0;
	// }
	// else
	// {
	// 	IGN1_flg = 1;
	// }
	return IGN1_flg;
}

uint8 GetHw_FLPESwSta(void)//左侧PE开关
{
	uint8 IGN1_flg = 0;

	IGN1_flg = Tca9539_IOValue[TCA9539_CHIP_B][IOEXP_TCA9539_P05];
	// IGN1_flg = IoExp_TCA9539_GetPortInputValue(TCA9539_CHIP_B, IOEXP_TCA9539_P05);
	// if (IGN1_flg == 1)
	// {
	// 	IGN1_flg = 0;
	// }
	// else
	// {
	// 	IGN1_flg = 1;
	// }
	return IGN1_flg;
}

uint8 temptime = 0;

	
// TMS
/* Input */
uint16 get_CabinValtage(void) // ADCIO B2 车内温度	IN_IAN33
{
	float ad_V = 0.0;
	ad_V = ((float)AD4067Avalue[4]) / 4095.0 * 3300.0;
	return (uint16)ad_V;
}

uint16 get_EnvValtage(void) // ADCIO B14 环境温度 车外温度	IN_IAN34
{
	float ad_V = 0.0;
	// uint16 ad_R = 0;
	ad_V = ((float)AD4067Avalue[6]) / 4095.0 * 3300.0; // * 6.0 / 5.0;
	// ad_R = (uint16)(ad_V / (VCC- ad_V) * 5100.0);
	return (uint16)ad_V;
}

uint16 get_FaceDuctValtage(void) // ADCIO B5 左吹面温度	IN_IAN31
{
	float ad_V = 0.0;
	ad_V = ((float)AD4067Avalue[3]) / 4095.0 * 3300.0; 
	return (uint16)ad_V;
}

uint16 get_FootDuctValtage(void) // ADCIO B7 吹脚传感器 左吹脚温度IN_IAN32
{
	float ad_V = 0.0;
	ad_V = ((float)AD4067Avalue[5]) / 4095.0 * 3300.0; 
	return (uint16)ad_V;
}

uint16 get_ACCMHighTempValtage(void) // ADC_EXP_A_IN8 L8 ACCM出口(AD4067A)压缩机排气温度传感器IAN47
{
	float ad_V = 0.0;
	ad_V = ((float)adc2_group1_resultbuffer[6]) / 4095.0 * 3300.0;
	return (uint16)ad_V;
}

uint16 get_WCCHighTempValtage(void) // ADC_EXP_A_IN9 L9 WCC出口(AD4067A)
{
	float ad_V = 0.0;
	// uint16 ad_R = 0;
	ad_V = ((float)adc2_group1_resultbuffer[5]) / 4095.0 * 3300.0; // * 6.0 / 5.0;
	// ad_R = (uint16)(ad_V / (VCC- ad_V) * 20000.0);
	return (uint16)ad_V;
}

uint16 get_OHXTempValtage(void) // ADC_EXP_A_IN10 L10 外换出口(AD4067A)室外换热器温度NTC+ IN_IAN49
{
	float ad_V = 0.0;
	ad_V = ((float)adc2_group1_resultbuffer[8]) / 4095.0 * 3300.0;
	return (uint16)ad_V;
}

uint16 get_EVAPTempValtage(void) // ADC_EXP_A_IN11 L11 蒸发器出口(AD4067A) IN_IAN48
{
	float ad_V = 0.0;
	ad_V = ((float)adc2_group1_resultbuffer[7]) / 4095.0 * 3300.0;
	return (uint16)ad_V;
}

uint16 get_ChillTempValtage(void)//chiller出口温度(AD4067A) IN_IAN43
{
	float ad_V = 0.0;
	ad_V = ((float)adc2_group1_resultbuffer[3]) / 4095.0 * 3300.0;
	return (uint16)ad_V;
}

uint16 get_MotInletTempValtage(void) // L1 电机入水口温度(AD4067A) 冷却水路温度IN_IAN41
{
	float ad_V = 0.0;
	ad_V = ((float)adc2_group1_resultbuffer[2]) / 4095.0 * 3300.0;
	return (uint16)ad_V;
}

uint16 get_EVAPSurfTempValtage(void) // ADCIO C0 蒸发器表面温度 IN_IAN37
{
	float ad_V = 0.0;
	ad_V = ((float)AD4067Avalue[9]) / 4095.0 * 3300.0;
	return (uint16)ad_V;
}

uint16 get_SolorValtage(void) // ADCIO C11 阳光传感器 IN_IAN17
{
	uint16 param1 = 0;
	param1 = (uint16)(((float)AD4067Evalue[3]) / 4095.0 * 3300.0);
	return param1;
}

uint16 get_WCCHighPressValtage(void) // ADC_EXP_A_IN15 L15 WCC出口压力传感器信号 IN_IAN45
{

	uint16 param1 = 0;
	param1 = (uint16)(((float)adc2_group1_resultbuffer[4]) / 4095.0 * 3300.0 * 1.68);
	return param1;
}

uint16 get_LowPressValtage(void) // ADC_EXP_A_IN7 L7 压缩机吸气压力传感器信号(AD4067A)IN_IAN44
{
	uint16 param1 = 0;
	param1 = (uint16)(((float)adc2_group1_resultbuffer[9]) / 4095.0 * 3300.0 * 1.68);
        return param1;
}

uint16 get_MixDoorValtage(void) // ADCIO C3 主驾侧温度执行器位置反馈 IN_IAN38
{
	uint16 param1 = 0;
	param1 = (uint16)(((float)AD4067Avalue[0]) / 4095.0 * 3300.0 * 1.68);
	return param1;
}

uint16 get_RecircValtage(void) // ADC_EXP_A_IN0 L0 内外循环执行器位置反馈(AD4067A)IN_IAN39
{
	uint16 param1 = 0;
	param1 = (uint16)(((float)AD4067Avalue[10]) / 4095.0 * 3300.0 * 1.68);
	return param1;
}

uint16 get_ModeMotorValtage(void) // ADCIO B3 模式执行器位置反馈 IN_IAN35
{
	uint16 param1 = 0;
	param1 =(uint16) (((float)adc2_group1_resultbuffer[1]) / 4095.0 * 3300.0 * 1.68);
	return param1;
}

void set_BlwFan(uint16 Frq, uint16 duty)
{
	uint32 Frq_A = 0;
	uint32 duty_pect = 0;
	// Dio_WriteChannel(GPIO_H5, 1);
	if(Frq !=0)
	{
		Frq_A = (uint32)1000000000 / Frq;
		duty_pect = (uint32)duty * (0x8000) / 100;
		VNQ7E100_CtrlB(VNQ7E100_Ch_Out0, Frq_A, duty_pect);

	}

}

void set_CoolFan(uint8 frq, uint8 duty)
{
	uint32 Frq = 0;

	TLE8108EM_TX_Buffer.SI.IN7 = InputDirctMode;
	tle8108 = TLE8108EM_TX_Buffer.U;
	if(frq !=0)
	{
		Frq = (uint32)1000000000 / frq;
		TLE8108EM_PwmCtrlChannelOutput(DO_OUT_7, duty, Frq);

	}

}

void set_MixDoor(uint8 p, uint8 n)
{
	// HBridge_MPQ6612A_Ctrl(MPQ6612A_CHIP_A, p, n);
	if (p == 1 && n == 1)
	{
		tca6424B[3] = 0x01 | tca6424B[3];
		tca6424B[2] = 0x80 | tca6424B[2];
	}
	else if (p == 1 && n == 0)
	{
		tca6424B[3] = 0x01 | tca6424B[3];
		tca6424B[2] = (0x80 ^ 0xFF) & tca6424B[2];
	}
	else if (p == 0 && n == 1)
	{
		tca6424B[3] = (0x01 ^ 0xFF) & tca6424B[3];
		tca6424B[2] = 0x80 | tca6424B[2];
	}
	else
	{
		tca6424B[3] = (0x01 ^ 0xFF) & tca6424B[3];
		tca6424B[2] = (0x80 ^ 0xFF) & tca6424B[2];
	}
}

void set_ModeMotor(uint8 p, uint8 n)
{
	// HBridge_MPQ6612A_Ctrl(MPQ6612A_CHIP_B, p, n);
	if (p == 1 && n == 1)
	{
		tca6424B[3] = 0x06 | tca6424B[3];
	}
	else if (p == 1 && n == 0)
	{
		tca6424B[3] = (0x02 ^ 0xFF) & tca6424B[3] | 0x04;
	}
	else if (p == 0 && n == 1)
	{
		tca6424B[3] = (0x04 ^ 0xFF) & tca6424B[3] | 0x02;
	}
	else
	{
		tca6424B[3] = (0x06 ^ 0xFF) & tca6424B[3];
	}
}

void set_RecircMotor(uint8 p, uint8 n)
{
	if (p == 1 && n == 1)
	{
		tca6424B[2] = 0x60 | tca6424B[2];
	}
	else if (p == 1 && n == 0)
	{
		tca6424B[2] = (0x20 ^ 0xFF) & tca6424B[2] | 0x40;
	}
	else if (p == 0 && n == 1)
	{
		tca6424B[2] = (0x40 ^ 0xFF) & tca6424B[2] | 0x20;
	}
	else
	{
		tca6424B[2] = (0x60 ^ 0xFF) & tca6424B[2];
	}
}

void set_PwrHVPart(uint8 u)
{
	if (u == 1)
	{
		tca6424B[1] = (1 << 5) | tca6424B[1];
		// BTS7120_CtrlOutputChannelOn(BTS7120_CHIP_C, BTS7120_OUT0);
	}
	else
	{
		tca6424B[1] = ((1 << 5) ^ 0xFF) & tca6424B[1];
		// BTS7120_CtrlOutputChannelOff(BTS7120_CHIP_C, BTS7120_OUT0);
	}
}

void set_PwrACPump(uint8 u)
{
	if (u == 1)
	{
		tle75242A = (1) | tle75242A;
	}
	else
	{
		tle75242A = (1 ^ 0xFF) & tle75242A;
	}
}

void set_PwrFanCabin(uint8 u)
{
	if (u == 1)
	{
		tca6424B[1] = (1 << 4) | tca6424B[1];
	}
	else
	{
		tca6424B[1] = ((1 << 4) ^ 0xFF) & tca6424B[1];
	}
}

void set_PwrSensor(uint8 u)
{
	if (1 == u)
	{
		tca6424C[3] = (0x04) | tca6424C[3];
	}
	else
	{
		tca6424C[3] = (uint8)(0x04 ^ 0xFF) & tca6424C[3];
	}
}

void set_PwrSOV(uint8 u)
{
	if (1 == u)
	{
		tle75004 = (uint8)(TLE75004_LS_OUT1 << TLE75004_CH_ON) | tle75004;
	}
	else
	{
		tle75004 = (uint8)((TLE75004_LS_OUT1 << TLE75004_CH_ON) ^ 0xFF) & tle75004;
	}
}

void set_PwrFanAndPump(uint8 status)
{
	if (status == 1)
	{
		tle75004 = 1 | tle75004;
	}
	else
	{
		tle75004 = (1 ^ 0xFF) & tle75004;
	}
}
adc2_group0 Get_adc2_group0_resultbuffer()
{
    adc2_group0 A;
    A.adc2_group0_0=adc2_group0_resultbuffer[0];
    A.adc2_group0_1=adc2_group0_resultbuffer[1];
    A.adc2_group0_2=adc2_group0_resultbuffer[2];
    return A;
}
adc2_group1 Get_adc2_group1_resultbuffer()
{    
	adc2_group1 A;
	A.adc2_group1_0=adc2_group1_resultbuffer[0];
	A.adc2_group1_1=adc2_group1_resultbuffer[1];
	A.adc2_group1_2=adc2_group1_resultbuffer[2];
	A.adc2_group1_3=adc2_group1_resultbuffer[3];
	A.adc2_group1_4=adc2_group1_resultbuffer[4];
	A.adc2_group1_5=adc2_group1_resultbuffer[5];
	A.adc2_group1_6=adc2_group1_resultbuffer[6];
	A.adc2_group1_7=adc2_group1_resultbuffer[7];
	A.adc2_group1_8=adc2_group1_resultbuffer[8];
	A.adc2_group1_9=adc2_group1_resultbuffer[9];
    return A;
	
}
adc2_group2 Get_adc2_group2_resultbuffer()
{  
	adc2_group2 A;
    A.adc2_group2_0 = AD4067Avalue[0];//adc2_group2_resultbuffer[0];
    A.adc2_group2_1=adc2_group2_resultbuffer[1];
    A.adc2_group2_2=adc2_group2_resultbuffer[2];
    A.adc2_group2_3=adc2_group2_resultbuffer[3];
    A.adc2_group2_4=adc2_group2_resultbuffer[4];
    return A;
}
uint8 Get_PSAuthentRes(void)
{
  return  1;//默认防盗通过
}
uint8 GetHw_CrashPWMSta(void)
{
  return 0;//默认数值
}
uint8 Get_RKEReq(void)
{
  return 0;//默认数值
}
uint16 GetHw_TurnIndcrVol(uint8 Sts)
{

	tca6424E[1] = (1 << 7) | tca6424E[1];
	if (Sts == 1)
	{
		tca6424E[2] = (1) | tca6424E[2];
	}
	else
	{
		tca6424E[2] = (1 ^ 0xFF) & tca6424E[2];
	}
	return (uint16)(((float)AD4067Bvalue[0] / 4095.0 * 3300.0)* 4800.0 /1500);
}

uint16 GetHw_RLTurnIndcrVol(void)//判断左转向灯故障
{
	return GetHw_TurnIndcrVol(0);
}
uint16 GetHw_RRTurnIndcrVol(void)//判断右转向灯故障
{
	return GetHw_TurnIndcrVol(1);
}
void Set_TrunkUnLock(uint8 Sts)
{
	if (Sts == 1)
	{
		tca6424D[2] = (1) | tca6424D[2];
	}
	else
	{
		tca6424D[2] = (1 ^ 0xFF) & tca6424D[2];
	}
}
void Set_BSDRightCtl(uint8 Sts)   //BSD2
{
	if (Sts == 1)
	{
		tle75242A = (1 << 6) | tle75242A;
	}
	else
	{
		tle75242A = ((1 << 6) ^ 0xFF) & tle75242A;
	}


}
void Set_BSDLeftCtl(uint8 Sts) //BSD1
{

	if (Sts == 1)
	{
		tle75242A = (1 << 5) | tle75242A;
	}
	else
	{
		tle75242A = ((1 << 5) ^ 0xFF) & tle75242A;
	}
}
uint16 GetHw_DrvSeatResis(void)
{
  float  ad_v =0.0; 
  ad_v = ((float)AD4067Dvalue[6] / 4095.0 * 3300.0*1.68);
  return (uint16)ad_v;
}
uint8 GetHw_DoorAjarRL(void)
{
  
	return Tca9539_IOValue[TCA9539_CHIP_A][IOEXP_TCA9539_P15];
}

uint8 GetHw_TrunkLckSts(void)
{
	return Tca9539_IOValue[TCA9539_CHIP_B][IOEXP_TCA9539_P03];
}
uint8 GetHw_DoorAjarRR(void)
{
	return Tca9539_IOValue[TCA9539_CHIP_A][IOEXP_TCA9539_P16];
}
uint8 GetHw_TrunkAjarSts(void)//尾门PE开关
{
    return Tca9539_IOValue[TCA9539_CHIP_A][IOEXP_TCA9539_P14];
}
uint8 GetHw_TrunkSts(void)//尾门PE开关预留 IDL24
{
	return Tca9539_IOValue[TCA9539_CHIP_B][IOEXP_TCA9539_P07];
}
uint8 GetHw_HoodAjarSts(void)
{
	return Tca9539_IOValue[TCA9539_CHIP_A][IOEXP_TCA9539_P13];
}
uint8 Get_KeyPos(void)
{
	return 0;//模拟返回值
}
uint16 GetHw_DrvWinMotorCur(void)
{
  uint16 curr = 0;
  curr = (uint16)((float)AD4067Bvalue[1]/4095*3300/22/0.002);
  return curr;
}
uint16 GetHw_DrvWinSwResis(void) //IN_IAN10 主驾驶的主驾车窗开关
{
    uint16 AD_R =0;
    float  AD_V =0.0;
    AD_V = ((float)AD4067Evalue[7]/4095.0*3300.0*6.0/5.0);
    if(AD_V >2400)
    {
        AD_R =0xFFFF;
    }
    else
    {
        AD_R =(uint16)(AD_V / (VCC - AD_V) *3000.0);
    }
    return AD_R;	
        
}
uint16 GetHw_PsgWinSwResis(void) //IN_IAN11 主驾驶的副驾车窗开关
{
    uint16 AD_R =0;
    float  AD_V =0.0;
    AD_V = ((float)AD4067Evalue[8]/4095.0*3300.0*6.0/5.0);
    if(AD_V >2400)
    {
        AD_R =0xFFFF;
    }
    else
    {
        AD_R =(uint16)(AD_V / (VCC - AD_V) *3000.0);
    }
    return AD_R;
  
}
uint16 GetHw_DrvPsgWinSwResis(void) //IN_IAN50 副驾侧副驾车窗开关
{
  
    uint16 AD_R =0;
    float  AD_V =0.0;
    AD_V = ((float)AD4067Avalue[8]/4095.0*3300.0*6.0/5.0);
    if(AD_V >2400)
    {
        AD_R =0xFFFF;
    }
    else
    {
        AD_R =(uint16)(AD_V / (VCC - AD_V) *3000.0);
    }
    return AD_R;
}

uint16 GetHw_PsgWinMotorCur(void) // AD_Current03 继电器E 副驾车窗电流
{
	return (uint16)((float)AD4067Bvalue[2]/4095*3300 /22 /0.002);	
}
uint16 GetHw_Lightlntst(void)
{
	return (uint16)((float)adc2_group1_resultbuffer[0]/4095*3300*42/25);
}
void SetHw_PwrSup(uint8 Sts)//转向柱锁电机继电器低边驱动 目前确认7E100_B_OUT2
{
	Dio_WriteChannel(GPIO_H0, Sts);
	// if (Sts == 1)
	// {
	// 	tle75242B = (1 << 1) | tle75242B;

	// }
	// else
	// {
	// 	tle75242B = ((1 << 1) ^ 0xFF) & tle75242B;
	// }	
}
void SetHw_RearMirrorHeat(uint8 Sts)
{
	if (Sts == 1)
	{
		TLE8108EM_TX_Buffer.SI.IN6 = 2;
	}
	else
	{
		TLE8108EM_TX_Buffer.SI.IN6 = 3;
	}
	tle8108 = TLE8108EM_TX_Buffer.U;
}
void SetHw_BoxLampSta(uint8 Sts)
{
	VNQ7E100_CtrlA(VNQ7E100_Ch_Out0,Sts);
}
uint16 GetHw_LowBatValtage()//BAT 电源检测
{
    return (uint16)((float)AD4067Bvalue[3]/4095*3300*6 +300);
}


void SetHw_BackLightDrv(uint8 frq,uint8 duty)  // 背光灯驱动
{
    	uint32 Frq_A = 0;
	uint32 duty_pect = 0;
	// Dio_WriteChannel(GPIO_H5, 1);
	Frq_A = (uint32)1000000000 / frq;
	duty_pect = (uint32)duty * (0x8000) / 100;
	
    // Pwm_SetPeriodAndDuty(PWM_CONFIG_CHANNEL_PwmChannel_7120_B_IN0,Frq_A,duty_pect);
	 Pwm_SetDutyCycle(PWM_CONFIG_CHANNEL_PwmChannel_7120_B_IN0,duty_pect);
}

uint16 GetHw_DrvSeatTempFrb(void)   // 座椅加热温度反馈
{
  	float ad_V = 0.0;
	ad_V = ((float)AD4067Avalue[6]) / 4095.0 * 3300.0* 6.0 / 5.0;
	return (uint16)ad_V;
}
void SetHw_DrvSeatHeat(uint8 frq,uint8 duty)  // 座椅加热PWM驱动
{
  	uint32 Frq_A = 0;
	uint32 duty_pect = 0;
	// Dio_WriteChannel(GPIO_H5, 1);
	Frq_A = (uint32)1000000000 / frq;
	duty_pect = (uint32)duty * (0x8000) / 100;
    // Pwm_SetPeriodAndDuty(PWM_CONFIG_CHANNEL_PwmChannel_BTS7012_A_IN0,Frq_A,duty_pect);
	 Pwm_SetDutyCycle(PWM_CONFIG_CHANNEL_PwmChannel_BTS7012_A_IN0,duty_pect);
}


//V1.9 -ADD NVM BLOCK Options
Std_ReturnType NvmVcuBlock01ReadData(uint8 *data, uint8 Length)
{
      uint8  index = 0;
      for(index = 0;index < Length;index++)
      {
          data[index] = *(NvM_BlockDescriptor[NvMBlock_Swc_VCU_01_64 - 1].NvmRamBlockDataAddress + index);
      }
      return E_OK;	
}
Std_ReturnType NvmVcuBlock01WriteData(uint8 *data, uint8 Length)
{	
      uint8  index = 0;
      if(Length >DataLength_VCU_NVMData)
      {
              return E_NOT_OK;
      }
      for(index = 0; index < Length; index++)
      {
      *(NvM_BlockDescriptor[NvMBlock_Swc_VCU_01_64 - 1].NvmRamBlockDataAddress + index) = data[index];
      }
      return E_OK;
}

Std_ReturnType NvmTmsBlockReadData(uint8 *data, uint8 Length)
{
    uint8  index = 0;
    for(index = 0;index < Length;index++)
    {
        data[index] = *(NvM_BlockDescriptor[NvMBlock_Swc_TMS - 1].NvmRamBlockDataAddress + index);
    }
    return E_OK;
}
Std_ReturnType NvmTmsBlockWriteData(uint8 *data, uint8 Length)
{
    uint8  index = 0;
    if(Length >DataLength_TMS_NVMData)
    {
        return E_NOT_OK;
    }
    for(index = 0; index < Length; index++)
    {
        *(NvM_BlockDescriptor[NvMBlock_Swc_TMS - 1].NvmRamBlockDataAddress + index) = data[index];
    }
	//NvM_WriteBlock(NvMBlock_Swc_TMS,NULL_PTR);

}
Std_ReturnType NvmBCmBlock_Imm_ReadData(uint8 *data, uint8 Length) 
{
  uint8  index;
//    NvM_RequestResultType NvmStatus = 0;
//    NvM_GetErrorStatus(NvMBlock_Swc_BCM_IMM_10,&NvmStatus);
//    if(NvmStatus != NVM_REQ_PENDING && NvmStatus != NVM_REQ_NOT_OK)
//    {
        for(index = 0;index < Length;index++)
        {
            data[index] = *(NvM_BlockDescriptor[NvMBlock_Swc_BCM_IMM_20 - 1].NvmRamBlockDataAddress + index);
        }
    	return E_OK;
//    }
//    else
//    {
//         return E_NOT_OK;
//    }
   

}
Std_ReturnType  NvmBcmBlock_Imm_WriteData(uint8 *data, uint8 Length)//即时存
{
    uint8  index = 0;
    NvM_RequestResultType NvmStatus = 0;
    if(Length >DataLength_BCM_IMM_NVMData)
    {
         return E_NOT_OK;
    }
            
    for(index = 0; index < Length; index++)
    {
    *(NvM_BlockDescriptor[NvMBlock_Swc_BCM_IMM_20 - 1].NvmRamBlockDataAddress + index) = data[index];
    }	
    NvM_WriteBlock(NvMBlock_Swc_BCM_IMM_20, NULL_PTR);
//    NvM_GetErrorStatus(NvMBlock_Swc_BCM_IMM_10,&NvmStatus);
//    if(NvmStatus != NVM_REQ_PENDING)
//    {
//            NvM_WriteBlock(NvMBlock_Swc_BCM_IMM_10, NULL_PTR);
//    }
//    else if(NVM_REQ_OK == NvmStatus)
//    {
//    
      return E_OK;
//
//    }
//    else
//    {
//        NvM_CancelJobs(NvMBlock_Swc_BCM_IMM_10);
//        NvM_WriteBlock(NvMBlock_Swc_BCM_IMM_10, NULL_PTR);
//    }
  



}
Std_ReturnType NvmBcmBlock02ReadData(uint8 *data, uint8 Length)
{
    uint8  index = 0;
    for(index = 0;index < Length;index++)
    {
        data[index] = *(NvM_BlockDescriptor[NvMBlock_Swc_BCM_PD_10 - 1].NvmRamBlockDataAddress + index);
    }

    return E_OK;
}
Std_ReturnType NvmBcmBlock02WriteData(uint8 *data, uint8 Length)
{
    uint8  index = 0;
    if(Length >DataLength_BCM_PD_NVMData)//判断数据长度是否正确
    {
        return E_NOT_OK;
    }
    for(index = 0; index < Length; index++)
    {
      *(NvM_BlockDescriptor[NvMBlock_Swc_BCM_PD_10 - 1].NvmRamBlockDataAddress + index) = data[index];
    }
    return E_OK;

}
/*add nvm block of vcu*/
uint8 *olddata = NULL;
Std_ReturnType NvmVcuBlockImdtWriteData(uint8 *data, uint8 Length)
{
    uint8  index = 0;
    if(Length >DataLength_VCU_IMM128_NVMData)
    {
        return E_NOT_OK;
    }
    for(index = 0; index < Length; index++)
    {
		if(olddata[index] == data[index])
		{
			/*nothing to do*/
		}
		else
		{
			*(NvM_BlockDescriptor[NvMBlock_Swc_VCU_02_128 - 1].NvmRamBlockDataAddress + index) = data[index];
			olddata[index] = data[index];
			NvM_WriteBlock(NvMBlock_Swc_VCU_02_128, NULL_PTR);
		}
        
    }
	
    return E_OK;
}

Std_ReturnType NvmVcuBlockImdtReadData(uint8 *data, uint8 Length)
{
	uint8  index = 0;
    for(index = 0;index < Length;index++)
    {
        data[index] = *(NvM_BlockDescriptor[NvMBlock_Swc_VCU_02_128 - 1].NvmRamBlockDataAddress + index);
    }

    return E_OK;

}



//上电唤醒原因
uint8 Get_EcuWakeupReasn(void)
{
  return CCUWakeupReturnValue;
}
/*
函数名称：ME11_ABIRTC_SetTime
函数作用：应用层调用设置RTC睡眠时间
函数输入：Param min
函数输出：无
*/
void Set_RtcWakeupTime(uint16 Param)
{
    // ABIRTC_Timer = Param;
   RTC_Timer =  Param;//KVCU_RtcWakeupTm_min

   if((SWCTimer_Min==RTC_Timer)||(SWCTimer_Max==RTC_Timer))
    {
        Mcu_Ip_PmuEnableIntWakeupSrc(PMU_WAKEUP_SRC_DISABLE);  // 禁用PMU中断唤醒源

    }
    else
    {
         Mcu_Ip_PmuEnableIntWakeupSrc(PMU_WAKEUP_SRC_ENABLE);   // 启用PMU中断唤醒源
    }
}



/*
函数名称：ME11_ABI_RequestCommunication
函数作用：应用层请求网络通信
函数输入：state 0-没有需求或1-请求
函数输出：返回1表示成功，返回0表示失败
*/
uint8 Set_EcuCommReq(uint8 state)
{
  
   if(1==state)
   {
          App_ComMReqFlag = 0x55;//APP_REQ_COMM;
   }
   else
   {
          App_ComMReqFlag = 0xAA;//APP_NOREQ_COMM;
   }
   BswM_RequestMode(10,App_ComMReqFlag);
   
   return 1;
   

}



/*
函数名称：ME11_ABI_SleepAllowed
函数作用：应用层允许控制器休眠
函数输入：1-允许
函数输出：返回1表示成功，返回0表示失败
*/

uint8 Set_EcuSleepAllow(uint8 state)
{
     if(1==state)
     {
            App_SleepReqFlag = 0x55;//APP_REQ_SLEEP;
     }
     else
     {
            App_SleepReqFlag = 0xAA; //APP_NOREQ_SLEEP;
     }
     BswM_RequestMode(20,App_SleepReqFlag);
     return 1;
}


boolean INV_IMMO_Req_EPT_RecV(PduIdType PduId, const PduInfoType* PduInfoPtr)//0x338接收callout
{	
    INV_IMMO_Req_EPT_RevFlag =1;
    return INV_IMMO_Req_EPT_RevFlag;
}
boolean INV_IMMO_Req_EPT_Rec_callout()//确认接收到0x338
{
  return INV_IMMO_Req_EPT_RevFlag;
}
boolean INV_IMMO_Req_EPT_Rec_ClaerFlg()//取消标志位 0x338
{
	INV_IMMO_Req_EPT_RevFlag =0;
    return INV_IMMO_Req_EPT_RevFlag;

}

boolean BCM_IMMOAuthResp1_EPT_Send_Notication(uint8 *data)//0x330发送
{
    Com_SendSignal(BCM_IMMOAuthResp1_EPT_IPDU_COM_BCM_IMMOAuthResp1_EPT_BCM_Learning_subID_IPDU_COM_BCM_IMMOAuthResp1_EPT,   &data[0]);
    Com_SendSignal(BCM_IMMOAuthResp1_EPT_IPDU_COM_BCM_IMMOAuthResp1_EPT_BCM_Learning_Status_IPDU_COM_BCM_IMMOAuthResp1_EPT,  &data[1]);
    Com_SendSignal(BCM_IMMOAuthResp1_EPT_IPDU_COM_BCM_IMMOAuthResp1_EPT_BCM_Learning_Data_02_IPDU_COM_BCM_IMMOAuthResp1_EPT, &data[2]);
    Com_SendSignal(BCM_IMMOAuthResp1_EPT_IPDU_COM_BCM_IMMOAuthResp1_EPT_BCM_Learning_Data_03_IPDU_COM_BCM_IMMOAuthResp1_EPT, &data[3]);
    Com_SendSignal(BCM_IMMOAuthResp1_EPT_IPDU_COM_BCM_IMMOAuthResp1_EPT_BCM_Learning_Data_04_IPDU_COM_BCM_IMMOAuthResp1_EPT, &data[4]);
    Com_SendSignal(BCM_IMMOAuthResp1_EPT_IPDU_COM_BCM_IMMOAuthResp1_EPT_BCM_Learning_Data_05_IPDU_COM_BCM_IMMOAuthResp1_EPT, &data[5]);
    Com_SendSignal(BCM_IMMOAuthResp1_EPT_IPDU_COM_BCM_IMMOAuthResp1_EPT_BCM_Learning_Data_06_IPDU_COM_BCM_IMMOAuthResp1_EPT, &data[6]);
    Com_SendSignal(BCM_IMMOAuthResp1_EPT_IPDU_COM_BCM_IMMOAuthResp1_EPT_BCM_Learning_Data_07_IPDU_COM_BCM_IMMOAuthResp1_EPT, &data[7]);
    Com_SendSignalGroup(BCM_IMMOAuthResp1_EPT_IPDU_COM_BCM_IMMOAuthResp1_EPT);
    return TRUE;
}

void BCM_SKRead(uint8 *data, uint8 length)
{
	uint8  index = 0;

    for(index = 0; index < length; index++)
    {
        data[index] = *(NvM_BlockDescriptor[NvMBlock3_DID_F157 - 1].NvmRamBlockDataAddress + index);
    }
}

uint16  GetHw_SteerWhlTempFrb(void) //方向盘加热温度反馈
{
    uint16 AD_R =0;
    float  AD_V =0.0;
    AD_V = ((float)AD4067Evalue[6]/4095.0*3300.0*6.0/5.0);
    if(AD_V >2400)
    {
        AD_R =0xFFFF;
    }
    else
    {
        AD_R =(uint16)(AD_V / (VCC - AD_V) *3000.0);
    }
    return AD_R;
}

void SetHw_SteerWhlHeat(uint8 Sts)//方向盘加热驱动
{
    if (Sts == 1)
    {
        tle75242B = (1) | tle75242B;
    }
    else
    {
        tle75242B = ( 1 ^ 0xFF) & tle75242B;
    }
}

// 20240605
void SetHw_PwrBlower(uint8 state)//blower
{
	if (state == 1)
	{
		/*pwr on*/
		TLE75242_OUT2_3_Switch(TLE75242_CHIP_B,STD_HIGH,TLE75242_CH_OUT2);
		tca6424E[3] = (1 << 4) | tca6424E[3];
	}
	else
	{
		/*off*/
		TLE75242_OUT2_3_Switch(TLE75242_CHIP_B,STD_LOW,TLE75242_CH_OUT2);
		tca6424E[3] = ((1 << 4) ^ 0xff) & tca6424E[3];
	}
}



uint16 GetHW_VCCAcq()  // VCC
{
    uint16  AD_V =0.0;
    AD_V = (uint16)((float)AD4067Evalue[6]/4095.0*3300*2 +300);
    return AD_V;
}

void Rte_DIDReadData(uint8 data,uint8 didId)
{
    switch (didId)
    {
    case DID_0xF260:
        Buffer_DcmDspData_F260H[0]=data;
        break;

    case DID_0xF261:
        Buffer_DcmDspData_F261H[0]=data;
        break;

    case DID_0xF262:
        Buffer_DcmDspData_F262H[0]=data;
        break;

    case DID_0xF263:
        Buffer_DcmDspData_F263H[0]=data;
        break;

    case DID_0xF264:
        Buffer_DcmDspData_F264H[0]=data;
        break;

    case DID_0xF265:
        Buffer_DcmDspData_F265H[0]=data;
        break;

    case DID_0xF269:
        Buffer_DcmDspData_F269H[0]=data;
        break;

    case DID_0xF26A:
        Buffer_DcmDspData_F26AH[0]=data;
        break;

    case DID_0xF26B:
        Buffer_DcmDspData_F26BH[0]=data;
        break;

    case DID_0xF26D:
        Buffer_DcmDspData_F26DH[0]=data;
        break;



    case DID_0xF26F:
        Buffer_DcmDspData_F26FH[0]=data;
        break;

    case DID_0xF273:
        Buffer_DcmDspData_F273H[0]=data;
        break;

    case DID_0xF274:
        Buffer_DcmDspData_F274H[0]=data;
        break;
        
    case DID_0xF275:
        Buffer_DcmDspData_F275H[0]=data;
        break;
        
    case DID_0xF276:
        Buffer_DcmDspData_F276H[0]=data;
        break;
        
    case DID_0xF277:
        Buffer_DcmDspData_F277H[0]=data;
        break;
        
    case DID_0xF278:
        Buffer_DcmDspData_F278H[0]=data;
        break;
        
    case DID_0xF279:
        Buffer_DcmDspData_F279H[0]=data;
        break;
        
    case DID_0xF27A:
        Buffer_DcmDspData_F27AH[0]=data;
        break;
        
    case DID_0xF27B:
        Buffer_DcmDspData_F27BH[0]=data;
        break;
        
        
    case DID_0xF27F:
        Buffer_DcmDspData_F27FH[0]=data;
        break;
        
    case DID_0xF280:
        Buffer_DcmDspData_F280H[0]=data;
        break;
                
    case DID_0xF281:
        Buffer_DcmDspData_F281H[0]=data;
        break;
                
    case DID_0xF282:
        Buffer_DcmDspData_F282H[0]=data;
        break;
    default:
        break;
    }
}


uint8 Rte_IOCtrl(uint8 didID)
{
    if (didID ==IODID_0x0x3237)
    {
        return Buffer_DcmDspData_3237[0];
    }
    else
    {
        return (uint8)0;
    }
}

uint8 GetHw_DrvModeSw(void) // 驾驶模式
{
	Dio_LevelType IDX_Sta;

	IDX_Sta = IoExp_TCA6408_GetChannelInputLevel(IOEXP_TCA6408_P01);

	return (uint8)IDX_Sta;
}

uint8 GetHw_CreepModeSw(void) // 蠕行
{
	Dio_LevelType IDX_Sta;

	IDX_Sta = IoExp_TCA6408_GetChannelInputLevel(IOEXP_TCA6408_P02);

	return (uint8)IDX_Sta;
}
#if 1
uint8 GetHw_HiBeamDigSts(void)
{
	return 0;
}

uint8 GetHw_LoBeamDigSts(void)
{
	return 0;
}
#endif