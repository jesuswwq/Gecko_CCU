#include "PEPS_ABI.h"
#include "Uhf_Fml.h"
#include "NvM.h"
#include "UHF_FML.h"
#include "Pke_Pks_App.h"
#include "Nck2910.h"
#include "sdrv_btm_hw.h"

/****射频信号初始化****/

// APP输出
uint8 u8KeyTempBuffVal[256] = {0};	 // ��ȡ�ʹ洢������ʱ����
uint8 u8PS_Auth_KeyPosReq = 0;		 // PS����������֤��λң��Կ��
uint8 u8PE_Auth_KeyPosReq = 0;		 // PE����������֤��λң��Կ��
uint8 u8FobKeyEnterWorkState = 0;	 // �������Ƿ������ң����ƥ������ģʽ
uint8 u8PollingFuncRequest = 0;		 // Polling��������
uint8 u8PolingStsReq = 0;			 //
uint8 u8AntDigRequest = 0;			 // �����������
uint8 u8LPEDriverCurRead = 0;		 // ���PE��������������ȡ
uint8 u8RPEDriverCurRead = 0;		 // �Ҳ�PE��������������ȡ
uint8 u8PSAntDirverCurRead = 0;		 // PS��������������ȡ
uint16 u16LPEAntDriveCurrentSet = 0; // ���PE����������������
uint16 u16RPEAntDriveCurrentSet = 0; // �Ҳ�PE����������������
uint16 u16PSAntDriveCurrentSet = 0;	 // PS����������������
uint16 u16LPEAntRssiLimitRead = 0;	 // ���PE���߳�ǿ��ֵ��ȡ
uint16 u16RPEAntRssiLimitRead = 0;	 // �Ҳ�PE���߳�ǿ��ֵ��ȡ
uint16 u16PSAntRssiLimitRead = 0;	 // PS���߳�ǿ��ֵ��ȡ
uint16 u16LPEAntRssiLimitSet = 0;	 // ���PE���߳�ǿ��ֵ����
uint16 u16RPEAntRssiLimitSet = 0;	 // �Ҳ�PE���߳�ǿ��ֵ����
uint16 u16PSAntRssiLimitSet = 0;	 // PS���߳�ǿ��ֵ����

// APP输入
uint8 u8PE_Auth_FobStatus = 0;						// PE����ң��Կ��λ����Ϣ
uint8 u8PS_Auth_FobStatus = 0;						// PS����ң��Կ��λ����Ϣ
uint16 u16Leftfront_Door_Ant_Rssi = 0;				// ��ǰ�ŵ�ǰ��Ƶ����ǿ��ֵ(ȫ�ֱ���)
uint16 u16Rightfront_Door_Ant_Rssi = 0;				// ��ǰ�ŵ�ǰ��Ƶ����ǿ��ֵ
uint16 u16InCar_Door_Ant_Rssi = 0;					// ���ڵ�ǰ��Ƶ����ǿ��ֵ
uint8 u8Lf_Polling_Work_State = 0;					// Polling����״̬
uint8 u8Welcome_Function_Request = 0;				// ӭ�����ܵ�ǰ����ģʽ
uint16 u16Left_Door_Ant_DriveCurrent = 0;			// ���PE����������������(ȫ�ֱ���)
uint16 u16Right_Door_Ant_DriveCurrent = 0;			// �Ҳ�PE����������������(ȫ�ֱ���)
uint16 u16Incar_Ant_DriveCurrent = 0;				// PS����������������(ȫ�ֱ���)
uint16 u16Left_Door_Ant_Rssi_Limit = 0;				// ���PE���߳�ǿ��ֵ����(ȫ�ֱ���)
uint16 u16Right_Door_Ant_Rssi_Limit = 0;			// �Ҳ�PE���߳�ǿ��ֵ����(ȫ�ֱ���)
uint16 u16Incar_Ant_Rssi_Limit = 0;					// PS���߳�ǿ��ֵ����(ȫ�ֱ���)
uint8 u8FobKey_Information_Management_Feedback = 0; // Կ��ѧϰ�Լ�����״̬����(ȫ�ֱ���)
uint8 u8FobKey_Disable_Status_Feedback = 0;			// Կ�׽���״̬����(ȫ�ֱ���)
uint8 u8SpiCurReadUhfDataBuf[18];					// ��ƵЭ������(ȫ�ֱ���)
uint8 u8Fobkey_Cur_RkeCmd = 0;
uint8 u8_Auth_KeyTestReq = 0;

uint8 psreq_count = 0;
uint8 psclear_count = 0;
uint8 lfworksta = 0;
uint16 RxNum2910 = 0;

/****射频模型输入接口API****/
#pragma default_function_attributes = @".iram_func"
// PE功能遥控钥匙位置信息
uint8 Get_PEAuth_FobStatus(void)
{

	return u8PE_Auth_FobStatus;
}

// PS功能遥控钥匙位置信息
uint8 Get_PSAuth_FobStatus(void)
{

	return u8PS_Auth_FobStatus;
}

// 迎宾功能当前工作模式
uint8 Get_Wlcm_FunStatus(void)
{

	return u8Welcome_Function_Request;
}

// Polling开启状态
uint8 Get_PollingWork_State(void)
{

	return u8Lf_Polling_Work_State;
}

// NVM变量休眠后读取
void PEPS_NVMRead(void)
{
	uint16 index;

	for (index = 0; index < 256; index++)
	{
		u8KeyTempBuffVal[index] = *(NvM_BlockDescriptor[NvMBlock_Swc_BCM_PEPS_256 - 1].NvmRamBlockDataAddress + index);
	}

	for (index = 0; index < 16; index++)
	{
		u8KeyTempBuffVal[index] = *(NvM_BlockDescriptor[NvMBlock3_DID_F157 - 1].NvmRamBlockDataAddress + index);
	}
}

// 获取钥匙禁能数量
uint8 Get_FobdKeyNum(void)
{
	uint8 key1, key2, FobdKey_Num;
	if ((u8FobKey_Disable_Status_Feedback & 0x01) > 0)
	{
		key1 = 1;
	}
	else
	{
		key1 = 0;
	}

	if ((u8FobKey_Disable_Status_Feedback & 0x02) > 0)
	{
		key2 = 1;
	}
	else
	{
		key2 = 0;
	}

	FobdKey_Num = key1 + key2;

	return FobdKey_Num;
}

// 钥匙电池电量是否过低读取
uint8 Get_KeyBat_VolLow(void)
{
	uint8 KeyBatLow_flg;

	KeyBatLow_flg = GetVariableFobKeyVoltStatus();

	return KeyBatLow_flg;
}

// 车门关闭钥匙不在车内提醒
uint8 Get_KeyNotInCar_Warn(void)
{
	uint8 KeyNotInCar_flg;

	KeyNotInCar_flg = ClsDoorKeyNotInCarWarn();

	return KeyNotInCar_flg;
}

/****射频模型输出接口API****/

// PE功能请求认证定位遥控钥匙
void Set_PEAuth_FobReq(uint8 PEReq_param)
{
	u8PE_Auth_KeyPosReq = PEReq_param;
}

// PS功能请求认证定位遥控钥匙
void Set_PSAuth_FobReq(uint8 PSReq_param)
{
	u8PS_Auth_KeyPosReq = PSReq_param;
}

// Polling功能请求
void Set_Polling_FunReq(uint8 PolReq_param)
{
	u8PollingFuncRequest = PolReq_param;
}

// 天线诊断请求
void Set_AntDig_FunReq(uint8 AntDigReq_param)
{
	u8AntDigRequest = AntDigReq_param;
}

// 左侧PE天线驱动电流设置
void Set_LPEDriverCur_Val(uint16 LCur_param)
{
	u16LPEAntDriveCurrentSet = LCur_param;
}

// 右侧PE天线驱动电流设置
void Set_RPEDriverCur_Val(uint16 RCur_param)
{
	u16RPEAntDriveCurrentSet = RCur_param;
}

// PS天线驱动电流设置
void Set_PSAntDirverCur_Val(uint16 PSCur_param)
{
	u16PSAntDriveCurrentSet = PSCur_param;
}

// 左侧PE天线场强阀值设置
void Set_LPEAntRssiLimit_Val(uint16 LRssi_param)
{
	u16LPEAntRssiLimitSet = LRssi_param;
}

// 右侧PE天线场强阀值设置
void Set_RPEAntRssiLimit_Val(uint16 RRssi_param)
{
	u16RPEAntRssiLimitSet = RRssi_param;
}

// PS天线场强阀值设置
void Set_PSAntRssiLimit_Val(uint16 PSRssi_param)
{
	u16PSAntRssiLimitSet = PSRssi_param;
}

void PEPS_NVMWrite(void)
{
	uint16 index;

	for (index = 0; index < 256; index++)
	{
		*(NvM_BlockDescriptor[NvMBlock_Swc_BCM_PEPS_256 - 1].NvmRamBlockDataAddress + index) = u8KeyTempBuffVal[index];
	}
}

void Clear_PSStatus(void)
{
	SetPs_AuthFobStatus(0);
	psclear_count++;
}

void Clear_PEStatus(void)
{
	SetPe_AuthFobStatus(0);
	// psclear_count ++;
}

void Clear_RKECommd(void)
{
	u8Fobkey_Cur_RkeCmd = 0;
}

void Clear_PollingCommd(void)
{
	u8Welcome_Function_Request = 0;
}

void PEPS_KL30_RessetMonit(void)
{
	uint32 Rtc_flg;
	Rtc_flg = sdrv_btm_hw_readl(0xF0010000, 0x50);
	if (Rtc_flg == 0x55)
	{
		SetEcuPowerOnMode(1);
	}
	else
	{
		SetEcuPowerOnMode(0);
	}
}
void PEPS_KL30Resset_ParamWrt(void)
{
	sdrv_btm_hw_writel(0xF0010000, 0x50, 0x55);
}
/****射频测试****/
void keystudy_test(void)
{
	u8KeyTempBuffVal[0] = 0x01;
	u8KeyTempBuffVal[1] = 0x02;
	u8KeyTempBuffVal[2] = 0x03;
	u8KeyTempBuffVal[3] = 0x04;
	u8KeyTempBuffVal[4] = 0x05;
	u8KeyTempBuffVal[5] = 0x06;
	u8KeyTempBuffVal[6] = 0x07;
	u8KeyTempBuffVal[7] = 0x08;
	u8KeyTempBuffVal[8] = 0x09;
	u8KeyTempBuffVal[9] = 0x0A;
	u8KeyTempBuffVal[10] = 0x0B;
	u8KeyTempBuffVal[11] = 0x0C;
	u8KeyTempBuffVal[12] = 0x0D;
	u8KeyTempBuffVal[13] = 0x0E;
	u8KeyTempBuffVal[14] = 0x0F;
	u8KeyTempBuffVal[15] = 0x10;

	u8FobKeyEnterWorkState = 1;
}

void LUnLock_PEPS_test(void)
{

	if (GetFobKeyCmdRequest() == 0x11)
	{
		SetHw_PstnLampOn(1);
	}
}

uint8 status2910, status29c0;

void PEPS_Interface2CAN(void)
{

	status2910 = tnNck2910WorkStatus;

	status29c0 = u8Njj29c0_WorkStatus;

	lfworksta = lfapp_work_sta;

	RxNum2910 = ((uint16)u32UhfRxNum);
}

#pragma default_function_attributes =
